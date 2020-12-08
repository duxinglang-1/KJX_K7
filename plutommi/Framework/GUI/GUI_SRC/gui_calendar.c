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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  gui_calendar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  calendar - UI component
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

 
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

/*****************************************************************************
 * include
 ****************************************************************************/
#include "kal_release.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"

#include "string.h"
#include "stdio.h"
#include "Unicodexdcl.h"

#include "MMI_trc_Int.h"
#include "GlobalResDef.h"
#include "gui_themes.h"
#include "gui_switch.h"
#include "gui_calendar.h"
#include "mmi_rp_app_uiframework_def.h"
#ifndef __COSMOS_MMI__
#include "Mmi_rp_app_calendar_def.h"
#endif
#include "ScrMemMgrGprot_Int.h"
#include "PixcomFontEngine.h"
#include "custom_mmi_default_value.h"
#include "wgui_inputs.h"
#include "wgui_categories_util.h"
#include "gui_font_size.h"
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif 

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/

#include "gui.h"
#include "wgui.h"

/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
static void gui_calendar_adjust_layout(gui_calendar_struct *c);
static void gui_calendar_init_date(gui_calendar_struct *c);
static void gui_calendar_adjust_date_boundary(
             gui_calendar_struct *c,
             applib_time_struct *start_time,
             applib_time_struct *end_time,
             applib_time_struct current_time);
static void gui_calendar_get_time(
             gui_calendar_struct *c,
             U32 row,
             U32 column,
             applib_time_struct *time,
             MMI_BOOL *is_valid);
#ifdef __MMI_TOUCH_SCREEN__
static void gui_calendar_adjust_switch_enable_state(gui_calendar_struct *c);
#endif

static void gui_calendar_query_cell_data(gui_calendar_struct *c);
static void gui_calendar_general_switch_update(
                gui_calendar_struct* c, 
			    applib_time_struct *highlight_time, 
			    U8 nHour, 
                gui_calendar_switch_update_enum style);
static void gui_calendar_malloc_cell_data_buffer(gui_calendar_struct *c);
static void gui_calendar_construct_cell_date(gui_calendar_struct *c);

static void gui_calendar_draw_bg(
             gui_calendar_struct* c,
             S32 x,
             S32 y,
             S32 width,
             S32 height);
static void gui_calendar_draw_bg_frame(gui_calendar_struct* c);
static void gui_calendar_draw_cell(
             gui_calendar_struct* c,
             S32 cell_x,
             S32 cell_y,
             S32 cell_width,
             S32 cell_height,
             S32 line_height,
             S32 base_line,
             S32 cell_date,
             gui_calendar_cell_struct *cell_data,
             U32 flags,
             kal_uint8 DayIndex);
static void gui_calendar_draw_horizontal_string(gui_calendar_struct* c);
static void gui_calendar_draw_vertical_select(gui_calendar_struct* c);
static void gui_calendar_draw_title(gui_calendar_struct* c);
#ifdef __MMI_MAINLCD_96X64__
static void gui_calendar_scrolling_detail_text_redraw_bg(S32 x1,S32 y1,S32 x2,S32 y2);
static void gui_calendar_scrolling_detail_text_handle(void);
static void gui_calendar_scrolling_title_text_redraw_bg(S32 x1,S32 y1,S32 x2,S32 y2);
static void gui_calendar_scrolling_title_text_handle(void);
#endif
static void gui_calendar_draw_detail(void);
static void gui_calendar_highlight_cell(gui_calendar_struct* c);
static void gui_calendar_unhighlight_cell(gui_calendar_struct* c);

static void gui_calendar_general_switch_handler(gui_calendar_key_direction_enum direction);
static void gui_calendar_left_arrow_key_handler(void);
static void gui_calendar_right_arrow_key_handler(void);
static void gui_calendar_up_arrow_key_handler(void);
static void gui_calendar_down_arrow_key_handler(void);
static void gui_calendar_side_up_key_handler(void);
static void gui_calendar_side_down_key_handler(void);

static void gui_calendar_calculate_highlight_position(
             gui_calendar_struct* c,
             U32 *row,
             U32 *column);

#ifdef __MMI_TOUCH_SCREEN__
static void gui_calendar_translate_pen_position(gui_calendar_struct* c, S32 x, S32 y, U32* pen_row, U32* pen_column);
static void gui_calendar_redraw_vertical_select(
                gui_calendar_struct* c,
                void func(gui_calendar_struct* c, gui_calendar_time_switch_enum type));
static MMI_BOOL gui_calendar_is_vertical_select_prev_icon(
                    gui_calendar_struct* c,
                    mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_is_vertical_select_next_icon(
                    gui_calendar_struct* c,
                    mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_PenDownHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_PenUpHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_PenMoveHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
static MMI_BOOL gui_calendar_PenAbortHandler(gui_calendar_struct* c, mmi_pen_point_struct pos);
MMI_BOOL gui_calendar_translate_pen_event(gui_calendar_struct *c, mmi_pen_event_type_enum pen_event, S16 x, S16 y);

#ifdef __MMI_CALENDAR_ENLARGE_CELL__
static void gui_calendar_enlarge_cell(gui_calendar_struct* c);
static void gui_calendar_recover_enlarge_cell(gui_calendar_struct* c);
#endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
#endif /*__MMI_TOUCH_SCREEN__*/

static gui_calendar_struct* current_calendar_pointer = NULL;

extern S32 UI_strlen(UI_string_type text);
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetDateSeperatorFormat(void);

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */


/*****************************************************************************
 * Local Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_default_hide_function
 * DESCRIPTION
 *  Use transparent color to redraw screen's calendar background.
 * PARAMETERS
 *  x1      [IN]     Area to redraw
 *  y1      [IN]     Area to redraw
 *  x2      [IN]     Area to redraw
 *  y2      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_default_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x, layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gui_push_clip();
    gui_set_clip(
        x1 - layer_offset_x,
        y1 - layer_offset_y,
        x2 - layer_offset_x,
        y2 - layer_offset_y);
    gdi_draw_solid_rect(
        x1 - layer_offset_x,
        y1 - layer_offset_y,
        x2 - layer_offset_x,
        y2 - layer_offset_y,
#ifdef __MMI_MAINLCD_96X64__
        GDI_COLOR_BLACK);
#else
        GDI_COLOR_TRANSPARENT);
#endif
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_get_time
 * DESCRIPTION
 *  Get the time of given row and column.
 * PARAMETERS
 *  c           [IN]        Is the calendar pointer.
 *  row         [IN]        Given row.
 *  column      [IN]        Given column.
 *  time        [IN/OUT]    The time of given row and column.
 *  is_valid    [IN]        Whether the time is a valid date.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_get_time(
             gui_calendar_struct *c,
             U32 row,
             U32 column,
             applib_time_struct *time,
             MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct inc, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    *is_valid = MMI_FALSE;
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {		
        inc.nDay = row * c->column + column;
        applib_dt_increase_time(
            (applib_time_struct*)&c->start_time,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
		if (result.nDay > applib_dt_last_day_of_mon(result.nMonth, result.nYear))
		{
			applib_time_struct temp;
			memset(&temp, 0, sizeof(applib_time_struct));
			temp = result;
			temp.nDay = applib_dt_last_day_of_mon(result.nMonth, result.nYear);
			inc.nDay = result.nDay - applib_dt_last_day_of_mon(result.nMonth, result.nYear);
			applib_dt_increase_time(
                (applib_time_struct*)&temp,
                (applib_time_struct*)&inc,
                (applib_time_struct*)&result);
		}
        if (result.nMonth == c->highlight_time.nMonth)
        {
            *is_valid = MMI_TRUE;
        }
    }
    if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        inc.nDay = column;
        inc.nHour = row * GUI_CALENDAR_WEEK_TIME_INTERVAL;
        applib_dt_increase_time(
            (applib_time_struct*)&c->start_time,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);

        if ((result.nYear >= c->min_time.nYear) && (result.nYear <= c->max_time.nYear))
        {
            *is_valid = MMI_TRUE;
        }
    }
    if ((*is_valid) == MMI_TRUE)
    {
        *time = result;
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_adjust_switch_enable_state
 * DESCRIPTION
 *  Adjust the prev/next switch icon enable state.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_adjust_switch_enable_state(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct temp;
    applib_time_struct inc, result, diff;
    applib_time_struct min_time, max_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    memset(&diff, 0, sizeof(applib_time_struct));
    memset(&min_time, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));

    /* Calculate the real min display time. */
    gui_calendar_adjust_date_boundary(
        c,
        &min_time,
        &temp,
        c->min_time);
    /* Calculate the real min display time. */
    gui_calendar_adjust_date_boundary(
        c,
        &temp,
        &max_time,
        c->max_time);

    c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    if (c->start_time.nYear == min_time.nYear &&
        c->start_time.nMonth == min_time.nMonth)
    {
        if (c->type == GUI_CALENDAR_TYPE_MONTH && c->start_time.nDay == min_time.nDay ||
            (c->type == GUI_CALENDAR_TYPE_WEEK && c->start_time.nDay == min_time.nDay))
        {
            c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
        }
    }
    if (c->end_time.nYear == max_time.nYear &&
        c->end_time.nMonth == max_time.nMonth)
    {
        if (c->type == GUI_CALENDAR_TYPE_MONTH && c->end_time.nDay == max_time.nDay ||
            (c->type == GUI_CALENDAR_TYPE_WEEK && c->end_time.nDay == max_time.nDay))
        {
            c->title.next_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
        }
    }

    c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    if (c->type == GUI_CALENDAR_TYPE_WEEK && c->start_time.nHour == 0)
    {
        c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
    }
    if (c->type == GUI_CALENDAR_TYPE_WEEK && c->end_time.nHour == DT_HRS_PRE_DAY)
    {
        c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_construct_cell_date
 * DESCRIPTION
 *  Construct the cell date of calendar.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_construct_cell_date(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    gui_calendar_adjust_date_boundary(
        c,
        &(c->start_time),
        &(c->end_time),
        c->highlight_time);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_init_date
 * DESCRIPTION
 *  Init the date boundary of calendar.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_init_date(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct temp;
    applib_time_struct inc, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));

    c->min_time.DayIndex = applib_dt_dow(c->min_time.nYear, c->min_time.nMonth, c->min_time.nDay);
    c->max_time.DayIndex = applib_dt_dow(c->max_time.nYear, c->max_time.nMonth, c->max_time.nDay);
    /* Set the date boundary of monthly view or weekly view. */
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
        temp.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL;
        c->time_interval = temp;

        temp.nYear = c->highlight_time.nYear;
        temp.nMonth = c->highlight_time.nMonth;
        temp.nDay = c->highlight_time.nDay;
        temp.DayIndex = applib_dt_dow(temp.nYear, temp.nMonth, temp.nDay);
        c->highlight_time = temp;
    }
    else if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        temp.nHour = GUI_CALENDAR_WEEK_TIME_INTERVAL;
        c->time_interval = temp;

        c->min_time.nHour = 0;
        c->max_time.nHour = DT_HRS_PRE_DAY;

        /* Calculate the highlight time. */
        temp.nHour = c->highlight_time.nHour % GUI_CALENDAR_WEEK_TIME_INTERVAL;
        if (temp.nHour != 0)
        {
            c->highlight_time.nHour = c->highlight_time.nHour - temp.nHour;
        }
        c->highlight_time.nMin = 0;
        c->highlight_time.nSec = 0;
        c->highlight_time.DayIndex = applib_dt_dow(c->highlight_time.nYear, c->highlight_time.nMonth, c->highlight_time.nDay);

        /* Calculate the start hour and end hour of week view */
        c->start_time.nHour = c->highlight_time.nHour;
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
    #else
		/* Following set of start time and end time is a trick method to sync calendar App's code.
		 * After calendar app finish its revise, we need remove this code and use above code.
		 */
		if ((c->highlight_time.nHour / GUI_CALENDAR_WEEK_TIME_INTERVAL) > c->row)
        {
            c->start_time.nHour = c->row * GUI_CALENDAR_WEEK_TIME_INTERVAL;
        }
        else
        {
            c->start_time.nHour = c->highlight_time.nHour;
        }
        c->end_time.nHour = c->start_time.nHour + GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
		if (c->end_time.nHour > DT_HRS_PRE_DAY)
		{
            c->start_time.nHour = c->start_time.nHour - (c->end_time.nHour - DT_HRS_PRE_DAY);
			c->end_time.nHour = DT_HRS_PRE_DAY;
		}
    #endif
        gui_calendar_adjust_date_boundary(
            c,
            &(c->start_time),
            &(c->end_time),
            c->highlight_time);
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_adjust_date_boundary
 * DESCRIPTION
 *  Adjust the date boundary of calendar.
 * PARAMETERS
 *  c               [IN]        Is the calendar pointer.
 *  start_time      [IN/OUT]    Is the start time.
 *  end_time        [IN/OUT]    Is the end time.
 *  current_time    [IN]        Is the current time.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_adjust_date_boundary(
             gui_calendar_struct *c,
             applib_time_struct *start_time,
             applib_time_struct *end_time,
             applib_time_struct current_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct temp;
    applib_time_struct inc, result;
    U8 week_start_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    MMI_DBG_ASSERT((start_time != NULL) && (end_time != NULL));
    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));

    /* Set the date boundary of monthly view or weekly view. */
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
        temp = current_time;
#ifndef __MMI_MAINLCD_96X64__
        /* Get the first day of cell to display. */
        temp.nDay = 1;
#endif
        temp.DayIndex = applib_dt_dow(temp.nYear, temp.nMonth, temp.nDay);

        /* If Sunday is the begin of one week. */
        if (c->flags & GUI_CALENDAR_SUNDAY_AS_BEGIN)
        {
            week_start_index = GUI_CALENDAR_WEEK_DAY_SUNDAY;
        }
        else
        {
            week_start_index = GUI_CALENDAR_WEEK_DAY_MONDAY;
        }
        
        /* Get the start date of the first valid row. */
        if (temp.DayIndex != week_start_index)
        {
            inc.nDay = temp.DayIndex - week_start_index + GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            if (inc.nDay >= GUI_CALENDAR_WEEK_DAY_OF_WEEK)
            {
                inc.nDay -= GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            }
        }
        applib_dt_decrease_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
#ifdef __MMI_MAINLCD_96X64__
        /*if 1st day of month can start in first row, dec one week*/
        inc.nDay = 1;
        applib_dt_decrease_time(&result,&inc,&temp);
        if(temp.nDay <= GUI_CALENDAR_WEEK_DAY_OF_WEEK)
        {
            temp = result;
            inc.nDay = GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            applib_dt_decrease_time(&temp,&inc,&result); 
        }
        else
        {
            inc.nDay = GUI_CALENDAR_WEEK_DAY_OF_WEEK*2;
            applib_dt_increase_time(&result,&inc,&temp);
            /*2nd row is invalid, dec one week*/
            if(current_time.nMonth == result.nMonth)
            {
                temp.nDay = applib_dt_last_day_of_mon(result.nMonth, result.nYear);
                if((temp.nDay - result.nDay) <= GUI_CALENDAR_WEEK_DAY_OF_WEEK)
                {
                    temp = result;
        			inc.nDay = GUI_CALENDAR_WEEK_DAY_OF_WEEK;
                    applib_dt_decrease_time(&temp,&inc,&result); 
                }
            }
            /*1st row is invalid, inc one week*/
            else if(current_time.nMonth == temp.nMonth)
            {
                if(temp.nDay <= GUI_CALENDAR_WEEK_DAY_OF_WEEK)
                {
                    temp = result;
        			inc.nDay = GUI_CALENDAR_WEEK_DAY_OF_WEEK;
                    applib_dt_increase_time(&temp,&inc,&result);
                }
            }
            else
            {
                ASSERT(0);
            }
        }
	    if (result.nYear > temp.nYear)
	    {
            *start_time = current_time;
	    }
	    else
	    {
            *start_time = result;
	    }
        temp = result;		
        /* Get the last day of cell to display. */
        //temp.nDay = applib_dt_last_day_of_mon(temp.nMonth, temp.nYear);
        inc.nDay = c->row * c->column - 1;// - temp.nDay - inc.nDay;
        applib_dt_increase_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
        *end_time = result;
#else

	    if (result.nYear > temp.nYear)
	    {
            *start_time = current_time;
	    }
	    else
	    {
            *start_time = result;
	    }

        /* Get the last day of cell to display. */
        temp.nDay = applib_dt_last_day_of_mon(temp.nMonth, temp.nYear);
        inc.nDay = c->row * c->column - temp.nDay - inc.nDay;
        applib_dt_increase_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
        *end_time = result;
#endif
    }
    else if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        temp.nHour = start_time->nHour;
        temp.nYear = current_time.nYear;
        temp.nMonth = current_time.nMonth;
        temp.nDay = current_time.nDay;
        temp.DayIndex = applib_dt_dow(temp.nYear, temp.nMonth, temp.nDay);

        /* If Sunday is the begin of one week. */
        if (c->flags & GUI_CALENDAR_SUNDAY_AS_BEGIN)
        {
            week_start_index = GUI_CALENDAR_WEEK_DAY_SUNDAY;
        }
        else
        {
            week_start_index = GUI_CALENDAR_WEEK_DAY_MONDAY;
        }
        
        if (temp.DayIndex != week_start_index)
        {
            inc.nDay = temp.DayIndex - week_start_index + GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            if (inc.nDay >= GUI_CALENDAR_WEEK_DAY_OF_WEEK)
            {
                inc.nDay -= GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            }
            applib_dt_decrease_time(&temp, &inc, &result);
			result.nHour = start_time->nHour;
            *start_time = result;
        }
        else
        {
            *start_time = temp;
            result = temp;
        }

        temp = result;
        inc.nDay = c->column - 1;
        applib_dt_increase_time(&temp, &inc, &result);
		result.nHour = end_time->nHour;
        *end_time = result;
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_adjust_layout
 * DESCRIPTION
 *  Adjust the layout of calendar horizontal string, vertical select and cell
 *  array.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_adjust_layout(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_offset_x, temp_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    temp_offset_x = (c->cell_array.width - (c->column - 1) * GUI_CALENDAR_FRAME_LINE_PIXEL) % c->column;
    c->cell_array.width -= temp_offset_x;
    c->cell_array.cell_width = (c->cell_array.width - (c->column - 1) * GUI_CALENDAR_FRAME_LINE_PIXEL) / c->column;
    c->horizontal_string.width = c->cell_array.width;
    c->horizontal_string.cell_width = c->cell_array.cell_width;
    if (temp_offset_x != 0)
    {
        /* Adjust the cell array to center align if vertical width is 0. */
        if (c->vertical_select.width == 0)
        {
            c->cell_array.x = (c->width - c->cell_array.width - 2 * GUI_CALENDAR_FRAME_LINE_PIXEL) / 2;
            c->horizontal_string.x = c->cell_array.x;
        }
    }

    temp_offset_y = (c->cell_array.height - (c->row - 1) * GUI_CALENDAR_FRAME_LINE_PIXEL) % c->row;
    c->cell_array.height -= temp_offset_y;
    c->cell_array.cell_height = (c->cell_array.height - (c->row - 1) * GUI_CALENDAR_FRAME_LINE_PIXEL) / c->row;
//    c->vertical_select.height = c->cell_array.height;
//    c->horizontal_string.cell_height = c->cell_array.cell_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_init_layout
 * DESCRIPTION
 *  Init the position and dimension with default value.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_init_layout(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    /* Set the layout of calendar. */
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    if (c->is_on_idle)
    {
        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
            c->x = GUI_CALENDAR_MONTH_FRAME_START_X_FOR_IDLE;
            c->y = GUI_CALENDAR_MONTH_FRAME_START_Y_FOR_IDLE;
            c->width = GUI_CALENDAR_MONTH_FRAME_START_WIDTH_FOR_IDLE;
            c->height = GUI_CALENDAR_MONTH_FRAME_START_HEIGHT_FOR_IDLE;
            //GUI_CALENDAR_FRAME_LINE_PIXEL = GUI_CALENDAR_FRAME_LINE_PIXEL;

            c->horizontal_string.x = GUI_CALENDAR_MONTH_HORIZON_STRING_X_FOR_IDLE - c->x;
            c->horizontal_string.y = GUI_CALENDAR_MONTH_HORIZON_STRING_Y_FOR_IDLE - c->y;
            c->horizontal_string.width = GUI_CALENDAR_MONTH_HORIZON_STRING_WIDTH_FOR_IDLE;
            c->horizontal_string.height = 0;//GUI_CALENDAR_MONTH_HORIZON_STRING_HEIGHT_FOR_IDLE;

            c->title.x = GUI_CALENDAR_FRAME_LINE_PIXEL;
            c->title.y = c->horizontal_string.y - GUI_CALENDAR_MONTH_TITLE_HEIGHT_FOR_IDLE;
            c->title.width = c->width - GUI_CALENDAR_FRAME_LINE_PIXEL * 2;
            c->title.height = GUI_CALENDAR_MONTH_TITLE_HEIGHT_FOR_IDLE;

            c->vertical_select.x = 0;
            c->vertical_select.y = 0;
            c->vertical_select.width = 0;
            c->vertical_select.height = 0;

            c->cell_array.x = GUI_CALENDAR_MONTH_CELL_ARRAY_X_FOR_IDLE - c->x;
            c->cell_array.y = GUI_CALENDAR_MONTH_CELL_ARRAY_Y_FOR_IDLE - c->y;
            c->cell_array.width = GUI_CALENDAR_MONTH_CELL_ARRAY_WIDTH_FOR_IDLE;
            c->cell_array.height = GUI_CALENDAR_MONTH_CELL_ARRAY_HEIGHT_FOR_IDLE;
        }
        if (c->type == GUI_CALENDAR_TYPE_WEEK)
        {
            c->x = GUI_CALENDAR_WEEK_CONTENT_X_FOR_IDLE;
            c->y = GUI_CALENDAR_WEEK_CONTENT_Y_FOR_IDLE;
            c->width = GUI_CALENDAR_WEEK_CONTENT_WIDTH_FOR_IDLE;
            c->height = GUI_CAKENDAR_WEEK_CONTENT_HEIGHT_FOR_IDLE;

            c->title.x = GUI_CALENDAR_FRAME_LINE_PIXEL;
            c->title.y = GUI_CALENDAR_WEEK_TITLE_Y_FOR_IDLE - c->y;
            c->title.width = c->width - GUI_CALENDAR_FRAME_LINE_PIXEL * 2;
            c->title.height = GUI_CALENDAR_WEEK_TITLE_HEIGHT_FOR_IDLE;

            c->vertical_select.x = 0;
            c->vertical_select.y = 0;
            c->vertical_select.width = 0;
            c->vertical_select.height = 0;

            c->horizontal_string.x = GUI_CALENDAR_WEEK_HORIZON_STRING_X_FOR_IDLE - c->x;
            c->horizontal_string.y = GUI_CALENDAR_WEEK_HORIZON_STRING_Y_FOR_IDLE - c->y;
            c->horizontal_string.width = GUI_CALENDAR_WEEK_HORIZON_STRING_WIDTH_FOR_IDLE;
            c->horizontal_string.height = GUI_CALENDAR_WEEK_HORIZON_STRING_HEIGHT_FOR_IDLE;

            c->cell_array.x = GUI_CALENDAR_WEEK_CELL_ARRAY_X_FOR_IDLE - c->x;
            c->cell_array.y = GUI_CALENDAR_WEEK_CELL_ARRAY_Y_FOR_IDLE - c->y;
            c->cell_array.width = GUI_CALENDAR_WEEK_CELL_ARRAY_WIDTH_FOR_IDLE;
            c->cell_array.height = GUI_CALENDAR_WEEK_CELL_ARRAY_HEIGHT_FOR_IDLE;
        }        
    }
    else
    {
#endif
    c->x = GUI_CALENDAR_FRAME_START_X;
    c->y = GUI_CALENDAR_FRAME_START_Y;
    c->width = GUI_CALENDAR_FRAME_WIDTH;
    c->height = GUI_CALENDAR_FRAME_HEIGHT;

    //GUI_CALENDAR_FRAME_LINE_PIXEL = GUI_CALENDAR_FRAME_LINE_PIXEL;

    /* Set the calendar title layout. */
    c->title.x = GUI_CALENDAR_FRAME_LINE_PIXEL;
    c->title.y = GUI_CALENDAR_FRAME_LINE_PIXEL;
    c->title.width = c->width - GUI_CALENDAR_FRAME_LINE_PIXEL * 2;
    c->title.height = GUI_CALENDAR_TITLE_HEIGHT;

    /* Set the calendar vertical select layout. */
    c->vertical_select.x = GUI_CALENDAR_FRAME_LINE_PIXEL;
    c->vertical_select.y = c->title.y + c->title.height + GUI_CALENDAR_FRAME_LINE_PIXEL;
    c->vertical_select.width = GUI_CALENDAR_VERTICAL_SELECT_WIDTH;
    c->vertical_select.height = c->height - c->title.height - GUI_CALENDAR_FRAME_LINE_PIXEL * 3;
    if (c->title.height == 0)
    {
        c->vertical_select.y = c->vertical_select.y - GUI_CALENDAR_FRAME_LINE_PIXEL;
        c->vertical_select.height = c->vertical_select.height + GUI_CALENDAR_FRAME_LINE_PIXEL;
    }

    /* Set the calendar horizontal string layout. */
    c->horizontal_string.x = c->vertical_select.x + c->vertical_select.width + GUI_CALENDAR_FRAME_LINE_PIXEL;
    c->horizontal_string.width = c->width - c->vertical_select.width - GUI_CALENDAR_FRAME_LINE_PIXEL * 3;
    if (c->vertical_select.width == 0)
    {
        c->horizontal_string.x = c->horizontal_string.x - GUI_CALENDAR_FRAME_LINE_PIXEL;
        c->horizontal_string.width = c->horizontal_string.width + GUI_CALENDAR_FRAME_LINE_PIXEL;
    }
    c->horizontal_string.y = c->vertical_select.y;
    c->horizontal_string.height = GUI_CALENDAR_HORIZONTAL_STRING_HEIGHT;
    
    /* Set the calendar cell array layout. */
    c->cell_array.x = c->horizontal_string.x;
    c->cell_array.y = c->horizontal_string.y + c->horizontal_string.height + GUI_CALENDAR_FRAME_LINE_PIXEL;
    c->cell_array.width = c->horizontal_string.width;
    c->cell_array.height = c->vertical_select.height - c->horizontal_string.height - GUI_CALENDAR_FRAME_LINE_PIXEL;
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    }
#endif

    /* Adjust the layout of vertical select, horizontal string and cell array */
    gui_calendar_adjust_layout(c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_malloc_cell_data_buffer
 * DESCRIPTION
 *  Malloc the memory buffer for cell data.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_malloc_cell_data_buffer(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->cell_array.cells != NULL)
    {
        mmi_frm_scrmem_free((PU8)c->cell_array.cells);
    }
    c->cell_array.cells = 
        (gui_calendar_cell_struct *)mmi_frm_scrmem_alloc(sizeof(gui_calendar_cell_struct) * c->row * c->column);
	// Follow memset is for test //
    if(c->cell_array.cells != NULL)
    {
        memset(c->cell_array.cells, 0, sizeof(gui_calendar_cell_struct) * c->row * c->column);
    }
    // Above memset is for test //

}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_query_cell_data
 * DESCRIPTION
 *  Query the data of cell array.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_query_cell_data(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    applib_time_struct begin, end, inc, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    gui_calendar_construct_cell_date(c);

    if (c->cell_data_query_handler != NULL)
    {
        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
            c->cell_data_query_handler(
                c->type,
                c->start_time,
                c->end_time,
                c->time_interval,
                c->row * c->column,
                (c->cell_array).cells);
        }
        else if (c->type == GUI_CALENDAR_TYPE_WEEK)
        {
            memset(&begin, 0, sizeof(applib_time_struct));
            memset(&end, 0, sizeof(applib_time_struct));
            memset(&inc, 0, sizeof(applib_time_struct));
            begin = c->start_time;
            end = c->start_time;
            end.nHour = c->end_time.nHour;
            inc.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL;
            /* Because the week data is in 2 hour period, so query it by a loop. */
            for (i = 0; i < c->column; i++)
            {
                c->cell_data_query_handler(
                    c->type,
                    begin,
                    end,
                    c->time_interval,
                    c->row,
                    (c->cell_array).cells + i * c->row);

                /* Adjust the begin and end time. */
                applib_dt_increase_time(
                    (applib_time_struct*)&(begin),
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&result);
                result.nHour = c->start_time.nHour;
                begin = result;
                applib_dt_increase_time(
                    (applib_time_struct*)&(end),
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&result);
                result.nHour = c->end_time.nHour;
                end = result;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_theme
 * DESCRIPTION
 *  Set the theme to calendar component.
 * PARAMETERS
 *  c           [IN]    Is the calendar pointer.
 *  t           [IN]    Is the theme pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_theme(gui_calendar_struct *c, UI_calendar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    /* Set title theme. */
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_TRUE)
    {
        c->title.text_color = t->title_text_for_idle;
        c->title.text_font = t->title_for_idle_font;
        /* At present, we not have title background for idle calendar */
        c->title.bg_color = t->title_bg_for_idle;
        c->title.bg_alpha = t->title_bg_for_idle_alpha;
    }
    else
    {
#endif
    c->title.text_color = t->title_text;
    c->title.text_font = t->title_font;
    c->title.bg_color = t->title_bg;
    c->title.bg_alpha = t->title_bg_alpha;
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif

    /* Set vertical select theme. */
    c->vertical_select.bg_color = t->vertical_select_bg;
    c->vertical_select.bg_alpha = t->vertical_select_bg_alpha;
    c->vertical_select.text_font = t->vertical_select_font;
    c->vertical_select.text_color = t->vertical_select_text;

    /* Set horizontal string theme. */
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_TRUE)
    {
        c->horizontal_string.bg_color = t->horizontal_string_bg_for_idle;
        c->horizontal_string.bg_alpha = t->horizontal_string_bg_for_idle_alpha;
        c->horizontal_string.text_font = t->horizontal_string_for_idle_font;
        c->horizontal_string.text_color = t->horizontal_string_text_for_idle;
    }
    else
    {
#endif
    c->horizontal_string.bg_color = t->horizontal_string_bg;
    c->horizontal_string.bg_alpha = t->horizontal_string_bg_alpha;
    c->horizontal_string.text_font = t->horizontal_string_font;
    c->horizontal_string.text_color = t->horizontal_string_text;
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif

    /* Set cell array theme. */
    for (i = 0; i < GUI_CALENDAR_COLOR_TOTAL; i ++)
    {
        c->cell_array.cell_bg[i] = t->cell_bg[i];
    }
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_TRUE)
    {
        c->cell_array.bg_color = t->cell_array_bg_for_idle;
        c->cell_array.bg_alpha = t->cell_array_bg_for_idle_alpha;
        c->cell_array.cell_valid_text = t->cell_valid_text_for_idle;
        c->cell_array.cell_invalid_text = t->cell_invalid_text_for_idle;
        c->cell_array.cell_highlight = t->cell_highlight_for_idle;
        c->cell_array.cell_current_text = t->cell_current_text_for_idle;
        c->cell_array.cell_font = t->cell_for_idle_font;
        c->cell_array.current_bg_filler = t->current_bg_for_idle_filler;
        c->cell_array.cell_line = t->cell_line_for_idle;
        c->cell_array.cell_line_alpha = t->cell_line_for_idle_alpha;
        c->cell_array.cell_current_bg_alpha = t->cell_current_bg_for_idle_alpha;
        c->cell_array.cell_highlight_alpha = t->cell_highlight_for_idle_alpha;
        c->cell_array.current_font = t->cell_for_idle_font;
    }
    else
    {
#endif
    c->cell_array.bg_color = t->cell_array_bg;
    c->cell_array.bg_alpha = t->cell_array_bg_alpha;
    c->cell_array.cell_valid_text = t->cell_valid_text;
    c->cell_array.cell_invalid_text = t->cell_invalid_text;
    c->cell_array.cell_highlight = t->cell_highlight;
    c->cell_array.cell_current_text = t->cell_current_text;
    c->cell_array.cell_font = t->cell_font;
    c->cell_array.current_bg_filler = t->current_bg_filler;
    c->cell_array.cell_line = t->cell_line;
    c->cell_array.cell_line_alpha = t->frame_line_alpha;
    c->cell_array.cell_current_bg_alpha = 100;
    c->cell_array.cell_highlight_alpha = 100;
    c->cell_array.current_font = t->current_font;
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif

    /* Set the dateil theme. */
    c->detail.bg_color = t->popup_bg;
    c->detail.border_color = t->popup_border;
    c->detail.text_color = t->popup_text;
    c->detail.text_font = gui_font_get_type(GUI_FONT_SIZE_CALENDAR_POPUP);
    /* Set the calendar theme. */
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_TRUE)
    {
        c->frame_line = t->frame_line_for_idle;
        c->frame_line_alpha = t->frame_line_for_idle_alpha;
        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
            c->bg_image = t->bg_image_for_idle;
        }
        else
        {
            c->bg_image = NULL;
        }
    }
    else
    {
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    c->frame_line = t->frame_line;
    c->frame_line_alpha = t->frame_line_alpha;
    c->bg_image = NULL;
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_general_switch_update
 * DESCRIPTION
 *  When need general switch, do same update.
 * PARAMETERS
 *  c               [IN]    
 *  highlight_time  [IN]
 *  nHour           [IN]
 *  style           [IN]
 * REMARK:
 *  c->highlight_change_callback in this API has two function:
 *  1. If it not outside the date boundary, it will ask category and App to
 *     adjust the highlight time
 *  2. If it out of date boundary, it need App popup information
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_general_switch_update(gui_calendar_struct* c, 
												applib_time_struct *highlight_time, 
												U8 nHour, 
												gui_calendar_switch_update_enum style)
{
	if(style == GUI_CALENDAR_HIGHLIGHT_UPDATE)
	{
		gui_calendar_unhighlight_cell(c);
	}
	if(highlight_time != NULL)
	{
		//c->highlight_time = highlight_time;
#ifdef __MMI_MAINLCD_96X64__
        applib_time_struct inc;
        applib_time_struct end_time;
        memset(&inc, 0, sizeof(applib_time_struct));
        inc.nDay = DT_DAYS_OF_WEEK * GUI_CALENDAR_CELL_ROW - 1;
        applib_dt_increase_time(&c->start_time, &inc, &end_time);
        if(applib_dt_compare_time(highlight_time, &c->start_time, NULL) == DT_TIME_LESS)
        {
		    style = GUI_CALENDAR_DETAIL_SHOW_UPDATE;
        }
        else if(applib_dt_compare_time(highlight_time, &end_time, NULL) == DT_TIME_GREATER)
        {
            style = GUI_CALENDAR_DETAIL_SHOW_UPDATE;
        }
#endif
		memcpy(&c->highlight_time, highlight_time,sizeof(applib_time_struct));
	}
	if(nHour != 0xFF)
	{
		c->highlight_time.nHour = nHour;
	}
	{
		/* Let category and App adjust the highlight time */
		gdi_layer_lock_frame_buffer();
		if (c->highlight_change_callback != NULL)
		{
			c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
		}
		gdi_layer_unlock_frame_buffer();
	}
	if(style == GUI_CALENDAR_HIGHLIGHT_UPDATE)
	{
		gui_calendar_highlight_cell(c);	
	}
	else
	{
		if(style == GUI_CALENDAR_DETAIL_SHOW_UPDATE || style == GUI_CALENDAR_SHOW_UPDATE)
		{
			if (c->detail.detail_is_shown == MMI_TRUE)
			{
#ifdef __MMI_MAINLCD_96X64__
				gui_scrolling_text_stop(&c->detail.scrolling_detail);
				if(c->detail.text != NULL)
				{
					mmi_frm_scrmem_free(c->detail.text);
					c->detail.text = NULL;
				}
#endif
				c->detail.detail_is_shown = MMI_FALSE;
			}
			gui_calendar_show(c);
		}
		else if(style == GUI_CALENDAR_SHOW_UPDATE)
		{
			gui_calendar_show(c);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_general_switch_handler
 * DESCRIPTION
 *  Handle the direction switch event when key or pen be pressed.
 * PARAMETERS
 *  direction   [IN]    Is the key's direction.
 * REMARK:
 *  c->highlight_change_callback in this API has two function:
 *  1. If it not outside the date boundary, it will ask category and App to
 *     adjust the highlight time
 *  2. If it out of date boundary, it need App popup information
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_general_switch_handler(gui_calendar_key_direction_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct temp;
    applib_time_struct inc, result, diff;
    applib_time_struct min_time, max_time;
    S32 time_compare;
    U32 temp_row, temp_column;
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;
    MMI_DBG_ASSERT(c != NULL);

    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    memset(&diff, 0, sizeof(applib_time_struct));
    memset(&min_time, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));

    gui_calendar_calculate_highlight_position(c, &temp_row, &temp_column);
    switch (direction)
    {
        case GUI_CALENDAR_DIRECTION_UP:
            {
                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    /* Calculate the real min display time. */
                    gui_calendar_adjust_date_boundary(
                        c,
                        &min_time,
                        &temp,
                        c->min_time);

                    inc.nDay = DT_DAYS_OF_WEEK;
                    applib_dt_decrease_time(
                        &c->highlight_time,
                        &inc,
                        &result);
                    /* If it switch to the date of prev month. */
                    if (result.nMonth < c->highlight_time.nMonth ||
                        result.nYear < c->highlight_time.nYear)
                    {
                        temp = result;
                        temp.nDay = 1;
                        time_compare = applib_dt_compare_time(
                                           &min_time,
                                           &temp,
                                           &diff);

                        /* If the time is greater than min_time, switch to prev month. */
                        if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
                        {
                            gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
                            gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_DETAIL_SHOW_UPDATE);
                        }
                        else
                        {
                            {
                                /* Out of date boundary, need App to popup information */
                                if (c->highlight_change_callback != NULL)
                                {
                                    c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                                }
                            }
                            return;
                        }
                    }
                    else
                    {
                        gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                    }
                }
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
                    if (c->highlight_time.nHour > c->start_time.nHour)
                    {
                        gui_calendar_general_switch_update(c, NULL, c->highlight_time.nHour - GUI_CALENDAR_WEEK_TIME_INTERVAL, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                    }
                    else
                    {
                        /* If still can move up. */
                        if (c->start_time.nHour > c->min_time.nHour)
                        {
                            c->start_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL;
                            c->end_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL;
                            gui_calendar_general_switch_update(c, NULL, c->highlight_time.nHour - GUI_CALENDAR_WEEK_TIME_INTERVAL, GUI_CALENDAR_SHOW_UPDATE);
                        }
                        else
                        {
                            /* Not need popup information. */
                            return;
                        }
                    }
                }
            }
            break;

        case GUI_CALENDAR_DIRECTION_DOWN:
            {
                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    /* Calculate the real max display time. */
                    gui_calendar_adjust_date_boundary(
                        c,
                        &temp,
                        &max_time,
                        c->max_time);

                    inc.nDay = DT_DAYS_OF_WEEK;
                    applib_dt_increase_time(
                        &c->highlight_time,
                        &inc,
                        &result);

                    /* If it switch to the date of next month. */
                    if (result.nMonth > c->highlight_time.nMonth ||
                        result.nYear > c->highlight_time.nYear)
                    {
                        temp = result;
                        temp.nDay = applib_dt_last_day_of_mon(temp.nMonth, temp.nYear);
                        time_compare = applib_dt_compare_time(
                                           &max_time,
                                           &temp,
                                           &diff);

                        /* If the time is smaller than max_time, switch to next month. */
                        if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
                        {
                            gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
                            gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_SHOW_UPDATE);
                        }
                        else
                        {
                            {
                                /* Out of date boundary, need App to popup information */
                                if (c->highlight_change_callback != NULL)
                                {
                                    c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                                }
                            }
                            return;
                        }
                    }
                    else
                    {
                        gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                    }
                }
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
					/* Remark: highlight time record one period of time, not a point of time.So we need to add
					 * GUI_CALENDAR_WEEK_TIME_INTERVAL to highlight hour before we compare it with end_time.
					 */
                    if ((c->highlight_time.nHour + GUI_CALENDAR_WEEK_TIME_INTERVAL) < c->end_time.nHour)
                    {
                        gui_calendar_general_switch_update(c, NULL, c->highlight_time.nHour + GUI_CALENDAR_WEEK_TIME_INTERVAL, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                    }
                    else
                    {
                        /* If still can move down. */
                        if (c->end_time.nHour < c->max_time.nHour)
                        {
                            c->start_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL;
                            c->end_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL;
							gui_calendar_general_switch_update(c, NULL, c->highlight_time.nHour + GUI_CALENDAR_WEEK_TIME_INTERVAL, GUI_CALENDAR_SHOW_UPDATE);
                        }
                        else
                        {
                            /* Not need to popup information. */
                            return;
                        }
                    }
                }
            }
            break;

        case GUI_CALENDAR_DIRECTION_LEFT:
            {
                /* Calculate the real min display time. */
                gui_calendar_adjust_date_boundary(
                    c,
                    &min_time,
                    &temp,
                    c->min_time);

                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    inc.nDay = 1;
                    applib_dt_decrease_time(
                        &c->highlight_time,
                        &inc,
                        &result);

                    /* If it switch to the date of prev month. */
                    if (result.nMonth < c->highlight_time.nMonth ||
                        result.nYear < c->highlight_time.nYear)
                    {
                        temp = result;
                        temp.nDay = 1;
                        time_compare = applib_dt_compare_time(
                                           &min_time,
                                           &temp,
                                           &diff);

                        /* If the time is greater than min_time, switch to prev month. */
                        if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
                        {
                            gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
							gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_DETAIL_SHOW_UPDATE);
                        }
                        else
                        {
                            {
                                /* Out of date boundary, need App to popup information */
                                if (c->highlight_change_callback != NULL)
                                {
                                    c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                                }
                            }
                            return;
                        }
                    }
                    else
                    {
						gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                    }
                }
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
                    inc.nDay = 1;
                    applib_dt_decrease_time(
                        &c->highlight_time,
                        &inc,
                        &result);
                    result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);

                    time_compare = applib_dt_compare_time(
                                       &c->start_time,
                                       &result,
                                       &diff);
                    if (time_compare == DT_TIME_GREATER)
                    {
                        time_compare = applib_dt_compare_time(
                                           &c->max_time,
                                           &c->end_time,
                                           &diff);
                        if ((c->highlight_time.nHour > c->start_time.nHour) && (time_compare != DT_TIME_LESS))
						{
							gui_calendar_general_switch_update(c, &c->end_time, c->highlight_time.nHour - GUI_CALENDAR_WEEK_TIME_INTERVAL, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                        }
                        else
                        {
                            inc.nDay = DT_DAYS_OF_WEEK;
                            applib_dt_decrease_time(
                                &c->highlight_time,
                                &inc,
                                &result);
                            temp = result;
                            time_compare = applib_dt_compare_time(
                                               &min_time,
                                               &temp,
                                               &diff);
                            /* If the time is greater than min_time, switch to prev week. */
                            if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
                            {
                                applib_dt_decrease_time(
                                    &c->start_time,
                                    &inc,
                                    &result);
							    result.nHour = c->start_time.nHour;
								result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);
                                c->start_time = result;
							    inc.nDay = c->column - 1;
                                applib_dt_increase_time(
                                    &c->start_time,
                                    &inc,
                                    &result);
							    result.nHour = c->end_time.nHour;
								result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);
                                c->end_time = result;
                                result = c->end_time;
								result.nHour = c->highlight_time.nHour;
								gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_SHOW_UPDATE);
                            }
                            else
                            {
                                {
                                    /* Out of date boundary, need App to popup information */
                                    if (c->highlight_change_callback != NULL)
                                    {
                                        c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                                    }
                                }
                                return;
                            }
						}
                    }
                    else
                    {
                        time_compare = applib_dt_compare_time(
                                           &c->min_time,
                                           &result,
                                           &diff);
                        if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
                        {
							gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                        }
                        else
                        {
                            {
                                /* Out of date boundary, need App to popup information */
                                if (c->highlight_change_callback != NULL)
                                {
                                    c->highlight_change_callback(c->type, result, c->start_time, c->end_time);
                                }
                            }
                            return;
                        }
                    }
                }
            }
            break;

        case GUI_CALENDAR_DIRECTION_RIGHT:
            {
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
                    max_time.nHour = DT_HRS_PRE_DAY;
                }
                /* Calculate the real max display time. */
                gui_calendar_adjust_date_boundary(
                    c,
                    &temp,
                    &max_time,
                    c->max_time);

                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    inc.nDay = 1;
                    applib_dt_increase_time(
                        &c->highlight_time,
                        &inc,
                        &result);

                    /* If it switch to the date of next month. */
                    if (result.nMonth > c->highlight_time.nMonth ||
                        result.nYear > c->highlight_time.nYear)
                    {
                        temp = result;
                        temp.nDay = applib_dt_last_day_of_mon(temp.nMonth, temp.nYear);
                        time_compare = applib_dt_compare_time(
                                           &max_time,
                                           &temp,
                                           &diff);

                        /* If the time is smaller than max_time, switch to next month. */
                        if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
                        {
                            gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
							gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_DETAIL_SHOW_UPDATE);
                        }
                        else
                        {
                            {
                                /* Out of date boundary, need App to popup information */
                                if (c->highlight_change_callback != NULL)
                                {
                                    c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                                }
                            }
                            return;
                        }
                    }
                    else
                    {
						gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                    }
                }
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
                    inc.nDay = 1;
                    applib_dt_increase_time(
                        &c->highlight_time,
                        &inc,
                        &result);
                    result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);

                    time_compare = applib_dt_compare_time(
                                       &c->end_time,
                                       &result,
                                       &diff);
                    if (time_compare == DT_TIME_LESS)
                    {
                        time_compare = applib_dt_compare_time(
                                           &c->min_time,
                                           &c->start_time,
                                           &diff);
                        if ((c->highlight_time.nHour < (c->end_time.nHour - GUI_CALENDAR_WEEK_TIME_INTERVAL)) &&
		            (time_compare != DT_TIME_GREATER))
                        {
							S32 temp = c->highlight_time.nHour + GUI_CALENDAR_WEEK_TIME_INTERVAL;
							gui_calendar_general_switch_update(c, &c->start_time, temp, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                        }
                        else
                        {
                            inc.nDay = DT_DAYS_OF_WEEK;
                            applib_dt_increase_time(
                                &c->highlight_time,
                                &inc,
                                &result);
                            temp = result;
                            time_compare = applib_dt_compare_time(
                                               &max_time,
                                               &temp,
                                               &diff);
                            /* If the time is smaller than max_time, go to next week. */
                            if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
                            {
                                applib_dt_increase_time(
                                    &c->start_time,
                                    &inc,
                                    &result);
                                result.nHour = c->start_time.nHour;
						        result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);
                                c->start_time = result;
						        inc.nDay = c->column - 1;
                                applib_dt_increase_time(
                                    &c->start_time,
                                    &inc,
                                    &result);
                                result.nHour = c->end_time.nHour;
							    result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);
                                c->end_time = result;
							    result = c->start_time;
							    result.nHour = c->highlight_time.nHour;
								gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_DETAIL_SHOW_UPDATE);
                            }
                            else
                            {
                                {
                                    /* Out of date boundary, need App to popup information */
                                    if (c->highlight_change_callback != NULL)
                                    {
                                        c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                                    }
                                }
                                return;
                            }
                        }
                    }
					else
                    {
                        time_compare = applib_dt_compare_time(
                                           &c->max_time,
                                           &result,
                                           &diff);
                        if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
                        {
							gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_HIGHLIGHT_UPDATE);
                        }
                        else
                        {
                            {
                                /* Out of date boundary, need App to popup information */
                                if (c->highlight_change_callback != NULL)
                                {
                                    c->highlight_change_callback(c->type, result, c->start_time, c->end_time);
                                }
                            }
                            return;
                        }
                    }
                }
            }
            break;

        case GUI_CALENDAR_DIRECTION_PAGE_UP:
            {
                /* Calculate the real min display time. */
                gui_calendar_adjust_date_boundary(
                    c,
                    &min_time,
                    &temp,
                    c->min_time);

                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    inc.nMonth = 1;
                    temp = c->highlight_time;
                    temp.nDay = 1;
                    applib_dt_decrease_time(&temp, &inc, &result);

                    time_compare = applib_dt_compare_time(
                                       &min_time,
                                       &result,
                                       &diff);

                    /* If the time is greater than min_time, go to prev month. */
                    if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
                    {
                        //c->highlight_time = result;
                        gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
                    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                        if (c->is_on_idle == MMI_TRUE)
                        {
                            return;
                        }
                    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
						gui_calendar_general_switch_update(c, &result, 0xFF, GUI_CALENDAR_DETAIL_SHOW_UPDATE);
                    }
                    else
					{
                        {
                            /* Out of date boundary, need App to popup information */
                            if (c->highlight_change_callback != NULL)
                            {
                                c->highlight_change_callback(c->type, result, c->start_time, c->end_time);
                            }
                        }
                        return;
                    }
                }
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
                    inc.nDay = DT_DAYS_OF_WEEK;
                    temp = c->highlight_time;
                    applib_dt_decrease_time(
                        &temp,
                        &inc,
                        &result);
		    temp = result;
                    
                    time_compare = applib_dt_compare_time(
                                       &min_time,
                                       &temp,
                                       &diff);
                    /* If the time is greater than min_time, go to prev week. */
                    if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
                    {
                        applib_dt_decrease_time(
                            &c->start_time,
                            &inc,
                            &result);
                        result.nHour = c->start_time.nHour;
                        c->start_time = result;
						applib_dt_decrease_time(
                            &c->highlight_time,
                            &inc,
                            &result);
                        c->highlight_time = result;
						inc.nDay = c->column - 1;
                        applib_dt_increase_time(
                            &c->start_time,
                            &inc,
                            &result);
                        result.nHour = c->end_time.nHour;
                        c->end_time = result;
                        /* Adjust the highlight time if it is the last week of one year */
                        time_compare = applib_dt_compare_time(
                                           &c->min_time,
                                           &c->highlight_time,
                                           &diff);
                        if (time_compare == DT_TIME_GREATER)
                        {
                            c->highlight_time.nYear = c->min_time.nYear;
                            c->highlight_time.nMonth = c->min_time.nMonth;
                            c->highlight_time.nDay = c->min_time.nDay;
                            c->highlight_time.DayIndex = c->min_time.DayIndex;
                        }

						gui_calendar_general_switch_update(c, NULL, 0xFF, GUI_CALENDAR_SHOW_UPDATE);
                    }
                    else
                    {
                        {
                            /* Out of date boundary, need App to popup information */
                            if (c->highlight_change_callback != NULL)
                            {
                                c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                            }
                        }
                        return;
                    }
                }
            }
            break;

        case GUI_CALENDAR_DIRECTION_PAGE_DOWN:
            {
                /* Calculate the real max display time. */
                gui_calendar_adjust_date_boundary(
                    c,
                    &temp,
                    &max_time,
                    c->max_time);

                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    inc.nMonth = 1;
                    temp = c->highlight_time;
                    temp.nDay = 1;
                    applib_dt_increase_time(&temp, &inc, &result);

                    temp = result;
                    temp.nDay = applib_dt_last_day_of_mon(temp.nMonth, temp.nYear);
                    time_compare = applib_dt_compare_time(
                                       &max_time,
                                       &temp,
                                       &diff);

                    /* If the time is smaller than max_time, go to next month. */
                    if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
                    {                        
                        c->highlight_time = result;
                        gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
                    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                        if (c->is_on_idle == MMI_TRUE)
                        {
                            return;
                        }
                    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
						gui_calendar_general_switch_update(c, NULL, 0xFF, GUI_CALENDAR_DETAIL_SHOW_UPDATE);
                    }
                    else
                    {
                        {
                            /* Out of date boundary, need App to popup information */
                            if (c->highlight_change_callback != NULL)
                            {
                                c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                            }
                        }
                        return;
                    }
                }
                if (c->type == GUI_CALENDAR_TYPE_WEEK)
                {
                    inc.nDay = DT_DAYS_OF_WEEK;
		    temp = c->highlight_time;
                    applib_dt_increase_time(
                        &temp,
                        &inc,
                        &result);
		    temp = result;
                    
                    time_compare = applib_dt_compare_time(
                                       &max_time,
                                       &temp,
                                       &diff);
                    /* If the time is smaller than max_time, go to next week. */
                    if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
                    {
                        applib_dt_increase_time(
                            &c->start_time,
                            &inc,
                            &result);
                        result.nHour = c->start_time.nHour;
                        c->start_time = result;
						applib_dt_increase_time(
                            &c->highlight_time,
                            &inc,
                            &result);
                        c->highlight_time = result;
						inc.nDay = c->column - 1;
                        applib_dt_increase_time(
                            &c->start_time,
                            &inc,
                            &result);
                        result.nHour = c->end_time.nHour;
                        c->end_time = result;
                        /* Adjust the highlight time if it is the last week of one year */
                        time_compare = applib_dt_compare_time(
                                           &c->max_time,
                                           &c->highlight_time,
                                           &diff);
                        if (time_compare == DT_TIME_LESS)
                        {
                            c->highlight_time.nYear = c->max_time.nYear;
                            c->highlight_time.nMonth = c->max_time.nMonth;
                            c->highlight_time.nDay = c->max_time.nDay;
                            c->highlight_time.DayIndex = c->max_time.DayIndex;
                        }

						gui_calendar_general_switch_update(c, NULL, 0xFF, GUI_CALENDAR_SHOW_UPDATE);
                    }
                    else
                    {
                        {
                            /* Out of date boundary, need App to popup information */
                            if (c->highlight_change_callback != NULL)
                            {
                                c->highlight_change_callback(c->type, temp, c->start_time, c->end_time);
                            }
                        }
                        return;
                    }
                }
            }
            break;

        default:
            MMI_DBG_ASSERT(0);
            break;
    }
    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_left_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_left_arrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_LEFT);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_right_arrow_key_handler
 * DESCRIPTION
 *  Handle the right arrow key event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_right_arrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_RIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_up_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_up_arrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_UP);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_down_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_down_arrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  static void gui_calendar_side_up_key_handler(void)
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_side_up_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_UP);
}


