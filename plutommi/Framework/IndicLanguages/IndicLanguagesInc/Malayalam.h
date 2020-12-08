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
 *   Malayalam.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file of Malayalam Language 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_MALAYALAM_H
#define MMI_MALAYALAM_H

#include "MMI_features.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_MALAYALAM__)

#define IRE_MALAYALAM_LANG_START_RANGE        0x0D01
#define IRE_MALAYALAM_LANG_END_RANGE          0x0D7F
#define IRE_MALAYALAM_PROPRIETRY_START_RANGE  0xA1FF
#define IRE_MALAYALAM_PROPRIETRY_END_RANGE    0xA236

typedef enum
{
	/* MALAYALAM SIGNS */
    MALAYALAM_DEVANAGARI_S_DANDA = 0x0964,
    MALAYALAM_DEVANAGARI_S_DOUBLE_DANDA = 0x0965,
	
	/* VARIOUS SIGNS */
	MALAYALAM_S_ANUSVARA	     =	0x0D02,
	MALAYALAM_S_VISARGA		     =	0x0D03,
	
	/* INDEPENDENT VOWEL */
	MALAYALAM_IV_A		         =	0x0D05,
	MALAYALAM_IV_AA		         =	0x0D06,
	MALAYALAM_IV_I		         =	0x0D07,
	MALAYALAM_IV_II		         =	0x0D08,
	MALAYALAM_IV_U		         =	0x0D09,
	MALAYALAM_IV_UU		         =	0x0D0A,
	MALAYALAM_IV_VR		         =	0x0D0B,
	MALAYALAM_IV_VL		         =	0x0D0C,
	MALAYALAM_IV_E		         =	0x0D0E,
	MALAYALAM_IV_EE		         =	0x0D0F,
	MALAYALAM_IV_AI		         =	0x0D10,
	MALAYALAM_IV_O		         =	0x0D12,
	MALAYALAM_IV_OO		         =	0x0D13,
	MALAYALAM_IV_AU		         =	0x0D14,
	
	/* CONSONANTS */
	MALAYALAM_C_KA		         =	0x0D15,
	MALAYALAM_C_KHA		         =	0x0D16,
	MALAYALAM_C_GA		         =	0x0D17,
	MALAYALAM_C_GHA		         =	0x0D18,
	MALAYALAM_C_NGA		         =	0x0D19,
	MALAYALAM_C_CA		         =	0x0D1A,
	MALAYALAM_C_CHA		         =	0x0D1B,
	MALAYALAM_C_JA		         =	0x0D1C,
	MALAYALAM_C_JHA		         =	0x0D1D,
	MALAYALAM_C_NYA		         =	0x0D1E,
	MALAYALAM_C_TTA		         =	0x0D1F,
	MALAYALAM_C_TTHA		     =	0x0D20,
	MALAYALAM_C_DDA		         =	0x0D21,
	MALAYALAM_C_DDHA		     =	0x0D22,
	MALAYALAM_C_NNA		         =	0x0D23,
	MALAYALAM_C_TA		         =	0x0D24,
	MALAYALAM_C_THA		         =	0x0D25,
	MALAYALAM_C_DA		         =	0x0D26,
	MALAYALAM_C_DHA		         =	0x0D27,
	MALAYALAM_C_NA		         =	0x0D28,
	MALAYALAM_C_PA		         =	0x0D2A,
	MALAYALAM_C_PHA		         =	0x0D2B,
	MALAYALAM_C_BA		         =	0x0D2C,
	MALAYALAM_C_BHA		         =	0x0D2D,
	MALAYALAM_C_MA		         =	0x0D2E,
	MALAYALAM_C_YA		         =	0x0D2F,
	MALAYALAM_C_RA		         =	0x0D30,
	MALAYALAM_C_RRA		         =	0x0D31,
	MALAYALAM_C_LA		         =	0x0D32,
	MALAYALAM_C_LLA		         =	0x0D33,
	MALAYALAM_C_LLLA		     =	0x0D34,
	MALAYALAM_C_VA		         =	0x0D35,
	MALAYALAM_C_SHA		         =	0x0D36,
	MALAYALAM_C_SSA		         =	0x0D37,
	MALAYALAM_C_SA		         =	0x0D38,
	MALAYALAM_C_HA		         =	0x0D39,
	
	/* VARIOUS SIGNS */ 
	MALAYALAM_S_AVAGRAHA         =	0x0D3D,
	
	/* DEPENDENT VOWELS */
	MALAYALAM_DV_AA		         =	0x0D3E,
	MALAYALAM_DV_I		         =	0x0D3F,
	MALAYALAM_DV_II		         =	0x0D40,
	MALAYALAM_DV_U		         =	0x0D41,
	MALAYALAM_DV_UU		         =	0x0D42,
	MALAYALAM_DV_VR		         =	0x0D43,
	MALAYALAM_DV_VRR	         =	0x0D44,
	MALAYALAM_DV_E		         =	0x0D46,
	MALAYALAM_DV_EE		         =	0x0D47,
	MALAYALAM_DV_AI		         =	0x0D48,
	MALAYALAM_DV_O		         =	0x0D4A,
	MALAYALAM_DV_OO		         =	0x0D4B,
	MALAYALAM_DV_AU		         =	0x0D4C,
	
	/* VARIOUS SIGNS */ 
	MALAYALAM_S_HALANT		     =	0x0D4D,
	MALAYALAM_S_AU_LENGTH_MARK	 =	0x0D57,
	
	/* INDEPENDENT VOWELS */
	MALAYALAM_IV_VRR		     =	0x0D60,
	MALAYALAM_IV_VLL		     =	0x0D61,
	
	/* DEPENDENT VOWELS */
	MALAYALAM_DV_VL			     =	0x0D62,
	MALAYALAM_DV_VLL		     =	0x0D63,

	/* MALAYALAM SIGNS */
    MALAYALAM_S_DANDA 			 = 0x0D64,
    MALAYALAM_S_DOUBLE_DANDA 	 = 0x0D65,

	/*  DIGITS  */
	MALAYALAM_D_ZERO		     =	0x0D66,
	MALAYALAM_D_ONE		         =	0x0D67,
	MALAYALAM_D_TWO		         =	0x0D68,
	MALAYALAM_D_THREE		     =	0x0D69,
	MALAYALAM_D_FOUR		     =	0x0D6A,
	MALAYALAM_D_FIVE		     =	0x0D6B,
	MALAYALAM_D_SIX		         =	0x0D6C,
	MALAYALAM_D_SEVEN		     =	0x0D6D,
	MALAYALAM_D_EIGHT		     =	0x0D6E,
	MALAYALAM_D_NINE		     =	0x0D6F,
	MALAYALAM_D_TEN			     =	0x0D70,
	MALAYALAM_D_HUNDERED	     =	0x0D71,
	MALAYALAM_D_THOUSAND	     =	0x0D72,
	
	/* FRACTION */
	MALAYALAM_F_QUARTER		     =	0x0D73,
	MALAYALAM_F_HALF		     =	0x0D74,
	MALAYALAM_F_THREE_QUARTER    =	0x0D75,
	
	/* DATE MARK */
	MALAYALAM_S_DATE_MARK		 =  0x0D79,
	
	/* CHILLU LETTERS */
	MALAYALAM_C_CHILLU_NN		 =  0x0D7A,
	MALAYALAM_C_CHILLU_N		 =  0x0D7B,
	MALAYALAM_C_CHILLU_RR		 =  0x0D7C,
	MALAYALAM_C_CHILLU_L		 =  0x0D7D,
	MALAYALAM_C_CHILLU_LL		 =  0x0D7E,
	MALAYALAM_C_CHILLU_K		 =  0x0D7F,
	
	/* END OF ENUM */
	MALAYALAM_DUMMY_END
}malayalam_characters_enum;

typedef enum
{
    MALAYALAM_L_YAKAR            =  0xA200,
    MALAYALAM_L_RAKAR            =  0xA201,
    MALAYALAM_L_LAKAR            =  0xA202,
    MALAYALAM_L_VAKAR            =  0xA203,
    MALAYALAM_L_V_VA             =  0xA204,
    MALAYALAM_L_G_GA             =  0xA205,
    MALAYALAM_L_DD_DDA           =  0xA206,
    MALAYALAM_L_NN_NNA           =  0xA207,
    MALAYALAM_L_P_PA             =  0xA208,
    MALAYALAM_L_SH_SHA           =  0xA209,
    MALAYALAM_L_S_SA             =  0xA20A,
    MALAYALAM_L_RR_RRA           =  0xA20B,
    MALAYALAM_L_S_RR_RRA         =  0xA20C,
    MALAYALAM_L_TT_TTA           =  0xA20D,
    MALAYALAM_L_D_DA             =  0xA20E,
    MALAYALAM_L_T_TA             =  0xA20F,
    MALAYALAM_L_M_MA             =  0xA210,
    MALAYALAM_L_LL_LLA           =  0xA211,
    MALAYALAM_L_J_JA             =  0xA212,
    MALAYALAM_L_NY_NYA           =  0xA213,
    MALAYALAM_L_N_NA             =  0xA214,
    MALAYALAM_L_K_KA             =  0xA215,
    MALAYALAM_L_NG_NGA           =  0xA216,
    MALAYALAM_L_B_BA             =  0xA217,
    MALAYALAM_L_C_CA             =  0xA218,
    MALAYALAM_L_Y_YA             =  0xA219,
    MALAYALAM_L_L_LA             =  0xA21A,
    MALAYALAM_L_C_CHA            =  0xA21B,
    MALAYALAM_L_K_TA             =  0xA21C,
    MALAYALAM_L_G_MA             =  0xA21D,
    MALAYALAM_L_H_MA             =  0xA21E,
    MALAYALAM_L_H_NA             =  0xA21F,
    MALAYALAM_L_N_MA             =  0xA220,
    MALAYALAM_L_NN_MA            =  0xA221,
    MALAYALAM_L_NN_TTA           =  0xA222,
    MALAYALAM_L_J_NYA            =  0xA223,
    MALAYALAM_L_NY_CA            =  0xA224,
    MALAYALAM_L_N_DHA            =  0xA225,
    MALAYALAM_L_N_DA             =  0xA226,
    MALAYALAM_L_T_THA            =  0xA227,
    MALAYALAM_L_S_THA            =  0xA228,
    MALAYALAM_L_K_SSA            =  0xA229,
    MALAYALAM_L_G_NA             =  0xA22A,
    MALAYALAM_L_NG_KA            =  0xA22B,
    MALAYALAM_L_T_MA             =  0xA22C,
    MALAYALAM_L_T_BHA            =  0xA22D,
    MALAYALAM_L_T_SA             =  0xA22E,
    MALAYALAM_L_D_DHA            =  0xA22F,
    MALAYALAM_L_N_TA             =  0xA230,
    MALAYALAM_L_N_THA            =  0xA231,
    MALAYALAM_L_M_PA             =  0xA232,
    MALAYALAM_L_B_DA             =  0xA233,
    MALAYALAM_L_B_DHA            =  0xA234,
    MALAYALAM_L_SH_CA            =  0xA235,
    MALAYALAM_L_SS_TTA           =  0xA236,
    
    /* END OF ENUM */
    MALAYALAM_L_DUMMY_END
}malayalam_ligatures_enum;

#if defined (__MMI_MULTITAP_MALAYALAM__) 

extern const UI_character_type default_malayalam_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_malayalammatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_malayalammatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_malayalammatra2_multitap_strings[MAX_MULTITAPS][32];

extern UI_string_type get_malayalam_multitap_string(S32 index);
extern UI_string_type get_malayalam_single_line_multitap_string(S32);
extern UI_character_type *get_malayalam_multitap_string_for_vk(S32 i);
#endif /* defined (__MMI_MULTITAP_MALAYALAM__) */
#endif /* defined (__MMI_LANG_MALAYALAM__) */ 
#endif /* MMI_MALAYALAM_H */ 

