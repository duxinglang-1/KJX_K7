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

/*****************************************************************************
 * Filename:
 * ---------
 *  wgui_fixed_menu_items.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  fixed menu item external interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_FIXED_MENUITEMS_H__
#define __WGUI_FIXED_MENUITEMS_H__
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "GlobalConstants.h"
#include "gui_fixed_menuitems.h"
#include "MMIDataType.h"
#include "gui_fixed_menus.h"
#include "kal_general_types.h"
#include "gui_theme_struct.h"
#include "gui_data_types.h"
#include "gui_config.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/* Integrated_menuitem structure */
typedef struct _integrated_menuitem
{
    /* Use union to share the space */
    union
    {
        /* Fixed twostate menuitem */
        fixed_twostate_menuitem_type fixedtwoStatetype[MAX_FIXED_TWOSTATE_MENU_ITEMS];
        /* Fixed icontext list menuitem */
        fixed_icontext_list_menuitem_type fixedIconListtype[MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS];
        /* Fixed icontext menuitem */
        fixed_icontext_menuitem_type fixedIconTexttype[MAX_FIXED_ICONTEXT_MENU_ITEMS];
        /* Fixed text menuitem */
        fixed_text_menuitem_type fixedTexttype[MAX_FIXED_TEXT_MENU_ITEMS];
    } menuUnion;
} integrated_menuitem;

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_menu_struct_fixed_menuitem>
 *  Structure of horizontal select menuitem */
typedef struct _wgui_horizontal_select_menuitem_struct
{
    /* X-coordinate */
    S32 x;
    /* Y-coordinate */
    S32 y;
    /* Width of the horizontal select */
    S32 width;
    /* Height of the horizontal select */
    S32 height;
    /* The index fo current displayed item */
    S32 current_item;
    /* Number of items in the horizontal select */
    S32 no_of_items;
    /* Callback function to get the data */
    wgui_two_line_get_horizontal_select_data_callback two_line_select_get_data;
    /* Complete callback function, do something at last */
    wgui_two_line_menuitem_complete_callback two_line_select_complete;
    /* Callback function to get default value */
    wgui_two_line_menuitem_get_default_callback two_line_default_value;
    /* Current event of pen */
    gui_list_pen_enum menuitem_current_event;
    /* Down event of pen */
    gui_list_pen_enum menuitem_down_event;
} wgui_horizontal_select_menuitem_struct;

/* <group dom_menu_struct_fixed_menuitem>
 *  Structure of level select menuitem */
typedef struct _wgui_level_select_menutitem_struct
{
    /* X-coordinate */
    S32 x;
    /* Y-coordinate */
    S32 y;
    /* Width of the level select */
    S32 width;
    /* Height of the level select */
    S32 height;
    /* The index fo current displayed item */
    S32 current_item;
    /* Number of items in the horizontal select */
    S32 no_of_items;
    /* Callback function to get the data */
    wgui_two_line_get_level_select_data_callback two_line_select_get_data;
    /* Complete callback function, do something at last */
    wgui_two_line_menuitem_complete_callback two_line_select_complete;
    /* Callback function to get default value */
    wgui_two_line_menuitem_get_default_callback two_line_default_value;
} wgui_level_select_menutitem_struct;

/* <group dom_menu_struct_fixed_menuitem>
 *  Structure of two-line arrow */
typedef struct 
{
    /* X-coordinate */
    S32 x;
    /* Y-coordinate */
    S32 y;
    /* Width of the arrow */
    S32 width;
    /* Height of the arrow */
    S32 height;
} wgui_two_line_arrow_struct;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/ 

extern fixed_text_menuitem MMI_fixed_text_menuitem;
extern fixed_text_menuitem_type *MMI_fixed_text_menuitems;
extern S32 *fixed_text_menu_n_items;
extern void *MMI_fixed_menuitem_pointers[];


extern fixed_icontext_menuitem MMI_fixed_icontext_menuitem;
extern fixed_icontext_menuitem_type *MMI_fixed_icontext_menuitems;
extern S32 *fixed_icontext_menu_n_items;


extern fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;
extern fixed_icontext_list_menuitem_type *MMI_fixed_icontext_list_menuitems;
extern S32 *fixed_icontext_list_menu_n_items;


