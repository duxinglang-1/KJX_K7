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
 *   wgui_categories_list_op.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Operator related categories for list menu
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#include "FileMgrSrvGProt.h"
#include "wgui_fixed_menuitems.h"
#if defined(__MMI_OP01_DCD__)
#include "ui_dcd_porting.h"
#endif /* defined(__MMI_OP01_DCD__) */

#ifdef __MMI_OP01_DCD_V30__
#include "mmi_rp_app_dcd_def.h"
#include "DCDV30Gprot.h"
#endif

#include "gui_data_types.h"
#include "MMIDataType.h"
#include "wgui_draw_manager.h"
#include "gdi_include.h"
#include "wgui_categories_enum.h"
#include "wgui_include.h"
#include "gui_typedef.h"
#include "gui_fixed_menuitems.h"
#include "gui_themes.h"
#include "mmi_frm_events_gprot.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_theme_struct.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menus.h"
#include "wgui.h"
#include "gui_switch.h"
#include "gui.h"
#include "string.h"
#include "gui_config.h"
#include "gui_windows.h"
#include "wgui_inputs.h"
#include "gui_inputs.h"
#include "kal_general_types.h"
#include "wgui_categories_list_op.h"
#include "gui_fixed_menus.h"
#include "CustThemesRes.h"
#include "CustDataRes.h"

extern void ExitListCategoryScreen(void);

#if defined(__MMI_OP01_DCD__)
static wgui_cat_182_getimagepath g_cat182_get_imagepath_func = NULL;
static S8 g_cat182_imagepath[(SRV_FMGR_PATH_MAX_LEN + 1)];
static GDI_HANDLE cat182_animation_handle;

extern UI_dcd_theme *current_dcd_theme;
extern S32 gdi_anim_get_current_frame_number(gdi_handle serial_handle);

/*****************************************************************************
 * FUNCTION
 *  ExitCategory182Screen
 * DESCRIPTION
 *  Exit the category182 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory182Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_pop_up_descriptions();

	gdi_image_stop_animation(cat182_animation_handle);
	cat182_animation_handle = GDI_ERROR_HANDLE;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */  
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    g_cat182_get_imagepath_func = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_182_post_display_menuitem
 * DESCRIPTION
 *  post menuitem to display
 * PARAMETERS
 *  item                    [IN]        item type
 *  common_item_data        [IN]        item list
 *  x                       [IN]        list x
 *  y                       [IN]        list y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_182_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    S32 x2, y2, item_index;
	S32 img_width, img_height;
	S32 number = 0;
    S32 img_width_align, img_height_align,x_position_align,y_position_align;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = x + m->width - 1;
    y2 = y + m->height - 1;

    //gui_push_clip();
    //gui_set_clip(x, y, x2, y2);
	memset(g_cat182_imagepath, 0, SRV_FMGR_PATH_MAX_LEN + 1);
    item_index = MMI_fixed_list_menu.current_displayed_item;
    if (item_index == -1)
    {
        item_index = wgui_title_get_menu_shortcut_number() - 1;
    }
    g_cat182_get_imagepath_func(item_index, g_cat182_imagepath);
	gdi_image_get_dimension_file(g_cat182_imagepath, &img_width, &img_height);
    /*Display the image justified center*/
    if (img_width >= CAT182_ICON_WIDTH)
	{
		img_width_align = CAT182_ICON_WIDTH;
        x_position_align = CAT182_ICON_X + x; 
	}
    else
    {
    	img_width_align = img_width;
        x_position_align = CAT182_ICON_X + x + ((CAT182_ICON_WIDTH -img_width) >>1); 
    }
    if (img_height >= CAT182_ICON_HEIGHT)
	{
		img_height_align = CAT182_ICON_HEIGHT;
        y_position_align = CAT182_ICON_Y + y;
	}
    else
    {
    	img_height_align = img_height;
        y_position_align = CAT182_ICON_Y + y + ((CAT182_ICON_HEIGHT -img_height) >>1);
    }	
    if(item_index == MMI_fixed_list_menu.highlighted_item)
	{
        if (gui_screen_smooth_scrolling_by_pen())
        {
            gdi_anim_stop(cat182_animation_handle);
            cat182_animation_handle = GDI_ERROR_HANDLE;
        }
		if(cat182_animation_handle != GDI_ERROR_HANDLE)
		{
			number = gdi_anim_get_current_frame_number(cat182_animation_handle);
			gdi_image_cache_reset();
            if((img_width != CAT182_ICON_WIDTH) || (img_height != CAT182_ICON_HEIGHT))
            {
			    gdi_image_draw_resized_file_frames(
			        x_position_align,
                    y_position_align,
                    img_width_align,
                    img_height_align,
					g_cat182_imagepath,
					number);
            }
            else
            {
                gdi_image_draw_file_frames(
			        CAT182_ICON_X + x,
                    CAT182_ICON_Y + y,
					g_cat182_imagepath,
					number);
            }
		}

		else if((img_width != CAT182_ICON_WIDTH) || (img_height != CAT182_ICON_HEIGHT))
		{ 
			gdi_image_draw_animation_resized_file(
			        x_position_align,
                    y_position_align,
                    img_width_align,
                    img_height_align,
                    g_cat182_imagepath,
					&cat182_animation_handle);
		}
		else
		{
    		gdi_image_draw_animation_file(CAT182_ICON_X + x, CAT182_ICON_Y + y, g_cat182_imagepath, &cat182_animation_handle);
		}
	}
	else if((img_width != CAT182_ICON_WIDTH) || (img_height != CAT182_ICON_HEIGHT))
	{
    	gdi_image_draw_resized_file(x_position_align, y_position_align, img_width_align, img_height_align, g_cat182_imagepath);
	}
    else
    {
        gdi_image_draw_file(CAT182_ICON_X + x, CAT182_ICON_Y + y, g_cat182_imagepath);
    }
    //gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat182_highlight_handler
 * DESCRIPTION
 *  cat182 Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat182_highlight_handler(S32 item_index)
{
	gdi_image_stop_animation(cat182_animation_handle);
	cat182_animation_handle = GDI_ERROR_HANDLE;
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }

    MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if (UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory182Screen
 * DESCRIPTION
 *  Displays the category182 screen , recommended image size 50X50
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items to be displayed
 *  list_of_items           [IN]        String array of list of text items 
 *  get_image_func          [IN]        Function pointer to get next displayed image path
 *  list_of_state           [IN]        Read/Unread state(0:read,1:unread) 
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory182Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        wgui_cat_182_getimagepath get_image_func,
        U8 *list_of_state,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 text_width, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();   /* in order to let APP to refresh quickly, we block this effect */
#endif
    g_cat182_get_imagepath_func = get_image_func;
    cat182_animation_handle = GDI_ERROR_HANDLE;

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT182_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP;
    dm_add_title(title, title_icon);
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);
    wgui_fixed_list_create_multi_icontext_menu(
        0, 
        1, 
        number_of_items, 
        highlighted_item, 
        CAT182_MENUITEM_HEIGHT, 
        0,
        MMI_CATEGORY182_ID,
        history_buffer);
    set_fixed_icontext_list_menuitems_post_display(wgui_cat_182_post_display_menuitem);
    set_fixed_icontext_list_text_coordinates(0, CAT182_TEXT_X, 0, text_width, CAT182_MENUITEM_HEIGHT);
