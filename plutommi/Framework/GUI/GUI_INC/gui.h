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
 *   gui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Primitive UI variables & wrappers
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      gui.h
   Author:        manju
   Date Created:  August-13-2002
   Contains:      PixTel UI routines header
               Contains several parts and has been split to multiple
               code files. See other files named gui_*.c and gui_*.h
               This file contains common functions and data (prototypes only).
**********************************************************************************/

#ifndef __GUI_H__
#define __GUI_H__

#include "stdC.h"
#include "mmi_platform.h"
#include "CustDataRes.h"
#include "gui_config.h"
#include "CustThemesRes.h"
#include "MMI_features.h"

#include "gui_resource_type.h"

#include "gdi_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/* <group dom_utility_variables>
 *  global device screen size                    */
extern S32 UI_device_width;
/* <group dom_utility_variables> */
extern S32 UI_device_height;

/* <group dom_utility_variables>
 *  UI globals                                */
extern S32 UI_clip_x1;
/* <group dom_utility_variables> */
extern S32 UI_clip_y1;
/* <group dom_utility_variables> */
extern S32 UI_clip_x2;
/* <group dom_utility_variables> */
extern S32 UI_clip_y2;
/* <group dom_utility_variables> */
extern S32 UI_old_clip_x1;
/* <group dom_utility_variables> */
extern S32 UI_old_clip_y1;
/* <group dom_utility_variables> */
extern S32 UI_old_clip_x2;
/* <group dom_utility_variables> */
extern S32 UI_old_clip_y2;
/* <group dom_utility_variables> */
extern S32 UI_text_x;
/* <group dom_utility_variables> */
extern S32 UI_text_y;
/* <group dom_utility_variables> */
extern S32 UI_text_height;
/* <group dom_utility_variables> */
extern S32 UI_pointer_x;
/* <group dom_utility_variables> */
extern S32 UI_pointer_y;
/* <group dom_utility_variables> */
extern U8 UI_printf_buffer[];

/* <group dom_utility_macro>
 *  MACRO:   calculates the percentage              */
#define pixtel_percent(x,p)   ((x)*(p)/(100))

/* <group dom_utility_macro>
 *  MACRO:   toggles a value                        */
#define pixtel_toggle(x)   x=(U8)((x)?0:1)

/* <group dom_utility_macro>
 *  MACRO:   divides, adds 1 if there is a remainder      */
#define pixtel_highdivide(x,y)   ((((x)%(y))>0)?(((x)/(y))+1):((x)/(y)))

    /* Base functions required by the UI system:    */
    /* All UI components will use these functions      */
    /* And will not directly use any other OS/system   */
    /* related functions.                        */


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_putpixel
 * DESCRIPTION
 *  Draw color at a point
 * PARAMETERS
 *  x      : [IN]        The x coordinate of point
 *  y      : [IN]        The y coordinate of point  
 *  c      : [IN]        The color of point
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_putpixel) (S32 x, S32 y, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_vertical_line
 * DESCRIPTION
 *  Draw a vertical line by color
 * PARAMETERS
 *  x       : [IN]        The x coordinate of vertical line
 *  y1      : [IN]        The top y coordinate of vertical line      
 *  y2      : [IN]        The bottom y coordinate of vertical line
 *  c       : [IN]        The color of vertical line
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_draw_vertical_line) (S32 y1, S32 y2, S32 x, color c);



