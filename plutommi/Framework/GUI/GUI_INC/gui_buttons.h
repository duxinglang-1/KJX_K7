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
 *   gui_buttons.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Button - UI component 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 20 2013 hujin.hu
 * removed!
 * .
 *
 * 12 25 2012 hujin.hu
 * removed!
 * .
 *
 * 07 06 2011 junqi.guan
 * removed!
 * add disable drag flag.
 *
 * 02 08 2011 ray.wu
 * removed!
 * .
 *
 * 02 08 2011 mason.chang
 * removed!
 * Rename/move file(s)
 *
 * 01 07 2011 helena.li
 * removed!
 * .
 *
 * 12 14 2010 helena.li
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/

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
   Filename:      gui_buttons.h
   Author:        manju
   Date Created:  August-13-2002
   Contains:      PixTel UI routines header for buttons
**********************************************************************************/

#ifndef __GUI_BUTTONS_H__
#define __GUI_BUTTONS_H__

/* DOM-NOT_FOR_SDK-BEGIN */

#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "gui_data_types.h"

/* MTK Leo add,20040318, for new simulator */
#include "gui_theme_struct.h"
#include "CustThemesRes.h"

#include "gui_typedef.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#ifdef __MMI_TOUCH_SCREEN__

/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_struct>
 * Struct of button's pen state.
 */
    typedef struct
    {
    /* pen is in button's area or not */
        U8 pen_inside;
    } gui_button_pen_state_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  gui_button_clear_background_hdlr
 * DESCRIPTION
 *  Clear background function handler of button.
 * PARAMETERS
 *  button_object           : [IN] Is the button object
 * RETURNS
 *  void
 *****************************************************************************/
    typedef void (*gui_button_clear_background_hdlr) (void *button_object);

/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef __MMI_TOUCH_SCREEN__
    typedef MMI_BOOL (*gui_button_draw_button_hdlr) (void *button_object);
#endif

/* <group dom_buttons_variables>
 *  UI button structure                    */
    extern UI_button_theme *current_button_theme;

/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_macro_flags>
 *  Is a button type which represents a normal button. */
#define UI_BUTTON_TYPE_NORMAL                   0x00000000
/* <group dom_buttons_macro_flags>
 *  Is a button type which represents a toggle button. */
#define UI_BUTTON_TYPE_TOGGLE                   0x00000001

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents the up state of a button. */
#define UI_BUTTON_STATE_UP                      0x00000000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents the down state of a button. */
#define UI_BUTTON_STATE_DOWN                    0x00000100
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents the normal state of a button. */
#define UI_BUTTON_STATE_NORMAL                  0x00000000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents the disabled state of a button. */
#define UI_BUTTON_STATE_DISABLED                0x00000200
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents the focussed state of a button. */
#define UI_BUTTON_STATE_FOCUSSED                0x00000400
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents the clicked state of a button. */
#define UI_BUTTON_STATE_CLICKED                 0x00000800

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that button's display will be shifted 1 pixel to rigth-bottom corner when pressed. */
#define UI_BUTTON_SHIFT_BUTTON1                 0x00001000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that button's display will be shifted 2 pixel to rigth-bottom corner when pressed. */
#define UI_BUTTON_SHIFT_BUTTON2                 0x00002000
/* <group dom_buttons_macro_flags>
 *  Is a flag which disable icontext button to display background. */
#define UI_BUTTON_DISABLE_BACKGND_DISPLAY       0x00004000
/* <group dom_buttons_macro_flags>
 *  Is a flag which disable icontext button to display text. */
#define UI_BUTTON_DISABLE_TEXT_DISPLAY          0x00008000
/* <group dom_buttons_macro_flags>
 *  Is a flag which disable icontext button to display image. */
#define UI_BUTTON_DISABLE_IMAGE_DISPLAY         0x00000010

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that text button and icontext button will use center-align to show its text in X direction. */
#define UI_BUTTON_TEXT_WITH_BORDER                 0x00000020
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that text button and icontext button will use center-align to show its text in X direction. */
#define UI_BUTTON_CENTER_TEXT_X                 0x00010000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that text button and icontext button will use center-align to show its text in Y direction. */
#define UI_BUTTON_CENTER_TEXT_Y                 0x00020000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that text button and icontext button will shift its text to show press effect. */
#define UI_BUTTON_SHIFT_TEXT                    0x00040000

/* DOM-NOT_FOR_SDK-BEGIN */

/* <group dom_buttons_macro>
 *  shift icon of button */
#define UI_BUTTON_SHIFT_ICON                    0x00080000

