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
 *    Punjabi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C file of punjabi font rule 
 *
 *
 * Author:
 * Rakesh Singh (mti00098)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "IndicEngineGprot.h"

#if defined (__MMI_LANG_PUNJABI__)

#ifndef NULL
#define NULL   0
#endif 

const ire_character_info_table_struct punjabi_character_info_table[] = 
{
    /* INDEPENDENT VOWEL */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},              /* 0x0A01 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},/* 0x0A02 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                /* 0x0A03 */

    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A04 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_2, 0}, /* 0x0A05 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A06 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_2, 0}, /* 0x0A07 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A08 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A09 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A0A */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0B */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0C */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0D */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A0E */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A0F */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A10 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A11 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A12 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A13 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0}, /* 0x0A14 */

    /* CONSONANTS */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A15 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},    /* 0x0A16 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},    /* 0x0A17 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A18 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A19 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A1A */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A1B */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},    /* 0x0A1C */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A1D */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A1E */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A1F */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A20 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A21 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A22 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A23 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A24 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A25 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A26 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A27 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A28 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A29 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A2A */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},    /* 0x0A2B */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A2C */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A2D */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A2E */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A2F */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A30 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A31 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},    /* 0x0A32 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A33 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A34 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A35 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A36 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A37 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},    /* 0x0A38 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},                  /* 0x0A39 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A3A */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A3B */

    /* SIGNS */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_3, 0},       /* 0x0A3C */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A3D */

    /* DEPENDENT VOWELS */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},         /* 0x0A3E */
    {0, IRE_PRE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, IRE_CHAR_TYPE_2, 0},           /* 0x0A3F */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},         /* 0x0A40 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_2, 0},       /* 0x0A41 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_2, 0},       /* 0x0A42 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A43 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A44 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A45 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A46 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},       /* 0x0A47 */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},       /* 0x0A48 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A49 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A4A */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},       /* 0x0A4B */
    {0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_1, 0},       /* 0x0A4C */

    /* SIGNS */
    {0, 0, 0, IRE_HALANT_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},       /* 0x0A4D */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A4E */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A4F */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A50 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE, 0, 0, 0},   /* 0x0A51 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A52 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A53 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A54 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A55 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A56 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A57 */

    /* ADDITIONAL CONSONANT */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A58 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A59 */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A5A */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A5B */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A5C */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A5D */
    {IRE_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A5E */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A5F */

    /* GENERIC ADDITIONS */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A60 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A61 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A62 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   /* 0x0A63 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A64 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A65 */

    /* DIGITS */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A66 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A67 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A68 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A69 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A6A */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A6B */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A6C */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A6D */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A6E */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},   /* 0x0A6F */

    /* GURMUKHI SPECIFIC ADDITOIN */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, IRE_CHAR_TYPE_2, 0},       /* 0x0A70 */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},       /* 0x0A71 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A72 */
    {0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, 0},    /* 0x0A73 */
    {0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},    /* 0x0A74 */
    
    /* SIGN */
    {0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE, 0, 0, 0}	/* Ox0A75 */
};

const ire_character_info_table_struct punjabi_ligature_info_table[] = 
{
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},     /* 0xEB00 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB01 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB02 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB03 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_PREBASE_POSITION, 0, 0, 0},      /* 0xEB04 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},     /* 0xEB05 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},     /* 0xEB06 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},     /* 0xEB07 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},     /* 0xEB08 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB09 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB0A */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB0B */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB0C */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB0D */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB0E */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB0F */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0,0, 0},   /* 0xEB10 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB11 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB12 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB13 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB14 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB15 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_POSTBASE_POSITION, 0, 0, 0},   /* 0xEB16 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB17 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB18 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB19 */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB1A */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB1B */
    {0, 0, 0, 0, IRE_NORMAL_LIGATURE, 0, IRE_ABOVE_BASE_POSITION, 0, 0, 0},   /* 0xEB1C */
};

 /*    CONSONANT'S TABLES   */

const ire_glyph_info_table_struct PUNJABI_KA_Tbl[] = 
{

    /* KA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_KA, 0x0}, {PUNJABI_C_KA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_KHA_Tbl[] = 
{
    /* KHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_KHA, 0x0}, {PUNJABI_C_KHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_GA_Tbl[] = 
{
    /* GA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_GA, 0x0}, {PUNJABI_C_GA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_GHA_Tbl[] = 
{
    /* GHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_GHA, 0x0}, {PUNJABI_C_GHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_NGA_Tbl[] = 
{
    /* NGA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NGA, 0x0}, {PUNJABI_C_NGA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_CA_Tbl[] = 
{
    /* CA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_CA, 0x0}, {PUNJABI_C_CA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_CHA_Tbl[] = 
{
    /* CHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_CHA, 0x0}, {PUNJABI_C_CHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_JA_Tbl[] = 
{
    /* JA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_JA, 0x0}, {PUNJABI_C_JA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_JHA_Tbl[] = 
{
    /* JHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_JHA, 0x0}, {PUNJABI_C_JHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_NYA_Tbl[] = 
{
    /* NYA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NYA, 0x0}, {PUNJABI_C_NYA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_TTA_Tbl[] = 
{
    /* TTA + space -> TTa */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_TTA, 0x0}, {PUNJABI_C_TTA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_TTHA_Tbl[] = 
{
    /* TTHA -> TTHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_TTHA, 0x0}, {PUNJABI_C_TTHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_DDA_Tbl[] = 
{
    /* DDA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DDA, 0x0}, {PUNJABI_C_DDA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_DDHA_Tbl[] = 
{
    /* DDHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DDHA, 0x0}, {PUNJABI_C_DDHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_NNA_Tbl[] = 
{
    /* NNA+ space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NNA, 0x0}, {PUNJABI_C_NNA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_TA_Tbl[] = 
{
    /* TA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_TA, 0x0}, {PUNJABI_C_TA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_THA_Tbl[] = 
{
    /* THA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_THA, 0x0}, {PUNJABI_C_THA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_DA_Tbl[] = 
{
    /* DA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DA, 0x0}, {PUNJABI_C_DA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_DHA_Tbl[] = 
{
    /* DHA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_DHA, 0x0}, {PUNJABI_C_DHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_NA_Tbl[] = 
{
    /* NA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_NA, 0x0}, {PUNJABI_C_NA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_PA_Tbl[] = 
{
    /* PA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_PA, 0x0}, {PUNJABI_C_PA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_PHA_Tbl[] = 
{
    /* PHA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_PHA, 0x0}, {PUNJABI_C_PHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_BA_Tbl[] = 
{
    /* BA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_BA, 0x0}, {PUNJABI_C_BA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_BHA_Tbl[] = 
{
    /* BHA  + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_BHA, 0x0}, {PUNJABI_C_BHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MA_Tbl[] = 
{
    /* MA  + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_MA, 0x0}, {PUNJABI_C_MA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_YA_Tbl[] = 
{
    /* YA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_YA, 0x0}, {PUNJABI_C_YA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_RA_Tbl[] = 
{
    /* RA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_RA, 0x0}, {PUNJABI_C_RA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_LA_Tbl[] = 
{
    /* LA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_LA, 0x0}, {PUNJABI_C_LA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_LLA_Tbl[] = 
{
    /* LLA */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_LLA, 0x0}, {PUNJABI_C_LLA, 0x0}},
    /* LLA + Halant -> LLA */
};

const ire_glyph_info_table_struct PUNJABI_VA_Tbl[] = 
{
    /* VA */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_VA, 0x0}, {PUNJABI_C_VA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_SHA_Tbl[] = 
{
    /* SHA */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_SHA, 0x0}, {PUNJABI_C_SHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_SA_Tbl[] = 
{
    /* SA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_SA, 0x0}, {PUNJABI_C_SA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_HA_Tbl[] = 
{
    /* HA + space  */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_C_HA, 0x0}, {PUNJABI_C_HA, 0x0}},
};

                           /* ADDITIONAL CONSONANT'S TABLE */

const ire_glyph_info_table_struct PUNJABI_KHHA_Tbl[] = 
{
    /* KHHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_KHHA, 0x0}, {PUNJABI_AC_KHHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_GHHA_Tbl[] = 
{
    /* GHHA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_GHHA, 0x0}, {PUNJABI_AC_GHHA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_ZA_Tbl[] = 
{
    /* ZA + space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_ZA, 0x0}, {PUNJABI_AC_ZA, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_L_ZA_VA, 0x0}},
    /*{0, 4, 2, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_L_ZA_VA, PUNJABI_DV_U, 0x0}},
    {0, 4, 2, MMI_ALL_LANG, {PUNJABI_AC_ZA, PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_L_ZA_VA, PUNJABI_DV_UU, 0x0}},*/
};

const ire_glyph_info_table_struct PUNJABI_RRA_Tbl[] = 
{
    /* RRA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_RRA, 0x0}, {PUNJABI_AC_RRA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_FA_Tbl[] = 
{
    /* FA +space */
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_FA, 0x0}, {PUNJABI_AC_FA, 0x0}},
};

              /* VARIOUS SIGNS TABLES */
const ire_glyph_info_table_struct PUNJABI_ADAK_BINDU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_S_ADAK_BINDI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_BINDI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_BINDI, 0x0}, {PUNJABI_S_BINDI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_VISARGA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_VISARGA, 0x0}, {PUNJABI_S_VISARGA, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_NUKTA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_NUKTA, 0x0}, {PUNJABI_S_NUKTA, 0x0}}
};

                        /* INDEPENDENT VOWEL'S TABLE */

const ire_glyph_info_table_struct PUNJABI_A_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_A, 0x0}, {PUNJABI_IV_A, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_AA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_AA, 0x0}, {PUNJABI_IV_AA, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_I_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_I, 0x0}, {PUNJABI_IV_I, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_I, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_I_TIPPI, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_I, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_I_ADDAK, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_I, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_IV_I_BINDI, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_I, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_L_IV_I_CBINDI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_II_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_II, 0x0}, {PUNJABI_IV_II, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_IV_II, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_II_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_II, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_II, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_II, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_II, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_II, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_II, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_U_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_U, 0x0}, {PUNJABI_IV_U, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_U, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_U, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_U, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_U, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_U, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_U, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_U, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_U, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_UU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_UU, 0x0}, {PUNJABI_IV_UU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_UU, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_UU, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_UU, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_UU, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_UU, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_UU, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_UU, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_UU, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_EE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_EE, 0x0}, {PUNJABI_IV_EE, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_EE, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_EE, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_EE, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_EE, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_EE, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_EE, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_EE, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_EE, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_AI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_AI, 0x0}, {PUNJABI_IV_AI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AI, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_AI, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AI, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_AI, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AI, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_AI, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AI, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_AI, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_OO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_OO, 0x0}, {PUNJABI_IV_OO, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_OO, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_OO, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_OO, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_OO, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_OO, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_OO, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_OO, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_OO, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_AU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_IV_AU, 0x0}, {PUNJABI_IV_AU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AU, PUNJABI_S_BINDI, 0x0}, {PUNJABI_IV_AU, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AU, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_IV_AU, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AU, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_IV_AU, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_IV_AU, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_IV_AU, PUNJABI_L_CBINDU, 0x0}}
};

                      /* DEPENDENT VOWEL SIGN/MATRAS TABLES */

