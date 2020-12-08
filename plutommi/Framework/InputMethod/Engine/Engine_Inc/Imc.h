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
 *    Imc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for Imc.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

#ifndef __IMC_H__
#define __IMC_H__

#include "IMERes.h"

#include "mmi_frm_gprot.h"
#include "ImeGprot.h"
#include "ImmProt.h"
//#include "Imui.h"
#include "Imc_config.h"
#include "Word_engine.h"

/* RHR ADD */

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "Imc_symbol.h"
#include "wgui_categories_list.h"

/*****************************************************************************
 *  Define
 *****************************************************************************/
#if defined(__MMI_IME_USER_DATABASE__)
#define MMI_IMC_ADD_NEW_WORD_POPUP_TIMEOUT_DURATION   (1000)
#define MMI_IMC_MAX_MULTITAP_INPUT_MODES_NUM_OF_A_LANG  (5)
#endif

/*****************************************************************************
 * Enums
 *****************************************************************************/
#define MMI_IMC_CUSTOM_IME_STATE_SIZE (20)

#define MMI_IMC_SELECT_LIST_ITEM_NUM_MAX 20
typedef enum
{
	MMI_IMC_POST_DATA_NONE,
	MMI_IMC_POST_SYMBOL_DATA,  //the symbol insert from symbol picker screen
	MMI_IMC_POST_NEWWORD_DATA, // the new word saved from new word screen
} mmi_imc_post_data_enum;

typedef enum {
    MMI_IMC_STATE_NONE = 0,
    MMI_IMC_STATE_INITIAL,
    MMI_IMC_STATE_CUSTOM_BEGIN,
    MMI_IMC_STATE_CUSTOM_END = MMI_IMC_STATE_CUSTOM_BEGIN + MMI_IMC_CUSTOM_IME_STATE_SIZE,
    MMI_IMC_STATE_SMART_CANDIDATE,
    MMI_IMC_STATE_PRE_SMART_CANDIDATE,
    MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC,
    MMI_IMC_STATE_MULTITAP,
    MMI_IMC_STATE_SPELL_INPUTING,
    MMI_IMC_STATE_SPELL_MULTITAP,
    MMI_IMC_STATE_CAND_SELECTING,
	MMI_IMC_STATE_CAND_SELECTING_GRID,
	MMI_IMC_STATE_ASSOC_SELECTING_GRID,
	MMI_IMC_STATE_SPELL_INPUTING_GRID,
	MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX,
	MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC,
    MMI_IMC_STATE_ASSOC_SELECTING,
    MMI_IMC_STATE_PRE_ASSOC_SELECTING,
    MMI_IMC_STATE_HAND_WRITING,
    MMI_IMC_STATE_HAND_WRITING_CAND,
    MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING,
    MMI_IMC_STATE_SPELL_WITH_INPUT, 
    MMI_IMC_STATE_CAND_SELECT_WITH_INPUT,
    MMI_IMC_STATE_VK_CAND,
    MMI_IMC_STATE_VK_CAND_MULTITAP,
    MMI_IMC_STATE_PREDICTING,
    MMI_IMC_STATE_INPUT,  /* state for cstar input */
    MMI_IMC_STATE_NEW_WORD_INITIAL,
    MMI_IMC_STATE_NEW_WORD_MULTITAP,
    MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP,
    MMI_IMC_STATE_CLIPBOARD_MARK_TEXT,
    MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN,
    MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS,
    MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU,
    MMI_IMC_STATE_WORD_HIGHLIGHTED,
    MMI_IMC_STATE_PASSWORD_PREVIEW,
	MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID
} mmi_imc_state_enum;


/*****************************************************************************
 * Typedef
 *****************************************************************************/
//#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
typedef enum
{
	OPEN,
	CLOSE
}mmi_imc_slider_status;
//#endif
typedef U32 (*mmi_imc_message_funcptr)( void *, mmi_imc_message_struct_p );