/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_horizontal_line
 * DESCRIPTION
 *  Use color to draw a horizontal line
 * PARAMETERS
 *  x1      : [IN]               The left cooridnate of horizontal line
 *  x2      : [IN]               The right cooridnate of horizotnal line
 *  y       : [IN]               The y coordinate of horizontal line
 *  c       : [IN]               The color of horizontal line
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_draw_horizontal_line) (S32 x1, S32 x2, S32 y, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_line
 * DESCRIPTION
 *  Draw a line from one point to other point
 * PARAMETERS
 *  x1      : [IN]        The x coordinate of point1
 *  y1      : [IN]        The y coordinate of point1
 *  x2      : [IN]        The x coordinate of point2
 *  y2      : [IN]        The y coordinate of point2
 *  c       : [IN]        The color of line
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_line) (S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_wline
 * DESCRIPTION
 *  Draw a wider line
 * PARAMETERS
 *  x1      : [IN]        The x cooridnate of point1
 *  y1      : [IN]        The y cooridnate of point1
 *  x2      : [IN]        The x cooridnate of point2
 *  y2      : [IN]        The y cooridnate of point2
 *  c       : [IN]        The color of line
 *  width   : [IN]        The width of line
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_wline) (S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 w);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_rectangle
 * DESCRIPTION
 *  Use color draw a rectangle
 * PARAMETERS
 *  x1      : [IN]        The x coordinate of left-top corner
 *  y1      : [IN]        The y coordinate of left-top corner
 *  x2      : [IN]        The x coordinate of right-bottom corner
 *  y2      : [IN]        The y cooridnate of right-bottom corner
 *  c       : [IN]        The color of rectangle
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_draw_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_fill_rectangle
 * DESCRIPTION
 *  Use color fill a rectangle
 * PARAMETERS
 *  x1      : [IN]        The x coordinate of left-top corner
 *  y1      : [IN]        The y coordinate of left-top corner
 *  x2      : [IN]        The x coordinate of right-bottom corner
 *  y2      : [IN]        The y coordinate of right-bottom corner
 *  c       : [IN]        The color of rectangle
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_cross_hatch_fill_rectangle
 * DESCRIPTION
 *  Use color fill rectangle with cross hatch
 * PARAMETERS
 *  x1      : [IN]        The x coordinate of left-top corner
 *  y1      : [IN]        The y coordinate of left-top corner
 *  x2      : [IN]        The x coordinate of right-bottom corner
 *  y2      : [IN]        The y coordinate of right-bottom corner
 *  c       : [IN]        The color of rectangle
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_cross_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_hatch_fill_rectangle
 * DESCRIPTION
 *  Use color fill rectangle with hatch
 * PARAMETERS
 *  x1      : [IN]        The x coordinate of left-top corner
 *  y1      : [IN]        The y coordinate of left-top corner
 *  x2      : [IN]        The x coordinate of right-bottom corner
 *  y2      : [IN]        The y coordinate of right-bottom corner
 *  c       : [IN]        The color of rectangle
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_alternate_cross_hatch_fill_rectangle
 * DESCRIPTION
 *  Use color fill a rectangle with alternate cross hatch
 * PARAMETERS
 *  x1      : [IN]          The x coordinate of left-top corner
 *  y1      : [IN]          The y coordinate of left-top corner
 *  x2      : [IN]          The x coordinate of right-bottom corner
 *  y2      : [IN]          The y coordinate of right-bottom corner
 *  c1      : [IN]          The color of rectangle
 *  c2      : [IN]          The color of alternate cross hatch
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_alternate_cross_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_alternate_hatch_fill_rectangle
 * DESCRIPTION
 *  Use color fill a rectangle with alternate hatch
 * PARAMETERS
 *  x1      : [IN]          The x coordinate of left-top corner
 *  y1      : [IN]          The y coordinate of left-top corner
 *  x2      : [IN]          The x coordinate of right-bottom corner
 *  y2      : [IN]          The y coordinate of right-bottom corner
 *  c1      : [IN]          The color of rectangle
 *  c2      : [IN]          The color of alternate hatch
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_alternate_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_text_clip
 * DESCRIPTION
 *  Set the clip of layer, the effect same as gdi_layer_set_clip
 * PARAMETERS
 *  x1      : [IN]          The x1 of clip area
 *  y1      : [IN]          The y1 of clip area
 *  x2      : [IN]          The x2 of clip area
 *  y2      : [IN]          The y2 of clip area
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_text_clip) (S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_get_text_clip
 * DESCRIPTION
 *  Get the layer of clip
 * PARAMETERS
 *  x1      : [OUT]         The pointer to store the x1 of clip area
 *  y1      : [OUT]         The pointer to store the y1 of clip area
 *  x2      : [OUT]         The pointer to store the x2 of clip area
 *  y2      : [OUT]         The pointer to store the y2 of clip area       
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_get_text_clip) (S32 *x1, S32 *y1, S32 *x2, S32 *y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_text_clip_preset
 * DESCRIPTION
 *  Set the clip interset with preset clip
 * PARAMETERS
 *  x1      : [IN]          The x1 of clip area
 *  y1      : [IN]          The y1 of clip area
 *  x2      : [IN]          The x2 of clip area
 *  y2      : [IN]          The y2 of clip area
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_text_clip_preset) (S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_clip
 * DESCRIPTION
 *  Set the clip of active layer
 * PARAMETERS
 *  x1      : [IN]          The x1 of clip area
 *  y1      : [IN]          The y1 of clip area
 *  x2      : [IN]          The x2 of clip area
 *  y2      : [IN]          The y2 of clip area
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_clip_with_bounding_box
 * DESCRIPTION
 *  Set the clip interset with given bound box
 * PARAMETERS
 *  x1      : [IN]          The x1 of clip area
 *  y1      : [IN]          The y1 of clip area
 *  x2      : [IN]          The x2 of clip area
 *  y2      : [IN]          The y2 of clip area
 *  bx1     : [IN]          The x1 of bound box
 *  by1     : [IN]          The y1 of bound box
 *  bx2     : [IN]          The x2 of bound box
 *  by2     : [IN]          The y2 of bound box
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_clip_with_bounding_box) (S32 x1, S32 y1, S32 x2, S32 y2, S32 bx1, S32 by1, S32 bx2, S32 by2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_get_clip
 * DESCRIPTION
 *  Get the active layer's clip
 * PARAMETERS
 *  x1      : [IN]          The pointer to store the x1 of clip area
 *  y1      : [IN]          The pointer to store the y1 of clip area
 *  x2      : [IN]          The pointer to store the x2 of clip area
 *  y2      : [IN]          The pointer to store the y2 of clip area
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_get_clip) (S32 *x1, S32 *y1, S32 *x2, S32 *y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_clip_preset
 * DESCRIPTION
 *  Set the clip interset with preset clip
 * PARAMETERS
 *  x1      : [IN]          The x1 of clip area
 *  y1      : [IN]          The y1 of clip area
 *  x2      : [IN]          The x2 of clip area
 *  y2      : [IN]          The y2 of clip area
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_clip_preset) (S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_reset_clip
 * DESCRIPTION
 *  Reset the active layer's clip.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_reset_clip) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_push_text_clip
 * DESCRIPTION
 *  Push the active layer's clip into stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_push_text_clip) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_pop_text_clip
 * DESCRIPTION
 *  Pop active layer's clip for stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_pop_text_clip) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_push_clip
 * DESCRIPTION
 *  Push the active layer's clip into stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_push_clip) (void);

/*----------------------------------------------------------------------------
Function Pointer: gui_push_and_set_clip
Description:      Saves the graphics clipping boundary and set clip of active layer
Input Parameters: none
Output Parameters:   none
Returns:       void
Remarks:       Currently not a stack type implementation
----------------------------------------------------------------------------*/

extern void (*gui_push_and_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2);

/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_pop_clip
 * DESCRIPTION
 *  Pop the active layer's clip from stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_pop_clip) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_reset_text_clip
 * DESCRIPTION
 *  Reset active layer's clip
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_reset_text_clip) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_line_height
 * DESCRIPTION
 *  Set the text's line height
 * PARAMETERS
 *  height      : [IN]          The new line height of text
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_line_height) (S32 height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_move_text_cursor
 * DESCRIPTION
 *  Move the text cursor
 * PARAMETERS
 *  x      : [IN]           The new x coordinate of text cursor
 *  y      : [IN]           The new y coordinate of text cursor
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_move_text_cursor) (S32 x, S32 y);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_text_color
 * DESCRIPTION
 *  Set the color of text
 * PARAMETERS 
 *  c       : [IN]          The color of text
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_text_color) (color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_text_border_color
 * DESCRIPTION
 *  Set the border color of text
 * PARAMETERS
 *  c       : [IN]          The color of text's border
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_text_border_color) (color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_get_text_color
 * DESCRIPTION
 *  Get the text's color
 * PARAMETERS
 *  void  
 * RETURNS
 *  The color of text
 *****************************************************************************/
extern color (*gui_get_text_color) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_get_text_border_color
 * DESCRIPTION
 *  Get the border color of text
 * PARAMETERS
 *  void        
 * RETURNS
 *  The color of text's border
 *****************************************************************************/
extern color (*gui_get_text_border_color) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_printf
 * DESCRIPTION
 *  Output some string in format, this function is same as c-function printf
 * PARAMETERS
 *  format      : [IN]          The format of string
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 (*gui_printf) (const S8 *format, ...);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_sprintf
 * DESCRIPTION
 *  Output some string in format into a given buffer
 * PARAMETERS
 *  _text       : [OUT]         The buffer to store the result
 *  format      : [IN]          The format of string
 * RETURNS
 *  void
 *****************************************************************************/
extern S32(*gui_sprintf) (UI_string_type _text, const S8 *format, ...);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_text
 * DESCRIPTION
 *  Print some string into LCD
 * PARAMETERS
 *  _text      : [IN]        The text want to be print out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_text) (UI_string_type _text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_text_n
 * DESCRIPTION
 *  Print some string into LCD with above limition
 * PARAMETERS
 *  _text       : [IN]          The text want to be print out
 *  n           : [IN]          The max count of char that will be print out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_text_n) (UI_string_type _text, int _n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_bordered_text_n
 * DESCRIPTION
 *  Print some string with border into LCD with above limition
 * PARAMETERS
 *  _text       : [IN]          The text want to be print out
 *  n           : [IN]          The max count of char that will be print out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_bordered_text_n) (UI_string_type _text, int _n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_bordered_text
 * DESCRIPTION
 *  Print some string with border into LCD
 * PARAMETERS
 *  _text      : [IN]           The text want to be print out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_bordered_text) (UI_string_type _text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_character
 * DESCRIPTION
 *  Print out a character into LCD
 * PARAMETERS       
 *  c       : [IN]          The char that will be print out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_character) (UI_character_type _c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_character_at_xy
 * DESCRIPTION
 *  Print out a character at a given point
 * PARAMETERS
 *  c      : [IN]           The char that will be print out
 *  x      : [IN]           The x coordinate of point
 *  y      : [IN]           The y coordinate of point
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_character_at_xy) (UI_character_type c, S32 x, S32 y);

                                                     
/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_bordered_character
 * DESCRIPTION
 *  Print out a character with border
 * PARAMETERS
 *  c       : [IN]        The char that will be print out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_print_bordered_character) (UI_character_type _c);



/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_truncated_text2
 * DESCRIPTION
 *  Displays truncated text (Does not display ...)
 * PARAMETERS
 *  x           : [IN]        Top left corner of text display
 *  y           : [IN]        Top left corner of text display
 *  xwidth      : [IN]        Width (in pixels) available for text display
 *  s           : [IN]         Text to be displayed
 * RETURNS
 *  Non-zero if the complete string was displayed
 *  zero if the complete string could not be displayed
 *****************************************************************************/
extern U8 gui_print_truncated_text2(S32 x, S32 y, S32 xwidth, UI_string_type *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_truncated_bordered_text2
 * DESCRIPTION
 *  Displays truncated bordered text (Does not display ...)
 * PARAMETERS
 *  x           : [IN]        Top left corner of text display
 *  y           : [IN]        Top left corner of text display
 *  xwidth      : [IN]        Width (in pixels) available for text display
 *  s           : [IN]        Text to be displayed
 * RETURNS
 *  Non-zero if the complete string was displayed
 *  zero if the complete string could not be displayed
 *****************************************************************************/
extern U8 gui_print_truncated_bordered_text2(S32 x, S32 y, S32 xwidth, UI_string_type *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_malloc
 * DESCRIPTION
 *  Malloc a give size memory
 * PARAMETERS
 *  size       : [IN]           The size of memory want to get
 * RETURNS
 *  void
 *****************************************************************************/
extern void *(*gui_malloc) (size_t size);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_free
 * DESCRIPTION
 *  Free the memory
 * PARAMETERS
 *  ptr       : [IN]            The pointer of memory
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_free) (void *ptr);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_character_width
 * DESCRIPTION
 *  Get a character's width
 * PARAMETERS
 *  c       : [IN]          The char that will be measure
 * RETURNS
 *  The width of character
 *****************************************************************************/
extern S32(*gui_get_character_width) (UI_character_type c);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_measure_character
 * DESCRIPTION
 *  Get a character's width and height
 * PARAMETERS
 *  c       : [IN]          The char that will be measure
 *  width   : [OUT]         The pointer to store the width of char
 *  height  : [OUT]         The pointer to store the height of char
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_measure_character) (UI_character_type c, S32 *width, S32 *height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_character_height
 * DESCRIPTION
 *  Get the char of height
 * PARAMETERS
 *  void       
 * RETURNS
 *  The height of char
 *****************************************************************************/
extern S32 (*gui_get_character_height) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text       : [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern S32(*gui_get_string_width) (UI_string_type text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_string_width_n
 * DESCRIPTION
 *  Get the string's width
 * PARAMETERS
 *  text        : [IN]       The text that will be measure
 *  n           : [IN]       The number of text   
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 (*gui_get_string_width_n) (UI_string_type text, S32 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_string_width_w
 * DESCRIPTION
 *  Get the string's width with give gap
 * PARAMETERS
 *  text       : [IN]           The text that will be measure
 *  w          : [IN]           The gap between char 
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 (*gui_get_string_width_w) (UI_string_type text, S32 w);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_string_width_wn
 * DESCRIPTION
 *  Get the string's width with give gap and number
 * PARAMETERS
 *  text       : [IN]           The text that will be measure
 *  w          : [IN]           The gap between char
 *  n          : [IN]           The number of string
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 (*gui_get_string_width_wn) (UI_string_type text, S32 w, S32 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_string_height
 * DESCRIPTION
 *  Get the string's height
 * PARAMETERS
 *  text       : [IN]       The text that will be measure   
 * RETURNS
 *  The height of text
 *****************************************************************************/
extern S32 (*gui_get_string_height) (UI_string_type text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_measure_string
 * DESCRIPTION
 *  Get the string's width and height
 * PARAMETERS
 *  text        : [IN]              The text that will be measure
 *  width       : [OUT]             The pointer to store the width of string
 *  height      : [OUT]             The pointer to store the height of string
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_measure_string) (UI_string_type text, S32 *width, S32 *height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_measure_string_n
 * DESCRIPTION
 *  Get the string's width and height with given the number of char
 * PARAMETERS
 *  text        : [IN]          The text that will be measure
 *  n           : [IN]          The number of char
 *  width       : [OUT]         The pointer to store the width of string 
 *  height      : [OUT]         The pointer to store the height of string
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_measure_string_n) (UI_string_type text, S32 n, S32 *width, S32 *height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_measure_string_w
 * DESCRIPTION
 *  Get the string's width and height with given gap between chars
 * PARAMETERS
 *  text       : [IN]           The text that will be measure
 *  w          : [IN]           The gap between char
 *  width      : [OUT]          The pointer to store the width of string
 *  height     : [OUT]          The pointer to store the height of string
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_measure_string_w) (UI_string_type text, S32 w, S32 *width, S32 *height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_measure_string_wn
 * DESCRIPTION
 *  Get the string's width and height with given gap and char count
 * PARAMETERS
 *  text       : [IN]           The text that will be measure
 *  w          : [IN]           The gap between char
 *  n          : [IN]           The count of char
 *  width      : [IN]           The pointer to store the width of string
 *  height     : [IN]           The pointer to store the height of string
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_measure_string_wn) (UI_string_type text, S32 w, S32 n, S32 *width, S32 *height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_set_font
 * DESCRIPTION
 *  Set the string's font
 * PARAMETERS
 *  f       : [IN]        The font of string to be set
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_set_font) (UI_font_type f);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_image
 * DESCRIPTION
 *  Show a image at a special position
 * PARAMETERS
 *  x       : [IN]          The x coordinate of position
 *  y       : [IN]          The y coordinate of position 
 *  i       : [IN]          The pointer of image will be shown
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_show_image) (S32 x, S32 y, PU8 i);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_transparent_image
 * DESCRIPTION
 *  Show a image at a special position, it same as gui_show_image
 * PARAMETERS
 *  x       : [IN]          The x cooridnate of position
 *  y       : [IN]          The y coordinate of position
 *  i       : [IN]          The pointer of image will be shown
 *  t       : [IN]          The transparent color
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_show_transparent_image) (S32 x, S32 y, PU8 i, UI_transparent_color_type t);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_measure_image
 * DESCRIPTION
 *  Get the image's width and height
 * PARAMETERS
 *  i       : [IN]          The pointer of image that will be measure
 *  width   : [IN]          The pointer to store the image's width
 *  height  : [IN]          The pointer to store the image's height
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_measure_image) (PU8 i, S32 *width, S32 *height);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_image_n_frames
 * DESCRIPTION
 *  Get the image's frame number
 * PARAMETERS
 *  i       : [IN]          The pointer of image that will be measure
 * RETURNS
 *  The image's frame count
 *****************************************************************************/
extern S32 (*gui_image_n_frames) (PU8 i);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_start_timer
 * DESCRIPTION
 *  Start a UI timer with give cycle time and callback
 * PARAMETERS
 *  count       : [IN]          The cycle time of timer, the unit is ms
 *  callback    : [IN]          The callback will be invoke when the time out
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_start_timer) (S32 count, void (*callback) (void));


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_start_timer_ex
 * DESCRIPTION
 *  Start a UI timer with give cycle time and callback, the callback with parameter
 * PARAMETERS
 *  count       : [IN]          The cycle time of timer, the unit is ms
 *  callback    : [IN]          The callback will be invoke when the time out
 *  arg         : [IN]          The parameter of callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_start_timer_ex) (S32 count, void (*callback)(void *arg), void *arg);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_cancel_timer
 * DESCRIPTION
 *  Cancel a UI timer
 * PARAMETERS
 *  callback       : [IN]           The callback of timer
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_cancel_timer) (void (*callback) (void));


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_hide_animated_image
 * DESCRIPTION
 *  Hide a animated image
 * PARAMETERS
 *  x       : [IN]          The x coordinate of image
 *  y       : [IN]          The y coordinate of image 
 *  i       : [IN]          The handler of animated image
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_hide_animated_image) (S32 x, S32 y, UI_animated_image_handle i);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_register_hide_animation_frame
 * DESCRIPTION
 *  Register a callback to hide animation frame
 * PARAMETERS
 *  i       : [IN]          The handler of animation image
 *  f       : [IN]          The callback of hide animation frame
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_register_hide_animation_frame) (UI_animated_image_handle i,
                                                  void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
                                                  

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_transparent_animated_image_frame
 * DESCRIPTION
 *  Show a animated image
 * PARAMETERS
 *  x       : [IN]          The x coordinate of image will be shown
 *  y       : [IN]          The y coordinate of image will be shown
 *  i       : [IN]          The pointer of image that will be shown
 *  t       : [IN]          The color of transparent
 *  frame_number    : [IN]  The index of frame that will be shown
 * RETURNS
 *  void
 *****************************************************************************/                                                  
extern U8(*gui_show_transparent_animated_image_frame) (S32 x, S32 y, PU8 i, UI_transparent_color_type t,
                                                       S16 frame_number);
                                                       
                                                       
/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_animated_image_frame
 * DESCRIPTION
 *  Show a animated image's single frame
 * PARAMETERS
 *  x       : [IN]          The x coordinate of image 
 *  y       : [IN]          The y coordinate of image 
 *  i       : [IN]          The pointer of image 
 *  frame_number    : [IN]  The index of frame that will be shown
 * RETURNS
 *  void
 *****************************************************************************/                                                       
extern U8(*gui_show_animated_image_frame) (S32 x, S32 y, PU8 i, S16 frame_number);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_hide_animations
 * DESCRIPTION
 *  Hide all animations
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_hide_animations) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_show_transparent_animated_image_frames
 * DESCRIPTION
 *  Show a animated image's mutil frame
 * PARAMETERS
 *  x       : [IN]          The x coordinate of image 
 *  y       : [IN]          The y coordinate of image
 *  t       : [IN]          The color of transparent
 *  start_frame     : [IN]  The index of start frame
 *  end_frame       : [IN]  The index of end frame
 * RETURNS
 *  void
 *****************************************************************************/
extern UI_animated_image_handle (*gui_show_transparent_animated_image_frames) (S32 x, S32 y, PU8 i,
                                                                              UI_transparent_color_type t,
                                                                              S16 start_frame, S16 end_frame);

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_transparent_color
 * DESCRIPTION
 *  Convert a color from RGB to color struct
 * PARAMETERS
 *  r       : [IN]        The value of red
 *  g       : [IN]        The value of green
 *  b       : [IN]        The value of blue
 * RETURNS
 *  The color
 *****************************************************************************/
extern UI_transparent_color_type(*gui_transparent_color) (U8 r, U8 g, U8 b);


/************************************************************* ****************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_color
 * DESCRIPTION
 *  Convert a color from RGB to color struct
 * PARAMETERS
 *  r       : [IN]        The value of red
 *  g       : [IN]        The value of green
 *  b       : [IN]        The value of blue
 * RETURNS
 *  The color
 *****************************************************************************/
extern color(*gui_color) (U8 r, U8 g, U8 b);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_color32
 * DESCRIPTION
 *  Convert a color from ARGB to color struct
 * PARAMETERS
 *  r       : [IN]        The value of red
 *  g       : [IN]        The value of green
 *  b       : [IN]        The value of blue
 *  alpha   : [IN]        The value of alpha
 * RETURNS
 *  The color
 *****************************************************************************/
extern color(*gui_color32) (U8 r, U8 g, U8 b, U8 alpha);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_color_RGB
 * DESCRIPTION
 *  Convert a color to RGB
 * PARAMETERS
 *  c       : [IN]          The color that will be convert
 *  r       : [IN]          The pointer to store the color's red value
 *  g       : [IN]          The pointer to store the color's green value
 *  b       : [IN]          The pointer to store the color's blue value
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_color_RGB) (color c, U8 *r, U8 *g, U8 *b);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_strcpy
 * DESCRIPTION
 *  Copy a string from source to desitination
 * PARAMETERS
 *  text1       : [IN]        The src string
 *  text2       : [IN]        The des string
 * RETURNS
 *  void
 *****************************************************************************/
