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
 *   gui_tab_bars.c
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
 *
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/
#include "MMI_features.h"
#include "gui_themes.h"
#include "gui_tab_bars.h"
#include "wgui.h"
#include "wgui_tab_bars.h"
#include "gui_menu_shortcut.h"
#include "wgui_categories_util.h"
#include "mmi_frm_gprot.h"
#include "wgui_include.h"
#include "gui_touch_feedback.h"

#include "MMIDataType.h"
#include "gui_tab_bars_pre_oem.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "gui.h"
#include "gui_typedef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "gui_theme_struct.h"
#include "gui_data_types.h"
#include "CustThemesRes.h"
#include "CustDataRes.h"
#include "gui_tab_bars_post_oem.h"
#include "string.h"
#include "gdi_const.h"
#include "gui_title.h"
#include "mmi_frm_input_gprot.h"



/*
 * TODO:
 * *
 * * If tab items is blinking but not displayed, the corresponding left/right arrows should be blinking, too.
 * *
 */

/*****************************************************************************
* Define
*****************************************************************************/


/* In previous design, focused tab item overlaps other tab items.
   However, it is not true anymore */
#undef UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER

#ifdef __MMI_OP11_TAB_BAR__
    #define GUI_TAB_NORMAL_ITEM_INDENT_Y        (0)
#else/* __MMI_OP11_TAB_BAR__ */
    #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        #define GUI_TAB_NORMAL_ITEM_INDENT_Y    (0)
    #elif defined(__MMI_MAINLCD_320X480__)
        #define GUI_TAB_NORMAL_ITEM_INDENT_Y    (4)
    #elif(defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
        #define GUI_TAB_NORMAL_ITEM_INDENT_Y    (3)
    #elif(defined(__MMI_MAINLCD_96X64__) ||defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
        #define GUI_TAB_NORMAL_ITEM_INDENT_Y    (2)
    #else
        #define GUI_TAB_NORMAL_ITEM_INDENT_Y    (0)
    #endif
#endif /*__MMI_OP11_TAB_BAR__ */


/*****************************************************************************
* Global Variable
*****************************************************************************/
void (*gui_show_horizontal_tab_bar)(horizontal_tab_bar *tb, BOOL disable_tab_area, BOOL disable_hint_area) = NULL;
static void (*gui_horizontal_tab_bar_locate_focused_item)(horizontal_tab_bar *tb) = NULL;
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
static void (*gui_horizontal_show_status_icon)(void) = NULL;
#endif
static void (*gui_horizontal_tab_bar_show_item)(horizontal_tab_bar *tb, S8 i) = NULL;
#if defined(UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER) || defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_OP11_TAB_BAR__)
static void (*gui_horizontal_tab_bar_show_focused_item)(horizontal_tab_bar *tb) = NULL;
#endif
#ifdef __MMI_TOUCH_SCREEN__
static gdi_handle (*gui_horizontal_tab_bar_setup_target_lcd_and_layer)(horizontal_tab_bar *tb);
static void (*gui_horizontal_tab_bar_restore_target_lcd_and_layer)(horizontal_tab_bar *tb, gdi_handle old_lcd_handle);
#endif
static void (*gui_horizontal_tab_bar_focused_text_scrolling_handler)(void);

/* Used for blinking */
horizontal_tab_bar *UI_current_horizontal_tab_bar;


/*****************************************************************************
* Local Function
*****************************************************************************/
/*
 * Adjust first_displayed_item, last_displayed_item, n_displayable_item according to focused_item
 * when the focus item index is incremented.
 */


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_locate_next_item
 * DESCRIPTION
 *  locate next item of tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_locate_next_item(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tb->n_displayable_item == 0)
    {
        gui_horizontal_tab_bar_locate_focused_item(tb);
    }

    if ((tb->last_displayed_item == tb->n_items - 1) ||
        (tb->focused_item + tb->n_item_ahead <= tb->last_displayed_item))
    {
        /* Unnecessary to rotate the tab items */
        return;
    }

    if (tb->n_items <= tb->n_displayable_item)
    {
        tb->first_displayed_item = 0;
        tb->last_displayed_item = tb->n_items - 1;
    }
    else if (tb->focused_item + tb->n_item_ahead >= tb->n_items - 1)
    {
        tb->first_displayed_item = tb->n_items - tb->n_displayable_item;
        tb->last_displayed_item = tb->n_items - 1;
    }
    else if (tb->focused_item + tb->n_item_ahead <= tb->n_displayable_item - 1)
    {
        tb->first_displayed_item = 0;
        tb->last_displayed_item = tb->n_displayable_item - 1;
    }
    else
    {
        tb->last_displayed_item = tb->focused_item + tb->n_item_ahead;
        tb->first_displayed_item = tb->last_displayed_item + 1 - tb->n_displayable_item;
    }
}

/*
 * Adjust first_displayed_item, last_displayed_item, n_displayable_item according to focused_item
 * when the focus item index is decremented. Try to show 'UI_TAB_BAR_SHOW_AHEAD' items ahead.
 *
 * gui_horizontal_tab_bar_locate_focused_item() should be invoked before this API.
 */


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_locate_prev_item
 * DESCRIPTION
 *  locate previous item of tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_locate_prev_item(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tb->n_displayable_item == 0)
    {
        gui_horizontal_tab_bar_locate_focused_item(tb);
    }

    if ((tb->first_displayed_item == 0) || (tb->focused_item >= tb->first_displayed_item + tb->n_item_ahead))
    {
        /* Unnecessary to rotate the tab items */
        return;
    }

    if (tb->n_items <= tb->n_displayable_item)
    {
        tb->first_displayed_item = 0;
        tb->last_displayed_item = tb->n_items - 1;
    }
    else if (tb->focused_item <= tb->n_item_ahead)
    {
        tb->first_displayed_item = 0;
        tb->last_displayed_item = tb->n_displayable_item - 1;
    }
    else if (tb->focused_item - tb->n_item_ahead + tb->n_displayable_item - 1 >= tb->n_items - 1)
    {
        tb->first_displayed_item = tb->n_items - tb->n_displayable_item;
        tb->last_displayed_item = tb->n_items - 1;
    }
    else
    {
        tb->first_displayed_item = tb->focused_item - tb->n_item_ahead;
        tb->last_displayed_item = tb->first_displayed_item + tb->n_displayable_item - 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_blink_hdlr
 * DESCRIPTION
 *  tab bar blink handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_tab_bar_blink_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;
    horizontal_tab_bar *tb = UI_current_horizontal_tab_bar;

#ifdef UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER
    BOOL redraw_focused_item = MMI_FALSE;
#endif
    BOOL redraw_bar = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!tb)
    {
        return;
    }

    gui_lock_double_buffer();

    gui_push_clip();



    for (i = tb->first_displayed_item; i <= tb->last_displayed_item; i++)
    {
        if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING)
        {
            if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED)
            {
                tb->items[i].flags &= ~UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED;
            }
            else
            {
                tb->items[i].flags |= UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED;
            }

        #ifdef __MMI_OP11_TAB_BAR__
            if (tb->items[i].blink_duration < 0)
            {
                continue;
            }
            else
            {
                tb->items[i].blink_duration -= UI_TAB_BAR_BLINKING_TIME;
            }
        #endif /* __MMI_OP11_TAB_BAR__ */

        #ifdef UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER
            if ((i == tb->focused_item - 1) || (i == tb->focused_item + 1))
            {
                redraw_focused_item = TRUE;
            }
        #endif /* UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER */

            MMI_DBG_ASSERT(i != tb->focused_item);
            gui_horizontal_tab_bar_show_item(tb, i);
            redraw_bar = TRUE;
        }
    }

#ifdef UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER
    if (redraw_focused_item)
    {
        gui_horizontal_tab_bar_show_focused_item(tb);
    }
#endif /* UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER */

    gui_pop_clip();
    gui_unlock_double_buffer();

    if (redraw_bar)
    {
        gui_BLT_double_buffer(tb->tab_area_x, tb->y, tb->tab_area_x + tb->tab_area_width - 1, tb->y + tb->tab_area_height - 1);
    }
    gui_start_timer(UI_TAB_BAR_BLINKING_TIME, gui_horizontal_tab_bar_blink_hdlr);
}

/*****************************************************************************
* Global Variable
*****************************************************************************/

UI_horizontal_tab_bar_theme *current_horizontal_tab_bar_theme = NULL;

