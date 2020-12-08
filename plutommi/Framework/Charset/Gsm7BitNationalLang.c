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
 *  Gsm7BitNationalLang.c
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
 //
#include "MMI_include.h"
#include "Gsm7BitNationalLang.h"
#include "SmsSrvGprot.h"

#ifdef __EMS_NON_STD_7BIT_CHAR__
#include "gui_ems.h"
#endif

extern U8 mmi_msg_get_seg_num(void);

typedef struct
{
    U16 ucs2;   /* ucs2 */
    U8 gsm;     /* 7 bit */
} ucs2_7bit_map;

/**************************************** GSM default **************************************/
const U16 default_7bit_to_ucs2_table[] = 
{
    64, 163, 36, 165, 232, 233, 249, 236, 242, 199, 10, 216, 248, 13, 197, 229,
    0x0394, 95, 0x03A6, 0x0393, 0x039B, 0x03A9, 0x03A0, 0x03A8, 0x03A3, 0x0398, 0x039E, 0x1B, 198, 230, 223, 201,
    32, 33, 34, 35, 164, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    161, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 196, 214, 209, 220, 167,
    191, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 228, 246, 241, 252, 224
};

const ucs2_7bit_map default_ucs2_to_7bit_table[] = 
{
    {10, 10}, {13, 13}, {27, 27}, {32, 32}, {33, 33},
    {34, 34}, {35, 35}, {36, 2}, {37, 37}, {38, 38},
    {39, 39}, {40, 40}, {41, 41}, {42, 42}, {43, 43},
    {44, 44}, {45, 45}, {46, 46}, {47, 47}, {48, 48},
    {49, 49}, {50, 50}, {51, 51}, {52, 52}, {53, 53},
    {54, 54}, {55, 55}, {56, 56}, {57, 57}, {58, 58},
    {59, 59}, {60, 60}, {61, 61}, {62, 62}, {63, 63},
    {64, 0}, {65, 65}, {66, 66}, {67, 67}, {68, 68},
    {69, 69}, {70, 70}, {71, 71}, {72, 72}, {73, 73},
    {74, 74}, {75, 75}, {76, 76}, {77, 77}, {78, 78},
    {79, 79}, {80, 80}, {81, 81}, {82, 82}, {83, 83},
    {84, 84}, {85, 85}, {86, 86}, {87, 87}, {88, 88},
    {89, 89}, {90, 90}, {95, 17}, {97, 97}, {98, 98},
    {99, 99}, {100, 100}, {101, 101}, {102, 102}, {103, 103},
    {104, 104}, {105, 105}, {106, 106}, {107, 107}, {108, 108},
    {109, 109}, {110, 110}, {111, 111}, {112, 112}, {113, 113},
    {114, 114}, {115, 115}, {116, 116}, {117, 117}, {118, 118},
    {119, 119}, {120, 120}, {121, 121}, {122, 122}, {161, 64},
    {163, 1}, {164, 36}, {165, 3}, {167, 95}, {191, 96},
    {196, 91}, {197, 14}, {198, 28}, {199, 9}, {201, 31},
    {209, 93}, {214, 92}, {216, 11}, {220, 94}, {223, 30},
    {224, 127}, {228, 123}, {229, 15}, {230, 29}, {232, 4},
    {233, 5}, {236, 7}, {241, 125}, {242, 8}, {246, 124},
    {248, 12}, {249, 6}, {252, 126}, {0x0393, 19}, {0x0394, 16},
    {0x0398, 25}, {0x039B, 20}, {0x039E, 26}, {0x03A0, 22}, {0x03A3, 24}, 
    {0x03A6, 18}, {0x03A8, 23}, {0x03A9, 21}, 
};

/**************************************** GSM default end **************************************/

#ifdef __SMS_R8_NATION_LANGUAGE__
/**************************************** turkish default **************************************/
const U16 turkish_7bit_to_ucs2_table[] = 
{
    64, 163, 36, 165, 0x20ac, 233, 249, 0x0131, 242, 199, 10, 0x011e, 0x011f, 13, 197, 229,
    0x0394, 95, 0x03A6, 0x0393, 0x039B, 0x03A9, 0x03A0, 0x03A8, 0x03A3, 0x0398, 0x039E, 0x1B, 0x015E, 0x015f, 223, 201,
    32, 33, 34, 35, 164, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    0x0130, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 196, 214, 209, 220, 167,
    231, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 228, 246, 241, 252, 224
};

const ucs2_7bit_map turkish_ucs2_to_7bit_table[] = 
{
    {10, 10}, {13, 13}, {27, 27}, {32, 32}, {33, 33}, 
    {34, 34}, {35, 35}, {36, 2},  {37, 37},
    {38, 38}, {39, 39}, {40, 40}, {41, 41}, {42, 42},
    {43, 43}, {44, 44}, {45, 45}, {46, 46}, {47, 47},
    {48, 48}, {49, 49}, {50, 50}, {51, 51}, {52, 52},
    {53, 53}, {54, 54}, {55, 55}, {56, 56}, {57, 57},
    {58, 58}, {59, 59}, {60, 60}, {61, 61}, {62, 62},
    {63, 63}, {64, 0}, {65, 65}, {66, 66}, {67, 67},
    {68, 68}, {69, 69}, {70, 70}, {71, 71}, {72, 72},
    {73, 73}, {74, 74}, {75, 75}, {76, 76}, {77, 77},
    {78, 78}, {79, 79}, {80, 80}, {81, 81}, {82, 82},
    {83, 83}, {84, 84}, {85, 85}, {86, 86}, {87, 87},
    {88, 88}, {89, 89}, {90, 90}, {95, 17}, {97, 97},
    {98, 98}, {99, 99}, {100, 100}, {101, 101}, {102, 102},
    {103, 103}, {104, 104}, {105, 105}, {106, 106}, {107, 107},
    {108, 108}, {109, 109}, {110, 110}, {111, 111}, {112, 112},
    {113, 113}, {114, 114}, {115, 115}, {116, 116}, {117, 117},
    {118, 118}, {119, 119}, {120, 120}, {121, 121}, {122, 122},
    {163, 1}, {164, 36}, {165, 3}, {167, 95}, {196, 91},
    {197, 14}, {199, 9}, {201, 31}, {209, 93}, {214, 92},
    {220, 94}, {223, 30}, {224, 127}, {228, 123}, {229, 15},
    {231, 96}, {233, 5}, {241, 125}, {242, 8}, {246, 124},
    {249, 6}, {252, 126}, {0x011e, 11}, {0x011f, 12}, {0x0130, 64}, 
    {0x0131, 7}, {0x015E, 28}, {0x015F, 29}, {0x0393, 19}, {0x0394, 16},
    {0x0398, 25}, {0x039B, 20}, {0x039E, 26}, {0x03A0, 22}, {0x03A3, 24}, 
    {0x03A6, 18}, {0x03A8, 23}, {0x03A9, 21}, {0x20ac, 4}
};

/**************************************** turkish default end **************************************/

