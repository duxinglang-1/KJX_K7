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
 *	 gd_primitive_arm.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Primitive ARM related.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"

#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
   #include "mmu.h"
   #include "cache_sw.h"
#endif

#include "kal_general_types.h"
#include "kal_release.h"
#include "string.h"
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_primitive.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif 

#if 0//defined(__MTK_TARGET__)
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
#ifdef __RVCT__
/* under construction !*/
#endif
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
/* under construction !*/
#ifdef __RVCT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else
int GDI_GRAY16SET(int add_end, int add)
{
    do
    {
        U32 color_of_two_pixels = ((U32*)add)[0]; //BBBBBGGGGGGRRRRRBBBBBGGGGGGRRRRR
        U32 r, g, b;

        b = (color_of_two_pixels & 0xF000F000) >> 11; // B : 00000000000BBBB0|00000000000BBBB0
        g = (color_of_two_pixels & 0x07800780) >> 5;  //2G : 0000000000GGGG00|0000000000GGGG00
        r = color_of_two_pixels & 0x001E001E;         // R : 00000000000RRRR0|00000000000RRRR0
        

        r = (r + g + b) >> 2; //(R+2G+B)/4
        r = r & 0x1F001F;     // To clear unneeded bits
        
        ((U32*)add)[0] = (r << 11) | (r << 6) | (r); //RRRRRRRRRR0RRRRR|RRRRRRRRRR0RRRRR
        
        add += 4;
        
    }while (add < add_end);
	return add;
}
#endif


/*
 * Fast SW resizer
 */
/* RGB565 macros for transform */
#define GDI_LAYER_SW_RESIZER_R_OF_RGB565(c)    (((c) << 16) >> 27)
#define GDI_LAYER_SW_RESIZER_G_OF_RGB565(c)    (((c) << 21) >> 26)
#define GDI_LAYER_SW_RESIZER_B_OF_RGB565(c)    (((c) << 27) >> 27)

/* RGB888 at bit [23:0] */
#define GDI_LAYER_SW_RESIZER_R_OF_RGB888(p)    (((p) << 8) >> 24)
#define GDI_LAYER_SW_RESIZER_G_OF_RGB888(p)    (((p) << 16) >> 24)
#define GDI_LAYER_SW_RESIZER_B_OF_RGB888(p)    (((p) << 24) >> 24)

/* ARGB8888 */
#define GDI_LAYER_SW_RESIZER_A_OF_ARGB8888(p)  ((p) >> 24)
#define GDI_LAYER_SW_RESIZER_R_OF_ARGB8888(p)  GDI_LAYER_SW_RESIZER_R_OF_RGB888(p)
#define GDI_LAYER_SW_RESIZER_G_OF_ARGB8888(p)  GDI_LAYER_SW_RESIZER_G_OF_RGB888(p)
#define GDI_LAYER_SW_RESIZER_B_OF_ARGB8888(p)  GDI_LAYER_SW_RESIZER_B_OF_RGB888(p)

#define GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS  16
#define GDI_LAYER_SW_RESIZER_TRANSFORM_ROUNDING_VALUE  (1 << (GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS - 1))
#define GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS   7   /* max 7 */

#define GDI_LAYER_SW_RESIZER_TRANSFORM_FP(x)  ((int)((float)(x) * (float)(1 << GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS)))
#define GDI_LAYER_SW_RESIZER_TRANSFORM_INT(x) ((x) << GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS)
#define GDI_LAYER_SW_RESIZER_TRANSFORM_TO_ROUND_INT(x)     (((x) + GDI_LAYER_SW_RESIZER_TRANSFORM_ROUNDING_VALUE) >> GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS)
#define GDI_LAYER_SW_RESIZER_TRANSFORM_TO_INT(x) ((x) >> GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS)

#define GET_PIXEL_16(mem)       (*((U16*)(mem)))
#define GET_PIXEL_24(mem)       ((((U8*)(mem))[0]) + (((U8*)(mem))[1] << 8) + (((U8*)(mem))[2] << 16))
#define GET_PIXEL_32(mem)       (*((U32*)(mem)))

#define GET_PIXEL_16_IDX(mem, i)    (*((U16*)(mem) + (i)))    
#define GET_PIXEL_24_IDX(mem, i)    ((((U8*)(mem))[3 * (i)]) + (((U8*)(mem))[3 * (i) + 1] << 8) + (((U8*)(mem))[3 * (i) + 2] << 16))
#define GET_PIXEL_32_IDX(mem, i)    (*((U32*)(mem) + (i)))

#define PUT_PIXEL_16(mem, p)    *((U16*)(mem)) = p
#define PUT_PIXEL_24(mem, p)       \
    do                             \
    {                              \
        U8 *mem_8 = (U8*)(mem);    \
        mem_8[0] = p;              \
        mem_8[1] = p >> 8;         \
        mem_8[2] = p >> 16;        \
    } while (0)

#define PUT_PIXEL_32(mem, p)    *((U32*)(mem)) = (p)

#define GDI_LAYER_SW_RESIZER_TRANSFORM_HANDLE_TRANSPARENT_PIXEL(source_key_color, p00, p10, p01, p11) \
do                                                  \
{                                                   \
    S32 transparent_mask;                        \
    transparent_mask = ((p00 == source_key_color) << 3) | ((p10 == source_key_color) << 2) | ((p01 == source_key_color) << 1) | (p11 == source_key_color); \
                                                    \
    switch (transparent_mask)                       \
    {                                               \
        case 1:                                     \
            p11 = p01;                              \
            break;                                  \
                                                    \
        case 2:                                     \
            p01 = p11;                              \
            break;                                  \
                                                    \
        case 3:                                     \
            p01 = p00;                              \
            p11 = p10;                              \
            break;                                  \
                                                    \
        case 4:                                     \
            p10 = p00;                              \
            break;                                  \
                                                    \
        case 5:                                     \
            p10 = p00;                              \
            p11 = p01;                              \
            break;                                  \
                                                    \
        case 6:                                     \
            p10 = p00;                              \
            p01 = p11;                              \
            break;                                  \
                                                    \
        case 7:                                     \
            p10 = p01 = p11 = p00;                  \
            break;                                  \
                                                    \
        case 8:                                     \
            p00 = p10;                              \
            break;                                  \
                                                    \
        case 9:                                     \
            p00 = p10;                              \
            p11 = p01;                              \
            break;                                  \
                                                    \
        case 10:                                    \
            p00 = p10;                              \
            p01 = p11;                              \
            break;                                  \
                                                    \
        case 11:                                    \
            p00 = p01 = p11 = p10;                  \
            break;                                  \
                                                    \
        case 12:                                    \
            p00 = p01;                              \
            p10 = p11;                              \
            break;                                  \
                                                    \
        case 13:                                    \
            p00 = p10 = p11 = p01;                  \
            break;                                  \
                                                    \
        case 14:                                    \
            p00 = p10 = p01 = p11;                  \
            break;                                  \
                                                    \
        case 15:                                    \
            /* this pixel is transparent */         \
            break;                                  \
    }                                               \
} while (0)


/*
 * bilinear interpolation
 */
#ifdef __TARGET_FEATURE_DSPMUL 


/* target version, optimized by ARM DSP extension */
#define GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE(pixel_bi, p00, p10, p01, p11, uv, source_key_color, bpp)                           \
do                                                                                                                                  \
{                                                                                                                                   \
    /* replace neighbor transparent pixels with black if the output pixel is a pure trasparent pixel */                             \
    /*GDI_LAYER_SW_RESIZER_TRANSFORM_HANDLE_TRANSPARENT_PIXEL(source_key_color, p00, p10, p01, p11);*/                                             \
                                                                                                                                    \
    /*                                                                                                                              \
     * optimized by DSP extension and fewer stack variables                                                                         \
     */                                                                                                                             \
    {                                                                                                                               \
        S32 line0, line1;                                                                                                        \
        S32 b0_b1, b2_b3;                                                                                                        \
        U32 red, green, blue;                                                                                                    \
        U32 opp_uv;                                                                                                              \
                                                                                                                                    \
        /*                                                                                                                          \
         * put 4 coefficients into 2 32-bit registers:                                                                              \
         *                                                                                                                          \
         * b0 = opp_u * opp_v;                                                                                                      \
         * b1 = u * opp_v;                                                                                                          \
         * b2 = opp_u * v;                                                                                                          \
         * b3 = u * v;                                                                                                              \
         */                                                                                                                         \
        opp_uv = 0x00800080 - uv;                                                                                                   \
        __asm                                                                                                                       \
        {                                                                                                                           \
            SMULTB b0, opp_uv, opp_uv;                                                                                              \
            SMULTB b1, uv, opp_uv;                                                                                                  \
            SMULTB b2, opp_uv, uv;                                                                                                  \
            SMULTB b3, uv, uv;                                                                                                      \
        }                                                                                                                           \
        b0_b1 = (b0 << 16) | b1;                                                                                                    \
        b2_b3 = (b2 << 16) | b3;                                                                                                    \
                                                                                                                                    \
        if (bpp == 16)                                                                                                              \
        {   /* 16-bit */                                                                                                            \
            U32     l0, l1, mask;                                                                                                \
                                                                                                                                    \
            /* put 4 16-bit neighbor pixels into 2 32-bit registers */                                                              \
            l0 = (p00 << 16) | p10;                                                                                                 \
            l1 = (p01 << 16) | p11;                                                                                                 \
                                                                                                                                    \
            __asm                                                                                                                   \
            {                                                                                                                       \
                /* 5-bit blue and red mask 0x001F001F */                                                                            \
                MOV     mask, 0x1F;                                                                                                 \
                ORR     mask, mask, mask, LSL 16;                                                                                   \
                                                                                                                                    \
                /* calculate B */                                                                                                   \
                AND     line0, l0, mask;                                                                                            \
                AND     line1, l1, mask;                                                                                            \
                SMULTT  blue, b0_b1, line0;                                                                                         \
                SMLABB  blue, b0_b1, line0, blue;                                                                                   \
                SMLATT  blue, b2_b3, line1, blue;                                                                                   \
                SMLABB  blue, b2_b3, line1, blue;                                                                                   \
                MOV     pixel_bi, blue, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                    \
                                                                                                                                    \
                /* calculate R */                                                                                                   \
                AND     line0, l0, mask, LSL 11;                                                                                    \
                AND     line1, l1, mask, LSL 11;                                                                                    \
                MOV     line0, line0, LSR 11;                                                                                       \
                MOV     line1, line1, LSR 11;                                                                                       \
                SMULTT  red, b0_b1, line0;                                                                                          \
                SMLABB  red, b0_b1, line0, red;                                                                                     \
                SMLATT  red, b2_b3, line1, red;                                                                                     \
                SMLABB  red, b2_b3, line1, red;                                                                                     \
                MOV     red, red, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                          \
                ORR     pixel_bi, pixel_bi, red, LSL 11;                                                                            \
                                                                                                                                    \
                /* 6-bit green mask 0x003F003F */                                                                                   \
                MOV     mask, 0x3F;                                                                                                 \
                ORR     mask, mask, mask, LSL 16;                                                                                   \
                                                                                                                                    \
                /* calculate G */                                                                                                   \
                AND     line0, l0, mask, LSL 5;                                                                                     \
                AND     line1, l1, mask, LSL 5;                                                                                     \
                SMULTT  green, b0_b1, line0;                                                                                        \
                SMLABB  green, b0_b1, line0, green;                                                                                 \
                SMLATT  green, b2_b3, line1, green;                                                                                 \
                SMLABB  green, b2_b3, line1, green;                                                                                 \
                MOV     green, green, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2 + 5);                                  \
                ORR     pixel_bi, pixel_bi, green, LSL 5;                                                                           \
            }                                                                                                                       \
        }                                                                                                                           \
        else if (bpp == 24)                                                                                                         \
        {   /* 24-bit */                                                                                                            \
            __asm                                                                                                                   \
            {                                                                                                                       \
                /* calculate B */                                                                                                   \
                AND     line0, p00, 0xFF;                                                                                           \
                SMULTB  blue, b0_b1, line0;         /* blue = b0 * B(p00) */                                                        \
                AND     line0, p10, 0xFF;                                                                                           \
                SMLABB  blue, b0_b1, line0, blue;   /* blue += b1 * B(p10) */                                                       \
                AND     line1, p01, 0xFF;                                                                                           \
                SMLATB  blue, b2_b3, line1, blue;   /* blue += b2 * B(p01) */                                                       \
                AND     line1, p11, 0xFF;                                                                                           \
                SMLABB  blue, b2_b3, line1, blue;   /* blue += b3 * B(p11) */                                                       \
                MOV     pixel_bi, blue, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);    /* pixel_bi = blue */           \
                                                                                                                                    \
                /* calculate R */                                                                                                   \
                MOV     line0, p00, LSL 8;                                                                                          \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMULTB  red, b0_b1, line0;          /* red = b0 * R(p00) */                                                         \
                MOV     line0, p10, LSL 8;                                                                                          \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMLABB  red, b0_b1, line0, red;     /* red += b1 * R(p10) */                                                        \
                MOV     line1, p01, LSL 8;                                                                                          \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLATB  red, b2_b3, line1, red;     /* red += b2 * R(p01) */                                                        \
                MOV     line1, p11, LSL 8;                                                                                          \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLABB  red, b2_b3, line1, red;     /* red += b3 * R(p11) */                                                        \
                MOV     red, red, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                          \
                ORR     pixel_bi, pixel_bi, red, LSL 16;    /* pixel_bi |= red << 16 */                                             \
                                                                                                                                    \
                /* calculate G */                                                                                                   \
                MOV     line0, p00, LSL 16;                                                                                         \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMULTB  green, b0_b1, line0;          /* green = b0 * G(p00) */                                                     \
                MOV     line0, p10, LSL 16;                                                                                         \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMLABB  green, b0_b1, line0, green;   /* green += b1 * G(p10) */                                                    \
                MOV     line1, p01, LSL 16;                                                                                         \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLATB  green, b2_b3, line1, green;   /* green += b2 * G(p01) */                                                    \
                MOV     line1, p11, LSL 16;                                                                                         \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLABB  green, b2_b3, line1, green;   /* green += b3 * G(p11) */                                                    \
                MOV     green, green, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                      \
                ORR     pixel_bi, pixel_bi, green, LSL 8;    /* pixel_bi |= green << 8 */                                           \
            }                                                                                                                       \
        }                                                                                                                           \
        else                                                                                                                        \
        {   /* 32-bit */                                                                                                            \
            S32 alpha;                                                                                                           \
                                                                                                                                    \
            __asm                                                                                                                   \
            {                                                                                                                       \
                /* calculate B */                                                                                                   \
                AND     line0, p00, 0xFF;                                                                                           \
                SMULTB  blue, b0_b1, line0;         /* blue = b0 * B(p00) */                                                        \
                AND     line0, p10, 0xFF;                                                                                           \
                SMLABB  blue, b0_b1, line0, blue;   /* blue += b1 * B(p10) */                                                       \
                AND     line1, p01, 0xFF;                                                                                           \
                SMLATB  blue, b2_b3, line1, blue;   /* blue += b2 * B(p01) */                                                       \
                AND     line1, p11, 0xFF;                                                                                           \
                SMLABB  blue, b2_b3, line1, blue;   /* blue += b3 * B(p11) */                                                       \
                MOV     pixel_bi, blue, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);    /* pixel_bi = blue */           \
                                                                                                                                    \
                /* calculate R */                                                                                                   \
                MOV     line0, p00, LSL 8;                                                                                          \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMULTB  red, b0_b1, line0;          /* red = b0 * R(p00) */                                                         \
                MOV     line0, p10, LSL 8;                                                                                          \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMLABB  red, b0_b1, line0, red;     /* red += b1 * R(p10) */                                                        \
                MOV     line1, p01, LSL 8;                                                                                          \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLATB  red, b2_b3, line1, red;     /* red += b2 * R(p01) */                                                        \
                MOV     line1, p11, LSL 8;                                                                                          \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLABB  red, b2_b3, line1, red;     /* red += b3 * R(p11) */                                                        \
                MOV     red, red, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                          \
                ORR     pixel_bi, pixel_bi, red, LSL 16;    /* pixel_bi |= red << 16 */                                             \
                                                                                                                                    \
                /* calculate G */                                                                                                   \
                MOV     line0, p00, LSL 16;                                                                                         \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMULTB  green, b0_b1, line0;          /* green = b0 * G(p00) */                                                     \
                MOV     line0, p10, LSL 16;                                                                                         \
                MOV     line0, line0, LSR 24;                                                                                       \
                SMLABB  green, b0_b1, line0, green;   /* green += b1 * G(p10) */                                                    \
                MOV     line1, p01, LSL 16;                                                                                         \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLATB  green, b2_b3, line1, green;   /* green += b2 * G(p01) */                                                    \
                MOV     line1, p11, LSL 16;                                                                                         \
                MOV     line1, line1, LSR 24;                                                                                       \
                SMLABB  green, b2_b3, line1, green;   /* green += b3 * G(p11) */                                                    \
                MOV     green, green, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                      \
                ORR     pixel_bi, pixel_bi, green, LSL 8;    /* pixel_bi |= green << 8 */                                           \
                                                                                                                                    \
                /* calculate A */                                                                                                   \
                MOV     line0, p00, LSR 24;                                                                                         \
                SMULTB  alpha, b0_b1, line0;          /* alpha = b0 * A(p00) */                                                     \
                MOV     line0, p10, LSR 24;                                                                                         \
                SMLABB  alpha, b0_b1, line0, alpha;   /* alpha += b1 * A(p10) */                                                    \
                MOV     line1, p01, LSR 24;                                                                                         \
                SMLATB  alpha, b2_b3, line1, alpha;   /* alpha += b2 * A(p01) */                                                    \
                MOV     line1, p11, LSR 24;                                                                                         \
                SMLABB  alpha, b2_b3, line1, alpha;   /* alpha += b3 * A(p11) */                                                    \
                MOV     alpha, alpha, LSR (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);                                      \
                ORR     pixel_bi, pixel_bi, alpha, LSL 24;    /* pixel_bi |= alpha << 8 */                                          \
            }                                                                                                                       \
        }                                                                                                                           \
    }                                                                                                                               \
} while (0)


