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
 * wgui_datetime.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for datetime screen control.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

 /*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

/**********************************************************************************
   Filename:      wgui_datetime.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines header for Date and Time input / display
**********************************************************************************/

#ifndef __WGUI_DATETIME_H__
#define __WGUI_DATETIME_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "MMI_features.h"
#include "MMIDataType.h"

#include "mmi_frm_input_gprot.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "gui_inputs.h"
#include "gui_data_types.h"
#include "custom_mmi_default_value.h"
#include "CustThemesRes.h"
#include "gui.h"
#include "kal_general_types.h"

#ifdef __MMI_FWUI_SLIM__
    #ifndef __MMI_DATETIME_SLIM__
    #define __MMI_DATETIME_SLIM__
    #endif
#endif


#if defined(__MMI_FTE_SUPPORT__)

#if defined(__MMI_MAINLCD_240X320__)
#define GAP_BETWEEN_INPUT_COMPONENT_BOTTOM_AND_BOUNDAY  10
#define GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY    8
#elif defined(__MMI_MAINLCD_240X400__)
#define GAP_BETWEEN_INPUT_COMPONENT_BOTTOM_AND_BOUNDAY  10
#define GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY    8
#elif defined(__MMI_MAINLCD_320X480__)
#define GAP_BETWEEN_INPUT_COMPONENT_BOTTOM_AND_BOUNDAY  11
#define GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY    10
#elif defined(__MMI_MAINLCD_480X800__)
#define GAP_BETWEEN_INPUT_COMPONENT_BOTTOM_AND_BOUNDAY  11
#define GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY    10
#elif defined(__MMI_MAINLCD_320X240__)
#define GAP_BETWEEN_INPUT_COMPONENT_BOTTOM_AND_BOUNDAY  10
#define GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY    8
#endif

#else /* (__MMI_FTE_SUPPORT__) */
#define GAP_BETWEEN_INPUT_COMPONENT_BOTTOM_AND_BOUNDAY  9
#define GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY    0
#endif /* (__MMI_FTE_SUPPORT__) */


    /* Date and time display   */

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    extern void set_day_display(void);
    extern void show_main_LCD_day_display(void);
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

    /* Date input object */

#define DATE_INPUT_MAX_FOCUS              8
#if defined(__MMI_MAINLCD_240X320__)
#define DATE_INPUT_HEIGHT                 22
#define DATE_INPUT_DAY_WIDTH              26
#define DATE_INPUT_MONTH_WIDTH               26
#define DATE_INPUT_YEAR_WIDTH             46
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#ifdef  __MMI_MAINLCD_128X64__
#define DATE_INPUT_HEIGHT                 15
#else
#define DATE_INPUT_HEIGHT                 16
#endif
#define DATE_INPUT_DAY_WIDTH              22
#define DATE_INPUT_MONTH_WIDTH               22
#define DATE_INPUT_YEAR_WIDTH             38
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#if defined(__MMI_MAINLCD_176X220__)
    #define DATE_INPUT_SEPERATOR_WIDTH           2
#elif defined(__MMI_MAINLCD_240X320__)
  #define DATE_INPUT_SEPERATOR_WIDTH           6
#elif defined(__MMI_MAINLCD_240X400__)
  #define DATE_INPUT_SEPERATOR_WIDTH           6
#elif defined(__MMI_MAINLCD_320X480__)
  #define DATE_INPUT_SEPERATOR_WIDTH           10
#elif defined(__MMI_MAINLCD_320X240__)
  #define DATE_INPUT_SEPERATOR_WIDTH           6
#else
    #define DATE_INPUT_SEPERATOR_WIDTH           2
#endif
#define DATE_INPUT_DAY_BUFFER_LENGTH         (3*ENCODING_LENGTH)
#define DATE_INPUT_MONTH_BUFFER_LENGTH       (3*ENCODING_LENGTH)
#define DATE_INPUT_YEAR_BUFFER_LENGTH        (5*ENCODING_LENGTH)


#define GENERAL_INPUT_FOCUS_NONE             0

#define DATE_INPUT_FOCUS_NONE             GENERAL_INPUT_FOCUS_NONE
#define DATE_INPUT_FOCUS_DAY              1
#define DATE_INPUT_FOCUS_MONTH               2
#define DATE_INPUT_FOCUS_YEAR             3

