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
 *  gui_tab_bars_pre_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  tab bars - UI component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_TAB_BARS_PRE_OEM_H__
#define __GUI_TAB_BARS_PRE_OEM_H__

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
#include "gui_title.h"

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "gui_theme_struct.h"
#include "gui_title_pre_oem.h"
#include "gui_windows.h"
#include "gdi_datatype.h"


/***************************************************************************** 
* Define
*****************************************************************************/
/* Flags of tab_bar_item_type.flags */
#define UI_TAB_BAR_ITEM_STATE_NORMAL                  0x00000000
#define UI_TAB_BAR_ITEM_STATE_BLINKING                0x00000001
#define UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED      0x00000004
#define UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED      0x00000008

/* Flags of horizontal_tab_bar.flags */
#define UI_TAB_BAR_DISABLE_DRAW                       0x00000001
#define UI_TAB_BAR_LOOP                               0x00000002
/* Disable pen control on tab bars in certain cases */
#define UI_TAB_BAR_DISABLE_PEN                        0x00000008


#ifdef __MMI_OP11_TAB_BAR__
    #define UI_TAB_BAR_BLINKING_DURATION            (4000)
    #define GUI_TAB_DISPLAY_ITEM_MAX                (7)
#else /* __MMI_OP11_TAB_BAR__ */
    #if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
        #define GUI_TAB_DISPLAY_ITEM_MAX            (3)
    #else
        #define GUI_TAB_DISPLAY_ITEM_MAX            (4)
    #endif
#endif/* __MMI_OP11_TAB_BAR__ */


/* Number of tabs to display ahead on scrolling */
#define UI_TAB_BAR_SHOW_AHEAD                (0)


#ifndef __MMI_OP11_TAB_BAR__
    #if defined(__MMI_MAINLCD_320X240__)
        #define UI_TAB_BAR_ARROW_ICON_GAP             (5)        /* be careful of overlapping with tab icon */
    #elif defined(__MMI_MAINLCD_240X320__)
        #define UI_TAB_BAR_ARROW_ICON_GAP             (5)
    #else
        #define UI_TAB_BAR_ARROW_ICON_GAP             (3)
    #endif
#else /* __MMI_OP11_TAB_BAR__ */
    #define UI_TAB_BAR_ARROW_ICON_GAP                 (1)
#endif /* __MMI_OP11_TAB_BAR__ */

#define UI_TAB_BAR_BLINKING_TIME                      (500)


#if defined(__MMI_MAINLCD_320X240__)
    #define GUI_TAB_ARROW_INDENT_X      (42)
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)
    #define GUI_TAB_ARROW_INDENT_X      (3)
#endif


/* The gap between items is 2 * GUI_TAB_BAR_ITEM_GAP pixel */
#ifdef __MMI_FTE_SUPPORT__
#define GUI_TAB_BAR_ITEM_GAP            (0)
#define GUI_TAB_TEXT_INDENT_X           (6)
#if defined(__MMI_MAINLCD_320X240__)
#define GUI_TAB_BAR_OVERLAP_WITH_TITLE  (0)
#else
#define GUI_TAB_BAR_OVERLAP_WITH_TITLE  (3)
#endif
#else /* __MMI_FTE_SUPPORT__ */
#define GUI_TAB_BAR_ITEM_GAP            (1)
#define GUI_TAB_TEXT_INDENT_X           (GUI_TAB_BAR_ITEM_GAP + 2)
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_TOUCH_SCREEN__

typedef struct
{
    S16 left_button_x, left_button_y;
    S16 left_button_width, left_button_height;
    S16 right_button_x, right_button_y;
    S16 right_button_width, right_button_height;
} gui_tab_bar_pen_state_struct;

#endif /* __MMI_TOUCH_SCREEN__ */


typedef struct _horizontal_tab_bar
{
    S8 n_items;
    S8 focused_item;
    /* first item displayed */
    S8 first_displayed_item;
    /* last item displayed */
    S8 last_displayed_item;
    /* the maximum number of tab items that can be displayed at the same time */
    S8 n_displayable_item;
    /* the number of tab items to display ahead when rotating the tab items. */
    S8 n_item_ahead;
    /* Left & right button */
    S8 left_button_pressed;
    S8 right_button_pressed;
    /* the coordinate of horizontal tab bar */
    S16 x, y;
    S16 width, height;
    S16 tab_area_x;
    S16 tab_area_width;
    S16 tab_gap;
    /* width of non-focused tab */
    S16 tab_width;
    S16 tab_height;
    /* width of focused tab */
    S16 focused_tab_width;
    S16 focused_tab_height;
    /* height of the tab area */
    S16 tab_area_height;
    /* height of the hint area */
    S16 hint_area_height;


    /* Icon/text position inside a tab item */
    S16 tab_icon_x, tab_icon_y; /* deprecated */
    S16 tab_text_x, tab_text_y, tab_text_width;

    U32 flags;
    U32 style;    

    UI_string_type hint;
    PU8 hint_icon;
    
    tab_bar_item_type *items;

    UI_horizontal_tab_bar_theme *theme;
    gui_title_struct title;
    scrolling_text focused_item_scrolling_text;
    /* tab bar target lcd */
    gdi_handle target_lcd;
    /* tab bar target layer */
    gdi_handle target_layer;
    /* tab bar alpha blend layer */
    gdi_handle alpha_blend_layer;
    /* tab bar hide callback funtion, use to hide tabbar */
    void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_TOUCH_SCREEN__
    /* Used by gui_horizontal_tab_bar_translate_pen_event() */
    gui_tab_bar_pen_state_struct pen_state;
#endif /* __MMI_TOUCH_SCREEN__ */
} horizontal_tab_bar;


/* the type of tab bar item's background */
typedef enum
{
    /* normal item's background */
    GUI_TAB_BAR_NORMAL_BACKGROUND,
    /* highlight item's background */
    GUI_TAB_BAR_HIGHLIGHT_BACKGROUND,
    /* blink item's background */
    GUI_TAB_BAR_BLINK_BACKGROUND,
    /* disabled item's background */
    GUI_TAB_BAR_DISABLED_BACKGROUND,
#ifdef __MMI_OP11_TAB_BAR__
    /* no response item's background */
    GUI_TAB_BAR_NO_RESPONSE_BACKGROUND,
#endif
    /* the end mark of background */
    GUI_TAB_BAR_TOTAL_BACKGROUND
} gui_tab_bar_background_enum;

#endif /* __GUI_TAB_BARS_PRE_OEM_H__ */


