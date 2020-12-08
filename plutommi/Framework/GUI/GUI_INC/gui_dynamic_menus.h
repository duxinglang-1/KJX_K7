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
 * Filename:
 * ---------
 *  gui_dynamic_menus.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  In order to use limited memory (size decided in compile-time) to load 
 *  unlimited items (size decide in run-time) to a category screen, a 
 *  modification in MMI for dynamic item loading is required as the following.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef __GUI_DYNAMIC_MENUS_H__
#define __GUI_DYNAMIC_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_fixed_menus.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "mmi_frm_input_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void gui_show_dynamic_list_menu_int(fixed_list_menu *m, gui_menu_type_enum menu_style);
extern void gui_show_dynamic_list_menu(fixed_list_menu *m);
extern void gui_show_dynamic_list_menu_no_draw(fixed_list_menu *m);

extern void switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item);

extern void gui_dynamic_list_menu_goto_item(fixed_list_menu *m, S32 i);
extern void gui_dynamic_list_menu_goto_next_item(fixed_list_menu *m);
extern void gui_dynamic_list_menu_goto_previous_item(fixed_list_menu *m);

extern void gui_show_dynamic_matrix_menu(fixed_matrix_menu * m);
extern void gui_show_dynamic_matrix_menu_specific_items(fixed_matrix_menu * m, S32 last_highlight);
extern void gui_dynamic_matrix_menu_goto_item(fixed_matrix_menu * m, S32 i);
extern void gui_dynamic_matrix_menu_goto_next_item(fixed_matrix_menu * m);
extern void gui_dynamic_matrix_menu_goto_next_row(fixed_matrix_menu * m);
extern void gui_dynamic_matrix_menu_goto_previous_item(fixed_matrix_menu * m);
extern void gui_dynamic_matrix_menu_goto_previous_row(fixed_matrix_menu * m);
extern void gui_dynamic_matrix_menu_goto_row(fixed_matrix_menu * m, S32 r);
extern void gui_dynamic_matrix_menu_locate_highlighted_item(fixed_matrix_menu * m);
extern void gui_dynamic_matrix_menu_locate_previous_item(fixed_matrix_menu *m);
extern void gui_dynamic_matrix_menu_locate_next_item(fixed_matrix_menu * m);

extern void gui_dynamic_list_menu_locate_highlighted_item(fixed_list_menu *m);
extern void gui_dynamic_list_menu_locate_previous_item(fixed_list_menu *m);
extern void gui_dynamic_list_menu_locate_next_item(fixed_list_menu *m);

extern void gui_dynamic_list_menu_switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item);
extern void gui_show_dynamic_list_menu_draw_bg(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f, MMI_BOOL show_scrollbar);
extern void gui_show_dynamic_list_menu_draw_items(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2, U8 disable_draw);

#ifdef __MMI_TOUCH_SCREEN__
extern void gui_dynamic_list_abort_scroll_timer(void);
extern void gui_dynamic_matrix_menu_set_pen_scroll_delay(fixed_matrix_menu *m, S32 delay_time);
extern BOOL gui_dynamic_list_menu_translate_pen_event(
                fixed_list_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_list_pen_enum *menu_event);
extern MMI_BOOL gui_dynamic_matrix_menu_translate_pen_event(
                fixed_matrix_menu * m, 
                mmi_pen_event_type_enum pen_event, 
                S16 x, 
                S16 y, 
                gui_matrix_pen_enum * menu_event);
extern MMI_BOOL gui_dynamic_list_menu_translate_pen_position(fixed_list_menu *m, S32 y, S32 *item_index);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __GUI_DYNAMIC_MENUS_H__ */ 


