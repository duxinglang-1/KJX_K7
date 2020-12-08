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
 *  wgui_categories_calendar.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Calendar related categories.
 *
 *  Author:
 * -------
 *  Tingting Li (MBJ07028)
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================

 ****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __WGUI_CATEGORIES_CALENDAR_H__
#define __WGUI_CATEGORIES_CALENDAR_H__
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "PixcomFontEngine.h"
#include "gui_data_types.h"

#include "app_datetime.h"
/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "wgui_include.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */
#include "gui_typedef.h"
#include "wgui.h"
   
//RHR 
    #include "MMIDataType.h"
    #include "gui_typedef.h"
    #include "MMI_features.h"
    #include "PixcomFontEngine.h"
    #include "gui_data_types.h"
    #include "wgui.h"
    #include "app_datetime.h"
    #include "kal_general_types.h"

#define  CLNDR_TITLE_LEN            12*ENCODING_LENGTH
#define  CLNDR_HINT_LEN             8*ENCODING_LENGTH
#define  CLNDR_MAX_DAYS             31
#define  CLNDR_LAST_NAVI_YEAR       2030
#define  CLNDR_FIRST_NAVI_YEAR      1970

#define  WGUI_CAT83_LAST_NAVI_YEAR          (2030)
#define  WGUI_CAT83_FIRST_NAVI_YEAR         (1900)

#define WGUI_CAT_CAL_EVENT_STRING_MAX_LENGTH    (55)
#if defined(__MMI_CLNDR_MULTITASK_DISPLAY__) && !defined(__MMI_FTE_SUPPORT__)
    #define WGUI_CAT_CAL_EVENT_ENTRY_NUM        (4)
#else
    #define WGUI_CAT_CAL_EVENT_ENTRY_NUM        (2)
#endif

#define WGUI_CAT_CAL_EVENT_ENTRY_SIZE           ((WGUI_CAT_CAL_EVENT_STRING_MAX_LENGTH + 1) * ENCODING_LENGTH)
#define WGUI_CAT_CAL_EVENT_BUFFER_SIZE          (WGUI_CAT_CAL_EVENT_ENTRY_SIZE * WGUI_CAT_CAL_EVENT_ENTRY_NUM)

#ifdef __MMI_CALENDAR_NEW_STYLE__
#define WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT            (1)
#else
#define WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT            (2)
#endif


#define WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH      (15)
#if 0
/* under construction !*/
#else
#define WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_SIZE        0
#endif

#define WGUI_CAT_CAL_BUFFER_SIZE                    (WGUI_CAT_CAL_EVENT_BUFFER_SIZE + WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_SIZE)

#if defined (__MMI_MAINLCD_320X240__)
    #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  13
#elif defined (__MMI_MAINLCD_240X320__)
    #ifndef __MMI_FTE_SUPPORT__
        #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  13
    #else /* __MMI_FTE_SUPPORT__ */
        #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  32
    #endif /* __MMI_FTE_SUPPORT__ */
#elif defined (__MMI_MAINLCD_240X400__)
    #ifndef __MMI_FTE_SUPPORT__
        #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  13
    #else /* __MMI_FTE_SUPPORT__ */
        #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  32
    #endif /* __MMI_FTE_SUPPORT__ */
#elif defined (__MMI_MAINLCD_176X220__)
    #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  13
#elif defined (__MMI_MAINLCD_128X160__)
    #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  13
#elif defined (__MMI_MAINLCD_128X128__)
    #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  13
#elif defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #ifndef __MMI_FTE_SUPPORT__
        #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  17
    #else /* __MMI_FTE_SUPPORT__ */
        #define WGUI_CAT_CAL_HORIZONTAL_SELECT_ICON_WIDTH  38
    #endif /* __MMI_FTE_SUPPORT__ */
#endif

#define wgui_cat83_event_entry_struct   gui_calendar_detail_entry_struct 
/*
 * Struct of calendar event entry.
 */
