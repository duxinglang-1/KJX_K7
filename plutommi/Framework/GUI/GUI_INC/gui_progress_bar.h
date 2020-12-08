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
 *  gui_progress_bar.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Header
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * include
 ****************************************************************************/
#ifndef __GUI_PROGRESS_BAR_H__
#define __GUI_PROGRESS_BAR_H__

#include "MMI_features.h"
//#include "gui.h"
//#include "gui_typedef.h"
#include "CustThemesRes.h"

#ifdef __MMI_TOUCH_SCREEN__
//#include "wgui_touch_screen.h"
#endif 

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"

/*****************************************************************************
 * Define
 ****************************************************************************/
typedef void (*mmi_pbar_funcptr) (void);

#define MMI_PROGRESS_BAR_DISPLAY_STRING_SIZE    12

/* Flags for the rendering part of the progress bar */
#define MMI_PROGRESS_BAR_SHOW_DIVISIONS                             0x00000001
#define MMI_PROGRESS_BAR_SHOW_STRING                                0x00000002
#define MMI_PROGRESS_BAR_SHOW_STRING_TYPE_PERCENTAGE                0x00000004
#define MMI_PROGRESS_BAR_SHOW_GRADIENT                              0x00000010

#define MMI_PROGRESS_BORDER_LINE                                    0X01

#ifdef __MMI_FTE_SUPPORT__
#define MMI_FTE_PROGRESS_BAR_BORDER_WIDTH     3
#endif

enum MMI_PROGRESS_BAR_TYPE
{
    PROGRESS_BAR_SOLID,
    PROGRESS_BAR_DIVIDED,
    PROGRESS_BAR_INDETERMINATE,
    PROGRESS_BAR_MAX
};

enum MMI_PROGRESS_BAR_STRING_TYPE
{
    PROGRESS_BAR_STRING_VALUE,
    PROGRESS_BAR_STRING_PERCENTAGE,
    PROGRESS_BAR_STRING_MAX
};

enum MMI_PROGRESS_BAR_FILL_TYPE
{
    PROGRESS_BAR_SINGLE_COLOR,
    PROGRESS_BAR_GRADIENT,
    PROGRESS_BAR_COLOR_MAX
};

/*****************************************************************************
 * Typedef
 ****************************************************************************/
/*
typedef struct _gui_progress_bar_color_union
{
    color c;
    gradient_color gc;

} gui_progress_bar_color_struct;
*/
typedef struct __gui_progress_bar_struct_type
{
    U16 x;
    U16 y;
    U16 width;
    U16 height;
    U16 max_value;
    U16 step_size_pixels;
    U16 step_size;
    U16 left_count;
    U16 *value;
    U32 flags;
    U8 string[MMI_PROGRESS_BAR_DISPLAY_STRING_SIZE];
    U16 slot_width;
    U16 slot_x;
    mmi_pbar_funcptr callback;

} gui_progress_bar_struct;


typedef struct
{
    UI_filled_area *background_filler;
    UI_filled_area *normal_progress_filler;
    UI_filled_area *step_filler;
    UI_filled_area *button_up_filler;
    UI_filled_area *button_press_filler;  /* When component is created, its button have 2 state, so add  2 state theme of button. */
    color text_color; 
}gui_progress_bar_theme_struct;


/*****************************************************************************
 * Global Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_set_progress_bar_focussed_theme
 * DESCRIPTION
 *  Set progress bar focussed theme.
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_set_progress_bar_theme(gui_progress_bar_struct *instance, gui_progress_bar_theme_struct *b);


/*****************************************************************************
 * FUNCTION
 *  gui_get_progress_bar_theme
 * DESCRIPTION
 *  Set progress bar focussed theme.
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_get_progress_bar_theme(gui_progress_bar_struct *instance, gui_progress_bar_theme_struct *b);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_create
 * DESCRIPTION
 *  Creates the progress bar control
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  x               [IN]        X coordinate
 *  y               [IN]        Y coordinate
 *  width           [IN]        Width
 *  height          [IN]        Height
 *  max             [IN]        Maximum value
 *  step_size       [IN]        Step size 
 *  value           [IN]        Present value of the control         
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_create(
        gui_progress_bar_struct *instance,
        U16 x,
        U16 y,
        U16 width,
        U16 height,
        U16 max,
        U16 step_size,
        U16 *value);
/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_register_change_listener
 * DESCRIPTION
 *  This API registers the change listener with the application. The callback
 *  is called whenever any change event happens on the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  funcptr         [IN]        Callback passed by application
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_register_change_listener(gui_progress_bar_struct *instance, mmi_pbar_funcptr funcptr);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_step
 * DESCRIPTION
 *  set progress bar step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Value of the step       
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_set_step(gui_progress_bar_struct *instance, S32 value);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_display_string
 * DESCRIPTION
 *  set progress bar type
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Whether to show or not the string on control
 *  type            [IN]        Progress bar value
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_set_display_string(
        gui_progress_bar_struct *instance,
        MMI_BOOL value,
        enum MMI_PROGRESS_BAR_STRING_TYPE type);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_value
 * DESCRIPTION
 *  set progress bar value
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Value of the control
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_set_value(gui_progress_bar_struct *instance, S32 value);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_fill_style
 * DESCRIPTION
 *  set progress bar fill style. It can be constant color or gradient.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  type            [IN]        Progress bar value
 *  gc              [IN]        Gradient color to be used         
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_set_fill_style(
        gui_progress_bar_struct *instance,
        enum MMI_PROGRESS_BAR_FILL_TYPE type
        );

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_type
 * DESCRIPTION
 *  set progress bar type. It can be solid or divided.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  type            [IN]        Progress bar type
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_set_type(gui_progress_bar_struct *instance, enum MMI_PROGRESS_BAR_TYPE type);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_draw_separaters
 * DESCRIPTION
 *  This API draws the separaters in case we choose the divided bar.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_draw_separaters(gui_progress_bar_struct *instance);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_increment
 * DESCRIPTION
 *  Increment the progress bar with the step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_increment(gui_progress_bar_struct *instance);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_decrement
 * DESCRIPTION
 *  Decrement the progress bar with the step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_decrement(gui_progress_bar_struct *instance);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_fill
 * DESCRIPTION
 *  Fills the progress bar with the color from 0 to its value.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_fill(gui_progress_bar_struct *instance);

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_draw_string
 * DESCRIPTION
 *  Draws the string in case its enabled in progress bar.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_draw_string(gui_progress_bar_struct *instance);

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_pen_handler
 * DESCRIPTION
 *  Handles the pen events in the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  pen_event       [IN]        Pen event
 *  x               [IN]        Pen x coordinate
 *  y               [IN]        Pen y coordinate
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern BOOL gui_progress_bar_pen_handler(gui_progress_bar_struct *instance, mmi_pen_event_type_enum pen_event, S16 x, S16 y);
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_draw
 * DESCRIPTION
 *  Draws the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_progress_bar_draw(gui_progress_bar_struct *instance);
#endif /* __GUI_PROGRESS_BAR_H__ */ 


