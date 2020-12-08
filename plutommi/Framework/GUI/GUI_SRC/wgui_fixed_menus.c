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
 *   wgui_fixed_menus.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  fixed menu related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 21 2013 hujin.hu
 * removed!
 * .
 *
 * 01 17 2013 hujin.hu
 * removed!
 * .build warning
 *
 * 12 28 2012 hujin.hu
 * removed!
 * .
 *
 * 12 27 2012 hujin.hu
 * removed!
 * .
 *
 * 12 26 2012 hujin.hu
 * removed!
 * .
 *
 * 12 25 2012 hujin.hu
 * removed!
 * .
 *
 * 06 27 2012 wei.fu
 * removed!
 * .
 *
 * 10 11 2011 wei.fu
 * removed!
 * .
 *
 * 09 30 2011 wei.fu
 * removed!
 * .
 *
 * 09 06 2011 lin.jiang
 * removed!
 * .
 *
 * 08 05 2011 lin.jiang
 * removed!
 * Support thick with tab menu item height..
 *
 * 07 06 2011 lin.jiang
 * removed!
 * .
 *
 * 07 06 2011 lin.jiang
 * removed!
 * Support disable navigate list menu by drag scrollbar..
 *
 * 05 13 2011 wei.fu
 * removed!
 * .
 *
 * 05 12 2011 lin.jiang
 * removed!
 * .
 *
 * 05 05 2011 lin.jiang
 * removed!
 * .
 *
 * 02 09 2011 lin.jiang
 * removed!
 * .
 *
 * 02 08 2011 ray.wu
 * removed!
 * .
 *
 * 02 08 2011 mason.chang
 * removed!
 * Rename/move file(s)
 *
 * 01 27 2011 lin.jiang
 * removed!
 * .
 *
 * 01 16 2011 lin.jiang
 * removed!
 * .
 *
 * 12 14 2010 lin.jiang
 * removed!
 * .
 *
 * 12 14 2010 lin.jiang
 * removed!
 * .
 *
 * 11 20 2010 lin.jiang
 * removed!
 * .
 *
 * 11 12 2010 lin.jiang
 * removed!
 * .
 *
 * 11 10 2010 lin.jiang
 * removed!
 * if goto next item will not change highlight index, no need to redraw list..
 *
 * 11 05 2010 lin.jiang
 * removed!
 * .
 *
 * 10 22 2010 lin.jiang
 * removed!
 * .
 *
 * 10 12 2010 lin.jiang
 * removed!
 * .
 *
 * 10 10 2010 lin.jiang
 * removed!
 * .
 *
 * 09 28 2010 lin.jiang
 * removed!
 * .
 *
 * 08 06 2010 lin.jiang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Revise MMI header files
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "CustDataRes.h"
#include "wgui_fixed_menus.h"
#include "gdi_include.h"
#include "wgui_include.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_categories_util.h"
#include "wgui_dynamic_menus.h"
#include "gui_dynamic_menus.h"
#include "gui_asyncdynamic_menus.h"
#include "wgui_asyncdynamic_menus.h"
#include "gui_font_size.h"
#include "ProfilingEngine.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "gui_config.h"
#include "gui.h"
#include "gui_fixed_menus.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMI_features.h"
#include "gui_data_types.h"
#include "wgui.h"
#include "GlobalResDef.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "gui_fixed_menuitems.h"
#include "gui_effect_oem.h"
#include "CustMenuRes.h"
#include "CustDataProts.h"
#include "GlobalConstants.h"
#include "gui_menu_post_oem.h"
#include "mmi_frm_input_gprot.h"
#include "gui_scrollbars.h"
#include "gui_main_menu_post_oem.h"
#include "lcd_sw_inc.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_defs.h"
#include "ScreenRotationGprot.h"
#include "gui_switch.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "wgui_touch_screen.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ 
static void wgui_fixed_matrix_main_menu_hide_current_highlight(void);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */
MMI_BOOL g_list_goto_disable_item = MMI_FALSE;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ 
extern gui_image_text_rect matrix_mm_rect[];
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */
BOOL wgui_fixed_list_show_empty = MMI_TRUE;

PreKeyHandler g_gui_list_pre_key_handler = NULL;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
void(*g_gui_list_skipping_pre_handler)(void) = NULL;
void(*g_gui_list_skipping_post_handler)(void) = NULL;
#endif



void (*_MMI_hide_fixed_list_menu) (void) = UI_dummy_function;

fixed_list_menu MMI_fixed_list_menu;
gdi_handle g_list_empty_image_handle = GDI_ERROR_HANDLE;

#ifdef __PLUTO_MMI__
extern void draw_bg(void);
extern void draw_bg_animation(void);
#endif  // __PLUTO_MMI__

extern void wgui_display_fixed_text_list_pop_up_description(void);

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
extern PU8 MMI_mm_animation;
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */

#ifdef __MMI_OP11_SIDEBAR__
extern U32 g_gui_list_clock;
#endif
/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void register_fixed_list_keys_ex(void);

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
MMI_BOOL wgui_list_create_multi_icontext_menu(S32 menu_type,
                                                S32 number_of_items, S32 number_of_text, S32 number_of_icon,
												GetAsyncItemFuncPtr get_item_func,
												GetAsyncHintFuncPtr get_hint_func,S32 highlighted_item,S32 menuitem_height,
												U32 flag, U16 history_ID, U8* history_buffer);

//hujin



/*****************************************************************************
 * FUNCTION
 *  dummy_highlight_handler
 * DESCRIPTION
 *  Dummy menu item highlight handler.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(item_index);
}


#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
S32 wgui_fixed_list_menu_frame_counter = 0;
#endif 

/*****************************************************************************
 * FUNCTION
 *  create_fixed_list
 * DESCRIPTION
 *  Creates the fixed list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_list_menu(
        &MMI_fixed_list_menu,
        MMI_content_x,
        MMI_content_y,
        MMI_content_width,
        MMI_content_height);
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    wgui_fixed_list_menu_frame_counter = 0;
#endif 

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif 
    normal_fixed_list();
}


/*****************************************************************************
 * FUNCTION
 *  plain_fixed_list
 * DESCRIPTION
 *  Set the list menu to plain display mode. (without background and scroll bar)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plain_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags |= (UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_DISABLE_SCROLLBAR);
}


/*****************************************************************************
 * FUNCTION
 *  normal_fixed_list
 * DESCRIPTION
 *  Set the list menu to normal display mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void normal_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags &=
        ~(UI_LIST_MENU_ALIGN_TO_TOP | UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_DISABLE_SCROLLBAR |
          UI_LIST_MENU_ENABLE_TRANSITION | UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA |
          UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER | UI_LIST_MENU_DISABLE_PEN | UI_LIST_MENU_DISABLE_MENUITEM_GAP);

    /* force align to top as default */
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    /* force support loop navigate list */
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_LOOP;

    _MMI_hide_fixed_list_menu = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  register_hide_fixed_list
 * DESCRIPTION
 *  Register the hide callback of the fixed list menu.
 * PARAMETERS
 *  f       [IN]        hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void register_hide_fixed_list(void (*f)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _MMI_hide_fixed_list_menu = f;
}


/*****************************************************************************
 * FUNCTION
 *  move_fixed_list
 * DESCRIPTION
 *  Move the fixed list menu.
 * PARAMETERS
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_fixed_list(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PLUTO_LISTBOX__)
    gui_move_fixed_list_menu(&MMI_fixed_list_menu, x + 1, y + 1);
#else /* defined(__MMI_PLUTO_LISTBOX__) */ 
    gui_move_fixed_list_menu(&MMI_fixed_list_menu, x, y);
#endif /* defined(__MMI_PLUTO_LISTBOX__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_highlight_handler
 * DESCRIPTION
 *  Register the highlight handler for the fixed list.
 * PARAMETERS
 *  f       [IN]        highlight handler of the fixed list
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_highlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_highlighted = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_unhighlight_handler
 * DESCRIPTION
 *  Register the unhighlight handler for the fixed list.
 * PARAMETERS
 *  f       [IN]        unhighlight handler of the fixed list
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_unhighlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_unhighlighted = f;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_list_menu_show_empty_label_if_needed
 * DESCRIPTION
 *  Display "empty" in list menu if it is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_menu_show_empty_label_if_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width, img_width;
    S32 str_height, img_height;
    CHAR *str_ptr;
    PU8 img_ptr;
    gdi_handle old_alpha_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_list_empty_image_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(g_list_empty_image_handle);
        g_list_empty_image_handle = GDI_ERROR_HANDLE;
    }
    if (MMI_fixed_list_menu.n_items > 0 || !wgui_fixed_list_show_empty)
    {
        return;
    }
    //gdi_layer_push_clip();

    gdi_layer_push_and_set_clip(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);

    if (MMI_fixed_list_menu.n_items == -1)
    {
        img_ptr = (PU8)GetImage(IMG_GLOBAL_PROGRESS);
        gdi_image_get_dimension(img_ptr, &img_width, &img_height);
        offset_x = (MMI_fixed_list_menu.width - img_width) / 2;
        offset_y = (MMI_fixed_list_menu.height - img_height) / 2;
        gdi_image_draw_animation(
            MMI_fixed_list_menu.x + offset_x, 
            MMI_fixed_list_menu.y + offset_y,
            img_ptr, 
            &g_list_empty_image_handle);

    }
    else
    {
        gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_LIST));
        gui_set_text_color(*(current_MMI_theme->list_normal_text_color));
        
        str_ptr = GetString(STR_GLOBAL_EMPTY);
        
        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        
        offset_x = MMI_fixed_list_menu.x + ((MMI_fixed_list_menu.width - str_width) >> 1);
        offset_y = MMI_fixed_list_menu.y + ((MMI_fixed_list_menu.height - str_height) >> 1);
        
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        old_alpha_layer = gui_list_set_alpha_blending_layer_ex(0, MMI_FALSE);
        gui_print_text((UI_string_type) str_ptr);
        gui_list_reset_alpha_blending_layer(old_alpha_layer);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  show_fixed_list
 * DESCRIPTION
 *  Show the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_fixed_list(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif
    //for inline will blt when display some menu item, cause display inconsistance, MAUI_02445079
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
    gui_add_cleanup_hook(gui_stop_list_highlight_effect);
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_cancel_timer(gui_ssp_update_frame);
    
    if (gui_screen_smooth_scrolling_in_freerun())
    {
        gui_ssp_pen_up_dummy();
        gui_ssp_sync_list_menu_display();
    }
#endif


    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
    {
        _MMI_hide_fixed_list_menu();
    }
    
    gui_show_fixed_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS
    wgui_display_fixed_text_list_pop_up_description();
#endif
    /* if is emtpty folder, show a empty string */
    wgui_list_menu_show_empty_label_if_needed();
    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  show_fixed_list_specified_item
 * DESCRIPTION
 *  Show the specified fixed list.
 * PARAMETERS
 *  item_index      [IN]        the specified item index
 * RETURNS
 *  void
 *****************************************************************************/
void show_fixed_list_specified_item(S32 item_index)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif	
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
    gui_add_cleanup_hook(gui_stop_list_highlight_effect);
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
    {
        _MMI_hide_fixed_list_menu();
    }
    
    gui_show_fixed_list_menu_specified_item(&MMI_fixed_list_menu, item_index);
	//kavin_modify
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS
    wgui_display_fixed_text_list_pop_up_description();
#endif

    /* if is emtpty folder, show a empty string */
    wgui_list_menu_show_empty_label_if_needed();

    gdi_layer_blt_previous(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_menu_end_frame
 * DESCRIPTION
 *  Show the fixed list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        if (g_gui_list_skipping_pre_handler)
        {
            g_gui_list_skipping_pre_handler();
        }
        
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_hide_animations();
        gui_lock_double_buffer();
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS
        wgui_display_fixed_text_list_pop_up_description();
#endif
        if (g_gui_list_skipping_post_handler)
        {
            g_gui_list_skipping_post_handler();
        }
        gui_unlock_double_buffer();
        gdi_layer_blt_previous(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_fixed_list_menu_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  redraw_fixed_list
 * DESCRIPTION
 *  Redraw the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
	gdi_handle act_lcd;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ANI_BG_LIST_MENU)
    {
        return;
    }

#ifdef __MMI_SUBLCD__
	gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif	
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#else 
//hujin
#ifndef __MMI_UI_MENU_SLIM__
    gui_cancel_timer(gui_callback_highlighter_text_filler);
#endif
#endif 
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_cancel_timer(gui_ssp_update_frame);
    
    if (gui_screen_smooth_scrolling_in_freerun())
    {
        gui_ssp_pen_up_dummy();
        gui_ssp_sync_list_menu_display();
    }
#endif

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        gdi_layer_lock_frame_buffer();
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS
        wgui_display_fixed_text_list_pop_up_description();
#endif
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    }
    else
#endif
    {
    #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
        if (wgui_fixed_list_menu_frame_counter > 0)
        {
            wgui_fixed_list_menu_frame_counter++;
            gui_show_fixed_list_menu_no_draw(&MMI_fixed_list_menu);
        }
        else
        {
            wgui_fixed_list_menu_frame_counter = 1;
            gui_show_fixed_list_menu_no_draw(&MMI_fixed_list_menu);
            gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_fixed_list_menu_end_frame);
        }
    #else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
        gdi_layer_lock_frame_buffer();

        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        wgui_display_fixed_text_list_pop_up_description();

        gdi_layer_unlock_frame_buffer();

        gdi_layer_blt_previous(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

    #endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
        gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__	
        gdi_lcd_set_active(act_lcd);
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  clear_menu_highlight_handler
 * DESCRIPTION
 *  Clear the highlight handler of the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_menu_highlight_handler(void* m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	((fixed_menu*)m)->item_highlighted = dummy_highlight_handler;
}

/*****************************************************************************
 * FUNCTION
 *  clear_fixed_list_highlight_handler
 * DESCRIPTION
 *  Clear the highlight handler of the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_fixed_list_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
}

MMI_BOOL gui_list_check_goto_item(void)
{
    if( (MMI_fixed_list_menu.n_items <= 0)||
		((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0)))
		return MMI_FALSE;
	else
		return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item_common
 * DESCRIPTION
 *  Go to the previous/next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_goto_item_common(U32 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    MMI_BOOL disable_slide_effect = MMI_FALSE;
#endif
    //
    U32 flags, flags_ext;
    S32 item_index=0;

    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);
	if(key_code == KEY_UP_ARROW && key_type ==KEY_EVENT_REPEAT && (MMI_fixed_list_menu.highlighted_item == 0))
		return;
	
	if(key_code == KEY_DOWN_ARROW && key_type ==KEY_EVENT_REPEAT && (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1))
		return;

    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    if(direction<GUI_FIXED_LIST_ITEM)
    {
         item_index = direction;
         if (item_index == MMI_fixed_list_menu.highlighted_item &&
	        (MMI_fixed_list_menu.highlighted_item >= MMI_fixed_list_menu.first_displayed_item &&
	        MMI_fixed_list_menu.highlighted_item <= MMI_fixed_list_menu.last_displayed_item))
	    {
	        return;
	    }

	    MMI_fixed_list_menu.item_get_flag_function(
	        MMI_fixed_list_menu.items[item_index],  
	        MMI_fixed_list_menu.common_item_data,
	        item_index,  
	        &flags, 
	        &flags_ext);

	    g_list_goto_disable_item = MMI_FALSE;
	    if (flags & UI_MENUITEM_STATE_DISABLED)
	    {
	        g_list_goto_disable_item = MMI_TRUE;
	        return;
	    }
    }
	else
		{
		    if (MMI_fixed_list_menu.highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
		    {
		        return;
		    }

		    if (g_gui_list_pre_key_handler)
		    {
		        MMI_key_code_type code = (direction == GUI_FIXED_LIST_PREV_ITEM) ? KEY_UP_ARROW : KEY_DOWN_ARROW;
		        if (g_gui_list_pre_key_handler(code) == MMI_TRUE)
		        {
		            return;
		        }
		    }

		    if ((MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)&&(direction == GUI_FIXED_LIST_NEXT_ITEM) &&
		        (MMI_fixed_list_menu.flags & UI_LIST_MENU_INLINE_EDIT) &&
		        (!(MMI_fixed_list_menu.flags & UI_LIST_MENU_LOOP)))
		    {
		        if (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1)
		        {
		            return;
		        }
		    }
		    
		    /* do nothing if there is only 1 menu item */
		    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
		    {
		        return;
		    }
		}
//hujin
#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);

    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif	
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    if(direction<GUI_FIXED_LIST_ITEM)
    {
          if (item_index >= MMI_fixed_list_menu.n_items)
	    {
	        gdi_layer_pop_and_restore_active();
			//hujin
			#ifdef __MMI_SUBLCD__
	        gdi_lcd_set_active(act_lcd); 
			#endif
	        return;
	    }
	}
    gui_stop_list_highlight_effect();
#else
  //hujin
#ifndef __MMI_UI_MENU_SLIM__
    if((MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)&&(direction > GUI_FIXED_LIST_ITEM))
       gui_cancel_timer(gui_callback_highlighter_text_filler);
#endif
#endif 
    if(direction<GUI_FIXED_LIST_ITEM)
		gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
	else
	{

#ifdef __MMI_UI_LIST_GRID_LINE__
	    if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
	    MMI_fixed_list_menu.key_info = (direction == GUI_FIXED_LIST_PREV_ITEM) ? GUI_LIST_KEY_INFO_UP : GUI_LIST_KEY_INFO_DOWN;
#endif /* __MMI_UI_LIST_GRID_LINE__ */

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
	    if ((MMI_fixed_list_menu.highlighted_item > MMI_fixed_list_menu.last_displayed_item) || 
	        (MMI_fixed_list_menu.highlighted_item < MMI_fixed_list_menu.first_displayed_item))
	        disable_slide_effect = MMI_TRUE;

	    if ((direction == GUI_FIXED_LIST_NEXT_ITEM&& MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.last_displayed_item) || 
	        (direction == GUI_FIXED_LIST_PREV_ITEM && MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.first_displayed_item))
	        disable_slide_effect = MMI_TRUE;

	    if (!disable_slide_effect)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
	    {
	        gui_list_effect_slide_start();
	    }
	}

if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC)
{ 	
    if (direction == GUI_FIXED_LIST_PREV_ITEM)
    {
        gui_dynamic_list_menu_goto_previous_item(&MMI_fixed_list_menu);
    }
    else
    {
        gui_dynamic_list_menu_goto_next_item(&MMI_fixed_list_menu);
    }

    redraw_dynamic_list();

}
else if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
{

    /* Max: to redraw list if there is only 1 item. */
    if (!((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))&&(direction>GUI_FIXED_LIST_ITEM))   /* return; */
    {
        if (direction == GUI_FIXED_LIST_PREV_ITEM)
        {
            gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
        }
        else
        {
            gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
        }
    }

    if (MMI_current_menu_type == PAGE_MENU)
    {
        gdi_layer_pop_and_restore_active();
		//hujin
		#ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(act_lcd);  
		#endif
        return;
    }

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
#endif  // __PLUTO_MMI__    
#endif

#ifdef __MMI_INTERACTIVE_PROFILNG__
    if(direction>GUI_FIXED_LIST_ITEM)
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
#endif

    redraw_fixed_list();
	
#ifdef __MMI_INTERACTIVE_PROFILNG__
     if(direction > GUI_FIXED_LIST_ITEM)
	    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
#endif
	}   
	if(direction > GUI_FIXED_LIST_ITEM)
		{

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
		    if (!disable_slide_effect)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
		    {
		        gui_list_effect_slide_end();
		    }

#ifdef __MMI_UI_LIST_GRID_LINE__
		   if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
		    MMI_fixed_list_menu.key_info = GUI_LIST_KEY_INFO_NONE;
#endif /* __MMI_UI_LIST_GRID_LINE__ */ 
		}
    gdi_layer_pop_and_restore_active();
	//hujin
	#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
	#endif
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__	
/* under construction !*/
#endif
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
/* under construction !*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __MMI_UI_LIST_GRID_LINE__
/* under construction !*/
#endif /* __MMI_UI_LIST_GRID_LINE__ */
/* under construction !*/
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MMI_SUBLCD__
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __PLUTO_MMI__    
#endif
/* under construction !*/
#ifdef __MMI_INTERACTIVE_PROFILNG__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_INTERACTIVE_PROFILNG__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_LIST_GRID_LINE__
/* under construction !*/
#endif /* __MMI_UI_LIST_GRID_LINE__ */ 
/* under construction !*/
  #ifdef __MMI_SUBLCD__
/* under construction !*/
  #endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  //  U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  GetkeyInfo(&key_code, &key_type);
	//if(key_code == KEY_UP_ARROW && key_type ==KEY_EVENT_REPEAT && (MMI_fixed_list_menu.highlighted_item == 0))
//		return;

   //hujin
    //fixed_list_goto_item_common(0);
    gui_list_goto_item_common(GUI_FIXED_LIST_PREV_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 //   U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //   GetkeyInfo(&key_code, &key_type);
//	if(key_code == KEY_DOWN_ARROW && key_type ==KEY_EVENT_REPEAT && (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1))
//		return;
    

   // fixed_list_goto_item_common(1);
   gui_list_goto_item_common(GUI_FIXED_LIST_NEXT_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_home
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!gui_list_check_goto_item())
		return;
#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif	
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
    gui_fixed_list_menu_goto_first_item(&MMI_fixed_list_menu);

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
#endif  // __PLUTO_MMI__    
#endif

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_end
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!gui_list_check_goto_item())
		return;

#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
    gui_fixed_list_menu_goto_last_item(&MMI_fixed_list_menu);

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
#endif  // __PLUTO_MMI__
#endif

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_previous_page
 * DESCRIPTION
 *  Go to the item in the previous page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!gui_list_check_goto_item())
		return;

#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_fixed_list_menu_goto_previous_page(&MMI_fixed_list_menu);

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
#endif  // __PLUTO_MMI__    
#endif

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_next_page
 * DESCRIPTION
 *  Go to the item in the next page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!gui_list_check_goto_item())
		return;
#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_fixed_list_menu_goto_next_page(&MMI_fixed_list_menu);

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
#endif  // __PLUTO_MMI__    
#endif

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_item(S32 item_index)
{
   gui_list_goto_item_common(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item_push_first
 * DESCRIPTION
 *  Go to the specified item and make it the first displayed item if possible.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_item_push_first(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__    
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
#endif  // __PLUTO_MMI__    
#endif

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the fixed list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index < -1)
    {
        item_index = 0;
    }
    if (item_index > (MMI_fixed_list_menu.n_items - 1))
    {
        item_index = MMI_fixed_list_menu.n_items - 1;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        MMI_fixed_list_menu.highlighted_item = -1;
    }
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_shortcut_handler
 * DESCRIPTION
 *  Register the shortcut handler for the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
    register_menu_shortcut_handler(fixed_list_shortcut_handle_with_SSK);
#else
    register_menu_shortcut_handler(fixed_list_shortcut_handle);
#endif

#ifdef __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT)
        register_menu_shortcut_selected(wgui_list_menu_shortcut_executer);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_measure
 * DESCRIPTION
 *  Get the dimension of the fixed list.
 * PARAMETERS
 *  width       [OUT]       width
 *  height      [OUT]       height
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_measure(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_fixed_list_menu.width;
    *height = MMI_fixed_list_menu.height;
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_list
 * DESCRIPTION
 *  Resize the fixed list.
 * PARAMETERS
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_list(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Auto resize the height based on height of menu-items and the specified height */
    /* FIXME. move the following code to gui_resize_fixed_list_menu */
    S32 w = 0, h = 0, new_height = height;
    S32 ih, mh, rh, count;
    gui_common_menuitem_base_struct *m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *  !!!CAUTION!!!
     *  resize_fixed_list() might be called with both NULL common menu item 
     *  and private menu items. For example, NO SIM MAIN MENU.
     */
    /* doing menu alignment only when the common menu item is not NULL */
    if (m)
    {
        if (MMI_fixed_list_menu.items != NULL)
        {
            MMI_fixed_list_menu.current_displayed_item = 0;
            MMI_fixed_list_menu.item_measure_function(
                                    MMI_fixed_list_menu.items[0],
                                    m,
                                    &w,
                                    &h);

            /* 
             * The two line menu item must be considered as a single line, or the menu 
             * center alignment below will go wrong when the number of single line 
             * menu items in the menu is odd.
             */
            if (m->ext_flags & UI_MENUITEM_EXT_CONTAIN_TWO_LINE_MENU_ITEM)
            {
                h >>= 1;
            }
        }
        else
        {
            MMI_fixed_list_menu.item_measure_function(NULL, m, &w, &h);
        }

        ih = h;

        /* If ih equals to 0, hopefully it will raise a divided-by-zero error. */
        count = height / ih;
        mh = count * ih;
        rh = height - mh; 
		if(MMI_fixed_list_menu.flags & UI_LIST_MENU_ALIGN_TO_TOP)
		{
		   MMI_fixed_list_menu.top = MMI_fixed_list_menu.spacing = 0;
		}
        else if (h > 0)
        {
            /* Menu item spacing is not supported yet. */
            
            MMI_fixed_list_menu.spacing = 0;
            MMI_fixed_list_menu.top = rh / 2;
        }
    }

    if (MMI_fixed_list_menu.item_resize_function != NULL)
    {
        MMI_fixed_list_menu.item_resize_function(w, 0); /* Change width of menuitem according to list menu at the same time. */
    }

    gui_resize_fixed_list_menu(&MMI_fixed_list_menu, width, new_height);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_keys_ex
 * DESCRIPTION
 *  Register key handlers of the fixed list, including 
 *  KEY_UP_ARROW, KEY_DOWN_ARROW .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void register_fixed_list_keys_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_keys
 * DESCRIPTION
 *  Register key handlers of the fixed list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_fixed_list_keys_ex();
    SetKeyHandler(fixed_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
}


#ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__

/*****************************************************************************
 * FUNCTION
 *  register_horizontal_fixed_list_keys
 * DESCRIPTION
 *  Register key handlers of the horizontal fixed list, including 
 *  KEY_LEFT_ARROW and KEY_RIGHT_ARROW.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_horizontal_fixed_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_list_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_list_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
}

#endif /* __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__ */


/*****************************************************************************
 * FUNCTION
 *  fixed_list_disable_looping
 * DESCRIPTION
 *  Disable looping.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_disable_looping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_LOOP;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_enable_looping
 * DESCRIPTION
 *  Enable looping.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_enable_looping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_LOOP;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_list_menu_disable_access_by_shortcut
 * DESCRIPTION
 *  Disable access menu directly by shortcut.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_menu_disable_access_by_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_list_menu_enable_access_by_shortcut
 * DESCRIPTION
 *  Enable access menu directly by shortcut.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_menu_enable_access_by_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT;
}


/* Fixed matrix menu wrappers */

fixed_matrix_menu MMI_fixed_matrix_menu;


/*****************************************************************************
 * FUNCTION
 *  dummy_fixed_matrix_resize_function
 * DESCRIPTION
 *  Dummy matrix resize handler
 * PARAMETERS
 *  item_width      [IN]       item width 
 *  item_height     [IN]       item height
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fixed_matrix_resize_function(S32 item_width, S32 item_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(item_width);
    UI_UNUSED_PARAMETER(item_height);
}

void (*resize_fixed_matrix_menuitems) (S32 item_width, S32 item_height) = dummy_fixed_matrix_resize_function;


/*****************************************************************************
 * FUNCTION
 *  create_fixed_matrix
 * DESCRIPTION
 *  Creates the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_matrix_menu(
        &MMI_fixed_matrix_menu,
        MMI_content_x,
        MMI_content_y,
        MMI_content_width,
        MMI_content_height - MMI_matrix_bar_height);
}


/*****************************************************************************
 * FUNCTION
 *  move_fixed_matrix
 * DESCRIPTION
 *  Move the fixed matrix menu.
 * PARAMETERS
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_fixed_matrix(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_fixed_matrix_menu(&MMI_fixed_matrix_menu, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  show_fixed_matrix
 * DESCRIPTION
 *  Show the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_fixed_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    if (MMI_current_menu_type == MATRIX_MENU_EMS)
    {
        gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
    }
    else
    {
        gui_main_menu_matrix_slide_stop();
        
    #ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
        if (MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_FOR_MAINMENU)
        {
            gui_measure_image(
                MMI_mm_animation,
                &(MMI_fixed_matrix_menu.highlighted_item_width),
                &(MMI_fixed_matrix_menu.highlighted_item_height));
            if ((MMI_fixed_matrix_menu.last_highlighted_item != -1))
            {
                mtk_UI_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
            }
            else
            {
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
                gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
                gui_draw_filled_area(0,0,LCD_WIDTH,LCD_HEIGHT,current_MMI_theme->main_menu_bkg_filler);
                //gdi_image_draw(0, 0, current_MMI_theme->main_menu_bkg_filler->b);
                gdi_layer_pop_and_restore_active();
#endif                
                gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
            }
        }
        else
        {
            MMI_fixed_matrix_menu.highlighted_item_width = MMI_fixed_matrix_menu.item_width;
            MMI_fixed_matrix_menu.highlighted_item_height = MMI_fixed_matrix_menu.item_height;
            gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
        }
    #else /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
        gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
    #endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
    }
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(
        MMI_fixed_matrix_menu.x,
        MMI_fixed_matrix_menu.y,
        MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
        LCD_HEIGHT - 1);
}

/* For Draw Manager  */


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_matrix_col_rows
 * DESCRIPTION
 *  Reset the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_matrix_col_rows(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_fixed_matrix_col_rows(&MMI_fixed_matrix_menu);
}


/*****************************************************************************
 * FUNCTION
 *  configure_fixed_matrix
 * DESCRIPTION
 *  Set the number of columns and rows and the dimension of the menuitems.
 * PARAMETERS
 *  item_width      [IN]        item width
 *  item_height     [IN]        item height
 *  n_columns       [IN]        number of columns
 *  n_rows          [IN]        number of rows
 * RETURNS
 *  void
 *****************************************************************************/
void configure_fixed_matrix(S32 item_width, S32 item_height, S32 n_columns, S32 n_rows)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_matrix_menu_setup(&MMI_fixed_matrix_menu, item_width, item_height, n_columns, n_rows);
    resize_fixed_matrix_menuitems(MMI_fixed_matrix_menu.item_width, MMI_fixed_matrix_menu.item_height);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_highlight_handler
 * DESCRIPTION
 *  Register the highlight handler of the fixed matrix menu.
 * PARAMETERS
 *  f               [IN]        matrix highlight handler function
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_highlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.item_highlighted = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_fixed_matrix_highlight_handler
 * DESCRIPTION
 *  Clear the matrix highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_fixed_matrix_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.item_highlighted = dummy_highlight_handler;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	GetkeyInfo(&key_code, &key_type);
	if((key_code == KEY_LEFT_ARROW || key_code == KEY_VOL_UP) && key_type ==KEY_EVENT_REPEAT && (MMI_fixed_matrix_menu.highlighted_item == 0))
		return;


    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif

    gui_main_menu_matrix_slide_start();
    
    gui_fixed_matrix_menu_goto_previous_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    if (MMI_fixed_matrix_menu.disable_scaling == MMI_FALSE && MMI_fixed_matrix_menu.last_highlighted_item != -1)
    {
        wgui_fixed_matrix_main_menu_hide_current_highlight();
    }
#endif    
    gui_main_menu_matrix_slide_end();    

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GetkeyInfo(&key_code, &key_type);
	if((key_code == KEY_RIGHT_ARROW || key_code == KEY_VOL_DOWN) && key_type ==KEY_EVENT_REPEAT && (MMI_fixed_matrix_menu.highlighted_item == MMI_fixed_matrix_menu.n_items - 1))
		return;


    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif

    gui_list_effect_slide_stop();
    gui_main_menu_matrix_slide_start();

    gui_fixed_matrix_menu_goto_next_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    if (MMI_fixed_matrix_menu.disable_scaling == MMI_FALSE && MMI_fixed_matrix_menu.last_highlighted_item != -1)
    {
        wgui_fixed_matrix_main_menu_hide_current_highlight();
    }
#endif    
    gui_main_menu_matrix_slide_end();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif        
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_column
 * DESCRIPTION
 *  Go to the previous column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_column(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_previous_column(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_column
 * DESCRIPTION
 *  Go to the next column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_column(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_next_column(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_row
 * DESCRIPTION
 *  Go to the previous row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_row(void)
{
 	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);
	if(key_code == KEY_UP_ARROW && key_type ==KEY_REPEAT && (MMI_fixed_matrix_menu.highlighted_item == 0))
		return;


    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
    
    gui_main_menu_matrix_slide_start();
    
    gui_fixed_matrix_menu_goto_previous_row(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    if (MMI_fixed_matrix_menu.disable_scaling == MMI_FALSE && MMI_fixed_matrix_menu.last_highlighted_item != -1)
    {
        wgui_fixed_matrix_main_menu_hide_current_highlight();
    }
#endif    
    gui_main_menu_matrix_slide_end();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_row
 * DESCRIPTION
 *  Go to the the next row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_row(void)
{
 	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);
	if(key_code == KEY_DOWN_ARROW && key_type ==KEY_REPEAT && (MMI_fixed_matrix_menu.highlighted_row == MMI_fixed_matrix_menu.n_rows -1))
		return;


    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
    
    gui_main_menu_matrix_slide_start();
    
    gui_fixed_matrix_menu_goto_next_row(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    if (MMI_fixed_matrix_menu.disable_scaling == MMI_FALSE && MMI_fixed_matrix_menu.last_highlighted_item != -1)
    {
        wgui_fixed_matrix_main_menu_hide_current_highlight();
    }
#endif    
    gui_main_menu_matrix_slide_end();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_home
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_first_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_end
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_last_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_page
 * DESCRIPTION
 *  Go to the previous page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_previous_page(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_page
 * DESCRIPTION
 *  Go to the next page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_next_page(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Use last_highlighted_item = -2 to indicate this goto item function fails.
     * See main_menu_shortcut_executer().
     */
    // TODO: SHOULD USE A BETTER WAY TO RESPOND.
    if ((item_index >= MMI_fixed_matrix_menu.n_items) || (item_index < 0))
    {
        MMI_fixed_matrix_menu.last_highlighted_item = -2;

        return;
    }
    
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
    if (!(MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_DISABLE_DRAW))
    {
        show_fixed_matrix();
    }
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the fixed matrix.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.highlighted_item = -1;
    gui_fixed_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_shortcut_handler
 * DESCRIPTION
 *  Register the menu shortcut handler for the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(fixed_matrix_goto_item);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_measure
 * DESCRIPTION
 *  Gets the dimension of the fixed matrix menu.
 * PARAMETERS
 *  width       [OUT]       width
 *  height      [OUT]       height
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_measure(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_fixed_matrix_menu.width;
    *height = MMI_fixed_matrix_menu.height;
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_matrix
 * DESCRIPTION
 *  Change the size of the fixed matrix menu.
 * PARAMETERS
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_matrix(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_fixed_matrix_menu(&MMI_fixed_matrix_menu, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_keys
 * DESCRIPTION
 *  Register key handlers for the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_previous_column, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_column, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_previous_column, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_next_column, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_matrix
 * DESCRIPTION
 *  Clear key and highlight handlers for the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
    wgui_text_menuitem_reset_scrolling();
    
    MMI_fixed_matrix_menu.flags &= ~UI_DYAMIC_MATRIX_MENU_ALIGN_LEFT_TOP;
    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    MMI_fixed_matrix_menu.item_highlighted = dummy_highlight_handler;

#ifdef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_matrix_ssp_reset_state();
#endif
    gui_ssp_reset_static_layer();
}

#if ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))

UI_string_type wgui_CM3D_items[WGUI_CM3D_MAX_ITEMS];
PU8 wgui_CM3D_images[WGUI_CM3D_MAX_ITEMS * WGUI_CM3D_N_ITEM_IMAGES];
PU8 wgui_CM3D_common_images[WGUI_CM3D_N_COMMON_IMAGES];
S32 wgui_CM3D_n_items;
UI_3D_circular_menu wgui_CM3D_menu;

/* 081404 Calvin fine tuned */
CM3D_item_position wgui_CM3D_item_positions[] = 
{
#if !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__)     /* 041205 Calvin modieid */
    {120, 82},              /* 0  */
    {104, 82},
    {88, 82},
    {72, 82},               /* 1  */
    {58, 82},               /* {58,79}, */
    {44, 79},
    {28, 74},               /* 2  */
    {22, 68},
    {15, 64},               /* {14,66}, */
    {7, 51},    // {4,51},  /*      3       */
    {9, 42},                /* {4,42}, */
    {11, 31},               /* {14,33}, */
    {22, 26},   // {21,25}, /*      4       */
    {29, 23},               /* {30,24}, */
    {38, 18},               /* {40,20}, */
    {51, 16},               /* 5  */
    {60, 16},
    {67, 15},
    {78, 15},               /* 6  */
    {85, 15},
    {92, 14},
    {103, 16},              /* 7  */
    {106, 16},
    {112, 16},
    {120, 16},              /* 8  */
    {0, 0},
    {0, 0},
#else /* !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__) */ 
    {169, 128},             /* 0  */
    {143, 126},
    {119, 124},
    {95, 122},              /* 1  */
    {74, 119},              /* {58,79}, */
    {54, 117},
    {34, 115},              /* 2  */
    {23, 102},
    {12, 89},               /* {14,66}, */
    {2, 76},    // {4,51},  /*      3       */
    {9, 62},                /* {4,42}, */
    {16, 54},               /* {14,33}, */
    {36, 52},   // {21,25}, /*      4       */
    {47, 47},               /* {30,24}, */
    {58, 41},               /* {40,20}, */
    {70, 35},               /* 5  */
    {81, 32},
    {93, 29},
    {105, 26},              /* 6  */
    {115, 25},
    {125, 24},
    {136, 23},              /* 7  */
    {147, 22},
    {158, 21},
    {169, 20},              /* 8  */
    {0, 0},
    {0, 0},
#endif /* !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__) */ 
};

CM3D_item_position wgui_CM3DR_item_positions[] =    /* Positions for 3D Rotate Menu */
{
#if ( defined  (__MMI_MAINLCD_128X160__))

#ifdef ROTATE_HORI      /* circular horizontal */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {72, 40},   /*  1  */
    {60, 27},
    {48, 15},
    {36, 9},    /* 2  */
    {24, 15},   /* {120,120}, */
    {12, 27},   /* {120,120}, */
    {0, 40},    /*   3  */
    {128, 160}, /* {30,11}, */
    {128, 160}, /* {15,25}, */
#else /* ROTATE_HORI */ 
#ifdef ROTATE_VERT      /* ////vertical */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {36, 84},   /*  1  */
    {36, 70},
    {36, 56},
    {36, 42},   /* 2  */
    {36, 28},   /* {120,120}, */
    {36, 14},   /* {120,120}, */
    {36, 0},    /*   3  */
    {128, 160}, /* {40,20}, */
    {128, 160}, /* {40,10}, */
#else /* ROTATE_VERT */ 
#ifdef ROTATE_VERT_CIR  /* /default is vertical circular */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {4, 84},    /*   1  */
    {19, 70},
    {30, 56},
    {38, 42},   /* 2  */
    {30, 28},   /* {120,120}, */
    {19, 14},   /* {120,120}, */
    {4, 0},     /* 3  */
    {128, 160}, /* {18,35}, */
    {128, 160}, /* {10,27}, */
#else /* ROTATE_VERT_CIR */ 
#ifdef ROTATE_VERT_LINE /* ////vertical */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {0, 84},    /*   1  */
    {0, 70},
    {0, 56},
    {0, 42},    /* 2  */
    {0, 28},    /* {120,120}, */
    {0, 14},    /* {120,120}, */
    {0, 0},     /* 3  */
    {128, 160}, /* {8,20}, */
    {128, 160}, /* {8,10}, */
#else /* ROTATE_VERT_LINE */ 
#ifdef ROTATE_VERT_LINE_RIGHT   /* ////vertical */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {72, 84},   /*  1  */
    {72, 70},
    {72, 56},
    {72, 42},   /* 2  */
    {72, 28},   /* {120,120}, */
    {72, 14},   /* {120,120}, */
    {72, 0},    /*   3  */
    {128, 160}, /* {70,20}, */
    {128, 160}  /* {70,10} */
    // #endif
#endif /* ROTATE_VERT_LINE_RIGHT */ 
#endif /* ROTATE_VERT_LINE */ 
#endif /* ROTATE_VERT_CIR */ 
#endif /* ROTATE_VERT */ 
#endif /* ROTATE_HORI */ 
#elif defined( __MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)    /* 041205 Calvin modieid */

#ifdef ROTATE_HORI      /* circular horizontal */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {108, 66},  /* 1  */
    {90, 50},
    {72, 37},
    {54, 9},    /* 2  */
    {36, 37},   /* {177,220}, */
    {18, 50},   /* {177,220}, */
    {0, 66},    /*   3  */
    {177, 220}, /* {42,42}, */
    {177, 220}, /* {27,56}, */
#else /* ROTATE_HORI */ 
#ifdef ROTATE_VERT      /* ////vertical */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {40, 138},  /* 1  */
    {40, 115},
    {40, 92},
    {40, 69},   /* 2  */
    {40, 46},   /* {177,220}, */
    {40, 23},   /* {177,220}, */
    {40, 0},    /*   3  */
    {177, 220}, /* {80,30}, */
    {177, 220}, /* {80,20}, */
#else /* ROTATE_VERT */ 
#ifdef ROTATE_VERT_CIR  /* /default is vertical circular */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {33, 138},  /* 1  */// {4,95},/*  1       */
    {48, 115},  /* {14,80}, */
    {60, 93},
    {66, 69},   /* 2  */
    {60, 46},   /* {177,220}, */
    {48, 23},   /* {177,220}, */
    {33, 0},    /* 3  */
    {177, 220}, /* {50,60}, */
    {177, 220}, /* {40,50}, */
#else /* ROTATE_VERT_CIR */ 
#ifdef ROTATE_VERT_LINE /* ////vertical */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {0, 138},   /* 1  */
    {0, 115},
    {0, 92},
    {0, 69},    /* 2  */
    {0, 46},    /* {177,220}, */
    {0, 23},    /* {177,220}, */
    {0, 0},     /* 3  */
    {177, 220}, /* {29,33}, */
    {177, 220}, /* {29,20}, */
#else /* ROTATE_VERT_LINE */ 
#ifdef ROTATE_VERT_LINE_RIGHT   /* ////vertical */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {108, 138}, /* 1  */
    {108, 115},
    {108, 92},
    {108, 69},  /* 2  */
    {108, 46},  /* {177,220}, */
    {108, 23},  /* {177,220}, */
    {108, 0},   /* 3  */
    {177, 220}, /* {120,30}, */
    {177, 220}  /* {120,20} */
#endif /* ROTATE_VERT_LINE_RIGHT */ 
#endif /* ROTATE_VERT_LINE */ 
#endif /* ROTATE_VERT_CIR */ 
#endif /* ROTATE_VERT */ 
#endif /* ROTATE_HORI */ 
#else /* __MMI_MAINLCD_128X128__ */
#ifdef ROTATE_HORI      /* circular horizontal */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {79, 36},   /*  1  */
    {66, 23},
    {53, 14},
    {40, 4},    /* 2  */
    {27, 14},   /* {120,120}, */
    {14, 23},   /* {120,120}, */
    {1, 36},    /*   3  */
    {128, 128}, /* {30,11}, */
    {128, 128}, /* {15,25}, */
#else /* ROTATE_HORI */ 
#ifdef ROTATE_VERT      /* ////vertical */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {40, 72},   /*  1  */
    {40, 60},
    {40, 48},
    {40, 36},   /* 2  */
    {40, 24},   /* {120,120}, */
    {40, 12},   /* {120,120}, */
    {40, 0},    /*   3  */
    {128, 128}, /* {40,20}, */
    {128, 128}, /* {40,10}, */
#else /* ROTATE_VERT */ 
#ifdef ROTATE_VERT_CIR  /* /default is vertical circular */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {4, 72},    /*   1  */
    {17, 60},
    {28, 48},
    {38, 36},   /* 2  */
    {28, 24},   /* {120,120}, */
    {17, 12},   /* {120,120}, */
    {4, 0},     /* 3  */
    {128, 128}, /* {18,35}, */
    {128, 128}, /* {10,27}, */
#else /* ROTATE_VERT_CIR */ 
#ifdef ROTATE_VERT_LINE /* ////vertical */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {0, 72},    /*   1  */
    {0, 60},
    {0, 48},
    {0, 36},    /* 2  */
    {0, 24},    /* {120,120}, */
    {0, 12},    /* {120,120}, */
    {0, 0},     /* 3  */
    {128, 128}, /* {8,20}, */
    {128, 128}, /* {8,10}, */
#else /* ROTATE_VERT_LINE */ 
#ifdef ROTATE_VERT_LINE_RIGHT   /* ////vertical */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {80, 72},   /*  1  */
    {80, 60},
    {80, 48},
    {80, 36},   /* 2  */
    {80, 24},   /* {120,120}, */
    {80, 12},   /* {120,120}, */
    {80, 0},    /*   3  */
    {128, 128}, /* {70,20}, */
    {128, 128}  /* {70,10} */
#endif /* ROTATE_VERT_LINE_RIGHT */ 
#endif /* ROTATE_VERT_LINE */ 
#endif /* ROTATE_VERT_CIR */ 
#endif /* ROTATE_VERT */ 
#endif /* ROTATE_HORI */ 

#endif /* MMI_UI_STYLES */
};

/* Temporary theme data. Will be removed later */

UI_3D_circular_menu_theme wgui_CM3D_theme = 
{
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    &MMI_default_font,
    0
};


/*****************************************************************************
 * FUNCTION
 *  set_circular_3d_menu_items
 * DESCRIPTION
 *  Set the items, common images and item images to be used
 *  by the circular 3D menu.
 * PARAMETERS
 *  n_items     [IN]        Number of items
 *  items       [IN]        Array of items (n_items number of elements)
 *  images      [IN]        Array of item images ((n_items * number of images per item) number of elements)
 * RETURNS
 *  void
 *****************************************************************************/
void set_circular_3d_menu_items(S32 n_items, MMI_ID_TYPE *items, MMI_ID_TYPE *images)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_common_images[0] = get_image(CM3D_COMMON_IMAGE0_IMAGE_ID);
    wgui_CM3D_common_images[1] = get_image(CM3D_COMMON_IMAGE1_IMAGE_ID);
    wgui_CM3D_common_images[2] = get_image(CM3D_COMMON_IMAGE2_IMAGE_ID);
    wgui_CM3D_common_images[3] = get_image(CM3D_COMMON_IMAGE3_IMAGE_ID);

    wgui_CM3D_n_items = n_items;
    for (i = 0; i < n_items; i++)
    {
        wgui_CM3D_items[i] = get_string(items[i]);
    }
    for (i = 0; i < n_items; i++)
    {
        wgui_CM3D_images[i] = get_image(images[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_circular_3d_menu
 * DESCRIPTION
 *  Create the circular 3D menu.
 * PARAMETERS
 *  n_items     [IN]        Number of items
 *  items       [IN]        Array of String IDs corresponding to items (n_items number of elements)
 *  images      [IN]        Array of Image IDs corresponding to item images ((n_items * number of images per item) number of elements)
 * RETURNS
 *  void
 *****************************************************************************/
void create_circular_3d_menu(S32 n_items, MMI_ID_TYPE *items, MMI_ID_TYPE *images)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_theme.bg_filler = current_MMI_theme->main_menu_background_filler;
    current_3D_circular_menu_theme = &wgui_CM3D_theme;
    set_circular_3d_menu_items(n_items, items, images);
    if (MMI_current_menu_type == CIRCULAR_3D_MENU)
    {
        gui_create_3D_circular_menu(
            &wgui_CM3D_menu,
            0,
            0,
            UI_device_width,
            UI_device_height - MMI_softkey_height,
            WGUI_CM3D_N_DISPLAYED_ITEMS + 2,
            wgui_CM3D_item_positions,
            WGUI_CM3D_N_ITEM_IMAGES,
            wgui_CM3D_images,
            wgui_CM3D_common_images);
    }
    else
    {
        gui_create_3D_circular_menu(
            &wgui_CM3D_menu,
            0,
            0,
            UI_device_width,
            UI_device_height - MMI_softkey_height,
            WGUI_CM3D_N_DISPLAYED_ITEMS + 2,
            wgui_CM3DR_item_positions,
            WGUI_CM3D_N_ITEM_IMAGES,
            wgui_CM3D_images,
            wgui_CM3D_common_images);
    }
    gui_set_3D_circular_menu_items(&wgui_CM3D_menu, n_items, wgui_CM3D_items);
}


/*****************************************************************************
 * FUNCTION
 *  show_circular_3d_menu
 * DESCRIPTION
 *  Show the circular 3D menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_circular_3d_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = wgui_CM3D_menu.x;
    S32 y1 = wgui_CM3D_menu.y;
    S32 x2 = x1 + wgui_CM3D_menu.width - 1;
    S32 y2 = y1 + wgui_CM3D_menu.height - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
#if defined (__GDI_MEMORY_PROFILE_2__)
    gui_set_multilayer_mask(gui_get_multilayer_mask() | UI_MUL_BKG_MAINMENU);
#endif 
    gui_show_3D_circular_menu(&wgui_CM3D_menu);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
}

/* For Draw Manager  */


/*****************************************************************************
 * FUNCTION
 *  move_circular_3d_menu
 * DESCRIPTION
 *  Move the circular 3D menu.
 * PARAMETERS
 *  s32X        [IN]        x
 *  s32Y        [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_circular_3d_menu(S32 s32X, S32 s32Y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_3D_circular_menu(&wgui_CM3D_menu, s32X, s32Y);
}

/* Add for Draw Manager */


/*****************************************************************************
 * FUNCTION
 *  resize_circular_3d_menu
 * DESCRIPTION
 *  Resize the circular 3D menu.
 * PARAMETERS
 *  s32Width        [IN]        width
 *  s32Height       [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_circular_3d_menu(S32 s32Width, S32 s32Height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_3D_circular_menu(&wgui_CM3D_menu, s32Width, s32Height);
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_gfx_processor
 * DESCRIPTION
 *  Circular 3D menu animation processor (Hooked to a timer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_gfx_processor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CM3D_MENU_GFX_TIMER
    if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &=
            ~(UI_3D_CIRCULAR_MENU_TRANSITION_L1 | UI_3D_CIRCULAR_MENU_TRANSITION_L2 | UI_3D_CIRCULAR_MENU_TRANSITION_R1
              | UI_3D_CIRCULAR_MENU_TRANSITION_R2);

        if (MMI_current_menu_type == CIRCULAR_3D_MENU)
        {
            wgui_CM3D_menu.item_highlighted(GetCurrHiliteID());
        }
        else
        {
            if (GetCurrHiliteID() == wgui_CM3D_menu.n_items - 1)
            {
                wgui_CM3D_menu.item_highlighted(0);
            }
            else
            {
                wgui_CM3D_menu.item_highlighted(GetCurrHiliteID() + 1);
            }
        }
    }
#else /* CM3D_MENU_GFX_TIMER */ 
    if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        circular_3d_menu_gfx_processor();
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        circular_3d_menu_gfx_processor();
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        circular_3d_menu_gfx_processor();
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        circular_3d_menu_gfx_processor();
    }
    else
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &=
            ~(UI_3D_CIRCULAR_MENU_TRANSITION_L1 | UI_3D_CIRCULAR_MENU_TRANSITION_L2 | UI_3D_CIRCULAR_MENU_TRANSITION_R1
              | UI_3D_CIRCULAR_MENU_TRANSITION_R2);

        if (MMI_current_menu_type == CIRCULAR_3D_MENU)
        {
            wgui_CM3D_menu.item_highlighted(GetCurrHiliteID());
        }
        else
        {
            if (GetCurrHiliteID() == wgui_CM3D_menu.n_items - 1)
            {
                wgui_CM3D_menu.item_highlighted(0);
            }
            else
            {
                wgui_CM3D_menu.item_highlighted(GetCurrHiliteID() + 1);
            }
        }
    }
#endif /* CM3D_MENU_GFX_TIMER */ 
}


/*****************************************************************************
 * FUNCTION
 *  stop_rotate_circular_menu
 * DESCRIPTION
 *  Stop the circular 3D menu animation effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void stop_rotate_circular_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CM3D_MENU_GFX_TIMER
    gui_cancel_timer(circular_3d_menu_gfx_processor);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_previous
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_3D_circular_menu_goto_previous_item(&wgui_CM3D_menu);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_L1;
    circular_3d_menu_gfx_processor();
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_next
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_3D_circular_menu_goto_next_item(&wgui_CM3D_menu);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_R1;
    circular_3d_menu_gfx_processor();
}


/*****************************************************************************
 * FUNCTION
 *  register_circular_3d_menu_keys
 * DESCRIPTION
 *  Registers the key handlers for the circular 3D menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_circular_3d_menu_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(circular_3d_menu_previous, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_previous, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_previous, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(circular_3d_menu_next, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(circular_3d_menu_previous, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(circular_3d_menu_next, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  register_rotate_menu_keys
 * DESCRIPTION
 *  Register the key handlers for the rotate menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_rotate_menu_keys(void)
{
#ifdef ROTATE_HORI
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(circular_3d_menu_previous, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_previous, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(circular_3d_menu_next, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
#else /* ROTATE_HORI */ 
    SetKeyHandler(circular_3d_menu_previous, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_previous, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(circular_3d_menu_next, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
#endif /* ROTATE_HORI */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_circular_3d_highlight_handler
 * DESCRIPTION
 *  Register the highlight handler for the 3d circular menu.
 * PARAMETERS
 *  f               [IN]        hightlight handler function
 * RETURNS
 *  void
 *****************************************************************************/
void register_circular_3d_highlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_menu.item_highlighted = f;
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the circular 3D menu.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_menu.highlighted_item = -1;
    gui_3D_circular_menu_goto_item(&wgui_CM3D_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ROTATE_MENU)
    {
        item_index -= 1;
        if (item_index < 0)
        {
            item_index = wgui_CM3D_menu.n_items - 1;
        }
    }
    gui_3D_circular_menu_goto_item(&wgui_CM3D_menu, item_index);
    show_circular_3d_menu();
}


/*****************************************************************************
 * FUNCTION
 *  register_3d_menu_shortcut_handler
 * DESCRIPTION
 *  Register the shortcut handler for the circular 3d menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_3d_menu_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(circular_3d_menu_goto_item);
}

#endif /* ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU)) */ 


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_list_show_empty
 * DESCRIPTION
 *  Reset fixed list show empty flag. The "empty" string is shown by default. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_list_show_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_fixed_list_show_empty = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  disable_fixed_list_show_empty
 * DESCRIPTION
 *  Do not show the fixed list empty string.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_fixed_list_show_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_fixed_list_show_empty = MMI_FALSE;
}




#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
extern MMI_BOOL gui_list_menu_is_support_smooth_scrolling(void);


/*****************************************************************************
 * FUNCTION
 *  fixed_list_shortcut_handle_with_SSK
 * DESCRIPTION
 *  shortcut handle with smooth scrolling effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_shortcut_handle_with_SSK(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    S32 old_highlighed_item, new_highlighted_item, menu_height;
    gui_common_menuitem_base_struct *m;
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    MMI_BOOL need_handle = MMI_FALSE;
#endif
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    MMI_fixed_list_menu.item_get_flag_function(
        MMI_fixed_list_menu.items[item_index],  
        MMI_fixed_list_menu.common_item_data,
        item_index,  
        &flags, 
        &flags_ext);

    g_list_goto_disable_item = MMI_FALSE;
    if (flags & UI_MENUITEM_STATE_DISABLED)
    {
        g_list_goto_disable_item = MMI_TRUE;
        return;
    }

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if (item_index == MMI_fixed_list_menu.highlighted_item &&
        (MMI_fixed_list_menu.highlighted_item < MMI_fixed_list_menu.first_displayed_item ||
        MMI_fixed_list_menu.highlighted_item > MMI_fixed_list_menu.last_displayed_item ))
    {
        need_handle = MMI_TRUE;
    }

    if (item_index != MMI_fixed_list_menu.highlighted_item || need_handle)
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    if (item_index != MMI_fixed_list_menu.highlighted_item)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    {
    #ifdef __MMI_SUBLCD__
        gdi_lcd_get_active(&act_lcd);
        gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
	#endif	
        gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        if (item_index >= MMI_fixed_list_menu.n_items)
        {
            gdi_layer_pop_and_restore_active();
			//hujin
			#ifdef __MMI_SUBLCD__
            gdi_lcd_set_active(act_lcd);        
            #endif
            return;
        }
        gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

        /* calculate first_displayed_item, last_displayed_item and highlighted_item */
        old_highlighed_item = MMI_fixed_list_menu.highlighted_item;
        gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

        if (gui_list_menu_is_support_smooth_scrolling())
        {
            new_highlighted_item = MMI_fixed_list_menu.highlighted_item;

            m = (gui_common_menuitem_base_struct*) MMI_fixed_list_menu.common_item_data;

            menu_height = MMI_fixed_list_menu.displayed_items * m->height;
            if (gui_list_menu_is_highlight_item_two_line())
            {
                menu_height += MMI_fixed_list_menu.height;
            }

            if ((new_highlighted_item == MMI_fixed_list_menu.first_displayed_item) && (new_highlighted_item > 0))
            {
                MMI_fixed_list_menu.first_displayed_item -= 1;
                MMI_fixed_list_menu.last_displayed_item -= 1;
            }
            else
            {
                if (MMI_fixed_list_menu.height < menu_height + (m->height / 3))
                {
                    if ((new_highlighted_item == MMI_fixed_list_menu.last_displayed_item) && (new_highlighted_item < (MMI_fixed_list_menu.n_items - 1)))
                    {
                        MMI_fixed_list_menu.first_displayed_item += 1;
                        MMI_fixed_list_menu.last_displayed_item += 1;
                    }
                }
            }
        }

        if (MMI_current_menu_type == PAGE_MENU)
        {
            gdi_layer_pop_and_restore_active();
			#ifdef __MMI_SUBLCD__
            gdi_lcd_set_active(act_lcd); 
			#endif
            return;
        }

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
#ifdef __PLUTO_MMI__
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
        {
            draw_bg();
            draw_bg_animation();
        }
#endif  // __PLUTO_MMI__        
#endif

        redraw_fixed_list();
        gdi_layer_pop_and_restore_active();
		//hujin
		#ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(act_lcd);
		#endif
    }
}
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */


/*
 * new list api
 */
// fixed text
/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_create_menu_common
 * DESCRIPTION
 *  Helper function
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        index of highlight
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_fixed_list_create_menu_common(S32 item_count, S32 highlight_item, U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_current_menu_type = LIST_MENU;
    register_fixed_list_highlight_handler(standard_list_highlight_handler);
    if (!(flag & WGUI_LIST_MENU_DISABLE_KEY_HANDLE))
    {
        if (flag & WGUI_LIST_MENU_DISABLE_VOL_KEY)
            register_fixed_list_keys_ex();
        else
            register_fixed_list_keys();
    }
    MMI_fixed_list_menu.n_items = item_count;
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_FIXED;
//#ifndef __MMI_UI_MENU_SLIM__
    wgui_title_set_menu_shortcut_number(-1);
//#endif    
    if (!(flag & WGUI_LIST_MENU_DISABLE_SHORTCUT))
    {        
        wgui_title_set_shortcut_count(item_count);
    //    register_hide_menu_shortcut(gui_redraw_menu_shortcut);
		register_fixed_list_shortcut_handler();

    }

    h_flag = set_list_menu_category_history(history_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlight_item;
    }
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    wgui_setup_pop_up_description_transition();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_items_common
 * DESCRIPTION
 *  Helper function
 * PARAMETERS
 *  list_of_items               [IN]        List of text items.
 *  list_of_descriptions        [IN]        Descriptions of list items
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_fixed_list_add_items_common(U8 **list_of_descriptions)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, item_count;
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    S32 hints = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_count = MMI_fixed_list_menu.n_items;
    for (i = 0; i < item_count; i++)
    {
        if (list_of_descriptions == NULL)
        {
            wgui_pop_up_description_strings[i].text_strings[0] = NULL;
        }
        else
        {
            wgui_pop_up_description_strings[i].text_strings[0] = (UI_string_type) list_of_descriptions[i];
        #ifdef __MMI_UI_HINTS_IN_MENUITEM__
            if (wgui_pop_up_description_strings[i].text_strings[0])
            {
                hints = 1;
            }
        #endif  // __MMI_UI_HINTS_IN_MENUITEM__
        }
    }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    if (hints)
    {
        if (is_set_force_icon_on_highlight_only_in_menuitem())
        {
            wgui_show_icon_only_highlight_in_icontext_menuitem();
        }
        if (is_set_force_all_hints_in_menuitem())
        {
            wgui_enable_hints_in_icontext_menuitem();
        }
        else if (is_set_force_hints_on_highlight_in_menuitem())
        {
            wgui_enable_hint_highlight_in_icontext_menuitem();
        }
        else
        {
            wgui_enable_hint_highlight_in_icontext_menuitem();
        }
    }
#endif  // __MMI_UI_HINTS_IN_MENUITEM__
    wgui_fixed_list_end_add_icontext_one_item();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_create_text_menu
 * DESCRIPTION
 *  create fixed text menu
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        index of highlight
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_create_text_menu(S32 item_count, S32 highlight_item, U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_DBG_ASSERT(item_count <= MAX_FIXED_TEXT_MENU_ITEMS);
    create_fixed_text_menuitems();
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif
    associate_fixed_text_list();
    wgui_fixed_list_create_menu_common(item_count, highlight_item, flag, history_ID, history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_text_items
 * DESCRIPTION
 *  add fixed text items
 * PARAMETERS
 *  list_of_items               [IN]        List of text items.
 *  list_of_descriptions        [IN]        Descriptions of list items
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_text_items(U8 **list_of_items, U8 **list_of_descriptions)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, item_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_count = MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.n_items = 0;
    for (i = 0; i < item_count; i++)
    {
        add_fixed_text_item((UI_string_type) list_of_items[i]);
    }
    wgui_fixed_list_add_items_common(list_of_descriptions);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_text_one_item
 * DESCRIPTION
 *  add one fixed text item
 * PARAMETERS
 *  item_index              [IN]        index of item.
 *  text_of_item            [IN]        text of current item
 *  text_of_description     [IN]        Descriptions of current item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_text_one_item(S32 item_index, U8 *text_of_item, U8 *text_of_description)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_DBG_ASSERT(item_index <= MAX_FIXED_TEXT_MENU_ITEMS);
    add_location_fixed_text_item(item_index, (UI_string_type) text_of_item);       
    if (text_of_description == NULL)
    {
       wgui_pop_up_description_strings[item_index].text_strings[0] = NULL;
    }
    else
    {
        wgui_pop_up_description_strings[item_index].text_strings[0] = (UI_string_type) text_of_description;
    }
}




/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_resize_text_menu
 * DESCRIPTION
 *  resize fixed text menu 
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_resize_text_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_list(width, height);
    resize_fixed_text_menuitems_to_list_width();
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
}




// fixed icontext
/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_create_icontext_menu
 * DESCRIPTION
 *  create fixed icontext menu
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        index of highlight
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_create_icontext_menu(S32 item_count, S32 highlight_item, U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(item_count <= MAX_FIXED_ICONTEXT_MENU_ITEMS);
    create_fixed_icontext_menuitems();
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif
    associate_fixed_icontext_list();
    wgui_fixed_list_create_menu_common(item_count, highlight_item, flag, history_ID, history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_icontext_items
 * DESCRIPTION
 *  add fixed icontext items
 * PARAMETERS
 *  list_of_items               [IN]        List of text items.
 *  list_of_icons               [IN]        list of icons
 *  list_of_descriptions        [IN]        Descriptions of list items
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_icontext_items(U8 **list_of_items, U8 **list_of_icons, U8 **list_of_descriptions)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, item_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_count = MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.n_items = 0;
    for (i = 0; i < item_count; i++)
    {
        add_fixed_icontext_item((UI_string_type) list_of_items[i], list_of_icons[i]);
    }
    wgui_fixed_list_add_items_common(list_of_descriptions);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_list_begin_add_one_item
 * DESCRIPTION
 *  begin to add one item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_begin_add_one_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.n_items = 0;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_icontext_one_item
 * DESCRIPTION
 *  add one fixed icontext item
 * PARAMETERS
 *  item_index              [IN]        index of item.
 *  text_of_item            [IN]        text of current item
 *  icons                   [IN]        icon of current item
 *  text_of_description     [IN]        Descriptions of current item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_icontext_one_item(S32 item_index, U8 *text_of_item, U8 *icons, U8 *text_of_description)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(item_index <= MAX_FIXED_ICONTEXT_MENU_ITEMS);
    add_location_fixed_icontext_item(item_index, (UI_string_type) text_of_item, icons);
    if (text_of_description == NULL)
    {
       wgui_pop_up_description_strings[item_index].text_strings[0] = NULL;
    }
    else
    {
        wgui_pop_up_description_strings[item_index].text_strings[0] = (UI_string_type) text_of_description;
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_end_add_icontext_one_item
 * DESCRIPTION
 *  end to add one fixed icontext item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_end_add_icontext_one_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.highlighted_item != WGUI_LIST_INVALID_HIGHLIGHT)
    {
        set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
        fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
        set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_update_icontext_menu
 * DESCRIPTION
 *  update fixed icontext menu data
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        highlight_item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_update_icontext_menu(S32 item_count, S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_shortcut_count(item_count);
    MMI_fixed_list_menu.n_items = item_count;
    MMI_fixed_list_menu.highlighted_item = highlight_item;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_resize_icontext_menu
 * DESCRIPTION
 *  resize fixed icontext menu 
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_resize_icontext_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_list(width, height);
    resize_fixed_icontext_menuitems_to_list_width();
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
}



// fixed icontext list
/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_create_multi_icontext_menu
 * DESCRIPTION
 *  create fixed multi icontext menu
 * PARAMETERS
 *  icon_count              [IN]        icon count
 *  text_count              [IN]        text count
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        index of highlight
 *  menuitem_height         [IN]        height of menu item
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_create_multi_icontext_menu(S32 icon_count, S32 text_count, S32 item_count, S32 highlight_item, S32 menuitem_height,U32 flag, U16 history_ID, U8* history_buffer)
{
     wgui_list_create_multi_icontext_menu(GUI_MENU_TYPE_FIXED,
	   	item_count, text_count, icon_count,
	    NULL, NULL, highlight_item, menuitem_height,
	    flag, history_ID, history_buffer );
}




/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_multi_icontext_one_item
 * DESCRIPTION
 *  add one fixed multi icontext item
 * PARAMETERS
 *  item_index              [IN]        index of item.
 *  list_of_items           [IN]        list of texts
 *  list_of_icons           [IN]        list of icons
 *  text_of_description     [IN]        Descriptions of current item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_multi_icontext_one_item(S32 item_index, U8 **list_of_items, U8 **list_of_icons, U8 *text_of_description)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(item_index <= MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS);
    fixed_icontext_list_item_insert(MMI_fixed_list_menu.n_items);
    for (i = 0; i < MMI_fixed_icontext_list_menuitem.n_text_columns; i++)
    {
        add_fixed_icontext_list_item_text(item_index, i, (UI_string_type) list_of_items[i]);
    }
    for (i = 0; i < MMI_fixed_icontext_list_menuitem.n_icon_columns; i++)
    {
        add_fixed_icontext_list_item_icon(item_index, i, list_of_icons[i]);
    }
    if (text_of_description == NULL)
    {
       wgui_pop_up_description_strings[item_index].text_strings[0] = NULL;
    }
    else
    {
        wgui_pop_up_description_strings[item_index].text_strings[0] = (UI_string_type) text_of_description;
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_resize_multi_icontext_menu
 * DESCRIPTION
 *  resize fixed multi icontext menu
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_resize_multi_icontext_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_list(width, height);
    resize_fixed_icontext_list_menuitems_to_list_width();
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
}


// two state
/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_create_twostate_menu
 * DESCRIPTION
 *  create fixed twostate menu
 * PARAMETERS
 *  ON_icon                 [IN]        on icon
 *  OFF_icon                [IN]        off icon
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        index of highlight
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_create_twostate_menu(PU8 ON_icon, PU8 OFF_icon, S32 item_count, S32 highlight_item, U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(item_count <= MAX_FIXED_TWOSTATE_MENU_ITEMS);
    create_fixed_twostate_menuitems(ON_icon, OFF_icon);
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif
    associate_fixed_twostate_list();
    wgui_fixed_list_create_menu_common(item_count, highlight_item, flag, history_ID, history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_twostate_items
 * DESCRIPTION
 *  add fixed twostate items
 * PARAMETERS
 *  list_of_items               [IN]        List of text items.
 *  list_of_states               [IN]       list of states
 *  list_of_descriptions        [IN]        Descriptions of list items
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_twostate_items(U8 **list_of_items, U8 *list_of_states, U8 **list_of_descriptions)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, item_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_count = MMI_fixed_list_menu.n_items;
    MMI_fixed_list_menu.n_items = 0;
    for (i = 0; i < item_count; i++)
    {
        add_fixed_twostate_item((UI_string_type) list_of_items[i]);
        if (list_of_states[i])
        {
            select_fixed_twostate_item(i);
        }
    }
    wgui_fixed_list_add_items_common(list_of_descriptions);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_add_twostate_one_item
 * DESCRIPTION
 *  add one fixed twostate item
 * PARAMETERS
 *  item_index               [IN]        item index
 *  text_of_item             [IN]        text of current item
 *  text_of_description      [IN]        descriptions
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_add_twostate_one_item(S32 item_index, U8 *text_of_item, U8 *text_of_description)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(item_index <= MAX_FIXED_TWOSTATE_MENU_ITEMS);
    add_location_fixed_twostate_item(item_index, (UI_string_type) text_of_item);       
    if (text_of_description == NULL)
    {
       wgui_pop_up_description_strings[item_index].text_strings[0] = NULL;
    }
    else
    {
        wgui_pop_up_description_strings[item_index].text_strings[0] = (UI_string_type) text_of_description;
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_resize_twostate_menu
 * DESCRIPTION
 *  resize fixed twostate menu
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_resize_twostate_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_list(width, height);
    resize_fixed_twostate_menuitems_to_list_width();
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    set_pop_up_descriptions(1, MMI_fixed_list_menu.n_items, MMI_fixed_list_menu.highlighted_item);
}


// dynamic list
/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_list_create_icontext_menu
 * DESCRIPTION
 *  create dynamic icontext menu
 * PARAMETERS
 *  number_of_items         [IN]        number of item
 *  get_item_func           [IN]        function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        index of highlight
 *  disable_data_cache      [IN]        whether caching of dynamic data is disabled
 *  flush_data_callback     [IN]        callback function invoked before data is reloaded
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_list_create_icontext_menu(S32 number_of_items, GetItemFuncPtr get_item_func,
                                            GetHintFuncPtr get_hint_func,S32 highlighted_item,
                                            MMI_BOOL disable_data_cache,void (*flush_data_callback) (void), U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_fixed_icontext_menuitems();
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif
    associate_fixed_icontext_list();
    MMI_current_menu_type = LIST_MENU;
    
    if (disable_data_cache)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA;
    }
    init_dynamic_item_buffer(number_of_items, get_item_func, get_hint_func, flush_data_callback);
    MMI_fixed_list_menu.n_items = number_of_items;
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_DYNAMIC;
    
    register_fixed_list_highlight_handler(dynamic_list_highlight_handler);
    if (!(flag & WGUI_LIST_MENU_DISABLE_KEY_HANDLE))
    {
        register_dynamic_list_keys();
    }
#ifndef __MMI_UI_MENU_SLIM__
    wgui_title_set_menu_shortcut_number(-1);
#endif           
    if (!(flag & WGUI_LIST_MENU_DISABLE_SHORTCUT))
    {
        wgui_title_set_shortcut_count(number_of_items);  
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__		
        wgui_title_set_no_icon_shct(MMI_TRUE);
#endif
        register_dynamic_list_shortcut_handler();
    }

    if (flag & WGUI_LIST_MENU_DISABLE_SCROLLBAR_DRAG)
    {
        wgui_list_menu_disable_scrollbar_drag(MMI_TRUE);
    }

    h_flag = set_list_menu_category_history(history_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    if (get_hint_func)
    {
        if (is_set_force_icon_on_highlight_only_in_menuitem())
        {
            wgui_show_icon_only_highlight_in_icontext_menuitem();
        }
        if (is_set_force_all_hints_in_menuitem())
        {
            wgui_enable_hints_in_icontext_menuitem();
        }
        else if (is_set_force_hints_on_highlight_in_menuitem())
        {
            wgui_enable_hint_highlight_in_icontext_menuitem();
        }
        else
        {
            wgui_enable_hint_highlight_in_icontext_menuitem();
        }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        gui_block_list_effect();    /* 072305 Calvin added */
#endif 
    }
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
    if (MMI_fixed_list_menu.highlighted_item != WGUI_LIST_INVALID_HIGHLIGHT)
    {
        set_dynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);      /* ????? */
        dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
        set_dynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
    }
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    wgui_setup_pop_up_description_transition();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_list_update_icontext_menu
 * DESCRIPTION
 *  update dynamic icontext menu data
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        highlight_item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_list_update_icontext_menu(S32 item_count, S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_shortcut_count(item_count);
    init_dynamic_item_buffer(item_count, dynamic_item_buffer.load_func, dynamic_item_buffer.hint_func, UI_dummy_function);
    MMI_fixed_list_menu.n_items = item_count;
    if (highlight_item != -1)
    {
        MMI_fixed_list_menu.highlighted_item = highlight_item;
        dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }
    redraw_dynamic_list();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_list_resize_icontext_menu
 * DESCRIPTION
 *  resize dynamic icontext menu 
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_list_resize_icontext_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_list(width, height);
    if (MMI_fixed_icontext_menuitem.ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
    {
        set_dynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
    }
    dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    if (MMI_fixed_icontext_menuitem.ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
    {
        set_dynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
    }
}


MMI_BOOL wgui_list_create_multi_icontext_menu(S32 menu_style,
                                                S32 number_of_items, S32 number_of_text, S32 number_of_icon,
												GetAsyncItemFuncPtr get_item_func,
												GetAsyncHintFuncPtr get_hint_func,S32 highlighted_item,S32 menuitem_height,
												U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	{
		
       gui_asyncdynamic_list_error = 0;
	   if (flag & WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE)
       {
          MMI_fixed_icontext_list_menuitem.ext_flags |= UI_MENUITEM_SHOW_HIGHLIGHTED_HINT;
       }
	}
    create_fixed_icontext_list_menuitems(number_of_text, number_of_icon);
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif
  
    if (flag & WGUI_LIST_MENU_MULTIROW)
    {
        associate_fixed_multirow_list_list(menuitem_height);
    }
    else
    {
        associate_fixed_icontext_list_list();
    }
    resize_fixed_icontext_list_menuitems(0, menuitem_height);            

	if(menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	{
	    if (!init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func))
	    {
	        return MMI_FALSE;
	    }
	    MMI_current_menu_type = LIST_MENU;
	    MMI_fixed_list_menu.n_items = number_of_items;
	    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_ASYNCDYNAMIC;
	    MMI_fixed_list_menu.show_loading_index = -1;
	
	    if (!(flag & WGUI_LIST_MENU_DISABLE_KEY_HANDLE))
	    {
	        register_asyncdynamic_list_keys();    
	    }
	    register_fixed_list_highlight_handler(asyncdynamic_list_highlight_handler);
	    #ifndef __MMI_UI_MENU_SLIM__
	    wgui_title_set_menu_shortcut_number(-1);    
		#endif
	    if (!(flag & WGUI_LIST_MENU_DISABLE_SHORTCUT))
	    {
	        wgui_title_set_shortcut_count(number_of_items);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__			
	        wgui_title_set_no_icon_shct(MMI_TRUE);
#endif
	        register_asyncdynamic_list_shortcut_handler();       
	    }
    
		
	    if (flag & WGUI_LIST_MENU_DISABLE_SCROLLBAR_DRAG)
	    {
	        wgui_list_menu_disable_scrollbar_drag(MMI_TRUE);
	    }
	}
	else if(menu_style == GUI_MENU_TYPE_FIXED)
	{
      	if (flag & WGUI_LIST_MENU_TWO_LINE)
	    {
	        MMI_fixed_icontext_list_menuitem.ext_flags |= UI_MENUITEM_SHOW_HIGHLIGHTED_HINT;
	    }
	    
	    wgui_fixed_list_create_menu_common(number_of_items, highlighted_item, flag, history_ID, history_buffer);
	}
	
    if (menuitem_height == MMI_MULTIROW_MENUITEM_HEIGHT)
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
        {    
            MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
            MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_multirow_highlight_filler;//menuitem_multirow_highlight_without_scroll_filler
            MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
        }
    }
    else if (menuitem_height == (MMI_MENUITEM_HEIGHT << 1))
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
        {    
            MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_two_line_highlight_filler;
            MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_two_line_highlight_filler;//menuitem_two_line_highlight_without_scroll_filler
            MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_two_line_highlight_filler;
        }
    }
    else if ((menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)&&(menuitem_height == MMI_MENUITEM_THICK_WITH_TAB_HEIGHT))
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
        {    
            MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
            MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;//menuitem_thick_with_tab_highlight_without_scroll_filler
            MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
        }
    }

#if defined(__MMI_MAINLCD_320X480__)  || defined(__MMI_UI_HINTS_IN_MENUITEM__)
    if (number_of_text == 2)
    {
        MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->list_normal_text_color;//two_line_first_line_text_color
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.normal_text_colors[1] = *current_MMI_theme->two_line_second_line_text_color;
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[1] = *current_MMI_theme->two_line_second_line_highlight_text_color;
        MMI_fixed_icontext_list_menuitem.selected_text_colors[1] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    }
    else if (number_of_text == 3)
    {
        MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->list_normal_text_color;//multirow_first_line_text_color
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->list_selected_text_color;//multirow_first_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->list_selected_text_color;//multirow_first_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.normal_text_colors[1] = *current_MMI_theme->two_line_second_line_text_color;//multirow_second_line_text_color
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[1] = *current_MMI_theme->two_line_second_line_highlight_text_color;//multirow_second_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.selected_text_colors[1] = *current_MMI_theme->two_line_second_line_highlight_text_color;//multirow_second_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.normal_text_colors[2] = *current_MMI_theme->multirow_third_line_text_color;
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = *current_MMI_theme->multirow_third_line_highlight_text_color;
        MMI_fixed_icontext_list_menuitem.selected_text_colors[2] = *current_MMI_theme->multirow_third_line_highlight_text_color;
    }
#endif
   if(menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
   	{
	    h_flag = set_list_menu_category_history(history_ID, history_buffer);
	    if (!h_flag)
	    {
	        MMI_fixed_list_menu.highlighted_item = highlighted_item;
	    }
	    if (MMI_fixed_list_menu.highlighted_item != WGUI_LIST_INVALID_HIGHLIGHT)
	    {
	        set_asyncdynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
	        asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
	        set_asyncdynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
	    }
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
	    wgui_setup_pop_up_description_transition();
#endif  
   	}
   return MMI_TRUE;
}

// asyncdynamic list
/*****************************************************************************
 * FUNCTION
 *  wgui_async_list_create_multi_icontext_menu
 * DESCRIPTION
 *  create asynchronism multi icontext menu
 * PARAMETERS
 *  number_of_items         [IN]        number of items
 *  number_of_text          [IN]        number of text columns
 *  number_of_icon          [IN]        number of icon columns
 *  get_item_func           [IN]        function pointer to get next displayed items
 *  get_hint_func           [IN]        function pointer to get next displayed hint data
 *  highlighted_item        [IN]        index of highlight
 *  menuitem_height         [IN]        height of menu item
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_async_list_create_multi_icontext_menu(S32 number_of_items, S32 number_of_text, S32 number_of_icon,
                                            GetAsyncItemFuncPtr get_item_func,
                                            GetAsyncHintFuncPtr get_hint_func,S32 highlighted_item,S32 menuitem_height,
                                            U32 flag, U16 history_ID, U8* history_buffer)
{
   return wgui_list_create_multi_icontext_menu(GUI_MENU_TYPE_ASYNCDYNAMIC,
		   	number_of_items, number_of_text, number_of_icon,
		   	get_item_func, get_hint_func, highlighted_item, menuitem_height,
		    flag, history_ID, history_buffer );
}


/*****************************************************************************
 * FUNCTION
 *  wgui_async_list_update_multi_icontext_menu
 * DESCRIPTION
 *  update asynchronism multi icontext menu data
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        highlight_item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_async_list_update_multi_icontext_menu(S32 item_count, S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_shortcut_count(item_count);
    init_asyncdynamic_item_buffer(item_count, asyncdynamic_item_buffer.load_func, asyncdynamic_item_buffer.hint_func);
    MMI_fixed_list_menu.n_items = item_count;
    if (highlight_item != -1)
    {
        MMI_fixed_list_menu.highlighted_item = highlight_item;
        asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }
    redraw_asyncdynamic_list();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_async_list_resize_multi_icontext_menu
 * DESCRIPTION
 *  resize asynchronism multi icontext menu
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_async_list_resize_multi_icontext_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_list(width, height);
    if (MMI_fixed_icontext_list_menuitem.ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
    {
        set_asyncdynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
    }
    asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    if (MMI_fixed_icontext_list_menuitem.ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
    {
        set_asyncdynamic_pop_up_descriptions(MMI_fixed_list_menu.highlighted_item);
    }
}

// fixed matrix
/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_matrix_create_menu
 * DESCRIPTION
 *  create fixed matrix menu
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        index of highlight
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_matrix_create_menu(S32 item_count, S32 highlight_item, U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(item_count <= MAX_FIXED_ICONTEXT_MENU_ITEMS);
    create_fixed_icontext_menuitems();
    associate_fixed_icontext_matrix();
    MMI_current_menu_type = MATRIX_MENU;
    register_fixed_matrix_highlight_handler(standard_animated_matrix_highlight_handler);
    if (!(flag & WGUI_LIST_MENU_DISABLE_KEY_HANDLE))
    {
        register_fixed_matrix_loop_keys();
    }    
    MMI_fixed_matrix_menu.n_items = item_count;
#ifndef __MMI_UI_MENU_SLIM__
    wgui_title_set_menu_shortcut_number(-1);
#endif    
    if (!(flag & WGUI_LIST_MENU_DISABLE_SHORTCUT))
    {
        wgui_title_set_shortcut_count(item_count);
      //  register_hide_menu_shortcut(gui_redraw_menu_shortcut);
		register_fixed_matrix_shortcut_handler();
    }
    h_flag = set_matrix_menu_category_history(history_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_matrix_menu.highlighted_item = highlight_item;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_matrix_add_items
 * DESCRIPTION
 *  add fixed matrix items
 * PARAMETERS
 *  list_of_items               [IN]        List of text items.
 *  list_of_icons               [IN]        list of icons
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_matrix_add_items(U8 **list_of_items, U8 **list_of_icons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, item_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_count = MMI_fixed_matrix_menu.n_items;
    MMI_fixed_matrix_menu.n_items = 0;
    for (i = 0; i < item_count; i++)
    {
        add_fixed_icontext_item((UI_string_type) list_of_items[i], list_of_icons[i]);
    }
    if (MMI_fixed_matrix_menu.highlighted_item != WGUI_LIST_INVALID_HIGHLIGHT)
    {
        fixed_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_matrix_begin_add_one_item
 * DESCRIPTION
 *  begin to add one fixed matrix item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_matrix_begin_add_one_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.n_items = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_matrix_end_add_one_item
 * DESCRIPTION
 *  end to add one fixed matrix item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_matrix_end_add_one_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_matrix_menu.highlighted_item != WGUI_LIST_INVALID_HIGHLIGHT)
    {
        fixed_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_matrix_update_menu
 * DESCRIPTION
 *  update fixed matrix menu data
 * PARAMETERS
 *  item_count              [IN]        item count
 *  highlight_item          [IN]        highlight_item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_matrix_update_menu(S32 item_count, S32 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_shortcut_count(item_count);
    MMI_fixed_matrix_menu.n_items = item_count;
    MMI_fixed_matrix_menu.highlighted_item = highlight_item;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_matrix_resize_menu
 * DESCRIPTION
 *  resize fixed matrix menu 
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_matrix_resize_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_matrix(width, height);
    resize_fixed_icontext_menuitems_to_list_width();
    fixed_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
}

// LIST
/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_hide_function
* DESCRIPTION
*  register hide function
* PARAMETERS
*  f       [IN]        New hide function
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_register_hide_function(void(*f)(S32 x1, S32 y1, S32 x2, S32 y2))
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_list_hide_menu = f;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_set_active_layer
* DESCRIPTION
*  set active layer layer
* PARAMETERS
*  active_layer             [IN]        active layer
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_set_active_layer(gdi_handle active_layer)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (active_layer)
    {
        MMI_fixed_list_menu.act_layer_handle = active_layer;
        gui_vertical_scrollbar_set_target_layer(&MMI_fixed_list_menu.vbar,active_layer);
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_get_active_layer
* DESCRIPTION
*  get active layer layer
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
gdi_handle wgui_fixed_list_get_active_layer(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_fixed_list_menu.act_layer_handle;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_set_alpha_blending_layer
* DESCRIPTION
*  set active alpha blend layer
* PARAMETERS
*  alpha_blend_layer        [IN]        alpha blending layer
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_set_alpha_blending_layer(gdi_handle alpha_blend_layer)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alpha_blend_layer)
    {
        MMI_fixed_list_menu.alpha_blend_layer_handle = alpha_blend_layer;
    }    
}

/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_get_alpha_blending_layer
* DESCRIPTION
*  get active alpha blend layer
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
gdi_handle wgui_fixed_list_get_alpha_blending_layer(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_fixed_list_menu.alpha_blend_layer_handle;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_get_underline_function
* DESCRIPTION
*  register get underline function
* PARAMETERS
* get_underline_func            new function to get index
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_register_get_underline_function(GetUnderLineFuncPtr get_underline_func)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_CAT203_SUPPORT__    
    g_gui_list_get_underline = get_underline_func;
#endif
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_pre_key_handler
* DESCRIPTION
*  register pre key handler
* PARAMETERS
* pre_key_handler            pre key handler
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_register_pre_key_handler(PreKeyHandler pre_key_handler)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_list_pre_key_handler = pre_key_handler;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_set_data_layout
* DESCRIPTION
*  set layout of data
* PARAMETERS
* f                     font of data
* gap                   gap of data
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_set_data_layout(UI_font_type f, S32 gap)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_list_data_font = f;
    g_gui_list_data_gap = gap;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_set_text_color
* DESCRIPTION
*  set text color of menu item
* PARAMETERS
* c                     color of menu item
* RETURNS
*  void
*****************************************************************************/
void wgui_fixed_list_set_text_color(color c)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_OP01_DCD__
    g_gui_list_text_color = c;
#endif  // __MMI_OP01_DCD__
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_get_style
* DESCRIPTION
*  get the style of list
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
gui_menu_type_enum wgui_fixed_list_get_style(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_fixed_list_menu.menu_style;
} 

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))

/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_skipping_handler
* DESCRIPTION
*  register skipping handler
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
void wgui_fixed_list_register_skipping_handler(void(*pre_handler)(void), void(*post_handler)(void))
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_list_skipping_pre_handler = pre_handler;
    g_gui_list_skipping_post_handler = post_handler;
}
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */
/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_get_flags_handler
* DESCRIPTION
*  register skipping handler
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
void wgui_fixed_list_register_get_flags_handler(GetMenuitemFlags get_flags_handler)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_list_get_menuitem_flags = get_flags_handler;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_display_callback
* DESCRIPTION
*  register asyncdynamic list display callback handler
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
void wgui_fixed_list_register_display_callback(AsyncDisplayCallback async_display_callback)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_list_display_callback = async_display_callback;
}


/*****************************************************************************
* FUNCTION
*  wgui_fixed_list_register_display_callback
* DESCRIPTION
*  register asyncdynamic list display callback handler
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
void wgui_fixed_list_register_indicator_display_callback(void (*f)(S32 index, S32 x, S32 y))
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_indicator_display_callback = f;
}


/*****************************************************************************
* FUNCTION
*  wgui_list_menu_shortcut_executer
* DESCRIPTION
*  execute the highlighted handler
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
void wgui_list_menu_shortcut_executer(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags, flags_ext;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index >= 0 && item_index < MMI_fixed_list_menu.n_items)
    {
        MMI_fixed_list_menu.item_get_flag_function(
        MMI_fixed_list_menu.items[item_index],  
        MMI_fixed_list_menu.common_item_data,
        item_index,  
        &flags, 
        &flags_ext);

        if ((flags & UI_MENUITEM_STATE_DISABLED) || g_list_goto_disable_item)
        {
            g_list_goto_disable_item = MMI_FALSE;
            return;
        }

#if defined(__MMI_TOUCH_SCREEN__)    
        if (MMI_fixed_list_menu.tap_callback_funtion == NULL)
        {
            execute_left_softkey_function(KEY_EVENT_UP);
        }
        else
        {
            MMI_fixed_list_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, item_index);
        }
#else   /* __MMI_TOUCH_SCREEN__ */
        execute_left_softkey_function(KEY_EVENT_UP);
#endif  /* __MMI_TOUCH_SCREEN__ */    
    }
}


#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
/*****************************************************************************
* FUNCTION
*  wgui_fixed_matrix_main_menu_hide_current_highlight
* DESCRIPTION
*  Hide current highlight item for scaling effect in matrix main menu.
* PARAMETERS
* void
* RETURNS
* menu style
*****************************************************************************/
static void wgui_fixed_matrix_main_menu_hide_current_highlight(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer[4];
    S32 current_highlight, last_highlight;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);
    gdi_layer_push_and_set_active(layer[0]);
    current_highlight = MMI_fixed_matrix_menu.highlighted_item - MMI_fixed_matrix_menu.first_displayed_row * MMI_fixed_matrix_menu.displayed_columns;
    last_highlight = MMI_fixed_matrix_menu.last_highlighted_item - MMI_fixed_matrix_menu.first_displayed_row * MMI_fixed_matrix_menu.displayed_columns;
	//gdi_layer_push_clip();
    gdi_layer_push_and_set_clip(
        matrix_mm_rect[current_highlight].rect.x,
        matrix_mm_rect[current_highlight].rect.y,
        matrix_mm_rect[current_highlight].rect.x + matrix_mm_rect[current_highlight].rect.width - 1,
        matrix_mm_rect[current_highlight].rect.y + matrix_mm_rect[current_highlight].rect.height - 1);
    //gdi_image_draw(0, 0, current_MMI_theme->main_menu_bkg_filler->b);//dm_draw_scr_bg_image();
    gui_draw_filled_area(0,0,LCD_WIDTH,LCD_HEIGHT,current_MMI_theme->main_menu_bkg_filler);
    gdi_layer_set_clip(
        matrix_mm_rect[last_highlight].rect.x,
        matrix_mm_rect[last_highlight].rect.y,
        matrix_mm_rect[last_highlight].rect.x + matrix_mm_rect[last_highlight].rect.width - 1,
        matrix_mm_rect[last_highlight].rect.y + matrix_mm_rect[last_highlight].rect.height - 1);
    gdi_image_draw(
        matrix_mm_rect[last_highlight].rect.x,
        matrix_mm_rect[last_highlight].rect.y,
        matrix_mm_rect[last_highlight].image);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */

#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_matrix_create_icontext_menu
 * DESCRIPTION
 *  create dynamic matrix menu
 * PARAMETERS
 *  number_of_items         [IN]        number of item
 *  get_item_func           [IN]        function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        index of highlight
 *  disable_data_cache      [IN]        whether caching of dynamic data is disabled
 *  flush_data_callback     [IN]        callback function invoked before data is reloaded
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_matrix_create_icontext_menu(S32 number_of_items, GetItemFuncPtr get_item_func,
                                            GetHintFuncPtr get_hint_func,S32 highlighted_item,
                                            MMI_BOOL disable_data_cache,void (*flush_data_callback) (void), U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(number_of_items <= MAX_FIXED_ICONTEXT_MENU_ITEMS);
    create_fixed_icontext_menuitems();
    associate_fixed_icontext_matrix();
    MMI_current_menu_type = MATRIX_MENU;
    
    if (disable_data_cache)
    {
        MMI_fixed_matrix_menu.flags |= UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA;
    }
    init_dynamic_item_buffer(number_of_items, get_item_func, get_hint_func, flush_data_callback);
    MMI_fixed_matrix_menu.n_items = number_of_items;
    if (number_of_items == 0)
    {
        return;
    }
    register_fixed_matrix_highlight_handler(dynamic_matrix_highlight_handler);
    MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_VERTICAL_LOOP;
    if (!(flag & WGUI_LIST_MENU_DISABLE_KEY_HANDLE))
    {
        register_dynamic_matrix_loop_keys();
    }
#ifndef __MMI_UI_MENU_SLIM__
    wgui_title_set_menu_shortcut_number(-1);    
#endif
    if (!(flag & WGUI_LIST_MENU_DISABLE_SHORTCUT))
    {
        wgui_title_set_shortcut_count(number_of_items);    
        wgui_title_set_no_icon_shct(MMI_FALSE);
        register_dynamic_matrix_shortcut_handler();
    }

    h_flag = set_matrix_menu_category_history(history_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_matrix_menu.highlighted_item = highlighted_item;
    }

    if (MMI_fixed_matrix_menu.highlighted_item != WGUI_LIST_INVALID_HIGHLIGHT)
    {
        dynamic_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_matrix_resize_icontext_menu
 * DESCRIPTION
 *  resize dynamic icontext menu 
 * PARAMETERS
 *  width                [in]        width
 *  height               [in]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_matrix_resize_icontext_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_matrix(width, height);
    dynamic_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
}
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__

/*****************************************************************************
 * FUNCTION
 *  wgui_list_set_slow_data_mode
 * DESCRIPTION
 *  Set Slow data read mode
 * PARAMETERS
 *  slow_mode      [IN]        Use slow mode or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_set_slow_data_mode(MMI_BOOL slow_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_list_menu_slow_data_mode = slow_mode;
    
}


/*****************************************************************************
* FUNCTION
*  wgui_list_get_slow_data_mode
* DESCRIPTION
*  Get Slow data read mode
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL Use slow mode or not
*****************************************************************************/
MMI_BOOL wgui_list_get_slow_data_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_list_menu_slow_data_mode;
    
}


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/* Asyncdynamic matrix menu */

/*****************************************************************************
 * FUNCTION
 *  wgui_asyncdynamic_matrix_create_icontext_menu
 * DESCRIPTION
 *  Create asyncdynamic matrix menu
 * PARAMETERS
 *  number_of_items         [IN]        number of item
 *  get_item_func           [IN]        function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        index of highlight
 *  disable_data_cache      [IN]        whether caching of dynamic data is disabled
 *  flush_data_callback     [IN]        callback function invoked before data is reloaded
 *  flag                    [IN]        flag for list create(WGUI_LIST_MENU_DISABLE_SHORTCUT to disabled shortcut)
 *  history_ID              [IN]        the ID used by category screens
 *  history_buffer          [IN]        the buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_asyncdynamic_matrix_create_icontext_list_menu(S32 number_of_items, S32 number_of_text, S32 number_of_icon,
                                            GetAsyncItemFuncPtr get_item_func,
                                            GetAsyncHintFuncPtr get_hint_func,S32 highlighted_item,S32 menuitem_height,
                                            U32 flag, U16 history_ID, U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_asyncdynamic_list_error = 0;
    create_fixed_icontext_list_menuitems(number_of_text, number_of_icon);
    associate_fixed_icontext_list_matrix();
    
    if (!init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func))
    {
        return MMI_FALSE;
    }

    MMI_current_menu_type = MATRIX_MENU;
    MMI_fixed_matrix_menu.n_items = number_of_items;
    
    register_fixed_matrix_highlight_handler(asyncdynamic_matrix_highlight_handler);
    MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_VERTICAL_LOOP;
    if (!(flag & WGUI_LIST_MENU_DISABLE_KEY_HANDLE))
    {
        register_asyncdynamic_matrix_loop_keys();
    }
#ifndef __MMI_UI_MENU_SLIM__
    wgui_title_set_menu_shortcut_number(-1); 
#endif
    if (!(flag & WGUI_LIST_MENU_DISABLE_SHORTCUT))
    {  
        wgui_title_set_shortcut_count(number_of_items);    
        wgui_title_set_no_icon_shct(MMI_FALSE);
        register_asyncdynamic_matrix_shortcut_handler();
    }

    h_flag = set_matrix_menu_category_history(history_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_matrix_menu.highlighted_item = highlighted_item;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_asyncdynamic_matrix_resize_icontext_menu
 * DESCRIPTION
 *  resize asyncdynamic icontext matrix menu 
 * PARAMETERS
 *  width                [IN]        width
 *  height               [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_asyncdynamic_matrix_resize_icontext_list_menu(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize_fixed_matrix(width, height);
    asyncdynamic_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */



/*****************************************************************************
 * FUNCTION
 *  wgui_list_menu_locate_highlighted_item
 * DESCRIPTION
 *  Just locate the highlighted item, re-calculate the layout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_menu_locate_highlighted_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_UI_HINTS_IN_MENUITEM__    

   if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
	   gui_fixed_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
#endif  /* __MMI_UI_HINTS_IN_MENUITEM__ */    

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_list_menu_enable_scrollbar_drag
 * DESCRIPTION
 *  enable or disable scrollbar drag operation in list menu
 * PARAMETERS
 *  enable      [IN]    whether disable navigation list by drag scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_menu_disable_scrollbar_drag(MMI_BOOL disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_vertical_scrollbar_disable_drag(&MMI_fixed_list_menu.vbar, disable);
    if (disable)
    {        
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR_DRAG;
    }
    else
    {        
        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_SCROLLBAR_DRAG;
    }
}