const ire_glyph_info_table_struct PUNJABI_MAA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_AA, 0x0}, {PUNJABI_DV_AA, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_AA, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_NBINDU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AA, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_AC_TIPPI, PUNJABI_DV_AA, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AA, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_AC_ADDAK, PUNJABI_DV_AA, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_I, 0x0}, {PUNJABI_DV_I, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_MII_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_II, 0x0}, {PUNJABI_DV_II, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_II, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_IIBINDU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_II, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_DV_II, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_II, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_DV_II, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_II, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_DV_II, PUNJABI_L_CBINDU, 0x0}}
	
};

const ire_glyph_info_table_struct PUNJABI_MU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_U, 0x0}, {PUNJABI_DV_U, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MUU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_UU, 0x0}, {PUNJABI_DV_UU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MEE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_EE, 0x0}, {PUNJABI_DV_EE, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_EE, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_EEBINDU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_EE, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_DV_EE, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_EE, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_DV_EE, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_EE, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_DV_EE, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MAI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_AI, 0x0}, {PUNJABI_DV_AI, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_AI, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_AIBINDU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AI, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_DV_AI, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AI, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_DV_AI, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AI, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_DV_AI, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MOO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_OO, 0x0}, {PUNJABI_DV_OO, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_OO, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_OOBINDU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_OO, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_DV_OO, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_OO, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_DV_OO, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_OO, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_DV_OO, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_MAU_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_DV_AU, 0x0}, {PUNJABI_DV_AU, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_DV_AU, PUNJABI_S_BINDI, 0x0}, {PUNJABI_L_AUBINDU, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AU, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_DV_AU, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AU, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_DV_AU, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_DV_AU, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_DV_AU, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_HAL_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, 0x0}, {PUNJABI_S_HALANT, 0x0}},
	{0, 2, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_YA, 0x0}, {PUNJABI_L_YA, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_RA, 0x0}, {PUNJABI_L_RA, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_VA, 0x0}, {PUNJABI_L_VA, 0x0}},
    {0, 2, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_HA, 0x0}, {PUNJABI_L_HA, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_RA, PUNJABI_DV_U, 0x0}, {PUNJABI_L_RU, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_VA, PUNJABI_DV_U, 0x0}, {PUNJABI_L_VU, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_HA, PUNJABI_DV_U, 0x0}, {PUNJABI_L_HU, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_RA, PUNJABI_DV_UU, 0x0}, {PUNJABI_L_RUU, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_VA, PUNJABI_DV_UU, 0x0}, {PUNJABI_L_VUU, 0x0}},
    {0, 3, 1, MMI_ALL_LANG, {PUNJABI_S_HALANT, PUNJABI_C_HA, PUNJABI_DV_UU, 0x0}, {PUNJABI_L_HUU, 0x0}},
};

const ire_glyph_info_table_struct PUNJABI_DANDA_Tbl[] = 
{

    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_S_DANDA, 0x0}, {PUNJABI_S_DANDA, 0x0}}

};

                       /* NUMERALS TABLE */
const ire_glyph_info_table_struct PUNJABI_ZERO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_ZERO, 0x0}, {PUNJABI_D_ZERO, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_ONE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_ONE, 0x0}, {PUNJABI_D_ONE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_TWO_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_TWO, 0x0}, {PUNJABI_D_TWO, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_THREE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_THREE, 0x0}, {PUNJABI_D_THREE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_FOUR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_FOUR, 0x0}, {PUNJABI_D_FOUR, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_FIVE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_FIVE, 0x0}, {PUNJABI_D_FIVE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_SIX_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_SIX, 0x0}, {PUNJABI_D_SIX, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_SEVEN_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_SEVEN, 0x0}, {PUNJABI_D_SEVEN, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_EIGHT_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_EIGHT, 0x0}, {PUNJABI_D_EIGHT, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_NINE_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_D_NINE, 0x0}, {PUNJABI_D_NINE, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_TIPPI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_AC_TIPPI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_ADDAK_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_AC_ADDAK, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_IRI_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_IRI, 0x0}, {PUNJABI_AC_IRI, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_URA_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_URA, 0x0}, {PUNJABI_AC_URA, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_AC_URA, PUNJABI_S_BINDI, 0x0}, {PUNJABI_AC_URA, PUNJABI_L_BINDI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_AC_URA, PUNJABI_AC_TIPPI, 0x0}, {PUNJABI_AC_URA, PUNJABI_L_TIPPI, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_AC_URA, PUNJABI_AC_ADDAK, 0x0}, {PUNJABI_AC_URA, PUNJABI_L_ADDAK, 0x0}},
    {0, 2, 2, MMI_ALL_LANG, {PUNJABI_AC_URA, PUNJABI_S_ADAK_BINDI, 0x0}, {PUNJABI_AC_URA, PUNJABI_L_CBINDU, 0x0}}
};

const ire_glyph_info_table_struct PUNJABI_ONKAR_Tbl[] = 
{
    {0, 1, 1, MMI_ALL_LANG, {PUNJABI_AC_ONKAR, 0x0}, {PUNJABI_AC_ONKAR, 0x0}}
};

