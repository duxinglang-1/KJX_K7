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
 *  gui_toolbar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Toolbar - UI component
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#include "MMI_include.h"

#ifdef __MMI_OP12_TOOLBAR__
#include "gui_themes.h"
#include "gui_toolbar.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menuitems.h"
#include "gui_font_size.h"
#include "wgui_categories_idlescreen.h"

/* Macro */
#define GUI_TOOLBAR_BAR_INDENT  15
#define GUI_TOOLBAR_BAR_GAP     2
#define GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES    8
#define GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMER    5

/* Local variables */
static gdi_handle g_old_menu_act_layer = GDI_NULL_HANDLE;
static gui_toolbar_struct *current_toolbar = NULL;

/* Global variables */
extern MMI_BOOL wgui_toolbar_history_enter;

#if defined(UI_SCROLLBAR_STYLE_8)
extern gdi_handle g_mmi_gui_scrollbar_src_layer;
#endif

UI_filled_area toolbar_menu_highlight_filler={
UI_FILLED_AREA_TYPE_BITMAP,
NULL,
NULL,
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
0};


UI_filled_area toolbar_menu_highlight_with_scrollbar_filler={
UI_FILLED_AREA_TYPE_BITMAP,
NULL,
NULL,
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
0};

UI_filled_area toolbar_menu_2line_highlight_filler={
UI_FILLED_AREA_TYPE_BITMAP,
NULL,
NULL,
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
0};


UI_filled_area toolbar_menu_2line_highlight_with_scrollbar_filler={
UI_FILLED_AREA_TYPE_BITMAP,
NULL,
NULL,
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
0};

/* Local APIs */
static void gui_toolbar_HandleKeyLeft(void);
static void gui_toolbar_HandleKeyRight(void);
static void gui_toolbar_setup_key_handlers(void);
static void gui_toolbar_clear_key_handlers(void);
static void gui_toolbar_open_popout_menu(gui_toolbar_struct *t);
static void gui_toolbar_close_popout_menu(gui_toolbar_struct *t);
static void gui_toolbar_get_bar_item_area(gui_toolbar_struct *t, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_toolbar_get_bar_highlight_area(gui_toolbar_struct *t, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_toolbar_get_title_area(gui_toolbar_struct *t, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_toolbar_get_popout_menu_area(gui_toolbar_struct *t, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_toolbar_clear_bar(gui_toolbar_struct *t);
static void gui_toolbar_show_arrows(gui_toolbar_struct *t);
static void gui_toolbar_show_bar(gui_toolbar_struct *t);
static void gui_toolbar_clear_bar_highlight(gui_toolbar_struct *t);
static void gui_toolbar_show_bar_highlight(gui_toolbar_struct *t);
static void gui_toolbar_show_title(gui_toolbar_struct *t);
static void gui_toolbar_clear_popout_menu(gui_toolbar_struct *t);
static void gui_toolbar_show_popout_menu_bg(gui_toolbar_struct *t);
static void gui_toolbar_show_popout_menu(gui_toolbar_struct *t);
static void gui_toolbar_clear_highlight_module(gui_toolbar_struct *t);
static void gui_toolbar_clear_all(gui_toolbar_struct *t);
static void gui_toolbar_popout_menu_hide_callback(S32 x1, S32 y1, S32 x2, S32 y2);
static void gui_toolbar_transition_left_to_right_popout_menu(void);
static void gui_toolbar_transition_left_to_right_bar_highlight(void);
static void gui_toolbar_transition_right_to_left_popout_menu(void);
static void gui_toolbar_transition_right_to_left_bar_highlight(void);
static void gui_toolbar_reset_transition(gui_toolbar_struct *t);
static void gui_toolbar_transition_left_to_right(gui_toolbar_struct *t);
static void gui_toolbar_transition_right_to_left(gui_toolbar_struct *t);
static void gui_toolbar_reset_transition_ex(gui_toolbar_struct *t);


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_HandleKeyLeft
 * DESCRIPTION
 *  key handler of left arrow key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_HandleKeyLeft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_toolbar_struct *t;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = current_toolbar;
    MMI_DBG_ASSERT(t != NULL);

    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        i = t->toolbar_highlighted_menu_index;

        if (MMI_fixed_list_menu.highlighted_item >= 0)
        {
            t->toolbar_menu[i].highlight_menu_item = MMI_fixed_list_menu.highlighted_item;
            t->toolbar_menu[i].first_menu_item = MMI_fixed_list_menu.first_displayed_item;
        }
        
        for (j = 0; j < t->toolbar_menu_number; j ++)
        {
            i --;
            if (i < 0)
            {
                i = t->toolbar_menu_number - 1;
            }
            if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
                t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
            {
                break;
            }
        }

        if (j >= t->toolbar_menu_number)
        {
            return;
        }
        else
        {
            t->toolbar_highlighted_menu_index = i;
            gui_toolbar_clear_highlight_module(t);
            gui_toolbar_reset_transition_ex(t);
            gui_toolbar_transition_right_to_left(t);
        }
        
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_HandleKeyRight
 * DESCRIPTION
 *  key handler of right arrow key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_HandleKeyRight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_toolbar_struct *t;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = current_toolbar;
    MMI_DBG_ASSERT(t != NULL);

    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        i = t->toolbar_highlighted_menu_index;
        
        if (MMI_fixed_list_menu.highlighted_item >= 0)
        {
            t->toolbar_menu[i].highlight_menu_item = MMI_fixed_list_menu.highlighted_item;
            t->toolbar_menu[i].first_menu_item = MMI_fixed_list_menu.first_displayed_item;
        }
        
        for (j = 0; j < t->toolbar_menu_number; j ++)
        {
            i ++;
            if (i >= t->toolbar_menu_number)
            {
                i = 0;
            }
            if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
                t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
            {
                break;
            }
        }

        if (j >= t->toolbar_menu_number)
        {
            return;
        }
        else
        {
            t->toolbar_highlighted_menu_index = i;
            gui_toolbar_clear_highlight_module(t);
            gui_toolbar_reset_transition_ex(t);
            gui_toolbar_transition_left_to_right(t);
        }
        
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_setup_key_handlers
 * DESCRIPTION
 *  setup key hanlders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_setup_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(gui_toolbar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_toolbar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_dummy
 * DESCRIPTION
 *  dummy hanlders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_key_handlers
 * DESCRIPTION
 *  clear key hanlders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(gui_toolbar_dummy, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_toolbar_dummy, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_create
 * DESCRIPTION
 *  create toolbar
 * PARAMETERS
 *  t                               [IN]    pointer of toolbar
 *  x                               [IN]    x coordinate of toolbar
 *  y                               [IN]    y coordinate of toolbar
 *  max_width                       [IN]    max width of toolbar
 *  max_height                      [IN]    max height of toolbar
 *  toolbar_layer                   [IN]    layer of tool bar
 *  popout_menu_layer               [IN]    layer of popout menu
 *  wallpaper_layer                 [IN]    layer of wallpaper
 *  number_of toolbar_menu          [IN]    number of toolbar module
 *  icons_of_toolbar_menu_normal    [IN]    icons of toolbar menu normal modules
 *  icons_of_toolbar_menu_highlight [IN]    icons of toolbar menu highlight modules
 *  get_menu_data_callback          [IN]    callbacks of get menu data
 *  menu_highlight_handler          [IN]    callbacks of menu highlight handler
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_create(
        gui_toolbar_struct *t,
        S32 x, S32 y,
        S32 max_width,S32 max_height,
        GDI_HANDLE toolbar_layer, 
        GDI_HANDLE popout_menu_layer, 
        GDI_HANDLE wallpaper_layer,
        S32 number_of_toolbar_menu, 
        PU8 *icons_of_toolbar_menu_normal, 
        PU8 *icons_of_toolbar_menu_highlight,
        wgui_toolbar_getmenudata_funcptr_type *get_menu_data_callback,
        wgui_toolbar_popout_menu_highlighthandler_funcptr_type *menu_highlight_handler,
        mmi_gui_toolbar_popout_menu_state_enum *popout_menu_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    MMI_DBG_ASSERT(number_of_toolbar_menu > 0);

    t->x = x;
    t->y = y;
    t->max_width = max_width;
    t->max_height = max_height;
    t->bar_x = x;
    t->bar_y = y;
    t->bar_width = max_width;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_BAR_BG_ACTIVE), &width, &height);
    t->bar_height = height;
    t->toolbar_layer = toolbar_layer;
    t->popout_menu_layer = popout_menu_layer;
    t->wallpaper_layer = wallpaper_layer;
    t->toolbar_menu_number = number_of_toolbar_menu;
    t->state = MMI_GUI_TOOLBAR_STATE_INACTIVE;
    t->toolbar_highlighted_menu_index = 0;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_MENU_ITEM_BG), &width, &height);

    for(i = 0; i < t->toolbar_menu_number; i ++)
    {   
        if (i >= GUI_TOOLBAR_MAX_MENU)
        {
            break;
        }
        
        t->toolbar_menu[i].icon_normal = icons_of_toolbar_menu_normal[i];
        t->toolbar_menu[i].icon_highlight = icons_of_toolbar_menu_highlight[i];
        t->toolbar_menu[i].get_menu_data_callback = get_menu_data_callback[i];
        t->toolbar_menu[i].menu_highlight_handler = menu_highlight_handler[i];
        t->toolbar_menu[i].state = popout_menu_state[i];
        t->toolbar_menu[i].popout_menu_item_height = height;
        t->toolbar_menu[i].popout_menu_item_width = width;
        t->toolbar_menu[i].bg_number = 0;
        t->toolbar_menu[i].highlight_menu_item = -1;
        t->toolbar_menu[i].first_menu_item = -1;
    }

    g_old_menu_act_layer = wgui_fixed_list_get_active_layer();
    current_toolbar = t;

    t->popout_menu_transition_offset = 0;
    t->title_transition_offset = 0;
    t->bar_highlight_transition_offset = 0;
    t->bar_highlight_transition_times = 0;
    t->popout_menu_transition_times = 0;
    t->is_in_transition = MMI_FALSE;

    t->menu_highlight_from_history = 0;
    t->current_popout_menu_keyhandler[0] = NULL;
    t->current_popout_menu_keyhandler[1] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_close
 * DESCRIPTION
 *  close toolbar
 * PARAMETERS
 *  t   [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_close(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    
    gui_toolbar_reset_transition(t);
    gui_toolbar_clear_key_handlers();
    gui_toolbar_close_popout_menu(t);

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_move
 * DESCRIPTION
 *  close toolbar
 * PARAMETERS
 *  t   [IN]    pointer of toolbar
 *  x   [IN]    x of toolbar
 *  y   [IN]    y of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_move(gui_toolbar_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    t->x = x;
    t->y = y;
    t->bar_x = x;
    t->bar_y = y;

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_resize
 * DESCRIPTION
 *  resize toolbar
 * PARAMETERS
 *  t           [IN]    pointer of toolbar
 *  max_width   [IN]    max width of toolbar
 *  max_height  [IN]    max height of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_resize(gui_toolbar_struct *t, S32 max_width, S32 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    t->max_width = max_width;
    t->max_height = max_height;
    t->bar_width = max_width;

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_set_layers
 * DESCRIPTION
 *  set layers of toolbar
 * PARAMETERS
 *  t                   [IN]    pointer of toolbar
 *  toolbar_layer       [IN]    layer of toolbar
 *  popout_menu_layer   [IN]    layer of popout menu
 *  wallpaper_layer     [IN]    layer of wallpaper
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_set_layers(gui_toolbar_struct *t, 
        GDI_HANDLE toolbar_layer, 
        GDI_HANDLE popout_menu_layer, 
        GDI_HANDLE wallpaper_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    t->toolbar_layer = toolbar_layer;
    t->popout_menu_layer = popout_menu_layer;
    t->wallpaper_layer = wallpaper_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_set_bar_state
 * DESCRIPTION
 *  set state of toolbar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  state   [IN]    state of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_set_bar_state(gui_toolbar_struct *t, mmi_gui_toolbar_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (state != t->state)
    {
        if (state == MMI_GUI_TOOLBAR_STATE_INACTIVE)
        {
            t->state = state;
            gui_toolbar_clear_key_handlers();
            gui_toolbar_close_popout_menu(t);
            
            if (t->current_popout_menu_keyhandler[0] != NULL)
            {
                SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
                t->current_popout_menu_keyhandler[0] = NULL;
            }
            if (t->current_popout_menu_keyhandler[1] != NULL)
            {
                SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                t->current_popout_menu_keyhandler[1] = NULL;
            }
            
            for(i = 0; i < t->toolbar_menu_number; i ++)
            {   
                if (i >= GUI_TOOLBAR_MAX_MENU)
                {
                    break;
                }

                t->toolbar_menu[i].highlight_menu_item = -1;
                t->toolbar_menu[i].first_menu_item = -1;
            }
            
            t->toolbar_highlighted_menu_index = 0;

            gdi_layer_lock_frame_buffer();
            gui_toolbar_reset_transition(t);
            gui_toolbar_clear_all(t);
            gui_toolbar_show(t);
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);
        }
        else if (state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
        {
            t->state = state;
            gui_toolbar_setup_key_handlers();
            gui_toolbar_open_popout_menu(t);
            gui_toolbar_clear_all(t);
            gui_toolbar_show(t);
            gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_set_popout_menu_state
 * DESCRIPTION
 *  set popout menu state
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  index   [IN]    index of popoutmenu
 *  state   [IN]    state of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_set_popout_menu_state(gui_toolbar_struct *t, S32 index, mmi_gui_toolbar_popout_menu_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    
    if (index < 0 || index >= t->toolbar_menu_number)
    {
        return;
    }

    if (state != t->toolbar_menu[index].state)
    {
        if (state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE && index == t->toolbar_highlighted_menu_index)
        {
            i = t->toolbar_highlighted_menu_index;
            for (j = 0; j < t->toolbar_menu_number; j ++)
            {
                i ++;
                if (i >= t->toolbar_menu_number)
                {
                    i = 0;
                }
                if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
                    t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
                {
                    break;
                }
            }
        
            if (i == t->toolbar_highlighted_menu_index)
            {
                return;
            }
            else
            {
                t->toolbar_highlighted_menu_index = i;
            }
        
        }
        
        if (state >= MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE && state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
        {
            t->toolbar_menu[index].state = state;

            if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
            {
                gui_toolbar_close_popout_menu(t);
                gui_toolbar_open_popout_menu(t);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_change_bar_icon
 * DESCRIPTION
 *  change the bar icon
 * PARAMETERS
 *  t               [IN]    pointer of toolbar
 *  index           [IN]    index of module
 *  icon_normal     [IN]    normal icon of bar item
 *  icon_highlight  [IN]    highlight icon of bar item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_change_bar_icon(gui_toolbar_struct *t, S32 index, PU8 icon_normal, PU8 icon_highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (index < 0 || index >= t->toolbar_menu_number)
    {
        return;
    }

    t->toolbar_menu[index].icon_normal = icon_normal;
    t->toolbar_menu[index].icon_highlight = icon_highlight;

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_open_popout_menu
 * DESCRIPTION
 *  open popout menu
 * PARAMETERS
 *  t               [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_open_popout_menu(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, index;
    S32 menu_x1, menu_y1, menu_x2, menu_y2;
    UI_fixed_text_menuitem_theme menu_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (t->toolbar_menu[t->toolbar_highlighted_menu_index].get_menu_data_callback == NULL)
    {
        return;
    }

    for (i = 0, index = t->toolbar_highlighted_menu_index; i < t->toolbar_menu_number; i ++, index ++)
    {
        if (index >= t->toolbar_menu_number)
        {
            index = 0;
        }
        
        if (t->toolbar_menu[index].state != MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            break;
        }
    }

    t->toolbar_highlighted_menu_index = index;
    
    t->toolbar_menu[t->toolbar_highlighted_menu_index].get_menu_data_callback(
        &t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items,
        &t->toolbar_menu[t->toolbar_highlighted_menu_index].title_text,
        t->toolbar_menu[t->toolbar_highlighted_menu_index].icon_of_items,
        t->toolbar_menu[t->toolbar_highlighted_menu_index].text_of_items,
        t->toolbar_menu[t->toolbar_highlighted_menu_index].text_of_description,
        MAX_SUB_MENUS); 

    if (t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items <= 0 ||
        t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items > MAX_SUB_MENUS)
    {
        return;
    }

    
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif

    if (t->toolbar_menu[t->toolbar_highlighted_menu_index].highlight_menu_item > -1)
    {
        wgui_fixed_list_create_icontext_menu(t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items,
            t->toolbar_menu[t->toolbar_highlighted_menu_index].highlight_menu_item, 
            WGUI_LIST_MENU_DISABLE_SHORTCUT|WGUI_LIST_MENU_DISABLE_VOL_KEY, 0, NULL);
    }
    else
    {
        wgui_fixed_list_create_icontext_menu(t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items,
            0, WGUI_LIST_MENU_DISABLE_SHORTCUT|WGUI_LIST_MENU_DISABLE_VOL_KEY, 0, NULL);
    }


#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    wgui_enable_hint_highlight_in_icontext_menuitem();
#endif

    /* Register highlight handler */
    RegisterHighlightHandler(t->toolbar_menu[t->toolbar_highlighted_menu_index].menu_highlight_handler);

    wgui_fixed_list_begin_add_icontext_one_item();
    for (i = 0; i < t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items; i++)
    {
        wgui_fixed_list_add_icontext_one_item(i, t->toolbar_menu[t->toolbar_highlighted_menu_index].text_of_items[i],
            t->toolbar_menu[t->toolbar_highlighted_menu_index].icon_of_items[i],
            t->toolbar_menu[t->toolbar_highlighted_menu_index].text_of_description[i]);
    }
    wgui_fixed_list_end_add_icontext_one_item();

    wgui_fixed_list_register_hide_function(gui_toolbar_popout_menu_hide_callback);

    menu_theme.disabled_filler = current_fixed_icontext_menuitem_theme->disabled_filler;
    menu_theme.disabled_text_color = current_fixed_icontext_menuitem_theme->disabled_text_color;
    menu_theme.flags = current_fixed_icontext_menuitem_theme->flags;
    menu_theme.focussed_text_color = current_fixed_icontext_menuitem_theme->focussed_text_color;
    menu_theme.normal_filler = current_fixed_icontext_menuitem_theme->normal_filler;
    menu_theme.normal_text_color = current_fixed_icontext_menuitem_theme->normal_text_color;
    menu_theme.selected_text_color = current_fixed_icontext_menuitem_theme->selected_text_color;
    menu_theme.text_font = current_fixed_icontext_menuitem_theme->text_font;

    toolbar_menu_highlight_filler.b = (PU8)GetImage(IMG_TOOLBAR_MENU_HIGHLIGHT_WITHOUT_SCROLLBAR);
    toolbar_menu_highlight_with_scrollbar_filler.b = (PU8)GetImage(IMG_TOOLBAR_MENU_HIGHLIGHT_WITH_SCROLLBAR);
    toolbar_menu_2line_highlight_filler.b = (PU8)GetImage(IMG_TOOLBAR_MENU_HIGHLIGHT_DOUBLE_LINE_WITHOUT_SCROLLBAR);
    toolbar_menu_2line_highlight_with_scrollbar_filler.b = (PU8)GetImage(IMG_TOOLBAR_MENU_HIGHLIGHT_DOUBLE_LINE_WITH_SCROLLBAR);

    menu_theme.selected_filler= &toolbar_menu_highlight_with_scrollbar_filler;
    menu_theme.focussed_filler = &toolbar_menu_highlight_with_scrollbar_filler;
    menu_theme.focussed_without_sc_filler = &toolbar_menu_highlight_filler;

    gui_toolbar_get_popout_menu_area(t, &menu_x1, &menu_y1, &menu_x2, &menu_y2);

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
    
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT;
    
    wgui_fixed_list_set_active_layer(t->popout_menu_layer);

    wgui_fixed_list_set_alpha_blending_layer(t->popout_menu_layer);
        
    resize_fixed_icontext_menuitems(0,
        t->toolbar_menu[t->toolbar_highlighted_menu_index].popout_menu_item_height);
    
    wgui_fixed_list_move_text_menu(menu_x1, menu_y1);

    wgui_fixed_list_resize_icontext_menu(MMI_fixed_list_menu.width, menu_y2 - menu_y1 + 1);

    resize_fixed_text_menuitems_to_list_width();

    gui_set_fixed_text_menuitem_theme(&MMI_fixed_icontext_menuitem,&menu_theme);
    gui_fixed_two_line_set_filler(&toolbar_menu_2line_highlight_with_scrollbar_filler, &toolbar_menu_2line_highlight_filler);
        
#if defined(UI_SCROLLBAR_STYLE_8)
    g_mmi_gui_scrollbar_src_layer = t->popout_menu_layer;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_close_popout_menu
 * DESCRIPTION
 *  close popout menu
 * PARAMETERS
 *  t               [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_close_popout_menu(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (t->current_popout_menu_keyhandler[0] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[0] = NULL;
    }
    if (t->current_popout_menu_keyhandler[1] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = NULL;
    }

    if (g_old_menu_act_layer != GDI_NULL_HANDLE)
    {
        wgui_fixed_list_set_active_layer(g_old_menu_act_layer);
    }
    
#if defined(UI_SCROLLBAR_STYLE_8)
    g_mmi_gui_scrollbar_src_layer = GDI_NULL_HANDLE;
#endif    
    /* Reset list */
    reset_fixed_list();
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;

    gui_fixed_two_line_set_filler(NULL, NULL);

    reset_pop_up_descriptions();    

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_get_bar_item_area
 * DESCRIPTION
 *  get the area of bar item
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  index   [IN]    index of bar item
 *  x1      [OUT]   x1 of bar item
 *  y1      [OUT]   y1 of bar item
 *  x2      [OUT]   x2 of bar item
 *  y2      [OUT]   y2 of bar item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_get_bar_item_area(gui_toolbar_struct *t, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ix1, iy1, ix2, iy2;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    ix1 = t->bar_x + GUI_TOOLBAR_BAR_INDENT;
    ix2 = t->bar_x + t->bar_width - 1 - GUI_TOOLBAR_BAR_INDENT;

    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE), &width, &height);
    iy1 = t->bar_y;
    iy2 = iy1 + height - 1;

    ix1 += index * (width + GUI_TOOLBAR_BAR_GAP);
    ix2 = ix1 + width - 1;

    *x1 = ix1;
    *y1 = iy1;
    *x2 = ix2;
    *y2 = iy2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_get_bar_highlight_area
 * DESCRIPTION
 *  get the area of bar highlight
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  index   [IN]    index of bar item
 *  x1      [OUT]   x1 of bar item
 *  y1      [OUT]   y1 of bar item
 *  x2      [OUT]   x2 of bar item
 *  y2      [OUT]   y2 of bar item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_get_bar_highlight_area(gui_toolbar_struct *t, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ix1, iy1, ix2, iy2;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    ix1 = t->bar_x + GUI_TOOLBAR_BAR_INDENT;
    ix2 = t->bar_x + t->bar_width - 1 - GUI_TOOLBAR_BAR_INDENT;

    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_BAR_BG_HIGHLIGHT), &width, &height);
    iy1 = t->bar_y;
    iy2 = iy1 + height - 1;

    ix1 += index * (width + GUI_TOOLBAR_BAR_GAP);
    ix2 = ix1 + width - 1;

    *x1 = ix1;
    *y1 = iy1;
    *x2 = ix2;
    *y2 = iy2;

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_get_title_area
 * DESCRIPTION
 *  get the area of title
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  x1      [OUT]   x1 of bar item
 *  y1      [OUT]   y1 of bar item
 *  x2      [OUT]   x2 of bar item
 *  y2      [OUT]   y2 of bar item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_get_title_area(gui_toolbar_struct *t, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_BAR_BG_HIGHLIGHT), &width, &height);
    *x1 = t->x;
    *y1 = t->y + height;
    
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_TITLE_BG), &width, &height);
    *x2 = *x1 + width - 1;
    *y2 = *y1 + height - 1;

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_get_popout_menu_area
 * DESCRIPTION
 *  get the area of popout menu
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  x1      [OUT]   x1 of bar item
 *  y1      [OUT]   y1 of bar item
 *  x2      [OUT]   x2 of bar item
 *  y2      [OUT]   y2 of bar item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_get_popout_menu_area(gui_toolbar_struct *t, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    *x1 = t->x;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_BAR_BG_HIGHLIGHT), &width, &height);
    *y1 = t->y + height;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_TITLE_BG), &width, &height);
    *y1 += height;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_MENU_ITEM_BG), &width, &height);
    *x2 = *x1 + width - 1;

    *y2 = *y1;

    for (i = 0, j = 0; i < t->toolbar_menu[t->toolbar_highlighted_menu_index].number_of_popout_menu_items; i ++)
    {
        *y2 = *y2 + height;
        j ++;

        if (*y2 > t->y + t->max_height - 1)
        {
            j --;
            break;
        }
    }

    if (t->toolbar_menu[t->toolbar_highlighted_menu_index].text_of_description[MMI_fixed_list_menu.highlighted_item] != NULL)
    {
        *y2 += height;
        j ++;    
        
        if (*y2 > t->y + t->max_height - 1)
        {
            j --;
        }
    }

    if (*y2 > t->y + t->max_height - 1)
    {
        *y2 = *y1 + (t->y + t->max_height - *y1) / height * height - 1;
    }
    else
    {
        *y2 -= 1;
    }

    t->toolbar_menu[t->toolbar_highlighted_menu_index].bg_number = j;

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_bar
 * DESCRIPTION
 *  clear the bar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_bar(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(t->toolbar_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(t->bar_x, t->bar_y, t->bar_x + t->bar_width - 1, t->bar_y + t->bar_height - 1);

    gdi_draw_solid_rect(t->bar_x, t->bar_y, t->bar_x + t->bar_width - 1, t->bar_y + t->bar_height - 1, 
        GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show_arrows
 * DESCRIPTION
 *  show arrows in the bar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_show_arrows(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, width, height;
    S32 ix1, iy1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = t->x;
    x2 = t->x + GUI_TOOLBAR_BAR_INDENT - 1;
    y1 = t->y;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_LEFT_ARROW), &width, &height);
    y2 = y1 + height - 1;

    ix1 = x1 + (x2 - x1 + 1 - width) / 2;
    iy1 = y1 + (y2 - y1 + 1 - height) / 2;
    gdi_image_draw(ix1, iy1, (PU8)GetImage(IMG_TOOLBAR_LEFT_ARROW));

    x2 = t->x + t->max_width - 1;
    x1 = x2 - GUI_TOOLBAR_BAR_INDENT + 1;
    y1 = t->y;
    gui_measure_image((PU8)GetImage(IMG_TOOLBAR_RIGHT_ARROW), &width, &height);
    y2 = y1 + height - 1;

    ix1 = x1 + (x2 - x1 + 1 - width) / 2;
    iy1 = y1 + (y2 - y1 + 1 - height) / 2;
    gdi_image_draw(ix1, iy1, (PU8)GetImage(IMG_TOOLBAR_RIGHT_ARROW));
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show_bar
 * DESCRIPTION
 *  show the bar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_show_bar(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, index;
    S32 x1, y1, x2, y2;
    S32 ix1, iy1;
    S32 iwidth, iheight;
    gdi_handle old_src_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_clear_bar(t);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(t->toolbar_layer);
    
    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        gdi_get_alpha_blending_source_layer(&old_src_layer);
        gdi_set_alpha_blending_source_layer(t->wallpaper_layer);

        gui_toolbar_show_arrows(t);
    }

    for (i = 0, index = 0; i < t->toolbar_menu_number; i ++)
    {
        if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            continue;
        }
        else if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_NORMAL ||
                 t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
        {
            gui_toolbar_get_bar_item_area(t, index, &x1, &y1, &x2, &y2);
            gui_measure_image(t->toolbar_menu[i].icon_normal, &iwidth, &iheight);
            ix1 = x1 + (x2 - x1 + 1 - iwidth) / 2;
            iy1 = y1 + (y2 - y1 + 1 - iheight) / 2;
            index ++;

            gdi_layer_push_clip();
            gdi_layer_set_clip(x1, y1, x2, y2);
            
            if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_NORMAL)
            {
                if (t->state == MMI_GUI_TOOLBAR_STATE_INACTIVE)
                {
                    gdi_image_draw(x1, y1, (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));
                }
                else if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
                {
                    gdi_image_draw(x1, y1, (PU8)GetImage(IMG_TOOLBAR_BAR_BG_ACTIVE));
                }
            }
            else if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
                {
                    gdi_image_draw(x1, y1, (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
                }
                else
                {
                    gdi_image_draw(x1, y1, (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT));
                }
            }

            gdi_image_draw(ix1, iy1, t->toolbar_menu[i].icon_normal);

            gdi_layer_pop_clip();
        }
    }
    
    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        gdi_set_alpha_blending_source_layer(old_src_layer);
    }

    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_bar_highlight
 * DESCRIPTION
 *  clear the highlight of bar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_bar_highlight(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_get_bar_highlight_area(t, t->toolbar_highlighted_menu_index, &x1, &y1, &x2, &y2);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(t->popout_menu_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(t->x + GUI_TOOLBAR_BAR_INDENT, y1, 
        t->x + t->max_width - GUI_TOOLBAR_BAR_INDENT, y2);

    gdi_draw_solid_rect(t->x + GUI_TOOLBAR_BAR_INDENT, y1, 
        t->x + t->max_width - GUI_TOOLBAR_BAR_INDENT, y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show_bar_highlight
 * DESCRIPTION
 *  show the highlight of bar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_show_bar_highlight(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 ix1, iy1;
    S32 width, height;
    gdi_handle old_src_layer;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_clear_bar_highlight(t);
    
    for (i = 0, j = t->toolbar_highlighted_menu_index; i <= t->toolbar_highlighted_menu_index; i ++)
    {
        if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            j --;
        }
    }
    gui_toolbar_get_bar_highlight_area(t, j, &x1, &y1, &x2, &y2);
    gui_measure_image(t->toolbar_menu[t->toolbar_highlighted_menu_index].icon_highlight, &width, &height);
    ix1 = x1 + (x2 - x1 + 1 - width) / 2;
    iy1 = y1 + (y2 - y1 + 1 - height) / 2;

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(t->popout_menu_layer);
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(t->wallpaper_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    gdi_image_draw(x1, y1, (PU8)GetImage(IMG_TOOLBAR_BAR_BG_HIGHLIGHT));

    if (t->toolbar_menu[t->toolbar_highlighted_menu_index].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
    {
        gdi_image_draw(x1, y1, (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT));
    }
    
    gdi_image_draw(ix1, iy1, t->toolbar_menu[t->toolbar_highlighted_menu_index].icon_highlight);

    gdi_layer_pop_clip();
    gdi_set_alpha_blending_source_layer(old_src_layer);
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show_title
 * DESCRIPTION
 *  show the title of bar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_show_title(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    gdi_handle old_src_layer;
    S32 text_x1, text_y1, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_get_title_area(t, &x1, &y1, &x2, &y2);

    gdi_layer_lock_frame_buffer();
    
    gdi_layer_push_and_set_active(t->popout_menu_layer);
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(t->wallpaper_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    /* show title background */
    gdi_image_draw(x1/* + t->popout_menu_transition_offset*/, y1, (PU8)GetImage(IMG_TOOLBAR_TITLE_BG));

    /* show title text */
    MMI_DBG_ASSERT(t->toolbar_menu[t->toolbar_highlighted_menu_index].title_text != NULL);
    
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_set_text_border_color(*current_MMI_theme->title_text_border_color);
    gui_measure_string((UI_string_type)t->toolbar_menu[t->toolbar_highlighted_menu_index].title_text, &width, &height);

    text_x1 = x1 + (x2 - x1 + 1 - width)  / 2;
    text_y1 = y1 + (y2 - y1 + 1 - height) / 2;
    if (text_x1 < x1)
    {
        text_x1 = x1;
    }
    if (width > (x2 - x1 + 1))
    {
        width = x2 - x1 + 1;
    }
    
    gui_move_text_cursor(text_x1 + t->title_transition_offset, text_y1);
    gui_print_truncated_borderd_text(text_x1 + t->title_transition_offset, text_y1, width, (UI_string_type)t->toolbar_menu[t->toolbar_highlighted_menu_index].title_text);
    
    
    gdi_layer_pop_clip();
    gdi_set_alpha_blending_source_layer(old_src_layer);
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_title
 * DESCRIPTION
 *  clear the title
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_title(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    
    gui_toolbar_get_title_area(t, &x1, &y1, &x2, &y2);

    gdi_layer_lock_frame_buffer();
    
    gdi_layer_push_and_set_active(t->popout_menu_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1 + t->popout_menu_transition_offset, y1, x2 + t->popout_menu_transition_offset, t->y + t->max_height - 1);

    gdi_draw_solid_rect(x1 + t->popout_menu_transition_offset, y1, x2 + t->popout_menu_transition_offset, t->y + t->max_height - 1, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_popout_menu
 * DESCRIPTION
 *  clear the popout menu 
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_popout_menu(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    
    gui_toolbar_get_popout_menu_area(t, &x1, &y1, &x2, &y2);

    gdi_layer_lock_frame_buffer();
    
    gdi_layer_push_and_set_active(t->popout_menu_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1 + t->popout_menu_transition_offset, y1, x2 + t->popout_menu_transition_offset, t->y + t->max_height - 1);

    gdi_draw_solid_rect(x1 + t->popout_menu_transition_offset, y1, x2 + t->popout_menu_transition_offset, t->y + t->max_height - 1, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt_previous(x1 + t->popout_menu_transition_offset, y1, x2 + t->popout_menu_transition_offset, t->y + t->max_height - 1);

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show_popout_menu_bg
 * DESCRIPTION
 *  show background of popout menu 
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_show_popout_menu_bg(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_src_layer;   
    S32 x1, y1, x2, y2, temp_y1;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_clear_popout_menu(t);
    
    gui_toolbar_get_popout_menu_area(t, &x1, &y1, &x2, &y2);
    
    wgui_fixed_list_resize_icontext_menu(MMI_fixed_list_menu.width, y2 - y1 + 1);
    resize_fixed_text_menuitems_to_list_width();
    
    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(t->popout_menu_layer); 
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(t->wallpaper_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1 + t->popout_menu_transition_offset, y1, x2 + t->popout_menu_transition_offset, y2);

    temp_y1 = y1;
    for (i = 0; i < t->toolbar_menu[t->toolbar_highlighted_menu_index].bg_number; i ++)
    {
        gdi_image_draw(x1 + t->popout_menu_transition_offset, temp_y1, (PU8)GetImage(IMG_TOOLBAR_MENU_ITEM_BG));
        temp_y1 += t->toolbar_menu[t->toolbar_highlighted_menu_index].popout_menu_item_height;
    }

    gdi_layer_pop_clip();
    
    gdi_image_abm_set_source_layer(old_src_layer);
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show_popout_menu
 * DESCRIPTION
 *  show popout menu 
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_show_popout_menu(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_x1, menu_y1, menu_x2, menu_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (!t->is_in_transition)
    {
        gui_toolbar_clear_popout_menu(t);
        gui_toolbar_show_bar_highlight(t);
    }
    
    if (wgui_toolbar_history_enter)
    {
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_setup_key_handlers();
        gui_toolbar_open_popout_menu(t);
        fixed_list_goto_item(t->menu_highlight_from_history);
        MMI_fixed_list_menu.first_displayed_item = t->menu_first_item_from_history;
        wgui_toolbar_history_enter = MMI_FALSE;
    }
    
    gui_toolbar_show_title(t);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_and_set_active(t->popout_menu_layer); 

    gui_toolbar_get_popout_menu_area(t, &menu_x1, &menu_y1, &menu_x2, &menu_y2);
    wgui_fixed_list_move_icontext_menu(menu_x1 + t->popout_menu_transition_offset, menu_y1);

    if (t->toolbar_menu[t->toolbar_highlighted_menu_index].first_menu_item > -1)
    {
        MMI_fixed_list_menu.first_displayed_item = t->toolbar_menu[t->toolbar_highlighted_menu_index].first_menu_item;
        t->toolbar_menu[t->toolbar_highlighted_menu_index].first_menu_item = -1;
    }

    show_fixed_list();
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_highlight_module
 * DESCRIPTION
 *  clear the highlight of popout menu 
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_highlight_module(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(t->popout_menu_layer); 

    gdi_draw_solid_rect(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1, GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_and_restore_active();
    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_clear_all
 * DESCRIPTION
 *  clear all of toolbar 
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_clear_all(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_clear_bar(t);

    gdi_layer_lock_frame_buffer();
    
    gdi_layer_push_and_set_active(t->popout_menu_layer); 

    gdi_draw_solid_rect(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1, GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_popout_menu_hide_callback
 * DESCRIPTION
 *  menu hide callback
 * PARAMETERS
 *  x1  [IN]    x1 of toolbar
 *  y1  [IN]    y1 of toolbar
 *  x2  [IN]    x2 of toolbar
 *  y2  [IN]    y2 of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_popout_menu_hide_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(current_toolbar!= NULL);

    gui_toolbar_show_popout_menu_bg(current_toolbar);
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_show
 * DESCRIPTION
 *  show the toolbar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_show(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_clear_all(t);
    
    if (t->state == MMI_GUI_TOOLBAR_STATE_INACTIVE)
    {
        gui_toolbar_show_bar(t);
    }
    else if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        gui_toolbar_show_bar(t);
        gui_toolbar_show_popout_menu(t);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_redraw_bar
 * DESCRIPTION
 *  redraw the toolbar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_redraw_bar(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_toolbar_show_bar(t);
    gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_redraw_popout_menu
 * DESCRIPTION
 *  redraw the popout menu
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_redraw_popout_menu(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        if (!t->is_in_transition)
        {
            gui_toolbar_show_popout_menu(t);
            gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_redraw
 * DESCRIPTION
 *  redraw the toolbar
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_redraw(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    
    
    if (t->state == MMI_GUI_TOOLBAR_STATE_INACTIVE)
    {
        gui_toolbar_clear_all(t);
        gui_toolbar_show_bar(t);
        
        gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);
    }
    else if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        if (!t->is_in_transition)
        {
            gui_toolbar_clear_all(t);
        }
        else
        {
            gui_toolbar_clear_bar(t);
        }
        
        gui_toolbar_show_bar(t);
        
        if (!t->is_in_transition)
        {
            gui_toolbar_show_popout_menu(t);
            gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_update_popout_menu
 * DESCRIPTION
 *  update of popout menu
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_update_popout_menu(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    
    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_setup_key_handlers();
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_clear_all(t);
        gui_toolbar_redraw_popout_menu(t);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_transition_left_to_right_popout_menu
 * DESCRIPTION
 *  popout menu transition of left to right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_transition_left_to_right_popout_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_toolbar_struct *t;
    S32 current_highlight_index;
    S32 i, j, offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = current_toolbar;
    MMI_DBG_ASSERT(t != NULL);
    t->is_in_transition = MMI_TRUE;

    if (t->current_popout_menu_keyhandler[0] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[0] = NULL;
    }
    if (t->current_popout_menu_keyhandler[1] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = NULL;
    }

    current_highlight_index = t->toolbar_highlighted_menu_index;

    gdi_layer_lock_frame_buffer();

    gui_toolbar_transition_left_to_right_bar_highlight();

    gui_toolbar_clear_title(t);

    gui_toolbar_clear_popout_menu(t);

    if (t->popout_menu_transition_times < GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2)
    {
        /* Setup pre menu */
        i = t->toolbar_highlighted_menu_index;
        for (j = 0; j < t->toolbar_menu_number; j ++)
        {
            i --;
            if (i < 0)
            {
                i = t->toolbar_menu_number - 1;
            }
            if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
                t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
            {
                break;
            }
        }
        
        t->toolbar_highlighted_menu_index = i;
        
        offset = 0 - t->max_width/ (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2) * 
            (t->popout_menu_transition_times + 1);
        
        if (t->popout_menu_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1)
        {
            offset = 0 - t->max_width;
        }    
        
        t->popout_menu_transition_offset = offset;
        
        offset = 0 - t->max_width/ (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1) * 
            (t->popout_menu_transition_times);
        
        if (t->popout_menu_transition_times >= GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 2)
        {
            offset = 0 - t->max_width;
        }    

        t->title_transition_offset = offset;
        
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_show_popout_menu(t);

        t->toolbar_highlighted_menu_index = current_highlight_index;

        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_close_popout_menu(t);

        t->current_popout_menu_keyhandler[0] = GetKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = GetKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    }
    else
    {
        /* Setup current menu */
        offset = t->max_width - t->max_width / (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2) * 
            (t->popout_menu_transition_times - GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 + 1);
        
        if (t->popout_menu_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 1)
        {
            offset = 0;
        }    
        
        t->popout_menu_transition_offset = offset;
        
        offset = t->max_width  - t->max_width / (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1) * 
            (t->popout_menu_transition_times - GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2);
        
        if (t->popout_menu_transition_times >= GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 2)
        {
            offset = 0;
        }    

        if (t->popout_menu_transition_times >= GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 2)
        {
            t->title_transition_offset = 0;
        }
        else
        {
            t->title_transition_offset = offset;
        }
        
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_show_popout_menu(t);

        t->current_popout_menu_keyhandler[0] = GetKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = GetKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    }

    /* Setup timer related */
    t->popout_menu_transition_times ++;

    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);

    if (t->popout_menu_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES)
    {
        t->popout_menu_transition_times = 0;
        t->popout_menu_transition_offset = 0;
        t->title_transition_offset = 0;
        t->is_in_transition = MMI_FALSE;

        if (t->current_popout_menu_keyhandler[0] != NULL)
        {
            SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
            t->current_popout_menu_keyhandler[0] = NULL;
        }
        if (t->current_popout_menu_keyhandler[1] != NULL)
        {
            SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            t->current_popout_menu_keyhandler[1] = NULL;
        }
#ifdef __MMI_OP12_CAT533_SUPPORT__
        wgui_cat533_resume_wallpaper();
#endif
    }
    else
    {
        gui_start_timer(GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMER, 
            gui_toolbar_transition_left_to_right_popout_menu);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_transition_left_to_right_bar_highlight
 * DESCRIPTION
 *  bar highlight transition of left to right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_transition_left_to_right_bar_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_toolbar_struct *t;
    S32 current_highlight_index;
    S32 i, j;
    S32 item1_x1, item1_y1, item1_x2, item1_y2;
    S32 item2_x1, item2_y1, item2_x2, item2_y2;
    S32 ix1, iy1, width, height;
    gdi_handle old_src_layer;
    S32 m, n;
    gdi_handle h1, h2, h3, h4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = current_toolbar;
    MMI_DBG_ASSERT(t != NULL);

    t->is_in_transition = MMI_TRUE;
    current_highlight_index = t->toolbar_highlighted_menu_index;
    i = t->toolbar_highlighted_menu_index;
    for (j = 0; j < t->toolbar_menu_number; j ++)
    {
        i --;
        if (i < 0)
        {
            i = t->toolbar_menu_number - 1;
        }
        if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
            t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
        {
            break;
        }
    }
    
    for (m = 0, n = current_highlight_index; m <= current_highlight_index; m ++)
    {
        if (t->toolbar_menu[m].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            n --;
        }
    }
    
    gui_toolbar_get_bar_highlight_area(t, n, &item1_x1, &item1_y1, &item1_x2, &item1_y2);

    for (m = 0, n = i; m <= i; m ++)
    {
        if (t->toolbar_menu[m].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            n --;
        }
    }
    gui_toolbar_get_bar_highlight_area(t, n, &item2_x1, &item2_y1, &item2_x2, &item2_y2);

    if (i > current_highlight_index)
    {
        /* tail to head */
        if (t->bar_highlight_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 1)
        {
            gui_toolbar_clear_bar_highlight(t);
            gui_toolbar_show_bar_highlight(t);
            
            t->bar_highlight_transition_offset = 0;
            t->bar_highlight_transition_times = 0;
            t->is_in_transition = MMI_FALSE;
        }
        else
        {
            t->bar_highlight_transition_offset = (item1_x2 - item1_x1 + 1 + GUI_TOOLBAR_BAR_GAP) / 
                GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES * (t->bar_highlight_transition_times + 1);

            gui_toolbar_clear_bar_highlight(t);

            gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);
            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            gdi_layer_push_clip();
            gdi_layer_set_clip(t->bar_x, item2_y1, t->bar_x + t->bar_width - 1, item2_y2);
            gdi_layer_flatten_with_clipping(h1, h2, h3, h4);
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            
            gdi_get_alpha_blending_source_layer(&old_src_layer);
            gdi_set_alpha_blending_source_layer(t->popout_menu_layer);
            
            gdi_layer_push_clip();
            gdi_layer_set_clip(item1_x1, item1_y1, item2_x2, item2_y2);            
            
            if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item2_x1, item2_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }
            
            if (t->toolbar_menu[current_highlight_index].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item1_x1, item1_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }           
            
            gdi_image_draw(item2_x1 +  t->bar_highlight_transition_offset, item2_y1,
                (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));
        
            gdi_image_draw(item1_x1 - (item1_x2 - item1_x1 + 1) + t->bar_highlight_transition_offset, item1_y1,
                (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));
            
            gui_measure_image(t->toolbar_menu[current_highlight_index].icon_highlight, &width, &height);

            ix1 = item1_x1 + (item1_x2 - item1_x1 + 1 - width) / 2;
            iy1 = item1_y1 + (item1_y2 - item1_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[current_highlight_index].icon_highlight);
            
            gui_measure_image(t->toolbar_menu[i].icon_highlight, &width, &height);

            ix1 = item2_x1 + (item2_x2 - item2_x1 + 1 - width) / 2;
            iy1 = item2_y1 + (item2_y2 - item2_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[i].icon_highlight);            
                
            gdi_layer_pop_clip();
            gdi_set_alpha_blending_source_layer(old_src_layer);
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            t->bar_highlight_transition_times ++;
        }

    }
    else
    {
        if (t->bar_highlight_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 1)
        {
            gui_toolbar_clear_bar_highlight(t);
            gui_toolbar_show_bar_highlight(t);
            
            t->bar_highlight_transition_offset = 0;
            t->bar_highlight_transition_times = 0;
            t->is_in_transition = MMI_FALSE;
        }
        else
        {
            t->bar_highlight_transition_offset = (item1_x1 - item2_x1 + 1) / 
                GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES * (t->bar_highlight_transition_times + 1);

            gui_toolbar_clear_bar_highlight(t);

            gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);
            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            gdi_layer_push_clip();
            gdi_layer_set_clip(t->bar_x, item2_y1, t->bar_x + t->bar_width - 1, item2_y2);
            gdi_layer_flatten_with_clipping(h1, h2, h3, h4);
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            
            gdi_get_alpha_blending_source_layer(&old_src_layer);
            gdi_set_alpha_blending_source_layer(t->popout_menu_layer);
            
            gdi_layer_push_clip();
            gdi_layer_set_clip(item2_x1, item2_y1, item1_x2, item1_y2);            
            
            if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item2_x1, item2_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }
            
            if (t->toolbar_menu[current_highlight_index].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item1_x1, item1_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }

            gdi_image_draw(item2_x1 +  t->bar_highlight_transition_offset, item2_y1,
                (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));
            
            gui_measure_image(t->toolbar_menu[current_highlight_index].icon_highlight, &width, &height);

            ix1 = item1_x1 + (item1_x2 - item1_x1 + 1 - width) / 2;
            iy1 = item1_y1 + (item1_y2 - item1_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[current_highlight_index].icon_highlight);
            
            gui_measure_image(t->toolbar_menu[i].icon_highlight, &width, &height);

            ix1 = item2_x1 + (item2_x2 - item2_x1 + 1 - width) / 2;
            iy1 = item2_y1 + (item2_y2 - item2_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[i].icon_highlight);            
                
            gdi_layer_pop_clip();
            
            gdi_set_alpha_blending_source_layer(old_src_layer);
            
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            t->bar_highlight_transition_times ++;
        }
        
    }

    
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_transition_right_to_left_popout_menu
 * DESCRIPTION
 *  popout menu transition of right to left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_transition_right_to_left_popout_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_toolbar_struct *t;
    S32 current_highlight_index;
    S32 i, j, offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = current_toolbar;
    MMI_DBG_ASSERT(t != NULL);
    t->is_in_transition = MMI_TRUE;

    if (t->current_popout_menu_keyhandler[0] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[0] = NULL;
    }
    if (t->current_popout_menu_keyhandler[1] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = NULL;
    }

    current_highlight_index = t->toolbar_highlighted_menu_index;
    
    gdi_layer_lock_frame_buffer();    
    
    gui_toolbar_transition_right_to_left_bar_highlight();

    gui_toolbar_clear_title(t);

    gui_toolbar_clear_popout_menu(t);

    if (t->popout_menu_transition_times < GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2)
    {
        /* Setup next menu */
        i = t->toolbar_highlighted_menu_index;
        for (j = 0; j < t->toolbar_menu_number; j ++)
        {
            i ++;
            if (i >= t->toolbar_menu_number)
            {
                i = 0;
            }
            if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
                t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
            {
                break;
            }
        }
        
        t->toolbar_highlighted_menu_index = i;
        
        offset = t->max_width / (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2) * 
            (t->popout_menu_transition_times + 1);
        
        if (t->popout_menu_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1)
        {
            offset = t->max_width;
        }    
        
        t->popout_menu_transition_offset = offset;
        
        offset = t->max_width / (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1) * 
            (t->popout_menu_transition_times);
        
        if (t->popout_menu_transition_times >= GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 2)
        {
            offset = t->max_width;
        }    
        
        t->title_transition_offset = offset;
        
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_show_popout_menu(t);
        
        if (t->popout_menu_transition_times >= GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1)
        {
            
            S32 x1, y1, x2, y2;
            
            MMI_DBG_ASSERT(t != NULL);
            
            gui_toolbar_get_popout_menu_area(t, &x1, &y1, &x2, &y2);
            
            gdi_layer_lock_frame_buffer();
            
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            gdi_layer_push_clip();
            gdi_layer_set_clip(t->x, y1, t->x + t->max_width - 1, t->y + t->max_height - 1);
            
            gdi_draw_solid_rect(t->x, y1, t->x + t->max_width - 1, t->y + t->max_height - 1, GDI_COLOR_TRANSPARENT);
            
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
            
            gdi_layer_blt_previous(t->x, y1, t->x + t->max_width - 1, t->y + t->max_height - 1);
            
            gdi_layer_unlock_frame_buffer();
            
        }    
     
        t->toolbar_highlighted_menu_index = current_highlight_index;

        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_close_popout_menu(t);

        t->current_popout_menu_keyhandler[0] = GetKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = GetKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    }
    else
    {
        /* Setup current menu */
        
        offset = t->max_width / (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2) * 
            (t->popout_menu_transition_times - GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 + 1) - t->max_width;
        
        if (t->popout_menu_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 1)
        {
            offset = 0;
        }    
        
        t->popout_menu_transition_offset = offset;
        
        
        offset = t->max_width / (GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2 - 1) * 
            (t->popout_menu_transition_times - GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES / 2) - t->max_width;
        
        if (t->popout_menu_transition_times >= GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 2)
        {
            offset = 0;
        }    
        
        t->title_transition_offset = offset;
        
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_show_popout_menu(t);

        t->current_popout_menu_keyhandler[0] = GetKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = GetKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    }

    /* Setup timer related */
    t->popout_menu_transition_times ++;

    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(t->x, t->y, t->x + t->max_width - 1, t->y + t->max_height - 1);

    if (t->popout_menu_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES)
    {
        t->popout_menu_transition_times = 0;
        t->popout_menu_transition_offset = 0;
        t->is_in_transition = MMI_FALSE;

        if (t->current_popout_menu_keyhandler[0] != NULL)
        {
            SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
            t->current_popout_menu_keyhandler[0] = NULL;
        }
        if (t->current_popout_menu_keyhandler[1] != NULL)
        {
            SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            t->current_popout_menu_keyhandler[1] = NULL;
        }
#ifdef __MMI_OP12_CAT533_SUPPORT__
        wgui_cat533_resume_wallpaper();
#endif       
    }
    else
    {
        gui_start_timer(GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMER, 
            gui_toolbar_transition_right_to_left_popout_menu);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_transition_right_to_left_bar_highlight
 * DESCRIPTION
 *  highlight transition of right to left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_transition_right_to_left_bar_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_toolbar_struct *t;
    S32 current_highlight_index;
    S32 i, j;
    S32 item1_x1, item1_y1, item1_x2, item1_y2;
    S32 item2_x1, item2_y1, item2_x2, item2_y2;
    S32 ix1, iy1, width, height;
    gdi_handle old_src_layer;
    S32 m, n;
    gdi_handle h1, h2, h3, h4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = current_toolbar;
    MMI_DBG_ASSERT(t != NULL);
    
    t->is_in_transition = MMI_TRUE;
    current_highlight_index = t->toolbar_highlighted_menu_index;
    i = t->toolbar_highlighted_menu_index;
    for (j = 0; j < t->toolbar_menu_number; j ++)
    {
        i ++;
        if (i >=  t->toolbar_menu_number)
        {
            i = 0;
        }
        if (t->toolbar_menu[i].state > MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE &&
            t->toolbar_menu[i].state < MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL)
        {
            break;
        }
    }
    
    for (m = 0, n = current_highlight_index; m <= current_highlight_index; m ++)
    {
        if (t->toolbar_menu[m].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            n --;
        }
    }
    
    gui_toolbar_get_bar_highlight_area(t, n, &item1_x1, &item1_y1, &item1_x2, &item1_y2);

    for (m = 0, n = i; m <= i; m ++)
    {
        if (t->toolbar_menu[m].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE)
        {
            n --;
        }
    }
    gui_toolbar_get_bar_highlight_area(t, n, &item2_x1, &item2_y1, &item2_x2, &item2_y2);

    if (i < current_highlight_index)
    {
        /* head to tail */
        if (t->bar_highlight_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 1)
        {
            gui_toolbar_clear_bar_highlight(t);
            gui_toolbar_show_bar_highlight(t);
            
            t->bar_highlight_transition_offset = 0;
            t->bar_highlight_transition_times = 0;
            t->is_in_transition = MMI_FALSE;
        }
        else
        {
            t->bar_highlight_transition_offset = (item1_x2 - item1_x1 + 1 + GUI_TOOLBAR_BAR_GAP) / 
                GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES * (t->bar_highlight_transition_times + 1);

            gui_toolbar_clear_bar_highlight(t);

            gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);
            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            gdi_layer_push_clip();
            gdi_layer_set_clip(t->bar_x, item2_y1, t->bar_x + t->bar_width - 1, item2_y2);
            gdi_layer_flatten_with_clipping(h1, h2, h3, h4);
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            
            gdi_get_alpha_blending_source_layer(&old_src_layer);
            gdi_set_alpha_blending_source_layer(t->popout_menu_layer);
            
            gdi_layer_push_clip();
            gdi_layer_set_clip(item2_x1, item2_y1, item1_x2, item1_y2);            
            
            if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item2_x1, item2_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }
            
            if (t->toolbar_menu[current_highlight_index].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item1_x1, item1_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }
            
            gdi_image_draw(item2_x1 -  t->bar_highlight_transition_offset, item2_y1,
                (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));

            gdi_image_draw(item1_x1 + (item1_x2 - item1_x1 + 1) - t->bar_highlight_transition_offset, item1_y1,
                (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));

            gui_measure_image(t->toolbar_menu[current_highlight_index].icon_highlight, &width, &height);

            ix1 = item1_x1 + (item1_x2 - item1_x1 + 1 - width) / 2;
            iy1 = item1_y1 + (item1_y2 - item1_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[current_highlight_index].icon_highlight);
            
            gui_measure_image(t->toolbar_menu[i].icon_highlight, &width, &height);

            ix1 = item2_x1 + (item2_x2 - item2_x1 + 1 - width) / 2;
            iy1 = item2_y1 + (item2_y2 - item2_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[i].icon_highlight);            
                
            gdi_layer_pop_clip();
            gdi_set_alpha_blending_source_layer(old_src_layer);
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            t->bar_highlight_transition_times ++;
        }

    }
    else
    {
        if (t->bar_highlight_transition_times == GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES - 1)
        {
            gui_toolbar_clear_bar_highlight(t);
            gui_toolbar_show_bar_highlight(t);
            
            t->bar_highlight_transition_offset = 0;
            t->bar_highlight_transition_times = 0;
            t->is_in_transition = MMI_FALSE;
        }
        else
        {
            t->bar_highlight_transition_offset = (item2_x1 - item1_x1 + 1) / 
                GUI_TOOLBAR_POPOUT_MENU_TRANSITION_TIMES * (t->bar_highlight_transition_times + 1);

            gui_toolbar_clear_bar_highlight(t);

            gdi_layer_get_blt_layer(&h1, &h2, &h3, &h4);
            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            gdi_layer_push_clip();
            gdi_layer_set_clip(t->bar_x, item2_y1, t->bar_x + t->bar_width - 1, item2_y2);
            gdi_layer_flatten_with_clipping(h1, h2, h3, h4);
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            gdi_layer_lock_frame_buffer();
            gdi_layer_push_and_set_active(t->popout_menu_layer);
            
            gdi_get_alpha_blending_source_layer(&old_src_layer);
            gdi_set_alpha_blending_source_layer(t->popout_menu_layer);
            
            gdi_layer_push_clip();
            gdi_layer_set_clip(item1_x1, item1_y1, item2_x2, item2_y2);            
            
            if (t->toolbar_menu[i].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item2_x1, item2_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }
            
            if (t->toolbar_menu[current_highlight_index].state == MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT)
            {
                gdi_image_draw(item1_x1, item1_y1,
                    (PU8)GetImage(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE));
            }

            gdi_image_draw(item2_x1 -  t->bar_highlight_transition_offset, item2_y1,
                (PU8)GetImage(IMG_TOOLBAR_BAR_BG_INACTIVE));
            
            gui_measure_image(t->toolbar_menu[current_highlight_index].icon_highlight, &width, &height);

            ix1 = item1_x1 + (item1_x2 - item1_x1 + 1 - width) / 2;
            iy1 = item1_y1 + (item1_y2 - item1_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[current_highlight_index].icon_highlight);
            
            gui_measure_image(t->toolbar_menu[i].icon_highlight, &width, &height);

            ix1 = item2_x1 + (item2_x2 - item2_x1 + 1 - width) / 2;
            iy1 = item2_y1 + (item2_y2 - item2_y1 + 1 - height) / 2;
            gdi_image_draw(ix1, iy1, t->toolbar_menu[i].icon_highlight);            
                
            gdi_layer_pop_clip();
            
            gdi_set_alpha_blending_source_layer(old_src_layer);
            
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            t->bar_highlight_transition_times ++;
        }
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_reset_transition
 * DESCRIPTION
 *  reset transition
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_reset_transition(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_cancel_timer(gui_toolbar_transition_left_to_right_popout_menu);
    gui_cancel_timer(gui_toolbar_transition_right_to_left_popout_menu);

    if (t->current_popout_menu_keyhandler[0] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[0] = NULL;
    }
    if (t->current_popout_menu_keyhandler[1] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = NULL;
    }

    t->bar_highlight_transition_offset = 0;
    t->popout_menu_transition_offset = 0;
    t->title_transition_offset = 0;
    t->bar_highlight_transition_times = 0;
    t->popout_menu_transition_times = 0;
    
    if (t->is_in_transition)
    {
        t->is_in_transition = MMI_FALSE;
        gui_toolbar_close_popout_menu(t);
        gui_toolbar_open_popout_menu(t);
        gui_toolbar_redraw(t);
    }

    t->is_in_transition = MMI_FALSE;
#ifdef __MMI_OP12_CAT533_SUPPORT__
    wgui_cat533_resume_wallpaper();
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_reset_transition_ex
 * DESCRIPTION
 *  reset transition
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_reset_transition_ex(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    gui_cancel_timer(gui_toolbar_transition_left_to_right_popout_menu);
    gui_cancel_timer(gui_toolbar_transition_right_to_left_popout_menu);

    if (t->current_popout_menu_keyhandler[0] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[0], KEY_UP_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[0] = NULL;
    }
    if (t->current_popout_menu_keyhandler[1] != NULL)
    {
        SetKeyHandler(t->current_popout_menu_keyhandler[1], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        t->current_popout_menu_keyhandler[1] = NULL;
    }

    t->bar_highlight_transition_offset = 0;
    t->popout_menu_transition_offset = 0;
    t->title_transition_offset = 0;
    t->bar_highlight_transition_times = 0;
    t->popout_menu_transition_times = 0;
    t->is_in_transition = MMI_FALSE;
#ifdef __MMI_OP12_CAT533_SUPPORT__
    wgui_cat533_resume_wallpaper();
#endif   
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_transition_left_to_right
 * DESCRIPTION
 *  toolbar transition of left to right
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_transition_left_to_right(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    gui_toolbar_reset_transition_ex(t);
    t->is_in_transition = MMI_TRUE;
#ifdef __MMI_OP12_CAT533_SUPPORT__   
    wgui_cat533_pause_wallpaper();
#endif   
    gui_toolbar_transition_left_to_right_popout_menu();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_transition_right_to_left
 * DESCRIPTION
 *  toolbar transition of right to left
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_toolbar_transition_right_to_left(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);
    gui_toolbar_reset_transition_ex(t);
    t->is_in_transition = MMI_TRUE;
#ifdef __MMI_OP12_CAT533_SUPPORT__    
    wgui_cat533_pause_wallpaper(); 
#endif   
    gui_toolbar_transition_right_to_left_popout_menu();
}


/*****************************************************************************
 * FUNCTION
 *  gui_toolbar_is_active
 * DESCRIPTION
 *  toolbar active or not
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_toolbar_is_active(gui_toolbar_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    if (t->state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
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
 *  gui_toolbar_change_popout_menu_highlight
 * DESCRIPTION
 *  set popout menu highlight
 * PARAMETERS
 *  t       [IN]    pointer of toolbar
 *  index
 *  highlight_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_toolbar_change_popout_menu_highlight(gui_toolbar_struct *t, S32 index, S32 highlight_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t != NULL);

    t->toolbar_menu[index].highlight_menu_item = highlight_position;
}
#endif /* __MMI_OP12_TOOLBAR__ */