extern UI_string_type(*gui_strcpy) (UI_string_type text1, UI_string_type text2);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_strncpy
 * DESCRIPTION
 *  Copy a string from source to desitination with above limition
 * PARAMETERS
 *  text1       : [IN]          The src string 
 *  text2       : [IN]          The des string
 *  n           : [IN]          The max number of char will be copy
 * RETURNS
 *  void
 *****************************************************************************/
extern UI_string_type(*gui_strncpy) (UI_string_type text1, UI_string_type text2, S32 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_strcmp
 * DESCRIPTION
 *  Compare two string is equal or not
 * PARAMETERS
 *  text1       : [IN]          The first string 
 *  text2       : [IN]          The second string
 * RETURNS
 *  The compare result of two string
 *****************************************************************************/
extern S32 (*gui_strcmp) (UI_string_type text1, UI_string_type text2);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_strlen
 * DESCRIPTION
 *  Get the string's length
 * PARAMETERS
 *  text       : [IN]           The string that will be measure
 * RETURNS
 *  The length of string
 *****************************************************************************/
extern S32(*gui_strlen) (UI_string_type text);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_strncmp
 * DESCRIPTION
 *  Compare two string with given above limition
 * PARAMETERS
 *  text1       : [IN]          The first string
 *  text2       : [IN]          The second string
 *  n           : [IN]          The max number of compare char
 * RETURNS
 *  void
 *****************************************************************************/
extern S32(*gui_strncmp) (UI_string_type text1, UI_string_type text2, S32 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_strcat
 * DESCRIPTION
 *  Contact two string 
 * PARAMETERS
 *  text1       : [IN]           The first string
 *  text2       : [IN]           The second string
 * RETURNS
 *  The result of contact
 *****************************************************************************/
extern UI_string_type(*gui_strcat) (UI_string_type text1, UI_string_type text2);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_itoa
 * DESCRIPTION
 *  Convert a natural number into a string
 * PARAMETERS
 *  value       : [IN]          The natural number
 *  s           : [OUT]         The buffer to store the string
 *  radix       : [IN]          The radix of value
 * RETURNS
 *  The pointer to store the string
 *****************************************************************************/
extern WCHAR *(*gui_itoa) (S32 value, WCHAR * s, U32 radix);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_atoi
 * DESCRIPTION
 *  Convert a string to a natural number
 * PARAMETERS
 *  s       : [IN]           The string that will be convert
 * RETURNS
 *  The natural value
 *****************************************************************************/
extern S32(*gui_atoi) (UI_string_type s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_memcpy
 * DESCRIPTION
 *  Copy memory from source to desitination
 * PARAMETERS
 *  d       : [OUT]         The desitination memory pointer
 *  s       : [IN]          The source memory pointer
 *  n       : [IN]          The size of memory will be copy
 * RETURNS
 *  void
 *****************************************************************************/
extern void* (*gui_memcpy) (void *d, const void *s, S32 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_misc>
 * FUNCTION
 *  gui_get_next_character
 * DESCRIPTION
 *  Get the next character form a string
 * PARAMETERS
 *  s       : [IN]          The string
 * RETURNS
 *  The next character
 *****************************************************************************/
extern UI_character_type(*gui_get_next_character) (UI_string_type *s);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_get_previous_character
 * DESCRIPTION
 *  Get the previous character form a string
 * PARAMETERS
 *  s       : [IN]          The string
 * RETURNS
 *  The previous character
 *****************************************************************************/
extern UI_character_type(*gui_get_previous_character) (UI_string_type *s);

/* Double buffer */

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_BLT_double_buffer
 * DESCRIPTION
 *  Blt gdi layer to LCD, it is same as gdi_layer_blt_previous
 * PARAMETERS
 *  x1       : [IN]         The x1 of blt range
 *  y1       : [IN]         The y1 of blt range
 *  x2       : [IN]         The x2 of blt range 
 *  y2       : [IN]         The y2 of blt range
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_BLT_double_buffer) (S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_lock_double_buffer
 * DESCRIPTION
 *  Lock the gdi layer buffer, so that,blt operator won't blt the result into LCD
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_lock_double_buffer) (void);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_unlock_double_buffer
 * DESCRIPTION
 *  Unlock the gdi layer buffer, this function should be used with gui_lock_double_buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
extern void (*gui_unlock_double_buffer) (void);

/* Layout */


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_setup_default_layout
 * DESCRIPTION
 *  Setup UI layout context to "Default Layout"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_setup_default_layout(void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_setup_common_layout
 * DESCRIPTION
 *  Setup UI layout context to "Common Layout"
 *
 *  The major differences between "Default Layout" and "Common Layout" is that
 *  category screens using "Common Layout" need to call gui_setup_common_layout()
 *  explicitly, but "Default Layout" does not. 
 *
 *  "Common Layout" is used for category screens which can be customized for 
 *  layout other than PlutoMMI's default.
 *
 *  "Default Layout" is used for category screens which always use PlutoMMI's default
 *  because it may be difficult to be scalable. (e.g. need to change images)
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_setup_common_layout(void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_setup_mainmenu_layout
 * DESCRIPTION
 *  Setup UI layout context to "Main Menu Layout"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_setup_mainmenu_layout(void);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_setup_submenu_layout
 * DESCRIPTION
 *  Setup UI layout context to "Sub Menu Layout"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_setup_submenu_layout(void);

/* <group dom_utility_variables>
 *  Right-to-left flag */
extern BOOL r2lMMIFlag;

/* Some standard functions: Need to be implemented through wrappers.    */
/* See the character set support functions, gui_get_next_character   */
/* and gui_get_previous_character                           */



/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_linebreak_character
 * DESCRIPTION
 *  Returns true if a given character is a line break character
 * PARAMETERS
 *  c       : [IN]        Character to be tested
 * RETURNS
 *  true  if c is a line break character
 *  false if c is not a line break character
 *****************************************************************************/
extern U8 gui_linebreak_character(UI_character_type c);


/*****************************************************************************
 * <group dom_utility_gui_layer_misc>
 * FUNCTION
 *  gui_endofstring_character
 * DESCRIPTION
 *  Returns true if a given character is an end of string character
 * PARAMETERS
 *  c       : [IN]        Character to be tested
 * RETURNS
 *  true  if c is an end of string character
 *  false if c is not an end of string character
 *  See UI_character_type (Abstract type)
 *****************************************************************************/
extern U8 gui_endofstring_character(UI_character_type c);



/*****************************************************************************
 * <group dom_utility_gui_layer_misc>
 * FUNCTION
 *  gui_blend_two_color
 * DESCRIPTION
 *  Blend two color together.
 * PARAMETERS
 *  c1          : [IN]        Color 1
 *  c2          : [IN]        Color 2
 *  weight1     : [IN]        Weighting of color 1
 *  weight2     : [IN]        Weighting of color 2
 * RETURNS
 *  blended color
 *****************************************************************************/
extern color gui_blend_two_color(color c1, color c2, S32 weight1, S32 weight2);

#define  UI_GRADIENT_COLOR_VERTICAL          0x00000100
#define  UI_GRADIENT_COLOR_HORIZONTAL        0x00000000
#define UI_GRADIENT_COLOR_FLIP               0x00000200

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_initialize_gradient_color
 * DESCRIPTION
 *  Creates a gradient color
 *  
 *  Note: gc must be allocated before calling this function.
 * PARAMETERS
 *  gc      : [OUT]       Is the gradient color      (pre-allocated)
 *  c       : [IN]        Is an array of colors      (n    elements)
 *  p       : [IN]        Is an array of percentages (n-1  elements)
 *  n       : [IN]        Is the number of colors
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_initialize_gradient_color(gradient_color *gc, color *c, U8 *p, U8 n);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_gradient_fill_rectangle
 * DESCRIPTION
 *  Gradient color fills a rectangle
 * PARAMETERS
 *  x1           : [IN]        Left-top corner of the rectangle
 *  y1           : [IN]        Left-top corner of the rectangle
 *  x2           : [IN]        Right-bottom corner of the rectangle
 *  y2           : [IN]        Right-bottom corner of the rectangle
 *  gc           : [IN]        Is the gradient color
 *  flags        : [IN]        Can have the following values:
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_gradient_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, gradient_color *gc, U32 flags);

/* <group dom_utility_struct>
 *  Filled Area border theme                  */
    typedef struct _UI_filled_area_border_theme
    {
        color filled_area_outer_light_border;
        color filled_area_inner_light_border;
        color filled_area_outer_dark_border;
        color filled_area_inner_dark_border;
    } UI_filled_area_border_theme;

    extern UI_filled_area_border_theme *current_filled_area_border_theme;

    /*
     * UI filled area structure
     * -------------------
     * bits 0-7:         filler types
     * bit    8:            1=vertical filler, 0=horizontal filler (used for gradients and textures)
     * bit  9:           flip filler
     * bit    10:        (reserved)
     * bit  11:       (reserved)
     * bit    12:        border yes/no
     * bit  13:       border size 0=single line, 1=double line
     * bit  14:       3D border
     * bit  15:       rounded border
     * bit    16:        1=elevated border, 0=depressed border
     * bit    17:        1=filled area with shadow
     * bit  18:            1=filled area with double line shadow, 0=single line shadow
     * bit  19:       (reserved)
     * bit  20:       left rounded border
     * bit  21:       right rounded border
     * bit  22:       Draw only horizontal lines in borders
     * bit  24:       transparent color
     */

/* <group dom_utility_macro>
 *  Bits 0-7: filler type */
#define UI_FILLED_AREA_MASK_TYPE                            0x000000FF
/* <group dom_utility_macro>
 *  --- */
#define UI_FILLED_AREA_TYPE_COLOR                           0x00000000
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_GRADIENT_COLOR                  0x00000001
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_TEXTURE                         0x00000002
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_BITMAP                          0x00000003
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_HATCH_COLOR                     0x00000004
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR           0x00000005
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_CROSS_HATCH_COLOR               0x00000006
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_ALTERNATE_CROSS_HATCH_COLOR     0x00000007
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_NO_BACKGROUND                   0x00000008
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1               0x00000009  
/* <group dom_utility_macro>
 *  Popup description 1 */
#define UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE2               0x0000000A  
/* <group dom_utility_macro>
 *  Popup description 2 */
#define UI_FILLED_AREA_TYPE_3D_BORDER                       0x0000000B
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_IMAGE_RIGHT_ALIGN               0x0000000C
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_TYPE_IMAGE_LEFT_ALIGN                0x0000000D

/* <group dom_utility_macro>
 *  Bit 8: horiztonal or vertical fill for gradient color */
#define UI_FILLED_AREA_MASK_FILL_DIRECTION                  0x00000100
/* <group dom_utility_macro>
 *  --- */
#define UI_FILLED_AREA_HORIZONTAL_FILL                      0x00000000
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_VERTICAL_FILL                        0x00000100

/* <group dom_utility_macro>
 *  Bit 9: flip fill or not */
#define UI_FILLED_AREA_FLIP_FILL                            0x00000200

/* <group dom_utility_macro>
 *  Bits 12-13: single-double-border */
#define UI_FILLED_AREA_MASK_BORDER_WIDTH                    0x00003000
/* <group dom_utility_macro>
 *  --- */
#define UI_FILLED_AREA_TYPE_NO_BORDER                       0x00000000
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_BORDER                               0x00001000
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_SINGLE_BORDER                        0x00001000  
/* <group dom_utility_macro>
 *  Contain UI_FILLED_AREA_BORDER */
#define UI_FILLED_AREA_DOUBLE_BORDER                        0x00003000  /* Contain UI_FILLED_AREA_BORDER */

/* <group dom_utility_macro>
 *  Bits 14: 3D border */
#define UI_FILLED_AREA_3D_BORDER                            0x00004000

/* <group dom_utility_macro>
 *  Bits 15: Rounded border */
#define UI_FILLED_AREA_ROUNDED_BORDER                       0x00008000

/* <group dom_utility_macro>
 *  Bits 16: Elevated or depressed border */
#define UI_FILLED_AREA_MASK_ELEVATION                       0x00010000
/* <group dom_utility_macro>
 *  --- */
#define UI_FILLED_AREA_ELEVATED_BORDER                      0x00010000
/* <group dom_utility_macro>  */
#define UI_FILLED_AREA_DEPRESSED_BORDER                     0x00000000

/* <group dom_utility_macro>
 *  Combination of Bit 14 and 16 */
#define UI_FILLED_AREA_3D_ELEVATED_BORDER                   (UI_FILLED_AREA_ELEVATED_BORDER | UI_FILLED_AREA_3D_BORDER)
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_3D_DEPRESSED_BORDER                  (UI_FILLED_AREA_DEPRESSED_BORDER | UI_FILLED_AREA_3D_BORDER)

/* <group dom_utility_macro>
 *  Bits 17-18: single-double-shadown */
#define UI_FILLED_AREA_MASK_SHADOW                          0x00060000
/* <group dom_utility_macro>
 *  --- */
#define UI_FILLED_AREA_SHADOW                               0x00020000
/* <group dom_utility_macro> */
#define UI_FILLED_AREA_SHADOW_DOUBLE_LINE                   0x00040000

/* <group dom_utility_macro>
 *  Bit 20: Left rounded border for Dalmatian style */
#define UI_FILLED_AREA_LEFT_ROUNDED_BORDER                  0x00100000

/* <group dom_utility_macro>
 *  Bit 21: Right rounded border for Dalmatian style */
#define UI_FILLED_AREA_RIGHT_ROUNDED_BORDER                 0x00200000
/* <group dom_utility_macro>
 * Bit 22: Draw only horizontal lines w/o vertical lines in UI_FILLED_AREA_BORDER */
#define UI_FILLED_AREA_NO_VERTICAL_LINE                     0x00400000

/* <group dom_utility_macro>
 *  Bit 24: Transparent color filler */
#define UI_FILLED_AREA_TYPE_TRANSPARENT_COLOR               0x01000000

/* <group dom_utility_macro>
 *  Bits 15: Rounded border */
#define UI_FILLED_AREA_LEFT_RIGHT_ROUNDED_BORDER            0x02000000

    extern UI_filled_area *current_UI_filler;

    //PMT VIKAS START 20050520
    //PMT VIKAS START 20051217
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined(__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__) || defined (UI_SCROLLBAR_STYLE_4) || defined(UI_SCROLLBAR_STYLE_6)      /* 072505 Calvin modified */
    /* PMT VIKAS END 20051217 */
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_fill_transparent_color
 * DESCRIPTION
 *  Fill the transparent color rectangle
 * PARAMETERS
 *  x1              : [IN]        The x1 of draw area
 *  y1              : [IN]        The y1 of draw area
 *  x2              : [IN]        The x2 of draw area
 *  y2              : [IN]        The y2 of draw area
 *  c               : [IN]        The color to be used to fill draw area
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_fill_transparent_color(S32 x1, S32 y1, S32 x2, S32 y2, color c);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_transparent_color_filler
 * DESCRIPTION
 *  Choose the color filler
 * PARAMETERS
 *  x1              : [IN]        The x1 of draw area
 *  y1              : [IN]        The y1 of draw area
 *  x2              : [IN]        The x2 of draw area
 *  y2              : [IN]        The y2 of draw area
 *  c               : [IN]        The color to be used to fill draw area
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_transparent_color_filler(S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_set_transparent_source_layer
 * DESCRIPTION
 *  Set transparent source layer
 * PARAMETERS
 *  layer       : [IN]        The handle of new transparent source layer
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_transparent_source_layer(gdi_handle layer);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_get_transparent_source_layer
 * DESCRIPTION
 *  Get transparent source layer
 * PARAMETERS
 *  void
 * RETURNS
 *  The layer handler of transparent source layer
 *****************************************************************************/
extern gdi_handle gui_get_transparent_source_layer(void);   /* 110705 WAP menu Clavin add */
    

/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_reset_transparent_source_layer
 * DESCRIPTION
 *  Reset transparent source layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_reset_transparent_source_layer(void);

    /* PMT VIKAS START 20050630 */
    

/*****************************************************************************
 * <group dom_utility_gui_layer_property_setting>
 * FUNCTION
 *  gui_is_current_transparency_with_multi_layer
 * DESCRIPTION
 *  This function returns if multilayer is enabled in transparency effect
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
extern S32 gui_is_current_transparency_with_multi_layer(void);
    /* PMT VIKAS END 20050630 */
#endif /* defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined(__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__) || defined (UI_SCROLLBAR_STYLE_4) */ 
    //PMT VIKAS END
    //PMT VIKAS START 20050707
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_fill_left_rounded_border
 * DESCRIPTION
 *  Draws a filled area with left rounded border shape
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  rx1     : [IN]        Left-top corner of the rectangle
 *  ry1     : [IN]        Left-top corner of the rectangle
 *  rx2     : [IN]        Right-bottom corner of the rectangle
 *  ry2     : [IN]        Right-bottom corner of the rectangle
 *  f       : [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_fill_left_rounded_border(S32 rx1, S32 ry1, S32 rx2, S32 ry2, UI_filled_area *f);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_fill_right_rounded_border
 * DESCRIPTION
 *  Draws a filled area with right rounded border shape
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  rx1     : [IN]        Left-top corner of the rectangle
 *  ry1     : [IN]        Left-top corner of the rectangle
 *  rx2     : [IN]        Right-bottom corner of the rectangle
 *  ry2     : [IN]        Right-bottom corner of the rectangle
 *  f       : [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_fill_right_rounded_border(S32 rx1, S32 ry1, S32 rx2, S32 ry2, UI_filled_area *f);
    /* PMT VIKAS END 20050707 */
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_shadow_filled_area
 * DESCRIPTION
 *  Draws a shadow for a filled area
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  x1      : [IN]        Left-top corner of the rectangle
 *  y1      : [IN]        Left-top corner of the rectangle
 *  x2      : [IN]        Right-bottom corner of the rectangle
 *  y2      : [IN]        Right-bottom corner of the rectangle
 *  f       : [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_shadow_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_filled_area
 * DESCRIPTION
 *  Draws a filled area
 *  
 *  See fillers (UI_filled_area structure)
 * PARAMETERS
 *  x1      : [IN]        Left-top corner of the rectangle
 *  y1      : [IN]        Left-top corner of the rectangle
 *  x2      : [IN]        Right-bottom corner of the rectangle
 *  y2      : [IN]        Right-bottom corner of the rectangle
 *  f       : [IN]        Is the filler to use
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_draw_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
    /* void gui_greyscale_rectangle(S32 x1,S32 y1,S32 x2,S32 y2, S32 white_value); */
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_greyscale_rectangle
 * DESCRIPTION
 *  Greyscale the assigned region
 * PARAMETERS
 *  x1              : [IN]        Left-top corner of the rectangle
 *  y1              : [IN]        Left-top corner of the rectangle
 *  x2              : [IN]        Right-bottom corner of the rectangle
 *  y2              : [IN]        Right-bottom corner of the rectangle
 *  white_value     : [IN]        0~255 change the gamma value of the region
 *  black_value     : [IN]        0~255 change the darkness of the region
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_greyscale_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, S32 white_value, S32 black_value);      /* 102605 greyscale Calvin chnaged */

    /* PMT HIMANSHU START 20050916 */

    typedef enum
    {
        MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_LEFT = 0,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_RIGHT,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_LEFT,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_RIGHT
    } mmi_gradient_rect_rounded_corner_style_enum;

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_rounded_corner
 * DESCRIPTION
 *  This function will draw the gradient rounded corner of the rectangle
 * PARAMETERS
 *  x1                      : [IN]        X coordinate of corner.
 *  y1                      : [IN]        Y coordinate of corner.
 *  size                    : [IN]        radio of rounded corner.
 *  rect_color_start        : [IN]        It specifies the outermost start color of the border.
 *  rect_color_end          : [IN]        It specifies the innermost end color of the border.
 *  level                   : [IN]        Levels of different colors
 *  corner_style            : [IN]        It specifies the corner of the rectangle.
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_draw_rounded_corner(
                S32 x1,
                S32 y1,
                S32 size,
                color rect_color_start,
                color rect_color_end,
                S32 levle,
                mmi_gradient_rect_rounded_corner_style_enum corner_style);

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_gradient_rounded_rectangle
 * DESCRIPTION
 *  This function is used to draw the rounded rectangle with gradient border.
 * PARAMETERS
 *  x1                  : [IN]        Left-top coordinate of the rectangle.
 *  y1                  : [IN]        Left-top coordinate of the rectangle.
 *  x2                  : [IN]        Bottom-right coordinate of the rectangle.
 *  y2                  : [IN]        Bottom-right coordinate of the rectangle.
 *  start_color         : [IN]        It specifies the outermost start color of the border.
 *  end_color           : [IN]        It specifies the innermost end color of the border.
 *  border_width        : [IN]        It specifies the width of the border.
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_draw_gradient_rounded_rectangle(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                color start_color,
                color end_color,
                S32 border_width);

    /* PMT HIMANSHU END 20050916 */
   /* <group dom_utility_struct> */
    typedef struct _UI_HLS_color
    {
        /* Hue */
        U16 h;  /* 0-360 */
        /* Lightness */
        U8 l;   /* 0-255 */
        /* Saturation */
        U8 s;   /* 0-255 */
    } UI_HLS_color;
    

/*****************************************************************************
 * <group dom_utility_gui_layer_misc>
 * FUNCTION
 *  gui_RGB_to_HLS
 * DESCRIPTION
 *  Convert RGB color to HLS color
 * PARAMETERS
 *  rgb     : [IN]        The RGB color value
 *  hls     : [OUT]       The HLS color value  
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_RGB_to_HLS(color rgb, UI_HLS_color *hls);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_misc>
 * FUNCTION
 *  gui_HLS_to_RGB
 * DESCRIPTION
 *  Convert HLS color to RGB color
 * PARAMETERS
 *  hls     : [IN]          The HLS color value
 *  rgb     : [OUT]         The RGB color value
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_HLS_to_RGB(UI_HLS_color hls, color *rgb);

    /* UI object co-ordinates structure       */
    /* <group dom_utility_struct>  */
    typedef struct _UI_object_coordinates
    {
        S32 x;
        S32 y;
        S32 width;
        S32 height;
    } UI_object_coordinates;

    /* Dummy functions called by UI elements by default, during events
       Do not remove any of these functions.  */

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_dummy_function
 * DESCRIPTION
 *  Dummy functio with out parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_dummy_function(void);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_dummy_function_byte
 * DESCRIPTION
 *  Dummay function with byte parameter
 * PARAMETERS
 *  a       : [IN]        Unused parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_dummy_function_byte(U8 a);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_dummy_function_s32
 * DESCRIPTION
 *  Dummy function with s32 parameter
 * PARAMETERS
 *  a       : [IN]        Unused parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_dummy_function_s32(S32 a);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_dummy_function_character
 * DESCRIPTION
 *  Dummy function with text parameter
 * PARAMETERS
 *  c       : [IN]        Unused parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_dummy_function_character(UI_character_type c);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_set_main_LCD_graphics_context
 * DESCRIPTION
 *  Set mainlcd as active lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_set_main_LCD_graphics_context(void);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_set_sub_LCD_graphics_context
 * DESCRIPTION
 *  Set sublcd as active lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_set_sub_LCD_graphics_context(void);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_test_sub_LCD_graphics_context
 * DESCRIPTION
 *  To check active lcd is sublcd or not
 * PARAMETERS
 *  void
 * RETURNS
 *  1   :   The active lcd is sublcd 
 *  0   :   The active lcd isn't sublcd
 *****************************************************************************/
extern U8 UI_test_sub_LCD_graphics_context(void);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_truncated_text
 * DESCRIPTION
 *  Print truncated text with no border .
 *  
 *  If length of text is greater  than
 *  screen width then the text is truncated . Three dots are shown at end of text
 * PARAMETERS
 *  x           : [IN]        Start x positoin
 *  y           : [IN]        Start Y position
 *  xwidth      : [IN]        Width of text in pixels to display
 *  st          : [IN]        Text to display
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_print_truncated_text(S32 x, S32 y, S32 xwidth, UI_string_type s);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_truncated_borderd_text
 * DESCRIPTION
 *  Print truncated text border .
 *  
 *  If length of text is greater  than
 *  screen width then the text is truncated . Three dots are shown at end of text
 * PARAMETERS
 *  x           : [IN]        Start x positoin
 *  y           : [IN]        Start Y position
 *  xwidth      : [IN]        Width of text in pixels to display
 *  st          : [IN]        Text to display
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_print_truncated_borderd_text(S32 x, S32 y, S32 xwidth, UI_string_type s);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_truncated_text_ex
 * DESCRIPTION
 *  Print truncated text with no border .
 *  
 *  If length of text is greater  than
 *  screen width then the text is truncated . Three dots are shown at end of text
 * PARAMETERS
 *  x           : [IN]        Start x positoin
 *  y           : [IN]        Start Y position
 *  xwidth      : [IN]        Width of text in pixels to display
 *  st          : [IN]        Text to display
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_print_truncated_text_ex(S32 x, S32 y, S32 xwidth, UI_string_type st);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_text_by_direction
 * DESCRIPTION
 *  Print the text by forcing reading direction the same to r2lMMIFlag.
 * PARAMETERS
 *  str       : [IN]  Text to display
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_print_text_by_direction(UI_string_type str);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_print_bordered_text_by_direction
 * DESCRIPTION
 *  Print the bordered text by forcing reading direction the same to r2lMMIFlag.
 * PARAMETERS
 *  str       : [IN]  Text to display
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_print_bordered_text_by_direction(UI_string_type str);


    /* Common string macros */

#ifdef __ASCII
/*  <group dom_utility_macro> */
#define UI_STRING_GET_NEXT_CHARACTER(p,c)                                                 \
      {                                                                                   \
         (c)=*((U8*)(p))++;                                                               \
      }
/*  <group dom_utility_macro> */
#define UI_STRING_GET_PREVIOUS_CHARACTER(p,c)                                                \
      {                                                                                      \
         (c)=*(--((U8*)(p)));                                                                \
      }
/*  <group dom_utility_macro> */
#define UI_STRING_INSERT_CHARACTER(p,c)                                                      \
      {                                                                                      \
         *((U8*)(p))++=(c);                                                                  \
      }

#endif /* __ASCII */ 

#ifdef __UCS2_ENCODING

    /* Warning: Currently, these macros assume Little endian format only */
/*  <group dom_utility_macro> */
#define UI_STRING_GET_NEXT_CHARACTER(p,c)                                                    \
      {                                                                                      \
         c=(UI_character_type)((*((p)+0))|((*((p)+1))<<8));                                  \
         (p)+=2;                                                                             \
      }
/*  <group dom_utility_macro> */
#define UI_STRING_GET_PREVIOUS_CHARACTER(p,c)                                                \
      {                                                                                      \
         p-=2;                                                                               \
         c=(UI_character_type)((*((p)+0))|((*((p)+1))<<8));                                  \
      }
/*  <group dom_utility_macro> */
#define UI_STRING_INSERT_CHARACTER(p,c)                                                      \
      {                                                                                      \
         (*((p))++)=(U8)(((c)&0xff));                                                        \
         (*((p))++)=(U8)(((c)>>8));                                                          \
      }

#endif /* __UCS2_ENCODING */ 
/*  <group dom_utility_macro> */
#define UI_TEST_CR_CHARACTER1(c)              (((UI_character_type)(c)==(UI_character_type)0x0D)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_CR_CHARACTER(c)               (((*(UI_character_type*)&(c))==(UI_character_type)0x0D)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_LF_CHARACTER1(c)              (((UI_character_type)(c)==(UI_character_type)0x0A)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_LF_CHARACTER(c)               (((*(UI_character_type*)&(c))==(UI_character_type)0x0A || ((c) == 0x2029) || ((c) == 0x2028))?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_ESC_CHARACTER1(c)             (((UI_character_type)(c)==(UI_character_type)0x1B)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_ESC_CHARACTER(c)              (((*(UI_character_type*)&(c))==(UI_character_type)0x1B)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_SEMICOLON_CHAR(c)             (((UI_character_type)(c) == 0x003B || (UI_character_type)(c) == 0xff1b)?(1):(0))   /* check if the char is ';'*/

/*  <group dom_utility_macro> */
#define UI_STRING_LINE_BREAK_CHARACTER1(c)    (((UI_character_type)(c)==(UI_character_type)'\n')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_STRING_LINE_BREAK_CHARACTER(c)     (((*(UI_character_type*)&(c))==(UI_character_type)'\n' || ((c) == 0x2029) || ((c) == 0x2028))?(1):(0))                                                                             

/*  <group dom_utility_macro> */
#define UI_STRING_END_OF_STRING_CHARACTER1(c) (((UI_character_type)(c)==(UI_character_type)'\0')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_STRING_END_OF_STRING_CHARACTER(c)  (((*(UI_character_type*)&(c))==(UI_character_type)'\0')?(1):(0))

/*  <group dom_utility_macro> */
#define UI_STRING_SPACE_CHARACTER1(c)         (((UI_character_type)(c)==(UI_character_type)' ')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_STRING_SPACE_CHARACTER(c)          (((*(UI_character_type*)&(c))==(UI_character_type)' ')?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_ASCII_NOT_IN_GSM_DEF_CHAR(c) (((c)==96)?(1):(0))
/*  <group dom_utility_macro> */
#define UI_TEST_8895_1_CHAR_IN_GSM_DEF_CHAR(c)  (((c)==162 ||(c)==163 ||(c)==165 || (c)==232 ||(c)==233 ||(c)==249 ||(c)==236 ||(c)==242 ||(c)==199 ||(c)==216 ||(c)==248 ||(c)==197 ||(c)==229 ||(c)==198 ||(c)==230 ||(c)==223 ||(c)==201 ||(c)==164 ||(c)==161 ||(c)==196 ||(c)==214 ||(c)==209 ||(c)==220 ||(c)==167 ||(c)==191 ||(c)==228 ||(c)==246 ||(c)==241 ||(c)==252 ||(c)==224)?(1):(0))

/* #define UI_TEST_UCS2_CHARACTER(c)            (((((c)&0xff80) && ( !UI_TEST_8895_1_CHAR_IN_GSM_DEF_CHAR(c))) || UI_TEST_ASCII_NOT_IN_GSM_DEF_CHAR(c))?(1):(0)) */
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_CHARACTER(c)         ((c != 0) && !mmi_7bit_check_gsm_default(c) && !mmi_7bit_check_gsm_ext_character_default(c))
    
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_INCREMENT_COUNT(c,count)   if(UI_TEST_UCS2_CHARACTER(c)) ((count)++)
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_DECREMENT_COUNT(c,count)   if(UI_TEST_UCS2_CHARACTER(c) && ((count)>0)) ((count)--)
/*  <group dom_utility_macro> */
#define UI_TEST_ASCII_CHARACTER(c)        (((c) < 0x7f) ? (1) : (0))
/*  <group dom_utility_macro> */
#define UI_TEST_NON_ASCII_INCREMENT_COUNT(c,count)   if(!UI_TEST_ASCII_CHARACTER(c)) ((count)++)
/*  <group dom_utility_macro> */
#define UI_TEST_NON_ASCII_DECREMENT_COUNT(c,count)   if(!UI_TEST_ASCII_CHARACTER(c) && ((count)>0)) ((count)--)
/*  <group dom_utility_macro> */
#define UI_UCS2_STRING_HALF_LENGTH(x)        (((x)&3)?(((x)>>1)+1):((x)>>1))

/*  <group dom_utility_macro>
 *  For Phone Book Name Length */
    // #define UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(x)      (((x)&3)?(((x)>>1)-1):(((x)>>1)-2))
#define UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(x) (((x)&3)?(((x)>>1)-1):(((x)>>1)))
/*  <group dom_utility_macro> */
#define UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(x) (((x)&3)?(((x)>>1)-87):(((x)>>1)-88))
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length)                   \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                             \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH(allocated_length);                  \
            (count)++;                                                                             \
         }                                                                                         \
      }

/* <group dom_utility_macro> */
    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(c,count,allocated_length,length)                \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                                \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(allocated_length);           \
            (count)++;                                                                                \
         }                                                                                            \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(c,count,allocated_length,length)                      \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                                      \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(allocated_length);           \
            (count)++;                                                                                      \
         }                                                                                                  \
      }
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length)                   \
      {  if(UI_TEST_UCS2_CHARACTER(c) && ((count)>0))                                              \
         {  ((count)--);                                                                           \
            if((count)==0) (length)=(allocated_length);                                            \
         }                                                                                         \
      }
