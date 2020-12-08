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
 *  wgui_editor.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Editor APIs for MRE APP
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 * 
 * 09 03 2012 liu.cheng
 * removed!
 * .
 * 
 * 07 27 2012 liu.cheng
 * removed!
 * process key for qwerty key pad.
 *
 * 07 14 2012 hongtao.liu
 * removed!
 * add API : vm_editor_show_from_first_line
 *
 * 06 27 2012 liu.cheng
 * removed!
 * .
 *
 * 06 04 2012 liu.cheng
 * removed!
 * Fix build error.
 *
 * 06 04 2012 liu.cheng
 * removed!
 * Add update text callback with cursor rect.
 *
 * 04 24 2012 liu.cheng
 * removed!
 * .
 *
 * 04 06 2012 liu.cheng
 * removed!
 * .
 *
 * 04 01 2012 liu.cheng
 * removed!
 * fix some ui bug
 *
 * 03 31 2012 liu.cheng
 * removed!
 * .
 *
 * 03 30 2012 liu.cheng
 * removed!
 * .
 *
 * 03 26 2012 liu.cheng
 * removed!
 * .
 *
 * 03 08 2012 liu.cheng
 * removed!
 * .
 *
 * 03 08 2012 liu.cheng
 * removed!
 * .
 *
 * 03 05 2012 liu.cheng
 * removed!
 * .
 *
 * 03 05 2012 liu.cheng
 * removed!
 * .
 *
 * 03 02 2012 liu.cheng
 * removed!
 * .
 *
 * 02 17 2012 liu.cheng
 * removed!
 * .
 *
 * 02 07 2012 liu.cheng
 * removed!
 * .
 *
 * 02 06 2012 liu.cheng
 * removed!
 * .
 *
 * 01 11 2012 liu.cheng
 * removed!
 * .
 *
 * 01 10 2012 liu.cheng
 * removed!
 * .
 *
 * 01 09 2012 liu.cheng
 * removed!
 * .
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 *******************************************************************************/

#include "MMIDataType.h"

#include "MMI_features.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

#include "gui_data_types.h"
#include "gui.h"
#include "gui_typedef.h"
#include "gui_inputs.h"
#include "ImeGprot.h"
#include "ImeGprotEnums.h"

 
#ifndef __WGUI_EDITOR_H__
#define __WGUI_EDITOR_H__

/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum
{
    WGUI_EDITOR_SINGLELINE,
    WGUI_EDITOR_MULTILINE,
    WGUI_EDITOR_END
} WGUI_EDITOR_TYPE;

typedef enum
{
    WGUI_EDITOR_NO_BORDER,
    WGUI_EDITOR_SINGLE_BORDER,
    WGUI_EDITOR_DOUBLE_BORDER,
    WGUI_EDITOR_BORDER_END
} WGUI_EDITOR_BORDER_TYPE;

/* For use GMS encoding mode. */
#define INPUT_SETTING_USE_ENCODING_BASED_LENGTH    0x00000001

/* For No-Show New Line Symbol. */
//#define INPUT_SETTING_EXT_NO_SHOW_NEW_LINE_SYMBOL  0x00000002




typedef void (* soft_key_handle_funcptr)(void);

typedef struct
{
    U8 is_valid; 
    WGUI_EDITOR_TYPE editor_type;
    S16 text_length;
    S16 allocated_length;
    S16 available_length;
    S16 current_position;
    S16 text_offset_x;
    S16 UCS2_count;
    U32 flags;
    mmi_imc_history ime_history;
    
    S16 n_lines;
    S16 text_height;    
    S16 text_offset_y;
    S16 cursor_x;
    S16 cursor_y;
    S16 cursor_line_position_counter;
    S16 line_before_cursor_line_p;
    S16 cursor_line_p;    
    S16 input_mode_cursor_p;
    S16 line_after_cursor_line_p;
    S16 line_after_cursor_line_last_p;
    S16 last_position_p;
    U8 pre_scrollbar_state;
    S32 pre_height;
    mmi_imm_input_mode_enum input_mode;
    S16 input_mode_start_p;
    S32 last_cursor_offset;
    U8  changed;
    //S8 state;   /* To keep current screen state in history buffer. */
	U32     ext_flags;
} wgui_editor_history_struct;

