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
 * wgui_slide_bar.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for slide bar control.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_typedef.h"
#include "gui_slide_bar.h"
#include "wgui_slide_bar.h"


/***************************************************************************** 
* Globar variable
*****************************************************************************/
/* varbale of type slide_control used in slide control screen */
slide_control *MMI_current_slide_control = NULL;

/* slide_control MMI_slide_control1,MMI_slide_control2; */
slide_control MMI_slide_control[MMI_MAX_SLIDE_CONTROL];

/* store current slide control value */
S32 *MMI_current_slide_control_value = NULL;
S32 *MMI_slide_control_value[MMI_MAX_SLIDE_CONTROL];


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_create
* DESCRIPTION
*  Create slide bar
* PARAMETERS
*  s            : [IN]          The pointer of slide bar
*  x            : [IN]          The x coordinate of slide bar 
*  y            : [IN]          The y coordinate of slide bar 
*  lower_limit  : [IN]          The low limit of slide bar range 
*  upper_limit  : [IN]          The up limit of slide bar range
*  current_value    : [IN]          The value of slide bar 
*  change_callback  : [IN]          The change callback function of slide bar
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_create(
        slide_control *s, 
        S32 x, 
        S32 y, 
        S32 lower_limit, 
        S32 upper_limit, 
        S32 current_value, 
        void(* change_callback)(S32 value))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_create(s, x, y, lower_limit, upper_limit, current_value, change_callback);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_move
* DESCRIPTION
*  MOve slide bar
* PARAMETERS
*  s            : [IN]          The pointer of slide bar
*  x            : [IN]          The x coordinate of slide bar 
*  y            : [IN]          The y coordinate of slide bar
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_move(slide_control *s, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_move(s, x, y);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_change_text
* DESCRIPTION
*  Change the slide bar's text
* PARAMETERS
*  s            : [IN]          The pointer of slide bar
*  text         : [IN]          New text of slide bar 
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_change_text(slide_control *s, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_change_text(s, text);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_set_focus
* DESCRIPTION
*  set teh focus on particular slide
* PARAMETERS
*  s       [IN]        
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_set_focus(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_current_slide_control = s;
    if (s == &MMI_slide_control[0])
    {
        MMI_current_slide_control_value = MMI_slide_control_value[0];
    }
    else if (s == &MMI_slide_control[1])
    {
        MMI_current_slide_control_value = MMI_slide_control_value[1];
    }
    else if (s == &MMI_slide_control[2])
    {
        MMI_current_slide_control_value = MMI_slide_control_value[2];
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_show
* DESCRIPTION
*  show slide control
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_show_text(MMI_current_slide_control);
    gui_slide_bar_show_control(MMI_current_slide_control);
    gui_slide_bar_show_value(MMI_current_slide_control);
    gdi_layer_blt_previous(
        MMI_current_slide_control->x,
        MMI_current_slide_control->y,
        MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width - 1,
        MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height - 1);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_update
* DESCRIPTION
*  update slide control slider and value
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_show_control(MMI_current_slide_control);
    gui_slide_bar_show_value(MMI_current_slide_control);
    gdi_layer_blt_previous(
        MMI_current_slide_control->x,
        MMI_current_slide_control->y,
        MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width - 1,
        MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height - 1);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_show_focus
* DESCRIPTION
*  set the foucs on particular slide control
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_show_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_show_background(MMI_current_slide_control, MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_hide_focus
* DESCRIPTION
*  hide slide control
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_hide_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_show_background(MMI_current_slide_control, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_control_previous
* DESCRIPTION
*  moveto previous slide control on screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_previous(MMI_current_slide_control);
    gdi_layer_lock_frame_buffer();
    wgui_slide_bar_update();
    gdi_layer_unlock_frame_buffer();
    *MMI_current_slide_control_value = MMI_current_slide_control->current_value;

    if (MMI_current_slide_control->change_callback)
    {
        MMI_current_slide_control->change_callback(*MMI_current_slide_control_value);
    }
    gdi_layer_blt_previous(
        MMI_current_slide_control->x,
        MMI_current_slide_control->y,
        MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width - 1,
        MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height - 1);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_next
* DESCRIPTION
*  moveto next slide control on screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_next(MMI_current_slide_control);
    gdi_layer_lock_frame_buffer();
    wgui_slide_bar_update();
    gdi_layer_unlock_frame_buffer();
    *MMI_current_slide_control_value = MMI_current_slide_control->current_value;

    if (MMI_current_slide_control->change_callback)
    {
        MMI_current_slide_control->change_callback(*MMI_current_slide_control_value);
    }
    gdi_layer_blt_previous(
        MMI_current_slide_control->x,
        MMI_current_slide_control->y,
        MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width - 1,
        MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height - 1);
}


/*****************************************************************************
* FUNCTION
*  wgui_slide_bar_set_value
* DESCRIPTION
*  
* PARAMETERS
*  value       [IN]        
* RETURNS
*  void
*****************************************************************************/
void wgui_slide_bar_set_value(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_slide_bar_set_value(MMI_current_slide_control, value);
    gdi_layer_lock_frame_buffer();
    wgui_slide_bar_update();
    gdi_layer_unlock_frame_buffer();
    *MMI_current_slide_control_value = MMI_current_slide_control->current_value;

    if (MMI_current_slide_control->change_callback)
    {
        MMI_current_slide_control->change_callback(*MMI_current_slide_control_value);
    }
    gdi_layer_blt_previous(
        MMI_current_slide_control->x,
        MMI_current_slide_control->y,
        MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width - 1,
        MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height - 1);
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  wgui_slide_control_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the slider control.
 * PARAMETERS
 *  s              : [IN]        slider control object         
 *  pen_event      : [IN]        pen event    
 *  x              : [IN]        pen x
 *  y              : [IN]        pen y
 *  slide_event    : [OUT]       pen event
 *  slide_param    : [OUT]       pen parameter  
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL wgui_slide_bar_translate_pen_event(
        slide_control *s,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_slide_control_pen_event_enum *slide_event,
        gui_pen_event_param_struct *slide_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_slide_bar_translate_pen_event(
            s,
            pen_event,
            x,
            y,
            slide_event,
            slide_param);
    if (*slide_event == GUI_SLIDE_CONTROL_PEN_JUMP_TO_I && pen_event != MMI_PEN_EVENT_DOWN)
    {
        wgui_slide_bar_set_value(slide_param->_u.i);
    }
    else if (ret == KAL_TRUE)
    {
        wgui_slide_bar_update();
    }
    
    return ret;
}

#endif

