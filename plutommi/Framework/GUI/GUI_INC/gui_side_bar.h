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
 *  gui_side_bar.h
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

#ifndef __GUI_SIDE_BAR_H__
#define __GUI_SIDE_BAR_H__

#include "MMI_features.h"

#ifdef __MMI_OP11_SIDEBAR__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "CustThemesRes.h"
#include "gui_theme_struct.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"

#define GUI_SIDE_BAR_INDICATOR_MAX          10
#define GUI_SIDE_BAR_MAX_MENU               10
#define GUI_SIDE_BAR_POPOUT_MENU_TIMER                  50
#define GUI_SIDE_BAR_POPOUT_MENU_TRANSITION_TIMES       3

#if defined(__MMI_MAINLCD_240X320__)
#define GUI_SIDE_BAR_TOP_BOTTOM_GAP         3
#define GUI_SIDE_BAR_AROUND_GAP             3
#define GUI_SIDE_BAR_ICON_SIZE              28
#define GUI_SIDE_BAR_BAR_WIDTH              34
#define GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER   2

#define GUI_SIDE_BAR_POPOUT_MENU_AROUND_GAP             2
#define GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y           0
#define GUI_SIDE_BAR_POPOUT_MENUITEM_HEIGHT             28
#define GUI_SIDE_BAR_POPOUT_MENUITEM_GAP                1
#define GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT             2
#define GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH    5
#define GUI_SIDE_BAR_POPOUT_MENU_GAP                    2
#define GUI_SIDE_BAR_PUPOUT_MENU_DATA_FONT              (&MMI_small_font)  

#define GUI_SIDE_BAR_INDICATOR_BORDER_GAP       3
#define GUI_SIDE_BAR_INDICATOR_GAP              1
#define GUI_SIDE_BAR_INDICATOR_SIZE             22
#define GUI_SIDE_BAR_INDICATOR_HINT_SIZE        19
#define GUI_SIDE_BAR_INDICATOR_HINT_BORDER      1
#define GUI_SIDE_BAR_INDICATOR_HINT_MAX_LENGTH  16
#elif defined(__MMI_MAINLCD_176X220__)
#define GUI_SIDE_BAR_TOP_BOTTOM_GAP         3
#define GUI_SIDE_BAR_AROUND_GAP             3
#define GUI_SIDE_BAR_ICON_SIZE              25
#define GUI_SIDE_BAR_BAR_WIDTH              31
#define GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER   1

#define GUI_SIDE_BAR_POPOUT_MENU_AROUND_GAP             1
#define GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y           2
#define GUI_SIDE_BAR_POPOUT_MENUITEM_HEIGHT             22
#define GUI_SIDE_BAR_POPOUT_MENUITEM_GAP                2
#define GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT             2
#define GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH    3
#define GUI_SIDE_BAR_POPOUT_MENU_GAP                    1
#define GUI_SIDE_BAR_PUPOUT_MENU_DATA_FONT              (&MMI_small_font)  

#define GUI_SIDE_BAR_INDICATOR_BORDER_GAP       2
#define GUI_SIDE_BAR_INDICATOR_GAP              1
#define GUI_SIDE_BAR_INDICATOR_SIZE             18
#define GUI_SIDE_BAR_INDICATOR_HINT_SIZE        18
#define GUI_SIDE_BAR_INDICATOR_HINT_BORDER      1
#define GUI_SIDE_BAR_INDICATOR_HINT_MAX_LENGTH  16
#else
#define GUI_SIDE_BAR_TOP_BOTTOM_GAP         3
#define GUI_SIDE_BAR_AROUND_GAP             3
#define GUI_SIDE_BAR_ICON_SIZE              28
#define GUI_SIDE_BAR_BAR_WIDTH              34
#define GUI_SIDE_BAR_HIGHLIGHT_BAR_BORDER   2

