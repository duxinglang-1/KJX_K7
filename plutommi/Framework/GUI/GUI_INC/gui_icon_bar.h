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
 *  gui_icon_bar.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Header
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
#ifndef __GUI_ICON_BAR_H__
#define __GUI_ICON_BAR_H__

/*****************************************************************************
 * include
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

#include "Gui_Setting.h"
#include "gui_typedef.h"

/*****************************************************************************
 * Define
 ****************************************************************************/
#define GUI_ICON_BAR_HINT_WIDTH             MAIN_LCD_DEVICE_WIDTH
#ifndef __MMI_FTE_SUPPORT__
#define GUI_ICON_BAR_HINT_HEIGHT            22
#else /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_MAINLCD_240X320__)
#define GUI_ICON_BAR_HINT_HEIGHT            30
#elif defined(__MMI_MAINLCD_240X400__)
#define GUI_ICON_BAR_HINT_HEIGHT            30
#elif defined(__MMI_MAINLCD_320X480__)
#define GUI_ICON_BAR_HINT_HEIGHT            36
#else
#define GUI_ICON_BAR_HINT_HEIGHT            30
#endif
#endif /* __MMI_FTE_SUPPORT__ */

#define GUI_ICON_BAR_USE_DOUBLE_BUFFER      2
#define MMI_ICON_BAR_HINT_BUF_SIZE          (GUI_ICON_BAR_HINT_WIDTH * GUI_ICON_BAR_HINT_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL >> 3)
#define MMI_ICON_BAR_COMPONENT_BUF_SIZE     (GUI_ICON_BAR_HINT_WIDTH * GUI_ICON_BAR_HINT_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL * GUI_ICON_BAR_USE_DOUBLE_BUFFER >> 3)

/* <group dom_icon_bar_macro>
 *  max count of items that icon bar can contain */
#define GUI_ICON_BAR_MAX_COUNT                  5

/* <group dom_icon_bar_macro>
 *  the count of icons that one screen can display */
#define GUI_ICON_BAR_DISPLAY_COUNT              5

#define GUI_ICON_BAR_GOLDEN_SECTION             0.618
/* <group dom_icon_bar_macro>
 *  gap between border and nearest item,
 * it may has arrow icon in this gap
 */
#define GUI_ICON_BAR_BORDER_GAP                 18
/* <group dom_icon_bar_macro>
 *  standard gap between each item, which
 * used to calculate icon_bar's display count
 */
#define GUI_ICON_BAR_STANDARD_ITEM_GAP          16
/* <group dom_icon_bar_macro>
 *  MIN gap between each item */
#define GUI_ICON_BAR_MIN_ITEM_GAP               0

/* <group dom_icon_bar_macro>
 *  min gap between border and arrow icon */
#define GUI_ICON_BAR_ARROW_ICON_BORDER_GAP      5

/* <group dom_icon_bar_macro>
 *  every icon's width and height */
#define GUI_ICON_BAR_ITEM_ICON_WIDTH            28
/* <group dom_icon_bar_macro> */
#define GUI_ICON_BAR_ITEM_ICON_HEIGHT           28

/* <group dom_icon_bar_macro>
 *  icon's init width & height */
#define GUI_ICON_BAR_ITEM_INIT_WIDTH            GUI_ICON_BAR_ITEM_ICON_WIDTH
/* <group dom_icon_bar_macro> */
#define GUI_ICON_BAR_ITEM_INIT_HEIGHT           GUI_ICON_BAR_ITEM_ICON_HEIGHT
/* <group dom_icon_bar_macro> */
/* content icon and text's gap */
#define GUI_ICON_BAR_ICON_TEXT_GAP              5
/* <group dom_icon_bar_macro> */
#define GUI_ICON_BAR_HINT_WAIT_TIME             600

#ifndef __MMI_FTE_SUPPORT__
#define GUI_ICON_BAR_HINT_X_GAP                   2
#define GUI_ICON_BAR_HINT_Y_GAP                   0
#else
#define GUI_ICON_BAR_HINT_X_GAP                   8
#define GUI_ICON_BAR_HINT_Y_GAP                   4
#endif
/* <group dom_icon_bar_macro> */
#define GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT    4
/* <group dom_icon_bar_macro> */
/* Is a flag which use double buffer to display hint. */
#define GUI_ICON_BAR_FLAG_HINT_USE_DOUBLE_BUFFER   0x00004000
/* <group dom_icon_bar_macro> */
/* Is a flag which enable icon bar to register left/right arrow key. */
#define GUI_ICON_BAR_FLAG_ENABLE_KEY_EVENT         0x00000100
/* <group dom_icon_bar_macro> */
/* Is a flag which show icon bar in horizontal direction */
#define GUI_ICON_BAR_FLAG_HORIZONTAL_DISPLAY        0x00100000
/* <group dom_icon_bar_macro> */
/* Is a flag which show icon bar in vertical direction */
#define GUI_ICON_BAR_FLAG_VERTICAL_DISPLAY          0x00200000
/* <group dom_icon_bar_macro> */
#define GUI_ICON_BAR_FLAG_ALIGN_BIT_OFFSET          24
/* <group dom_icon_bar_macro> */
/* Is a flag mask of icon bar align type. */
#define GUI_ICON_BAR_FLAG_ALIGN_MASK                0x0F000000
/* <group dom_icon_bar_macro> */
/* Is a flag mask of icon bar align init state. */
#define GUI_ICON_BAR_FLAG_ALIGN_INIT                0x00000000
/* <group dom_icon_bar_macro> */
/* Is a flag which show icon bar by head align. */
#define GUI_ICON_BAR_FLAG_HEAD_ALIGN                0x01000000
/* <group dom_icon_bar_macro> */
/* Is a flag which show icon bar by center align. */
#define GUI_ICON_BAR_FLAG_CENTER_ALIGN              0x02000000
/* <group dom_icon_bar_macro> */
/* Is a flag which show icon bar by equidistance align. */
#define GUI_ICON_BAR_FLAG_EQUIDISTANCE_ALIGN        0x04000000
/* <group dom_icon_bar_macro> */
/* Is a flag which show icon bar by end align. */
#define GUI_ICON_BAR_FLAG_END_ALIGN                 0x08000000
/* <group dom_icon_bar_macro> */
/* Is a flag which means the user set the align mode by set_align API */
#define GUI_ICON_BAR_FLAG_SETTED_ALIGN              0x10000000

/*****************************************************************************
 * Typedef
 ****************************************************************************/
/* <group dom_icon_bar_enum> */
typedef enum
{
    GUI_ICON_BAR_ICON_STATE_START = 1,
    GUI_ICON_BAR_ICON_STATE_NORMAL,
    GUI_ICON_BAR_ICON_STATE_KEY_DOWN,
    GUI_ICON_BAR_ICON_STATE_DISABLED,
    GUI_ICON_BAR_ICON_STATE_PEN_DOWN,
    GUI_ICON_BAR_ICON_STATE_PEN_MOVE_IN,
    GUI_ICON_BAR_ICON_STATE_PEN_MOVE_OUT,
    GUI_ICON_BAR_ICON_STATE_PEN_ABORT,
    GUI_ICON_BAR_ICON_STATE_END
} gui_icon_bar_icon_state_enum;

/* <group dom_icon_bar_struct> */
typedef struct
{
    /* Position and dimension of component's item. */
    U8 *normal_icon; /* up background icon of one item. */
    U8 *down_icon; /* down background icon of one item. */
    U8 *content_icon; /* content icon of one item. */
    U8 *disabled_content_icon; /* disable content icon of one item. */
    /* discription of item, can be displayed as hint or text label. */
    U8 *text_of_description;
    /* Callback function of item */
    GUIIconbarItemCallback callback;
    MMI_BOOL disabled; /* disabled state of item */
} gui_icon_bar_item_struct;

/* <group dom_icon_bar_struct> */
typedef struct
{
    U8 *normal_icon;
    U8 *down_icon;
    gui_icon_bar_icon_state_enum state; /* normal or down */
} gui_icon_bar_arrow_icon_struct;

/* <group dom_icon_bar_struct> */
typedef struct
{
    /* position and dimension of icon_bar */
    S32 x, y;
    S32 width, height;

    /* gap information, which can calculate the pos of every item */
    S32 border_gap;
    S32 item_gap;

    /* width of item's icon width */
    S32 item_width;
    S32 item_height;

    /* width of hint */
    S32 hint_width;

    /* count of items that need display */
    U32 count;
    /* display count of a screen */
    U32 display_count;
    /* flags of icon bar */
    U32 flags;

    /*target layer to display*/
    GDI_HANDLE target_layer;
    /* abm source layer */
    GDI_HANDLE abm_layer;

    U8 *highlight; /* highlight image */
    /* hint memory pointer, the memory used for create the hint display layer */
    PU8 hint_layer_ptr1;
    /* hint memory pointer, the memory used for double buffer of hint display layer */
    PU8 hint_layer_ptr2;
    gdi_handle hint_layer_handle;
    gdi_handle h1, h2, h3, h4;

    gui_icon_bar_item_struct item[GUI_ICON_BAR_MAX_COUNT];
    gui_icon_bar_arrow_icon_struct prev_arrow, next_arrow;
    gui_icon_bar_align_enum align_type;
    gui_icon_bar_icon_state_enum focused_item_state;

    /* first_displayed_item item is in value of 0 ~ (count-1) */
    U32 first_displayed_item;
    /* focused item is in value of 0 ~ (display_count-1) */
    U32 focused_item;

    void (*hide_callback) (S32 x1, S32 y1, S32 x2, S32 y2); /*hide function*/
    /* icon_bar_update_handler used to get item's information dynamiclly */
    MMI_BOOL (*dynamic_update_handler)(
                U32 start_index,
                U32 item_count,
                PU8 *normal_icon,
                PU8 *down_icon,
                PU8 *content_icon,
                PU8 *disabled_content_icon,
                PU8 *text_of_description);
    void (*highlight_handler)(S32 index);
    void (*idle_display_handler)(S32 index);
    MMI_BOOL (*item_refresh_callback)(S32 index);
    U32 pause_interactive_UI_callback_count;
    U32 resume_interactive_UI_callback_count;
    FuncPtr pause_interactive_UI_callback[GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT];
    FuncPtr resume_interactive_UI_callback[GUI_ICON_BAR_PAUSE_INTERACTIVE_CALLBACK_MAX_COUNT];
    MMI_BOOL interactive_UI_paused;
    MMI_BOOL need_draw_hint; /* whether focused item need draw hint or not */
    MMI_BOOL need_erase_hint; /* whether focused item need erase hint or not */

    /* icon_bar is active or not, if it is active, left/right key can work,
     * or, it will do nothing
     */
    MMI_BOOL active;
    /* whether permit icon bar to arrange item position automatically */
    MMI_BOOL auto_arrange_item;
} gui_icon_bar_struct;

/*****************************************************************************
 * Global Function
 ****************************************************************************/
extern MMI_BOOL gui_icon_bar_create(
                 gui_icon_bar_struct *icon_bar,
                 S32 x,
                 S32 y,
                 S32 width,
                 S32 height,
                 S32 item_count,
                 MMI_BOOL enable_key_event,
                 MMI_BOOL hint_use_double_buffer);
extern void gui_icon_bar_close(gui_icon_bar_struct *icon_bar);
extern void gui_icon_bar_move(gui_icon_bar_struct *icon_bar, S32 x, S32 y);
extern void gui_icon_bar_resize(gui_icon_bar_struct *icon_bar, S32 width, S32 height);
extern void gui_icon_bar_set_item(
             gui_icon_bar_struct *icon_bar,
             U32 index,
             U8 *normal_icon,
             U8 *down_icon,
             U8 *content_icon,
             U8 *disabled_content_icon,
             U8 *text_of_description,
             GUIIconbarItemCallback callback);
extern void gui_icon_bar_set_item_enable_state(
             gui_icon_bar_struct *icon_bar,
             U32 index,
             MMI_BOOL state);
extern void gui_icon_bar_set_align(
             gui_icon_bar_struct *icon_bar,
             gui_icon_bar_align_enum align_type);
extern void gui_icon_bar_set_target_layer(
             gui_icon_bar_struct *icon_bar,
             GDI_HANDLE target_layer);
extern void gui_icon_bar_set_abm_layer(
             gui_icon_bar_struct *icon_bar,
             GDI_HANDLE abm_layer);
extern MMI_BOOL gui_icon_bar_is_active(gui_icon_bar_struct *icon_bar);
extern void gui_icon_bar_register_highlight_handler(
             gui_icon_bar_struct *icon_bar,
             void (*f)(S32 index));
extern void gui_icon_bar_register_idle_display_handler(
             gui_icon_bar_struct *icon_bar,
             void (*f)(S32 index));
extern void gui_icon_bar_show(gui_icon_bar_struct *icon_bar);
extern void gui_icon_bar_set_arrow_icon(
             gui_icon_bar_struct *icon_bar,
             gui_icon_bar_arrow_enum arrow,
             U8 *normal_icon,
             U8 *down_icon);
extern void gui_icon_bar_set_highlight_icon(
             gui_icon_bar_struct *icon_bar,
             U8 *highlight_icon);
extern void gui_icon_bar_set_fixed_position_info(
             gui_icon_bar_struct *icon_bar,
             S32 item_width,
             S32 item_height,
             S32 item_gap);
extern void gui_icon_bar_register_update_handler(
             gui_icon_bar_struct *icon_bar,
             MMI_BOOL (*f) (
                 U32 start_index,
                 U32 item_count,
                 U8 **normal_icon,
                 U8 **down_icon,
                 U8 **content_icon,
                 U8 **disabled_content_icon,
                 U8 **text_of_description));
extern void gui_icon_bar_register_hide_function(
             gui_icon_bar_struct *icon_bar,
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_icon_bar_active(gui_icon_bar_struct *icon_bar);
extern void gui_icon_bar_deactive(gui_icon_bar_struct *icon_bar);
extern void gui_icon_bar_set_flags_on(
             gui_icon_bar_struct *icon_bar,
             U32 flag);
extern void gui_icon_bar_set_flags_off(
             gui_icon_bar_struct *icon_bar,
             U32 flag);
extern gdi_handle gui_icon_bar_get_hint_layer_handle(
                   gui_icon_bar_struct *icon_bar);
extern void gui_icon_bar_set_display_direction(
             gui_icon_bar_struct *icon_bar,
             gui_icon_bar_display_direction_enum direction);

#ifdef __MMI_FTE_SUPPORT__
extern void gui_icon_bar_register_pause_interactive_UI_callback(
             gui_icon_bar_struct *icon_bar,
             void (*f) (void));
extern void gui_icon_bar_register_resume_interactive_UI_callback(
             gui_icon_bar_struct *icon_bar,
             void (*f) (void));
#else
 #define gui_icon_bar_register_pause_interactive_UI_callback(_arg1, _arg2) 0
 #define gui_icon_bar_register_resume_interactive_UI_callback(_arg1,_arg2) 0
#endif
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL gui_icon_bar_translate_pen_event(
          gui_icon_bar_struct *icon_bar,
          mmi_pen_event_type_enum pen_event,
          S16 x,
          S16 y);
extern void gui_icon_bar_reset_pen_state(gui_icon_bar_struct *icon_bar);

extern void gui_icon_bar_register_item_refresh_callback(
             gui_icon_bar_struct *icon_bar,
             MMI_BOOL (*f)(S32 index));
/* DOM-NOT_FOR_SDK-END */


#endif /* __MMI_TOUCH_SCREEN__ */


#endif /* __GUI_ICON_BAR_H__ */ 