typedef struct
{
    S32 x1, y1, x2, y2;
} wgui_editor_rect_points, *wgui_editor_rect_points_p;

typedef struct
{
    WGUI_EDITOR_TYPE editor_type;                       //editor type
    MMI_BOOL is_disable_softkey;                        //whether disable softkey or not
    GDI_HANDLE layer_handle;                            //layer handle id
    mmi_imm_input_type_enum input_type;                 //input type
    S32 input_setting;                                  //input setting
    mmi_imm_input_mode_enum *input_mode_array;           //set of input mode 
    mmi_imm_input_mode_enum default_input_mode;         //default input mode
    mmi_imc_message_funcptr ime_msg_callback;           //ime message callback function
    soft_key_handle_funcptr softkey_handle[WGUI_MAX_SOFTKEYS];     //softkey handle
    UI_string_type softkey_label[WGUI_MAX_SOFTKEYS];    //softkey label
    PU8 softkey_icon[WGUI_MAX_SOFTKEYS];                //softkey icon    
    U8 RSK_label_clear;                                 //RSK label is clear
    stFontAttribute text_font;                          //text font
    void (*update_text_callback) (UI_buffer_type text, UI_buffer_type cursor, S32 text_length);
    void (*update_text_with_cursor_rect_callback) (UI_buffer_type text, UI_buffer_type cursor, S32 text_length, wgui_editor_rect_points_p cursor_rect_points);
    UI_filled_area focussed_bg_filler, normal_bg_filler;  //background filler(resource)
    gui_inputs_bg_mem_image_struct normal_mem_bg_image, focussed_mem_bg_image;   //background image(from memory)
    wgui_editor_history_struct *history;   
    void *editor;                                   //editor object(multiline or singleline)
} wgui_editor_struct;



/***************************************************************************** 
* Extern Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_memory_size
 * DESCRIPTION
 *  Get memory size of an editor instance
 * PARAMETERS
 *  editor_type     [IN]        Is the editor type
 * RETURNSwgui_cat
 *  U32: memory size of an editor instance
 *****************************************************************************/
extern U32 wgui_editor_get_memory_size(WGUI_EDITOR_TYPE editor_type);


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_create
 * DESCRIPTION
 *  Creates an editor
 * PARAMETERS
 *  buffer                  [IN/OUT]    Is the wgui editor buffer (pre-allocated)
 *  editor_type             [IN]        Is the editor type
 *  x                       [IN]        Is the left-top corner
 *  y                       [IN]        Is the left-top corner
 *  width                   [IN]        Is the width of the editor
 *  height                  [IN]        Is the height of the editor
 *  text_buffer             [IN]        Is the text buffer the editor should use (pre-allocated)
 *  text_buffer_size        [IN]        Is the text buffer size in Bytes
 *  is_disable_softkey      [IN]        disable softkey or not
 *  layer_handle            [IN]        Is the layer handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_create(
                wgui_editor_struct *buffer,
                WGUI_EDITOR_TYPE editor_type,
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                UI_string_type text_buffer,
                S32 text_buffer_size,
                MMI_BOOL is_disable_softkey,
                GDI_HANDLE layer_handle);

                

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_close
 * DESCRIPTION
 *  Close the editor
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_close(wgui_editor_struct *b);


