/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * MMITask.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for datetime screen control.
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
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

 /*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

/**********************************************************************************
   Filename:      wgui_datetime.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines for Date and Time input / display
**********************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "GlobalConstants.h"
#include "MMI_trc_Int.h"

#include "string.h"
#include "stdio.h"
#include "Unicodexdcl.h"

/* ... Add More MMI header */

#include "CustDataRes.h"
#include "DateTimeType.h"
#include "SettingGprots.h"
#include "CallSetSrvGprot.h"
#include "PixcomFontEngine.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

#include "app_datetime.h"
#include "mmi_rp_app_uiframework_def.h"

#include "gui_config.h"
#include "gui_switch.h"
#include "gui_theme_struct.h"
#include "gui_themes.h"
#include "wgui_datetime.h"
#include "gui_font_size.h"
#include "gui.h"
#include "wgui_fixed_menuitems.h"
#include "MiscFunctions.h"

#include "gui_clock.h"
#include "wgui_clock.h"
#include "wgui_include.h"
#include "wgui_draw_manager.h"
#include "wgui_softkeys.h"
#include "wgui_inputs.h"

#include "wgui_categories_idlescreen.h"
#include "wgui_categories_CM.h"
#include "wgui_inline_edit.h"
#include "gui_fixed_menuitems.h"
#include "gui_fixed_menus.h"
#include "wgui_fixed_menus.h"

#include "wgui_categories_util.h"


#ifdef __MMI_UCM__
#include "UcmSrvGprot.h"
#include "UcmGprot.h"
#endif

#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) || defined(__MMI_UI_STATUS_BAR_AT_BOTTOM__)
#endif 

#if defined(__MMI_OP01_DCD__)
#include "DCDGprot.h"
#endif

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/

#define DT_FLAGS_TYPE   (0x00000fff)

#ifdef __MMI_SUBLCD__
typedef enum
{
    /* Show date before time */
    SUBLCD_DT_DATE_THEN_TIME_TYPE1,
    /* Show time before date */
    SUBLCD_DT_TIME_THEN_DATE_TYPE1,
    SUBLCD_DT_TIME_THEN_DATE_TYPE2
} SUBLCD_DATE_TIME_DISPLAY_TYPE;
#endif /* __MMI_SUBLCD__ */ 
/* MTK Elvis for R2L characters */
#ifdef __MMI_BIDI_ALG__
extern U8 visual_str[];
#endif 

/* MTK end */

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_is_playing(void);
#endif 

/* Date and Time input related objects    */
/* Currently only input boxes are used    */

extern void idle_screen_show_network_details(void);
extern pBOOL IsChineseSet(void);

#ifdef __MMI_SUBLCD__
extern S32 Sub_lcd_title_height;
#endif 
#ifdef __MMI_SUB_WALLPAPER__
extern GDI_HANDLE sublcd_base_layer;
#endif 


U8 show_date = 0;
MMI_BOOL main_lcd_update_date_time = MMI_TRUE;

#ifdef __MMI_SUBLCD__
MMI_BOOL sub_lcd_update_date_time = MMI_TRUE;
#endif 
/* MTK Elvis for date boundary setting */
S32 g_date_year_max = 2030, g_date_year_min = 1970, g_date_month_max = 12, g_date_month_min = 1;

/* MTK end */

/* global variable of main lcd date objet */
UI_date_time_display main_LCD_dt_object;

#ifdef __MMI_SUBLCD__
   /* global variable of sublcd lcd date objet city 1 */
UI_date_time_display sub_LCD_dt_object1;

   /* global variable of sublcd lcd date objet city 2 */
UI_date_time_display sub_LCD_dt_object2;
SUBLCD_DATE_TIME_DISPLAY_TYPE sublcd_date_time_display_type;
#endif /* __MMI_SUBLCD__ */ 

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
extern MMI_ID_TYPE idlescreen_bar_id;//070306 Alpha layer

U8 g_clock_type = ANALOG;   /* default clock for Techno Idlescreen Bar */

U16 *day_string = NULL; /* pointer storing the address of the MMI_ID_TYPE of day string. */
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */

/* global variable of main lcd time objet */
UI_date_time_display main_LCD_time_object;
static void UI_dummy_hide_function(S32 x1, S32 y1, S32 x2, S32 y2);
static void (*MMI_main_LCD_dt_hide_function) (void);
static void (*MMI_main_LCD_dt_update_function) (void);
static void (*MMI_main_LCD_dt_display_function) (void);
static void (*MMI_main_LCD_dt_close_function) (void);
#ifdef __MMI_SUBLCD__
static void (*MMI_sub_LCD_dt_hide_function) (void);
static void (*MMI_sub_LCD_dt_update_function) (void);
static void (*MMI_sub_LCD_dt_display_function) (void);
static void (*MMI_sub_LCD_dt_close_function) (void);
#endif
static void dt_show_duration(void);
extern S32 UI_get_font_height(UI_font_type f);
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetDateSeperatorFormat(void);
extern U8 PhnsetGetTimeFormat(void);
extern UI_string_type UI_strcat(UI_string_type text1, UI_string_type text2);
extern UI_string_type UI_strcpy(UI_string_type text1, UI_string_type text2);
extern void (*gui_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2);

/* Externals for graphics context switching  */
extern bitmap main_LCD_device_bitmap;           /* main lcd graphicd context */
#ifdef __MMI_SUBLCD__
extern bitmap sub_LCD_device_bitmap;            /* sub lcd graphic context */
#endif
void UI_set_main_LCD_graphics_context(void);    /* set main lcd graphic contrext */
void UI_set_sub_LCD_graphics_context(void);     /* set sub lcd graphic cntext */
extern bitmap *current_LCD_device_bitmap;       /* store current graphic context */

#ifdef __MMI_SUBLCD__
extern stFontAttribute MMI_sublcd_font;
extern S32 SUB_LCD_device_width;
extern void RedrawSubLCDAnalogClockScreen(void);
#endif /* __MMI_SUBLCD__ */ 


/* MTK Tim */
extern void kal_get_time(U32 *ticks_ptr);
U32 last_duration_ticks;
U32 last_duration;

UI_time last_duration_time;
#ifdef __MMI_ANALOG_CLOCK__
static MMI_BOOL wgui_datetime_need_show_date = MMI_TRUE;
#endif
static U32 wgui_clock_mainlcd_clock1 = WGUI_CLOCK_INVALID_INDEX;
static U32 wgui_clock_mainlcd_clock2 = WGUI_CLOCK_INVALID_INDEX;
#ifdef __MMI_SUBLCD__
static U32 wgui_clock_sublcd_clock1 = WGUI_CLOCK_INVALID_INDEX;
static U32 wgui_clock_sublcd_clock2 = WGUI_CLOCK_INVALID_INDEX;
#endif

#if defined(__MMI_MAINLCD_128X128__)
S32 ANALOG_CLOCK_DIAL_X = 36;
S32 ANALOG_CLOCK_DIAL_Y = 36;
#elif defined(__MMI_MAINLCD_320X480__)
S32 ANALOG_CLOCK_DIAL_X = 6;
S32 ANALOG_CLOCK_DIAL_Y = 16;
#else
S32 ANALOG_CLOCK_DIAL_X = 26;
S32 ANALOG_CLOCK_DIAL_Y = 26;
#endif

/*****************************************************************************
 * FUNCTION
 *  analog_clock_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void analog_clock_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT HIMANSHU START 20050625 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    #if defined (__MMI_MAINLCD_320X240__)
        ANALOG_CLOCK_DIAL_X = (MMI_SIGNAL_WIDTH);
        ANALOG_CLOCK_DIAL_Y = 26;
    #elif defined (__MMI_MAINLCD_320X480__)
        ANALOG_CLOCK_DIAL_X = 6;
        ANALOG_CLOCK_DIAL_Y = 16;
    #else /* defined (__MMI_MAINLCD_320X240__) */
        ANALOG_CLOCK_DIAL_X = (MMI_SIGNAL_WIDTH + 2);
        ANALOG_CLOCK_DIAL_Y = (MMI_status_bar_height);
    #endif /* defined (__MMI_MAINLCD_320X240__) */
#else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
    ANALOG_CLOCK_DIAL_X = (UI_device_width >> 1) - (ANALOG_CLOCK_DIAL_WIDTH >> 1);
    ANALOG_CLOCK_DIAL_Y = (UI_device_height >> 1) - (ANALOG_CLOCK_DIAL_HEIGHT >> 1) - 1;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  get_year
 * DESCRIPTION
 *  return year of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* Date and time display related code  */
U16 get_year(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nYear);
}


/*****************************************************************************
 * FUNCTION
 *  get_month
 * DESCRIPTION
 *  return month of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_month(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nMonth);
}


/*****************************************************************************
 * FUNCTION
 *  get_day
 * DESCRIPTION
 *  return day of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_day(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nDay);
}


/*****************************************************************************
 * FUNCTION
 *  get_hours
 * DESCRIPTION
 *  return hours of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_hours(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nHour);
}


/*****************************************************************************
 * FUNCTION
 *  get_minutes
 * DESCRIPTION
 *  return minutes of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_minutes(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nMin);
}


/*****************************************************************************
 * FUNCTION
 *  get_seconds
 * DESCRIPTION
 *  return seconds of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_seconds(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->nSec);
}


/*****************************************************************************
 * FUNCTION
 *  get_dayofweek
 * DESCRIPTION
 *  return day of week  of UI_time pass as parameter
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 get_dayofweek(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (t->DayIndex);
}


/*****************************************************************************
 * FUNCTION
 *  date_string
 * DESCRIPTION
 *  get date time string for different requirement
 * PARAMETERS
 *  time        [IN]        Date time to convert
 *  string      [OUT]       Date time string
 *  flags       [IN]        Date time type
 * RETURNS
 *  void
 *****************************************************************************/
void date_string(UI_time *time, UI_string_type string, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 day, month, year;
    S8 ts[32];
    U8 seperator = 0;

#ifdef __MMI_SUBLCD__
    /* MAUI_00169917 START */
    U16 day_index;
    S8 as[64];
    U8 Tempbuffer[64];

    /* MAUI_00169917 END */

    U8 *day_name = NULL;
#endif /* __MMI_SUBLCD__ */ 
#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
    S8 ts2[32];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    day_index = get_dayofweek(time);
#endif
    day = get_day(time);
    month = get_month(time);
    year = get_year(time);

    if (month > 12 || month < 1)
    {
        month = 1;
    }

    switch (PhnsetGetDateSeperatorFormat())
    {
        case 0:
            seperator = '.';
            break;

        case 1:
            seperator = ':';
            break;

        case 2:
            seperator = '/';
            break;

        case 3:
            seperator = '-';
            break;

        default:
            seperator = '.';
            break;
    }

    switch (flags & DT_FLAGS_TYPE)
    {
      /***** MainLCD DataTime *****/
        case DT_IDLE_SCREEN:
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            case DT_IDLE_SCREEN_NO_DAY:
        #endif
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_MO_CALL_SCREEN:        
    #ifndef __MMI_DATETIME_SLIM__    
        case DT_NETWORK_SEARCH:
        case DT_MO_CALLING_SCREEN:
        case DT_DIGITAL_CLOCK_SC2:
        case DT_DIGITAL_CLOCK_SC3:
        case DT_VOIP_CALL_SCREEN:
    #endif
        case DT_TABBED_CALL_SCREEN:
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_DIGITAL_CLOCK_SC1:
    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
    #endif
        {
            switch (PhnsetGetDateFormat())  /* Get the current format of date */
            {
                case 0: /* day, month, year */
                    sprintf((S8*)ts, "%02d%c%02d%c%04d", day, seperator, month, seperator, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 1:
                    sprintf((S8*) ts, "%02d%c%02d%c%04d", month, seperator, day, seperator, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 2:
                    sprintf((S8*) ts, "%04d%c%02d%c%02d", year, seperator, month, seperator, day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
            }
        }
            break;
        case DT_IDLE_SCREEN_2:
        {
            switch (PhnsetGetDateFormat())
            {
                case 0:
                    sprintf((S8*) ts, "%02d%c%02d", day, seperator, month);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
                case 1:
                case 2:
                    sprintf((S8*) ts, "%02d%c%02d", month, seperator, day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
            }
        }
            break;

    #ifdef __MMI_SUBLCD__
      /***** SubLCD DataTime *****/
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
        case DT_SUBLCD_IDLE_SCREEN3:
        case DT_SUBLCD_IDLE_SCREEN4:
        {
            if (IsChineseSet()) /* check if current language is chinese or not */
            {
                switch (day_index)
                {
                    case 0:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_SUNDAY);
                        break;

                    case 1:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_MONDAY);
                        break;

                    case 2:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_TUESDAY);
                        break;

                    case 3:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_WEDNESDAY);
                        break;

                    case 4:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_THURSDAY);
                        break;

                    case 5:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_FRIDAY);
                        break;

                    case 6:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_SATURDAY);
                        break;
                }
            }
            else
            {
                /* not chinese */
                switch (day_index)
                {
                    case 0:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_SUNDAY);
                        break;

                    case 1:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_MONDAY);
                        break;

                    case 2:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_TUESDAY);
                        break;

                    case 3:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_WEDNESDAY);
                        break;

                    case 4:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_THURSDAY);
                        break;

                    case 5:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_FRIDAY);
                        break;

                    case 6:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_SATURDAY);
                        break;
                }
            }   /* end of check chiese */
            /* MAUI_00169917 START */
            mmi_ucs2cpy((S8*) as, (S8*) day_name);
            /* MAUI_00169917 END */

            if ((flags & DT_FLAGS_TYPE) == DT_SUBLCD_IDLE_SCREEN3)
            {
                year %= 100;

                switch (PhnsetGetDateFormat())  /* Get the current format of date */
                {
                    case 0:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d/%02d", day, month, year);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;

                    case 1:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d/%02d", month, day, year);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;

                    case 2:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d/%02d", year, month, day);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;
                }

            }
            /* 101804 MTK Calvin added */
            else if ((flags & DT_FLAGS_TYPE) == DT_SUBLCD_IDLE_SCREEN2)
            {
                year %= 100;

                switch (PhnsetGetDateFormat())  /* Get the current format of date */
                {
                    case 0:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d", day, month);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;

                    case 1:
                    case 2:
                        /* MAUI_00169917 START */
                        sprintf((S8*) ts, "%02d/%02d", month, day);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        /* MAUI_00169917 END */
                        break;
                }

            }
            /* MTK Calvin end */
            else
            {
                /* MAUI_00169917 START */
                sprintf((S8*) ts, "%02d/%02d", day, month);
                mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                /* MAUI_00169917 END */
            }

            /* MAUI_00169917 START */
            mmi_ucs2cpy((S8*) string, (S8*) as);
            /* MAUI_00169917 END */
            break;
        }
            /* break; */
    #endif /* __MMI_SUBLCD__ */ 

    #ifndef __MMI_SLIM_FILE_MANAGER__
      /***** FileManager DataTime *****/
        case DT_FILEMANAGER:
        {
            year %= 100;
            switch (PhnsetGetDateFormat())  /* Get the current format of date */
            {
                case 0: /* day, month, year */
                    sprintf((S8*)ts, "%02d%c%02d%c%02d", day, seperator, month, seperator, year);
                    break;

                case 1:
                    sprintf((S8*) ts, "%02d%c%02d%c%02d", month, seperator, day, seperator, year);
                    break;

                case 2:
                    sprintf((S8*) ts, "%02d%c%02d%c%02d", year, seperator, month, seperator, day);
                    break;
            }
            mmi_asc_to_ucs2((S8*) string, ts);
            break;
        }
    #endif /*__MMI_SLIM_FILE_MANAGER__*/
            /* break; */

    }
}


/*****************************************************************************
 * FUNCTION
 *  time_string
 * DESCRIPTION
 *  convert time to string accoding to current time format
 * PARAMETERS
 *  t           [IN]        Date to convets
 *  s           [OUT]       String format of time
 *  flags       [IN]        Date type
 * RETURNS
 *  void
 *****************************************************************************/
void time_string(UI_time *t, UI_string_type s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes;

#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
    UI_string_type postfix;
#endif 
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = get_hours(t);
    minutes = get_minutes(t);
    switch (flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            case DT_IDLE_SCREEN_NO_DAY:
        #endif
        case DT_IDLE_SCREEN_2:
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_MO_CALL_SCREEN:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_NETWORK_SEARCH:
        case DT_MO_CALLING_SCREEN:
        case DT_DIGITAL_CLOCK_SC2:
        case DT_DIGITAL_CLOCK_SC3:
        case DT_VOIP_CALL_SCREEN:
    #endif
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
        case DT_DIGITAL_CLOCK_SC1:
    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
    #endif
            if (PhnsetGetTimeFormat())  /* get current time format */
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                mmi_asc_to_ucs2((S8*) s, ts);
            }
            else
            {
            #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d AM", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d AM", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);
            #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);

                if (hours >= 12)
                {
                    postfix = ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_ENGLISH_ONLY) ?
                        (UI_string_type) get_string(STR_GUI_TIME_PM_ENG) :
                        (UI_string_type) get_string(STR_GUI_TIME_PM);
                }
                else
                {
                    postfix = ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_ENGLISH_ONLY) ?
                        (UI_string_type) get_string(STR_GUI_TIME_AM_ENG) :
                        (UI_string_type) get_string(STR_GUI_TIME_AM);
                }

                if (postfix)
                {
                    UI_strcat((UI_string_type) s, postfix);
                }
            #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
            }
            break;

        #ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
        case DT_SUBLCD_IDLE_SCREEN3:
            if (PhnsetGetTimeFormat())
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
            }
            else
            {
                S32 width, height;

                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d AM", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d AM", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);
                gui_measure_string((UI_string_type) s, &width, &height);
                if (width > SUB_LCD_device_width)
                {
                    if (hours == 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                    else if (hours == 0)
                    {
                        sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                    }
                    else if (hours > 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                    }
                    else
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                }
            }
            mmi_asc_to_ucs2((S8*) s, ts);
            break;

        case DT_SUBLCD_IDLE_SCREEN4:
            if (PhnsetGetTimeFormat())
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
            }
            else
            {
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
            }
            mmi_asc_to_ucs2((S8*) s, ts);
            break;
        #endif /* __MMI_SUBLCD__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  duration_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t           [?]         
 *  s           [IN]        
 *  flags       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void duration_string(UI_time *t, UI_string_type s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes, seconds;
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = get_hours(t);
    minutes = get_minutes(t);
    seconds = get_seconds(t);
    switch (flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            case DT_IDLE_SCREEN_NO_DAY:
        #endif
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_MO_CALL_SCREEN:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_NETWORK_SEARCH:
        case DT_MO_CALLING_SCREEN:
        case DT_VOIP_CALL_SCREEN:
    #endif
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
    #ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
    #endif /* __MMI_SUBLCD__ */ 
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
    #ifndef __MMI_DATETIME_SLIM__
        case DT_AUDIO_PLAY_DURATION:
            sprintf((S8*) ts, "%02d:%02d", minutes, seconds);
            break;
    #endif
        default:
            hours = 0;
            minutes = 0;
            seconds = 0;
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
                
    }
    mmi_asc_to_ucs2((S8*) s, ts);
}

#ifndef __MMI_DATETIME_SLIM__

/*****************************************************************************
 * FUNCTION
 *  get_time_difference2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_time        [?]     
 *  ref_time        [?]     
 *  diff_time       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void get_time_difference2(UI_time *new_time, UI_time *ref_time, UI_time *diff_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 min_flag = 0, hour_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_time->nSec >= ref_time->nSec)
    {
        diff_time->nSec = new_time->nSec - ref_time->nSec;
    }
    else
    {
        diff_time->nSec = new_time->nSec + 60 - ref_time->nSec;
        min_flag = 1;

    }
    if (new_time->nMin >= ref_time->nMin + min_flag)
    {
        diff_time->nMin = new_time->nMin - ref_time->nMin - min_flag;
    }
    else
    {
        diff_time->nMin = new_time->nMin + 60 - ref_time->nMin - min_flag;
        hour_flag = 1;
    }
    if (new_time->nHour >= ref_time->nHour + hour_flag)
    {
        diff_time->nHour = new_time->nHour - ref_time->nHour - hour_flag;
    }
    else
    {
        diff_time->nHour = new_time->nHour + 24 - ref_time->nHour - hour_flag;
        new_time->nDay -= 1;
    }
    diff_time->nDay = 0;
    diff_time->nMonth = 0;
    diff_time->nYear = 0;
    diff_time->DayIndex = 0;
}


/*****************************************************************************
 * FUNCTION
 *  increment_seconds
 * DESCRIPTION
 *  increment the seconds by 1
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void increment_seconds(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time curr_time, diff_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&curr_time);
    get_time_difference2(&curr_time, &last_duration_time, &diff_time);
    IncrementTime(*t, diff_time, t );
    last_duration_time.nSec = curr_time.nSec;
    last_duration_time.nMin = curr_time.nMin;
    last_duration_time.nHour = curr_time.nHour;
    last_duration_time.nDay = curr_time.nDay;
    last_duration_time.nMonth = curr_time.nMonth;
    last_duration_time.DayIndex = curr_time.DayIndex;
}

#endif /*__MMI_DATETIME_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  increment_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void increment_ticks(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time;
    U32 secs, mins, hrs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    secs = (U32) ((current_time - last_duration_ticks + last_duration) * 0.004615 + 0.5);
    mins = secs / 60;
    hrs = mins / 60;
    t->nSec = (U8) (secs - mins * 60);
    t->nMin = (U8) (mins - hrs * 60);
    t->nHour = (U8) hrs;
    t->nYear = t->nMonth = t->nDay = 0;
}

FLOAT dt_difference1;
FLOAT dt_difference2;

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  get_time_difference
 * DESCRIPTION
 *  calculate time difference between two times pass as parameter
 * PARAMETERS
 *  time_303            [?]         
 *  city_diff_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_time_difference(MYTIME *time_303, FLOAT city_diff_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_time, hour_sublcd1, min_sublcd1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_time = ((time_303->nHour * 60) + time_303->nMin) + ((S32) (city_diff_time * 60));

    if (total_time < 0)
    {
        total_time = 1440 + total_time;
    }
    if (total_time > 1440)
    {
        total_time = total_time - 1440;
    }
    hour_sublcd1 = total_time / 60;
    min_sublcd1 = total_time % 60;
    time_303->nHour = (U8) hour_sublcd1;
    time_303->nMin = (U8) min_sublcd1;
}
#endif /* __MMI_SUBLCD__ */ 

#ifndef __MMI_DATETIME_SLIM__
/*****************************************************************************
 * FUNCTION
 *  set_time_difference
 * DESCRIPTION
 *  set value of output parameter equal to input parameter
 * PARAMETERS
 *  t           [OUT]       
 *  diff        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_time_difference(MYTIME *t, MYTIME *diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *t = *diff;
}
#endif /*__MMI_DATETIME_SLIM__*/


/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_hide_function
Description:      function pointer of main lcd date hide function
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
static void (*MMI_main_LCD_dt_hide_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_update_function
Description:      function pointer of main lcd date update  function
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
static void (*MMI_main_LCD_dt_update_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_display_function
Description:      function pointer of main lcd date display  function
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
static void (*MMI_main_LCD_dt_display_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_close_function
Description:      function pointer of close date display  of main lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
static void (*MMI_main_LCD_dt_close_function) (void) = UI_dummy_function;

#ifdef __MMI_SUBLCD__
/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_hide_function
Description:      function pointer of date hide function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

static void (*MMI_sub_LCD_dt_hide_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_update_function
Description:      function pointer of date update  function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

static void (*MMI_sub_LCD_dt_update_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_display_function
Description:      function pointer of date display  function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
static void (*MMI_sub_LCD_dt_display_function) (void) = UI_dummy_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_close_function
Description:      function pointer of date close display  function of sub lcd
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
static void (*MMI_sub_LCD_dt_close_function) (void) = UI_dummy_function;
#endif /*__MMI_SUBLCD__*/

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_day_hide_function
Description:      day hide funtion pointer of main lcd 
Input Parameters: function pointer
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_day_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */

/* Lisen0522 */

#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
extern void mmi_show_idle_screen(void);
extern MMI_BOOL mmi_idle_is_active(void);
#endif /* __OLED_BW_MMI__ */
#endif

#if defined(__OLDMAN_STYLE__)
extern MMI_BOOL mmi_idle_is_active(void);
extern void mmi_show_old_idle_screen(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  update_mainlcd_dt_display
 * DESCRIPTION
 *  updaet date tiem dispaly on main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_mainlcd_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_96X64__)
        if(wgui_get_idle_screen_is_extra_text())
        {
            return; 
        }
#endif

#if defined(__GGT_TASK__)
// baiwenlin 20130902  更新时间
#if defined(__OLED_BW_MMI__)
	if(mmi_idle_is_active())
	{
		mmi_show_idle_screen();
	}
#endif /* __OLED_BW_MMI__ */
#endif

#if defined(__OLDMAN_STYLE__)
	if(mmi_idle_is_active())
	{
		mmi_show_old_idle_screen();
		return;
	}
#endif

    if (MMI_main_LCD_dt_hide_function != UI_dummy_function)
    {
        /* we need pay attention to gdi_layer_lock_frame_buffer,
         * it may cause some GDI problem in show non blocking image
         */
        gdi_layer_lock_frame_buffer();
        MMI_main_LCD_dt_hide_function();    /* call current hide function of date time of main lcd */
        gdi_layer_unlock_frame_buffer();
    }
    MMI_main_LCD_dt_update_function();  /* call current update function of date time of main lcd */
    if (MMI_main_LCD_dt_update_function == UI_dummy_function)
    {
        wgui_clock_main_lcd_update_func();
    }
    MMI_main_LCD_dt_display_function();
}

/* Lisen0522 */


/*****************************************************************************
 * FUNCTION
 *  update_sublcd_dt_display
 * DESCRIPTION
 *  updaet date tiem dispaly on main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_sublcd_dt_display(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_hide_function();     /* call current hide function of date time of sub lcd */
    MMI_sub_LCD_dt_update_function();   /* call current update function of date time of sub lcd */
    MMI_sub_LCD_dt_display_function();  /* call display function of  date time of sub lcd */
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  show_main_LCD_dt_display
 * DESCRIPTION
 *  get current tiem and update date time of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_main_LCD_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_update_function();  /* call update function of date teime of main lcd */
    MMI_main_LCD_dt_display_function(); /* call display func of date time of main lcd */
}


/*****************************************************************************
 * FUNCTION
 *  show_sub_LCD_dt_display
 * DESCRIPTION
 *  get current tiem and update date time of sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_sub_LCD_dt_display(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_update_function();   /* call update function of date teime of sub lcd */
    MMI_sub_LCD_dt_display_function();  /* call display func of date time of sub lcd */
#endif
}


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_hide_function
 * DESCRIPTION
 *  dummy hide function :- clear the particular area with white color
 * PARAMETERS
 *  x1      [IN]        Start x postion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // PMT DLT_FIXES - TK 200603225 START   /*background color should be taken from the current MMI theme*/
    color c = *current_MMI_theme->datetime_bar_background_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      color c=gui_color(255,255,255);
    //PMT DLT_FIXES - TK 200603225 END
    gdi_layer_reset_clip();
    gui_fill_rectangle(x1, y1, x2, y2, c);
}

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
extern S32 MAIN_LCD_device_width;
#endif 

#define DT_DISPLAY_GAP  1
#define DT_SOFTKEY_GAP  2


U8 enable_main_LCD_date_time_display = 1;
#ifdef __MMI_SUBLCD__
U8 enable_sub_LCD_date_time_display = 1;
#endif

#if defined (__MMI_MAINLCD_128X128__)
#define GUI_CALENDAR_TIME_Y     92
#define GUI_CALENDAR_DATE_Y     75
#elif defined (__MMI_MAINLCD_128X160__)
#define GUI_CALENDAR_TIME_Y     124
#define GUI_CALENDAR_DATE_Y     111
#endif/* defined (__MMI_MAINLCD_128X128__) */
static void pre_setup_previous_control(S16 x, S16 y, S16 width, S16 height)
{
    dm_coordinates coordinates;
    
    coordinates.s16X = x;
    coordinates.s16Y = y;
    coordinates.s16Width = width;
    coordinates.s16Height = height;
    coordinates.Flags = 0;
    setup_previous_control(&coordinates);
}

/*****************************************************************************
 * FUNCTION
 *  show_main_LCD_date_time
 * DESCRIPTION
 *  show upadte date time on main lcd /sub lcd depend on the
 *  current date flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_main_LCD_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 h, w, x, y;
    UI_character_type s[64];
    S32 x1, y1, x2, y2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;
    S32 old_x1, old_y1, old_x2, old_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (main_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    UI_set_main_LCD_graphics_context();

    old_x1 =
        (main_LCD_dt_object.time.x < main_LCD_dt_object.date.x) ? main_LCD_dt_object.time.x : main_LCD_dt_object.date.x;
    old_y1 =
        (main_LCD_dt_object.time.y < main_LCD_dt_object.date.y) ? main_LCD_dt_object.time.y : main_LCD_dt_object.date.y;
    old_x2 =
        (main_LCD_dt_object.time.x + main_LCD_dt_object.time.width >
         main_LCD_dt_object.date.x + main_LCD_dt_object.date.width) ? main_LCD_dt_object.time.x +
        main_LCD_dt_object.time.width : main_LCD_dt_object.date.x + main_LCD_dt_object.date.width;
    old_y2 =
        (main_LCD_dt_object.time.y + main_LCD_dt_object.time.height >
         main_LCD_dt_object.date.y + main_LCD_dt_object.date.height) ? main_LCD_dt_object.time.y +
        main_LCD_dt_object.time.height : main_LCD_dt_object.date.y + main_LCD_dt_object.date.height;

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    switch (main_LCD_dt_object.flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
    #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        case DT_IDLE_SCREEN_NO_DAY:
    #endif
        {
#if defined(__MMI_MAINLCD_96X64__)
                if(wgui_get_idle_screen_is_extra_text())
                {
                    return; 
                }
#endif

			#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__	
                if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) !=
                    DT_IDLE_SCREEN_NO_DAY)
                {
			        gdi_layer_lock_frame_buffer();
				    show_main_LCD_day_display();
				    gdi_layer_unlock_frame_buffer();
                }
			#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

                    if (enable_main_LCD_date_time_display)
                    {
                wgui_clock_show_main_lcd();
                    }

            if (enable_main_LCD_date_time_display)
            {
                pre_setup_previous_control(main_LCD_dt_object.time.x, main_LCD_dt_object.time.y,
                    main_LCD_dt_object.time.width, main_LCD_dt_object.time.height);
            }
        }
            break;

        case DT_IDLE_SCREEN_2:
        {
            if (enable_main_LCD_date_time_display)
            {
                wgui_clock_show_main_lcd();
            }

        }
            break;

    #ifndef __MMI_DATETIME_SLIM__
        case DT_NETWORK_SEARCH:
        {
            gui_set_font(main_LCD_dt_object.time.font);
            /* get current time in string format */
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = (UI_device_width >> 1) - (w >> 1);

        #if defined(__MMI_UI_DALMATIAN_IDLESCREEN__)
            y = UI_device_height - MMI_button_bar_height - (h + (BAR_CONTENT_GAP));
        #else 
            y = UI_device_height - MMI_softkey_height - (h + (DT_DISPLAY_GAP << 1)) - 1;
        #endif 

            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                gui_set_text_border_color(main_LCD_dt_object.time.text_border_color);

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
            #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y + 1);
                }
                else
                {
                    gui_move_text_cursor(x, y + 1);
                }
            #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                gui_set_text_clip(x1 - 1, y1, x2, y2);  /* For proper clipping of the text */
            #else 
                gui_set_text_clip(x1, y1, x2, y2);
            #endif 
                gui_print_bordered_text(s);

                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }
            }
            gui_set_font(main_LCD_dt_object.date.font);
            /* get date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = (UI_device_width >> 1) - (w >> 1);
        #if defined(__MMI_UI_DALMATIAN_IDLESCREEN__) || defined(__MMI_MAINLCD_128X128__)//060606 network search Calvin
            y = y - h - 1;  /* to handle the font height change on dalmatian */
        #else 
            y = y - main_LCD_dt_object.time.height;
        #endif 

            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.date.text_color);
                gui_set_text_border_color(main_LCD_dt_object.date.text_border_color);

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
            #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y + 1);
                }
                else
                {
                    gui_move_text_cursor(x, y + 1);
                }
            #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

                x2 = x1 + main_LCD_dt_object.date.width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;

            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                gui_set_text_clip(x1 - 1, y1, x2, y2);
            #else 
                gui_set_text_clip(x1, y1, x2, y2);
            #endif 
                gui_print_bordered_text(s);
                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (enable_main_LCD_date_time_display)
            {
                pre_setup_previous_control(main_LCD_dt_object.time.x, main_LCD_dt_object.time.y, 
                    main_LCD_dt_object.time.width, main_LCD_dt_object.time.height);
            }
        }
            break;
    #endif /*__MMI_DATETIME_SLIM__*/

        case DT_MO_CALL_SCREEN:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_MO_CALLING_SCREEN:
    #endif        
        case DT_MT_CALL_SCREEN:
        {
            if((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_MT_CALL_SCREEN)
            {                
                y = (MMI_title_y + MMI_title_height);
            }
            else
            {
                y = MMI_status_bar_height;
            }
            gui_set_font(main_LCD_dt_object.date.font);
            /* get current date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w;
            main_LCD_dt_object.date.height = h;
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.date.text_color);
                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.date.width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;
                /* print current date */
                gui_print_text(s);
                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }
            }

            gui_set_font(main_LCD_dt_object.time.font);
            x = 2;
            y = y + h;
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            /* get current tiem in string format */
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w;
            main_LCD_dt_object.time.height = h;
            if (enable_main_LCD_date_time_display)
            {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;
                gui_set_text_clip(x1, y1, x2, y2);
                /* print time */
                gui_print_text(s);

                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (enable_main_LCD_date_time_display)
            {
                pre_setup_previous_control(main_LCD_dt_object.time.x, main_LCD_dt_object.time.y, 
                    main_LCD_dt_object.time.width, main_LCD_dt_object.time.height);
            }
        }
            break;

        case DT_TABBED_CALL_SCREEN:
        {
            MYTIME curr_time, duration;
            MYTIME *start_time;
            memset (&duration, 0, sizeof(MYTIME));
            memset (&curr_time, 0, sizeof(MYTIME));

            DTGetRTCTime(&curr_time);
            start_time = &main_LCD_time_object.duration_start_time;

            /* overflow 2030/12/31/23:59:59 */
            if (start_time->nYear == 2030 && 
                curr_time.nYear < start_time->nYear)
            {
                curr_time.nYear = start_time->nYear;
                curr_time.nMonth = start_time->nMonth;
                curr_time.nDay = start_time->nDay+1;
            }

            GetTimeDifference(&curr_time, start_time, &duration);
            memcpy(&main_LCD_dt_object.duration.t, &duration, sizeof(MYTIME));

            /* TABBED CALL only have duration. not show date and time */
            if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
            {
				x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
				gui_set_font(main_LCD_dt_object.duration.font);
				duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
				gui_measure_string(s, &w, &h);
				main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
				x2 = main_LCD_dt_object.duration.width + x1 - 1;
				y2 = main_LCD_dt_object.duration.height + y1 - 1;
                if (enable_main_LCD_date_time_display)
				{
                    gui_set_text_color(main_LCD_dt_object.duration.text_color);
					
                    if (mmi_fe_get_r2l_state())
					{
						gui_move_text_cursor(x1 + w - 1, y1);
					}
					else
					{
						gui_move_text_cursor(x1, y1);
					}
					
					/* print call duration */
					gui_print_text(s);
					gdi_layer_blt_previous(
						x1 < old_x1 ? x1 : old_x1,
						y1 < old_y1 ? y1 : old_y1,
						x2 > old_x2 ? x2 : old_x2,
						y2 > old_y2 ? y2 : old_y2);
				}
            }
        }
            break;
        case DT_ACTIVE_CALL_SCREEN:
        {
            if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)//080106 active call
            {
                y = MMI_status_bar_height;
            }
            else
            {
                y = MMI_CONTENT_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT -
                    MMI_TITLE_HEIGHT;
            }

            gui_set_font(main_LCD_dt_object.date.font);
            /* get current date in string format */
            date_string(&main_LCD_dt_object.date.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w;
            main_LCD_dt_object.date.height = h;
            if (enable_main_LCD_date_time_display)
            {
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
                gui_set_text_color(main_LCD_dt_object.date.text_color);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
                if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)
                {
                    /* use list text color to match the full screen background */
                    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
                }
                else
                {
                gui_set_text_color(main_LCD_dt_object.date.text_color);
                }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.date.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = UI_device_width - 1;
                y2 = y1 + main_LCD_dt_object.date.height - 1;
                /* print date */
                gui_print_text(s);
                if (x1 < old_x1)
                {
                    old_x1 = x1;
                }
                if (y1 < old_y1)
                {
                    old_y1 = y1;
                }
                if (x2 > old_x2)
                {
                    old_x2 = x2;
                }
                if (y2 > old_y2)
                {
                    old_y2 = y2;
                }

            }
            gui_set_font(main_LCD_dt_object.time.font);
            /* get current time in string format */
            time_string(&main_LCD_dt_object.time.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);
            x = 2;
            y = y + h + 1;
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w;
            main_LCD_dt_object.time.height = h;
            if (enable_main_LCD_date_time_display)
            {
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
                gui_set_text_color(main_LCD_dt_object.time.text_color);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
                if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)
                {
                    /* use list text color to match the full screen background */
                    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
                }
                else
                {
                gui_set_text_color(main_LCD_dt_object.time.text_color);
                }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

                if (mmi_fe_get_r2l_state())
                {
                    gui_move_text_cursor(x + main_LCD_dt_object.time.width - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x, y);
                }
                x2 = x1 + main_LCD_dt_object.time.width - 1;
                y2 = y1 + main_LCD_dt_object.time.height - 1;
                /* print time */
                gui_print_text(s);
                gdi_layer_blt_previous(
                    x1 < old_x1 ? x1 : old_x1,
                    y1 < old_y1 ? y1 : old_y1,
                    x2 > old_x2 ? x2 : old_x2,
                    y2 > old_y2 ? y2 : old_y2);
            }
            if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
            {
				MYTIME curr_time, duration;
				MYTIME *start_time;
				memset (&duration, 0, sizeof(MYTIME));
				
				DTGetRTCTime(&curr_time);
				start_time = &main_LCD_time_object.duration_start_time;
				
				/* overflow 2030/12/31/23:59:59 */
				if (start_time->nYear == 2030 && 
					curr_time.nYear < start_time->nYear)
				{
					curr_time.nYear = start_time->nYear;
					curr_time.nMonth = start_time->nMonth;
					curr_time.nDay = start_time->nDay+1;
				}
				
				GetTimeDifference(&curr_time, start_time, &duration);
				memcpy(&main_LCD_dt_object.duration.t, &duration, sizeof(MYTIME));

                gui_set_font(main_LCD_dt_object.duration.font);
                x = 2;
                y = y + h + 1;
                /* get call duration in string format */
                duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
                gui_measure_string(s, &w, &h);
                x1 = main_LCD_dt_object.duration.x = x;
                y1 = main_LCD_dt_object.duration.y = y;
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
                if (enable_main_LCD_date_time_display)
                {
                    gui_set_text_color(main_LCD_dt_object.duration.text_color);

                    if (mmi_fe_get_r2l_state())
                    {
                        gui_move_text_cursor(x + w - 1, y);
                    }
                    else
                    {
                        gui_move_text_cursor(x, y);
                    }
                    x2 = x1 + main_LCD_dt_object.duration.width - 1;
                    y2 = y1 + main_LCD_dt_object.duration.height - 1;
                    /* display call duration in active acll screen */
                    gui_print_text(s);
                    gdi_layer_blt_previous(
                        x1 < old_x1 ? x1 : old_x1,
                        y1 < old_y1 ? y1 : old_y1,
                        x2 > old_x2 ? x2 : old_x2,
                        y2 > old_y2 ? y2 : old_y2);
                }
            }
            else
            {
                y = y + h + 1;
                x1 = main_LCD_dt_object.duration.x = x;
            #ifdef __MMI_UCM__
                if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) +
                    srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) != 1)
            #else /* __MMI_UCM__ */   
                if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) +
                    srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 1)
            #endif /* __MMI_UCM__ */
                {
                    y1 = main_LCD_dt_object.duration.y = main_LCD_dt_object.date.y + main_LCD_dt_object.date.height;
                }
                else
                {
                    y1 = main_LCD_dt_object.duration.y = y;
                }
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
            }
            if (enable_main_LCD_date_time_display)
            {
                pre_setup_previous_control(main_LCD_dt_object.duration.x, main_LCD_dt_object.duration.y,
                    main_LCD_dt_object.duration.width, main_LCD_dt_object.duration.height);
            }
        }
            break;
    #ifndef __MMI_DATETIME_SLIM__
        case DT_VOIP_CALL_SCREEN:
        {
            gui_set_font(main_LCD_dt_object.duration.font);
            /* get call duration in string format */
            duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
            gui_measure_string(s, &w, &h);

            if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
                if (enable_main_LCD_date_time_display)
                {
                    gui_set_text_color(main_LCD_dt_object.duration.text_color);

                    if (mmi_fe_get_r2l_state())
                    {
                        gui_move_text_cursor(x1 + w - 1, y1);
                    }
                    else
                    {
                        gui_move_text_cursor(x1, y1);
                    }
                    x2 = x1 + main_LCD_dt_object.duration.width - 1;
                    y2 = y1 + main_LCD_dt_object.duration.height - 1;
                    /* display call duration in active acll screen */
                    gui_print_text(s);
                    if (x1 < old_x1)
                    {
                        old_x1 = x1;
                    }
                    if (y1 < old_y1)
                    {
                        old_y1 = y1;
                    }
                    if (x2 > old_x2)
                    {
                        old_x2 = x2;
                    }
                    if (y2 > old_y2)
                    {
                        old_y2 = y2;
                    }
                    gdi_layer_blt_previous(
                        x1 < old_x1 ? x1 : old_x1,
                        y1 < old_y1 ? y1 : old_y1,
                        x2 > old_x2 ? x2 : old_x2,
                        y2 > old_y2 ? y2 : old_y2);
                }
            }
            else
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                main_LCD_dt_object.duration.width = (UI_device_width >> 1) + 16;
                main_LCD_dt_object.duration.height = h;
            }
            if (enable_main_LCD_date_time_display)
            {
                
                pre_setup_previous_control(main_LCD_dt_object.duration.x, main_LCD_dt_object.duration.y,
                    main_LCD_dt_object.duration.width, main_LCD_dt_object.duration.height);
            }
        }
            break;
    #endif /*__MMI_DATETIME_SLIM__*/

        case DT_DIGITAL_CLOCK_SC1:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_DIGITAL_CLOCK_SC2:   
        case DT_DIGITAL_CLOCK_SC3:
    #endif
        {
                if (enable_main_LCD_date_time_display)
                {
                wgui_clock_show_main_lcd();
                    }

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_push_and_set_clip(                
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 2 - 1);
                show_boundries_to_status_bar_at_bottom_idlescreen();
                gdi_layer_pop_clip();
                gdi_layer_blt_previous(
                    0,
                    0,
                    (UI_device_width - 1),
                    (UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 1 - 2));
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            if (enable_main_LCD_date_time_display)
            {
                if ((show_date == 0 && ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_DIGITAL_CLOCK_SC1)) 
            #ifndef __MMI_DATETIME_SLIM__
                    || main_LCD_dt_object.flags & DT_FLAGS_TYPE == DT_DIGITAL_CLOCK_SC2
            #endif
                    )
                {
                    pre_setup_previous_control(main_LCD_dt_object.date.x, main_LCD_dt_object.date.y,
                        main_LCD_dt_object.date.width, main_LCD_dt_object.date.height);
                }
                else if(main_LCD_dt_object.flags & DT_FLAGS_TYPE == DT_DIGITAL_CLOCK_SC1 
            #ifndef __MMI_DATETIME_SLIM__
                    || (main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_DIGITAL_CLOCK_SC3
            #endif
                    )
                {
                    pre_setup_previous_control(main_LCD_dt_object.time.x, main_LCD_dt_object.time.y,
                        main_LCD_dt_object.time.width, main_LCD_dt_object.time.height);
                }
            }
        }
            break;

    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
        {
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_push_clip();
                gui_set_clip(
                    0,
                    0,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 2 - 1);
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
            if (enable_main_LCD_date_time_display)
            {
                gdi_layer_lock_frame_buffer();
                wgui_clock_show_main_lcd();
            }

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                gdi_layer_pop_clip();
                show_boundries_to_status_bar_at_bottom_idlescreen();
            }
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            if (enable_main_LCD_date_time_display)
            {
                gdi_layer_unlock_frame_buffer();

            #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                gdi_layer_blt_previous(
                    0,
                    (MMI_title_y + MMI_title_height),
                    (UI_device_width - 1),
                    (UI_device_height - wgui_cat033_get_shortcut_max_height() - 1));
			#elif defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
				gdi_layer_blt_previous(
                    0,
                    (MMI_title_y + MMI_title_height),
                    (UI_device_width - 1),
                    (UI_device_height - WGUI_IDLE_SCREEN_ICON_SHORTCUT_HEIGHT - 1));	
            #else /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 

            #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
                if (is_on_idlescreen())
                {
                    gdi_layer_blt_previous(
                        0,
                        0,
                        (UI_device_width - 1),
                        (UI_device_height - 1 - MMI_button_bar_height - MMI_status_bar_height - 1 - 2));
                }
                else
            #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
                    gdi_layer_blt_previous(
                        0,
                        (MMI_title_y + MMI_title_height),
                        (UI_device_width - 1),
                        (UI_device_height - 1));
            #endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
            }
            if (enable_main_LCD_date_time_display)
            {
                if (show_date == 0)
                {
                    pre_setup_previous_control(main_LCD_dt_object.date.x, main_LCD_dt_object.date.y,
                        main_LCD_dt_object.date.width, main_LCD_dt_object.date.height);
                }
                else
                {
                    pre_setup_previous_control(ANALOG_CLOCK_DIAL_X, ANALOG_CLOCK_DIAL_Y,
                        ANALOG_CLOCK_DIAL_WIDTH, ANALOG_CLOCK_DIAL_HEIGHT);
                }
            }
        }
            break;
    #endif /* __MMI_ANALOG_CLOCK__ */ 
    }
    gdi_layer_pop_clip();

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
#ifdef __MMI_SUBLCD__
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  hide_main_LCD_date_time
 * DESCRIPTION
 *  hide function of main lcd date time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_main_LCD_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (main_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    UI_set_main_LCD_graphics_context();
    switch (main_LCD_dt_object.flags & DT_FLAGS_TYPE)
    {
    #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        case DT_IDLE_SCREEN_NO_DAY:
        {
            break;
        }
    #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

        case DT_IDLE_SCREEN:
        case DT_IDLE_SCREEN_2:
        case DT_MO_CALL_SCREEN:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_NETWORK_SEARCH:
        case DT_MO_CALLING_SCREEN:
    #endif
        case DT_MT_CALL_SCREEN:
        {
            /*
             * MTK Justin
             * 
             * Note that we should hide "date" first, then hide "time".
             * The sequence should not be changed.
             * 
             * This is for a hack for optimizing the speed of redraw background image.
             * Please refer to  idle_screen_hide_date_display and
             * idle_screen_hide_time_display
             * 
             * MTK Justin end
             */
            x1 = main_LCD_dt_object.date.x;
            y1 = main_LCD_dt_object.date.y;
            x2 = main_LCD_dt_object.date.width + x1 - 1;
            y2 = main_LCD_dt_object.date.height + y1 - 1;
            main_LCD_dt_object.date.hide_function(x1, y1, x2, y2);

            if (x1 > main_LCD_dt_object.time.x)
            {
                x1 = main_LCD_dt_object.time.x;
            }
            y1 = main_LCD_dt_object.time.y;
            if (x2 < main_LCD_dt_object.time.width + main_LCD_dt_object.time.x)
            {
                x2 = main_LCD_dt_object.time.width + main_LCD_dt_object.time.x - 1;
            }
            y2 = main_LCD_dt_object.time.y + main_LCD_dt_object.time.height - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);      /* call hide function of idle,netwroksearch,call screen */
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN)
            {
                if (g_clock_type == ANALOG)
				{
                x1 = ANALOG_BACKGROUND_X + ANALOG_BACKGROUND_WIDTH;
				}
				else
				{
					x1 = DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH;
				}
                y1 = MMI_status_bar_height + (MMI_IDLESCREEN_BAR_HEIGHT >> 1);
                x2 = UI_device_width - MMI_SIGNAL_WIDTH;
                y2 = y1 + (MMI_IDLESCREEN_BAR_HEIGHT >> 1) - 1;
                MMI_main_LCD_dt_day_hide_function(x1, y1, x2, y2);
            }
        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

        }
            break;
        case DT_TABBED_CALL_SCREEN:
        {
            if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                x2 = main_LCD_dt_object.duration.width + x1 - 1;
                y2 = main_LCD_dt_object.duration.height + y1 - 1;
                main_LCD_dt_object.duration.hide_function(x1, y1, x2, y2);
            }
        }
        break;
        case DT_ACTIVE_CALL_SCREEN:
        {
            x1 = main_LCD_dt_object.date.x;
            y1 = main_LCD_dt_object.date.y;
            x2 = main_LCD_dt_object.date.width + x1 - 1;
            y2 = main_LCD_dt_object.date.height + y1 - 1;
            main_LCD_dt_object.date.hide_function(x1, y1, x2, y2);

            x1 = main_LCD_dt_object.time.x;
            y1 = main_LCD_dt_object.time.y;
            x2 = main_LCD_dt_object.time.width + x1 - 1;
            y2 = main_LCD_dt_object.time.height + y1 - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);

            if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                x2 = main_LCD_dt_object.duration.width + x1 - 1;
                y2 = main_LCD_dt_object.duration.height + y1 - 1;
                main_LCD_dt_object.duration.hide_function(x1, y1, x2, y2);
            }
        }
            break;
    #ifndef __MMI_DATETIME_SLIM__
        case DT_VOIP_CALL_SCREEN:
        {
            if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
            {
                x1 = main_LCD_dt_object.duration.x;
                y1 = main_LCD_dt_object.duration.y;
                x2 = main_LCD_dt_object.duration.width + x1 - 1;
                y2 = main_LCD_dt_object.duration.height + y1 - 1;
                main_LCD_dt_object.duration.hide_function(0, y1, UI_device_width - 1, y2);
            }
        }

            break;
    #endif /*__MMI_DATETIME_SLIM__*/

        case DT_DIGITAL_CLOCK_SC1:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_DIGITAL_CLOCK_SC2:
        case DT_DIGITAL_CLOCK_SC3:
    #endif
        {
            x1 = main_LCD_dt_object.date.x;
            y1 = main_LCD_dt_object.date.y;
            x2 = main_LCD_dt_object.date.width + x1 - 1;
            y2 = main_LCD_dt_object.date.height + y1 - 1;
            main_LCD_dt_object.date.hide_function(x1, y1, x2, y2);

            x1 = main_LCD_dt_object.time.x;
            y1 = main_LCD_dt_object.time.y;
            x2 = main_LCD_dt_object.time.width + x1 - 1;
            y2 = main_LCD_dt_object.time.height + y1 - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);
        }
            break;

    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
        {
            x1 = main_LCD_dt_object.time.x;
            y1 = main_LCD_dt_object.time.y;
            x2 = main_LCD_dt_object.time.width + x1 - 1;
            y2 = main_LCD_dt_object.time.height + y1 - 1;
            main_LCD_dt_object.time.hide_function(x1, y1, x2, y2);
        }
            break;
    #endif /* __MMI_ANALOG_CLOCK__ */ 
    }
    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
#ifdef __MMI_SUBLCD__
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  update_main_LCD_date_time
 * DESCRIPTION
 *  update main lcd date time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_main_LCD_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&main_LCD_dt_object.date.t);
    main_LCD_dt_object.time.t = main_LCD_dt_object.date.t;
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    set_day_display();
    if ((main_LCD_dt_object.flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN)
    {
        gdi_layer_lock_frame_buffer();
        show_main_LCD_day_display();
        gdi_layer_unlock_frame_buffer();
    }
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
    wgui_clock_update_main_lcd();
}


/*****************************************************************************
 * FUNCTION
 *  set_dt_duration
 * DESCRIPTION
 *  set the call duration of category17
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_dt_duration(UI_time *t)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_dt_object.duration.t = *t; /* set the duration value */
    DTGetRTCTime(&last_duration_time);
#endif
}

void main_LCD_measure_time_duration_string(S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    UI_character_type s[64];
    U16 hours, minutes, seconds;
    S8 ts[32];
    U16 i;
    S32 width, height, max_width, max_height;
    
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(main_LCD_time_object.duration.font);

    for (i = 0, max_width = 0, max_height = 0; i <= 9; i ++)
    {
        hours = i;
        minutes = i;
        seconds = i;
    switch (main_LCD_dt_object.flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
    #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        case DT_IDLE_SCREEN_NO_DAY:
    #endif
        case DT_IDLE_SCREEN_ENGLISH_ONLY:
        case DT_MO_CALL_SCREEN:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_NETWORK_SEARCH:
        case DT_MO_CALLING_SCREEN:
        case DT_VOIP_CALL_SCREEN:
    #endif
        case DT_MT_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
#ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        case DT_SUBLCD_IDLE_SCREEN2:
#endif /* __MMI_SUBLCD__ */ 
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
    #ifndef __MMI_DATETIME_SLIM__
        case DT_AUDIO_PLAY_DURATION:
            sprintf((S8*) ts, "%02d:%02d", minutes, seconds);
            break;
    #endif
        default:
                hours = i;
                minutes = i;
                seconds = i;
            sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
            break;
                
    }
    mmi_asc_to_ucs2((S8*) s, ts);

        gui_measure_string(s, &width, &height);

        if (width > max_width)
        {
            max_width = width;
        }

        if (height > max_height)
        {
            max_height = height;
        }
    }

    *w = max_width;
    *h = max_height;


}


#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  show_sub_LCD_date_time1
 * DESCRIPTION
 *  show sub lcd date time when ther is one city set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_sub_LCD_date_time1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bitmap *saved_graphics_context = current_LCD_device_bitmap;
    dm_coordinates coordinates;

#if defined(__MMI_SUBLCD_SHOW_DATE__) || defined(__MMI_SUBLCD_SHOW_TIME__)
    S32 h, w, x, y;
    UI_character_type s[64];
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y = 16; /* magic number by Pixtel */
#endif /* defined(__MMI_SUBLCD_SHOW_DATE__) || defined(__MMI_SUBLCD_SHOW_TIME__) */ 
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    if (enable_sub_LCD_date_time_display)
    {
        GDI_LOCK;
        UI_set_sub_LCD_graphics_context();  /* change graphic context to sub lcd */
    #ifdef __MMI_SUB_WALLPAPER__
        if (sublcd_base_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_push_and_set_active(sublcd_base_layer);
        }
    #endif /* __MMI_SUB_WALLPAPER__ */ 
    }

