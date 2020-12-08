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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_alpha_bmp_internal.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Internal header for alpha bitmap  
 *
 *  To do the best optimization and get away from maintaining lots of code 
 *  path, MACRO CODE TEMPLATES are heavily used here. 
 * 
 *  TODO: DO NOT USE INLINE ASSEMBLY. Currently, only use inline assembly for ADS.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMAGE_ALPHA_BMP_INTERNAL_H__
#define __GDI_IMAGE_ALPHA_BMP_INTERNAL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "lcd_sw_rnd.h"
#include "MMI_features.h"
#include "MMIDataType.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RGB_16_BIT_TYPE         DRV_RGB_TO_HW(0, 255, 0)
#define COLOR_FORMAT_RGB3553    0xE007  /* 6205B, 6218 */
#define COLOR_FORMAT_RGB565     0x07E0  /* other than 6205B and 6218 */

#define DEST_ALPHA_VALUE        255     /* alpha value 255 on 32-bit ARGB destination layer */

/* Color index 0 is the transparent color. */
#define ABM_TRANSPARENT_COLOR_INDEX 0

/* (((x) + 127) / 255) */
#define ABM_DIV_255(x)  ((((x) + 128) * 257) >> 16)

/* GDI_IMAGE_ABM_DIV_15(x) == int(x / 15 + 0.5) */
#define GDI_IMAGE_ABM_DIV_15(x)         ((((x) + 8) * 4369) >> 16)

/* GDI_IMAGE_ABM_BITS_5_to_8(x) ~= int(x * 255 / 31 + 0.5) */
#define GDI_IMAGE_ABM_BITS_5_to_8(x)    (((x) << 3) | ((x) >> 2))

/* GDI_IMAGE_ABM_BITS_6_to_8(x) ~= int(x * 255 / 63 + 0.5) */
#define GDI_IMAGE_ABM_BITS_6_to_8(x)    (((x) << 2) | ((x) >> 4))


#define ABM_MAX(a, b)   ((a) > (b) ? (a) : (b))
#define ABM_MIN(a, b)   ((a) < (b) ? (a) : (b))

/* RGB888 at bit [23:0] */
#define R_OF_RGB888(p)                  (((p) << 8) >> 24)
#define G_OF_RGB888(p)                  (((p) << 16) >> 24)
#define B_OF_RGB888(p)                  (((p) << 24) >> 24)

/* ARGB8888 */
#define A_OF_ARGB8888(p)                ((p) >> 24)
#define R_OF_ARGB8888(p)                R_OF_RGB888(p)
#define G_OF_ARGB8888(p)                G_OF_RGB888(p)
#define B_OF_ARGB8888(p)                B_OF_RGB888(p)

/* RGB565 at bit [15:0] */
#define R_OF_RGB565(c)                  (((c) << 16) >> 27)
#define G_OF_RGB565(c)                  (((c) << 21) >> 26)
#define B_OF_RGB565(c)                  (((c) << 27) >> 27)

/* RGB565 at the high half word bit [31:16] */
#define R_OF_HIGH_RGB565(p) ((p) >> 27)
#define G_OF_HIGH_RGB565(p) (((p) << 5) >> 26)
#define B_OF_HIGH_RGB565(p) (((p) << 11) >> 27)

#define PUT_PIXEL_16(mem, p)    *((U16*)(mem)) = p
#define PUT_PIXEL_24(mem, p)       \
    do                             \
    {                              \
        U8 *mem_8 = (U8*)(mem);    \
        mem_8[0] = p;              \
        mem_8[1] = p >> 8;         \
        mem_8[2] = p >> 16;        \
    } while (0)

/* the ARGB alpha channel must be 255 to be OPAQUE */
#define PUT_PIXEL_32(mem, p)    *((U32*)(mem)) = (p)

#define GET_PIXEL_16(mem)       (*((U16*)(mem)))
#define GET_PIXEL_24(mem)       ((((U8*)(mem))[0]) + (((U8*)(mem))[1] << 8) + (((U8*)(mem))[2] << 16))
#define GET_PIXEL_32(mem)       (*((U32*)(mem)))