/*****************************************************************************
* FUNCTION
*  wgui_editor_set_IME
* DESCRIPTION
*  set ime
* PARAMETERS
*  b                           [IN/OUT]    Is the wgui editor instance
*  input_type                  [IN]        Is the input type
*  input_setting               [IN]        Is the input setting
*  input_mode_array            [IN]        Is the input mode set, can pass null to use default mode set
*  default_input_mode          [IN]        Is the highest priority input mode in the mode set, can pass 0 to use default
*  mmi_imc_message_funcptr     [IN]        Is the ime callback function
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_set_IME(
                         wgui_editor_struct *b,
                         mmi_imm_input_type_enum input_type,
                         S32 input_setting,
                         mmi_imm_input_mode_enum *input_mode_array,
                         mmi_imm_input_mode_enum default_input_mode,
                         mmi_imc_message_funcptr ime_callback);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_softkey
 * DESCRIPTION
 *  set softkey
 * PARAMETERS
 *  b                           [IN/OUT]    Is the wgui editor instance
 *  s                           [IN]        Is the label
 *  icon                        [IN]        Is the icon
 *  key                         [IN]        Is softkey type
 *  f                           [IN]        Is the softkey handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_softkey(
                wgui_editor_struct *b,
                UI_string_type s,
                PU8 icon,
                WGUI_SOFTKEY_ENUM key,
                void (*f) (void));


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_show
 * DESCRIPTION
 *  Display the editor (not blt)
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_show(wgui_editor_struct *b);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_redraw
 * DESCRIPTION
 *  Display the active editor (show and blt)
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_redraw(wgui_editor_struct *b);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_text_font
 * DESCRIPTION
 *  set text font
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  text_font       [IN]        Is the text font
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_text_font(wgui_editor_struct *b, UI_font_type text_font);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_fit_text_font
 * DESCRIPTION
 *  set fit text font according to editor's height autoly for single line editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  text_font       [IN]        Is the text font
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_fit_text_font(wgui_editor_struct *b);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_bg_image_from_resource
 * DESCRIPTION
 *  set the normal and focuss image pointers for image background from resource
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  b                   [IN]        Is the wgui editor instance
 *  focussed_image      [IN]        Is the focuss image
 *  normal_image        [IN]        Is the normal image
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_bg_image_from_resource(wgui_editor_struct *b, PU8 focussed_image, PU8 normal_image);


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_bg_image_from_memory
 * DESCRIPTION
 *  set the normal and focuss image pointers for image background from memory
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  b                       [IN]        Is the wgui editor instance
 *  focussed_image          [IN]        Is the focuss image
 *  normal_image            [IN]        Is the normal image
 *  focussed_image_length   [IN]        Is the image length of focuss image
 *  normal_image_length     [IN]        Is the image length of normal image
 *  focussed_image_type     [IN]        Is the image type of focuss image
 *  normal_image_type       [IN]        Is the image type of normal image
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_bg_image_from_memory(
        wgui_editor_struct *b,
        PU8 focussed_image,
        PU8 normal_image,
        S32 focussed_image_length,
        S32 normal_image_length,
        U8 focussed_image_type,
        U8 normal_image_type);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_bg_border_style
 * DESCRIPTION
 *  set border style for rectangle background
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  b                       [IN]        Is the wgui editor instance
 *  border_width            [IN]        Is the border width(no border/single border/double border)
 *  border_normal_color     [IN]        Is the border color of normal style
 *  border_focussed_color     [IN]        Is the border color of focuss style
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_bg_border_style(wgui_editor_struct *b, WGUI_EDITOR_BORDER_TYPE border_width, color border_normal_color, color border_focussed_color);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_margin
 * DESCRIPTION
 *  set margin for editor
 *  (for singleline, align center along y direction)
 * PARAMETERS
 *  b           [IN/OUT]    Is the wgui editor instance
 *  top         [IN]        top >0: set new value; -1: use default value
 *  down        [IN]        down >0: set new value; -1: use default value
 *  left        [IN]        left >0: set new value; -1: use default value
 *  right       [IN]        right >0: set new value; -1: use default value
 * RETURNS
 *  byte
 *****************************************************************************/
