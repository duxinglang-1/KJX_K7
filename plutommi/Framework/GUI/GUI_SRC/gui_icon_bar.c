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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "kal_release.h"
#include "GlobalConstants.h"
#include "PixcomFontEngine.h"
#include "MMI_trc_Int.h"

#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "ScrMemMgrGprot_Int.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "gui_data_types.h"
#include "gui_icon_bar.h"
#include "gui_font_size.h"
#include "Wgui_categories_util.h"
#include "wgui_inputs.h"


#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/

/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */
static gui_icon_bar_struct* current_icon_bar_pointer = NULL;

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */
static void gui_icon_bar_draw_arrow(
             gui_icon_bar_struct *icon_bar,
             gui_icon_bar_arrow_enum arrow_type);
static void gui_icon_bar_default_hide_function(S32 x1, S32 y1, S32 x2, S32 y2);
static void gui_icon_bar_calculate_display_count(gui_icon_bar_struct *icon_bar);
static void gui_icon_bar_calculate_item_position(gui_icon_bar_struct *icon_bar);
static void gui_icon_bar_set_arrow_state(gui_icon_bar_struct *icon_bar);
static void gui_icon_bar_set_key_handler(void);
static void gui_icon_bar_clear_key_handler(void);
static void gui_icon_bar_prev_arrow_key_up_handler(void);
static void gui_icon_bar_prev_arrow_key_down_handler(void);
static void gui_icon_bar_next_arrow_key_up_handler(void);
static void gui_icon_bar_next_arrow_key_down_handler(void);
static void gui_icon_bar_ok_key_up_handler(void);
static void gui_icon_bar_draw_highlight(
             gui_icon_bar_struct* icon_bar,
             U32 index);
static void gui_icon_bar_erase_highlight(
             gui_icon_bar_struct* icon_bar,
             U32 index);
static void gui_icon_bar_draw_item(
             gui_icon_bar_struct* icon_bar,
             U32 item_index);
static void gui_icon_bar_erase_item(
             gui_icon_bar_struct* icon_bar,
             U32 item_index);
static void gui_icon_bar_draw_hint(void);
static void gui_icon_bar_erase_hint(void);
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL gui_icon_bar_translate_arrow_position(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y,
                 gui_icon_bar_arrow_enum *arrow);
static MMI_BOOL gui_icon_bar_translate_item_position(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y,
                 U32 *index);