/**************************************** portuguese default **************************************/
const U16 portuguese_7bit_to_ucs2_table[] = 
{
    64, 163, 36, 165, 0xea, 233, 0xfa, 0xed, 0xf3, 0xe7, 10, 0xd4, 0xf4, 13, 0xc1, 0xe1,
    0x0394, 95, 0xaa, 0xc7, 0xc0, 0x221e, 0x5e, 0x5c, 0x20ac, 0xd3, 0x7c, 0x1B, 0xc2, 0xe2, 0xca, 201,
    32, 33, 34, 35, 0xba, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    0xcd, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 0xc3, 0xd5, 0xda, 0xdc, 0xa7,
    0x7e, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 0xe3, 0xf5, 0x60, 252, 224
};

const ucs2_7bit_map portuguese_ucs2_to_7bit_table[] = 
{
    {10, 10}, {13, 13}, {27, 27}, {32, 32}, 
    {33, 33}, {34, 34}, {35, 35}, {36, 2}, {37, 37},
    {38, 38}, {39, 39}, {40, 40}, {41, 41}, {42, 42},
    {43, 43}, {44, 44}, {45, 45}, {46, 46}, {47, 47},
    {48, 48}, {49, 49}, {50, 50}, {51, 51}, {52, 52},
    {53, 53}, {54, 54}, {55, 55}, {56, 56}, {57, 57},
    {58, 58}, {59, 59}, {60, 60}, {61, 61}, {62, 62},
    {63, 63}, {64, 0}, {65, 65}, {66, 66}, {67, 67},
    {68, 68}, {69, 69}, {70, 70}, {71, 71}, {72, 72},
    {73, 73}, {74, 74}, {75, 75}, {76, 76}, {77, 77},
    {78, 78}, {79, 79}, {80, 80}, {81, 81}, {82, 82},
    {83, 83}, {84, 84}, {85, 85}, {86, 86}, {87, 87},
    {88, 88}, {89, 89}, {90, 90}, {92, 23}, {94, 22},
    {95, 17}, {96, 125}, {97, 97}, {98, 98}, {99, 99},
    {100, 100}, {101, 101}, {102, 102}, {103, 103}, {104, 104},
    {105, 105}, {106, 106}, {107, 107}, {108, 108}, {109, 109},
    {110, 110}, {111, 111}, {112, 112}, {113, 113}, {114, 114},
    {115, 115}, {116, 116}, {117, 117}, {118, 118}, {119, 119},
    {120, 120}, {121, 121}, {122, 122}, {124, 26}, {126, 96},
    {163, 1}, {165, 3}, {167, 95}, {170, 18}, {186, 36},
    {192, 20}, {193, 14}, {194, 28}, {195, 91}, {199, 19},
    {201, 31}, {202, 30}, {205, 64}, {211, 25}, {212, 11},
    {213, 92}, {218, 93}, {220, 94}, {224, 127}, {225, 15},
    {226, 29}, {227, 123}, {231, 9}, {233, 5}, {234, 4},
    {237, 7}, {243, 8}, {244, 12}, {245, 124}, {250, 6},
    {252, 126}, {0x0394, 16}, {0x20ac, 24}, {0x221e, 21}
};

/**************************************** portuguese default end **************************************/
#endif /* __SMS_R8_NATION_LANGUAGE__ */ 

/**************************************** default extention **************************************/
const ucs2_7bit_map default_7bit_to_ucs2_ext_table[] = 
{
    {0x5e, 0x14},
    {0x20, 0x1b},
    {0x7b, 0x28},
    {0x7d, 0x29},
    {0x5c, 0x2f},
    {0x5b, 0x3c},
    {0x7e, 0x3d},
    {0x5d, 0x3e},
    {0x7c, 0x40},
    {0x20ac, 0x65}
};

const ucs2_7bit_map default_ucs2_to_7bit_ext_table[] = 
{
    {0x5b, 0x3c},
    {0x5c, 0x2f},
    {0x5d, 0x3e},
    {0x5e, 0x14},
    {0x7b, 0x28},
    {0x7c, 0x40},
    {0x7d, 0x29},
    {0x7e, 0x3d},
    {0x20ac, 0x65}
};

/**************************************** default extention end **************************************/

#ifdef __SMS_R8_NATION_LANGUAGE__
/**************************************** turkish extention ************************************/
const ucs2_7bit_map turkish_7bit_to_ucs2_ext_table[] = 
{
    {0x20, 0x0d},
    {0x5e, 0x14},
    {0x20, 0x1b},
    {0x7b, 0x28},
    {0x7d, 0x29},
    {0x5c, 0x2f},
    {0x5b, 0x3c},
    {0x7e, 0x3d},
    {0x5d, 0x3e},
    {0x7c, 0x40},
    {0x011e, 0x47},
    {0x0130, 0x49},
    {0x015e, 0x53},
    {0xe7, 0x63},
    {0x20ac, 0x65},
    {0x011f, 0x67},
    {0x0131, 0x69},
    {0x015f, 0x73}
};

const ucs2_7bit_map turkish_ucs2_to_7bit_ext_table[] = 
{
    {0x5b, 0x3c},
    {0x5c, 0x2f},
    {0x5d, 0x3e},
    {0x5e, 0x14},
    {0x7b, 0x28},
    {0x7c, 0x40},
    {0x7d, 0x29},
    {0x7e, 0x3d},
    {0xe7, 0x63},
    {0x011e, 0x47},
    {0x011f, 0x67},
    {0x0130, 0x49},
    {0x0131, 0x69},
    {0x015e, 0x53},
    {0x015f, 0x73},
    {0x20ac, 0x65}
};

/**************************************** turkish extention end ************************************/

/**************************************** spanish extention ************************************/
const ucs2_7bit_map spanish_7bit_to_ucs2_ext_table[] = 
{
    {0xe7, 0x09},
    {0x20, 0x0d},
    {0x5e, 0x14},
    {0x20, 0x1b},
    {0x7b, 0x28},
    {0x7d, 0x29},
    {0x5c, 0x2f},
    {0x5b, 0x3c},
    {0x7e, 0x3d},
    {0x5d, 0x3e},
    {0x7c, 0x40},
    {0xc1, 0x41},
    {0xcd, 0x49},
    {0xd3, 0x4f},
    {0xda, 0x55},
    {0xe1, 0x61},
    {0x20ac, 0x65},
    {0xed, 0x69},
    {0xf3, 0x6f},
    {0xfa, 0x75}
};

const ucs2_7bit_map spanish_ucs2_to_7bit_ext_table[] = 
{
    {0x5b, 0x3c},
    {0x5c, 0x2f},
    {0x5d, 0x3e},
    {0x5e, 0x14},
    {0x7b, 0x28},
    {0x7c, 0x40},
    {0x7d, 0x29},
    {0x7e, 0x3d},
    {0xc1, 0x41},
    {0xcd, 0x49},
    {0xd3, 0x4f},
    {0xda, 0x55},
    {0xe1, 0x61},
    {0xe7, 0x09},
    {0xed, 0x69},
    {0xf3, 0x6f},
    {0xfa, 0x75},
    {0x20ac, 0x65},
};

