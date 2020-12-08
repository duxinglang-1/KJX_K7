/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   swje_const_tables.h
 *
 * Project:
 * --------
 *   Maui
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SWJE_CONST_TABLES_H__
#define __SWJE_CONST_TABLES_H__

#include "kal_general_types.h"

#define SWJE_HUFF_DC_BITS_BITS              17
#define SWJE_HUFF_DC_VAL_BITS               12
#define SWJE_HUFF_AC_BITS_BITS              17
#define SWJE_HUFF_AC_VAL_BITS               162

#define SWJE_HUFF_DC_TRANSLATION_BITS       12
#define SWJE_HUFF_AC_TRANSLATION_BITS       256


extern const kal_int8 swje_quant_std_luminance_1_table[64];
extern const kal_int8 swje_quant_std_chrominance_1_table[64];
extern const kal_int8 swje_quant_nonstd_luminance_1_table[64];
extern const kal_int8 swje_quant_nonstd_chrominance_1_table[64];
extern const kal_uint32 swje_z_zag_table[64];
extern const kal_int32 swje_fixedpoint_quant_fdct_table[64];

extern const kal_uint8 swje_dc_luminance_bits_table[SWJE_HUFF_DC_BITS_BITS];
extern const kal_uint8 swje_dc_luminance_val_table[SWJE_HUFF_DC_VAL_BITS];
extern const kal_uint8 swje_dc_chrominance_bits_table[SWJE_HUFF_DC_BITS_BITS];
extern const kal_uint8 swje_dc_chrominance_val_table[SWJE_HUFF_DC_VAL_BITS];
extern const kal_uint8 swje_ac_luminance_bits_table[SWJE_HUFF_AC_BITS_BITS];
extern const kal_uint8 swje_ac_luminance_val_table[SWJE_HUFF_AC_VAL_BITS];
extern const kal_uint8 swje_ac_chrominance_bits_table[SWJE_HUFF_AC_BITS_BITS];
extern const kal_uint8 swje_ac_chrominance_val_table[SWJE_HUFF_AC_VAL_BITS];

extern const kal_uint16 swje_dc_luminance_symbol2code_table[SWJE_HUFF_DC_TRANSLATION_BITS];
extern const kal_uint8 swje_dc_luminance_symbol2size_table[SWJE_HUFF_DC_TRANSLATION_BITS];
extern const kal_uint16 swje_dc_chrominance_symbol2code_table[SWJE_HUFF_DC_TRANSLATION_BITS];
extern const kal_uint8 swje_dc_chrominance_symbol2size_table[SWJE_HUFF_DC_TRANSLATION_BITS];
extern const kal_uint16 swje_ac_luminance_symbol2code_table[SWJE_HUFF_AC_TRANSLATION_BITS];
extern const kal_uint8 swje_ac_luminance_symbol2size_table[SWJE_HUFF_AC_TRANSLATION_BITS];
extern const kal_uint16 swje_ac_chrominance_symbol2code_table[SWJE_HUFF_AC_TRANSLATION_BITS];
extern const kal_uint8 swje_ac_chrominance_symbol2size_table[SWJE_HUFF_AC_TRANSLATION_BITS];

extern const kal_uint32 _swje_huff_enc_bitmask_table[17];

#endif