/*  <group dom_utility_macro> */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(old_c,c,count,allocated_length,length)                   \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length);                    \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(old_c,c,count,allocated_length,length)             \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(c,count,allocated_length,length);              \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(old_c,c,count,allocated_length,length)             \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(c,count,allocated_length,length);              \
      }
/* <group dom_utility_macro> */
#define UI_TEST_UCS2_COUNT_SET_LENGTH(count,allocated_length,length)                            \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH(allocated_length);                   \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(count,allocated_length,length)                            \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(allocated_length);               \
      }
/* <group dom_utility_macro> */
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE3(count,allocated_length,length)                                  \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(allocated_length);               \
      }

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_disable_alignment_timers
 * DESCRIPTION
 *  Disable timers alignment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_disable_alignment_timers(void);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  UI_enable_alignment_timers
 * DESCRIPTION
 *  Enable timers alignment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_enable_alignment_timers(void);


    /* Page break character equivalent needs to be added  */
    /* Euro character equivalent = 0xA2             */
/* <group dom_utility_macro> */
#define UI_TEST_GSM_EXTENDED mmi_7bit_check_gsm_ext_character_default
/* <group dom_utility_macro> */
#define UI_TEST_GSM_INCREMENT_COUNT(c,count)   if(UI_TEST_GSM_EXTENDED(c)) ((count)++)
/* <group dom_utility_macro> */    
#define UI_TEST_GSM_DECREMENT_COUNT(c,count)   if(UI_TEST_GSM_EXTENDED(c) && ((count)>0)) ((count)--)
/* <group dom_utility_macro> */
#define UI_TEST_GSM_CHANGE_COUNT(old_c,c,count)      \
    {  UI_TEST_GSM_DECREMENT_COUNT(old_c,count);     \
       UI_TEST_GSM_INCREMENT_COUNT(c,count);         \
    }