extern void wgui_editor_set_margin(wgui_editor_struct *b, S32 top, S32 down, S32 left, s32 right);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_pos
 * DESCRIPTION
 *  Move the editor
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 *  x               [IN]        Is the left-top corner
 *  y               [IN]        Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_pos(wgui_editor_struct *b, S32 x, S32 y);


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_size
 * DESCRIPTION
 *  Resize the editor
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 *  width           [IN]        Is the width of the editor
 *  height          [IN]        Is the height of the editor
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_size(wgui_editor_struct *b, S32 width, S32 height);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_text_color
 * DESCRIPTION
 *  set text color
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 *  text_color      [IN]        Is the text color
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_text_color(wgui_editor_struct *b, color text_color);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_cursor_color
 * DESCRIPTION
 *  set cursor color
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 *  cursor_color    [IN]        Is the cursor color
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_cursor_color(wgui_editor_struct *b, color cursor_color);

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_layer_handle
* DESCRIPTION
*  set editor layer handle
* PARAMETERS
*  b                           [IN/OUT]    Is the wgui editor instance
*  layer_handle                [IN]        Is the layer handle
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_set_layer_handle(wgui_editor_struct *b, GDI_HANDLE layer_handle);

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_is_draw_ime_floating_indicator
* DESCRIPTION
*  set if draw ime floating indicator
* PARAMETERS
*  is_draw_ime_floating_indicator        [IN]        if draw ime floating indicator
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_set_is_draw_ime_floating_indicator(MMI_BOOL is_draw_ime_floating_indicator);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_update_text_callback
 * DESCRIPTION
 *  set update text call back
 * PARAMETERS
 *  b                           [IN/OUT]    Is the wgui editor instance
 *  f                           [IN]        Is update text callback
 * RETURNS
 *  void
*****************************************************************************/
extern void wgui_editor_set_update_text_callback(
                wgui_editor_struct *b, 
                void (*f)(UI_buffer_type text, UI_buffer_type cursor, S32 text_length));

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_update_text_with_cursor_rect_callback
 * DESCRIPTION
 *  set update text call back(with curosr x, y info)
 * PARAMETERS
 *  b                           [IN/OUT]    Is the wgui editor instance
 *  f                           [IN]        Is update text with x y callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_update_text_with_cursor_rect_callback(
    wgui_editor_struct *b, 
    void (*f)(UI_buffer_type text, UI_buffer_type cursor, S32 text_length, wgui_editor_rect_points_p cursor_rect_points));


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_pos
 * DESCRIPTION
 *  Get editor position
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  x               [OUT]       Is the left-top corner
 *  y               [OUT]       Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_get_pos(wgui_editor_struct *b, S32 *x, S32 *y);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_cursor_index
 * DESCRIPTION
 *  Set editor cursor index
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  cursor_index    [IN]        Is the cursor index
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_cursor_index(wgui_editor_struct *b, U32 cursor_index);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_cursor_index
 * DESCRIPTION
 *  Get editor cursor index
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 * RETURNS
 *  S32: cursor index
 *****************************************************************************/
extern S32 wgui_editor_get_cursor_index(wgui_editor_struct *b);



/*****************************************************************************
* FUNCTION
*  wgui_editor_get_size
* DESCRIPTION
* get editor size
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  width           [OUT]        Is the width of the editor
*  height          [OUT]        Is the height of the editor
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_get_size(wgui_editor_struct *b, S32 *width, S32 *height);


/*****************************************************************************
* FUNCTION
*  wgui_editor_get_fit_height
* DESCRIPTION
*  get fit editor height according to the font size. only for singleline editor
* PARAMETERS
*  b               [IN]         Is the wgui editor instance
*  vertical_margin [IN]         Is the top/down margin
*  font_size       [IN]         Is the font size
* RETURNS
*  fit singleline editor height
*****************************************************************************/
extern S32 wgui_editor_get_fit_height(S32 vertical_margin, U8 font_size);

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_text
* DESCRIPTION
*  Set text
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  text_buffer     [IN]        Is the text buffer
*  buffer_size     [IN]        Is the buffer size(byte)
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_set_text(wgui_editor_struct *b, UI_string_type text_buffer, S32 buffer_size);

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_default_text
* DESCRIPTION
*  Set default text
* PARAMETERS
*  b                       [IN]        Is the wgui editor instance
*  default_text_buffer     [IN]       Is the default text buffer
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_set_default_text(wgui_editor_struct *b, UI_string_type default_text_buffer);

