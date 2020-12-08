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
 *  Thai.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Thai language module
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "./../LangModuleInc/ThaiGProt.h"
#include "./../LangModuleInc/Thai.h"
#include "gui_data_types.h"
#if defined(__MMI_LANG_THAI__)
#include "wgui_inputs.h"
#include "gui_ems.h"
#include "gui_inputs.h"
#include "LangModule.h"
#include "ImeGprot.h"

/* RHR */
#include "MMIDataType.h"
#include "kal_general_types.h"
    
/****************************************************************************** 
* External Global variables
***************************************************************************** */
extern stFontAttribute     MMI_medium_font;

/****************************************************************************** 
* External Global Functions
***************************************************************************** */

/****************************************************************************** 
* Global variables
***************************************************************************** */
#if defined(__MMI_MULTITAP_THAI__)
#if defined(__MMI_MULTITAP_THAI_PROFILE_1__)
/* the begining key mapping 
  * only leading vowel, sign, consonant are allowed
  */
const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */ /* only leading vowel allowed when first input */
    {THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};
/* after a consonant is input 
  * all are allowed
  */
const UI_character_type default_multitap_thai_strings_con[MAX_MULTITAPS][32] = 
{
    {THAI_AV_MAIHAN_AKAT, THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_BV_SARA_U, THAI_BV_SARA_UU, '0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */
    {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};
/* after tone mark 
  * no other tone mark, above and below vowel
  */
const UI_character_type default_multitap_thai_strings_tone[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */
    {THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};
/* After Above and Below vowel
  * no above and below vowel is allowed
  */
const UI_character_type default_multitap_thai_strings_vowel[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */
    {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};

const UI_character_type default_multitap_thai_strings_sara_aa[MAX_MULTITAPS][32] = 
{
    {'0', '\0'},
    {' ', '.', ',', '-', '(', ')', '%', '!', '1', '\0'},
    {THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHUAT, THAI_C_KHO_KHWAI, THAI_C_KHO_KHON, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, '2', '\0'},
    {THAI_C_CHO_CHAN, THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, '3', '\0'},
    {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_C_DO_DEK, THAI_C_TO_TAO, '4', '\0'},
    {THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, '5', '\0'},
    {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, '6', '\0'},
    {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_C_LU, '7', '\0'},
    {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, '8', '\0'},
    {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, '9', '\0'},
    {THAI_FV_SARA_A, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_LV_SARA_O, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, '\0'},     /* '*' */ /* only leading vowel allowed when first input */
    {THAI_S_PAIYANNOI, THAI_S_MAIYAMOK, THAI_SB_BAHT, '\0'},     /* '#' */
};

#else 
/* for default case, it should be __MMI_MULTITAP_THAI_PROFILE_2__ */

/* the begining key mapping 
  * only leading vowel, sign, consonant are allowed
  */
const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};

/* after a consonant is input 
  * all are allowed
  */
const UI_character_type default_multitap_thai_strings_con[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, THAI_AV_MAIHAN_AKAT, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_BV_SARA_U, THAI_BV_SARA_UU, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* after tone mark 
  * no other tone mark, above and below vowel
  */
const UI_character_type default_multitap_thai_strings_tone[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ { THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* After Above and Below vowel
  * no above and below vowel is allowed
  */
const UI_character_type default_multitap_thai_strings_vowel[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_multitap_thai_strings_sara_aa[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};



#endif

#elif defined (__MMI_LANG_THAI__) 
/* for default case, it should be __MMI_MULTITAP_THAI_PROFILE_2__ */

/* the begining key mapping 
  * only leading vowel, sign, consonant are allowed
  */
const UI_character_type default_multitap_thai_strings_normal[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};

/* after a consonant is input 
  * all are allowed
  */
const UI_character_type default_multitap_thai_strings_con[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, THAI_AV_MAIHAN_AKAT, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_AV_SARA_I, THAI_AV_SARA_II, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_AV_SARA_UEE, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_AV_MAITAIKHU, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_BV_SARA_U, THAI_BV_SARA_UU, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* after tone mark 
  * no other tone mark, above and below vowel
  */
const UI_character_type default_multitap_thai_strings_tone[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ { THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
/* After Above and Below vowel
  * no above and below vowel is allowed
  */
const UI_character_type default_multitap_thai_strings_vowel[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_FV_SARA_AA, THAI_FV_SARA_AM, THAI_S_LAKKHANGYAO, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_AV_SARA_UE, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_TM_MAI_EK, THAI_TM_MAI_THO, THAI_TM_MAI_TRI, THAI_TM_MAI_CHATTAWA, THAI_S_THANTHAKHAT, THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_S_MAIYAMOK, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_multitap_thai_strings_sara_aa[MAX_MULTITAPS][32] = 
{
    /* key0 */ {THAI_D_ZERO, ' ', 0x0030, '\0'},
    /* key1 */ {THAI_D_ONE, THAI_C_KO_KAI, THAI_C_KHO_KHAI, THAI_C_KHO_KHWAI, THAI_C_KHO_RAKHANG, THAI_C_NGO_NGU, THAI_C_CHO_CHAN, THAI_FV_SARA_A, 0x0031, '\0'},
    /* key2 */ {THAI_C_CHO_CHING, THAI_C_CHO_CHANG, THAI_C_SO_SO, THAI_C_CHO_CHOE, THAI_C_YO_YING, THAI_D_TWO, 0x0032, '\0'},
    /* key3 */ {THAI_C_DO_CHADA, THAI_C_TO_PATAK, THAI_C_THO_THAN, THAI_C_THO_NANGMONTHO, THAI_C_THO_PHUTHAO, THAI_C_NO_NEN, THAI_D_THREE, 0x0033, '\0'},
    /* key4 */ {THAI_C_DO_DEK, THAI_C_TO_TAO, THAI_C_THO_THUNG, THAI_C_THO_THAHAN, THAI_C_THO_THONG, THAI_C_NO_NU, THAI_D_FOUR, 0x0034, '\0'},
    /* key5 */ {THAI_D_FIVE, 0x0035, '\0'},
    /* key6 */ {THAI_C_BO_BAIMAI, THAI_C_PO_PLA, THAI_C_PHO_PHUNG, THAI_C_FO_FA, THAI_C_PHO_PHAN, THAI_C_FO_FAN, THAI_D_SIX, 0x0036, '\0'},
    /* key7 */ {THAI_C_PHO_SAMPHAO, THAI_C_MO_MA, THAI_C_YO_YAK, THAI_C_RO_RUA, THAI_C_RU, THAI_C_LO_LING, THAI_LV_SARA_E, THAI_LV_SARA_AE, THAI_D_SEVEN, 0x0037, '\0'},
    /* key8 */ {THAI_C_WO_WAEN, THAI_C_SO_SALA, THAI_C_SO_RUSI, THAI_C_SO_SUA, THAI_LV_SARA_O, THAI_D_EIGHT, 0x0038, '\0'},
    /* key9 */ {THAI_C_HO_HIP, THAI_C_LO_CHULA, THAI_C_O_ANG, THAI_C_HO_NOKHUK, THAI_LV_SARA_AI_MAIMUAN, THAI_LV_SARA_AI_MAIMALAI, THAI_D_NINE, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

};



#endif

/***************************************************************************** 
* Local Variables
*****************************************************************************/
const Thai_character_info_table_struct thai_character_info_table[] =	
{
    /* 0x0E01 */
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},
    //THAI_C_KHO_KHAI , 0x0E02
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},    
    //THAI_C_KHO_KHUAT , 0x0E03
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_KHO_KHWAI , 0x0E04
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_KHO_KHON , 0x0E05
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_KHO_RAKHANG , 0x0E06
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_NGO_NGU , 0x0E07
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_CHO_CHAN , 0x0E08
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_CHO_CHING , 0x0E09
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_CHO_CHANG , 0x0E0A
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_SO_SO , 0x0E0B
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_CHO_CHOE , 0x0E0C
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_YO_YING , 0x0E0D
    {THAI_CHAR_SPLITTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_DO_CHADA , 0x0E0E
    {THAI_CHAR_UNDERTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_TO_PATAK , 0x0E0F
    {THAI_CHAR_UNDERTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_THO_THAN , 0x0E10
    {THAI_CHAR_SPLITTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_THO_NANGMONTHO , 0x0E11
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_THO_PHUTHAO , 0x0E12
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_NO_NEN , 0x0E13
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_DO_DEK , 0x0E14
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_TO_TAO , 0x0E15
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_THO_THUNG , 0x0E16
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_THO_THAHAN , 0x0E17
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_THO_THONG , 0x0E18
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_NO_NU , 0x0E19
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_BO_BAIMAI , 0x0E1A
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_PO_PLA , 0x0E1B
    {THAI_CHAR_LONGTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_PHO_PHUNG , 0x0E1C
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_FO_FA , 0x0E1D
    {THAI_CHAR_LONGTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_PHO_PHAN , 0x0E1E
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_FO_FAN , 0x0E1F
    {THAI_CHAR_LONGTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_PHO_SAMPHAO , 0x0E20
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_MO_MA , 0x0E21
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_YO_YAK , 0x0E22
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_RO_RUA , 0x0E23
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_RU , 0x0E24
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_LO_LING , 0x0E25
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_LU , 0x0E26
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_WO_WAEN , 0x0E27
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_SO_SALA , 0x0E28
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_SO_RUSI , 0x0E29
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_SO_SUA , 0x0E2A
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_HO_HIP , 0x0E2B
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_LO_CHULA , 0x0E2C
    {THAI_CHAR_LONGTAIL_CONSONANT,  THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_O_ANG , 0x0E2D
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_C_HO_NOKHUK , 0x0E2E
    {THAI_CHAR_CONSONANT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_S_PAIYANNOI , 0x0E2F
    {THAI_CHAR_SIGN, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_FV_SARA_A , 0x0E30 /* following vowels */
    {THAI_CHAR_FOLLOW_VOWEL, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_AV_MAIHAN_AKAT , 0x0E31 /* above vowels */
    {THAI_CHAR_ABOVE_VOWEL,  THAI_CHAR_POSITION_ABOVE_L2}, 
    //THAI_FV_SARA_AA , 0x0E32 /* following vowels */
    {THAI_CHAR_FOLLOW_VOWEL, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_FV_SARA_AM , 0x0E33 /* following vowels */
    {THAI_CHAR_FOLLOW_VOWEL, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_AV_SARA_I , 0x0E34 /* above vowels */
    {THAI_CHAR_ABOVE_VOWEL,  THAI_CHAR_POSITION_ABOVE_L2}, 
    //THAI_AV_SARA_II , 0x0E35 /* above vowels */
    {THAI_CHAR_ABOVE_VOWEL,  THAI_CHAR_POSITION_ABOVE_L2}, 
    //THAI_AV_SARA_UE , 0x0E36 /* above vowels */
    {THAI_CHAR_ABOVE_VOWEL,  THAI_CHAR_POSITION_ABOVE_L2}, 
    //THAI_AV_SARA_UEE , 0x0E37 /* above vowels */
    {THAI_CHAR_ABOVE_VOWEL,  THAI_CHAR_POSITION_ABOVE_L2}, 
    //THAI_BV_SARA_U , 0x0E38 /* above vowels */
    {THAI_CHAR_BELOW_VOWEL, THAI_CHAR_POSITION_BELOW}, 
    //THAI_BV_SARA_UU , 0x0E39 /* above vowels */
    {THAI_CHAR_BELOW_VOWEL, THAI_CHAR_POSITION_BELOW},
    //THAI_BV_PHINTHU , 0x0E3A /* below vowels */
    {THAI_CHAR_BELOW_VOWEL, THAI_CHAR_POSITION_BELOW},
    // 0x0E3B
    {THAI_CHAR_NONE, THAI_CHAR_POSITION_NONE},
    // 0x0E3C
    {THAI_CHAR_NONE, THAI_CHAR_POSITION_NONE},
    // 0x0E3D
    {THAI_CHAR_NONE, THAI_CHAR_POSITION_NONE},
    // 0x0E3E
    {THAI_CHAR_NONE, THAI_CHAR_POSITION_NONE},
    //THAI_SB_BAHT , 0x0E3F /* currency symbol */
    {THAI_CHAR_CURRENCY_SYMBOL, THAI_CHAR_POSITION_BELOW},
    //THAI_LV_SARA_E , 0x0E40 /* leading vowels */
    {THAI_CHAR_LEAD_VOWEL, THAI_CHAR_POSITION_BASELINE},
    //THAI_LV_SARA_AE , 0x0E41 /* leading vowels */
    {THAI_CHAR_LEAD_VOWEL, THAI_CHAR_POSITION_BASELINE},
    //THAI_LV_SARA_O , 0x0E42 /* leading vowels */
    {THAI_CHAR_LEAD_VOWEL, THAI_CHAR_POSITION_BASELINE},
    //THAI_LV_SARA_AI_MAIMUAN , 0x0E43 /* leading vowels */
    {THAI_CHAR_LEAD_VOWEL, THAI_CHAR_POSITION_BASELINE},
    //THAI_LV_SARA_AI_MAIMALAI , 0x0E44 /* leading vowels */
    {THAI_CHAR_LEAD_VOWEL, THAI_CHAR_POSITION_BASELINE},
    //THAI_S_LAKKHANGYAO , 0x0E45 /* signs */
    {THAI_CHAR_SIGN, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_S_MAIYAMOK , 0x0E46 /* signs repetition */
    {THAI_CHAR_SIGN, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_AV_MAITAIKHU , 0x0E47 /* above vowels */
    {THAI_CHAR_ABOVE_VOWEL,  THAI_CHAR_POSITION_ABOVE_L1}, 
    //THAI_TM_MAI_EK , 0x0E48 /* tone mark */
    {THAI_CHAR_TONE_MARK,  THAI_CHAR_POSITION_ABOVE_L1},
    //THAI_TM_MAI_THO , 0x0E49 /* tone mark */
    {THAI_CHAR_TONE_MARK,  THAI_CHAR_POSITION_ABOVE_L1},
    //THAI_TM_MAI_TRI , 0x0E4A /* tone mark */
    {THAI_CHAR_TONE_MARK,  THAI_CHAR_POSITION_ABOVE_L1},
    //THAI_TM_MAI_CHATTAWA , 0x0E4B /* tone mark */
    {THAI_CHAR_TONE_MARK,  THAI_CHAR_POSITION_ABOVE_L1},
    //THAI_S_THANTHAKHAT , 0x0E4C /* sign - cancellation mark */
    {THAI_CHAR_SIGN,  THAI_CHAR_POSITION_ABOVE_L1}, 
    //THAI_S_NIKHAHIT , 0x0E4D /* sign - final nasal */
    {THAI_CHAR_SIGN,  THAI_CHAR_POSITION_ABOVE_L1}, 
    //THAI_S_YAMAKKAN , 0x0E4E /* sign */
    {THAI_CHAR_SIGN,  THAI_CHAR_POSITION_ABOVE_L1}, 
    //THAI_S_FONGMAN , 0x0E4F /* sign - used as a bullet */
    {THAI_CHAR_SIGN, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_D_ZERO , 0x0E50 /* Thai digital 0 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_ONE , 0x0E51 /* Thai digital 1 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_TWO , 0x0E52 /* Thai digital 2 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_THREE , 0x0E53 /* Thai digital 3 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_FOUR , 0x0E54 /* Thai digital 4 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_FIVE , 0x0E55 /* Thai digital 5 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_SIX , 0x0E56 /* Thai digital 6 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_SEVEN , 0x0E57 /* Thai digital 7 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_EIGHT , 0x0E58 /* Thai digital 8 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_D_NINE , 0x0E59 /* Thai digital 9 */
    {THAI_CHAR_DIGIT, THAI_CHAR_POSITION_BASELINE},  
    //THAI_S_ANGKHANKHU , 0x0E5A /* sign */
    {THAI_CHAR_SIGN, THAI_CHAR_POSITION_BASELINE}, 
    //THAI_S_KHOMUT , 0x0E5B
    {THAI_CHAR_SIGN, THAI_CHAR_POSITION_BASELINE}, 
       
};

static MMI_BOOL g_mmi_lm_thai_private_check = MMI_FALSE;
static MMI_BOOL g_mmi_lm_thai_private_usage = MMI_FALSE;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)

/* windows private range 0xF700~0xF71A */
static UI_character_type g_mmi_lm_thai_private_range[] = 
{
    0xF700, 0xF701, 0xF702, 0xF703, 0xF704, 0xF705, 0xF706, 0xF707, 
    0xF708, 0xF709, 0xF70A, 0xF70B, 0xF70C, 0xF70D, 0xF70E, 0xF70F, 
    0xF710, 0xF711, 0xF712, 0xF713, 0xF714, 0xF715, 0xF716, 0xF717, 
    0xF718, 0xF719, 0xF71A       
};
#else
/* Thai private range according to MTK font spec */
static UI_character_type g_mmi_lm_thai_private_range[] = 
{
    0xF700, 0xF70F       
};

#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_lm_thai_measure_cluster(mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p curr_cluster);
static MMI_BOOL RequireToMoveCursor(U16 preCh, U16 curCh);
static MMI_BOOL is_thai_char_in_table(const UI_character_type default_multitap_thai_array[MAX_MULTITAPS][32], UI_character_type candidate);
MMI_BOOL is_thai_valid_input_int(UI_string_type candidate, U8 strlen, UI_string_type previous_string);

#define MMI_LM_THAI_GET_CHAR_TYPE(ch) (thai_character_info_table[THAI_CHAR_OFFSET((ch))].char_type)

#define MMI_LM_THAI_GET_CHAR_POS(ch) (thai_character_info_table[THAI_CHAR_OFFSET((ch))].char_position)

#define MMI_LM_THAI_CHECK_FLAG(flag, mask)	((flag) & (mask))

#define MMI_LM_THAI_CHECK_CHAR_TYPE(ch, mask)	(MMI_LM_THAI_CHECK_FLAG(MMI_LM_THAI_GET_CHAR_TYPE((ch)),  (mask)))

#define MMI_LM_THAI_CHECK_CHAR_POS(ch, mask)	(MMI_LM_THAI_CHECK_FLAG(MMI_LM_THAI_GET_CHAR_POS((ch)), (mask)))

/*****************************************************************************
 * FUNCTION
 *  IsThaiUpDownVowel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiUpDownVowel(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_AV_MAIHAN_AKAT || ch >= THAI_AV_SARA_I && ch <= THAI_BV_PHINTHU || ch == THAI_AV_MAITAIKHU)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiUpVowel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiUpVowel(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_AV_MAIHAN_AKAT || ch >= THAI_AV_SARA_I && ch <= THAI_AV_SARA_UEE || ch == THAI_AV_MAITAIKHU)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiConsonant
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiConsonant(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= THAI_C_KO_KAI && ch <= THAI_C_HO_NOKHUK)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiToneMark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiToneMark(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_TM_MAI_EK || ch == THAI_TM_MAI_THO || ch == THAI_TM_MAI_TRI || ch == THAI_TM_MAI_CHATTAWA)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiBaseLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiBaseLineChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= THAI_C_KO_KAI && ch <= THAI_S_KHOMUT)
    {
        /* above vowels */
        if (ch != THAI_AV_MAIHAN_AKAT && ch != THAI_AV_MAITAIKHU && ch != THAI_AV_SARA_I && 
            ch != THAI_AV_SARA_II && ch != THAI_AV_SARA_UE && ch != THAI_AV_SARA_UEE &&
            /* Tone marks */
            ch != THAI_TM_MAI_CHATTAWA && ch != THAI_TM_MAI_EK && ch != THAI_TM_MAI_THO && ch != THAI_TM_MAI_TRI &&
            /* Below vowels */
            ch != THAI_BV_PHINTHU && ch != THAI_BV_SARA_U && ch != THAI_BV_SARA_UU && 
            /* Signs */
            ch != THAI_S_ANGKHANKHU && ch != THAI_S_FONGMAN && ch != THAI_S_KHOMUT && ch != THAI_S_LAKKHANGYAO && 
            ch != THAI_S_MAIYAMOK && ch != THAI_S_NIKHAHIT && ch != THAI_S_PAIYANNOI && ch != THAI_S_THANTHAKHAT && ch != THAI_S_YAMAKKAN &&
            /* Exclude Thai digits */
            ch <= THAI_D_ZERO)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }

    }
    else if (ch == 0xF70F || ch == 0xF700)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiAboveLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL IsThaiBaseLineVowel(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == 0x0e32 || ch == 0x0e33 || (ch >= 0x0e40 && ch <= 0x0e45))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  IsThaiAboveLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiAboveLineChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_AV_MAIHAN_AKAT || ch == THAI_AV_SARA_I || ch == THAI_AV_SARA_II || ch == THAI_AV_SARA_UE || ch == THAI_AV_SARA_UEE || ch == THAI_AV_MAITAIKHU || ch == THAI_S_THANTHAKHAT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiBottomLineChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiBottomLineChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_BV_SARA_U || ch == THAI_BV_SARA_UU || ch == THAI_BV_PHINTHU)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiLongTailChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiLongTailChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_C_PO_PLA || ch == THAI_C_FO_FA || ch == THAI_C_FO_FAN)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsThaiDigitChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiDigitChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= THAI_D_ZERO && ch <= THAI_D_NINE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}



/*****************************************************************************
 * FUNCTION
 *  isThaiSignChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL IsThaiSignChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsThaiUpSign(ch) || IsThaiBaseSignChar(ch))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  IsThaiUpSign
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL IsThaiUpSign(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= 0x0E4C && ch <= 0x0E4e))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  IsThaiBaseSignChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL IsThaiBaseSignChar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == THAI_S_PAIYANNOI || ch == THAI_SB_BAHT || ch == THAI_S_LAKKHANGYAO || ch == THAI_S_MAIYAMOK || ch == THAI_S_FONGMAN || ch == THAI_S_ANGKHANKHU || ch == THAI_S_KHOMUT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  RequireToMoveCursor
 * DESCRIPTION
 *  TO check if the cursor position should be moved or not.
 * PARAMETERS
 *  preCh:       [IN]      the prevois character  
 *  curCh:       [IN]      the current character  
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static MMI_BOOL RequireToMoveCursor(U16 preCh, U16 curCh)
{
#if defined(__MMI_LANG_THAI__)
    pBOOL isPreBaseLineChar = IsThaiBaseLineChar(preCh);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curCh >= 0x0E01 && curCh <= 0x0E7F)
    {
        //if (curCh == THAI_FV_SARA_AM && IsThaiConsonant(preCh))
		if (curCh == THAI_FV_SARA_AM && (IsThaiConsonant(preCh) || IsThaiToneMark(preCh) || IsThaiUpDownVowel(preCh) ))
        {
            return MMI_FALSE;
        }
        else if (IsThaiBaseLineChar(curCh) || IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
        {   /* For base level character */
            return MMI_TRUE;
        }
        else if (IsThaiAboveLineChar(curCh))
        {   /* For above level character */
            if (isPreBaseLineChar && IsThaiConsonant(preCh))
            {
                return MMI_FALSE;
            }
            /*else if (curCh == 0x0E4C && preCh != 0x0E4C && preCh != 0x0E47)
            {
                return FALSE;
            }*/
            else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            }

        }
        else if (IsThaiBottomLineChar(curCh))
        {   /* For below level character */
            if (isPreBaseLineChar && IsThaiConsonant(preCh))
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            }
        }
        else if (IsThaiToneMark(curCh))
        {   /* For Tone mark characters */
            
            /* Tone couldn't be put together with Sign. */
            if (IsThaiSignChar(preCh))
            {
                return MMI_TRUE;
            }
            if ((isPreBaseLineChar && preCh != THAI_FV_SARA_A)  || IsThaiAboveLineChar(preCh) || IsThaiBottomLineChar(preCh))
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            }

        }
        else if (IsThaiUpSign(curCh))
        {
            /* current character is sign and the previous character is consonant */
            if (IsThaiBaseLineChar(preCh))
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            }
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
#endif
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_get_cluster_info
 * DESCRIPTION
 *  Get thai cluster info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lm_thai_get_cluster_info(mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_fe_query_single_cluster(prev_cluster, cluster);
}


static UI_character_type mmi_lm_thai_get_shift_down_windows(UI_character_type in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (in)
    {
       /* below vowel */    
       case 0x0E38:
           return 0xF718;
       case 0x0E39:
       	   return 0xF719;
       case 0x0E3A:
       	   return 0xF71A;
       /*  character of above layer 1 */	   
       case 0x0E48:
           return 0xF70A;
       case 0x0E49:
       	   return 0xF70B;
       case 0x0E4A:
       	   return 0xF70C;       	
       case 0x0E4B:
       	   return 0xF70D;
       case 0x0E4C:
       	   return 0xF70E;       	
       default:
       	   return in;
    }
}

static UI_character_type mmi_lm_thai_get_shift_left_windows(UI_character_type in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (in)
    {
       case 0x0E34:
           return 0xF701;
       case 0x0E35:
       	   return 0xF702;
       case 0x0E36:
       	   return 0xF703;
       case 0x0E37:
       	   return 0xF704;
       case 0x0E31:
       	   return 0xF710;
       case 0x0E4D:
       	   return 0xF711;
       case 0x0E47:
       	   return 0xF712;
       case 0x0E48:
       	   return 0xF713;
       case 0x0E49:
       	   return 0xF714;
       case 0x0E4A:
       	   return 0xF715;
       case 0x0E4B:
       	   return 0xF716;
       case 0x0E4C:
       	   return 0xF717;
       default:
       	   return in;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_substitute
 * DESCRIPTION
 *  To substitute Thai char by private char
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lm_thai_substitute(mmi_lm_cluster_info_p curr_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    /* substitution */
    if (g_mmi_lm_thai_private_usage)
    {
        if (curr_cluster->display_buffer[0] == THAI_C_YO_YING || curr_cluster->display_buffer[0] == THAI_C_THO_THAN)
        {
            /* check for below vowel */
            if (curr_cluster->cluster_len > 1)
            {
                U32 attr = MMI_LM_THAI_GET_CHAR_TYPE(curr_cluster->display_buffer[1]);
                if (attr == THAI_CHAR_BELOW_VOWEL)
                {
                    if (curr_cluster->display_buffer[0] == THAI_C_YO_YING)
                        curr_cluster->display_buffer[0] = 0xF70F;
                    if (curr_cluster->display_buffer[0] == THAI_C_THO_THAN)
                        curr_cluster->display_buffer[0] = 0xF700;
                    
                }
            }
        }
    }
#else
    if (g_mmi_lm_thai_private_usage)
    {
        if (curr_cluster->cluster_len == 1 && 
            (!(MMI_LM_THAI_CHECK_CHAR_POS(curr_cluster->display_buffer[0], THAI_CHAR_POSITION_BASELINE)) ||
               curr_cluster->display_buffer[0] == THAI_FV_SARA_AM))
        {
            /* add 0x25cc invalid combining marks */            
            curr_cluster->display_buffer[1] = curr_cluster->display_buffer[0];
            curr_cluster->cluster_len++;
            curr_cluster->display_buffer[0] = MMI_LM_BASE_CHAR;
        }
        else if (curr_cluster->cluster_len == 2)
        {
            UI_character_type curCh = curr_cluster->display_buffer[0];
            UI_character_type nextCh = curr_cluster->display_buffer[1];
            if (MMI_LM_THAI_CHECK_CHAR_TYPE(curCh, THAI_CHAR_LONGTAIL_CONSONANT) &&
            	nextCh == THAI_FV_SARA_AM)
          	{
                /* for longtail consonant, replace 0x0E33 with 0xF711 + 0x0E32 */
                curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_left_windows(0x0E4D);
                curr_cluster->display_buffer[2] = 0x0E32;
                curr_cluster->cluster_len = 3;

            }
            else if (MMI_LM_THAI_CHECK_CHAR_TYPE(curCh, THAI_CHAR_CONSONANT) &&
            	nextCh == THAI_FV_SARA_AM)
          	{
                /* replace 0x0E33 with 0x0E4D + 0x0E32 */
                curr_cluster->display_buffer[1] = 0x0E4D;
                curr_cluster->display_buffer[2] = 0x0E32;
                curr_cluster->cluster_len = 3;

            }
            else if (IsThaiLongTailChar(curCh))
            {
                if (MMI_LM_THAI_CHECK_CHAR_POS(nextCh, THAI_CHAR_POSITION_ABOVE))
                {
                    curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_left_windows(nextCh) ;
                }
            }
            else if (!IsThaiLongTailChar(curCh) && 
            	     (MMI_LM_THAI_CHECK_CHAR_POS(nextCh, THAI_CHAR_POSITION_ABOVE_L1)))
            {
                curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_down_windows(nextCh) ;
            }
            else if (MMI_LM_THAI_CHECK_CHAR_POS(nextCh, THAI_CHAR_POSITION_BELOW))
           	{
           	    switch(curCh)
           	    {
           	        case 0x0E0E:
           	    	case 0x0E0F:	
           	            curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_down_windows(nextCh) ;
           	    	    break;
           	    	case 0x0E0D:
           	    		curr_cluster->display_buffer[0] = 0xF70F;
           	    		break;
           	    	case 0X0E10:
           	    		curr_cluster->display_buffer[0] = 0xF700;
           	    		break;
           	    }
           	}
            
        }
        else if (curr_cluster->cluster_len == 3)
        {
            UI_character_type curCh = curr_cluster->display_buffer[0];
            UI_character_type nextCh = curr_cluster->display_buffer[1];
            UI_character_type next2Ch = curr_cluster->display_buffer[2];
            if (IsThaiLongTailChar(curCh) &&
            	   MMI_LM_THAI_CHECK_CHAR_TYPE(nextCh, THAI_CHAR_TONE_MARK) &&
            	    next2Ch == THAI_FV_SARA_AM)
            {
                curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_left_windows(0x0E4D);
                curr_cluster->display_buffer[2] = mmi_lm_thai_get_shift_left_windows(nextCh);
                curr_cluster->display_buffer[3] = 0x0E32;       	        
                curr_cluster->cluster_len = 4;	
            }
            else if (!IsThaiLongTailChar(curCh) &&
                 	MMI_LM_THAI_CHECK_CHAR_TYPE(nextCh, THAI_CHAR_TONE_MARK) &&
                 	next2Ch == THAI_FV_SARA_AM)
            {
                curr_cluster->display_buffer[1] = 0x0E4D;
                curr_cluster->display_buffer[2] = nextCh;
                curr_cluster->display_buffer[3] = 0x0E32;       	        
                curr_cluster->cluster_len = 4;	
            }
            else if (IsThaiLongTailChar(curCh) &&
            	          MMI_LM_THAI_CHECK_CHAR_TYPE(nextCh, THAI_CHAR_ABOVE_VOWEL | THAI_CHAR_BELOW_VOWEL) &&
            	          MMI_LM_THAI_CHECK_CHAR_POS(next2Ch, THAI_CHAR_POSITION_ABOVE_L1))
            {
                curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_left_windows(nextCh);
                curr_cluster->display_buffer[2] = mmi_lm_thai_get_shift_left_windows(next2Ch);
            }
            else if (MMI_LM_THAI_CHECK_CHAR_POS(curCh, THAI_CHAR_POSITION_BASELINE) &&
            	          MMI_LM_THAI_CHECK_CHAR_TYPE(nextCh, THAI_CHAR_BELOW_VOWEL) &&
                       MMI_LM_THAI_CHECK_CHAR_POS(next2Ch, THAI_CHAR_POSITION_ABOVE_L1))
            {
                curr_cluster->display_buffer[1] = nextCh;
                curr_cluster->display_buffer[2] = mmi_lm_thai_get_shift_down_windows(next2Ch);                 
            }
            else if (MMI_LM_THAI_CHECK_CHAR_POS(nextCh, THAI_CHAR_POSITION_BELOW))
            {
                switch(curCh)
                {
                    case 0x0E0E:
                    case 0x0E0F:	
                        curr_cluster->display_buffer[1] = mmi_lm_thai_get_shift_down_windows(nextCh) ;
                        break;
                    case 0x0E0D:
                        curr_cluster->display_buffer[0] = 0xF70F;
                        break;
                    case 0X0E10:
                        curr_cluster->display_buffer[0] = 0xF700;
                        break;
                }
            }

        }

    }
    else
    {
        S32 i = 0;
        for (i = 0; i < curr_cluster->cluster_len; i ++)
        {
            if (curr_cluster->display_buffer[i] == THAI_FV_SARA_AM)
            {
                MMI_ASSERT((curr_cluster->cluster_len) < MMI_LM_CLUSTER_MAX);
                memmove(&curr_cluster->display_buffer[i + 2], &curr_cluster->display_buffer[i + 1], curr_cluster->cluster_len - i);
                curr_cluster->display_buffer[i] = 0x0E4D;
                curr_cluster->display_buffer[++i] = 0x0e32;
                curr_cluster->cluster_len ++;
            }
        }
    }

#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_get_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_thai_get_current_cluster(
            PU8 start, 
            PU8 end, 
            mmi_lm_cluster_info_p prev2_cluster, 
            mmi_lm_cluster_info_p prev_cluster, 
            mmi_lm_cluster_info_p curr_cluster, 
            MMI_BOOL pos_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type curch, nextch;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_lm_thai_private_check)
    {
        /* check windows Thai private range */
        if (mmi_fe_check_string(MMI_medium_font, (U8*)(&g_mmi_lm_thai_private_range), sizeof(g_mmi_lm_thai_private_range)>>1 ))
            g_mmi_lm_thai_private_usage = MMI_TRUE;
        g_mmi_lm_thai_private_check = MMI_TRUE;
    }

    
    nextch = MMI_LM_GET_CHARACTER_FROM_BUFFER(start);
    do
    {
        curch = nextch;
        nextch = MMI_LM_GET_NEXT_CHARACTER_FROM_BUFFER(start, end);
        curr_cluster->display_buffer[curr_cluster->data_len] = curch;
        curr_cluster->data_len++;
        if (RequireToMoveCursor(curch, nextch) ||  ((curr_cluster->data_len + 1) >= MMI_LM_CLUSTER_MAX))
            break;
        start += 2;
    } while (start < end);

    curr_cluster->cluster_len = curr_cluster->data_len;
    #ifndef __MMI_SCRIPT_EASY__
    mmi_lm_thai_substitute(curr_cluster);
    #endif

    if (!pos_only)
    {
        mmi_lm_thai_measure_cluster(prev_cluster, curr_cluster);
        if (prev_cluster->lang_id== MMI_LM_LANG_INDIC && prev_cluster->lang_id != curr_cluster->lang_id)
        {
            curr_cluster->rx = prev_cluster->w - prev_cluster->adv_x;
            if (curr_cluster->rx < 0)
                curr_cluster->rx = 0;
        }
        if ((prev_cluster->data_len == 1 && 
              MMI_LM_THAI_GET_CHAR_TYPE(prev_cluster->display_buffer[0]) == THAI_CHAR_CONSONANT &&
              !IsThaiLongTailChar(prev_cluster->display_buffer[0])) && 
            curr_cluster->display_buffer[0] == THAI_FV_SARA_AM)
        {
            curr_cluster->rx = -3;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_get_next_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_thai_get_next_cluster(
            PU8 start, 
            PU8 end, 
            PU8 cursor, 
            MMI_BOOL pos_only,
            mmi_lm_cluster_info_p next_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_get_prev_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_thai_get_prev_cluster(
            PU8 start, 
            PU8 end, 
            PU8 cursor, 
            MMI_BOOL pos_only,
            mmi_lm_cluster_info_p prev_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_draw_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lm_thai_draw_cluster(mmi_lm_show_cluster_param_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_show_one_cluster_param_struct fe_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fe_param.string = (PU8)param->cluster->display_buffer;
    fe_param.len = param->cluster->cluster_len;
    fe_param.baseline = param->baseline;
    fe_param.bordered = param->bordered;
    fe_param.x = param->x;
    fe_param.y = param->y;
    fe_param.langid = param->cluster->lang_id;
    fe_param.subarray_start = 0;
    fe_param.subarray_len = fe_param.len;
    mmi_fe_show_single_cluster(&fe_param);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_measure_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_lm_thai_measure_cluster(mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p curr_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct param = {0};
    UI_character_type curch;
    U16 chtype, prechtype = THAI_CHAR_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_GAP;

    if (prev_cluster->lang_id == MMI_LM_LANG_THAI)
    {
        curch = curr_cluster->display_buffer[0];
        chtype = MMI_LM_THAI_GET_CHAR_TYPE(curch);
        if (prev_cluster->cluster_len)
        {
            prechtype = MMI_LM_THAI_GET_CHAR_TYPE(prev_cluster->display_buffer[0]);
        }
        if (chtype == THAI_CHAR_FOLLOW_VOWEL && prechtype == THAI_CHAR_CONSONANT)
        {
            curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
            curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_NO_GAP;
        }
        if (chtype == THAI_CHAR_CONSONANT && prechtype == THAI_CHAR_LEAD_VOWEL)
        {
            curr_cluster->is_connect = MMI_LM_CLUSTER_ATTR_CONNECT;
            curr_cluster->is_gap = MMI_LM_CLUSTER_ATTR_NO_GAP;
        }
        
    }
    param.String = (PU8)curr_cluster->display_buffer;
    param.n = curr_cluster->cluster_len;
    
    mmi_lm_thai_get_cluster_info(prev_cluster, curr_cluster);

    if (prev_cluster->lang_id != curr_cluster->lang_id && prev_cluster->w > prev_cluster->adv_x)
        curr_cluster->rx = prev_cluster->w - prev_cluster->adv_x;
    

}



    
/*****************************************************************************
 * FUNCTION
 *  mmi_lm_thai_cluster_translate
 * DESCRIPTION
 *  Translate string. If in the src, there is a pattern A + B could be changed to another unicode C, then change it to C.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_lm_thai_cluster_translate(UI_string_type src, UI_string_type dst, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = src[0];
    return 1;

}

MMI_BOOL is_thai_valid_input(U16 *Unicode, U8 strlen)
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 previous_str[2] = {0};
    mmi_imc_message_struct imc_msg;
    UI_character_type string_buf[10] = {0}; ///TODO: define an value for the string length

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imc_msg.message_id = MMI_IMC_MESSAGE_IS_AUTO_CLEAR_HIGHLIGHT_WORD_MODE; 
    
    if (mmi_imc_send_message(&imc_msg))
    {
        /* get previous character but skip highlight and multitap. */
        imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE; 
        imc_msg.param_0 = 1;
        imc_msg.param_1 = (U32)string_buf;
        
        mmi_imc_send_message(&imc_msg);
	    
    }   
    else
    {
        imc_msg.message_id = MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR; 
        imc_msg.param_0 = (U32)&string_buf[0];
        
        mmi_imc_send_message(&imc_msg);
    }    

    previous_str[0] = string_buf[0];
    
    
    return is_thai_valid_input_int(Unicode, strlen, previous_str);

}
static MMI_BOOL is_thai_char_in_table(const UI_character_type default_multitap_thai_array[MAX_MULTITAPS][32], UI_character_type candidate)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/
	U32 i = 0, j = 0;
	/*----------------------------------------------------------------*/
	/* Code Body 													 */
	/*----------------------------------------------------------------*/    

	for(i = 0 ; i < MAX_MULTITAPS ; i++)
	{
		for(j = 0 ; j < 32 ; j++)
		{
			if(default_multitap_thai_array[i][j] == candidate)
				return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}

MMI_BOOL is_thai_valid_input_int(UI_string_type candidate, U8 strlen, UI_string_type previous_string)
{
	/*----------------------------------------------------------------*/
	   /* Local Variables												 */
	   /*----------------------------------------------------------------*/
	   UI_character_type prev_char = 0;
		UI_character_type curr_char = 0;
		/*----------------------------------------------------------------*/
	   /* Code Body 													 */
	   /*----------------------------------------------------------------*/    
	   /* get previous character but skip highlight and multitap. */
		curr_char = candidate[0];
	   prev_char = previous_string[0];

	   if (prev_char)
	   {
		   if ((prev_char >= THAI_C_KO_KAI) && (prev_char <= THAI_S_KHOMUT)) /* Thai character */
		   {
			   if (prev_char == THAI_FV_SARA_AA)
			   {
				   /* THAI_FV_SARA_A + THAI_FV_SARA_A is a special case for two following vowel combination. */
				    if(is_thai_char_in_table( default_multitap_thai_strings_sara_aa,curr_char))
						return MMI_TRUE;
			   } 
			   else  if (IsThaiToneMark(prev_char))
			   {
				   if(is_thai_char_in_table(default_multitap_thai_strings_tone,curr_char))
					   return MMI_TRUE;
			   }
			   else if (IsThaiConsonant(prev_char))
			   {
				   if(is_thai_char_in_table(default_multitap_thai_strings_con,curr_char))
					   return MMI_TRUE;

			   }
			   else if (IsThaiUpDownVowel(prev_char))
			   {
				   if(is_thai_char_in_table( default_multitap_thai_strings_vowel,curr_char))
					   return MMI_TRUE;
			   }
		   }
		   else
		   {
			   if(is_thai_char_in_table( default_multitap_thai_strings_normal,curr_char))
				   return MMI_TRUE;

		   }
	   }
	   else{
		   if(is_thai_char_in_table( default_multitap_thai_strings_normal,curr_char))
			   return MMI_TRUE;

	   }
	
	   if(is_thai_char_in_table( default_multitap_thai_strings_normal,curr_char))
		   return MMI_TRUE;

		return MMI_FALSE;

}

#if defined(__MMI_MULTITAP_THAI__)
/*****************************************************************************
 * FUNCTION
 *  get_thai_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_thai_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type prev_char = 0;
    mmi_imc_message_struct imc_msg;
    UI_character_type string_buf[10] = {0}; ///TODO: define an value for the string length
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* get previous character but skip highlight and multitap. */
    imc_msg.message_id = MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE;
    imc_msg.param_0 = 1;
    imc_msg.param_1 = (U32)string_buf;

    mmi_imc_send_message(&imc_msg);

    prev_char = string_buf[0];
    
    if (prev_char)
    {
        if ((prev_char >= THAI_C_KO_KAI) && (prev_char <= THAI_S_KHOMUT)) /* Thai character */
        {
            if (prev_char == THAI_FV_SARA_AA)
            {
                /* THAI_FV_SARA_A + THAI_FV_SARA_A is a special case for two following vowel combination. */
                return ((UI_character_type*) default_multitap_thai_strings_sara_aa[i]);
            } 
            else  if (IsThaiToneMark(prev_char))
            {
                return ((UI_character_type*) default_multitap_thai_strings_tone[i]);
            }
            else if (IsThaiConsonant(prev_char))
            {
                return ((UI_character_type*) default_multitap_thai_strings_con[i]);
            }
            else if (IsThaiUpDownVowel(prev_char))
            {
                return ((UI_character_type*) default_multitap_thai_strings_vowel[i]);
            }
        }
        else
        {
            return ((UI_character_type*) default_multitap_thai_strings_normal[i]);
        }
    }
    else{
        return ((UI_character_type*) default_multitap_thai_strings_normal[i]);
    }

    return ((UI_character_type*) default_multitap_thai_strings_normal[i]);
}
UI_character_type *get_thai_multitap_string_for_vk(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    		
    return ((UI_character_type*) default_multitap_thai_strings_con[i]);
}
#endif /* defined(__MMI_MULTITAP_THAI__) */
#endif /* defined(__MMI_LANG_THAI__) */

/*****************************************************************************
 * FUNCTION
 *  HaveThaiCharacter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL HaveThaiCharacter(U16 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ch = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        ch = str[0];
        if (ch == 0)
        {
            return MMI_FALSE;
        }
        if (ch >= THAI_C_KO_KAI && ch <= THAI_S_KHOMUT)
        {
            return MMI_TRUE;
        }
        str++;
    }


}