typedef struct
{
    mmi_imc_post_data_enum  curr_data_type;
    UI_character_type curr_data[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
}   mmi_imc_post_process_data_struct;


typedef struct
{
    U16                          symb_buff[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    U16                          symb_buff_backup[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    UI_character_type           cand_buff[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];
    UI_character_type           comp_buff[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    U8                            cand_valid_flags[(MMI_IMC_MAX_CANDIDATE_PAGE*MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER)/8];
#else
    U8                            cand_valid_flags[(MMI_IMC_MAX_CANDIDATE_PAGE*MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN)/8];
#endif
    S32                          cand_check_cnt;
    U16                          key_buffer[MMI_IMC_MAX_KEY_BUFFER_SIZE]; /* mmi_imc_symbol_key_enum */
    S32                         key_element_length;
    U8                          symb_count;
    U8                          symb_count_backup;
    U8                          cand_count;
    U8                          cand_select;
    U16                         cand_first_index[MMI_IMC_MAX_CANDIDATE_PAGE + 1];
    U8                          cand_page;
    U8                          comp_count;
    U8                          comp_select;
    U8                          comp_first_index[MMI_IMC_MAX_COMPOSITION_PAGE + 1];
    U8                          comp_page;
    U8                          old_comp_select;
    U8                          old_comp_page;
    U16                        tone;
    UI_character_type           pre_string[MMI_IMC_MAX_PRE_STRING_LEN + 1];
    UI_string_type              permit_string_ptr;
    U8                          permit_string_len;
    UI_string_type              forbid_string_ptr;
    U8                          forbid_string_len;
    S32                        cand_length;
    mmi_ime_word_capital_state_enum  capital_state;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    U32                        special_key_flag_table[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    UI_character_type          dead_char;
#endif
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)    
    S32                         key_buffer_cusor; /* used in smart phonetic input to indicate the key element index */
    UI_character_type           input_buff[MMI_IMC_MAX_INPUT_BUFFSIZE];
    S32                          input_length;
    S32                          input_confirm_length;
    U8                          cand_match_len[MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE];
    U16                          key_buffer_backup[MMI_IMC_MAX_KEY_SEQUENCE_RECORD + 1][MMI_IMC_MAX_KEY_BUFFER_SIZE]; /* mmi_imc_symbol_key_enum */
    U16                          key_len_backup[MMI_IMC_MAX_KEY_SEQUENCE_RECORD + 1];
    UI_character_type    select_cand[MMI_IMC_MAX_KEY_SEQUENCE_RECORD + 1][MMI_IMC_MAX_KEY_BUFFER_SIZE + 1]; /* mmi_imc_symbol_key_enum */
    S32                        key_seq_index; /* the active key sequence */
    S32                        key_seq_num; /* total key symbol number */
#endif
#if defined(__MMI_IME_CANDIDATE_FILTER__)
    MMI_BOOL              cand_filter; /* to store candidate filter status. After recover input, it should be true and then if there is any modification to the input, it should be false; */
    UI_character_type    cand_check[MMI_IMC_MAX_KEY_BUFFER_SIZE + 1];
    U8 filter_page;
#endif

#if defined(__MMI_IME_USER_DATABASE__)
    UI_character_type          first_candidate[MMI_IMC_MAX_KEY_BUFFER_SIZE + 1];
    S32                        active_multitap;
    S32                        multitap_buffer_len;
    UI_character_type          multitap_buffer[MULTITAP_MAX_KEY_CHAR * 4];
    UI_character_type          new_word[MMI_IMC_MAX_KEY_BUFFER_SIZE + 1];
    mmi_imc_key_custom_value   multitap_key_code;
    S32                        char_index;
    UI_string_type             new_word_prompt;
#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    mmi_ime_word_capital_state_enum  capital_state_seq[MMI_IMC_MAX_KEY_BUFFER_SIZE + 1];
    MMI_BOOL                   capital_lock;
#endif
}   mmi_imc_global_data_struct, *mmi_imc_global_data_struct_p;


typedef struct
{
    U32 style;
    U32 force_style;
    U32 force_style_flag;
    MMI_BOOL is_clean_force_style_flag_allowed;
    mmi_imui_param_struct backup_imui_param;
}mmi_imc_ui_style_param_struct, *mmi_imc_ui_style_param_struct_p;

/*****************************************************************************
*  Global Functions
*****************************************************************************/
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern void mmi_imm_set_current_writing_lang(mmi_imm_support_writing_lang_enum lang);
extern S32 mmi_imm_get_current_allowed_writing_language_num(void);
#endif

extern void wgui_hide_left_softkey(void);
#ifdef __MMI_IME_MEMORY_CARD_SUPPORT__
extern const sIMEModeDetails * mmi_imc_memory_card_change_input_mode(const sIMEModeDetails *mode_details_ptr);
extern MMI_BOOL mmi_imc_memory_card_is_language_supported(const sIMEModeDetails *mode_detail_ptr, S32 lang_index);
#endif
extern void mmi_imc_change_state_from_grid_to_initial(void);
#if defined(__MMI_IME_CANDIDATE_GRID__)
extern void mmi_imc_get_candidates_word_engine_grid(mmi_imc_state_enum state);
extern void mmi_imc_set_state_acc_to_mode(void);
extern MMI_BOOL mmi_imc_is_grid_state(void);
extern MMI_BOOL g_imc_is_change_from_grid;
extern void mmi_imc_update_smart_pinyin_composition(void);
#endif
#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
extern  void  mmi_imc_process_simulated_slider_event(mmi_imc_slider_status status);
#endif
extern void  mmi_imc_repaint_screen(void);
extern void mmi_imc_show_inputmode_list(void);
extern void mmi_imc_pen_set_history_input_style(mmi_imc_pen_input_style_enum input_style);

extern UI_string_type mmi_imc_get_select_string_from_candidate_box(void);
extern  void mmi_imc_gdi_lcd_freeze(BOOL lcd_freeze);
extern U32 mmi_imc_get_state_imui_set(mmi_imc_state_enum state);
extern void     mmi_imc_start_timer(S32 count, void (*callback) (void), void (*cancel_callback) (void));
extern void     mmi_imc_restart_timer(S32 count, void (*callback) (void), void (*cancel_callback) (void));
extern void     mmi_imc_cancel_timer(void); /* Called by interrup event*/
extern FuncPtr mmi_imc_delete_timer(void);
#if defined(__MMI_TOUCH_SCREEN__)
extern MMI_BOOL     mmi_imc_is_handwriting_disabled(void);
extern void mmi_imc_set_hw_type_validity(MMI_BOOL v);
extern MMI_BOOL mmi_imc_get_hw_type_validity(void);
#endif
extern MMI_BOOL     mmi_imc_is_key_disabled(void);
extern MMI_BOOL mmi_imc_is_symbol_picker_disable(void);
extern MMI_BOOL mmi_imc_is_fixed_input_box(void);
extern void mmi_imc_draw_indicator_floating(MMI_BOOL Background_redraw);
extern mmi_imc_global_data_struct_p     mmi_imc_get_global_data( void );
extern void mmi_imc_reset_global_data(void);

extern UI_string_type mmi_imc_get_candidate_by_index(UI_character_type * cand_buff, U8 index);

extern void mmi_imc_clear_symbol_buffer(void);
extern void mmi_imc_select_candidate_from_candidate_box(void);
extern MMI_BOOL mmi_imc_change_candidate_box_page(void);

extern void mmi_imc_change_highlighted_candidate_from_candidate_box(U8 candidate_index);

extern S32 mmi_imc_change_highlighted_composition_from_composition_box(U8 candidate_index);

extern S32 mmi_imc_update_candidate_box_by_query_result(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page);

extern S32 mmi_imc_update_candidate_box_by_query_result_ext(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page,
        MMI_BOOL            is_vertical);

extern S32 mmi_imc_update_composition_box_by_query_result(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page);

extern S32 mmi_imc_update_composition_box_by_query_result_ext(
        UI_string_type      result_buffer,
        U8                  result_cnt,
        MMI_BOOL            next_page,
        MMI_BOOL            is_auto_resizable);

extern void mmi_imc_string_to_title_case(UI_string_type string);
extern void mmi_imc_string_to_lower_case(UI_string_type string);
extern void mmi_imc_string_to_upper_case(UI_string_type string);
extern MMI_BOOL mmi_imc_candidate_check(UI_string_type cand, S32 len);
extern MMI_BOOL mmi_imc_select_composition_from_composition_box(void);

extern void mmi_imc_redraw_imui(U32 imui_set);

extern void mmi_imc_common_arrow_key_handler(mmi_imc_key_custom_value key_code, U16 event_type);
extern mmi_imc_state_enum  mmi_imc_get_state( void );
    #if defined(__MMI_IME_USER_DATABASE__)
extern S32 mmi_imc_new_word_str_len();
#endif
extern MMI_BOOL mmi_imc_change_composition_box_page(void);
extern void  mmi_imc_set_state( mmi_imc_state_enum state);
extern void  mmi_imc_get_candidates_from_word_engine( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
extern void mmi_imc_candidate_index_mapping(S32 *index);
extern void mmi_imc_set_candidate_valid_flag(S32 index, S32 flags, S32 len);
extern void mmi_imc_reset_candidate_valid_flag(void);
extern void mmi_imc_change_alphabetic_candidate_case(UI_string_type cand, mmi_ime_word_capital_state_enum state);
extern void mmi_imc_change_candidate_list_caps(mmi_ime_word_capital_state_enum state);
extern mmi_ime_word_capital_state_enum mmi_imc_get_input_mode_caps(const sIMEModeDetails * mode_details_ptr);
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
extern void mmi_imc_change_candidate_list_by_caps_seq(void);
extern void mmi_imc_change_alphabetic_candidate_case_by_caps_seq(UI_string_type cand, mmi_ime_word_capital_state_enum *state_seq);
extern void mmi_imc_set_caps_seq_by_cur_state(S32 index);
#endif
    
#if defined(__MMI_IME_MAGIC_ONE__)
extern MMI_BOOL mmi_imc_get_magic_key_down(void);
extern void mmi_imc_set_magic_key_down(MMI_BOOL val);
extern MMI_BOOL mmi_imc_change_to_magic_state(void);
extern void mmi_imc_back_from_magic_state(void);
extern MMI_BOOL mmi_imc_check_magic_state(void);
#endif

#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
extern void mmi_imc_update_input_area(S32 highlight_start, S32 highlight_num, S32 wave_start, S32 wave_num, S32 cursor_index);
extern void mmi_imc_update_candidate_as_null(void);
extern S32 mmi_imc_input_area_add_string(UI_string_type in);
extern MMI_BOOL mmi_imc_input_area_delete_string(S32 len);
extern MMI_BOOL mmi_imc_input_area_add_space(void);
extern void mmi_imc_reset_input_area(void);
extern void mmi_imc_reset_key_seq_data(void);
#endif

MMI_BOOL mmi_imc_get_csk_config(void);

#if defined(__MMI_IME_USER_DATABASE__)
extern void mmi_imc_update_word_frequency_for_string(UI_string_type str_ptr);
extern void mmi_imc_entry_spell_new_word_screen(void);
#endif

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
extern void  mmi_imc_get_associates_from_word_engine( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif

#ifdef __MMI_CLIPBOARD__ 
extern void mmi_imc_clipboard_show_hide_cascading_menu(void);
extern void mmi_imc_clipboard_show_option_menu(void);
#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
extern void mmi_imc_clipboard_show_option_floating_menu(void);
#endif /* __MMI_CLIPBOARD_FLOATING_MENU__ */
extern MMI_BOOL mmi_imc_clipboard_option_handle(U16 menu_id);
extern MMI_BOOL mmi_imc_clipboard_is_disable(void);
extern MMI_BOOL mmi_imc_clipboard_is_allow_to_enter_state(void);
extern void mmi_imc_clipboard_redraw_screen_by_state(void);

#endif /* __MMI_CLIPBOARD__ */

extern void mmi_imc_print_string_inserted_to_editor(UI_string_type str_ptr, S32 str_len);

extern void mmi_imc_config_printing_character(MMI_BOOL is_on);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
extern void mmi_imc_config_floating_candidate_box(MMI_BOOL is_on);
#endif
extern void mmi_imc_config_ui_style(U32 ui_style, MMI_BOOL is_on);
extern void mmi_imc_config_force_ui_style(U32 ui_style, MMI_BOOL is_on);

extern void mmi_imc_config_floating_state(MMI_BOOL is_floating);
extern MMI_BOOL mmi_imc_is_in_atv_editor(void);
extern MMI_BOOL mmi_imc_disable_ime_handlers(void);
extern void mmi_imc_clean_force_ui_style(U32 ui_style);
extern void mmi_imc_config_clean_force_ui_style_valitation(MMI_BOOL allow_clean);

#if defined(__MMI_TOUCH_SCREEN__)
extern MMI_BOOL mmi_imc_is_vk_disabled(void);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

#if defined(__MMI_IME_FTE_ENHANCE__)
extern void mmi_imc_config_single_block_handwriting_state(MMI_BOOL config);
extern MMI_BOOL mmi_imc_get_single_block_handwriting_state(void);
#endif

#if defined(__MMI_VIRTUAL_KEYBOARD__)

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)

#define MMI_VIRTUAL_KEYBOARD_LANG (mmi_imc_get_current_vk_type())
#define MMI_IME_SHOW_VIRTUAL_KEYBOARD wgui_show_virtual_keyboard

#else

#define MMI_VIRTUAL_KEYBOARD_LANG (mmi_imc_get_current_vk_type())
#define MMI_IME_SHOW_VIRTUAL_KEYBOARD wgui_virtual_keyboard_show

#endif

#if defined(__MMI_IME_V3__)
extern mmi_imm_input_mode_enum mmi_imc_get_next_input_mode_from_list(void);
#endif 

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern void mmi_imc_initial_selection_mode_list(void);

#endif

#endif /*defined(__MMI_VIRTUAL_KEYBOARD__)*/

extern void mmi_imc_redraw_ime_indicator(void);

extern mmi_ime_word_capital_state_enum mmi_imc_get_candidate_case_before_cursor(void);

extern mmi_ime_word_capital_state_enum mmi_imc_get_candidate_case_before_candidate(void);

extern mmi_ime_word_capital_state_enum mmi_imc_get_candidate_case_by_text_buffer(U8 *text_start, U8 *text_end);

extern MMI_BOOL mmi_imc_change_input_mode_according_to_capital_state(mmi_ime_word_capital_state_enum capital_state);

extern void mmi_imc_get_ui_style_param(mmi_imc_ui_style_param_struct_p ui_style);

extern void mmi_imc_set_ui_style_param(mmi_imc_ui_style_param_struct_p ui_style);


#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
extern void mmi_imc_entry_config_smart_input_method_screen_with_sg(mmi_id g_id);
#endif

extern void mmi_imc_set_inputmode(U32 inputmode_index);

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern void mmi_imc_set_wlang(U32 wlang_index);
#endif

extern MMI_BOOL mmi_imc_is_rotated(void);
extern void mmi_imc_set_is_rotated(MMI_BOOL is_rotated);

extern MMI_BOOL mmi_imc_is_in_custom_state(mmi_imc_state_enum state);

#ifdef __MMI_CSTAR_PHRASE_INPUT__
extern S32 mmi_imc_change_highlighted_composition_from_composition_box(U8 index);
extern void mmi_imc_commit_input_box_content(void);
#endif

extern mmi_imc_slider_status mmi_imc_get_slider_status(void);
#ifdef __MMI_COSMOS_KEYPAD_SLIDER__
extern void mmi_imc_set_slider_status(mmi_imc_slider_status);
#if 0 
/* under construction !*/
#endif
#endif

#if defined(__MMI_IME_V3__)
extern S32 mmi_imc_get_high_light_item_in_list(mmi_imm_input_mode_enum input_mode, mmi_imm_input_mode_enum* mode_array, S32 mode_num);
extern void mmi_imc_show_popup_list(    S32 x, 
                                        S32 y, 
                                        S32 number_of_items,
                                        U16 *list_of_items,
                                        S32 highlighted_item,
                                        mmi_int_funcptr_type confirm_callback, 
                                        FuncPtr cancel_callback);

extern void mmi_imc_init_select_mode_list_index(void);
#else
extern void mmi_imc_show_popup_list(    S32 x, 
                                        S32 y, 
                                        S32 number_of_items,
                                        U16 *list_of_items,
                                        S32 highlighted_item,
                                        mmi_int_funcptr_type confirm_callback, 
                                        FuncPtr cancel_callback,
										UI_string_ID_type title);
#endif

extern void mmi_imc_config_auto_cap_flag(MMI_BOOL val);
extern void mmi_frm_scrn_set_active_input_buf_size (U16 input_buf_size); /* For removing build warning */
#endif /* !defined(__IMC_H__) */ 

