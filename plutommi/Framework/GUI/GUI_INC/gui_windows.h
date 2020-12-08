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
 *  gui_windows.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Miscellaneous UI components. 
 *
 *  [Popup description]
 *  [Scrolling text]
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_WINDOWS_H__
#define __GUI_WINDOWS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui.h"
#include "gui_theme_struct.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "mmi_frm_gprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */
#ifdef __MMI_FTE_SUPPORT__
#include "gdi_include.h"
#endif 

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* <group dom_utility_macro> */
#define UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL        0x00000010
/* <group dom_utility_macro> */
#define UI_POP_UP_DESCRIPTION_TWO_DIRECTION_SCROLL  0x00000020
/* <group dom_utility_macro> */
#define UI_POP_UP_DESCRIPTION_DISPLAY_SCROLL        0x00000040
/* <group dom_utility_macro> */
#define UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM        0x00000080
/* <group dom_utility_macro> */
#define MAX_POP_UP_DESCRIPTION_STRINGS              2

/* <group dom_menu_macro>
 *  number of steps for transition animation */
#define MAX_POP_UP_DESCRIPTION_TRANSITION_STEPS     9
/* <group dom_menu_macro>
 *  step time in ms for transition animation */
#define POPUP_DESCRIPTION_TRANSITION_STEP_TIME      100

/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_ENABLE_SCROLL             0x00000001
/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_MARQUEE_SCROLL            0x00000002
/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_TWO_DIRECTION_SCROLL      0x00000004
/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT    0x00000008
/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_BORDERED_TEXT             0x00000010
/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_DISPLAY_SCROLL            0x00000020
/* <group dom_utility_macro> */
#define UI_SCROLLING_TEXT_PRESET_CLIP               0x00000040


/* <group dom_utility_macro> */
#define GUI_WAIT_LONGPRESS_MAX_DISTANCE             15
/* <group dom_utility_macro> */
#define GUI_WAIT_LONGPRESS_CACHE_SIZE               (50 * 50 * 2)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* <group dom_utility_struct> */
typedef struct _UI_pop_up_description
{
    S32 x, y;
    S32 width, height;
    color text_color;
    UI_font_type text_font;
    UI_filled_area *background_filler;
    UI_string_type text_strings[MAX_POP_UP_DESCRIPTION_STRINGS];
    S32 n_strings;
    S32 text_x, text_y;
    S32 scroll_x, scroll_width, text_width;
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    S32 transition_step;
#endif
    U32 flags;
#ifdef __MMI_FTE_SUPPORT__
    gdi_image_cache_bmp_struct hint_cache_buf;
#endif 
} UI_pop_up_description;

/* <group dom_utility_struct> */
typedef struct _scrolling_text
{
    S32 x, y;
    S32 width, height;
    S32 text_width, text_height;
    U32 flags;
    S32 scroll_size;
    S32 scroll_gap;
    S32 scroll_pause;
    color text_color;
    color text_border_color;
    stFontAttribute text_font;
    UI_string_type text;
    S32 scroll_x;
    S32 scroll_counter;
    S32 scroll_time;
    MMI_BOOL force_scroll;
    bitmap *graphics_context;
    void (*timer_callback)(void);
    void (*draw_background)(S32 x1, S32 y1, S32 x2, S32 y2);

    UI_string_type scroll_text;
    UI_string_type scroll_text_end;
} scrolling_text;

/* <group dom_utility_enum> */
typedef enum
{
    GUI_WAIT_LONGPRESS_UNDECIDED = 0,
    GUI_WAIT_LONGPRESS_INVALID,
    GUI_WAIT_LONGPRESS_ANIMATING,
    GUI_WAIT_LONGPRESS_ANIMATION_FINISHED,
    GUI_WAIT_LONGPRESS_READY
} gui_wait_longpress_enum;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* <group dom_utility_variables>
 * popup description
 */
extern UI_pop_up_description_theme *current_pop_up_description_theme;



/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_pop_up_description_current_theme
 * DESCRIPTION
 *  Applies the current theme for a pop up description
 * PARAMETERS
 *  b       : [IN]        Is the pop up description to use
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_pop_up_description_current_theme(UI_pop_up_description *b);


