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
 *  wgui_categories_idlescreen.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Idle Screen related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __WGUI_CATEGORIES_IDLESCREEN_H__
#define __WGUI_CATEGORIES_IDLESCREEN_H__
/* DOM-NOT_FOR_SDK-END */

#include "MMI_features.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_list.h"
#include "gui_data_types.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_config.h"
#include "gui_typedef.h"
#include "wgui_draw_manager.h"
#include "wgui.h"

/* DOM-NOT_FOR_SDK-BEGIN */
/* reminder related */
typedef enum
{
    cat33_reminder_area_state_deinit = 0,  /* deinit */
    cat33_reminder_area_state_init,   /* init */
    cat33_reminder_area_state_show,   /* show */
    cat33_reminder_area_state_end    
} cat33_reminder_area_state_enum;

/* reminder type enum */
typedef enum
{
    wgui_cat033_reminder_calendar, /*calendar */
    wgui_cat033_reminder_dcd,  /* dcd */
    wgui_cat033_reminder_icon_shortcut_bar,  /* icon shorcut */
    wgui_cat033_reminder_total
} cat33_reminder_type_enum;
/* DOM-NOT_FOR_SDK-END */

#if defined(__MMI_TOUCH_SCREEN__)
typedef MMI_BOOL (*cat33_reminder_pen_handler)  (mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
#if defined(__MMI_SEARCH_WEB__)
typedef MMI_BOOL (*cat33_search_pen_handler)  (mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
#endif /*__MMI_SEARCH_WEB__*/
#endif /* defined (__MMI_TOUCH__)*/

typedef void (*cat33_reminder_set_history) (void* history_buffer);
typedef U8* (*cat33_reminder_get_history) (void* history_buffer);
typedef S32 (*cat33_reminder_get_history_size)(void);

/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct _wgui_cat033_reminder_area_info
{
    S32 x, y, w, h;
    FuncPtr init, show, redraw, deinit;
    void* data;
    cat33_reminder_area_state_enum state;    
    cat33_reminder_set_history set_history_function;
    cat33_reminder_get_history get_history_function;
    cat33_reminder_get_history_size get_history_size_function;
#if defined(__MMI_TOUCH_SCREEN__)
    cat33_reminder_pen_handler pen_event_handler;
#endif /* defined (__MMI_TOUCH__)*/
} wgui_cat033_reminder_area_info;
/* DOM-NOT_FOR_SDK-END */
#if defined(__MMI_SEARCH_WEB__)
typedef struct _wgui_cat033_search_area_info
{
	S32 x, y, w, h;
	U8 *image;
	U8 *string;
	FuncPtr handler;
#if defined(__MMI_TOUCH_SCREEN__)
    cat33_search_pen_handler pen_event_handler;
#endif /* defined (__MMI_TOUCH__)*/
}wgui_cat033_search_area_info;
#endif /* __MMI_SEARCH_WEB__*/

/*****************************************************************************
 * FUNCTION
 *  wgui_cat033_reset_reminder_state
 * DESCRIPTION
 *  reset reminder state
 *  THIS FUNCTION IS ONLY FOR IDLE APP, PLEASE DO NOT USE ARBITRARILY
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat033_reset_reminder_state(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat033_get_number_of_informaiont_line
 * DESCRIPTION
 *  Caculate if show network status for phone setup (the second line in idlescreen)
 *  THIS FUNCTION IS ONLY FOR IDLE APP, PLEASE DO NOT USE ARBITRARILY
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 wgui_cat033_get_number_of_informaiont_line(void);

/*****************************************************************************
 * FUNCTION
 *  idle_screen_show_network_details
 * DESCRIPTION
 *  show network name, network status and extra information on idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void idle_screen_show_network_details(void);

/*****************************************************************************
 * FUNCTION
 *  SetIdleScreenNetworkName
 * DESCRIPTION
 *  Sets the network name to be displayed by the idle screen
 * PARAMETERS
 *  s      : [IN] (C033_1)     network name string
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetIdleScreenNetworkName(U8 *s);

/*****************************************************************************
 * FUNCTION
 *  SetIdleScreenNetworkStatus
 * DESCRIPTION
 *  Sets the network status to be displayed by the idle screen
 * PARAMETERS
 *  s      : [IN] (C033_2)     status string
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetIdleScreenNetworkStatus(U8 *s);
extern UI_string_type wgui_cat033_get_extra_text(void);

#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  idle_screen_enable_calendar_display
 * DESCRIPTION
 *  for idle app to display calendar on idle screen category
 *  this function must be called before show category funcion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void idle_screen_enable_calendar_display(void);
#endif /* defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) */

/*****************************************************************************
 * FUNCTION
 *  draw_wallpaper
 * DESCRIPTION
 *  Redraws the Idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void draw_wallpaper(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_cat33_get_cache_wallpaper_info
 * DESCRIPTION
 *  get cat33 cache wallpaper information, used after ShowCategory33Screen and before entering another new screen
 * PARAMETERS
 *  id                 : [IN] (N/A)    Current wallpaper id to determine whether to cache
 *  filename           : [IN] (N/A)    Current wallpaper filename to determine whether to cache
 *  wallpaper_layer    : [OUT] (N/A)   layer handle of wallpaper
 *  output_image_type  : [OUT] (N/A)   output image type (GDI image type)
 * RETURNS
 *  MMI_BOOL            whether to enable cache wallpaper mechanism
 *****************************************************************************/
extern MMI_BOOL mmi_cat33_get_cache_wallpaper_info (MMI_ID_TYPE id, CHAR *filename, GDI_HANDLE *wallpaper_layer, U16 *output_image_type);

/*****************************************************************************
 * FUNCTION
 *  SetIdleScreenWallpaper
 * DESCRIPTION
 *  Sets the Image to be used by the idle screen
 * PARAMETERS
 *  image_ID       : [IN] (N/A)        wallpaper image ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetIdleScreenWallpaper(U16 image_ID);

/*****************************************************************************
 * FUNCTION
 *  SetIdleScreenWallpaperID
 * DESCRIPTION
 *  set Idle screen wall paper ID
 * PARAMETERS
 *  image_ID       : [IN] (N/A)        wallpaper ID
 *  is_default     : [IN] (N/A)        Save the layer of wallpaper as fast format
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetIdleScreenWallpaperID(U16 image_ID, MMI_BOOL is_default);

/*****************************************************************************
 * FUNCTION
 *  SetIdleScreenWallpaperName
 * DESCRIPTION
 *  set idle screen wallpaper name
 * PARAMETERS
 *  name       : [IN] (N/A)        image file name
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetIdleScreenWallpaperName(UI_string_type name);

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
/*****************************************************************************
 * FUNCTION
 *  SetListWallpaperID
 * DESCRIPTION
 *  set list wallpaper ID
 * PARAMETERS
 *  image_ID       : [IN] (N/A)        wallpaper ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetListWallpaperID(U16 image_ID);

/*****************************************************************************
 * FUNCTION
 *  wgui_set_wallpaper_change
 * DESCRIPTION
 *  Sets the Image to be used by the idle screen using ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_set_wallpaper_change(void);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

/* DCD */
/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_OP01_DCD__)
#define SCRMEM_CAT33_POOL_SIZE ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3)
#if defined(__MMI_TOUCH_SCREEN__)

extern void idle_screen_register_dcd_pen_handler(cat33_reminder_pen_handler pen_handler);
#endif /* defined(__MMI_TOUCH_SCREEN__) */
extern void idle_screen_enable_dcd_display(void* agent);
#endif /* defined(__MMI_OP01_DCD__) */

/* touch shortcut */
#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
extern S32 wgui_cat033_get_shortcut_max_height(void);
extern MMI_BOOL wgui_cat033_shortcut_get_mainmenu_area(S32* x, S32* y, S32* w, S32* h);
extern MMI_BOOL wgui_cat033_shortcut_clear_mainmenu_area(void);
#endif 
/* DOM-NOT_FOR_SDK-END */

/* icon shortcut bar */
#ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat033_enable_icon_shortcut_bar_display
 * DESCRIPTION
 *  enalbe icon shortcut bar display in idle screen
 * PARAMETERS
 *  number_of_item       : [IN] (N/A)   number of shortcut item
 *  function_array       : [IN] (N/A)   shortcut item function
 *  hint_array           : [IN] (N/A)   hint of shortcut item
 *  pressed_icon_array   : [IN] (N/A)   pressed shorcut item icon array
 *  unpressed_icon_array : [IN] (N/A)   unpressed shorcut item icon array
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat033_enable_icon_shortcut_bar_display(
              S32 number_of_item, 
              GUIIconbarItemCallback function_array, 
              PU8* hint_array, 
              PU8* pressed_icon_array, 
              PU8* unpressed_icon_array);
#endif /* __MMI_IDLE_SCREEN_ICON_SHORTCUT__ */

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
extern void show_boundries_to_status_bar_at_bottom_idlescreen(void);
#endif

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
extern void wgui_cat033_draw_region_with_technobar(S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat033_show_techo_date_and_static_network_name(void);
#endif

extern void wgui_cat033_set_text_abm_layer(GDI_HANDLE abm_layer);
extern void wgui_cat033_reset_text_abm_layer(void);

extern S32 is_on_idlescreen(void);
extern void set_on_idlescreen(S32);
/* DOM-NOT_FOR_SDK-END */

/**************************************************************
  * FUNCTION
  * ShowCategory33Screen
  * Description
  * Show category 33 screen
  * 
  * <img name="wgui_cat033_img1" />
  * 176x220
  * 
  * <img name="wgui_cat033_img2" />
  * 240x320
  * 
  * <img name="wgui_cat033_img3" />
  * 320x480
  * 
  * Parameters
  * left_softkey :        [IN] (LSK) Left softkey label
  * left_softkey_icon :   [IN] (N/A) Icon for the Left softkey
  * right_softkey :       [IN] (RSK) Right softkey label
  * right_softkey_icon :  [IN] (N/A) Icon for the right softkey
  * history_buffer :      [IN] (N/A) History buffer
  * Returns
  *  void    
  * EXAMPLE
  * <code>
  * void EntryScreen_33(void)
  *  {
  *     U8 *guiBuffer = NULL;
  * 
  *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *  
  * #ifdef __MMI_TOUCH_SCREEN__
  *     mmi_idle_pen_block();
  * #endif 
  * 
  *     ShowCategory33Screen(STR_ID_CSB_LSK_TEXT, 0, STR_ID_CSB_RSK_TEXT, 0, guiBuffer);
  * 
  *     csb_set_key_handlers();
  * }
  * </code>                                                  
  **************************************************************/
extern void ShowCategory33Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */
	/* Just for backward compatible with the existing category. */
extern void ShowCategory33Screen_int(
		  U16 left_softkey,
		  U16 right_softkey,
		  U8 *history_buffer);
#define ShowCategory33Screen(_arg0, _arg1, _arg2, _arg3, _arg4) \
			ShowCategory33Screen_int( _arg0, _arg2, _arg4)
	/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory33Screen(void);
/* DOM-NOT_FOR_SDK-END */


/**************************************************************
  * FUNCTION
  * ShowCategory106Screen
  * Description
  * Show category106 screen (an animated icon)
  * 
  * <img name="wgui_cat106_img1" />
  * 
  * Parameters
  * icon_screensaver :  [IN] (N/A) screen saver image ID
  * filename :          [IN] (N/A) screen saver image file path
  * history_buffer :    [IN] (N/A) History buffer
  * Returns
  *  void  
  * EXAMPLE
  * <code>
  * void EntryScreen_106(void)
  * {
  *     U8 *guiBuffer = NULL;
  * 
  *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *     ShowCategory106Screen(IMG_USB_POWER_ON, NULL, guiBuffer);
  * 
  *     csb_set_key_handlers();
  * }
  * </code>                                                    
  **************************************************************/
extern void ShowCategory106Screen(U16 icon_screensaver, U8 *filename, U8 *history_buffer);


/* DOM-NOT_FOR_SDK-BEGIN */
extern void DrawCate130CategoryControlArea(dm_coordinates *coordinate);
extern void ExitCategory130Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory130Screen
 * DESCRIPTION
 *  Displays the category130 screen,show system theme wallpaper
 * 
 * <img name="wgui_cat130_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon displayed with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_130(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     wgui_set_touch_title_bar_buttons();
 * 
 *     ShowCategory130Screen(
 *         (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         IMG_GLOBAL_YES,
 *         STR_ID_CSB_RSK_TEXT,
 *         IMG_GLOBAL_NO,
 *         guiBuffer);
 *         
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory130Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory33Screen_ext
 * DESCRIPTION
 *  Displays the Category33 screen,show idle screen
 * 
 * <img name="wgui_cat33_img1" />
 * PARAMETERS
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_33(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     wgui_set_touch_title_bar_buttons();
 * 
 *     ShowCategory33Screen(
 *         STR_ID_CSB_LSK_TEXT,
 *         IMG_GLOBAL_YES,
 *         STR_ID_CSB_RSK_TEXT,
 *         IMG_GLOBAL_NO,
 *         guiBuffer);
 *         
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/

extern void ShowCategory33Screen_ext(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);

extern void ShowCategory33Screen_ext_int(
                U16 left_softkey,
                U16 right_softkey,
                U8 *history_buffer);
#define ShowCategory33Screen_ext(_arg0, _arg1, _arg2, _arg3, _arg4)\
       ShowCategory33Screen_ext_int( _arg0, _arg2, _arg4)

#ifdef __MMI_LCD_PARTIAL_ON__
/**********************************************
  * FUNCTION
  * ShowCategory161Screen
  * Description
  * Show category161 screen (time screen saver)
  * 
  * <img name="wgui_cat161_img1" />
  * PARAMETERS
  *  t   : [IN] (N/A) current time
  * Returns
  *  void   
  * EXAMPLE
  * <code>
  * void EntryScreen_161(void)
  * {
  *     MYTIME time;
  * 
  *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *     GetDateTime(&time);
  *     ShowCategory161Screen(&time);
  * 
  *     csb_set_key_handlers();
  * }
  * </code>                                   
  **********************************************/
extern void ShowCategory161Screen(UI_time *t);

/*****************************************************************************
 * FUNCTION
 *  RedrawCategory161Screen
 * DESCRIPTION
 *  Redraw category161 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void RedrawCategory161Screen(void);

/*****************************************************************************
 * FUNCTION
 *  Category161ChangeTime
 * DESCRIPTION
 *  change the time of category161 screen
 * PARAMETERS
 *  t      : [IN] (N/A)        Time
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category161ChangeTime(UI_time *t);
#endif /* __MMI_LCD_PARTIAL_ON__ */ 

#if defined(__MMI_FANCY_SCREEN_LOCK__)

#define WGUI_CAT30_MAX_ICON_TEXT_INFO 3
#define WGUI_CAT30_ICON_TEXT_INFO1    0
#define WGUI_CAT30_ICON_TEXT_INFO2    1
#define WGUI_CAT30_ICON_TEXT_INFO3    2 

#define WGUI_CAT30_OPERATOR_ON_DATE_TIME_BAR      0x01
/*****************************************************************************
 * FUNCTION
 *  wgui_cat30_show
 * DESCRIPTION
 *  Show category 30 screen
 * PARAMETERS
 *  phone_unlock_str            [IN]      phone unlock string
 *  callback_to_app             [IN]        callback to APP on long press
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat30_show(UI_string_type phone_unlock_str,
                     FuncPtr callback_to_app,
                     U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat30_update_details 
 * DESCRIPTION
 *
 *  This API is for application to update the icon, text info etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat30_update_details(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat30_move_and_draw_unlock_bar 
 * DESCRIPTION
 *  It is to used by the SSE to show the expand effect
 * PARAMETERS
 *  x              : [IN] x coordinate for the unlock bar
 *  y              : [IN] y coordinate for the unlock bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat30_move_and_draw_unlock_bar(S32 x, S32 y);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat30_move_and_draw_date_time_bar 
 * DESCRIPTION
 *  It is to used by the SSE to show the expand effect
 * PARAMETERS
 *  x              : [IN] x coordinate for the date time bar
 *  y              : [IN] y coordinate for the date time bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat30_move_and_draw_date_time_bar(S32 x, S32 y);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat30_set_line_info 
 * DESCRIPTION
 *  Its sets the icon and text information for the lines
 * PARAMETERS
 *  index           [IN]    index of the line
 *  info_str        [IN]    information string
 *  info_img        [IN]    information image
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat30_set_line_info(S32 index, U16 * info_str, PU8 info_img);

/* VIJAYAN */
extern void wgui_cat31_show(UI_string_type phone_unlock_str,FuncPtr callback_to_app, U8 flag, U8 *history_buffer);

extern void idle_screen_show_lock_details(void);

extern  void idle_screen_enable_search_bar(const U8 *image, const WCHAR* text, FuncPtr touch_handler);
extern void wgui_cat30_key_down_handler(void);
extern void wgui_cat30_key_up_handler(void);
#endif


extern S32 wgui_get_idle_screen_is_extra_text(void);


#endif /* __WGUI_CATEGORIES_IDLESCREEN_H__ */ 


