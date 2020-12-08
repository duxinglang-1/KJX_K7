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
 *    Imm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for IMCtrl.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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


#ifndef __IMM_H__
#define __IMM_H__

#include "gui_data_types.h"
#include "ImeGprot.h"
#include "IMERes.h"

/* RHR ADD */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_virtual_keyboard_language_type.h"
/*****************************************************************************
*  golbal varible
*****************************************************************************/
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_V3__)
    #define MMI_IMM_QWERTY_MAX_LETTER_GROUPS  (28)
    #define MMI_IMM_QWERTY_MAX_GROUP_LETTER_NUM (20)
    #define MMI_IMM_MAX_GROUP_LETTER_SET (448)
    extern UI_character_type g_mmi_imm_group_letter_set[MMI_IMM_MAX_GROUP_LETTER_SET];
    extern UI_character_type g_mmi_imm_cur_lang_group_letter_table[MMI_IMM_QWERTY_MAX_LETTER_GROUPS][MMI_IMM_QWERTY_MAX_GROUP_LETTER_NUM]; 
#if defined(__MMI_IME_VK_TYPE_QWERTY__)
    extern UI_character_type g_mmi_imm_group_letter_set_for_vk[MMI_IMM_MAX_GROUP_LETTER_SET];
#endif
#endif

/*****************************************************************************
*  Define
*****************************************************************************/
#define   IMM_MAX_DISABLE_CHAR_NUM_BUF_LEN  32

typedef enum
{
    MMI_IME_HINT_FLAG_NONE = 0,
    MMI_IME_HINT_FLAG_INFO_BAR = 1,
    MMI_IME_HINT_FLAG_CSK = 2,
    MMI_IME_HINT_FLAG_VK_ICON = 4,
    MMI_IME_HINT_FLAG_LOWER_CASE = 0x10,
    MMI_IME_HINT_FLAG_UPPER_CASE = 0x20,
    MMI_IME_HINT_FLAG_FIRST_UPPER_CASE = 0x40,
    MMI_IME_HINT_FLAG_MAX
}mmi_ime_hint_flag_enum;

typedef enum
{
    MMI_IME_HINT_TYPE_STRING = 0,
    MMI_IME_HINT_TYPE_IMAGE,
    MMI_IME_HINT_TYPE_MAX
}mmi_ime_hint_type_enum;


typedef struct
{
    U8 display_flag;
    U8 hint_type;
    U16 hint_id;
}mmi_imm_input_mode_hint_item_struct, *mmi_imm_input_mode_hint_item_struct_p;

typedef struct
{
    mmi_imm_input_mode_enum mode_id;
    mmi_imm_input_mode_hint_item_struct_p hint_item_ptr;
}mmi_imm_input_mode_info_struct, *mmi_imm_input_mode_info_struct_p;

typedef struct
{
    mmi_imm_support_writing_lang_enum lang_id;
    UI_character_type new_word[20];
}mmi_imm_new_word_string_mapping_struct, *mmi_imm_new_word_string_mapping_struct_p;

typedef struct
{
    mmi_imc_pen_handwriting_type_enum hw_enum;
    U16 content_id;
} mmi_imm_hw_category_struct, *mmi_imm_hw_category_struct_p;

typedef struct
{
    mmi_imm_support_writing_lang_enum lang_id;
    mmi_imc_pen_handwriting_type_enum extra_block;
    U16 extra_block_ind_id;
} mmi_imm_hand_writing_category_info_struct, *mmi_imm_hand_writing_category_info_struct_p;

/*****************************************************************************
*  Global Functions
*****************************************************************************/
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_CSTAR__) && defined(__MMI_IME_V3__)
extern void mmi_imm_qwerty_get_group_letters_for_cur_lang(mmi_imm_support_writing_lang_enum search_lang);
#if defined(__MMI_IME_VK_TYPE_QWERTY__)  && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
extern void mmi_imm_get_group_letters_from_vk();
#endif
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
MMI_BOOL mmi_imm_is_vibration_enabled(void);
MMI_BOOL mmi_imm_is_sound_feedback_enabled(void);
MMI_BOOL mmi_imm_is_sound_feedback_enabled_for_ime(void);
MMI_BOOL mmi_imm_is_auto_space_enabled(void);
MMI_BOOL mmi_imm_memory_card_is_auto_space_enabled(void);
MMI_BOOL mmi_imm_pen_is_shift_state_enable_on_current_mode(void);

extern mmi_imm_input_mode_enum mmi_imm_vk_get_input_mode_according_smart_and_multitap(void);
extern S32 mmi_imm_get_curr_allow_input_mode_string_list_of_imev3(U16* strarray, S32 max);
extern S32 mmi_imm_get_curr_allow_input_mode_list_of_imev3(mmi_imm_input_mode_enum *mode_array, S32 max);

extern void mmi_imm_set_handwriting_default_input_mode(mmi_imm_input_mode_enum input_mode);
extern mmi_imm_input_mode_enum mmi_imm_get_handwriting_default_input_mode(void);

#endif

