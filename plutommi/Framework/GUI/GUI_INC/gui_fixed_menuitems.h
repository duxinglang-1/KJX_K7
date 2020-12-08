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
 *  gui_fixed_menuitems.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Menu items in fixed menu - UI component
 *
 *  [Text menu item]
 *  [Icontext menu item]
 *  [Icontext-list menu item]
 *  [Twostate menu item]
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_FIXED_MENUITEMS_H__
#define __GUI_FIXED_MENUITEMS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui.h"
#include "gui_typedef.h"
#include "gui_theme_struct.h"
#include "gui_fixed_menus.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustThemesRes.h"
#include "gui_data_types.h"
#include "gdi_datatype.h"
#include "mmi_frm_input_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/* <group dom_menu_macro>
 *  Highlight opacity factor value from 0 to 100 */
#ifdef __MMI_MAINLCD_96X64__
#define HIGHLIGHTER_COLOR_OPACITY_VALUE     100
#else
#define HIGHLIGHTER_COLOR_OPACITY_VALUE     85
#endif

/* <group dom_menu_macro>
 *  The time period of list transparent highlight effect */
#define LIST_TRANSPARENT_HIGHLIGHTER_TIMER  175
/* <group dom_menu_macro>
 *  The time period of list flash highlight effect */
#define LIST_FLASH_HIGHLIGHTER_TIMER        150
/* <group dom_menu_macro>
 *  The time period of list animation highlight effect */
#define LIST_ANIMATION_HIGHLIGHTER_TIMER    175
/* <group dom_menu_macro>
 *  The max opacity value */
#define MAX_OPACITY_VALUE_FACTOR            10
/* <group dom_menu_macro>
 *  The start opacity value */
#define TRANSPARENCY_START_OPACITY_VALUE    1
/* <group dom_menu_macro>
 *  The number of frames jumped one time, used in transparent and flash feeling highlight effects */
#define JUMP_IN_HIGHLIGHTERS_EFFECTS_FRAME  4

/* DOM-NOT_FOR_SDK-END */

/* 
 * base structure of the common menuitem 
 */

/* <group dom_menu_macro>
 * Base structure of the common menuitem
 *
 *   ---Dimensions of menu item---               
 *   S32 width, height;                          
 *   ---Falgs to indicate the state---          
 *   U32 flags;                                  
 *   ---Extension flags to indicate the state---
 *   U32 ext_flags;                                        
 *   ---X-coordinate of scroll text---           
 *   S32 scroll_x, scroll_width;                 
 *   ---Scroll width of scroll text---         
 *   S32 scroll_width;                           
 *   ---The width of the text---                
 *   S32 text_width;                                    
 *   ---Coordinates of text---                   
 *   S32 text_x, text_y;                         
 *   ---Coordinates of icon---                  
 *   S32 icon_x, icon_y;                                                                         
 *   ---Filler in unhighlighted state---        
 *   UI_filled_area *normal_filler;              
 *   ---Filler in disabled state---             
 *   UI_filled_area *disabled_filler;            
 *   ---Filler in selected state---             
 *   UI_filled_area *selected_filler;           
 *   ---Filler in focussed state---             
 *   UI_filled_area *focussed_filler;            
 *   ---Filler without scrollbar when focussed---
 *   UI_filled_area *focussed_without_sc_filler; 
 *   ---Text color of unhighlighted item---      
 *   color normal_text_color;                    
 *   ---Text color of disabled item---           
 *   color disabled_text_color;                  
 *   ---Text color of selected item---          
 *   color selected_text_color;                  
 *   ---Text color of focussed item---           
 *   color focussed_text_color;                  
 *   ---Font of text---                          
 *   UI_font_type text_font;                      
 *   ---Parent menu is list---                  
 *   fixed_list_menu *parent_list;               
 *   ---Parent menu is matrix---                 
 *   fixed_matrix_menu *parent_matrix;
 */ 
#define GUI_COMMON_MENUITEM_BASE_STRUCT         \
    S32 width, height;                          \
                                                \
    U32 flags;                                  \
    U32 ext_flags;                              \
                                                \
    /* text scrolling */                        \
    S32 scroll_x, scroll_width;                 \
    S32 text_width;                             \
                                                \
    /* menuitem coordinates */                  \
    S32 text_x, text_y;                         \
    S32 icon_x, icon_y;                         \
                                                \
    /* theme */                                 \
    UI_filled_area *normal_filler;              \
    UI_filled_area *disabled_filler;            \
    UI_filled_area *selected_filler;            \
    UI_filled_area *focussed_filler;            \
    UI_filled_area *focussed_without_sc_filler; \
    color normal_text_color;                    \
    color disabled_text_color;                  \
    color selected_text_color;                  \
    color focussed_text_color;                  \
    UI_font_type text_font;                     \
    void(*hide_function)(S32 x1, S32 y1, S32 x2, S32 y2);    \
                                                \
    /* parent menu */                           \
    fixed_list_menu *parent_list;               \
    fixed_matrix_menu *parent_matrix;

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* <group dom_menu_struct_fixed_menuitem>
 *   * Base structure of the common menuitem.
 * This structure contains a macro in it.
 * In order to get the whole picture of this structure , you should refer to GUI_COMMON_MENUITEM_BASE_STRUCT 
 *
 * The original structure declaration is as below :
 * typedef struct gui_common_menuitem_base_struct                                      
 * {                                       
 *      GUI_COMMON_MENUITEM_BASE_STRUCT
 *
 *	    ... 
 * } gui_common_menuitem_base_struct;                                              
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    GUI_COMMON_MENUITEM_BASE_STRUCT
    S32 checkbox_x, checkbox_y;                 
    checkbox_clicked_funcptr_type checkbox_clicked_callback;    
    checkbox_get_image_funcptr_type checkbox_get_image_callback;   
    /* DOM-NOT_FOR_SDK-END */
} gui_common_menuitem_base_struct;

//for slim
typedef struct _gui_common_menuitem
{
   GUI_COMMON_MENUITEM_BASE_STRUCT
}gui_common_menuitem;
typedef struct
{
    S32 head_item_index;
    S32 head;
    S32 tail;
    S32 count;
    S32 n_total_items;
}gui_dynamic_circle_buffer_common;



typedef struct _fixed_menuitem_type
{
    /* Flags to indicate the state */
    U32 flags;
    /* Extension flags to indicate the state */
    U32 ext_flags; 
} fixed_menuitem_type;
//end for slim
/* 
 * fixed icontext menuitem 
 */

/* <group dom_menu_struct_fixed_menuitem>
 *  Special structure of each icontext menuitem */
typedef struct _fixed_icontext_menuitem_type
{
    /* Flags to indicate the state */
    U32 flags;
    /* Extension flags to indicate the state */
    U32 ext_flags; 

	/* Icon of menu item */
    PU8 item_icon;
    /* Handle of icon */
    gdi_handle item_icon_handle;
    /* Text of menuitem */
    UI_string_type item_text;

    /* width of text */
    S32 text_width;
    /* height of text */
    S32 text_height;
    /* baseline of current text */
    S32 baseline;
} fixed_icontext_menuitem_type;

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_menu_struct_fixed_menuitem>
 *  Structure of checkbox */
typedef struct
{
    /* Coordinates of checkbox */
    S32     x, y;
    /* Image of checkboc */
    PU8     image;
    /* Dimensions of the image */
    S32     image_width, image_height;
} gui_menuitem_icontext_checkbox_struct;
/* DOM-NOT_FOR_SDK-END */

/* <group dom_menu_struct_fixed_menuitem>
 * Common date structure of fixed icontext menuitem.
 * This structure contains a macro in it.
 * In order to get the whole picture of this structure , you should refer to GUI_COMMON_MENUITEM_BASE_STRUCT 
 *
 * The original structure declaration is as below :
 * typedef struct _fixed_icontext_menuitem                                      
 * {                                       
 *      GUI_COMMON_MENUITEM_BASE_STRUCT
 *
 *	    ... 
 * } fixed_icontext_menuitem;                                              
 */
typedef struct _fixed_icontext_menuitem
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    GUI_COMMON_MENUITEM_BASE_STRUCT
    /* DOM-NOT_FOR_SDK-END */
    /* Coordinates of checkbox */
    S32 checkbox_x, checkbox_y;
    /* Callback function when checkboc is clicked */
    checkbox_clicked_funcptr_type checkbox_clicked_callback;
    /* Callback function to get the image to checkbox */
    checkbox_get_image_funcptr_type checkbox_get_image_callback;  
    /* Post display callback funciton */
    void (*post_display_function) (void *item, void *common_item_data, S32 x, S32 y);
} fixed_icontext_menuitem;


/* 
 * fixed text menuitem
 *
 * EQUIVALENT to icontext menuitem
 */

/* Common date structure of fixed text menuitem */
typedef fixed_icontext_menuitem fixed_text_menuitem;
/* Special structure of each text menuitem */
typedef fixed_icontext_menuitem_type fixed_text_menuitem_type;


/* <group dom_menu_struct_fixed_menuitem>
 *  Fixed icontext list menuitems */ 
typedef struct _fixed_icontext_list_menuitem_type
{
    /* Falgs to indicate the state */
    U32 flags;
    /* Extension flags to indicate the state */
    U32 ext_flags; 
    /* Icons of the icontext list menuitem */
    PU8 item_icons[FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS];
    /* Handles of the icons */
    gdi_handle item_icon_handles[FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS];
    /* Texts of the icontext list menuitem */
    UI_string_type item_texts[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];

} fixed_icontext_list_menuitem_type;

/* <group dom_menu_struct_fixed_menuitem>
 * Common structure of fixed icontext list menuitem 
 * This structure contains a macro in it.
 * In order to get the whole picture of this structure , you should refer to GUI_COMMON_MENUITEM_BASE_STRUCT 
 *
 * The original structure declaration is as below :
 * typedef struct _fixed_icontext_list_menuitem                                      
 * {                                       
 *      GUI_COMMON_MENUITEM_BASE_STRUCT
 *
 *	    ... 
 * } fixed_icontext_list_menuitem;                                              
 */
typedef struct _fixed_icontext_list_menuitem
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    GUI_COMMON_MENUITEM_BASE_STRUCT
    /* DOM-NOT_FOR_SDK-END */
    /* Coordinates of checkbox */
    S32 checkbox_x, checkbox_y;
    /* Callback function when checkboc is clicked */
    checkbox_clicked_funcptr_type checkbox_clicked_callback;
    /* Callback function to get the image to checkbox */
    checkbox_get_image_funcptr_type checkbox_get_image_callback;  
    /* Number of text columns */
    S32 n_text_columns;
    /* Number of icon columns */
    S32 n_icon_columns;    
    /* Coordinates of the texts */
    UI_object_coordinates text_coordinates[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    /* Coordinates of the icons */
    UI_object_coordinates icon_coordinates[FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS];
    /* Text colors of normal menuitem */
    color normal_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    /* Text colors of disabled menuitem */
    color disabled_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    /* Text colors of selected menuitem */
    color selected_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    /* Text colors of focussed menuitems */
    color focussed_text_colors[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];    
    /* Fonts of texts */
    UI_font_type text_fonts[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    /* Font of selected texts */
    UI_font_type selected_fonts[FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS];
    /* Post display callback funciton */
    void (*post_display_function) (void *item, void *common_item_data, S32 x, S32 y);
    /* Callback function for two-line highlight style menuitem in fmgr */
    void (*highlight_twoline_display_function) (void *item,S32 x1, S32 y1, S32 x2, S32 y2);
} fixed_icontext_list_menuitem;


/* <group dom_menu_struct_fixed_menuitem>
 *  Structure of fixed twostate menuitem  */ 
typedef struct _fixed_twostate_menuitem_type
{
     /* Flags to indicate the state of twostate menuitem */
    U32 flags;
	 /* Text of twostate menuitem */
    UI_string_type item_text;

} fixed_twostate_menuitem_type;

/* <group dom_menu_struct_fixed_menuitem>
 *  
 * Common structure of fixed twostate menuitem.
 * This structure contains a macro in it.
 * In order to get the whole picture of this structure , you should refer to GUI_COMMON_MENUITEM_BASE_STRUCT 
 *
 * The original structure declaration is as below :
 * typedef struct _fixed_twostate_menuitem                                      
 * {                                       
 *      GUI_COMMON_MENUITEM_BASE_STRUCT
 *
 *	    PU8 ON_icon;
 *      PU8 OFF_icon;  
 * } fixed_twostate_menuitem;                                              
 */
typedef struct _fixed_twostate_menuitem
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    GUI_COMMON_MENUITEM_BASE_STRUCT
    /* DOM-NOT_FOR_SDK-END */
    /* Icon when in on state */
    PU8 ON_icon;
    /* Icon when in off state */
    PU8 OFF_icon;
} fixed_twostate_menuitem;

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_menu_struct_fixed_menuitem>
 * 
 * miscellaneous
 */
