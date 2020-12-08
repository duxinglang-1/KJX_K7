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
 *    Oriya.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file of oriya font rule 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef MMI_ORIYA_H
#define MMI_ORIYA_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"

#if defined (__MMI_LANG_ORIYA__)

#define IRE_ORIYA_LANG_START_RANGE        0x0B00
#define IRE_ORIYA_LANG_END_RANGE       0x0B71

#define IRE_ORIYA_PROPRIETRY_START_RANGE  0xA2ff
#define IRE_ORIYA_PROPRIETRY_END_RANGE    0xA3FF

typedef enum
{   
	/* ORIYA SIGNS */
    ORIYA_DEVANAGARI_S_DANDA = 0x0964,
    ORIYA_DEVANAGARI_S_DOUBLE_DANDA = 0x0965,
	
	/* VARIOUS SIGNS + INDEPENDENT VOWEL */
    ORIYA_S_CHANDRA_BINDU = 0x0B01,
    ORIYA_S_ANUSVARA = 0x0B02,
    ORIYA_S_VISARGA = 0x0B03,

    ORIYA_IV_A = 0x0B05,
    ORIYA_IV_AA = 0x0B06,
    ORIYA_IV_I = 0x0B07,
    ORIYA_IV_II = 0x0B08,
    ORIYA_IV_U = 0x0B09,
    ORIYA_IV_UU = 0x0B0A,
    ORIYA_IV_R = 0x0B0B,
    ORIYA_IV_L = 0x0B0C,
    ORIYA_IV_E = 0x0B0F,
    ORIYA_IV_AI = 0x0B10,
    ORIYA_IV_O = 0x0B13,
    ORIYA_IV_AU = 0x0B14,

    /* CONSONANTS */
    ORIYA_C_KA = 0x0B15,
    ORIYA_C_KHA = 0x0B16,
    ORIYA_C_GA = 0x0B17,
    ORIYA_C_GHA = 0x0B18,
    ORIYA_C_NGA = 0x0B19,
    ORIYA_C_CHA = 0x0B1A,
    ORIYA_C_CHHA = 0x0B1B,
    ORIYA_C_JA = 0x0B1C,
    ORIYA_C_JHA = 0x0B1D,
    ORIYA_C_NYA = 0x0B1E,
    ORIYA_C_TTA = 0x0B1F,
    ORIYA_C_TTHA = 0x0B20,
    ORIYA_C_DDA = 0x0B21,
    ORIYA_C_DDHA = 0x0B22,
    ORIYA_C_NNA = 0x0B23,
    ORIYA_C_TA = 0x0B24,
    ORIYA_C_THA = 0x0B25,
    ORIYA_C_DA = 0x0B26,
    ORIYA_C_DHA = 0x0B27,
    ORIYA_C_NA = 0x0B28,

    ORIYA_C_PA = 0x0B2A,
    ORIYA_C_PHA = 0x0B2B,
    ORIYA_C_BA = 0x0B2C,
    ORIYA_C_BHA = 0x0B2D,
    ORIYA_C_MA = 0x0B2E,
    ORIYA_C_YA = 0x0B2F,
    ORIYA_C_RA = 0x0B30,

    ORIYA_C_LA = 0x0B32,
    ORIYA_C_LLA = 0x0B33,

    ORIYA_C_VA = 0x0B35,
    ORIYA_C_SHA = 0x0B36,
    ORIYA_C_SSA = 0x0B37,
    ORIYA_C_SA = 0x0B38,
    ORIYA_C_HA = 0x0B39,

    /* SIGNS */
    ORIYA_S_NUKTA = 0x0B3C,
    ORIYA_NS_AVAGRAHA = 0x0B3D,

    /* DEPENDENT VOWELS */
    ORIYA_DV_AA = 0x0B3E,
    ORIYA_DV_I = 0x0B3F,
    ORIYA_DV_II = 0x0B40,
    ORIYA_DV_U = 0x0B41,
    ORIYA_DV_UU = 0x0B42,
    ORIYA_DV_R = 0x0B43,
    ORIYA_DV_RR = 0x0B44,

    ORIYA_DV_E = 0x0B47,
    ORIYA_DV_AI = 0x0B48,

		ORIYA_SAN_AU = 0x0B4A, /* extra: to handle 0x0B4C becouse its pre,above and post base dependent vowle*/
    ORIYA_DV_O = 0x0B4B,
    ORIYA_DV_AU = 0x0B4C,

    /* SIGNS */
    ORIYA_S_HALANT = 0x0B4D,

    ORIYA_S_AI = 0x0B56,
    ORIYA_S_AU = 0x0B57,

    /* ADDITIONAL CONSONANT */
    ORIYA_AC_RRA = 0x0B5C,
    ORIYA_AC_RHA = 0x0B5D,
    ORIYA_AC_YYA = 0x0B5F,

    /* GENERIC ADDITIONS */
    ORIYA_NG_RR = 0x0B60,
    ORIYA_NG_LL = 0x0B61,
    ORIYA_NG_L = 0x0B62,
    ORIYA_NG_VLL = 0x0B63,
    ORIYA_NG_D = 0x0B64,
    ORIYA_NG_DD = 0x0B65,

    /* DIGITS */
    ORIYA_D_ZERO = 0x0B66,
    ORIYA_D_ONE = 0x0B67,
    ORIYA_D_TWO = 0x0B68,
    ORIYA_D_THREE = 0x0B69,
    ORIYA_D_FOUR = 0x0B6A,
    ORIYA_D_FIVE = 0x0B6B,
    ORIYA_D_SIX = 0x0B6C,
    ORIYA_D_SEVEN = 0x0B6D,
    ORIYA_D_EIGHT = 0x0B6E,
    ORIYA_D_NINE = 0x0B6F,
    /* ORIYA SPECIFIC ADDITOIN */
    ORIYA_S_ISSHAR = 0x0B70,
    ORIYA_S_WA = 0x0B71
} ORIYA_characters_enum;

typedef enum
{
    /* various half forms,ligature etc */
    ORIYA_H_KAKA = 0xA300,
    ORIYA_H_LLAKA = 0xA301,
    ORIYA_H_LAKA = 0xA302,
    ORIYA_H_SSAKA = 0xA303,
    ORIYA_H_SAKA = 0xA304,
    ORIYA_H_JAJA = 0xA305,
    ORIYA_H_KANA = 0xA306,
    ORIYA_H_GANA = 0xA307,
    ORIYA_H_GHANA = 0xA308,
    ORIYA_H_TANA = 0xA309,
    ORIYA_H_DHANA = 0xA30A,
    ORIYA_H_NANA = 0xA30B,
    ORIYA_H_GADHANA = 0xA30C,
    ORIYA_H_NNANA = 0xA30D,
    ORIYA_H_SANA = 0xA30E,
    ORIYA_H_HANA = 0xA30F,
    ORIYA_H_KALLA = 0xA310,
    ORIYA_H_GALLA = 0xA311,
    ORIYA_H_GADHALLA = 0xA312,
    ORIYA_H_MALLA = 0xA313,
    ORIYA_H_NNALLA = 0xA314,
    ORIYA_H_KALA = 0xA315,
    ORIYA_H_GALA = 0xA316,
    ORIYA_H_GADHALA = 0xA317,
    ORIYA_H_PHALA = 0xA318,
    ORIYA_H_BALA = 0xA319,
    ORIYA_H_SALA = 0xA31A,
    ORIYA_H_HALA = 0xA31B,
    ORIYA_H_MABA = 0xA31C,
    ORIYA_H_KAWA = 0xA31D,
    ORIYA_H_GAWA = 0xA31E,
    ORIYA_H_JAWA = 0xA31F,
    ORIYA_H_CHAWA = 0xA320,
    ORIYA_H_TTAWA = 0xA321,
    ORIYA_H_DDAWA = 0xA322,
    ORIYA_H_NNAWA = 0xA323,
    ORIYA_H_TAWA = 0xA324,
    ORIYA_H_THAWA = 0xA325,
    ORIYA_H_DAWA = 0xA326,
    ORIYA_H_DHAWA = 0xA327,
    ORIYA_H_NAWA = 0xA328,
    ORIYA_H_LAWA = 0xA329,
    ORIYA_H_SHAWA = 0xA32A,
    ORIYA_H_SAWA = 0xA32B,
    ORIYA_H_HAWA = 0xA32C,
    ORIYA_H_TAKA = 0xA32D,
    ORIYA_H_TAPA = 0xA32E,
    ORIYA_H_TAPHA = 0xA32F,
    ORIYA_H_TAMA = 0xA330,
    ORIYA_H_TASA = 0xA331,
    ORIYA_H_NNADDHA = 0xA332,
    ORIYA_H_NATHA = 0xA333,
    ORIYA_H_SATHA = 0xA334,
    ORIYA_H_SHACHHA = 0xA335,   
    ORIYA_H_MABHA = 0xA336,   
    ORIYA_H_KAMA = 0xA337,  
    ORIYA_H_KASSAMA = 0xA338,
    /* ORIYA_H_TAMA = 0xA339, */
    ORIYA_H_GAMA = 0xA33A,
    ORIYA_H_KATA = 0xA33B,
    ORIYA_H_NATA = 0xA33C,
    ORIYA_H_PATA = 0xA33D,
    ORIYA_H_SATA = 0xA33E,
    ORIYA_H_NNADDA = 0xA33F,
    ORIYA_S_KAYYA = 0xA340,
    ORIYA_S_KASSAYYA = 0xA341,
    ORIYA_S_KHAYYA = 0xA342,
    ORIYA_S_GAYYA = 0xA343,
    ORIYA_S_NATARA = 0xA344,
    ORIYA_S_SATARA = 0xA345,
    ORIYA_S_NNANNA = 0xA346,
    ORIYA_S_SSANNA = 0xA347,
    ORIYA_S_SATAU = 0xA348,
    ORIYA_S_NATAU = 0xA349,
    ORIYA_L_NGAKA = 0xA34A,
    ORIYA_L_NGAKHA = 0xA34B,
    ORIYA_L_NGAGA = 0xA34C,
    ORIYA_L_NGAGHA = 0xA34D,
    ORIYA_L_NYACHA = 0xA34E,
    ORIYA_L_NYACHHA = 0xA34F,
    ORIYA_L_NYAJA = 0xA350,
    ORIYA_L_NYAJHA = 0xA351,
    ORIYA_L_JANYA = 0xA352,
    ORIYA_L_CHACHA = 0xA353,
    ORIYA_L_TTATTA = 0xA354,
    ORIYA_L_DADA = 0xA355,   
    ORIYA_L_DADHA = 0xA356,
    ORIYA_L_BADA = 0xA357,    
    ORIYA_L_BABA = 0xA358,
    ORIYA_L_DABHA = 0xA359,    
    ORIYA_L_TATA = 0xA35A,
    ORIYA_L_NADA = 0xA35B,
    ORIYA_L_NADHA = 0xA35C,
    ORIYA_L_KASSA = 0xA35D,
    ORIYA_L_MAPA = 0xA35E,
    ORIYA_L_MAPHA = 0xA35F,
    ORIYA_D_SAKHA = 0xA360,
    ORIYA_D_NGAKASSA = 0xA361,
    ORIYA_D_DDAGA = 0xA362,
    ORIYA_D_DAGA = 0xA363,
    ORIYA_D_LAGA = 0xA364,
    ORIYA_D_DAGHA = 0xA365,
    ORIYA_D_SHACHA = 0xA366,
    ORIYA_D_JAJHA = 0xA367,
    ORIYA_D_KATTA = 0xA368,
    ORIYA_D_NNATTA = 0xA369,
    ORIYA_D_GADHATTA = 0xA36A,
    ORIYA_D_PHATTA = 0xA36B,
    ORIYA_D_SSATTA = 0xA36C,
    ORIYA_D_SATTA = 0xA36D,
    ORIYA_D_LATTA = 0xA36E,
    ORIYA_D_CHATTA = 0xA36F,
    ORIYA_D_NNATTHA = 0xA370,
    ORIYA_D_SSATTHA = 0xA371,
    ORIYA_D_DDADDA = 0xA372,
    ORIYA_D_LLADDA = 0xA373,
    ORIYA_D_KASSANNA = 0xA374,
    ORIYA_D_GANNA = 0xA375,
    ORIYA_D_HANNA = 0xA376,
    ORIYA_D_TATHA = 0xA377,
    ORIYA_D_GADA = 0xA378,
    ORIYA_D_GADHA = 0xA379,
    ORIYA_D_BADHA = 0xA37A,
    ORIYA_D_PAPA = 0xA37B,
    ORIYA_D_LLAPA = 0xA37C,
    ORIYA_D_SSAPA = 0xA37D,
    ORIYA_D_SAPA = 0xA37E,
    ORIYA_D_LAPHA = 0xA37F,
    ORIYA_D_LLAPHA = 0xA380,
    ORIYA_D_SSAPHA = 0xA381,
    ORIYA_D_SAPHA = 0xA382,
    ORIYA_D_DABA = 0xA383,
    ORIYA_D_LLABHA = 0xA384,
    ORIYA_D_MAMA = 0xA385,
    ORIYA_D_DAYA = 0xA386,
    ORIYA_D_KASA = 0xA387,
    ORIYA_D_DDASA = 0xA388,
    ORIYA_D_NASA = 0xA389,
    ORIYA_D_PASA = 0xA38A,
    ORIYA_D_MASA = 0xA38B,
    ORIYA_D_LASA = 0xA38C,
    ORIYA_D_SASA = 0xA38D,
    ORIYA_L_TASANA = 0xA38E,
    ORIYA_L_NATAWA = 0xA38F,
    ORIYA_L_NADAWA = 0xA390,
    ORIYA_L_CHACHHA = 0xA391,
    ORIYA_L_NADHAYYA = 0xA392,
    ORIYA_L_NATARAYYA = 0xA393,
    ORIYA_L_TATAYYA = 0xA394,   
    ORIYA_L_JAJAWA = 0xA395,
    ORIYA_L_DAMA = 0xA396,
    ORIYA_L_BAYYA = 0xA397,
    ORIYA_L_GHAYYA = 0xA398,
    ORIYA_L_THAYYA = 0xA399,         
    ORIYA_L_TAYYA = 0xA39A,
    ORIYA_SUP_RA = 0xA39B,
    ORIYA_SUB_RA = 0xA39C,
    ORIYA_L_ACB = 0xA39D,
    ORIYA_SUP_RA1 = 0xA39E,
    ORIYA_SAN_YA = 0xA39F,
    
    ORIYA_L_KHAMA = 0xA3A0,
    ORIYA_L_GHAMA = 0xA3A1,
    ORIYA_L_NGAMA = 0xA3A2,
    ORIYA_L_CAMA = 0xA3A3,
    ORIYA_L_CHAMA = 0xA3A4,
    ORIYA_L_JAMA = 0xA3A5,
    ORIYA_L_JHAMA = 0xA3A6,
    ORIYA_L_NYAMA = 0xA3A7,
    ORIYA_L_TTAMA = 0xA3A8,
    ORIYA_L_TTHAMA = 0xA3A9,
    ORIYA_L_DDAMA = 0xA3AA,
    ORIYA_L_DDHAMA = 0xA3AB,
    ORIYA_L_NNAMA = 0xA3AC,
    ORIYA_L_TAMA = 0xA3AD,
    ORIYA_L_THAMA = 0xA3AE,
    ORIYA_L_DHAMA = 0xA3AF,
    ORIYA_L_NAMA = 0xA3B0,
    ORIYA_L_PAMA = 0xA3B1,
    ORIYA_L_PHAMA = 0xA3B2,
    ORIYA_L_BAMA = 0xA3B3,
    ORIYA_L_BHAMA = 0xA3B4,
    ORIYA_L_MAMA = 0xA3B5,
    ORIYA_L_YAMA = 0xA3B6,
    ORIYA_L_RAMA = 0xA3B7,
    ORIYA_L_LAMA = 0xA3B8,
    ORIYA_L_LLAMA = 0xA3B9,
    ORIYA_L_VAMA = 0xA3BA,
    ORIYA_L_SHAMA = 0xA3BB,
    ORIYA_L_SSAMA = 0xA3BC,
    ORIYA_L_SAMA = 0xA3BD,
    ORIYA_L_HAMA = 0xA3BE,
    ORIYA_L_RRAMA = 0xA3BF,
    ORIYA_L_RHAMA = 0xA3C0,
    ORIYA_L_YYAMA = 0xA3C1,
    ORIYA_L_ISSHARMA = 0xA3C2,
    ORIYA_L_WAMA = 0xA3C3,
    ORIYA_L_SHALA = 0xA3C4,
    ORIYA_L_U = 0xA3C5,
    ORIYA_L_UU = 0xA3C6,
    ORIYA_L_VR = 0xA3C7,
    ORIYA_L_VRR = 0xA3C8,
    ORIYA_L_SUBRA = 0xA3C9    
} oriya_ligatures_enum;


#if defined (__MMI_MULTITAP_ORIYA__)

extern const UI_character_type default_oriya_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_oriyamatra_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_oriyamatra1_multitap_strings[MAX_MULTITAPS][32];
extern const UI_character_type default_oriyamatra2_multitap_strings[MAX_MULTITAPS][32];
 
extern UI_string_type get_oriya_multitap_string(S32 i);
extern UI_string_type get_oriya_single_line_multitap_string(S32 i);
extern UI_character_type *get_oriya_multitap_string_for_vk(S32 i);

#endif /* defined (__MMI_MULTITAP_ORIYA__) */ 
#endif /* defined (__MMI_LANG_ORIYA__) */ /* defined (__MMI_LANG_ORIYA__) || defined(__MMI_LANG_MARATHI__) */

//UI_character_type pre_previous_char; /* to store previous character[chandrabindu not allowed after consonant+super-ra] */ 
#endif /* MMI_ORIYA_H */ 


