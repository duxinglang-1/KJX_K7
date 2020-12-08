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
 *  gui_dynamic_menus.c
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
#include "MMI_Features.h"
#include "gui_config.h"
#include "gui_dynamic_menus.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_categories_util.h"
#include "gdi_include.h"
#include "gui_touch_feedback.h"
#include "gd_include.h"
#include "MMIDataType.h"
#include "gui_fixed_menus.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gdi_datatype.h"
#include "gui.h"
#include "wgui_fixed_menus.h"
#include "lcd_sw_inc.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "gui_switch.h"
#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif
#include "gui_scrollbars.h"
#include "gui_effect_oem.h"
#include "gui_fixed_menuitems.h"
#include "CustThemesRes.h"
#include "wgui.h"
#include "wgui_draw_manager.h"
#include "gdi_const.h"
#include "gui_themes.h"
#include "gui_data_types.h"
#include "string.h"
#include "mmi_frm_input_gprot.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
static void gui_dynamic_list_menu_goto_item_without_change_highlight(fixed_list_menu *m, S32 first_displayed_item);
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */

#ifdef __MMI_TOUCH_SCREEN__
static void gui_dyamic_list_menu_scroll_timer_hdlr(void);
static void gui_dynamic_list_menu_scroll_by_pen(fixed_list_menu *m, S32 first_displayed, gui_list_pen_enum *menu_event);
static void gui_dyamic_list_start_scroll_timer(fixed_list_menu *m, S32 value);
static void gui_dynamic_list_menu_get_menuitem_position(fixed_list_menu *m, S32 item_index, S32 *x, S32 *y);

#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
static void gui_dynamic_matrix_abort_scroll_timer(void);
static void gui_dyamic_matrix_menu_scroll_timer_hdlr(void);
static void gui_dyamic_matrix_start_scroll_timer(fixed_matrix_menu *m, S32 value);
static void gui_dynamic_matrix_menu_vertical_scroll_by_pen(
                fixed_matrix_menu *m,
                S32 first_displayed_row,
                gui_matrix_pen_enum *menu_event);
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__

static fixed_list_menu *gui_pen_scroll_dynamic_menu = NULL;
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
static fixed_matrix_menu *gui_pen_scroll_dynamic_matrix_menu = NULL;
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
extern S32 g_pen_down_item_index;
extern gdi_handle g_gui_ssp_static_layer;
extern MMI_BOOL g_current_display_half_menuitem;
extern S32 gui_asyncdynamic_list_error;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_switch_highlighted_item
 * DESCRIPTION
 *  Switch from the old highlighted item index to the new highlighted item.
 * PARAMETERS
 *  m                       [IN]        dynamic list menu object          
 *  last_highlighted_item   [IN]        old highlighted menu item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            if (in_dynamic_item_buffer(last_highlighted_item))
            {
                m->item_remove_highlight_function(
                    get_dynamic_item_from_buffer(last_highlighted_item),
                    m->common_item_data);
            }
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_event_current_selected_callback_function = m->pen_event_default_selected_callback_function;
    #endif 
        m->item_highlighted(m->highlighted_item);
    }
}


#ifdef __MMI_TOUCH_SCREEN__

/* 
 * Because loading data takes some time (depending on the applications using dynamic list), 
 * we use a timer to reduce gui_dynamic_list_menu_scroll_by_pen().  
 */

#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  gui_dyamic_matrix_menu_scroll_timer_hdlr
 * DESCRIPTION
 *  Scrolling timer handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dyamic_matrix_menu_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_matrix_menu *m = gui_pen_scroll_dynamic_matrix_menu;
    gui_matrix_pen_enum menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_dynamic_matrix_menu = NULL;

    if (!m)
    {
        return;
    }

    //gui_dynamic_matrix_menu_scroll_by_pen(m, m->pen_scroll_delay_time, &menu_event);
    gui_dynamic_matrix_menu_vertical_scroll_by_pen(m, m->pen_scroll_after_delay, &menu_event);
    if (menu_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED || menu_event == GUI_MATRIX_PEN_NEED_REDRAW)
    {
        gui_lock_double_buffer();
        gui_show_dynamic_matrix_menu(&MMI_fixed_matrix_menu);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_matrix_menu.x,
            MMI_fixed_matrix_menu.y,
            MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
            LCD_HEIGHT - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_abort_scroll_timer
 * DESCRIPTION
 *  Abort scrolling timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dynamic_matrix_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_dynamic_matrix_menu = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dyamic_matrix_start_scroll_timer
 * DESCRIPTION
 *  Start scrolling timer.
 * PARAMETERS
 *  m       [IN]        dynamic matrix menu object         
 *  value   [IN]        item index to scroll to
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dyamic_matrix_start_scroll_timer(fixed_matrix_menu *m, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(!gui_pen_scroll_dynamic_matrix_menu || gui_pen_scroll_dynamic_matrix_menu == m);

    m->pen_scroll_after_delay = value;
    gui_pen_scroll_dynamic_matrix_menu = m;

    gui_cancel_timer(gui_dyamic_matrix_menu_scroll_timer_hdlr);
    gui_start_timer(m->pen_scroll_delay_time, gui_dyamic_matrix_menu_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_dynamic_matrix_abort_scroll_timer);
}
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
 
/*****************************************************************************
 * FUNCTION
 *  gui_dyamic_list_menu_scroll_timer_hdlr
 * DESCRIPTION
 *  Scrolling timer handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dyamic_list_menu_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_list_menu *m = gui_pen_scroll_dynamic_menu;
    gui_list_pen_enum menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_dynamic_menu = NULL;

    if (!m)
    {
        return;
    }

    gui_dynamic_list_menu_scroll_by_pen(m, m->pen_scroll_after_delay, &menu_event);

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
 *  gui_dynamic_list_abort_scroll_timer
 * DESCRIPTION
 *  Abort scrolling timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_dynamic_menu = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dyamic_list_start_scroll_timer
 * DESCRIPTION
 *  Start scrolling timer.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object         
 *  value   [IN]        item index to scroll to
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dyamic_list_start_scroll_timer(fixed_list_menu *m, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(!gui_pen_scroll_dynamic_menu || gui_pen_scroll_dynamic_menu == m);

    m->pen_scroll_after_delay = value;
    gui_pen_scroll_dynamic_menu = m;

    gui_cancel_timer(gui_dyamic_list_menu_scroll_timer_hdlr);
    gui_start_timer(m->pen_scroll_delay_time, gui_dyamic_list_menu_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_dynamic_list_abort_scroll_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_translate_pen_position
 * DESCRIPTION
 *  Get item index from the pen y coordinate.
 * PARAMETERS
 *  m           [IN]        dynamic list menu object         
 *  y           [IN]        y      
 *  item_index  [OUT]       penned item index
 * RETURNS
 *  Return MMI_TRUE if y is within the menu; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_dynamic_list_menu_translate_pen_position(fixed_list_menu *m, S32 y, S32 *item_index)
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
    y -= m->y;
    if (m->n_items <= 0)
    {
        *item_index = 0;
        /* ret is false */
    }
    else if (y < 0)
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
        /* ret is false */
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
        /* ret is false */
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
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            /* Use null because menu item might not be loaded yet */
            m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > y)
            {
                *item_index = i;
                ret = MMI_TRUE;
                break;
            }
        }
        m->current_displayed_item = -1;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_get_menuitem_position
 * DESCRIPTION
 *  Get menu item (x1, y1) by its index.
 * PARAMETERS
 *  m           [IN]        dynamic list menu object         
 *  item_index  [IN]        item index
 *  x           [OUT]       x1 of the item  
 *  y           [OUT]       y1 of the item 
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dynamic_list_menu_get_menuitem_position(fixed_list_menu *m, S32 item_index, S32 *x, S32 *y)
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
#endif
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
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
        /* Use null because menu item might not be loaded yet */
        m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (i + 1 == item_index)
        {
            *y = total_height;
            return;
        }
    }
    *y = total_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_scroll_by_pen
 * DESCRIPTION
 *  Scroll the menu by pen.
 * PARAMETERS
 *  m                   [IN]        dynamic list menu object       
 *  first_displayed     [IN]        first displayed item index
 *  menu_event          [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dynamic_list_menu_scroll_by_pen(
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
    gui_dynamic_list_menu_goto_item_without_change_highlight(m, first_displayed);
    *menu_event = GUI_LIST_PEN_NEED_REDRAW;
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    if (first_displayed > m->highlighted_item)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_dynamic_list_menu_goto_item(m, first_displayed);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
    }
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    else if (first_displayed == m->highlighted_item && m->first_displayed_offset > 0)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_dynamic_list_menu_goto_item(m, first_displayed + 1);
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
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 

            /* Use null because menu item might not be loaded yet */
            m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > m->height)
            {
                last_displayed = i - 1;
                break;
            }
        }

        if (last_displayed < m->highlighted_item)
        {
            m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            gui_dynamic_list_menu_goto_item(m, last_displayed);
            m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            m->first_displayed_item = first_displayed;
            m->last_displayed_item = last_displayed;
            /* Handle this in similar way to dynamic_list_goto_item_no_redraw() */
            if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
            {
                flush_dynamic_item_buffer_before_load_chunk();
            }
            load_chunk_dynamic_item_buffer(
                m->first_displayed_item,
                m->last_displayed_item - m->first_displayed_item + 2);
            gui_dynamic_list_menu_switch_highlighted_item(m, -1);
            *menu_event = GUI_LIST_PEN_NEED_REDRAW;
        }
    }
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    m->flags = old_flags;
}

#endif /* __MMI_TOUCH_SCREEN__ */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/*
 * NOTE: we use load_chunk_dynamic_item_buffer from 
 * first_displayed_item to (m->last_displayed_item + 1).
 * It's because some UI functions access data of (m->last_displayed_item + 1).
 *
 */

/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted menu item.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_locate_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_DYNAMIC;
    gui_list_menu_locate_highlighted_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the menu item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_locate_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
    {
        /*
         * FIXME: __MMI_UI_HINTS_IN_MENUITEM__ is not supported here.
         * UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA is used only in Category 185.
         */
		if (!in_dynamic_item_buffer(m->highlighted_item))
		{
			gui_dynamic_list_menu_locate_highlighted_item(m);
		}
        if (m->highlighted_item < m->first_displayed_item)
        {
            /*
             * Call gui_dynamic_list_menu_locate_highlighted_item() because 
             * * we need to load data from first_displayed_item to last_displayed_item
             * * We do not want to duplicate the code of computing last_displayed_item.
             */
            m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
            gui_dynamic_list_menu_locate_highlighted_item(m);
            m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        }
    }
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    else if (m->highlighted_item <= m->first_displayed_item)
    {
        if (m->first_displayed_offset > 0 && m->highlighted_item != 0)
        {
            m->first_displayed_item = m->highlighted_item - 1;
        }
        else
        {
            m->first_displayed_item = m->highlighted_item;
            m->first_displayed_offset = 0;
        }
        load_chunk_dynamic_item_buffer(m->first_displayed_item, 1);
    }
#else
    else if (m->highlighted_item < m->first_displayed_item)
    {
        m->first_displayed_item = m->highlighted_item;
        load_chunk_dynamic_item_buffer(m->highlighted_item, 1);
    }
#endif
#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
    else
    {
        if (m->highlighted_item == m->last_displayed_item - 1)
        {
            m->first_displayed_item = 0;
            gui_list_menu_locate_item_compute_first(m);
            /* Load one more item because it might be accessed in gui_show_dynamic_list_menu() */
            load_chunk_dynamic_item_buffer(m->first_displayed_item, 2);
        }
    }
#endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_locate_next_item
 * DESCRIPTION
 *  Locate the menu item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_locate_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) || defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
    if (m->highlighted_item >= m->last_displayed_item)
#else /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
    if (m->highlighted_item > m->last_displayed_item)
#endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
    {
        S32 old_first_displayed_item;

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (m->last_displayed_offset > 0 && m->highlighted_item != m->n_items - 1)
        {
            m->last_displayed_item = m->highlighted_item + 1;
        }
        else
        {
            m->last_displayed_item = m->highlighted_item;
            m->last_displayed_offset = 0;
        }
#else
        m->last_displayed_item = m->highlighted_item;
#endif
        old_first_displayed_item = m->first_displayed_item;
        m->first_displayed_item = 0;
        gui_list_menu_locate_item_compute_first(m);

        /* Load one more item because it might be accessed in gui_show_dynamic_list_menu() */
        if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
        {
            flush_dynamic_item_buffer_before_load_chunk();
            load_chunk_dynamic_item_buffer(
                m->first_displayed_item,
                m->last_displayed_item - m->first_displayed_item + 2);
        }
        else if (m->first_displayed_item < old_first_displayed_item)
        {
            load_chunk_dynamic_item_buffer(
                m->first_displayed_item,
                m->last_displayed_item - m->first_displayed_item + 2);
        }
        else
        {
            load_chunk_dynamic_item_buffer(m->highlighted_item, 2);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item by its index.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_goto_item(fixed_list_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_DYNAMIC;
    gui_list_menu_goto_item(m, i);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_goto_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_DYNAMIC;
    gui_list_menu_goto_next_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_list_menu_goto_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_DYNAMIC;
    gui_list_menu_goto_previous_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dynamic_list_menu_draw_bg
 * DESCRIPTION
 *  Helper functoin of gui_show_dynamic_list_menu.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dynamic_list_menu_draw_bg(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f, MMI_BOOL show_scrollbar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_GRID_LINE__	
    S32 iwidth = 0, iheight = 0;
    gdi_handle alpha_layer;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(x1, y1, x2, y2);

    if (!(m->flags & UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER) && (wgui_is_wallpaper_on_bottom() == MMI_TRUE))
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#ifdef __MMI_UI_LIST_GRID_LINE__
        if (!(m->flags & UI_LIST_MENU_DISABLE_GRID_LINE) && m->n_items > 0)
        {
            S32 line_height = 0, display_index, index, highlight_height, grid_x;
            void *item;
    
            iheight = 0;
            m->current_displayed_item = -1;

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            line_height -= m->first_displayed_offset;
#endif
            if (m->menu_style == GUI_MENU_TYPE_DYNAMIC)
            {
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
                if (in_dynamic_item_buffer(m->highlighted_item))
                {
                    item = get_dynamic_item_from_buffer(m->highlighted_item);
                }
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
                item = get_dynamic_item_from_buffer(m->highlighted_item);
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
            }
            else
            {
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
                if (in_asyncdynamic_item_buffer(m->highlighted_item))
                {
                    item = get_asyncdynamic_item_from_buffer(m->highlighted_item);
                }
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
                item = get_asyncdynamic_item_from_buffer(m->highlighted_item);
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
            }
            m->item_measure_function(item, m->common_item_data, &iwidth, &highlight_height);
    
            index = m->current_displayed_item;
            display_index = m->first_displayed_item;
    
            if (mmi_fe_get_r2l_state())
            {
                grid_x = x1 + GUI_MENUITEM_X2_GAP;
#ifndef __MMI_FTE_SUPPORT__
                if (show_scrollbar)
                {
                    grid_x = grid_x + m->vbar.width;
                }
                else
#endif /* __MMI_FTE_SUPPORT__ */
                {
                    grid_x += GUI_LIST_MENU_X2_GAP;
                }
            }
            else
            {
                grid_x = x1 + GUI_MENUITEM_X1_GAP;    
            }
    
#if !defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
            if (m->highlighted_item >= 1 || m->n_items == 1)
            {
                m->current_displayed_item = 0;
                m->item_measure_function(m->items[0], m->common_item_data, &iwidth, &iheight);
            }
            else if (m->n_items != 0)
            {
                m->current_displayed_item = 1;
                m->item_measure_function(m->items[1], m->common_item_data, &iwidth, &iheight);
            }
#else
            if (m->n_items != 0)
            {
                m->current_displayed_item = display_index;
                m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
            }
#endif
            if (iheight)
            {
                if (display_index == m->highlighted_item)
                {
                    line_height += y1 + highlight_height;
                }
                else
                {
                    line_height += y1 + iheight;
                }
                while (line_height < y2)
                {
                    if (MMI_fixed_list_menu.alpha_blend_layer_handle)
                    {
                        alpha_layer = MMI_fixed_list_menu.alpha_blend_layer_handle;
                    }
                    else 
                    {
                        alpha_layer = dm_get_scr_bg_layer();
                        if (alpha_layer == GDI_ERROR_HANDLE)
                        {
                            gdi_layer_get_active(&alpha_layer);
                        }
                    }
                    if (m->key_info != GUI_LIST_KEY_INFO_UP || display_index != m->highlighted_item)
                    {
                        U32 ret_flag = 0, ref_flag_next = 0;
                        U32 ret_flag_ext = 0, ref_flag_ext_next = 0;
    
                        if ((m->menu_style == GUI_MENU_TYPE_DYNAMIC || m->menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)&& 
                            g_gui_list_get_menuitem_flags && (display_index >= 0))
                        {
                            g_gui_list_get_menuitem_flags(display_index, &ret_flag, &ret_flag_ext);
                            if (display_index < m->n_items - 1)
                            {
                                g_gui_list_get_menuitem_flags(display_index + 1, &ref_flag_next, &ref_flag_ext_next);
                            }

                        }
                        if (!(ret_flag_ext & UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE) &&
                            !(ref_flag_ext_next & UI_MENUITEM_EXT_SHOW_SEPARATORLINE))
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
    
                    display_index++;
					//unimportant issues
					#ifndef __MMI_UI_MENU_SLIM__
                    if ((m->flags & UI_LIST_MENU_DISABLE_EXT_GRID_LINE) && (display_index > m->n_items - 1))
                    {
                        break;
                    }
                    #endif
                    if (display_index == m->highlighted_item)
                    {
                        line_height += highlight_height;
                    }
                    else
                    {
#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
                        m->current_displayed_item = display_index;
                        m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
#endif
                        line_height += iheight;
                    }
                }
            }
            m->current_displayed_item = index;
        }
#endif

    #if (defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__))
        if (gui_get_transparent_source_layer() == GDI_LAYER_EMPTY_HANDLE)
        {
            gui_set_transparent_source_layer(dm_get_scr_bg_layer());        /* should remove */
        }
    #endif /* (defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)) */ 
    }
    else
    {
    #if !defined(MT6205B) && !defined(MT6208)
        gui_draw_filled_area(x1, y1, x2, y2, f);
    #else /* !defined(MT6205B) && !defined(MT6208) */
        /* For low-end phone, disable list menu background can greately improve menu performance. 
           We use the color of filler to draw the background (typically white). */
        color c = f->c;
        gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(255, c.r, c.g, c.b));
    #endif /* !defined(MT6205B) && !defined(MT6208) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dynamic_list_menu_draw_items
 * DESCRIPTION
 *  Helper function for gui_show_dynamic_list_menu.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dynamic_list_menu_draw_items(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2, U8 disable_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y_offset;
    S32 total_height, counter, list_height;
    S32 i;
    S32 iwidth = 0, iheight = 0;
    U8 done = 0;
    void *item_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_height = m->height;
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    total_height = 0;
    counter = 0;
    m->current_displayed_item = -1;

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    total_height -= m->first_displayed_offset;
    m->last_displayed_offset = 0;
#endif
    for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
    {
        if (m->menu_style == GUI_MENU_TYPE_DYNAMIC)
        {
            item_p = get_dynamic_item_from_buffer(i);
        }
        else
        {
            item_p = get_asyncdynamic_item_from_buffer(i);
            if (i == m->highlighted_item)
            {
                ((fixed_icontext_list_menuitem_type*)item_p)->flags |= UI_MENUITEM_STATE_FOCUSSED;
            }
        }
        m->current_displayed_item = (i == m->highlighted_item) ? -1 : i;

        m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);

        y_offset = total_height;
        total_height += iheight;

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (i == m->first_displayed_item && m->first_displayed_offset > 0)
        {
            g_current_display_half_menuitem = MMI_TRUE;
            if (!disable_draw)
            {
                gui_push_and_set_clip(x1, y1, x2, y2);
                m->item_display_function(item_p, m->common_item_data, x1, y_offset + y1);
                gui_pop_clip();
            }
			//unimportant issues
			#ifndef __MMI_UI_MENU_SLIM__
            if (i == m->highlighted_item)
            {
                m->highlight_x = x1;
                m->highlight_y = y_offset + y1;
            }
			#endif
            counter++;
            g_current_display_half_menuitem = MMI_FALSE;
        }
        else
#endif
        if (total_height > list_height)
        {
            done = 1;
            if ( !disable_draw
                && (counter == 0)
            )
            {
                m->item_display_function(item_p, m->common_item_data, x1, y_offset + y1);
            }
//#ifdef __MMI_FTE_SUPPORT__
            if (!disable_draw && y_offset + y1 < y2)
            {
                g_current_display_half_menuitem = MMI_TRUE;
                gui_push_and_set_clip(x1, y1, x2, y2);
                m->item_display_function(item_p, m->common_item_data, x1, y_offset + y1);
                gui_pop_clip();
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
                m->last_displayed_offset = iheight - (total_height - list_height);
                if (i == m->first_displayed_item)
                {
                    m->last_displayed_offset = 0;
                }
                counter++;
#endif
                g_current_display_half_menuitem = MMI_FALSE;
            }
            if (i == m->highlighted_item)
            {
                m->highlight_x = x1;
                m->highlight_y = y_offset + y1;
            }
//#endif
        }
        else
        {
            if (!disable_draw)
            {
                if (i == m->highlighted_item)
                {
                    m->highlight_x = x1;
                    m->highlight_y = y_offset + y1;
                }

                m->item_display_function(item_p, m->common_item_data, x1, y_offset + y1);
            }
            counter++;
        }
    }

    m->current_displayed_item = -1;
    m->last_displayed_item = (counter == 0) ? m->first_displayed_item : m->first_displayed_item + counter - 1;
    m->displayed_items = counter;
}


/*****************************************************************************
 * FUNCTION
 *	gui_show_asyncdynamic_list_menu
 * DESCRIPTION
 *	Show the asyncdynamic menu.
 * PARAMETERS
 *	m		[IN]		asyncdynamic list menu object	  
 * RETURNS
 *	void
 *****************************************************************************/
void gui_show_dynamic_list_menu_int(fixed_list_menu *m, gui_menu_type_enum menu_style)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 x1, y1, x2, y2;
	UI_filled_area *f;
	U8 disable_draw = 0;
	
	MMI_BOOL show_scrollbar;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	m->menu_style = menu_style;//GUI_MENU_TYPE_ASYNCDYNAMIC;	
	
	if(menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	{
		if (gui_asyncdynamic_list_error)
		{
			/* Context is invalid, and screen is exiting */
			return;
		}	   


		/* invoke pre display callback */
		if (m->pre_display_function)
		{
			m->pre_display_function();
		}
	}
	
	if (m->flags & UI_LIST_MENU_DISABLE_DRAW)
	{
		disable_draw = 1;
	}

	gui_push_clip();
	gui_push_text_clip();

	x1 = m->x;
	y1 = m->y;
	x2 = x1 + m->width - 1;
	y2 = y1 + m->height - 1;

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
	if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
	{
		if ((m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
			((m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && (m->displayed_items >= m->n_items)))
		{
			f = m->focussed_without_sc_filler;
		}
		else
		{
			f = m->focussed_filler;
		}
	}
	else
#endif
	{
		f = m->normal_filler;
	}

	/* Check presence of scrollbar */
	show_scrollbar = gui_show_list_menu_check_scrollbar(m);

	gui_set_clip(x1, y1, x2, y2);

	if (!disable_draw && !(m->flags & UI_LIST_MENU_DISABLE_BACKGROUND))
	{
		gui_show_dynamic_list_menu_draw_bg(m, x1, y1, x2, y2, f, show_scrollbar);
	}

	if (m->n_items <= 0)
	{
		gui_pop_clip();
		gui_pop_text_clip();
		return;
	}

	/* Configure region of menu items */
	gui_show_list_menu_config_item_region(m, &x1, &x2, &y1, show_scrollbar);

	gui_show_dynamic_list_menu_draw_items(m, x1, y1, x2, y2, disable_draw);
	if(!disable_draw && show_scrollbar)//gui_show_list_menu_check_scrollbar(m))
		gui_show_list_menu_scrollbar(m, disable_draw);
	
	gui_pop_clip();
	gui_pop_text_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dynamic_list_menu
 * DESCRIPTION
 *  Show the dynamic menu.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dynamic_list_menu(fixed_list_menu *m)
{
   gui_show_dynamic_list_menu_int(m, GUI_MENU_TYPE_DYNAMIC);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dynamic_list_menu_no_draw
 * DESCRIPTION
 *  Calculate the first and the last displayed item indices.
 * PARAMETERS
 *  m       [IN]        dynamic list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dynamic_list_menu_no_draw(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_list_menu_no_draw(m);
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_list_menu_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the dynamic list menu.
 * PARAMETERS
 *  m           [IN]        dynamic list menu object         
 *  pen_event   [IN]        pen event type
 *  x           [IN]        pen x   
 *  y           [IN]        pen y
 *  menu_event  [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_dynamic_list_menu_translate_pen_event(
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
    gui_list_pen_enum menuitem_event;
    gui_pen_event_param_struct menuitem_param;
    S32 item_index;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
    gui_common_menuitem_base_struct *cm;
    S32 menu_height;
#endif /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN  */   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), 0, GUI_LIST_PEN_NONE);

    *menu_event = GUI_LIST_PEN_NONE;

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (m->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
            {
                gui_dyamic_list_start_scroll_timer(m, scrollbar_param._u.i);
            }
            else
            {
                gui_dynamic_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
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
        S32 item_x, item_y;

        gui_dynamic_list_menu_get_menuitem_position(m, m->highlighted_item, &item_x, &item_y);

        GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), m->highlighted_item, GUI_LIST_PEN_NONE);

        if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
        {
            flush_dynamic_item_buffer_before_load_chunk();
        }
        if (!in_dynamic_item_buffer(m->highlighted_item))
        {
            load_chunk_dynamic_item_buffer(m->highlighted_item, 1);
        }
        m->item_pen_function(
            get_dynamic_item_from_buffer(m->highlighted_item),
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
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    pen_state->handled_by_menu_item = 0;
                    pen_state->pen_on_scrollbar = 0;
                    pen_state->pen_down_state_box = 0;
                    g_pen_down_item_index = -1;
                    if (m->n_items <= 0)
                    {
                        /* In current design, scrollbar is hiden if m->n_items == 0 */
                        ret = MMI_FALSE;
                    }
                    else if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) &&
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
                                gui_dyamic_list_start_scroll_timer(m, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_dynamic_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                            }
                        }
                    }
                    else
                    {
                        if (gui_dynamic_list_menu_translate_pen_position(m, y, &item_index))
                        {
                            U32 iflags, iflags_ext, old_flags;
                            S32 item_x, item_y;

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
                                gui_dynamic_list_menu_goto_item(m, item_index);
                                m->flags = old_flags;
                                *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;

                                GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), item_index, GUI_LIST_PEN_HIGHLIGHT_CHANGED);                                
                            }

                            /* Even if highlight is changed, we still need to invoke menuitem pen handler */
                            gui_dynamic_list_menu_get_menuitem_position(m, item_index, &item_x, &item_y);
                            if (m->item_pen_function(
                                    get_dynamic_item_from_buffer(item_index),
                                    m->common_item_data,
                                    item_x,
                                    item_y,
                                    MMI_PEN_EVENT_DOWN,
                                    x,
                                    y,
                                    &menuitem_event,
                                    &menuitem_param))
                            {
                                if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
                                {
                                    menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
                                }
                                /* original menu_event could be GUI_LIST_PEN_HIGHLIGHT_CHANGED */
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
                if (!m->disable_move_highlight)
                {
                    gui_dynamic_list_menu_translate_pen_position(m, y, &item_index);
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
                    m->item_get_flag_function(NULL, NULL, item_index, &flags, &flags_ext);
                    if ((item_index != m->highlighted_item) && !(flags & UI_MENUITEM_STATE_DISABLED))
#else
                    if (item_index != m->highlighted_item)
#endif /* __MMI_UI_LIST_SKIP_DISABLED__ */
                    {
                        gui_dynamic_list_menu_goto_item(m, item_index);
#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
                        if (gui_list_menu_is_support_smooth_scrolling())
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
                if (!m->disable_up_select)
                {
                    if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                    {
                        gui_dynamic_list_menu_translate_pen_position(m, y, &item_index);
                        if (item_index != m->highlighted_item && 
                            item_index >= m->first_displayed_item &&
                            item_index <= m->last_displayed_item)
                        {
                            if (!m->disable_move_highlight)
                            {
                                if (g_pen_down_item_index == item_index)
                                {
                                    U32 flags, flags_ext;
                                    m->item_get_flag_function(
                                        m->items[item_index],  
                                        m->common_item_data,
                                        item_index,  
                                        &flags, 
                                        &flags_ext);
                                    if (!(flags & UI_MENUITEM_STATE_DISABLED))
                                    {
                                        /* If MMI_PEN_EVENT_MOVE is not delivered before moving to this item */
                                        gui_dynamic_list_menu_goto_item(m, item_index);
#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
                                        if (gui_list_menu_is_support_smooth_scrolling())
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
                        }
                        else if (pen_state->highlight_changed)
                        {
                            *menu_event = GUI_LIST_PEN_NONE;
                        }
                        else
                        {
                            *menu_event = GUI_LIST_PEN_ITEM_SELECTED;
                        }
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


#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/*****************************************************************************
* FUNCTION
*  gui_dynamic_list_menu_goto_item_without_change_highlight
* DESCRIPTION
*  goto the specify item without change highlight, even if the highlight is out of the screen
*
* PARAMETERS
*  m                            [IN]        fixed list menu object
*  first_displayed_item      [IN]       the first displayed item index
* RETURNS
*  void
*****************************************************************************/
static void gui_dynamic_list_menu_goto_item_without_change_highlight(fixed_list_menu *m, S32 first_displayed_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_height, list_height, iheight, iwidth, highlighted_item;
    U8 done, already_out_of_screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    gui_dynamic_list_abort_scroll_timer();
#endif

    if ((first_displayed_item < 0) || (first_displayed_item > m->n_items - 1))
    {
        return;
    }

    if (first_displayed_item == m->first_displayed_item)
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

    m->first_displayed_item = first_displayed_item;

    for (i = m->first_displayed_item; i < m->n_items && (!done); i++)
    {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 

        m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);

        total_height += iheight;
        
        if (total_height > list_height)
        {
            done = 1;
            m->last_displayed_item = i - 1;
        }
    }

    /* Check if in the last page */
    if (total_height <= list_height)
    {
        total_height = 0;
        for (i = m->n_items - 1; (i >= 0) && (!done); i--)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 

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
        if (total_height <= list_height)
        {
            m->first_displayed_item = 0;
            m->last_displayed_item = m->n_items - 1;
        }
    }
    
    if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
    {
        flush_dynamic_item_buffer_before_load_chunk();
    }

    load_chunk_dynamic_item_buffer(m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2);
    
    if (highlighted_item <= m->last_displayed_item && (highlighted_item >= m->first_displayed_item))
    {
        gui_dynamic_list_menu_switch_highlighted_item(m, -1);
    }
    else if (!already_out_of_screen)
    {
        /* highglight item is out of current screen */
        gui_fixed_icontext_menuitem_stop_scroll();
        gui_pop_up_description_stop_scroll();
    }
}
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */


#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted item in the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_locate_highlighted_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->highlighted_column = m->highlighted_item % m->n_columns;
    m->highlighted_row = m->highlighted_item / m->n_columns;
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
    if ((m->first_displayed_row + m->displayed_rows - 1) >= m->n_rows)
    {
        m->first_displayed_row = m->n_rows - m->displayed_rows;
        if (m->first_displayed_row < 0)
        {
            m->first_displayed_row = 0;
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
    if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
    {
        flush_dynamic_item_buffer_before_load_chunk();
    }
    load_chunk_dynamic_item_buffer(
        m->first_displayed_row * m->n_columns,
        m->displayed_rows * m->displayed_columns);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the previous item in the dynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_locate_previous_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
    {
        m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
        if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
        {
            m->first_displayed_row = (m->n_rows - m->displayed_rows);
        }
    }
    if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
    {
        flush_dynamic_item_buffer_before_load_chunk();
    }
    load_chunk_dynamic_item_buffer(
        m->first_displayed_row * m->n_columns, 
        m->n_columns);
}



/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_locate_next_item
 * DESCRIPTION
 *  Locate the next item in the dynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_locate_next_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
    {
        m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
        if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
        {
            m->first_displayed_row = (m->n_rows - m->displayed_rows);
        }
    }
    if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
    {
        flush_dynamic_item_buffer_before_load_chunk();
    }
    load_chunk_dynamic_item_buffer(
        (m->first_displayed_row + m->displayed_rows - 1) * m->n_columns, 
        m->n_columns);
}



/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_goto_next_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop_flag = 0;
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 
    if (m->highlighted_item >= (m->n_items - 1))
    {
        if (m->flags & UI_MATRIX_MENU_LOOP)
        {
            loop_flag = 1;
            m->highlighted_item = 0;
        }
        else
        {
            return;
        }
    }
    else
    {
        m->highlighted_item++;
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
            gui_dynamic_matrix_menu_locate_highlighted_item(m);
        }
        else
        {
            gui_dynamic_matrix_menu_locate_next_item(m);
        }
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(old_highlighted_item), m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_goto_previous_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop_flag = 0;
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */
    if (m->highlighted_item <= 0)
    {
        if (m->flags & UI_MATRIX_MENU_LOOP)
        {
            loop_flag = 1;
            m->highlighted_item = m->n_items - 1;
        }
        else
        {
            return;
        }
    }
    else
    {
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
            gui_dynamic_matrix_menu_locate_highlighted_item(m);
        }
        else
        {
            gui_dynamic_matrix_menu_locate_previous_item(m);
        }
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(old_highlighted_item), m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_row
 * DESCRIPTION
 *  Go to the item in the previous row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_goto_previous_row(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 locate_highlight = 0;
    U8 locate_previous = 0;
    S32 old_highlighted_item;
    S32 last_row_columns;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */
    old_highlighted_item = m->highlighted_item;
    last_row_columns = m->n_items % m->displayed_columns;

    /* Menu rotation */
    if (m->highlighted_row <= 0)
    {
        locate_highlight = 1;
        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
        if (m->highlighted_row == 0 &&
            last_row_columns &&
            m->flags & UI_MATRIX_MENU_VERTICAL_LOOP &&
            m->highlighted_column > last_row_columns - 1)
        {
            m->highlighted_column = last_row_columns - 1;
        }
        m->highlighted_row = m->n_rows - 1;

        /* To avoid the blcok cursor go to non-existed item. */
        m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;

        /* To support that a row is not full of items */
		m->first_displayed_row = m->highlighted_row - m->displayed_rows + 1;

        if (m->highlighted_item > (m->n_items - 1))
        {
            m->highlighted_row -= 1;
            m->highlighted_item -= m->n_columns;
        }
        m->first_displayed_row = m->highlighted_row - m->displayed_rows + 1;
        if (m->first_displayed_row < 0)
        {
            m->first_displayed_row = 0;
        }
    }
    else
    {
        m->highlighted_row--;
        if (m->highlighted_row < m->first_displayed_row)
        {
            locate_previous = 1;
            m->first_displayed_row = m->highlighted_row;
        }
    }
    
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (locate_highlight)
    {
        gui_dynamic_matrix_menu_locate_highlighted_item(m);
    }
    else if (locate_previous)
    {
        gui_dynamic_matrix_menu_locate_previous_item(m);
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(old_highlighted_item), m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_goto_next_row
 * DESCRIPTION
 *  Go to the item in the next row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_goto_next_row(fixed_matrix_menu *m)
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
    gui_dynamic_matrix_abort_scroll_timer();
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
        gui_dynamic_matrix_menu_locate_highlighted_item(m);
    }
    else if (locate_previous)
    {
        gui_dynamic_matrix_menu_locate_next_item(m);
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(old_highlighted_item), m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_goto_row
 * DESCRIPTION
 *  Go to the specified row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  r       [IN]        row index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_goto_row(fixed_matrix_menu *m, S32 r)
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
    gui_dynamic_matrix_abort_scroll_timer();
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

    gui_dynamic_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(old_highlighted_item), m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item by its index.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  i       [IN]        item index to be highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dynamic_matrix_menu_goto_item(fixed_matrix_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_matrix_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */
    if ((i < 0) || (i > (m->n_items - 1)))
    {
        return;
    }
    m->highlighted_item = i;
    gui_dynamic_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(old_highlighted_item), m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dynamic_matrix_menu
 * DESCRIPTION
 *  Display the dynamic matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dynamic_matrix_menu(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, xoff, yoff, width, height;
    UI_filled_area *f;
    S32 i, j, k, o;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 ix, iy, iwidth, iheight, ix2, iy2;
    U8 show_vbar = 0;
    fixed_icontext_menuitem_type* item_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }

    if (mmi_fe_get_r2l_state())
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

    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        f = m->focussed_filler;
    }
    else
    {
        f = m->normal_filler;
    }
    if (m->flags & UI_MATRIX_MENU_DISABLE_BACKGROUND)
    {
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

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }

    if (m->n_items == 0)
    {
        return;
    }

    if (!mmi_fe_get_r2l_state() && show_vbar)
    {
        x2 -= m->vbar.width - 1;
    }
    
    width = x2 - x1 + 1;
    height = y2 - y1 + 1;
    iwidth = m->item_width;
    iheight = m->item_height;

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);

    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);
    iy = y1 + yoff;
    for (j = 0; j < m->displayed_rows; j++)
    {
        ix = x1 + xoff;
        o = (m->first_displayed_row + j) * m->n_columns;
        for (i = 0; i < m->displayed_columns; i++)
        {
            k = o + (m->first_displayed_column + i);
            m->current_display_item = k;
            item_p = get_dynamic_item_from_buffer(k);
            if (k > (m->n_items - 1))
            {
                break;
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
            m->item_display_function(item_p, m->common_item_data, ix, iy);
            gdi_layer_pop_clip();
            ix += iwidth + xoff;
        }
        iy += iheight + yoff;
    }
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
    if (show_vbar)
		gui_matrix_menu_show_vscrollbar(m);

}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dynamic_matrix_menu_specific_item
 * DESCRIPTION
 *  Display last hightlight and current highlight in dynamic matrix menu.
 * PARAMETERS
 *  m                  [IN]    Fixed matrix menu object
 *  last_highlight     [IN]    The index of last highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dynamic_matrix_menu_specific_items(fixed_matrix_menu *m, S32 last_highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, xoff, yoff, width, height;
    UI_filled_area *f;
    S32 i, j, k, o;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 ix, iy, iwidth, iheight, ix2, iy2;
    U8 show_vbar = 0;
    fixed_icontext_menuitem_type* item_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }

    if (mmi_fe_get_r2l_state())
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

    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        f = m->focussed_filler;
    }
    else
    {
        f = m->normal_filler;
    }

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }

    if (m->n_items == 0)
    {
        return;
    }

    if (!mmi_fe_get_r2l_state() && show_vbar)
    {
        x2 -= m->vbar.width - 1;
    }

    width = x2 - x1 + 1;
    height = y2 - y1 + 1;
    iwidth = m->item_width;
    iheight = m->item_height;

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);
    iy = y1 + yoff;
    for (j = 0; j < m->displayed_rows; j++)
    {
        ix = x1 + xoff;
        o = (m->first_displayed_row + j) * m->n_columns;
        for (i = 0; i < m->displayed_columns; i++)
        {
            k = o + (m->first_displayed_column + i);
            m->current_display_item = k;
            item_p = get_dynamic_item_from_buffer(k);
            if (k > (m->n_items - 1))
            {
                break;
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
            gdi_layer_pop_clip();
            ix += iwidth + xoff;
        }
        iy += iheight + yoff;
    }

    if (show_vbar)
	gui_matrix_menu_show_vscrollbar(m);

    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_vertical_scroll_by_pen
 * DESCRIPTION
 *  Scroll the matrix menu vertically by pen.
 * PARAMETERS
 *  m                       [IN]        fixed matrix menu object
 *  first_displayed_row     [IN]        new row index
 *  menu_event              [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dynamic_matrix_menu_vertical_scroll_by_pen(
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
    if (first_displayed_row > m->highlighted_row)
    {
        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        gui_dynamic_matrix_menu_goto_row(m, first_displayed_row);
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
            gui_dynamic_matrix_menu_goto_row(m, last_displayed_row);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            /* Scrolling without changing highlight (this case only  happens with pen support) */
            m->first_displayed_row = first_displayed_row;

            /* Although highlighted item stays the same, we need to stop and restart the animation */
            m->item_remove_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);
            m->item_highlight_function(get_dynamic_item_from_buffer(m->highlighted_item), m->common_item_data);

            *menu_event = GUI_MATRIX_PEN_NEED_REDRAW;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dynamic_matrix_menu_handle_pen_position
 * DESCRIPTION
 *  Handle the pen event (down/move/up), go to the menu item, and set the menu event.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  pen_event       [IN]        pen event. Only MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_MOVE, MMI_PEN_EVENT_UP is supported
 *  menu_event      [OUT]       pen event result
 *  item_of_index   [OUT]       the index of menu item which pen event happen on
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dynamic_matrix_menu_handle_pen_position(
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
            gui_dynamic_matrix_menu_goto_item(m, item_index);
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
            gui_dynamic_matrix_menu_goto_item(m, item_index);
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
                gui_dynamic_matrix_menu_goto_item(m, item_index);
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
                gui_dynamic_matrix_menu_goto_item(m, item_index);
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
            gui_dynamic_matrix_menu_goto_item(m, item_index);
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
 *  gui_dynamic_matrix_menu_translate_pen_event
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
MMI_BOOL gui_dynamic_matrix_menu_translate_pen_event(
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

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_vertical_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (m->pen_scroll_delay_time > 0)
            {
                gui_dyamic_matrix_start_scroll_timer(m, scrollbar_param._u.i);
            }
            else
            {
                gui_dynamic_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
            }          
        }
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (m->n_items <= 0)
                {
                    /* In current design, scrollbar is hiden if m->n_items == 0 */
                    ret = MMI_FALSE;
                }
                else if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
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
                                gui_dyamic_matrix_start_scroll_timer(m, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_dynamic_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);       
                            }
                        }
                    }
                    else
                    {
                        pen_state->pen_on_vertical_scrollbar = 0;
                        gui_dynamic_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_DOWN, menu_event, &item_index);
                        if (item_index >= 0)
                        {
                            //only give feedback when pen down on menu item
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
                gui_dynamic_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_MOVE, menu_event, &item_index);
                break;

            case MMI_PEN_EVENT_UP:
                gui_dynamic_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_UP, menu_event, &item_index);
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
*  gui_dynamic_matrix_menu_set_pen_scroll_delay
* DESCRIPTION
*  Set the delay time that menu scrolling after scrollbar is scrolled by pen.
*  
*  Typically used in dynamic and asyncdynamic list or matrix menu because it need to load
*  data when menu is scrolled.
*  
*  THE SCROLL DELAY IS IMPLEMENTED IN DYNAMIC AND ASYNCDYNAMIC LIST ONLY.
*  THIS IS DUMMY FUNCTION FOR API CONSISTENCY.
* PARAMETERS
*  m               [IN]        fixed list menu object
*  delay_time      [IN]        time in milliseconds
* RETURNS
*  void
*****************************************************************************/
void gui_dynamic_matrix_menu_set_pen_scroll_delay(fixed_matrix_menu *m, S32 delay_time)
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

#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__


