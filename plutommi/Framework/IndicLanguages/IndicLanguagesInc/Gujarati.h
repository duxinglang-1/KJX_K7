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
 *    Gujarati.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file of Gujarati font rule 
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
 
#ifndef MMI_GUJARATI_H
#define MMI_GUJARATI_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_GUJARATI__)

#define IRE_GUJARATI_LANG_START_RANGE        0xa80
#define IRE_GUJARATI_LANG_END_RANGE          0xaff
#define IRE_GUJARATI_PROPRIETRY_START_RANGE  0xa0ff
#define IRE_GUJARATI_PROPRIETRY_END_RANGE    0xa1ff

typedef enum
{
	  /* DEVANAGARI SIGNS */
		GUJARATI_DEVANAGARI_S_DANDA		= 0x0964,
		GUJARATI_DEVANAGARI_S_DDANDA		= 0x0965,
		
	/* VARIOUS SIGNS + INDEPENDENT VOWEL */

  GUJARATI_S_CHANDRA_BINDU = 0xa81,
  GUJARATI_S_BINDU = 0xa82,
  GUJARATI_S_VISARGA = 0xa83,
	GUJARATI_IV_A		     =	0xa85,
	GUJARATI_IV_AA		     =	0xa86,
	GUJARATI_IV_I		     =	0xa87,
	GUJARATI_IV_II		     =	0xa88,
	GUJARATI_IV_U		     =	0xa89,
	GUJARATI_IV_UU		     =	0xa8a,
	GUJARATI_IV_VR		     =	0xa8b,
	GUJARATI_IV_VL		     =	0xa8c,
	GUJARATI_IV_CE		     =	0xa8d,
	GUJARATI_IV_E		     =	0xa8f,
	GUJARATI_IV_AI		     =	0xa90,
	GUJARATI_IV_CO		     =	0xa91,
	GUJARATI_IV_O		     =	0xa93,
	GUJARATI_IV_AU		     =	0xa94,

	/*  CONSONANTS  */

	GUJARATI_C_KA		     =	0xa95,
	GUJARATI_C_KHA		     =	0xa96,
	GUJARATI_C_GA		     =	0xa97,
	GUJARATI_C_GHA		     =	0xa98,
	GUJARATI_C_NGA		     =	0xa99,
	GUJARATI_C_CA		     =	0xa9a,
	GUJARATI_C_CHA		     =	0xa9b,
	GUJARATI_C_JA		     =	0xa9c,
	GUJARATI_C_JHA		     =	0xa9d,
	GUJARATI_C_NYA		     =	0xa9e,
	GUJARATI_C_TTA		     =	0xa9f,
	GUJARATI_C_TTHA		     =	0xaa0,
	GUJARATI_C_DDA		     =	0xaa1,
	GUJARATI_C_DDHA		     =	0xaa2,
	GUJARATI_C_NNA		     =	0xaa3,
	GUJARATI_C_TA		     =	0xaa4,
	GUJARATI_C_THA		     =	0xaa5,
	GUJARATI_C_DA		     =	0xaa6,
	GUJARATI_C_DHA		     =	0xaa7,
	GUJARATI_C_NA		     =	0xaa8,
	GUJARATI_C_PA		     =	0xaaa,
	GUJARATI_C_PHA		     =	0xaab,
	GUJARATI_C_BA		     =	0xaac,
	GUJARATI_C_BHA		     =	0xaad,
	GUJARATI_C_MA		     =	0xaae,
	GUJARATI_C_YA		     =	0xaaf,
	GUJARATI_C_RA		     =	0xab0,
	GUJARATI_C_LA		     =	0xab2,
	GUJARATI_C_LLA		     =	0xab3,
	GUJARATI_C_VA		     =	0xab5,
	GUJARATI_C_SHA		     =	0xab6,
	GUJARATI_C_SSA		     =	0xab7,
	GUJARATI_C_SA		     =	0xab8,
	GUJARATI_C_HA		     =	0xab9,

	GUJARATI_S_NUKTA		     =	0xabc,
	GUJARATI_S_AVAGRAHA		     =	0xabd,

	/*  DEPENDENT VOWELS  */

	GUJARATI_DV_AA		     =	0xabe,
	GUJARATI_DV_I		     =	0xabf,
	GUJARATI_DV_II		     =	0xac0,
	GUJARATI_DV_U		     =	0xac1,
	GUJARATI_DV_UU		     =	0xac2,
	GUJARATI_DV_VR		     =	0xac3,
	GUJARATI_DV_VRR		     =	0xac4,
	GUJARATI_DV_CE		     =	0xac5,
	GUJARATI_DV_E		     =	0xac7,
	GUJARATI_DV_AI		     =	0xac8,
	GUJARATI_DV_CO		     =	0xac9,
	GUJARATI_DV_O		     =	0xacb,
	GUJARATI_DV_AU		     =	0xacc,
	GUJARATI_S_HALANT		     =	0xacd,
	GUJARATI_S_OM		     =	0xad0,
	GUJARATI_IV_VRR		     =	0xae0,
	GUJARATI_IV_VLL		     =	0xae1,
	GUJARATI_S_VL		     =	0xae2,
	GUJARATI_S_VLL		     =	0xae3,
	GUJARATI_DEVANAGARI_D		     =	0xae4,
	GUJARATI_DEVANAGARI_DD		     =	0xae5,

	/*  DIGITS  */

	GUJARATI_D_ZERO		     =	0xae6,
	GUJARATI_D_ONE		     =	0xae7,
	GUJARATI_D_TWO		     =	0xae8,
	GUJARATI_D_THREE		     =	0xae9,
	GUJARATI_D_FOUR		     =	0xaea,
	GUJARATI_D_FIVE		     =	0xaeb,
	GUJARATI_D_SIX		     =	0xaec,
	GUJARATI_D_SEVEN		     =	0xaed,
	GUJARATI_D_EIGHT		     =	0xaee,
	GUJARATI_D_NINE		     =	0xaef,
	GUJARATI_D_CS		     =	0xaf1

}gujarati_characters_enum;


typedef enum
{
    /* various half forms,ligature etc */
    
    GUJARATI_H_KA = 0xA100,
    GUJARATI_H_KHA = 0xA101,
    GUJARATI_H_GA = 0xA102,
    GUJARATI_H_GHA = 0xA103,
    GUJARATI_H_CA = 0xA104,
    GUJARATI_H_JA = 0xA105,
    GUJARATI_H_JHA = 0xA106,
    GUJARATI_H_NYA = 0xA107,
    GUJARATI_H_NNA = 0xA108,
    GUJARATI_H_TA = 0xA109,
    GUJARATI_H_THA = 0xA10A,
    GUJARATI_H_DHA = 0xA10B,
    GUJARATI_H_NA = 0xA10C,
    GUJARATI_H_PA = 0xA10D,
    GUJARATI_H_BA = 0xA10E,
    GUJARATI_H_BHA = 0xA10F,
    GUJARATI_H_MA = 0xA110,
    GUJARATI_H_YA = 0xA111,
    GUJARATI_H_LA = 0xA112,
    GUJARATI_H_LLA = 0xA113,
    GUJARATI_H_VA = 0xA114,
    GUJARATI_H_SHA = 0xA115,
    GUJARATI_H_SSA = 0xA116,
    GUJARATI_H_SA = 0xA117,
    GUJARATI_H_HA = 0xA118,
    GUJARATI_H_PHA = 0xA119,
    
    GUJARATI_L_KKA = 0xA11B,
    GUJARATI_L_SSATTA = 0xA11C,
    GUJARATI_L_SSATTHA = 0xA11D,
    GUJARATI_L_YA = 0xA11E,
    
    GUJARATI_L_KSHA = 0xA121,
    GUJARATI_L_JNYA = 0xA122,
    GUJARATI_L_TTTA = 0xA123,
    GUJARATI_L_TRA = 0xA124,

    GUJARATI_L_TTTTA = 0xA125,
    GUJARATI_L_THTHA = 0xA126,
    GUJARATI_L_TTTHA = 0xA127,
    GUJARATI_C_DADDA = 0xA128,
    GUJARATI_L_DHADHA = 0xA129,
    
    GUJARATI_C_DADA = 0xA12A,
    GUJARATI_L_DADHA = 0xA12B,
    GUJARATI_L_DAMA = 0xA12C,
    GUJARATI_L_DVA = 0xA12D,
    GUJARATI_L_DDYA = 0xA12E,
    GUJARATI_L_DRA = 0xA12F,
    GUJARATI_L_NNA = 0xA130,
    GUJARATI_LH_KSHA = 0xA131,
    GUJARATI_LH_JNYA = 0xA132,
    GUJARATI_LH_TTTA = 0xA133,
    GUJARATI_LH_TRA = 0xA134,
    GUJARATI_L_SHRA = 0xA135,
    GUJARATI_LH_SHRA = 0xA136,
    GUJARATI_LH_NNA= 0xA137,  
    GUJARATI_C_DADDHA = 0xA138,   
    GUJARATI_L_HAVR = 0xA13C,   
    GUJARATI_L_HNA = 0xA13D,  
    GUJARATI_L_HMMA = 0xA13E,
    GUJARATI_L_HYA = 0xA13F,
    GUJARATI_LL_SHRA = 0xA140, 
    
    GUJARATI_L_KRA = 0xA141,
    GUJARATI_L_JRA = 0xA144,
    GUJARATI_L_JHARA = 0xA145,
    GUJARATI_C_NNARA = 0xA146,

    GUJARATI_L_PHARA = 0xA14B,
    GUJARATI_L_SHRA1 = 0xA14D,
    GUJARATI_L_SRA = 0xA14F,
    GUJARATI_L_HRA = 0xA150,
    GUJARATI_L_JAAA = 0xA151,
    GUJARATI_L_JAII = 0xA152,
    GUJARATI_L_RU = 0xA153,
    GUJARATI_L_RUU = 0xA154,
    GUJARATI_L_JAAU = 0xA155,
    GUJARATI_L_JAO = 0xA156,
            
    GUJARATI_L_SUPR2 = 0xA161,
    GUJARATI_L_SUPRB2 = 0xA162,
    GUJARATI_L_NCAND = 0xA163,
    GUJARATI_L_NBINDU = 0xA164,
    GUJARATI_L_AAR = 0xA165,
    GUJARATI_L_AARB = 0xA166,
    GUJARATI_S_CHANDRA_BINDU1 = 0xA167,
    GUJARATI_L_VR = 0xA168,
    GUJARATI_L_VRR = 0xA169,
    GUJARATI_L_HALANT1 = 0xA16A,
    GUJARATI_L_SUBRA1 = 0xA16B,
    GUJARATI_L_SPR = 0xA16C,
    GUJARATI_L_SPRB = 0xA16D,
    GUJARATI_S_BINDU1 = 0xA16E,
    GUJARATI_S_BINDU2 = 0xA16F,
    GUJARATI_L_E = 0xA170,
    GUJARATI_L_CE = 0xA171,   
    GUJARATI_L_AI = 0xA172,
    GUJARATI_L_U = 0xA173,    
    GUJARATI_L_UU = 0xA174,
    GUJARATI_S_NUKTA1 = 0xA175,    
    GUJARATI_S_CHANDRA_BINDU2 = 0xA176,
    GUJARATI_S_NUKTA2 = 0xA177,
    GUJARATI_L_SPR1 = 0xA178,
    GUJARATI_L_SPRB1 = 0xA179,
    GUJARATI_L_SUBRA2 = 0xA17A,
    GUJARATI_L_PB_DV_U = 0xA17B,
    GUJARATI_L_PB_DV_UU = 0xA17C,
    GUJARATI_L_PB_DV_VR = 0xA17D,
    GUJARATI_L_PB_DV_VRR = 0xA17E,
    GUJARATI_L_PB_HALANT = 0xA17F,
    GUJARATI_L_PB_CBINDU = 0xA180,
    GUJARATI_L_TTHA_YA = 0xA181,
    /* END OF ENUM */
    GUJARATI_L_DUMMY_END
} gujarati_ligatures_enum;


#if defined (__MMI_MULTITAP_GUJARATI__)

#if defined(__MMI_ZI_GUJARATI__)
extern const UI_character_type default_gujarati_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra2_multitap_strings[MAX_MULTITAPS][32];
#else /* defined (__MMI_ZI_GUJARATI__) */
extern const UI_character_type default_gujarati_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra2_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_gujaratimatra3_multitap_strings[MAX_MULTITAPS][32];
#endif /* defined (__MMI_ZI_GUJARATI__) */ 


extern UI_string_type get_gujarati_multitap_string(S32 i);
extern UI_string_type get_gujarati_single_line_multitap_string(S32 i);
extern UI_character_type *get_gujarati_multitap_string_for_vk(S32 i);
#endif /* defined (__MMI_MULTITAP_GUJARATI__)  */

//UI_character_type pre_previous_char; /* to store previous character[chandrabindu not allowed after consonant+super-ra] */ 
#endif /* defined (__MMI_LANG_GUJARATI__) */ 
#endif /* MMI_GUJARATI_H */ 

