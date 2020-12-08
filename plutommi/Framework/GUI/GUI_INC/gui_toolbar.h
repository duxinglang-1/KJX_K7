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
 *  gui_toolbar.h
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

#ifndef __GUI_TOOLBAR_H__
#define __GUI_TOOLBAR_H__

#include "MMI_features.h"

#ifdef __MMI_OP12_TOOLBAR__

#include "Wgui.h"

/* Macro */
#define GUI_TOOLBAR_MAX_MENU    5


/* Typedef */
typedef void (*wgui_toolbar_getmenudata_funcptr_type)(
            S32 *number_of_items, 
            PU8 *title_text, 
            PU8 *icon_of_items, 
            PU8 *text_of_items, 
            PU8 *text_of_description, 
            S32 max_number);
typedef void (*wgui_toolbar_popout_menu_highlighthandler_funcptr_type)(S32 item_index);


typedef enum
{
    MMI_GUI_TOOLBAR_STATE_INACTIVE,
    MMI_GUI_TOOLBAR_STATE_ACTIVE,
    MMI_GUI_TOOLBAR_STATE_TOTAL
} mmi_gui_toolbar_state_enum;

typedef enum
{
    MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_HIDE,
    MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_NORMAL,   
    MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_EVENT,        
    MMI_GUI_TOOLBAR_POPOUT_MENU_STATE_TOTAL
} mmi_gui_toolbar_popout_menu_state_enum;

typedef struct
{
    PU8 icon_normal;
    PU8 icon_highlight;
    PU8 title_text;
    mmi_gui_toolbar_popout_menu_state_enum state;
    S32 number_of_popout_menu_items;
    PU8 icon_of_items [MAX_SUB_MENUS];
    PU8 text_of_items[MAX_SUB_MENUS];
    PU8 text_of_description[MAX_SUB_MENUS];
    wgui_toolbar_getmenudata_funcptr_type get_menu_data_callback;
    wgui_toolbar_popout_menu_highlighthandler_funcptr_type menu_highlight_handler;
    S32 popout_menu_item_width;
    S32 popout_menu_item_height;
    S32 bg_number;
    S32 highlight_menu_item;
    S32 first_menu_item;
} gui_toolbar_menu_struct;

typedef struct
{
    S32 x;
    S32 y;
    S32 max_width;
    S32 max_height;
    S32 bar_x;
    S32 bar_y;
    S32 bar_width;
    S32 bar_height;
    mmi_gui_toolbar_state_enum state;
    GDI_HANDLE toolbar_layer;
    GDI_HANDLE popout_menu_layer;
    GDI_HANDLE wallpaper_layer;
    S32 toolbar_menu_number;
    S32 toolbar_highlighted_menu_index;
    gui_toolbar_menu_struct toolbar_menu[GUI_TOOLBAR_MAX_MENU];
    S32 popout_menu_transition_offset;
    S32 bar_highlight_transition_offset;
    S32 title_transition_offset;
    S32 popout_menu_transition_times;
    S32 bar_highlight_transition_times;
    MMI_BOOL is_in_transition;
    S32 menu_highlight_from_history;
    S32 menu_first_item_from_history;
    FuncPtr current_popout_menu_keyhandler[2];
} gui_toolbar_struct;



/* Extern API */
extern void gui_toolbar_create(
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
                mmi_gui_toolbar_popout_menu_state_enum *popout_menu_state);
extern void gui_toolbar_close(gui_toolbar_struct *t);
extern void gui_toolbar_move(gui_toolbar_struct *t, S32 x, S32 y);
extern void gui_toolbar_resize(gui_toolbar_struct *t, S32 max_width, S32 max_height);
extern void gui_toolbar_set_layers(gui_toolbar_struct *t, 
                GDI_HANDLE toolbar_layer, 
                GDI_HANDLE popout_menu_layer, 
                GDI_HANDLE wallpaper_layer);
extern void gui_toolbar_show(gui_toolbar_struct *t);
extern void gui_toolbar_set_bar_state(gui_toolbar_struct *t, mmi_gui_toolbar_state_enum state);
extern void gui_toolbar_set_popout_menu_state(gui_toolbar_struct *t, S32 index, mmi_gui_toolbar_popout_menu_state_enum state);
extern void gui_toolbar_update_popout_menu(gui_toolbar_struct *t);
extern void gui_toolbar_redraw(gui_toolbar_struct *t);
extern void gui_toolbar_change_bar_icon(gui_toolbar_struct *t, S32 index, PU8 icon_normal, PU8 icon_highlight);
extern MMI_BOOL gui_toolbar_is_active(gui_toolbar_struct *t);
extern void gui_toolbar_change_popout_menu_highlight(gui_toolbar_struct *t, S32 index, S32 highlight_position);

#endif /* __MMI_OP12_TOOLBAR__ */

#endif /* __GUI_TOOLBAR_H__ */