/*****************************************************************************
 * <group dom_utility_gui_layer_theme>
 * FUNCTION
 *  gui_set_pop_up_description_theme
 * DESCRIPTION
 *  Applies the given theme to a pop up description
 * PARAMETERS
 *  b       : [IN]        Is the pop up description to use
 *  t       : [IN]        Is the theme to set 
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_pop_up_description_theme(UI_pop_up_description *b, UI_pop_up_description_theme *t);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_create_pop_up_description
 * DESCRIPTION
 *  Creates a pop up description
 * PARAMETERS
 *  b           : [IN]        Is the pop up description (pre-allocated)
 *  x           : [IN]        Is the position of the left-top corner of the pop up description
 *  y           : [IN]        Is the position of the left-top corner of the pop up description
 *  width       : [IN]        Is the width of the pop up description
 *  height      : [IN]        Is the height of the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_create_pop_up_description(UI_pop_up_description *b, S32 x, S32 y, S32 width, S32 height);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_resize_pop_up_description
 * DESCRIPTION
 *  Resizes a pop up description
 * PARAMETERS
 *  b           : [IN]        Is the pop up description
 *  width       : [IN]        Is the width of the pop up description
 *  height      : [IN]        Is the height of the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_resize_pop_up_description(UI_pop_up_description *b, S32 width, S32 height);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_move_pop_up_description
 * DESCRIPTION
 *  Moves a pop up description
 * PARAMETERS
 *  b       : [IN]        Is the pop up description
 *  x       : [IN]        Is the new location
 *  y       : [IN]        Is the new location
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_move_pop_up_description(UI_pop_up_description *b, S32 x, S32 y);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_pop_up_description
 * DESCRIPTION
 *  Moves and resizes the pop up description
 * PARAMETERS
 *  b           : [IN]        Is the pop up description
 *  x           : [IN]        Is the position of the left-top corner of the pop up description
 *  y           : [IN]        Is the position of the left-top corner of the pop up description
 *  width       : [IN]        Is the width of the pop up description
 *  height      : [IN]        Is the height of the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_pop_up_description(UI_pop_up_description *b, S32 x, S32 y, S32 width, S32 height);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_pop_up_description_n_strings
 * DESCRIPTION
 *  Sets the number of strings to be displayed in the pop up description
 * PARAMETERS
 *  b       : [IN]        Is the pop up description
 *  n       : [IN]        Is the number of strings
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_pop_up_description_n_strings(UI_pop_up_description *b, S32 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_pop_up_description_text
 * DESCRIPTION
 *  Sets the text to be displayed for a particular row
 * PARAMETERS
 *  b           : [IN]        Is the pop up description
 *  i           : [IN]        Is the row index (zero based)
 *  text        : [IN]        Is the string
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_pop_up_description_text(UI_pop_up_description *b, S32 i, UI_string_type text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_pop_up_description
 * DESCRIPTION
 *  Displays the pop up description
 * PARAMETERS
 *  b       : [IN]        Is the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_show_pop_up_description(UI_pop_up_description *b);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_autoresize_pop_up_description
 * DESCRIPTION
 *  Automatically resizes the pop up description based on the text inside it
 * PARAMETERS
 *  b           : [IN]        Is the pop up description
 *  width       : [IN]        Is the maximum width
 *  height      : [IN]        Is the maximum height
 * RETURNS
 *  1 : there is some text in the pop up (Pop up can be displayed)
 *  0 : there is no text in the pop up (Pop up need not be displayed)
 *****************************************************************************/
