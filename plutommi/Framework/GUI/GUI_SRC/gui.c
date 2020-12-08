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
 *   gui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GUI primitives
 *
 *   This file includes
 *   o Wrapper function pointers
 *   o Special filler effects
 *   o HLS colorspace
 *   o Truncated text display
 *   o Gui cleanup callback
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

#include "MMI_features.h"

#include "kal_general_types.h"

#include "gui.h"

#include "gdi_include.h"
#include "lcd_sw_rnd.h"

#include "mmi_frm_gprot.h"

#include "wgui_categories_res.h"
#include "math.h"       /* Floating arithmetics */


#include "BIDIDef.h"

#if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)
#include "wgui.h"
#endif
#include "gui_effect_oem.h"

#ifdef __MMI_VIRTUAL_KEYBOARD__
#include "wgui_virtual_keyboard.h"
#endif

#include "MMI_features_type.h"
#include "gui_virtual_keyboard.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "wchar.h"
#include "CustThemesRes.h"
#include "gui_config.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "string.h"
#include "kal_general_types.h"
#include "gui_switch.h"
#include "PixcomFontEngine.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"


#ifdef __MMI_VIRTUAL_KEYBOARD__
#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
extern virtual_keyboard MMI_virtual_keyboard;
#endif

#endif /* __MMI_VIRTUAL_KEYBOARD__ */



extern void UI_set_current_text_color(color c);

#define  BUF_PIXEL_OFFSET(buff_ptr,x , y, width)  ((U32*)(buff_ptr + (((y) * width + (x)) * (gdi_act_layer->bits_per_pixel >> 3))))


/* UI globals */
S32 UI_clip_x1;             /* Left edge of UI clip rectangle */
S32 UI_clip_y1;             /* Top edge of UI clip rectangle */
S32 UI_clip_x2;             /* Right edge of UI clip rectangle */
S32 UI_clip_y2;             /* Bottom edge of UI clip rectangle */
S32 UI_old_clip_x1;         /* Saved UI clipping values */
S32 UI_old_clip_y1;
S32 UI_old_clip_x2;
S32 UI_old_clip_y2;
S32 UI_text_x;              /* Current text cursor position */
S32 UI_text_y;
S32 UI_text_height;         /* Current line height to use */
S32 UI_pointer_x;           /* Current pointer position */
S32 UI_pointer_y;

/*
 * Base functions required by the UI system:
 * All UI components will use these functions and will not directly use any other 
 * OS or hardware related functions.                        
 * All these calls are function pointers and need to be initialized with the
 * proper driver (Ex: wingui.c for Win32 platforms)
 */

/*----------------------------------------------------------------------------
Function Pointer: gui_putpixel
Description:      Plots a pixel at (x,y) with color c
Input Parameters: (x,y) co-ordinates in the device screen
               c     color in which the pixel is plotted
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_putpixel) (S32 x, S32 y, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_draw_vertical_line
Description:      Draws a vertical line from (x,y1) to (x,y2) with color c
Input Parameters: y1    starting y co-ordinate
               y2    ending y co-ordinate
               x     x co-ordinate
               c     color in which the line is drawn
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide line
               Currently doesn't support (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_draw_vertical_line) (S32 y1, S32 y2, S32 x, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_draw_horizontal_line
Description:      Draws a horizontal line from (x1,y) to (x2,y) with color c
Input Parameters: x1    starting x co-ordinate
               x2    ending x co-ordinate
               y     y co-ordinate
               c     color in which the line is drawn
               type_line NORMAL/DOTTED/DASHED
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide line
               Currently doesn't support (x2<x1)
----------------------------------------------------------------------------*/

void (*gui_draw_horizontal_line) (S32 x1, S32 x2, S32 y, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_line
Description:      Draws a line from (x1,y1) to (x2,y2) with color c
Input Parameters: (x1,y1)  end point 1
               (x2,y2)  end point 2
               c     color
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide line
----------------------------------------------------------------------------*/

void (*gui_line) (S32 x1, S32 y1, S32 x2, S32 y2, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_wline
Description:      Draws a line from (x1,y1) to (x2,y2) with color c
Input Parameters: (x1,y1)  end point 1
               (x2,y2)  end point 2
               c     color
               w     is the width in pixels
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide line
----------------------------------------------------------------------------*/

void (*gui_wline) (S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 w) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_draw_rectangle_type
Description:      Draws a rectangle (x1,y1) to (x2,y2) with color c
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c     color
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide, outlined rectangle
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_draw_rectangle_type) (S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 type_line) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_draw_vertical_line_type
Description:      Draws a vertical line from (x,y1) to (x,y2) with color c
Input Parameters: y1    starting y co-ordinate
               y2    ending y co-ordinate
               x     x co-ordinate
               c     color in which the line is drawn
               type_line NORMAL/DOTTED/DASHED
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide line
               Currently doesn't support (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_draw_vert_line_type) (S32 y1, S32 y2, S32 x, color c, S32 type_line) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_draw_horizontal_line_type 
Description:      Draws a horizontal line from (x1,y) to (x2,y) with color c
Input Parameters: x1    starting x co-ordinate
               x2    ending x co-ordinate
               y     y co-ordinate
               c     color in which the line is drawn
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide line
               Currently doesn't support (x2<x1)
----------------------------------------------------------------------------*/

void (*gui_draw_hori_line_type) (S32 x1, S32 x2, S32 y, color c, S32 type_line) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_draw_rectangle
Description:      Draws a rectangle (x1,y1) to (x2,y2) with color c with t
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c     color
               type_line NORMAL/DOTTED/DASHED
Output Parameters:   none
Returns:       void
Remarks:       Single pixel wide, outlined rectangle
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_draw_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_fill_rectangle
Description:      Draws a filled rectangle (x1,y1) to (x2,y2) with color c
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c     color
Output Parameters:   none
Returns:       void
Remarks:       Filled rectangle without border
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_cross_hatch_fill_rectangle
Description:      Draws a cross hatch filled rectangle (x1,y1) to (x2,y2) with color c
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c     color
Output Parameters:   none
Returns:       void
Remarks:       Filled rectangle without border
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_cross_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_hatch_fill_rectangle
Description:      Draws a horizontal hatch filled rectangle (x1,y1) to (x2,y2) with color c
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c     color
Output Parameters:   none
Returns:       void
Remarks:       Filled rectangle without border
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_alternate_cross_hatch_fill_rectangle
Description:      Draws a cross hatch filled rectangle (x1,y1) to (x2,y2) with alternating colors c1 and c2
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c1, c2   colors
Output Parameters:   none
Returns:       void
Remarks:       Filled rectangle without border
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_alternate_cross_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_alternate_hatch_fill_rectangle
Description:      Draws a horizontal hatch filled rectangle (x1,y1) to (x2,y2) with alternating colors c1 and c2
Input Parameters: (x1,y1)  left-top corner of the rectangle
               (x2,y2)  right-bottom corner of the rectangle
               c1, c2   colors
Output Parameters:   none
Returns:       void
Remarks:       Filled rectangle without border
               Currently doesn't support (x2<x1) or (y2<y1)
----------------------------------------------------------------------------*/

void (*gui_alternate_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_text_clip
Description:      Sets the text clipping boundary
Input Parameters: (x1,y1)  left-top corner of the text clipping rectangle
               (x2,y2)  right-bottom corner of the text clipping rectangle
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_set_text_clip) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_text_clip
Description:      Gets the text clipping boundary
Input Parameters: none
Output Parameters:   (x1,y1)  left-top corner of the text clipping rectangle
               (x2,y2)  right-bottom corner of the text clipping rectangle
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_get_text_clip) (S32 *x1, S32 *y1, S32 *x2, S32 *y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_text_clip_preset
Description:      Sets the text clipping boundary making sure its not larger
               than the previously set boundary.
Input Parameters: (x1,y1)  left-top corner of the text clipping rectangle
               (x2,y2)  right-bottom corner of the text clipping rectangle
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_set_text_clip_preset) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_clip
Description:      Sets the graphics clipping boundary
Input Parameters: (x1,y1)  left-top corner of the clipping rectangle
               (x2,y2)  right-bottom corner of the clipping rectangle
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_clip_with_bounding_box
Description:      Sets the graphics clipping boundary with boundary 
Input Parameters: (x1,y1)  left-top corner of the clipping rectangle
               (x2,y2)     right-bottom corner of the clipping rectangle
               (bx1, by1)  left-top corner of the bounding rectangle
               (bx2, by2)  right-bottom corner of the bounding rectangle
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/
extern void (*gui_set_clip_with_bounding_box) (S32 x1, S32 y1, S32 x2, S32 y2, S32 bx1, S32 by1, S32 bx2, S32 by2) =
    NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_clip
Description:      Gets the graphics clipping boundary
Input Parameters: none
Output Parameters:   (x1,y1)  left-top corner of the clipping rectangle
               (x2,y2)  right-bottom corner of the clipping rectangle
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_get_clip) (S32 *x1, S32 *y1, S32 *x2, S32 *y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_clip_preset
Description:      Sets the graphics clipping boundary making sure its not larger
               than the previously set boundary.
Input Parameters: (x1,y1)  left-top corner of the clipping rectangle
               (x2,y2)  right-bottom corner of the clipping rectangle
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_set_clip_preset) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_reset_clip
Description:      Resets the graphics clipping to the default values
Input Parameters: none
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_reset_clip) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_reset_text_clip
Description:      Resets the text clipping to the default values
Input Parameters: none
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_reset_text_clip) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_move_text_cursor
Description:      Positions the text cursor at (x,y)
Input Parameters: (x,y) pixel from which the text drawing begins.
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_move_text_cursor) (S32 x, S32 y) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_line_height
Description:      Sets the line height to use
Input Parameters: height is the line height to use
Output Parameters:   none
Returns:       void
Remarks:       In the current implemenation, line height is reset after 
               every call to gui_move_text_cursor. So, this function
               must be called after gui_move_text_cursor
----------------------------------------------------------------------------*/

void (*gui_set_line_height) (S32 height) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_text_color
Description:      Sets the color of text.
Input Parameters: c  is the color using which the text is drawn
Output Parameters:   none
Returns:       void
Remarks:       Affects all the text that is drawn after calling this function.
               Text that was drawn before calling this function will not be affected.
----------------------------------------------------------------------------*/

