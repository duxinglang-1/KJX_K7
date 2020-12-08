/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_categories_calendar.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  calendar related funtions
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
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"

#include "string.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "lcd_sw_inc.h"

//#include "GlobalDefs.h"
#include "CustDataRes.h"
//#include "CustDataProts.h"
//#include "WguiCategoryGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_app_uiframework_def.h"
//#include "mmi_frm_gprot.h"
//#include "CalendarDef.h"        /* Calendar image */
//#include "CalendarProt.h"
//#include "CalendarResDef.h"
//#include "CalendarGprot.h"

#include "gui_themes.h"
#include "gui_font_size.h"
//#include "profilingengine.h"
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
//#include "gui_effect_oem.h"
#endif 

#include "mmi_frm_events_gprot.h"
#include "Gui_Setting.h"
#include "wgui_categories_enum.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_calendar.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/

//RHR
    #include "MMI_features.h"
    #include "app_datetime.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "wgui.h"
    #include "gui_theme_struct.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_typedef.h"
    #include "wgui_categories_calendar.h"
    #include "gui_data_types.h"
    #include "string.h"
    #include "mmi_frm_input_gprot.h"
    #include "gdi_include.h"
    #include "wgui_include.h"
    #include "gui.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "gui_themes.h"
    #include "CustThemesRes.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "stdio.h"
    #include "Unicodexdcl.h"
    #include "wgui_inputs.h"
    #include "gui_calendar.h"
    #include "mmi_frm_mem_gprot.h"
    #include "wgui_categories_enum.h"
    #include "wgui_draw_manager.h"
    #include "wgui_categories_util.h"
    #include "custom_mmi_default_value.h"
    #include "wgui_touch_screen.h"
    #include "mmi_frm_events_gprot.h"
    #include "lcd_sw_rnd.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "PhoneSetupGprots.h"

static applib_time_struct g_cat_calendar_highlight_time;
#ifndef __MMI_CALENDAR_NEW_STYLE__
static applib_time_struct g_cat_calendar_start_time;
#endif
static applib_time_struct g_cat_calendar_end_time;
static applib_time_struct g_cat_calendar_max_time;
static applib_time_struct g_cat_calendar_min_time;
#ifdef __GDI_MEMORY_PROFILE_2__
static GDI_HANDLE g_cat_calendar_abm_layer = NULL;
#endif
static GDI_HANDLE g_cat_calendar_target_layer = NULL;
static UI_image_ID_type g_cat_calendar_bg_id = IMAGE_ID_NULL;

#ifdef __MMI_MENSTRUAL__
static U8 g_cat_calendar_horizontal_select0_left_filler = GUI_CALENDAR_COLOR_NONE;
static U8 g_cat_calendar_horizontal_select0_right_filler = GUI_CALENDAR_COLOR_NONE;
static PU8 g_cat_calendar_horizontal_select0_string = NULL;
#ifndef __MMI_CALENDAR_NEW_STYLE__
static U8 g_cat_calendar_horizontal_select1_left_filler = GUI_CALENDAR_COLOR_NONE;
static U8 g_cat_calendar_horizontal_select1_right_filler = GUI_CALENDAR_COLOR_NONE;
static PU8 g_cat_calendar_horizontal_select1_string = NULL;
#endif
static MMI_BOOL g_cat_calendar_is_in_mens = MMI_FALSE;
#endif /* __MMI_MENSTRUAL__ */


static gui_calendar_type_enum g_cat_calendar_type;
static wgui_cat83_event_struct g_cat_calendar_events;

#ifdef __MMI_CALENDAR_EVENT__
static S32 (*g_cat_calendar_cell_data_query_handler)(
             gui_calendar_type_enum type,
             applib_time_struct start_time,
             applib_time_struct end_time,
             applib_time_struct interval,
             S32 query_count,
             gui_calendar_cell_struct *cells) = NULL;
#endif
static S32 (*g_cat_calendar_cell_lunar_query_handler)(
             gui_calendar_type_enum type, // calendar type
             applib_time_struct cell_time, // highlighted time to query
             applib_time_struct time_interval, // the interval of time to query
             PU8 title, // title of cell
             U32 title_length, // title's length in U8
             gui_calendar_cell_detail_info_struct *detail_info) = NULL;

#ifdef __MMI_CLNDR_EVENT_INFO__
static S32 (*g_cat_calendar_event_query_handler)(
             gui_calendar_type_enum type, // calendar type
             applib_time_struct event_time, // highlighted time to query
             applib_time_struct time_interval, // the interval of time to query
             wgui_cat83_event_struct *event_info) = NULL;
#endif
static MMI_BOOL (*g_cat_calendar_highlight_change_callback)(
                  gui_calendar_type_enum type, // calendar type
                  applib_time_struct highlighted_time,
                  applib_time_struct start_time,
                  applib_time_struct end_time) = NULL;

static wgui_calendar_horizontal_select_struct g_cat83_cal_h_select[WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT];

static void wgui_cat83_draw_horizontal_select(U8 index);

#if 0
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

extern S32 UI_strlen(UI_string_type text);


#ifdef __MMI_TOUCH_SCREEN__