extern U8 gui_autoresize_pop_up_description(UI_pop_up_description *b, S32 width, S32 height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_pop_up_description_start_scroll
 * DESCRIPTION
 *  Start scrolling the popuup description.
 * PARAMETERS
 *  m       : [IN]          Is the pop up description.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_pop_up_description_start_scroll(UI_pop_up_description *m);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_pop_up_description_stop_scroll
 * DESCRIPTION
 *  Stop scroll popup description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_pop_up_description_stop_scroll(void);

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_setup_pop_up_description_transition
 * DESCRIPTION
 *  Setup the transition animation of the pop up descriptions
 * PARAMETERS
 *  b       : [IN]        Is the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_setup_pop_up_description_transition(UI_pop_up_description *b);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_reset_pop_up_description_transition
 * DESCRIPTION
 *  Setup the transition animation of the pop up descriptions
 * PARAMETERS
 *  b       : [IN]        Is the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_reset_pop_up_description_transition(UI_pop_up_description *b);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_reset_pop_up_description_transition_ex
 * DESCRIPTION
 *  Setup the transition animation of the pop up descriptions
 * PARAMETERS
 *  b       : [IN]        Is the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_reset_pop_up_description_transition_ex(UI_pop_up_description *b);
#endif 


/* 
 * scrolling text
 */


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  default_scrolling_text_draw_background
 * DESCRIPTION
 *  The default function to show scrolling text background
 * PARAMETERS
 *  x1      : [IN]        The x coordinate of left-top corner
 *  y1      : [IN]        The y coordinate of left-top corner
 *  x2      : [IN]        The x coordinate of right-bottom corner
 *  y2      : [IN]        The y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
extern void default_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_struct>
 * FUNCTION
 *  gui_create_scrolling_text
 * DESCRIPTION
 *  Create a scrolling text
 * PARAMETERS
 *  s                 : [IN/OUT]         The pointer to scrollint text
 *  x                 : [IN]             The x coordinate of scrolling text
 *  y                 : [IN]             The y coordinate of scrolling text
 *  width             : [IN]             The width of scrolling text
 *  height            : [IN]             The height of scrolling text
 *  text              : [IN]             The string of scrolling text
 *  timer_callback    : [IN]             The callback of hander this scrolling text
 *  draw_background   : [IN]             The callback of show scrolling text's background
 *  text_color        : [IN]             The color of string
 *  border_color      : [IN]             The border color of string
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_create_scrolling_text(
                scrolling_text *s, 
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height, 
                UI_string_type text,
                void (*timer_callback)(void), 
                void (*draw_background)(S32 x1, S32 y1, S32 x2, S32 y2), 
                color text_color,
                color border_color);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_redraw_scrolling_text
 * DESCRIPTION
 *  Redraw the scrolling text
 * PARAMETERS
 *  s       : [IN]          The pointer to scrolling text     
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_redraw_scrolling_text(scrolling_text *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_handle_scrolling_text
 * DESCRIPTION
 *  Scrolling text handle function, this function update scrolling text' state
 * PARAMETERS
 *  s       : [IN]          The pointer of scrolling text
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_handle_scrolling_text(scrolling_text *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_scrolling_text_start
 * DESCRIPTION
 *  Start scrolling text to scroll
 * PARAMETERS
 *  s       : [IN]          The pointer of scrolling text
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_scrolling_text_start(scrolling_text *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_scrolling_text_stop
 * DESCRIPTION
 *  Stop a scrolling text
 * PARAMETERS
 *  s       : [IN]      The pointer to scrolling text
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_scrolling_text_stop(scrolling_text *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_scrolling_text
 * DESCRIPTION
 *  Show a scrolling text
 * PARAMETERS
 *  s       : [IN]      The pointer to scrolling text
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_show_scrolling_text(scrolling_text *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_change_scrolling_text_font
 * DESCRIPTION
 *  Change the scrolling text's font
 * PARAMETERS
 *  s           : [IN]           The pointer to scrolling text
 *  font        : [IN]           The new font of scrolling text
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_change_scrolling_text_font(scrolling_text *s, UI_font_type font);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_change_scrolling_text
 * DESCRIPTION
 *  Change the scrolling text's string
 * PARAMETERS
 *  s           : [IN]         The pointer to scrolling text
 *  text        : [IN]         The new string to scrolling text
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_change_scrolling_text(scrolling_text *s, UI_string_type text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_force_scrolling_text
 * DESCRIPTION
 *  Create a force scrolling text, the scrolling text will be scrolling
 * PARAMETERS
 *  s                   : [IN]            The pointer to scrolling text         
 *  x                   : [IN]            The x coordinate of scrolling text
 *  y                   : [IN]            The y cooridnate of scrolling text
 *  width               : [IN]            The width of scrolling text
 *  height              : [IN]            The height of scrolling text
 *  text                : [IN]            The string of scrolling text
 *  timer_callback      : [IN]            The callback of update scrolling text
 *  draw_background     : [IN]            The callback to show scrolling text's background
 *  text_color          : [IN]            The color of scrolling text's string
 *  border_color        : [IN]            The border color of scrolling text's string
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_force_scrolling_text(
                scrolling_text *s, 
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height, 
                UI_string_type text,
                void (*timer_callback)(void), 
                void (*draw_background)(S32 x1, S32 y1, S32 x2, S32 y2), 
                color text_color,
                color border_color);


/* 
 * multiple layer screen utility 
 */


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_is_entry_new_screen
 * DESCRIPTION
 *  To check entry a new screen or not
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U8 gui_is_entry_new_screen(void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_entry_new_screen
 * DESCRIPTION
 *  Set a flag to indicator entry a new screen.
 * PARAMETERS
 *  new_entry       : [IN]        The new value of flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_entry_new_screen(U8 new_entry);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_free_multilayer_screen
 * DESCRIPTION
 *  Free screen's multi layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_free_multilayer_screen(void);



/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_layer_transparent
 * DESCRIPTION
 *  Show a transparent range in layer
 * PARAMETERS
 *  gui_show_layer      : [IN]          The layer hander 
 *  trans_value         : [IN]          The transparent color
 *  x1                  : [IN]          The x1 of transparent range
 *  y1                  : [IN]          The y1 of transparent range
 *  x2                  : [IN]          The x2 of transparent range
 *  y2                  : [IN]          The y2 of transparent range
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_layer_transparent(S32 gui_show_layer, U8 trans_value, S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_layer_show_animation_file
 * DESCRIPTION
 *  Show a animate from file into layer
 * PARAMETERS
 *  gui_show_layer      : [IN]          The layer handler
 *  trans_value         : [IN]          The transparent color of layer
 *  frame_idx           : [IN]          The index of animate frame         
 *  file_name           : [IN]          The path of animate file
 *  x1                  : [IN]          The x1 of clip
 *  y1                  : [IN]          The y1 of clip
 *  x2                  : [IN]          The x2 of clip
 *  y2                  : [IN]          The y2 of clip
 *  image_x1            : [IN]          The x coordinate of show animate
 *  image_y1            : [IN]          The y coordinate of show animate
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_layer_show_animation_file(
                S32 gui_show_layer,
                U8 trans_value,
                S32 *frame_idx,
                S8 *file_name,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                S32 image_x1,
                S32 image_y1);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_layer_show_animation_ID
 * DESCRIPTION
 *  Show 
 * PARAMETERS
 *  gui_show_layer      : [IN]          The layer handler
 *  trans_value         : [IN]          The transparent color of layer
 *  frame_idx           : [IN]          The index of animate frame         
 *  image_id            : [IN]          The image id of animate
 *  x1                  : [IN]          The x1 of clip
 *  y1                  : [IN]          The y1 of clip
 *  x2                  : [IN]          The x2 of clip
 *  y2                  : [IN]          The y2 of clip
 *  image_x1            : [IN]          The x coordinate of show animate
 *  image_y1            : [IN]          The y coordinate of show animate       
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_layer_show_animation_ID(
                S32 gui_show_layer,
                U8 trans_value,
                S32 *frame_idx,
                U16 image_id,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                S32 image_x1,
                S32 image_y1);
/* multiple layer mask */


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_multilayer_mask
 * DESCRIPTION
 *  Set multilayer mask for screen
 * PARAMETERS
 *  in_multilayer_mask      : [IN]      The new value of mask      
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_multilayer_mask(S32 in_multilayer_mask);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_get_multilayer_mask
 * DESCRIPTION
 *  Get multilayer maks of screen
 * PARAMETERS
 *  void
 * RETURNS
 *  The multilayer mask of screen
 *****************************************************************************/
extern U16 gui_get_multilayer_mask(void);


/* Touch Panel - Utility functions for waiting longtap animation */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * <group dom_utility_gui_layer_touch>
 * FUNCTION
 *  gui_pen_wait_longpress
 * DESCRIPTION
 *  Show pen event wait animate when process pen event
 * PARAMETERS
 *  pen_event       : [IN]              The pen event
 *  x               : [IN]              The x coordinate of pen event
 *  y               : [IN]              The y coordinate of pen event
 * RETURNS
 *  
 *****************************************************************************/
extern gui_wait_longpress_enum gui_pen_wait_longpress(mmi_pen_event_type_enum pen_event, S16 x, S16 y);

#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __GUI_WINDOWS_H__ */