extern U32 mmi_imm_get_special_ext_input_type(void);
extern void mmi_imm_reset_allowed_and_disabled_list(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_imm_reset_allowed_and_disabled_list_vk(void);
#endif
extern MMI_BOOL mmi_imm_init(void);
extern void mmi_imm_connect(void);
extern void mmi_imm_disconnect(void);
extern MMI_BOOL mmi_imm_get_allowed_or_disabled_characters(MMI_BOOL * is_allowed, UI_string_type characters_list);

extern MMI_BOOL mmi_imm_is_change_input_mode_enabled(void);

extern MMI_BOOL mmi_imm_test_r2l_input(void);

extern MMI_BOOL mmi_imm_test_reset_allowed_and_disabled_list(void);
#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_imm_test_reset_allowed_and_disabled_list_vk(void);
#endif
extern void mmi_imm_set_allowed_and_disabled_list(MMI_BOOL value);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_imm_set_allowed_and_disabled_list_vk(MMI_BOOL value);
#endif
extern void mmi_imm_set_history_input_mode(mmi_imm_input_mode_enum input_mode);

extern mmi_imm_input_mode_enum mmi_imm_get_history_input_mode(void);

extern mmi_imm_input_mode_info_struct_p mmi_imm_get_curr_input_mode_hint_info(void);

extern MMI_BOOL mmi_imm_is_smart_alphabetic_input_mode_available(void);

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL mmi_imm_get_allowed_or_disabled_events(MMI_BOOL * is_allowed, gui_virtual_keyboard_pen_enum * events_list);
#endif /* __MMI_TOUCH_SCREEN__ */

#if  defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
void mmi_imm_set_curr_writing_lang_by_curr_mode(void);
#endif

#if defined(__MMI_IME_USER_DATABASE__)
extern UI_string_type mmi_imm_get_new_word_string_by_language(mmi_imm_support_writing_lang_enum lang_id);
#endif


#if defined(__MMI_IMC_CAPITAL_SWITCH__)
extern S32 mmi_imm_get_current_allowed_writing_language_num(void);
extern void mmi_imm_set_current_writing_lang(mmi_imm_support_writing_lang_enum lang);
extern mmi_imm_support_writing_lang_enum mmi_imm_get_not_used_desired_writing_language_from_history(void);
extern S32 mmi_imm_get_input_mode_num_in_current_writing_language(void);
#endif

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
extern void mmi_imm_set_special_key_icon(U32 special_key_flag, U32 special_key_lock_flag);
extern U16 mmi_imm_get_special_key_icon(void);
extern mmi_ime_hint_flag_enum mmi_imm_get_current_input_case(void);
extern void mmi_imm_config_special_key_validation(const sIMEModeDetails * mode_details_ptr);
extern MMI_BOOL mmi_imm_is_dead_character_of_current_lang(UI_character_type char_code);
extern UI_character_type mmi_imm_get_merged_character_of_current_lang(UI_character_type dead_char, UI_character_type original_char);
extern void mmi_imm_change_dead_character_lang_table(mmi_imm_support_writing_lang_enum lang);
extern MMI_BOOL mmi_imm_is_strict_morphology_language(mmi_imm_input_mode_enum input_mode);
#endif

extern const sIMEModeDetails * mmi_imm_get_input_mode_array_item(mmi_imm_input_mode_enum input_mode);

extern const sIMEModeDetails * mmi_imm_get_corresponding_multitap_mode(mmi_imm_input_mode_enum input_mode, U16 mode_case);

extern const sIMEModeDetails * mmi_imm_get_corresponding_smart_mode(mmi_imm_input_mode_enum input_mode, U16 mode_case);

extern const sIMEModeDetails * mmi_imm_get_corresponding_smart_lower_case_mode(mmi_imm_input_mode_enum input_mode);

extern S32 mmi_imm_get_multitap_input_mode_by_writing_language(mmi_imm_input_mode_enum *input_mode_table, mmi_imm_support_writing_lang_enum lang_id, S32 max_size);

extern MMI_BOOL mmi_imm_is_curr_capital_state_of_curr_input_mode(void);

extern const sIMEModeDetails * mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_input_mode_enum input_mode, mmi_ime_word_capital_state_enum cap_state);

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
extern mmi_imm_hand_writing_category_info_struct_p mmi_imm_get_hand_writing_category(mmi_imm_support_writing_lang_enum lang_id);
#endif


#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
extern MMI_BOOL mmi_imm_is_auto_capitalization_valid(void);
extern void mmi_imm_set_initial_input_mode_by_auto_capitalization(void);
extern void mmi_imm_config_auto_capitalization_validation(MMI_BOOL is_valid);
extern MMI_BOOL mmi_imm_memory_card_is_auto_capitalization_enabled(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imm_config_keyboard_type
 * DESCRIPTION
 * Set whetehr or not hwsetting to be displayed
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imm_config_handwriting_setting( MMI_BOOL is_available);

extern MMI_BOOL mmi_imm_is_current_mode_smart(void);

extern mmi_imm_input_mode_enum mmi_imm_get_first_allowed_input_mode_of_lang(mmi_imm_support_writing_lang_enum writing_lang);

extern mmi_imm_support_writing_lang_enum mmi_imm_get_wlang_by_index(U32 index);

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imm_init_pen_speed
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void mmi_imm_init_pen_speed(void);
extern MMI_BOOL mmi_imm_current_handwriting_is_enable(void);
#endif

MMI_BOOL mmi_imm_does_current_type_support_titlecase(void);
extern MMI_BOOL mmi_imm_is_seemless_switching_enable(void);
#endif /* !defined(__IMM_H__) */ 