/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that icon button and icontext button will use center-align to show its icon in X direction. */
#define UI_BUTTON_CENTER_ICON_X                 0x00100000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that icon button and icontext button will use center-align to show its icon in Y direction. */
#define UI_BUTTON_CENTER_ICON_Y                 0x00200000

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that icontext button will show button without button bar. */
#define UI_BUTTON_NO_UNDER_BAR                  0x00400000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that icontext button will align icon and text and display. */
#define UI_BUTTON_ALIGN_ICON_TEXT               0x00800000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that icontext button will use left-align to show its content in X direction. */
#define UI_BUTTON_LEFT_ALIGN                    0x01000000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that icontext button will use right-align to show its content in X direction. */
#define UI_BUTTON_RIGHT_ALIGN                   0x02000000

/* DOM-NOT_FOR_SDK-BEGIN */

/* <group dom_buttons_macro_flags>
 *  Always send GUI_BUTTON_PEN_UP_INSIDE even when pen is up outside the button */
#define UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE     0x04000000
/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that button do not shift when pressed. */
#define UI_BUTTON_NO_SHIFT_BUTTON               0x08000000
/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that every point's pen event will be responsed if the point is in button's area. */
#define UI_BUTTON_FULL_TOUCH_AREA               0x10000000

#if defined(__MMI_VECTOR_FONT_SUPPORT__)

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that text button and icontext button will disable text's transluence of vector font. */
#define UI_BUTTON_TEXT_NO_TRANSLUCENCE          0x20000000

#endif

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that softkey will enable double buffer. */
#define UI_BUTTON_ENABLE_DOUBLE_BUFFER          0x40000000

/* <group dom_buttons_macro_flags>
 *  Is a flag which represents that scrollbutton will disable drag. */
#define UI_BUTTON_DISABLE_DRAG          0x80000000

/* <group dom_buttons_macro>
 *  Is a gap which represents the space between icontext button's content and its border in X direction.
 * REMARKS
 * This gap only works when icontext button has UI_BUTTON_LEFT_ALIGN or UI_BUTTON_RIGHT_ALIGN flag.
 */
#define GUI_BUTTON_HORIZONTAL_GAP               2
/* <group dom_buttons_macro>
 *  Is a gap which represents the space between icontext button's content and its border in Y direction. */
#define GUI_BUTTON_VERTICAL_GAP                 2

/* DOM-NOT_FOR_SDK-BEGIN */

/* <group dom_buttons_macro>
 *  Button's text border width in pixel. */
#define GUI_BUTTON_TEXT_BORDER                  1

typedef enum{
GUI_BUTTON,
GUI_TEXT_BUTTON,
GUI_ICON_BUTTON,
GUI_ICONTEXT_BUTTON
}gui_button_type;

/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_struct>
 * Struct of button component.
 */
    typedef struct _button
    {
    S32 x; /* Is the x position of button */
    S32 y; /* Is the y position of button */
    S32 width; /* Is the width of button */
    S32 height; /* Is the height of button */
    UI_filled_area *normal_up_filler; /* Is the background filler of button in its notmal up state */
    UI_filled_area *normal_down_filler; /* Is the background filler of button in its notmal down state */
    UI_filled_area *disabled_up_filler; /* Is the background filler of button in its disabled up state */
    UI_filled_area *disabled_down_filler; /* Is the background filler of button in its disabled down state */
    UI_filled_area *clicked_up_filler; /* Is the background filler of button in its clicked up state */
    UI_filled_area *clicked_down_filler; /* Is the background filler of button in its clicked down state */
    UI_filled_area *focussed_up_filler; /* Is the background filler of button in its focussed up state */
    UI_filled_area *focussed_down_filler; /* Is the background filler of button in its focussed down state */
    U32 flags; /* Is the flag of button */

     /* Is the clear background function handler of button
      * SEE ALSO
      * You should also know gui_button_clear_background_hdlr as well.
      */
        gui_button_clear_background_hdlr clear_background_fp;

    #ifdef __MMI_TOUCH_SCREEN__
    /* Is button's pen state which is supported only in touch projects */
        gui_button_pen_state_struct pen_state;
    #endif 
    } button;


/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_button_current_theme
 * DESCRIPTION
 *  Applies the current system theme to a button object.
 * PARAMETERS
 *  b            : [IN] Is the button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_set_button_current_theme(button *b);

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_button_theme
 * DESCRIPTION
 *  Applies the given theme to a button object.
 * PARAMETERS
 *  b            : [IN] Is the button object
 *  t            : [IN] Is the given theme
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_set_button_theme(button *b, UI_button_theme *t);