#define GENERAL_INPUT_USE_RESET_CLIP        0x00100000

#define DATE_INPUT_TYPE_DD_MM_YYYY           0x00000001
#define DATE_INPUT_TYPE_MM_DD_YYYY           0x00000002
#define DATE_INPUT_TYPE_YYYY_MM_DD           0x00000003
#define DATE_INPUT_TYPE_YYYY                 0x00000004
#define DATE_INPUT_TYPE_MASK              0x000000FF
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_DAY    0x00000100
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_MONTH     0x00000200
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR      0x00000300
#define DATE_INPUT_TYPE_DEFAULT_FOCUS_MASK      0x0000FF00
#define DATE_INPUT_JUSTIFY_MASK              0x00030000
#define DATE_INPUT_LEFT_JUSTIFY              0x00000000
#define DATE_INPUT_RIGHT_JUSTIFY          0x00010000
#define DATE_INPUT_CENTER_JUSTIFY            0x00020000
#define DATE_INPUT_USE_PRESET_CLIP          GENERAL_INPUT_USE_RESET_CLIP

typedef struct _general_input
{
    S32 x, y;
    S32 width, height;
    S32 offset_x, offset_y;
    U32 flags;
    void (*hide_callback) (S32 x1, S32 y1, S32 x2, S32 y2);/*hide function*/
} general_input;

typedef void (*general_input_func_ptr) (void *);

    typedef struct _date_input
    {
    general_input input;
        S32 day_x, day_y;
        S32 month_x, month_y;
        S32 year_x, year_y;
        S32 s1_x, s1_y;
        S32 s2_x, s2_y;
        U32 focus_list[DATE_INPUT_MAX_FOCUS];
        U32 current_focus;
        single_line_input_box day_input_box;
        single_line_input_box month_input_box;
        single_line_input_box year_input_box;
        single_line_input_box *focus_input_box;
        
        UI_character_type seperator;
    } date_input;

    extern void date_input_show_background(date_input *d);
extern void date_input_reset_focus(void *d);
extern void date_input_set_focus(void *d);
    extern void date_input_set_default_focus(date_input *d);
    extern void create_date_input(
                    date_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type day_buffer,
                    UI_buffer_type month_buffer,
                    UI_buffer_type year_buffer);
    extern void show_date_input(date_input *d);
    extern void date_input_set_seperator(date_input *d, UI_character_type seperator);
    extern void date_input_set_hide_function(date_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));

    extern date_input *current_date_input;
    extern void (*current_date_input_callback) (void);

    extern void set_current_date_input(date_input *d);
    extern void date_input_direct_input(UI_character_type c);
    extern MMI_BOOL date_input_direct_input_nodraw(UI_character_type c);
    extern void date_input_delete_character(void);
    extern S32  date_input_test_last_position(date_input *d);
    extern void date_input_previous_character(void);
    extern void date_input_first_character(void);
    extern void date_input_next_character(void);
    extern void date_input_toggle_insert_mode(void);
    extern void date_input_delete_current_character(void);
    extern void date_input_delete_all_characters(void);
    extern void date_input_numeric_keyboard_input_handler(S32 keyc);
    extern void date_input_handle_key_down(MMI_key_code_type k);
    extern void date_input_key_handler(S32 vkey_code, S32 key_state);
    extern void date_input_register_keys(void);
    extern void date_input_clear_keys(void);
extern void register_date_input_callback(void (*f) (void));
    extern void clear_date_input_callback(void);

    /* Time input object */

#define TIME_INPUT_MAX_FOCUS              8
#if defined(__MMI_MAINLCD_240X320__)
#define TIME_INPUT_HEIGHT                 22
#define TIME_INPUT_HOURS_WIDTH               26
#define TIME_INPUT_MINUTES_WIDTH          26
#define TIME_INPUT_SECONDS_WIDTH          26
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#ifdef  __MMI_MAINLCD_128X64__
#define TIME_INPUT_HEIGHT                 15
#else
#define TIME_INPUT_HEIGHT                 16
#endif
#define TIME_INPUT_HOURS_WIDTH               22
#define TIME_INPUT_MINUTES_WIDTH          22
#define TIME_INPUT_SECONDS_WIDTH          22
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_INPUT_SEPERATOR_WIDTH           0
#define TIME_INPUT_HOURS_BUFFER_LENGTH       (3*ENCODING_LENGTH)
#define TIME_INPUT_MINUTES_BUFFER_LENGTH     (3*ENCODING_LENGTH)
#define TIME_INPUT_SECONDS_BUFFER_LENGTH     (3*ENCODING_LENGTH)

#define TIME_INPUT_FOCUS_NONE             GENERAL_INPUT_FOCUS_NONE
#define TIME_INPUT_FOCUS_HOURS               1
#define TIME_INPUT_FOCUS_MINUTES          2
#define TIME_INPUT_FOCUS_SECONDS          3

#define TIME_INPUT_TYPE_HH_MM             0x00000001
#define TIME_INPUT_TYPE_HH_MM_SS          0x00000002
#define TIME_INPUT_TYPE_MASK              0x000000FF
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS     0x00000100
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_MINUTES   0x00000200
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_SECONDS   0x00000300
#define TIME_INPUT_TYPE_DEFAULT_FOCUS_MASK      0x0000FF00
#define TIME_INPUT_JUSTIFY_MASK              0x00030000
#define TIME_INPUT_LEFT_JUSTIFY              0x00000000
#define TIME_INPUT_RIGHT_JUSTIFY          0x00010000
#define TIME_INPUT_CENTER_JUSTIFY            0x00020000
#define TIME_INPUT_USE_PRESET_CLIP             GENERAL_INPUT_USE_RESET_CLIP

    typedef struct _time_input
    {
    general_input input;
        S32 hours_x, hours_y;
        S32 minutes_x, minutes_y;
        S32 seconds_x, seconds_y;
        S32 s1_x, s1_y;
        S32 s2_x, s2_y;
        U32 focus_list[TIME_INPUT_MAX_FOCUS];
        U32 current_focus;
        
        UI_character_type seperator;
        single_line_input_box hours_input_box;
        single_line_input_box minutes_input_box;
        single_line_input_box seconds_input_box;
        single_line_input_box *focus_input_box;
    } time_input;

    extern void time_input_show_background(time_input *d);
extern void time_input_reset_focus(void *d);
extern void time_input_set_focus(void *d);
    extern void time_input_set_default_focus(time_input *d);
    extern void create_time_input(
                    time_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type hours_buffer,
                    UI_buffer_type minutes_buffer,
                    UI_buffer_type seconds_buffer);
    extern void show_time_input(time_input *d);
    extern void time_input_set_seperator(time_input *d, UI_character_type seperator);
    extern void time_input_set_hide_function(time_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));

    extern time_input *current_time_input;
    extern void (*current_time_input_callback) (void);

    extern void set_current_time_input(time_input *d);
    extern void time_input_direct_input(UI_character_type c);
    extern MMI_BOOL time_input_direct_input_nodraw(UI_character_type c);
    extern S32 time_input_test_last_position(time_input *t);
    extern void time_input_delete_character(void);
    extern void time_input_previous_character(void);
    extern void time_input_first_character(void);
    extern void time_input_next_character(void);
    extern void time_input_toggle_insert_mode(void);
    extern void time_input_delete_current_character(void);
    extern void time_input_delete_all_characters(void);
    extern void time_input_numeric_keyboard_input_handler(S32 keyc);
    extern void time_input_handle_key_down(MMI_key_code_type k);
    extern void time_input_key_handler(S32 vkey_code, S32 key_state);
    extern void time_input_register_keys(void);
    extern void time_input_clear_keys(void);
extern void register_time_input_callback(void (*f) (void));
    extern void clear_time_input_callback(void);

    /* Day of Week select object  */

#if defined (__MMI_MAINLCD_240X320__)
#ifndef __MMI_FTE_SUPPORT__
#define DOW_CELL_WIDTH        21
#else
#define DOW_CELL_WIDTH        28
#endif
#elif defined (__MMI_MAINLCD_240X400__)
#ifndef __MMI_FTE_SUPPORT__
#define DOW_CELL_WIDTH        21
#else
#define DOW_CELL_WIDTH        28
#endif
#elif defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__)
#define DOW_CELL_WIDTH        12
#elif defined (__MMI_MAINLCD_320X240__)
#define DOW_CELL_WIDTH        22
#elif defined (__MMI_MAINLCD_320X480__)
#ifndef __MMI_FTE_SUPPORT__
#define DOW_CELL_WIDTH        22
#else
#define DOW_CELL_WIDTH        30
#endif
#elif defined (__MMI_MAINLCD_176X220__)
#define DOW_CELL_WIDTH        17
#else
#define DOW_CELL_WIDTH        13
#endif