#if defined(__MMI_OP01_DCD__)
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_dcd_theme->dcd_channel_list_highlight_filler;
    MMI_fixed_icontext_list_menuitem.selected_filler = current_dcd_theme->dcd_channel_list_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_dcd_theme->dcd_channel_list_highlight_filler;
#endif
    resize_fixed_icontext_list_menuitems(0, CAT182_MENUITEM_HEIGHT);
    wgui_fixed_list_override_multi_icontext_highlight_handler(wgui_cat182_highlight_handler);
    wgui_fixed_list_begin_add_multi_icontext_one_item();

    for (i = 0; i < number_of_items; i++)
    {
        U8* items[1];
        items[0] = list_of_items[i];
        /* set different color */
        if (list_of_state[i] == 1)
        {
	        MMI_fixed_icontext_list_menuitems[i].ext_flags |= UI_MENUITEM_EXT_SHOW_DIFFERENT_COLOR;
	        wgui_fixed_list_set_text_color(current_dcd_theme->dcd_idle_read_text_color);
        }
        wgui_fixed_list_add_multi_icontext_one_item(i, items, NULL, NULL);
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();
    //wgui_fixed_list_resize_multi_icontext_menu(MMI_content_width, MMI_content_height);

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory182Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY182_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /* defined(__MMI_OP01_DCD__) */


#if defined(__MMI_OP11_HOMESCREEN__)
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
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
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
        #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
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
#endif /* defined(__MMI_OP11_HOMESCREEN__) */

#ifdef __MMI_CAT1X_0P11_SUPPORT__

typedef struct _list_menu_category_history1001_op11
{
    U16 history_ID;
    S16 highlighted_item;
    S16 first_displayed_item;
    S16 last_displayed_item;
    S16 displayed_items;
    U32 flags;
    S32 width;
	S32 height;
} list_menu_category_history_cat1001_op11;

/*****************************************************************************
 * FUNCTION
 *  set_list_menu_category1001_op11_history
 * DESCRIPTION
 *  Sets the history data for the list menu of category1001
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [IN]        Buffer from which history data is taken
 * RETURNS
 *  byte              Returns true if the history ID is valid
 *****************************************************************************/
static U8 set_list_menu_category1001_op11_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history_cat1001_op11 *h = (list_menu_category_history_cat1001_op11*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            MMI_fixed_list_menu.highlighted_item = h->highlighted_item;
            MMI_fixed_list_menu.first_displayed_item = h->first_displayed_item;
            MMI_fixed_list_menu.last_displayed_item = h->last_displayed_item;
            MMI_fixed_list_menu.displayed_items = h->displayed_items;
            MMI_fixed_list_menu.flags = h->flags;
			MMI_fixed_list_menu.width = h->width;
			MMI_fixed_list_menu.height = h->height;
            return (1);
        }
    }
    return (0);
}   /* end of set_list_menu_cat1001_op11_history */


/*****************************************************************************
 * FUNCTION
 *  get_list_menu_category_history1001_op11
 * DESCRIPTION
 *  Gets the history data for the list menu of category1001
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [OUT]        Buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
static void get_list_menu_category_history1001_op11(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);

        list_menu_category_history_cat1001_op11 *h = (list_menu_category_history_cat1001_op11*) history_buffer;

        h->history_ID = hID;
        h->highlighted_item = (S16) MMI_fixed_list_menu.highlighted_item;
        h->first_displayed_item = (S16) MMI_fixed_list_menu.first_displayed_item;
        h->last_displayed_item = (S16) MMI_fixed_list_menu.last_displayed_item;
        h->displayed_items = (S16) MMI_fixed_list_menu.displayed_items;
        h->flags = MMI_fixed_list_menu.flags;
		h->width = MMI_fixed_list_menu.width;
		h->height = MMI_fixed_list_menu.height;
    }
}   /* end of get_list_menu_category_history155 */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_op11_get_history_size
 * DESCRIPTION
 *  Gets the history buffer size for Category1001 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 wgui_cat1001_op11_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_category_history_cat1001_op11));
}   /* end of GetCategory152HistorySize */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_op11_get_history
 * DESCRIPTION
 *  Gets the history buffer for Category1001 screen
 * PARAMETERS
 *  history_buffer      [OUT]        History_buffer is a pointer to the buffer where the history data is to be stored      (pre-allocated)
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *wgui_cat1001_op11_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history1001_op11(MMI_CAT1001_OP11_ID, history_buffer);
    return (history_buffer);
}   /* end of GetCategory155History */


/*****************************************************************************
* FUNCTION
*  wgui_cat1001_op11_draw_ctrl_area
* DESCRIPTION
*  Cateogry 1001 for op11 control area redraw callback
* PARAMETERS
*  coordinate      [IN]     Area to redraw
* RETURNS
*  void
 *****************************************************************************/    
static void wgui_cat1001_op11_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    s32 element_width, element_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    coordinate->s16X = 0;
#ifdef GUI_COMMON_SHOW_STATUS_ICON
    coordinate->s16Y = (MMI_STATUS_BAR_HEIGHT + MMI_MENUITEM_HEIGHT);
#else
    coordinate->s16Y = (MMI_MENUITEM_HEIGHT);
#endif
    coordinate->s16Width = UI_device_width;

    resize_multiline_inputbox_fit(
        MMI_content_width,
        MMI_content_height,
        &element_width,
        &element_height);

    move_multiline_inputbox(0, coordinate->s16Y);
    resize_multiline_inputbox(element_width, element_height);
    show_multiline_inputbox();

    coordinate->s16Height = element_height;
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1001_op11_exit
* DESCRIPTION
*  Exits the category1001_op11 screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1001_op11_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitListCategoryScreen();
}


