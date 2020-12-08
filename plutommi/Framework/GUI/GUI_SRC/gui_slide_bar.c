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
 * gui_slide_bar.h
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
 ****************************************************************************/
#include "gui_slide_bar.h"
#include "gui_themes.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gui_touch_feedback.h"
 
 /* 
 * Slide control implementation  
 * 
 * Different implementation than 'horizontal_slide' and 'vertical_slide'
 */


/*****************************************************************************
 * Globarl Variable 
 ****************************************************************************/

#ifdef GDI_USING_LAYER


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_layer
 * DESCRIPTION
 *  Set the slider control display layer
 * PARAMETERS
 *  s           [IN]        slider control object       
 *  layer       [IN]        layer handle to display the slider control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_set_target_layer(slide_control *s, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  reset_slide_control_layer
 * DESCRIPTION
 *  Reset the slider control display layer.
 * PARAMETERS
 *  s           [IN]        slider control object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_reset_target_layer(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->target_layer = GDI_ERROR_HANDLE;
}

#endif /* GDI_USING_LAYER */ 


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_change_text
 * DESCRIPTION
 *  Set the slider label text.
 * PARAMETERS
 *  s               [IN]        slider control object
 *  label_string    [IN]        slider label text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_change_text(slide_control *s, U8 *label_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->text = label_string;
    if (s->text)
    {
        S32 str_width = 0, str_height = 0;

        gui_measure_string((UI_string_type) s->text, &str_width, &str_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_show_control
 * DESCRIPTION
 *  Show the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_show_control(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, ub, lb, r;
    S32 move_width;
    color c;
    gdi_handle active_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__
    if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_SLIDE)
    {
        s->slide_image = current_MMI_theme->slide_bar_focused_indicator_image;
    }
    else
    {
        s->slide_image = current_MMI_theme->slide_bar_indicator_image;
    }
#endif
#endif

#ifdef GDI_USING_LAYER
    if (s->target_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->target_layer);
    }
#endif /* GDI_USING_LAYER */ 
    gui_push_clip();
    gui_reset_clip();
    if (wgui_is_wallpaper_on_bottom())
    {
        gdi_draw_solid_rect(s->x, s->y, s->x + s->bg_image_width - 1, s->y + s->bg_image_height - 1, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_fill_rectangle(s->x, s->y, s->x + s->bg_image_width - 1, s->y + s->bg_image_height - 1, c);
    }
//#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_SLIM_IMG_RES__)
    gdi_image_draw_resized(s->x, s->y, s->bg_image_width, s->bg_image_height, s->background_image);
//#else
//    gdi_image_draw(s->x, s->y, s->background_image);
//#endif
    ub = s->upper_limit;
    lb = s->lower_limit;
    r = ub - lb;
    if (r == 0)
    {
        r = 1;
    }

    move_width = s->width - UI_SLIDER_X1_GAP - UI_SLIDER_X2_GAP;
    MMI_DBG_ASSERT(move_width >= 0);

    x = ((s->current_value - lb) * move_width) / r;
    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);
    gdi_image_draw(
        s->x + x + UI_SLIDER_X1_GAP,
        s->y + ((s->bg_image_height - s->slide_image_height) >> 1) /* s->start_y */ ,
        s->slide_image);
    gdi_pop_and_restore_alpha_blending_source_layer();
    gui_pop_clip();
#ifdef GDI_USING_LAYER
    if (s->target_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* GDI_USING_LAYER */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_show_background
 * DESCRIPTION
 *  Clear the focus rectangle of the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object    
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_show_background(slide_control *s, MMI_BOOL focused)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
#ifndef __MMI_FTE_SUPPORT__
    gdi_color rect_color;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if(focused)
    {
        s->background_image = current_MMI_theme->slide_bar_focused_bg_image;
    }
    else
    {
        s->background_image = current_MMI_theme->slide_bar_background_image;
    }
#else /* __MMI_FTE_SUPPORT__ */
    if(focused)
    {
        rect_color = GDI_COLOR_RED;
    }
    else
    {
        rect_color = GDI_COLOR_TRANSPARENT;
    }
#endif /* __MMI_FTE_SUPPORT__ */

    #ifdef GDI_USING_LAYER
    if (s->target_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->target_layer);
    }
    #endif /* GDI_USING_LAYER */ 
    x1 = MMI_current_slide_control->x - 2;
    y1 = MMI_current_slide_control->y - 2;
    x2 = MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width + 1;
    y2 = MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height + 1;
    gdi_layer_reset_clip();
#ifdef __MMI_FTE_SUPPORT__
    gui_slide_bar_show_control(s);
#else /* __MMI_FTE_SUPPORT__ */
	#if !defined(__MMI_MAINLCD_128X64__)
    gdi_draw_rect(x1, y1, x2, y2, rect_color);
	#endif
#endif /* __MMI_FTE_SUPPORT__ */
    gdi_layer_blt_previous(x1, y1, x2, y2);
    #ifdef GDI_USING_LAYER
    if (s->target_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    #endif /* GDI_USING_LAYER */ 

}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_show_text
 * DESCRIPTION
 *  Show the slider control label text.
 * PARAMETERS
 *  s               [IN]        slider control object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_show_text(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->text)
    {
        S32 str_width = 0, str_height = 0;

    #ifdef GDI_USING_LAYER
        if (s->target_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_push_and_set_active(s->target_layer);
        }
    #endif /* GDI_USING_LAYER */ 
    #if defined(__MMI_MAINLCD_128X64__) || defined(__MMI_MAINLCD_96X64__) 
		gui_set_font(&MMI_small_font);
	#else
        gui_set_font(&MMI_default_font);
	#endif
        gui_measure_string((UI_string_type) s->text, &str_width, &str_height);
        if (r2lMMIFlag)
        {
            /* align the label to right edge of the slider background image */
            gui_move_text_cursor(s->x + s->bg_image_width - 1 - GUI_SLIDE_CONTROL_TEXT_X_GAP, s->y - str_height - GUI_SLIDE_CONTROL_TEXT_LABEL_TO_SLIDE_GAP);
        }
        else
        {
            gui_move_text_cursor(s->x + GUI_SLIDE_CONTROL_TEXT_X_GAP, s->y - str_height - GUI_SLIDE_CONTROL_TEXT_LABEL_TO_SLIDE_GAP);
        }
        if (wgui_is_wallpaper_on_bottom())
        {
            gui_set_text_color(*current_MMI_theme->list_normal_text_color);
        }
        else
        {
            gui_set_text_color(UI_COLOR_BLACK);
        }
        gui_print_text((UI_string_type) s->text);
    #ifdef GDI_USING_LAYER
        if (s->target_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* GDI_USING_LAYER */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_show_value
 * DESCRIPTION
 *  Show the slider control value.
 * PARAMETERS
 *  s               [IN]        slider control object      
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_show_value(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    color c;
    U8 ts[32];
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0, gap_x = 0;
#ifndef __MMI_MAINLCD_96X64__    
    UI_filled_area *value_bg_filler;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = *current_MMI_theme->popup_description_text_color;
    
    if (s->flags & GUI_SLIDE_CONTROL_VALUE_POS_NONE)
    {
        return;
    }

    gui_itoa(s->current_value, (UI_string_type) ts, 10);
    gui_reset_clip();
#if defined(__MMI_MAINLCD_128X64__) || defined(__MMI_MAINLCD_96X64__)
	gui_set_font(&MMI_small_font);
#else
    gui_set_font(&MMI_default_font);
#endif
    gui_measure_string((UI_string_type) ts, &w, &h);

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_BIDI_ALG__
    if (r2lMMIFlag)
    {
        x1 = s->x + GUI_SLIDE_CONTROL_TEXT_X_GAP;
        x2 = x1 + s->value_string_width;
    }
    else
#endif
    {
        x2 = s->x + s->bg_image_width - GUI_SLIDE_CONTROL_TEXT_X_GAP;
        x1 = x2 - s->value_string_width;
    }
    y1 = s->y - s->value_string_height - GUI_SLIDE_CONTROL_TEXT_X_GAP;
    y2 = y1 + s->value_string_height;
    
#else /* __MMI_FTE_SUPPORT__ */
    /* keep 1 pixel gap between the value rectangle and the focus rectangle */
    if (s->flags == GUI_SLIDE_CONTROL_VALUE_POS_HEAD)
    {
        x1 = s->x - s->value_string_width - s->value_string_gap - GUI_SLIDE_CONTROL_FOCUS_GAP - 1 - 1;  /* gap of focus rectangle */
        // y1 = s->y + s->bg_image_height - s->value_string_height + 1;
        y1 = s->y;
        x2 = x1 + s->value_string_width;
        if (s->value_string_height >= s->bg_image_height)
        {
            y2 = y1 + s->value_string_height;
        }
        else
        {
            y2 = y1 + s->bg_image_height;
        }
    }
    else if (s->flags == GUI_SLIDE_CONTROL_VALUE_POS_TAIL)
    {
        x1 = s->x + s->bg_image_width + s->value_string_gap + GUI_SLIDE_CONTROL_FOCUS_GAP + 1;  /* gap of focus rectangle */
        // y1 = s->y + s->bg_image_height - s->value_string_height + 1;
        y1 = s->y;
        x2 = x1 + s->value_string_width;
        if (s->value_string_height >= s->bg_image_height)
        {
            y2 = y1 + s->value_string_height;
        }
        else
        {
            y2 = y1 + s->bg_image_height;
        }
    }
    else if (s->flags == GUI_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
    {
        x1 = s->x + ((s->bg_image_width - s->value_string_width) >> 1) + 1;
    #if defined(__MMI_MAINLCD_96X64__) 
        y1 = s->y + s->bg_image_height + 1;
    #else
        y1 = s->y + s->bg_image_height + GUI_SLIDE_CONTROL_FOCUS_GAP + 1;       /* 1 pixel gap for focus */
    #endif
        x2 = x1 + s->value_string_width;
        y2 = y1 + s->value_string_height;
    }
    else
    {
        return;
    }
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef GDI_USING_LAYER
    if (s->target_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->target_layer);
    }
#endif /* GDI_USING_LAYER */ 

#if defined(__MMI_MAINLCD_96X64__) 
    gdi_draw_solid_rect(x1, y1, x2 , y2, GDI_COLOR_BLACK);
#else
    if (wgui_is_wallpaper_on_bottom())
    {
        gdi_draw_solid_rect(x1, y1, x2 , y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
    }
#endif

#ifndef __MMI_MAINLCD_96X64__ 
    value_bg_filler = current_MMI_theme->popup_description_background_filler;

#ifdef __MMI_FTE_SUPPORT__
    gap_x = 12;
#else /* __MMI_FTE_SUPPORT__ */
    gap_x = 4;
#endif /* __MMI_FTE_SUPPORT__ */

    if (value_bg_filler)
    {
        gui_draw_filled_area(x2 - w - gap_x, y1, x2, y2, value_bg_filler);
    }
#endif /*__MMI_MAINLCD_94X64__*/

    gui_set_text_color(c);

    /* center alignment in both directions */
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2 - (gap_x >> 1) - 1, y1 + ((y2 - y1 - h) >> 1));
    }
    else
    {
        gui_move_text_cursor(x2 - w - (gap_x >> 1), y1 + ((y2 - y1 - h) >> 1));
    }

    gui_print_text((UI_string_type) ts);

#ifdef __MMI_MAINLCD_96X64__
    // draw lower value in left
    gui_itoa(s->lower_limit, (UI_string_type) ts, 10);
	gui_measure_string((UI_string_type) ts, &w, &h);

#ifdef __MMI_BIDI_ALG__
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            s->x + 2 + w,
            s->y - h);
    }
    else
#endif /* __MMI_BIDI_ALG__ */ 
    gui_move_text_cursor(s->x + 2, s->y - h);
    gui_print_text((UI_string_type) ts);

    //draw upper value in right
    gui_itoa(s->upper_limit, (UI_string_type) ts, 10);
    gui_measure_string((UI_string_type) ts, &w, &h);

#ifdef __MMI_BIDI_ALG__
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            s->x + s->bg_image_width - 2,
            s->y - h);
    }
    else
#endif /* __MMI_BIDI_ALG__ */ 
        gui_move_text_cursor(
            s->x + s->bg_image_width - w - 2,
            s->y - h);
    gui_print_text((UI_string_type) ts);
#endif

    gui_BLT_double_buffer(x1, y1, x2, y2);

#ifdef GDI_USING_LAYER
    if (s->target_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* GDI_USING_LAYER */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_previous
 * DESCRIPTION
 *  Decrease the slider control value.
 * PARAMETERS
 *  s               [IN]        slider control object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_previous(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->current_value > s->lower_limit)
    {
        s->current_value--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_next
 * DESCRIPTION
 *  Increase the slider control value.
 * PARAMETERS
 *  s               [IN]        slider control object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_next(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->current_value < s->upper_limit)
    {
        s->current_value++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_set_range
 * DESCRIPTION
 *  Set the slider control value range.
 * PARAMETERS
 *  s               [IN]        slider control object         
 *  lower_limit     [IN]        lowest (minimum) limit
 *  upper_limit     [IN]        uppest (maximum) limit
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_set_range(slide_control *s, S32 lower_limit, S32 upper_limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digits;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->lower_limit = lower_limit;
    s->upper_limit = upper_limit;
#if defined(__MMI_MAINLCD_128X64__) || defined(__MMI_MAINLCD_96X64__)
	gui_set_font(&MMI_small_font);
#else
    gui_set_font(&MMI_default_font);
#endif
    /* measure maximum number string width and height */
    for (digits = 1; (upper_limit /= 10); digits++);
    mmi_fe_measure_string_by_char_num((U8*)L"0123456789", digits, &s->value_string_width, &s->value_string_height);

    /* leave 2-pixel gaps for the text and rectangle in each direction */
    // TODO: config this in gui_config.h
#ifdef __MMI_FTE_SUPPORT__
    s->value_string_width += 12;
    s->value_string_height += 10;
#else /* __MMI_FTE_SUPPORT__ */
#ifndef __MMI_MAINLCD_96X64__
    s->value_string_width += 4;
    s->value_string_height += 4;
#endif        
#endif /* __MMI_FTE_SUPPORT__ */  
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_set_value
 * DESCRIPTION
 *  Set the slider control value.
 * PARAMETERS
 *  s           [IN]        slider control object         
 *  value       [IN]        slider control value
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_set_value(slide_control *s, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((value < s->lower_limit) || (value > s->upper_limit))
    {
        return;
    }
    s->current_value = value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_create
 * DESCRIPTION
 *  Setup the slider control.
 * PARAMETERS
 *  s                   [IN]        slider control object        
 *  x                   [IN]        x
 *  y                   [IN]        y
 *  lower_limit         [IN]        minimum slider value
 *  upper_limit         [IN]        maximum slider value
 *  current_value       [IN]        current slider value
 *  change_callback     [IN]        slider change callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_create(
        slide_control *s,
        S32 x,
        S32 y,
        S32 lower_limit,
        S32 upper_limit,
        S32 current_value,
        void (*change_callback) (S32 value))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->x = x;
    s->y = y;
    s->background_image = NULL;
    s->slide_image = NULL;
    s->value_string_width = 0;
    s->value_string_height = 0;
    s->value_string_gap = 0;
    s->lower_limit = 0;
    s->upper_limit = 0;
    s->current_value = 0;
#ifdef GDI_USING_LAYER
    s->target_layer = GDI_ERROR_HANDLE;
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    s->pen_state = GUI_SLIDE_CONTROL_PEN_STATE_INVALID;
#endif

#ifdef __MMI_FTE_SUPPORT__
    s->background_image = current_MMI_theme->slide_bar_background_image;
    s->slide_image = current_MMI_theme->slide_bar_indicator_image;
#else
    s->background_image = (PU8) get_image(WGUI_SLIDE_CONTROL_BG_IMAGE_ID);
    s->slide_image = (PU8) get_image(WGUI_SLIDE_CONTROL_SI_IMAGE_ID);
#endif
    
    gui_measure_image(s->background_image, &s->bg_image_width, &s->bg_image_height);
    gui_measure_image(s->slide_image, &s->slide_image_width, &s->slide_image_height);
//#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_SLIM_IMG_RES__)
#ifndef __MMI_MAINLCD_96X64__ 
    s->bg_image_width = UI_device_width - 20;
    s->bg_image_height = GUI_SLIDE_BAR_BG_MIN_HEIGHT;
#endif
//#endif 
    s->width = s->bg_image_width - s->slide_image_width;

    s->change_callback = change_callback;
    gui_slide_bar_set_range(s, lower_limit, upper_limit);
    gui_slide_bar_set_value(s, current_value);
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_move
 * DESCRIPTION
 *  Move the position of the slider control value text.
 * PARAMETERS
 *  s       [IN]        slider control object         
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_slide_bar_move(slide_control *s, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* label is displayed */
    if (s->text)
    {
        S32 str_width = 0, str_height = 0;

        gui_measure_string((UI_string_type) s->text, &str_width, &str_height);
        s->x = x;
        s->y = y + str_height + 2;  /* gap is fixed to 2 */
    }
    else
    {
        s->x = x;
        s->y = y;
    }
}

#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  wgui_slide_control_translate_pen_position
 * DESCRIPTION
 *  Translate pen x position to the corresponding slider
 * PARAMETERS
 *  s           [IN]        slider control object         
 *  x           [IN]        pen x
 *  value       [OUT]       slider value      
 *  state       [OUT]       slider state
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_slide_bar_translate_pen_position(
                slide_control *s,
                S16 x,
                S32 *value,
                gui_slide_control_pen_state_enum *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ub = s->upper_limit;
    S32 lb = s->lower_limit;
    S32 r = ub - lb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x -= s->x;

    if (r == 0)
    {
        r = 1;
    }

    *value = (x * r + lb * s->width + (s->width >> 1))/s->width;
    *state = GUI_SLIDE_CONTROL_PEN_STATE_SLIDE;
    MMI_DBG_ASSERT(*value >= lb && *value <= ub);
}


/*****************************************************************************
 * FUNCTION
 *  gui_slide_bar_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object         
 *  pen_event       [IN]        pen event    
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  slide_event     [OUT]       pen event
 *  slide_param     [OUT]       pen parameter  
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_slide_bar_translate_pen_event(
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
    MMI_BOOL ret = MMI_TRUE;
    S32 new_value;
    gui_slide_control_pen_state_enum new_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *slide_event = GUI_SLIDE_CONTROL_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(slide_param);

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(
                x, 
                y, 
                s->x, 
                s->y, 
                s->bg_image_width, 
                s->bg_image_height))
            {
                gui_slide_bar_translate_pen_position(s, x, &new_value, &new_state);
                s->pen_state = new_state;
                *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, new_value);
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            else
            {
                ret = MMI_FALSE;
                s->pen_state = GUI_SLIDE_CONTROL_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_SLIDE)
            {
                gui_slide_bar_translate_pen_position(s, x, &new_value, &new_state);
                if (new_value != s->current_value)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, new_value);
                }
            }
            else
            {
                /* Ignore the event */
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_ABORT:
            /* Do nothing */
            s->pen_state = GUI_SLIDE_CONTROL_PEN_STATE_INVALID;
            break;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */


