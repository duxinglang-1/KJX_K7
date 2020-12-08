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
 *  wgui_inputs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Functions for editor.
 *
 *  Author:
 * -------
 *  Elvis Lin (MTK00560)
 *  Terry Yang (MTK00866)
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_inputs.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines header for Input objects
**********************************************************************************/

#ifndef __WGUI_INPUTS_H__
#define __WGUI_INPUTS_H__

/* DOM-NOT_FOR_SDK-BEGIN */

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "wgui.h"
#include "gui_inputs.h"
#include "wgui_draw_manager.h"
#include "ImeGProt.h"

#ifdef __MMI_TOUCH_SCREEN__
//#include "kal_non_specific_general_types.h"
//#include "mmi_frm_gprot.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 

    #include "MMI_features.h"
    #include "mmi_frm_input_gprot.h"
    #include "mmi_clipboard_gprot.h"
    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    
    #include "custom_hw_default.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 


/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#define MAX_MULTITAPS         12  /* Maximum number of multitaps */
#elif defined(__MMI_MULTITAP_BANGLA_SPEC__) 
#define MAX_MULTITAPS         12
#else
#define MAX_MULTITAPS         10
#endif
#ifdef __MMI_MULTITAP_THAI__
#define MAX_MULTITAPS_THAI       MAX_MULTITAPS
#endif 

#define  UI_MULTI_LINE_INIT_SCROLL           2000
#define  UI_MULTI_LINE_SCROLL_TIMEOUT        500

#define WGUI_SCROLL_LINE_BY_LINE         0
#define WGUI_SCROLL_PAGE_BY_PAGE         1
#define WGUI_AUTO_SCROLL_ON           1
#define WGUI_AUTO_SCROLL_OFF          0

#define COMPLETE_PERCENTAGE_SCALE            100

#define WGUI_MAX_SCROLL_TIME              5

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)

#define WGUI_PAGING_SCROLL_LINE_BY_LINE         0
#define WGUI_PAGING_SCROLL_PAGE_BY_PAGE         1

#define WGUI_PAGING_AUTO_SCROLL_ON           1
#define WGUI_PAGING_AUTO_SCROLL_OFF          0

#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 

#define WGUI_INPUTS_STYLE_DEFAULT               -1

#define WGUI_INPUTS_DRV_TIME_UNIT                10                                               /* HW(unit : 10ms ) */                      
#define WGUI_INPUTS_KPD_REPEAT_PERIOD            (50 * WGUI_INPUTS_DRV_TIME_UNIT)                 /* Keypad repeat period */
#define WGUI_INPUTS_TP_REPEAT_PERIOD             (MMI_PEN_REPEAT_TIME * WGUI_INPUTS_DRV_TIME_UNIT)  /* Keypad repeat period */
#define WGUI_INPUTS_MAX_REPEAT_COUNT             10                                               /* We speed up when reach certain repeat period */
#define WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME  100                                              /* Normal speed (100ms per char) */
#define WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME  50                                               /* Fastest speed (50ms per char) */

#define WGUI_INPUTS_ADJUST_VIEW_OFFSET       20

/* Clipboard max characters */
#define WGUI_INPUTS_CLIPBOARD_MAX_SIZE       MMI_CLIPBOARD_MAX_SIZE

//////////////////////////////////////////////////////////////////////////////
/// NEED TO REMOVE!!!
//////////////////////////////////////////////////////////////////////////////
#define set_current_input_box_type                      wgui_inputs_set_current_input_box_type
#define clear_multitap_key_handlers                     wgui_inputs_multitap_clear_key_handlers
#define wgui_setup_multitap_functions                   wgui_inputs_multitap_setup_functions
#define wgui_reset_multitap                             wgui_inputs_multitap_reset
#define wgui_stop_multitap                              wgui_inputs_multitap_stop
#define mmi_direct_input_from_tst_module                wgui_inputs_direct_input_from_tst_module
#define wgui_is_r2l_display                             wgui_inputs_is_r2l_display
#define Register_pound_key_buffer_flush_test_function   wgui_inputs_register_pound_key_buffer_flush_test_function
#define redraw_input_mode_only                          wgui_inputs_redraw_input_mode_only
#define wgui_setup_input_information                    wgui_inputs_setup_input_information
#define wgui_input_information_background               wgui_inputs_input_information_background
#define wgui_hide_input_information_bar                 wgui_inputs_hide_input_information_bar
#define wgui_show_input_mode_internal                   wgui_inputs_show_input_mode_internal
#define wgui_show_input_mode                            wgui_inputs_show_input_mode
#define wgui_redraw_input_information_background        wgui_inputs_redraw_input_information_background
#define wgui_input_box_to_gb_len                        wgui_inputs_ucs2_to_gb_len
#define RegisterInputBoxValidationFunction              wgui_inputs_register_validation_func
#define RegisterInputBoxNotEmptyFunction                wgui_inputs_register_not_empty_func
#define RegisterInputBoxEmptyFunction                   wgui_inputs_register_empty_func
#define GetInputBoxUCS2Count                            wgui_inputs_get_ucs2_count
#define GetInputBoxExtendedGSMCount                     wgui_inputs_get_ext_gsm_count
#define SetInputboxLSKFunction                          wgui_inputs_set_LSK_func
#define SetInputboxLSKText                              wgui_inputs_set_LSK_text
/* slim_2_2 */ //#define create_singleline_inputbox                      wgui_inputs_sl_create
#define create_singleline_inputbox_set_buffer           wgui_inputs_sl_create_set_buffer
#define show_singleline_inputbox                        wgui_inputs_sl_show
#define wgui_singleline_inputbox_end_frame              wgui_inputs_sl_end_frame
#define redraw_singleline_inputbox                      wgui_inputs_sl_redraw
#define singleline_inputbox_multitap_input              wgui_inputs_sl_multitap_input
#define singleline_inputbox_multitap_input_complete     wgui_inputs_sl_multitap_input_complete
#define singleline_inputbox_direct_input                wgui_inputs_sl_direct_input
#define singleline_inputbox_direct_input_no_draw        wgui_inputs_sl_direct_input_no_draw
#define singleline_inputbox_delete_character            wgui_inputs_sl_delete_character
#define singleline_inputbox_delete_character_no_draw    wgui_inputs_sl_delete_character_no_draw
#define singleline_inputbox_previous_character          wgui_inputs_sl_previous_character
#define singleline_inputbox_next_character              wgui_inputs_sl_next_character
#define singleline_inputbox_toggle_insert_mode          wgui_inputs_sl_toggle_insert_mode
#define singleline_inputbox_delete_current_character    wgui_inputs_sl_delete_current_character
#define singleline_inputbox_delete_all_characters       wgui_inputs_sl_delete_all_characters
#define singleline_inputbox_handle_key_down             wgui_inputs_sl_handle_key_down
#define singleline_inputbox_key_handler                 wgui_inputs_sl_key_handler
#define register_singleline_inputbox_keys               wgui_inputs_sl_register_keys
#define set_singleline_inputbox_mask                    wgui_inputs_sl_set_mask
#define reset_singleline_inputbox                       wgui_inputs_sl_reset
#define get_singleline_inputbox_display_status          wgui_inputs_sl_get_display_status
#define resize_singleline_inputbox                      wgui_inputs_sl_resize
#define resize_single_line_input_box_fix                wgui_inputs_sl_resize_fix
#define move_singleline_inputbox                        wgui_inputs_sl_move
#define register_singleline_inputbox_input_callback     wgui_inputs_sl_register_input_callback
#define register_singleline_inputbox_navigate_callback  wgui_inputs_sl_register_navigate_callback
/* slim_2_2 */ //#define change_singleline_inputbox_content              wgui_inputs_sl_change_content
#define singleline_inputbox_empty                       wgui_inputs_sl_is_empty
#define wgui_redraw_singleline_input_box_remaining_characters_display wgui_inputs_sl_redraw_remaining_characters_display
#define wgui_redraw_singleline_input_information_bar    wgui_inputs_sl_redraw_information_bar
#define set_singleline_inputbox_category_history        wgui_inputs_sl_set_category_history
#define get_singleline_inputbox_category_history        wgui_inputs_sl_get_category_history
#define wgui_handle_singleline_inputbox_right_softkey_down          wgui_inputs_sl_handle_right_softkey_down
#define wgui_handle_singleline_inputbox_right_softkey_up            wgui_inputs_sl_handle_right_softkey_up
#define wgui_register_singleline_inputbox_handle_right_softkey_up   wgui_inputs_sl_register_handle_right_softkey_up
#define wgui_register_singleline_inputbox_handle_clear_key_up       wgui_inputs_sl_register_handle_clear_key_up
#define wgui_handle_singleline_inputbox_right_softkey_long_press    wgui_inputs_sl_handle_right_softkey_long_press
#define wgui_handle_singleline_inputbox_input           wgui_inputs_sl_handle_input
#define wgui_handle_singleline_inputbox_navigate        wgui_inputs_sl_handle_navigate
#define wgui_singleline_inputbox_validation_callback    wgui_inputs_sl_validation_callback
#define wgui_singleline_inputbox_get_UCS2_count         wgui_inputs_sl_get_ucs2_count
#define wgui_singleline_inputbox_get_GSM_ext_count      wgui_inputs_sl_get_ext_gsm_count
#define wgui_set_singleline_RSK                         wgui_inputs_sl_set_RSK
#define wgui_setup_singleline_inputbox                  wgui_inputs_sl_setup
#define wgui_close_singleline_inputbox                  wgui_inputs_sl_close
#define register_multiline_inputbox_input_callback      wgui_inputs_ml_register_input_callback
#define register_multiline_inputbox_navigate_callback   wgui_inputs_ml_register_navigate_callback
#define register_multiline_inputbox_validation_callback             wgui_inputs_ml_register_validation_callback
/* slim_2_2 */ //#define create_multiline_inputbox                       wgui_inputs_ml_create
#define create_multiline_inputbox_set_buffer            wgui_inputs_ml_create_set_buffer
#define create_multiline_inputbox_set_buffer_no_text_reset          wgui_inputs_ml_create_set_buffer_no_text_reset
#define resize_multiline_inputbox_fit                   wgui_inputs_ml_resize_fit
#define resize_multiline_inputbox                       wgui_inputs_ml_resize
#define move_multiline_inputbox                         wgui_inputs_ml_move
#define show_multiline_inputbox                         wgui_inputs_ml_show
#define show_multiline_inputbox_no_draw                 wgui_inputs_ml_show_no_draw
#define wgui_multiline_inputbox_end_frame               wgui_inputs_ml_end_frame
#define redraw_multiline_inputbox                       wgui_inputs_ml_redraw
#define multiline_inputbox_multitap_input               wgui_inputs_ml_multitap_input
#define multiline_inputbox_multitap_input_complete      wgui_inputs_ml_multitap_input_complete
#define multiline_inputbox_direct_input                 wgui_inputs_ml_direct_input
#define multiline_inputbox_direct_input_no_draw         wgui_inputs_ml_direct_input_no_draw
#define multiline_inputbox_direct_input_no_LF_check     wgui_inputs_ml_direct_input_no_LF_check
#define multiline_inputbox_delete_character             wgui_inputs_ml_delete_character
#define multiline_inputbox_delete_character_no_draw     wgui_inputs_ml_delete_character_no_draw
#define multiline_inputbox_previous_character           wgui_inputs_ml_previous_character
#define multiline_inputbox_next_character               wgui_inputs_ml_next_character
#define multiline_inputbox_delete_all_characters        wgui_inputs_ml_delete_all_characters
#define get_multiline_input_box                         wgui_inputs_ml_is_inline
#define multiline_inputbox_vertical_scroll              wgui_inputs_ml_vertical_scroll
#define multiline_inputbox_previous_line                wgui_inputs_ml_previous_line
#define multiline_inscreen_inputbox_previous_line       wgui_inputs_ml_inline_previous_line
#define multiline_inputbox_next_line                    wgui_inputs_ml_next_line
#define multiline_inscreen_inputbox_next_line           wgui_inputs_ml_inline_next_line
#define multiline_inputbox_home                         wgui_inputs_ml_home
#define multiline_inputbox_end                          wgui_inputs_ml_end
#define multiline_inputbox_previous_page                wgui_inputs_ml_previous_page
#define multiline_inputbox_next_page                    wgui_inputs_ml_next_page
#define multiline_inputbox_toggle_insert_mode           wgui_inputs_ml_toggle_insert_mode
#define multiline_inputbox_delete_current_character     wgui_inputs_ml_delete_current_character
#define multiline_WCSS_inputbox_alphabetic_keyboard_input_handler   wgui_inputs_ml_wcss_alphabetic_keyboard_input_handler
#define multiline_inputbox_key_handler                  wgui_inputs_ml_key_handler
#define register_multiline_inputbox_keys                wgui_inputs_ml_register_keys
#define register_inscreen_multiline_inputbox_keys       wgui_inputs_ml_inline_register_keys
#define multiline_inputbox_viewer_key_handler           wgui_inputs_ml_viewer_key_handler
#define register_multiline_inputbox_viewer_keys         wgui_inputs_ml_register_viewer_keys
#define wgui_multiline_inputbox_previous_hilite         wgui_inputs_ml_previous_hilite
#define wgui_multiline_inputbox_next_hilite             wgui_inputs_ml_next_hilite
#define register_multiline_inputbox_hilite_keys         wgui_inputs_ml_register_hilite_keys
#ifdef __MMI_TOUCH_SCREEN__
#define wgui_multiline_inputbox_hilite_pen_down_handler wgui_inputs_ml_hilite_pen_down_handler
#define register_multiline_inputbox_hilite_pen_event_handler        wgui_inputs_ml_register_hilite_pen_event_handler
#endif /* __MMI_TOUCH_SCREEN__ */ 
#define set_multiline_inputbox_mask                     wgui_inputs_ml_set_mask
#define reset_multiline_inputbox                        wgui_inputs_ml_reset
#define reset_multiline_inputbox_vertical_scroll        wgui_inputs_ml_reset_vertical_scroll
#define multiline_inputbox_empty                        wgui_inputs_ml_is_empty
#define multiline_inputbox_length                       wgui_inputs_ml_get_length
#define get_multiline_inputbox_line_height              wgui_inputs_ml_get_line_height
#define get_multiline_inputbox_display_status           wgui_inputs_ml_get_display_status
#define get_multiline_inputbox_height                   wgui_inputs_ml_get_height
#define get_multiline_inputbox_line_height_with_obj     wgui_inputs_ml_get_line_height_with_obj
#define is_multiline_inputbox_in_view_mode              wgui_inputs_ml_is_in_view_mode
#define wgui_config_general_multiline_icon_handler      wgui_inputs_ml_config_general_icon_handler
#define wgui_reset_general_multiline_icon_handler       wgui_inputs_ml_reset_general_icon_handler
#define wgui_general_multiline_icon_handler             wgui_inputs_ml_general_icon_handler
#define wgui_set_multiline_inputbox_register_up_down_key_funcptr    wgui_inputs_ml_set_register_up_down_key_funcptr
#define wgui_reset_multiline_inputbox_register_up_down_key_funcptr  wgui_inputs_ml_reset_register_up_down_key_funcptr
#define wgui_multiline_inputbox_register_infobar_callback           wgui_inputs_ml_register_infobar_callback
#define wgui_multiline_inputbox_register_change_event_handler       wgui_inputs_ml_register_change_event_handler
#define wgui_set_multiline_inputbox_text_color          wgui_inputs_ml_set_text_color
#define wgui_multi_line_clear_pen_down_flag             wgui_inputs_ml_clear_pen_down_flag
#define wgui_multi_line_set_pen_down_flag               wgui_inputs_ml_set_pen_down_flag
#define wgui_multi_line_get_pen_down_flag               wgui_inputs_ml_get_pen_down_flag
#define set_multiline_inputbox_category_history         wgui_inputs_ml_set_category_history
#define get_multiline_inputbox_category_history         wgui_inputs_ml_get_category_history
#define set_multiline_inputbox_category_history_state   wgui_inputs_ml_set_category_history_state
#define get_multiline_inputbox_category_history_state   wgui_inputs_ml_get_category_history_state
#define wgui_redraw_remaining_characters_display_internal           wgui_inputs_ml_redraw_remaining_characters_display_internal
#define wgui_redraw_remaining_characters_display                    wgui_inputs_ml_redraw_remaining_characters_display
#define wgui_multiline_inputbox_show_current_input_method           wgui_inputs_ml_show_current_input_method
#define wgui_redraw_input_information_bar               wgui_inputs_ml_redraw_input_information_bar
#define wgui_handle_inputbox_right_softkey_down         wgui_inputs_ml_handle_right_softkey_down
#define wgui_handle_inputbox_right_softkey_up           wgui_inputs_ml_handle_right_softkey_up
#define wgui_register_inputbox_handle_right_softkey_up  wgui_inputs_ml_register_handle_right_softkey_up
#define wgui_register_inputbox_handle_clear_key_up      wgui_inputs_ml_register_handle_clear_key_up
#define wgui_handle_inputbox_right_softkey_long_press   wgui_inputs_ml_handle_right_softkey_long_press
#define wgui_handle_inputbox_input                      wgui_inputs_ml_handle_input
#define wgui_handle_inputbox_navigate                   wgui_inputs_ml_handle_navigate
#define change_multiline_information_bar_input_method   wgui_inputs_ml_change_information_bar_input_method
#define wgui_show_inputbox                              wgui_inputs_ml_show_with_information_bar
#define wgui_multiline_inputbox_hide_text_content       wgui_inputs_ml_hide_text_content
#define wgui_multiline_inputbox_validation_callback     wgui_inputs_ml_validation_callback
#define wgui_multiline_inputbox_get_UCS2_count          wgui_inputs_ml_get_ucs2_count
#define wgui_multiline_inputbox_get_GSM_ext_count       wgui_inputs_ml_get_ext_gsm_count
#define wgui_multiline_inputbox_test_change_input_mode  wgui_inputs_ml_test_change_input_mode
#define wgui_setup_inputbox_ext                         wgui_inputs_ml_setup_ext
#define wgui_setup_inputbox                             wgui_inputs_ml_setup
#define wgui_set_RSK                                    wgui_inputs_ml_set_RSK
#define wgui_close_inputbox                             wgui_inputs_ml_close
#define wgui_multiline_setup_inputbox                   wgui_inputs_ml_inline_setup
#define wgui_multiline_inputbox_append_string           wgui_inputs_ml_append_string
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#define wgui_paging_multiline_inputbox_previous_page                wgui_inputs_ml_paging_previous_page
#define wgui_paging_multiline_inputbox_next_page                    wgui_inputs_ml_paging_next_page
#define wgui_paging_multiline_inputbox_next_line_in_paging_scroll   wgui_inputs_ml_paging_next_line_in_paging_scroll
#define wgui_paging_multiline_inputbox_next_line_in_paging          wgui_inputs_ml_paging_next_line_in_paging
#define wgui_paging_multiline_inputbox_set_stop_scroll_callback     wgui_inputs_ml_paging_set_stop_scroll_callback
#define wgui_paging_multiline_inputbox_previous_line_in_paging      wgui_inputs_ml_paging_previous_line_in_paging  
#define wgui_paging_multiline_inputbox_calculate_percentage         wgui_inputs_ml_paging_calculate_percentage
#define wgui_paging_start_text_scroll                               wgui_inputs_paging_start_text_scroll
#define wgui_paging_multiline_set_scroll_info                       wgui_inputs_ml_paging_set_scroll_info
#define wgui_paging_stop_text_scroll                                wgui_inputs_ml_paging_stop_text_scroll
#define wgui_paging_multiline_start_text_scroll                     wgui_inputs_ml_paging_start_text_scroll
#define wgui_paging_multiline_set_font                              wgui_inputs_ml_paging_set_font
#define wgui_paging_multiline_set_get_page_callback                 wgui_inputs_ml_paging_set_get_page_callback
#define wgui_paging_set_scrollbar_range                             wgui_inputs_ml_paging_set_scrollbar_range
#define wgui_paging_multiline_set_percentage                        wgui_inputs_ml_paging_set_percentage
#define wgui_paging_multiline_translate_to_text_percentage          wgui_inputs_ml_paging_translate_to_text_percentage
#define wgui_paging_multiline_check_to_end                          wgui_inputs_ml_paging_check_to_end
#define wgui_paging_multiline_check_cursor_to_end                   wgui_inputs_ml_paging_check_cursor_to_end
#define wgui_paging_multiline_clear_last_percentage                 wgui_inputs_ml_paging_clear_last_percentage
#define wgui_paging_multiline_set_page                              wgui_inputs_ml_paging_set_page
#define wgui_paging_set_show_percentage_flag                        wgui_inputs_ml_paging_set_show_percentage_flag
#define wgui_paging_reset_show_percentage_flag                      wgui_inputs_ml_paging_reset_show_percentage_flag
#define wgui_dm_set_multiline_data                                  wgui_inputs_ml_set_dm_data
#define wgui_paging_multiline_inputbox_set_percentage_scale         wgui_inputs_ml_paging_set_percentage_scale
#define wgui_paging_multiline_inputbox_set_percentage_callback      wgui_inputs_ml_paging_set_percentage_callback
#define wgui_paging_highlight_search_string                         wgui_inputs_ml_paging_highlight_search_string
#define wgui_paging_multiline_get_current_page                      wgui_inputs_ml_paging_get_current_page
#define wgui_paging_multiline_get_visible_count                     wgui_inputs_ml_get_visible_count
#define wgui_paging_jump_to_end                                     wgui_inputs_ml_paging_jump_to_end
#define wgui_paging_set_page_info                                   wgui_inputs_ml_paging_set_page_info  
#ifdef __MMI_TOUCH_SCREEN__
#define wgui_paging_multiline_set_scroll_data_cb                    wgui_inputs_ml_paging_set_scroll_data_callback
#define wgui_paging_multiline_inputbox_set_percentage_scale_TS      wgui_inputs_ml_paging_set_percentage_scale_TS
#define wgui_paging_multiline_key_maaping_TS    wgui_inputs_ml_paging_key_mapping_TS
#define wgui_paging_get_data_during_scrolling   wgui_inputs_ml_paging_get_data_during_scrolling
#define wgui_paging_set_full_screen_flag        wgui_inputs_ml_paging_set_full_screen_flag
#define wgui_paging_pen_up_hdlr                 wgui_inputs_ml_paging_pen_up_handler
#define wgui_paging_pen_down_hdlr               wgui_inputs_ml_paging_pen_down_handler
#define wgui_paging_pen_repeat_hdlr             wgui_inputs_ml_paging_pen_repeat_handler
#define wgui_paging_pen_move_hdlr               wgui_inputs_ml_paging_pen_move_handler
#define wgui_paging_set_async_pen_callback      wgui_inputs_ml_paging_set_async_pen_callback
#define wgui_paging_timer_callback_forward      wgui_inputs_ml_paging_timer_forward_callback
#define wgui_paging_timer_callback_backward     wgui_inputs_ml_paging_timer_backward_callback
#define wgui_paging_timer_callback_pen_move     wgui_inputs_ml_paging_timer_pen_move_callback
#define wgui_paging_timer_callback_pen_up       wgui_inputs_ml_paging_timer_pen_up_callback
#define wgui_paging_virtual_keypad_callback     wgui_inputs_ml_paging_virtual_keypad_callback
#define wgui_paging_clear_pen_timer_handler     wgui_inputs_ml_paging_clear_pen_timer_handler
#endif /* defined(__MMI_TOUCH_SCREEN__) */
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
#define wgui_color_buffer_create_reader                 wgui_inputs_color_buffer_create_reader
#define wgui_color_buffer_read_stripped_text            wgui_inputs_color_buffer_read_stripped_text
#define wgui_color_buffer_create_writer                 wgui_inputs_color_buffer_create_write
#define wgui_color_buffer_get_space_for_write           wgui_inputs_color_buffer_get_space_for_write
#define wgui_color_buffer_write_char                    wgui_inputs_color_buffer_write_char
#define wgui_color_buffer_write_2char                   wgui_inputs_color_buffer_write_2char
#define wgui_color_buffer_write_3char                   wgui_inputs_color_buffer_write_3char
#define wgui_color_buffer_write_4char                   wgui_inputs_color_buffer_write_4char
#define wgui_color_buffer_write_string                  wgui_inputs_color_buffer_write_string
/* slim_2_2 */ //#define create_dialer_inputbox                          wgui_inputs_dialer_create
#define create_dialer_inputbox_set_buffer               wgui_inputs_dialer_create_set_buffer
#define show_dialer_inputbox                            wgui_inputs_dialer_show
#define wgui_dialer_inputbox_end_frame                  wgui_inputs_dialer_end_frame
#define redraw_dialer_inputbox                          wgui_inputs_dialer_redraw
#define dialer_inputbox_handle_plus_key                 wgui_inputs_dialer_handle_plus_key
#define dialer_inputbox_multitap_input                  wgui_inputs_dialer_multitap_input
#define dialer_inputbox_multitap_input_complete         wgui_inputs_dialer_multitap_input_complete
#define dialer_inputbox_direct_input                    wgui_inputs_dialer_direct_input
#define dialer_inputbox_delete_character                wgui_inputs_dialer_delete_character
#define dialer_inputbox_previous_character              wgui_inputs_dialer_previous_character
#define dialer_inputbox_next_character                  wgui_inputs_dialer_next_character
#define dialer_inputbox_toggle_insert_mode              wgui_inputs_dialer_toggle_insert_mode
#define dialer_inputbox_delete_current_character        wgui_inputs_dialer_delete_current_character
#define dialer_inputbox_delete_all_characters           wgui_inputs_dialer_delete_all_characters
#define dialer_inputbox_alphabetic_keyboard_input_handler   wgui_inputs_dialer_alphabetic_keyboard_input_handler
#define dialer_inputbox_numeric_keyboard_input_handler      wgui_inputs_dialer_numeric_keyboard_input_handler
#define dialer_inputbox_next_line                       wgui_inputs_dialer_next_line
#define dialer_inputbox_prev_line                       wgui_inputs_dialer_previous_line
#define dialer_inputbox_key_handler                     wgui_inputs_dialer_key_handler
#define register_dialer_inputbox_keys                   wgui_inputs_dialer_register_keys
#define set_dialer_inputbox_mask                        wgui_inputs_dialer_set_mask
#define reset_dialer_inputbox                           wgui_inputs_dialer_reset
#define resize_dialer_inputbox                          wgui_inputs_dialer_resize
#define move_dialer_inputbox                            wgui_inputs_dialer_move
/* slim_2_2 */ //#define register_dialer_inputbox_input_callback         wgui_inputs_dialer_register_input_callback
/* slim_2_2 */ //#define register_dialer_inputbox_navigate_callback      wgui_inputs_dialer_register_navigate_callback
#define dialer_input_box_change_callback                wgui_inputs_dialer_change_callback
#define dialer_inputbox_handle_multitap_complete        wgui_inputs_dialer_handle_multitap_complete
#define dialer_inputbox_handle_key_down                 wgui_inputs_dialer_handle_key_down
#define dialer_inputbox_complete_multitap_star_key      wgui_inputs_dialer_multitap_complete_star_key
#define dialer_inputbox_handle_multitap_star_key_down   wgui_inputs_dialer_multitap_handle_star_key_down
#define dialer_inputbox_handle_multitap_star_key_up     wgui_inputs_dialer_multitap_handle_star_key_up
#define dialer_inputbox_complete_multitap_zero_key      wgui_inputs_dialer_multitap_complete_zero_key
#define dialer_inputbox_handle_multitap_zero_key_down   wgui_inputs_dialer_multitap_handle_zero_key_down
#define dialer_inputbox_handle_multitap_zero_key_up     wgui_inputs_dialer_multitap_handle_zero_key_up
#define dialer_inputbox_handle_zero_key_long_press      wgui_inputs_dialer_handle_zero_key_long_press
#define dialer_inputbox_handle_hash_key_down            wgui_inputs_dialer_handle_hash_key_down
#define dialer_inputbox_handle_star_key_down            wgui_inputs_dialer_handle_star_key_down
#define wgui_handle_dialer_inputbox_right_softkey_down  wgui_inputs_dialer_handle_right_softkey_down
#define wgui_handle_dialer_inputbox_right_softkey_up    wgui_inputs_dialer_handle_right_softkey_up
#define wgui_register_dialer_inputbox_handle_right_softkey_up   wgui_inputs_dialer_register_handle_right_softkey_up
#define wgui_register_dialer_inputbox_handle_clear_key_up       wgui_inputs_dialer_register_handle_clear_key_up
#define wgui_handle_dialer_inputbox_input               wgui_inputs_dialer_handle_input
#define register_dialer_inputbox_dialer_keys            wgui_inputs_dialer_register_dialer_keys
#define wgui_dialer_validation_callback                 wgui_inputs_dialer_validation_callback
#define wgui_handle_dialer_inputbox_right_softkey_long_press    wgui_inputs_dialer_handle_right_softkey_long_press
#define wgui_dialer_inputbox_set_border                 wgui_inputs_dialer_set_border
#define wgui_setup_dialer_inputbox                      wgui_inputs_dialer_setup
#define close_dialer_inputbox                           wgui_inputs_dialer_close
#ifdef __MMI_TOUCH_DIAL_SCREEN__
#define setup_dialing_keypad                            wgui_inputs_dialer_setup_dialing_keypad
#define show_dialing_screen                             wgui_inputs_dialer_show_dialing_screen
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 
//////////////////////////////////////////////////////////////////////////////
/// NEED TO REMOVE!!!
//////////////////////////////////////////////////////////////////////////////

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)

#ifdef __MMI_TOUCH_SCREEN__
	typedef void (*get_data_during_scrolling_cb)(S32 page_id,PU8 buffer);
#endif

    typedef struct
    {
        U32 end_id;
        U32 start_id;
        U32 doc_size;
    	S32 last_text_offset_y;  
        S16 jump_offset_from_app;
        S16 text_offset;
        U8 scroll_speed;
        U8 scroll_type;
        U8 scroll_flag;
        U8 font_size;
        S8 search_str_len;
        S8 font_style;
        U8 override_direction;
        pBOOL jump_to_end;
        pBOOL highlight_string;
        pBOOL search_flag_is_on;
        U8 last_showed_percentage;
        U8 fixed_view_flag;
        get_page_callback get_page_cb;
#ifdef __MMI_TOUCH_SCREEN__
    	void (*key_callback)(UI_character_type c);
        get_data_during_scrolling_cb get_data_during_scrolling;
#endif
    } gui_page_info_app;

#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 

    typedef enum
    {
        FONT_SIZE_SMALL,
        FONT_SIZE_MEDIUM,
        FONT_SIZE_LARGE
    } WGUI_FONT_SIZE;

    typedef struct
    {
        S32 start_line_index;
        S32 total_line_count;
        S32 highlight_offset;
        S32 highlight_len;
        U8 scroll_speed;
        U8 scroll_type;
        U8 scroll_flag;
        U8 font_size;
        S8 font_style;
        U8 override_direction;
        MMI_BOOL b_highlight;
        MMI_BOOL jump_to_end;
        gui_inputs_get_data_callback get_data_cb;
        
#ifdef __MMI_TOUCH_SCREEN__
    	void (*key_callback)(UI_character_type c);
#endif        
    } wgui_ml_line_base_info;

    typedef struct
    {
        /* Try to reduce overheads of GetImage() and gui_measure_image() */
        PU8 icon;
        U8 icon_width;
        U8 icon_height;
        /* Character sequence to represent an icon. English only. */
        char string[MMI_MULTILINE_ICON_MAX_STRING_LEN + 1];
    } wgui_multiline_icon_struct;

    typedef struct
    {
        U8 *buffer;
        S32 head;       /* current read position (in byte) */
        S32 byte_count; /* byte count excluding '\0' */
    } wgui_color_buffer_reader_struct;

    typedef struct
    {
        U8 *buffer;
        S32 tail;   /* current write position (in byte) */
        S32 size;   /* buffer size */
    } wgui_color_buffer_writer_struct;

    typedef enum
    {
        WGUI_MULTITAP_TYPE_UPPERCASE_ABC = 0,
        WGUI_MULTITAP_TYPE_UPPERCASE_ABC_NO_NUMBER,
        WGUI_MULTITAP_TYPE_MAX
    } wgui_multitap_type_enum;
    
    typedef enum
    {
        EDITOR_MULTILINE_INPUT_BOX,
        EDITOR_EMS_INPUT_BOX,
        EDITOR_INLINE_MULTILINE_INPUT_BOX,
        EDITOR_SINGLE_LINE_INPU_BOX,
        EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX,
        EDITOR_INLINE_TEXT,
        EDITOR_NONE_INPUT_BOX
    } mmi_editor_inoutbox_enum;
    
    typedef enum
    {
        MMI_EDITOR_MULTILINE_INPUT_BOX,
        MMI_EDITOR_EMS_INPUT_BOX,
        MMI_EDITOR_SINGLE_LINE_INPU_BOX,
        MMI_EDITOR_INLINE_INPUT_BOX,
        MMI_EDITOR_LINE_BASED_INPUT_BOX,
        MMI_EDITOR_MAX_INPUT_BOX
    } mmi_editor_inputbox_type_enum;
    
    typedef enum
    {
        MMI_EDITOR_NORMAL_INPUT_BOX,
        MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX,
        MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX,
        MMI_EDITOR_DATE,
        MMI_EDITOR_IP4,
        MMI_EDITOR_TIME,
        MMI_EDITOR_TIME_PERIOD,
        MMI_EDITOR_DICT_MULTILINE_INPUT_BOX,
        MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX,
        MMI_EDITOR_VOIP_DIALER_MULTLINE_INPUT_BOX,
        MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX,
        MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX,
        MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX,
        MMI_EBOOK_REDRAW_TEMP,
        MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX,
        MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX,
        MMI_EDITOR_UCE_MULTLINE_INPUT_BOX,
        MMI_EDITOR_INPUT_BOX_READ_ONLY,
        MMI_EDITOR_INPUT_BOX_EBOOK,
        MMI_EDITOR_INPUT_BOX_MMS_VIEWER,
        MMI_EDITOR_MAX_SUB_INPUT_BOX
    } mmi_editor_inputbox_sub_type_enum;

    typedef enum
    {
        WGUI_INPUTS_CURSOR_POS_START,
        WGUI_INPUTS_CURSOR_POS_END,
        WGUI_INPUTS_CURSOR_POS_NONE
    } wgui_inputs_cursor_pos_enum;

    typedef enum
    {
        WGUI_INPUTS_EDITOR_DIALER,
        WGUI_INPUTS_EDITOR_SL,
        WGUI_INPUTS_EDITOR_INLINE_SL,
        WGUI_INPUTS_EDITOR_ML,
        WGUI_INPUTS_EDITOR_INLINE_ML,
        WGUI_INPUTS_EDITOR_EMS,
        WGUI_INPUTS_EDITOR_TATOL
    } wgui_inputs_fast_del_nav_editor_enum;

    typedef enum
    {
        WGUI_INPUTS_OPER_FAST_DEL,
        WGUI_INPUTS_OPER_FAST_NAV_LEFT,
        WGUI_INPUTS_OPER_FAST_NAV_RIGHT,
        WGUI_INPUTS_OPER_FAST_NAV_UP,
        WGUI_INPUTS_OPER_FAST_NAV_DOWN,
        WGUI_INPUTS_OPER_FAST_NONE
    } wgui_inputs_fast_del_nav_oper_enum;
    
    typedef struct
    {
        mmi_editor_inputbox_type_enum input_box_type;
        mmi_editor_inputbox_sub_type_enum input_box_sub_type;
        void * input_box_handler;
    }mmi_editor_handler_struct;

    typedef MMI_BOOL (*wgui_inputs_ml_key_hdlr) (S16 keyCode);

/***************************************************************************** 
 * Extern Function
 *****************************************************************************/
/* Common functions */
extern void wgui_inputs_set_current_input_box_type(mmi_editor_inoutbox_enum input_box_type);
extern void wgui_inputs_multitap_clear_key_handlers(void);
extern MMI_BOOL wgui_inputs_multitap_setup_functions(wgui_multitap_type_enum multitap_type, void (*input_callback) (UI_character_type), void (*input_complete_callback) (void));
extern void wgui_inputs_multitap_reset(void);
extern void wgui_inputs_multitap_stop(void);
extern U32 wgui_inputs_direct_input_from_tst_module(U8 index, U8 *p);
extern MMI_BOOL wgui_inputs_is_r2l_display(void);
extern void wgui_inputs_register_pound_key_buffer_flush_test_function(BOOL(*FuncPtr) (void));
extern void wgui_inputs_redraw_input_mode_only(void);
extern void wgui_inputs_setup_input_information(S32 x, S32 y, S32 width, S32 height);
extern void wgui_inputs_input_information_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_inputs_hide_input_information_bar(void);
extern void wgui_inputs_show_input_mode_internal(
                S32 info_bar_x,
                S32 info_bar_y,
                S32 info_bar_width,
                S32 info_bar_height,
                mmi_imm_input_mode_enum input_mode, 
                PU8 inputbox_information_icon);
extern void wgui_inputs_show_input_mode(mmi_imm_input_mode_enum input_mode, PU8 inputbox_information_icon);
extern void wgui_inputs_redraw_input_information_background(void);
extern U8 wgui_inputs_ucs2_to_gb_len(U16 ucs2_char);
extern void wgui_inputs_register_validation_func(void (*f) (U8 *, U8 *, S32));
extern void wgui_inputs_register_not_empty_func(void (*f) (void));
extern void wgui_inputs_register_empty_func(void (*f) (void));
extern void wgui_inputs_register_input_method_change_func(void (*f) (void));
extern S32 wgui_inputs_get_ucs2_count(void);
extern S32 wgui_inputs_get_ext_gsm_count(void);
extern void wgui_inputs_set_LSK_func(FuncPtr f);
extern void wgui_inputs_set_LSK_text(void);
extern S32 mmi_get_current_editor_style(void);
extern MMI_BOOL wgui_inputs_is_input_char_valid(U16 in);

extern void wgui_inputs_options_menu_highlight_handler(S32 item_index);
extern U16 wgui_inputs_options_add_menu_items(
         S32 number_of_items,
         U8 **list_of_items,
         U8 **new_list_of_items,
         U16 *list_of_icons,
         U16 *new_list_of_icons,
         U8 **list_of_descriptions,
         U8 **new_list_of_descriptions,
         void (*f_highlight) (S32 item_index),
         void (*f_close) (void),
         U8 *history_buffer);
extern MMI_BOOL wgui_inputs_menu_index_in_editor_range(void);
extern void wgui_inputs_options_menu_set_editor_history(U8 *history_buffer);
extern void wgui_inputs_options_menu_get_category_history(U8 *history_buffer);
extern mmi_ret wgui_inputs_options_menu_handler(mmi_event_struct *evt, mmi_id parent_id);

extern S32  wgui_inputs_get_current_imui_height(mmi_editor_inputbox_type_enum input_box_type);
extern void wgui_inputs_close(void);

/* Singleline editor */
/* slim_2_2 */ //extern void wgui_inputs_sl_create(UI_string_type buffer, S32 buffer_length);
extern void wgui_inputs_sl_create_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position);
extern void wgui_inputs_sl_show(void);
extern void wgui_inputs_sl_end_frame(void);
extern void wgui_inputs_sl_redraw(void);
extern MMI_BOOL wgui_inputs_sl_multitap_input(UI_character_type c);
extern void wgui_inputs_sl_multitap_input_complete(void);
extern MMI_BOOL wgui_inputs_sl_direct_input(UI_character_type c);
extern MMI_BOOL wgui_inputs_sl_direct_input_no_draw(UI_character_type c);
extern void wgui_inputs_sl_delete_character(void);
extern void wgui_inputs_sl_delete_character_no_draw(void);
extern void wgui_inputs_sl_previous_character(void);
extern void wgui_inputs_sl_next_character(void);
extern void wgui_inputs_sl_toggle_insert_mode(void);
extern void wgui_inputs_sl_delete_current_character(void);
extern void wgui_inputs_sl_delete_all_characters(void);
extern void wgui_inputs_sl_handle_key_down(MMI_key_code_type k);
extern void wgui_inputs_sl_key_handler(S32 vkey_code, S32 key_state);
extern void wgui_inputs_sl_register_keys(void);
extern void wgui_inputs_sl_set_mask(U8 m);
extern void wgui_inputs_sl_reset(void);
extern MMI_BOOL wgui_inputs_sl_get_display_status(void);
extern void wgui_inputs_sl_resize(S32 width, S32 height);
extern void wgui_inputs_sl_resize_fix(void);
extern void wgui_inputs_sl_move(S32 x, S32 y);
extern void wgui_inputs_sl_register_input_callback(void (*f) (void));
extern S32 wgui_inputs_sl_multitap_input_string(PU8 str);
extern void wgui_inputs_sl_register_navigate_callback(void (*f) (void));
/* slim_2_2 */ //extern void wgui_inputs_sl_change_content(UI_string_type string);
extern U8 wgui_inputs_sl_is_empty(void);
extern void wgui_inputs_sl_redraw_remaining_characters_display(void);
extern void wgui_inputs_sl_redraw_information_bar(void);
extern U8 wgui_inputs_sl_set_category_history(U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_sl_get_category_history(U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_sl_get_category_history_ext(single_line_input_box *b, U16 history_ID, U8 *history_buffer);
extern U8 wgui_inputs_sl_set_category_history_ext(single_line_input_box *b, U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_sl_handle_right_softkey_down(void);
extern void wgui_inputs_sl_handle_right_softkey_up(void);
extern void wgui_inputs_sl_register_handle_right_softkey_up(void);
extern void wgui_inputs_sl_register_handle_clear_key_up(void);
extern void wgui_inputs_sl_handle_right_softkey_long_press(void);
extern void wgui_inputs_sl_handle_input(void);
extern void wgui_inputs_sl_handle_navigate(void);
extern void wgui_inputs_sl_validation_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length);
extern S32 wgui_inputs_sl_get_ucs2_count(void);
extern S32 wgui_inputs_sl_get_ext_gsm_count(void);
extern void wgui_inputs_sl_set_RSK(void);
extern void wgui_inputs_sl_setup(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U32 input_type,
                U8 *history_buffer,
                U8 information_bar_flag);
extern void wgui_inputs_sl_setup_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U32 input_type,
                U8 *history_buffer,
                U8 information_bar_flag,
                U32 (*msg_call_back) (void * input_box_handle, mmi_imc_message_struct_p msg_ptr));
extern void wgui_inputs_sl_close(void);
extern void wgui_inputs_sl_disable_up_down_key_register(MMI_BOOL is_disable);
extern void wgui_inputs_sl_disable_left_right_key_register(MMI_BOOL is_disable);
extern void wgui_inputs_sl_set_show_flag(MMI_BOOL is_on);
extern void wgui_inputs_sl_register_change_event_handler(MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C));
extern void wgui_inputs_sl_move_cursor(wgui_inputs_cursor_pos_enum pos);
extern U32 wgui_inputs_sl_insert_string(UI_string_type str, U32 len, MMI_BOOL is_redraw);
extern void wgui_inputs_sl_set_default_text(UI_string_type default_text);
extern void wgui_inputs_set_break_insert(MMI_BOOL is_break);
extern void wgui_inputs_sl_disable(void);
extern void wgui_inputs_sl_enable(void);

/* Multiline editor*/
extern void wgui_inputs_ml_register_input_callback(void (*f) (void));
extern void wgui_inputs_ml_register_navigate_callback(void (*f) (void));
extern void wgui_inputs_ml_register_validation_callback(void (*f) (UI_buffer_type text, UI_buffer_type cursor, S32 text_length));
/* slim_2_2 */ //extern void wgui_inputs_ml_create(UI_string_type buffer, S32 buffer_length);
extern void wgui_inputs_ml_create_set_buffer_no_text_reset(UI_string_type, S32, S32, S32);
extern void wgui_inputs_ml_resize_fit(S32 width, S32 height, S32 *fit_width, S32 *fit_height);
extern void wgui_inputs_ml_resize(S32 width, S32 height);
extern void wgui_inputs_ml_move(S32 x, S32 y);
extern void wgui_inputs_ml_show_no_draw(void);
extern void wgui_inputs_ml_end_frame(void);
extern void wgui_inputs_ml_redraw(void);
extern MMI_BOOL wgui_inputs_ml_multitap_input(UI_character_type c);
extern S32 wgui_inputs_ml_multitap_input_string(PU8 str);
extern void wgui_inputs_ml_multitap_input_complete(void);
extern MMI_BOOL wgui_inputs_ml_direct_input(UI_character_type c);
extern MMI_BOOL wgui_inputs_ml_direct_input_no_draw(UI_character_type c);
extern void wgui_inputs_ml_direct_input_no_LF_check(UI_character_type c);
extern void wgui_inputs_ml_delete_character(void);
extern void wgui_inputs_ml_delete_character_no_draw(void);
extern void wgui_inputs_ml_previous_character(void);
extern void wgui_inputs_ml_next_character(void);
extern void wgui_inputs_ml_delete_all_characters(void);
extern S8 wgui_inputs_ml_is_inline(void *item);
extern void wgui_inputs_ml_vertical_scroll(void);
extern void wgui_inputs_ml_previous_line(void);
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
extern void wgui_inputs_ml_inline_previous_line(void);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
extern void wgui_inputs_ml_next_line(void);
extern void wgui_inputs_ml_inline_next_line(void);
extern void wgui_inputs_ml_home(void);
extern void wgui_inputs_ml_end(void);
extern void wgui_inputs_ml_previous_page(void);
extern void wgui_inputs_ml_next_page(void);
extern void wgui_inputs_ml_toggle_insert_mode(void);
extern void wgui_inputs_ml_delete_current_character(void);
extern void wgui_inputs_ml_wcss_alphabetic_keyboard_input_handler(S32 keyc);
extern void wgui_inputs_ml_key_handler(S32 vkey_code, S32 key_state);
extern void wgui_inputs_ml_register_keys(void);
extern void wgui_inputs_ml_inline_register_keys(void);
extern void wgui_inputs_ml_viewer_key_handler(S32 vkey_code, S32 key_state);
extern void wgui_inputs_ml_register_viewer_keys(void);
extern void wgui_inputs_ml_previous_hilite(void);
extern void wgui_inputs_ml_next_hilite(void);
extern void wgui_inputs_ml_register_hilite_keys(void);
extern void wgui_inputs_ml_next_line_with_hilite_list(void);
extern void wgui_inputs_ml_previous_line_with_hilite_list(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void wgui_inputs_ml_hilite_pen_down_handler(mmi_pen_point_struct pos);
extern void wgui_inputs_ml_hilite_pen_up_handler(mmi_pen_point_struct pos);
extern void wgui_inputs_ml_register_hilite_pen_event_handler(void);
extern MMI_BOOL wgui_inputs_ml_hilite_pen_handler(mmi_pen_point_struct pos, mmi_pen_event_type_enum pen_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 
extern void wgui_inputs_ml_set_mask(U8 m);
extern void wgui_inputs_ml_reset(void);
extern void wgui_inputs_ml_reset_vertical_scroll(void);
extern U8 wgui_inputs_ml_is_empty(void);
extern S32 wgui_inputs_ml_get_length(void);
extern S32 wgui_inputs_ml_get_line_height(void);
extern MMI_BOOL wgui_inputs_ml_get_display_status(void);
extern S32 wgui_inputs_ml_get_height(void);
extern S32 wgui_inputs_ml_get_line_height_with_obj(multi_line_input_box *b);
extern MMI_BOOL wgui_inputs_ml_is_in_view_mode(void);
extern void wgui_inputs_ml_config_general_icon_handler(BOOL is_sorted, U8 num_items, const wgui_multiline_icon_struct *items);
extern void wgui_inputs_ml_reset_general_icon_handler(void);
extern S32 wgui_inputs_ml_general_icon_handler(
                const U8 *s,
                BOOL do_draw,
                S32 *icon_width,
                S32 *icon_height,
                S32 x,
                S32 y);
extern void wgui_inputs_ml_set_register_up_down_key_funcptr(void (*FuncPtr) (void));
extern void wgui_inputs_ml_reset_register_up_down_key_funcptr(void);
extern void wgui_inputs_ml_register_infobar_callback(
                void(*redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                void(*reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                U32 height);
extern void wgui_inputs_ml_register_change_event_handler(MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C));
extern void wgui_inputs_ml_set_text_color(color c);
extern void wgui_inputs_ml_clear_pen_down_flag(void);
extern void wgui_inputs_ml_set_pen_down_flag(void);
extern BOOL wgui_inputs_ml_get_pen_down_flag(void);
extern U8 wgui_inputs_ml_set_category_history(U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_ml_get_category_history(U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_ml_get_category_history_ext(multi_line_input_box *b, U16 history_ID, U8 *history_buffer);
extern U8 wgui_inputs_ml_set_category_history_ext(multi_line_input_box *b, U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_ml_set_category_history_state(U16 history_ID, U8 *history_buffer, S8 state); 
extern S8 wgui_inputs_ml_get_category_history_state(U16 history_ID, U8 *history_buffer);
extern void wgui_inputs_ml_redraw_remaining_characters_display_internal(void);
extern void wgui_inputs_ml_redraw_remaining_characters_display(void);
extern void wgui_inputs_ml_show_current_input_method(S32 x1,S32 y1,S32 x2,S32 y2);
extern void wgui_inputs_ml_redraw_input_information_bar(void);
extern void wgui_inputs_ml_handle_right_softkey_down(void);
extern void wgui_inputs_ml_handle_right_softkey_up(void);
extern void wgui_inputs_ml_register_handle_right_softkey_up(void);
extern void wgui_inputs_ml_register_handle_clear_key_up(void);
extern void wgui_inputs_ml_handle_right_softkey_long_press(void);
extern void wgui_inputs_ml_handle_input(void);
extern void wgui_inputs_ml_handle_navigate(void);
extern void wgui_inputs_ml_change_information_bar_input_method(void);
extern void wgui_inputs_ml_show_with_information_bar(void);
extern void wgui_inputs_ml_hide_text_content(MMI_BOOL hide);
extern void wgui_inputs_ml_validation_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length);
extern S32 wgui_inputs_ml_get_ucs2_count(void);
extern S32 wgui_inputs_ml_get_ext_gsm_count(void);
extern U8 wgui_inputs_ml_test_change_input_mode(void);
extern void wgui_inputs_ml_move_cursor(wgui_inputs_cursor_pos_enum pos);
extern S32 wgui_inputs_ml_get_scroll_bar_width(void);
extern void wgui_inputs_ml_setup_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U32 input_type,
                U8 *history_buffer,
                mmi_imm_input_mode_enum *input_mode_array,
                U8 information_bar_flag,
                U32 additional_flags,
                S16 min_text_height,
                S16 min_line_height,
                S16 header_height,
                S16 footer_height,
                multi_line_input_box_icon_hdlr icon_callback);
extern void wgui_inputs_ml_setup_ext2(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U32 input_type,
                U8 *history_buffer,
                mmi_imm_input_mode_enum *input_mode_array,
                U8 information_bar_flag,
                U32 additional_flags,
                S16 min_text_height,
                S16 min_line_height,
                S16 header_height,
                S16 footer_height,
                multi_line_input_box_icon_hdlr icon_callback,
                U32 (*msg_call_back) (void * input_box_handle, mmi_imc_message_struct_p msg_ptr),
                MMI_BOOL connect_ime);

extern void wgui_inputs_ml_set_RSK(void);
extern void wgui_inputs_ml_inline_setup(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U32 input_type,
                U8 *history_buffer,
                U8 information_bar_flag);
extern void wgui_inputs_ml_append_string(
                U32 input_type, 
                U8 *buffer, 
                S32 buffer_size, 
                U8 *s, 
                U8 *history_buffer,
                U16 category_id,
                MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 C));
extern void wgui_inputs_ml_view_mode_setup(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size);
extern void wgui_inputs_ml_set_common_style(MMI_BOOL info_area, MMI_BOOL wallpaper);
extern void wgui_inputs_ml_set_style(U32 style, U32 ext_style);
extern void wgui_inputs_ml_set_style_with_obj(multi_line_input_box *b, U32 style, U32 ext_style);
extern void wgui_inputs_ml_move_cursor_to_start(void);
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
extern void wgui_inputs_ml_set_predefine_pos_info(
                S16 *predefined_pos,
                void (*cursor_move_callback)(S32 cursor_offset),
                MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 c));
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
extern S32 wgui_inputs_ml_get_text_length(void);
extern void wgui_inputs_ml_go_to_last_line(void);
extern MMI_BOOL wgui_inputs_ml_is_last_line(void);

extern U32 wgui_inputs_ml_insert_string(UI_string_type str, U32 len, MMI_BOOL is_redraw);
extern U32 wgui_inputs_ml_delete_string(U32 len, MMI_BOOL no_redraw);

extern void wgui_inputs_ml_set_auto_display_remaining_counter(void);
extern void wgui_inputs_ml_set_clear_key_delete_all_mode(void);

extern void wgui_inputs_ml_handle_right_softkey_repeat(void);
extern void wgui_inputs_ml_handle_right_softkey_touch_repeat(void);

extern void wgui_inputs_ml_handle_input_ext_type(U32 input_type);

/* Line base mode start */
extern void wgui_inputs_ml_jump_to_line(S32 line_index, MMI_BOOL b_show);
extern gui_line_struct *wgui_inputs_ml_get_layout_info(void);
extern gui_line_struct *wgui_inputs_ml_get_visible_info(void);
extern void wgui_inputs_ml_set_total_line_count(S32 line_count, MMI_BOOL b_show);
extern void wgui_inputs_ml_linebase_register_callback(gui_inputs_get_data_callback f);
extern void wgui_inputs_ml_jump_to_line_bg(S32 line_index);
extern gui_line_struct * wgui_inputs_ml_get_layout_info_bg(void);

extern void wgui_inputs_ml_linebase_next_line(void);
extern void wgui_inputs_ml_linebase_previous_line(void);
extern void wgui_inputs_ml_linebase_next_page(void);
extern void wgui_inputs_ml_linebase_previous_page(void);
extern void wgui_inputs_ml_linebase_start_auto_scroll(void);
extern void wgui_inputs_ml_linebase_start_text_scroll(void);
extern void wgui_inputs_ml_linebase_stop_text_scroll(void);
extern void wgui_inputs_ml_linebase_set_stop_scroll_callback(void* callback);
extern void wgui_inputs_ml_linebase_set_font(U8 gui_font_type, U8 gui_font_style);
extern void wgui_inputs_ml_linebase_highlight_search_string(S32 text_offset, S8 len);
extern void wgui_inputs_ml_linebase_set_scroll_info(wgui_ml_line_base_info *info);
extern void wgui_inputs_ml_linebase_set_percentage_callback(void* callback);
extern void wgui_inputs_ml_linebase_jump_to_end(void);
extern void wgui_inputs_ml_linebase_get_percentage(UI_character_type *str);
extern void wgui_inputs_ml_linebase_init(wgui_ml_line_base_info *page_info_d);
extern S32 wgui_inputs_ml_linebase_validate_for_last_page(S32 index);
#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL wgui_inputs_ml_linebase_pen_move_hdlr(mmi_pen_point_struct pos);
extern MMI_BOOL wgui_inputs_ml_linebase_pen_down_hdlr(mmi_pen_point_struct pos);
extern MMI_BOOL wgui_inputs_ml_linebase_pen_up_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_dirty
 * DESCRIPTION
 *  Set the editor buffer dirty, if this flag is MMI_TURE, Editor will call 
 *  get_data_cb to re-get the data when show
 * PARAMETERS
 * is_dirty     [IN]                 set dirty or not           
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_ml_set_dirty(MMI_BOOL is_dirty);

/* Line base mode end */

extern void wgui_inputs_ml_get_visible_character_range(S32 *start, S32 *end);

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    extern void wgui_inputs_ml_paging_previous_page(void);
    extern void wgui_inputs_ml_paging_next_page(void);
    extern void wgui_inputs_ml_paging_next_line_in_paging_scroll(void);
    extern void wgui_inputs_ml_paging_next_line_in_paging(void);
    extern void wgui_inputs_ml_paging_set_stop_scroll_callback(void* callback);
    extern void wgui_inputs_ml_paging_previous_line_in_paging(void);   
    extern void wgui_inputs_ml_paging_calculate_percentage(PU8 percentage_scale);
    extern void wgui_inputs_paging_start_text_scroll(void);
    extern void wgui_inputs_ml_paging_set_scroll_info(gui_page_info_app **gui_scroll_info);
    extern void wgui_inputs_ml_paging_stop_text_scroll(void);
    extern void wgui_inputs_ml_paging_start_text_scroll(void);
    extern void wgui_inputs_ml_paging_set_font(U8 gui_paging_font_type, U8 gui_paging_font_style);
    extern void wgui_inputs_ml_paging_set_get_page_callback(get_page_callback get_page);
    extern void wgui_inputs_ml_paging_set_scrollbar_range(U32 document_size);
    extern void wgui_inputs_ml_paging_set_percentage(U32 page_id, S16 text_offset);
    extern U8 wgui_inputs_ml_paging_translate_to_text_percentage(U8 percentage_scale);
    extern MMI_BOOL wgui_inputs_ml_paging_check_to_end(void);
    extern MMI_BOOL wgui_inputs_ml_paging_check_to_start(void);
    extern MMI_BOOL wgui_inputs_ml_paging_check_cursor_to_end(void);
    extern void wgui_inputs_ml_paging_clear_last_percentage(void);
    extern void wgui_inputs_ml_paging_set_page(U32 start_id, U32 end_id);
    extern void wgui_inputs_ml_paging_set_show_percentage_flag(void);
    extern void wgui_inputs_ml_paging_reset_show_percentage_flag(void);
    extern void wgui_inputs_ml_set_dm_data(dm_coordinates *gui_multiline_get_coordinates);
    extern void wgui_inputs_ml_paging_set_percentage_scale(U8 percentage_scale);
    extern void wgui_inputs_ml_paging_set_percentage_callback(void* callback);
    extern void wgui_inputs_ml_paging_highlight_search_string(S32 text_offset, S8 search_str_len);
    extern void wgui_inputs_ml_paging_get_current_page(
                    PU32 page_id,
                    PS32 text_offset,
                    PU8 shared_bytes,
                    PU8 last_showed_percentage,
				    PS32 last_text_offset_y);
    extern S32 wgui_inputs_ml_get_visible_count(void);
    extern void wgui_inputs_ml_paging_jump_to_end(void);
    extern void wgui_inputs_ml_paging_set_page_info(gui_page_info_app *page_info_d);
#ifdef __MMI_TOUCH_SCREEN__
    extern void wgui_inputs_ml_paging_set_scroll_data_callback(get_data_during_scrolling_cb data_callback);
    extern void wgui_inputs_ml_paging_set_percentage_scale_TS(U8 percentage_scale);
    extern void wgui_inputs_ml_paging_key_mapping_TS(UI_character_type c);	
	extern void wgui_inputs_ml_paging_get_data_during_scrolling(S32 percentage_val);
    extern void wgui_inputs_ml_paging_set_full_screen_flag(pBOOL flag_value);
    extern MMI_BOOL wgui_inputs_ml_paging_pen_up_handler(mmi_pen_point_struct pos);
    extern MMI_BOOL wgui_inputs_ml_paging_pen_down_handler(mmi_pen_point_struct pos);
    extern MMI_BOOL wgui_inputs_ml_paging_pen_repeat_handler(mmi_pen_point_struct pos);
    extern MMI_BOOL wgui_inputs_ml_paging_pen_move_handler(mmi_pen_point_struct pos);
    extern void wgui_inputs_ml_paging_set_async_pen_callback(void (*f) (void));
    extern void wgui_inputs_ml_paging_timer_forward_callback(void);
    extern void wgui_inputs_ml_paging_timer_backward_callback(void);
    extern void wgui_inputs_ml_paging_timer_pen_move_callback(void);
    extern void wgui_inputs_ml_paging_timer_pen_up_callback(void);    
    extern void wgui_inputs_ml_paging_virtual_keypad_callback(void);
    extern void wgui_inputs_ml_paging_clear_pen_timer_handler(void);
#endif 
    extern void wgui_paging_set_data_for_find_next(gui_page_info_app *gui_multiline_data, U8 *buffer_data);  
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 
/* API to read/write color editor buffer (UI_MULTI_LINE_INPUT_BOX_RICHTEXT)  */
extern void wgui_inputs_color_buffer_create_reader(wgui_color_buffer_reader_struct *reader, U8 *buffer);
extern BOOL wgui_inputs_color_buffer_read_stripped_text(
                wgui_color_buffer_reader_struct *reader,
                U8 *dest_buffer,
                S32 size_of_dest,
                S32 *bytes_written);
extern void wgui_inputs_color_buffer_create_write(wgui_color_buffer_writer_struct *writer, U8 *buffer, S32 size);
extern S32 wgui_inputs_color_buffer_get_space_for_write(wgui_color_buffer_writer_struct *writer);
extern BOOL wgui_inputs_color_buffer_write_char(wgui_color_buffer_writer_struct *writer, U16 ch);
extern BOOL wgui_inputs_color_buffer_write_2char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2);
extern BOOL wgui_inputs_color_buffer_write_3char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2, U16 ch3);
extern BOOL wgui_inputs_color_buffer_write_4char(
                wgui_color_buffer_writer_struct *writer,
                U16 ch1,
                U16 ch2,
                U16 ch3,
                U16 ch4);