/* For detail description, please refer to wgui_categories_list_op.h */
void wgui_cat1001_op11_show(
            UI_string_type message_title,
            UI_string_type message,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_items,
            U8 **list_of_items,
            U16 *list_of_icons,
            U8 **list_of_descriptions,
            S32 highlighted_item,
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 i;
    U8 flag = 0;
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    /* softkey */
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    /* message area */
     l = gui_strlen(message_title);
	create_singleline_inputbox_set_buffer(message_title, (l + 1), l, 0);
    set_singleline_inputbox_mask(0);
    MMI_singleline_inputbox.normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    MMI_singleline_inputbox.text_font = &MMI_large_font;
    MMI_singleline_inputbox.flags |=
          (UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
           UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT | UI_SINGLE_LINE_INPUT_BOX_CENTER_Y);

    l = gui_strlen(message);
    create_multiline_inputbox_set_buffer(message, l, l, 0);
	MMI_multiline_inputbox.normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

    /* list */
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CAT1001_OP11_ID, history_buffer);
    wgui_fixed_list_begin_add_icontext_one_item();

    if (list_of_descriptions == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
        }
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]), list_of_descriptions[i]);
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    for (i = 0; i < number_of_items; i++)
    {
        if (list_of_icons[i] != UI_NULL_IMAGE)
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        set_fixed_icontext_positions(GUI_TEXT_MENUITEM_TEXT_X, 0, 1, 0);

    }  

    gdi_layer_unlock_frame_buffer();
    ExitCategoryFunction = wgui_cat1001_op11_exit;
    dm_register_category_controlled_callback(wgui_cat1001_op11_draw_ctrl_area);
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT1001_OP11_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}

/* category 1002 for re-order */

static wgui_cat1002_op11_draw_menuitem_func g_cat1002_op11_draw_menuitem_func;
static U8 **g_cat1002_op11_list_items = NULL;
static U16 *g_cat1002_op11_list_icons1 = NULL;
static U16 *g_cat1002_op11_list_icons2 = NULL;
static S32 g_cat1002_op11_list_number = 0;
static MMI_BOOL g_cat1002_op11_is_order_screen = MMI_FALSE;

/* For detail description, please refer to wgui_categorie_list_op.h */
void wgui_cat1002_op11_set_order_screen(MMI_BOOL is_order_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat1002_op11_is_order_screen = is_order_screen;
}

/* For detail description, please refer to wgui_categorie_list_op.h */
void wgui_cat1002_op11_goto_list(S32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < g_cat1002_op11_list_number; i++)
    {
        MMI_fixed_icontext_list_menuitems[i].item_texts[0] = (UI_string_type)g_cat1002_op11_list_items[i];
        MMI_fixed_icontext_list_menuitems[i].item_icons[0] = get_image(g_cat1002_op11_list_icons1[i]);
        MMI_fixed_icontext_list_menuitems[i].item_icons[1] = get_image(g_cat1002_op11_list_icons2[i]);
    }
    fixed_list_goto_item(highlighted_item);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/* For detail description, please refer to wgui_categorie_list_op.h */
void wgui_cat1002_op11_touch_refresh_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < g_cat1002_op11_list_number; i++)
    {
        MMI_fixed_icontext_list_menuitems[i].item_texts[0] = (UI_string_type)g_cat1002_op11_list_items[i];
        MMI_fixed_icontext_list_menuitems[i].item_icons[0] = get_image(g_cat1002_op11_list_icons1[i]);
        MMI_fixed_icontext_list_menuitems[i].item_icons[1] = get_image(g_cat1002_op11_list_icons2[i]);
    }
    show_fixed_list();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/* For detail description, please refer to wgui_categorie_list_op.h */
void wgui_cat1002_op11_refresh_item_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < g_cat1002_op11_list_number; i++)
    {
        MMI_fixed_icontext_list_menuitems[i].item_texts[0] = (UI_string_type)g_cat1002_op11_list_items[i];
        MMI_fixed_icontext_list_menuitems[i].item_icons[0] = get_image(g_cat1002_op11_list_icons1[i]);
        MMI_fixed_icontext_list_menuitems[i].item_icons[1] = get_image(g_cat1002_op11_list_icons2[i]);
    }

    gdi_layer_unlock_frame_buffer();
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1002_op11_exit
* DESCRIPTION
*  Exits the category1002_op11 screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1002_op11_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitListCategoryScreen();
    g_cat1002_op11_is_order_screen = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1002_op11_show_menuitem
 * DESCRIPTION
 *  Category 1002_op11 menu item show function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 *  x                      [IN]     x
 *  y                      [IN]     y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1002_op11_show_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_hilighted;
    S32 item_width, item_height;
    U32 list_flags;
    fixed_icontext_list_menuitem_type *mi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_fixed_list_set_alpha_blending_layer(dm_get_scr_bg_layer());
    gui_show_fixed_icontext_list_menuitem(item, common_item_data, x, y);
    mi = (fixed_icontext_list_menuitem_type*) item;
    list_flags = mi->flags;

    if ((MMI_fixed_list_menu.current_displayed_item == MMI_fixed_list_menu.highlighted_item) &&
        (list_flags & UI_MENUITEM_STATE_FOCUSSED))    
    {
        is_hilighted = MMI_TRUE;
    }
    else
    {
        is_hilighted = MMI_FALSE;
    }

    MMI_fixed_list_menu.item_measure_function(
                            item,
                            common_item_data,
                            &item_width,
                            &item_height);

    if (g_cat1002_op11_draw_menuitem_func != NULL)
    {
        gdi_layer_lock_frame_buffer();        
        g_cat1002_op11_draw_menuitem_func(
            MMI_fixed_list_menu.current_displayed_item,
            is_hilighted,
            x,
            y,
            x + item_width - 1,
            y + item_height - 1);
        gdi_layer_unlock_frame_buffer();
    }
}
UI_filled_area g_1002_focussed_filler =
    {UI_FILLED_AREA_LEFT_RIGHT_ROUNDED_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 255, 0},
    {0, 0, 0, 0},
    {255, 128, 0, 0},
    {0, 0, 0, 0},
    0
};