/* #define UI_TEST_GSM_EXTENDED(c)     \
(     (c==0xA2)                     \
   || (c=='^')                      \
   || (c=='{')                      \
   || (c=='}')                      \
   || (c=='\\')                     \
   || (c=='[')                      \
   || (c=='~')                      \
   || (c==']')                      \
   || (c=='|')                      \
)*/                                   \

    /* 
     * Painter Component: encapsulates various painting operations with common interface
     */

    /* Custom-defined callback type to draw a rectangle region 
       (x, y) is the left-top corner of drawing
       (clip_x1, clip_y1, clip_x2, clip_y2) is the clipping area. */
    typedef void (*gui_util_painter_callback_type)(
                    S32 x, 
                    S32 y, 
                    S32 clip_x1, 
                    S32 clip_y1, 
                    S32 clip_x2, 
                    S32 clip_y2);

   /*  <group dom_utility_enum>
    *  Types of painting operations */
    typedef enum 
    {
        /* Do nothing */
        GUI_UTIL_PAINTER_TYPE_EMPTY = 0,
        /* Fill transparent color */
        GUI_UTIL_PAINTER_TYPE_TRANSPARENT,
        /* Draw an image */
        GUI_UTIL_PAINTER_TYPE_IMAGEID,
        /* Call a custom-defined callback routine */
        GUI_UTIL_PAINTER_TYPE_CALLBACK,
        /* Use a filler */
        GUI_UTIL_PAINTER_TYPE_FILLER,
        /* Draw an image */
        GUI_UTIL_PAINTER_TYPE_IMAGERES,
        /* Last dummy enum type */
        GUI_UTIL_PAINTER_TYPE_END_OF_ENUM
    } gui_util_painter_type_enum;

    /* <group dom_utility_struct> */
    /* Painter UI component */
    typedef struct
    {
        gui_util_painter_type_enum type;
        union
        {
            MMI_ID_TYPE imageid;
            gui_util_painter_callback_type callback;
            const UI_filled_area *filler;
            PU8 image_res;
        } _u;
    } gui_util_painter_struct;

 /*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_image_with_alpha_transparent
 * DESCRIPTION
 *  draw an image with alpha 
 * PARAMETERS
 *  p       : [OUT]            
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_draw_image_with_alpha_transparent(U8* img_ptr, S32 x, S32 y, S32 alpha);   

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_draw_image_with_alpha_transparent
 * DESCRIPTION
 *  draw an image with alpha 
 * PARAMETERS
 *  p       : [OUT]            
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_draw_image_id_with_alpha_transparent(U16 image_id, S32 x, S32 y, S32 alpha);   
	

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_util_painter_create_empty
 * DESCRIPTION
 *  Create an empty painter that draws nothing
 * PARAMETERS
 *  p       : [OUT]           created painter object 
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_util_painter_create_empty(gui_util_painter_struct *p);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_util_painter_create_transparent
 * DESCRIPTION
 *  Create a painter that fills transparent background
 * PARAMETERS
 *  p       : [OUT]           created painter object 
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_util_painter_create_transparent(gui_util_painter_struct *p);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_util_painter_create_imageid
 * DESCRIPTION
 *  Create a painter that draws a image
 *
 *  Note: it's preferred to use image ID instead of raw data because 
 *  image ID can be drawn with downloadable theme.
 * PARAMETERS
 *  p           : [OUT]       created painter object 
 *  imageid     : [IN]        image to be drawn
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_util_painter_create_imageid(
                gui_util_painter_struct *p, 
                MMI_ID_TYPE imageid);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_util_painter_create_imageid
 * DESCRIPTION
 *  Create a painter that uses a callback to draw the region
 * PARAMETERS
 *  p           : [OUT]       created painter object 
 *  callback    : [IN]        callback draw function
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_util_painter_create_callback(
                gui_util_painter_struct *p, 
                gui_util_painter_callback_type callback);


/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_util_painter_create_filler
 * DESCRIPTION
 *  Create a painter that draws a filler
 * PARAMETERS
 *  p           : [OUT]       created painter object 
 *  filler      : [IN]        filler (must not be released before the painter object is released)
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_util_painter_create_filler(
                gui_util_painter_struct *p, 
                const UI_filled_area *filler);


/*****************************************************************************
* <group dom_utility_gui_layer_basic>
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
*  p              : [IN]    painter object 
*  x              : [IN]    x coordinate of left-top corner of painting area
*  y              : [IN]    y coordinate of left-top corner of painting area
*  clip_x1        : [IN]    clipping area
*  clip_y1        : [IN]    clipping area
*  clip_x2        : [IN]    clipping area
*  clip_y2        : [IN]    clipping area
* RETURNS
*  void
*****************************************************************************/
extern void gui_util_painter_show_clipped(
    const gui_util_painter_struct *p, 
    S32 x, 
    S32 y, 
    S32 clip_x1, 
    S32 clip_y1, 
    S32 clip_x2, 
    S32 clip_y2);

        