extern S32 wgui_inputs_color_buffer_write_string(
                wgui_color_buffer_writer_struct *writer,
                const U8 *string,
                BOOL allow_partial_write,
                BOOL *whole_string_written);
/* Dialer */
/* slim_2_2 */ //extern void wgui_inputs_dialer_create(UI_string_type buffer, S32 buffer_length);
extern void wgui_inputs_dialer_create_set_buffer(
                UI_string_type buffer,
                S32 buffer_length,
                S32 text_length,
                S32 edit_position);
extern void wgui_inputs_dialer_show(void);
extern void wgui_inputs_dialer_end_frame(void);
extern void wgui_inputs_dialer_redraw(void);
extern void wgui_inputs_dialer_handle_plus_key(void);
extern void wgui_inputs_dialer_multitap_input(UI_character_type c);
extern void wgui_inputs_dialer_multitap_input_complete(void);
extern void wgui_inputs_dialer_direct_input(UI_character_type c);
extern void wgui_inputs_dialer_delete_character(void);
extern void wgui_inputs_dialer_previous_character(void);
extern void wgui_inputs_dialer_next_character(void);
extern void wgui_inputs_dialer_toggle_insert_mode(void);
extern void wgui_inputs_dialer_delete_current_character(void);
extern void wgui_inputs_dialer_delete_all_characters(void);
extern void wgui_inputs_dialer_alphabetic_keyboard_input_handler(S32 keyc);
extern void wgui_inputs_dialer_numeric_keyboard_input_handler(S32 keyc);
extern void wgui_inputs_dialer_next_line(void);
extern void wgui_inputs_dialer_previous_line(void);
extern void wgui_inputs_dialer_key_handler(S32 vkey_code, S32 key_state);
extern void wgui_inputs_dialer_register_keys(void);
extern void wgui_inputs_dialer_set_mask(U8 m);
extern void wgui_inputs_dialer_reset(void);
extern void wgui_inputs_dialer_resize(S32 width, S32 height);
extern void wgui_inputs_dialer_move(S32 x, S32 y);
extern void wgui_inputs_dialer_register_input_callback(void (*f) (void));
/* slim_2_2 */ //extern void wgui_inputs_dialer_register_navigate_callback(void (*f) (void));
extern void wgui_inputs_dialer_change_callback(void);
extern void wgui_inputs_dialer_handle_multitap_complete(S32 type);
extern void wgui_inputs_dialer_handle_key_down(MMI_key_code_type k);
extern void wgui_inputs_dialer_handle_key_up(MMI_key_code_type k);
extern void wgui_inputs_dialer_multitap_complete_star_key(void);
extern void wgui_inputs_dialer_multitap_handle_star_key_down(void);
extern void wgui_inputs_dialer_multitap_handle_star_key_up(void);
extern void wgui_inputs_dialer_multitap_complete_zero_key(void);
extern void wgui_inputs_dialer_multitap_handle_zero_key_down(void);
extern void wgui_inputs_dialer_multitap_handle_zero_key_up(void);
extern void wgui_inputs_dialer_handle_zero_key_long_press(void);
extern void wgui_inputs_dialer_handle_hash_key_down(void);
extern void wgui_inputs_dialer_handle_star_key_down(void);
extern void wgui_inputs_dialer_handle_right_softkey_down(void);
extern void wgui_inputs_dialer_handle_right_softkey_up(void);
extern void wgui_inputs_dialer_register_handle_right_softkey_up(void);
extern void wgui_inputs_dialer_register_handle_clear_key_up(void);
extern void wgui_inputs_dialer_handle_input(void);
extern void wgui_inputs_dialer_register_dialer_keys(void);
extern void wgui_inputs_dialer_validation_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length);
extern void wgui_inputs_dialer_handle_right_softkey_long_press(void);
extern void wgui_inputs_dialer_set_border(MMI_BOOL is_border_existing, color border_color);
extern void wgui_inputs_dialer_set_cursor_to_first(void);
extern void wgui_inputs_dialer_setup(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *buffer,
                S32 buffer_size,
                U16 category_screen_ID,
                UI_string_type RSK_label,
                PU8 RSK_icon,
                U8 *history_buffer,
                U32 flags);
extern void wgui_inputs_dialer_close(void);
extern void wgui_inputs_dialer_register_star_key_up_callback(void(*f)(void));

#ifdef __MMI_TOUCH_DIAL_SCREEN__
extern void wgui_inputs_dialer_setup_dialing_keypad(dialing_keypad_struct *dialing_keypad);
extern void wgui_inputs_dialer_show_dialing_screen(S32 x1, S32 y1, S32 width, S32 height);
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
    extern single_line_input_box MMI_singleline_inputbox;
    extern multi_line_input_box MMI_multiline_inputbox;
    extern dialer_input_box MMI_dialer_inputbox;
    
    extern S32 MMI_multitap_x;
    extern S32 MMI_multitap_y;
    extern S32 MMI_multitap_width;
    extern S32 MMI_multitap_height;
    extern S32 MMI_general_inputbox_x;
    extern S32 MMI_general_inputbox_y;
    extern S32 MMI_general_inputbox_width;
    extern S32 MMI_general_inputbox_height;

    extern S32 MMI_singleline_inputbox_x;
    extern S32 MMI_singleline_inputbox_y;
    extern S32 MMI_singleline_inputbox_width;
    extern S32 MMI_singleline_inputbox_height;
    extern S32 MMI_multiline_inputbox_x;
    extern S32 MMI_multiline_inputbox_y;
    extern S32 MMI_multiline_inputbox_width;
    extern S32 MMI_multiline_inputbox_height;

    extern S32 wgui_inputbox_information_bar_x;
    extern S32 wgui_inputbox_information_bar_y;
    extern S32 wgui_inputbox_information_bar_width;
    extern S32 wgui_inputbox_information_bar_height;
    extern U8 wgui_inputbox_information_flag;

    extern S32 wgui_inputbox_buffer_size;
    extern S16 MMI_current_input_ext_type;
    extern mmi_editor_inoutbox_enum MMI_current_input_box_type;
    extern S32(*wgui_inputbox_UCS2_count_function) (void);
    extern S32(*wgui_inputbox_GSM_ext_count_function) (void);
    extern BOOL(*wgui_check_pound_key_buffer_flush) (void);

    extern void (*wgui_inputbox_not_empty_callback) (void);
    extern void (*wgui_inputbox_empty_callback) (void);
    extern void (*wgui_inputbox_validation_callback) (U8 *text, U8 *cursor, S32 text_length);
    extern void (*wgui_inputbox_input_method_change_callback) (void);

    extern void (*singleline_inputbox_input_callback) (void);
    extern void (*singleline_inputbox_navigate_callback) (void);
    extern void (*multiline_inputbox_input_callback) (void);
    extern void (*dialer_inputbox_input_callback) (void);