/* For detail description, please refer to wgui_categorie_list_op.h */
void wgui_cat1002_op11_show(
            UI_string_type message_title,
            UI_string_type message,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_items,
            U8 **list_of_items,
            U16 *list_of_icons1,
            U16 *list_of_icons2,
            S32 highlighted_item,
            wgui_cat1002_op11_draw_menuitem_func draw_menuitem_func,
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 l;
    S32 text_width = 0, text_position = 0, icon1_position = 0, icon2_position = 0;
    S32 i = 0, w1 = 0, w2 = 0, h1 = 0, h2 = 0, iw = 0, ih = 0;
    U8 *img = NULL;
    U8 isicon1 = 0, isicon2 = 0;
	U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    /* softkey */
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);
    g_cat1002_op11_list_items = list_of_items;
    g_cat1002_op11_list_icons1 = list_of_icons1;
    g_cat1002_op11_list_icons2 = list_of_icons2;
    g_cat1002_op11_list_number = number_of_items;
    g_cat1002_op11_draw_menuitem_func = draw_menuitem_func;

    /* message area */
     l = gui_strlen(message_title);
	create_singleline_inputbox_set_buffer(message_title, (l + 1), l, 0);
    set_singleline_inputbox_mask(0);
    MMI_singleline_inputbox.normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    MMI_singleline_inputbox.text_font = &MMI_large_font;
    MMI_singleline_inputbox.flags |=
          (UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
           UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT | UI_SINGLE_LINE_INPUT_BOX_CENTER_Y);

    l = gui_strlen(message);
    create_multiline_inputbox_set_buffer(message, l, l, 0);
	MMI_multiline_inputbox.normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;
    dm_register_category_controlled_callback(wgui_cat1001_op11_draw_ctrl_area);

    /* list */
    wgui_fixed_list_create_multi_icontext_menu(
        2,
        1,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_DISABLE_SHORTCUT,
        0,
        NULL);
	h_flag = set_list_menu_category1001_op11_history(MMI_CAT1001_OP11_ID, history_buffer);
	if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    if(g_cat1002_op11_is_order_screen)
    {
        MMI_fixed_icontext_list_menuitem.focussed_filler = &g_1002_focussed_filler;
	    MMI_fixed_icontext_list_menuitem.selected_filler = &g_1002_focussed_filler;
    #ifndef __MMI_FTE_SUPPORT__
        MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = gui_color(0, 0, 0);
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = gui_color(0, 0, 0);
    #else
        MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = gui_color(255, 255, 255);
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = gui_color(255, 255, 255);
    #endif
    }
    for (i = 0; i < number_of_items; i++)
    {
        //img = (U8*) GetImage(list_of_icons1[i]);
        //if (img)
        //{
            gui_measure_image(GetImage(list_of_icons1[i]), &iw, &ih);
            w1 = (iw > w1) ? (iw) : (w1);
            h1 = (ih > h1) ? (ih) : (h1);
        //}

        //img = (U8*) GetImage(list_of_icons2[i]);
        //if (img)
        //{
            gui_measure_image(GetImage(list_of_icons2[i]), &iw, &ih);
            w2 = (iw > w2) ? (iw) : (w2);
            h2 = (ih > h2) ? (ih) : (h2);
        //}
    }

    isicon1 = (!w1 || !h1) ? (0) : (1);
    isicon2 = (!w2 || !h2) ? (0) : (1);
    w1 = (isicon1) ? (w1) : (0);
    h1 = (isicon1) ? (h1) : (0);
    w2 = (isicon2) ? (w2) : (0);
    h2 = (isicon2) ? (h2) : (0);

    icon1_position = (isicon1) ? (GUI_ICONTEXT_MENUITEM_ICON_X) : (0);
    text_position = (isicon1) ? (GUI_ICONTEXT_MENUITEM_TEXT_X) : (GUI_TEXT_MENUITEM_TEXT_X);
    text_width = (UI_device_width - MMI_fixed_list_menu.vbar.width - text_position - 1 - 2/* image highlight border*/);
    text_width -= (isicon2) ? (w2 + 3) : (0);
    icon2_position = (isicon2) ? (text_position + text_width + 3 - 1) : (0);

    set_fixed_icontext_list_text_coordinates(0, text_position, 0, text_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_icon_coordinates(0, icon1_position, 0, w1, h1);
    set_fixed_icontext_list_icon_coordinates(1, icon2_position, 0, w2, h2);

    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[1];
        U8 *icons[2];
        items[0] = list_of_items[i];
        icons[0] = get_image(list_of_icons1[i]);
        icons[1] = get_image(list_of_icons2[i]);

        wgui_fixed_list_add_multi_icontext_one_item(i, items, icons, NULL);

    }
    wgui_fixed_list_end_add_multi_icontext_one_item();
    MMI_fixed_list_menu.item_display_function = wgui_cat1002_op11_show_menuitem;

    gdi_layer_unlock_frame_buffer();
    ExitCategoryFunction = wgui_cat1002_op11_exit;
    dm_setup_category_functions(dm_redraw_category_screen, wgui_cat1001_op11_get_history, wgui_cat1001_op11_get_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT1001_OP11_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /* __MMI_CAT1X_0P11_SUPPORT__*/
#ifdef __MMI_OP01_DCD_V30__
extern S32 gdi_anim_get_current_frame_number(gdi_handle serial_handle);
static wgui_cat9005_op01_getimagepath g_cat9005_op01_get_imagepath_func = NULL;
static S8 g_cat9005_op01_imagepath[(SRV_FMGR_PATH_MAX_LEN + 1)];
static GDI_HANDLE cat9005_op01_animation_handle;
static void wgui_cat9005_op01_exit(void);
static void wgui_cat9005_op01_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y);
static void wgui_cat9005_op01_post_display_menuitem_extern(void *item, void *common_item_data, S32 x, S32 y);
static void wgui_cat9005_op_highlight_handler(S32 item_index);
static void wgui_cat9005_op01_menuitem_image_draw(S32 img_width,
                                                                S32 img_height,
                                                                S32 x,
                                                                S32 y,
                                                                S32 item_index,
                                                                U8* img_ptr,
                                                                MMI_BOOL resource_img);