/*****************************************************************************
 * <group dom_buttons_struct>
 * FUNCTION
 *  gui_create_button
 * DESCRIPTION
 *  Create a button object.
 * REMARKS
 *  Memory must be allocated to the button object before call this API.
 * PARAMETERS
 *  b           : [IN] Is the button object
 *  x           : [IN] Is the x position of button
 *  y           : [IN] Is the y position of button
 *  width       : [IN] Is the width of button
 *  height      : [IN] Is the height of button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_create_button(button *b, S32 x, S32 y, S32 width, S32 height);

/*****************************************************************************
 * <group dom_buttons_struct>
 * FUNCTION
 *  gui_show_button
 * DESCRIPTION
 *  Draw a button object to main LCD. This API will only draw the background 
 *  and content of button. It will not blt button to the main LCD.
 * PARAMETERS
 *  b           : [IN] Is the button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_show_button(button *b);


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_buttons_gui_layer_touch>
 * FUNCTION
 *  gui_button_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of a button object and display the corresponding effect.
 * PARAMETERS
 *  b                : [IN] Is the button object
 *  pen_event        : [IN] Is the pen event
 *  x                : [IN] Is the x position of pen
 *  y                : [IN] Is the y position of pen
 *  button_event     : [IN/OUT] Is the pointer of parameter to get button's pen event
 * RETURNS
 *  MMI_BOOL
 * Return Values
 *  MMI_TRUE: Button will handle the given pen event.
 *  MMI_FALSE: Button will not handle the given pen event.
 * REMARKS
 *  This API is supported only in touch projects.
 *****************************************************************************/
extern MMI_BOOL gui_button_translate_pen_event(
                    button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);

/* DOM-NOT_FOR_SDK-BEGIN */

#endif /* __MMI_TOUCH_SCREEN__ */ 

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

    /* UI text_button structure               */

    extern UI_text_button_theme *current_text_button_theme;

/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_struct>
 * Struct of text button component.
 */
    typedef struct _text_button
    {
    S32 x; /* Is the x position of text button */
    S32 y; /* Is the y position of text button */
    S32 width; /* Is the width of text button */
    S32 height; /* Is the height of text button */
    UI_filled_area *normal_up_filler; /* Is the background filler of text button in its notmal up state */
    UI_filled_area *normal_down_filler; /* Is the background filler of text button in its notmal down state */
    UI_filled_area *disabled_up_filler; /* Is the background filler of text button in its disable up state */
    UI_filled_area *disabled_down_filler; /* Is the background filler of text button in its disable down state */
    UI_filled_area *clicked_up_filler; /* Is the background filler of text button in its clicked up state */
    UI_filled_area *clicked_down_filler; /* Is the background filler of text button in its clicked down state */
    UI_filled_area *focussed_up_filler; /* Is the background filler of text button in its focussed up state */
    UI_filled_area *focussed_down_filler; /* Is the background filler of text button in its focussed down state */
    U32 flags; /* Is the flag of text button */
    S32 text_x; /* Is the logical x position of text */
    S32 text_y; /* Is the logical y position of text */
    S32 text_height; /* Is the text's height of text button */
    UI_string_type text; /* Is the text's content of text button */
    color normal_up_text_color; /* Is the text's color of text button in its notmal up state */
    color normal_down_text_color; /* Is the text's color of text button in its notmal down state */
    color disabled_up_text_color; /* Is the text's color of text button in its disabled up state */
    color disabled_down_text_color; /* Is the text's color of text button in its disabled down state */
    color focussed_up_text_color; /* Is the text's color of text button in its focussed up state */
    color focussed_down_text_color; /* Is the text's color of text button in its focussed down state */
    color clicked_up_text_color; /* Is the text's color of text button in its clicked up state */
    color clicked_down_text_color; /* Is the text's color of text button in its clicked down state */
    UI_font_type text_font; /* Is the text's font size of text button */
     /* Is the clear background function handler of text button
      * SEE ALSO
      * You should also know gui_button_clear_background_hdlr as well.
      */
        gui_button_clear_background_hdlr clear_background_fp;
    #ifdef __MMI_TOUCH_SCREEN__
    /* Is text button's pen state which is supported only in touch projects */
        gui_button_pen_state_struct pen_state;
    #endif 
    } text_button;


/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_text_button_current_theme
 * DESCRIPTION
 *  Applies the current system theme to a text button object.
 * PARAMETERS
 *  b        : [IN] Is the text button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_set_text_button_current_theme(text_button *b);


/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_text_button_theme
 * DESCRIPTION
 *  Applies the given theme to a text button object.
 * REMARKS
 *  The API will set background fillers, text color and text font size of given
 *  theme to a text button object.
 * PARAMETERS
 *  b        : [IN] Is the text button object
 *  t        : [IN] Is the given theme
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_set_text_button_BG_theme as well.
 *****************************************************************************/
    extern void gui_set_text_button_theme(text_button *b, UI_text_button_theme *t);


/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_text_button_BG_theme
 * DESCRIPTION
 *  Applies the given theme to a text button object.
 * REMARKS
 *  The API will only set background fillers of given theme to a text button object.
 * PARAMETERS
 *  b        : [IN]  Is the text button object
 *  t        : [IN]  Is text button's background theme
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_set_text_button_theme as well.
 *****************************************************************************/
    extern void gui_set_text_button_BG_theme(text_button *b, UI_button_theme *t);


/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_create_text_button
 * DESCRIPTION
 *  Create a text button object.
 * REMARKS
 *  Memory must be allocated to the text button object before call this API.
 * PARAMETERS
 *  b            : [IN] Is the text button object
 *  x            : [IN] Is the x position of text button
 *  y            : [IN] Is the y position of text button
 *  width        : [IN] Is the width of text button
 *  height       : [IN] Is the height of text button
 *  text         : [IN] Is the text content of text button
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_create_text_button(
             text_button *b,
             S32 x,
             S32 y,
             S32 width,
             S32 height,
             UI_string_type text);


/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_text_button_set_text_position
 * DESCRIPTION
 *  Set text's logical position to text button.
 * PARAMETERS
 *  b        : [IN] Is the text button object
 *  x        : [IN] Is the logical x position of text
 *  y        : [IN] Is the logical y position of text
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_text_button_set_text_position(text_button *b, S32 x, S32 y);


/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_show_text_button
 * DESCRIPTION
 *  Draw a text button object to main LCD. This API will only
 *  draw the background and text content of button. It will not blt text button
 *  to main LCD.
 * PARAMETERS
 *  b        : [IN] Is the text button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_show_text_button(text_button *b);


/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef __MMI_TOUCH_SCREEN__

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_buttons_gui_layer_touch>
 * FUNCTION
 *  gui_text_button_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of a text button object and display the corresponding effect.
 * PARAMETERS
 *  b                : [IN] Is the text button object
 *  pen_event        : [IN] Is the pen event
 *  x                : [IN] Is the x position of pen
 *  y                : [IN] Is the y position of pen
 *  button_event     : [IN/OUT] Is the pointer of parameter to get text button's pen event
 * RETURNS
 *  MMI_BOOL
 * Return Values
 *  MMI_TRUE: Text button will handle the given pen event.
 *  MMI_FALSE: Text button will not handle the given pen event.
 * REMARKS
 *  This API is supported only in touch projects.
 *****************************************************************************/
    extern MMI_BOOL gui_text_button_translate_pen_event(
                    text_button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);

/* DOM-NOT_FOR_SDK-BEGIN */
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_buttons_variables> */
    extern UI_icon_button_theme *current_icon_button_theme;
/* DOM-NOT_FOR_SDK-END */


