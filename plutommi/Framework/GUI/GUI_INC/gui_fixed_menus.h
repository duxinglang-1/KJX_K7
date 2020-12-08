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
 *  gui_fixed_menus.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Fixed-list menu - UI component
 *  1. The number of menu items stays unchanged after the UI component is created.
 *  2. The storage of all menu item data is preallocated.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_FIXED_MENUS_H__
#define __GUI_FIXED_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_fixed_menus.h"
#include "MMI_features.h"
#include "wgui.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "gui.h"
#include "CustThemesRes.h"
#include "gui_scrollbars.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "wgui_touch_screen.h"
#include "gdi_include.h"
#include "gui_theme_struct.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/* displacement tolerated on tapping left/right arrows */
#define GUI_ABS(x)   ((x) < 0 ? -(x):(x))


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* <group dom_menu_enum>
 * fixed list
 */
typedef enum
{
    GUI_LIST_PEN_NONE,
    GUI_LIST_PEN_HIGHLIGHT_CHANGED,
    GUI_LIST_PEN_NEED_REDRAW,
    GUI_LIST_PEN_ITEM_SELECTED,
    /* Two-state menu item */
    GUI_TWOSTATE_PEN_TOGGLE,
    GUI_LIST_PEN_TWO_LINE_NEXT,
    GUI_LIST_PEN_TWO_LINE_PREVIOUS,
    GUI_LIST_PEN_CASCADING_OTHER,
    GUI_LIST_PEN_DOWN_ON_STATE_BOX
} gui_list_pen_enum;

#ifdef __MMI_UI_LIST_GRID_LINE__
/* <group dom_menu_enum> */
typedef enum
{
    GUI_LIST_KEY_INFO_NONE,
    GUI_LIST_KEY_INFO_UP,
    GUI_LIST_KEY_INFO_DOWN
} gui_list_key_info_enum;
#endif /* __MMI_UI_LIST_GRID_LINE__ */
/* <group dom_menu_struct> */
typedef struct
{
    S8 pen_on_scrollbar;
    /* pen events are handled by menu item directly */
    S8 handled_by_menu_item;
    /* highlighted item is changed between Pen Down and Pen Up */
    S8 highlight_changed;
    /* pen down on the check box or radio button */
    S8 pen_down_state_box;
    /* highlighted item on pen down */
    S32 first_highlighed_item;
} gui_list_pen_state_struct;

#ifdef __MMI_TOUCH_SCREEN__
typedef BOOL (*fixed_menuitem_pen_hdlr)(void *item, void *common_item_data, S32 item_x, S32 item_y,
                                        mmi_pen_event_type_enum pen_event, S16 x, S16 y,
                                        gui_list_pen_enum *menuitem_event,
                                        gui_pen_event_param_struct *menuitem_param);
#endif /* __MMI_TOUCH_SCREEN__ */

/* <group dom_menu_struct> */
typedef struct _fixed_list_menu
{
    S32 x, y;
    S32 width, height;
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    UI_filled_area *focussed_without_sc_filler;
	U32 flags;
	void **items;
    S32 highlighted_item;
	S32 n_items;
	void *common_item_data;
	void (*item_remove_highlight_function)(void *item, void *common_item_data);
	void (*item_highlight_function)(void *item, void *common_item_data);
	void (*item_highlighted)(S32 i);
	void (*item_unhighlighted)(S32 i);
	void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height);
	void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y);
	void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y);
	void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32* flag, U32* flag_ext);
#ifdef __MMI_TOUCH_SCREEN__ 
	void (*pen_event_current_selected_callback_function)(void);
	void (*pen_event_default_selected_callback_function)(void);
	/* Configured in associate_fixed_xxx_ */
	void (*tap_callback_funtion)(mmi_tap_type_enum tap_type, S32 index);
	/* Delay time when moving scroll bar button */
	S32 pen_scroll_delay_time;	
	S32 pen_scroll_after_delay; 