/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_util_painter_show
 * DESCRIPTION
 *  Draw a painter 
 * PARAMETERS
 *  p              : [IN]    painter object 
 *  x1             : [IN]    x coordinate of left-top corner 
 *  y1             : [IN]    y coordinate of left-top corner 
 *  x2             : [IN]    x coordinate of right-bottom corner 
 *  y2             : [IN]    y coordinate of right-bottom corner 
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_util_painter_show(const gui_util_painter_struct *p, S32 x1, S32 y1, S32 x2, S32 y2);

    /* 
     * Clean-up of GUI components 
     * To avoid clean-up each UI component explicitly in WGUI/draw manager/widget, 
     * general cleanup mechanism is provided here.
     */
/* <group dom_utility_macro> */
#define GUI_MAX_CLEANUP_HOOK  16

    typedef void (*gui_cleanup_hook_hdlr) (void);

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_add_cleanup_hook
 * DESCRIPTION
 *  Add cleanup hook function
 * PARAMETERS
 *  fp      : [IN]          The clean up hook function to be added
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_add_cleanup_hook(gui_cleanup_hook_hdlr fp);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_remove_cleanup_hook
 * DESCRIPTION
 *  Remove cleanup hook function
 * PARAMETERS
 *  fp      : [IN]          The function pointer to be remove
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_remove_cleanup_hook(gui_cleanup_hook_hdlr fp);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_cleanup
 * DESCRIPTION
 *  Call hook function of component when clean up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_cleanup(void);

    /* PMT VIKAS START 20051209 */
    /* Pre cleanup functions for GUI components */

    typedef void (*gui_pre_cleanup_hook_hdlr) (void);

    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_add_pre_cleanup_hook
 * DESCRIPTION
 *  Add a pre cleanup hook function
 * PARAMETERS
 *  fp      : [IN]        The hook function to be added
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_add_pre_cleanup_hook(gui_cleanup_hook_hdlr fp);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_remove_pre_cleanup_hook
 * DESCRIPTION
 *  Remove a pre clean up hook function
 * PARAMETERS
 *  fp      : [IN]          The function pointer to be remove
 * RETURNS
 *  void
 *****************************************************************************/
 extern void gui_remove_pre_cleanup_hook(gui_cleanup_hook_hdlr fp);
    