/*****************************************************************************
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_tab_bar_current_theme
 * DESCRIPTION
 *
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_tab_bar_current_theme(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->theme = current_horizontal_tab_bar_theme;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_tab_bar_theme
 * DESCRIPTION
 *  Apply the given theme to the horizontal tab bar
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 *  t       [IN]            Theme (memory should not be released when the tab bar is still active)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_tab_bar_theme(horizontal_tab_bar *tb, UI_horizontal_tab_bar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->theme = t;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_tab_bar_ex
 * DESCRIPTION
 *  Apply the given theme to the horizontal tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 *  x                       [IN]            position
 *  y                       [IN]            position
 *  width                   [IN]            tab bar width
 *  tab_area_height         [IN]            tab area height
 *  hint_area_height        [IN]            hint area height
 *  tab_width               [IN]            tab width
 *  focused_tab_width       [IN]            focused tab width
 *  hint                    [IN]            hint string
 *  n_item                  [IN]            number of tabs
 *  focused_item            [IN]            focused tab index
 *  style                   [IN]            style of tab bar
 *  items                   [IN]            tab items data
 *  target_lcd              [IN]            tab bar's target lcd
 *  target_layer            [IN]            tab bar's target layer
 *  alpha_blend_layer       [IN]            tab bar's alpha blend layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_tab_bar_ex(
        horizontal_tab_bar *tb,
        S32 x,
        S32 y,
        S16 width,
        S16 tab_area_height,
        S16 hint_area_height,
        S16 tab_width,
        S16 focused_tab_width,
	S16 tab_gap,
        UI_string_type hint,
        S8 n_item,
        S8 focused_item,
        U32 style,
        tab_bar_item_type *items,
        gdi_handle target_lcd,
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ih = 0, iw = 0;

    #ifdef __MMI_OP11_TAB_BAR__
    S32 i;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->x = x;
    tb->y = y;
    tb->width = width;
    tb->height = tab_area_height + hint_area_height;
    tb->flags = 0;

    tb->tab_gap = tab_gap;
    tb->tab_area_x = tb->x + tb->tab_gap;
    tb->tab_area_width = tb->width - (tb->tab_gap<<1);

    tb->target_lcd = target_lcd;
    tb->target_layer = target_layer;
    tb->alpha_blend_layer = alpha_blend_layer;
    tb->hide_callback = NULL;

    if (focused_item >= n_item)
    {
        focused_item = 0;
    }

    /* mandatory */
    if (focused_tab_width < tab_width)
    {
        focused_tab_width = tab_width;
    }

    tb->hint = hint;
    tb->hint_icon = NULL;

    tb->n_items = n_item;
    tb->focused_item = focused_item;
    tb->items = items;
    tb->style = style;

#ifdef __MMI_OP11_TAB_BAR__
    tb->style &= ~GUI_TAB_BAR_STYLE_SCOLLING_FOCUSED_ITEM_TEXT;
    tb->style |= GUI_TAB_BAR_STYLE_AUTO_RESIZE_ITEM_WIDTH;

    for (i = 0; i < tb->n_items; i ++)
    {
        if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING)
        {
            tb->items[i].blink_duration = UI_TAB_BAR_BLINKING_DURATION;
        }
        else
        {
            tb->items[i].blink_duration = -1;
        }

        if (tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING &&
            tb->items[i].flags & UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED)
        {
            tb->items[i].blink_duration = -1;
        }
    }
#endif /* __MMI_OP11_TAB_BAR__ */


    tb->first_displayed_item = 0;
    tb->last_displayed_item = 0;
    tb->n_displayable_item = 0;
    tb->n_item_ahead = 0;

    tb->tab_width = tab_width;
    tb->focused_tab_width = focused_tab_width;
    tb->tab_area_height = tab_area_height;
    tb->hint_area_height = hint_area_height;

    tb->left_button_pressed = 0;
    tb->right_button_pressed = 0;

    tb->tab_icon_x = 0;
    tb->tab_icon_y = 0;
    tb->tab_text_x = GUI_TAB_TEXT_INDENT_X;
    tb->tab_text_y = 0;
    tb->tab_text_width = tb->tab_width - ((GUI_TAB_TEXT_INDENT_X) << 1);

    gui_set_horizontal_tab_bar_current_theme(tb);

    if (tb->theme->focused_tab_filler)
    {
        if (tb->theme->focused_tab_filler->flags & UI_FILLED_AREA_TYPE_BITMAP)
        {
            gui_measure_image((PU8) tb->theme->focused_tab_filler->b, &iw, &ih);
            tb->focused_tab_height = (S16) ih;
        }
        else
        {
            tb->focused_tab_height = tab_area_height;
        }
    }
    else if (tb->theme->focused_tab_icon) /* use icon instead of filler */
    {
        gui_measure_image((PU8) GetImage(tb->theme->focused_tab_icon), &iw, &ih);
        tb->focused_tab_height = (S16) ih;
    }
    else
    {
        tb->focused_tab_height = tab_area_height;
    }
    tb->tab_height = tb->focused_tab_height - GUI_TAB_NORMAL_ITEM_INDENT_Y;