#endif	
    S32 first_displayed_item;
    S32 last_displayed_item;
    S32 current_displayed_item;
    S32 displayed_items;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    S32 first_displayed_offset;
    S32 last_displayed_offset;
#endif

    S32 spacing, top;
    S32 highlight_x;
    S32 highlight_y;
    S32 show_loading_index;
    S32 default_inline_item;
    vertical_scrollbar vbar;
    void (*item_displayed_callback)(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);
    void (*gui_display_pop_up_description) (S32 x, S32 y, S32 width, S32 height);
    UI_string_type (*gui_get_current_pop_up_description_string)(void);
    /* add for inline indicator */
    void (*item_indicator_display_callback)(S32 index, S32 x, S32 y);
    void (*item_resize_function)(S32 x, S32 y);
    void (*item_get_length_function)(void *item, void *common_item_data, S32 *width);

    void (*pre_display_function)(void);

    gdi_handle alpha_blend_layer_handle;
    gdi_handle act_layer_handle;
    gdi_handle act_lcd_handle;
    MMI_BOOL resized_before_locate;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL disable_move_highlight;
    MMI_BOOL disable_up_select;
    /* Runtime data */
    gui_list_pen_state_struct pen_state;
    /* Configured in pen handler */
    void (*pen_redraw_menu_function) (void);
    /* Configured in gui_set_fixed_list_menu_item_pen_function() */
    fixed_menuitem_pen_hdlr item_pen_function;
#ifdef __MMI_UI_LIST_GRID_LINE__
    gui_list_key_info_enum key_info;
#endif /* __MMI_UI_LIST_GRID_LINE__ */
#endif /* __MMI_TOUCH_SCREEN__ */ 
    gui_menu_type_enum menu_style;
#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
    MMI_BOOL (*item_pen_check_bound_function)(void *item, void *common_item_data, S32 index, S16 x, S16 y);
    S32 (*item_get_height_function)(S32 index);
#endif
    void (*menu_goto_function)(struct _fixed_list_menu *m, S32 i);
    void (*menu_goto_next_function)(struct _fixed_list_menu *m);
    void (*menu_goto_previous_function)(struct _fixed_list_menu *m);
} fixed_list_menu;                                        


/* <group dom_menu_enum>
 * 
 * fixed matrix
 */
typedef enum
{
    GUI_MATRIX_PEN_NONE,
    GUI_MATRIX_PEN_HIGHLIGHT_CHANGED,
    GUI_MATRIX_PEN_NEED_REDRAW,
    GUI_MATRIX_PEN_ITEM_SELECTED
} gui_matrix_pen_enum;

typedef enum{
    GUI_ASYNC_ITEM = 1000000,
	GUI_ASYNC_NEXT_ITEM,
	GUI_ASYNC_NEXT_ROW,
	GUI_ASYNC_PREV_ITEM,
	GUI_ASYNC_PREV_ROW,
	GUI_ASYNC_HILITED,//highlighted 
	GUI_FIXED_HILITED,
	GUI_FIXED_PREV_ROW,
	GUI_FIXED_NEXT_ROW,
	GUI_ASYNC_END
}gui_matrix_goto_type;
typedef enum{
   GUI_FIXED_LIST_ITEM = 1000000,
   GUI_FIXED_LIST_NEXT_ITEM,
   GUI_FIXED_LIST_PREV_ITEM,
   GUI_FIXED_LIST_SPECIFIC_ITEM,
   
   GUI_LIST_GOTO_END

}gui_list_goto_type;
typedef enum{
   GUI_SHOW_FIXED_MENU =1000000,
   GUI_SHOW_ASYNC_MENU,
   GUI_SHOW_ASYNC_SPECIAL,
   GUI_SHOW_END   
}gui_menu_show_type;
/* <group dom_menu_struct> */
typedef struct
{
    S8 pen_on_horizontal_scrollbar;
    S8 pen_on_vertical_scrollbar;
    /* highlighted item is changed between Pen Down and Pen Up */
    S8 highlight_changed;
    /* highlighted item on pen down */
    S32 first_highlighed_item;
} gui_matrix_pen_state_struct;

/* <group dom_menu_struct> */
typedef struct
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
    U8 *string;
    U16 img_id;
} gui_matrix_ind_area_struct;

/* <group dom_menu_struct> */
typedef struct _fixed_matrix_menu
{
    S32 x, y;
	S32 width, height;
    UI_filled_area *normal_filler;
    UI_filled_area *focussed_filler;
    UI_filled_area *focussed_without_sc_filler;
    U32 flags;
	void **items;
    S32 highlighted_item;   //1500
    S32 n_items;    //800
	void *common_item_data;
	void (*item_remove_highlight_function)(void *item, void *common_item_data);
	void (*item_highlight_function)(void *item, void *common_item_data);
	void (*item_highlighted)(S32 i);
	void (*item_unhighlighted)(S32 i);
	void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height);
	void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y);
	void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y);
	void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32* flag, U32* flag_ext);
#ifdef __MMI_TOUCH_SCREEN__ 
	void (*pen_event_current_selected_callback_function)(void);
	void (*pen_event_default_selected_callback_function)(void);
	/* Configured in associate_fixed_xxx_ */
	void (*tap_callback_funtion)(mmi_tap_type_enum tap_type, S32 index);
	/* Delay time when moving scroll bar button */
	S32 pen_scroll_delay_time;	
	S32 pen_scroll_after_delay; 
#endif	
    S32 n_columns;  //160
    S32 n_rows; //110
    S32 first_displayed_row;    // 240
    S32 first_displayed_column; //140
    S32 displayed_rows; //160
    S32 displayed_columns;  //120
    S32 highlighted_row;    //165
    S32 highlighted_column; //135
    S32 item_width; //120
    S32 item_height;//120
    S32 last_highlighted_item;  //115
    S32 highlighted_item_width; //17
    S32 highlighted_item_height;    //17
    S32 current_display_item;
    S32 last_hilited_x; //5
    S32 last_hilited_y; //5
    vertical_scrollbar vbar;    //69
    horizontal_scrollbar hbar;//69
    /* When row number < 0 && UI_MATRIX_MENU_VERTICAL_TRIGGER */
    void (*trigger_top_function) (void);
    /* When row number > max  && UI_MATRIX_MENU_VERTICAL_TRIGGER */
    void (*trigger_bottom_function) (void);
    S32 cache_bmp_x1;//14
    S32 cache_bmp_x2;
    S32 cache_bmp_y1;
    S32 cache_bmp_y2;
    gdi_image_cache_bmp_struct buffer;
#ifdef __MMI_TOUCH_SCREEN__
    /* Runtime data */
    gui_matrix_pen_state_struct pen_state;  //100
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    gui_matrix_ind_area_struct up_ind_area;
    gui_matrix_ind_area_struct down_ind_area;
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
    MMI_BOOL disable_scaling;
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */  
} fixed_matrix_menu;

typedef struct _fixed_menu
{
    S32 x, y;
	S32 width, height;
	UI_filled_area *normal_filler;
	UI_filled_area *focussed_filler;
	UI_filled_area *focussed_without_sc_filler;
	U32 flags;
	void **items;
    S32 highlighted_item;
	S32 n_items;
	void *common_item_data;
	void (*item_remove_highlight_function)(void *item, void *common_item_data);
	void (*item_highlight_function)(void *item, void *common_item_data);
	void (*item_highlighted)(S32 i);
	void (*item_unhighlighted)(S32 i);
	void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height);
	void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y);
	void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y);
	void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32* flag, U32* flag_ext);
#ifdef __MMI_TOUCH_SCREEN__ 
	void (*pen_event_current_selected_callback_function)(void);
	void (*pen_event_default_selected_callback_function)(void);
	/* Configured in associate_fixed_xxx_ */
	void (*tap_callback_funtion)(mmi_tap_type_enum tap_type, S32 index);
	/* Delay time when moving scroll bar button */
	S32 pen_scroll_delay_time;	
	S32 pen_scroll_after_delay; 
#endif			
}fixed_menu;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* <group dom_menu_variables> */
extern UI_fixed_list_menu_theme *current_fixed_list_menu_theme;
/* <group dom_menu_variables> */
extern UI_fixed_matrix_menu_theme *current_fixed_matrix_menu_theme;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * fixed list menu
 */
extern void gui_show_list_menu_background_outside_area(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_set_fixed_list_menu_current_theme(fixed_list_menu *m);
extern void gui_set_fixed_list_menu_theme(fixed_list_menu *m, UI_fixed_list_menu_theme *t);
extern void gui_create_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y, S32 width, S32 height);
extern void gui_resize_fixed_list_menu(fixed_list_menu *m, S32 width, S32 height);
extern void gui_move_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y);
extern void gui_fixed_list_menu_locate_highlighted_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_item(fixed_list_menu *m, S32 i);
extern void gui_fixed_list_menu_goto_next_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_previous_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_next_page(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_previous_page(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_first_item(fixed_list_menu *m);
extern void gui_fixed_list_menu_goto_last_item(fixed_list_menu *m);
extern void gui_show_fixed_list_menu(fixed_list_menu *m);
extern void gui_show_fixed_list_menu_specified_item(fixed_list_menu *m, S32 item_index);
extern void gui_hide_fixed_list_menu_highlighted_item(fixed_list_menu *m);
extern void gui_set_fixed_list_menu_item_functions(
        fixed_list_menu *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_resize_function) (S32 x, S32 y),
        void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32 *flags, U32 *flags_ext),
        void (*item_get_length_function)(void *item, void *common_item_data, S32 *width));
#ifndef __MMI_UI_MENU_SLIM__
extern void gui_set_fixed_list_menu_common_item_data(fixed_list_menu *m, void *c);
#else
 #define gui_set_fixed_list_menu_common_item_data(_arg1, _arg2)
#endif
extern void gui_show_fixed_list_menu_no_draw(fixed_list_menu *m);

/* common fuctions for fixed/dynamic/asyncdynamic menu */
extern void gui_list_menu_locate_highlighted_item(fixed_list_menu *m);
extern U8 gui_list_menu_locate_item_compute_first(fixed_list_menu *m);
extern void gui_list_menu_goto_item(fixed_list_menu *m, S32 i);
extern void gui_list_menu_goto_next_item(fixed_list_menu *m);
extern void gui_list_menu_goto_previous_item(fixed_list_menu *m);
extern MMI_BOOL gui_show_list_menu_check_scrollbar(fixed_list_menu *m);
extern void gui_show_list_menu_config_item_region(fixed_list_menu *m, S32 *x1, S32 *x2, S32 *y1, MMI_BOOL show_scrollbar);
extern void gui_show_list_menu_scrollbar(fixed_list_menu *m, U8 disable_draw);
extern void gui_show_list_menu_no_draw(fixed_list_menu *m);

#ifdef __MMI_TOUCH_SCREEN__
extern void gui_fixed_list_menu_set_pen_scroll_delay(fixed_list_menu *m, S32 delay_time);
extern void gui_set_fixed_list_menu_item_pen_function(
                fixed_list_menu *m,
                fixed_menuitem_pen_hdlr item_pen_function,
                MMI_BOOL disable_move_highlight,
                MMI_BOOL disable_up_select);
extern BOOL gui_fixed_list_menu_translate_pen_event(
                fixed_list_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menu_event);
extern MMI_BOOL gui_fixed_list_menu_translate_pen_position(fixed_list_menu *m, S32 y, S32 *item_index);
#endif /* __MMI_TOUCH_SCREEN__ */