/**************************************** spanish extention end ************************************/

/**************************************** portuguese extention ************************************/
const ucs2_7bit_map portuguese_7bit_to_ucs2_ext_table[] = 
{
    {0xea, 0x05},
    {0xe7, 0x09},
    {0xd4, 0x0b},
    {0xf4, 0x0c},
    {0x20, 0x0d},
    {0xc1, 0x0e},
    {0xe1, 0x0f},
    {0x03a6, 0x12},
    {0x0393, 0x13},
    {0x5e, 0x14},
    {0x03a9, 0x15},
    {0x03a0, 0x16},
    {0x03a8, 0x17},
    {0x03a3, 0x18},
    {0x0398, 0x19},
    {0x20, 0x1b},
    {0xca, 0x1f},
    {0x7b, 0x28},
    {0x7d, 0x29},
    {0x5c, 0x2f},
    {0x5b, 0x3c},
    {0x7e, 0x3d},
    {0x5d, 0x3e},
    {0x7c, 0x40},
    {0xc0, 0x41},
    {0xcd, 0x49},
    {0xd3, 0x4f},
    {0xda, 0x55},
    {0xc3, 0x5b},
    {0xd5, 0x5c},
    {0xc2, 0x61},
    {0x20ac, 0x65},
    {0xed, 0x69},
    {0xf3, 0x6f},
    {0xfa, 0x75},
    {0xe3, 0x7b},
    {0xf5, 0x7c},
    {0xe2, 0x7f}
};

const ucs2_7bit_map portuguese_ucs2_to_7bit_ext_table[] = 
{
    {0x20, 0x1b},
    {0x5b, 0x3c},
    {0x5c, 0x2f},
    {0x5d, 0x3e},
    {0x5e, 0x14},
    {0x7b, 0x28},
    {0x7c, 0x40},
    {0x7d, 0x29},
    {0x7e, 0x3d},
    {0xc0, 0x41},
    {0xc1, 0x0e},
    {0xc2, 0x61},
    {0xc3, 0x5b},
    {0xca, 0x1f},
    {0xcd, 0x49},
    {0xd3, 0x4f},
    {0xd4, 0x0b},
    {0xd5, 0x5c},
    {0xda, 0x55},
    {0xe1, 0x0f},
    {0xe2, 0x7f},
    {0xe3, 0x7b},
    {0xe7, 0x09},
    {0xea, 0x05},
    {0xed, 0x69},
    {0xf3, 0x6f},
    {0xf4, 0x0c},
    {0xf5, 0x7c},
    {0xfa, 0x75},
    {0x0393, 0x13},
    {0x0398, 0x19},
    {0x03a0, 0x16},
    {0x03a3, 0x18},
    {0x03a6, 0x12},        
    {0x03a8, 0x17},
    {0x03a9, 0x15},
    {0x20ac, 0x65},
};

/**************************************** portuguese extention end ************************************/
#endif /* __SMS_R8_NATION_LANGUAGE__ */ 

#define U16_TABLE_TYPE          0x0001
#define MAPPING_TABLE_TYPE      0x0002
#define DEFAULT_LANG_TYPE       0x0004
#define TURKISH_LANG_TYPE       0x0008
#define PORTUGUESE_LANG_TYPE    0x0010
#define SPANISH_LANG_TYPE       0x0020
#define UCS2_TO_7BIT_TYPE       0x0040
#define GSM_ESC_CHAR            0x1B

typedef struct
{
    const void *table;
    U32 table_size;
    U32 table_type;
} gsm_lang_table_struct;

static const gsm_lang_table_struct g_nl_default_table[] = 
{
    {default_7bit_to_ucs2_table, sizeof(default_7bit_to_ucs2_table) / sizeof(U16), U16_TABLE_TYPE | DEFAULT_LANG_TYPE},
    {default_ucs2_to_7bit_table, sizeof(default_ucs2_to_7bit_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | DEFAULT_LANG_TYPE | UCS2_TO_7BIT_TYPE},
 #ifdef __SMS_R8_NATION_LANGUAGE__
    {turkish_7bit_to_ucs2_table, sizeof(turkish_7bit_to_ucs2_table) / sizeof(U16), U16_TABLE_TYPE | TURKISH_LANG_TYPE},
    {turkish_ucs2_to_7bit_table, sizeof(turkish_ucs2_to_7bit_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | TURKISH_LANG_TYPE | UCS2_TO_7BIT_TYPE},
    {portuguese_7bit_to_ucs2_table, sizeof(portuguese_7bit_to_ucs2_table) / sizeof(U16),
     U16_TABLE_TYPE | PORTUGUESE_LANG_TYPE},
    {portuguese_ucs2_to_7bit_table, sizeof(portuguese_ucs2_to_7bit_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | PORTUGUESE_LANG_TYPE | UCS2_TO_7BIT_TYPE},
 #endif /* __SMS_R8_NATION_LANGUAGE__ */ 
    {NULL, 0, 0}
};

static const gsm_lang_table_struct g_nl_ext_table[] = 
{
    {default_7bit_to_ucs2_ext_table, sizeof(default_7bit_to_ucs2_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | DEFAULT_LANG_TYPE},
    {default_ucs2_to_7bit_ext_table, sizeof(default_ucs2_to_7bit_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | DEFAULT_LANG_TYPE | UCS2_TO_7BIT_TYPE},

 #ifdef __SMS_R8_NATION_LANGUAGE__
    {turkish_7bit_to_ucs2_ext_table, sizeof(turkish_7bit_to_ucs2_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | TURKISH_LANG_TYPE},
    {turkish_ucs2_to_7bit_ext_table, sizeof(turkish_ucs2_to_7bit_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | TURKISH_LANG_TYPE | UCS2_TO_7BIT_TYPE},
    {portuguese_7bit_to_ucs2_ext_table, sizeof(portuguese_7bit_to_ucs2_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | PORTUGUESE_LANG_TYPE},
    {portuguese_ucs2_to_7bit_ext_table, sizeof(portuguese_ucs2_to_7bit_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | PORTUGUESE_LANG_TYPE | UCS2_TO_7BIT_TYPE},
    {spanish_7bit_to_ucs2_ext_table, sizeof(spanish_7bit_to_ucs2_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | SPANISH_LANG_TYPE},
    {spanish_ucs2_to_7bit_ext_table, sizeof(spanish_ucs2_to_7bit_ext_table) / sizeof(ucs2_7bit_map),
     MAPPING_TABLE_TYPE | SPANISH_LANG_TYPE | UCS2_TO_7BIT_TYPE},
 #endif /* __SMS_R8_NATION_LANGUAGE__ */ 
    {NULL, 0, 0}
};

#ifdef __SMS_R8_NATION_LANGUAGE__
/* the current table choose mechanism */
static S32 g_cur_mechanism_type = DEFAULT_GSM_NATIONAL_TABLE_MECHANISM;
#endif

/* the current default table */
static S32 g_cur_default_table = DEFAULT_LANG_TYPE;

/* the current extension table */
static S32 g_cur_ext_table = DEFAULT_LANG_TYPE;

/* the current language setting */
EMSNationalLanguageType g_cur_lang_type = EMS_NL_DEFAULT;

/* static function */
static S32 mmi_7bit_find(S32 which, U16 key, ucs2_7bit_map *array, S32 end_idx);
static const gsm_lang_table_struct *mmi_7bit_get_table(S32 is_default, S32 cur_table);
static S32 mmi_7bit_convert(U16 c, const gsm_lang_table_struct *lt);

#ifdef __SMS_R8_NATION_LANGUAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_change_table_mechanism_by_catcher
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_7bit_change_table_mechanism_by_catcher(S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode > EMS_AUTO_DETECTION || mode < EMS_DEFAULT_ONLY)
        return;

#if (!defined(__EMS_REL5__) && !defined(__SLIM_EMS__))
    /* EMS4.0 can't support the both_table mode */
    if (mode == EMS_BOTH_TABLE)
        return;
#endif

    mmi_7bit_set_table_mechanism((gui_ems_table_mechanism_enum)mode);

    mmi_7bit_set_national_lang(g_cur_lang_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_set_table_mechanism
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_7bit_set_table_mechanism(gui_ems_table_mechanism_enum m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(m <= EMS_AUTO_DETECTION);
    g_cur_mechanism_type = m;
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_GSM_7BIT_MECHANISM_SET, m);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_get_table_mechanism
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
gui_ems_table_mechanism_enum mmi_7bit_get_table_mechanism(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gui_ems_table_mechanism_enum)g_cur_mechanism_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_get_national_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
EMSNationalLanguageType mmi_7bit_get_national_lang(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cur_lang_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_set_national_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_7bit_set_national_lang(EMSNationalLanguageType t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cur_lang_type = t;

    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_GSM_7BIT_LANGUAGE_SET, g_cur_lang_type);

    if (g_cur_mechanism_type == EMS_DEFAULT_ONLY)
    {
        g_cur_default_table = DEFAULT_LANG_TYPE;
        g_cur_ext_table = DEFAULT_LANG_TYPE;

        MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_GSM_7BIT_TABLE_SET, g_cur_default_table, g_cur_ext_table);
        return;
    }

    switch (t)
    {
        case EMS_NL_DEFAULT:
            g_cur_default_table = DEFAULT_LANG_TYPE;
            g_cur_ext_table = DEFAULT_LANG_TYPE;
            break;

        case EMS_NL_TURKISH:
            if (g_cur_mechanism_type == EMS_LOCK_SHIFT_ONLY)
            {
                g_cur_default_table = TURKISH_LANG_TYPE;
                g_cur_ext_table = DEFAULT_LANG_TYPE;
            }
            else if(g_cur_mechanism_type == EMS_BOTH_TABLE)
            {
                g_cur_default_table = TURKISH_LANG_TYPE;
                g_cur_ext_table = TURKISH_LANG_TYPE;
            }
            else
            {
                g_cur_default_table = DEFAULT_LANG_TYPE;
                g_cur_ext_table = TURKISH_LANG_TYPE;
            }
            break;

        case EMS_NL_SPANISH:
            g_cur_default_table = DEFAULT_LANG_TYPE;
            g_cur_ext_table = SPANISH_LANG_TYPE;
            break;

        case EMS_NL_PORTUGUESE:
            if (g_cur_mechanism_type == EMS_LOCK_SHIFT_ONLY)
            {
                g_cur_default_table = PORTUGUESE_LANG_TYPE;
                g_cur_ext_table = DEFAULT_LANG_TYPE;
            }
            else if(g_cur_mechanism_type == EMS_BOTH_TABLE)
            {
                g_cur_default_table = PORTUGUESE_LANG_TYPE;
                g_cur_ext_table = PORTUGUESE_LANG_TYPE;
            }
            else
            {
                g_cur_default_table = DEFAULT_LANG_TYPE;
                g_cur_ext_table = PORTUGUESE_LANG_TYPE;
            }
            break;

        default:
            g_cur_default_table = DEFAULT_LANG_TYPE;
            g_cur_ext_table = DEFAULT_LANG_TYPE;
            break;
    }

    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_GSM_7BIT_TABLE_SET, g_cur_default_table, g_cur_ext_table);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_set_national_lang_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_7bit_set_national_lang_table(EMSNationalLanguage *l)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (l->locking_shift)
    {
        case EMS_NL_DEFAULT:
            g_cur_default_table = DEFAULT_LANG_TYPE;
            break;

        case EMS_NL_TURKISH:
            g_cur_default_table = TURKISH_LANG_TYPE;
            break;

        case EMS_NL_SPANISH:
            /* no locking table for Spanish*/
            g_cur_default_table = DEFAULT_LANG_TYPE;
            break;

        case EMS_NL_PORTUGUESE:
            g_cur_default_table = PORTUGUESE_LANG_TYPE;
            break;

        default:
            g_cur_default_table = DEFAULT_LANG_TYPE;
            break;
    }

    switch (l->single_shift)
    {
        case EMS_NL_DEFAULT:
            g_cur_ext_table = DEFAULT_LANG_TYPE;
            break;

        case EMS_NL_TURKISH:
            g_cur_ext_table = TURKISH_LANG_TYPE;
            break;

        case EMS_NL_SPANISH:
            g_cur_ext_table = SPANISH_LANG_TYPE;
            break;

        case EMS_NL_PORTUGUESE:
            g_cur_ext_table = PORTUGUESE_LANG_TYPE;
            break;

        default:
            g_cur_ext_table = DEFAULT_LANG_TYPE;
            break;
    }

    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_GSM_7BIT_TABLE_SET, g_cur_default_table, g_cur_ext_table);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_get_national_lang_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_7bit_get_national_lang_table(EMSNationalLanguage *l)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_cur_default_table)
    {
    case DEFAULT_LANG_TYPE:
        l->locking_shift = EMS_NL_DEFAULT;
        break;
        
    case TURKISH_LANG_TYPE:
        l->locking_shift = EMS_NL_TURKISH;
        break;
        
    case SPANISH_LANG_TYPE:
        /* no locking table for Spanish*/
        l->locking_shift = EMS_NL_DEFAULT;
        break;
        
    case PORTUGUESE_LANG_TYPE:
        l->locking_shift = EMS_NL_PORTUGUESE;
        break;
        
    default:
        l->locking_shift = EMS_NL_DEFAULT;
            break;
    }

    switch (g_cur_ext_table)
    {
    case DEFAULT_LANG_TYPE:
        l->single_shift = EMS_NL_DEFAULT;
        break;
        
    case TURKISH_LANG_TYPE:
        l->single_shift = EMS_NL_TURKISH;
        break;
        
    case SPANISH_LANG_TYPE:
        l->single_shift = EMS_NL_SPANISH;
        break;
        
    case PORTUGUESE_LANG_TYPE:
        l->single_shift = EMS_NL_PORTUGUESE;
        break;
        
    default:
        l->single_shift = EMS_NL_DEFAULT;
            break;
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_get_table_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_7bit_get_table_type(EMSNationalLanguageType t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (t)
    {
        case EMS_NL_DEFAULT:
            return DEFAULT_LANG_TYPE;

        case EMS_NL_TURKISH:
            return TURKISH_LANG_TYPE;

        case EMS_NL_SPANISH:
            return SPANISH_LANG_TYPE;

        case EMS_NL_PORTUGUESE:
            return PORTUGUESE_LANG_TYPE;

        default:
            return DEFAULT_LANG_TYPE;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_check_gsm_by_nl_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 *  t       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_check_gsm_by_nl_table(U16 c, EMSNationalLanguageType t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(1, mmi_7bit_get_table_type(t) | UCS2_TO_7BIT_TYPE);
    if (lt)
    {
        return (mmi_7bit_convert((U16) c, lt) >= 0);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_check_gsm_ext_character_by_nl_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 *  t       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_check_gsm_ext_character_by_nl_table(U16 c, EMSNationalLanguageType t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(0, mmi_7bit_get_table_type(t) | UCS2_TO_7BIT_TYPE);
    if (lt)
    {
        return (mmi_7bit_convert((U16) c, lt) >= 0);
    }

    return 0;
}
#endif /* __SMS_R8_NATION_LANGUAGE__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_ucs2_to_gsm_char_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_ucs2_to_gsm_char_default(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(1, DEFAULT_LANG_TYPE | UCS2_TO_7BIT_TYPE);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_ucs2_to_gsm_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_ucs2_to_gsm_char(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(1, g_cur_default_table | UCS2_TO_7BIT_TYPE);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_ucs2_to_gsm_ext_char_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_ucs2_to_gsm_ext_char_default(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(0, DEFAULT_LANG_TYPE | UCS2_TO_7BIT_TYPE);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_ucs2_to_gsm_ext_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_ucs2_to_gsm_ext_char(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(0, g_cur_ext_table | UCS2_TO_7BIT_TYPE);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_check_gsm_default
 * DESCRIPTION
 *  check c only use the default table
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_check_gsm_default(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    return mmi_7bit_check_gsm_by_nl_table(c, EMS_NL_DEFAULT);
#else
    return mmi_7bit_check_gsm(c);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_check_gsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_check_gsm(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_7bit_ucs2_to_gsm_char(c) >= 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_check_gsm_default
 * DESCRIPTION
 *  check c only use the default table
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_check_gsm_ext_character_default(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    return mmi_7bit_check_gsm_ext_character_by_nl_table(c, EMS_NL_DEFAULT);
#else
    return mmi_7bit_check_gsm_ext_character(c);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_check_gsm_ext_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_check_gsm_ext_character(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    if (g_cur_default_table != DEFAULT_LANG_TYPE
        || g_cur_ext_table != DEFAULT_LANG_TYPE)
    {
        if (mmi_7bit_check_gsm(c))
            return 0;
    }
#endif

    return (mmi_7bit_ucs2_to_gsm_ext_char(c) >= 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_gsm_to_ucs2_char_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_gsm_to_ucs2_char_default(U8 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(1, DEFAULT_LANG_TYPE);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_gsm_to_ucs2_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_gsm_to_ucs2_char(U8 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(1, g_cur_default_table);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_gsm_ext_to_ucs2_char_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_gsm_ext_to_ucs2_char_default(U8 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(0, DEFAULT_LANG_TYPE);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_gsm_ext_to_ucs2_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_gsm_ext_to_ucs2_char(U8 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lt = mmi_7bit_get_table(0, g_cur_ext_table);
    if (lt)
    {
        return mmi_7bit_convert((U16) c, lt);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_gsm_to_ucs2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_in              [?]         
 *  str_out             [?]         
 *  in_count            [IN]        
 *  out_count           [?]         
 *  not_found_char      [IN]        
 *  add_ESC             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_gsm_to_ucs2_string(
        U8 *str_in,
        U8 *str_out,
        U32 in_count,
        U32 *out_count,
        U16 not_found_char,
        U16 (*convert_not_found)(U8),
        S32 add_ESC)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p = str_in;
    S32 cur_count = 0, c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (in_count > 0 && cur_count < (S32)*out_count)
    {
        if (*p == GSM_ESC_CHAR)
        {
            /* the latter is an extention character */
            p++;
            in_count--;

            if (in_count == 0)
            {
                /* all input string is over, one extention character left. error! */
                UI_STRING_INSERT_CHARACTER(str_out, GSM_ESC_CHAR);
                cur_count++;
                *out_count = cur_count;
                return 0;
            }

            c = mmi_7bit_gsm_ext_to_ucs2_char(*p);
            if (c >= 0)
            {
                if (add_ESC)
                {
                    UI_STRING_INSERT_CHARACTER(str_out, GSM_ESC_CHAR);
                    cur_count++;
                }
                
                UI_STRING_INSERT_CHARACTER(str_out, c);
            }
            else
            {
                if (add_ESC)
                {
                    UI_STRING_INSERT_CHARACTER(str_out, GSM_ESC_CHAR);
                    cur_count++;
                }

                if (convert_not_found != NULL)
                {
                    UI_STRING_INSERT_CHARACTER(str_out, convert_not_found(*p));
                }
                else
                {
                    /* if this character is not found at the extension table, use the 
                     * main table to replace its value.
                     */

                    c = mmi_7bit_gsm_to_ucs2_char(*p);
                    UI_STRING_INSERT_CHARACTER(str_out, c);
                    /* UI_STRING_INSERT_CHARACTER(str_out, not_found_char); */
                }
            }
            
            cur_count++;
        }
        else
        {
            /* 7bit default char */
            c = mmi_7bit_gsm_to_ucs2_char(*p);
            if (c >=0)
            {
                UI_STRING_INSERT_CHARACTER(str_out, c);
                cur_count++;
            }
            else
            {
                c = mmi_7bit_gsm_ext_to_ucs2_char(*p);
                if (c >= 0)
                {
                    UI_STRING_INSERT_CHARACTER(str_out, c);
                    cur_count++;
                }
                else
                {
                    c = not_found_char;
                }
            }
        }

        p++;
        in_count--;
    }

    *out_count = cur_count;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_ucs2_to_gsm_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_in              [?]         
 *  str_out             [?]         
 *  in_count            [IN]        
 *  out_count           [?]         
 *  not_found_char      [IN]        
 *  added_ESC           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_ucs2_to_gsm_string(
        U8 *str_in,
        U8 *str_out,
        U32 in_count,
        U32 *out_count,
        U8 not_found_char,
        U8 (*convert_not_found)(U16),
        S32 added_ESC)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p = str_in;
    S32 gsm;
    S32 cur_count = 0, c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (in_count == 0 || cur_count >= (S32)*out_count)
        {
            *out_count = cur_count;
           
             break; //return 1;
        }

        UI_STRING_GET_NEXT_CHARACTER(p, c);
        in_count--;

        if (c == GSM_ESC_CHAR)
        {
            /* ESC character */
            if (added_ESC)
            {
                /* ESC has been exist in the str_in */
                if (in_count == 0)
                {
                    str_out[cur_count++] = GSM_ESC_CHAR;
                    *out_count = cur_count;
                    return 1;
                }

                UI_STRING_GET_NEXT_CHARACTER(p, c);
                in_count--;
                gsm = mmi_7bit_ucs2_to_gsm_ext_char((U16) c);
                if (gsm >= 0)
                {
                    str_out[cur_count++] = GSM_ESC_CHAR;
                    str_out[cur_count] = gsm;
                }
                else
                {
                    /* try the default table */
                    gsm = mmi_7bit_ucs2_to_gsm_char((U16) c);
                    if (gsm >= 0)
                    {
                        str_out[cur_count++] = GSM_ESC_CHAR;
                        str_out[cur_count] = gsm;
                    }
                    else
                    {
                        str_out[cur_count++] = GSM_ESC_CHAR;
                        
                        if (convert_not_found != NULL)
                            str_out[cur_count] = convert_not_found((U16)c);
                        else
                            str_out[cur_count] = not_found_char;
                    }
                }
            }
            else
            {
                /* no ESC flag, handle it as a common 7bit */
                gsm = mmi_7bit_ucs2_to_gsm_char((U16) c);
                if (gsm >= 0)
                {
                    str_out[cur_count] = gsm;
                }
                else
                {
                    if (convert_not_found != NULL)
                        str_out[cur_count] = convert_not_found((U16)c);
                    else
                        str_out[cur_count] = not_found_char;
                }
            }
        }
        else
        {
            /* not a ESC character */
            if (added_ESC)
            {
                /* is not a extention character */
                gsm = mmi_7bit_ucs2_to_gsm_char((U16) c);
                if (gsm >= 0)
                {
                    str_out[cur_count] = gsm;
                }
                else
                {
                    gsm = mmi_7bit_ucs2_to_gsm_ext_char((U16) c);
                    if (gsm >= 0)
                    {
                        str_out[cur_count] = gsm;
                    }
                    else
                    {
                        if (convert_not_found != NULL)
                            str_out[cur_count] = convert_not_found((U16)c);
                        else
                            str_out[cur_count] = not_found_char;
                    }
                }
            }
            else
            {
                /* maybe it's a default, or a extention character */
                gsm = mmi_7bit_ucs2_to_gsm_char((U16) c);
                if (gsm >= 0)
                {
                    str_out[cur_count] = gsm;
                }
                else
                {
                    /* try extention character */
                    gsm = mmi_7bit_ucs2_to_gsm_ext_char((U16) c);
                    if (gsm >= 0)
                    {
                        str_out[cur_count++] = GSM_ESC_CHAR;
                        str_out[cur_count] = gsm;
                    }
                    else
                    {
                        str_out[cur_count++] = GSM_ESC_CHAR;

                        if (convert_not_found != NULL)
                            str_out[cur_count] = convert_not_found((U16)c);
                        else
                            str_out[cur_count] = not_found_char;
                    }
                }
            }
        }

        cur_count++;
    }

    *out_count = cur_count;
    return 1;
}

#ifdef __SMS_R8_NATION_LANGUAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_exchange_table_for_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_in              [?]         
 *  str_out             [?]         
 *  in_count            [IN]        
 *  out_count           [?]         
 *  not_found_char      [IN]        
 *  added_ESC           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_7bit_ucs2_exchange_by_new_table(
        U8 *str_in,
        U8 *str_out,
        U32 in_count,
        U32 *out_count,
        EMSNationalLanguage *old_l,
        EMSNationalLanguage *new_l,
        U16 not_found_char,
        U16 (*convert_not_found)(U16))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p = str_in;
    S32 gsm;
    S32 cur_count = 0, c;
    EMSNationalLanguage backup_l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_7bit_get_national_lang_table(&backup_l);
    
    while (1)
    {
        if (in_count == 0 || cur_count >= (S32)*out_count)
        {
            *out_count = cur_count;
            return 1;
        }
        
        UI_STRING_GET_NEXT_CHARACTER(p, c);
        in_count--;
        
        mmi_7bit_set_national_lang_table(old_l);
        
        if (c == GSM_ESC_CHAR)
        {
            if (in_count == 0)
            {
                /* the current extension character is invalid */
                *out_count = cur_count;
                return 1;
            }

            /* ESC has been exist in the str_in */
            UI_STRING_GET_NEXT_CHARACTER(p, c);
            in_count--;

            UI_STRING_INSERT_CHARACTER(str_out, GSM_ESC_CHAR);
            cur_count++;

            gsm = mmi_7bit_ucs2_to_gsm_ext_char((U16)c);
            if (gsm < 0)
            {
                /* is not a extention character */
                if (convert_not_found != NULL)
                {
                    UI_STRING_INSERT_CHARACTER(str_out, convert_not_found(*p));
                }
                else
                {
                    UI_STRING_INSERT_CHARACTER(str_out, not_found_char);
                }
            }
            else
            {
                mmi_7bit_set_national_lang_table(new_l);

                c = mmi_7bit_gsm_ext_to_ucs2_char((U8)gsm);
                if (c < 0)
                {
                    /* is not a extention character */
                    if (convert_not_found != NULL)
                    {
                        UI_STRING_INSERT_CHARACTER(str_out, convert_not_found(*p));
                    }
                    else
                    {
                        UI_STRING_INSERT_CHARACTER(str_out, not_found_char);
                    }
                }
                else
                {
                    UI_STRING_INSERT_CHARACTER(str_out, c);
                }
            }

            cur_count++;
        }
        else
        {
            gsm = mmi_7bit_ucs2_to_gsm_char((U16)c);
            if (gsm < 0)
            {
                /* is not a extension character */
                if (convert_not_found != NULL)
                {
                    UI_STRING_INSERT_CHARACTER(str_out, convert_not_found(*p));
                }
                else
                {
                    UI_STRING_INSERT_CHARACTER(str_out, not_found_char);
                }
            }
            else
            {
                mmi_7bit_set_national_lang_table(new_l);
                
                c = mmi_7bit_gsm_to_ucs2_char((U8)gsm);
                if (c < 0)
                {
                    /* is not a extention character */
                    if (convert_not_found != NULL)
                    {
                        UI_STRING_INSERT_CHARACTER(str_out, convert_not_found(*p));
                    }
                    else
                    {
                        UI_STRING_INSERT_CHARACTER(str_out, not_found_char);
                    }
                }
                else
                {
                    UI_STRING_INSERT_CHARACTER(str_out, c);
                }
            }

            cur_count++;
        }
    }
    
    mmi_7bit_set_national_lang_table(&backup_l);
    *out_count = cur_count;
    return 1;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_get_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_default      [IN]        
 *  cur_table       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static const gsm_lang_table_struct *mmi_7bit_get_table(S32 is_default, S32 cur_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gsm_lang_table_struct *lt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_default)
    {
        lt = &g_nl_default_table[0];
    }
    else
        lt = &g_nl_ext_table[0];

    while (lt->table != NULL)
    {
        if ((lt->table_type & cur_table) == (U32)cur_table)
        {
            return lt;
        }

        lt++;
    }

    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 *  lt      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_7bit_convert(U16 c, const gsm_lang_table_struct *lt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lt->table == NULL)
        return -1;

    if (lt->table_type & U16_TABLE_TYPE)
    {
        /* U16 table, return the value */
        return ((U16*) lt->table)[c];
    }
    else if (lt->table_type & MAPPING_TABLE_TYPE)
    {
        /* mapping table, find one value */
        if (lt->table_type & UCS2_TO_7BIT_TYPE)
        {
            index = mmi_7bit_find(0, c, (ucs2_7bit_map*) lt->table, lt->table_size - 1);
            if (index >= 0)
                return ((ucs2_7bit_map*) lt->table)[index].gsm;
        }
        else
        {
            index = mmi_7bit_find(1, c, (ucs2_7bit_map*) lt->table, lt->table_size - 1);
            if (index >= 0)
                return ((ucs2_7bit_map*) lt->table)[index].ucs2;
        }

    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  which       [IN]        
 *  key         [IN]        
 *  array       [?]         
 *  end_idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_7bit_find(S32 which, U16 key, ucs2_7bit_map *array, S32 end_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = end_idx;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;
        if (which == 0)
        {
            if (key == array[nMid].ucs2)
                return nMid;
            else if (key > array[nMid].ucs2)
            {
                nFirst = nMid + 1;
            }
            else
            {
                nLast = nMid - 1;
            }
        }
        else if (which == 1)
        {
            if (key == array[nMid].gsm)
                return nMid;
            else if (key > array[nMid].gsm)
            {
                nFirst = nMid + 1;
            }
            else
            {
                nLast = nMid - 1;
            }
        }
    }

    return -1;
}


/* For GSM-related counter start */
static mmi_7bit_counter_struct g_7bit_counter;

#ifdef __SMS_R8_NATION_LANGUAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_update_character_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_7bit_update_character_type(mmi_7bit_auto_detection_struct *auto_detection, U16 c, MMI_BOOL b_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguageType cur_lang = mmi_7bit_get_national_lang();
    gui_ems_table_mechanism_enum cur_m;
    S32 dt = 0, ext = 0, n_dt = 0, n_ext = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cur_lang == EMS_NL_DEFAULT)
    {
        /* only support default */
        return;
    }
    else
    {
        cur_m = mmi_7bit_get_table_mechanism();
        if (cur_m == EMS_AUTO_DETECTION)
        {
            dt = mmi_7bit_check_gsm_by_nl_table(c, EMS_NL_DEFAULT);
            n_dt = mmi_7bit_check_gsm_by_nl_table(c, cur_lang);
            ext = mmi_7bit_check_gsm_ext_character_by_nl_table(c, EMS_NL_DEFAULT);
            n_ext = mmi_7bit_check_gsm_ext_character_by_nl_table(c, cur_lang);

            if (!dt && !ext && n_ext)
            {
                /* this is the specific character for current language, which is located at
                 * the national extention table. And if Locking shift table exists, it is also
                 * located at it.
                 */
                if (b_add)
                    auto_detection->national_char++;
                else
                    auto_detection->national_char--;
            }
            else if(dt && !n_dt && !ext && !n_ext)
            {
                /* this is the character that is only located at the default table. If this kind of 
                 * character exist, the main table must use default table.
                 */
                if (b_add)
                    auto_detection->only_in_default++;
                else
                    auto_detection->only_in_default--;
            }
            else if(!n_dt && dt && n_ext)
            {
                /* this is the character that is removed from default table by Locking shift table, 
                 * but moved to the Single Shift table.  
                 */
                if (b_add)
                    auto_detection->only_not_in_locking++;
                else
                    auto_detection->only_not_in_locking--;
            }
            else if(!dt && n_dt && ext)
            {
                if (b_add)
                    auto_detection->in_ext_and_national++;
                else
                    auto_detection->in_ext_and_national--;
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_choose_national_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_7bit_choose_national_table(mmi_7bit_auto_detection_struct *auto_detection, EMSNationalLanguage *l)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguageType cur_lang = mmi_7bit_get_national_lang();


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auto_detection->national_char == 0)
    {
        /* all the characters is at the default or ext table */
        if (auto_detection->in_ext_and_national <= (12 * mmi_msg_get_seg_num())) /* 12 is the difference between default and locking mode */
        {
            l->locking_shift = EMS_NL_DEFAULT;
            l->single_shift = EMS_NL_DEFAULT;
        }
        else
        {
            l->locking_shift = cur_lang;
            l->single_shift = EMS_NL_DEFAULT;
        }
    }
    else
    {
        if (auto_detection->only_in_default > 0)
        {
            /* some character is only at the default table */
            l->locking_shift = EMS_NL_DEFAULT;
            l->single_shift = cur_lang;
        }
        else if(auto_detection->only_not_in_locking > 0)
        {
            /* some character is both at default and national ext table */
            if (auto_detection->national_char > auto_detection->only_not_in_locking + 3 * mmi_msg_get_seg_num())
            {
                l->locking_shift = cur_lang;
                l->single_shift = cur_lang;
            }
            else
            {
                l->locking_shift = EMS_NL_DEFAULT;
                l->single_shift = cur_lang;
            }
        }
        else
        {
            if (cur_lang == EMS_NL_SPANISH)
            {
                /* no Spanish locking table */
                l->locking_shift = EMS_NL_DEFAULT;
                l->single_shift = cur_lang;                
            }
            else
            {
                l->locking_shift = cur_lang;
                l->single_shift = EMS_NL_DEFAULT;
            }
        }
    }
    
}
#endif

static void mmi_7bit_counter_parse_all_text(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p = string;
    U16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_7bit_counter.gsm_count = 0;
    g_7bit_counter.gsm_ext_count = 0;
    g_7bit_counter.ucs2_count = 0;

    UI_STRING_GET_NEXT_CHARACTER(p, c);
    while(c != 0)
    {
        if (mmi_7bit_check_gsm(c))
        {
            g_7bit_counter.gsm_count++;
        }
        else if (mmi_7bit_check_gsm_ext_character(c))
        {
            g_7bit_counter.gsm_ext_count++;
        }
        else
            g_7bit_counter.ucs2_count++;

        UI_STRING_GET_NEXT_CHARACTER(p, c);
    }
}


void mmi_7bit_counter_init(U8* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
    EMSNationalLanguage l;
    U8 *p = string;
    U16 c;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_7bit_counter, 0, sizeof(mmi_7bit_counter_struct));

    if (string == NULL)
    {
        return;
    }

#ifdef __SMS_R8_NATION_LANGUAGE__
    if (cur_m == EMS_AUTO_DETECTION)
    {
        UI_STRING_GET_NEXT_CHARACTER(p, c);
        while(c != 0)
        {
            mmi_7bit_update_character_type(&g_7bit_counter.auto_detection, c, MMI_TRUE);
            
            UI_STRING_GET_NEXT_CHARACTER(p, c);
        }
        
        mmi_7bit_choose_national_table(&g_7bit_counter.auto_detection, &l);
        mmi_7bit_set_national_lang_table(&l);
    }
#endif

    mmi_7bit_counter_parse_all_text(string);
}

void mmi_7bit_counter_add(U8 *string, U16 c, S32 b_only_restore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
    EMSNationalLanguageType cur_lang = mmi_7bit_get_national_lang();
    EMSNationalLanguage old_l, new_l;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    if (cur_m == EMS_AUTO_DETECTION)
    {
        mmi_7bit_update_character_type(&g_7bit_counter.auto_detection, c, MMI_TRUE);
        if (g_7bit_counter.ucs2_count == 0)
        {
            mmi_7bit_choose_national_table(&g_7bit_counter.auto_detection, &new_l);
            mmi_7bit_get_national_lang_table(&old_l);
            if (new_l.locking_shift != old_l.locking_shift
                || new_l.single_shift != old_l.single_shift)
            {
                /* table is changed, all the text need to be re-counter */
                mmi_7bit_set_national_lang_table(&new_l);
                
                mmi_7bit_counter_parse_all_text(string);

                if (b_only_restore)
                    return;
            }
        }     
    }
#endif

    if (mmi_7bit_check_gsm(c))
    {
        g_7bit_counter.gsm_count++;
    }
    else if (mmi_7bit_check_gsm_ext_character(c))
    {
        g_7bit_counter.gsm_ext_count++;
    }
    else 
    {
    #ifdef __SMS_R8_NATION_LANGUAGE__
        if (cur_m == EMS_AUTO_DETECTION)
        {
            if (!mmi_7bit_test_gsm_character_in_all_table(c))
            {
                g_7bit_counter.ucs2_count++;
            }
        }
        else
    #endif
        {
            g_7bit_counter.ucs2_count++;
        }
    }
}

void mmi_7bit_counter_delete(U8 *string, U16 c, S32 b_only_restore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    gui_ems_table_mechanism_enum cur_m = mmi_7bit_get_table_mechanism();
    EMSNationalLanguageType cur_lang = mmi_7bit_get_national_lang();
    EMSNationalLanguage old_l, new_l;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    if (cur_m == EMS_AUTO_DETECTION)
    {
        mmi_7bit_update_character_type(&g_7bit_counter.auto_detection, c, MMI_FALSE);
        if (g_7bit_counter.ucs2_count <= 1)
        {
            mmi_7bit_choose_national_table(&g_7bit_counter.auto_detection, &new_l);
            mmi_7bit_get_national_lang_table(&old_l);
            if (new_l.locking_shift != old_l.locking_shift
                || new_l.single_shift != old_l.single_shift)
            {
                /* table is changed, all the text need to be re-counter */
                mmi_7bit_set_national_lang_table(&new_l);
                
                mmi_7bit_counter_parse_all_text(string);
                if (b_only_restore)
                    return;
            }
        }     
    }
#endif
    
    if (mmi_7bit_check_gsm(c))
    {
        g_7bit_counter.gsm_count--;
    }
    else if (mmi_7bit_check_gsm_ext_character(c))
    {
        g_7bit_counter.gsm_ext_count--;
    }
    else
        g_7bit_counter.ucs2_count--;
}


mmi_7bit_counter_struct* mmi_7bit_counter_get_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_7bit_counter;
}

/* For GSM-related counter end */

#ifdef __SMS_R8_NATION_LANGUAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_7bit_test_gsm_character_in_all_table
 * DESCRIPTION
 *  Test gsm character in all tables (default and national lauange table (4 tables))
 * PARAMETERS
 *  c       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_7bit_test_gsm_character_in_all_table(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguageType cur_lang = mmi_7bit_get_national_lang();
    S32 b = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b = mmi_7bit_check_gsm_by_nl_table(c, EMS_NL_DEFAULT);
    if (b)
        return MMI_TRUE;
    
    b = mmi_7bit_check_gsm_ext_character_by_nl_table(c, cur_lang);
    if (b)
        return MMI_TRUE;

            return MMI_FALSE;
}
#endif


kal_uint16 gui_ems_ucs2_to_nl_callback(EMSNationalLanguage lang, kal_uint8 *src, kal_uint8 *dest, kal_uint16 len, kal_uint8 seg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 out = len * 2;
#ifdef __SMS_R8_NATION_LANGUAGE__ 
    EMSNationalLanguage old_l;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__     
    mmi_7bit_get_national_lang_table(&old_l);
    mmi_7bit_set_national_lang_table(&lang);
#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
    /* if force 7bit, return NONE UCS2*/
    if (srv_sms_is_7bit_setting(SRV_SMS_SIM_1) == MMI_TRUE)
    {
        mmi_7bit_ucs2_to_gsm_string(src, dest, len, &out, 0x20, convert_non_standard_gsm, 1);
    }
    else
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
        mmi_7bit_ucs2_to_gsm_string(src, dest, len, &out, 0x20, NULL, 1);

#ifdef __SMS_R8_NATION_LANGUAGE__     
    mmi_7bit_set_national_lang_table(&old_l);
#endif    

    return (kal_uint16)out;
}


kal_uint16 gui_ems_nl_to_ucs2_callback(EMSNationalLanguage lang, kal_uint8 *src, kal_uint8 *dest, kal_uint16 len, kal_uint8 seg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 out = len * 2, ext_len = 0;
    S32 c = 0;
    static kal_uint8 last_c = 0;

#ifdef __SMS_R8_NATION_LANGUAGE__ 
    EMSNationalLanguage old_l;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (seg_num == 0)
        last_c = 0;

#ifdef __SMS_R8_NATION_LANGUAGE__     
    mmi_7bit_get_national_lang_table(&old_l);
    if (lang.locking_shift == EMS_NL_DEFAULT 
        && lang.single_shift == EMS_NL_DEFAULT)
    {
        // for backward compatiable
        // before 3GPP TS 23.038 spec, it use Turkish extension table
        // and the table include all characters in default extension table and adding more characters
        lang.single_shift = EMS_NL_TURKISH;
    }
    mmi_7bit_set_national_lang_table(&lang);
#endif
    
    if (seg_num >0 && last_c == 0x1b && len > 0)
    {
        /* update the last_c */
        last_c = src[len - 1];

        c = mmi_7bit_gsm_ext_to_ucs2_char(*src);
        if (c < 0)
        {
            c = mmi_7bit_gsm_to_ucs2_char(*src);
        }

        UI_STRING_INSERT_CHARACTER(dest, c);

        src++;
        len--;
        ext_len = 1;
    }
    else
    {
        /* update the last_c */
        last_c = (len > 0) ? src[len - 1] : 0;
    }

    mmi_7bit_gsm_to_ucs2_string(src, dest, len, &out, 0x20, NULL, 1);

#ifdef __SMS_R8_NATION_LANGUAGE__     
    mmi_7bit_set_national_lang_table(&old_l);
#endif   

    return (kal_uint16)(out + ext_len);
}