/* <group dom_buttons_struct>
 * Struct of icon button component.
 */
    typedef struct _icon_button
    {
    S32 x; /* Is the x position of icon button */
    S32 y; /* Is the y position of icon button */
    S32 width; /* Is the width of icon button */
    S32 height; /* Is the height of icon button */
    UI_filled_area *normal_up_filler; /* Is the background filler of icon button in its notmal up state */
    UI_filled_area *normal_down_filler; /* Is the background filler of icon button in its notmal down state */
    UI_filled_area *disabled_up_filler; /* Is the background filler of icon button in its disabled up state */
    UI_filled_area *disabled_down_filler; /* Is the background filler of icon button in its disabled down state */
    UI_filled_area *clicked_up_filler; /* Is the background filler of icon button in its clicked up state */
    UI_filled_area *clicked_down_filler; /* Is the background filler of icon button in its clicked down state */
    UI_filled_area *focussed_up_filler; /* Is the background filler of icon button in its focussed up state */
    UI_filled_area *focussed_down_filler; /* Is the background filler of icon button in its focussed down state */
    U32 flags; /* Is the flag of icon button */
    PU8 normal_up_icon; /* Is the icon of icon button in its normal up state */
    PU8 normal_down_icon; /* Is the icon of icon button in its normal down state */
    PU8 disabled_up_icon; /* Is the icon of icon button in its disabled up state */
    PU8 disabled_down_icon; /* Is the icon of icon button in its disabled down state */
    PU8 clicked_up_icon; /* Is the icon of icon button in its clicked up state */
    PU8 clicked_down_icon; /* Is the icon of icon button in its clicked down state */
    PU8 focussed_up_icon; /* Is the icon of icon button in its focussed up state */
    PU8 focussed_down_icon; /* Is the icon of icon button in its focussed down state */
    S32 icon_x; /* Is the logical x position of icon */
    S32 icon_y; /* Is the logical y position of icon */
    UI_transparent_color_type icon_transparent_color; /* Is icon's transparent color */
    /* Is the clear background function handler of icon button
      * SEE ALSO
      * You should also know gui_button_clear_background_hdlr as well.
      */
        gui_button_clear_background_hdlr clear_background_fp;
    #ifdef __MMI_TOUCH_SCREEN__
    /* Is icon button's pen state which is supported only in touch projects */
        gui_button_pen_state_struct pen_state;
    #endif 
    } icon_button;

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_icon_button_current_theme
 * DESCRIPTION
 *  Applies the current system theme to an icon button object.
 * PARAMETERS
 *  b        : [IN]  Is the icon button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_set_icon_button_current_theme(icon_button *b);

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_icon_button_theme
 * DESCRIPTION
 *  Applies the given theme to an icon button object.
 * PARAMETERS
 *  b        : [IN]  Is the icon button object
 *  t        : [IN]  Is the given theme
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_set_icon_button_BG_theme as well.
 *****************************************************************************/
    extern void gui_set_icon_button_theme(icon_button *b, UI_icon_button_theme *t);

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_icon_button_BG_theme
 * DESCRIPTION
 *  Applies the given theme to an icon button object.
 * REMARKS
 *  The API will only set background fillers of given theme to an icon button object.
 * PARAMETERS
 *  b        : [IN]  Is the icon button object
 *  t        : [IN]  Is icon button's background theme
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_set_icon_button_theme as well.
 *****************************************************************************/
    extern void gui_set_icon_button_BG_theme(icon_button *b, UI_button_theme *t);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_create_icon_button
 * DESCRIPTION
 *  Create an icon button object.
 * REMARKS
 *  Memory must be allocated to the icon button object before call this API.
 * PARAMETERS
 *  b                : [IN]  Is the icon button object
 *  x                : [IN]  Is the x position of icon button
 *  y                : [IN]  Is the y position of icon button
 *  width            : [IN]  Is the width of icon button
 *  height           : [IN]  Is the height of icon button
 *  button_icon      : [IN]  Is the icon of icon button
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_create_icon_button(
             icon_button *b,
             S32 x,
             S32 y,
             S32 width,
             S32 height,
             PU8 button_icon);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_resize_icon_button
 * DESCRIPTION
 *  Resize icon button object to a new dimension.
 * PARAMETERS
 *  b            : [IN]  Is the icon button object
 *  width        : [IN]  Is the new width of icon button
 *  height       : [IN]  Is the new height of icon button
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_resize_icon_button(icon_button *b, S32 width, S32 height);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_move_icon_button
 * DESCRIPTION
 *  Move icon button object to a new position.
 * PARAMETERS
 *  b            : [IN]  Is the icon button object
 *  x            : [IN]  Is the new x position of icon button
 *  y            : [IN]  Is the new y position of icon button
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_move_icon_button(icon_button *b, S32 x, S32 y);

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icon_button_set_icon_positon
 * DESCRIPTION
 *  Set icon's logical position to icon button object.
 * PARAMETERS
 *  b        : [IN]  Is the icon button object
 *  x        : [IN]  Is the logical x position of icon
 *  y        : [IN]  Is the logical y position of icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_icon_button_set_icon_positon(icon_button *b, S32 x, S32 y);

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icon_button_set_icon
 * DESCRIPTION
 *  Set the icon to icon button object.
 * PARAMETERS
 *  b                        : [IN]  Is the icon button object
 *  button_icon              : [IN]  Is the icon of icon button
 *  icon_transparent_color   : [IN]  Is the transparent color of icon button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_icon_button_set_icon(
                    icon_button *b,
                    PU8 button_icon,
                    UI_transparent_color_type icon_transparent_color);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_show_icon_button
 * DESCRIPTION
 *  Draw an icon button object to main LCD. This API will only
 *  draw the background and icon of button. It will not blt icon button
 *  to main LCD.
 * PARAMETERS
 *  b        : [IN]  is the icon button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_show_icon_button(icon_button *b);

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_buttons_gui_layer_touch>
 * FUNCTION
 *  gui_icon_button_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of an icon button object and display the corresponding effect.
 * PARAMETERS
 *  b                : [IN] Is the icon button object
 *  pen_event        : [IN] Is the pen event
 *  x                : [IN] Is the x position of pen
 *  y                : [IN] Is the y position of pen
 *  button_event     : [IN/OUT] Is the pointer of parameter to get icon button's pen event
 * RETURNS
 *  MMI_BOOL
 * Return Values
 *  MMI_TRUE: Icon button will handle the given pen event.
 *  MMI_FALSE: Icon button will not handle the given pen event.
 * REMARKS
 *  This API is supported only in touch projects.
 *****************************************************************************/
    extern MMI_BOOL gui_icon_button_translate_pen_event(
                    icon_button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);