void wgui_cat9005_op01_show(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        wgui_cat9005_op01_getimagepath get_image_func,
        U8 *list_of_state,
        S32 highlighted_item,
        U8 *history_buffer,
        MMI_BOOL ext_flag)
{
    dm_data_struct dm_data;
    S32 text_width, i;
    S32 font_height_s;
    S32 font_height_m;
    U8* items[2];
    gdi_layer_lock_frame_buffer();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();   /* in order to let APP to refresh quickly, we block this effect */
#endif
    g_cat9005_op01_get_imagepath_func = get_image_func;
    cat9005_op01_animation_handle = GDI_ERROR_HANDLE;
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT9005_OP01_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP;
    dm_add_title(title, title_icon);
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);
    wgui_fixed_list_create_multi_icontext_menu(
        0, 
        2, 
        number_of_items, 
        highlighted_item, 
        CAT9005_OP01_MENUITEM_HEIGHT, 
        0,
        MMI_CAT9005_OP01_ID,
        history_buffer);
    if(ext_flag)
    {
        set_fixed_icontext_list_menuitems_post_display(wgui_cat9005_op01_post_display_menuitem_extern);
    }
    else
    {
        set_fixed_icontext_list_menuitems_post_display(wgui_cat9005_op01_post_display_menuitem);
    }

    font_height_s = Get_CharHeightOfAllLang(SMALL_FONT);
    font_height_m = Get_CharHeightOfAllLang(MEDIUM_FONT);
    set_fixed_icontext_list_text_coordinates(0, CAT9005_OP01_TEXT_X, 6, text_width, font_height_m);
    set_fixed_icontext_list_text_coordinates(1, CAT9005_OP01_TEXT_X, CAT9005_OP01_MENUITEM_HEIGHT - font_height_s, text_width, font_height_s);
