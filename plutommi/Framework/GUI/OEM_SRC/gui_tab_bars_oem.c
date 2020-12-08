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

/*******************************************************************************
 * Filename:
 * ---------
 *  gui_tab_bars_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Extract the codes related drawing into this file for oem
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
/*****************************************************************************
* Include
*****************************************************************************/
#include "MMI_features.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_tab_bars_pre_oem.h"
#include "gui_tab_bars.h"
#include "gui_tab_bars_post_oem.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "gui_theme_struct.h"
#include "gui.h"
#include "gdi_include.h"
#include "CustThemesRes.h"
#include "gdi_const.h"
#include "gui_typedef.h"
#include "gui_windows.h"
#include "wgui_inputs.h"
#include "mmi_rp_app_uiframework_def.h"

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
extern horizontal_tab_bar *UI_current_horizontal_tab_bar;

#ifdef __MMI_OP11_TAB_BAR__

UI_filled_area tab_left_no_response_filler = {
    UI_FILLED_AREA_TYPE_BITMAP,
    (U8*)NULL,
    NULL,
    {255,255,255,100},
    {205,205,205,205},
    {205,205,205,205},
    {205,205,205,205},
    205};

UI_filled_area tab_no_response_filler = {
    UI_FILLED_AREA_TYPE_BITMAP,
    (U8*)NULL,
    NULL,
    {255,255,255,100},
    {205,205,205,205},
    {205,205,205,205},
    {205,205,205,205},
    205};

UI_filled_area tab_right_no_response_filler = {
    UI_FILLED_AREA_TYPE_BITMAP,
    (U8*)NULL,
    NULL,
    {255,255,255,100},
    {205,205,205,205},
    {205,205,205,205},
    {205,205,205,205},
    205};
    
#endif /* __MMI_OP11_TAB_BAR__ */


/*****************************************************************************
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_get_item_position
 * DESCRIPTION
 *  get item position of tab bar
 * PARAMETERS
 *  tb          [IN/OUT]        The tab bar control
 *  index       [IN]            index of tab
 *  x1          [OUT]           tab position
 *  x2          [OUT]           tab position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_get_item_position(horizontal_tab_bar *tb, S32 index, S32 *x1, S32 *x2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = tb->tab_area_x;
    for (i = tb->first_displayed_item; i <= tb->last_displayed_item; i++)
    {
        if (i == index)
        {
            *x1 = x;
            if (i == tb->focused_item)
            {
                *x2 = x + tb->focused_tab_width - 1;
            }
            else
            {
                *x2 = x + tb->tab_width - 1;
            }

            if (i == tb->last_displayed_item && tb->n_items >= tb->n_displayable_item)
            {
                *x2 = tb->tab_area_x + tb->tab_area_width - 1;
            }
            /* The gap between item is 2 * GUI_TAB_BAR_ITEM_GAP */
            *x1 += GUI_TAB_BAR_ITEM_GAP;
            *x2 -= GUI_TAB_BAR_ITEM_GAP;
            return;
        }

        if (i == tb->focused_item)
        {
            x += tb->focused_tab_width;
        }
        else
        {
            x += tb->tab_width;
        }
    }
    MMI_DBG_ASSERT(0);
    *x1 = *x2 = 0;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_left_arrow
 * DESCRIPTION
 *  show left arrow
 * PARAMETERS
 *  tb                  [IN/OUT]        The tab bar control
 *  tab_y_offset        [IN]            tab y offset
 *  x1                  [IN]            x position
 *  x2                  [IN]            x position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_show_left_arrow(horizontal_tab_bar *tb, S32 tab_y_offset, S32 x1, S32 x2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img;
    S32 iw, ih;
    gdi_handle old_src_layer,act_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(tab_y_offset);
#ifdef __MMI_FTE_SUPPORT__
    img = (PU8)tb->theme->tab_bar_left_indicator;
#else
    img = (PU8) GetImage(tb->theme->left_button_icon);
#endif
    if (img)
    {
        S32 icon_x, icon_y;
        gui_measure_image(img, &iw, &ih);
   #if (!defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__))
        icon_x = x1 + UI_TAB_BAR_ARROW_ICON_GAP;
   #else
        icon_x = tb->x + GUI_TAB_ARROW_INDENT_X;
   #endif

   #ifdef __MMI_FTE_SUPPORT__
        icon_y = tb->y + tb->tab_area_height - ih;
   #else /* __MMI_FTE_SUPPORT__ */
        icon_y = tb->y + ((tb->tab_area_height - ih) >> 1);
   #endif /* __MMI_FTE_SUPPORT__ */

   #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_FTE_SUPPORT__)
        gdi_get_alpha_blending_source_layer(&old_src_layer);
        gdi_layer_get_active(&act_layer);
        gdi_set_alpha_blending_source_layer(act_layer);
   #endif
        gdi_layer_push_and_set_clip(icon_x, icon_y, icon_x + iw -1, icon_y + ih - 1);
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_128X160__) && !defined(__MMI_MAINLCD_176X220__)
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(icon_x, icon_y, icon_x + iw - 1, icon_y + ih - 1, GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gdi_draw_solid_rect(icon_x, icon_y, icon_x + iw - 1, icon_y + ih - 1, GDI_COLOR_WHITE);
        }
 #endif       
        gdi_image_draw_blend2layers(
            icon_x,
            icon_y + (tb->left_button_pressed ? 1 : 0),
            img);


        gdi_layer_pop_clip();
   #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_FTE_SUPPORT__)
        gdi_set_alpha_blending_source_layer(old_src_layer);
   #endif

        gdi_layer_blt_previous(icon_x, icon_y, icon_x + iw -1, icon_y + ih - 1);

   #ifdef __MMI_TOUCH_SCREEN__
       #if (!defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__))
            /* The pen area is larger than the icon itself */
            tb->pen_state.left_button_x = (S16) tb->tab_area_x;
            tb->pen_state.left_button_y = (S16) tb->y;
            tb->pen_state.left_button_width = (S16) iw + (UI_TAB_BAR_ARROW_ICON_GAP << 1);
            tb->pen_state.left_button_height = (S16) tb->tab_area_height;
       #else /* __MMI_MAINLCD_320X240__ */
            /* The pen area is larger than the icon itself */
            tb->pen_state.left_button_x = (S16) icon_x;
            tb->pen_state.left_button_y = (S16) icon_y;
            tb->pen_state.left_button_width = (S16) iw;
            tb->pen_state.left_button_height = (S16) ih;
       #endif /* __MMI_MAINLCD_320X240__ */
   #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_right_arrow
 * DESCRIPTION
 *  show right arrow
 * PARAMETERS
 *  tb                  [IN/OUT]        The tab bar control
 *  tab_y_offset        [IN]            tab y offset
 *  x1                  [IN]            x position
 *  x2                  [IN]            x position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_show_right_arrow(horizontal_tab_bar *tb, S32 tab_y_offset, S32 x1, S32 x2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img;
    S32 iw, ih;
    gdi_handle old_src_layer,act_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(tab_y_offset);
#ifdef __MMI_FTE_SUPPORT__
    img = (PU8)tb->theme->tab_bar_right_indicator;
#else
    img = (PU8) GetImage(tb->theme->right_button_icon);
#endif

    if (img)
    {
        S32 icon_x, icon_y;
        gui_measure_image(img, &iw, &ih);
    #if (!defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__))
        icon_x = x2 - UI_TAB_BAR_ARROW_ICON_GAP - iw;
    #else
        icon_x = tb->x + tb->width - 1 - GUI_TAB_ARROW_INDENT_X- iw;
    #endif

    #ifdef __MMI_FTE_SUPPORT__
        icon_y = tb->y + tb->tab_area_height - ih;
    #else /* __MMI_FTE_SUPPORT__ */
        icon_y = tb->y + ((tb->tab_area_height - ih) >> 1);
    #endif /* __MMI_FTE_SUPPORT__ */

    #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_FTE_SUPPORT__)
        gdi_get_alpha_blending_source_layer(&old_src_layer);
        gdi_layer_get_active(&act_layer);
        gdi_set_alpha_blending_source_layer(act_layer);
    #endif

        gdi_layer_push_and_set_clip(icon_x, icon_y, icon_x + iw -1, icon_y + ih - 1);
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_128X160__) && !defined(__MMI_MAINLCD_176X220__)       
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(icon_x, icon_y, icon_x + iw - 1, icon_y + ih - 1, GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gdi_draw_solid_rect(icon_x, icon_y, icon_x + iw - 1, icon_y + ih - 1, GDI_COLOR_WHITE);
        }
#endif
        gdi_image_draw_blend2layers(
            icon_x,
            icon_y + (tb->right_button_pressed ? 1 : 0),
            img);

        gdi_layer_pop_clip();

   #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_FTE_SUPPORT__)
        gdi_set_alpha_blending_source_layer(old_src_layer);
   #endif
        gdi_layer_blt_previous(icon_x, icon_y, icon_x + iw -1, icon_y + ih - 1);

   #ifdef __MMI_TOUCH_SCREEN__
       #if (!defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__))
            /* The pen area is larger than the icon itself */
            tb->pen_state.right_button_x = (S16) icon_x - UI_TAB_BAR_ARROW_ICON_GAP;
            tb->pen_state.right_button_y = (S16) tb->y;
            tb->pen_state.right_button_width = (S16) iw + (UI_TAB_BAR_ARROW_ICON_GAP << 1);
            tb->pen_state.right_button_height = (S16) tb->tab_area_height;
       #else /* __MMI_MAINLCD_320X240__ */
            /* The pen area is larger than the icon itself */
            tb->pen_state.right_button_x = (S16) icon_x;
            tb->pen_state.right_button_y = (S16) icon_y;
            tb->pen_state.right_button_width = (S16) iw;
            tb->pen_state.right_button_height = (S16) ih;
       #endif /* __MMI_MAINLCD_320X240__ */
   #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_get_item_image
 * DESCRIPTION
 *  get item position of tab bar
 * PARAMETERS
 *  tb          [IN/OUT]        The tab bar control
 *  index       [IN]            index of tab
 *  x1          [OUT]           tab position
 *  x2          [OUT]           tab position
 * RETURNS
 *  void
 *****************************************************************************/
static PU8 gui_horizontal_tab_bar_get_item_image(UI_filled_area *filler, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 image = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filler && (filler->flags & UI_FILLED_AREA_TYPE_BITMAP))
    {
        image = filler->b;
    }
    else if (image_id && filler == NULL)
    {
        image = (PU8)GetImage(image_id);
    }
    return image;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_item_background
 * DESCRIPTION
 *  draw filler
 * PARAMETERS
 *  x1          [IN]        draw area
 *  y1          [IN]        draw area
 *  x2          [IN]        draw area
 *  y2          [IN]        draw area
 *  imageid     [IN]        image id
 *  filler      [IN]        filled area
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_show_item_background(S32 x1, S32 y1, S32 x2, S32 y2, gui_tab_bar_background_enum background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_horizontal_tab_bar_theme *theme = UI_current_horizontal_tab_bar->theme;
    UI_filled_area *middle_filler = NULL;    
#if !defined(__MMI_TAB_BAR_SLIM__) || defined(__MMI_OP11_TAB_BAR__)
    UI_filled_area *left_filler = NULL;
    UI_filled_area *right_filler = NULL;
    S32 image_height;
    S32 image_width;
    PU8 left_image = NULL;
    PU8 right_image = NULL;
#endif /*__MMI_TAB_BAR_SLIM__*/
    PU8 middle_image = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (background)
    {
        case GUI_TAB_BAR_NORMAL_BACKGROUND:

        #ifndef __MMI_TAB_BAR_SLIM__
            left_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->normal_l_tab_filler,
                    theme->normal_l_tab_icon);
            left_filler = theme->normal_l_tab_filler;
            right_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->normal_r_tab_filler,
                    theme->normal_r_tab_icon);
            right_filler = theme->normal_r_tab_filler;

            middle_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->normal_tab_filler,
                    theme->normal_tab_icon);
        #endif /*__MMI_TAB_BAR_SLIM__*/
            middle_filler = theme->normal_tab_filler;

            break;
            
       case GUI_TAB_BAR_HIGHLIGHT_BACKGROUND:

        #ifndef __MMI_TAB_BAR_SLIM__
            left_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->focused_l_tab_filler,
                    theme->focused_l_tab_icon);
            left_filler = theme->focused_l_tab_filler;
            right_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->focused_r_tab_filler,
                    theme->focused_r_tab_icon);
            right_filler = theme->focused_r_tab_filler;

            middle_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->focused_tab_filler,
                    theme->focused_tab_icon);
        #endif /*__MMI_TAB_BAR_SLIM__*/
            middle_filler = theme->focused_tab_filler;

            break;

       case GUI_TAB_BAR_BLINK_BACKGROUND:
        #ifndef __MMI_TAB_BAR_SLIM__
            left_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->blinking_l_tab_filler,
                    theme->blinking_l_tab_icon);
            left_filler = theme->blinking_l_tab_filler;
            right_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->blinking_r_tab_filler,
                    theme->blinking_r_tab_icon);
            right_filler = theme->blinking_r_tab_filler; 

            middle_image = 
                gui_horizontal_tab_bar_get_item_image(
                    theme->blinking_tab_filler,
                    theme->blinking_tab_icon);
        #endif /*__MMI_TAB_BAR_SLIM__*/
            middle_filler = theme->blinking_tab_filler;

            break;

       case GUI_TAB_BAR_DISABLED_BACKGROUND:
           middle_image = (U8*)GetImage(IMG_HORIZONTAL_DISABLED_TAB);
           break;

    #ifdef __MMI_OP11_TAB_BAR__
        case GUI_TAB_BAR_NO_RESPONSE_BACKGROUND:
            left_image = 
                gui_horizontal_tab_bar_get_item_image(
                    &tab_left_no_response_filler,
                    NULL);
            left_filler = &tab_left_no_response_filler;
            middle_image =
                gui_horizontal_tab_bar_get_item_image(
                    &tab_no_response_filler,
                    NULL);
            middle_filler = &tab_no_response_filler;
            right_image =
                gui_horizontal_tab_bar_get_item_image(
                    &tab_right_no_response_filler,
                    NULL);
            right_filler = &tab_right_no_response_filler;
            break;
    #endif

       default:
            MMI_ASSERT(0);
            break;
    }
    
    gdi_layer_push_clip();


#if defined(__OP01_FWPBW__) && defined(__MMI_MAINLCD_128X64__)
    if (background == GUI_TAB_BAR_HIGHLIGHT_BACKGROUND)
    {
        
        /* clear underline */
        gdi_draw_line(x1, y2, x2, y2, GDI_COLOR_WHITE);
    }
    else
    {
        /* redraw underline */
        gdi_draw_line(x1, y2, x2, y2, GDI_COLOR_BLACK);
    }
    /* left vertical line */
    gdi_draw_line(x1, y1 + 2, x1, y2 - 1, GDI_COLOR_BLACK);
    /* top horizontal line */
    gdi_draw_line(x1 + 1, y1 + 1, x2 - 1, y1 + 1, GDI_COLOR_BLACK);
    /* right vertical line */
    gdi_draw_line(x2, y1 + 2, x2, y2 - 1, GDI_COLOR_BLACK);
    
#else
#if defined(__MMI_FTE_SUPPORT__) && (!defined(__MMI_OP11_TAB_BAR__))
    if (background == GUI_TAB_BAR_HIGHLIGHT_BACKGROUND)
    {
        gdi_layer_set_clip(x1, y1, x2, y2 + GUI_TAB_BAR_OVERLAP_WITH_TITLE);
        if (middle_image == NULL)
        {
            gui_draw_filled_area(x1, y1, x2, y2 + GUI_TAB_BAR_OVERLAP_WITH_TITLE, middle_filler);
        }
        else
        {
            gdi_image_draw_resized_blend2layers(x1, y1, x2 - x1 + 1, y2 + GUI_TAB_BAR_OVERLAP_WITH_TITLE - y1 + 1, middle_image);
        }
    }
    else if (background == GUI_TAB_BAR_DISABLED_BACKGROUND)
    {
        gdi_layer_set_clip(x1, y1, x2, y2 + GUI_TAB_BAR_OVERLAP_WITH_TITLE);
        gdi_image_draw_resized_blend2layers(x1, y1, x2 - x1 + 1, y2 - y1 + 1, (PU8)GetImage(IMG_HORIZONTAL_DISABLED_TAB));
    }
    else
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
        if (middle_image == NULL)
        {
            gui_draw_filled_area(x1, y1, x2, y2, middle_filler);
        }
        else
        {
            gdi_image_draw_resized_blend2layers(x1, y1, x2 - x1 + 1, y2 - y1 + 1, middle_image);
        }
    }

#else /* __MMI_FTE_SUPPORT__ */

#if !defined(__MMI_TAB_BAR_SLIM__) && defined(__MMI_OP11_TAB_BAR__)
	if (background != GUI_TAB_BAR_DISABLED_BACKGROUND)
	{
    if (left_image == NULL)
    {
        gdi_layer_set_clip(x1, y1, x1 + GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH - 1, y2);
        gui_draw_filled_area(x1, y1, x1 + GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH - 1, y2,left_filler);
        x1 += GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH;
    }
    else
    {
        gdi_image_get_dimension(left_image, &image_width, &image_height);
        gdi_layer_set_clip(x1, y1, x1 + image_width - 1, y2);
        gdi_image_draw(x1, y1, left_image);
        x1 += image_width;
    }

    if (right_image == NULL)
    {
        gdi_layer_set_clip(x2 - GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH + 1, y1, x2, y2);
        gui_draw_filled_area(x2 - GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH + 1, y1, x2, y2, right_filler);
        x2 -= GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH;
    }
    else
    {
        gdi_image_get_dimension(right_image, &image_width, &image_height);
        gdi_layer_set_clip(x2 - image_width + 1, y1, x2, y2);
        gdi_image_draw(x2 - image_width + 1, y1, right_image);
        x2 -= image_width;
    }
	}

    if(middle_image == NULL)
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
        gui_draw_filled_area(x1, y1, x2, y2, middle_filler);
    }
    else
    {
        gdi_image_get_dimension(middle_image, &image_width, &image_height);
        while(x1 <= x2)
        {
            if(x1 + image_width - 1 < x2)
            {
                gdi_layer_set_clip(x1, y1, x1 + image_width - 1, y2);
            }
            else
            {
                gdi_layer_set_clip(x1, y1, x2, y2);
            }
            gdi_image_draw(x1, y1, middle_image);
            x1 += image_width;
        }
    }
#else /*!defined(__MMI_TAB_BAR_SLIM__) && defined(__MMI_OP11_TAB_BAR__)*/
    
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (middle_image == NULL)
    {
        gui_draw_filled_area(x1, y1, x2, y2, middle_filler);
    }
    else
    {
        gdi_image_draw_resized_blend2layers(x1, y1, x2 - x1 + 1, y2 - y1 + 1, middle_image);
    }
#endif
    
#endif /* __MMI_FTE_SUPPORT__ */

#endif
    
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_scrolling_text_handler
 * DESCRIPTION
 *  Scolling the focused item's text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void gui_horizontal_tab_bar_show_scrolling_text_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 focused_item_x1, focused_item_y1, focused_item_x2, focused_item_y2;
    horizontal_tab_bar *tb = UI_current_horizontal_tab_bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_get_item_position(tb, tb->focused_item, &focused_item_x1, &focused_item_x2);
    focused_item_y2 = tb->y + tb->tab_area_height - 1;
    focused_item_y1 = focused_item_y2 - tb->focused_tab_height + 1;
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gui_horizontal_tab_bar_show_item_background(focused_item_x1, focused_item_y1, focused_item_x2, focused_item_y2, GUI_TAB_BAR_HIGHLIGHT_BACKGROUND);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_setup_target_lcd_and_layer_oem
 * DESCRIPTION
 *  set up horizontal tab bar taget lcd, target layer and alpha_blend_layer
 * PARAMETERS
 *  tb      [IN]    the struct of horizontal tab bar
 * RETURNS
 *  the old lcd handle
 *****************************************************************************/