/* DOM-NOT_FOR_SDK-BEGIN */
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_buttons_variables>
 *  UI icon text button structure             */
    extern UI_icontext_button_theme *current_icontext_button_theme;
/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_struct>
 * struct of icontext button component.
 */
    typedef struct _icontext_button
    {
    S32 x; /* Is the x position of icontext button */
    S32 y; /* Is the y position of icontext button */
    S32 width; /* Is the width of icontext button */
    S32 height; /* Is the height of icontext button */
    UI_filled_area *normal_up_filler; /* Is the background filler of icontext button in its notmal up state */
    UI_filled_area *normal_down_filler; /* Is the background filler of icontext button in its notmal down state */
    UI_filled_area *disabled_up_filler; /* Is the background filler of icontext button in its disabled up state */
    UI_filled_area *disabled_down_filler; /* Is the background filler of icontext button in its disabled down state */
    UI_filled_area *clicked_up_filler; /* Is the background filler of icontext button in its clicked up state */
    UI_filled_area *clicked_down_filler; /* Is the background filler of icontext button in its clicked down state */
    UI_filled_area *focussed_up_filler; /* Is the background filler of icontext button in its focussed up state */
    UI_filled_area *focussed_down_filler; /* Is the background filler of icontext button in its focussed down state */
    U32 flags; /* Is the flag of icontext button */
    PU8 normal_up_icon; /* Is the icon of icontext button in its normal up state */
    PU8 normal_down_icon; /* Is the icon of icontext button in its normal down state */
    PU8 disabled_up_icon; /* Is the icon of icontext button in its disabled up state */
    PU8 disabled_down_icon; /* Is the icon of icontext button in its disabled down state */
    PU8 clicked_up_icon; /* Is the icon of icontext button in its clicked up state */
    PU8 clicked_down_icon; /* Is the icon of icontext button in its clicked down state */
    PU8 focussed_up_icon; /* Is the icon of icontext button in its focussed up state */
    PU8 focussed_down_icon; /* Is the icon of icontext button in its focussed down state */
    S32 icon_x; /* Is the logical x position of icon */
    S32 icon_y; /* Is the logical y position of icon */
    /* Is the horizontal gap between icontext button's content and its border in X direction */
    UI_transparent_color_type icon_transparent_color; /* Is icon's transparent color */
	   /* Is the clear background function handler of icontext button
      * SEE ALSO
      * You should also know gui_button_clear_background_hdlr as well.
      */
        gui_button_clear_background_hdlr clear_background_fp;
	#ifdef __MMI_TOUCH_SCREEN__
    /* Is icon button's pen state which is supported only in touch projects */
        gui_button_pen_state_struct pen_state;
    #endif    
	
    S32 text_x; /* Is the logical x position of text */
    S32 text_y; /* Is the logical y position of text */

    S32 text_height; /* Is the text's height of icontext button */
    S32 text_width; /* Is the text's width of icontext button */
    UI_string_type text; /* Is the text's content of icontext button */
    color normal_up_text_color; /* Is the text's color of icontext button in its notmal up state */
    color normal_down_text_color; /* Is the text's color of icontext button in its notmal down state */
    color disabled_up_text_color; /* Is the text's color of icontext button in its disabled up state */
    color disabled_down_text_color; /* Is the text's color of icontext button in its disabled down state */
    color focussed_up_text_color; /* Is the text's color of icontext button in its focussed up state */
    color focussed_down_text_color; /* Is the text's color of icontext button in its focussed down state */
    color clicked_up_text_color; /* Is the text's color of icontext button in its clicked up state */
    color clicked_down_text_color; /* Is the text's color of icontext button in its clicked down state */
    color normal_up_text_border_color; /* Is the text border's color of icontext button in its notmal up state */
    color normal_down_text_border_color; /* Is the text border's color of icontext button in its notmal down state */
    color disabled_up_text_border_color; /* Is the text border's color of icontext button in its disabled up state */
    color disabled_down_text_border_color; /* Is the text border's color of icontext button in its disabled down state */
    color focussed_up_text_border_color; /* Is the text border's color of icontext button in its focussed up state */
    color focussed_down_text_border_color; /* Is the text border's color of icontext button in its focussed down state */
    color clicked_up_text_border_color; /* Is the text border's color of icontext button in its clicked up state */
    color clicked_down_text_border_color; /* Is the text border's color of icontext button in its clicked down state */

    UI_font_type text_font; /* Is the text's font size of icontext button */
  
    S32 touch_area_x1; /* Is the x position of touch area's left-top corner */
    S32 touch_area_y1; /* Is the y position of touch area's left-top corner */
    S32 touch_area_x2; /* Is the x position of touch area's right-bottom corner */
    S32 touch_area_y2; /* Is the y position of touch area's right-bottom corner */
    S32 display_area_x1; /* Is the x position of display area's left-top corner */
    S32 display_area_y1; /* Is the y position of display area's left-top corner */
    S32 display_area_x2; /* Is the x position of display area's right-bottom corner */
    S32 display_area_y2; /* Is the y position of display area's right-bottom corner */
    S32 horizontal_gap;

    #ifdef __MMI_TOUCH_SCREEN__
    /* Is a function handler which displays icontext button in its pen down state */
        gui_button_draw_button_hdlr draw_down_fp;
    /* Is a function handler which displays icontext button in its pen up state */
        gui_button_draw_button_hdlr draw_up_fp;
    #endif /* __MMI_TOUCH_SCREEN__ */

    } icontext_button;

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_text_button_current_theme
 * DESCRIPTION
 *  Applies the current system theme to an icontext button object.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_set_icontext_button_current_theme(icontext_button *b);

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_icontext_button_theme
 * DESCRIPTION
 *  Applies the given theme to an icontext button object.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 *  t        : [IN]  Is the given theme
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_set_icontext_button_BG_theme as well.
 *****************************************************************************/
    extern void gui_set_icontext_button_theme(icontext_button *b, UI_icontext_button_theme *t);

/*****************************************************************************
 * <group dom_buttons_gui_layer_theme>
 * FUNCTION
 *  gui_set_icontext_button_BG_theme
 * DESCRIPTION
 *  Applies the given theme to an icontext button object.
 * REMARKS
 *  The API will only set background fillers of given theme to an icon button object.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 *  t        : [IN]  Is icontext button's background theme
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_set_icontext_button_theme as well.
 *****************************************************************************/
    extern void gui_set_icontext_button_BG_theme(icontext_button *b, UI_button_theme *t);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_create_icontext_button
 * DESCRIPTION
 *  Create an icontext button object.
 * REMARKS
 *  Memory must be allocated to the icontext button object before call this API.
 * PARAMETERS
 *  b               : [IN]  Is the icontext button object
 *  x               : [IN]  Is the x position of icontext button
 *  y               : [IN]  Is the y position of icontext button
 *  width           : [IN]  Is the width of icontext button
 *  height          : [IN]  Is the height of icontext button
 *  text            : [IN]  Is the text of icontext button
 *  button_icon     : [IN]  Is the icon of icontext button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_create_icontext_button(
                    icontext_button *b,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    UI_string_type text,
                    PU8 button_icon);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_resize_icontext_button
 * DESCRIPTION
 *  Resize icontext button object to a new dimension.
 * PARAMETERS
 *  b           : [IN]  Is the icontext button object
 *  width       : [IN]  Is the new width of icontext button
 *  height      : [IN]  Is the new height of icontext button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_resize_icontext_button(icontext_button *b, S32 width, S32 height);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_move_icontext_button
 * DESCRIPTION
 *  Move icontext button object to a new position.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 *  x        : [IN]  Is the new x position of icontext button
 *  y        : [IN]  Is the new y position of icontext button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_move_icontext_button(icontext_button *b, S32 x, S32 y);

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icontext_button_set_icon_positon
 * DESCRIPTION
 *  Set icon's logical position to icontext button object.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 *  x        : [IN]  Is the logical x position of icon
 *  y        : [IN]  Is the logical y position of icon
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_icontext_button_set_icon_positon(icontext_button *b, S32 x, S32 y);

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icontext_button_set_text_position
 * DESCRIPTION
 *  Set text's logical position to icontext button object.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 *  x        : [IN]  Is the logical x position of text
 *  y        : [IN]  Is the logical y position of text
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_icontext_button_set_text_position(icontext_button *b, S32 x, S32 y);

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icontext_button_set_icon
 * DESCRIPTION
 *  Set the icon to icontext button object.
 * PARAMETERS
 *  b                            : [IN]  Is the icontext button object
 *  button_icon                  : [IN]  Is the icon of icontext button
 *  icon_transparent_color       : [IN]  Is the transparent color of icontext button
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_icontext_button_set_icon(
                    icontext_button *b,
                    PU8 button_icon,
                    UI_transparent_color_type icon_transparent_color);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_show_icontext_button
 * DESCRIPTION
 *  Draw an icontext button object to main LCD. This API will only
 *  draw the background and content of button. It will not blt icontext button
 *  to main LCD.
 * PARAMETERS
 *  b        : [IN]  Is the icontext button object
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_show_icontext_button(icontext_button *b);

/***************************************************************************** 
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icontext_set_horizontal_gap
 * DESCRIPTION
 *  Set the horizontal gap to icontext button object.
 * PARAMETERS
 *  b                : [IN]  Is the icontext button object
 *  horizontal_gap   : [IN]  Is the horizontal gap value in pixel
 * RETURNS
 *  void
 *****************************************************************************/
    extern void gui_icontext_set_horizontal_gap(icontext_button *b, S32 horizontal_gap);

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_buttons_gui_layer_touch>
 * FUNCTION
 *  gui_icontext_button_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of an icontext button object and display the corresponding effect.
 * PARAMETERS
 *  b                : [IN]  Is the icontext button object
 *  pen_event        : [IN]  Is the pen event
 *  x                : [IN]  Is the x position of pen
 *  y                : [IN]  Is the y position of pen
 *  button_event     : [IN/OUT] Is the pointer of parameter to get icontext button's pen event
 * RETURNS
 *  MMI_BOOL
 * Return Values
 *  MMI_TRUE: Icontext button will handle the given pen event.
 *  MMI_FALSE: Icontext button will not handle the given pen event.
 * REMARKS
 *  This API is supported only in touch projects.
 *****************************************************************************/
    extern MMI_BOOL gui_icontext_button_translate_pen_event(
                    icontext_button *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icontext_button_overwirte_pen_response_area
 * DESCRIPTION
 *  Overwrite the response area of icontext button.
 * PARAMETERS
 *  b           : [IN]  Is the icontext button object
 *  x1          : [IN]  Is the new x position of pen response area's left-top corner
 *  y1          : [IN]  Is the new y position of pen response area's left-top corner
 *  x2          : [IN]  Is the new x position of pen response area's right-bottom corner
 *  y2          : [IN]  Is the new y position of pen response area's right-bottom corner
 * RETURNS
 *  
 *****************************************************************************/
extern void gui_icontext_button_overwirte_pen_response_area(
             icontext_button *b,
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_icontext_button_show_up_by_pen
 * DESCRIPTION
 *  Show icontext button's up state after pen release.
 * PARAMETERS
 *  button_object       : [IN]  Is the icontext button object
 * RETURNS
 *  MMI_BOOL
 * REMARKS
 *  This API is supported only in touch projects.
 *****************************************************************************/
    extern MMI_BOOL gui_icontext_button_show_up_by_pen(void *button_object);

/*****************************************************************************
 * <group dom_buttons_gui_layer_basic>
 * FUNCTION
 *  gui_icontext_button_show_down_by_pen
 * DESCRIPTION
 *  Show icontext button's down state after pen release.
 * PARAMETERS
 *  button_object       : [IN]  Is the icontext button object
 * RETURNS
 *  MMI_BOOL
 * REMARKS
 *  This API is supported only in touch projects.
 *****************************************************************************/
    extern MMI_BOOL gui_icontext_button_show_down_by_pen(void *button_object);

/* DOM-NOT_FOR_SDK-BEGIN */
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_buttons_gui_layer_property_setting>
 * FUNCTION
 *  gui_icontext_button_get_display_area
 * DESCRIPTION
 *  Get content's display area of icontext button.
 * PARAMETERS
 *  b                : [IN]  Is the icontext button object
 *  display_x1       : [IN]  Is the x position of display area's left-top corner
 *  display_y1       : [IN]  Is the y position of display area's left-top corner
 *  display_x2       : [IN]  Is the x position of display area's right-bottom corner
 *  display_y2       : [IN]  Is the y position of display area's right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_icontext_button_get_display_area(
             icontext_button *b,
             S32 *display_x1,
             S32 *display_y1,
             S32 *display_x2,
             S32 *display_y2);

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __cplusplus
}
#endif 
/* DOM-NOT_FOR_SDK-END */

#endif /* __GUI_BUTTONS_H__ */ 