extern fixed_twostate_menuitem MMI_fixed_twostate_menuitem;
extern fixed_twostate_menuitem_type *MMI_fixed_twostate_menuitems;
extern S32 *fixed_twostate_menu_n_items;

extern MMI_BOOL wgui_list_menu_slow_data_mode;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/ 
/* 
 * fixed text menuitem  
 */

/* DOM-NOT_FOR_SDK-BEGIN */

 /*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  get_menu_item_height
 * DESCRIPTION
 *  Get the height of menuitem according to current font height. However, to support 
 *  image highlight, this function always returns MMI_MENUITEM_HEIGHT.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_MENUITEM_HEIGHT
 *****************************************************************************/
extern U8 get_menu_item_height(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_text_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme for the fixed text menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_text_menuitem_apply_current_theme(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_text_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the given theme to the fixed text menu items.
 * PARAMETERS
 *  t       [IN]        Fixed text menu item theme     
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_text_menuitem_apply_theme(UI_fixed_text_menuitem_theme *t);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  create_fixed_text_menuitems
 * DESCRIPTION
 *  Create the fixed text menu items and configure the common data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void create_fixed_text_menuitems(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_text_menuitems
 * DESCRIPTION
 *  Resize the fixed text menu items.
 * PARAMETERS
 *  width       : [IN]        New width of fixed text menuitems
 *  height      : [IN]        New height of fixed text menuitems
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_text_menuitems(S32 width, S32 height);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_text_list
 * DESCRIPTION
 *  Associate the fixed text menu items with the fixed list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_text_list(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_text_matrix
 * DESCRIPTION
 *  Associate fixed text menu items with the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_text_matrix(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_fixed_text_item
 * DESCRIPTION
 *  Add an item to the list of fixed text menu items at the end.
 * PARAMETERS
 *  s       : [IN]        Item text
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_text_item(UI_string_type s);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_location_fixed_text_item
 * DESCRIPTION
 *  Add an item to the list of fixed text menu items at a specified index.
 * PARAMETERS
 *  index       : [IN]        The location at which the new item is added (zero based)
 *  s           : [IN]        Item text
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_location_fixed_text_item(S32 index, UI_string_type s);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  remove_fixed_text_item
 * DESCRIPTION
 *  Remove a specified item from the fixed list
 * PARAMETERS
 *  index       : [IN]        The location of the item to be removed (zero based)
 * RETURNS
 *  void
 *****************************************************************************/
extern void remove_fixed_text_item(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_fixed_text_items
 * DESCRIPTION
 *  Add an array of items to the list of fixed text menu items at the end.
 * PARAMETERS
 *  n_items     : [IN]        Number of items to be added
 *  s           : [IN]        An array of item text
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_text_items(S32 n_items, UI_string_type *s);


/*****************************************************************************
* <group dom_menu_wgui_layer_fixed_menu_item_misc>
* FUNCTION
*  associate_fixed_multirow_list_list
* DESCRIPTION
*  Associate the list of fixed multirow list menu items with the fixed list.
* PARAMETERS
*  menu_item_height        : [IN]        Menu item height
* RETURNS
*  void
 *****************************************************************************/
extern void associate_fixed_multirow_list_list(S32);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_single_row_iconlist_fixed_list
 * DESCRIPTION
 *  Set menuitem's height to single line height
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_single_row_iconlist_fixed_list(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  fixed_matrix_auto_disable_scrollbar
 * DESCRIPTION
 *  Auto disable the scroll bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 * RETURN VALUES
 *  1  : If the auto-disable scroll bar option is enabled
 *  -1 : If the auto-disable scroll bar option is disabled
 *****************************************************************************/
extern S32 fixed_matrix_auto_disable_scrollbar(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  set_fixed_text_positions
 * DESCRIPTION
 *  Set the text position of the fixed text menu item.
 * PARAMETERS
 *  tx      : [IN]        X position of text   (0: centered horizontally)
 *  ty      : [IN]        Y position of text   (0: centered vertically)
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_fixed_text_positions(S32 tx, S32 ty);


/* 
 * fixed icontext menuitem 
 */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_icontext_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed icontext menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_icontext_menuitem_apply_current_theme(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_icontext_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the given theme to the fixed icontext menuitems.
 * PARAMETERS
 *  t       : [IN]        Fixed icontext menu item theme
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_icontext_menuitem_apply_theme(UI_fixed_icontext_menuitem_theme *t);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  create_fixed_icontext_menuitems
 * DESCRIPTION
 *  Create a list of icontext menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void create_fixed_icontext_menuitems(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_icontext_menuitems
 * DESCRIPTION
 *  Resize all fixed icontext menu items.
 * PARAMETERS
 *  width       : [IN]        New width of fixed icontext menu items
 *  height      : [IN]        New height of fixed icontext menu items
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_icontext_menuitems(S32 width, S32 height);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  center_fixed_icontext_positions
 * DESCRIPTION
 *  Set center justification of text and icons within the fixed icontext menu items.
 * PARAMETERS
 *  tx      : [IN]        1: Center text horizontally, 0: normal
 *  ty      : [IN]        1: Center text vertically, 0: normal
 *  ix      : [IN]        1: Center icon horizontally, 0: normal
 *  iy      : [IN]        1: Center icon vertically, 0: normal
 * RETURNS
 *  void
 *****************************************************************************/
extern void center_fixed_icontext_positions(U8 tx, U8 ty, U8 ix, U8 iy);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_fixed_icontext_positions
 * DESCRIPTION
 *  Set the positions of text and icons within the fixed icontext menu items.
 * PARAMETERS
 *  tx      : [IN]        X position of text   (0: The text is centered horizontally.)
 *  ty      : [IN]        Y position of text   (0: The text is centered vertically.)
 *  ix      : [IN]        X position of icon   (0: The icon is centered horizontally.)
 *  iy      : [IN]        Y position of icon   (0: The icon is centered vertically.)
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_fixed_icontext_positions(S32 tx, S32 ty, S32 ix, S32 iy);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_icontext_list
 * DESCRIPTION
 *  Associate the list of fixed icontext menu items with the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_icontext_list(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_icontext_matrix
 * DESCRIPTION
 *  Associate the list of fixed icontext menu items with the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_icontext_matrix(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_fixed_icontext_item
 * DESCRIPTION
 *  Add a new item to the list of fixed icontext menu items at the end.
 * PARAMETERS
 *  s       : [IN]        Item text
 *  img     : [IN]        Item icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_icontext_item(UI_string_type s, PU8 img);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  change_fixed_icontext_item
 * DESCRIPTION
 *  Change the text and icon of the specified item.
 * PARAMETERS
 *  index       : [IN]        Item index
 *  s           : [IN]        Item text
 *  img         : [IN]        Item icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void change_fixed_icontext_item(S32 index, UI_string_type s, PU8 img);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_location_fixed_icontext_item
 * DESCRIPTION
 *  Add a new item to the list of fixed icontext menu items at the specified index.
 * PARAMETERS
 *  index       : [IN]        The location at which the item is added (zero based)
 *  s           : [IN]        Item text
 *  img         : [IN]        Item icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_location_fixed_icontext_item(S32 index, UI_string_type s, PU8 img);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  remove_fixed_icontext_item
 * DESCRIPTION
 *  Remove the specified fixed icontext menu item.
 * PARAMETERS
 *  index       : [IN]        The location of the item to be removed
 * RETURNS
 *  void
 *****************************************************************************/
extern void remove_fixed_icontext_item(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_fixed_icontext_items
 * DESCRIPTION
 *  Adds an array of items at the end.
 * PARAMETERS
 *  n_items     : [IN]        Number of items to be added
 *  s           : [IN]        An array of item text strings
 *  img         : [IN]        An array of item icons
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_icontext_items(S32 n_items, UI_string_type *s, PU8 *img);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_menuitem_set_icontext_checkbox_position
 * DESCRIPTION
 *  Set the checkbox x and y offset to menu item (x1, y1).
 * PARAMETERS
 *  x_offset       : [IN]     X offset
 *  y_offset       : [IN]     Y offset
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_menuitem_set_icontext_checkbox_position(S32 x_offset, S32 y_offset);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_menuitem_register_icontext_checkbox_callback
 * DESCRIPTION
 *  Register the icontext checkbox callback function.
 * PARAMETERS
 *  clicked_cb      : [IN]    Checkbox clicked callback function pointer
 *  get_image_cb    : [IN]    Checkbox get image callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_menuitem_register_icontext_checkbox_callback(
                checkbox_clicked_funcptr_type clicked_cb, 
                checkbox_get_image_funcptr_type get_image_cb);



/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_menuitem_set_icontext_list_checkbox_position
 * DESCRIPTION
 *  Set the checkbox x and y offset to menu item (x1, y1).
 * PARAMETERS
 *  x_offset       : [IN]     X offset
 *  y_offset       : [IN]     Y offset
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_menuitem_set_icontext_list_checkbox_position(S32 x_offset, S32 y_offset);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_menuitem_register_icontext_checkbox_callback
 * DESCRIPTION
 *  Register the icontext checkbox callback function.
 * PARAMETERS
 *  clicked_cb      : [IN]    Checkbox clicked callback function pointer
 *  get_image_cb    : [IN]    Checkbox get image callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_menuitem_register_icontext_list_checkbox_callback(
                checkbox_clicked_funcptr_type clicked_cb, 
                checkbox_get_image_funcptr_type get_image_cb);


/* 
 * fixed icontext list menuitem 
 */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_icontext_list_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed icontext list menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_icontext_list_menuitem_apply_current_theme(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_icontext_list_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the given theme to the fixed icontext list menu items
 * PARAMETERS
 *  t       : [IN]     Fixed icontext list menu item theme
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_icontext_list_menuitem_apply_theme(UI_fixed_icontext_list_menuitem_theme *t);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  create_fixed_icontext_list_menuitems
 * DESCRIPTION
 *  Create a list of fixed icontext list menuitems.
 * PARAMETERS
 *  n_text_columns      : [IN]        Number of text columns
 *  n_icon_columns      : [IN]        Number of icon columns
 * RETURNS
 *  void
 *****************************************************************************/
extern void create_fixed_icontext_list_menuitems(S32 n_text_columns, S32 n_icon_columns);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
* <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
* FUNCTION
*  set_fixed_icontext_list_menuitems_post_display
* DESCRIPTION
*  Register callback handler after an icontext-list menu item is displayed.
*  
*  Icontext-list menu item is a general form of menu item that has more than one text & icon item
*  It can be further extended by registering post-display function which is called after each menu item
*  is drawn (not bitblted yet).
* PARAMETERS
*  post_display_function       : [IN]        Post display callback function
* RETURNS
*  void
 *****************************************************************************/
void set_fixed_icontext_menuitems_post_display(void (*post_display_function)
                                                    (void *item, void *common_item_data, S32 x, S32 y));


/*****************************************************************************
* <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
* FUNCTION
*  set_fixed_icontext_list_menuitems_post_display
* DESCRIPTION
*  Register callback handler after an icontext-list menu item is displayed.
*  
*  Icontext-list menu item is a general form of menu item that has more than one text & icon item
*  It can be further extended by registering post-display function which is called after each menu item
*  is drawn (not bitblted yet).
* PARAMETERS
*  post_display_function       : [IN]        Post display callback function
* RETURNS
*  void
 *****************************************************************************/
void set_fixed_icontext_list_menuitems_post_display(void (*post_display_function)
                                                    (void *item, void *common_item_data, S32 x, S32 y));


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_icontext_list_menuitems
 * DESCRIPTION
 *  Resize all the fixed icontext list menu items.
 * PARAMETERS
 *  width       : [IN]        New width of fixed icontext list menuitems
 *  height      : [IN]        New height of fixed icontext list menuitems
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_icontext_list_menuitems(S32 width, S32 height);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_fixed_icontext_list_text_coordinates
 * DESCRIPTION
 *  Set the coordinates of the specified text column.
 * PARAMETERS
 *  c           : [IN]        Index of the text column (zero based)
 *  x           : [IN]        Position of the text column within the item
 *  y           : [IN]        Position of the text column within the item
 *  width       : [IN]        Width of the text column
 *  height      : [IN]        Height of the text column
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_fixed_icontext_list_text_coordinates(S32 c, S32 x, S32 y, S32 width, S32 height);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_fixed_icontext_list_icon_coordinates
 * DESCRIPTION
 *  Set the coordinates of the specified icon column.
 * PARAMETERS
 *  c           : [IN]        Index of the icon column (zero based)
 *  x           : [IN]        Position of the icon column within the item
 *  y           : [IN]        Position of the icon column within the item
 *  width       : [IN]        Width of the icon column
 *  height      : [IN]        Height of the icon column
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_fixed_icontext_list_icon_coordinates(S32 c, S32 x, S32 y, S32 width, S32 height);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_icontext_list_list
 * DESCRIPTION
 *  Associate the list of fixed icontext list menu items with the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_icontext_list_list(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_icontext_list_matrix
 * DESCRIPTION
 *  Associate the list of fixed icontext list menu items with the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_icontext_list_matrix(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  add_fixed_icontext_list_item_text
 * DESCRIPTION
 *  Change the text in the specified column of an item.
 * PARAMETERS
 *  index       : [IN]        Item index
 *  c           : [IN]        Text column index (zero based)
 *  s           : [IN]        String to be displayed in this text column
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_icontext_list_item_text(S32 index, S32 c, UI_string_type s);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  add_fixed_icontext_list_item_icon
 * DESCRIPTION
 *  Change the icon in the specified column of an item.
 * PARAMETERS
 *  index       : [IN]        Item index
 *  c           : [IN]        Icon column index (zero based)
 *  img         : [IN]        Icon to be displayed in this icon column
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_icontext_list_item_icon(S32 index, S32 c, PU8 img);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  fixed_icontext_list_item_insert
 * DESCRIPTION
 *  Inserts a new item to the list of fixed icontext list menu items.
 * PARAMETERS
 *  index       : [IN]        Index at which a new item is inserted (zero based)
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_icontext_list_item_insert(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  remove_fixed_icontext_list_item
 * DESCRIPTION
 *  Removs an item at the specified index.
 * PARAMETERS
 *  index       : [IN]        Index of the item to be removed (zero based) 
 * RETURNS
 *  void
 *****************************************************************************/
extern void remove_fixed_icontext_list_item(S32 index);

/* DOM-NOT_FOR_SDK-END */

#ifdef __MMI_UI_HINTS_IN_MENUITEM__


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_enable_hints_in_icontext_menuitem
 * DESCRIPTION
 *  Enable hints for all menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_enable_hints_in_icontext_menuitem(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_enable_hint_highlight_in_icontext_menuitem
 * DESCRIPTION
 *  Enable hints for the highlighted menu item only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_enable_hint_highlight_in_icontext_menuitem(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_show_icon_only_highlight_in_icontext_menuitem
 * DESCRIPTION
 *  Shows icon only if the menu item is highlighted.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_show_icon_only_highlight_in_icontext_menuitem(void);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


/* 
 * fixed twostate menuitem 
 */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_twostate_menuitem_apply_current_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed twostate menu items.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_twostate_menuitem_apply_current_theme(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_theme>
 * FUNCTION
 *  fixed_twostate_menuitem_apply_theme
 * DESCRIPTION
 *  Apply the current theme to the fixed twostate menu items.
 * PARAMETERS
 *  t       : [IN]        Fixed two-state menu item theme     
 * RETURNS
 *  void
 *****************************************************************************/
extern void fixed_twostate_menuitem_apply_theme(UI_fixed_twostate_menuitem_theme *t);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  create_fixed_twostate_menuitems
 * DESCRIPTION
 *  Create a list of fixed two-state menu items.
 * PARAMETERS
 *  ON_icon         : [IN]        Common ON icon
 *  OFF_icon        : [IN]        Common OFF icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void create_fixed_twostate_menuitems(PU8 ON_icon, PU8 OFF_icon);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_twostate_menuitems
 * DESCRIPTION
 *  Resize all the fixed two-state menu items.
 * PARAMETERS
 *  width       : [IN]        New width of fixed twostate menuitems
 *  height      : [IN]        New height of fixed twostate menuitems
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_twostate_menuitems(S32 width, S32 height);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_twostate_list
 * DESCRIPTION
 *  Associate the list of fixed two-state menuitems with the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_twostate_list(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  associate_fixed_twostate_matrix
 * DESCRIPTION
 *  Associate the list of fixed twos-tate menu items with the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void associate_fixed_twostate_matrix(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  center_fixed_twostate_positions
 * DESCRIPTION
 *  Set center justification of text and icons within the fixed two-state menu items.
 * PARAMETERS
 *  tx      : [IN]        1: Center text horizontally, 0: normal
 *  ty      : [IN]        1: Center text vertically, 0: normal
 *  ix      : [IN]        1: Center icon horizontally, 0: normal
 *  iy      : [IN]        1: Center icon vertically, 0: normal
 * RETURNS
 *  void
 *****************************************************************************/
extern void center_fixed_twostate_positions(U8 tx, U8 ty, U8 ix, U8 iy);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_fixed_twostate_positions
 * DESCRIPTION
 *  Set the positions of text and icons within the fixed two-state menu items.
 * PARAMETERS
 *  tx      : [IN]        X position of text   (0: The text is centered horizontally.)
 *  ty      : [IN]        Y position of text   (0: The text is centered vertically.)
 *  ix      : [IN]        X position of icon   (0: The icon is centered horizontally.)
 *  iy      : [IN]        Y position of icon   (0: The icon is centered vertically.)
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_fixed_twostate_positions(S32 tx, S32 ty, S32 ix, S32 iy);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_fixed_twostate_icons
 * DESCRIPTION
 *  Change the icons to be used in fixed two-state menu items.
 * PARAMETERS
 *  ON_icon         : [IN]        Icon to be displayed when an item is selected
 *  OFF_icon        : [IN]        Icon to be displayed when the item is not selected
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_fixed_twostate_icons(PU8 ON_icon, PU8 OFF_icon);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_fixed_twostate_item
 * DESCRIPTION
 *  Adds an item to the list of fixed two-state menu items at the end.
 * PARAMETERS
 *  s       : [IN]        Item text
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_twostate_item(UI_string_type s);

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_location_fixed_twostate_item
 * DESCRIPTION
 *  Adds an item to the list of fixed two-state menu items at the specified index.
 * PARAMETERS
 *  index       : [IN]        Index at which the item is added (zero based)
 *  s           : [IN]        Item text
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_location_fixed_twostate_item(S32 index, UI_string_type s);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  remove_fixed_twostate_item
 * DESCRIPTION
 *  Remove an item at the specified location.
 * PARAMETERS
 *  index       : [IN]        Index at which the item is removed (zero based)
 * RETURNS
 *  void
 *****************************************************************************/
extern void remove_fixed_twostate_item(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  add_fixed_twostate_items
 * DESCRIPTION
 *  Add an array of items to the fixed two-state menu item list.
 * PARAMETERS
 *  n_items     : [IN]        Number of items
 *  s           : [IN]        An array of item text strings
 * RETURNS
 *  void
 *****************************************************************************/
extern void add_fixed_twostate_items(S32 n_items, UI_string_type *s);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  select_fixed_twostate_item
 * DESCRIPTION
 *  Select an item. Set the item to ON state.
 * PARAMETERS
 *  index       : [IN]        Index of the item to be selected
 * RETURNS
 *  void
 *****************************************************************************/
extern void select_fixed_twostate_item(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  unselect_fixed_twostate_item
 * DESCRIPTION
 *  Un-select an item. Set the item to OFF state.
 * PARAMETERS
 *  index       : [IN]        Index of the item to be selected
 * RETURNS
 *  void
 *****************************************************************************/
extern void unselect_fixed_twostate_item(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  toggle_fixed_twostate_item
 * DESCRIPTION
 *  Toggle the state of the specified item.
 * PARAMETERS
 *  index       : [IN]        Index of the item to be selected
 * RETURNS
 *  void
 *****************************************************************************/
extern void toggle_fixed_twostate_item(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  get_fixed_twostate_item_state
 * DESCRIPTION
 *  Get the state of the item at the given index.
 * PARAMETERS
 *  index       : [IN]        Item index
 * RETURNS
 *  Return 0 if the item is unselected and 1 if the item is selected.
 *****************************************************************************/
extern U8 get_fixed_twostate_item_state(S32 index);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  remove_all_fixed_icontext_item
 * DESCRIPTION
 *  Remove all items in fixed list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void remove_all_fixed_icontext_item(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
* <group dom_menu_wgui_layer_fixed_menu_item_misc>
* FUNCTION
*  get_item_text
* DESCRIPTION
*  Gets the text of the item at the given index in the currently displayed menu
* PARAMETERS
*  index       : [IN]         Index(zero based) of the item whose text needs to be retrieved
* RETURNS
*  a pointer to the text of the specified item
 *****************************************************************************/
extern UI_string_type get_item_text(S32 index);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_icontext_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed icontext menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_icontext_menuitems_to_list_width(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_text_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed text menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define resize_fixed_text_menuitems_to_list_width resize_fixed_icontext_menuitems_to_list_width

/*****************************************************************************
 * FUNCTION
 *  wgui_scrolling_text_draw_two_line_background
 * DESCRIPTION
 *  Draw the two line select text background.
 * PARAMETERS
 *  x1      [IN]        x1
 *  y1      [IN]        y1
 *  x2      [IN]        x2
 *  y2      [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/

#define wgui_scrolling_text_draw_two_line_background gui_show_two_line_background


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_icontext_list_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed icontext list menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_icontext_list_menuitems_to_list_width(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  resize_fixed_twostate_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the fixed two-state menu item to the maximum width.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_fixed_twostate_menuitems_to_list_width(void);

/* DOM-NOT_FOR_SDK-END */

#ifdef __MMI_UI_TRANSPARENT_EFFECT__


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  disable_fixed_icontext_menuitem_transparent_effect
 * DESCRIPTION
 *  Disable the transparent effect flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void disable_fixed_icontext_menuitem_transparent_effect(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  enable_fixed_icontext_menuitem_transparent_effect
 * DESCRIPTION
 *  Enable the transparent effect flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void enable_fixed_icontext_menuitem_transparent_effect(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  disable_fixed_icontext_list_menuitem_transparent_effect
 * DESCRIPTION
 *  Disable the transparent effect flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void disable_fixed_icontext_list_menuitem_transparent_effect(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  enable_fixed_icontext_menuitem_transparent_effect
 * DESCRIPTION
 *  Enable the transparent effect flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void enable_fixed_icontext_list_menuitem_transparent_effect(void);
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */  

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_two_line_get_thumbnail_flags
 * DESCRIPTION
 *  Get the thumbnail flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current thumbnail flag.
 *****************************************************************************/
extern U8 wgui_two_line_get_thumbnail_flags(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_two_line_toggle_thumbnail_direction
 * DESCRIPTION
 *  Toggle the thumbnail direction.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_two_line_toggle_thumbnail_direction(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_two_line_reset_all_pointers
 * DESCRIPTION
 *  Reset pointers related to two line function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_two_line_reset_all_pointers(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_set_pfn_to_get_current_menu_item_properties
 * DESCRIPTION
 *  Set the callback function to get current menu item property.
 * PARAMETERS
 *  pfn     : [IN]        Callback to get the two-line item property
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_set_pfn_to_get_current_menu_item_properties(wgui_get_two_line_menu_item_properties pfn);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_set_pfn_to_get_display_style
 * DESCRIPTION
 *  Set the callback function to get current menu item display style.
 * PARAMETERS
 *  pfn     : [IN]        Get display style callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_set_pfn_to_get_display_style(wgui_get_display_style pfn);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  reset_fixed_icontext_menuitem_type
 * DESCRIPTION
 *  Set default two-line menu item callback fucntions.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void reset_fixed_icontext_menuitem_type(void);

/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 

#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  wgui_two_line_stop_scroller
 * DESCRIPTION
 *  Stop the scrolling for the two-line.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_two_line_stop_scroller(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_two_line_disable_complete_callback
 * DESCRIPTION
 *  Disable two line remove highlight callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_two_line_disable_complete_callback(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_current_two_line_menuitem_data
 * DESCRIPTION
 *  Check if two line  horizontal select or level and sets the data for a particular
 *  menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_current_two_line_menuitem_data(void);

/* DOM-NOT_FOR_SDK-END */

#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 

#ifdef __MMI_UI_HINTS_IN_MENUITEM__

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  gui_show_two_line_hint_part
 * DESCRIPTION
 *  Show the two line hint.
 * PARAMETERS
 *  hint_x1         : [IN]        Start x position
 *  hint_x2         : [IN]        End x position
 *  hint_y1         : [IN]        Start x position
 *  hint_y2         : [IN]        End y position
 *  _hint_text      : [IN]        Hint text
 *  flags           : [IN]        Menu item flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_show_two_line_hint_part(
                S32 hint_x1,
                S32 hint_x2,
                S32 hint_y1,
                S32 hint_y2,
                UI_string_type _hint_text,
                U32 flags);

/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  wgui_initialise_and_set_two_line_horizontal_select_callbacks
 * DESCRIPTION
 *  Initialize the two line horizontal select.
 * PARAMETERS
 *  no_of_items                 : [IN]        Number of items
 *  get_data_callback           : [IN]        Get menu item callback
 *  default_value_callback      : [IN]        Callback to set default values
 *  complete_callback           : [IN]        Callback to remove highlight
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_initialise_and_set_two_line_horizontal_select_callbacks(
                S32 no_of_items,
                wgui_two_line_get_horizontal_select_data_callback get_data_callback,
                wgui_two_line_menuitem_get_default_callback default_value_callback,
                wgui_two_line_menuitem_complete_callback complete_callback);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_show_two_line_horizontal_select
 * DESCRIPTION
 *  Show the two line horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_show_two_line_horizontal_select(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_complete_two_line_horizontal_select
 * DESCRIPTION
 *  Remove highlight function of the two-line horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_complete_two_line_horizontal_select(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  wgui_two_line_horizontal_select_move_next_item
 * DESCRIPTION
 *  This is called when users presses right arraw key on horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_two_line_horizontal_select_move_next_item(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  wgui_two_line_horizontal_select_move_previous_item
 * DESCRIPTION
 *  This is called when users presses left arraw key on horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_two_line_horizontal_select_move_previous_item(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_misc>
 * FUNCTION
 *  wgui_move_and_set_keyhandlers_two_line_horizontal_select
 * DESCRIPTION
 *  Move the two line inline select and set its key handlers.
 * PARAMETERS
 *  x       : [IN]        New x position of inline horizontal select
 *  y       : [IN]        New y position of inline horizontal select
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_move_and_set_keyhandlers_two_line_horizontal_select(S32 x, S32 y);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_resize_two_line_horizontal_select
 * DESCRIPTION
 *  Resize the two line inline select menu item.
 * PARAMETERS
 *  width       : [IN]        New width of two line horizontal select
 *  height      : [IN]        New height of two line horizontal select
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_resize_two_line_horizontal_select(S32 width, S32 height);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  get_two_line_menuitem_height
 * DESCRIPTION
 *  Callback function to check if the the current item is two line.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 1 for two line; otherwise, 0 for single line.
 *****************************************************************************/
extern pBOOL get_two_line_menuitem_height(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_two_line_display_for_dynamic_menus
 * DESCRIPTION
 *  Set the callback to get display style in case of dynamic menus.
 * PARAMETERS
 *  callback        : [IN]        Get display style callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_two_line_display_for_dynamic_menus(two_line_dynamic_menuitem_style callback);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  get_two_line_dynamic_menuitem_height
 * DESCRIPTION
 *  Callback function to check if the the current item is two line for the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 1 for two line; otherwise, 0 for single line.
 *****************************************************************************/
extern pBOOL get_two_line_dynamic_menuitem_height(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  set_two_line_display_for_asyncdynamic_menus
 * DESCRIPTION
 *  Set the callback to get display style in case of asyncdynamic menus.
 * PARAMETERS
 *  callback        : [IN]        Get display style callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_two_line_display_for_asyncdynamic_menus(two_line_dynamic_menuitem_style callback);


/*****************************************************************************
 * <group dom_menu_wgui_layer_fixed_menu_item_property_setting>
 * FUNCTION
 *  get_two_line_asyncdynamic_menuitem_height
 * DESCRIPTION
 *  Callback function to check if the the current item is two line for the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 1 for two line; otherwise, 0 for single line.
 *****************************************************************************/
extern pBOOL get_two_line_asyncdynamic_menuitem_height(void);



/*****************************************************************************
 * <group dom_menu_gui_layer_fixed_menu_item_basic>
 * FUNCTION
 *  wgui_show_two_line_background
 * DESCRIPTION
 *  Show the two line background.
 * PARAMETERS
 *  x1       : [IN]   X coordinate of the top-left point
 *  y1       : [IN]   Y coordinate of the top-left point
 *  x2       : [IN]   X coordinate of the bottom-right point
 *  y2       : [IN]   Y coordinate of the bottom-right point
 * RETURNS
 *  void
 *****************************************************************************/
#define wgui_show_two_line_background(_arg1, _arg2, _arg3, _arg4) gui_show_two_line_background(_arg1, _arg2, _arg3, _arg4)

#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-BEGIN */
extern void wgui_two_line_translate_pen_event(S32 x, S32 y, mmi_pen_event_type_enum pen_event, gui_list_pen_enum *menuitem_event);
/* DOM-NOT_FOR_SDK-END */
#endif

/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 

#endif /* __WGUI_FIXED_MENUITEMS_H__ */ 