/*
 * fixed matrix menu
 */
extern void gui_set_fixed_matrix_menu_current_theme(fixed_matrix_menu *m);
extern void gui_set_fixed_matrix_menu_theme(fixed_matrix_menu *m, UI_fixed_matrix_menu_theme *t);
extern void gui_create_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y, S32 width, S32 height);
extern void gui_fixed_matrix_menu_setup(
                fixed_matrix_menu *m,
                S32 item_width,
                S32 item_height,
                S32 n_columns,
                S32 n_rows);
extern void gui_resize_fixed_matrix_menu(fixed_matrix_menu *m, S32 width, S32 height);
extern void gui_move_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y);
extern void gui_fixed_matrix_menu_locate_highlighted_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_row(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_row(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_column(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_column(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_first_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_last_item(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_next_page(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_previous_page(fixed_matrix_menu *m);
extern void gui_fixed_matrix_menu_goto_item(fixed_matrix_menu *m, S32 i);

extern void mtk_UI_show_fixed_matrix_menu(fixed_matrix_menu *m);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL gui_fixed_matrix_menu_translate_pen_event(
                fixed_matrix_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_matrix_pen_enum *menu_event);
#endif /* __MMI_TOUCH_SCREEN__ */

extern void gui_show_fixed_matrix_menu(fixed_matrix_menu *m);
#ifndef __MMI_UI_MENU_SLIM__
extern void gui_hide_fixed_matrix_menu_highlighted_item(fixed_matrix_menu *m);
#else
#define gui_hide_fixed_matrix_menu_highlighted_item(_arg) 
#endif
extern void gui_set_fixed_matrix_menu_item_functions(fixed_matrix_menu *m,
                                                     void (*item_display_function)(void *item, void *common_item_data, S32 x, S32 y),
                                                     void (*item_measure_function)(void *item, void *common_item_data, S32 *width, S32 *height),
                                                     void (*item_highlight_function)(void *item, void *common_item_data),
                                                     void (*item_remove_highlight_function)(void *item, void *common_item_data),
                                                     void (*item_hide_function)(void *item, void *common_item_data, S32 x, S32 y),
                                                     void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32* flag, U32* flag_ext));
extern void gui_set_fixed_matrix_menu_common_item_data(fixed_matrix_menu *m, void *c);

extern void gui_reset_fixed_matrix_col_rows(fixed_matrix_menu *m);
extern S32 gui_fixed_matrix_auto_disable_scrollbar(fixed_matrix_menu *m);
extern void gui_matrix_menu_goto_row_x(fixed_matrix_menu *m, S32 goto_type);

extern void gui_matrix_menu_show_vscrollbar(void* common_item_data);
extern void gui_matrix_menu_show_hscrollbar(void* common_item_data);

/* dummy functions used by fixed menus */
extern void UI_fixed_menuitem_dummy_display_function(void *item, void *common_item_data, S32 x, S32 y);
extern void UI_fixed_menuitem_dummy_hide_function(void *item, void *common_item_data, S32 x, S32 y);
extern void UI_fixed_menuitem_dummy_measure_function(void *item, void *common_item_data, S32 *width, S32 *height);
extern void UI_fixed_menuitem_dummy_highlight_function(void *item, void *common_item_data);
extern void UI_fixed_menuitem_dummy_remove_highlight_function(void *item, void *common_item_data);
extern void UI_fixed_menuitem_dummy_resize_function(S32 x, S32 y);
extern void UI_fixed_menuitem_dummy_get_length_function(void *item, void *common_item_data, S32 *width);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL UI_fixed_menuitem_dummy_pen_function(
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


extern void (*g_gui_list_hide_menu) (S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_auto_resize_fixed_list_menu(fixed_list_menu *m, S32 max_width, S32 max_height);

#endif /* __GUI_FIXED_MENUS_H__ */ 