const ire_main_glyph_table_struct PunjabiTbl[] = 
{
    /* VARIOUS SIGNS */
    {PUNJABI_ADAK_BINDU_Tbl, sizeof(PUNJABI_ADAK_BINDU_Tbl) / sizeof(PUNJABI_ADAK_BINDU_Tbl[0]), 1}     /* 0x0A01 */
    ,
    {PUNJABI_BINDI_Tbl, sizeof(PUNJABI_BINDI_Tbl) / sizeof(PUNJABI_BINDI_Tbl[0]), 1}    /* 0x0A02 */
    ,
    {PUNJABI_VISARGA_Tbl, sizeof(PUNJABI_VISARGA_Tbl) / sizeof(PUNJABI_VISARGA_Tbl[0]), 1}      /* 0x0A03 */
    ,
    {NULL, 0, 0}    /* 0x0A04 */
    ,
    /* INDEPENDENT VOWELS */
    {PUNJABI_A_Tbl, sizeof(PUNJABI_A_Tbl) / sizeof(PUNJABI_A_Tbl[0]), 1}        /* 0x0A05 */
    ,
    {PUNJABI_AA_Tbl, sizeof(PUNJABI_AA_Tbl) / sizeof(PUNJABI_AA_Tbl[0]), 1}     /* 0x0A06 */
    ,
    {PUNJABI_I_Tbl, sizeof(PUNJABI_I_Tbl) / sizeof(PUNJABI_I_Tbl[0]), 2}        /* 0x0A07 */
    ,
    {PUNJABI_II_Tbl, sizeof(PUNJABI_II_Tbl) / sizeof(PUNJABI_II_Tbl[0]), 2}     /* 0x0A08 */
    ,
    {PUNJABI_U_Tbl, sizeof(PUNJABI_U_Tbl) / sizeof(PUNJABI_U_Tbl[0]), 2}        /* 0x0A09 */
    ,
    {PUNJABI_UU_Tbl, sizeof(PUNJABI_UU_Tbl) / sizeof(PUNJABI_UU_Tbl[0]), 2}     /* 0x0A0A */
    ,
    {NULL, 0, 0}    /* 0x0A0B */
    ,
    {NULL, 0, 0}    /* 0x0A0C */
    ,
    {NULL, 0, 0}    /* 0x0A0D */
    ,
    {NULL, 0, 0}    /* 0x0A0E */
    ,
    {PUNJABI_EE_Tbl, sizeof(PUNJABI_EE_Tbl) / sizeof(PUNJABI_EE_Tbl[0]), 2}     /* 0x0A0F */
    ,
    {PUNJABI_AI_Tbl, sizeof(PUNJABI_AI_Tbl) / sizeof(PUNJABI_AI_Tbl[0]), 2}     /* 0x0A10 */
    ,
    {NULL, 0, 0}    /* 0x0A11 */
    ,
    {NULL, 0, 0}    /* 0x0A12 */
    ,
    {PUNJABI_OO_Tbl, sizeof(PUNJABI_OO_Tbl) / sizeof(PUNJABI_OO_Tbl[0]), 2}     /* 0x0A13 */
    ,
    {PUNJABI_AU_Tbl, sizeof(PUNJABI_AU_Tbl) / sizeof(PUNJABI_AU_Tbl[0]), 2}     /* 0x0A14 */
    ,
    /* CONSONANTS */
    {PUNJABI_KA_Tbl, sizeof(PUNJABI_KA_Tbl) / sizeof(PUNJABI_KA_Tbl[0]), 1}     /* 0x0A15 */
    ,
    {PUNJABI_KHA_Tbl, sizeof(PUNJABI_KHA_Tbl) / sizeof(PUNJABI_KHA_Tbl[0]), 1}  /* 0x0A16 */
    ,
    {PUNJABI_GA_Tbl, sizeof(PUNJABI_GA_Tbl) / sizeof(PUNJABI_GA_Tbl[0]), 1}     /* 0x0A17 */
    ,
    {PUNJABI_GHA_Tbl, sizeof(PUNJABI_GHA_Tbl) / sizeof(PUNJABI_GHA_Tbl[0]), 1}  /* 0x0A18 */
    ,
    {PUNJABI_NGA_Tbl, sizeof(PUNJABI_NGA_Tbl) / sizeof(PUNJABI_NGA_Tbl[0]), 1}  /* 0x0A19 */
    ,
    {PUNJABI_CA_Tbl, sizeof(PUNJABI_CA_Tbl) / sizeof(PUNJABI_CA_Tbl[0]), 1}     /* 0x0A1A */
    ,
    {PUNJABI_CHA_Tbl, sizeof(PUNJABI_CHA_Tbl) / sizeof(PUNJABI_CHA_Tbl[0]), 1}  /* 0x0A1B */
    ,
    {PUNJABI_JA_Tbl, sizeof(PUNJABI_JA_Tbl) / sizeof(PUNJABI_JA_Tbl[0]), 1}     /* 0x0A1C */
    ,
    {PUNJABI_JHA_Tbl, sizeof(PUNJABI_JHA_Tbl) / sizeof(PUNJABI_JHA_Tbl[0]), 1}  /* 0x0A1D */
    ,
    {PUNJABI_NYA_Tbl, sizeof(PUNJABI_NYA_Tbl) / sizeof(PUNJABI_NYA_Tbl[0]), 1}  /* 0x0A1E */
    ,
    {PUNJABI_TTA_Tbl, sizeof(PUNJABI_TTA_Tbl) / sizeof(PUNJABI_TTA_Tbl[0]), 1}  /* 0x0A1F */
    ,
    {PUNJABI_TTHA_Tbl, sizeof(PUNJABI_TTHA_Tbl) / sizeof(PUNJABI_TTHA_Tbl[0]), 1}       /* 0x0A20 */
    ,
    {PUNJABI_DDA_Tbl, sizeof(PUNJABI_DDA_Tbl) / sizeof(PUNJABI_DDA_Tbl[0]), 1}  /* 0x0A21 */
    ,
    {PUNJABI_DDHA_Tbl, sizeof(PUNJABI_DDHA_Tbl) / sizeof(PUNJABI_DDHA_Tbl[0]), 1}       /* 0x0A22 */
    ,
    {PUNJABI_NNA_Tbl, sizeof(PUNJABI_NNA_Tbl) / sizeof(PUNJABI_NNA_Tbl[0]), 1}  /* 0x0A23 */
    ,
    {PUNJABI_TA_Tbl, sizeof(PUNJABI_TA_Tbl) / sizeof(PUNJABI_TA_Tbl[0]), 1}     /* 0x0A24 */
    ,
    {PUNJABI_THA_Tbl, sizeof(PUNJABI_THA_Tbl) / sizeof(PUNJABI_THA_Tbl[0]), 1}  /* 0x0A25 */
    ,
    {PUNJABI_DA_Tbl, sizeof(PUNJABI_DA_Tbl) / sizeof(PUNJABI_DA_Tbl[0]), 1}     /* 0x0A26 */
    ,
    {PUNJABI_DHA_Tbl, sizeof(PUNJABI_DHA_Tbl) / sizeof(PUNJABI_DHA_Tbl[0]), 1}  /* 0x0A27 */
    ,
    {PUNJABI_NA_Tbl, sizeof(PUNJABI_NA_Tbl) / sizeof(PUNJABI_NA_Tbl[0]), 1}     /* 0x0A28 */
    ,
    {NULL, 0, 0}    /* 0x0A29 */
    ,
    {PUNJABI_PA_Tbl, sizeof(PUNJABI_PA_Tbl) / sizeof(PUNJABI_PA_Tbl[0]), 1}     /* 0x0A2A */
    ,
    {PUNJABI_PHA_Tbl, sizeof(PUNJABI_PHA_Tbl) / sizeof(PUNJABI_PHA_Tbl[0]), 1}  /* 0x0A2B */
    ,
    {PUNJABI_BA_Tbl, sizeof(PUNJABI_BA_Tbl) / sizeof(PUNJABI_BA_Tbl[0]), 1}     /* 0x0A2C */
    ,
    {PUNJABI_BHA_Tbl, sizeof(PUNJABI_BHA_Tbl) / sizeof(PUNJABI_BHA_Tbl[0]), 1}  /* 0x0A2D */
    ,
    {PUNJABI_MA_Tbl, sizeof(PUNJABI_MA_Tbl) / sizeof(PUNJABI_MA_Tbl[0]), 1}     /* 0x0A2E */
    ,
    {PUNJABI_YA_Tbl, sizeof(PUNJABI_YA_Tbl) / sizeof(PUNJABI_YA_Tbl[0]), 1}     /* 0x0A2F */
    ,
    {PUNJABI_RA_Tbl, sizeof(PUNJABI_RA_Tbl) / sizeof(PUNJABI_RA_Tbl[0]), 1}     /* 0x0A30 */
    ,
    {NULL, 0, 0}    /* 0x0A31 */
    ,
    {PUNJABI_LA_Tbl, sizeof(PUNJABI_LA_Tbl) / sizeof(PUNJABI_LA_Tbl[0]), 1}     /* 0x0A32 */
    ,
    {PUNJABI_LLA_Tbl, sizeof(PUNJABI_LLA_Tbl) / sizeof(PUNJABI_LLA_Tbl[0]), 1}  /* 0x0A33 */
    ,
    {NULL, 0, 0}    /* 0x0A34 */
    ,
    {PUNJABI_VA_Tbl, sizeof(PUNJABI_VA_Tbl) / sizeof(PUNJABI_VA_Tbl[0]), 1}     /* 0x0A35 */
    ,
    {PUNJABI_SHA_Tbl, sizeof(PUNJABI_SHA_Tbl) / sizeof(PUNJABI_SHA_Tbl[0]), 1}  /* 0x0A36 */
    ,
    {NULL, 0, 0}    /* 0x0A37 */
    ,
    {PUNJABI_SA_Tbl, sizeof(PUNJABI_SA_Tbl) / sizeof(PUNJABI_SA_Tbl[0]), 1}     /* 0x0A38 */
    ,
    {PUNJABI_HA_Tbl, sizeof(PUNJABI_HA_Tbl) / sizeof(PUNJABI_HA_Tbl[0]), 1}     /* 0x0A39 */
    ,
    {NULL, 0, 0}    /* 0x0A3A */
    ,
    {NULL, 0, 0}    /* 0x0A3B */
    ,
    /* VARIOUS SIGNS */
    {PUNJABI_NUKTA_Tbl, sizeof(PUNJABI_NUKTA_Tbl) / sizeof(PUNJABI_NUKTA_Tbl[0]), 1}    /* 0x0A3C */
    ,
    {NULL, 0, 0}    /* 0x0A3D */
    ,
    /* DEPENDENT VOWEL SIGNS */
    {PUNJABI_MAA_Tbl, sizeof(PUNJABI_MAA_Tbl) / sizeof(PUNJABI_MAA_Tbl[0]), 2}  /* 0x0A3E */
    ,
    {PUNJABI_MI_Tbl, sizeof(PUNJABI_MI_Tbl) / sizeof(PUNJABI_MI_Tbl[0]), 1}     /* 0x0A3F */
    ,
    {PUNJABI_MII_Tbl, sizeof(PUNJABI_MII_Tbl) / sizeof(PUNJABI_MII_Tbl[0]), 2}  /* 0x0A40 */
    ,
    {PUNJABI_MU_Tbl, sizeof(PUNJABI_MU_Tbl) / sizeof(PUNJABI_MU_Tbl[0]), 1}     /* 0x0A41 */
    ,
    {PUNJABI_MUU_Tbl, sizeof(PUNJABI_MUU_Tbl) / sizeof(PUNJABI_MUU_Tbl[0]), 1}  /* 0x0A42 */
    ,
    {NULL, 0, 0}    /* 0x0A43 */
    ,
    {NULL, 0, 0}    /* 0x0A44 */
    ,
    {NULL, 0, 0}    /* 0x0A45 */
    ,
    {NULL, 0, 0}    /* 0x0A46 */
    ,
    {PUNJABI_MEE_Tbl, sizeof(PUNJABI_MEE_Tbl) / sizeof(PUNJABI_MEE_Tbl[0]), 2}  /* 0x0A47 */
    ,
    {PUNJABI_MAI_Tbl, sizeof(PUNJABI_MAI_Tbl) / sizeof(PUNJABI_MAI_Tbl[0]), 2}  /* 0x0A48 */
    ,
    {NULL, 0, 0}    /* 0x0A49 */
    ,
    {NULL, 0, 0}    /* 0x0A4A */
    ,
    {PUNJABI_MOO_Tbl, sizeof(PUNJABI_MOO_Tbl) / sizeof(PUNJABI_MOO_Tbl[0]), 2}  /* 0x0A4B */
    ,
    {PUNJABI_MAU_Tbl, sizeof(PUNJABI_MAU_Tbl) / sizeof(PUNJABI_MAU_Tbl[0]), 2}  /* 0x0A4C */
    ,
    /* VARIOUS SIGNS */
    {PUNJABI_HAL_Tbl, sizeof(PUNJABI_HAL_Tbl) / sizeof(PUNJABI_HAL_Tbl[0]), 3}  /* 0x0A4D */
    ,
    {NULL, 0, 0}    /* 0x0A4E */
    ,
    {NULL, 0, 0}    /* 0x0A4F */
    ,
    {NULL, 0, 0}    /* 0x0A50 */
    ,
    {NULL, 0, 0}    /* 0x0A51 */
    ,
    {NULL, 0, 0}    /* 0x0A52 */
    ,
    {NULL, 0, 0}    /* 0x0A53 */
    ,
    {NULL, 0, 0}    /* 0x0A54 */
    ,
    {NULL, 0, 0}    /* 0x0A55 */
    ,
    {NULL, 0, 0}    /* 0x0A56 */
    ,
    {NULL, 0, 0}    /* 0x0A57 */
    ,
    {NULL, 0, 0}    /* 0x0A58 */
    ,
    /* ADDITIONAL CONSONANTS */
    {PUNJABI_KHHA_Tbl, sizeof(PUNJABI_KHHA_Tbl) / sizeof(PUNJABI_KHHA_Tbl[0]), 1}       /* 0x0A59 */
    ,
    {PUNJABI_GHHA_Tbl, sizeof(PUNJABI_GHHA_Tbl) / sizeof(PUNJABI_GHHA_Tbl[0]), 1}       /* 0x0A5A */
    ,
    {PUNJABI_ZA_Tbl, sizeof(PUNJABI_ZA_Tbl) / sizeof(PUNJABI_ZA_Tbl[0]), 3}     /* 0x0A5B */
    ,
    {PUNJABI_RRA_Tbl, sizeof(PUNJABI_RRA_Tbl) / sizeof(PUNJABI_RRA_Tbl[0]), 1}  /* 0x0A5C */
    ,
    {NULL, 0, 0}    /* 0x0A5D */
    ,
    {PUNJABI_FA_Tbl, sizeof(PUNJABI_FA_Tbl) / sizeof(PUNJABI_FA_Tbl[0]), 1}     /* 0x0A5E */
    ,
    {NULL, 0, 0}    /* 0x0A5F */
    ,
    {NULL, 0, 0}    /* 0x0A60 */
    ,
    {NULL, 0, 0}    /* 0x0A61 */
    ,
    {NULL, 0, 0}    /* 0x0A62 */
    ,
    {NULL, 0, 0}    /* 0x0A63 */
    ,
    {PUNJABI_DANDA_Tbl, sizeof(PUNJABI_DANDA_Tbl) / sizeof(PUNJABI_DANDA_Tbl[0]), 1}    /* 0x0A64 */
    ,
    {NULL, 0, 0}    /* 0x0A65 */
    ,
    /* DIGITS */
    {PUNJABI_ZERO_Tbl, sizeof(PUNJABI_ZERO_Tbl) / sizeof(PUNJABI_ZERO_Tbl[0]), 1}       /* 0x0A66 */
    ,
    {PUNJABI_ONE_Tbl, sizeof(PUNJABI_ONE_Tbl) / sizeof(PUNJABI_ONE_Tbl[0]), 1}  /* 0x0A67 */
    ,
    {PUNJABI_TWO_Tbl, sizeof(PUNJABI_TWO_Tbl) / sizeof(PUNJABI_TWO_Tbl[0]), 1}  /* 0x0A68 */
    ,
    {PUNJABI_THREE_Tbl, sizeof(PUNJABI_THREE_Tbl) / sizeof(PUNJABI_THREE_Tbl[0]), 1}    /* 0x0A69 */
    ,
    {PUNJABI_FOUR_Tbl, sizeof(PUNJABI_FOUR_Tbl) / sizeof(PUNJABI_FOUR_Tbl[0]), 1}       /* 0x0A6A */
    ,
    {PUNJABI_FIVE_Tbl, sizeof(PUNJABI_FIVE_Tbl) / sizeof(PUNJABI_FIVE_Tbl[0]), 1}       /* 0x0A6B */
    ,
    {PUNJABI_SIX_Tbl, sizeof(PUNJABI_SIX_Tbl) / sizeof(PUNJABI_SIX_Tbl[0]), 1}  /* 0x0A6C */
    ,
    {PUNJABI_SEVEN_Tbl, sizeof(PUNJABI_SEVEN_Tbl) / sizeof(PUNJABI_SEVEN_Tbl[0]), 1}    /* 0x0A6D */
    ,
    {PUNJABI_EIGHT_Tbl, sizeof(PUNJABI_EIGHT_Tbl) / sizeof(PUNJABI_EIGHT_Tbl[0]), 1}    /* 0x0A6E */
    ,
    {PUNJABI_NINE_Tbl, sizeof(PUNJABI_NINE_Tbl) / sizeof(PUNJABI_NINE_Tbl[0]), 1}       /* 0x0A6F */
    ,
    /* SPECIFIC ADDITIONS */
    {PUNJABI_TIPPI_Tbl, sizeof(PUNJABI_TIPPI_Tbl) / sizeof(PUNJABI_TIPPI_Tbl[0]), 1}    /* 0x0A70 */
    ,
    {PUNJABI_ADDAK_Tbl, sizeof(PUNJABI_ADDAK_Tbl) / sizeof(PUNJABI_ADDAK_Tbl[0]), 1}    /* 0x0A71 */
    ,
    {PUNJABI_IRI_Tbl, sizeof(PUNJABI_IRI_Tbl) / sizeof(PUNJABI_IRI_Tbl[0]), 1}  /* 0x0A72 */
    ,
    {PUNJABI_URA_Tbl, sizeof(PUNJABI_URA_Tbl) / sizeof(PUNJABI_URA_Tbl[0]), 2}  /* 0x0A73 */
    ,
    {PUNJABI_ONKAR_Tbl, sizeof(PUNJABI_ONKAR_Tbl) / sizeof(PUNJABI_ONKAR_Tbl[0]), 1}    /* 0x0A74 */
	,
    {NULL, 0, 0}	/* 0x0A75 */
    
};