/* get palette color */
#define GET_PALETTE_COLOR_16(pal, p) GET_PIXEL_16((U8*)(pal) + 2 * (p)) // (((U16*)(pal))[p])
#define GET_PALETTE_COLOR_24(pal, p) GET_PIXEL_24((U8*)(pal) + 3 * (p))

// TODO: support RGB3553, but it is not feasible to do that?
#define RGB888_TO_RGB16(c)  rgb888_to_rgb565(c)
#define RGB16_TO_RGB888(c)  rgb565_to_rgb888(c)

#define ABM_DEFAULT_PALETTE_BPP     ((MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) ? 16 : 24)


/*
 * bitstream reader
 */
#define BIT_INIT(mem_ptr)               \
    {                                   \
        U32 BR_bits_buf;                \
        U16 *BR_bits_mem_ptr;           \
        U32 BR_bits_left;               \
                                        \
        BR_bits_mem_ptr = (U16*)(mem_ptr);              \
        BR_bits_buf = 0;                \
        BR_bits_left = 0;                               \
                                                        \
        /* take care of unalignment */                  \
        if ((U32)BR_bits_mem_ptr & 1)                   \
        {                                               \
            U8 *BR_mem_8 = (U8*)BR_bits_mem_ptr;        \
                                                        \
            BR_bits_buf = *BR_mem_8++;                  \
            BR_bits_mem_ptr = (U16*)BR_mem_8;           \
            BR_bits_left = 8;                           \
        }
  
#define BIT_END() }

#define BIT_READ(cb, data_mask, bit_data)  BR_bit_reader((cb), (data_mask), BR_bits_buf, BR_bits_left, BR_bits_mem_ptr, bit_data)
#define BIT_SEEK(s)                        BR_bit_seek((s), BR_bits_buf, BR_bits_left, BR_bits_mem_ptr)

/* bitstream read, output bit_data */
#define BR_bit_reader(cb, data_bit_mask, bits_buf, bits_left, bits_mem_ptr, bit_data) \
    do                                                                              \
    {                                                                               \
        /* bits in the buffer are not enough, append the buffer with 16 bits  */    \
        if (bits_left < cb)                                                         \
        {                                                                           \
            bits_buf += (*bits_mem_ptr++) << bits_left;                             \
            bits_left += 16;                                                        \
        }                                                                           \
                                                                                    \
        /* consume bits */                                                          \
        bit_data = bits_buf & (data_bit_mask);                                      \
        bits_buf >>= cb;                                                            \
        bits_left -= cb;                                                            \
    } while (0)


/* bitstream seek */
#define BR_bit_seek(seek_bits, bits_buf, bits_left, bits_mem_ptr)               \
    do                                                                          \
    {                                                                           \
        if (bits_left > seek_bits)                                              \
        {                                                                       \
            bits_left -= seek_bits;                                             \
            bits_buf >>= seek_bits;                                             \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            U32 sb = seek_bits;                                                 \
                                                                                \
            sb -= bits_left;                                                    \
            bits_mem_ptr += sb / 16;                                            \
            bits_buf = *bits_mem_ptr++;                                         \
            sb &= 0xF;                                                          \
            /* consume skipped bits */                                          \
            bits_buf >>= sb;                                                    \
            bits_left = 16 - sb;                                                \
        }                                                                       \
    } while (0)


#define ABM_ASSEMBLE_COLOR_ALPHA(out_color, color, alpha, BPP)                  \
    do                                                                          \
    {                                                                           \
        if (BPP == 32 || BPP == 33)                                             \
        {                                                                       \
            out_color = (U32)((alpha) << 24) | (color);                         \
        }                                                                       \
        else if (BPP == 25)                                                     \
        {                                                                       \
            out_color = (U32)(((alpha) >> 2 ) << 18) | (color);                 \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            out_color = (color);                                                \
        }                                                                       \
    } while(0)


/*
 * ABM decoder core functions (Only support from 16 or 24 bits)
 */
#define ABM_CONVERT_COLOR_WITHOUT_ALPHA(to_color, from_color, TO_BPP, FROM_BPP) \
    do                                                                          \
    {                                                                           \
        if (TO_BPP == FROM_BPP)                                                 \
        {                                                                       \
            to_color = (from_color);                                            \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            if (FROM_BPP == 16)                                                 \
            {                                                                   \
                if (TO_BPP == 24)                                               \
                {                                                               \
                    to_color = rgb565_to_rgb888(from_color);                    \
                }                                                               \
                else if (TO_BPP == 25)                                          \
                {                                                               \
                    to_color = rgb565_to_rgb666(from_color);                    \
                }                                                               \
                else if (TO_BPP == 32 || TO_BPP == 33)                          \
                {                                                               \
                    to_color = rgb565_to_rgb888(from_color);                    \
                }                                                               \
                else                                                            \
                {                                                               \
                    to_color = 0;                                               \
                }                                                               \
            }                                                                   \
            else if (FROM_BPP == 24)                                            \
            {                                                                   \
                if (TO_BPP == 16)                                               \
                {                                                               \
                    to_color = rgb888_to_rgb565(from_color);                    \
                }                                                               \
                else if (TO_BPP == 25)                                          \
                {                                                               \
                    to_color = rgb888_to_rgb666(from_color);                    \
                }                                                               \
                else if (TO_BPP == 32 || TO_BPP == 33)                          \
                {                                                               \
                    to_color = (from_color);                                    \
                }                                                               \
                else                                                            \
                {                                                               \
                    to_color = 0;                                               \
                }                                                               \
            }                                                                   \
            else                                                                \
            {                                                                   \
                to_color = 0;                                                   \
            }                                                                   \
        }                                                                       \
    } while(0)


#define ABM_CONVERT_COLOR(to_color, from_color, TO_BPP, FROM_BPP)               \
    do                                                                          \
    {                                                                           \
        if ((TO_BPP == 32 || TO_BPP == 33) && FROM_BPP == 32)                   \
        {                                                                       \
            to_color = argb8888_to_pargb8888(from_color);                       \
        }                                                                       \
        else if (TO_BPP == FROM_BPP)                                            \
        {                                                                       \
            to_color = (from_color);                                            \
        }                                                                       \
        else if (TO_BPP == 16 && FROM_BPP == 24)                                \
        {                                                                       \
            to_color = rgb888_to_rgb565(from_color);                            \
        }                                                                       \
        else if (TO_BPP == 24 && FROM_BPP == 16)                                \
        {                                                                       \
            to_color = rgb565_to_rgb888(from_color);                            \
        }                                                                       \
        else if ((TO_BPP == 32 || TO_BPP == 33) && FROM_BPP == 16)              \
        {                                                                       \
            to_color = rgb565_to_rgb888(from_color) | 0xff000000;               \
        }                                                                       \
        else if ((TO_BPP == 32 || TO_BPP == 33) && FROM_BPP == 24)              \
        {                                                                       \
            to_color = (from_color) | 0xff000000;                               \
        }                                                                       \
        else if (TO_BPP == 25 && FROM_BPP == 16)                                \
        {                                                                       \
            to_color = GDI_PARGB6666_FROM_RGB565(from_color);                   \
        }                                                                       \
        else if (TO_BPP == 25 && FROM_BPP == 24)                                \
        {                                                                       \
            to_color = GDI_PARGB6666_FROM_RGB888(from_color);                   \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            /* Not support */                                                   \
            to_color = 0;                                                       \
        }                                                                       \
    } while(0)


#define ABM_ALPHA_BLEND(out_color, src_color, color, alpha, BPP)                \
    do                                                                          \
    {                                                                           \
        if (BPP == 16)                                                          \
        {                                                                       \
            out_color = alpha_blend_16bit_pixel(src_color, color, alpha);       \
        }                                                                       \
        else if (BPP == 24)                                                     \
        {                                                                       \
            out_color = alpha_blend_24bit_pixel(src_color, color, alpha);       \
        }                                                                       \
        else if (BPP == 25)                                                     \
        {                                                                       \
            out_color = alpha_blend_6666_pixel_hq(src_color, color, alpha);     \
        }                                                                       \
        else /* if (BPP == 32 || BPP == 33) */                                  \
        {                                                                       \
            out_color = alpha_blend_32bit_pixel_hq(src_color, color, alpha);    \
        }                                                                       \
    } while(0)


#define ABM_ALPHA_BLEND_HQ(out_color, src_color, color, alpha, BPP)             \
    do                                                                          \
    {                                                                           \
        if (BPP == 16)                                                          \
        {                                                                       \
            out_color = alpha_blend_16bit_pixel_hq(src_color, color, alpha);    \
        }                                                                       \
        else if (BPP == 24)                                                     \
        {                                                                       \
            out_color = alpha_blend_24bit_pixel_hq(src_color, color, alpha);    \
        }                                                                       \
        else if (BPP == 25)                                                     \
        {                                                                       \
            out_color = alpha_blend_6666_pixel_hq(src_color, color, alpha);     \
        }                                                                       \
        else /* if (BPP == 32 || BPP == 33) */                                  \
        {                                                                       \
            out_color = alpha_blend_32bit_pixel_hq(src_color, color, alpha);    \
        }                                                                       \
    } while(0)


/*
 * get a pixel from looking up the palette by the color index
 */
#define ABM_GET_IMG_PIXEL(color, palette_ptr, color_index, TARGET_BPP, IMG_BPP) \
    do                                                                          \
    {                                                                           \
        if (IMG_BPP == 16)                                                      \
        {                                                                       \
            color = GET_PALETTE_COLOR_16((palette_ptr), (color_index));         \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            color = GET_PALETTE_COLOR_24((palette_ptr), (color_index));         \
        }                                                                       \
                                                                                \
        ABM_CONVERT_COLOR_WITHOUT_ALPHA(color, color, TARGET_BPP, IMG_BPP);     \
                                                                                \
    } while(0)    

/*
 * Read a pixel
 *
 */
#define ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP)                         \
    do                                                                          \
    {                                                                           \
        if (SRC_BPP == 16)                                                      \
        {                                                                       \
            src_pixel = GET_PIXEL_16(src_mem_ptr);                              \
        }                                                                       \
        else if (SRC_BPP == 24 || SRC_BPP == 25)                                \
        {                                                                       \
            src_pixel = GET_PIXEL_24(src_mem_ptr);                              \
        }                                                                       \
        else /* if (SRC_BPP == 32 || SRC_BPP == 33) */                          \
        {                                                                       \
            src_pixel = GET_PIXEL_32(src_mem_ptr);                              \
        }                                                                       \
    } while (0)


/*
 * Write a pixel
 */
#define ABM_PUT_PIXEL(out_mem_ptr, out_pixel, TARGET_BPP)                       \
    do                                                                          \
    {                                                                           \
        if (TARGET_BPP == 16)                                                   \
        {                                                                       \
            PUT_PIXEL_16(out_mem_ptr, out_pixel);                               \
        }                                                                       \
        else if (TARGET_BPP == 24 || TARGET_BPP == 25)                          \
        {                                                                       \
            PUT_PIXEL_24(out_mem_ptr, out_pixel);                               \
        }                                                                       \
        else /* if (TARGET_BPP == 32 || TARGET_BPP == 33) */                    \
        {                                                                       \
            PUT_PIXEL_32(out_mem_ptr, out_pixel);                               \
        }                                                                       \
    } while (0)


/* 
 * General ABM decoder for ABM images without alpha 
 */
#define ABM_DECODER_OUTPUT(TARGET_BPP, IMG_BPP)                                                     \
    do                                                                                              \
    {                                                                                               \
        U32 temp;                                                                                   \
        while (Y > 0)                                                                               \
        {                                                                                           \
            /* output a line */                                                                     \
            for (x = CLIP_WIDTH_MINUS_1; x >= 0; x--)                                               \
            {                                                                                       \
                /* read the pixel from bitstream */                                                 \
                BIT_READ(bpp, BPP_BIT_MASK, color_index);                                           \
                if (color_index != ABM_TRANSPARENT_COLOR_INDEX)                                     \
                {                                                                                   \
                    ABM_GET_IMG_PIXEL(img_pixel, PALETTE_PTR, color_index, TARGET_BPP, IMG_BPP);    \
                                                                                                    \
                    alpha = 0xff;                                                                   \
                    color_index -= ALPHA_CI_START;                                                  \
                    if (color_index >= 0)                                                           \
                    {                                                                               \
                        alpha -= ALPHA_PTR[color_index];                                            \
                    }                                                                               \
                    ABM_ASSEMBLE_COLOR_ALPHA(img_pixel, img_pixel, alpha, TARGET_BPP);              \
                }                                                                                   \
                else                                                                                \
                {                                                                                   \
                    img_pixel = 0;                                                                  \
                }                                                                                   \
                                                                                                    \
                ABM_PUT_PIXEL(out_mem_ptr, img_pixel, TARGET_BPP);                                  \
                                                                                                    \
                out_mem_ptr += (TARGET_BPP) / 8;                                                    \
            }                                                                                       \
                                                                                                    \
            /* line jump for src/out memory pointers and ABM bitstream */                           \
            temp = get_r11();                                                                       \
            dst_line_jump_bytes = temp >> 16;                                                       \
            abm_line_jump_bits = temp & 0xFFFF;                                                     \
            BIT_SEEK(abm_line_jump_bits);                                                           \
                                                                                                    \
            /* jump to the start pixel in the next line of the target layer */                      \
            out_mem_ptr += dst_line_jump_bytes;                                                     \
                                                                                                    \
            DECREASE_Y_BY_1();  /* y-- */                                                           \
        }                                                                                           \
    } while (0)


/* 
 * General ABM decoder for ABM images without alpha 
 */
#define ABM_DECODER_WITHOUT_ALPHA(TARGET_BPP, IMG_BPP)                                              \
    do                                                                                              \
    {                                                                                               \
        set_r9(BPP_BIT_MASK);                                                                       \
        set_r10(dst_line_jump_bytes);                                                               \
        set_r11(abm_line_jump_bits);                                                                \
                                                                                                    \
        while (Y > 0)                                                                               \
        {                                                                                           \
            /* output a line */                                                                     \
            for (x = CLIP_WIDTH_MINUS_1; x >= 0; x--)                                               \
            {                                                                                       \
                /* read the pixel from bitstream */                                                 \
                BIT_READ(bpp, get_r9(), color_index);                                               \
                if (color_index != ABM_TRANSPARENT_COLOR_INDEX)                                     \
                {                                                                                   \
                    ABM_GET_IMG_PIXEL(img_pixel, PALETTE_PTR, color_index, TARGET_BPP, IMG_BPP);    \
                    ABM_ASSEMBLE_COLOR_ALPHA(img_pixel, img_pixel, 0xff, TARGET_BPP);               \
                    ABM_PUT_PIXEL(out_mem_ptr, img_pixel, TARGET_BPP);                              \
                }                                                                                   \
                                                                                                    \
                out_mem_ptr += (TARGET_BPP) / 8;                                                    \
            }                                                                                       \
                                                                                                    \
            /* jump to the start pixel in the next line of the ABM image */                         \
            abm_line_jump_bits = get_r11();                                                         \
            BIT_SEEK(abm_line_jump_bits);                                                           \
                                                                                                    \
            /* jump to the start pixel in the next line of the target layer */                      \
            out_mem_ptr += get_r10();                                                               \
                                                                                                    \
            DECREASE_Y_BY_1();  /* y-- */                                                           \
        }                                                                                           \
    } while (0)


/* 
 * General ABM decoder for ABM images with alpha 
 */
#define ABM_DECODER_ALPHA(TARGET_BPP, SRC_BPP, IMG_BPP)                                         \
    do                                                                                          \
    {                                                                                           \
        U32 temp;                                                                               \
        for (x = CLIP_WIDTH_MINUS_1; x >= 0; x--)                                               \
        {                                                                                       \
            /* get color index from the ABM bitstream */                                        \
            BIT_READ(BPP, BPP_BIT_MASK, color_index);                                           \
            if (color_index != ABM_TRANSPARENT_COLOR_INDEX)                                     \
            {                                                                                   \
                ABM_GET_IMG_PIXEL(img_pixel, PALETTE_PTR, color_index, TARGET_BPP, IMG_BPP);    \
                                                                                                \
                color_index -= ALPHA_CI_START;                                                  \
                if (color_index >= 0)                                                           \
                {                                                                               \
                    alpha = ALPHA_PTR[color_index];                                             \
                    ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP);                            \
                    ABM_CONVERT_COLOR(src_pixel, src_pixel, TARGET_BPP, SRC_BPP);               \
                    ABM_ALPHA_BLEND(img_pixel, src_pixel, img_pixel, alpha, TARGET_BPP);        \
                }                                                                               \
                else                                                                            \
                {                                                                               \
                    ABM_ASSEMBLE_COLOR_ALPHA(img_pixel, img_pixel, 0xff, TARGET_BPP);           \
                }                                                                               \
            }                                                                                   \
            else                                                                                \
            {                                                                                   \
                ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP);                                \
                ABM_CONVERT_COLOR(img_pixel, src_pixel, TARGET_BPP, SRC_BPP);                   \
            }                                                                                   \
                                                                                                \
            ABM_PUT_PIXEL(out_mem_ptr, img_pixel, TARGET_BPP);                                  \
                                                                                                \
            /* increase src/out memory pointers */                                              \
            src_mem_ptr += (SRC_BPP) / 8;                                                       \
            out_mem_ptr += (TARGET_BPP) / 8;                                                    \
        }                                                                                       \
                                                                                                \
        /* line jump for src/out memory pointers and ABM bitstream */                           \
        temp = get_r11();                                                                       \
        dst_line_jump_bytes = temp >> 16;                                                       \
        abm_line_jump_bits = temp & 0xFFFF;                                                     \
        BIT_SEEK(abm_line_jump_bits);                                                           \
                                                                                                \
        src_mem_ptr += src_line_jump_bytes;                                                     \
        out_mem_ptr += dst_line_jump_bytes;                                                     \
                                                                                                \
        /* y-- */                                                                               \
        DECREASE_Y_BY_1();                                                                      \
    } while (Y > 0)


/* 
 * General ABM decoder for ABM images in 2 Layers mode
 */
#define ABM_DECODER_2_LAYERS(TARGET_BPP, SRC_BPP, IMG_BPP)                                      \
    do                                                                                          \
    {                                                                                           \
        U32 temp;                                                                               \
        for (x = CLIP_WIDTH_MINUS_1; x >= 0; x--)                                               \
        {                                                                                       \
            /* get color index p from the ABM bitstream */                                      \
            BIT_READ(BPP, BPP_BIT_MASK, color_index);                                           \
            if (color_index != ABM_TRANSPARENT_COLOR_INDEX)                                     \
            {                                                                                   \
                ABM_GET_IMG_PIXEL(img_pixel, PALETTE_PTR, color_index, TARGET_BPP, IMG_BPP);    \
                                                                                                \
                color_index -= ALPHA_CI_START;                                                  \
                if (color_index >= 0)                                                           \
                {                                                                               \
                    alpha = ALPHA_PTR[color_index];                                             \
                                                                                                \
                    ABM_READ_PIXEL(out_mem_ptr, src_pixel, TARGET_BPP);                         \
                    /* if the pixel is color key, than from the source layer */                 \
                    if (src_key_enable && src_pixel == src_key_value)                           \
                    {                                                                           \
                        ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP);                        \
                        ABM_CONVERT_COLOR(src_pixel, src_pixel, TARGET_BPP, SRC_BPP);           \
                    }                                                                           \
                                                                                                \
                    ABM_ALPHA_BLEND_HQ(img_pixel, src_pixel, img_pixel, alpha, TARGET_BPP);     \
                }                                                                               \
                else                                                                            \
                {                                                                               \
                    ABM_ASSEMBLE_COLOR_ALPHA(img_pixel, img_pixel, 0xff, TARGET_BPP);           \
                }                                                                               \
                                                                                                \
                ABM_PUT_PIXEL(out_mem_ptr, img_pixel, TARGET_BPP);                              \
            }                                                                                   \
                                                                                                \
            /* increase src/out memory pointers */                                              \
            src_mem_ptr += (SRC_BPP) / 8;                                                       \
            out_mem_ptr += (TARGET_BPP) / 8;                                                    \
        }                                                                                       \
                                                                                                \
        /* line jump for src/out memory pointers and ABM bitstream */                           \
        temp = get_r11();                                                                       \
        dst_line_jump_bytes = temp >> 16;                                                       \
        abm_line_jump_bits = temp & 0xFFFF;                                                     \
        BIT_SEEK(abm_line_jump_bits);                                                           \
                                                                                                \
        src_mem_ptr += src_line_jump_bytes;                                                     \
        out_mem_ptr += dst_line_jump_bytes;                                                     \
                                                                                                \
        /* y-- */                                                                               \
        DECREASE_Y_BY_1();                                                                      \
    } while (Y > 0)


/*
 * register storage
 */ 
/* 
 * R9 
 * bit[31:28]   BPP
 * bit[27:16]   ALPHA_CI_START
 * bit[15:0]    BPP_BIT_MASK 
 */
#define BPP_BIT_MASK        (get_r9() & 0xFFFF)         /* bit mask for consumed bits */
#define ALPHA_CI_START      ((get_r9() >> 16) & 0xFFF)
#define BPP                 (get_r9() >> 28)

/* R10 ALPHA_PTR */
#define ALPHA_PTR           ((U8*)get_r10())

//#define PALETTE_PTR         ((U8*)get_r12())
#define PALETTE_PTR         (palette_ptr)

/* 
 * R8
 * bit[31:16]   CLIP_WIDTH_MINUS_1
 * bit[15:0]    Y
 */
#define CLIP_WIDTH_MINUS_1  (get_r8() >> 16)
#define Y                   (get_r8() & 0xFFFF)
#define DECREASE_Y_BY_1()   \
    do                      \
    {                       \
        y = get_r8();       \
        y--;                \
        set_r8(y);          \
    } while (0)


#if (defined(__MTK_TARGET__) && !defined(__RVCT__))
/*
 * target, to use r8 to r11 in thumb mode
 */
static U32 register_context[4];

#define DECLARE_SET_REGISTER_FUNC(reg)  \
    static void set_r##reg(U32 value)   \
    {                                   \
        __asm                           \
        {                               \
            MOV     r##reg, value;      \
        }                               \
    }