#ifdef __MMI_SUBLCD_SHOW_DATE__
    gui_set_font(sub_LCD_dt_object1.date.font);
    /* get current date in string format */
    date_string(&sub_LCD_dt_object1.date.t, (UI_string_type) s, sub_LCD_dt_object1.flags);
    gui_measure_string(s, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
    x1 = sub_LCD_dt_object1.date.x = x;
    y1 = sub_LCD_dt_object1.date.y = y;
    sub_LCD_dt_object1.date.width = w;
    sub_LCD_dt_object1.date.height = h - 2;
    if (enable_sub_LCD_date_time_display)
    {

        gui_set_text_color(sub_LCD_dt_object1.date.text_color);

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + sub_LCD_dt_object1.date.width, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }

        x2 = x1 + sub_LCD_dt_object1.date.width - 1;
        y2 = y1 + sub_LCD_dt_object1.date.height - 1;
        gui_set_text_clip(x1, y1, x2, y2);
        /* print date */
        gui_print_text(s);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    coordinates.s16X = sub_LCD_dt_object1.date.x;
    coordinates.s16Y = sub_LCD_dt_object1.date.y;
    coordinates.s16Width = sub_LCD_dt_object1.date.width;
    coordinates.s16Height = sub_LCD_dt_object1.date.height;
    y = y + h;
#endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

#ifdef __MMI_SUBLCD_SHOW_TIME__
    gui_set_font(sub_LCD_dt_object1.time.font);
    /* get current time instring format */
    time_string(&sub_LCD_dt_object1.time.t, (UI_string_type) s, sub_LCD_dt_object1.flags);
    gui_measure_string(s, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
#ifdef __MMI_SUBLCD_SHOW_WORLD_CLOCK__
    y = y + 14;
#endif 
    x1 = sub_LCD_dt_object1.time.x = x;
    y1 = sub_LCD_dt_object1.time.y = y;
    sub_LCD_dt_object1.time.width = w;
    sub_LCD_dt_object1.time.height = h;
    if (enable_sub_LCD_date_time_display)
    {
        gui_set_text_color(sub_LCD_dt_object1.time.text_color);
        gui_set_text_border_color(sub_LCD_dt_object1.time.text_border_color);

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + sub_LCD_dt_object1.time.width, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }

        x2 = x1 + sub_LCD_dt_object1.time.width - 1;
        y2 = y1 + sub_LCD_dt_object1.time.height - 1;
        gui_set_text_clip(x1, y1, x2, y2);
        /* print time */
        gui_print_text(s);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    coordinates.s16X = sub_LCD_dt_object1.time.x;
    coordinates.s16Y = sub_LCD_dt_object1.time.y;
    coordinates.s16Width = sub_LCD_dt_object1.time.width;
    coordinates.s16Height = sub_LCD_dt_object1.time.height;

#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
    gui_set_font(sub_LCD_dt_object2.time.font);
    time_string(&sub_LCD_dt_object2.time.t, (UI_string_type) s, sub_LCD_dt_object2.flags);
    gui_measure_string(s, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
    y = UI_device_height - h;
    x1 = sub_LCD_dt_object2.time.x = x;
    y1 = sub_LCD_dt_object2.time.y = y;
    sub_LCD_dt_object2.time.width = w;
    sub_LCD_dt_object2.time.height = h;
    if (enable_sub_LCD_date_time_display)
    {
        gui_set_text_color(sub_LCD_dt_object2.time.text_color);
        gui_set_text_border_color(sub_LCD_dt_object2.time.text_border_color);
        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + sub_LCD_dt_object2.time.width, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }
        x2 = x1 + sub_LCD_dt_object2.time.width - 1;
        y2 = y1 + sub_LCD_dt_object2.time.height - 1;
        gui_set_text_clip(x1, y1, x2, y2);
        gui_print_text(s);
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
    coordinates.s16X = sub_LCD_dt_object2.time.x;
    coordinates.s16Y = sub_LCD_dt_object2.time.y;
    coordinates.s16Width = sub_LCD_dt_object2.time.width;
    coordinates.s16Height = sub_LCD_dt_object2.time.height;
#endif /* __MMI_SUBLCD_SHOW_ONE_CITY__ */ 

#endif /* __MMI_SUBLCD_SHOW_TIME__ */ 

    setup_previous_control(&coordinates);

    if (enable_sub_LCD_date_time_display)
    {
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }
        GDI_UNLOCK;
    #ifdef __MMI_SUB_WALLPAPER__
        if (sublcd_base_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __MMI_SUB_WALLPAPER__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  hide_sub_LCD_date_time1
 * DESCRIPTION
 *  hide function of date time of sub lcd when only 1 city is set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_sub_LCD_date_time1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    GDI_LOCK;
    UI_set_sub_LCD_graphics_context();

#ifdef __MMI_SUBLCD_SHOW_DATE__
    x1 = sub_LCD_dt_object1.date.x;
    y1 = sub_LCD_dt_object1.date.y;
    x2 = sub_LCD_dt_object1.date.width + x1 - 1;
    y2 = sub_LCD_dt_object1.date.height + y1 - 1;
    sub_LCD_dt_object1.date.hide_function(x1, y1, x2, y2);
#endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

    x1 = sub_LCD_dt_object1.time.x;
    y1 = sub_LCD_dt_object1.time.y;
    x2 = sub_LCD_dt_object1.time.width + x1 - 1;
    y2 = sub_LCD_dt_object1.time.height + y1 - 1;
    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);

#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
    x1 = sub_LCD_dt_object2.time.x;
    y1 = sub_LCD_dt_object2.time.y;
    x2 = sub_LCD_dt_object2.time.width + x1 - 1;
    y2 = sub_LCD_dt_object2.time.height + y1 - 1;
    sub_LCD_dt_object2.time.hide_function(x1, y1, x2, y2);
#endif /* __MMI_SUBLCD_SHOW_ONE_CITY__ */ 

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  update_sub_LCD_date_time1
 * DESCRIPTION
 *  get current date time and update date time on sublcd
 *  when one sub lcd city is set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_sub_LCD_date_time1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    GetDateTime(&sub_LCD_dt_object1.date.t);
    sub_LCD_dt_object2.date.t = sub_LCD_dt_object1.date.t;
    get_time_difference(&sub_LCD_dt_object1.date.t, dt_difference1);    /* get tiem diff of city1 with current time */
    sub_LCD_dt_object1.time.t = sub_LCD_dt_object1.date.t;

#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
    get_time_difference(&sub_LCD_dt_object2.date.t, dt_difference2);    /* get tiem diff of city2 with current time */
    sub_LCD_dt_object2.time.t = sub_LCD_dt_object2.date.t;
#endif /* __MMI_SUBLCD_SHOW_ONE_CITY__ */ 

    GDI_UNLOCK;

    wgui_clock_update_sub_lcd();
}


/*****************************************************************************
 * FUNCTION
 *  show_sub_LCD_date_time2
 * DESCRIPTION
 *  show sub lcd date tiem of 2 cities
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_sub_LCD_date_time2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    if (enable_sub_LCD_date_time_display)
    {
        wgui_clock_show_sub_lcd();
    }

}


/*****************************************************************************
 * FUNCTION
 *  hide_sub_LCD_date_time2
 * DESCRIPTION
 *  hide function of date tiem of sub lcd when 2 cities is set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_sub_LCD_date_time2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_lcd_update_date_time == MMI_FALSE)
    {
        return;
    }

    GDI_LOCK;
    UI_set_sub_LCD_graphics_context();

#if (defined  __MMI_SUBLCD_SHOW_DATE__) && (defined __MMI_SUBLCD_SHOW_TIME__)

    x1 = sub_LCD_dt_object1.date.x;
    x2 = sub_LCD_dt_object1.date.width + x1 - 1;

    if (sublcd_date_time_display_type == SUBLCD_DT_DATE_THEN_TIME_TYPE1)
    {
        y1 = sub_LCD_dt_object1.date.y;
        y2 = sub_LCD_dt_object1.time.height + sub_LCD_dt_object1.time.y - 1;
    }
    else if (sublcd_date_time_display_type == SUBLCD_DT_TIME_THEN_DATE_TYPE1)
    {
        y1 = sub_LCD_dt_object1.time.y;
        y2 = sub_LCD_dt_object1.date.height + sub_LCD_dt_object1.date.y - 1;
    }

    if (x1 > sub_LCD_dt_object1.time.x)
    {
        x1 = sub_LCD_dt_object1.time.x;
    }

    if (x2 < sub_LCD_dt_object1.time.width + sub_LCD_dt_object1.time.x - 1)
    {
        x2 = sub_LCD_dt_object1.time.width + sub_LCD_dt_object1.time.x - 1;
    }

    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);  /* call hide function of time sub lcd */

#elif defined (__MMI_SUBLCD_SHOW_DATE__)

    x1 = sub_LCD_dt_object1.date.x;
    y1 = sub_LCD_dt_object1.date.y;
    x2 = sub_LCD_dt_object1.date.width + x1 - 1;
    y2 = sub_LCD_dt_object1.date.height + y1 - 1;
    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);  /* call hide func of date sub lcd */

#elif defined (__MMI_SUBLCD_SHOW_TIME__)

    x1 = sub_LCD_dt_object1.time.x;
    y1 = sub_LCD_dt_object1.time.y;
    x2 = sub_LCD_dt_object1.time.width + x1 - 1;
    y2 = sub_LCD_dt_object1.time.height + y1 - 1;
    sub_LCD_dt_object1.time.hide_function(x1, y1, x2, y2);  /* call hide function of time sub lcd */

#endif 

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }

    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  update_sub_LCD_date_time2
 * DESCRIPTION
 *  upadet date tiem of sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_sub_LCD_date_time2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    GetDateTime(&sub_LCD_dt_object1.date.t);    /* get current date time */
    get_time_difference(&sub_LCD_dt_object1.date.t, dt_difference1);    /* get time diff between city1 and and current time */
    sub_LCD_dt_object1.time.t = sub_LCD_dt_object1.date.t;
    GDI_UNLOCK;

    wgui_clock_update_sub_lcd();

}
#endif /* __MMI_SUBLCD__ */ 

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_date_hide_function
Description:      date hide funtion pointer of main lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_main_LCD_dt_date_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_time_hide_function
Description:      time hide funtion pointer of main lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_main_LCD_dt_time_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_main_LCD_dt_duration_hide_function
Description:      call time  duration  hide funtion pointer of main lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_main_LCD_dt_duration_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

#ifdef __MMI_SUBLCD__
/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_date_hide_function
Description:      date  hide funtion pointer of sub  lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_sub_LCD_dt_date_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_time_hide_function
Description:      time  hide funtion pointer of sub  lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/

void (*MMI_sub_LCD_dt_time_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;

/*----------------------------------------------------------------------------
Function:         MMI_sub_LCD_dt_duration_hide_function
Description:      call time duration   hide funtion pointer of sub  lcd
Input Parameters: S32 x1   start x position
               S32 y1   start y position
               S32 x2   end x position
               S32 y2   end y position
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*MMI_sub_LCD_dt_duration_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_dt_date_hide_function
 * DESCRIPTION
 *  register date hide function of main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_dt_date_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_date_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_dt_time_hide_function
 * DESCRIPTION
 *  register time hide function of main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_dt_time_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_time_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_dt_duration_hide_function
 * DESCRIPTION
 *  register call time duration  hide function of main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_dt_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_duration_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_sub_LCD_dt_date_hide_function
 * DESCRIPTION
 *  register date hide function of sub lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_sub_LCD_dt_date_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_date_hide_function = f;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  set_sub_LCD_dt_time_hide_function
 * DESCRIPTION
 *  register time hide function of sub lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_sub_LCD_dt_time_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_time_hide_function = f;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  set_sub_LCD_dt_duration_hide_function
 * DESCRIPTION
 *  register cal time duration  hide function of sub lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_sub_LCD_dt_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_duration_hide_function = f;
#endif
}

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_day_hide_function
 * DESCRIPTION
 *  register day hide function of Main LCD
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_day_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_day_hide_function = f;
}
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */


/*****************************************************************************
 * FUNCTION
 *  dt_show_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void dt_show_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    S32 x1, y1, x2, y2;
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    x1 = main_LCD_dt_object.duration.x;
    y1 = main_LCD_dt_object.duration.y;
    x2 = main_LCD_dt_object.duration.width + x1 - 1;
    y2 = main_LCD_dt_object.duration.height + y1 - 1;
    if (main_LCD_dt_object.duration.hide_function)
    {
        main_LCD_dt_object.duration.hide_function(x1, y1, x2, y2);  /* call hide function of call duration */
    }

    gui_set_font(main_LCD_dt_object.duration.font);
    /* get call duration in string fromat */
    duration_string(&main_LCD_dt_object.duration.t, (UI_string_type) s, main_LCD_dt_object.flags);
    gui_set_text_color(main_LCD_dt_object.duration.text_color);
    w = gui_get_string_width(s);

    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x1 + w - 1, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }

    gui_set_text_clip(x1, y1, x2, y2);
    /* print call duration */
    gui_print_text(s);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


#ifndef __MMI_DATETIME_SLIM__
/*****************************************************************************
 * FUNCTION
 *  dt_update_duration_cat19
 * DESCRIPTION
 *  update teh call time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dt_update_duration_cat19(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time, duration;
    MYTIME *start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));

    DTGetRTCTime(&curr_time);
    start_time = NULL;

    if (start_time == NULL)
    {
        return;
    }

    /* overflow 2030/12/31/23:59:59 */
    if (start_time->nYear == 2030 && 
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay+1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);

    memcpy(&main_LCD_dt_object.duration.t, &duration, sizeof(MYTIME));

    if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
    {
		dt_show_duration();
    }
    gui_start_timer(1000, dt_update_duration_cat19);
}
#endif /*__MMI_DATETIME_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  dt_update_duration
 * DESCRIPTION
 *  update teh call time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dt_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time, duration;
    MYTIME *start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));
    memset (&curr_time, 0, sizeof(MYTIME));

    DTGetRTCTime(&curr_time);
    start_time = &main_LCD_time_object.duration_start_time;

    /* overflow 2030/12/31/23:59:59 */
    if (start_time->nYear == 2030 && 
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay+1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);

    memcpy(&main_LCD_dt_object.duration.t, &duration, sizeof(MYTIME));

    if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
    {
        dt_show_duration();
    }
    gui_start_timer(1000, dt_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  dt_update_duration_gprs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dt_update_duration_gprs(void)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    increment_seconds(&main_LCD_dt_object.duration.t);  /* increment secods by 1 */
#ifdef __MMI_UCM__
    if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
    {
#endif /* __MMI_UCM__ */
    dt_show_duration();
#ifdef __MMI_UCM__
    }
#endif

    gui_start_timer(1000, dt_update_duration_gprs);
#endif /*__MMI_DATETIME_SLIM__*/
}


/*****************************************************************************
 * FUNCTION
 *  wgui_datetime_update_mainlcd_cm_duration
 * DESCRIPTION
 *  update call time duration, this func only provide for CM to refresd call duration
 *  NOTICE: This update duration not include category 19
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_datetime_update_mainlcd_cm_duration(void)
{
#ifndef __MMI_DATETIME_SLIM__
    switch (main_LCD_dt_object.flags)
    {
        #ifndef __MMI_CM_SCREEN_HIDE_DATE_TIME__
            case DT_VOIP_CALL_SCREEN:
        #endif /* __MMI_CM_SCREEN_HIDE_DATE_TIME__ */
        case DT_GPRS_ACTIVE_CALL:
        case DT_GPRS_CONF_CALL:
            {
                 dt_update_duration_gprs();
             }
             break;

         #ifndef __MMI_CM_SCREEN_HIDE_DATE_TIME__
             case DT_TABBED_CALL_SCREEN:
             case DT_ACTIVE_CALL_SCREEN:
                {
                     dt_update_duration();
                 }
                 break;
         #endif /* __MMI_CM_SCREEN_HIDE_DATE_TIME__ */

         default:
            break;
    }
#endif/*__MMI_DATETIME_SLIM__*/
}


/*****************************************************************************
 * FUNCTION
 *  CategoryScreenUpdateDuration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Cat19UpdateDuration(MYTIME *t)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME curr_time, duration;
    MYTIME *start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));

    DTGetRTCTime(&curr_time);
    start_time = NULL;

    if (start_time == NULL)
    {
        return;
    }

    /* overflow 2030/12/31/23:59:59 */
    if (start_time->nYear == 2030 && 
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay+1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);

    gui_cancel_timer(dt_update_duration);
    set_dt_duration(&duration);
    if (!(MMI_FALSE == srv_callset_call_time_display_get_mode()))
    {
        dt_show_duration();
    }
    gui_start_timer(1000, dt_update_duration_cat19);
#endif /*__MMI_DATETIME_SLIM__*/
}


/*****************************************************************************
 * FUNCTION
 *  reset_dt_display
 * DESCRIPTION
 *  set dt_display object to initialized value:0
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_dt_object.date.x = main_LCD_dt_object.date.y = 0;
    main_LCD_dt_object.date.height = main_LCD_dt_object.date.width = 0;
    main_LCD_dt_object.time.x = main_LCD_dt_object.time.y = 0;
    main_LCD_dt_object.time.height = main_LCD_dt_object.time.width = 0;
}

/*****************************************************************************
 * FUNCTION
 *  set_dt_update_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_dt_update_function(void)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function of upadet date time of main lcd */
#endif
}


#ifdef __MMI_SUBLCD__
#ifdef __MMI_SUB_WALLPAPER__
extern gdi_handle wgui_sublcd_wallpaper_layer(void);
#endif
#endif
static void set_date_text_font_and_color(U32 clock_id)
{
    wgui_clock_set_date_text_font(clock_id, main_LCD_dt_object.date.font);
    wgui_clock_set_date_text_color(clock_id, main_LCD_dt_object.date.text_color);
    wgui_clock_set_date_text_border_color(clock_id, main_LCD_dt_object.date.text_border_color);
}
static void set_time_text_font_and_color(U32 clock_id)
{
    wgui_clock_set_time_text_font(clock_id, main_LCD_dt_object.time.font);
    wgui_clock_set_time_text_color(clock_id, main_LCD_dt_object.time.text_color);
    wgui_clock_set_time_text_border_color(clock_id, main_LCD_dt_object.time.text_border_color);
}
/*****************************************************************************
 * FUNCTION
 *  set_dt_display
 * DESCRIPTION
 *  set teh hide/dispaly function od date time depend on the
 *  date flag passed as parameter
 * PARAMETERS
 *  flags       [IN]        Date type flag
 * RETURNS
 *  void
 *****************************************************************************/
void set_dt_display(U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 w, h, x, y, x1, y1, x2, y2, x3, y3, x4, y4;
#ifdef __MMI_SUBLCD__    
    S32 date_height, date_width;
    S32 gap;
    S32 time_height, time_width;
    S32 min_x1 = 0, min_y1 = 0, max_x2 = 0, max_y2 = 0;
#endif /* __MMI_SUBLCD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    switch (flags & DT_FLAGS_TYPE)
    {
        case DT_IDLE_SCREEN:
    #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        case DT_IDLE_SCREEN_NO_DAY:
    #endif
        {
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                break;  /* check if dispaly tiem date on idel screen is enabel or not */
            }
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;

            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE_IDLESCREEN1);
	
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;

            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME_IDLESCREEN1);
            main_LCD_dt_object.time.text_color = *current_MMI_theme->idle_scr_time_color;
            main_LCD_dt_object.time.text_border_color = *current_MMI_theme->idle_scr_time_border_color;
	
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            switch (g_clock_type)
            {
                case ANALOG:
                    {
                    wgui_clock_create(
                        &wgui_clock_mainlcd_clock1,
                        ANALOG_CLOCK_DIAL_X + 12 + 1,
                        ANALOG_CLOCK_DIAL_Y + 12 + 1,
                        ANALOG_CLOCK_DIAL_WIDTH - 24,
                        ANALOG_CLOCK_DIAL_HEIGHT - 24,
                        GUI_CLOCK_MAINLCD_TYPE_ANALOG);
                    wgui_clock_set_on_idle(wgui_clock_mainlcd_clock1, MMI_TRUE);
                    wgui_clock_enable_update(wgui_clock_mainlcd_clock1, MMI_FALSE);
                    }
                    break;
                case DIGITAL:

        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

                #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
                    wgui_clock_create(&wgui_clock_mainlcd_clock1,
                        0,0,0,0,
                        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_IMAGE);
                #else
                    wgui_clock_create(&wgui_clock_mainlcd_clock1,
                        0,0,0,0,
                        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME);
                #endif

                    wgui_clock_set_on_idle(wgui_clock_mainlcd_clock1, MMI_TRUE);
                    wgui_clock_enable_update(wgui_clock_mainlcd_clock1, MMI_FALSE);
			    #if defined (__MMI_MAINLCD_128X64__)
                    wgui_clock_set_digital_align_type(wgui_clock_mainlcd_clock1,GUI_CLOCK_DIGITAL_ALIGN_LEFT);
					wgui_clock_set_text_border_enable(wgui_clock_mainlcd_clock1, MMI_FALSE);
                #else
					wgui_clock_set_digital_align_type(wgui_clock_mainlcd_clock1,GUI_CLOCK_DIGITAL_ALIGN_CENTER);
                #endif

                /* in techno bar, we use image instead of text */
                #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
                    wgui_clock_measure_digital_clock(wgui_clock_mainlcd_clock1, &w, &h);
                #else
                    set_time_text_font_and_color(wgui_clock_mainlcd_clock1);
	
                    wgui_clock_measure_time_text(wgui_clock_mainlcd_clock1, 
                        &w, &h, main_LCD_dt_object.time.font);
                #endif

                #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
                    x = DIGITAL_BACKGROUND_X + (DIGITAL_BACKGROUND_WIDTH >> 1) - (w >> 1);
                    y = MMI_status_bar_height + (MMI_IDLESCREEN_BAR_HEIGHT >> 1) - (h >> 1);

                #elif defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    /* change in value of y, when the __MMI_UI_TECHNO_IDLESCREEN_BAR__
                       		is not enabled and idlescreen shortcuts are enabled. */
                    x = (UI_device_width >> 1) - (w >> 1);
                    y = UI_device_height - wgui_cat033_get_shortcut_max_height() - (h + (DT_DISPLAY_GAP << 1)) - 4;
				#elif defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
                    x = (UI_device_width >> 1) - (w >> 1);
                    y = UI_device_height - MMI_softkey_height - (h + (DT_DISPLAY_GAP << 1)) - 4 - WGUI_IDLE_SCREEN_ICON_SHORTCUT_HEIGHT;					
                #else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
                    /* calculate start x ,y and end x,y position of time display string */
                    x = (UI_device_width >> 1) - (w >> 1);
                #if defined(__MMI_OP01_DCD__)
                    if (MMI_TRUE == mmi_dcd_is_switch_on() &&
                        MMI_TRUE == mmi_dcd_is_idle_on())
					{
                        y = MMI_IDLE_DCD_START_Y - h - MMI_DCD_DT_DISPLAY_GAP;
					}
					else
					{
		    			y = UI_device_height - MMI_softkey_height - (h + (DT_DISPLAY_GAP << 1)) - 4;
					}
                #else /* __MMI_OP01_DCD__ */
                    y = UI_device_height - MMI_softkey_height - (h + (DT_DISPLAY_GAP << 1)) - 4;
                #endif /* __MMI_OP01_DCD__ */
                #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

            	#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
                    y = GUI_CALENDAR_TIME_Y;
            	#endif /* defined (__MMI_MAINLCD_128X128__) */

                #if defined (__MMI_MAINLCD_128X64__)
                    x = MMI_IDLE_DT_BORDER_GAP;
                    y = MMI_IDLE_DT_TIME_Y;
                #endif /* defined (__MMI_MAINLCD_128X64__) */

                #ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__
                    w += 2;                
                #endif

                    main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
                    main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
					x1 = main_LCD_dt_object.time.x = x - DT_DISPLAY_GAP;
                    y1 = main_LCD_dt_object.time.y = y - DT_DISPLAY_GAP;

                    wgui_clock_move(wgui_clock_mainlcd_clock1, 
                        x1, y1);
                    wgui_clock_resize(wgui_clock_mainlcd_clock1,
                        main_LCD_dt_object.time.width,
                        main_LCD_dt_object.time.height);

                    x2 = x1 + main_LCD_dt_object.time.width - 1;
                    y2 = y1 + main_LCD_dt_object.time.height - 1;
                    
        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            }
        #endif /*__MMI_UI_TECHNO_IDLESCREEN_BAR__*/
		
            wgui_clock_create(&wgui_clock_mainlcd_clock2, 
                0,0,0,0, 
                GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE);

            wgui_clock_set_on_idle(wgui_clock_mainlcd_clock2, MMI_TRUE);
            wgui_clock_enable_update(wgui_clock_mainlcd_clock2, MMI_FALSE);

        #if defined (__MMI_MAINLCD_128X64__)
            wgui_clock_set_digital_align_type(wgui_clock_mainlcd_clock2,GUI_CLOCK_DIGITAL_ALIGN_RIGHT);
			wgui_clock_set_text_border_enable(wgui_clock_mainlcd_clock2, MMI_FALSE);
        #endif

            set_date_text_font_and_color(wgui_clock_mainlcd_clock2);

            wgui_clock_measure_date_text(wgui_clock_mainlcd_clock2, 
                &w, &h, main_LCD_dt_object.date.font);
        
            /* calculate start x,y and end x,y position of date string display */
			w += 2;

            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
		  #if defined (__MMI_MAINLCD_240X400__)
			x = ((MAIN_LCD_device_width - MMI_SIGNAL_WIDTH) - w);
		  #else
            x = ((MAIN_LCD_device_width - MMI_SIGNAL_WIDTH - 2) - w);
		  #endif
            y = MMI_status_bar_height + (MMI_IDLESCREEN_BAR_HEIGHT >> 2) - (h >> 1);
        #else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
            x = (UI_device_width >> 1) - (main_LCD_dt_object.date.width >> 1);
            y = y1 - main_LCD_dt_object.date.height;
        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

        #if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
            y = GUI_CALENDAR_DATE_Y;
        #endif /* defined (__MMI_MAINLCD_128X128__) */

        #if defined (__MMI_MAINLCD_128X64__)
            x = UI_device_width - main_LCD_dt_object.date.width - MMI_IDLE_DT_BORDER_GAP;
            y = MMI_IDLE_DT_DATE_Y;
        #endif /* defined (__MMI_MAINLCD_128X64__) */

		#ifdef __KJX_FUN__
			y = 264;
		#endif

            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;

            wgui_clock_move(wgui_clock_mainlcd_clock2,
                x1, y1);
            wgui_clock_resize(wgui_clock_mainlcd_clock2,
                main_LCD_dt_object.date.width,
                main_LCD_dt_object.date.height);

        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            if ((flags & DT_FLAGS_TYPE) == DT_IDLE_SCREEN_NO_DAY)
            {
                wgui_clock_close(wgui_clock_mainlcd_clock2);
                wgui_clock_mainlcd_clock2 = WGUI_CLOCK_INVALID_INDEX;
                main_LCD_dt_object.date.x = 0;
                main_LCD_dt_object.date.y = 0;
                main_LCD_dt_object.date.width = 0;
                main_LCD_dt_object.date.height = 0;
            }	
        #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;    /* set function pointer of hide func of date time of main lcd */
            MMI_main_LCD_dt_display_function = UI_dummy_function;

        #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
        #else 
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function of upadet date time of main lcd */
        #endif 

            MMI_main_LCD_dt_update_function();  /* upadet date tiem */
            wgui_clock_enable_update(wgui_clock_mainlcd_clock1, MMI_TRUE);
		#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
            if ((flags & DT_FLAGS_TYPE) != DT_IDLE_SCREEN_NO_DAY)
            {            
            	wgui_clock_enable_update(wgui_clock_mainlcd_clock2, MMI_TRUE);
            }
		#else
            wgui_clock_enable_update(wgui_clock_mainlcd_clock2, MMI_TRUE);
		#endif
        }
            break;

            /* Date/Time display is above softkeys */
        case DT_IDLE_SCREEN_2:
        {
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                break;  /* check if dispaly tiem date on idel screen is enabel or not */
            }

            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;

            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE);
            #if defined (__MMI_UI_STATUS_BAR_AT_BOTTOM__) && defined (__MMI_MAINLCD_240X400__)
                main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM);
	    #endif
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;

            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_DATE);
	    #if defined (__MMI_UI_STATUS_BAR_AT_BOTTOM__) && defined (__MMI_MAINLCD_240X400__)
            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM);
	    #endif
            main_LCD_dt_object.time.text_color = *current_MMI_theme->idle_scr_time_color;
            main_LCD_dt_object.time.text_border_color = *current_MMI_theme->idle_scr_time_border_color;

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;    /* set function pointer of hide func of date time of main lcd */
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set func piinter of show date time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function of upadet date time of main lcd */

        #ifdef __MMI_MAINLCD_96X64__
            wgui_clock_create(&wgui_clock_mainlcd_clock1,
                0,0,0,0,
                GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_TIME_MONTH_DAY_ONE_LINE);
            wgui_clock_set_text_border_enable(wgui_clock_mainlcd_clock1, MMI_FALSE);
        #else
            wgui_clock_create(&wgui_clock_mainlcd_clock1,
                0,0,0,0,
                GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_ONE_LINE);
        #endif

            set_time_text_font_and_color(wgui_clock_mainlcd_clock1);

            set_date_text_font_and_color(wgui_clock_mainlcd_clock1);


            wgui_clock_measure_time_text(wgui_clock_mainlcd_clock1, 
                &w, &h, main_LCD_dt_object.time.font);

            /* calculate start x ,y and end x,y position of time display string */
            x = DT_SOFTKEY_GAP;

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
        #else 
            y = UI_device_height - MMI_button_bar_height - h - DT_SOFTKEY_GAP - 1;
        #endif 

            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
		#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
			#if defined(__MMI_MAINLCD_176X220__)
			main_LCD_dt_object.time.height = h;
			#else
			main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
			#endif
		#else /* (__MMI_UI_STATUS_BAR_AT_BOTTOM__) */
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);
		#endif /* (__MMI_UI_STATUS_BAR_AT_BOTTOM__) */
            x2 = x1 + main_LCD_dt_object.time.width - 1;
            y2 = y1 + main_LCD_dt_object.time.height - 1;

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            main_LCD_dt_object.flags &= ~DT_IDLE_SCREEN_2;
            main_LCD_dt_object.flags |= DT_IDLE_SCREEN;

        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
        
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            main_LCD_dt_object.flags &= ~DT_IDLE_SCREEN;
            main_LCD_dt_object.flags |= DT_IDLE_SCREEN_2;
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
        
            /* calculate date string width */
            wgui_clock_measure_date_text(wgui_clock_mainlcd_clock1, 
                &w, &h, main_LCD_dt_object.date.font);
        
            /* calculate start x,y and end x,y position of date string display */
            x = UI_device_width - 1 - w - DT_SOFTKEY_GAP;

        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
        #else 
            y = UI_device_height - MMI_button_bar_height - h - DT_SOFTKEY_GAP - 1;
        #endif 

            x3 = main_LCD_dt_object.date.x = x;
            y3 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
		#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
			#if defined(__MMI_MAINLCD_176X220__)
			main_LCD_dt_object.date.height = h;
			#else
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
			#endif
		#else /* (__MMI_UI_STATUS_BAR_AT_BOTTOM__) */
			main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
		#endif /* (__MMI_UI_STATUS_BAR_AT_BOTTOM__) */
            x4 = x3 + main_LCD_dt_object.date.width - 1;
            y4 = y3 + main_LCD_dt_object.date.height - 1;

            wgui_clock_move(wgui_clock_mainlcd_clock1, 
                min(x1, x3), min(y1,y3));

            wgui_clock_resize(wgui_clock_mainlcd_clock1, 
                max(x2, x4) - min(x1, x3) + 1, 
                max(y2, y4) - min(y1,y3) + 1);

            MMI_main_LCD_dt_update_function();  /* upadet date tiem */
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function(); /* display date tiem on main lcd */
            enable_main_LCD_date_time_display = 1;
        }
            break;

    #ifndef __MMI_DATETIME_SLIM__
        case DT_NETWORK_SEARCH:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE);
        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME_NETWORK_SEARCH);

        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.time.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;    /* set function pointer of hide func of main lcd */
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set function pointer of show date/time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;        /* set function pointer of upadet date/time of main lcd */
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    #endif /*__MMI_DATETIME_SLIM__*/

    #ifndef __MMI_CM_SCREEN_HIDE_DATE_TIME__
        case DT_MO_CALL_SCREEN:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_MO_CALLING_SCREEN:
        case DT_VOIP_CALL_SCREEN:
    #endif
        case DT_MT_CALL_SCREEN:
        case DT_TABBED_CALL_SCREEN:
        case DT_ACTIVE_CALL_SCREEN:
        {
        #ifndef __MMI_DATETIME_SLIM__
            if ((flags & DT_FLAGS_TYPE) != DT_VOIP_CALL_SCREEN)
        #endif
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE);
            main_LCD_dt_object.date.text_color = *current_MMI_theme->datetime_bar_date_text_color;
            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME);
            main_LCD_dt_object.time.text_color = *current_MMI_theme->datetime_bar_time_text_color;
            }
            
            if ((flags & DT_FLAGS_TYPE) == DT_TABBED_CALL_SCREEN 
                || (flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN
            #ifndef __MMI_DATETIME_SLIM__
                || (flags & DT_FLAGS_TYPE) == DT_VOIP_CALL_SCREEN
            #endif
                )
            {
                main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;  
                main_LCD_dt_object.duration.font = gui_font_get_type(GUI_FONT_SIZE_DURATION);
                main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
            }
            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            if ((flags & DT_FLAGS_TYPE) == DT_TABBED_CALL_SCREEN 
                || (flags & DT_FLAGS_TYPE) == DT_ACTIVE_CALL_SCREEN)
            {
                gui_start_timer(1000, dt_update_duration);
            }
        #ifndef __MMI_DATETIME_SLIM__
            if ((flags & DT_FLAGS_TYPE) == DT_VOIP_CALL_SCREEN)
            {
                gui_start_timer(1000, dt_update_duration_gprs);
            }
        #endif
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    /*    case DT_VOIP_CALL_SCREEN:
            {
                main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
                main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
                main_LCD_dt_object.duration.font = gui_font_get_type(GUI_FONT_SIZE_DURATION);
                main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
                MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
                MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
                MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
                gui_start_timer(1000, dt_update_duration_gprs);
                MMI_main_LCD_dt_update_function();
                enable_main_LCD_date_time_display = 0;
                MMI_main_LCD_dt_display_function();
                enable_main_LCD_date_time_display = 1;
            }
                break;
        */
    #endif /* __MMI_CM_SCREEN_HIDE_DATE_TIME__ */ 
    #ifndef __MMI_DATETIME_SLIM__
        case DT_GPRS_ACTIVE_CALL:
        case DT_GPRS_CONF_CALL:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
            if ((flags & DT_FLAGS_TYPE) == DT_GPRS_ACTIVE_CALL)
            {
                main_LCD_dt_object.duration.font = gui_font_get_type(GUI_FONT_SIZE_DURATION_ACTIVE_CALL);
                main_LCD_dt_object.duration.y = MMI_status_bar_height;
            }
            else
            {
                main_LCD_dt_object.duration.font = gui_font_get_type(GUI_FONT_SIZE_DURATION_CONF_CALL);
                main_LCD_dt_object.duration.y = MMI_status_bar_height + 20;
            }
            main_LCD_dt_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
            main_LCD_dt_object.duration.x = 0;
            main_LCD_dt_object.duration.width = UI_device_width - 1;
            main_LCD_dt_object.duration.height = DURATION_CM_HEIGHT;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time; /* set func piinter of show date time of main lcd */
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            gui_start_timer(1000, dt_update_duration_gprs);
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;

        }
            break;
    #endif /*__MMI_DATETIME_SLIM__*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    #ifdef __MMI_SUBLCD__
        case DT_SUBLCD_IDLE_SCREEN1:
        {
            sub_LCD_dt_object1.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object1.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object1.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
            sub_LCD_dt_object1.date.font = gui_font_get_type(GUI_FONT_SIZE_SUB_DATE);
            sub_LCD_dt_object1.date.text_color = gui_color(0, 0, 0);
            sub_LCD_dt_object1.time.font = gui_font_get_type(GUI_FONT_SIZE_SUB_TIME);
            sub_LCD_dt_object1.time.text_color = gui_color(0, 0, 0);

            sub_LCD_dt_object2.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object2.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object2.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
            sub_LCD_dt_object2.date.font = gui_font_get_type(GUI_FONT_SIZE_SUB_DATE);
            sub_LCD_dt_object2.date.text_color = gui_color(0, 0, 0);
            sub_LCD_dt_object2.time.font = gui_font_get_type(GUI_FONT_SIZE_SUB_TIME);
            sub_LCD_dt_object2.time.text_color = gui_color(0, 0, 0);

            MMI_sub_LCD_dt_hide_function = hide_sub_LCD_date_time1;
            MMI_sub_LCD_dt_display_function = show_sub_LCD_date_time1;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time1;
            MMI_sub_LCD_dt_update_function();
            enable_sub_LCD_date_time_display = 0;
            MMI_sub_LCD_dt_display_function();
            enable_sub_LCD_date_time_display = 1;
        }
            break;

        case DT_SUBLCD_IDLE_SCREEN2:
        case DT_SUBLCD_IDLE_SCREEN3:
        case DT_SUBLCD_IDLE_SCREEN4:
        {
            gdi_handle sublcd_abm_layer = NULL;
            if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN2)
            {
                sublcd_date_time_display_type = SUBLCD_DT_DATE_THEN_TIME_TYPE1;
            }
            else if((flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN3) || (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN4))
            {                     
                sublcd_date_time_display_type = SUBLCD_DT_TIME_THEN_DATE_TYPE1;
            }
            sub_LCD_dt_object1.flags = (flags & DT_FLAGS_TYPE);
            sub_LCD_dt_object1.date.hide_function = MMI_sub_LCD_dt_date_hide_function;
            sub_LCD_dt_object1.time.hide_function = MMI_sub_LCD_dt_time_hide_function;
            if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN4)
            {                
                sub_LCD_dt_object1.date.font = gui_font_get_type(GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4);
            }
        #ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
            else if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN2)
            {
                sub_LCD_dt_object1.date.font = gui_font_get_type(GUI_FONT_SIZE_SUB_LARGE_DATE);
            }
            else if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN3)
            {            
                sub_LCD_dt_object1.time.font = gui_font_get_type(GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3);
            }
        #else 
            else
            {
                sub_LCD_dt_object1.date.font = gui_font_get_type(GUI_FONT_SIZE_SUB_DATE);
            }
        #endif 

        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.date.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.date.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN4)
            {               
                sub_LCD_dt_object1.date.text_color = gui_color(130, 230, 220);
            }
            else
            {
                sub_LCD_dt_object1.date.text_color = gui_color(0, 0, 0);
            }
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN4)
            {
                sub_LCD_dt_object1.time.font = gui_font_get_type(GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4);
            }
            else
            {
        #ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
            sub_LCD_dt_object1.time.font = gui_font_get_type(GUI_FONT_SIZE_SUB_LARGE_TIME);
        #else 
            sub_LCD_dt_object1.time.font = gui_font_get_type(GUI_FONT_SIZE_SUB_TIME);
        #endif 
            }

        #ifdef __MMI_SUB_WALLPAPER__
            sub_LCD_dt_object1.time.text_color = gui_color(255, 255, 255);
            sub_LCD_dt_object1.time.text_border_color = gui_color(0, 0, 0);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN4)
            {                
                sub_LCD_dt_object1.time.text_color = gui_color(255, 255, 0);
            }
            else //screen 2 or screen 3
            {
                sub_LCD_dt_object1.time.text_color = gui_color(0, 0, 0);
            }
        #endif /* __MMI_SUB_WALLPAPER__ */ 


            if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN2)
            {
                wgui_clock_create(&wgui_clock_sublcd_clock1,
                    0,0,0,0,
                    GUI_CLOCK_SUBLCD_TYPE2);
            }
            else if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN3)
            { 
                wgui_clock_create(&wgui_clock_sublcd_clock1,
                    0,0,0,0,
                    GUI_CLOCK_SUBLCD_TYPE3);           
            }
            else if (flags & DT_FLAGS_TYPE == DT_SUBLCD_IDLE_SCREEN4)
            {
                wgui_clock_create(&wgui_clock_sublcd_clock1,
                    0,0,0,0,
                    GUI_CLOCK_SUBLCD_TYPE4);
            }

        #ifndef __MMI_SUB_WALLPAPER__
            wgui_clock_set_text_border_enable(wgui_clock_sublcd_clock1, MMI_FALSE);
        #else
            sublcd_abm_layer = wgui_sublcd_wallpaper_layer();
            if(sublcd_abm_layer != GDI_ERROR_HANDLE)
            {
                wgui_clock_set_abm_layer(wgui_clock_sublcd_clock1, sublcd_abm_layer);
            }
        #endif /* __MMI_SUB_WALLPAPER__ */ 

        #if defined (__MMI_SUBLCD_SHOW_DATE__) && defined (__MMI_SUBLCD_SHOW_TIME__)
            wgui_clock_measure_date_text(
                wgui_clock_sublcd_clock1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            wgui_clock_measure_time_text(
                wgui_clock_sublcd_clock1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - (Sub_lcd_title_height * 4) - date_height - time_height) / 3;

            if (sublcd_date_time_display_type == SUBLCD_DT_DATE_THEN_TIME_TYPE1)
            {
                sub_LCD_dt_object1.date.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;
            }
            else if (sublcd_date_time_display_type == SUBLCD_DT_TIME_THEN_DATE_TYPE1)
            {
                sub_LCD_dt_object1.time.y = UI_device_height - (gap << 1) - date_height - time_height - 1;
                sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;
            }

        #elif defined (__MMI_SUBLCD_SHOW_DATE__)
            wgui_clock_measure_date_text(
                wgui_clock_sublcd_clock1,
                &date_width,
                &date_height,
                sub_LCD_dt_object1.date.font);
        #ifdef __MMI_SUB_WALLPAPER__
            date_width += 2;    /* 2 is for border size. */
            date_height += 2;   /* 2 is for border size. */
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            gap = (UI_device_height - (Sub_lcd_title_height * 4) - date_height) >> 1;
            sub_LCD_dt_object1.date.y = UI_device_height - gap - date_height - 1;

        #elif defined (__MMI_SUBLCD_SHOW_TIME__)

            wgui_clock_measure_time_text(
                wgui_clock_sublcd_clock1,
                &time_width,
                &time_height,
                sub_LCD_dt_object1.time.font);
        
            time_width += 2;    /* 2 is for border size. */
            time_height += 2;   /* 2 is for border size. */

            gap = (UI_device_height - (Sub_lcd_title_height * 4) - time_height) >> 1;
            sub_LCD_dt_object1.time.y = UI_device_height - gap - time_height - 1;

        #endif 

        #ifdef __MMI_SUBLCD_SHOW_DATE__

            x1 = sub_LCD_dt_object1.date.x = (UI_device_width - date_width) >> 1;
            y1 = sub_LCD_dt_object1.date.y;
            sub_LCD_dt_object1.date.width = date_width;
            sub_LCD_dt_object1.date.height = date_height;
            x2 = x1 + date_width - 1;
            y2 = y1 + date_height - 1;

            min_x1 = x1;
            min_y1 = y1;
            max_x2 = x2;
            max_y2 = y2;

        #endif /* __MMI_SUBLCD_SHOW_DATE__ */ 

        #ifdef __MMI_SUBLCD_SHOW_TIME__
            x3 = sub_LCD_dt_object1.time.x = (UI_device_width - time_width) >> 1;
            y3 = sub_LCD_dt_object1.time.y;
            sub_LCD_dt_object1.time.width = time_width;
            sub_LCD_dt_object1.time.height = time_height;
            x4 = x3 + time_width - 1;
            y4 = y3 + time_height - 1;

            if (min_x1 == max_x2 && min_y1 == max_y2)
            {
                min_x1 = x3;
                min_y1 = y3;
                max_x2 = x4;
                max_y2 = y4;
            }
            else
            {
                min_x1 = min(min_x1, x3);
                min_y1 = min(min_y1, y3);
                max_x2 = max(max_x2, x4);
                max_y2 = max(max_y2, y4);
            }
            
        #endif /* __MMI_SUBLCD_SHOW_TIME__ */ 

            wgui_clock_move(wgui_clock_sublcd_clock1, 0, min_y1);

            wgui_clock_resize(wgui_clock_sublcd_clock1,
                SUBLCD_WIDTH, max_y2 - min_y1 + 1);

            wgui_clock_set_gap_between_two_lines(wgui_clock_sublcd_clock1, 
                gap);
        
            MMI_sub_LCD_dt_hide_function = hide_sub_LCD_date_time2;
            MMI_sub_LCD_dt_display_function = show_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time2;
            MMI_sub_LCD_dt_update_function();
            enable_sub_LCD_date_time_display = 0;
            MMI_sub_LCD_dt_display_function();
            enable_sub_LCD_date_time_display = 1;
        }
            break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #else /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #else /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifndef __MMI_SUB_WALLPAPER__
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #if defined (__MMI_SUBLCD_SHOW_DATE__) && defined (__MMI_SUBLCD_SHOW_TIME__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #elif defined (__MMI_SUBLCD_SHOW_DATE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #elif defined (__MMI_SUBLCD_SHOW_TIME__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
        #ifdef __MMI_SUBLCD_SHOW_DATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUBLCD_SHOW_DATE__ */ 