gdi_handle gui_horizontal_tab_bar_setup_target_lcd_and_layer_oem(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active (&old_lcd_handle);
    if(tb->target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
    if(tb->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    if(tb->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(tb->target_layer);
    }
    if(tb->alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_push_and_set_alpha_blending_source_layer(tb->alpha_blend_layer);
    }
    return old_lcd_handle;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_restore_target_lcd_and_layer_oem
 * DESCRIPTION
 *  restore horizontal tab bar taget lcd, target layer and alpha_blend_layer
 * PARAMETERS
 *  tb              [IN]    the struct of horizontal tab bar
 *  old_lcd_handle  [IN]    the old lcd handle
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_restore_target_lcd_and_layer_oem(horizontal_tab_bar *tb, gdi_handle old_lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(tb->alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    if(tb->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    if(tb->target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    if(tb->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_locate_focused_item_oem
 * DESCRIPTION
 *  Locate the tab bar focused item
 * PARAMETERS
 *  tb          [IN/OUT]    Pointer of horizontal tab bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_locate_focused_item_oem(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(tb->style&GUI_TAB_BAR_STYLE_AUTO_RESIZE_ITEM_WIDTH)
    {
        if(tb->n_items > GUI_TAB_DISPLAY_ITEM_MAX)
        {
            tb->n_displayable_item = GUI_TAB_DISPLAY_ITEM_MAX;
        }
        else if(tb->n_items == 1)
        {
            tb->n_displayable_item = 2;
        }
        else
        {
            tb->n_displayable_item = tb->n_items;
        }
        tb->focused_tab_width = tb->tab_width = tb->tab_area_width/tb->n_displayable_item;
        tb->tab_text_width = tb->tab_width - ((GUI_TAB_TEXT_INDENT_X) << 1);
    }
    else
    {
        tb->n_displayable_item = tb->tab_area_width / tb->tab_width;
    }

    if (tb->n_displayable_item > UI_TAB_BAR_SHOW_AHEAD)
    {
        tb->n_item_ahead = UI_TAB_BAR_SHOW_AHEAD;
    }
    else
    {
        tb->n_item_ahead = 0;
    }

    if (tb->n_items <= tb->n_displayable_item)
    {
        tb->first_displayed_item = 0;
        tb->last_displayed_item = tb->n_items - 1;
    }
    else if (tb->focused_item <= tb->n_item_ahead)
    {
        tb->first_displayed_item = 0;
        tb->last_displayed_item = tb->n_displayable_item - 1;
    }
    else if (tb->focused_item - tb->n_item_ahead + tb->n_displayable_item - 1 <= tb->n_items - 1)
    {
        tb->first_displayed_item = tb->first_displayed_item; //tb->focused_item - tb->n_item_ahead;
        tb->last_displayed_item = tb->first_displayed_item + tb->n_displayable_item - 1;
    }
    else if (tb->focused_item <= tb->first_displayed_item + tb->n_displayable_item - 1)
    {
         tb->first_displayed_item = tb->first_displayed_item; //tb->focused_item - tb->n_item_ahead;
         tb->last_displayed_item = tb->first_displayed_item + tb->n_displayable_item - 1;
    }
    else
    {
        tb->first_displayed_item = tb->n_items - tb->n_displayable_item;
        tb->last_displayed_item = tb->n_items - 1;
    }
    
//#ifdef __MMI_FTE_SUPPORT__
    /* when in FTE project, always let a normal item at border */
    if((tb->focused_item == tb->last_displayed_item) && (tb->last_displayed_item != tb->n_items - 1))
    {
        tb->first_displayed_item++;
        tb->last_displayed_item++;
    }
    else if((tb->focused_item == tb->first_displayed_item) && (tb->first_displayed_item != 0))
    {
        tb->first_displayed_item--;
        tb->last_displayed_item--;
    }
//#endif

}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_scrolling_text_handler
 * DESCRIPTION
 *  Scolling the focused item's text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void gui_horizontal_tab_bar_focused_scrolling_text_handler_oem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&(UI_current_horizontal_tab_bar->focused_item_scrolling_text));
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_show_status_icon_oem
 * DESCRIPTION
 *  show status icon on tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_show_status_icon_oem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iw = 0, ih = 0;
    S32 icon_x, icon_y;
    horizontal_tab_bar *tb;
#ifdef __MMI_CALL_INDICATOR__
    S32 iw1 = 0, ih1 = 0;
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
    S32 iw2 = 0, ih2 = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Signal strength*/
    tb = UI_current_horizontal_tab_bar;
    gdi_layer_push_clip();

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE 
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_SIGNAL_STRENGTH, &iw, &ih);
#endif
    icon_x = (S32)tb->x;
    icon_y = (S32)tb->y;
    gdi_layer_set_clip(icon_x, icon_y, icon_x + iw - 1, icon_y + ih - 1);
    gui_draw_filled_area(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1,
            tb->theme->background_filler);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_SIGNAL_STRENGTH, icon_x, icon_y);
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_get_integrated_icon_size (STATUS_ICON_SLAVE_SIGNAL_STRENGTH, &iw2, &ih2);
#endif
    icon_x = icon_x + iw - 1 + STATUS_ICON_X_GAP;
    icon_y = tb->y;
    gdi_layer_set_clip(icon_x, icon_y, icon_x + iw2 - 1, icon_y + ih2 - 1);
    gui_draw_filled_area(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1,
            tb->theme->background_filler);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, icon_x, icon_y);
#endif
#endif

    /*Battery strength*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_BATTERY_STRENGTH, &iw, &ih);
#endif
    icon_x = (S32)tb->x + tb->width - iw;
    icon_y = (S32)tb->y;
    gdi_layer_set_clip(icon_x, icon_y, icon_x + iw - 1, icon_y + ih - 1);
    gui_draw_filled_area(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1,
            tb->theme->background_filler);

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_BATTERY_STRENGTH, icon_x, icon_y);
#endif

#ifdef __MMI_CALL_INDICATOR__
    /* call indicator */
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_get_integrated_icon_size(STATUS_ICON_CALL_INDICATOR, &iw1, &ih1);
#endif
    icon_x = (S32)tb->x + tb->width - iw - iw1 - STATUS_ICON_X_GAP + 1;
    icon_y = (S32)tb->y;
    gdi_layer_set_clip(icon_x, icon_y, icon_x + iw1 - 1, icon_y + ih1 - 1);
    gui_draw_filled_area(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1,
            tb->theme->background_filler);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_show_integrated_icon(STATUS_ICON_CALL_INDICATOR, icon_x, icon_y);
#endif
#endif
    gdi_layer_pop_clip();

    gdi_layer_blt_previous(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1);
 }


#ifdef __MMI_OP11_TAB_BAR__


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_item_OG
 * DESCRIPTION
 *  show tab bar item
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 *  i       [IN]            index of item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_show_item_OG(horizontal_tab_bar *tb, S8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, tab_y_offset;
    BOOL blinking_displayed = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i == tb->focused_item) || (i < tb->first_displayed_item) || (i > tb->last_displayed_item))
    {
        return;
    }

    gui_horizontal_tab_bar_get_item_position(tb, i, &x1, &x2);
    y1 = tb->y;
    y2 = tb->y + tb->tab_height - 1;

    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);

    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

    if ((tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED) && (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING))
    {
        blinking_displayed = TRUE;
    }

    if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING
        && tb->items[i].blink_duration < 0)
    {
        blinking_displayed = TRUE;
    }

    tab_y_offset = y2 - tb->tab_height + 1;

    if (blinking_displayed)
    {
        if (tb->items[i].blink_duration >= 0)
        {
            gui_horizontal_tab_bar_show_item_background(
                x1,
                tab_y_offset,
                x2,
                y2,
                GUI_TAB_BAR_BLINK_BACKGROUND);
        }
        else
        {
            gui_horizontal_tab_bar_show_item_background(
                x1,
                tab_y_offset,
                x2,
                y2,
                GUI_TAB_BAR_NO_RESPONSE_BACKGROUND);
            tb->items[i].flags &= ~UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED;
        }
    }
    else
    {
        if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED)
        {
            gui_horizontal_tab_bar_show_item_background(
                x1,
                tab_y_offset,
                x2,
                y2,
                GUI_TAB_BAR_DISABLED_BACKGROUND);
        }
        else
        {
            gui_horizontal_tab_bar_show_item_background(
                x1,
                tab_y_offset,
                x2,
                y2,
                GUI_TAB_BAR_NORMAL_BACKGROUND);
        }
    }

    if (tb->items[i].icon && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM))
    {
        S32 iw, ih;
        gui_measure_image(tb->items[i].icon, &iw, &ih);
        gdi_image_draw_blend2layers(
            x1 + (abs(tb->tab_width - iw) >> 1),
            tab_y_offset + (abs(tb->tab_height - ih) >> 1),
            tb->items[i].icon);
    }

    if (tb->items[i].text && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_ICON_IN_TAB_ITEM))
    {
        S32 w, h, temp1, temp2;
        gui_set_font(tb->theme->tab_text_font);
        gui_set_text_color(tb->theme->normal_tab_text_color);

        temp1 = tb->tab_text_x;
        temp2 = tb->tab_text_y;

        gui_measure_string((UI_string_type)tb->items[i].text, &w, &h);
        tb->tab_text_y = (tab_y_offset - y1) + ((tb->tab_height - h) >> 1);
        if(tb->tab_text_width > w)
        {
            tb->tab_text_x = (tb->tab_text_width - w) >> 1;
        }

        if (mmi_fe_get_r2l_state())
        {
            gui_print_truncated_text_ex(
                x1 - tb->tab_text_x + tb->tab_width - 1,
                y1 + tb->tab_text_y,
                tb->tab_text_width,
                tb->items[i].text);
        }
        else
        {
            gui_print_truncated_text_ex(
                x1 + tb->tab_text_x,
                y1 + tb->tab_text_y,
                tb->tab_text_width,
                tb->items[i].text);
        }

        tb->tab_text_x = temp1;
        tb->tab_text_y = temp2;
    }

    if ((i == tb->first_displayed_item) && (tb->n_displayable_item < tb->n_items))
    {
        gui_horizontal_tab_bar_show_left_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }

    if ((i == tb->last_displayed_item) && (tb->n_displayable_item < tb->n_items))
    {
        gui_horizontal_tab_bar_show_right_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_focused_item_OG
 * DESCRIPTION
 *  shwo focused item of tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_show_focused_item_OG(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, tab_y_offset;
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = tb->focused_item;

    if (i < tb->first_displayed_item || i > tb->last_displayed_item)
    {
        return;
    }

    gui_horizontal_tab_bar_get_item_position(tb, i, &x1, &x2);
    y1 = tb->y;
    y2 = tb->y + tb->tab_area_height - 1;

    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);
    tab_y_offset = y2 - tb->focused_tab_height + 1;
    gui_horizontal_tab_bar_show_item_background(
        x1,
        tab_y_offset,
        x2,
        y2,
        GUI_TAB_BAR_HIGHLIGHT_BACKGROUND);

    if (tb->items[i].icon && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM))
    {
        S32 iw, ih;
        gui_measure_image(tb->items[i].icon, &iw, &ih);
         gdi_image_draw_blend2layers(
            x1 + (abs(tb->focused_tab_width - iw) >> 1),
            tab_y_offset + (abs(tb->focused_tab_height - ih) >> 1),
            tb->items[i].icon);
    }

    if (tb->items[i].text && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_ICON_IN_TAB_ITEM))
    {
        S32 w, h, temp1, temp2;
        gui_set_font(tb->theme->focused_tab_text_font);
        gui_set_text_color(tb->theme->focused_tab_text_color);

        temp1 = tb->tab_text_x;
        temp2 = tb->tab_text_y;

        gui_measure_string((UI_string_type)tb->items[i].text, &w, &h);
        tb->tab_text_y = (tab_y_offset - y1) + ((tb->focused_tab_height - h) >> 1);
        if(tb->tab_text_width > w)
        {
            tb->tab_text_x = (tb->tab_text_width - w) >> 1;
        }

        if (mmi_fe_get_r2l_state())
        {
            if(tb->style&GUI_TAB_BAR_STYLE_SCOLLING_FOCUSED_ITEM_TEXT)
            {
                gui_create_scrolling_text(
                    &(tb->focused_item_scrolling_text),
                    x1 + tb->tab_text_x,
                    y1 + tb->tab_text_y,
                    tb->tab_text_width -2,
                    h,
                    tb->items[i].text,
                    gui_horizontal_tab_bar_focused_scrolling_text_handler_oem,
                    gui_horizontal_tab_bar_show_scrolling_text_background,
                    tb->theme->focused_tab_text_color,
                    tb->theme->focused_tab_text_color);

                gui_show_scrolling_text(&(tb->focused_item_scrolling_text));
            }
            else
            {
                gui_print_truncated_text_ex(
                    x1 - tb->tab_text_x + tb->tab_width - 1,
                    y1 + tb->tab_text_y,
                    tb->tab_text_width - 2,
                    tb->items[i].text);
            }
        }
        else
        {
            if(tb->style&GUI_TAB_BAR_STYLE_SCOLLING_FOCUSED_ITEM_TEXT)
            {
                gui_create_scrolling_text(
                    &(tb->focused_item_scrolling_text),
                    x1 + tb->tab_text_x,
                    y1 + tb->tab_text_y,
                    tb->tab_text_width - 2,
                    h,
                    tb->items[i].text,
                    gui_horizontal_tab_bar_focused_scrolling_text_handler_oem,
                    gui_horizontal_tab_bar_show_scrolling_text_background,
                    tb->theme->focused_tab_text_color,
                    tb->theme->focused_tab_text_color);

                gui_show_scrolling_text(&(tb->focused_item_scrolling_text));
            }
            else
            {
                gui_print_truncated_text_ex(x1 + tb->tab_text_x, y1 + tb->tab_text_y, tb->tab_text_width, tb->items[i].text);
            }
        }

        tb->tab_text_x = temp1;
        tb->tab_text_y = temp2;
    }

    tab_y_offset = y1 + (tb->focused_tab_height - tb->tab_height);

    if ((i == tb->first_displayed_item) && (tb->n_displayable_item < tb->n_items))
    {
        gui_horizontal_tab_bar_show_left_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }

    if ((i == tb->last_displayed_item) && (tb->n_displayable_item < tb->n_items))
    {
        gui_horizontal_tab_bar_show_right_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }

    tb->items[i].flags = UI_TAB_BAR_ITEM_STATE_NORMAL;
    tb->items[i].blink_duration = -1;
}

/*****************************************************************************
* FUNCTION
*  gui_show_horizontal_tab_bar_OG
* DESCRIPTION
*  Display the horizontal tab bar
* PARAMETERS
*  tb                      [IN/OUT]        The tab bar control
*  disable_tab_area        [IN]            disable tab area or not
*  disable_hint_area       [IN]            disable hint area or not
* RETURNS
*  void
*****************************************************************************/
void gui_show_horizontal_tab_bar_OG(horizontal_tab_bar *tb, BOOL disable_tab_area, BOOL disable_hint_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_horizontal_tab_bar = tb;
    tab_left_no_response_filler.b = (PU8)GetImage(IMG_HORIZONTAL_NO_RESPONSE_LEFT_TAB);
    tab_no_response_filler.b = (PU8)GetImage(IMG_HORIZONTAL_NO_RESPONSE_TAB);
    tab_right_no_response_filler.b = (PU8)GetImage(IMG_HORIZONTAL_NO_RESPONSE_RIGHT_TAB);
    old_lcd_handle = gui_horizontal_tab_bar_setup_target_lcd_and_layer_oem(tb);
    gui_push_and_set_clip(tb->x, tb->y, tb->x + tb->width - 1, tb->y + tb->height - 1);
    if(tb->hide_callback)
    {
        tb->hide_callback(tb->x, tb->y, tb->x + tb->width - 1, tb->y + tb->height - 1);
    }

    if (!disable_tab_area)
    {
        gui_draw_filled_area(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1,
            tb->theme->background_filler);

        for (i = tb->first_displayed_item; i <= tb->last_displayed_item; i++)
        {
            if (i != tb->focused_item)
            {
                gui_horizontal_tab_bar_show_item_OG(tb, i);
            }
        }

        gui_horizontal_tab_bar_show_focused_item_OG(tb);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        gui_horizontal_show_status_icon_oem();
#endif
    }

    gui_pop_clip();
    gui_horizontal_tab_bar_restore_target_lcd_and_layer_oem(tb, old_lcd_handle);
}


#else /* __MMI_OP11_TAB_BAR__ */


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_item_normal
 * DESCRIPTION
 *  show tab bar item
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 *  i       [IN]            index of item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_show_item_normal(horizontal_tab_bar *tb, S8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, tab_y_offset;
    BOOL blinking_displayed = FALSE;
    gui_tab_bar_background_enum background_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i == tb->focused_item) || (i < tb->first_displayed_item) || (i > tb->last_displayed_item))
    {
        return;
    }

    gui_horizontal_tab_bar_get_item_position(tb, i, &x1, &x2);
    y1 = tb->y;
    y2 = tb->y + tb->tab_area_height - 1;

    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    if ((tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED) && (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING))
    {
        blinking_displayed = TRUE;
    }

    tab_y_offset = y2 - tb->tab_height + 1;

    if (blinking_displayed)
    {
        background_type = GUI_TAB_BAR_BLINK_BACKGROUND;
    }
    else
    {
        if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED)
        {
            background_type = GUI_TAB_BAR_DISABLED_BACKGROUND;
        }
        else
        {
            background_type = GUI_TAB_BAR_NORMAL_BACKGROUND;
        }
    }    
    gui_horizontal_tab_bar_show_item_background(
        x1,
        tab_y_offset,
        x2,
        y2,
        background_type);


    if (tb->items[i].icon && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM))
    {
        S32 iw, ih;
        gui_measure_image(tb->items[i].icon, &iw, &ih);

#if defined(__OP01_FWPBW__) && defined(__MMI_MAINLCD_128X64__)
        gdi_image_draw_blend2layers(
            x1 + (abs(tb->tab_width - iw) >> 1) - 1,
            2 > (tab_y_offset + (abs(tb->focused_tab_height - ih) >> 1) - 1) ? 2 : tab_y_offset + (abs(tb->focused_tab_height - ih) >> 1) - 1,
            tb->items[i].icon);
#else		
        gdi_image_draw_blend2layers(
            x1 + (abs(tb->tab_width - iw) >> 1) - 1,
            tab_y_offset + (abs(tb->tab_height - ih) >> 1) - 1,
            tb->items[i].icon);
#endif
    }

    if (tb->items[i].text && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_ICON_IN_TAB_ITEM))
    {
        S32 w, h, temp1, temp2, temp3;
        gui_set_font(tb->theme->tab_text_font);
        gui_set_text_color(tb->theme->normal_tab_text_color);
        gui_set_text_border_color(tb->theme->normal_tab_text_border_color);

        temp1 = tb->tab_text_x;
        temp2 = tb->tab_text_y;
        temp3 = tb->tab_text_width;
        tb->tab_text_width -= 2 * GUI_TAB_TEXT_GAP;
        tb->tab_text_x += GUI_TAB_TEXT_GAP;

        gui_measure_string((UI_string_type)tb->items[i].text, &w, &h);
        /* because the text have border, so add 2 pixel */
        w += 2;
        tb->tab_text_y = (tab_y_offset - y1) + ((tb->tab_height - h) >> 1);
        if(tb->tab_text_width > w)
        {
            tb->tab_text_x += (tb->tab_text_width - w) >> 1;
        }

        if (mmi_fe_get_r2l_state())
        {
            gui_print_truncated_borderd_text(
                x1 - tb->tab_text_x + tb->tab_width - 1,
                y1 + tb->tab_text_y,
                tb->tab_text_width,
                tb->items[i].text);
        }
        else
        {
            gui_print_truncated_borderd_text(
                x1 + tb->tab_text_x,
                y1 + tb->tab_text_y,
                tb->tab_text_width,
                tb->items[i].text);
        }

        tb->tab_text_x = temp1;
        tb->tab_text_y = temp2;
        tb->tab_text_width = temp3;
    }

    if ((i == tb->first_displayed_item) && (tb->n_displayable_item < tb->n_items) && (tb->first_displayed_item != 0))
    {
        gui_horizontal_tab_bar_show_left_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }

    if ((i == tb->last_displayed_item) && (tb->n_displayable_item < tb->n_items) && (tb->last_displayed_item != tb->n_items - 1))
    {
        gui_horizontal_tab_bar_show_right_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_show_focused_item_normal
 * DESCRIPTION
 *  shwo focused item of tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_show_focused_item_normal(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, tab_y_offset;
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = tb->focused_item;

    if (i < tb->first_displayed_item || i > tb->last_displayed_item)
    {
        return;
    }

    gui_horizontal_tab_bar_get_item_position(tb, i, &x1, &x2);
    y1 = tb->y;
    y2 = tb->y + tb->tab_area_height - 1;

    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);
    tab_y_offset = y2 - tb->focused_tab_height + 1;

    gui_horizontal_tab_bar_show_item_background(
       x1,
       tab_y_offset,
       x2,
       y2,
       GUI_TAB_BAR_HIGHLIGHT_BACKGROUND);

#ifdef __MMI_MAINLCD_320X240__ 
if (tb->hint && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_ICON_IN_TAB_ITEM))
    {
        S32 w, h, temp1, temp2, temp3;
        gui_set_font(tb->theme->focused_tab_text_font);
        gui_set_text_color(tb->theme->focused_tab_text_color);
        gui_set_text_border_color(tb->theme->focused_tab_text_border_color);

        temp1 = tb->tab_text_x;
        temp2 = tb->tab_text_y;
        temp3 = tb->tab_text_width;
        tb->tab_text_width -= 2 * GUI_TAB_TEXT_GAP;
        tb->tab_text_x += GUI_TAB_TEXT_GAP;

        gui_measure_string((UI_string_type)tb->hint, &w, &h);
        /* because of have border, so add 2 pixel */
        w += 2;
        tb->tab_text_y = (tab_y_offset - y1) + ((tb->focused_tab_height - h) >> 1);

        if(tb->tab_text_width > w)
        {
            tb->tab_text_x += (tb->tab_text_width - w) >> 1;
        }

        
        gui_create_scrolling_text(
            &(tb->focused_item_scrolling_text),
            x1 + tb->tab_text_x,
            y1 + tb->tab_text_y,
            tb->tab_text_width - 2,
            h,
            tb->hint,
            gui_horizontal_tab_bar_focused_scrolling_text_handler_oem,
            gui_horizontal_tab_bar_show_scrolling_text_background,
            tb->theme->focused_tab_text_color,
            tb->theme->focused_tab_text_border_color);
        
        tb->focused_item_scrolling_text.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
        
        gui_show_scrolling_text(&(tb->focused_item_scrolling_text));


        tb->tab_text_x = temp1;
        tb->tab_text_y = temp2;
        tb->tab_text_width = temp3;
    }
