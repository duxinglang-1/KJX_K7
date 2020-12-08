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
 *   wgui_categories_notification.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_windows.h"
#include "gdi_include.h"
#include "gui_themes.h"
#include "gui.h"
#include "gui_theme_struct.h"
#include "gui_typedef.h"
#include "wgui_inputs.h"
#include "gui_data_types.h"
#include "ScreenRotationGprot.h"
#include "wgui_categories_util.h"
#include "wgui_draw_manager.h"
#include "wgui.h"
#include "wgui_categories.h"
#include "wgui_include.h"
#include "wgui_title.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_enum.h"
#include "gui_inputs.h"
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
U8 Category154Align = 0;
static scrolling_text scroll_text_cat154;
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/

/* category 154 message 1 y postition */
S32 category_154_message1_y = 0;

/* category 154 message 2 y position  */
S32 category_154_message2_y = 0;

static MMI_BOOL wgui_cat154_owner_draw_softkey = MMI_FALSE;

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
#define WGUI_CAT154_TEXT_GAP 2
#else
#define WGUI_CAT154_TEXT_GAP 1
#endif

void wgui_cat154_set_owner_draw_softkey(MMI_BOOL is_draw_softkey)
{
     wgui_cat154_owner_draw_softkey = is_draw_softkey;
}
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat154_scrolling_timer
 * DESCRIPTION
 *  category 154 scrolling timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat154_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&scroll_text_cat154);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat154_scrolling_text_draw_background
 * DESCRIPTION
 *  Draw category 154 scrolling text draw background
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat154_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_cat154_draw_controlarea
 * DESCRIPTION
 *  redraw 154 control area
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat154_draw_controlarea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, h1, w2, h2, x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();

#ifdef __MMI_MAINLCD_128X64__
	wgui_status_icon_bar_move(
        WGUI_STATUS_ICON_BAR_H_BAR, 
        0, 
        0);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
	wgui_status_icon_bar_update();
#endif
	
    gui_set_font(current_UI_theme->multi_line_input_box_theme->text_font);
    gui_measure_string(MMI_message_string, &w1, &h1);
    gui_measure_string(MMI_message_string2, &w2, &h2);
    gui_set_text_color(UI_COLOR_BLACK);
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    if (Category154Align)
    {
        x = WGUI_CAT154_TEXT_GAP;
    }
    else
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
    {
        x = (UI_device_width >> 1) - (w1 >> 1);
        if (x < WGUI_CAT154_TEXT_GAP)
        {
            x = WGUI_CAT154_TEXT_GAP;
        }
    }

    if (mmi_fe_get_r2l_state())
    {
        if(w1 > (UI_device_width - 2*WGUI_CAT154_TEXT_GAP))
        {
            x = UI_device_width - WGUI_CAT154_TEXT_GAP;
        }
        else
        {
            x += w1;
        }
    }

#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    if(w1 > (UI_device_width - 2*WGUI_CAT154_TEXT_GAP))
    {
        gui_create_scrolling_text(
            &scroll_text_cat154,
            x,
            category_154_message1_y,
            (UI_device_width - 2*WGUI_CAT154_TEXT_GAP),
            h1,
            MMI_message_string,
            wgui_cat154_scrolling_timer,
            wgui_cat154_scrolling_text_draw_background,
            gui_color(0, 0, 0),
            gui_color(255, 255, 255));
        gui_show_scrolling_text(&scroll_text_cat154);
    }
    else
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
    {
        gui_move_text_cursor(x, category_154_message1_y);
        gui_set_line_height(h1);
        gui_print_text(MMI_message_string);
    }
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    if (Category154Align)
    {
        x = WGUI_CAT154_TEXT_GAP;
    }
    else
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
    {
        x = (UI_device_width >> 1) - (w2 >> 1);
        if (x < WGUI_CAT154_TEXT_GAP)
        {
            x = WGUI_CAT154_TEXT_GAP;
        }
    }

    if (mmi_fe_get_r2l_state())
    {
        if (gui_get_string_width((UI_string_type) MMI_message_string2) >= UI_device_width)
        {
            x = UI_device_width - WGUI_CAT154_TEXT_GAP;
        }
        else
        {
            x += gui_get_string_width((UI_string_type) MMI_message_string2);
        }
    }

    gui_print_truncated_text(x, category_154_message2_y, UI_device_width - 2*WGUI_CAT154_TEXT_GAP, MMI_message_string2);
#ifdef __MMI_SCREEN_ROTATE__	
	if(mmi_frm_is_screen_width_height_swapped())
	{
		gdi_layer_set_clip(
			0,
			(MMI_title_y + MMI_title_height) + 1,
			UI_device_width - 1,
			UI_device_height - 1);
	}
	else
#endif
	{
    gdi_layer_set_clip(
        0,
        (MMI_title_y + MMI_title_height) + 1,
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1);
	}
    wgui_show_transparent_animation();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat154_refresh
 * DESCRIPTION
 *  refresh category154 if message change
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat154_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(dm_get_layer_handle(1));
	gdi_layer_push_clip();
	gdi_draw_solid_rect(0,
		      (MMI_title_y + MMI_title_height) + 1,
		       UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1, GDI_COLOR_TRANSPARENT);
	gdi_anim_stop_all();
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    gui_scrolling_text_stop(&scroll_text_cat154);
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
	wgui_cat154_draw_controlarea();
	gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
	gdi_layer_blt_previous(0, (MMI_title_y + MMI_title_height) + 1,
		UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  DrawCate154CategoryControlArea
 * DESCRIPTION
 *  redraw 154 control area
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw     
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate154CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_cat154_draw_controlarea();	
}

#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
/*****************************************************************************
 * FUNCTION
 *  Setcategory154LeftAlign
 * DESCRIPTION
 *  Set content of category154 left alignment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Setcategory154LeftAlign(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category154Align = 1;
}
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  ChangeCategory154Data
 * DESCRIPTION
 *  Change data of category154
 * PARAMETERS
 *  message1            [IN]        Data pointer of message1
 *  message2            [IN]        Data pointer of message2
 *  message_icon        [IN]        Id of message icon
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeCategory154Data(U8 *message1, U8 *message2, U16 message_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, h1, w2, h2, w3, h3, y, th, rh;
    PU8 image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_message_string = (UI_string_type) message1;
    MMI_message_string2 = (UI_string_type) message2;
    gui_set_font(current_UI_theme->multi_line_input_box_theme->text_font);
    gui_measure_string(MMI_message_string, &w1, &h1);
    gui_measure_string(MMI_message_string2, &w2, &h2);
    image = get_image(message_icon);
    if (wgui_switch_title_with_status_bar == 0)
    {
        gui_measure_image(image, &w3, &h3);
        th = h1 + h2 + h3 + 2;
        y = (MMI_title_y + MMI_title_height) + 1 + ((MMI_content_height - 1) >> 1) - (th >> 1);
        if (th < MMI_content_height)
        {
            rh = (MMI_content_height - th) >> 2;
        }
        else
        {
            rh = 0;
        }
        y -= rh;
        if (y < ((MMI_title_y + MMI_title_height) + 1))
        {
            y = (MMI_title_y + MMI_title_height) + 1;
        }
        category_154_message1_y = y;
        category_154_message2_y = y + h1;
        y += h1 + h2 + rh + 2;
    }
    else
    {
        category_154_message1_y = CAT154_IMAGE_Y - h1 - 1 - h2 - 2;
        category_154_message2_y = CAT154_IMAGE_Y - h2 - 2;
        y = CAT154_IMAGE_Y;
    }

    wgui_set_animation_image_y((UI_device_width >> 1), y, image);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory154Screen
 * DESCRIPTION
 *  Displays the Message Received screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  message1                [IN]        Notification message 1
 *  message2                [IN]        Notification message 2
 *  message_icon            [IN]        Image to show
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory154Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *message1,
        U8 *message2,
        U16 message_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 w1, h1, w2, h2, w3, h3, y, th, rh;
    PU8 image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_reset_context();
    UI_UNUSED_PARAMETER(history_buffer);
    gdi_layer_lock_frame_buffer();
    wgui_title_set_menu_shortcut_number(-1);
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();
#ifdef __MMI_MAINLCD_128X64__
	message_icon = 0;
#endif
    if (title == 0)
    {
        wgui_switch_title_with_status_bar = 1;
        ShowStatusIconsTitle();
    }
    else
    {
        MMI_title_string = get_string(title);
        MMI_title_icon = get_image(title_icon);
        wgui_switch_title_with_status_bar = 0;
    }
    MMI_message_string = (UI_string_type) message1;
    MMI_message_string2 = (UI_string_type) message2;
    gui_set_font(current_UI_theme->multi_line_input_box_theme->text_font);
    gui_measure_string(MMI_message_string, &w1, &h1);
    gui_measure_string(MMI_message_string2, &w2, &h2);
    image = get_image(message_icon);
    if (wgui_switch_title_with_status_bar == 0)
    {
        gui_measure_image(image, &w3, &h3);
        th = h1 + 1 + h2 + 2 + h3;
        y = (MMI_title_y + MMI_title_height) + 1 + ((MMI_content_height - 1) >> 1) - (th >> 1);
        if (th < MMI_content_height)
        {
            rh = (MMI_content_height - th) >> 2;
        }
        else
        {
            rh = 0;
        }
        y -= rh;
        if (y < ((MMI_title_y + MMI_title_height) + 1))
        {
            y = (MMI_title_y + MMI_title_height) + 1;
        }
        category_154_message1_y = y;
        category_154_message2_y = y + h1 + 1;
        y += h1 + 1 + h2 + rh + 2;
    }
    else
    {
        category_154_message1_y = CAT154_IMAGE_Y - h1 - 1 - h2 - 2;
        category_154_message2_y = CAT154_IMAGE_Y - h2 - 2;
        y = CAT154_IMAGE_Y;
        if(image == NULL)  /* for Vcard */
        {
            category_154_message1_y = MMI_title_y + MMI_content_height/2;
            category_154_message2_y = MMI_title_y + MMI_content_height/2 + h1 + 2;
        }
    }
    wgui_set_animation_image_y((UI_device_width >> 1), y, image);

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory154Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_register_category_controlled_callback(DrawCate154CategoryControlArea);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND_COLOR | DM_SET_NEW_LAYER_ACTIVE;
    if((left_softkey == 0) && (left_softkey_icon == 0) && (right_softkey == 0) && (right_softkey_icon == 0))
    {
        if(!wgui_cat154_owner_draw_softkey)
        {
	        dm_data.s32flags |= DM_NO_SOFTKEY;
        }
    }
    if (wgui_switch_title_with_status_bar == 1)
    {
        dm_data.s32CatId = MMI_CATEGORY154_STATUS_ICON_ID;
#ifdef __MMI_MAINLCD_128X64__
		dm_data.s32flags |= DM_NO_STATUS_BAR; // draw by self.
#endif
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY154_ID;
    }
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory154Screen
 * DESCRIPTION
 *  Exits the Message Received screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory154Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_switch_title_with_status_bar)
    {
        wgui_status_icon_bar_reset();
        wgui_switch_title_with_status_bar = 0;
    }
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    gui_scrolling_text_stop(&scroll_text_cat154);
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
    wgui_cat154_set_owner_draw_softkey(MMI_FALSE);
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    Category154Align = 0;
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
    MMI_message_string = NULL;
    MMI_message_string2 = NULL;
    gui_hide_animations();
}


static void wgui_cat9002_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_BLACK);
}

static void wgui_cat9002_exit(void)
{
    
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9002_show
 * DESCRIPTION
 *  Show category9 screen (usb animated icon)
 * PARAMETERS
 *  image_icon_1        [IN]       usb text image
 *  image_icon_2         [IN]        usb animation image
 *  history_buffer          [IN]        History buffer
 *  flags                   [IN]   reserved
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9002_show(U16 image_icon_1, U16 image_icon_2, U8 *history_buffer, U8 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    UI_UNUSED_PARAMETER(history_buffer);
    gdi_layer_lock_frame_buffer();
    wgui_title_set_menu_shortcut_number(-1);
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    
    dm_add_image(get_image(image_icon_1), NULL, NULL);
    dm_add_image(get_image(image_icon_2), NULL, NULL);


    gdi_layer_unlock_frame_buffer();
    dm_register_category_controlled_callback(wgui_cat9002_draw_ctrl_area);

    wgui_cat_setup_category_default_history(MMI_CAT9002_ID, 0, wgui_cat9002_exit);
    dm_redraw_category_screen();
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory9Screen
 * DESCRIPTION
 *  Displays the category9 screen
 * PARAMETERS
 *  message             [IN]        Message string
 *  message_icon        [IN]        Message icon
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory9Screen(U16 message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_reset_context();
    UI_UNUSED_PARAMETER(history_buffer);
    gdi_layer_lock_frame_buffer();
    entry_full_screen();
    wgui_title_set_menu_shortcut_number(-1);
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();

    if (message != 0)
    {
        MMI_message_string = (UI_string_type) get_string(message);
        l = gui_strlen(MMI_message_string);
        create_multiline_inputbox_set_buffer(MMI_message_string, l, l, 0);
        MMI_multiline_inputbox.normal_text_color = gui_color(0, 0, 0);
        MMI_multiline_inputbox.flags |=
            (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
             UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR);
    }
    else
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    dm_add_image(get_image(message_icon), NULL, NULL);

    gdi_layer_unlock_frame_buffer();

    wgui_cat_setup_category_default_history(MMI_CATEGORY9_ID, DM_CLEAR_SCREEN_BACKGROUND_COLOR, UI_dummy_function);

    dm_redraw_category_screen();

}   /* end of ShowCategory9Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory9Screen
 * DESCRIPTION
 *  Exits the category9 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory9Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();
}   /* end of ExitCategory9Screen */