#define GUI_SIDE_BAR_POPOUT_MENU_AROUND_GAP             2
#define GUI_SIDE_BAR_POPOUT_MENUITEM_OFFSET_Y           0
#define GUI_SIDE_BAR_POPOUT_MENUITEM_HEIGHT             28
#define GUI_SIDE_BAR_POPOUT_MENUITEM_GAP                1
#define GUI_SIDE_BAR_POPOUT_MENU_HOR_INDENT             2
#define GUI_SIDE_BAR_POPOUT_MENU_SHADOW_BORDER_WIDTH    5
#define GUI_SIDE_BAR_POPOUT_MENU_GAP                    2
#define GUI_SIDE_BAR_PUPOUT_MENU_DATA_FONT              (&MMI_small_font)  

#define GUI_SIDE_BAR_INDICATOR_BORDER_GAP       3
#define GUI_SIDE_BAR_INDICATOR_GAP              1
#define GUI_SIDE_BAR_INDICATOR_SIZE             22
#define GUI_SIDE_BAR_INDICATOR_HINT_SIZE        19
#define GUI_SIDE_BAR_INDICATOR_HINT_BORDER      1
#define GUI_SIDE_BAR_INDICATOR_HINT_MAX_LENGTH  16
#endif

typedef void (*wgui_sidebar_getmenudata_funcptr_type)(S32 *number_of_items,
                                        PU8 *list_of_items,
                                        S32 *time_menuitem_index,
                                        MMI_BOOL *flags_is_data, S32 max_number);

typedef void (*wgui_sidebar_getindicator_funcptr_type)(S32 *number_of_indicators, 
                                        PU8 *icon_of_indicators, 
                                        S32 *data_of_indicators,
                                        FuncPtr *pen_excute_hanlder, S32 max_number);

typedef void (*wgui_sidebar_popout_menu_highlighthandler_funcptr_type)(S32 item_index);

typedef void (*wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type)(S32 item_index);


typedef enum
{
    MMI_GUI_SIDE_BAR_STATE_INACTIVE,
    MMI_GUI_SIDE_BAR_STATE_ACTIVE_NO_POPUP,
    MMI_GUI_SIDE_BAR_STATE_ACTIVE,
    MMI_GUI_SIDE_BAR_STATE_ACTIVE_POPUP,
    MMI_GUI_SIDE_BAR_STATE_TOTAL
} mmi_gui_side_bar_state_enum;

typedef enum
{
    MMI_GUI_SIDE_BAR_PEN_ON_V_BAR,
    MMI_GUI_SIDE_BAR_PEN_ON_INDICATOR,
    MMI_GUI_SIDE_BAR_PEN_ON_POPUP_MENU,
    MMI_GUI_SIDE_BAR_PEN_OUT_OF_SIDE_BAR,
    MMI_GUI_SIDE_BAR_PEN_TOTAL
} mmi_gui_side_bar_pen_state_enum;

typedef struct
{
    PU8 icon_normal;
    PU8 icon_highlight;

    S32 indicator_number;
    PU8 icon_of_indicators[GUI_SIDE_BAR_INDICATOR_MAX];
    S32 data_of_indicators[GUI_SIDE_BAR_INDICATOR_MAX];
    FuncPtr pen_excute_hanlder[GUI_SIDE_BAR_INDICATOR_MAX];
    MMI_BOOL pen_on_indicator[GUI_SIDE_BAR_INDICATOR_MAX];
    wgui_sidebar_popout_menu_highlighthandler_funcptr_type menu_highlight_handler;
    wgui_sidebar_getindicator_funcptr_type get_indicators_callback;
    
    S32 number_of_popout_menu_items;
    PU8 list_of_items[MAX_SUB_MENUS];
    S32 time_menuitem_index;
    MMI_BOOL flags_is_data[MAX_SUB_MENUS];
    wgui_sidebar_getmenudata_funcptr_type get_menu_data_callback;
    S32 popout_menu_item_width;
    S32 popout_menu_item_height;

    MMI_BOOL reach_bottom, reach_top;

} gui_side_bar_menu_struct;