/* under construction !*/
        #ifdef __MMI_SUBLCD_SHOW_TIME__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUBLCD_SHOW_TIME__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #else /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #else /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifndef __MMI_SUB_WALLPAPER__
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
        #if defined (__MMI_SUBLCD_SHOW_DATE__) && defined (__MMI_SUBLCD_SHOW_TIME__)
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #elif defined (__MMI_SUBLCD_SHOW_DATE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUB_WALLPAPER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #elif defined (__MMI_SUBLCD_SHOW_TIME__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
        #ifdef __MMI_SUBLCD_SHOW_DATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUBLCD_SHOW_DATE__ */ 
/* under construction !*/
        #ifdef __MMI_SUBLCD_SHOW_TIME__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SUBLCD_SHOW_TIME__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    #endif /* __MMI_SUBLCD__ */ 
        case DT_DIGITAL_CLOCK_SC1:
    #ifndef __MMI_DATETIME_SLIM__
        case DT_DIGITAL_CLOCK_SC3:
    #endif
        {
        
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }
        
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE);
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC);
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
#else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;
            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC);
            main_LCD_dt_object.time.text_color = *current_MMI_theme->idle_scr_time_color;
            main_LCD_dt_object.time.text_border_color = *current_MMI_theme->idle_scr_time_border_color;
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 


            wgui_clock_create(&wgui_clock_mainlcd_clock1,0,0,
                0,
                0,
                GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME);

            
            set_date_text_font_and_color(wgui_clock_mainlcd_clock1);            
            set_time_text_font_and_color(wgui_clock_mainlcd_clock1);

            wgui_clock_measure_time_text(wgui_clock_mainlcd_clock1, 
                &w, &h, main_LCD_dt_object.time.font);
            
            x = (UI_device_width >> 1) - (w >> 1);
            y = (UI_device_height >> 1) - (h >> 1);
            x1 = main_LCD_dt_object.time.x = x;
            y1 = main_LCD_dt_object.time.y = y;
            main_LCD_dt_object.time.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.time.height = h + (DT_DISPLAY_GAP << 1);

            wgui_clock_move(wgui_clock_mainlcd_clock1, x1, y1);
            
            wgui_clock_resize(wgui_clock_mainlcd_clock1, main_LCD_dt_object.time.width, main_LCD_dt_object.time.height);

            if (show_date == 0 && ((flags & DT_FLAGS_TYPE) == DT_DIGITAL_CLOCK_SC1)) /* if display date time is enable */
            {
            #if defined(__MMI_OP01_DCD__)
                if (!(MMI_TRUE == mmi_dcd_is_switch_on() && MMI_TRUE == mmi_dcd_is_idle_on()))
                {
            #endif
                wgui_clock_create(&wgui_clock_mainlcd_clock2, 
                    0,0,0,0, 
                    GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE);
                
                set_date_text_font_and_color(wgui_clock_mainlcd_clock2);
                
                set_time_text_font_and_color(wgui_clock_mainlcd_clock2);
                
                wgui_clock_measure_date_text(wgui_clock_mainlcd_clock2, 
                    &w, &h, 
                    main_LCD_dt_object.date.font);
                
                x = (UI_device_width >> 1) - (w >> 1);
            #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
                if (is_on_idlescreen())
                {
                    y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
                }
                else
            #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    /* change in value of y, when idlescreen shortcuts are enabled. */
                    y = UI_device_height - wgui_cat033_get_shortcut_max_height() - h - 4;
			#elif defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)				  	
					y = UI_device_height - WGUI_IDLE_SCREEN_ICON_SHORTCUT_HEIGHT - h - 4;			
            #else /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
                    y = UI_device_height - MMI_button_bar_height - h - 4;
            #endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 

                x1 = main_LCD_dt_object.date.x = x;
                y1 = main_LCD_dt_object.date.y = y;
                main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
				#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
					#if defined(__MMI_MAINLCD_176X220__)
						main_LCD_dt_object.date.height = h;
					#else
                main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
					#endif
				#else /* (__MMI_UI_STATUS_BAR_AT_BOTTOM__) */
					main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);
				#endif /* (__MMI_UI_STATUS_BAR_AT_BOTTOM__) */

                wgui_clock_move(wgui_clock_mainlcd_clock2, x1, y1);
                wgui_clock_resize(
                    wgui_clock_mainlcd_clock2,
                    main_LCD_dt_object.date.width,
                    main_LCD_dt_object.date.height);
            #if defined(__MMI_OP01_DCD__)
                }
            #endif
            }   /* show_date == 0 */
        
            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    #ifndef __MMI_DATETIME_SLIM__
        case DT_DIGITAL_CLOCK_SC2:
        {
        
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE)
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }
        
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE);
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC);
            main_LCD_dt_object.time.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
#else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
            main_LCD_dt_object.time.font = gui_font_get_type(GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC);
            main_LCD_dt_object.time.text_color = gui_color(0, 0, 0);
            main_LCD_dt_object.time.text_border_color = gui_color(255, 255, 255);
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 


            wgui_clock_create(&wgui_clock_mainlcd_clock1,0,0,
                0,
                0,
                GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE);

            set_date_text_font_and_color(wgui_clock_mainlcd_clock1);
            
            set_time_text_font_and_color(wgui_clock_mainlcd_clock1);

            wgui_clock_measure_date_text(wgui_clock_mainlcd_clock1, 
                &w, &h, main_LCD_dt_object.date.font);

            x = (UI_device_width >> 1) - (w >> 1);
        #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
            if (is_on_idlescreen())
            {
                y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
            }
            else
        #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 
                y = UI_device_height - MMI_button_bar_height - (h + (DT_DISPLAY_GAP << 1)) - 4;

            x1 = main_LCD_dt_object.date.x = x;
            y1 = main_LCD_dt_object.date.y = y;
            main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
            main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

            
            wgui_clock_move(wgui_clock_mainlcd_clock1, 
                x1, y1);

            wgui_clock_resize(wgui_clock_mainlcd_clock1, 
                main_LCD_dt_object.date.width, 
                main_LCD_dt_object.date.height);

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
                break;
    #endif /*__MMI_DATETIME_SLIM__*/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    #ifdef __MMI_ANALOG_CLOCK__
        case DT_ANALOG_CLOCK_SC:
        {
            if (PhnsetGetShowDateTimeStatus() == MMI_FALSE) /* check if display of date is enable on idle screen or not */
            {
                show_date = 1;
            }
            else
            {
                show_date = 0;
            }
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.date.hide_function = MMI_main_LCD_dt_date_hide_function;
            main_LCD_dt_object.time.hide_function = MMI_main_LCD_dt_time_hide_function;
            main_LCD_dt_object.date.font = gui_font_get_type(GUI_FONT_SIZE_DATE);

        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.date.text_color = *current_MMI_theme->title_text_color;
            main_LCD_dt_object.date.text_border_color = gui_color(255, 255, 255);
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.date.text_color = *current_MMI_theme->idle_scr_date_color;
            main_LCD_dt_object.date.text_border_color = *current_MMI_theme->idle_scr_date_border_color;
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            main_LCD_dt_object.time.x = ANALOG_CLOCK_DIAL_X;
            main_LCD_dt_object.time.y = ANALOG_CLOCK_DIAL_Y;
            main_LCD_dt_object.time.width = ANALOG_CLOCK_DIAL_WIDTH;
            main_LCD_dt_object.time.height = ANALOG_CLOCK_DIAL_HEIGHT;
            wgui_clock_create(&wgui_clock_mainlcd_clock1,
                ANALOG_CLOCK_DIAL_X,
                ANALOG_CLOCK_DIAL_Y,
                ANALOG_CLOCK_DIAL_WIDTH,
                ANALOG_CLOCK_DIAL_HEIGHT,
                GUI_CLOCK_MAINLCD_TYPE_ANALOG);

            if (show_date == 0 && wgui_datetime_need_show_date == MMI_TRUE)
            {
            #if defined(__MMI_OP01_DCD__)
                if (!(MMI_TRUE == mmi_dcd_is_switch_on() && MMI_TRUE == mmi_dcd_is_idle_on()))
                {
            #endif
                wgui_clock_create(&wgui_clock_mainlcd_clock2,
                    0,0,0,0,
                    GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE);

                set_date_text_font_and_color(wgui_clock_mainlcd_clock2);

                wgui_clock_measure_date_text(wgui_clock_mainlcd_clock2, 
                    &w, &h, main_LCD_dt_object.date.font);
                                
                x = (UI_device_width >> 1) - (w >> 1);

            #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
                if (is_on_idlescreen())
                {
                    y = DT_DISPLAY_OFFSET_IN_STATUS_BAR_AT_BOTTOM;
                }
                else
            #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */ 

            #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    /* change in value of y, when idlescreen shortcuts are enabled. */
                    y = UI_device_height - wgui_cat033_get_shortcut_max_height() - (h + (DT_DISPLAY_GAP << 1));
			#elif defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
					y = UI_device_height - WGUI_IDLE_SCREEN_ICON_SHORTCUT_HEIGHT - (h + (DT_DISPLAY_GAP << 1));
            #else /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 
                    y = UI_device_height - MMI_button_bar_height - (h + (DT_DISPLAY_GAP << 1));
            #endif /* defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */ 

                x1 = main_LCD_dt_object.date.x = x;
                y1 = main_LCD_dt_object.date.y = y;
                main_LCD_dt_object.date.width = w + (DT_DISPLAY_GAP << 1);
                main_LCD_dt_object.date.height = h + (DT_DISPLAY_GAP << 1);

                wgui_clock_move(wgui_clock_mainlcd_clock2,
                    x1, y1);
                wgui_clock_resize(wgui_clock_mainlcd_clock2, 
                    main_LCD_dt_object.date.width, 
                    main_LCD_dt_object.date.height);
            #if defined(__MMI_OP01_DCD__)
                }
            #endif
            }

        

            MMI_main_LCD_dt_hide_function = hide_main_LCD_date_time;
            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    #endif /* __MMI_ANALOG_CLOCK__ */ 
    #ifndef __MMI_DATETIME_SLIM__
        case DT_AUDIO_PLAY_DURATION:
        {
            main_LCD_dt_object.flags = (flags & DT_FLAGS_TYPE);
            main_LCD_dt_object.duration.x = 6;
            main_LCD_dt_object.duration.y = 30;
            main_LCD_dt_object.duration.width = 44;
            main_LCD_dt_object.duration.height = 19;
            main_LCD_dt_object.duration.hide_function = MMI_main_LCD_dt_duration_hide_function;
        #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
            main_LCD_dt_object.duration.font = gui_font_get_type(GUI_FONT_SIZE_DURATION_AUDIO_PLAY);
            main_LCD_dt_object.duration.text_color = *current_MMI_theme->title_text_color;
        #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 
            main_LCD_dt_object.duration.font = gui_font_get_type(GUI_FONT_SIZE_DURATION_AUDIO_PLAY);
            main_LCD_dt_object.duration.text_color = gui_color(0, 255, 0);
        #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */ 

            MMI_main_LCD_dt_display_function = show_main_LCD_date_time;
            MMI_main_LCD_dt_update_function = update_main_LCD_date_time;
            MMI_main_LCD_dt_update_function();
            enable_main_LCD_date_time_display = 0;
            MMI_main_LCD_dt_display_function();
            enable_main_LCD_date_time_display = 1;
        }
            break;
    #endif /*__MMI_DATETIME_SLIM__*/
    #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
        case DT_SUBLCD_ANALOG_CLOCK:
        {
            wgui_clock_create(&wgui_clock_sublcd_clock1,
                g_gui_clock_sub_lcd_analog_clock_dial_x,
                g_gui_clock_sub_lcd_analog_clock_dial_y,
                GUI_CLOCK_SUB_ANALOG_CLOCK_SECONDS_HAND_LENGTH,
                GUI_CLOCK_SUB_ANALOG_CLOCK_SECONDS_HAND_LENGTH,
                GUI_CLOCK_SUBLCD_ANALOG_CLOCK);
            
            MMI_sub_LCD_dt_hide_function = UI_dummy_function;
            MMI_sub_LCD_dt_display_function = RedrawSubLCDAnalogClockScreen;
            MMI_sub_LCD_dt_update_function = update_sub_LCD_date_time1;
        }
            break;
    #endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
        default:
            reset_dt_display();
    }
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  close_main_LCD_dt_display
 * DESCRIPTION
 *  set all function pointer of date tiem display ofmain lcd
 *  to dummy functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_main_LCD_dt_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_dt_update_function = UI_dummy_function;
    MMI_main_LCD_dt_display_function = UI_dummy_function;
    MMI_main_LCD_dt_hide_function = UI_dummy_function;
    MMI_main_LCD_dt_close_function();
    MMI_main_LCD_dt_close_function = UI_dummy_function;
    MMI_main_LCD_dt_date_hide_function = UI_dummy_hide_function;
    MMI_main_LCD_dt_time_hide_function = UI_dummy_hide_function;
    MMI_main_LCD_dt_duration_hide_function = UI_dummy_hide_function;
    gui_cancel_timer(dt_update_duration);
#ifndef __MMI_DATETIME_SLIM__
    gui_cancel_timer(dt_update_duration_gprs);
    gui_cancel_timer(dt_update_duration_cat19);
#endif
    wgui_clock_close_main_lcd();
    
}


/*****************************************************************************
 * FUNCTION
 *  close_sub_LCD_dt_display
 * DESCRIPTION
 *  set all function pointer of date tiem display of sub  lcd
 *  to dummy functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_sub_LCD_dt_display(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_sub_LCD_dt_update_function = UI_dummy_function;
    MMI_sub_LCD_dt_display_function = UI_dummy_function;
    MMI_sub_LCD_dt_hide_function = UI_dummy_function;
    MMI_sub_LCD_dt_close_function();
    MMI_sub_LCD_dt_close_function = UI_dummy_function;
    MMI_sub_LCD_dt_date_hide_function = UI_dummy_hide_function;
    MMI_sub_LCD_dt_time_hide_function = UI_dummy_hide_function;
    MMI_sub_LCD_dt_duration_hide_function = UI_dummy_hide_function;

    wgui_clock_close_sub_lcd();
#endif    
}

/* global variable store the call cost symbol */
PU8 UI_call_cost_symbol = NULL;

/* global variable store the call cost valeu */
PU8 UI_call_cost_value = NULL;

/*****************************************************************************
 * FUNCTION
 *  reset_call_cost_UI
 * DESCRIPTION
 *  reset the call cost and call symbol to null
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_call_cost_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_call_cost_symbol = NULL;
    UI_call_cost_value = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  show_call_cost_UI
 * DESCRIPTION
 *  show call cost on active calll screen
 * PARAMETERS
 *  symbol      [IN]        Currency symbol
 *  value       [IN]        Total cost
 * RETURNS
 *  void
 *****************************************************************************/
/* code added vandana mehtani AOC   */
void show_call_cost_UI(PU8 symbol, PU8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height;
    UI_character_type Buffer[30];
    S32 tx, ty, x;
    color c = *current_MMI_theme->datetime_bar_AOC_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_call_cost_symbol = symbol;
    UI_call_cost_value = value;


    if ((NULL == symbol) || (NULL == value))
    {
        return;
    }

    if (!mmi_ucm_get_show_aoc())
    {
        return ;
    }

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    x = (UI_device_width >> 1) + 16;
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_DURATION));
    gui_strcpy(Buffer, (U16*) symbol);
    gui_strcat(Buffer, (UI_string_type) " ");
    gui_strcat(Buffer, (UI_string_type) value);
    string_width = gui_get_string_width(Buffer);
    string_height = gui_get_character_height();
    ty = main_LCD_dt_object.duration.y;
    MMI_ASSERT(main_LCD_dt_object.duration.hide_function!=NULL);//102506 call cost
    main_LCD_dt_object.duration.hide_function(x, ty, UI_device_width - 1, ty + string_height - 1);      /* call duration hide function */
    tx = UI_device_width - string_width - 2;
    gdi_layer_reset_clip();

    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(tx + string_width, ty);
    }
    else
    {
        gui_move_text_cursor(tx, ty);
    }

    gui_set_text_color(c);
    /* print callcost */
    gui_print_text(Buffer);
    gdi_layer_pop_clip();
    gdi_layer_blt_previous((UI_device_width - 1) >> 1, ty, UI_device_width - 1, ty + string_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  redraw_call_cost_UI
 * DESCRIPTION
 *  update cost value on active call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_call_cost_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_call_cost_UI(UI_call_cost_symbol, UI_call_cost_value);
}

/* code ended vandana mehtani */

/* Theme data for formatted input objects. Should be obtained from theme resource   */
/* date time input box background color scheme */
UI_filled_area date_time_input_background_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* date time input box field color scheme */
UI_filled_area date_time_input_field_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

UI_single_line_input_box_theme date_time_input_theme = { &date_time_input_field_filler,
    &date_time_input_field_filler,
    &date_time_input_field_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &UI_DEFAULT_FONT,
    0,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};


/*****************************************************************************
 * FUNCTION
 *  max_num_of_days
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y       [IN]        
 *  m       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 max_num_of_days(S32 y, S32 m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        return 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    else    /* Feb */
    {
        U8 isLeap = 0;

        if (y % 400 == 0)
        {
            isLeap = 1;
        }
        else if (y % 100 == 0)
        {
            isLeap = 0;
        }
        else if (y % 4 == 0)
        {
            isLeap = 1;
        }
        else
        {
            isLeap = 0;
        }

        return 28 + isLeap;
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
 * CODE Start For SLIM: General APIs for All Inputs
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  general_input_show_background
 * DESCRIPTION
 *  Background display API of input. 
 * PARAMETERS
 *  input
 * RETURNS
 *  void
 *****************************************************************************/
static general_input_show_background(general_input *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    if (input->flags & GENERAL_INPUT_USE_RESET_CLIP)
    {
        gui_set_clip_preset(
            input->x,
            input->y,
            input->x + input->width - 1,
            input->y + input->height - 1);
    }
    else
    {
        gdi_layer_set_clip(
            input->x,
            input->y,
            input->x + input->width - 1,
            input->y + input->height - 1);
    }

    if (input->hide_callback!= NULL)
    {
        /* app set image as date input component's background */
        input->hide_callback(
            input->x,
            input->y,
            input->x + input->width - 1,
            input->y + input->height - 1);
    }
    else
    {
        x1 = input->x;
        y1 = input->y;
        x2 = x1 + input->width - 1;
        y2 = y1 + input->height - 1;
        /* the default background  */
        gui_draw_filled_area(x1, y1, x2, y2, &date_time_input_background_filler);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  general_input_init
 * DESCRIPTION
 *  Init input. 
 * PARAMETERS
 *  input
 * RETURNS
 *  void
 *****************************************************************************/
static general_input_init(
        general_input *input,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input->x = x;
    input->y = y;
    input->width = width;
    input->height = height;
    input->flags = flags;
    input->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  genreal_input_box_reset_flags
 * DESCRIPTION
 *  reset flag of input box
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void genreal_input_box_reset_flags(single_line_input_box *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    input->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    input->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  genreal_input_box_set_focus_flags
 * DESCRIPTION
 *  reset flag of input box
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void genreal_input_box_set_focus_flags(single_line_input_box *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_NORMAL;
    input->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
    input->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  genreal_input_box_show_separator
 * DESCRIPTION
 *  Diaplay the separator of input box
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void genreal_input_box_show_separator(
             general_input *input,
             UI_font_type f,
             color c,
             UI_character_type seperator1,
             UI_character_type seperator2,
             UI_character_type seperator3,
             S32 sx1,
             S32 sy1,
             S32 sx2,
             S32 sy2,
             S32 sx3,
             S32 sy3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input->flags & GENERAL_INPUT_USE_RESET_CLIP)
    {
        gui_push_clip();
        gui_set_clip_preset(
            input->x,
            input->y,
            input->x + input->width - 1,
            input->y + input->height - 1);
    }
    else
    {
        gdi_layer_reset_clip();
    }

    gui_set_font(f);
    gui_set_text_color(c);

    if (seperator1 != 0)
    {
        if (mmi_fe_get_r2l_state())
        {
            sw = gui_get_character_width(seperator1);
            gui_move_text_cursor(sx1 + sw - 1, sy1);
        }
        else
        {
            gui_move_text_cursor(sx1, sy1);
        }
        gui_print_character(seperator1);
    }
    if (seperator2 != 0)
    {
        if (mmi_fe_get_r2l_state())
        {
            sw = gui_get_character_width(seperator2);
            gui_move_text_cursor(sx2 + sw - 1, sy2);
        }
        else
        {
            gui_move_text_cursor(sx2, sy1);
        }
        gui_print_character(seperator2);
    }
    if (seperator3 != 0)
    {
        if (mmi_fe_get_r2l_state())
        {
            sw = gui_get_character_width(seperator3);
            gui_move_text_cursor(sx3 + sw - 1, sy3);
        }
        else
        {
            gui_move_text_cursor(sx3, sy3);
        }
        gui_print_character(seperator3);
    }

    if (input->flags & GENERAL_INPUT_USE_RESET_CLIP)
    {
        gui_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_set_prev_next_focus
 * DESCRIPTION
 *  set focus to prev or next box of general input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  byte
 *****************************************************************************/
static U8 general_input_set_prev_next_focus(
           MMI_BOOL is_prev,
           void *d,
           single_line_input_box **focus_input_box,
           U32 *focus_list,
           U32 *current_focus,    
           general_input_func_ptr input_reset_focus,
           general_input_func_ptr input_set_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_focus = *current_focus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_prev)
    {
        temp_focus--;
    }
    else
    {
        temp_focus++;
    }
    
    if (focus_list[temp_focus] == GENERAL_INPUT_FOCUS_NONE)
    {
        return (0);
    }
    else
    {
        input_reset_focus(d);
        *current_focus = temp_focus;
        input_set_focus(d);
    #if defined(__MMI_TOUCH_SCREEN__)
        if (MMI_FALSE == is_prev)
        {
            gui_single_line_input_box_goto_first_character(*focus_input_box);
        }
        else
        {
            gui_single_line_input_box_goto_last_character(*focus_input_box);
            gui_single_line_input_box_previous(*focus_input_box);
        }
    #endif /* __MMI_TOUCH_SCREEN__ */
        return (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_box_set_seperator_pos
 * DESCRIPTION
 *  Calculate the pos of separaotr
 * PARAMETERS
 *  box1        [IN]
 *  box2        [IN]
 *  text_width  [IN]
 *  text_height [IN]
 *  separator_x [IN]
 *  separator_y [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_box_set_seperator_pos(
             single_line_input_box *box1,
             single_line_input_box *box2,
             S32 text_width,
             S32 text_height,
             S32 *separator_x,
             S32 *separaotr_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *separaotr_y = (box1->height >> 1) - (text_height >> 1);
    x1 = box1->x + box1->width - 1;
    x2 = box2->x;
    *separator_x = x1 + ((x2 - x1) >> 1) - (text_width >> 1);
}


/*****************************************************************************
 * FUNCTION
 *  general_input_box_direct_input
 * DESCRIPTION
 *  insert the character in date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL general_input_box_direct_input(
                 UI_character_type c,
                 void *current_input,
                 single_line_input_box **focus_input_box,
                 U8 (*input_box_set_next_focus)(void *current_input))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_test_last_position_overflow(*focus_input_box))
    {
        if (input_box_set_next_focus(current_input))
        {
            result = gui_single_line_input_box_insert_character(*focus_input_box, c);
        }
    }
    else
    {
        result = gui_single_line_input_box_insert_character(*focus_input_box, c);
        if (gui_single_line_input_box_test_last_position_overflow(*focus_input_box))
        {
            if (!input_box_set_next_focus(current_input))
            {
                gui_single_line_input_box_previous(*focus_input_box);
            }
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  general_input_box_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  tp                  [?]         
 *  time_input(?)       [IN]        *t
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 general_input_box_test_last_position(
            U32 current_focus,
            U32 *focus_list,
            single_line_input_box *focus_input_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (focus_list[current_focus + 1] != GENERAL_INPUT_FOCUS_NONE)
    {
        return 0;
    }
    else
    {
        if (gui_single_line_input_box_test_last_character_position(focus_input_box))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_direct_input
 * DESCRIPTION
 *  insert the character in date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_box_delete_character(
                void *current_input,
                single_line_input_box *focus_input_box,
                U8 (*input_box_set_previous_focus)(void *current_input))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_test_first_position(focus_input_box))
    {
        input_box_set_previous_focus(current_input);
    }
    else
    {
        gui_single_line_input_box_delete_character(focus_input_box);
        if (gui_single_line_input_box_test_first_position(focus_input_box))
        {
            input_box_set_previous_focus(current_input);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_box_previous_character
 * DESCRIPTION
 *  insert the character in date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_box_previous_character(
                void *current_input,
                single_line_input_box **focus_input_box,
                U8 (*input_box_set_previous_focus)(void *current_input))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_test_first_position(*focus_input_box))
    {
        if (input_box_set_previous_focus(current_input))
        {
            gui_single_line_input_box_goto_last_character(*focus_input_box);
            gui_single_line_input_box_previous(*focus_input_box);
        }
    }
    else
    {
        gui_single_line_input_box_previous(*focus_input_box);
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_box_first_character
 * DESCRIPTION
 *  insert the character in date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_box_first_character(
                void *current_input,
                single_line_input_box **focus_input_box,
                U8 (*input_box_set_previous_focus)(void *current_input))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* goto first single line */
    while (input_box_set_previous_focus(current_input));

    /* goto first character of the first single line */
    while (!gui_single_line_input_box_test_first_position(*focus_input_box))
    {
        gui_single_line_input_box_previous(*focus_input_box);
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_box_next_character
 * DESCRIPTION
 *  insert the character in date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_box_next_character(
                void *current_input,
                single_line_input_box *focus_input_box,
                U8 (*input_box_set_next_focus)(void *current_input))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_test_last_character_position(focus_input_box))
    {
        input_box_set_next_focus(current_input);
    }
    else
    {
        gui_single_line_input_box_next(focus_input_box);
    }
}


/*****************************************************************************
 * FUNCTION
 *  general_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle numeric key input of general input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_numeric_keyboard_input_handler(
             S32 keyc,
             void (*general_input_direct_input)(UI_character_type c),
             void (*general_input_delete_character)(void),
             void (*general_input_delete_all_characters)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        general_input_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        general_input_delete_character();
    }
    else if (keyc == 0x1b)
    {
        general_input_delete_all_characters();
    }
    /* else if (keyc == 0x0d); */
}


/*****************************************************************************
 * FUNCTION
 *  general_input_key_handler
 * DESCRIPTION
 *  register key handlers of input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_key_handler(
             S32 vkey_code,
             S32 key_state,
             void (*general_input_previous_character)(void),
             void (*general_input_next_character)(void),
             void (*general_input_toggle_insert_mode)(void),
             void (*general_input_delete_current_character)(void))
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                general_input_previous_character();
                break;
            case 38:    /* up */
                break;
            case 39:
                general_input_next_character();
                break;
            case 40:    /* down */
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                general_input_toggle_insert_mode();
                break;
            case 46:
                general_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  general_input_register_keys
 * DESCRIPTION
 *  register input box key handlers
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_register_keys(
             void (*general_input_handle_key_down)(MMI_key_code_type k),
             void (*general_input_numeric_keyboard_input_handler)(S32 keyc),
             void (*general_input_previous_character)(void),
             void (*general_input_next_character)(void),
             void (*general_input_key_handler)(S32 vkey_code, S32 key_state))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_down_handler(general_input_handle_key_down);
    register_keyboard_input_handler(general_input_numeric_keyboard_input_handler);
    SetKeyHandler(general_input_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(general_input_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(general_input_previous_character, KEY_LEFT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(general_input_next_character, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(general_input_previous_character, KEY_LEFT_ARROW, KEY_REPEAT);
    SetKeyHandler(general_input_next_character, KEY_RIGHT_ARROW, KEY_REPEAT);
    register_keyboard_key_handler(general_input_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  general_input_register_keys
 * DESCRIPTION
 *  clear all key handlers of date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void general_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
    clear_key_down_handler();
    clear_keyboard_input_handler();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
}

/*****************************************************************************
 * Date Input
 *****************************************************************************/
/* Default Date validation functions   */




/*****************************************************************************
 * FUNCTION
 *  set_inline_date_boundary
 * DESCRIPTION
 *  to set date setting boundary
 * PARAMETERS
 *  date_year_max       [IN]        
 *  date_year_min       [IN]        
 *  date_month_max      [IN]        
 *  date_month_min      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_inline_date_boundary(
      S32 date_year_max,
      S32 date_year_min,
      S32 date_month_max,
      S32 date_month_min)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_date_year_max = date_year_max;
    g_date_year_min = date_year_min;
    g_date_month_max = date_month_max;
    g_date_month_min = date_month_min;
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_date_day_validation
 * DESCRIPTION
 *  validation function of day input of inline editing
 * PARAMETERS
 *  text            [IN]        Text
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_date_day_validation(
      UI_buffer_type text,
      UI_buffer_type cursor,
      S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);
    S32 l = gui_strlen((UI_string_type) text);
    S32 y = gui_atoi((UI_string_type) current_date_input->year_input_box.text);
    S32 m = gui_atoi((UI_string_type) current_date_input->month_input_box.text);
    U8 d = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d = max_num_of_days(y, m);

    if ((i < 1) && (l > 1))
    {
        i = 1;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    else if (i > d)
    {
        i = d;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_date_month_validation
 * DESCRIPTION
 *  validation function of month input of inline editing
 * PARAMETERS
 *  text            [IN]        Text
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_date_month_validation(
      UI_buffer_type text,
      UI_buffer_type cursor,
      S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);
    S32 l = gui_strlen((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < g_date_month_min) && (l > 1))
    {
        i = g_date_month_min;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    else if (i > g_date_month_max)
    {
        i = g_date_month_max;
        gui_sprintf((UI_string_type) text, "%02d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    
    default_inline_date_day_validation(
        current_date_input->day_input_box.text,
        current_date_input->day_input_box.current_text_p,
        (current_date_input->day_input_box.text_length >> 1) - 1);
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_date_year_validation
 * DESCRIPTION
 *  validation function of year input of inline editing
 * PARAMETERS
 *  text            [IN]        Text
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_date_year_validation(
      UI_buffer_type text,
      UI_buffer_type cursor,
      S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);
    S32 l = gui_strlen((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < g_date_year_min) && (l > 3))
    {
        i = g_date_year_min;
        gui_sprintf((UI_string_type) text, "%04d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }
    else if (i > g_date_year_max)
    {
        i = g_date_year_max;
        gui_sprintf((UI_string_type) text, "%04d", i);
        /* Play error tone here */
        UI_editor_play_tone_invalid_data();
    }    

    default_inline_date_month_validation(
        current_date_input->month_input_box.text,
        current_date_input->month_input_box.current_text_p,
        (current_date_input->month_input_box.text_length >> 1) - 1);
    default_inline_date_day_validation(
        current_date_input->day_input_box.text,
        current_date_input->day_input_box.current_text_p,
        (current_date_input->day_input_box.text_length >> 1) - 1);
}

/*****************************************************************************
 * FUNCTION
 *  create_date_input
 * DESCRIPTION
 *  create date input box
 * PARAMETERS
 *  d                   [IN]        Date input box
 *  x                   [IN]        Start x position of date input box
 *  y                   [IN]        Styart y position of date input box
 *  width               [IN]        Width of date iput box
 *  height              [IN]        Height of date input box
 *  flags               [IN]        
 *  day_buffer          [IN]        Store day value
 *  month_buffer        [IN]        Store month value
 *  year_buffer         [IN]        Store year value
 * RETURNS
 *  void
 *****************************************************************************/
void create_date_input(
        date_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type day_buffer,
        UI_buffer_type month_buffer,
        UI_buffer_type year_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, w2, w3, h, ox, oy, sw, tw, l, w, sh;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_init(&(d->input), x, y, width, height, flags);
    
    gui_set_font(date_time_input_theme.text_font);
    w= gui_get_character_width((UI_character_type)'0');
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    w1 = 2 * w + 8; /* DATE_INPUT_DAY_WIDTH; */
    w2 = 2 * w + 8; /* DATE_INPUT_MONTH_WIDTH; */
    w3 = 4 * w + 8; /*DATE_INPUT_YEAR_WIDTH; */
#else
	w1 = 2 * w + 10; /* DATE_INPUT_DAY_WIDTH; */
    w2 = 2 * w + 10; /* DATE_INPUT_MONTH_WIDTH; */
    w3 = 4 * w + 10; /*DATE_INPUT_YEAR_WIDTH; */
#endif
    sw = DATE_INPUT_SEPERATOR_WIDTH;

#ifdef  __OP01_FWPBW__
    if ((flags & DATE_INPUT_TYPE_MASK) == DATE_INPUT_TYPE_YYYY)
    {
        tw = w3;
    }
    else
#endif  // __OP01_FWPBW__
    {
        tw = w1 + sw + w2 + sw + w3;
    }

    /* START VIJAY PMT 20060111...as menuitem height is one pixel less for this LCD size */
#if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__ && defined __MMI_MAINLCD_128X64__
    if (IsInlineItemDefaultTextEnable())
    {
        h =  gui_get_character_height() + 1;
        h = (h < DATE_INPUT_HEIGHT - 1) ? DATE_INPUT_HEIGHT - 1 : h;
    }
    else
#endif /* defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__ */ 
        /* END VIJAY PMT 20060111 */
    {
#if defined(__MMI_MAINLCD_240X400__)
        h = gui_get_character_height() + 3;
#elif defined(__MMI_MAINLCD_240X320__)
		h = gui_get_character_height() + 5;
#elif defined(__MMI_MAINLCD_320X480__)
        h = gui_get_character_height() + 7;
#else
        h =  gui_get_character_height() + 1;
#endif
        h = (h < DATE_INPUT_HEIGHT) ? DATE_INPUT_HEIGHT : h;
    }

    oy = (height >> 1) - (h >> 1);
#if defined(__MMI_MAINLCD_128X128__)
	if (oy <= 0)
	{
		oy = 1; /* 1 is frame line width of date input */
	}
#endif /* (__MMI_MAINLCD_128X128__) */
    switch (flags & DATE_INPUT_JUSTIFY_MASK)
    {
        case DATE_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw);
            break;

        case DATE_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;

        default:
        {
        #if defined(__MMI_FTE_SUPPORT__) 
            ox = GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY;
        #else
            ox = 0;
        #endif
            break;
        }
    }

    /* 20051012 HIMANSHU START INLINE DATE */
    /* Inline item type Date must be left align in normal case and it must be right
       align in case of r2lMMIFlag is ON, when the default text effect is enabled */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        if (mmi_fe_get_r2l_state())
        {
            ox = width - ox - tw - 1;
        }
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
    /* 20051012 HIMANSHU END INLINE DATE */

    d->focus_list[0] = DATE_INPUT_FOCUS_NONE;
    d->focus_list[4] = DATE_INPUT_FOCUS_NONE;
    switch (flags & DATE_INPUT_TYPE_MASK)
    {
        case DATE_INPUT_TYPE_DD_MM_YYYY:
            d->focus_list[1] = DATE_INPUT_FOCUS_DAY;
            d->focus_list[2] = DATE_INPUT_FOCUS_MONTH;
            d->focus_list[3] = DATE_INPUT_FOCUS_YEAR;
            d->day_x = ox;
            ox += w1 + sw;
            d->month_x = ox;
            ox += w2 + sw;
            d->year_x = ox;
            d->input.flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_DAY;
            break;
        case DATE_INPUT_TYPE_MM_DD_YYYY:
            d->focus_list[1] = DATE_INPUT_FOCUS_MONTH;
            d->focus_list[2] = DATE_INPUT_FOCUS_DAY;
            d->focus_list[3] = DATE_INPUT_FOCUS_YEAR;
            d->month_x = ox;
            ox += w2 + sw;
            d->day_x = ox;
            ox += w1 + sw;
            d->year_x = ox;
            d->input.flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_MONTH;
            break;
        case DATE_INPUT_TYPE_YYYY_MM_DD:
            d->focus_list[1] = DATE_INPUT_FOCUS_YEAR;
            d->focus_list[2] = DATE_INPUT_FOCUS_MONTH;
            d->focus_list[3] = DATE_INPUT_FOCUS_DAY;
            d->year_x = ox;
            ox += w3 + sw;
            d->month_x = ox;
            ox += w2 + sw;
            d->day_x = ox;
            d->input.flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR;
            break;
#ifdef  __OP01_FWPBW__
        case DATE_INPUT_TYPE_YYYY:
            d->focus_list[1] = DATE_INPUT_FOCUS_YEAR;
            d->focus_list[2] = DATE_INPUT_FOCUS_NONE;
            d->year_x = ox;
            d->input.flags |= DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR;
            break;
#endif  // __OP01_FWPBW__
    }
    current_single_line_input_box_theme = &date_time_input_theme;
    d->day_y = oy;
    d->month_y = oy;
    d->year_y = oy;
    gui_measure_character(d->seperator, &sw, &sh);
    d->s1_y = oy + (h >> 1) - (sh >> 1);
    d->s2_y = d->s1_y;
#ifndef __MMI_MAINLCD_96X64__
#if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__
    if (!IsInlineItemDefaultTextEnable())
    {
#endif /* defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__ */ 
        if ((h + 2) > height)
        {
            h = height - 2;
        }
    #if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__
    }
#endif 
#endif
    l = gui_strlen((UI_string_type) day_buffer) /* +1 */ ;
    /* craete single inputbox of day */
    gui_create_single_line_input_box_set_buffer(
        &d->day_input_box,
        x + d->day_x,
        y + d->day_y,
        w1,
        h,
        (UI_string_type) day_buffer,
        DATE_INPUT_DAY_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->day_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->day_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->day_input_box);
    l = gui_strlen((UI_string_type) month_buffer) /* +1 */ ;
    /* craete single inputbox of month  */
    gui_create_single_line_input_box_set_buffer(
        &d->month_input_box,
        x + d->month_x,
        y + d->month_y,
        w2,
        h,
        (UI_string_type) month_buffer,
        DATE_INPUT_MONTH_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->month_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->month_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->month_input_box);
    l = gui_strlen((UI_string_type) year_buffer) /* +1 */ ;
    /* craete single inputbox of year */
    gui_create_single_line_input_box_set_buffer(
        &d->year_input_box,
        x + d->year_x,
        y + d->year_y,
        w3,
        h,
        (UI_string_type) year_buffer,
        DATE_INPUT_YEAR_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    /* MTK end */
    d->year_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->year_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->year_input_box);
    date_input_reset_focus((void *)d);
    date_input_set_default_focus(d);
    date_input_set_focus((void *)d);
    /* set theme of input box */
    current_single_line_input_box_theme = t;

    /* Setup default validation functions  */
    d->day_input_box.validation_callback = default_inline_date_day_validation;  /* set function pointer of validation of day input */
    d->month_input_box.validation_callback = default_inline_date_month_validation;      /* set function pointer of validation of month input */
    d->year_input_box.validation_callback = default_inline_date_year_validation;        /* set function pointer of validation of year input */
}


/* Date input object */



/*****************************************************************************
 * FUNCTION
 *  date_input_show_background
 * DESCRIPTION
 *  show the background color of date input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_show_background(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_show_background(&(d->input));
}


/*****************************************************************************
 * FUNCTION
 *  date_input_reset_focus
 * DESCRIPTION
 *  reset focus of date input box to noram state
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_reset_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    date_input *d = (date_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    genreal_input_box_reset_flags(&(d->day_input_box));
    genreal_input_box_reset_flags(&(d->month_input_box));
    genreal_input_box_reset_flags(&(d->year_input_box));
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_focus
 * DESCRIPTION
 *  reset focus of date input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *input_box = NULL;
    date_input *d = (date_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 3))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case DATE_INPUT_FOCUS_DAY:
            input_box = &d->day_input_box;
            break;
        case DATE_INPUT_FOCUS_MONTH:
            input_box = &d->month_input_box;
            break;
        case DATE_INPUT_FOCUS_YEAR:
            input_box = &d->year_input_box;
            break;
    }
    if (input_box != NULL)
    {
        genreal_input_box_set_focus_flags(input_box);
        d->focus_input_box = input_box;
    }
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_next_focus
 * DESCRIPTION
 *  set the fous to next box of date input box
 * PARAMETERS
 *  d       [IN]        Date input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 date_input_set_next_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    date_input *d = (date_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_FALSE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               date_input_reset_focus,
               date_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_previous_focus
 * DESCRIPTION
 *  set the focus to previous box oof date input box
 * PARAMETERS
 *  d       [IN]        Date input box
 * RETURNS
 *  byte
 *****************************************************************************/
static U8 date_input_set_previous_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    date_input *d = (date_input*)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_TRUE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               date_input_reset_focus,
               date_input_set_focus);

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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
/* under construction !*/
#endif
}

/*****************************************************************************
 * FUNCTION
 *  date_input_set_default_focus
 * DESCRIPTION
 *  set the defualt focus of date input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_default_focus(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 focus = DATE_INPUT_FOCUS_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->input.flags & DATE_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case DATE_INPUT_TYPE_DEFAULT_FOCUS_DAY:
             focus = DATE_INPUT_FOCUS_DAY;
            break;
        case DATE_INPUT_TYPE_DEFAULT_FOCUS_MONTH:
             focus = DATE_INPUT_FOCUS_MONTH;
            break;
        case DATE_INPUT_TYPE_DEFAULT_FOCUS_YEAR:
             focus = DATE_INPUT_FOCUS_YEAR;
            break;
    }
    
    if (focus != DATE_INPUT_FOCUS_NONE)
    {
        for (i = 0; i < 5; i++)
        {
            if (d->focus_list[i] == focus)
            {
                d->current_focus = i;
            }
}
    }
}


/*****************************************************************************
 * FUNCTION
 *  show_date_input
 * DESCRIPTION
 *  shaow date input box
 * PARAMETERS
 *  d       [IN]        Date input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_date_input(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_single_line_input_box_theme = &date_time_input_theme;
    gui_set_single_line_input_box_current_theme(&d->day_input_box);
    gui_set_single_line_input_box_current_theme(&d->month_input_box);
    gui_set_single_line_input_box_current_theme(&d->year_input_box);
    date_input_show_background(d);
    if (d->input.flags & DATE_INPUT_USE_PRESET_CLIP)
    {
        d->year_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->month_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->day_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
    }

    if ((d->input.flags & DATE_INPUT_TYPE_MASK) != DATE_INPUT_TYPE_YYYY)
    {
        /* show day input box */
        gui_show_single_line_input_box(&d->day_input_box);
        /* show month input box */
        gui_show_single_line_input_box(&d->month_input_box);
    }
    /* show day year box */
    gui_show_single_line_input_box(&d->year_input_box);

    if ((d->input.flags & DATE_INPUT_TYPE_MASK) != DATE_INPUT_TYPE_YYYY)
    {
        genreal_input_box_show_separator(
            &(d->input),
            d->day_input_box.text_font,
            d->day_input_box.normal_text_color,
            d->seperator,
            d->seperator,
            0,
            d->s1_x,
            d->s1_y + d->input.y,
            d->s2_x,
            d->s2_y + d->input.y,
            0,
            0);
    }
    gdi_layer_blt_previous(
        d->input.x,
        d->input.y,
        d->input.x + d->input.width - 1,
        d->input.y + d->input.height - 1);
    current_single_line_input_box_theme = t;
}


#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  date_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  d       [IN]        Date input box S32 x S32 y
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_move_to_x_y(date_input *d, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, d->input.x, d->input.y, d->input.width, d->input.height))
    {
        if (PEN_CHECK_BOUND
            (x, y, d->day_input_box.x, d->day_input_box.y, d->day_input_box.width, d->day_input_box.height))
        {
            if (d->input.flags & DATE_INPUT_TYPE_MASK != DATE_INPUT_TYPE_YYYY)
            {
                gui_single_line_input_box_goto_first_character(d->focus_input_box);
                date_input_reset_focus((void *)d);
                for (;; i++)
                {
                    if (d->focus_list[i] == DATE_INPUT_FOCUS_DAY)
                    {
                        d->current_focus = i;
                        break;
                    }
                }
                date_input_set_focus((void *)d);
            }
        }
        else if (PEN_CHECK_BOUND
                 (x, y, d->month_input_box.x, d->month_input_box.y, d->month_input_box.width,
                  d->month_input_box.height))
        {
            if (d->input.flags & DATE_INPUT_TYPE_MASK != DATE_INPUT_TYPE_YYYY)
            {
                gui_single_line_input_box_goto_first_character(d->focus_input_box);
                date_input_reset_focus((void *)d);
                for (;; i++)
                {
                    if (d->focus_list[i] == DATE_INPUT_FOCUS_MONTH)
                    {
                        d->current_focus = i;
                        break;
                    }
                }
                date_input_set_focus((void *)d);
            }
        }
        else if (PEN_CHECK_BOUND
                 (x, y, d->year_input_box.x, d->year_input_box.y, d->year_input_box.width, d->year_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(d->focus_input_box);
            date_input_reset_focus((void *)d);
            for (;; i++)
            {
                if (d->focus_list[i] == DATE_INPUT_FOCUS_YEAR)
                {
                    d->current_focus = i;
                    break;
                }
            }
            date_input_set_focus((void *)d);
        }
        else
        {
            return;
        }
        gui_show_single_line_input_box_ext(d->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(d->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(d->focus_input_box);
            gui_single_line_input_box_previous(d->focus_input_box);
        }
        show_date_input(d);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  date_input_set_seperator
 * DESCRIPTION
 *  set the mask of date input box
 * PARAMETERS
 *  d               [IN]        Date input box
 *  seperator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_seperator(date_input *d, UI_character_type seperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;
    single_line_input_box *box1 = NULL;
    single_line_input_box *box2 = NULL;
    single_line_input_box *box3 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator = seperator;
    gui_set_font(d->day_input_box.text_font);
	gui_measure_character(d->seperator, &sw, &sh);
    switch (d->input.flags & DATE_INPUT_TYPE_MASK)
    {
        case DATE_INPUT_TYPE_DD_MM_YYYY:
            box1 = &(d->day_input_box);
            box2 = &(d->month_input_box);
            box3 = &(d->year_input_box);
            break;

        case DATE_INPUT_TYPE_MM_DD_YYYY:
            box1 = &(d->month_input_box);
            box2 = &(d->day_input_box);
            box3 = &(d->year_input_box);
            break;

        case DATE_INPUT_TYPE_YYYY_MM_DD:
            box1 = &(d->year_input_box);
            box2 = &(d->month_input_box);
            box3 = &(d->day_input_box);
            break;
    }

    if (box1 != NULL)
    {
        general_input_box_set_seperator_pos(
            box1,
            box2,
            sw,
            sh,
            &d->s1_x,
            &d->s1_y);
        general_input_box_set_seperator_pos(
            box2,
            box3,
            sw,
            sh,
            &d->s2_x,
            &d->s2_y);
    }
      
    d->s1_y += d->day_input_box.y - d->input.y;
	d->s2_y = d->s1_y;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_set_hide_function
 * DESCRIPTION
 *  set the hide callback function of date input box
 * PARAMETERS
 *  d               [IN]        Date input box
 *  f                [IN]        hide callback funtion
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_set_hide_function(date_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(d != NULL);

    d->input.hide_callback = f;
}


/* store the value of current date input */

date_input *current_date_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_date_input_callback
Description:      a function pointer of current date input callback
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*current_date_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_date_input
 * DESCRIPTION
 *  set current date input to global variable
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_date_input(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_date_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_direct_input
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }
    general_input_box_direct_input(
        c,
        (void *)current_date_input,
        &(current_date_input->focus_input_box),
        date_input_set_next_focus);
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
    /* show date input box */
    show_date_input(current_date_input);
    /* call daet input validation function */
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL date_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return MMI_FALSE;
    }

    result = general_input_box_direct_input(
                 c,
                 (void *)current_date_input,
                 &(current_date_input->focus_input_box),
                 date_input_set_next_focus);
    current_date_input_callback();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  date_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 date_input_test_last_position(date_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_box_test_last_position(
               d->current_focus,
               d->focus_list,
               d->focus_input_box);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_character
 * DESCRIPTION
 *  delete current character of date input box
 * PARAMETERS
 *  void
 *  nonoe(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_delete_character(
        current_date_input,
        current_date_input->focus_input_box,
        date_input_set_previous_focus);
    /* show date input box */
    show_date_input(current_date_input);
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_previous_character
 * DESCRIPTION
 *  set the focus to previous caharacter  of daet input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_previous_character(
        current_date_input,
        &(current_date_input->focus_input_box),
        date_input_set_previous_focus);
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_first_character
 * DESCRIPTION
 *  set the focus to previous caharacter  of daet input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_first_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_first_character(
        current_date_input,
       & (current_date_input->focus_input_box),
        date_input_set_previous_focus);
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_next_character
 * DESCRIPTION
 *  set the focus to next caharacter  of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_next_character(
        current_date_input,
        current_date_input->focus_input_box,
        date_input_set_next_focus);
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_toggle_insert_mode
 * DESCRIPTION
 *  toggle the insert mode of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }
    gui_single_line_input_box_toggle_insert_mode(current_date_input->focus_input_box);
    /* show date input box */
    show_date_input(current_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_character
 * DESCRIPTION
 *  delete the character of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void date_input_delete_character_internal(MMI_BOOL delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_date_input == NULL || current_date_input->focus_input_box == NULL)
    {
        return;
    }

    if (delete_all == MMI_FALSE)
    {
        gui_single_line_input_box_delete_current_character(current_date_input->focus_input_box);
    }
    else
    {
        gui_single_line_input_box_delete_all(current_date_input->focus_input_box);
    }
    /* show date input box */
    show_date_input(current_date_input);
    current_date_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_current_character
 * DESCRIPTION
 *  delete the current character of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_input_delete_character_internal(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_delete_all_characters
 * DESCRIPTION
 *  delete all characters of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_input_delete_character_internal(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle numeric key input of date input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_numeric_keyboard_input_handler(
        keyc,
        date_input_direct_input,
        date_input_delete_character,
        date_input_delete_all_characters);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_handle_key_down
 * DESCRIPTION
 *  handle date input key down
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  date_input_key_handler
 * DESCRIPTION
 *  register the key handler of date input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_key_handler(
        vkey_code,
        key_state,
        date_input_previous_character,
        date_input_next_character,
        date_input_toggle_insert_mode,
        date_input_delete_current_character);
}


/*****************************************************************************
 * FUNCTION
 *  date_input_register_keys
 * DESCRIPTION
 *  register date input box key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_register_keys(
        date_input_handle_key_down,
        date_input_numeric_keyboard_input_handler,
        date_input_previous_character,
        date_input_next_character,
        date_input_key_handler);
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
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  date_input_clear_keys
 * DESCRIPTION
 *  clear all key handlers of date input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void date_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_clear_keys();
}


/*****************************************************************************
 * FUNCTION
 *  register_date_input_callback
 * DESCRIPTION
 *  register date input call back function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void register_date_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_date_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_date_input_callback
 * DESCRIPTION
 *  clear date input callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_date_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_date_input_callback = UI_dummy_function;
}





/*****************************************************************************
 * IP4 Input
 *****************************************************************************/
/* Default IP field validation functions  */


/*****************************************************************************
 * FUNCTION
 *  default_inline_IP_field_validation
 * DESCRIPTION
 *  validaion function of IP4 input box
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_IP_field_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i < 0)
    {
        i = 0;
        gui_sprintf((UI_string_type) text, "%03d", i);
        UI_editor_play_tone_invalid_data();
    }
    else if (i > 255)
    {
        i = 255;
        gui_sprintf((UI_string_type) text, "%03d", i);
        UI_editor_play_tone_invalid_data();
    }
}



/*****************************************************************************
 * FUNCTION
 *  create_IP4_input
 * DESCRIPTION
 *  create Ip4 input box
 * PARAMETERS
 *  d                   [IN]        
 *  x                   [IN]        Start x postion of ip4 input box
 *  y                   [IN]        Start y position of ip4 input box
 *  width               [IN]        Width of ip4 input box
 *  height              [IN]        
 *  flags               [IN]        
 *  b1                  [IN]        Buffer1 of ip4 input box
 *  b2                  [IN]        Buffer 2 of ip4 input box
 *  b3                  [IN]        Buffer 3o f ip4 input box
 *  b4                  [IN]        Buffer 4 of ip4 input box
 *  heighthight(?)      [IN]        Of ip4 input box
 * RETURNS
 *  void
 *****************************************************************************/
void create_IP4_input(
        IP4_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type b1,
        UI_buffer_type b2,
        UI_buffer_type b3,
        UI_buffer_type b4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, ox, oy, sw, tw, l, sh;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_init(&(d->input), x, y, width, height, flags);

    gui_set_font(date_time_input_theme.text_font);
    if (((width >> 2) - 1) < IP4_INPUT_FIELD_WIDTH)
    {
        w = (width >> 2) - 1;
    }
    else
    {
    #if !defined(__MMI_VECTOR_FONT_SUPPORT__)
        w= gui_get_character_width((UI_character_type)'0') * 3 + 6;
    #else
		w= gui_get_character_width((UI_character_type)'0') * 3 + 8;
    #endif
    /* w = IP4_INPUT_FIELD_WIDTH; */
    }
    sw = IP4_INPUT_SEPERATOR_WIDTH;
    tw = w + sw + w + sw + w + sw + w;
    h =  gui_get_character_height() + 1;
    h = (h < IP4_INPUT_HEIGHT) ? IP4_INPUT_HEIGHT : h;
    oy = (height >> 1) - (h >> 1);
    switch (flags & IP4_INPUT_JUSTIFY_MASK)
    {
        case IP4_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw - 2);
            break;
        case IP4_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;
        default:
        {
        #if defined(__MMI_FTE_SUPPORT__) 
            ox = GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY;
        #else
            ox = 2;
        #endif
            break;
        }
    }

    d->focus_list[0] = IP4_INPUT_FOCUS_NONE;
    d->focus_list[5] = IP4_INPUT_FOCUS_NONE;
    d->focus_list[1] = IP4_INPUT_FOCUS_FIELD1;
    d->focus_list[2] = IP4_INPUT_FOCUS_FIELD2;
    d->focus_list[3] = IP4_INPUT_FOCUS_FIELD3;
    d->focus_list[4] = IP4_INPUT_FOCUS_FIELD4;
    d->field1_x = ox;
    ox += w + sw;
    d->field2_x = ox;
    ox += w + sw;
    d->field3_x = ox;
    ox += w + sw;
    d->field4_x = ox;
    ox += w + sw;
    d->input.flags |= IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD1;
    current_single_line_input_box_theme = &date_time_input_theme;
    d->field1_y = oy;
    d->field2_y = oy;
    d->field3_y = oy;
    d->field4_y = oy;
    gui_measure_character(d->seperator, &sw, &sh);
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    d->s1_y = oy + (h >> 1) - (sh >> 1);
#else
	d->s1_y = oy + gui_get_character_height() - 3 - sh;
#endif
    d->s2_y = d->s1_y;
    d->s3_y = d->s1_y;
    if ((h + 2) > height)
    {
        h = height - 2;
    }

    l = gui_strlen((UI_string_type) b1) /* +1 */ ;
    /* craete single inpyut box of field1 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box1,
        x + d->field1_x,
        y + d->field1_y,
        w,
        h,
        (UI_string_type) b1,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box1.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->field_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->field_input_box1);
    l = gui_strlen((UI_string_type) b2) /* +1 */ ;
    /* craete single inpyut box of field2 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box2,
        x + d->field2_x,
        y + d->field2_y,
        w,
        h,
        (UI_string_type) b2,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box2.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->field_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->field_input_box2);
    l = gui_strlen((UI_string_type) b3) /* +1 */ ;
    /* craete single inpyut box of field3 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box3,
        x + d->field3_x,
        y + d->field3_y,
        w,
        h,
        (UI_string_type) b3,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box3.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->field_input_box3.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->field_input_box3);
    l = gui_strlen((UI_string_type) b4) /* +1 */ ;
    /* craete single inpyut box of field4 */
    gui_create_single_line_input_box_set_buffer(
        &d->field_input_box4,
        x + d->field4_x,
        y + d->field4_y,
        w,
        h,
        (UI_string_type) b4,
        IP4_INPUT_FIELD_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->field_input_box4.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->field_input_box4.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->field_input_box4);
    IP4_input_reset_focus((void *)d);
    IP4_input_set_default_focus(d);
    IP4_input_set_focus((void *)d);
    current_single_line_input_box_theme = t;
    /* MTK end */

    /* Setup default validation functions  */
    d->field_input_box1.validation_callback = default_inline_IP_field_validation;
    d->field_input_box2.validation_callback = default_inline_IP_field_validation;
    d->field_input_box3.validation_callback = default_inline_IP_field_validation;
    d->field_input_box4.validation_callback = default_inline_IP_field_validation;
}


/* IP4 input object  */


/*****************************************************************************
 * FUNCTION
 *  IP4_input_show_background
 * DESCRIPTION
 *  show background of Ip4 input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_show_background(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_show_background(&(d->input));
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_reset_focus
 * DESCRIPTION
 *  reset focus of IP4 input box to default
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_reset_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IP4_input *d = (IP4_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    genreal_input_box_reset_flags(&(d->field_input_box1));
    genreal_input_box_reset_flags(&(d->field_input_box2));
    genreal_input_box_reset_flags(&(d->field_input_box3));
    genreal_input_box_reset_flags(&(d->field_input_box4));
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_focus
 * DESCRIPTION
 *  set focus to particaulr field depend on teh value
 *  of current focus
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *input_box = NULL;
    IP4_input *d = (IP4_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 4))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case IP4_INPUT_FOCUS_FIELD1:
            input_box = &d->field_input_box1;
            break;

        case IP4_INPUT_FOCUS_FIELD2:
            input_box = &d->field_input_box2;
            break;

        case IP4_INPUT_FOCUS_FIELD3:
            input_box = &d->field_input_box3;
            break;

        case IP4_INPUT_FOCUS_FIELD4:
            input_box = &d->field_input_box4;
            break;
    }
    if (input_box != NULL)
    {
        genreal_input_box_set_focus_flags(input_box);
        d->focus_input_box = input_box;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_default_focus
 * DESCRIPTION
 *  set focus to default box of IP4
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_default_focus(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U8 focus = IP4_INPUT_FOCUS_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->input.flags & IP4_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD1:
            focus = IP4_INPUT_FOCUS_FIELD1;
            break;

        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD2:
            focus = IP4_INPUT_FOCUS_FIELD2;
            break;

        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD3:
            focus = IP4_INPUT_FOCUS_FIELD3;
            break;

        case IP4_INPUT_TYPE_DEFAULT_FOCUS_FIELD4:
            focus = IP4_INPUT_FOCUS_FIELD4;
            break;
    }

    if (focus != IP4_INPUT_FOCUS_NONE)
    {
        for (i = 0; i < 6; i++)
        {
            if (d->focus_list[i] == focus)
            {
                d->current_focus = i;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_next_focus
 * DESCRIPTION
 *  set focus to next  character
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 IP4_input_set_next_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IP4_input *d = (IP4_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_FALSE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               IP4_input_reset_focus,
               IP4_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_previous_focus
 * DESCRIPTION
 *  set focus to previous character
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 IP4_input_set_previous_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IP4_input *d = (IP4_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_TRUE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               IP4_input_reset_focus,
               IP4_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  show_IP4_input
 * DESCRIPTION
 *  show Ip4 input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_IP4_input(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IP4_input_show_background(d);
    if (d->input.flags & TIME_INPUT_USE_PRESET_CLIP)
    {
        d->field_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->field_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->field_input_box3.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->field_input_box4.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
    }
    /* show single input box  field1 */
    gui_show_single_line_input_box(&d->field_input_box1);
    /* show single input box  field2 */
    gui_show_single_line_input_box(&d->field_input_box2);
    /* show single input box  field3 */
    gui_show_single_line_input_box(&d->field_input_box3);
    /* show single input box  field4 */
    gui_show_single_line_input_box(&d->field_input_box4);

    genreal_input_box_show_separator(
        &(d->input),
        d->field_input_box1.text_font,
        d->field_input_box1.normal_text_color,
        d->seperator,
        d->seperator,
        d->seperator,
        d->s1_x,
        d->s1_y + d->input.y,
        d->s2_x,
        d->s2_y + d->input.y,
        d->s3_x, 
        d->s3_y + d->input.y);

    gdi_layer_blt_previous(
        d->input.x,
        d->input.y,
        d->input.x + d->input.width - 1,
        d->input.y + d->input.height - 1);
}


#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  IP4_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  ip4     [IN]        IP4 input box S32 x S32 y
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_move_to_x_y(IP4_input *ip4, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, ip4->input.x, ip4->input.y, ip4->input.width, ip4->input.height))
    {
        if (PEN_CHECK_BOUND
            (x, y, ip4->field_input_box1.x, ip4->field_input_box1.y, ip4->field_input_box1.width,
             ip4->field_input_box1.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus((void *)ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD1)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus((void *)ip4);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, ip4->field_input_box2.x, ip4->field_input_box2.y, ip4->field_input_box2.width,
                  ip4->field_input_box2.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus((void *)ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD2)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus((void *)ip4);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, ip4->field_input_box3.x, ip4->field_input_box3.y, ip4->field_input_box3.width,
                  ip4->field_input_box3.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus((void *)ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD3)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus((void *)ip4);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, ip4->field_input_box4.x, ip4->field_input_box4.y, ip4->field_input_box4.width,
                  ip4->field_input_box4.height))
        {
            gui_single_line_input_box_goto_first_character(ip4->focus_input_box);
            IP4_input_reset_focus((void *)ip4);
            for (;; i++)
            {
                if (ip4->focus_list[i] == IP4_INPUT_FOCUS_FIELD4)
                {
                    ip4->current_focus = i;
                    break;
                }
            }
            IP4_input_set_focus((void *)ip4);
        }
        else
        {
            /*
             * for(;;i++)
             * {
             * if (ip4->focus_list[i]==IP4_INPUT_FOCUS_NONE)
             * {
             * ip4->current_focus = i-1;
             * break;
             * }
             * }
             * IP4_input_set_focus(ip4);
             */
            return;
        }
        gui_show_single_line_input_box_ext(ip4->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(ip4->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(ip4->focus_input_box);
            gui_single_line_input_box_previous(ip4->focus_input_box);
        }
        show_IP4_input(ip4);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_seperator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  d               [IN]        
 *  seperator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_seperator(IP4_input *d, UI_character_type seperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator = seperator;
    gui_set_font(d->field_input_box1.text_font);
    gui_measure_character(d->seperator, &sw, &sh);

    general_input_box_set_seperator_pos(
        &(d->field_input_box1),
        &(d->field_input_box2),
        sw,
        sh,
        &d->s1_x,
        &d->s1_y);
    general_input_box_set_seperator_pos(
        &(d->field_input_box2),
        &(d->field_input_box3),
        sw,
        sh,
        &d->s2_x,
        &d->s2_y);
    general_input_box_set_seperator_pos(
        &(d->field_input_box3),
        &(d->field_input_box4),
        sw,
        sh,
        &d->s3_x,
        &d->s3_y);

#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    d->s1_y += d->field_input_box1.y - d->input.y;
#else
    d->s1_y = d->field_input_box1.y - d->input.y + gui_get_character_height() - 3 - sh;
#endif
    d->s3_y = d->s2_y = d->s1_y;
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_set_hide_function
 * DESCRIPTION
 *  set the hide callback function of IP4 input box
 * PARAMETERS
 *  d               [IN]        IP4 input box
 *  f                [IN]       hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_set_hide_function(IP4_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(d != NULL);

    d->input.hide_callback = f;
}


/* a global variabel o ftype IP4_input */
IP4_input *current_IP4_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_IP4_input_callback
Description:      a function pointer store the address of function 
               of I4 input callback 
Input Parameters: none
               
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/
void (*current_IP4_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_IP4_input
 * DESCRIPTION
 *  Set the global variable of IP4_input equal to valeu pass as parameter
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_IP4_input(IP4_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_IP4_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_direct_input
 * DESCRIPTION
 *  append the currentinsert character to IP4 text and show the Ip4 text box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_direct_input(
        c,
        (void *)current_IP4_input,
        &(current_IP4_input->focus_input_box),
        IP4_input_set_next_focus);
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
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL IP4_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return MMI_FALSE;
    }

    result = general_input_box_direct_input(
                 c,
                 (void *)current_IP4_input,
                 &(current_IP4_input->focus_input_box),
                 IP4_input_set_next_focus);
    current_IP4_input_callback();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  ip4     [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 IP4_input_test_last_position(IP4_input *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_box_test_last_position(
               ip4->current_focus,
               ip4->focus_list,
               ip4->focus_input_box);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_character
 * DESCRIPTION
 *  delete character of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_delete_character(
        current_IP4_input,
        current_IP4_input->focus_input_box,
        IP4_input_set_previous_focus);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_previous_character
 * DESCRIPTION
 *  set focus to previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_previous_character(
        current_IP4_input,
        &(current_IP4_input->focus_input_box),
        IP4_input_set_previous_focus);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_first_character
 * DESCRIPTION
 *  set focus to previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_first_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_first_character(
        current_IP4_input,
       & (current_IP4_input->focus_input_box),
        IP4_input_set_previous_focus);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_next_character
 * DESCRIPTION
 *  set focus to next caharacter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_next_character(
        current_IP4_input,
        current_IP4_input->focus_input_box,
        IP4_input_set_next_focus);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_toggle_insert_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }
    gui_single_line_input_box_toggle_insert_mode(current_IP4_input->focus_input_box);
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_current_character
 * DESCRIPTION
 *  delete charactert of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IP4_input_delete_character_internal(MMI_BOOL delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_IP4_input == NULL || current_IP4_input->focus_input_box == NULL)
    {
        return;
    }

    if (delete_all == MMI_FALSE)
    {
        gui_single_line_input_box_delete_current_character(current_IP4_input->focus_input_box);
    }
    else
    {
        gui_single_line_input_box_delete_all(current_IP4_input->focus_input_box);
    }
    /* show IP4 input box */
    show_IP4_input(current_IP4_input);
    current_IP4_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_current_character
 * DESCRIPTION
 *  delete current charactert of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IP4_input_delete_character_internal(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_delete_all_characters
 * DESCRIPTION
 *  delete all characterts of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IP4_input_delete_character_internal(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle numeric key input of IP4 input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_numeric_keyboard_input_handler(
        keyc,
        IP4_input_direct_input,
        IP4_input_delete_character,
        IP4_input_delete_all_characters);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_handle_key_down
 * DESCRIPTION
 *  funtion handle key down event of IP4 input box
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IP4_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_key_handler
 * DESCRIPTION
 *  regsiter key handlers of IP4 input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_key_handler(
        vkey_code,
        key_state,
        IP4_input_previous_character,
        IP4_input_next_character,
        IP4_input_toggle_insert_mode,
        IP4_input_delete_current_character);
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_register_keys
 * DESCRIPTION
 *  regsiter key handlers of IP4 input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_register_keys(
        IP4_input_handle_key_down,
        IP4_input_numeric_keyboard_input_handler,
        IP4_input_previous_character,
        IP4_input_next_character,
        IP4_input_key_handler);
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
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  IP4_input_clear_keys
 * DESCRIPTION
 *  clear all key events of IP4 input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IP4_input_clear_keys(void)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_clear_keys();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  register_IP4_input_callback
 * DESCRIPTION
 *  registe IP4 input callback function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void register_IP4_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_IP4_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_IP4_input_callback
 * DESCRIPTION
 *  clear ip4 input callback to dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_IP4_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_IP4_input_callback = UI_dummy_function;
}


/*****************************************************************************
 * Time Input
 *****************************************************************************/
/* Default Time validation functions   */


/*****************************************************************************
 * FUNCTION
 *  default_inline_time_minutes_validation
 * DESCRIPTION
 *  deafult function of time mnutes validation
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_time_minutes_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i < 0)
    {
        i = 0;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
    else if (i > 59)
    {
        i = 59;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  default_inline_time_hours_validation
 * DESCRIPTION
 *  deafult function of time hours validation
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void default_inline_time_hours_validation(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = gui_atoi((UI_string_type) text);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i < 0)
    {
        i = 0;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }
    else if (i > 23)
    {
        i = 23;
        gui_sprintf((UI_string_type) text, "%02d", i);
        UI_editor_play_tone_invalid_data();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  create_time_input
 * DESCRIPTION
 *  create time input box
 * PARAMETERS
 *  d                   [IN]        Time input box
 *  x                   [IN]        Start x position of time input box
 *  y                   [IN]        Strat y position of time input box
 *  width               [IN]        Width of time input box
 *  height              [IN]        Height of time input box
 *  flags               [IN]        
 *  hours_buffer        [IN]        Hours buffer
 *  minutes_buffer      [IN]        Minutes buffer
 *  seconds_buffer      [IN]        Seconds buffer
 * RETURNS
 *  void
 *****************************************************************************/
void create_time_input(
        time_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type hours_buffer,
        UI_buffer_type minutes_buffer,
        UI_buffer_type seconds_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, w2, w3, h, ox, oy, sw, tw, l, w, sh;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_init(&(d->input), x, y, width, height, flags);

    gui_set_font(date_time_input_theme.text_font);
    w= gui_get_character_width((UI_character_type)'0');
   /* 
    w1 = TIME_INPUT_HOURS_WIDTH;
    w2 = TIME_INPUT_MINUTES_WIDTH;
    w3 = TIME_INPUT_SECONDS_WIDTH;
   */
    w1 = 2 * w + 8;
    w2 = 2 * w + 8;
    w3 = 2 * w + 8;
    sw = TIME_INPUT_SEPERATOR_WIDTH;

    tw = w1 + sw + w2;
    if ((flags & TIME_INPUT_TYPE_MASK) != TIME_INPUT_TYPE_HH_MM)
    {
        tw += sw + w3;
    }
#if defined(__MMI_MAINLCD_240X400__)
	h = gui_get_character_height() + 3;
#elif defined(__MMI_MAINLCD_240X320__)
    h = gui_get_character_height() + 5;
#elif defined(__MMI_MAINLCD_320X480__)
    h = gui_get_character_height() + 7;
#else
    h =  gui_get_character_height() + 1;
#endif
    h = (h < TIME_INPUT_HEIGHT) ? TIME_INPUT_HEIGHT : h;
    oy = (height >> 1) - (h >> 1);
    switch (flags & TIME_INPUT_JUSTIFY_MASK)
    {
        case TIME_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw);
            break;

        case TIME_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;

        default:
        {
        #if defined(__MMI_FTE_SUPPORT__)
            ox = GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY;
        #else
            ox = 0;
        #endif
            break;
        }
    }

    /* 20051012 HIMANSHU START INLINE TIME */
    /* Inline item type Time must be left align in normal case and it must be right
       align in case of r2lMMIFlag is ON, when the default text effect is enabled */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        if (mmi_fe_get_r2l_state())
        {
            ox = width - ox - tw - 1;
        }
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
    /* 20051012 HIMANSHU END INLINE TIME */

    d->focus_list[0] = TIME_INPUT_FOCUS_NONE;
    d->focus_list[4] = TIME_INPUT_FOCUS_NONE;
    switch (flags & TIME_INPUT_TYPE_MASK)
    {
        case TIME_INPUT_TYPE_HH_MM:
            d->focus_list[1] = TIME_INPUT_FOCUS_HOURS;
            d->focus_list[2] = TIME_INPUT_FOCUS_MINUTES;
            d->focus_list[3] = TIME_INPUT_FOCUS_NONE;
            d->hours_x = ox;
            ox += w1 + sw;
            d->minutes_x = ox;
            d->input.flags |= TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS;
            d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
            break;

        case TIME_INPUT_TYPE_HH_MM_SS:
            d->focus_list[1] = TIME_INPUT_FOCUS_HOURS;
            d->focus_list[2] = TIME_INPUT_FOCUS_MINUTES;
            d->focus_list[3] = TIME_INPUT_FOCUS_SECONDS;
            d->hours_x = ox;
            ox += w1 + sw;
            d->minutes_x = ox;
            ox += w2 + sw;
            d->seconds_x = ox;
            d->input.flags |= TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS;
            break;
    }
    current_single_line_input_box_theme = &date_time_input_theme;
    d->hours_y = oy;
    d->minutes_y = oy;
    d->seconds_y = oy;
    gui_measure_character(d->seperator, &sw, &sh);
    d->s1_y = oy + (h >> 1) - (sh >> 1);
    d->s2_y = d->s1_y;
#if defined __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ && defined __MMI_MAINLCD_128X160__ && defined __MMI_MAINLCD_128X64__
    if (IsInlineItemDefaultTextEnable())
    {
        h = height - 2;
    }
#endif

    /* MTK Terry for Bidi Issue */
    l = gui_strlen((UI_string_type) hours_buffer);
    /* create single input box of hours */
    /* MTK Elvis for R2L characters */
    gui_create_single_line_input_box_set_buffer(
        &d->hours_input_box,
        x + d->hours_x,
        y + d->hours_y,
        w1,
        h,
        (UI_string_type) hours_buffer,
        TIME_INPUT_HOURS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->hours_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->hours_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->hours_input_box);

    l = gui_strlen((UI_string_type) minutes_buffer);
    /* create single input box of minutes */
    /* MTK Elvis for R2L characters */
    gui_create_single_line_input_box_set_buffer(
        &d->minutes_input_box,
        x + d->minutes_x,
        y + d->minutes_y,
        w2,
        h,
        (UI_string_type) minutes_buffer,
        TIME_INPUT_MINUTES_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->minutes_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->minutes_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->minutes_input_box);

    l = gui_strlen((UI_string_type) seconds_buffer);
    /* create single input box of seconds */
    /* MTK Elvis for R2L characters */
    gui_create_single_line_input_box_set_buffer(
        &d->seconds_input_box,
        x + d->seconds_x,
        y + d->seconds_y,
        w3,
        h,
        (UI_string_type) seconds_buffer,
        TIME_INPUT_SECONDS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->seconds_input_box.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->seconds_input_box);
    time_input_reset_focus((void *)d);
    time_input_set_default_focus(d);
    time_input_set_focus((void *)d);
    /* set theme of input box */
    current_single_line_input_box_theme = t;

    /* Setup default validation functions  */
    d->hours_input_box.validation_callback = default_inline_time_hours_validation;
    d->minutes_input_box.validation_callback = default_inline_time_minutes_validation;
    d->seconds_input_box.validation_callback = default_inline_time_minutes_validation;
}


/* Time input object */


/*****************************************************************************
 * FUNCTION
 *  time_input_show_background
 * DESCRIPTION
 *  show time input bkg color
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_show_background(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_show_background(&(d->input));
}


/*****************************************************************************
 * FUNCTION
 *  time_input_reset_focus
 * DESCRIPTION
 *  reset teh foucs of time input
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_reset_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_input *d = (time_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    genreal_input_box_reset_flags(&(d->hours_input_box));
    genreal_input_box_reset_flags(&(d->minutes_input_box));
    genreal_input_box_reset_flags(&(d->seconds_input_box));
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_focus
 * DESCRIPTION
 *  set the focus of time input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *input_box = NULL;
    time_input *d = (time_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 3))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case TIME_INPUT_FOCUS_HOURS:
            input_box = &d->hours_input_box;
            break;

        case TIME_INPUT_FOCUS_MINUTES:
            input_box = &d->minutes_input_box;
            break;

        case TIME_INPUT_FOCUS_SECONDS:
            input_box = &d->seconds_input_box;
            break;
    }
    if (input_box != NULL)
    {
        genreal_input_box_set_focus_flags(input_box);
        d->focus_input_box = input_box;
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_default_focus
 * DESCRIPTION
 *  set the default  focus of time input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_default_focus(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 focus = TIME_INPUT_FOCUS_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->input.flags & TIME_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case TIME_INPUT_TYPE_DEFAULT_FOCUS_HOURS:
            focus = TIME_INPUT_FOCUS_HOURS;
            break;

        case TIME_INPUT_TYPE_DEFAULT_FOCUS_MINUTES:
            focus = TIME_INPUT_FOCUS_MINUTES;
            break;

        case TIME_INPUT_TYPE_DEFAULT_FOCUS_SECONDS:
            focus = TIME_INPUT_FOCUS_SECONDS;
            break;
    }

    if (focus != TIME_INPUT_FOCUS_NONE)
    {
        for (i = 0; i < 5; i++)
        {
            if (d->focus_list[i] == focus)
            {
                d->current_focus = i;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_next_focus
 * DESCRIPTION
 *  set the focus of time input box to next box
 * PARAMETERS
 *  d       [IN]        Time input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_input_set_next_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_input *d = (time_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_FALSE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               time_input_reset_focus,
               time_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_previous_focus
 * DESCRIPTION
 *  set the focus of time input box to previous box
 * PARAMETERS
 *  d       [IN]        Time input box
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_input_set_previous_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_input *d = (time_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_TRUE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               time_input_reset_focus,
               time_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  show_time_input
 * DESCRIPTION
 *  shoe time input box
 * PARAMETERS
 *  d       [IN]        Time input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_time_input(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_single_line_input_box_theme = &date_time_input_theme;
    gui_set_single_line_input_box_current_theme(&d->hours_input_box);
    gui_set_single_line_input_box_current_theme(&d->minutes_input_box);
    time_input_show_background(d);
    if (d->input.flags & TIME_INPUT_USE_PRESET_CLIP)
    {
        d->hours_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->minutes_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->seconds_input_box.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
    }

    /* show hours inout box */
    gui_show_single_line_input_box(&d->hours_input_box);
    /* show minutes input box */
    gui_show_single_line_input_box(&d->minutes_input_box);
    if ((d->input.flags & TIME_INPUT_TYPE_MASK) != TIME_INPUT_TYPE_HH_MM)
    {
        gui_show_single_line_input_box(&d->seconds_input_box);  /* show seconds input box */
        genreal_input_box_show_separator(
            &(d->input),
            d->hours_input_box.text_font,
            d->hours_input_box.normal_text_color,
            d->seperator,
            d->seperator,
            0,
            d->s1_x,
            d->s1_y + d->input.y,
            d->s2_x,
            d->s2_y + d->input.y,
            0, 
            0);
    }
    else
    {
        genreal_input_box_show_separator(
            &(d->input),
            d->hours_input_box.text_font,
            d->hours_input_box.normal_text_color,
            d->seperator,
            0,
            0,
            d->s1_x,
            d->s1_y + d->input.y,
            0,
            0,
            0, 
            0);
    }

    gdi_layer_blt_previous(
        d->input.x,
        d->input.y,
        d->input.x + d->input.width - 1,
        d->input.y + d->input.height - 1);
    current_single_line_input_box_theme = t;
}


#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  time_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  t           [?]         
 *  x           [IN]        
 *  y           [IN]        
 *  tp(?)       [IN]        Time input box S32 x S32 y
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_move_to_x_y(time_input *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, t->input.x, t->input.y, t->input.width, t->input.height))
    {
        if (PEN_CHECK_BOUND
            (x, y, t->hours_input_box.x, t->hours_input_box.y, t->hours_input_box.width, t->hours_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(t->focus_input_box);
            time_input_reset_focus((void *)t);
            for (;; i++)
            {
                if (t->focus_list[i] == TIME_INPUT_FOCUS_HOURS)
                {
                    t->current_focus = i;
                    break;
                }
            }
            time_input_set_focus((void *)t);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, t->minutes_input_box.x, t->minutes_input_box.y, t->minutes_input_box.width,
                  t->minutes_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(t->focus_input_box);
            time_input_reset_focus((void *)t);
            for (;; i++)
            {
                if (t->focus_list[i] == TIME_INPUT_FOCUS_MINUTES)
                {
                    t->current_focus = i;
                    break;
                }
            }
            time_input_set_focus((void *)t);
        }
        else if (((t->input.flags & TIME_INPUT_TYPE_MASK) == TIME_INPUT_TYPE_HH_MM_SS) &&PEN_CHECK_BOUND
                 (x, y, t->seconds_input_box.x, t->seconds_input_box.y, t->seconds_input_box.width,
                  t->seconds_input_box.height))
        {
            gui_single_line_input_box_goto_first_character(t->focus_input_box);
            time_input_reset_focus((void *)t);
            for (;; i++)
            {
                if (t->focus_list[i] == TIME_INPUT_FOCUS_SECONDS)
                {
                    t->current_focus = i;
                    break;
                }
            }
            time_input_set_focus((void *)t);
        }
        else
        {
            return;
        }
        gui_show_single_line_input_box_ext(t->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(t->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(t->focus_input_box);
            gui_single_line_input_box_previous(t->focus_input_box);
        }
        show_time_input(t);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  time_input_set_seperator
 * DESCRIPTION
 *  set the mask of time input box
 * PARAMETERS
 *  d               [IN]        
 *  seperator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_seperator(time_input *d, UI_character_type seperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;
    single_line_input_box *box1 = NULL;
    single_line_input_box *box2 = NULL;
    single_line_input_box *box3 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator = seperator;
    gui_set_font(d->hours_input_box.text_font);
	gui_measure_character(d->seperator, &sw, &sh);
	

    switch (d->input.flags & TIME_INPUT_TYPE_MASK)
    {
        case TIME_INPUT_TYPE_HH_MM:
        case TIME_INPUT_TYPE_HH_MM_SS:
            box1 = &(d->hours_input_box);
            box2 = &(d->minutes_input_box);
            box3 = &(d->seconds_input_box);
            break;
    }
    
    if (box1 != NULL)
    {
        general_input_box_set_seperator_pos(
            box1,
            box2,
            sw,
            sh,
            &d->s1_x,
            &d->s1_y);
        general_input_box_set_seperator_pos(
            box2,
            box3,
            sw,
            sh,
            &d->s2_x,
            &d->s2_y);
    }

    d->s1_y += d->hours_input_box.y - d->input.y;
	d->s2_y = d->s1_y;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_set_hide_function
 * DESCRIPTION
 *  set the hide callback funtion of time input box
 * PARAMETERS
 *  d               [IN]        time input box
 *  f               [IN]        hide callback funtion
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_set_hide_function(time_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(d != NULL);

    d->input.hide_callback = f;
#endif
}


/* global variable store current time input */
time_input *current_time_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_time_input_callback
Description:      a function pointer of current time input callback 
Input Parameters: none
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*current_time_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_time_input
 * DESCRIPTION
 *  set the valeu of global variable store current
 *  time input equal to valeu pass as parameter
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_time_input(time_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_direct_input
 * DESCRIPTION
 *  enter the current character in time input box and show the time input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_direct_input(
        c,
        (void *)current_time_input,
        &(current_time_input->focus_input_box),
        time_input_set_next_focus);
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
    /* show time input box */
    show_time_input(current_time_input);
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL time_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return MMI_FALSE;
    }

    result = general_input_box_direct_input(
                 c,
                 (void *)current_time_input,
                 &(current_time_input->focus_input_box),
                 time_input_set_next_focus);

    current_time_input_callback();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  time_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 time_input_test_last_position(time_input *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_box_test_last_position(
               t->current_focus,
               t->focus_list,
               t->focus_input_box);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_character
 * DESCRIPTION
 *  delete character of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_delete_character(
        current_time_input,
        current_time_input->focus_input_box,
        time_input_set_previous_focus);
    /* show time input box */
    show_time_input(current_time_input);
    /* current time input callback fuc */
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_previous_character
 * DESCRIPTION
 *  delete previous cahracter of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_previous_character(
        current_time_input,
        &(current_time_input->focus_input_box),
        time_input_set_previous_focus);
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_first_character
 * DESCRIPTION
 *  goto first character of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_first_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_first_character(
        current_time_input,
       & (current_time_input->focus_input_box),
        time_input_set_previous_focus);
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_next_character
 * DESCRIPTION
 *  delete next  cahracter of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_next_character(
        current_time_input,
        current_time_input->focus_input_box,
        time_input_set_next_focus);
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_toggle_insert_mode
 * DESCRIPTION
 *  toggle insert mode of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }
    gui_single_line_input_box_toggle_insert_mode(current_time_input->focus_input_box);
    /* show time input box */
    show_time_input(current_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_current_character
 * DESCRIPTION
 *  delete character of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void time_input_delete_character_internal(MMI_BOOL delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_input == NULL || current_time_input->focus_input_box == NULL)
    {
        return;
    }

    if (delete_all == MMI_FALSE)
    {
        gui_single_line_input_box_delete_current_character(current_time_input->focus_input_box);
    }
    else
    {
        gui_single_line_input_box_delete_all(current_time_input->focus_input_box);
    }
    /* show time input box */
    show_time_input(current_time_input);
    current_time_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_current_character
 * DESCRIPTION
 *  delete current character of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_input_delete_character_internal(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_delete_all_characters
 * DESCRIPTION
 *  delete all characters of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_input_delete_character_internal(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  numeric key handle of time input box
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_numeric_keyboard_input_handler(
        keyc,
        time_input_direct_input,
        time_input_delete_character,
        time_input_delete_all_characters);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_handle_key_down
 * DESCRIPTION
 *  handle key down of time input box
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  time_input_key_handler
 * DESCRIPTION
 *  register key handlers of time input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_key_handler(
        vkey_code,
        key_state,
        time_input_previous_character,
        time_input_next_character,
        time_input_toggle_insert_mode,
        time_input_delete_current_character);
}


/*****************************************************************************
 * FUNCTION
 *  time_input_register_keys
 * DESCRIPTION
 *  register key handlers of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_register_keys(
        time_input_handle_key_down,
        time_input_numeric_keyboard_input_handler,
        time_input_previous_character,
        time_input_next_character,
        time_input_key_handler);
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
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  time_input_clear_keys
 * DESCRIPTION
 *  clear key handlers of time input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_input_clear_keys(void)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_clear_keys();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  register_time_input_callback
 * DESCRIPTION
 *  register time input call back function
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 *****************************************************************************/
void register_time_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_time_input_callback
 * DESCRIPTION
 *  clear  time input call back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_time_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_input_callback = UI_dummy_function;
}



/* color theme of time period input box */
UI_filled_area time_period_input_background_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};



/*****************************************************************************
 * Time Period Input
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  create_time_period_input
 * DESCRIPTION
 *  set defualt foucs of time period input box
 * PARAMETERS
 *  d                   [IN]        
 *  x                   [IN]        Start x position of time period input
 *  y                   [IN]        Start y position of time period input
 *  width               [IN]        Width of time  period input
 *  height              [IN]        Height of time period input
 *  flags               [IN]        
 *  hours_buffer1       [IN]        Hours buffer first range
 *  minutes_buffer1     [IN]        Minutes buffer first range
 *  hours_buffer2       [IN]        Hours buffer max range
 *  minutes_buffer2     [IN]        Minutes buffer max range
 * RETURNS
 *  void
 *****************************************************************************/
void create_time_period_input(
        time_period_input *d,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U32 flags,
        UI_buffer_type hours_buffer1,
        UI_buffer_type minutes_buffer1,
        UI_buffer_type hours_buffer2,
        UI_buffer_type minutes_buffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, w2, h, ox, oy, sw1, sw2, tw, l, w, sh1, sh2;
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_init(&(d->input), x, y, width, height, flags);

    gui_set_font(date_time_input_theme.text_font);
    w= gui_get_character_width((UI_character_type)'0');
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    w1 = 2 * w + 6;
    w2 = 2 * w + 6;
#else
	w1 = 2 * w + 8;
    w2 = 2 * w + 8;
#endif
    sw1 = TIME_PERIOD_INPUT_SEPERATOR_WIDTH1;
    sw2 = TIME_PERIOD_INPUT_SEPERATOR_WIDTH2;
    tw = w1 + sw1 + w2 + sw2 + w1 + sw1 + w2;
    h =  gui_get_character_height() + 1;
    h = (h < TIME_PERIOD_INPUT_HEIGHT) ? TIME_PERIOD_INPUT_HEIGHT : h;
    oy = (height >> 1) - (h >> 1);
    switch (flags & TIME_PERIOD_INPUT_JUSTIFY_MASK)
    {
        case TIME_PERIOD_INPUT_RIGHT_JUSTIFY:
            ox = (width - tw);
            break;

        case TIME_PERIOD_INPUT_CENTER_JUSTIFY:
            ox = (width >> 1) - (tw >> 1);
            break;

        default:
        {
        #if defined(__MMI_FTE_SUPPORT__)
            ox = GAP_BETWEEN_INPUT_COMPONENT_LEFT_AND_BOUNDAY;
        #else
            ox = 0;
        #endif
            break;
        }
    }

    d->focus_list[0] = TIME_PERIOD_INPUT_FOCUS_NONE;
    d->focus_list[5] = TIME_PERIOD_INPUT_FOCUS_NONE;
    d->focus_list[1] = TIME_PERIOD_INPUT_FOCUS_HOURS1;
    d->focus_list[2] = TIME_PERIOD_INPUT_FOCUS_MINUTES1;
    d->focus_list[3] = TIME_PERIOD_INPUT_FOCUS_HOURS2;
    d->focus_list[4] = TIME_PERIOD_INPUT_FOCUS_MINUTES2;
    d->hours1_x = ox;
    ox += w1 + sw1;
    d->minutes1_x = ox;
    ox += w2 + sw2;
    d->hours2_x = ox;
    ox += w1 + sw1;
    d->minutes2_x = ox;
    d->input.flags |= TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS1;
    current_single_line_input_box_theme = &date_time_input_theme;
    d->hours1_y = oy;
    d->minutes1_y = oy;
    d->hours2_y = oy;
    d->minutes2_y = oy;
    gui_measure_character(d->seperator1, &sw1, &sh1);
    gui_measure_character(d->seperator2, &sw2, &sh2);
    d->s1_y = oy + (h >> 1) - (sh1 >> 1);
    d->s2_y = oy + (h >> 1) - (sh2 >> 1);
    d->s3_y = d->s1_y;
    if ((h + 2) > height)
    {
        h = height - 2;
    }
    /* MTK Elvis for R2L characters */
    l = gui_strlen((UI_string_type) hours_buffer1) /* +1 */ ;
    /* create single input box of hours 1 */
    gui_create_single_line_input_box_set_buffer(
        &d->hours_input_box1,
        x + d->hours1_x,
        y + d->hours1_y,
        w1,
        h,
        (UI_string_type) hours_buffer1,
        TIME_PERIOD_INPUT_HOURS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->hours_input_box1.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->hours_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->hours_input_box1);
    l = gui_strlen((UI_string_type) minutes_buffer1) /* +1 */ ;
    /* create single input box of minutes 1 */
    gui_create_single_line_input_box_set_buffer(
        &d->minutes_input_box1,
        x + d->minutes1_x,
        y + d->minutes1_y,
        w2,
        h,
        (UI_string_type) minutes_buffer1,
        TIME_PERIOD_INPUT_MINUTES_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->minutes_input_box1.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->minutes_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->minutes_input_box1);
    l = gui_strlen((UI_string_type) hours_buffer1) /* +1 */ ;
    /* create single input box of hours 2 */
    gui_create_single_line_input_box_set_buffer(
        &d->hours_input_box2,
        x + d->hours2_x,
        y + d->hours2_y,
        w1,
        h,
        (UI_string_type) hours_buffer2,
        TIME_PERIOD_INPUT_HOURS_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->hours_input_box2.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->hours_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->hours_input_box2);
    l = gui_strlen((UI_string_type) minutes_buffer2) /* +1 */ ;
    /* create single input box of minutes 2 */
    gui_create_single_line_input_box_set_buffer(
        &d->minutes_input_box2,
        x + d->minutes2_x,
        y + d->minutes2_y,
        w2,
        h,
        (UI_string_type) minutes_buffer2,
        TIME_PERIOD_INPUT_MINUTES_BUFFER_LENGTH,
        (l + 1) * ENCODING_LENGTH,
        0);
    d->minutes_input_box2.flags |=
        (UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE | UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR |
         UI_SINGLE_LINE_INPUT_BOX_NO_BORDER);
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_BASIC_UI_STYLE__)
    d->minutes_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND;
#endif
    gui_single_line_input_box_goto_first_character(&d->minutes_input_box2);
    time_period_input_reset_focus((void *)d);
    time_period_input_set_default_focus(d);
    time_period_input_set_focus((void *)d);
    current_single_line_input_box_theme = t;
    /* MTK end */

    /* Setup default validation functions  */
    d->hours_input_box1.validation_callback = default_inline_time_hours_validation;
    d->minutes_input_box1.validation_callback = default_inline_time_minutes_validation;
    d->hours_input_box2.validation_callback = default_inline_time_hours_validation;
    d->minutes_input_box2.validation_callback = default_inline_time_minutes_validation;
}


/* Time period input object   */


/*****************************************************************************
 * FUNCTION
 *  time_period_input_show_background
 * DESCRIPTION
 *  show background of time period
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_show_background(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_show_background(&(d->input));
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_reset_focus
 * DESCRIPTION
 *  reset foucus of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_reset_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_period_input *d = (time_period_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    genreal_input_box_reset_flags(&(d->hours_input_box1));
    genreal_input_box_reset_flags(&(d->minutes_input_box1));
    genreal_input_box_reset_flags(&(d->hours_input_box2));
    genreal_input_box_reset_flags(&(d->minutes_input_box2));
    d->focus_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_focus
 * DESCRIPTION
 *  set foucus of time period input box depend on current focus
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *input_box = NULL;
    time_period_input *d = (time_period_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((d->current_focus < 1) || (d->current_focus > 4))
    {
        return;
    }

    switch (d->focus_list[d->current_focus])
    {
        case TIME_PERIOD_INPUT_FOCUS_HOURS1:
            input_box = &d->hours_input_box1;
            break;

        case TIME_PERIOD_INPUT_FOCUS_MINUTES1:
            input_box = &d->minutes_input_box1;
            break;

        case TIME_PERIOD_INPUT_FOCUS_HOURS2:
            input_box = &d->hours_input_box2;
            break;

        case TIME_PERIOD_INPUT_FOCUS_MINUTES2:
            input_box = &d->minutes_input_box2;
            break;
    }
    if (input_box != NULL)
    {
        genreal_input_box_set_focus_flags(input_box);
        d->focus_input_box = input_box;
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_default_focus
 * DESCRIPTION
 *  set defualt foucs of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_default_focus(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 focus = TIME_PERIOD_INPUT_FOCUS_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d->input.flags & TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MASK)
    {
        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS1:
            focus = TIME_PERIOD_INPUT_FOCUS_HOURS1;
            break;

        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES1:
            focus = TIME_PERIOD_INPUT_FOCUS_MINUTES1;
            break;

        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_HOURS2:
            focus = TIME_PERIOD_INPUT_FOCUS_HOURS2;
            break;

        case TIME_PERIOD_INPUT_TYPE_DEFAULT_FOCUS_MINUTES2:
            focus = TIME_PERIOD_INPUT_FOCUS_MINUTES2;
            break;
    }

    if (focus != TIME_PERIOD_INPUT_FOCUS_NONE)
    {
        for (i = 0; i < 6; i++)
        {
            if (d->focus_list[i] == focus)
            {
                d->current_focus = i;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_next_focus
 * DESCRIPTION
 *  set fopcus to next box of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_period_input_set_next_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_period_input *d = (time_period_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_FALSE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               time_period_input_reset_focus,
               time_period_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_previous_focus
 * DESCRIPTION
 *  set fopcus to previous  box of time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  byte
 *****************************************************************************/
U8 time_period_input_set_previous_focus(void *temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_period_input *d = (time_period_input *)temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_set_prev_next_focus(
               MMI_TRUE,
               d,
               &(d->focus_input_box),
               d->focus_list,
               &(d->current_focus),
               time_period_input_reset_focus,
               time_period_input_set_focus);
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
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  show_time_period_input
 * DESCRIPTION
 *  show time period input box
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_time_period_input(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_single_line_input_box_theme *t = current_single_line_input_box_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_single_line_input_box_theme = &date_time_input_theme;
    gui_set_single_line_input_box_current_theme(&d->hours_input_box1);
    gui_set_single_line_input_box_current_theme(&d->minutes_input_box1);
    gui_set_single_line_input_box_current_theme(&d->hours_input_box2);
    gui_set_single_line_input_box_current_theme(&d->minutes_input_box2);
    if (d->input.flags & TIME_PERIOD_INPUT_USE_PRESET_CLIP)
    {
        d->hours_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->minutes_input_box1.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->hours_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        d->minutes_input_box2.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
    }
    /* show single input box of hours 1 */
    gui_show_single_line_input_box(&d->hours_input_box1);
    /* show single input box of minutes 1 */
    gui_show_single_line_input_box(&d->minutes_input_box1);
    /* show single input box of hours2 */
    gui_show_single_line_input_box(&d->hours_input_box2);
    /* show single input box of minutes2 */
    gui_show_single_line_input_box(&d->minutes_input_box2);

    genreal_input_box_show_separator(
        &(d->input),
        d->hours_input_box1.text_font,
        d->hours_input_box1.normal_text_color,
        d->seperator1,
        d->seperator2,
        d->seperator1,
        d->s1_x,
        d->s1_y + d->input.y,
        d->s2_x,
        d->s2_y + d->input.y,
        d->s3_x,
        d->s3_y + d->input.y);
    gdi_layer_blt_previous(
        d->input.x,
        d->input.y,
        d->input.x + d->input.width - 1,
        d->input.y + d->input.height - 1);
    current_single_line_input_box_theme = t;
}


#if defined (__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  time_period_input_move_to_x_y
 * DESCRIPTION
 *  set the cursor position to (x,y) position
 * PARAMETERS
 *  tp      [IN]        Time period input box S32 x S32 y
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_move_to_x_y(time_period_input *tp, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, tp->input.x, tp->input.y, tp->input.width, tp->input.height) &&
        !(PEN_CHECK_BOUND
          (x, y, tp->minutes_input_box1.x + tp->minutes_input_box1.width, tp->input.y,
           tp->hours_input_box1.x - (tp->minutes_input_box1.x + tp->minutes_input_box1.width), tp->input.height)))
    {
        if (PEN_CHECK_BOUND
            (x, y, tp->hours_input_box1.x, tp->hours_input_box1.y, tp->hours_input_box1.width,
             tp->hours_input_box1.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus((void *)tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_HOURS1)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus((void *)tp);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, tp->minutes_input_box1.x, tp->minutes_input_box1.y, tp->minutes_input_box1.width,
                  tp->minutes_input_box1.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus((void *)tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_MINUTES1)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus((void *)tp);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, tp->hours_input_box2.x, tp->hours_input_box2.y, tp->hours_input_box2.width,
                  tp->hours_input_box2.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus((void *)tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_HOURS2)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus((void *)tp);
        }
        else if (PEN_CHECK_BOUND
                 (x, y, tp->minutes_input_box2.x, tp->minutes_input_box2.y, tp->minutes_input_box2.width,
                  tp->minutes_input_box2.height))
        {
            gui_single_line_input_box_goto_first_character(tp->focus_input_box);
            time_period_input_reset_focus((void *)tp);
            for (;; i++)
            {
                if (tp->focus_list[i] == TIME_PERIOD_INPUT_FOCUS_MINUTES2)
                {
                    tp->current_focus = i;
                    break;
                }
            }
            time_period_input_set_focus((void *)tp);
        }
        else
        {
            return;
        }
        gui_show_single_line_input_box_ext(tp->focus_input_box, x, y);
        if (gui_single_line_input_box_test_last_character_position(tp->focus_input_box))
        {
            gui_single_line_input_box_goto_last_character(tp->focus_input_box);
            gui_single_line_input_box_previous(tp->focus_input_box);
        }
        show_time_period_input(tp);
    }
}
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_seperators
 * DESCRIPTION
 *  set the mask of time period input box
 * PARAMETERS
 *  d               [IN]        
 *  seperator1      [IN]        Separator of first time period
 *  seperator2      [IN]        Seperartor of second time period
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_seperators(time_period_input *d, UI_character_type seperator1, UI_character_type seperator2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw1, sw2, sh1, sh2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->seperator1 = seperator1;
    d->seperator2 = seperator2;
    gui_set_font(d->hours_input_box1.text_font);
    
    gui_measure_character(d->seperator1, &sw1, &sh1);
    gui_measure_character(d->seperator2, &sw2, &sh2);

    general_input_box_set_seperator_pos(
        &(d->hours_input_box1),
        &(d->minutes_input_box1),
        sw1,
        sh1,
        &d->s1_x,
        &d->s1_y);
    d->s1_y += d->hours_input_box1.y - d->input.y;

    general_input_box_set_seperator_pos(
        &(d->minutes_input_box1),
        &(d->hours_input_box2),
        sw2,
        sh2,
        &d->s2_x,
        &d->s2_y);
    d->s2_y += d->minutes_input_box1.y - d->input.y;

    general_input_box_set_seperator_pos(
        &(d->hours_input_box2),
        &(d->minutes_input_box2),
        sw1,
        sh1,
        &d->s3_x,
        &d->s3_y);
    d->s3_y += d->hours_input_box2.y - d->input.y;
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_set_hide_function
 * DESCRIPTION
 *  set the hide callback function of time period input box
 * PARAMETERS
 *  d               [IN]        time input box
 *  f               [IN]        hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_set_hide_function(time_period_input *d, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(d != NULL);

    d->input.hide_callback = f;
}


/* glbal variable store value of current time period input box */
time_period_input *current_time_period_input = NULL;

/*----------------------------------------------------------------------------
Function:         current_time_period_input_callback
Description:   a function pointer of time period input callback 
Input Parameters: none
               
Output Parameters:   none
Returns:       none
----------------------------------------------------------------------------*/
void (*current_time_period_input_callback) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  set_current_time_period_input
 * DESCRIPTION
 *  set the valeu of global variable of current time period input
 *  equal to value pass as parameter
 * PARAMETERS
 *  d       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_time_period_input(time_period_input *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_period_input = d;
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_direct_input
 * DESCRIPTION
 *  insert the character in time period input
 *  and show the time period input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_direct_input(
        c,
        (void *)current_time_period_input,
        &(current_time_period_input->focus_input_box),
        time_period_input_set_next_focus);
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
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_direct_input_nodraw
 * DESCRIPTION
 *  insert the character in date input box and redraw date input box
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL time_period_input_direct_input_nodraw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return MMI_FALSE;
    }

    result = general_input_box_direct_input(
                 c,
                 (void *)current_time_period_input,
                 &(current_time_period_input->focus_input_box),
                 time_period_input_set_next_focus);

    current_time_period_input_callback();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_test_last_position
 * DESCRIPTION
 *  test current position is the last position or not
 * PARAMETERS
 *  tp                  [?]         
 *  time_input(?)       [IN]        *t
 * RETURNS
 *  S32
 *****************************************************************************/
S32 time_period_input_test_last_position(time_period_input *tp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return general_input_box_test_last_position(
               tp->current_focus,
               tp->focus_list,
               tp->focus_input_box);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_character
 * DESCRIPTION
 *  delete caharcter of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_delete_character(
        current_time_period_input,
        current_time_period_input->focus_input_box,
        time_period_input_set_previous_focus);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_previous_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_previous_character(
        current_time_period_input,
        &(current_time_period_input->focus_input_box),
        time_period_input_set_previous_focus);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_first_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_first_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_first_character(
        current_time_period_input,
        &(current_time_period_input->focus_input_box),
        time_period_input_set_previous_focus);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_next_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    general_input_box_next_character(
        current_time_period_input,
        current_time_period_input->focus_input_box,
        time_period_input_set_next_focus);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_toggle_insert_mode
 * DESCRIPTION
 *  cahneg the insert mode of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL ||
        current_time_period_input->focus_input_box == NULL)
    {
        return;
    }
    gui_single_line_input_box_toggle_insert_mode(current_time_period_input->focus_input_box);
    /* show time period input box */
    show_time_period_input(current_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_current_character
 * DESCRIPTION
 *  delete charactert of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void time_period_input_delete_character_internal(MMI_BOOL delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_time_period_input == NULL || current_time_period_input->focus_input_box == NULL)
    {
        return;
    }

    if (delete_all == MMI_FALSE)
    {
        gui_single_line_input_box_delete_current_character(current_time_period_input->focus_input_box);
    }
    else
    {
        gui_single_line_input_box_delete_all(current_time_period_input->focus_input_box);
    }
    /* show IP4 input box */
    show_time_period_input(current_time_period_input);
    current_time_period_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_current_character
 * DESCRIPTION
 *  delete current  character of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_period_input_delete_character_internal(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_delete_all_characters
 * DESCRIPTION
 *  delete all character of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_period_input_delete_character_internal(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_numeric_keyboard_input_handler
 * DESCRIPTION
 *  handle time period numeric input
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_numeric_keyboard_input_handler(
        keyc,
        time_period_input_direct_input,
        time_period_input_delete_character,
        time_period_input_delete_all_characters);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_handle_key_down
 * DESCRIPTION
 *  handle time periosd key down event
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_period_input_direct_input((UI_character_type) ('0' + k));
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_key_handler
 * DESCRIPTION
 *  register  key handlers of time period input box
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_key_handler(
        vkey_code,
        key_state,
        time_period_input_previous_character,
        time_period_input_next_character,
        time_period_input_toggle_insert_mode,
        time_period_input_delete_current_character);
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_register_keys
 * DESCRIPTION
 *  register all key handlers of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_register_keys(
        time_period_input_handle_key_down,
        time_period_input_numeric_keyboard_input_handler,
        time_period_input_previous_character,
        time_period_input_next_character,
        time_period_input_key_handler);
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
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  time_period_input_clear_keys
 * DESCRIPTION
 *  clear all key handlers of time period input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_period_input_clear_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    general_input_clear_keys();
}


/*****************************************************************************
 * FUNCTION
 *  register_time_period_input_callback
 * DESCRIPTION
 *  register current time period input callback function
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_time_period_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_period_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_time_period_input_callback
 * DESCRIPTION
 *  set current time period input callback to dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_time_period_input_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_time_period_input_callback = UI_dummy_function;
}


#if !defined(__OP01_FWPBW__)
UI_filled_area DOW_normal_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
#else
UI_filled_area DOW_normal_cell_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
#endif

/* theme when DOW is highlighted */
#if !defined(__OP01_FWPBW__)
UI_filled_area DOW_normal_highlighted_cell_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {9, 235, 253, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};
#else
UI_filled_area DOW_normal_highlighted_cell_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};
#endif

/* theme when DOW is selected */
#if !defined(__OP01_FWPBW__)
UI_filled_area DOW_selected_highlighted_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {9, 235, 253, 100},
    {0, 0, 0, 0},
    {235, 247, 17, 100},
    {0, 0, 0, 0},
    0
};
#else
UI_filled_area DOW_selected_highlighted_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
#endif

#if !defined(__OP01_FWPBW__)
UI_filled_area DOW_selected_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 240, 0, 100},
    {0, 0, 0, 0},
    {235, 247, 17, 100},
    {0, 0, 0, 0},
    0
};
#else
UI_filled_area DOW_selected_cell_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
#endif

UI_filled_area list_menu_DOW_normal_BG_filler = {UI_FILLED_AREA_TYPE_NO_BACKGROUND,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

#if !defined(__OP01_FWPBW__)
UI_filled_area list_menu_DOW_selected_cell_filler = {UI_FILLED_AREA_TYPE_NO_BACKGROUND | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {255, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
#else
UI_filled_area list_menu_DOW_selected_cell_filler = {UI_FILLED_AREA_TYPE_NO_BACKGROUND | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    0
};
#endif


/*****************************************************************************
 * FUNCTION
 *  create_DOW_select
 * DESCRIPTION
 *  create DOW selct input box
 * PARAMETERS
 *  d           [IN]        DOW input box
 *  x           [IN]        Start x position of DOW
 *  y           [IN]        Start y position of DOW
 *  width       [IN]        Width of DOW box
 *  height      [IN]        Height of DOW box
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 get_menu_item_height(void);
void create_DOW_select(DOW_select *d, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
#ifndef __MMI_FTE_SUPPORT__
    color c1 = {235, 247, 17, 100};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_FTE_SUPPORT__) && !defined(__OP01_FWPBW__)
    DOW_normal_cell_filler = *MMI_fixed_icontext_menuitem.focussed_filler;
    DOW_normal_cell_filler.flags &= 0X00000FFF;
    DOW_selected_cell_filler = *MMI_fixed_icontext_menuitem.focussed_filler;
    DOW_selected_cell_filler.flags &= 0X00000FFF;
    DOW_selected_cell_filler.flags |= UI_FILLED_AREA_SINGLE_BORDER;
    DOW_selected_cell_filler.border_color = c1;
#endif /* __MMI_FTE_SUPPORT__ */

#ifndef __MMI_FTE_SUPPORT__
    d->background_filler = &DOW_normal_cell_filler;
    d->normal_cell_filler = &DOW_normal_cell_filler;
    d->normal_highlighted_cell_filler = &DOW_normal_highlighted_cell_filler;
    d->selected_highlighted_cell_filler = &DOW_selected_highlighted_cell_filler;
    d->selected_cell_filler = &DOW_selected_cell_filler;
#if !defined(__OP01_FWPBW__)
    d->normal_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->normal_highlighted_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->selected_highlighted_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->selected_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
#else
    d->normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->normal_highlighted_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->selected_highlighted_text_color = MMI_fixed_icontext_menuitem.focussed_text_color;
    d->selected_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
#endif
#else /* __MMI_FTE_SUPPORT__ */
    d->background_filler = current_MMI_theme->DOW_normal_background_filler;
    d->normal_cell_filler = NULL;
    d->normal_highlighted_cell_filler = current_MMI_theme->DOW_cell_highlight_filler;
    d->selected_highlighted_cell_filler = current_MMI_theme->DOW_cell_highlight_filler;
    d->selected_cell_filler = current_MMI_theme->DOW_cell_normal_selected_filler;
    d->normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->normal_highlighted_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->selected_highlighted_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->selected_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->disabled_text_color = *(current_MMI_theme->icon_bar_item_text_disable_color);
#endif /* __MMI_FTE_SUPPORT__ */

    d->cell_width = DOW_CELL_WIDTH;
#ifndef __MMI_FTE_SUPPORT__
    d->cell_height = MMI_MENUITEM_HEIGHT;
#else
    d->cell_height = DOW_CELL_HEIGHT;
#endif
    d->x = x;
    d->y = y;
    d->width = width;
    d->height = height;
    d->cell_gap = DOW_CELL_GAP;
    d->offset_x = (width >> 1) - ((7 * (d->cell_width + d->cell_gap)) >> 1);
    d->offset_y = (height >> 1) - (d->cell_height >> 1);
    d->highlighted_cell = 0;
    d->text_font = gui_font_get_type(GUI_FONT_SIZE_DOW_SELECT);
#ifndef __MMI_FTE_SUPPORT__
    d->flags = 0;
#else
    d->flags = DOW_SELECT_STATE_DISABLED;
#endif
    for (i = 0; i < 7; i++)
    {
        d->states[i] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  show_DOW_select_background
 * DESCRIPTION
 *  show DOW bkg
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_DOW_select_background(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = d->x;
    y1 = d->y;
    x2 = x1 + d->width - 1;
    y2 = y1 + d->height - 1;

    gdi_layer_push_clip();
    if (d->flags & DOW_SELECT_USE_PRESET_CLIP)
    {
        gui_set_clip_preset(x1, y1, x2, y2);
    }
    else
    {
        gdi_layer_reset_clip();
    }

#ifdef __MMI_FTE_SUPPORT__
    switch (d->flags & DOW_SELECT_STATE_MASK)
    {
        case DOW_SELECT_STATE_FOCUSED:
            d->background_filler = current_MMI_theme->DOW_highlight_background_filler;
            break;

        case DOW_SELECT_STATE_DISABLED:
        case DOW_SELECT_STATE_NORMAL:
        default:
            d->background_filler = current_MMI_theme->DOW_normal_background_filler;
            break;
    }
    if (d->background_filler != NULL)
    {
        if ((d->background_filler)->b != NULL)
        {
            gdi_image_draw_resized(
                x1,
                y1,
                d->width,
                d->height,
                (d->background_filler)->b);
        }
        else
        {
            gui_draw_filled_area(x1, y1, x2, y2, d->background_filler);
        }		
    }
#else /* __MMI_FTE_SUPPORT__ */
    gui_draw_filled_area(x1, y1, x2, y2, d->background_filler);
#endif /* __MMI_FTE_SUPPORT__ */

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  show_DOW_select
 * DESCRIPTION
 *  show DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void show_DOW_select(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, character_width, character_height;
    color text_color;
    S32 i, x, y;
    UI_filled_area *f;
#ifdef __MMI_FTE_SUPPORT__
    UI_filled_area *highlight_filler;
    gdi_handle active_layer = GDI_NULL_HANDLE;
    gdi_handle abm_layer = GDI_NULL_HANDLE;
#endif /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_BASIC_UI_STYLE__)
    S32 DOW_list[] = { 'S', 'M', 'T', 'W', 'T', 'F', 'S' };
#else /* (__MMI_MAINLCD_128X160__)  || (__MMI_MAINLCD_128X128__) */
    S32 DOW_list[] = { 'S', 'M', 'T', 'W', 'T', 'F', 'S' };
    U16 string_id = STR_DOW_SUNDAY;
    S8 *dow_string;
    MMI_BOOL use_DOW_list = MMI_FALSE;
#endif /* (__MMI_MAINLCD_128X160__) || (__MMI_MAINLCD_128X128__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    if (d->flags & DOW_SELECT_USE_PRESET_CLIP)
    {
        gui_set_clip_preset(d->x, d->y, d->x + d->width - 1, d->y + d->height - 1);
    }
    else
    {
        gdi_layer_reset_clip();
    }
    x = d->x + d->offset_x;
    y = d->y + d->offset_y;
    gui_set_font(d->text_font);

#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_BASIC_UI_STYLE__)
    character_height = gui_get_character_height();
#endif

#if !defined(__MMI_MAINLCD_128X160__) && !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_BASIC_UI_STYLE__)
    for (i = 0; i < 7; i++)
    {
        dow_string = GetString(string_id + i);
        gui_measure_string((UI_string_type) dow_string, &character_width,&character_height);
        if (character_width >= d->cell_width)
        {
            use_DOW_list = MMI_TRUE;
            break;
        }
    }
#endif
    for (i = 0; i < 7; i++)
    {
        if (i == d->highlighted_cell)
        {
            if (d->states[i])
            {
            #ifndef __MMI_FTE_SUPPORT__
                f = d->selected_highlighted_cell_filler;
            #else /* __MMI_FTE_SUPPORT__ */
                if ((d->flags & DOW_SELECT_STATE_MASK) == DOW_SELECT_STATE_FOCUSED)
                {
                    f = current_MMI_theme->DOW_cell_focus_selected_filler;
                    highlight_filler = current_MMI_theme->DOW_cell_highlight_filler;
                }
                else
                {
                    f = current_MMI_theme->DOW_cell_normal_selected_filler;
                    highlight_filler = NULL;
                }
            #endif /* __MMI_FTE_SUPPORT__ */
                text_color = d->selected_highlighted_text_color;
            }
            else
            {
            #ifndef __MMI_FTE_SUPPORT__
                f = d->normal_highlighted_cell_filler;
            #else /* __MMI_FTE_SUPPORT__ */
                if ((d->flags & DOW_SELECT_STATE_MASK) == DOW_SELECT_STATE_FOCUSED)
                {
                    f = NULL;
                    highlight_filler = current_MMI_theme->DOW_cell_highlight_filler;
                }
                else
                {
                    f = NULL;
                    highlight_filler = NULL;
                }
            #endif /* __MMI_FTE_SUPPORT__ */
                text_color = d->normal_highlighted_text_color;
            }
        }
        else
        {
            if (d->states[i])
            {
            #ifndef __MMI_FTE_SUPPORT__
                f = d->selected_cell_filler;
            #else /* __MMI_FTE_SUPPORT__ */
                if ((d->flags & DOW_SELECT_STATE_MASK) == DOW_SELECT_STATE_FOCUSED)
                {
                    f = current_MMI_theme->DOW_cell_focus_selected_filler;
                }
                else
                {
                    f = current_MMI_theme->DOW_cell_normal_selected_filler;
                }
                highlight_filler = NULL;
            #endif /* __MMI_FTE_SUPPORT__ */
                text_color = d->selected_text_color;
            }
            else
            {
                f = d->normal_cell_filler;
             #ifdef __MMI_FTE_SUPPORT__
                highlight_filler = NULL;
             #endif
                text_color = d->normal_text_color;
            }
        }
        x1 = x;
        y1 = y;
        x2 = x1 + d->cell_width - 1;
        y2 = y1 + d->cell_height - 1;
        if (d->flags & DOW_SELECT_USE_PRESET_CLIP)
        {
            gdi_layer_push_clip();
            gui_set_clip_preset(x1, y1, x2, y2);
        }
        else
        {
            gui_set_clip(x1, y1, x2, y2);
            gui_set_text_clip(x1, y1, x2, y2);
        }
    #ifdef __MMI_FTE_SUPPORT__
        gdi_layer_get_active(&active_layer);
        abm_layer = gdi_set_alpha_blending_source_layer(active_layer);
        if ((d->flags & DOW_SELECT_STATE_MASK) == DOW_SELECT_STATE_DISABLED)
        {
            f = NULL;
            highlight_filler = NULL;
            text_color = d->disabled_text_color;
        }
        if (highlight_filler != NULL)
        {
            if (highlight_filler->b != NULL)
            {
                gdi_image_draw_resized(
                    x1,
                    y1,
                    d->cell_width,
                    d->cell_height,
                    highlight_filler->b);
            }
            else
            {
                gui_draw_filled_area(x1, y1, x2, y2, highlight_filler);
            }
        }
        if (f != NULL)
        {
            if (f->b != NULL)
            {
                gdi_image_draw_resized(
                    x1,
                    y1,
                    d->cell_width,
                    d->cell_height,
                    f->b);
            }
            else
            {
                gui_draw_filled_area(x1, y1, x2, y2, f);
            }
        }        
        gdi_set_alpha_blending_source_layer(abm_layer);
    #else /* __MMI_FTE_SUPPORT__ */
        gui_draw_filled_area(x1, y1, x2, y2, f);
    #endif /* __MMI_FTE_SUPPORT__ */

    #if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_BASIC_UI_STYLE__)
        character_width = gui_get_character_width((UI_character_type) DOW_list[i]);
    #else /* (__MMI_MAINLCD_128X160__) || (__MMI_MAINLCD_128X128__) */
        if (use_DOW_list == MMI_FALSE)
        {
            dow_string = GetString(string_id + i);
            gui_measure_string((UI_string_type) dow_string, &character_width,&character_height);
        }
        else
        {
            character_width = gui_get_character_width((UI_character_type) DOW_list[i]);
        }
    #endif /* (__MMI_MAINLCD_128X160__) || (__MMI_MAINLCD_128X128__) */

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(
                x + ((d->cell_width - character_width) / 2) + character_width,
                y + ((d->cell_height - character_height) / 2));
        }
        else
        {
            gui_move_text_cursor(
                x + ((d->cell_width - character_width) / 2),
                y + ((d->cell_height - character_height) / 2));
        }

        gui_set_text_color(text_color);
        
    #if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_BASIC_UI_STYLE__)
        gui_print_character((UI_character_type) DOW_list[i]);
    #else /* (__MMI_MAINLCD_128X160__) || (__MMI_MAINLCD_128X128__)  */
        if (use_DOW_list == MMI_FALSE)
        {
            gui_print_text((UI_string_type) dow_string);
        }
        else
        {
            gui_print_character((UI_character_type) DOW_list[i]);
        }
    #endif /* (__MMI_MAINLCD_128X160__) || (__MMI_MAINLCD_128X128__)  */

        if (d->flags & DOW_SELECT_USE_PRESET_CLIP)
        {
            gdi_layer_pop_clip();
        }
        x += d->cell_width + d->cell_gap;
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  set_DOW_select_list_menu_theme
 * DESCRIPTION
 *  set color theme of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void set_DOW_select_list_menu_theme(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    color c1 = {255, 0, 0, 100};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    list_menu_DOW_selected_cell_filler = *MMI_fixed_list_menu.normal_filler;
    list_menu_DOW_selected_cell_filler.flags = (UI_FILLED_AREA_TYPE_NO_BACKGROUND | UI_FILLED_AREA_SINGLE_BORDER);
    list_menu_DOW_selected_cell_filler.border_color = c1;
    list_menu_DOW_normal_BG_filler = *MMI_fixed_list_menu.normal_filler;
    list_menu_DOW_normal_BG_filler.flags = UI_FILLED_AREA_TYPE_NO_BACKGROUND;

    d->background_filler = &list_menu_DOW_normal_BG_filler;
    d->normal_cell_filler = &list_menu_DOW_normal_BG_filler;
    d->normal_highlighted_cell_filler = &list_menu_DOW_normal_BG_filler;
    d->selected_highlighted_cell_filler = &list_menu_DOW_selected_cell_filler;
    d->selected_cell_filler = &list_menu_DOW_selected_cell_filler;
    d->normal_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->normal_highlighted_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->selected_highlighted_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    d->selected_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  set_DOW_select_states
 * DESCRIPTION
 *  set staes of days in DOW input box
 * PARAMETERS
 *  d           [IN]        DOW input box
 *  states      [IN]        []  :- store teh states valeu
 * RETURNS
 *  void
 *****************************************************************************/
void set_DOW_select_states(DOW_select *d, U8 states[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 7; i++)
    {
        d->states[i] = states[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_DOW_select_flags
 * DESCRIPTION
 *  set flags of DOW input box
 * PARAMETERS
 *  d           [IN]        DOW input box
 *  flags       [IN]        the flag of DOW select
 * RETURNS
 *  void
 *****************************************************************************/
void set_DOW_select_flags(DOW_select *d, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d->flags = flags;
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  DOW_translate_pen_position
 * DESCRIPTION
 *  Translate pen events for DOW
 * PARAMETERS
 *  d               [IN]        DOW input box
 *  x               [IN]        X coordniate
 *  cell_index      [OUT]       Corresponding cell index ( -1 for invalid position)
 * RETURNS
 *  void
 *****************************************************************************/
static void DOW_translate_pen_position(DOW_select *d, S32 x, S32 *cell_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = d->x + d->offset_x;

    if (x < offset)
    {
        *cell_index = -1;
        return;
    }

    for (i = 0; i < 7; i++)
    {
        offset += d->cell_width + d->cell_gap;
        if (x < offset)
        {
            *cell_index = i;
            return;
        }
    }
    *cell_index = -1;
}


/*****************************************************************************
 * FUNCTION
 *  DOW_translate_pen_event
 * DESCRIPTION
 *  Translate pen events for DOW
 * PARAMETERS
 *  d               [IN]        DOW input box
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  DOW_event       [?]         
 *  DOW_param       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
BOOL DOW_translate_pen_event(
        DOW_select *d,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        DOW_pen_event_enum *DOW_event,
        gui_pen_event_param_struct *DOW_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *DOW_event = DOW_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(DOW_param);

    /* Only react to pen down event */
    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        if (PEN_CHECK_BOUND(x, y, d->x, d->y, d->width, d->height))
        {
            S32 cell_index;

            DOW_translate_pen_position(d, x, &cell_index);

            if (cell_index >= 0)
            {
                if (d->highlighted_cell != cell_index)
                {
                    *DOW_event = DOW_PEN_CHANGE_HIGHLIGHT_AND_TOGGLE_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(DOW_param, cell_index);
                }
                else
                {
                    *DOW_event = DOW_PEN_TOGGLE_CURRENT_ITEM;
                }
            }
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }
        else
        {
            ret = MMI_FALSE;
        }
    }

    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  DOW_select_previous
 * DESCRIPTION
 *  set focus on previous select day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_previous(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((S32) d->highlighted_cell <= 0)
    {
        return;
    }

    d->highlighted_cell--;
}


/*****************************************************************************
 * FUNCTION
 *  DOW_select_next
 * DESCRIPTION
 *  set focus on next  select day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_next(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (d->highlighted_cell >= 6)
    {
        return;
    }

    d->highlighted_cell++;
}


/*****************************************************************************
 * FUNCTION
 *  DOW_select_toggle_item
 * DESCRIPTION
 *  toggle the select or unslect day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_toggle_item(DOW_select *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((S32) d->highlighted_cell < 0) || (d->highlighted_cell > 6))
    {
        return;
    }

    if (d->states[d->highlighted_cell] == 1)
    {
        d->states[d->highlighted_cell] = 0;
    }
    else if (d->states[d->highlighted_cell] == 0)
    {
        d->states[d->highlighted_cell] = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DOW_select_highlight_item
 * DESCRIPTION
 *  highlight particular day of DOW input box
 * PARAMETERS
 *  d       [IN]        DOW input box
 *  i       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void DOW_select_highlight_item(DOW_select *d, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < 0) || (i > 6))
    {
        return;
    }

    d->highlighted_cell = (U8) i;
}


void (*MMI_main_LCD_time_duration_hide_function) (S32 x1, S32 y1, S32 x2, S32 y2) = UI_dummy_hide_function;


/*****************************************************************************
 * FUNCTION
 *  set_main_LCD_time_duration_hide_function
 * DESCRIPTION
 *  set hide time duration function for main lcd
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Ptr f
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_LCD_time_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_main_LCD_time_duration_hide_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  set_time_duration
 * DESCRIPTION
 *  set main lcd time duration object
 * PARAMETERS
 *  t               [IN]        
 *  duration        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_time_duration(UI_time *t, U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_time_object.duration.t = *t;   /* set the duration value */
    kal_get_time(&last_duration_ticks);
    last_duration = duration;
}


/*****************************************************************************
 * FUNCTION
 *  set_duration_start_time
 * DESCRIPTION
 *  set main lcd time duration object's start time
 * PARAMETERS
 *  t               [IN]        
 *  duration        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_duration_start_time(UI_time *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_time_object.duration_start_time = *t;   /* set the duration value */
}


/*****************************************************************************
 * FUNCTION
 *  get_time_duration
 * DESCRIPTION
 *  get main lcd time duration object
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_time_duration(UI_time *t)
{
#ifndef __MMI_DATETIME_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *t = main_LCD_time_object.duration.t;   /* get the duration value */
#endif
}


/*****************************************************************************
 * FUNCTION
 *  get_duration_string
 * DESCRIPTION
 *  get main lcd time duration string
 * PARAMETERS
 *  t           [IN]        
 *  s           [IN]        
 *  flags       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_duration_string(UI_time *t, UI_string_type s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes, seconds;
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = get_hours(t);
    minutes = get_minutes(t);
    seconds = get_seconds(t);
    sprintf((S8*) ts, "%02d:%02d:%02d", hours, minutes, seconds);
    mmi_asc_to_ucs2((S8*) s, ts);
}


/*****************************************************************************
 * FUNCTION
 *  time_display_duration
 * DESCRIPTION
 *  display time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_display_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    S32 x1, y1, x2, y2;
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = main_LCD_time_object.duration.x;
    y1 = main_LCD_time_object.duration.y;
    x2 = main_LCD_time_object.duration.width + x1 - 1;
    y2 = main_LCD_time_object.duration.height + y1 - 1;
    main_LCD_time_object.duration.hide_function(x1, y1, x2, y2);        /* call hide function of call duration */

    gui_set_font(main_LCD_time_object.duration.font);
    /* get call duration in string fromat */
    get_duration_string(&main_LCD_time_object.duration.t, (UI_string_type) s, main_LCD_time_object.flags);
    gui_set_text_color(main_LCD_time_object.duration.text_color);
    w = gui_get_string_width(s);

    if (mmi_fe_get_r2l_state())
    {
        //gui_move_text_cursor(x1 + w, y1);
        gui_move_text_cursor(x1+((main_LCD_time_object.duration.width-w)>>1) + w - 1, y1);
    }
    else
    {
        //gui_move_text_cursor(x1, y1);
        gui_move_text_cursor(x1+((main_LCD_time_object.duration.width-w)>>1), y1);
    }

    gui_set_text_clip(x1, y1, x2, y2);
    /* print call duration */
    gui_print_text(s);
    gdi_layer_blt_previous(x1, y1, x2, y2);

}


/*****************************************************************************
 * FUNCTION
 *  time_update_duration
 * DESCRIPTION
 *  update time duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void time_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    increment_ticks(&main_LCD_time_object.duration.t);  /* increment secods by 1 */
    time_display_duration();
    gui_start_timer(300, time_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  set_time_display
 * DESCRIPTION
 *  set time duration object properties
 * PARAMETERS
 *  flags       [IN]        
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_time_display(U32 flags, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    main_LCD_time_object.flags = (flags & DT_FLAGS_TYPE);
    main_LCD_time_object.duration.hide_function = MMI_main_LCD_time_duration_hide_function;
    main_LCD_time_object.duration.font = &MMI_large_font;
	main_LCD_time_object.duration.text_color = *current_MMI_theme->datetime_bar_duration_text_color;
    main_LCD_time_object.duration.x = x;
    main_LCD_time_object.duration.y = y;
    main_LCD_time_object.duration.width = width;
    main_LCD_time_object.duration.height = height;
    gui_cancel_timer(time_update_duration);
    if (flags != 0)
    {
        gui_start_timer(300, time_update_duration);
    }
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  close_main_LCD_time_display
 * DESCRIPTION
 *  disable main lcd time display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_main_LCD_time_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(time_update_duration);
    MMI_main_LCD_time_duration_hide_function = UI_dummy_hide_function;
}


/*****************************************************************************
 * FUNCTION
 *  enactive_main_lcd_update_date_time
 * DESCRIPTION
 *  enable update date time for main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enactive_main_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_lcd_update_date_time = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  deactive_main_lcd_update_date_time
 * DESCRIPTION
 *  disable update date time for main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void deactive_main_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_lcd_update_date_time = MMI_FALSE;
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  enactive_sub_lcd_update_date_time
 * DESCRIPTION
 *  enable update date time display for sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enactive_sub_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sub_lcd_update_date_time = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  deactive_sub_lcd_update_date_time
 * DESCRIPTION
 *  disable update date time display for sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void deactive_sub_lcd_update_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sub_lcd_update_date_time = MMI_FALSE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_main_lcd_duration_position
 * DESCRIPTION
 *  set the position of duration display on main lcd
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_main_lcd_duration_position(U16 x, U16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    main_LCD_dt_object.duration.x = x;
    main_LCD_dt_object.duration.y = y;
}

/* PMT HIMANSHU START 20050721 */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__


/*****************************************************************************
 * FUNCTION
 *  wgui_set_clock_type
 * DESCRIPTION
 *  set the value of the current clock to be displayed.
 * PARAMETERS
 *  clock_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_clock_type(U8 clock_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (clock_type)
    {
        case ANALOG:
            g_clock_type = ANALOG;
            idlescreen_bar_id = IMG_TECHNO_ANALOG_CLOCK;//070306 Alpha layer
            break;
        case DIGITAL:
            g_clock_type = DIGITAL;
            idlescreen_bar_id = IMG_TECHNO_DIGITAL_CLOCK;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_day_display
 * DESCRIPTION
 *  set the pointer to point to the current day string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_day_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    day_string = get_string((U16) (STR_IDLESCREEN_SUNDAY + main_LCD_dt_object.date.t.DayIndex));
}


/*****************************************************************************
 * FUNCTION
 *  show_main_LCD_day_display
 * DESCRIPTION
 *  show the day string on main lcd in techon idlescreeen
 *  bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_main_LCD_day_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 x1, y1, x2, y2;
    S32 w, h;
    stFontAttribute *font;
    color text_color, text_border_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_color = *current_MMI_theme->idle_scr_weekday_color;
    text_border_color = *current_MMI_theme->idle_scr_weekday_border_color;
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    font = gui_font_get_type(GUI_FONT_SIZE_DAY);
#else /* __MMI_MAINLCD_240X320__ */ 
    font = gui_font_get_type(GUI_FONT_SIZE_DAY);
#endif /* __MMI_MAINLCD_240X320__ */ 
    gui_set_font(font);
    gui_measure_string(day_string, &w, &h);
    gui_set_text_color(text_color);
    gui_set_text_border_color(text_border_color);
	if (g_clock_type == ANALOG)
	{
    x1 = ANALOG_BACKGROUND_X + ANALOG_BACKGROUND_WIDTH + 1;
	}
	else
	{
		x1 = DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH + 1;
	}
    y1 = MMI_status_bar_height + ((MMI_IDLESCREEN_BAR_HEIGHT + (MMI_IDLESCREEN_BAR_HEIGHT >> 1) - h) >> 1);
    x2 = UI_device_width - MMI_SIGNAL_WIDTH;
    y2 = y1 + h - 1;
    gdi_layer_push_clip();
    gui_set_clip(x1, y1-1, x2, y2+1);//091206 idlescreen day
    /* PMT HIMANSHU START 20051012 */
    /* Day string is not coming at right location in case of r2lMMIFlag is ON.
       So move the cursor at correct position. */
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x2 - 2, y1);
    }
    else
    {
        gui_move_text_cursor(((x2 - 2) - w), y1);
    }
    /* PMT HIMANSHU END 20051012 */
    gui_print_bordered_text(day_string);
    gdi_layer_pop_clip();

    gdi_layer_blt_previous(x1, y1-1, x2, y2+1);
    
}
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
/* PMT HIMANSHU END 20050721 */


/*****************************************************************************
 * FUNCTION
 *  set_day_display
 * DESCRIPTION
 *  set the pointer to point to the current day string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_datetime_show_date_set_enable(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ANALOG_CLOCK__
    wgui_datetime_need_show_date = enable;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wgui_datetime_measure_duration
 * DESCRIPTION
 *  measure the MAX width of duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_datetime_measure_duration(S32 *w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    UI_time t;
    S32 i, j, width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t.nHour = 0;
    t.nMin = 0;
    *w = 0;
    j = 0;
    
    gui_set_font(main_LCD_dt_object.duration.font);

    for (i = 0; i <= 9; i++)
    {
        t.nSec = (kal_uint8)i;
        /* get call duration in string fromat */
        duration_string(&t, (UI_string_type) s, main_LCD_dt_object.flags);
        width = gui_get_string_width(s);
        if (width > *w)
        {
            *w = width;
            j = i;
        }
    }

    /* measure the MAX width */
    t.nHour = (kal_uint8)(j * 10 + j);
    t.nMin = t.nHour;
    t.nSec = t.nMin;
    duration_string(&t, (UI_string_type) s, main_LCD_dt_object.flags);
    *w = gui_get_string_width(s);
}



