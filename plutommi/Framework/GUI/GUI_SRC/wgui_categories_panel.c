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
 * wgui_categories_panel.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Categories with panel component
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
#include "stdC.h"
#include "CustThemesRes.h"
#include "gui_font_size.h"

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_HID_BQP_SUPPORT__)

#ifdef __GDI_MEMORY_PROFILE_2__
#include "gdi_layer.h"
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

/*RHR*/
    #include "MMIDataType.h"
    #include "gui_buttons.h"
    #include "gui_panel.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_draw_manager.h"
    #include "gdi_include.h"
    #include "gui_typedef.h"
    #include "gui.h"
    #include "gui_data_types.h"
    #include "wgui_title.h"
    #include "gui_themes.h"
    #include "wgui_include.h"
    #include "wgui_categories_panel.h"
    #include "CustDataRes.h"
    #include "kal_general_types.h"
    #include "wgui_categories_util.h"
    #include "wgui_inputs.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_enum.h"
    #include "mmi_frm_events_gprot.h"

/*-------------------------------
External Global variables
-------------------------------*/
//extern BOOL r2lMMIFlag;

/*-------------------------------
External Global Functions
-------------------------------*/
extern icontext_button MMI_softkeys[];

/*-------------------------------
Global variables
-------------------------------*/
#ifndef __GDI_MEMORY_PROFILE_2__
static MMI_ID_TYPE wgui_cat95_panel_bg_id;
#endif
static S32 wgui_cat95_panel_handle;


/***************************************************************************** 
* Local Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_general_key_handler
 * DESCRIPTION
 *  wgui_cat95_general_key_handler
 *  
 *  Calendar hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    gui_panel_struct* panel;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    panel = dm_get_panel(wgui_cat95_panel_handle);
    gui_panel_general_key_handler(panel, keycode, keytype);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_hide_left_softkey
 * DESCRIPTION
 *  Hides the left softkey
 *  
 *  Calendar hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_hide_left_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_softkeys[MMI_LEFT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2,
        UI_device_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        MMI_softkeys[MMI_LEFT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width + 2,
        UI_device_height - 1, 
        GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_draw_id(0, 0, wgui_cat95_panel_bg_id);
#endif 
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_hide_right_softkey
 * DESCRIPTION
 *  Hides the right softkey
 *  
 *  Calendar hide right softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_hide_right_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2,
        UI_device_height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width + 2,
        UI_device_height - 1, 
        GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_draw_id(0, 0, wgui_cat95_panel_bg_id);
#endif 
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat95_draw_title
 * DESCRIPTION
 *  Displays the category95 screen title
 * PARAMETERS
 *  x                   [IN]        x of the top-left of the title
 *  y            [IN]        y of the top-left of the title
 *  clip_x1       [IN]        x1 of the clip area
 *  clip_y1           [IN]        y1 of the clip area
 *  clip_x2      [IN]        x2 of the clip area
 *  clip_y2          [IN]        y2 of the clip area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat95_draw_title(
                    S32 x, 
                    S32 y, 
                    S32 clip_x1, 
                    S32 clip_y1, 
                    S32 clip_x2, 
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width , string_height;
    S32 string_x, string_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gui_measure_string(MMI_title_string, &string_width, &string_height);
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_set_text_border_color(*current_MMI_theme->title_text_border_color);

    string_x = clip_x1 + (clip_x2 - clip_x1 + 1 - string_width)>>1;
    if (mmi_fe_get_r2l_state())
    {
        string_x = string_x + string_width - 1;
    }
    string_y = clip_y1 + (clip_y2 - clip_y1 + 1 - string_height)>>1;
    gui_move_text_cursor(string_x, string_y);
    gui_print_bordered_text(MMI_title_string);

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory95Screen
 * DESCRIPTION
 *  Exits the category95 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory95Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (!(defined(__OP01__) && (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X400__))) && !defined(__MMI_FTE_SUPPORT__))
    enable_softkey_background();
#endif /* !defined(__OP01__) && !defined(__MMI_FTE_SUPPORT__) */
}


