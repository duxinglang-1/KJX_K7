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
*    Marathi.c
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   c file of marathi font rule 
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

#include "MMI_include.h"
#ifndef __MMI_MARATHI_H__
#define __MMI_MARATHI_H__

#if defined (__MMI_LANG_MARATHI__)

#include "IndicRuleEngineCommon.h"
#include "IndicEngineGprot.h"

#ifndef NULL
#define NULL	0
#endif

/* In editors, this array is used for language indication */

#if defined(__MMI_MULTITAP_MARATHI__) 
#if defined(__MMI_ZI_MARATHI__)

#if defined (__MMI_ZI_V7__)

const UI_character_type default_marathi_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1',MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO, '\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE, '\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN,'\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1', MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, MARATHI_S_HALANT, MARATHI_S_NUKTA, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_CHANDRA_BINDU, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO, MARATHI_DV_AA,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE, MARATHI_DV_I, '\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, MARATHI_DV_II, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, MARATHI_DV_U, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, MARATHI_DV_UU, MARATHI_DV_R, MARATHI_DV_CE, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN, MARATHI_DV_E, MARATHI_DV_AI, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, MARATHI_NDV_CO, MARATHI_DV_O, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, MARATHI_DV_AU, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0', MARATHI_D_ZERO, ' ', '\0'},   /* key 0 */
    {'1', MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_CHANDRA_BINDU, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE,'\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_marathimatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1',MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM,MARATHI_S_BINDU,MARATHI_S_VISARGA,'\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE,'\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA,MARATHI_IV_II, MARATHI_AC_ZA, '4',MARATHI_D_FOUR, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA,MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5',MARATHI_D_FIVE, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA,MARATHI_C_NA,MARATHI_C_PA, MARATHI_C_PHA,MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6',MARATHI_D_SIX, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA,MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7',MARATHI_D_SEVEN, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA,MARATHI_C_LLA,MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8',MARATHI_D_EIGHT, '\0'},   /* key 8 */
    { MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA,MARATHI_IV_AU,'9',MARATHI_D_NINE,'\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_marathimatra3_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1', MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, MARATHI_S_HALANT, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_CHANDRA_BINDU, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO, MARATHI_DV_AA,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE, MARATHI_DV_I, '\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, MARATHI_DV_II, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, MARATHI_DV_U, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, MARATHI_DV_UU, MARATHI_DV_R, MARATHI_DV_CE, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN, MARATHI_DV_E, MARATHI_DV_AI, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, MARATHI_NDV_CO, MARATHI_DV_O, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, MARATHI_DV_AU, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */
};

#else /* defined (__MMI_ZI_V7__) */

const UI_character_type default_marathi_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1',MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO, '\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE, '\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN,'\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1', MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, MARATHI_S_HALANT, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_CHANDRA_BINDU, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO, MARATHI_DV_AA,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE, MARATHI_DV_I, '\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, MARATHI_DV_II, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, MARATHI_DV_U, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, MARATHI_DV_UU, MARATHI_DV_R, MARATHI_DV_CE, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN, MARATHI_DV_E, MARATHI_DV_AI, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, MARATHI_NDV_CO, MARATHI_DV_O, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, MARATHI_DV_AU, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0', MARATHI_D_ZERO, ' ', '\0'},   /* key 0 */
    {'1', MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_CHANDRA_BINDU, '\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE,'\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_IV_II, MARATHI_AC_ZA, '4', MARATHI_D_FOUR, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5', MARATHI_D_FIVE, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_PA, MARATHI_C_PHA, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6', MARATHI_D_SIX, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7', MARATHI_D_SEVEN, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_NIV_CO, MARATHI_IV_O, MARATHI_C_RRA, '8', MARATHI_D_EIGHT, '\0'},   /* key 8 */
    {MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_IV_AU, '9', MARATHI_D_NINE, '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_marathimatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'0',MARATHI_D_ZERO,' ', '\0'},   /* key 0 */
    {'1',MARATHI_D_ONE, MARATHI_NG_D, MARATHI_S_OM,MARATHI_S_BINDU,MARATHI_S_VISARGA,'\0'},   /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, '2',MARATHI_D_TWO,'\0'},   /* key 2 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_IV_I, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '3', MARATHI_D_THREE,'\0'},   /* key 3 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_C_TTA, MARATHI_C_TTHA,MARATHI_IV_II, MARATHI_AC_ZA, '4',MARATHI_D_FOUR, '\0'},   /* key 4 */
    {MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA,MARATHI_C_TA, MARATHI_C_THA, MARATHI_IV_U, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '5',MARATHI_D_FIVE, '\0'},   /* key 5 */
    {MARATHI_C_DA, MARATHI_C_DHA,MARATHI_C_NA,MARATHI_C_PA, MARATHI_C_PHA,MARATHI_IV_UU, MARATHI_IV_R, MARATHI_C_NNNA, MARATHI_AC_FA, '6',MARATHI_D_SIX, '\0'},   /* key 6 */
    {MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_C_YA,MARATHI_IV_E, MARATHI_IV_AI, MARATHI_AC_YYA, '7',MARATHI_D_SEVEN, '\0'},   /* key 7 */
    {MARATHI_C_RA, MARATHI_C_LA,MARATHI_C_LLA,MARATHI_NIV_CO, MARATHI_IV_O,MARATHI_C_RRA, '8',MARATHI_D_EIGHT, '\0'},   /* key 8 */
    { MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA,MARATHI_IV_AU,'9',MARATHI_D_NINE,'\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined (__MMI_ZI_V7__) */
/* t9 portion */
#elif defined(__MMI_T9_MARATHI__)

const UI_character_type default_marathi_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},   /* key 0 */
    {'1', '\0'},        /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, '2', '\0'},        /* key 2 */
    {MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, '3', '\0'},        /* key 3 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '4', '\0'},        /* key 4 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, '5', '\0'},        /* key 5 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '6', '\0'},        /* key 6 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA,MARATHI_C_NA, MARATHI_C_NNNA, '7', '\0'}, /* key 7 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, '8', '\0'},        /* key 8 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_C_LLA, MARATHI_C_RRA, MARATHI_C_LLLA, MARATHI_AC_YYA, '9', '\0'},        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_marathimatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},                               /* key 0 */
    {MARATHI_S_CHANDRA_BINDU	 , MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_HALANT, '1', '\0'},    /* key 1 */
    {MARATHI_DV_AA, MARATHI_DV_I, MARATHI_DV_II, MARATHI_DV_U, MARATHI_DV_UU, MARATHI_DV_R, MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, '2', '\0'},        /* key 2 */
    {MARATHI_DV_E, MARATHI_DV_AI, MARATHI_DV_CE, MARATHI_DV_O, MARATHI_DV_AU, MARATHI_NDV_CO, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, '3', '\0'}, /* key 3 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '4', '\0'},        /* key 4 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, '5', '\0'},        /* key 5 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '6', '\0'},        /* key 6 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA,MARATHI_C_NA, MARATHI_C_NNNA, '7', '\0'}, /* key 7 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, '8', '\0'},        /* key 8 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_C_LLA, MARATHI_C_RRA, MARATHI_C_LLLA, MARATHI_AC_YYA, '9', '\0'},        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_marathimatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},                       /* key 0 */
    {MARATHI_S_CHANDRA_BINDU	 , MARATHI_S_BINDU, MARATHI_S_VISARGA, '1', '\0'},    /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, '2', '\0'},        /* key 2 */
    {MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, '3', '\0'},        /* key 3 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '4', '\0'},        /* key 4 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, '5', '\0'},        /* key 5 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '6', '\0'},        /* key 6 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA,MARATHI_C_NA, MARATHI_C_NNNA, '7', '\0'}, /* key 7 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, '8', '\0'},        /* key 8 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA,
     MARATHI_C_LLA, MARATHI_C_RRA, MARATHI_C_LLLA, MARATHI_AC_YYA, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},               /* key 0 */
    {MARATHI_S_BINDU, MARATHI_S_VISARGA, '1', '\0'},    /* key 1 */
    {MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, '2', '\0'},        /* key 2 */
    {MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, '3', '\0'},        /* key 3 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, '4', '\0'},        /* key 4 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, '5', '\0'},        /* key 5 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, '6', '\0'},        /* key 6 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA,MARATHI_C_NA, MARATHI_C_NNNA, '7', '\0'}, /* key 7 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, '8', '\0'},        /* key 8 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_VA, MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_C_LLA, MARATHI_C_RRA, MARATHI_C_LLLA, MARATHI_AC_YYA, '9', '\0'},        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

#else 

const UI_character_type default_marathi_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '.', MARATHI_NG_D, MARATHI_S_OM, MARATHI_NG_DD, MARATHI_D_ZERO, '0', '\0'},               /* key 0 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, MARATHI_D_ONE, '1', '\0'},      /* key 1 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, MARATHI_D_TWO, '2', '\0'},  /* key 2 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, MARATHI_D_THREE, '3', '\0'}, /* key 3 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_NNNA, MARATHI_D_FOUR, '4', '\0'},    /* key 4 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, MARATHI_D_FIVE, '5', '\0'},     /* key 5 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_C_VA, MARATHI_C_LLLA, MARATHI_AC_YYA, MARATHI_C_RRA, MARATHI_D_SIX, '6', '\0'},  /* key 6 */
    {MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_D_SEVEN, '7', '\0'},                  /* key 7 */
    {MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, MARATHI_D_EIGHT, '8', '\0'}, /* key 8 */
    {MARATHI_D_NINE, '9', '\0'},                                            /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', MARATHI_S_HALANT, MARATHI_S_CHANDRA_BINDU, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_OM, MARATHI_NG_D, MARATHI_S_ABBR, MARATHI_NG_DD, '.', MARATHI_D_ZERO, '0', '\0'},    /* key 0 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, MARATHI_D_ONE, '1', '\0'},      /* key 1 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, MARATHI_D_TWO, '2', '\0'},  /* key 2 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, MARATHI_D_THREE, '3', '\0'}, /* key 3 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_NNNA, MARATHI_D_FOUR, '4', '\0'},    /* key 4 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, MARATHI_D_FIVE, '5', '\0'},     /* key 5 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_C_VA, MARATHI_C_LLLA, MARATHI_AC_YYA, MARATHI_C_RRA, MARATHI_D_SIX, '6', '\0'},  /* key 6 */
    {MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_D_SEVEN, '7', '\0'},                  /* key 7 */
    {MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, MARATHI_D_EIGHT, '8', '\0'}, /* key 8 */
    {MARATHI_DV_AA, MARATHI_DV_I, MARATHI_DV_II, MARATHI_DV_U, MARATHI_DV_UU, MARATHI_DV_R, MARATHI_DV_E, MARATHI_DV_AI, MARATHI_DV_CE, MARATHI_DV_O, MARATHI_DV_AU, MARATHI_NDV_CO, MARATHI_D_NINE, '9', '\0'},        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', MARATHI_S_CHANDRA_BINDU, MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_OM, MARATHI_NG_D, MARATHI_S_ABBR, MARATHI_NG_DD, '.', MARATHI_D_ZERO, '0', '\0'},      /* key 0 */
    {MARATHI_C_KA,  MARATHI_C_KHA,  MARATHI_C_GA,  MARATHI_C_GHA,  MARATHI_C_NGA, MARATHI_AC_QA,MARATHI_AC_KHHA, MARATHI_AC_GHHA, MARATHI_D_ONE, '1', '\0'},      /* key 1 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA,  MARATHI_C_JHA,  MARATHI_C_NYA, MARATHI_AC_ZA, MARATHI_D_TWO, '2', '\0'},  /* key 2 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, MARATHI_D_THREE, '3', '\0'}, /* key 3 */
    {MARATHI_C_TA,  MARATHI_C_THA,  MARATHI_C_DA,  MARATHI_C_DHA,  MARATHI_C_NA, MARATHI_C_NNNA, MARATHI_D_FOUR, '4', '\0'},    /* key 4 */
    {MARATHI_C_PA,  MARATHI_C_PHA,  MARATHI_C_BA,  MARATHI_C_BHA,  MARATHI_C_MA, MARATHI_AC_FA, MARATHI_D_FIVE, '5', '\0'},     /* key 5 */
    {MARATHI_C_YA,  MARATHI_C_RA,   MARATHI_C_LA,  MARATHI_C_LLA,  MARATHI_C_VA, MARATHI_C_LLLA, MARATHI_AC_YYA, MARATHI_C_RRA, MARATHI_D_SIX, '6', '\0'},  /* key 6 */
    {MARATHI_C_SHA, MARATHI_C_SSA,  MARATHI_C_SA,  MARATHI_C_HA, MARATHI_D_SEVEN, '7', '\0'},                  /* key 7 */
    {MARATHI_IV_A,  MARATHI_IV_AA,  MARATHI_IV_I,  MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, MARATHI_D_EIGHT, '8', '\0'}, /* key 8 */
    {MARATHI_D_NINE, '9', '\0'},                                            /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_marathimatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '.', MARATHI_S_BINDU, MARATHI_S_VISARGA, MARATHI_S_OM, MARATHI_NG_D, MARATHI_S_ABBR, MARATHI_NG_DD, MARATHI_D_ZERO, '0', '\0'},       /* key 0 */
    {MARATHI_C_KA, MARATHI_C_KHA, MARATHI_C_GA, MARATHI_C_GHA, MARATHI_C_NGA, MARATHI_AC_QA, MARATHI_AC_KHHA, MARATHI_AC_GHHA, MARATHI_D_ONE, '1', '\0'},      /* key 1 */
    {MARATHI_C_CHA, MARATHI_C_CHHA, MARATHI_C_JA, MARATHI_C_JHA, MARATHI_C_NYA, MARATHI_AC_ZA, MARATHI_D_TWO, '2', '\0'},  /* key 2 */
    {MARATHI_C_TTA, MARATHI_C_TTHA, MARATHI_C_DDA, MARATHI_C_DDHA, MARATHI_C_NNA, MARATHI_AC_DDDHA, MARATHI_AC_RHA, MARATHI_D_THREE, '3', '\0'}, /* key 3 */
    {MARATHI_C_TA, MARATHI_C_THA, MARATHI_C_DA, MARATHI_C_DHA, MARATHI_C_NA, MARATHI_C_NNNA, MARATHI_D_FOUR, '4', '\0'},    /* key 4 */
    {MARATHI_C_PA, MARATHI_C_PHA, MARATHI_C_BA, MARATHI_C_BHA, MARATHI_C_MA, MARATHI_AC_FA, MARATHI_D_FIVE, '5', '\0'},     /* key 5 */
    {MARATHI_C_YA, MARATHI_C_RA, MARATHI_C_LA, MARATHI_C_LLA, MARATHI_C_VA, MARATHI_C_LLLA, MARATHI_AC_YYA, MARATHI_C_RRA, MARATHI_D_SIX, '6', '\0'},  /* key 6 */
    {MARATHI_C_SHA, MARATHI_C_SSA, MARATHI_C_SA, MARATHI_C_HA, MARATHI_D_SEVEN, '7', '\0'},                  /* key 7 */
    {MARATHI_IV_A, MARATHI_IV_AA, MARATHI_IV_I, MARATHI_IV_II, MARATHI_IV_U, MARATHI_IV_UU, MARATHI_IV_R, MARATHI_IV_E, MARATHI_IV_AI, MARATHI_IV_O, MARATHI_IV_AU, MARATHI_NIV_CO, MARATHI_D_EIGHT, '8', '\0'}, /* key 8 */
    {MARATHI_D_NINE, '9', '\0'},                                            /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif 


/*****************************************************************************
 * FUNCTION
 *  get_marathi_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type get_marathi_multitap_string(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    UI_character_type previous_char = 0;
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
	
    previous_char = string_buf[0];

    if (previous_char)
    {
       if ((previous_char >= MARATHI_C_KA && previous_char <= MARATHI_C_HA) || 
           (previous_char >= MARATHI_AC_QA && previous_char <= MARATHI_AC_YYA))
       {
       #if defined (__MMI_ZI_V7__) && defined (__MMI_ZI_MARATHI__)
            switch(previous_char)
            {
                case MARATHI_C_KA:
                case MARATHI_C_KHA:
                case MARATHI_C_GA:
                case MARATHI_C_JA:
                case MARATHI_C_DDA:
                case MARATHI_C_DDHA:
                case MARATHI_C_NA:
                case MARATHI_C_PHA:
                case MARATHI_C_YA:
                case MARATHI_C_RA:
                case MARATHI_C_LLA:
                    return (UI_character_type*)default_marathimatra_multitap_strings[index];
                    break;
                default:
                    return (UI_character_type*)default_marathimatra3_multitap_strings[index];
            
            }
        #else /* defined (__MMI_ZI_V7__) && defined (__MMI_ZI_MARATHI__) */ 
                return (UI_character_type*)default_marathimatra_multitap_strings[index];
        #endif /* defined (__MMI_ZI_V7__) && defined (__MMI_ZI_MARATHI__) */
        }
        else
        {
            switch (previous_char)
            {
                case (MARATHI_DV_AA):
                case (MARATHI_DV_U):
                case (MARATHI_DV_UU):
                case (MARATHI_DV_R):
                case (MARATHI_IV_A):
                case (MARATHI_IV_AA):
                case (MARATHI_IV_I):
                case (MARATHI_IV_U):
                case (MARATHI_IV_UU):
                case (MARATHI_IV_R):
                case (MARATHI_IV_E):
                {
                    return (UI_character_type*)default_marathimatra1_multitap_strings[index];
                    break;
                }
                case (MARATHI_DV_I):
                case (MARATHI_DV_II):
                case (MARATHI_DV_CE):
                case (MARATHI_DV_E):
                case (MARATHI_DV_AI):
                case (MARATHI_NDV_CO):
                case (MARATHI_DV_O):
                case (MARATHI_DV_AU):
                case (MARATHI_IV_II):
                case (MARATHI_IV_AI):
                case (MARATHI_NIV_CO):
                case (MARATHI_IV_O):
                case (MARATHI_IV_AU):
                {
                    return (UI_character_type*)default_marathimatra2_multitap_strings[index];
                    break;
                }
                default:
                     return (UI_character_type*)default_marathi_multitap_strings[index];
            }
        }
       
    }
    else
    {
         return (UI_character_type*)default_marathi_multitap_strings[index];
}

}


/*****************************************************************************
 * FUNCTION
 *  get_marathi_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_marathi_single_line_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    UI_character_type previous_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
   
    if (previous_char)
    {
        if ((previous_char >= MARATHI_C_KA && previous_char <= MARATHI_C_HA) || 
           (previous_char >= MARATHI_AC_QA && previous_char <= MARATHI_AC_YYA))
        {
        #if defined (__MMI_ZI_V7__) && defined (__MMI_ZI_MARATHI__)
            switch(previous_char)
            {
                case MARATHI_C_KA:
                case MARATHI_C_KHA:
                case MARATHI_C_GA:
                case MARATHI_C_JA:
                case MARATHI_C_DDA:
                case MARATHI_C_DDHA:
                case MARATHI_C_NA:
                case MARATHI_C_PHA:
                case MARATHI_C_YA:
                case MARATHI_C_RA:
                case MARATHI_C_LLA:
                    return (UI_character_type*)default_marathimatra_multitap_strings[i];
                    break;
                default:
                    return (UI_character_type*)default_marathimatra3_multitap_strings[i];
            
            }
        #else /* defined (__MMI_ZI_V7__) && defined (__MMI_ZI_MARATHI__) */ 
                return (UI_character_type*)default_marathimatra_multitap_strings[i];
        #endif /* defined (__MMI_ZI_V7__) && defined (__MMI_ZI_MARATHI__) */ 
        }
        else
        {
            switch (previous_char)
            {
                case (MARATHI_DV_AA):
                case (MARATHI_DV_U):
                case (MARATHI_DV_UU):
                case (MARATHI_DV_R):
                case (MARATHI_IV_A):
                case (MARATHI_IV_AA):
                case (MARATHI_IV_I):
                case (MARATHI_IV_U):
                case (MARATHI_IV_UU):
                case (MARATHI_IV_R):
                case (MARATHI_IV_E):
                {
                    return ((UI_character_type*) default_marathimatra1_multitap_strings[i]);
                    break;
                }
                case (MARATHI_DV_I):
                case (MARATHI_DV_II):
                case (MARATHI_DV_CE):
                case (MARATHI_DV_E):
                case (MARATHI_DV_AI):
                case (MARATHI_NDV_CO):
                case (MARATHI_DV_O):
                case (MARATHI_DV_AU):
                case (MARATHI_IV_II):
                case (MARATHI_IV_AI):
                case (MARATHI_NIV_CO):
                case (MARATHI_IV_O):
                case (MARATHI_IV_AU):
                {
                    return ((UI_character_type*) default_marathimatra2_multitap_strings[i]);
                    break;
                }
                default:
                {
                    return ((UI_character_type*) default_marathi_multitap_strings[i]);
                }

            }
        }

    }
    else
    {
        return ((UI_character_type*) default_marathi_multitap_strings[i]);
    }

}
UI_character_type *get_marathi_multitap_string_for_vk(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    	
	return ((UI_character_type*) default_marathimatra_multitap_strings[i]);
}

#endif /* defined(__MMI_MULTITAP_MARATHI__)  */

#else/* defined (__MMI_LANG_MARATHI__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_marathi_warning_remove
 * DESCRIPTION
 *  for removing warnings
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_marathi_warning_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy function */
}
#endif /* defined (__MMI_LANG_MARATHI__) */
#endif /* __MMI_MARATHI_H__*/