void (*gui_set_text_color) (color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_text_border_color
Description:      Sets the border color of text.
Input Parameters: c  is the color using which the text border is drawn
Output Parameters:   none
Returns:       void
Remarks:       Affects all the text that is drawn after calling this function.
               Text that was drawn before calling this function will not be affected.
----------------------------------------------------------------------------*/

void (*gui_set_text_border_color) (color c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_text_color
Description:      Gets the color of text.
Input Parameters: none
Output Parameters:   none
Returns:       text color
----------------------------------------------------------------------------*/

color (*gui_get_text_color) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_text_border_color
Description:      Gets the border color of text.
Input Parameters: none
Output Parameters:   none
Returns:       text border color
----------------------------------------------------------------------------*/

color (*gui_get_text_border_color) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_printf
Description:      Platform's printf() function
Input Parameters: Same as printf()
Output Parameters:   none
Returns:       Same as printf()
Remarks:       The text is displayed at the current text cursor position using
               the current font and text color, See gui_set_text_color(),
               gui_set_font(), gui_move_text_cursor()
----------------------------------------------------------------------------*/

S32(*gui_printf) (const S8 *format,...) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_sprintf
Description:      Platform's sprintf() function
Input Parameters: Same as sprintf()
Output Parameters:   none
Returns:       Same as sprintf()
----------------------------------------------------------------------------*/

S32(*gui_sprintf) (UI_string_type _text, const S8 *format,...) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_text
Description:      Displays a string.
Input Parameters: _text is the text that is displayed
Output Parameters:   none
Returns:       void
Remarks:       The text is displayed at the current text cursor position using
               the current font and text color, See gui_set_text_color(),
               gui_set_font(), gui_move_text_cursor()
----------------------------------------------------------------------------*/

void (*gui_print_text) (UI_string_type _text) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_character
Description:      Displays a character
Input Parameters: _c    is the character that is displayed
Output Parameters:   none
Returns:       void
Remarks:       The character is displayed at the current text cursor position using
               the current font and text color, See gui_set_text_color(),
               gui_set_font(), gui_move_text_cursor()
----------------------------------------------------------------------------*/

void (*gui_print_character) (UI_character_type _c) = NULL;

void (*gui_print_bordered_character) (UI_character_type _c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_character_at_xy
Description:      Displays a character
Input Parameters: _c    is the character that is displayed
Output Parameters:   none
Returns:       void
Remarks:       The character is displayed at the position assigned by caller using
               the current font and text color, See gui_set_text_color(),
               gui_set_font()
----------------------------------------------------------------------------*/

void (*gui_print_character_at_xy) (UI_character_type c, S32 x, S32 y) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_stacked_character
Description:      Displays a stacked character
Input Parameters: _curCh is the character that is displayed, _pre2Ch is the previous two char, and _preCh is the previous char
Output Parameters:   none
Returns:       void
Remarks:       The displayed position is decided by previous two characters.
               This function is to print the stacked character. it means that one word may
               composed by several characters and be stacked up.
----------------------------------------------------------------------------*/

void (*gui_print_stacked_character) (UI_character_type _curCh, UI_character_type _pre2Ch, UI_character_type _preCh) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_bordered_stacked_character
Description:      Displays a stacked character
Input Parameters: _curCh is the character that is displayed, _pre2Ch is the previous two char, and _preCh is the previous char
Output Parameters:   none
Returns:       void
Remarks:       The displayed position is decided by previous two characters.
               This function is to print the stacked character. it means that one word may
               composed by several characters and be stacked up.
----------------------------------------------------------------------------*/

void (*gui_print_bordered_stacked_character) (UI_character_type _curCh, UI_character_type _pre2Ch,
                                              UI_character_type _preCh) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_bordered_text
Description:      Displays a string.
Input Parameters: _text is the text that is displayed
Output Parameters:   none
Returns:       void
Remarks:       The text is displayed at the current text cursor position using
               the current font and the current color and border color, See also
               gui_set_font(), gui_move_text_cursor(),
               gui_set_text_color(),gui_set_text_border_color()
----------------------------------------------------------------------------*/

void (*gui_print_bordered_text) (UI_string_type _text) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_text_n
Description:      Displays a string with length n.
Input Parameters: _text is the text that is displayed,_n is the length to display
Output Parameters:   none
Returns:       void
Remarks:       The text is displayed at the current text cursor position using
               the current font and text color, See gui_set_text_color(),
               gui_set_font(), gui_move_text_cursor()
----------------------------------------------------------------------------*/

void (*gui_print_text_n) (UI_string_type _text, int _n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_print_bordered_text_n
Description:      Displays a string with length n.
Input Parameters: _text is the text that is displayed,_n id the length to dusplay
Output Parameters:   none
Returns:       void
Remarks:       The text is displayed at the current text cursor position using
               the current font and the current color and border color, See also
               gui_set_font(), gui_move_text_cursor(),
               gui_set_text_color(),gui_set_text_border_color()
----------------------------------------------------------------------------*/

void (*gui_print_bordered_text_n) (UI_string_type _text, int _n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_push_text_clip
Description:      Saves the text clipping boundary
Input Parameters: none
Output Parameters:   none
Returns:       void
Remarks:       Currently not a stack type implementation
----------------------------------------------------------------------------*/

void (*gui_push_text_clip) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_pop_text_clip
Description:      Retrieves the text clipping boundary
Input Parameters: none
Output Parameters:   none
Returns:       void
Remarks:       Currently not a stack type implementation
----------------------------------------------------------------------------*/

void (*gui_pop_text_clip) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_push_clip
Description:      Saves the graphics clipping boundary
Input Parameters: none
Output Parameters:   none
Returns:       void
Remarks:       Currently not a stack type implementation
----------------------------------------------------------------------------*/

void (*gui_push_clip) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_push_and_set_clip
Description:      Saves the graphics clipping boundary and set clip of active layer
Input Parameters: none
Output Parameters:   none
Returns:       void
Remarks:       Currently not a stack type implementation
----------------------------------------------------------------------------*/

void (*gui_push_and_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_pop_clip
Description:      Retrieves the graphics clipping boundary
Input Parameters: none
Output Parameters:   none
Returns:       void
Remarks:       Currently not a stack type implementation
----------------------------------------------------------------------------*/

void (*gui_pop_clip) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_malloc
Description:      Same as malloc
Input Parameters: Same as malloc
Output Parameters:   none
Returns:       Same as malloc
Remarks:       All UI functions use this to allocate memory.
----------------------------------------------------------------------------*/

void *(*gui_malloc) (size_t size) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_free
Description:      Same as free
Input Parameters: Same as free
Output Parameters:   none
Returns:       Same as free
Remarks:       All UI functions use this to free memory.
----------------------------------------------------------------------------*/

void (*gui_free) (void *ptr) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_character_width
Description:      Returns the width of a given character in pixels
Input Parameters: c  is the character whose width is to be measured
Output Parameters:   none
Returns:       width of the character in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_character_width) (UI_character_type c) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_character_height
Description:      Returns the height of characters in the current font
Input Parameters: none
Output Parameters:   none
Returns:       height of the character in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_character_height) (void) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_measure_character
Description:      Returns the width and height of a given character
Input Parameters: c     is the character to be measured
Output Parameters:   width pointer to the width of the character in pixels
               height   pointer to the height of the character in pixels
Returns:       void
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

void (*gui_measure_character) (UI_character_type c, S32 *width, S32 *height) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_string_width
Description:      Returns the width of a string in pixels
Input Parameters: text  pointer to the string
Output Parameters:   none
Returns:       width of the string in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_string_width) (UI_string_type text) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_string_height
Description:      Returns the height of a string in pixels
Input Parameters: text  pointer to the string
Output Parameters:   none
Returns:       height of the string in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_string_height) (UI_string_type text) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_measure_string
Description:      Returns the width and height of a string in pixels
Input Parameters: text  pointer to the string
Output Parameters:   width pointer to width of string in pixels
               height   pointer to height of string in pixels
Returns:       void
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

void (*gui_measure_string) (UI_string_type text, S32 *width, S32 *height) = NULL;
void (*gui_measure_string_n) (UI_string_type text, S32 n, S32 *width, S32 *height) = NULL;
void (*gui_measure_string_w) (UI_string_type text, S32 w, S32 *width, S32 *height) = NULL;
void (*gui_measure_string_wn) (UI_string_type text, S32 w, S32 n, S32 *width, S32 *height) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_string_width_n
Description:      Returns the width of first n characters in a string
Input Parameters: text  pointer to the string
               n     number of characters to measure
Output Parameters:   none
Returns:       width of the string in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_string_width_n) (UI_string_type text, S32 n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_string_width_w
Description:      Returns the width of a string
Input Parameters: text  pointer to the string
               w     spacing between characters
Output Parameters:   none
Returns:       width of the string in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_string_width_w) (UI_string_type text, S32 w) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_get_string_width_wn
Description:      Returns the width of first n characters in a string
Input Parameters: text  pointer to the string
               w     spacing between characters
               n     number of characters to measure
Output Parameters:   none
Returns:       width of the string in pixels
Remarks:       This works with reference to the current font.
               See gui_set_font()
----------------------------------------------------------------------------*/

S32(*gui_get_string_width_wn) (UI_string_type text, S32 w, S32 n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_strlen
Description:      Returns the length of a string
Input Parameters: text  pointer to the string
Output Parameters:   none
Returns:       number of characters in the string (Not including the terminator)
Remarks:       Currently an ASCIIZ implementation. Will later support Unicode.
----------------------------------------------------------------------------*/

S32(*gui_strlen) (UI_string_type text) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_strcpy
Description:      Copies text2 contents into text1
Input Parameters: text2 pointer to the source string
Output Parameters:   text1 pointer to the destination string
Returns:       pointer to the destination string
Remarks:       Currently an ASCIIZ implementation. Will later support Unicode.
----------------------------------------------------------------------------*/

UI_string_type(*gui_strcpy) (UI_string_type text1, UI_string_type text2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_strncpy
Description:      Copies text2 contents into text1 upto n given characters
Input Parameters: text2 pointer to the source string
               n     number of characters to copy
Output Parameters:   text1 pointer to the destination string
Returns:       pointer to the destination string
Remarks:       Currently an ASCIIZ implementation. Will later support Unicode.
----------------------------------------------------------------------------*/

UI_string_type(*gui_strncpy) (UI_string_type text1, UI_string_type text2, S32 n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_strcat
Description:      Copies text2 contents into text1 starting at the end of text1
               (Concatenation of strings)
Input Parameters: text2 pointer to the source string
Output Parameters:   text1 pointer to the destination string
Returns:       pointer to the destination string
Remarks:       Currently an ASCIIZ implementation. Will later support Unicode.
----------------------------------------------------------------------------*/

UI_string_type(*gui_strcat) (UI_string_type text1, UI_string_type text2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_strcmp
Description:      Compares two strings
Input Parameters: text1 pointer to the first string
               text2 pointer to the second string
Output Parameters:   none
Returns:       Same as strmp
Remarks:       Currently an ASCIIZ implementation. Will later support Unicode.
----------------------------------------------------------------------------*/

S32(*gui_strcmp) (UI_string_type text1, UI_string_type text2) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_strncmp
Description:      Compares two strings upto n characters
Input Parameters: text1 pointer to the first string
               text2 pointer to the second string
               n     Number of characters upto which to perform the comparision
Output Parameters:   none
Returns:       Same as strncmp
Remarks:       Currently an ASCIIZ implementation. Will later support Unicode.
----------------------------------------------------------------------------*/

S32(*gui_strncmp) (UI_string_type text1, UI_string_type text2, S32 n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_memcpy
Description:      Similar to memcpy
Input Parameters: s     pointer to source
               n     number of octets to copy
Output Parameters:   d     pointer to destination
Returns:       pointer to the destination string
----------------------------------------------------------------------------*/

void *(*gui_memcpy) (void *d, const void *s, S32 n) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_itoa
Description:      Converts an integer to a string
Input Parameters: value Integer value to be converted
               radix Base system to use (Ex: Decimal, Binary, Hexadecimal --etc).
Output Parameters:   s     Pointer to the string into which this value is written
Returns:       Same as itoa (Pointer to the string)
----------------------------------------------------------------------------*/

WCHAR *(*gui_itoa) (S32 value, WCHAR * s, U32 radix) = NULL;//

/*----------------------------------------------------------------------------
Function Pointer: gui_atoi
Description:      Converts an string to a integer
Input Parameters: s     Pointer to the string to be converted
Output Parameters:   none
Returns:       Same as atoi (An integer)
----------------------------------------------------------------------------*/

S32(*gui_atoi) (UI_string_type s) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_set_font
Description:      Sets the font to be used by text display functions
Input Parameters: f     is the font to be used
Output Parameters:   none
Returns:       void
Remarks:       See UI_font_type (Abstract type)
----------------------------------------------------------------------------*/

void (*gui_set_font) (UI_font_type f) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_show_image
Description:      Displays an image at (x,y)
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is the image to be displayed
Output Parameters:   none
Returns:       void
Remarks:       See PU8 (Abstract type)
----------------------------------------------------------------------------*/

void (*gui_show_image) (S32 x, S32 y, PU8 i) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_show_animated_image
Description:      Displays an animated image at (x,y)
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is the image to be displayed
Output Parameters:   none
Returns:       A handle to the animated image of the type UI_animated_image_handle
Remarks:       See PU8 (Abstract type)
               See UI_animated_image_handle (Abstract type)
----------------------------------------------------------------------------*/

/* UI_animated_image_handle     (*gui_show_animated_image)(S32 x,S32 y,PU8 i)=NULL; */

/*----------------------------------------------------------------------------
Function Pointer: gui_show_transparent_image
Description:      Displays an image at (x,y). Omits the display of color t.
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is the image to be displayed
               t     is the color in the image bitmap to consider as transparent
Output Parameters:   none
Returns:       void
Remarks:       Used for irregular bitmaps (Some pixels in the bitmap rectangle are not drawn)
               See PU8 (Abstract type)
               See UI_transparent_color_type (Abstract type)
----------------------------------------------------------------------------*/

void (*gui_show_transparent_image) (S32 x, S32 y, PU8 i, UI_transparent_color_type t) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_show_transparent_animated_image
Description:      Displays an animated image at (x,y). Omits the display of color t.
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is the image to be displayed
               t     is the color in the image bitmap to consider as transparent
Output Parameters:   none
Returns:       A handle to the animated image of the type UI_animated_image_handle
Remarks:       Used for irregular bitmaps (Some pixels in the bitmap rectangle are not drawn)
               See PU8 (Abstract type)
               See UI_transparent_color_type (Abstract type)
               See UI_animated_image_handle (Abstract type)
               See also gui_register_hide_animation_frame()
----------------------------------------------------------------------------*/

/* UI_animated_image_handle             (*gui_show_transparent_animated_image)(S32 x,S32 y,PU8 i,UI_transparent_color_type t)=NULL; */

/*----------------------------------------------------------------------------
Function Pointer: gui_measure_image
Description:      Gets the width and height of a given image
Input Parameters: i     is the image
Output Parameters:   width is the width of the image in pixels
               height   is the height of the image in pixels
Returns:       void
Remarks:       See PU8 (Abstract type)
----------------------------------------------------------------------------*/

void (*gui_measure_image) (PU8 i, S32 *width, S32 *height) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_image_n_frames
Description:      Gets the number of frames in the given image
Input Parameters: i     is the image
Output Parameters:   none
Returns:       The number of frames in the image
Remarks:       See PU8 (Abstract type)
----------------------------------------------------------------------------*/

S32(*gui_image_n_frames) (PU8 i) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_register_hide_animation_frame
Description:      Registers a function to be called to hide a frame of an animating image
               Normally used for animated transparent images
Input Parameters: i     is a handle to the animated image 
                     (returned from gui_show_animated_image or
                                 gui_show_transparent_animated_image)
               f     function that is used to hide a frame
                     (x1,y1,x2,y2) is the rectangular area that is drawn to hide the animated image
Output Parameters:   none
Returns:       void
Remarks:       Note: This function may not be available in later versions
               See UI_animated_image_handle (Abstract type)
----------------------------------------------------------------------------*/

void (*gui_register_hide_animation_frame) (UI_animated_image_handle i, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2)) =
    NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_hide_animated_image
Description:      Hides an animated image
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is a handle to the animated image 
                     (returned from gui_show_animated_image or
                                 gui_show_transparent_animated_image)
Output Parameters:   none
Returns:       void
Remarks:       See PU8 (Abstract type)
               See UI_animated_image_handle (Abstract type) 
----------------------------------------------------------------------------*/

void (*gui_hide_animated_image) (S32 x, S32 y, UI_animated_image_handle i) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_show_transparent_animated_image_frame
Description:      Displays a single frame of an animated image
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is the image
               t     is the transparent color
               frame_number   is the index (0 based) of the frame to display
Output Parameters:   none
Returns:       void
Remarks:       See PU8 (Abstract type)
               See UI_transparent_color (Abstract type)
----------------------------------------------------------------------------*/

U8(*gui_show_transparent_animated_image_frame) (S32 x, S32 y, PU8 i, UI_transparent_color_type t, S16 frame_number) =
    NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_show_animated_image_frame
Description:      Displays a single frame of an animated image
Input Parameters: (x,y) co-ordinates of the top left corner of the image
               i     is the image
               t     is the transparent color
               frame_number   is the index (0 based) of the frame to display
Output Parameters:   none
Returns:       void
Remarks:       See PU8 (Abstract type)
               See UI_transparent_color (Abstract type)
----------------------------------------------------------------------------*/

U8(*gui_show_animated_image_frame) (S32 x, S32 y, PU8 i, S16 frame_number) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_hide_animations
Description:      Cancels all animations
Input Parameters: none
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_hide_animations) (void) = NULL;


/*----------------------------------------------------------------------------
Function Pointer: gui_start_timer
Description:      One shot timer
Input Parameters: count    is the delay (Implementation dependent: Normally milliseconds)
               callback is the function that is called when the timer expires
Output Parameters:   none
Returns:       void
Remakrs:       NOTE: DO NOT USE UI TIMER IN CRITICAL CASES
               UI timer will be suspended when LCD backlight is turned off.
----------------------------------------------------------------------------*/

void (*gui_start_timer) (S32 count, void (*callback) (void)) = NULL;


/*----------------------------------------------------------------------------
Function Pointer: gui_start_timer_ex
Description:      One shot timer
Input Parameters:   count    is the delay (Implementation dependent: Normally milliseconds)
                    callback is the function that is called when the timer expires
                    arg is the argument passed to the timer callback
Output Parameters:   none
Returns:       void
Remakrs:       NOTE: DO NOT USE UI TIMER IN CRITICAL CASES
               UI timer will be suspended when LCD backlight is turned off.
----------------------------------------------------------------------------*/

void (*gui_start_timer_ex) (S32 count, void (*callback)(void *), void *arg) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_cancel_timer
Description:      Cancels a timer if it has been started for a particular call back function
Input Parameters: callback is the function that is called when the timer expires
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_cancel_timer) (void (*callback) (void)) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_transparent_color
Description:      Returns a transparent color value for given R,G,B values
Input Parameters: r     red component of a color   (0 to 255)
               g     green component of a color (0 to 255)
               b     blue component of a color  (0 to 255)
Output Parameters:   none
Returns:       Transparent color value 
               (Implementation dependent, see UI_transparent_color_type (Abstract type))
----------------------------------------------------------------------------*/

UI_transparent_color_type(*gui_transparent_color) (U8 r, U8 g, U8 b) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_color
Description:      Returns a color value for given R,G,B values
Input Parameters: r     red component of a color   (0 to 255)
               g     green component of a color (0 to 255)
               b     blue component of a color  (0 to 255)
Output Parameters:   none
Returns:       color value. 
               (Implementation dependent, see color (Abstract type))
----------------------------------------------------------------------------*/

color(*gui_color) (U8 r, U8 g, U8 b) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_color32
Description:      Returns a color value for given R,G,B and alpha values
Input Parameters: r     red component of a color   (0 to 255)
               g     green component of a color (0 to 255)
               b     blue component of a color  (0 to 255)
               alpha alpha value (0 to 100 in percentage)
Output Parameters:   none
Returns:       color value. 
               (Implementation dependent, see color (Abstract type))
----------------------------------------------------------------------------*/

color(*gui_color32) (U8 r, U8 g, U8 b, U8 alpha) = NULL;

/*----------------------------------------------------------------------------
Function Pointer: gui_color_RGB
Description:      Returns the R,G,B values for a given color
Input Parameters: c     is the color
Output Parameters:   r     red component of a color   (0 to 255)
               g     green component of a color (0 to 255)
               b     blue component of a color  (0 to 255)
Returns:       void
----------------------------------------------------------------------------*/

void (*gui_color_RGB) (color c, U8 *r, U8 *g, U8 *b) = NULL;

/* Functions added for multiple character set support. Comments will be added later */

UI_character_type(*gui_get_next_character) (UI_string_type *s) = NULL;
UI_character_type(*gui_get_previous_character) (UI_string_type *s) = NULL;

/* Functions to support double buffering. Comments will be added later  */

void (*gui_BLT_double_buffer) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;
void (*gui_lock_double_buffer) (void) = NULL;
void (*gui_unlock_double_buffer) (void) = NULL;

/* 
 * Dummy functions are called by UI elements by default. 
 * Do not remove any of these functions.  
 */


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_function_byte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a       [IN]        Unused parameter
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_function_byte(U8 a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(a);
}


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_function_s32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_function_s32(S32 a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(a);
}


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_function_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_function_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(c);
}

/* Some standard functions                */


/*****************************************************************************
 * FUNCTION
 *  gui_blend_two_color
 * DESCRIPTION
 *  Blend two color together.
 * PARAMETERS
 *  c1          [IN]        Color 1
 *  c2          [IN]        Color 2
 *  weight1     [IN]        Weighting of color 1
 *  weight2     [IN]        Weighting of color 2
 * RETURNS
 *  blended color
 *****************************************************************************/
color gui_blend_two_color(color c1, color c2, S32 weight1, S32 weight2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 weight = weight1 + weight2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.alpha = (U8) ((weight1 * c1.alpha + weight2 * c2.alpha) / weight);
    c.r = (U8) ((weight1 * c1.r + weight2 * c2.r) / weight);
    c.g = (U8) ((weight1 * c1.g + weight2 * c2.g) / weight);
    c.b = (U8) ((weight1 * c1.b + weight2 * c2.b) / weight);
    return c;
}


/*****************************************************************************
 * FUNCTION
 *  gui_linebreak_character
 * DESCRIPTION
 *  Returns true if a given character is a line break character
 * PARAMETERS
 *  c       [IN]        Character to be tested
 * RETURNS
 *  true  if c is a line break character
 *  false if c is not a line break character
 *****************************************************************************/
U8 gui_linebreak_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((UI_character_type) c == '\n')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_endofstring_character
 * DESCRIPTION
 *  Returns true if a given character is an end of string character
 * PARAMETERS
 *  c       [IN]        Character to be tested
 * RETURNS
 *  true  if c is an end of string character
 *  false if c is not an end of string character
 *  See UI_character_type (Abstract type)
 *****************************************************************************/
U8 gui_endofstring_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((UI_character_type) c == '\0')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_initialize_gradient_color
 * DESCRIPTION
 *  Creates a gradient color
 *  
 *  Note: gc must be allocated before calling this function.
 * PARAMETERS
 *  gc      [OUT]       Is the gradient color      (pre-allocated)
 *  c       [IN]        Is an array of colors      (n    elements)
 *  p       [IN]        Is an array of percentages (n-1  elements)
 *  n       [IN]        Is the number of colors
 * RETURNS
 *  void
 *****************************************************************************/
void gui_initialize_gradient_color(gradient_color *gc, color *c, U8 *p, U8 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gc->c = c;
    gc->p = p;
    gc->n = n;
}

static void gui_gradient_fill_rectangle_int(S32 start, S32 end, S32 start_xy, S32 end_xy, gradient_color *gc, U32 flags)
{

	S32 fill_lenght = end - start + 1;
	S32 i, fill_start = 0, fill_end, p, fill_i;
	FLOAT ir, ig, ib, divisor;
	FLOAT tr, tg, tb;
	U8 done = 0;
	color start_color, end_color, c;

	//S32 color_idx;//, color_idx_end;
	for (i = 0; (i < (gc->n - 1) && !done); i++)
	{
	    //color_idx = i;
		//color_idx_end = color_idx + 1;
		//if(flags & UI_GRADIENT_COLOR_FLIP)
		//{
        //   color_idx = gc->n - 1 - i;
		 //  color_idx_end = color_idx - 1;
		//}
		
		start_color = gc->c[i];
		end_color = gc->c[i + 1];
		p = gc->p[i];
		fill_end = fill_start + pixtel_percent(fill_lenght, p);
		if (fill_end > fill_lenght - 1)
		{
			fill_end = fill_lenght - 1;
			done = 1;
		}
		divisor = (FLOAT) (fill_end - fill_start) + 1;
		if (divisor == 0)
		{
			divisor = 1;
		}
		ir = -(start_color.r - end_color.r) / divisor;
		ig = -(start_color.g - end_color.g) / divisor;
		ib = -(start_color.b - end_color.b) / divisor;
		tr = c.r = start_color.r;
		tg = c.g = start_color.g;
		tb = c.b = start_color.b;
		c.alpha = start_color.alpha;
		for (fill_i = fill_start; fill_i <= fill_end; fill_i++)
		{
		    if (flags & UI_GRADIENT_COLOR_VERTICAL)
				gui_draw_horizontal_line(start_xy, end_xy, fill_i + start, c);
			else
				gui_draw_vertical_line(start_xy, end_xy, fill_i+ start, c);

			tr += ir;
			tg += ig;
			tb += ib;
			c.r = (S8) tr;
			c.g = (S8) tg;
			c.b = (S8) tb;
		}
		fill_start = fill_end + 1;
	}

}


/*****************************************************************************
 * FUNCTION
 *  gui_gradient_fill_rectangle
 * DESCRIPTION
 *  Gradient color fills a rectangle
 * PARAMETERS
 *  x1                                  [IN]        Left-top corner of the rectangle
 *  y1                                  [IN]        Left-top corner of the rectangle
 *  x2                                  [IN]        Right-bottom corner of the rectangle
 *  y2                                  [IN]        Right-bottom corner of the rectangle
 *  gc                                  [IN]        Is the gradient color
 *  flags                               [IN]        Can have the following values:
 * RETURNS
 *  void
 *****************************************************************************/
#if(UI_INDEXED_COLOR_SYSTEM)

void gui_gradient_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, gradient_color *gc, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flags & UI_GRADIENT_COLOR_VERTICAL)
    {
        S32 fill_height = y2 - y1 + 1;
        S32 i, y_start = 0, y_end, p;
        U8 done = 0;
        color start_color, end_color;

        if (flags & UI_GRADIENT_COLOR_FLIP)
        {
            for (i = gc->n - 1; (i > 0 && !done); i--)
            {
                start_color = gc->c[i];
                end_color = gc->c[i - 1];
                p = gc->p[i - 1];
                y_end = y_start + pixtel_percent(fill_height, p);
                if (y_end > fill_height - 1)
                {
                    y_end = fill_height - 1;
                    done = 1;
                }
                gui_fill_rectangle(x1, y_start, x2, y_end, start_color);
                y_start = y_end + 1;
            }
        }
        else
        {
            for (i = 0; (i < (gc->n - 1) && !done); i++)
            {
                start_color = gc->c[i];
                end_color = gc->c[i + 1];
                p = gc->p[i];
                y_end = y_start + pixtel_percent(fill_height, p);
                if (y_end > fill_height - 1)
                {
                    y_end = fill_height - 1;
                    done = 1;
                }
                gui_fill_rectangle(x1, y_start, x2, y_end, start_color);
                y_start = y_end + 1;
            }
        }
    }
    else
    {
        S32 fill_width = x2 - x1 + 1;
        S32 i, x_start = 0, x_end, p;
        U8 done = 0;
        color start_color, end_color;

        if (flags & UI_GRADIENT_COLOR_FLIP)
        {
            for (i = gc->n - 1; (i > 0 && !done); i--)
            {
                start_color = gc->c[i];
                end_color = gc->c[i - 1];
                p = gc->p[i - 1];
                x_end = x_start + pixtel_percent(fill_width, p);
                if (x_end > fill_width - 1)
                {
                    x_end = fill_width - 1;
                    done = 1;
                }
                gui_fill_rectangle(x_start, y1, x_end, y2, start_color);
                x_start = x_end + 1;
            }
        }
        else
        {
            for (i = 0; (i < (gc->n - 1) && !done); i++)
            {
                start_color = gc->c[i];
                end_color = gc->c[i + 1];
                p = gc->p[i];
                x_end = x_start + pixtel_percent(fill_width, p);
                if (x_end > fill_width - 1)
                {
                    x_end = fill_width - 1;
                    done = 1;
                }
                gui_fill_rectangle(x_start, y1, x_end, y2, start_color);
                x_start = x_end + 1;
            }
        }
    }
}