static MMI_BOOL wgui_cat83_pen_check_bound(mmi_pen_point_struct pos ,U8 index ,U8 icon_index)
{
    if (PEN_CHECK_BOUND(pos.x, pos.y,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_width,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_height))
    {
        return MMI_TRUE;
    }
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL wgui_cat83_horizintal_select_switch(U8 index, U8 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    applib_time_struct inc, temp, current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&temp, 0, sizeof(applib_time_struct));
    current_time = g_cat_calendar_highlight_time;
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
    {
        current_time.nDay = 1;
#ifdef __MMI_CALENDAR_NEW_STYLE__
            inc.nMonth = 1;
#else
            if (index == 0)
            {
                inc.nYear = 1;
            }
            if (index == 1)
            {
                inc.nMonth = 1;
            }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/

        if (direction == WGUI_CAL_H_SELECT_ALLOW_PREV)
        {
            applib_dt_decrease_time(
                (applib_time_struct*)&current_time,
                (applib_time_struct*)&inc,
                (applib_time_struct*)&temp);
        }
        if (direction == WGUI_CAL_H_SELECT_ALLOW_NEXT)
        {
            applib_dt_increase_time(
                (applib_time_struct*)&current_time,
                (applib_time_struct*)&inc,
                (applib_time_struct*)&temp);
        }

		/* compare with the max time and min time */
		{
            applib_time_struct diff;
			S32 compare_result = 0;
			compare_result = applib_dt_compare_time(
                                 &g_cat_calendar_max_time,
                                 &temp,
                                 &diff);
			if (compare_result != DT_TIME_LESS)
			{
				compare_result = applib_dt_compare_time(
                                     &g_cat_calendar_min_time,
                                     &temp,
                                     &diff);
                if (compare_result != DT_TIME_GREATER)
                {
                    result = MMI_TRUE;
                }
			}
		}
    }
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
    {
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (index == 0)
#endif
        {
            inc.nDay = 7;

            if (direction == WGUI_CAL_H_SELECT_ALLOW_PREV)
            {
                inc.nDay = current_time.DayIndex + 1;
                applib_dt_decrease_time(
                    (applib_time_struct*)&current_time,
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&temp);
            }
            if (direction == WGUI_CAL_H_SELECT_ALLOW_NEXT)
            {
                inc.nDay = DT_DAYS_OF_WEEK - current_time.DayIndex;
                applib_dt_increase_time(
                    (applib_time_struct*)&current_time,
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&temp);
            }

			/* compare with the max time and min time */
			{
				applib_time_struct diff;
				S32 compare_result = 0;
				compare_result = applib_dt_compare_time(
									&g_cat_calendar_max_time,
									&temp,
									&diff);
				if (compare_result != DT_TIME_LESS)
				{
					compare_result = applib_dt_compare_time(
										&g_cat_calendar_min_time,
										&temp,
										&diff);
					if (compare_result != DT_TIME_GREATER)
					{
						result = MMI_TRUE;
					}
				}
			}
        }
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (index == 1)
        {
            if (direction == WGUI_CAL_H_SELECT_ALLOW_PREV &&
                g_cat_calendar_start_time.nHour > 0)
            {
                result = MMI_TRUE;
            }
            if (direction == WGUI_CAL_H_SELECT_ALLOW_NEXT &&
                g_cat_calendar_end_time.nHour < DT_HRS_PRE_DAY)
            {
                result = MMI_TRUE;
            }
        }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
    }
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index ,icon_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_TRUE)
    {
        return MMI_FALSE;
    }
#endif

#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
#else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if (wgui_cat83_pen_check_bound(pos, index, icon_index))
            {
                if(g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
                {
                    return MMI_FALSE;
                }
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_DOWN;
        #ifdef __MMI_SLIM_IMG_RES__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_y += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
        #endif /* __MMI_SLIM_IMG_RES__ */

                //gdi_layer_lock_frame_buffer();
                wgui_cat83_draw_horizontal_select(index);
                //gdi_layer_unlock_frame_buffer();
                
                g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = TRUE;
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
        }
    }
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index ,icon_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
#else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if(g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button == TRUE)
            {
    #ifdef __MMI_SLIM_IMG_RES__
                if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN ||
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN)
                {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                }
    #endif

                if (wgui_cat83_pen_check_bound(pos ,index ,icon_index))
                {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state != GUI_CALENDAR_PEN_STATE_DOWN)
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                                       
                        //gdi_layer_lock_frame_buffer();
                        wgui_cat83_draw_horizontal_select(index);
                        //gdi_layer_unlock_frame_buffer();
                   }
                   else
                   {
                        if(icon_index == 0)/*prev icon*/
                        {
                               if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
                               {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
                        #else
                                    if(index == 0)
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_YEAR);
                                    }
                                    else
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
                                    }
                        #endif
                               }

                               if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
                               {
                 #ifdef __MMI_CALENDAR_NEW_STYLE__
                                    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_WEEK);
                 #else
                                    if (index == 0)
                                    {
                                         wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_WEEK);
                                    } 
                                    else
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD);
                                    }
                 #endif
                               }     
                        }
                        else /*next icon*/
                        {
                            if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
                            {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
                        #else
                                if(index == 0)
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_YEAR);
                                }
                                else
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
                                }
                        #endif
                        }

                        if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
                        {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_WEEK);
                        #else
                                if (index == 0)
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_WEEK);
                                }
                                else
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD);
                                 }
                         #endif
                          }
                      }
                     wgui_cat83_draw_horizontal_select(index);
                     gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
                  }
               }
               else
               {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;

                        //gdi_layer_lock_frame_buffer();
                        wgui_cat83_draw_horizontal_select(index);
                        //gdi_layer_unlock_frame_buffer();
                  }
               }
               g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = FALSE;
            }
        }
    }
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U8 index ,icon_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
#else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if (g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button == TRUE)
            {
                if (wgui_cat83_pen_check_bound(pos ,index ,icon_index))
                {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
                    {
                        result = MMI_TRUE;
                    }
                    else
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_MOVE_IN;
                    #ifdef __MMI_SLIM_IMG_RES__
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_x += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_y += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    #endif /* __MMI_SLIM_IMG_RES__ */
                    }
                }
                else
                {
                #ifdef __MMI_SLIM_IMG_RES__
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_y -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    }
                #endif /* __MMI_SLIM_IMG_RES__ */
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                }

                //gdi_layer_lock_frame_buffer();
                wgui_cat83_draw_horizontal_select(index);
                //gdi_layer_unlock_frame_buffer();
                 result = MMI_TRUE;
          }
       }
    }
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_abort_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_abort_hdlr(mmi_pen_point_struct pos)
        {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index ,icon_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
    #else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
    #endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if (g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button == TRUE)
            {
            #ifdef __MMI_SLIM_IMG_RES__
                if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN ||
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN)
        {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
            }
        #endif /* __MMI_SLIM_IMG_RES__ */
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;

                //gdi_layer_lock_frame_buffer();
                wgui_cat83_draw_horizontal_select(index);
                //gdi_layer_unlock_frame_buffer();
                g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = FALSE;
            }
         }
     }
    return MMI_TRUE;
        }
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
static void wgui_cat83_draw_icon_with_opacity_layer(S32 x, S32 y, S32 w, S32 h, PU8 icon)
        {
    GDI_HANDLE opacity_layer = GDI_NULL_HANDLE;
    GDI_HANDLE abm_src_layer = GDI_NULL_HANDLE;

    if (g_cat_calendar_abm_layer != NULL)
            {
        abm_src_layer = g_cat_calendar_abm_layer;
            }
    else
    {
        gdi_layer_get_active(&abm_src_layer);
    }

    gdi_layer_create(x, y, w - 1, h - 1, &opacity_layer);
    gdi_layer_push_and_set_active(opacity_layer);
    //gdi_push_and_set_alpha_blending_source_layer(opacity_layer);
    //gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(MMI_TRUE,128); 
    gdi_image_draw(0, 0, icon);
    //gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
    gdi_layer_push_and_set_clip(x, y, x + w - 1, y + h - 1);
    gdi_layer_flatten_with_clipping(abm_src_layer, opacity_layer, 0, 0);
    gdi_layer_pop_clip();
    gdi_layer_free(opacity_layer);
    }
#endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_init_horizontal_select
 * DESCRIPTION
 *  Calendar category init horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat83_init_horizontal_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_width[WGUI_CAL_H_SELECT_ALLOW_TOTAL] = {0, 0};
    S32 icon_height[WGUI_CAL_H_SELECT_ALLOW_TOTAL] = {0, 0};
#ifdef __MMI_MENSTRUAL__
    U8 color_index[WGUI_CAL_H_SELECT_ALLOW_TOTAL] = {GUI_CALENDAR_COLOR_NONE ,GUI_CALENDAR_COLOR_NONE};
#endif
    U8 index ,icon_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*get icon width and height*/
#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_FALSE)
    {
#endif /* __MMI_MENSTRUAL__ */
#ifdef __MMI_CALENDAR__
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
    gdi_image_get_dimension_id(
        (U16)LEFT_RED_ARROW_NORMAL,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_PREV],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_PREV]);
    gdi_image_get_dimension_id(
        (U16)RIGHT_RED_ARROW_NORMAL,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_NEXT],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_NEXT]);
#else
    gdi_image_get_dimension_id(
        (U16)CAL_LEFT_ARROW_UP_IMAGE,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_PREV],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_PREV]);
    gdi_image_get_dimension_id(
        (U16)CAL_RIGHT_ARROW_UP_IMAGE,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_NEXT],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_NEXT]);
#endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
#endif /* __MMI_CALENDAR__ */
#ifdef __MMI_MENSTRUAL__
        }
#endif /* __MMI_MENSTRUAL__ */

