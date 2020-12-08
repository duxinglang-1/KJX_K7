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
 *   wgui_categories_search.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#include "Wgui_softkeys.h"
#include "Wgui_inputs_internal.h"

//RHR
    #include "MMIDataType.h"
    #include "wgui_categories_text_viewer.h"
    #include "wgui_draw_manager.h"
    #include "gui_data_types.h"
    #include "gdi_include.h"
    #include "wgui_categories_util.h"
    #include "gui_typedef.h"
    #include "wgui_include.h"
    #include "wgui_title.h"
    #include "wgui_inputs.h"
    #include "gui.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "gui_inputs.h"
    #include "gui_config.h"
    #include "ImeGprot.h"
    #include "CustThemesRes.h"
    #include "gui_themes.h"
    #include "mmi_frm_events_gprot.h"
    #include "wgui_categories_enum.h"
    #include "kal_general_types.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "gui_title.h"
    #include "wgui_categories_list.h"
    #include "app_mem.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "string.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "gui_buttons.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "gui_switch.h"
    #include "wgui.h"
    #include "wgui_categories_CM.h"
    #include "gui_virtual_keyboard_language_type.h"
    #include "wgui_categories_inputs.h"
    #include "wgui_touch_screen.h"
    #include "mmi_frm_mem_gprot.h"
    #include "Unicodexdcl.h"
    #include "PixcomFontEngine.h"
    #include "lcd_if.h"
    #include "gui_windows.h"
    #include "ImmProt.h"
    #include "wgui_fixed_menuitems.h"
    #include "wgui_fixed_menus.h"

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static U8 idle_scr_bg_opacity;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 

static U8 *g_wgui_cat7_string_buf = NULL;
static U32 g_wgui_cat_special_style_flags = 0;

/* for category 75 and 77 */
#ifdef __MMI_EBOOK_READER__
static U8 old_font_size = 0;
static S8 old_font_style = 0;
#endif /* __MMI_EBOOK_READER__ */
/* text viewer category slide buttons */
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
wgui_cat_slide_control_cntx *g_wgui_cat_slide_control_ptr = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

#if defined(__SOCIAL_NETWORK_SUPPORT__)
static wgui_cat_sns_title* g_cat74_sns_title = NULL;
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#ifdef MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE
U16 show_icon1_ID = 0;
U16 show_icon2_ID = 0;
U8*  show_title_text = NULL;
U32  show_flag = 0;
void wgui_cat_text_viewer_setup_title_change(U16 icon_ID, U16 icon2_ID, U8 *text, U32 flag);
#endif
/***************************************************************************** 
* Local Function
*****************************************************************************/
static void wgui_cat_text_viewer_show_internal(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        MMI_BOOL need_scrollbar,
        MMI_BOOL is_r2l_display,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer,
        S32 cat_id);
static void wgui_cat_text_viewer_show_internal_by_res_id(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S8 highlighted_tab,
        MMI_BOOL need_scrollbar,
        MMI_BOOL is_r2l_display,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer,
        S32 cat_id);

void wgui_cat_ml_setup_image_res(PU8 header_img, PU8 footer_img);

void wgui_cat_ml_setup_image(CHAR* header_img, CHAR* footer_img);


#if defined(__SOCIAL_NETWORK_SUPPORT__)
static void wgui_cat74_draw_sns_title(dm_coordinates *coordinate);
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory21Screen
 * DESCRIPTION
 *  Displays the category21 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  message                 [IN]        Notification message (string. Not string ID)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory21Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type msg = get_string(message);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);
    wgui_cat_text_viewer_show_internal_by_res_id(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            0,
            MMI_TRUE,
            MMI_FALSE,
            (U8*)msg,
            gui_strlen(msg),
            NULL,
            MMI_CATEGORY21_ID);
}   /* end of ShowCategory21Screen */


/*****************************************************************************
* FUNCTION
*  wgui_cat074_change_text
* DESCRIPTION
*  Change the content of string used in category74.
* PARAMETERS
*  new_string      [IN]        New content of string
* RETURNS
*  void
*****************************************************************************/
void wgui_cat074_change_text(U8 *new_string, S32 buffer_size, MMI_BOOL is_reset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_clipboard_state())
    {
        mmi_imc_clipboard_go_back_to_initial();
    }
#endif

    ChangeCategory79MessageString(new_string, buffer_size, is_reset_y, MMI_TRUE, MMI_FALSE);

    /* Disable clipboard */
    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);
} 


/*****************************************************************************
* FUNCTION
*  wgui_cat79_get_visible_count_bg
* DESCRIPTION
*  typesetting without display.
* PARAMETERS
*  new_string      [IN]        New content of string
*  buffer_size     [IN]        string buffer size
*  scroll_flag     [IN]        Need scroll-bar or not
*  start           [OUT]       The first character in visibel area
*  end             [OUT]       The last character in visibel area
* RETURNS
*  void
*****************************************************************************/
void wgui_cat79_get_visible_count_bg(
        U8 *new_string, 
        S32 buffer_size, 
        MMI_BOOL scroll_flag,
        S32 *start, 
        S32 *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box cat74_inputbox;
    dm_coordinates gui_multiline_get_coordinates;
    S32 l;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    l = gui_strlen((UI_string_type) new_string);

    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY74_ID,
        DM_MULTILINE_INPUTBOX1,
        -1,
        &gui_multiline_get_coordinates);
    
    gui_create_multi_line_input_box_set_buffer(
        &cat74_inputbox,
        gui_multiline_get_coordinates.s16X,
        gui_multiline_get_coordinates.s16Y,
        gui_multiline_get_coordinates.s16Width,
        gui_multiline_get_coordinates.s16Height,
        (UI_string_type) new_string,
        buffer_size * 2,
        (l + 1) * 2,
        0);

    if (scroll_flag == MMI_FALSE)
    {
        cat74_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        cat74_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_ONLY_VISIBLE_LINE;
    }
    cat74_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE | UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW);

    gui_show_multi_line_input_box(&cat74_inputbox);
    cat74_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    *start = cat74_inputbox.visible_start;
    *end = cat74_inputbox.visible_end;
    return; 
}


/*****************************************************************************
* FUNCTION
*  ChangeCategory79MessageString
* DESCRIPTION
*  Change the content of string used in category74.
* PARAMETERS
*  new_string      [IN]        New content of string
*  buffer_size     [IN]        string buffer size
*  is_reset_y      [IN]        whether to keep the position of scroll-bar
* RETURNS
*  void
*****************************************************************************/
void ChangeCategory79MessageString(U8 *new_string, S32 buffer_size, MMI_BOOL is_reset_y, MMI_BOOL need_scrollbar, MMI_BOOL is_r2l_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;
    S32 old_text_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
#ifdef __MMI_TOUCH_SCREEN__

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_all_line_update();
#endif /* GUI_INPUT_BOX_CACHE_SUPPORT */

    gui_multi_line_input_box_scroll_timer_hdlr();
#endif /* __MMI_TOUCH_SCREEN__ */

    l = gui_strlen((UI_string_type) new_string);
    old_text_offset = MMI_multiline_inputbox.text_offset_y;
    
    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.height,
        (UI_string_type) new_string,
        buffer_size * 2,
        (l + 1) * 2,
        0);
    
    if (is_reset_y == MMI_FALSE)
    {
        MMI_multiline_inputbox.text_offset_y = old_text_offset;
    }
    
    if (need_scrollbar == MMI_FALSE)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_ONLY_VISIBLE_LINE;
    }

    MMI_multiline_inputbox.override_direction = is_r2l_display ? 2 : 1;
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);

#if defined(__SOCIAL_NETWORK_SUPPORT__)
    if (g_cat74_sns_title != NULL)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_RICHTEXT;
    }
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

    if (g_wgui_cat_special_style_flags & WGUI_CAT_TEXT_VIEWER_LARGE_MARGIN)
    {
        gui_multi_line_input_box_set_margin(
            &MMI_multiline_inputbox, 
            WGUI_CAT_TEXT_VIEWER_TOP_MARGIN,
            WGUI_CAT_TEXT_VIEWER_BOTTOM_MARGIN,
            WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN, 
            WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN);
    }
    if (g_wgui_cat_special_style_flags & WGUI_CAT_TEXT_VIEWER_HORIZONTAL_CENTER)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY;
    }

#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif

    wgui_inputs_ml_show();
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_blt_previous(0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT);
} 


/*****************************************************************************
 * FUNCTION
*  ChangeCategory79Title
* DESCRIPTION
*  Change the content of string used in category74.
* PARAMETERS
*  new_string      [IN]        New content of string
*  buffer_size     [IN]        string buffer size
*  is_reset_y      [IN]        whether to keep the position of scroll-bar
* RETURNS
*  void
*****************************************************************************/
void ChangeCategory79Title(UI_string_type title, U16 title_icon)
{
    wgui_title_change(title_icon, 0, (U8*) title, WGUI_TITLE_CHANGE_ICON|WGUI_TITLE_CHANGE_TEXT);
    wgui_title_show(GUI_TITLE_PART_ALL);
}

/*****************************************************************************
 * FUNCTION
*  wgui_cat_setup_special_style
* DESCRIPTION
*  Set the special style
* PARAMETERS
*  style_flags      [IN]       style flags
* RETURNS
*  void
*****************************************************************************/
void wgui_cat_setup_special_style(U32 style_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat_special_style_flags = style_flags;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_setup_slide_buttons
 * DESCRIPTION
 *  Setup the slide buttons for text viewer screen.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  left_button_string :          [IN] Left button string.
 *  left_button_down_image :      [IN] Left button down image.
 *  left_button_up_image :        [IN] Left button normal image.
 *  left_button_function :        [IN] Left button call back function.
 *  right_button_string :         [IN] Right button string.
 *  right_button_down_image :     [IN] Right button down image.
 *  right_button_up_image :       [IN] Right button normal image.
 *  right_button_function :       [IN] Right button call back function.
 *  middle_string :               [IN] The string between the buttons.
 *  flags :                       [IN] Flags.(Unused)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_setup_slide_buttons(
        WCHAR* left_button_string,
        PU8 left_button_down_image,
        PU8 left_button_up_image,
        FuncPtr left_button_function,
        WCHAR* right_button_string,
        PU8 right_button_down_image,
        PU8 right_button_up_image,
        FuncPtr right_button_function,
        WCHAR* middle_string,
        U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    /* allocate memory */
    if (g_wgui_cat_slide_control_ptr == NULL)
    {
        g_wgui_cat_slide_control_ptr = (wgui_cat_slide_control_cntx *)applib_mem_screen_alloc(sizeof(wgui_cat_slide_control_cntx));
        MMI_ASSERT(g_wgui_cat_slide_control_ptr != NULL);
        memset(g_wgui_cat_slide_control_ptr, 0, sizeof(wgui_cat_slide_control_cntx));
    }

    /* initialize */
    g_wgui_cat_slide_control_ptr->left_button_string = left_button_string;
    if (left_button_down_image != NULL)
    {
        g_wgui_cat_slide_control_ptr->left_button_down_image = left_button_down_image;
    }
    else
    {
        if (left_button_function == NULL)
        {
            g_wgui_cat_slide_control_ptr->left_button_down_image = get_image(LEFT_RED_ARROW);
        }
        else
        {
            g_wgui_cat_slide_control_ptr->left_button_down_image = get_image(LEFT_RED_ARROW_PRESSED);
        }
    }
    
    if (left_button_up_image != NULL)
    {
        g_wgui_cat_slide_control_ptr->left_button_up_image = left_button_up_image;
    }
    else
    {
        if (left_button_function == NULL)
        {
            g_wgui_cat_slide_control_ptr->left_button_up_image = get_image(LEFT_RED_ARROW);
        }
        else
        {
            g_wgui_cat_slide_control_ptr->left_button_up_image = get_image(LEFT_RED_ARROW_NORMAL);
        }
    }

    g_wgui_cat_slide_control_ptr->left_button_function = left_button_function;
    g_wgui_cat_slide_control_ptr->right_button_string = right_button_string;


    if (right_button_down_image != NULL)
    {
        g_wgui_cat_slide_control_ptr->right_button_down_image = right_button_down_image;
    }
    else
    {
        if (right_button_function == NULL)
        {
            g_wgui_cat_slide_control_ptr->right_button_down_image = get_image(RIGHT_RED_ARROW);
        }
        else
        {
            g_wgui_cat_slide_control_ptr->right_button_down_image = get_image(RIGHT_RED_ARROW_PRESSED);
        }
    }
    if (right_button_up_image != NULL)
    {
        g_wgui_cat_slide_control_ptr->right_button_up_image = right_button_up_image;
    }
    else
    {
        if (right_button_function == NULL)
        {
            g_wgui_cat_slide_control_ptr->right_button_up_image = get_image(RIGHT_RED_ARROW);
        }
        else
        {
            g_wgui_cat_slide_control_ptr->right_button_up_image = get_image(RIGHT_RED_ARROW_NORMAL);
        }
    }

    g_wgui_cat_slide_control_ptr->right_button_function = right_button_function;
    g_wgui_cat_slide_control_ptr->middle_string = middle_string;
    g_wgui_cat_slide_control_ptr->flags = flags;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_change_slide_buttons_string
 * DESCRIPTION
 *  Change the text of the slide buttons for text viewer screen.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_change_slide_buttons_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    dm_coordinates dm_string_info;
    S32 string_width, string_height;
    icontext_button *left_bt = NULL;
    icontext_button *right_bt = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr == NULL)
    {
        return;
    }

    if (g_wgui_cat_slide_control_ptr->middle_string == NULL)
    {
        return;
    }
    
    gdi_layer_lock_frame_buffer(); 

    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY74_ID_SLIDE_CONTROL,
        DM_STRING,
        -1,
        &dm_string_info);
    
    gui_push_text_clip();
    gui_push_clip();

    gui_set_clip(
        dm_string_info.s16X,
        dm_string_info.s16Y,
        dm_string_info.s16X + dm_string_info.s16Width - 1,
        dm_string_info.s16Y + dm_string_info.s16Height - 1);

    gui_set_text_clip(
        dm_string_info.s16X,
        dm_string_info.s16Y,
        dm_string_info.s16X + dm_string_info.s16Width - 1,
        dm_string_info.s16Y + dm_string_info.s16Height - 1);

    gui_set_font(&MMI_medium_font);
    gui_measure_string(g_wgui_cat_slide_control_ptr->middle_string, &string_width, &string_height);

    /* Align the string on x asis as per the flag */
    if (string_width < dm_string_info.s16Width)
    {
        dm_string_info.s16X += (dm_string_info.s16Width - string_width) >> 1;
    }
    /* Align the string on y asis as per the flag */
    if (string_height < dm_string_info.s16Height)
    {
        dm_string_info.s16Y += (dm_string_info.s16Height - string_height) >> 1;
    }

    gui_set_text_color(*current_MMI_theme->title_text_color);
   
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(dm_string_info.s16X + string_width, dm_string_info.s16Y);
    }
    else
    {
        gui_move_text_cursor(dm_string_info.s16X, dm_string_info.s16Y);
    }

    gui_set_line_height(string_height);

    /* clear text arer */
    gdi_draw_solid_rect(
        (WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W >> 1) + 1, 
        dm_string_info.s16Y, 
        UI_device_width - (WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W  >> 1) - 1,
        dm_string_info.s16Y + string_height - 1, 
        GDI_COLOR_TRANSPARENT);

    gui_print_text(g_wgui_cat_slide_control_ptr->middle_string);

    gui_pop_text_clip();
    gui_pop_clip();
    gdi_layer_unlock_frame_buffer(); 
    gdi_layer_blt_previous(
        (WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W >> 1) + 1, 
        dm_string_info.s16Y, 
        UI_device_width - (WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W  >> 1) - 1,
        dm_string_info.s16Y + string_height - 1);

    /* update the button */
    left_bt = dm_get_button(g_wgui_cat_slide_control_ptr->left_button_id);
	if (left_bt != NULL)
	{

        left_bt->clicked_down_icon = g_wgui_cat_slide_control_ptr->left_button_down_image;
        left_bt->normal_down_icon = g_wgui_cat_slide_control_ptr->left_button_down_image;
        left_bt->normal_up_icon = g_wgui_cat_slide_control_ptr->left_button_up_image;
        gui_show_icontext_button(left_bt);
        gui_BLT_double_buffer(
            left_bt->x, 
            left_bt->y, 
		    left_bt->x + left_bt->width + 1, 
		    left_bt->y + left_bt->height + 1);
#if defined(__MMI_TOUCH_SCREEN__)
       dm_register_button_functions(
           g_wgui_cat_slide_control_ptr->left_button_id, 
           KEY_EVENT_UP, 
           g_wgui_cat_slide_control_ptr->left_button_function);
#endif /* defined(__MMI_TOUCH_SCREEN__) */
    }

    right_bt = dm_get_button(g_wgui_cat_slide_control_ptr->right_button_id);
	if (right_bt != NULL)
	{

        right_bt->clicked_down_icon = g_wgui_cat_slide_control_ptr->right_button_down_image;
        right_bt->normal_down_icon = g_wgui_cat_slide_control_ptr->right_button_down_image;
        right_bt->normal_up_icon = g_wgui_cat_slide_control_ptr->right_button_up_image;
        gui_show_icontext_button(right_bt);
        gui_BLT_double_buffer(
            right_bt->x, 
            right_bt->y, 
		    right_bt->x + left_bt->width + 1, 
		    right_bt->y + left_bt->height + 1);
#if defined(__MMI_TOUCH_SCREEN__)
       dm_register_button_functions(
           g_wgui_cat_slide_control_ptr->right_button_id, 
           KEY_EVENT_UP, 
           g_wgui_cat_slide_control_ptr->right_button_function);
#endif /* defined(__MMI_TOUCH_SCREEN__) */
    }
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_left_slide_button_down
 * DESCRIPTION
 *  Show left button down effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_show_left_slide_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
	icontext_button *left_bt = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr == NULL)
    {
        return;
    }
        
    left_bt = dm_get_button(g_wgui_cat_slide_control_ptr->left_button_id);
	if (left_bt != NULL)
	{
        wgui_cat_clear_button_bg(left_bt);
        left_bt->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);
        gui_show_icontext_button(left_bt);
        gui_BLT_double_buffer(
		    left_bt->x, 
		    left_bt->y, 
		    left_bt->x + left_bt->width + 1, 
		    left_bt->y + left_bt->height + 1);
	}
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_right_slide_button_down
 * DESCRIPTION
 *  Show right button down effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_show_right_slide_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
	icontext_button *right_bt = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr == NULL)
    {
        return;
    }
        
    right_bt = dm_get_button(g_wgui_cat_slide_control_ptr->right_button_id);
	if (right_bt != NULL)
	{
        wgui_cat_clear_button_bg(right_bt);
        right_bt->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);
        gui_show_icontext_button(right_bt);
	    gui_BLT_double_buffer(
		    right_bt->x, 
		    right_bt->y, 
		    right_bt->x + right_bt->width + 1, 
		    right_bt->y + right_bt->height + 1);
	}
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_left_slide_button_up
 * DESCRIPTION
 *  Show left button down effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_show_left_slide_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
	icontext_button *left_bt = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr == NULL)
    {
        return;
    }
        
    left_bt = dm_get_button(g_wgui_cat_slide_control_ptr->left_button_id);
	if (left_bt != NULL)
	{
        wgui_cat_clear_button_bg(left_bt);
        left_bt->flags &= ~(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);
        gui_show_icontext_button(left_bt);
        gui_BLT_double_buffer(
		    left_bt->x, 
		    left_bt->y, 
		    left_bt->x + left_bt->width + 1, 
		    left_bt->y + left_bt->height + 1);
	}
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_right_slide_button_up
 * DESCRIPTION
 *  Show right button down effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_show_right_slide_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
	icontext_button *right_bt = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr == NULL)
    {
        return;
    }
        
    right_bt = dm_get_button(g_wgui_cat_slide_control_ptr->right_button_id);
	if (right_bt != NULL)
	{
        wgui_cat_clear_button_bg(right_bt);
        right_bt->flags &= ~(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);
        gui_show_icontext_button(right_bt);
	    gui_BLT_double_buffer(
		    right_bt->x, 
		    right_bt->y, 
		    right_bt->x + right_bt->width + 1, 
		    right_bt->y + right_bt->height + 1);
	}
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}