/*****************************************************************************
* FUNCTION
*  wgui_editor_insert_string
* DESCRIPTION
*  insert string
* PARAMETERS
*  b                       [IN]        Is the wgui editor instance
*  str                     [IN]        Is the string to be inserted
*  len                     [IN]        string length
* RETURNS
*  U32: length of the string actually inserted
*****************************************************************************/
extern U32 wgui_editor_insert_string(wgui_editor_struct *b, UI_string_type str, U32 len);



/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_text
 * DESCRIPTION
 *  Set text
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  text_buffer     [IN/OUT]    Is the text buffer
 *  buffer_size     [IN]        Is the buffer size(byte)
 * RETURNS
 *  S32: text length
 *****************************************************************************/
extern S32 wgui_editor_get_text(wgui_editor_struct *b, UI_string_type text_buffer, S32 buffer_size);


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_activate
 * DESCRIPTION
 *  Activate the editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_activate(wgui_editor_struct *b, MMI_BOOL showVK);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_deactivate
 * DESCRIPTION
 *  Deactivate the editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  showVK          [IN]        If show VK when activate
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_deactivate(wgui_editor_struct *b);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_active_editor
 * DESCRIPTION
 *  Get current active editor
 * PARAMETERS
 *  b               [IN]        Is the pointer point to the wgui editor pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_get_active_editor(wgui_editor_struct **b);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_process_key
 * DESCRIPTION
 *  process key
 * PARAMETERS
 *  keyCode               [IN]        key code
 *  keyType               [IN]        key type
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL wgui_editor_process_key(U16 keyCode, U16 keyType);

/*****************************************************************************
* FUNCTION
*  wgui_editor_process_key_ext
* DESCRIPTION
*  process key(include qwerty key)
* PARAMETERS
*  keyCode               [IN]        key code
*  keyType               [IN]        key type
*  ucs2_value            [IN]
*  special_key_flag      [IN]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL wgui_editor_process_key_ext(U16 keyCode, U16 keyType, U16 ucs2_value, U32 special_key_flag);

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_editor_process_pen
 * DESCRIPTION
 *  process pen
 * PARAMETERS
 *  pos                     [IN]        pen position
 *  eventType               [IN]        pen event type
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL wgui_editor_process_pen(mmi_pen_point_struct pos , mmi_pen_event_type_enum eventType);
#endif /*__MMI_TOUCH_SCREEN__*/

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_save
 * DESCRIPTION
 *  Save gui info of editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  history_buffer  [IN]        Is the buffer used to save eidtor info
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_save(wgui_editor_struct *b, U8 *history_buffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_restore
 * DESCRIPTION
 *  Restore history gui info to editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  history_buffer  [IN]        Is the saved eidtor info
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_restore(wgui_editor_struct *b, U8 *history_buffer);


/* the following api pack IME related api */
/*****************************************************************************
 * FUNCTION
 *  wgui_editor_redraw_ime_floating_ui_within_rect
 * DESCRIPTION
 *  Redraw ime floating ui within given rectangle area
 * PARAMETERS
 *  rect               [IN]        Is the given rectangle area
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_redraw_ime_floating_ui_within_rect(mmi_imc_rect_p rect);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_redraw_ime_screen
 * DESCRIPTION
 *  Redraw ime UIs(floating ui and fixed ui) 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_redraw_ime_screen(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_extra_imui_layer_handler
 * DESCRIPTION
 *  get extra imui layer handler (like handwriting drawn layer)
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
extern GDI_HANDLE wgui_editor_get_extra_imui_layer_handler(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_imui_background_filler
 * DESCRIPTION
 *  set imui background filler
 * PARAMETERS
 *  draw_imui_background_funcptr        [in]        draw imui background funtion pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_editor_set_imui_background_filler(void (*draw_imui_background_funcptr)(S32 x1, S32 y1, S32 x2, S32 y2));

/*****************************************************************************
* FUNCTION
*  wgui_editor_show_from_start
* DESCRIPTION
*  jump to start to show from the beginning
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
* RETURNS
*  void
*****************************************************************************/
extern void wgui_editor_show_from_start(wgui_editor_struct *b);

#endif /*__WGUI_EDITOR_H__*/