#ifndef __MMI_FTE_SUPPORT__
#define DOW_CELL_HEIGHT       18
#else /* __MMI_FTE_SUPPORT__ */
    #if defined (__MMI_MAINLCD_240X320__)
    #define DOW_CELL_HEIGHT        35
    #elif defined (__MMI_MAINLCD_240X400__)
    #define DOW_CELL_HEIGHT        35
    #elif defined (__MMI_MAINLCD_320X480__)
    #define DOW_CELL_HEIGHT        40
    #elif defined (__MMI_MAINLCD_480X800__)
    #define DOW_CELL_HEIGHT        40
    #elif defined (__MMI_MAINLCD_320X240__)
    #define DOW_CELL_HEIGHT        35
    #endif
#endif /* __MMI_FTE_SUPPORT__ */
#define DOW_CELL_GAP       1

#define DOW_SELECT_STATE_DISABLED       0x00000001
#define DOW_SELECT_STATE_FOCUSED        0x00000002
#define DOW_SELECT_STATE_NORMAL         0x00000004
#define DOW_SELECT_STATE_MASK           0x0000000F
#define DOW_SELECT_USE_PRESET_CLIP      0x00000010

#ifdef __MMI_TOUCH_SCREEN__
    typedef enum
    {
        DOW_PEN_NONE,
        DOW_PEN_TOGGLE_CURRENT_ITEM,
        DOW_PEN_CHANGE_HIGHLIGHT_AND_TOGGLE_I
    } DOW_pen_event_enum;

#endif /* __MMI_TOUCH_SCREEN__ */ 

    typedef struct _DOW_select
    {
        S32 x, y;
        S32 width, height;
        S32 cell_width, cell_height;
        U8 states[8];
        S32 highlighted_cell;
        UI_filled_area *background_filler;
        UI_filled_area *normal_cell_filler;
        UI_filled_area *normal_highlighted_cell_filler;
        UI_filled_area *selected_highlighted_cell_filler;
        UI_filled_area *selected_cell_filler;
        color normal_text_color;
        color normal_highlighted_text_color;
        color selected_highlighted_text_color;
        color selected_text_color;
    #ifdef __MMI_FTE_SUPPORT__
        color disabled_text_color;
    #endif
        S32 offset_x, offset_y;
        S32 cell_gap;
        UI_font_type text_font;
        U32 flags;
    } DOW_select;

    extern void create_DOW_select(DOW_select *d, S32 x, S32 y, S32 width, S32 height);
    extern void set_DOW_select_states(DOW_select *d, U8 states[]);
    extern void set_DOW_select_flags(DOW_select *d, U32 flags);
    extern void set_DOW_select_list_menu_theme(DOW_select *d);
    extern void show_DOW_select(DOW_select *d);
    extern void show_DOW_select_background(DOW_select *d);
    extern void DOW_select_previous(DOW_select *d);
    extern void DOW_select_next(DOW_select *d);
    extern void DOW_select_toggle_item(DOW_select *d);
    extern void DOW_select_highlight_item(DOW_select *d, S32 i);
#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL DOW_translate_pen_event(
                    DOW_select *d,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    DOW_pen_event_enum *DOW_event,
                    gui_pen_event_param_struct *DOW_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* Time period input object   */

#define TIME_PERIOD_INPUT_MAX_FOCUS                8
#if defined(__MMI_MAINLCD_240X320__)
#define TIME_PERIOD_INPUT_HEIGHT                22
#define TIME_PERIOD_INPUT_HOURS_WIDTH              26
#define TIME_PERIOD_INPUT_MINUTES_WIDTH               26
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_PERIOD_INPUT_HEIGHT                16
#define TIME_PERIOD_INPUT_HOURS_WIDTH              22
#define TIME_PERIOD_INPUT_MINUTES_WIDTH               22
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define TIME_PERIOD_INPUT_SEPERATOR_WIDTH1            0
#if defined(__MMI_MAINLCD_128X160__)
#define TIME_PERIOD_INPUT_SEPERATOR_WIDTH2            8
#else
#define TIME_PERIOD_INPUT_SEPERATOR_WIDTH2            12
#endif
#define TIME_PERIOD_INPUT_HOURS_BUFFER_LENGTH         (3*ENCODING_LENGTH)
#define TIME_PERIOD_INPUT_MINUTES_BUFFER_LENGTH       (3*ENCODING_LENGTH)

