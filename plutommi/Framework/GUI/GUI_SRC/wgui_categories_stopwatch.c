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
 *   wgui_categories_stopwatch.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Functions to display Stop Watch related Screens
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_STOPWATCH__

//#include "stdC.h"
//#include "mmi_platform.h"
//#include "mmi_frm_gprot.h"

//#include "GlobalDefs.h"
//#include "WguiCategoryGprot.h"
//#include "CustDataProts.h"
//#include "CustMenuRes.h"
#include "CustThemesRes.h"
#include "wgui_fixed_menuitems.h"
#include "gui_font_size.h"

/* Stopwatch Header Files */
//#include "StopwatchGprot.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_stopwatch_def.h"
#endif
#include "Stopwatchprot.h"

//RHR
    #include "MMIDataType.h"
    #include "wgui_categories_stopwatch.h"
    #include "wgui_categories_list.h"
    #include "gui_data_types.h"
    #include "gui.h"
    #include "kal_public_api.h"
    #include "gui_typedef.h"
    #include "wgui_categories_util.h"
    #include "string.h"
    #include "gdi_include.h"
    #include "wgui.h"
    #include "gui_themes.h"
    #include "wgui_title.h"
    #include "app_mem.h"
    #include "wgui_draw_manager.h"
    #include "gdi_const.h"
    #include "CustDataRes.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "gui_switch.h"
    #include "gui_panel.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories_multimedia.h"
    #include "kal_general_types.h"
    #include "wgui_categories_enum.h"
    #include "mmi_frm_events_gprot.h"
    #include "wgui_touch_screen.h"
    #include "wgui_fixed_menus.h"
    #include "gui_fixed_menus.h"
    #include "gui_fixed_menuitems.h"
    #include "gdi_datatype.h"
    #include "DebugInitDef_Int.h"
    #include "gui_config.h"
    #include "stdio.h"
    #include "Unicodexdcl.h"
    #include "wgui_include.h"
    #include "mmi_frm_mem_gprot.h"
    #include "PixcomFontEngine.h"
    #include "lcd_sw_rnd.h"
    #include "gui_scrollbars.h"
/***************************************************************************** 
* Local Variable
*****************************************************************************/
static U8 stop_play_flag = 0;     /* The stopwatch is started or not */
wtchSkinResStruct wtch_pos;       /* The coordinates of stopwatch's control area */

/* For get increment time, the unit is ticks */
static U32 gInitialTime = 0;
static U32 gCurrentTime = 0;
static U32 gMPInitialTime = 0;
static U32 gMPCurrentTime = 0;

SCREEN_NAME g_current_screen = NOT_STOPWATCH_SCR;  /* Screen flag */
INCREMENT_TYPE gDoNotIncrement;                    /* Increment flag */

/***************************************************************************** 
* External variable / function
*****************************************************************************/
extern S32 GUI_current_fixed_icontext_list_menuitem_column;
extern BOOL r2lMMIFlag;
extern U8 category89_string_list[MAX_CATEGORY89_STRINGS][MAX_CATEGORY89_STRING_LENGTH];
extern UI_filled_area  *old_bg_filler;

extern S32 fixed_icontext_list_menuitem_total(void);
extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);

/*****************************************************************************/
/***  N-way Stopwatch                                                      ***/
/*****************************************************************************/

/**********************************************************************************/
/*** nWay Stopwatch Screen                                                      ***/
/*** Screen ID: 306                                                             ***/
/**********************************************************************************/
/***                                                                            ***/
/***                                                                            ***/
/***   CategoryScreen306:                                                       ***/
/***                                                                            ***/
/***   ====================                                                     ***/
/***   =   00:14:56:07    =    <-- Main timer (title_time)                      ***/
/***   ====================                                                     ***/
/***   =    StopWatch     =    <-- Title Bar, might be removed in 128 x 128 Scr ***/
/***   ====================                                                     ***/
/***   = A 00:01:12:33    =    <-- individual timer #1                          ***/
/***   = B 00:03:25:36    =    <-- individual timer #2                          ***/
/***   = C 00:02:56:11    =    <-- individual timer #3                          ***/
/***   = D 00:07:23:27    =    <-- individual timer #4  (list_watch[])          ***/
/***   ====================                                                     ***/
/***   == LSK ==||== RSK ==                                                     ***/
/***   ====================                                                     ***/
/***                                                                            ***/
/***                                                                            ***/
/**********************************************************************************/

#define NWAY_TIME_FONT gui_font_get_type(GUI_FONT_SIZE_STOPWATCH_NWAY_TIME)
#define NWAY_TIME_HILITE gui_font_get_type(GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE)

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* Timer Variable Declearation */
static UI_stop_watch title_time;                            /* Main Timer */
static UI_stop_watch list_watch[MAX_MULTIPURPOSE_TIMER];    /* Individual Timer */

/* coordinate in category306, allocate memory in show category and free in exit function */
cat306_screen_info_cntx *cat306_cntx_ptr = NULL;

/* The current highligh timer index */
static S32 current_stop_watch_highlight = 0;

/* Using in increement timer */
static DOUBLE gTypTimerLogMSecValue = 0;
static DOUBLE gMPTimerLogMSecValue = 0;

/***************************************************************************** 
* Local Function Defination
*****************************************************************************/
void update_stop_watch_time(void);
void display_stop_watch_list_content(S32, S32, S32, S32);
void clean_active_timer(void);
void draw_stopwatch_title(void);
void redraw_stop_watch_list(void);
static S32 category306_get_text_y_offset(S32 idx);
static S32 category306_get_img_y_offset(S32 idx);
static S32 category306_get_timer_text_width(S32 idx);

/*****************************************************************************
 * FUNCTION
 *  GetMultipurposeTimeValues
 * DESCRIPTION
 *  This function is to retrieve current active timer
 *  Call by Application
 * PARAMETERS
 *  high_light      [OUT]     get highlight index 
 * RETURNS
 *  void
 *****************************************************************************/
void GetMultipurposeTimeValues(S32 *high_light)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *high_light = current_stop_watch_highlight;
}


/*****************************************************************************
 * FUNCTION
 *  stop_multipurpose_timers
 * DESCRIPTION
 *  This function is to stop current active timer
 *  Call by Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void stop_multipurpose_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    stop_play_flag = TIMER_STOP;
}


/*****************************************************************************
 * FUNCTION
 *  start_multipurpose_list_watch
 * DESCRIPTION
 *  This function is to start certain individual timer
 * PARAMETERS
 *  index       [IN]        index of stop watch
 * RETURNS
 *  void
 *****************************************************************************/
void start_multipurpose_list_watch(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    if (stop_play_flag == TIMER_STOP)
    {
        kal_get_time(&gMPInitialTime);

        stop_play_flag = TIMER_START;
    }
    else
    {
        update_stop_watch_time();
        gui_cancel_timer(update_stop_watch_time);
    }
    current_stop_watch_highlight = index;
    gui_start_timer(STPWACH_UI_UPDATE_PERIOD, update_stop_watch_time);

    gui_lock_double_buffer();

    gui_reset_clip();
    gui_reset_text_clip();

    cat306_cntx_ptr->text_y_offset = category306_get_text_y_offset(current_stop_watch_highlight);
    cat306_cntx_ptr->img_y_offset = category306_get_img_y_offset(current_stop_watch_highlight);

    draw_stopwatch_title();
    redraw_stop_watch_list();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - MMI_button_bar_height);

}


/*****************************************************************************
 * FUNCTION
 *  set_stop_watch_history
 * DESCRIPTION
 *  This function is to set stopwatch history
 * PARAMETERS
 *  history_ID          [IN]        History ID
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
U8 set_stop_watch_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        UI_stop_watch_history *h = (UI_stop_watch_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            current_stop_watch_highlight = h->highlight_item;
            stop_play_flag = h->cur_stop_play_flag;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_stop_watch_history
 * DESCRIPTION
 *  This function is to get stopwatch history
 * PARAMETERS
 *  history_ID          [IN]         History ID
 *  history_buffer      [OUT]        History buffer to set
 * RETURNS
 *  void
 *****************************************************************************/
void get_stop_watch_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        UI_stop_watch_history *h = (UI_stop_watch_history*) history_buffer;

        h->history_ID = hID;
        h->cur_stop_play_flag = stop_play_flag;
        h->highlight_item = current_stop_watch_highlight;
    }
}


/*****************************************************************************
 * FUNCTION
 *  reset_all_multipurpose_time
 * DESCRIPTION
 *  This function is to reset all timer when long press LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_all_multipurpose_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(update_stop_watch_time);
    stop_play_flag = TIMER_STOP;

    /* Reset main timer */
    memset(&title_time, 0, sizeof(UI_stop_watch));

    /* Reset individual timer */
    for (index = 0; index < MAX_MULTIPURPOSE_TIMER; index++)
    {
        list_watch[index].hour = list_watch[index].mili_sec = list_watch[index].min = list_watch[index].sec = 0;
        memset(list_watch[index].watch_string, 0, 40);
    }

    current_stop_watch_highlight = 0;
    cat306_cntx_ptr->text_y_offset = category306_get_text_y_offset(current_stop_watch_highlight);
    cat306_cntx_ptr->img_y_offset = category306_get_img_y_offset(current_stop_watch_highlight);

    /* Update screen */
    gui_lock_double_buffer();

    change_stopwatchtime_to_string(
        title_time.mili_sec,
        title_time.hour,
        title_time.min,
        title_time.sec,
        title_time.watch_string,
        DISPLAY_MILISEC_TRUE);

    draw_stopwatch_title();
    redraw_stop_watch_list();

    gui_unlock_double_buffer();

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - MMI_button_bar_height);
}


/*****************************************************************************
 * FUNCTION
 *  clean_active_timer
 * DESCRIPTION
 *  This function is to clear (drew white background on) active individual timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clean_active_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(NWAY_TIME_HILITE);
    
    if (cat306_cntx_ptr->img_width == 0 || cat306_cntx_ptr->img_height == 0)
    {
        gdi_draw_solid_rect(
            0,
            cat306_cntx_ptr->text_y_offset,
            MMI_content_width,
            cat306_cntx_ptr->text_y_offset + cat306_cntx_ptr->text_hilite_height,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(
            cat306_cntx_ptr->text_x_offset,
            cat306_cntx_ptr->text_y_offset,
            cat306_cntx_ptr->text_x_offset + category306_get_timer_text_width(current_stop_watch_highlight),
            cat306_cntx_ptr->text_y_offset + cat306_cntx_ptr->text_hilite_height,
            GDI_COLOR_TRANSPARENT);   
    }
}


/*****************************************************************************
 * FUNCTION
 *  redraw_stop_watch_list
 * DESCRIPTION
 *  This function is to redraw the individual timer list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_stop_watch_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display_stop_watch_list_content(
        wtch_pos.nWay_dialog_start.x,
        wtch_pos.nWay_dialog_start.y,
        wtch_pos.nWay_dialog_end.x,
        wtch_pos.nWay_dialog_end.y);
}


/*****************************************************************************
 * FUNCTION
 *  display_stop_watch_list_content
 * DESCRIPTION
 *  This function is nWay stopwatch to drew individual timer
 * PARAMETERS
 *  x1      [IN]        start x
 *  y1      [IN]        start y
 *  x2      [IN]        end x
 *  y2      [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
void display_stop_watch_list_content(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 list_y = 0;
    S32 img_y = 0, text_x = 0, text_y = 0, text_width = 0;
    PU8 cur_image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == MP_TIMER_SCR)
    {
        list_y = y1 + wtch_pos.separator_height;

        gdi_draw_solid_rect(
            x1 + STPWACH_NW_FRAM_BORDER,
            list_y + STPWACH_NW_FRAM_BORDER,
            x2 - STPWACH_NW_FRAM_BORDER,
            y2 - STPWACH_NW_FRAM_BORDER,
            GDI_COLOR_TRANSPARENT);

        for (index = 0; index < MAX_MULTIPURPOSE_TIMER; index++)
        {
            img_y = category306_get_img_y_offset(index);
            text_y = category306_get_text_y_offset(index);

            if (index == current_stop_watch_highlight)
            {
                clean_active_timer();
                cur_image = (PU8) list_watch[index].highlightimagedata;
                gui_set_text_color((*current_MMI_theme->stopwatch_active_timer_text_color));
                gui_set_font(NWAY_TIME_HILITE);
            }
            else
            {
                color text_grey = (*current_MMI_theme->stopwatch_inactive_timer_text_color);
                cur_image = (PU8) list_watch[index].normalimagedata;
                gui_set_text_color(text_grey);
                gui_set_font(NWAY_TIME_FONT);
            }

            /* Make timer string */
            change_stopwatchtime_to_string(
                list_watch[index].mili_sec,
                list_watch[index].hour,
                list_watch[index].min,
                list_watch[index].sec,
                list_watch[index].watch_string,
                DISPLAY_MILISEC_TRUE);

            text_width = category306_get_timer_text_width(index);

            if (cat306_cntx_ptr->img_width == 0 || cat306_cntx_ptr->img_height == 0)
            {
                /* Center */
                text_x = ((MMI_content_width - text_width) >> 1);
            }
            else
            {
                text_x = cat306_cntx_ptr->text_x_offset;
            }
            
            /* Draw image */
            gui_show_image(cat306_cntx_ptr->img_x_offset, img_y, cur_image);

            /* Draw text */
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(text_x + text_width, text_y);
            }
            else
            {
                gui_move_text_cursor(text_x, text_y);
            }

            gui_print_text((UI_string_type) list_watch[index].watch_string);

        }   /* end of for loop */
    }

}


/*****************************************************************************
 * FUNCTION
 *  draw_stopwatch_title
 * DESCRIPTION
 *  This function is to draw main timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_stopwatch_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == MP_TIMER_SCR)
    {
        S32 maintimer_height;
        S32 title_x, title_y;

        maintimer_height =
            wtch_pos.nWay_maintimer_end.y - wtch_pos.nWay_maintimer_start.y - (STPWACH_NW_FRAM_BORDER << 1);

        gdi_draw_solid_rect(
            wtch_pos.nWay_maintimer_start.x + STPWACH_NW_FRAM_BORDER,
            wtch_pos.nWay_maintimer_start.y + STPWACH_NW_FRAM_BORDER,
            wtch_pos.nWay_maintimer_end.x - STPWACH_NW_FRAM_BORDER,
            wtch_pos.nWay_maintimer_end.y - STPWACH_NW_FRAM_BORDER,
            GDI_COLOR_TRANSPARENT);

        gui_set_font(gui_font_get_type(GUI_FONT_SIZE_STOPWATCH_DURATION));        
        width = gui_get_string_width((UI_string_type) MMI_title_string);
        
        /* Main timer start x, y coordinate */
        title_x = wtch_pos.nWay_maintimer_start.x + STPWACH_NW_FRAM_BORDER
            + ((wtch_pos.nWay_maintimer_end.x - wtch_pos.nWay_maintimer_start.x - width) >> 1);

        title_y = wtch_pos.nWay_maintimer_start.y + STPWACH_NW_FRAM_BORDER
            + ((maintimer_height >> 1) - (cat306_cntx_ptr->text_height >> 1));

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(title_x + width, title_y);
        }
        else
        {
            gui_move_text_cursor(title_x, title_y);
        }

        gui_set_text_color(*current_MMI_theme->title_text_color);
        gui_set_text_border_color(*current_MMI_theme->title_text_border_color);

        MMI_title_string = (UI_string_type) title_time.watch_string;
        gui_print_bordered_text((UI_string_type) MMI_title_string);
    }
}


/*****************************************************************************
 * FUNCTION
 *  increment_time_stopwatch
 * DESCRIPTION
 *  This function is to increase time different for certain timer record
 * PARAMETERS
 *  stop_watch      [IN/OUT]     stop watch struct
 * RETURNS
 *  void
 *****************************************************************************/
void increment_time_stopwatch(UI_stop_watch *stop_watch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        U32 initTime = 0, currTime = 0;
        DOUBLE TotalTime;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        if (gDoNotIncrement == TYP_TIMER_INCREMENT || gDoNotIncrement == NO_INCREMENT)
        {
            initTime = gInitialTime;
            currTime = gCurrentTime;
        }
        else if (gDoNotIncrement == MP_TITLE_TIME_INCREMENT || gDoNotIncrement == MP_LIST_TIMER_INCREMENT)
        {
            initTime = gMPInitialTime;
            currTime = gMPCurrentTime;
        }

        if (initTime > currTime)
        {
            TotalTime = (0xffffffff - initTime) + currTime;
        }
        else
        {
            TotalTime = currTime - initTime;
        }

        TotalTime = TotalTime * 4.6153846;
        if (TotalTime >= 10)
        {
            stop_watch->mili_sec += (U32) TotalTime / 10;
            TotalTime = TotalTime - ((U32) TotalTime / 10) * 10;
        }
        if (TotalTime)
        {
            if (gDoNotIncrement == TYP_TIMER_INCREMENT)
            {
                gTypTimerLogMSecValue = gTypTimerLogMSecValue + TotalTime;
                if (gTypTimerLogMSecValue >= 10.0)
                {
                    stop_watch->mili_sec++;
                    gTypTimerLogMSecValue = gTypTimerLogMSecValue - 10.0;
                }
            }
            else if (gDoNotIncrement == MP_TITLE_TIME_INCREMENT || gDoNotIncrement == MP_LIST_TIMER_INCREMENT)
            {
                if (gDoNotIncrement == MP_TITLE_TIME_INCREMENT)
                {
                    gMPTimerLogMSecValue = gMPTimerLogMSecValue + TotalTime;
                }
                if (gMPTimerLogMSecValue >= 10.0)
                {
                    stop_watch->mili_sec++;
                    if (gDoNotIncrement == MP_LIST_TIMER_INCREMENT)
                    {
                        gMPTimerLogMSecValue = gMPTimerLogMSecValue - 10.0;
                    }
                }
            }
        }
    }

    if (stop_watch->mili_sec >= 100)
    {
        stop_watch->sec += stop_watch->mili_sec / 100;
        stop_watch->mili_sec -= (stop_watch->mili_sec / 100) * 100;
        if (stop_watch->sec >= 60)
        {
            stop_watch->min += stop_watch->sec / 60;
            stop_watch->sec -= (stop_watch->sec / 60) * 60;
            if (stop_watch->min >= 60)
            {
                stop_watch->hour += stop_watch->min / 60;
                stop_watch->min -= (stop_watch->min / 60) * 60;
                if (stop_watch->hour >= 100)
                {
                    stop_watch->hour = 0;
                }
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  UpdateMPTime
 * DESCRIPTION
 *  This function is to start timer to update stopwatch screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateMPTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stop_play_flag == TIMER_START)
    {
        kal_get_time(&gMPCurrentTime);
        gDoNotIncrement = MP_TITLE_TIME_INCREMENT;

        increment_time_stopwatch(&title_time);

        gDoNotIncrement = MP_LIST_TIMER_INCREMENT;

        increment_time_stopwatch(&list_watch[current_stop_watch_highlight]);

        gMPInitialTime = gMPCurrentTime;

        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, update_stop_watch_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_stop_watch_time
 * DESCRIPTION
 *  This function UI update timeout handler (every STPWACH_UI_UPDATE_PERIOD )
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_stop_watch_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_x = 0,text_width = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateMPTime();

    /* See the stopwatch is running in the background or not */
    if (g_current_screen == MP_TIMER_SCR)
    {
        gui_lock_double_buffer();

        clean_active_timer();

        /* update main timer string */
        change_stopwatchtime_to_string(
            title_time.mili_sec,
            title_time.hour,
            title_time.min,
            title_time.sec,
            title_time.watch_string,
            DISPLAY_MILISEC_TRUE);

        /* update active individual timer string */
        change_stopwatchtime_to_string(
            list_watch[current_stop_watch_highlight].mili_sec,
            list_watch[current_stop_watch_highlight].hour,
            list_watch[current_stop_watch_highlight].min,
            list_watch[current_stop_watch_highlight].sec,
            list_watch[current_stop_watch_highlight].watch_string,
            DISPLAY_MILISEC_TRUE);

        /* Draw main timer */
        draw_stopwatch_title();

        gui_set_font(NWAY_TIME_HILITE);
        gui_set_text_color((*current_MMI_theme->stopwatch_active_timer_text_color));

        text_width = category306_get_timer_text_width(current_stop_watch_highlight);
        
        if (cat306_cntx_ptr->img_width == 0 || cat306_cntx_ptr->img_height == 0)
        {
            /* Center */
            text_x = ((MMI_content_width - text_width) >> 1);
        }
        else
        {
            text_x = cat306_cntx_ptr->text_x_offset;
        }

        /* Move cursor */
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(text_x + text_width, cat306_cntx_ptr->text_y_offset);
        }
        else
        {
            gui_move_text_cursor(text_x, cat306_cntx_ptr->text_y_offset);
        }

        /* Draw timer text */
        gui_print_text((UI_string_type) list_watch[current_stop_watch_highlight].watch_string);

        gui_unlock_double_buffer();

        gui_BLT_double_buffer(
            wtch_pos.nWay_maintimer_start.x,
            wtch_pos.nWay_maintimer_start.y,
            wtch_pos.nWay_maintimer_end.x,
            wtch_pos.nWay_maintimer_end.y);

        gui_BLT_double_buffer(
            wtch_pos.nWay_dialog_start.x,
            cat306_cntx_ptr->text_y_offset,
            wtch_pos.nWay_dialog_end.x,
            cat306_cntx_ptr->text_y_offset + cat306_cntx_ptr->area_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory306Screen
 * DESCRIPTION
 *  This function is nWay stopwatch exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory306Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cat306_cntx_ptr != NULL)
    {    
        applib_mem_screen_free(cat306_cntx_ptr);
    }
    cat306_cntx_ptr = NULL;
    gui_cancel_timer(update_stop_watch_time);
    g_current_screen = NOT_STOPWATCH_SCR;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat306_draw_control_area
 * DESCRIPTION
 *  This function is redraw 306 control area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat306_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_128X128__   
#ifdef __PLUTO_MMI_PACKAGE__
    gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
    gdi_image_draw_id(STPWACH_NWAY_CONTROL_AREA_X, STPWACH_NWAY_CONTROL_AREA_Y, IMG_STOPWATCH_NWAY_BG);
    gdi_layer_pop_and_restore_active();
    old_bg_filler = NULL;
#endif
#endif /* __MMI_MAINLCD_128X128__ */
    /* main-timer coordinates */
    wtch_pos.nWay_maintimer_start.x = STPWACH_NWAY_MAINTIMER_START_X;
    wtch_pos.nWay_maintimer_start.y = STPWACH_NWAY_MAINTIMER_START_Y;
    wtch_pos.nWay_maintimer_end.x = STPWACH_NWAY_MAINTIMER_END_X;
    wtch_pos.nWay_maintimer_end.y = STPWACH_NWAY_MAINTIMER_END_Y;

    /* list-timer coordinates */
    wtch_pos.nWay_dialog_start.x = STPWACH_NWAY_LISTTIMER_START_X;
    wtch_pos.nWay_dialog_start.y = STPWACH_NWAY_LISTTIMER_START_Y;
    wtch_pos.nWay_dialog_end.x = STPWACH_NWAY_LISTTIMER_END_X;
    wtch_pos.nWay_dialog_end.y = STPWACH_NWAY_LISTTIMER_END_Y;
    wtch_pos.separator_height = STPWACH_NWAY_SEPARATOR_HEIGHT;

    /* the height of each list-timer */
    cat306_cntx_ptr->area_height =
        ((wtch_pos.nWay_dialog_end.y - wtch_pos.nWay_dialog_start.y -
          wtch_pos.separator_height) / MAX_MULTIPURPOSE_TIMER);

    /* Text start position */
    cat306_cntx_ptr->text_y_offset = category306_get_text_y_offset(current_stop_watch_highlight);
    cat306_cntx_ptr->text_x_offset = wtch_pos.nWay_dialog_start.x + STPWACH_NW_FRAM_BORDER +
        ((wtch_pos.nWay_dialog_end.x - wtch_pos.nWay_dialog_start.x - cat306_cntx_ptr->img_width -
          cat306_cntx_ptr->text_width - (STPWACH_NW_FRAM_BORDER << 1)) >> 1) +
        cat306_cntx_ptr->img_width + STPWACH_NW_FRAM_BORDER * 2;

    /* Image start position */
    cat306_cntx_ptr->img_x_offset = cat306_cntx_ptr->text_x_offset - cat306_cntx_ptr->img_width - STPWACH_NW_FRAM_BORDER * 2;
    cat306_cntx_ptr->img_y_offset = category306_get_img_y_offset(current_stop_watch_highlight);

    /* Draw main timer */
    draw_stopwatch_title();

    /* Draw individual timer */
    redraw_stop_watch_list();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory306Screen
 * DESCRIPTION
 *  This function is to Display nWay stopwatch
 * PARAMETERS
 *  title_values            [IN]        Title string 
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  stop_watch_list         [IN]        Stopwatch list
 *  history_buffer          [IN]        History buffer
 *  highlight_item          [IN]        Default highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory306Screen(
        UI_stop_watch *title_values,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        UI_stop_watch *stop_watch_list,
        U8 *history_buffer,
        S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory306PanelScreen(
        title_values,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        stop_watch_list,
        NULL, 
        history_buffer,
        highlight_item);
}


#if defined(__MMI_CAT_STOPWATCH_PANEL__)
static S32 wgui_catsw_panel_handle;
const S32 panel_button_position_catsw[3][4] = 
{
    {0,  386,106,57 },
    {106,386,108,57 },
    {214,386,106,57 }
};

/*****************************************************************************
 * FUNCTION
 *  wgui_catsw_general_key_handler
 * DESCRIPTION
 *  category 307 panel key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_catsw_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    gui_panel_struct* panel;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    panel = dm_get_panel(wgui_catsw_panel_handle);
    gui_panel_general_key_handler(panel, keycode, keytype);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catsw_update_panel
 * DESCRIPTION
 *  stopwatch category update panel data
 * PARAMETERS
 *  panel_area_data         [IN]        Panel struct
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_catsw_update_panel(wgui_panel_area_struct *panel_area_data)
{
    S32 i;
    gui_util_painter_struct disable_painter, off_painter, on_painter, down_painter;
    gui_panel_struct* panel;

    
    gui_lock_double_buffer();   
    for(i = 0; i < panel_area_data->num_of_element; i++)
    {
        gui_util_painter_create_imageid(&disable_painter, panel_area_data->element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, panel_area_data->element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, panel_area_data->element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, panel_area_data->element_list[i].down_imageid);

        dm_update_panel_element(
                wgui_catsw_panel_handle, 
                i, 
                panel_area_data->element_list[i].keycode,
                panel_area_data->element_list[i].down_event_callback,
                panel_area_data->element_list[i].up_event_callback,
                panel_area_data->element_list[i].repeat_event_callback,
                off_painter,
                on_painter,
                down_painter,
                disable_painter);
        dm_set_panel_enable_element(wgui_catsw_panel_handle, i, panel_area_data->element_list[i].enabled, MMI_FALSE); 
    }    
    panel = dm_get_panel(wgui_catsw_panel_handle);
    gui_panel_show(panel);
    gui_unlock_double_buffer();
    
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - MMI_button_bar_height);
}

#endif /* defined(__MMI_CAT_STOPWATCH_PANEL__) */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory306PanelScreen
 * DESCRIPTION
 *  This function is to Display nWay stopwatch
 * PARAMETERS
 *  title_values            [IN]        Title string 
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  stop_watch_list         [IN]        Stopwatch list
 *  history_buffer          [IN]        History buffer
 *  highlight_item          [IN]        Default highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory306PanelScreen(
        UI_stop_watch *title_values,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        UI_stop_watch *stop_watch_list,
        wgui_panel_area_struct *panel_area_data, 
        U8 *history_buffer,
        S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S32 img_width_1, img_height_1, img_width_2, img_height_2;
#if defined(__MMI_CAT_STOPWATCH_PANEL__)    
    gui_util_painter_struct bg_painter, disable_painter, off_painter, on_painter, down_painter;
    S32 i;
#endif /* defined(__MMI_CAT_STOPWATCH_PANEL__) */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat306_cntx_ptr = (cat306_screen_info_cntx *)applib_mem_screen_alloc(sizeof(cat306_screen_info_cntx));

    g_current_screen = MP_TIMER_SCR;
    UpdateMPTime();

    gui_lock_double_buffer();
    entry_full_screen();
    wgui_title_set_menu_shortcut_number(-1);
    clear_category_screen_key_handlers();

    gui_set_font(&MMI_medium_font);

    current_stop_watch_highlight = highlight_item;

    /* Make main timer string */
    change_stopwatchtime_to_string(
        title_time.mili_sec,
        title_time.hour,
        title_time.min,
        title_time.sec,
        title_time.watch_string,
        DISPLAY_MILISEC_TRUE);

    /* Full screen stopwatch, the screen title is main timer */
    MMI_title_string = (UI_string_type) title_time.watch_string;

    /* Store the icon ID in front of each individual timer */
    {
        U8 count = 0;

        for (count = 0; count < MAX_MULTIPURPOSE_TIMER; count++)
        {
            list_watch[count].normalimagedata = stop_watch_list[count].normalimagedata;
            list_watch[count].highlightimagedata = stop_watch_list[count].highlightimagedata;
        }
    }

#if defined(__MMI_CAT_STOPWATCH_PANEL__) && !defined(__MMI_FTE_SUPPORT__)
    /* Set panel position */
    for (i = 0; i< panel_area_data->num_of_element; i++)
    {
        panel_area_data->element_list[i].x = panel_button_position_catsw[i][0];
        panel_area_data->element_list[i].y = panel_button_position_catsw[i][1];
        panel_area_data->element_list[i].width = panel_button_position_catsw[i][2];
        panel_area_data->element_list[i].height = panel_button_position_catsw[i][3];
    }
    
    /* Panel Background */
    gui_util_painter_create_imageid(&bg_painter, panel_area_data->panel_bg_img_id);
    wgui_catsw_panel_handle = dm_add_panel(0, 0, UI_device_width, UI_device_height, bg_painter, MMI_FALSE, panel_area_data->repeat_period);
    /* add panel buttons */
    for(i = 0; i < panel_area_data->num_of_element; i++)
    {
        gui_util_painter_create_imageid(&disable_painter, panel_area_data->element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, panel_area_data->element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, panel_area_data->element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, panel_area_data->element_list[i].down_imageid);
        dm_add_panel_element(
            wgui_catsw_panel_handle,
            panel_area_data->element_list[i].x,
            panel_area_data->element_list[i].y,
            panel_area_data->element_list[i].width,
            panel_area_data->element_list[i].height,
            panel_area_data->element_list[i].keycode,
            panel_area_data->element_list[i].down_event_callback,
            panel_area_data->element_list[i].up_event_callback,
            panel_area_data->element_list[i].repeat_event_callback,
            off_painter,
            on_painter,
            down_painter,
            disable_painter,
            MMI_FALSE);
        dm_set_panel_enable_element(wgui_catsw_panel_handle, i, panel_area_data->element_list[i].enabled, MMI_FALSE); 
    }
    dm_register_panel_keys(wgui_catsw_panel_handle, wgui_catsw_general_key_handler);
#else /* defined(__MMI_STOPWATCH_PANEL__) */ 
    UI_UNUSED_PARAMETER(panel_area_data);
#endif /* defined(__MMI_STOPWATCH_PANEL__) */ 

    /* Store the screen information */
    gui_measure_image((PU8) list_watch[0].normalimagedata, &img_width_1, &img_height_1);
    gui_measure_image((PU8) list_watch[0].highlightimagedata, &img_width_2, &img_height_2);

    gui_set_font(NWAY_TIME_FONT);
    cat306_cntx_ptr->text_width = gui_get_string_width((UI_string_type) MMI_title_string);
    cat306_cntx_ptr->text_height = gui_get_character_height();

    gui_set_font(NWAY_TIME_HILITE);
    cat306_cntx_ptr->text_hilite_height = gui_get_character_height();

    ASSERT((img_width_1 == img_width_2) && (img_height_1 == img_height_2));

    cat306_cntx_ptr->img_height = img_height_1;
    cat306_cntx_ptr->img_width = img_width_1;

    /* Set key handler  */
    dm_add_softkey_id(left_softkey, right_softkey);

    h_flag = set_stop_watch_history(MMI_CATEGORY306_ID, history_buffer);

    gui_unlock_double_buffer();

    dm_register_category_controlled_callback(wgui_cat306_draw_control_area);
    /* Register screen function pointer */
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(wgui_stopwatch_pen_down_handler);
#endif
    
    wgui_cat_setup_category(MMI_CATEGORY306_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory306Screen, get_category306_history, get_category306_history_size);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  get_category306_history
 * DESCRIPTION
 *  This function is used by draw manager to get history.
 * PARAMETERS
 *  history_buffer      [IN/OUT]        Buffer of history data.
 * RETURNS
 *  U8 history
 *****************************************************************************/
U8 *get_category306_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_stop_watch_history((U16)MMI_CATEGORY306_ID, history_buffer);
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  get_category306_history_size
 * DESCRIPTION
 *  This function is used by draw manager to get history size.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32                 history size
 *****************************************************************************/
S32 get_category306_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(UI_stop_watch_history));
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_stopwatch_pen_down_handler
 * DESCRIPTION
 *  Handles Pen Down Event on nWay Stopwatch
 * PARAMETERS
 *  point       [IN]        Pen's position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_stopwatch_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* list-timer handlers */
    if (wgui_stopwatch_get_active_timer_index(point, &index) == MMI_TRUE)
    {
#ifdef __PLUTO_MMI_PACKAGE__
        gStopwatchAppInfo.currentTimerIndex = index;
        StartIndexTimer();
        start_multipurpose_list_watch((U8) index);
#endif
    }
    /* softkey handlers */
    wgui_general_pen_down_hdlr(point);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_stopwatch_pen_down_hdlr
 * DESCRIPTION
 *  Handles Pen Down Event on Stopwatch
 * PARAMETERS
 *  point       [IN]        Pen's position
 *  index       [OUT]       Index of Timer
 * RETURNS
 *  MMI_BOOL True/False
 *****************************************************************************/
MMI_BOOL wgui_stopwatch_get_active_timer_index(mmi_pen_point_struct point, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    S32 posx = point.x, posy = point.y;
    S32 img_y, text_y;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == NOT_STOPWATCH_SCR)
    {
        return ret;
    }
    if (g_current_screen == MP_TIMER_SCR)
    {
        img_y = category306_get_img_y_offset(0);
        text_y = category306_get_text_y_offset(0);
        x1 = cat306_cntx_ptr->img_x_offset;
        y1 = (img_y < text_y) ? img_y : text_y;
        if (y1 < wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER)
        {
            y1 = wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER;
        }
        x2 = cat306_cntx_ptr->text_x_offset + cat306_cntx_ptr->text_width;
        img_y = category306_get_img_y_offset(MAX_MULTIPURPOSE_TIMER - 1);
        text_y = category306_get_text_y_offset(MAX_MULTIPURPOSE_TIMER - 1);
        y2 = (img_y + cat306_cntx_ptr->img_height) >
            (text_y + cat306_cntx_ptr->text_height) ? (img_y + cat306_cntx_ptr->img_height) : (text_y + cat306_cntx_ptr->text_height);
        if (y2 > wtch_pos.nWay_dialog_end.y - STPWACH_NW_FRAM_BORDER)
        {
            y2 = wtch_pos.nWay_dialog_end.y - STPWACH_NW_FRAM_BORDER;
        }
    }
    if (posx >= x1 && posx <= x2 && posy >= y1 && posy <= y2)
    {
        ret = gui_stopwatch_translate_penevent(point.x, point.y, index);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_stopwatch_translate_penevent
 * DESCRIPTION
 *  Finds the index of Stopwatch Timer
 * PARAMETERS
 *  x           [IN]        Pen's x position
 *  y           [IN]        Pen's y position
 *  index       [OUT]         Index of Timer
 * RETURNS
 *  MMI_BOOL True/False
 *****************************************************************************/
MMI_BOOL gui_stopwatch_translate_penevent(S32 x, S32 y, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_screen == MP_TIMER_SCR)
    {
        S32 y1, y2, i;
        S32 img_y, text_y;

        for (i = 0; i < MAX_MULTIPURPOSE_TIMER; i++)
        {
            img_y = category306_get_img_y_offset(i);
            text_y = category306_get_text_y_offset(i);
            y1 = (img_y < text_y) ? img_y : text_y;
            y2 = (y1 + cat306_cntx_ptr->text_height >
                  y1 + cat306_cntx_ptr->img_height) ? (y1 + cat306_cntx_ptr->text_height) : (y1 + cat306_cntx_ptr->img_height);
            if (y >= y1 && y <= y2)
            {
                *index = i;
                ret = MMI_TRUE;
                break;
            }
        }
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


///TODO: Should be delete after "Wgui_touch_screen.c" and "wgui_draw_manager.c" revised
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL wgui_stopwatch_pen_down_hdlr(mmi_pen_point_struct point, S32 *index)
{
    return MMI_TRUE;
}
#endif

void show_nway_stop_watch(void)
{
    return;
}

void show_typical_stop_watch(void)
{
    return;
}
///TODO: END


/*****************************************************************************
 * FUNCTION
 *  category306_get_text_y_offset
 * DESCRIPTION
 *  This function is to get active timer text y coordinator
 * PARAMETERS
 *  idx     [IN]        index of list
 * RETURNS
 *  void
 *****************************************************************************/
static S32 category306_get_text_y_offset(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER)
        + (idx * cat306_cntx_ptr->area_height) + (cat306_cntx_ptr->area_height >> 1) - (cat306_cntx_ptr->text_height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  category306_get_img_y_offset
 * DESCRIPTION
 *  This function is to get active timer imgage y coordinator
 * PARAMETERS
 *  idx     [IN]        index of list
 * RETURNS
 *  void
 *****************************************************************************/
static S32 category306_get_img_y_offset(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wtch_pos.nWay_dialog_start.y + wtch_pos.separator_height + STPWACH_NW_FRAM_BORDER)
        + (idx * cat306_cntx_ptr->area_height) + (cat306_cntx_ptr->area_height >> 1) - (cat306_cntx_ptr->img_height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  category306_get_timer_text_width
 * DESCRIPTION
 *  This function is to get active timer imgage y coordinator
 * PARAMETERS
 *  idx     [IN]        index of list
 * RETURNS
 *  void
 *****************************************************************************/
static S32 category306_get_timer_text_width(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_get_string_width((UI_string_type) list_watch[idx].watch_string);
}

/*****************************************************************************/
/***  Typical Stopwatch                                                    ***/
/*****************************************************************************/

/**********************************************************************************/
/*** Typical Stopwatch Screen                                                   ***/
/*** Screen ID: 307                                                             ***/
/**********************************************************************************/
/***                                                                            ***/
/***                                                                            ***/
/***   CategoryScreen307:                                                       ***/
/***                                                                            ***/
/***   ====================                                                     ***/
/***   = Split/Lap 1      =     <--   Split/Lap window, the number of items is  ***/
/***   = Split/Lap 2      =         depends on screen size. In 128x128 and 120  ***/
/***   = Split/Lap 3      =         x160, there are 2 itmes. In 176x220, there  ***/
/***   = ...              =         are 4 items. It is adjusting dynamically.   ***/
/***   ====================                                                     ***/
/***   =  xx xxxxxxxx xx  =                                                     ***/
/***   =  xxxxxxxxxxxxxx  =                                                     ***/
/***   =   x==========x   =                                                     ***/
/***   =   x 10:22:03 x   =     <--   Main window, with a background image and  ***/
/***   =   x    50    x   =          timer running on it. Because there is no   ***/
/***   =   x==========x   =          image cache mechanism implemented, suggest ***/
/***   =  xxxxxxxxxxxxxx  =          use plan color as background color.        ***/
/***   =  xx xxxxxxxx xx  =                                                     ***/
/***   ====================                                                     ***/
/***   == LSK ==||== RSK ==                                                     ***/
/***   ====================                                                     ***/
/***                                                                            ***/
/***                                                                            ***/
/**********************************************************************************/

#define TYP_TIME_FONT gui_font_get_type(GUI_FONT_SIZE_STOPWATCH_DURATION)

/* Timer Variable Declearation */
S32 start_timer_again;
U8  timer_flag_stop_start;
U8  gResetTimer;
S32 stop_watch_total_frames;
S32 stop_watch_n_frame;
cat307_screen_info_cntx *cat307_cntx_ptr = NULL;
S32 center_mili = 0, center_sec = 0, center_hr = 0, center_min = 0;

/***************************************************************************** 
* Local Function Defination
*****************************************************************************/
void stop_watch_animation_processor(void);
void show_center_time(void);


/*****************************************************************************
 * FUNCTION
 *  reset_timer
 * DESCRIPTION
 *  reset timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(show_center_time);

#ifndef __MMI_FTE_SUPPORT__
    memset(cat307_cntx_ptr->watch_string, 0, sizeof(cat307_cntx_ptr->watch_string));
    memset(category89_string_list, 0, (MAX_CATEGORY89_STRINGS * MAX_CATEGORY89_STRING_LENGTH));
#endif

    timer_flag_stop_start = TIMER_STOP;
    center_mili = center_sec = center_hr = center_min = 0;

    show_center_time();

    remove_all_fixed_icontext_item();
    MMI_fixed_list_menu.highlighted_item = -1;
    show_fixed_list();
    gResetTimer = 1;

    if (stop_watch_total_frames > 1)
    {
        stop_watch_n_frame = -1;
        stop_watch_animation_processor();
    }

    /* Gurinder - 28/4/2004 - Stop Scroll Timer On List Reset. */
    wgui_text_menuitem_reset_scrolling();
}


/*****************************************************************************
 * FUNCTION
 *  initialize_stop_watch_timer
 * DESCRIPTION
 *  Initialize timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_stop_watch_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(stop_watch_animation_processor);
    gui_cancel_timer(show_center_time);
    timer_flag_stop_start = TIMER_STOP;

    center_mili = center_hr = center_min = center_sec = 0;
 
    if (stop_watch_total_frames > 1)
    {
        stop_watch_n_frame = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UpdateHistoryValue
 * DESCRIPTION
 *  update history value
 * PARAMETERS
 *  mili        [IN]     mile second
 *  hr          [IN]     hour
 *  min         [IN]     minute
 *  sec         [IN]     second
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateHistoryValue(S32 *mili, S32 *hr, S32 *min, S32 *sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total = 0, index = 0;
    U32 TempPrevCurrentValue = 0;
    UI_stop_watch temp_watch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_watch.hour = center_hr;
    temp_watch.mili_sec = center_mili;
    temp_watch.min = center_min;
    temp_watch.sec = center_sec;

    TempPrevCurrentValue = gCurrentTime;
    kal_get_time(&gCurrentTime);
    gDoNotIncrement = NO_INCREMENT;

    increment_time_stopwatch(&temp_watch);

    gCurrentTime = TempPrevCurrentValue;

    *mili = temp_watch.mili_sec;
    *hr = temp_watch.hour;
    *min = temp_watch.min;
    *sec = temp_watch.sec;

    if (start_timer_again == STOP_START_AGAIN)
    {
        center_mili = center_hr = center_min = center_sec = 0;
        gResetTimer = 1;
        kal_get_time(&gInitialTime);
    }

    if (g_current_screen == TYPICAL_TIMER_SCR)
    {
        wgui_title_set_menu_shortcut_number(-1);

        total = fixed_icontext_list_menuitem_total();

        if (total > 0)
        {
            index = total;
        }
        else
        {
            index = 0;
        }

        fixed_icontext_list_item_insert(index);
        gui_itoa(total + 1, (UI_string_type) category89_string_list[index], 10);
        gui_strcat((UI_string_type) category89_string_list[index], (UI_string_type) ".\0");
        add_fixed_icontext_list_item_text(index, 0, (UI_string_type) category89_string_list[index]);

        change_stopwatchtime_to_string(*mili, *hr, *min, *sec, cat307_cntx_ptr->watch_string[index], DISPLAY_MILISEC_TRUE);
        add_fixed_icontext_list_item_text(index, 1, (UI_string_type) cat307_cntx_ptr->watch_string[index]);
        MMI_fixed_icontext_list_menuitems[index].flags |= UI_MENUITEM_TEXT_COL1_IS_NUMBER;

        if (index == 0)
        {
            fixed_list_goto_item_no_redraw(index);
        }
        else
        {
            fixed_list_goto_item(index);
        }

        show_fixed_list();
        gui_BLT_double_buffer(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

    }
}


/*****************************************************************************
 * FUNCTION
 *  start_stop_watch_timer
 * DESCRIPTION
 *  start stop watch timer
 * PARAMETERS
 *  start_stop_flag     [IN]        stop or stop timer
 * RETURNS
 *  void
 *****************************************************************************/
void start_stop_watch_timer(U8 start_stop_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_stop_flag == TIMER_STOP)
    {
        gui_cancel_timer(show_center_time);
        if (timer_flag_stop_start == TIMER_START)
        {
            show_center_time();
        }
    }
    else if (start_stop_flag == TIMER_START)
    {
        kal_get_time(&gInitialTime);
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);

        if (stop_watch_total_frames > 1)
        {
            gui_start_timer(STOP_WATCH_ANIMATION_DELAY, stop_watch_animation_processor);
        }

    }
    timer_flag_stop_start = start_stop_flag;
}

U8 gMainTimeUpdatedFlag = 0;


/*****************************************************************************
 * FUNCTION
 *  UpdateTypicalTimer
 * DESCRIPTION
 *  update typical timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateTypicalTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_stop_watch temp_watch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timer_flag_stop_start == TIMER_START)
    {
        temp_watch.hour = center_hr;
        temp_watch.mili_sec = center_mili;
        temp_watch.min = center_min;
        temp_watch.sec = center_sec;

        kal_get_time(&gCurrentTime);
        gDoNotIncrement = TYP_TIMER_INCREMENT;
        increment_time_stopwatch(&temp_watch);
        gInitialTime = gCurrentTime;

        if ((center_hr == temp_watch.hour) && (center_min == temp_watch.min) && (center_sec == temp_watch.sec))
        {
            gMainTimeUpdatedFlag = 0;
        }
        else
        {
            gMainTimeUpdatedFlag = 1;
        }

        center_hr = temp_watch.hour;
        center_mili = temp_watch.mili_sec;
        center_min = temp_watch.min;
        center_sec = temp_watch.sec;
    }
}


#ifdef __MMI_FTE_SUPPORT__
static bitmap g_wgui_cat307_num_bg;
static U8 *g_wgui_cat307_num_bg_buf = NULL;
#else
static bitmap gdata_maintimer;
static bitmap gdata_millitimer;

static U8 *gbuffer_maintime = NULL;
static U8 *gbuffer_millitime = NULL;
#endif


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  print_center_time
 * DESCRIPTION
 *  draw center time
 * PARAMETERS
 *  need_redraw_all      [IN]  redraw all number at first time.
 * RETURNS
 *  void
 *****************************************************************************/
void print_center_time(MMI_BOOL need_redraw_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num[6];
    S32 i;
    S32 value;
    gdi_handle active_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateTypicalTimer();

    gdi_layer_lock_frame_buffer();

    gui_set_clip(
        0,
        MMI_STATUS_BAR_HEIGHT,
        UI_device_width -1,
        MMI_STATUS_BAR_HEIGHT + WGUI_CAT307_CONTROL_AREA_H);

    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);
    
    /* show the symbol */
    if (g_wgui_cat307_num_bg_buf == NULL)
    {
        MMI_ASSERT(0);
    }

    if (need_redraw_all)
    {
        _show_bitmap(cat307_cntx_ptr->symbol_image_x[2], cat307_cntx_ptr->num_image_y, &g_wgui_cat307_num_bg);
        gui_show_image(cat307_cntx_ptr->symbol_image_x[2], cat307_cntx_ptr->num_image_y, cat307_cntx_ptr->colon_image);
        
        _show_bitmap(cat307_cntx_ptr->symbol_image_x[1], cat307_cntx_ptr->num_image_y, &g_wgui_cat307_num_bg);
        gui_show_image(cat307_cntx_ptr->symbol_image_x[1], cat307_cntx_ptr->num_image_y, cat307_cntx_ptr->colon_image);
        
        _show_bitmap(cat307_cntx_ptr->symbol_image_x[0], cat307_cntx_ptr->num_image_y, &g_wgui_cat307_num_bg);
        gui_show_image(cat307_cntx_ptr->symbol_image_x[0], cat307_cntx_ptr->num_image_y, cat307_cntx_ptr->dot_image);
    }

    /* calculate the number for each position */
    num[5] = center_hr % 10;
    num[4] = center_min / 10;
    num[3] = center_min % 10;
    num[2] = center_sec / 10;
    num[1] = center_sec % 10;
    num[0] = center_mili / 10;

    /* show the number */
    _show_bitmap(cat307_cntx_ptr->num_image_x[0], cat307_cntx_ptr->num_image_y, &g_wgui_cat307_num_bg);
    gui_show_image(cat307_cntx_ptr->num_image_x[0], cat307_cntx_ptr->num_image_y, cat307_cntx_ptr->num_image[num[0]]);
    _show_bitmap(cat307_cntx_ptr->num_image_x[1], cat307_cntx_ptr->num_image_y, &g_wgui_cat307_num_bg);
    gui_show_image(cat307_cntx_ptr->num_image_x[1], cat307_cntx_ptr->num_image_y, cat307_cntx_ptr->num_image[num[1]]);

    for (i = 2; ((i < WGUI_CAT307_NUM_MAIN_TIMER) && (need_redraw_all || (num[i-1] == 0))); i++)
    {
        value = num[i];
        _show_bitmap(cat307_cntx_ptr->num_image_x[i], cat307_cntx_ptr->num_image_y, &g_wgui_cat307_num_bg);
        gui_show_image(cat307_cntx_ptr->num_image_x[i], cat307_cntx_ptr->num_image_y, cat307_cntx_ptr->num_image[value]);
    }
    
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  show_center_time
 * DESCRIPTION
 *  show center time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_center_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateTypicalTimer();
    
    if (g_current_screen == TYPICAL_TIMER_SCR)
    {
        gdi_layer_lock_frame_buffer();
        print_center_time(MMI_TRUE);

        gdi_layer_unlock_frame_buffer();
        gui_BLT_double_buffer(
            0,
            MMI_STATUS_BAR_HEIGHT,
            UI_device_width -1,
            MMI_STATUS_BAR_HEIGHT + WGUI_CAT307_CONTROL_AREA_H);
    }

    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
}
#else
/*****************************************************************************
 * FUNCTION
 *  print_center_time
 * DESCRIPTION
 *  draw center time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void print_center_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 time_string[TIMER_TEXT_SIZE];
    U8 mili_string[20], uni_mili_string[TIMER_TEXT_SIZE];
    color text_col = gui_color(0, 0, 0);
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateTypicalTimer();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_set_font(TYP_TIME_FONT);

    change_stopwatchtime_to_string(0, center_hr, center_min, center_sec, time_string, DISPLAY_MILISEC_FALSE);

    sprintf((S8*) mili_string, "%02d", center_mili);
    mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);

    gui_measure_string((UI_string_type) time_string, &w, &h);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(wtch_pos.typ_timer.x + w -1, wtch_pos.typ_timer.y);
    }
    else
    {
        gui_move_text_cursor(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y);
    }

    gui_set_text_color(text_col);
    gui_print_text((UI_string_type) time_string);

    gui_measure_string((UI_string_type) uni_mili_string, &w, &h);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(wtch_pos.typ_milsec.x + w - 1, wtch_pos.typ_milsec.y);
    }
    else
    {
        gui_move_text_cursor(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y);
    }

    gui_print_text((UI_string_type) uni_mili_string);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  show_center_time
 * DESCRIPTION
 *  show center time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_center_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w;
    U8 time_string[TIMER_TEXT_SIZE];
    U8 mili_string[20], uni_mili_string[TIMER_TEXT_SIZE];
    color text_col = gui_color(0, 0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateTypicalTimer();
    if (g_current_screen == TYPICAL_TIMER_SCR)
    {
        gui_lock_double_buffer();
        gui_reset_clip();
        gui_reset_text_clip();

        gui_set_font(TYP_TIME_FONT);

        gui_set_text_color(text_col);

        if (stop_watch_total_frames > 1)
        {
            if (gbuffer_maintime != NULL && gbuffer_millitime != NULL)
            {               
                _show_bitmap(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y, &gdata_maintimer);
                _show_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, &gdata_millitimer);
            }
            else
            {
                if (stop_watch_total_frames > 1)
                {
                    gui_show_animated_image_frame(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img), (S16) stop_watch_n_frame);
                }
                else
                {
                    gui_show_image(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img));
                }                
            }
            print_center_time();
        }
        else
        {
            if ((gMainTimeUpdatedFlag == 1) || (gResetTimer))
            {
                change_stopwatchtime_to_string(
                    0,
                    center_hr,
                    center_min,
                    center_sec,
                    time_string,
                    DISPLAY_MILISEC_FALSE);
                sprintf((S8*) mili_string, "%02d", center_mili);
                mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);

                if (gbuffer_maintime != NULL && gbuffer_millitime != NULL)
                {               
                    _show_bitmap(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y, &gdata_maintimer);
                    _show_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, &gdata_millitimer);
                }
                else
                {
                    if (stop_watch_total_frames > 1)
                    {
                        gui_show_animated_image_frame(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img), (S16) stop_watch_n_frame);
                    }
                    else
                    {
                        gui_show_image(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img));
                    }                
                }

                w = gui_get_string_width((UI_string_type) time_string);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(wtch_pos.typ_timer.x + w - 1, wtch_pos.typ_timer.y);
                }
                else
                {
                    gui_move_text_cursor(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y);
                }

                gui_print_text((UI_string_type) time_string);


                w = gui_get_string_width((UI_string_type) uni_mili_string);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x + w - 1, wtch_pos.typ_milsec.y);
                }
                else
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y);
                }

                gui_print_text((UI_string_type) uni_mili_string);
                gResetTimer = 0;
            }
            else
            {
                sprintf((S8*) mili_string, "%02d", center_mili);
                mmi_asc_to_ucs2((PS8) uni_mili_string, (PS8) mili_string);
                if (gbuffer_millitime != NULL)
                {                  
                    _show_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, &gdata_millitimer);
                }
                else
                {
                    gui_push_clip();
                    gui_set_clip(
                        wtch_pos.typ_milsec.x,
                        wtch_pos.typ_milsec.y,
                        (wtch_pos.typ_milsec.x + wtch_pos.typ_milsec.width - 1),
                        (wtch_pos.typ_milsec.y + wtch_pos.typ_milsec.height - 1));
                    if (stop_watch_total_frames > 1)
                    {
                        gui_show_animated_image_frame(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img), (S16) stop_watch_n_frame);
                    }
                    else
                    {
                        gui_show_image(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img));
                    }   
                    gui_pop_clip();
                }

                w = gui_get_string_width((UI_string_type) uni_mili_string);
                if (r2lMMIFlag)
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x + w - 1, wtch_pos.typ_milsec.y);
                }
                else
                {
                    gui_move_text_cursor(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y);
                }

                gui_print_text((UI_string_type) uni_mili_string);
            }
        }

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            cat307_cntx_ptr->image_x, 
            cat307_cntx_ptr->image_y,
            UI_device_width - 1,
            (UI_device_height - MMI_button_bar_height));
    }

    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
}
#endif/* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory307Screen
 * DESCRIPTION
 *  Exit category 307
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory307Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(show_center_time);

    gui_cancel_timer(stop_watch_animation_processor);

    ClearHighlightHandler();
    reset_softkeys();

#ifdef __MMI_FTE_SUPPORT__
    if (g_wgui_cat307_num_bg_buf != NULL)
    {        
        mmi_frm_scrmem_free(g_wgui_cat307_num_bg_buf);
    }
    g_wgui_cat307_num_bg_buf = NULL;
#else
    if (gbuffer_maintime != NULL)
    {        
        mmi_frm_scrmem_free(gbuffer_maintime);
    }
    if (gbuffer_millitime != NULL)
    {        
        mmi_frm_scrmem_free(gbuffer_millitime);
    }
    gbuffer_maintime = NULL;
    gbuffer_millitime = NULL;
#endif

    if (cat307_cntx_ptr != NULL)
    {   
        applib_mem_screen_free(cat307_cntx_ptr);
    }
    cat307_cntx_ptr = NULL;

    
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    g_current_screen = NOT_STOPWATCH_SCR;
    wgui_text_menuitem_reset_scrolling();
}


/*****************************************************************************
 * FUNCTION
 *  stop_watch_animation_processor
 * DESCRIPTION
 *  Draw Animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void stop_watch_animation_processor()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    int i;
    dm_coordinates history_list;
    PU8 stop_watch_img = get_image(cat307_cntx_ptr->bkg_img);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    stop_watch_n_frame++;
    if (stop_watch_n_frame >= stop_watch_total_frames)
    {
        stop_watch_n_frame = 0;
    }

    gui_cancel_timer(stop_watch_animation_processor);
    gui_cancel_timer(show_center_time);

    gui_lock_double_buffer();

    gui_reset_clip();
    gui_reset_text_clip();

    dm_get_control_coordinates_from_category(
        (S32)GetActiveScreenId(), 
        MMI_CATEGORY307_ID, 
        DM_LIST1, 
        0, 
        &history_list);
    gui_set_clip(0, history_list.s16Y + history_list.s16Height, UI_device_width - 1, UI_device_height - MMI_button_bar_height - 1);
    gui_draw_filled_area(
        0,
        history_list.s16Y + history_list.s16Height,
        UI_device_width - 1,
        UI_device_height - 1,
        current_MMI_theme->general_background_filler);

    for (i = 0; i <= stop_watch_n_frame; i++)
    {
        gdi_image_draw_animation_single_frame(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, stop_watch_img, (S16) i);
    }

   /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
   /***********************************************************/
   if (gbuffer_maintime != NULL)
   {
        memset(gbuffer_maintime, 0, sizeof(gbuffer_maintime));
        gdata_maintimer.data = gbuffer_maintime;
        _get_bitmap(
            wtch_pos.typ_timer.x,
            wtch_pos.typ_timer.y,
            (wtch_pos.typ_timer.x + wtch_pos.typ_timer.width - 1),
            (wtch_pos.typ_timer.y + wtch_pos.typ_timer.height - 1),
            &gdata_maintimer);
   }

   /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
   /***********************************************************/
   if (gbuffer_millitime != NULL)
   {   
        memset(gbuffer_millitime, 0, sizeof(gbuffer_millitime));
        gdata_millitimer.data = gbuffer_millitime;
        _get_bitmap(
            wtch_pos.typ_milsec.x,
            wtch_pos.typ_milsec.y,
            (wtch_pos.typ_milsec.x + wtch_pos.typ_milsec.width - 1),
            (wtch_pos.typ_milsec.y + wtch_pos.typ_milsec.height - 1),
            &gdata_millitimer);
   }

    print_center_time();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, (UI_device_height - MMI_button_bar_height));
    gui_start_timer(STOP_WATCH_ANIMATION_DELAY, stop_watch_animation_processor);

    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
#endif
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat307_draw_control_area
 * DESCRIPTION
 *  This function is redraw 307 control area(typical main timer)
 * PARAMETERS
 *  coordinate      [IN]  the area of the control area
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat307_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(show_center_time);
    
    /* the coordinate of time's background */
    cat307_cntx_ptr->image_x = (MAIN_LCD_DEVICE_WIDTH - cat307_cntx_ptr->image_width) >> 1;
    cat307_cntx_ptr->image_y = MMI_STATUS_BAR_HEIGHT;
    
    /* show the background of maintime and milsec-time */
    gui_set_clip(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, UI_device_width - 1, MMI_STATUS_BAR_HEIGHT + WGUI_CAT307_CONTROL_AREA_H);
    gui_show_image(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, get_image(cat307_cntx_ptr->bkg_img));

    /* get the background of time-text */
    if (g_wgui_cat307_num_bg_buf != NULL)
    {   
        memset(g_wgui_cat307_num_bg_buf, 0, sizeof(g_wgui_cat307_num_bg_buf));
        g_wgui_cat307_num_bg.data = g_wgui_cat307_num_bg_buf;
        _get_bitmap(cat307_cntx_ptr->num_image_x[0],
                     cat307_cntx_ptr->num_image_y,
                     cat307_cntx_ptr->num_image_x[0] + cat307_cntx_ptr->num_image_w,
                     cat307_cntx_ptr->num_image_y + cat307_cntx_ptr->num_image_h,
                     &g_wgui_cat307_num_bg); 
    }

    /* show the time-text */ 
    print_center_time(MMI_TRUE);

    /* start timer for time-text */
    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
}
#else
/*****************************************************************************
 * FUNCTION
 *  wgui_cat307_draw_control_area
 * DESCRIPTION
 *  This function is redraw 307 control area(typical main timer)
 * PARAMETERS
 *  coordinate      [IN]  the area of the control area
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat307_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
    PU8 stop_watch_img = (PU8) GetImage(cat307_cntx_ptr->bkg_img);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(stop_watch_animation_processor);
    gui_cancel_timer(show_center_time);

    /* the coordinate of time's background */
    cat307_cntx_ptr->image_x = (MAIN_LCD_DEVICE_WIDTH - cat307_cntx_ptr->image_width) >> 1;
    cat307_cntx_ptr->image_y = WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH - (cat307_cntx_ptr->image_height>> 1);

    /* reset maintime position */
    wtch_pos.typ_timer.x = WGUI_CAT_SW_TYP_TIMER_X;
    wtch_pos.typ_timer.y = WGUI_CAT_SW_TYP_TIMER_Y;

    /* reset milsec position */
    wtch_pos.typ_milsec.x = WGUI_CAT_SW_TYP_MILSEC_X;
    wtch_pos.typ_milsec.y = WGUI_CAT_SW_TYP_MILSEC_Y;
    
    /* show the background of maintime and milsec-time */
    gui_set_clip(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_x, UI_device_width - 1, UI_device_height - MMI_button_bar_height);
    if (stop_watch_total_frames > 1)
    {
        gui_show_animated_image_frame(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, stop_watch_img, (S16) stop_watch_n_frame);
    }
    else
    {
        gui_show_image(cat307_cntx_ptr->image_x, cat307_cntx_ptr->image_y, stop_watch_img);
    }    

    /* adjust the position for mediacy */
    /***********************************************************/
    /* Notices!!!                                              */
    /* Change the X,Y offset should change the buffer size of  */
    /* gbuffer_millitime[] and gbuffer_maintime[] as well      */
    /***********************************************************/
    gui_set_font(TYP_TIME_FONT);
    mmi_fe_measure_string_by_char_num((U8*)(L"0123456789:"), 8, &width, &height);
    wtch_pos.typ_timer.height = height;
    wtch_pos.typ_timer.width = width;
    wtch_pos.typ_timer.x -= (wtch_pos.typ_timer.width >> 1);
    mmi_fe_measure_string_by_char_num((U8*)(L"0123456789"), 3, &width, &height);
    wtch_pos.typ_milsec.height = height;
    wtch_pos.typ_milsec.width = width;
    wtch_pos.typ_milsec.x -= (wtch_pos.typ_milsec.width >> 1);

    /* get the background of time-text */
    if (gbuffer_maintime != NULL)
    {   
        memset(gbuffer_maintime, 0, sizeof(gbuffer_maintime));
        gdata_maintimer.data = gbuffer_maintime;
        _get_bitmap(wtch_pos.typ_timer.x, wtch_pos.typ_timer.y, (wtch_pos.typ_timer.x + wtch_pos.typ_timer.width - 1), (wtch_pos.typ_timer.y + wtch_pos.typ_timer.height - 1), &gdata_maintimer); 
    }
    if (gbuffer_millitime != NULL)
    {   
        memset(gbuffer_millitime, 0, sizeof(gbuffer_millitime));
        gdata_millitimer.data = gbuffer_millitime;
        _get_bitmap(wtch_pos.typ_milsec.x, wtch_pos.typ_milsec.y, (wtch_pos.typ_milsec.x + wtch_pos.typ_milsec.width - 1), (wtch_pos.typ_milsec.y + wtch_pos.typ_milsec.height - 1), &gdata_millitimer);
}

    /* show the time-text */ 
    print_center_time();

    /* start timer for animation */
    if (stop_watch_total_frames > 1)
    {
        gui_start_timer(STOP_WATCH_ANIMATION_DELAY, stop_watch_animation_processor);
    }
    /* start timer for time-text */
    if (timer_flag_stop_start == TIMER_START)
    {
        gui_start_timer(STPWACH_UI_UPDATE_PERIOD, show_center_time);
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory307PanelScreen
 * DESCRIPTION
 *  Show typical stopwatch screen.
 * PARAMETERS
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  number_of_items         [IN]        Number of items
 *  list_watch              [IN]        watch list
 *  highlighted_item        [IN]        highlighted item
 *  bkg_image               [IN]        background image ID
 *  panel_area_data         [IN]        Panel struct
 *  start_continue_flag     [IN]        start continue flag
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory307PanelScreen(
    U16 left_softkey,
    U16 left_softkey_icon,
    U16 right_softkey,
    U16 right_softkey_icon,
    S32 number_of_items,
    UI_stop_watch *list_watch,
    S32 highlighted_item,
    U16 bkg_image,
    wgui_panel_area_struct *panel_area_data, 
    S32 start_continue_flag,
    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    PU8 img_bkg_stop;
    S32 width, height;
    dm_coordinates history_list;
#if defined(__MMI_CAT_STOPWATCH_PANEL__)    
    gui_util_painter_struct bg_painter, disable_painter, off_painter, on_painter, down_painter;
#endif /* defined(__MMI_CAT_STOPWATCH_PANEL__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* already be alloced in FTE project */
    if (cat307_cntx_ptr == NULL)
    {
        cat307_cntx_ptr = (cat307_screen_info_cntx *)applib_mem_screen_alloc(sizeof(cat307_screen_info_cntx));
    }

    g_current_screen = TYPICAL_TIMER_SCR;

    gui_lock_double_buffer();

#ifdef __MMI_FTE_SUPPORT__
    gui_measure_image(cat307_cntx_ptr->num_image[0], &width, &height);
    g_wgui_cat307_num_bg_buf = (U8*)mmi_frm_scrmem_alloc(((width+1) * (height+1) * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
#else
    gui_set_font(TYP_TIME_FONT);
    mmi_fe_measure_string_by_char_num((U8*)(L"0123456789:"), 8, &width, &height);
    gbuffer_maintime = (U8*)mmi_frm_scrmem_alloc(((width+1) * (height+1) * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
    mmi_fe_measure_string_by_char_num((U8*)(L"0123456789"), 3, &width, &height);
    gbuffer_millitime = (U8*)mmi_frm_scrmem_alloc(((width+1) * (height+1) * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
#endif

    start_timer_again = start_continue_flag;

    dm_add_softkey_id(left_softkey, right_softkey);

#if !(defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_240X400__))
    entry_full_screen();
#endif 
    wgui_fixed_list_create_multi_icontext_menu(
        0, 
        2,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_DISABLE_SHORTCUT,
        MMI_CATEGORY307_ID,
        history_buffer);

    GUI_current_fixed_icontext_list_menuitem_column = 1;

    set_fixed_icontext_list_text_coordinates(0, (1 + WGUI_CAT307_LIST_TEXT_GAP_X), 0, 30, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(
        1,
        (30 + WGUI_CAT307_LIST_TEXT_GAP_X),
        0,
        UI_device_width - 30 - 4 - MMI_fixed_list_menu.vbar.width,
        MMI_MENUITEM_HEIGHT);
    dm_get_control_coordinates_from_category((S32)GetActiveScreenId(), MMI_CATEGORY307_ID, DM_LIST1, 0, &history_list);

    /* set the list-text color */
    for (i = 0; i < 2; i++)
    {
        MMI_fixed_icontext_list_menuitem.normal_text_colors[i] = *current_MMI_theme->list_normal_text_color;
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[i] = *current_MMI_theme->list_selected_text_color;
        MMI_fixed_icontext_list_menuitem.selected_text_colors[i] = *current_MMI_theme->list_selected_text_color;
    }

    wgui_fixed_list_begin_add_multi_icontext_one_item();

    for (i = 0; i < number_of_items; i++)
    {
        U8* items[2];
        gui_itoa(i + 1, (UI_string_type) category89_string_list[i], 10);
        gui_strcat((UI_string_type) category89_string_list[i], (UI_string_type) ".\0");
        items[0] = category89_string_list[i];
        MMI_fixed_icontext_list_menuitems[i].flags |= UI_MENUITEM_TEXT_COL1_IS_NUMBER;
        change_stopwatchtime_to_string(
            list_watch[i].mili_sec,
            list_watch[i].hour,
            list_watch[i].min,
            list_watch[i].sec,
            list_watch[i].watch_string,
            DISPLAY_MILISEC_TRUE);
        items[1] = list_watch[i].watch_string;
        wgui_fixed_list_add_multi_icontext_one_item(i, items, NULL, NULL);
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();
    wgui_fixed_list_resize_multi_icontext_menu(MMI_content_width, history_list.s16Height);

    resize_fixed_icontext_list_menuitems(0, MMI_menuitem_height);
    set_fixed_icontext_positions(0, 0, 1, 0);
    wgui_fixed_list_override_multi_icontext_highlight_handler(standard_stop_watch_list_highlight_handler);

    cat307_cntx_ptr->bkg_img = bkg_image;
    img_bkg_stop = (PU8) GetImage(bkg_image);
    gui_measure_image(img_bkg_stop, &cat307_cntx_ptr->image_width, &cat307_cntx_ptr->image_height);
    stop_watch_total_frames = gui_image_n_frames(img_bkg_stop);
#ifdef __MMI_FTE_SUPPORT__
    MMI_ASSERT(stop_watch_total_frames <= 1);
#endif


#if defined(__MMI_CAT_STOPWATCH_PANEL__) && !defined(__MMI_FTE_SUPPORT__)
    /* Set panel position */
    for (i = 0; i< panel_area_data->num_of_element; i++)
    {
        panel_area_data->element_list[i].x = panel_button_position_catsw[i][0];
        panel_area_data->element_list[i].y = panel_button_position_catsw[i][1];
        panel_area_data->element_list[i].width = panel_button_position_catsw[i][2];
        panel_area_data->element_list[i].height = panel_button_position_catsw[i][3];
    }

    /* Panel Background */
    gui_util_painter_create_imageid(&bg_painter, panel_area_data->panel_bg_img_id);
    wgui_catsw_panel_handle = dm_add_panel(0, 0, UI_device_width, UI_device_height, bg_painter, MMI_FALSE, panel_area_data->repeat_period);
    /* add panel buttons */
    for(i = 0; i < panel_area_data->num_of_element; i++)
    {
        gui_util_painter_create_imageid(&disable_painter, panel_area_data->element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, panel_area_data->element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, panel_area_data->element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, panel_area_data->element_list[i].down_imageid);
        dm_add_panel_element(
            wgui_catsw_panel_handle,
            panel_area_data->element_list[i].x,
            panel_area_data->element_list[i].y,
            panel_area_data->element_list[i].width,
            panel_area_data->element_list[i].height,
            panel_area_data->element_list[i].keycode,
            panel_area_data->element_list[i].down_event_callback,
            panel_area_data->element_list[i].up_event_callback,
            panel_area_data->element_list[i].repeat_event_callback,
            off_painter,
            on_painter,
            down_painter,
            disable_painter,
            MMI_FALSE);
        dm_set_panel_enable_element(wgui_catsw_panel_handle, i, panel_area_data->element_list[i].enabled, MMI_FALSE); 
    }
    dm_register_panel_keys(wgui_catsw_panel_handle, wgui_catsw_general_key_handler);
#else /* defined(__MMI_STOPWATCH_PANEL__) */ 
    UI_UNUSED_PARAMETER(panel_area_data);
#endif /* defined(__MMI_STOPWATCH_PANEL__) */ 

    gui_unlock_double_buffer();

    /* Not to execute LSK function when pen down on list menuitem */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(UI_dummy_function);
#endif 
    /* show the control area (central timer) */
    dm_register_category_controlled_callback(wgui_cat307_draw_control_area);

    wgui_cat_setup_category(MMI_CATEGORY307_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory307Screen, get_category307_history, get_category307_history_size);
    dm_redraw_category_screen();
}


#if defined (__MMI_FTE_SUPPORT__) 
/*****************************************************************************
 * FUNCTION
 *  ShowCategory307Screen
 * DESCRIPTION
 *  Show typical stopwatch screen.
 * PARAMETERS
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  number_of_items         [IN]        Number of items
 *  list_watch              [IN]        watch list
 *  highlighted_item        [IN]        highlighted item
 *  history_buffer          [IN]        history buffer
 *  bkg_image               [IN]        background image ID
 *  num_image               [IN]        number image
 *  colon_image             [IN]        colon image
 *  dot_image               [IN]        dot image
 *  start_continue_flag     [IN]        start continue flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory307Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        UI_stop_watch *list_watch,
        S32 highlighted_item,
        U8 *history_buffer,
        U16 bkg_image,
        PU8* num_image,
        PU8 colon_image,
        PU8 dot_image,
        S32 start_continue_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 unused_value;
    S32 num_x = 0;
    S32 symboy_i = WGUI_CAT307_NUM_SYMBOL - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_icon_bar_is_created());

    if (cat307_cntx_ptr == NULL)
    {
        cat307_cntx_ptr = (cat307_screen_info_cntx *)applib_mem_screen_alloc(sizeof(cat307_screen_info_cntx));
    }

    /* initialize the main timer image */
    for (i = 0; i < WGUI_CAT307_NUM_NUMERIC_IMAGE; i++)
    {
        cat307_cntx_ptr->num_image[i] = num_image[i];
    }
    cat307_cntx_ptr->colon_image = colon_image;
    cat307_cntx_ptr->dot_image = dot_image;

    /* setup number image position */
    if ((cat307_cntx_ptr->num_image[0] != NULL) && 
        (cat307_cntx_ptr->colon_image != NULL) && 
        (cat307_cntx_ptr->dot_image != NULL))
    {
        gui_measure_image(cat307_cntx_ptr->num_image[0], &cat307_cntx_ptr->num_image_w, &cat307_cntx_ptr->num_image_h);
        gui_measure_image(cat307_cntx_ptr->colon_image, &cat307_cntx_ptr->symbol_image_w, &unused_value);

        num_x = ((UI_device_width - (cat307_cntx_ptr->num_image_w * WGUI_CAT307_NUM_MAIN_TIMER) - 
            (cat307_cntx_ptr->symbol_image_w * WGUI_CAT307_NUM_SYMBOL)) >> 1);
        MMI_ASSERT(num_x >= 0);

        for (i = (WGUI_CAT307_NUM_MAIN_TIMER - 1); i >= 0; i--)
        {
            cat307_cntx_ptr->num_image_x[i] = num_x;
            num_x += cat307_cntx_ptr->num_image_w;
            if ((i == 5) || (i == 3) || (i == 1))
            {
                cat307_cntx_ptr->symbol_image_x[symboy_i--] = num_x;
                num_x += cat307_cntx_ptr->symbol_image_w;
            }
        }

        cat307_cntx_ptr->num_image_y = MMI_STATUS_BAR_HEIGHT + ((WGUI_CAT307_CONTROL_AREA_H - cat307_cntx_ptr->num_image_h) >> 1);
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    ShowCategory307PanelScreen(
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_watch,
        highlighted_item,
        bkg_image,
        NULL, 
        start_continue_flag,
        history_buffer);
}

#else
/*****************************************************************************
 * FUNCTION
 *  ShowCategory307Screen
 * DESCRIPTION
 *  Show typical stopwatch screen.
 * PARAMETERS
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  number_of_items         [IN]        Number of items
 *  list_watch              [IN]        watch list
 *  highlighted_item        [IN]        highlighted item
 *  history_buffer          [IN]        history buffer
 *  bkg_image               [IN]        background image ID
 *  start_continue_flag     [IN]        start continue flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory307Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        UI_stop_watch *list_watch,
        S32 highlighted_item,
        U8 *history_buffer,
        U16 bkg_image,
        S32 start_continue_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory307PanelScreen(
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_watch,
        highlighted_item,
        bkg_image,
        NULL, 
        start_continue_flag,
        history_buffer);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  get_category307_history
 * DESCRIPTION
 *  This function is used by draw manager to get history.
 * PARAMETERS
 *  history_buffer      [IN]            Buffer of history data.
 * RETURNS
 *  U8 history
 *****************************************************************************/
U8 *get_category307_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history((U16)MMI_CATEGORY307_ID, history_buffer);
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  get_category307_history_size
 * DESCRIPTION
 *  This function is used by draw manager to get history size.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32                history size
 *****************************************************************************/
S32 get_category307_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_category_history));
}


/*****************************************************************************/
/***  Utility Function                                                     ***/
/*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  change_stopwatchtime_to_string
 * DESCRIPTION
 *  This function is to make stopwatch timer value to string
 * PARAMETERS
 *  milisec                     [IN]        mile second
 *  hour                        [IN]        hour
 *  min                         [IN]        minute
 *  sec                         [IN]        second
 *  str_val                     [IN]        string buffer
 *  display_milisec_flag        [IN]        If display mile second
 * RETURNS
 *  void
 *****************************************************************************/
void change_stopwatchtime_to_string(S32 milisec, S32 hour, S32 min, S32 sec, U8 *str_val, U8 display_milisec_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_str[TIMER_TEXT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (display_milisec_flag)
    {
        sprintf((S8*) temp_str, "%02d:%02d:%02d:%02d", hour, min, sec, milisec);
    }
    else
    {
        sprintf((S8*) temp_str, "%02d:%02d:%02d", hour, min, sec);
    }

    mmi_asc_to_ucs2((PS8) str_val, (PS8) temp_str);

    return;
}

#else /* __MMI_STOPWATCH__ */ 
void wgui_categories_stopwatch_dummy(void){}
#endif /* __MMI_STOPWATCH__ */ 


