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
 *  gui_asyncdynamic_menus.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  In order to use limited memory (size decided in compile-time) to load unlimited items (size decide in run-time) 
 *  to a category screen, a modification in MMI for dynamic item loading is required as the following.
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
#include "gui_asyncdynamic_menus.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "wgui_categories_util.h"
#include "gui_touch_feedback.h"
#include "gd_include.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_fixed_menus.h"
#include "gui_dynamic_menus.h"
#include "gui_typedef.h"
#include "gdi_datatype.h"
#include "gui_fixed_menuitems.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "gui_effect_oem.h"
#include "wgui_fixed_menus.h"
#include "CustThemesRes.h"
#include "gui.h"
#include "gui_switch.h"
#include "gui_config.h"
#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif
#include "gui_scrollbars.h"
#include "gdi_include.h"
#include "wgui.h"
#include "wgui_draw_manager.h"
#include "gdi_const.h"
#include "gui_themes.h"
#include "gui_data_types.h"
#include "lcd_sw_inc.h"
#include "string.h"
#include "mmi_frm_input_gprot.h"
#include "ProfilingEngine.h"

#include "gui_font_size.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
//static void gui_asyncdynamic_matrix_abort_scroll_timer(void);
static void gui_asyncdyamic_matrix_menu_scroll_timer_hdlr(void);
static void gui_asyncdyamic_matrix_start_scroll_timer(fixed_matrix_menu *m, S32 value);
static void gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen(
                                                           fixed_matrix_menu *m,
                                                           S32 first_displayed_row,
                                                           gui_matrix_pen_enum *menu_event);
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */                                                           
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
static void gui_asyncdynamic_list_menu_goto_item_without_change_highlight(fixed_list_menu *m, S32 first_displayed);
#endif

#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
static fixed_matrix_menu *gui_pen_scroll_asyncdynamic_matrix_menu = NULL;
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */
static fixed_list_menu *gui_pen_scroll_asyncdynamic_menu = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */

static void gui_asyncdynamic_menu_switch_highlighted_item(void *m, S32 last_highlighted_item);
static void gui_asyncdynamic_list_menu_locate_next_item_helper(fixed_list_menu *m, S32 old_first_displayed_item);

void gui_matrix_menu_locate_x(fixed_matrix_menu *m1, S32 locate_type);
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Indicate menu item loading failure for application. */
S32 gui_asyncdynamic_list_error = 0;
S32 gui_asyncdynamic_list_loading_error = 0;
AsyncDisplayCallback g_gui_list_display_callback = NULL;
AsyncUpdateCallback g_gui_async_list_update_callback = NULL;

extern S32 g_pen_down_item_index;
extern gdi_handle g_gui_ssp_static_layer;

#if defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__) 
extern S32 matrix_mm_active_image_num;
extern gui_image_text_rect matrix_mm_rect[];
#endif /* defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__) */


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted menu item.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_locate_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_ASYNCDYNAMIC;
    gui_list_menu_locate_highlighted_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the menu item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_locate_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_first_displayed_item = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gui_async_list_update_callback && !mmi_frm_in_exit_hdlr_proc())
    {
        g_gui_async_list_update_callback(m->highlighted_item);
    }
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    if (m->highlighted_item <= m->first_displayed_item)
    {
        m->first_displayed_item = m->highlighted_item;
        if (m->highlighted_item == 0 || m->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS)
        {
            m->first_displayed_offset = 0;
        }
        else if (m->first_displayed_offset > 0)
        {
            S32 i, iwidth, iheight, offset;
            if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
            {
                // TODO: it's workaround for hint in highlight item
                m->highlighted_item = (m->first_displayed_item < m->n_items - 1) ? m->first_displayed_item + 1 : 0;
            }
            gui_list_menu_measure_item(m, m->first_displayed_item, &iwidth, &iheight);
            m->highlighted_item = m->first_displayed_item;

            offset = iheight - m->first_displayed_offset;

            for (i = m->highlighted_item - 1; i >= 0; i--)
            {
                gui_list_menu_measure_item(m, i, &iwidth, &iheight);
                if (offset < iheight)
                {
                    m->first_displayed_item = i;
                    m->first_displayed_offset = iheight - offset;
                    break;
                }
                offset -= iheight;
            }
            if (i < 0)
            {
                m->first_displayed_item = 0;
                m->first_displayed_offset = 0;
            }
        }

        gui_list_menu_locate_item_compute_last(m);
        if (m->last_displayed_item == m->highlighted_item && m->last_displayed_offset > 0)
        {
            m->last_displayed_offset = 0;
            gui_list_menu_locate_item_compute_first(m);
        }
        if (m->first_displayed_item == m->highlighted_item && m->first_displayed_offset > 0)
        {
            m->first_displayed_offset = 0;
        }

        if (gui_asyncdynamic_list_error == 0 &&
            !load_chunk_asyncdynamic_item_buffer(m->first_displayed_item, 1))
        {
            gui_asyncdynamic_list_error = 1;
        }
    }
#else
    if (m->highlighted_item < m->first_displayed_item)
    {
        m->first_displayed_item = m->highlighted_item;
        if (gui_asyncdynamic_list_error == 0 &&
            !load_chunk_asyncdynamic_item_buffer(m->highlighted_item, 1))
        {
            gui_asyncdynamic_list_error = 1;
        }
    }
#endif
    else if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
    {
        if (m->highlighted_item == m->last_displayed_item - 1)
        {
            old_first_displayed_item = m->first_displayed_item;
            m->first_displayed_item = 0;
            gui_list_menu_locate_item_compute_first(m);

        gui_asyncdynamic_list_menu_locate_next_item_helper(m, old_first_displayed_item);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_locate_next_item
 * DESCRIPTION
 *  Locate the menu item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_locate_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    S32 last_highlight;
#endif
    S32 old_first_displayed_item = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_first_displayed_item = m->first_displayed_item;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    if (m->highlighted_item >= m->last_displayed_item)
#else
    last_highlight = m->last_displayed_item;
    /* in two-line style load one more for height of highlight is double */
    if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
    {
        last_highlight--;
    }
    if (m->highlighted_item > last_highlight)
#endif
    {
        m->last_displayed_item = m->highlighted_item;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (m->highlighted_item == m->n_items - 1 || m->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS)
        {
            m->last_displayed_offset = 0;
        }
        else if (m->last_displayed_offset > 0)
        {
            S32 i, iwidth, iheight;
            for (i = m->highlighted_item + 1; i < m->n_items; i++)
            {
                gui_list_menu_measure_item(m, i, &iwidth, &iheight);
                if (m->last_displayed_offset < iheight)
                {
                    m->last_displayed_item = i;
                    break;
                }
                m->last_displayed_offset -= iheight;
            }
            if (i == m->n_items)
            {
                m->last_displayed_item = m->n_items - 1;
                m->last_displayed_offset = 0;
            }
        }

        gui_list_menu_locate_item_compute_first(m);
        if (m->first_displayed_item == m->highlighted_item && m->first_displayed_offset > 0)
        {
            m->first_displayed_offset = 0;
            gui_list_menu_locate_item_compute_last(m);
        }
        if (m->last_displayed_item == m->highlighted_item && m->last_displayed_offset > 0)
        {
            m->last_displayed_offset = 0;
        }
#else
        gui_list_menu_locate_item_compute_first(m);
#endif
        if (g_gui_async_list_update_callback && !mmi_frm_in_exit_hdlr_proc())
        {
            g_gui_async_list_update_callback(m->highlighted_item);
        }
        m->current_displayed_item = -1;
        gui_asyncdynamic_list_menu_locate_next_item_helper(m, old_first_displayed_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_switch_highlighted_item
 * DESCRIPTION
 *  Switch from the old highlighted item index to the new highlighted item.
 * PARAMETERS
 *  m                       [IN]        asyncdynamic list menu object      
 *  last_highlighted_item   [IN]        old highlighted menu item index
 * menu_type [IN] 0, list, 1, matrix
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_list_menu_locate_next_item_helper(fixed_list_menu *m, S32 old_first_displayed_item)
{
	if (m->first_displayed_item < old_first_displayed_item)
	 {
		 if (gui_asyncdynamic_list_error == 0 &&
			 !load_chunk_asyncdynamic_item_buffer(m->first_displayed_item, old_first_displayed_item - m->first_displayed_item))
		 {
			 gui_asyncdynamic_list_error = 1;
		 }
	 }
	 /* Load one more item because it might be accessed in gui_show_asyncdynamic_list_menu() */
	 if (gui_asyncdynamic_list_error == 0 &&
		 !load_chunk_asyncdynamic_item_buffer(m->highlighted_item, 2))
	 {
		 gui_asyncdynamic_list_error = 1;
	 }
}
/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_switch_highlighted_item
 * DESCRIPTION
 *  Switch from the old highlighted item index to the new highlighted item.
 * PARAMETERS
 *  m                       [IN]        asyncdynamic list menu object      
 *  last_highlighted_item   [IN]        old highlighted menu item index
 * menu_type [IN] 0, list, 1, matrix
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_menu_switch_highlighted_item(void*m1, S32 last_highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fixed_menu*m = (fixed_menu*)m1;
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            if (in_asyncdynamic_item_buffer(last_highlighted_item))
            {
                m->item_remove_highlight_function(
                    get_asyncdynamic_item_from_buffer(last_highlighted_item),
                    m->common_item_data);
            }
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_asyncdynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_event_current_selected_callback_function = m->pen_event_default_selected_callback_function;
    #endif 
        if (gui_asyncdynamic_list_loading_error == 0)
        {
            m->item_highlighted(m->highlighted_item);
        }
        else
        {
            wgui_title_set_menu_shortcut_number(m->highlighted_item + 1);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_switch_highlighted_item
 * DESCRIPTION
 *  Switch from the old highlighted item index to the new highlighted item.
 * PARAMETERS
 *  m                       [IN]        asyncdynamic list menu object      
 *  last_highlighted_item   [IN]        old highlighted menu item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//hujin
	gui_asyncdynamic_menu_switch_highlighted_item(m, last_highlighted_item);
}

#ifndef __MMI_UI_MENU_SLIM__
void gui_asyncdynamic_list_menu_set_goto_functions(
    fixed_list_menu * m,
    void (*menu_goto_function)(fixed_list_menu *m, S32 i),
    void (*menu_goto_next_function)(fixed_list_menu *m),
    void (*menu_goto_previous_function)(fixed_list_menu *m))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->menu_goto_function = menu_goto_function;
    m->menu_goto_next_function = menu_goto_next_function;
    m->menu_goto_previous_function = menu_goto_previous_function;
}
#endif

#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
void gui_asyncdynamic_list_menu_set_item_get_height_function(fixed_list_menu *m, S32 (*item_get_height_function)(S32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_get_height_function = item_get_height_function;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item by its index.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object         
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_goto_item(fixed_list_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_ASYNCDYNAMIC;
    if (m->flags & UI_LIST_MENU_CUSTOM_GOTO_FUNCTION && m->menu_goto_function)
    {
        m->menu_goto_function(m, i);
    }
    else
    {
        gui_list_menu_goto_item(m, i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object    
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_goto_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_ASYNCDYNAMIC;
    if (m->flags & UI_LIST_MENU_CUSTOM_GOTO_FUNCTION && m->menu_goto_next_function)
    {
        m->menu_goto_next_function(m);
    }
    else
    {
        gui_list_menu_goto_next_item(m);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_menu_goto_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_ASYNCDYNAMIC;
    if (m->flags & UI_LIST_MENU_CUSTOM_GOTO_FUNCTION && m->menu_goto_previous_function)
    {
        m->menu_goto_previous_function(m);
    }
    else
    {
        gui_list_menu_goto_previous_item(m);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_asyncdynamic_list_menu
 * DESCRIPTION
 *  Show the asyncdynamic menu.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_asyncdynamic_list_menu(fixed_list_menu *m)
{
   gui_show_dynamic_list_menu_int(m, GUI_MENU_TYPE_ASYNCDYNAMIC);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_asyncdynamic_list_menu_no_draw
 * DESCRIPTION
 *  Calculate the first and the last displayed item indices.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_asyncdynamic_list_menu_no_draw(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_list_menu_no_draw(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted item in the asyncdynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_matrix_menu_locate_x(fixed_matrix_menu *m,  S32 locate_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((locate_type == GUI_ASYNC_HILITED)||(locate_type == GUI_FIXED_HILITED))
	{
	    m->highlighted_column = m->highlighted_item % m->n_columns;
	    m->highlighted_row = m->highlighted_item / m->n_columns;
	}
	
    if (m->highlighted_column < 0)
    {
        m->highlighted_column = 0;
    }
    if (m->highlighted_row < 0)
    {
        m->highlighted_row = 0;
    }
    if (m->highlighted_column > (m->n_columns - 1))
    {
        m->highlighted_column = m->n_columns - 1;
    }
    if (m->highlighted_row > (m->n_rows - 1))
    {
        m->highlighted_row = m->n_rows - 1;
    }
  if((locate_type == GUI_ASYNC_HILITED)||(locate_type == GUI_FIXED_HILITED))
  {
	    if (m->flags & UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW)
	    {
	        m->first_displayed_row = m->highlighted_row;
	        if (m->first_displayed_row > m->n_rows - m->displayed_rows)
	        {
	            m->first_displayed_row = m->n_rows - m->displayed_rows;
	        }
	    }
	    else if (m->flags & UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW)
	    {
	        m->first_displayed_row = m->highlighted_row - m->displayed_rows + 1;
	        if (m->first_displayed_row < 0)
	        {
	            m->first_displayed_row = 0;
	        }
	    }
	    if (m->flags & UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL)
	    {
	        m->first_displayed_column = m->highlighted_column;
	        if (m->first_displayed_column > m->n_columns - m->displayed_columns)
	        {
	            m->first_displayed_column = m->n_columns - m->displayed_columns;
	        }
	    }
	    else if (m->flags & UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL)
	    {
	        m->first_displayed_column = m->highlighted_column - m->displayed_columns + 1;
	        if (m->first_displayed_column < 0)
	        {
	            m->first_displayed_column = 0;
	        }
	    }
  	}
  
    if (m->highlighted_column < m->first_displayed_column)
    {
        m->first_displayed_column = m->highlighted_column;
    }
    if (m->highlighted_row < m->first_displayed_row)
    {
        m->first_displayed_row = m->highlighted_row;
    }
   
	if (m->highlighted_column > (m->first_displayed_column + m->displayed_columns - 1))
    {
        m->first_displayed_column = (m->highlighted_column - m->displayed_columns + 1);
        if (m->first_displayed_column > (m->n_columns - m->displayed_columns))
        {
            m->first_displayed_column = (m->n_columns - m->displayed_columns);
        }
    } 
	if((locate_type == GUI_ASYNC_HILITED)||(locate_type == GUI_FIXED_HILITED))
    {
	    if ((m->first_displayed_row + m->displayed_rows - 1) >= m->n_rows)
	    {
	        m->first_displayed_row = m->n_rows - m->displayed_rows;
	        if (m->first_displayed_row < 0)
	        {
	            m->first_displayed_row = 0;
	        }
	    }
	}
    if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
    {
        m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
        if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
        {
            m->first_displayed_row = (m->n_rows - m->displayed_rows);
        }
    }
	
	if(locate_type == GUI_FIXED_HILITED)
		return;
	
    if (g_gui_async_list_update_callback && !mmi_frm_in_exit_hdlr_proc())
    {
        g_gui_async_list_update_callback(m->highlighted_item);
    }
	if(locate_type == GUI_ASYNC_HILITED)
	{
	    if (gui_asyncdynamic_list_error == 0 &&
	        !load_chunk_asyncdynamic_item_buffer
	        (m->first_displayed_row * m->n_columns, m->displayed_rows * m->displayed_columns))
	    {
	        gui_asyncdynamic_list_error = 1;
	    }
	}
	else if(locate_type == GUI_ASYNC_NEXT_ITEM)
	{
	    if (gui_asyncdynamic_list_error == 0 &&
	        !load_chunk_asyncdynamic_item_buffer
	        ((m->first_displayed_row + m->displayed_rows - 1) * m->n_columns, m->n_columns))
	    {
	        gui_asyncdynamic_list_error = 1;
	    }
	}
	else if(locate_type == GUI_ASYNC_PREV_ITEM)
	{
	      if (gui_asyncdynamic_list_error == 0 &&
	        !load_chunk_asyncdynamic_item_buffer
	        (m->first_displayed_row * m->n_columns, m->n_columns))
	    {
	        gui_asyncdynamic_list_error = 1;
	    }
	}
}


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__

/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted item in the asyncdynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_locate_highlighted_item(fixed_matrix_menu *m)
{
   gui_matrix_menu_locate_x(m, GUI_ASYNC_HILITED);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the previous item in the asyncdynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_locate_previous_item(fixed_matrix_menu *m)
{
   gui_matrix_menu_locate_x(m, GUI_ASYNC_PREV_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_locate_next_item
 * DESCRIPTION
 *  Locate the next item in the asyncdynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_locate_next_item(fixed_matrix_menu *m)
{
    gui_matrix_menu_locate_x(m, GUI_ASYNC_NEXT_ITEM);
}


/*****************************************************************************
* FUNCTION
*  gui_asyncdynamic_matrix_menu_switch_highlighted_item
* DESCRIPTION
*  Switch from the old highlighted item index to the new highlighted item.
* PARAMETERS
*  m                       [IN]        asyncdynamic matrix menu object      
*  last_highlighted_item   [IN]        old highlighted menu item index
* RETURNS
*  void
*****************************************************************************/
void gui_asyncdynamic_matrix_menu_switch_highlighted_item(fixed_matrix_menu *m, S32 last_highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_asyncdynamic_menu_switch_highlighted_item(m, last_highlighted_item);
}

/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_goto_next_item(fixed_matrix_menu *m)
{
   gui_asyncdynamic_matrix_menu_goto_item(m, GUI_ASYNC_NEXT_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_goto_previous_item(fixed_matrix_menu *m)
{
  gui_asyncdynamic_matrix_menu_goto_item(m, GUI_ASYNC_PREV_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_goto_previous_row
 * DESCRIPTION
 *  Go to the item in the previous row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_goto_previous_row(fixed_matrix_menu *m)
{
   gui_matrix_menu_goto_row_x(m, GUI_ASYNC_PREV_ROW);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_goto_next_row
 * DESCRIPTION
 *  Go to the item in the next row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_goto_next_row(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 locate_highlight = 0;
    U8 locate_previous = 0;
    S32 old_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_asyncdynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 
    old_highlighted_item = m->highlighted_item;

    /* Menu rotation */
    if (m->highlighted_row >= (m->n_rows - 1))
    {
        locate_highlight = 1;
        m->highlighted_row = 0;
        m->first_displayed_row = 0;
    }
    else
    {
        m->highlighted_row++;
        if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
        {
            locate_previous = 1;
            m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
            if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
            {
                m->first_displayed_row = (m->n_rows - m->displayed_rows);
            }
        }
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    m->highlighted_column = m->highlighted_item % m->n_columns;
    m->highlighted_row = m->highlighted_item / m->n_columns;
    /* to support that a row is not full of items */
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        locate_highlight = 1;
        m->highlighted_row = 0;
        m->highlighted_item = m->highlighted_column;
        m->first_displayed_row = 0;
    }
    if (locate_highlight)
    {
        gui_asyncdynamic_matrix_menu_locate_highlighted_item(m);
    }
    else if (locate_previous)
    {
        gui_asyncdynamic_matrix_menu_locate_next_item(m);
    }
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    
    gui_asyncdynamic_matrix_menu_switch_highlighted_item(m, old_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_goto_row
 * DESCRIPTION
 *  Go to the specified row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  r       [IN]        row index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_goto_row(fixed_matrix_menu *m, S32 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_asyncdynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 
    if ((r < 0) || (r > (m->n_rows - 1)) || (r == m->highlighted_row))
    {
        return;
    }

    highlighted_item = m->highlighted_item;
    highlighted_item += (r - m->highlighted_row) * m->n_columns;
    if (highlighted_item >= m->n_items)
    {
        highlighted_item = m->n_items - 1;
    }
    m->highlighted_item = highlighted_item;

    m->highlighted_column = m->highlighted_item % m->n_columns;
    m->highlighted_row = m->highlighted_item / m->n_columns;
    
    gui_asyncdynamic_matrix_menu_locate_highlighted_item(m);
    
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    
    gui_asyncdynamic_matrix_menu_switch_highlighted_item(m, old_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item by its index.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  i       [IN]        item index to be highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_matrix_menu_goto_item(fixed_matrix_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

	U8 loop_flag = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_asyncdynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 
   if(i<GUI_ASYNC_ITEM)//go to item x
   	{
	    if ((i < 0) || (i > (m->n_items - 1)))
	    {
	        return;
	    }
	    m->highlighted_item = i;
	    gui_asyncdynamic_matrix_menu_locate_highlighted_item(m);
	   	}
   else//goto nextitem previten
   {
      if (((m->highlighted_item >= (m->n_items - 1))&& (i==GUI_ASYNC_NEXT_ITEM))
	  	|| ((m->highlighted_item <= 0)&&(i==GUI_ASYNC_PREV_ITEM)))
	  {
	        if (m->flags & UI_MATRIX_MENU_LOOP)
	        {
	            loop_flag = 1;
				m->highlighted_item = ((i==GUI_ASYNC_NEXT_ITEM)?(0):(m->n_items - 1));
	            //m->highlighted_item = 0;
	        }
	        else
	        {
	            return;
	        }
	    }
	    else
	    {
	        //m->highlighted_item++;
			if(i==GUI_ASYNC_NEXT_ITEM)
			    m->highlighted_item++;
			else
				m->highlighted_item--;
	    }
	    m->highlighted_column = m->highlighted_item % m->n_columns;
	    m->highlighted_row = m->highlighted_item / m->n_columns;
	    if ((m->highlighted_row < m->first_displayed_row) ||
	        (m->highlighted_column < m->first_displayed_column) ||
	        (m->highlighted_column > m->first_displayed_column + m->displayed_columns - 1) ||
	        (m->highlighted_row > m->first_displayed_row + m->displayed_rows - 1))
	    {
	        if (loop_flag)
	        {
	            gui_asyncdynamic_matrix_menu_locate_highlighted_item(m);
	        }
	        else
	        {   
	            if(i == GUI_ASYNC_NEXT_ITEM)
		            gui_asyncdynamic_matrix_menu_locate_next_item(m);
			    else					
					gui_asyncdynamic_matrix_menu_locate_previous_item(m);
	        }
	    }
 

   }
    
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    
    gui_asyncdynamic_matrix_menu_switch_highlighted_item(m, old_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_asyncdynamic_matrix_menu
 * DESCRIPTION
 *  Display the asyncdynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_asyncdynamic_matrix_menu(fixed_matrix_menu *m)
{
    gui_show_asyncdynamic_matrix_menu_specific_items(m, GUI_SHOW_ASYNC_MENU); 
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


/*****************************************************************************
 * FUNCTION
 *  gui_show_asyncdynamic_matrix_menu_specific_items
 * DESCRIPTION
 *  Display last highlight and current highlight in dynamic matrix menu.
 * PARAMETERS
 *  m                  [IN]    Fixed matrix menu object
 *  last_highlight     [IN]    The index of last highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_asyncdynamic_matrix_menu_specific_items(fixed_matrix_menu *m, S32 last_highlight)
{
	//gui_show_matrix_menu(m, GUI_SHOW_ASYNC_SPECIAL, last_highlight);

     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, xoff, yoff, width, height;
    S32 yoff_gap;
    UI_filled_area *f;
    S32 i, j, k, o;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 ix, iy, iwidth, iheight, ix2, iy2;
    U8 show_vbar = 0, show_hbar = 0;
    S32 highlite_x = 0, highlite_y = 0; /* Show selected item after all other items displayed //111605 warning Calvin */

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    S32 xoff2, yoff2;
    S32 xPos, xPos2, yPos, yPos2;
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 

    //asyncdynamic
    fixed_icontext_list_menuitem_type* item_p=NULL;

	//
	S32 matrix_type = last_highlight;
	if(matrix_type< GUI_SHOW_FIXED_MENU)
		matrix_type = GUI_SHOW_ASYNC_SPECIAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->n_items <= 0)
       return;

	if(matrix_type == GUI_SHOW_ASYNC_MENU)//asyncdynamic matrix
	{
     	if (gui_asyncdynamic_list_error)/* Context is invalid, and screen is exiting */    
          return;
	}
	

//hujin
    else if(matrix_type == GUI_SHOW_FIXED_MENU)//fixed matrix   
    {
#if defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__)
    matrix_mm_active_image_num = 0;
#endif
      if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
      {
        show_hbar = 1;
      }
    }

    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }

//hujin
	if(mmi_fe_get_r2l_state())
    {
        if (show_vbar)
        {
            x1 = m->x + m->vbar.width;
        }
        else
        {
            x1 = m->x;
        }
        x2 = m->x + m->width - 1;
    }
    else
    {
        x1 = m->x;
        x2 = x1 + m->width - 1;
    }

    y1 = m->y;
        y2 = y1 + m->height - 1;

    if (m->flags & UI_MATRIX_MENU_STATE_FOCUSSED)
    {
        f = m->focussed_filler;
    }
    else
    {
        f = m->normal_filler;
    }

  //asyncdynamic
  if((matrix_type == GUI_SHOW_ASYNC_MENU)||(matrix_type == GUI_SHOW_FIXED_MENU))
  {
   if (m->flags & UI_MATRIX_MENU_DISABLE_BACKGROUND)
    {
    //hujin
    
	   gdi_layer_push_and_set_clip(x1, y1, x2, y2);
	
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_clip();
    }
    else
    {
        gui_set_clip(x1, y1, x2, y2);
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        #if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
            /* gui_set_transparent_source_layer(dm_get_scr_bg_layer());//should remove */
        #endif 
        }
        else if (f != NULL)
        {
            UI_filled_area tmp_f = *f;

            /* In current implementation, matrix menu does not support bordered background 
               very well because highlighted item is overlapped with border. */
            tmp_f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
            
            gui_draw_filled_area(x1, y1, x2, y2, &tmp_f);
        }
        else
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
  }


		
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
   	//fixed matrix
	if(matrix_type == GUI_SHOW_FIXED_MENU)
	{
	    /* Start Draw Indication Arrows. */
	    if (MMI_current_menu_type == LIST_MATRIX_MENU)
	    {
	            gdi_layer_push_clip();
	            gdi_layer_reset_clip();
	        if (m->displayed_rows < m->n_rows)
	            {
	            draw_arrow_indication(MMI_FALSE, MMI_FALSE, MMI_TRUE, MMI_TRUE);
	            }
	        else
	            {
	                gdi_draw_solid_rect(
	                    0,
	                    UI_device_height - MMI_button_bar_height,
	                    UI_device_width - 1,
	                    UI_device_height - 1,
	                    GDI_COLOR_TRANSPARENT);
	            redraw_softkey(MMI_LEFT_SOFTKEY);
	            redraw_softkey(MMI_RIGHT_SOFTKEY);
	            redraw_softkey(MMI_CENTER_SOFTKEY);
	            }
	            gdi_layer_pop_clip();
	            
	    }
	    /* End Draw Indication Arrows. */
	}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

//hujin
//    if (r2lMMIFlag)
    if(mmi_fe_get_r2l_state())
    {
        if (show_hbar &&(matrix_type==GUI_SHOW_FIXED_MENU))
        {
            y2 -= m->hbar.height - 1;
        }
    }
    else
    {
        if (show_vbar)
        {
            x2 -= m->vbar.width;
        }
        if (show_hbar&&(matrix_type == GUI_SHOW_FIXED_MENU))
        {
            y2 -= m->hbar.height - 1;
        }
    }

    width = x2 - x1 + 1;
    height = y2 - y1 + 1;
    iwidth = m->item_width;
    iheight = m->item_height;

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);

    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);
//fixed matrix
   if(matrix_type ==GUI_SHOW_FIXED_MENU)
   	{
		yoff_gap = (height - (iheight * m->displayed_rows)) % (m->displayed_rows + 1);
	    if (yoff_gap)
	    {
	        m->height -= yoff_gap;
	    }
   	}
   
    iy = y1 + yoff;
    for (j = 0; j < m->displayed_rows; j++)
    {
        ix = x1 + xoff;
        o = (m->first_displayed_row + j) * m->n_columns;
        for (i = 0; i < m->displayed_columns; i++)
        {
            k = o + (m->first_displayed_column + i);
			//fixed matrix
			if(matrix_type == GUI_SHOW_FIXED_MENU)
               m->current_display_item = k;
			
            if (k > (m->n_items - 1))
            {
                break;
            }
			if((matrix_type == GUI_SHOW_ASYNC_MENU)||(matrix_type == GUI_SHOW_ASYNC_SPECIAL))//
			{
				m->current_display_item = k;
				item_p = get_asyncdynamic_item_from_buffer(k);
			}
			
            ix2 = ix + iwidth - 1;
            iy2 = iy + iheight - 1;
            if (ix2 > x2)
            {
                ix2 = x2;
            }
            if (iy2 > y2)
            {
                iy2 = y2;
            }
            gdi_layer_push_clip();
            gui_set_clip(ix, iy, ix2, iy2);
            gui_set_text_clip(ix, iy, ix2, iy2);

        #if defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__)
            if(matrix_type == GUI_SHOW_FIXED_MENU)
            {
			    /* save matrix icon information for the sliding effect */
	            if ((MMI_current_menu_type == LIST_MATRIX_MENU) || (((MMI_current_menu_type == MATRIX_MENU) || (MMI_current_menu_type == MATRIX_PAGE_MENU)) 
	                && (MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_FOR_MAINMENU)))
	            {
	                S32 sw = 0, sh = 0;                
	                gui_image_text_rect    *image_rect = &matrix_mm_rect[matrix_mm_active_image_num];
	                fixed_icontext_menuitem_type *mi = (fixed_icontext_menuitem_type*)m->items[k];
	                fixed_text_menuitem *mm = (fixed_text_menuitem*)m->common_item_data;
	                
	                image_rect->rect.x = ix;
	                image_rect->rect.y = iy;
	                image_rect->rect.width = ix2 - ix + 1;
	                image_rect->rect.height = iy2 - iy + 1;

	                if (mm->flags & UI_MENUITEM_CENTER_TEXT_X)
	                {
	                    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_MATRIX_MAINMENU));
	                    gui_measure_string(mi->item_text, &sw, &sh);
						//hujin
	                    //if (r2lMMIFlag)
	                    if(mmi_fe_get_r2l_state())
						{
	                        image_rect->rect_text.x = mm->width - 1 - ((mm->width - sw) >> 1) - 1 + ix; 
	                    }
	                    else
	                    {
	                        image_rect->rect_text.x = ix + ((mm->width - sw) >> 1);
	                    }
	                }
	                else
	                {
	                    image_rect->rect_text.x = ix + mm->text_x;
	                }                
	                if (image_rect->rect_text.x < ix)
	                    image_rect->rect_text.x = ix;
	                image_rect->rect_text.y = iy + mm->text_y;
	                image_rect->rect_text.width = mm->scroll_width;
	                image_rect->rect_text.height = iy2 - image_rect->rect_text.y + 1;

	                image_rect->image = mi->item_icon;                                
	                image_rect->text = mi->item_text;    
	                matrix_mm_active_image_num++;
	            }
            }
        #endif /* defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__) */
            
         //fixed matrix
         if(matrix_type == GUI_SHOW_FIXED_MENU)
         {
	            /* show selected item after all other items displayed */
	            if (k == m->highlighted_item)
	            {
	                highlite_x = ix;
	                highlite_y = iy;
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
	                if (m->flags & UI_MATRIX_MENU_FOR_MAINMENU)
	                {
	                    //hujin
	                    #if 0
/* under construction !*/
/* under construction !*/
						#endif
	                    gdi_layer_push_and_set_clip(ix, iy, ix + iwidth - 1, iy + iheight - 1); 
						
	                    gdi_layer_flatten_with_clipping(dm_get_scr_bg_layer(), 0, 0, 0);
	                    gdi_layer_pop_clip();
	                }
	                else
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */
	                {
	                    m->item_remove_highlight_function(m->items[k], m->common_item_data);
	                    m->item_display_function(m->items[k], m->common_item_data, ix, iy);
	                    m->item_highlight_function(m->items[k], m->common_item_data);
	                }
	            }
	            else
	            {
	                m->item_display_function(m->items[k], m->common_item_data, ix, iy);
	            }
         	}
		    else if(matrix_type == GUI_SHOW_ASYNC_MENU)
		    {
               
			   m->item_display_function(item_p, m->common_item_data, ix, iy);
			}
			else
			{
            /* show last highlight and current highlight only */
            if (k == last_highlight || k == m->highlighted_item)
            {
                if (m->flags & UI_MATRIX_MENU_DISABLE_BACKGROUND)
                {
                    gdi_draw_solid_rect(ix, iy, ix2, iy2, GDI_COLOR_TRANSPARENT);
                }
                else
                {
                    gui_set_clip(ix, iy, ix2, iy2);
                    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
                    {
                        gdi_draw_solid_rect(ix, iy, ix2, iy2, GDI_COLOR_TRANSPARENT);
                    }
                    else if (f != NULL)
                    {
                        UI_filled_area tmp_f = *f;

                        /* In current implementation, matrix menu does not support bordered background 
                           very well because highlighted item is overlapped with border. */
                        tmp_f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
            
                        gui_draw_filled_area(ix, iy, ix2, iy2, &tmp_f);
                    }
                    else
                    {
                        gdi_draw_solid_rect(ix, iy, ix2, iy2, GDI_COLOR_WHITE);
                    }
                }
                m->item_display_function(item_p, m->common_item_data, ix, iy);
            }
			}
            gdi_layer_pop_clip();
            ix += iwidth + xoff;
        }
        iy += iheight + yoff;
    }

#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    if (m->flags & UI_MATRIX_MENU_FOR_MAINMENU)
    {
        gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
	   //hujin
	   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #endif
	    gdi_layer_push_and_set_clip(
            m->x,
            m->y,
            m->x + m->width - 1,
            m->y + m-> height - 1);
        if (xoff || yoff)
        {
            gdi_layer_flatten_with_clipping(dm_get_scr_bg_layer(),GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0);
        }
        else
        {
            gdi_layer_flatten_with_clipping(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
        }
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */   

    /* EMS menu not optimized in current implementation, but it can be optimized */
    if ((MMI_current_menu_type != MATRIX_MENU_EMS) &&
        (m->flags & UI_MATRIX_MENU_FOR_MAINMENU))
    {
    #ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
        if (m->highlighted_item_width > m->item_width)
        {
            xoff2 = (m->highlighted_item_width - m->item_width);
            xPos = highlite_x - (xoff2 >> 1);
            xPos2 = xPos + m->highlighted_item_width - 1;
            if (xPos < x1)
            {
                xPos = x1;
                xPos2 = xPos + m->highlighted_item_width - 1;
            }
            if (xPos2 > x1 + width - 1)
            {
                xPos2 = x1 + width - 1;
                xPos = xPos2 - m->highlighted_item_width + 1;
            }
            
        }
        else
        {
            xoff2 = 0;
            
            xPos = highlite_x - (xoff2 >> 1);
            xPos2 = xPos + m->item_width - 1;
            if (xPos < m->x)
            {
                xPos = m->x;
                xPos2 = xPos + m->item_width - 1;
            }
            if (xPos2 > x1 + width - 1)
            {
                xPos2 = x1 + width - 1;
                xPos = xPos2 - m->item_width + 1;
            }
        }
        if (m->highlighted_item_height > m->item_height)
        {
            yoff2 = (m->highlighted_item_height - m->item_height);
            yPos = highlite_y - (yoff2 >> 1);
            yPos2 = yPos + m->highlighted_item_height - 1;
            
            
            if (yPos < m->y)
            {
                yPos = m->y;
                yPos2 = yPos + m->highlighted_item_height - 1;
            }
            if (yPos2 > m->y + m->height - 1)
            {
                yPos2 = m->y + m->height - 1;
                yPos = yPos2 - m->highlighted_item_height + 1;
            }
        }
        else
        {
            yoff2 = 0;
            yPos = highlite_y - (yoff2 >> 1);
            yPos2 = yPos + m->item_height - 1;
            
            
            if (yPos < m->y)
            {
                yPos = m->y;
                yPos2 = yPos + m->item_height - 1;
            }
            if (yPos2 > m->y + m->height - 1)
            {
                yPos2 = m->y + m->height - 1;
                yPos = yPos2 - m->item_height + 1;
            }
        }
		//hujin
        //gdi_layer_push_clip();
        gdi_layer_push_and_set_clip(xPos, yPos, xPos2, yPos2);
        
        MMI_ASSERT((xPos2 - xPos + 1) * (yPos2 - yPos + 1) * gdi_layer_get_bit_per_pixel() >> 3 <=
                   MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
    
        gdi_image_cache_bmp_get(xPos, yPos, xPos2, yPos2, &m->buffer);
        gdi_layer_pop_clip();

        m->cache_bmp_x1 = xPos;
        m->cache_bmp_x2 = xPos2;
        m->cache_bmp_y1 = yPos;
        m->cache_bmp_y2 = yPos2;
        m->last_hilited_x = highlite_x;
        m->last_hilited_y = highlite_y;
    #endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
    }

    /* Clear background for vector font, clear the effect of drawing one item twice */
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    gdi_draw_solid_rect(
        highlite_x,
        highlite_y,
        highlite_x + m->item_width - 1,
        highlite_y + m->item_height - 1,
        GDI_COLOR_TRANSPARENT);
#endif
if(matrix_type == GUI_SHOW_FIXED_MENU)
{
    /* gui_set_clip(highlite_x,highlite_y,highlite_x+iwidth,highlite_y+iheight); */
    m->current_display_item = m->highlighted_item;
    m->item_display_function(m->items[m->highlighted_item], m->common_item_data, highlite_x, highlite_y);
}
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);


	//hujin
	if(show_vbar && ((matrix_type == GUI_SHOW_FIXED_MENU) ||(matrix_type == GUI_SHOW_ASYNC_MENU)))
		gui_matrix_menu_show_vscrollbar(m);
	
	if((matrix_type == GUI_SHOW_FIXED_MENU)&& show_hbar)
		gui_matrix_menu_show_hscrollbar(m);

}


#ifdef __MMI_TOUCH_SCREEN__


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/*****************************************************************************
* FUNCTION
*  gui_asyncdyamic_matrix_menu_scroll_timer_hdlr
* DESCRIPTION
*  Scrolling timer handler.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void gui_asyncdyamic_matrix_menu_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_matrix_menu *m = gui_pen_scroll_asyncdynamic_matrix_menu;
    gui_matrix_pen_enum menu_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_asyncdynamic_matrix_menu = NULL;  
    
    if (!m)
    {
        return;
    }
    if (gui_asyncdynamic_list_error)
    {
        return;
    }

    gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen(m, m->pen_scroll_after_delay, &menu_event);

    if (gui_asyncdynamic_list_error)
    {
        return;
    }

    if (menu_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED || menu_event == GUI_MATRIX_PEN_NEED_REDRAW)
    {
        gui_lock_double_buffer();
        gui_show_asyncdynamic_matrix_menu(&MMI_fixed_matrix_menu);
        gui_unlock_double_buffer();
        gdi_layer_blt_previous(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
}


/*****************************************************************************
* FUNCTION
*  gui_asyncdynamic_matrix_abort_scroll_timer
* DESCRIPTION
*  Abort scrolling timer.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gui_asyncdynamic_matrix_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_asyncdynamic_matrix_menu = NULL;
}


/*****************************************************************************
* FUNCTION
*  gui_asyncdyamic_matrix_start_scroll_timer
* DESCRIPTION
*  Start scrolling timer.
* PARAMETERS
*  m       [IN]        asyncdynamic matrix menu object         
*  value   [IN]        item index to scroll to
* RETURNS
*  void
*****************************************************************************/
static void gui_asyncdyamic_matrix_start_scroll_timer(fixed_matrix_menu *m, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(!gui_pen_scroll_asyncdynamic_matrix_menu || gui_pen_scroll_asyncdynamic_matrix_menu == m);
    
    m->pen_scroll_after_delay = value;
    gui_pen_scroll_asyncdynamic_matrix_menu = m;
    
    gui_cancel_timer(gui_asyncdyamic_matrix_menu_scroll_timer_hdlr);
    gui_start_timer(m->pen_scroll_delay_time, gui_asyncdyamic_matrix_menu_scroll_timer_hdlr);
    
    gui_add_cleanup_hook(gui_asyncdynamic_matrix_abort_scroll_timer);
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


static void gui_asyncdynamic_list_menu_scroll_by_pen(
                fixed_list_menu *m,
                S32 first_displayed,
                gui_list_pen_enum *menu_event);

/* Target menu for scroll timer */

/* Because loading data takes some time (depending on the applications using asyncdynamic list), 
   we use a timer to reduce gui_asyncdynamic_list_menu_scroll_by_pen().  */


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_scroll_timer_hdlr
 * DESCRIPTION
 *  Scrolling timer handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_list_menu_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_list_menu *m = gui_pen_scroll_asyncdynamic_menu;
    gui_list_pen_enum menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_asyncdynamic_menu = NULL;

    if (!m)
    {
        return;
    }

    if (gui_asyncdynamic_list_error)
    {
        return;
    }

    gui_asyncdynamic_list_menu_scroll_by_pen(m, m->pen_scroll_after_delay, &menu_event);

    if (gui_asyncdynamic_list_error)
    {
        return;
    }

    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED || menu_event == GUI_LIST_PEN_NEED_REDRAW)
    {
        if (m->pen_redraw_menu_function)
        {
            m->pen_redraw_menu_function();
        }
        else
        {
            MMI_DBG_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_abort_scroll_timer
 * DESCRIPTION
 *  Abort scrolling timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_list_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_asyncdynamic_menu = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_start_scroll_timer
 * DESCRIPTION
 *  Start scrolling timer.
 * PARAMETERS
 *  m       [IN]        asyncdynamic list menu object
 *  value   [IN]        item index to scroll to
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_list_start_scroll_timer(fixed_list_menu *m, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* assert that no two menu scroll at the same time */
    MMI_DBG_ASSERT(!gui_pen_scroll_asyncdynamic_menu || gui_pen_scroll_asyncdynamic_menu == m);

    m->pen_scroll_after_delay = value;
    gui_pen_scroll_asyncdynamic_menu = m;

    gui_cancel_timer(gui_asyncdynamic_list_menu_scroll_timer_hdlr);
    gui_start_timer(m->pen_scroll_delay_time, gui_asyncdynamic_list_menu_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_asyncdynamic_list_abort_scroll_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_translate_pen_position
 * DESCRIPTION
 *  Get item index from the pen y coordinate.
 * PARAMETERS
 *  m           [IN]        asyncdynamic list menu object         
 *  y           [IN]        y      
 *  item_index  [OUT]       penned item index
 * RETURNS
 *  Return MMI_TRUE if y is within the menu; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_asyncdynamic_list_menu_translate_pen_position(fixed_list_menu *m, S32 x, S32 y, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, i;
    S32 iwidth, iheight;
    MMI_BOOL ret = MMI_FALSE;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x -= m->x;
    y -= m->y;

    if (y < 0)
    {
        *item_index = (m->first_displayed_item > 0) ? m->first_displayed_item - 1 : 0;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
        m->item_get_flag_function(NULL, NULL, *item_index, &flags, &flags_ext);
        if (flags & UI_MENUITEM_STATE_DISABLED)
        {        
            while (flags & UI_MENUITEM_STATE_DISABLED)
            {
                if ( *item_index != 0)        
                {
                    (*item_index) --;
                }
                else
                {
                    break;
                }
                m->item_get_flag_function(NULL, NULL, *item_index, &flags, &flags_ext);
            }        
        }
#endif
    }
    else if (y >= m->height)
    {
        *item_index = (m->last_displayed_item < m->n_items - 1) ? m->last_displayed_item + 1 : m->n_items - 1;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
        m->item_get_flag_function(NULL, NULL, *item_index, &flags, &flags_ext);
        if (flags & UI_MENUITEM_STATE_DISABLED)
        {        
            while (flags & UI_MENUITEM_STATE_DISABLED)
            {
                if ( *item_index >= (m->n_items - 1))        
                {
                    break;
                }
                else
                {
                    (*item_index) ++;
                }
                m->item_get_flag_function(NULL, NULL, *item_index, &flags, &flags_ext);
            }        
        }
#endif
    }
    else
    {
        *item_index = m->n_items - 1;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (m->first_displayed_offset > 0)
        {
            total_height -= m->first_displayed_offset;
        }
#endif
        for (i = m->first_displayed_item; i < m->n_items; i++)
        {
            if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT
#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
                || ((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_EXT_INEQUAL_HEIGHT
#endif
               )
            {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
            } 
            /* Use null because menu item might not be loaded yet */
            m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > y)
            {
                *item_index = i;
#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
                if (mmi_fe_get_r2l_state())
                {
#ifndef __MMI_FTE_SUPPORT__
                    x += m->vbar.width + GUI_MENUITEM_X2_GAP;
#else
                    x += GUI_MENUITEM_X2_GAP;
#endif /* __MMI_FTE_SUPPORT__ */
                }

                if (gui_fixed_icontext_list_menuitem_is_pen_in_checkbox(NULL, m->common_item_data, 0, 0, x, y - (total_height - iheight)))
                {
                    return MMI_TRUE;
                }
                if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_EXT_INEQUAL_HEIGHT
                    && m->item_pen_check_bound_function)
                {
                    ret = m->item_pen_check_bound_function(NULL, m->common_item_data, i, x, y - (total_height - iheight));
                }
                else
#endif
                {
                    ret = MMI_TRUE;
                }
                break;
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_scroll_by_pen
 * DESCRIPTION
 *  Scroll the menu by pen.
 * PARAMETERS
 *  m                   [IN]        asyncdynamic list menu object       
 *  first_displayed     [IN]        first displayed item index
 *  menu_event          [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_list_menu_scroll_by_pen(
                fixed_list_menu *m,
                S32 first_displayed,
                gui_list_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    S32 total_height = 0, i;
    S32 iwidth, iheight;
    S32 last_displayed;
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    S32 old_flags = m->flags;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    S32 item_index = 0, done = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_flags = m->flags;
    m->flags &= ~UI_LIST_MENU_LOOP;
    
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    for (i = 0; i < m->n_items; i++)
    {
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (!done && total_height > first_displayed)
        {
            done = 1;
            item_index = i;
            m->first_displayed_offset = first_displayed - (total_height - iheight);
        }
        if (total_height > first_displayed + m->height)
        {
            m->last_displayed_offset = (first_displayed + m->height) - (total_height - iheight);
            break;
        }
    }
    first_displayed = item_index;
#endif

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__    
    gui_asyncdynamic_list_menu_goto_item_without_change_highlight(m, first_displayed);
    *menu_event = GUI_LIST_PEN_NEED_REDRAW;
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */    
    if (first_displayed > m->highlighted_item)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_asyncdynamic_list_menu_goto_item(m, first_displayed);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
    }
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    else if (first_displayed == m->highlighted_item && m->first_displayed_offset > 0)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_asyncdynamic_list_menu_goto_item(m, first_displayed + 1);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
    }
#endif
    else
    {
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        total_height = -m->first_displayed_offset;
#endif
        last_displayed = m->n_items - 1;
        for (i = first_displayed; i < m->n_items; i++)
        {
            if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
            {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
            } 
            /* Use null because menu item might not be loaded yet */
            m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > m->height + 1)
            {
                last_displayed = i - 1;
                break;
            }
        }

        if (last_displayed < m->highlighted_item)
        {
            m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            gui_asyncdynamic_list_menu_goto_item(m, last_displayed);
            m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            m->first_displayed_item = first_displayed;
            m->last_displayed_item = last_displayed;
            /* Handle this in similar way to asyncdynamic_list_goto_item_no_redraw */
            if (gui_asyncdynamic_list_error == 0)
            {   
            if (load_chunk_asyncdynamic_item_buffer
                (m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2))
            {
                gui_asyncdynamic_list_menu_switch_highlighted_item(m, -1);
            }
            else
            {
                gui_asyncdynamic_list_error = 1;
            }
            }

            *menu_event = GUI_LIST_PEN_NEED_REDRAW;
        }
    }
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */

    if (gui_asyncdynamic_list_error)
    {
        *menu_event = GUI_LIST_PEN_NONE;
    }
    m->flags = old_flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdymaic_list_menu_get_menuitem_position
 * DESCRIPTION
 *  Get menu item (x1, y1) by its index.
 * PARAMETERS
 *  m           [IN]        asyncdynamic list menu object         
 *  item_index  [IN]        item index
 *  x           [OUT]       x1 of the item
 *  y           [OUT]       y1 of the item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdymaic_list_menu_get_menuitem_position(fixed_list_menu *m, S32 item_index, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_height = m->y;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = m->x;

    // TODO: must consider scrollbar absence
    if (mmi_fe_get_r2l_state())
    {
#ifndef __MMI_FTE_SUPPORT__    
        *x += m->vbar.width + GUI_MENUITEM_X2_GAP;
#else
        *x += GUI_MENUITEM_X2_GAP;
#endif /* __MMI_FTE_SUPPORT__ */
    }

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    if (m->first_displayed_offset > 0)
    {
        total_height -= m->first_displayed_offset;
    }
#endif

    if (item_index <= m->first_displayed_item)
    {
        *y = total_height;
        return;
    }

    for (i = m->first_displayed_item; i <= m->last_displayed_item; i++)
    {
        if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
        {
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
        } 
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (i + 1 == item_index)
        {
            *y = total_height;
            return;
        }
    }
    *y = total_height;
}


#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
void gui_asyncdynamic_list_menu_set_pen_check_bound_function(
    fixed_list_menu *m,
    MMI_BOOL (*item_pen_check_bound_function)(void *item, void *common_item_data, S32 index, S16 x, S16 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_pen_check_bound_function = item_pen_check_bound_function;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_list_menu_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the asyncdynamic list menu.
 * PARAMETERS
 *  m           [IN]        asyncdynamic list menu object         
 *  pen_event   [IN]        pen event type
 *  x           [IN]        pen x   
 *  y           [IN]        pen y
 *  menu_event  [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_asyncdynamic_list_menu_translate_pen_event(
        fixed_list_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_list_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    S32 item_index;
    gui_pen_event_param_struct menuitem_param;
    gui_list_pen_enum menuitem_event;
    S32 item_x, item_y;

#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
    gui_common_menuitem_base_struct *cm;
    S32 menu_height;
#endif /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN  */       
    S32 old_flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: Use the same pen handler for all menus.
    
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    *menu_event = GUI_LIST_PEN_NONE;

    if (gui_asyncdynamic_list_error)
    {
        return MMI_FALSE;
    }

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (m->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
            {
                gui_asyncdynamic_list_start_scroll_timer(m, scrollbar_param._u.i);
            }
            else
            {
                gui_asyncdynamic_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
            }
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    else if ((pen_event == MMI_PEN_EVENT_MOVE && pen_state->pen_down_state_box) ||
             (pen_event != MMI_PEN_EVENT_DOWN && pen_event!= MMI_PEN_EVENT_MOVE && pen_state->handled_by_menu_item))
    {
        /* For example, tap down on checkbox of two-state menuitem, the subsequent move/up events are discarded */ 
        gui_asyncdymaic_list_menu_get_menuitem_position(m, m->highlighted_item, &item_x, &item_y);

        GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), m->highlighted_item, GUI_LIST_PEN_NONE);
        
        m->item_pen_function(
            get_asyncdynamic_item_from_buffer(m->highlighted_item),
            m->common_item_data,
            item_x,
            item_y,
            pen_event,
            x,
            y,
            &menuitem_event,
            &menuitem_param);

        if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
        {
            menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
        }
        
        *menu_event = menuitem_event;
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                g_pen_down_item_index = -1;
                if (m->n_items <= 0)
                {
                    /* In current design, scrollbar is hiden if m->n_items == 0 */
                    ret = MMI_FALSE;
                }
                else if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    pen_state->handled_by_menu_item = 0;                    
                    pen_state->pen_on_scrollbar = 0;
                    pen_state->pen_down_state_box = 0;

                    if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) &&
                       !(m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR && (m->displayed_items == m->n_items)) &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &m->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_scrollbar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            if ((m->pen_scroll_delay_time > 0) &&
                                !(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR_DRAG))   /* Delay time for scrollbar scrolling */
                            {
                                gui_asyncdynamic_list_start_scroll_timer(m, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_asyncdynamic_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                            }
                        }
                    }
                    else
                    {
                        if (gui_asyncdynamic_list_menu_translate_pen_position(m, x, y, &item_index))
                        {
                            U32 iflags, iflags_ext;

                            g_pen_down_item_index = item_index;
                            m->item_get_flag_function(
                                NULL,  
                                NULL,
                                item_index,  
                                &iflags, 
                                &iflags_ext);

                            if (!(iflags & UI_MENUITEM_STATE_DISABLED))
                            {
                                // only enable item give touch feedback
                                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                            }
                            
                            if (item_index != m->highlighted_item && 
                                item_index >= m->first_displayed_item &&
                                item_index <= m->last_displayed_item &&
                                !(iflags & UI_MENUITEM_STATE_DISABLED))
                            {
                                old_flags = m->flags;
                                m->flags &= ~UI_LIST_MENU_LOOP;
                                gui_asyncdynamic_list_menu_goto_item(m, item_index);
                                m->flags = old_flags;
                                *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                                GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), item_index, GUI_LIST_PEN_HIGHLIGHT_CHANGED);
                            }   
                            
                            gui_asyncdymaic_list_menu_get_menuitem_position(m, item_index, &item_x, &item_y);                            
                            if (m->item_pen_function(
                                    get_asyncdynamic_item_from_buffer(item_index),
                                    m->common_item_data,
                                    item_x,
                                    item_y,
                                    pen_event,
                                    x,
                                    y,
                                    &menuitem_event,
                                    &menuitem_param))
                            {                                
                                if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
                                {
                                    menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
                                }
                                
                                if (menuitem_event != GUI_LIST_PEN_NONE)
                                {
                                    *menu_event = menuitem_event;
                                }

                                pen_state->handled_by_menu_item = 1;
                                if (menuitem_event == GUI_LIST_PEN_DOWN_ON_STATE_BOX)
                                {
                                    pen_state->pen_down_state_box = 1;
                                }
                            }                 
                        }
                        else
                        {
                            /* # of menu items < # of displayable menu items */
                            ret = MMI_FALSE;
                        }
                    }
                    pen_state->first_highlighed_item = m->highlighted_item;
                    pen_state->highlight_changed = 0;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_LONG_TAP:
                /* FALLTHROUGH no break */
                break;

            case MMI_PEN_EVENT_REPEAT:
                /* FALLTHROUGH no break */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)                
                break;
#endif

            case MMI_PEN_EVENT_MOVE:
                {
                U32 iflags, iflags_ext;
                gui_asyncdynamic_list_menu_translate_pen_position(m, x, y, &item_index);

                m->item_get_flag_function(
                    NULL,  
                    NULL,
                    item_index,  
                    &iflags, 
                    &iflags_ext);

                if ((item_index != m->highlighted_item) &&
                    !(iflags & UI_MENUITEM_STATE_DISABLED))
                {
                    gui_asyncdynamic_list_menu_goto_item(m, item_index);
#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
                    if (gui_list_menu_is_support_smooth_scrolling() && (!gui_asyncdynamic_list_error))
                    {
                        if ((m->highlighted_item == m->first_displayed_item) && (m->first_displayed_item > 0))
                        {
                            m->first_displayed_item -= 1;
                            m->last_displayed_item -= 1;
                        }
                        else if ((m->highlighted_item == m->last_displayed_item) && (m->last_displayed_item < (m->n_items - 1)))
                        {
                            m->first_displayed_item += 1;
                            m->last_displayed_item += 1;
                        }
                    }
#endif  /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN */
                    *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                }
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    gui_asyncdynamic_list_menu_translate_pen_position(m, x, y, &item_index);
                    if (item_index != m->highlighted_item && 
                        item_index >= m->first_displayed_item &&
                        item_index <= m->last_displayed_item)
                    {
                        if (g_pen_down_item_index == item_index)
                        {
                            U32 iflags, iflags_ext;
                            m->item_get_flag_function(
                                NULL,  
                                NULL,
                                item_index,  
                                &iflags, 
                                &iflags_ext);
                            if (!(iflags & UI_MENUITEM_STATE_DISABLED))
                            {
                                /* If MMI_PEN_EVENT_MOVE is not delivered before moving to this item */
                                gui_asyncdynamic_list_menu_goto_item(m, item_index);
#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
                                if (gui_list_menu_is_support_smooth_scrolling() && (!gui_asyncdynamic_list_error))
                                {
                                    if ((m->highlighted_item == m->first_displayed_item) && (m->first_displayed_item > 0))
                                    {
                                        m->first_displayed_item -= 1;
                                        m->last_displayed_item -= 1;
                                    }
                                    else if ((m->highlighted_item == m->last_displayed_item) && (m->last_displayed_item < (m->n_items - 1)))
                                    {
                                        cm = (gui_common_menuitem_base_struct*) m->common_item_data;
                                        menu_height = m->displayed_items * cm->height;
                                        if (gui_list_menu_is_highlight_item_two_line())
                                        {
                                            menu_height += m->height;
                                        }
                                
                                        if (m->height < menu_height + (m->height / 3))
                                        {
                                            if ((m->highlighted_item == m->last_displayed_item) && (m->highlighted_item < (m->n_items - 1)))
                                            {
                                                m->first_displayed_item += 1;
                                                m->last_displayed_item += 1;
                                            }
                                        }
                                    }
                                }
#endif  /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN */
                                *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                            }
                        }
                    }
                    else if (!pen_state->highlight_changed && item_index == m->highlighted_item)
                    {
                        *menu_event = GUI_LIST_PEN_ITEM_SELECTED;
                    }
                    else
                    {
                        *menu_event = GUI_LIST_PEN_NONE;
                    }
                }
                break;

            case MMI_PEN_EVENT_ABORT:
                /* Do nothing */
                break;

            default:
                MMI_ASSERT(0);
        }
    }

    if (gui_asyncdynamic_list_error)
    {
        *menu_event = GUI_LIST_PEN_NONE;
        return MMI_FALSE;
    }

    if (ret)
    {
        if (pen_state->first_highlighed_item != m->highlighted_item)
        {
            pen_state->highlight_changed = 1;
        }
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_TOUCH_SCREEN__


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen
 * DESCRIPTION
 *  Scroll the matrix menu vertically by pen.
 * PARAMETERS
 *  m                       [IN]        fixed matrix menu object
 *  first_displayed_row     [IN]        new row index
 *  menu_event              [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen(
                fixed_matrix_menu *m,
                S32 first_displayed_row,
                gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed_row > m->first_displayed_row + m->displayed_rows - 1)
    {
        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        gui_asyncdynamic_matrix_menu_goto_row(m, first_displayed_row);
        m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
    }
    else
    {
        last_displayed_row = first_displayed_row + m->displayed_rows - 1;
        MMI_DBG_ASSERT(last_displayed_row <= m->n_rows - 1);

        if (last_displayed_row < m->highlighted_row)
        {
            m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            gui_asyncdynamic_matrix_menu_goto_row(m, last_displayed_row);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            /* Scrolling without changing highlight (this case only  happens with pen support) */
            m->first_displayed_row = first_displayed_row;
            if (m->first_displayed_row > m->highlighted_row)
            {
                m->highlighted_row = m->first_displayed_row;
                m->highlighted_item = m->highlighted_row * m->n_columns + m->highlighted_column;
            }
            //if (m->first_displayed_row + m->displayed_rows - 1 <)
            if (gui_asyncdynamic_list_error == 0)
            {   
                if (load_chunk_asyncdynamic_item_buffer
                    (m->first_displayed_row * m->n_columns, m->displayed_rows * m->displayed_columns))
                {
                    gui_asyncdynamic_matrix_menu_switch_highlighted_item(m, -1);                    
                }
                else
                {
                    gui_asyncdynamic_list_error = 1;
                }
            }

            *menu_event = GUI_MATRIX_PEN_NEED_REDRAW;
        }
    }
    if (gui_asyncdynamic_list_error)
    {
        *menu_event = GUI_MATRIX_PEN_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_handle_pen_position
 * DESCRIPTION
 *  Handle the pen event (down/move/up), go to the menu item, and set the menu event.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  pen_event       [IN]        pen event. Only MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_MOVE, MMI_PEN_EVENT_UP is supported
 *  menu_event      [OUT]       pen event result
 *  index_of_item   [OUT]       the index of item which pen event happen on
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_asyncdynamic_matrix_menu_handle_pen_position(
                fixed_matrix_menu *m,
                S32 x,
                S32 y,
                mmi_pen_event_type_enum pen_event,
                gui_matrix_pen_enum *menu_event,
                S32 *index_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * Because the sampling rate of Pen Move events is not very high on hardware, 
     * * we might "jump" to a menu item aparted from the last highlighted menu item.
     */

    /* FIXME. we do not handle the case that hilighted menu item has bigger size, but it is usually okay */

    S32 xoff, yoff;
    S32 width, height;
    S32 iwidth, iheight;
    S32 new_row, new_column, item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define COMPUTE_NEW_ROW()  do {                                            \
      if (y < yoff)                                                           \
         new_row = m->first_displayed_row;                                    \
      else                                                                    \
         new_row = m->first_displayed_row + ((y - yoff) / (iheight + yoff));  \
      if (new_row > m->first_displayed_row + m->displayed_rows - 1)           \
         new_row = m->first_displayed_row + m->displayed_rows - 1;            \
   } while (0)

#define COMPUTE_NEW_COLUMN() do {                                                \
      if (x < xoff)                                                                 \
         new_column = m->first_displayed_column;                                    \
      else                                                                          \
         new_column = m->first_displayed_column + ((x - xoff) / (iwidth + xoff));   \
      if (new_column > m->first_displayed_column + m->displayed_columns - 1)        \
         new_column = m->first_displayed_column + m->displayed_columns - 1;         \
   } while (0)

    y -= m->y;
    x -= m->x;
    iwidth = m->item_width;
    iheight = m->item_height;
    width = m->width;
    height = m->height;
    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        width -= m->vbar.width;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        height -= m->hbar.height;
    }
    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);

    MMI_DBG_ASSERT(pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_MOVE || pen_event == MMI_PEN_EVENT_UP);

    /* These asumptions are mandatory */
    MMI_DBG_ASSERT(m->first_displayed_row >= 0 && m->first_displayed_column >= 0);

    if (y < 0)  /* Scroll up */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_row == 0)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_row = m->first_displayed_row - 1;

            COMPUTE_NEW_COLUMN();

            item_index = new_row * m->n_columns + new_column;

            m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
            gui_asyncdynamic_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            *index_of_item = item_index;
        }
    }
    else if (x < 0) /* Scroll left */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_column == 0)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_column = m->first_displayed_column - 1;

            COMPUTE_NEW_ROW();

            item_index = new_row * m->n_columns + new_column;

            m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
            gui_asyncdynamic_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            *index_of_item = item_index;
        }
    }
    else if (y >= height)   /* Scroll down */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_row == m->n_rows - m->displayed_rows)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_row = m->first_displayed_row + m->displayed_rows;

            COMPUTE_NEW_COLUMN();

            item_index = new_row * m->n_columns + new_column;

            if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
            {
                m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
                gui_asyncdynamic_matrix_menu_goto_item(m, item_index);
                m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;

                *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
                *index_of_item = item_index;
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
                *index_of_item = -1;
            }
        }
    }
    else if (x >= width)    /* Scroll right */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_column == m->n_columns - m->displayed_columns)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_column = m->first_displayed_column + m->displayed_columns;

            COMPUTE_NEW_ROW();

            item_index = new_row * m->n_columns + new_column;

            if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
            {
                m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
                gui_asyncdynamic_matrix_menu_goto_item(m, item_index);
                m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;

                *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
                *index_of_item = item_index;
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
                *index_of_item = -1;
            }
        }

    }
    else
    {
        S32 act_x = 0, act_y = 0;

        act_x = xoff * (m->displayed_columns) + (m->displayed_columns) * m->item_width;
        act_y = yoff * (m->displayed_rows) + (m->displayed_rows) * m->item_height;

        if (x > act_x || y > act_y)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
            return;
        }

        COMPUTE_NEW_ROW();
        COMPUTE_NEW_COLUMN();

        item_index = new_row * m->n_columns + new_column;
        if (item_index < m->n_items && item_index != m->highlighted_item)
        {
            gui_asyncdynamic_matrix_menu_goto_item(m, item_index);
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            *index_of_item = item_index;
        }
        else
        {
            if (pen_event == MMI_PEN_EVENT_UP)
            {
                if (m->pen_state.highlight_changed || (item_index >= m->n_items))
                {
                    *menu_event = GUI_MATRIX_PEN_NONE;
                    if (m->pen_state.highlight_changed && (item_index < m->n_items))
                    {
                        *index_of_item = m->highlighted_item;
                    }
                    else
                    {
                        *index_of_item = -1;
                    }
                }
                else
                {
                    *menu_event = GUI_MATRIX_PEN_ITEM_SELECTED;
                    *index_of_item = m->highlighted_item;
                }
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
                if (pen_event == MMI_PEN_EVENT_DOWN)
                {
                    if (item_index == m->highlighted_item)
                    {
                        *index_of_item = item_index;
                    }
                    else
                    {
                        *index_of_item = -1;
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_asyncdynamic_matrix_menu_translate_pen_event
 * DESCRIPTION
 *  Translate the pen events occured in the matrix menu.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  pen_event       [IN]        pen event type
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  menu_event      [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_asyncdynamic_matrix_menu_translate_pen_event(
        fixed_matrix_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    gui_matrix_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    S32 item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    *menu_event = GUI_MATRIX_PEN_NONE;

    if (m->flags & UI_MATRIX_MENU_DISABLE_PEN)
    {
        return MMI_FALSE;
    }

    if (gui_asyncdynamic_list_error)
    {
        return MMI_FALSE;
    }

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_event != MMI_PEN_EVENT_ABORT && pen_state->pen_on_vertical_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (m->pen_scroll_delay_time > 0)
            {
                gui_asyncdyamic_matrix_start_scroll_timer(m, scrollbar_param._u.i);
            }
            else
            {
                gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
            }     
        }
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    if ((m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR) &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &m->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_vertical_scrollbar = 1;
                        pen_state->pen_on_horizontal_scrollbar = 0;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            if (m->pen_scroll_delay_time > 0)
                            {
                                gui_asyncdyamic_matrix_start_scroll_timer(m, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                            }  
                            //gui_asyncdynamic_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else
                    {
                        pen_state->pen_on_vertical_scrollbar = 0;
                        gui_asyncdynamic_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_DOWN, menu_event, &item_index);
                        if (item_index >= 0)
                        {
                            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                        }
                    }

                    pen_state->first_highlighed_item = m->highlighted_item;
                    pen_state->highlight_changed = 0;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_MOVE:
                gui_asyncdynamic_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_MOVE, menu_event, &item_index);
                break;

            case MMI_PEN_EVENT_UP:
                gui_asyncdynamic_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_UP, menu_event, &item_index);
                break;

            case MMI_PEN_EVENT_LONG_TAP:
                /* Do nothing */
                break;

            case MMI_PEN_EVENT_REPEAT:
                /* Do nothing */
                break;

            case MMI_PEN_EVENT_ABORT:
                /* Do nothing */
                break;

            default:
                MMI_ASSERT(0);

        }
    }

    if (gui_asyncdynamic_list_error)
    {
        *menu_event = GUI_MATRIX_PEN_NONE;
        return MMI_FALSE;
    }

    if (ret)
    {
        if (pen_state->first_highlighed_item != m->highlighted_item)
        {
            pen_state->highlight_changed = 1;
        }
        m->last_highlighted_item = -1;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  gui_asyncdynamic_matrix_menu_set_pen_scroll_delay
* DESCRIPTION
*  Set the delay time that menu scrolling after scrollbar is scrolled by pen.
*  
*  Typically used in dynamic and asyncdynamic list or matrix menu because it need to load
*  data when menu is scrolled.
*  
*  THE SCROLL DELAY IS IMPLEMENTED IN DYNAMIC AND ASYNCDYNAMIC LIST OR MATRIX ONLY.
*  THIS IS DUMMY FUNCTION FOR API CONSISTENCY.
* PARAMETERS
*  m               [IN]        fixed list menu object
*  delay_time      [IN]        time in milliseconds
* RETURNS
*  void
*****************************************************************************/
void gui_asyncdynamic_matrix_menu_set_pen_scroll_delay(fixed_matrix_menu *m, S32 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(delay_time < (S32) 0x0000FFFF);
    m->pen_scroll_delay_time = delay_time;
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/*****************************************************************************
* FUNCTION
*  gui_asyncdynamic_list_menu_goto_item_without_change_highlight
* DESCRIPTION
*  
* PARAMETERS
*  m                        [IN]        fixed list menu object
*  first_displayed      [IN]        the first displayed item
* RETURNS
*  void
*****************************************************************************/
static void gui_asyncdynamic_list_menu_goto_item_without_change_highlight(fixed_list_menu * m,S32 first_displayed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_height, list_height, iheight, iwidth, highlighted_item;
    U8 done, already_out_of_screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    gui_asyncdynamic_list_abort_scroll_timer();
#endif

    if ((first_displayed < 0) || (first_displayed > m->n_items - 1))
    {
        return;
    }

    if (first_displayed == m->first_displayed_item)
    {
        return;
    }

    
    list_height = m->height;
    total_height = 0;
    done = 0;
    already_out_of_screen = 0;
    highlighted_item = m->highlighted_item;
    if (highlighted_item < m->first_displayed_item || highlighted_item > m->last_displayed_item)
    {
        already_out_of_screen = 1;
    }

    m->first_displayed_item = first_displayed;

    /* Re-compute last_displayed_item */
    for (i = m->first_displayed_item; i < m->n_items && (!done); i++)
    {
        if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
        {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
        }

        m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
    
        total_height += iheight;

        if (total_height > list_height)
        {
            done = 1;
            m->last_displayed_item = i - 1;
        }
    }
    m->current_displayed_item = -1;

    /* Check if in the last page */
    if (total_height <= list_height)
    {
        total_height = 0;
        for (i = m->n_items - 1; (i >= 0) && (!done); i--)
        {
            if (((fixed_icontext_list_menuitem*)m->common_item_data)->ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT)
            {
                if (i == m->highlighted_item)
                {
                    m->current_displayed_item = -1;
                }
                else
                {
                    m->current_displayed_item = i;
                }
            } 
    
            m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
    
            total_height += iheight;

            if (total_height > list_height)
            {
                if (m->first_displayed_item > i)
                {
                    done = 1;
                    m->first_displayed_item = i + 1;
                    m->last_displayed_item = m->n_items - 1;
                }
                break;
            }
        }
        m->current_displayed_item = -1;
        if (total_height <= list_height)
        {
            m->first_displayed_item = 0;
            m->last_displayed_item = m->n_items - 1;
        }
    }
        
    if (highlighted_item >= m->first_displayed_item &&
        highlighted_item <= m->last_displayed_item)
    {
        if (g_gui_async_list_update_callback && !mmi_frm_in_exit_hdlr_proc())
        {
            g_gui_async_list_update_callback(highlighted_item);
        }
    }

    if (gui_asyncdynamic_list_error == 0 &&
        !load_chunk_asyncdynamic_item_buffer
        (m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2))
    {
        gui_asyncdynamic_list_error = 1;
    }

    if (highlighted_item <= m->last_displayed_item && (highlighted_item >= m->first_displayed_item))
    {
        gui_asyncdynamic_list_menu_switch_highlighted_item(m, -1);
    }
    else if (!already_out_of_screen)
    {
        /* highglight item is out of current screen */
        gui_fixed_icontext_list_menuitem_stop_scroll();
        gui_pop_up_description_stop_scroll();
    }
}
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */


