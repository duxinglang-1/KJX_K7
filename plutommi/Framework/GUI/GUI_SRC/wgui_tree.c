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
 *  wgui_tree.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  A simple tree menu implemented in asyncdynamic icontext list
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "wgui.h"
#include "wgui_categories_util.h"
#include "wgui_include.h"

#include "wgui_tree.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menus.h"

#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "gui_fixed_menus.h"
#include "gui.h"
#include "gui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_typedef.h"
#include "gui_theme_struct.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "DebugInitDef_Int.h"
#include "gui_data_types.h"
#include "wgui_inputs.h"
#include "string.h"
#include "wgui_fixed_menus.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static wgui_tree_struct g_wgui_tree_context; 
static wgui_tree_struct * const wgui_tree_p = &g_wgui_tree_context;

#ifdef __MMI_TOUCH_SCREEN__
static BOOL wgui_tree_menuitem_translate_pen_event(
        void *item,
        void *common_item_data,
        S32 item_x,
        S32 item_y,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_list_pen_enum *menuitem_event,
        gui_pen_event_param_struct *menuitem_param);
#endif /* __MMI_TOUCH_SCREEN__ */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern fixed_icontext_list_menuitem_type *GUI_current_fixed_icontext_list_menuitem_data;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_tree_load_item_complete_callback
 * DESCRIPTION
 *  Asyncdyanmic load complete callback function for the tree
 * PARAMETERS
 *  start_index       [IN]  start index
 *  n_items           [IN]  number of items
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_load_item_complete_callback(S32 start_index, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    fixed_icontext_list_menuitem_type *mi;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < n_items; i++)
    {
        mi = get_asyncdynamic_item_from_buffer(start_index + i);
        mi->ext_flags = wgui_tree_p->level_buffer[i];
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_get_item
 * DESCRIPTION
 *  Tree get item callback function.
 * PARAMETERS
 *  start_index       [IN]  start index
 *  menu_data         [IN]  menu item data
 *  data_size         [IN]  number of items in request
 * RETURNS
 *  Number of accquired items.
 *****************************************************************************/
static S32 wgui_tree_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     ret;
    S32     level;
    S32     item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < data_size; i++)
    {
        MMI_fixed_icontext_list_menuitem.n_text_columns = FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS;
        MMI_fixed_icontext_list_menuitem.n_icon_columns = FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS;

        item_index = wgui_tree_translate_viewable_index_to_item_index(start_index + i);
        
        /* get one item */
        ret = wgui_tree_p->get_item_funcptr(item_index, menu_data + i, 1);
        level = WGUI_TREE_GET_LEVEL(item_index);
        
        MMI_ASSERT((ret == MMI_TRUE) && (level >= 0) && (level < wgui_tree_p->level_num));
        
        wgui_tree_p->level_buffer[i] = (U8)level;
    }

    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_get_hint
 * DESCRIPTION
 *  Tree get item hint callback function.
 * PARAMETERS
 *  item_index       [IN]   item index
 *  hint_array       [IN]   hint string array
 * RETURNS
 *  1 if successful; otherwise, 0
 *****************************************************************************/
static S32 wgui_tree_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_tree_p->get_hint_funcptr)
    {
        item_index = wgui_tree_translate_viewable_index_to_item_index(item_index);
    
        return wgui_tree_p->get_hint_funcptr(item_index, hint_array);
    }

    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_apply_item_coordinate
 * DESCRIPTION
 *  Applys the coordiante to the multi icontext menu item.
 * PARAMETERS
 *  mi       [IN]   private menu item
 *  m        [IN]   common menu item
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_apply_item_coordinate(fixed_icontext_list_menuitem_type* mi, fixed_icontext_list_menuitem* m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 coordinate_start_index;
    S32 level;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    level = mi->ext_flags;

    m->n_text_columns = wgui_tree_p->level_info[level].text_num;    
    m->n_icon_columns = wgui_tree_p->level_info[level].icon_num;
    
    /* copy coordinates and data */
    coordinate_start_index = wgui_tree_p->level_info[level].coordinate_start_index;
    for (i = 0; i < m->n_text_columns; i++)
    {
        m->text_coordinates[i] = wgui_tree_p->item_coordinates[coordinate_start_index + i].coordinate;
        if (wgui_tree_p->item_coordinates[coordinate_start_index + i].font)
        {
            m->text_fonts[i] = wgui_tree_p->item_coordinates[coordinate_start_index + i].font;
        }
    }

    /* adjust the scroll width */
    m->scroll_width = m->text_coordinates[0].width;

    coordinate_start_index = wgui_tree_p->level_info[level].coordinate_start_index + m->n_text_columns;    
    for (i = 0; i < m->n_icon_columns; i++)
    {
        m->icon_coordinates[i] = wgui_tree_p->item_coordinates[coordinate_start_index + i].coordinate;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_show_item
 * DESCRIPTION
 *  Menu item show function.
 * PARAMETERS
 *  item                   [IN]     private menu item
 *  common_item_data       [IN]     common menu item
 *  x                      [IN]     x
 *  y                      [IN]     y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_show_item(void *item, void *common_item_data, S32 x, S32 y)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* apply the individual tree level coordinate */
    wgui_tree_apply_item_coordinate((fixed_icontext_list_menuitem_type*)item, (fixed_icontext_list_menuitem*)common_item_data);
    
    gui_show_fixed_icontext_list_menuitem(item, common_item_data, x, y);
    
    /* restore the highlighted item coordinate for scrolling */
    wgui_tree_apply_item_coordinate(GUI_current_fixed_icontext_list_menuitem_data, (fixed_icontext_list_menuitem*)common_item_data);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_highlight_item
 * DESCRIPTION
 *  Menu item highlight function.
 * PARAMETERS
 *  item                   [IN]     private menu item
 *  common_item_data       [IN]     common menu item     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_highlight_item(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_tree_apply_item_coordinate((fixed_icontext_list_menuitem_type*)item, (fixed_icontext_list_menuitem*)common_item_data);
    gui_highlight_fixed_icontext_list_menuitem(item, common_item_data);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_remove_highlight_item
 * DESCRIPTION
 *  Menu item remove highlight function.
 * PARAMETERS
 *  item                   [IN]     private menu item
 *  common_item_data       [IN]     common menu item  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_remove_highlight_item(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_tree_apply_item_coordinate((fixed_icontext_list_menuitem_type*)item, (fixed_icontext_list_menuitem*)common_item_data);    
    gui_remove_highlight_fixed_icontext_list_menuitem(item, common_item_data);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_set_coordinate
 * DESCRIPTION
 *  Sets the coordinate internally.
 * PARAMETERS
 *  coordinate_index  [IN]  coordinate index
 *  x                 [IN]  x
 *  y                 [IN]  y
 *  width             [IN]  width
 *  height            [IN]  height
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_set_coordinate(S32 coordinate_index, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_object_coordinates   *coordinate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(coordinate_index >= 0 && coordinate_index < WGUI_TREE_MAX_TOTAL_COORDINATES);
    
    coordinate = &wgui_tree_p->item_coordinates[coordinate_index].coordinate;
    coordinate->x = x;
    coordinate->y = y;
    coordinate->width = width;
    coordinate->height = height;
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  wgui_tree_menuitem_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the tree item.
 * PARAMETERS
 *  item                    [IN]        private icontext menu item
 *  common_item_data        [IN]        common icontext menu item
 *  item_x                  [IN]        item x1
 *  item_y                  [IN]        item y1
 *  pen_event               [IN]        pen event type
 *  x                       [IN]        pen x
 *  y                       [IN]        pen y
 *  menuitem_event          [OUT]       pen event result
 *  menuitem_param          [IN]        pen event parameter
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE. 
 *****************************************************************************/
static BOOL wgui_tree_menuitem_translate_pen_event(
        void *item,
        void *common_item_data,
        S32 item_x,
        S32 item_y,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_list_pen_enum *menuitem_event,
        gui_pen_event_param_struct *menuitem_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_index;
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*)common_item_data;
    S32 hit_rect_x, hit_rect_y, hit_rect_w, hit_rect_h;
    MMI_BOOL is_pen_in_hit_rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (wgui_tree_p->folder_clicked_funcptr == NULL)
    {
        return MMI_FALSE;
    }

    *menuitem_event = GUI_LIST_PEN_NONE;

    item_index = menuitem_param->_u.i;

    if (mmi_fe_get_r2l_state())
    {
        hit_rect_x = item_x + m->width - m->icon_coordinates[0].x - m->icon_coordinates[0].width;
    }
    else
    {
        hit_rect_x = item_x + m->icon_coordinates[0].x;
    }
   
    hit_rect_y = item_y + m->icon_coordinates[0].y;
    hit_rect_w = m->icon_coordinates[0].width;
    hit_rect_h = m->icon_coordinates[0].height;
      
    is_pen_in_hit_rect = (MMI_BOOL)PEN_CHECK_BOUND(x, y, hit_rect_x, hit_rect_y, hit_rect_w, hit_rect_h);

    if (is_pen_in_hit_rect)
    {            
        if (pen_event == MMI_PEN_EVENT_DOWN)
        {
            return MMI_TRUE;
        }   
        else if (pen_event == MMI_PEN_EVENT_UP)
        {
            if (wgui_tree_p->folder_clicked_funcptr(wgui_tree_translate_viewable_index_to_item_index(item_index)) == MMI_TRUE)
            {               
                *menuitem_event = GUI_LIST_PEN_NEED_REDRAW;
            }
            else
            {  /* execute lsk handler if clicking on the first icon but not a folder. */
                *menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
            }
            
            return MMI_TRUE;
        }             
    }

    GUI_PEN_EVENT_PARAM_SET_VOID(menuitem_param); 
    
    return MMI_FALSE;
}


#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_highlight_handler
 * DESCRIPTION
 *  Tree highlight handler wrapper. (translate list viewable index to item index)
 * PARAMETERS
 *  item_index       [IN]   highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_tree_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_tree_p->highlight_handler)
    {
        wgui_tree_p->highlight_handler(wgui_tree_translate_viewable_index_to_item_index(item_index));
    }
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_tree_close
 * DESCRIPTION
 *  Closes the tree.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();

    memset(wgui_tree_p, 0, sizeof(wgui_tree_struct));    

    wgui_asyncdynamic_menuitem_register_load_complete_callback(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_create
 * DESCRIPTION
 *  Creates the tree.
 * PARAMETERS
 *  item_num                [IN]    number of items
 *  level_num               [IN]    number of levels
 *  menu_item_height        [IN]    menu item height
 *  get_item_callback       [IN]    get item callback function
 *  get_hint_callback       [IN]    get hint callback function
 *  get_level_callback      [IN]    get level callback function
 *  get_state_callback      [IN]    get state callback function
 *  set_state_callback      [IN]    set state callback function
 *  folder_clicked_callback [IN]    folder icon clicked callback function
 *  history_id              [IN]    category ID
 *  history_buffer          [IN]    GUI history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_create(
        S32 item_num,
        S32 level_num,
        S32 menu_item_height,
        wgui_tree_get_item_callback_funcptr_type get_item_callback,
        wgui_tree_get_hint_callback_funcptr_type get_hint_callback,
        wgui_tree_get_item_level_callback_funcptr_type get_level_callback,    
        wgui_tree_get_item_state_callback_funcptr_type get_state_callback,
        wgui_tree_set_item_state_callback_funcptr_type set_state_callback,
        wgui_tree_folder_clicked_callback_funcptr_type folder_clicked_callback,
        void (*highlight_handler)(S32 item_index),
        S32 highlighted_item,
        U16 history_id,
        PU8 history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  h_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_item_callback && get_state_callback && set_state_callback && get_level_callback && (item_num >= 0) && (level_num <= WGUI_TREE_MAX_LEVEL_NUM));
    
    wgui_title_set_menu_shortcut_number(-1);

    create_fixed_icontext_list_menuitems(FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS, FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS);
    
    associate_fixed_icontext_list_list();    

    /* register pen event handler to support click on icon */
#ifdef __MMI_TOUCH_SCREEN__
    gui_set_fixed_list_menu_item_pen_function(
        &MMI_fixed_list_menu,
        wgui_tree_menuitem_translate_pen_event,
        MMI_FALSE,
        MMI_FALSE);    
#endif /* __MMI_TOUCH_SCREEN__ */         

    resize_fixed_icontext_list_menuitems(0, menu_item_height);

    gui_set_fixed_list_menu_item_functions(
        &MMI_fixed_list_menu,
        wgui_tree_show_item,
        gui_measure_fixed_icontext_list_menuitem,
        wgui_tree_highlight_item,
        wgui_tree_remove_highlight_item,
        UI_fixed_menuitem_dummy_hide_function,
        resize_fixed_icontext_list_menuitems,
        gui_get_fixed_icontext_list_menuitem_flag,
        UI_fixed_menuitem_dummy_get_length_function);
    
    register_asyncdynamic_list_keys();
    register_fixed_list_highlight_handler(wgui_tree_highlight_handler);    
    register_asyncdynamic_list_shortcut_handler();

    MMI_current_menu_type = LIST_MENU;
    
    wgui_tree_p->level_num = level_num;
    wgui_tree_p->get_item_funcptr = get_item_callback;
    wgui_tree_p->get_hint_funcptr = get_hint_callback;
    wgui_tree_p->get_level_funcptr = get_level_callback;    
    wgui_tree_p->get_state_funcptr = get_state_callback;
    wgui_tree_p->set_state_funcptr = set_state_callback;

    wgui_tree_p->folder_clicked_funcptr = folder_clicked_callback;

    wgui_tree_p->highlight_handler = highlight_handler;
    
    wgui_tree_p->n_items = item_num;
    wgui_tree_p->viewable_n_items = item_num;
    MMI_fixed_list_menu.n_items = item_num;
    
    init_asyncdynamic_item_buffer(
        item_num,
        wgui_tree_get_item,
        wgui_tree_get_hint);       

    /* use the last item to store the highlight item */
    wgui_asyncdynamic_menuitem_register_load_complete_callback(wgui_tree_load_item_complete_callback);
    
    /* calculate MMI_fixed_list_menu.n_items (viewable items) */
    wgui_tree_update(WGUI_TREE_ITEM_NUMBER_UNCHANGED, WGUI_TREE_HIGHLIGHT_DONTCARE); 
    
    h_flag = set_list_menu_category_history(history_id, history_buffer);
    if (h_flag)
    {   /* valid history */
        highlighted_item = MMI_fixed_list_menu.highlighted_item;        
        wgui_tree_update(WGUI_TREE_ITEM_NUMBER_UNCHANGED, highlighted_item);        
    }           
    else
    {   /* First entry. Default tree item states are handled by upper layers. */
        // wgui_tree_collapse_all();
        wgui_tree_update(WGUI_TREE_ITEM_NUMBER_UNCHANGED, highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_set_level_coordinate_num
 * DESCRIPTION
 *  Sets the coordinate numbers of a tree level.
 * PARAMETERS
 *  level_index       [IN]  level index
 *  text_num          [IN]  number of text coordinates
 *  icon_num          [IN]  number of icon coordinates
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_set_level_coordinate_num(S32 level_index, S32 text_num, S32 icon_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(level_index < wgui_tree_p->level_num);

    wgui_tree_p->level_info[level_index].text_num = text_num;
    wgui_tree_p->level_info[level_index].icon_num = icon_num;
    wgui_tree_p->level_info[level_index].coordinate_start_index = wgui_tree_p->allocated_coordinate_num;    
    wgui_tree_p->allocated_coordinate_num += text_num + icon_num;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_set_text_coordinate
 * DESCRIPTION
 *  Sets the text coordinate of a tree level.
 * PARAMETERS
 *  level_index       [IN]  level
 *  i                 [IN]  text coordinate index
 *  x                 [IN]  x
 *  y                 [IN]  y
 *  width             [IN]  width
 *  height            [IN]  height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_set_text_coordinate(S32 level_index, S32 i, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((level_index < wgui_tree_p->level_num) && (i < wgui_tree_p->level_info[level_index].text_num));  

    wgui_tree_set_coordinate(
        wgui_tree_p->level_info[level_index].coordinate_start_index + i,
        x,
        y,
        width,
        height);   
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_set_text_color
 * DESCRIPTION
 *  Sets the text color in a level.
 * PARAMETERS
 *  level_index       [IN]  level
 *  i                 [IN]  text coordinate index
 *  text_color        [IN]  text color
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_set_text_color(S32 level_index, S32 i, color text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((level_index < wgui_tree_p->level_num) && (i < wgui_tree_p->level_info[level_index].text_num));  

    index = wgui_tree_p->level_info[level_index].coordinate_start_index + i;
    wgui_tree_p->item_coordinates[index].color = text_color; 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_set_text_font
 * DESCRIPTION
 *  Sets the text font in a level.
 * PARAMETERS
 *  level_index       [IN]  level
 *  i                 [IN]  text coordinate index
 *  font              [IN]  text font
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_set_text_font(S32 level_index, S32 i, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((level_index < wgui_tree_p->level_num) && (i < wgui_tree_p->level_info[level_index].text_num));  

    index = wgui_tree_p->level_info[level_index].coordinate_start_index + i;
    wgui_tree_p->item_coordinates[index].font = font; 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_set_icon_coordinate
 * DESCRIPTION
 *  Sets the icon coordinate of a tree level.
 * PARAMETERS
 *  level_index       [IN]  level
 *  i                 [IN]  icon coordinate index
 *  x                 [IN]  x
 *  y                 [IN]  y
 *  width             [IN]  width
 *  height            [IN]  height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_set_icon_coordinate(S32 level_index, S32 i, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((level_index < wgui_tree_p->level_num) && (i < wgui_tree_p->level_info[level_index].icon_num));  

    wgui_tree_set_coordinate(
        wgui_tree_p->level_info[level_index].coordinate_start_index + wgui_tree_p->level_info[level_index].text_num + i,
        x,
        y,
        width,
        height);     
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_show
 * DESCRIPTION
 *  Shows the tree.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_asyncdynamic_list();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_update
 * DESCRIPTION
 *  Updates the tree item number and highlighted item.
 * PARAMETERS
 *  item_num              [IN]  new number of menu items. -1: don't change
 *  highlight_index       [IN]  New highlight index. -1: decided by the tree menu. Others: highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_update(S32 item_num, S32 highlight_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlight_item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_num < 0)
    {
        item_num = wgui_tree_p->n_items;        
    }

    wgui_tree_p->n_items = item_num;

    /* calculate viewable number of items */
    wgui_tree_p->viewable_n_items = wgui_tree_get_viewable_item_num();
    MMI_fixed_list_menu.n_items = wgui_tree_p->viewable_n_items;
    item_num = wgui_tree_p->viewable_n_items;

    init_asyncdynamic_item_buffer(
        item_num,
        asyncdynamic_item_buffer.load_func,
        asyncdynamic_item_buffer.hint_func);

    /* update title shortcut number */
    set_menu_item_count(item_num);

    if (item_num == 0)
    {
        MMI_fixed_list_menu.highlighted_item = 0;
        
        return;    
    }

    old_highlight_item_index = MMI_fixed_list_menu.highlighted_item;

    /* 
     * Decide the highlight index automatically if highlight_index is -1.
     * Keep the highlight index unchanged as possible.
     */
    if (highlight_index < 0)
    {
        if (old_highlight_item_index >= item_num)
        {   /* old highlight index exceeds the new item number, go to the last item. */
            highlight_index = item_num - 1;
        }
        else
        {   /* remain old highlight index */
            highlight_index = old_highlight_item_index;
        }
    }    

    /* force goto item by -1 */
    // MMI_fixed_list_menu.highlighted_item = -1;

    set_asyncdynamic_pop_up_descriptions(highlight_index);
    asyncdynamic_list_goto_item_no_redraw(highlight_index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_is_parent_node
 * DESCRIPTION
 *  Checks if a tree item is a parent.
 * PARAMETERS
 *  item_index       [IN]   item index
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE
 *****************************************************************************/
MMI_BOOL wgui_tree_is_parent_node(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_TREE_GET_STATE(item_index) & WGUI_TREE_ITEM_FLAG_PARENT) 
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_is_hided_node
 * DESCRIPTION
 *  Checks if a tree item is hidden.
 * PARAMETERS
 *  item_index       [IN]   item index
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE
 *****************************************************************************/
MMI_BOOL wgui_tree_is_hidden_node(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_TREE_GET_STATE(item_index) & WGUI_TREE_ITEM_FLAG_HIDDEN) 
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_get_child_num
 * DESCRIPTION
 *  Gets the number of childs of a parent.
 * PARAMETERS
 *  item_index       [IN]   parent index
 * RETURNS
 *  Number of childs.
 *****************************************************************************/
S32 wgui_tree_get_child_num(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 child_num;
    S32 parent_level;
    
    child_num = 0;
    parent_level = WGUI_TREE_GET_LEVEL(item_index);

    while (++item_index < wgui_tree_p->n_items)
    {    
        // TODO: FIX ME
        /*
         * wgui_tree_is_parent_node() is a workaround to make orange IMPS work, but       
         * a folder cannot contain another folder.
         */
        if ((WGUI_TREE_GET_LEVEL(item_index) <= parent_level) || 
            wgui_tree_is_parent_node(item_index)) 
        {
            break;
        }
        else
        {
            child_num++;            
        }  
    }    

    return child_num;    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_get_viewable_child_num
 * DESCRIPTION
 *  Gets the number of viewable childs of a parent
 * PARAMETERS
 *  item_index       [IN]   parent index
 * RETURNS
 *  Number of viewable childs.
 *****************************************************************************/
S32 wgui_tree_get_viewable_child_num(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 child_num;
    S32 parent_level;
    
    child_num = 0;
    parent_level = WGUI_TREE_GET_LEVEL(item_index);

    while (++item_index < wgui_tree_p->n_items)
    {    
        if (WGUI_TREE_GET_LEVEL(item_index) <= parent_level)
        {
            break;
        }
        else
        {
            if (wgui_tree_is_parent_node(item_index))
            {
                child_num++;

                /* folded parent node */
                if (wgui_tree_is_hidden_node(item_index))
                {
                    item_index += wgui_tree_get_child_num(item_index);
                }
            }
            else
            {
                if (!wgui_tree_is_hidden_node(item_index))
                {
                    child_num++;
                }
            }            
        }       
    }    

    return child_num;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_get_viewable_item_num
 * DESCRIPTION
 *  Gets the number of viewable items.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of viewable items.
 *****************************************************************************/
S32 wgui_tree_get_viewable_item_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     viewable_num;

    viewable_num = 0;

    for (i = 0; i < wgui_tree_p->n_items; i++)
    {
        if (wgui_tree_is_parent_node(i))
        {
            viewable_num++;
            
            if (wgui_tree_is_hidden_node(i))
            {                    
                i += wgui_tree_get_child_num(i);
                continue;
            }
        }
        else
        {
            if (!wgui_tree_is_hidden_node(i))
            {
                viewable_num++;
            }
        }
    }

    return viewable_num;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_translate_viewable_index_to_item_index
 * DESCRIPTION
 *  Translates the list viewable index to the item index.
 * PARAMETERS
 *  list_view_index       [IN]  list view index
 * RETURNS
 *  Tree item index.
 *****************************************************************************/
S32 wgui_tree_translate_viewable_index_to_item_index(S32 list_view_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 k;
    S32 tree_view_index;

    tree_view_index = -1;

    for (k = 0; k < wgui_tree_p->n_items; k++)
    {
        /* parent node */
        if (wgui_tree_is_parent_node(k))
        {        
            if (wgui_tree_is_hidden_node(k))
            {   /* collapsed node */
                if (++tree_view_index == list_view_index)
                {
                    break;
                }

                /* skip collapsed child nodes */
                k += wgui_tree_get_child_num(k);
                continue;
            }
        }          
            
        if (!wgui_tree_is_hidden_node(k))
        {
            tree_view_index++;
        }

        if (tree_view_index == list_view_index)
        {
            break;
        }              
    }
 
    MMI_ASSERT(k < wgui_tree_p->n_items);

    return k;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_is_folder_expanded
 * DESCRIPTION
 *  Checks if a folder is expanded.
 * PARAMETERS
 *  item_index       [IN]   item idnex
 * RETURNS
 *  MMI_TRUE if yes; otherwise, MMI_FALSE
 *****************************************************************************/
MMI_BOOL wgui_tree_is_folder_expanded(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_tree_is_parent_node(item_index))
    {
        if (!wgui_tree_is_hidden_node(item_index))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_expand
 * DESCRIPTION
 *  Expands a folder.
 * PARAMETERS
 *  item_index       [IN]   item index
 * RETURNS
 *  Number of viewable childs in the folder.
 *****************************************************************************/
S32 wgui_tree_expand(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 child_num;
    S32 menu_item_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_item_index = MMI_fixed_list_menu.highlighted_item;

    child_num = 0;

    if (wgui_tree_is_parent_node(item_index) == MMI_FALSE)
    {
        return 0;
    } 
    
    child_num = wgui_tree_get_viewable_child_num(item_index);

    WGUI_TREE_SET_STATE(item_index, WGUI_TREE_ITEM_STATE_PARENT_EXPANDED);    
 
    /* change the first displayed item to see more childs as possible */
    if (menu_item_index + child_num > MMI_fixed_list_menu.last_displayed_item)
    {               
        MMI_fixed_list_menu.first_displayed_item += child_num;

        if (MMI_fixed_list_menu.first_displayed_item > menu_item_index)
        {
            MMI_fixed_list_menu.first_displayed_item = menu_item_index;
        }
    }

    wgui_tree_update(WGUI_TREE_ITEM_NUMBER_UNCHANGED, WGUI_TREE_HIGHLIGHT_DONTCARE);

    return child_num;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_collapse
 * DESCRIPTION
 *  Collapses a parent item.
 * PARAMETERS
 *  item_index       [IN]   tree item index
 * RETURNS
 *  Number of childs of the node.
 *****************************************************************************/
S32 wgui_tree_collapse(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 child_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    child_num = 0;

    if (wgui_tree_is_parent_node(item_index) == MMI_FALSE)
    {
        return 0;
    }

    child_num = wgui_tree_get_viewable_child_num(item_index);

    WGUI_TREE_SET_STATE(item_index, WGUI_TREE_ITEM_STATE_PARENT_COLLAPSED);

    /* align to bottom */
    if (MMI_fixed_list_menu.last_displayed_item - child_num < MMI_fixed_list_menu.n_items)
    {
        MMI_fixed_list_menu.last_displayed_item = MMI_fixed_list_menu.n_items - child_num - 1;
    }

    wgui_tree_update(WGUI_TREE_ITEM_NUMBER_UNCHANGED, WGUI_TREE_HIGHLIGHT_DONTCARE);

    return child_num;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_collapse_all
 * DESCRIPTION
 *  Collapses all parent nodes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_collapse_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < wgui_tree_p->n_items; i++)
    {
        if (wgui_tree_is_parent_node(i))
        {
            WGUI_TREE_SET_STATE(i, WGUI_TREE_ITEM_STATE_PARENT_COLLAPSED);
        }
    }

    wgui_tree_update(WGUI_TREE_ITEM_NUMBER_UNCHANGED, WGUI_TREE_HIGHLIGHT_DONTCARE); 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_expand_all
 * DESCRIPTION
 *  Expands all parent nodes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_expand_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < wgui_tree_p->n_items; i++)
    {
        if (wgui_tree_is_parent_node(i))
        {
            WGUI_TREE_SET_STATE(i, WGUI_TREE_ITEM_STATE_PARENT_EXPANDED);
        }
    }

    wgui_tree_update(wgui_tree_p->n_items, WGUI_TREE_HIGHLIGHT_DONTCARE); 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_get_item_num
 * DESCRIPTION
 *  Gets the number of tree items.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of tree items.
 *****************************************************************************/
S32 wgui_tree_get_item_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_tree_p->n_items;    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_tree_toggle
 * DESCRIPTION
 *  Toggles the folder.
 * PARAMETERS
 *  item_index       [IN]   item index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_tree_toggle(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_tree_is_parent_node(item_index))
    {
        if (wgui_tree_is_folder_expanded(item_index))
        {
            wgui_tree_collapse(item_index);
        }
        else
        {
            wgui_tree_expand(item_index);
        }               
    }
}



