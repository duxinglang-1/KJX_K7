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
 * ArabicShapingEngine.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is implemenation for ArabicShapingEngine
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_include.h"


#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicShapingEngine.h"
#include "ArabicGProt.h"
#include "string.h"

#undef NULL
#define NULL 0

const ARABIC_SHAPE_TABLE glyph_base_Tb[] = 
{

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA */

    {N_HAMZA_FORM_B, N_HAMZA_FORM_B, N_HAMZA_FORM_B, N_HAMZA_FORM_B},

    /* MADDA_ON_ALEF */

    {N_MADDA_ON_ALEF_FORM_B, L_MADDA_ON_ALEF, R_MADDA_ON_ALEF, M_MADDA_ON_ALEF},

    /* HAMZA_ON_ALEF */

    {N_HAMZA_ON_ALEF_FORM_B, L_HAMZA_ON_ALEF, R_HAMZA_ON_ALEF, M_HAMZA_ON_ALEF},

    /* HAMZA_ON_WOW */

    {N_HAMZA_ON_WOW_FORM_B, L_HAMZA_ON_WOW, R_HAMZA_ON_WOW, M_HAMZA_ON_WOW},

    /* HAMZA_UNDER_ALEF */

    {N_HAMZA_UNDER_ALEF_FORM_B, L_HAMZA_UNDER_ALEF, R_HAMZA_UNDER_ALEF, M_HAMZA_UNDER_ALEF},

    /* HAMZA_ON_YEH */

    {N_HAMZA_ON_YEH_FORM_B, L_HAMZA_ON_YEH, R_HAMZA_ON_YEH, M_HAMZA_ON_YEH},

    /* ALEF */

    {N_ALEF_FORM_B, L_ALEF, R_ALEF, M_ALEF},

    /* BEH */

    {N_BEH_FORM_B, L_BEH, R_BEH, M_BEH},

    /* TEH_MARBUTA */

    {N_TEH_MARBUTA_FORM_B, L_TEH_MARBUTA, R_TEH_MARBUTA, M_TEH_MARBUTA},

    /* TEH */

    {N_TEH_FORM_B, L_TEH, R_TEH, M_TEH},

    /* THEH */

    {N_THEH_FORM_B, L_THEH, R_THEH, M_THEH},

    /* JEEM */

    {N_JEEM_FORM_B, L_JEEM, R_JEEM, M_JEEM},

    /* HAH */

    {N_HAH_FORM_B, L_HAH, R_HAH, M_HAH},

    /* KHAH */

    {N_KHAH_FORM_B, L_KHAH, R_KHAH, M_KHAH},

    /* DAL */

    {N_DAL_FORM_B, L_DAL, R_DAL, M_DAL},

    /* THAL */

    {N_THAL_FORM_B, L_THAL, R_THAL, M_THAL},

    /* REH */

    {N_REH_FORM_B, L_REH, R_REH, M_REH},

    /* ZAIN */

    {N_ZAIN_FORM_B, L_ZAIN, R_ZAIN, M_ZAIN},

    /* SEEN */

    {N_SEEN_FORM_B, L_SEEN, R_SEEN, M_SEEN},

    /* SHEEN */

    {N_SHEEN_FORM_B, L_SHEEN, R_SHEEN, M_SHEEN},

    /* SAD */

    {N_SAD_FORM_B, L_SAD, R_SAD, M_SAD},

    /* DAD */

    {N_DAD_FORM_B, L_DAD, R_DAD, M_DAD},

    /* TAH */

    {N_TAH_FORM_B, L_TAH, R_TAH, M_TAH},

    /* ZAH */

    {N_ZAH_FORM_B, L_ZAH, R_ZAH, M_ZAH},

    /* AIN */

    {N_AIN_FORM_B, L_AIN, R_AIN, M_AIN},

    /* GHAIN */

    {N_GHAIN_FORM_B, L_GHAIN, R_GHAIN, M_GHAIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TATWEEL */

    {N_TATWEEL, N_TATWEEL, N_TATWEEL, N_TATWEEL},

    /* FEH */

    {N_FEH_FORM_B, L_FEH, R_FEH, M_FEH},

    /* QAF */

    {N_QAF_FORM_B, L_QAF, R_QAF, M_QAF},

    /* KAF */

    {N_KAF_FORM_B, L_KAF, R_KAF, M_KAF},

    /* LAM */

    {N_LAM_FORM_B, L_LAM, R_LAM, M_LAM},

    /* MEEM */

    {N_MEEM_FORM_B, L_MEEM, R_MEEM, M_MEEM},

    /* NOON */

    {N_NOON_FORM_B, L_NOON, R_NOON, M_NOON},

    /* HEH */

    {N_HEH_FORM_B, L_HEH, R_HEH, M_HEH},

    /* WAW */

    {N_WAW_FORM_B, L_WAW, R_WAW, M_WAW},

    /* ALEF_MAKSURA */

    {N_ALEF_MAKSURA_FORM_B, L_ALEF_MAKSURA, R_ALEF_MAKSURA, M_ALEF_MAKSURA},

    /* YEH */

    {N_YEH_FORM_B, L_YEH, R_YEH, M_YEH},
    /* PMT START PERSIAN */

    /* 0x064b Arabic FATHATAN */

    {NULL, NULL, NULL, NULL},

    /* 0x064c Arabic DAMMATAN */

    {NULL, NULL, NULL, NULL},

    /* 0x064d Arabic KASRATAN */

    {NULL, NULL, NULL, NULL},

    /* 0x064e Arabic FATHA */

    {NULL, NULL, NULL, NULL},

    /* 0x064f Arabic DAMMA */

    {NULL, NULL, NULL, NULL},
    /* 0x0650 Arabic KASRA */

    {NULL, NULL, NULL, NULL},

    /* 0x0651 Arabic SHADDA */

    {NULL, NULL, NULL, NULL},

    /* 0x0652 Arabic SUKUN */

    {NULL, NULL, NULL, NULL},

    /* 0x0653 Arabic MADDAH ABOVE */

    {NULL, NULL, NULL, NULL},

    /* 0x0654 Arabic HAMZA ABOVE */

    {NULL, NULL, NULL, NULL},
    /* 0x0655 Arabic HAMZA BELOW */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_ARABIC_D_ZERO, N_ARABIC_D_ZERO, N_ARABIC_D_ZERO, N_ARABIC_D_ZERO},

    /* NULL */

    {N_ARABIC_D_ONE, N_ARABIC_D_ONE, N_ARABIC_D_ONE, N_ARABIC_D_ONE},

    /* NULL */

    {N_ARABIC_D_TWO, N_ARABIC_D_TWO, N_ARABIC_D_TWO, N_ARABIC_D_TWO},

    /* NULL */

    {N_ARABIC_D_THREE, N_ARABIC_D_THREE, N_ARABIC_D_THREE, N_ARABIC_D_THREE},
    /* NULL */

    {N_ARABIC_D_FOUR, N_ARABIC_D_FOUR, N_ARABIC_D_FOUR, N_ARABIC_D_FOUR},

    /* NULL */

    {N_ARABIC_D_FIVE, N_ARABIC_D_FIVE, N_ARABIC_D_FIVE, N_ARABIC_D_FIVE},

    /* NULL */

    {N_ARABIC_D_SIX, N_ARABIC_D_SIX, N_ARABIC_D_SIX, N_ARABIC_D_SIX},

    /* NULL */

    {N_ARABIC_D_SEVEN, N_ARABIC_D_SEVEN, N_ARABIC_D_SEVEN, N_ARABIC_D_SEVEN},

    /* NULL */

    {N_ARABIC_D_EIGHT, N_ARABIC_D_EIGHT, N_ARABIC_D_EIGHT, N_ARABIC_D_EIGHT},
    /* NULL */

    {N_ARABIC_D_NINE, N_ARABIC_D_NINE, N_ARABIC_D_NINE, N_ARABIC_D_NINE},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_TTEH, L_TTEH, R_TTEH, M_TTEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* PEH 0x067E */

    {N_PEH_FORM_A, L_PEH, R_PEH, M_PEH},

    /* 0x067F */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TCHEH 0x0686 */

    {N_TCHEH_FORM_A, L_TCHEH, R_TCHEH, M_TCHEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_DDAL_FORM_A, L_DDAL, R_DDAL, M_DDAL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL 0x0691 */

    {N_RREH_FORM_A, L_RREH, R_RREH, M_RREH},

    /* 0x0692 */

    {NULL, NULL, NULL, NULL},

    /* 0x0693 */

    {NULL, NULL, NULL, NULL},

    /* 0x0694 */

    {NULL, NULL, NULL, NULL},

    /* 0x0695 */

    {NULL, NULL, NULL, NULL},
    /* 0x0696 */

    {NULL, NULL, NULL, NULL},

    /* 0x0697 */

    {NULL, NULL, NULL, NULL},

    /* JEH 0x0698 */

    {N_JEH_FORM_A, L_JEH, R_JEH, M_JEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KHEHEH 0x06A9 */

    {N_KHEHEH_FORM_A, L_KHEHEH, R_KHEHEH, M_KHEHEH},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* GAF 0x06AF */
    {N_GAF_FORM_A, L_GAF, R_GAF, M_GAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {N_NOON_GHUNNA_FORM_A, L_NOON_GHUNNA, R_NOON_GHUNNA, M_NOON_GHUNNA},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL 0x06BE */

    {N_HEH_DOCHASHMEE_FORM_A, L_HEH_DOCHASHMEE, R_HEH_DOCHASHMEE, M_HEH_DOCHASHMEE},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL 0x06C1 */

    {N_HEH_GOAL_FORM_A, L_HEH_GOAL, R_HEH_GOAL, M_HEH_GOAL},

    /* HEH_GOAL_WITH_HAMZA_ABOVE 0x06C2 */

    {N_HEH_GOAL_WITH_HAMZA_ABOVE, N_HEH_GOAL_WITH_HAMZA_ABOVE, N_HEH_GOAL_WITH_HAMZA_ABOVE,
     N_HEH_GOAL_WITH_HAMZA_ABOVE},

    /* HEH_MARBUTA_GOAL 0x06C3 */

    {N_HEH_MARBUTA_GOAL, N_HEH_MARBUTA_GOAL, N_HEH_MARBUTA_GOAL, N_HEH_MARBUTA_GOAL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* FARSIYEH 0x06CC */

    {N_FARSIYEH_FORM_A, L_FARSIYEH, R_FARSIYEH, M_FARSIYEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* N_YEH_BARREE 0x06D2 */

    {N_YEH_BARREE_FORM_A, L_YEH_BARREE, R_YEH_BARREE, M_YEH_BARREE},

    /* YEH_BARREE_WITH_HAMZA_ABOVE 0x06D3 */

    {N_YEH_BARREE_WITH_HAMZA_ABOVE_FORM_A, L_YEH_BARREE_WITH_HAMZA_ABOVE, R_YEH_BARREE_WITH_HAMZA_ABOVE,
     M_YEH_BARREE_WITH_HAMZA_ABOVE},

     /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},
     /* NULL */

    {N_ARABIC_EXD_ZERO, N_ARABIC_EXD_ZERO, N_ARABIC_EXD_ZERO, N_ARABIC_EXD_ZERO},

    /* NULL */

    {N_ARABIC_EXD_ONE, N_ARABIC_EXD_ONE, N_ARABIC_EXD_ONE, N_ARABIC_EXD_ONE},

    /* NULL */

    {N_ARABIC_EXD_TWO, N_ARABIC_EXD_TWO, N_ARABIC_EXD_TWO, N_ARABIC_EXD_TWO},

    /* NULL */

    {N_ARABIC_EXD_THREE, N_ARABIC_EXD_THREE, N_ARABIC_EXD_THREE, N_ARABIC_EXD_THREE},
    /* NULL */

    {N_ARABIC_EXD_FOUR, N_ARABIC_EXD_FOUR, N_ARABIC_EXD_FOUR, N_ARABIC_EXD_FOUR},

    /* NULL */

    {N_ARABIC_EXD_FIVE, N_ARABIC_EXD_FIVE, N_ARABIC_EXD_FIVE, N_ARABIC_EXD_FIVE},

    /* NULL */

    {N_ARABIC_EXD_SIX, N_ARABIC_EXD_SIX, N_ARABIC_EXD_SIX, N_ARABIC_EXD_SIX},

    /* NULL */

    {N_ARABIC_EXD_SEVEN, N_ARABIC_EXD_SEVEN, N_ARABIC_EXD_SEVEN, N_ARABIC_EXD_SEVEN},

    /* NULL */

    {N_ARABIC_EXD_EIGHT, N_ARABIC_EXD_EIGHT, N_ARABIC_EXD_EIGHT, N_ARABIC_EXD_EIGHT},
    /* NULL */

    {N_ARABIC_EXD_NINE, N_ARABIC_EXD_NINE, N_ARABIC_EXD_NINE, N_ARABIC_EXD_NINE},

};

/* START PMTARABIC 20060904 */

const ARABIC_SHAPE_TABLE glyph_Tb_B[] = 
{
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA */

    {N_HAMZA_FORM_B, N_HAMZA_FORM_B, N_HAMZA_FORM_B, N_HAMZA_FORM_B},

    /* MADDA_ON_ALEF */

    {N_MADDA_ON_ALEF_FORM_B, L_MADDA_ON_ALEF, R_MADDA_ON_ALEF, M_MADDA_ON_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_ON_ALEF */

    {N_HAMZA_ON_ALEF_FORM_B, L_HAMZA_ON_ALEF, R_HAMZA_ON_ALEF, M_HAMZA_ON_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_ON_WOW */

    {N_HAMZA_ON_WOW_FORM_B, L_HAMZA_ON_WOW, R_HAMZA_ON_WOW, M_HAMZA_ON_WOW},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_UNDER_ALEF */

    {N_HAMZA_UNDER_ALEF_FORM_B, L_HAMZA_UNDER_ALEF, R_HAMZA_UNDER_ALEF, M_HAMZA_UNDER_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAMZA_ON_YEH */

    {N_HAMZA_ON_YEH_FORM_B, L_HAMZA_ON_YEH, R_HAMZA_ON_YEH, M_HAMZA_ON_YEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ALEF */

    {N_ALEF_FORM_B, L_ALEF, R_ALEF, M_ALEF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* BEH */

    {N_BEH_FORM_B, L_BEH, R_BEH, M_BEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TEH_MARBUTA */

    {N_TEH_MARBUTA_FORM_B, L_TEH_MARBUTA, R_TEH_MARBUTA, M_TEH_MARBUTA},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TEH */

    {N_TEH_FORM_B, L_TEH, R_TEH, M_TEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* THEH */

    {N_THEH_FORM_B, L_THEH, R_THEH, M_THEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* JEEM */

    {N_JEEM_FORM_B, L_JEEM, R_JEEM, M_JEEM},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HAH */

    {N_HAH_FORM_B, L_HAH, R_HAH, M_HAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KHAH */

    {N_KHAH_FORM_B, L_KHAH, R_KHAH, M_KHAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* DAL */

    {N_DAL_FORM_B, L_DAL, R_DAL, M_DAL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* THAL */

    {N_THAL_FORM_B, L_THAL, R_THAL, M_THAL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* REH */

    {N_REH_FORM_B, L_REH, R_REH, M_REH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ZAIN */

    {N_ZAIN_FORM_B, L_ZAIN, R_ZAIN, M_ZAIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* SEEN */

    {N_SEEN_FORM_B, L_SEEN, R_SEEN, M_SEEN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* SHEEN */

    {N_SHEEN_FORM_B, L_SHEEN, R_SHEEN, M_SHEEN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* SAD */

    {N_SAD_FORM_B, L_SAD, R_SAD, M_SAD},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* DAD */

    {N_DAD_FORM_B, L_DAD, R_DAD, M_DAD},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TAH */

    {N_TAH_FORM_B, L_TAH, R_TAH, M_TAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ZAH */

    {N_ZAH_FORM_B, L_ZAH, R_ZAH, M_ZAH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* AIN */

    {N_AIN_FORM_B, L_AIN, R_AIN, M_AIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* GHAIN */

    {N_GHAIN_FORM_B, L_GHAIN, R_GHAIN, M_GHAIN},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},    

    /* FEH */

    {N_FEH_FORM_B, L_FEH, R_FEH, M_FEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* QAF */

    {N_QAF_FORM_B, L_QAF, R_QAF, M_QAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KAF */

    {N_KAF_FORM_B, L_KAF, R_KAF, M_KAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* LAM */

    {N_LAM_FORM_B, L_LAM, R_LAM, M_LAM},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* MEEM */

    {N_MEEM_FORM_B, L_MEEM, R_MEEM, M_MEEM},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NOON */

    {N_NOON_FORM_B, L_NOON, R_NOON, M_NOON},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* HEH */

    {N_HEH_FORM_B, L_HEH, R_HEH, M_HEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* WAW */

    {N_WAW_FORM_B, L_WAW, R_WAW, M_WAW},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* ALEF_MAKSURA */

    {N_ALEF_MAKSURA_FORM_B, L_ALEF_MAKSURA, R_ALEF_MAKSURA, M_ALEF_MAKSURA},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* YEH */

    {N_YEH_FORM_B, L_YEH, R_YEH, M_YEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
};

/* PMT END URDU */

//PMT START URDU 
const ARABIC_SHAPE_TABLE glyph_Tb_A[] = 
{
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* PEH */

    {N_PEH_FORM_A, L_PEH, R_PEH, M_PEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_TTEH_FORM_A, L_TTEH, R_TTEH, M_TTEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* TCHEH */

    {N_TCHEH_FORM_A, L_TCHEH, R_TCHEH, M_TCHEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_DDAL_FORM_A, L_DDAL, R_DDAL, M_DDAL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* JEH */

    {N_JEH_FORM_A, L_JEH, R_JEH, M_JEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_RREH_FORM_A, L_RREH, R_RREH, M_RREH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* KHEHEH */

    {N_KHEHEH_FORM_A, L_KHEHEH, R_KHEHEH, M_KHEHEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* GAF */

    {N_GAF_FORM_A, L_GAF, R_GAF, M_GAF},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_NOON_GHUNNA_FORM_A, L_NOON_GHUNNA, R_NOON_GHUNNA, M_NOON_GHUNNA},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_HEH_GOAL_FORM_A, L_HEH_GOAL, R_HEH_GOAL, M_HEH_GOAL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_HEH_DOCHASHMEE_FORM_A, L_HEH_DOCHASHMEE, R_HEH_DOCHASHMEE, M_HEH_DOCHASHMEE},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_YEH_BARREE_FORM_A, L_YEH_BARREE, R_YEH_BARREE, M_YEH_BARREE},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {N_YEH_BARREE_WITH_HAMZA_ABOVE_FORM_A, L_YEH_BARREE_WITH_HAMZA_ABOVE, R_YEH_BARREE_WITH_HAMZA_ABOVE,
     M_YEH_BARREE_WITH_HAMZA_ABOVE},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* FARSIYEH */

    {N_FARSIYEH_FORM_A, L_FARSIYEH, R_FARSIYEH, M_FARSIYEH},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},
    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL},

    /* NULL */

    {NULL, NULL, NULL, NULL}

};

//PMT END URDU
//PMT PERSIAN END - Ailsa
//PMT START URDU 
const LIGATURE_INFO_TABLE L_LAM_Tbl[] = 
{
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN_URDU, {L_LAM, R_ALEF, 0x0}, {N_LAMALEF, 0x0}},
#endif 

#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN, {L_LAM, R_HAMZA_ON_ALEF, 0x0}, {N_HAMZA_ON_LAMALEF, 0x0}},
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN, {L_LAM, R_HAMZA_UNDER_ALEF, 0x0}, {N_HAMZA_UNDER_LAMALEF, 0x0}},
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN, {L_LAM, R_MADDA_ON_ALEF, 0x0}, {N_MADDA_ON_LAMALEF, 0x0}},
#endif /* defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, R_JEEM, 0x0}, {N_LAM_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, R_MEEM, 0x0}, {N_LAM_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, R_KHAH, 0x0}, {N_LAM_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, M_JEEM, 0x0}, {L_LAM_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, M_HAH, 0x0}, {L_LAM_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, M_KHAH, 0x0}, {L_LAM_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_LAM, M_MEEM, 0x0}, {L_LAM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_LAM, R_HAH, 0x0}, {N_LAM_WITH_HAH, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_LAM, M_HEH, 0x0}, {L_LAM_WITH_HEH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_LAM, M_KHAH, M_MEEM, 0x0}, {L_LAM_WITH_KHAH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};

const LIGATURE_INFO_TABLE M_LAM_Tbl[] = 
{
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN_URDU, {M_LAM, R_ALEF, 0x0}, {R_LAMALEF, 0x0}},
#endif 
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN, {M_LAM, R_HAMZA_ON_ALEF, 0x0}, {R_HAMZA_ON_LAMALEF, 0x0}},
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN, {M_LAM, R_HAMZA_UNDER_ALEF, 0x0}, {R_HAMZA_UNDER_LAMALEF, 0x0}},
    {2, 1, ARABIC_LIGATURE_ARABIC_PERSIAN, {M_LAM, R_MADDA_ON_ALEF, 0x0}, {R_MADDA_ON_LAMALEF, 0x0}},
#endif /* defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_LAM, R_MEEM, 0x0}, {R_LAM_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_LAM, M_MEEM, 0x0}, {M_LAM_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_LAM, M_JEEM, R_MEEM, 0x0}, {R_LAM_WITH_JEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {3, 1, ARABIC_LIGATURE_PERSIAN, {M_LAM, M_KHAH, R_MEEM, 0x0}, {R_LAM_WITH_KHAH_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_HAMZA_ON_YEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_HAMZA_ON_YEH, R_MEEM, 0x0}, {N_HAMZA_ON_YEH_WITH_MEEM, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_HAMZA_ON_YEH, R_ALEF, 0x0}, {N_HAMZA_ON_YEH_WITH_ALEF, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_HAMZA_ON_YEH, R_WAW, 0x0}, {N_HAMZA_ON_YEH_WITH_WAW, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_HAMZA_ON_YEH, R_JEEM, 0x0}, {N_HAMZA_ON_YEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_HAMZA_ON_YEH, R_HAH, 0x0}, {N_HAMZA_ON_YEH_WITH_HAH, 0x0}},
#endif /* defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) ||  defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_HAMZA_ON_YEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_HAMZA_ON_YEH, R_ALEF, 0x0}, {R_HAMZA_ON_YEH_WITH_ALEF, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_HAMZA_ON_YEH, R_WAW, 0x0}, {R_HAMZA_ON_YEH_WITH_WAW, 0x0}},
/* START PMT PATCH04052007 */
#endif /*__MMI_LANG_PERSIAN__*/
#if defined(__MMI_LANG_PERSIAN__) ||  defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_HAMZA_ON_YEH, R_MEEM, 0x0}, {R_HAMZA_ON_YEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_HAMZA_ON_YEH, R_NOON, 0x0}, {R_HAMZA_ON_YEH_WITH_NOON, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) ||  defined(__MMI_LANG_URDU__) */ 
/* END PMT PATCH04052007 */
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {M_HAMZA_ON_YEH, R_REH, 0x0}, {R_HAMZA_ON_YEH_WITH_REH, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {M_HAMZA_ON_YEH, R_ZAIN, 0x0}, {R_HAMZA_ON_YEH_WITH_ZAIN, 0x0}},
#endif /* defined(__MMI_LANG_URDU__) */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_BEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_BEH, R_MEEM, 0x0}, {N_BEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_BEH, M_JEEM, 0x0}, {L_BEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_BEH, M_HAH, 0x0}, {L_BEH_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_BEH, M_KHAH, 0x0}, {L_BEH_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_BEH, M_MEEM, 0x0}, {L_BEH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_BEH, R_JEEM, 0x0}, {N_BEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_BEH, R_HAH, 0x0}, {N_BEH_WITH_HAH, 0x0}},
#endif /* defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_BEH, M_HEH, 0x0}, {L_BEH_WITH_HEH, 0x0}},
#endif /*__MMI_LANG_PERSIAN__*/
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_BEH, R_KHAH, 0x0}, {N_BEH_WITH_KHAH, 0x0}},
#endif /*defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)*/ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_BEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_BEH, R_REH, 0x0}, {R_BEH_WITH_REH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_BEH, R_ZAIN, 0x0}, {R_BEH_WITH_ZAIN, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_BEH, R_MEEM, 0x0}, {R_BEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_BEH, R_NOON, 0x0}, {R_BEH_WITH_NOON, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_BEH, M_MEEM, 0x0}, {M_BEH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_BEH, M_HEH, 0x0}, {M_BEH_WITH_HEH, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#endif
/*
const LIGATURE_INFO_TABLE L_ALEF_Tbl[] = 
{{0},
#if defined(__MMI_LANG_PERSIAN__)
    {4, 1, ARABIC_LIGATURE_PERSIAN, {L_ALEF, L_LAM, M_LAM, R_HEH, 0x0}, {N_ALEF_WITH_LAM_WITH_LAM_WITH_HEH, 0x0}},
#endif 
#if 0
    {4, 1, ARABIC_LIGATURE_NONE, {L_ALEF, M_KAF, M_BEH, R_REH, 0x0}, {N_ALEF_WITH_KAF_WITH_BEH_WITH_REH  , 0x0}}
#endif 

};
*/
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_REH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__)
    {4, 1, ARABIC_LIGATURE_PERSIAN, {L_REH, L_SEEN, R_WAW, R_LAM, 0x0}, {N_REH_WITH_SEEN_WITH_WAW_WITH_LAM, 0x0}},
#endif 
#if defined(__MMI_LANG_URDU__)
    {4, 1, ARABIC_LIGATURE_URDU, {L_REH, L_SEEN, R_WAW, N_LAM_FORM_B, 0x0}, {N_REH_WITH_SEEN_WITH_WAW_WITH_LAM, 0x0}},
    {4, 1, ARABIC_LIGATURE_URDU, {L_REH, L_FARSIYEH, R_ALEF, N_LAM_FORM_B, 0x0},
     {N_REH_WITH_FARSIYEH_WITH_ALEF_WITH_LAM, 0x0}}
#endif /* defined(__MMI_LANG_URDU__) */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_TEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_TEH, M_HEH, 0x0}, {L_TEH_WITH_HEH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_TEH, M_JEEM, M_MEEM, 0x0}, {L_TEH_WITH_JEEM_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_TEH, M_HAH, M_JEEM, 0x0}, {L_TEH_WITH_HAH_WITH_JEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_TEH, M_HAH, M_MEEM, 0x0}, {L_TEH_WITH_HAH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, M_JEEM, 0x0}, {L_TEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, R_MEEM, 0x0}, {N_TEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, M_HAH, 0x0}, {L_TEH_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, M_KHAH, 0x0}, {L_TEH_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, M_MEEM, 0x0}, {L_TEH_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, M_KHAH, M_MEEM, 0x0}, {L_TEH_WITH_KHAH_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TEH, M_MEEM, M_JEEM, 0x0}, {L_TEH_WITH_MEEM_WITH_JEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_TEH, R_JEEM, 0x0}, {N_TEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_TEH, R_HAH, 0x0}, {N_TEH_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_TEH, R_KHAH, 0x0}, {N_TEH_WITH_KHAH, 0x0}},
    {3, 1, ARABIC_LIGATURE_URDU, {L_TEH, M_MEEM, M_HAH, 0x0}, {L_TEH_WITH_MEEM_WITH_HAH, 0x0}},
#endif /* defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_TEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_TEH, R_REH, 0x0}, {R_TEH_WITH_REH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_TEH, M_MEEM, 0x0}, {M_TEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_TEH, R_MEEM, 0x0}, {R_TEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_TEH, R_NOON, 0x0}, {R_TEH_WITH_NOON, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_TEH, R_ZAIN, 0x0}, {R_TEH_WITH_ZAIN, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_TEH, M_MEEM, 0x0}, {M_TEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_TEH, M_HEH, 0x0}, {M_TEH_WITH_HEH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_THEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_THEH, M_MEEM, 0x0}, {L_THEH_WITH_MEEM, 0x0}},
#endif 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_THEH, R_MEEM, 0x0}, {N_THEH_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_THEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_THEH, R_REH, 0x0}, {R_THEH_WITH_REH, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_THEH, R_MEEM, 0x0}, {R_THEH_WITH_MEEM, 0x0}},
#endif 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {M_THEH, M_MEEM, 0x0}, {M_THEH_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_JEEM_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_JEEM, R_MEEM, 0x0}, {N_JEEM_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_JEEM, M_MEEM, 0x0}, {L_JEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_JEEM, R_HAH, 0x0}, {N_JEEM_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_JEEM, M_HAH, 0x0}, {L_JEEM_WITH_HAH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#endif
#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#endif 
#if defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_HAH_Tbl[] = 
{
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_HAH, R_JEEM, 0x0}, {N_HAH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_HAH, R_MEEM, 0x0}, {N_HAH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_HAH, M_JEEM, 0x0}, {L_HAH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_HAH, M_MEEM, 0x0}, {L_HAH_WITH_MEEM, 0x0}}
#endif /* defined(__MMI_LANG_URDU__) */ 
};
#endif
#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif /* 0 */ 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_KHAH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_KHAH, R_MEEM, 0x0}, {N_KHAH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_KHAH, M_JEEM, 0x0}, {L_KHAH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_KHAH, M_MEEM, 0x0}, {L_KHAH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_SEEN_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, R_KHAH, 0x0}, {N_SEEN_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, R_MEEM, 0x0}, {N_SEEN_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, M_JEEM, 0x0}, {L_SEEN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, M_HAH, 0x0}, {L_SEEN_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, M_KHAH, 0x0}, {L_SEEN_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, M_MEEM, 0x0}, {L_SEEN_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, R_REH, 0x0}, {N_SEEN_WITH_REH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SEEN, M_MEEM, M_JEEM, 0x0}, {L_SEEN_WITH_MEEM_WITH_JEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_SEEN, M_HEH, 0x0}, {L_SEEN_WITH_HEH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_SEEN, M_MEEM, M_MEEM, 0x0}, {L_SEEN_WITH_MEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_SEEN, R_JEEM, 0x0}, {N_SEEN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_SEEN, R_HAH, 0x0}, {N_SEEN_WITH_HAH, 0x0}},
#endif /* defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_SEEN_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SEEN, M_JEEM, 0x0}, {M_SEEN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SEEN, M_HAH, 0x0}, {M_SEEN_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SEEN, M_KHAH, 0x0}, {M_SEEN_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SEEN, R_REH, 0x0}, {R_SEEN_WITH_REH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {M_SEEN, M_MEEM, 0x0}, {M_SEEN_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_SHEEN_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SHEEN, R_HAH, 0x0}, {N_SHEEN_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SHEEN, R_REH, 0x0}, {N_SHEEN_WITH_REH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SHEEN, M_JEEM, 0x0}, {L_SHEEN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SHEEN, M_HAH, 0x0}, {L_SHEEN_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SHEEN, M_KHAH, 0x0}, {L_SHEEN_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SHEEN, M_MEEM, 0x0}, {L_SHEEN_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_SHEEN, R_MEEM, 0x0}, {N_SHEEN_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_SHEEN, M_HEH, 0x0}, {L_SHEEN_WITH_HEH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_SHEEN, M_MEEM, M_KHAH, 0x0}, {L_SHEEN_WITH_MEEM_WITH_KHAH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_SHEEN, R_KHAH, 0x0}, {N_SHEEN_WITH_KHAH, 0x0}}
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_SHEEN_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SHEEN, M_MEEM, 0x0}, {M_SHEEN_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SHEEN, R_MEEM, 0x0}, {R_SHEEN_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SHEEN, R_REH, 0x0}, {R_SHEEN_WITH_REH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SHEEN, M_JEEM, 0x0}, {M_SHEEN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SHEEN, M_KHAH, 0x0}, {M_SHEEN_WITH_KHAH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_SHEEN, M_HEH, 0x0}, {M_SHEEN_WITH_HEH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {M_SHEEN, M_MEEM, R_MEEM, 0x0}, {R_SHEEN_WITH_MEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_SAD_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SAD, R_HAH, 0x0}, {N_SAD_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SAD, R_MEEM, 0x0}, {N_SAD_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SAD, M_HAH, 0x0}, {L_SAD_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SAD, M_MEEM, 0x0}, {L_SAD_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_SAD, R_REH, 0x0}, {N_SAD_WITH_REH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_SAD, M_KHAH, 0x0}, {L_SAD_WITH_KHAH, 0x0}},
#endif 
#if defined(__MMI_LANG_URDU__)
    {3, 1, ARABIC_LIGATURE_URDU, {L_SAD, M_LAM, R_YEH_BARREE, 0x0}, {N_SAD_WITH_LAM_WITH_YEH_BARREE, 0x0}},
    {4, 1, ARABIC_LIGATURE_URDU, {L_SAD, M_LAM, M_AIN, R_MEEM, 0x0}, {N_SAD_WITH_LAM_WITH_AIN_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_SAD_Tbl[] = 
{
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {M_SAD, R_REH, 0x0}, {R_SAD_WITH_REH, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__)
    {3, 1, ARABIC_LIGATURE_PERSIAN, {M_SAD, M_HAH, R_HAH, 0x0}, {R_SAD_WITH_HAH_WITH_HAH, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_SAD, M_MEEM, R_MEEM, 0x0}, {R_SAD_WITH_MEEM_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_DAD_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_DAD, R_MEEM, 0x0}, {N_DAD_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_DAD, M_MEEM, 0x0}, {L_DAD_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_DAD, R_REH, 0x0}, {N_DAD_WITH_REH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_DAD, M_JEEM, 0x0}, {L_DAD_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_DAD, M_HAH, 0x0}, {L_DAD_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_DAD, M_KHAH, 0x0}, {L_DAD_WITH_KHAH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_DAD_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_DAD, R_REH, 0x0}, {R_DAD_WITH_REH, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_TAH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TAH, R_MEEM, 0x0}, {N_TAH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_TAH, M_MEEM, 0x0}, {L_TAH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_TAH, M_HAH, 0x0}, {L_TAH_WITH_HAH, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_TAH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_TAH, M_MEEM, 0x0}, {M_TAH_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_WAW_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {4, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_WAW, L_SEEN, M_LAM, R_MEEM, 0x0}, {N_WAW_WITH_SEEN_WITH_LAM_WITH_MEEM, 0x0}}
#endif 
};
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_ZAH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_ZAH, R_MEEM, 0x0}, {N_ZAH_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
#endif /* 0 */ 
};
#endif
/*
const LIGATURE_INFO_TABLE M_ZAH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_ZAH, M_MEEM, 0x0}, {M_ZAH_WITH_MEEM, 0x0}}
#endif 
};
*/
const LIGATURE_INFO_TABLE L_GHAIN_Tbl[] = 
{{0},
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_GHAIN, R_MEEM, 0x0}, {N_GHAIN_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_GHAIN, M_MEEM, 0x0}, {L_GHAIN_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

};
/*
const LIGATURE_INFO_TABLE M_GHAIN_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__)
    {3, 1, ARABIC_LIGATURE_PERSIAN, {M_GHAIN, M_MEEM, R_MEEM, 0x0}, {R_GHAIN_WITH_MEEM_WITH_MEEM, 0x0}},
#endif 
#if 0
    {3, 1, ARABIC_LIGATURE_PERSIAN, {M_GHAIN, M_MEEM, R_YEH, 0x0}, {R_GHAIN_WITH_MEEM_WITH_YEH, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {M_GHAIN, M_MEEM, R_ALEF_MAKSURA, 0x0}, {R_GHAIN_WITH_MEEM_WITH_ALEF_MAKSURA, 0x0}},
    {2, 1, ARABIC_LIGATURE_NONE, {M_GHAIN, R_ALEF_MAKSURA, 0x0}, {R_GHAIN_WITH_ALEF_MAKSURA, 0x0}},
    {2, 1, ARABIC_LIGATURE_NONE, {M_GHAIN, R_YEH, 0x0}, {R_GHAIN_WITH_YEH, 0x0}}
#endif

};
*/
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_AIN_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_AIN, R_JEEM, 0x0}, {N_AIN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_AIN, M_JEEM, 0x0}, {L_AIN_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_AIN, M_MEEM, 0x0}, {L_AIN_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_AIN, M_JEEM, M_MEEM, 0x0}, {L_AIN_WITH_JEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_AIN, R_MEEM, 0x0}, {N_AIN_WITH_MEEM, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__)
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_AIN, M_MEEM, M_MEEM, 0x0}, {L_AIN_WITH_MEEM_WITH_MEEM, 0x0}},
#endif 
#if 0
/* under construction !*/
#endif /* 0 */ 

};
#endif
#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif /* 0 */ 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_FEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_FEH, M_JEEM, 0x0}, {L_FEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_FEH, M_HAH, 0x0}, {L_FEH_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_FEH, M_KHAH, 0x0}, {L_FEH_WITH_KHAH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_FEH, R_MEEM, 0x0}, {N_FEH_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_FEH, M_MEEM, 0x0}, {L_FEH_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_FEH, R_KHAH, 0x0}, {N_FEH_WITH_KHAH, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif /* 0 */ 
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_QAF_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_QAF, R_MEEM, 0x0}, {N_QAF_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_QAF, M_HAH, 0x0}, {L_QAF_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_QAF, M_MEEM, 0x0}, {L_QAF_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif

#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_MEEM_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, R_MEEM, 0x0}, {N_MEEM_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_JEEM, 0x0}, {L_MEEM_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_HAH, 0x0}, {L_MEEM_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_KHAH, 0x0}, {L_MEEM_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_MEEM, 0x0}, {L_MEEM_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_HAH, M_MEEM, 0x0}, {L_MEEM_WITH_HAH_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_JEEM, M_MEEM, 0x0}, {L_MEEM_WITH_JEEM_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_KHAH, M_MEEM, 0x0}, {L_MEEM_WITH_KHAH_WITH_MEEM, 0x0}},
    {4, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_MEEM, M_HAH, M_MEEM, R_DAL, 0x0},
     {N_MEEM_WITH_HAH_WITH_MEEM_WITH_DAL, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
 #if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_MEEM, R_HAH, 0x0}, {N_MEEM_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_MEEM, R_JEEM, 0x0}, {N_MEEM_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_URDU, {L_MEEM, R_KHAH, 0x0}, {N_MEEM_WITH_KHAH, 0x0}},
 #endif /* defined(__MMI_LANG_URDU__) */ 
 #if defined(__MMI_LANG_PERSIAN__)
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_MEEM, M_HAH, M_JEEM, 0x0}, {L_MEEM_WITH_HAH_WITH_JEEM, 0x0}},
 #endif 
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif /* 0 */ 
};
#endif

#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_MEEM_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_MEEM, R_MEEM, 0x0}, {R_MEEM_WITH_MEEM, 0x0}},
#endif 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_MEEM, R_ALEF, 0x0}, {R_MEEM_WITH_ALEF, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE L_NOON_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, R_JEEM, 0x0}, {N_NOON_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, R_KHAH, 0x0}, {N_NOON_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, R_MEEM, 0x0}, {N_NOON_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, M_JEEM, 0x0}, {L_NOON_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, M_HAH, 0x0}, {L_NOON_WITH_HAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, M_KHAH, 0x0}, {L_NOON_WITH_KHAH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, M_MEEM, 0x0}, {L_NOON_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {L_NOON, M_JEEM, M_MEEM, 0x0}, {L_NOON_WITH_JEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_NOON, M_HEH, 0x0}, {L_NOON_WITH_HEH, 0x0}},
#endif 
#if defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_URDU, {L_NOON, R_HAH, 0x0}, {N_NOON_WITH_HAH, 0x0}},
#endif 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
const LIGATURE_INFO_TABLE M_NOON_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_NOON, R_ZAIN, 0x0}, {R_NOON_WITH_ZAIN, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_NOON, R_MEEM, 0x0}, {R_NOON_WITH_MEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_NOON, R_NOON, 0x0}, {R_NOON_WITH_NOON, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_NOON, M_MEEM, 0x0}, {M_NOON_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN_URDU, {M_NOON, M_JEEM, R_MEEM, 0x0}, {R_NOON_WITH_JEEM_WITH_MEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__) */ 
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_NOON, R_REH, 0x0}, {R_NOON_WITH_REH, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {M_NOON, M_HEH, 0x0}, {M_NOON_WITH_HEH, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif
#if defined(__MMI_LANG_PERSIAN__)
const LIGATURE_INFO_TABLE L_HEH_Tbl[] = 
{
#if defined(__MMI_LANG_PERSIAN__)
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_HEH, M_JEEM, 0x0}, {L_HEH_WITH_JEEM, 0x0}},
    {2, 1, ARABIC_LIGATURE_PERSIAN, {L_HEH, M_MEEM, 0x0}, {L_HEH_WITH_MEEM, 0x0}},
    {3, 1, ARABIC_LIGATURE_PERSIAN, {L_HEH, M_MEEM, M_JEEM, 0x0}, {L_HEH_WITH_MEEM_WITH_JEEM, 0x0}},
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
};
#endif /* defined(__MMI_LANG_PERSIAN__) */ 
#if 0
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif /* 0 */
#if 0 
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* under construction !*/
#endif /* 0 */

const ARABIC_MAIN_TABLE Arabic_base_Tbl[] = 
{
    {NULL, 0, 0}    /* 0x0620 */
    ,
    {NULL, 0, 0}    /* 0x0621 */
    ,
    {NULL, 0, 0}    /* 0x0622 */
    ,
    {NULL, 0, 0}    /* 0x0623 */
    ,
    {NULL, 0, 0}    /* 0x0624 */
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
	
};

/* PMT START URDU */
const ARABIC_MAIN_TABLE Arabic_Tbl_B[] = 
{
    {NULL, 0, 0}    /* FE70 */
    ,
    {NULL, 0, 0}    /* FE71 */
    ,
    {NULL, 0, 0}    /* FE72 */
    ,
    {NULL, 0, 0}    /* FE73 */
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_HAMZA_ON_YEH_Tbl, sizeof(L_HAMZA_ON_YEH_Tbl) / sizeof(L_HAMZA_ON_YEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) ||  defined(__MMI_LANG_URDU__)
    {M_HAMZA_ON_YEH_Tbl, sizeof(M_HAMZA_ON_YEH_Tbl) / sizeof(M_HAMZA_ON_YEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},    
#endif
    {NULL, 0, 0}//{L_ALEF_Tbl, sizeof(L_ALEF_Tbl) / sizeof(L_ALEF_Tbl[0]), 4}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_BEH_Tbl, sizeof(L_BEH_Tbl) / sizeof(L_BEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_BEH_Tbl, sizeof(M_BEH_Tbl) / sizeof(M_BEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_TEH_Tbl, sizeof(L_TEH_Tbl) / sizeof(L_TEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_TEH_Tbl, sizeof(M_TEH_Tbl) / sizeof(M_TEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_THEH_Tbl, sizeof(L_THEH_Tbl) / sizeof(L_THEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_THEH_Tbl, sizeof(M_THEH_Tbl) / sizeof(M_THEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_JEEM_Tbl, sizeof(L_JEEM_Tbl) / sizeof(L_JEEM_Tbl[0]), 3},
#else
	{NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_JEEM_Tbl, sizeof(M_JEEM_Tbl) / sizeof(M_JEEM_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_URDU__)
    {L_HAH_Tbl, sizeof(L_HAH_Tbl) / sizeof(L_HAH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_HAH_Tbl, sizeof(M_HAH_Tbl) / sizeof(M_HAH_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_KHAH_Tbl, sizeof(L_KHAH_Tbl) / sizeof(L_KHAH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_KHAH_Tbl, sizeof(M_KHAH_Tbl) / sizeof(M_KHAH_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_REH_Tbl, sizeof(L_REH_Tbl) / sizeof(L_REH_Tbl[0]), 4},
#else
    {NULL, 0, 0},
#endif
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_SEEN_Tbl, sizeof(L_SEEN_Tbl) / sizeof(L_SEEN_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_SEEN_Tbl, sizeof(M_SEEN_Tbl) / sizeof(M_SEEN_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_SHEEN_Tbl, sizeof(L_SHEEN_Tbl) / sizeof(L_SHEEN_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_SHEEN_Tbl, sizeof(M_SHEEN_Tbl) / sizeof(M_SHEEN_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_SAD_Tbl, sizeof(L_SAD_Tbl) / sizeof(L_SAD_Tbl[0]), 4},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_SAD_Tbl, sizeof(M_SAD_Tbl) / sizeof(M_SAD_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_DAD_Tbl, sizeof(L_DAD_Tbl) / sizeof(L_DAD_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_DAD_Tbl, sizeof(M_DAD_Tbl) / sizeof(M_DAD_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_TAH_Tbl, sizeof(L_TAH_Tbl) / sizeof(L_TAH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_TAH_Tbl, sizeof(M_TAH_Tbl) / sizeof(M_TAH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_ZAH_Tbl, sizeof(L_ZAH_Tbl) / sizeof(L_ZAH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_ZAH_Tbl, sizeof(M_ZAH_Tbl) / sizeof(M_ZAH_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_AIN_Tbl, sizeof(L_AIN_Tbl) / sizeof(L_AIN_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_AIN_Tbl, sizeof(M_AIN_Tbl) / sizeof(M_AIN_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
    {L_GHAIN_Tbl, sizeof(L_GHAIN_Tbl) / sizeof(L_GHAIN_Tbl[0]), 3}
    ,
    {NULL, 0, 0}//{M_GHAIN_Tbl, sizeof(M_GHAIN_Tbl) / sizeof(M_GHAIN_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_FEH_Tbl, sizeof(L_FEH_Tbl) / sizeof(L_FEH_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_FEH_Tbl, sizeof(M_FEH_Tbl) / sizeof(M_FEH_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_QAF_Tbl, sizeof(L_QAF_Tbl) / sizeof(L_QAF_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}//{M_QAF_Tbl, sizeof(M_QAF_Tbl) / sizeof(M_QAF_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
    {NULL, 0, 0}//{L_KAF_Tbl, sizeof(L_KAF_Tbl) / sizeof(L_KAF_Tbl[0]), 3}
    ,
    {NULL, 0, 0}//{M_KAF_Tbl, sizeof(M_KAF_Tbl) / sizeof(M_KAF_Tbl[0]), 3}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,	
    {L_LAM_Tbl, sizeof(L_LAM_Tbl) / sizeof(L_LAM_Tbl[0]), 3}
    ,
    {M_LAM_Tbl, sizeof(M_LAM_Tbl) / sizeof(M_LAM_Tbl[0]), 3}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_MEEM_Tbl, sizeof(L_MEEM_Tbl) / sizeof(L_MEEM_Tbl[0]), 4},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_MEEM_Tbl, sizeof(M_MEEM_Tbl) / sizeof(M_MEEM_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_NOON_Tbl, sizeof(L_NOON_Tbl) / sizeof(L_NOON_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {M_NOON_Tbl, sizeof(M_NOON_Tbl) / sizeof(M_NOON_Tbl[0]), 3},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__)
    {L_HEH_Tbl, sizeof(L_HEH_Tbl) / sizeof(L_HEH_Tbl[0]), 3}
    ,
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
#if defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__)
    {L_WAW_Tbl, sizeof(L_WAW_Tbl) / sizeof(L_WAW_Tbl[0]), 4},
#else
    {NULL, 0, 0},
#endif
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}//{L_YEH_Tbl, sizeof(L_YEH_Tbl) / sizeof(L_YEH_Tbl[0]), 3}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    /* PMT END PERSIAN */
};

/* PMT END URDU */

/* PMT START PERSIAN */
/* PMT START URDU */
const ARABIC_MAIN_TABLE Arabic_Tbl_A[] = 
{
    {NULL, 0, 0}    /* 0xFB50 */
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}   
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
    {NULL, 0, 0}
    ,
	{NULL, 0, 0}
    ,
	{NULL, 0, 0}    
    ,
    {NULL, 0, 0}

};

const ARABIC_JOIN_TYPE_ENUM g_arabic_base_char_array[] = 
{
    ARABIC_NON_JOIN, //0x0620
    ARABIC_NON_JOIN,    /* 0x0621 hamza */
    ARABIC_RIGHT_JOIN, /* 0x0622 madda_on_alef */
    ARABIC_RIGHT_JOIN, /* 0x0623 hamza_on_alef */
    ARABIC_RIGHT_JOIN, /* 0x0624 hamza_on_waw */
    ARABIC_RIGHT_JOIN, /* 0x0625 hamza_under_alef */
    ARABIC_DUAL_JOIN,   /* 0x0626 hamza_on_yeh */
    ARABIC_RIGHT_JOIN, /* 0x0627 alef */
    ARABIC_DUAL_JOIN,   /* 0x0628 beh */
    ARABIC_RIGHT_JOIN, /* 0x0629 teh_marbuta */
    ARABIC_DUAL_JOIN,   /* 0x062A teh */
    ARABIC_DUAL_JOIN,   /* 0x062B theh */
    ARABIC_DUAL_JOIN,   /* 0x062C jeem */
    ARABIC_DUAL_JOIN,   /* 0x062D hah */
    ARABIC_DUAL_JOIN,   /* 0x062E khah */
    ARABIC_RIGHT_JOIN, /* 0x062F dal */
    ARABIC_RIGHT_JOIN, /* 0x0630 thal */
    ARABIC_RIGHT_JOIN, /* 0x0631 reh */
    ARABIC_RIGHT_JOIN, /* 0x0632 zain */
    ARABIC_DUAL_JOIN,   /* 0x0633 seen */
    ARABIC_DUAL_JOIN,   /* 0x0634 sheen */
    ARABIC_DUAL_JOIN,   /* 0x0635 sad */
    ARABIC_DUAL_JOIN,   /* 0x0636 dad */
    ARABIC_DUAL_JOIN,   /* 0x0637 tah */
    ARABIC_DUAL_JOIN,   /* 0x0638 zah */
    ARABIC_DUAL_JOIN,   /* 0x0639 ain */
    ARABIC_DUAL_JOIN,   /* 0x063A ghain */
    ARABIC_NON_JOIN,   /* 0x063B */
    ARABIC_NON_JOIN,   /* 0x063C */
    ARABIC_NON_JOIN,   /* 0x063D */
    ARABIC_NON_JOIN,   /* 0x063E */
    ARABIC_NON_JOIN,   /* 0x063F */
    ARABIC_JOIN_CAUSING,   /* 0x0640 */
    ARABIC_DUAL_JOIN,   /* 0x0641 feh */
    ARABIC_DUAL_JOIN,   /* 0x0642 qaf */
    ARABIC_DUAL_JOIN,   /* 0x0643 kaf */
    ARABIC_DUAL_JOIN,   /* 0x0644 lam */
    ARABIC_DUAL_JOIN,   /* 0x0645 meem */
    ARABIC_DUAL_JOIN,   /* 0x0646 noon */
    ARABIC_DUAL_JOIN,   /* 0x0647 heh */
    ARABIC_RIGHT_JOIN, /* 0x0648 waw */
    ARABIC_RIGHT_JOIN, /* 0x0649 alef_maksura */
    ARABIC_DUAL_JOIN,   /* 0x064A yeh */
    ARABIC_TRANSPARENT, /* 0x064B fathatan */
    ARABIC_TRANSPARENT, /* 0x064C dammatan */
    ARABIC_TRANSPARENT, /* 0x064D kasratan */
    ARABIC_TRANSPARENT, /* 0x064E fatha */
    ARABIC_TRANSPARENT, /* 0x064F damma */
    ARABIC_TRANSPARENT, /* 0x0650 karsa */
    ARABIC_TRANSPARENT, /* 0x0651 shadda */
    ARABIC_TRANSPARENT, /* 0x0652 sukun */
    ARABIC_TRANSPARENT, /* 0x0653 maddah above */
    ARABIC_TRANSPARENT, /* 0x0654 hamza above */
    ARABIC_TRANSPARENT, /* 0x0655 hamza below */
    ARABIC_NON_JOIN,   /* 0x0656 */
    ARABIC_NON_JOIN,   /* 0x0657 */
    ARABIC_NON_JOIN,   /* 0x0658 */
    ARABIC_NON_JOIN,   /* 0x0659 */
    ARABIC_NON_JOIN,   /* 0x065A */
    ARABIC_NON_JOIN,   /* 0x065B */
    ARABIC_NON_JOIN,   /* 0x065C */
    ARABIC_NON_JOIN,   /* 0x065D */
    ARABIC_NON_JOIN,   /* 0x065E */
    ARABIC_NON_JOIN,   /* 0x065F */
    ARABIC_NON_JOIN,   /* 0x0660 Arabic_Indic digit zero */
    ARABIC_NON_JOIN,   /* 0x0661 Arabic_Indic digit one */
    ARABIC_NON_JOIN,   /* 0x0662 Arabic_Indic digit two */
    ARABIC_NON_JOIN,   /* 0x0663 Arabic_Indic digit three */
    ARABIC_NON_JOIN,   /* 0x0664 Arabic_Indic digit four */
    ARABIC_NON_JOIN,   /* 0x0665 Arabic_Indic digit five */
    ARABIC_NON_JOIN,   /* 0x0666 Arabic_Indic digit six */
    ARABIC_NON_JOIN,   /* 0x0667 Arabic_Indic digit seven */
    ARABIC_NON_JOIN,   /* 0x0668 Arabic_Indic digit eight */
    ARABIC_NON_JOIN,   /* 0x0669 Arabic_Indic digit nine */
    ARABIC_NON_JOIN,   /* 0x066A punctuation - percent sign */
    ARABIC_NON_JOIN,   /* 0x066B punctuation - decimal separator */
    ARABIC_NON_JOIN,   /* 0x066C punctuation - thousands separator */
    ARABIC_NON_JOIN,   /* 0x066D punctuation - five pointed start */
    ARABIC_NON_JOIN,   /* 0x066E */
    ARABIC_NON_JOIN,   /* 0x066F */
    ARABIC_TRANSPARENT, /* 0x0670 superscript alef */
    ARABIC_NON_JOIN, /* 0x0671 alef wasla */
    ARABIC_NON_JOIN, /* 0x0672 alef with wavy hamza above */
    ARABIC_NON_JOIN, /* 0x0673 alef with wavy hamza below */
    ARABIC_NON_JOIN, /* 0x0674 high hamza */
    ARABIC_NON_JOIN, /* 0x0675 high hamza alef */
    ARABIC_NON_JOIN, /* 0x0676 high hamza waw */
    ARABIC_NON_JOIN, /* 0x0677 U with hamza above */
    ARABIC_NON_JOIN, /* 0x0678 hamza yeh */
    ARABIC_DUAL_JOIN, /* 0x0679 tteh */
    ARABIC_NON_JOIN, /* 0x067A tteheh */
    ARABIC_NON_JOIN, /* 0x067B beeh */
    ARABIC_NON_JOIN, /* 0x067C teh with ring */
    ARABIC_NON_JOIN, /* 0x067D teh with three dos above downwards */
    ARABIC_DUAL_JOIN, /* 0x067E peh */
    ARABIC_NON_JOIN, /* 0x067F thehe */
    ARABIC_NON_JOIN, /* 0x0680 beheh */
    ARABIC_NON_JOIN, /* 0x0681 hah with hamza above */
    ARABIC_NON_JOIN, /* 0x0682 hah with two dots vertical above */
    ARABIC_NON_JOIN, /* 0x0683 nyeh */
    ARABIC_NON_JOIN, /* 0x0684 dyeh */
    ARABIC_NON_JOIN, /* 0x0685 hah with three dots above */
    ARABIC_DUAL_JOIN, /* 0x0686 tcheh */
    ARABIC_NON_JOIN, /* 0x0687 tcheheh */
    ARABIC_RIGHT_JOIN, /* 0x0688 ddal */
    ARABIC_NON_JOIN, /* 0x0689 dal with ring */
    ARABIC_NON_JOIN, /* 0x068A dal with dot */
    ARABIC_NON_JOIN, /* 0x068B dal with dot below and small tah */
    ARABIC_NON_JOIN, /* 0x068C dahah */
    ARABIC_NON_JOIN, /* 0x068D ddahah */
    ARABIC_NON_JOIN, /* 0x068E dul */
    ARABIC_NON_JOIN, /* 0x068F dal with three dots above downwards */
    ARABIC_NON_JOIN, /* 0x0690 dal with four dots above */
    ARABIC_RIGHT_JOIN, /* 0x0691 rreh */
    ARABIC_NON_JOIN, /* 0x0692 reh with small v */
    ARABIC_NON_JOIN, /* 0x0693 reh with ring */
    ARABIC_NON_JOIN, /* 0x0694 reh with dot */
    ARABIC_NON_JOIN, /* 0x0695 reh with small v below */
    ARABIC_NON_JOIN, /* 0x0696 reh with dot below and dot above */
    ARABIC_NON_JOIN, /* 0x0697 reh with two dots above */
    ARABIC_RIGHT_JOIN, /* 0x0698 jeh */
    ARABIC_NON_JOIN, /* 0x0699 reh with four dots above */
    ARABIC_NON_JOIN, /* 0x069A seen with dot below and dot above */
    ARABIC_NON_JOIN, /* 0x069B seen with three dots below */
    ARABIC_NON_JOIN, /* 0x069C seen with three dots below and three dots above */
    ARABIC_NON_JOIN, /* 0x069D sad with two dots below */
    ARABIC_NON_JOIN, /* 0x069E sad with three dots above */
    ARABIC_NON_JOIN, /* 0x069F tah with three dots above */
    ARABIC_NON_JOIN, /* 0x06A0 ain with three dots above */
    ARABIC_NON_JOIN, /* 0x06A1 dotless feh */
    ARABIC_NON_JOIN, /* 0x06A2 feh with dot */
    ARABIC_NON_JOIN, /* 0x06A3 feh with dot below */
    ARABIC_NON_JOIN, /* 0x06A4 veh */
    ARABIC_NON_JOIN, /* 0x06A5 feh with three dots below */
    ARABIC_NON_JOIN, /* 0x06A6 peheh */
    ARABIC_NON_JOIN, /* 0x06A7 qaf with dot above */
    ARABIC_NON_JOIN, /* 0x06A8 qaf with three dots above */
    ARABIC_DUAL_JOIN, /* 0x06A9 keheh */
    ARABIC_NON_JOIN, /* 0x06AA swash kaf */
    ARABIC_NON_JOIN, /* 0x06AB kaf with ring */
    ARABIC_NON_JOIN, /* 0x06AC kaf with dot */
    ARABIC_NON_JOIN, /* 0x06AD ng */
    ARABIC_NON_JOIN, /* 0x06AE kaf with three dots below */
    ARABIC_DUAL_JOIN, /* 0x06AF gaf */
    ARABIC_NON_JOIN, /* 0x06B0 gaf with ring */
    ARABIC_NON_JOIN, /* 0x06B1 ngoeh */
    ARABIC_NON_JOIN, /* 0x06B2 gaf with two dots below */
    ARABIC_NON_JOIN, /* 0x06B3 gueh */
    ARABIC_NON_JOIN, /* 0x06B4 gaf with three dots above */
    ARABIC_NON_JOIN, /* 0x06B5 lam with small v */
    ARABIC_NON_JOIN, /* 0x06B6 lam with dot */
    ARABIC_NON_JOIN, /* 0x06B7 lam with three dots above */
    ARABIC_NON_JOIN, /* 0x06B8 lam with three dots below */
    ARABIC_NON_JOIN, /* 0x06B9 noon with dot */
    ARABIC_RIGHT_JOIN, /* 0x06BA noon ghunna */
    ARABIC_NON_JOIN, /* 0x06BB rnoon */
    ARABIC_NON_JOIN, /* 0x06BC noon with ring */
    ARABIC_NON_JOIN, /* 0x06BD noon with three dots above */
    ARABIC_DUAL_JOIN, /* 0x06BE heh doachashmee */
    ARABIC_NON_JOIN, /* 0x06BF tcheh with dot above */
    ARABIC_NON_JOIN, /* 0x06C0 heh with yeh above */
    ARABIC_DUAL_JOIN, /* 0x06C1 heh goal */
    ARABIC_NON_JOIN, /* 0x06C2 heh goal with hamza above */
    ARABIC_NON_JOIN, /* 0x06C3 teh marbuta goal */
    ARABIC_NON_JOIN, /* 0x06C4 waw with ring */
    ARABIC_NON_JOIN, /* 0x06C5 kirghiz oe */
    ARABIC_NON_JOIN, /* 0x06C6 oe */
    ARABIC_NON_JOIN, /* 0x06C7 u */
    ARABIC_NON_JOIN, /* 0x06C8 yu */
    ARABIC_NON_JOIN, /* 0x06C9 kirghiz yu */
    ARABIC_NON_JOIN, /* 0x06CA waw with two dots above */
    ARABIC_NON_JOIN, /* 0x06CB ve */
    ARABIC_DUAL_JOIN, /* 0x06CC farsi yeh */
    ARABIC_NON_JOIN, /* 0x06CD yeh with tail */
    ARABIC_NON_JOIN, /* 0x06CE teh with small v */
    ARABIC_NON_JOIN, /* 0x06CF waw with dot above */
    ARABIC_NON_JOIN, /* 0x06D0 e */
    ARABIC_NON_JOIN, /* 0x06D1 teh with three dots below */
    ARABIC_RIGHT_JOIN, /* 0x06D2 yeh barree */
    ARABIC_RIGHT_JOIN, /* 0x06D3 yeh barree with hamza above */
    ARABIC_NON_JOIN, /* 0x06D4 full stop */
    ARABIC_NON_JOIN, /* 0x06D5 ae */
    ARABIC_TRANSPARENT, /* 0x06D6 small high ligature sad with lam with alef maksura */
    ARABIC_TRANSPARENT, /* 0x06D7 small high ligature qaf with lam with alef maksura */
    ARABIC_TRANSPARENT, /* 0x06D8 small high meem initial form */
    ARABIC_TRANSPARENT, /* 0x06D9 small high lam alef */
    ARABIC_TRANSPARENT, /* 0x06DA high jeem */
    ARABIC_TRANSPARENT, /* 0x06DB high three dots */
    ARABIC_TRANSPARENT, /* 0x06DC small high seen */
    ARABIC_NON_JOIN, /* 0x06DD end of ayah */
    ARABIC_NON_JOIN, /* 0x06DE start of rub el hizb */
    ARABIC_TRANSPARENT, /* 0x06DF small high rounded zero */
    ARABIC_TRANSPARENT, /* 0x06E0 small high upright pectangular zero */
    ARABIC_TRANSPARENT, /* 0x06E1 small high dotless head of khah */
    ARABIC_TRANSPARENT, /* 0x06E2 smal high meem isolated form */
    ARABIC_TRANSPARENT, /* 0x06E3 small low seen */
    ARABIC_TRANSPARENT, /* 0x06E4 small high madda */
    ARABIC_TRANSPARENT, /* 0x06E5 small waw */
    ARABIC_TRANSPARENT, /* 0x06E6 small yeh */
    ARABIC_TRANSPARENT, /* 0x06E7 small high yeh */
    ARABIC_TRANSPARENT, /* 0x06E8 small high noon */
    ARABIC_NON_JOIN, /* 0x06E9 place of sajdah */
    ARABIC_TRANSPARENT, /* 0x06EA empty centre low stop */
    ARABIC_TRANSPARENT, /* 0x06EB empty centre low stop */
    ARABIC_TRANSPARENT, /* 0x06EC rounded high stop with filled centre */
    ARABIC_TRANSPARENT, /* 0x06ED small low meem */
    ARABIC_NON_JOIN, /* 0x06EE */
    ARABIC_NON_JOIN, /* 0x06EF */
    ARABIC_NON_JOIN, /* 0x06F0 extended Arabic-Indic digit zero */
    ARABIC_NON_JOIN, /* 0x06F1 extended Arabic-Indic digit 1 */
    ARABIC_NON_JOIN, /* 0x06F2 extended Arabic-Indic digit 2 */
    ARABIC_NON_JOIN, /* 0x06F3 extended Arabic-Indic digit 3 */
    ARABIC_NON_JOIN, /* 0x06F4 extended Arabic-Indic digit 4 */
    ARABIC_NON_JOIN, /* 0x06F5 extended Arabic-Indic digit 5 */
    ARABIC_NON_JOIN, /* 0x06F6 extended Arabic-Indic digit 6 */
    ARABIC_NON_JOIN, /* 0x06F7 extended Arabic-Indic digit 7 */
    ARABIC_NON_JOIN, /* 0x06F8 extended Arabic-Indic digit 8 */
    ARABIC_NON_JOIN, /* 0x06F9 extended Arabic-Indic digit 9 */
    ARABIC_NON_JOIN, /* 0x06FA sheen with dot below*/
    ARABIC_NON_JOIN, /* 0x06FB dad with dot below */
    ARABIC_NON_JOIN, /* 0x06FC ghain with dot below */
    ARABIC_NON_JOIN, /* 0x06FD sign sindhi ampersand */
    ARABIC_NON_JOIN, /* 0x06FE sign sindhi postposition men */
    ARABIC_NON_JOIN, /* 0x06FF */
};

const ARABIC_JOIN_TYPE_ENUM g_arabic_form_A_char_array[] = 
{
    ARABIC_NON_JOIN, /* 0xFB50 */
    ARABIC_NON_JOIN, /* 0xFB51 */
    ARABIC_NON_JOIN, /* 0xFB52 */
    ARABIC_NON_JOIN, /* 0xFB53 */
    ARABIC_NON_JOIN, /* 0xFB54 */
    ARABIC_NON_JOIN, /* 0xFB55 */
    ARABIC_DUAL_JOIN, /* 0xFB56 */
    ARABIC_NON_JOIN, /* 0xFB57 */
    ARABIC_NON_JOIN, /* 0xFB58 */
    ARABIC_NON_JOIN, /* 0xFB59 */
    ARABIC_NON_JOIN, /* 0xFB5A */
    ARABIC_NON_JOIN, /* 0xFB5B */
    ARABIC_NON_JOIN, /* 0xFB5C */
    ARABIC_NON_JOIN, /* 0xFB5D */
    ARABIC_NON_JOIN, /* 0xFB5E */
    ARABIC_NON_JOIN, /* 0xFB5F */
    ARABIC_NON_JOIN,/* 0xFB60 */
    ARABIC_NON_JOIN,/* 0xFB61 */
    ARABIC_NON_JOIN,/* 0xFB62 */
    ARABIC_NON_JOIN,/* 0xFB63 */
    ARABIC_NON_JOIN,/* 0xFB64 */
    ARABIC_NON_JOIN,/* 0xFB65 */
    ARABIC_NON_JOIN,/* 0xFB66 */
    ARABIC_NON_JOIN,/* 0xFB67 */
    ARABIC_NON_JOIN,/* 0xFB68 */
    ARABIC_NON_JOIN,/* 0xFB69 */
    ARABIC_NON_JOIN,/* 0xFB6A */
    ARABIC_NON_JOIN,/* 0xFB6B */
    ARABIC_NON_JOIN,/* 0xFB6C */
    ARABIC_NON_JOIN,/* 0xFB6D */
    ARABIC_NON_JOIN,/* 0xFB6E */
    ARABIC_NON_JOIN,/* 0xFB6F */
    ARABIC_NON_JOIN,/* 0xFB70 */
    ARABIC_NON_JOIN,/* 0xFB71 */
    ARABIC_NON_JOIN,/* 0xFB72 */
    ARABIC_NON_JOIN,/* 0xFB73 */
    ARABIC_NON_JOIN,/* 0xFB74 */
    ARABIC_NON_JOIN,/* 0xFB75 */
    ARABIC_NON_JOIN,/* 0xFB76 */
    ARABIC_NON_JOIN,/* 0xFB77 */
    ARABIC_NON_JOIN,/* 0xFB78 */
    ARABIC_NON_JOIN,/* 0xFB79 */
    ARABIC_DUAL_JOIN,/* 0xFB7A */
    ARABIC_NON_JOIN,/* 0xFB7B */
    ARABIC_NON_JOIN,/* 0xFB7C */
    ARABIC_NON_JOIN,/* 0xFB7D */
    ARABIC_NON_JOIN,/* 0xFB7E */
    ARABIC_NON_JOIN,/* 0xFB7F */
    ARABIC_NON_JOIN,/* 0xFB80 */
    ARABIC_NON_JOIN,/* 0xFB81 */
    ARABIC_NON_JOIN,/* 0xFB82 */
    ARABIC_NON_JOIN,/* 0xFB83 */
    ARABIC_NON_JOIN,/* 0xFB84 */
    ARABIC_NON_JOIN,/* 0xFB85 */
    ARABIC_NON_JOIN,/* 0xFB86 */
    ARABIC_NON_JOIN,/* 0xFB87 */
    ARABIC_NON_JOIN,/* 0xFB88 */
    ARABIC_NON_JOIN,/* 0xFB89 */
    ARABIC_NON_JOIN,/* 0xFB8A */
    ARABIC_NON_JOIN,/* 0xFB8B */
    ARABIC_NON_JOIN,/* 0xFB8C */
    ARABIC_NON_JOIN,/* 0xFB8D */
    ARABIC_DUAL_JOIN,/* 0xFB8E */
    ARABIC_NON_JOIN,/* 0xFB8F */
    ARABIC_NON_JOIN,/* 0xFB90 */
    ARABIC_NON_JOIN,/* 0xFB91 */
    ARABIC_DUAL_JOIN,/* 0xFB92 */
    ARABIC_NON_JOIN,/* 0xFB93 */
    ARABIC_NON_JOIN,/* 0xFB94 */
    ARABIC_NON_JOIN,/* 0xFB95 */
    ARABIC_NON_JOIN,/* 0xFB96 */
    ARABIC_NON_JOIN,/* 0xFB97 */
    ARABIC_NON_JOIN,/* 0xFB98 */
    ARABIC_NON_JOIN,/* 0xFB99 */
    ARABIC_NON_JOIN,/* 0xFB9A */
    ARABIC_NON_JOIN,/* 0xFB9B */
    ARABIC_NON_JOIN,/* 0xFB9C */
    ARABIC_NON_JOIN,/* 0xFB9D */
    ARABIC_NON_JOIN,/* 0xFB9E */
    ARABIC_NON_JOIN,/* 0xFB9F */
    ARABIC_NON_JOIN,/* 0xFBA0 */
    ARABIC_NON_JOIN,/* 0xFBA1 */
    ARABIC_NON_JOIN,/* 0xFBA2 */
    ARABIC_NON_JOIN,/* 0xFBA3 */
    ARABIC_NON_JOIN,/* 0xFBA4 */
    ARABIC_NON_JOIN,/* 0xFBA5 */
    ARABIC_NON_JOIN,/* 0xFBA6 */
    ARABIC_NON_JOIN,/* 0xFBA7 */
    ARABIC_NON_JOIN,/* 0xFBA8 */
    ARABIC_NON_JOIN,/* 0xFBA9 */
    ARABIC_NON_JOIN,/* 0xFBAA */
    ARABIC_NON_JOIN,/* 0xFBAB */
    ARABIC_NON_JOIN,/* 0xFBAC */
    ARABIC_NON_JOIN,/* 0xFBAD */
    ARABIC_NON_JOIN,/* 0xFBAE */
    ARABIC_NON_JOIN,/* 0xFBAF */
    ARABIC_NON_JOIN,/* 0xFBB0 */
    ARABIC_NON_JOIN,/* 0xFBB1 */
    ARABIC_NON_JOIN,/* 0xFBB2 */
    ARABIC_NON_JOIN,/* 0xFBB3 */
    ARABIC_NON_JOIN,/* 0xFBB4 */
    ARABIC_NON_JOIN,/* 0xFBB5 */
    ARABIC_NON_JOIN,/* 0xFBB6 */
    ARABIC_NON_JOIN,/* 0xFBB7 */
    ARABIC_NON_JOIN,/* 0xFBB8 */
    ARABIC_NON_JOIN,/* 0xFBB9 */
    ARABIC_NON_JOIN,/* 0xFBBA */
    ARABIC_NON_JOIN,/* 0xFBBB */
    ARABIC_NON_JOIN,/* 0xFBBC */
    ARABIC_NON_JOIN,/* 0xFBBD */
    ARABIC_NON_JOIN,/* 0xFBBE */
    ARABIC_NON_JOIN,/* 0xFBBF */
    ARABIC_NON_JOIN,/* 0xFBC0 */
    ARABIC_NON_JOIN,/* 0xFBC1 */
    ARABIC_NON_JOIN,/* 0xFBC2 */
    ARABIC_NON_JOIN,/* 0xFBC3 */
    ARABIC_NON_JOIN,/* 0xFBC4 */
    ARABIC_NON_JOIN,/* 0xFBC5 */
    ARABIC_NON_JOIN,/* 0xFBC6 */
    ARABIC_NON_JOIN,/* 0xFBC7 */
    ARABIC_NON_JOIN,/* 0xFBC8 */
    ARABIC_NON_JOIN,/* 0xFBC9 */
    ARABIC_NON_JOIN,/* 0xFBCA */
    ARABIC_NON_JOIN,/* 0xFBCB */
    ARABIC_NON_JOIN,/* 0xFBCC */
    ARABIC_NON_JOIN,/* 0xFBCD */
    ARABIC_NON_JOIN,/* 0xFBCE */
    ARABIC_NON_JOIN,/* 0xFBCF */
    ARABIC_NON_JOIN,/* 0xFBD0 */
    ARABIC_NON_JOIN,/* 0xFBD1 */
    ARABIC_NON_JOIN,/* 0xFBD2 */
    ARABIC_NON_JOIN,/* 0xFBD3 */
    ARABIC_NON_JOIN,/* 0xFBD4 */
    ARABIC_NON_JOIN,/* 0xFBD5 */
    ARABIC_NON_JOIN,/* 0xFBD6 */
    ARABIC_NON_JOIN,/* 0xFBD7 */
    ARABIC_NON_JOIN,/* 0xFBD8 */
    ARABIC_NON_JOIN,/* 0xFBD9 */
    ARABIC_NON_JOIN,/* 0xFBDA */
    ARABIC_NON_JOIN,/* 0xFBDB */
    ARABIC_NON_JOIN,/* 0xFBDC */
    ARABIC_NON_JOIN,/* 0xFBDD */
    ARABIC_NON_JOIN,/* 0xFBDE */
    ARABIC_NON_JOIN,/* 0xFBDF */
    ARABIC_NON_JOIN,/* 0xFBE0 */
    ARABIC_NON_JOIN,/* 0xFBE1 */
    ARABIC_NON_JOIN,/* 0xFBE2 */
    ARABIC_NON_JOIN,/* 0xFBE3 */
    ARABIC_NON_JOIN,/* 0xFBE4 */
    ARABIC_NON_JOIN,/* 0xFBE5 */
    ARABIC_NON_JOIN,/* 0xFBE6 */
    ARABIC_NON_JOIN,/* 0xFBE7 */
    ARABIC_NON_JOIN,/* 0xFBE8 */
    ARABIC_NON_JOIN,/* 0xFBE9 */
    ARABIC_NON_JOIN,/* 0xFBEA */
    ARABIC_NON_JOIN,/* 0xFBEB */
    ARABIC_NON_JOIN,/* 0xFBEC */
    ARABIC_NON_JOIN,/* 0xFBED */
    ARABIC_NON_JOIN,/* 0xFBEE */
    ARABIC_NON_JOIN,/* 0xFBEF */
    ARABIC_NON_JOIN,/* 0xFBF0 */
    ARABIC_NON_JOIN,/* 0xFBF1 */
    ARABIC_NON_JOIN,/* 0xFBF2 */
    ARABIC_NON_JOIN,/* 0xFBF3 */
    ARABIC_NON_JOIN,/* 0xFBF4 */
    ARABIC_NON_JOIN,/* 0xFBF5 */
    ARABIC_NON_JOIN,/* 0xFBF6 */
    ARABIC_NON_JOIN,/* 0xFBF7 */
    ARABIC_NON_JOIN,/* 0xFBF8 */
    ARABIC_NON_JOIN,/* 0xFBF9 */
    ARABIC_NON_JOIN,/* 0xFBFA */
    ARABIC_NON_JOIN,/* 0xFBFB */
    ARABIC_DUAL_JOIN,/* 0xFBFC */
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN,
    ARABIC_NON_JOIN
};

const ARABIC_JOIN_TYPE_ENUM g_arabic_form_B_char_array[] =
{
    ARABIC_DUAL_JOIN,  /* FE70 */
    ARABIC_NON_JOIN,  /* FE71 */ 
    ARABIC_NON_JOIN,  /* FE72 */
    ARABIC_NON_JOIN,  /* FE73 */
    ARABIC_NON_JOIN,  /* FE74 */
    ARABIC_NON_JOIN,  /* FE75 */
    ARABIC_DUAL_JOIN,  /* FE76 */
    ARABIC_NON_JOIN,  /* FE77 */
    ARABIC_DUAL_JOIN,  /* FE78 */
    ARABIC_NON_JOIN,   /* FE79 */   
    ARABIC_DUAL_JOIN,  /* FE7A */
    ARABIC_NON_JOIN,  /* FE7B */
    ARABIC_DUAL_JOIN,  /* FE7C */
    ARABIC_NON_JOIN,  /* FE7D */
    ARABIC_DUAL_JOIN,  /* FE7E */
    ARABIC_NON_JOIN,  /* FE7F */    
    ARABIC_NON_JOIN,  /* FE80 */ 
    ARABIC_RIGHT_JOIN,  /* FE81 */ 
    ARABIC_NON_JOIN,  /* FE82 */
    ARABIC_RIGHT_JOIN,  /* FE83 */ 
    ARABIC_NON_JOIN,  /* FE84 */
    ARABIC_RIGHT_JOIN,   /* FE85 */
    ARABIC_NON_JOIN,  /* FE86 */
    ARABIC_RIGHT_JOIN,  /* FE87 */ 
    ARABIC_NON_JOIN,  /* FE88 */
    ARABIC_DUAL_JOIN,  /* FE89 */ 
    ARABIC_NON_JOIN,  /* FE8A */
    ARABIC_NON_JOIN,  /* FE8B */    
    ARABIC_NON_JOIN,  /* FE8C */
    ARABIC_RIGHT_JOIN, /* FE8D */ 
    ARABIC_NON_JOIN, /* FE8E */
    ARABIC_DUAL_JOIN, /* FE8F */ 
    ARABIC_NON_JOIN, /* FE90 */
    ARABIC_NON_JOIN, /* FE91 */    
    ARABIC_NON_JOIN, /* FE92 */
    ARABIC_RIGHT_JOIN, /* FE93 */
    ARABIC_NON_JOIN, /* FE94 */
    ARABIC_DUAL_JOIN, /* FE95 */
    ARABIC_NON_JOIN, /* FE96 */
    ARABIC_NON_JOIN, /* FE97 */    
    ARABIC_NON_JOIN, /* FE98 */
    ARABIC_DUAL_JOIN, /* FE99 */
    ARABIC_NON_JOIN, /* FE9A */
    ARABIC_NON_JOIN, /* FE9B */
    ARABIC_NON_JOIN, /* FE9C */
    ARABIC_DUAL_JOIN, /* FE9D */
    ARABIC_NON_JOIN, /* FE9E */
    ARABIC_NON_JOIN, /* FE9F */
    ARABIC_NON_JOIN, /* FEA0 */
    ARABIC_DUAL_JOIN, /* FEA1 */
    ARABIC_NON_JOIN, /* FEA2 */
    ARABIC_NON_JOIN, /* FEA3 */    
    ARABIC_NON_JOIN, /* FEA4 */
    ARABIC_DUAL_JOIN, /* FEA5 */
    ARABIC_NON_JOIN, /* FEA6 */
    ARABIC_NON_JOIN, /* FEA7 */
    ARABIC_NON_JOIN, /* FEA8 */
    ARABIC_RIGHT_JOIN, /* FEA9 */
    ARABIC_NON_JOIN, /* FEAA */
    ARABIC_RIGHT_JOIN, /* FEAB */
    ARABIC_NON_JOIN, /* FEAC */
    ARABIC_RIGHT_JOIN, /* FEAD */
    ARABIC_NON_JOIN, /* FEAE */
    ARABIC_RIGHT_JOIN, /* FEAF */
    ARABIC_NON_JOIN, /* FEB0 */
    ARABIC_DUAL_JOIN, /* FEB1 */
    ARABIC_NON_JOIN, /* FEB2 */
    ARABIC_NON_JOIN, /* FEB3 */
    ARABIC_NON_JOIN, /* FEB4 */
    ARABIC_DUAL_JOIN, /* FEB5 */
    ARABIC_NON_JOIN, /* FEB6 */
    ARABIC_NON_JOIN, /* FEB7 */
    ARABIC_NON_JOIN, /* FEB8 */
    ARABIC_DUAL_JOIN, /* FEB9 */
    ARABIC_NON_JOIN, /* FEBA */
    ARABIC_NON_JOIN,  /* FEBB */   
    ARABIC_NON_JOIN, /* FEBC */
    ARABIC_DUAL_JOIN, /* FEBD */
    ARABIC_NON_JOIN, /* FEBE */
    ARABIC_NON_JOIN, /* FEBF */
    ARABIC_NON_JOIN, /* FEC0 */
    ARABIC_DUAL_JOIN, /* FEC1 */
    ARABIC_NON_JOIN, /* FEC2 */
    ARABIC_NON_JOIN, /* FEC3 */
    ARABIC_NON_JOIN, /* FEC4 */
    ARABIC_DUAL_JOIN, /* FEC5 */
    ARABIC_NON_JOIN, /* FEC6 */
    ARABIC_NON_JOIN, /* FEC7 */    
    ARABIC_NON_JOIN, /* FEC8 */
    ARABIC_DUAL_JOIN, /* FEC9 */
    ARABIC_NON_JOIN, /* FECA */
    ARABIC_NON_JOIN, /* FECB */
    ARABIC_NON_JOIN, /* FECC */
    ARABIC_DUAL_JOIN, /* FECD */
    ARABIC_NON_JOIN, /* FECE */
    ARABIC_NON_JOIN, /* FECF */
    ARABIC_NON_JOIN, /* FED0 */
    ARABIC_DUAL_JOIN, /* FED1 */
    ARABIC_NON_JOIN, /* FED2 */
    ARABIC_NON_JOIN, /* FED3 */    
    ARABIC_NON_JOIN, /* FED4 */
    ARABIC_DUAL_JOIN, /* FED5 */
    ARABIC_NON_JOIN, /* FED6 */
    ARABIC_NON_JOIN, /* FED7 */
    ARABIC_NON_JOIN, /* FED8 */
    ARABIC_DUAL_JOIN, /* FED9 */
    ARABIC_NON_JOIN, /* FEDA */
    ARABIC_NON_JOIN, /* FEDB */
    ARABIC_NON_JOIN, /* FEDC */
    ARABIC_DUAL_JOIN, /* FEDD */
    ARABIC_NON_JOIN, /* FEDE */
    ARABIC_NON_JOIN, /* FEEF */    
    ARABIC_NON_JOIN, /* FEE0 */ 
    ARABIC_DUAL_JOIN, /* FEE1 */
    ARABIC_NON_JOIN, /* FEE2 */ 
    ARABIC_NON_JOIN, /* FEE3 */ 
    ARABIC_NON_JOIN, /* FEE4 */ 
    ARABIC_DUAL_JOIN, /* FEE5 */
    ARABIC_NON_JOIN, /* FEE6 */ 
    ARABIC_NON_JOIN, /* FEE7 */ 
    ARABIC_NON_JOIN, /* FEE8 */ 
    ARABIC_DUAL_JOIN, /* FEE9 */
    ARABIC_NON_JOIN, /* FEEA */ 
    ARABIC_NON_JOIN, /* FEEB */     
    ARABIC_NON_JOIN, /* FEEC */ 
    ARABIC_RIGHT_JOIN, /* FEED */
    ARABIC_NON_JOIN, /* FEEE */ 
    ARABIC_RIGHT_JOIN, /* FEFF */ 
    ARABIC_NON_JOIN, /* FEF0 */ 
    ARABIC_DUAL_JOIN, /* FEF1 */
    ARABIC_NON_JOIN, /* FEF2 */ 
    ARABIC_NON_JOIN, /* FEF3 */ 
    ARABIC_NON_JOIN, /* FEF4 */ 
    ARABIC_RIGHT_JOIN, /* FEF5 */ 
    ARABIC_NON_JOIN, /* FEF6 */ 
    ARABIC_RIGHT_JOIN, /* FEF7 */     
    ARABIC_NON_JOIN, /* FEF8 */ 
    ARABIC_RIGHT_JOIN, /* FEF9 */ 
    ARABIC_NON_JOIN, /* FEFA */ 
    ARABIC_RIGHT_JOIN, /* FEFB */ 
    ARABIC_NON_JOIN, /* FEFC */ 
    ARABIC_NON_JOIN, /* FEFD */ 
    ARABIC_NON_JOIN, /* FEFE */ 
    ARABIC_NON_JOIN /* FEFF */
};

/*****************************************************************************
 * FUNCTION
 *  ArabicGetJoinType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
ARABIC_JOIN_TYPE_ENUM ArabicGetJoinType(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ARABIC_JOIN_TYPE_ENUM join_type = ARABIC_NON_JOIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(UI_ARABIC_CHARACTER_RANGE(ch) || UI_ARABIC_FORM_B_RANGE(ch) || UI_ARABIC_FORM_A_RANGE(ch)))
    {
        return ARABIC_NON_JOIN;
    }
    
    /* get join type of the character */
    if (UI_ARABIC_CHARACTER_RANGE(ch))
    {
        join_type = g_arabic_base_char_array[UNICODE_ARABIC(ch)];
    }
    else if (UI_ARABIC_FORM_B_RANGE(ch))
    {
        join_type = g_arabic_form_B_char_array[UNICODE_ARABIC_FORM_B(ch)];
    }
    else if (UI_ARABIC_FORM_A_RANGE(ch))
    {
        join_type = g_arabic_form_A_char_array[UNICODE_ARABIC_FORM_A(ch)];
    }

    return join_type;

}


/*****************************************************************************
 * FUNCTION
 *  WhetherRightJoinCausingChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL WhetherRightJoinCausingChar(U16 pre_char, U16 pre2_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ARABIC_JOIN_TYPE_ENUM join_type = ARABIC_NON_JOIN;
    ARABIC_JOIN_TYPE_ENUM join_type2 = ARABIC_NON_JOIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(UI_ARABIC_CHARACTER_RANGE(pre_char) || UI_ARABIC_FORM_B_RANGE(pre_char) || UI_ARABIC_FORM_A_RANGE(pre_char)))
    {
        return FALSE;
    }

    /* get join type of previous character */
    join_type = ArabicGetJoinType(pre_char);
    join_type2 = ArabicGetJoinType(pre2_char);

    switch (join_type)
    {
        case ARABIC_LEFT_JOIN:
        case ARABIC_DUAL_JOIN:
        case ARABIC_JOIN_CAUSING:
            return TRUE;
            break;
        case ARABIC_TRANSPARENT:
            switch(join_type2)
            {
                case ARABIC_LEFT_JOIN:
                case ARABIC_DUAL_JOIN:
                case ARABIC_JOIN_CAUSING:    
                    return TRUE;
                    break;
                default:
                    return FALSE;
                    break;
            }
            break;
        default:
            return FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  WhetherLeftJoinCausingChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL WhetherLeftJoinCausingChar(U16 post_char, U16 post2_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ARABIC_JOIN_TYPE_ENUM join_type = ARABIC_NON_JOIN;
    ARABIC_JOIN_TYPE_ENUM join_type2 = ARABIC_NON_JOIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(UI_ARABIC_CHARACTER_RANGE(post_char) || UI_ARABIC_FORM_B_RANGE(post_char)|| UI_ARABIC_FORM_A_RANGE(post_char)))
    {
        return FALSE;
    }

    /* get join type of previous character */
    join_type = ArabicGetJoinType(post_char);
    join_type2 = ArabicGetJoinType(post2_char);

    switch (join_type)
    {
        case ARABIC_RIGHT_JOIN:
        case ARABIC_DUAL_JOIN:
        case ARABIC_JOIN_CAUSING:
            return TRUE;
            break;
        case ARABIC_TRANSPARENT:
            switch(join_type2)
            {
                case ARABIC_RIGHT_JOIN:
                case ARABIC_DUAL_JOIN:
                case ARABIC_JOIN_CAUSING:    
                    return TRUE;
                    break;
                default:
                    return FALSE;
                    break;
            }
            break;
        default:
            return FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  language        [IN]        
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* PMT START URDU */
void ArabicShapeEngine(U8 language, PU16 length, PU16 text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ArabicShapeEngine2(language, length, text_buffer, NULL, NULL);
}
/* PMT END URDU */


/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  language        [IN]        
 *  length          [IN]        
 *  text_buffer     [IN]        
 *  pOrgToSha       [IN]        
 *  pShaToOrg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine2(U8 language, PU16 length, PU16 text_buffer, PU16 pOrgToSha, PU16 pShaToOrg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_length = *length;
    BOOL is_arabic_char_present = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_arabic_char_present = arabic_shape_rules(temp_length, text_buffer);
    if (is_arabic_char_present) /* if arabic character present in text_buffer then calls rules API */
    {
        arabic_ligature_rules(language, text_buffer, text_buffer, length, pOrgToSha, pShaToOrg, MMI_FALSE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  language        [IN]        
 *  length          [IN]        
 *  text_buffer     [IN]        
 *  pOrgToSha       [IN]        
 *  pShaToOrg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL arabic_shape_rules(U16 length, PU16 text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const ARABIC_SHAPE_TABLE *glyph_form = glyph_base_Tb;
    U16 preChar = 0;
    U16 pre2Char = 0;
    U16 postChar = 0;
    U16 post2Char = 0;
    U16 current_character;
    U16 count = 0;
    MMI_BOOL is_arabic_char_present = MMI_FALSE;
    ARABIC_JOIN_TYPE_ENUM join_type = ARABIC_NON_JOIN;
    U16 base = 0;
    U16 temp_length = length;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_length)
    {
        current_character = text_buffer[count];

        if (UI_ARABIC_FORM_B_RANGE(current_character))
        {
            glyph_form = glyph_Tb_B;
            base = UNICODE_ARABIC_FORM_B(current_character);
        }
        else if (UI_ARABIC_FORM_A_RANGE(current_character))
        {
            glyph_form = glyph_Tb_A;
            base = UNICODE_ARABIC_FORM_A(current_character);
        }
        else
        {
            glyph_form = glyph_base_Tb;
            base = UNICODE_ARABIC(current_character);
        }

        /* get next char */
        if (count + 1 < length)
            postChar = text_buffer[count + 1];
        else
            postChar= 0;

        /* get next 2 char */
        if (count + 2 < length)
            post2Char = text_buffer[count + 2];
        else
            post2Char= 0;
        
        if (UI_ARABIC_CHARACTER_RANGE(current_character)) //check for current character in Arabic
        {
            is_arabic_char_present = 1;
            join_type = ArabicGetJoinType(current_character);
            switch (join_type)
            {
                case ARABIC_NON_JOIN:
                    pre2Char = preChar;
                    preChar = current_character;
                    if (current_character == 0x0621) /* because hamza only has its nominal glyph form */
                        current_character = glyph_form[base].nominalForm;
                    break;
                case ARABIC_RIGHT_JOIN:
                    if (WhetherRightJoinCausingChar(preChar, pre2Char))
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].postForm;
                    }
                    else
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].nominalForm;
                    }
                        
                    break;
                case ARABIC_LEFT_JOIN:
                    if (WhetherLeftJoinCausingChar(postChar, post2Char))
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].preForm;
                    }
                    else
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].nominalForm;
                    }
                    
                    break;
                case ARABIC_DUAL_JOIN:
                    if (WhetherLeftJoinCausingChar(postChar, post2Char) && 
                        WhetherRightJoinCausingChar(preChar, pre2Char))
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].middleForm;
                    }
                    else if (WhetherLeftJoinCausingChar(postChar, post2Char))
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].preForm;
                    }
                    else if (WhetherRightJoinCausingChar(preChar, pre2Char))
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].postForm;
                    }
                    else
                    {
                        pre2Char = preChar;
                        preChar = current_character;
                        current_character = glyph_form[base].nominalForm;
                    }
                    
                    break;
                case ARABIC_TRANSPARENT:
                    pre2Char = preChar;
                    preChar = current_character;
                    break;
                case ARABIC_JOIN_CAUSING:
                    pre2Char = preChar;
                    preChar = current_character;
                    current_character = glyph_form[base].nominalForm;
                    break;

            }
            if (current_character != NULL) text_buffer[count] = current_character;
            
        }
        else    /* if current character is not in arabic */
        {
            preChar = 0;
            postChar = 0;
        }

        count = count + 1;
        temp_length--;
    }
    return is_arabic_char_present;
}


/*****************************************************************************
 * FUNCTION
 *  arabic_ligature_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  language        [IN]        
 *  text_buffer [IN]        
 *  length      [IN]        
 *  pOrgToSha   [IN]        
 *  pShaToOrg   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 arabic_ligature_rules(U8 language, PU16 text_buffer_in, PU16 text_buffer_out, PU16 length, PU16 pOrgToSha, PU16 pShaToOrg, MMI_BOOL one_cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    ARABIC_MAIN_TABLE ind_table;
    const LIGATURE_INFO_TABLE *char_table;
    U16 input_buffer[ARABIC_LIGATURE_LENGTH];
    U16 current_character;
    U16 ch_index;	
    S32 size;    
    S32 max_size;    
    U16 count = 0;
    U16 read_count = 0;	
    U8 is_req_orginal_to_shape_position = 0;
    U8 is_req_shape_to_original_position = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (pOrgToSha != NULL)
    {
        is_req_orginal_to_shape_position = 1;
    }

    if (pShaToOrg != NULL)
    {
        is_req_shape_to_original_position = 1;
    }

    while(read_count < *length)
    {
        current_character = text_buffer_in[read_count];

        if (is_req_orginal_to_shape_position)
        {
            pOrgToSha[read_count] = count;
        }

        text_buffer_out[count] = current_character;
        if (is_req_shape_to_original_position)
        {
            pShaToOrg[count] = read_count;
        }

        if (UI_ARABIC_FORM_B_RANGE(current_character) || UI_ARABIC_FORM_A_RANGE(current_character))
        {
            if (UI_ARABIC_FORM_A_RANGE(current_character))
            {
                ch_index = UNICODE_ARABIC_FORM_A(current_character);    /* find the index of character in main table */
                ind_table = Arabic_Tbl_A[ch_index]; /* gets the individual charactr's table in main table */
            }
            else
            {
                ch_index = UNICODE_ARABIC_FORM_B(current_character);    /* find the index of character in main table */
                ind_table = Arabic_Tbl_B[ch_index]; /* gets the individual charactr's table in main table */
            }
            char_table = ind_table.glyphinfo;   /* holds the add. of individual character */
            size = ind_table.nsize;
            max_size = ind_table.maxInputGlyphSize;
            if (char_table != NULL)
            {
                S32 i;

                memset(&input_buffer, 0, sizeof(input_buffer));
                for (i = 0; (i < max_size) && ((read_count + i) < *length); i++)
                {
                    input_buffer[i] = text_buffer_in[read_count + i];
                }
                while (size)
                {
                    size--;
                    if (((char_table[size].language_for_ligature & language)
                         && memcmp(char_table[size].Input_glyph, input_buffer, char_table[size].nInputLen * 2) == 0))
                    {
                        memcpy(input_buffer, char_table[size].Output_glyph, char_table[size].nOutputLen * 2);
                        input_buffer[char_table[size].nOutputLen] = (U16) NULL;
                        if (is_req_orginal_to_shape_position)
                        {
                            for(i=read_count;i<read_count+char_table[size].nInputLen;i++)
                            {
                                pOrgToSha[i] = count;
                            }
                        }                
                        read_count += char_table[size].nInputLen-1;
                        count+=char_table[size].nOutputLen-1;
                        break;
                    }
                }
                for(i=0;i<char_table[size].nOutputLen;i++)
                {
                    text_buffer_out[count+i] = input_buffer[i];
                }
                if (is_req_shape_to_original_position)
                {
                    for(i=0;i<char_table[size].nOutputLen-1;i++)
                    {
                        pShaToOrg[count+i+1] = read_count;
                    }
                }
            }
	    else
	    {
                text_buffer_out[count] = current_character;                
	    }
        }
        else
        {
            text_buffer_out[count] = current_character;
        }
        count++;
        read_count++;
        if (one_cluster)
            break;
    }
    *length = (U16)count;
    for(;count<read_count;count++)
    {
        text_buffer_out[count] = (U16) NULL;
    }
    return read_count;
}


/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine_ext(PU16 nLen, PU16 buffer)
{
    ArabicShapeEngine(
        ARABIC_LIGATURE_NONE
        #if defined(__MMI_LANG_ARABIC__)
        | ARABIC_LIGATURE_ARABIC
        #endif
        #if defined(__MMI_LANG_PERSIAN__)
        | ARABIC_LIGATURE_PERSIAN
        #endif
        #if defined(__MMI_LANG_URDU__)
        | ARABIC_LIGATURE_URDU
        #endif
        ,nLen, 
        buffer);    /* output will replace the input string after returning */
}


/*****************************************************************************
 * FUNCTION
 *  ArabicShapeEngine2_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [IN]        
 *  text_buffer     [IN]        
 *  pOrgToSha       [IN]        
 *  pShaToOrg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ArabicShapeEngine2_ext(PU16 length, PU16 text_buffer, PU16 pOrgToSha, PU16 pShaToOrg)
{
    ArabicShapeEngine2(
        ARABIC_LIGATURE_NONE
        #if defined(__MMI_LANG_ARABIC__)
        | ARABIC_LIGATURE_ARABIC
        #endif
        #if defined(__MMI_LANG_PERSIAN__)
        | ARABIC_LIGATURE_PERSIAN
        #endif
        #if defined(__MMI_LANG_URDU__)
        | ARABIC_LIGATURE_URDU
        #endif
        , length, 
        text_buffer, 
        pOrgToSha, 
        pShaToOrg);


}

#endif /* __MMI_ARSHAPING_ENGINE__ */ 
/* PMT END PERSIAN */