#if 0//defined(__MMI_OP01_DCD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    resize_fixed_icontext_list_menuitems(0, CAT9005_OP01_MENUITEM_HEIGHT);
    wgui_fixed_list_override_multi_icontext_highlight_handler(wgui_cat9005_op_highlight_handler);
    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        items[0] = list_of_items1[i];
        items[1] = list_of_items2[i]/*list_of_items[i]*/;
        if (list_of_state[i] == 1)
        {
	        MMI_fixed_icontext_list_menuitems[i].ext_flags |= UI_MENUITEM_EXT_SHOW_DIFFERENT_COLOR;
	        //wgui_fixed_list_set_text_color(current_dcd_theme->dcd_idle_read_text_color);
        }
        wgui_fixed_list_add_multi_icontext_one_item(i, items, NULL, NULL);
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();
    gdi_layer_unlock_frame_buffer();
    ExitCategoryFunction = wgui_cat9005_op01_exit;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT9005_OP01_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9005_op01_exit
 * DESCRIPTION
 *  Exit the cat9005_op01 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9005_op01_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_pop_up_descriptions();

	gdi_image_stop_animation(cat9005_op01_animation_handle);
	cat9005_op01_animation_handle = GDI_ERROR_HANDLE;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */  
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    g_cat9005_op01_get_imagepath_func = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9005_op01_post_display_menuitem
 * DESCRIPTION
 *  post menuitem to display
 * PARAMETERS
 *  item                    [IN]        item type
 *  common_item_data        [IN]        item list
 *  x                       [IN]        list x
 *  y                       [IN]        list y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9005_op01_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    S32 item_index;
	S32 img_width, img_height;
    S32 channel_cnt = 0;
    MMI_BOOL      preset_only = MMI_FALSE;
    MMI_BOOL      resource_img = MMI_FALSE;
    U8*           img_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(g_cat9005_op01_imagepath, 0, SRV_FMGR_PATH_MAX_LEN + 1);
    item_index = MMI_fixed_list_menu.current_displayed_item;
    if (item_index == -1)
    {
        item_index = wgui_title_get_menu_shortcut_number() - 1;
    }

    mmi_dcd_get_channel_list_status(&channel_cnt, &preset_only);
    if((preset_only))
    {
        if(item_index == 0)
        {
            img_ptr = get_image(IMG_ID_DCD_DEFAULT);
        }
        else
        {
            img_ptr = get_image(IMG_ID_DCD_MY_FAVORITE);
        }
        gdi_image_get_dimension(img_ptr, &img_width, &img_height);
        resource_img = MMI_TRUE;
    }
    else if(item_index == channel_cnt)
    {
        img_ptr = get_image(IMG_ID_DCD_MY_FAVORITE);
        gdi_image_get_dimension(img_ptr, &img_width, &img_height);
        resource_img = MMI_TRUE;
    }
    else
    {
        g_cat9005_op01_get_imagepath_func(item_index, g_cat9005_op01_imagepath);
        if(strlen(g_cat9005_op01_imagepath) > 0)
        {
        	gdi_image_get_dimension_file(g_cat9005_op01_imagepath, &img_width, &img_height);
        }
        else
        {
            img_ptr = get_image(IMG_ID_DCD_DEFAULT);
            gdi_image_get_dimension(img_ptr, &img_width, &img_height);
            resource_img = MMI_TRUE;
        }
    
    }

    wgui_cat9005_op01_menuitem_image_draw(img_width, img_height, x, y, item_index, img_ptr, resource_img);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9005_op01_post_display_menuitem_extern
 * DESCRIPTION
 *  post menuitem to display
 * PARAMETERS
 *  item                    [IN]        item type
 *  common_item_data        [IN]        item list
 *  x                       [IN]        list x
 *  y                       [IN]        list y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9005_op01_post_display_menuitem_extern(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    S32 item_index;
	S32 img_width, img_height;
    MMI_BOOL      resource_img = MMI_FALSE;
    U8*           img_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(g_cat9005_op01_imagepath, 0, SRV_FMGR_PATH_MAX_LEN + 1);
    item_index = MMI_fixed_list_menu.current_displayed_item;
    if (item_index == -1)
    {
        item_index = wgui_title_get_menu_shortcut_number() - 1;
    }

    g_cat9005_op01_get_imagepath_func(item_index, g_cat9005_op01_imagepath);
    if(strlen(g_cat9005_op01_imagepath) > 0)
    {
    	gdi_image_get_dimension_file(g_cat9005_op01_imagepath, &img_width, &img_height);
    }
    else
    {
        img_ptr = get_image(IMG_ID_DCD_DEFAULT);
        gdi_image_get_dimension(img_ptr, &img_width, &img_height);
        resource_img = MMI_TRUE;
    }
    wgui_cat9005_op01_menuitem_image_draw(img_width, img_height, x, y, item_index, img_ptr, resource_img);
}