#define DECLARE_GET_REGISTER_FUNC(reg)  \
    static U32 get_r##reg()             \
    {                                   \
        U32 value;                      \
                                        \
        __asm                           \
        {                               \
            MOV     value, r##reg;      \
        }                               \
        return value;                   \
    }                     
    
#else /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

/* 
 * simulator, use a static array to simulate registers
 */
static U32 register_pool[16];

#define DECLARE_SET_REGISTER_FUNC(reg)  \
    static void set_r##reg(U32 value)   \
    {                                   \
       register_pool[reg] = value;      \
    }


#define DECLARE_GET_REGISTER_FUNC(reg)  \
    static U32 get_r##reg()             \
    {                                   \
        return register_pool[reg];      \
    }

#endif /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

/*
 * For the thumb C compiler (tcc), it only utilizes r0-r7, r12, r14 
 * (total 10 regiters) for variable allocation. The following trick 
 * uses r8-r11 in thumb mode.
 */
/* set ARM register functions */
DECLARE_SET_REGISTER_FUNC(8)    /* set_r8() */
DECLARE_SET_REGISTER_FUNC(9)    /* set_r9() */
DECLARE_SET_REGISTER_FUNC(10)   /* set_r10() */
DECLARE_SET_REGISTER_FUNC(11)   /* set_r11() */
DECLARE_SET_REGISTER_FUNC(12)   /* set_r12() */ /* SCRATCH */