typedef struct
{
    /* The detail list of one cell. */
    wgui_cat83_event_entry_struct entry_list[WGUI_CAT_CAL_EVENT_ENTRY_NUM];
    /* The max length of one detail string. */
    U8 event_string_max_length;
    /* The number of total entry. */
    U8 event_entry_number;
}wgui_cat83_event_struct;

/* DOM-NOT_FOR_SDK-END */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    WGUI_CAL_H_SELECT_ALLOW_PREV = 0,
    WGUI_CAL_H_SELECT_ALLOW_NEXT,
    WGUI_CAL_H_SELECT_ALLOW_TOTAL
} wgui_calendar_horizontal_select_allow_enum;

typedef struct
{
    /*icon x ,y width ,height*/
    S32 icon_x;
    S32 icon_y;
    S32 icon_width;
    S32 icon_height;
    /* The image of  arrow up / down / disable state. */
    PU8 up_icon;
    PU8 down_icon;
    PU8 disable_icon;
#ifdef __MMI_TOUCH_SCREEN__
    /* Pen state of  arraw icon. */
    gui_calendar_pen_state_enum icon_state;
    /* Whether pen is down in  arraw button. */
    U8 pen_down_in_button;
#endif /* __MMI_TOUCH_SCREEN__ */
}wgui_calendar_horizontal_select_icon_struct;

typedef struct
{
    /* Relative position of calendar title. */
    S32 x, y;
    /* Dimension of calendar title. */
    S32 width, height;
    /*icon info*/
    wgui_calendar_horizontal_select_icon_struct icon_info[WGUI_CAL_H_SELECT_ALLOW_TOTAL]; 
    /* Text font of horizontal select. */
    stFontAttribute *text_font;
    /* Text color of horizontal select. */
    color text_color;
    /* Text border color of horizontal select. */
    color text_border_color;
} wgui_calendar_horizontal_select_struct;


/****************************************************************************
  * FUNCTION
  *  ShowCategory83Screen
  * Description
  *  Displays the calendar screen.
  *
  *  <img name="wgui_cat083_img1" />
  * Parameters
  * bg_id :               [IN] (N/A) Full screen background.
  * num_of_row :          [IN] (N/A) The row of calendar.
  * num_of_column :       [IN] (N/A) The column of canlendar.
  * current_row :         [IN] (N/A) The row of highlight day(Cannot be changed later).
  * current_column :      [IN] (N/A) The column of highlight day(Cannot be changed later).
  * highlighted_row :     [IN] (N/A) The row of highlight day(Can be changed by pen or key).
  * highlighted_column :  [IN] (N/A) The column of highlight day(Can be changed by pen or key).
  * is_status_bar :       [IN] (N/A) Show the status icon or not.
  * str_LeftSoftkey :     [IN] (LSK) Left-softkey text.
  * str_rightSoftkey :    [IN] (RSK) Right-softkey text.
  * Returns
  *  void     
  * Example
  * <code>
  *  void EntryScreen_83(void)
  *  {
  *      U8 *guiBuffer = NULL;
  *      gui_calendar_cell_struct *CalendarCell;
  *      S32 i, j;
  *
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      CalendarCell = cell_buf[0];
  *      
  *      for(i = 0; i < 6; i++)
  *      {
  *          for(j = 0; j < 7; j++)
  *          {
  *              cell_buf[i][j].bg_index = GUI_CALENDAR_COLOR_ONE_TASK;
  *              cell_buf[i][j].icon_id = 0;
  *              mmi_asc_to_ucs2((PS8) cell_buf[i][j].text, (PS8) L"a");
  *          }
  *      }
  *      wgui_calendar_set_cell_array(
  *      CalendarCell,
  *      GUI_CALENDAR_CELL_BG_FILL_VERTICAL,
  *      GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
  *      GUI_CALENDAR_CELL_ICON_DISPLAY_CENTER);
  *
  *      ShowCategory83Screen(
  *          0,
  *          6,
  *          7,
  *          3,
  *          3,
  *          4,
  *          4,
  *          MMI_TRUE,
  *          (U8*) GetString(STR_ID_CSB_LSK_TEXT),
  *          (U8*) GetString(STR_ID_CSB_RSK_TEXT));
  *
  *      csb_set_key_handlers();
  *  }
  * </code>                                                                                      
  ****************************************************************************/