#else /* __TARGET_FEATURE_DSPMUL */                                                                                                                                                       


#define GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE(pixel_bi, p00, p10, p01, p11, uv, source_key_color, bpp)                                                                                 \
do                                                                                                                                                                                        \
{                                                                                                                                                                                         \
    /* replace neighbor transparent pixels with black if the output pixel is a pure trasparent pixel */                                                                                   \
    /*GDI_LAYER_SW_RESIZER_TRANSFORM_HANDLE_TRANSPARENT_PIXEL(source_key_color, p00, p10, p01, p11);*/                                                                                                   \
    {                                                                                                                                                                                     \
        S32     b0, b1, b2, b3;                                                                                                                                                        \
        U32     opp_u, opp_v;                                                                                                                                                          \
        S32     u, v;                                                                                                                                                                  \
                                                                                                                                                                                          \
        /* put 4 16-bit neighbor pixels into 2 32-bit registers */                                                                                                                        \
        u = uv >> 16;                                                                                                                                                                     \
        v = uv & 0xFFFF;                                                                                                                                                                  \
                                                                                                                                                                                          \
        opp_u = (1 << GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - u;                                                                                                                 \
        opp_v = (1 << GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS) - v;                                                                                                                 \
                                                                                                                                                                                          \
        b0 = opp_u * opp_v;                                                                                                                                                               \
        b1 = u * opp_v;                                                                                                                                                                   \
        b2 = opp_u * v;                                                                                                                                                                   \
        b3 = u * v;                                                                                                                                                                       \
                                                                                                                                                                                          \
        if (bpp == 16)                                                                                                                                                                    \
        {   /* 16-bit */                                                                                                                                                                  \
            pixel_bi = (b0 * GDI_LAYER_SW_RESIZER_B_OF_RGB565(p00) + b1 * GDI_LAYER_SW_RESIZER_B_OF_RGB565(p10) + b2 * GDI_LAYER_SW_RESIZER_B_OF_RGB565(p01) + b3 * GDI_LAYER_SW_RESIZER_B_OF_RGB565(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);            \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_G_OF_RGB565(p00) + b1 * GDI_LAYER_SW_RESIZER_G_OF_RGB565(p10) + b2 * GDI_LAYER_SW_RESIZER_G_OF_RGB565(p01) + b3 * GDI_LAYER_SW_RESIZER_G_OF_RGB565(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 5;    \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_R_OF_RGB565(p00) + b1 * GDI_LAYER_SW_RESIZER_R_OF_RGB565(p10) + b2 * GDI_LAYER_SW_RESIZER_R_OF_RGB565(p01) + b3 * GDI_LAYER_SW_RESIZER_R_OF_RGB565(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 11;   \
        }                                                                                                                                                                                 \
        else if (bpp == 24)                                                                                                                                                               \
        {   /* 24-bit */                                                                                                                                                                  \
            pixel_bi = (b0 * GDI_LAYER_SW_RESIZER_B_OF_RGB888(p00) + b1 * GDI_LAYER_SW_RESIZER_B_OF_RGB888(p10) + b2 * GDI_LAYER_SW_RESIZER_B_OF_RGB888(p01) + b3 * GDI_LAYER_SW_RESIZER_B_OF_RGB888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);            \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_G_OF_RGB888(p00) + b1 * GDI_LAYER_SW_RESIZER_G_OF_RGB888(p10) + b2 * GDI_LAYER_SW_RESIZER_G_OF_RGB888(p01) + b3 * GDI_LAYER_SW_RESIZER_G_OF_RGB888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 8;    \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_R_OF_RGB888(p00) + b1 * GDI_LAYER_SW_RESIZER_R_OF_RGB888(p10) + b2 * GDI_LAYER_SW_RESIZER_R_OF_RGB888(p01) + b3 * GDI_LAYER_SW_RESIZER_R_OF_RGB888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 16;   \
        }                                                                                                                                                                                 \
        else                                                                                                                                                                              \
        {   /* 32-bit */                                                                                                                                                                  \
            pixel_bi = (b0 * GDI_LAYER_SW_RESIZER_B_OF_ARGB8888(p00) + b1 * GDI_LAYER_SW_RESIZER_B_OF_ARGB8888(p10) + b2 * GDI_LAYER_SW_RESIZER_B_OF_ARGB8888(p01) + b3 * GDI_LAYER_SW_RESIZER_B_OF_ARGB8888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2);    \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_G_OF_ARGB8888(p00) + b1 * GDI_LAYER_SW_RESIZER_G_OF_ARGB8888(p10) + b2 * GDI_LAYER_SW_RESIZER_G_OF_ARGB8888(p01) + b3 * GDI_LAYER_SW_RESIZER_G_OF_ARGB8888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 8;        \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_R_OF_ARGB8888(p00) + b1 * GDI_LAYER_SW_RESIZER_R_OF_ARGB8888(p10) + b2 * GDI_LAYER_SW_RESIZER_R_OF_ARGB8888(p01) + b3 * GDI_LAYER_SW_RESIZER_R_OF_ARGB8888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 16;       \
            pixel_bi |= ((b0 * GDI_LAYER_SW_RESIZER_A_OF_ARGB8888(p00) + b1 * GDI_LAYER_SW_RESIZER_A_OF_ARGB8888(p10) + b2 * GDI_LAYER_SW_RESIZER_A_OF_ARGB8888(p01) + b3 * GDI_LAYER_SW_RESIZER_A_OF_ARGB8888(p11)) >> (GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS * 2)) << 24;       \
        }                                                                                                                                                                                             \
    }                                                                                                                                                                                     \
} while (0)

    
#endif /* __TARGET_FEATURE_DSPMUL */


/* apply transform according to type, sampling, and color format */
#define GDI_LAYER_SW_RESIZER_APPLY_TRANSFORM(sampling_method, color_format, arg)    \
do                                                                                  \
{                                                                                   \
    switch (color_format)                                                           \
    {                                                                               \
        case GDI_COLOR_FORMAT_16:                                                   \
            gdi_layer_sw_resizer_apply_image_by_##sampling_method##_16 arg;         \
            break;                                                                  \
                                                                                    \
        case GDI_COLOR_FORMAT_24:                                                   \
            gdi_layer_sw_resizer_apply_image_by_##sampling_method##_24 arg;         \
            break;                                                                  \
                                                                                    \
        case GDI_COLOR_FORMAT_32:                                                   \
            gdi_layer_sw_resizer_apply_image_by_##sampling_method##_32 arg;         \
            break;                                                                  \
                                                                                    \
        case GDI_COLOR_FORMAT_32_PARGB:                                             \
            gdi_layer_sw_resizer_apply_image_by_##sampling_method##_32 arg;         \
            break;                                                                  \
                                                                                    \
        default:                                                                    \
            GDI_ASSERT(0);                                                          \
            break;                                                                  \
    }                                                                               \
} while (0)


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_sw_resizer_apply_image_by_nearest
 * DESCRIPTION
 *  Nearest neighborhood resizer.
 * PARAMETERS
 *  src_buffer            [IN]      input source buffer
 *  src_layer_width       [IN]      source layer width 
 *  src_x1                [IN]      source x1
 *  src_y1                [IN]      source y1
 *  src_x2                [IN]      source x2
 *  src_y2                [IN]      source y2
 *  dst_buffer            [OUT]     output dest. buffer
 *  dst_layer_width       [IN]      source y2
 *  dst_w                 [IN]      dest. rect width
 *  dst_h                 [IN]      dest. rect height
 *  dst_x1                [IN]      dest. clip x1
 *  dst_y1                [IN]      dest. clip y1
 *  dst_x2                [IN]      dest. clip x2
 *  dst_y2                [IN]      dest. clip y2
 *  dst_off_x             [IN]      x offset to the dest. origin
 *  dst_off_y             [IN]      y offset to the dest. origin
 * RETURNS
 *  void
 *****************************************************************************/
#define GDI_LAYER_SW_RESIZER_FUNC(bpp)                                                                  \
void gdi_layer_sw_resizer_apply_image_by_nearest_##bpp(                                                 \
        U8 *src_buffer,                                                                                 \
        S32 src_layer_width,                                                                            \
        S32 src_x1,                                                                                     \
        S32 src_y1,                                                                                     \
        S32 src_x2,                                                                                     \
        S32 src_y2,                                                                                     \
        U8 *dst_buffer,                                                                                 \
        S32 dst_layer_width,                                                                            \
        S32 dst_w,                                                                                      \
        S32 dst_h,                                                                                      \
        S32 dst_x1,                                                                                     \
        S32 dst_y1,                                                                                     \
        S32 dst_x2,                                                                                     \
        S32 dst_y2,                                                                                     \
        S32 dst_off_x,                                                                                  \
        S32 dst_off_y)                                                                                  \
{                                                                                                       \
    /*----------------------------------------------------------------*/                                \
    /* Local Variables                                                */                                \
    /*----------------------------------------------------------------*/                                \
    S32 x, y;                                                                                           \
    S32 sy;                                                                                             \
    S32 old_src_y;                                                                                      \
    S32 dx, dy;                                                                                         \
    U8 *dst_ptr, *src_ptr;                                                                              \
    S32 src_pitch, dst_pitch;                                                                           \
    S32 src_x, src_y;                                                                                   \
                                                                                                        \
    /*----------------------------------------------------------------*/                                \
    /* Code Body                                                      */                                \
    /*----------------------------------------------------------------*/                                \
    dx = GDI_LAYER_SW_RESIZER_TRANSFORM_FP(1.0) * (src_x2 - src_x1 + 1) / dst_w;                        \
    dy = GDI_LAYER_SW_RESIZER_TRANSFORM_FP(1.0) * (src_y2 - src_y1 + 1) / dst_h;                        \
    dst_w = dst_x2 - dst_x1 + 1;                                                                        \
    dst_h = dst_y2 - dst_y1 + 1;                                                                        \
    dst_pitch = (dst_layer_width - dst_w) * ((bpp) / 8);                                                \
    src_pitch = src_layer_width * ((bpp) / 8);                                                          \
    src_ptr = src_buffer + (src_y1 * src_layer_width + src_x1) * ((bpp) / 8);                           \
    dst_ptr = dst_buffer + (dst_y1 * dst_layer_width + dst_x1) * ((bpp) / 8);                           \
                                                                                                        \
    src_y2 = src_y2 - src_y1;                                                                           \
    src_y = dst_off_y * dy;                                                                             \
    old_src_y = 0;                                                                                      \
                                                                                                        \
    for (y = dst_h - 1; y >= 0; y--)                                                                    \
    {                                                                                                   \
        sy = GDI_LAYER_SW_RESIZER_TRANSFORM_TO_INT(src_y);                                              \
        if ((old_src_y != sy) && (sy != src_y2))                                                        \
        {                                                                                               \
            src_ptr += (sy - old_src_y) * src_pitch;                                                    \
            old_src_y = sy;                                                                             \
        }                                                                                               \
                                                                                                        \
        src_x = dst_off_x * dx;                                                                         \
        src_y += dy;                                                                                    \
                                                                                                        \
        for (x = dst_w - 1; x >= 0; x--)                                                                \
        {                                                                                               \
            PUT_PIXEL_##bpp(                                                                            \
                dst_ptr,                                                                                \
                GET_PIXEL_##bpp##_IDX(src_ptr, GDI_LAYER_SW_RESIZER_TRANSFORM_TO_INT(src_x)));          \
            dst_ptr += ((bpp) / 8);                                                                     \
                                                                                                        \
            src_x += dx;                                                                                \
        }                                                                                               \
        dst_ptr += dst_pitch;                                                                           \
    }                                                                                                   \
}


/* resizers for each color format in nearest */
GDI_LAYER_SW_RESIZER_FUNC(16)
GDI_LAYER_SW_RESIZER_FUNC(24)
GDI_LAYER_SW_RESIZER_FUNC(32)


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_sw_resizer_apply_image_by_bilinear
 * DESCRIPTION
 *  Nearest neighborhood resizer.
 * PARAMETERS
 *  src_buffer            [IN]      input source buffer
 *  src_layer_width       [IN]      source layer width 
 *  src_x1                [IN]      source x1
 *  src_y1                [IN]      source y1
 *  src_x2                [IN]      source x2
 *  src_y2                [IN]      source y2
 *  dst_buffer            [OUT]     output dest. buffer
 *  dst_layer_width       [IN]      source y2
 *  dst_w                 [IN]      dest. rect width
 *  dst_h                 [IN]      dest. rect height
 *  dst_x1                [IN]      dest. clip x1
 *  dst_y1                [IN]      dest. clip y1
 *  dst_x2                [IN]      dest. clip x2
 *  dst_y2                [IN]      dest. clip y2
 *  dst_off_x             [IN]      x offset to the dest. origin
 *  dst_off_y             [IN]      y offset to the dest. origin
 * RETURNS
 *  void
 *****************************************************************************/
#define GDI_LAYER_SW_RESIZER_BILINEAR_FUNC(bpp, _source_key_color)                                                              \
void gdi_layer_sw_resizer_apply_image_by_bilinear_##bpp(                                                                        \
        U8 *src_buffer,                                                                                                         \
        S32 src_layer_width,                                                                                                    \
        S32 src_x1,                                                                                                             \
        S32 src_y1,                                                                                                             \
        S32 src_x2,                                                                                                             \
        S32 src_y2,                                                                                                             \
        U8 *dst_buffer,                                                                                                         \
        S32 dst_layer_width,                                                                                                    \
        S32 dst_w,                                                                                                              \
        S32 dst_h,                                                                                                              \
        S32 dst_x1,                                                                                                             \
        S32 dst_y1,                                                                                                             \
        S32 dst_x2,                                                                                                             \
        S32 dst_y2,                                                                                                             \
        S32 dst_off_x,                                                                                                          \
        S32 dst_off_y)                                                                                                          \
{                                                                                                                               \
    /*----------------------------------------------------------------*/                                                        \
    /* Local Variables                                                */                                                        \
    /*----------------------------------------------------------------*/                                                        \
    S32 x, y;                                                                                                                   \
    S32 sy;                                                                                                                     \
    S32 old_src_y;                                                                                                              \
    S32 dx, dy;                                                                                                                 \
    U8 *dst_ptr, *src_ptr;                                                                                                      \
    U32 u, v, uv;                                                                                                               \
    U32 p00, p10, p01, p11;                                                                                                     \
    U32 pixel_bi;                                                                                                               \
    S32 src_width = src_layer_width;                                                                                            \
    U8 *src_pixel_p;                                                                                                            \
    S32 b0, b1, b2, b3;                                                                                                         \
    S32 src_pitch, dst_pitch;                                                                                                   \
    S32 src_x, src_y;                                                                                                           \
                                                                                                                                \
    /*----------------------------------------------------------------*/                                                        \
    /* Code Body                                                      */                                                        \
    /*----------------------------------------------------------------*/                                                        \
    dx = GDI_LAYER_SW_RESIZER_TRANSFORM_FP(1.0) * (src_x2 - src_x1 + 1) / dst_w;                                                \
    dy = GDI_LAYER_SW_RESIZER_TRANSFORM_FP(1.0) * (src_y2 - src_y1 + 1) / dst_h;                                                \
    dst_w = dst_x2 - dst_x1 + 1;                                                                                                \
    dst_h = dst_y2 - dst_y1 + 1;                                                                                                \
    dst_pitch = (dst_layer_width - dst_w) * ((bpp) / 8);                                                                        \
    src_pitch = src_layer_width * ((bpp) / 8);                                                                                  \
    src_ptr = src_buffer + (src_y1 * src_layer_width + src_x1) * ((bpp) / 8);                                                   \
    dst_ptr = dst_buffer + (dst_y1 * dst_layer_width + dst_x1) * ((bpp) / 8);                                                   \
                                                                                                                                \
    src_x2 = src_x2 - src_x1;                                                                                                   \
    src_y2 = src_y2 - src_y1;                                                                                                   \
    src_y = dst_off_y * dy;                                                                                                     \
    old_src_y = 0;                                                                                                              \
                                                                                                                                \
    for (y = dst_h - 1; y >= 0; y--)                                                                                            \
    {                                                                                                                           \
        sy = GDI_LAYER_SW_RESIZER_TRANSFORM_TO_INT(src_y);                                                                      \
        if (old_src_y != sy)                                                                                                    \
        {                                                                                                                       \
            src_ptr += (sy - old_src_y) * src_pitch;                                                                            \
            old_src_y = sy;                                                                                                     \
        }                                                                                                                       \
                                                                                                                                \
        src_x = dst_off_x * dx;                                                                                                 \
                                                                                                                                \
        v = (U32)src_y << (32 - GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS);                                                 \
        v >>= 32 - GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS;                                                    \
                                                                                                                                \
        src_y += dy;                                                                                                            \
                                                                                                                                \
        for (x = dst_w - 1; x >= 0; x--)                                                                                        \
        {                                                                                                                       \
            S32 src_x_int;                                                                                                      \
                                                                                                                                \
            src_x_int = GDI_LAYER_SW_RESIZER_TRANSFORM_TO_INT(src_x);                                                           \
                                                                                                                                \
            u = (U32)src_x << (32 - GDI_LAYER_SW_RESIZER_TRANSFORM_PRECISION_BITS);                                             \
            u >>= 32 - GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE_BITS;                                                \
            uv = (u << 16) | v;                                                                                                 \
                                                                                                                                \
            src_pixel_p = src_ptr + src_x_int * ((bpp) / 8);                                                                    \
            p00 = GET_PIXEL_##bpp##_IDX(src_pixel_p, 0);                                                                        \
            p10 = GET_PIXEL_##bpp##_IDX(src_pixel_p, 1);                                                                        \
            p01 = GET_PIXEL_##bpp##_IDX(src_pixel_p, src_width);                                                                \
            p11 = GET_PIXEL_##bpp##_IDX(src_pixel_p, src_width + 1);                                                            \
                                                                                                                                \
            /* (x + 1) line */                                                                                                  \
            if (src_x_int >= src_x2)                                                                                            \
            {                                                                                                                   \
                p10 = p00;                                                                                                      \
                p11 = p01;                                                                                                      \
            }                                                                                                                   \
                                                                                                                                \
            /* (y + 1) line */                                                                                                  \
            if (sy >= src_y2)                                                                                                   \
            {                                                                                                                   \
                p01 = p00;                                                                                                      \
                p11 = p10;                                                                                                      \
            }                                                                                                                   \
                                                                                                                                \
            GDI_LAYER_SW_RESIZER_TRANSFORM_BILINEAR_INTERPOLATE(pixel_bi, p00, p10, p01, p11, uv, _source_key_color, bpp);      \
                                                                                                                                \
			if ((bpp != 32) && (pixel_bi == _source_key_color)) \
			{ \
				pixel_bi ^= 1; \
			} \
																																\
            PUT_PIXEL_##bpp(dst_ptr, pixel_bi);                                                                                 \
                                                                                                                                \
            dst_ptr += ((bpp) / 8);                                                                                             \
                                                                                                                                \
            src_x += dx;                                                                                                        \
        }                                                                                                                       \
        dst_ptr += dst_pitch;                                                                                                   \
    }                                                                                                                           \
}


/* resizers for each color format in bilinear */
GDI_LAYER_SW_RESIZER_BILINEAR_FUNC(16, 0x1F)
GDI_LAYER_SW_RESIZER_BILINEAR_FUNC(24, 0xFF)
GDI_LAYER_SW_RESIZER_BILINEAR_FUNC(32, 0xFF)

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
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
/* under construction !*/
/* under construction !*/
    #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static const S16 g_gdi_alpha_inverse_table[256] = 
{
    0, /* FORBIDDEN 255 / 0 */
    32640, 16320, 10880, 8160, 6528, 5440, 4662, 4080, 
    3626, 3264, 2967, 2720, 2510, 2331, 2176, 2040, 
    1920, 1813, 1717, 1632, 1554, 1483, 1419, 1360, 
    1305, 1255, 1208, 1165, 1125, 1088, 1052, 1020, 
    989, 960, 932, 906, 882, 858, 836, 816, 
    796, 777, 759, 741, 725, 709, 694, 680, 
    666, 652, 640, 627, 615, 604, 593, 582, 
    572, 562, 553, 544, 535, 526, 518, 510, 
    502, 494, 487, 480, 473, 466, 459, 453, 
    447, 441, 435, 429, 423, 418, 413, 408, 
    402, 398, 393, 388, 384, 379, 375, 370, 
    366, 362, 358, 354, 350, 347, 343, 340, 
    336, 333, 329, 326, 323, 320, 316, 313, 
    310, 307, 305, 302, 299, 296, 294, 291, 
    288, 286, 283, 281, 278, 276, 274, 272, 
    269, 267, 265, 263, 261, 259, 257, 255, 
    253, 251, 249, 247, 245, 243, 241, 240, 
    238, 236, 234, 233, 231, 229, 228, 226, 
    225, 223, 222, 220, 219, 217, 216, 214, 
    213, 211, 210, 209, 207, 206, 205, 204, 
    202, 201, 200, 199, 197, 196, 195, 194, 
    193, 192, 190, 189, 188, 187, 186, 185, 
    184, 183, 182, 181, 180, 179, 178, 177, 
    176, 175, 174, 173, 172, 171, 170, 170, 
    169, 168, 167, 166, 165, 164, 164, 163, 
    162, 161, 160, 160, 159, 158, 157, 156, 
    156, 155, 154, 153, 153, 152, 151, 151, 
    150, 149, 149, 148, 147, 147, 146, 145, 
    145, 144, 143, 143, 142, 141, 141, 140, 
    140, 139, 138, 138, 137, 137, 136, 136, 
    135, 134, 134, 133, 133, 132, 132, 131, 
    131, 130, 130, 129, 129, 128, 128
};


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_fill_byte
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static gdi_color gdi_img_buf_convert_color(
    gdi_color from_color, 
    gdi_img_buf_color_format_enum to_format,
    gdi_img_buf_color_format_enum from_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef GDI_LAYER_PARGB6666_SUPPORT
    if (to_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888)
    {
        return GDI_PARGB6666_FROM_PARGB8888(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
    {
        return GDI_PARGB8888_FROM_PARGB6666(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
    {
        U32 alpha;
        from_color = GDI_PARGB8888_FROM_PARGB6666(from_color);
        alpha = GDI_A_OF_PARGB8888(from_color);
        return GDI_ARGB8888(alpha,
                GDI_DIVIDE_ALPHA_255(alpha, GDI_PR_OF_PARGB8888(from_color)),
                GDI_DIVIDE_ALPHA_255(alpha, GDI_PG_OF_PARGB8888(from_color)),
                GDI_DIVIDE_ALPHA_255(alpha, GDI_PB_OF_PARGB8888(from_color)));
    }
	else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
    {
        return GDI_RGB565_FROM_PARGB6666(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
    {
        return GDI_PARGB6666_FROM_RGB565(from_color);
    }

#endif
    if (to_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888)
    {
        return GDI_RGB565_FROM_RGB888(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565 &&
        (from_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 || from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888))
    {
        return GDI_RGB565_FROM_ARGB8888(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
    {
        return GDI_RGB888_FROM_RGB565(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888 &&
        (from_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 || from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888))
    {
        return GDI_RGB888_FROM_ARGB8888(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
    {
        return GDI_ARGB8888_FROM_RGB565(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888)
    {
        return GDI_ARGB8888_FROM_RGB888(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888)
    {
        U32 alpha;
        alpha = GDI_A_OF_PARGB8888(from_color);
        return GDI_ARGB8888(
                alpha,
                GDI_DIVIDE_ALPHA_255(alpha, GDI_PR_OF_PARGB8888(from_color)),
                GDI_DIVIDE_ALPHA_255(alpha, GDI_PG_OF_PARGB8888(from_color)),
                GDI_DIVIDE_ALPHA_255(alpha, GDI_PB_OF_PARGB8888(from_color)));
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
    {
        return GDI_PARGB8888_FROM_RGB565(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888)
    {
        return GDI_PARGB8888_FROM_RGB888(from_color);
    }
    else if (to_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888 &&
        from_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888)
    {
        return GDI_PARGB8888_FROM_ARGB8888(from_color);
    }
    else if (to_format == from_format)
    {
        /*
         * Caller should uses special handing for this case,
         * otherwise it will be very slow.
         */
        return from_color;
    }
    else
    {
        GDI_DEBUG_ASSERT(0);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
gdi_color gdi_img_buf_get_data(
    const U8 *ptr,
    gdi_img_buf_color_format_enum color_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (color_format)
    {
        case GDI_IMG_BUF_COLOR_FORMAT_RGB565:
            return GDI_MEM_GET_16(ptr);
        case GDI_IMG_BUF_COLOR_FORMAT_RGB888:
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB6666:
            return GDI_MEM_GET_24(ptr);
        case GDI_IMG_BUF_COLOR_FORMAT_ARGB8888:
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB8888:
            return GDI_MEM_GET_32(ptr);
        default:
            GDI_DEBUG_ASSERT(0);
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_put_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_put_data(
    const U8 *ptr,
    gdi_img_buf_color_format_enum color_format,
    gdi_color value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (color_format)
    {
        case GDI_IMG_BUF_COLOR_FORMAT_RGB565:
            GDI_MEM_PUT_16(ptr, value);
            break;
        case GDI_IMG_BUF_COLOR_FORMAT_RGB888:
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB6666:
            GDI_MEM_PUT_24(ptr, value);
            break;
        case GDI_IMG_BUF_COLOR_FORMAT_ARGB8888:
        case GDI_IMG_BUF_COLOR_FORMAT_PARGB8888:
            GDI_MEM_PUT_32(ptr, value);
            break;
        default:
            GDI_DEBUG_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_fill_byte
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_fill_byte(
    gdi_img_buf_struct *dst_buf, 
    U8 dst_byte,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 line_size;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    line_size   = width * GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format);
    for (i = height; i != 0; i--)
    {
        memset(dst_ptr, dst_byte, line_size);
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_fill_color_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_fill_color_16(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *color_ptr = (U8 *)&dst_color;
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 line_size;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 2);

    /* Optimize for one pixel. */
    if (width == 1 && height == 1)
    {
        GDI_MEM_PUT_16(dst_buf->ptr, dst_color);
        return;
    }

    /* Optimize for 0x0000 or 0xffff, etc. */
    if (color_ptr[0] == color_ptr[1])
    {
        gdi_img_buf_fill_byte(dst_buf, color_ptr[0], width, height);
        return;
    }

    /* Optimize for 16bits color fill */
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    line_size   = width * 2;
    for (i = height; i != 0; i--)
    {
        gdi_memset16(dst_ptr, (U16)dst_color, line_size);
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_fill_color_24
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_fill_color_24(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *color_ptr = (U8 *)&dst_color;
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 3);

    /* Optimize for one pixel. */
    if (width == 1 && height == 1)
    {
        GDI_MEM_PUT_24(dst_buf->ptr, dst_color);
        return;
    }

    /* Optimize for 0x0000 or 0xffff, etc. */
    if (color_ptr[0] == color_ptr[1] && 
        color_ptr[0] == color_ptr[2])
    {
        gdi_img_buf_fill_byte(dst_buf, color_ptr[0], width, height);
        return;
    }

    // TODO: need optimize
    /* Optimize for 16bits color fill */
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        for (i = width; i != 0; i--)
        {
            GDI_MEM_PUT_24(dst_line_ptr, dst_color);
            dst_line_ptr += 3;
        }
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_fill_color_32
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_fill_color_32(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *color_ptr = (U8 *)&dst_color;
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 4);

    /* Optimize for one pixel. */
    if (width == 1 && height == 1)
    {
        GDI_MEM_PUT_32(dst_buf->ptr, dst_color);
        return;
    }

    /* Optimize for 0x0000 or 0xffff, etc. */
    if (color_ptr[0] == color_ptr[1] && 
        color_ptr[0] == color_ptr[2] &&
        color_ptr[0] == color_ptr[3])
    {
        gdi_img_buf_fill_byte(dst_buf, color_ptr[0], width, height);
        return;
    }

    // TODO: need optimize
    /* Optimize for 16bits color fill */
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        for (i = width; i != 0; i--)
        {
            GDI_MEM_PUT_32(dst_line_ptr, dst_color);
            dst_line_ptr += 4;
        }
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_color_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_color_16(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_a;
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 2);

    color_a = 255 - GDI_A_OF_PARGB8888(pargb8888_color);            
    
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel_16 = GDI_MEM_GET_16(dst_line_ptr);
            U32 pixel = GDI_ARGB8888_FROM_RGB565(pixel_16);

            pixel = GDI_RGB888(
                GDI_DIV_255(GDI_R_OF_RGB888(pixel) * color_a),
                GDI_DIV_255(GDI_G_OF_RGB888(pixel) * color_a),
                GDI_DIV_255(GDI_B_OF_RGB888(pixel) * color_a));
            pixel += pargb8888_color;

            GDI_MEM_PUT_16(dst_line_ptr, GDI_RGB565_FROM_RGB888(pixel));

            dst_line_ptr += 2;
        }
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_color_24
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_color_24(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rgb888_color;
    U32 color_a;
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 3);

    rgb888_color = GDI_RGB888_FROM_ARGB8888(pargb8888_color);
    color_a = 255 - GDI_A_OF_PARGB8888(pargb8888_color);            
    
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = GDI_MEM_GET_24(dst_line_ptr);
            pixel = GDI_RGB888(
                GDI_DIV_255(GDI_R_OF_RGB888(pixel) * color_a),
                GDI_DIV_255(GDI_G_OF_RGB888(pixel) * color_a),
                GDI_DIV_255(GDI_B_OF_RGB888(pixel) * color_a));
            pixel += rgb888_color;

            GDI_MEM_PUT_24(dst_line_ptr, pixel);

            dst_line_ptr += 3;
        }
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_color_24
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_color_PARGB6666(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *dst_ptr;
    kal_int32 dst_pitch;
    kal_int32 i, j;
    kal_uint32 inv_a6;
    gdi_color pargb6666_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 3);

    inv_a6 = 0x3f - GDI_BITS_8_to_6(GDI_A_OF_PARGB8888(pargb8888_color));
    pargb6666_color = GDI_PARGB6666_FROM_PARGB8888(pargb8888_color);
    
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        kal_uint8 *dst_line_ptr = dst_ptr;
        for (i = width; i != 0; i--)
        {
            kal_uint32 pixel = GDI_MEM_GET_24(dst_line_ptr);
            pixel = GDI_PARGB6666(
                GDI_DIV_63(GDI_A_OF_PARGB6666(pixel) * inv_a6),
                GDI_DIV_63(GDI_PR_OF_PARGB6666(pixel) * inv_a6),
                GDI_DIV_63(GDI_PG_OF_PARGB6666(pixel) * inv_a6),
                GDI_DIV_63(GDI_PB_OF_PARGB6666(pixel) * inv_a6));
            pixel += pargb6666_color;
            
            GDI_MEM_PUT_24(dst_line_ptr, pixel);

            dst_line_ptr += 3;
        }
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_color_PARGB8888
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_color_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_a;
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    //GDI_DEBUG_ASSERT(dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);

    color_a = 255 - GDI_A_OF_PARGB8888(pargb8888_color);
    
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = GDI_MEM_GET_32(dst_line_ptr);            
            pixel = GDI_PARGB8888(
                GDI_DIV_255(GDI_A_OF_ARGB8888(pixel) * color_a),
                GDI_DIV_255(GDI_R_OF_ARGB8888(pixel) * color_a),
                GDI_DIV_255(GDI_G_OF_ARGB8888(pixel) * color_a),
                GDI_DIV_255(GDI_B_OF_ARGB8888(pixel) * color_a));
            pixel += pargb8888_color;

            GDI_MEM_PUT_32(dst_line_ptr, pixel);

            dst_line_ptr += 4;
        }
        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_flatten_16_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_flatten_16_16(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color_key,
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 2);
    GDI_DEBUG_ASSERT(src_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(src_buf->color_format) == 2);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = GDI_MEM_GET_16(dst_line_ptr);
            if (pixel == dst_color_key)
            {
                pixel = GDI_MEM_GET_16(src_line_ptr);
            }
            GDI_MEM_PUT_16(dst_line_ptr, pixel);

            dst_line_ptr += 2;
            src_line_ptr += 2;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_flatten_general
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_flatten_general(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color_key,
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    gdi_img_buf_color_format_enum dst_color_format;
    S32 dst_pixel_bytes;
    S32 dst_pitch;
    U8 *src_ptr;
    gdi_img_buf_color_format_enum src_color_format;
    S32 src_pixel_bytes;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf != NULL);

    dst_ptr             = dst_buf->ptr;
    dst_color_format    = dst_buf->color_format;
    dst_pixel_bytes     = GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_color_format);
    dst_pitch           = dst_buf->pitch_bytes;
    src_ptr             = src_buf->ptr;
    src_color_format    = src_buf->color_format;
    src_pixel_bytes     = GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(src_color_format);
    src_pitch           = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = gdi_img_buf_get_data(dst_line_ptr, dst_color_format);
            if (pixel == dst_color_key)
            {
                if (src_color_format == dst_color_format)
                {
                    pixel = gdi_img_buf_get_data(src_line_ptr, src_color_format);
                }
                else
                {
                    pixel = gdi_img_buf_convert_color(
                        gdi_img_buf_get_data(src_line_ptr, src_color_format),
                        dst_color_format,
                        src_color_format);
                }
            }
            gdi_img_buf_put_data(dst_line_ptr, dst_color_format, pixel);

            dst_line_ptr += dst_pixel_bytes;
            src_line_ptr += src_pixel_bytes;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_copy_same_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_copy_same_format(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    S32 line_size;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf != NULL);
    GDI_DEBUG_ASSERT(dst_buf->color_format == src_buf->color_format);
    
    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    line_size   = width * GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format);
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (i = height; i != 0; i--)
    {
        memcpy(dst_ptr, src_ptr, line_size);
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_copy_general
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_copy_general(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    U8 *dst_ptr;
    gdi_img_buf_color_format_enum dst_color_format;
    S32 dst_pixel_bytes;
    S32 dst_pitch;
    U8 *src_ptr;
    gdi_img_buf_color_format_enum src_color_format;
    S32 src_pixel_bytes;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf != NULL);

    dst_ptr             = dst_buf->ptr;
    dst_color_format    = dst_buf->color_format;
    dst_pixel_bytes     = GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_color_format);
    dst_pitch           = dst_buf->pitch_bytes;
    src_ptr             = src_buf->ptr;
    src_color_format    = src_buf->color_format;
    src_pixel_bytes     = GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(src_color_format);
    src_pitch           = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = gdi_img_buf_convert_color(
                            gdi_img_buf_get_data(src_line_ptr, src_color_format),
                            dst_color_format,
                            src_color_format);
            gdi_img_buf_put_data(dst_line_ptr, dst_color_format, pixel);

            dst_line_ptr += dst_pixel_bytes;
            src_line_ptr += src_pixel_bytes;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_16_PARGB8888
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_16_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 2);
    GDI_DEBUG_ASSERT(src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 src_color = GDI_MEM_GET_32(src_line_ptr);
            U32 src_a = 255 - GDI_A_OF_PARGB8888(src_color);            
    
            U32 pixel_16 = GDI_MEM_GET_16(dst_line_ptr);
            U32 pixel = GDI_ARGB8888_FROM_RGB565(pixel_16); 

            pixel = GDI_RGB888(
                GDI_DIV_255(GDI_R_OF_RGB888(pixel) * src_a),
                GDI_DIV_255(GDI_G_OF_RGB888(pixel) * src_a),
                GDI_DIV_255(GDI_B_OF_RGB888(pixel) * src_a));
            pixel += src_color;

            GDI_MEM_PUT_16(dst_line_ptr, GDI_RGB565_FROM_RGB888(pixel));

            dst_line_ptr += 2;
            src_line_ptr += 4;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_24_PARGB8888
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_24_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    GDI_DEBUG_ASSERT(GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(dst_buf->color_format) == 3);
    GDI_DEBUG_ASSERT(src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 src_color = GDI_MEM_GET_32(src_line_ptr);
            U32 src_rgb888 = GDI_RGB888_FROM_ARGB8888(src_color);
            U32 src_a = 255 - GDI_A_OF_PARGB8888(src_color);
    
            U32 pixel = GDI_MEM_GET_24(dst_line_ptr);
            pixel = GDI_RGB888(
                GDI_DIV_255(GDI_R_OF_RGB888(pixel) * src_a),
                GDI_DIV_255(GDI_G_OF_RGB888(pixel) * src_a),
                GDI_DIV_255(GDI_B_OF_RGB888(pixel) * src_a));
            pixel += src_rgb888;

            GDI_MEM_PUT_24(dst_line_ptr, pixel);

            dst_line_ptr += 3;
            src_line_ptr += 4;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_blending_PARGB8888_PARGB8888
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_blending_PARGB8888_PARGB8888(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    //GDI_DEBUG_ASSERT(dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);
    GDI_DEBUG_ASSERT(src_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 src_color = GDI_MEM_GET_32(src_line_ptr);
            U32 src_a = 255 - GDI_A_OF_PARGB8888(src_color);
    
            U32 pixel = GDI_MEM_GET_32(dst_line_ptr);
            pixel = GDI_PARGB8888(
                GDI_DIV_255(GDI_A_OF_ARGB8888(pixel) * src_a),
                GDI_DIV_255(GDI_R_OF_ARGB8888(pixel) * src_a),
                GDI_DIV_255(GDI_G_OF_ARGB8888(pixel) * src_a),
                GDI_DIV_255(GDI_B_OF_ARGB8888(pixel) * src_a));
            pixel += src_color;

            GDI_MEM_PUT_32(dst_line_ptr, pixel);

            dst_line_ptr += 4;
            src_line_ptr += 4;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


void gdi_img_buf_blending_PARGB8888_to_PARGB6666(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL);
    //GDI_DEBUG_ASSERT(dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);
    GDI_DEBUG_ASSERT(src_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 src_color_8888 = GDI_MEM_GET_32(src_line_ptr);
            U32 a_of_src_color_8888 = GDI_A_OF_PARGB8888(src_color_8888);

            if (a_of_src_color_8888 == 255)
            {
                U32 src_color_6666 = GDI_PARGB6666_FROM_PARGB8888(src_color_8888);
                GDI_MEM_PUT_24(dst_line_ptr, src_color_6666);
            }
            else if (a_of_src_color_8888 == 0)
            {
                /* Transparent, ignore */
            }
            else
            {
                U32 src_color_6666 = GDI_PARGB6666_FROM_PARGB8888(src_color_8888);
                U32 src_inv_a_6666 = 0x3f - GDI_A_OF_PARGB6666(src_color_6666);
        
                U32 pixel = GDI_MEM_GET_24(dst_line_ptr);
                pixel = GDI_PARGB6666(
                    GDI_DIV_63(GDI_A_OF_PARGB6666(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_PR_OF_PARGB6666(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_PG_OF_PARGB6666(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_PB_OF_PARGB6666(pixel) * src_inv_a_6666));
                pixel += src_color_6666;

                GDI_MEM_PUT_24(dst_line_ptr, pixel);
            }

            dst_line_ptr += 3;
            src_line_ptr += 4;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_convert_PARGB8888_from_ARGB8888
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_convert_PARGB8888_from_ARGB8888(
    gdi_img_buf_struct *buf, 
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr;
    S32 pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(buf != NULL);
    GDI_DEBUG_ASSERT(buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888);

    buf->color_format = GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;

    ptr     = buf->ptr;
    pitch   = buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *line_ptr = ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = GDI_MEM_GET_32(line_ptr);
            U32 pixel_a = GDI_A_OF_ARGB8888(pixel);
            pixel = GDI_PARGB8888(
                pixel_a,
                GDI_DIV_255(GDI_R_OF_ARGB8888(pixel) * pixel_a),
                GDI_DIV_255(GDI_G_OF_ARGB8888(pixel) * pixel_a),
                GDI_DIV_255(GDI_B_OF_ARGB8888(pixel) * pixel_a));
            GDI_MEM_PUT_32(line_ptr, pixel);

            line_ptr += 4;
        }
        ptr += pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_img_buf_convert_ARGB8888_from_PARGB8888
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_img_buf_convert_ARGB8888_from_PARGB8888(
    gdi_img_buf_struct *buf, 
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr;
    S32 pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(buf != NULL);
    GDI_DEBUG_ASSERT(buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888);

    buf->color_format = GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;

    ptr     = buf->ptr;
    pitch   = buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *line_ptr = ptr;
        for (i = width; i != 0; i--)
        {
            U32 pixel = GDI_MEM_GET_32(line_ptr);
            U32 pixel_a = GDI_A_OF_ARGB8888(pixel);
            S16 inv = g_gdi_alpha_inverse_table[pixel_a];
            pixel = GDI_PARGB8888(
                pixel_a,
                (GDI_PR_OF_PARGB8888(pixel) * inv) >> 7,
                (GDI_PG_OF_PARGB8888(pixel) * inv) >> 7,
                (GDI_PB_OF_PARGB8888(pixel) * inv) >> 7);
            GDI_MEM_PUT_32(line_ptr, pixel);

            line_ptr += 4;
        }
        ptr += pitch;            
    }
}



void gdi_img_buf_blending_PARGB6666_to_PARGB6666(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL && src_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 src_color_6666 = GDI_MEM_GET_24(src_line_ptr);
            U32 src_inv_a_6666 = 0x3f - GDI_A_OF_PARGB6666(src_color_6666);

            if (src_inv_a_6666 == 0) /* alpha == 0x3f */
            {
                GDI_MEM_PUT_24(dst_line_ptr, src_color_6666);
            }
            else if (src_inv_a_6666 == 0x3f) /* alpha == 0 */
            {
                /* Ignore */
            }
            else
            {
                U32 pixel = GDI_MEM_GET_24(dst_line_ptr);
                pixel = GDI_PARGB6666(
                    GDI_DIV_63(GDI_A_OF_PARGB6666(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_PR_OF_PARGB6666(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_PG_OF_PARGB6666(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_PB_OF_PARGB6666(pixel) * src_inv_a_6666));
                pixel += src_color_6666;

                GDI_MEM_PUT_24(dst_line_ptr, pixel);
            }

            dst_line_ptr += 3;
            src_line_ptr += 3;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}


void gdi_img_buf_blending_PARGB6666_to_RGB565(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dst_ptr;
    S32 dst_pitch;
    U8 *src_ptr;
    S32 src_pitch;
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(dst_buf != NULL && src_buf != NULL);
    GDI_DEBUG_ASSERT(src_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_ptr     = src_buf->ptr;
    src_pitch   = src_buf->pitch_bytes;
    for (j = height; j != 0; j--)
    {
        U8 *dst_line_ptr = dst_ptr;
        U8 *src_line_ptr = src_ptr;
        for (i = width; i != 0; i--)
        {
            U32 src_color_6666 = GDI_MEM_GET_24(src_line_ptr);
            U32 src_inv_a_6666 = 0x3f - GDI_A_OF_PARGB6666(src_color_6666);

            if (src_inv_a_6666 == 0) /* alpha == 0x3f */
            {
                U32 pixel = GDI_RGB565_FROM_PARGB6666(src_color_6666);
                GDI_MEM_PUT_16(dst_line_ptr, pixel);
            }
            else if (src_inv_a_6666 == 0x3f) /* alpha == 0 */
            {
                /* Transparent, ignore */
            }
            else
            {
                U32 pixel = GDI_MEM_GET_16(dst_line_ptr);
                pixel = GDI_PARGB6666(
                    0x3f,
                    GDI_DIV_63(GDI_BITS_5_to_6(GDI_R_OF_RGB565(pixel)) * src_inv_a_6666),
                    GDI_DIV_63(GDI_G_OF_RGB565(pixel) * src_inv_a_6666),
                    GDI_DIV_63(GDI_BITS_5_to_6(GDI_B_OF_RGB565(pixel)) * src_inv_a_6666));
                pixel += src_color_6666;

                pixel = GDI_RGB565_FROM_PARGB6666(pixel);
                GDI_MEM_PUT_16(dst_line_ptr, pixel);
            }

            dst_line_ptr += 2;
            src_line_ptr += 3;
        }
        dst_ptr += dst_pitch;            
        src_ptr += src_pitch;            
    }
}



