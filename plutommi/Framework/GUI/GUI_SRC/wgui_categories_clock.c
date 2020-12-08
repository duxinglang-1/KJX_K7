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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
//#include "mmi_frm_gprot.h"
//#include "WguiCategoryGprot.h"
//#include "CommonScreens.h"
#include "WorldclockResDef.h"
#include "wgui_softkeys.h"

//RHR
#include "MMIDataType.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "gui_typedef.h"
#include "gdi_include.h"
#include "wgui_include.h"
#include "wgui_draw_manager.h"
#include "gui_title.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_uiframework_def.h"
#include "wgui_categories_clock.h"
#include "GlobalConstants.h"
#include "wgui_categories_enum.h"
#include "mmi_frm_events_gprot.h"
#include "wgui.h"
#include "IdleAppDef.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_list.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_touch_screen.h"
#include "gui_switch.h"
#include "gui_themes.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "wgui_title.h"
#include "mmi_frm_mem_gprot.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/


#if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)||defined(__MMI_SCREEN_SAVER__)

#ifdef WGUI_STATUS_ICON_SHOW_V_BAR 
extern S16 status_icon;
#endif


#ifdef __MMI_ANALOG_CLOCK__
extern void analog_clock_initialize(void);
#endif
extern void cat129_clear_icon_bg(void *button);
extern void dummy_dt_hide_function(S32 x1, S32 y1, S32 x2, S32 y2);

#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
#ifndef __GDI_MEMORY_PROFILE_2__
/* Image id and the top-left corner position for category86/128 */
/* ONLY used for the platform of NOT support multi-layer */
PU8 clock_category_image; 
S32 clock_category_image_x, clock_category_image_y;
#endif /* __GDI_MEMORY_PROFILE_2__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_category_hide_clock_display
 * DESCRIPTION
 *  hide function of  clock of categor 86 and 128
 * PARAMETERS
 *  x1      [IN]        Start x position
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category_hide_clock(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    x1 = 0;
    x2 = UI_device_width - 1;
    y1 = MMI_title_y + MMI_title_height;
    y2 = UI_device_height - MMI_button_bar_height - 1;
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(clock_category_image_x, clock_category_image_y, clock_category_image);
#endif 

#ifdef WGUI_STATUS_ICON_SHOW_V_BAR 
    if (status_icon)
    {
        wgui_status_icon_bar_redraw(WGUI_STATUS_ICON_BAR_V_BAR);
    }
#endif /*WGUI_STATUS_ICON_SHOW_V_BAR*/
}


/*****************************************************************************
 * FUNCTION
 *  wgui_category_draw_clock_category_control_area
 * DESCRIPTION
 *  Draw the control area of category86 and 128
 * PARAMETERS
 *  coordinate      [IN]     area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category_draw_clock_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_main_LCD_dt_display();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_category_exit_clock_category
 * DESCRIPTION
 *  Exit the clock category (category86 and 128)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category_exit_clock_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();

    /* cancel the background of title-text */
    title_bg_id = 0;
    close_main_LCD_dt_display();
#ifdef __MMI_ANALOG_CLOCK__
    wgui_datetime_show_date_set_enable(MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_category_show_clock_category
 * DESCRIPTION
 *  Displays the setting screen wallpaper or screen-saver
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Reserved
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  screen_img              [IN]        Background image ID
 *  history_buffer          [IN]        History buffer
 *  clock_types             [IN]        Analog clock or digital clock 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category_show_clock_category(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 screen_img,
        U8 *history_buffer,
        U8  clock_types)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
#if defined(__MMI_TOUCH_SCREEN__)
    U16 btn_prev_item_id = 0, btn_next_item_id = 0; 
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);
    UI_UNUSED_PARAMETER(title_icon);

    gui_lock_double_buffer();
    /* disable shortcut */
    wgui_title_set_menu_shortcut_number(-1);
    dm_add_softkey_id(left_softkey, right_softkey);
    wgui_softkey_set_filler_disabled(MMI_TRUE);

    dm_add_title_id(title, 0);

    dm_add_image(get_image(screen_img), NULL, NULL);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#ifndef __GDI_MEMORY_PROFILE_2__
    clock_category_image_x = clock_category_image_y = 0;
    clock_category_image = get_image(screen_img);
#endif /* __GDI_MEMORY_PROFILE_2__ */

    /* check if the title bar buttons are enabled for the particular screen. */
    if (wgui_is_touch_title_bar_buttons())
    {
#if defined(__MMI_TOUCH_SCREEN__)
        btn_prev_item_id = 
#endif /* defined(__MMI_TOUCH_SCREEN__) */
            dm_add_button(
                            NULL,
                            get_image(LEFT_RED_ARROW),
                            get_image(LEFT_RED_ARROW),
                            cat129_clear_icon_bg);

#if defined(__MMI_TOUCH_SCREEN__)
        btn_next_item_id = 
#endif /* defined(__MMI_TOUCH_SCREEN__) */
            dm_add_button(
                            NULL,
                            get_image(RIGHT_RED_ARROW),
                            get_image(RIGHT_RED_ARROW),
                            cat129_clear_icon_bg);
        title_bg_id = IMAGE_VIEW_TITLEBAR_BG;
    }

    set_main_LCD_dt_date_hide_function(dummy_dt_hide_function);
    set_main_LCD_dt_time_hide_function(wgui_category_hide_clock);

    if (clock_types == ANALOG_CLOCK_CATEGORY_FLAG)
    {
        analog_clock_initialize();
        wgui_datetime_show_date_set_enable(MMI_TRUE);
        set_dt_display(DT_ANALOG_CLOCK_SC);
    }
    else if (clock_types == DIGITAL_CLOCK_CATEGORY_FLAG)
    {
        set_dt_display(DT_DIGITAL_CLOCK_SC1);
    }

    gui_unlock_double_buffer();

#if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        /* register the handler for pen event down istead of pen event up. */
        dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_down_handler);
        dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_down_handler);
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    ExitCategoryFunction = wgui_category_exit_clock_category;
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_register_category_controlled_callback(wgui_category_draw_clock_control_area);

    /* //// */
    if (clock_types == ANALOG_CLOCK_CATEGORY_FLAG)
    {
    dm_data.s32CatId = MMI_CATEGORY86_ID;
    }
    else if (clock_types == DIGITAL_CLOCK_CATEGORY_FLAG)
    {
        dm_data.s32CatId = MMI_CATEGORY128_ID;
    }
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32flags |= DM_SET_AS_ABM_LAYER;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}

#endif /* (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__)) */


#ifdef __MMI_ANALOG_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  ShowCategory86Screen
 * DESCRIPTION
 *  Displays the setting screen wallpaper or screen-saver(analog clock)
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Reserved
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  screen_img              [IN]        Background image ID
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory86Screen(
        U16 title, 
        U16 title_icon, 
        U16 left_softkey, 
        U16 left_softkey_icon, 
        U16 right_softkey, 
        U16 right_softkey_icon, 
        U16 screen_img, 
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_category_show_clock_category(
            title,
            title_icon,
            left_softkey,
            left_softkey_icon,
            right_softkey,
            right_softkey_icon,
            screen_img,
            history_buffer,
            ANALOG_CLOCK_CATEGORY_FLAG);
}
#endif /* __MMI_ANALOG_CLOCK__ */ 


#ifdef __MMI_DIGITAL_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  ShowCategory128Screen
 * DESCRIPTION
 *  Displays the setting screen wallpaper or screen-saver(digital clock)
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Reserved
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  screen_img              [IN]        Background image ID
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory128Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 screen_img,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_category_show_clock_category(
            title,
            title_icon,
            left_softkey,
            left_softkey_icon,
            right_softkey,
            right_softkey_icon,
            screen_img,
            history_buffer,
            DIGITAL_CLOCK_CATEGORY_FLAG);
}
#endif /* __MMI_DIGITAL_CLOCK__ */ 
#endif /*!defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)||defined(__MMI_SCREEN_SAVER__)*/

#ifdef __MMI_SCREEN_SAVER__
/*****************************************************************************
 * FUNCTION
 *  ExitCategory131Screen
 * DESCRIPTION
 *  Exits the category131 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory131Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();
    close_main_LCD_dt_display();
}

#ifdef __MMI_ANALOG_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  cat131_hide_analog_clock_display
 * DESCRIPTION
 *  hide function of category131 for analog clock
 * PARAMETERS
 *  x1      [IN]        Start x position
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void cat131_hide_analog_clock_display(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(GDI_USING_LAYER)       
    PU8 image;
    gdi_handle image_handle;
#endif /* defined(GDI_USING_LAYER) */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_USING_LAYER)
    x1 = 16;
    y1 = (MMI_title_y + MMI_title_height);
    x2 = UI_device_width - 16;
    y2 = UI_device_height - MMI_button_bar_height;
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* defined(GDI_USING_LAYER) */
    image = get_image(IMG_ID_DISPCHAR_ANALOG_CLK);
    gdi_image_draw_animation(
        0,
        0,
        image,
        &image_handle);    
#endif /* defined(GDI_USING_LAYER) */
}
#endif /* __MMI_ANALOG_CLOCK__ */