#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_clear_button_bg
 * DESCRIPTION
 *  clear button area
 * PARAMETERS
 *  button   [IN]   button information
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_clear_button_bg(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button;
    GDI_HANDLE scr_bg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw information bar background */
    scr_bg = dm_get_scr_bg_layer();
    
    if (scr_bg == GDI_ERROR_HANDLE)
    {
        gdi_layer_get_active(&scr_bg);
    }

    gdi_push_and_set_alpha_blending_source_layer(scr_bg);
    wgui_category_clear_region_with_transparent_color(b->x, b->y, b->x + b->width, b->y + b->height); // shit 1 pixel
    gdi_pop_and_restore_alpha_blending_source_layer();
}
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat74_draw_ctrl_area
 * DESCRIPTION
 *  For IME redraw.
 * PARAMETERS
 *  coordinate   [IN]  Unused.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat74_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ICON_BAR_SUPPORT__
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        wgui_inputs_ml_resize((S32)coordinate->s16Width, (S32)coordinate->s16Height - MMI_ICON_BAR_HEIGHT);
        wgui_inputs_ml_show();
        wgui_icon_bar_show();
    }
#endif /*__MMI_ICON_BAR_SUPPORT__*/	
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_internal_by_res_id
 * DESCRIPTION
 *  Internal function for display a nornal text viewer category.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  need_scrollbar          [IN]        Text-scroll is allowed or not 
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 *  cat_id                  [IN]        flag for different category
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_text_viewer_show_internal_by_res_id(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S8 highlighted_tab,
        MMI_BOOL need_scrollbar,
        MMI_BOOL is_r2l_display,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer,
        S32 cat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_internal(
        get_string(title),
        get_image(title_icon),
        get_string(left_softkey),
        get_string(right_softkey),
        highlighted_tab,
        need_scrollbar,
        is_r2l_display,
        buffer,
        buffer_length,
        history_buffer,
        cat_id);
}


extern CHAR* g_wgui_cat_ml_header_img;
extern CHAR* g_wgui_cat_ml_footer_img;
extern PU8 g_wgui_cat_ml_header_img_res;
extern PU8 g_wgui_cat_ml_footer_img_res;

extern gdi_image_cache_bmp_struct g_wgui_cat_ml_header_img_cache;
extern MMI_BOOL g_wgui_cat_ml_header_img_is_cached;
extern gdi_handle g_wgui_cat_ml_image_handle;

extern void wgui_cat_ml_timer_callback(void);
extern void wgui_cat_ml_header_img_show(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2);
extern void wgui_cat_ml_footer_img_show(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2);
extern S32 wgui_cat_ml_get_resized_image_height(CHAR* image_file, S32 max_w, S32 max_h);
extern S32 wgui_cat_ml_get_resized_image_height_res(PU8 image_res, S32 max_w, S32 max_h);

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
extern void wgui_cattab_get_space_and_tab_width(S16 *space, S16 *tab_w, S8 n_tabs);
extern void wgui_cat_mbbms_set_tab_theme(void);
#endif

#ifdef MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_setup_title_change
 * DESCRIPTION
 *   function for App setup title's icon 
 * PARAMETERS
 *  show_icon1_ID    [IN]        Icon shown with the title
 *  show_icon2_ID    [IN]        Icon shown with the title
 *  text             [IN]        text shown with the title
 *  flag             [IN]        flag for show title 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_setup_title_change(U16 icon_ID, U16 icon2_ID, U8 *text, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
     show_icon1_ID = icon_ID;
     show_icon2_ID = icon2_ID;
     show_title_text = text;
     show_flag = flag;  
}
#endif
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_internal
 * DESCRIPTION
 *  Internal function for display a nornal text viewer category.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  need_scrollbar          [IN]        Text-scroll is allowed or not 
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 *  cat_id                  [IN]        flag for different category
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_text_viewer_show_internal(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        MMI_BOOL need_scrollbar,
        MMI_BOOL is_r2l_display,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer,
        S32 cat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_flag = DM_CLEAR_SCREEN_BACKGROUND;
    S32 l;
    S8 n_tabs;
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__    
    S32 left_bt_x = 0, right_bt_x = 0;   
    S32 bt_y = 0, bt_w, bt_h;
    icontext_button *left_bt = NULL, *right_bt = NULL;
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    U8 h = 0;
    S32 resize_h = 0;
    MMI_BOOL has_title = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* setup softkey */
    dm_add_softkey_str(left_softkey, right_softkey);


    /* setup title or tab bar */
    if (cat_id == MMI_CAT3001_ID)
    {
        mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs); 
#if defined(__MMI_MAINLCD_128X64__) || defined(__MMI_MAINLCD_128X128__) || (defined(__MMI_MAINLCD_320X240__) && defined(__MMI_VIRTUAL_KEYBOARD__)) || (defined(__MMI_MAINLCD_320X240__) && defined(__MMI_FTE_SUPPORT__))
        wgui_create_horizontal_tab_bar(FALSE, title, n_tabs, highlighted_tab, MMI_FALSE);
#else /* __MMI_MAINLCD_128X64__ */
        wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);
#endif /* __MMI_MAINLCD_128X64__ */
    }
    else
    {
#if defined(__SOCIAL_NETWORK_SUPPORT__)
        if (g_cat74_sns_title == NULL)
#endif /* __SOCIAL_NETWORK_SUPPORT__ */
        {
            if ((title != NULL) || (title_icon != NULL))
            {
                wgui_title_set_menu_shortcut_number(-1);
                wgui_title_disable_menu_shortcut_display(MMI_TRUE);
                dm_add_title(title, title_icon);
            }
            else
            {
                has_title = MMI_FALSE;
            }
        }
    }

    if (cat_id == MMI_CAT3002_ID)
    {
        S16 spac = 0;
        S16 tab_w = 0;
        mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs); 
        //wgui_create_horizontal_tab_bar(FALSE, title, n_tabs, highlighted_tab, MMI_FALSE);

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__ 
		wgui_cattab_get_space_and_tab_width(&spac, &tab_w, n_tabs);
#endif
        wgui_create_horizontal_tab_bar_ex(
            FALSE,
            (UI_string_type)title, 
            n_tabs, 
            highlighted_tab,
            tab_w,
            tab_w,
            spac,
            MMI_FALSE,
            GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();   
        
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
        /*set tab text font to be small font*/
        wgui_cat_mbbms_set_tab_theme();
#endif
    }

    /* setup slide control */
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if ((cat_id == MMI_CATEGORY74_ID_SLIDE_CONTROL) || (cat_id == MMI_CATEGORY78_ID_SLIDE_CONTROL))
    {   
        if (g_wgui_cat_slide_control_ptr != NULL)
        {
            /* setup button */
            g_wgui_cat_slide_control_ptr->left_button_id = dm_add_button(
                    g_wgui_cat_slide_control_ptr->left_button_string,
                    g_wgui_cat_slide_control_ptr->left_button_up_image,
                    g_wgui_cat_slide_control_ptr->left_button_down_image,
                    wgui_cat_clear_button_bg);
            
            g_wgui_cat_slide_control_ptr->right_button_id = dm_add_button(
                    g_wgui_cat_slide_control_ptr->right_button_string,
                    g_wgui_cat_slide_control_ptr->right_button_up_image,
                    g_wgui_cat_slide_control_ptr->right_button_down_image,
                    wgui_cat_clear_button_bg);
            
#if defined(__MMI_TOUCH_SCREEN__)
            dm_register_button_functions(
                g_wgui_cat_slide_control_ptr->left_button_id, 
                KEY_EVENT_UP, 
                g_wgui_cat_slide_control_ptr->left_button_function);
            dm_register_button_functions(
                g_wgui_cat_slide_control_ptr->right_button_id, 
                KEY_EVENT_UP, 
                g_wgui_cat_slide_control_ptr->right_button_function);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

            /* if callback is NULL, disable button */
            left_bt = dm_get_button(g_wgui_cat_slide_control_ptr->left_button_id);
            right_bt = dm_get_button(g_wgui_cat_slide_control_ptr->right_button_id);
            if (g_wgui_cat_slide_control_ptr->left_button_function == NULL)
            {
                left_bt->flags |= UI_BUTTON_NO_SHIFT_BUTTON;
            }
            if (g_wgui_cat_slide_control_ptr->right_button_function == NULL)
            {
                right_bt->flags |= UI_BUTTON_NO_SHIFT_BUTTON;
            }

            /* move and resize button */
            gdi_image_get_dimension(g_wgui_cat_slide_control_ptr->left_button_up_image, &bt_w, &bt_h);
            left_bt_x = ((UI_device_width - WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W - (bt_w << 1)) >> 1);
            right_bt_x = left_bt_x + bt_w + WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W;
            bt_y = MMI_CONTENT_Y + ((WGUI_CAT_SLIDE_CONTROL_H  - bt_h) >> 1);

            dm_move_button(g_wgui_cat_slide_control_ptr->left_button_id, left_bt_x, bt_y); 
            dm_resize_button(g_wgui_cat_slide_control_ptr->left_button_id, bt_w, bt_h);
            dm_move_button(g_wgui_cat_slide_control_ptr->right_button_id, right_bt_x, bt_y);
            dm_resize_button(g_wgui_cat_slide_control_ptr->right_button_id, bt_w, bt_h);

            /* setup middle string */
            dm_add_string(
                g_wgui_cat_slide_control_ptr->middle_string,
                &MMI_medium_font,
                *current_MMI_theme->title_text_color,
                *current_MMI_theme->title_text_border_color,
                NULL);
        }
    }
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

    /* setup inputbox */
    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_length, l, 0);

#if defined(__WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__)
    if (g_cate_hilite_list.hilite_type != 0)
    {
	wgui_inputs_ml_register_hilite_keys();
        gui_inputs_ml_parse_keywords(&MMI_multiline_inputbox, g_cate_hilite_list.hilite_type, NULL, NULL);
        gui_inputs_ml_set_hilite_list(
            &MMI_multiline_inputbox,
            NULL,
            0,
            g_cate_hilite_list.curr_hilite_idx,
            g_cate_hilite_list.hilite_cb,
            g_cate_hilite_list.click_cb);
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
#if defined(__MMI_TOUCH_SCREEN__)
        wgui_cate_register_ctrl_area_pen_hdlr();
#endif /* __MMI_TOUCH_SCREEN__ */
    }
#endif /* __WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__ */

#ifdef __MMI_CATEGORY79_IMGAGE_SUPPORT__
    if ((MMI_CATEGORY79_ID == cat_id) && (g_wgui_cat_ml_header_img_cache.buf_ptr) && (g_wgui_cat_ml_header_img_is_cached))
    {
        if (g_wgui_cat_ml_header_img_cache.height < WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT)
        {
            MMI_multiline_inputbox.header_height = WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT + WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN;
        }
        else
        {
            MMI_multiline_inputbox.header_height = g_wgui_cat_ml_header_img_cache.height + WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN;
        }
        MMI_multiline_inputbox.header_callback = wgui_cat_ml_header_img_show;
    }
    else if ((MMI_CATEGORY79_ID == cat_id) && (g_wgui_cat_ml_header_img_res != NULL))
    {
        resize_h = wgui_cat_ml_get_resized_image_height_res(g_wgui_cat_ml_header_img_res, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_WIDTH, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_HEIGHT);
        if (resize_h < WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT)
        {
            resize_h = WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT;
        }
        MMI_multiline_inputbox.header_height = resize_h + WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN;
        MMI_multiline_inputbox.header_callback = wgui_cat_ml_header_img_show;
        if (g_wgui_cat_ml_header_img != NULL)
        {
            MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD;
        }
    }
    else if ((MMI_CATEGORY79_ID == cat_id) && (g_wgui_cat_ml_header_img != NULL))
    {
        resize_h = wgui_cat_ml_get_resized_image_height(g_wgui_cat_ml_header_img, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_WIDTH, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_HEIGHT);
        if (resize_h < WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT)
        {
            resize_h = WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT;
        }
        MMI_multiline_inputbox.header_height = resize_h + WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN;
        MMI_multiline_inputbox.header_callback = wgui_cat_ml_header_img_show;
    }

    if ((MMI_CATEGORY79_ID == cat_id) && (g_wgui_cat_ml_footer_img != NULL))
    {
        resize_h = wgui_cat_ml_get_resized_image_height(g_wgui_cat_ml_footer_img, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_WIDTH, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_HEIGHT);
        if (resize_h < WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT)
        {
            resize_h = WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT;
        }
        MMI_multiline_inputbox.footer_height = resize_h + WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN;
        MMI_multiline_inputbox.footer_callback = wgui_cat_ml_footer_img_show;
    }
    else if ((MMI_CATEGORY79_ID == cat_id) && (g_wgui_cat_ml_footer_img_res != NULL))
    {
        resize_h = wgui_cat_ml_get_resized_image_height_res(g_wgui_cat_ml_footer_img_res, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_WIDTH, WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_HEIGHT);
        if (resize_h < WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT)
        {
            resize_h = WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT;
        }
        MMI_multiline_inputbox.footer_height = resize_h + WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN;
        MMI_multiline_inputbox.footer_callback = wgui_cat_ml_footer_img_show;
    }
