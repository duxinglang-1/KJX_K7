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
 *   wgui_categories_sublcd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Sublcd display related categories.
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 kavin.ma
 * removed!
 * .
 *
 * 12 05 2011 sachin.jain1
 * removed!
 * .
 *
 * 07 28 2011 sachin.jain1
 * removed!
 * .
 *
 * 07 06 2011 sachin.jain1
 * removed!
 * .
 *
 * 02 08 2011 ray.wu
 * removed!
 * .
 *
 * 02 08 2011 mason.chang
 * removed!
 * Rename/move file(s)
 *
 * 01 18 2011 sachin.jain1
 * removed!
 * .
 *
 * 01 17 2011 sachin.jain1
 * removed!
 * .
 *
 * 01 10 2011 sachin.jain1
 * removed!
 * .
 *
 * 01 10 2011 sachin.jain1
 * removed!
 * .
 *
 * 12 17 2010 sachin.jain1
 * removed!
 * .
 *
 * 11 23 2010 sachin.jain1
 * removed!
 * .
 *
 * 11 17 2010 sachin.jain1
 * removed!
 * .
 *
 * 11 17 2010 sachin.jain1
 * removed!
 * .
 *
 * 11 16 2010 sachin.jain1
 * removed!
 * .
 *
 * 11 15 2010 sachin.jain1
 * removed!
 * .
 *
 * 11 01 2010 sachin.jain1
 * removed!
 * .
 *
 * 10 26 2010 pawanjeet.singh
 * removed!
 * .
 *
 * 10 25 2010 sachin.jain1
 * removed!
 * .
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
 * Revise header files
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
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 * Rename ReadPhnset to PhnsetRead
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
 *******************************************************************************/

/******************************************************************************
 *
 *  File:            %P%
 *  -----
 *
 *  SCCS Version:    %I%
 *  -------------
 *
 *  Copyright Statement:
 *  --------------------
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 *
 *  Project:        
 *  --------
 *
 *  Software Unit:  plutommi
 *  --------------
 *
 *  Description:
 *  ------------
 *  PixTel UI wrapper routines
   High Level Category screen wrappers.
 *  
 *  Modification History:
 *  ---------------------
 *  Date          Vers           Auth  Details
 *  ----          ----           ----  -------
 *  2004/05/18 Initial version.    LeoHu Split from wgui_categories.c   
 *
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SUB_WALLPAPER__
#include "WPSSProtos.h" /* diamond, 2005/06/21 bad file callback */
#endif 

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "custom_mmi_default_value.h"
#include "gui.h"
#include "wgui_categories_util.h"
#include "gdi_include.h"
#include "wgui_include.h"
#include "gui_typedef.h"
#include "wgui_draw_manager.h"
#include "wgui_fixed_menus.h"
#include "gui_font_size.h"
#include "wgui_categories_sublcd.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_uiframework_def.h"
#include "wgui_fixed_menuitems.h"
#include "GpioSrvGprot.h"
/*
 * Local Variable
 */
#ifdef __MMI_SUBLCD__
static multi_line_input_box SUBLCD_input_box;

/* Store the message of current multibox dispaly on sub lcd */
static UI_string_type SUBLCD_MMI_message_string;
static UI_string_type SUBLCD_MMI_message_string1;

static S32 category311_text_offset_x = 0;
static S32 category311_text_width = 0;
static S32 category311_text_height = 0;
static MMI_BOOL g_mmi_gui_in_cat310 = MMI_FALSE;
static U8 *wgui_cat312_info1 = NULL;
static U8 *wgui_cat312_info2 = NULL;

#endif /* __MMI_SUBLCD__ */

#ifdef __MMI_SUB_WALLPAPER__
static GDI_HANDLE *sublcd_wallpaper_layer = NULL;
static GDI_HANDLE sublcd_wallpaper_animation_handle = GDI_ERROR_HANDLE;
static MMI_ID_TYPE idle_screen_wallpaper_sub_ID = 0;

#ifdef __MTK_TARGET__
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
#endif /* __MTK_TARGET__ */
#ifndef __MTK_TARGET__
#define __align(X)
#endif
__align( __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__) static U8 sub_wallpaper_buf[(GDI_SUBLCD_WIDTH * GDI_SUBLCD_HEIGHT * GDI_SUBLCD_BIT_PER_PIXEL + 7)>>3];
#ifdef __MTK_TARGET__
#pragma arm section zidata, rwdata
#endif

/* store the x position of wallpaer of idle screen */
static S32 cat312_image_x;

/* store the y position of wallpaer of idle screen */
static S32 cat312_image_y;

/* store the image width  of wallpaer of idle screen */
static S32 cat312_image_width;

/* store the image height  of wallpaer of idle screen */
static S32 cat312_image_height;

/* store the total number frames  of animation wallpaper */
#endif /* __MMI_SUB_WALLPAPER__ */ 

/*
 * Local Function
 */

/*
 * Global Variable
 */

//extern BOOL r2lMMIFlag;

#ifdef __MMI_SUB_WALLPAPER__
extern S8 *idle_screen_wallpaper_sub_name;
#endif 

S32 Sub_lcd_title_height = 13;

#ifdef __MMI_SUB_WALLPAPER__
GDI_HANDLE sublcd_base_layer = GDI_ERROR_HANDLE;
MMI_BOOL is_sub_idle_screen = MMI_FALSE;
#endif /* __MMI_SUB_WALLPAPER__ */ 

/*
 * Used in wgui_show_animation serial functions
 * After revise these codes, the following variables can be saved
 */
PU8 SUBLCD_MMI_animated_icon = NULL;
S32 SUBLCD_MMI_animated_icon_x = 0;
S32 SUBLCD_MMI_animated_icon_y = 0;
UI_animated_image_handle SUBLCD_MMI_animated_icon_handle = NULL;

/*
 * Global Function
 */
extern void arrange_status_icons_sublcd(void);
extern void UI_set_sub_LCD_graphics_context(void);
extern void wgui_set_animation_y(S32 x, S32 y, MMI_ID_TYPE img);
extern void get_time_difference(MYTIME *time_303, FLOAT city_diff);
extern void analog_clock_initialize(void);
extern void ShowSubLCDChargingScr(void);
extern void ShowSubLCDChargingCompleteScr(void);

#ifdef __MMI_ANALOG_CLOCK__
extern void analog_clock_initialize(void);
#endif /* __MMI_ANALOG_CLOCK__ */ 

/*****************************************************************************
* FUNCTION
*  SUBLCD_ExitCategoryFunction
*
* DESCRIPTION
*   function pointer store the address of exit function of current sub lcd category scrren
*
* PARAMETERS
*  void
*
* RETURNS
*  void
*
* GLOBALS AFFECTED
*
*****************************************************************************/
void (*SUBLCD_ExitCategoryFunction) (void) = UI_dummy_function;

/*****************************************************************************
* FUNCTION
*  SUBLCD_RedrawCategoryFunction
*
* DESCRIPTION
*   function pointer store the address of redraw function of current sub lcd category scrren
*
* PARAMETERS
*  void
*
* RETURNS
*  void
*
* GLOBALS AFFECTED
*
*****************************************************************************/
void (*SUBLCD_RedrawCategoryFunction) (void) = UI_dummy_function;

/*****************************************************************************
* FUNCTION
*  SUBLCD_GetCategoryHistory
*
* DESCRIPTION
*   function pointer store the address of getcategoryhistory function of current sub lcd category scrren
*
* PARAMETERS
*  buffer      IN/OUT      history buffer
*
* RETURNS
*  U8*
*
* GLOBALS AFFECTED
*
*****************************************************************************/
U8 *(*SUBLCD_GetCategoryHistory) (U8 *buffer) = dummy_get_history;


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_screens_show_status_icons
 * DESCRIPTION
 *  function pointer store the address of getcategoryhistory function of current sub lcd category scrren
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 History size
 *****************************************************************************/
S32(*SUBLCD_GetCategoryHistorySize) (void) = dummy_get_history_size;

/*
 * void initialize_sublcd_category_screen(void)
 * {
 * SUBLCD_ExitCategoryFunction=MMI_dummy_function;
 * SUBLCD_RedrawCategoryFunction=MMI_dummy_function;
 * SUBLCD_GetCategoryHistory=dummy_get_history;
 * SUBLCD_GetCategoryHistorySize=dummy_get_history_size;
 * }
 */

#if (0)
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
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

void SUBLCD_screens_show_status_icons(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    return;
#endif 
    GDI_LOCK;

    gdi_layer_push_clip();
    wgui_status_icon_bar_update();
    gdi_layer_reset_clip();
    gdi_layer_pop_clip();
#ifndef __MMI_STATUS_BAR_NO_UNDERLINE__
    gdi_draw_line(0, Sub_lcd_title_height - 1, UI_device_width - 1, Sub_lcd_title_height - 1, GDI_COLOR_BLACK);
#endif 

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_screens_hide_status_icons
 * DESCRIPTION
 *  hide status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SUBLCD_screens_hide_status_icons(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    return;
#endif 

    GDI_LOCK;

    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_show_sublcd_background(0, 0, (UI_device_width - 1), Sub_lcd_title_height - 1, MMI_TRUE);
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDStatusIconsTitle
 * DESCRIPTION
 *  show staus bar on sub lcd screen
 * PARAMETERS
 *  void
 *  S16(?)      [IN]        Icon_ID
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDStatusIconsTitle(void)
{
#ifdef __MMI_SUBLCD__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    return;
#endif 

    GDI_LOCK;

    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, 
        SUBLCD_screens_hide_status_icons);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);

    GDI_UNLOCK;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_screens_hide_date_time
 * DESCRIPTION
 *  Hide date time
 * PARAMETERS
 *  x1      [IN]        Start x
 *  y1      [IN]        Start y
 *  x2      [IN]        End x
 *  y2      [IN]        End y
 * RETURNS
 *  void
 *****************************************************************************/
void SUBLCD_screens_hide_date_time(S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    gdi_layer_reset_clip();

#ifdef __MMI_SUB_WALLPAPER__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    wgui_status_icon_bar_show_sublcd_background(x1, y1, x2, y2, MMI_FALSE);
#endif 

    gdi_layer_blt_previous(x1, y1, x2, y2);

    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_category301_callback
 * DESCRIPTION
 *  Draws the category301 screen category control area
 * PARAMETERS
 *  coordinates     [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void dm_category301_callback(dm_coordinates *coordinates)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SUBLCD_MMI_message_string)
    {
        S32 sw, sh, y, fh;

        SUBLCD_input_box.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(&SUBLCD_input_box);
        SUBLCD_input_box.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_set_font(SUBLCD_input_box.text_font);
        fh = get_multiline_inputbox_line_height_with_obj(&SUBLCD_input_box);
        y = (SUBLCD_input_box.n_lines * fh) + 4 + SUBLCD_input_box.text_y;
        gui_resize_multi_line_input_box(&SUBLCD_input_box, SUBLCD_input_box.width, y);
        gui_measure_string(SUBLCD_MMI_message_string, &sw, &sh);
        if (SUB_LCD_device_width - sw < 0)
        {
            gui_move_multi_line_input_box(&SUBLCD_input_box, 0, (SUB_LCD_device_height - SUBLCD_input_box.height) >> 1);
        }
        else
        {
            if (mmi_fe_get_r2l_state())
            {
                gui_move_multi_line_input_box(
                    &SUBLCD_input_box,
                    -((SUB_LCD_device_width - sw) >> 1),
                    (SUB_LCD_device_height - SUBLCD_input_box.height) >> 1);
            }
            else
            {
                gui_move_multi_line_input_box(
                    &SUBLCD_input_box,
                    (SUB_LCD_device_width - sw) >> 1,
                    (SUB_LCD_device_height - SUBLCD_input_box.height) >> 1);
            }
        }
        coordinates->s16Y = y;
        coordinates->s16Width = SUBLCD_input_box.width;
        coordinates->s16X = SUBLCD_input_box.x;
        coordinates->s16Height = 18;
        gui_show_multi_line_input_box(&SUBLCD_input_box);
    }
    else
    {
        coordinates->s16Y = (UI_device_height >> 1);
        coordinates->s16Width = 0;
        coordinates->s16X = 0;
        coordinates->s16Height = 0;
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory301Screen
 * DESCRIPTION
 *  Displays the category301 screen
 * PARAMETERS
 *  message             [IN]        Message string
 *  message_icon        [IN]        Message icon
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory301Screen(U8 *message, U16 message_icon, U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 l;
    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    

    gdi_layer_lock_frame_buffer();

    SUBLCD_MMI_message_string = (UI_string_type) message;

    if (message == 0)
    {
        SUBLCD_MMI_message_string = NULL;
    }
    else    /* message==0 */
    {
        l = gui_strlen(SUBLCD_MMI_message_string);
        gui_create_multi_line_input_box_set_buffer(
            &SUBLCD_input_box,
            0,
            20,
            UI_device_width,
            UI_device_height,
            SUBLCD_MMI_message_string,
            (l + 1) * ENCODING_LENGTH,
            (l + 1) * ENCODING_LENGTH,
            0);
        SUBLCD_input_box.text_gap = 0;
        SUBLCD_input_box.text_font = &MMI_small_font;

    #ifdef __MMI_KLG__
        SUBLCD_input_box.normal_text_color = UI_COLOR_WHITE;
    #else
        SUBLCD_input_box.normal_text_color = UI_COLOR_BLACK;
    #endif 

        SUBLCD_input_box.flags |=
            (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
             UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);

    }   /* message==0 */

    ShowSubLCDStatusIconsTitle();
    gdi_layer_unlock_frame_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory301Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    dm_register_sub_category_controlled_callback(dm_category301_callback);
    if (message_icon != 0)
    {
        dm_add_image(get_image(message_icon), NULL, NULL);
    }
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY301_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory301Screen
 * DESCRIPTION
 *  Exits the category301 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory301Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_reset();
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory302Screen
 * DESCRIPTION
 *  Redraws the category302 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory302Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();
    wgui_status_icon_bar_show_sublcd_background(0, 0, (UI_device_width - 1), (UI_device_height - 1), MMI_FALSE);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory302Screen
 * DESCRIPTION
 *  Displays the category302 screen  (Clears SUB LCD)
 * PARAMETERS
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory302Screen(U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    SUBLCD_ExitCategoryFunction = ExitCategory302Screen;
    SUBLCD_RedrawCategoryFunction = RedrawCategory302Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    RedrawCategory302Screen();

    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory302Screen
 * DESCRIPTION
 *  Exits the category302 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory302Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_category303_callback
 * DESCRIPTION
 *  draw control area callback
 * PARAMETERS
 *  coordinates     [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void dm_category303_callback(dm_coordinates *coordinates)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KLG__
    gdi_draw_line(0, 54, UI_device_width - 1, 54, GDI_COLOR_WHITE);
#else 
    gdi_draw_line(0, 54, UI_device_width - 1, 54, GDI_COLOR_BLACK);
#endif 

#ifdef __MMI_SUBLCD_SHOW_WORLD_CLOCK__

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(c);

    gui_measure_string(SUBLCD_MMI_message_string, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);

    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x + w, sub_LCD_dt_object1.date.y + sub_LCD_dt_object1.date.height + 2);
    }
    else
    {
        gui_move_text_cursor(x, sub_LCD_dt_object1.date.y + sub_LCD_dt_object1.date.height + 2);
    }

    gui_print_text(SUBLCD_MMI_message_string);

    gui_measure_string(SUBLCD_MMI_message_string1, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);

    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x + w, sub_LCD_dt_object2.time.y - (h));
    }
    else
    {
        gui_move_text_cursor(x, sub_LCD_dt_object2.time.y - (h));
    }

    gui_print_text(SUBLCD_MMI_message_string1);

    gdi_layer_pop_clip();
#endif /* __MMI_SUBLCD_SHOW_WORLD_CLOCK__ */ 

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory303Screen
 * DESCRIPTION
 *  Displays the category303 screen :- sub lcd screen display details of 2 cities on sublcd
 * PARAMETERS
 *  message1            [IN]        String of message1
 *  message2            [IN]        String of message2
 *  time_diff1          [IN]        Time difference1
 *  time_diff2          [IN]        Time difference2
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory303Screen(U8 *message1, U8 *message2, FLOAT time_diff1, FLOAT time_diff2, U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();
    set_sub_LCD_dt_date_hide_function(SUBLCD_screens_hide_date_time);
    set_sub_LCD_dt_time_hide_function(SUBLCD_screens_hide_date_time);

#ifdef __MMI_SUBLCD_SHOW_WORLD_CLOCK__
    dt_difference1 = time_diff1;
    dt_difference2 = time_diff2;
    SUBLCD_MMI_message_string = (UI_string_type) message1;
    SUBLCD_MMI_message_string1 = (UI_string_type) message2;
#endif /* __MMI_SUBLCD_SHOW_WORLD_CLOCK__ */ 

    set_dt_display(DT_SUBLCD_IDLE_SCREEN1);
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, 
        SUBLCD_screens_hide_status_icons);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    gdi_layer_unlock_frame_buffer();
    SUBLCD_ExitCategoryFunction = ExitCategory303Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    dm_register_sub_category_controlled_callback(dm_category303_callback);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY303_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory303Screen
 * DESCRIPTION
 *  Exits the category303 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory303Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_reset();
    close_sub_LCD_dt_display();
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory304Screen
 * DESCRIPTION
 *  Displays the category304 screen
 * PARAMETERS
 *  message_icon        [IN]        Message icon
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory304Screen(U16 message_icon, U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();

#ifdef __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
#else /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, 
        SUBLCD_screens_hide_status_icons);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
#endif /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 
    gdi_layer_unlock_frame_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory304Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    dm_add_image(get_image(message_icon), NULL, NULL);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY304_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory304Screen
 * DESCRIPTION
 *  Exits the category304 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory304Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_reset();
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  handle_category311_text_scroll
 * DESCRIPTION
 *  handle scrolling text on category311:- sub lcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_category311_text_scroll(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;

#ifdef __MMI_KLG__
    color bc = gui_color(255, 255, 255);
#else 
    color bc = gui_color(0, 0, 0);
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;

    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gui_set_text_color(bc);
    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));

    if (mmi_fe_get_r2l_state())
    {
        category311_text_offset_x += CATEGORY311_TEXT_SCROLL_SIZE;
        if ((category311_text_offset_x + CATEGORY311_TEXT_SCROLL_X) >=
            (category311_text_width + CATEGORY311_TEXT_SCROLL_GAP))
        {
            category311_text_offset_x = CATEGORY311_TEXT_SCROLL_X;
        }
    }
    else
    {
        category311_text_offset_x -= CATEGORY311_TEXT_SCROLL_SIZE;
        if ((category311_text_offset_x + category311_text_width + CATEGORY311_TEXT_SCROLL_GAP) <
            CATEGORY311_TEXT_SCROLL_X)
        {
            category311_text_offset_x = CATEGORY311_TEXT_SCROLL_X;
        }
    }

    /* 102604 MTK Calvin modified becuase Thai_14 font is higher than CATEGORY311_TEXT_SCROLL_Y by 3 */
#if defined(__MMI_LANG_THAI__)
    wgui_status_icon_bar_show_sublcd_background(
        0,
        14 /* one pixel lower than icon bar */ ,
        (UI_device_width - 1),
        (CATEGORY311_TEXT_SCROLL_Y + category311_text_height + 2),
        MMI_FALSE);
#else /* defined(__MMI_LANG_THAI__) */ 
    wgui_status_icon_bar_show_sublcd_background(
        0,
        CATEGORY311_TEXT_SCROLL_Y,
        (UI_device_width - 1),
        (CATEGORY311_TEXT_SCROLL_Y + category311_text_height - 1),
        MMI_FALSE);
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK Calvin end */

    gui_move_text_cursor(category311_text_offset_x, CATEGORY311_TEXT_SCROLL_Y);
    gui_print_text(SUBLCD_MMI_message_string);
    if ((category311_text_offset_x + category311_text_width + CATEGORY311_TEXT_SCROLL_GAP) < UI_device_width)
    {

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(
                category311_text_offset_x - (category311_text_width + CATEGORY311_TEXT_SCROLL_GAP),
                CATEGORY311_TEXT_SCROLL_Y);
        }
        else
        {
            gui_move_text_cursor(
                category311_text_offset_x + category311_text_width + CATEGORY311_TEXT_SCROLL_GAP,
                CATEGORY311_TEXT_SCROLL_Y);
        }

        gui_print_text(SUBLCD_MMI_message_string);
    }
    gdi_layer_pop_clip();

    gui_start_timer(CATEGORY311_TEXT_SCROLL_TIME, handle_category311_text_scroll);
    gdi_layer_blt_previous(
        0,
        CATEGORY311_TEXT_SCROLL_Y,
        UI_device_width - 1,
        CATEGORY311_TEXT_SCROLL_Y + category311_text_height - 1);

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_category311_callback
 * DESCRIPTION
 *  control area callback
 * PARAMETERS
 *  coordinates     [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void dm_category311_callback(dm_coordinates *coordinates)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SUBLCD_MMI_message_string)
    {
        color bc = gui_color(0, 0, 0);
        S32 w, x, y = CATEGORY311_TEXT_SCROLL_Y;

        gui_set_text_color(bc);
        gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
        gui_measure_string(SUBLCD_MMI_message_string, &w, &category311_text_height);
        if (w < UI_device_width)
        {
            x = (UI_device_width >> 1) - (w >> 1);
        }
        else
        {
            category311_text_width = w;
            x = category311_text_offset_x = CATEGORY311_TEXT_SCROLL_X;
            gui_start_timer(CATEGORY311_TEXT_SCROLL_WAIT, handle_category311_text_scroll);
        }

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x + SUBLCD_WIDTH - 1, y);
			category311_text_offset_x = SUBLCD_WIDTH - 1;
        }
        else
        {
            gui_move_text_cursor(x, y);
        }

        gui_print_text(SUBLCD_MMI_message_string);
        coordinates->s16X = UI_device_width >> 1;
        coordinates->s16Y = 40;
        coordinates->s16Width = 0;
        coordinates->s16Height = 0;
    }
    else
    {
        coordinates->s16X = UI_device_width >> 1;
        coordinates->s16Y = UI_device_height >> 1;
        coordinates->s16Width = 0;
        coordinates->s16Height = 0;
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory311Screen
 * DESCRIPTION
 *  Displays the category311 screen:- dispaly the mesage and icon on sublcd
 *  if text s longer than sublcd witdth then scroll text
 * PARAMETERS
 *  message             [IN]        Message string
 *  message_icon        [IN]        Message icon
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory311Screen(U8 *message, U16 message_icon, U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();

    SUBLCD_MMI_message_string = (UI_string_type) message;

    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, 
        SUBLCD_screens_hide_status_icons);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    gdi_layer_unlock_frame_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory311Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    dm_register_sub_category_controlled_callback(dm_category311_callback);
    dm_add_image(get_image(message_icon), NULL, NULL);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY311_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory311Screen
 * DESCRIPTION
 *  Exits the category311 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory311Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gui_cancel_timer(handle_category311_text_scroll);
    wgui_status_icon_bar_reset();
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}

#ifdef __MMI_SUB_WALLPAPER__


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_UpdateWallpaper
 * DESCRIPTION
 *  a function to update sublcd wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SUBLCD_UpdateWallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;
	gdi_handle src_layer_handle;
    GDI_RESULT ret = 0;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sublcd_wallpaper_layer == NULL || *sublcd_wallpaper_layer == GDI_ERROR_HANDLE)
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd_handle);
    if (act_lcd_handle != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }

    gdi_layer_push_and_set_active(*sublcd_wallpaper_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
	gdi_get_alpha_blending_source_layer(&src_layer_handle);
	gdi_set_alpha_blending_source_layer(*sublcd_wallpaper_layer);
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* stop previous animations, if any */
    if (sublcd_wallpaper_animation_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(sublcd_wallpaper_animation_handle);
        sublcd_wallpaper_animation_handle = GDI_ERROR_HANDLE;
    }

    /* from resource */
    if (idle_screen_wallpaper_sub_ID != 0)
    {
        gdi_image_draw_animation_id(
            cat312_image_x,
            cat312_image_y,
            idle_screen_wallpaper_sub_ID,
            &sublcd_wallpaper_animation_handle);
    }
    /* from file */
    else
    {

        gdi_image_get_dimension_file((S8*) idle_screen_wallpaper_sub_name, &cat312_image_width, &cat312_image_height);
        /* the image is larger than screen size */
        if (cat312_image_width > SUB_LCD_device_width || cat312_image_height > SUB_LCD_device_height)
        {
            S32 resized_offset_x;
            S32 resized_offset_y;
            S32 resized_width;
            S32 resized_height;
            //U16 img_type;

            gdi_image_util_fit_bbox(
                SUB_LCD_device_width,
                SUB_LCD_device_height,
                cat312_image_width,
                cat312_image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            //img_type = gdi_image_get_type_from_file((PS8) idle_screen_wallpaper_sub_name);
            /* only resize jpg files !! */
            /* will take lots ot time to resize images of other format */
            /* for images of other formats, try to set center alignment */
            //if (img_type == GDI_IMAGE_TYPE_JPG_FILE)
            {
                cat312_image_x = resized_offset_x;
                cat312_image_y = resized_offset_y;
                ret = gdi_image_draw_resized_file(
                        resized_offset_x,
                        resized_offset_y,
                        resized_width,
                        resized_height,
                        (PS8) idle_screen_wallpaper_sub_name);
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
#endif
        }
        else
        {
            ret = gdi_image_draw_animation_file((SUB_LCD_device_width - cat312_image_width) >> 1, (SUB_LCD_device_height - cat312_image_height) >> 1, idle_screen_wallpaper_sub_name, &sublcd_wallpaper_animation_handle);      /* diamond, 2005/05/09 for sub-LCD wallpaper */
        }
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt(*sublcd_wallpaper_layer, sublcd_base_layer, 0, 0, 0, 0, UI_device_width - 1, UI_device_height - 1);
	gdi_set_alpha_blending_source_layer(src_layer_handle);
    if (act_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    /* diamond, 2005/06/09 bad file callback */
    if (ret < 0 && ret != GDI_GIF_ERR_OUT_OF_CLIP_REGION && ret != GDI_BMP_ERR_OUT_OF_CLIP_REGION)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "SUBLCD_UpdateWallpaper():[$$$]GDI_RESULT:%d[$$$]\n", ret);
        PhnsetWallpaperSubBadFileCallBack(0);
        gdi_image_draw_animation_id(
            cat312_image_x,
            cat312_image_y,
            idle_screen_wallpaper_sub_ID,
            &sublcd_wallpaper_animation_handle);
    }
    /* end, diamond */
}


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_SetIdleScreenWallpaperID
 * DESCRIPTION
 *  set idle screen wallpaper ID
 * PARAMETERS
 *  image_ID        [IN]        Image ID
 * RETURNS
 *  void
 *****************************************************************************/
void SUBLCD_SetIdleScreenWallpaperID(U16 image_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idle_screen_wallpaper_sub_ID = image_ID;
    gdi_image_get_dimension_id(idle_screen_wallpaper_sub_ID, &cat312_image_width, &cat312_image_height);
    cat312_image_x = (SUB_LCD_device_width >> 1) - (cat312_image_width >> 1);
    cat312_image_y = (SUB_LCD_device_height >> 1) - (cat312_image_height >> 1);
}


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_SetIdleScreenWallpaperName
 * DESCRIPTION
 *  set Idel screen wallpapaer name
 * PARAMETERS
 *  name        [IN]        name of wallpaper
 * RETURNS
 *  void
 *****************************************************************************/
void SUBLCD_SetIdleScreenWallpaperName(UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idle_screen_wallpaper_sub_ID = 0;
    mmi_ucs2cpy(idle_screen_wallpaper_sub_name, (S8*) name);
    /* since image size is unknown, just set image_x, image_y to 0 */
    /* when display the image, we will calculate image_x, image_y */
    cat312_image_x = 0;
    cat312_image_y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  SUBLCD_CheckWallpaperFrameCount
 * DESCRIPTION
 *  to check if the image frame out of limit
 * PARAMETERS
 *  name        [IN]        Image path
 * RETURNS
 *  void
 *****************************************************************************/
BOOL SUBLCD_CheckWallpaperFrameCount(UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cat33_n_frames = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_gif_get_frame_count_file((S8*) name, &cat33_n_frames);
    if (cat33_n_frames > MAX_SUB_WALLPAPER_FRAME)
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
 *  cat312_hide_time_display
 * DESCRIPTION
 *  hide function of time display of analog/digital  clock
 * PARAMETERS
 *  x1      [IN]        Start x position
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void cat312_hide_time_display(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(sublcd_base_layer);
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  cat312_hide_status_icon_bar
 * DESCRIPTION
 *  hide function of status icon bar
 * PARAMETERS
 *  void
 *  S32(?)      [IN]        Y2      :- end y position
 * RETURNS
 *  void
 *****************************************************************************/
void cat312_hide_status_icon_bar(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_get_clip(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR,
        &x1,
        &y1,
        &x2,
        &y2);
    gdi_layer_push_and_set_active(sublcd_base_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(
        x1,
        y1,
        x2,
        y2,
        GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
#endif    
}
#endif /* __MMI_SUB_WALLPAPER__ */ 


void wgui_cat312_setinfo1(U8 *message)
{
#ifdef __MMI_SUBLCD__
    wgui_cat312_info1 = message ;
#endif
}


void wgui_cat312_setinfo2(U8 *message)
{
#ifdef __MMI_SUBLCD__
    wgui_cat312_info2 = message ;
#endif
}


void wgui_cat312_refresh_info(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    S32 dm_flag;
    dm_data_struct g_dm_data_temp_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();
    dm_get_main_lcd_data(&g_dm_data_temp_struct);
    dm_set_sub_lcd_active();

    gdi_draw_solid_rect(
         0, 
         WGUI_CAT312_STRING_Y, 
         UI_device_width - 1, 
         WGUI_CAT312_STRING_Y + WGUI_CAT312_STRING_HEIGHT - 1, 
         GDI_COLOR_TRANSPARENT);
    dm_change_string(0, (UI_string_type)wgui_cat312_info1,  &MMI_sublcd_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);
#ifdef __MMI_DUAL_SIM__
    gdi_draw_solid_rect(
         0, 
         WGUI_CAT312_STRING_Y + WGUI_CAT312_STRING_HEIGHT + 1, 
         UI_device_width - 1, 
         WGUI_CAT312_STRING_Y + (WGUI_CAT312_STRING_HEIGHT * 2) + 1 - 1, 
         GDI_COLOR_TRANSPARENT);
    dm_change_string(1, (UI_string_type)wgui_cat312_info2,  &MMI_sublcd_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);
#endif /* __MMI_DUAL_SIM__ */
    
gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
   dm_set_main_lcd_data(&g_dm_data_temp_struct);

#endif
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory312Screen
 * DESCRIPTION
 *  Displays the category312 screen:- show one city detail on sub lcd screen
 *  [1] STRING     message to be displayed
 *  [2]   MYTIME      time difference
 * PARAMETERS
 *  message             [IN]        Message string
 *  time_diff_312       [IN]        Time difference
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory312Screen(U8 *message, FLOAT time_diff_312, U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle src_layer_handle;
    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
#ifdef __MMI_SUB_WALLPAPER__
    GDI_RESULT create_sublcd_wallpaer_layer_fail = 1;
#endif 
#ifndef __MMI_SUB_WALLPAPER__
    GDI_HANDLE base_layer = GDI_ERROR_HANDLE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;
    gdi_get_alpha_blending_source_layer(&src_layer_handle);
#ifdef __MMI_SUB_WALLPAPER__
    if (SUBLCD_ExitCategoryFunction != ExitCategory312Screen)
#endif 
        SUBLCD_ExitCategoryFunction();

#ifdef __MMI_SUB_WALLPAPER__
    is_sub_idle_screen = MMI_TRUE;
#endif 

    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();

#ifdef __MMI_SUB_WALLPAPER__
    set_sub_LCD_dt_date_hide_function(cat312_hide_time_display);
    set_sub_LCD_dt_time_hide_function(cat312_hide_time_display);
#else /* __MMI_SUB_WALLPAPER__ */ 
    set_sub_LCD_dt_date_hide_function(SUBLCD_screens_hide_date_time);
    set_sub_LCD_dt_time_hide_function(SUBLCD_screens_hide_date_time);
#endif /* __MMI_SUB_WALLPAPER__ */ 

#ifdef __MMI_SUBLCD_SHOW_WORLD_CLOCK__
    dt_difference1 = time_diff_312;
    SUBLCD_MMI_message_string = (UI_string_type) message;
    dm_add_string((UI_string_type)message, &MMI_medium_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);
#else /* __MMI_SUBLCD_SHOW_WORLD_CLOCK__ */ 
#ifdef __MMI_DUAL_SIM__
    if(wgui_cat312_info1 != NULL)
        dm_add_string((UI_string_type)wgui_cat312_info1, &MMI_small_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);

    if(wgui_cat312_info2 != NULL)
        dm_add_string((UI_string_type)wgui_cat312_info2, &MMI_small_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);
#else
    dm_add_string((UI_string_type)wgui_cat312_info1, &MMI_small_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);
#endif /* __MMI_DUAL_SIM__ */ 
#endif /* __MMI_SUBLCD_SHOW_WORLD_CLOCK__ */ 

#if (defined __MMI_SUB_WALLPAPER__)
    {
        /* get base layer as skin layer */
        gdi_layer_get_base_handle(&sublcd_base_layer);

        if (sublcd_wallpaper_layer == NULL || *sublcd_wallpaper_layer == GDI_ERROR_HANDLE)
        {
            gdi_layer_get_base_handle(&sublcd_base_layer);
            gdi_layer_push_and_set_active(sublcd_base_layer);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            if (dm_create_layer_using_outside_memory(
                    0,
                    0,
                    UI_device_width,
                    UI_device_height,
                    &sublcd_wallpaper_layer,
                    (U8*) sub_wallpaper_buf,
                    (GDI_SUBLCD_WIDTH * GDI_SUBLCD_HEIGHT * GDI_SUBLCD_BIT_PER_PIXEL + 7)>>3,
                    DM_LAYER_BOTTOM) != GDI_LAYER_SUCCEED)
            {
                create_sublcd_wallpaer_layer_fail = 0;
            }
            MMI_ASSERT(create_sublcd_wallpaer_layer_fail);
            gdi_layer_push_and_set_active(*sublcd_wallpaper_layer);
	        gdi_set_alpha_blending_source_layer(*sublcd_wallpaper_layer);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            SUBLCD_UpdateWallpaper();
        }
    }
#endif /* (defined __MMI_SUB_WALLPAPER__) */ 

#ifdef __MMI_KLG__
    set_dt_display(DT_SUBLCD_IDLE_SCREEN4);
#else /* __MMI_KLG__ */ 
#ifdef __MMI_SUBLCD_L_TIME_M_DATE_1__
    set_dt_display(DT_SUBLCD_IDLE_SCREEN3);
#else 
    set_dt_display(DT_SUBLCD_IDLE_SCREEN2);
#endif 
#endif /* __MMI_KLG__ */ 

#ifdef __MMI_SUB_WALLPAPER__
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, 
        cat312_hide_status_icon_bar);
	wgui_status_icon_bar_set_alpha_blend_layer(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, *sublcd_wallpaper_layer);
	wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, sublcd_base_layer);
#else 
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, 
        SUBLCD_screens_hide_status_icons);
    gdi_layer_get_base_handle(&base_layer);
    wgui_status_icon_bar_set_alpha_blend_layer(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, base_layer);
	wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, base_layer);
#endif 
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    gdi_layer_unlock_frame_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory312Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY312_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT | DM_SUB_LCD_TRANSPARENT_BG;
#if !defined(__MMI_SUB_WALLPAPER__)
    dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND_COLOR;
#endif
    dm_sublcd_setup_data(&dm_data);
    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    dm_sublcd_redraw_category_screen();

    gdi_set_alpha_blending_source_layer(src_layer_handle);
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory312Screen
 * DESCRIPTION
 *  Exits the category312 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory312Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_reset();
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR,
        SUBLCD_screens_hide_status_icons);
    close_sub_LCD_dt_display();
#ifdef __MMI_SUB_WALLPAPER__
    is_sub_idle_screen = MMI_FALSE;
	sublcd_wallpaper_layer = NULL;
    gdi_layer_set_blt_layer(sublcd_base_layer, 0, 0, 0);
    if ( sublcd_wallpaper_animation_handle != GDI_ERROR_HANDLE )
    {
        gdi_image_stop_animation(sublcd_wallpaper_animation_handle);
        sublcd_wallpaper_animation_handle = GDI_ERROR_HANDLE;
    }
#endif /* __MMI_SUB_WALLPAPER__ */ 
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory313Screen
 * DESCRIPTION
 *  Displays the category313 screen
 * PARAMETERS
 *  message_icon        [IN]        Message icon
 *  history_buffer      [IN]        History Buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory313Screen(U16 message_icon, U8 *history_buffer)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!srv_clam_is_close())
    {
        return;
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);

    SUBLCD_ExitCategoryFunction = ExitCategory313Screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    dm_add_image(get_image(message_icon), NULL, NULL);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY313_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory313Screen
 * DESCRIPTION
 *  Exits the category313 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory313Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_rotate_180_sublcd
 * DESCRIPTION
 *  Draw rotate 180
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_rotate_180_sublcd(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value1, value2;
    U16 x1, y1, x2, y2;
    U32 counter = GDI_LAYER.act_rows * GDI_LAYER.act_pitch / 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (y1 = 0, y2 = GDI_LAYER.act_rows - 1; y1 < GDI_LAYER.act_rows; y1++, y2--)
    {
        for (x1 = 0, x2 = GDI_LAYER.act_pitch - 1; x1 < GDI_LAYER.act_pitch; x1++, x2--)
        {
            if ((counter--) == 0)
            {
                return;
            }
            GDI_SUBLCD_GET_BUFFER_PIXEL(x1, y1, value1);
            GDI_SUBLCD_GET_BUFFER_PIXEL(x2, y2, value2);
            GDI_SUBLCD_SET_BUFFER_PIXEL(x1, y1, !value2);
            GDI_SUBLCD_SET_BUFFER_PIXEL(x2, y2, !value1);
        }
    }
#endif /* __MMI_SUBLCD__ */ 
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  RedrawSubLCDAnalogClockScreen
 * DESCRIPTION
 *  redraw Sub LCD analog clock screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawSubLCDAnalogClockScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gdi_image_draw(0, 0, get_image(IMG_SUBLCD_ANALOG_CLOCK));
    wgui_clock_show_sub_lcd();
    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDAnalogClockScreen
 * DESCRIPTION
 *  Exit sub LCD analog clock screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDAnalogClockScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    close_sub_LCD_dt_display();
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDAnalogClockScreen
 * DESCRIPTION
 *  Show SubLCD analog clock screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDAnalogClockScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    analog_clock_initialize();
    set_dt_display(DT_SUBLCD_ANALOG_CLOCK);
    RedrawSubLCDAnalogClockScreen();
    SUBLCD_ExitCategoryFunction = ExitSubLCDAnalogClockScreen;
    SUBLCD_RedrawCategoryFunction = ExitSubLCDAnalogClockScreen;

    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory310Screen
 * DESCRIPTION
 *  Exit category 310 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory310Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_gui_in_cat310 = MMI_FALSE;
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    wgui_status_icon_bar_reset();
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
}

/******************************************************************
Function Name  :  ShowCategory310Screen ( (UI_string_type) string )
Memo        :  Show single string in sublcd ( center alignment vertically and horizontaly )
******************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory310Screen
 * DESCRIPTION
 *  Show category 310 screen
 * PARAMETERS
 *  string      [IN]        string to show
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory310Screen(UI_string_type string)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_gui_in_cat310 == MMI_TRUE)
    {
        return;
    }
    else
    {
        g_mmi_gui_in_cat310 = MMI_TRUE;
    }
    GDI_LOCK;

    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    dm_add_string(string, &MMI_medium_font, UI_COLOR_BLACK, UI_COLOR_WHITE, NULL);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY310_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    //dm_data.s32flags = DM_SUB_LCD_ROTATE_180;
	
    gdi_layer_unlock_frame_buffer();
    SUBLCD_ExitCategoryFunction = ExitCategory310Screen;
    SUBLCD_RedrawCategoryFunction = dm_sublcd_redraw_category_screen;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();
    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

    GDI_UNLOCK;

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDLogoString
 * DESCRIPTION
 *  Show SubLCD logo string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDLogoString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate314CategoryControlArea
 * DESCRIPTION
 *  redraw category 314 control area
 * PARAMETERS
 *  coordinate      [IN]     area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate314CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUB_WALLPAPER__
    SUBLCD_UpdateWallpaper();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory314Screen
 * DESCRIPTION
 *  Exit category 314 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory314Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER;
    MMI_fixed_list_menu.act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    MMI_fixed_list_menu.act_lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
    reset_fixed_list();
}


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory314KeyStateInd
 * DESCRIPTION
 *  Update category 314 key state 
 * PARAMETERS
 *  state       [IN]        key state
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateCategory314KeyStateInd(MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
    if (state)
    {
        MMI_title_icon = (PU8) get_image(IMG_GLOBAL_L30);
    }
    else
    {
        MMI_title_icon = NULL;
    }
    draw_title();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory314Screen
 * DESCRIPTION
 *  show category 314 screen
 * PARAMETERS
 *  title                       [IN]        Title string
 *  title_icon                  [IN]        Title icon ID
 *  number_of_items             [IN]        Total count of number
 *  list_of_items               [IN]        String list of items
 *  list_of_icons               [IN]        Icon list of items
 *  list_of_descriptions        [IN]        Description list of items
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory314Screen(
        U8 *title,
        U16 title_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 i;
    U8 h_flag;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    gdi_handle sub_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();

    dm_add_title((UI_string_type) title, get_image(0)); /* sublcd can't show title icon */

    wgui_fixed_list_create_icontext_menu(
        number_of_items,
        highlighted_item,
        0,
        MMI_CATEGORY314_ID,
        history_buffer);

    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);

    resize_fixed_icontext_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - 1,
        MMI_fixed_icontext_menuitem.height);

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER;

    gdi_layer_get_base_handle(&sub_handle);
    MMI_fixed_list_menu.act_layer_handle = sub_handle;
    MMI_fixed_list_menu.act_lcd_handle = GDI_LCD_SUB_LCD_HANDLE;
    wgui_fixed_list_begin_add_icontext_one_item();
    if (list_of_descriptions == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, (U8*) get_string(list_of_items[i]), wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
        }
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, (U8*) get_string(list_of_items[i]), wgui_get_list_menu_icon(i, list_of_icons[i]), list_of_descriptions[i]);
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();
    wgui_fixed_list_resize_icontext_menu(UI_device_width, UI_device_height - MMI_SUBLCD_TITLE_HEIGHT);

    gdi_layer_unlock_frame_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory314Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY314_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

}
/*****************************************************************************
 * FUNCTION
 *  ExitCategory315Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory315Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearHighlightHandler();
    //reset_softkey();
    //reset_fixed_list();
    //reset_menu_shortcut_handler();
    reset_dynamic_list();
    //reset_pop_up_descriptions();

    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER;
    MMI_fixed_list_menu.act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    MMI_fixed_list_menu.act_lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory315Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                       [?]         
 *  title_icon                  [IN]        
 *  number_of_items             [IN]        
 *  get_item_func               [IN]        
 *  get_hint_func               [IN]        
 *  highlighted_item            [IN]        
 *  disable_data_cache          [IN]        Whether caching of dynamic data is disabled
 *  flush_data_callback         [IN]        Callback function invoked before data is reloaded
 *  history_buffer              [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory315Screen(
        U8 *title,
        U16 title_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        MMI_BOOL disable_data_cache,
        void (*flush_data_callback) (void),
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
//    S32 i;
    U8 h_flag;
    GDI_HANDLE act_lcd = GDI_ERROR_HANDLE;
    gdi_handle sub_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction();
    gdi_lcd_get_active(&act_lcd);
    if (act_lcd != GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }    
    gdi_layer_lock_frame_buffer();

    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        disable_data_cache,
        flush_data_callback,
        0,
        MMI_CATEGORY315_ID,
        history_buffer);

    /* Title */
    dm_add_title((UI_string_type) title, get_image(title_icon));
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);
    /* List */
    wgui_dynamic_list_resize_icontext_menu(
        UI_device_width, UI_device_height - MMI_SUBLCD_TITLE_HEIGHT);
    resize_fixed_icontext_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - 1,
        MMI_fixed_icontext_menuitem.height);

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER;

    gdi_layer_get_base_handle(&sub_handle);
    MMI_fixed_list_menu.act_layer_handle = sub_handle;
    MMI_fixed_list_menu.act_lcd_handle = GDI_LCD_SUB_LCD_HANDLE;

    gdi_layer_unlock_frame_buffer();
	SUBLCD_ExitCategoryFunction = ExitCategory315Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY315_ID;
    dm_data.s32flags = DM_SUB_LCD_CONTEXT;
    dm_sublcd_setup_data(&dm_data);
    dm_sublcd_redraw_category_screen();

    if (act_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }

}

#ifdef __MMI_SUBLCD__
#ifdef __MMI_SUB_WALLPAPER__

/*****************************************************************************
 * FUNCTION
 *  ShowCategory315Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
gdi_handle wgui_sublcd_wallpaper_layer(void)
{
    if(sublcd_wallpaper_layer != NULL)
        return *sublcd_wallpaper_layer;
    else
        return GDI_ERROR_HANDLE;
}
#endif
#endif

#endif /* __MMI_SUBLCD__ */ 