/* get ARM register functions */
DECLARE_GET_REGISTER_FUNC(8)    /* get_r8() */
DECLARE_GET_REGISTER_FUNC(9)    /* get_r9() */
DECLARE_GET_REGISTER_FUNC(10)   /* get_r10() */
DECLARE_GET_REGISTER_FUNC(11)   /* get_r11() */
DECLARE_GET_REGISTER_FUNC(12)   /* get_r12() */ /* SCRATCH */

/* save/restore register */
#define SAVE_REGISTER() save_register()
#define RESTORE_REGISTER() restore_register()

#if (defined(__MTK_TARGET__) && !defined(__RVCT__))

/* save r8 to r11 registers */
static void save_register(void)
{
    register_context[0] = get_r8();
    register_context[1] = get_r9();
    register_context[2] = get_r10();
    register_context[3] = get_r11();        
}
 
/* 
 * turn off C compiler optimization temporarily to prevent code from DISAPPEARING 
 * due to optimization 
 */
#pragma O0

/* restore r8 to r11 registers */
static U32 restore_register()
{    
    set_r8(register_context[0]);
    set_r9(register_context[1]);
    set_r10(register_context[2]);
    set_r11(register_context[3]);    
    
    return get_r8() + get_r9() + get_r10() + get_r11();
}

