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
 *  Lao.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "IndicEngineGprot.h"
#include "Lao.h"

/****************************************************************************** 
* External Global variables
***************************************************************************** */

/****************************************************************************** 
* External Global Functions
***************************************************************************** */

/****************************************************************************** 
* Global variables
***************************************************************************** */
#if defined(__MMI_LANG_LAO__)

const ire_character_info_table_struct lao_character_info_table[] = 
{
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0e81 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0e82 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e83 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0e84 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e85 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e86 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0e87 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0e88 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e89 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},		/* 0x0e8A */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e8B */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e8C */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0e8D */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e8E */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0e8F */
	
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 0x0e90 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 0x0e91 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 0x0e92 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 0x0e93 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e94 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e95 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e96 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e97 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* 0x0e98 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e99 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e9A */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e9B */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e9C */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	 /* 0x0e9D */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e9E */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0}, /* 0x0e9F */
	
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ea0 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ea1 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ea2 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ea3 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ea4 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ea5 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ea6 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ea7 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ea8 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ea9 */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},		/* 0x0eaA */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0eaB */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0eaC */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0eaD */
	{IRE_SMALL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0eaE */	
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0,  0, 0},	/* 0x0eaF */
	
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0eb0 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},	/* 0x0eb1 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0eb2 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0eb3 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},	/* 0x0eb4 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},	/* 0x0eb5 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},	/* 0x0eb6 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},	/* 0x0eb7 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_BELOW_BASE_POSITION, 0, 0, 0},	/* 0x0eb8 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_BELOW_BASE_POSITION, 0, 0, 0},	/* 0x0eb9 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ebA */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},	/* 0x0ebB */
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_BELOW_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},	/* 0x0ebC */
	//{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},	/* 0x0ebD */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 0x0ebD */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ebE */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 0x0ebF */
	
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ec0 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ec1 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ec2 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ec3 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},	/* 0x0ec4 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0,  0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},
	{0, 0, 0, IRE_NORMAL_SIGN, IRE_RIGHT_ALIGNED_CHARACTER, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_4, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 0x0ed0 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},// work aroud for cursor issue.
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	
    //{IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},
	//{IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	
};



const ire_glyph_info_table_struct LAO_C_KO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_KO, 0x0}, {LAO_C_KO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_KHO_SUNG_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_KHO_SUNG, 0x0}, {LAO_C_KHO_SUNG, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_KHO_TAM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_KHO_TAM, 0x0}, {LAO_C_KHO_TAM, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_NGO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_NGO, 0x0}, {LAO_C_NGO, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_C_CO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_CO, 0x0}, {LAO_C_CO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_SO_TAM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_SO_TAM, 0x0}, {LAO_C_SO_TAM, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_NYO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_NYO, 0x0}, {LAO_C_NYO, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_C_DO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_DO, 0x0}, {LAO_C_DO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_TO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_TO, 0x0}, {LAO_C_TO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_THO_SUNG_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_THO_SUNG, 0x0}, {LAO_C_THO_SUNG, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_THO_TAM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_THO_TAM, 0x0}, {LAO_C_THO_TAM, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_NO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_NO, 0x0}, {LAO_C_NO, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_C_BO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_BO, 0x0}, {LAO_C_BO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_PO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_PO, 0x0}, {LAO_C_PO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_PHO_SUNG_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_PHO_SUNG, 0x0}, {LAO_C_PHO_SUNG, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_FO_TAM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_FO_TAM, 0x0}, {LAO_C_FO_TAM, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_PHO_TAM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_PHO_TAM, 0x0}, {LAO_C_PHO_TAM, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_C_FO_SUNG_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_FO_SUNG, 0x0}, {LAO_C_FO_SUNG, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_MO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_MO, 0x0}, {LAO_C_MO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_YO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_YO, 0x0}, {LAO_C_YO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_LO_LING_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_LO_LING, 0x0}, {LAO_C_LO_LING, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_LO_LOOT_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_LO_LOOT, 0x0}, {LAO_C_LO_LOOT, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_C_WO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_WO, 0x0}, {LAO_C_WO, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_SO_SUNG_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_SO_SUNG, 0x0}, {LAO_C_SO_SUNG, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_HO_SUNG_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_HO_SUNG, 0x0}, {LAO_C_HO_SUNG, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_O_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_O, 0x0}, {LAO_C_O, 0x0}},
};
const ire_glyph_info_table_struct LAO_C_HO_TAM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_C_HO_TAM, 0x0}, {LAO_C_HO_TAM, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_S_ELLIPSIS_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_S_ELLIPSIS, 0x0}, {LAO_S_ELLIPSIS, 0x0}},
};
    
    /* INDEPENDENT VOWLES */
