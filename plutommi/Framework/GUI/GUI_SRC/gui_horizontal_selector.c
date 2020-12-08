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
 *  gui_horizontal_selector.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  horizontal selector - UI component
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "gui_horizontal_selector.h"
#include "gui_touch_feedback.h"

#include "gui_typedef.h"
#include "gui_theme_struct.h"
#include "MMIDataType.h"
#include "CustThemesRes.h"
#include "gdi_include.h"
#include "gui.h"
#include "kal_general_types.h"
#include "gui_windows.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_at_util_gprot.h"
#include "wgui_categories_util.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static gui_horizontal_select_struct *current_horizontal_select = NULL;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
UI_horizontal_select_theme *current_horizontal_select_theme = NULL;


/***************************************************************************** 
 * Local functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_show_background
 * DESCRIPTION
 *  Apply the current theme to the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_show_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_struct *m;
#ifdef __MMI_FTE_SUPPORT__       
    UI_filled_area *select_background;
#else
    UI_filled_area *f;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m = current_horizontal_select;
#ifdef __MMI_FTE_SUPPORT__   
    if (m->flags & UI_HORIZONTAL_SELECT_FOCUSED_STATE)
    {
        select_background = m->theme->select_focused_background;
    }
    else
    {
        select_background = m->theme->select_background;
    }
#else
    f= m->theme->background_filler;
#endif
    
    gdi_layer_push_clip();
    if (m->flags & UI_HORIZONTAL_SELECT_USE_PRESET_CLIP)
    {
        gui_set_clip_preset(x1, y1, x2, y2);
    }
    else
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
    }
    
    if (m->hide_callback)
    {
        m->hide_callback(x1, y1, x2, y2);
    }
    else
    {
        if ( (wgui_is_wallpaper_on_bottom() == MMI_TRUE) && (!m->flags & UI_HORIZONTAL_SELECT_NOT_CLEAR_BACKGROUND))
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
    #ifdef __MMI_FTE_SUPPORT__    
        gui_draw_filled_area(m->x, m->y, m->x + m->width - 1, m->y + m->height - 1, select_background);
    #else /* __MMI_FTE_SUPPORT__ */
        gui_draw_filled_area(m->x, m->y, m->x + m->width - 1, m->y + m->height - 1, f);
    #endif /* __MMI_FTE_SUPPORT__ */
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_scrolling_text_handler
 * DESCRIPTION
 *  The handler of horizontal selector scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_scrolling_text_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&(current_horizontal_select->scroll_text));
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_redraw
 * DESCRIPTION
 *  Draw and blt out the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_redraw(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_horizontal_select_show(m);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(m->x, m->y, m->x + m->width - 1, m->y + m->height - 1);
	#ifdef __IV_TTS__
	if(NPR_TTS_get_menu_read_enble())
	NPR_TTS_menu_read(m->items[m->highlighted_item].text);
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_images
 * DESCRIPTION
 *  Set horizontal select left and right arrow images.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_set_arrow_state(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
#ifdef __MMI_TOUCH_SCREEN__
    S32 left_arrow_x, left_arrow_y;
    S32 right_arrow_x, right_arrow_y;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->theme->left_arrow_image != NULL)
    {
        gdi_image_get_dimension(m->theme->left_arrow_image, &width, &height);
    #ifdef __MMI_TOUCH_SCREEN__

    #if defined(__MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__) && !defined(__MMI_FTE_SUPPORT__)
        left_arrow_x = 0;
    #else /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        left_arrow_x = GUI_HORIZONTAL_SELECT_ICON_X_GAP;
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        left_arrow_y = (m->height -height) >> 1;

        m->pen_state.left_region_x = left_arrow_x - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.left_region_x < 0)
        {
            m->pen_state.left_region_x = 0;
        }
        
        m->pen_state.left_region_y = left_arrow_y - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.left_region_y < 0)
        {
            m->pen_state.left_region_y = 0;
        }
        
        m->pen_state.left_region_width = width + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION << 1);
        if (m->pen_state.left_region_x + m->pen_state.left_region_width >= (m->width >> 1))
        {
            m->pen_state.left_region_width = (m->width >> 1) - m->pen_state.left_region_x - 1;
        }
        
        m->pen_state.left_region_height = height + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION << 1);
        if (m->pen_state.left_region_y + m->pen_state.left_region_height >= m->height)
        {
            m->pen_state.left_region_height = m->height - m->pen_state.left_region_y - 1;
        }
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    
    if (m->theme->right_arrow_image != NULL)
    {
        gdi_image_get_dimension(m->theme->right_arrow_image, &width, &height);

    #ifdef __MMI_TOUCH_SCREEN__

    #if defined(__MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__) && !defined(__MMI_FTE_SUPPORT__)
        right_arrow_x = m->width - width;
    #else /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        right_arrow_x = m->width - width - GUI_HORIZONTAL_SELECT_ICON_X_GAP;
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

        right_arrow_y = (m->height -height) >> 1;

        m->pen_state.right_region_x = right_arrow_x - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.right_region_x < (m->width >> 1))
        {
            m->pen_state.right_region_x = (m->width >> 1);
        }
        
        m->pen_state.right_region_y = right_arrow_y - GUI_HORIZONTAL_SELECT_PEN_VALID_REGION;
        if (m->pen_state.right_region_y < 0)
        {
            m->pen_state.right_region_y = 0;
        }
        
        m->pen_state.right_region_width = width + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION << 1);
        if (m->pen_state.right_region_x + m->pen_state.right_region_width >= m->width)
        {
            m->pen_state.right_region_width = m->width - m->pen_state.right_region_x - 1;
        }
        
        m->pen_state.right_region_height = height + (GUI_HORIZONTAL_SELECT_PEN_VALID_REGION << 1);
        if (m->pen_state.right_region_y + m->pen_state.right_region_height >= m->height)
        {
            m->pen_state.right_region_height = m->height - m->pen_state.right_region_y - 1;
        }
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_select_images
 * DESCRIPTION
 *  Set horizontal select left and right arrow images.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_show_arrow(gui_horizontal_select_struct *m, S32 *center_x1, S32 *center_x2, MMI_BOOL show_arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
    S32 left_arrow_x = 0, left_arrow_y = 0;
    S32 right_arrow_x = 0, right_arrow_y = 0;
#ifdef __MMI_FTE_SUPPORT__
    gdi_handle active_layer;
#endif            

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *center_x1 = 0;
    *center_x2 = 0;
    if (m->theme->left_arrow_image != NULL)
    {
        gdi_image_get_dimension(m->theme->left_arrow_image, &width, &height);
    #if defined(__MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__) && !defined(__MMI_FTE_SUPPORT__)
        left_arrow_x = 0;
        *center_x1 = left_arrow_x + width -1 + 3;
    #else /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        left_arrow_x = GUI_HORIZONTAL_SELECT_ICON_X_GAP;
        *center_x1 = left_arrow_x + width - 1 + GUI_HORIZONTAL_SELECT_TEXT_X_GAP;
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        left_arrow_y = (m->height -height) >> 1;
    }
    
    if (m->theme->right_arrow_image != NULL)
    {
        gdi_image_get_dimension(m->theme->right_arrow_image, &width, &height);

    #if defined(__MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__) && !defined(__MMI_FTE_SUPPORT__)
        right_arrow_x = m->width - width;
        *center_x2 = right_arrow_x - 3;
    #else /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        right_arrow_x = m->width - width - GUI_HORIZONTAL_SELECT_ICON_X_GAP;
        *center_x2 = right_arrow_x - GUI_HORIZONTAL_SELECT_TEXT_X_GAP;
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

        right_arrow_y = (m->height - height) >> 1;
    }

    if (show_arrow)
    {
    #ifdef __MMI_FTE_SUPPORT__
        gdi_layer_get_active(&active_layer);
        gdi_push_and_set_alpha_blending_source_layer(active_layer);
        if (m->theme->left_arrow_image != NULL)
        {
            if (m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_LEFT)
            {
                gdi_image_draw(m->x + left_arrow_x, m->y + left_arrow_y, m->theme->left_arrow_clicked_image);
            }
            else
            {
                gdi_image_draw(m->x + left_arrow_x, m->y + left_arrow_y, m->theme->left_arrow_image);
            }
        }
        
        if (m->theme->right_arrow_image != NULL)
        {
            if (m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_RIGHT)
            {
                gdi_image_draw(m->x + right_arrow_x, m->y + right_arrow_y, m->theme->right_arrow_clicked_image);
            }
            else
            {
                gdi_image_draw(m->x + right_arrow_x, m->y + right_arrow_y, m->theme->right_arrow_image);
            }
        }
        gdi_pop_and_restore_alpha_blending_source_layer();
    #else /* __MMI_FTE_SUPPORT__ */
        S32 left_arrow_pressed = 0;
        S32 right_arrow_pressed = 0;
        
        if (m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_LEFT)
        {
            left_arrow_pressed = 1;
        }
        else if(m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_RIGHT)
        {
            right_arrow_pressed = 1;
        }
            
        if (m->theme->left_arrow_image != NULL)
        {
            gdi_image_draw(m->x + left_arrow_x, m->y + left_arrow_y + left_arrow_pressed, m->theme->left_arrow_image);
        }
        
        if (m->theme->right_arrow_image != NULL)
        {
            gdi_image_draw(m->x + right_arrow_x, m->y + right_arrow_y + right_arrow_pressed, m->theme->right_arrow_image);
        }
    #endif /* __MMI_FTE_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_show_color_select
 * DESCRIPTION
 *  Show color selector for horizontal select.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_show_multi_area(
                gui_horizontal_select_struct *m,
                S32 center_x1,
                S32 center_x2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 gap = GUI_HORIZONTAL_SELECT_COLOR_H_GAP;
    S32 color_width, color_height;
    S32 i;
    S32 color_x1, color_x2, color_y1, color_y2;
    S32 color_index;
    gdi_handle active_layer;
#ifdef __MMI_FTE_SUPPORT__
    S32 color_border_width = GUI_HORIZONTAL_SELECT_COLOR_BORDER_WIDTH;
#endif
    color c;
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->flags & UI_HORIZONTAL_SELECT_ZONE_IS_COLOR)
    {
        color_height = m->height - (GUI_HORIZONTAL_SELECT_COLOR_V_GAP << 1);
        color_width = color_height;
    }
    else
    {
        gdi_image_get_dimension(
            m->items[m->highlighted_item]._u.icon,
            &color_width, 
            &color_height);
        gdi_layer_get_active(&active_layer);
        gdi_push_and_set_alpha_blending_source_layer(active_layer);
    }
    
    color_y1 = m->y + ((m->height - color_height) >> 1);
    color_y2 = color_y1 + color_height - 1;
    
    m->display_count = (center_x2 - center_x1 + 1 + gap)/(color_width + gap);
    if (m->display_count > m->n_items)
    {
        m->display_count = m->n_items;
        m->first_display_index = 0;
    }
    else
    {
        if (m->highlighted_item > m->first_display_index + m->display_count - 1)
        {
            m->first_display_index = m->highlighted_item - m->display_count + 1;
        }
        else if(m->highlighted_item < m->first_display_index)
        {
            m->first_display_index = m->highlighted_item;
        }
    }
    
    color_x1 = m->x + center_x1 + gap;
    
    for (i = 0; i < m->display_count; i++)
    {
        color_x2 = color_x1 + color_width - 1;
        color_index = m->first_display_index + i;
#ifdef __MMI_FTE_SUPPORT__
        if (color_index == m->highlighted_item)
        {
            U8 *image = m->theme->select_highlight_item_bg;
            gdi_layer_get_active(&active_layer);
            gdi_push_and_set_alpha_blending_source_layer(active_layer);
            gdi_image_draw_resized(
                color_x1 - color_border_width, 
                m->y, 
                color_width + (color_border_width << 1),
                m->height,
                image);
           gdi_pop_and_restore_alpha_blending_source_layer();
        }
#endif  
        if (m->flags & UI_HORIZONTAL_SELECT_ZONE_IS_COLOR)
        {
            c = m->items[color_index]._u.zone_color;

            /* if is pure blue, draw cross */
            if (c.r == 0 && c.g == 0 && c.b == 255)
            {
                gui_fill_rectangle(
                    color_x1, 
                    color_y1, 
                    color_x2, 
                    color_y2, 
                    gui_color(255, 255, 255));
                
                gui_line(color_x1, color_y1, color_x2, color_y2, gui_color(0, 0, 0));
                gui_line(color_x2, color_y1, color_x1, color_y2, gui_color(0, 0, 0));
            }
            else
            {
                gui_fill_rectangle(
                    color_x1, 
                    color_y1, 
                    color_x2, 
                    color_y2, 
                    c);
            }

            gui_draw_rectangle(
                color_x1, 
                color_y1, 
                color_x2,
                color_y2,
                gui_color(255, 255, 255));

            if (color_index == m->highlighted_item)
            {
            #ifndef __MMI_FTE_SUPPORT__            
                gui_draw_rectangle(
                    color_x1 - 1, 
                    color_y1 - 1, 
                    color_x2 + 1, 
                    color_y2 + 1, 
                    gui_color(255, 0, 0));
            #endif
            }
            else
            {
                gui_draw_rectangle(
                    color_x1 - 1,
                    color_y1 - 1, 
                    color_x2 + 1, 
                    color_y2 + 1, 
                    gui_color(0, 0, 0));
            }
        }
        else
        {
            gdi_image_draw(
                color_x1, 
                color_y1, 
                m->items[color_index]._u.icon);
        }

        color_x1 = color_x2 + gap;
    }

    if (!(m->flags & UI_HORIZONTAL_SELECT_ZONE_IS_COLOR))
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_show_color_select
 * DESCRIPTION
 *  Show multi icon for horizontal select.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_show_text(
                gui_horizontal_select_struct *m,
                S32 center_x1,
                S32 center_x2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type text;
    S32 iwidth, iheight;    
    S32 x1, x2;
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text = m->items[m->highlighted_item].text;
    x1 = m->x + center_x1;
    x2 = m->x + center_x2;

    gui_set_font(m->theme->text_font);
    gui_set_text_color(m->theme->text_color);
    gui_measure_string((UI_string_type)text, &iwidth, &iheight);

    gdi_layer_push_clip();
    if (m->flags & UI_HORIZONTAL_SELECT_USE_PRESET_CLIP)
    {
        gui_set_clip_preset(x1, m->y, x2, m->y + m->height - 1);
    }
    else
    {
        gdi_layer_set_clip(x1, m->y, x2, m->y + m->height - 1);
    }
    
    if ((m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_CENTER) &&
        (iwidth < x2 - x1 + 1))
    {
        x1 += ((center_x2 - center_x1 + 1) - iwidth) >> 1;
        x2 -= ((center_x2 - center_x1 + 1) - iwidth) >> 1;
    }
    else if ((m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_RIGHT) &&
             (iwidth < x2 - x1 + 1))
    {
        x1 = x2 - iwidth;
    }
	else
	{
       x1 = x1 + 3;//left, 3pixels gap
	   x2 = x2 - 3;//right, 3pixels gap
	
	}

    if (m->flags & UI_HORIZONTAL_SELECT_FOCUSED_STATE)
    {
        gui_create_scrolling_text(
            &(m->scroll_text),
            x1,
            m->y + ((m->height - iheight) >> 1),
            x2 - x1 + 1,
            iheight,
            text,
            gui_horizontal_select_scrolling_text_handler,
            gui_horizontal_select_show_background,
            m->theme->text_color,
            m->theme->text_color);
        if (m->flags & UI_HORIZONTAL_SELECT_USE_PRESET_CLIP)
        {
            m->scroll_text.flags |= UI_SCROLLING_TEXT_PRESET_CLIP;
        }
        
        gui_show_scrolling_text(&(m->scroll_text));
    }
    else
    {
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x2, m->y + ((m->height - iheight) >> 1));
        }
        else
        {
            gui_move_text_cursor(x1, m->y + ((m->height - iheight) >> 1));
        }
        
        gui_print_text((UI_string_type)text);
    }
    
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_show_color_select
 * DESCRIPTION
 *  Show multi icon for horizontal select.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_show_text_area(
                gui_horizontal_select_struct *m,
                S32 center_x1,
                S32 center_x2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width, text_height;
    S32 color_x1, color_x2, color_y1, color_y2,color_width, color_height;
    UI_string_type text;
    color c;
    S32 gap = GUI_HORIZONTAL_SELECT_COLOR_H_GAP;
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text = m->items[m->highlighted_item].text;
    c = m->items[m->highlighted_item]._u.zone_color;
    if (m->flags & UI_HORIZONTAL_SELECT_ZONE_IS_COLOR)
    {
        color_width = GUI_HORIZONTAL_SELECT_SINGLE_COLOR_WIDTH;
        color_height = color_width;
    }
    else
    {
        gdi_image_get_dimension(
            m->items[m->highlighted_item]._u.icon,
            &color_width, 
            &color_height);
    }
    
    gui_set_font(m->theme->text_font);
    gui_measure_string(text, &text_width, &text_height);
    if ((text_width + color_width + (gap << 1)) >= (center_x2 - center_x1))
    {
        if (m->flags & UI_HORIZONTAL_SELECT_AREA_TEXT_ORDER)
        {
            color_x1 = m->x + center_x1 + gap;
            color_x2 = color_x1 + color_width - 1;
            center_x1 += color_width + (gap << 1);
        }
        else
        {
            color_x2 = m->x + center_x2 - gap;
            color_x1 = color_x2 - color_width + 1;
            center_x2 -= color_width + (gap << 1);
        }
    }
    else
    {
        if (m->flags & UI_HORIZONTAL_SELECT_AREA_TEXT_ORDER)
        {
            if ((m->flags & UI_HORIZONTAL_SELECT_ZONE_ALIGN_LEFT) &&
                (m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_LEFT))
            {
                color_x1 = m->x + center_x1 + gap;
                color_x2 = color_x1 + color_width - 1;
                center_x1 += color_width + (gap << 1);
            }
            else if ((m->flags & UI_HORIZONTAL_SELECT_ZONE_ALIGN_RIGHT) &&
                     (m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_RIGHT))
            {
                center_x1 = center_x2 - text_width - gap;
                color_x2 = center_x1;
                color_x1 = color_x2 - color_width + 1;
            }
            else if ((m->flags & UI_HORIZONTAL_SELECT_ZONE_ALIGN_LEFT) &&
                     (m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_RIGHT))
            {
                color_x1 = m->x + center_x1 + gap;
                color_x2 = color_x1 + color_width - 1;
                center_x1 = center_x2 - text_width;
            }
            else
            {
                color_x1 = m->x + center_x1 + ((center_x2 - center_x1 - (color_width + text_width + gap)) >> 1);
                color_x2 = color_x1 + color_width - 1;
                center_x1 = (color_x2 - m->x) + gap;
                center_x2 = center_x1 + text_width;
            }
        }
        else
        {
            if ((m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_LEFT) &&
                (m->flags & UI_HORIZONTAL_SELECT_ZONE_ALIGN_LEFT))
            {
                center_x2 = center_x1 + text_width;
                color_x1 = m->x + center_x2 + gap;
                color_x2 = color_x1 + color_width - 1;
            }
            else if ((m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_RIGHT) &&
                     (m->flags & UI_HORIZONTAL_SELECT_ZONE_ALIGN_RIGHT))
            {
                color_x2 = m->x + center_x2 - gap;
                color_x1 = color_x2 - color_width + 1;
                center_x2 -= color_width + (gap << 1);
                center_x1 = center_x2 - text_width;
            }
            else if ((m->flags & UI_HORIZONTAL_SELECT_TEXT_ALIGN_LEFT) &&
                     (m->flags & UI_HORIZONTAL_SELECT_ZONE_ALIGN_RIGHT))
            {
                color_x2 = m->x + center_x2 - gap;
                color_x1 = color_x2 - color_width + 1;
                center_x2 = center_x1 + text_width;
            }
            else
            {
                color_x2 = m->x + center_x2 - ((center_x2 - center_x1 - (color_width + text_width + gap)) >> 1);
                color_x1 = color_x2 - color_width + 1;
                center_x2 = color_x1 - m->x - gap;
                center_x1 = center_x2 - text_width;
            }
        }
    }

    color_y1 = m->y + ((m->height - color_height) >> 1);
    color_y2 = color_y1 + color_width - 1;

    if (m->flags & UI_HORIZONTAL_SELECT_ZONE_IS_COLOR)
    {
        gui_fill_rectangle(
            color_x1,
            color_y1,
            color_x2,
            color_y2,
            c);
        gui_draw_rectangle(
            color_x1,
            color_y1,
            color_x2,
            color_y2,
            gui_color(255, 255, 255));
        gui_draw_rectangle(
            color_x1 - 1,
            color_y1 - 1,
            color_x2 + 1,
            color_y2 + 1,
            gui_color(0, 0, 0));
    }
    else
    {
        gdi_image_draw_blend2layers(color_x1, color_y1, m->items[m->highlighted_item]._u.icon);
    }
    
    gui_horizontal_select_show_text(
        m, 
        center_x1, 
        center_x2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_left_key_down
 * DESCRIPTION
 *  Left key down handler.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_left_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_left_key_down_handler(current_horizontal_select);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_left_key_up
 * DESCRIPTION
 *  Left key up handler.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_left_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_left_key_up_handler(current_horizontal_select);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_right_key_down
 * DESCRIPTION
 *  Right key down handler.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_right_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_right_key_down_handler(current_horizontal_select);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_right_key_up
 * DESCRIPTION
 *  Right key up handler.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_select_right_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_right_key_up_handler(current_horizontal_select);
}


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_set_current_theme
 * DESCRIPTION
 *  Apply the current theme to the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_set_current_theme(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->theme = current_horizontal_select_theme;  
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_set_theme
 * DESCRIPTION
 *  Apply the given theme to the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  t       [IN]        horizontal select menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_set_theme(gui_horizontal_select_struct *m, UI_horizontal_select_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->theme = t;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_create
 * DESCRIPTION
 *  Create the horizontal select menu.
 * PARAMETERS
 *  m           [IN]        horizontal select menu object
 *  x           [IN]        x
 *  y           [IN]        y
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_create(
        gui_horizontal_select_struct *m, 
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height,
        U32 flag,
        S32 highlight_index,
        void (*highlight_callback)(S32 index),
        gui_horizontal_select_item_struct *items,
        S32 n_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((highlight_index >= 0) && (highlight_index < n_item));
    m->x = x;
    m->y = y;
    m->width = width;
    m->height = height;
    m->n_items = n_item;
    m->highlighted_item = highlight_index;
    m->highlight_callback = highlight_callback;
    gui_horizontal_select_set_current_theme(m);
    m->hide_callback = NULL;
    m->items = items;
    m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_NONE;
    
    m->flags = (UI_HORIZONTAL_SELECT_LOOP) | flag;
#ifndef __MMI_FTE_SUPPORT__
    m->flags |= UI_HORIZONTAL_SELECT_TEXT_ALIGN_CENTER;
#endif
    
#ifdef __MMI_TOUCH_SCREEN__
    memset(&m->pen_state, 0, sizeof(gui_horizontal_select_pen_state_struct));
#endif 
    gui_horizontal_select_set_arrow_state(m);

    if (m->flags & UI_HORIZONTAL_SELECT_FOCUSED_STATE)
    {
        if (current_horizontal_select != NULL)
        {
            gui_scrolling_text_stop(&(current_horizontal_select->scroll_text));
        }
        
        current_horizontal_select = m;
        if (m->flags & UI_HORIZONTAL_SELECT_REGISTER_KEY_HANDLER)
        {
            gui_horizontal_select_register_key_handler();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_resize
 * DESCRIPTION
 *  Resize the horizontal select menu.
 * PARAMETERS
 *  m           [IN]        horizontal select menu object
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_resize(gui_horizontal_select_struct *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_move
 * DESCRIPTION
 *  Move the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_move(gui_horizontal_select_struct *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_left_key_down_handler
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_left_key_down_handler(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_LEFT;
    gui_horizontal_select_redraw(m);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_left_key_up_handler
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_left_key_up_handler(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_NONE;
    ret = gui_horizontal_select_goto_previous_item(m);
    gui_horizontal_select_redraw(m);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_right_key_down_handler
 * DESCRIPTION
 *  The handle of right arrow key down.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_right_key_down_handler(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_RIGHT;
    gui_horizontal_select_redraw(m);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_right_key_up_handler
 * DESCRIPTION
 *  The handle of right arrow key up.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_right_key_up_handler(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_NONE;
    ret = gui_horizontal_select_goto_next_item(m);
    gui_horizontal_select_redraw(m);
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_register_key_handler
 * DESCRIPTION
 *  register key handlers for horizontal select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_register_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     /* key rule. 09.10.17 */
    SetKeyHandler(gui_horizontal_select_left_key_down, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_horizontal_select_right_key_down, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    
    SetKeyHandler(gui_horizontal_select_left_key_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_horizontal_select_right_key_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(gui_horizontal_select_left_key_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(gui_horizontal_select_right_key_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_set_flag
 * DESCRIPTION
 *  Set the flag of horizontal select
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  flag    [IN]        the flag of be set
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_set_flag(gui_horizontal_select_struct *m, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags = flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_get_flag
 * DESCRIPTION
 *  Get the flag of horizontal select
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  The flag of horizontal selector
 *****************************************************************************/
U32 gui_horizontal_select_get_flag(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return m->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_item
 * DESCRIPTION
 *  Go to the item by its index.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_goto_item(gui_horizontal_select_struct *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_index;
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_index = m->highlighted_item;
    ret = MMI_FALSE;
    
    if ((i < 0) || (i > m->n_items - 1))
    {
        return ret;
    }
    
    if (i == m->highlighted_item)
    {
        return ret;
    }
    
    m->highlighted_item = i;
    m->flags |= UI_HORIZONTAL_SELECT_HIGHLIGHT_ITEM_CHANGE;
    
    if (m->highlight_callback)
    {
        m->highlight_callback(m->highlighted_item);
    }
    gui_scrolling_text_stop(&(m->scroll_text));

    if (m->highlighted_item != highlight_index)
    {
        ret = MMI_TRUE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_goto_next_item(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop_flag = 0;
    MMI_BOOL ret;
    S32 highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_index = m->highlighted_item;
    ret = MMI_FALSE;
    
    if (m->highlighted_item >= (m->n_items - 1))
    {
        if (m->flags & UI_HORIZONTAL_SELECT_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return ret;
        }
    }
    
    if (loop_flag)
    {
        m->highlighted_item = 0;
    }
    else
    {
        m->highlighted_item++;
    }

    if (m->get_next_callback)
    {
        m->get_next_callback(&(m->items[m->highlighted_item]));
    }
    m->flags |= UI_HORIZONTAL_SELECT_HIGHLIGHT_ITEM_CHANGE;
    
    if (m->highlight_callback)
    {
        m->highlight_callback(m->highlighted_item);
    }
    
    gui_scrolling_text_stop(&(m->scroll_text));
    if (loop_flag || (m->highlighted_item != highlight_index))
    {
        ret = MMI_TRUE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_goto_previous_item(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop_flag = 0;
    S32 highlight_index;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_index = m->highlighted_item;
    ret = MMI_FALSE;
    
    if (m->highlighted_item <= 0)
    {
        if (m->flags & UI_HORIZONTAL_SELECT_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return ret;
        }
    }
    
    if (loop_flag)
    {
        m->highlighted_item = m->n_items - 1;
    }
    else
    {
        m->highlighted_item--;
    }

    if (m->get_prev_callback)
    {
        m->get_prev_callback(&(m->items[m->highlighted_item]));
    }
    m->flags |= UI_HORIZONTAL_SELECT_HIGHLIGHT_ITEM_CHANGE;
    
    if (m->highlight_callback)
    {
        m->highlight_callback(m->highlighted_item);
    }
    
    gui_scrolling_text_stop(&(m->scroll_text));
    
    if (loop_flag || (m->highlighted_item != highlight_index))
    {
        ret = MMI_TRUE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_first_item
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_goto_first_item(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_index;
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_index = m->highlighted_item;
    ret = MMI_FALSE;
    
    if (m->highlighted_item == 0)
    {
        return ret;
    }
    
    m->highlighted_item = 0;
    m->flags |= UI_HORIZONTAL_SELECT_HIGHLIGHT_ITEM_CHANGE;
    
    if (m->highlight_callback)
    {
        m->highlight_callback(m->highlighted_item);
    }

    gui_scrolling_text_stop(&(m->scroll_text));
    if (m->highlighted_item != highlight_index)
    {
        ret = MMI_TRUE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_goto_last_item
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_goto_last_item(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_index;
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight_index = m->highlighted_item;
    ret = MMI_FALSE;
    
    if (m->highlighted_item == (m->n_items - 1))
    {
        return ret;
    }
    m->highlighted_item = (m->n_items - 1);
    m->flags |= UI_HORIZONTAL_SELECT_HIGHLIGHT_ITEM_CHANGE;
    
    if (m->highlight_callback)
    {
        m->highlight_callback(m->highlighted_item);
    }
    
    gui_scrolling_text_stop(&(m->scroll_text));

    if (m->highlighted_item != highlight_index)
    {
        ret = MMI_TRUE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_register_get_data_callback
 * DESCRIPTION
 *  Register get data callback for horizontal selector
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_register_get_data_callback(
        gui_horizontal_select_struct *m,
        void (*get_prev_callback)(gui_horizontal_select_item_struct *item),
        void (*get_current_callback)(gui_horizontal_select_item_struct *item),
        void (*get_next_callback)(gui_horizontal_select_item_struct *item))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->get_prev_callback = get_prev_callback,
    m->get_current_callback = get_current_callback;
    m->get_next_callback = get_next_callback;
    
    if (m->get_current_callback)
    {
        m->get_current_callback(&(m->items[m->highlighted_item]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_show
 * DESCRIPTION
 *  Show the horizontal select menu.
 * PARAMETERS
 *  m       [IN]        horizontal select menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_show(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 center_x1, center_x2;
#ifdef __MMI_FTE_SUPPORT__
    UI_filled_area *select_background_filler = NULL;
    PU8 select_background_image = NULL;
#else
    UI_filled_area *f = m->theme->background_filler;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_FTE_SUPPORT__
    if (m->flags & UI_HORIZONTAL_SELECT_FOCUSED_STATE)
    {
        if(m->flags & UI_HORIZONTAL_SELECT_MULTI_AREA)
        {
            select_background_image = current_MMI_theme->inline_item_color_select_highlighted_bg_image;
        }
        else
        {
            select_background_filler = m->theme->select_focused_background;
        }
    }
    else
    {
        if(m->flags & UI_HORIZONTAL_SELECT_MULTI_AREA)
        {
            select_background_image = current_MMI_theme->inline_item_color_select_unhighlighted_bg_image;
        }
        else
        {
            select_background_filler = m->theme->select_background;
        }
    }
#endif
    mmi_frm_dss_set_menu_highlight(MMI_SCREEN_HIGHLIGHT_FOR_HOR_SELECT);
    
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;
#if defined(__MMI_UI_LIST_GRID_LINE__) && !defined (__MMI_FTE_SUPPORT__)
    y1 ++;
    y2 --;
#endif
    gdi_layer_push_clip();
    if (m->flags & UI_HORIZONTAL_SELECT_USE_PRESET_CLIP)
    {
        gui_set_clip_preset(x1, y1, x2, y2);
    }
    else
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
    }
    
    if (m->hide_callback)
    {
        m->hide_callback(x1, y1, x2, y2);
    }
    else
    {
    #ifdef __MMI_FTE_SUPPORT__
        if (m->flags & UI_HORIZONTAL_SELECT_MULTI_AREA)
        {
            gdi_image_draw_resized(x1, y1, x2 - x1 + 1, y2 - y1 + 1, select_background_image);
        }
        else
        {
            gui_draw_filled_area(x1, y1, x2, y2,select_background_filler);
        }
    #else
        if (!m->flags & UI_HORIZONTAL_SELECT_NOT_CLEAR_BACKGROUND)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
        gui_horizontal_select_show_arrow(
            m, 
            &center_x1, 
            &center_x2, 
            MMI_FALSE);
        gui_draw_filled_area(x1 + center_x1, y1, x1 + center_x2, y2, f);
    #endif
    }
    
    if ((m->n_items == 0) || (m->highlighted_item < 0) || (m->highlighted_item > (m->n_items - 1)))
    {
        gdi_layer_pop_clip();
        return;
    }
    
    gui_horizontal_select_show_arrow(
        m, 
        &center_x1, 
        &center_x2, 
        MMI_TRUE);

    x1 = m->x + center_x1;
    if (center_x2 == 0)
    {
        x2 = m->x + m->width - 1;
        center_x2 = m->width - 1;
    }
    else
    {
        x2 = m->x + center_x2;
    }
    y1 = m->y;
    y2 = m->y + m->height - 1;
    if (m->flags & UI_HORIZONTAL_SELECT_USE_PRESET_CLIP)
    {
        gui_set_clip_preset(x1, y1, x2, y2);
    }
    else
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
    }

    if (m->flags & UI_HORIZONTAL_SELECT_MULTI_AREA)
    {
        gui_horizontal_select_show_multi_area(m, center_x1, center_x2);
    }
    else if((m->flags & UI_HORIZONTAL_SELECT_AREA_TEXT_ORDER) ||
            (m->flags & UI_HORIZONTAL_SELECT_TEXT_AREA_ORDER))
    {
        gui_horizontal_select_show_text_area(m, center_x1, center_x2);
    }
    else
    {
        gui_horizontal_select_show_text(m, center_x1, center_x2);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_register_hide_callback
 * DESCRIPTION
 *  Set the function used to clear background.
 *  The function is typically used when UI_LIST_MENU_DISABLE_BACKGROUND is set.
 * 
 *  (Set 'clear_bg_function' to NULL to disable the callback)
 * PARAMETERS
 *  m                   [IN]        horizontal select menu object
 *  clear_bg_function   [IN]        callback to clear background
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_register_hide_callback(
        gui_horizontal_select_struct *m,
        void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_close
 * DESCRIPTION
 *  Close the horizontal select.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_close(gui_horizontal_select_struct *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&(m->scroll_text));
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_get_history
 * DESCRIPTION
 *  Close the horizontal select.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_get_history(gui_horizontal_select_struct *m, gui_horizontal_select_history_struct *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->first_display_index = m->first_display_index;
    h->flag = m->flags;
    h->highlight_index = m->highlighted_item;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_set_history
 * DESCRIPTION
 *  Close the horizontal select.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_select_set_history(gui_horizontal_select_struct *m, gui_horizontal_select_history_struct *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->first_display_index = h->first_display_index;
    m->flags = h->flag;
    m->highlighted_item = h->highlight_index;
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_select_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the horizontal select menu.
 * PARAMETERS
 *  m               [IN]        horizontal select menu object     
 *  pen_event       [IN]        pen event type
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  select_event    [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_horizontal_select_translate_pen_event(
            gui_horizontal_select_struct *m,
            mmi_pen_event_type_enum pen_event,
            S16 x,
            S16 y,
            gui_horizontal_select_pen_enum *select_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 in_left_region = 0, in_right_region = 0;
    gui_horizontal_select_pen_state_struct *pen_state;
    S32 center_x1, center_x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_show_arrow(m, &center_x1, &center_x2, MMI_FALSE);
    pen_state = &m->pen_state;
    ret = MMI_TRUE;
    *select_event = GUI_HORIZONTAL_SELECT_PEN_NONE;

    if (PEN_CHECK_BOUND(
            x,
            y,
            m->x + pen_state->left_region_x,
            m->y + pen_state->left_region_y,
            pen_state->left_region_width,
            pen_state->left_region_height))
    {
        in_left_region = 1;
    }
    else if (PEN_CHECK_BOUND(
                x,
                y,
                m->x + pen_state->right_region_x,
                m->y + pen_state->right_region_y,
                pen_state->right_region_width,
                pen_state->right_region_height))
    {
        in_right_region = 1;
    }

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            pen_state->pen_down_left_arrow = 0;
            pen_state->pen_down_right_arrow = 0;
            if (in_left_region)
            {
                pen_state->pen_down_left_arrow = 1;
                m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_LEFT;
                gui_horizontal_select_redraw(m);
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            else if (in_right_region)
            {
                pen_state->pen_down_right_arrow = 1;
                m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_RIGHT;
                gui_horizontal_select_redraw(m);
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            else if (PEN_CHECK_BOUND(x, y, m->x + center_x1, m->y, center_x2 - center_x1 + 1, m->height))
            {
                if (m->flags & UI_HORIZONTAL_SELECT_MULTI_AREA)
                {
                    S32 color_x1, color_x2;
                    S32 index;
                    S32 color_width, color_height;

                    color_x1 = m->x + center_x1 + GUI_HORIZONTAL_SELECT_COLOR_H_GAP;
                    if (m->flags & UI_HORIZONTAL_SELECT_ZONE_IS_COLOR)
                    {
                        color_width = m->height - (GUI_HORIZONTAL_SELECT_COLOR_V_GAP << 1);
                    }
                    else
                    {
                        gdi_image_get_dimension(
                            m->items[m->highlighted_item]._u.icon,
                            &color_width, 
                            &color_height);
                    }
                    
                    for (index = 0; index < m->display_count; index++)
                    {
                        color_x2 = color_x1 + color_width - 1;
                        if (PEN_CHECK_BOUND(x, y, color_x1, m->y, color_width, m->height))
                        {
                            m->highlighted_item = m->first_display_index + index;
                            if (m->highlight_callback)
                            {
                                m->highlight_callback(m->highlighted_item);
                            }
                            
                            break;
                        }
                        color_x1 = color_x2 + GUI_HORIZONTAL_SELECT_COLOR_H_GAP;
                    }
                }
                else
                {
                    m->pen_state.pen_down_center_area = 1;
                }
            }
            else if (!PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
            {
                ret = MMI_FALSE;
            }

            break;

        case MMI_PEN_EVENT_UP:
            if (pen_state->pen_down_left_arrow)
            {
                if (in_left_region)
                {
                    *select_event = GUI_HORIZONTAL_SELECT_PEN_PREV;
                    gui_horizontal_select_goto_previous_item(m);
                }
            }
            else if (pen_state->pen_down_right_arrow)
            {
                if (in_right_region)
                {
                    *select_event = GUI_HORIZONTAL_SELECT_PEN_NEXT;
                    gui_horizontal_select_goto_next_item(m);
                }
            }

            m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_NONE;
            gui_horizontal_select_redraw(m);
            
            break;

        case MMI_PEN_EVENT_MOVE:
            if (pen_state->pen_down_left_arrow)
            {
                if (in_left_region)
                {
                    if (m->clicked_state != GUI_HORIZONTAL_SELECT_CLICKED_LEFT)
                    {
                        m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_LEFT;
                        gui_horizontal_select_redraw(m);
                    }
                }
                else
                {
                    if (m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_LEFT)
                    {
                        m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_NONE;
                        gui_horizontal_select_redraw(m);
                    }
                }
            }
            else if (pen_state->pen_down_right_arrow)
            {
                if (in_right_region)
                {
                    if (m->clicked_state != GUI_HORIZONTAL_SELECT_CLICKED_RIGHT)
                    {
                        m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_RIGHT;
                        gui_horizontal_select_redraw(m);
                    }
                }
                else
                {
                    if (m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_RIGHT)
                    {
                        m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_RIGHT;
                        gui_horizontal_select_redraw(m);
                    }
                }
            }

            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            if (m->pen_state.pen_down_center_area)
            {
                if (PEN_CHECK_BOUND(x, y, m->x + center_x1, m->y, center_x2 - center_x1 + 1, m->height))
                {
                    *select_event = GUI_HORIZONTAL_SELECT_PEN_CENTER_AREA;
                }
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            if ((m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_LEFT) ||
                (m->clicked_state == GUI_HORIZONTAL_SELECT_CLICKED_RIGHT))
            {
                m->clicked_state = GUI_HORIZONTAL_SELECT_CLICKED_NONE;
                gui_horizontal_select_redraw(m);
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 



