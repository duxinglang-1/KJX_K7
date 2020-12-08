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
 *  gui_side_bar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sidebar - UI component
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

#include "MMI_features.h"

#ifdef __MMI_OP11_SIDEBAR__
#include "gui.h"
#include "gui_themes.h"
#include "gui_side_bar.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menuitems.h"
#include "gui_font_size.h"
#include "gui_touch_feedback.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

#include "MMIDataType.h"
#include "gui_theme_struct.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "PixcomFontEngine.h"
#include "CustThemesRes.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_include.h"
#include "wgui_categories_list.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "gui_scrollbars.h"
#include "gui_fixed_menus.h"
#include "CustDataRes.h"
#include "mmi_rp_app_uiframework_def.h"

static S32 gui_side_bar_transition_time = 0;
UI_side_bar_theme *current_side_bar_theme = NULL;
gui_side_bar_struct *current_side_bar_ptr = NULL;
static gdi_handle g_old_menu_act_layer = GDI_NULL_HANDLE;
static gdi_handle g_old_scrollbar_src_layer = GDI_NULL_HANDLE;
static U8 popout_menu_layer_opacity_value;
static BOOL popout_menu_layer_opacity_enable;
MMI_BOOL history_enter = MMI_FALSE;
static MMI_BOOL popout_menu_is_transition = MMI_FALSE;
static MMI_BOOL popout_menu_opacity_store = MMI_FALSE;

/* Temp theme for test */
UI_side_bar_theme temp_theme;


color popout_menu_bg_color = {255,255,255,50};
color popout_menu_border_color = {0,0,0,100};

color indicator_hint_bg_color = {255, 199, 0, 255};
color indicator_hint_bg_boder_color = {255,255,255,255};
color indicator_hint_text_color = {0,0,0,255};
stFontAttribute *indicator_hint_text_font = &MMI_sublcd_font;


UI_filled_area menu_highlight_filler={
UI_FILLED_AREA_TYPE_BITMAP,
NULL,
NULL,
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
0};


UI_filled_area menu_highlight_with_scrollbar_filler={
UI_FILLED_AREA_TYPE_BITMAP,
NULL,
NULL,
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
{0,0,0,100},
0};


static void gui_side_bar_HandleKeyUp(void);
static void gui_side_bar_HandleKeyDown(void);
static void gui_side_bar_HandleKeyLeft(void);
static void gui_side_bar_HandleKeyRight(void);
void gui_side_bar_open_popout_menu(gui_side_bar_struct *s);
void gui_side_bar_close_popout_menu(gui_side_bar_struct *s);
static void gui_side_bar_register_key_handler(void);
static void gui_side_bar_redraw_bar_background(gui_side_bar_struct *s);
static void gui_side_bar_get_bar_item_area(gui_side_bar_struct *s, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_side_bar_get_bar_item_highlight_area(gui_side_bar_struct *s, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_side_bar_redraw_bar_item(gui_side_bar_struct *s, S32 index);
static void gui_side_bar_get_popout_menu_list_area(gui_side_bar_struct *s, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_side_bar_get_popout_menu_bg_area(gui_side_bar_struct *s, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
static void gui_side_bar_clear_popout_menu_no_redraw(gui_side_bar_struct *s);
static void gui_side_bar_clear_popout_menu(gui_side_bar_struct *s);
static void gui_side_bar_clear_bar_highlight(gui_side_bar_struct *s);
static void gui_side_bar_redraw_bar_highlight(gui_side_bar_struct *s);
static void gui_side_bar_redraw_bar_highlight_background(gui_side_bar_struct *s);
static void gui_side_bar_redraw_bar_highlight_background_ex(gui_side_bar_struct *s);
static void gui_side_bar_redraw_popout_menu_background(gui_side_bar_struct *s);
static void gui_side_bar_popout_menu_hide_callback(S32 x1, S32 y1, S32 x2, S32 y2);
static void gui_side_bar_popout_menu_transition_callback(void);
static void gui_side_bar_redraw_popout_menu_transition(gui_side_bar_struct *s);
static void gui_side_bar_clear_indicators_by_line(gui_side_bar_struct *s, S32 index);
static void gui_side_bar_redraw_indicators_by_line(gui_side_bar_struct *s, S32 index);


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_set_current_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_set_current_theme(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    temp_theme.popout_menu_highlight_bg = &menu_highlight_filler;
    current_side_bar_theme = &temp_theme;

    s->bar_bg = current_side_bar_theme->bar_bg;
    s->bar_menu_highlight_bg = current_side_bar_theme->bar_menu_highlight_bg;
    s->popout_menu_highlight_bg = current_side_bar_theme->popout_menu_highlight_bg;
    s->popout_menu_top_bg = current_side_bar_theme->popout_menu_top_bg;
    s->popout_menu_middle_bg = current_side_bar_theme->popout_menu_middle_bg;
    s->popout_menu_bottom_bg = current_side_bar_theme->popout_menu_bottom_bg;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_set_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_set_theme(gui_side_bar_struct *s, UI_side_bar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);
    
    s->bar_bg = t->bar_bg;
    s->bar_menu_highlight_bg = t->bar_menu_highlight_bg;
    s->popout_menu_highlight_bg = t->popout_menu_highlight_bg;
    s->popout_menu_top_bg = t->popout_menu_top_bg;
    s->popout_menu_middle_bg = t->popout_menu_middle_bg;
    s->popout_menu_bottom_bg = t->popout_menu_bottom_bg;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_create(
            gui_side_bar_struct *s,
            S32 x, S32 y,
            S32 max_width,S32 max_height,
            GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer,
            S32 number_of_side_bar_menu, 
            PU8 *icons_of_side_bar_menu_normal, PU8 *icons_of_side_bar_menu_highlight,
            wgui_sidebar_getindicator_funcptr_type *get_indicators_callback, 
            wgui_sidebar_getmenudata_funcptr_type *get_menu_data_callback,
            wgui_sidebar_popout_menu_highlighthandler_funcptr_type *menu_highlight_handler)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    s->x = x;
    s->y = y;
    s->side_bar_max_width = max_width;
    s->side_bar_max_height = max_height;
    s->bar_x = s->x;
    s->bar_y = s->y + GUI_SIDE_BAR_TOP_BOTTOM_GAP;
    s->bar_width = GUI_SIDE_BAR_BAR_WIDTH;
    s->bar_height = s->side_bar_max_height - GUI_SIDE_BAR_TOP_BOTTOM_GAP * 2;
    
    s->state = MMI_GUI_SIDE_BAR_STATE_INACTIVE;
    
    s->side_bar_layer = side_bar_layer;
    s->popout_menu_layer = popout_menu_layer;
    s->wallpaper_layer = wallpaper_layer;
    
    if (number_of_side_bar_menu <= 0)
    {
        return;
    }
    
    s->side_bar_menu_number = number_of_side_bar_menu;

    s->side_bar_highlighted_menu = -1;

    for( i = 0; i< s->side_bar_menu_number; i ++)
    {
        if (icons_of_side_bar_menu_normal != NULL)
        {
            s->side_bar_menu[i].icon_normal = icons_of_side_bar_menu_normal[i];
        }
        else
        {
            MMI_DBG_ASSERT(0);
        }
        
        if (icons_of_side_bar_menu_highlight != NULL)
        {
            s->side_bar_menu[i].icon_highlight = icons_of_side_bar_menu_highlight[i];
        }
        else
        {
            MMI_DBG_ASSERT(0);
        }
        
        if (get_indicators_callback != NULL) 
        {
            s->side_bar_menu[i].get_indicators_callback = get_indicators_callback[i];
        }
        else
        {
            MMI_DBG_ASSERT(0);
        }
        
        if (get_menu_data_callback != NULL)
        {
            s->side_bar_menu[i].get_menu_data_callback = get_menu_data_callback[i];
        }
        else
        {
            MMI_DBG_ASSERT(0);
        }
        
        s->side_bar_menu[i].menu_highlight_handler = menu_highlight_handler[i];

        s->side_bar_menu[i].popout_menu_item_height= GUI_SIDE_BAR_POPOUT_MENUITEM_HEIGHT;
        
        for (j = 0; j < MAX_SUB_MENUS; j ++)
        {
            s->side_bar_menu[i].list_of_items[j] = subMenuData[j];
        }

    }


    current_side_bar_ptr = s;

    for (i = 0; i < MAX_KEY_TYPE; i ++)
    {
        s->AppLeftRightKeyHandler[0][i] = NULL;
        s->AppLeftRightKeyHandler[1][i] = NULL;
    }

    s->side_bar_highlight_handler = NULL;

    gui_side_bar_set_current_theme(s);

    s->current_popout_menu_highlight_index = -1;
    s->current_popup_menu_first_display_item = -1;
    s->current_popup_menu_last_display_item = -1;

    g_old_menu_act_layer = wgui_fixed_list_get_active_layer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_move(gui_side_bar_struct *s, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);
    
    s->x = x;
    s->y = y;
    s->bar_x = s->x;
    s->bar_y = s->y + GUI_SIDE_BAR_TOP_BOTTOM_GAP;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_resize(gui_side_bar_struct *s, S32 max_width, S32 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    s->side_bar_max_width = max_width;
    s->side_bar_max_height = max_height;

    s->bar_width = GUI_SIDE_BAR_BAR_WIDTH;
    s->bar_height = s->side_bar_max_height - GUI_SIDE_BAR_TOP_BOTTOM_GAP * 2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_set_layers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_set_layers(gui_side_bar_struct *s, 
    GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    s->side_bar_layer = side_bar_layer;
    s->popout_menu_layer = popout_menu_layer;
    s->wallpaper_layer = wallpaper_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_redraw(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    /* Draw bar */
    gui_side_bar_redraw_bar(s);
   
    if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
        gui_side_bar_redraw_indicators(s);
    }
    
    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP)
    {
        gui_side_bar_redraw_indicators(s);

        gui_side_bar_redraw_bar_highlight_background_ex(s);
        gui_side_bar_redraw_bar_highlight(s);
    }

    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE || s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
    {
        gui_side_bar_redraw_popout_menu(s);

        gui_side_bar_redraw_indicators(s);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_show(gui_side_bar_struct *s)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    gui_side_bar_register_key_handler();

    /* Draw bar */
    gui_side_bar_redraw(s);
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_close(gui_side_bar_struct *s)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(s != NULL);

    gui_side_bar_transition_time = 0;
    gui_cancel_timer(gui_side_bar_popout_menu_transition_callback);
    popout_menu_is_transition = MMI_FALSE;

    gui_side_bar_close_popout_menu(s);
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_update_indicators
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_update_indicators(gui_side_bar_struct *s, S32 side_bar_menu_index)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (side_bar_menu_index < 0 || side_bar_menu_index >= s->side_bar_menu_number)
    {
        return;
    }

    gui_side_bar_clear_indicators_by_line(s, side_bar_menu_index);
    
    gui_side_bar_redraw_indicators_by_line(s, side_bar_menu_index);

    gui_side_bar_get_bar_item_area(s, side_bar_menu_index, &x1, &y1, &x2, &y2);

    x1 = s->x;
    x2 = s->x + s->side_bar_max_width - 1;

    gdi_layer_blt_previous(x1, y1, x2, y2);
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_register_left_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_register_left_arrow_key_handler(gui_side_bar_struct *s, FuncPtr funcPtr, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    MMI_DBG_ASSERT(keyType < MAX_KEY_TYPE);
    
    s->AppLeftRightKeyHandler[0][keyType] = funcPtr;

    if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
    SetKeyHandler(funcPtr, KEY_LEFT_ARROW, keyType);
}
    else
    {
        SetKeyHandler(gui_side_bar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(gui_side_bar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_register_right_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_register_right_arrow_key_handler(gui_side_bar_struct *s, FuncPtr funcPtr, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    MMI_DBG_ASSERT(keyType < MAX_KEY_TYPE);
    
    s->AppLeftRightKeyHandler[1][keyType] = funcPtr;

    if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
    SetKeyHandler(funcPtr, KEY_RIGHT_ARROW, keyType);
}
    else
    {
        SetKeyHandler(gui_side_bar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(gui_side_bar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_HandleKeyUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_HandleKeyUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;
    U16 keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;
    MMI_DBG_ASSERT(s != NULL);

    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        s->side_bar_highlighted_menu --;

        if (s->side_bar_highlighted_menu < 0)
        {
            s->side_bar_highlighted_menu = s->side_bar_menu_number - 1;
        }
        gui_side_bar_clear_popout_menu_no_redraw(s);
        gui_side_bar_close(s);
        gui_side_bar_open_popout_menu(s);
        gui_side_bar_redraw_popout_menu_transition(s);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE;

        s->side_bar_highlighted_menu = 0;

        
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
        {
            SetKeyHandler(NULL, KEY_LEFT_ARROW, keyType);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, keyType);
        }

        SetKeyHandler(gui_side_bar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(gui_side_bar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        
        gui_side_bar_clear_popout_menu_no_redraw(s);
        gui_side_bar_open_popout_menu(s);
        gui_side_bar_redraw_popout_menu_transition(s);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
    {
        fixed_list_goto_previous_item();
        
        gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP)
    {
        gui_side_bar_clear_bar_highlight(s);
        
        s->side_bar_highlighted_menu --;
        
        if (s->side_bar_highlighted_menu < 0)
        {
            s->side_bar_highlighted_menu = s->side_bar_menu_number - 1;
        }
        
        gui_side_bar_redraw_bar_highlight_background_ex(s);
        gui_side_bar_redraw_bar_highlight(s);
        
        gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_HandleKeyDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_HandleKeyDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;
    U16 keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;
    MMI_DBG_ASSERT(s != NULL);

    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        s->side_bar_highlighted_menu ++;

        if (s->side_bar_highlighted_menu >= s->side_bar_menu_number)
        {
            s->side_bar_highlighted_menu = 0;
        }
        
        gui_side_bar_clear_popout_menu_no_redraw(s);
        gui_side_bar_close(s);
        gui_side_bar_open_popout_menu(s);
        gui_side_bar_redraw_popout_menu_transition(s);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE;
        
        s->side_bar_highlighted_menu = 0;

        
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
        {
            SetKeyHandler(NULL, KEY_LEFT_ARROW, keyType);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, keyType);
        }

        SetKeyHandler(gui_side_bar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(gui_side_bar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        
        gui_side_bar_clear_popout_menu_no_redraw(s);
        gui_side_bar_open_popout_menu(s);
        gui_side_bar_redraw_popout_menu_transition(s);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
    {
        fixed_list_goto_next_item();
        gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP)
    {
        gui_side_bar_clear_bar_highlight(s);
        
        s->side_bar_highlighted_menu ++;
        
        if (s->side_bar_highlighted_menu >= s->side_bar_menu_number)
        {
            s->side_bar_highlighted_menu = 0;
        }
        
        gui_side_bar_redraw_bar_highlight_background_ex(s);
        gui_side_bar_redraw_bar_highlight(s);
        
        gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_HandleKeyLeft
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_HandleKeyLeft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;
    U16 keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;
    MMI_DBG_ASSERT(s != NULL);

    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP;
        
        gui_side_bar_clear_popout_menu_no_redraw(s);

        gui_side_bar_close_popout_menu(s);

        gui_side_bar_redraw_indicators(s);

        gui_side_bar_redraw_bar_highlight_background_ex(s);
        gui_side_bar_redraw_bar_highlight(s);
        
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE;
        fixed_list_goto_item(-1);
        
        if (s->side_bar_highlight_handler != NULL)
        {
            s->side_bar_highlight_handler(s->side_bar_highlighted_menu);
        }
        gui_side_bar_register_key_handler();
        gui_side_bar_redraw_popout_menu(s);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_INACTIVE;
        gui_side_bar_clear_bar_highlight(s);
        
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
        {
            SetKeyHandler(s->AppLeftRightKeyHandler[0][keyType], KEY_LEFT_ARROW, keyType);
            SetKeyHandler(s->AppLeftRightKeyHandler[1][keyType], KEY_RIGHT_ARROW, keyType);
        }
        
    }
    else
    {
        return;
    }
    
    gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_HandleKeyRight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_HandleKeyRight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;
    MMI_DBG_ASSERT(s != NULL);

    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;
        fixed_list_goto_home();
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE;
        gui_side_bar_open_popout_menu(s);
        fixed_list_goto_item(-1);
        gui_side_bar_redraw_popout_menu_transition(s);
    }
    else
    {
        return;
    }
    
    gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_HandleKeyCSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_HandleKeyCSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;
    U16 keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;
    MMI_DBG_ASSERT(s != NULL);

    if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE;
        
        s->side_bar_highlighted_menu = 0;

        
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
        {
            SetKeyHandler(NULL, KEY_LEFT_ARROW, keyType);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, keyType);
        }

        SetKeyHandler(gui_side_bar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(gui_side_bar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        
        gui_side_bar_clear_popout_menu_no_redraw(s);
        gui_side_bar_open_popout_menu(s);
        gui_side_bar_redraw_popout_menu_transition(s);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE;
        gui_side_bar_open_popout_menu(s);
        fixed_list_goto_item(-1);
        gui_side_bar_redraw_popout_menu_transition(s);
        gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    }
    else if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;
        fixed_list_goto_home();
        gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_open_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_open_popout_menu(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_fixed_text_menuitem_theme menu_theme;
    S32 menu_x1, menu_y1, menu_x2, menu_y2, menu_width, menu_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    
    if (s->side_bar_menu[s->side_bar_highlighted_menu].get_menu_data_callback == NULL)
    {
        return;
    }

    s->side_bar_menu[s->side_bar_highlighted_menu].get_menu_data_callback(
        &s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items,
        s->side_bar_menu[s->side_bar_highlighted_menu].list_of_items,
        &s->side_bar_menu[s->side_bar_highlighted_menu].time_menuitem_index,
        s->side_bar_menu[s->side_bar_highlighted_menu].flags_is_data,
        MAX_SUB_MENUS); 

    if (s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items <= 0 
        || s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items > MAX_SUB_MENUS) 
    {
        return;
    }

    wgui_fixed_list_create_text_menu(s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items,
        -1, WGUI_LIST_MENU_DISABLE_SHORTCUT|WGUI_LIST_MENU_DISABLE_VOL_KEY, 0, NULL);

    wgui_fixed_list_begin_add_text_one_item();
    for (i = 0; i < s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items; i++)
    {
        wgui_fixed_list_add_text_one_item(i, s->side_bar_menu[s->side_bar_highlighted_menu].list_of_items[i], NULL);

        if (s->side_bar_menu[s->side_bar_highlighted_menu].flags_is_data[i])
        {
            MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_SHOW_DATA;
        }
    }

    if (s->side_bar_menu[s->side_bar_highlighted_menu].time_menuitem_index >= 0 
        &&s->side_bar_menu[s->side_bar_highlighted_menu].time_menuitem_index < s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items)
    {
        MMI_fixed_icontext_menuitems[s->side_bar_menu[s->side_bar_highlighted_menu].time_menuitem_index].ext_flags |= UI_MENUITEM_EXT_SHOW_TIME;
    }
    
    wgui_fixed_list_end_add_text_one_item();

    wgui_fixed_list_register_hide_function(gui_side_bar_popout_menu_hide_callback);

    gui_vertical_scrollbar_register_hide_callback(&MMI_fixed_list_menu.vbar, gui_side_bar_popout_menu_hide_callback);
    
    g_old_scrollbar_src_layer = gui_vertical_scrollbar_get_alpha_blend_layer(&MMI_fixed_list_menu.vbar);
    gui_vertical_scrollbar_set_alpha_blend_layer(&MMI_fixed_list_menu.vbar, s->popout_menu_layer);
    
    menu_theme.disabled_filler = current_fixed_icontext_menuitem_theme->disabled_filler;
    menu_theme.disabled_text_color = current_fixed_icontext_menuitem_theme->disabled_text_color;
    menu_theme.flags = current_fixed_icontext_menuitem_theme->flags;
    menu_theme.focussed_text_color = current_fixed_icontext_menuitem_theme->focussed_text_color;
    menu_theme.normal_filler = current_fixed_icontext_menuitem_theme->normal_filler;
    menu_theme.normal_text_color = current_fixed_icontext_menuitem_theme->normal_text_color;
    menu_theme.selected_text_color = current_fixed_icontext_menuitem_theme->selected_text_color;
    menu_theme.text_font = current_fixed_icontext_menuitem_theme->text_font;
    
    menu_highlight_filler.b = (PU8)GetImage(IMG_SIDE_BAR_MENU_HIGHLIGHT_WITHOUT_SCROLLBAR);
    menu_highlight_with_scrollbar_filler.b = (PU8)GetImage(IMG_SIDE_BAR_MENU_HIGHLIGHT_WITH_SCROLLBAR);
    
    menu_theme.selected_filler= &menu_highlight_with_scrollbar_filler;
    menu_theme.focussed_filler = &menu_highlight_with_scrollbar_filler;
    menu_theme.focussed_without_sc_filler = &menu_highlight_filler;
    
    gui_side_bar_get_popout_menu_list_area(s, &menu_x1, &menu_y1, &menu_x2, &menu_y2);
    menu_width = menu_x2 - menu_x1 + 1;
    menu_height = menu_y2 - menu_y1 + 1;

    s->side_bar_menu[s->side_bar_highlighted_menu].popout_menu_item_width= menu_width;

    
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
    
    wgui_fixed_list_set_active_layer(s->popout_menu_layer);

    wgui_fixed_list_set_alpha_blending_layer(s->popout_menu_layer);
        
    resize_fixed_text_menuitems(0,
        s->side_bar_menu[s->side_bar_highlighted_menu].popout_menu_item_height);
    
    wgui_fixed_list_move_text_menu(menu_x1 - 1, menu_y1 - 1);

    wgui_fixed_list_resize_text_menu(menu_width, menu_height);

    resize_fixed_text_menuitems_to_list_width();
        
    MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_MARQUEE_SCROLL;
    
    MMI_fixed_list_menu.focussed_filler = s->popout_menu_highlight_bg;

    gui_set_fixed_text_menuitem_theme(&MMI_fixed_icontext_menuitem,&menu_theme);

    /* Grab key handler*/
    
    gui_side_bar_register_key_handler();

    /* Register highlight handler */
    RegisterHighlightHandler(s->side_bar_menu[s->side_bar_highlighted_menu].menu_highlight_handler);

    /* Set font of list */
    wgui_fixed_list_set_data_layout(GUI_SIDE_BAR_PUPOUT_MENU_DATA_FONT, GUI_SIDE_BAR_POPOUT_MENU_GAP);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_close_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_close_popout_menu(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (g_old_menu_act_layer != GDI_NULL_HANDLE)
    {
        wgui_fixed_list_set_active_layer(g_old_menu_act_layer);
    }
    g_old_scrollbar_src_layer = GDI_NULL_HANDLE;
    gui_vertical_scrollbar_set_alpha_blend_layer(&MMI_fixed_list_menu.vbar, g_old_scrollbar_src_layer);
    gui_vertical_scrollbar_reset_hide_callback(&MMI_fixed_list_menu.vbar);

    gui_cancel_timer(gui_side_bar_popout_menu_transition_callback);
    popout_menu_is_transition = MMI_FALSE;

    if (popout_menu_opacity_store)
    {
        gdi_layer_push_and_set_active(s->popout_menu_layer);
        gdi_layer_set_opacity(popout_menu_layer_opacity_enable, popout_menu_layer_opacity_value);
        gdi_layer_pop_and_restore_active();
    }

    /* Reset list */

    reset_fixed_list();
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;

    /* Grab key handler*/
    
    gui_side_bar_register_key_handler();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_register_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_register_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetKeyHandler(gui_side_bar_HandleKeyUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_side_bar_HandleKeyUp, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_side_bar_HandleKeyDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_side_bar_HandleKeyDown, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_side_bar_HandleKeyCSK, KEY_ENTER, KEY_EVENT_DOWN);
    SetCenterSoftkeyFunction(gui_side_bar_HandleKeyCSK, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_get_bar_item_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_get_bar_item_area(gui_side_bar_struct *s, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 icon_space;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (index >= s->side_bar_menu_number)
    {
        return;
    }
    
    icon_space = (s->side_bar_max_height - GUI_SIDE_BAR_AROUND_GAP * 2 - GUI_SIDE_BAR_TOP_BOTTOM_GAP * 2 - GUI_SIDE_BAR_ICON_SIZE * s->side_bar_menu_number) / (s->side_bar_menu_number - 1);

    *x1 = s->x + GUI_SIDE_BAR_AROUND_GAP;
    *y1 = s->bar_y + (icon_space + GUI_SIDE_BAR_ICON_SIZE) * index + GUI_SIDE_BAR_AROUND_GAP;
    *x2 = *x1 + GUI_SIDE_BAR_ICON_SIZE - 1;
    *y2 = *y1 + GUI_SIDE_BAR_ICON_SIZE - 1;

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_get_bar_item_highlight_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_get_bar_item_highlight_area(gui_side_bar_struct *s, S32 index, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 temp_x1, temp_y1, temp_x2, temp_y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    
    gui_side_bar_get_bar_item_area(s, index, &temp_x1, &temp_y1, &temp_x2, &temp_y2);

    *x1 = temp_x1 - GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER;
    *y1 = temp_y1 - GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER;
    *x2 = s->bar_x + s->bar_width - 1 + GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT;
    *y2 = temp_y2 + GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER;
    *y2 += GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_bar_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_bar_background(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gdi_handle old_src_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    
    gdi_layer_push_and_set_active(s->side_bar_layer);
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(s->wallpaper_layer);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(s->bar_x, s->bar_y, s->bar_x + s->bar_width - 1, s->bar_y + s->bar_height - 1);
    gdi_image_draw_id(s->bar_x, s->bar_y, IMG_SIDE_BAR_LEFT);
    gdi_layer_pop_clip();
    
    gdi_set_alpha_blending_source_layer(old_src_layer);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_bar_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_bar_item(gui_side_bar_struct *s, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1, y1, x2, y2, x, y, width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (index >= s->side_bar_menu_number)
    {
        return;
    }

    gui_side_bar_get_bar_item_area(s, index, &x1, &y1, &x2, &y2);

    gdi_layer_push_and_set_active(s->side_bar_layer);

    gdi_image_get_dimension(s->side_bar_menu[index].icon_normal, &width, &height);
    x = x1 + ((x2 - x1 + 1 - width) >> 1);
    y = y1 + ((y2 - y1 + 1 - height) >> 1);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_draw(x, y, s->side_bar_menu[index].icon_normal);
    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_redraw_bar(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    gui_side_bar_redraw_bar_background(s);

    for (index = 0; index < s->side_bar_menu_number; index ++)
    {
        gui_side_bar_redraw_bar_item(s, index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_get_popout_menu_list_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_get_popout_menu_list_area(gui_side_bar_struct *s, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 popout_menu_item_count, index;
    S32 min_y, max_y, temp_x1, temp_y1, temp_x2, temp_y2;
    S32 i;
    S32 menu_y1, menu_y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    index = s->side_bar_highlighted_menu;
    popout_menu_item_count = s->side_bar_menu[index].number_of_popout_menu_items;

    if (popout_menu_item_count <=0)
    {
        popout_menu_item_count = 1;
    }

    s->side_bar_menu[index].reach_top = MMI_FALSE;
    s->side_bar_menu[index].reach_bottom = MMI_FALSE;

    /* Get the min&max y of popout list area */
    //gui_side_bar_get_bar_item_highlight_area(s, 0, &temp_x1, &temp_y1, &temp_x2, &temp_y2);

    min_y = s->y/*temp_y1*/ + GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER + GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y;

    //gui_side_bar_get_bar_item_highlight_area(s, s->side_bar_menu_number - 1, &temp_x1, &temp_y1, &temp_x2, &temp_y2);

    max_y = s->y + s->side_bar_max_height - 1/*temp_y2*/ - GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH;

    /* Get popout list area */
    gui_side_bar_get_bar_item_area(s, index, &temp_x1, &temp_y1, &temp_x2, &temp_y2);
    menu_y1 = temp_y1 + GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y;
    menu_y2 = menu_y1 - 1;
    
    for (i = 0; i < popout_menu_item_count; i ++)
    {
        if (!s->side_bar_menu[index].reach_top && !s->side_bar_menu[index].reach_bottom)
        {
            menu_y2 += (s->side_bar_menu[index].popout_menu_item_height);
            if (menu_y2 > max_y)
            {
                menu_y2 -= (s->side_bar_menu[index].popout_menu_item_height);
                s->side_bar_menu[index].reach_bottom = MMI_TRUE;
            }
        }
        
        if (!s->side_bar_menu[index].reach_top && s->side_bar_menu[index].reach_bottom)
        {
            menu_y1 -= (s->side_bar_menu[index].popout_menu_item_height);

            if (menu_y1 < min_y)
            {
                menu_y1 += (s->side_bar_menu[index].popout_menu_item_height);
                s->side_bar_menu[index].reach_top = MMI_TRUE;
            }
        }

        if (s->side_bar_menu[index].reach_top && s->side_bar_menu[index].reach_bottom)
        {
            break;
        }
    }

    *x1 = s->x + s->bar_width 
        + GUI_SIDE_BAR_POPOUT_MENU_AROUND_GAP + GUI_SIDE_BAR_POPOUT_MENUITEM_GAP
        + GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT;
    *y1 = menu_y1;
    *x2 = s->x + s->side_bar_max_width - 1 -(GUI_SIDE_BAR_POPOUT_MENU_AROUND_GAP + GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT);
    *y2 = menu_y2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_get_popout_menu_bg_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_get_popout_menu_bg_area(gui_side_bar_struct *s, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    //S32 temp_x1, temp_y1, temp_x2, temp_y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);
    
    gui_side_bar_get_popout_menu_list_area(s, x1, y1, x2, y2);

    *x1 = s->bar_x + s->bar_width + GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT;
    *x2 = s->x + s->side_bar_max_width - 1;
    *y1 -= (GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER + GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y);
    *y2 += (GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER + (GUI_SIDE_BAR_ICON_SIZE - GUI_SIDE_BAR_POPOUT_MENUITEM_HEIGHT - GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y));
    /*if (s->side_bar_highlighted_menu == s->side_bar_menu_number - 1)
    {
        gui_side_bar_get_bar_item_highlight_area(s, s->side_bar_menu_number - 1, &temp_x1, &temp_y1, &temp_x2, &temp_y2);
        *y1 = temp_y2 - *y2 + *y1;
        *y2 = temp_y2;
        *y1 -= GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH;
    }
    else*/
    {
        *y2 += GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_clear_popout_menu_no_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_clear_popout_menu_no_redraw(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    x1 = s->x;
    y1 = s->y;
    x2 = s->x + s->side_bar_max_width - 1;
    y2 = s->y + s->side_bar_max_height - 1;

    gdi_layer_push_and_set_active(s->popout_menu_layer);

    gdi_layer_push_clip();

    gdi_layer_set_clip(x1, y1, x2, y2);

    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_clear_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_clear_popout_menu(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    x1 = s->x;
    y1 = s->y;
    x2 = s->x + s->side_bar_max_width - 1;
    y2 = s->y + s->side_bar_max_height - 1;

    gui_side_bar_clear_popout_menu_no_redraw(s);

    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_popout_menu_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_popout_menu_hide_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;

    MMI_DBG_ASSERT(s != NULL);

    /* redraw pop out menu background */
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2 + 1, y2 + 1);
    
    gui_side_bar_redraw_popout_menu_background(s);
    
    gdi_layer_pop_clip();
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_clear_bar_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_clear_bar_highlight(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    index = s->side_bar_highlighted_menu;

    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }

    gdi_layer_push_and_set_active(s->popout_menu_layer);

    gui_side_bar_get_bar_item_highlight_area(s, index, &hl_bg_x1, &hl_bg_y1, &hl_bg_x2, &hl_bg_y2);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(hl_bg_x1, hl_bg_y1, hl_bg_x2 + 2, hl_bg_y2);

    gdi_draw_solid_rect(hl_bg_x1, hl_bg_y1, hl_bg_x2 + 2, hl_bg_y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_bar_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_bar_highlight(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_src_layer;    
    S32 x1, y1, x2, y2, x, y, width, height;
    S32 hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    index = s->side_bar_highlighted_menu;

    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }

    gdi_layer_push_and_set_active(s->popout_menu_layer);
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(s->side_bar_layer);

    /* draw highlight side bar menu */
    gui_side_bar_get_bar_item_area(s, index, &x1, &y1, &x2, &y2);

    gdi_image_get_dimension(s->side_bar_menu[s->side_bar_highlighted_menu].icon_highlight, &width, &height);
    x = x1 + ((x2 - x1 + 1 - width) >> 1);
    y = y1 + ((y2 - y1 + 1 - height) >> 1);
    
    gui_side_bar_get_bar_item_highlight_area(s, index, &hl_bg_x1, &hl_bg_y1, &hl_bg_x2, &hl_bg_y2);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2);

    gdi_image_draw(x, y, s->side_bar_menu[index].icon_highlight);
    
    gdi_layer_pop_clip();
    gdi_set_alpha_blending_source_layer(old_src_layer);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_bar_highlight_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_bar_highlight_background(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    index = s->side_bar_highlighted_menu;

    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }

    gdi_layer_push_and_set_active(s->popout_menu_layer);

    gui_side_bar_get_bar_item_highlight_area(s, index, &hl_bg_x1, &hl_bg_y1, &hl_bg_x2, &hl_bg_y2);
    
    gdi_layer_push_clip();
    //if (s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items == 1)
    {
        gdi_layer_set_clip(hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2);
    }
    /*else
    {
    gdi_layer_set_clip(hl_bg_x1, hl_bg_y1, hl_bg_x2 + 2, hl_bg_y2);
    }*/

    gdi_image_draw_id(hl_bg_x1, hl_bg_y1, IMG_SIDE_BAR_MENU_LEFT);

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_bar_highlight_background_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_bar_highlight_background_ex(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    index = s->side_bar_highlighted_menu;

    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }

    gdi_layer_push_and_set_active(s->popout_menu_layer);

    gui_side_bar_get_bar_item_highlight_area(s, index, &hl_bg_x1, &hl_bg_y1, &hl_bg_x2, &hl_bg_y2);

    hl_bg_x2 = s->bar_x + s->bar_width - 1;
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(hl_bg_x1, hl_bg_y1, hl_bg_x2, hl_bg_y2);

    gdi_image_draw_id(hl_bg_x1, hl_bg_y1, IMG_SIDE_BAR_MENU_LEFT);

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_popout_menu_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_popout_menu_background(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gdi_handle old_src_layer;    
    S32 menu_x1, menu_y1, menu_x2, menu_y2;
    S32 i, x, y, w, h, middle_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    gdi_layer_push_and_set_active(s->popout_menu_layer);
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(s->wallpaper_layer);


    /* draw popout menu background */
    gui_side_bar_get_popout_menu_bg_area(s, &menu_x1, &menu_y1, &menu_x2, &menu_y2);

    /* Draw top image */
    x= menu_x1;
    y = menu_y1;
   
    if ((s->side_bar_menu[s->side_bar_highlighted_menu].reach_bottom == MMI_TRUE) && 
        (s->side_bar_highlighted_menu != 0) && 
        (s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items != 1))
    {
        gdi_image_draw_id(x, y, IMG_SIDE_BAR_MENU_TOP);
        gdi_image_get_dimension_id(IMG_SIDE_BAR_MENU_TOP, &w, &h);
    }
    else
    {
        gdi_image_draw_id(x, y, IMG_SIDE_BAR_MENU_TOP2);
        gdi_image_get_dimension_id(IMG_SIDE_BAR_MENU_TOP2, &w, &h);
    }
    y += h;

    /* Draw middle image */
    middle_count = s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items - 2;
    if (middle_count > 0)
    {
        for (i = 0; i < middle_count; i ++)
        {
            if (y + h > menu_y2)
            {
                break;
            }
            
            gdi_image_draw_id(x, y, IMG_SIDE_BAR_MENU_MIDDLE);
            gdi_image_get_dimension_id(IMG_SIDE_BAR_MENU_MIDDLE, &w, &h);
            
            y += h;
        }
    }

    /* Draw bottom image */
    if (s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items == 1)
    {
        x= menu_x1;
        y = menu_y1 + 2;
        
            gdi_image_draw_id(x, y, IMG_SIDE_BAR_MENU_BOTTOM2);
        }
        else
        {
        if (y + h > menu_y2)
        {
            y -= h;
        }
        
        if (s->side_bar_highlighted_menu == s->side_bar_menu_number - 1)
        {
            gdi_image_draw_id(x, y, IMG_SIDE_BAR_MENU_BOTTOM2);
        }
        else
        {
            gdi_image_draw_id(x, y, IMG_SIDE_BAR_MENU_BOTTOM);
        }
    }
    
    gdi_image_abm_set_source_layer(old_src_layer);
    gdi_layer_pop_and_restore_active();

}



/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_redraw_popout_menu(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (history_enter)
    {
        gui_side_bar_open_popout_menu(s);
        history_enter = MMI_FALSE;
    }

    if (popout_menu_is_transition)
    {
        return;
    }

    if (s->side_bar_menu[s->side_bar_highlighted_menu].get_menu_data_callback == NULL)
    {
        return;
    }

    if (s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items <= 0 
        || s->side_bar_menu[s->side_bar_highlighted_menu].number_of_popout_menu_items > MAX_SUB_MENUS) 
    {
        return;
    }

    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE || s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
    {
        if (s->side_bar_highlighted_menu != s->side_bar_menu_number - 1
            && !s->side_bar_menu[s->side_bar_highlighted_menu].reach_bottom)
        {
            /* redraw popout menu background */
            gui_side_bar_redraw_popout_menu_background(s);
            
            /* redraw side bar highlight background */
            gui_side_bar_redraw_bar_highlight_background(s);
        }
        else
        {
            /* redraw side bar highlight background */
            gui_side_bar_redraw_bar_highlight_background(s);
            
            /* redraw popout menu background */
            gui_side_bar_redraw_popout_menu_background(s);
        }
        
        /* redraw side bar highlight*/
        gui_side_bar_redraw_bar_highlight(s);
        
    }

    /* draw menu component */

    gdi_layer_push_and_set_active(s->popout_menu_layer); 
    if (s->current_popup_menu_first_display_item >= 0 && ((s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP && s->current_popout_menu_highlight_index != -1) || s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE))
    {
        MMI_fixed_list_menu.first_displayed_item = s->current_popup_menu_first_display_item;
        MMI_fixed_list_menu.last_displayed_item = s->current_popup_menu_last_display_item;
        if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
        {
            fixed_list_goto_item(s->current_popout_menu_highlight_index);
        }
        s->current_popout_menu_highlight_index = -1;
        s->current_popup_menu_first_display_item = -1;
        s->current_popup_menu_last_display_item = -1;
    }

    show_fixed_list();
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_popout_menu_transition_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_popout_menu_transition_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    gui_side_bar_struct *s;
    S32 x1, y1, x2, y2, menu_x1, menu_y1, menu_x2, menu_y2;
    U8  opacity_offset, current_opacity;
    S32 t_x1, t_y1, t_x2, t_y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = current_side_bar_ptr;

    MMI_DBG_ASSERT(s != NULL);
    
    gui_side_bar_get_popout_menu_bg_area(s, &menu_x1, &menu_y1, &menu_x2, &menu_y2);
    
    x1 = s->x;
    x2 = s->x + s->side_bar_max_width * (gui_side_bar_transition_time + 1) / GUI_SIDE_BAR_POPOUT_MENU_TRANSITION_TIMES;
    t_x1 = x2 + 1;
    t_x2 = s->x + s->side_bar_max_width;
    
    if (gui_side_bar_transition_time == GUI_SIDE_BAR_POPOUT_MENU_TRANSITION_TIMES)
    {
        x2 = s->x + s->side_bar_max_width - 1;
    }
    
    y1 = menu_y1;
    y2 = menu_y2;
    t_y1 = y1;
    t_y2 = y2;

    
    gdi_layer_push_and_set_active(s->popout_menu_layer);
    
    if (gui_side_bar_transition_time == 0)
    {
    gdi_layer_get_opacity(&popout_menu_layer_opacity_enable, &popout_menu_layer_opacity_value);
        popout_menu_opacity_store = MMI_TRUE;
    }
    
        opacity_offset = (255 - popout_menu_layer_opacity_value) / GUI_SIDE_BAR_POPOUT_MENU_TRANSITION_TIMES;
        current_opacity = opacity_offset * gui_side_bar_transition_time;
        
        if (gui_side_bar_transition_time == GUI_SIDE_BAR_POPOUT_MENU_TRANSITION_TIMES)
        {
            gdi_layer_set_opacity(popout_menu_layer_opacity_enable, popout_menu_layer_opacity_value);
        }
        else
        {
            gdi_layer_set_opacity(TRUE, current_opacity);
        }

        gdi_layer_lock_frame_buffer();

    popout_menu_is_transition = MMI_FALSE;

        gui_side_bar_redraw_popout_menu(s);

    popout_menu_is_transition = MMI_TRUE;

    gdi_layer_push_and_set_active(s->popout_menu_layer);
    gdi_draw_solid_rect(t_x1, t_y1, t_x2, t_y2, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

        gdi_layer_unlock_frame_buffer();
        
        GDI_LCD->blt_rect_is_used = FALSE;
        
        gdi_layer_blt_previous(x1, y1, x2, y2);
        
        
        gdi_layer_pop_and_restore_active();
        
        if (gui_side_bar_transition_time == GUI_SIDE_BAR_POPOUT_MENU_TRANSITION_TIMES)
        {
        
        gdi_layer_push_and_set_active(s->popout_menu_layer);
        gdi_layer_set_opacity(popout_menu_layer_opacity_enable, popout_menu_layer_opacity_value);
        gdi_layer_pop_and_restore_active();

            gui_side_bar_transition_time = 0;
        popout_menu_opacity_store = MMI_FALSE;

        gui_cancel_timer(gui_side_bar_popout_menu_transition_callback);
        popout_menu_is_transition = MMI_FALSE;
        }
        else
        {
            gui_side_bar_transition_time ++;
        gui_start_timer(GUI_SIDE_BAR_POPOUT_MENU_TIMER, gui_side_bar_popout_menu_transition_callback);
        }


    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_popout_menu_transition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_popout_menu_transition(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    gui_side_bar_transition_time = 0;
    
    gui_side_bar_clear_popout_menu(s);
    
    gui_cancel_timer(gui_side_bar_popout_menu_transition_callback);
    popout_menu_is_transition = MMI_TRUE;

    if (popout_menu_opacity_store)
    {
        gdi_layer_push_and_set_active(s->popout_menu_layer);
        gdi_layer_set_opacity(popout_menu_layer_opacity_enable, popout_menu_layer_opacity_value);
        gdi_layer_pop_and_restore_active();
    }
    
    gui_side_bar_popout_menu_transition_callback();
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_clear_indicators_by_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_clear_indicators_by_line(gui_side_bar_struct *s, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }
    

    gui_side_bar_get_bar_item_area(s, index, 
        &x1, &y1, &x2, &y2);

    x1 = s->bar_x + s->bar_width - 1 + GUI_SIDE_BAR_INDICATOR_BORDER_GAP;
    x2 = s->x + s->side_bar_max_width - 1;
    y1 += GUI_SIDE_BAR_INDICATOR_BORDER_GAP;
    y2 -= GUI_SIDE_BAR_INDICATOR_BORDER_GAP;

    
    gdi_layer_push_and_set_active(s->side_bar_layer);

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_clip();
        
    gdi_layer_pop_and_restore_active();
        
        
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_get_indicator_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_get_indicator_area(gui_side_bar_struct *s, S32 index, S32 col, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(s != NULL);

    *x1 = *y1 = *x2 = *y2 = 0;
    
    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }
    
    if (s->side_bar_menu[index].indicator_number <= 0 
        || s->side_bar_menu[index].indicator_number > GUI_SIDE_BAR_INDICATOR_MAX)
    {
        return;
    }

    if (col < 0 || col >= s->side_bar_menu[index].indicator_number)
    {
        return;
    }
    
    gui_side_bar_get_bar_item_area(s, index, 
        x1, y1, x2, y2);
    
    *x1 = s->bar_x + s->bar_width - 1 + GUI_SIDE_BAR_INDICATOR_BORDER_GAP + col * (GUI_SIDE_BAR_INDICATOR_GAP + GUI_SIDE_BAR_INDICATOR_SIZE);
    *x2 = *x1 + GUI_SIDE_BAR_INDICATOR_SIZE - 1;
    *y1 += GUI_SIDE_BAR_INDICATOR_BORDER_GAP;
    *y2 -= GUI_SIDE_BAR_INDICATOR_BORDER_GAP;

}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_indicators_by_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_redraw_indicators_by_line(gui_side_bar_struct *s, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 j, x1, y1, x2, y2, ix, iy, iwidth, iheight;
    S32 hint_x1, hint_y1, hint_x2, hint_y2, text_x1, text_y1, text_width, text_height;
    U8  hint_text[(GUI_SIDE_BAR_INDICATOR_HINT_MAX_LENGTH + 1) * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    if (index < 0 || index >= s->side_bar_menu_number)
    {
        return;
    }
    
    if (s->side_bar_menu[index].get_indicators_callback)
    {
        s->side_bar_menu[index].get_indicators_callback(
        &s->side_bar_menu[index].indicator_number,
        s->side_bar_menu[index].icon_of_indicators,
        s->side_bar_menu[index].data_of_indicators,
        s->side_bar_menu[index].pen_excute_hanlder,
        GUI_SIDE_BAR_INDICATOR_MAX);
    
        if (s->side_bar_menu[index].indicator_number <= 0 
            || s->side_bar_menu[index].indicator_number > GUI_SIDE_BAR_INDICATOR_MAX)
        {
            return;
        }
    
        gui_side_bar_get_bar_item_area(s, index, 
            &x1, &y1, &x2, &y2);
    
        x1 = s->bar_x + s->bar_width - 1 + GUI_SIDE_BAR_INDICATOR_BORDER_GAP;
        x2 = x1 + GUI_SIDE_BAR_INDICATOR_SIZE - 1;
        y1 += GUI_SIDE_BAR_INDICATOR_BORDER_GAP;
        y2 -= GUI_SIDE_BAR_INDICATOR_BORDER_GAP;

        
        gdi_layer_push_and_set_active(s->side_bar_layer);

        for (j = 0; j < s->side_bar_menu[index].indicator_number; j ++)
        {
            gdi_layer_push_clip();
            gdi_layer_set_clip(x1, y1, x2, y2);
            
            /* Draw icon */
            gdi_image_get_dimension(s->side_bar_menu[index].icon_of_indicators[j], &iwidth, &iheight);
            ix = x1 + ((x2 - x1 + 1 - iwidth) >> 1);
            iy = y1 + ((y2 - y1 + 1 - iheight) >> 1);
            gdi_image_draw(ix, iy, s->side_bar_menu[index].icon_of_indicators[j]);

            /* Draw hint */

            if (s->side_bar_menu[index].data_of_indicators[j] > 0)
            {
                if (s->side_bar_menu[index].data_of_indicators[j] >= 1000)
                {
                    s->side_bar_menu[index].data_of_indicators[j] = 999;
                }
                
                hint_x1 = x1;
                hint_y1 = y1;
                if (s->side_bar_menu[index].data_of_indicators[j] >= 100)
                {
                    hint_x2 = x1 + GUI_SIDE_BAR_INDICATOR_HINT_SIZE - 1;
                }
                else
                {
                    hint_x2 = x1 + GUI_SIDE_BAR_INDICATOR_HINT_SIZE * 2 / 3 + 1;
                }
                
                hint_y2 = y1 + GUI_SIDE_BAR_INDICATOR_HINT_SIZE * 2 / 3 - 1;
                
                gdi_draw_round_rect(hint_x1, hint_y1, hint_x2, hint_y2, 
                    gdi_act_color_from_rgb(
                        indicator_hint_bg_color.alpha, 
                        indicator_hint_bg_color.r, 
                        indicator_hint_bg_color.g, 
                        indicator_hint_bg_color.b), 
                    gdi_act_color_from_rgb(
                        indicator_hint_bg_boder_color.alpha, 
                        indicator_hint_bg_boder_color.r, 
                        indicator_hint_bg_boder_color.g, 
                        indicator_hint_bg_boder_color.b),  
                    GUI_SIDE_BAR_INDICATOR_HINT_BORDER);
                
                kal_wsprintf((unsigned short *)hint_text, 
                    "%d", 
                    s->side_bar_menu[index].data_of_indicators[j]);
                
                gui_set_font(indicator_hint_text_font);
                gui_set_text_color(indicator_hint_text_color);

                gui_measure_string((unsigned short *)hint_text, &text_width, & text_height);

                text_x1 = hint_x1 + ((hint_x2 - hint_x1 + 1 - text_width) >> 1);
                text_y1 = hint_y1 + ((hint_y2 - hint_y1 + 1 - text_height) >> 1);
                
                gui_move_text_cursor(text_x1, text_y1);
                
                gui_print_text((unsigned short *)hint_text);
            }
            
            gdi_layer_pop_clip();
            
            x1 = x2 + GUI_SIDE_BAR_INDICATOR_GAP;
            x2 = x1 + GUI_SIDE_BAR_INDICATOR_SIZE - 1;
        }

        
        gdi_layer_pop_and_restore_active();
        
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_redraw_indicators
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_redraw_indicators(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_DBG_ASSERT(s != NULL);

    for (i = 0; i < s->side_bar_menu_number; i ++)
    {
        gui_side_bar_redraw_indicators_by_line(s, i);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_update_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_update_popout_menu(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP || s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
    gui_side_bar_clear_popout_menu_no_redraw(s);
    gui_side_bar_close(s);
    gui_side_bar_open_popout_menu(s);
    gui_side_bar_redraw_popout_menu(s);
    
    gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
}
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_get_popout_menu_layout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_get_popout_menu_layout(gui_side_bar_struct *s, 
    UI_font_type *command_font, UI_font_type * data_font, 
    S32 *command_width, S32 *data_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *command_font = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_LIST);
    *data_font = GUI_SIDE_BAR_PUPOUT_MENU_DATA_FONT;
    gui_side_bar_get_popout_menu_list_area(s, &x1, &y1, &x2, &y2);
    *command_width = x2 - x1 + 1 - 9;
    if (s->side_bar_menu[s->side_bar_highlighted_menu].reach_bottom && 
        s->side_bar_menu[s->side_bar_highlighted_menu].reach_top)
    {
        *command_width -= current_MMI_theme->scrollbar_size;
    }
    *data_width = *command_width - GUI_SIDE_BAR_POPOUT_MENU_GAP;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_register_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_register_highlight_handler(gui_side_bar_struct *s, wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type handler)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->side_bar_highlight_handler = handler;
}


/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_register_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_side_bar_reset_to_inactive(gui_side_bar_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyType;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->state = MMI_GUI_SIDE_BAR_STATE_INACTIVE;
    s->side_bar_highlighted_menu = 0;
    
    for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
    {
        SetKeyHandler(s->AppLeftRightKeyHandler[0][keyType], KEY_LEFT_ARROW, keyType);
        SetKeyHandler(s->AppLeftRightKeyHandler[1][keyType], KEY_RIGHT_ARROW, keyType);
    }
    
    if (g_old_menu_act_layer != GDI_NULL_HANDLE)
    {
        wgui_fixed_list_set_active_layer(g_old_menu_act_layer);
    }

    /* Reset list */

    reset_fixed_list();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif

    gui_side_bar_clear_popout_menu_no_redraw(s);    
    gui_side_bar_redraw_bar(s);

    gui_side_bar_register_key_handler();

    gui_cancel_timer(gui_side_bar_popout_menu_transition_callback);
    popout_menu_is_transition = MMI_FALSE;
    s->side_bar_highlighted_menu = -1;

    history_enter = MMI_FALSE;

    gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
    
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_side_bar_translate_pen_position(gui_side_bar_struct *s, mmi_pen_point_struct point, S32 *param1, S32 *param2, mmi_gui_side_bar_pen_state_enum *side_bar_pen_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i, j;
    S32 x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(s != NULL);

    *side_bar_pen_state = MMI_GUI_SIDE_BAR_PEN_OUT_OF_SIDE_BAR;

    switch (s->state)
    {
        case MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP:
            
            /* check bar */
            if (PEN_CHECK_BOUND(point.x, point.y, s->bar_x, s->bar_y, s->bar_width, s->bar_height))
            {
                for (i = 0; i < s->side_bar_menu_number; i ++)
                {
                    gui_side_bar_get_bar_item_area(s, i, &x1, &y1, &x2, &y2);
                    if (PEN_CHECK_BOUND(point.x, point.y, x1, y1, x2 - x1 + 1, y2 - y1 + 1))
                    {
                        break;
                    }
                }

                if (i < s->side_bar_menu_number && i >= 0)
                {
                    *side_bar_pen_state = MMI_GUI_SIDE_BAR_PEN_ON_V_BAR;
                    *param1 = i;
                    return;
                }
            }

            break;
            
        case MMI_GUI_SIDE_BAR_STATE_ACTIVE:
        case MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP:
            
            /* check bar */
            if (PEN_CHECK_BOUND(point.x, point.y, s->bar_x, s->bar_y, s->bar_width, s->bar_height))
            {
                for (i = 0; i < s->side_bar_menu_number; i ++)
                {
                    gui_side_bar_get_bar_item_area(s, i, &x1, &y1, &x2, &y2);
                    if (PEN_CHECK_BOUND(point.x, point.y, x1, y1, x2 - x1 + 1, y2 - y1 + 1))
                    {
                        break;
                    }
                }

                if (i < s->side_bar_menu_number && i >= 0)
                {
                    *side_bar_pen_state = MMI_GUI_SIDE_BAR_PEN_ON_V_BAR;
                    *param1 = i;
                    return;
                }
            }

            /* check menu list */
            gui_side_bar_get_popout_menu_list_area(s, &x1, &y1, &x2, &y2);
            if (PEN_CHECK_BOUND(point.x, point.y, x1, y1, x2 - x1 + 1, y2 - y1 + 1))
            {
                *side_bar_pen_state = MMI_GUI_SIDE_BAR_PEN_ON_POPUP_MENU;
                return;
            }
            break;
            
        case MMI_GUI_SIDE_BAR_STATE_INACTIVE:
            /* check bar */
            if (PEN_CHECK_BOUND(point.x, point.y, s->bar_x, s->bar_y, s->bar_width, s->bar_height))
            {
                for (i = 0; i < s->side_bar_menu_number; i ++)
                {
                    gui_side_bar_get_bar_item_area(s, i, &x1, &y1, &x2, &y2);
                    if (PEN_CHECK_BOUND(point.x, point.y, x1, y1, x2 - x1 + 1, y2 - y1 + 1))
                    {
                        break;
                    }
                }

                if (i < s->side_bar_menu_number && i >= 0)
                {
                    *side_bar_pen_state = MMI_GUI_SIDE_BAR_PEN_ON_V_BAR;
                    *param1 = i;
                    return;
                }
            }
            
            /* check indicators */
            for (i = 0; i < s->side_bar_menu_number; i ++)
            {
                for (j = 0; j < s->side_bar_menu[i].indicator_number; j ++)
                {
                    gui_side_bar_get_indicator_area(s, i, j, &x1, &y1, &x2, &y2);
                    if (PEN_CHECK_BOUND(point.x, point.y, x1, y1, x2 - x1 + 1, y2 - y1 + 1))
                    {
                        *side_bar_pen_state = MMI_GUI_SIDE_BAR_PEN_ON_INDICATOR;
                        *param1 = i;
                        *param2 = j;
                        return;
                    }
                }
            }
            
            break;
            
        default:
            MMI_ASSERT(0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  gui_side_bar_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_side_bar_pen_handler(gui_side_bar_struct *s, mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 param1, param2;
    mmi_gui_side_bar_pen_state_enum side_bar_pen_state;
    U16 keyType;
    S32 i;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(s != NULL);

    gui_side_bar_translate_pen_position(s, point, &param1, &param2, &side_bar_pen_state);

    if (!PEN_CHECK_BOUND(point.x, point.y, s->x, s->y, s->side_bar_max_width, s->side_bar_max_height))
    {
        return ret;
    }
    
    MMI_fixed_list_menu.pen_redraw_menu_function = show_fixed_list;
    history_enter = MMI_FALSE;

    switch (event_type)
    {
        case MMI_PEN_EVENT_DOWN:
            if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_INDICATOR)
            {
                if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
                {
                    if (s->side_bar_highlight_handler != NULL)
                    {
                        s->side_bar_highlight_handler(s->side_bar_highlighted_menu);
                    }
                }
                
                s->state = MMI_GUI_SIDE_BAR_STATE_INACTIVE;
                for (i = 0; i < GUI_SIDE_BAR_INDICATOR_MAX; i ++)
                {
                    s->side_bar_menu[param1].pen_on_indicator[i] = MMI_FALSE;
                }
                s->side_bar_menu[param1].pen_on_indicator[param2] = MMI_TRUE;
                ret = MMI_TRUE;
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            else if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_V_BAR)
            {
                if (s->side_bar_highlighted_menu == param1 && s->state != MMI_GUI_SIDE_BAR_STATE_INACTIVE)
                {
                    if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
                    {
                        if (s->side_bar_highlight_handler != NULL)
                        {
                            s->side_bar_highlight_handler(s->side_bar_highlighted_menu);
                        }
                    }
                    
                    gui_side_bar_reset_to_inactive(s);
                    ret = MMI_TRUE;
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                    break;
                }
            }
        case MMI_PEN_EVENT_MOVE:
            if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_V_BAR)
            {
                if (s->state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
                {
                    s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;

                    s->side_bar_highlighted_menu = param1;
                    
                    for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
                    {
                        SetKeyHandler(NULL, KEY_LEFT_ARROW, keyType);
                        SetKeyHandler(NULL, KEY_RIGHT_ARROW, keyType);
                    }
                    
                    SetKeyHandler(gui_side_bar_HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(gui_side_bar_HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    
                    gui_side_bar_clear_popout_menu_no_redraw(s);
                    gui_side_bar_open_popout_menu(s);
                    gdi_layer_lock_frame_buffer();
                    fixed_list_goto_home();
                    gdi_layer_unlock_frame_buffer();
                    gui_side_bar_redraw_popout_menu_transition(s);

                    ret = MMI_TRUE;
                }
                else
                {
                    s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;

                    if (s->side_bar_highlighted_menu != param1)
                    {
                        s->side_bar_highlighted_menu  = param1;
                        
                        if (s->side_bar_highlighted_menu < 0)
                        {
                            s->side_bar_highlighted_menu = s->side_bar_menu_number - 1;
                        }
                        gui_side_bar_clear_popout_menu_no_redraw(s);
                        gui_side_bar_close(s);
                        gui_side_bar_open_popout_menu(s);
                        gdi_layer_lock_frame_buffer();
                        fixed_list_goto_home();
                        gdi_layer_unlock_frame_buffer();
                        gui_side_bar_redraw_popout_menu_transition(s);

                    }
                    
                    ret = MMI_TRUE;
                }
            }
            else if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_POPUP_MENU)
            {
                s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;
                ret = wgui_general_pen_list_menu_hdlr(point, event_type);
            }
            else if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_OUT_OF_SIDE_BAR)
            {
                if (s->state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
                {
                    if (s->side_bar_highlight_handler != NULL)
                    {
                        s->side_bar_highlight_handler(s->side_bar_highlighted_menu);
                    }
                }
                
                s->state = MMI_GUI_SIDE_BAR_STATE_INACTIVE;
                
                gui_side_bar_clear_bar_highlight(s);

                gui_side_bar_clear_popout_menu_no_redraw(s);
                
                gui_side_bar_close_popout_menu(s);
                
                gui_side_bar_redraw_indicators(s);
                
                for (keyType = 0; keyType < MAX_KEY_TYPE; keyType ++)
                {
                    SetKeyHandler(s->AppLeftRightKeyHandler[0][keyType], KEY_LEFT_ARROW, keyType);
                    SetKeyHandler(s->AppLeftRightKeyHandler[1][keyType], KEY_RIGHT_ARROW, keyType);
                }
                    
                gdi_layer_blt_previous(s->x, s->y, s->x + s->side_bar_max_width - 1, s->y + s->side_bar_max_height - 1);
                ret = MMI_FALSE;
            }
            
            break;
            
        case MMI_PEN_EVENT_UP:
            if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_INDICATOR)
            {
                s->state = MMI_GUI_SIDE_BAR_STATE_INACTIVE;

                if (s->side_bar_menu[param1].pen_on_indicator[param2]
                    && s->side_bar_menu[param1].pen_excute_hanlder[param2] != NULL)
                {
                s->side_bar_menu[param1].pen_excute_hanlder[param2]();
                }
                
                ret = MMI_TRUE;
            }
            else if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_POPUP_MENU)
            {
                s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;
                
                ret = wgui_general_pen_list_menu_hdlr(point, event_type);
            }
            break;
    
        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
        case MMI_PEN_EVENT_ABORT:
            if (side_bar_pen_state == MMI_GUI_SIDE_BAR_PEN_ON_POPUP_MENU)
            {
                s->state = MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP;
                
                ret = wgui_general_pen_list_menu_hdlr(point, event_type);
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_OP11_SIDEBAR__ */


