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
 *  gui_menu_oem.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GUI Menu OEM Layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gdi_include.h"
#include "wgui_draw_manager.h"
#include "gui_effect_oem.h"
#include "wgui_fixed_menus.h"
#include "gui_asyncdynamic_menus.h"
#include "wgui_categories_util.h"
#include "gui_menu_post_oem.h"
#include "CustThemesRes.h"
#include "gui.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_typedef.h"
#include "MMI_features.h"
#include "gui_switch.h"
#include "wgui.h"
#include "kal_general_types.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "gui_fixed_menus.h"
#include "wgui_inputs.h"
#include "gui_config.h"
#include "gui_scrollbars.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_themes.h"
#include "gui_fixed_menuitems.h"
#include "gui_resource_type.h"
#include "wgui_categories_enum.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
static UI_filled_area slide_highlight_effect_transparent_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_IMAGE_ID_NULL,
    NULL,
    {0,0,255,100},  /* transparent color */
    {0,0,0,100},
    {0,0,0,100},
    {0,0,0,100},
    0
};

static UI_filled_area *old_menu_item_focussed_filler = NULL;
static UI_filled_area *old_menu_item_focussed_without_sc_filler = NULL;
static U8 g_list_effect_slide_disable = 1;
static S32 g_old_list_highlight_x, g_old_list_highlight_y;

gdi_handle anim_handle = GDI_NULL_HANDLE;

/* static function prototypes */
static void gui_list_effect_slide_draw_highlight_filler(S32 x, S32 y, S32 width, S32 height);
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
extern gui_effect_struct    *g_slide_effect;
extern gdi_handle  g_gui_effect_layer;
extern gui_menu_type_enum g_gui_list_menu_slide_menu_type;

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
extern S32 gblock_list_effect;
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
extern S32 gblock_list_animation_highlight;


/*****************************************************************************
 * FUNCTION
 *  gui_animation_before_background
 * DESCRIPTION
 *  Animation with background draw before callback.
 * PARAMETERS
 *  result       [IN]   GDI image result code
 * RETURNS
 *  void
 *****************************************************************************/  