static void wgui_cat9005_op01_menuitem_image_draw(S32 img_width,
                                                                S32 img_height,
                                                                S32 x,
                                                                S32 y,
                                                                S32 item_index,
                                                                U8* img_ptr,
                                                                MMI_BOOL resource_img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number = 0;
    S32 img_width_align, img_height_align, x_position_align, y_position_align;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (img_width >= CAT9005_OP01_ICON_WIDTH)
	{
		img_width_align = CAT9005_OP01_ICON_WIDTH;
        x_position_align = CAT9005_OP01_ICON_X + x; 
	}
    else
    {
    	img_width_align = img_width;
        x_position_align = CAT9005_OP01_ICON_X + x + ((CAT9005_OP01_ICON_WIDTH -img_width) >>1); 
    }
    if (img_height >= CAT9005_OP01_ICON_HEIGHT)
	{
		img_height_align = CAT9005_OP01_ICON_HEIGHT;
        y_position_align = CAT9005_OP01_ICON_Y + y;
	}
    else
    {
    	img_height_align = img_height;
        y_position_align = CAT9005_OP01_ICON_Y + y + ((CAT9005_OP01_ICON_HEIGHT -img_height) >>1);
    }	
    if(item_index == MMI_fixed_list_menu.highlighted_item)
	{

        if(resource_img)
        {
            if((img_width != CAT9005_OP01_ICON_WIDTH) || (img_height != CAT9005_OP01_ICON_HEIGHT))
            {

                
                gdi_image_draw_resized(x_position_align,
                                            y_position_align,
                                            img_width_align,
                                            img_height_align,
                                            img_ptr);
            }
            else
            {
                gdi_image_draw(x_position_align,
                                    y_position_align,
                                    img_ptr);
            }
        }
        else
        {
            if (gui_screen_smooth_scrolling_by_pen())
            {
                gdi_anim_stop(cat9005_op01_animation_handle);
                cat9005_op01_animation_handle = GDI_ERROR_HANDLE;
            }
    		if(cat9005_op01_animation_handle != GDI_ERROR_HANDLE)
    		{
    			number = gdi_anim_get_current_frame_number(cat9005_op01_animation_handle);
    			gdi_image_cache_reset();
                if((img_width != CAT9005_OP01_ICON_WIDTH) || (img_height != CAT9005_OP01_ICON_HEIGHT))
                {
    			    gdi_image_draw_resized_file_frames(
    			        x_position_align,
                        y_position_align,
                        img_width_align,
                        img_height_align,
    					g_cat9005_op01_imagepath,
    					number);
                }
                else
                {
                    gdi_image_draw_file_frames(
    			        CAT9005_OP01_ICON_X + x,
                        CAT9005_OP01_ICON_Y + y,
    					g_cat9005_op01_imagepath,
    					number);
                }
    		}

    		else if((img_width != CAT9005_OP01_ICON_WIDTH) || (img_height != CAT9005_OP01_ICON_HEIGHT))
    		{ 
    			gdi_image_draw_animation_resized_file(
    			        x_position_align,
                        y_position_align,
                        img_width_align,
                        img_height_align,
                        g_cat9005_op01_imagepath,
    					&cat9005_op01_animation_handle);
    		}
    		else
    		{
        		gdi_image_draw_animation_file(CAT9005_OP01_ICON_X + x, CAT9005_OP01_ICON_Y + y, g_cat9005_op01_imagepath, &cat9005_op01_animation_handle);
    		}
        }
        
	}
	else if((img_width != CAT9005_OP01_ICON_WIDTH) || (img_height != CAT9005_OP01_ICON_HEIGHT))
	{
    	if(resource_img)
        {
            gdi_image_draw_resized(x_position_align,
                                        y_position_align,
                                        img_width_align,
                                        img_height_align,
                                        img_ptr);
        }   
        else
        {
            gdi_image_draw_resized_file(x_position_align, y_position_align, img_width_align, img_height_align, g_cat9005_op01_imagepath);
        }
	}
    else
    {
        if(resource_img)
        {
            gdi_image_draw(x_position_align,
                                y_position_align,
                                img_ptr);
        }
        else
        {
            gdi_image_draw_file(CAT9005_OP01_ICON_X + x, CAT9005_OP01_ICON_Y + y, g_cat9005_op01_imagepath);
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9005_op_highlight_handler
 * DESCRIPTION
 *  cat9005 Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9005_op_highlight_handler(S32 item_index)
{
	gdi_image_stop_animation(cat9005_op01_animation_handle);
	cat9005_op01_animation_handle = GDI_ERROR_HANDLE;
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }

    MMI_list_highlight_handler(item_index);
#if (UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}

#endif /*__MMI_OP01_DCD_V30__*/