#ifdef __MMI_FTE_SUPPORT__
    tb->focused_tab_height -= GUI_TAB_NORMAL_ITEM_INDENT_Y;
#endif

#ifdef __MMI_OP11_TAB_BAR__
    gui_horizontal_tab_bar_show_item =gui_horizontal_tab_bar_show_item_OG;
    gui_horizontal_tab_bar_show_focused_item = gui_horizontal_tab_bar_show_focused_item_OG;
    gui_show_horizontal_tab_bar = gui_show_horizontal_tab_bar_OG;
#else /* __MMI_OP11_TAB_BAR__  */
    gui_horizontal_tab_bar_show_item = gui_horizontal_tab_bar_show_item_normal;
#if defined(UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER) || defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_OP11_TAB_BAR__)
    gui_horizontal_tab_bar_show_focused_item = gui_horizontal_tab_bar_show_focused_item_normal;
#endif
    gui_show_horizontal_tab_bar = gui_show_horizontal_tab_bar_normal;
#endif /* __MMI_OP11_TAB_BAR__  */

    gui_horizontal_tab_bar_locate_focused_item = gui_horizontal_tab_bar_locate_focused_item_oem;
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    gui_horizontal_show_status_icon = gui_horizontal_show_status_icon_oem;
#endif
#ifdef __MMI_TOUCH_SCREEN__
    gui_horizontal_tab_bar_setup_target_lcd_and_layer = gui_horizontal_tab_bar_setup_target_lcd_and_layer_oem;
    gui_horizontal_tab_bar_restore_target_lcd_and_layer = gui_horizontal_tab_bar_restore_target_lcd_and_layer_oem;
#endif
    gui_horizontal_tab_bar_focused_text_scrolling_handler = gui_horizontal_tab_bar_focused_scrolling_text_handler_oem;

    gui_horizontal_tab_bar_locate_focused_item(tb);

#ifdef __MMI_TOUCH_SCREEN__
    memset(&tb->pen_state, 0, sizeof(tb->pen_state));