typedef struct
{
    S32 x;
    S32 y;
    S32 side_bar_max_width;
    S32 side_bar_max_height;
    S32 bar_x;
    S32 bar_y;
    S32 bar_width;
    S32 bar_height;
    
    mmi_gui_side_bar_state_enum state; 
    
    GDI_HANDLE side_bar_layer;
    GDI_HANDLE popout_menu_layer;
    GDI_HANDLE wallpaper_layer;
    
    S32 side_bar_menu_number;
    S32 side_bar_highlighted_menu;
    gui_side_bar_menu_struct side_bar_menu[GUI_SIDE_BAR_MAX_MENU];

    FuncPtr AppLeftRightKeyHandler[2][MAX_KEY_TYPE];

    
    UI_filled_area *bar_bg;
    UI_filled_area *bar_menu_highlight_bg;
    UI_filled_area *popout_menu_highlight_bg;
    UI_filled_area *popout_menu_top_bg;
    UI_filled_area *popout_menu_middle_bg;
    UI_filled_area *popout_menu_bottom_bg;        

    wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type side_bar_highlight_handler;
    S32 current_popout_menu_highlight_index;
    S32 current_popup_menu_first_display_item;
    S32 current_popup_menu_last_display_item;
} gui_side_bar_struct;

extern UI_side_bar_theme * current_side_bar_theme;

extern void gui_side_bar_set_current_theme(gui_side_bar_struct *s);
extern void gui_side_bar_set_theme(gui_side_bar_struct *s, UI_side_bar_theme *t);
extern void gui_side_bar_create(
            gui_side_bar_struct *s,
            S32 x, S32 y,
            S32 max_width,S32 max_height,
            GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer,
            S32 number_of_side_bar_menu, 
            PU8 *icons_of_side_bar_menu_normal, PU8 *icons_of_side_bar_menu_highlight,
            wgui_sidebar_getindicator_funcptr_type *get_indicators_callback, 
            wgui_sidebar_getmenudata_funcptr_type *get_menu_data_callback,
            wgui_sidebar_popout_menu_highlighthandler_funcptr_type *menu_highlight_handler
            );
            
extern void gui_side_bar_show(gui_side_bar_struct *s);
extern void gui_side_bar_close(gui_side_bar_struct *s);
extern void gui_side_bar_update_indicators(gui_side_bar_struct *s, S32 side_bar_menu_index);
extern void gui_side_bar_register_left_arrow_key_handler(gui_side_bar_struct *s, FuncPtr funcPtr, U16 keyType);
extern void gui_side_bar_register_right_arrow_key_handler(gui_side_bar_struct *s, FuncPtr funcPtr, U16 keyType);
extern void gui_side_bar_redraw_bar(gui_side_bar_struct *s);
extern void gui_side_bar_redraw_popout_menu(gui_side_bar_struct *s);
extern void gui_side_bar_redraw_indicators(gui_side_bar_struct *s);

extern void gui_side_bar_move(gui_side_bar_struct *s, S32 x, S32 y);
extern void gui_side_bar_resize(gui_side_bar_struct *s, S32 max_width, S32 max_height);
extern void gui_side_bar_set_layers(gui_side_bar_struct *s, 
    GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer);

extern void gui_side_bar_update_popout_menu(gui_side_bar_struct *s);
extern void gui_side_bar_get_popout_menu_layout(gui_side_bar_struct *s, 
                UI_font_type *command_font, UI_font_type *data_font, 
                S32 *command_width, S32 *data_width);
extern void gui_side_bar_register_highlight_handler(gui_side_bar_struct *s, wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type handler);
extern void gui_side_bar_reset_to_inactive(gui_side_bar_struct *s);
extern void gui_side_bar_redraw(gui_side_bar_struct *s);


#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL gui_side_bar_pen_handler(gui_side_bar_struct *s, mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
#endif /* __MMI_TOUCH_SCREEN__ */


#endif /*__MMI_OP11_SIDEBAR__ */
#endif /* __GUI_SIDE_BAR_H__ */