/* slim_2_2 */ //    extern void (*dialer_inputbox_navigate_callback) (void);

    extern void (*wgui_singleline_inputbox_RSK_function) (void);
    extern void (*wgui_singleline_inputbox_LSK_function) (void);
    extern UI_string_type wgui_singleline_inputbox_LSK_label_string;
    extern PU8 wgui_singleline_inputbox_LSK_label_icon;
    
#ifdef __MMI_TOUCH_SCREEN__
    extern UI_buffer_type g_wgui_inputs_ml_pen_down_cursor_p;
#endif /* __MMI_TOUCH_SCREEN__ */

    /* e-dic */
    extern void (*wgui_register_multiline_inputbox_up_down_key_handler) (void);

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    extern dialing_keypad_struct dialing_keypad;
#endif 

#ifdef __MMI_SMALL_EDIT_SCREEN__
    extern U8 wgui_small_editor_information_flag;
#endif 

    /* extern from other module */
   // extern BOOL r2lMMIFlag;
    extern S32 MMI_title_height;

    extern U32 g_wgui_inputs_repeat_count;

    /* Reset key callback in editor option menu */
    extern void wgui_inputs_option_menu_register_key_callback(void (*f) (void));
    extern void wgui_inputs_option_menu_reset_key_callback(void);
    extern void wgui_inputs_option_menu_register_highlight_callback(void (*f) (U32));
    extern void wgui_inputs_options_menu_get_menu_info(S32 *new_item_num,  S32 *start_index);
    extern void wgui_inputs_option_menu_reset_highlight_callback(void);
    extern void wgui_inputs_options_menu_set_category_history_key_info(U8 *history_buffer);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    extern MMI_BOOL wgui_inputs_dialer_qwerty_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
#endif
    extern MMI_BOOL wgui_inputs_dialer_is_dialer_keys(S16 mmi_key_code);
    extern void wgui_inputs_dialer_display_char(U8 key_code);

    extern void wgui_inputs_ml_register_pre_key_handler(wgui_inputs_ml_key_hdlr f);
    extern void wgui_inputs_ml_reset_pre_key_handler(void);
    extern void wgui_inputs_ml_disable(void);
    extern void wgui_inputs_ml_enable(void);
    extern MMI_BOOL wgui_inputs_ml_is_disable(void);
    extern void wgui_inputs_ml_register_pre_delete_callback(FuncPtr f);
    extern void wgui_inputs_ml_reset_pre_delete_callback(void);
    extern S32 wgui_inputs_ml_get_cursor_index(void);

    extern void wgui_inputs_ml_update_content(void);
    extern void wgui_inputs_ml_set_decimal_flag(U32 input_type);

    extern void wgui_inputs_ml_register_floating_counter(MMI_BOOL (*get_remaining_counter)(UI_character_type *buffer, S32 buffer_size));

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_set_key_callback
 * DESCRIPTION
 *  Set key handler for App in editor screen
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_ml_register_set_key_callback(void (*f) (void));

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_is_area_visible
 * DESCRIPTION
 *  Check the area is visible or not
 * PARAMETERS
 *  x               [IN]               
 *  y               [IN]
 *  width           [IN]
 *  height          [IN]
 *  gap             [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern S32 wgui_inputs_ml_is_area_visible(S32 x, S32 y, S32 width, S32 height, S32 gap);


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_connect
 * DESCRIPTION
 *  Connect editor
 * PARAMETERS
 *  input_type              [IN]            input type
 *  input_mode_array        [IN]            input mode array
 *  default_input_mode      [IN]            default input mode
 *  input_box_type          [IN]            inputbox type
 *  input_box_sub_type      [IN]            inputbox sub type
 *  input_box_handler       [IN]            editor pointer
 *  msg_callback            [IN]            message callback
 * RETURNS
 *  Connect IME successfully or not
 *****************************************************************************/
MMI_BOOL wgui_inputs_connect(
              U32 input_type,
              mmi_imm_input_mode_enum *input_mode_array,
              mmi_imm_input_mode_enum default_input_mode,
              mmi_editor_inputbox_type_enum input_box_type,
              mmi_editor_inputbox_sub_type_enum input_box_sub_type,
              void * input_box_handler,
              mmi_imc_message_funcptr msg_callback);
              
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_disconnect
 * DESCRIPTION
 *  Disconnect editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_disconnect(void);


#ifdef __cplusplus
}
#endif 

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_create_set_buffer
 * DESCRIPTION
 *  Creates a read-only multiline inputbox instance
 *
 * PARAMETERS
 *  buffer              : [IN]        the buffer to use
 *  buffer_length       : [IN]        the length of the buffer to use
 *  text_length         : [IN]        the length of the text in the buffer
 *  edit_position       : [IN]        the cursor position on entry
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_ml_create_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position);


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_setup
 * DESCRIPTION
 *  Creates a editable multiline inputbox instance
 *
 * PARAMETERS
 *  x                           : [IN]        start x postition of inputr box
 *  y                           : [IN]        strar y position of input box
 *  width                       : [IN]        width of input box
 *  height                      : [IN]        height of input box
 *  buffer                      : [IN/OUT]    buffer of input box        
 *  buffer_size                 : [IN]        the length of the buffer
 *  category_screen_ID          : [IN]        category screen id
 *  RSK_label                   : [IN]        the label of right softkey
 *  RSK_icon                    : [IN]        the icon of the right softkey     
 *  input_type                  : [IN]        the input type of input method 
 *  history_buffer              : [IN]        the history buffer 
 *  information_bar_flag        : [IN]        indicate whether to display information bar
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_ml_setup(
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height,
                    U8 *buffer,
                    S32 buffer_size,
                    U16 category_screen_ID,
                    UI_string_type RSK_label,
                    PU8 RSK_icon,
                    U32 input_type,
                    U8 *history_buffer,
                    U8 information_bar_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_show
 * DESCRIPTION
 *  Displays the multiline inputbox
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
 extern void wgui_inputs_ml_show(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_close
 * DESCRIPTION
 *  Destroy a multiline inputbox instance. It will release all the inputbox resource
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_ml_close(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_setup
 * DESCRIPTION
 *  create an editable singleline input box
 *
 * PARAMETERS
 *  x                           : [IN]        start x of single line input box
 *  y                           : [IN]        start y of single line input box
 *  width                       : [IN]        width of single line input box
 *  height                      : [IN]        height of single line input box
 *  buffer                      : [IN]        buffer of single line input box
 *  buffer_size                 : [IN]        size of buffer
 *  category_screen_ID          : [IN]        id of category screen
 *  RSK_label                   : [IN]        string of RSK
 *  RSK_icon                    : [IN]        icon of RSK
 *  input_type                  : [IN]        the input type of input method
 *  history_buffer              : [IN]        history buffer
 *  information_bar_flag        : [IN]        indicate whether to display information bar
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_sl_setup(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *buffer,
        S32 buffer_size,
        U16 category_screen_ID,
        UI_string_type RSK_label,
        PU8 RSK_icon,
        U32 input_type,
        U8 *history_buffer,
        U8 information_bar_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_show
 * DESCRIPTION
 *  Displays the singleline inputbox
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_sl_show(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_close
 * DESCRIPTION
 *  Destroy a singleline input box
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_sl_close(void);

#ifdef __OP01_FWPBW__

extern UI_character_type g_wgui_inputs_remaining_characters_str[];

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_show_current_input_method
 * DESCRIPTION
 *  wgui_inputs_ml_show_current_input_method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_show_current_input_method_timer_handler(void);

#endif /* __OP01_FWPBW__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_reset_repeat_count
 * DESCRIPTION
 *  reset repeat count for fast del/navigate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_fast_del_nav_reset_repeat_count(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_fast_del_nav_handler
 * DESCRIPTION
 *  handle fast delete and navigation within specific time period
 * PARAMETERS
 *  type             [IN]     operation type
 *  time_period      [IN]     time period of operation
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_fast_del_nav_handler(wgui_inputs_fast_del_nav_oper_enum type, wgui_inputs_fast_del_nav_editor_enum editor, U32 time_period);

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_fast_del_pen_handler
 * DESCRIPTION
 *  handle fast delete and navigation pen event
 * PARAMETERS
 *  type             [IN]     operation type
 *  editor           [IN]     editor type
 *  pen_event        [IN]     pen event
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_fast_del_pen_handler(wgui_inputs_fast_del_nav_oper_enum type, wgui_inputs_fast_del_nav_editor_enum editor, mmi_pen_event_type_enum pen_event);
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_hide_items
 * DESCRIPTION
 *  Hide editor option menu items
 * PARAMETERS
 *  parent_id   [IN]        parent id
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_options_menu_hide_items(mmi_id parent_id, MMI_BOOL isHide);

#endif /* __WGUI_INPUTS_H__ */ 

