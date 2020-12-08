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
 *    Imc_pen.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for Imc_pen.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_TOUCH_SCREEN__

#ifndef __IMC_PEN_H__
#define __IMC_PEN_H__

#include "IMERes.h"
#include "mmi_frm_gprot.h"

#include "MMIDataType.h"
#include "ImeGprot.h"
#include "gui_virtual_keyboard_language_type.h"
#include "gui_data_types.h"
#include "wgui_categories_list.h"
#include "mmi_frm_input_gprot.h"

/*****************************************************************************
 *  Define
 *****************************************************************************/


typedef enum
{
    MMI_IMC_PEN_SORT_CAPITAL_FIRST,
    MMI_IMC_PEN_SORT_NON_CAPITAL_FIRST
} mmi_imc_pen_resort_type_enum;

#if defined(__MMI_IME_CANDIDATE_GRID__)
extern MMI_BOOL g_imc_enter_grid_state;
#endif

/*****************************************************************************
 *  Global Functions
 *****************************************************************************/
#if (!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || (defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && defined(__MMI_CSTAR_PHRASE_INPUT__)))
extern S32 mmi_imc_key_smart_phonetic_get_composition(S32 index);
#endif
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern S32 mmi_imm_get_input_mode_num_in_current_writing_language(void);
extern U16 mmi_imm_is_curr_allowed_wlang(S32 wlang);
extern S32 mmi_imm_get_writing_language_num(void);
extern mmi_imm_input_mode_enum mmi_imm_get_default_input_mode_of_curr_writing_language(void);
#endif
extern void reset_fixed_list(void);
extern MMI_BOOL vm_frm_is_active(void);
extern mmi_imm_input_mode_enum mmi_imm_get_default_input_mode_of_curr_writing_language(void);

#if defined(__MMI_CSTAR_PHRASE_INPUT__)
extern void mmi_imc_pen_get_candidates_qwerty_input_mode(void);
#endif
extern MMI_BOOL     mmi_imc_is_pen_disabled(void);

extern void mmi_imc_pen_update_hw_cand_by_index(S32 index);
extern MMI_BOOL mmi_imc_pen_init( void );
extern void     mmi_imc_pen_deinit( void );
extern MMI_BOOL mmi_imc_pen_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved );
#if defined(__MMI_VIRTUAL_KEYBOARD__)
extern  MMI_BOOL mmi_imc_pen_is_handwriting_vk(void);
#endif
extern void     mmi_imc_pen_activate( void );
extern void     mmi_imc_pen_deactivate( void );
extern void     mmi_imc_pen_disable_handwriting( void );
extern void     mmi_imc_pen_enable_handwriting( void );
extern void     mmi_imc_pen_change_handwriting_area( void );
extern void     mmi_imc_pen_enable_multiblock_handwriting( void );
extern void     mmi_imc_pen_disable_multiblock_handwriting( void );
extern mmi_imc_pen_handwriting_style_enum mmi_imc_pen_get_handwriting_style(void);
extern void     mmi_imc_pen_reset_ime_state(void);

#if defined(__MMI_VIRTUAL_KEYBOARD__) 
extern MMI_BOOL mmi_imc_pen_is_multiblock_handwriting_type(gui_virtual_keyboard_language_enum vk_type);
extern void     mmi_imc_pen_set_desired_vk_type(gui_virtual_keyboard_language_enum vk_type);
extern MMI_BOOL mmi_imc_pen_vk_insert_char(UI_character_type char_code);
extern MMI_BOOL mmi_imc_pen_set_vk_candidate(void);
extern void mmi_imc_pen_update_display_area_by_sym_buffer(void);
extern void mmi_imc_pen_set_vk_at_start(void);
extern MMI_BOOL mmi_imc_pen_is_symbol_vk_type(gui_virtual_keyboard_language_enum vk_type);
extern MMI_BOOL mmi_imc_pen_is_only_symbol_vk_type(gui_virtual_keyboard_language_enum vk_type);
extern void mmi_imc_pen_set_virtual_keyboard(gui_virtual_keyboard_language_enum vk_type, MMI_BOOL has_cand_box);

#if defined(__MMI_IME_VK_TYPE_QWERTY__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern void mmi_imc_pen_get_group_letters_from_vk(UI_character_type* character_array, S32 length);
#endif

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
extern void mmi_imc_pen_cursor_move_handler(gui_virtual_keyboard_language_enum prev_vk);
#endif /* defined(__MMI_IME_AUTO_CAPITALIZATION__) */
#if defined(__MMI_IME_FTE_ENHANCE__)
extern void mmi_imc_pen_set_history_is_vk_enlarge(MMI_BOOL on);
extern mmi_imc_pen_input_style_enum mmi_imc_pen_get_curr_input_style(void);
extern void mmi_imc_pen_set_user_desired_input_style(mmi_imc_pen_input_style_enum input_style);
extern void mmi_imc_pen_set_curr_input_style(mmi_imc_pen_input_style_enum input_style);
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__)  */


extern void mmi_imc_pen_softkey_up_post_hdlr(FuncPtr f);
extern void mmi_imc_pen_confirm_handwriting_selection(void);
extern void mmi_imc_pen_change_vk_by_capital_state(void);

#if defined(__MMI_IME_FTE_ENHANCE__)
extern void mmi_imc_pen_start_singleblock_handwriting(void);
extern void mmi_imc_pen_stop_singleblock_handwriting(void);
extern void mmi_imc_pen_clear_pen_repeat_event(void);
extern void mmi_imc_pen_reset_pen_repeat_event(void);
#endif

extern void mmi_imc_pen_restart_hw_timer(void);
extern void mmi_imc_pen_change_hw_cand_index(void);

extern void mmi_imc_pen_set_dialer_callback(MMI_BOOL (*funcptr)(mmi_imc_dialer_pen_code_enum pen_code, mmi_pen_event_type_enum pen_event));

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
extern void mmi_imc_pen_open_symbol_lock(void);
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
extern void mmi_imc_pen_vk_enable_single_block_hw(void);
#endif

extern void mmi_imc_pen_set_handwriting_style(void);

#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
extern void mmi_imc_pen_vk_icon_display_callback(
              U32 pen_symbol,
              gui_virtual_keyboard_display_callback_type_enum *flag,
              PU8 *text,
              PU8 *image,
              gui_virtual_keyboard_key_state_enum key_state);

#endif

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
extern S32 mmi_imc_pen_get_input_style_list(mmi_imc_pen_input_style_enum* style_array, PU16 strid_array, S32 array_size, S32* highlight);
#endif

extern void mmi_imc_pen_config_chinese_word_prediction_by_pen_enabled(MMI_BOOL is_enabled);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
extern gui_virtual_keyboard_event_enum mmi_imc_pen_vk_event_callback(gui_virtual_keyboard_pen_enum key_event, S32 key_param, U32 ret);
#endif
#if defined(__MMI_COSMOS_KEYPAD_BAR__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern void mmi_imc_pen_show_handwriting_vk(void);
#endif
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
extern void mmi_imc_pen_process_state_before_sliding(void);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern gui_virtual_keyboard_key_pos_info_struct mmi_imc_pen_get_keyinfo(void);
#endif
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) && defined(__MMI_IME_VK_TYPE_HANDWRITING__)
extern void mmi_imc_pen_change_vk_style_from_list(void);
extern void set_full_screen(void);
extern MMI_BOOL get_is_full_screen(void);
#endif //__MMI_IME_V3__
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern void mmi_imc_pen_handle_slider_close_on_123_input_mode(void);
void mmi_imc_pen_change_vk_style(void);
extern void mmi_imc_pen_set_vk_active_row(mmi_imm_input_type_enum input_type);
extern void mmi_imc_pen_process_vk_state_after_confirm_candidate(void);
extern void mmi_imc_pen_get_input_box_heigt(S32* x, S32* y, S32* width, S32* height);
extern MMI_BOOL mmi_imc_pen_vk_event_change_mode(mmi_pen_event_type_enum pen_event);
extern MMI_BOOL g_imc_pen_is_vk_caps_lock_down;
#endif /*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__*/

#if  defined(__MMI_IME_V3__)
extern void mmi_imc_pen_play_touch_feed_back(void);
#endif

#endif /* !defined(__IMC_PEN_H__) */ 

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_V3__)
extern void mmi_ime_reset_group_letters(const sIMEModeDetails * mode_details_ptr);
#endif

#endif /* #ifdef __MMI_TOUCH_SCREEN__ */