#else /* (UI_INDEXED_COLOR_SYSTEM) */ 

void gui_gradient_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, gradient_color *gc, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flags & UI_GRADIENT_COLOR_VERTICAL)
    {
     gui_gradient_fill_rectangle_int(y1,y2,x1, x2, gc, flags);
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
	#endif	
    }
    else
    {
     gui_gradient_fill_rectangle_int(x1,x2,y1, y2, gc, flags);
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
	#endif	
    }
}

#endif /* (UI_INDEXED_COLOR_SYSTEM) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_transparent_texture_fill_rectangle
 * DESCRIPTION
 *  Texture fills a rectangle
 * PARAMETERS
 *  x1          [IN]        Left-top corner of the rectangle
 *  y1          [IN]        Left-top corner of the rectangle
 *  x2          [IN]        Right-bottom corner of the rectangle
 *  y2          [IN]        Right-bottom corner of the rectangle
 *  image       [IN]        Is the texture to use (repeating pattern bitmap)
 *  t           [IN]        Color which should be considered as transparent
 * RETURNS
 *  void
 *****************************************************************************/
void gui_transparent_texture_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, PU8 image, UI_transparent_color_type t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ysize = y2 - y1 + 1;
    S32 xsize = x2 - x1 + 1;
    S32 i, j, txsize, tysize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image(image, &txsize, &tysize);
    gui_push_clip();
    gui_set_clip_preset(x1, y1, x2, y2);
    for (j = 0; j < ysize; j += tysize)
    {
        for (i = 0; i < xsize; i += txsize)
        {
            gui_show_transparent_image(x1 + i, y1 + j, image, t);
        }
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_texture_fill_rectangle
 * DESCRIPTION
 *  Texture fills a rectangle
 * PARAMETERS
 *  x1          [IN]        Left-top corner of the rectangle
 *  y1          [IN]        Left-top corner of the rectangle
 *  x2          [IN]        Right-bottom corner of the rectangle
 *  y2          [IN]        Right-bottom corner of the rectangle
 *  image       [IN]        Is the texture to use (repeating pattern bitmap)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_texture_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, PU8 image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE current_active_lager;
    U8 *layer_buffer_ptr;
    U32 *write_buffer_ptr, *first_image_buffer_ptr;
    S32 layer_width, layer_height, image_width, image_height;
    S32 i, j, x_times, y_times, rows;
    S32 last_width, last_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((y2 < y1) || (x2 < x1) || (x1 >= GDI_LCD->act_width) || (x2 < 0) || (y1 >= GDI_LCD->act_height) || (y2 < 0))
    {
        return;
    }
    
    gdi_layer_get_active(&current_active_lager);
    gdi_layer_get_buffer_ptr(&layer_buffer_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    if (x1 < 0)
    {
        x1 = 0;
    }
    if (y1 < 0)
    {
        y1 = 0;
    }
    if (x2 > layer_width - 1)
    {
        x2 = layer_width - 1;
    }
    if (y2 > layer_height - 1)
    {
        y2 = layer_height - 1;
    }

    gdi_image_get_dimension(image, &image_width, & image_height);

    if ((image_width >= x2 - x1 + 1) && (image_height >= y2 - y1 + 1))
    {
       // gdi_layer_push_clip();
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        gdi_image_draw(x1, y1, image);
        gdi_layer_pop_clip();
    }
    else if ((image_width <= x2 - x1 + 1) && (image_height > y2 - y1 + 1))
    {
        first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1, layer_width);

        x_times = (x2 - x1 + 1) / image_width;
        rows = ((image_height) < (y2 - y1 + 1)) ? (image_height) : (y2 - y1 + 1);
        last_width = (x2 - x1 + 1) % image_width;        

        //gdi_layer_push_clip();
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        gdi_image_draw(x1, y1, image);
        gdi_layer_pop_clip();

        for (i = 1; i < x_times; i ++)
        {
            for ( j = 0; j < rows; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1 + i * image_width, y1 + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, image_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }

        if (last_width != 0)
        {
            for ( j = 0; j < rows; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1 + i * image_width, y1 + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, last_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }
    }
    else if ((image_width > x2 - x1 + 1) && (image_height <= y2 - y1 + 1))
    {
        first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1, layer_width);

        y_times = (y2 - y1 + 1) / image_height;
        rows = image_height;
        last_width = ((image_width) < (x2 - x1 + 1)) ? (image_width) : (x2 - x1 + 1);
        last_height = (y2 - y1 + 1) % image_height;

       // gdi_layer_push_clip();
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        gdi_image_draw(x1, y1, image);
        gdi_layer_pop_clip();

        for (i = 1; i < y_times; i ++)
        {
            for ( j = 0; j < rows; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + i * image_height + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, last_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }

        if (last_height != 0)
        {
            for ( j = 0; j < last_height; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + i * image_height + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, last_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }
     
    }
    else 
    { 
        first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1, layer_width);

        x_times = (x2 - x1 + 1) / image_width;
        y_times = (y2 - y1 + 1) / image_height;
        rows = image_height;
        last_width = (x2 - x1 + 1) % image_width;
        last_height = (y2 - y1 + 1) % image_height;

       // gdi_layer_push_clip();
        gdi_layer_push_and_set_clip(x1, y1, x2, y2);
        gdi_image_draw(x1, y1, image);
        gdi_layer_pop_clip();

        for (i = 1; i < x_times; i ++)
        {
            for ( j = 0; j < rows; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1 + i * image_width, y1 + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, image_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }

        if (last_width != 0)
        {
            for ( j = 0; j < rows; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1 + i * image_width, y1 + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);
        
                memcpy(write_buffer_ptr, first_image_buffer_ptr, last_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }

        last_width = x2 - x1 + 1;
        for (i = 1; i < y_times; i ++)
        {
            for (j = 0; j < rows; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + i * image_height + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, last_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }

        if (last_height != 0)
        {
            for (j = 0; j < last_height; j ++)
            {
                write_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + i * image_height + j, layer_width);
                first_image_buffer_ptr = BUF_PIXEL_OFFSET(layer_buffer_ptr, x1, y1 + j, layer_width);

                memcpy(write_buffer_ptr, first_image_buffer_ptr, last_width * (gdi_act_layer->bits_per_pixel >> 3));
            }
        }
    
    }
    
    
}


/* NOTICE: the watermark may fail in bad luck */
#define GUI_DARKEN_WATERMARK   0xABADC0DE
#define GUI_DARKEN_PERCENT      75


#if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)

/*****************************************************************************
 * FUNCTION
 *  gui_check_watermark
 * DESCRIPTION
 *  Check if there is a 32-bit watermark starting from (x, y) to (x, y + pixel_num - 1).
 * PARAMETERS
 *  x           [IN]    x
 *  y           [IN]    y
 *  pixel_num   [IN]    number of pixels to be checked (1 ~ 32)
 * RETURNS
 *  MMI_TRUE if there is a watermark; otherwise, MMI_FALSE
 *****************************************************************************/
static MMI_BOOL gui_check_watermark(S32 x, S32 y, S32 pixel_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color   p;
    S32         i;
    U32         a, r, g, b;
    U32         real_blue_bit0_pos_in_8;
    S32         width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pixel_num > 32)
    {
        pixel_num = 32;
    }
    
    /*
     * The watermark is at BLUE bit 0 of 32 sequential pixels.
     */    
    if (gdi_layer_get_bit_per_pixel() == 16)
    {
        real_blue_bit0_pos_in_8 = 3;
    }
    else
    {
        real_blue_bit0_pos_in_8 = 0;
    }

    width = 0;
    gdi_layer_get_dimension(&width, &height);
    if (y + pixel_num > height)
    {
        pixel_num = height - y;
    }
    
    for (i = 0; i < pixel_num; i++)
    {
        p = gdi_act_get_pixel(x, y + i);
        gdi_act_color_to_rgb(&a, &r, &g, &b, p);
        b >>= real_blue_bit0_pos_in_8;
        b &= 1;

        if (b != ((GUI_DARKEN_WATERMARK >> (31 - i)) & 1))
        {
            break;
        }
    }

    if (i == pixel_num)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_put_watermark
 * DESCRIPTION
 *  Put a 32-bit watermark starting from (x, y) to (x, y + pixel_num - 1).
 * PARAMETERS
 *  x           [IN]    x
 *  y           [IN]    y
 *  pixel_num   [IN]    number of pixels to put the watermark (1 ~ 32)
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_put_watermark(S32 x, S32 y, S32 pixel_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color   p;
    S32         i;
    U32         watermark = GUI_DARKEN_WATERMARK;
    U32         a, r, g, b;
    U32         real_blue_bit0_pos_in_8;
    S32         width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pixel_num > 32)
    {
        pixel_num = 32;
    }
    
    /*
     * The watermark is at BLUE bit 0 of 32 sequential pixels.
     */
    if (gdi_layer_get_bit_per_pixel() == 16)
    {
        real_blue_bit0_pos_in_8 = 3;
    }
    else
    {
        real_blue_bit0_pos_in_8 = 0;
    }

    width = 0;
    gdi_layer_get_dimension(&width, &height);
    if (y + pixel_num > height)
    {
        pixel_num = height - y;
    }
    
    for (i = 0; i < pixel_num; i++)
    {
        p = gdi_act_get_pixel(x, y + i);
        gdi_act_color_to_rgb(&a, &r, &g, &b, p);

        /* stamp blue bit 0 */
        b &= ~(1 << real_blue_bit0_pos_in_8);
        b |= (watermark >> 31) << real_blue_bit0_pos_in_8;
        watermark <<= 1;

        p = gdi_act_color_from_rgb(a, r, g, b);
        gdi_act_put_pixel(x, y + i, p);
    }
}

#endif /* (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN) */


/*****************************************************************************
 * FUNCTION
 *  gui_greyscale_rectangle
 * DESCRIPTION
 *  Greyscale the assigned region
 * PARAMETERS
 *  x1              [IN]        Left-top corner of the rectangle
 *  y1              [IN]        Left-top corner of the rectangle
 *  x2              [IN]        Right-bottom corner of the rectangle
 *  y2              [IN]        Right-bottom corner of the rectangle
 *  white_value     [IN]        0~255 change the gamma value of the region
 *  black_value     [IN]        0~255 change the darkness of the region
 * RETURNS
 *  void
 *****************************************************************************/
void gui_greyscale_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, S32 white_value, S32 black_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((x1 == 0) && (y1 == 0) && (x2 == UI_device_width - 1) && (y2 == UI_device_height - 1))
    {
        /* Full screen case */
    #if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)

        #ifdef __MMI_MAINLCD_320X480__
        {
            /*
             * Darken the status bar
             */
            if (gui_check_watermark(0, 0, MMI_STATUS_BAR_HEIGHT) != MMI_TRUE)
            {
                gdi_draw_darken_rect(0, 0, UI_device_width - 1, MMI_STATUS_BAR_HEIGHT - 1, GUI_DARKEN_PERCENT);
                gui_put_watermark(0, 0, MMI_STATUS_BAR_HEIGHT);
            }

            /*
             * Darken the title bar
             */
            if (gui_check_watermark(0, MMI_STATUS_BAR_HEIGHT, MMI_TITLE_HEIGHT) != MMI_TRUE)
            {
                gdi_draw_darken_rect(0, MMI_STATUS_BAR_HEIGHT, UI_device_width - 1, MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT - 1, GUI_DARKEN_PERCENT);
                gui_put_watermark(0, MMI_STATUS_BAR_HEIGHT, MMI_TITLE_HEIGHT);
            }

            /*
             * Darken the screen except softkey bar.
             */
            if (gui_check_watermark(0, MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT, 32) != MMI_TRUE)
            {
                gdi_draw_darken_rect(0, MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT, UI_device_width - 1, UI_device_height - 1, GUI_DARKEN_PERCENT);
                gui_put_watermark(0, MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT, 32);
                
            #if 0//def __MMI_SCREEN_SWITCH_EFFECT__
/* under construction !*/
            #endif
            }    

            /*
             * Darken the popup dialog
             */
        #if 0//def __MMI_SCREEN_SWITCH_EFFECT__
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
        #endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
        }
        #else /* __MMI_MAINLCD_320X480__ */
        {
            /*
             * Use a simple watermark trick here to decide whether a rect was darkened or not.
             */
            // TODO: FIX ME! THE WATERMARK MAY GO WRONG. THE DECISION TO DARKEN OR NOT
            // TODO: SHOULD BE DECIDED BY THE CATEGORY. BUT MAYBE IT IS HARD?

            /*
             * Darken the screen except softkey bar.
             */
            if (gui_check_watermark(0, 0, 32) != MMI_TRUE)
            {
                gdi_draw_darken_rect(0, 0, UI_device_width - 1, UI_device_height - MMI_BUTTON_BAR_HEIGHT - 1, GUI_DARKEN_PERCENT);
                gui_put_watermark(0, 0, 32);

            #if 0//def __MMI_SCREEN_SWITCH_EFFECT__
/* under construction !*/
            #endif
                
                /* put watermark for category 112 small screen virtual keyboard */
            #ifdef __MMI_TOUCH_SCREEN__
                gui_put_watermark(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT - 32, 32);
            #endif
            }    
            
            /* 
             * Darken the softkey bar.
             * This is necessary for category 165, which has a small screen and softkey bar.
             */
            if (gui_check_watermark(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT, MMI_BUTTON_BAR_HEIGHT) != MMI_TRUE)
            {
                gdi_draw_darken_rect(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT, UI_device_width - 1, UI_device_height - 1, GUI_DARKEN_PERCENT);
                gui_put_watermark(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT, MMI_BUTTON_BAR_HEIGHT);
            }        

        #ifdef __MMI_VIRTUAL_KEYBOARD__
            /* darken for category 112 small screen virtual keyboard */
            if (gui_check_watermark(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT - 32, 32) != MMI_TRUE)
            {
             #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
                /* darken keyboard area */
                // TODO: MAGIC NUMBER - 1 must be synced. See mmi_imui_draw_back_ground().
                gdi_draw_darken_rect(0, MMI_virtual_keyboard.y - 1, UI_device_width - 1, UI_device_height - MMI_BUTTON_BAR_HEIGHT - 1, GUI_DARKEN_PERCENT);
             #else
                 S32 vk_x, vk_y;
                 /* darken keyboard area */
                // TODO: MAGIC NUMBER - 1 must be synced. See mmi_imui_draw_back_ground().
                wgui_virtual_keyboard_get_positon(&vk_x, &vk_y);
                gdi_draw_darken_rect(0, vk_y - 1, UI_device_width - 1, UI_device_height - MMI_BUTTON_BAR_HEIGHT - 1, GUI_DARKEN_PERCENT);
             #endif
                /* put watermark again for darkened lines */
                gui_put_watermark(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT - 32, 32);
            }
        #endif /* __MMI_VIRTUAL_KEYBOARD__ */

            /*
             * Screen Switch Effect
             */
        #if 0//def __MMI_SCREEN_SWITCH_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
        }
        #endif /* __MMI_MAINLCD_320X480__ */
    
    #else /* (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN) */
        gdi_layer_apply_gray_effect();
    #endif /* (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN) */     
    }
    else
    {
        /* Partial screen case */
        if (white_value == 0 && black_value == 0)
        {
            gdi_draw_darken_rect(x1, y1, x2, y2, GUI_DARKEN_PERCENT);
        }
        else
        {
            gdi_draw_greyscale_rect(x1, y1, x2, y2, white_value, black_value);
        }
    }
}


/* array storing the color bit values used for calculating the gradient color */
S32 rounded_corner_color_bit[6][6] = 
{ 
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1, 2},
    {0, 1, 1, 2, 2, 3},
    {0, 1, 1, 2, 3, 4},
    {1, 1, 2, 3, 4, 5}
};


/*****************************************************************************
 * FUNCTION
 *  gui_draw_rounded_corner
 * DESCRIPTION
 *  This function will draw the gradient rounded corner of the rectangle
 * PARAMETERS
 *  x1                      [IN]        
 *  y1                      [IN]        
 *  size                    [IN]        
 *  rect_color_start        [IN]        It specifies the outermost start color of the border.
 *  rect_color_end          [IN]        It specifies the innermost end color of the border.
 *  level                   [IN]        Levels of different colors
 *  corner_style            [IN]        It specifies the corner of the rectangle.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_rounded_corner(
        S32 x1,
        S32 y1,
        S32 size,
        color rect_color_start,
        color rect_color_end,
        S32 level,
        mmi_gradient_rect_rounded_corner_style_enum corner_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x2, y2, i, j, color_percentage;
    S32 increment;
    color result;
    S32 idx1, idx2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (size == 0)//now only support fixed size with 6 pixels */
    size = 6;
    x2 = x1 + size - 1;
    y2 = y1 + size - 1;
    /* if (level == 0) */
    level = 5;
    increment = 100 / level;

    for (i = y1; i <= y2; i++)
    {
        for (j = x1; j <= x2; j++)
        {
            switch(corner_style)
            {
				case MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_LEFT:
				{
					idx1 = i - y1;
					idx2 = j - x1;
					break;
				}
				case MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_RIGHT:
				{
					idx1 = x2 - j;
					idx2 = i - y1;
					break;
				}
				
				case MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_LEFT:
				{
					idx1 = j - x1;
					idx2 = y2 - i;
					break;
				}
				
				case MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_RIGHT:
				{
					idx1 = x2 - j;
					idx2 = y2 - i;
					break;
				}
				default:
					return;

			}
            if ((rounded_corner_color_bit[idx1][idx2] > 0))
            {
                color_percentage = 100 - ((rounded_corner_color_bit[idx1][idx2]) - 1) * increment;
                result = gui_blend_two_color(
                            rect_color_start,
                            rect_color_end,
                            color_percentage,
                            100 - color_percentage);
                gui_putpixel(j, i, result);
            }
        }
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
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_gradient_rounded_rectangle
 * DESCRIPTION
 *  This function is used to draw the rounded rectangle with gradient border.
 * PARAMETERS
 *  x1                  [IN]        Left-top coordinate of the rectangle.
 *  y1                  [IN]        
 *  x2                  [IN]        Bottom-right coordinate of the rectangle.
 *  y2                  [IN]        
 *  start_color         [IN]        It specifies the outermost start color of the border.
 *  end_color           [IN]        It specifies the innermost end color of the border.
 *  border_width        [IN]        It specifies the width of the border.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_gradient_rounded_rectangle(
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2,
        color start_color,
        color end_color,
        S32 border_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = border_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //currently the width is hardcoded to 6. It will be removed later.
    //if (width == 0)
    width = 6;

    /* fill the inner rectanlgle */
    gui_fill_rectangle(x1 + width, y1 + width, x2 - width, y2 - width, end_color);

    /* draw the top horizontal gradient border */
    gdi_draw_gradient_rect(
        x1 + width,
        y1,
        x2 - width,
        y1 + width,
        gdi_act_color_from_rgb(start_color.alpha, start_color.r, start_color.g, start_color.b),
        gdi_act_color_from_rgb(end_color.alpha, end_color.r, end_color.g, end_color.b),
        0,
        0,
        GDI_GRADIENT_RECT_VER);

    /* draw the bottom horizontal gradient border */
    gdi_draw_gradient_rect(
        x1 + width,
        y2 - width,
        x2 - width,
        y2,
        gdi_act_color_from_rgb(end_color.alpha, end_color.r, end_color.g, end_color.b),
        gdi_act_color_from_rgb(start_color.alpha, start_color.r, start_color.g, start_color.b),
        0,
        0,
        GDI_GRADIENT_RECT_VER);

    /* draw the left vertical gradient border */
    gdi_draw_gradient_rect(
        x1,
        y1 + width,
        x1 + width,
        y2 - width,
        gdi_act_color_from_rgb(start_color.alpha, start_color.r, start_color.g, start_color.b),
        gdi_act_color_from_rgb(end_color.alpha, end_color.r, end_color.g, end_color.b),
        0,
        0,
        GDI_GRADIENT_RECT_HOR);

    /* draw the right vertical gradient border */
    gdi_draw_gradient_rect(
        x2 - width,
        y1 + width,
        x2,
        y2 - width,
        gdi_act_color_from_rgb(end_color.alpha, end_color.r, end_color.g, end_color.b),
        gdi_act_color_from_rgb(start_color.alpha, start_color.r, start_color.g, start_color.b),
        0,
        0,
        GDI_GRADIENT_RECT_HOR);

    /* draw the top left gradient corner border */
    gui_draw_rounded_corner(x1, y1, 0, start_color, end_color, 0, MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_LEFT);

    /* draw the top right gradient corner border */
    gui_draw_rounded_corner(
        x2 - width + 1,
        y1,
        0,
        start_color,
        end_color,
        0,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_RIGHT);

    /* draw the bottom left gradient corner border */
    gui_draw_rounded_corner(
        x1,
        y2 - width + 1,
        0,
        start_color,
        end_color,
        0,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_LEFT);

    /* draw the bottom right gradient corner border */
    gui_draw_rounded_corner(
        x2 - width + 1,
        y2 - width + 1,
        0,
        start_color,
        end_color,
        0,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_RIGHT);
}


/* 
 * HLS colorspace
 * http://en.wikipedia.org/wiki/HSV_color_space
 * http://en.wikipedia.org/wiki/HLS_color_space
 */

#define COLOR_MAX(a, b)    ((a) >= (b) ? (a) : (b))
#define COLOR_MIN(a, b)    ((a) >= (b) ? (b) : (a))
#define COLOR_MAX3(r, g, b)   COLOR_MAX(COLOR_MAX((r), (g)), (b))
#define COLOR_MIN3(r, g, b)   COLOR_MIN(COLOR_MIN((r), (g)), (b))
#define UI_UNDEFINED_HUE      0x0FFF

#if !defined(__MTK_TARGET__)
/* Round to integer */
#define RINT gui_util_rint
#else /* !defined(__MTK_TARGET__) */ 
#define RINT rint
#endif /* !defined(__MTK_TARGET__) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_util_fix_short_integer_bound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [OUT]         
 *  min         [IN]        
 *  max         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_util_fix_short_integer_bound(S16 *v, S16 min, S16 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*v < min)
    {
        *v = min;
    }
    else if (*v > max)
    {
        *v = max;
    }
}

#if !defined(__MTK_TARGET__)
/* Round floating point to nearest integer */


/*****************************************************************************
 * FUNCTION
 *  gui_util_rint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static double gui_util_rint(double d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double m = fmod(d, 1.0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m < 0.5)
    {
        return floor(d);
    }
    else
    {
        return ceil(d);
    }
}
#endif /* !defined(__MTK_TARGET__) */ 

/* FIXME. Add Alpha value in UI_HLS_color */


/*****************************************************************************
 * FUNCTION
 *  gui_RGB_to_HLS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rgb     [IN]        
 *  hls     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_RGB_to_HLS(color rgb, UI_HLS_color *hls)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double r, g, b; /* 0-1.0 */
    double mx /* max of r,g,b */ , mn /* min of r.g.b */ , md /* diff of min/max */ ;
    U8 max_rgb;     /* 0-255 */
    S16 h, l, s;    /* Use S16 to prevent overflow */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    r = (double)rgb.r / 255.0;
    g = (double)rgb.g / 255.0;
    b = (double)rgb.b / 255.0;

    mx = COLOR_MAX3(r, g, b);
    mn = COLOR_MIN3(r, g, b);
    md = mx - mn;

    l = (S16) RINT((mx + mn) * 255.0 / 2.0);    /* 0-255 */

    if (md == 0.0)
    {
        h = UI_UNDEFINED_HUE;
        s = 0;
    }
    else
    {
        if (l <= 127)
        {
            s = (S16) RINT(md * 255.0 / (mx + mn));
        }
        else
        {
            s = (S16) RINT(md * 255.0 / (2.0 - mx - mn));
        }

        r = (((mx - r) * 60.0) + (md * 180.0)) / md;
        g = (((mx - g) * 60.0) + (md * 180.0)) / md;
        b = (((mx - b) * 60.0) + (md * 180.0)) / md;

        max_rgb = (U8) COLOR_MAX3(rgb.r, rgb.g, rgb.b);
        if (rgb.r == max_rgb)
        {
            h = (S16) RINT(b - g);
        }
        else if (rgb.g == max_rgb)
        {
            h = (S16) RINT(r - b + 120.0);
        }
        else
        {
            h = (S16) RINT(g - r + 240.0);
        }
    }

    gui_util_fix_short_integer_bound(&l, 0, 255);
    gui_util_fix_short_integer_bound(&s, 0, 255);
    if (h != UI_UNDEFINED_HUE)
    {
        if (h >= 360)
        {
            h -= 360;
        }
        if (h < 0)
        {
            h += 360;
        }
    }
    hls->l = (U8) l;
    hls->s = (U8) s;
    hls->h = (U16) h;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_hue_to_RGB
 * DESCRIPTION
 *  Convert HLS color to RGB colorspace
 * PARAMETERS
 *  v1          [IN]        
 *  v2          [IN]        
 *  vh          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static double gui_util_hue_to_RGB(double v1, double v2, double vh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vh < 0)
    {
        vh += 1.0;
    }
    if (vh > 1)
    {
        vh -= 1.0;
    }
    if ((6.0 * vh) < 1.0)
    {
        return v1 + (v2 - v1) * 6.0 * vh;
    }
    if ((2.0 * vh) < 1.0)
    {
        return v2;
    }
    if ((3.0 * vh) < 2.0)
    {
        return v1 + (v2 - v1) * ((2.0 / 3.0) - vh) * 6.0;
    }
    return v1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_HLS_to_RGB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hls     [IN]        
 *  rgb     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_HLS_to_RGB(UI_HLS_color hls, color *rgb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double var1, var2;
    double h, l, s;
    S16 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This is slightly different than standard implementation because 
       GUI might set s != 0 while h is undefined */
    if (hls.s == 0 || hls.h == UI_UNDEFINED_HUE)
    {
        rgb->r = hls.l;
        rgb->g = hls.l;
        rgb->b = hls.l;
    }
    else
    {
        h = (double)hls.h / 360.0;
        l = (double)hls.l / 255.0;
        s = (double)hls.s / 255.0;

        if (l <= 0.5)
        {
            var2 = l * (1 + s);
        }
        else
        {
            var2 = (l + s) - (s * l);
        }
        var1 = 2.0 * l - var2;

        tmp = (S16) RINT(255.0 * gui_util_hue_to_RGB(var1, var2, h + 1.0 / 3.0));
        gui_util_fix_short_integer_bound(&tmp, 0, 255);
        rgb->r = (U8) tmp;

        tmp = (S16) RINT(255.0 * gui_util_hue_to_RGB(var1, var2, h));
        gui_util_fix_short_integer_bound(&tmp, 0, 255);
        rgb->g = (U8) tmp;

        tmp = (S16) RINT(255.0 * gui_util_hue_to_RGB(var1, var2, h - 1.0 / 3.0));
        gui_util_fix_short_integer_bound(&tmp, 0, 255);
        rgb->b = (U8) tmp;
    }
    rgb->alpha = 100;
}

/* This must be initialized to a valid theme    */
UI_filled_area_border_theme *current_filled_area_border_theme = NULL;

UI_filled_area *current_UI_filler = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_shadow_filled_area
 * DESCRIPTION
 *  Draws a shadow for a filled area
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  x1      [IN]        Left-top corner of the rectangle
 *  y1      [IN]        Left-top corner of the rectangle
 *  x2      [IN]        Right-bottom corner of the rectangle
 *  y2      [IN]        Right-bottom corner of the rectangle
 *  f       [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shadow_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags = f->flags;
    color shadow_color = f->shadow_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flags & UI_FILLED_AREA_SHADOW_DOUBLE_LINE)
    {
        if ((flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
        {
            if (flags & UI_FILLED_AREA_ROUNDED_BORDER)
            {
                gui_draw_horizontal_line(x1 + 3, x2 + 1, y2 + 1, shadow_color);
                gui_draw_horizontal_line(x1 + 4, x2, y2 + 2, shadow_color);
                gui_draw_vertical_line(y1 + 3, y2, x2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 4, y2, x2 + 2, shadow_color);
                gui_putpixel(x2 - 1, y2, shadow_color);
                gui_putpixel(x2, y2, shadow_color);
                gui_putpixel(x2, y2 - 1, shadow_color);
            }
            else
            {
                gui_draw_horizontal_line(x1 + 2, x2 + 2, y2 + 1, shadow_color);
                gui_draw_horizontal_line(x1 + 2, x2 + 2, y2 + 2, shadow_color);
                gui_draw_vertical_line(y1 + 2, y2, x2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 2, y2, x2 + 2, shadow_color);
            }
        }
        else
        {
            if (flags & UI_FILLED_AREA_ROUNDED_BORDER)
            {
                gui_draw_horizontal_line(x1 + 3, x2 + 1, y2 + 1, shadow_color);
                gui_draw_horizontal_line(x1 + 4, x2, y2 + 2, shadow_color);
                gui_draw_vertical_line(y1 + 3, y2, x2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 4, y2, x2 + 2, shadow_color);
                gui_putpixel(x2 - 1, y2, shadow_color);
                gui_putpixel(x2, y2, shadow_color);
                gui_putpixel(x2, y2 - 1, shadow_color);
            }
            else
            {
                gui_draw_horizontal_line(x1 + 2, x2 + 2, y2 + 1, shadow_color);
                gui_draw_horizontal_line(x1 + 2, x2 + 2, y2 + 2, shadow_color);
                gui_draw_vertical_line(y1 + 2, y2, x2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 2, y2, x2 + 2, shadow_color);
            }
        }
    }
    else
    {
        if ((flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
        {
            if (flags & UI_FILLED_AREA_ROUNDED_BORDER)
            {
                gui_draw_horizontal_line(x1 + 3, x2 - 2, y2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 3, y2 - 2, x2 + 1, shadow_color);
                gui_putpixel(x2, y2 - 1, shadow_color);
                gui_putpixel(x2 - 1, y2, shadow_color);
            }
            else
            {
                gui_draw_horizontal_line(x1 + 1, x2 + 1, y2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 1, y2, x2 + 1, shadow_color);
            }
        }
        else
        {
            if (flags & UI_FILLED_AREA_ROUNDED_BORDER)
            {
                gui_draw_horizontal_line(x1 + 2, x2 - 1, y2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 2, y2 - 1, x2 + 1, shadow_color);
                gui_putpixel(x2, y2, shadow_color);
            }
            else
            {
                gui_draw_horizontal_line(x1 + 1, x2 + 1, y2 + 1, shadow_color);
                gui_draw_vertical_line(y1 + 1, y2, x2 + 1, shadow_color);
            }
        }
    }
}

/* c=c+x such that c does not go above 255   */
#define INCREMENT_COLOR_COMPONENT(c,x)    \
{  S32   cc=c;                            \
   cc=cc+x;                               \
   if(cc>255) cc=255;                     \
   c=(U8)cc;                              \
}

/* c=c-x such that c does not go below 0  */
#define DECREMENT_COLOR_COMPONENT(c,x)    \
{  S32   cc=c;                            \
   cc=cc-x;                               \
   if(cc<0) cc=0;                         \
   c=(U8)cc;                              \
}

#define UI_FILLED_AREA_INFO_BORDER_OFFSET 5


/*****************************************************************************
 * FUNCTION
 *  gui_custom_fill_area_type2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  f       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_custom_fill_area_type2(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rx1 = x1, rx2 = x2, ry1 = y1, ry2 = y2, i = 0;
    color c = f->c;
    gdi_color gdi_c = gdi_act_color_from_rgb(255, c.r, c.g, c.b);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ry2 -= UI_FILLED_AREA_INFO_BORDER_OFFSET;

    gdi_draw_solid_rect(rx1 + 1, ry1 + 1, rx2 - 1, ry2 - 1, gdi_c);
    for (i = 0; i < 5; i++)
    {
        gdi_draw_line(rx1 + 9 + i, ry2 + i, rx1 + 17 - i, ry2 + i, gdi_c);
    }

    c = f->border_color;
    gdi_c = gdi_act_color_from_rgb(255, c.r, c.g, c.b);
    gdi_draw_line(rx1, ry1 + 2, rx1, ry2 - 2, gdi_c);
    gdi_draw_line(rx1 + 1, ry1 + 2, rx1 + 1, ry2 - 3, GDI_COLOR_WHITE);
    gdi_draw_line(rx1 + 2, ry1, rx2 - 2, ry1, gdi_c);
    gdi_draw_line(rx1 + 2, ry1 + 1, rx2 - 3, ry1 + 1, GDI_COLOR_WHITE);
    gdi_draw_point(rx1 + 1, ry1 + 1, gdi_c);            /* Line Next To Upper Line */
    gdi_draw_point(rx1 + 2, ry1 + 2, GDI_COLOR_WHITE);  /* Line Next To Upper Line */
    gdi_draw_point(rx2 - 1, ry1 + 1, gdi_c);            /* Line Next To Upper Line */
    gdi_draw_point(rx2 - 2, ry1 + 1, gdi_c);            /* Line Next To Upper Line */
    gdi_draw_point(rx1 + 1, ry2 - 1, gdi_c);            /* Lower Edge */
    gdi_draw_point(rx1 + 1, ry2 - 2, gdi_c);            /* Lower Edge */
    gdi_draw_point(rx2 - 1, ry2 - 1, gdi_c);            /* Ipx above lower edge */
    gdi_draw_point(rx2 - 2, ry2 - 2, gdi_c);            /* Ipx above lower edge */
    gdi_draw_line(rx2 - 1, ry1 + 2, rx2 - 1, ry2 - 2, gdi_c);
    gdi_draw_line(rx2, ry1 + 2, rx2, ry2 - 2, gdi_c);

    gdi_draw_line(rx1 + 2, ry2, rx1 + 8, ry2, gdi_c);
    gdi_draw_line(rx1 + 2, ry2 - 1, rx1 + 8, ry2 - 1, gdi_c);
    gdi_draw_line(rx1 + 18, ry2, rx2 - 2, ry2, gdi_c);
    gdi_draw_line(rx1 + 18, ry2 - 1, rx2 - 2, ry2 - 1, gdi_c);

    gdi_draw_line(rx1 + 8, ry2, rx1 + 13, ry2 + UI_FILLED_AREA_INFO_BORDER_OFFSET, gdi_c);
    gdi_draw_line(rx1 + 9, ry2, rx1 + 13, ry2 + UI_FILLED_AREA_INFO_BORDER_OFFSET - 1, gdi_c);
    gdi_draw_line(
        rx1 + 8 + UI_FILLED_AREA_INFO_BORDER_OFFSET,
        ry2 + UI_FILLED_AREA_INFO_BORDER_OFFSET,
        rx1 + 8 + (UI_FILLED_AREA_INFO_BORDER_OFFSET << 1),
        ry2,
        gdi_c);
    gdi_draw_line(
        rx1 + 8 + UI_FILLED_AREA_INFO_BORDER_OFFSET,
        ry2 + UI_FILLED_AREA_INFO_BORDER_OFFSET - 1,
        rx1 + 8 + (UI_FILLED_AREA_INFO_BORDER_OFFSET << 1),
        ry2,
        gdi_c);

}

/* For new hint style 2 & 3 */


/*****************************************************************************
 * FUNCTION
 *  gui_custom_fill_area_type1and2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  f       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_custom_fill_area_type1and2(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f)
{
#if defined(UI_POPUP_DESCRIPTION_STYLE_1)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(x1, y1, x2, y2, f->c);

#elif defined(UI_POPUP_DESCRIPTION_STYLE_2)
    UI_HLS_color hls;
    color sc;
    U8 l;

    gui_fill_rectangle(x1 + 1, y1 + 1, x2 - 2, y2 - 2, f->c);
    gui_putpixel(x1 + 1, y1 + 1, f->border_color);
    gui_putpixel(x1 + 1, y2 - 2, f->border_color);
    gui_putpixel(x2 - 2, y1 + 1, f->border_color);
    gui_putpixel(x2 - 2, y2 - 2, f->border_color);
    gui_draw_horizontal_line(x1 + 2, x2 - 3, y1, f->border_color);
    gui_draw_horizontal_line(x1 + 2, x2 - 3, y2 - 1, f->border_color);
    gui_draw_vertical_line(y1 + 2, y2 - 3, x1, f->border_color);
    gui_draw_vertical_line(y1 + 2, y2 - 3, x2 - 1, f->border_color);
    gui_RGB_to_HLS(f->c, &hls);
    l = hls.l;
    l -= (l >> 2);
    sc = gui_color(l, l, l);
    gui_draw_horizontal_line(x1 + 2 + 1, x2 - 3, y2, sc);
    gui_draw_vertical_line(y1 + 2 + 1, y2 - 3, x2, sc);
    l -= (l >> 3);
    sc = gui_color(l, l, l);
    gui_putpixel(x2 - 1, y2 - 2, sc);
    gui_putpixel(x2 - 2, y2 - 1, sc);
    l = hls.l;
    l -= (l >> 3);
    sc = gui_color(l, l, l);
    gui_putpixel(x1 + 2, y2, sc);
    gui_putpixel(x1 + 1, y2 - 1, sc);
    gui_putpixel(x2, y1 + 2, sc);

    gui_putpixel(x2 - 1, y2 - 1, sc);
    gui_putpixel(x2 - 2, y2, sc);
    gui_putpixel(x2, y2 - 2, sc);

#elif defined(UI_POPUP_DESCRIPTION_STYLE_3)
    color c, sc, bc, lc;    /* fill color, shadow color, border color, light color */
    S32 i;
    BOOL upward;

#if 1
    static color cache_c, cache_bc, cache_sc;

    c = f->c;
    bc = f->border_color;
    lc = gui_color(255, 255, 255);
    if (memcpy(&cache_c, &c, sizeof(color)) || memcpy(&cache_bc, &bc, sizeof(color)))
    {
        UI_HLS_color hls1, hls2;

        cache_c = c;
        cache_bc = bc;

        gui_RGB_to_HLS(c, &hls1);
        gui_RGB_to_HLS(bc, &hls2);
        hls2.l = ((hls1.l << 1) + hls2.l) / 3;
        hls2.s -= (hls2.s >> 4) + (hls2.s >> 3);    /* about 0.8 */
        gui_HLS_to_RGB(hls2, &cache_sc);
    }
    sc = cache_sc;
#else /* 1 */ /* alternative algorithm. simple but does not work for all color combination */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 1 */ 

    if ((f->flags & 0x0ff) == UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1)
    {
        upward = MMI_TRUE;
    }
    else
    {
        upward = MMI_FALSE;
    }

    if (upward)
    {
        y1 += 3;
    }
    else
    {
        y2 -= 3;
    }

    /* internal */
    gui_fill_rectangle(x1 + 2, y1 + 2, x2 - 2, y2 - 2, c);

    /* shadown */
    gui_draw_horizontal_line(x1 + 2, x2 - 2, y1 + 1, lc);
    gui_draw_horizontal_line(x1 + 2, x2 - 2, y2 - 1, sc);
    gui_draw_vertical_line(y1 + 2, y2 - 2, x1 + 1, sc);
    gui_draw_vertical_line(y1 + 2, y2 - 2, x2 - 1, sc);

    /* border */
    gui_draw_horizontal_line(x1 + 2, x2 - 2, y1, bc);
    gui_draw_horizontal_line(x1 + 2, x2 - 2, y2, bc);
    gui_draw_vertical_line(y1 + 2, y2 - 2, x1, bc);
    gui_draw_vertical_line(y1 + 2, y2 - 2, x2, bc);
    gui_putpixel(x1 + 1, y1 + 1, bc);
    gui_putpixel(x1 + 1, y2 - 1, bc);
    gui_putpixel(x2 - 1, y1 + 1, bc);
    gui_putpixel(x2 - 1, y2 - 1, bc);

// Min size is 15 for single character
    if (x2 - x1 > 10 + 5)
    {
        if (!mmi_fe_get_r2l_state())
        {
            x1 += 10;
        }
        else
        {
            x1 = x2 - 10 - 7;
        }
        x2 = x1 + 6;

        if (upward)
        {
            y1 -= 3;
            for (i = 0; i < 3; i++)
            {
                gui_draw_horizontal_line(x1 + 2 - i, x2 - 2 + i, y1 + i, bc);
            }

            for (i = 0; i < 4; i++)
            {
                gui_draw_horizontal_line(x1 + 3 - i, x2 - 3 + i, y1 + i, lc);
            }
            y1++;
            for (i = 0; i < 4; i++)
            {
                gui_draw_horizontal_line(x1 + 3 - i, x2 - 3 + i, y1 + i, c);
            }
        }
        else
        {
            y2 += 3;
            for (i = 0; i < 3; i++)
            {
                gui_draw_horizontal_line(x1 + 2 - i, x2 - 2 + i, y2 - i, bc);
            }

            for (i = 0; i < 4; i++)
            {
                gui_draw_horizontal_line(x1 + 3 - i, x2 - 3 + i, y2 - i, sc);
            }
            y2--;
            for (i = 0; i < 4; i++)
            {
                gui_draw_horizontal_line(x1 + 3 - i, x2 - 3 + i, y2 - i, c);
            }
        }
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  gui_fill_left_rounded_border
 * DESCRIPTION
 *  Draws a filled area with left rounded border shape
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  rx1     [IN]        Left-top corner of the rectangle
 *  ry1     [IN]        Left-top corner of the rectangle
 *  rx2     [IN]        Right-bottom corner of the rectangle
 *  ry2     [IN]        Right-bottom corner of the rectangle
 *  f       [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fill_left_rounded_border(S32 rx1, S32 ry1, S32 rx2, S32 ry2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color filler_color = f->c;
    color border_color = f->border_color;
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_draw_vertical_line(ry1, ry2, rx1 - 1, border_color);
    gui_draw_vertical_line(ry1 - 1, ry2 + 1, rx1, border_color);
    gui_draw_horizontal_line(rx1 + 5, rx2, ry1 - 6, border_color);
    gui_draw_horizontal_line(rx1 + 3, rx2, ry1 - 5, border_color);
    gui_draw_horizontal_line(rx1 + 5, rx2, ry2 + 6, border_color);
    gui_draw_horizontal_line(rx1 + 3, rx2, ry2 + 5, border_color);

    for(i = 1; i<5; i++)
    {  
	 gui_draw_horizontal_line(rx1 + i, rx2, ry1 - i, filler_color);	 
	 gui_draw_horizontal_line(rx1 + i, rx2, ry2 + i, filler_color);

	 gui_putpixel(rx1+ i-1, ry1 -(i-1)- 1, border_color);
     gui_putpixel(rx1 + i-1, ry1 -(i-1)- 2, border_color);

     gui_putpixel(rx1+(i-1), ry2 +(i-1)+ 1, border_color);
     gui_putpixel(rx1+(i-1), ry2 +(i-1) + 2, border_color);
	 
	}
#if	0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	gui_putpixel(rx1 + 4, ry1 - 4, border_color);
    gui_putpixel(rx1 + 4, ry1 - 5, border_color);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 	
    gui_putpixel(rx1 + 4, ry2 + 4, border_color);
    gui_putpixel(rx1 + 4, ry2 + 5, border_color);

}


/*****************************************************************************
 * FUNCTION
 *  gui_fill_right_rounded_border
 * DESCRIPTION
 *  Draws a filled area with right rounded border shape
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  rx1     [IN]        Left-top corner of the rectangle
 *  ry1     [IN]        Left-top corner of the rectangle
 *  rx2     [IN]        Right-bottom corner of the rectangle
 *  ry2     [IN]        Right-bottom corner of the rectangle
 *  f       [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fill_right_rounded_border(S32 rx1, S32 ry1, S32 rx2, S32 ry2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color filler_color = f->c;
    color border_color = f->border_color;
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_draw_vertical_line(ry1, ry2, rx2 + 1, border_color);
    gui_draw_vertical_line(ry1 - 1, ry2 + 1, rx2, border_color);
    gui_draw_horizontal_line(rx1, rx2 - 5, ry1 - 6, border_color);
    gui_draw_horizontal_line(rx1, rx2 - 3, ry1 - 5, border_color);
    gui_draw_horizontal_line(rx1, rx2 - 5, ry2 + 6, border_color);
    gui_draw_horizontal_line(rx1, rx2 - 3, ry2 + 5, border_color);

    for(i = 1; i<5; i++)
    {
		gui_draw_horizontal_line(rx1, rx2 - i, ry1 - i, filler_color);
		gui_draw_horizontal_line(rx1, rx2 - i, ry2 + i, filler_color);

		gui_putpixel(rx2 - i+1, ry1 -i+1 -1, border_color);
		gui_putpixel(rx2 - i+1, ry1 -i+1 -2, border_color);

		gui_putpixel(rx2-i+1, ry2 +(i-1)+ 1, border_color);
		gui_putpixel(rx2-i+1, ry2 +(i-1)+ 2, border_color);
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
	#endif


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
#endif	
    gui_putpixel(rx2 - 4, ry1 - 4, border_color); 
    gui_putpixel(rx2 - 4, ry1 - 5, border_color);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
    gui_putpixel(rx2 - 4, ry2 + 4, border_color);
    gui_putpixel(rx2 - 4, ry2 + 5, border_color);
}



/*****************************************************************************
 * FUNCTION
 *  gui_draw_filled_area
 * DESCRIPTION
 *  Draws a filled area
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  x1      [IN]        Left-top corner of the rectangle
 *  y1      [IN]        Left-top corner of the rectangle
 *  x2      [IN]        Right-bottom corner of the rectangle
 *  y2      [IN]        Right-bottom corner of the rectangle
 *  f       [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rx1 = x1, ry1 = y1, rx2 = x2, ry2 = y2, width, height;
    U32 flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f == NULL)
    {
        return;
    }
    flags = f->flags;
    if ((flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        rx1 += 2;
        rx2 -= 2;
        ry1 += 2;
        ry2 -= 2;
        if (flags & UI_FILLED_AREA_NO_VERTICAL_LINE)
        {
            rx1 -= 2;
            rx2 += 2;
        }
    }
    else if (flags & UI_FILLED_AREA_SINGLE_BORDER)
    {
        rx1 += 1;
        rx2 -= 1;
        ry1 += 1;
        ry2 -= 1;
        if (flags & UI_FILLED_AREA_NO_VERTICAL_LINE)
        {
            rx1 -= 1;
            rx2 += 1;
        }
    }
    if (flags & UI_FILLED_AREA_LEFT_RIGHT_ROUNDED_BORDER)
    {
        rx1 += 2;
        rx2 -= 2;
        ry1 += 6;
        ry2 -= 6;
    }
    else if (flags & UI_FILLED_AREA_LEFT_ROUNDED_BORDER)
    {
        rx1 += 2;
        ry1 += 6;
        ry2 -= 6;
    }
    else if (flags & UI_FILLED_AREA_RIGHT_ROUNDED_BORDER)
    {
        rx2 -= 2;
        ry1 += 6;
        ry2 -= 6;
    }

    switch (flags & 0x0ff)
    {
        case UI_FILLED_AREA_TYPE_COLOR:
        #if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)      /* 072505 Calvin modified */
            if (flags & UI_FILLED_AREA_TYPE_TRANSPARENT_COLOR)
            {
                gui_transparent_color_filler(rx1, ry1, rx2, ry2, f->c); /* For transparent color filler */
            }
            else
        #endif /* defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) */ 
            {
                gui_fill_rectangle(rx1, ry1, rx2, ry2, f->c);
            }
            break;
            
        case UI_FILLED_AREA_TYPE_GRADIENT_COLOR:
            gui_gradient_fill_rectangle(rx1, ry1, rx2, ry2, f->gc, flags);
            break;
            
        case UI_FILLED_AREA_TYPE_TEXTURE:
            //for slim
			#if 0
/* under construction !*/
/* under construction !*/
			#endif
            
        case UI_FILLED_AREA_TYPE_BITMAP:
        case UI_FILLED_AREA_TYPE_IMAGE_LEFT_ALIGN:
            gui_push_clip();
            gui_set_clip_preset(x1, y1, x2, y2);
            if (f->b && f->b[0] == GDI_IMAGE_TYPE_9SLICE)
            {
                gdi_image_draw_resized(x1, y1, x2 - x1 + 1, y2 - y1 + 1, f->b);
            }
            else if (f->transparent_color != UI_NULL_TRANSPARENT_COLOR)
            {
                gui_show_transparent_image(x1, y1, f->b, f->transparent_color);
            }
            else
            {
                gui_show_image(x1, y1, f->b);
            }
            gui_pop_clip();
            break;
        case UI_FILLED_AREA_TYPE_IMAGE_RIGHT_ALIGN:
            gui_measure_image(f->b, &width, &height);
            gui_push_clip();
            gui_set_clip_preset(x1, y1, x2, y2);
            if (width > (x2 - x1 + 1))
            {
                if (f->transparent_color != UI_NULL_TRANSPARENT_COLOR)
                {
                    gui_show_transparent_image(x2 + 1 - width, y1, f->b, f->transparent_color);
                }
                else
                {
                    gui_show_image(x2 + 1 - width, y1, f->b);
                }
            }
            else
            {
                if (f->transparent_color != UI_NULL_TRANSPARENT_COLOR)
                {
                    gui_show_transparent_image(x1, y1, f->b, f->transparent_color);
                }
                else
                {
                    gui_show_image(x1, y1, f->b);
                }
            }
            gui_pop_clip();
            break;    
            
        case UI_FILLED_AREA_TYPE_HATCH_COLOR:
            gui_hatch_fill_rectangle(rx1, ry1, rx2, ry2, f->c);
            break;
            
        case UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR:
            gui_alternate_hatch_fill_rectangle(rx1, ry1, rx2, ry2, f->c, f->ac);
            break;
            
        case UI_FILLED_AREA_TYPE_CROSS_HATCH_COLOR:
            gui_cross_hatch_fill_rectangle(rx1, ry1, rx2, ry2, f->c);
            break;
            
        case UI_FILLED_AREA_TYPE_ALTERNATE_CROSS_HATCH_COLOR:
            gui_alternate_cross_hatch_fill_rectangle(rx1, ry1, rx2, ry2, f->c, f->ac);
            break;

//for slim
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
#endif			
    }

    if (flags & UI_FILLED_AREA_LEFT_RIGHT_ROUNDED_BORDER)
    {
        gui_fill_left_rounded_border(rx1, ry1, x1 + (rx2 - rx1) / 2, ry2, f);
        gui_fill_right_rounded_border(x1 + (rx2 - rx1) / 2, ry1, rx2, ry2, f);
    }
    else if (flags & UI_FILLED_AREA_LEFT_ROUNDED_BORDER)
    {
        gui_fill_left_rounded_border(rx1, ry1, rx2, ry2, f);
    }
    else if (flags & UI_FILLED_AREA_RIGHT_ROUNDED_BORDER)
    {
        gui_fill_right_rounded_border(rx1, ry1, rx2, ry2, f);
    }

//for slim
//#if 0
    if (flags & UI_FILLED_AREA_BORDER)  /* if border flag is set */
    {
        color border_color = f->border_color;   /* border color */
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
                #if !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__)
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
                #else /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
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
                #endif /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
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
                #if !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
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
                #endif /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
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
        {
 #if 0       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #if !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__)
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
                #else /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
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
                #endif /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
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
            {
#if 0            
/* under construction !*/
/* under construction !*/
                #if !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /* !defined(__MMI_PLUTO_DOUBLEPX_ROUND_CORNER__) */ 
/* under construction !*/
/* under construction !*/
#endif					
                {
                    gui_draw_horizontal_line(x1, x2, y1, border_color);
                    gui_draw_vertical_line(y1, y2, x1, border_color);
                    gui_draw_horizontal_line(x1 + 1, x2, y2, border_color);
                    gui_draw_vertical_line(y1 + 1, y2 - 1, x2, border_color);
                }
            }
        }
    }
//	#endif
	//end for slim
    if (flags & UI_FILLED_AREA_SHADOW)
    {
        gui_shadow_filled_area(x1, y1, x2, y2, f);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_truncated_text
 * DESCRIPTION
 *  Print truncated text with no border .
 *  
 *  If length of text is greater  than
 *  screen width then the text is truncated . Three dots are shown at end of text
 * PARAMETERS
 *  x           [IN]        Start x positoin
 *  y           [IN]        Start Y position
 *  xwidth      [IN]        Width of text in pixels to display
 *  st          [IN]        Text to display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_print_truncated_text(S32 x, S32 y, S32 xwidth, UI_string_type st)
{
    mmi_font_engine_show_truncated_text(
        x, 
        y, 
        xwidth, 
        (U8*)st, 
        (U8*)((UI_string_type) GUI_TEXT_TRUNCATE_SUFFIX), 
        MMI_FALSE);
    UI_text_height = 0;        
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_truncated_text_ex
 * DESCRIPTION
 *  Print truncated text with no border .
 *  
 *  If length of text is greater  than
 *  screen width then the text is truncated . Three dots are shown at end of text
 * PARAMETERS
 *  x           [IN]        Start x positoin
 *  y           [IN]        Start Y position
 *  xwidth      [IN]        Width of text in pixels to display
 *  st          [IN]        Text to display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_print_truncated_text_ex(S32 x, S32 y, S32 xwidth, UI_string_type st)
{
    mmi_font_engine_show_truncated_text(
        x, 
        y, 
        xwidth, 
        (U8*)st, 
        (U8*)((UI_string_type) L"."), 
        MMI_FALSE);
    UI_text_height = 0;        
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_truncated_bordered_text2
 * DESCRIPTION
 *  Displays truncated bordered text (Does not display ...)
 * PARAMETERS
 *  x           [IN]        Top left corner of text display
 *  y           [IN]        Top left corner of text display
 *  xwidth      [IN]        Width (in pixels) available for text display
 *  ss          [IN]        Text to be displayed
 * RETURNS
 *  Non-zero if the complete string was displayed
 *  zero if the complete string could not be displayed
 *****************************************************************************/
U8 gui_print_truncated_bordered_text2(S32 x, S32 y, S32 xwidth, UI_string_type *text_p)
{
    mmi_font_engine_show_truncated_text(
        x, 
        y, 
        xwidth, 
        (U8*)*text_p, 
        NULL, // TODO: may I pass NULL here?
        MMI_TRUE);
    UI_text_height = 0;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_truncated_text2
 * DESCRIPTION
 *  Displays truncated text (Does not display ...)
 * PARAMETERS
 *  x           [IN]        Top left corner of text display
 *  y           [IN]        Top left corner of text display
 *  xwidth      [IN]        Width (in pixels) available for text display
 *  ss          [IN]         Text to be displayed
 * RETURNS
 *  Non-zero if the complete string was displayed
 *  zero if the complete string could not be displayed
 *****************************************************************************/
U8 gui_print_truncated_text2(S32 x, S32 y, S32 xwidth, UI_string_type *ss)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_font_engine_show_truncated_text(
            x, 
            y, 
            xwidth, 
            (U8*)(*ss), 
            NULL, // TODO: may I pass NULL here?
            MMI_FALSE);
    UI_text_height = 0;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_truncated_borderd_text
 * DESCRIPTION
 *  Print truncated text border .
 *  
 *  If length of text is greater  than
 *  screen width then the text is truncated . Three dots are shown at end of text
 * PARAMETERS
 *  x           [IN]        Start x positoin
 *  y           [IN]        Start Y position
 *  xwidth      [IN]        Width of text in pixels to display
 *  st          [IN]        Text to display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_print_truncated_borderd_text(S32 x, S32 y, S32 xwidth, UI_string_type st)
{
    mmi_font_engine_show_truncated_text(
        x, 
        y, 
        xwidth, 
        (U8*)st, 
        (U8*)((UI_string_type) GUI_TEXT_TRUNCATE_SUFFIX), 
        MMI_TRUE);
    UI_text_height = 0;        
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_text_by_direction
 * DESCRIPTION
 *  Print the text by forcing reading direction the same to r2lMMIFlag.
 * PARAMETERS
 *  str       [IN]  Text to display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_print_text_by_direction(UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 direction;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (str == NULL)
    {
        return;
    }
    
    if (mmi_fe_get_r2l_state())
    {
        direction = BIDI_R;
    }
    else
    {
        direction = BIDI_L;
    }
    
    ShowString_by_direction(
        UI_text_x,
        UI_text_y,
        *UI_font, 
        0, 
        (U8*)str, 
        UI_text_height,
        direction);
    UI_text_height = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_print_bordered_text_by_direction
 * DESCRIPTION
 *  Print the bordered text by forcing reading direction the same to r2lMMIFlag.
 * PARAMETERS
 *  str       [IN]  Text to display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_print_bordered_text_by_direction(UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 direction;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return;
    }
    
    if (mmi_fe_get_r2l_state())
    {
        direction = BIDI_R;
    }
    else
    {
        direction = BIDI_L;
    }

    ShowStringBordered_by_direction(
        UI_text_x,
        UI_text_y,
        *UI_font, 
        0, 
        (U8*)str, 
        UI_text_height,
        direction);
    UI_text_height = 0;
}



/*****************************************************************************
 * FUNCTION
 *  gui_draw_image_with_alpha_transparent
 * DESCRIPTION
 *  gui draw image with alpha transparent.
 * PARAMETERS
 *  str       [IN]  Text to display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_image_with_alpha_transparent(U8* img_ptr, S32 x, S32 y, S32 alpha)  
{
	 gdi_handle temp_layer = NULL;
	 S32 w, h;
	 S32 tmp_size;
	 U8 *tmp_buf;
	 gdi_image_get_dimension(img_ptr, &w, &h);
	 tmp_size = w * h * GDI_COLOR_FORMAT_32;
	 tmp_buf = (U8*) mmi_frm_scrmem_alloc_framebuffer(tmp_size);	 
	
	 gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32,
		 x,
		 y,
		 w,
		 h,
		 &temp_layer,
		 tmp_buf,
		 tmp_size);
					 
	 gdi_layer_push_and_set_active(temp_layer);
	 gdi_image_draw(
		0,
		0,
		img_ptr);
	gdi_layer_set_opacity(MMI_TRUE, alpha);

	gdi_layer_pop_and_restore_active();
//	gdi_image_bmp_encode_file(w,
//		 h,4, ((gdi_layer_struct*)temp_layer)->buf_ptr,  (PS8)L"E:\\b.bmp");

   ((gdi_layer_struct*)temp_layer)->offset_x = ((gdi_layer_struct*)temp_layer)->offset_x + gdi_act_layer->offset_x;
   ((gdi_layer_struct*)temp_layer)->offset_y = ((gdi_layer_struct*)temp_layer)->offset_y + gdi_act_layer->offset_y;
 


   gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer,temp_layer, 0 , 0);

	gdi_layer_free(temp_layer);
	mmi_frm_scrmem_free(tmp_buf);
}

void gui_draw_image_id_with_alpha_transparent(U16 image_id, S32 x, S32 y, S32 alpha)  
{
	gui_draw_image_with_alpha_transparent((U8*)GetImage(image_id),x, y, alpha);
}

/* 
 * Painter Component: encapsulates various painting operations with common interface
 */

/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_create_empty
 * DESCRIPTION
 *  Create an empty painter that draws nothing
 * PARAMETERS
 *  p       [OUT]           created painter object 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_create_empty(gui_util_painter_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->type = GUI_UTIL_PAINTER_TYPE_EMPTY;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_create_transparent
 * DESCRIPTION
 *  Create a painter that fills transparent background
 * PARAMETERS
 *  p       [OUT]           created painter object 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_create_transparent(gui_util_painter_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->type = GUI_UTIL_PAINTER_TYPE_TRANSPARENT;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_create_imageid
 * DESCRIPTION
 *  Create a painter that draws a image
 *
 *  Note: it's preferred to use image ID instead of raw data because 
 *  image ID can be drawn with downloadable theme.
 * PARAMETERS
 *  p           [OUT]       created painter object 
 *  imageid     [IN]        image to be drawn
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_create_imageid(gui_util_painter_struct *p, MMI_ID_TYPE imageid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->type = GUI_UTIL_PAINTER_TYPE_IMAGEID;
    p->_u.imageid = imageid;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_create_imageres
 * DESCRIPTION
 *  Create a painter that draws a image
 *
 *  Note: it's preferred to use image ID instead of raw data because 
 *  image ID can be drawn with downloadable theme.
 * PARAMETERS
 *  p           [OUT]       created painter object 
 *  imageid     [IN]        image to be drawn
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_create_imageres(gui_util_painter_struct *p, PU8 image_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->type = GUI_UTIL_PAINTER_TYPE_IMAGERES;
    p->_u.image_res = image_res;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_create_imageid
 * DESCRIPTION
 *  Create a painter that uses a callback to draw the region
 * PARAMETERS
 *  p           [OUT]       created painter object 
 *  callback    [IN]        callback draw function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_create_callback(gui_util_painter_struct *p, gui_util_painter_callback_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->type = GUI_UTIL_PAINTER_TYPE_CALLBACK;
    p->_u.callback = callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_create_filler
 * DESCRIPTION
 *  Create a painter that draws a filler
 * PARAMETERS
 *  p           [OUT]       created painter object 
 *  filler      [IN]        filler (must not be released before the painter object is released)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_create_filler(gui_util_painter_struct *p, const UI_filled_area *filler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->type = GUI_UTIL_PAINTER_TYPE_FILLER;
    p->_u.filler = filler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_show_clipped
 * DESCRIPTION
 *  Draw a painter in a clipped region
 *
 *  Note: if (x, y) is outside (clip_x1, clip_y1, clip_x2, clip_y2), it is clipped. 
 *
 *  For example, when it draws an image, the left-top corner of the image is
 *  (x, y), but the displayed area is (clip_x1, clip_y1, clip_x2, clip_y2).
 * PARAMETERS
 *  p               [IN]    painter object 
 *  x               [IN]    x coordinate of left-top corner of painting area
 *  y               [IN]    y coordinate of left-top corner of painting area
 *  clip_x1         [IN]    clipping area
 *  clip_y1         [IN]    clipping area
 *  clip_x2         [IN]    clipping area
 *  clip_y2         [IN]    clipping area
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_show_clipped(
        const gui_util_painter_struct *p, 
        S32 x, 
        S32 y, 
        S32 clip_x1, 
        S32 clip_y1, 
        S32 clip_x2, 
        S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x > clip_x2 || y > clip_y2 || clip_x2 < 0 || clip_y2 < 0 || 
        x >= UI_device_width || y >= UI_device_height)
    {
        return;
    }
    if (x > clip_x1)
    {
        clip_x1 = x;
    }
    if (y > clip_y1)
    {
        clip_y1 = y;
    }
    
    //gui_push_clip();
    gui_push_and_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    switch (p->type)
    {
        case GUI_UTIL_PAINTER_TYPE_TRANSPARENT:
            gdi_draw_solid_rect(clip_x1, clip_y1, clip_x2, clip_y2, GDI_COLOR_TRANSPARENT);
            break;
            
        case GUI_UTIL_PAINTER_TYPE_IMAGEID:
            gui_show_transparent_image(
                x,
                y,
                (PU8) GetImage(p->_u.imageid),
                UI_DEFAULT_TRANSPARENT_COLOR);
            break;
            
        case GUI_UTIL_PAINTER_TYPE_IMAGERES:
            gui_show_transparent_image(
                x,
                y,
                (PU8)(p->_u.image_res),
                UI_DEFAULT_TRANSPARENT_COLOR);
            break;

        case GUI_UTIL_PAINTER_TYPE_CALLBACK:
            p->_u.callback(x, y, clip_x1, clip_y1, clip_x2, clip_y2);
            break;

        case GUI_UTIL_PAINTER_TYPE_FILLER:
            /* Some types of filler have starting point, so we use x/y instead of clip_x1/clip_y1 */
            gui_draw_filled_area(x, y, clip_x2, clip_y2, (UI_filled_area *) p->_u.filler);
            break;
            
        default:
            /* Do nothing */
            break;
    }
 
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_util_painter_show
 * DESCRIPTION
 *  Draw a painter 
 * PARAMETERS
 *  p               [IN]    painter object 
 *  x1              [IN]    x coordinate of left-top corner 
 *  y1              [IN]    y coordinate of left-top corner 
 *  x2              [IN]    x coordinate of right-bottom corner 
 *  y2              [IN]    y coordinate of right-bottom corner 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_util_painter_show(const gui_util_painter_struct *p, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_util_painter_show_clipped(p, x1, y1, x1, y1, x2, y2);
}


/* 
 * Clean-up of GUI components 
 * To avoid clean-up each UI component explicitly in WGUI/draw manager/widget, 
 * general cleanup mechanism is provided here.
 */

static gui_cleanup_hook_hdlr g_mmi_gui_cleanup_hooks[GUI_MAX_CLEANUP_HOOK];


/*****************************************************************************
 * FUNCTION
 *  gui_add_cleanup_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_add_cleanup_hook(gui_cleanup_hook_hdlr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_cleanup_hook_hdlr *item = g_mmi_gui_cleanup_hooks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!fp)
    {
        return;
    }

    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (*item == fp)
        {
            return;
        }
        item++;
    }

    item = g_mmi_gui_cleanup_hooks;
    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (!*item)
        {
            *item = fp;
            return;
        }
        item++;
    }

    /* The table is full */
    MMI_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_remove_cleanup_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_remove_cleanup_hook(gui_cleanup_hook_hdlr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_cleanup_hook_hdlr *item = g_mmi_gui_cleanup_hooks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (*item == fp)
        {
            *item = NULL;
            return;
        }
        item++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_cleanup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_cleanup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_cleanup_hook_hdlr *item = g_mmi_gui_cleanup_hooks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (*item)
        {
            (*item) ();
            *item = NULL;   /* remove handler */
        }
        item++;
    }
}

/* 
 * Pre Clean-up of GUI components 
 * general pre cleanup mechanism is provided here.
 */

static gui_pre_cleanup_hook_hdlr g_mmi_gui_pre_cleanup_hooks[GUI_MAX_CLEANUP_HOOK];


/*****************************************************************************
 * FUNCTION
 *  gui_add_pre_cleanup_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_add_pre_cleanup_hook(gui_cleanup_hook_hdlr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_cleanup_hook_hdlr *item = g_mmi_gui_pre_cleanup_hooks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!fp)
    {
        return;
    }

    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (*item == fp)
        {
            return;
        }
        item++;
    }

    item = g_mmi_gui_pre_cleanup_hooks;
    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (!*item)
        {
            *item = fp;
            return;
        }
        item++;
    }

    /* The table is full */
    MMI_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_remove_pre_cleanup_hook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_remove_pre_cleanup_hook(gui_cleanup_hook_hdlr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_cleanup_hook_hdlr *item = g_mmi_gui_pre_cleanup_hooks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (*item == fp)
        {
            *item = NULL;
            return;
        }
        item++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_pre_cleanup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_pre_cleanup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_cleanup_hook_hdlr *item = g_mmi_gui_pre_cleanup_hooks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < GUI_MAX_CLEANUP_HOOK; i++)
    {
        if (*item)
        {
            (*item) ();
            *item = NULL;   /* remove handler */
        }
        item++;
    }
}