/* For detail description, please refer to wgui_categories_panel.h */
void ShowCategory95Screen(
        U8 *title,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        MMI_ID_TYPE bg_id,
        wgui_cat95_panel_element_struct *element_list,
        S32 num_of_element,
        S32 focused_element,
        U32 repeat_period,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    gui_util_painter_struct bg_painter, disable_painter, off_painter, on_painter, down_painter, title_painter;
    S32 current_focus = focused_element;
    S32 i;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    dm_add_softkey(
        (UI_string_type)GetString(left_softkey), (PU8)GetImage(left_softkey_icon),
        (UI_string_type)GetString(right_softkey), (PU8)GetImage(right_softkey_icon));

#ifndef __GDI_MEMORY_PROFILE_2__
    wgui_cat95_panel_bg_id = bg_id;
#endif

#if (!(defined(__OP01__) && (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X400__))) && !defined(__MMI_FTE_SUPPORT__))
    disable_softkey_background();
    register_hide_left_softkey(wgui_cat95_hide_left_softkey);
    register_hide_right_softkey(wgui_cat95_hide_right_softkey);
#endif /* !defined(__OP01__) && !defined(__MMI_FTE_SUPPORT__) */

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#else /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
    #ifdef WGUI_STATUS_ICON_SHOW_V_BAR 
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_V_BAR);
    #endif /*WGUI_STATUS_ICON_SHOW_V_BAR*/
#endif /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */

/* background */    
#ifdef __GDI_MEMORY_PROFILE_2__
    gui_util_painter_create_transparent(&bg_painter);
    dm_add_image(get_image(bg_id), NULL, NULL);
#else 
    gui_util_painter_create_imageid(&bg_painter, bg_id);
#endif 
    wgui_cat95_panel_handle = dm_add_panel(0, 0, UI_device_width, UI_device_height, bg_painter, MMI_TRUE, repeat_period);

/* title */
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    dm_add_title((UI_string_type)title, NULL);
#else /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
    MMI_title_string = (UI_string_type)title;
    gui_util_painter_create_callback(&title_painter, wgui_cat95_draw_title);
    dm_add_panel_element(
            wgui_cat95_panel_handle,
            0,
            0,
            MMI_title_width,
            MMI_title_height,
            KEY_INVALID,
            NULL,
            NULL,
            NULL,
            title_painter,
            title_painter,
            title_painter,
            title_painter,
            MMI_FALSE);
#endif /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */

/* button */
    for(i = 0; i < num_of_element; i++)
    {
        gui_util_painter_create_imageid(&disable_painter, element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, element_list[i].down_imageid);
        dm_add_panel_element(
            wgui_cat95_panel_handle,
            element_list[i].x,
            element_list[i].y,
            element_list[i].width,
            element_list[i].height,
            element_list[i].keycode,
            element_list[i].down_event_callback,
            element_list[i].up_event_callback,
            element_list[i].repeat_event_callback,
            off_painter,
            on_painter,
            down_painter,
            disable_painter,
            MMI_FALSE);
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        dm_set_panel_enable_element(wgui_cat95_panel_handle, i, element_list[i].enabled, MMI_FALSE);
#else /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
        dm_set_panel_enable_element(wgui_cat95_panel_handle, i+1, element_list[i].enabled, MMI_FALSE);
#endif /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
    }

    h_flag = set_panel_category_history(MMI_CATEGORY95_ID, history_buffer);
    if(!h_flag)
    {
        dm_set_panel_element_focus(wgui_cat95_panel_handle, current_focus, MMI_FALSE);
    }

    dm_register_panel_keys(wgui_cat95_panel_handle, wgui_cat95_general_key_handler);
    
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SET_AS_ABM_LAYER;

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory95Screen;

#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY95_ID;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif
#endif
/*
#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_HID_BQP_SUPPORT__)
*/