#endif

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_register_integrated_redraw(gui_horizontal_show_status_icon);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_tab_bar
 * DESCRIPTION
 *  Apply the given theme to the horizontal tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 *  x                       [IN]            position
 *  y                       [IN]            position
 *  width                   [IN]            tab bar width
 *  tab_area_height         [IN]            tab area height
 *  hint_area_height        [IN]            hint area height
 *  tab_width               [IN]            tab width
 *  focused_tab_width       [IN]            focused tab width
 *  hint                    [IN]            hint string
 *  n_item                  [IN]            number of tabs
 *  focused_item            [IN]            focused tab index
 *  items                   [IN]            tab items data
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_tab_bar(
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
        tab_bar_item_type *items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_horizontal_tab_bar_ex(
        tb,
        x,
        y,
        width,
        tab_area_height,
        hint_area_height,
        tab_width,
        focused_tab_width,
	GUI_TAB_GAP,
        hint,
        n_item,
        focused_item,
        GUI_TAB_BAR_STYLE_DEFAULT,
        items,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_horizontal_tab_bar
 * DESCRIPTION
 *  Change the size of a tab bar
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 *  width                   [IN]            New width
 *  tab_area_height         [IN]            new tab area height
 *  hint_area_height        [IN]            new hint area height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_horizontal_tab_bar(horizontal_tab_bar *tb, S16 width, S16 tab_area_height, S16 hint_area_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->width = width;
    tb->height = tab_area_height + hint_area_height;

    tb->tab_area_height = tab_area_height;
    tb->hint_area_height = hint_area_height;

    tb->tab_area_width = (tb->width - tb->tab_gap) << 1;

    gui_horizontal_tab_bar_locate_focused_item(tb);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_horizontal_tab_bar
 * DESCRIPTION
 *  Move the tab bar to different location
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 *  x       [IN]            The new left-top corner
 *  y       [IN]            The new left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_horizontal_tab_bar(horizontal_tab_bar *tb, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->x = x;
    tb->y = y;

    tb->tab_area_x = tb->x + tb->tab_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_set_target_lcd
 * DESCRIPTION
 *  set the tab bar to target lcd
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 *  target_lcd   [IN]            The new target lcd
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_set_target_lcd(horizontal_tab_bar *tb, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_get_target_lcd
 * DESCRIPTION
 *  get the tab bar to target lcd
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 * RETURNS
 *  tab bar target lcd
 *****************************************************************************/
gdi_handle gui_horizontal_tab_bar_get_target_lcd(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return tb->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_reset_target_lcd
 * DESCRIPTION
 *  reset the tab bar
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_reset_target_lcd(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_set_target_layer
 * DESCRIPTION
 *  set the tab bar to target layer
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 *  target_layer [IN]            The new target layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_set_target_layer(horizontal_tab_bar *tb, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_get_target_layer
 * DESCRIPTION
 *  get the tab bar to target layer
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 * RETURNS
 *  tab bar target layer
 *****************************************************************************/
gdi_handle gui_horizontal_tab_bar_get_target_layer(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return tb->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_reset_target_layer
 * DESCRIPTION
 *  reset the tab bar
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_reset_target_layer(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_set_alpha_blend_layer
 * DESCRIPTION
 *  set the tab bar to alpha_blend_layer
 * PARAMETERS
 *  tb                [IN/OUT]        The tab bar control
 *  alpha_blend_layer [IN]            The new alpha_blend_layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_set_alpha_blend_layer(horizontal_tab_bar *tb, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_get_alpha_blend_layer
 * DESCRIPTION
 *  get the tab bar alpha_blend_layer
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 * RETURNS
 *  tab bar alpha_blend_layer
 *****************************************************************************/
gdi_handle gui_horizontal_tab_bar_get_alpha_blend_layer(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return tb->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_reset_alpha_blend_layer
 * DESCRIPTION
 *  reset the tab bar
 * PARAMETERS
 *  tb           [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_reset_alpha_blend_layer(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_register_hide_callback
 * DESCRIPTION
 *  register the tab bar's hide callback function
 * PARAMETERS
 *  tb            [IN/OUT]        The tab bar control
 *  hide_callback [IN]            The new hide_callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_register_hide_callback(horizontal_tab_bar *tb, void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_reset_hide_callback
 * DESCRIPTION
 *  reset the tab bar's hide callback function
 * PARAMETERS
 *  tb            [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_reset_hide_callback(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_close
 * DESCRIPTION
 *  close the tab bar , init the struct of tab bar
 * PARAMETERS
 *  tb            [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_close(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_horizontal_tab_bar_stop_blinking(tb);
    gui_title_close(&(tb->title));
#ifdef __MMI_MAINLCD_320X240__ 
    gui_cancel_timer(gui_horizontal_tab_bar_focused_text_scrolling_handler);
#else
    if(tb->style&GUI_TAB_BAR_STYLE_SCOLLING_FOCUSED_ITEM_TEXT)
    {
        gui_cancel_timer(gui_horizontal_tab_bar_focused_text_scrolling_handler);
    }
#endif

    tb->n_items = 0;
    tb->style = GUI_TAB_BAR_STYLE_DEFAULT;
    tb->target_lcd = GDI_NULL_HANDLE;
    tb->target_layer = GDI_NULL_HANDLE;
    tb->alpha_blend_layer = GDI_NULL_HANDLE;
    tb->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_set_icon_position
 * DESCRIPTION
 *  Set the icon position inside a tab item
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 *  x       [IN]            The new left-top corner
 *  y       [IN]            The new left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_set_icon_position(horizontal_tab_bar *tb, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->tab_icon_x = x;
    tb->tab_icon_y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_set_text_position
 * DESCRIPTION
 *  Set the text position inside a tab item
 * PARAMETERS
 *  tb          [IN/OUT]        The tab bar control
 *  x           [IN]            The new left-top corner
 *  y           [IN]            The new left-top corner
 *  width       [IN]            New width
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_set_text_position(horizontal_tab_bar *tb, S16 x, S16 y, S16 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tb->tab_text_x = x;
    tb->tab_text_y = y;
    tb->tab_text_width = width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_set_blinking
 * DESCRIPTION
 *  Blinking a certain tab
 * PARAMETERS
 *  tb          [IN/OUT]        The tab bar control
 *  index       [IN]            The tab item index to blink
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_set_blinking(horizontal_tab_bar *tb, S8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= tb->n_items)
    {
        return;
    }

    tb->items[index].flags |= UI_TAB_BAR_ITEM_STATE_BLINKING;

#ifdef __MMI_OP11_TAB_BAR__
    tb->items[index].blink_duration = UI_TAB_BAR_BLINKING_DURATION;
#endif /* __MMI_OP11_TAB_BAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_unset_blinking
 * DESCRIPTION
 *  Stop blinking of a certain tab
 * PARAMETERS
 *  tb          [IN/OUT]        The tab bar control
 *  index       [IN]            The tab item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_unset_blinking(horizontal_tab_bar *tb, S8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= tb->n_items)
    {
        return;
    }

    tb->items[index].flags &= ~UI_TAB_BAR_ITEM_STATE_BLINKING;

#ifdef __MMI_OP11_TAB_BAR__
    tb->items[index].blink_duration = -1;
#endif /* __MMI_OP11_TAB_BAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_tab_bar_display_range
 * DESCRIPTION
 *  Set the display range of tab bar
 * PARAMETERS
 *  tb                          [IN/OUT]        The tab bar control
 *  first_displayed_item        [IN]            The first displayed tab item
 * RETURNS
 *  Wthether the display range is changed.
 *****************************************************************************/
MMI_BOOL gui_set_horizontal_tab_bar_display_range(horizontal_tab_bar *tb, S32 first_displayed_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed_item;
    S32 previous_value = tb->first_displayed_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed_item < 0)
    {
        MMI_DBG_ASSERT(0);
        first_displayed_item = 0;
    }

    last_displayed_item = first_displayed_item + tb->n_displayable_item - 1;

    if (first_displayed_item > tb->focused_item)
    {
        first_displayed_item = tb->focused_item;
        last_displayed_item = first_displayed_item + tb->n_displayable_item - 1;
    }
    else if (last_displayed_item < tb->focused_item)
    {
        last_displayed_item = tb->focused_item;
        first_displayed_item = last_displayed_item - tb->n_displayable_item + 1;
    }

    if (last_displayed_item >= tb->n_items)
    {
        last_displayed_item = tb->n_items - 1;
        first_displayed_item = last_displayed_item - tb->n_displayable_item + 1;
        if (first_displayed_item < 0)
        {
            first_displayed_item = 0;
        }
    }

    tb->first_displayed_item = (S8) first_displayed_item;
    tb->last_displayed_item = (S8) last_displayed_item;
    

    /* always let a normal item at border */
    if((tb->focused_item == tb->last_displayed_item) && (tb->last_displayed_item != tb->n_items - 1))
    {
        tb->first_displayed_item++;
        tb->last_displayed_item++;
    }
    else if((tb->focused_item == tb->first_displayed_item) && (tb->first_displayed_item != 0))
    {
        tb->first_displayed_item--;
        tb->last_displayed_item--;
    }


    if (first_displayed_item == previous_value)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_focus_item
 * DESCRIPTION
 *  Focus to a certain tab
 * PARAMETERS
 *  tb          [IN/OUT]        The tab bar control
 *  index       [IN]            The tab item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_focus_item(horizontal_tab_bar *tb, S8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= tb->n_items || index == tb->focused_item)
    {
        return;
    }

    tb->focused_item = index;
    gui_horizontal_tab_bar_locate_focused_item(tb);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_focus_next_item
 * DESCRIPTION
 *  Focus to the next tab
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_focus_next_item(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tb->flags & UI_TAB_BAR_LOOP)
    {
        if (tb->focused_item == tb->n_items - 1)
        {
            tb->focused_item = 0;
            gui_horizontal_tab_bar_locate_focused_item(tb);
        }
        else
        {
            tb->focused_item++;
            gui_horizontal_tab_bar_locate_next_item(tb);
        }
    }
    else
    {
        if (tb->focused_item != tb->n_items - 1)
        {
            tb->focused_item++;
            gui_horizontal_tab_bar_locate_next_item(tb);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_focus_prev_item
 * DESCRIPTION
 *  Focus to the previous tab
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_focus_prev_item(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tb->flags & UI_TAB_BAR_LOOP)
    {
        if (tb->focused_item == 0)
        {
            tb->focused_item = tb->n_items - 1;
            gui_horizontal_tab_bar_locate_focused_item(tb);
        }
        else
        {
            tb->focused_item--;
            gui_horizontal_tab_bar_locate_prev_item(tb);
        }
    }
    else
    {
        if (tb->focused_item != 0)
        {
            tb->focused_item--;
            gui_horizontal_tab_bar_locate_prev_item(tb);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_focus_first_item
 * DESCRIPTION
 *  Focus to the first tab
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_focus_first_item(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_item(tb, 0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_focus_last_item
 * DESCRIPTION
 *  Focus to the last tab
 * PARAMETERS
 *  tb      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_focus_last_item(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_item(tb, (S8) (tb->n_items - 1));
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_is_item_displayed
 * DESCRIPTION
 *  Check if a tab bar item
 * PARAMETERS
 *  tb          [IN]        The tab bar control
 *  index       [IN]        Index of tab item
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL gui_horizontal_tab_bar_is_item_displayed(horizontal_tab_bar *tb, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= tb->first_displayed_item && index <= tb->last_displayed_item)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_start_blinking
 * DESCRIPTION
 *  Animate the blinking tabs
 * PARAMETERS
 *  tb      [IN]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_start_blinking(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_horizontal_tab_bar = tb;
    gui_start_timer(UI_TAB_BAR_BLINKING_TIME, gui_horizontal_tab_bar_blink_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_stop_blinking
 * DESCRIPTION
 *  Stop animation of the blinking tabs
 * PARAMETERS
 *  tb      [IN]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_stop_blinking(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_horizontal_tab_bar_blink_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  gui_setup_tab_item
 * DESCRIPTION
 *  Setup the data of a tab item
 * PARAMETERS
 *  item                [IN]        tab item
 *  icon                [IN]        new icon
 *  text                [IN]        new hint
 *  enable_blinking     [IN]        enable blink or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_tab_item(tab_bar_item_type *item, PU8 icon, UI_string_type text, MMI_BOOL enable_blinking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->text = text;
    item->icon = icon;
    if (enable_blinking)
    {
        item->flags = UI_TAB_BAR_ITEM_STATE_BLINKING;
    #ifdef __MMI_OP11_TAB_BAR__
        item->blink_duration = UI_TAB_BAR_BLINKING_DURATION;
    #endif /* __MMI_OP11_TAB_BAR__ */
    }
    else
    {
        item->flags = UI_TAB_BAR_ITEM_STATE_NORMAL;
    #ifdef __MMI_OP11_TAB_BAR__
        item->blink_duration = UI_TAB_BAR_BLINKING_DURATION;
    #endif /* __MMI_OP11_TAB_BAR__ */
    }
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_redraw_left_button
 * DESCRIPTION
 *
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_redraw_left_button(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_lcd_handle = gui_horizontal_tab_bar_setup_target_lcd_and_layer(tb);
    gui_lock_double_buffer();
    if (tb->first_displayed_item == tb->focused_item)
    {
        gui_horizontal_tab_bar_show_focused_item(tb);
    }
    else
    {
        gui_horizontal_tab_bar_show_item(tb, tb->first_displayed_item);
    #ifdef UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER
        if (tb->focused_item == tb->first_displayed_item + 1)
        {
            /* We need to redisplay focused tab because it might overlap with other tabs */
            gui_horizontal_tab_bar_show_focused_item(tb);
        }
    #endif /* UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER */
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(tb->tab_area_x, tb->y, tb->tab_area_x + tb->tab_area_width - 1, tb->y + tb->tab_area_height - 1);
    gui_horizontal_tab_bar_restore_target_lcd_and_layer(tb, old_lcd_handle);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_redraw_right_button
 * DESCRIPTION
 *
 * PARAMETERS
 *  tb                      [IN/OUT]        The tab bar control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_tab_bar_redraw_right_button(horizontal_tab_bar *tb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_lcd_handle = gui_horizontal_tab_bar_setup_target_lcd_and_layer(tb);
    gui_lock_double_buffer();
    if (tb->last_displayed_item == tb->focused_item)
    {
        gui_horizontal_tab_bar_show_focused_item(tb);
    }
    else
    {
        gui_horizontal_tab_bar_show_item(tb, tb->last_displayed_item);
    #ifdef UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER
        if (tb->focused_item == tb->last_displayed_item - 1)
        {
            /* We need to redisplay focused tab because it might overlap with other tabs */
            gui_horizontal_tab_bar_show_focused_item(tb);
        }
    #endif /* UI_TAB_BAR_FOCUSED_ITEM_OVERLAP_OTHER */
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(tb->tab_area_x, tb->y, tb->tab_area_x + tb->tab_area_width - 1, tb->y + tb->tab_area_height - 1);
    gui_horizontal_tab_bar_restore_target_lcd_and_layer(tb, old_lcd_handle);
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_tab_bar_translate_pen_event
 * DESCRIPTION
 *
 * PARAMETERS
 *  tb                  [IN/OUT]        The tab bar control
 *  pen_event           [IN]            pen event
 *  x                   [IN]            pen position
 *  y                   [IN]            pen position
 *  tab_event           [IN]            tab event
 *  tab_event_param     [IN]            tab event param
 * RETURNS
 *
 *****************************************************************************/
BOOL gui_horizontal_tab_bar_translate_pen_event(
        horizontal_tab_bar *tb,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_tab_bar_pen_enum *tab_event,
        gui_pen_event_param_struct *tab_event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    S32 in_left_button = 0, in_right_button = 0;
    S32 item_index = -1;
#ifndef __MMI_FTE_SUPPORT__
    gui_tab_bar_pen_state_struct *pen_state;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tb->flags & UI_TAB_BAR_DISABLE_PEN)
    {
        return MMI_FALSE;
    }

    
    ret = MMI_TRUE;
    *tab_event = GUI_TAB_BAR_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(tab_event_param);

/* In FTE project not check whether in left button or right button 
 * Otherwise, when pen event in button area, the item won't respone the pen event */
#ifndef __MMI_FTE_SUPPORT__
    pen_state = &tb->pen_state;
    if (PEN_CHECK_BOUND(
            x,
            y,
            pen_state->left_button_x,
            pen_state->left_button_y,
            pen_state->left_button_width,
            pen_state->left_button_height))
    {
        in_left_button = 1;
    }
    else if (PEN_CHECK_BOUND(
                x,
                y,
                pen_state->right_button_x,
                pen_state->right_button_y,
                pen_state->right_button_width,
                pen_state->right_button_height))
    {
        in_right_button = 1;
    }
    else if (PEN_CHECK_BOUND(x, y, tb->tab_area_x, tb->y, tb->tab_area_width, tb->tab_area_height))
#else /* __MMI_FTE_SUPPORT__ */
    if (PEN_CHECK_BOUND(x, y, tb->tab_area_x, tb->y, tb->tab_area_width, tb->tab_area_height))
#endif /* __MMI_FTE_SUPPORT__ */
    {
        item_index = tb->first_displayed_item + ((x - tb->tab_area_x) / tb->tab_width);
    }

    if (item_index >= tb->n_items)
    {
        return MMI_FALSE;
    }

    if (tb->items[item_index].flags & UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED)
    {
        return MMI_FALSE;
    }

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (in_left_button)
            {
                item_index = tb->focused_item - 1;
                if (item_index < 0)
                {
                    item_index = tb->n_items - 1;
                }
                tb->left_button_pressed = 1;
                gui_horizontal_tab_bar_redraw_left_button(tb);
                
                *tab_event = GUI_TAB_BAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(tab_event_param, item_index);
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            else if (in_right_button)
            {
                item_index = tb->focused_item + 1;
                if (item_index >= tb->n_items)
                {
                    item_index = 0;
                }
                tb->right_button_pressed = 1;
                gui_horizontal_tab_bar_redraw_right_button(tb);
                
                *tab_event = GUI_TAB_BAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(tab_event_param, item_index);
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            else if (item_index >= 0)
            {
                *tab_event = GUI_TAB_BAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(tab_event_param, item_index);
				gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
            
            break;

        case MMI_PEN_EVENT_UP:
            if (tb->left_button_pressed)
            {
                tb->left_button_pressed = 0;
                gui_horizontal_tab_bar_redraw_left_button(tb);
            }
            else if (tb->right_button_pressed)
            {
                tb->right_button_pressed = 0;
                gui_horizontal_tab_bar_redraw_right_button(tb);
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (in_left_button)
            {
                if (!tb->left_button_pressed)
                {
                    tb->left_button_pressed = 1;
                    gui_horizontal_tab_bar_redraw_left_button(tb);
                }
            }
            else
            {
                if (tb->left_button_pressed)
                {
                    tb->left_button_pressed = 0;
                    gui_horizontal_tab_bar_redraw_left_button(tb);
                }
            }

            if (in_right_button)
            {
                if (!tb->right_button_pressed)
                {
                    tb->right_button_pressed = 1;
                    gui_horizontal_tab_bar_redraw_right_button(tb);
                }
            }
            else
            {
                if (tb->right_button_pressed)
                {
                    tb->right_button_pressed = 0;
                    gui_horizontal_tab_bar_redraw_right_button(tb);
                }
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            if (in_left_button)
            {
                item_index = tb->focused_item - 1;
                if (item_index < 0)
                {
                    item_index = tb->n_items - 1;
                }
                
                *tab_event = GUI_TAB_BAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(tab_event_param, item_index);
            }
            else if (in_right_button)
            {
                item_index = tb->focused_item + 1;
                if (item_index >= tb->n_items)
                {
                    item_index = 0;
                }
                
                *tab_event = GUI_TAB_BAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(tab_event_param, item_index);
            }
            else if (item_index >= 0)
            {
                *tab_event = GUI_TAB_BAR_PEN_JUMP_TO_I;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(tab_event_param, item_index);
            }
            
            break;

        case MMI_PEN_EVENT_ABORT:
            if (tb->left_button_pressed)
            {
                tb->left_button_pressed = 0;
                gui_horizontal_tab_bar_redraw_left_button(tb);
            }
            else if (tb->right_button_pressed)
            {
                tb->right_button_pressed = 0;
                gui_horizontal_tab_bar_redraw_right_button(tb);
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */


