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

/*******************************************************************************
 * Filename:
 * ---------
 *  FontRes.h
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
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _FONTRES_H_
#define _FONTRES_H_

#include "MMIDataType.h"
// #include "FontData.h"
#include "MMI_features.h"

//#define SMALL_FONT  1
//#define MEDIUM_FONT 2
//#define LARGE_FONT  3




#ifdef __UCS2_ENCODING
#define LANGUAGE_NAME 40
#else 
#define LANGUAGE_NAME 20
#endif 


#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define FONT_LOAD(x)  NULL
#else
#define FONT_LOAD(x)  x
#endif

#define  SSC_SIZE 10
#define  LCC_SIZE 8
#define ISO_SIZE 4
// #define MAX_LANGUAGES 2

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#define  MAX_FONT_TYPES      9
#else
#define  MAX_FONT_TYPES      6
#endif

#define  SMALL_FONT        0x0000
#define  MEDIUM_FONT    0x0001
#define  LARGE_FONT        0x0002
#define  SUBLCD_FONT    0x0003
#define  DIALER_FONT    0x0004

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
#define  NUMBER_1_FONT      0x0005
#define  NUMBER_2_FONT      0x0006
#define  VIRTUAL_KEYBOARD_FONT      0x0007
#define  VIRTUAL_KEYBOARD_LARGE_FONT      0x0008
#else
#define  VIRTUAL_KEYBOARD_FONT      0x0005
#endif

#define  NORMAL_DISPLAY_FONT                    0x80000000
#define  SMALLCAPS_DISPLAY_FONT                 0x40000000

#define  FONTATTRIB_NORMAL                   0x00000001
#define  FONTATTRIB_BOLD                        0x00000002
#define  FONTATTRIB_ITALIC                      0x00000004
#define  FONTATTRIB_OBLIQUE                     0x00000008
#define  FONTATTRIB_UNDERLINE                   0x00000010
#define  FONTATTRIB_STRIKETHROUGH               0x00000020

#ifdef __MMI_VECTOR_FONT_SUPPORT__
	#define __MMI_FONT_EFFECTS__
#endif


#if defined(__MMI_MAINLCD_96X64__)
#define MMI_FE_FONT_SIZE_SMALL      5
#define MMI_FE_FONT_SIZE_MEDIUM     9
#define MMI_FE_FONT_SIZE_LARGE      12

#elif defined(__MMI_MAINLCD_128X128__)
#define MMI_FE_FONT_SIZE_SMALL      9
#define MMI_FE_FONT_SIZE_MEDIUM     14
#define MMI_FE_FONT_SIZE_LARGE      16

#elif defined(__MMI_MAINLCD_128X160__)
#define MMI_FE_FONT_SIZE_SMALL      9
#define MMI_FE_FONT_SIZE_MEDIUM     14
#define MMI_FE_FONT_SIZE_LARGE      16

#elif defined(__MMI_MAINLCD_176X220__)
#define MMI_FE_FONT_SIZE_SMALL      9
#define MMI_FE_FONT_SIZE_MEDIUM     14
#define MMI_FE_FONT_SIZE_LARGE      16

#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_FE_FONT_SIZE_SMALL      14
#define MMI_FE_FONT_SIZE_MEDIUM     20
#define MMI_FE_FONT_SIZE_LARGE      22

#elif defined(__MMI_MAINLCD_240X400__)
#define MMI_FE_FONT_SIZE_SMALL      14
#define MMI_FE_FONT_SIZE_MEDIUM     20
#define MMI_FE_FONT_SIZE_LARGE      22

#elif defined(__MMI_MAINLCD_320X240__)
#define MMI_FE_FONT_SIZE_SMALL      14
#define MMI_FE_FONT_SIZE_MEDIUM     20
#define MMI_FE_FONT_SIZE_LARGE      22

#elif defined(__MMI_MAINLCD_320X480__)
#define MMI_FE_FONT_SIZE_SMALL      14
#define MMI_FE_FONT_SIZE_MEDIUM     20
#define MMI_FE_FONT_SIZE_LARGE      24

#elif defined(__MMI_MAINLCD_480X800__)
#define MMI_FE_FONT_SIZE_SMALL      14
#define MMI_FE_FONT_SIZE_MEDIUM     20
#define MMI_FE_FONT_SIZE_LARGE      24

#else
#define MMI_FE_FONT_SIZE_SMALL      14
#define MMI_FE_FONT_SIZE_MEDIUM     20
#define MMI_FE_FONT_SIZE_LARGE      24

#endif






typedef enum
{
    FONT_EFFECT_NONE,
	FONT_EFFECT_ENGRAVE,
#if defined(__MMI_FONT_EFFECTS__)
	FONT_EFFECT_DROP_SHADOW,
	FONT_EFFECT_OUTER_GLOW,
	FONT_EFFECT_ENHANCED_ENGRAVE,
	FONT_EFFECT_GRADIENT,
	FONT_EFFECT_BORDER,
	FONT_EFFECT_GRADIENT_DROP_SHADOW,
	FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE,
#endif /* __MMI_FONT_EFFECTS__ */
	FONT_EFFECT_MAX
} mmi_font_effect_enum;


typedef struct Range
{
    U16 nMin;
    U16 nMax;
} RangeData;

typedef struct RangeInfo
{
    U16 nNoOfRanges;
    const RangeData *pRangeData;

} RangeDetails;

typedef struct Group
{
    U32 nOffset;
    U16 nSize;
} GroupData;

typedef struct GroupInfo
{
    U16 nNoOfGroup;
    const GroupData* pGroupData;

} GroupDetails;

#if defined(__MMI_FONT_COMPRESSION__) ||  (defined(__MMI_BDF_SW_COMPRESSION__))
/* for font comression */
typedef struct
{
    U16  num_of_block;
    const U16* block_index_array;
    const U16* rangeOffset;
} mmi_font_range_offset_struct;

typedef struct
{
    U8* org_data_ptr;
    U32 org_data_size;
    const U8* zip_data_ptr;
    U32 zip_data_size; 
} mmi_font_compress_info;

#endif


typedef struct _CustFontData
{
    U8 nHeight;
    U8 nWidth;
    U8 nAscent;
    U8 nDescent;
    U8 nEquiDistant;
    U8 nCharBytes;
    U16 nMaxChars;
    U8 *pDWidthArray;
    U8 *pWidthArray;
#if defined(__MMI_FONT_COMPRESSION__) || (defined(__MMI_BDF_SW_COMPRESSION__))
    U8 *pOffsetArray;
#else
    U32 *pOffsetArray;
#endif
    U8 *pDataArray;
#if (defined(__MMI_FONT_COMPRESSION__)) || (defined(__MMI_BDF_SW_COMPRESSION__))
    mmi_font_range_offset_struct* pRange;
#else
    U16 *pRange;
#endif
    const RangeDetails *pRangeDetails;
#if defined(__MMI_FONT_GROUP_COMPRESSION__)
    const GroupDetails *pGroupDetails;
#endif

    U32 language_flag;
} sCustFontData;

typedef struct _FontFamily
{
    U16 nTotalFonts;
    sCustFontData *fontData[MAX_FONT_TYPES];
} sFontFamily;

typedef struct 
{
    U16 nTotalFonts;
    const sCustFontData *const *fontData;
} font_group_struct;

typedef struct _LanguageDetails
{
    U8 aName[LANGUAGE_NAME];
    U8 aLangSSC[SSC_SIZE];
  //  U8 nCurrentFamily;
   // sFontFamily *fontfamilyList[MAX_FONT_FAMILIES];
    U8 aLangCountryCode[LCC_SIZE];
    U8 aLangIsoCode[ISO_SIZE];
} sLanguageDetails;

/* sLanguageDetails gLanguageArray[MAX_LANGUAGES]; */

#define MAX_FONT_SIZE MAX_FONT_TYPES


#endif /* _FONTRES_H_ */ 