/*init horizontal select*/
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
    #else
    for (index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index++)
    #endif
    {
        /* Calculate every horizontal select's position and dimension. */
#ifdef __MMI_CALENDAR_NEW_STYLE__
            g_cat83_cal_h_select[index].x = GUI_CALENDAR_FRAME_START_X + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER;
#else
        if (index == 0)
        {
            g_cat83_cal_h_select[index].x = GUI_CALENDAR_FRAME_START_X + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER;
        }
        else
        {
            g_cat83_cal_h_select[index].x = 
                GUI_CALENDAR_FRAME_START_X + (GUI_CALENDAR_FRAME_WIDTH + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER) / 2;
    }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
        if (dm_check_control_exist(MMI_CATEGORY83_ID, DM_STATUS_BAR1))
    {
            g_cat83_cal_h_select[index].y = MMI_status_bar_height;
        }
        else
        {
            g_cat83_cal_h_select[index].y = 0;
        }
        
#ifdef __MMI_CALENDAR_NEW_STYLE__
        g_cat83_cal_h_select[index].width = GUI_CALENDAR_FRAME_WIDTH - (GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER << 1);
    #else
        g_cat83_cal_h_select[index].width = 
            GUI_CALENDAR_FRAME_WIDTH / 2 - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER / 2 - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER;
    #endif
        g_cat83_cal_h_select[index].height = GUI_CALENDAR_FRAME_START_Y - g_cat83_cal_h_select[index].y;

#ifdef __MMI_MENSTRUAL__
        if (g_cat_calendar_is_in_mens == MMI_FALSE)
        {
#endif /* __MMI_MENSTRUAL__ */
        /* init horizontal select prev and next icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index++)
        {
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
            if(icon_index == 0)
            {
#ifdef __MMI_CALENDAR__
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(LEFT_RED_ARROW_NORMAL);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(LEFT_RED_ARROW_PRESSED);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(LEFT_RED_ARROW_NORMAL);
#endif /* __MMI_CALENDAR__ */
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = g_cat83_cal_h_select[index].x;
    }
            else
    {
#ifdef __MMI_CALENDAR__
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(RIGHT_RED_ARROW_NORMAL);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(RIGHT_RED_ARROW_PRESSED);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(RIGHT_RED_ARROW_NORMAL);
#endif /* __MMI_CALENDAR__ */
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = 
                     g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - icon_width[icon_index];
    #ifdef __MMI_SLIM_IMG_RES__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
#endif
            }

#else
            if(icon_index == 0)
        {
        #ifdef __MMI_CALENDAR__
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(CAL_LEFT_ARROW_UP_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(CAL_LEFT_ARROW_DOWN_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(CAL_LEFT_ARROW_DISABLE_IMAGE);
        #endif /* __MMI_CALENDAR__ */
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = g_cat83_cal_h_select[index].x;
        }
            else
            {
        #ifdef __MMI_CALENDAR__
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(CAL_RIGHT_ARROW_UP_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(CAL_RIGHT_ARROW_DOWN_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(CAL_RIGHT_ARROW_DISABLE_IMAGE);
        #endif /* __MMI_CALENDAR__ */
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = 
                     g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - icon_width[icon_index];
    #ifdef __MMI_SLIM_IMG_RES__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
    #endif
    }
#endif /*__MMI_SLIM_IMG_RES__*/
            
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_width = icon_width[icon_index];
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_height = icon_height[icon_index];
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_y = 
                g_cat83_cal_h_select[index].y + (g_cat83_cal_h_select[index].height - icon_height[icon_index]) / 2;

    #ifdef __MMI_TOUCH_SCREEN__
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = 0;
    #endif /* __MMI_TOUCH_SCREEN__ */
        }
#ifdef __MMI_MENSTRUAL__
        }
        else
    {
        #ifdef __MMI_CALENDAR_NEW_STYLE__
                color_index[WGUI_CAL_H_SELECT_ALLOW_PREV] = g_cat_calendar_horizontal_select0_left_filler;
                color_index[WGUI_CAL_H_SELECT_ALLOW_NEXT] = g_cat_calendar_horizontal_select0_right_filler;
        #else
            if (index == 0)
            {
                color_index[WGUI_CAL_H_SELECT_ALLOW_PREV] = g_cat_calendar_horizontal_select0_left_filler;
                color_index[WGUI_CAL_H_SELECT_ALLOW_NEXT] = g_cat_calendar_horizontal_select0_right_filler;
             }
            else
        {
                color_index[WGUI_CAL_H_SELECT_ALLOW_PREV] = g_cat_calendar_horizontal_select1_left_filler;
                color_index[WGUI_CAL_H_SELECT_ALLOW_NEXT] = g_cat_calendar_horizontal_select1_right_filler;
        }
        #endif /*__MMI_CALENDAR_NEW_STYLE__*/

            for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index++)
            {
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = NULL;
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = NULL;
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = NULL;

                if(color_index[icon_index] < GUI_CALENDAR_COLOR_TOTAL)
                {
            #if defined (__MMI_MAINLCD_320X240__)
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_width = WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH * 2;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_height = WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH * 2;
    #else
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_width = WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_height = WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH;
    #endif
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = g_cat83_cal_h_select[index].x;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y =
                        g_cat83_cal_h_select[index].y + (g_cat83_cal_h_select[index].height - g_cat83_cal_h_select[index].icon_info[icon_index].icon_height) / 2;
    }
                else
                {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_width = 0;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_height = 0;
}

        #ifdef __MMI_TOUCH_SCREEN__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = 0;
#endif /* __MMI_TOUCH_SCREEN__ */
            }
        }
#endif /* __MMI_MENSTRUAL__ */
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_draw_horizontal_select
 * DESCRIPTION
 *  Calendar category display horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat83_draw_horizontal_select(U8 index)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_width, string_x = 0; 
    S32 string_width, string_height;
    PU8 icon;
    S8 temp_text[WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH + 1];
    UI_character_type text[WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH + 1];
#ifdef __MMI_MENSTRUAL__
    U8 color_index_prev = GUI_CALENDAR_COLOR_NONE;
    U8 color_index_next = GUI_CALENDAR_COLOR_NONE;
#endif
    U8 seperator;

    U8 icon_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
    #endif
    
    switch (PhnsetGetDateSeperatorFormat())
    {
        case 0:
            seperator = '.';
            break;
    
        case 1:
            seperator = ':';
            break;
    
        case 2:
            seperator = '/';
            break;
    
        case 3:
            seperator = '-';
            break;
    
        default:
            seperator = '.';
            break;
    }


    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(g_cat_calendar_target_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        g_cat83_cal_h_select[index].x,
        g_cat83_cal_h_select[index].y,
        g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer != NULL &&
        g_cat_calendar_abm_layer != GDI_ERROR_HANDLE)
    {    
        gdi_draw_solid_rect(
            g_cat83_cal_h_select[index].x,
            g_cat83_cal_h_select[index].y,
            g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
            g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
#endif /* __GDI_MEMORY_PROFILE_2__ */
    gdi_draw_solid_rect(
        g_cat83_cal_h_select[index].x,
        g_cat83_cal_h_select[index].y,
        g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1,
        GDI_COLOR_WHITE);
    if (g_cat_calendar_bg_id != IMAGE_ID_NULL)
    {
        gdi_image_draw_id(0, 0, g_cat_calendar_bg_id);
    }
    else
    {
        gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_TRUE)
    {
    #ifdef __MMI_CALENDAR_NEW_STYLE__
            color_index_prev = g_cat_calendar_horizontal_select0_left_filler;
            color_index_next = g_cat_calendar_horizontal_select0_right_filler;
    #else
        if (index == 0)
        {
            color_index_prev = g_cat_calendar_horizontal_select0_left_filler;
            color_index_next = g_cat_calendar_horizontal_select0_right_filler;
        }
        if (index == 1)
        {
            color_index_prev = g_cat_calendar_horizontal_select1_left_filler;
            color_index_next = g_cat_calendar_horizontal_select1_right_filler;
        }
    #endif
    }
#endif /* __MMI_MENSTRUAL__ */

    /*prev and next allow*/
#ifdef __MMI_TOUCH_SCREEN__
    for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
    {

        if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
    {
            icon = g_cat83_cal_h_select[index].icon_info[icon_index].down_icon;
    }
        else if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
    {
            icon = g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon;
    }
    else
    {
            icon = g_cat83_cal_h_select[index].icon_info[icon_index].up_icon;
    }
    if(icon != NULL)
    {
        #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            if(g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                wgui_cat83_draw_icon_with_opacity_layer(
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_width,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_height,
                    icon);
            }
            else
        #endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
            {
        gdi_image_draw(
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
            icon);
    }
        }
    #ifdef __MMI_MENSTRUAL__
    else
    {
        /* need draw filler */
            if (g_cat_calendar_is_in_mens == MMI_TRUE && g_cat83_cal_h_select[index].icon_info[icon_index].icon_width != 0)
        {            
            gdi_draw_frame_rect(
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x + g_cat83_cal_h_select[index].icon_info[icon_index].icon_width - 1,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y + g_cat83_cal_h_select[index].icon_info[icon_index].icon_height - 1,                
                gdi_act_color_from_rgb(
                255,
                current_UI_theme->calendar_theme->cell_bg[color_index_prev].r,
                current_UI_theme->calendar_theme->cell_bg[color_index_prev].g,
                current_UI_theme->calendar_theme->cell_bg[color_index_prev].b),
                GDI_COLOR_WHITE,
                1);
        }
        }
    #endif /* __MMI_MENSTRUAL__ */
    }
#endif /* __MMI_TOUCH_SCREEN__ */

    /* Display text */
    cell_x = g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_width;
#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_FALSE)
    {
#endif /* __MMI_MENSTRUAL__ */
    cell_width =
        g_cat83_cal_h_select[index].width -
        g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_width -
        g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_height;
#ifdef __MMI_MENSTRUAL__
    }
    else
    {  
        cell_width =
            g_cat83_cal_h_select[index].width -
            g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_width;
    }
#endif /* __MMI_MENSTRUAL__ */

    /* Show text background */
#ifndef __MMI_CLNDR_FTE_SLIM_RES__
#ifdef __MMI_FTE_SUPPORT__  /*lhm remove IMG_CALENDAR_HORIZONTAL_SELECT_BG*/
    if (g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].up_icon != NULL &&
        g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_NEXT].up_icon != NULL)
        {
            gdi_image_draw_resized_id(
                cell_x,
                g_cat83_cal_h_select[index].y + ((g_cat83_cal_h_select[index].height - g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_height) >> 1),
                g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_NEXT].icon_x - cell_x,
                g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_height,
                IMG_CALENDAR_HORIZONTAL_SELECT_BG);
        }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_CLNDR_FTE_SLIM_RES__*/

