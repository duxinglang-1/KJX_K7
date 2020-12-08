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
 *  gui_scrollbars_post_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Scrollbars - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_SCROLLBARS_POST_OEM_H__
#define __GUI_SCROLLBARS_POST_OEM_H__

#include "gui_scrollbars.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"

#if defined(UI_SCROLLBAR_STYLE_9)
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE9       3
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE9   3
#define GUI_SCROLLBAR_ARROW_GAP_STYLE9                  3
#define GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9          1
#endif /* defined(UI_SCROLLBAR_STYLE_9) */

#if defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_WIDER_STYLE_7)
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE7       5
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE7   15
#define GUI_SCROLLBAR_ARROW_GAP_STYLE7                  3
#endif /* defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_WIDER_STYLE_7) */

#if defined(UI_SCROLLBAR_STYLE_8)
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE8       5
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE8   15
#define GUI_SCROLLBAR_ARROW_GAP_STYLE8                  3
#endif /* defined(UI_SCROLLBAR_STYLE_8) */

#if defined(UI_SCROLLBAR_STYLE_6) || defined(UI_SCROLLBAR_WIDER_STYLE_6)

#define GUI_SCROLLBAR_STYLE4_GAP_STYLE6                 1
#define GUI_SCROLLBAR_ALPHA_STYLE6                      50

#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE6       5

#define GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6           2

#define GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE6         1

#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE6   15

/* Spacing of arrow and icon border */
#define GUI_SCROLLBAR_ARROW_GAP_STYLE6                  3
/* 
* In current design, 176x220 use 14-pixel scrollbar. 240x320 use 16-pixel scrollbar 
* There is only 10 graident colors inside 16-pixel scrollbar.
* GUI_SCROLLBAR_NUM_GRADIENT_COLOR=16 is pretty enough for normal use.
*/
#define GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE6         16

#define GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE6     160
#define GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS_STYLE6     120

#define GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE6    120
#define GUI_SCROLLBAR_MIN_GRADIENT_SATURATION_STYLE6    80

#define GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6                4
#define GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6      200
#define GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6      80
#define GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_SATURATION_STYLE6     240
#define GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_SATURATION_STYLE6     180

#define GUI_SCROLLBAR_NUM_INDICATOR_GRADIENT_STYLE6                 3
#define GUI_SCROLLBAR_MAX_INDICATOR_GRADIENT_LIGHTNESS_STYLE6       180
#define GUI_SCROLLBAR_MIN_INDICATOR_GRADIENT_LIGHTNESS_STYLE6       120
#define GUI_SCROLLBAR_MAX_INDICATOR_GRADIENT_SATURATION_STYLE6      200
#define GUI_SCROLLBAR_MIN_INDICATOR_GRADIENT_SATURATION_STYLE6      100

#endif /* defined(UI_SCROLLBAR_STYLE_6) || defined(UI_SCROLLBAR_WIDER_STYLE_6) */

#if defined(UI_SCROLLBAR_STYLE_5) || defined(UI_SCROLLBAR_WIDER_STYLE_5)

#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE5       5
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE5   15
#define GUI_SCROLLBAR_ARROW_GAP_STYLE5                  3

#endif /* defined(UI_SCROLLBAR_STYLE_5) || defined(UI_SCROLLBAR_WIDER_STYLE_5) */

#if defined(UI_SCROLLBAR_STYLE_4) || defined(UI_SCROLLBAR_WIDER_STYLE_4)

#define GUI_SCROLLBAR_STYLE4_GAP_STYLE4                 1
#define GUI_SCROLLBAR_ALPHA_STYLE4                      50

#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE4       5

#define GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4           2

#define GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4         1

#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE4   15

/* Spacing of arrow and icon border */
#define GUI_SCROLLBAR_ARROW_GAP_STYLE4                  3
/* 
* In current design, 176x220 use 14-pixel scrollbar. 240x320 use 16-pixel scrollbar 
* There is only 10 graident colors inside 16-pixel scrollbar.
* GUI_SCROLLBAR_NUM_GRADIENT_COLOR=16 is pretty enough for normal use.
*/
#define GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE4         3

#define GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE4     220
#define GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS_STYLE4     180

#define GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE4    220
#define GUI_SCROLLBAR_MIN_GRADIENT_SATURATION_STYLE4    180

#endif /* defined(UI_SCROLLBAR_STYLE_4) || defined(UI_SCROLLBAR_WIDER_STYLE_4) */

#if defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_WIDER_STYLE_3)

#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE3       5
#define GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE3   15

/* Minimum height of scroll button to have 3 marker lines */
#define GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3_STYLE3     30
/* Minimum height of scroll button to have 2 marker lines */
#define GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2_STYLE3     20
#define GUI_SCROLLBAR_MARK_WIDTH_STYLE3                 6

/* Spacing of arrow and icon border */
#define GUI_SCROLLBAR_ARROW_GAP_STYLE3                  3

/* 
 *Only GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL and GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL
 * use theme colors.
 */

#define GUI_SCROLLBAR_ARROW_SATURATION_STYLE3           200     /* large value */
#define GUI_SCROLLBAR_ARROW_LIGHTNESS_STYLE3            140     /* small value */

/* 
 * In current design, 176x220 use 14-pixel scrollbar. 240x320 use 16-pixel scrollbar 
 * There is only 10 graident colors inside 16-pixel scrollbar.
 * GUI_SCROLLBAR_NUM_GRADIENT_COLOR=16 is pretty enough for normal use.
 */
#define GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3         16

#define GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE3    230
#define GUI_SCROLLBAR_MIN_GRADIENT_SATURATION_STYLE3    160
#define GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE3     210
#define GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS_STYLE3     160

#define GUI_SCROLLBAR_LIGHT_SATURATION_STYLE3           200     /* < GUI_SCROLLBAR_MAX_GRADIENT_SATURATION */
#define GUI_SCROLLBAR_LIGHT_LIGHTNESS_STYLE3            230     /* > GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS */
#define GUI_SCROLLBAR_MEDIUM_SATURATION_STYLE3          180
#define GUI_SCROLLBAR_MEDIUM_LIGHTNESS_STYLE3           175
#define GUI_SCROLLBAR_DARK_SATURATION_STYLE3            150
#define GUI_SCROLLBAR_DARK_LIGHTNESS_STYLE3             145
#define GUI_SCROLLBAR_BORDER_SATURATION_STYLE3          250     /* large value */
#define GUI_SCROLLBAR_BORDER_LIGHTNESS_STYLE3           120     /* small value */

#endif /* defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_WIDER_STYLE_3) */

#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_WIDER_STYLE_2)
#define GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE2       5
#endif /* defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_WIDER_STYLE_2) */

#if defined(UI_SCROLLBAR_STYLE_1) || defined(UI_SCROLLBAR_WIDER_STYLE_1)
extern void gui_horizontal_scrollbar_redraw_button_style_1(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_1(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_1(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_1(vertical_scrollbar *v);
#endif

#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_WIDER_STYLE_2)
extern void gui_horizontal_scrollbar_redraw_button_style_2(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_2(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_2(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_2(vertical_scrollbar *v);
extern S32 gui_scrollbar_get_button_min_size_style_2(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_WIDER_STYLE_3)
extern void gui_horizontal_scrollbar_redraw_button_style_3(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_3(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_3(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_3(vertical_scrollbar *v);
extern S32 gui_scrollbar_get_button_min_size_style_3(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_4) || defined(UI_SCROLLBAR_WIDER_STYLE_4)
extern void gui_horizontal_scrollbar_redraw_button_style_4(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_4(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_4(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_4(vertical_scrollbar *v);
extern S32 gui_scrollbar_get_button_min_size_style_4(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_5) || defined(UI_SCROLLBAR_WIDER_STYLE_5)
extern void gui_horizontal_scrollbar_redraw_button_style_5(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_5(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_5(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_5(vertical_scrollbar *v);
extern S32 gui_scrollbar_get_button_min_size_style_5(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_6) || defined(UI_SCROLLBAR_WIDER_STYLE_6)
extern void gui_horizontal_scrollbar_redraw_button_style_6(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_horizontal_scrollbar_style_6(horizontal_scrollbar *v);
extern void gui_vertical_scrollbar_redraw_button_style_6(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_show_vertical_scrollbar_style_6(vertical_scrollbar *v);
extern S32 gui_scrollbar_get_button_min_size_style_6(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_8)
extern void gui_show_horizontal_scrollbar_style_VFR(horizontal_scrollbar *v);
extern void gui_show_vertical_scrollbar_style_VFR(vertical_scrollbar *v);
extern void gui_horizontal_scrollbar_redraw_button_style_VFR(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_vertical_scrollbar_redraw_button_style_VFR(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern S32 gui_scrollbar_get_button_min_size_style_8(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_WIDER_STYLE_7)
extern void gui_show_horizontal_scrollbar_style_7(horizontal_scrollbar *v);
extern void gui_show_vertical_scrollbar_style_7(vertical_scrollbar *v);
extern void gui_horizontal_scrollbar_redraw_button_style_7(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_vertical_scrollbar_redraw_button_style_7(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern S32 gui_scrollbar_get_button_min_size_style_7(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

#if defined(UI_SCROLLBAR_STYLE_9) 
extern void gui_show_horizontal_scrollbar_style_9(horizontal_scrollbar *v);
extern void gui_show_vertical_scrollbar_style_9(vertical_scrollbar *v);
extern void gui_horizontal_scrollbar_redraw_button_style_9(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern void gui_vertical_scrollbar_redraw_button_style_9(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed);
extern S32 gui_scrollbar_get_button_min_size_style_9(gui_scrollbar_buttton_enum type, S32 bar_width);
#endif

extern gdi_handle gui_vertical_scrollbar_setup_target_lcd_and_layer(vertical_scrollbar *v);
extern void gui_vertical_scrollbar_restore_target_lcd_and_layer(vertical_scrollbar *v, gdi_handle old_lcd_handle);
extern gdi_handle gui_horizontal_scrollbar_setup_target_lcd_and_layer(horizontal_scrollbar *h);
extern void gui_horizontal_scrollbar_restore_target_lcd_and_layer(horizontal_scrollbar *h, gdi_handle old_lcd_handle);

#endif /* __GUI_SCROLLBARS_POST_OEM_H__ */