const ire_glyph_info_table_struct LAO_IV_A_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_A, 0x0}, {LAO_IV_A, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_MAIKAN_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_MAIKAN, 0x0}, {LAO_DV_MAIKAN, 0x0}},
};

const ire_glyph_info_table_struct LAO_IV_AA_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_AA, 0x0}, {LAO_IV_AA, 0x0}},
};
const ire_glyph_info_table_struct LAO_IV_AM_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_AM, 0x0}, {LAO_IV_AM, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_I_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_I, 0x0}, {LAO_DV_I, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_II_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_II, 0x0}, {LAO_DV_II, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_Y_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_Y, 0x0}, {LAO_DV_Y, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_DV_YY_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_YY, 0x0}, {LAO_DV_YY, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_U_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_U, 0x0}, {LAO_DV_U, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_UU_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_UU, 0x0}, {LAO_DV_UU, 0x0}},
};
const ire_glyph_info_table_struct LAO_DV_MAI_KON_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_DV_MAI_KON, 0x0}, {LAO_DV_MAI_KON, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_S_LO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_S_LO, 0x0}, {LAO_S_LO, 0x0}},
};
const ire_glyph_info_table_struct LAO_S_NYO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_S_NYO, 0x0}, {LAO_S_NYO, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_IV_E_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_E, 0x0}, {LAO_IV_E, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_IV_EI_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_EI, 0x0}, {LAO_IV_EI, 0x0}},
};
const ire_glyph_info_table_struct LAO_IV_O_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_O, 0x0}, {LAO_IV_O, 0x0}},
};
const ire_glyph_info_table_struct LAO_IV_AY_Tbl[] = 
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_AY, 0x0}, {LAO_IV_AY, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_IV_AI_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_IV_AI, 0x0}, {LAO_IV_AI, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_M_KOLA_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_M_KOLA, 0x0}, {LAO_M_KOLA, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_TM_MAI_EK_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_TM_MAI_EK, 0x0}, {LAO_TM_MAI_EK, 0x0}},
};
const ire_glyph_info_table_struct LAO_TM_MAI_THO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_TM_MAI_THO, 0x0}, {LAO_TM_MAI_THO, 0x0}},
};
const ire_glyph_info_table_struct LAO_TM_MAI_TI_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_TM_MAI_TI, 0x0}, {LAO_TM_MAI_TI, 0x0}},
};
const ire_glyph_info_table_struct LAO_TM_MAI_CATAWA_Tbl[] = 
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_TM_MAI_CATAWA, 0x0}, {LAO_TM_MAI_CATAWA, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_S_CANCELLATION_MARK_Tbl[] = 
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_S_CANCELLATION_MARK, 0x0}, {LAO_S_CANCELLATION_MARK, 0x0}},
};
const ire_glyph_info_table_struct LAO_S_NIGGAHITA_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_S_NIGGAHITA, 0x0}, {LAO_S_NIGGAHITA, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_D_ZERO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_ZERO, 0x0}, {LAO_D_ZERO, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_ONE_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_ONE, 0x0}, {LAO_D_ONE, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_TWO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_TWO, 0x0}, {LAO_D_TWO, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_THREE_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_THREE, 0x0}, {LAO_D_THREE, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_FOUR_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_FOUR, 0x0}, {LAO_D_FOUR, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_FIVE_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_FIVE, 0x0}, {LAO_D_FIVE, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_SIX_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_SIX, 0x0}, {LAO_D_SIX, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_SEVEN_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_SEVEN, 0x0}, {LAO_D_SEVEN, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_EIGHT_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_EIGHT, 0x0}, {LAO_D_EIGHT, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_NINE_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_NINE, 0x0}, {LAO_D_NINE, 0x0}},
};
    
const ire_glyph_info_table_struct LAO_D_HONO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_HONO, 0x0}, {LAO_D_HONO, 0x0}},
};
const ire_glyph_info_table_struct LAO_D_HOMO_Tbl[] =
{
	{0, 1, 1, MMI_ALL_LANG, {LAO_D_HOMO, 0x0}, {LAO_D_HOMO, 0x0}},
};
    

const ire_main_glyph_table_struct LaoDvngTbl[] = 
{

    {LAO_C_KO_Tbl, sizeof(LAO_C_KO_Tbl) / sizeof(LAO_C_KO_Tbl[0]), 1},
    {LAO_C_KHO_SUNG_Tbl, sizeof(LAO_C_KHO_SUNG_Tbl) / sizeof(LAO_C_KHO_SUNG_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_C_KHO_TAM_Tbl, sizeof(LAO_C_KHO_TAM_Tbl) / sizeof(LAO_C_KHO_TAM_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    {LAO_C_NGO_Tbl, sizeof(LAO_C_NGO_Tbl) / sizeof(LAO_C_NGO_Tbl[0]), 1},
    {LAO_C_CO_Tbl, sizeof(LAO_C_CO_Tbl) / sizeof(LAO_C_CO_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_C_SO_TAM_Tbl, sizeof(LAO_C_SO_TAM_Tbl) / sizeof(LAO_C_SO_TAM_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    {LAO_C_NYO_Tbl, sizeof(LAO_C_NYO_Tbl) / sizeof(LAO_C_NYO_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    
    {NULL, 0, 0},
    {NULL, 0, 0},
    {NULL, 0, 0},
    {NULL, 0, 0},
    {LAO_C_DO_Tbl, sizeof(LAO_C_DO_Tbl) / sizeof(LAO_C_DO_Tbl[0]), 1},
    {LAO_C_TO_Tbl, sizeof(LAO_C_TO_Tbl) / sizeof(LAO_C_TO_Tbl[0]), 1},
    {LAO_C_THO_SUNG_Tbl, sizeof(LAO_C_THO_SUNG_Tbl) / sizeof(LAO_C_THO_SUNG_Tbl[0]), 1},
    {LAO_C_THO_TAM_Tbl, sizeof(LAO_C_THO_TAM_Tbl) / sizeof(LAO_C_THO_TAM_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_C_NO_Tbl, sizeof(LAO_C_NO_Tbl) / sizeof(LAO_C_NO_Tbl[0]), 1},
    {LAO_C_BO_Tbl, sizeof(LAO_C_BO_Tbl) / sizeof(LAO_C_BO_Tbl[0]), 1},
    {LAO_C_PO_Tbl, sizeof(LAO_C_PO_Tbl) / sizeof(LAO_C_PO_Tbl[0]), 1},
    {LAO_C_PHO_SUNG_Tbl, sizeof(LAO_C_PHO_SUNG_Tbl) / sizeof(LAO_C_PHO_SUNG_Tbl[0]), 1},
    {LAO_C_FO_TAM_Tbl, sizeof(LAO_C_FO_TAM_Tbl) / sizeof(LAO_C_FO_TAM_Tbl[0]), 1},
    {LAO_C_PHO_TAM_Tbl, sizeof(LAO_C_PHO_TAM_Tbl) / sizeof(LAO_C_PHO_TAM_Tbl[0]), 1},
    {LAO_C_FO_SUNG_Tbl, sizeof(LAO_C_FO_SUNG_Tbl) / sizeof(LAO_C_FO_SUNG_Tbl[0]), 1},
    
    {NULL, 0, 0},
    {LAO_C_MO_Tbl, sizeof(LAO_C_MO_Tbl) / sizeof(LAO_C_MO_Tbl[0]), 1},
    {LAO_C_YO_Tbl, sizeof(LAO_C_YO_Tbl) / sizeof(LAO_C_YO_Tbl[0]), 1},
    {LAO_C_LO_LING_Tbl, sizeof(LAO_C_LO_LING_Tbl) / sizeof(LAO_C_LO_LING_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_C_LO_LOOT_Tbl, sizeof(LAO_C_LO_LOOT_Tbl) / sizeof(LAO_C_LO_LOOT_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_C_WO_Tbl, sizeof(LAO_C_WO_Tbl) / sizeof(LAO_C_WO_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    {LAO_C_SO_SUNG_Tbl, sizeof(LAO_C_SO_SUNG_Tbl) / sizeof(LAO_C_SO_SUNG_Tbl[0]), 1},
    {LAO_C_HO_SUNG_Tbl, sizeof(LAO_C_HO_SUNG_Tbl) / sizeof(LAO_C_HO_SUNG_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_C_O_Tbl, sizeof(LAO_C_O_Tbl) / sizeof(LAO_C_O_Tbl[0]), 1},
    {LAO_C_HO_TAM_Tbl, sizeof(LAO_C_HO_TAM_Tbl) / sizeof(LAO_C_HO_TAM_Tbl[0]), 1},
    {LAO_S_ELLIPSIS_Tbl, sizeof(LAO_S_ELLIPSIS_Tbl) / sizeof(LAO_S_ELLIPSIS_Tbl[0]), 1},
    
    {LAO_IV_A_Tbl, sizeof(LAO_IV_A_Tbl) / sizeof(LAO_IV_A_Tbl[0]), 1},
    {LAO_DV_MAIKAN_Tbl, sizeof(LAO_DV_MAIKAN_Tbl) / sizeof(LAO_DV_MAIKAN_Tbl[0]), 1},
    {LAO_IV_AA_Tbl, sizeof(LAO_IV_AA_Tbl) / sizeof(LAO_IV_AA_Tbl[0]), 1},
    {LAO_IV_AM_Tbl, sizeof(LAO_IV_AM_Tbl) / sizeof(LAO_IV_AM_Tbl[0]), 1},
    {LAO_DV_I_Tbl, sizeof(LAO_DV_I_Tbl) / sizeof(LAO_DV_I_Tbl[0]), 1},
    {LAO_DV_II_Tbl, sizeof(LAO_DV_II_Tbl) / sizeof(LAO_DV_II_Tbl[0]), 1},
    {LAO_DV_Y_Tbl, sizeof(LAO_DV_Y_Tbl) / sizeof(LAO_DV_Y_Tbl[0]), 1},
    {LAO_DV_YY_Tbl, sizeof(LAO_DV_YY_Tbl) / sizeof(LAO_DV_YY_Tbl[0]), 1},
    {LAO_DV_U_Tbl, sizeof(LAO_DV_U_Tbl) / sizeof(LAO_DV_U_Tbl[0]), 1},
    {LAO_DV_UU_Tbl, sizeof(LAO_DV_UU_Tbl) / sizeof(LAO_DV_UU_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_DV_MAI_KON_Tbl, sizeof(LAO_DV_MAI_KON_Tbl) / sizeof(LAO_DV_MAI_KON_Tbl[0]), 1},
    {LAO_S_LO_Tbl, sizeof(LAO_S_LO_Tbl) / sizeof(LAO_S_LO_Tbl[0]), 1},
    {LAO_S_NYO_Tbl, sizeof(LAO_S_NYO_Tbl) / sizeof(LAO_S_NYO_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    
    {LAO_IV_E_Tbl, sizeof(LAO_IV_E_Tbl) / sizeof(LAO_IV_E_Tbl[0]), 1},
    {LAO_IV_EI_Tbl, sizeof(LAO_IV_EI_Tbl) / sizeof(LAO_IV_EI_Tbl[0]), 1},
    {LAO_IV_O_Tbl, sizeof(LAO_IV_O_Tbl) / sizeof(LAO_IV_O_Tbl[0]), 1},
    {LAO_IV_AY_Tbl, sizeof(LAO_IV_AY_Tbl) / sizeof(LAO_IV_AY_Tbl[0]), 1},
    {LAO_IV_AI_Tbl, sizeof(LAO_IV_AI_Tbl) / sizeof(LAO_IV_AI_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_M_KOLA_Tbl, sizeof(LAO_M_KOLA_Tbl) / sizeof(LAO_M_KOLA_Tbl[0]), 1},
    {NULL, 0, 0},
    {LAO_TM_MAI_EK_Tbl, sizeof(LAO_TM_MAI_EK_Tbl) / sizeof(LAO_TM_MAI_EK_Tbl[0]), 1},
    {LAO_TM_MAI_THO_Tbl, sizeof(LAO_TM_MAI_THO_Tbl) / sizeof(LAO_TM_MAI_THO_Tbl[0]), 1},
    {LAO_TM_MAI_TI_Tbl, sizeof(LAO_TM_MAI_TI_Tbl) / sizeof(LAO_TM_MAI_TI_Tbl[0]), 1},
    {LAO_TM_MAI_CATAWA_Tbl, sizeof(LAO_TM_MAI_CATAWA_Tbl) / sizeof(LAO_TM_MAI_CATAWA_Tbl[0]), 1},
    {LAO_S_CANCELLATION_MARK_Tbl, sizeof(LAO_S_CANCELLATION_MARK_Tbl) / sizeof(LAO_S_CANCELLATION_MARK_Tbl[0]), 1},
    {LAO_S_NIGGAHITA_Tbl, sizeof(LAO_S_NIGGAHITA_Tbl) / sizeof(LAO_S_NIGGAHITA_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    
    {LAO_D_ZERO_Tbl, sizeof(LAO_D_ZERO_Tbl) / sizeof(LAO_D_ZERO_Tbl[0]), 1},
    {LAO_D_ONE_Tbl, sizeof(LAO_D_ONE_Tbl) / sizeof(LAO_D_ONE_Tbl[0]), 1},
    {LAO_D_TWO_Tbl, sizeof(LAO_D_TWO_Tbl) / sizeof(LAO_D_TWO_Tbl[0]), 1},   
    {LAO_D_THREE_Tbl, sizeof(LAO_D_THREE_Tbl) / sizeof(LAO_D_THREE_Tbl[0]), 1},
    {LAO_D_FOUR_Tbl, sizeof(LAO_D_FOUR_Tbl) / sizeof(LAO_D_FOUR_Tbl[0]), 1},
    {LAO_D_FIVE_Tbl, sizeof(LAO_D_FIVE_Tbl) / sizeof(LAO_D_FIVE_Tbl[0]), 1},
    {LAO_D_SIX_Tbl, sizeof(LAO_D_SIX_Tbl) / sizeof(LAO_D_SIX_Tbl[0]), 1},
    {LAO_D_SEVEN_Tbl, sizeof(LAO_D_SEVEN_Tbl) / sizeof(LAO_D_SEVEN_Tbl[0]), 1},     
    {LAO_D_EIGHT_Tbl, sizeof(LAO_D_EIGHT_Tbl) / sizeof(LAO_D_EIGHT_Tbl[0]), 1},
    {LAO_D_NINE_Tbl, sizeof(LAO_D_NINE_Tbl) / sizeof(LAO_D_NINE_Tbl[0]), 1},
    {NULL, 0, 0},
    {NULL, 0, 0},
    {LAO_D_HONO_Tbl, sizeof(LAO_D_HONO_Tbl) / sizeof(LAO_D_HONO_Tbl[0]), 1},
    {LAO_D_HOMO_Tbl, sizeof(LAO_D_HOMO_Tbl) / sizeof(LAO_D_HOMO_Tbl[0]), 1},
};



#if defined(__MMI_MULTITAP_LAO__)

const UI_character_type default_lao_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_NYO, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},        /* key 8 */
    {LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after consonant */
const UI_character_type default_laomatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_LO, LAO_S_NYO, LAO_S_CANCELLATION_MARK, LAO_S_NIGGAHITA, LAO_TM_MAI_EK, LAO_TM_MAI_THO, LAO_TM_MAI_TI, LAO_TM_MAI_CATAWA, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_DV_MAIKAN, LAO_DV_I, LAO_DV_II,  LAO_DV_Y, LAO_DV_YY, LAO_DV_U, LAO_DV_UU, LAO_DV_MAI_KON, LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after consonant + vowel : (all tone marks/ all signs) */
const UI_character_type default_laomatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_LO, LAO_S_NYO, LAO_S_CANCELLATION_MARK, LAO_S_NIGGAHITA, LAO_TM_MAI_EK, LAO_TM_MAI_THO, LAO_TM_MAI_TI, LAO_TM_MAI_CATAWA, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};


/* after consonant + vowel : (all tone marks/ 3 signs) */
const UI_character_type default_laomatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_NYO, LAO_S_CANCELLATION_MARK, LAO_S_NIGGAHITA, LAO_TM_MAI_EK, LAO_TM_MAI_THO, LAO_TM_MAI_TI, LAO_TM_MAI_CATAWA, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after consonant + vowel : (all tone marks/ 1 signs) */
const UI_character_type default_laomatra3_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_NYO, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after consonant + tonemark : (vowles) */
const UI_character_type default_laomatra4_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_NYO, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_DV_MAIKAN, LAO_DV_I, LAO_DV_II,  LAO_DV_Y, LAO_DV_YY, LAO_DV_MAI_KON, LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after consonant + sing : (vowles) */
const UI_character_type default_laomatra5_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_NYO, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_DV_MAIKAN, LAO_DV_I, LAO_DV_II,  LAO_DV_Y, LAO_DV_YY, LAO_DV_U, LAO_DV_UU, LAO_DV_MAI_KON, LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* after consonant + sing : (vowles) */
const UI_character_type default_laomatra6_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', LAO_S_NYO, LAO_D_ZERO, '0', '\0'},  /* key 0 */
    {LAO_C_KO, LAO_C_KHO_SUNG, LAO_C_KHO_TAM, LAO_C_NGO, LAO_D_ONE, '1', '\0'},        /* key 1 */
    {LAO_C_CO, LAO_C_SO_TAM,  LAO_C_NYO, LAO_D_TWO, '2', '\0'},        /* key 2 */
    {LAO_C_DO, LAO_C_TO, LAO_C_THO_SUNG, LAO_C_THO_TAM, LAO_C_NO, LAO_D_THREE, '3', '\0'},  /* key 3 */
    {LAO_C_BO, LAO_C_PO, LAO_C_PHO_SUNG, LAO_C_FO_TAM, LAO_C_PHO_TAM, LAO_C_FO_SUNG, LAO_C_MO, LAO_D_FOUR, '4', '\0'},        /* key 4 */
    {LAO_C_YO, LAO_C_LO_LING, LAO_C_LO_LOOT, LAO_C_WO, LAO_D_FIVE, '5', '\0'},        /* key 5 */
    {LAO_C_SO_SUNG, LAO_C_HO_SUNG, LAO_C_O, LAO_C_HO_TAM, LAO_D_SIX, '6', '\0'},       /* key 6 */
    {LAO_D_HONO, LAO_D_HOMO, LAO_D_SEVEN, '7', '\0'}, /* key 7 */
    {LAO_IV_A, LAO_IV_AA, LAO_IV_AM, LAO_IV_E, LAO_IV_EI, LAO_IV_O, LAO_IV_AY, LAO_IV_AI, LAO_D_EIGHT, '8', '\0'},
    {LAO_DV_MAIKAN, LAO_DV_I, LAO_DV_II,  LAO_DV_Y, LAO_DV_YY, LAO_DV_MAI_KON, LAO_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif

#if defined(__MMI_MULTITAP_LAO__)

/*****************************************************************************
 * FUNCTION
 *  get_lao_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  i(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
/* MTI IRE OPTIMIZATION START */
UI_string_type get_lao_multitap_string(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;
    mmi_imc_message_struct imc_msg;
    UI_character_type string_buf[10] = {0}; /* /TODO: define an value for the string length */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* get previous character but skip highlight and multitap. */
    imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE;
    imc_msg.param_0 = 1;
    imc_msg.param_1 = (U32)string_buf;
	
    mmi_imc_send_message(&imc_msg);
	
    previous_char = string_buf[0];
    if (previous_char)
    {
        if ((previous_char >= LAO_C_KO && previous_char <= LAO_C_HO_TAM) || (previous_char >= LAO_D_HONO && previous_char <= LAO_D_HOMO))
        {
            return (UI_character_type*) default_laomatra_multitap_strings[index];
        }
        else
        {
			switch(previous_char)
			{
				case LAO_TM_MAI_EK:	
				case LAO_TM_MAI_THO:
				case LAO_TM_MAI_TI:
				case LAO_TM_MAI_CATAWA:
					return (UI_character_type*) default_laomatra4_multitap_strings[index];
				case LAO_S_LO:	
				//case LAO_S_NYO:
					return (UI_character_type*) default_laomatra5_multitap_strings[index];
				case LAO_S_CANCELLATION_MARK:
				case LAO_S_NIGGAHITA:
					return (UI_character_type*) default_laomatra6_multitap_strings[index];
				case LAO_DV_U:
				case LAO_DV_UU:
					return (UI_character_type*) default_laomatra1_multitap_strings[index];
				case LAO_DV_MAIKAN:
				case LAO_DV_I:
				case LAO_DV_II:
				case LAO_DV_Y:
				case LAO_DV_YY:
				case LAO_DV_MAI_KON:
					return (UI_character_type*) default_laomatra2_multitap_strings[index];
				case LAO_IV_A:
				case LAO_IV_AA:
				case LAO_IV_AM:
					return (UI_character_type*) default_laomatra3_multitap_strings[index];
				default:
						return (UI_character_type*) default_lao_multitap_strings[index];
			}
        }
    }
    else
    {
        return (UI_character_type*) default_lao_multitap_strings[index];
    }

}

/*****************************************************************************
 * FUNCTION
 *  get_bengali_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_lao_single_line_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
    if (previous_char)
    {
        if ((previous_char >= LAO_C_KO && previous_char <= LAO_C_HO_TAM) || (previous_char >= LAO_D_HONO && previous_char <= LAO_D_HOMO))
        {
            return ((UI_character_type*) default_laomatra_multitap_strings[i]);
        }
        else
        {
			switch(previous_char)
			{
				case LAO_TM_MAI_EK:	
				case LAO_TM_MAI_THO:
				case LAO_TM_MAI_TI:
				case LAO_TM_MAI_CATAWA:
					return (UI_character_type*) default_laomatra4_multitap_strings[i];
				case LAO_S_LO:	
				case LAO_S_NYO:
					return (UI_character_type*) default_laomatra5_multitap_strings[i];
				case LAO_S_CANCELLATION_MARK:
				case LAO_S_NIGGAHITA:
					return (UI_character_type*) default_laomatra6_multitap_strings[i];
				case LAO_DV_U:
				case LAO_DV_UU:
					return (UI_character_type*) default_laomatra1_multitap_strings[i];
				case LAO_DV_MAIKAN:
				case LAO_DV_I:
				case LAO_DV_II:
				case LAO_DV_Y:
				case LAO_DV_YY:
				case LAO_DV_MAI_KON:
					return (UI_character_type*) default_laomatra2_multitap_strings[i];
				case LAO_IV_A:
				case LAO_IV_AA:
				case LAO_IV_AM:
					return (UI_character_type*) default_laomatra3_multitap_strings[i];
				default:
					return (UI_character_type*) default_lao_multitap_strings[i];
			}
        }
    }
    else
    {
        return ((UI_character_type*) default_lao_multitap_strings[i]);
    }

}
#endif /* defined(__MMI_MULTITAP_LAO__) */ 

#else /* defined (__MMI_LANG_LAO__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_lao_warning_remove
 * DESCRIPTION
 *  for removing warnings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lao_warning_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy function */
}
#endif /* defined (__MMI_LANG_LAO__) */ 




