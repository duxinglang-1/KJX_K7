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
*  wgui_asyncdynamic_menus.c
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
#include "CustMenuRes.h"
#include "wgui_fixed_menus.h"
#include "wgui_asyncdynamic_menus.h"
#include "gui_asyncdynamic_menus.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "MMIDataType.h"
#include "gui_config.h"
#include "MMI_features.h"
#include "gui_fixed_menuitems.h"
#include "gui_effect_oem.h"
#include "CustDataProts.h"
#include "gui.h"
#include "wgui.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "gui_fixed_menus.h"
#include "gdi_const.h"
#include "wgui_include.h"
#include "gui_scrollbars.h"
#include "kal_general_types.h"
#include "gui_menu_post_oem.h"
#include "gdi_include.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "ProfilingEngine.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern void dummy_highlight_handler(S32 item_index);
extern void (*_MMI_hide_fixed_list_menu) (void);
extern void wgui_display_fixed_text_list_pop_up_description(void);
extern void wgui_display_asyncdynamic_text_list_pop_up_description(void);
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
static void asyncdynamic_matrix_goto_x(S32 goto_type, S32 item_index);
#endif
extern S32 gui_asyncdynamic_list_error;
extern MMI_BOOL g_list_goto_disable_item;

#if( UI_ENABLE_FRAME_SKIPPING )
extern S32 wgui_fixed_list_menu_frame_counter;
#endif 

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  reset_asyncdynamic_list
 * DESCRIPTION
 *  Reset the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	/* clear asyncdynamic list pre-display handler */
    register_asyncdynamic_list_pre_display_handler(NULL);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (MMI_current_menu_type == LIST_MENU)
        gui_ssp_pen_up_dummy();
#endif

#if( UI_ENABLE_FRAME_SKIPPING )
    if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
       gui_cancel_timer(wgui_asyncdynamic_list_menu_end_frame);
	   wgui_fixed_list_menu_frame_counter = 0;
    }
	else
	{
		#if(ENABLE_LIST_MENU_FRAME_SKIPPING)
          gui_cancel_timer(wgui_fixed_list_menu_end_frame);
           wgui_fixed_list_menu_frame_counter = 0; 
		#endif/*end ENABLE_LIST_MENU_FRAME_SKIPPING*/
	}
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
    normal_fixed_list();
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)      /* 072505 Calvin modified */
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
	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	{
      ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
      ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
      ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_REPEAT);
      ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_REPEAT);
	}

    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
    MMI_fixed_list_menu.highlighted_item = -1;
    MMI_fixed_list_menu.alpha_blend_layer_handle = GDI_NULL_HANDLE;    
	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	//{
       MMI_fixed_list_menu.show_loading_index = -1;
	//}
    wgui_text_menuitem_reset_scrolling();

	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
	//{
	   gui_fixed_icontext_list_menuitem_stop_scroll();
	//}
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

    if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
       wgui_async_list_register_update_callback(NULL);
    }
	else if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
	{
	   wgui_fixed_list_register_display_callback(NULL);
       wgui_fixed_list_register_indicator_display_callback(NULL);
       gui_resize_vertical_scrollbar(&MMI_fixed_list_menu.vbar, MMI_fixed_list_menu.vbar.width, MMI_fixed_list_menu.height);

       #ifdef __MMI_OP11_SIDEBAR__
       wgui_clock_close(g_gui_list_clock);
       g_gui_list_clock = WGUI_CLOCK_INVALID_INDEX;
       #endif
	}
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
 *  show_asyncdynamic_list
 * DESCRIPTION
 *  Show the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_asyncdynamic_list(void)
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
    gui_show_asyncdynamic_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS	
    wgui_display_asyncdynamic_text_list_pop_up_description();
#endif

    wgui_list_menu_show_empty_label_if_needed();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gdi_layer_blt_previous(
	    MMI_fixed_list_menu.x, 
	    MMI_fixed_list_menu.y - 1, 
	    MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, 
	    MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);     /* 052305 Calvin modified */
#endif 
    if (g_gui_list_display_callback)
    {
        g_gui_list_display_callback();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  redraw_asyncdynamic_list
 * DESCRIPTION
 *  Redraw the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ANI_BG_LIST_MENU)
    {
        return;
    }
#if( UI_ENABLE_FRAME_SKIPPING )
    if (wgui_fixed_list_menu_frame_counter > 0)
    {
        wgui_fixed_list_menu_frame_counter++;
        gui_show_asyncdynamic_list_menu_no_draw(&MMI_fixed_list_menu);
    }
    else
    {
        wgui_fixed_list_menu_frame_counter = 1;
        gui_show_asyncdynamic_list_menu_no_draw(&MMI_fixed_list_menu);
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_asyncdynamic_list_menu_end_frame);
    }
#else /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
    show_asyncdynamic_list();
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item_common
 * DESCRIPTION
 *  Go to the previous/next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asyncdynamic_list_goto_item_common(S32 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    MMI_BOOL disable_slide_effect = MMI_FALSE;
#endif

	 U16 key_code, key_type;
	
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 GetkeyInfo(&key_code, &key_type);
	 if(key_code == KEY_DOWN_ARROW && key_type ==KEY_REPEAT && (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1))
		 return;
	
	if(key_code == KEY_UP_ARROW && key_type ==KEY_REPEAT && (MMI_fixed_list_menu.highlighted_item == 0))
		 return;

    if(!gui_list_check_goto_item())
		return;
    if (g_gui_list_pre_key_handler)
    {
        MMI_key_code_type code = (direction == 0) ? KEY_UP_ARROW : KEY_DOWN_ARROW;
        if (g_gui_list_pre_key_handler(code) == MMI_TRUE)
        {
            return;
        }
    }

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if ((MMI_fixed_list_menu.highlighted_item > MMI_fixed_list_menu.last_displayed_item) || 
        (MMI_fixed_list_menu.highlighted_item < MMI_fixed_list_menu.first_displayed_item))
        disable_slide_effect = MMI_TRUE;

    if ((direction == 1 && MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.last_displayed_item) || 
        (direction == 0 && MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.first_displayed_item))
        disable_slide_effect = MMI_TRUE;

    if (!disable_slide_effect)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    {
        gui_list_effect_slide_start();
    }
    
    if (direction == 0)
    {
        gui_asyncdynamic_list_menu_goto_previous_item(&MMI_fixed_list_menu);
    }
    else
    {
        gui_asyncdynamic_list_menu_goto_next_item(&MMI_fixed_list_menu);
    }

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if (gui_asyncdynamic_list_error && (!disable_slide_effect))
#else
    if (gui_asyncdynamic_list_error)
#endif
    {
        gui_list_effect_slide_end();
        gui_list_effect_slide_stop();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        if (gui_get_current_list_effect() == MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE)
        {
            gdi_layer_blt_previous(0, 0, 0, 0);
        }
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

        return;
    }

    redraw_asyncdynamic_list();

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if (!disable_slide_effect)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    {
        gui_list_effect_slide_end();    
    }
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_list_goto_item_common(0);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_list_goto_item_common(1);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if ((item_index == MMI_fixed_list_menu.highlighted_item) &&
        (MMI_fixed_list_menu.highlighted_item >= MMI_fixed_list_menu.first_displayed_item &&
        MMI_fixed_list_menu.highlighted_item <= MMI_fixed_list_menu.last_displayed_item))
#else
    if (item_index == MMI_fixed_list_menu.highlighted_item)
#endif
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

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To avoid highlight effect when user jump to wrong menu index */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
    gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    
    redraw_asyncdynamic_list();
}


#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_shortcut_handle_with_SSK
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
*****************************************************************************/
void asyncdynamic_list_shortcut_handle_with_SSK(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_highlighted_item, menu_height, last_displayed_item;
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
#else
    if (item_index != MMI_fixed_list_menu.highlighted_item)
#endif
    {
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        /* To avoid highlight effect when user jump to wrong menu index */
        if (item_index >= MMI_fixed_list_menu.n_items)
        {
            return;
        }
        gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

        /* calculate first_displayed_item, last_displayed_item and highlighted_item */
        gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

        if (gui_list_menu_is_support_smooth_scrolling() && (!gui_asyncdynamic_list_error))
        {   
            /* if gui_list_menu_is_support_smooth_scrolling return MMI_TRUE, common_item_data must be Non-NULL */
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
                    last_displayed_item = MMI_fixed_list_menu.last_displayed_item;
                    if ((new_highlighted_item == last_displayed_item) && 
                        (new_highlighted_item < (asyncdynamic_item_buffer.n_total_items - 1)))
                    {
                            MMI_fixed_list_menu.first_displayed_item += 1;
                            MMI_fixed_list_menu.last_displayed_item += 1;
                    }
                }
            }
        }

        if (gui_asyncdynamic_list_error)
        {
            return;
        }
    
        redraw_asyncdynamic_list();
    }
}
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the asyncdynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item_no_redraw(S32 item_index)
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
    set_asyncdynamic_pop_up_descriptions(item_index);
    if (item_index < 0)
    {
        item_index = 0;
    }
    if (item_index > (MMI_fixed_list_menu.n_items - 1))
    {
        item_index = MMI_fixed_list_menu.n_items - 1;
    }
    /* 
     * This is used in menu setup. Highlighted item is set to -1 at first because
     * 1. gui_asyncdynamic_list_menu_goto_item() might return directly if (highlighted_item==m->highlighted_item)
     * 2. m->item_remove_highlight_function will not be invoked on the previous highlighted item.
     */
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        MMI_fixed_list_menu.highlighted_item = -1;
    }

    gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
    set_asyncdynamic_pop_up_descriptions(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
    register_menu_shortcut_handler(asyncdynamic_list_shortcut_handle_with_SSK);
#else
    register_menu_shortcut_handler(asyncdynamic_list_shortcut_handle);
#endif

#ifdef __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT)
        register_menu_shortcut_selected(wgui_list_menu_shortcut_executer);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the asyncdynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_keyboard_key_handler();
    SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
}


#if( UI_ENABLE_FRAME_SKIPPING )

/*****************************************************************************
 * FUNCTION
 *  wgui_asyncdynamic_list_menu_end_frame
 * DESCRIPTION
 *  Show the dynamic list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_asyncdynamic_list_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_hide_animations();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif 
        gui_show_asyncdynamic_list_menu(&MMI_fixed_list_menu);
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
    #endif 
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS
        wgui_display_asyncdynamic_text_list_pop_up_description();
#endif
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_blt_previous(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_asyncdynamic_list_menu_end_frame);
    }
}


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  wgui_asyncdynamic_matrix_menu_end_frame
 * DESCRIPTION
 *  Show the asyncdynamic matrix for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_asyncdynamic_matrix_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        if (MMI_fixed_matrix_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_matrix_menu();
        }
        gui_hide_animations();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif 
        gui_show_asyncdynamic_matrix_menu(&MMI_fixed_matrix_menu);
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
    #endif 
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_blt_previous(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width,
            MMI_fixed_matrix_menu.y + MMI_fixed_matrix_menu.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_asyncdynamic_matrix_menu_end_frame);
    }
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_pre_display_handler
 * DESCRIPTION
 *  Register the handler function before displaying the menu.
 * PARAMETERS
 *  (*pre_display_handler)(void)       [IN]     pre-display callback function
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_pre_display_handler(void (*pre_display_handler)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.pre_display_function = pre_display_handler;
}

#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/* Asyncdynamic matrix menu */
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
void show_asyncdynamic_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_asyncdynamic_matrix_menu(&MMI_fixed_matrix_menu);
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(
        MMI_fixed_matrix_menu.x,
        MMI_fixed_matrix_menu.y,
        MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
        LCD_HEIGHT - 1);
}


/*****************************************************************************
 * FUNCTION
 *  reset_asyncdynamic_matrix
 * DESCRIPTION
 *  Reset the dynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_asyncdynamic_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    MMI_fixed_matrix_menu.item_highlighted = dummy_highlight_handler;

#ifdef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_matrix_ssp_reset_state();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_previous_item(void)
{
     asyncdynamic_matrix_goto_x(GUI_ASYNC_PREV_ITEM, -1);

}



/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_next_row
 * DESCRIPTION
 *  Go to the the next row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asyncdynamic_matrix_goto_x(S32 goto_type, S32 item_index)
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
    if(goto_type == GUI_ASYNC_ITEM)
    {
         // TODO: SHOULD USE A BETTER WAY TO RESPOND.
	    if ((item_index >= MMI_fixed_matrix_menu.n_items) || (item_index < 0))
	    {
	        MMI_fixed_matrix_menu.last_highlighted_item = -2;

	        return;
	    }
    }
	//hujin

	
    if((goto_type == GUI_ASYNC_NEXT_ROW)|| (goto_type == GUI_ASYNC_PREV_ROW))
    {
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
   }

    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;

	if(goto_type == GUI_ASYNC_NEXT_ROW)		
	   gui_asyncdynamic_matrix_menu_goto_next_row(&MMI_fixed_matrix_menu);
    else if(goto_type == GUI_ASYNC_NEXT_ITEM)
	   gui_asyncdynamic_matrix_menu_goto_next_item(&MMI_fixed_matrix_menu);
    else if(goto_type == GUI_ASYNC_PREV_ITEM)		
       gui_asyncdynamic_matrix_menu_goto_previous_item(&MMI_fixed_matrix_menu);
    else if(goto_type == GUI_ASYNC_PREV_ROW)		
       gui_asyncdynamic_matrix_menu_goto_previous_row(&MMI_fixed_matrix_menu);
	else if(goto_type == GUI_ASYNC_ITEM)		
	    gui_asyncdynamic_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);

	if (gui_asyncdynamic_list_error)
    {
        return;
    }
	
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_asyncdynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
        gui_unlock_double_buffer();
		//hujin
        gdi_layer_blt_previous(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
    else
    {
        redraw_asyncdynamic_matrix();  
    }    

#ifdef __MMI_INTERACTIVE_PROFILNG__
    if((goto_type == GUI_ASYNC_NEXT_ROW)||(goto_type == GUI_ASYNC_PREV_ROW))
      mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_next_item(void)
{
   asyncdynamic_matrix_goto_x(GUI_ASYNC_NEXT_ITEM, -1);
}



/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_previous_row
 * DESCRIPTION
 *  Go to the previous row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_previous_row(void)
{
  asyncdynamic_matrix_goto_x(GUI_ASYNC_PREV_ROW, -1);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_next_row
 * DESCRIPTION
 *  Go to the the next row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_next_row(void)
{
   asyncdynamic_matrix_goto_x(GUI_ASYNC_NEXT_ROW, -1);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_item(S32 item_index)
{
   asyncdynamic_matrix_goto_x(GUI_ASYNC_ITEM, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the fixed matrix.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.highlighted_item = -1;
    gui_asyncdynamic_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_matrix_loop_keys
 * DESCRIPTION
 *  register key handlers of asyncdynamic matrix menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_matrix_loop_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(asyncdynamic_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_matrix_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_matrix_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(asyncdynamic_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_matrix_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the asyncdynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_matrix_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(asyncdynamic_matrix_goto_item);
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


/*****************************************************************************
* FUNCTION
*  wgui_async_list_register_update_callback
* DESCRIPTION
*  Register asyncdynamic list update callback handler
* PARAMETERS
*  async_update_callback     :   [IN] Update callback funtion to update highlight index
* RETURNS
*  void
*****************************************************************************/
void wgui_async_list_register_update_callback(AsyncUpdateCallback async_update_callback)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_async_list_update_callback = async_update_callback;
}


