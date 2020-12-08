/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  gui_menu_shortcuts.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  shortcuts related funtions
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_themes.h"
#include "gui_menu_shortcut.h"
#include "wgui_categories_util.h"
#include "Wgui_title.h"
#include "gui_font_size.h"

#include "MMIDataType.h"
#include "gui_theme_struct.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gui.h"
#include "gdi_const.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "wgui.h"
#include "gui_switch.h"
#include "gui_config.h"
#include "PixcomFontEngine.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define GUI_SHORTCUT_DEFLEN             3       /* default wdith of shortcut */

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*****************************************************************************              
 * Variable                                                                    
 *****************************************************************************/


UI_shortcut_box_theme *current_shortcut_box_theme = NULL;
MMI_BOOL goto_callback = MMI_TRUE;


/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
static void gui_shortcut_dummy_hide_menu(S32 x, S32 y, S32 w, S32 h);
static void gui_shortcut_dummy_timer_callback(void);
static void gui_shortcut_enable_input_flag(void);

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_setup_target_lcd_and_layer
 * DESCRIPTION
 *  set the component target lcd, target layer and alpha_blend_layer
 * PARAMETERS
 *  sc       [IN]        the struct of menu shortcut
 * RETURNS
 *  the old lcd handle
 *****************************************************************************/
static gdi_handle gui_shortcut_setup_target_lcd_and_layer(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&old_lcd_handle);
    if(sc->target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();  /* switch to sub lcd graphic context */
    }
    else if(sc->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context(); /* switch to sub lcd graphic context */
    }
    if(sc->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(sc->target_layer);
    }
    if(sc->alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_push_and_set_alpha_blending_source_layer(sc->alpha_blend_layer);
    }
    return old_lcd_handle;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_restore_target_lcd_and_layer
 * DESCRIPTION
 *  set the component target lcd, target layer and alpha_blend_layer
 * PARAMETERS
 *  sc              [IN]        the struct of menu shortcut
 *  old_lcd_handle  [IN]    the old lcd handle
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_shortcut_restore_target_lcd_and_layer(gui_shortcut_struct *sc, gdi_handle old_lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(sc->alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    if(sc->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    if(sc->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
    if(sc->target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_dummy_hide_menu
 * DESCRIPTION
 *  Dummy function used in shortcut
 * PARAMETERS
 *  x       [IN]        Is the left-top conner position
 *  y       [IN]        Is the left-top conner position
 *  w       [IN]        Is the right-bottom conner position
 *  h       [IN]        Is the right-bottom conner position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_shortcut_dummy_hide_menu(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x);
    UI_UNUSED_PARAMETER(y);
    UI_UNUSED_PARAMETER(w);
    UI_UNUSED_PARAMETER(h);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_dummy_timer_callback
 * DESCRIPTION
 *  Dummy function used in shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_shortcut_dummy_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_handler_keyinput
 * DESCRIPTION
 *  This function is called when a menu shortcut key is pressed
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  c       [IN]            The character that is input
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_handler_keyinput(gui_shortcut_struct *sc, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, nstr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sc->number < 0)
    {
        return;
    }

    if (mmi_ucs2strlen((const CHAR*)sc->input_buffer) >= sc->input_length)
    {
        goto_callback = MMI_FALSE;
        gui_start_timer(MMI_MENU_SHORTCUT_TIMEOUT, gui_shortcut_enable_input_flag);
        sc->timer_callback();
    }
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    else if (sc->display == 0 && c == '0' && sc->input_buffer[0] == 0)
#else  
    else if (c == '0' && sc->input_buffer[0] == 0)
#endif
	{
        return;
    }
    else if (goto_callback)
    {

        if (sc->display == MMI_FALSE)
        {
            sc->display = MMI_TRUE;
            sc->input_buffer[0] = 0;
        }

        nstr = mmi_ucs2strlen((const CHAR*)sc->input_buffer);
        sc->input_buffer[nstr] = c;
        sc->input_buffer[nstr + 1] = 0;
        i = gui_atoi((UI_string_type) sc->input_buffer);
        sc->number = i - 1;
        gui_start_timer(MMI_MENU_SHORTCUT_TIMEOUT, sc->timer_callback);

        if (!sc->display_disabled)
        {
            if (!mmi_fe_get_r2l_state())
            {
                sc->x -= GUI_SHORTCUT_INSERT_GAP;
            }
            else
            {
                sc->x += GUI_SHORTCUT_INSERT_GAP;
            }
            gdi_layer_lock_frame_buffer();
            gui_shortcut_show(sc);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(sc->x, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
            if (!mmi_fe_get_r2l_state())
            {
                sc->x += GUI_SHORTCUT_INSERT_GAP;
            }
            else
            {
                sc->x -= GUI_SHORTCUT_INSERT_GAP;
            }

        }
    }
    else
    {
        gui_start_timer(MMI_MENU_SHORTCUT_TIMEOUT, gui_shortcut_enable_input_flag);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_create_ex
 * DESCRIPTION
 *  Creates the menu shortcut
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  x       [IN]            Is the left-top corner position
 *  y       [IN]            Is the left-top corner position
 *  w       [IN]            Is the width of shortcut
 *  h       [IN]            Is the height of shortcut
 *  target_lcd          [IN]            Is the target_lcd of shortcut
 *  target_layer        [IN]            Is the target_layer of shortcut
 *  alpha_blend_layer   [IN]            Is the alpha_blend_layer of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_create_ex(
    gui_shortcut_struct *sc, 
    S32 x, 
    S32 y, 
    S32 w, 
    S32 h,
    gdi_handle target_lcd, 
    gdi_handle target_layer,
    gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_fe_get_r2l_state())
    {
        sc->x = x + w - GUI_SHORTCUT_WIDTH;
    }
    else
    {
        sc->x = x;
    }
    sc->y = y;
    sc->width = GUI_SHORTCUT_WIDTH;
    sc->height = h;
    sc->input_length = GUI_SHORTCUT_DEFLEN;
    gui_shortcut_set_current_theme(sc);

    sc->display = MMI_FALSE;
    sc->display_disabled = MMI_TRUE;
    sc->max_number = -1;
    sc->input_number = -1;
    sc->number = -1;
    sc->target_lcd = target_lcd;
    sc->target_layer = target_layer;
    sc->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_create
 * DESCRIPTION
 *  Creates the menu shortcut
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  x       [IN]            Is the left-top corner position
 *  y       [IN]            Is the left-top corner position
 *  w       [IN]            Is the width of shortcut
 *  h       [IN]            Is the height of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_create(gui_shortcut_struct *sc, S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_create_ex(sc, x, y, w, h, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_register_callback
 * DESCRIPTION
 *  Registers the function to be called when a shortcut
 *  is being entered.
 * PARAMETERS
 *  sc                  [IN/OUT]        Is the struct of shortcut
 *  timer_callback      [IN]            Callback function of timer out
 *  hide_funcptr        [IN]            Callback funtion of hide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_register_callback(
        gui_shortcut_struct *sc,
        void (*timer_callback) (void),
        void (*hide_funcptr) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timer_callback)
    {
        sc->timer_callback = timer_callback;
    }
    if (hide_funcptr)
    {
        sc->hide_callback = hide_funcptr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_move
 * DESCRIPTION
 *  Moves the menu shortcut indicator to a new position
 * PARAMETERS
 *  sc      [IN/OUT]        Struct of shortcut
 *  x       [IN]            Is the new left-top corner position
 *  y       [IN]            Is the new left-top corner position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_move(gui_shortcut_struct *sc, S32 x, S32 y)
{
    sc->x = x;
    sc->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_auto_resize
 * DESCRIPTION
 *  Auto resizes the menu shortcut indicator
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  h       [IN]            Is the height of shortcut
 * RETURNS
 *  width of shortcut
 *****************************************************************************/
S32 gui_shortcut_auto_resize(gui_shortcut_struct *sc, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR s[GUI_SHORTCUT_MAX_SIZE];
    S32 l, w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(8, (UI_string_type) s, 10);
    gui_set_font(sc->normal_font);
    gui_measure_string((UI_string_type) s, &w, &l);
    w = w * sc->input_length + GUI_SHORTCUT_GAP;
    sc->width = w;
    sc->height = h;
    return w;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_show
 * DESCRIPTION
 *  show the menu shortcut
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_show(gui_shortcut_struct *sc)
{
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height;
    UI_character_type s[GUI_SHORTCUT_MAX_SIZE];
    stFontAttribute *font = sc->normal_font;
    S32 l;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* __MMI_WALLPAPER_ON_BOTTOM__ does not show shortcut in title */


    old_lcd_handle = gui_shortcut_setup_target_lcd_and_layer(sc);

    if (!sc->display_disabled && sc->number >= 0 && sc->max_number > 0)
    {
        gdi_layer_push_clip();
        gui_itoa(sc->number + 1, (UI_string_type) s, 10);
        gui_set_font(font);
        if (!mmi_fe_get_r2l_state())
        {
            gdi_layer_set_clip(sc->x - GUI_SHORTCUT_INSERT_GAP, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
            if(sc->hide_callback)
            {
                sc->hide_callback(sc->x - GUI_SHORTCUT_INSERT_GAP, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
            }
        }
        else
        {
            gdi_layer_set_clip(sc->x + GUI_SHORTCUT_INSERT_GAP, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
            if(sc->hide_callback)
            {
                sc->hide_callback(sc->x + GUI_SHORTCUT_INSERT_GAP, sc->y, sc->x + sc->width - 1, sc->y + sc->height - 1);
            }
        }
        gui_set_text_color(sc->normal_text_color);
        if (sc->use_border)
        {
            gui_set_text_border_color(sc->normal_text_border_color);
        }
        /* For Animated effect */
        if (sc->input_buffer[0] == 0)
        {
            gui_measure_string((UI_string_type) s, &l, &character_height);
        }
        else
        {
            gui_measure_string((UI_string_type) sc->input_buffer, &l, &character_height);
        }

        if (!mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(
                sc->x + sc->width - l - GUI_SHORTCUT_TEXT_BORDER_X_GAP,
                sc->y + ((sc->height >> 1) - (character_height >> 1)));
        }
        else
        {
            gui_move_text_cursor(
                sc->x + GUI_SHORTCUT_TEXT_BORDER_X_GAP + l,
                sc->y + ((sc->height >> 1) - (character_height >> 1)));
        }

        gui_set_line_height(character_height);
        if (sc->use_border)
        {
            if (sc->input_buffer[0] == 0)
            {
                gui_print_bordered_text(s);
            }
            else
            {
                gui_print_bordered_text((UI_string_type) sc->input_buffer);
            }
        }
        else
        {
            if (sc->input_buffer[0] == 0)
            {
                gui_print_text(s);
            }
            else
            {
                gui_print_text((UI_string_type) sc->input_buffer);
            }

        }
        gdi_layer_pop_clip();
    }

    gui_shortcut_restore_target_lcd_and_layer(sc, old_lcd_handle);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_close
 * DESCRIPTION
 *  Clears keyboard and keypad handlers registerd with the menu shortcut handler.
 *  Also clears the menu handling and hide functions.
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_close(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(sc->timer_callback);
    sc->hide_callback = gui_shortcut_dummy_hide_menu;
    sc->timer_callback = gui_shortcut_dummy_timer_callback;
    sc->display = MMI_TRUE;
    sc->display_disabled = MMI_FALSE;
    sc->input_buffer[0] = 0;
    sc->target_layer = GDI_NULL_HANDLE;
    sc->target_lcd = GDI_NULL_HANDLE;
    sc->alpha_blend_layer = GDI_NULL_HANDLE;
    sc->number = -1;
    sc->max_number = -1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_theme
 * DESCRIPTION
 *  set the specify theme
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 *  th      [IN]            Is the point of theme structure of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_theme(gui_shortcut_struct *sc, UI_shortcut_box_theme *th)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sc->normal_text_color = th->normal_text_color;
    sc->normal_text_border_color = th->normal_text_border_color;
    sc->use_border = th->use_border;
    sc->normal_font = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE);
    sc->active_font = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_current_theme
 * DESCRIPTION
 *  set the current theme
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_current_theme(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_set_theme(sc, current_shortcut_box_theme);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_item_count
 * DESCRIPTION
 *  Sets the number of digits allowed in the menu shortcut
 *  This is based on the number of items in the menu.
 * PARAMETERS
 *  sc          [IN/OUT]        Is the struct of shortcut
 *  n_items     [IN]            Is the number of menu items in a screen
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_item_count(gui_shortcut_struct *sc, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR s[GUI_SHORTCUT_MAX_SIZE];
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(n_items, (UI_string_type) s, 10);
    l = mmi_ucs2strlen(s);
    sc->input_length = (U8) l;
    sc->max_number = n_items;
    if(sc->number >= n_items)
    {
        sc->number = n_items -1;
    }
    if(sc->number < 0)
    {
        sc->number = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_width
 * DESCRIPTION
 *  Get the width of shortcut's area.
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_shortcut_get_width(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sc->display_disabled && sc->number >= 0)
    {
        width = sc->width;
    }
    return width;

}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_index
 * DESCRIPTION
 *  Set current number of the shortcut to be showed
 * PARAMETERS
 *  sc          [IN/OUT]        Is the struct of shortcut
 *  index       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_set_index(gui_shortcut_struct *sc, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sc->number = index - 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_index
 * DESCRIPTION
 *  Get current number of the shortcut to be showed
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_shortcut_get_index(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sc->number + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_is_show
 * DESCRIPTION
 *  shortcut is shown or not
 * PARAMETERS
 *  sc      [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  shortcut is shown or not
 *****************************************************************************/
MMI_BOOL gui_shortcut_is_show(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sc->display_disabled && sc->number >= 0 && sc->max_number > 0)
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
 *  gui_shortcut_set_show
 * DESCRIPTION
 *  Set shortcut shown or not
 * PARAMETERS
 *  sc          [IN/OUT]        Is the struct of shortcut
 *  show        [IN]            
 * RETURNS
 *  Shortcut is shown or not.
 *****************************************************************************/
void gui_shortcut_set_show(gui_shortcut_struct *sc, MMI_BOOL show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sc->display_disabled = show;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_enable_input_flag
 * DESCRIPTION
 *  enable the shortcut input flag
 * PARAMETERS
 *              
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_shortcut_enable_input_flag(void)
{
    goto_callback = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_max_number
 * DESCRIPTION
 *  Get current max number of the shortcut be allowed 
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_shortcut_get_max_number(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sc->max_number);
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_is_goto_callback
 * DESCRIPTION
 *  Get the goto callback state
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_shortcut_is_goto_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return goto_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_target_layer
 * DESCRIPTION
 *  set shortcut target layer
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 *  target_layer    [IN]            the target_layer want to set to shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void  gui_shortcut_set_target_layer(gui_shortcut_struct *sc, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    sc->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_target_layer
 * DESCRIPTION
 *  get shortcut target layer
 * PARAMETERS
 *  sc              [IN]        Is the struct of shortcut
 * RETURNS
 *  shortcut's target layer
 *****************************************************************************/
gdi_handle gui_shortcut_get_target_layer(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    return sc->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_reset_target_layer
 * DESCRIPTION
 *  reset shortcut target layer
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void  gui_shortcut_reset_target_layer(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    sc->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_target_lcd
 * DESCRIPTION
 *  set target lcd 
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 *  target_lcd      [IN]            the target_lcd want to set to shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void  gui_shortcut_set_target_lcd(gui_shortcut_struct *sc, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    sc->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_target_lcd
 * DESCRIPTION
 *  get shortcut target lcd
 * PARAMETERS
 *  sc              [IN]        Is the struct of shortcut
 * RETURNS
 *  shortcut's target lcd
 *****************************************************************************/
gdi_handle gui_shortcut_get_target_lcd(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    return sc->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_reset_target_lcd
 * DESCRIPTION
 *  reset shortcut target lcd
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void  gui_shortcut_reset_target_lcd(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    sc->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_set_alpha_blend_layer
 * DESCRIPTION
 *  set alpha_blend_layer
 * PARAMETERS
 *  sc                     [IN/OUT]        Is the struct of shortcut
 *  alpha_blend_layer      [IN]            the alpha blend layer want to set to shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void  gui_shortcut_set_alpha_blend_layer(gui_shortcut_struct *sc, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    sc->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_get_alpha_blend_layer
 * DESCRIPTION
 *  get shortcut alpha_blend_layer
 * PARAMETERS
 *  sc              [IN]        Is the struct of shortcut
 * RETURNS
 *  shortcut's alpha_blend_layer
 *****************************************************************************/
gdi_handle gui_shortcut_get_alpha_blend_layer(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    return sc->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_reset_alpha_blend_layer
 * DESCRIPTION
 *  reset shortcut alpha_blend_layer
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void  gui_shortcut_reset_alpha_blend_layer(gui_shortcut_struct *sc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (sc != NULL);
    sc->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_register_hide_callback
 * DESCRIPTION
 *  reset shortcut alpha_blend_layer
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 *  hide_callback   [IN]            Is the shortcut hide_callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_register_hide_callback(gui_shortcut_struct *sc, void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    MMI_DBG_ASSERT (sc != NULL);
    sc->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_shortcut_reset_hide_callback
 * DESCRIPTION
 *  reset shortcut hide callback function
 * PARAMETERS
 *  sc              [IN/OUT]        Is the struct of shortcut
 * RETURNS
 *  void
 *****************************************************************************/
void gui_shortcut_reset_hide_callback(gui_shortcut_struct *sc)
{
    MMI_DBG_ASSERT (sc != NULL);
    sc->hide_callback = NULL;
}