static MMI_BOOL gui_icon_bar_pen_down_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y);
static MMI_BOOL gui_icon_bar_pen_move_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y);
static MMI_BOOL gui_icon_bar_pen_up_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y);
static MMI_BOOL gui_icon_bar_pen_abort_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y);
#endif /* __MMI_TOUCH_SCREEN__ */
/*****************************************************************************
 * Local Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_draw_arrow
 * DESCRIPTION
 *  show arrow icon of icon_bar
 * PARAMETERS
 *  icon_bar       [IN]     pointer of icon_bar
 *  arrow_type     [IN]     left/right arrow 
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_draw_arrow(
             gui_icon_bar_struct *icon_bar,
             gui_icon_bar_arrow_enum arrow_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 arrow_x, arrow_y, arrow_width, arrow_height;
    S32 width = 0, height = 0, offset = 0;
    gdi_handle abm_layer = GDI_NULL_HANDLE;
    S32 layer_offset_x = 0, layer_offset_y = 0;
    S32 clip_x, clip_y, clip_width, clip_height;
    gui_icon_bar_arrow_icon_struct *temp_arrow = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    MMI_DBG_ASSERT(arrow_type == GUI_ICON_BAR_ARROW_PREV ||
                   arrow_type == GUI_ICON_BAR_ARROW_NEXT);

    if (arrow_type == GUI_ICON_BAR_ARROW_PREV)
    {
        temp_arrow = &(icon_bar->prev_arrow);
    }
    else
    {
        temp_arrow = &(icon_bar->next_arrow);
    }

    if (temp_arrow->normal_icon == NULL ||
        temp_arrow->down_icon == NULL)
    {
        return;
    }

    if (temp_arrow->state == GUI_ICON_BAR_ICON_STATE_DISABLED ||
        temp_arrow->state == GUI_ICON_BAR_ICON_STATE_START)
    {
        return;
    }

    if (temp_arrow->normal_icon != NULL &&
        temp_arrow->down_icon != NULL)
    {
        gdi_image_get_dimension(
            temp_arrow->normal_icon,
            &arrow_width,
            &arrow_height);
    }
    if (icon_bar->highlight != NULL)
    {
        /* calculate highlight's position */
        gdi_image_get_dimension(icon_bar->highlight, &width, &height);
    }
    else
    {
        width = icon_bar->item_width;
        height = icon_bar->item_height;
    }

    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(icon_bar->target_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    }
    gdi_layer_push_clip();
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        clip_width = icon_bar->border_gap;
        clip_height = icon_bar->height;
        clip_y = icon_bar->y;
        arrow_y = icon_bar->y + icon_bar->height / 2 - arrow_height / 2;
        offset = (width - icon_bar->item_width) / 2;
        if (arrow_type == GUI_ICON_BAR_ARROW_PREV)
        {
            clip_x = icon_bar->x;
        }
        else
        {
            clip_x = icon_bar->x + icon_bar->width - icon_bar->border_gap;            
        }
        arrow_x = clip_x + (icon_bar->border_gap - offset) / 2 - arrow_width / 2;
        if (arrow_x < clip_x)
        {
            arrow_x = clip_x;
        }
    }
    else
    {
        clip_width = icon_bar->width;
        clip_height = icon_bar->border_gap;
        clip_x = icon_bar->x;
        arrow_x = icon_bar->x + icon_bar->width / 2 - arrow_width / 2;
        offset = (height - icon_bar->item_height) / 2;
        if (arrow_type == GUI_ICON_BAR_ARROW_PREV)
        {
            clip_y = icon_bar->y;
        }
        else
        {
            clip_y = icon_bar->y + icon_bar->height - icon_bar->border_gap;            
        }
        arrow_y = clip_y + (icon_bar->border_gap - offset) / 2 - arrow_height / 2;
        if (arrow_y < clip_y)
        {
            arrow_y = clip_y;
        }
    }
    gdi_layer_set_clip(
        clip_x - layer_offset_x,
        clip_y - layer_offset_y,
        clip_x + clip_width - 1 - layer_offset_x,
        clip_y + clip_height - 1 - layer_offset_y);
    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        abm_layer = gdi_set_alpha_blending_source_layer(icon_bar->abm_layer);
    }
    if (temp_arrow->state == GUI_ICON_BAR_ICON_STATE_KEY_DOWN ||
        temp_arrow->state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN ||
        temp_arrow->state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN)
    {
        gdi_image_draw(
            arrow_x - layer_offset_x,
            arrow_y - layer_offset_y,
            temp_arrow->down_icon);
    }
    else
    {
        gdi_image_draw(
            arrow_x - layer_offset_x,
            arrow_y - layer_offset_y,
            temp_arrow->normal_icon);
    }

    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    gdi_layer_pop_clip();
    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_default_hide_function
 * DESCRIPTION
 *  use transparent color to redraw icon_bar bg  
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_default_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;
    U32 alpha, r, g, b;
    gui_icon_bar_struct* icon_bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_get_alpha_blending_source_layer(&abm_layer);
        gdi_act_color_to_rgb(&alpha, &r, &g, &b, GDI_COLOR_TRANSPARENT);
        gdi_effect_alpha_blending_rect(abm_layer, x1, y1, x2, y2, 0, r, g, b); 
    }
    else if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
             icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_act_color_to_rgb(&alpha, &r, &g, &b, GDI_COLOR_TRANSPARENT);
        gdi_effect_alpha_blending_rect(icon_bar->abm_layer, x1, y1, x2, y2, 0, r, g, b);
    }
    else
    {
        gdi_draw_solid_rect(
            x1,
            y1,
            x2,
            y2,
            GDI_COLOR_BLACK);
    }

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_arrow_state
 * DESCRIPTION
 *  This API used to set the left/right arrow state when component create or 
 *  resize
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_set_arrow_state(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
    icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
    if (icon_bar->count > icon_bar->display_count)
    {
        if (icon_bar->first_displayed_item > 0)
        {
            icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        }
        if ((icon_bar->first_displayed_item + icon_bar->focused_item) <
            (icon_bar->count - 1))
        {
            icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_calculate_display_count
 * DESCRIPTION
 *  This API used to calculate every display count
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_calculate_display_count(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 display_dimension;
    S32 need_dimension, item_dimension;
    U32 item_gap;
    U32 align_flag = GUI_ICON_BAR_FLAG_ALIGN_INIT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        item_dimension = icon_bar->item_width;
        display_dimension = icon_bar->width;
    }
    else
    {
        item_dimension = icon_bar->item_height;
        display_dimension = icon_bar->height;
    }
    /* we will first calculate whether all items can put in one screen */
    if (icon_bar->auto_arrange_item == MMI_TRUE)
    {
        need_dimension = item_dimension * icon_bar->count +
                     (icon_bar->count - 1) * GUI_ICON_BAR_MIN_ITEM_GAP;
    }
    else
    {
        need_dimension = item_dimension * icon_bar->count +
                     (icon_bar->count - 1) * icon_bar->item_gap;
    }

    /* we can not put all items in one screen, we will use
     * left/right arrows to change focus of every item
     */
    if (display_dimension < need_dimension)
    {
        /* calculate the display count */
        if (display_dimension < GUI_ICON_BAR_BORDER_GAP * 2)
        {
            icon_bar->display_count = 0;
            return;
        }
        display_dimension = display_dimension - GUI_ICON_BAR_BORDER_GAP * 2;
        if (icon_bar->auto_arrange_item == MMI_TRUE)
        {
            item_gap = (U32)(item_dimension * GUI_ICON_BAR_GOLDEN_SECTION);
            icon_bar->display_count = (display_dimension + item_gap) /
                                      (item_dimension + item_gap);
        }
        else
        {
            icon_bar->display_count = (display_dimension + icon_bar->item_gap) /
                                      (item_dimension + icon_bar->item_gap);
        }

        if (icon_bar->display_count == 0)
        {
            return;
        }
        /* since item count is more than display count, align type will
         * be set GUI_ICON_BAR_ALIGN_BY_EQUIDISTANCE by default
         */
        align_flag = GUI_ICON_BAR_FLAG_EQUIDISTANCE_ALIGN;
    }
    else
    {
        /* all items can input in one screen */
        icon_bar->display_count = icon_bar->count;
        if (icon_bar->auto_arrange_item == MMI_TRUE)
        {
            if (icon_bar->display_count == 1)
            {
                /* we will align this item in head-align by default */
                align_flag = GUI_ICON_BAR_FLAG_HEAD_ALIGN;
            }
            else
            {
                /* calculate the gap between item */
                item_gap = (display_dimension - item_dimension * icon_bar->display_count) /
                           (icon_bar->display_count - 1);
                if (item_gap > (U32)item_dimension * GUI_ICON_BAR_GOLDEN_SECTION)
                {
                    align_flag = GUI_ICON_BAR_FLAG_HEAD_ALIGN;
                }
                else
                {
                    align_flag = GUI_ICON_BAR_FLAG_EQUIDISTANCE_ALIGN;
                }
            }
        }
    }

    /* set align type if align_type is not be set */
    if ((icon_bar->flags & GUI_ICON_BAR_FLAG_ALIGN_MASK) ==
        GUI_ICON_BAR_FLAG_ALIGN_INIT)
    {
        icon_bar->flags |= align_flag;
    }
    else if ((icon_bar->auto_arrange_item == MMI_TRUE) && !(icon_bar->flags & GUI_ICON_BAR_FLAG_SETTED_ALIGN))
    {
        /* change the align mode to a suitable one */
        icon_bar->flags &= ~GUI_ICON_BAR_FLAG_ALIGN_MASK;
        icon_bar->flags |= align_flag;
    }

    /* set prev/next arrow's state */
    gui_icon_bar_set_arrow_state(icon_bar);
    gui_icon_bar_calculate_item_position(icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_calculate_item_position
 * DESCRIPTION
 *  This API used to calculate every item's position
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_calculate_item_position(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_gap, border_gap = 0;
    S32 display_dimension, item_dimension;
    S32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->display_count == 0)
    {
        return;
    }

    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        display_dimension = icon_bar->width;
        item_dimension = icon_bar->item_width;
    }
    else
    {
        display_dimension = icon_bar->height;
        item_dimension = icon_bar->item_height;
    }

    if (icon_bar->count > icon_bar->display_count)
    {
        display_dimension = display_dimension - GUI_ICON_BAR_BORDER_GAP * 2;
    }

    switch (icon_bar->flags & GUI_ICON_BAR_FLAG_ALIGN_MASK)
    {
        case GUI_ICON_BAR_FLAG_HEAD_ALIGN:
        case GUI_ICON_BAR_FLAG_CENTER_ALIGN:
        case GUI_ICON_BAR_FLAG_END_ALIGN:
            {
                if (icon_bar->auto_arrange_item == MMI_TRUE)
                {
                    item_gap = (U32)(item_dimension * GUI_ICON_BAR_GOLDEN_SECTION);
                }
                else
                {
                    item_gap = icon_bar->item_gap;
                }
                temp = item_gap * (icon_bar->display_count - 1) +
                       item_dimension * icon_bar->display_count;

                /* if display_dimension can contain display_count items */
                if (temp <= display_dimension)
                {
                    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HEAD_ALIGN)
                    {
                        if (icon_bar->count > icon_bar->display_count)
                        {
                            border_gap = GUI_ICON_BAR_BORDER_GAP;
                        }
                        /* if icon_bar->count <= icon_bar->display_count,
                         * border_gap is 0 in init value.
                         */
                    }
                    else if (icon_bar->flags & GUI_ICON_BAR_FLAG_END_ALIGN)
                    {
                        if (icon_bar->count > icon_bar->display_count)
                        {
                            border_gap = GUI_ICON_BAR_BORDER_GAP;
                        }
                        else
                        {
                            border_gap = display_dimension - temp;
                        }
                    }
                    else
                    {
                        border_gap = display_dimension / 2 - temp / 2;
                    }
                    break;
                }
            }
        /* we do not use break here, because if display_dimension can not contain
         * temp width, we still need use equidistance align though it's align
         * type is head align, center align or end align
         */

        case GUI_ICON_BAR_FLAG_EQUIDISTANCE_ALIGN:
            {                
                if (icon_bar->count > icon_bar->display_count)
                {
                    border_gap = GUI_ICON_BAR_BORDER_GAP;
                    /* if icon_bar->count <= icon_bar->display_count,
                     * border_gap is 0 in init value.
                     */
                }
                if (icon_bar->display_count > 1)
                {
                    item_gap = (display_dimension -
                                (icon_bar->display_count *
                                 item_dimension)) /
                               (icon_bar->display_count - 1);
                }                         
                else /* if is only 1 item */
                {
                    item_gap = GUI_ICON_BAR_STANDARD_ITEM_GAP;
                    border_gap = display_dimension / 2 - item_dimension / 2;
                }
            }
            break;

        default:
            {
                if (icon_bar->display_count > 1)
                {
                    item_gap = (display_dimension -
                                (icon_bar->display_count *
                                 item_dimension)) /
                                (icon_bar->display_count - 1);
                }
                else
                {
                    item_gap = 0;
                }
            }
            break;
    }
    icon_bar->item_gap = item_gap;
    icon_bar->border_gap = border_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_set_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;
    U16 prev_key_code, next_key_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_KEY_EVENT))
    {
        return;
    }
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        prev_key_code = KEY_LEFT_ARROW;
        next_key_code = KEY_RIGHT_ARROW;
    }
    else
    {
        prev_key_code = KEY_UP_ARROW;
        next_key_code = KEY_DOWN_ARROW;
    }
    SetKeyHandler(gui_icon_bar_prev_arrow_key_up_handler, prev_key_code, KEY_EVENT_UP);
    SetKeyHandler(gui_icon_bar_prev_arrow_key_down_handler, prev_key_code, KEY_EVENT_DOWN);
    SetKeyHandler(gui_icon_bar_next_arrow_key_up_handler, next_key_code, KEY_EVENT_UP);
    SetKeyHandler(gui_icon_bar_next_arrow_key_down_handler, next_key_code, KEY_EVENT_DOWN);
    SetKeyHandler(gui_icon_bar_ok_key_up_handler, KEY_ENTER, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_clear_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_clear_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;
    U16 prev_key_code, next_key_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_KEY_EVENT))
    {
        return;
    }
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        prev_key_code = KEY_LEFT_ARROW;
        next_key_code = KEY_RIGHT_ARROW;
    }
    else
    {
        prev_key_code = KEY_UP_ARROW;
        next_key_code = KEY_DOWN_ARROW;
    }
    ClearKeyHandler(prev_key_code, KEY_EVENT_UP);
    ClearKeyHandler(prev_key_code, KEY_EVENT_DOWN);
    ClearKeyHandler(next_key_code, KEY_EVENT_UP);
    ClearKeyHandler(next_key_code, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_prev_arrow_key_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_prev_arrow_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return;
    }

    if (icon_bar->focused_item_state != GUI_ICON_BAR_ICON_STATE_KEY_DOWN)
    {
        return;
    }

    icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
    gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
    
    if (icon_bar->count > icon_bar->display_count)
    {
        if (icon_bar->focused_item == 0 &&
            icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_KEY_DOWN)
        {
            icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
            gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
        }
    }

    gdi_layer_blt_previous(
        icon_bar->x,
        icon_bar->y,
        icon_bar->x + icon_bar->width - 1,
        icon_bar->y + icon_bar->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_prev_arrow_key_down_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_prev_arrow_key_down_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;
//    MMI_BOOL result;
    U8 *normal_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *down_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *disabled_content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *text_of_description[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return;
    }

    /* if focused item is not normal state, no action */
    if (icon_bar->focused_item_state != GUI_ICON_BAR_ICON_STATE_NORMAL)
    {
        return;
    }
    else
    {
        if (icon_bar->dynamic_update_handler != NULL)
        {
            /*result = */icon_bar->dynamic_update_handler(
                         icon_bar->first_displayed_item,
                         icon_bar->display_count,
                         (U8**)&normal_icon,
                         (U8**)&down_icon,
                         (U8**)&content_icon,
                         (U8**)&disabled_content_icon,
                         (U8**)&text_of_description);
           // MMI_DBG_ASSERT(result == MMI_TRUE);
            for (i = 0; i < icon_bar->display_count; i++)
            {
                icon_bar->item[icon_bar->first_displayed_item + i].normal_icon =
                    normal_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].down_icon =
                    down_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].content_icon =
                    content_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].disabled_content_icon =
                    disabled_content_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].text_of_description =
                    text_of_description[i];
            }
        }

        if (icon_bar->need_draw_hint)// == MMI_TRUE)
        {
            gui_cancel_timer(gui_icon_bar_draw_hint);
            icon_bar->need_draw_hint = MMI_FALSE;
        }
        if (icon_bar->need_erase_hint)// == MMI_TRUE)
        {
            gui_icon_bar_erase_hint();
            icon_bar->need_erase_hint = MMI_FALSE;
        }

        /* if focused item is the first item of icon_bar */
        if ((icon_bar->first_displayed_item + icon_bar->focused_item) == 0)
        {
            icon_bar->focused_item = icon_bar->display_count - 1;
            icon_bar->first_displayed_item = icon_bar->count - 1 - icon_bar->focused_item;
            icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;
            if (icon_bar->display_count < icon_bar->count)
            {
                icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
            }
            gui_icon_bar_show(icon_bar);
        }
        else
        {
            /* if focused item is not the first one, first displayed item not change,
             * just redraw highlight and unhighlight item
             */
            if (icon_bar->focused_item > 0)
            {
                /* unhighlight current focused item */
                gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);

                /* focused item move one item left */
                icon_bar->focused_item -= 1;
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;

                gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item + 1);                

                /* highlight current focused item */
                gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
                gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
            }
            else
            {
                icon_bar->first_displayed_item -= 1;
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;
                if (icon_bar->count > icon_bar->display_count)
                {
                    icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                    if (icon_bar->first_displayed_item == 0)
                    {
                        icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
                    }
                    else
                    {
                        icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;
                    }
                }
                gui_icon_bar_show(icon_bar);
            }
        }
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);
            
        if (icon_bar->highlight_handler != NULL)
        {
            icon_bar->highlight_handler(
                icon_bar->first_displayed_item + icon_bar->focused_item);
        }
        if (icon_bar->idle_display_handler != NULL)
        {
            icon_bar->idle_display_handler(
                icon_bar->first_displayed_item + icon_bar->focused_item);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_next_arrow_key_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_next_arrow_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return;
    }

    if (icon_bar->focused_item_state != GUI_ICON_BAR_ICON_STATE_KEY_DOWN)
    {
        return;
    }

    icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
    gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
    
    if (icon_bar->count > icon_bar->display_count)
    {
        if (icon_bar->focused_item == (icon_bar->display_count - 1) &&
            icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_KEY_DOWN)
        {
            icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
            gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
        }
    }

    gdi_layer_blt_previous(
        icon_bar->x,
        icon_bar->y,
        icon_bar->x + icon_bar->width - 1,
        icon_bar->y + icon_bar->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_next_arrow_key_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_next_arrow_key_down_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;
//    MMI_BOOL result;
    U8 *normal_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *down_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *disabled_content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *text_of_description[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return;
    }
    /* if focused item is not normal state, no action */
    if (icon_bar->focused_item_state != GUI_ICON_BAR_ICON_STATE_NORMAL)
    {
        return;
    }
    else
    {
        /* update item's content */
        if (icon_bar->dynamic_update_handler != NULL)
        {
            /*result = */icon_bar->dynamic_update_handler(
                         icon_bar->first_displayed_item,
                         icon_bar->display_count,
                         (U8**)&normal_icon,
                         (U8**)&down_icon,
                         (U8**)&content_icon,
                         (U8**)&disabled_content_icon,
                         (U8**)&text_of_description);
            //MMI_DBG_ASSERT(result == MMI_TRUE);
            for (i = 0; i < icon_bar->display_count; i++)
            {
                icon_bar->item[icon_bar->first_displayed_item + i].normal_icon =
                    normal_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].down_icon =
                    down_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].content_icon =
                    content_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].disabled_content_icon =
                    disabled_content_icon[i];
                icon_bar->item[icon_bar->first_displayed_item + i].text_of_description =
                    text_of_description[i];
            }
        }

        /* if focused item is not the last one, first displayed item not change,
         * just redraw highlight and unhighlight item
         */
        if (icon_bar->need_draw_hint == MMI_TRUE)
        {
            gui_cancel_timer(gui_icon_bar_draw_hint);
            icon_bar->need_draw_hint = MMI_FALSE;
        }
        if (icon_bar->need_erase_hint == MMI_TRUE)
        {
            gui_icon_bar_erase_hint();
            icon_bar->need_erase_hint = MMI_FALSE;
        }

        /* if focused item is the last item of icon_bar, no action */
        if ((icon_bar->first_displayed_item + icon_bar->focused_item) ==
            (icon_bar->count - 1))
        {
            icon_bar->first_displayed_item = 0;
            icon_bar->focused_item = 0;
            icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;
            if (icon_bar->display_count < icon_bar->count)
            {
                icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
                icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
            }
            gui_icon_bar_show(icon_bar);
        }
        else
        {
            if (icon_bar->focused_item < (icon_bar->display_count - 1))
            {
                /* unhighlight current focused item */
                gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);

                /* focused item move one item left */
                icon_bar->focused_item += 1;
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;

                gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item - 1);

                /* highlight current focused item */
                gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
                gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
            }
            else
            {
                icon_bar->first_displayed_item += 1;
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;
                if (icon_bar->count > icon_bar->display_count)
                {
                    icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                    if ((icon_bar->first_displayed_item + icon_bar->focused_item) ==
                        (icon_bar->count - 1))
                    {
                        icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
                    }
                    else
                    {
                        icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_KEY_DOWN;
                    }
                }
                gui_icon_bar_show(icon_bar);
            }
        }
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);

        if (icon_bar->highlight_handler != NULL)
        {
            icon_bar->highlight_handler(
                icon_bar->first_displayed_item + icon_bar->focused_item);
        }
        if (icon_bar->idle_display_handler != NULL)
        {
            icon_bar->idle_display_handler(
                icon_bar->first_displayed_item + icon_bar->focused_item);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_ok_key_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_ok_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return;
    }

    if ((icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].callback != NULL) &&
        (icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].disabled == MMI_FALSE))
    {
        /* stop timer of draw hint and erase hint */
        if (icon_bar->need_draw_hint == MMI_TRUE)
        {
            gui_cancel_timer(gui_icon_bar_draw_hint);
            icon_bar->need_draw_hint = MMI_FALSE;
        }
        icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].callback(
            icon_bar->first_displayed_item + icon_bar->focused_item);
}
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_draw_highlight
 * DESCRIPTION
 *  draw icon_bar component's highlight
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 *  index           [IN]    display index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_draw_highlight(
             gui_icon_bar_struct* icon_bar,
             U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, width, height;
    gdi_handle active_layer = GDI_NULL_HANDLE;
    gdi_handle abm_layer = GDI_NULL_HANDLE;
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    if (icon_bar->highlight == NULL)
    {
        gui_icon_bar_erase_item(icon_bar, index);
        return;
    }

    gdi_layer_push_clip();

    /* get focused item's position */
    width = icon_bar->item_width;
    height = icon_bar->item_height;
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        x = icon_bar->border_gap + index * (icon_bar->item_gap + width);
        y = icon_bar->height / 2 - height / 2;
    }
    else
    {
        x = icon_bar->width / 2 - width / 2;
        y = icon_bar->border_gap + index * (icon_bar->item_gap + height);
    }

    /* calculate highlight's position */
    gdi_image_get_dimension(icon_bar->highlight, &width, &height);
    x -= width / 2 - icon_bar->item_width /2;
    y -= height / 2 - icon_bar->item_height / 2;

    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(icon_bar->target_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    }
    gdi_layer_set_clip(
        icon_bar->x + x - layer_offset_x,
        icon_bar->y + y - layer_offset_y,
        icon_bar->x + x + width - 1 -layer_offset_x,
        icon_bar->y + y + height - 1 - layer_offset_y);

    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        abm_layer = gdi_set_alpha_blending_source_layer(icon_bar->abm_layer);
    }
    icon_bar->hide_callback(
        icon_bar->x + x - layer_offset_x,
        icon_bar->y + y - layer_offset_y,
        icon_bar->x + x + width - 1 - layer_offset_x,
        icon_bar->y + y + height - 1 - layer_offset_y);
    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    /* show highlight */
    /* default hide func use transparent color */
    gdi_layer_get_active(&active_layer);
    abm_layer = gdi_set_alpha_blending_source_layer(active_layer);
    gdi_image_draw(
        icon_bar->x + x - layer_offset_x,
        icon_bar->y + y - layer_offset_y,
        icon_bar->highlight);
    gdi_set_alpha_blending_source_layer(abm_layer);

    gdi_layer_pop_clip();
    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_erase_highlight
 * DESCRIPTION
 *  erase icon_bar component's highlight
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 *  index           [IN]    display index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_erase_highlight(
             gui_icon_bar_struct* icon_bar,
             U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, width, height;
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    if (icon_bar->highlight == NULL)
    {
        gui_icon_bar_erase_item(icon_bar, index);
        return;
    }

    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(icon_bar->target_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    }
    gdi_layer_push_clip();
    
    /* get focused item's position */
    width = icon_bar->item_width;
    height = icon_bar->item_height;
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        x = icon_bar->border_gap + index * (icon_bar->item_gap + width);
        y = icon_bar->height / 2 - height / 2;
    }
    else
    {
        x = icon_bar->width / 2 - width / 2;
        y = icon_bar->border_gap + index * (icon_bar->item_gap + height);
    }

    /* calculate highlight's position */
    gdi_image_get_dimension(icon_bar->highlight, &width, &height);
    x -= width / 2 - icon_bar->item_width / 2;
    y -= height / 2 - icon_bar->item_height / 2;

    gdi_layer_set_clip(
        icon_bar->x + x - layer_offset_x,
        icon_bar->y + y - layer_offset_y,
        icon_bar->x + x + width - 1 - layer_offset_x,
        icon_bar->y + y + height - 1 - layer_offset_y);

    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        abm_layer = gdi_set_alpha_blending_source_layer(icon_bar->abm_layer);
    }
    icon_bar->hide_callback(
        icon_bar->x + x - layer_offset_x,
        icon_bar->y + y - layer_offset_y,
        icon_bar->x + x + width - 1 - layer_offset_x,
        icon_bar->y + y + height - 1 - layer_offset_y);
    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    gdi_layer_pop_clip();
    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_draw_item
 * DESCRIPTION
 *  draw icon_bar component's one item
 * PARAMETERS
 *  icon_bar    [IN]    pointer of icon_bar
 *  item_index  [IN]    item_index is between 0 ~ display_count
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_draw_item(
             gui_icon_bar_struct* icon_bar,
             U32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_x, item_y, item_width, item_height;
    S32 content_icon_x = 0, content_icon_y = 0;
    S32 content_icon_width = 0, content_icon_height = 0;
    S32 description_x = 0, description_y = 0;
    S32 description_width = 0, description_height = 0;
    U32 index; /* it is the real index of icon_bar, between 0 ~ count */
    gdi_handle active_layer = GDI_NULL_HANDLE;
    gdi_handle abm_layer = GDI_NULL_HANDLE;
    stFontAttribute font;
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    index = icon_bar->first_displayed_item + item_index;
    MMI_DBG_ASSERT(icon_bar->item[index].normal_icon != NULL);
    MMI_DBG_ASSERT(icon_bar->item[index].down_icon != NULL);

    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(icon_bar->target_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    }
    gdi_layer_push_clip();

    /* get item's dimension */
    item_width = icon_bar->item_width;
    item_height = icon_bar->item_height;

    /* calculate item's position */
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        item_x = icon_bar->border_gap +
                 item_index * (icon_bar->item_gap + item_width);
        item_y = icon_bar->height / 2 - item_height / 2;
        if (item_y < 0)
        {
            item_y = 0;
        }
    }
    else
    {
        item_x = icon_bar->width / 2 - item_width / 2;
        item_y = icon_bar->border_gap +
                 item_index * (icon_bar->item_gap + item_height);
        if (item_x < 0)
        {
            item_x = 0;
        }
    }

    gdi_layer_set_clip(
        icon_bar->x + item_x - layer_offset_x,
        icon_bar->y + item_y - layer_offset_y,
        icon_bar->x + item_x + item_width - 1 - layer_offset_x,
        icon_bar->y + item_y + item_height - 1 - layer_offset_y);

    gdi_layer_get_active(&active_layer);
    abm_layer = gdi_set_alpha_blending_source_layer(active_layer);

    /* show item background */
    /* if item is focused item */
    if (item_index == icon_bar->focused_item)
    {
        if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_KEY_DOWN ||
            icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN ||
            icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN)
        {
            if (icon_bar->item[index].disabled == MMI_TRUE)
            {
                gdi_image_draw_resized(
                    icon_bar->x + item_x - layer_offset_x,
                    icon_bar->y + item_y - layer_offset_y,
                    icon_bar->item_width,
                    icon_bar->item_height,
                    icon_bar->item[index].normal_icon);
            }
            else
            {
                gdi_image_draw_resized(
                    icon_bar->x + item_x - layer_offset_x,
                    icon_bar->y + item_y - layer_offset_y,
                    icon_bar->item_width,
                    icon_bar->item_height,
                    icon_bar->item[index].down_icon);
            }
        }
        else
        {
            gdi_image_draw_resized(
                icon_bar->x + item_x - layer_offset_x,
                icon_bar->y + item_y - layer_offset_y,
                icon_bar->item_width,
                icon_bar->item_height,
                icon_bar->item[index].normal_icon);
        }
    }
    else
    {
        gdi_image_draw_resized(
            icon_bar->x + item_x - layer_offset_x,
            icon_bar->y + item_y - layer_offset_y,
            icon_bar->item_width,
            icon_bar->item_height,
            icon_bar->item[index].normal_icon);
    }

    /* show item content if it has content */
    if (icon_bar->item[index].content_icon != NULL ||
        (icon_bar->item[index].text_of_description != NULL &&
        !(icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_HINT) &&
        (icon_bar->flags & GUI_ICON_BAR_FLAG_DRAW_HINT_AS_TEXT)))
    {
        if (icon_bar->item[index].content_icon != NULL)
        {
            gdi_image_get_dimension(
                icon_bar->item[index].content_icon,
                &content_icon_width,
                &content_icon_height);
        }
        if (icon_bar->item[index].text_of_description != NULL &&
            !(icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_HINT) &&
            (icon_bar->flags & GUI_ICON_BAR_FLAG_DRAW_HINT_AS_TEXT))
        {
            /* measure text length */
            font = *(gui_font_get_type(GUI_FONT_SIZE_ICONBAR_ITEM_TEXT));
        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
            font.smallCaps = 2;
        #endif
            gui_set_font(&font);
            gui_measure_string(
                (UI_string_type)icon_bar->item[index].text_of_description,
                &description_width,
                &description_height);
            description_width += 2; // add border width
            description_height += 2; // add border height
        }
        if (icon_bar->item[index].content_icon != NULL)
        {
            content_icon_x = item_width / 2 - content_icon_width / 2;
            content_icon_y = item_height / 2 - content_icon_height / 2;
            if (description_width > 0)
            {
                if (mmi_fe_get_r2l_state())
                {
                    content_icon_x += (description_width + GUI_ICON_BAR_ICON_TEXT_GAP) / 2;
                }
                else
                {
                    content_icon_x -= (description_width + GUI_ICON_BAR_ICON_TEXT_GAP) / 2;
                }
            }
            if (icon_bar->item[index].disabled)// == MMI_TRUE &&
            //    icon_bar->item[index].disabled_content_icon != NULL)
            {
            	gui_draw_image_with_alpha_transparent(icon_bar->item[index].content_icon,
					icon_bar->x + item_x + content_icon_x - layer_offset_x,
					icon_bar->y + item_y + content_icon_y - layer_offset_y,
					125);
            
               /* gdi_image_draw(
                    icon_bar->x + item_x + content_icon_x - layer_offset_x,
                    icon_bar->y + item_y + content_icon_y - layer_offset_y,
                    icon_bar->item[index].disabled_content_icon);*/
            }
            else
            {
                gdi_image_draw(
                    icon_bar->x + item_x + content_icon_x - layer_offset_x,
                    icon_bar->y + item_y + content_icon_y - layer_offset_y,
                    icon_bar->item[index].content_icon);
            }
        }
        if (description_width > 0)
        {
            description_x = item_width / 2 - description_width / 2;
            description_y = item_height / 2 - description_height / 2;
            if (content_icon_width > 0)
            {
                if (mmi_fe_get_r2l_state())
                {
                    description_x = content_icon_x - GUI_ICON_BAR_ICON_TEXT_GAP;
                }
                else
                {
                    description_x = content_icon_x + content_icon_width + GUI_ICON_BAR_ICON_TEXT_GAP;
                }
            }
            else
            {
                if (mmi_fe_get_r2l_state())
                {
                    description_x += description_width - 1;
                }
            }
            gui_move_text_cursor(
                icon_bar->x + item_x + description_x - layer_offset_x,
                icon_bar->y + item_y + description_y - layer_offset_y);
            if (icon_bar->item[index].disabled == MMI_TRUE)
            {
                gui_set_text_color(*current_MMI_theme->icon_bar_item_text_disable_color);
                gui_set_text_border_color(*current_MMI_theme->icon_bar_item_text_border_disable_color);
            }
            else
            {
                gui_set_text_color(*current_MMI_theme->icon_bar_item_text_normal_color);
                gui_set_text_border_color(*current_MMI_theme->icon_bar_item_text_border_normal_color);
            }
        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
            gui_print_text((UI_string_type)icon_bar->item[index].text_of_description);
        #else
            gui_print_bordered_text((UI_string_type)icon_bar->item[index].text_of_description);
        #endif
        }
        
    }

    gdi_layer_pop_clip();
    gdi_set_alpha_blending_source_layer(abm_layer);

    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_erase_item
 * DESCRIPTION
 *  erase icon_bar component's item
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 *  index           [IN]    display index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_erase_item(
             gui_icon_bar_struct* icon_bar,
             U32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_x, item_y, item_width, item_height;
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(icon_bar != NULL);

    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(icon_bar->target_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    }
    gdi_layer_push_clip();
    
    /* get item's dimension */
    item_width = icon_bar->item_width;
    item_height = icon_bar->item_height;

    /* calculate item's position */
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        item_x = icon_bar->border_gap +
                 item_index * (icon_bar->item_gap + item_width);
        item_y = icon_bar->height / 2 - item_height / 2;
        if (item_y < 0)
        {
            item_y = 0;
        }
    }
    else
    {
        item_x = icon_bar->width / 2 - item_width / 2;
        item_y = icon_bar->border_gap +
                 item_index * (icon_bar->item_gap + item_height);
        if (item_x < 0)
        {
            item_x = 0;
        }
    }

    gdi_layer_set_clip(
        icon_bar->x + item_x - layer_offset_x,
        icon_bar->y + item_y - layer_offset_y,
        icon_bar->x + item_x + item_width - 1 - layer_offset_x,
        icon_bar->y + item_y + item_height - 1 - layer_offset_y);

    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        abm_layer = gdi_set_alpha_blending_source_layer(icon_bar->abm_layer);
    }
    icon_bar->hide_callback(
        icon_bar->x + item_x - layer_offset_x,
        icon_bar->y + item_y - layer_offset_y,
        icon_bar->x + item_x + item_width - 1 - layer_offset_x,
        icon_bar->y + item_y + item_height - 1 - layer_offset_y);
    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    gdi_layer_pop_clip();
    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_draw_hint
 * DESCRIPTION
 *  draw icon_bar component item's hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area hint_filler =
    {   UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
        UI_NULL_IMAGE,
        NULL,
        {255, 255, 255, 80},
        {0, 0, 0, 0},
        {0, 0, 0, 100},
        {249, 249, 249, 0},
        0
    };
    gui_icon_bar_struct* icon_bar;
    S32 hint_x, hint_y, hint_width, hint_height;
    S32 text_x, text_y, text_width, text_height;
    UI_string_type text;
    S32 layer_offset_x = 0, layer_offset_y = 0;

    U32 i = 0, j = 0;
    U32 layer_count = 4;
    gdi_handle blt_layers[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);

    if ((icon_bar->hint_layer_ptr1 == NULL) ||
        (icon_bar->hint_layer_handle == GDI_NULL_HANDLE))
    {
        return;
    }
    if ((icon_bar->flags & GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER) &&
        (icon_bar->hint_layer_ptr2 == NULL))
    {
        return;
    }

    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_HINT))
    {
        return;
    }

    /* draw hint's text */
    text = (UI_string_type)icon_bar->item[icon_bar->first_displayed_item +
                                          icon_bar->focused_item].text_of_description;
    if (text == NULL)
    {
        return;
    }

    if (icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].disabled == MMI_TRUE &&
        icon_bar->interactive_UI_paused == MMI_FALSE)
    {
        for (j = 0; j < icon_bar->pause_interactive_UI_callback_count; j++)
        {
            if (icon_bar->pause_interactive_UI_callback[j] != NULL)
            {
                icon_bar->pause_interactive_UI_callback[j]();
            }
        }
        icon_bar->interactive_UI_paused = MMI_TRUE;
    }
    /* measure text length */
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_ICONBAR_HINT));        
    gui_measure_string(text, &text_width, &text_height);

    if (text_width + GUI_ICON_BAR_HINT_X_GAP * 2 < GUI_ICON_BAR_HINT_WIDTH)
    {
        hint_width = text_width + GUI_ICON_BAR_HINT_X_GAP * 2;
    }
    else
    {
        hint_width = GUI_ICON_BAR_HINT_WIDTH;
    }

    hint_height = GUI_ICON_BAR_HINT_HEIGHT;
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        hint_x = icon_bar->border_gap +
                 icon_bar->focused_item * (icon_bar->item_gap + icon_bar->item_width) + 
                 (icon_bar->item_width - hint_width) / 2;
        if ((hint_x + hint_width) >
            (icon_bar->border_gap + (S32)icon_bar->display_count * icon_bar->item_width + ((S32)icon_bar->display_count - 1) * icon_bar->item_gap))
        {
            hint_x = icon_bar->border_gap + icon_bar->display_count * icon_bar->item_width +
                     (icon_bar->display_count - 1) * icon_bar->item_gap - hint_width - 1;
        }
        if (hint_x < icon_bar->border_gap)
        {
            hint_x = icon_bar->border_gap;
        }
    }
    else
    {
        hint_x = icon_bar->width / 2 - hint_width / 2;
    }

    icon_bar->hint_width = hint_width;

    /* convert logic coordinate to physical coordinate */
    hint_x += icon_bar->x;
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY)
    {
        if (hint_x + hint_width > UI_device_width)
        {
            hint_x = UI_device_width - hint_width;
        }
        if (hint_x < 0)
        {
            hint_x = 0;
        }
    }

    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
    #ifndef __MMI_FTE_SUPPORT__
        hint_y = icon_bar->y + icon_bar->height + GUI_ICON_BAR_HINT_Y_GAP;
        if (hint_y + hint_height > UI_device_height)
        {
            hint_y = icon_bar->y - hint_height - GUI_ICON_BAR_HINT_Y_GAP;
        }
    #else /* __MMI_FTE_SUPPORT__ */
        hint_y = icon_bar->y - hint_height - GUI_ICON_BAR_HINT_Y_GAP;
    #endif /* __MMI_FTE_SUPPORT__ */
    }
    else
    {
        hint_y = icon_bar->y + icon_bar->border_gap +
                 icon_bar->focused_item * (icon_bar->item_gap + icon_bar->item_height) - 
                 hint_height;
        if (hint_y < 0)
        {
            hint_y = 0;
        }
    }

    gdi_layer_get_blt_layer(
        &icon_bar->h1,
        &icon_bar->h2,
        &icon_bar->h3,
        &icon_bar->h4);

    gdi_layer_push_and_set_active(icon_bar->hint_layer_handle);
    gdi_layer_set_position(0, hint_y);

    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER))
    {
        /* flatten all layer content to active layer */
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            hint_x - layer_offset_x,
            hint_y - layer_offset_y,
            hint_x + hint_width - 1  - layer_offset_x,
            hint_y + hint_height - 1 - layer_offset_y);        
        gdi_layer_flatten_with_clipping(
            icon_bar->h1,
            icon_bar->h2,
            icon_bar->h3,
            icon_bar->h4);
        gdi_layer_pop_clip();
        gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    }
    else
    {
        gdi_layer_toggle_double();
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    }

    /* keep current display content */
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        hint_x,
        0,
        hint_x + hint_width - 1,
        hint_height - 1);
    
    icon_bar->need_draw_hint = MMI_FALSE;

    gui_set_text_color(*current_MMI_theme->icon_bar_hint_text_color);
    if (text_width > hint_width)
    {
        text_x = hint_x + GUI_ICON_BAR_HINT_X_GAP;
        if (mmi_fe_get_r2l_state())
        {
            text_x = hint_x + hint_width - GUI_ICON_BAR_HINT_X_GAP;
        }
        text_width = hint_width - 2 * GUI_ICON_BAR_HINT_X_GAP;
    }
    else
    {
        text_x = hint_x + hint_width / 2 - text_width / 2;
        if (mmi_fe_get_r2l_state())
        {
            text_x = text_x + text_width - 1;
        }
    }
    if (text_height > hint_height)
    {
        text_y = 1;
    }
    else
    {
        text_y = hint_height / 2 - text_height / 2;
    }