#ifdef __MMI_DIGITAL_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  cat131_hide_digital_clock_display
 * DESCRIPTION
 *  hide function of category131 for digital  clock
 * PARAMETERS
 *  x1      [IN]        Start x position
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void cat131_hide_digital_clock_display(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(GDI_USING_LAYER)       
    PU8 image;
    gdi_handle image_handle;
#endif /* defined(GDI_USING_LAYER) */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_USING_LAYER)    
    x1 = 0;
    y1 = 0;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* defined(GDI_USING_LAYER) */
    image = get_image(IMG_ID_DISPCHAR_DIGITAL_CLK);
    gdi_image_draw_animation(
        0,
        0,
        image,
        &image_handle);
#endif /* defined(GDI_USING_LAYER) */    
}
#endif /* __MMI_DIGITAL_CLOCK__ */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory131Screen
 * DESCRIPTION
 *  show analog or digital clock screen saver depends icon_screensaver value
 * PARAMETERS
 *  icon_screensaver        [IN]        Id of the image
 *  screen_saver_type       [IN]        type of screen saver (normal, analog, digital)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory131Screen(U16 icon_screensaver, U8 screen_saver_type, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

    entry_full_screen();
    gui_lock_double_buffer();
    clear_category_screen_key_handlers();
    if (screen_saver_type == ANALOG_SCREEN_SAVER)
    {
    #ifdef __MMI_ANALOG_CLOCK__
        analog_clock_initialize();
        set_main_LCD_dt_time_hide_function(cat131_hide_analog_clock_display);
        set_dt_display(DT_ANALOG_CLOCK_SC);
    #endif /* __MMI_ANALOG_CLOCK__ */ 
    }
    else if (screen_saver_type == DIGITAL_SCREEN_SAVER)
    {
    #ifdef __MMI_DIGITAL_CLOCK__
        set_main_LCD_dt_time_hide_function(cat131_hide_digital_clock_display);
        set_dt_display(DT_DIGITAL_CLOCK_SC1);
    #endif /* __MMI_DIGITAL_CLOCK__ */ 
    }
    set_main_LCD_dt_date_hide_function(dummy_dt_hide_function);

#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__  
    dm_add_image(get_image(icon_screensaver), NULL, NULL);
#endif    
    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory131Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY131_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SET_AS_ABM_LAYER;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /*__MMI_SCREEN_SAVER__*/

#ifdef __MMI_WORLD_CLOCK__
#if defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)

#include "worldclock.h"

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    CAT230_TOUCH_NONE,
    CAT230_TOUCH_ON_LEFT_ARROW_UP,
    CAT230_TOUCH_ON_LEFT_ARROW_DOWN,
    CAT230_TOUCH_ON_RIGHT_ARROW_UP,
    CAT230_TOUCH_ON_RIGHT_ARROW_DOWN,
    CAT230_TOUCH_ON_INDEX_UP,
    CAT230_TOUCH_ON_INDEX_DOWN,
    CAT230_TOUCH_ON_PAINT_UP,
    CAT230_TOUCH_ON_PAINT_DOWN,
    CAT230_TOUCH_ON_PAINT_REPEAT,
    CAT230_TOUCH_ON_PAINT_MOVE,
    CAT230_TOUCH_ON_RSK
} CAT230_PEN_EVENTS;

S32 Cat230PenEvent = CAT230_TOUCH_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */

MMI_BOOL Cat230LeftArrowPressed = MMI_FALSE;
MMI_BOOL Cat230RightArrowPressed = MMI_FALSE;
U8 *Cat230TitleString = NULL;
U8 *Cat230IndexInfoString[MAX_CAT230_INDEX];
U8 Cat230NumberofIndex = 0;
U8 Cat230HighlightedIndex = 0;
S32 Cat230Paint_y = 0;
S32 Cat230Paint_height = 0;
GDI_HANDLE Cat230PaintLayer = GDI_NULL_HANDLE;
MMI_BOOL Cat230FirstEnter = MMI_TRUE;

#ifdef __MMI_FTE_SUPPORT__
color Cat230Index_bg = {55, 55, 55, 255};
color Cat230Index_bg_highlight = {100, 100, 100, 255};
color Cat230Index_fg = {255, 255, 255, 255};
color Cat230Index_fg_highlight = {255, 255, 255, 255};
#else
color Cat230Index_bg = {254, 164, 42, 255};
color Cat230Index_bg_highlight = {254, 210, 41, 255};
color Cat230Index_fg = {0, 0, 0, 255};
color Cat230Index_fg_highlight = {255, 255, 255, 255};
#endif

void (*Cat230AppLeftKeyHandler) (U8 index_num) = UI_dummy_function_byte;
void (*Cat230AppRightKeyHandler) (U8 index_num) = UI_dummy_function_byte;
void (*Cat230RedrawPaint) (void) = UI_dummy_function;
void (*Cat230GetPaintInfo) (void *paint_info) = NULL;

static void RedrawCategory230Screen(void);

static void Cat230RedrawPaint_WC(void);
FuncPtr Cat230RedrawPaintArray[CAT230_SCREEN_TYPE_MAX] = {    Cat230RedrawPaint_WC    };

#ifdef __MMI_TOUCH_SCREEN__
typedef void (*Cat230PaintPenEventFuncPtr) (S32 x, S32 y, S32 event_type);

void (*Cat230PaintPenEventHandler) (S32 x, S32 y, S32 event_type) = NULL;
void (*Cat230AppPaintPenEventHandler) (S32 x, S32 y, S32 event_type) = NULL;
static void Cat230PaintPenEventHandler_WC(S32 x, S32 y, S32 event_type);
Cat230PaintPenEventFuncPtr Cat230PaintPenEventHandlerArray[CAT230_SCREEN_TYPE_MAX] = {  Cat230PaintPenEventHandler_WC   };
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetCat230IndexInfo
 * DESCRIPTION
 *  set category index info
 * PARAMETERS
 *  index_num       [IN]        Index to set info
 *  info_string     [IN]        Info string to set
 * RETURNS
 *  void
 *****************************************************************************/
void SetCat230IndexInfo(U8 index_num, U8* info_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index_num < MAX_CAT230_INDEX);
    Cat230IndexInfoString[index_num] = info_string;
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  RegisterCat230PaintPenEventHandler
 * DESCRIPTION
 *  register 230 category pen event handler
 * PARAMETERS
 *  AppPaintPenEventHandler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterCat230PaintPenEventHandler(void (*AppPaintPenEventHandler) (S32 x, S32 y, S32 event_type))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat230AppPaintPenEventHandler = AppPaintPenEventHandler;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyRight
 * DESCRIPTION
 *  Right arrow key handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyRight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(Cat230AppRightKeyHandler!=NULL);
    Cat230AppRightKeyHandler(Cat230HighlightedIndex);
    RedrawCategory230Screen();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyLeft
 * DESCRIPTION
 *  Left arrow key handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyLeft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(Cat230AppLeftKeyHandler!=NULL);
    Cat230AppLeftKeyHandler(Cat230HighlightedIndex);
    RedrawCategory230Screen();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyUp
 * DESCRIPTION
 *  Up arrow key handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat230HighlightedIndex == 0)
    {
        Cat230HighlightedIndex = Cat230NumberofIndex - 1;
    }
    else
    {
        Cat230HighlightedIndex--;
    }
    RedrawCategory230Screen();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyDown
 * DESCRIPTION
 *  Down arrow key handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat230HighlightedIndex == Cat230NumberofIndex-1)
    {
        Cat230HighlightedIndex = 0;
    }
    else
    {
        Cat230HighlightedIndex++;
    }
    RedrawCategory230Screen();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyRightDown
 * DESCRIPTION
 *  Right navigation key down handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyRightDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat230RightArrowPressed = MMI_TRUE;
    Cat230HandleKeyRight();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyRightUp
 * DESCRIPTION
 *  Right navigation key up handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyRightUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat230RightArrowPressed = MMI_FALSE;
    RedrawCategory230Screen();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyLeftDown
 * DESCRIPTION
 *  Left navigation key down handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyLeftDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat230LeftArrowPressed = MMI_TRUE;
    Cat230HandleKeyLeft();
}


/*****************************************************************************
 * FUNCTION
 *  Cat230HandleKeyLeftUp
 * DESCRIPTION
 *  Left navigation key up handler of Cat230.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230HandleKeyLeftUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat230LeftArrowPressed = MMI_FALSE;
    RedrawCategory230Screen();
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  Cat230PenDownHandler
 * DESCRIPTION
 *  category 230 pen down handler
 * PARAMETERS
 *  point       [IN]        Pen down position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL Cat230PenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct pos;
    U8 j;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_320X240__)
    /* on index */
    pos.pos_x = 0;
    pos.pos_y = 0;
    pos.width = UI_device_width;
    pos.height = CAT230_INDEX_HEIGHT*Cat230NumberofIndex;
#elif defined (__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X320__)
    pos.pos_x = 0;
    pos.pos_y = MMI_status_bar_height;
    pos.width = UI_device_width;
    pos.height = CAT230_INDEX_HEIGHT*Cat230NumberofIndex;
#else
    /* on index */
    pos.pos_x = 0;
    pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT;
    pos.width = UI_device_width;
    pos.height = CAT230_INDEX_HEIGHT*Cat230NumberofIndex;
#endif
    
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* INDEX */
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
#ifdef __MMI_SLIM_IMG_RES__
	    gui_measure_image(get_image(LEFT_RED_ARROW), &iwidth, &iheight);
#else
        gui_measure_image(get_image(LEFT_ARROW_UP), &iwidth, &iheight);
#endif
        pos.width = iwidth;
        pos.height = iheight;
        
        /* on left arrow */
        for (j=0; j<Cat230NumberofIndex; j++)
        {
        #if defined (__MMI_MAINLCD_320X240__)
            pos.pos_x = CAT230_ARROW_OFFSET;
            pos.pos_y = CAT230_INDEX_HEIGHT*j + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
            pos.pos_x = CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height + CAT230_INDEX_HEIGHT*j + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #else
            pos.pos_x = CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT+CAT230_INDEX_HEIGHT*j + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #endif
			pos.pos_x = 0;
			pos.width = iwidth + CAT230_ARROW_OFFSET + CAT230_ARROW_SHIFT;
            if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* LEFT ARROW */
            {
                Cat230PenEvent = CAT230_TOUCH_ON_LEFT_ARROW_DOWN;
                Cat230HighlightedIndex = j;
				Cat230LeftArrowPressed = MMI_TRUE;
                Cat230HandleKeyLeft();
                return MMI_TRUE;
            }
        }

        /* on right arrow */
        for (j=0; j<Cat230NumberofIndex; j++)
        {
        
        #if defined (__MMI_MAINLCD_320X240__)
            pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
            pos.pos_y = CAT230_INDEX_HEIGHT*j + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #elif defined (__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X320__)
            pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height + CAT230_INDEX_HEIGHT*j + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #else
            pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT+CAT230_INDEX_HEIGHT*j + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #endif
            pos.pos_x -= CAT230_ARROW_SHIFT;
			pos.width = iwidth + CAT230_ARROW_OFFSET + CAT230_ARROW_SHIFT;
            if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* RIGHT ARROW */
            {
                Cat230PenEvent = CAT230_TOUCH_ON_RIGHT_ARROW_DOWN;
                Cat230HighlightedIndex = j;
				Cat230RightArrowPressed = MMI_TRUE;
                Cat230HandleKeyRight();
                return MMI_TRUE;
            }
        }
#if defined (__MMI_MAINLCD_320X240__)
        Cat230HighlightedIndex = point.y / CAT230_INDEX_HEIGHT;
#elif defined (__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X320__)
        Cat230HighlightedIndex = ((point.y - MMI_status_bar_height) / CAT230_INDEX_HEIGHT);
#else
        Cat230HighlightedIndex = ((point.y-(MMI_status_bar_height+CAT230_TITLE_HEIGHT)) / CAT230_INDEX_HEIGHT);
#endif
        Cat230PenEvent = CAT230_TOUCH_ON_INDEX_DOWN;
        RedrawCategory230Screen();
        return MMI_TRUE;
    }

    /* on paint */
    pos.pos_x = 0;
    pos.pos_y = Cat230Paint_y;
    pos.width = UI_device_width;
    pos.height = Cat230Paint_height;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* Paint */
    {
        Cat230PenEvent = CAT230_TOUCH_ON_PAINT_DOWN;
        Cat230PaintPenEventHandler(point.x, point.y, Cat230PenEvent);
        return MMI_TRUE;
    }
    
    Cat230PenEvent = CAT230_TOUCH_NONE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat230PenUpHandler
 * DESCRIPTION
 *  pen up handler of category 230
 * PARAMETERS
 *  point       [IN]        Pen up position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL Cat230PenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct pos;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SLIM_IMG_RES__
	    gui_measure_image(get_image(LEFT_RED_ARROW), &iwidth, &iheight);
#else
    gui_measure_image(get_image(LEFT_ARROW_UP), &iwidth, &iheight);
#endif
    pos.width = iwidth;
    pos.height = iheight;
    /* left arrow */
    if (Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_DOWN)
    {
    
    #if defined (__MMI_MAINLCD_320X240__)
        pos.pos_x = CAT230_ARROW_OFFSET;
        pos.pos_y = CAT230_INDEX_HEIGHT*Cat230HighlightedIndex+ ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
    #elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
        pos.pos_x = CAT230_ARROW_OFFSET;
        pos.pos_y = MMI_status_bar_height + CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
    #else
        pos.pos_x = CAT230_ARROW_OFFSET;
        pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT+CAT230_INDEX_HEIGHT*Cat230HighlightedIndex+ ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
    #endif
		pos.pos_x = 0;
		pos.width = iwidth + CAT230_ARROW_OFFSET + CAT230_ARROW_SHIFT;

        if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* LEFT ARROW */
        {
            Cat230PenEvent = CAT230_TOUCH_NONE;
			Cat230LeftArrowPressed = MMI_FALSE;
            RedrawCategory230Screen();
            return MMI_TRUE;
        }
    }

    /* right arrow */
    if (Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_DOWN)
    {
    #if defined (__MMI_MAINLCD_320X240__)
        pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
        pos.pos_y = CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
    #elif defined (__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X320__)
        pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
        pos.pos_y = MMI_status_bar_height + CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;    
    #else
        pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
        pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT+CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
    #endif
        pos.pos_x -= CAT230_ARROW_SHIFT;
		pos.width = iwidth + CAT230_ARROW_OFFSET + CAT230_ARROW_SHIFT;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* RIGHT ARROW */
        {
            Cat230PenEvent = CAT230_TOUCH_NONE;
			Cat230RightArrowPressed = MMI_FALSE;
            RedrawCategory230Screen();
            return MMI_TRUE;
        }
    }
    
    Cat230PenEvent = CAT230_TOUCH_NONE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat230PenRepeatHandler
 * DESCRIPTION
 *  pen repeat handler of category 230
 * PARAMETERS
 *  point       [IN]        Pen repeat position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL Cat230PenRepeatHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* left arrow */
    if (Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_DOWN)
    {
        Cat230HandleKeyLeft();
        return MMI_TRUE;
    }

    /* right arrow */
    if (Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_DOWN)
    {
        Cat230HandleKeyRight();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat230PenMoveHandler
 * DESCRIPTION
 *  pen move handler of category 230
 * PARAMETERS
 *  point       [IN]        Pen move position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL Cat230PenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct pos;
    U8 highlighted_index;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if defined (__MMI_MAINLCD_320X240__)
    /* on index */
    pos.pos_x = 0;
    pos.pos_y = 0;
    pos.width = UI_device_width;
    pos.height = CAT230_INDEX_HEIGHT*Cat230NumberofIndex;
#elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
    /* on index */
    pos.pos_x = 0;
    pos.pos_y = MMI_status_bar_height;
    pos.width = UI_device_width;
    pos.height = CAT230_INDEX_HEIGHT*Cat230NumberofIndex;

#else
    /* on index */
    pos.pos_x = 0;
    pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT;
    pos.width = UI_device_width;
    pos.height = CAT230_INDEX_HEIGHT*Cat230NumberofIndex;
#endif
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* INDEX */
    {
#ifdef __MMI_SLIM_IMG_RES__
	    gui_measure_image(get_image(LEFT_RED_ARROW), &iwidth, &iheight);
#else
        gui_measure_image(get_image(LEFT_ARROW_UP), &iwidth, &iheight);
#endif
        pos.width = iwidth;
        pos.height = iheight;
        /* left arrow */
        if (Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_DOWN ||
            Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_UP)
        {
        
        #if defined (__MMI_MAINLCD_320X240__)
            pos.pos_x = CAT230_ARROW_OFFSET;
            pos.pos_y = CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
            pos.pos_x = CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height+CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #else
            pos.pos_x = CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT+CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #endif
        	pos.pos_x = 0;
		    pos.width = iwidth + CAT230_ARROW_OFFSET + CAT230_ARROW_SHIFT;
            if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* LEFT ARROW */
            {
                Cat230PenEvent = CAT230_TOUCH_ON_LEFT_ARROW_DOWN;
                return MMI_TRUE;
            }
            else
            {
                if (Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_DOWN)
                {
                    Cat230PenEvent = CAT230_TOUCH_ON_LEFT_ARROW_UP;
                    Cat230LeftArrowPressed = MMI_FALSE;
                    RedrawCategory230Screen();
                }
                return MMI_TRUE;
            }
        }
        /* right arrow */
        if (Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_DOWN ||
            Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_UP)
        {
        
        #if defined (__MMI_MAINLCD_320X240__)
            pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
            pos.pos_y = CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
            pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height+CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;  
        #else
            pos.pos_x = UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET;
            pos.pos_y = MMI_status_bar_height+CAT230_TITLE_HEIGHT+CAT230_INDEX_HEIGHT*Cat230HighlightedIndex + ((CAT230_INDEX_HEIGHT-iheight) >> 1) - 1;
        #endif
            pos.pos_x -= CAT230_ARROW_SHIFT;
		    pos.width = iwidth + 2*CAT230_ARROW_OFFSET + CAT230_ARROW_SHIFT;
            if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* RIGHT ARROW */
            {
                Cat230PenEvent = CAT230_TOUCH_ON_RIGHT_ARROW_DOWN;
                return MMI_TRUE;
            }
            else
            {
                if (Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_DOWN)
                {
                    Cat230PenEvent = CAT230_TOUCH_ON_RIGHT_ARROW_UP;
                    Cat230RightArrowPressed = MMI_FALSE;
                    RedrawCategory230Screen();
                }
                return MMI_TRUE;
            }
        }

        if (Cat230PenEvent == CAT230_TOUCH_ON_INDEX_DOWN ||
            Cat230PenEvent == CAT230_TOUCH_ON_INDEX_UP)
        {
        
        #if defined (__MMI_MAINLCD_320X240__)
            highlighted_index = point.y / CAT230_INDEX_HEIGHT;
        #elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
            highlighted_index = ((point.y-MMI_status_bar_height) / CAT230_INDEX_HEIGHT);
        #else
            highlighted_index = ((point.y-(MMI_status_bar_height+CAT230_TITLE_HEIGHT)) / CAT230_INDEX_HEIGHT);
        #endif
        
        #if defined (__MMI_MAINLCD_320X240__)
            if (highlighted_index != Cat230HighlightedIndex &&
                point.y >= 0 &&
                highlighted_index <= Cat230NumberofIndex)
        #elif defined(__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
            if (highlighted_index != Cat230HighlightedIndex &&
                point.y >= MMI_status_bar_height &&
                highlighted_index <= Cat230NumberofIndex)
        #else
            if (highlighted_index != Cat230HighlightedIndex &&
                point.y >= (MMI_status_bar_height+CAT230_TITLE_HEIGHT) &&
                highlighted_index <= Cat230NumberofIndex)
        #endif
            {
                Cat230HighlightedIndex = highlighted_index;
                Cat230PenEvent = CAT230_TOUCH_ON_INDEX_DOWN;
                RedrawCategory230Screen();
            }
            return MMI_TRUE;
        }
    }
    else
    {
        if (Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_DOWN)
        {
            Cat230PenEvent = CAT230_TOUCH_ON_LEFT_ARROW_UP;
            Cat230LeftArrowPressed = MMI_FALSE;
            RedrawCategory230Screen();
        }
        else if (Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_DOWN)
        {
            Cat230PenEvent = CAT230_TOUCH_ON_RIGHT_ARROW_UP;
            Cat230RightArrowPressed = MMI_FALSE;
            RedrawCategory230Screen();
        }
    }

    /* on paint */
    pos.pos_x = 0;
    pos.pos_y = Cat230Paint_y;
    pos.width = UI_device_width;
    pos.height = Cat230Paint_height;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* Paint */
    {
        if (Cat230PenEvent == CAT230_TOUCH_ON_PAINT_DOWN ||
            Cat230PenEvent == CAT230_TOUCH_ON_PAINT_UP)
        {
            Cat230PenEvent = CAT230_TOUCH_ON_PAINT_DOWN;
            Cat230PaintPenEventHandler(point.x, point.y, Cat230PenEvent);
            return MMI_TRUE;
        }
    }

    if (Cat230PenEvent == CAT230_TOUCH_ON_INDEX_DOWN ||
        Cat230PenEvent == CAT230_TOUCH_ON_INDEX_UP)
    {
        Cat230PenEvent = CAT230_TOUCH_ON_INDEX_UP;
    }
    else if (Cat230PenEvent == CAT230_TOUCH_ON_PAINT_DOWN ||
        Cat230PenEvent == CAT230_TOUCH_ON_PAINT_UP)
    {
        Cat230PenEvent = CAT230_TOUCH_ON_PAINT_DOWN;
    }
    else
    {
        Cat230PenEvent = CAT230_TOUCH_NONE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat230PaintPenEventHandler_WC
 * DESCRIPTION
 *  pen event hanlder of category 230
 * PARAMETERS
 *  x               [IN]        X
 *  y               [IN]        Y
 *  event_type      [IN]        Event type
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230PaintPenEventHandler_WC(S32 x, S32 y, S32 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 relative_x, relative_y;
    wgui_component_info_struct pos;
    mmi_pen_point_struct point;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point.x = x;
    point.y = y;

    
#if defined (__MMI_MAINLCD_320X240__)
    pos.pos_x = 0;
    pos.pos_y = Cat230Paint_y + CAT230_TIME_HEIGHT;
    pos.width = UI_device_width;
    pos.height = Cat230Paint_height-CAT230_TIME_HEIGHT;
#else
    pos.pos_x = 0;
    pos.pos_y = Cat230Paint_y + CAT230_TIME_HEIGHT;
    pos.width = UI_device_width;
    pos.height = Cat230Paint_height-CAT230_TIME_HEIGHT*2-CAT230_CITY_HEIGHT;
#endif

    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* Map */
    {
        relative_x = x;
        relative_y = y - Cat230Paint_y - CAT230_TIME_HEIGHT;
        Cat230AppPaintPenEventHandler(relative_x, relative_y, event_type);
        RedrawCategory230Screen();
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitCategory230Screen
 * DESCRIPTION
 *  exit function of category230
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory230Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();
    Cat230TitleString = NULL;
    for (i=0; i<MAX_CAT230_INDEX; i++)
    {
        Cat230IndexInfoString[i] = NULL;
    }
    Cat230NumberofIndex = 0;
    Cat230HighlightedIndex = 0;
    Cat230FirstEnter = MMI_TRUE;

    Cat230AppLeftKeyHandler = UI_dummy_function_byte;
    Cat230AppRightKeyHandler = UI_dummy_function_byte;
    Cat230RedrawPaint = UI_dummy_function;
    Cat230GetPaintInfo = NULL;
#ifdef __MMI_TOUCH_SCREEN__
    Cat230PaintPenEventHandler = NULL;
    Cat230AppPaintPenEventHandler = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory230HistorySize
 * DESCRIPTION
 *  Gets the history buffer size of category 230
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory230HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory230History
 * DESCRIPTION
 *  Gets the history buffer of category230
 * PARAMETERS
 *  history_buffer      [OUT]        Is the buffer into which the history data is stored
 * RETURNS
 *  return history buffer
 *****************************************************************************/
U8 *GetCategory230History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  Cat230DrawTitle
 * DESCRIPTION
 *  Category 230 redraw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Cat230DrawTitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color cblack = {0, 0, 0, 255};
    color cwhite = {255, 255, 255, 255};
    S32 width = 0;
    S32 height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gui_reset_text_clip();
    gui_lock_double_buffer();

#ifdef __MMI_MAINLCD_320X480__
    gui_set_font(&MMI_large_font);
#else
    gui_set_font(&MMI_default_font);
#endif
    gui_measure_string((UI_string_type)Cat230TitleString, &width, &height);
    gdi_draw_solid_rect(0, MMI_status_bar_height, UI_device_width-1, MMI_status_bar_height+CAT230_TITLE_HEIGHT-1, gdi_act_color_from_rgb(cblack.alpha, cblack.r, cblack.g, cblack.b));
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(((UI_device_width - width) >> 1) + width, MMI_status_bar_height + ((CAT230_TITLE_HEIGHT-height)>>1));
    }
    else
    {
        gui_move_text_cursor((UI_device_width - width) >> 1, MMI_status_bar_height + ((CAT230_TITLE_HEIGHT-height)>>1));
    }
    gui_set_text_color(cwhite);
    gui_print_text((UI_string_type)Cat230TitleString);

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, MMI_status_bar_height, UI_device_width-1, MMI_status_bar_height+CAT230_TITLE_HEIGHT-1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat230DrawIndex
 * DESCRIPTION
 *  category 230 redraw index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Cat230DrawIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height, iwidth, iheight;
    color bg_color, text_color;
    U8 i;
    S32 vertical_gap;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gui_reset_text_clip();
    gui_lock_double_buffer();
#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
    vertical_gap = MMI_status_bar_height;
#elif defined (__MMI_MAINLCD_320X240__)
    vertical_gap = 0;
#else
    vertical_gap = MMI_status_bar_height+CAT230_TITLE_HEIGHT;
#endif
    
    gui_set_font(&MMI_small_font);
#ifdef __MMI_SLIM_IMG_RES__
	    gui_measure_image(get_image(LEFT_RED_ARROW), &iwidth, &iheight);
#else
    gui_measure_image(get_image(LEFT_ARROW_UP), &iwidth, &iheight);
#endif

    for (i=0; i<Cat230NumberofIndex; i++)
    {
        width = height = 0;
        if (i == Cat230HighlightedIndex)
        {
            bg_color = Cat230Index_bg_highlight;
            text_color = Cat230Index_fg_highlight;
        }
        else
        {
            bg_color = Cat230Index_bg;
            text_color = Cat230Index_fg;
        }
        
        /* draw background */
        gdi_draw_solid_rect(0, vertical_gap + CAT230_INDEX_HEIGHT * i, UI_device_width - 1, 
            vertical_gap + CAT230_INDEX_HEIGHT * (i + 1) - 1, 
            gdi_act_color_from_rgb(bg_color.alpha, bg_color.r, bg_color.g, bg_color.b));
        
        /* draw fg text */
        gui_measure_string((UI_string_type)Cat230IndexInfoString[i], &width, &height);
        
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(((UI_device_width - width) >> 1) + width, 
                vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - height) >> 1));
        }
        else
        {
            gui_move_text_cursor((UI_device_width - width) >> 1, 
                vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - height) >> 1));
        }
        gui_set_text_color(text_color);
        gui_print_text((UI_string_type)Cat230IndexInfoString[i]);

        /* draw left arrow */
    #ifdef __MMI_TOUCH_SCREEN__
        if (Cat230PenEvent == CAT230_TOUCH_ON_LEFT_ARROW_DOWN && i == Cat230HighlightedIndex)
        {
            gui_show_transparent_image(
                CAT230_ARROW_OFFSET,
                vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - iheight) >> 1),
#ifdef __MMI_SLIM_IMG_RES__
                get_image(LEFT_RED_ARROW), 
#else
				 get_image(LEFT_ARROW_DOWN),
#endif
                0);
        }
        else
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        {
            if (Cat230LeftArrowPressed && i == Cat230HighlightedIndex)
            {
                gui_show_transparent_image(
                    CAT230_ARROW_OFFSET,
                    vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - iheight) >> 1),
#ifdef __MMI_SLIM_IMG_RES__
                    get_image(LEFT_RED_ARROW),
#else
					get_image(LEFT_ARROW_DOWN),
#endif
                    0);
            }
            else
            {
                gui_show_transparent_image(
                    CAT230_ARROW_OFFSET,
                    vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - iheight) >> 1),
#ifdef __MMI_SLIM_IMG_RES__
                    get_image(LEFT_RED_ARROW),
#else
					get_image(LEFT_ARROW_UP),
#endif
                    0);
            }
        }            
    
        /* draw right arrow */
    #ifdef __MMI_TOUCH_SCREEN__
        if (Cat230PenEvent == CAT230_TOUCH_ON_RIGHT_ARROW_DOWN && i == Cat230HighlightedIndex)
        {
            gui_show_transparent_image(
                UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET,
                vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - iheight) >> 1),
#ifdef __MMI_SLIM_IMG_RES__
                get_image(RIGHT_RED_ARROW),
#else
				get_image(RIGHT_ARROW_DOWN),
#endif
                0);
        }
        else
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        {
            if (Cat230RightArrowPressed && i == Cat230HighlightedIndex)
            {
                gui_show_transparent_image(
                    UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET,
                    vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - iheight) >> 1),
#ifdef __MMI_SLIM_IMG_RES__
					get_image(RIGHT_RED_ARROW),
#else
					get_image(RIGHT_ARROW_DOWN),
#endif
                    0);
            }
            else
            {
                gui_show_transparent_image(
                    UI_device_width - iwidth - 1 - CAT230_ARROW_OFFSET,
                    vertical_gap + CAT230_INDEX_HEIGHT * i + ((CAT230_INDEX_HEIGHT - iheight) >> 1),
#ifdef __MMI_SLIM_IMG_RES__
                    get_image(RIGHT_RED_ARROW),
#else
				get_image(RIGHT_ARROW_UP),
#endif
                    0);
            }                
        }
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, vertical_gap, UI_device_width-1, Cat230Paint_y-1);
}

static void Cat230RedrawDynaTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;
    S32 height = 0;
    S32 start_y = 0;
    cat230_paint_wc_info_struct wc_info;
#ifdef __MMI_FTE_SUPPORT__
    color dynamic_time_bg = {217, 217, 217, 255};
    color dynamic_time_fg = {0, 0, 0, 255};
#else
    color dynamic_time_bg = {255, 113, 21, 255};
    color dynamic_time_fg = {0, 0, 0, 255};
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(Cat230GetPaintInfo!=NULL);
    Cat230GetPaintInfo((void *)(&wc_info));

    
    gui_set_font(&MMI_small_font);
 
    /* draw dynamic time */
    start_y = Cat230Paint_y;
    gui_measure_string((UI_string_type)wc_info.dynamic_string, &width, &height);
    gdi_draw_solid_rect(0, start_y, UI_device_width-1, start_y+CAT230_TIME_HEIGHT-1, gdi_act_color_from_rgb(dynamic_time_bg.alpha, dynamic_time_bg.r, dynamic_time_bg.g, dynamic_time_bg.b));
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(((UI_device_width - width) >> 1) + width, start_y + ((CAT230_TIME_HEIGHT-height)>>1));
    }
    else
    {
        gui_move_text_cursor((UI_device_width - width) >> 1, start_y + ((CAT230_TIME_HEIGHT-height)>>1));
    }
    gui_set_text_color(dynamic_time_fg);
    gui_print_text((UI_string_type)wc_info.dynamic_string);

}

static void Cat230RedrawStaticTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;
    S32 height = 0;
    S32 start_y = 0;
    cat230_paint_wc_info_struct wc_info;
#ifdef __MMI_FTE_SUPPORT__
    color static_time_bg = {217, 217, 217, 255};
    color static_time_fg = {0, 0, 0, 255};
#else
    color static_time_bg = {82, 22, 48, 255};
    color static_time_fg = {255, 255, 255, 255};
#endif  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(Cat230GetPaintInfo!=NULL);
    Cat230GetPaintInfo((void *)(&wc_info));

    
    gui_set_font(&MMI_small_font);
 
     /* draw static time */
    start_y = UI_device_height-MMI_button_bar_height-CAT230_TIME_HEIGHT;
    gui_measure_string((UI_string_type)wc_info.static_string, &width, &height);
    gdi_draw_solid_rect(0, start_y, UI_device_width-1, start_y+CAT230_TIME_HEIGHT-1, gdi_act_color_from_rgb(static_time_bg.alpha, static_time_bg.r, static_time_bg.g, static_time_bg.b));
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(((UI_device_width - width) >> 1) + width, start_y + ((CAT230_TIME_HEIGHT-height)>>1));
    }
    else
    {
        gui_move_text_cursor((UI_device_width - width) >> 1, start_y + ((CAT230_TIME_HEIGHT-height)>>1));
    }
    gui_set_text_color(static_time_fg);
    gui_print_text((UI_string_type)wc_info.static_string);

}

void Cat230UpdateTime(void)
{
    gui_lock_double_buffer();
    
    Cat230RedrawDynaTime();
    
#ifndef  __MMI_MAINLCD_320X240__
    Cat230RedrawStaticTime();
#endif
    
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, Cat230Paint_y, UI_device_width-1, Cat230Paint_y+Cat230Paint_height-1);
}

#define WGUI_CAT230_HINT_CITY_BUF_LEN 25
/*****************************************************************************
 * FUNCTION
 *  Cat230RedrawPaint_WC
 * DESCRIPTION
 *  redraw paint_wc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat230RedrawPaint_WC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
#ifdef __MMI_FTE_SUPPORT__
    color city_bg = {55, 55, 55, 255};
    color hint_fg = {255, 255, 255, 255};
#else
    color city_bg = {0, 0, 0, 255};
    color hint_fg = {255, 255, 255, 255};
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* defined(__MMI_MAINLCD_240X320__) */
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_SLIM_IMG_RES__)
    color dynamic_line = {255, 0, 0, 255};
    color static_line = {255, 255, 255, 255};
#else
    color dynamic_line = {255, 0, 0, 255};
    color static_line = {0, 0, 0, 255};
#endif
    S32 width = 0;
    S32 height = 0;
    
#if defined(__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
    S32 width1 = 0;
    S32 height1 = 0;
	WCHAR hint[WGUI_CAT230_HINT_CITY_BUF_LEN+1];
#endif /* defined(__MMI_MAINLCD_240X320__) */
    S32 start_y = 0;
    cat230_paint_wc_info_struct wc_info;
    
    MMI_ASSERT(Cat230GetPaintInfo!=NULL);
    Cat230GetPaintInfo((void *)(&wc_info));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 060706 NITZ category Calvin Start */
    if (!wc_info.need_redraw)
    {
        return;
    }
    /* 060706 NITZ category Calvin End */
     
    gui_reset_clip();
    gui_reset_text_clip();
    gui_lock_double_buffer();
    
    gui_set_font(&MMI_small_font);

    /* draw dynamic time */
    Cat230RedrawDynaTime();
    
#if defined(__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
    /* draw city */
    start_y = UI_device_height-MMI_button_bar_height-CAT230_TIME_HEIGHT-CAT230_CITY_HEIGHT;
    gui_measure_string((UI_string_type)wc_info.hint_string, &width, &height);
    gui_measure_string((UI_string_type)wc_info.city_string, &width1, &height1);
    gdi_draw_solid_rect(0, start_y, UI_device_width-1, start_y+CAT230_CITY_HEIGHT-1, gdi_act_color_from_rgb(city_bg.alpha, city_bg.r, city_bg.g, city_bg.b));
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(((UI_device_width - (width+5+width1)) >> 1) + width+5+width1, start_y + ((CAT230_CITY_HEIGHT-height)>>1));
    }
    else
    {
        gui_move_text_cursor((UI_device_width - (width+5+width1)) >> 1, start_y + ((CAT230_CITY_HEIGHT-height)>>1));
    }
    gui_set_text_color(hint_fg);
	memset(hint, 0, sizeof(hint));
	mmi_wcscpy(hint, (WCHAR*)wc_info.hint_string);
	mmi_wcscat(hint, (WCHAR*)L"  ");
	mmi_wcscat(hint, (WCHAR*)wc_info.city_string);
    gui_print_text((UI_string_type)hint);

     Cat230RedrawStaticTime();

#endif /* defined(__MMI_MAINLCD_240X320__) */

    /* draw map */
    start_y = Cat230Paint_y + CAT230_TIME_HEIGHT;
    if (Cat230FirstEnter == MMI_TRUE)
    {
#if defined(__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
        dm_create_layer(0, start_y, UI_device_width, Cat230Paint_height-CAT230_TIME_HEIGHT*2-CAT230_CITY_HEIGHT, &Cat230PaintLayer, DM_LAYER_BOTTOM);
#elif defined(__MMI_MAINLCD_320X240__)
        dm_create_layer(0, start_y, UI_device_width, Cat230Paint_height-CAT230_TIME_HEIGHT, &Cat230PaintLayer, DM_LAYER_BOTTOM);
#endif
        gdi_layer_push_and_set_active(Cat230PaintLayer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_reset_clip();
        /* draw fix list backgroud */
        #if defined(__MMI_WORLD_CLOCK__)
        gdi_image_draw_id(0, 0, WORLD_CLOCK_IMAGE1);
        #endif
        gdi_layer_pop_and_restore_active();
        Cat230FirstEnter = MMI_FALSE;
    }

    /* draw line indication */
    gdi_layer_push_clip();
#if defined(__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
    gdi_layer_set_clip(0, start_y, UI_device_width-1, UI_device_height-MMI_button_bar_height-CAT230_TIME_HEIGHT-CAT230_CITY_HEIGHT-1);
    gdi_draw_solid_rect(0, start_y, UI_device_width-1, UI_device_height-MMI_button_bar_height-CAT230_TIME_HEIGHT-CAT230_CITY_HEIGHT-1, GDI_COLOR_TRANSPARENT);
    gui_draw_vertical_line(start_y, UI_device_height-MMI_button_bar_height-CAT230_TIME_HEIGHT-CAT230_CITY_HEIGHT-1, wc_info.static_x, static_line);
    gui_draw_horizontal_line(0, UI_device_width-1, start_y+wc_info.static_y, static_line);
    gui_draw_vertical_line(start_y, UI_device_height-MMI_button_bar_height-CAT230_TIME_HEIGHT-CAT230_CITY_HEIGHT-1, wc_info.dynamic_x, dynamic_line);
    gui_draw_horizontal_line(0, UI_device_width-1, start_y+wc_info.dynamic_y, dynamic_line);
#elif defined(__MMI_MAINLCD_320X240__)
    gdi_layer_set_clip(0, start_y, UI_device_width-1, UI_device_height-MMI_button_bar_height-1);
    gdi_draw_solid_rect(0, start_y, UI_device_width-1, UI_device_height-MMI_button_bar_height-1, GDI_COLOR_TRANSPARENT);
    gui_draw_vertical_line(start_y, UI_device_height-MMI_button_bar_height - 1, wc_info.static_x, static_line);
    gui_draw_horizontal_line(0, UI_device_width-1, start_y+wc_info.static_y, static_line);
    gui_draw_vertical_line(start_y, UI_device_height-MMI_button_bar_height - 1, wc_info.dynamic_x, dynamic_line);
    gui_draw_horizontal_line(0, UI_device_width-1, start_y+wc_info.dynamic_y, dynamic_line);
#endif
    gdi_layer_pop_clip();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, Cat230Paint_y, UI_device_width-1, Cat230Paint_y+Cat230Paint_height-1);
    
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory230Screen
 * DESCRIPTION
 *  redraw category 230
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void RedrawCategory230Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) 
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_320X240__)
    MMI_title_string = (UI_string_type)Cat230TitleString;
    MMI_title_icon = 0;
    draw_title();
#endif
#elif defined(__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
    Cat230DrawTitle();
#endif
    Cat230DrawIndex();
    MMI_ASSERT(Cat230RedrawPaint!=NULL);
    Cat230RedrawPaint();
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategoryControlledArea230Screen
 * DESCRIPTION
 *  redraw category230 control area
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw     
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategoryControlledArea230Screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RedrawCategory230Screen();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory230Screen
 * DESCRIPTION
 *  category screen of phone search
 * PARAMETERS
 *  title                   [IN]        Title string
 *  number_of_index         [IN]        Number of index
 *  index_info              [IN]        
 *  highlighted_index       [IN]        Highlighted index
 *  screen_type             [IN]        Screen type
 *  left_key_handler        [IN]        Function pointer to app right key handler
 *  right_key_handler       [IN]        
 *  get_paint_info          [IN]        Function pointer to get info of non-index area
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory230Screen(
        U8 *title,
        U8 number_of_index,
        U8 **index_info,
        U8 highlighted_index,
        U8 screen_type,
        void (*left_key_handler) (U8 index_num),
        void (*right_key_handler) (U8 index_num),
        void (*get_paint_info) (void *paint_info))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 i;
    S32 vertical_gap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_MAINLCD_240X320__)
    vertical_gap = MMI_status_bar_height;
#elif defined (__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)||  defined (__MMI_MAINLCD_480X800__)
    vertical_gap = MMI_status_bar_height+CAT230_TITLE_HEIGHT;
#elif defined (__MMI_MAINLCD_320X240__)
    vertical_gap = 0;
#endif

    Cat230LeftArrowPressed = MMI_FALSE;
    Cat230RightArrowPressed = MMI_FALSE;
    Cat230TitleString = title;
    Cat230NumberofIndex = number_of_index;
    for(i=0; i<MAX_CAT230_INDEX; i++)
    {
        Cat230IndexInfoString[i] = index_info[i];
    }
    Cat230HighlightedIndex = highlighted_index;
    Cat230AppLeftKeyHandler = left_key_handler;
    Cat230AppRightKeyHandler = right_key_handler;
    Cat230RedrawPaint = Cat230RedrawPaintArray[screen_type];
#ifdef __MMI_TOUCH_SCREEN__
    Cat230PaintPenEventHandler = Cat230PaintPenEventHandlerArray[screen_type];
    Cat230PenEvent = CAT230_TOUCH_NONE;
#endif
    Cat230GetPaintInfo = get_paint_info;
    Cat230Paint_y = vertical_gap + CAT230_INDEX_HEIGHT*Cat230NumberofIndex;
    Cat230Paint_height = UI_device_height - Cat230Paint_y - MMI_button_bar_height;
   
    SetupCategoryKeyHandlers();
    ClearKeyEvents();    
    dm_register_category_controlled_callback(RedrawCategoryControlledArea230Screen);

    SetKeyHandler(Cat230HandleKeyLeftDown, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat230HandleKeyLeftUp, KEY_LEFT_ARROW, KEY_EVENT_UP);    
    SetKeyHandler(Cat230HandleKeyLeftDown, KEY_LEFT_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(Cat230HandleKeyLeftDown, KEY_LEFT_ARROW, KEY_REPEAT);
    
    SetKeyHandler(Cat230HandleKeyRightDown, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat230HandleKeyRightUp, KEY_RIGHT_ARROW, KEY_EVENT_UP);    
    SetKeyHandler(Cat230HandleKeyRightDown, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(Cat230HandleKeyRightDown, KEY_RIGHT_ARROW, KEY_REPEAT);
    
    SetKeyHandler(Cat230HandleKeyUp, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat230HandleKeyUp, KEY_UP_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(Cat230HandleKeyUp, KEY_UP_ARROW, KEY_REPEAT);

    SetKeyHandler(Cat230HandleKeyDown, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat230HandleKeyDown, KEY_DOWN_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(Cat230HandleKeyDown, KEY_DOWN_ARROW, KEY_REPEAT);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(Cat230PenDownHandler, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cat230PenUpHandler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(Cat230PenRepeatHandler, MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(Cat230PenMoveHandler, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* 060706 NITZ category Calvin Start */
    ExitCategoryFunction = ExitCategory230Screen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = GetCategory230History;
    GetCategoryHistorySize = GetCategory230HistorySize;
    /* 060706 NITZ category Calvin End */
    dm_data.s32CatId = MMI_CATEGORY230_ID;
    dm_data.s32ScrId = GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /* defined ( __MMI_MAINLCD_240X320__) */ 
/* 052206 NITZ category Calvin End */


#if defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__) ||  defined (__MMI_MAINLCD_480X800__)

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    CAT231_TOUCH_NONE,
    CAT231_TOUCH_ON_LEFT_ARROW_UP,
    CAT231_TOUCH_ON_LEFT_ARROW_DOWN,
    CAT231_TOUCH_ON_RIGHT_ARROW_UP,
    CAT231_TOUCH_ON_RIGHT_ARROW_DOWN,
    CAT231_TOUCH_ON_MAP,
    CAT231_TOUCH_ON_MAX
} cat231_pen_event;
#endif /* __MMI_TOUCH_SCREEN__ */ 

void (*Cat231AppLeftKeyHandler) (void) = UI_dummy_function;
void (*Cat231AppRightKeyHandler) (void) = UI_dummy_function;
void (*Cat231GetPaintInfo) (void *paint_info) = NULL;
gdi_image_cache_bmp_struct Cat231VLine_buf;
gdi_image_cache_bmp_struct Cat231HLine_buf;
cat231_paint_wc_info_struct old_wc_info;
S32 Cat231_map_width, Cat231_map_height;
S32 Cat231_dt_y;
MMI_BOOL Cat231_show_status_icon = MMI_FALSE;
#ifdef __MMI_TOUCH_SCREEN__
void (*Cat231AppPaintPenEventHandler) (S32 x, S32 y) = NULL;
MMI_BOOL left_arrow_pressed = MMI_FALSE;
MMI_BOOL right_arrow_pressed = MMI_FALSE;
S32 left_x1, left_y1, left_width, left_height;
S32 right_x1, right_y1, right_width, right_height;
#endif

#define CAT231_V_LINE_CACHE_SIZE    ((UI_device_height * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL) >> 3)
#define CAT231_H_LINE_CACHE_SIZE    ((UI_device_width * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL) >> 3)
#define CAT231_DAY_IMAGE_GAP        10
#define CAT231_ARROW_GAP            5


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  RegisterCat231PaintPenEventHandler
 * DESCRIPTION
 *  register 231 category pen event handler
 * PARAMETERS
 *  AppPaintPenEventHandler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterCat231PaintPenEventHandler(void (*AppPaintPenEventHandler) (S32 x, S32 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat231AppPaintPenEventHandler = AppPaintPenEventHandler;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  Cat231Redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void Cat231Redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cat231_paint_wc_info_struct wc_info;
    S32 x1, y1, x2, y2;
    S32 text_x1, text_y1, width, height, iwidth, iheight, ix1, iy1;
    S32 dt_x1, dt_x2, dt_y1, dt_y2;
    color cwhite = {255, 255, 255, 100};
    color cred = {255, 0, 0, 100};
    color cblack = {0, 0, 0, 100};
    color cblue = {160, 205, 250, 100};
    S32 gap = CAT231_DAY_IMAGE_GAP;
 //   #ifdef __MMI_TOUCH_SCREEN__
    S32 igap = CAT231_ARROW_GAP;
 //   #endif
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(Cat231GetPaintInfo!=NULL);
    Cat231GetPaintInfo((void *)(&wc_info));

    gdi_layer_lock_frame_buffer();

    /* draw title */
    x1 = 0;
    x2 = MMI_title_width - 1;
    if (Cat231_show_status_icon)
    {
        y1 = MMI_status_bar_height;
        y2 = y1 + MMI_title_height - 1;
    }
    else
    {
        y1 = 0;
        y2 = MMI_title_height - 1;
    }
    
    if (wc_info.title_string)
    {
        gui_measure_string((UI_string_type)wc_info.title_string, &width, &height);
        //text_x1 = x1 + ((x2 - x1 + 1 - width) >> 1) + (r2lMMIFlag ? width : 0);
        if(mmi_fe_get_r2l_state())
        {
            text_x1 = x1 + ((x2 - x1 + 1 - width)>>1) + width;
        }
        else
        {
            text_x1 = x1 + ((x2 - x1 + 1 - width)>>1);
        }
        text_y1 = y1 + ((y2 - y1 + 1 - height) >> 1);
        
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_draw_solid_rect(x1, y1, x2, y2,GDI_COLOR_BLACK);
        gdi_layer_pop_clip();
    
        gui_set_text_color(cwhite);
        gui_set_font(&MMI_medium_font);
        gui_move_text_cursor(text_x1, text_y1);
        gui_print_text((UI_string_type)wc_info.title_string);
        old_wc_info.title_string = wc_info.title_string;
    }

#if (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WORLD_CLOCK__))
    if (left_arrow_pressed)
    {
        ix1 = x1 + igap;
        gui_measure_image((PU8)GetImage(WORLD_CLOCK_LEFT_ARROW_DOWN), &iwidth, &iheight);
        iy1 = y1 + ((y2 - y1 + 1 - iheight) >> 1);
        gui_show_image(ix1, iy1, (PU8)GetImage(WORLD_CLOCK_LEFT_ARROW_DOWN));
    }
    else
    {
        ix1 = x1 + igap;
        gui_measure_image((PU8)GetImage(WORLD_CLOCK_LEFT_ARROW_UP), &iwidth, &iheight);
        iy1 = y1 + ((y2 - y1 + 1 - iheight) >> 1);
        gui_show_image(ix1, iy1, (PU8)GetImage(WORLD_CLOCK_LEFT_ARROW_UP));
    }
    left_x1 = ix1;
    left_y1 = iy1;
    left_width = iwidth;
    left_height = iheight;
    
    if (right_arrow_pressed)
    {
        gui_measure_image((PU8)GetImage(WORLD_CLOCK_RIGHT_ARROW_DOWN), &iwidth, &iheight);
        ix1 = x2 - igap - iwidth;
        iy1 = y1 + ((y2 - y1 + 1 - iheight) >> 1);
        gui_show_image(ix1, iy1, (PU8)GetImage(WORLD_CLOCK_RIGHT_ARROW_DOWN));
    }
    else
    {
        gui_measure_image((PU8)GetImage(WORLD_CLOCK_RIGHT_ARROW_UP), &iwidth, &iheight);
        ix1 = x2 - igap - iwidth;
        iy1 = y1 + ((y2 - y1 + 1 - iheight) >> 1);
        gui_show_image(ix1, iy1, (PU8)GetImage(WORLD_CLOCK_RIGHT_ARROW_UP));
    }
    right_x1 = ix1;
    right_y1 = iy1;
    right_width = iwidth;
    right_height = iheight;
#else /* (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WORLD_CLOCK__)) */
    ix1 = x1 + igap;
    gui_measure_image((PU8)GetImage(LEFT_RED_ARROW), &iwidth, &iheight);
    iy1 = y1 + ((y2 - y1 + 1 - iheight) >> 1);
    gui_show_image(ix1, iy1, (PU8)GetImage(LEFT_RED_ARROW));

    gui_measure_image((PU8)GetImage(RIGHT_RED_ARROW), &iwidth, &iheight);
    ix1 = x2 - igap - iwidth;
    iy1 = y1 + ((y2 - y1 + 1 - iheight) >> 1);
    gui_show_image(ix1, iy1, (PU8)GetImage(RIGHT_RED_ARROW));
#endif /* (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WORLD_CLOCK__)) */


    /* draw map */
    y1 = y2 + 1;
    gui_measure_image(get_image(wc_info.curMap), &width, &height);
    y2 = y1 + height - 1;
    Cat231_map_width = x2 - x1 + 1;
    Cat231_map_height = y2 - y1 + 1;

    if (wc_info.curMap != old_wc_info.curMap)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        gui_show_image(x1, y1, get_image(wc_info.curMap));
        gdi_layer_pop_clip();
        old_wc_info.curMap = wc_info.curMap;

        old_wc_info.x = -1;
        old_wc_info.y = -1;
    }


    /* draw 2 lines */
    if (wc_info.x != old_wc_info.x || wc_info.y != old_wc_info.y)
    {
        if (old_wc_info.x != -1 && old_wc_info.y != -1)
        {
            gdi_image_cache_bmp_draw(x1, y1 + old_wc_info.y, &Cat231HLine_buf);
            gdi_image_cache_bmp_draw(x1 + old_wc_info.x, y1, &Cat231VLine_buf);        
        }
    
        gdi_image_cache_bmp_get(x1 + wc_info.x, y1, x1 + wc_info.x, y2, &Cat231VLine_buf);
        gdi_image_cache_bmp_get(x1, y1 + wc_info.y, x2, y1 + wc_info.y, &Cat231HLine_buf);
        
        gui_draw_vertical_line(y1, y2, x1 + wc_info.x, cred);
        gui_draw_horizontal_line(x1, x2, y1 + wc_info.y, cred);

        old_wc_info.x = wc_info.x;
        old_wc_info.y = wc_info.y;
    }

    /* draw date time */
    y1 = y2;
    y2 = UI_device_height - MMI_softkey_height;
    Cat231_dt_y = y1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gui_fill_rectangle(x1, y1, x2, y2 - 1, cblue);
    gdi_layer_pop_clip();
    
    dt_x1 = x1;
    dt_x2 = x2;
    dt_y1 = y1;
    dt_y2 = y1 + ((y2 - y1) >> 1);
    gui_set_text_color(cblack);
    if (wc_info.date_string)
    {
        gui_measure_string((UI_string_type)wc_info.date_string, &width, &height);
        //text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width) >> 1) + (r2lMMIFlag ? width : 0);
        if(mmi_fe_get_r2l_state())
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width)>>1) + width;
        }
        else
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width)>>1);
        }
        text_y1 = dt_y1 + ((dt_y2 - dt_y1 + 1 - height) >> 1);
    
        gui_move_text_cursor(text_x1, text_y1);
        gui_print_text((UI_string_type)wc_info.date_string);
    }
    
    dt_y1 = dt_y2;
    dt_y2 = y2;
    
    if (wc_info.time_string)
    {
        gui_measure_string((UI_string_type)wc_info.time_string, &width, &height);
        gui_measure_image((PU8)GetImage(wc_info.day_image), &iwidth, &iheight);
    
        //text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width - iwidth - gap) >> 1) + (r2lMMIFlag ? width : 0);
        if(mmi_fe_get_r2l_state())
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width - iwidth - gap) >> 1) + width;
        }
        else
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width - iwidth - gap) >> 1);
        }
        text_y1 = dt_y1 + ((dt_y2 - dt_y1 + 1 - height) >> 1);
    
        gui_move_text_cursor(text_x1, text_y1);
        gui_print_text((UI_string_type)wc_info.time_string);
    
        //ix1 = text_x1 + (r2lMMIFlag ? 0 : width) + gap;
        if(mmi_fe_get_r2l_state())
        {
            ix1 = text_x1 + gap;
        }
        else
        {
            ix1 = text_x1 + width + gap;
        }
        iy1 = text_y1;
        if (iy1 + iheight > dt_y2)
        {
            iy1 = dt_y2 - iheight;
        }
        gui_show_image(ix1, iy1, (PU8)GetImage(wc_info.day_image));
    }

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  Cat231UpdateDT
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void Cat231UpdateDT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cat231_paint_wc_info_struct wc_info;
    S32 x1, y1, x2, y2;
    S32 text_x1, text_y1, width, height, iwidth, iheight, ix1, iy1;
    S32 dt_x1, dt_x2, dt_y1, dt_y2;
    color cblack = {0, 0, 0, 100};
    color cblue = {160, 205, 250, 100};
    S32 gap = CAT231_DAY_IMAGE_GAP;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(Cat231GetPaintInfo!=NULL);
    Cat231GetPaintInfo((void *)(&wc_info));

    gdi_layer_lock_frame_buffer();

    x1 = 0;
    x2 = MMI_title_width - 1;

    /* draw date time */
    y1 = Cat231_dt_y;
    y2 = UI_device_height - MMI_softkey_height;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gui_fill_rectangle(x1, y1, x2, y2 - 1, cblue);
    gdi_layer_pop_clip();
    
    dt_x1 = x1;
    dt_x2 = x2;
    dt_y1 = y1;
    dt_y2 = y1 + ((y2 - y1) >> 1);
    gui_set_text_color(cblack);
    if (wc_info.date_string)
    {
        gui_measure_string((UI_string_type)wc_info.date_string, &width, &height);
        //text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width) >> 1) + (r2lMMIFlag ? width : 0);
        if(mmi_fe_get_r2l_state())
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width) >> 1) + width;
        }
        else
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width) >> 1);
        }
        text_y1 = dt_y1 + ((dt_y2 - dt_y1 + 1 - height) >> 1);
    
        gui_move_text_cursor(text_x1, text_y1);
        gui_print_text((UI_string_type)wc_info.date_string);
    }
    
    dt_y1 = dt_y2;
    dt_y2 = y2;
    
    if (wc_info.time_string)
    {
        gui_measure_string((UI_string_type)wc_info.time_string, &width, &height);
        gui_measure_image((PU8)GetImage(wc_info.day_image), &iwidth, &iheight);
    
        //text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width - iwidth - gap) >> 1) + (r2lMMIFlag ? width : 0);
        if(mmi_fe_get_r2l_state())
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width - iwidth - gap) >> 1) + width;
        }
        else
        {
            text_x1 = dt_x1 + ((dt_x2 - dt_x1 + 1 - width - iwidth - gap) >> 1);
        }
        text_y1 = dt_y1 + ((dt_y2 - dt_y1 + 1 - height) >> 1);
    
        gui_move_text_cursor(text_x1, text_y1);
        gui_print_text((UI_string_type)wc_info.time_string);
    
        //ix1 = text_x1 + (r2lMMIFlag ? 0 : width) + gap;
        if(mmi_fe_get_r2l_state())
        {
            ix1 = text_x1 + gap;
        }
        else
        {
            ix1 = text_x1 + width + gap;
        }
        iy1 = text_y1;
        if (iy1 + iheight > dt_y2)
        {
            iy1 = dt_y2 - iheight;
        }
    
        gui_show_image(ix1, iy1, (PU8)GetImage(wc_info.day_image));
    }
    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategoryControlledArea231Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategoryControlledArea231Screen(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Cat231Redraw();

}


