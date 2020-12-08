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
 *  gui_horizontal_selector.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  horizontal selector - UI component
 *  
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_HORIZONTAL_SELECTOR_H__
#define __GUI_HORIZONTAL_SELECTOR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_typedef.h"
#include "gui_themes.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/* displacement tolerated on tapping left/right arrows */
#define GUI_HORIZONTAL_SELECT_PEN_VALID_REGION          (5)
#define GUI_HORIZONTAL_SELECT_ICON_X_GAP                (3)
#define GUI_HORIZONTAL_SELECT_ICON_Y_GAP                (2)
#if defined(__MMI_MAINLCD_480X800__)
#define GUI_HORIZONTAL_SELECT_TEXT_X_GAP                (5)
#else
#define GUI_HORIZONTAL_SELECT_TEXT_X_GAP                (2)
#endif
#define GUI_HORIZONTAL_SELECT_COLOR_V_GAP               (7)
#define GUI_HORIZONTAL_SELECT_COLOR_H_GAP               (3)
#define GUI_HORIZONTAL_SELECT_COLOR_BORDER_WIDTH        (2)
#define GUI_HORIZONTAL_SELECT_SINGLE_COLOR_WIDTH        (10)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern UI_horizontal_select_theme *current_horizontal_select_theme;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void gui_horizontal_select_set_current_theme(gui_horizontal_select_struct *m);
extern void gui_horizontal_select_set_theme(
                gui_horizontal_select_struct *m, 
                UI_horizontal_select_theme *t);
extern void gui_horizontal_select_create(
                gui_horizontal_select_struct *m, 
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height, 
                U32 flag, 
                S32 highlight_index,
                void (*highlight_callback)(S32 index),
                gui_horizontal_select_item_struct *items, 
                S32 n_item);
extern void gui_horizontal_select_resize(
                gui_horizontal_select_struct *m, 
                S32 width, 
                S32 height);
extern void gui_horizontal_select_move(gui_horizontal_select_struct *m, S32 x, S32 y);
extern MMI_BOOL gui_horizontal_select_left_key_down_handler(gui_horizontal_select_struct *m);
extern MMI_BOOL gui_horizontal_select_left_key_up_handler(gui_horizontal_select_struct *m);
extern MMI_BOOL gui_horizontal_select_right_key_down_handler(gui_horizontal_select_struct *m);
extern MMI_BOOL gui_horizontal_select_right_key_up_handler(gui_horizontal_select_struct *m);
extern void gui_horizontal_select_register_key_handler(void);
extern MMI_BOOL gui_horizontal_select_goto_item(gui_horizontal_select_struct *m, S32 i);
extern MMI_BOOL gui_horizontal_select_goto_next_item(gui_horizontal_select_struct *m);
extern MMI_BOOL gui_horizontal_select_goto_previous_item(gui_horizontal_select_struct *m);
extern MMI_BOOL gui_horizontal_select_goto_first_item(gui_horizontal_select_struct *m);
extern MMI_BOOL gui_horizontal_select_goto_last_item(gui_horizontal_select_struct *m);
extern void gui_horizontal_select_register_get_data_callback(
                gui_horizontal_select_struct *m, 
                void (*get_prev_callback)(gui_horizontal_select_item_struct *item),
                void (*get_current_callback)(gui_horizontal_select_item_struct *item), 
                void (*get_next_callback)(gui_horizontal_select_item_struct *item));
extern void gui_horizontal_select_show(gui_horizontal_select_struct *m);
extern void gui_horizontal_select_register_hide_callback(
                gui_horizontal_select_struct *m,
                void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_horizontal_select_close(gui_horizontal_select_struct *m);
extern void gui_horizontal_select_get_history(
                gui_horizontal_select_struct *m, 
                gui_horizontal_select_history_struct *h);
extern void gui_horizontal_select_set_history(
                gui_horizontal_select_struct *m, 
                gui_horizontal_select_history_struct *h);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL gui_horizontal_select_translate_pen_event(
                    gui_horizontal_select_struct *m,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_horizontal_select_pen_enum *select_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __GUI_HORIZONTAL_SELECTOR_H__ */ 


