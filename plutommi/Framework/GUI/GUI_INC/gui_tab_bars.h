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
 *   gui_tab_bars.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tab Bar - UI component
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only.
 * It's not recommended to be included in application code directly.
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#ifndef _GUI_TAB_BARS_H
#define _GUI_TAB_BARS_H
/*****************************************************************************
* Include
*****************************************************************************/

#include "gui.h"
#include "gui_theme_struct.h"
#include "gui_buttons.h"
#include "gui_title.h"
#include "gui_typedef.h"
#include "gui_tab_bars_pre_oem.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#include "mmi_frm_gprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
* Define
*****************************************************************************/
#if defined(__MMI_FWUI_SLIM__) && !defined(__MMI_OP11_TAB_BAR__)
    #ifndef __MMI_TAB_BAR_SLIM__
    #define __MMI_TAB_BAR_SLIM__ 
    #endif
#endif

#ifdef __MMI_FTE_SUPPORT__
    #define GUI_TAB_GAP         0
#elif defined(__MMI_MAINLCD_320X480__)
    #define GUI_TAB_GAP         32
#elif defined(__MMI_MAINLCD_320X240__)
    #define GUI_TAB_GAP         60
#elif defined(__MMI_MAINLCD_240X400__)
    #define GUI_TAB_GAP         16
#elif defined(__MMI_MAINLCD_96X64__) || (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__))
    #define GUI_TAB_GAP         1
#else
    #define GUI_TAB_GAP         0
#endif

#define GUI_TAB_TEXT_GAP    2

/*****************************************************************************
* Typedef
*****************************************************************************/


#ifdef __MMI_TOUCH_SCREEN__

typedef enum
{
    GUI_TAB_BAR_PEN_NONE,
    GUI_TAB_BAR_PEN_NEED_REDRAW,
    GUI_TAB_BAR_PEN_JUMP_TO_I
} gui_tab_bar_pen_enum;

#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
* Extern Global Variable
*****************************************************************************/
extern UI_horizontal_tab_bar_theme *current_horizontal_tab_bar_theme;

/*****************************************************************************
* Extern Global Function
*****************************************************************************/

/* Horizontal tab bar - Basic UI conponent interface */
extern void gui_set_horizontal_tab_bar_current_theme(horizontal_tab_bar *tb);
extern void gui_set_horizontal_tab_bar_theme(horizontal_tab_bar *tb, UI_horizontal_tab_bar_theme *t);

extern void gui_create_horizontal_tab_bar_ex(
                horizontal_tab_bar *tb,
                S32 x,
                S32 y,
                S16 width,
                S16 tab_area_height,
                S16 hint_area_height,
                S16 tab_width,
		S16 tab_gap,
                S16 focused_tab_width,
                UI_string_type hint,
                S8 n_item,
                S8 focused_item,
                U32 style,
                tab_bar_item_type *items,
                gdi_handle target_lcd,
                gdi_handle target_layer,
                gdi_handle alpha_blend_layer);
extern void gui_create_horizontal_tab_bar(
                horizontal_tab_bar *tb,
                S32 x,
                S32 y,
                S16 width,
                S16 tab_area_height,
                S16 hint_area_height,
                S16 tab_width,
                S16 focused_tab_width,
                UI_string_type hint,
                S8 n_item,
                S8 focused_item,
                tab_bar_item_type *items);

extern void gui_resize_horizontal_tab_bar(
                horizontal_tab_bar *tb,
                S16 width,
                S16 tab_area_height,
                S16 hint_area_height);
extern void gui_move_horizontal_tab_bar(horizontal_tab_bar *tb, S32 x, S32 y);
extern void (*gui_show_horizontal_tab_bar)(horizontal_tab_bar *tb, BOOL disable_tab_area, BOOL disable_hint_area);
extern void gui_horizontal_tab_bar_set_target_lcd(horizontal_tab_bar *tb, gdi_handle target_lcd);
extern gdi_handle gui_horizontal_tab_bar_get_target_lcd(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_reset_target_lcd(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_set_target_layer(horizontal_tab_bar *tb, gdi_handle target_layer);
extern gdi_handle gui_horizontal_tab_bar_get_target_layer(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_reset_target_layer(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_set_alpha_blend_layer(horizontal_tab_bar *tb, gdi_handle alpha_blend_layer);
extern gdi_handle gui_horizontal_tab_bar_get_alpha_blend_layer(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_reset_alpha_blend_layer(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_register_hide_callback(horizontal_tab_bar *tb, void(*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_horizontal_tab_bar_reset_hide_callback(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_close(horizontal_tab_bar *tb);

#ifdef __MMI_TOUCH_SCREEN__
extern BOOL gui_horizontal_tab_bar_translate_pen_event(
                horizontal_tab_bar *tb,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_tab_bar_pen_enum *tab_event,
                gui_pen_event_param_struct *tab_event_param);
#endif /* __MMI_TOUCH_SCREEN__ */

/* Horizontal tab bar - Attributes */
extern void gui_horizontal_tab_bar_set_icon_position(horizontal_tab_bar *tb, S16 x, S16 y);
extern void gui_horizontal_tab_bar_set_text_position(horizontal_tab_bar *tb, S16 x, S16 y, S16 width);

extern void gui_horizontal_tab_bar_set_blinking(horizontal_tab_bar *tb, S8 index);
extern void gui_horizontal_tab_bar_unset_blinking(horizontal_tab_bar *tb, S8 index);

extern MMI_BOOL gui_set_horizontal_tab_bar_display_range(horizontal_tab_bar *tb, S32 first_displayed_item);

/* Horizontal tab bar - Navigation */
extern void gui_horizontal_tab_bar_focus_item(horizontal_tab_bar *tb, S8 index);
extern void gui_horizontal_tab_bar_focus_next_item(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_focus_prev_item(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_focus_first_item(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_focus_last_item(horizontal_tab_bar *tb);

extern BOOL gui_horizontal_tab_bar_is_item_displayed(horizontal_tab_bar *tb, int index);

/* Horizontal tab bar - Blinking */
extern void gui_horizontal_tab_bar_start_blinking(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_stop_blinking(horizontal_tab_bar *tb);

/* Tab item */
extern void gui_setup_tab_item(tab_bar_item_type *item, PU8 icon, UI_string_type text, MMI_BOOL enable_blinking);

#include "gui_tab_bars_post_oem.h"

#endif /* _GUI_TAB_BARS_H */