#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_FALSE)
    {
#endif /* __MMI_MENSTRUAL__ */
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
    {
        applib_time_struct temp, diff;
        S32 time_compare;
        time_compare = applib_dt_compare_time(
                            &g_cat_calendar_max_time,
                            &g_cat_calendar_highlight_time,
                            &diff);
        if (DT_TIME_LESS == time_compare)
        {
            temp = g_cat_calendar_max_time;
        }
        else
        {
            time_compare = applib_dt_compare_time(
                               &g_cat_calendar_min_time,
                               &g_cat_calendar_highlight_time,
                               &diff);
            if (DT_TIME_GREATER == time_compare)
            {
                temp = g_cat_calendar_min_time;
            }
            else
            {
                temp = g_cat_calendar_highlight_time;
             }
        }
    #ifdef __MMI_CALENDAR_NEW_STYLE__
                switch (PhnsetGetDateFormat())
                {
                    case 0: /* day,month,year */
                    case 1: /* month, day, year */
                        sprintf((S8*)temp_text, "%02d%c%04d", temp.nMonth, seperator, temp.nYear);
                        break;
        #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
                    default:
                        sprintf((S8*)temp_text, "%04d%c%02d", temp.nYear, seperator, temp.nMonth);
                        break;
                }
    #else
            if (index == 0)
            {
                sprintf((S8*)temp_text, "%4d", temp.nYear);
            }
            if (index == 1)
            {
                sprintf((S8*)temp_text, "%d", temp.nMonth);
            }
    #endif /*__MMI_CALENDAR_NEW_STYLE__*/
    }
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
    {
    #ifdef __MMI_TOUCH_SCREEN__
    #ifdef __MMI_CALENDAR_NEW_STYLE__
                switch (PhnsetGetDateFormat())
                {
                    case 0: /* day,month,year */
                    case 1: /* month, day, year */
                        sprintf((S8*)temp_text, "Week%02d%c%04d", applib_dt_get_week_number(&g_cat_calendar_end_time), seperator, g_cat_calendar_end_time.nYear);
                        break;
        #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
                    default:
                        sprintf((S8*)temp_text, "%04d%cWeek%02d", g_cat_calendar_end_time.nYear, seperator, applib_dt_get_week_number(&g_cat_calendar_end_time));
                        break;
                }
    #else
            if (index == 0)
            {
                sprintf((S8*)temp_text, "W%02d", applib_dt_get_week_number(&g_cat_calendar_highlight_time));
            }
            if (index == 1)
            {
                sprintf((S8*)temp_text, "12H");
            }
    #endif /*__MMI_CALENDAR_NEW_STYLE__*/
#else /*__MMI_TOUCH_SCREEN__*/
    #ifdef __MMI_CALENDAR_NEW_STYLE__
                switch (PhnsetGetDateFormat())
                {
                    case 0: /* day,month,year */
                    case 1: /* month, day, year */
                        sprintf((S8*)temp_text, "Week%02d%c%04d", applib_dt_get_week_number(&g_cat_calendar_end_time), seperator, g_cat_calendar_end_time.nYear);
                        break;
        #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
                    default:
                        sprintf((S8*)temp_text, "%04d%cWeek%02d", g_cat_calendar_end_time.nYear, seperator, applib_dt_get_week_number(&g_cat_calendar_end_time));
                        break;
                }
    #else
            if (index == 0)
            {
                sprintf((S8*)temp_text, "Week");
            }
            if (index == 1)
            {
                sprintf((S8*)temp_text, "%2d", applib_dt_get_week_number(&g_cat_calendar_highlight_time));
            }
    #endif /*__MMI_CALENDAR_NEW_STYLE__*/
#endif /*__MMI_TOUCH_SCREEN__*/
    }
    mmi_asc_to_ucs2((S8*)text, temp_text);
#ifdef __MMI_MENSTRUAL__
    }
    else
    {
    #ifndef __MMI_CALENDAR_NEW_STYLE__
        if (index == 0)
    #endif
        {
            /* Set 0 to horizontal select string's end. */
            mmi_ucs2ncpy(
                (S8*)text,
                (S8*)g_cat_calendar_horizontal_select0_string,
                WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH);
            text[WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH] = 0;
        }
    #ifndef __MMI_CALENDAR_NEW_STYLE__
        if (index == 1)
        {
            /* Set 0 to horizontal select string's end. */
            mmi_ucs2ncpy(
                (S8*)text,
                (S8*)g_cat_calendar_horizontal_select1_string,
                WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH);
            text[WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH] = 0;
        }
    #endif
    }
#endif /* __MMI_MENSTRUAL__ */

    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT));
    gui_measure_string((UI_string_type)text, &string_width, &string_height);
    gui_set_text_color(*(current_MMI_theme->calendar_horizontal_text_color));
    gui_set_text_border_color(*(current_MMI_theme->calendar_horizontal_border_color));

    gdi_layer_set_clip(
        cell_x,
        g_cat83_cal_h_select[index].y,
        cell_x + cell_width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);

#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_FALSE)
    {
#endif /* __MMI_MENSTRUAL__ */
    string_x = cell_x + ((cell_width - string_width) >> 1);
#ifdef __MMI_MENSTRUAL__
    }
    else
    {
        string_x = cell_x + 1;
    }
#endif /* __MMI_MENSTRUAL__ */
    //if (r2lMMIFlag)
    if(mmi_fe_get_r2l_state())
    {
        string_x += string_width - 1;
    }

    gui_move_text_cursor(
        string_x,
        g_cat83_cal_h_select[index].y + ((g_cat83_cal_h_select[index].height - string_height) >> 1));

    gui_print_bordered_text((UI_string_type)text);
    gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();

    #ifdef __MMI_CALENDAR_NEW_STYLE__
        gdi_layer_blt_previous(
            cell_x,
            g_cat83_cal_h_select[index].y,
            cell_x + cell_width - 1,
            g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
    #endif
    
    gdi_layer_unlock_frame_buffer();  
    
    gdi_layer_blt_previous(
        g_cat83_cal_h_select[index].x,
        g_cat83_cal_h_select[index].y,
        g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_highlight_change_handler
 * DESCRIPTION
 *  Calendar category highlight change handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat83_highlight_change_handler(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time,
             applib_time_struct start_time,
             applib_time_struct end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_FALSE)
    {
#endif /* __MMI_MENSTRUAL__ */
    if (g_cat_calendar_highlight_change_callback != NULL)
    {
        U8 index ;
    #ifdef __MMI_TOUCH_SCREEN__
        U8 icon_index;
    #endif
        MMI_BOOL change_horizintal_select = MMI_TRUE;
    
    #ifndef __MMI_CALENDAR_NEW_STYLE__
        g_cat_calendar_start_time = start_time;
    #endif
        g_cat_calendar_end_time = end_time;
        g_cat_calendar_highlight_time = highlighted_time;


#ifdef __MMI_CALENDAR_NEW_STYLE__
        index = 0;
#else
        for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
        {
            change_horizintal_select = MMI_TRUE;
    #ifdef __MMI_TOUCH_SCREEN__
            for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
            {
            
                if(wgui_cat83_horizintal_select_switch(index, icon_index) == MMI_TRUE)
                {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                }
                else
                {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
                    {
                        change_horizintal_select = MMI_FALSE;
                    }
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_DISABLED;
                }
            }
    #endif /* __MMI_TOUCH_SCREEN__ */
        
            if (change_horizintal_select)
            {
                wgui_cat83_draw_horizontal_select(index);            
                gdi_layer_blt_previous(
                    g_cat83_cal_h_select[index].x,
                    g_cat83_cal_h_select[index].y,
                    g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
                    g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
            }
        }

        if (g_cat_calendar_highlight_change_callback(type, highlighted_time, start_time, end_time) == MMI_FALSE)
        {
            return;
        }
    }

#ifdef __MMI_CLNDR_EVENT_INFO__
    if (g_cat_calendar_event_query_handler != NULL)
    {
    /* Display the cell event. */
    #if defined(__MMI_CLNDR_EVENT_INFO__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
        S32 entry_x, entry_y, entry_width, entry_height;
        S32 icon_x, icon_width, icon_height;
        S32 string_x, string_width, string_height, string_xwidth;
        S32 i;
        applib_time_struct time_interval;
    
        memset(&time_interval, 0, sizeof(applib_time_struct));
        if (type == GUI_CALENDAR_TYPE_MONTH)
        {
            time_interval.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL;
        }
        if (type == GUI_CALENDAR_TYPE_WEEK)
        {
            time_interval.nHour = GUI_CALENDAR_WEEK_TIME_INTERVAL;
        }
        g_cat_calendar_event_query_handler(
            type,
            highlighted_time,
            time_interval,
            &g_cat_calendar_events);

        entry_width = GUI_CALENDAR_INFOBOX_WIDTH - GUI_CALENDAR_INFOBOX_GAP * 2;
        entry_height = GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
        entry_x = GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_GAP;
        entry_y = GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_GAP;

    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_CALENDAR_INFOBOX));
    gui_set_text_color(*(current_MMI_theme->calendar_infobox_text_color));

    gdi_layer_push_and_set_active(g_cat_calendar_target_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        GUI_CALENDAR_INFOBOX_START_X,
        GUI_CALENDAR_INFOBOX_START_Y,
        GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
        GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer != NULL &&
        g_cat_calendar_abm_layer != GDI_ERROR_HANDLE)
    {    
        gdi_effect_alpha_blending_rect(
            g_cat_calendar_abm_layer,
            GUI_CALENDAR_INFOBOX_START_X,
            GUI_CALENDAR_INFOBOX_START_Y,
            GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
            GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1,
            current_MMI_theme->calendar_infobox_bg_alpha * 255 / 100,
            current_MMI_theme->calendar_infobox_bg_color->r,
            current_MMI_theme->calendar_infobox_bg_color->g,
            current_MMI_theme->calendar_infobox_bg_color->b);
    }
    else
    {
#endif /* __GDI_MEMORY_PROFILE_2__ */
	gdi_draw_solid_rect(
        GUI_CALENDAR_INFOBOX_START_X,
        GUI_CALENDAR_INFOBOX_START_Y,
        GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
        GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1,
        gdi_act_color_from_rgb(
            current_MMI_theme->calendar_infobox_bg_alpha,
            current_MMI_theme->calendar_infobox_bg_color->r,
            current_MMI_theme->calendar_infobox_bg_color->g,
            current_MMI_theme->calendar_infobox_bg_color->b));
#ifdef __GDI_MEMORY_PROFILE_2__
    }
#endif

    for (i = 0; i < g_cat_calendar_events.event_entry_number; i++)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(entry_x, entry_y, entry_x + entry_width - 1, entry_y + entry_height - 1);
        gdi_effect_alpha_blending_rect(
            g_cat_calendar_target_layer,
            entry_x,
            entry_y,
            entry_x + entry_width - 1,
            entry_y + entry_height - 1,
            current_MMI_theme->calendar_infobox_entry_alpha * 255 / 100,
            current_MMI_theme->calendar_infobox_entry_bg_color->r,
            current_MMI_theme->calendar_infobox_entry_bg_color->g,
            current_MMI_theme->calendar_infobox_entry_bg_color->b);

        //if (r2lMMIFlag)
        if(mmi_fe_get_r2l_state())
        {
            icon_x = entry_x + entry_width - GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
        }
        else
        {
            icon_x = entry_x;
        }
        string_x = icon_x;
        if(g_cat_calendar_events.entry_list[i].icon != 0)
        {
            gdi_handle h0, h1, h2, h3;

            gdi_image_get_dimension_id(
                (U16)g_cat_calendar_events.entry_list[i].icon,
                &icon_width,
                &icon_height);
            gdi_layer_push_clip();
            gdi_layer_set_clip(
                icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_height) >> 1),
                icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1) + icon_width - 1,
                entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_height) >> 1) + icon_height - 1);
            gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
            gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
            gdi_push_and_set_alpha_blending_source_layer(g_cat_calendar_target_layer);
            gdi_image_draw_id(
                icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                (U16) g_cat_calendar_events.entry_list[i].icon);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_clip();
            //if (!r2lMMIFlag)
            if(!mmi_fe_get_r2l_state())
            {
                string_x += GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
            }
        }
        else
        {
            icon_width = 0;
            icon_height = 0;
        }

        if (g_cat_calendar_events.entry_list[i].string != NULL &&
            UI_strlen((UI_string_type)(g_cat_calendar_events.entry_list[i].string)) > 0)
        {
            if(g_cat_calendar_events.entry_list[i].string != NULL)
            {
                gui_measure_string(
                    (UI_string_type)g_cat_calendar_events.entry_list[i].string,
                    &string_width,
                    &string_height);
                    string_xwidth = entry_width - GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
                gui_print_truncated_text(
                    string_x,
                    entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - string_height) >> 1),
                    string_xwidth, 
                    (UI_string_type)g_cat_calendar_events.entry_list[i].string);
            }
        }
        
        entry_y += entry_height + GUI_CALENDAR_INFOBOX_GAP;
        gdi_layer_pop_clip();
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(
        GUI_CALENDAR_INFOBOX_START_X,
        GUI_CALENDAR_INFOBOX_START_Y,
        GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
        GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1);
#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
    }
#endif /*__MMI_CLNDR_EVENT_INFO__*/
#ifdef __MMI_MENSTRUAL__
    }
#endif /* __MMI_MENSTRUAL__ */
}



/*****************************************************************************
 * FUNCTION
 *  ExitCategory83Screen
 * DESCRIPTION
 *  exit function of category83
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory83Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif
    reset_softkeys();

    wgui_calendar_close();

#ifdef __MMI_CALENDAR_EVENT__
    g_cat_calendar_cell_data_query_handler = NULL;
#endif
    g_cat_calendar_cell_lunar_query_handler = NULL;
#ifdef __MMI_CLNDR_EVENT_INFO__
    g_cat_calendar_event_query_handler = NULL;
#endif
    g_cat_calendar_highlight_change_callback = NULL;
#if 0
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
#endif
#endif

    /* Free event entry of calendar. */
    for (i = 0; i < WGUI_CAT_CAL_EVENT_ENTRY_NUM; i++)
    {
        if (g_cat_calendar_events.entry_list[i].string != NULL)
        {
            mmi_frm_scrmem_free(g_cat_calendar_events.entry_list[i].string);
            g_cat_calendar_events.entry_list[i].string = NULL;
	    g_cat_calendar_events.entry_list[i].icon = NULL;
        }
    }
    g_cat_calendar_events.event_entry_number = 0;
    g_cat_calendar_events.event_string_max_length = 0;

