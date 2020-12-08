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
 *  gui_icon_bar.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Source
 *
 * Author:
 * -------
 *  
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

/*****************************************************************************
 * include
 ****************************************************************************/
  #include "gui_progress_bar.h"
  #include "MMIDataType.h"
  #include "mmi_frm_input_gprot.h"
  #include "kal_general_types.h"
/*****************************************************************************
 * Static Declaration
 ****************************************************************************/

/*****************************************************************************
 * Global Variable
 ****************************************************************************/

/*****************************************************************************
 * Local Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_create
 * DESCRIPTION
 *  set data for inline time edit
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  x               [IN]        X coordinate
 *  y               [IN]        Y coordinate
 *  width           [IN]        Width
 *  height          [IN]        Height
 *  max             [IN]        Maximum value
 *  step_size       [IN]        step size
 *  value           [IN/OUT]    value of the control         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_create(
        gui_progress_bar_struct *instance,
        U16 x,
        U16 y,
        U16 width,
        U16 height,
        U16 max,
        U16 step_size,
        U16 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_create(instance, x, y, width, height, max, step_size, value);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_set_step
 * DESCRIPTION
 *  set progress bar step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Value of the step       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_set_step(gui_progress_bar_struct *instance, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_set_step(instance, value);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_pen_handler
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
BOOL wgui_progress_bar_pen_handler(gui_progress_bar_struct *instance, mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_progress_bar_pen_handler(instance, pen_event, x, y);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_set_value
 * DESCRIPTION
 *  set progress bar value
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Value of the control
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_set_value(gui_progress_bar_struct *instance, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_set_value(instance, value);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_reset_display_string
 * DESCRIPTION
 *  Reset progress bar display string
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_reset_display_string(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_set_display_string(instance, MMI_FALSE, PROGRESS_BAR_STRING_VALUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_register_change_listener
 * DESCRIPTION
 *  This API registers the change listener with the application. The callback
 *  is called whenever any change event happens on the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  funcptr         [IN]        Callback passed by application
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_register_change_listener(gui_progress_bar_struct *instance, mmi_pbar_funcptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_register_change_listener(instance, callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_set_display_string
 * DESCRIPTION
 *  set progress bar display string
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_set_display_string(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_set_display_string(instance, MMI_TRUE, PROGRESS_BAR_STRING_VALUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_set_display_string_percentage
 * DESCRIPTION
 *  set progress bar string type
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_set_display_string_percentage(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_set_display_string(instance, MMI_TRUE, PROGRESS_BAR_STRING_PERCENTAGE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_set_type_divided
 * DESCRIPTION
 *  set the progress bar to be divided
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_set_type_divided(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_set_type(instance, PROGRESS_BAR_DIVIDED);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_increment
 * DESCRIPTION
 *  API to increment the value of control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_increment(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_increment(instance);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_decrement
 * DESCRIPTION
 *  API to decrement the value of control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_decrement(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_decrement(instance);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_progress_bar_draw
 * DESCRIPTION
 *  Draws the progress bar control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_progress_bar_draw(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_progress_bar_draw(instance);

}