extern void ShowCategory83Screen(
             UI_image_ID_type bg_id,
             gui_calendar_type_enum type,
             applib_time_struct max_date,
             applib_time_struct min_date,
             applib_time_struct show_date,
             MMI_BOOL is_status_bar,
             U8 *str_LeftSoftkey,
             U8 *str_rightSoftkey,
             U8 *history_buffer,
             U32 flag);

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9004_show
 * DESCRIPTION
 *  category screen of integrated calendar (monthly/weekly and menstral)
 * PARAMETERS
 *  bg_id                       [IN]        Full screen background.
 *  horizon_string_list         [IN]        Horizontal string list
 *  cell                        [IN]        2 dimension cell array
 *  num_of_row                  [IN]        Number of row
 *  num_of_column               [IN]        Number of column
 *  current_row                 [IN]        Row of current time
 *  current_column              [IN]        Column of current time
 *  highlighted_row             [IN]        Highlighted row
 *  highlighted_column          [IN]        Highlighted column
 *  is_status_bar               [IN]        Show the status icon or not.
 *  item_count                  [IN]        Item count of tool bar.
 *  resource_array              [IN]        Resource array of tool bar.
 *  callback                    [IN]        callback function of tool bar.
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat9004_show(
             UI_image_ID_type bg_id,
             gui_calendar_type_enum type,
             applib_time_struct max_date,
             applib_time_struct min_date,
             applib_time_struct show_date,
             MMI_BOOL is_status_bar,
             U8 *str_LeftSoftkey,
             U8 *str_RightSoftkey,
             S32 item_count,
             gui_icon_bar_item_resource_struct *resource_array,
             GUIIconbarItemCallback callback,
             MMI_BOOL *icon_bar_enable_state,
             U8 *history_buffer,
             U32 flag);
#endif /* __MMI_FTE_SUPPORT__ */

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
extern void wgui_cat83_register_cell_data_query_handler(
             S32 (*f)(
                gui_calendar_type_enum type,
                applib_time_struct start_time,
                applib_time_struct end_time,
                applib_time_struct interval,
                S32 query_count,
                gui_calendar_cell_struct *cells));
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
extern void wgui_cat83_register_cell_lunar_query_handler(
             S32 (*f)(
                   gui_calendar_type_enum type,
                   applib_time_struct cell_time,
                   applib_time_struct time_interval,
                   PU8 title,
                   U32 title_length,
                   gui_calendar_cell_detail_info_struct *detail_info));

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
extern void wgui_cat83_register_event_query_handler(
             S32 (*f)(
                   gui_calendar_type_enum type,
                   applib_time_struct cell_time,
                   applib_time_struct time_interval,
                   wgui_cat83_event_struct *event_info));
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
extern void wgui_cat83_register_highlight_change_callback(
                 MMI_BOOL (*f)(
                        gui_calendar_type_enum type,
                        applib_time_struct highlighted_time,
                        applib_time_struct start_time,
                        applib_time_struct end_time));



#ifdef __MMI_TOUCH_SCREEN__
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
#endif

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
extern void wgui_cat83_register_highlight_select_callback(
             void (*f)(
                   gui_calendar_type_enum type,
                   applib_time_struct highlighted_time));

#endif /* __MMI_TOUCH_SCREEN__ */


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
extern void wgui_cat83_refresh_events_reminder(void);


#endif /* __WGUI_CATEGORIES_CALENDAR_H__ */ 


