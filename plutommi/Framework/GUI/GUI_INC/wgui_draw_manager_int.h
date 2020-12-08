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
/* **** Copy Right Note ********* 
 *  Copyright Notice
 *  (c) PMT.
 *  All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 *******************************************************************************
 * Filename:
 * ---------
 * wgui_draw_manager_int.h
 *
 * Project:
 * --------
 * PDG2
 *
 * Description:
 * ------------
 * This file contains the prototypes for Draw Manager.
 * Author:
 * -------
 * 
 * -------
 *
 * ==============================================================================
 * HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __WGUI_DRAW_MANAGER_INT_H__
#define __WGUI_DRAW_MANAGER_INT_H__

#include "MMI_features.h"
#include "gui_data_types.h"
#include "wgui_draw_manager.h"

typedef enum
{
    DM_SMALL_SCREEN_FLATTEN_ON,         /* Flattening to keep the old screen in the main base layer. */
    DM_SMALL_SCREEN_FLATTEN_OFF,        /* No flattening to discard the old screen. */
    DM_SMALL_SCREEN_FLATTEN_FORCE_ON    /* Force flattening on. Used only when going back to a small screen in the history. */
} dm_small_screen_flatten_state_enum;

typedef struct
{
    dm_redraw_state_enum redraw_screen_main;
    U8 redraw_scr_directly;
    U8 redraw_scr_bg_flag;
    U8 lock_redraw_main;
    U8 exit_full_screen_on_exit;
    U8 is_context_reset;
#ifdef __MMI_SUBLCD__
    dm_redraw_state_enum redraw_screen_sub;
    U8 lock_redraw_sub;
#endif /* __MMI_SUBLCD__ */ 
    MMI_BOOL is_fixed_layer_mode;
    dm_small_screen_flatten_state_enum enable_small_screen_flatten; /* small screen flatten flag */
} dm_cntx_struct;

typedef struct
{
    GDI_HANDLE layer_handle;
    /* GDI_HANDLE           animation_handle; */
    U16 image_id;
    S8 *image_name;
    U8 is_used;
    MMI_BOOL scr_bg_layer_exist;
    S32 offset_x;
    S32 offset_y;
    U8 layer_opacity;
    S32 flags;//082906 scr_bg
} dm_scr_bg_cntx_struct;


typedef struct
{
    dm_coordinates coordinate;
    S16 s16X2;
    S16 s16Y2;
} dm_previous_control_coordinates_struct;


typedef struct
{
    S16 x;  /* Icons are offset from this position                */
    S16 y;  /* Icons are offset from this position                */
    S16 x1; /* Area occupied by the status bar: Used for hiding      */
    S16 y1; /* Area occupied by the status bar: Used for hiding      */
    S16 x2; /* Area occupied by the status bar: Used for hiding      */
    S16 y2; /* Area occupied by the status bar: Used for hiding      */
    S16 flags;
} dm_status_info_struct;

typedef struct
{
    dm_coordinates coordinate;
    S16 button_width;
} dm_buttonbar_info_struct;

typedef struct
{
    UI_string_type string;
    UI_font_type font;
    color text_color;
    color border_color;
    UI_filled_area back_fill;
} dm_string_data_struct;


typedef struct
{
    color line_color;
    dm_rectangle_fill_style fill_rectangle;
} dm_rectangle_data_struct;


typedef struct
{
    S16 x, y;
    S32 width, height;
    PU8 image;
    UI_string_type name;
    UI_filled_area *back_fill;
    gdi_handle image_handle;
    void (*blt_before_callback_ptr)(GDI_RESULT result);
    S32 image_size;
    U32 dyn_prop_flag;
    U8 image_type;
} dm_image_data_struct;


typedef struct
{
    S16 s16X;
    S16 s16Y;
    S16 s16width;
    S16 s16height;
    U16 x_space;
    U16 y_space;
    S32 Flags;
    MMI_BOOL is_in_aligned_area;
} dm_aligned_area_data_struct;

typedef struct
{
    dm_coordinates coordinate;
    S16 typ_timer_x;
    S16 typ_timer_y;
    S16 typ_milsec_x;
    S16 typ_milsec_y;
    S16 typ_history_height;
} dm_typical_stopwatch_info_struct;

typedef struct
{
    dm_coordinates coordinate;
    S16 nway_main_timer_x1;
    S16 nway_main_timer_y1;
    S16 nway_main_timer_x2;
    S16 nway_main_timer_y2;
    S16 nway_dialog_x1;
    S16 nway_dialog_y1;
    S16 nway_dialog_x2;
    S16 nway_dialog_y2;
    S16 separator_height;
} dm_nway_stopwatch_info_struct;

#ifdef __DM_PROGRESS_BAR_9_SLICE_BG_IMAGE__
typedef struct
{
    S16 x;
    S16 y;
    S16 width;
    S16 height;
    U16 value;
    color bar_color;
    U16 bg_image;
    U8  *progres_string;
} dm_percentage_bar_struct;
#else
typedef struct
{
    S16 x;
    S16 y;
    S16 width;
    S16 height;
    U16 value;
    color bar_color;
    U16 bg_image;
    U16 left_side_image;
    U16 right_side_image;
    U8  *progres_string;
} dm_percentage_bar_struct;
#endif

/*****************************************************************************
 * FUNCTION
 *  dm_get_status_icon_bar_coordinates
 * DESCRIPTION
 *  This function is used obtain the status icon bar coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_status_info          [IN/OUT]        Status bar coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
extern S16 *dm_get_status_icon_bar_coordinates(S16 *UICtrlAccessPtr_p, dm_status_info_struct *dm_status_info);

/*****************************************************************************
 * FUNCTION
 *  dm_get_button_bar_coordinates
 * DESCRIPTION
 *  This function is used obtain the button bar coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_buttonbar_info       [IN/OUT]        Button bar coordinate info.
 * RETURNS
 *  void
 *****************************************************************************/
extern S16 *dm_get_button_bar_coordinates(S16 *UICtrlAccessPtr_p, dm_buttonbar_info_struct *dm_status_info);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_title_coordinates
 * DESCRIPTION
 *  Reset function for the title coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_title_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_fixed_list_coordinates
 * DESCRIPTION
 *  Reset function for the fixed list coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_fixed_list_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_lsk_coordinates
 * DESCRIPTION
 *  Reset function for the lsk coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_lsk_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_csk_coordinates
 * DESCRIPTION
 *  Reset function for the csk coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_csk_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_rsk_coordinates
 * DESCRIPTION
 *  Reset function for the rsk coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_rsk_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_button_bar_coordinates
 * DESCRIPTION
 *  This function resets button bar to its original height.
 *  Reuired till all categories are moved to Draw Manager
 * PARAMETERS
 *  void
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_image_info_struct I  N/OUT image area coordinate info.(?)
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_button_bar_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_multitaps_coordinates
 * DESCRIPTION
 *  Reset function for the multitap coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_multitaps_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_reset_inline_fixed_list_coordinates
 * DESCRIPTION
 *  Reset function for the inline fixed list coordinates so that other category screens get the original values only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_reset_inline_fixed_list_coordinates(void);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_new_layer
 * DESCRIPTION
 *  This function is used setup a new layer
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_new_layer(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_circular_menu
 * DESCRIPTION
 *  This function is used setup the circular menu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_circular_menu(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_fixed_list
 * DESCRIPTION
 *  This function is used setup the fixed list based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_fixed_list(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_dynamic_list
 * DESCRIPTION
 *  This function is used setup the dynamic list based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_dynamic_list(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_dynamic_matrix
 * DESCRIPTION
 *  This function is used setup the dynamic matrx based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_dynamic_matrix(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_matrix_menu
 * DESCRIPTION
 *  This function is used setup the matrix menu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_matrix_menu(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_multiline_inputbox
 * DESCRIPTION
 *  This function is used setup the multiline inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_cat_scr_info         [?]             
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_multiline_inputbox(S16 **UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_ems_inputbox
 * DESCRIPTION
 *  This function is used setup the EMS inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_cat_scr_info         [?]             
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_ems_inputbox(S16 **UICtrlAccessPtr_p, dm_cat_scr_info_struct *dm_cat_scr_info);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_dialer_inputbox
 * DESCRIPTION
 *  This function is used setup the dialer inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_dialer_inputbox(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_singleline_inputbox
 * DESCRIPTION
 *  This function is used setup the singleline inputbox based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_singleline_inputbox(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_left_softkey
 * DESCRIPTION
 *  This function is used setup the left softkey based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_left_softkey(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_right_softkey
 * DESCRIPTION
 *  This function is used setup the right softkey based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_right_softkey(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_title
 * DESCRIPTION
 *  This function is used setup the title bar  based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_title(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_category_controlled_area
 * DESCRIPTION
 *  This function is used setup the category controlled area based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_category_controlled_area(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_status_icons
 * DESCRIPTION
 *  This function is used setup the status icons based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_status_icons(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_button_bar
 * DESCRIPTION
 *  This function is used setup the button bar based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_button_bar(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_inline_item
 * DESCRIPTION
 *  This function is used setup the inline items based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_inline_item(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set
 * DESCRIPTION
 *  This function is used setup the base control set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_base_control_set(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set2
 * DESCRIPTION
 *  This function is used setup the base control set 2 based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_base_control_set2(S16 **UICtrlAccessPtr_p);


extern S32 dm_setup_and_draw_base_control_submenu(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_base_control_set_common
 * DESCRIPTION
 *  This function is used setup the base control set submenu based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  _UICtrlAccessPtr            [IN]            
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_base_control_common(S16 **UICtrlAccessPtr_p);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_string
 * DESCRIPTION
 *  This function is used setup the string area set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_string(S16 **UICtrlAccessPtr_p, S32 index);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_image
 * DESCRIPTION
 *  This function is used setup the image area set based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_image(S16 **UICtrlAccessPtr_p, S32 index);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_slide_control
 * DESCRIPTION
 *  This function is used setup the slide control based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_slide_control(S16 **UICtrlAccessPtr_p, S32 index);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_aligned_area
 * DESCRIPTION
 *  This function is used setup the aligned area based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  control_set_ptr         [?]             
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_aligned_area(S16 **UICtrlAccessPtr_p, U8 *control_set_ptr);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_scroll_text
 * DESCRIPTION
 *  This function is used setup the popup background based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            
 *  *(?)
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_scroll_text(S16 **UICtrlAccessPtr_p, S32 index);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_button
 * DESCRIPTION
 *  This function is used setup the icon button based on the coordinate set and
 *  then draw it
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN/OUT]        It specifies the start position to take out the coordinates.
 *  index                   [IN]            Index of icon button array
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 dm_setup_and_draw_button(S16 **UICtrlAccessPtr_p, S32 index);

/*****************************************************************************
 * FUNCTION
 *  dm_setup_and_draw_panel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UICtrlAccessPtr_p       [IN]        
 *  count                   [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 dm_setup_and_draw_panel(S16 **UICtrlAccessPtr_p, S32 count);

/*****************************************************************************
 * FUNCTION
 *  dm_get_typical_stopwatch_coordinates
 * DESCRIPTION
 *  This function is used obtain the typical stopwatch control coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p               [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_typical_stopwatch_info       [?]             
 *  dm_calendar_info(?)             [IN/OUT]        Calendar control coordinate info.
 * RETURNS
 *  S16
 *****************************************************************************/
extern S16 *dm_get_typical_stopwatch_coordinates(
                S16 *UICtrlAccessPtr_p,
                dm_typical_stopwatch_info_struct *dm_typical_stopwatch_info);

/*****************************************************************************
 * FUNCTION
 *  dm_get_nway_stopwatch_coordinates
 * DESCRIPTION
 *  This function is used obtain the N Way stopwatch control coordinates.
 * PARAMETERS
 *  UICtrlAccessPtr_p           [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_nway_stopwatch_info      [?]             
 *  dm_calendar_info(?)         [IN/OUT]        Calendar control coordinate info.
 * RETURNS
 *  S16
 *****************************************************************************/
extern S16 *dm_get_nway_stopwatch_coordinates(
                S16 *UICtrlAccessPtr_p,
                dm_nway_stopwatch_info_struct *dm_nway_stopwatch_info);

/*****************************************************************************
 * FUNCTION
 *  dm_enable_fixed_layer_mode
 * DESCRIPTION
 *  This function is used to enable fixed layers mode(In which layers are not freed)
 * PARAMETERS
 *  MMI_BOOL		[IN]	is_enabled
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_enable_fixed_layer_mode(MMI_BOOL is_enabled);

/*****************************************************************************
 * FUNCTION
 *  dm_is_fixed_layer_mode_enabled
 * DESCRIPTION
 *  This function tells if fixed layer mode is enabled or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL dm_is_fixed_layer_mode_enabled(void);

#endif /*__WGUI_DRAW_MANAGER_INT_H__*/
