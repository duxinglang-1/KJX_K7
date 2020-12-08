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

/*****************************************************************************
 * Filename:
 * ---------
 *  wgui_fixed_menus.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  fixed menu external interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_FIXED_MENUS_H__
#define __WGUI_FIXED_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_typedef.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_fixed_menus.h"
#include "gui_config.h"
#include "gui_effect_oem.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/* The number of menu item pointers is limited to MAX_SUB_MENUS. */
#define MAX_FIXED_MENU_ITEM_POINTERS   LIMIT_MENU_ITEM_NUMBER(100)

/* 
 * circular 3D menu 
 */
#define WGUI_CM3D_MAX_ITEMS             16
#define WGUI_CM3D_N_ITEM_IMAGES         3
#define WGUI_CM3D_N_COMMON_IMAGES       4
#define WGUI_CM3D_N_DISPLAYED_ITEMS     7


/*
 * techno main menu
 */
#define BACKGROUND_FRAMES               5
#define FIRST_FRAME                     0
#define LAST_FRAME                      (BACKGROUND_FRAMES - 1)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * techno main menu
 */
typedef struct _MMTechno_image_position
{
    S32 x;
    S32 y;
} MMTechno_image_position;

typedef struct _MMTechno_animo_menu
{
    PU8 item_image;
    MMTechno_image_position *item_position;
} MMTechno_animo_menu;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern fixed_list_menu MMI_fixed_list_menu;


extern fixed_matrix_menu MMI_fixed_matrix_menu;

extern PreKeyHandler g_gui_list_pre_key_handler;


#if ENABLE_CIRCULAR_3D_MENU
extern UI_string_type wgui_CM3D_items[];
extern PU8 wgui_CM3D_images[];
extern PU8 wgui_CM3D_common_images[];
extern S32 wgui_CM3D_n_items;
extern UI_3D_circular_menu wgui_CM3D_menu;
#endif /* ENABLE_CIRCULAR_3D_MENU */

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * fixed list menu
 */
extern void create_fixed_list(void);
extern void plain_fixed_list(void);
extern void normal_fixed_list(void);
extern void register_hide_fixed_list(void (*f) (void));
extern void move_fixed_list(S32 x, S32 y);
extern void show_fixed_list(void);
extern void redraw_fixed_list(void);
extern void register_fixed_list_highlight_handler(void (*f) (S32 item_index));
extern void register_fixed_list_unhighlight_handler(void (*f) (S32 item_index));
extern void clear_fixed_list_highlight_handler(void);
extern void fixed_list_goto_previous_item(void);
extern void fixed_list_goto_next_item(void);
extern void fixed_list_goto_home(void);
extern void fixed_list_goto_end(void);
extern void fixed_list_goto_previous_page(void);
extern void fixed_list_goto_next_page(void);
extern void fixed_list_goto_item(S32 item_index);
extern void fixed_list_goto_item_no_redraw(S32 item_index);
extern void fixed_list_goto_item_push_first(S32 item_index);
extern void register_fixed_list_shortcut_handler(void);
extern void fixed_list_measure(S32 *width, S32 *height);
extern void resize_fixed_list(S32 width, S32 height);
extern void move_fixed_list(S32 x, S32 y);
extern void register_fixed_list_keys(void);
#if 0
/* under construction !*/
#endif
#define reset_fixed_list reset_asyncdynamic_list
void wgui_list_begin_add_one_item(void);
extern void fixed_list_disable_looping(void);
extern void fixed_list_enable_looping(void);
extern void wgui_list_menu_disable_access_by_shortcut(void);
extern void wgui_list_menu_enable_access_by_shortcut(void);
extern void wgui_list_menu_show_empty_label_if_needed(void);
extern void show_fixed_list_specified_item(S32 item_index);
extern void disable_fixed_list_show_empty(void);
extern void reset_fixed_list_show_empty(void);

//extern void fixed_list_shortcut_handle(S32 index);
#define fixed_list_shortcut_handle fixed_list_goto_item
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
extern void fixed_list_shortcut_handle_with_SSK(S32 index);
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */
extern void wgui_list_menu_disable_scrollbar_drag(MMI_BOOL disable);

/* 
 * fixed matrix menu
 */
extern void (*resize_fixed_matrix_menuitems) (S32 item_width, S32 item_height);

extern void create_fixed_matrix(void);
extern void move_fixed_matrix(S32 x, S32 y);
extern void show_fixed_matrix(void);
extern void configure_fixed_matrix(S32 item_width, S32 item_height, S32 n_columns, S32 n_rows);
extern void register_fixed_matrix_highlight_handler(void (*f) (S32 item_index));
extern void clear_fixed_matrix_highlight_handler(void);
extern void fixed_matrix_goto_previous_item(void);
extern void fixed_matrix_goto_next_item(void);
extern void fixed_matrix_goto_previous_column(void);
extern void fixed_matrix_goto_next_column(void);
extern void fixed_matrix_goto_previous_row(void);
extern void fixed_matrix_goto_next_row(void);
extern void fixed_matrix_goto_home(void);
extern void fixed_matrix_goto_end(void);
extern void fixed_matrix_goto_previous_page(void);
extern void fixed_matrix_goto_next_page(void);
extern void fixed_matrix_goto_item(S32 item_index);
extern void fixed_matrix_goto_item_no_redraw(S32 item_index);
extern void register_fixed_matrix_shortcut_handler(void);
extern void fixed_matrix_measure(S32 *width, S32 *height);
extern void resize_fixed_matrix(S32 width, S32 height);
extern void move_fixed_matrix(S32 x, S32 y);
extern void register_fixed_matrix_keys(void);
extern void reset_fixed_matrix(void);
extern void reset_fixed_matrix_col_rows(void);
extern MMI_BOOL gui_list_check_goto_item(void);
extern void gui_list_goto_item_common(U32 direction);
extern void clear_menu_highlight_handler(void* m);
/*
 * circular 3D menu
 */
#if ENABLE_CIRCULAR_3D_MENU
extern void show_circular_3d_menu(void);
extern void create_circular_3d_menu(S32 n_items, MMI_ID_TYPE *items, MMI_ID_TYPE *images);
extern void register_circular_3d_menu_keys(void);
extern void register_rotate_menu_keys(void);    /* 111904 Calvin added for ROTATE mainmenu */
extern void register_circular_3d_highlight_handler(void (*f) (S32 item_index));
extern void circular_3d_menu_goto_item_no_redraw(S32 item_index);
extern void circular_3d_menu_next(void);
extern void circular_3d_menu_previous(void);
extern void circular_3d_menu_goto_item(S32 item_index);
extern void register_3d_menu_shortcut_handler(void);
extern void move_circular_3d_menu(S32 s32X, S32 s32Y);
extern void resize_circular_3d_menu(S32 s32Width, S32 s32Height);
#endif /* ENABLE_CIRCULAR_3D_MENU */ 


#endif /* __WGUI_FIXED_MENUS_H__ */ 