#endif /* __MMI_CATEGORY79_IMGAGE_SUPPORT__ */

    if (need_scrollbar)
    {
        wgui_inputs_ml_register_viewer_keys();
    }
    else
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_ONLY_VISIBLE_LINE;
    }

    MMI_multiline_inputbox.override_direction = (U8)is_r2l_display ? 2 : 1;
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
    if ((cat_id == MMI_CAT3005_ID) || (cat_id == MMI_CATEGORY78_ID) || (cat_id == MMI_CATEGORY78_ID_SLIDE_CONTROL))
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_RICHTEXT;
    }
    if (cat_id == MMI_CATEGORY152_ID)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND;
    }

    if (g_wgui_cat_special_style_flags & WGUI_CAT_TEXT_VIEWER_LARGE_MARGIN)
    {
        gui_multi_line_input_box_set_margin(
            &MMI_multiline_inputbox, 
            WGUI_CAT_TEXT_VIEWER_TOP_MARGIN,
            WGUI_CAT_TEXT_VIEWER_BOTTOM_MARGIN,
            WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN, 
            WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN);
    }
    if (g_wgui_cat_special_style_flags & WGUI_CAT_TEXT_VIEWER_HORIZONTAL_CENTER)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY;
    }

#if defined(__SOCIAL_NETWORK_SUPPORT__)
    if (g_cat74_sns_title != NULL)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_RICHTEXT;
    }
#endif /* __SOCIAL_NETWORK_SUPPORT__ */
    
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    dm_get_scr_bg_opacity(&idle_scr_bg_opacity);
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    if (g_cat74_sns_title == NULL)
#endif
    {
        dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
    }
#endif 

#ifdef __MMI_CLIPBOARD__
#if defined(__WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__)
    if (g_cate_hilite_list.hilite_type == 0)
#endif /* __WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__ */
	{
            if (!(g_wgui_cat_special_style_flags & WGUI_CAT_TEXT_VIEWER_DISABLE_CILPBOARD))
            {
                mmi_imc_clipboard_connect(INPUTBOX_MULTILINE);
            }
	}
#endif /* __MMI_CLIPBOARD__ */

#ifdef __MMI_ICON_BAR_SUPPORT__
#ifdef __MMI_FTE_SUPPORT__
    if ((cat_id == MMI_CATEGORY74_ID_SLIDE_CONTROL) || (cat_id == MMI_CATEGORY78_ID_SLIDE_CONTROL))
    {
        if(MMI_TRUE == wgui_icon_bar_is_created())
        {
            dm_register_category_controlled_callback(wgui_cat74_draw_ctrl_area);
        }
    }
#endif
#endif/*__MMI_ICON_BAR_SUPPORT__*/
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    if (g_cat74_sns_title != NULL)
    {
        dm_register_category_controlled_callback(wgui_cat74_draw_sns_title);
    }
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

    if (cat_id == MMI_CATEGORY79_ID)
    {
        dm_data_flag |= DM_SCROLL_TITLE;
        cat_id = MMI_CATEGORY74_ID;
    }

    if (cat_id == MMI_CATEGORY152_ID)
    {
        dm_data_flag |= DM_LEFT_ALIGN_TITLE;
    }
    #ifdef MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE
    if(show_icon1_ID)
    {
        dm_data_flag |= DM_SCROLL_TITLE;
        wgui_title_change(show_icon1_ID,show_icon2_ID,show_title_text,show_flag);
        MMI_multiline_inputbox.ext_flags|= GUI_MULTI_LINE_INPUT_BOX_DISPLAY_BORDER;
    }   
    #endif /*MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE*/

    if (has_title == MMI_FALSE)
    {
        dm_data_flag |= DM_NO_TITLE;
    }
    wgui_cat_setup_category_default_history(
        cat_id,
        dm_data_flag,
        ExitCategory74Screen);
    dm_redraw_category_screen();
    
    h = wgui_inputs_ml_set_category_history((U16)cat_id, history_buffer);
#if defined(__WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__)
    if (MMI_multiline_inputbox.hilite_str_number != 0)
    {
	    if (h)
	    {
	        gui_multi_line_input_box_go_to_hilite(
	            &MMI_multiline_inputbox,
	            (U16)MMI_multiline_inputbox.current_hilite_idx,
	            MMI_FALSE);
	    }
	    else
	    {
	        gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
	    }
    }
#endif /* __WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__ */

    if (has_title == MMI_FALSE)
    {
        wgui_inputs_ml_move(WGUI_INPUTS_STYLE_DEFAULT, MMI_title_y);
        wgui_inputs_ml_resize(WGUI_INPUTS_STYLE_DEFAULT, MMI_content_height + MMI_title_height);
    }

    wgui_inputs_ml_show();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();

    /* reset button response area */
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if ((cat_id == MMI_CATEGORY74_ID_SLIDE_CONTROL) || (cat_id == MMI_CATEGORY78_ID_SLIDE_CONTROL))
    {   
        if (g_wgui_cat_slide_control_ptr != NULL)
        {
#ifdef __MMI_TOUCH_SCREEN__
            gui_icontext_button_overwirte_pen_response_area(left_bt, left_bt_x, bt_y, left_bt_x + bt_w - 1, bt_y + bt_h - 1);
            gui_icontext_button_overwirte_pen_response_area(right_bt, right_bt_x, bt_y, right_bt_x + bt_w - 1, bt_y + bt_h - 1);
#endif /* __MMI_TOUCH_SCREEN__ */
        }
    }
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
}   /* end of ShowCategory74Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory74Screen
 * DESCRIPTION
 *  Displays the category74 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory74Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *buffer,
        S32 buffer_length,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cat_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr != NULL)
    {
        cat_id = MMI_CATEGORY74_ID_SLIDE_CONTROL;
    }
    else
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
    {
        cat_id = MMI_CATEGORY74_ID;
    }
    
    /* the title should not scroll in category74 */
    wgui_cat_text_viewer_show_internal_by_res_id(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        0,
        MMI_TRUE,
        MMI_FALSE,
        buffer,
        buffer_length,
        history_buffer,
        cat_id);
}   /* end of ShowCategory79Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory79Screen
 * DESCRIPTION
 *  Displays the category79 screen, 
 *  category79 is a text viewer screen, and the text-scroll can be disable by "need_scrollbar"
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  need_scrollbar          [IN]        Text-scroll is allowed or not 
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory79Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        MMI_BOOL need_scrollbar,
        MMI_BOOL is_r2l_display,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_internal(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        0,
        need_scrollbar,
        is_r2l_display,
        buffer,
        buffer_length,
        history_buffer,
        MMI_CATEGORY79_ID);
}   /* end of ShowCategory79Screen */

    
/*****************************************************************************
 * FUNCTION
 *  wgui_cat3001_show
 * DESCRIPTION
 *  Displays the category3001 screen, 
 *  category3001 is a text viewer screen with tab bar.
 * PARAMETERS
 *  tab_title               [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  highlighted_tab         [IN]        Highlighted tab
 *  need_scrollbar          [IN]        Text-scroll is allowed or not 
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3001_show_int(
        UI_string_type tab_title,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        MMI_BOOL need_scrollbar,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_internal(
        tab_title,
        0,
        left_softkey,
        right_softkey,
        highlighted_tab,
        need_scrollbar,
        MMI_FALSE,
        buffer,
        buffer_length,
        history_buffer,
        MMI_CAT3001_ID);
}   /* end of ShowCategory79Screen */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3002_show
 * DESCRIPTION
 *  Displays the category3001 screen, 
 *  category3002 is a text viewer screen with title and tab bar.
 * PARAMETERS
 *  tab_title               [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  highlighted_tab         [IN]        Highlighted tab
 *  need_scrollbar          [IN]        Text-scroll is allowed or not 
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_length           [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3002_show(
        UI_string_type tab_title,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        MMI_BOOL need_scrollbar,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_internal(
        tab_title,
        0,
        left_softkey,
        right_softkey,
        highlighted_tab,
        need_scrollbar,
        MMI_FALSE,
        buffer,
        buffer_length,
        history_buffer,
        MMI_CAT3002_ID);
}   /* end of ShowCategory79Screen */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3005_show
 * DESCRIPTION
 *  Displays the category3005 screen, 
 *  Text viewer support rich text.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_length           [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3005_show(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_show_internal(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        0,
        MMI_TRUE,
        MMI_FALSE,
        buffer,
        buffer_length,
        history_buffer,
        MMI_CAT3005_ID);
}   /* end of ShowCategory79Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory74Screen
 * DESCRIPTION
 *  Exits the category74 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory74Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_disconnect();
#endif /* __MMI_CLIPBOARD__ */

    wgui_inputs_ml_reset();
    wgui_close_horizontal_tab_bar();
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_set_scr_bg_opacity(idle_scr_bg_opacity);
#endif 

#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if(g_wgui_cat_slide_control_ptr != NULL)
    {
        applib_mem_screen_free(g_wgui_cat_slide_control_ptr);
		g_wgui_cat_slide_control_ptr = NULL;
    }     
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

#if defined(__WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__)
    wgui_cate_set_highlight_list(NULL);
#endif /* __WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__ */

    if(g_wgui_cat7_string_buf != NULL)
    {
        mmi_frm_scrmem_free(g_wgui_cat7_string_buf);
        g_wgui_cat7_string_buf = NULL;
    }

    wgui_cat_ml_setup_image(NULL, NULL);
    wgui_cat_ml_setup_image_res(NULL, NULL);
    g_wgui_cat_special_style_flags = 0;
#if defined(__SOCIAL_NETWORK_SUPPORT__)
    g_cat74_sns_title = NULL;
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

    g_wgui_cat_ml_image_handle = 0xFFFF;
    gui_cancel_timer(wgui_cat_ml_timer_callback);
#ifdef MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE
    show_icon1_ID = 0;
    show_icon2_ID = 0;
    show_title_text = NULL;
    show_flag = 0;   
#endif /*MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE*/
}   /* end of ExitCategory74Screen */


#ifdef __MMI_EBOOK_READER__

#ifdef __MMI_TOUCH_SCREEN__
S32 MMI_content_height_prev;
S32 MMI_content_y_prev;
#endif /* __MMI_TOUCH_SCREEN__ */ 
/*****************************************************************************
 * FUNCTION
 *  ShowCategory75Screen
 * DESCRIPTION
 *  Displays the category75 screen(normal ebook viewer)
 * PARAMETERS
 *  name                    [IN]        Title string
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 *  stop_scroll_callback    [IN]        Stop scroll callback function
 *  page_info_app           [IN]        Info of page
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory75Screen(
        U16 *name,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer,
        void (*stop_scroll_callback)(void),
        gui_page_info_app **page_info_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_flag = DM_CLEAR_SCREEN_BACKGROUND;
    S32 l;
    gui_page_info_app *page_info_d = *page_info_app;
    dm_coordinates gui_multiline_get_coordinates;
    S32 shortcut_width;
#if defined(__MMI_TOUCH_SCREEN__)
    const gui_virtual_keyboard_pen_enum disable_backspace_list[] = {GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_NONE};
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_paging_set_full_screen_flag(FALSE);
#endif 
    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY74_ID,
        DM_MULTILINE_INPUTBOX1,
        -1,
        &gui_multiline_get_coordinates);
/* 061507 128x160 touch Start */
#ifdef __MMI_TOUCH_SCREEN__
    //gui_multiline_get_coordinates.s16Height = gui_multiline_get_coordinates.s16Height - MMI_title_y - 4;
#endif 
    //wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);
    gui_lock_double_buffer();
    MMI_multiline_inputbox.jump_to_offset_flag = 0;
    wgui_title_set_menu_shortcut_number(-1);
    shortcut_width = set_menu_item_count(100)+7;
    resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    MMI_title_string = (UI_string_type) name;
    MMI_title_icon = (PU8) get_image(title_icon);

    //l = gui_strlen((UI_string_type) buffer);
    //create_multiline_inputbox_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
#ifdef __MMI_TOUCH_SCREEN__
    if (page_info_d->key_callback != NULL)
    {
        mmi_imm_set_events(MMI_FALSE, disable_backspace_list);
        mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_123); //Need to be modified
        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
        mmi_imc_disable_handwriting();
        mmi_imc_disable_key_input();
        mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_multiline);
        gui_multiline_get_coordinates.s16Height = gui_multiline_get_coordinates.s16Height - mmi_imc_get_vk_area_height();
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX;

    wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);
    l = gui_strlen((UI_string_type) buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
/* 061507 128x160 touch End */

    wgui_paging_multiline_inputbox_set_stop_scroll_callback((void*)stop_scroll_callback);
    wgui_paging_multiline_set_page(page_info_d->start_id, page_info_d->end_id);
    wgui_paging_multiline_set_font(page_info_d->font_size, page_info_d->font_style);

    register_multiline_inputbox_viewer_keys();
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);  /* |UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND); */

    if (page_info_d->highlight_string == 1)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        wgui_paging_highlight_search_string(page_info_d->jump_offset_from_app, page_info_d->search_str_len);
    }
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_get_scr_bg_opacity(&idle_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif 
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
    MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
    if (!page_info_d->fixed_view_flag)
        MMI_multiline_inputbox.jump_offset_from_app = page_info_d->jump_offset_from_app;
    else
        MMI_multiline_inputbox.jump_offset_from_app = 0;
    MMI_multiline_inputbox.search_flag_is_on = page_info_d->search_flag_is_on;
    MMI_multiline_inputbox.size_of_total_data = page_info_d->doc_size;
    MMI_multiline_inputbox.override_direction = page_info_d->override_direction ? 2 : 1;
    show_multiline_inputbox_no_draw();

    wgui_paging_set_scrollbar_range(page_info_d->doc_size);
    /* PMT MMSVIEWER */
    wgui_paging_multiline_set_get_page_callback(page_info_d->get_page_cb);                    

    set_multiline_inputbox_category_history(MMI_CATEGORY74_ID, history_buffer);

    wgui_paging_multiline_set_scroll_info(&page_info_d);
    wgui_paging_set_show_percentage_flag();
    if(old_font_size != page_info_d->font_size || old_font_style != page_info_d->font_style)
        wgui_paging_multiline_clear_last_percentage();

    if (old_font_size == page_info_d->font_size && old_font_style == page_info_d->font_style)
    {
        if (page_info_d->text_offset != 0 || page_info_d->fixed_view_flag)
        {
            if (MMI_multiline_inputbox.text_offset_y != page_info_d->last_text_offset_y)
            {
                MMI_multiline_inputbox.text_offset_y = page_info_d->last_text_offset_y;
            }
        } 
    }

    if (page_info_d->text_offset)
    {
        wgui_paging_multiline_set_percentage(page_info_d->start_id, page_info_d->text_offset);
		
        if (MMI_multiline_inputbox.edit_height >= MMI_multiline_inputbox.text_height)
        {
            wgui_paging_multiline_set_percentage(page_info_d->start_id, 0);
        }
    }
    else
    {
        show_multiline_inputbox_no_draw();
        if (MMI_multiline_inputbox.search_flag_is_on)
        {
            show_multiline_inputbox_no_draw();
            if (!page_info_d->fixed_view_flag)
                wgui_paging_multiline_set_percentage(page_info_d->start_id, (S16)MMI_multiline_inputbox.text_offset);
            else
                wgui_paging_multiline_inputbox_set_percentage_scale(page_info_d->last_showed_percentage);
        }
        else
        {
            wgui_paging_multiline_set_percentage(page_info_d->start_id, page_info_d->jump_offset_from_app);
        }
    }
    if (page_info_d->jump_to_end == 0)
    {
        show_multiline_inputbox_no_draw();
        wgui_paging_jump_to_end();
        wgui_paging_multiline_inputbox_set_percentage_scale(COMPLETE_PERCENTAGE_SCALE);
    }

    gui_unlock_double_buffer();

    old_font_size = page_info_d->font_size;
    old_font_style = page_info_d->font_style;

#ifdef __MMI_TOUCH_SCREEN__
    dm_register_category_controlled_callback(RedrawCategoryControlledArea75Screen);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_move_hdlr, MMI_PEN_EVENT_MOVE);

    if (page_info_d->key_callback != NULL)
    {
        dm_data_flag |= DM_SHOW_VKPAD;
        dm_register_vkpad_callback(wgui_inputs_ml_paging_virtual_keypad_callback);
    }

    wgui_cat_setup_category_default_history(
        MMI_CATEGORY75_ID,
        dm_data_flag,
        ExitCategory75Screen);
#else 
    wgui_cat_setup_category_default_history(
        MMI_CATEGORY74_ID,
        dm_data_flag,
        ExitCategory75Screen);

#endif 

    dm_redraw_category_screen();

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif
    MMI_multiline_inputbox.page_offset = MMI_multiline_inputbox.jump_offset_from_app = 0;

    /* wgui_paging_multiline_set_scroll_info(&page_info_d); */
    if (page_info_d->scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON && page_info_d->scroll_speed != 0)
    {
        wgui_paging_start_text_scroll();
    }
    else
    {
        wgui_paging_stop_text_scroll();
    }
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    if (page_info_d->scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
    {
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    }
    else
    {
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_page, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_page, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
}   /* end of ShowCategory75Screen */

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  RedrawCategoryControlledArea75Screen
 * DESCRIPTION
 *  redraw function for category 75 in touch screen
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategoryControlledArea75Screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    redraw_multiline_inputbox();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitCategory75Screen
 * DESCRIPTION
 *  Exits the category75 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory75Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_multiline_inputbox();
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_set_scr_bg_opacity(idle_scr_bg_opacity);
#endif
    MMI_multiline_inputbox.previous_shared_bytes = 0;
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    wgui_paging_reset_show_percentage_flag();
    wgui_paging_stop_text_scroll();
    wgui_paging_multiline_inputbox_set_stop_scroll_callback(NULL);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_imc_disconnect();
#endif 
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
}   /* end of ExitCategory75Screen */

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define CAT375_INFO_BAR_HEIGHT 22
#elif defined(__MMI_MAINLCD_320X240__)
    #define CAT375_INFO_BAR_HEIGHT 22
#elif defined(__MMI_MAINLCD_320X480__)
    #define CAT375_INFO_BAR_HEIGHT 31    
#else /* defined(__MMI_MAINLCD_240X320__) */
    #define CAT375_INFO_BAR_HEIGHT 18
#endif 

MMI_BOOL g_wgui_category375_is_fullscreen;
static MMI_BOOL g_wgui_redraw_enable = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory375Counter
 * DESCRIPTION
 *  Display the counter for category375
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory375Counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, x, y, w, h;
    UI_character_type str[32];
    color c = {255, 255, 255, 0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gui_push_clip();

    x1 = MMI_multiline_inputbox.x;
    y1 = MMI_multiline_inputbox.y + MMI_multiline_inputbox.height;
    x2 = x1 + MMI_multiline_inputbox.width - 1;
    y2 = y1 + CAT375_INFO_BAR_HEIGHT -1;
    
    gui_set_clip(x1, y1, x2, y2);   
    gdi_draw_rect(x1, y1, x2, y2, GDI_COLOR_BLACK);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_GRAY);
    wgui_inputs_ml_linebase_get_percentage(str);

    gui_set_font(&MMI_medium_font);
    gui_measure_string(str, &w, &h);
    y = y1 + (CAT375_INFO_BAR_HEIGHT - h)/2;

    if (mmi_fe_get_r2l_state())
        x = x1 + w + 1;
    else
        x = x2 - w - 1;

    gui_move_text_cursor(x, y);
    gui_set_text_color(c);
    gui_set_font(&MMI_medium_font);
    gui_print_text(str);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(x1,y1,x2,y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */     
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  get_category375_inputbox_coordinate
 * DESCRIPTION
 *  get the inputbox position of category375
 * PARAMETERS
 *  x             [OUT]
 *  y             [OUT]
 *  width         [OUT]
 *  height        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category375_get_inputbox_and_counter_size(S32 *x, S32 *y, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    *x = MMI_multiline_inputbox.x;
    *y = MMI_multiline_inputbox.y;
    *width = MMI_multiline_inputbox.width;
    *height = MMI_multiline_inputbox.height + CAT375_INFO_BAR_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_category375_resize_inputbox_and_counter
 * DESCRIPTION
 *  get the inputbox position of category375
 * PARAMETERS
 *  x             [OUT]
 *  y             [OUT]
 *  width         [OUT]
 *  height        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category375_resize_inputbox_and_counter(multi_line_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if(g_wgui_category375_is_fullscreen)
    {
        gui_resize_multi_line_input_box_no_draw(b, width, height);
    }
    else
    {
        gui_resize_multi_line_input_box_no_draw(b, width, height - CAT375_INFO_BAR_HEIGHT);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_category375_redraw_inputbox_and_counter
 * DESCRIPTION
 *  get the inputbox position of category375
 * PARAMETERS
 *  x             [OUT]
 *  y             [OUT]
 *  width         [OUT]
 *  height        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category375_redraw_inputbox_and_counter(void)
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/  
        gui_push_clip();
        gui_set_clip(
            MMI_multiline_inputbox.x, 
            MMI_multiline_inputbox.y, 
            MMI_multiline_inputbox.width- 1, 
            MMI_multiline_inputbox.height + CAT375_INFO_BAR_HEIGHT - 1);   
        
		if (g_wgui_redraw_enable)
			redraw_multiline_inputbox(); 
        
        if(g_wgui_category375_is_fullscreen == MMI_FALSE)
        {
            RedrawCategory375Counter(); 
        }
        
        gui_pop_clip();

}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategoryControlledArea375Screen
 * DESCRIPTION
 *  Redraw the controlled area for category375
 * PARAMETERS
 *  coordinate         [IN]  the control area position and size
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategoryControlledArea375Screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_wgui_redraw_enable = MMI_TRUE;
    mmi_imc_redraw_screen_by_state();
	g_wgui_redraw_enable = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory375Screen
 * DESCRIPTION
 *  Exits the category375 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory375Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_multiline_inputbox();

    wgui_inputs_ml_linebase_stop_text_scroll();
    wgui_inputs_ml_linebase_set_stop_scroll_callback(NULL);
    wgui_inputs_ml_linebase_set_percentage_callback((void*)NULL);
    mmi_imm_reset_allowed_and_disabled_list();
    
    if(g_wgui_category375_is_fullscreen)
    {
        MMI_content_height -= MMI_softkey_height;
    }

#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
        dm_set_scr_bg_opacity(idle_scr_bg_opacity);
#endif

    mmi_imc_disconnect();

    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE;
}   /* end of ExitCategory75Screen */
/*
void gui_temp_bg_update(void)
{
    S32 n;
    
    n = MMI_multiline_inputbox.total_line_count + 10;

    if (n>100)
    {
        wgui_inputs_ml_set_total_line_count(100, 1);
    }
    else
    {
        wgui_inputs_ml_set_total_line_count(n, 1);
        gui_start_timer(1000, gui_temp_bg_update);
    }
}*/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory375Screen
 * DESCRIPTION
 *  Displays the linebased category75 screen(normal ebook viewer)
 * PARAMETERS
 *  name                    [IN]        Title string
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 *  stop_scroll_callback    [IN]        Stop scroll callback function
 *  page_info_app           [IN]        Info of page
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory375Screen(
        U16 *name,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer,
        void (*stop_scroll_callback)(void),
        wgui_ml_line_base_info **page_info_app,
        MMI_BOOL is_fullscreen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_cat_id;
    S32 dm_data_flag = DM_CLEAR_SCREEN_BACKGROUND;
    wgui_ml_line_base_info *page_info_d = *page_info_app;
    dm_coordinates gui_multiline_get_coordinates;
#if defined(__MMI_TOUCH_SCREEN__)
    const gui_virtual_keyboard_pen_enum disable_backspace_list[] = {GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_NONE};
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_category375_is_fullscreen = is_fullscreen;
    gui_lock_double_buffer();
    if(is_fullscreen == MMI_FALSE)
    {
        dm_add_softkey_id(left_softkey, right_softkey);
        dm_add_title(name, get_image(title_icon));

        gui_multiline_get_coordinates.s16X = MMI_COMMON_CONTENT_X;
        gui_multiline_get_coordinates.s16Y = MMI_COMMON_CONTENT_Y;
        gui_multiline_get_coordinates.s16Width = MMI_COMMON_CONTENT_WIDTH;
        gui_multiline_get_coordinates.s16Height = MMI_COMMON_CONTENT_HEIGHT - CAT375_INFO_BAR_HEIGHT;
    }
    else
    {
        gui_multiline_get_coordinates.s16X = 0;
        gui_multiline_get_coordinates.s16Y = 0;
        gui_multiline_get_coordinates.s16Width = UI_DEVICE_WIDTH;
        gui_multiline_get_coordinates.s16Height = UI_DEVICE_HEIGHT;
        MMI_content_height += MMI_softkey_height;
    }

        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
        
#ifdef __MMI_TOUCH_SCREEN__
        mmi_imm_set_events(MMI_FALSE, disable_backspace_list);
        mmi_imc_disable_handwriting();
#endif /* __MMI_TOUCH_SCREEN__ */ 
        mmi_imc_disable_key_input();
        mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_123); 
        mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_multiline);
        
#ifdef __MMI_TOUCH_SCREEN__
        gui_multiline_get_coordinates.s16Height -= mmi_imc_get_vk_area_height();
#endif /* __MMI_TOUCH_SCREEN__ */

    wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);

    create_multiline_inputbox_set_buffer(NULL, 0, 0, 0);
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);  /* |UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND); */
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE;

    wgui_inputs_ml_linebase_init(page_info_d);
    wgui_inputs_ml_linebase_set_stop_scroll_callback((void*)stop_scroll_callback);

#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_get_scr_bg_opacity(&idle_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif 

    /* In fullscreen, the counter should be hided */
    if(is_fullscreen == MMI_FALSE)
    {
        wgui_inputs_ml_linebase_set_percentage_callback((void*)mmi_imc_redraw_screen_by_state);
    }
    set_multiline_inputbox_category_history(MMI_CATEGORY375_ID, history_buffer);

    /* currently, we use RtoL flag to decide the direction. The final solution should be given by application */
    /*if (r2lMMIFlag)
    {
        page_info_d->override_direction = BIDI_R;
    }
    else
    {
        page_info_d->override_direction = BIDI_L;
    }*/   

    gui_unlock_double_buffer();

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_inputs_ml_linebase_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_inputs_ml_linebase_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_inputs_ml_linebase_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if(is_fullscreen)
    {
        dm_data_cat_id = MMI_CATEGORY375_ID_FULLSCREEN;
    }
    else
    {
        dm_data_cat_id = MMI_CATEGORY375_ID;
#ifdef __MMI_MAINLCD_320X240__
        dm_data_flag |= DM_NO_STATUS_BAR;
#endif
    }

    dm_register_category_controlled_callback(RedrawCategoryControlledArea375Screen);
    wgui_cat_setup_category_default_history(
        dm_data_cat_id,
        dm_data_flag,
        ExitCategory375Screen);
    dm_redraw_category_screen();

    if (page_info_d->scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON && page_info_d->scroll_speed != 0)
    {
        wgui_inputs_ml_linebase_start_auto_scroll();
    }
    else
    {
        wgui_inputs_ml_linebase_stop_text_scroll();
    }
    
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;

    SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_previous_line, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_next_line, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_VOL_UP, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_VOL_DOWN, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_ml_linebase_previous_line, KEY_LEFT_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_ml_linebase_next_line, KEY_RIGHT_ARROW, KEY_REPEAT);
}   /* end of ShowCategory75Screen */

#ifdef __MMI_FTE_SUPPORT__

typedef struct _wgui_cat3003_cntx_struct
{
    MMI_BOOL is_full_screen;
    
    GDI_HANDLE iconbar_layer;  
    MMI_BOOL full_screen_has_icon_bar;
    void (*tap_event_hdlr)(void);
    void (*move_event_hdlr)(void);
    void (*pen_down_icon_bar_cb)(void);
    void (*pen_up_icon_bar_cb)(void);
    S16 pen_pos_x;
    S16 pen_pos_y;
    MMI_BOOL is_tap_event;
    
    GDI_HANDLE counter_layer;
    MMI_BOOL has_counter;

} wgui_cat3003_cntx_struct;

#define CAT3003_ICON_BAR_OPACITY         (230)
#define CAT3003_COUNTER_OPACITY          (255)
#define CAT3003_ICON_BAR_BG_COLOR       (gdi_act_color_from_rgb(255, 100, 100, 100))
#define CAT3003_PEN_UP_RESPOND_GAP      (10)
#define CAT3003_COUNTER_GAP_X             (10)
#define CAT3003_COUNTER_GAP_Y             (8)
#define CAT3003_COUNTER_STRING_GAP_X     (4)

static wgui_cat3003_cntx_struct* g_wgui_cat3003_cntx_ptr = NULL;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_register_pen_event_handler
 * DESCRIPTION
 *  set category3003 tap/move event callback function
 * PARAMETERS
 *  tap_event       [IN]        tap event callback function
 *  move_event      [IN]        move_event callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_register_pen_event_handler(
void (*tap_event) (void), 
        void (*move_event) (void),
        void (*pen_down_icon_bar_callback) (void), 
        void (*pen_up_icon_bar_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat3003_cntx_ptr->tap_event_hdlr = tap_event;
    g_wgui_cat3003_cntx_ptr->move_event_hdlr = move_event;
    g_wgui_cat3003_cntx_ptr->pen_down_icon_bar_cb = pen_down_icon_bar_callback;
    g_wgui_cat3003_cntx_ptr->pen_up_icon_bar_cb = pen_up_icon_bar_callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_icon_bar_is_displayed
 * DESCRIPTION
 *  Check the icon bar state in full screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL      Icon bar is displayed or not.
 *****************************************************************************/
MMI_BOOL wgui_cat3003_icon_bar_is_displayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_counter_is_displayed
 * DESCRIPTION
 *  Check the counter state in full screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL      Icon bar is displayed or not.
 *****************************************************************************/
MMI_BOOL wgui_cat3003_counter_is_displayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_cat3003_cntx_ptr->has_counter;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_show_floating_iconbar
 * DESCRIPTION
 *  draw floating iconbar.
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_show_floating_iconbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle icon_bar_hint_layer = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the icon bar have been displayed, or it is not created */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_FALSE ||
        g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE || 
        wgui_icon_bar_is_created() == MMI_FALSE)
    {
        return;
    }
    
    gdi_layer_lock_frame_buffer(); 
    g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar = MMI_TRUE;

    /* change active layer */
    gdi_layer_push_and_set_active(g_wgui_cat3003_cntx_ptr->iconbar_layer);
    gdi_push_and_set_alpha_blending_source_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
    gdi_layer_clear(GDI_COLOR_GRAY);

    /* show icon bar */
    wgui_icon_bar_move(0, UI_device_height - MMI_ICON_BAR_HEIGHT);
    wgui_icon_bar_resize(UI_device_width, MMI_ICON_BAR_HEIGHT);
    wgui_icon_bar_show();

    /* resume active layer */
    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();
    
    gdi_layer_unlock_frame_buffer(); 
    
    icon_bar_hint_layer = wgui_icon_bar_get_hint_layer_handle();
    
    if (g_wgui_cat3003_cntx_ptr->has_counter)
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, g_wgui_cat3003_cntx_ptr->counter_layer, icon_bar_hint_layer);
    }
    else
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, icon_bar_hint_layer, 0);
    }
    gdi_layer_blt_previous(
        0,
        UI_device_height - MMI_ICON_BAR_HEIGHT,
        UI_device_width -1,
        UI_device_height -1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_hide_floating_iconbar
 * DESCRIPTION
 *  hide floating iconbar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_hide_floating_iconbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_FALSE ||
        g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_FALSE)
    {
        return;
    }
    
    g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar = MMI_FALSE;

    if (g_wgui_cat3003_cntx_ptr->has_counter == MMI_TRUE)
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->counter_layer, 0, 0);
    }
    else
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
    }
    gdi_layer_blt_previous(
        0,
        UI_device_height - MMI_ICON_BAR_HEIGHT,
        UI_device_width -1,
        UI_device_height -1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_draw_counter_with_bg
 * DESCRIPTION
 *  Draw the counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3003_draw_counter_with_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bg_x, bg_y, bg_w, bg_h, str_x, str_y, str_w, str_h;
    UI_character_type str[32];
    color c = {255, 255, 255, 0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    /* get string size */
    wgui_inputs_ml_linebase_get_percentage(str);
    gui_set_font(&MMI_small_font);
    gui_measure_string(str, &str_w, &str_h);

    /* set counter background position */
    bg_x = UI_device_width - CAT3003_COUNTER_GAP_X - str_w - (CAT3003_COUNTER_STRING_GAP_X << 1);
    bg_y = 0;
    bg_w = str_w + (CAT3003_COUNTER_STRING_GAP_X << 1);
    bg_h = str_h + (CAT3003_COUNTER_STRING_GAP_X << 1);/* border */
   
    /* draw background */
    gdi_image_draw_resized_blend2layers(bg_x, bg_y, bg_w, bg_h, current_MMI_theme->inputbox_remaining_counter_bg);
    //gdi_image_draw_resized(bg_x, bg_y, bg_w, bg_h, current_MMI_theme->inputbox_remaining_counter_bg);
    
    /* set counter text position */
	if (mmi_fe_get_r2l_state())
	{
		str_x = bg_x + CAT3003_COUNTER_STRING_GAP_X + str_w;
	}
	else
	{
        str_x = bg_x + CAT3003_COUNTER_STRING_GAP_X;
	}

    str_y = bg_y + ((bg_h - str_h) >> 1);

    /* draw counter text */
    gui_move_text_cursor(str_x, str_y);
    gui_set_text_color(c);
    gui_set_font(&MMI_small_font);
    gui_print_text(str);

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_show_counter
 * DESCRIPTION
 *  draw counter for line-based ebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_show_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter_offset_y = 0, counter_w, counter_h;
    gdi_handle icon_bar_hint_layer = 0;
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_imc_is_clipboard_state())
    {
        return;
    }

    gdi_layer_lock_frame_buffer(); 
    g_wgui_cat3003_cntx_ptr->has_counter = MMI_TRUE;

    /* change active layer */
    gdi_layer_push_and_set_active(g_wgui_cat3003_cntx_ptr->counter_layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    /* show icon bar */
    wgui_cat3003_draw_counter_with_bg();
    
    /* resume active layer */
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_unlock_frame_buffer(); 

    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_FALSE)
    {
        /* set counter offset */
        counter_offset_y = MMI_content_y;
    }
    
    /* get counter height */
    wgui_inputs_ml_linebase_get_percentage(str);
    gui_set_font(&MMI_small_font);
    gui_measure_string(str, &counter_w, &counter_h);
    counter_h += (CAT3003_COUNTER_STRING_GAP_X << 1); /* border */
    
    /* blt counter area */
    if ((g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE) &&
        (g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE))
    {
        icon_bar_hint_layer = wgui_icon_bar_get_hint_layer_handle();
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, g_wgui_cat3003_cntx_ptr->counter_layer, icon_bar_hint_layer);
    }
    else
    {
        icon_bar_hint_layer = wgui_icon_bar_get_hint_layer_handle();
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->counter_layer, icon_bar_hint_layer, 0);
    }
    gdi_layer_blt_previous(
            UI_device_width - CAT3003_COUNTER_GAP_X - counter_w - (CAT3003_COUNTER_STRING_GAP_X << 1),
            counter_offset_y + CAT3003_COUNTER_GAP_Y,
            UI_device_width - CAT3003_COUNTER_GAP_X,
            counter_offset_y + CAT3003_COUNTER_GAP_Y + counter_h - 1);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_hide_counter
 * DESCRIPTION
 *  hide counter.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_hide_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter_offset_y = 0, counter_w, counter_h;
    gdi_handle icon_bar_hint_layer = 0;
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_cat3003_cntx_ptr->has_counter== MMI_FALSE)
    {
        return;
    }
    
    g_wgui_cat3003_cntx_ptr->has_counter = MMI_FALSE;

    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_FALSE)
    {
        /* set counter offset */
        counter_offset_y = MMI_content_y;
    }

    /* get counter height */
    wgui_inputs_ml_linebase_get_percentage(str);
    gui_set_font(&MMI_small_font);
    gui_measure_string(str, &counter_w, &counter_h);
    counter_h += (CAT3003_COUNTER_STRING_GAP_X << 1); /* border */

    /* blt counter area */
    icon_bar_hint_layer = wgui_icon_bar_get_hint_layer_handle();
    
    if ((g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE) &&
        (g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE))
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, icon_bar_hint_layer, 0);
    }
    else
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, icon_bar_hint_layer, 0, 0);
    }
    gdi_layer_blt_previous(
            UI_device_width - CAT3003_COUNTER_GAP_X - counter_w - (CAT3003_COUNTER_STRING_GAP_X << 1),
            counter_offset_y + CAT3003_COUNTER_GAP_Y,
            UI_device_width - CAT3003_COUNTER_GAP_X,
            counter_offset_y + CAT3003_COUNTER_GAP_Y + counter_h - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_update_counter
 * DESCRIPTION
 *  update counter.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_update_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  clear counter but not blt*/
    gdi_layer_lock_frame_buffer(); 
    wgui_cat3003_hide_counter();
    gdi_layer_unlock_frame_buffer(); 
    
    wgui_cat3003_show_counter();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_percentage_callback
 * DESCRIPTION
 *  update counter when text move.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3003_percentage_callback(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat3003_counter_is_displayed())
    {
        wgui_cat3003_update_counter();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_draw_iconbar_bg
 * DESCRIPTION
 *  clear the region of iconbar.
 * PARAMETERS
 *  x1    [IN]    start x
 *  y1    [IN]    start y
 *  x2    [IN]    end x
 *  y2    [IN[    end y 
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3003_draw_iconbar_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, CAT3003_ICON_BAR_BG_COLOR);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_pen_down_hdlr
 * DESCRIPTION
 *  pen down handler of category 3003
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_cat3003_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iconbar_h = 0;
	mmi_pen_point_struct pos_iconbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* use the pen down position to check whether need to handle by app and editor */
    g_wgui_cat3003_cntx_ptr->pen_pos_x = pos.x;
    g_wgui_cat3003_cntx_ptr->pen_pos_y = pos.y;
    if (!(PEN_CHECK_BOUND(
            pos.x, 
            pos.y, 
            0, 
            0, 
            UI_device_width, 
            UI_device_height)))
    {
        return MMI_FALSE;
    }

    /* in full screen */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE)
    {
        /* if pen down on iconbar */
        if ((g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE) &&
            (PEN_CHECK_BOUND(
                pos.x, 
                pos.y, 
                0, 
                UI_device_height - MMI_ICON_BAR_HEIGHT, 
                UI_device_width, 
                MMI_ICON_BAR_HEIGHT)))
        {
            /* offset for icon bar pen handler */
            pos_iconbar.x = pos.x;
            pos_iconbar.y = pos.y;// - (UI_device_height - MMI_ICON_BAR_HEIGHT);

            wgui_icon_bar_set_target_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            gdi_push_and_set_alpha_blending_source_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            
            /* callback to app for stop timer */
            if (g_wgui_cat3003_cntx_ptr->pen_down_icon_bar_cb!= NULL)
            {
                g_wgui_cat3003_cntx_ptr->pen_down_icon_bar_cb();
            }

            /* handle by icon bar */
            wgui_icon_bar_translate_pen_event(pos_iconbar, MMI_PEN_EVENT_DOWN);

            gdi_pop_and_restore_alpha_blending_source_layer();

            /* don't handle by app's callback */
            g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_FALSE;
        }
        else /* pen down on text area */
        {
            /* handle by editor */
            wgui_inputs_ml_linebase_pen_down_hdlr(pos);
        #ifdef __MMI_CLIPBOARD__
            mmi_imc_clipboard_pen_event_down_handler(pos);
        #endif /* __MMI_CLIPBOARD__ */
        }
        return MMI_TRUE;
    }
    else /* not full screen */
    {
        if (wgui_icon_bar_is_created() == MMI_TRUE)
        {
            iconbar_h = MMI_ICON_BAR_HEIGHT;
        }

        /* pen down on text area */
        if (PEN_CHECK_BOUND(
            pos.x, 
            pos.y, 
            0, 
            MMI_content_y, 
            MMI_content_width, 
            MMI_content_height - iconbar_h))
        {
            /* handle by editor */
            wgui_inputs_ml_linebase_pen_down_hdlr(pos);
        #ifdef __MMI_CLIPBOARD__
            mmi_imc_clipboard_pen_event_down_handler(pos);
        #endif /* __MMI_CLIPBOARD__ */
            return MMI_TRUE;
        }
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_pen_move_hdlr
 * DESCRIPTION
 *  pen move handler of category 3003
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_cat3003_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iconbar_h = 0;
    mmi_pen_point_struct pos_iconbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(PEN_CHECK_BOUND(
            g_wgui_cat3003_cntx_ptr->pen_pos_x, 
            g_wgui_cat3003_cntx_ptr->pen_pos_y, 
            0, 
            0, 
            UI_device_width, 
            UI_device_height)))
    {
        return MMI_FALSE;
    }

    /* in full screen */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen)
    {
        /* pen down point on iconbar */
        if ((g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE) &&
            (PEN_CHECK_BOUND(
                g_wgui_cat3003_cntx_ptr->pen_pos_x, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y, 
                0, 
                UI_device_height - MMI_ICON_BAR_HEIGHT, 
                UI_device_width, 
                MMI_ICON_BAR_HEIGHT)))
        {
            /* offset for icon bar pen handler */
            pos_iconbar.x = pos.x;
            pos_iconbar.y = pos.y;// - (UI_device_height - MMI_ICON_BAR_HEIGHT);

            wgui_icon_bar_set_target_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            gdi_push_and_set_alpha_blending_source_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            
            wgui_icon_bar_translate_pen_event(pos_iconbar, MMI_PEN_EVENT_MOVE);

            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        else /* pen down point on editor */
        {
            /* pen move a long distance */
            if (MMI_FALSE == PEN_CHECK_BOUND(
                pos.x, 
                pos.y, 
                g_wgui_cat3003_cntx_ptr->pen_pos_x - CAT3003_PEN_UP_RESPOND_GAP, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y - CAT3003_PEN_UP_RESPOND_GAP, 
                CAT3003_PEN_UP_RESPOND_GAP << 1, 
                CAT3003_PEN_UP_RESPOND_GAP << 1))
            {
                /* if pen moved, it is not a tap event */
                g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_FALSE;

                /* counter and icon bar need disappear while pen moving */
                if (g_wgui_cat3003_cntx_ptr->move_event_hdlr != NULL)
                {
                    g_wgui_cat3003_cntx_ptr->move_event_hdlr();
                }
            }
            /* handle by editor */
        #ifdef __MMI_CLIPBOARD__
            if (!mmi_imc_is_clipboard_state())
        #endif
            {
                wgui_inputs_ml_linebase_pen_move_hdlr(pos);
            }
        #ifdef __MMI_CLIPBOARD__
            mmi_imc_clipboard_pen_event_move_handler(pos);
        #endif /* __MMI_CLIPBOARD__ */
        }
        return MMI_TRUE;
    }
    else /* not full screen */
    {
        if (wgui_icon_bar_is_created() == MMI_TRUE)
        {
            iconbar_h = MMI_ICON_BAR_HEIGHT;
        }

        /* the pen down point is in text area */
        if (PEN_CHECK_BOUND(
                g_wgui_cat3003_cntx_ptr->pen_pos_x, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y, 
                0, 
                MMI_content_y, 
                MMI_content_width, 
                MMI_content_height - iconbar_h))
        {
            /* pen moved a long distance */
            if (MMI_FALSE == PEN_CHECK_BOUND(
                    pos.x, 
                    pos.y, 
                    g_wgui_cat3003_cntx_ptr->pen_pos_x - CAT3003_PEN_UP_RESPOND_GAP, 
                    g_wgui_cat3003_cntx_ptr->pen_pos_y - CAT3003_PEN_UP_RESPOND_GAP, 
                    CAT3003_PEN_UP_RESPOND_GAP << 1, 
                    CAT3003_PEN_UP_RESPOND_GAP << 1))
            {
                /* if pen moved, it is not pen tap event */
                g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_FALSE;

                /* counter need disappear while pen moving */
                if (g_wgui_cat3003_cntx_ptr->move_event_hdlr != NULL)
                {
                    g_wgui_cat3003_cntx_ptr->move_event_hdlr();
                }
            }
            /* handle by editor */
        #ifdef __MMI_CLIPBOARD__
            if (!mmi_imc_is_clipboard_state())
        #endif
            {
                wgui_inputs_ml_linebase_pen_move_hdlr(pos);
            }
        #ifdef __MMI_CLIPBOARD__
            mmi_imc_clipboard_pen_event_move_handler(pos);
        #endif /* __MMI_CLIPBOARD__ */
            return MMI_TRUE;
        }
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_pen_up_hdlr
 * DESCRIPTION
 *  pen up handler category 3003
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_cat3003_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iconbar_h = 0;
    mmi_pen_point_struct pos_iconbar;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(PEN_CHECK_BOUND(
            g_wgui_cat3003_cntx_ptr->pen_pos_x, 
            g_wgui_cat3003_cntx_ptr->pen_pos_y, 
            0, 
            0, 
            UI_device_width, 
            UI_device_height)))
    {
        return MMI_FALSE;
    }

    /* in full screen */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE)
    {
        /* if the pen down point is on iconbar */
        if ((g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE) &&
            (PEN_CHECK_BOUND(
                g_wgui_cat3003_cntx_ptr->pen_pos_x, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y, 
                0, 
                UI_device_height - MMI_ICON_BAR_HEIGHT, 
                UI_device_width, 
                MMI_ICON_BAR_HEIGHT)))
        {
            /* offset for icon bar pen handler */
            pos_iconbar.x = pos.x;
            pos_iconbar.y = pos.y;// - (UI_device_height - MMI_ICON_BAR_HEIGHT);

			/* reset the flag for next pen event */
            g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_TRUE;

            wgui_icon_bar_set_target_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            
            /* callback to app for re-start timer */
            if (g_wgui_cat3003_cntx_ptr->pen_up_icon_bar_cb!= NULL)
            {
                g_wgui_cat3003_cntx_ptr->pen_up_icon_bar_cb();
            }
            
            wgui_icon_bar_translate_pen_event(pos_iconbar, MMI_PEN_EVENT_UP);

        }
        else /* pen down point is on text area */
        {
            if (!mmi_imc_is_clipboard_state())
            {
                /* app need to show/hide iconbar and counter in this callback */
                if ((g_wgui_cat3003_cntx_ptr->is_tap_event == MMI_TRUE) && 
                    (g_wgui_cat3003_cntx_ptr->tap_event_hdlr != NULL))
                {
                    g_wgui_cat3003_cntx_ptr->tap_event_hdlr();
                }
            }

			/* reset the flag for next pen event */
            g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_TRUE;

            /* handle by editor */
            wgui_inputs_ml_linebase_pen_up_hdlr(pos);
        #ifdef __MMI_CLIPBOARD__
            mmi_imc_clipboard_pen_event_up_handler(pos);
        #endif /* __MMI_CLIPBOARD__ */  
        }

        return MMI_TRUE;
    }
    else /* not full screen */
    {
        if (wgui_icon_bar_is_created() == MMI_TRUE)
        {
            iconbar_h = MMI_ICON_BAR_HEIGHT;
        }
        /* if the pen down point is on text area */
        if (PEN_CHECK_BOUND(
                g_wgui_cat3003_cntx_ptr->pen_pos_x, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y, 
                0, 
                MMI_content_y, 
                MMI_content_width, 
                MMI_content_height - iconbar_h))
        {
            if (!mmi_imc_is_clipboard_state())
            {
                /* app need to show/hide iconbar and counter in this callback */
                if ((g_wgui_cat3003_cntx_ptr->is_tap_event == MMI_TRUE) && 
                    (g_wgui_cat3003_cntx_ptr->tap_event_hdlr != NULL))
                {
                    g_wgui_cat3003_cntx_ptr->tap_event_hdlr();
                }
            }

            /* reset the flag for next pen event */
            g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_TRUE;

            /* handle by editor */
            wgui_inputs_ml_linebase_pen_up_hdlr(pos);

        #ifdef __MMI_CLIPBOARD__
            mmi_imc_clipboard_pen_event_up_handler(pos);
        #endif /* __MMI_CLIPBOARD__ */    
            return MMI_TRUE;
        }
        g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_TRUE;
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_pen_abort_hdlr
 * DESCRIPTION
 *  pen abort handler of category 3003
 * PARAMETERS
 *  pos     [IN]        Pen abort position
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_cat3003_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct pos_iconbar;
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(PEN_CHECK_BOUND(
            g_wgui_cat3003_cntx_ptr->pen_pos_x, 
            g_wgui_cat3003_cntx_ptr->pen_pos_y, 
            0, 
            0, 
            UI_device_width, 
            UI_device_height)))
    {
        return MMI_FALSE;
    }

    /* in full screen */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE)
    {
        /* if the pen down point is on iconbar */
        if ((g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE) &&
            (PEN_CHECK_BOUND(
                g_wgui_cat3003_cntx_ptr->pen_pos_x, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y, 
                0, 
                UI_device_height - MMI_ICON_BAR_HEIGHT, 
                UI_device_width, 
                MMI_ICON_BAR_HEIGHT)))
        {
            /* offset for icon bar pen handler */
            pos_iconbar.x = pos.x;
            pos_iconbar.y = pos.y;// - (UI_device_height - MMI_ICON_BAR_HEIGHT);
            wgui_icon_bar_set_target_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            gdi_push_and_set_alpha_blending_source_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            
            wgui_icon_bar_translate_pen_event(pos_iconbar, MMI_PEN_EVENT_ABORT);

            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        ret = MMI_TRUE;
    }

#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_pen_event_abort_handler(pos);
#endif /* __MMI_CLIPBOARD__ */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_pen_repeat_hdlr
 * DESCRIPTION
 *  pen repeat handler of category 3003
 * PARAMETERS
 *  pos     [IN]        Pen repeat position
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_cat3003_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct pos_iconbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(PEN_CHECK_BOUND(
            g_wgui_cat3003_cntx_ptr->pen_pos_x, 
            g_wgui_cat3003_cntx_ptr->pen_pos_y, 
            0, 
            0, 
            UI_device_width, 
            UI_device_height)))
    {
        return MMI_FALSE;
    }

    /* in full screen */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE)
    {
        /* if the pen down point is on iconbar */
        if ((g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE) &&
            (PEN_CHECK_BOUND(
                g_wgui_cat3003_cntx_ptr->pen_pos_x, 
                g_wgui_cat3003_cntx_ptr->pen_pos_y, 
                0, 
                UI_device_height - MMI_ICON_BAR_HEIGHT, 
                UI_device_width, 
                MMI_ICON_BAR_HEIGHT)))
        {
            /* offset for icon bar pen handler */
            pos_iconbar.x = pos.x;
            pos_iconbar.y = pos.y;// - (UI_device_height - MMI_ICON_BAR_HEIGHT);
            wgui_icon_bar_set_target_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            gdi_push_and_set_alpha_blending_source_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
            
            wgui_icon_bar_translate_pen_event(pos_iconbar, MMI_PEN_EVENT_REPEAT);

            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_create_layer
 * DESCRIPTION
 *  create layer for iconbar and counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3003_create_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    S32 counter_offset_y = 0, counter_w, counter_h;
    gdi_handle icon_bar_hint_layer = 0;
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_multi_layer_enable();
    
    if (g_wgui_cat3003_cntx_ptr->is_full_screen == MMI_TRUE)
    {
        /* create iconbar layer */
        ret = gdi_layer_create(
                0,
                UI_device_height - MMI_ICON_BAR_HEIGHT,
                UI_device_width,
                MMI_ICON_BAR_HEIGHT,
                &g_wgui_cat3003_cntx_ptr->iconbar_layer);
        MMI_ASSERT(ret >= 0);
        wgui_icon_bar_set_target_layer(g_wgui_cat3003_cntx_ptr->iconbar_layer);
        
        /* set layer info */
        gdi_layer_push_and_set_active(g_wgui_cat3003_cntx_ptr->iconbar_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_opacity(TRUE, (U8)CAT3003_ICON_BAR_OPACITY);
        gdi_layer_clear(GDI_COLOR_GRAY);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        /* set counter layer offset */
        counter_offset_y = MMI_content_y;
    }

    /* get counter height */
    gui_sprintf(str, "%d/%d", 0, 0);
    gui_set_font(&MMI_small_font);
    gui_measure_string(str, &counter_w, &counter_h);
    counter_h += (CAT3003_COUNTER_STRING_GAP_X << 1); /* border */
    
    /* create counter layer */
    ret = gdi_layer_create(
            0,
            counter_offset_y + CAT3003_COUNTER_GAP_Y,
            UI_device_width,
            counter_h,
            &g_wgui_cat3003_cntx_ptr->counter_layer);
    MMI_ASSERT(ret >= 0);
    
    /* set layer info */
    gdi_layer_push_and_set_active(g_wgui_cat3003_cntx_ptr->counter_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, (U8)CAT3003_COUNTER_OPACITY);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    if (wgui_icon_bar_is_created())
    {
        icon_bar_hint_layer = wgui_icon_bar_get_hint_layer_handle();
    }

    gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, icon_bar_hint_layer, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_exit
 * DESCRIPTION
 *  Exits the category3003 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3003_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flatten for interrupt */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen)
    {
        if (g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE && g_wgui_cat3003_cntx_ptr->has_counter == MMI_TRUE)
        {
            gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, g_wgui_cat3003_cntx_ptr->counter_layer, 0);
        }
        else if (g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE)
        {
            gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, 0, 0);
        }
        else if (g_wgui_cat3003_cntx_ptr->has_counter == MMI_TRUE)
        {
            gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, g_wgui_cat3003_cntx_ptr->counter_layer, 0);
        }
        else
        {
            gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
        }
    }
    else
    {
        if (g_wgui_cat3003_cntx_ptr->has_counter == MMI_TRUE)
        {
            gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->counter_layer, 0, 0);
        }
        else
        {
            gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
        }
    }

#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_disconnect();
#endif /* __MMI_CLIPBOARD__ */

    reset_multiline_inputbox();
    wgui_inputs_ml_linebase_stop_text_scroll();
    wgui_inputs_ml_linebase_set_stop_scroll_callback(NULL);
    wgui_inputs_ml_linebase_set_percentage_callback((void*)NULL);
    wgui_inputs_ml_reset_pre_key_handler();
    
    /* flatten for interrupt */
    if (g_wgui_cat3003_cntx_ptr->full_screen_has_icon_bar == MMI_TRUE)
    {
        gdi_layer_flatten(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->iconbar_layer, 0, 0);
    }
    if (g_wgui_cat3003_cntx_ptr->has_counter == MMI_TRUE)
    {
        gdi_layer_flatten(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, g_wgui_cat3003_cntx_ptr->counter_layer, 0, 0);
    }
    
    /* free layer */
    if (g_wgui_cat3003_cntx_ptr->is_full_screen== MMI_TRUE)
    {
        gdi_layer_free(g_wgui_cat3003_cntx_ptr->iconbar_layer);
    }
    gdi_layer_free(g_wgui_cat3003_cntx_ptr->counter_layer);
 
    /* free parameter */
    if(g_wgui_cat3003_cntx_ptr != NULL)
    {
        OslMfree(g_wgui_cat3003_cntx_ptr);
		g_wgui_cat3003_cntx_ptr = NULL;
    } 
    
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_set_scr_bg_opacity(idle_scr_bg_opacity);
#endif 
}   /* end of ExitCategory3003Screen */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_show
 * DESCRIPTION
 *  Displays the linebased category375 screen(For FTE)
 * PARAMETERS
 *  name                    [IN]        Title string
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 *  stop_scroll_callback    [IN]        Stop scroll callback function
 *  page_info_app           [IN]        Info of page
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3003_show(
        U16 *name,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer,
        void (*stop_scroll_callback)(void),
        wgui_ml_line_base_info **page_info_app,
        MMI_BOOL is_fullscreen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_cat_id;
    wgui_ml_line_base_info *page_info_d = *page_info_app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pre-process memory */
    if(g_wgui_cat3003_cntx_ptr != NULL)
    {
        OslMfree(g_wgui_cat3003_cntx_ptr);
		g_wgui_cat3003_cntx_ptr = NULL;
    }    

    /* allocate memory and initialize */
    g_wgui_cat3003_cntx_ptr = (wgui_cat3003_cntx_struct*)OslMalloc(sizeof(wgui_cat3003_cntx_struct));
    MMI_ASSERT(g_wgui_cat3003_cntx_ptr != NULL);
    memset(g_wgui_cat3003_cntx_ptr, 0, sizeof(wgui_cat3003_cntx_struct));
    g_wgui_cat3003_cntx_ptr->is_tap_event = MMI_TRUE;
    g_wgui_cat3003_cntx_ptr->is_full_screen = is_fullscreen;

    if (wgui_icon_bar_is_created() == MMI_TRUE)
    {
        wgui_icon_bar_set_flags_on(GUI_ICON_BAR_FLAG_SET_BLT_LAYERS_BY_CATEGORY);
    }    
    

    /* create layer for iconbar and counter */
    wgui_cat3003_create_layer();
    
    gdi_layer_lock_frame_buffer();
    
    /* setup title and softkey */
    if(is_fullscreen == MMI_FALSE)
    {
        dm_add_title(name, get_image(title_icon));
        dm_add_softkey_id(left_softkey, right_softkey);
    }
    
    /* setup inputbox */
    wgui_inputs_ml_create_set_buffer((UI_string_type)NULL, 0, 0, 0);
    if(is_fullscreen == MMI_FALSE)
    {
        wgui_inputs_ml_move(MMI_content_x, MMI_content_y);
        wgui_inputs_ml_resize(MMI_content_width, MMI_content_height - MMI_ICON_BAR_HEIGHT);
    }
    else
    {
        wgui_inputs_ml_move(0, 0);
        wgui_inputs_ml_resize(UI_device_width, UI_device_height);
    }
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE;
    wgui_inputs_ml_linebase_init(page_info_d);
    wgui_inputs_ml_linebase_set_stop_scroll_callback((void*)stop_scroll_callback);
    wgui_inputs_ml_linebase_set_percentage_callback((void*)wgui_cat3003_percentage_callback);

    /* register key handler and set flags */
    wgui_inputs_ml_register_viewer_keys();
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);

#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_connect(INPUTBOX_MULTILINE_EBOOK);
#ifdef __MMI_TOUCH_SCREEN__
    /* To override IME pen handler */
    wgui_register_general_pen_handler();
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_CLIPBOARD__ */
    
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    dm_get_scr_bg_opacity(&idle_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_high));
#endif 

    /* For full screen ebook, setup toolbar hide callback function */
    if (is_fullscreen)
    {
        wgui_icon_bar_register_hide_function(wgui_cat3003_draw_iconbar_bg);
    }

    /* set history and register darw control area callback */
    if (is_fullscreen)
    {
        wgui_inputs_ml_set_category_history(MMI_CATEGORY74_ID, history_buffer);
    }
    else
    {
        wgui_inputs_ml_set_category_history(MMI_CATEGORY74_ID, history_buffer);
    }
    
    gdi_layer_unlock_frame_buffer();

    /* set the pen handler */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat3003_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat3003_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat3003_pen_repeat_hdlr, MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat3003_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat3003_pen_abort_hdlr, MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if (is_fullscreen)
    {
        dm_data_cat_id= MMI_CAT3003_ID_FULLSCREEN;
    }
    else
    {
        dm_data_cat_id =  MMI_CAT3003_ID;
    }
    wgui_cat_setup_category_default_history(
        dm_data_cat_id,
        DM_CLEAR_SCREEN_BACKGROUND,
        wgui_cat3003_exit);
    dm_redraw_category_screen();
    
    if (page_info_d->scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON && page_info_d->scroll_speed != 0)
    {
        wgui_inputs_ml_linebase_start_auto_scroll();
    }
    else
    {
        wgui_inputs_ml_linebase_stop_text_scroll();
    }
    
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;

    SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_previous_line, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_linebase_next_line, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);   
}


#endif /* __MMI_FTE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  ShowCategory77Screen
 * DESCRIPTION
 *  Full screen ebook viewer
 * PARAMETERS
 *  name                    [IN]        Title string
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 *  stop_scroll_callback    [IN]        Stop scroll callback function 
 *  page_info_app           [IN]        Info of page
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory77Screen(
        U16 *name,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer,
        void (*stop_scroll_callback)(void),
        gui_page_info_app **page_info_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_flag = DM_CLEAR_SCREEN_BACKGROUND;
    S32 l;
    gui_page_info_app *page_info_d = *page_info_app;
    dm_coordinates gui_multiline_get_coordinates;
#if defined(__MMI_TOUCH_SCREEN__)
    const gui_virtual_keyboard_pen_enum disable_backspace_list[] = {GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_NONE};
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    wgui_paging_set_full_screen_flag(TRUE);
    gui_multiline_get_coordinates.s16X = 0;
    gui_multiline_get_coordinates.s16Y = 0;
    gui_multiline_get_coordinates.s16Width = MAIN_LCD_DEVICE_WIDTH;
    gui_multiline_get_coordinates.s16Height = MAIN_LCD_DEVICE_HEIGHT;
    if (page_info_d->key_callback != NULL)
    {
        gui_multiline_get_coordinates.s16Height -= (MMI_title_y + 3);
    }
    MMI_content_height_prev = MMI_content_height;
    MMI_content_y_prev = MMI_content_y;
    MMI_content_y = 0;
    MMI_content_height = MAIN_LCD_DEVICE_HEIGHT;
#else /* __MMI_TOUCH_SCREEN__ */ 
    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY77_ID,
        DM_MULTILINE_INPUTBOX1,
        -1,
        &gui_multiline_get_coordinates);
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* 061507 128x160 touch Start */
    //wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);

    gui_lock_double_buffer();
    entry_full_screen();
    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    MMI_title_string = (UI_string_type) name;
    MMI_title_icon = (PU8) get_image(title_icon);

    //l = gui_strlen((UI_string_type) buffer);
    //MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
    //create_multiline_inputbox_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
#ifdef __MMI_TOUCH_SCREEN__
    if (page_info_d->key_callback != NULL)
    {
        mmi_imm_set_events(MMI_FALSE, disable_backspace_list);
        mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_123); //Need to be modified
        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX;
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
        mmi_imc_disable_handwriting();
        mmi_imc_disable_key_input();
        mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_multiline);
        gui_multiline_get_coordinates.s16Height = MAIN_LCD_DEVICE_HEIGHT - mmi_imc_get_vk_area_height();
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX;

    wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);
    l = gui_strlen((UI_string_type) buffer);
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
    create_multiline_inputbox_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
/* 061507 128x160 touch End */

    wgui_paging_multiline_inputbox_set_stop_scroll_callback((void*)stop_scroll_callback);
    wgui_paging_multiline_set_page(page_info_d->start_id, page_info_d->end_id);
    wgui_paging_multiline_set_font(page_info_d->font_size, page_info_d->font_style);
    /* PMT MMSVIEWER */
    wgui_paging_multiline_set_get_page_callback(page_info_d->get_page_cb);                    
    register_multiline_inputbox_viewer_keys();
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE); 
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
    if (page_info_d->highlight_string == 1)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        wgui_paging_highlight_search_string(page_info_d->jump_offset_from_app, page_info_d->search_str_len);
    }

    MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
    if (!page_info_d->fixed_view_flag)
        MMI_multiline_inputbox.jump_offset_from_app = page_info_d->jump_offset_from_app;
    else
        MMI_multiline_inputbox.jump_offset_from_app = 0;
    MMI_multiline_inputbox.search_flag_is_on = page_info_d->search_flag_is_on;
    MMI_multiline_inputbox.size_of_total_data = page_info_d->doc_size;
    MMI_multiline_inputbox.override_direction = page_info_d->override_direction ? 2 : 1;
    show_multiline_inputbox_no_draw();
    wgui_paging_set_scrollbar_range(page_info_d->doc_size);
    wgui_paging_reset_show_percentage_flag();
//    if (page_info_d->jump_to_end == 0)
//    {
//        wgui_paging_jump_to_end();
//    }
    set_multiline_inputbox_category_history(MMI_CATEGORY77_ID, history_buffer);

    wgui_paging_multiline_set_scroll_info(&page_info_d);
    if(old_font_size != page_info_d->font_size || old_font_style != page_info_d->font_style)
        wgui_paging_multiline_clear_last_percentage();

    if (old_font_size == page_info_d->font_size && old_font_style == page_info_d->font_style)
    {
        if (page_info_d->text_offset != 0 || page_info_d->fixed_view_flag)
        {
            if (MMI_multiline_inputbox.text_offset_y != page_info_d->last_text_offset_y)
            {
                MMI_multiline_inputbox.text_offset_y = page_info_d->last_text_offset_y;
            }
        } 
    }

    if (page_info_d->text_offset)
    {
        wgui_paging_multiline_set_percentage(page_info_d->start_id, page_info_d->text_offset);
    }
    else
    {
        show_multiline_inputbox_no_draw();
        if (MMI_multiline_inputbox.search_flag_is_on)
        {
            show_multiline_inputbox_no_draw();
            wgui_paging_multiline_set_percentage(page_info_d->start_id, (S16)MMI_multiline_inputbox.text_offset);
        }
        else
        {
            wgui_paging_multiline_set_percentage(page_info_d->start_id, page_info_d->jump_offset_from_app);
        }
    }

    old_font_size = page_info_d->font_size;
    old_font_style = page_info_d->font_style;

    if (page_info_d->jump_to_end == 0)
    {
        wgui_paging_jump_to_end();
    }
    gui_unlock_double_buffer();

#ifdef __MMI_TOUCH_SCREEN__
    dm_register_category_controlled_callback(RedrawCategoryControlledArea75Screen);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_up_hdlr, MMI_PEN_EVENT_UP);

    if (page_info_d->key_callback != NULL)
    {
        dm_data_flag |= DM_SHOW_VKPAD;
        dm_register_vkpad_callback(mmi_imc_redraw_screen_by_state);
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    wgui_cat_setup_category_default_history(
        MMI_CATEGORY77_ID,
        dm_data_flag,
        ExitCategory77Screen);
    dm_redraw_category_screen();

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    if (page_info_d->scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
    {
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
    else
    {
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_page, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_next_page, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
    if (page_info_d->scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON && page_info_d->scroll_speed != 0)
    {
        wgui_paging_start_text_scroll();
    }
    else
    {
        wgui_paging_stop_text_scroll();
    }

}   /* end of ShowCategory77Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory77Screen
 * DESCRIPTION
 *  Exit category 77 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory77Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_reset();
    MMI_multiline_inputbox.previous_shared_bytes = 0;
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    wgui_paging_stop_text_scroll();
    wgui_paging_reset_show_percentage_flag();
    wgui_paging_multiline_inputbox_set_stop_scroll_callback(NULL);
#ifdef __MMI_TOUCH_SCREEN__
    MMI_content_height = MMI_content_height_prev;
    MMI_content_y = MMI_content_y_prev;
    mmi_imc_disconnect();
#endif /* __MMI_TOUCH_SCREEN__ */ 
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
}   /* end of ExitCategory77Screen */

#endif /* __MMI_EBOOK_READER__ */ 


/*****************************************************************************
 * FUNCTION
*  wgui_cat_ebook_is_full_screen
* DESCRIPTION
*  current screen is full screen ebook or not.
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL wgui_cat_ebook_is_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EBOOK_READER__
    if(g_dm_data.s32CatId == MMI_CATEGORY375_ID_FULLSCREEN)
    {
        ret = g_wgui_category375_is_fullscreen;
    }
#ifdef __MMI_FTE_SUPPORT__
    else if (g_dm_data.s32CatId == MMI_CAT3003_ID_FULLSCREEN)
    {
        if (g_wgui_cat3003_cntx_ptr != NULL)
        {
            ret = g_wgui_cat3003_cntx_ptr->is_full_screen;
        }
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_EBOOK_READER__ */
    return ret;
}


///TODO: Only for OBIGO_Q03C_MMS_V01
/*****************************************************************************
 * FUNCTION
 *  ShowCategory76Screen
 * DESCRIPTION
 *  Displays the category76 screen
 *  handle the UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_size             [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory76Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

    dm_add_softkey_id(left_softkey, right_softkey);
    dm_add_title_id(title, title_icon);

    l = gui_strlen((UI_string_type) buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR);
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_get_scr_bg_opacity(&idle_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif     
    register_multiline_inputbox_viewer_keys();

    set_multiline_inputbox_category_history(MMI_CATEGORY76_ID, history_buffer);

    gdi_layer_unlock_frame_buffer();

    wgui_cat_setup_category_default_history(
        MMI_CATEGORY76_ID,
        DM_CLEAR_SCREEN_BACKGROUND,
        ExitCategory74Screen);
    dm_redraw_category_screen();

}   /* end of ShowCategory76Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory78Screen
 * DESCRIPTION
 *  Displays the category78 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  icon_callback           [IN]        
 *  buffer                  [IN]        Buffer the input box should use.
 *  buffer_size             [IN]        Size of the buffer.
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory78Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        multi_line_input_box_icon_hdlr icon_callback,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cat_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    if (g_wgui_cat_slide_control_ptr != NULL)
    {
        cat_id = MMI_CATEGORY78_ID_SLIDE_CONTROL;
    }
    else
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
    {
        cat_id = MMI_CATEGORY78_ID;
    }
    
    gdi_layer_lock_frame_buffer();
    wgui_cat_text_viewer_show_internal_by_res_id(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        0,
        MMI_TRUE,
        MMI_FALSE,
        (UI_buffer_type)buffer,
        buffer_size,
        history_buffer,
        cat_id);

    /* icon_callback will be reset when create multiline editor */
    MMI_multiline_inputbox.icon_callback = icon_callback;
    wgui_inputs_ml_set_category_history((U16)cat_id, history_buffer);
    wgui_inputs_ml_show();
    
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();

}


/* barcode */
#if defined(__MMI_CLIPBOARD__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat228_pen_down_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat228_pen_down_event_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = 0;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   ret = gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &multi_line_input_box_event);
   
#ifdef __MMI_CLIPBOARD__
   if (mmi_imc_is_clipboard_state() && (MMI_multiline_inputbox.hilite_str_number == 0))
   {
       mmi_imc_clipboard_pen_event_down_handler(pos);
       return;
   }
#endif
   
   if ((ret == 1) && (multi_line_input_box_event != GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR))
   {
       MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
       gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
       MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
       if (gui_multi_line_input_box_is_pen_down_in_hilite(&MMI_multiline_inputbox))
       {
           wgui_inputs_ml_set_pen_down_flag();
           gui_multi_line_input_box_go_to_hilite(
               &MMI_multiline_inputbox,
               MMI_multiline_inputbox.current_hilite_idx,
               MMI_FALSE);
           wgui_inputs_ml_clear_pen_down_flag();
           wgui_general_pen_down_hdlr(pos);
       }
       else
       {
#ifdef __MMI_CLIPBOARD__
           if (MMI_multiline_inputbox.hilite_str_number == 0)
           {
               mmi_imc_clipboard_pen_event_down_handler(pos);
           }
           else
#endif /* __MMI_CLIPBOARD__ */
           {
               wgui_general_pen_down_hdlr(pos);
           }
       }
   }
   else
   {
       if (MMI_multiline_inputbox.hilite_str_number == 0)
       {
           mmi_imc_clipboard_pen_event_down_handler(pos);
       }
       else
       {
           wgui_general_pen_down_hdlr(pos);
       }
   }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  ShowCategory228Screen
 * DESCRIPTION
 *  show category 228 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen  
 *  title_icon              [IN]        Icon shown with the title  
 *  left_softkey            [IN]        Left softkey label  
 *  left_softkey_icon       [IN]        Icon for the Left softkey  
 *  right_softkey           [IN]        Right softkey label  
 *  right_softkey_icon      [IN]        Icon for the right softkey  
 *  buffer                  [IN]        String buffer to set to input box
 *  buffer_size             [IN]        Buffer size of input box
 *  hilite_str_list         [IN]        Hilite string list
 *  hilite_str_number       [IN]        Hilite string number
 *  hilite_cb               [IN]        Hilite callback
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory228Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *buffer,
        S32 buffer_size,
        HILITE_STR hilite_str_list[],
        U16 hilite_str_number,
        void (*hilite_cb) (S32 idx),
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;
    U8 h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
    wgui_inputs_ml_register_viewer_keys();
    wgui_inputs_ml_register_hilite_keys();
    MMI_multiline_inputbox.hilite_list = hilite_str_list;
    MMI_multiline_inputbox.hilite_str_number = hilite_str_number;
    MMI_multiline_inputbox.current_hilite_idx = 0;

    wgui_inputs_ml_resize(MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_inputs_ml_register_hilite_pen_event_handler();
#endif 

    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT);
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_get_scr_bg_opacity(&idle_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif 
    MMI_multiline_inputbox.hilite_cb = hilite_cb;

    wgui_inputs_ml_show_no_draw();  /* initialize multiline internal data for set text highlight. */
    h = set_multiline_inputbox_category_history(MMI_CATEGORY228_ID, history_buffer);
    if (hilite_str_number != 0)
    {
	    if (h)
	    {
	        gui_multi_line_input_box_go_to_hilite(
	            &MMI_multiline_inputbox,
	            (U16)MMI_multiline_inputbox.current_hilite_idx,
	            MMI_FALSE);
	    }
	    else
	    {
	        gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
	    }
    }
    gdi_layer_unlock_frame_buffer();

#ifdef __MMI_CLIPBOARD__
    if (hilite_str_number == 0)
    {
        mmi_imc_clipboard_connect(INPUTBOX_MULTILINE);
    }
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(wgui_cat228_pen_down_event_handler);
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_CLIPBOARD__ */

    wgui_cat_setup_category_default_history(
        MMI_CATEGORY228_ID,
        DM_CLEAR_SCREEN_BACKGROUND,
        ExitCategory74Screen);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_set_highlight_click_callback
 * DESCRIPTION
 *  set the highlight text click callback.
 * PARAMETERS
 *  click_cb :               [IN] (N?A) callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_text_viewer_set_highlight_click_callback(void (*click_cb) (S32 idx))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    MMI_multiline_inputbox.hilite_click_cb = click_cb;
#endif 
}   /* end of ExitCategory74Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory152Screen
 * DESCRIPTION
 *  Exit category152 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory152Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_disconnect();
#endif /* __MMI_CLIPBOARD__ */
}   /* end of ExitCategory152Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory152Screen
 * DESCRIPTION
 *  Displays the category screen 152
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  message                 [IN]        Message
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory152Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

    /* the title should not scroll in category74 */
    wgui_cat_text_viewer_show_internal_by_res_id(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        0,
        MMI_TRUE,
        MMI_FALSE,
        (UI_buffer_type)message,
        gui_strlen((UI_string_type)message),
        NULL,
        MMI_CATEGORY152_ID);
}   /* end of ShowCategory152Screen */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory2Screen
 * DESCRIPTION
 *  Displays the category2 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  message                 [IN]        Message string
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory2Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory7Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        (U8*) get_string(message),
        history_buffer);
}   /* end of ShowCategory2Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory7Screen
 * DESCRIPTION
 *  Displays the category7 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  message                 [IN]        Notification message (string. Not string ID)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory7Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;
    UI_buffer_type text_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

    MMI_message_string = (UI_string_type) (message);
    l = gui_strlen(MMI_message_string);
    
    g_wgui_cat7_string_buf = mmi_frm_scrmem_alloc_framebuffer(WGUI_CAT7_STRING_BUF_SIZE);
    
    if(g_wgui_cat7_string_buf != NULL && WGUI_CAT7_STRING_BUF_SIZE > ((2 * l) + 2))
    {
        mmi_ucs2cpy((S8*)g_wgui_cat7_string_buf, (S8*)message);
        text_buf = (UI_buffer_type)g_wgui_cat7_string_buf;
    }
    else
    {
        text_buf = (UI_buffer_type)MMI_message_string;
    }

    wgui_cat_text_viewer_show_internal_by_res_id(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        0,
        MMI_TRUE,
        MMI_FALSE,
        text_buf,
        l,
        NULL,
        MMI_CATEGORY7_ID);
}   /* end of ShowCategory7Screen */


static wgui_cat3006_context_struct *wgui_cat3006_cntx = NULL;
/*****************************************************************************
 * FUNCTION
 *  wgui_cat3006_draw_ctrl_area
 * DESCRIPTION
 *  redraw video and video info for category3006
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3006_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 preview_name_w, preview_name_h, preview_time_w, preview_time_h, image_w, image_h;
    S32 resized_offset_x, resized_offset_y, resized_width, resized_height , resized_gap_x = 0;
#if defined(__MMI_FTE_SUPPORT__)
    #if defined(__MMI_MAINLCD_240X320__)
        stFontAttribute *f = &MMI_small_font;
    #else
        stFontAttribute *f = &MMI_medium_font;
    #endif
#else
    stFontAttribute *f = &MMI_medium_font;
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* clear control area */
#ifdef __MMI_FTE_SUPPORT__
    gdi_draw_solid_rect(
        0,
        WGUI_CAT3006_CONTROL_AREA_Y,
        UI_device_width - 1,
        WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_CONTROL_AREA_H - 1,
        GDI_COLOR_WHITE);
#else
    gdi_draw_solid_rect(
        0,
        WGUI_CAT3006_CONTROL_AREA_Y,
        UI_device_width - 1,
        WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_CONTROL_AREA_H - 1,
        GDI_COLOR_TRANSPARENT);
#endif
    
    /* show image */
    if (wgui_cat3006_cntx->preview_image)
    {
#ifdef __MMI_FTE_SUPPORT__
        GDI_HANDLE act_layer;

        gdi_layer_get_active(&act_layer);

        gdi_push_and_set_alpha_blending_source_layer(act_layer);
#endif
        gui_measure_image(wgui_cat3006_cntx->preview_image, &image_w, &image_h);
        gdi_image_util_fit_bbox(
			    WGUI_CAT3006_PREVIEW_W,
			    WGUI_CAT3006_PREVIEW_H,
			    image_w,
			    image_h,
			    &resized_offset_x,
			    &resized_offset_y,
			    &resized_width,
			    &resized_height);

       gdi_image_draw_resized(
            WGUI_CAT3006_PREVIEW_X,
            WGUI_CAT3006_PREVIEW_Y + resized_offset_y + ((WGUI_CAT3006_CONTROL_AREA_H - WGUI_CAT3006_PREVIEW_H) >> 1),
            resized_width,
            resized_height,
            wgui_cat3006_cntx->preview_image);

#ifdef __MMI_FTE_SUPPORT__
       gdi_pop_and_restore_alpha_blending_source_layer();
#endif
       if (resized_offset_x > 0)
       {
           resized_gap_x = (resized_offset_x << 1);
       }
    }

    /* video name */
    gui_set_font(f);
    gui_measure_string(wgui_cat3006_cntx->preview_name, &preview_name_w, &preview_name_h);
    if (preview_name_w > (WGUI_CAT3006_NAME_W + resized_gap_x))
    {
        wgui_cat3006_cntx->preview_name_scrolling_text.x -= resized_gap_x;
        wgui_cat3006_cntx->preview_name_scrolling_text.width += resized_gap_x;

        gui_show_scrolling_text(&wgui_cat3006_cntx->preview_name_scrolling_text);
    }
    else
    {
        gui_set_text_color(*(current_MMI_theme->inputbox_normal_text_color));
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(WGUI_CAT3006_NAME_X + WGUI_CAT3006_NAME_W, WGUI_CAT3006_NAME_Y + ((WGUI_CAT3006_NAME_H - preview_name_h) >> 1));
        }
        else
        {
            gui_move_text_cursor(WGUI_CAT3006_NAME_X - resized_gap_x, WGUI_CAT3006_NAME_Y + ((WGUI_CAT3006_NAME_H - preview_name_h) >> 1));
        }
        gui_print_text(wgui_cat3006_cntx->preview_name);
    }

    /* video time */
    gui_set_font(f);
    gui_measure_string(wgui_cat3006_cntx->preview_time, &preview_time_w, &preview_time_h);
    gui_set_text_color(*(current_MMI_theme->inputbox_normal_text_color));
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(WGUI_CAT3006_TIME_X + WGUI_CAT3006_TIME_W, WGUI_CAT3006_TIME_Y + ((WGUI_CAT3006_TIME_H - preview_time_h) >> 1));
        gui_print_truncated_text(
            WGUI_CAT3006_TIME_X + WGUI_CAT3006_TIME_W, 
            WGUI_CAT3006_TIME_Y + ((WGUI_CAT3006_TIME_H - preview_time_h) >> 1),
            WGUI_CAT3006_TIME_W + resized_gap_x,
            wgui_cat3006_cntx->preview_time);
    }
    else
    {
        gui_move_text_cursor(WGUI_CAT3006_TIME_X - resized_gap_x, WGUI_CAT3006_TIME_Y + ((WGUI_CAT3006_TIME_H - preview_time_h) >> 1));
        gui_print_truncated_text(
            WGUI_CAT3006_TIME_X - resized_gap_x, 
            WGUI_CAT3006_TIME_Y + ((WGUI_CAT3006_TIME_H - preview_time_h) >> 1),
            WGUI_CAT3006_TIME_W + resized_gap_x,
            wgui_cat3006_cntx->preview_time);
    }

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3006_scrolling_timer
 * DESCRIPTION
 *  timer callback of category3006scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3006_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&wgui_cat3006_cntx->preview_name_scrolling_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3006_scrolling_text_draw_background
 * DESCRIPTION
 *  draw background callback function of scrolling text of category3006
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat3006_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
#else
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3006_exit
 * DESCRIPTION
 *  Exits the category3006 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3006_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLIPBOARD__
    mmi_imc_clipboard_disconnect();
#endif /* __MMI_CLIPBOARD__ */

    wgui_inputs_ml_reset();
    gui_scrolling_text_stop(&wgui_cat3006_cntx->preview_name_scrolling_text);

    if (wgui_cat3006_cntx != NULL)
    {
        mmi_frm_scrmem_free(wgui_cat3006_cntx);
        wgui_cat3006_cntx = NULL;
    }
}   /* end of ExitCategory74Screen */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3006_show
 * DESCRIPTION
 *  Show text viewer screen with preview video.
 * PARAMETERS
 *  title :                   [IN] (TITLE) Title for the screen
 *  title_icon :              [IN] (N/A) Icon shown with the title
 *  left_softkey :            [IN] (LSK) Left softkey label
 *  left_softkey_icon :       [IN] (N/A) Icon for the Left softkey
 *  right_softkey :           [IN] (RSK) Right softkey label
 *  right_softkey_icon :      [IN] (N/A) Icon for the right softkey
 *  buffer :                  [IN] (N/A) Buffer the input box should use
 *  history_buffer :          [IN] (N/A) History buffer
 *  video_name :              [IN] (N/A) video name string
 *  video_time :              [IN] (N/A) video time string
 *  preview_image :           [IN] (N/A) preview image
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat3006_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        UI_buffer_type buffer,
        UI_buffer_type history_buffer,
        WCHAR* video_name,
        WCHAR* video_time,
        PU8 preview_image,
        U32 icon_position,
        PU8 icon_data,
        HILITE_STR hilite_str_list[],
        U16 hilite_str_number,
        void (*hilite_cb) (S32 idx),
        void (*click_cb) (S32 idx))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //dm_data_struct dm_data;
    S32 l;
#if defined(__MMI_FTE_SUPPORT__)
    #if defined(__MMI_MAINLCD_240X320__)
        stFontAttribute *f = &MMI_small_font;
    #else
        stFontAttribute *f = &MMI_medium_font;
    #endif
#else
    stFontAttribute *f = &MMI_medium_font;
#endif
    U8 h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* setup softkey and title */
    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    dm_add_title(title, title_icon);

    /* context memory */
    wgui_cat3006_cntx = (wgui_cat3006_context_struct*)mmi_frm_scrmem_alloc_framebuffer(sizeof(wgui_cat3006_context_struct));
    MMI_ASSERT(wgui_cat3006_cntx);
    memset(wgui_cat3006_cntx, 0, sizeof(wgui_cat3006_context_struct));

    /* setup context */
    wgui_cat3006_cntx->preview_name = video_name;
    wgui_cat3006_cntx->preview_time = video_time;
    wgui_cat3006_cntx->preview_image = preview_image;

    /* setup icon callback */
    if (icon_data)
    {
        S32 width, height, len, i;
        
        wgui_cat3006_cntx->icon_table[0].icon = icon_data;
        gui_measure_image(icon_data, &width, &height);
        wgui_cat3006_cntx->icon_table[0].icon_height = height;
        wgui_cat3006_cntx->icon_table[0].icon_width = width;
        wgui_cat3006_cntx->icon_table[0].string[0] = 0x01;
        wgui_cat3006_cntx->icon_table[0].string[1] = 0x02;
        wgui_config_general_multiline_icon_handler(MMI_FALSE, 1, wgui_cat3006_cntx->icon_table);
        MMI_multiline_inputbox.icon_callback = wgui_inputs_ml_general_icon_handler;
        len = gui_strlen((UI_string_type) buffer);
        for (i = ((len + 1) * ENCODING_LENGTH); i >= (icon_position * ENCODING_LENGTH); i--)
        {
            buffer[i + 4] = buffer[i];
        }
        buffer[i + 1] = 0x01;
        buffer[i + 2] = 0x00;
        buffer[i + 3] = 0x02;
        buffer[i + 4] = 0x00;

        for (i = 0; i < hilite_str_number; i++)
        {
            if ((&buffer[i + 1]) < hilite_str_list[i].str_addr)
            {
                hilite_str_list[i].str_addr += (2 * ENCODING_LENGTH);
            }
        }
    }

    gui_set_font(f);
    gui_create_scrolling_text(
        &wgui_cat3006_cntx->preview_name_scrolling_text,
        WGUI_CAT3006_NAME_X,
        WGUI_CAT3006_NAME_Y,
        WGUI_CAT3006_NAME_W,
        WGUI_CAT3006_NAME_H,
        (UI_string_type) wgui_cat3006_cntx->preview_name,
        wgui_cat3006_scrolling_timer,
        wgui_cat3006_scrolling_text_draw_background,
        *current_MMI_theme->inputbox_normal_text_color,
        *current_MMI_theme->inputbox_normal_text_color);

    /* setup inputbox */
    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, l, l, 0);
    wgui_inputs_ml_register_viewer_keys();
    if (icon_data)
    {
        MMI_multiline_inputbox.icon_callback = wgui_inputs_ml_general_icon_handler;
    }

    MMI_multiline_inputbox.flags = (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND | UI_MULTI_LINE_INPUT_BOX_RICHTEXT;
    
    if (hilite_str_number > 0)
    {
        wgui_inputs_ml_register_hilite_keys();
        MMI_multiline_inputbox.hilite_list = hilite_str_list;
        MMI_multiline_inputbox.hilite_str_number = hilite_str_number;
        MMI_multiline_inputbox.current_hilite_idx = 0;
        MMI_multiline_inputbox.hilite_cb = hilite_cb;
#ifdef __MMI_TOUCH_SCREEN__
        wgui_inputs_ml_register_hilite_pen_event_handler();
        MMI_multiline_inputbox.hilite_click_cb = click_cb;
#endif 
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    
    h = wgui_inputs_ml_set_category_history((U16)MMI_CAT3006_ID, history_buffer);
    if (hilite_str_number != 0)
    {
	    if (h)
	    {
	        gui_multi_line_input_box_go_to_hilite(
	            &MMI_multiline_inputbox,
	            (U16)MMI_multiline_inputbox.current_hilite_idx,
	            MMI_FALSE);
	    }
	    else
	    {
	        gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
	    }
    }

    gdi_layer_unlock_frame_buffer();

    dm_register_category_controlled_callback(wgui_cat3006_draw_ctrl_area);
    wgui_cat_setup_category_default_history(
        MMI_CAT3006_ID,
        DM_CLEAR_SCREEN_BACKGROUND,
        wgui_cat3006_exit);
    
    dm_redraw_category_screen();
}   /* end of wgui_cat3006_show */



#if defined(__SOCIAL_NETWORK_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat74_setup_sns_title
 * DESCRIPTION
 *  setup the sns title.
 * PARAMETERS
 *  wgui_cat_sns_title      [IN]        sns title
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat74_setup_sns_title(wgui_cat_sns_title* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat74_sns_title = title;
}


//extern void wgui_cate_sns_show_title(S32 x, S32 y, S32 width, S32 height, wgui_cat_sns_title *area);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_sns_show_title
 * DESCRIPTION
 *  x			[IN]
 *  y			[IN]
 *  width		[IN]
 *  height	[IN]
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_text_viewer_sns_show_title(S32 x, S32 y, S32 width, S32 height, wgui_cat_sns_title *area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S32 clip_x1, clip_y1, xx;
    S32 icon_w = 0, icon_h, text_w = 0, text_h = 0;
    gdi_handle target_layer, alpha_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    /* set layer */
    gdi_layer_get_active(&target_layer);
    gdi_layer_push_and_set_active(target_layer);
    alpha_layer = dm_get_scr_bg_layer();
    if (alpha_layer == GDI_ERROR_HANDLE)
    {
        alpha_layer = target_layer;
    }
    gdi_push_and_set_alpha_blending_source_layer(alpha_layer);
    
    /* draw background to transparent */
    gui_push_clip();
    gui_set_clip(x, y, x + width, y + height);
    if (wgui_is_wallpaper_on_bottom())
    {
        gdi_draw_solid_rect(x, y, x + width, y + height, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(x, y, x + width, y + height, GDI_COLOR_WHITE);
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gui_pop_clip();

	width -= MMI_fixed_list_menu.vbar.width;
    /* draw thumbnail icon */
	y = y + WGUI_THUMBNAIL_TOP_BOM_GAP + 1;
	xx = x;
    if (area->tn_icon_filepath)
    {
        S32 resized_x = 0, resized_y = 0, resized_w = 0, resized_h = 0;
		GDI_RESULT ret;
		if(mmi_fe_get_r2l_state())
		{
			clip_x1 = x + width - GUI_ICONTEXT_MENUITEM_ICON_X - WGUI_CAT_SNS_THUMBNAIL_W;
		}
		else
		{
			clip_x1 = GUI_ICONTEXT_MENUITEM_ICON_X + x;
		}
        clip_y1 = y;
        gui_push_clip();
        gui_set_clip(
			clip_x1, 
			clip_y1, 
			clip_x1 + WGUI_CAT_SNS_THUMBNAIL_W, 
			clip_y1 + WGUI_CAT_SNS_THUMBNAIL_H);
        ret = gdi_image_get_dimension_file((CHAR*)area->tn_icon_filepath, &icon_w, &icon_h);
		resized_y = clip_y1;
		if (ret == GDI_SUCCEED)
		{
		    if (icon_w < WGUI_CAT_SNS_THUMBNAIL_W && icon_h < WGUI_CAT_SNS_THUMBNAIL_H)
		    {
		        resized_x += ((WGUI_CAT_SNS_THUMBNAIL_W - icon_w)>>1);
				resized_y += ((WGUI_CAT_SNS_THUMBNAIL_H - icon_h)>>1);
				resized_w = icon_w;
				resized_h = icon_h;
		    }
			else
			{
				gdi_util_fit_box(
					GDI_UTIL_MODE_LONG_SIDE_FIT,
					WGUI_CAT_SNS_THUMBNAIL_W, WGUI_CAT_SNS_THUMBNAIL_H,
					icon_w, icon_h,
					&resized_x, &resized_y, &resized_w, &resized_h);
			}
			resized_x += clip_x1;
			resized_y = clip_y1;
			
			gdi_image_draw_resized_file(
				resized_x, resized_y, resized_w, resized_h, (CHAR*)area->tn_icon_filepath);
			if(mmi_fe_get_r2l_state())
			{
				xx = resized_x - WGUI_THUMBNAIL_LEFT_RIGHT_GAP;
				
			}
			else
			{
				xx = resized_x + resized_w + WGUI_THUMBNAIL_LEFT_RIGHT_GAP;
			}
		}
        gui_pop_clip();
    }
	else
	{
	    S32 resized_x = 0, resized_y = 0, resized_w = 0, resized_h = 0;
		
		if(mmi_fe_get_r2l_state())
		{
			clip_x1 = x + width - GUI_ICONTEXT_MENUITEM_ICON_X - WGUI_CAT_SNS_THUMBNAIL_W;
		}
		else
		{
			clip_x1 = GUI_ICONTEXT_MENUITEM_ICON_X + x;
		}
		clip_y1 = y;
	    gui_measure_image((PU8)GetImage(area->tn_icon_id), &icon_w, &icon_h);
		resized_y = clip_y1;
		if (icon_w < WGUI_CAT_SNS_THUMBNAIL_W && icon_h < WGUI_CAT_SNS_THUMBNAIL_H)
		{
			resized_x += ((WGUI_CAT_SNS_THUMBNAIL_W - icon_w)>>1);
			resized_y += ((WGUI_CAT_SNS_THUMBNAIL_H - icon_h)>>1);
			resized_w = icon_w;
			resized_h = icon_h;
		}
		else
		{
			gdi_util_fit_box(
				GDI_UTIL_MODE_LONG_SIDE_FIT,
				WGUI_CAT_SNS_THUMBNAIL_W, WGUI_CAT_SNS_THUMBNAIL_H,
				icon_w, icon_h,
				&resized_x, &resized_y, &resized_w, &resized_h);
		}
		resized_x += clip_x1;
		resized_y = clip_y1;
		gui_push_clip();
		gui_set_clip(
			clip_x1, 
			clip_y1, 
			clip_x1 + WGUI_CAT_SNS_THUMBNAIL_W, 
			clip_y1 + WGUI_CAT_SNS_THUMBNAIL_H);
		gdi_image_draw_id(resized_x, resized_y, area->tn_icon_id);
		if(mmi_fe_get_r2l_state())
		{
			xx = resized_x - WGUI_THUMBNAIL_LEFT_RIGHT_GAP;
			
		}
		else
		{
			xx = resized_x + resized_w + WGUI_THUMBNAIL_LEFT_RIGHT_GAP;
		}
		gui_pop_clip();
	}

    /* draw status icon */
    if (area->status_icon)
    {
		GDI_RESULT ret;
		ret = gdi_image_get_dimension_file((CHAR*)area->status_icon, &icon_w, &icon_h);
		if (ret == GDI_SUCCEED)
		{
			if (mmi_fe_get_r2l_state())
			{
			    clip_x1 = x;
			}
			else
			{
			    clip_x1 = width - 1 - icon_w;
			}
			clip_y1 = y;
			gui_push_clip();
			gui_set_clip(clip_x1, clip_y1, width - 1, clip_y1 + icon_h);
			gdi_image_draw_file(clip_x1, clip_y1, area->status_icon);
			gui_pop_clip();
		}
    }
    
    width = width - 1 - icon_w;
    
    /* draw type icon */
    if (area->type_icon)
    {
		GDI_RESULT ret;
		ret = gdi_image_get_dimension_file((CHAR*)area->type_icon, &icon_w, &icon_h);
		if (ret == GDI_SUCCEED)
		{
			if (mmi_fe_get_r2l_state())
			{
			    clip_x1 = x;
			}
			else
			{
			    clip_x1 = width - 1 - icon_w;
			}
			clip_y1 = y;
			gui_push_clip();
			gui_set_clip(clip_x1, clip_y1, width - 1, clip_y1 + icon_h);
			gdi_image_draw_file(clip_x1, clip_y1, area->type_icon);
			gui_pop_clip();
		}
    }
    
	if (mmi_fe_get_r2l_state())
	{
	    width = xx - icon_w - 1;
	}
	else
	{
	    width = width - 1 - icon_w - xx;
	}
    
    /* draw user name */
    if (area->user_name)
    {
        gui_set_font(&MMI_medium_font);
        gui_set_text_color(MMI_fixed_icontext_menuitem.normal_text_color);
		if (mmi_fe_get_r2l_state())
		{
		    clip_x1 = xx - width;
		}
		else
		{
		    clip_x1 = xx + 1;
		}
        clip_y1 = y;
        text_w = width - 2;
        text_h = Get_CharHeightOfAllLang(MEDIUM_FONT);
        gui_push_text_clip();
        gui_set_text_clip(clip_x1, clip_y1, clip_x1 + text_w, clip_y1 + text_h);
		if (mmi_fe_get_r2l_state())
		{
			gui_print_truncated_text(clip_x1 + text_w - 1, clip_y1, text_w, (UI_string_type)area->user_name);
		}
		else
		{
			gui_print_truncated_text(clip_x1, clip_y1, text_w, (UI_string_type)area->user_name);
		}
        gui_pop_text_clip();
    }
    
    y = y + 1 + text_h;
    
    /* draw user status */
    if (area->user_status)
    {
        gui_set_font(&MMI_small_font);
        gui_set_text_color(MMI_fixed_icontext_menuitem.normal_text_color);
		if (mmi_fe_get_r2l_state())
		{
		    clip_x1 = xx - width;
		}
		else
		{
		    clip_x1 = xx + 1;
		}
        clip_y1 = y + 1;
        text_w = width - 2;
        text_h = Get_CharHeightOfAllLang(SMALL_FONT);
        gui_push_text_clip();
        gui_set_text_clip(clip_x1, clip_y1, clip_x1 + text_w, clip_y1 + text_h);
		if (mmi_fe_get_r2l_state())
		{
			gui_print_truncated_text(clip_x1 + text_w - 1, clip_y1, text_w, (UI_string_type)area->user_status);
		}
		else
		{
			gui_print_truncated_text(clip_x1, clip_y1, text_w, (UI_string_type)area->user_status);
		}
        gui_pop_text_clip();
    }

    /* restore layer */
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat74_draw_sns_title
 * DESCRIPTION
 *  draw sns title
 * PARAMETERS
 *  coordinate   [IN]  Unused.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat74_draw_sns_title(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    wgui_cat_text_viewer_sns_show_title(MMI_title_x, MMI_title_y, MMI_title_width, WGUI_CAT_SNS_TITLE_HEIGHT, g_cat74_sns_title);

    wgui_inputs_ml_move(WGUI_INPUTS_STYLE_DEFAULT, MMI_title_y + WGUI_CAT_SNS_TITLE_HEIGHT);
    wgui_inputs_ml_resize(WGUI_INPUTS_STYLE_DEFAULT, MMI_content_height + MMI_title_height - WGUI_CAT_SNS_TITLE_HEIGHT);
    wgui_inputs_ml_redraw();
}
#endif /* __SOCIAL_NETWORK_SUPPORT__ */