typedef enum
{
    ICON_TEXT_ICON = 0,
    ICON_ICON_TEXT,
    TEXT_ICON_ICON
} CAT73DISPLAY;
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/* <group dom_menu_struct_fixed_menuitem>
 *  Structure of animation with background */
typedef struct
{
    /* Animation x and y coordinate */
    S32             x, y;    
    /* Animation */
    PU8             animation;         
    /* Animation background filler */
    UI_filled_area  *background_filler;    
    /* Old source layer */    
    gdi_handle      old_src_layer;
    /* Handle of the animation */
    gdi_handle      animation_handler;
    /* Image type */
    U16             image_type;
    
} gui_animation_with_background_struct;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* <group dom_menu_variables> */
extern UI_fixed_text_menuitem_theme             *current_fixed_text_menuitem_theme;
/* <group dom_menu_variables> */
extern UI_fixed_icontext_menuitem_theme         *current_fixed_icontext_menuitem_theme;
/* <group dom_menu_variables> */
extern UI_fixed_icontext_list_menuitem_theme    *current_fixed_icontext_list_menuitem_theme;
/* <group dom_menu_variables> */
extern UI_fixed_twostate_menuitem_theme         *current_fixed_twostate_menuitem_theme;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * fixed text menuitem  
 */

/* DOM-NOT_FOR_SDK-BEGIN */ 
extern void gui_set_fixed_text_menuitem_theme(fixed_text_menuitem *m, UI_fixed_text_menuitem_theme *t);
extern void gui_set_fixed_text_menuitem_current_theme(fixed_text_menuitem *m);
extern void gui_create_fixed_text_menuitem(fixed_text_menuitem *m, S32 width, S32 height);
extern void gui_fixed_text_menuitem_set_text_position(fixed_text_menuitem *m, S32 x, S32 y);
extern void gui_resize_fixed_text_menuitem(fixed_text_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_text_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_text_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_text_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_text_menuitem(void *item, void *common_item_data);
extern void gui_fixed_text_menuitem_stop_scroll(void);
#define gui_fixed_text_menuitem_start_scroll() gui_fixed_icontext_menuitem_start_scroll()
/* DOM-NOT_FOR_SDK-END */

/* 
 * fixed icontext menuitem  
 */
/* DOM-NOT_FOR_SDK-BEGIN */
extern void gui_set_fixed_icontext_menuitem_current_theme(fixed_icontext_menuitem *m);
extern void gui_set_fixed_icontext_menuitem_theme(fixed_icontext_menuitem *m, UI_fixed_icontext_menuitem_theme *t);
extern void gui_create_fixed_icontext_menuitem(fixed_icontext_menuitem *m, S32 width, S32 height);
extern void gui_menuitem_set_text_position(void *common_item_data, S32 x, S32 y);
extern gdi_handle gui_list_set_alpha_blending_layer_ex(U32 flags, MMI_BOOL ext);
extern void gui_list_reset_alpha_blending_layer(gdi_handle old_alpha_layer);
#define gui_fixed_icontext_menuitem_set_text_position(_arg1, _arg2, _arg3) gui_menuitem_set_text_position(_arg1, _arg2, _arg3)
extern void gui_fixed_icontext_menuitem_set_icon_position(fixed_icontext_menuitem *m, S32 x, S32 y);
extern void gui_resize_fixed_icontext_menuitem(fixed_icontext_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_icontext_menuitem(void *item, void *common_item_data, S32 x, S32 y);
#ifndef __MMI_UI_MENU_SLIM__
extern void gui_hide_fixed_icontext_menuitem(void *item, void *common_item_data, S32 x, S32 y);
#else
#define gui_hide_fixed_icontext_menuitem 0
#endif
extern void gui_measure_fixed_icontext_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_icontext_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_icontext_menuitem(void *item, void *common_item_data);
extern void gui_fixed_icontext_menuitem_start_scroll(void);
extern void gui_fixed_icontext_menuitem_stop_scroll(void);
extern void gui_get_fixed_icontext_menuitem_flag(void *item, void *common_item_data, S32 index, U32 *flags, U32 *flags_ext);
extern void gui_register_fixed_icontext_menuitem_hide_function(void *common_item_data, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
/* DOM-NOT_FOR_SDK-END */
#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
/* DOM-NOT_FOR_SDK-BEGIN */
extern void gui_show_two_line_icontext_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_two_line_scroller_stop(void);
/* DOM-NOT_FOR_SDK-END */
#endif /* (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__) */ 

#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-BEGIN */
extern BOOL gui_fixed_icontext_menuitem_translate_pen_event(
                void *item,
                void *common_item_data,
                S32 item_x,
                S32 item_y,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menuitem_event,
                gui_pen_event_param_struct *menuitem_param);

extern BOOL gui_fixed_icontext_list_menuitem_translate_pen_event(
                                                            void *item,
                                                            void *common_item_data,
                                                            S32 item_x,
                                                            S32 item_y,
                                                            mmi_pen_event_type_enum pen_event,
                                                            S16 x,
                                                            S16 y,
                                                            gui_list_pen_enum *menuitem_event,
                                                            gui_pen_event_param_struct *menuitem_param);
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_TOUCH_SCREEN__ */ 


/* 
 * fixed icontext list menuitem  
 */
/* DOM-NOT_FOR_SDK-BEGIN */
extern void gui_set_fixed_icontext_list_menuitem_current_theme(fixed_icontext_list_menuitem *m);
extern void gui_set_fixed_icontext_list_menuitem_theme(
                fixed_icontext_list_menuitem *m,
                UI_fixed_icontext_list_menuitem_theme *t);
extern void gui_create_fixed_icontext_list_menuitem(
                fixed_icontext_list_menuitem *m,
                S32 width,
                S32 height,
                S32 n_text_columns,
                S32 n_icon_columns);
void gui_fixed_icontext_menuitem_set_post_display(fixed_icontext_menuitem *m,
                                                  void (*post_display_function) (void *item, void *common_item_data, S32 x, S32 y));
void gui_fixed_icontext_list_menuitem_set_post_display(fixed_icontext_list_menuitem *m,
                                                       void (*post_display_function)(void *item, void *common_item_data, S32 x, S32 y));
extern void gui_fixed_icontext_list_menuitem_set_text_coordinates(
                fixed_icontext_list_menuitem *m,
                S32 text_column,
                S32 x,
                S32 y,
                S32 width,
                S32 height);
extern void gui_fixed_icontext_list_menuitem_set_icon_coordinates(
                fixed_icontext_list_menuitem *m,
                S32 icon_column,
                S32 x,
                S32 y,
                S32 width,
                S32 height);
extern void gui_resize_fixed_icontext_list_menuitem(fixed_icontext_list_menuitem *m, S32 width, S32 height);
extern void gui_show_fixed_icontext_list_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_icontext_list_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_icontext_list_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_icontext_list_menuitem(void *item, void *common_item_data);
extern void gui_fixed_icontext_list_menuitem_start_scroll(void);
extern void gui_fixed_icontext_list_menuitem_stop_scroll(void);
extern void gui_get_fixed_icontext_list_menuitem_flag(void *item, void *common_item_data, S32 index, U32 *flags, U32 *flags_ext);
/* DOM-NOT_FOR_SDK-END */

/* 
 * fixed twostate menuitem  
 */
/* DOM-NOT_FOR_SDK-BEGIN */
extern void gui_set_fixed_twostate_menuitem_current_theme(fixed_twostate_menuitem *m);
extern void gui_set_fixed_twostate_menuitem_theme(
                fixed_twostate_menuitem *m,
                UI_fixed_twostate_menuitem_theme *t);
extern void gui_create_fixed_twostate_menuitem(
                fixed_twostate_menuitem *m,
                S32 width,
                S32 height,
                PU8 ON_icon,
                PU8 OFF_icon);
extern void gui_fixed_twostate_menuitem_set_text_position(fixed_twostate_menuitem *m, S32 x, S32 y);
extern void gui_fixed_twostate_menuitem_set_icon_position(fixed_twostate_menuitem *m, S32 x, S32 y);
extern void gui_resize_fixed_twostate_menuitem(fixed_twostate_menuitem *m, S32 width, S32 height);
extern void gui_fixed_twostate_menuitem_set_icons(fixed_twostate_menuitem *m, PU8 ON_icon, PU8 OFF_icon);
extern void gui_show_fixed_twostate_menuitem(void *item, void *common_item_data, S32 x, S32 y);
extern void gui_measure_fixed_twostate_menuitem(void *item, void *common_item_data, S32 *width, S32 *height);
extern void gui_highlight_fixed_twostate_menuitem(void *item, void *common_item_data);
extern void gui_remove_highlight_fixed_twostate_menuitem(void *item, void *common_item_data);
extern void gui_fixed_twostate_menuitem_start_scroll(void);
extern void gui_fixed_twostate_menuitem_stop_scroll(void);
extern void gui_get_fixed_twostate_menuitem_flag(void *item, void *common_item_data, S32 index, U32* flags, U32* flags_ext);
/* DOM-NOT_FOR_SDK-END */
#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-BEGIN */
extern BOOL gui_fixed_twostate_menuitem_translate_pen_event(
                void *item,
                void *common_item_data,
                S32 item_x,
                S32 item_y,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menuitem_event,
                gui_pen_event_param_struct *menuitem_param);
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_UI_TRANSPARENT_EFFECT__
/* DOM-NOT_FOR_SDK-BEGIN */
extern void gui_block_transparency_effect(void);
extern void gui_unblock_transparency_effect(void);
extern void gui_fixed_icontext_enable_transparent_effect(void*common_item_data);//(fixed_icontext_menuitem *m);
extern void gui_fixed_icontext_disable_transparent_effect(void* common_item_data);//(fixed_icontext_menuitem *m);
#define gui_fixed_icontext_list_enable_transparent_effect(_arg1) gui_fixed_icontext_enable_transparent_effect(_arg1)
#define gui_fixed_icontext_list_disable_transparent_effect(_arg1) gui_fixed_icontext_disable_transparent_effect(_arg1)
#define gui_fixed_text_menuitem_enable_transparent_effect(_arg1) gui_fixed_icontext_enable_transparent_effect(_arg1)
#define gui_fixed_text_menuitem_disable_transparent_effect(_arg1) gui_fixed_icontext_disable_transparent_effect(_arg1)
#define gui_fixed_twostate_menuitem_enable_transparent_effect(_arg1) gui_fixed_icontext_enable_transparent_effect(_arg1)
#define gui_fixed_twostate_menuitem_disable_transparent_effect(_arg1) gui_fixed_icontext_disable_transparent_effect(_arg1)
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __MMI_UI_MENU_SLIM__
extern void gui_callback_highlighter_text_filler(void);
#else
#define gui_callback_highlighter_text_filler UI_dummy_function
#endif
/* DOM-NOT_FOR_SDK-END */
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* DOM-NOT_FOR_SDK-BEGIN */
extern S32 gui_list_effect_is_blocked(void);
extern void gui_stop_list_highlight_effect(void);
#ifdef  __MMI_UI_LIST_ANIMATE_HIGHLIGHT_EFFECTS__
extern void gui_draw_animated_highlight_filler(
                S32 Xstart_effect,
                S32 Ystart_effect,
                S32 Xend_effect,
                S32 Yend_effect,
                UI_filled_area *f);
#endif  /* __MMI_UI_LIST_ANIMATE_HIGHLIGHT_EFFECTS__ */
extern void gui_draw_transparent_color_filler(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
extern void gui_draw_flash_feeling_filler(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
extern void gui_reset_current_list_effect(void);
extern void gui_set_current_list_effect_to_default(void);
extern void gui_draw_list_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
#ifndef __MMI_UI_MENU_SLIM__
extern void gui_scroll_start_handler_for_list_effects(void);
#else
#define gui_scroll_start_handler_for_list_effects UI_dummy_function
#endif
extern S32 gui_get_current_list_effect(void);
extern void gui_dummy_scroll_handler_for_list_effects(void);
void gui_register_callback_menuitem_scroll(void (*f) (void));
extern void gui_unblock_list_effect(void);
extern void gui_block_list_effect(void);
extern void gui_draw_list_highlight_effect_last_frame(void);
extern void gui_set_current_list_effect(gui_list_effect_styles list_style);
extern void gui_restore_current_list_effect(void);
extern S32 is_draw_next_frame_list_highlight_effect_value(void);
extern void set_is_draw_next_frame_list_highlight_effect_value(MMI_BOOL draw_next_frame);
extern void set_start_position_parameter_for_list_highlighter_effect(S32 x, S32 y);
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

#ifndef __MMI_UI_MENU_SLIM__
extern void set_start_position_and_item_parameters_for_list_highlighter_effect(
                void *item,
                void *common_item_data,
                S32 x,
                S32 y);
#else
#define set_start_position_and_item_parameters_for_list_highlighter_effect(_arg1, _arg2, _arg3, _arg4) 
#endif
/* DOM-NOT_FOR_SDK-BEGIN */
extern void gui_block_list_animation_highlight(void);
extern void gui_unblock_list_animation_highlight(void);
/* DOM-NOT_FOR_SDK-END */

#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
/* DOM-NOT_FOR_SDK-BEGIN */
extern void (*gui_reset_current_two_line_menuitem_data)(void);

extern void UI_dummy_reset_current_two_line_menuitem_data(void);

extern void gui_show_two_line_background(S32 x1, S32 y1, S32 x2, S32 y2);
/* DOM-NOT_FOR_SDK-END */
#endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */
extern void gui_fixed_two_line_set_filler(UI_filled_area *filler, UI_filled_area *filler_without_sc);

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
/* DOM-NOT_FOR_SDK-BEGIN */
extern void (*gui_set_current_two_line_menuitem_data)(void);
extern void (*gui_show_two_line_menuitem_part)(void);
extern void (*gui_move_two_line_menuitem_part)(S32 x, S32 y);
extern void (*gui_resize_two_line_menuitem_part)(S32 x, S32 y);
extern pBOOL (*gui_get_two_line_menuitem_height)(void);
extern void (*gui_reset_two_line)(void);
extern void (*gui_two_line_toggle_thumbnail_direction)(void);
extern U8 (*gui_two_line_get_thumbnail_flags)(void);

extern void UI_dummy_show_two_line_menuitem_part(void);
extern pBOOL UI_dummy_get_two_line_menuitem_height(void);
extern void UI_dummy_set_current_two_line_menuitem_data(void);
extern void UI_dummy_move_two_line_menuitem_part(S32 x, S32 y);
extern void UI_dummy_resize_two_line_menuitem_part(S32 x, S32 y);
extern U8 UI_dummy_two_line_get_thumbnail_flags(void);
extern void two_line_menuitem_cleanup_function(void);
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


extern void UI_dummy_display_pop_up_description(S32 x, S32 y, S32 width, S32 height);
/* DOM-NOT_FOR_SDK-END */
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
/* DOM-NOT_FOR_SDK-BEGIN */

extern UI_string_type UI_dummy_get_current_pop_up_description_string(void);
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
/* DOM-NOT_FOR_SDK-BEGIN */
#define gui_menuitem_verify_image_highlight_dimension(_arg) 0

extern void gui_show_animation_with_background_image(S32 x, S32 y, PU8 animation, PU8 anim_bg_image, gdi_handle *animation_handle);
extern void gui_show_animation_with_background_filler(S32 x, S32 y, PU8 animation, UI_filled_area *background_filler, gdi_handle *animation_handle);    

extern void gui_get_fixed_text_length_menuitem(void *item, void *common_item_data, S32 *width);

#ifdef  __MMI_CAT203_SUPPORT__
extern GetUnderLineFuncPtr g_gui_list_get_underline;
#endif
extern UI_font_type g_gui_list_data_font;
extern S32          g_gui_list_data_gap;
extern color g_gui_list_text_color;


extern GetMenuitemFlags g_gui_list_get_menuitem_flags;
/* DOM-NOT_FOR_SDK-END */
#include "gui_menu_post_oem.h"

#endif /* __GUI_FIXED_MENUITEMS_H__ */ 


