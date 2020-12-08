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
 *  wgui_side_bar.c
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
#include "wgui_side_bar.h"
#include "wgui_fixed_menus.h"

#include "gui_side_bar.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "wgui_categories_list.h"
#include "gui_fixed_menus.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"

gui_side_bar_struct g_wgui_side_bar;
extern void gui_side_bar_open_popout_menu(gui_side_bar_struct *s);
extern void gui_side_bar_close_popout_menu(gui_side_bar_struct *s);
extern MMI_BOOL history_enter;


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_create(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_side_bar_create(
                &g_wgui_side_bar,
                x, y,
                max_width, max_height,
                side_bar_layer, popout_menu_layer, wallpaper_layer,
                number_of_side_bar_menu, 
                icons_of_side_bar_menu_normal, icons_of_side_bar_menu_highlight,
                get_indicators_callback, 
                get_menu_data_callback,
                menu_highlight_handler);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_side_bar_show(&g_wgui_side_bar);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_side_bar_close(&g_wgui_side_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_update_indicators
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_update_indicators(S32 side_bar_menu_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_side_bar_update_indicators(&g_wgui_side_bar, side_bar_menu_index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_register_left_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_register_left_arrow_key_handler(FuncPtr funcPtr, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_side_bar_register_left_arrow_key_handler(&g_wgui_side_bar, funcPtr, keyType);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_register_right_arrow_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_register_right_arrow_key_handler(FuncPtr funcPtr, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_side_bar_register_right_arrow_key_handler(&g_wgui_side_bar, funcPtr, keyType);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_redraw_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_redraw_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_redraw_bar(&g_wgui_side_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_redraw_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_redraw_popout_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_side_bar.state != MMI_GUI_SIDE_BAR_STATE_ACTIVE ||
        g_wgui_side_bar.state != MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP)
    {
        return;
    }
    gui_side_bar_redraw_popout_menu(&g_wgui_side_bar);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_redraw_indicators
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_redraw_indicators(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_redraw_indicators(&g_wgui_side_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_move(&g_wgui_side_bar, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_resize(S32 max_width, S32 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_resize(&g_wgui_side_bar, max_width, max_height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_set_layers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_set_layers(GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_set_layers(&g_wgui_side_bar,
        side_bar_layer, popout_menu_layer, wallpaper_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_get_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_get_history(wgui_side_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history->no_popup_v_bar_index = g_wgui_side_bar.side_bar_highlighted_menu;
    history->state = g_wgui_side_bar.state;
    if (g_wgui_side_bar.state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP || g_wgui_side_bar.state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        history->popup_menu_highlight_item = MMI_fixed_list_menu.highlighted_item;
        history->popup_menu_first_display_item = MMI_fixed_list_menu.first_displayed_item;
        history->popup_menu_last_display_item = MMI_fixed_list_menu.last_displayed_item;
    }
    else
    {
        history->popup_menu_highlight_item = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_set_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_set_history(wgui_side_bar_history_struct * history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history->state < MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP || history->state >= MMI_GUI_SIDE_BAR_STATE_TOTAL)
    {
        return;
    }
    
    g_wgui_side_bar.state = history->state;
    g_wgui_side_bar.side_bar_highlighted_menu = 0;
    g_wgui_side_bar.current_popout_menu_highlight_index = -1;
    g_wgui_side_bar.current_popup_menu_first_display_item = -1;
    g_wgui_side_bar.current_popup_menu_last_display_item = -1;
    
    if (g_wgui_side_bar.state == MMI_GUI_SIDE_BAR_STATE_INACTIVE)
    {
        return;
    }
    else if (g_wgui_side_bar.state == MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP || g_wgui_side_bar.state == MMI_GUI_SIDE_BAR_STATE_ACTIVE)
    {
        g_wgui_side_bar.side_bar_highlighted_menu = history->no_popup_v_bar_index;
        g_wgui_side_bar.current_popout_menu_highlight_index = history->popup_menu_highlight_item;
        g_wgui_side_bar.current_popup_menu_first_display_item = history->popup_menu_first_display_item;
        g_wgui_side_bar.current_popup_menu_last_display_item = history->popup_menu_last_display_item;
    }
    else
    {
        g_wgui_side_bar.side_bar_highlighted_menu = history->no_popup_v_bar_index;
    }

    history_enter = MMI_TRUE;

    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_update_popout_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_update_popout_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_update_popout_menu(&g_wgui_side_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_get_popout_menu_layout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_get_popout_menu_layout(UI_font_type *command_font, UI_font_type *data_font, 
        S32 *command_width, S32 *data_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_get_popout_menu_layout(&g_wgui_side_bar, command_font, data_font, command_width, data_width);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_register_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_register_highlight_handler(wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_register_highlight_handler(&g_wgui_side_bar, handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_reset_to_inactive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_reset_to_inactive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_reset_to_inactive(&g_wgui_side_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_side_bar_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_side_bar_redraw(&g_wgui_side_bar);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_side_bar_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_side_bar_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
    return gui_side_bar_pen_handler(&g_wgui_side_bar,
        point,event_type);
}
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_OP11_SIDEBAR__ */