#ifndef __MMI_FTE_SUPPORT__
    if (current_MMI_theme->icon_bar_hint_filler != NULL)
    {
        gui_draw_filled_area(
            hint_x,
            0,
            hint_x + hint_width - 1,
            hint_height - 1,
            current_MMI_theme->icon_bar_hint_filler);
    }
#else /* __MMI_FTE_SUPPORT__ */
    if (current_MMI_theme->icon_bar_hint_filler != NULL &&
        current_MMI_theme->icon_bar_hint_filler->b != NULL)
    {
        gdi_image_draw_resized(
            hint_x,
            0,
            hint_width,
            hint_height,
            current_MMI_theme->icon_bar_hint_filler->b);
    }
#endif /* __MMI_FTE_SUPPORT__ */
    else
    {
        gui_draw_filled_area(
            hint_x,
            0,
            hint_x + hint_width - 1,
            hint_height - 1,
            (UI_filled_area*)&hint_filler);
    }
    gui_print_truncated_text(text_x, text_y, text_width, text);

    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER))
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_SET_BLT_LAYERS_BY_CATEGORY))
    {
        gdi_layer_get_blt_layer(
            &blt_layers[0],
            &blt_layers[1],
            &blt_layers[2],
            &blt_layers[3]);
        for (i = 0; i < layer_count; i++)
        {
            if (blt_layers[i] == GDI_NULL_HANDLE)
            {
                break;
            }
        }
        blt_layers[i] = icon_bar->hint_layer_handle;
        gdi_layer_set_blt_layer(
            blt_layers[0],
            blt_layers[1],
            blt_layers[2],
            blt_layers[3]);
    }
    gdi_layer_blt_previous(
        hint_x,
        hint_y,
        hint_x + hint_width - 1,
        hint_y + hint_height - 1);
    icon_bar->need_erase_hint = MMI_TRUE;

    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_erase_hint
 * DESCRIPTION
 *  erase icon_bar component item's hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_icon_bar_erase_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_struct* icon_bar;
    S32 hint_x, hint_y, hint_width, hint_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_bar = current_icon_bar_pointer;
    MMI_DBG_ASSERT(icon_bar != NULL);

    if ((icon_bar->hint_layer_ptr1 == NULL) ||
        (icon_bar->hint_layer_handle == GDI_NULL_HANDLE))
    {
        return;
    }
    if ((icon_bar->flags & GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER) &&
        (icon_bar->hint_layer_ptr2 == NULL))
    {
        return;
    }

    if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_HINT))
    {
        return;
    }

    hint_width = icon_bar->hint_width;
    hint_height = GUI_ICON_BAR_HINT_HEIGHT;
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        hint_x = icon_bar->border_gap +
                 icon_bar->focused_item * (icon_bar->item_gap + icon_bar->item_width) + 
                 (icon_bar->item_width - hint_width) / 2;
        if ((hint_x + hint_width) >
            (icon_bar->border_gap + (S32)icon_bar->display_count * icon_bar->item_width + ((S32)icon_bar->display_count - 1) * icon_bar->item_gap))
        {
            hint_x = icon_bar->border_gap + icon_bar->display_count * icon_bar->item_width +
                     (icon_bar->display_count - 1) * icon_bar->item_gap - hint_width - 1;
        }
        if (hint_x < icon_bar->border_gap)
        {
            hint_x = icon_bar->border_gap;
        }
    }
    else
    {
        hint_x = icon_bar->width / 2 - hint_width / 2;
    }

    hint_x += icon_bar->x;
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY)
    {
        if (hint_x + hint_width > UI_device_width)
        {
            hint_x = UI_device_width - hint_width;
        }
        if (hint_x < 0)
        {
            hint_x = 0;
        }
    }

    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
    #ifndef __MMI_FTE_SUPPORT__
        hint_y = icon_bar->y + icon_bar->height + GUI_ICON_BAR_HINT_Y_GAP;
        if (hint_y + hint_height > UI_device_height)
        {
            hint_y = icon_bar->y - hint_height - GUI_ICON_BAR_HINT_Y_GAP;
        }
    #else /* __MMI_FTE_SUPPORT__ */
        hint_y = icon_bar->y - hint_height - GUI_ICON_BAR_HINT_Y_GAP;
    #endif /* __MMI_FTE_SUPPORT__ */
    }
    else
    {
        hint_y = icon_bar->y + icon_bar->border_gap +
                 icon_bar->focused_item * (icon_bar->item_gap + icon_bar->item_height) - 
                 hint_height;
        if (hint_y < 0)
        {
            hint_y = 0;
        }
    }

    /* keep current display content */
    gdi_layer_push_and_set_active(icon_bar->hint_layer_handle);
    gdi_layer_set_position(0, hint_y);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        hint_x,
        0,
        hint_x + hint_width - 1,
        hint_height - 1);

    if (icon_bar->need_erase_hint == MMI_TRUE)
    {
        if (icon_bar->flags & GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER)
        {
            gdi_layer_toggle_double();
        }
        gdi_draw_solid_rect(
            hint_x,
            0,
            hint_x + hint_width - 1,
            hint_height - 1,
            GDI_COLOR_TRANSPARENT);
        icon_bar->need_erase_hint = MMI_FALSE;
        gdi_layer_blt_previous(
            hint_x,
            hint_y,
            hint_x + hint_width - 1,
            hint_y + hint_height - 1);
        if (!(icon_bar->flags & GUI_ICON_BAR_FLAG_SET_BLT_LAYERS_BY_CATEGORY))
        {
            gdi_layer_set_blt_layer(
                icon_bar->h1,
                icon_bar->h2,
                icon_bar->h3,
                icon_bar->h4);
        }
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_translate_arrow_position
 * DESCRIPTION
 *  translate pen's position whether in an arrow's area
 * PARAMETERS
 *  icon_bar                [IN]
 *  x                       [IN]
 *  y                       [IN]
 *  arrow                   [IN/OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_icon_bar_translate_arrow_position(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y,
                 gui_icon_bar_arrow_enum *arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_x, item_y, item_width, item_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    /* whether pen is in icon_bar's area */
    if (!PEN_CHECK_BOUND(
             x,
             y,
             icon_bar->x,
             icon_bar->y,
             icon_bar->width,
             icon_bar->height))
    {
        return MMI_FALSE;
    }

    /* if pen is not in the area of item */
    if (((icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY) &&
         !PEN_CHECK_BOUND(
            x,
            y,
            icon_bar->x + icon_bar->border_gap, 
            icon_bar->y,
            icon_bar->width - 2 * icon_bar->border_gap,
             icon_bar->height)) ||
        ((icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY) &&
         !PEN_CHECK_BOUND(
             x,
             y,
             icon_bar->x, 
             icon_bar->y + icon_bar->border_gap,
             icon_bar->width,
             icon_bar->height - 2 * icon_bar->border_gap)))
    {
        /* prev arrow */
        if (icon_bar->prev_arrow.normal_icon != NULL &&
            icon_bar->prev_arrow.down_icon != NULL)
        {
            gdi_image_get_dimension(
                icon_bar->prev_arrow.normal_icon,
                &item_width,
                &item_height);
            if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
            {
                item_x = icon_bar->x + (icon_bar->border_gap / 2 - item_width / 2);
                item_y = icon_bar->y + (icon_bar->height / 2 - item_width / 2);
            }
            else
            {
                item_x = icon_bar->x + (icon_bar->width / 2 - item_width / 2);
                item_y = icon_bar->y + (icon_bar->border_gap / 2 - item_height / 2);
            }
            if (PEN_CHECK_BOUND(
                x,
                y,
                item_x,
                item_y,
                item_width,
                item_height))
            {
                if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_DISABLED)
                {
                    return MMI_FALSE;
                }
                *arrow = GUI_ICON_BAR_ARROW_PREV;
                return MMI_TRUE;
            }
        }

        /* right arrow */
        if (icon_bar->next_arrow.normal_icon != NULL &&
            icon_bar->next_arrow.down_icon != NULL)
        {
            gdi_image_get_dimension(
                icon_bar->next_arrow.normal_icon,
                &item_width,
                &item_height);
            if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
            {
                item_x = icon_bar->x + icon_bar->width - 1 - icon_bar->border_gap + 
                         (icon_bar->border_gap / 2 - item_width / 2);
                item_y = icon_bar->y + (icon_bar->height / 2 - item_width / 2);
            }
            else
            {
                item_x = icon_bar->x + (icon_bar->width / 2 - item_width / 2);
                item_y = icon_bar->y + icon_bar->height - 1 - icon_bar->border_gap + 
                         (icon_bar->border_gap / 2 - item_height / 2);
            }
            if (PEN_CHECK_BOUND(
                x,
                y,
                item_x,
                item_y,
                item_width,
                item_height))
            {
                if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_DISABLED)
                {
                    return MMI_FALSE;
                }
                *arrow = GUI_ICON_BAR_ARROW_NEXT;
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_translate_item_position
 * DESCRIPTION
 *  translate pen's position whether in an item's area
 * PARAMETERS
 *  icon_bar                [IN]
 *  x                       [IN]
 *  y                       [IN]
 *  item_index              [IN/OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_icon_bar_translate_item_position(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y,
                 U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_x, item_y, item_width, item_height;
    U32 item_index;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    /* whether pen is in icon_bar's area */
    if (!PEN_CHECK_BOUND(
             x,
             y,
             icon_bar->x,
             icon_bar->y,
             icon_bar->width,
             icon_bar->height))
    {
        return MMI_FALSE;
    }

    /* if pen is in the area of item */
    if (((icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY) &&
         PEN_CHECK_BOUND(
            x,
            y,
            icon_bar->x + icon_bar->border_gap,
            icon_bar->y,
            icon_bar->width - icon_bar->border_gap,
            icon_bar->height)) ||
         ((icon_bar->flags & GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY) &&
         PEN_CHECK_BOUND(
             x,
             y,
             icon_bar->x,
             icon_bar->y + icon_bar->border_gap,
             icon_bar->width,
             icon_bar->height - icon_bar->border_gap)))
    {
        item_width = icon_bar->item_width;
        item_height = icon_bar->item_height;

        if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
        {
            item_index = (x - icon_bar->x - icon_bar->border_gap) /
                         (item_width + icon_bar->item_gap);
        }
        else
        {
            item_index = (y - icon_bar->y - icon_bar->border_gap) /
                         (item_height + icon_bar->item_gap);
        }

        /* if item_index >= display count, pen is out of item area */
        if (item_index >= icon_bar->display_count)
        {
            return MMI_FALSE;
        }

        if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
        {
            item_x = icon_bar->x + icon_bar->border_gap + 
                     item_index * (item_width + icon_bar->item_gap);
            item_y = icon_bar->y + (icon_bar->height / 2 - item_height / 2);
        }
        else
        {
            item_x = icon_bar->x + (icon_bar->width / 2 - item_width / 2);
            item_y = icon_bar->y + icon_bar->border_gap + 
                     item_index * (item_height + icon_bar->item_gap);
        }
        if (PEN_CHECK_BOUND(
                x,
                y,
                item_x,
                item_y,
                item_width,
                item_height))
        {
            *index = item_index;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_pen_down_handler
 * DESCRIPTION
 *  handle icon_bar's pen down event
 * PARAMETERS
 *  icon_bar                [IN]
 *  x                       [IN]
 *  y                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_icon_bar_pen_down_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
//    MMI_BOOL result;
    U32 item_index;
    gui_icon_bar_arrow_enum arrow;
    U8 *normal_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *down_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *disabled_content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *text_of_description[GUI_ICON_BAR_DISPLAY_COUNT];

    U32 i, j;
    U32 temp_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    item_index = icon_bar->display_count;
    /* pen is on a item */
    if (gui_icon_bar_translate_item_position(icon_bar, x, y, &item_index))
    {
        if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_NORMAL)
        {
            /* stop timer of draw hint and erase hint */
            if (icon_bar->need_draw_hint == MMI_TRUE)
            {
                gui_cancel_timer(gui_icon_bar_draw_hint);
                icon_bar->need_draw_hint = MMI_FALSE;
            }
            if (icon_bar->need_erase_hint == MMI_TRUE)
            {
                gui_icon_bar_erase_hint();
                icon_bar->need_erase_hint = MMI_FALSE;
            }

            if (icon_bar->item[icon_bar->first_displayed_item + item_index].disabled == MMI_FALSE)
            {
                for (j = 0; j < icon_bar->pause_interactive_UI_callback_count; j++)
                {
                    if (icon_bar->pause_interactive_UI_callback[j] != NULL)
                    {
                        icon_bar->pause_interactive_UI_callback[j]();
                    }
                }
                icon_bar->interactive_UI_paused = MMI_TRUE;
            }

            /* update item's info */
            if (icon_bar->dynamic_update_handler != NULL)
            {
               /* result = */icon_bar->dynamic_update_handler(
                             icon_bar->first_displayed_item,
                             icon_bar->display_count,
                             (U8**)&normal_icon,
                             (U8**)&down_icon,
                             (U8**)&content_icon,
                             (U8**)&disabled_content_icon,
                             (U8**)&text_of_description);
               // MMI_DBG_ASSERT(result == MMI_TRUE);
                for (i = 0; i < icon_bar->display_count; i++)
                {
                    icon_bar->item[icon_bar->first_displayed_item + i].normal_icon =
                        normal_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].down_icon =
                         down_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].content_icon =
                         content_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].disabled_content_icon =
                        disabled_content_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].text_of_description =
                        text_of_description[i];
                }
            }

            /* if icon_bar is not active, active it */
            icon_bar->active = MMI_TRUE;
            gui_icon_bar_set_key_handler();

            /* unhighlight old focued item and highlight new item */
            gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
            if (icon_bar->focused_item != item_index)
            {
                temp_index = icon_bar->focused_item;
                /* set new focused item */
                icon_bar->focused_item = item_index;
                /* we need chage focused_item before draw temp_index icon,
                 * because it will use different abm layer in gui_icon_bar_draw_item()
                 */
                gui_icon_bar_draw_item(icon_bar, temp_index);
            }
            if ((icon_bar->flags & GUI_ICON_BAR_FLAG_ENABLE_HINT) &&
                (icon_bar->item[icon_bar->first_displayed_item +
                 icon_bar->focused_item].text_of_description != NULL))
            {
                gui_start_timer(GUI_ICON_BAR_HINT_WAIT_TIME, gui_icon_bar_draw_hint);
                icon_bar->need_draw_hint = MMI_TRUE;
            }

            icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_DOWN;
            /* highlight current focused item */
            gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
            gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);

            /* call highligh handler and idle display handler */
            if (icon_bar->highlight_handler != NULL)
            {
                icon_bar->highlight_handler(
                    icon_bar->first_displayed_item + icon_bar->focused_item);
            }
            if (icon_bar->idle_display_handler != NULL)
            {
                icon_bar->idle_display_handler(
                    icon_bar->first_displayed_item + icon_bar->focused_item);
            }
            gdi_layer_blt_previous(
                icon_bar->x,
                icon_bar->y,
                icon_bar->x + icon_bar->width - 1,
                icon_bar->y + icon_bar->height - 1);
            ret = MMI_TRUE;
            if (icon_bar->item[icon_bar->focused_item].disabled == MMI_FALSE)
            {
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
        }
    }

    if (gui_icon_bar_translate_arrow_position(icon_bar, x, y, &arrow))
    {
        /* left arrow */
        if (arrow == GUI_ICON_BAR_ARROW_PREV &&
            icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_NORMAL)
        {
            icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_PEN_DOWN;
            gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
            gdi_layer_blt_previous(
                icon_bar->x,
                icon_bar->y,
                icon_bar->x + icon_bar->border_gap - 1,
                icon_bar->y + icon_bar->height - 1);
            ret = MMI_TRUE;
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }
        /* right arrow */
        if (arrow == GUI_ICON_BAR_ARROW_NEXT &&
            icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_NORMAL)
        {
            icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_PEN_DOWN;
            gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
            gdi_layer_blt_previous(
                icon_bar->x + icon_bar->width - 1 - icon_bar->border_gap,
                icon_bar->y,
                icon_bar->x + icon_bar->width - 1,
                icon_bar->y + icon_bar->height - 1);
            ret = MMI_TRUE;
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }

        /* if icon_bar is not active, active it */
        icon_bar->active = MMI_TRUE;
        gui_icon_bar_set_key_handler();
    }
    MMI_DBG_ASSERT(!((item_index < icon_bar->display_count) &&
                   (arrow == GUI_ICON_BAR_ARROW_NEXT ||
                    arrow == GUI_ICON_BAR_ARROW_PREV)));
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_pen_move_handler
 * DESCRIPTION
 *  handle icon_bar's pen move event
 * PARAMETERS
 *  icon_bar                [IN]
 *  x                       [IN]
 *  y                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_icon_bar_pen_move_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;//, result;
    U32 item_index;
    gui_icon_bar_arrow_enum arrow;
    U8 *normal_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *down_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *disabled_content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *text_of_description[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 i;
#ifndef __MMI_FTE_SUPPORT__
    U32 temp_index;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_ABORT ||
        icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_NORMAL)
    {
        return MMI_FALSE;
    }
    /* pen is on one item */
    if (gui_icon_bar_translate_item_position(icon_bar, x, y, &item_index))
    {
        if (icon_bar->focused_item == item_index &&
            (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
             icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN))
        {
            return MMI_FALSE;
        }
        else
        {
            if (icon_bar->dynamic_update_handler != NULL)
            {
                /*result = */icon_bar->dynamic_update_handler(
                             icon_bar->first_displayed_item,
                             icon_bar->display_count,
                             (U8**)&normal_icon,
                             (U8**)&down_icon,
                             (U8**)&content_icon,
                             (U8**)&disabled_content_icon,
                             (U8**)&text_of_description);
                //MMI_DBG_ASSERT(result == MMI_TRUE);
                for (i = 0; i < icon_bar->display_count; i++)
                {
                    icon_bar->item[icon_bar->first_displayed_item + i].normal_icon =
                        normal_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].down_icon =
                        down_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].content_icon =
                        content_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].disabled_content_icon =
                        disabled_content_icon[i];
                    icon_bar->item[icon_bar->first_displayed_item + i].text_of_description =
                        text_of_description[i];
                }
            }

            /* unhighlight old focused item and highlight new item */
            gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
            if (icon_bar->focused_item != item_index)
            {
                if (icon_bar->need_draw_hint == MMI_TRUE)
                {
                    gui_cancel_timer(gui_icon_bar_draw_hint);
                    icon_bar->need_draw_hint = MMI_FALSE;
                }
                if (icon_bar->need_erase_hint == MMI_TRUE)
                {
                    gui_icon_bar_erase_hint();
                    icon_bar->need_erase_hint = MMI_FALSE;
                }

            #ifndef __MMI_FTE_SUPPORT__
                temp_index = icon_bar->focused_item;
                /* set new focused item */
                icon_bar->focused_item = item_index;
                gui_icon_bar_draw_item(icon_bar, temp_index);
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN;
            #else /* __MMI_FTE_SUPPORT__ */
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT;
            #endif /* __MMI_FTE_SUPPORT__ */
                /* highlight current focused item */
                gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
                gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);

            }
            else
            {
                icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN;
                /* highlight current focused item */
                gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
                gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
            }

            gdi_layer_blt_previous(
                icon_bar->x,
                icon_bar->y,
                icon_bar->x + icon_bar->width - 1,
                icon_bar->y + icon_bar->height - 1);
            /* call highlight handler and idle display handler */
            if (icon_bar->highlight_handler != NULL)
            {
                icon_bar->highlight_handler(
                    icon_bar->first_displayed_item + icon_bar->focused_item);
            }
            if (icon_bar->idle_display_handler != NULL)
            {
                icon_bar->idle_display_handler(
                    icon_bar->first_displayed_item + icon_bar->focused_item);
            }
            ret = MMI_TRUE;
        }
    }
    else
    {
        /* if pen move out of focused item */
        if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN ||
            icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN)
        {
            icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT;
            /* stop timer of draw hint and erase hint */
            if (icon_bar->need_draw_hint == MMI_TRUE)
            {
                gui_cancel_timer(gui_icon_bar_draw_hint);
                icon_bar->need_draw_hint = MMI_FALSE;
            }
            if (icon_bar->need_erase_hint == MMI_TRUE)
            {
                gui_icon_bar_erase_hint();
                icon_bar->need_erase_hint = MMI_FALSE;
            }
            gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
            gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
            gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
            gdi_layer_blt_previous(
                icon_bar->x,
                icon_bar->y,
                icon_bar->x + icon_bar->width - 1,
                icon_bar->y + icon_bar->height - 1);
            ret = MMI_TRUE;
        }        
    }

    if (gui_icon_bar_translate_arrow_position(icon_bar, x, y, &arrow))
    {
        /* left arrow */
        if (arrow == GUI_ICON_BAR_ARROW_PREV)
        {
            if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
                icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
            {
                return MMI_FALSE;
            }
            else
            {
                icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN;
                gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
                gdi_layer_blt_previous(
                    icon_bar->x,
                    icon_bar->y,
                    icon_bar->x + icon_bar->border_gap - 1,
                    icon_bar->y + icon_bar->height - 1);
            }
        }

        /* right arrow */
        if (arrow == GUI_ICON_BAR_ARROW_NEXT)
        {
            if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
                icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
            {
                return MMI_FALSE;
            }
            else
            {
                icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN;
                gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
                gdi_layer_blt_previous(
                    icon_bar->x + icon_bar->width - 1 - icon_bar->border_gap,
                    icon_bar->y,
                    icon_bar->x + icon_bar->width - 1,
                    icon_bar->y + icon_bar->height - 1);
            }
        }
    }
    else
    {
        if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
            icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
        {
            icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT;
            gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
            gdi_layer_blt_previous(
                icon_bar->x,
                icon_bar->y,
                icon_bar->x + icon_bar->border_gap - 1,
                icon_bar->y + icon_bar->height - 1);
        }

        if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
            icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
        {
            icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT;
            gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
            gdi_layer_blt_previous(
                    icon_bar->x + icon_bar->width - 1 - icon_bar->border_gap,
                    icon_bar->y,
                    icon_bar->x + icon_bar->width - 1,
                    icon_bar->y + icon_bar->height - 1);
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_pen_up_handler
 * DESCRIPTION
 *  handle icon_bar's pen up event
 * PARAMETERS
 *  icon_bar                [IN]
 *  x                       [IN]
 *  y                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_icon_bar_pen_up_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_icon_state_enum state;
    MMI_BOOL ret = MMI_FALSE;
    U32 item_index;
    gui_icon_bar_arrow_enum arrow;
//    MMI_BOOL result;
    U8 *normal_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *down_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *disabled_content_icon[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 *text_of_description[GUI_ICON_BAR_DISPLAY_COUNT];
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_ABORT)
    {
        icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        if (icon_bar->interactive_UI_paused == MMI_TRUE)
        {
            for (j = 0; j < icon_bar->resume_interactive_UI_callback_count; j++)
            {
                if (icon_bar->resume_interactive_UI_callback[j] != NULL)
                {
                    icon_bar->resume_interactive_UI_callback[j]();
                }
            }
            icon_bar->interactive_UI_paused = MMI_FALSE;
        }
        return MMI_TRUE;
    }
    /* pen is on one item */
    if (gui_icon_bar_translate_item_position(icon_bar, x, y, &item_index))
    {
        MMI_BOOL refresh_item = MMI_TRUE;
        if (icon_bar->item_refresh_callback != NULL)
        {
            refresh_item = icon_bar->item_refresh_callback(item_index);
        }

        if (MMI_TRUE == refresh_item)
        {
        /* unhighlight old focused item and highlight new item */
        gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
        state = icon_bar->focused_item_state;
    #ifndef __MMI_FTE_SUPPORT__
        icon_bar->focused_item = item_index;
    #endif
        icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        /* highlight current focused item */
        gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
        gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);
        }
        else
        {
            state = icon_bar->focused_item_state;
        #ifndef __MMI_FTE_SUPPORT__
            icon_bar->focused_item = item_index;
        #endif
            icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        }
        if (state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
        {
            /* stop timer of draw hint and erase hint */
            if (icon_bar->need_draw_hint == MMI_TRUE)
            {
                gui_cancel_timer(gui_icon_bar_draw_hint);
                icon_bar->need_draw_hint = MMI_FALSE;
            }
            if (icon_bar->need_erase_hint)// == MMI_TRUE)
            {
                gui_icon_bar_erase_hint();
                icon_bar->need_erase_hint = MMI_FALSE;
            }
            if ((icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].callback != NULL))
            {
                if (icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].disabled == MMI_FALSE)
                {
                    icon_bar->item[icon_bar->first_displayed_item + icon_bar->focused_item].callback(
                        icon_bar->first_displayed_item + icon_bar->focused_item);
                }
                else
                {
                    if (icon_bar->interactive_UI_paused)// == MMI_TRUE)
                    {
                        for (j = 0; j < icon_bar->resume_interactive_UI_callback_count; j++)
                        {
                            if (icon_bar->resume_interactive_UI_callback[j] != NULL)
                            {
                                icon_bar->resume_interactive_UI_callback[j]();
                            }
                        }
                        icon_bar->interactive_UI_paused = MMI_FALSE;
                    }
                }
            }
            else
            {
                if (icon_bar->interactive_UI_paused)// == MMI_TRUE)
                {
                    for (j = 0; j < icon_bar->resume_interactive_UI_callback_count; j++)
                    {
                        if (icon_bar->resume_interactive_UI_callback[j] != NULL)
                        {
                            icon_bar->resume_interactive_UI_callback[j]();
                        }
                    }
                    icon_bar->interactive_UI_paused = MMI_FALSE;
                }
            }
            ret = MMI_TRUE;
        }
        else
        {
            if (icon_bar->interactive_UI_paused)// == MMI_TRUE)
            {
                for (j = 0; j < icon_bar->resume_interactive_UI_callback_count; j++)
                {
                    if (icon_bar->resume_interactive_UI_callback[j] != NULL)
                    {
                        icon_bar->resume_interactive_UI_callback[j]();
                    }
                }
                icon_bar->interactive_UI_paused = MMI_FALSE;
            }
        }
    }
    else
    {
        if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN ||
            icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN)
        {
            /* unhighlight old focused item and highlight new item */
            gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
            icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
            /* highlight current focused item */
            gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
            gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
            gdi_layer_blt_previous(
                icon_bar->x,
                icon_bar->y,
                icon_bar->x + icon_bar->width - 1,
                icon_bar->y + icon_bar->height - 1);
            /* stop timer of draw hint and erase hint */
            if (icon_bar->need_draw_hint)// == MMI_TRUE)
            {
                gui_cancel_timer(gui_icon_bar_draw_hint);
                icon_bar->need_draw_hint = MMI_FALSE;
            }
            if (!icon_bar->need_erase_hint)// == MMI_TRUE)
            {
                gui_icon_bar_erase_hint();
                icon_bar->need_erase_hint = MMI_FALSE;
            }
        }
        if (icon_bar->interactive_UI_paused)// == MMI_TRUE)
        {
            for (j = 0; j < icon_bar->resume_interactive_UI_callback_count; j++)
            {
                if (icon_bar->resume_interactive_UI_callback[j] != NULL)
                {
                    icon_bar->resume_interactive_UI_callback[j]();
                }
            }
            icon_bar->interactive_UI_paused = MMI_FALSE;
        }
        icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        ret = MMI_TRUE;
    }

    if (gui_icon_bar_translate_arrow_position(icon_bar, x, y, &arrow))
    {
        /* left arrow */
        if (arrow == GUI_ICON_BAR_ARROW_PREV)
        {
            if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
            {
                /* stop timer of draw hint and erase hint */
                if (icon_bar->need_draw_hint)// == MMI_TRUE)
                {
                    gui_cancel_timer(gui_icon_bar_draw_hint);
                    icon_bar->need_draw_hint = MMI_FALSE;
                }
                if (icon_bar->need_erase_hint)// == MMI_TRUE)
                {
                    gui_icon_bar_erase_hint();
                    icon_bar->need_erase_hint = MMI_FALSE;
                }

                icon_bar->first_displayed_item -= 1;
                if (icon_bar->focused_item != (icon_bar->display_count - 1))
                {
                    icon_bar->focused_item += 1;
                }
                if (icon_bar->first_displayed_item == 0)
                {
                    icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
                }
                else
                {
                    icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                }
                if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_DISABLED)
                {
                    icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                }
                if (icon_bar->dynamic_update_handler != NULL)
                {
                    /*result = */icon_bar->dynamic_update_handler(
                                icon_bar->first_displayed_item,
                                icon_bar->display_count,
                                (U8**)&normal_icon,
                                (U8**)&down_icon,
                                (U8**)&content_icon,
                                (U8**)&disabled_content_icon,
                                (U8**)&text_of_description);
                    //MMI_DBG_ASSERT(result == MMI_TRUE);
                    for (i = 0; i < icon_bar->display_count; i++)
                    {
                        icon_bar->item[icon_bar->first_displayed_item + i].normal_icon =
                            normal_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].down_icon =
                            down_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].content_icon =
                            content_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].disabled_content_icon =
                            disabled_content_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].text_of_description =
                            text_of_description[i];
                    }
                }

                gui_icon_bar_show(icon_bar);
                gdi_layer_blt_previous(
                    icon_bar->x,
                    icon_bar->y,
                    icon_bar->x + icon_bar->width - 1,
                    icon_bar->y + icon_bar->height - 1);
                ret = MMI_TRUE;
            }
            else
            {
                icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
                gdi_layer_blt_previous(
                    icon_bar->x,
                    icon_bar->y,
                    icon_bar->x + icon_bar->border_gap - 1,
                    icon_bar->y + icon_bar->height - 1);
            }
        }

        /* right arrow */
        if (arrow == GUI_ICON_BAR_ARROW_NEXT)
        {
            if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
            {
                /* stop timer of draw hint and erase hint */
                if (icon_bar->need_draw_hint)// == MMI_TRUE)
                {
                    gui_cancel_timer(gui_icon_bar_draw_hint);
                    icon_bar->need_draw_hint = MMI_FALSE;
                }
                if (icon_bar->need_erase_hint)// == MMI_TRUE)
                {
                    gui_icon_bar_erase_hint();
                    icon_bar->need_erase_hint = MMI_FALSE;
                }

                /* adjust first displayed item and focused item */
                icon_bar->first_displayed_item += 1;
                if (icon_bar->focused_item > 0)
                {
                    icon_bar->focused_item -= 1;
                }

                if (icon_bar->first_displayed_item == 
                    (icon_bar->count - icon_bar->display_count))
                {
                    icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_DISABLED;
                }
                else
                {
                    icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                }
                if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_DISABLED)
                {
                    icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                }

                if (icon_bar->dynamic_update_handler != NULL)
                {
                    /*result = */icon_bar->dynamic_update_handler(
                                icon_bar->first_displayed_item,
                                icon_bar->display_count,
                                (U8**)&normal_icon,
                                (U8**)&down_icon,
                                (U8**)&content_icon,
                                (U8**)&disabled_content_icon,
                                (U8**)&text_of_description);
                   // MMI_DBG_ASSERT(result == MMI_TRUE);
                    for (i = 0; i < icon_bar->display_count; i++)
                    {
                        icon_bar->item[icon_bar->first_displayed_item + i].normal_icon =
                            normal_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].down_icon =
                            down_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].content_icon =
                            content_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].disabled_content_icon =
                            disabled_content_icon[i];
                        icon_bar->item[icon_bar->first_displayed_item + i].text_of_description =
                            text_of_description[i];
                    }
                }

                gui_icon_bar_show(icon_bar);
                gdi_layer_blt_previous(
                    icon_bar->x,
                    icon_bar->y,
                    icon_bar->x + icon_bar->width - 1,
                    icon_bar->y + icon_bar->height - 1);
                ret = MMI_TRUE;
            }
            else
            {
                icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
                gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
                gdi_layer_blt_previous(
                    icon_bar->x + icon_bar->width - 1 - icon_bar->border_gap,
                    icon_bar->y,
                    icon_bar->x + icon_bar->width - 1,
                    icon_bar->y + icon_bar->height - 1);
                ret = MMI_TRUE;
            }
        }
    }
    else
    {
        /* left arrow */
        if (icon_bar->prev_arrow.state != GUI_ICON_BAR_ICON_STATE_DISABLED)
        {
            icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        }

        /* right arrow */
        if (icon_bar->next_arrow.state != GUI_ICON_BAR_ICON_STATE_DISABLED)
        {
            icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_pen_abort_handler
 * DESCRIPTION
 *  handle icon_bar's pen up event
 * PARAMETERS
 *  icon_bar                [IN]
 *  x                       [IN]
 *  y                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_icon_bar_pen_abort_handler(
                 gui_icon_bar_struct *icon_bar,
                 S16 x,
                 S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* recover the focused item state */
    if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN ||
        icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN)
    {
        /* stop timer of draw hint and erase hint */
        if (icon_bar->need_draw_hint)// == MMI_TRUE)
        {
            gui_cancel_timer(gui_icon_bar_draw_hint);
            icon_bar->need_draw_hint = MMI_FALSE;
        }
        if (icon_bar->need_erase_hint)// == MMI_TRUE)
        {
            gui_icon_bar_erase_hint();
            icon_bar->need_erase_hint = MMI_FALSE;
        }
        icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
        gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
        gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);
    }
    icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;

    /* recover the arrow state */
    if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
        icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
    {
        icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->border_gap - 1,
            icon_bar->y + icon_bar->height - 1);
    }
    if (icon_bar->prev_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT)
    {
        icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    }

    /* right arrow */
    if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN ||
        icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN)
    {
        icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
        gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
        gdi_layer_blt_previous(
            icon_bar->x + icon_bar->width - 1 - icon_bar->border_gap,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);
    }
    if (icon_bar->next_arrow.state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT)
    {
        icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    }

    if (icon_bar->interactive_UI_paused)// == MMI_TRUE)
    {
        for (j = 0; j < (S32)icon_bar->resume_interactive_UI_callback_count; j++)
        {
            if (icon_bar->resume_interactive_UI_callback[j] != NULL)
            {
                icon_bar->resume_interactive_UI_callback[j]();
            }
        }
        icon_bar->interactive_UI_paused = MMI_FALSE;
    }
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */

/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_create
 * DESCRIPTION
 *  create a icon_bar component
 * PARAMETERS
 *  icon_bar        [IN]    pointer of icon_bar
 *  x               [IN]    x pos of icon_bar component
 *  y               [IN]    y pos of icon_bar component
 *  width           [IN]    x dimension of icon_bar component
 *  height          [IN]    y dimension of icon_bar component
 *  item_count      [IN]    count of items that need display
 *  background      [IN]    background of icon_bar component
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_icon_bar_create(
          gui_icon_bar_struct *icon_bar,
          S32 x,
          S32 y,
          S32 width,
          S32 height,
          S32 item_count,
          MMI_BOOL enable_key_event,
          MMI_BOOL hint_use_double_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (item_count < 0 || item_count > GUI_ICON_BAR_MAX_COUNT)
    {
        return MMI_FALSE;
    }

    icon_bar->hint_layer_ptr1 = (U8*)mmi_frm_scrmem_alloc_framebuffer(
                                         MMI_ICON_BAR_HINT_BUF_SIZE);
    if (icon_bar->hint_layer_ptr1 == NULL)
    {
        return MMI_FALSE;
    }
    if (hint_use_double_buffer)// == MMI_TRUE)
    {
        icon_bar->hint_layer_ptr2 = (U8*)mmi_frm_scrmem_alloc_framebuffer(
                                             MMI_ICON_BAR_HINT_BUF_SIZE);
        if (icon_bar->hint_layer_ptr2 == NULL)
        {
            mmi_frm_scrmem_free(icon_bar->hint_layer_ptr1);
            icon_bar->hint_layer_ptr1 = NULL;
            return MMI_FALSE;
        }
    }
    if (!hint_use_double_buffer)// == MMI_FALSE)
    {
        result = gdi_layer_create_cf_using_outside_memory(
                     gdi_act_layer->cf, /* color format */
                     0,
                     0,
                     GUI_ICON_BAR_HINT_WIDTH,
                     GUI_ICON_BAR_HINT_HEIGHT,
                     &(icon_bar->hint_layer_handle),
                     icon_bar->hint_layer_ptr1,
                     MMI_ICON_BAR_HINT_BUF_SIZE);
    }
    else
    {
        result = gdi_layer_create_cf_double_using_outside_memory(
                     gdi_act_layer->cf, /* color format */
                     0,
                     0,
                     GUI_ICON_BAR_HINT_WIDTH,
                     GUI_ICON_BAR_HINT_HEIGHT,
                     &(icon_bar->hint_layer_handle),
                     icon_bar->hint_layer_ptr1,
                     MMI_ICON_BAR_HINT_BUF_SIZE,
                     icon_bar->hint_layer_ptr2,
                     MMI_ICON_BAR_HINT_BUF_SIZE);
    }

    if (result != GDI_SUCCEED)
    {
        mmi_frm_scrmem_free(icon_bar->hint_layer_ptr1);
        icon_bar->hint_layer_ptr1 = NULL;
        if (hint_use_double_buffer)// == MMI_TRUE)
        {
            mmi_frm_scrmem_free(icon_bar->hint_layer_ptr2);
            icon_bar->hint_layer_ptr2 = NULL;
        }
        return MMI_FALSE;
    }
    else
    {
        gdi_layer_push_and_set_active(icon_bar->hint_layer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        if (hint_use_double_buffer)// == MMI_TRUE)
        {
            gdi_layer_toggle_double();
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            icon_bar->flags = GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER;
        }
        gdi_layer_pop_and_restore_active();
    }
    icon_bar->h1 = icon_bar->h2 = icon_bar->h3 = icon_bar->h4 = GDI_NULL_HANDLE;

    icon_bar->x =x;
    icon_bar->y = y;
    icon_bar->width = width;
    icon_bar->height = height;
    icon_bar->count = item_count;
    icon_bar->first_displayed_item = 0;
    icon_bar->focused_item = 0;

    icon_bar->pause_interactive_UI_callback_count = 0;
    icon_bar->resume_interactive_UI_callback_count = 0;

    icon_bar->item_width = GUI_ICON_BAR_ITEM_INIT_WIDTH;
    icon_bar->item_height = GUI_ICON_BAR_ITEM_INIT_HEIGHT;
    icon_bar->flags |= GUI_ICON_BAR_FLAG_ALIGN_INIT;
    icon_bar->flags |= GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY;
    icon_bar->auto_arrange_item = MMI_TRUE;
    gui_icon_bar_calculate_display_count(icon_bar);

    icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    icon_bar->hide_callback = gui_icon_bar_default_hide_function;
    icon_bar->need_draw_hint = MMI_FALSE;
    icon_bar->need_erase_hint = MMI_FALSE;
    icon_bar->active = MMI_FALSE;
    icon_bar->interactive_UI_paused = MMI_FALSE;
    if (enable_key_event)// == MMI_TRUE)
    {
        icon_bar->flags |= GUI_ICON_BAR_FLAG_ENABLE_KEY_EVENT;
    }
    current_icon_bar_pointer = icon_bar;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_close
 * DESCRIPTION
 *  close a icon_bar component
 * PARAMETERS
 *  icon_bar        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_close(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    /* reset short component */
    for (i = 0; i < icon_bar->count; i++)
    {
        icon_bar->item[i].normal_icon = NULL;
        icon_bar->item[i].down_icon = NULL;
        icon_bar->item[i].content_icon = NULL;
        icon_bar->item[i].disabled_content_icon = NULL;
        icon_bar->item[i].text_of_description = NULL;
        icon_bar->item[i].disabled = MMI_FALSE;
        icon_bar->item[i].callback = NULL;
    }

    if (icon_bar->need_draw_hint)// == MMI_TRUE)
    {
        gui_cancel_timer(gui_icon_bar_draw_hint);
    }
    if (icon_bar->need_erase_hint &&//== MMI_TRUE &&
        !(icon_bar->flags & GUI_ICON_BAR_FLAG_SET_BLT_LAYERS_BY_CATEGORY))
    {
        gdi_layer_set_blt_layer(
            icon_bar->h1,
            icon_bar->h2,
            icon_bar->h3,
            icon_bar->h4);
    }
    if (icon_bar->hint_layer_ptr1 != NULL &&
        icon_bar->hint_layer_handle != GDI_NULL_HANDLE)
    {
        /* free hint layer and buffer */
        gdi_layer_free(icon_bar->hint_layer_handle);
        mmi_frm_scrmem_free(icon_bar->hint_layer_ptr1);
        if (icon_bar->flags & GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER)
        {
            if (icon_bar->hint_layer_ptr2 != NULL)
            {
                mmi_frm_scrmem_free(icon_bar->hint_layer_ptr2);
                icon_bar->hint_layer_ptr2 = NULL;
            }
            else
            {
                MMI_DBG_ASSERT(0);
            }
        }
        icon_bar->hint_layer_handle = GDI_NULL_HANDLE;
        icon_bar->hint_layer_ptr1 = NULL;
    }
    icon_bar->h1 = icon_bar->h2 = icon_bar->h3 = icon_bar->h4 = GDI_NULL_HANDLE;
    icon_bar->need_draw_hint = MMI_FALSE;
    icon_bar->need_erase_hint = MMI_FALSE;

    /*  reset arrow icon */
    icon_bar->prev_arrow.normal_icon = NULL;
    icon_bar->prev_arrow.down_icon = NULL;
    icon_bar->next_arrow.normal_icon = NULL;
    icon_bar->next_arrow.down_icon = NULL;

    /* reset highlight icon */
    icon_bar->highlight = NULL;

    icon_bar->dynamic_update_handler = NULL;
    icon_bar->hide_callback = NULL;
    icon_bar->highlight_handler = NULL;
    icon_bar->idle_display_handler = NULL;
    for (i = 0; i < GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT; i++)
    {
        icon_bar->pause_interactive_UI_callback[i] = NULL;
    }
    for (i = 0; i < GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT; i++)
    {
        icon_bar->resume_interactive_UI_callback[i] = NULL;
    }
    icon_bar->pause_interactive_UI_callback_count = 0;
    icon_bar->resume_interactive_UI_callback_count = 0;

    icon_bar->target_layer = GDI_NULL_HANDLE;
    icon_bar->abm_layer = GDI_NULL_HANDLE;
    icon_bar->width = 0;
    icon_bar->height = 0;
    icon_bar->flags = 0;
    icon_bar->active = MMI_FALSE;
    current_icon_bar_pointer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_item
 * DESCRIPTION
 *  set one item of icon_bar
 *  Remark: the icon of all item should be the same dimension
 * PARAMETERS
 *  icon_bar            [IN]
 *  index               [IN]    index of item
 *  normal_icon         [IN]    up image of item
 *  down_icon           [IN]    down image of item
 *  content_icon            [IN]    content icon of item
 *  disabled_content_icon   [IN]    disabled content icon of item
 *  text_of_description [IN]    hint
 *  callback            [IN]    callback func when key pressed
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_item(
      gui_icon_bar_struct *icon_bar,
      U32 index,
      U8 *normal_icon,
      U8 *down_icon,
      U8 *content_icon,
      U8 *disabled_content_icon,
      U8 *text_of_description,
      GUIIconbarItemCallback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    MMI_DBG_ASSERT(index < icon_bar->count);
    MMI_DBG_ASSERT(normal_icon != NULL && down_icon != NULL);

    icon_bar->item[index].normal_icon = normal_icon;
    icon_bar->item[index].down_icon = down_icon;
    icon_bar->item[index].content_icon = content_icon;
    icon_bar->item[index].disabled_content_icon = disabled_content_icon;
    icon_bar->item[index].text_of_description = text_of_description;
    icon_bar->item[index].callback = callback;

    /* calculate item's dimension */
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
    {
        gdi_image_get_dimension(normal_icon, &width, &icon_bar->item_height);
        if (width != icon_bar->item_width)
        {
            icon_bar->item_width = width;
            gui_icon_bar_calculate_display_count(icon_bar);
        }
    }
    else
    {
        gdi_image_get_dimension(normal_icon, &icon_bar->item_width, &height);
        if (height != icon_bar->item_height)
        {
            icon_bar->item_height = height;
            gui_icon_bar_calculate_display_count(icon_bar);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_item_enable_state
 * DESCRIPTION
 *  set one item's enabled state of icon_bar
 * PARAMETERS
 *  icon_bar                [IN]
 *  index                   [IN]    index of item
 *  disabled                [IN]    ensabled state of item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_item_enable_state(
      gui_icon_bar_struct *icon_bar,
      U32 index,
      MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__	
    MMI_BOOL disabled_state;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  MMI_DBG_ASSERT(icon_bar != NULL);
  //  MMI_DBG_ASSERT(index < icon_bar->count);

    disabled_state = icon_bar->item[index].disabled;
#endif	
    icon_bar->item[index].disabled = (state == MMI_TRUE) ? MMI_FALSE : MMI_TRUE;
#ifdef __MMI_TOUCH_SCREEN__
    /* If change the disabled state, recover the pen handle of icon bar */
    if ((disabled_state != icon_bar->item[index].disabled) &&
        (index == icon_bar->first_displayed_item + icon_bar->focused_item))
    {
        gui_icon_bar_reset_pen_state(icon_bar);
    }
#endif /* __MMI_TOUCH_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_arrow_icon
 * DESCRIPTION
 *  set arrow icon of icon_bar
 * PARAMETERS
 *  icon_bar            [IN]
 *  arrow               [IN]    left arrow or right arrow
 *  normal_icon         [IN]    up image of item
 *  down_icon           [IN]    down image of item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_arrow_icon(
      gui_icon_bar_struct *icon_bar,
      gui_icon_bar_arrow_enum arrow,
      U8 *normal_icon,
      U8 *down_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (arrow == GUI_ICON_BAR_ARROW_PREV)
    {
        icon_bar->prev_arrow.normal_icon = normal_icon;
        icon_bar->prev_arrow.down_icon = down_icon;
    }
    else if (arrow == GUI_ICON_BAR_ARROW_NEXT)
    {
        icon_bar->next_arrow.normal_icon = normal_icon;
        icon_bar->next_arrow.down_icon = down_icon;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_highlight_icon
 * DESCRIPTION
 *  set highlight icon of icon_bar
 * PARAMETERS
 *  icon_bar            [IN]
 *  highlight           [IN]    highlight
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_highlight_icon(
      gui_icon_bar_struct *icon_bar,
      U8 *highlight_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->highlight = highlight_icon;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_align
 * DESCRIPTION
 *  set icon_bar's align type
 * PARAMETERS
 *  icon_bar            [IN]
 *  align_type          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_align(
      gui_icon_bar_struct *icon_bar,
      gui_icon_bar_align_enum align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 align_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    MMI_DBG_ASSERT(align_type > GUI_ICON_BAR_ALIGN_START &&
               align_type < GUI_ICON_BAR_ALIGN_END);
    align_flag = ((1 << (U32)(align_type - GUI_ICON_BAR_ALIGN_BY_HEAD)) <<
                 GUI_ICON_BAR_FLAG_ALIGN_BIT_OFFSET);
    icon_bar->flags &= ~GUI_ICON_BAR_FLAG_ALIGN_MASK;
    icon_bar->flags |= align_flag;
    icon_bar->flags |= GUI_ICON_BAR_FLAG_SETTED_ALIGN;
    gui_icon_bar_calculate_item_position(icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_target_layer
 * DESCRIPTION
 *  set icon_bar's target layer
 * PARAMETERS
 *  icon_bar            [IN]
 *  target_layer        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_target_layer(
      gui_icon_bar_struct *icon_bar,
      GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_abm_layer
 * DESCRIPTION
 *  set icon_bar's abm layer
 * PARAMETERS
 *  icon_bar            [IN]
 *  abm_layer        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_abm_layer(
      gui_icon_bar_struct *icon_bar,
      GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->abm_layer = abm_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_fixed_position_info
 * DESCRIPTION
 *  Set fixed position information to icon bar.
 * PARAMETERS
 *  icon_bar            [IN]
 *  item_width          [IN]
 *  item_height         [IN]
 *  item_gap            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_fixed_position_info(
      gui_icon_bar_struct *icon_bar,
      S32 item_width,
      S32 item_height,
      S32 item_gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->item_gap = item_gap;
    icon_bar->item_width = item_width;
    icon_bar->item_height = item_height;
    icon_bar->auto_arrange_item = MMI_FALSE;
    if ((icon_bar->flags & GUI_ICON_BAR_FLAG_ALIGN_MASK) == GUI_ICON_BAR_FLAG_ALIGN_INIT ||
        (icon_bar->flags & GUI_ICON_BAR_FLAG_EQUIDISTANCE_ALIGN))
    {
        icon_bar->flags &= ~GUI_ICON_BAR_FLAG_ALIGN_MASK;
        icon_bar->flags |= GUI_ICON_BAR_FLAG_CENTER_ALIGN;
    }
    gui_icon_bar_calculate_display_count(icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_is_active
 * DESCRIPTION
 *  set icon_bar's active state
 * PARAMETERS
 *  icon_bar            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_icon_bar_is_active(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    return icon_bar->active;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_highlight_handler
 * DESCRIPTION
 *  set icon_bar's highlight handler
 * PARAMETERS
 *  icon_bar            [IN]
 *  f                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_highlight_handler(
      gui_icon_bar_struct *icon_bar,
      void (*f)(S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->highlight_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_idle_display_handler
 * DESCRIPTION
 *  set icon_bar's highlight handler
 * PARAMETERS
 *  icon_bar            [IN]
 *  index               [IN]
 *  f                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_idle_display_handler(
      gui_icon_bar_struct *icon_bar,
      void (*f)(S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->idle_display_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_move
 * DESCRIPTION
 *  move icon_bar
 * PARAMETERS
 *  icon_bar        [IN]
 *  x               [IN]
 *  y               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_move(gui_icon_bar_struct *icon_bar, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->x = x;
    icon_bar->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_resize
 * DESCRIPTION
 *  resize icon_bar
 * PARAMETERS
 *  icon_bar        [IN]
 *  width           [IN]
 *  height          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_resize(gui_icon_bar_struct *icon_bar, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->width = width;
    icon_bar->height = height;
    gui_icon_bar_calculate_display_count(icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_hide_function
 * DESCRIPTION
 *  set the hide callback function of the icon_bar
 * PARAMETERS
 *  icon_bar        [IN]        Pointer of icon_bar component
 *  f               [IN]        New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_hide_function(
      gui_icon_bar_struct *icon_bar,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    icon_bar->hide_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_update_handler
 * DESCRIPTION
 *  set the update callback function of the icon_bar
 * PARAMETERS
 *  icon_bar        [IN]        Pointer of icon_bar component
 *  f               [IN]        New update callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_update_handler(
      gui_icon_bar_struct *icon_bar,
      MMI_BOOL (*f) (
                U32 start_index,
                U32 item_count,
                PU8 *normal_icon,
                PU8 *down_icon,
                PU8 *content_icon,
                PU8 *disabled_content_icon,
                PU8 *text_of_despription))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    icon_bar->dynamic_update_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_show
 * DESCRIPTION
 *  show icon_bar component
 * PARAMETERS
 *  icon_bar        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_show(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;
    S32 layer_offset_x = 0, layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    /* if display cout is zero, do nothing */
    if (icon_bar->display_count == 0)
    {
        return;
    }

    /* if not enable disable, just return */
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return;
    }

    gdi_layer_lock_frame_buffer();
    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(icon_bar->target_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    }
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        icon_bar->x - layer_offset_x,
        icon_bar->y - layer_offset_y,
        icon_bar->x + icon_bar->width - 1 - layer_offset_x,
        icon_bar->y + icon_bar->height - 1 - layer_offset_y);
    /* show icon_bar's background */
    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        abm_layer = gdi_set_alpha_blending_source_layer(icon_bar->abm_layer);
    }
    icon_bar->hide_callback(
        icon_bar->x - layer_offset_x,
        icon_bar->y - layer_offset_y,
        icon_bar->x + icon_bar->width - 1 - layer_offset_x,
        icon_bar->y + icon_bar->height - 1 - layer_offset_y);    
    if (icon_bar->abm_layer != GDI_NULL_HANDLE &&
        icon_bar->abm_layer != GDI_ERROR_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    /* if icon_bar has been actived, draw highlight */
    if (icon_bar->active == MMI_TRUE)
    {
        gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
    }

    /* draw items */
    for (i = 0; i < icon_bar->display_count; i++)
    {
        gui_icon_bar_draw_item(icon_bar, i);
    }

    /* show arrow icon */
    if (icon_bar->count > icon_bar->display_count)
    {
        gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_PREV);
        gui_icon_bar_draw_arrow(icon_bar, GUI_ICON_BAR_ARROW_NEXT);
    }

    gdi_layer_pop_clip();
    if (icon_bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_active
 * DESCRIPTION
 *  active icon_bar component
 * PARAMETERS
 *  icon_bar        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_active(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    if (icon_bar->active == MMI_FALSE)
    {
        icon_bar->active = MMI_TRUE;
        gui_icon_bar_set_key_handler();
        gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
        gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_deactive
 * DESCRIPTION
 *  deactive icon_bar component
 * PARAMETERS
 *  icon_bar        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_deactive(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    gui_icon_bar_clear_key_handler();
    icon_bar->active = MMI_FALSE;
    if (icon_bar->need_draw_hint == MMI_TRUE)
    {
        gui_cancel_timer(gui_icon_bar_draw_hint);
        icon_bar->need_draw_hint = MMI_FALSE;
    }
    if (icon_bar->need_erase_hint == MMI_TRUE)
    {
        gui_icon_bar_erase_hint();
        icon_bar->need_erase_hint = MMI_FALSE;
    }
    icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    if (icon_bar->prev_arrow.state != GUI_ICON_BAR_ICON_STATE_DISABLED)
    {
        icon_bar->prev_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    }
    if (icon_bar->next_arrow.state != GUI_ICON_BAR_ICON_STATE_DISABLED)
    {
        icon_bar->next_arrow.state = GUI_ICON_BAR_ICON_STATE_NORMAL;
    }
    gui_icon_bar_show(icon_bar);
    gdi_layer_blt_previous(
        icon_bar->x,
        icon_bar->y,
        icon_bar->x + icon_bar->width - 1,
        icon_bar->y + icon_bar->height - 1);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_translate_pen_event
 * DESCRIPTION
 *  translate icon_bar's pen event
 * PARAMETERS
 *  icon_bar                [IN]
 *  pen_event               [IN]
 *  x                       [IN]
 *  y                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_icon_bar_translate_pen_event(
          gui_icon_bar_struct *icon_bar,
          mmi_pen_event_type_enum pen_event,
          S16 x,
          S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->flags & GUI_ICON_BAR_FLAG_DISABLE_DISPLAY)
    {
        return MMI_FALSE;
    }
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:            
            ret = gui_icon_bar_pen_down_handler(icon_bar, x, y);
            break;

        case MMI_PEN_EVENT_UP:
            ret = gui_icon_bar_pen_up_handler(icon_bar, x, y);
            break;

        case MMI_PEN_EVENT_MOVE:
            ret = gui_icon_bar_pen_move_handler(icon_bar, x, y);
            break;

        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
            break;

        case MMI_PEN_EVENT_ABORT:
            ret = gui_icon_bar_pen_abort_handler(icon_bar, x, y);
            break;

        default:
            MMI_DBG_ASSERT(0);
    }
    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_flags_on
 * DESCRIPTION
 *  Turn on flag of icon bar.
 * PARAMETERS
 *  icon_bar                [IN]
 *  flag                    [IN]    flag of icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_flags_on(
      gui_icon_bar_struct *icon_bar,
      U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->flags |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_flags_off
 * DESCRIPTION
 *  Turn off flag of icon bar.
 * PARAMETERS
 *  icon_bar                [IN]
 *  flag                    [IN]    flag of icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_flags_off(
      gui_icon_bar_struct *icon_bar,
      U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->flags &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_get_hint_layer_handle
 * DESCRIPTION
 *  Get the hint layer handle
 * PARAMETERS
 *  icon_bar                [IN]
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
gdi_handle gui_icon_bar_get_hint_layer_handle(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    return icon_bar->hint_layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_set_display_direction
 * DESCRIPTION
 *  set icon_bar's display direction.
 * PARAMETERS
 *  icon_bar            [IN]
 *  direction           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_set_display_direction(
      gui_icon_bar_struct *icon_bar,
      gui_icon_bar_display_direction_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    MMI_DBG_ASSERT(direction > GUI_ICON_BAR_DISPLAY_DIRECTION_START &&
                   direction < GUI_ICON_BAR_DISPLAY_DIRECTION_END);
    if (direction == GUI_ICON_BAR_DISPLAY_HORIZONTAL)
    {
        if (icon_bar->flags & GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY)
        {
            return;            
        }
        icon_bar->flags &= ~GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY;
        icon_bar->flags |= GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY;
    }
    else
    {
        if (icon_bar->flags & GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY)
        {
            return;            
        }
        icon_bar->flags &= ~GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY;
        icon_bar->flags |= GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY;
    }
    gui_icon_bar_calculate_display_count(icon_bar);
}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_pause_interactive_UI_callback
 * DESCRIPTION
 *  set icon_bar's callback to pause interactive UI
 * PARAMETERS
 *  icon_bar            [IN]
 *  f                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_pause_interactive_UI_callback(
      gui_icon_bar_struct *icon_bar,
      void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->pause_interactive_UI_callback_count >= GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT)
    {
        return;
    }

    icon_bar->pause_interactive_UI_callback[icon_bar->pause_interactive_UI_callback_count] = f;
    icon_bar->pause_interactive_UI_callback_count++;
}


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_resume_interactive_UI_callback
 * DESCRIPTION
 *  set icon_bar's callback to resume interactive UI
 * PARAMETERS
 *  icon_bar            [IN]
 *  index               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_resume_interactive_UI_callback(
      gui_icon_bar_struct *icon_bar,
      void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    if (icon_bar->resume_interactive_UI_callback_count >= GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT)
    {
        return;
    }

    icon_bar->resume_interactive_UI_callback[icon_bar->resume_interactive_UI_callback_count] = f;
    icon_bar->resume_interactive_UI_callback_count++;
}
#endif

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_reset_pen_state
 * DESCRIPTION
 *  reset icon bar's pen state
 * PARAMETERS
 *  icon_bar                [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_reset_pen_state(gui_icon_bar_struct *icon_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);

    /* reset the pen state of icon bar */
    if (icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_DOWN ||
        icon_bar->focused_item_state == GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN)
    {
        /* stop timer of draw hint and erase hint */
        if (icon_bar->need_draw_hint == MMI_TRUE)
        {
            gui_cancel_timer(gui_icon_bar_draw_hint);
            icon_bar->need_draw_hint = MMI_FALSE;
        }
        if (icon_bar->need_erase_hint == MMI_TRUE)
        {
            gui_icon_bar_erase_hint();
            icon_bar->need_erase_hint = MMI_FALSE;
        }
        gui_icon_bar_erase_highlight(icon_bar, icon_bar->focused_item);
        icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_ABORT;
        gui_icon_bar_draw_highlight(icon_bar, icon_bar->focused_item);
        gui_icon_bar_draw_item(icon_bar, icon_bar->focused_item);
        gdi_layer_blt_previous(
            icon_bar->x,
            icon_bar->y,
            icon_bar->x + icon_bar->width - 1,
            icon_bar->y + icon_bar->height - 1);
    }
    if (icon_bar->focused_item_state != GUI_ICON_BAR_ICON_STATE_NORMAL)
    {
        icon_bar->focused_item_state = GUI_ICON_BAR_ICON_STATE_PEN_ABORT;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  gui_icon_bar_register_item_refresh_callback
 * DESCRIPTION
 *  set icon_bar's refresh callback
 * PARAMETERS
 *  icon_bar            [IN]
 *  f                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_icon_bar_register_item_refresh_callback(
      gui_icon_bar_struct *icon_bar,
      MMI_BOOL (*f)(S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(icon_bar != NULL);
    icon_bar->item_refresh_callback = f;
}

