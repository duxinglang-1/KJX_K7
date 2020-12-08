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
*  wgui_dynamic_menus.c
*
* Project:
* --------
*   PlutoMMI
*
* Description:
* ------------
*   In order to use limited memory (size decided in compile-time) to load unlimited items (size decide in run-time) 
*   to a category screen, a modification in MMI for dynamic item loading is required as the following.
*
* Author:
* -------
 * -------
*
*******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui_fixed_menuitems.h"
#include "gui_dynamic_menus.h"
#include "ProfilingEngine.h"
#include "gui_typedef.h"
#include "gui_config.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "gui_fixed_menuitems.h"
#include "gui_effect_oem.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "wgui_fixed_menus.h"
#include "gui.h"
#include "wgui.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "gui_fixed_menus.h"
#include "gdi_const.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "gui_scrollbars.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gui_menu_post_oem.h"
#include "wgui_dynamic_menuitems.h"
#include "Unicodexdcl.h"
#include "lcd_sw_inc.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
extern S32 wgui_fixed_list_menu_frame_counter;
#endif
extern MMI_BOOL g_list_goto_disable_item;

extern void dummy_highlight_handler(S32 item_index);
extern void (*_MMI_hide_fixed_list_menu) (void);
extern void wgui_display_fixed_text_list_pop_up_description(void);
extern void wgui_display_dynamic_text_list_pop_up_description(void);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  reset_dynamic_list
 * DESCRIPTION
 *  Reset the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_dynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (MMI_current_menu_type == LIST_MENU)
        gui_ssp_pen_up_dummy();
#endif

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    gui_cancel_timer(wgui_dynamic_list_menu_end_frame);
    wgui_fixed_list_menu_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
    normal_fixed_list();

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    gui_reset_transparent_source_layer();
#endif 
#ifndef __MMI_UI_MENU_SLIM__
    gui_cancel_timer(gui_callback_highlighter_text_filler);
#endif
    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
    MMI_fixed_list_menu.highlighted_item = -1;
    MMI_fixed_list_menu.alpha_blend_layer_handle = GDI_NULL_HANDLE;    
    wgui_text_menuitem_reset_scrolling();
    wgui_fixed_list_register_get_underline_function(NULL);
    wgui_fixed_list_register_pre_key_handler(NULL);
    wgui_fixed_list_set_data_layout(NULL, 0);
    wgui_fixed_list_register_hide_function(NULL);
    wgui_fixed_list_register_get_flags_handler(NULL);
    register_fixed_list_unhighlight_handler(UI_dummy_function_s32);
    gui_vertical_scrollbar_reset_target_layer(&MMI_fixed_list_menu.vbar);
    gui_vertical_scrollbar_reset_alpha_blend_layer(&MMI_fixed_list_menu.vbar);
    gui_vertical_scrollbar_enable_clear_background(&MMI_fixed_list_menu.vbar, MMI_TRUE);
    wgui_list_set_slow_data_mode(MMI_FALSE);

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif 
    wgui_list_menu_disable_access_by_shortcut();
    wgui_effect_register_query_enable_draw_last_frame(NULL);
    wgui_list_menu_disable_scrollbar_drag(MMI_FALSE);

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_ssp_reset_static_layer();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  show_dynamic_list
 * DESCRIPTION
 *  Show the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_dynamic_list(void)
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
#endif 
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_cancel_timer(gui_ssp_update_frame);
    if (gui_screen_smooth_scrolling_in_freerun())
    {
        gui_ssp_pen_up_dummy();
        gui_ssp_sync_list_menu_display();
    }
#endif
#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
    wgui_two_line_stop_scroller();
#endif

    /* call pre-display callback */
    if (MMI_fixed_list_menu.pre_display_function)
    {
        MMI_fixed_list_menu.pre_display_function();
    }
    
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
    {
        _MMI_hide_fixed_list_menu();
    }
    
    gui_show_dynamic_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS	
    wgui_display_dynamic_text_list_pop_up_description();
#endif
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


/*****************************************************************************
 * FUNCTION
 *  redraw_dynamic_list
 * DESCRIPTION
 *  Redraw the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_dynamic_list(void)
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
    
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    if (wgui_fixed_list_menu_frame_counter > 0)
    {
        wgui_fixed_list_menu_frame_counter++;
        gui_show_dynamic_list_menu_no_draw(&MMI_fixed_list_menu);
    }
    else
    {
        wgui_fixed_list_menu_frame_counter = 1;
        gui_show_dynamic_list_menu_no_draw(&MMI_fixed_list_menu);
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_dynamic_list_menu_end_frame);
    }
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
    show_dynamic_list();
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 

    gdi_layer_pop_and_restore_active();
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
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
#else 
#ifndef __MMI_UI_MENU_SLIM__
/* under construction !*/
#endif
#endif 
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
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
#endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_goto_item_common(GUI_FIXED_LIST_PREV_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_goto_item_common(GUI_FIXED_LIST_NEXT_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    if (item_index == MMI_fixed_list_menu.highlighted_item &&
        (MMI_fixed_list_menu.highlighted_item >= MMI_fixed_list_menu.first_displayed_item &&
        MMI_fixed_list_menu.highlighted_item <= MMI_fixed_list_menu.last_displayed_item))
    {
        return;
    }

    MMI_fixed_list_menu.item_get_flag_function(
        NULL,  
        NULL,
        item_index,  
        &flags, 
        &flags_ext);

    g_list_goto_disable_item = MMI_FALSE;
    if (flags & UI_MENUITEM_STATE_DISABLED)
    {
        g_list_goto_disable_item = MMI_TRUE;
        return;
    }

#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif	
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To handle the redraw of hilighter if item index is greater then no of items */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        gdi_layer_pop_and_restore_active();
		#ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(act_lcd);
		#endif
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    redraw_dynamic_list();

    gdi_layer_pop_and_restore_active();
	#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);  
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_shortcut_handle
 * DESCRIPTION
 *  the shortcut handle of dynamic list menu
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_shortcut_handle(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


        dynamic_list_goto_item(item_index);
}


#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
/*****************************************************************************
 * FUNCTION
 *  dynamic_list_shortcut_handle_with_SSK
 * DESCRIPTION
 *  Go to the specified item with smooth scrolling effect.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
*****************************************************************************/
void dynamic_list_shortcut_handle_with_SSK(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;
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
        NULL,
        NULL,
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
        /* goto the item with smooth scrolling effect */
		#ifdef __MMI_SUBLCD__
        gdi_lcd_get_active(&act_lcd);
        gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
		#endif
        gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        /* To handle the redraw of hilighter if item index is greater then no of items */
        if (item_index >= MMI_fixed_list_menu.n_items)
        {
            gdi_layer_pop_and_restore_active();
			#ifdef __MMI_SUBLCD__
            gdi_lcd_set_active(act_lcd);
			#endif
            return;
        }
        gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

        old_highlighed_item = MMI_fixed_list_menu.highlighted_item;
        gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

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
                    /* for scroll down, the next menu item has already load in buffer */
                    if ((new_highlighted_item == MMI_fixed_list_menu.last_displayed_item) && 
                        (new_highlighted_item < (MMI_fixed_list_menu.n_items - 1)))
                    {
                        MMI_fixed_list_menu.first_displayed_item += 1;
                        MMI_fixed_list_menu.last_displayed_item += 1;
                    }
                }
            }
        }

        redraw_dynamic_list();

        gdi_layer_pop_and_restore_active();
		#ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(act_lcd); 
		#endif
    }
}
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the dynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_item_no_redraw(S32 item_index)
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
    set_dynamic_pop_up_descriptions(item_index);
	#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
	#endif
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
    if (item_index < 0)
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
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    gdi_layer_pop_and_restore_active();
	#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);           
	#endif
    set_dynamic_pop_up_descriptions(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
    register_menu_shortcut_handler(dynamic_list_shortcut_handle_with_SSK);
#else
    register_menu_shortcut_handler(dynamic_list_shortcut_handle);
#endif
    
#ifdef __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT)
        register_menu_shortcut_selected(wgui_list_menu_shortcut_executer);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the dynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_keyboard_key_handler();
    SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
}

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))


/*****************************************************************************
 * FUNCTION
 *  wgui_dynamic_list_menu_end_frame
 * DESCRIPTION
 *  Show the dynamic list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dynamic_list_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        #ifdef __MMI_SUBLCD__
        gdi_lcd_get_active(&act_lcd);
        gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
		#endif
        gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_hide_animations();

        gui_lock_double_buffer();
        gui_show_dynamic_list_menu(&MMI_fixed_list_menu);
        gui_unlock_double_buffer();
        
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS        
        wgui_display_dynamic_text_list_pop_up_description();
#endif
        gdi_layer_blt_previous(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

        gdi_layer_pop_and_restore_active();
		#ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(act_lcd);        
        #endif 

        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_dynamic_list_menu_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  DynamicListIncreaseItem
 * DESCRIPTION
 *  Increase the total number of dynamic item.
 * PARAMETERS
 *  steps       [IN]        Number of items to be increased
 * RETURNS
 *  void
 *****************************************************************************/
void DynamicListIncreaseItem(S16 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_buffer.n_total_items = dynamic_item_buffer.n_total_items + steps;
    MMI_fixed_list_menu.n_items = MMI_fixed_list_menu.n_items + steps;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicListGetItems
 * DESCRIPTION
 *  Return total number of dynamic items and the requested item text from the dynamic buffer.
 *  The caller must take care of the validity of the specified item in the buffer.
 * PARAMETERS
 *  string          [OUT]       Requested item text
 *  item_index      [IN]        Index of the requested item
 * RETURNS
 *  total number of dynamic items
 *****************************************************************************/
S32 DynamicListGetItems(U8 *string, U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy((CHAR *) string, (CHAR *) MMI_fixed_icontext_menuitems[(item_index) % 32].item_text);
    }

    return MMI_fixed_list_menu.n_items;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicListGetHighlightedItem
 * DESCRIPTION
 *  Return the index and text of the highlighted item.
 * PARAMETERS
 *  string      [OUT]       Highlighted item text
 * RETURNS
 *  Highlighted item index
 *****************************************************************************/
S32 DynamicListGetHighlightedItem(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy(
            (CHAR *) string,
            (CHAR *) MMI_fixed_icontext_menuitems[(MMI_fixed_list_menu.highlighted_item) % 32].item_text);
    }

    return MMI_fixed_list_menu.highlighted_item;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicGetFirstDisplayedItem
 * DESCRIPTION
 *  Return the index and text of first displayed item.
 * PARAMETERS
 *  string      [OUT]       First displayed item text
 * RETURNS
 *  First displayed item index
 *****************************************************************************/
S32 DynamicGetFirstDisplayedItem(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy(
            (CHAR *) string,
            (CHAR *) MMI_fixed_icontext_menuitems[(MMI_fixed_list_menu.first_displayed_item) % 32].item_text);
    }

    return MMI_fixed_list_menu.first_displayed_item;
}


#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  show_dynamic_matrix
 * DESCRIPTION
 *  Show the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_dynamic_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_dynamic_matrix_menu(&MMI_fixed_matrix_menu);
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(
        MMI_fixed_matrix_menu.x,
        MMI_fixed_matrix_menu.y,
        MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
        LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  redraw_dynamic_matrix
 * DESCRIPTION
 *  Redraw the dynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_dynamic_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ANI_BG_LIST_MENU)
    {
        return;
    }
    
    #ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd); 
    show_dynamic_matrix();
    gdi_lcd_set_active(act_lcd);  
	#else
	show_dynamic_matrix();
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  reset_dynamic_matrix
 * DESCRIPTION
 *  Reset the dynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_dynamic_matrix(void)
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
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_matrix_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_first_displayed_row, last_highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_matrix_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_matrix_menu.n_items == 1) && (MMI_fixed_matrix_menu.highlighted_item == 0))
    {
        return;
    }

    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_dynamic_matrix_menu_goto_previous_item(&MMI_fixed_matrix_menu);
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_dynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
    else
    {
        redraw_dynamic_matrix();  
    }          
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_matrix_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_first_displayed_row, last_highlight_item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_matrix_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_matrix_menu.n_items == 1) && (MMI_fixed_matrix_menu.highlighted_item == 0))
    {
        return;
    }

    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_dynamic_matrix_menu_goto_next_item(&MMI_fixed_matrix_menu);
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_dynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
    else
    {
        redraw_dynamic_matrix();  
    }    
}



/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_goto_previous_row
 * DESCRIPTION
 *  Go to the previous row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_matrix_goto_previous_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_first_displayed_row, last_highlight_item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_dynamic_matrix_menu_goto_previous_row(&MMI_fixed_matrix_menu);
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_dynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
    else
    {
        redraw_dynamic_matrix();  
    }    

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
void dynamic_matrix_goto_next_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_first_displayed_row, last_highlight_item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_dynamic_matrix_menu_goto_next_row(&MMI_fixed_matrix_menu);
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_dynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
    else
    {
        redraw_dynamic_matrix();  
    }    

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_matrix_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_first_displayed_row, last_highlight_item;
    
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
    
    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_dynamic_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_dynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
    else
    {
        redraw_dynamic_matrix();  
    }    
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the fixed matrix.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_matrix_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.highlighted_item = -1;
    gui_dynamic_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_loop_keys
 * DESCRIPTION
 *  register key handlers of dynamic matrix menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_matrix_loop_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(dynamic_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_matrix_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_matrix_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(dynamic_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_matrix_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_matrix_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(dynamic_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_matrix_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the dynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_matrix_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(dynamic_matrix_goto_item);
}
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__