static void gui_animation_before_background(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(0, 0, UI_device_width,2 * MMI_MENUITEM_HEIGHT,GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  gui_animation_after_background
 * DESCRIPTION
 *  Animation with background draw before callback.
 * PARAMETERS
 *  result       [IN]   GDI image result code
 * RETURNS
 *  void
 *****************************************************************************/    
static void gui_animation_after_background(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    S32 i, j;
    gdi_handle h[4];
    S32 iwidth, iheight, height, y_min, y_max;
#ifdef __MMI_UI_LIST_GRID_LINE__
    MMI_BOOL show_scrollbar;
#endif
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (MMI_current_menu_type == LIST_MENU)
    {
        gdi_layer_get_blt_layer(&h[0], &h[1], &h[2], &h[3]);
    if (g_slide_effect->start_y > g_slide_effect->end_y)
    {
        y_min = g_slide_effect->end_y;
        y_max = g_slide_effect->start_y;
    }
    else
    {
        y_max = g_slide_effect->end_y;
        y_min = g_slide_effect->start_y;
    }
        for (i = 0; i < 3; i++)
        {
        if (h[i] == g_gui_effect_layer && h[i+1] > GDI_NULL_HANDLE)
            {
                g_slide_effect->in_flatten = 1;
                gdi_layer_push_and_set_active(h[i+1]);
                gui_push_clip();
                gui_set_clip(g_slide_effect->start_x, 
                    y_min, 
                    g_slide_effect->start_x + g_slide_effect->width - 1, 
                    y_max + g_slide_effect->height - 1);

            if (g_gui_list_hide_menu)
            {
                g_gui_list_hide_menu(
                    g_slide_effect->start_x, 
                    y_min, 
                    g_slide_effect->start_x + g_slide_effect->width - 1, 
                    y_max + g_slide_effect->height - 1);
            }
            else if (!(MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER) && 
                (wgui_is_wallpaper_on_bottom() == MMI_TRUE))
            {
                gui_push_clip();
                gui_set_clip(
                    g_slide_effect->start_x, 
                    y_min, 
                    g_slide_effect->start_x + g_slide_effect->width - 1, 
                    y_max + g_slide_effect->height - 1);
                gdi_draw_solid_rect(
                    g_slide_effect->start_x, 
                    y_min, 
                    g_slide_effect->start_x + g_slide_effect->width - 1, 
                    y_max + g_slide_effect->height - 1, 
                    GDI_COLOR_TRANSPARENT);
#ifdef __MMI_UI_LIST_GRID_LINE__
             /* Check presence of scrollbar */
             show_scrollbar = MMI_FALSE;
             if (!(MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR))
             {
                 if (MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
                 {
                     /* FIXME. we need to compute m->displayed_items twice */
                     //gui_show_asyncdynamic_list_menu_no_draw(m);                
                     if (MMI_fixed_list_menu.first_displayed_item > 0)
                     {
                         show_scrollbar = MMI_TRUE;
                     }
                     else
                     {
                         if (MMI_fixed_list_menu.displayed_items < MMI_fixed_list_menu.n_items)
                         {
                             show_scrollbar = MMI_TRUE;
                         }
                     }
                 }
                 else
                 {
                     show_scrollbar = MMI_TRUE;
                 }
             }
            if (MMI_fixed_list_menu.n_items > 0)
            {
                S32 line_height, display_index, index, highlight_height, grid_x;
                gdi_handle alpha_layer;

                iheight = 0;
                MMI_fixed_list_menu.current_displayed_item = -1; 
                index = MMI_fixed_list_menu.current_displayed_item;
                display_index = MMI_fixed_list_menu.first_displayed_item;
                
                if (r2lMMIFlag)
                {
                    grid_x = MMI_fixed_list_menu.x + GUI_MENUITEM_X2_GAP;
                    if (show_scrollbar)
                    {
                        grid_x = grid_x + MMI_fixed_list_menu.vbar.width;
                    }
                    else
                    {
                        grid_x += GUI_LIST_MENU_X2_GAP;
                    }
                }
                else
                {
                    grid_x = MMI_fixed_list_menu.x + GUI_MENUITEM_X1_GAP;    
                }
                if (g_gui_list_menu_slide_menu_type == GUI_MENU_TYPE_FIXED)
                {
                    MMI_fixed_list_menu.item_measure_function(
                        MMI_fixed_list_menu.items[MMI_fixed_list_menu.highlighted_item], 
                        MMI_fixed_list_menu.common_item_data,&iwidth, &highlight_height);
                    if (MMI_fixed_list_menu.highlighted_item >= 1 || MMI_fixed_list_menu.n_items == 1)
                    {
                        MMI_fixed_list_menu.current_displayed_item = 0;                
                        MMI_fixed_list_menu.item_measure_function(MMI_fixed_list_menu.items[0], 
                            MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
                    }
                    else if (MMI_fixed_list_menu.n_items != 0)
                    {
                        MMI_fixed_list_menu.current_displayed_item = 1;                
                        MMI_fixed_list_menu.item_measure_function(MMI_fixed_list_menu.items[1], 
                            MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
                    }
                }
                else if (g_gui_list_menu_slide_menu_type == GUI_MENU_TYPE_DYNAMIC)
                {
                    MMI_fixed_list_menu.item_measure_function(
                        get_dynamic_item_from_buffer(MMI_fixed_list_menu.highlighted_item), 
                        MMI_fixed_list_menu.common_item_data,&iwidth, &highlight_height);
                    if (MMI_fixed_list_menu.highlighted_item >= 1 || MMI_fixed_list_menu.n_items == 1)
                    {
                         MMI_fixed_list_menu.current_displayed_item = 0;                
                        MMI_fixed_list_menu.item_measure_function(get_dynamic_item_from_buffer(0), 
                            MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
                    }
                    else if (MMI_fixed_list_menu.n_items != 0)
                    {
                        MMI_fixed_list_menu.current_displayed_item = 1;                
                        MMI_fixed_list_menu.item_measure_function(get_dynamic_item_from_buffer(1), 
                            MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
                    }
                }
                else if (g_gui_list_menu_slide_menu_type == GUI_MENU_TYPE_ASYNCDYNAMIC)
                {
                    MMI_fixed_list_menu.item_measure_function(
                        get_asyncdynamic_item_from_buffer(MMI_fixed_list_menu.highlighted_item), 
                        MMI_fixed_list_menu.common_item_data,&iwidth, &highlight_height);
                    if ((MMI_fixed_list_menu.highlighted_item >= MMI_fixed_list_menu.first_displayed_item + 1) || (MMI_fixed_list_menu.n_items == 1))
                    {
                         MMI_fixed_list_menu.current_displayed_item = MMI_fixed_list_menu.first_displayed_item;                
                        MMI_fixed_list_menu.item_measure_function(get_asyncdynamic_item_from_buffer(MMI_fixed_list_menu.first_displayed_item), 
                            MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
                    }
                    else if (MMI_fixed_list_menu.n_items != 0)
                    {
                        MMI_fixed_list_menu.current_displayed_item = MMI_fixed_list_menu.first_displayed_item + 1;                
                        MMI_fixed_list_menu.item_measure_function(get_asyncdynamic_item_from_buffer(MMI_fixed_list_menu.first_displayed_item + 1),
                            MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
                    }
                }
                
                if (iheight)
                {
                    if (display_index == MMI_fixed_list_menu.highlighted_item)
                    {
                        line_height = MMI_fixed_list_menu.y + highlight_height;
                    }
                    else
                    {
                        line_height = MMI_fixed_list_menu.y + iheight;
                    }
                    while (line_height < MMI_fixed_list_menu.y + MMI_fixed_list_menu.height -1)
                    {
                        alpha_layer = dm_get_scr_bg_layer();                        
                        if (MMI_fixed_list_menu.alpha_blend_layer_handle)
                        {
                            alpha_layer = dm_get_scr_bg_layer(); 
                        }
                        else 
                        {
                            alpha_layer = dm_get_scr_bg_layer();   
                            if (alpha_layer == GDI_ERROR_HANDLE)
                            {
                                gdi_layer_get_active(&alpha_layer);
                            }
                        }
                        if (display_index != MMI_fixed_list_menu.highlighted_item - 1)
                        {
                            gdi_effect_alpha_blending_rect(
                                alpha_layer, 
                                grid_x, 
                                line_height, 
                                grid_x + iwidth - 1, 
                                line_height, 
                                current_MMI_theme->list_grid_line_alpha * 255 / 100,
                                current_MMI_theme->list_grid_line_color->r,
                                current_MMI_theme->list_grid_line_color->g,
                                current_MMI_theme->list_grid_line_color->b);
                        }
                        display_index ++;                       
                        if (display_index == MMI_fixed_list_menu.highlighted_item)
                        {   
                            line_height += highlight_height;                        
                        }
                        else
                        {
                            line_height += iheight;                        
                        }
                    }
                }
                MMI_fixed_list_menu.current_displayed_item = index;                         
                
            }
#endif
                gui_pop_clip();
            }
            gdi_layer_flatten_with_clipping(h[0], h[1], h[2], h[3]);
            gui_pop_clip();
            height = MMI_fixed_list_menu.y;
            MMI_fixed_list_menu.current_displayed_item = -1;
            for (j = MMI_fixed_list_menu.first_displayed_item; j <= MMI_fixed_list_menu.last_displayed_item; j++)
            {          
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__                
                set_is_draw_next_frame_list_highlight_effect_value(MMI_TRUE);
#endif
                MMI_fixed_list_menu.current_displayed_item = j;
                MMI_fixed_list_menu.current_displayed_item = j;
                if (g_gui_list_menu_slide_menu_type == GUI_MENU_TYPE_FIXED)
                {
                    MMI_fixed_list_menu.item_measure_function(
                        MMI_fixed_list_menu.items[j], 
                        MMI_fixed_list_menu.common_item_data, 
                        &iwidth, 
                        &iheight);
                    height += iheight;
                    if (height > y_min)
                    {
                        MMI_fixed_list_menu.item_display_function(
                            MMI_fixed_list_menu.items[j], 
                            MMI_fixed_list_menu.common_item_data, 
                            g_slide_effect->start_x, 
                            height - iheight);
                    }
                }
                else if (g_gui_list_menu_slide_menu_type == GUI_MENU_TYPE_DYNAMIC)
                {
                    MMI_fixed_list_menu.item_measure_function(
                        get_dynamic_item_from_buffer(j), 
                        MMI_fixed_list_menu.common_item_data,
                        &iwidth, 
                        &iheight);
                    height += iheight;
                    if (height > y_min)
                    {
                        MMI_fixed_list_menu.item_display_function(
                            get_dynamic_item_from_buffer(j), 
                            MMI_fixed_list_menu.common_item_data, 
                            g_slide_effect->start_x, 
                            height - iheight);
                    }
                }
                else if (g_gui_list_menu_slide_menu_type == GUI_MENU_TYPE_ASYNCDYNAMIC)
                {

                    gui_push_clip();
                    gui_set_clip(g_slide_effect->start_x, 
                        y_min, 
                        g_slide_effect->start_x + g_slide_effect->width - 1, 
                        y_max + g_slide_effect->height - 1);
                    MMI_fixed_list_menu.item_measure_function(
                        get_asyncdynamic_item_from_buffer(j), 
                        MMI_fixed_list_menu.common_item_data, 
                        &iwidth, 
                        &iheight);
                    height += iheight;
                    if (height > y_min)
                    {
                        MMI_fixed_list_menu.item_display_function(
                            get_asyncdynamic_item_from_buffer(j), 
                            MMI_fixed_list_menu.common_item_data, 
                            g_slide_effect->start_x, 
                            height - iheight);
                    }
                    gui_pop_clip();
                }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
                set_is_draw_next_frame_list_highlight_effect_value(MMI_FALSE);
#endif
                if (height >= y_max + g_slide_effect->height - 1)
                    break;
                }
                MMI_fixed_list_menu.current_displayed_item = -1;
                gdi_layer_pop_and_restore_active();
                g_slide_effect->in_flatten = 0;
                break;
            }
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_draw_highlight_filler
 * DESCRIPTION
 *  Show list effet highlight during slidig.
 * PARAMETERS
 *  x       [IN]    x
 *  y       [IN]    y
 *  w       [IN]    width
 *  h       [IN]    height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_list_effect_slide_draw_highlight_filler(S32 x, S32 y, S32 width, S32 height)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_common_menuitem_base_struct *m;
    UI_filled_area *f;
    S32 count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(0, 0, width - 1, height - 1);
    if ((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
        ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && 
        (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
    {
        f = m->focussed_without_sc_filler;
    }
    else
    {
        f =  m->focussed_filler;
    }         
        
        
    if (g_slide_effect->current_frame_index == g_slide_effect->frame_count)
    {   
        if (f && f->flags & UI_FILLED_AREA_TYPE_BITMAP && f->b &&
            (f->b[0] == GDI_IMAGE_TYPE_PNG_SEQUENCE || f->b[0] == GDI_IMAGE_TYPE_ABM_SEQUENCE || 
             f->b[0] == IMAGE_TYPE_AB2_SEQUENCE || 
             f->b[0] == GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET ||
             f->b[0] == GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET || 
             f->b[0] == GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET))
        {
            gdi_image_cache_reset();
            if (anim_handle)
            {
                gdi_anim_stop(anim_handle);
                anim_handle = GDI_NULL_HANDLE;
            }
            gdi_image_get_frame_count(f->b, &count);
            if (gblock_list_effect || gblock_list_animation_highlight)
            {   
                if (count >= 1)
                {
                    gdi_image_draw_frames(0, 0, f->b, count - 1);
                }
                else
                {
                    gui_draw_filled_area(0, 0, width - 1, height - 1, f);
                }
            }
            else
            {
                gdi_anim_set_draw_before_callback(gui_animation_before_background);
                gdi_anim_set_draw_after_callback(gui_animation_after_background);
                if (gdi_anim_get_count(f->b) == 1)
                {
                    gdi_anim_draw_once(0, 0, f->b, &anim_handle);
                }
                else                
                {
                    gdi_anim_draw(0, 0, f->b, &anim_handle);
                }
            }
        }
        else
            gui_draw_filled_area(0, 0, width - 1, height - 1, f);
    }
    else
    {
        if (gblock_list_animation_highlight && m->focussed_filler->flags & UI_FILLED_AREA_TYPE_BITMAP 
            && m->focussed_filler->b)
        {
            gdi_image_get_frame_count(m->focussed_filler->b, &count);
            if (count >=1)
                gdi_image_draw_frames(0, 0, f->b, count - 1);
            else
                gui_draw_filled_area(0, 0, width - 1, height - 1, f);
        }
        else 
        {
            gui_draw_filled_area(0, 0, width - 1, height - 1, f);
        }
    }
    
    gdi_layer_pop_clip();
}

#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#ifdef __MMI_UI_LIST_SLIDE_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_start
 * DESCRIPTION
 *  List highlight slide effect start call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_effect_slide_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_common_menuitem_base_struct *m;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;

    g_list_effect_slide_disable = 0;        

    if ((gui_get_current_list_effect() != MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE) || 
        (MMI_current_menu_type != LIST_MENU) ||
        (m->flags & UI_MENUITEM_DISABLE_HIGHLIGHT) ||
        (m->ext_flags & UI_MENUITEM_EXT_INEQUAL_HEIGHT) ||
        gui_list_effect_slide_is_highlight_item_two_line() || 
        (m->focussed_filler->b == NULL) 
#ifdef __MMI_SMALL_LIST_SCREEN__
        || 
        (g_dm_data.s32CatId == MMI_CATEGORY10_ID)
#endif
        )
    {
        g_list_effect_slide_disable = 1;

        return;
    }

    g_old_list_highlight_x = MMI_fixed_list_menu.highlight_x;
    g_old_list_highlight_y = MMI_fixed_list_menu.highlight_y;

    gui_effect_slide_create(
        g_old_list_highlight_x, 
        g_old_list_highlight_y,
        g_old_list_highlight_x,
        g_old_list_highlight_y,
        m->width,
        m->height,
        GUI_EFFECT_LIST_SLIDE_DURATION,
        gui_list_effect_slide_draw_highlight_filler,
        NULL,
        GUI_EFFECT_FRAME_FIRST);

    gui_effect_slide_close();
            
    old_menu_item_focussed_filler = m->focussed_filler;
    old_menu_item_focussed_without_sc_filler = m->focussed_without_sc_filler;
    m->selected_filler = &slide_highlight_effect_transparent_filler;
    m->focussed_filler = &slide_highlight_effect_transparent_filler;
    m->focussed_without_sc_filler = &slide_highlight_effect_transparent_filler;

    gui_effect_set_blt_layer();

    gdi_layer_lock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_end
 * DESCRIPTION
 *  List highlight slide effect end call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_effect_slide_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_common_menuitem_base_struct *m;
    S32 start_frame;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_list_effect_slide_disable)
    {
        return;
    }

    m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;
    
    // gui_effect_restore_blt_layer();
 
    /* Do nothing if the highlight filler is changed. for example...theme change. */
    if (m->focussed_filler != &slide_highlight_effect_transparent_filler)
    {
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, 0, 0);

        return;
    }

    if (gui_list_effect_slide_is_highlight_item_two_line())
    {
        /* 
         * Do not restore the focussed filler since the filler has been changed to two line.
         * Currently, no sliding is allowed from any items to two-line items.
         */
        start_frame = GUI_EFFECT_FRAME_LAST;
    }
    else
    {   
        m->selected_filler = old_menu_item_focussed_filler;
        m->focussed_without_sc_filler = old_menu_item_focussed_without_sc_filler;
        m->focussed_filler = old_menu_item_focussed_filler;           
        start_frame = GUI_EFFECT_FRAME_FIRST;
    }
    if (gui_asyncdynamic_list_error && g_gui_list_menu_slide_menu_type ==GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, 0, 0);
        
        return;
    }

    gui_effect_slide_create(
        g_old_list_highlight_x, 
        g_old_list_highlight_y,
        MMI_fixed_list_menu.highlight_x,
        MMI_fixed_list_menu.highlight_y,
        m->width,
        m->height,
        GUI_EFFECT_LIST_SLIDE_DURATION,
        gui_list_effect_slide_draw_highlight_filler,
        NULL,
        start_frame);

    m->selected_filler = old_menu_item_focussed_filler;
    m->focussed_filler = old_menu_item_focussed_filler;
    m->focussed_without_sc_filler = old_menu_item_focussed_without_sc_filler;
    g_list_effect_slide_disable = 1;
    
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_stop
 * DESCRIPTION
 *  List highlight slide effect stop call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_effect_slide_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_slide_close();
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_is_enable
 * DESCRIPTION
 *  Check if the slide effect is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  0: disable. 1: enable.
 *****************************************************************************/
S32 gui_list_effect_slide_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)(!g_list_effect_slide_disable);
}

#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */



