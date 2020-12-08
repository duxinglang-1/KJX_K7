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
 *    IndicRuleEngine.h
 *
 * Project:
 * --------
 *   Indic Languages
 *
 * Description:
 * ------------
 *   header file of Indic language engine 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_INDIC_RULE_ENGINE_H
#define MMI_INDIC_RULE_ENGINE_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "IndicEngineGprot.h"
#include "SSCStringHandle.h"
#include "IndicRuleEngineCommon.h"

/**************			EXTERN DEFINITION			*********************/

extern U32 *g_character_status_flag_p;
extern const ire_character_info_table_struct *g_lang_character_info_p;
extern indic_rules_ligature_enum indic_rules_current_set_language;
extern indic_rules_ligature_enum indic_rules_prefered_set_language;
extern BOOL r2lMMIFlag;

extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
const HindiRulesLangSSC HRLangSSC[] = 
{
#if defined(__MMI_LANG_HINDI__)
    {SSC_HINDI, MMI_HINDI_LANG},
#endif
#if defined(__MMI_LANG_MARATHI__)
    {SSC_MARATHI, MMI_MARATHI_LANG},
#endif
#if defined(__MMI_LANG_BENGALI__)
   {SSC_BENGALI, MMI_BENGALI_LANG},
#endif   
#if defined(__MMI_LANG_ASSAMESE__)   
    {SSC_ASSAMESE, MMI_ASSAMESE_LANG},
#endif    
};
#endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__) */ 

/**************			MACROS DEFINITION			*********************/

#define NORMAL_CON							0x00000001
#define RA_CON								0x00000002	/*Because there are 2 type of shiort ra one is r halant ka and other is ka halant ra*/
#define SMALL_CON							0x00000003	/*Because in some languages there small characters that come below the original characters*/
#define KANNADA_RA_CON				        0x00000004
#define CHILLU_CHARACTER					0x00000005
#define LIGATURE_USED_AS_CONSONANT			0x00000006
#define ALL_CONSONANT_TYPE					(NORMAL_CON | RA_CON | SMALL_CON | KANNADA_RA_CON | CHILLU_CHARACTER | LIGATURE_USED_AS_CONSONANT)

#define PRE_BASE_DEPVOWEL					0x00000008
#define POST_BASE_DEPVOWEL					0x00000010
#define BELOW_BASE_DEPVOWEL					0x00000018
#define ABOVE_BASE_DEPVOWEL					0x00000020
#define CENTER_BASE_DEPVOWEL				0x00000028
#define ABOVE_BASE_NORMAL_CON               0x00003001

/* Macros for position of characters */ 	/*For these characters we have to have a synch with font engine as to whether the charcter is in which base or who is to decide where the character lies.*/
#define PRE_BASE_POSITION					            0x00001000	/* Not used Anywhere*/
#define POST_BASE_POSITION					            0x00002000	/* Not used Anywhere*/
#define ABOVE_BASE_POSITION					            0x00003000	/*This is the deciding factor for the variables to lie on the same starting point as to where the the previous character has started*/
#define BELOW_BASE_POSITION                             0x00004000	/* uSed by Pixcom for Below base characters and other adjustments*/
#define CENTER_BASE_POSITION                            0x00005000	/* Never Used*/
#define SPECIAL_POST_BASE_POSITION                      0x00006000	/* Used for Kannada for adjusting the charaters*/
#define BELOW_AND_POST_BASE_POSITION                    0x00007000	/*Used By Pixcom to udjust the characters*/
#define POST_BASE_POSITION_REQ_CORRECTION               0x00008000	/*Used for Kannada and telugu for adjustment purposes*/
#define BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE 0x00009000	/**/
#define POST_BASE_POSITION_REQ_CORRECTION2              0x0000a000	/*There is no need of this Enum as the work done by both correction2 is same*/
#define POST_BASE_POSITION_CONSIDERING_PREV_OFFSET		0x0000b000	/**/

/* Macro to check entry of vowel after vowel */
#define MASK_CHECK_ENTER_AFTER_VOWEL					0x00010000

#define INDEPVOWEL							0x00000040

#define HALANT								0x00000080
#define NORMALSIGN							0x00000100
#define TAMIL_HALANT_SIGN					0x00000180

#define LIGATURE							0x00000200
#define RIGHT_ALIGNED_CHARACTER				0x00000400
#define DIGITS								0x00000800

/* Macros used for masking */ 
#define MASK_HIGHER_ORDER_BYTES				0x000001FF	/* to identify the consonant, dep vowel, indep vowel, sign types */
#define MASK_POSITION_BYTES				    0x0000F000	/*To identify positions*/
#define MASK_CHAR_TYPE_FOR_VALIDATION       0x000E0000  /* to identify the character type (IRE_CHAR_TYPE_0, IRE_CHAR_TYPE_1, IRE_CHAR_TYPE_2 or IRE_CHAR_TYPE_3) */
#define MASK_CHARACTER_ALIGNMENT			0x00000600	/**/

#define MASK_LANG_SPECIFIC					0xFFF00000	/* to identify the language specific attributes */

#define  TWO								2
/*	To Convert U8 to U16 (unicode value) */
#define IRE_LANG_ID_CONVERT_U8_U16(pCharacter) ((pCharacter)[0]|((pCharacter)[1]<<8))

/*	To Convert previous val U8 to U16 (unicode value) */
#define IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(pCharacter) ((pCharacter - 2)[0]|((pCharacter - 2)[1]<<8))

/*	To Convert next value U8 to U16 (unicode value) */
#define IRE_LANG_ID_CONVERT_NEXT_VAL_U8_U16(pCharacter) ((pCharacter + 2)[0]|((pCharacter + 2)[1]<<8))

/*  To calculate the language ID of the current character from the previous character language ID */
#define IRE_GET_CHARACTER_LANG_ID_FROM_PREV_CHAR(character, lang_id)\
{\
    U8 call_to_function = MMI_TRUE;\
    if((take_prev_char_id == MMI_TRUE) && (g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index != 0))\
    {\
        if((character >= g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.start_range) && \
	       (character <= g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info.end_range)) \
	    {\
	       lang_id = g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index;\
	       call_to_function = MMI_FALSE;\
        }\
    }\
    take_prev_char_id = MMI_TRUE;\
    if(call_to_function)\
    {\
        lang_id = ire_get_character_lang_id(character);\
    }\
    g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index = lang_id;\
}

/* To set the previous charactres language ID equal to the current characters lang ID */
#define IRE_SET_PREV_CHAR_LANG_ID(lang_id)\
{\
	g_indic_rule_engine_cntx.ire_prev_char_lang_id.lang_id_index = lang_id;\
}

/* To set the previous charactres info table equal to the current characters charactres info table */
#define IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(lang_id)\
{\
	g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info = indic_lang_table_info = indic_lang_char_info_table[lang_id];\
}

/* To set the previous charactres info table equal to the current characters ligature info table */
#define IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(lang_id)\
{\
	g_indic_rule_engine_cntx.ire_prev_char_lang_id.ire_prev_char_table_info = indic_lang_table_info = indic_lang_ligature_info_table[lang_id];\
}

/*to check whether the current character lies in the language range*/
#if defined (__MMI_MULTITAP_BANGLA_SPEC__)

#define  IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(start_cluster,character,startRange,endRange,nFill)\
{\
	if((character<startRange) || (character>endRange))\
	{\
	   	if((character != BENGALI_L_RA) && (character != BENGALI_H_RA) && (character != BENGALI_L_YA))\
	   		{\
		start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;\
		g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);\
		return nFill;\
	}\
	   }\
}

#else

#define  IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(start_cluster,character,startRange,endRange,nFill)\
{\
	if((character<startRange) || (character>endRange))\
	{\
		start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;\
		g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);\
		return nFill;\
	}\
}

#endif

#define  IRE_CHECK_NEXT_CHARACTER_LANG_RANGE_VARIANT(start_cluster,character,startRange,endRange,nFill)\
{\
    if((character<startRange) || (character>endRange))\
	{\
        start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len + 1] = (U16) NULL;\
        g_indic_rule_engine_cntx.g_cluster_start_p += (2 *(nFill));\
        return nFill;\
    }\
}\

#define IRE_LANG_ID_FILL_CLUSTER_SMALL_CONS()						\
{																	\
   ++nFill;															\
   start_char+=2;													\
   g_indic_rule_engine_cntx.g_display_buffer_len++;					\
}
/*	fills the temporary buffer with unicode values,
	increment the array index and start character pointer	*/
#define IRE_LANG_ID_FILL_CLUSTER()									\
{																	\
   start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = IRE_LANG_ID_CONVERT_U8_U16(start_char);   \
   nFill++;															\
   start_char+=2;													\
   g_indic_rule_engine_cntx.g_display_buffer_len++;					\
}                                           

#define IRE_LANG_ID_END_CLUSTER(start_cluster,start_char,nFill)	\
{																\
	if( start_char == g_indic_rule_engine_cntx.g_cluster_end_p)	\
	{															\
		start_cluster[g_indic_rule_engine_cntx.g_display_buffer_len] = (U16)NULL;	                \
		g_indic_rule_engine_cntx.g_cluster_start_p += (2 * nFill);	\
		return nFill;											\
	}															\
}

/*to check whether the current character lies in the language range*/
#define  IRE_CHECK_CHARACTER_LANG_RANGE(character,startRange,endRange)  ( ((character<startRange )|| (character>endRange))? (0) : (1) )

/* This macro will be use dto modify the startRange, EndRange and char_status_flag_p if the 
 * the current character is a ligatue and it does not lies in the 1st ligature Range.
 * For such cases we will use the 2nd ligature range
 */
#define IRE_MODIFY_LIGATURE_RELATED_INFORMATION(character,char_status_flag_p,startRange,endRange,lang_id)\
{\
	if (!((character >= startRange) && (character <= endRange)))\
	{\
		if (character & 0xE000)\
		{\
			ire_indic_languages_table_struct indic_ligature2_table_info;\
			indic_ligature2_table_info  = indic_lang_ligature2_info_table[lang_id];\
			startRange                  = indic_ligature2_table_info.start_range;\
			endRange                    = indic_ligature2_table_info.end_range;\
			char_status_flag_p          = indic_ligature2_table_info.indic_char_info_flag_p;\
		}\
		else\
		{\
			MMI_ASSERT(!((character >= startRange) && (character <= endRange)));\
		}\
	}\
}

/*macro to fill the global structure variable with full character info*/
#if defined (__MMI_MULTITAP_BANGLA_SPEC__)

#define IRE_IDENTIFY_CHARACTER(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	U32 lang_id = 0;\
	if((character == BENGALI_L_RA) || (character == BENGALI_H_RA) || (character == BENGALI_L_YA))\
		{\
		lang_id = ire_get_character_lang_id(character);\
		IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(lang_id);\
	char_status_flag_p		= indic_lang_table_info.indic_char_info_flag_p;\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - 0xEA00));\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	0x3F;\
	IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(lang_id);\
	char_status_flag_p		= indic_lang_table_info.indic_char_info_flag_p;\
}\
		else\
			{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	MASK_HIGHER_ORDER_BYTES;\
			}\
}
#else

#define IRE_IDENTIFY_CHARACTER(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	MASK_HIGHER_ORDER_BYTES;\
}
#endif
/*macro to fill the global structure variable with full character position info*/
#define IRE_IDENTIFY_CHARACTER_POSITION(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	MASK_POSITION_BYTES;\
}

/*macro to check if entry of vowel is allowed after vowel or not */
#define IRE_CHECK_VOWEL_ENTRY_ATTRIBUTE(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	MASK_CHECK_ENTER_AFTER_VOWEL;\
}

/*macro to check if entry of vowel is allowed after vowel or not */
#define IRE_LANGUAGE_SPECIFIC_ATTRIBUTE(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= (mCharacterStatusFlag & MASK_LANG_SPECIFIC) >> 20;\
}

/* macro to identify the start range and char_status_flag_p for the input character, 
 * based on whether the character is a unicode character or a proprietary ligature
 */
#define IRE_IDENTIFY_LANGUAGE_START_RANGE(character)\
{\
    if (!((character) & 0xE000))\
    {\
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_CHAR_INFO_TABLE(langIdIndex);\
    }\
    else\
    {\
        IRE_SET_PREV_CHAR_INFO_TABLE_FROM_LIGATURE_INFO_TABLE(langIdIndex);\
    }\
    startRange = indic_lang_table_info.start_range;\
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;\
}

/* macro to find out the character type used for validating the candidates (IRE_CHAR_TYPE_0, IRE_CHAR_TYPE_1 ,IRE_CHAR_TYPE_2 or IRE_CHAR_TYPE_3) */
#define IRE_IDENTIFY_CHAR_TYPE_FOR_VALIDITY(character,char_status_flag_p,startRange,mCharacterStatusFlag)\
{\
	mCharacterStatusFlag		= 0;\
	g_lang_character_info_p		= (char_status_flag_p + (character - startRange)-1);\
	g_character_status_flag_p	= (U32*)g_lang_character_info_p;\
	mCharacterStatusFlag		= *g_character_status_flag_p;\
	mCharacterStatusFlag		= mCharacterStatusFlag &	MASK_CHAR_TYPE_FOR_VALIDATION;\
}
/*Con + Hal + Con2+  PreBase M -> Prebase M + Con + Hal + Con2  */
/*Con + PreBase M -> Prebase M + Con */
#define IRE_REORDER_PREBASE_MATRA(nEntries,tempCount,uTempVar)\
{\
	uTempVar = start_cluster[nEntries - 1];\
	for (tempCount = nEntries - 2; tempCount >= 0; tempCount--)\
	{\
		start_cluster[tempCount + 1] = start_cluster[tempCount];\
	}\
	start_cluster[0] = uTempVar;\
}

/*Ra + Hal + Con + PostBase M -> Con + Postbase M + Ra + Hal*/
/*Ra + Hal + Con -> Con + Ra + Hal*/
#define IRE_REORDER_RA_HALANT_CONS_SEQUENCE(nEntries,tempCount,uTempVar,i)\
{\
	for (i = 0; i <= 1; i++)\
	{\
		uTempVar = start_cluster[0];\
		for (tempCount = 0; tempCount < nEntries - 1; tempCount++)\
		{\
			start_cluster[tempCount] = start_cluster[tempCount + 1];\
		}\
		start_cluster[tempCount] = uTempVar;\
	}\
} 

/* Example :
 * Con + RA + Hal + NUkta + Halant -> RA + Hal + Con + NUkta + Halant
 * Con + + Hal + Con + RA + Hal + NUkta + Halant -> RA + Hal + Con + Hal + Con + NUkta + Halant 
 */
#define IRE_UNDO_RA_HAL_REORDERING(nEntries,tempCount,uTempVar,i)\
{\
	for (i = 0; i <= 1; i++)\
	{\
		uTempVar = start_cluster[nEntries - 1];\
		for (tempCount = nEntries - 1; tempCount > 0; tempCount--)\
		{\
			start_cluster[tempCount] = start_cluster[tempCount - 1];\
		}\
		start_cluster[tempCount] = uTempVar;\
	}\
}

/*Con + Hal + Con + Hal + Ra + Hal -> Con + Hal + Hal + Con + Ra + Hal*/
/*Con + Hal + Con + Hal + Con + Hal + Ra + Hal -> Con + Hal + Hal + Con + Hal + Con + Ra + Hal*/
#define IRE_REORDER_CONS_HALANT_KANNADA_RA_HALANT_SEQUENCE(nEntries, tempCount, uTempVar)\
{\
	uTempVar = start_cluster[nEntries - 3];\
	for (tempCount = nEntries - 3; tempCount > 2; tempCount--)\
	{\
		start_cluster[tempCount] = start_cluster[tempCount - 1];\
	}\
	start_cluster[tempCount] = uTempVar;\
}


/* This macro will reorder the entry at index startReorderingVarIndex to the the index (nEntries -1) and shift
 * the move the entire from  index (startReorderingVarIndex+ 1) to (nEntries -1) to the to the previous entry 
 * EXAMPLE: KA + x + hal + KA
 * if we use macro 
 * IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(1, 4),
 * then the final output will be KA + hal + KA + X*/
#define IRE_REORDER_KANNADA_POST_BASE_MATRA_AFTER_RULES(startReorderingVarIndex, nEntries, tempCount, uTempVar)\
{\
	uTempVar = glyphoutput[startReorderingVarIndex];\
	for (tempCount = startReorderingVarIndex; tempCount < (nEntries - 1); tempCount++)\
	{\
		glyphoutput[tempCount] = glyphoutput[tempCount + 1];\
	}\
	glyphoutput[tempCount] = uTempVar;\
}


/*Ra + Hal + Con + Hal -> Con + Ra + Hal + Hal*/
/*Ra + Hal + Con + Hal + Con + Hal -> Con + Hal + Con + Ra + Hal + Hal*/
#define IRE_REORDER_RA_HALANT_CONS_HALANT_SEQUENCE(nEntries,tempCount,uTempVar,i)\
{\
        U16 temp_unicode =0;\
	uTempVar = start_cluster[nEntries - 1];\
	for (i = 0; i <= 1; i++)\
	{\
		temp_unicode = start_cluster[0];\
		for (tempCount = 0; tempCount < nEntries - 2; tempCount++)\
		{\
			start_cluster[tempCount] = start_cluster[tempCount + 1];\
		}\
		start_cluster[tempCount] = temp_unicode;\
	}\
	start_cluster[nEntries - 1] = uTempVar;\
}
/*CON1 + CenterBase M - > Pre + CON1 + Post*/
#define IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster,nEntries,char_table_p,uTempVar,size,tempCount)\
{\
	uTempVar = start_cluster[nEntries - 1];\
	for (tempCount = nEntries - 2; tempCount >= 0; tempCount--)\
	{\
		start_cluster[tempCount + 1] = start_cluster[tempCount];\
	}\
	start_cluster[0]		        = char_table_p[size].output_buffer_glyph[0];\
	start_cluster[nEntries]			= uTempVar;\
	start_cluster[nEntries + 1]		= char_table_p[size].output_buffer_glyph[1];\
	start_char+=2;\
	nFill++;\
}

/*CON1 + Hal + CON2 - > CON1 + CON2 + Hal*/
#define IRE_REORDER_SMALL_CONS_HAL_CONS(nEntries,tempCount,uTempVar)\
{\
	uTempVar = start_cluster[1];\
	for (tempCount = 1; tempCount < nEntries - 1; tempCount++)\
	{\
		start_cluster[tempCount] = start_cluster[tempCount + 1];\
	}\
	start_cluster[tempCount] = uTempVar;\
}

/*CON1 + Hal + CON2 + PostBase M- > CON1 + PostBase M + CON2 + Hal*/
/*CON1 + Hal + CON2 + Hal + CON3 + PostBase M- > CON1 + PostBase M + CON2 + Hal + CON3 + Hal*/
#define IRE_REORDER_SMALL_CON_POST_BASE_MATRA(nEntries,tempCount,uTempVar,i)\
{\
	for (tempCount = 1; tempCount <= nEntries - 2; tempCount++)\
	{\
		uTempVar = start_cluster[nEntries - tempCount ];\
        start_cluster[nEntries - tempCount] = start_cluster[nEntries - tempCount - 1];\
		start_cluster[nEntries - tempCount - 1 ] = uTempVar;\
	}\
}


typedef enum 
{
	IRE_REORDER_TYPE_INVALID,
	IRE_REORDER_TYPE_PREBASE,
	IRE_REORDER_TYPE_CENTERBASE,
	IRE_RA_CON
} ire_reorder_type_info_enum;

#endif /* MMI_INDIC_RULE_ENGINE_H */ 