/*****************************************************************************
 * <group dom_utility_gui_layer_basic>
 * FUNCTION
 *  gui_pre_cleanup
 * DESCRIPTION
 *  Preview clean up before component exit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_pre_cleanup(void);
    /* PMT VIKAS END 20051209 */
    /* Touch Panel Events */
    /* <group dom_utility_enum> */
    typedef enum
    {
        GUI_PEN_EVENT_PARAM_VOID,
        GUI_PEN_EVENT_PARAM_INTEGER,
        GUI_PEN_EVENT_PARAM_INTEGER2,
        GUI_PEN_EVENT_PARAM_INTEGER3,
        GUI_PEN_EVENT_PARAM_POINTER,
        GUI_PEN_EVENT_PARAM_POINTER_INTEGER,
        GUI_PEN_EVENT_PARAM_POINTER_INTEGER2
    } gui_pen_event_param_enum;
    /* <group dom_utility_struct> */
    typedef struct _mmi_gui_pen_event_param_struct
    {
        gui_pen_event_param_enum type;
        union
        {
            int i;
            void *p;
        } _u;
        int i2;
        int i3;
    } gui_pen_event_param_struct;
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_VOID(_s) do {_s->type = GUI_PEN_EVENT_PARAM_VOID;} while (0)
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_INTEGER(_s, _i) do {_s->type = GUI_PEN_EVENT_PARAM_INTEGER;  \
                                                   _s->_u.i = _i;                            \
                                                   } while (0)
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_INTEGER2(_s, _i, _i2) do {_s->type = GUI_PEN_EVENT_PARAM_INTEGER2; \
                                                   _s->_u.i = _i;                                  \
                                                   _s->i2 = _i2;                                   \
                                                   } while (0)
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_INTEGER3(_s, _i, _i2, _i3) do {_s->type = GUI_PEN_EVENT_PARAM_INTEGER3;  \
                                                   _s->_u.i = _i;                                        \
                                                   _s->i2 = _i2;                                         \
                                                   _s->i3 = _i3;                                         \
                                                   } while (0)
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_POINTER(_s, _p) do {_s->type = GUI_PEN_EVENT_PARAM_POINTER;  \
                                                   _s->_u.p = _p;                            \
                                                   } while (0)
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_POINTER_INTEGER(_s, _p, _i2) do {_s->type = GUI_PEN_EVENT_PARAM_POINTER_INTEGER;  \
                                                   _s->_u.p = _p;                                                 \
                                                   _s->i2 = _i2;                                                  \
                                                   } while (0)
/* <group dom_utility_macro> */
#define GUI_PEN_EVENT_PARAM_SET_POINTER_INTEGER2(_s, _p, _i2, _i3) do {_s->type = GUI_PEN_EVENT_PARAM_POINTER_INTEGER2; \
                                                   _s->_u.p = _p;                                                       \
                                                   _s->i2 = _i2;                                                        \
                                                   _s->i3 = _i3;                                                        \
                                                   } while (0)

#ifdef __cplusplus
}
#endif 

#endif /* __GUI_H__ */ 