/* turn on optimization again */
#pragma O2

#else /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

static void save_register(void) {}
static void restore_register(void) {}

#endif /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

/* The ARM C compiler can support returning 4 32-bit variables in registers r0-r3. */
#ifdef __MTK_TARGET__
#define RET_VALUE_IN_REGS __value_in_regs
#else
#define RET_VALUE_IN_REGS
#endif

#define INVALID_RECT    (-1)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct 
{
    S32 x1, y1; /* top-left point */
    S32 x2, y2; /* bottom-right point */
} rect_struct;

/* ABM pre-processing info */
typedef struct
{
     U8     *abm_bitstream_ptr;
     U8     *palette_ptr;
     U8     *src_mem_ptr;
     U8     *out_mem_ptr;

     U32    abm_start_bit_offset;
     U32    dst_bpp;
     U32    src_bpp; 
     U32    alpha_color_num;
     U32    src_line_jump_bytes;
     U32    dst_line_jump_bytes;
     U32    abm_line_jump_bits;
     
     U32    bpp;
     U32    palette_bpp;

     U32    r8, r9, r10, r11;
} abm_info_struct;

/* ABM decode drawing mode */
typedef enum
{
    GDI_IMAGE_ABM_DECODE_MODE_AUTO,     /* Auto dectect */
    GDI_IMAGE_ABM_DECODE_MODE_OUTPUT,   /* Direct output */
    GDI_IMAGE_ABM_DECODE_MODE_SRC_KEY,  /* Source color key mode */
    GDI_IMAGE_ABM_DECODE_MODE_ALPHA,    /* Alpha Blending mode */
    GDI_IMAGE_ABM_DECODE_MODE_2_LAYERS, /* 2-Layers mode */
    GDI_IMAGE_ABM_DECODE_MODE_END_OF_ENUM
} gdi_image_abm_decode_mode_enum;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __GDI_IMAGE_ALPHA_BMP_INTERNAL_H__ */