#if defined (__MMI_MULTITAP_PUNJABI__)

#if defined (__MMI_ZI_PUNJABI__)

const UI_character_type default_punjabi_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, '1', '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_AC_ZA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, '1', PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_S_HALANT, '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', PUNJABI_DV_AA, PUNJABI_DV_I, PUNJABI_DV_II, PUNJABI_DV_U, PUNJABI_DV_UU, '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', PUNJABI_DV_EE, PUNJABI_DV_AI, PUNJABI_DV_OO, PUNJABI_DV_AU, '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_AC_ZA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra1_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, '1', PUNJABI_AC_ADDAK, PUNJABI_S_BINDI, '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_AC_ZA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_punjabimatra2_multitap_strings[MAX_MULTITAPS][45] = 
{
    {' ', PUNJABI_C_SA, PUNJABI_C_SHA, PUNJABI_C_HA, '0', '\0'},   /* key 0 */
    {PUNJABI_S_DANDA, '1', PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, '\0'},   /* key 1 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, '2', '\0'},   /* key 2*/
    {PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, '3', '\0'},   /* key 3 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_AC_KHHA, PUNJABI_C_GA, PUNJABI_AC_GHHA, PUNJABI_C_GHA, PUNJABI_C_NGA, '4', '\0'},   /* key 4 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_AC_ZA, PUNJABI_C_JHA, PUNJABI_C_NYA, '5', '\0'},   /* key 5 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, '6', '\0'},   /* key 6 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, '7', '\0'},   /* key 7 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_AC_FA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, '8', '\0'},   /* key 8 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_LLA, PUNJABI_C_VA, PUNJABI_AC_RRA, '9', '\0'},   /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#else /* defined (__MMI_ZI_PUNJABI__) */ 

const UI_character_type default_punjabi_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', PUNJABI_DEVANAGARI_S_DANDA, PUNJABI_D_ZERO, PUNJABI_DEVANAGARI_S_DOUBLE_DANDA, '0', '\0'},   /* key 0 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_D_EIGHT, '8', '\0'},       /* key 8 */
    {PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', PUNJABI_DEVANAGARI_S_DANDA, PUNJABI_D_ZERO, PUNJABI_DEVANAGARI_S_DOUBLE_DANDA, '0', '\0'},   /* key 0 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_DV_AA, PUNJABI_DV_I, PUNJABI_DV_II, PUNJABI_DV_U, PUNJABI_DV_UU, PUNJABI_DV_EE, PUNJABI_DV_AI, PUNJABI_DV_OO, PUNJABI_DV_AU, PUNJABI_D_EIGHT, '8', '\0'},  /* key 8 */
    {PUNJABI_S_VISARGA, PUNJABI_S_HALANT, PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
const UI_character_type default_punjabimatra1_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', PUNJABI_DEVANAGARI_S_DANDA, PUNJABI_D_ZERO, PUNJABI_DEVANAGARI_S_DOUBLE_DANDA, '0', '\0'},   /* key 0 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_D_EIGHT, '8', '\0'},       /* key 8 */
    {PUNJABI_S_BINDI, PUNJABI_S_VISARGA, PUNJABI_AC_ADDAK, PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},      /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_punjabimatra2_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', PUNJABI_DEVANAGARI_S_DANDA, PUNJABI_D_ZERO, PUNJABI_DEVANAGARI_S_DOUBLE_DANDA, '0', '\0'},   /* key 0 */
    {PUNJABI_C_KA, PUNJABI_C_KHA, PUNJABI_C_GA, PUNJABI_C_GHA, PUNJABI_C_NGA, PUNJABI_AC_KHHA, PUNJABI_AC_GHHA, PUNJABI_D_ONE, '1', '\0'},      /* key 1 */
    {PUNJABI_C_CA, PUNJABI_C_CHA, PUNJABI_C_JA, PUNJABI_C_JHA, PUNJABI_C_NYA, PUNJABI_AC_ZA, PUNJABI_D_TWO, '2', '\0'}, /* key 2 */
    {PUNJABI_C_TTA, PUNJABI_C_TTHA, PUNJABI_C_DDA, PUNJABI_C_DDHA, PUNJABI_C_NNA, PUNJABI_D_THREE, '3', '\0'},  /* key 3 */
    {PUNJABI_C_TA, PUNJABI_C_THA, PUNJABI_C_DA, PUNJABI_C_DHA, PUNJABI_C_NA, PUNJABI_D_FOUR, '4', '\0'},        /* key 4 */
    {PUNJABI_C_PA, PUNJABI_C_PHA, PUNJABI_C_BA, PUNJABI_C_BHA, PUNJABI_C_MA, PUNJABI_AC_FA, PUNJABI_D_FIVE, '5', '\0'}, /* key 5 */
    {PUNJABI_C_YA, PUNJABI_C_RA, PUNJABI_C_LA, PUNJABI_C_VA, PUNJABI_AC_RRA, PUNJABI_C_SA, PUNJABI_C_HA, PUNJABI_C_LLA, PUNJABI_C_SHA, PUNJABI_D_SIX, '6', '\0'},     /* Key 6 */
    {PUNJABI_IV_A, PUNJABI_IV_AA, PUNJABI_IV_I, PUNJABI_IV_II, PUNJABI_IV_U, PUNJABI_IV_UU, PUNJABI_IV_EE, PUNJABI_IV_AI, PUNJABI_IV_OO, PUNJABI_IV_AU, PUNJABI_AC_IRI, PUNJABI_AC_URA, PUNJABI_D_SEVEN, '7', '\0'},    /* key 7 */
    {PUNJABI_D_EIGHT, '8', '\0'},       /* key 8 */
    {PUNJABI_S_VISARGA, PUNJABI_AC_TIPPI, PUNJABI_AC_ADDAK, PUNJABI_AC_ONKAR, PUNJABI_D_NINE, '9', '\0'},      /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

#endif /* defined (__MMI_ZI_PUNJABI__) */ 


/*****************************************************************************
 * FUNCTION
 *  get_punjabi_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type get_punjabi_multitap_string(S32 index)
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
        if (previous_char >= PUNJABI_C_KA && previous_char <= PUNJABI_C_HA || previous_char >= PUNJABI_AC_KHHA &&
            previous_char <= PUNJABI_AC_FA)
        {
            return (UI_character_type*)default_punjabimatra_multitap_strings[index];
        }
        else
        {
            switch (previous_char)
            {
                case (PUNJABI_DV_AA):
                case (PUNJABI_DV_II):
                case (PUNJABI_DV_EE):
                case (PUNJABI_DV_AI):
                case (PUNJABI_DV_OO):
                case (PUNJABI_DV_AU):
                case (PUNJABI_IV_AA):
                case (PUNJABI_IV_EE):
                case (PUNJABI_IV_II):
                case (PUNJABI_IV_AI):
                case (PUNJABI_IV_AU):
                case (PUNJABI_IV_U):
                case (PUNJABI_IV_UU):
                case (PUNJABI_IV_OO):
                {
                    return (UI_character_type*)default_punjabimatra1_multitap_strings[index];

                }
                case (PUNJABI_DV_I):
                case (PUNJABI_DV_U):
                case (PUNJABI_DV_UU):
                case (PUNJABI_IV_A):
                case (PUNJABI_IV_I):
                {
                    return (UI_character_type*)default_punjabimatra2_multitap_strings[index];

                }
                default:
                {
                    return (UI_character_type*)default_punjabi_multitap_strings[index];
                }
            }
        }

    }
    else
    {
        return  (UI_character_type*)default_punjabi_multitap_strings[index];
    }

}


/*****************************************************************************
 * FUNCTION
 *  get_punjabi_single_line_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_punjabi_single_line_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
    /* For performance improval */
    if (previous_char)
    {
        if (previous_char >= PUNJABI_C_KA && previous_char <= PUNJABI_C_HA || previous_char >= PUNJABI_AC_KHHA &&
            previous_char <= PUNJABI_AC_FA)
        {
            return ((UI_character_type*) default_punjabimatra_multitap_strings[i]);
        }
        else
        {
            switch (previous_char)
            {
                case (PUNJABI_DV_AA):
                case (PUNJABI_DV_II):
                case (PUNJABI_DV_EE):
                case (PUNJABI_DV_AI):
                case (PUNJABI_DV_OO):
                case (PUNJABI_DV_AU):
                case (PUNJABI_IV_AA):
                case (PUNJABI_IV_EE):
                case (PUNJABI_IV_II):
                case (PUNJABI_IV_AI):
                case (PUNJABI_IV_AU):
                case (PUNJABI_IV_U):
                case (PUNJABI_IV_UU):
                case (PUNJABI_IV_OO):
                {
                    return ((UI_character_type*) default_punjabimatra1_multitap_strings[i]);

                }
                case (PUNJABI_DV_I):
                case (PUNJABI_DV_U):
                case (PUNJABI_DV_UU):
                case (PUNJABI_IV_A):
                case (PUNJABI_IV_I):
                {
                    return ((UI_character_type*) default_punjabimatra2_multitap_strings[i]);

                }
                default:
                {
                    return ((UI_character_type*) default_punjabi_multitap_strings[i]);
                }

            }
        }

    }
    else
    {
        return ((UI_character_type*) default_punjabi_multitap_strings[i]);
    }

}
UI_character_type *get_punjabi_multitap_string_for_vk(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    	
	return ((UI_character_type*) default_punjabimatra_multitap_strings[i]);
}

#endif /* defined (__MMI_MULTITAP_PUNJABI__) */ /* #if defined (__MMI_MULTITAP_PUNJABI__)  */

#else /* defined (__MMI_LANG_PUNJABI__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_punjabi_warning_remove
 * DESCRIPTION
 *  for removing warnings
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_punjabi_warning_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy function */
}
#endif /* defined (__MMI_LANG_PUNJABI__) */ /* #if defined (__MMI_LANG_PUNJABI__) */


