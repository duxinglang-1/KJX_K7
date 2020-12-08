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
 *    Imc_key.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for Imc_key.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __IMC_KEY_H__
#define __IMC_KEY_H__

#include "MMIDataType.h"
#include "IMERes.h"
#include "ImeGProt.h"
/* RHR ADD*/
#include "gui_buttons.h"
#include "kal_general_types.h"
#include "Imc_symbol.h"
#include "gui_data_types.h"
/*****************************************************************************
 *  Define
 *****************************************************************************/

/*****************************************************************************
 *  Extern Global Variables
 *****************************************************************************/
extern icontext_button MMI_softkeys[];
#if defined(__MMI_IME_CANDIDATE_GRID__)

extern MMI_BOOL g_imc_prev_state_is_grid ;
#endif


/*****************************************************************************
 *  Global Functions
 *****************************************************************************/
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
extern S32 mmi_imc_key_smart_phonetic_get_candidate(MMI_BOOL match_comp);
#endif

#if defined (__MMI_CSTAR_PHRASE_INPUT__)
extern MMI_BOOL mmi_imc_key_smart_phonetic_candidate_select(void);
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
extern U32 mmi_frm_qwerty_get_invalid_customized_special_key(void);
#endif

extern void vadp_p2v_show_symbol_picker(void);

extern MMI_BOOL mmi_imc_key_init( void );
extern void     mmi_imc_key_deinit( void );
extern MMI_BOOL mmi_imc_key_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved );
extern void     mmi_imc_key_reset_ime_state(void);
extern void     mmi_imc_key_activate( void );
extern S32 mmi_imc_key_stroke_get_candidate(void);
extern void     mmi_imc_key_deactivate( void );
extern void     mmi_imc_key_set_softkey(void);
extern void     mmi_imc_key_redraw_softkey(void);
extern void     mmi_imc_key_common_arrow_key_handler(mmi_imc_key_custom_value key_code, U16 event_type);
extern void     mmi_imc_key_smart_alphabetic_confirm_candidate(void);
extern MMI_BOOL mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt(void);
extern S32 mmi_imc_key_smart_alphabetic_insert_candidate(S32 cand_index);
extern S32 mmi_imc_key_smart_alphabetic_get_candidate(S32 index);
#if defined(__MMI_IME_CANDIDATE_FILTER__)
extern MMI_BOOL mmi_imc_key_smart_alphabetic_filter_candidate(UI_string_type cand);
#endif
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
extern void mmi_imc_key_change_candidate_case_by_previous_string(void);
#endif

extern void mmi_imc_key_set_csk(void);
extern U16 mmi_imc_key_get_last_imc_key_code(void);
extern mmi_imc_key_custom_value mmi_imc_key_get_last_translated_imc_key_code(void);

extern void mmi_immc_config_softkeys_changeable(MMI_BOOL is_changeable);

#ifdef __MMI_CLIPBOARD__ 
extern MMI_BOOL mmi_imc_key_clipboard_pre_key_handler(U16 key_code, U16 key_type);
#endif /* __MMI_CLIPBOARD__ */

extern S16 mmi_imc_key_get_mmi_key_code_of_symbol_key(mmi_imc_symbol_key_enum symbol_key);

extern void mmi_imc_key_group_key_down_int(U16 key_code, U16 key_type);
extern void mmi_imc_key_group_key_up_int(U16 key_code, U16 key_type);
extern void mmi_imc_key_group_key_long_int(U16 key_code, U16 key_type);
extern void mmi_imc_key_group_key_repeat_int(U16 key_code, U16 key_type);


extern void mmi_imc_key_multitap_alphabetic_input_confirm( void );

extern void mmi_imc_key_set_softkey_label(UI_string_type s, WGUI_SOFTKEY_ENUM key);

extern void mmi_imc_key_set_softkey_icon(PU8 icon, WGUI_SOFTKEY_ENUM key);

extern void mmi_imc_key_set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);

extern void mmi_imc_key_clear_softkey_handler(WGUI_SOFTKEY_ENUM key);

extern void mmi_imc_key_show_softkey(WGUI_SOFTKEY_ENUM key);

extern void mmi_imc_key_register_softkey_handler(WGUI_SOFTKEY_ENUM key);

extern void mmi_imc_key_set_key_handler(FuncPtr funcPtr, U16 keyCode, U16 keyType);

extern FuncPtr mmi_imc_key_get_key_handler(U16 keyCode, U16 keyType);

extern void mmi_imc_key_clear_key_handler(U16 keyCode, U16 keyType);

#if defined(__MMI_IMC_CAPITAL_SWITCH__)
extern void mmi_imc_key_entry_change_language_screen(void);
#endif

#ifdef __MMI_CSTAR_PHRASE_INPUT__
extern S32 mmi_imc_key_change_highlighted_composition_cstar_style(S32 index);
extern void mmi_imc_key_commit_input_box_content(void);
#endif

#endif /* !defined(__IMC_KEY_H__) */ 

