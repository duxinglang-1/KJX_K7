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
 *    IndicEngineGprot.h
 *
 * Project:
 * --------
 *   Languages
 *
 * Description:
 * ------------
 *   Header file of Indic language Engine 
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_INDIC_ENGINE_GPROT_H
#define MMI_INDIC_ENGINE_GPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "IndicRuleEngineCommon.h"

/* RHR */
#include "gui_inputs.h"
#include "gui_ems.h"
#include "gui_data_types.h"
#include "kal_general_types.h"

extern single_line_input_box MMI_inline_singleline_inputbox;
#ifdef UI_EMS_SUPPORT
extern UI_character_type gui_EMS_current_character(UI_EMS_input_box *b);
#endif
extern UI_character_type gui_multi_line_current_character(multi_line_input_box *b);
extern UI_character_type gui_single_line_current_character(single_line_input_box *b);
extern ire_prev_char_struct ire_prev_char_lang_id;
struct ire_g_context_struct
{
	S32 g_prev_char_text_x;		/*Starting X of the previous character*/
	S32 g_prev_char_dwidth;
	S32 g_prev_char_width;
	#if !defined(__MMI_IRE_SLIM__)
	S32 g_prev_char_btext_x;
	S32 g_prev_char_bdwidth;
	S32 g_new_bline;
	#endif
	S32 g_use_multitap;
	S32 g_reset_hindi_pms;
	S32 g_indic_padding;
	S32 g_new_line;
	S32 parse_hindi;
	S32 g_display_buffer_len;
	S32 g_ire_arabic_language_character_count;
	S32 g_ire_indic_language_character_count;
	S32 g_ire_width_adjustment_required;
	U16 g_temp_array[G_MAX + 1];
	U16 g_prev_character;
	PU8 g_cursor_end_curr_cluster_p;
	PU8 g_cluster_start_p;
	PU8 g_cluster_end_p;
	PU8	padding_val;
	U32 small_cons;
	U32 small_cons_halant_present;
    U32 sign_cons_or_below_base;    
	#if defined ( __MMI_BIDI_ALG__ ) && defined ( __MMI_INDIC_ALG__ )
	U32 zi_check_for_singleline;
	#endif
	U32 error_correction_for_rendering;      
    U16 g_vk_indic_disable_grey;
    MMI_BOOL g_indic_cluster_last_char; 
    ire_prev_char_struct ire_prev_char_lang_id;
};

extern struct ire_g_context_struct g_indic_rule_engine_cntx;

/*********************	EXTERN DEFINITIONS	*******************************/

/*This method will identify the characters which will participate in cluster formation */
extern S32 ire_get_cluster(PU16 buffer);
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
extern S32 ire_check_cluster_for_length(PU8 cluster);
extern void ire_shuffling_editor_buffer_for_bengali_spec(U8* b_text, S32 str_len);
extern void ire_reshuffling_editor_buffer_for_bengali_spec(U8* b_text, S32 str_len);
#endif

/*This method will search for the next cluster and returns the pointer to the begining of the cluster*/
extern PU8 ire_get_next_cluster_p(PU8 previous_cursor_p, PU8 current_cursor_p);

extern PU8 ire_get_next_cluster_p_with_size(PU8 previous_cursor_p, PU8 current_cursor_p, S32 *cluster_size);
/*This method will find the current cluster and	copy it into the output buffer*/
extern S32 ire_get_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, PU16 output_buffer);

/*This method checks the input unicode value and returns the correponding language Id*/
extern U32 ire_get_character_lang_id(U16 character);

/*This method will search for the next cluster and returns the pointer to the begining of the cluster and 
 will also give the  size of current cluster in no. of pixels*/ 
extern PU8 ire_get_next_cluster_p_with_size(PU8 previous_cursor_p, PU8 current_cursor_p, S32 *cluster_size);

/*This method will return the size of cluster in numbers of pixels*/
extern S32 ire_size_of_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, U16 cursor);

/*This method will apply grammer rules on the input cluster buffer and copy the output buffer i.e glyphoutput*/
extern S32 ire_language_rules(PU16 glyphoutput, PU16 cluster, S32 nentry);

/*This method will find the length of cluster (special case CON + HALANT + CON + HALANT.......)*/
/* extern S32 ire_get_consonant_cluster(PU16 *start_cluster, PU8 *start_char, S32 nentry); */

/* extern S32 ire_get_small_cons_cluster(PU16 *start_cluster, PU8 *startchar, S32 nentry); */

/*This method will search the previous cluster and returns the pointer to the begining of cluster*/
extern PU8 ire_get_prev_cluster_p(PU8 text_p, PU8 cursor_p);

/*This method will calculate the width and height of the the input text*/
extern S32 ire_get_string_width_height(UI_string_type text);

extern void ire_get_multitap_text_x(S32 *ptext_x, U16 current_character, S32 Char_Range, S32 check_char);

/*This method will calculate the width, dwidth based upon the type of input characters*/
extern void ire_get_text_x(PS32, U16, S32, U16, U16);

extern void ire_get_bordered_text_x(PS32, U16, S32);

#if defined (__MMI_INDIC_ALG__) && defined (__MMI_BIDI_ALG__)
/*This method will apply the language rules on the input string*/
extern void ire_get_indic_rules_for_whole_string(PU8 String, PU8 temp_buffer);
#endif /* defined (__MMI_INDIC_ALG__) && defined (__MMI_BIDI_ALG__) */

/*This method will identify the character type like consonant, dep vowel etc*/
extern S32 ire_identify_character_type(U16 currentCharacter);

/*This method will identify the character whether it belongs to sign category or not*/
extern S32 ire_identify_sign_range(U16 currentCharacter);

extern S32 ire_identify_char_position(U16 currentCharacter);
extern S32 ire_identify_char_alignment(U16 currentCharacter);
extern S32 ire_is_character_ext_consonant_capable(U16 prevCharacter) ;
extern S32 ire_is_character_nukta(U16 currentCharacter); 

/* This method identifies for rendering correction and adds delta correction only for signs*/
extern S32 ire_small_con_rendering_correction(U16 currentCharacter);

/**/
extern UI_string_type get_marathi_single_line_multitap_string(S32);

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
extern MMI_BOOL overwrite_current_language_for_hindi_rules_based_on_input_method(void);

/*This method will set the current language*/
extern void set_current_language_for_hindi_rules(void);

/*This method will restore the current language and update the flag*/
extern void restore_current_language_for_hindi_rules(void);
#endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__) */ 

/* This method is used to do the memory comparison between 2 memory blocks starting end in areverse manner */
extern U8 mmi_ire_reverse_memcmp(const U16 *source, const U16 *dest, U8 count);

/*  Some times after the language rules have been applied , 
 *	we need to adjuct/reorder some of the	character. For this we will call a 
 *	function corresponding to a specific language to adjust/reorder the 
 *	characters, according to the requirement. For malayalam language this API is used
 */
extern void ire_adjust_after_language_rules_for_malayalam(U16 *glyphoutput_buffer, S32 nentry_buffer);

/*  Some times after the language rules have been applied , 
 *	we need to adjuct/reorder some of the	character. For this we will call a 
 *	function corresponding to a specific language to adjust/reorder the 
 *	characters, according to the requirement. For kannada language this API is 
 *  used for handling the display for special(two part) post base matras
 */
extern void ire_adjust_after_language_rules_for_kannada(U16 *glyphoutput_buffer, S32 nentry_buffer);

/*  Some times after the language rules have been applied , 
 *	we need to adjuct/reorder some of the	character. For this we will call a 
 *	function corresponding to a specific language to adjust/reorder the 
 *	characters, according to the requirement. For telugu language this API is 
 *  used for handling the display in the situation in which glyphoutput contains
 *  SMALL_CON + DV + NORMAL_CON + ......
 */
extern void ire_adjust_after_language_rules_for_telugu(U16 *glyphoutput, S32 nentry_buffer);

/*********************	MACRO DEFINITIONS	*******************************/
#define ZWNJ					0x200C
#define ZWJ						0x200D

#define  ire_init_cluster_start_p(buffer)\
{\
	g_indic_rule_engine_cntx.g_cluster_start_p = buffer;\
}

#define ire_init_cluster_end_p(buffer)\
{\
	g_indic_rule_engine_cntx.g_cluster_end_p = buffer;\
}

#define IRE_WIDTH_ADJUSTMENT_REQUIRED()     g_indic_rule_engine_cntx.g_ire_width_adjustment_required = 1
#define IRE_WIDTH_ADJUSTMENT_NOT_REQUIRED() g_indic_rule_engine_cntx.g_ire_width_adjustment_required = 0
#define IRE_IS_OFFSET_REQUIRED() 			g_indic_rule_engine_cntx.g_ire_width_adjustment_required
#define ire_get_cluster_start_p() g_indic_rule_engine_cntx.g_cluster_start_p
#define ire_increment_cluster_start_p(value) g_indic_rule_engine_cntx.g_cluster_start_p += value;

#define IRE_IS_CHAR_TYPE_CONSONANT(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_CON)			? (1) : (0)

#define IRE_IS_CHAR_TYPE_DEP_VOWEL(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_DEPVOWEL)	? (1) : (0)

#define IRE_IS_CHAR_TYPE_INDEP_VOWEL(ch) 	(ire_identify_character_type(ch) == IRE_CHAR_TYPE_INDEPVOWEL)	? (1) : (0)

#define IRE_IS_CHAR_TYPE_SIGN(ch)			(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_SIGN)		? (1) : (0)

#define IRE_IS_CHAR_TYPE_HALANT(ch)			(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_HALANT)		? (1) : (0)
	
#define IRE_IS_CHAR_TYPE_HALANT1(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_HALANT1)		? (1) : (0)

#define IRE_IS_CHAR_TYPE_DIGIT(ch)			(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_DIGIT)		? (1) : (0)

#define IRE_IS_CHAR_TYPE_LIGATURE(ch)		(ire_identify_character_type(ch)  == IRE_CHAR_TYPE_LIGATURE)	? (1) : (0)

#define IRE_UI_INDIC_SIGN_RANGE(ch)			(ire_identify_sign_range(ch)) ? (1) : (0)/*Not used anywhere can be scrapped*/

/* Macro to find whether the rendering correction is required for the dependendant vowel
 * KANNADA_DV_U		= 0x0cc1
 * KANNADA_DV_UU	= 0x0cc2
 */	
#if defined(__MMI_LANG_KANNADA__)
#define IRE_IS_DV_RENDERING_CORRECTION_REQUIRED(ch)	(((U16)(ch) == 0x0cc1) || ((U16)(ch) == 0x0cc2)) ? (1) : (0)
#endif /* defined(__MMI_LANG_KANNADA__) */

/*To check whether the character lies in the Indic language range*/
#define IRE_INDIC_LANGUAGE_RANGE(ch)   ( ( (((U16)(ch)>=0x0900) && ((U16)(ch)<=0x0D7F)) || ((U16)(ch) == ZWJ) || ((U16)(ch) == ZWNJ) || (((U16)(ch)>=0x177F) && ((U16)(ch)<=0x17FF)) || (((U16)(ch)>=0x0E80) && ((U16)(ch)<=0x0EFF))  || (((U16)(ch)>=0x0FFF) && ((U16)(ch)<=0x109F))) ?(1) : (0) )

#define IRE_GET_CHARACTER_LANG_ID(unicode)  ire_get_character_lang_id(unicode)
#define IRE_INDIC_CHARACTER_UCS2_RANGE(x)  ( ( (((U16)(x) >= 0x900) && ((U16)(x) <= 0x0D7F)) || (((U16)(x) > 59647) && ((U16)(x) < 61012)) || (((U16)(x) > 40960) && ((U16)(x) < 42191)) || ((U16)(x) == ZWJ) || ((U16)(x) == ZWNJ) || (((U16)(x) > 0x177F) && ((U16)(x) < 0x17FF)) || (((U16)(x) > 0x0E80) && ((U16)(x) < 0x0EFF)) || (((U16)(x) > 0x0FFF) && ((U16)(x) < 0x109F)) || (((U16)(x) > 0XE700) && ((U16)(x) <= 0XE7B8)) || (((U16)(x) > 0xE7FF) && ((U16)(x) <= 0xE8C2))) ?(1) : (0) )
#define IRE_IS_PREV_CURR_SAME_LANG(PREV,CURR) ((((PREV) & (0xff80)) ^ ((CURR) & (0xff80)) )? (0):(1))
extern U8 ire_IsValidInput(U16 *Unicode, U8);
extern U8 ire_IsvalidInput_from_adaption(U16 *Unicode, U16 strlen);
extern U8 ire_IsValidInput_int(UI_string_type candidate, U8 strlen, UI_string_type previous_string);

#define ire_get_display_buffer_len()					g_indic_rule_engine_cntx.g_display_buffer_len				
#define ire_reset_use_multitap()						g_indic_rule_engine_cntx.g_use_multitap=0
#define ire_set_use_multitap_multi_line()				g_indic_rule_engine_cntx.g_use_multitap=1
#define ire_set_use_multitap_single_line()				g_indic_rule_engine_cntx.g_use_multitap=2
#define ire_set_use_multitap_inline_single_line()	    g_indic_rule_engine_cntx.g_use_multitap=3
#define ire_current_input_box_type()					g_indic_rule_engine_cntx.g_use_multitap
#define ire_disable_indic_rules_parsing()				g_indic_rule_engine_cntx.parse_hindi=1
#define ire_enable_indic_rules_parsing()				g_indic_rule_engine_cntx.parse_hindi=0
#define ire_is_indic_rules_parsing()					(!(g_indic_rule_engine_cntx.parse_hindi))
#define ire_disable_indic_reset_hindi_params()			g_indic_rule_engine_cntx.g_reset_hindi_pms=1
#define ire_enable_indic_reset_indic_params()			g_indic_rule_engine_cntx.g_reset_hindi_pms=0
#define ire_is_reset_indic_params()						(!(g_indic_rule_engine_cntx.g_reset_hindi_pms))
#define ire_indic_padding_value(val)					g_indic_rule_engine_cntx.g_indic_padding=val;
#define ire_indic_padding_def_value()					g_indic_rule_engine_cntx.g_indic_padding=0;

#if defined ( __MMI_BIDI_ALG__ ) && defined ( __MMI_INDIC_ALG__ )
#define ire_check_arabic_and_indic()                    g_indic_rule_engine_cntx.zi_check_for_singleline
#define ire_reset_check_arabic_and_indic()			    g_indic_rule_engine_cntx.zi_check_for_singleline = 0;	
#define ire_set_check_arabic_and_indic()			    g_indic_rule_engine_cntx.zi_check_for_singleline = 1;
#endif /* defined ( __MMI_BIDI_ALG__ ) && defined ( __MMI_INDIC_ALG__ ) */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#define ire_reset_indic_params()\
						   {\
							   g_indic_rule_engine_cntx.g_prev_char_text_x	= 0;\
                               g_indic_rule_engine_cntx.g_prev_char_dwidth	= 0;\
                               g_indic_rule_engine_cntx.g_prev_char_width	= 0;\
                               g_indic_rule_engine_cntx.g_prev_character	= 0;\
                               g_indic_rule_engine_cntx.g_new_line          = 0;\
						   }

#define IRE_IS_RENDERING_CORRECTION()       g_indic_rule_engine_cntx.error_correction_for_rendering
#define IRE_RESET_RENDERING_CORRECTION()    g_indic_rule_engine_cntx.error_correction_for_rendering = 0
#define IRE_SET_RENDERING_CORRECTION(ch)    ire_small_con_rendering_correction(ch)
#define IRE_GET_RENDERING_CORRECTION() g_indic_rule_engine_cntx.error_correction_for_rendering
#define ire_vk_grey_disable() g_indic_rule_engine_cntx.g_vk_indic_disable_grey = 1;
#define ire_vk_grey_enable()  g_indic_rule_engine_cntx.g_vk_indic_disable_grey = 0;
#define ire_vk_get_grey()     g_indic_rule_engine_cntx.g_vk_indic_disable_grey
#define IRE_QUERY_WORD_LAST_CHAR() g_indic_rule_engine_cntx.g_indic_cluster_last_char
#define IRE_SET_WORD_LAST_CHAR() (g_indic_rule_engine_cntx.g_indic_cluster_last_char = MMI_TRUE)
#define IRE_RESET_WORD_LAST_CHAR() (g_indic_rule_engine_cntx.g_indic_cluster_last_char = MMI_FALSE)

/* Different language Id's */
typedef enum
{
	IRE_LANGUAGE_ID_INVALID						= 0x00,
	IRE_LANGUAGE_ID_HINDI						= 0x01,	
    IRE_LANGUAGE_ID_BENGALI						= 0x02,
    IRE_LANGUAGE_ID_PUNJABI						= 0x03,
    IRE_LANGUAGE_ID_GUJARATI					= 0x04,
    IRE_LANGUAGE_ID_ORIYA						= 0x05,
    IRE_LANGUAGE_ID_TAMIL						= 0x06, 
    IRE_LANGUAGE_ID_TELUGU						= 0x07,
    IRE_LANGUAGE_ID_KANNADA						= 0x08,
    IRE_LANGUAGE_ID_MALAYALAM					= 0x09,
    IRE_LANGUAGE_ID_SINHALA						= 0x0A,
    IRE_LANGUAGE_ID_THAI						= 0x0B,
	IRE_LANGUAGE_ID_LAO						= 0x0C,
	IRE_LANGUAGE_ID_KHMER						= 0x0D,
	IRE_LANGUAGE_ID_MYANMAR						= 0x0E,
	IRE_LANGUAGE_ID_ENGLISH						= 0x0F,
	/****************************************************************************
	 *
	 * Add any new language id here
	 *
	 ****************************************************************************/
    IRE_LANGUAGE_ID_MAX
} ire_language_id_enum;

#endif /* MMI_INDIC_ENGINE_GPROT_H */

/*************Bit pattern definition of gLangStatusFlag********/
/*
	
	MSB........................................................LSB
	15	14	13	12	11	10	9	8	7	6	5	4	3	2	1	0 
	.	.	.	.	.	.	.	.	.	.	.	.	.								
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	0	0		-	INVALID_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	0	1		-	IRE_NORMAL_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	1	0		-	IRE_SPECIAL_RA_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	0	1	1		-	IRE_SMALL_CONSONANT
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	0	0		-
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	0	1		-
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	1	0		-
	.	.	.	.	.	.	.	.	.	.	.	.	.	1	1	1		-
	.	.	.	.	.	.	.	.	.	.	.	.	.
	.	.	.	.	.	.	.	.	.	.	.	.	.  
	.	.	.	.	.	.	.	.	.		0	0	0					-	INVALID_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	0	0	1					-	IRE_PRE_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	0	1	0					-	IRE_POST_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	0	1	1					-	IRE_BELOW_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	1	0	0					-	IRE_ABOVE_BASE_DEP_VOWEL
	.	.	.		.	.	.	.	.		1	0	1					-	IRE_CENTER_BASE_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	1	1	0					-	IRE_MAX_DEP_VOWEL
	.	.	.	.	.	.	.	.	.	.	1	1	1					-
	.	.		.	.	.	.	.	.	.
	.	.	.	.	.	.	.	.	.	0								-	IRE_INVALID_INDEP_VOWEL
	.	.	.	.	.	.	.	.	.	1								-	IRE_INDEP_VOWEL
	.	.	.	.	.	.	.	.	.								
	.	.	.	.	.	.	.	0	0									-	IRE_INVALID_SIGN
	.	.	.	.	.	.	.	0	1									-	IRE_HALANT_SIGN
	.	.	.	.	.	.	.	1	0									-	IRE_NORMAL_SIGN
	.	.	.	.	.	.	.	1	1									-	IRE_TAMIL_HAL_SIGN
	.	.	.	.	.	.	.
	.	.	.	.	.
	.	.	.	.	.	0	0											-	IRE_INVALID_LIGATURE
	.	.	.	.	.	0	1											-	IRE_NORMAL_LIGATURE
	.	.	.	.	.													
	.	.	.	.	0													-	IRE_INVALID_DIGIT
	.	.	.	.	1													-	IRE_NUMERIC_DIGIT
	.	.	.
	0	0	0	0														-   IRE_NO_POSITION			
	0	0	0	1														-	IRE_PREBASE_POSITION	
	0	0	1	0														-	IRE_POSTBASE_POSITION	
	0	0	1	1														-	IRE_ABOVE_BASE_POSITION	
	0	1	0	0														-	IRE_BELOW_BASE_POSITION	
	0	1	0	1														-	IRE_CENTER_BASE_POSITION
	0	1	1	0														-	IRE_MAX_POSITION		
	0	1	1	1														-

	MSB........................................................LSB		
	31	30	29	28	27	26	25	24	23	22	21	20	19	18	17	16
												
												0	0	0	0	0		- padding
												0	0	0	0	1
												.	.	.	.	.
												.	.	.	.	.
												.	.	.	.	.
												1	1	1	1	1



typedef struct languageFlag
{

	U32 consonant			:3;					//	bits for different consonant		
	U32 dep_vowel			:3;					//	bits for different dependent vowel	
	U32 indep_vowel			:1;					//	bits for independent vowel			
	U32 sign				:2;					//	bits for differnt sign				
	U32 ligature			:2;					//	bits for different ligature			
	U32 digit				:1;					//	bits for different digit			
	U32 char_position		:4;					//	bits for rendering info				
	U32 padding				:16;				//	bits for unicdoe value of character	
		
}gLanguageStatusFlag;

*/