#else
    if (tb->items[i].icon && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM))
    {
        S32 iw, ih;
        gui_measure_image(tb->items[i].icon, &iw, &ih);

#if defined(__OP01_FWPBW__) && defined(__MMI_MAINLCD_128X64__)
        gdi_image_draw_blend2layers(
            x1 + (abs(tb->focused_tab_width - iw) >> 1) - 1,
            2 > (tab_y_offset + (abs(tb->focused_tab_height - ih) >> 1) - 1) ? 2 : tab_y_offset + (abs(tb->focused_tab_height - ih) >> 1) - 1,
            tb->items[i].icon);
#else		
        gdi_image_draw_blend2layers(
            x1 + (abs(tb->focused_tab_width - iw) >> 1) - 1,
            tab_y_offset + (abs(tb->focused_tab_height - ih) >> 1) - 1,
            tb->items[i].icon);
#endif
    }

    if (tb->items[i].text && !(tb->style&GUI_TAB_BAR_STYLE_SHOW_ONLY_ICON_IN_TAB_ITEM))
    {
        S32 w, h, temp1, temp2, temp3;
        gui_set_font(tb->theme->focused_tab_text_font);
        gui_set_text_color(tb->theme->focused_tab_text_color);
        gui_set_text_border_color(tb->theme->focused_tab_text_border_color);

        temp1 = tb->tab_text_x;
        temp2 = tb->tab_text_y;
        temp3 = tb->tab_text_width;
        tb->tab_text_width -= 2 * GUI_TAB_TEXT_GAP;
        tb->tab_text_x += GUI_TAB_TEXT_GAP;

        gui_measure_string((UI_string_type)tb->items[i].text, &w, &h);
        /* because of have border, so add 2 pixel */
        w += 2;
        tb->tab_text_y = (tab_y_offset - y1) + ((tb->focused_tab_height - h) >> 1);

        if(tb->tab_text_width > w)
        {
            tb->tab_text_x += (tb->tab_text_width - w) >> 1;
        }

            if(tb->style&GUI_TAB_BAR_STYLE_SCOLLING_FOCUSED_ITEM_TEXT)
            {
                gui_create_scrolling_text(
                    &(tb->focused_item_scrolling_text),
                    x1 + tb->tab_text_x,
                    y1 + tb->tab_text_y,
                    tb->tab_text_width -2,
                    h,
                    tb->items[i].text,
                    gui_horizontal_tab_bar_focused_scrolling_text_handler_oem,
                    gui_horizontal_tab_bar_show_scrolling_text_background,
                    tb->theme->focused_tab_text_color,
                    tb->theme->focused_tab_text_border_color);
                
                tb->focused_item_scrolling_text.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

                gui_show_scrolling_text(&(tb->focused_item_scrolling_text));
            }
            else
        {
            if (mmi_fe_get_r2l_state())
            {
                gui_print_truncated_borderd_text(
                    x1 - tb->tab_text_x + tb->tab_width - 1,
                    y1 + tb->tab_text_y,
                    tb->tab_text_width,
                    tb->items[i].text);
            }
            else
            {
                gui_print_truncated_borderd_text(x1 + tb->tab_text_x, y1 + tb->tab_text_y, tb->tab_text_width, tb->items[i].text);
            }
        }

        tb->tab_text_x = temp1;
        tb->tab_text_y = temp2;
        tb->tab_text_width = temp3;
    }
#endif

    tab_y_offset = y1 + (tb->focused_tab_height - tb->tab_height);
    if ((i == tb->first_displayed_item) && (tb->n_displayable_item < tb->n_items) && (tb->first_displayed_item != 0))
    {
        gui_horizontal_tab_bar_show_left_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }

    if ((i == tb->last_displayed_item) && (tb->n_displayable_item < tb->n_items) && (tb->last_displayed_item != tb->n_items - 1))
    {
        gui_horizontal_tab_bar_show_right_arrow(tb, tab_y_offset, tb->x, tb->x + tb->width - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_horizontal_tab_bar_normal
 * DESCRIPTION
 *  Display the horizontal tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 *  disable_tab_area        [IN]            disable tab area or not
 *  disable_hint_area       [IN]            disable hint area or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_tab_bar_normal(horizontal_tab_bar *tb, BOOL disable_tab_area, BOOL disable_hint_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_horizontal_tab_bar = tb;
    old_lcd_handle = gui_horizontal_tab_bar_setup_target_lcd_and_layer_oem(tb);
    gui_push_and_set_clip(tb->x, tb->y, tb->x + tb->width - 1, tb->y + tb->height - 1);
    if(tb->hide_callback)
    {
        tb->hide_callback(tb->x, tb->y, tb->x + tb->width - 1, tb->y + tb->height - 1);
    }

    if (!disable_tab_area)
    {
        gui_draw_filled_area(
            tb->x,
            tb->y,
            tb->x + tb->width - 1,
            tb->y + tb->tab_area_height - 1,
            tb->theme->background_filler);
        
        #if defined(__OP01_FWPBW__) && defined(__MMI_MAINLCD_128X64__)
        gdi_draw_line(tb->x, tb->y + tb->height - 1, tb->x + tb->width - 1, tb->y + tb->height - 1, GDI_COLOR_BLACK);
        #endif

        for (i = tb->first_displayed_item; i <= tb->last_displayed_item; i++)
        {
            if (i != tb->focused_item)
            {
                gui_horizontal_tab_bar_show_item_normal(tb, i);
            }
        }

        gui_horizontal_tab_bar_show_focused_item_normal(tb);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        gui_horizontal_show_status_icon_oem();
#endif
    }


    gui_pop_clip();
    gui_horizontal_tab_bar_restore_target_lcd_and_layer_oem(tb, old_lcd_handle);
}

#endif /* __MMI_OP11_TAB_BAR__ */