/*****************************************************************************
 * FUNCTION
 *  static void gui_calendar_side_down_key_handler(void)
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_side_down_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_key_handler
 * DESCRIPTION
 *  Set the key handler of calendar. Calendar will control left/right/up/down
 *  arrow to move the highlight of cell.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_key_handler(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    SetKeyHandler(gui_calendar_left_arrow_key_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_left_arrow_key_handler, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_calendar_left_arrow_key_handler, KEY_LEFT_ARROW, KEY_LONG_PRESS);

    SetKeyHandler(gui_calendar_right_arrow_key_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_right_arrow_key_handler, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_calendar_right_arrow_key_handler, KEY_RIGHT_ARROW, KEY_LONG_PRESS);

    SetKeyHandler(gui_calendar_up_arrow_key_handler, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_up_arrow_key_handler, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_calendar_up_arrow_key_handler, KEY_UP_ARROW, KEY_LONG_PRESS);

    SetKeyHandler(gui_calendar_down_arrow_key_handler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_down_arrow_key_handler, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_calendar_down_arrow_key_handler, KEY_DOWN_ARROW, KEY_LONG_PRESS);

    SetKeyHandler(gui_calendar_side_up_key_handler, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_side_up_key_handler, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_calendar_side_up_key_handler, KEY_VOL_UP, KEY_LONG_PRESS);

    SetKeyHandler(gui_calendar_side_down_key_handler, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(gui_calendar_side_down_key_handler, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_calendar_side_down_key_handler, KEY_VOL_DOWN, KEY_LONG_PRESS);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_clear_key_handler
 * DESCRIPTION
 *  Clear the key handler of calendar.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_clear_key_handler(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_UP_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_LONG_PRESS);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_bg_frame
 * DESCRIPTION
 *  Redraw the background frame of calendar.
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_bg_frame(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    gdi_handle abm_src_layer = GDI_NULL_HANDLE;

    S32 left_top_x = 0, left_top_y = 0, right_bottom_x = 0, right_bottom_y = 0;
    S32 calendar_left_top_x = 0, calendar_left_top_y = 0;
    S32 calendar_right_bottom_x = 0, calendar_right_bottom_y = 0;
    color border_color, bg_color;
    U32 i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&x, &y);
    x = c->x - x;
    y = c->y - y;
    if (c->abm_layer != NULL)
    {
        abm_src_layer = c->abm_layer;
        gui_set_transparent_source_layer(abm_src_layer);
    }
    else
    {
        gdi_layer_get_active(&abm_src_layer);
    }

	gdi_layer_push_clip();
    gdi_layer_set_clip(
        x,
        y,
        x + c->width - 1,
        y + c->height - 1);
    /* Draw the border frame of calendar. */
    border_color = c->frame_line;
    border_color.alpha = c->frame_line_alpha;// * 255 / 100;
    /* Draw top border line. */
    gui_fill_transparent_color(
        x,
        y,
        x + c->width - 1,
        y + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
        border_color);
    /* Draw bottom border line. */
    gui_fill_transparent_color( 
        x,
        y + c->height - 1,
        x + c->width - 1,
        y + c->height - GUI_CALENDAR_FRAME_LINE_PIXEL,
        border_color);
    /* Draw left border line. */
    gui_fill_transparent_color( 
        x,
        y + GUI_CALENDAR_FRAME_LINE_PIXEL,
        x + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
        y + c->height - GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
        border_color);
    /* Draw right border line. */
    gui_fill_transparent_color( 
        x + c->width - GUI_CALENDAR_FRAME_LINE_PIXEL,
        y + GUI_CALENDAR_FRAME_LINE_PIXEL,
        x + c->width - 1,
        y + c->height - GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
        border_color);
    gdi_layer_pop_clip();

    /* Since every calendar will have horizontal string and cell array, we will
     * use this to draw the frame of calendar.
     */
    /* Calculate the left_top and right_bottom coordinate of horizontal string and cell array */
    left_top_x = x + c->horizontal_string.x;
    left_top_y = y + c->horizontal_string.y;
    right_bottom_x = x + c->cell_array.x + c->cell_array.width - 1;
    right_bottom_y = y + c->cell_array.y + c->cell_array.height - 1;
    /* Calculate the left_top and right_bottom coordinate of calendar */
    calendar_left_top_x = x + GUI_CALENDAR_FRAME_LINE_PIXEL;
    calendar_left_top_y = y + GUI_CALENDAR_FRAME_LINE_PIXEL;
    calendar_right_bottom_x = x + c->width - 1 - GUI_CALENDAR_FRAME_LINE_PIXEL;
    calendar_right_bottom_y = y + c->height - 1 - GUI_CALENDAR_FRAME_LINE_PIXEL;

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        calendar_left_top_x,
        calendar_left_top_y,
        calendar_right_bottom_x,
        calendar_right_bottom_y);

    /* There is gap between horizontal string and calendar up frame. */
    if (left_top_y > calendar_left_top_y)
    {

        /* First draw the up frame line of horizontal string. */
        gui_fill_transparent_color( 
            left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL,
            left_top_y - GUI_CALENDAR_FRAME_LINE_PIXEL,
            right_bottom_x + GUI_CALENDAR_FRAME_LINE_PIXEL,
            left_top_y - 1,
            border_color);

        if ((left_top_y - calendar_left_top_y) > GUI_CALENDAR_FRAME_LINE_PIXEL)
        {
            if (c->title.height > 0)
            {
                bg_color = c->title.bg_color;
                bg_color.alpha = c->title.bg_alpha;// * 255 / 100;
                if (c->vertical_select.width > 0)
                {
                    border_color = c->frame_line;
                    border_color.alpha = c->frame_line_alpha;// * 255 / 100;
                }
                else
                {
                    border_color = c->vertical_select.bg_color;
                    border_color.alpha = c->vertical_select.bg_alpha;// * 255 / 100;
                }
            }
            else
            {
                bg_color = c->vertical_select.bg_color;
                bg_color.alpha = c->vertical_select.bg_alpha;// * 255 / 100;
                border_color = c->vertical_select.bg_color;
                border_color.alpha = c->vertical_select.bg_alpha;// * 255 / 100;
            }

            /* Draw the area above horizontal string */
            gui_fill_transparent_color( 
                calendar_left_top_x,
                calendar_left_top_y,
                calendar_right_bottom_x,
                left_top_y - GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
                bg_color);
            /* Draw the left up line */
            if ((left_top_x - calendar_left_top_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
            {
                gui_fill_transparent_color(
                    calendar_left_top_x,
                    left_top_y - GUI_CALENDAR_FRAME_LINE_PIXEL,
                    left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
                    left_top_y - 1,
                    border_color);
            }
            /* Draw the right up line */
            if ((calendar_right_bottom_x - right_bottom_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
            {
                gui_fill_transparent_color(
                    right_bottom_x + GUI_CALENDAR_FRAME_LINE_PIXEL + 1,
                    left_top_y - GUI_CALENDAR_FRAME_LINE_PIXEL,
                    calendar_right_bottom_x,
                    left_top_y - 1,
                    border_color);
            }
        }

    }
    else if (left_top_y == calendar_left_top_y)
    {
    #ifdef __MMI_FTE_SUPPORT__
        if ((c->horizontal_string.height > 0)
        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            && (c->is_on_idle == MMI_FALSE)
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
            )
        {
            gdi_image_draw_resized_id(
                calendar_left_top_x,
                calendar_left_top_y,
                calendar_right_bottom_x - calendar_left_top_x + 1,
                c->horizontal_string.height,
                IMG_CALENDAR_HORIZONTAL_STRING_BG);
        }
    #endif /* __MMI_FTE_SUPPORT__ */
    }
    

    /* There is gap between horizontal string and calendar left frame */
    if (left_top_x > calendar_left_top_x)
    {
        border_color = c->frame_line;
        border_color.alpha = c->frame_line_alpha;// * 255 / 100;
        /* First draw the left frame line of horizontal string and cell array. */
    #ifndef __MMI_FTE_SUPPORT__
        gui_fill_transparent_color( 
            (left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL),
            left_top_y,
            (left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL) + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
            right_bottom_y,
            border_color);
    #else
		gui_fill_transparent_color( 
            (left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL),
            y + c->cell_array.y,
            (left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL) + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
            right_bottom_y,
            border_color);
    #endif

        if ((left_top_x - calendar_left_top_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
        {
            bg_color = c->vertical_select.bg_color;
            bg_color.alpha = c->vertical_select.bg_alpha;// * 255 / 100;

        /* Fill the area of vertical select */
        #ifndef __MMI_FTE_SUPPORT__            
            gui_fill_transparent_color( 
                calendar_left_top_x,
                left_top_y,
                left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
                right_bottom_y,
                bg_color);
        #else
            gui_fill_transparent_color( 
                calendar_left_top_x,
                y + c->cell_array.y,
                left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
                right_bottom_y,
                bg_color);
        #endif
		}
    }

    /* There is gap between horizontal string and calendar right frame */
    if (right_bottom_x < calendar_right_bottom_x)
    {
        border_color = c->frame_line;
        border_color.alpha = c->frame_line_alpha;// * 255 / 100;
        /* First draw the right frame line of horizontal string and cell array. */
        gui_fill_transparent_color(
            right_bottom_x,
            left_top_y,
            right_bottom_x + c->frame_line_alpha - 1,
            right_bottom_y,
            border_color);

        if ((calendar_right_bottom_x - right_bottom_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
        {
            bg_color = c->vertical_select.bg_color;
            bg_color.alpha = c->vertical_select.bg_alpha;// * 255 / 100;

            /* Fill the area of vertical select */
            gui_fill_transparent_color( 
                right_bottom_x + GUI_CALENDAR_FRAME_LINE_PIXEL + 1,
                left_top_y,
                calendar_right_bottom_x,
                right_bottom_y,
                bg_color);
        }
    }

    /* There is gap between horizontal string and calendar bottom frame */
    if (right_bottom_y < calendar_right_bottom_y)
    {
        border_color = c->frame_line;
        border_color.alpha = c->frame_line_alpha;// * 255 / 100;
        /* First draw the right frame line of horizontal string and cell array. */
        gui_fill_transparent_color(
            left_top_x,
            right_bottom_y,
            right_bottom_x,
            right_bottom_y + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
            border_color);

        if ((calendar_right_bottom_x - right_bottom_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
        {
            bg_color = c->vertical_select.bg_color;
            bg_color.alpha = c->vertical_select.bg_alpha;// * 255 / 100;
            border_color = c->vertical_select.bg_color;
            border_color.alpha = c->vertical_select.bg_alpha ;//* 255 / 100;

            /* Fill the area of vertical select */
            gui_fill_transparent_color( 
                left_top_x,
                right_bottom_y + GUI_CALENDAR_FRAME_LINE_PIXEL,
                right_bottom_x,
                calendar_right_bottom_x,
                bg_color);

            /* Draw the left down line */
            if ((left_top_x - calendar_left_top_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
            {
                gui_fill_transparent_color( 
                    calendar_left_top_x,
                    right_bottom_y,
                    left_top_x - GUI_CALENDAR_FRAME_LINE_PIXEL,
                    right_bottom_y + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
                    border_color);
            }
            /* Draw the right down line */
            if ((calendar_right_bottom_x - right_bottom_x) > GUI_CALENDAR_FRAME_LINE_PIXEL)
            {
                gui_fill_transparent_color( 
                    right_bottom_x + GUI_CALENDAR_FRAME_LINE_PIXEL,
                    right_bottom_y,
                    calendar_right_bottom_x,
                    right_bottom_y + GUI_CALENDAR_FRAME_LINE_PIXEL - 1,
                    border_color);
            }
        }
    }

#ifdef __MMI_FTE_SUPPORT__
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_FALSE && c->vertical_select.width > 0)
    {
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
        S32 x1, y1;
        border_color = c->frame_line;
        border_color.alpha = c->frame_line_alpha;// * 255 / 100;
        for (i = 1; i < c->row; i++)
        {
            x1 = c->vertical_select.x;
            y1 = c->cell_array.y + i * (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) - 1;
            gui_fill_transparent_color(
                x1 + x,
                y1 + y,
                x1 + c->vertical_select.width - 1 + x,
                y1 + GUI_CALENDAR_FRAME_LINE_PIXEL - 1 + y,
                border_color);
        }
    }
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#endif /* __MMI_FTE_SUPPORT__ */

#ifndef __MMI_FTE_SUPPORT__
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_FALSE || c->title.height == 0)
    {
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    /* draw horizon string's background */
    bg_color = c->horizontal_string.bg_color;
    bg_color.alpha = c->horizontal_string.bg_alpha;// * 255 / 100;
    gui_fill_transparent_color(
        c->horizontal_string.x + x,
        c->horizontal_string.y + y,
        c->horizontal_string.x + c->horizontal_string.width - 1 + x,
        c->horizontal_string.y + c->horizontal_string.height - 1 + y,
        bg_color);
    
    /* draw the border between horizontal string and cell array */
    gui_fill_transparent_color(
        c->cell_array.x + x,
        c->cell_array.y - GUI_CALENDAR_FRAME_LINE_PIXEL + y,
        c->cell_array.x + c->cell_array.width - 1 + x,
        c->cell_array.y - 1 + y, /* (c->cell_array_y - GUI_CALENDAR_FRAME_LINE_PIXEL) + GUI_CALENDAR_FRAME_LINE_PIXEL -1 */
        border_color);
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#endif /* __MMI_FTE_SUPPORT__ */
    
    /* draw cell array's background and frame line */
    bg_color = c->cell_array.bg_color;
    bg_color.alpha = c->cell_array.bg_alpha;// * 255 / 100;
    border_color = c->cell_array.cell_line;
    border_color.alpha = c->frame_line_alpha;// * 255 / 100;

    for (i = 0; i < c->row; i++)
    {
        for (j = 0; j < c->column; j++)
        {
            S32 x1, y1;
            x1 = c->cell_array.x + j * (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL);
            y1 = c->cell_array.y + i * (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL);
            /* fill cell's background */
            gui_fill_transparent_color(
                x1 + x,
                y1 + y,
                x1 + c->cell_array.cell_width - 1 + x,
                y1 + c->cell_array.cell_height - 1 + y,
                bg_color); 
             
            /* draw column line of this line */
            if (j == (c->column - 1))
            {
                ;
            }
            else
            {
                gui_fill_transparent_color(
                    x1 + c->cell_array.cell_width + x,
                    y1,
                    x1 + c->cell_array.cell_width  + GUI_CALENDAR_FRAME_LINE_PIXEL - 1 + x,
                    y1 + c->cell_array.cell_height - 1 + y,
                    border_color); 
            }  
        }
         
        if (i == 0)
        {
            ;
        }
        else
        {
            gui_fill_transparent_color(
                c->cell_array.x + x,
                c->cell_array.y + i * (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) - GUI_CALENDAR_FRAME_LINE_PIXEL + y,
                c->cell_array.x + c->cell_array.width - 1 + x,
                c->cell_array.y + i * (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) - 1 + y,
                border_color); 
        }          
    }
    if (c->abm_layer != NULL)
        gui_reset_transparent_source_layer();
    gdi_layer_pop_clip();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_bg
 * DESCRIPTION
 *  Redraw the calendar background in a give area. The coordinate is absolute.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 *  x       [IN]    Is the clip x position.
 *  y       [IN]    Is the clip y position.
 *  width   [IN]    Is the clip width.
 *  height  [IN]    Is the clip height.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_bg(
             gui_calendar_struct* c,
             S32 x,
             S32 y,
             S32 width,
             S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gdi_layer_push_clip();

    if (c->abm_layer != NULL)
    {
        gdi_push_and_set_alpha_blending_source_layer(c->abm_layer);
    }

    gdi_layer_set_clip(
        x - layer_offset_x,
        y - layer_offset_y,
        x + width - 1 - layer_offset_x,
        y + height - 1 - layer_offset_y);

    if (c->bg_image != NULL)
    {
        gdi_image_draw(
            c->x - layer_offset_x,
            c->y - layer_offset_y,
            c->bg_image);
    }
    else if (c->bg_id != IMAGE_ID_NULL)
    {
        gdi_image_draw_id(
            c->x - layer_offset_x,
            c->y - layer_offset_y,
            c->bg_id);
    }
	else if (c->hide_callback != NULL)
    {
        c->hide_callback(
            x,
            y,
            x + width - 1,
            y + height - 1);
    }
    else
    {
        gdi_draw_solid_rect(
            x - layer_offset_x,
            y - layer_offset_y,
            x + width - 1 - layer_offset_x,
            y + height - 1 - layer_offset_y,
            GDI_COLOR_TRANSPARENT);
    }
	if (c->abm_layer != NULL)
	{
        gdi_pop_and_restore_alpha_blending_source_layer();
	}
    gdi_layer_pop_clip();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_cell
 * DESCRIPTION
 *  Redraw the data of one cell. Since gui_calendar_draw_cell_aray will help
 *  set active layer and alpha blending layer, so this API will draw directly.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 *  cell_x          [IN]    Is the x position of cell.
 *  cell_y          [IN]    Is the y position of cell.
 *  cell_width      [IN]    Is the width of cell.
 *  cell_height     [IN]    Is the height of cell.
 *  line_height     [IN]    Is the line height for vector font.
 *  base_line       [IN]    Is the base line for vector font.
 *  cell_date       [IN]    Is the date of cell.
 *  cell_data       [IN]    Is the cell data get from application. 
 *  flags           [IN]    Is the display flags of cell.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_cell(
             gui_calendar_struct* c,
             S32 cell_x,
             S32 cell_y,
             S32 cell_width,
             S32 cell_height,
             S32 line_height,
             S32 base_line,
             S32 cell_date,
             gui_calendar_cell_struct *cell_data,
             U32 flags,
             kal_uint8 DayIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fill_bg_x = 0, fill_bg_y = 0, fill_bg_width = 0, fill_bg_height = 0;
    S32 text_x = 0, text_y = 0, text_width, text_height;
    S32 icon_x = 0, icon_y = 0, icon_width, icon_height;
    S8 temp_text[GUI_CALENDAR_MAX_CELL_TEXT];
    UI_character_type cell_text[GUI_CALENDAR_MAX_CELL_TEXT];
#ifdef __MMI_MAINLCD_96X64__
    MMI_BOOL event_base_line = MMI_FALSE;
#endif
#if defined(__MMI_MAINLCD_128X160__) && (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    S32 date_icon_x, date_icon_y, date_icon_width, date_icon_height;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if ((flags & GUI_CALENDAR_CELL_DISPLAY_MASK) == GUI_CALENDAR_CELL_NO_DRAW)
    {
        return;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        cell_x,
        cell_y,
        cell_x + cell_width - 1,
        cell_y + cell_height - 1);

#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    if (c->is_in_venus == MMI_FALSE)
    {
#endif
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    }
#endif
    /* Draw the background of current cell. */
    if ((flags & GUI_CALENDAR_CELL_CURRENT) && !(c->flags & GUI_CALENDAR_HIDE_CURRENT_BACKGROUND))
    {
        if (c->cell_array.current_bg_filler != NULL)
        {
            gui_draw_filled_area(
                cell_x,
                cell_y,
                cell_x + cell_width - 1,
                cell_y + cell_height - 1,
                c->cell_array.current_bg_filler);
        }
    }
#ifdef __MMI_MAINLCD_96X64__
    if ((cell_data != NULL) && (cell_data->bg_index != GUI_CALENDAR_COLOR_NONE))
    {
        event_base_line = MMI_TRUE;
    }
#else /*__MMI_MAINLCD_96X64__*/
    /* Draw the event background of calendar. */
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    if (c->is_on_idle != MMI_TRUE)
    {
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    /* fill bg */
    if (flags & GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL)
    {
        fill_bg_x = cell_x;
        fill_bg_y = cell_y + cell_height - (cell_height >> 1);
        fill_bg_width = cell_width;
        fill_bg_height = cell_y + cell_height - fill_bg_y;
    }
    else if (flags & GUI_CALENDAR_CELL_BG_FILL_VERTICAL)
    {
        fill_bg_x = cell_x + (cell_width >> 2);
        fill_bg_y = cell_y;
        fill_bg_width = cell_width >> 1;
        fill_bg_height = cell_height;
    }

    if ((cell_data != NULL) && (cell_data->bg_index != GUI_CALENDAR_COLOR_NONE))
    {
        gdi_draw_solid_rect(
            fill_bg_x,
            fill_bg_y,
            fill_bg_x + fill_bg_width - 1,
            fill_bg_y + fill_bg_height - 1,
            gdi_act_color_from_rgb(
                c->cell_array.cell_bg[cell_data->bg_index].alpha,
                c->cell_array.cell_bg[cell_data->bg_index].r,
                c->cell_array.cell_bg[cell_data->bg_index].g,
                c->cell_array.cell_bg[cell_data->bg_index].b));
    }

    /* draw icon */
    if ((cell_data != NULL) && (cell_data->icon_id != 0))
    {
        gdi_image_get_dimension_id((U16)cell_data->icon_id, &icon_width, &icon_height);
        if (flags & GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHTTOP)
        {
            icon_x = cell_x + cell_width - icon_width - 1;
            icon_y = cell_y + 1;
        }
        else if (flags & GUI_CALENDAR_CELL_ICON_DISPLAY_CENTER)
        {
            icon_x = cell_x + ((cell_width-icon_width) >> 1);
            icon_y = cell_y + ((cell_height-icon_height) >> 1);
        }

        gdi_image_draw_id(icon_x, icon_y, (U16)cell_data->icon_id);
    }
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    }
#endif
#endif /*__MMI_MAINLCD_96X64__*/
    /* draw text */
    if (!(flags & GUI_CALENDAR_CELL_DATE_DISPLAY_DISABLE) &&
        (cell_date != GUI_CALENDAR_CELL_INVALID_DATE))
    {
        if(flags & GUI_CALENDAR_CELL_DATE_DISPLAY_CENTER)
        {
            sprintf((S8*)temp_text, "%d", cell_date);
        }
        else
        {
            sprintf((S8*)temp_text, "%2d", cell_date);
        }
        mmi_asc_to_ucs2((S8*)cell_text, temp_text);

        if ((flags & GUI_CALENDAR_CELL_CURRENT) && !(c->flags & GUI_CALENDAR_HIDE_CURRENT_BACKGROUND))
        {
            gui_set_font(c->cell_array.current_font);
            if (c->cell_array.current_font != c->cell_array.cell_font)
            {
                mmi_fe_get_string_info_param_struct query;
                /* Use a default date string to calculate base_line and line_height */
                memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
                query.String = (U8*)cell_text;
                query.n = mmi_ucs2strlen((const char*)cell_text);
                query.enableTruncated = MMI_FALSE;
                query.w = 0;
                mmi_fe_get_string_widthheight(&query);

                if (query.baseline > base_line)
                {
                    base_line = query.baseline;
                }
                if (query.pHeight> line_height)
                {
                    line_height = query.pHeight;
                }
            }
        }
        else
        {
            gui_set_font(c->cell_array.cell_font);
        }

        gui_measure_string(cell_text, &text_width, &text_height);
        text_height = line_height;
        
        if (flags & GUI_CALENDAR_CELL_DATE_DISPLAY_LEFT_BOTTOM)
        {
            text_x = cell_x;
            text_y = cell_y + cell_height - text_height;
        #ifdef __MMI_FTE_SUPPORT__
            text_x = text_x + GUI_CALENDAR_FRAME_LINE_PIXEL;
            text_y = text_y - GUI_CALENDAR_FRAME_LINE_PIXEL;
        #endif
        }
        else if (flags & GUI_CALENDAR_CELL_DATE_DISPLAY_CENTER_BOTTOM)
        {
            text_x = cell_x + ((cell_width - text_width) >> 1);
            text_y = cell_y + cell_height - text_height;
        #ifdef __MMI_FTE_SUPPORT__
            text_y = text_y - GUI_CALENDAR_FRAME_LINE_PIXEL;
        #endif
        }
        else if(flags & GUI_CALENDAR_CELL_DATE_DISPLAY_CENTER)
        {
            text_x = cell_x + ((cell_width-text_width+1) >> 1);
            text_y = cell_y + ((cell_height-text_height+1) >> 1);
        }
        else
        {
            MMI_DBG_ASSERT(0);
        }

        if (flags & GUI_CALENDAR_CELL_VALID)
        {
            if ((flags & GUI_CALENDAR_CELL_CURRENT) && !(c->flags & GUI_CALENDAR_HIDE_CURRENT_BACKGROUND))
            {    
                gui_set_text_color(c->cell_array.cell_current_text);
            }
            else
            {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
                gui_set_text_color(c->cell_array.cell_valid_text);
#endif
            }
        }
        else
        {
            gui_set_text_color(c->cell_array.cell_invalid_text);
        }

        if (mmi_fe_get_r2l_state())
        {
            text_x += text_width - 1;
        }   

    #if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && defined(__MMI_MAINLCD_128X160__) && (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
        if ((c->type == GUI_CALENDAR_TYPE_WEEK) &&
            (c->is_in_venus == MMI_TRUE) &&
            (c->is_on_idle == MMI_TRUE))
        {
            gdi_image_get_dimension_id(
                IMG_ID_IDLE_CALENDAR_NUM_0,
                &date_icon_width,
                &date_icon_height);
            if (date / 10 > 0)
            {
                date_icon_x = cell_x + ((cell_width - date_icon_width * 2) >> 1);
            }
            else
            {
                date_icon_x = cell_x + ((cell_width - date_icon_width) >> 1);
            }
            date_icon_y = cell_y + ((cell_height - date_icon_height) >> 1);
            if (date / 10 > 0)
            {
                gdi_image_draw_id(
                    date_icon_x,
                    date_icon_y,
                    (U16)(IMG_ID_IDLE_CALENDAR_NUM_0 + cell_date / 10));
                if ((flags & GUI_CALENDAR_CELL_EVENT) == GUI_CALENDAR_CELL_SCHEDULED)
                {
                    gui_draw_horizontal_line(
                        date_icon_x,
                        date_icon_x + date_icon_width - 1,
                        date_icon_y + date_icon_height + 1,
                        c->horizontal_string.text_color);
                }
                date_icon_x += date_icon_width;
            }
            gdi_image_draw_id(
                date_icon_x,
                date_icon_y,
                (U16)(IMG_ID_IDLE_CALENDAR_NUM_0 + cell_date % 10));
            if (flags & GUI_CALENDAR_CELL_SCHEDULED)
            {
                gui_draw_horizontal_line(
                    date_icon_x,
                    date_icon_x + date_icon_width - 1,
                    date_icon_y + date_icon_height + 1,
                    c->horizontal_string.text_color);
            }
        }
        else
        {
    #endif /* __MMI_MAINLCD_128X160__ && (__MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__) */
        mmi_fe_show_string_baseline(
            text_x,
            text_y,
            (PU8)cell_text,
            base_line,
            0);
#ifdef __MMI_MAINLCD_96X64__
            if(event_base_line == MMI_TRUE)
            {
                 gui_draw_horizontal_line(
                    cell_x +1,
                    cell_x + cell_width- 1,
                    cell_y + cell_height - 1 -1,
                    gui_get_text_color());
            }
#endif
        #if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
            if ((c->type == GUI_CALENDAR_TYPE_WEEK) &&
                (c->is_in_venus == MMI_TRUE) &&
                (c->is_on_idle == MMI_TRUE))
            {
                gui_draw_horizontal_line(
                    text_x,
                    text_x + text_width - 1,
                    text_y + text_height + 1,
                    c->horizontal_string.text_color);
            }
        #endif
    #if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && defined(__MMI_MAINLCD_128X160__) && (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
        }
    #endif
    }

#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    if (c->is_in_venus == MMI_FALSE)
    {
#endif
    gdi_pop_and_restore_alpha_blending_source_layer();
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    }
#endif
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_cell_array
 * DESCRIPTION
 *  Redraw the cell array of calendar.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_draw_cell_array(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y;
    U32 cell_flags = 0;
    U32 i, j;

    mmi_fe_get_string_info_param_struct query;
    S32 line_height = 0, base_line = 0;
    U8 date_str[12][GUI_CALENDAR_MAX_CELL_TEXT] = {"01", "02", "03", "04",
                                                   "05", "06", "17", "18",
                                                   "28", "29", "30", "31"};
    UI_character_type cell_text[GUI_CALENDAR_MAX_CELL_TEXT];

    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;
    applib_time_struct temp;
    applib_time_struct inc, result, current;
    gui_calendar_cell_struct *cell_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->cell_array.x + c->x - layer_offset_x,
        c->cell_array.y + c->y - layer_offset_y,
        c->cell_array.x + c->cell_array.width - 1 + c->x - layer_offset_x,
        c->cell_array.y + c->cell_array.height - 1 + c->y - layer_offset_y);

    /* Use a default date string to calculate base_line and line_height */
    gui_set_font(c->cell_array.cell_font);
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    for (i = 0; i < (sizeof(date_str) / sizeof(date_str[0])); i++)
    {
        mmi_asc_to_ucs2((S8*)cell_text, (S8*)date_str[i]);
        query.String = (U8*)cell_text;
        query.n = mmi_ucs2strlen((const char*)cell_text);
        query.enableTruncated = MMI_FALSE;
        query.w = 0;
        mmi_fe_get_string_widthheight(&query);
        
        if (query.baseline > base_line)
        {
            base_line = query.baseline;
        }
        
        if (query.pHeight> line_height)
        {
            line_height = query.pHeight;
        }
    }

    /* 
     * Redraw each cell. The monthly view need draw by horizontal 
     * direction but weekly view need draw by vertical direction.
     */
    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {

        temp = c->start_time;
        applib_dt_get_date_time(&current);
        for (i = 0; i < c->row; i++)
        {
            #ifdef __MMI_MAINLCD_96X64__
            cell_y = c->cell_array.y + (c->cell_array.cell_height - 1) * i;
            #else
            cell_y = c->cell_array.y + (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) * i;
            #endif
            for (j = 0; j < c->column; j++)
            {
            #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                MMI_BOOL cell_no_draw = MMI_FALSE;
            #endif
                cell_x = c->cell_array.x + (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) * j;
				if (c->cell_array.cells)
				{
                    cell_data = (gui_calendar_cell_struct *)(c->cell_array.cells) + i * c->column + j;
				}

                applib_dt_increase_time(
                    (applib_time_struct*)&temp,
                    (applib_time_struct*)&(c->time_interval),
                    (applib_time_struct*)&result);

                cell_flags = 0;
                if (temp.nMonth != c->highlight_time.nMonth)
                {
                    cell_flags |= GUI_CALENDAR_CELL_INVALID;
                #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                    if (c->is_on_idle == TRUE &&
                        temp.nMonth != c->highlight_time.nMonth)
                    {
                        if (temp.nYear < c->highlight_time.nYear ||
                            (temp.nYear == c->highlight_time.nYear &&
                             temp.nMonth < c->highlight_time.nMonth))
                        {
                            cell_no_draw = MMI_TRUE;
                        }
                    }
                #endif
                }
                else
                {
                    cell_flags |= GUI_CALENDAR_CELL_VALID;
                    if (temp.nDay == c->highlight_time.nDay)
                    {
                        cell_flags |= GUI_CALENDAR_CELL_HIGHLIGHT;
                    }
                    if (current.nYear == temp.nYear &&
                        current.nMonth == temp.nMonth &&
                        current.nDay == temp.nDay)
                    {
                        cell_flags |= GUI_CALENDAR_CELL_CURRENT;
                    }
                }

            #if !(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                cell_flags |= GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHTTOP;
            #endif
            cell_flags |= GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL;

            #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                if (c->is_on_idle == TRUE)
                {
                    cell_flags |= GUI_CALENDAR_CELL_DATE_DISPLAY_CENTER_BOTTOM;
                }
                else
                {
           #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
           #ifdef __MMI_MAINLCD_96X64__
                    cell_flags |= GUI_CALENDAR_CELL_DATE_DISPLAY_CENTER;
           #else
                    cell_flags |= GUI_CALENDAR_CELL_DATE_DISPLAY_LEFT_BOTTOM;
           #endif
            #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                }
            #endif

            if (c->type == GUI_CALENDAR_TYPE_MONTH)
            {
                cell_flags |= GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHTTOP;
            }
			if (cell_data != NULL)
			{
                cell_flags |= (cell_data->flags & 0x0000000F);
			}
	    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
			if (cell_no_draw == MMI_FALSE)
			{
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
            gui_calendar_draw_cell(
                c,
                cell_x + c->x - layer_offset_x,
                cell_y + c->y - layer_offset_y,
                c->cell_array.cell_width,
                c->cell_array.cell_height,
                line_height,
                base_line,
                temp.nDay,
                cell_data,
                cell_flags,
                temp.DayIndex);
        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            }
        #endif
            temp = result;
            }
        }
    }
    else if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        temp = c->start_time;
        for (i = 0; i < c->column; i++)
        {
            cell_x = c->cell_array.x + (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) * i;
            inc.nDay = 0;
            inc.nHour = GUI_CALENDAR_WEEK_TIME_INTERVAL;
            for (j = 0; j < c->row; j++)
            {
            #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                MMI_BOOL cell_no_draw = MMI_FALSE;
            #endif
                cell_y = c->cell_array.y + (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) * j;
				if (c->cell_array.cells != NULL)
				{
                    cell_data = (gui_calendar_cell_struct *)(c->cell_array.cells) + i * c->row + j;
				}

                cell_flags = 0;

                if (c->highlight_time.nYear == temp.nYear &&
                    c->highlight_time.nMonth == temp.nMonth &&
                    c->highlight_time.nDay == temp.nDay &&
                    c->highlight_time.nHour == temp.nHour)
                {
                    cell_flags |= GUI_CALENDAR_CELL_HIGHLIGHT;
                }

                cell_flags |= GUI_CALENDAR_CELL_BG_FILL_VERTICAL;

            #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                if (c->is_on_idle == TRUE)
                {
                    cell_no_draw = MMI_TRUE;
                }
            #endif

            if (cell_data != NULL)
			{
			    cell_flags |= (cell_data->flags & 0x0000000F);
			}

        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
			if (cell_no_draw == MMI_FALSE)
			{
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
            gui_calendar_draw_cell(
                c,
                cell_x + c->x - layer_offset_x,
                cell_y + c->y - layer_offset_y,
                c->cell_array.cell_width,
                c->cell_array.cell_height,
                line_height,
                base_line,
                GUI_CALENDAR_CELL_INVALID_DATE,
                cell_data,
                cell_flags,
                temp.DayIndex);
        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            }
        #endif

            applib_dt_increase_time(
                    (applib_time_struct*)&temp,
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&result);
            temp = result;
            }
            inc.nHour = 0;
            inc.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL;
            temp.nHour = c->start_time.nHour;
            applib_dt_increase_time(
                (applib_time_struct*)&temp,
                (applib_time_struct*)&inc,
                (applib_time_struct*)&result);
            temp = result;
        }
    }

    gdi_layer_pop_clip();
    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_horizontal_string
 * DESCRIPTION
 *  Redraw the horizontal string of calendar.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_horizontal_string(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y, cell_width, cell_height;
    S32 string_width, string_height, string_x; 
    U32 i;

    mmi_fe_get_string_info_param_struct weekday_query, date_query;
    S32 weekday_line_h = 0, weekday_base_line = 0;
    S32 date_line_h = 0, date_base_line = 0;
    applib_time_struct temp, inc, result;
    S8 temp_text[GUI_CALENDAR_MAX_HORIZONTAL_STRING_TEXT];
    UI_character_type string_text[GUI_CALENDAR_MAX_HORIZONTAL_STRING_TEXT];
    U8 weekday_str[7][4] = {"Sun", "Mon", "Tus", "Wed", "Thu", "Fri", "Sat"};

    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->horizontal_string.height == 0)
    {
        return;
    }

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->horizontal_string.x + c->x - layer_offset_x,
        c->horizontal_string.y + c->y - layer_offset_y,
        c->horizontal_string.x + c->horizontal_string.width - 1 + c->x - layer_offset_x,
        c->horizontal_string.y + c->horizontal_string.height - 1 + c->y - layer_offset_y);

    gui_set_font(c->horizontal_string.text_font);
    gui_set_text_color(c->horizontal_string.text_color);

    /* Calculate the horizontal string's base line. */
    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    temp = c->start_time;
    inc.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL;

    memset(&weekday_query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    memset(&date_query, 0, sizeof(mmi_fe_get_string_info_param_struct));

    for(i = 0; i < c->column; i++)
    {
        /* Meausre the vash line and line height. */
        if (c->flags & GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_ONE_LINE)
        {
            sprintf((S8*)temp_text, "%1.1s%d", weekday_str[temp.DayIndex], temp.nDay);
            mmi_asc_to_ucs2((S8*)string_text, temp_text);
            weekday_query.String = (U8*)string_text;
            weekday_query.n = mmi_ucs2strlen((const char*)string_text);
            weekday_query.enableTruncated = MMI_FALSE;
            weekday_query.w = 0;
            mmi_fe_get_string_widthheight(&weekday_query);
            
            date_query.baseline = 0;
            date_query.pHeight = 0;
        }
        else
        {
            sprintf((S8*)temp_text, "%d", temp.nDay);
            mmi_asc_to_ucs2((S8*)string_text, temp_text);
            date_query.String = (U8*)string_text;
            date_query.n = mmi_ucs2strlen((const char*)string_text);
            date_query.enableTruncated = MMI_FALSE;
            date_query.w = 0;
            mmi_fe_get_string_widthheight(&date_query);
            
            sprintf((S8*)temp_text, "%1.1s", weekday_str[temp.DayIndex]);
            mmi_asc_to_ucs2((S8*)string_text, temp_text);
            weekday_query.String = (U8*)string_text;
            weekday_query.n = mmi_ucs2strlen((const char*)string_text);
            weekday_query.enableTruncated = MMI_FALSE;
            weekday_query.w = 0;
            mmi_fe_get_string_widthheight(&weekday_query);
        }

        if (weekday_query.baseline > weekday_base_line)
        {
            weekday_base_line = weekday_query.baseline;
        }        
        if (weekday_query.pHeight > weekday_line_h)
        {
            weekday_line_h = weekday_query.pHeight;
        }
        if (date_query.baseline > date_base_line)
        {
            date_base_line = date_query.baseline;
        }        
        if (date_query.pHeight > date_line_h)
        {
            date_line_h = date_query.pHeight;
        }

        applib_dt_increase_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
        result.DayIndex = applib_dt_dow(result.nYear, result.nMonth, result.nDay);
        temp = result;
    }

    /* Display the horizontal string. */
    temp = c->start_time;
    for(i = 0; i < c->column; i++)
    {
        /* Draw the weekday string. */
        if (c->type == GUI_CALENDAR_TYPE_WEEK &&
            c->flags & GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_ONE_LINE)
        {
            if (c->flags & GUI_CALENDAR_WEEK_HIDE_DATE_STRING)
            {
                sprintf((S8*)temp_text, "%1.1s", weekday_str[temp.DayIndex]);
            }
            else if (c->flags & GUI_CALENDAR_WEEK_HIDE_WEEKDAY_STRING)
            {
                sprintf((S8*)temp_text, "%d", temp.nDay);
            }
            else
            {
                sprintf((S8*)temp_text, "%1.1s%d", weekday_str[temp.DayIndex], temp.nDay);
            }
        }
        else
        {
            sprintf((S8*)temp_text, "%1.1s", weekday_str[temp.DayIndex]);
        }
        mmi_asc_to_ucs2((S8*)string_text, temp_text);
        gui_measure_string((UI_string_type)string_text, &string_width, &string_height);

        cell_width =  c->horizontal_string.cell_width;
        cell_x = c->horizontal_string.x + i * (cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL);
        cell_y = c->horizontal_string.y;
        if (c->type == GUI_CALENDAR_TYPE_WEEK &&
            c->flags & GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_TWO_LINE)
        {
            cell_height = c->horizontal_string.height >> 1;
        }
        else
        {
            cell_height = c->horizontal_string.height;
        }
        string_height = weekday_line_h;
        string_x = cell_x + ((cell_width - string_width) >> 1);
        if (mmi_fe_get_r2l_state())
        {
            string_x += string_width - 1;
        }
        if (c->type == GUI_CALENDAR_TYPE_MONTH ||
            (c->type == GUI_CALENDAR_TYPE_WEEK &&
            !(c->flags & GUI_CALENDAR_WEEK_HIDE_WEEKDAY_STRING)))
        {
#ifndef __MMI_MAINLCD_96X64__
            mmi_fe_show_string_baseline(
                string_x + c->x - layer_offset_x,
                cell_y + ((cell_height - string_height) >> 1) + c->y - layer_offset_y,
                (PU8)string_text,
                weekday_base_line,
                0);
#else
            gui_set_text_border_color(*current_MMI_theme->calendar_horizontal_border_color);
            mmi_fe_show_string_bordered_baseline(
                string_x + c->x - layer_offset_x,
                cell_y + (cell_height - string_height) + c->y - layer_offset_y,
                (PU8)string_text,
                weekday_base_line,
                0);
#endif
        }

		if (c->type == GUI_CALENDAR_TYPE_WEEK)
		{
		    applib_time_struct current;
		    applib_dt_get_date_time(&current);

		    if (c->flags & GUI_CALENDAR_WEEK_HIDE_WEEKDAY_STRING ||
		        c->flags & GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_TWO_LINE)
		    {
                /* Draw the date string. */
                sprintf((S8*)temp_text, "%d", temp.nDay);
                mmi_asc_to_ucs2((S8*)string_text, temp_text);
                gui_measure_string((UI_string_type)string_text, &string_width, &string_height);

                if (c->flags & GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_TWO_LINE)
                {
                    cell_height = c->horizontal_string.height >> 1;
                    cell_y = c->horizontal_string.y + cell_height;
                }
                else
                {
                    cell_height = c->horizontal_string.height;
                    cell_y = c->horizontal_string.y;
                }

                if (date_base_line == 0)
                {
                    date_base_line = weekday_base_line;
                }
                if (date_line_h == 0)
                {
                    date_line_h = weekday_line_h;
                }

                string_height = date_line_h;
                string_x = cell_x + ((cell_width - string_width) >> 1);
                if (mmi_fe_get_r2l_state())
                {
                    string_x += string_width - 1;
                }
                mmi_fe_show_string_baseline(
                    string_x + c->x - layer_offset_x,
                    cell_y + ((cell_height - string_height) >> 1) + c->y - layer_offset_y,
                    (PU8)string_text,
                    date_base_line,
                    0);
            }
            if (current.nDay == temp.nDay &&
                current.nMonth == temp.nMonth &&
                current.nYear == temp.nYear)
            {
                S32 underline_y;
                underline_y = cell_y + cell_height - ((cell_height - string_height) >> 2);
                if (underline_y > c->horizontal_string.y + c->horizontal_string.height - 1)
                {
                    underline_y = c->horizontal_string.y + c->horizontal_string.height - 1;
                }
                gui_draw_horizontal_line(
                    cell_x + (cell_width >> 1) - (string_width >> 1) + c->x - layer_offset_x,
                    cell_x + (cell_width >> 1) + (string_width >> 1) + c->x - layer_offset_x,
                    underline_y + c->y - layer_offset_y,
                    c->horizontal_string.text_color);
            }
		}
        
        applib_dt_increase_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
        temp = result;
    }

    gdi_layer_pop_clip();
    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_vertical_select
 * DESCRIPTION
 *  Display the vertical select of calendar.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_vertical_select(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x = 0, cell_y = 0, cell_width, cell_height;
    S32 string_x, string_y, string_width, string_height; 
    U32 i;
#ifdef __MMI_TOUCH_SCREEN__
    PU8 icon;
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
    U16 bg_icon;
    S32 icon_width, icon_height;
    gdi_handle diable_button_layer;
#endif
#endif
    applib_time_struct temp, inc, result;
    S8 temp_text[GUI_CALENDAR_MAX_VERTICAL_SELECT_TEXT];
    UI_character_type string_text[GUI_CALENDAR_MAX_VERTICAL_SELECT_TEXT];

    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;
    gdi_handle abm_src_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->vertical_select.width == 0)
    {
        return;
    }

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->vertical_select.x + c->x - layer_offset_x,
        c->vertical_select.y + c->y - layer_offset_y,
        c->vertical_select.x + c->vertical_select.width - 1 + c->x - layer_offset_x,
        c->vertical_select.y + c->vertical_select.height - 1 + c->y - layer_offset_y);
    
    if (c->abm_layer != NULL)
    {
        abm_src_layer = c->abm_layer;
    }
    else
    {
        gdi_layer_get_active(&abm_src_layer);
    }
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if( c->is_on_idle == MMI_FALSE)
    {
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#ifndef __MMI_FTE_SUPPORT__
    gdi_effect_alpha_blending_rect(
        abm_src_layer, 
        c->vertical_select.x + c->x - layer_offset_x,
        c->vertical_select.y + c->y - layer_offset_y,
        c->vertical_select.x + c->vertical_select.width - 1 + c->x - layer_offset_x,
        c->vertical_select.y + c->vertical_select.height - 1 + c->y - layer_offset_y,
        c->vertical_select.bg_alpha * 255 / 100, c->vertical_select.bg_color.r, c->vertical_select.bg_color.g, c->vertical_select.bg_color.b);
#else
    {
        gdi_effect_alpha_blending_rect(
            abm_src_layer, 
            c->vertical_select.x + c->x - layer_offset_x,
            c->cell_array.y + c->y - layer_offset_y,
            c->vertical_select.x + c->vertical_select.width - 1 + c->x - layer_offset_x,
            c->vertical_select.y + c->vertical_select.height - 1 + c->y - layer_offset_y,
            c->vertical_select.bg_alpha * 255 / 100, c->vertical_select.bg_color.r, c->vertical_select.bg_color.g, c->vertical_select.bg_color.b);

        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
            S32 temp_x, temp_y;
            for (i = 1; i < c->row; i++)
            {
                temp_x = c->vertical_select.x;
                temp_y = c->cell_array.y + i * (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) - 1;
                gdi_effect_alpha_blending_rect(
                    abm_src_layer,
                    temp_x + c->x - layer_offset_x,
                    temp_y + c->y - layer_offset_y,
                    temp_x + c->vertical_select.width - 1 + c->x - layer_offset_x,
                    temp_y + GUI_CALENDAR_FRAME_LINE_PIXEL - 1 + c->y - layer_offset_y,
                    c->frame_line_alpha * 255 / 100, (c->frame_line).r, (c->frame_line).g, (c->frame_line).b);
            }
        }
    }
#endif
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#ifdef __MMI_TOUCH_SCREEN__
    c->vertical_select.prev_icon_y = c->vertical_select.y;
    c->vertical_select.next_icon_y = c->vertical_select.y + c->vertical_select.height - 1;
    if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        /* Draw prev arrow. */
        if (c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
            c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
        {
            icon = c->vertical_select.prev_down_icon;
            #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            bg_icon = CAL_DOWN_ARROW_BG_9SLICE_IMAGE;
            #endif
        }
        else if (c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
        {
            icon = c->vertical_select.prev_disable_icon;
            #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            bg_icon = CAL_UP_ARROW_BG_9SLICE_IMAGE;
            #endif
        }
        else
        {
            icon = c->vertical_select.prev_up_icon;
            #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            bg_icon = CAL_UP_ARROW_BG_9SLICE_IMAGE;
            #endif
        }
        if(icon != NULL)
        {
            c->vertical_select.prev_icon_x = c->vertical_select.x + ((c->vertical_select.width - c->vertical_select.prev_icon_width) >> 1);
            c->vertical_select.prev_icon_y = c->vertical_select.y;
        #ifdef __MMI_FTE_SUPPORT__
            c->vertical_select.prev_icon_y = c->cell_array.y;
        #endif

        #if defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_CLNDR_FTE_SLIM_RES__)
            if (c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
            {
                c->vertical_select.prev_icon_x += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                c->vertical_select.prev_icon_y += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
            }
        #endif
			gdi_layer_push_clip();
            gdi_layer_set_clip(
                c->vertical_select.x + c->x - layer_offset_x,
                c->vertical_select.prev_icon_y + c->y - layer_offset_y,
                c->vertical_select.x + c->vertical_select.width - 1 + c->x - layer_offset_x,
                c->vertical_select.prev_icon_y + c->vertical_select.prev_icon_height - 1 + c->y - layer_offset_y);
        #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            if (c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                gdi_layer_create(
                    c->vertical_select.x + c->x - layer_offset_x,
                    c->vertical_select.prev_icon_y + c->y - layer_offset_y,
                    c->vertical_select.width,
                    c->vertical_select.prev_icon_height,
                &diable_button_layer);
                gdi_layer_push_and_set_active(diable_button_layer);
                gdi_push_and_set_alpha_blending_source_layer(diable_button_layer);
                gdi_layer_set_opacity(KAL_TRUE,128);
                gdi_image_draw_resized_id(
                    0,
                    0,
                    c->vertical_select.prev_icon_width,
                    c->vertical_select.prev_icon_height,
                    bg_icon);           
                gdi_image_get_dimension(c->vertical_select.prev_down_icon,&icon_width,&icon_height);
                gdi_image_draw(
                    (c->vertical_select.prev_icon_width - icon_width)>>1,
                    (c->vertical_select.prev_icon_height - icon_height)>>1,
                    icon);
                gdi_pop_and_restore_alpha_blending_source_layer();
                gdi_layer_pop_and_restore_active();
                gdi_layer_flatten_with_clipping(abm_src_layer,diable_button_layer,0,0);
                gdi_layer_free(diable_button_layer);
            }
            else
            {
                gdi_image_draw_resized_id(
                    c->vertical_select.prev_icon_x + c->x - layer_offset_x,
                    c->vertical_select.prev_icon_y + c->y - layer_offset_y,
                    c->vertical_select.prev_icon_width,
                    c->vertical_select.prev_icon_height,
                    bg_icon);           
                gdi_image_get_dimension(c->vertical_select.prev_down_icon,&icon_width,&icon_height);
                gdi_image_draw(
                    c->vertical_select.prev_icon_x + ((c->vertical_select.prev_icon_width - icon_width)>>1) + c->x - layer_offset_x,
                    c->vertical_select.prev_icon_y + ((c->vertical_select.prev_icon_height - icon_height)>>1) + c->y - layer_offset_y,
                    icon);
            }
        #else
            gdi_image_draw(
                c->vertical_select.prev_icon_x + c->x - layer_offset_x,
                c->vertical_select.prev_icon_y + c->y - layer_offset_y,
                icon);
        #endif
			gdi_layer_pop_clip();
        }

        /* Draw next arrow. */
        if (c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
            c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
        {
            icon = c->vertical_select.next_down_icon;
            #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            bg_icon = CAL_DOWN_ARROW_BG_9SLICE_IMAGE;
            #endif
        }
        else if (c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
        {
            icon = c->vertical_select.next_disable_icon;
            #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            bg_icon = CAL_UP_ARROW_BG_9SLICE_IMAGE;
            #endif
        }
        else
        {
            icon = c->vertical_select.next_up_icon;
            #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            bg_icon = CAL_UP_ARROW_BG_9SLICE_IMAGE;
            #endif
        }
        if(icon != NULL)
        {
            c->vertical_select.next_icon_x = c->vertical_select.x + ((c->vertical_select.width - c->vertical_select.next_icon_width) >> 1);
            c->vertical_select.next_icon_y = c->vertical_select.y + c->vertical_select.height - c->vertical_select.next_icon_height;
        #if defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_CLNDR_FTE_SLIM_RES__)
            if (c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
            {
                c->vertical_select.next_icon_x += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                c->vertical_select.next_icon_y += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
            }
        #endif
    	    gdi_layer_push_clip();
            gdi_layer_set_clip(
                c->vertical_select.x + c->x - layer_offset_x,
                c->vertical_select.next_icon_y + c->y - layer_offset_y,
                c->vertical_select.x + c->vertical_select.width - 1 + c->x - layer_offset_x,
                c->vertical_select.next_icon_y + c->vertical_select.next_icon_height - 1 + c->y - layer_offset_y);
        #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            if (c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                gdi_layer_create(
                    c->vertical_select.x + c->x - layer_offset_x,
                    c->vertical_select.next_icon_y + c->y - layer_offset_y,
                    c->vertical_select.width,
                    c->vertical_select.next_icon_height,
                &diable_button_layer);
                gdi_layer_push_and_set_active(diable_button_layer);
                gdi_push_and_set_alpha_blending_source_layer(diable_button_layer);
                gdi_layer_set_opacity(KAL_TRUE,128);
                gdi_image_draw_resized_id(
                    0,
                    0,
                    c->vertical_select.next_icon_width,
                    c->vertical_select.next_icon_height,
                    bg_icon);           
                gdi_image_get_dimension(c->vertical_select.next_down_icon,&icon_width,&icon_height);
                gdi_image_draw(
                    (c->vertical_select.next_icon_width - icon_width)>>1,
                    (c->vertical_select.next_icon_height - icon_height)>>1,
                    icon);
                gdi_pop_and_restore_alpha_blending_source_layer();
                gdi_layer_pop_and_restore_active();
                gdi_layer_flatten_with_clipping(abm_src_layer,diable_button_layer,0,0);
                gdi_layer_free(diable_button_layer);
            }
            else
            {
                gdi_image_draw_resized_id(
                    c->vertical_select.next_icon_x + c->x - layer_offset_x,
                    c->vertical_select.next_icon_y + c->y - layer_offset_y,
                    c->vertical_select.next_icon_width,
                    c->vertical_select.next_icon_height,
                    bg_icon);           
                gdi_image_get_dimension(c->vertical_select.next_down_icon,&icon_width,&icon_height);
                gdi_image_draw(
                    c->vertical_select.next_icon_x + ((c->vertical_select.next_icon_width - icon_width)>>1) + c->x - layer_offset_x,
                    c->vertical_select.next_icon_y + ((c->vertical_select.next_icon_height - icon_height)>>1) + c->y - layer_offset_y,
                    icon);
            }
        #else/* __MMI_CLNDR_FTE_SLIM_RES__ */
            gdi_image_draw(
                c->vertical_select.next_icon_x + c->x - layer_offset_x,
                c->vertical_select.next_icon_y + c->y - layer_offset_y,
                icon);
        #endif
			gdi_layer_pop_clip();
        }
    }
#endif /* __MMI_TOUCH_SCREEN__ */

    /* Draw text string. */
    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    temp = c->start_time;
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
        inc.nDay = GUI_CALENDAR_WEEK_DAY_OF_WEEK - 1;
        applib_dt_increase_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
        temp = result;
        inc.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL * c->column;
    }
    if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        inc.nHour = GUI_CALENDAR_WEEK_TIME_INTERVAL;
    }
    for (i = 0; i < c->row; i++)
    {
        do
        {
        cell_x = c->vertical_select.x;
        cell_width = c->vertical_select.width;
        cell_height = c->cell_array.cell_height;
        if(c->vertical_select.align == GUI_CALENDAR_ALIGN_CELL)
        {
            cell_y = c->cell_array.y + i * (cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL);
        }
        else if(c->vertical_select.align == GUI_CALENDAR_ALIGN_LINE)
        {
            cell_y = c->cell_array.y + i * (cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) - (cell_height >> 1);
        }

        gui_set_font(c->vertical_select.text_font);
        gui_set_text_color(c->vertical_select.text_color);
        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
        #if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
            sprintf((S8*)temp_text, "%c%d%d", 'W', applib_dt_get_week_number(&temp) / 10, applib_dt_get_week_number(&temp) % 10);
        #else
	    sprintf((S8*)temp_text, "%d%d",applib_dt_get_week_number(&temp) / 10, applib_dt_get_week_number(&temp) % 10);
        #endif
            mmi_asc_to_ucs2((S8*)string_text, temp_text);
        }
        else if (c->type == GUI_CALENDAR_TYPE_WEEK)
        {
        #ifdef __MMI_FTE_SUPPORT__
            if (i == 0)
	    {
                continue;
            }
        #endif
        #if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
			sprintf((S8*)temp_text, "%2d:%d%d", temp.nHour, temp.nMin / 10, temp.nMin % 10);
        #else
            sprintf((S8*)temp_text, "%2d", temp.nHour);
        #endif
            mmi_asc_to_ucs2((S8*)string_text, temp_text);
        }
        gui_measure_string((UI_string_type)string_text, &string_width, &string_height);
        string_x = cell_x + ((cell_width - string_width) >> 1);
        if (mmi_fe_get_r2l_state())
        {
            string_x += string_width - 1;
        }
        string_y = cell_y + ((cell_height - string_height) >> 1);
    #ifdef __MMI_TOUCH_SCREEN__
        if (string_y > (c->vertical_select.prev_icon_y + c->vertical_select.prev_icon_height - 1)
        #if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
            && (string_y + string_height - 1) < c->vertical_select.next_icon_y
        #endif
	)
        {
    #endif
            gui_move_text_cursor(
                string_x + c->x - layer_offset_x,
                string_y + c->y - layer_offset_y);
            gui_print_text((UI_string_type)string_text);
    #ifdef __MMI_TOUCH_SCREEN__
        }
    #endif
        }
        while (0);
        applib_dt_increase_time(
            (applib_time_struct*)&temp,
            (applib_time_struct*)&inc,
            (applib_time_struct*)&result);
        temp = result;
    }

    gdi_layer_pop_clip();
    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_title
 * DESCRIPTION
 *  Display the title of calendar.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_title(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height, string_x = 0;
    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__    
    S8 temp_text[GUI_CALENDAR_TITLE_MAX_LENGTH];
    U8 seperator;
    U8 date_format;
#endif
    UI_character_type string_text[GUI_CALENDAR_TITLE_MAX_LENGTH + 1];
#if defined(__MMI_TOUCH_SCREEN__)&& defined(__MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__)
    PU8 icon;
    S32 icon_width = 0, icon_height = 0, icon_x = 0, icon_y = 0;
#endif
    gdi_handle abm_src_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->title.height == 0)
    {
        return;
    }

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->title.x + c->x - layer_offset_x,
        c->title.y + c->y - layer_offset_y,
        c->title.x + c->title.width - 1 + c->x - layer_offset_x,
        c->title.y + c->title.height - 1 + c->y - layer_offset_y);

    gui_calendar_draw_bg(
        c,
        c->title.x + c->x,
        c->title.y + c->y,
        c->title.width,
        c->title.height);

	if (c->abm_layer != NULL)
    {
        abm_src_layer = c->abm_layer;
    }
    else
    {
        gdi_layer_get_active(&abm_src_layer);
    }
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        if( c->is_on_idle == MMI_FALSE)
        {
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    #ifndef __MMI_FTE_SUPPORT__
        gdi_effect_alpha_blending_rect(
            abm_src_layer, 
            c->title.x + c->x - layer_offset_x,
            c->title.y + c->y - layer_offset_y,
            c->title.x + c->title.width - 1 + c->x - layer_offset_x,
            c->title.y + c->title.height - 1 + c->y - layer_offset_y,
            c->title.bg_alpha * 255 / 100, c->title.bg_color.r, c->title.bg_color.g, c->title.bg_color.b);
    #else
            gdi_image_draw_resized_id(
                c->x + GUI_CALENDAR_FRAME_LINE_PIXEL - layer_offset_x,
                c->y + GUI_CALENDAR_FRAME_LINE_PIXEL - layer_offset_y,
                c->title.width,
                c->title.height,
                IMG_CALENDAR_HORIZONTAL_STRING_BG);
    #endif
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
		}
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

    gui_set_font(c->title.text_font);
    gui_set_text_color(c->title.text_color);


#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    date_format = PhnsetGetDateFormat();
    if (c->is_on_idle == MMI_TRUE)
    {
        S32 ascent = 0, descent = 0, string_y = 0;
        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
            PU8 month_string;
            month_string = (U8*)GetString((U16)(STR_GLOBAL_JANUARY_SHORT + c->highlight_time.nMonth - 1));
            sprintf((S8*)temp_text, "%04d", c->highlight_time.nYear);
            mmi_asc_to_ucs2((S8*)string_text, temp_text);

        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
            mmi_fe_get_char_info_of_all_lang(
                (c->title.text_font)->size,
	            &string_height,
	            &ascent,
	            &descent);
            string_y = c->title.y + (c->title.height >> 1) - ((ascent + descent) >> 1);
        #endif
            gui_measure_string((UI_string_type)month_string, &string_width, &string_height);
        #if !defined(__MMI_VECTOR_FONT_SUPPORT__)
            string_y = c->title.y + (c->title.height >> 1) - (string_height >> 1);
        #endif
        #if defined (__MMI_VUI_HOMESCREEN__)
            if (c->is_in_venus == MMI_TRUE)
            {
                if (date_format == 2)
                {
                    string_x = c->title.x + c->title.width - string_width - GUI_CALENDAR_VENUS_TITLE_BORDER_GAP_FOR_IDLE;
                }
                else
                {
                    string_x = GUI_CALENDAR_VENUS_TITLE_BORDER_GAP_FOR_IDLE;
                }
            }
            else
            {
        #endif
            if (date_format == 2)
            {
                string_x = c->title.x + (c->title.width >> 1) + (((c->title.width >> 1) - string_width) >> 1);
            }
            else
            {
                string_x = c->title.x + (((c->title.width >> 1) - string_width) >> 1);
            }            
        #if defined (__MMI_VUI_HOMESCREEN__)
            }
        #endif
            if (mmi_fe_get_r2l_state())
            {
                string_x += string_width - 1;
            }
        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
            mmi_fe_show_string_baseline(
                string_x + c->x - layer_offset_x,
                string_y + c->y - layer_offset_x,
                (PU8)month_string,
                ascent,
                0);
        #else
            gui_move_text_cursor(
                string_x + c->x - layer_offset_x,
                string_y + c->y - layer_offset_x);
            gui_print_text((UI_string_type)month_string);
        #endif

            gui_measure_string((UI_string_type)string_text, &string_width, &string_height);
        #if !defined(__MMI_VECTOR_FONT_SUPPORT__)
            string_y = c->title.y + (c->title.height >> 1) - (string_height >> 1);
        #endif
        #if defined (__MMI_VUI_HOMESCREEN__)
            if (c->is_in_venus == MMI_TRUE)
            {
                if (date_format == 2)
                {
                    string_x = GUI_CALENDAR_VENUS_TITLE_BORDER_GAP_FOR_IDLE;                    
                }
                else
                {
                    string_x = c->title.x + c->title.width - string_width - GUI_CALENDAR_VENUS_TITLE_BORDER_GAP_FOR_IDLE;
                }
            }
            else
            {
        #endif
            if (date_format == 2)
            {
                string_x = c->title.x + (((c->title.width >> 1) - string_width) >> 1);
            }
            else
            {                
                string_x = c->title.x + (c->title.width >> 1) + (((c->title.width >> 1) - string_width) >> 1);
            } 
            
        #if defined (__MMI_VUI_HOMESCREEN__)
            }
        #endif
            if (mmi_fe_get_r2l_state())
            {
                string_x += string_width - 1;
            }
        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
            mmi_fe_show_string_baseline(
                string_x + c->x - layer_offset_x,
                string_y + c->y - layer_offset_y,
                (PU8)string_text,
                ascent,
                0);
        #else
            gui_move_text_cursor(
                string_x + c->x - layer_offset_x,
                string_y + c->y - layer_offset_y);
            gui_print_text((UI_string_type)string_text);
        #endif
        }
        if (c->type == GUI_CALENDAR_TYPE_WEEK)
        {
            sprintf(
                (S8*)temp_text,
                "W%d%d-%04d",
                applib_dt_get_week_number(&c->highlight_time) /10,
				applib_dt_get_week_number(&c->highlight_time) % 10,
                c->highlight_time.nYear);
            mmi_asc_to_ucs2((S8*)string_text, temp_text);

            gui_measure_string((UI_string_type)string_text, &string_width, &string_height);
            string_x = c->title.x + ((c->title.width - string_width) >> 1);
            if (mmi_fe_get_r2l_state())
            {
                string_x += string_width - 1;
            }
            gui_move_text_cursor(
                string_x + c->x - layer_offset_x,
                c->title.y + ((c->title.height - string_height) >> 1) + c->y - layer_offset_y);
            gui_print_text((UI_string_type)string_text);        
        }
    }
    else
    {
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#if 0
/* under construction !*/
#else
    if ((c->title.text == NULL) || (UI_strlen((UI_string_type)c->title.text) == 0))
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
        date_string((UI_time *) &c->highlight_time,string_text,DT_DIGITAL_CLOCK_SC1);
    }
    else
    {
        /* Set 0 to title string's end. */
        mmi_ucs2ncpy(
            (S8*)string_text,
            (S8*)c->title.text,
            GUI_CALENDAR_TITLE_MAX_LENGTH);
        string_text[GUI_CALENDAR_TITLE_MAX_LENGTH] = 0;
    }
#endif
    gui_measure_string((UI_string_type)string_text, &string_width, &string_height);
    if (c->title.align == GUI_CALENDAR_ALIGN_CENTER)
    {
        string_x = c->title.x + ((c->title.width - string_width) >> 1);
    }
    if (c->title.align == GUI_CALENDAR_ALIGN_LEFT)
    {
        string_x = c->title.x;
    }
    if (c->title.align == GUI_CALENDAR_ALIGN_RIGHT)
    {
        string_x = c->title.x + c->title.width - string_width;
    }
    if (mmi_fe_get_r2l_state())
    {
        string_x += string_width - 1;
    }
#ifdef __MMI_MAINLCD_96X64__
    gui_scrolling_text_stop(&c->title.scrolling_title);
    if(string_width > c->title.width)
    {
        gui_create_scrolling_text(
                &c->title.scrolling_title,
                c->title.x + c->x - layer_offset_x,
                c->title.y + ((c->title.height - string_height) >> 1) + c->y - layer_offset_y,
                c->title.width + c->x - layer_offset_x,//c->title.x + c->title.width - 1 + c->x - layer_offset_x,
                c->title.y + c->title.height - 1 + c->y - layer_offset_y,
                (UI_string_type) c->title.text,
                gui_calendar_scrolling_title_text_handle,
                gui_calendar_scrolling_title_text_redraw_bg,
                c->title.text_color,
                c->title.bg_color);
        gui_show_scrolling_text(&c->title.scrolling_title);
    }
    else
    {
        gui_move_text_cursor(
            string_x + c->x - layer_offset_x,
            c->title.y + ((c->title.height - string_height) >> 1) + c->y - layer_offset_y);
        gui_print_text((UI_string_type)string_text);
    }
#else    
    gui_move_text_cursor(
        string_x + c->x - layer_offset_x,
        c->title.y + ((c->title.height - string_height) >> 1) + c->y - layer_offset_y);
    gui_print_text((UI_string_type)string_text);
#endif
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__)
    /* draw prev/next arrow of title */
    if (!(c->flags & GUI_CALENDAR_DISABLE_PREV_NEXT_SWITCH))
    {
        /* Draw prev arrow. */
        if (c->title.prev_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
            c->title.prev_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
        {
            icon = c->title.prev_down_icon;
        }
        else if (c->title.prev_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
        {
            icon = c->title.prev_disable_icon;
        }
        else
        {
            icon = c->title.prev_up_icon;
        }
        gdi_image_get_dimension(icon, &icon_width, &icon_height);
        if (c->title.align == GUI_CALENDAR_ALIGN_CENTER)
        {
            icon_x = c->title.x + ((string_x - c->title.x - icon_width) >> 1);
        }
        if (c->title.align == GUI_CALENDAR_ALIGN_LEFT)
        {
            icon_x = c->title.x + c->title.width - 2 * icon_width;
        }
        if (c->title.align == GUI_CALENDAR_ALIGN_RIGHT)
        {
            icon_x = c->title.x;
        }
		icon_y = c->title.y + ((c->title.height - icon_height) >> 1);
		c->title.prev_icon_x = icon_x;
		c->title.prev_icon_y = icon_y;
        if(icon != NULL)
        {
            gdi_image_draw(
                icon_x + c->x - layer_offset_x,
                icon_y + c->y - layer_offset_y,
                icon);
        }

        /* Draw next arrow. */
        if (c->title.next_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
            c->title.next_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
        {
            icon = c->title.next_down_icon;
        }
        else if (c->title.next_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
        {
            icon = c->title.next_disable_icon;
        }
        else
        {
            icon = c->title.next_up_icon;
        }
        gdi_image_get_dimension(icon, &icon_width, &icon_height);
        if (c->title.align == GUI_CALENDAR_ALIGN_CENTER)
        {
            icon_x = c->title.x + c->title.width - ((string_x - c->title.x - icon_width) >> 1) - icon_width;
        }
        if (c->title.align == GUI_CALENDAR_ALIGN_LEFT)
        {
            icon_x = c->title.x + c->title.width - icon_width;
        }
        if (c->title.align == GUI_CALENDAR_ALIGN_RIGHT)
        {
            icon_x = c->title.x + icon_width;
        }
		icon_y = c->title.y + ((c->title.height - icon_height) >> 1);
		c->title.next_icon_x = icon_x;
		c->title.next_icon_y = icon_y;
        if(icon != NULL)
        {
    	    gdi_image_draw(
                icon_x + c->x - layer_offset_x,
                icon_y + c->y - layer_offset_y,
                icon);
        }
    }
#endif /* __MMI_TOUCH_SCREEN__ */

    gdi_layer_pop_clip();

    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }

}

#ifdef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_scrolling_detail_text_redraw_bg
 * DESCRIPTION
 *  redraw detail text background
 * PARAMETERS
 *  x1       [IN]
 *  y1       [IN]
 *  x2       [IN]
 *  y2       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_scrolling_detail_text_redraw_bg(S32 x1,S32 y1,S32 x2,S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct *c = current_calendar_pointer;
    
    gui_fill_transparent_color( 
        x1,
        y1,
        x2,
        y2,
        c->detail.bg_color);
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_scrolling_detail_text_handle
 * DESCRIPTION
 *  Handle scroll text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_scrolling_detail_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct *c = current_calendar_pointer;
    
    gui_handle_scrolling_text(&c->detail.scrolling_detail);
	//gui_calendar_scrolling_detail_text_redraw_bg(0,0,0,0);
}
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_scrolling_title_text_redraw_bg
 * DESCRIPTION
 *  redraw title text background
 * PARAMETERS
 *  x1       [IN]
 *  y1       [IN]
 *  x2       [IN]
 *  y2       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_scrolling_title_text_redraw_bg(S32 x1,S32 y1,S32 x2,S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct *c = current_calendar_pointer;
    
    gui_fill_transparent_color( 
        x1,
        y1,
        x2,
        y2,
        c->title.bg_color);
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_scrolling_title_text_handle
 * DESCRIPTION
 *  Handle title scroll text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_scrolling_title_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calendar_struct *c = current_calendar_pointer;
    
    gui_handle_scrolling_text(&c->title.scrolling_title);
	//gui_calendar_scrolling_detail_text_redraw_bg(0,0,0,0);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_draw_detail
 * DESCRIPTION
 *  Display the detail of calendar.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_draw_detail(void)
{
#ifdef __MMI_CALENDAR_CHINESE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* These can be obtained from theme data  */
    UI_filled_area detail_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
        UI_NULL_IMAGE,
        NULL,
        {47, 55, 143, 80},
        {0, 0, 0, 0},
        {0, 0, 0, 100},
        {0, 0, 0, 0},
        0
    };
    S32 detail_x1, detail_y1, detail_x2, detail_y2;
    U32 highlight_row, highlight_column;
    S32 width, height, y;
#ifdef __MMI_MAINLCD_96X64__
    S32 str_height = 0;
#endif
    S32 icon_width[GUI_CALENDAR_DETAIL_ENTRY_NUM], icon_height[GUI_CALENDAR_DETAIL_ENTRY_NUM];
    S32 w[GUI_CALENDAR_DETAIL_ENTRY_NUM], h[GUI_CALENDAR_DETAIL_ENTRY_NUM];
    S32 x1 ,y1 ,x2, y2;
    S32 left_width, right_width, up_height, down_height;
    UI_string_type msg[GUI_CALENDAR_DETAIL_ENTRY_NUM];
    UI_image_ID_type icon[GUI_CALENDAR_DETAIL_ENTRY_NUM];
    S32 border_gap = 2;
    U32 i;
    
    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;
    gui_calendar_struct* c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_calendar_pointer;
    MMI_DBG_ASSERT(c != NULL);

    /* Calculate the highlight cell's position. */
    gui_calendar_calculate_highlight_position(c, &highlight_row, &highlight_column);
    x1 = c->cell_array.x + (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_column;
    y1 = c->cell_array.y + (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_row;
    x2 = x1 + c->cell_array.cell_width - 1;
    y2 = y1 + c->cell_array.cell_height - 1;

    /* Set font of detail. */
    gui_set_font(c->detail.text_font);

    width = 0;
    height = 0;
    for (i = 0; i < GUI_CALENDAR_DETAIL_ENTRY_NUM; i++)
    {
        msg[i] = (UI_string_type)c->detail.detail_info.detail_list[i].string;
        icon[i] = c->detail.detail_info.detail_list[i].icon;
        w[i] = 0;
        h[i] = 0;
        icon_width[i] = 0;
        icon_height[i] = 0;
        if (msg[i] != NULL && UI_strlen((UI_string_type)(msg[i])) > 0)
        {
            gui_measure_string(msg[i], &w[i], &h[i]);
        }
        if (icon[i] != 0)
        {
            gdi_image_get_dimension_id((U16)icon[i], &icon_width[i], &icon_height[i]);
        }
        if (width < w[i] + icon_width[i])
        {
            width = w[i] + icon_width[i];
        }
#ifdef __MMI_MAINLCD_96X64__
        if (str_height < h[i] + icon_height[i])
        {
            str_height = h[i] + icon_height[i];
        }
#endif
        if (h[i] < icon_height[i])
        {
            h[i] = icon_height[i];
        }
        height += h[i] + border_gap;
    }
    if (width == 0)
    {
        c->detail.need_draw_detail = MMI_FALSE;
		return;
    }
    width += border_gap * 2;
#ifdef __MMI_MAINLCD_96X64__
    if (width > (GUI_CALENDAR_FRAME_WIDTH * 3 / c->column - 2))
    {
        width = GUI_CALENDAR_FRAME_WIDTH * 3 / c->column - 2;
    }
    if (height > 18)
    {
        height = 18;
    }
#else
    if (width > (GUI_CALENDAR_FRAME_WIDTH * (c->column - 1) / c->column))
    {
        width = GUI_CALENDAR_FRAME_WIDTH * (c->column - 1) / c->column;
    }
    if (height > (GUI_CALENDAR_FRAME_WIDTH * (c->row - 1) / c->row))
    {
        height = (GUI_CALENDAR_FRAME_WIDTH * (c->row - 1) / c->row);
    }
#endif
    /* Adjust position to avoid cover highlighted cell frame */
    /* x1 = c->cell_array.x + left_width - 1, if we count the pixel of x1 and c->cell_array.x in left_width
     * then, left_width =  (x1 - c->cell_array.x + 1 - 2) - GUI_CALENDAR_FRAME_LINE_PIXEL
     * here we do not count x1 and c->cell_array.x and GUI_CALENDAR_FRAME_LINE_PIXEL
     * so left_width = x1 - c->cell_array_x - 1 - GUI_CALENDAR_FRAME_LINE_PIXEL
     */
    left_width = x1 - c->cell_array.x - 1 - GUI_CALENDAR_FRAME_LINE_PIXEL;
    right_width = c->cell_array.x + c->cell_array.width - x2 - 2 - GUI_CALENDAR_FRAME_LINE_PIXEL;
    up_height = y1 - c->cell_array.y - 1 - GUI_CALENDAR_FRAME_LINE_PIXEL;
    down_height = c->cell_array.y + c->cell_array.height - y2 - 2 - GUI_CALENDAR_FRAME_LINE_PIXEL;
    left_width -= width;
    right_width -= width;
    up_height -= height;
    down_height -= height;
    /* Calculate the start position of detail. */
    {
        S32 temp_w, temp_h;
        temp_w = left_width > right_width ? left_width : right_width;
        temp_h = up_height > down_height ? up_height : down_height;
        if (temp_w > temp_h)
        {
            if (left_width > right_width)
            {
                detail_x1 = x1 - GUI_CALENDAR_FRAME_LINE_PIXEL - width;
                if (detail_x1 < c->cell_array.x)
                {
                    detail_x1 = c->cell_array.x;
                }
            }
            else
            {
                detail_x1 = x2 + 1 + GUI_CALENDAR_FRAME_LINE_PIXEL;
                if ((detail_x1 + width - 1) > (c->cell_array.x + c->cell_array.width - 1))
                {
                    detail_x1 = c->cell_array.x + c->cell_array.width - 1 - width;
                }
            }
            detail_y1 = y1;
            if ((detail_y1 + height - 1) > (c->cell_array.y + c->cell_array.height - 1))
            {
                detail_y1 = (c->cell_array.y + c->cell_array.height - 1) - height;
                if (detail_y1 < c->cell_array.y)
                {
                    detail_y1 = c->cell_array.y;
                }
            }
            
        }
        else
        {
            if (up_height > down_height)
            {
                detail_y1 = y1 - GUI_CALENDAR_FRAME_LINE_PIXEL - height;
                if (detail_y1 < c->cell_array.y)
                {
                    detail_y1 = c->cell_array.y;
                }
            }
            else
            {
                detail_y1 = y2 + 1 + GUI_CALENDAR_FRAME_LINE_PIXEL;
                if ((detail_y1 + height - 1) > (c->cell_array.y + c->cell_array.height - 1))
                {
                    detail_y1 = c->cell_array.y + c->cell_array.height - 1 - height;
                }
            }
            detail_x1 = x1;
            if ((detail_x1 + width - 1) > c->cell_array.x + c->cell_array.width - 1)
            {
                detail_x1 = (c->cell_array.x + c->cell_array.width - 1) - width;
                if (detail_x1 < c->cell_array.x)
                {
                    detail_x1 = c->cell_array.x;
                }
            }
        }       
    }
    
    detail_x2 = detail_x1 + width - 1;
    detail_y2 = detail_y1 + height - 1;

	if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        detail_x1 + c->x - layer_offset_x,
        detail_y1 + c->y - layer_offset_y,
        detail_x2 + c->x - layer_offset_x,
        detail_y2 + c->y - layer_offset_y);
    if(NULL != c->detail.detail_cache.buf_ptr)
    {
        gdi_image_cache_bmp_get(
            detail_x1 + c->x - layer_offset_x,
            detail_y1 + c->y - layer_offset_y,
            detail_x2 + c->x - layer_offset_x,
            detail_y2 + c->y - layer_offset_y,
            &c->detail.detail_cache);
    }
    c->detail.detail_is_shown = MMI_TRUE;
    c->detail.x = detail_x1;
    c->detail.y = detail_y1;
	c->detail.width = width;
	c->detail.height = height;
    detail_filler.c = c->detail.bg_color;
    detail_filler.border_color = c->detail.border_color;
    /* set text color */
    gui_set_text_color(c->detail.text_color);
#ifdef __MMI_MAINLCD_96X64__
    /* fill the color of popup */
    gdi_draw_rect(
        detail_x1 + c->x - layer_offset_x,
        detail_y1 + c->y - layer_offset_y,
        detail_x2 + c->x - layer_offset_x,
        detail_y2 + c->y - layer_offset_y,
        gdi_act_color_from_rgb(
            detail_filler.border_color.alpha,
            detail_filler.border_color.r,
            detail_filler.border_color.g,
            detail_filler.border_color.b));
    gui_draw_filled_area(
        detail_x1 + c->x - layer_offset_x,
        detail_y1 + c->y - layer_offset_y,
        detail_x2 + c->x - layer_offset_x,
        detail_y2 + c->y - layer_offset_y,
        (UI_filled_area*)&detail_filler);

    if(c->detail.text != NULL)
    {
        ASSERT(0);//this buffer should be free before this.
        //mmi_frm_scrmem_free(c->detail.text);
        //c->detail.text = NULL;
    }
    c->detail.text = mmi_frm_scrmem_alloc(GUI_CALENDAR_DETAIL_ENTRY_NUM * (GUI_CALENDAR_DETAIL_STRING_MAX_LENGTH + 1) * ENCODING_LENGTH + 1);;
    memset(c->detail.text, 0, GUI_CALENDAR_DETAIL_ENTRY_NUM * (GUI_CALENDAR_DETAIL_STRING_MAX_LENGTH + 1) * ENCODING_LENGTH + 1);
    for (i = 0; i < GUI_CALENDAR_DETAIL_ENTRY_NUM; i++)
    {
        if (msg[i] != NULL && UI_strlen((UI_string_type)(msg[i])) > 0)
        {
            UI_strcat(c->detail.text, msg[i]);
            UI_strcat(c->detail.text, L" ");
        }
    }   
    gui_create_scrolling_text(
        &c->detail.scrolling_detail,
        c->detail.x + border_gap + c->x - layer_offset_x,
        c->detail.y + ((c->detail.height - str_height)>>1) + c->y - layer_offset_y,
        c->detail.width - 2 * (border_gap) + c->x - layer_offset_x,
        c->detail.height - (c->detail.height - str_height) + c->y - layer_offset_y,
        (UI_string_type) c->detail.text,
        gui_calendar_scrolling_detail_text_handle,
        gui_calendar_scrolling_detail_text_redraw_bg,
        c->detail.text_color,
        c->detail.border_color);
    gui_show_scrolling_text(&c->detail.scrolling_detail);
#else
    /* fill the color of popup */
    gui_draw_filled_area(
        detail_x1 + c->x - layer_offset_x,
        detail_y1 + c->y - layer_offset_y,
        detail_x2 + c->x - layer_offset_x,
        detail_y2 + c->y - layer_offset_y,
        (UI_filled_area*)&detail_filler);
    y = detail_y1 + 3;
    for (i = 0; i < GUI_CALENDAR_DETAIL_ENTRY_NUM; i++)
    {
        if (h[i] > 0)
        {
            if (w[i] > 0)
            {
                if (w[i] + icon_width[i] > (width - 2 * border_gap))
                {
                    if (mmi_fe_get_r2l_state())
                    {
                        gui_print_truncated_text(
                            detail_x2 - border_gap - icon_width[i] + c->x - layer_offset_x,
                            y + c->y - layer_offset_y,
                            width - 2 * border_gap - icon_width[i],
                            msg[i]);   /* print bordered text on button */
                    }
                    else
                    {
                        gui_print_truncated_text(
                            detail_x1 + border_gap + icon_width[i] + c->x - layer_offset_x,
                            y + c->y - layer_offset_y,
                            width - 2 * border_gap - icon_width[i],
                            msg[i]);   /* print bordered text on button */
                    }
                }
                else
                {
                    if (mmi_fe_get_r2l_state())
                    {
                        gui_move_text_cursor(
                            detail_x2 - border_gap - icon_width[i] + c->x - layer_offset_x,
                            y + c->y - layer_offset_y);
                    }
                    else
                    {
                        gui_move_text_cursor(
                            detail_x1 + border_gap + icon_width[i] + c->x - layer_offset_x,
                            y + c->y - layer_offset_y);
                    }
                    gui_print_text(msg[i]);
                }
                if (icon_width[i] > 0)
                {
                    if (mmi_fe_get_r2l_state())
                    {
                        gdi_image_draw_id(
                            detail_x2 - border_gap - icon_width[i] + c->x - layer_offset_x,
                            y + c->y - layer_offset_y,
                            (U16)icon[i]);
                    }
                    else
                    {
                        gdi_image_draw_id(
                            detail_x1 + border_gap + c->x - layer_offset_x,
                            y + c->y - layer_offset_y,
                            (U16)icon[i]);
                    }
                }
                y += h[i] + 1;
            }
        }
    }
#endif
    gdi_layer_pop_clip();
    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_blt_previous(
        detail_x1 + c->x,
        detail_y1 + c->y,
        detail_x2 + c->x,
        detail_y2 + c->y);
#endif /*__MMI_CALENDAR_CHINESE_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_calculate_highlight_position
 * DESCRIPTION
 *  Calculate the highlight row and column number.
 * PARAMETERS
 *  c               [IN]        Is the calendar pointer.
 *  row             [IN/OUT]    Is the row number of highlight
 *  column          [IN/OUT]    Is the column number of highlight
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_calculate_highlight_position(
             gui_calendar_struct* c,
             U32 *row,
             U32 *column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    applib_time_struct inc, temp, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *row = 0;
    *column = 0;
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
        *column = c->highlight_time.DayIndex - c->start_time.DayIndex;
        if (!(c->flags & GUI_CALENDAR_SUNDAY_AS_BEGIN))
        {
            if (*column == (U32)-1)
            {
                *column += GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            }
        }
        memset(&inc, 0, sizeof(applib_time_struct));
        memset(&temp, 0, sizeof(applib_time_struct));
        memset(&result, 0, sizeof(applib_time_struct));

        inc.nDay = *column;
        temp = c->start_time;
        applib_dt_increase_time(
            &temp,
            &inc,
            &result);
        if (result.nYear == c->highlight_time.nYear &&
            result.nMonth == c->highlight_time.nMonth &&
            result.nDay == c->highlight_time.nDay)
        {
            *row = 0;
        }
        else
        {
            inc.nDay = c->column;
            for (i = 0; i < c->row; i++)
            {
                if (applib_dt_get_week_number(&c->highlight_time) !=
                    applib_dt_get_week_number(&temp))
                {
                    applib_dt_increase_time(
                        &temp,
                        &inc,
                        &result);
                    temp = result;
                }
                else
                {
                    break;
                }
            }
            *row = i;
            if (!(c->flags & GUI_CALENDAR_SUNDAY_AS_BEGIN))
            {
                if ((c->highlight_time.DayIndex) == (U8)GUI_CALENDAR_WEEK_DAY_SUNDAY)
                {
                    *row -= 1;
                }
            }
        }
    }
    else if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        *column = c->highlight_time.DayIndex - c->start_time.DayIndex;
        if (!(c->flags & GUI_CALENDAR_SUNDAY_AS_BEGIN))
        {
            if (*column == (U32)-1)
            {
                *column += GUI_CALENDAR_WEEK_DAY_OF_WEEK;
            }
        }
        *row = (c->highlight_time.nHour - c->start_time.nHour) / GUI_CALENDAR_WEEK_TIME_INTERVAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_highlight_cell
 * DESCRIPTION
 *  Highlight the cell.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_highlight_cell(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_cell_x, highlight_cell_y;
    S32 highlight_cell_width, highlight_cell_height;
    U32 highlight_row, highlight_column;

    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    /* Not show highlight of idle calendar. */
    if (c->flags & GUI_CALENDAR_WEEK_HIDE_CELL_ARRAY)
    {
        return;
    }

#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_FALSE)
    {
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

    /* Calculate the cell row and column of highlight. */
    gui_calendar_calculate_highlight_position(c, &highlight_row, &highlight_column);

    highlight_cell_width = c->cell_array.cell_width;
    highlight_cell_height = c->cell_array.cell_height;
    highlight_cell_x = c->cell_array.x + highlight_column * (highlight_cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL);
    highlight_cell_y = c->cell_array.y + highlight_row * (highlight_cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL);

    /* Adjust highlight field to include cell's frame line. */
#ifndef __MMI_FTE_SUPPORT__
    highlight_cell_x = highlight_cell_x - GUI_CALENDAR_FRAME_LINE_PIXEL;
    highlight_cell_y = highlight_cell_y - GUI_CALENDAR_FRAME_LINE_PIXEL;
    highlight_cell_width = highlight_cell_width + 2 * GUI_CALENDAR_FRAME_LINE_PIXEL;
    highlight_cell_height = highlight_cell_height + 2 * GUI_CALENDAR_FRAME_LINE_PIXEL;    
#endif
#ifdef __MMI_MAINLCD_96X64__
    highlight_cell_y = highlight_cell_y - highlight_row;
#endif
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        highlight_cell_x + c->x - layer_offset_x,
        highlight_cell_y + c->y - layer_offset_y,
        highlight_cell_x + highlight_cell_width - 1 + c->x - layer_offset_x,
        highlight_cell_y + highlight_cell_height - 1 + c->y - layer_offset_y);

    if(c->cell_array.cell_cache.buf_ptr != NULL)
    {
        gdi_image_cache_bmp_get(
            highlight_cell_x + c->x - layer_offset_x,
            highlight_cell_y + c->y - layer_offset_y,
            highlight_cell_x + highlight_cell_width - 1 + c->x - layer_offset_x,
            highlight_cell_y + highlight_cell_height - 1 + c->y - layer_offset_y,
            &(c->cell_array.cell_cache));
    }
    gdi_draw_rect(
        highlight_cell_x + c->x - layer_offset_x,
        highlight_cell_y + c->y - layer_offset_y,
        highlight_cell_x + highlight_cell_width - 1 + c->x - layer_offset_x,
        highlight_cell_y + highlight_cell_height - 1 + c->y - layer_offset_y,
        gdi_act_color_from_rgb(
            c->cell_array.cell_highlight_alpha,
            c->cell_array.cell_highlight.r,
            c->cell_array.cell_highlight.g,
            c->cell_array.cell_highlight.b));
    gdi_layer_pop_clip();
    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }

    gdi_layer_lock_frame_buffer();
    if (c->highlight_change_callback != NULL)
    {
        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
    }
    gdi_layer_unlock_frame_buffer();

#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

    /* Draw title and detail. */
    if(c->cell_detail_query_handler != NULL && c->title.text != NULL && c->detail.detail_info.detail_list != NULL)
    {
        S32 i;
       // MMI_DBG_ASSERT(c->title.text != NULL);
       // MMI_DBG_ASSERT(c->detail.detail_info.detail_list != NULL);
        memset(c->title.text, 0, (GUI_CALENDAR_TITLE_MAX_LENGTH + 1) * ENCODING_LENGTH);
        for (i = 0; i < GUI_CALENDAR_DETAIL_ENTRY_NUM; i++)
        {
            if (c->detail.detail_info.detail_list[i].string != NULL)
            {
                memset(c->detail.detail_info.detail_list[i].string, 0, (GUI_CALENDAR_DETAIL_STRING_MAX_LENGTH + 1) * ENCODING_LENGTH);
            }
        }
        c->cell_detail_query_handler(
            c->type,
            c->highlight_time,
            c->time_interval,
            c->title.text,
            GUI_CALENDAR_TITLE_MAX_LENGTH * ENCODING_LENGTH,
            &(c->detail.detail_info));

        gui_calendar_draw_title(c);
        /* Display detail. */
        if (c->detail.need_draw_detail == MMI_TRUE)
        {
            gui_cancel_timer(gui_calendar_draw_detail);
            c->detail.need_draw_detail = MMI_FALSE;
        }
    #ifdef __MMI_TOUCH_SCREEN__
        if (c->cell_array.pen_down_in_cell_array != TRUE)
        {
    #endif/* __MMI_TOUCH_SCREEN__ */
        c->detail.need_draw_detail = MMI_TRUE;
        gui_start_timer(GUI_CALENDAR_DETAIL_WAIT_TIME, gui_calendar_draw_detail);
    #ifdef __MMI_TOUCH_SCREEN__
        }
    #endif/* __MMI_TOUCH_SCREEN__ */
    }
	else
	{
		gui_calendar_draw_title(c);
	}
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_unhighlight_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                       [IN]         
 *  highlight_row         [IN]        
 *  highlight_column      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_unhighlight_cell(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_cell_x, highlight_cell_y;
    S32 highlight_cell_width, highlight_cell_height;
    U32 highlight_row, highlight_column;

    S32 layer_offset_x = 0, layer_offset_y = 0;
    gdi_handle active_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    if (c->is_on_idle == MMI_TRUE)
    {
        return;
    }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    /* Not show highlight of idle calendar. */
    if (c->flags & GUI_CALENDAR_WEEK_HIDE_CELL_ARRAY)
    {
        return;
    }

    if (c->detail.need_draw_detail == MMI_TRUE)
    {
        gui_cancel_timer(gui_calendar_draw_detail);
        c->detail.need_draw_detail = MMI_FALSE;
    }

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    /* Calculate the cell row and column of highlight. */
    gui_calendar_calculate_highlight_position(c, &highlight_row, &highlight_column);

    highlight_cell_width = c->cell_array.cell_width;
    highlight_cell_height = c->cell_array.cell_height;
    highlight_cell_x = c->cell_array.x + highlight_column * (highlight_cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL);
    highlight_cell_y = c->cell_array.y + highlight_row * (highlight_cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL);

    /* Adjust highlight field to include cell's frame line. */
#ifndef __MMI_FTE_SUPPORT__
    highlight_cell_x = highlight_cell_x - GUI_CALENDAR_FRAME_LINE_PIXEL;
    highlight_cell_y = highlight_cell_y - GUI_CALENDAR_FRAME_LINE_PIXEL;
    highlight_cell_width = highlight_cell_width + 2 * GUI_CALENDAR_FRAME_LINE_PIXEL;
    highlight_cell_height = highlight_cell_height + 2 * GUI_CALENDAR_FRAME_LINE_PIXEL;    
#endif
#ifdef __MMI_MAINLCD_96X64__
    highlight_cell_y = highlight_cell_y - highlight_row;
#endif    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->detail.x + c->x - layer_offset_x,
        c->detail.y + c->y - layer_offset_y,
        c->detail.x + c->detail.width - 1 + c->x - layer_offset_x,
        c->detail.y + c->detail.height - 1 + c->y - layer_offset_y);
    if (c->detail.detail_is_shown == MMI_TRUE)
    {
        #ifdef __MMI_MAINLCD_96X64__
	    gui_scrolling_text_stop(&c->detail.scrolling_detail);
        if(c->detail.text != NULL)
        {
            mmi_frm_scrmem_free(c->detail.text);
            c->detail.text = NULL;
        }
        #endif
        if(NULL != c->detail.detail_cache.buf_ptr)
        {
            gdi_image_cache_bmp_draw(
                c->detail.x + c->x - layer_offset_x,
                c->detail.y + c->y - layer_offset_y,
                &c->detail.detail_cache);
        }
        else
        {
            gui_calendar_draw_cell_array(c);
        }
        c->detail.detail_is_shown = MMI_FALSE;
    }
    gdi_layer_pop_clip();

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        highlight_cell_x + c->x - layer_offset_x,
        highlight_cell_y + c->y - layer_offset_y,
        highlight_cell_x + highlight_cell_width - 1 + c->x - layer_offset_x,
        highlight_cell_y + highlight_cell_height - 1 + c->y - layer_offset_y);
    if(c->cell_array.cell_cache.buf_ptr != NULL)
    {
        gdi_image_cache_bmp_draw(
            highlight_cell_x + c->x - layer_offset_x,
            highlight_cell_y + c->y - layer_offset_y,
            &c->cell_array.cell_cache);
    }
    else
    {
            gui_calendar_draw_cell_array(c);
    }
    gdi_layer_pop_clip();

    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_create
 * DESCRIPTION
 *  Initialize the settings of calendar
 * PARAMETERS
 *  c                   [IN]    Is the calendar pointer.
 *  type                [IN]    Is the type of calendar.
 *  max_date            [IN]    Is the max date calendar can display.
 *  min_date            [IN]    Is the min date calendar can display.
 *  show_date           [IN]    The display date of calendar.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_create(
      gui_calendar_struct *c,
      gui_calendar_type_enum type,
      applib_time_struct max_date,
      applib_time_struct min_date,
      applib_time_struct show_date,
      U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    MMI_DBG_ASSERT(type > GUI_CALENDAR_TYPE_MONTH &&
                   type < GUI_CALENDAR_TYPE_END);

    /* Check the time to display is valid or not. */
    MMI_DBG_ASSERT(applib_dt_is_valid(&max_date));
    MMI_DBG_ASSERT(applib_dt_is_valid(&min_date));
    MMI_DBG_ASSERT(applib_dt_is_valid(&show_date));

    c->type = type;
    c->max_time = max_date;
    c->min_time = min_date;
    c->highlight_time = show_date;
    c->flags = GUI_CALENDAR_SUNDAY_AS_BEGIN;
    if (flag & GUI_CALENDAR_MONDAY_AS_BEGIN)
    {
        c->flags = GUI_CALENDAR_MONDAY_AS_BEGIN;
    }
    c->vertical_select.align = GUI_CALENDAR_ALIGN_CELL;
    c->title.align = GUI_CALENDAR_ALIGN_CENTER;
    if (type == GUI_CALENDAR_TYPE_WEEK)
    {
        c->vertical_select.align = GUI_CALENDAR_ALIGN_LINE;
    }

    c->row = GUI_CALENDAR_CELL_ROW;
    c->column = GUI_CALENDAR_CELL_COLUMN;

    /* Arrange date information by calendar type. */
    gui_calendar_init_date(c);
    /* Set the defaule dimension information to calendar.  */
    gui_calendar_init_layout(c);
    gui_calendar_set_theme(c, current_UI_theme->calendar_theme);

    /* Init the member of calendar */
    c->target_layer = GDI_NULL_HANDLE;
    c->abm_layer = GDI_NULL_HANDLE;
    c->bg_id = 0;
#ifdef __MMI_TOUCH_SCREEN__
    c->pen_enable = MMI_FALSE;
#endif

    c->cell_data_query_handler = NULL;
    c->cell_detail_query_handler = NULL;
#ifdef __MMI_TOUCH_SCREEN__
    c->highlight_select_callback = NULL;
    c->highlight_change_callback = NULL;
#endif
    c->hide_callback = gui_calendar_default_hide_function;

#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    c->is_in_venus = MMI_FALSE;
    c->venus_update_screen_callback = NULL;
    c->venus_update_screen_handle = NULL;
    c->is_venus_update = MMI_FALSE;
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

    /* Malloc memory of cell cache */
    c->cell_array.cell_cache.buf_ptr = (U8*)mmi_frm_scrmem_alloc(GUI_CALENDAR_CACHE_CELL_SIZE);
    if (NULL != c->cell_array.cell_cache.buf_ptr)
    {
        memset(c->cell_array.cell_cache.buf_ptr, 0, GUI_CALENDAR_CACHE_CELL_SIZE);
    }
#ifdef __MMI_TOUCH_SCREEN__
    gui_calendar_set_pen_enable(c, MMI_TRUE);
#endif

    current_calendar_pointer = c;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_close
 * DESCRIPTION
 *  Close the calendar component.
 * PARAMETERS
 *  c       [IN]    Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_close(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->type = GUI_CALENDAR_TYPE_NONE;

    /* Cancel the detail timer. */
    if (c->detail.need_draw_detail == MMI_TRUE)
    {
        gui_cancel_timer(gui_calendar_draw_detail); /* stop the timer */
    }

    memset(&(c->min_time), 0, sizeof(applib_time_struct));
    memset(&(c->max_time), 0, sizeof(applib_time_struct));
    memset(&(c->time_interval), 0, sizeof(applib_time_struct));
    memset(&(c->highlight_time), 0, sizeof(applib_time_struct));
    c->flags = 0;

    c->target_layer = GDI_NULL_HANDLE;
    c->abm_layer = GDI_NULL_HANDLE;
    c->bg_id = 0;

#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    c->is_in_venus = MMI_FALSE;
    c->venus_update_screen_callback = NULL;
    c->venus_update_screen_handle = NULL;
    c->is_venus_update = MMI_FALSE;
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    c->is_on_idle = MMI_FALSE;
#endif

#ifdef __MMI_TOUCH_SCREEN__
    c->highlight_select_callback = NULL;
    c->pen_enable = MMI_FALSE;
#endif
    c->highlight_change_callback = NULL;

    c->cell_data_query_handler = NULL;
    c->cell_detail_query_handler = NULL;

    /* Recover the title init state. */
    /* Free the memory of title. */
    if (c->title.text != NULL)
    {
        mmi_frm_scrmem_free(c->title.text);
        c->title.text = NULL;
    }
#ifdef __MMI_TOUCH_SCREEN__
    c->title.prev_up_icon = NULL;
    c->title.prev_down_icon = NULL;
    c->title.prev_disable_icon = NULL;
    c->title.next_up_icon = NULL;
    c->title.next_down_icon = NULL;
    c->title.next_disable_icon = NULL;
    c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    c->title.pen_down_in_prev_button = 0;
    c->title.pen_down_in_next_button = 0;
#endif /* __MMI_TOUCH_SCREEN__ */
    c->title.align = GUI_CALENDAR_ALIGN_NONE;

    /* Recover the vertical select init state. */
#ifdef __MMI_TOUCH_SCREEN__
    c->vertical_select.prev_up_icon = NULL;
    c->vertical_select.prev_down_icon = NULL;
    c->vertical_select.prev_disable_icon = NULL;
    c->vertical_select.next_up_icon = NULL;
    c->vertical_select.next_down_icon = NULL;
    c->vertical_select.next_disable_icon = NULL;
    c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
    c->vertical_select.pen_down_in_prev_button = 0;
    c->vertical_select.pen_down_in_next_button = 0;
#endif /* __MMI_TOUCH_SCREEN__ */
    c->vertical_select.align = GUI_CALENDAR_ALIGN_NONE;

    /* Recover the cell array init state. */
    /* Free the memory of cell. */
    if (c->cell_array.cells != NULL)
    {
        mmi_frm_scrmem_free(c->cell_array.cells);
        c->cell_array.cells = NULL;
    }
    if (c->cell_array.cell_cache.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(c->cell_array.cell_cache.buf_ptr);
        c->cell_array.cell_cache.buf_ptr = NULL;
    }

#ifdef __MMI_CALENDAR_ENLARGE_CELL__
    if (c->cell_array.cell_enlarge_cache.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(c->cell_array.cell_enlarge_cache.buf_ptr);
        c->cell_array.cell_enlarge_cache.buf_ptr = NULL;
    }
    c->cell_array.cell_enlarge_is_shown = MMI_FALSE;
#endif /* __MMI_CALENDAR_ENLARGE_CELL__ */

    /* Recover the detail init state. */
    for (i = 0; i < GUI_CALENDAR_DETAIL_ENTRY_NUM; i++)
    {
        if (c->detail.detail_info.detail_list[i].string != NULL)
        {
            mmi_frm_scrmem_free(c->detail.detail_info.detail_list[i].string);
            c->detail.detail_info.detail_list[i].string = NULL;
        }
    }
    if (c->detail.detail_cache.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(c->detail.detail_cache.buf_ptr);
        c->detail.detail_cache.buf_ptr = NULL;
    }
    c->detail.detail_is_shown = MMI_FALSE;

	c->detail.width = 0;
	c->detail.height = 0;
    #ifdef __MMI_MAINLCD_96X64__
    gui_scrolling_text_stop(&c->detail.scrolling_detail);
    if(c->detail.text != NULL)
    {
        mmi_frm_scrmem_free(c->detail.text);
        c->detail.text = NULL;
    }
    gui_scrolling_text_stop(&c->title.scrolling_title);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_move
 * DESCRIPTION
 *  Changes the location of calendar.
 * PARAMETERS
 *  c       [IN]        Is the calendar pointer.
 *  x       [IN]        Is the new location of X direction.
 *  y       [IN]        Is the new location of Y direction.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_move(gui_calendar_struct *c, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    c->x = x;
    c->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_resize
 * DESCRIPTION
 *  Changes the dimension of calendar.
 * PARAMETERS
 *  c           [IN]    Is the calendar pointer.
 *  width       [IN]    Is the new width of calendar.
 *  height      [IN]    Is the new height of calendar.
 *  title_height[IN]    Is the new height of calendar title.
 *  cell_width  [IN]    Is the new width of calendar's every cell.
 *  cell_ehgith [IN]    Is the new height of calendar's every cell.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_resize(
      gui_calendar_struct *c,
      S32 width,
      S32 height,
      S32 title_height,
      S32 cell_width,
      S32 cell_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    c->width = width;
    c->height = height;

    c->title.height = title_height;
    c->cell_array.cell_width = cell_width;
    c->cell_array.cell_height = cell_height;
    gui_calendar_adjust_layout(c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_show
 * DESCRIPTION
 *  Display the calendar component.
 * PARAMETERS
 *  c       [IN]     Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_show(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->type == GUI_CALENDAR_TYPE_NONE || c->type == GUI_CALENDAR_TYPE_END)
    {
        return;
    }

    /* Draw calendar's Frame. */
    gui_calendar_draw_bg(c, c->x, c->y, c->width, c->height);
    if (c->bg_image == NULL)
    {
#ifndef __MMI_MAINLCD_96X64__
        gui_calendar_draw_bg_frame(c);
#endif
    }
    
    /* Query the data from calendar. */
    gui_calendar_query_cell_data(c);
#ifdef __MMI_TOUCH_SCREEN__
    gui_calendar_adjust_switch_enable_state(c);
#endif

    gui_calendar_draw_cell_array(c);

    gui_calendar_draw_horizontal_string(c);
    gui_calendar_draw_vertical_select(c);
    gui_calendar_highlight_cell(c);
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_pen_enable
 * DESCRIPTION
 *  Set calendar's pen enable state. If it is MMI_TRUE, calendar will response
 *  to pen event.
 *  Remark: If pen is enable and calendar in not in idlse screen, we will malloc
 *          the memory of cell cache. If it is a FTE project, we will also malloc
 *          the memory of enlarge cell cache.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 *  is_pen_enable   [IN]    Is the pen enable state.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_pen_enable(gui_calendar_struct* c, MMI_BOOL is_pen_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->pen_enable != is_pen_enable)
    {
	#ifdef __MMI_CALENDAR_ENLARGE_CELL__
        if (c->pen_enable == MMI_TRUE)
        {
            /* Free the memory of enlarge cell. */
            if (c->cell_array.cell_enlarge_cache.buf_ptr != NULL)
            {
                mmi_frm_scrmem_free(c->cell_array.cell_enlarge_cache.buf_ptr);
                c->cell_array.cell_enlarge_cache.buf_ptr = NULL;
            }
        }
        else
        {
            /* Malloc the memory of enlarge cell. */
            if (c->type == GUI_CALENDAR_TYPE_MONTH &&
				c->cell_array.cell_enlarge_cache.buf_ptr == NULL)
            {
                c->cell_array.cell_enlarge_cache.buf_ptr = 
                    (U8*)mmi_frm_scrmem_alloc(GUI_CALENDAR_CACHE_CELL_ENLARGE_SIZE);
				// Follow memset is for test //
				if(NULL != c->cell_array.cell_enlarge_cache.buf_ptr)
				{
				    memset(c->cell_array.cell_enlarge_cache.buf_ptr, 0, GUI_CALENDAR_CACHE_CELL_ENLARGE_SIZE);
				}
                // Above memset is for test //
            }
        }
    #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
	    c->pen_enable = is_pen_enable;
		if (c->type == GUI_CALENDAR_TYPE_WEEK)
		{
			if (c->pen_enable == MMI_TRUE)
			{
			#ifdef __MMI_CALENDAR__
				c->vertical_select.prev_up_icon = get_image(CAL_UP_ARROW_UP_IMAGE);
				c->vertical_select.prev_down_icon = get_image(CAL_UP_ARROW_DOWN_IMAGE);
				c->vertical_select.next_up_icon = get_image(CAL_DOWN_ARROW_UP_IMAGE);
				c->vertical_select.next_down_icon = get_image(CAL_DOWN_ARROW_DOWN_IMAGE);
                #ifdef __MMI_CLNDR_FTE_SLIM_RES__
                c->vertical_select.prev_disable_icon = get_image(CAL_UP_ARROW_UP_IMAGE);
                c->vertical_select.next_disable_icon = get_image(CAL_DOWN_ARROW_UP_IMAGE);
                #else
                c->vertical_select.prev_disable_icon = get_image(CAL_UP_ARROW_DISABLE_IMAGE);
                c->vertical_select.next_disable_icon = get_image(CAL_DOWN_ARROW_DISABLE_IMAGE);
                #endif
            #endif /* __MMI_CALENDAR__ */
				c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                #ifdef __MMI_CLNDR_FTE_SLIM_RES__
                gdi_image_get_dimension_id(
					CAL_UP_ARROW_BG_9SLICE_IMAGE,
					&(c->vertical_select.prev_icon_width),
					&(c->vertical_select.prev_icon_height));
                #ifdef __MMI_CLNDR_240X320_LARGE_FONT_SUPPORT__
                c->vertical_select.prev_icon_height -= 4;
                #endif /* __MMI_CLNDR_240X320_LARGE_FONT_SUPPORT__ */
                c->vertical_select.prev_icon_width = c->vertical_select.width;
                c->vertical_select.next_icon_height = c->vertical_select.prev_icon_height;
                c->vertical_select.next_icon_width= c->vertical_select.width;
                #else /* __MMI_CLNDR_FTE_SLIM_RES__ */
				gdi_image_get_dimension(
					c->vertical_select.prev_up_icon,
					&(c->vertical_select.prev_icon_width),
					&(c->vertical_select.prev_icon_height));
				gdi_image_get_dimension(
					c->vertical_select.next_up_icon,
					&(c->vertical_select.next_icon_width),
					&(c->vertical_select.next_icon_height));
                #endif
			}
			else
			{
				//c->vertical_select.prev_up_icon = NULL;
				//c->vertical_select.prev_down_icon = NULL;
                //c->vertical_select.prev_disable_icon = NULL;
				//c->vertical_select.next_up_icon = NULL;
				//c->vertical_select.next_down_icon = NULL;
                //c->vertical_select.next_disable_icon = NULL;
				c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
                c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
			}
		}
#ifdef __MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__
		if (!(c->flags & GUI_CALENDAR_DISABLE_PREV_NEXT_SWITCH))
		{
        #ifdef __MMI_FTE_SUPPORT__
            c->title.prev_up_icon = get_image(MENSTURAL_LEFT_ARROW_UP_IMAGE);
        	c->title.prev_down_icon = get_image(MENSTURAL_LEFT_ARROW_DOWN_IMAGE);
        	c->title.prev_disable_icon = get_image(MENSTURAL_LEFT_ARROW_DISABLE_IMAGE);
            c->title.next_up_icon = get_image(MENSTURAL_RIGHT_ARROW_UP_IMAGE);
        	c->title.next_down_icon = get_image(MENSTURAL_RIGHT_ARROW_DOWN_IMAGE);
        	c->title.next_disable_icon = get_image(MENSTURAL_RIGHT_ARROW_DISABLE_IMAGE);
        #else
        	c->title.prev_up_icon = get_image(CAL_LEFT_ARROW_UP_IMAGE);
        	c->title.prev_down_icon = get_image(CAL_LEFT_ARROW_DOWN_IMAGE);
        	c->title.prev_disable_icon = get_image(CAL_LEFT_ARROW_DISABLE_IMAGE);
            c->title.next_up_icon = get_image(CAL_RIGHT_ARROW_UP_IMAGE);
        	c->title.next_down_icon = get_image(CAL_RIGHT_ARROW_DOWN_IMAGE);
        	c->title.next_disable_icon = get_image(CAL_RIGHT_ARROW_DISABLE_IMAGE);
        #endif /* __MMI_CALENDAR__ */
        	c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            gdi_image_get_dimension(
                c->title.prev_up_icon,
                &(c->title.prev_icon_width),
                &(c->title.prev_icon_height));
            gdi_image_get_dimension(
                c->title.next_up_icon,
                &(c->title.next_icon_width),
                &(c->title.next_icon_height));
		}
		else
		{
            c->title.prev_up_icon = NULL;
            c->title.prev_down_icon = NULL;
            c->title.prev_disable_icon = NULL;
            c->title.next_up_icon = NULL;
            c->title.next_down_icon = NULL;
            c->title.next_disable_icon = NULL;
            c->title.prev_icon_x = c->title.prev_icon_y = 0;
            c->title.prev_icon_width = c->title.prev_icon_height = 0;
            c->title.next_icon_x = c->title.next_icon_y = 0;
            c->title.next_icon_width = c->title.next_icon_height = 0;
            c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
            c->title.next_button_state = GUI_CALENDAR_PEN_STATE_DISABLED;
            c->title.pen_down_in_prev_button = 0;
            c->title.pen_down_in_next_button = 0;
		}
#endif
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c           [IN]         
 *  bg_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_bg(gui_calendar_struct* c, UI_image_ID_type bg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->bg_id = bg_id;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_target_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  target_layer    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_target_layer(gui_calendar_struct* c, GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_target_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  abm_layer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_abm_layer(gui_calendar_struct* c, GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->abm_layer = abm_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_cell_data_query_handler
 * DESCRIPTION
 *  Set the query handler of cell data.
 * PARAMETERS
 *  c                           [IN]    Is the calendar pointer.
 *  cell_data_query_handler     [IN]    Is the query handler of cell data.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_cell_data_query_handler(
      gui_calendar_struct* c,
      S32 (*cell_data_query_handler) (
            gui_calendar_type_enum type,
            applib_time_struct start_time,
            applib_time_struct end_time,
            applib_time_struct interval,
            S32 cell_count,
            gui_calendar_cell_struct *cells))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    MMI_DBG_ASSERT(cell_data_query_handler != NULL);
    
    c->cell_data_query_handler = cell_data_query_handler;
    /* Malloc the memory of cells */
    gui_calendar_malloc_cell_data_buffer(c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_cell_detail_query_handler
 * DESCRIPTION
 *  Set the query handler of cell detail.
 * PARAMETERS
 *  c                           [IN]    Is the calendar pointer.
 *  cell_detail_query_handler   [IN]    Is the query handler of cell detail.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_cell_detail_query_handler(
      gui_calendar_struct* c,
      S32 (*cell_detail_query_handler) (
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
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    MMI_DBG_ASSERT(cell_detail_query_handler != NULL);
    
    c->cell_detail_query_handler = cell_detail_query_handler;
    /* Malloc the memory of title */
    if (c->title.text == NULL)
    {
        c->title.text = 
            (U8*)mmi_frm_scrmem_alloc((GUI_CALENDAR_TITLE_MAX_LENGTH + 1) * ENCODING_LENGTH);
		// Follow memset is for test //
		if(c->title.text != NULL)
		{
            memset(c->title.text, 0, (GUI_CALENDAR_TITLE_MAX_LENGTH + 1) * ENCODING_LENGTH);
		}
        // Above memset is for test //
    }

    /* Malloc the memory of detail info. */
    for (i = 0; i < GUI_CALENDAR_DETAIL_ENTRY_NUM; i++)
    {
        if (c->detail.detail_info.detail_list[i].string == NULL)
        {
            c->detail.detail_info.detail_list[i].string =
                (U8*)mmi_frm_scrmem_alloc((GUI_CALENDAR_DETAIL_STRING_MAX_LENGTH + 1) * ENCODING_LENGTH);
			// Follow memset is for test //
			if(c->detail.detail_info.detail_list[i].string != NULL)
			{
                memset(c->detail.detail_info.detail_list[i].string, 0, (GUI_CALENDAR_DETAIL_STRING_MAX_LENGTH + 1) * ENCODING_LENGTH);
			}
            // Above memset is for test //
        }
    }
    c->detail.detail_info.detail_string_max_length = GUI_CALENDAR_DETAIL_STRING_MAX_LENGTH;
    c->detail.detail_info.detail_entry_number = GUI_CALENDAR_DETAIL_ENTRY_NUM;
    if (c->detail.detail_cache.buf_ptr == NULL)
    {
        c->detail.detail_cache.buf_ptr =
            (U8*)mmi_frm_scrmem_alloc(GUI_CALENDAR_CACHE_DETAIL_SIZE);
		// Follow memset is for test //
		if(c->detail.detail_cache.buf_ptr != NULL)
		{
            memset(c->detail.detail_cache.buf_ptr, 0, GUI_CALENDAR_CACHE_DETAIL_SIZE);
		}
        // Above memset is for test //
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_hide_function
 * DESCRIPTION
 *  Set the hide callback function of the calendar.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 *  f               [IN]    Is the new hide callback function.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_hide_function(
      gui_calendar_struct *c,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->hide_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_highlight_change_function
 * DESCRIPTION
 *  Set the highlight move callback function of the calendar.
 * REMARK:
 *  In fact the start_time and end_time in this API is useless in current calendar
 *  component's design. We add this two parameter only is to map the current calendar
 *  App. We advise calendar App to revise their code in the future. We will remove 
 *  start_time and end_time in that time.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 *  f               [IN]    Is the hide select callback function.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_highlight_change_function(
      gui_calendar_struct *c,
      void (*highlight_change_callback)(
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
    MMI_DBG_ASSERT(c != NULL);

    c->highlight_change_callback = highlight_change_callback;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_highlight_select_function
 * DESCRIPTION
 *  Set the highlight select callback function of the calendar.
 * PARAMETERS
 *  c               [IN]    Is the calendar pointer.
 *  f               [IN]    Is the hide select callback function.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_highlight_select_function(
      gui_calendar_struct *c,
      void (*highlight_select_callback)(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->highlight_select_callback = highlight_select_callback;
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  x               [IN]        
 *  y               [IN]        
 *  pen_row         [IN]         
 *  pen_column      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_translate_pen_position(
             gui_calendar_struct* c,
             S32 x,
             S32 y,
             U32* pen_row,
             U32* pen_column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if ((x - c->cell_array.x + 1) % (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) != 0)
    {
        *pen_column = (x - c->cell_array.x + 1) / (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL);
    }

    if ((y - c->cell_array.y + 1) % (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) != 0)
    {
        *pen_row = (y - c->cell_array.y + 1) / (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_redraw_vertical_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  func            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_redraw_vertical_select(
             gui_calendar_struct* c,
             void func(gui_calendar_struct* c, gui_calendar_time_switch_enum type))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if(func)
    {
        func(c, GUI_CALENDAR_TIME_SWITCH_SINGLE_PERIOD);
    }
    gui_calendar_draw_vertical_select(c);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        c->x + c->vertical_select.x,
        c->y + c->vertical_select.y,
        c->x + c->vertical_select.x + c->vertical_select.width - 1,
        c->y + c->vertical_select.y + c->vertical_select.height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_is_vertical_select_prev_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  pos            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL gui_calendar_is_vertical_select_prev_icon(
             gui_calendar_struct* c,
             mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->vertical_select.prev_icon_x,
                c->y + c->vertical_select.prev_icon_y,
                c->vertical_select.prev_icon_width,
                c->vertical_select.prev_icon_height);
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_is_vertical_select_next_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  pos            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL gui_calendar_is_vertical_select_next_icon(
             gui_calendar_struct* c,
             mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->vertical_select.next_icon_x,
                c->y + c->vertical_select.next_icon_y,
                c->vertical_select.next_icon_width,
                c->vertical_select.next_icon_height);
}

/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenDownHandler(
                 gui_calendar_struct* c,
                 mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
	if (!PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            c->x,
            c->y,
            c->width,
            c->height))
	{
		return MMI_FALSE;
	}
    
    /* Vertical select. */
    /*if (PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            c->x + c->vertical_select.x,
            c->y + c->vertical_select.y,
            c->vertical_select.width,
            c->vertical_select.height))*/
    {
        /* Prev arrow. */
        if (gui_calendar_is_vertical_select_prev_icon(
                c,
                pos))
        {
            if (c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                return MMI_FALSE;
            }
            c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_DOWN;
            gui_calendar_redraw_vertical_select(
                c,
                NULL);
            c->vertical_select.pen_down_in_prev_button = TRUE;
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }

        /* Bottom arrow */
        if (gui_calendar_is_vertical_select_next_icon(
                c,
                pos))
        {
            if (c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                return MMI_FALSE;
            }
            c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_DOWN;
            gui_calendar_redraw_vertical_select(
                c,
                NULL);
            c->vertical_select.pen_down_in_next_button = TRUE;
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }
    }
#ifdef __MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__
    /* Title */
    if (PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            c->x + c->title.x,
            c->y + c->title.y,
            c->title.width,
            c->title.height))
    {
        /* Prev arrow */
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->title.x + c->title.prev_icon_x,
                c->y + c->title.y + c->title.prev_icon_y,
                c->title.prev_icon_width,
                c->title.prev_icon_height))
        {
			if (c->title.prev_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                return MMI_FALSE;
            }
            gdi_layer_lock_frame_buffer();
            c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_DOWN;
            gui_calendar_draw_title(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->x + c->title.x,
                c->y + c->title.y,
                c->x + c->title.x + c->title.width - 1,
                c->y + c->title.y + c->title.height - 1);
            c->title.pen_down_in_prev_button = TRUE;
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }

        /* Next arrow */
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->title.x + c->title.next_icon_x,
                c->y + c->title.y + c->title.next_icon_y,
                c->title.next_icon_width,
                c->title.next_icon_height))
        {
			if (c->title.next_button_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                return MMI_FALSE;
            }
            gdi_layer_lock_frame_buffer();
            c->title.next_button_state = GUI_CALENDAR_PEN_STATE_DOWN;
            gui_calendar_draw_title(c);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->x + c->title.x,
                c->y + c->title.y,
                c->x + c->title.x + c->title.width - 1,
                c->y + c->title.y + c->title.height - 1);
            c->title.pen_down_in_next_button = TRUE;
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }
    }
#endif
    /* Cell array */
    if (PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            c->x + c->cell_array.x,
            c->y + c->cell_array.y,
            c->cell_array.width,
            c->cell_array.height))
    {
        U32 pen_row = 0xffffffff, pen_column = 0xffffffff;
        U32 highlight_row = 0xffffffff, highlight_column = 0xffffffff;

        gui_calendar_translate_pen_position(
            c,
            pos.x - c->x,
            pos.y - c->y,
            &pen_row,
            &pen_column);

        if (pen_row >= c->row || pen_column >= c->column)
        {
            return MMI_FALSE;
        }

        gui_calendar_calculate_highlight_position(
            c,
            &highlight_row,
            &highlight_column);

        if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
        {
            applib_time_struct temp;
            MMI_BOOL is_valid;
            gui_calendar_get_time(c, pen_row, pen_column, &temp, &is_valid);

            if ((highlight_row == pen_row) && (highlight_column == pen_column))
            {
                c->cell_array.pen_on_highlight = TRUE;
            #ifdef __MMI_CALENDAR_ENLARGE_CELL__
                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    gui_calendar_unhighlight_cell(c);
                    gdi_layer_lock_frame_buffer();
                    gui_calendar_enlarge_cell(c);
                    gdi_layer_blt_previous(
			        c->cell_array.cell_enlarge_cache_x + c->x,
			        c->cell_array.cell_enlarge_cache_y + c->y,
			        c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
			        c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
                    gdi_layer_unlock_frame_buffer();
                    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                }
            #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
            }
            else if(is_valid == MMI_TRUE)
            {
                gui_calendar_unhighlight_cell(c);
                c->highlight_time = temp;
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
            #ifdef __MMI_CALENDAR_ENLARGE_CELL__
                if (c->type == GUI_CALENDAR_TYPE_MONTH)
                {
                    gdi_layer_lock_frame_buffer();
                    gui_calendar_enlarge_cell(c);
	            gdi_layer_blt_previous(
    			c->cell_array.cell_enlarge_cache_x + c->x,
    			c->cell_array.cell_enlarge_cache_y + c->y,
    			c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
    			c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
    		    gdi_layer_unlock_frame_buffer();
                }
                else
                {
                    gui_calendar_highlight_cell(c);
                }
            #else /* __MMI_CALENDAR_ENLARGE_CELL__ */
                gui_calendar_highlight_cell(c);
            #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
                gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
        }
        c->cell_array.pen_down_in_cell_array = TRUE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenUpHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenUpHandler(gui_calendar_struct* c, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if (c->cell_array.pen_down_in_cell_array == TRUE)
    {
        U32 highlight_row, highlight_column;
        U32 pen_row = 0xffffffff, pen_column = 0xffffffff;
        applib_time_struct temp = c->highlight_time;
        MMI_BOOL is_valid = MMI_FALSE;

        gui_calendar_calculate_highlight_position(c, &highlight_row, &highlight_column);
        gui_calendar_translate_pen_position(c, pos.x - c->x, pos.y - c->y, &pen_row, &pen_column);
        if (!(pen_row >= c->row || pen_column >= c->column))
        {
            gui_calendar_get_time(c, pen_row, pen_column, &temp, &is_valid);
        }

        c->cell_array.pen_down_in_cell_array = FALSE;
    #ifdef __MMI_CALENDAR_ENLARGE_CELL__
        /* Pen is in the area of cell enlarge icon, not handle it. */
        if ((c->type == GUI_CALENDAR_TYPE_MONTH) &&
            (c->cell_array.cell_enlarge_is_shown == MMI_TRUE) &&
            (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->cell_array.cell_enlarge_cache_x,
                c->y + c->cell_array.cell_enlarge_cache_y,
                c->cell_array.cell_enlarge_cache_width,
                c->cell_array.cell_enlarge_cache_height) ||
            PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->cell_array.x + (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_column,
                c->y + c->cell_array.y + (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_row,
                c->cell_array.cell_width,
                c->cell_array.cell_height)))
        {
            gdi_layer_lock_frame_buffer();
            gui_calendar_recover_enlarge_cell(c);
	        gdi_layer_blt_previous(
		        c->cell_array.cell_enlarge_cache_x + c->x,
		        c->cell_array.cell_enlarge_cache_y + c->y,
		        c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
		        c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
	        gdi_layer_unlock_frame_buffer();
            /* we need set highlight_row_old to a value not equal highlight_row */
            if (is_valid == MMI_TRUE)
            {
                c->highlight_time = temp;
                /* Let category and App adjust the highlight time */
                gdi_layer_lock_frame_buffer();
                if (c->highlight_change_callback != NULL)
                {
                    c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                }
                gdi_layer_unlock_frame_buffer();
            }
            gui_calendar_highlight_cell(c);
            gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            if (c->cell_array.pen_on_highlight == TRUE)
            {
                c->cell_array.pen_on_highlight = FALSE;
                if (c->highlight_select_callback != NULL)
                {
                    c->highlight_select_callback(c->type, temp);
                }
            }
            return MMI_TRUE;
        }
    #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */

        /* cell array */
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->cell_array.x,
                c->y + c->cell_array.y,
                c->cell_array.width,
                c->cell_array.height))
        {
            if (pen_row >= c->row || pen_column >= c->column)
            {
            #ifdef __MMI_CALENDAR_ENLARGE_CELL__
                if ((c->type == GUI_CALENDAR_TYPE_MONTH) &&
                    (c->cell_array.cell_enlarge_is_shown == MMI_TRUE))
                {
                    gdi_layer_lock_frame_buffer();
                    gui_calendar_recover_enlarge_cell(c);
        		    gdi_layer_blt_previous(
        			c->cell_array.cell_enlarge_cache_x + c->x,
        			c->cell_array.cell_enlarge_cache_y + c->y,
        			c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
        			c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
        		    gdi_layer_unlock_frame_buffer();
                    /* we need set highlight_row_old to a value not equal highlight_row */
                    if (is_valid == MMI_TRUE)
                    {
                        c->highlight_time = temp;
                    }
                    gui_calendar_highlight_cell(c);
                    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                }
            #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
                return MMI_FALSE;
            }

            if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
            {
                if ((highlight_row == pen_row) && (highlight_column == pen_column))
                {
                    if (c->cell_array.pen_on_highlight == TRUE)
                    {
                        c->cell_array.pen_on_highlight = FALSE;
                        if (c->highlight_select_callback != NULL)
                        {
                            c->highlight_select_callback(c->type, temp);
                        }
                    }
                }
            #ifdef __MMI_CALENDAR_ENLARGE_CELL__
                else
                {
                    if (c->cell_array.cell_enlarge_is_shown == MMI_TRUE)
                    {
                        gdi_layer_lock_frame_buffer();
                        gui_calendar_recover_enlarge_cell(c);
                        gdi_layer_blt_previous(
			                c->cell_array.cell_enlarge_cache_x + c->x,
			                c->cell_array.cell_enlarge_cache_y + c->y,
			                c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
			                c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
		                    gdi_layer_unlock_frame_buffer();
                    }
                    else
                    {
                        gui_calendar_unhighlight_cell(c);
                    }
                    gui_calendar_highlight_cell(c);
                    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                }
            #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
            }
        }
    #ifdef __MMI_CALENDAR_ENLARGE_CELL__
        else
        {
            gui_calendar_unhighlight_cell(c);
            gui_calendar_highlight_cell(c);
            gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
        }
    #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
    }

    /* vertical select */
    if (c->vertical_select.pen_down_in_prev_button == TRUE)
    {
        if (gui_calendar_is_vertical_select_prev_icon(
                c,
                pos))
        {
            if (c->vertical_select.prev_button_state != GUI_CALENDAR_PEN_STATE_DOWN)
            {
                c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                gui_calendar_redraw_vertical_select(
                    c,
                    NULL);

            }
            else
            {
                c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                gui_calendar_redraw_vertical_select(
                    c,
                    gui_calendar_switch_prev);

            }
        }
        else
        {
            c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            gui_calendar_redraw_vertical_select(
                    c,
                    NULL);
        }
        //c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        c->vertical_select.pen_down_in_prev_button = FALSE;
    }
    if (c->vertical_select.pen_down_in_next_button == TRUE)
    {
        if (gui_calendar_is_vertical_select_next_icon(
                c,
                pos))
        {
            if (c->vertical_select.next_button_state != GUI_CALENDAR_PEN_STATE_DOWN)
            {
                c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                gui_calendar_redraw_vertical_select(
                    c,
                    NULL);
            }
            else
            {
                c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
		        gui_calendar_redraw_vertical_select(
                    c,
                    gui_calendar_switch_next);
            }
        }
        else
        {
            c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            gui_calendar_redraw_vertical_select(
                    c,
                    NULL);
        }
        //c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        c->vertical_select.pen_down_in_next_button = FALSE;
    }

#ifdef __MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__
    /* Title */
    if (c->title.pen_down_in_prev_button == TRUE)
    {
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->title.x + c->title.prev_icon_x,
                c->y + c->title.y + c->title.prev_icon_y,
                c->title.prev_icon_width,
                c->title.prev_icon_height))
        {
            if (c->title.prev_button_state != GUI_CALENDAR_PEN_STATE_DOWN)
            {
                c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                gdi_layer_lock_frame_buffer();
                gui_calendar_draw_title(c);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_blt_previous(
                    c->x + c->title.x,
                    c->y + c->title.y,
                    c->x + c->title.x + c->title.width - 1,
                    c->y + c->title.y + c->title.height - 1);
            }
            else
            {
                c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                gdi_layer_lock_frame_buffer();
                gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_UP);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_blt_previous(
                    c->x + c->title.x,
                    c->y + c->title.y,
                    c->x + c->title.x + c->title.width - 1,
                    c->y + c->title.y + c->title.height - 1);
            }
        }
        else
        {
            c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            gdi_layer_lock_frame_buffer();
            gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_UP);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->x + c->title.x,
                c->y + c->title.y,
                c->x + c->title.x + c->title.width - 1,
                c->y + c->title.y + c->title.height - 1);
        }
        c->title.pen_down_in_prev_button = FALSE;
    }
    if (c->title.pen_down_in_next_button == TRUE)
    {
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->title.x + c->title.next_icon_x,
                c->y + c->title.y + c->title.next_icon_y,
                c->title.next_icon_width,
                c->title.next_icon_height))
        {
            if (c->title.next_button_state != GUI_CALENDAR_PEN_STATE_DOWN)
            {
                c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                gdi_layer_lock_frame_buffer();
                gui_calendar_draw_title(c);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_blt_previous(
                    c->x + c->title.x,
                    c->y + c->title.y,
                    c->x + c->title.x + c->title.width - 1,
                    c->y + c->title.y + c->title.height - 1);
            }
            else
            {
                c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
				gdi_layer_lock_frame_buffer();
                gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_DOWN);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_blt_previous(
                    c->x + c->title.x,
                    c->y + c->title.y,
                    c->x + c->title.x + c->title.width - 1,
                    c->y + c->title.y + c->title.height - 1);
            }
        }
        else
        {
            c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            gdi_layer_lock_frame_buffer();
            gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_DOWN);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(
                c->x + c->title.x,
                c->y + c->title.y,
                c->x + c->title.x + c->title.width - 1,
                c->y + c->title.y + c->title.height - 1);
        }
        c->title.pen_down_in_next_button = FALSE;
    }
#endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenMoveHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenMoveHandler(gui_calendar_struct* c, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->cell_array.pen_down_in_cell_array == TRUE)
    {
        U32 highlight_row, highlight_column;
        U32 pen_row = 0xffffffff, pen_column = 0xffffffff;
        applib_time_struct temp = c->highlight_time;
        MMI_BOOL is_valid = MMI_FALSE;

        gui_calendar_calculate_highlight_position(c, &highlight_row, &highlight_column);
        gui_calendar_translate_pen_position(c, pos.x - c->x, pos.y - c->y, &pen_row, &pen_column);
        if (!(pen_row >= c->row || pen_column >= c->column))
        {
            gui_calendar_get_time(c, pen_row, pen_column, &temp, &is_valid);
        }
    #ifdef __MMI_CALENDAR_ENLARGE_CELL__
    /* Pen is in the area of hignlight cell and its enlarge icon, not handle it. */
        if ((c->type == GUI_CALENDAR_TYPE_MONTH) &&
            (c->cell_array.cell_enlarge_is_shown == MMI_TRUE))
        {
            if (PEN_CHECK_BOUND(
                    pos.x,
                    pos.y,
                    c->x + c->cell_array.x + (c->cell_array.cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_column,
                    c->y + c->cell_array.y + (c->cell_array.cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_row,
                    c->cell_array.cell_width,
                    c->cell_array.cell_height))
            {
                return result;
            }
            else
            {
                c->cell_array.pen_on_highlight = FALSE;
            }
        }

        if (c->type == GUI_CALENDAR_TYPE_MONTH)
        {
            if (PEN_CHECK_BOUND(
                    pos.x,
                    pos.y,
                    c->x + c->cell_array.x,
                    c->y + c->cell_array.y,
                    c->cell_array.width,
                    c->cell_array.height))
            {
                if (pen_row >= c->row || pen_column >= c->column)
                {                
                    return result;
                }

                /* Pen move to another cell */
                if (c->cell_array.cell_enlarge_is_shown == MMI_TRUE)
                {
                    /* Pen move to another valid cell */
                    if(is_valid == MMI_TRUE)
                    {
                        /* change highlight to the new cell */
			            gdi_layer_lock_frame_buffer();
                        gui_calendar_recover_enlarge_cell(c);
            			gdi_layer_blt_previous(
            			    c->cell_array.cell_enlarge_cache_x + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->y,
            			    c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
            			gdi_layer_unlock_frame_buffer();
                        c->highlight_time = temp;
                        gdi_layer_lock_frame_buffer();
                        gui_calendar_enlarge_cell(c);
            			gdi_layer_blt_previous(
            			    c->cell_array.cell_enlarge_cache_x + c->x,
            		        c->cell_array.cell_enlarge_cache_y + c->y,
            			    c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
            			gdi_layer_unlock_frame_buffer();
                        c->cell_array.pen_on_highlight = FALSE;
                    }
                    else /* Pen move to invalid cell, highlight the cell */
                    {
                        gdi_layer_lock_frame_buffer();
                        gui_calendar_recover_enlarge_cell(c);
            			gdi_layer_blt_previous(
            			    c->cell_array.cell_enlarge_cache_x + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->y,
            			    c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
            			gdi_layer_unlock_frame_buffer();
                        gui_calendar_highlight_cell(c);
                    }
                    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                }
                else
                {
                    /* Pen move to valid cell */
                    if(is_valid == MMI_TRUE)
                    {
                        gui_calendar_unhighlight_cell(c);
                        c->highlight_time = temp;
                        gdi_layer_lock_frame_buffer();
                        gui_calendar_enlarge_cell(c);
            			gdi_layer_blt_previous(
            			    c->cell_array.cell_enlarge_cache_x + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->y,
            			    c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
            			    c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
            			gdi_layer_unlock_frame_buffer();
                        gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                    }
                    else /* Pen move to invalid cell, highlight the cell */
                    {
                        ;
                    }
                }
            }
            else /* Pen is in outside of cell area */
            {
                if (c->cell_array.cell_enlarge_is_shown == MMI_TRUE)
                {
                    gdi_layer_lock_frame_buffer();
                    gui_calendar_recover_enlarge_cell(c);
		    gdi_layer_blt_previous(
			c->cell_array.cell_enlarge_cache_x + c->x,
			c->cell_array.cell_enlarge_cache_y + c->y,
			c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x,
			c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y);
		    gdi_layer_unlock_frame_buffer();
                    /* we need set highlight_row_old to a value not equal highlight_row */
                    gui_calendar_highlight_cell(c);
                    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                }
                else
                {
                    ;
                }
            }
        }
        else
        {
            if (PEN_CHECK_BOUND(
                    pos.x,
                    pos.y,
                    c->x + c->cell_array.x,
                    c->y + c->cell_array.y,
                    c->cell_array.width,
                    c->cell_array.height))
            {
                if (pen_row >= c->row || pen_column >= c->column)
                {
                    result = MMI_FALSE;
                }

                if ((highlight_row == pen_row) && (highlight_column == pen_column) &&
                    (c->cell_array.pen_on_highlight == TRUE))
                {
                    c->cell_array.pen_on_highlight = TRUE;
                }
                else
                {
                    if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
                    {
                        if ((highlight_row != pen_row) || (highlight_column != pen_column))
                        {
                            if(is_valid == MMI_TRUE)
                            {
                                gui_calendar_unhighlight_cell(c);
                                c->highlight_time = temp;
                                gui_calendar_highlight_cell(c);
                                gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                            }
                        }
                    }   
                    c->cell_array.pen_on_highlight = FALSE;
                }
            }
        }
    #else /* __MMI_CALENDAR_ENLARGE_CELL__ */

        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->cell_array.x,
                c->y + c->cell_array.y,
                c->cell_array.width,
                c->cell_array.height))
        {
            if (pen_row >= c->row || pen_column >= c->column)
            {
                result = MMI_FALSE;
            }

            if ((highlight_row == pen_row) && (highlight_column == pen_column) &&
                (c->cell_array.pen_on_highlight == TRUE))
            {
                c->cell_array.pen_on_highlight = TRUE;
            }
            else
            {
                if ((pen_row != 0xffffffff) && (pen_column != 0xffffffff))
                {
                    if ((highlight_row != pen_row) || (highlight_column != pen_column))
                    {
                        if(is_valid == MMI_TRUE)
                        {
                            gui_calendar_unhighlight_cell(c);
                            c->highlight_time = temp;
                            gui_calendar_highlight_cell(c);
                            gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
                        }
                    }
                }   
                c->cell_array.pen_on_highlight = FALSE;
            }
        }
    #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */
    }

    /* vertical select */
    if (c->vertical_select.pen_down_in_prev_button == TRUE)
    {
        if (gui_calendar_is_vertical_select_prev_icon(
                c,
                pos))
        {
            if (c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                c->vertical_select.prev_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
            {
                result = MMI_TRUE;
            }
            else
            {
                c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_MOVE_IN;
            }
        }
        else
        {
            c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        }
    
        gui_calendar_redraw_vertical_select(
                    c,
                    NULL);

        result = MMI_TRUE;
    }
    if (c->vertical_select.pen_down_in_next_button == TRUE)
    {
        if (gui_calendar_is_vertical_select_next_icon(
                c,
                pos))
        {
            if (c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                c->vertical_select.next_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
            {
                result = MMI_TRUE;
            }
            else
            {
                c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_MOVE_IN;
            }
        }
        else
        {
            c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        }

        gui_calendar_redraw_vertical_select(
                    c,
                    NULL);

        result = MMI_TRUE;
    }

#ifdef __MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__
    /* Title */
    if (c->title.pen_down_in_prev_button == TRUE)
    {
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->title.x + c->title.prev_icon_x,
                c->y + c->title.y + c->title.prev_icon_y,
                c->title.prev_icon_width,
                c->title.prev_icon_height))
        {
            if (c->title.prev_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                c->title.prev_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
            {
                result = MMI_TRUE;
            }
            else
            {
                c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_MOVE_IN;
            }
        }
        else
        {
            c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        }
    
        gdi_layer_lock_frame_buffer();
        gui_calendar_draw_title(c);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            c->x + c->title.x,
            c->y + c->title.y,
            c->x + c->title.x + c->title.width - 1,
            c->y + c->title.y + c->title.height - 1);

        result = MMI_TRUE;
    }
    if (c->title.pen_down_in_next_button == TRUE)
    {
        if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                c->x + c->title.x + c->title.next_icon_x,
                c->y + c->title.y + c->title.next_icon_y,
                c->title.next_icon_width,
                c->title.next_icon_height))
        {
            if (c->title.next_button_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                c->title.next_button_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
            {
                result = MMI_TRUE;
            }
            else
            {
                c->title.next_button_state = GUI_CALENDAR_PEN_STATE_MOVE_IN;
            }
        }
        else
        {
            c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        }
    
        gdi_layer_lock_frame_buffer();
        gui_calendar_draw_title(c);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            c->x + c->title.x,
            c->y + c->title.y,
            c->x + c->title.x + c->title.width - 1,
            c->y + c->title.y + c->title.height - 1);

        result = MMI_TRUE;
    }
#endif
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_PenAbortHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_calendar_PenAbortHandler(gui_calendar_struct* c, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if (c->cell_array.pen_down_in_cell_array == TRUE)
    {
    #ifdef __MMI_CALENDAR_ENLARGE_CELL__
        /* Pen is in the area of cell enlarge icon, not handle it. */
        if ((c->type == GUI_CALENDAR_TYPE_MONTH) && 
            (c->cell_array.cell_enlarge_is_shown == MMI_TRUE))
        {
            gui_calendar_recover_enlarge_cell(c);
            gui_calendar_highlight_cell(c);
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            c->cell_array.pen_on_highlight = FALSE;
            c->cell_array.pen_down_in_cell_array = FALSE;
            return MMI_TRUE;
        }
    #endif /* __MMI_CALENDAR_ENLARGE_CELL__ */

        c->cell_array.pen_on_highlight = FALSE;
        c->cell_array.pen_down_in_cell_array = FALSE;
    }

    /* vertical select */
    if (c->vertical_select.pen_down_in_prev_button || c->vertical_select.pen_down_in_next_button)
    {
        c->vertical_select.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        c->vertical_select.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        gui_calendar_redraw_vertical_select(
                    c,
                    NULL);

        c->vertical_select.pen_down_in_prev_button = FALSE;
        c->vertical_select.pen_down_in_next_button = FALSE;
    }
#ifdef __MMI_CALENDAR_TITLE_PREV_NEXT_SWITCH__
    if (c->title.pen_down_in_prev_button == TRUE)
    {
        c->title.prev_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        gdi_layer_lock_frame_buffer();
        gui_calendar_draw_title(c);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            c->x + c->title.x,
            c->y + c->title.y,
            c->x + c->title.x + c->title.width - 1,
            c->y + c->title.y + c->title.height - 1);
        c->title.pen_down_in_prev_button = FALSE;
    }
    if (c->title.pen_down_in_next_button == TRUE)
    {
        c->title.next_button_state = GUI_CALENDAR_PEN_STATE_NORMAL;
        gdi_layer_lock_frame_buffer();
        gui_calendar_draw_title(c);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            c->x + c->title.x,
            c->y + c->title.y,
            c->x + c->title.x + c->title.width - 1,
            c->y + c->title.y + c->title.height - 1);
        c->title.pen_down_in_next_button = FALSE;
    }
#endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]         
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_calendar_translate_pen_event(
          gui_calendar_struct *c,
          mmi_pen_event_type_enum pen_event,
          S16 x,
          S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_pen_point_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    if (c->is_on_idle == MMI_TRUE)
    {
        return ret;
    }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    
    if (c->pen_enable == MMI_FALSE)
    {
        return ret;
    }

    pos.x = x;
    pos.y = y;
    
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            ret = gui_calendar_PenDownHandler(c, pos);
            break;
            
        case MMI_PEN_EVENT_UP:
            ret = gui_calendar_PenUpHandler(c, pos);
            break;
    
        case MMI_PEN_EVENT_MOVE:
            ret = gui_calendar_PenMoveHandler(c, pos);
            break;

        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
            break;

        case MMI_PEN_EVENT_ABORT:
            ret = gui_calendar_PenAbortHandler(c, pos);
            break;

        default:
            MMI_ASSERT(0);
    }
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_switch_prev
 * DESCRIPTION
 *  Switch current calendar to prev month / week.
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_switch_prev(
      gui_calendar_struct* c,
      gui_calendar_time_switch_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CALENDAR_NEW_STYLE__    
    applib_time_struct temp;
    applib_time_struct inc, result, diff;
    applib_time_struct min_time;
    S32 time_compare;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    memset(&diff, 0, sizeof(applib_time_struct));
    memset(&min_time, 0, sizeof(applib_time_struct));
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (type == GUI_CALENDAR_TIME_SWITCH_YEAR)
        {
            /* Calculate the real min display time. */
            gui_calendar_adjust_date_boundary(
                c,
                &min_time,
                &temp,
                c->min_time);

            inc.nYear = 1;
            temp = c->highlight_time;
            temp.nDay = 1;
            applib_dt_decrease_time(&temp, &inc, &result);

            time_compare = applib_dt_compare_time(
                               &min_time,
                               &result,
                               &diff);

            /* If the time is greater than min_time, go to prev month. */
            if (time_compare == DT_TIME_LESS || time_compare == DT_TIME_EQUAL)
            {
                c->highlight_time = result;
                gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                if (c->detail.detail_is_shown == MMI_TRUE)
                {
                    c->detail.detail_is_shown = MMI_FALSE;
                }
                gui_calendar_show(c);
		gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }
            else
            {
                {
                    /* Out of date boundary, need App to popup information */
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, result, c->start_time, c->end_time);
                    }
                }
                return;
            }
        }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
        if (type == GUI_CALENDAR_TIME_SWITCH_MONTH)
        {
            gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_UP);
        }
    }
    else if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        if (type == GUI_CALENDAR_TIME_SWITCH_WEEK)
        {
            gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_UP);
        }
        if (type == GUI_CALENDAR_TIME_SWITCH_SINGLE_PERIOD)
        {
            if (c->start_time.nHour >= GUI_CALENDAR_WEEK_TIME_INTERVAL)
            {
                c->start_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL;
                c->end_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL;
                if (c->highlight_time.nHour == c->end_time.nHour)
                {
                    c->highlight_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL;
                }
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                gui_calendar_show(c);
		gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }
        }
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (type == GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD)
        {
			if (c->start_time.nHour >= GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row)
            {
                c->start_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
                c->end_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
                c->highlight_time.nHour -= GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                gui_calendar_show(c);
		gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }
            else if(c->start_time.nHour > 0)
            {
                c->end_time.nHour -= c->start_time.nHour;
		c->highlight_time.nHour -= c->start_time.nHour;
		c->start_time.nHour = 0;
		{
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
		gui_calendar_show(c);
		gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
	    }
        }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_switch_next
 * DESCRIPTION
 *  Switch current calendar to next time.
 * PARAMETERS
 *  c       [IN]
 *  type    [IN]: Is the time switch type.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_switch_next(
      gui_calendar_struct* c,
      gui_calendar_time_switch_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CALENDAR_NEW_STYLE__    
    applib_time_struct temp;
    applib_time_struct inc, result, diff;
    applib_time_struct max_time;
    S32 time_compare;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    memset(&temp, 0, sizeof(applib_time_struct));
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&result, 0, sizeof(applib_time_struct));
    memset(&diff, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));
#endif /*__MMI_CALENDAR_NEW_STYLE__*/    
    if (c->type == GUI_CALENDAR_TYPE_MONTH)
    {
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (type == GUI_CALENDAR_TIME_SWITCH_YEAR)
        {
            /* Calculate the real max display time. */
            gui_calendar_adjust_date_boundary(
                c,
                &temp,
                &max_time,
                c->max_time);

            inc.nYear = 1;
            temp = c->highlight_time;
            temp.nDay = 1;
            applib_dt_increase_time(&temp, &inc, &result);

            time_compare = applib_dt_compare_time(
                               &max_time,
                               &result,
                               &diff);

            /* If the time is smaller than max_time, go to next month. */
            if (time_compare == DT_TIME_GREATER || time_compare == DT_TIME_EQUAL)
            {
                c->highlight_time = result;
                gui_calendar_adjust_date_boundary(c, &c->start_time, &c->end_time, result);
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                if (c->detail.detail_is_shown == MMI_TRUE)
                {
                    c->detail.detail_is_shown = MMI_FALSE;
                }
                gui_calendar_show(c);
                gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }
            else
            {
                {
                    /* Out of date boundary, need App to popup information */
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, result, c->start_time, c->end_time);
                    }
                }
                return;
            }
        }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
        if (type == GUI_CALENDAR_TIME_SWITCH_MONTH)
        {
            gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_DOWN);
        }
    }
    else if (c->type == GUI_CALENDAR_TYPE_WEEK)
    {
        if (type == GUI_CALENDAR_TIME_SWITCH_WEEK)
        {
            gui_calendar_general_switch_handler(GUI_CALENDAR_DIRECTION_PAGE_DOWN);
        }
        
        if (type == GUI_CALENDAR_TIME_SWITCH_SINGLE_PERIOD)
        {
            if (c->end_time.nHour < DT_HRS_PRE_DAY)
            {                
                c->end_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL;
                if (c->highlight_time.nHour == c->start_time.nHour)
                {
                    c->highlight_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL;
                }
                c->start_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL;
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                gui_calendar_show(c);
                gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }
        }
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (type == GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD)
        {
            if (c->end_time.nHour + GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row <= DT_HRS_PRE_DAY)
            {
                c->start_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
                c->end_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
                c->highlight_time.nHour += GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                gui_calendar_show(c);
                gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }
            else if (c->end_time.nHour < DT_HRS_PRE_DAY)
            {
                c->start_time.nHour += DT_HRS_PRE_DAY - c->end_time.nHour;
                c->highlight_time.nHour += DT_HRS_PRE_DAY - c->end_time.nHour;
                c->end_time.nHour = DT_HRS_PRE_DAY;
                {
                    /* Let category and App adjust the highlight time */
                    gdi_layer_lock_frame_buffer();
                    if (c->highlight_change_callback != NULL)
                    {
                        c->highlight_change_callback(c->type, c->highlight_time, c->start_time, c->end_time);
                    }
                    gdi_layer_unlock_frame_buffer();
                }
                gui_calendar_show(c);
                gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
            }

        }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
    }
    else
    {
        return;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_get_position
 * DESCRIPTION
 *  get the location of calendar
 * PARAMETERS
 *  c       [IN]        Is the calendar
 *  x       [IN]        Is the x pos
 *  y       [IN]        Is the y pos
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_get_position(gui_calendar_struct *c, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = c->x;
    *y = c->y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_get_dimension
 * DESCRIPTION
 *  get the dimension of calendar
 * PARAMETERS
 *  c       [IN]        Is the calendar
 *  width   [IN]        Is the width
 *  height  [IN]        Is the height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_get_dimension(gui_calendar_struct *c, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = c->width;
    *height = c->height;
}


#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_on_idle
 * DESCRIPTION
 *  Set idle calendar is od idle or not.
 * REMARKS
 *  
 * PARAMETERS
 *  c                   : [IN] Is the calendar object
 *  is_on_idle          : [IN] Is on idle nor not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_on_idle(gui_calendar_struct *c, MMI_BOOL is_on_idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (is_on_idle != c->is_on_idle)
    {
        c->is_on_idle = is_on_idle;
        
        if (c->is_on_idle == MMI_TRUE)
        {
            /* Idle calendar not need cache the cell */
            if (c->cell_array.cell_cache.buf_ptr != NULL)
            {
                mmi_frm_scrmem_free(c->cell_array.cell_cache.buf_ptr);
                c->cell_array.cell_cache.buf_ptr = NULL;
            }
        #ifdef __MMI_TOUCH_SCREEN__
            gui_calendar_set_pen_enable(c, MMI_FALSE);
        #endif
        }
        else
        {
            /* Malloc memory of cell cache */
            c->cell_array.cell_cache.buf_ptr = (U8*)mmi_frm_scrmem_alloc(GUI_CALENDAR_CACHE_CELL_SIZE);
            MMI_DBG_ASSERT(c->cell_array.cell_cache.buf_ptr != NULL);
            memset(c->cell_array.cell_cache.buf_ptr, 0, GUI_CALENDAR_CACHE_CELL_SIZE);
        #ifdef __MMI_TOUCH_SCREEN__
            gui_calendar_set_pen_enable(c, MMI_TRUE);
        #endif
            
        }
        gui_calendar_init_layout(c);
        gui_calendar_set_theme(c, current_UI_theme->calendar_theme);
    }
}


#if defined (__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_in_venus
 * DESCRIPTION
 *  Set idle calendar is in venus or not.
 * REMARKS
 *  This API only available when the calendar's type is GUI_CALENDAR_IDLE_NORMAL_MONTH.
 * PARAMETERS
 *  c                   : [IN] Is the calendar object
 *  is_in_venus         : [IN] Is in venus nor not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_in_venus(gui_calendar_struct *c, MMI_BOOL is_in_venus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->is_on_idle == MMI_TRUE)
    {
        c->is_in_venus = is_in_venus;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_update_screen_callback
 * DESCRIPTION
 *  Register calendar's update screen callback of venus.
 * REMARKS
 *  This API only available when the calendar's type is GUI_CALENDAR_IDLE_NORMAL_MONTH.
 * PARAMETERS
 *  c                               : [IN] Is the calendar object
 *  update_screen_callback          : [IN] Is update screen callback
 *  update_screen_handle            : [IN] In update screen handle
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_register_update_screen_callback(
      gui_calendar_struct *c,
      void (*update_screen_callback)(void *handle),
      void *update_screen_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->is_on_idle == MMI_TRUE)
    {
        c->venus_update_screen_callback = update_screen_callback;
        c->venus_update_screen_handle = update_screen_handle;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_venus_update
 * DESCRIPTION
 *  The update of idle calendar is triggered by venus.
 * REMARKS
 *  This API only available when the calendar's type is GUI_CALENDAR_IDLE_NORMAL_MONTH.
 * PARAMETERS
 *  c                       : [IN] Is the calendar object
 *  is_venus_update         : [IN] The update is ocme from venus
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_venus_update(gui_calendar_struct *c, MMI_BOOL is_venus_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->is_on_idle == MMI_TRUE)
    {
        c->is_venus_update = is_venus_update;
    }
}
#endif /* __MMI_VUI_HOMESCREEN__ || __MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__*/


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_idle_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_idle_update(gui_calendar_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->is_on_idle == MMI_TRUE)
    {
    #if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if (c->is_in_venus == MMI_TRUE)
        {
            if (c->is_venus_update == MMI_FALSE)
            {
                gui_calendar_move(c, 0, 0);
                gui_calendar_show(c);
                c->venus_update_screen_callback(c->venus_update_screen_handle);
            }
            else
            {
                gui_calendar_show(c);				
                c->is_venus_update = MMI_FALSE;
            }
            return;
        }
    #endif /* __MMI_VUI_HOMESCREEN__ || __MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__*/
		gui_calendar_show(c);
		gdi_layer_blt_previous(
			c->x, 
			c->y, 
			c->x + c->width - 1, 
			c->y + c->height - 1);
    }
}
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#ifdef __MMI_CALENDAR_ENLARGE_CELL__
/*****************************************************************************
 * FUNCTION
 *  gui_calendar_enlarge_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_enlarge_cell(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_y, cell_width, cell_height;
    S32 highlighted_cell_x, highlighted_cell_y;
    U32 highlight_row, highlight_column;
    S32 text_x, text_y, text_width, text_height;
    S32 layer_offset_x = 0, layer_offset_y = 0;
    S8 temp_text[GUI_CALENDAR_MAX_CELL_TEXT];
    UI_character_type cell_text[GUI_CALENDAR_MAX_CELL_TEXT];
    gdi_handle active_layer = GDI_NULL_HANDLE;
	gdi_handle h0, h1, h2, h3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_get_active(&active_layer);

    cell_x = c->cell_array.x;
    cell_y = c->cell_array.y;
    cell_width = c->cell_array.cell_width;
    cell_height = c->cell_array.cell_height;

    gui_calendar_calculate_highlight_position(c, &highlight_row, &highlight_column);
    highlighted_cell_x = cell_x + (cell_width + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_column;
    highlighted_cell_y = cell_y + (cell_height + GUI_CALENDAR_FRAME_LINE_PIXEL) * highlight_row;
    c->cell_array.cell_enlarge_cache_width = GUI_CALENDAR_CACHE_CELL_ENLARGE_WIDTH;
    c->cell_array.cell_enlarge_cache_height = GUI_CALENDAR_CACHE_CELL_ENLARGE_HEIGHT;
    c->cell_array.cell_enlarge_cache_x = highlighted_cell_x -
                                         (c->cell_array.cell_enlarge_cache_width - cell_width) / 2;
    c->cell_array.cell_enlarge_cache_y = highlighted_cell_y -
                                         c->cell_array.cell_enlarge_cache_height +
                                         (c->cell_array.cell_enlarge_cache_height - cell_height) / 2;
    if ((c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width) >
        (c->cell_array.x + c->cell_array.width))
    {
        c->cell_array.cell_enlarge_cache_x = c->cell_array.x + c->cell_array.width - c->cell_array.cell_enlarge_cache_width;
    }
    if (c->cell_array.cell_enlarge_cache_x < c->cell_array.x)
    {
        c->cell_array.cell_enlarge_cache_x = c->cell_array.x;
    }

    gui_set_text_color(c->title.text_color);
    /* we use medium bold font since we may not have large of some language */
#if defined(__MMI_MAINLCD_320X480__)
    gui_set_font(&MMI_virtual_keyboard_hint_font);
#else
    gui_set_font(&MMI_medium_font);
#endif
    sprintf((S8*)temp_text, "%2d", c->highlight_time.nDay);
    mmi_asc_to_ucs2((S8*)cell_text, temp_text);
    gui_measure_string(cell_text, &text_width, &text_height);
    text_x = c->cell_array.cell_enlarge_cache_x + (c->cell_array.cell_enlarge_cache_width - text_width) / 2;
    text_y = c->cell_array.cell_enlarge_cache_y + (c->cell_array.cell_enlarge_cache_height - text_height) / 2;
    if (mmi_fe_get_r2l_state())
    {
        text_x += text_width - 1;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->cell_array.cell_enlarge_cache_x + c->x - layer_offset_x,
        c->cell_array.cell_enlarge_cache_y + c->y - layer_offset_y,
        c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x - layer_offset_x,
        c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y - layer_offset_y);

    /* keep the current screen content */
    if(NULL != c->cell_array.cell_enlarge_cache.buf_ptr)
    {
        gdi_image_cache_bmp_get(
            c->cell_array.cell_enlarge_cache_x + c->x - layer_offset_x,
            c->cell_array.cell_enlarge_cache_y + c->y - layer_offset_y,
            c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x - layer_offset_x,
            c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y - layer_offset_y,
            &c->cell_array.cell_enlarge_cache);
    }
	gdi_push_and_set_alpha_blending_source_layer(active_layer);

    if (current_MMI_theme->popup_cell_normal_background != NULL)
    {
		gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
		gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
        gdi_image_draw_resized(
            c->cell_array.cell_enlarge_cache_x + c->x - layer_offset_x,
            c->cell_array.cell_enlarge_cache_y + c->y - layer_offset_y,
            c->cell_array.cell_enlarge_cache_width,
            c->cell_array.cell_enlarge_cache_height,
            current_MMI_theme->popup_cell_normal_background);
    }
    gui_move_text_cursor(text_x + c->x - layer_offset_x, text_y + c->y - layer_offset_y);
    gui_print_text((UI_string_type)cell_text);

    gdi_layer_pop_clip();

    gdi_pop_and_restore_alpha_blending_source_layer();
    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }

    c->cell_array.cell_enlarge_is_shown = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_recover_enlarge_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c                       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_calendar_recover_enlarge_cell(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(c->target_layer);
    }
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        c->cell_array.cell_enlarge_cache_x + c->x - layer_offset_x,
        c->cell_array.cell_enlarge_cache_y + c->y - layer_offset_y,
        c->cell_array.cell_enlarge_cache_x + c->cell_array.cell_enlarge_cache_width - 1 + c->x - layer_offset_x,
        c->cell_array.cell_enlarge_cache_y + c->cell_array.cell_enlarge_cache_height - 1 + c->y - layer_offset_y);
    if (c->cell_array.cell_enlarge_is_shown == MMI_TRUE)
    {
        if(NULL != c->cell_array.cell_enlarge_cache.buf_ptr)
        {
            gdi_image_cache_bmp_draw(
                c->cell_array.cell_enlarge_cache_x + c->x - layer_offset_x,
                c->cell_array.cell_enlarge_cache_y + c->y - layer_offset_y,
                &c->cell_array.cell_enlarge_cache);
        }
        else
        {
            gui_calendar_draw_cell_array(c);
        }
        c->cell_array.cell_enlarge_is_shown = MMI_FALSE;
    }

    gdi_layer_pop_clip();

    if (c->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}
#endif /* __MMI_CALENDAR_ENLARGE_CELL__ */


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_flags_on
 * DESCRIPTION
 *  Turn on flag of calendar
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_flags_on(gui_calendar_struct* c, S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    c->flags |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_flags_off
 * DESCRIPTION
 *  Turn off flag of calendar
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_flags_off(gui_calendar_struct* c, S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    c->flags &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_set_week_start_hour
 * DESCRIPTION
 *  Set the start hour of calendar weekly view.
 * PARAMETERS
 *  start_hour        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_set_week_start_hour(gui_calendar_struct* c, S32 start_hour)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 end_hour, temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if ((c->type != GUI_CALENDAR_TYPE_WEEK) || (start_hour < 0))
    {
        return;
    }
    temp = start_hour % GUI_CALENDAR_WEEK_TIME_INTERVAL;
    if (temp != 0)
    {
        start_hour = start_hour - temp;
    }
    end_hour = start_hour + GUI_CALENDAR_WEEK_TIME_INTERVAL * c->row;
    if (end_hour > DT_HRS_PRE_DAY)
    {
        return;
    }
    if ((start_hour > c->highlight_time.nHour) || (end_hour <= c->highlight_time.nHour))
    {
        return;
    }

    c->start_time.nHour = start_hour;
    c->end_time.nHour = end_hour;
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_system_date_change
 * DESCRIPTION
 *  When System date change, check whether it need to change highlight.
 * PARAMETERS
 *  start_hour        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_system_date_change(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    applib_time_struct current, inc, temp, result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    applib_dt_get_date_time(&current);
	memset(&inc, 0, sizeof(applib_time_struct));
	memset(&temp, 0, sizeof(applib_time_struct));
	memset(&result, 0, sizeof(applib_time_struct));

	temp = c->highlight_time;
	inc.nDay = 1;
	applib_dt_increase_time(&temp, &inc, &result);

    if (c->is_on_idle == MMI_TRUE)
    {
        c->highlight_time = current;
    }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_update
 * DESCRIPTION
 *  Update the calendar component.
 * PARAMETERS
 *  c       [IN]     Is the calendar pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calendar_update(gui_calendar_struct* c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_ENLARGE_CELL__
    MMI_BOOL recover_enlarge_cell = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    if (c->type == GUI_CALENDAR_TYPE_NONE || c->type == GUI_CALENDAR_TYPE_END)
    {
        return;
    }

    gdi_layer_lock_frame_buffer();
#ifdef __MMI_CALENDAR_ENLARGE_CELL__
    if (c->cell_array.cell_enlarge_is_shown == MMI_TRUE)
    {
        gui_calendar_recover_enlarge_cell(c);
        recover_enlarge_cell = MMI_TRUE;
    }
#endif
    gui_calendar_unhighlight_cell(c);

    gui_calendar_draw_bg(c, c->x, c->y, c->width, c->height);
    if (c->bg_image == NULL)
    {
        gui_calendar_draw_bg_frame(c);
    }
    
    /* Query the data from calendar. */
    gui_calendar_query_cell_data(c);
    gui_calendar_draw_cell_array(c);

    gui_calendar_draw_horizontal_string(c);
    gui_calendar_draw_vertical_select(c);
#ifdef __MMI_CALENDAR_ENLARGE_CELL__
    if (recover_enlarge_cell == MMI_TRUE)
    {
        gui_calendar_enlarge_cell(c);
    }
#endif
    gui_calendar_highlight_cell(c);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
}