#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_TRUE)
    {
        g_cat_calendar_horizontal_select0_left_filler = GUI_CALENDAR_COLOR_NONE;
        g_cat_calendar_horizontal_select0_right_filler = GUI_CALENDAR_COLOR_NONE;
        g_cat_calendar_horizontal_select0_string = NULL;
    #ifndef __MMI_CALENDAR_NEW_STYLE__
        g_cat_calendar_horizontal_select1_left_filler = GUI_CALENDAR_COLOR_NONE;
        g_cat_calendar_horizontal_select1_right_filler = GUI_CALENDAR_COLOR_NONE;
        g_cat_calendar_horizontal_select1_string = NULL;
    #endif
        g_cat_calendar_is_in_mens = MMI_FALSE;
    }
#endif /* __MMI_MENSTRUAL__ */

    g_cat_calendar_type = GUI_CALENDAR_TYPE_NONE;
#ifdef __GDI_MEMORY_PROFILE_2__
    g_cat_calendar_abm_layer = NULL;
#endif
    g_cat_calendar_target_layer = NULL;
    g_cat_calendar_bg_id = IMAGE_ID_NULL;
#if 0
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory83HistorySize
 * DESCRIPTION
 *  Gets the history buffer size of category 83
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory83HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_calendar_get_history_size();
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory83History
 * DESCRIPTION
 *  Gets the history buffer of category 83
 * PARAMETERS
 *  history_buffer      [?]     
 * RETURNS
 *  return history buffer
 *****************************************************************************/
U8 *GetCategory83History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GUI_CALENDAR_TYPE_WEEK == g_cat_calendar_type)
    {
        wgui_calendar_get_history(MMI_CATEGORY83_ID, history_buffer);
    }
    return (history_buffer);
}

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
#if !defined (__MMI_MAINLCD_128X128__)
/* under construction !*/
#endif
/* under construction !*/
#endif

#ifdef __MMI_CALENDAR_EVENT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_cell_data_query_handler
 * DESCRIPTION
 *  Register cell data query handler.
 * PARAMETERS
 *  f           [IN]    Is the cell data query handler.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_cell_data_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct start_time,
            applib_time_struct end_time,
            applib_time_struct interval,
            S32 query_count,
            gui_calendar_cell_struct *cells))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_cell_data_query_handler = f;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_cell_lunar_query_handler
 * DESCRIPTION
 *  Register cell lunar query handler.
 * PARAMETERS
 *  f           [IN]    Is the cell lunar query handler.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_cell_lunar_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct cell_time,
            applib_time_struct time_interval,
            PU8 title,
            U32 title_length,
            gui_calendar_cell_detail_info_struct *detail_info))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_cell_lunar_query_handler = f;
}

