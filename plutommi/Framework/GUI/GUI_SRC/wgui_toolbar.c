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
 *  wgui_toolbar.c
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
#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "gui_themes.h"
#include "wgui_toolbar.h"
#include "wgui_fixed_menus.h"

/* Local variable */
static gui_toolbar_struct g_wgui_toolbar;

/* Global variable */
MMI_BOOL wgui_toolbar_history_enter = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_create
 * DESCRIPTION
 *  create toolbar
 * PARAMETERS
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
void wgui_toolbar_create(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_create(
            &g_wgui_toolbar,
            x, y,
            max_width, max_height,
            toolbar_layer, 
            popout_menu_layer, 
            wallpaper_layer,
            number_of_toolbar_menu, 
            icons_of_toolbar_menu_normal, 
            icons_of_toolbar_menu_highlight,
            get_menu_data_callback,
            menu_highlight_handler,
            popout_menu_state);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_close
 * DESCRIPTION
 *  close toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_close(&g_wgui_toolbar);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_show
 * DESCRIPTION
 *  show the toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_show(&g_wgui_toolbar);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_move
 * DESCRIPTION
 *  move the toolbar
 * PARAMETERS
 *  x   [IN]    x of toolbar
 *  y   [IN]    y of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_move(&g_wgui_toolbar, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_resize
 * DESCRIPTION
 *  resize toolbar
 * PARAMETERS
 *  max_width   [IN]    max width of toolbar
 *  max_height  [IN]    max height of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_resize(S32 max_width, S32 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_resize(&g_wgui_toolbar, max_width, max_height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_set_layers
 * DESCRIPTION
 *  set layers of toolbar
 * PARAMETERS
 *  toolbar_layer       [IN]    layer of toolbar
 *  popout_menu_layer   [IN]    layer of popout menu
 *  wallpaper_layer     [IN]    layer of wallpaper
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_set_layers(
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
    gui_toolbar_set_layers(&g_wgui_toolbar, toolbar_layer, popout_menu_layer, wallpaper_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_set_bar_state
 * DESCRIPTION
 *  set state of toolbar
 * PARAMETERS
 *  state   [IN]    state of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_set_bar_state(mmi_gui_toolbar_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_set_bar_state(&g_wgui_toolbar, state);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_set_popout_menu_state
 * DESCRIPTION
 *  set popout menu state
 * PARAMETERS
 *  index   [IN]    index of popoutmenu
 *  state   [IN]    state of toolbar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_set_popout_menu_state(S32 index, mmi_gui_toolbar_popout_menu_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_set_popout_menu_state(&g_wgui_toolbar, index, state);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_redraw
 * DESCRIPTION
 *  redraw the toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_redraw(&g_wgui_toolbar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_update_popout_menu
 * DESCRIPTION
 *  update of popout menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_update_popout_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_update_popout_menu(&g_wgui_toolbar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_change_bar_icon
 * DESCRIPTION
 *  change the bar icon
 * PARAMETERS
 *  index           [IN]    index of module
 *  icon_normal     [IN]    normal icon of bar item
 *  icon_highlight  [IN]    highlight icon of bar item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_change_bar_icon(S32 index, PU8 icon_normal, PU8 icon_highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_change_bar_icon(&g_wgui_toolbar, index, icon_normal, icon_highlight);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_get_history
 * DESCRIPTION
 *  get history of toolbar
 * PARAMETERS
 *  history [OUT]   history storage pointer    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_get_history(wgui_toolbar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history->toolbar_state = g_wgui_toolbar.state;
    
    for(i = 0; i < g_wgui_toolbar.toolbar_menu_number; i ++)
    {   
        if (i >= GUI_TOOLBAR_MAX_MENU)
        {
            break;
        }
        
        history->menu_state[i] = g_wgui_toolbar.toolbar_menu[i].state;

    }

    
    if (g_wgui_toolbar.state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        history->popout_menu_index = g_wgui_toolbar.toolbar_highlighted_menu_index;
        history->popout_menu_highlight = MMI_fixed_list_menu.highlighted_item;
        history->popout_menu_first_item = MMI_fixed_list_menu.first_displayed_item;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_set_history
 * DESCRIPTION
 *  set history of toolbar
 * PARAMETERS
 *  history [IN]   history storage pointer    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_set_history(wgui_toolbar_history_struct * history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(i = 0; i < g_wgui_toolbar.toolbar_menu_number; i ++)
    {   
        if (i >= GUI_TOOLBAR_MAX_MENU)
        {
            break;
        }

        g_wgui_toolbar.toolbar_menu[i].state = history->menu_state[i];

    }
    
    if (history->toolbar_state == MMI_GUI_TOOLBAR_STATE_ACTIVE)
    {
        g_wgui_toolbar.state = history->toolbar_state;
        g_wgui_toolbar.toolbar_highlighted_menu_index = history->popout_menu_index;
        g_wgui_toolbar.menu_highlight_from_history = history->popout_menu_highlight;
        g_wgui_toolbar.menu_first_item_from_history = history->popout_menu_first_item;
        wgui_toolbar_history_enter = MMI_TRUE;
    }
    else if (history->toolbar_state == MMI_GUI_TOOLBAR_STATE_INACTIVE)
    {
        g_wgui_toolbar.state = history->toolbar_state;
        wgui_toolbar_history_enter = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_is_active
 * DESCRIPTION
 *  get active of toolbar
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_toolbar_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_toolbar_is_active(&g_wgui_toolbar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_toolbar_change_popout_menu_highlight
 * DESCRIPTION
 *  set popout menu highlight
 * PARAMETERS
 *  index
 *  highlight_position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_toolbar_change_popout_menu_highlight(S32 index, S32 highlight_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_toolbar_change_popout_menu_highlight(&g_wgui_toolbar, index, highlight_position);
}

#endif /* __MMI_OP12_TOOLBAR__ */

