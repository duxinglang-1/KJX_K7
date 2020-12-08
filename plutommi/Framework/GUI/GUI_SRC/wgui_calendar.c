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
 *  wgui_calendar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Calendar - UI component
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

#include "MMI_features.h"
#include "gui_calendar.h"
#include "wgui_calendar.h"
 
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

gui_calendar_struct g_wgui_calendar;


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calendar_type       [IN]        
 *  row_num             [IN]        
 *  column_num          [IN]        
 *  cell_buf            [?]         
 *  popup_buf           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_create(
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
    gui_calendar_create(
        &g_wgui_calendar,
        type,
        max_date,
        min_date,
        show_date,
        flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bg_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_bg(UI_image_ID_type bg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_bg(&g_wgui_calendar, bg_id);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_close(&g_wgui_calendar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_show(&g_wgui_calendar);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL wgui_calendar_translate_pen_event(mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_calendar_translate_pen_event(&g_wgui_calendar, pen_event, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_highlight_select_function
 * DESCRIPTION
 *  Set the highlight select callback function of the calendar.
 * PARAMETERS
 *  f               [IN]    Is the hide select callback function.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_highlight_select_function(
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
    gui_calendar_register_highlight_select_function(&g_wgui_calendar, highlight_select_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_pen_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_pen_enable   [IN]    is pen enable or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_pen_enable(MMI_BOOL is_pen_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_pen_enable(&g_wgui_calendar, is_pen_enable);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_switch_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]: Is the time type we want to switch.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_switch_prev(gui_calendar_time_switch_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_switch_prev(&g_wgui_calendar, type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_switch_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]: Is the time type we want to switch.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_switch_next(gui_calendar_time_switch_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_switch_next(&g_wgui_calendar, type);
}
#endif /*__MMI_TOUCH_SCREEN__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_get_frame_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
void wgui_calendar_get_frame_area(S32 *x, S32 *y, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = g_wgui_calendar.x;
    *y = g_wgui_calendar.y;
    *width = g_wgui_calendar.width;
    *height = g_wgui_calendar.height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]    is x pos
 *  y       [IN]    is y pos
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_move(&g_wgui_calendar, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_resize
 * DESCRIPTION
 *  Changes the dimension of calendar.
 * PARAMETERS
 *  width       [IN]    Is the new width of calendar.
 *  height      [IN]    Is the new height of calendar.
 *  title_height[IN]    Is the new height of calendar title.
 *  cell_width  [IN]    Is the new width of calendar's every cell.
 *  cell_ehgith [IN]    Is the new height of calendar's every cell.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_resize(S32 width, S32 height, S32 title_height, S32 cell_width, S32 cell_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_resize(
        &g_wgui_calendar,
        width,
        height,
        title_height,
        cell_height,
        cell_height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_cell_data_query_handler
 * DESCRIPTION
 *  Set the query handler of cell data.
 * PARAMETERS
 *  cell_data_query_handler     [IN]    Is the query handler of cell data.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_cell_data_query_handler(
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
    gui_calendar_register_cell_data_query_handler(&g_wgui_calendar, cell_data_query_handler);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calendar_register_cell_detail_query_handler
 * DESCRIPTION
 *  Set the query handler of cell detail.
 * PARAMETERS
 *  cell_detail_query_handler   [IN]    Is the query handler of cell detail.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_cell_detail_query_handler(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_cell_detail_query_handler(&g_wgui_calendar, cell_detail_query_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_highlight_change_function
 * DESCRIPTION
 *  Set the highlight move callback function of the calendar.
 * PARAMETERS
 *  highlight_change_callback   [IN]    Is the hide select callback function.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_highlight_change_function(
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
    gui_calendar_register_highlight_change_function(&g_wgui_calendar, highlight_change_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_get_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]    is x pos
 *  y       [IN]    is y pos
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_get_position(S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_get_position(&g_wgui_calendar, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_get_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width   [IN]        Is the width
 *  height  [IN]        Is the height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_get_dimension(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_get_dimension(&g_wgui_calendar, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_hide_function
 * DESCRIPTION
 *  set the hide callback function of the calendar
 * PARAMETERS
 *  f               [IN]        New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gui_calendar_register_hide_function(&g_wgui_calendar, f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_target_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target_layer    [IN]    Is the target layer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_target_layer(GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_target_layer(&g_wgui_calendar, target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_abm_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target_layer    [IN]    Is the target layer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_abm_layer(GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_abm_layer(&g_wgui_calendar, abm_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_key_handler
 * DESCRIPTION
 *  Set calendar component key handler.
 * REMARKS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_key_handler(&g_wgui_calendar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_clear_key_handler
 * DESCRIPTION
 *  Clear calendar component key handler.
 * REMARKS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_clear_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_clear_key_handler(&g_wgui_calendar);
}


#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_on_idle
 * DESCRIPTION
 *  Set idle calendar is on idle or not.
 * REMARKS
 *  
 * PARAMETERS
 *  is_on_idle         : [IN] Is on idle nor not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_on_idle(MMI_BOOL is_on_idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_on_idle(&g_wgui_calendar, is_on_idle);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_idle_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_idle_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_idle_update(&g_wgui_calendar);
}


#if defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_in_venus
 * DESCRIPTION
 *  Set idle calendar is in venus or not.
 * REMARKS
 *  This API only available when the calendar's type is GUI_CALENDAR_IDLE_NORMAL.
 * PARAMETERS
 *  is_in_venus         : [IN] Is in venus nor not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_in_venus(MMI_BOOL is_in_venus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_in_venus(&g_wgui_calendar, is_in_venus);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_register_update_screen_callback
 * DESCRIPTION
 *  Register calendar's update screen callback of venus.
 * REMARKS
 *  This API only available when the calendar's type is GUI_CALENDAR_IDLE_NORMAL.
 * PARAMETERS
 *  update_screen_callback          : [IN] Is update screen callback
 *  update_screen_handle            : [IN] In update screen handle
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_register_update_screen_callback(
      void (*update_screen_callback)(void *handle),
      void *update_screen_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_register_update_screen_callback(
        &g_wgui_calendar,
        update_screen_callback,
        update_screen_handle);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_venus_update
 * DESCRIPTION
 *  The update of idle calendar is triggered by venus.
 * REMARKS
 *  This API only available when the calendar's type is GUI_CALENDAR_IDLE_NORMAL.
 * PARAMETERS
 *  is_venus_update         : [IN] The update is ocme from venus
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_venus_update(MMI_BOOL is_venus_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_venus_update(&g_wgui_calendar, is_venus_update);
}

#endif /* __MMI_VUI_HOMESCREEN__ || __MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__*/

#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_flags_on
 * DESCRIPTION
 *  Turn on flag of calendar
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_flags_on(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_flags_on(&g_wgui_calendar, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_flags_off
 * DESCRIPTION
 *  Turn off flag of calendar
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_flags_off(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_set_flags_off(&g_wgui_calendar, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_set_history
 * DESCRIPTION
 *  Set the history of calendar weekly view.
 * PARAMETERS
 *  history        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_set_history(U16 history_ID, U8 *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history != NULL)
    {
        wgui_calendar_history_struct *h = (wgui_calendar_history_struct*)history;
        if (h->history_ID == (history_ID | 0x8000))
        {
            gui_calendar_set_week_start_hour(&g_wgui_calendar, h->week_start_hour);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_get_history
 * DESCRIPTION
 *  Get the history of calendar weekly view.
 * PARAMETERS
 *  history        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_get_history(U16 history_ID, U8 *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        wgui_calendar_history_struct *h = (wgui_calendar_history_struct*)history;
        h->history_ID = hID;
        h->week_start_hour = (g_wgui_calendar.start_time).nHour;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_get_history_size
 * DESCRIPTION
 *  get the history size of calendar
 * PARAMETERS
 *  viod
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_calendar_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(wgui_calendar_history_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_system_date_change
 * DESCRIPTION
 *  When System date change, check whether it need to change highlight.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_system_date_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_system_date_change(&g_wgui_calendar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_calendar_update
 * DESCRIPTION
 *  Update the calendar display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_calendar_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_calendar_update(&g_wgui_calendar);
}