#define TIME_PERIOD_INPUT_FOCUS_NONE               GENERAL_INPUT_FOCUS_NONE
#define TIME_PERIOD_INPUT_FOCUS_HOURS1             1
#define TIME_PERIOD_INPUT_FOCUS_MINUTES1           2
#define TIME_PERIOD_INPUT_FOCUS_HOURS2             3
#define TIME_PERIOD_INPUT_FOCUS_MINUTES2           4

#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS1      0x00000100
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES1 0x00000200
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS2      0x00000300
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES2 0x00000400
#define TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MASK     0x0000FF00
#define TIME_PERIOD_INPUT_JUSTIFY_MASK             0x00030000
#define TIME_PERIOD_INPUT_LEFT_JUSTIFY             0x00000000
#define TIME_PERIOD_INPUT_RIGHT_JUSTIFY               0x00010000
#define TIME_PERIOD_INPUT_CENTER_JUSTIFY           0x00020000
#define TIME_PERIOD_INPUT_USE_PRESET_CLIP           GENERAL_INPUT_USE_RESET_CLIP

    typedef struct _time_period_input
    {
    general_input input;
        S32 hours1_x, hours1_y;
        S32 s1_x, s1_y;
        S32 minutes1_x, minutes1_y;
        S32 s2_x, s2_y;
        S32 hours2_x, hours2_y;
        S32 s3_x, s3_y;
        S32 minutes2_x, minutes2_y;
        U32 focus_list[TIME_PERIOD_INPUT_MAX_FOCUS];
        U32 current_focus;
        single_line_input_box hours_input_box1;
        single_line_input_box minutes_input_box1;
        single_line_input_box hours_input_box2;
        single_line_input_box minutes_input_box2;
        single_line_input_box *focus_input_box;
        UI_character_type seperator1;
        UI_character_type seperator2;
    } time_period_input;

    extern void time_period_input_show_background(time_period_input *d);
extern void time_period_input_reset_focus(void *d);
extern void time_period_input_set_focus(void *d);
    extern void time_period_input_set_default_focus(time_period_input *d);
    extern void create_time_period_input(
                    time_period_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type hours_buffer1,
                    UI_buffer_type minutes_buffer1,
                    UI_buffer_type hours_buffer2,
                    UI_buffer_type minutes_buffer2);
    extern void show_time_period_input(time_period_input *d);
    extern void time_period_input_set_seperators(
                    time_period_input *d,
                    UI_character_type seperator1,
                    UI_character_type seperator2);
    extern void time_period_input_set_hide_function(time_period_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));

    extern time_period_input *current_time_period_input;
    extern void (*current_time_period_input_callback) (void);

    extern void set_current_time_period_input(time_period_input *d);
    extern void time_period_input_direct_input(UI_character_type c);
    extern MMI_BOOL time_period_input_direct_input_nodraw(UI_character_type c);
    extern S32  time_period_input_test_last_position(time_period_input *tp);
    extern void time_period_input_delete_character(void);
    extern void time_period_input_previous_character(void);
    extern void time_period_input_next_character(void);
    extern void time_period_input_first_character(void);
    extern void time_period_input_toggle_insert_mode(void);
    extern void time_period_input_delete_current_character(void);
    extern void time_period_input_delete_all_characters(void);
    extern void time_period_input_numeric_keyboard_input_handler(S32 keyc);
    extern void time_period_input_handle_key_down(MMI_key_code_type k);
    extern void time_period_input_key_handler(S32 vkey_code, S32 key_state);
    extern void time_period_input_register_keys(void);
    extern void time_period_input_clear_keys(void);
extern void register_time_period_input_callback(void (*f) (void));
    extern void clear_time_period_input_callback(void);

    /* Time IP4 input object   */

#define IP4_INPUT_MAX_FOCUS                  8
#if defined(__MMI_MAINLCD_240X320__)
#define IP4_INPUT_HEIGHT                  22
#define IP4_INPUT_FIELD_WIDTH             36
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define IP4_INPUT_HEIGHT                  16
#define IP4_INPUT_FIELD_WIDTH             30
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#define IP4_INPUT_SEPERATOR_WIDTH            0
#define IP4_INPUT_FIELD_BUFFER_LENGTH        (4*ENCODING_LENGTH)

#define IP4_INPUT_FOCUS_NONE              GENERAL_INPUT_FOCUS_NONE
#define IP4_INPUT_FOCUS_FIELD1               1
#define IP4_INPUT_FOCUS_FIELD2               2
#define IP4_INPUT_FOCUS_FIELD3               3
#define IP4_INPUT_FOCUS_FIELD4               4

#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD1     0x00000100
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD2     0x00000200
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD3     0x00000300
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD4     0x00000400
#define IP4_INPUT_TYPE_DEFAULT_FOCUS_MASK    0x0000FF00
#define IP4_INPUT_JUSTIFY_MASK               0x00030000
#define IP4_INPUT_LEFT_JUSTIFY               0x00000000
#define IP4_INPUT_RIGHT_JUSTIFY              0x00010000
#define IP4_INPUT_CENTER_JUSTIFY          0x00020000
#define IP4_INPUT_USE_PRESET_CLIP             GENERAL_INPUT_USE_RESET_CLIP

    typedef struct _IP4_input
    {
    general_input input;
        S32 field1_x, field1_y;
        S32 s1_x, s1_y;
        S32 field2_x, field2_y;
        S32 s2_x, s2_y;
        S32 field3_x, field3_y;
        S32 s3_x, s3_y;
        S32 field4_x, field4_y;
        U32 focus_list[IP4_INPUT_MAX_FOCUS];
        U32 current_focus;
        single_line_input_box field_input_box1;
        single_line_input_box field_input_box2;
        single_line_input_box field_input_box3;
        single_line_input_box field_input_box4;
        single_line_input_box *focus_input_box;
        UI_character_type seperator;
    } IP4_input;

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
#define DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM 2
#endif 

    extern void IP4_input_show_background(IP4_input *d);
extern void IP4_input_reset_focus(void *d);
extern void IP4_input_set_focus(void *d);
    extern void IP4_input_set_default_focus(IP4_input *d);
    extern void create_IP4_input(
                    IP4_input *d,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U32 flags,
                    UI_buffer_type b1,
                    UI_buffer_type b2,
                    UI_buffer_type b3,
                    UI_buffer_type b4);
    extern void show_IP4_input(IP4_input *d);
    extern void IP4_input_set_seperator(IP4_input *d, UI_character_type seperator);
    extern void IP4_input_set_hide_function(IP4_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));

    extern IP4_input *current_IP4_input;
    extern void (*current_IP4_input_callback) (void);

    extern void set_current_IP4_input(IP4_input *d);
    extern void IP4_input_direct_input(UI_character_type c);
    extern MMI_BOOL IP4_input_direct_input_nodraw(UI_character_type c);
    extern S32  IP4_input_test_last_position(IP4_input *ip4);
    extern void IP4_input_delete_character(void);
    extern void IP4_input_previous_character(void);
    extern void IP4_input_first_character(void);
    extern void IP4_input_next_character(void);
    extern void IP4_input_toggle_insert_mode(void);
    extern void IP4_input_delete_current_character(void);
    extern void IP4_input_delete_all_characters(void);
    extern void IP4_input_numeric_keyboard_input_handler(S32 keyc);
    extern void IP4_input_handle_key_down(MMI_key_code_type k);
    extern void IP4_input_key_handler(S32 vkey_code, S32 key_state);
    extern void IP4_input_register_keys(void);
    extern void IP4_input_clear_keys(void);
extern void register_IP4_input_callback(void (*f) (void));
    extern void clear_IP4_input_callback(void);
    extern void set_inline_date_boundary(S32 date_year_max, S32 date_year_min, S32 date_month_max, S32 date_month_min);

    extern UI_date_time_display main_LCD_time_object;

#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_DATETIME_H__ */ 