/*****************************************************************************
 * FUNCTION
 *  Cat231HandleKeyLeft
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat231HandleKeyLeft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(Cat231AppLeftKeyHandler != NULL);
    Cat231AppLeftKeyHandler();
    Cat231Redraw();
    
    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat231HandleKeyRight
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat231HandleKeyRight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(Cat231AppRightKeyHandler != NULL);
    Cat231AppRightKeyHandler();
    Cat231Redraw();
    
    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  Cat231PenDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL Cat231PenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    wgui_component_info_struct pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* on arrow */
    pos.pos_x = left_x1;
    pos.pos_y = left_y1;
    pos.width = left_width;
    pos.height = left_height;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  
    {
        left_arrow_pressed = MMI_TRUE;
        Cat231HandleKeyLeft();
        return MMI_TRUE;
    }
    
    pos.pos_x = right_x1;
    pos.pos_y = right_y1;
    pos.width = right_width;
    pos.height = right_height;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  
    {
        right_arrow_pressed = MMI_TRUE;
        Cat231HandleKeyRight();
        return MMI_TRUE;
    }
    
    /* on paint */
    pos.pos_x = 0;
    if (Cat231_show_status_icon)
    {
        pos.pos_y = MMI_title_height + MMI_status_bar_height;
    }
    else
    {
        pos.pos_y = MMI_title_height;
    }
    pos.width = Cat231_map_width;
    pos.height = Cat231_map_height;
    
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  
    {
        Cat231AppPaintPenEventHandler(point.x, point.y);
        Cat231Redraw();
        gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
        return MMI_TRUE;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Cat231PenUpHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL Cat231PenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    wgui_component_info_struct pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* on arrow */
    if (left_arrow_pressed)
    {
        pos.pos_x = left_x1;
        pos.pos_y = left_y1;
        pos.width = left_width;
        pos.height = left_height;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  
        {
            left_arrow_pressed = MMI_FALSE;
            Cat231Redraw();
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
            return MMI_TRUE;
        }
    }

    if (right_arrow_pressed)
    {
        pos.pos_x = right_x1;
        pos.pos_y = right_y1;
        pos.width = right_width;
        pos.height = right_height;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  
        {
            right_arrow_pressed = MMI_FALSE;
            Cat231Redraw();
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
            return MMI_TRUE;
        }
    }
    
    if (left_arrow_pressed)
    {
        left_arrow_pressed = MMI_FALSE;
    }
    
    if (right_arrow_pressed)
    {
        right_arrow_pressed = MMI_FALSE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Cat231PenRepeatHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL Cat231PenRepeatHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    wgui_component_info_struct pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* on arrow */
    pos.pos_x = left_x1;
    pos.pos_y = left_y1;
    pos.width = left_width;
    pos.height = left_height;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  
    {
        left_arrow_pressed = MMI_TRUE;
        Cat231HandleKeyLeft();
        return MMI_TRUE;
    }
    
    pos.pos_x = right_x1;
    pos.pos_y = right_y1;
    pos.width = right_width;
    pos.height = right_height;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  
    {
        right_arrow_pressed = MMI_TRUE;
        Cat231HandleKeyRight();
        return MMI_TRUE;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Cat231PenMoveHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL Cat231PenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    wgui_component_info_struct pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* on arrow */
    if (left_arrow_pressed)
    {
        pos.pos_x = left_x1;
        pos.pos_y = left_y1;
        pos.width = left_width;
        pos.height = left_height;
        if (wgui_test_object_position(point, pos) != MMI_TRUE)  
        {
            left_arrow_pressed = MMI_FALSE;
            Cat231Redraw();
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
            return MMI_TRUE;
        }
    }

    if (right_arrow_pressed)
    {
        pos.pos_x = right_x1;
        pos.pos_y = right_y1;
        pos.width = right_width;
        pos.height = right_height;
        if (wgui_test_object_position(point, pos) != MMI_TRUE)  
        {
            right_arrow_pressed = MMI_FALSE;
            Cat231Redraw();
            gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
            return MMI_TRUE;
        }
    }
    
    /* on paint */
    pos.pos_x = 0;
    
    if (Cat231_show_status_icon)
    {
        pos.pos_y = MMI_title_height + MMI_status_bar_height;
    }
    else
    {
        pos.pos_y = MMI_title_height;
    }
    pos.width = Cat231_map_width;
    pos.height = Cat231_map_height;
    
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  
    {
        Cat231AppPaintPenEventHandler(point.x, point.y);
        Cat231Redraw();
        gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
        return MMI_TRUE;
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory231Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory231Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat231VLine_buf.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(Cat231VLine_buf.buf_ptr);
        Cat231VLine_buf.buf_ptr = NULL;
    }

    if (Cat231HLine_buf.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(Cat231HLine_buf.buf_ptr);
        Cat231HLine_buf.buf_ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory231History
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
U8 *GetCategory231History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory231HistorySize
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
S32 GetCategory231HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory231Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
void ShowCategory231Screen(
        void (*left_key_handler) (void),
        void (*right_key_handler) (void),
        void (*get_paint_info) (void *paint_info),
        MMI_BOOL show_status_icons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat231AppLeftKeyHandler = left_key_handler;
    Cat231AppRightKeyHandler = right_key_handler;
    Cat231GetPaintInfo = get_paint_info;

    Cat231VLine_buf.buf_ptr= (U8*)mmi_frm_scrmem_alloc(CAT231_V_LINE_CACHE_SIZE);
    Cat231HLine_buf.buf_ptr = (U8*)mmi_frm_scrmem_alloc(CAT231_H_LINE_CACHE_SIZE);

    MMI_DBG_ASSERT(Cat231VLine_buf.buf_ptr);
    MMI_DBG_ASSERT(Cat231HLine_buf.buf_ptr);

    old_wc_info.curMap = 0;
    old_wc_info.date_string = NULL;
    old_wc_info.day_image = 0;
    old_wc_info.time_string = NULL;
    old_wc_info.title_string = NULL;
    old_wc_info.x = -1;
    old_wc_info.y = -1;

#ifdef __MMI_TOUCH_SCREEN__
    left_arrow_pressed = MMI_FALSE;
    right_arrow_pressed = MMI_FALSE;
#endif

    SetupCategoryKeyHandlers();
    dm_register_category_controlled_callback(RedrawCategoryControlledArea231Screen);

    SetKeyHandler(Cat231HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat231HandleKeyLeft, KEY_LEFT_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(Cat231HandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(Cat231HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat231HandleKeyRight, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
	SetKeyHandler(Cat231HandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(Cat231PenDownHandler, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cat231PenUpHandler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(Cat231PenRepeatHandler, MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(Cat231PenMoveHandler, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    ExitCategoryFunction = ExitCategory231Screen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = GetCategory231History;
    GetCategoryHistorySize = GetCategory231HistorySize;

    Cat231_show_status_icon = show_status_icons;

    if (Cat231_show_status_icon)
    {
        dm_data.s32CatId = MMI_CATEGORY232_ID;
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY231_ID;
    }
    dm_data.s32ScrId = GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#else
void Cat231UpdateDT(void)
{

}
void ExitCategory231Screen(void)
{

}

void ShowCategory231Screen(
        void (*left_key_handler) (void),
        void (*right_key_handler) (void),
        void (*get_paint_info) (void *paint_info),
        MMI_BOOL show_status_icons)
{

}

#endif /* defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__) */
#endif /*__MMI_WORLD_CLOCK__*/

