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
 *  gui_clock.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  clock related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 28 2011 helena.li
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
 * 01 07 2011 helena.li
 * removed!
 * .
 *
 * 12 14 2010 helena.li
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
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 *******************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

#include "MMI_features.h"
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "gui_theme_struct.h"

#include "App_datetime.h"
#include "gui_typedef.h"

#ifndef __GUI_CLOCK_H__
#define __GUI_CLOCK_H__

#define max(a,b)        (((a) > (b)) ? (a) : (b))

#define min(a,b)        (((a) < (b)) ? (a) : (b))

#define GUI_CLOCK_SUB_ANALOG_CLOCK_HOURS_HAND_LENGTH      (SUB_LCD_DEVICE_WIDTH/4)
#define GUI_CLOCK_SUB_ANALOG_CLOCK_MINUTES_HAND_LENGTH    (SUB_ANALOG_CLOCK_HOURS_HAND_LENGTH+4)
#define GUI_CLOCK_SUB_ANALOG_CLOCK_SECONDS_HAND_LENGTH    (SUB_ANALOG_CLOCK_HOURS_HAND_LENGTH+6)
#define GUI_CLOCK_SUB_ANALOG_CLOCK_DIAL_WIDTH             SUB_LCD_DEVICE_WIDTH
#define GUI_CLOCK_SUB_ANALOG_CLOCK_DIAL_HEIGHT            SUB_LCD_DEVICE_HEIGHT

#define GUI_CLOCK_AXIS_RADIUS   2

/* <group dom_clock_macro>
 *  if digital clock use image, gap of every image is 1 pixel */
#ifndef __COSMOS_MMI__
#define GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP           1
#else
#define GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP           0
#endif
/* <group dom_clock_macro>
 *  total five images, 00:00 */
#define GUI_CLOCK_DIGITAL_CLOCK_NUMBER_COUNT        4

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
/* <group dom_clock_variables>
 * analog's left top in sub lcd*/
extern S32 g_gui_clock_sub_lcd_analog_clock_dial_x;
extern S32 g_gui_clock_sub_lcd_analog_clock_dial_y;
/* <group dom_clock_variables>
 * analog's center coordinate in sub lcd*/
extern S32 g_gui_clock_sub_lcd_analog_clock_center_x;
/* <group dom_clock_variables> */
extern S32 g_gui_clock_sub_lcd_analog_clock_center_y;
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
/* <group dom_clock_struct> */
typedef struct
{
    S32 x,y;
    S32 width,height;
    void (*hide_callback) (S32 x1, S32 y1, S32 x2, S32 y2);/*hide function*/
    GDI_HANDLE target_layer;    /*target layer to display*/
    GDI_HANDLE abm_layer;    /* alpha blending layer of clock */
    GDI_HANDLE target_lcd;      /*target lcd to display*/
    applib_time_struct diff; /*record the difference between set-time and phone-time*/
    S32 time_compare;   /*difference between set-time and cur-time*/
    UI_font_type date_text_font;    /*font of date text*/
    UI_font_type time_text_font;    /*font of time text*/
    color date_text_color;              /*color of date text*/
    color date_text_border_color;/*border color of date text*/
    color time_text_color;             /*color of time text*/
    color time_text_border_color;/*border color of time text*/

    color analog_hand_hour_color;           /*color of hour hand*/
    color analog_hand_min_color;            /*color of minute hand*/
    color analog_axis_color;                    /*color of axis (not used)*/

    S32  gap_between_two_lines;         /*gap between date text and time text*/
    S32  gap_between_time_date_one_line;    /*gap between time and date in one line*/
    MMI_BOOL    border_enable;
    MMI_BOOL    on_idle;
    MMI_BOOL enable_update;
    MMI_BOOL active;      /*clock is active or not*/

    /*close callback function, when clock is closed by other app, it will call this function */
    void (*close_callback) (void); 
    /* post display callback function, it will be called when clock finish display */
    void (*post_display_callback) (S32 x1, S32 y1, S32 x2, S32 y2);

    gui_clock_type_enum type;   /*clock type*/
    gui_clock_digital_align_enum align_type; /* align type */
} gui_clock_struct;

extern UI_clock_theme *current_clock_theme;

extern void gui_clock_create(gui_clock_struct *c, S32 x, S32 y, S32 width, S32 height, gui_clock_type_enum clock_type);
extern void gui_clock_close(gui_clock_struct *c);
extern void gui_clock_show(gui_clock_struct *c);
extern MMI_BOOL gui_clock_update(gui_clock_struct *c);
extern void gui_clock_move(gui_clock_struct *c, S32 x, S32 y);
extern void gui_clock_resize(gui_clock_struct *c, S32 width, S32 height);
extern void gui_clock_set_time(gui_clock_struct *c, applib_time_struct newtime);
extern void gui_clock_get_time(gui_clock_struct *c, applib_time_struct *time);
extern void gui_clock_set_hide_function(gui_clock_struct *c, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_clock_set_close_callback (gui_clock_struct *c, FuncPtr f); 
extern void gui_clock_set_post_display_callback(
             gui_clock_struct *c,
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_clock_set_theme(gui_clock_struct *c, UI_clock_theme *t);
extern void gui_clock_set_current_theme(gui_clock_struct *c);

extern void gui_clock_set_analog_clock_hour_hand_color(gui_clock_struct *c, color new_color);
extern void gui_clock_set_analog_clock_min_hand_color(gui_clock_struct *c, color new_color);
extern void gui_clock_set_date_text_font(gui_clock_struct *c, UI_font_type new_font);
extern void gui_clock_set_date_text_color(gui_clock_struct *c, color new_color);
extern void gui_clock_set_date_text_border_color(gui_clock_struct *c, color new_color);
extern void gui_clock_set_time_text_font(gui_clock_struct *c, UI_font_type new_font);
extern void gui_clock_set_time_text_color(gui_clock_struct *c, color new_color);
extern void gui_clock_set_time_text_border_color (gui_clock_struct *c, color new_color);

extern void gui_clock_enable_update(gui_clock_struct *c, MMI_BOOL enable_update);

extern void gui_clock_set_gap_between_two_lines(gui_clock_struct *c, S32 new_gap);
extern void gui_clock_measure_time_text(gui_clock_struct *c, S32 *w, S32 *h, UI_font_type font);
extern void gui_clock_measure_date_text(gui_clock_struct *c, S32 *w, S32 *h, UI_font_type font);
extern void gui_clock_set_text_border_enable(gui_clock_struct *c, MMI_BOOL enable);
extern void gui_clock_set_on_idle(gui_clock_struct *c, MMI_BOOL on_idle);
extern void gui_clock_set_target_layer(gui_clock_struct *c, GDI_HANDLE target_layer);
extern void gui_clock_set_abm_layer(gui_clock_struct *c, GDI_HANDLE abm_layer);
extern void gdi_draw_antialiasing_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color);
extern void gui_clock_set_digital_align_type(gui_clock_struct *c, gui_clock_digital_align_enum type);
extern void gui_clock_measure_digital_clock(gui_clock_struct *c, S32 *w, S32 *h);
extern void gui_clock_measure_digital_small_clock(gui_clock_struct *c, S32 *w, S32 *h);
#endif /* __GUI_CLOCK_H__ */ 