#ifdef __MMI_CLNDR_EVENT_INFO__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_event_query_handler
 * DESCRIPTION
 *  Register cell event query handler.
 * PARAMETERS
 *  f           [IN]    Is the cell event query handler.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_event_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct cell_time,
            applib_time_struct time_interval,
            wgui_cat83_event_struct *event_info))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_event_query_handler = f;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_highlight_change_callback
 * DESCRIPTION
 *  Register highlight select callback.
 * PARAMETERS
 *  f           [IN]    Is the highlight change callback.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_highlight_change_callback(
          MMI_BOOL (*f)(
                gui_calendar_type_enum type,
                applib_time_struct highlighted_time,
                applib_time_struct start_time,
                applib_time_struct end_time))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_highlight_change_callback = f;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_highlight_select_callback
 * DESCRIPTION
 *  Register highlight select callback.
 * PARAMETERS
 *  f           [IN]    Is the highlight select callback.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_highlight_select_callback(
      void (*f)(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_cat_calendar_highlight_select_callback = f;
    wgui_calendar_register_highlight_select_function(f);
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_handle_control_area
 * DESCRIPTION
 *  This function is only set the layers to calendar component.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_handle_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer == NULL)
    {
        g_cat_calendar_abm_layer = dm_get_scr_bg_layer();
        if (g_cat_calendar_abm_layer != NULL &&
            g_cat_calendar_abm_layer != GDI_ERROR_HANDLE)
        {
            wgui_calendar_set_abm_layer(g_cat_calendar_abm_layer);
        }
    }
#endif
    if (g_cat_calendar_target_layer == NULL)
    {
        gdi_layer_get_base_handle(&g_cat_calendar_target_layer);
        if (g_cat_calendar_target_layer != NULL &&
            g_cat_calendar_target_layer != GDI_ERROR_HANDLE)
        {
            wgui_calendar_set_target_layer(g_cat_calendar_target_layer);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory83Screen
 * DESCRIPTION
 *  category screen of integrated calendar (monthly/weekly and menstral)
 * PARAMETERS
 *  bg_id               [IN]    Is the background of calendar.
 *  type                [IN]    Is the type of calendar.
 *  max_date            [IN]    Is the max date to display.
 *  min_date            [IN]    Is the min date to display.
 *  show_date           [IN]    Is the date to show.
 *  str_LeftSoftkey     [IN]    The string of left softkey.
 *  str_rightSoftkey    [IN]    The string of right softkey.
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory83Screen(
      UI_image_ID_type bg_id,
      gui_calendar_type_enum type,
      applib_time_struct max_date,
      applib_time_struct min_date,
      applib_time_struct show_date,
      MMI_BOOL is_status_bar,
      U8 *str_LeftSoftkey,
      U8 *str_rightSoftkey,
      U8 *history_buffer,
      U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_flags = DM_CLEAR_SCREEN_BACKGROUND;
    S32 i;
#if 0
/* under construction !*/
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetupCategoryKeyHandlers();

    /* Create calendar component. */
#ifdef __MMI_MENSTRUAL__
    if (g_cat_calendar_is_in_mens == MMI_FALSE)
    {
#endif /* __MMI_MENSTRUAL__ */
    /* Create the memory of event info. */
    for (i = 0; i < WGUI_CAT_CAL_EVENT_ENTRY_NUM; i++)
    {
        g_cat_calendar_events.entry_list[i].string = (U8*)mmi_frm_scrmem_alloc(WGUI_CAT_CAL_EVENT_ENTRY_SIZE);
		MMI_DBG_ASSERT(g_cat_calendar_events.entry_list[i].string != NULL);
		memset(g_cat_calendar_events.entry_list[i].string, 0, WGUI_CAT_CAL_EVENT_ENTRY_SIZE);
    }
    g_cat_calendar_events.event_entry_number = WGUI_CAT_CAL_EVENT_ENTRY_NUM;
    g_cat_calendar_events.event_string_max_length = WGUI_CAT_CAL_EVENT_STRING_MAX_LENGTH * ENCODING_LENGTH;
#ifdef __MMI_MENSTRUAL__
    }
#endif /* __MMI_MENSTRUAL__ */

    /* Record the max / min time and highlight time. */
    g_cat_calendar_type = type;
    g_cat_calendar_max_time = max_date;
    g_cat_calendar_min_time = min_date;
    g_cat_calendar_highlight_time = show_date;

    wgui_calendar_create(
        g_cat_calendar_type,
        max_date,
        min_date,
        show_date,
        flag);
    wgui_calendar_set_key_handler();

    if (history_buffer != NULL)
    {
        wgui_calendar_set_history(MMI_CATEGORY83_ID, history_buffer);
    }

#ifdef __MMI_CALENDAR_EVENT__
    if (g_cat_calendar_cell_data_query_handler != NULL)
    {
        wgui_calendar_register_cell_data_query_handler(
            g_cat_calendar_cell_data_query_handler);
    }
#endif
    if (g_cat_calendar_cell_lunar_query_handler != NULL)
    {
        wgui_calendar_register_cell_detail_query_handler(
            g_cat_calendar_cell_lunar_query_handler);
    }
    wgui_calendar_register_highlight_change_function(
        wgui_cat83_highlight_change_handler);

#ifdef __MMI_MENSTRUAL__
        if (g_cat_calendar_is_in_mens != MMI_FALSE)
    {
        wgui_calendar_set_flags_on(GUI_CALENDAR_HIDE_CURRENT_BACKGROUND);
    }
#endif /* __MMI_MENSTRUAL__ */


    if (type == GUI_CALENDAR_TYPE_WEEK)
    {
        wgui_calendar_set_flags_on(GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_ONE_LINE);
    #if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_CLNDR_240X320_LARGE_FONT_SUPPORT__)
        wgui_calendar_set_flags_on(GUI_CALENDAR_WEEK_HIDE_WEEKDAY_STRING);
    #endif
    }

#if 0
#ifdef __MMI_TOUCH_SCREEN__
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
#endif

/*init horizontal select */
    wgui_cat83_init_horizontal_select();  

    gdi_layer_lock_frame_buffer();
    if (bg_id != NULL)
    {
        dm_set_scr_bg_image(bg_id, NULL, 0, 0, 255);
        g_cat_calendar_bg_id = bg_id;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gdi_layer_unlock_frame_buffer();
    dm_register_category_controlled_callback(wgui_cat83_handle_control_area);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_abort_hdlr, MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */

    set_left_softkey_label((UI_string_type)str_LeftSoftkey);
    set_right_softkey_label((UI_string_type)str_rightSoftkey);

    if (is_status_bar == MMI_FALSE)
    {
        dm_data_flags |= DM_NO_STATUS_BAR;
    }
    
    wgui_cat_setup_category(MMI_CATEGORY83_ID, dm_data_flags, ExitCategory83Screen, GetCategory83History, GetCategory83HistorySize);
    dm_redraw_category_screen();
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_FTE_SUPPORT__)&&defined(__MMI_TOUCH_SCREEN__)&&defined(__MMI_ICON_BAR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  ShowCategory83Screen
 * DESCRIPTION
 *  category screen of integrated calendar (monthly/weekly and menstral)
 * PARAMETERS
 *  bg_id                       [IN]        
 *  horizon_string_list         [IN]        Horizontal string list
 *  cell                        [IN]        2 dimension cell array
 *  num_of_row                  [IN]        Number of row
 *  num_of_column               [IN]        Number of column
 *  current_row                 [IN]        Row of current time
 *  current_column              [IN]        Column of current time
 *  highlighted_row             [IN]        Highlighted row
 *  highlighted_column          [IN]        Highlighted column
 *  is_status_bar               [IN]  
 *  item_count                  [IN]
 *  resource_array              [IN]
 *  callback                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9004_show(
      UI_image_ID_type bg_id,
      gui_calendar_type_enum type,
      applib_time_struct max_date,
      applib_time_struct min_date,
      applib_time_struct show_date,
      MMI_BOOL is_status_bar,
      U8 *str_LeftSoftkey,
      U8 *str_rightSoftkey,
      S32 item_count,
      gui_icon_bar_item_resource_struct *resource_array,
      GUIIconbarItemCallback callback,
      MMI_BOOL *icon_bar_enable_state,
      U8 *history_buffer,
      U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X480__)
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X480__)
    wgui_icon_bar_setup_by_resource(
        item_count,
        resource_array,
        callback);
    for(i = 0; i < item_count; i++)
    {
        wgui_icon_bar_set_item_enable_state(i, icon_bar_enable_state[i]);
    }
#endif /* __MMI_MAINLCD_320X480__ */
    
    ShowCategory83Screen(
        bg_id,
        type,
        max_date,
        min_date,
        show_date,
        is_status_bar,
        str_LeftSoftkey,
        str_rightSoftkey,
        history_buffer,
        flag);
}
#endif /* defined(__MMI_FTE_SUPPORT__)&&defined(__MMI_TOUCH_SCREEN__)&&defined(__MMI_ICON_BAR_SUPPORT__)*/


#ifdef __MMI_MENSTRUAL__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_set_mens_horizontal_select
 * DESCRIPTION
 *  Set the horizontal select content of health
 * PARAMETERS
 *  message         [IN]    Message to show on status bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_set_mens_horizontal_select(
      U8 left_filler_index0,
      U8 right_filler_index0,
      U8 *string0,
      U8 left_filler_index1,
      U8 right_filler_index1,
      U8 *string1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_horizontal_select0_left_filler = left_filler_index0;
    g_cat_calendar_horizontal_select0_right_filler = right_filler_index0;
    g_cat_calendar_horizontal_select0_string = string0;
#ifndef __MMI_CALENDAR_NEW_STYLE__
    g_cat_calendar_horizontal_select1_left_filler = left_filler_index1;
    g_cat_calendar_horizontal_select1_right_filler = right_filler_index1;
    g_cat_calendar_horizontal_select1_string = string1;
#endif
    g_cat_calendar_is_in_mens = MMI_TRUE;
}
#endif /* __MMI_MENSTRUAL__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_refresh_events_reminder
 * DESCRIPTION
 *  Update calendar events reminder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_refresh_events_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_calendar_update();
}


