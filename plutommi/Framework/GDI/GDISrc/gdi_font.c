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
 *  gdi_font.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI low-level font library
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
 * removed!
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
 * removed!
 *
 * removed!
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

#include "gdi_internal.h"
#include "gd_primitive.h"
#include "Font_engine_interface.h"
#include "fontres.h"
#include "gdi_font.h"

#if defined(GDI_USING_2D_ENGINE_V3)
#include "cache_sw.h"
#endif

#include "kal_general_types.h"
#include "kal_release.h"
#include "MMIDataType.h"

#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_image_alpha_bmp.h"
#include "gdi_2d_engine.h"
#include "gd_include.h"
#include "gdi_primitive.h"

const U32 gdi_tilt_table[61] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2,
    2, 2, 2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 5, 5, 5, 5, 5, 6, 6, 6,
    6, 7, 7, 7, 7, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 10, 10, 10, 10, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13
};

#define MAX_TILT  13

static S32 text_clip_x1;    /* Left edge of text clip rectangle */
static S32 text_clip_y1;    /* Top edge of text clip rectangle  */
static S32 text_clip_x2;    /* Right edge of text clip rectangle   */
static S32 text_clip_y2;    /* Bottom edge of text clip rectangle  */

static gd_put_pixel_func put_pixel;

#define put_pixel_with_clip(x,y,c)                    \
   {                                                  \
      if((x >= text_clip_x1) && (x <= text_clip_x2)   \
      &&(y >= text_clip_y1) && (y <= text_clip_y2))   \
         put_pixel(x,y,c);                            \
   }                                                  \

#ifdef __MMI_VECTOR_FONT_SUPPORT__
static U32 AA_font_4bits_text_color_header[((6+16)*2+16)/4];
static U32 AA_font_4bits_border_color_header[((6+16)*2+16)/4];
#endif

/* W05.50 Skip unnecessary action when the character is out of clip */
#define GDI_CHECK_CHAR_CLIP(x,y,char_width,char_height,NULL_ACTION)                 \
   {                                                                                \
      if((x -1 > text_clip_x2   )    || (x+char_width  +MAX_TILT +1 < text_clip_x1) \
      ||(y -1 > text_clip_y2) || (y+char_height +1 < text_clip_y1))                 \
         NULL_ACTION;                                                               \
   }                                                                                \

#define __GDI_SHOW_CHAR__  gdi_show_char_no_clip
#define __GDI_SET_PIXEL__  put_pixel
#include "gdi_font_show_char.h"
#undef __GDI_SHOW_CHAR__
#undef __GDI_SET_PIXEL__

#define __GDI_SHOW_CHAR__  gdi_show_char_with_clip
#define __GDI_SET_PIXEL__  put_pixel_with_clip
#include "gdi_font_show_char.h"
#undef __GDI_SHOW_CHAR__
#undef __GDI_SET_PIXEL__

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define gdi_font_blend_pixel(src_c, src_cf, dst_p, dst_cf, opacity)                              \
do                                                                                               \
{                                                                                                \
        if (src_cf != GDI_COLOR_FORMAT_32)                                                       \
        {                                                                                        \
            break;                                                                               \
        }                                                                                        \
                                                                                                 \
    if (dst_cf == GDI_COLOR_FORMAT_16)                                                           \
    {                                                                                            \
            U32 a, p, s;                                                                         \
            U32 dp, sp, src;                                                                     \
            U32 alpha;                                                                           \
            U16 r;                                                                               \
            src = src_c;                                                                         \
            a = GDI_A_OF_ARGB8888(src);                                                          \
            if (opacity != 15)                                                                   \
            {                                                                                    \
                a = GDI_DIV_15(a * opacity);                                                     \
             }                                                                                   \
                                                                                                 \
            if (a == 0)                                                                          \
            {                                                                                    \
            }                                                                                    \
            else if (a == 255)                                                                   \
            {                                                                                    \
                r = GDI_RGB565_FROM_ARGB8888(src);                                               \
                *(U16*)dst_p = r;                                                                \
            }                                                                                    \
            else                                                                                 \
            {                                                                                    \
                    s = GDI_RGB565_FROM_ARGB8888(src);                                           \
                    sp = (s | (s << 16)) & 0x7E0F81F;                                            \
                    alpha = (a) >> 3;                                                            \
                    dp = (U32)(*(U16 *)dst_p);                                                   \
                    dp = (dp | (dp << 16)) & 0x7E0F81F;                                          \
                    p = ((sp - dp) * alpha / 32 + dp) & 0x7E0F81F;                               \
                    *(U16*)dst_p = (U16)(p | (p >> 16));                                         \
            }                                                                                    \
        }                                                                                        \
    else if (dst_cf == GDI_COLOR_FORMAT_32_PARGB)                                                \
    {                                                                                            \
        U32 out;                                                                                 \
        U32 a;                                                                                   \
        U32 inv_a;                                                                               \
        U32 final_a;                                                                             \
        U32 src, dst;                                                                            \
        dst = *(U32 *)dst_p;                                                                     \
            src = src_c;                                                                         \
            a = GDI_A_OF_ARGB8888(src);                                                          \
            if (opacity != 15)                                                                   \
            {                                                                                    \
                a = GDI_DIV_15(a * opacity);                                                     \
            }                                                                                    \
                                                                                                 \
            if (a == 0)                                                                          \
            {                                                                                    \
            }                                                                                    \
            else if (a == 255)                                                                   \
            {                                                                                    \
                *(U32*)dst_p = src;                                                              \
            }                                                                                    \
            else                                                                                 \
            {                                                                                    \
                inv_a = 255 - a;                                                                 \
                GDI_DEBUG_ASSERT(a < 256 && inv_a < 256);                                        \
                final_a = GDI_DIV_255(GDI_A_OF_PARGB8888(dst)*inv_a) + a;                        \
                out = final_a << 24;                                                             \
                out |= ((((dst & 0xff00ff) * inv_a + (src & 0xff00ff) * a) >> 8) & 0xff00ff);    \
                out |= ((((dst & 0x00ff00) * inv_a + (src & 0x00ff00) * a) >> 8) & 0x00ff00);    \
                *(U32*)dst_p = out;                                                              \
            }                                                                                    \
        }                                                                                        \
        else if (dst_cf == GDI_COLOR_FORMAT_PARGB6666)                                           \
        {                                                                                        \
            U32 out;                                                                             \
            U32 a;                                                                               \
            U32 inv_a;                                                                           \
            U32 final_a;                                                                         \
            U32 src, dst;                                                                        \
            dst = GDI_MEM_GET_24((U8 *)dst_p);                                                   \
                a = GDI_A_OF_ARGB8888(src_c);                                                    \
                if (opacity != 15)                                                               \
                {                                                                                \
                    a = GDI_DIV_15(a * opacity);                                                 \
                }                                                                                \
                                                                                                 \
                if (a == 0)                                                                      \
                {                                                                                \
                }                                                                                \
                else if (a == 255)                                                               \
                {                                                                                \
                    src = GDI_PARGB6666_FROM_PARGB8888(src_c);                                   \
                    GDI_MEM_PUT_24((U8 *) dst_p, src);                                           \
                }                                                                                \
                else                                                                             \
                {                                                                                \
                    inv_a = 255 - a;                                                             \
                    GDI_DEBUG_ASSERT(a < 256 && inv_a < 256);                                    \
                    src = GDI_PARGB6666_FROM_PARGB8888(src_c);                                   \
                    final_a = GDI_DIV_63(GDI_A_OF_PARGB6666(dst)*inv_a) + a;                     \
                    inv_a = (inv_a >> 2);                                                        \
                    a = (a >> 2);                                                                \
                    out = (final_a >> 2) << 18;                                                  \
                    out |= ((((dst & 0x3F03F) * inv_a + (src & 0x3F03F) * a) >> 6) & 0x3F03F);   \
                    out |= ((((dst & 0xFC0) * inv_a + (src & 0xFC0) * a) >> 6) & 0xFC0);         \
                    GDI_MEM_PUT_24((U8 *)dst_p, out);                                            \
                }                                                                                \
    }                                                                                            \
    else if (dst_cf == GDI_COLOR_FORMAT_32)                                                      \
    {                                                                                            \
        U32 out;                                                                                 \
        U32 a;                                                                                   \
        U32 inv_a;                                                                               \
        U32 final_a;                                                                             \
        U32 src, dst;                                                                            \
        dst = *(U32 *)dst_p;                                                                     \
            src = src_c;                                                                         \
            a = GDI_A_OF_ARGB8888(src);                                                          \
            if (opacity != 15)                                                                   \
            {                                                                                    \
                a = GDI_DIV_15(a * opacity);                                                     \
            }                                                                                    \
                                                                                                 \
            if (a == 0)                                                                          \
            {                                                                                    \
            }                                                                                    \
            else if (a == 255)                                                                   \
            {                                                                                    \
                *(U32*)dst_p = src;                                                              \
            }                                                                                    \
            else                                                                                 \
            {                                                                                    \
                inv_a = GDI_DIV_255(GDI_A_OF_ARGB8888(dst) * (255 - a));                         \
                final_a = inv_a + a;                                                             \
                a = GDI_DIVIDE_ALPHA_255(final_a,a);                                             \
                inv_a = 255 - a;                                                                 \
                GDI_DEBUG_ASSERT(a < 256 && inv_a < 256);                                        \
                out = final_a << 24;                                                             \
                out |= ((((dst & 0xff00ff) * inv_a + (src & 0xff00ff) * a) >> 8) & 0xff00ff);    \
                out |= ((((dst & 0x00ff00) * inv_a + (src & 0x00ff00) * a) >> 8) & 0x00ff00);    \
                *(U32*)dst_p = out;                                                              \
            }                                                                                    \
        }                                                                                        \
    else if (dst_cf == GDI_COLOR_FORMAT_24)                                                      \
    {                                                                                            \
        U32 out = 0x0;                                                                           \
        U32 a;                                                                                   \
        U32 inv_a;                                                                               \
        U32 src, dst;                                                                            \
        U8* p_dst = (U8*)(dst_p);                                                                \
        dst = GDI_MEM_GET_24(p_dst);                                                             \
            src = src_c;                                                                         \
            a = GDI_A_OF_ARGB8888(src);                                                          \
            if (opacity != 15)                                                                   \
            {                                                                                    \
                a = GDI_DIV_15(a * opacity);                                                     \
            }else{}                                                                              \
                                                                                                 \
            if (a == 0)                                                                          \
            {                                                                                    \
            }                                                                                    \
            else if (a == 255)                                                                   \
            {                                                                                    \
                GDI_MEM_PUT_24((U8*)(p_dst), src);                                               \
            }                                                                                    \
            else                                                                                 \
            {                                                                                    \
                inv_a = 255 - a;                                                                 \
                GDI_DEBUG_ASSERT(a < 256 && inv_a < 256);                                        \
                out = (out | ((((dst & 0xff00ff) * inv_a + (src & 0xff00ff) * a) >> 8) & 0xff00ff)); \
                out = (out | ((((dst & 0x00ff00) * inv_a + (src & 0x00ff00) * a) >> 8) & 0x00ff00)); \
                GDI_MEM_PUT_24((U8*)(p_dst), out);                                               \
            }                                                                                    \
        }                                                                                        \
} while (0)
#endif

/* 
 * ABM font engine 
 */
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
#define BR_bit_seek(seek_bits, bits_buf, bits_left, bits_mem_ptr)  \
    do                                                              \
    {                                                               \
        if (bits_left > seek_bits)                                  \
        {                                                           \
            bits_left -= seek_bits;                                 \
            bits_buf >>= seek_bits;                                 \
        }                                                           \
        else                                                        \
        {                                                           \
            U32 sb = seek_bits;                                     \
                                                                    \
            sb -= bits_left;                                        \
            bits_mem_ptr += sb / 16;                                \
            bits_buf = *bits_mem_ptr++;                             \
            sb &= 0xF;                                              \
            /* consume skipped bits */                              \
            bits_buf >>= sb;                                        \
            bits_left = 16 - sb;                                    \
        }                                                           \
    } while (0)
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define min(a,b)        (((a) < (b)) ? (a) : (b))

#define PUT_PIXEL_16(bpp, mem, p)    *((U16*)(mem)) = (U16)p;
#define PUT_PIXEL_dst_bpp(bpp, mem, p)          \
    do                                  \
    {                                   \
        if (bpp == 24){                 \
            /*U8 *mem = (mem);*/       \
            ((U8*)mem)[0] = p;                 \
            ((U8*)mem)[1] = p >> 8;            \
            ((U8*)mem)[2] = p >> 16;           \
        }else if (bpp == 8){            \
            *((U8*)(mem)) = (U8)p;      \
        }else if (bpp == 16){           \
            *((U16*)(mem)) = (U16)p;    \
        }else{                          \
            *((U32*)(mem)) = (U32)p;    \
        }                               \
    } while (0)    
              
#define PUT_PIXEL(bpp, mem, p)  PUT_PIXEL_##bpp##(bpp, mem,p);

#define OUTPUT_BORDER(border_buf, output_border_start, output_border_end, dst_bpp, not_draw_left_border)   \
    do                                                              \
    {                                                               \
        U32 tmp_line_buf2;                                          \
        S32 i;                                                      \
        tmp_line_buf2 = border_buf >> not_draw_left_border;         \
        for (i = output_border_start; i >= output_border_end; i--)  \
        {                                                           \
            if (tmp_line_buf2 & 1){                                 \
                PUT_PIXEL(dst_bpp, out_mem_ptr, border_color);      \
            }                                                       \
            out_mem_ptr += dst_byte_per_pixel;                      \
            tmp_line_buf2 = tmp_line_buf2 >> 1;                     \
        }                                                           \
    }while(0)

#ifdef __MMI_VECTOR_FONT_SUPPORT__
#define DIV_15(x) ((((x) + 8) * 4369) >> 16)    /* (x + 7) / 15 */
#define DIV_255(x) ((((x) + 128) * 257) >> 16)  /* (x + 127) / 255 */
#endif

#if defined(GDI_USING_2D_ENGINE_V2) || defined(GDI_USING_2D_ENGINE_V3)    
/*****************************************************************************
 * FUNCTION
 *  gdi_font_use_2d_acceleration
 * DESCRIPTION
 *  Check whether to use hardware 2D engine to accelerate 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gdi_font_use_2d_acceleration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf && gdi_act_layer->cf <= GDI_COLOR_FORMAT_32_PARGB) ||
        GDI_COLOR_FORMAT_PARGB6666 == gdi_act_layer->cf)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* defined(GDI_USING_2D_ENGINE_V2) || defined(GDI_USING_2D_ENGINE_V3) */

    
/*****************************************************************************
 * FUNCTION
 *  gdi_font_show_border_of_char
 * DESCRIPTION
 *  draw the border of a char with border_color (Optimized software version)
 * PARAMETERS
 *  x                    [IN]   character x
 *  y                    [IN]   character y
 *  border_color         [IN]   border color
 *  font_data            [IN]   font data
 *  font_data_size       [IN]   font data size
 *  char_width           [IN]   character width
 *  char_height          [IN]   character height
 *  font_attr            [IN]   font atrribute
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_font_show_border_of_char(
                S32 x,
                S32 y,
                gdi_color border_color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 16-byte ABM header for font information */
    U32 font_buf;                                   //buffer to store data in font data
    S32 clip_width, clip_height;                    //char width and height after clipping
    U32 abm_start_bit_offset;                       //bit offset of first pixel to draw in font data
    U32 dst_line_jump_bytes, abm_line_jump_bits;    //offset to jump to first pixel to draw in the next line
    U32 bpp, dst_bpp, dst_byte_per_pixel;           //bits per pixel in source, destination
    U8  *out_mem_ptr = 0;                             //points to current output memory
    U8  not_draw_up_border, not_draw_down_border, not_draw_left_border, not_draw_right_border;  //decide to draw the border or not after cliping
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //pre process, the section is a simplify version of gdi_image_abm_pre_process()
    {
        U32     abm_start_pixel_offset;
        U32     img_w, img_h;
        S32     x1, x2, y1, y2;
        U32     line_jump_pixel_num;
        S32     layer_width;
        S32     clip_rect_x1, clip_rect_y1, clip_rect_x2, clip_rect_y2;
        S32     border_clip_rect_x1, border_clip_rect_y1, border_clip_rect_x2, border_clip_rect_y2;
        gdi_handle dst_layer;
        gdi_layer_struct *dst_layer_struct;
        
        img_w = (U32)char_width;
        img_h = (U32)char_height;    
        x1 = x;
        y1 = y;
        x2 = x1 + img_w - 1;
        y2 = y1 + img_h - 1;
        gdi_layer_get_active(&dst_layer);
        dst_layer_struct = (gdi_layer_struct*)dst_layer;
        /* check if the draw rect is out of the clip */
        if ((x1 > dst_layer_struct->clipx2) || (y1 > dst_layer_struct->clipy2) || (x2 < dst_layer_struct->clipx1) || (y2 < dst_layer_struct->clipy1))
        {
            return ;
        }

        /* calculate the overlapped rect */
        clip_rect_y1 = max(y1, dst_layer_struct->clipy1);
        clip_rect_y2 = min(y2, dst_layer_struct->clipy2);
        clip_rect_x1 = max(x1, dst_layer_struct->clipx1);
        clip_rect_x2 = min(x2, dst_layer_struct->clipx2);

        /* calculate the draw rect of border */
        border_clip_rect_y1 = max(y1-1, dst_layer_struct->clipy1);
        border_clip_rect_y2 = min(y2+1, dst_layer_struct->clipy2);
        border_clip_rect_x1 = max(x1-1, dst_layer_struct->clipx1);
        border_clip_rect_x2 = min(x2+1, dst_layer_struct->clipx2);

        //decide to draw border or not
        not_draw_up_border = (clip_rect_y1 == border_clip_rect_y1)? 1:0;
        not_draw_down_border = (clip_rect_y2 == border_clip_rect_y2)? 1:0;
        not_draw_left_border = (clip_rect_x1 == border_clip_rect_x1)? 1:0;
        not_draw_right_border = (clip_rect_x2 == border_clip_rect_x2)? 1:0;
        
        bpp = 1;    
        abm_start_pixel_offset = clip_rect_x1 - x1 + (clip_rect_y1 - y1) * img_w;
        abm_start_bit_offset = abm_start_pixel_offset * bpp;

        layer_width = GDI_LAYER.width;
        clip_width = clip_rect_x2 - clip_rect_x1 + 1;
        clip_height = clip_rect_y2 - clip_rect_y1 + 1;
        line_jump_pixel_num = layer_width - clip_width;

        dst_bpp = gdi_layer_get_bit_per_pixel();
        dst_byte_per_pixel = dst_bpp / 8;
        dst_line_jump_bytes = line_jump_pixel_num * dst_byte_per_pixel;

        // bits to skipped for a line jump of the source ABM 
        abm_line_jump_bits = (img_w - clip_width) * bpp;

        // set memory pointers to the start pixel 
        out_mem_ptr = (U8*)GDI_LAYER.buf_ptr;
        out_mem_ptr += (clip_rect_y1 * layer_width + clip_rect_x1) * dst_byte_per_pixel;
    }
    {
        BIT_INIT(font_data);
        BIT_SEEK(abm_start_bit_offset);

        {
            S32 y = clip_height;
            U32 border_buf0, border_buf1, border_buf2, readpixelnum;
            S32 output_border_start, output_border_end;

            border_buf0 = 0;    //border_buf0,1,2 is bit mask used to store the border
            border_buf1 = 0;
            border_buf2 = 0;
            
            readpixelnum = 16;  // the max number that the Bit reader can read
            
            if ((dst_bpp == 16) && (clip_width < readpixelnum))
            {
                // if dsp_bpp is 16 and clip_width<readpixelnum, we use the faster algorithm
                U32 mask, border_buf_len;
                readpixelnum = clip_width;
                border_buf_len = readpixelnum + 2;
                mask = (1 << readpixelnum) - 1;

                output_border_start = (border_buf_len - 1) - not_draw_left_border;
                output_border_end = not_draw_right_border;
                while (y > 0)                                                                  
                {
                    U32 tmp_line_buf;                       
                    U8 *ori_output_mem;
                    
                    border_buf2 = 0;
                    // read the pixel from bitstream 
                    BIT_READ(readpixelnum, mask, font_buf); 

                    //find the border, store in border_buf0,1,2
                    border_buf0 |= (font_buf);              
                    border_buf1 |= (font_buf);              
                    border_buf2 |= (font_buf);              
                    tmp_line_buf = font_buf << 1;           
                    border_buf0 |= tmp_line_buf;            
                    border_buf2 |= tmp_line_buf;            
                    tmp_line_buf = font_buf << 2;           
                    border_buf0 |= tmp_line_buf;            
                    border_buf1 |= tmp_line_buf;            
                    border_buf2 |= tmp_line_buf;  

                    //out put the border to dest layer
                    ori_output_mem = out_mem_ptr;   /* store current output mem position */ 
                    do
                    {
                        if (y == clip_height && not_draw_up_border) //the first line and not to draw up border
                        {
                            out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;
                            break;
                        }
                        
                        /* move pos to previous pixel of previous line */ 
                        out_mem_ptr = ori_output_mem - ((GDI_LAYER.width + ((not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);
                        /* read border_buf to draw border */
                        OUTPUT_BORDER(border_buf0, output_border_start, output_border_end, 16, not_draw_left_border);
                                                                                     
                        if (y == 1) // if it's the final line
                        {                                                               
                            out_mem_ptr = ori_output_mem - ((not_draw_left_border - 1) * (-1)) * dst_byte_per_pixel; 
                            OUTPUT_BORDER(border_buf1, output_border_start, output_border_end, 16, not_draw_left_border);

                            if (not_draw_down_border)   // not draw the down border
                            {
                                out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;     
                                break;
                            }
                            out_mem_ptr = ori_output_mem + ((GDI_LAYER.width - ((not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);    
                            OUTPUT_BORDER(border_buf2, output_border_start, output_border_end, 16, not_draw_left_border);
                        }                                          
                        out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;               
                    }while(0);
                    
                    BIT_SEEK(abm_line_jump_bits);   // jump to the start pixel in the next line of the ABM image 
                    out_mem_ptr += dst_line_jump_bytes; // jump to the start pixel in the next line of the target layer 
                    y--;
                    
                    tmp_line_buf = border_buf0;     //shift the three border_buf
                    border_buf0 = border_buf1;
                    border_buf1 = border_buf2;
                    border_buf2 = tmp_line_buf;
                }
            }
            else
            {   //dst_bpp != 16 || clip_width > readpixelnum, we use the generic version
                while (y > 0)                                                                  
                {
                    //output a line 
                    for (x = (clip_width - 1); x >= 0; x -= readpixelnum)
                    {   
                        U32 mask, border_buf_len;
                        U32 tmp_line_buf;                       
                        U8 *ori_output_mem;     
                        U8 tmp_not_draw_left_border,tmp_not_draw_right_border;

                        tmp_not_draw_left_border = (x == (clip_width - 1))? not_draw_left_border : 0;
                        tmp_not_draw_right_border = (x <= 16)? not_draw_right_border : 0;
                        
                        border_buf0 = 0;
                        border_buf1 = 0;
                        border_buf2 = 0;
                        // read the pixel from bitstream 
                        readpixelnum = 16;
                        if (readpixelnum > x+1)
                        {
                            readpixelnum = x+1;
                        }
                        border_buf_len = readpixelnum + 2;
                        mask = (1 << readpixelnum) - 1;
                                
                        BIT_READ(readpixelnum, mask, font_buf); 
                                                                
                        border_buf0 |= (font_buf);              
                        border_buf1 |= (font_buf);              
                        border_buf2 |= (font_buf);              
                        tmp_line_buf = font_buf << 1;           
                        border_buf0 |= tmp_line_buf;            
                        border_buf2 |= tmp_line_buf;            
                        tmp_line_buf = font_buf << 2;           
                        border_buf0 |= tmp_line_buf;            
                        border_buf1 |= tmp_line_buf;            
                        border_buf2 |= tmp_line_buf;            

                        output_border_start = (border_buf_len - 1) - tmp_not_draw_left_border;
                        output_border_end = tmp_not_draw_right_border;

                        ori_output_mem = out_mem_ptr;   /* store current output mem position */ 

                        if (!(y == clip_height && not_draw_up_border))
                        {
                            /* move pos to previous pixel of previous line */
                            out_mem_ptr = ori_output_mem - ((GDI_LAYER.width + ((tmp_not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);     
                            /* read border_buf to draw border */    
                            OUTPUT_BORDER(border_buf0, output_border_start, output_border_end, dst_bpp, tmp_not_draw_left_border);
                        }
                        out_mem_ptr = ori_output_mem - ((tmp_not_draw_left_border - 1) * (-1)) * dst_byte_per_pixel; 
                        OUTPUT_BORDER(border_buf1, output_border_start, output_border_end, dst_bpp, tmp_not_draw_left_border);
                         
                        if (!(y == 1 && not_draw_down_border)){
                            out_mem_ptr = ori_output_mem + ((GDI_LAYER.width - ((tmp_not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);    
                            OUTPUT_BORDER(border_buf2, output_border_start, output_border_end, dst_bpp, tmp_not_draw_left_border);
                        }                                         
                        out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;

                    }
                    BIT_SEEK(abm_line_jump_bits);   // jump to the start pixel in the next line of the ABM image 
                    out_mem_ptr += dst_line_jump_bytes; // jump to the start pixel in the next line of the target layer 
                    y--;
                }
            }
        }
        /* close bitstream reader */
        BIT_END();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_draw_font_by_abm
 * DESCRIPTION
 *  Wrapper for drawing a 1-bit bitmap font by the ABM decoder (accelerated)
 * PARAMETERS
 *  x                    [IN]   character x
 *  y                    [IN]   character y
 *  color                [IN]   text color
 *  font_data            [IN]   font data
 *  char_width           [IN]   character width
 *  char_height          [IN]   character height
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_draw_font_by_abm(
                S32 x, 
                S32 y, 
                gdi_color color, 
                U8 *font_data, 
                S32 char_width, 
                S32 char_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 16-byte ABM header for font information */
    U32 abm_font_header[4];
    U16* abm = (U16*)abm_font_header;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abm[0] = (U16)char_width;
    abm[1] = (U16)char_height;

    /* use 24-bit palette if the active layer bpp is 24 or 32 */
    if (gdi_act_layer->bits_per_pixel > 16)
    {
        abm[1] |= 0x8000;
    }    

    /* 1-bit color font: 1 for transparent color, 1 for the character color. */
    abm[2] = 2;

    abm[3] = 0;
    abm[4] = 0;
    abm[5] = 0;

    *((U32*)&abm[6]) = (U32)color;
    
    gdi_image_abm_draw_font(x, y, (U8*)abm, font_data);
}

#if defined(__VENUS_3D_UI_ENGINE__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  gdi_font_draw_vector_font_to_A8
 * DESCRIPTION
 *  draw vector font to A8 color format
 * PARAMETERS
 *  font_data       [IN]   font data
 *  font_width      [IN]   character width
 *  font_height     [IN]   character height
 *  dest_x          [IN]   destination x on destination layer
 *  dest_y          [IN]   destination y on destination layer
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_font_draw_vector_font_to_A8(U8* font_data, U16 font_width, U16 font_height, S32 dest_x, S32 dest_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[2], as, ad1, ad2;
    U16 af;
    U8 *output_ptr = NULL, *src_ptr = NULL;
    U16 *output_ptr2 = NULL;
    S16 i, j, last;
    S32 data_shift;
    S16 rect_x1 = dest_x, rect_x2 = dest_x+font_width-1;
    S16 rect_y1=dest_y, rect_y2=dest_y+font_height-1;
    S16 des_clip_width, des_clip_height;
    S16 src_x1, src_y1, src_x2, src_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* NOTE: This is a tricky way for Venus 3D to improve performance of drawing vector font. 
     *       Venus 3D use A8 (8bit alpha) color format instead of ARGB8888 layer as font drawing cache.
     *       GDI_COLOR_FORMAT_A8 is originally a index color layer with palette.
     *       But here we use it as a A8 (8bit alpha) layer for Venus 3D.
     * TODO: Add A8 layer in GDI.
     */
    
    ASSERT(gdi_act_layer->cf == GDI_COLOR_FORMAT_A8);
    
    GDI_CLIP_TWO_RECT(rect_x1, rect_y1, rect_x2, rect_y2, gdi_act_layer->clipx1, gdi_act_layer->clipy1, gdi_act_layer->clipx2, gdi_act_layer->clipy2, return);
    if (rect_x1<dest_x || rect_y1<dest_y || rect_x2>(dest_x+font_width-1) || rect_y2>(dest_y+font_height-1))
    {
        return GDI_IMAGE_OUT_OF_CLIP_REGION;
    }

    des_clip_width = rect_x2 - rect_x1 + 1; 
    des_clip_height = rect_y2 - rect_y1 + 1; 
                
    j = des_clip_height;
    while (--j >= 0)
    {
        output_ptr = gdi_act_layer->buf_ptr + ((rect_y1 * (S16)gdi_act_layer->width) + rect_x1);
        data_shift = ((rect_y1 - dest_y) * (S16)font_width) + (rect_x1 - dest_x);
        src_ptr = font_data + (data_shift / 2);

        i = des_clip_width;

        // handle the first half point
        if ((data_shift & 0x1) && (i > 0))
        {
            ad1 = *output_ptr;
            as = DIV_15(255 * (src_ptr[0] >> 4));
            *output_ptr = as + ad1 - DIV_255(as * ad1);
            
            src_ptr++;
            output_ptr++;
            i--;
        }

        // operate 2pixels at once
        last = i & 0x1;
        i >>= 1;
        output_ptr2 = (U16*)output_ptr;
        while (--i >= 0)
        {
            data[0] = *src_ptr;
            data[1] = data[0] >> 4;
            data[0] = data[0] & 0xF;

            af = *output_ptr2;
            ad1 = af & 0xFF;
            as = DIV_15(255 * data[0]);
            ad1 = as + ad1 - DIV_255(as * ad1);

            ad2 = af >> 8;
            as = DIV_15(255 * data[1]);
            ad2 = as + ad2 - DIV_255(as * ad2);
            
            *output_ptr2 = (ad2 << 8) | ad1;
            
            src_ptr++;
            output_ptr2++;
        }

        // operate the last odd pixel
        output_ptr = (U8*)output_ptr2;
        if (last)
        {
            ad1 = *output_ptr;
            as = DIV_15(255 * (src_ptr[0] & 0xF));
            *output_ptr = as + ad1 - DIV_255(as * ad1);
            
            src_ptr++;
            output_ptr++;
        }

        rect_y1++;
    }

    return GDI_SUCCEED;
}
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  gdi_font_draw_vector_font_with_alpha_blending
 * DESCRIPTION
 *  Optmize for draw font to active layer with 4 bits alpha value per pix,
 *  Currently ONLY support: blend_src_layer is NULL, or active_layer color format
 *  is ARGB8888 or PARGB8888, or blend_src_layer is equal to active_layer.
 * PARAMETERS
 *  dest_x               [IN]   character x
 *  dest_y               [IN]   character y
 *  color                [IN]   text color
 *  font_data            [IN]   font data
 *  char_width           [IN]   character width
 *  char_height          [IN]   character height
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_font_draw_vector_font_with_alpha_blending(
		S32 dest_x,
		S32 dest_y,
		gdi_color color,
		U8* font_data,
		U16 char_width,
		U16 char_height)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    gdi_handle dst_layer_handle, src_layer_handle;
    gdi_handle orig_src_layer_handle = GDI_NULL_HANDLE;
    gdi_color_format dst_layer_vcf;
    gdi_layer_struct* active_layer;
    S16 rect_x1, rect_x2, rect_y1, rect_y2, des_clip_width, des_clip_height;
    S16 i, j, last;
    S32 data_shift;
    U8 *output_ptr = NULL, *src_ptr = NULL;
    S16 bytes_per_pixel;
    U8 alphadata[4];
    U16 alpha16;
    U32 a, r, g, b, act_color;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (char_width == 0 || char_height ==0)
    {
        /* do nothing */
        return GDI_SUCCEED;
    }

    gdi_layer_get_active(&dst_layer_handle);
    gdi_get_alpha_blending_source_layer(&src_layer_handle);
    
    /* Get destination layer color format */
    dst_layer_vcf = ((gdi_layer_struct*)dst_layer_handle)->vcf;
    if (dst_layer_vcf != GDI_COLOR_FORMAT_16 &&
        dst_layer_vcf != GDI_COLOR_FORMAT_24 &&
        dst_layer_vcf != GDI_COLOR_FORMAT_32 &&
        dst_layer_vcf != GDI_COLOR_FORMAT_32_PARGB &&
        dst_layer_vcf != GDI_COLOR_FORMAT_PARGB6666)
    {
        /* Not supported destination layer format */
        return GDI_FAILED;
    }
   
    gdi_set_alpha_blending_source_layer(dst_layer_handle);    
    orig_src_layer_handle = src_layer_handle;
    src_layer_handle = dst_layer_handle;

    /* return when out of clip*/
    active_layer = (gdi_layer_struct*)dst_layer_handle;
    rect_x1 = dest_x; rect_x2 = dest_x+char_width-1;
    rect_y1 = dest_y; rect_y2 = dest_y+char_height-1;
    GDI_CLIP_TWO_RECT(rect_x1, rect_y1, rect_x2, rect_y2, active_layer->clipx1, active_layer->clipy1, active_layer->clipx2, active_layer->clipy2, return);
    if (rect_x1<dest_x || rect_y1<dest_y || rect_x2>(dest_x+char_width-1) || rect_y2>(dest_y+char_height-1))
    {
        return GDI_IMAGE_OUT_OF_CLIP_REGION;
    }

    des_clip_width = rect_x2 - rect_x1 + 1; 
    des_clip_height = rect_y2 - rect_y1 + 1; 
    bytes_per_pixel = active_layer->bits_per_pixel / 8;
    gdi_act_color_to_rgb(&a, &r, &g, &b, color);
    act_color = GDI_ARGB8888(a, r, g, b);    
        /* GDI_IMAGE_ABM_DECODE_MODE_ALPHA */
        j = des_clip_height;
        while (--j >= 0)
        {
            /* need to depends on dst color format */
            output_ptr = active_layer->buf_ptr + (((rect_y1 * (S16)active_layer->width) + rect_x1)*bytes_per_pixel);
            data_shift = ((rect_y1 - dest_y) * (S16)char_width) + (rect_x1 - dest_x);
            src_ptr = font_data + (data_shift / 2);

            i = des_clip_width;
            // handle the first half alpha
            if ((data_shift & 0x1) && (i > 0))
            {
                alphadata[0] = *(U8*)src_ptr;
                alphadata[0] = alphadata[0] >> 4;
                gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[0]);

                src_ptr++;
                output_ptr+= bytes_per_pixel;
                i--;
            }
            // operate 2 alphas at once
            last = i & 0x1;
            i >>= 1;
            while (i > 0)
            {
                if (i >= 2 && !((U32)src_ptr & 0x1))
                {
                    do
                    {
                        alpha16 = GDI_MEM_GET_16(src_ptr);
                        alphadata[0] = (alpha16 & 0xF);
                        alphadata[1] = ((alpha16 >> 4) & 0xF);
                        alphadata[2] = ((alpha16 >> 8) & 0xF);
                        alphadata[3] = (alpha16 >> 12);
                        gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[0]);
                        output_ptr += bytes_per_pixel;
                        gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[1]);
                        output_ptr += bytes_per_pixel;
                        gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[2]);
                        output_ptr += bytes_per_pixel;
                        gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[3]);
                        output_ptr += bytes_per_pixel;

                        src_ptr += 2;
                        i -= 2;
                    }while(i >= 2);
                }
                else
                {
                    alphadata[0] = *(U8*)src_ptr;
                    alphadata[1] = alphadata[0] >> 4;
                    alphadata[0] = alphadata[0] & 0xF;
                    
                    gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[0]);
                    output_ptr += bytes_per_pixel;
                    gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[1]);

                    src_ptr++;
                    output_ptr+= bytes_per_pixel;
                    i -= 1;
                }
            }

            // operate the last odd pixel
            if (last)
            {
                alphadata[0] = *(U8*)src_ptr;
                alphadata[0] = alphadata[0] & 0xF;
                gdi_font_blend_pixel(act_color, GDI_COLOR_FORMAT_32, output_ptr, dst_layer_vcf, alphadata[0]);

                src_ptr++;
                output_ptr+= bytes_per_pixel;
            }
            rect_y1++;
        }

    /* restore alpha blending source layer */
    gdi_set_alpha_blending_source_layer(orig_src_layer_handle);

    return GDI_SUCCEED;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_show_char
 * DESCRIPTION
 *  Low-level font drawing
 * PARAMETERS
 *  x                   [IN]        X
 *  y                   [IN]        Y
 *  color               [IN]        Font color
 *  font_data           [IN]        Raw font data
 *  font_data_size      [IN]        Font data size in bytes
 *  char_width          [IN]        Character width
 *  char_height         [IN]        Character height
 *  font_attr           [IN]        Font attributes
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_show_char(
            S32 x,
            S32 y,
            gdi_color color,
            U8 *font_data,
            U32 font_data_size,
            U16 char_width,
            U16 char_height,
            U8 font_attr,
            MMI_BOOL is_gray_bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
#if defined(GDI_USING_2D_ENGINE_V3) && defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(GDI_AA_FONT_SUPPORT)
    gdi_handle src_layer_handle;
    gdi_handle act_layer_handle;
#endif
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_handle src_layer_handle2;
    gdi_handle dst_layer_handle2;
    MMI_BOOL force_abm_draw_font = MMI_FALSE;
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip unnecessary action when the character is out of clip */
    GDI_CHECK_CHAR_CLIP(x, y, char_width, char_height, return GDI_SUCCEED);

    font_attr &= ~(FONTATTRIB_UNDERLINE | FONTATTRIB_BOLD);
    /* hardware font engine */
#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration() && 
        !(font_attr & FONTATTRIB_UNDERLINE) && 
        !((char_height > GDI_MAX_TILT_TABLE_SIZE) && (font_attr & FONTATTRIB_ITALIC)))
    {
        /* W06.04 Temp Solution for Italic Font */
        if (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
        {
            gdi_2d_set_tilt_table(gdi_tilt_table, char_height);
        }
        gdi_2d_draw_font(x, y, font_data, 0, char_width, char_height);
        return GDI_SUCCEED;
    }
#elif defined(GDI_USING_2D_ENGINE_V3)
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (gdi_act_layer_info->source_key_enable)
    {
        U32 a, r, g, b;
        U32 ra, rr, rg, rb;
        gdi_act_color_to_rgb(&a, &r, &g, &b, color);
        gdi_act_color_to_rgb(&ra, &rr, &rg, &rb, gdi_act_layer_info->source_key);
        if ((r == rr) &&
            (g == rg) &&
            (b == rb))
        {
            color = color ^ 1;
        }
    }
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    if (gdi_font_use_2d_acceleration() && 
        (!INT_QueryIsCachedRAM((kal_uint32)font_data, font_data_size)) &&
        !(font_attr & FONTATTRIB_UNDERLINE) && 
        (gdi_act_layer->width <= 2047) && (gdi_act_layer->height <= 2047))
    {
        /* Display AA font, if G2D fail, we need return fail to let
         * font engine to try draw again
         */
        if (font_attr & FE_FONT_ATTR_ANTIALIAS)
        {
        #if defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(GDI_AA_FONT_SUPPORT)
            gdi_get_alpha_blending_source_layer(&src_layer_handle);
            gdi_layer_get_active(&act_layer_handle);
			if (src_layer_handle == act_layer_handle)
			{
                src_layer_handle = NULL;
			}
             ret = gdi_2d_draw_AA_font(
                      MMI_FALSE,
                      color,
                      0,
                      src_layer_handle,
                      font_data, 
                      font_data_size,
                      0, 
                      x, 
                      y, 
                      char_width, 
                      char_height);
            if (ret == GDI_SUCCEED)
            {
                return ret;
            }
        #endif
        }
        else if(!((char_height > GDI_MAX_TILT_TABLE_SIZE) && (font_attr & FONTATTRIB_ITALIC)))
        {
            ret = gdi_2d_draw_font_v3(
                MMI_FALSE,  /* Not bordered font */
                color,
                0,
                (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) ? MMI_TRUE : MMI_FALSE,
                (const S32 *) gdi_tilt_table, 
                char_height,
                font_data, 
                font_data_size,
                0, 
                x, 
                y, 
                char_width, 
                char_height);
            if (ret == GDI_SUCCEED)
            {
                return ret;
            }
        }
    }
#endif

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    //if (font_attr & FE_FONT_ATTR_ANTIALIAS)
    {
        if (!is_gray_bitmap)
        {
            gdi_draw_font_by_abm(x, y, color, font_data, char_width, char_height);
        }
    #if defined(__VENUS_3D_UI_ENGINE__)
        else if (gdi_act_layer->cf == GDI_COLOR_FORMAT_A8)
        {
            /* NOTE: This is a tricky way for Venus 3D to improve performance of drawing vector font. 
             *       Venus 3D use A8 (8bit alpha) color format instead of ARGB8888 layer as font drawing cache.
             *       GDI_COLOR_FORMAT_A8 is originally a index color layer with palette.
             *       But here we use it as a A8 (8bit alpha) layer for Venus 3D.
             * TODO: Add A8 layer in GDI.
             */
            ret = gdi_font_draw_vector_font_to_A8(font_data, char_width, char_height, x, y);
            if (ret != GDI_SUCCEED)
            {
                return ret;
            }
        }
    #endif
        else
        {
            gdi_get_alpha_blending_source_layer(&src_layer_handle2);
            gdi_layer_get_active(&dst_layer_handle2);


            
            if ((force_abm_draw_font == MMI_FALSE) && (src_layer_handle2 == GDI_NULL_HANDLE || 
                                          ((gdi_layer_struct*)dst_layer_handle2)->cf == GDI_COLOR_FORMAT_32 ||
                                          ((gdi_layer_struct*)dst_layer_handle2)->cf == GDI_COLOR_FORMAT_32_PARGB ||
                                          ((gdi_layer_struct*)dst_layer_handle2)->cf == GDI_COLOR_FORMAT_PARGB6666 ||
                                           src_layer_handle2 == dst_layer_handle2))
            {
                /* Draw vector font with alpha blending */
                gdi_font_draw_vector_font_with_alpha_blending(
	                    x,
	                    y,
	                    color,
	                    font_data,
	                    char_width,
	                    char_height);
            }
            else
            {
                /* ABM draw font */
                /* Draw vector font with 2 layers */
                U16 *temp;
                gdi_font_prepare_4bits_font_palette(
                    AA_font_4bits_text_color_header,
                    sizeof(AA_font_4bits_text_color_header),
                    color);
                temp = (U16*)(&AA_font_4bits_text_color_header);
                temp[0] = char_width;
                temp[1] = char_height;
                gdi_image_abm_draw_vector_font(
                    x,
                    y,
                    (U8*)AA_font_4bits_text_color_header,
                    font_data);
            }
        }
        return GDI_SUCCEED;
    }
#endif

    if (gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        color = GDI_PARGB8888_FROM_PARGB6666(color);
    }

    /* software font engine */
    if (((font_attr == 0) || (font_attr & FONTATTRIB_NORMAL)) && (gdi_act_layer->bits_per_pixel >= 16))
    {   /* draw normal font by ABM decoder (ABM decoder only supports 16, 24, and 32 bpp.) */
        gdi_draw_font_by_abm(x, y, color, font_data, char_width, char_height);
    }
    else if ((x - 1 < text_clip_x1) || (x + char_width + MAX_TILT + 1 > text_clip_x2) ||
             (y - 1 < text_clip_y1) || (y + char_height + 1 > text_clip_y2))
    {
        gdi_show_char_with_clip(x, y, color, font_data, font_data_size, char_width, char_height, font_attr);
    }
    else
    {
        gdi_show_char_no_clip(x, y, color, font_data, font_data_size, char_width, char_height, font_attr);
    }
    ret = GDI_SUCCEED;  //fix warning 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_show_char_bordered
 * DESCRIPTION
 *  Low-level drawing routine for a borered character
 * PARAMETERS
 *  x                   [IN]        X
 *  y                   [IN]        Y
 *  color               [IN]        Font color   
 *  border_color        [IN]        Font border color
 *  font_data           [IN]        Raw font data
 *  font_data_size      [IN]        Font data size in bytes
 *  char_width          [IN]        Character width
 *  char_height         [IN]        Character height
 *  font_attr           [IN]        Font attributes
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_show_char_bordered(
            S32 x,
            S32 y,
            gdi_color text_color,
            gdi_color border_color,
            U8 *font_data,
            U32 font_data_size,
            U16 char_width,
            U16 char_height,
            U8 font_attr,
            MMI_BOOL is_gray_bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
#if defined(GDI_USING_2D_ENGINE_V3)
    gdi_handle src_layer_handle;
    gdi_handle act_layer_handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip unnecessary action when the character is out of clip */
    GDI_CHECK_CHAR_CLIP(x, y, char_width, char_height,  return GDI_SUCCEED);
    
    /* Ignore underline attribute */
    font_attr &= ~(FONTATTRIB_UNDERLINE | FONTATTRIB_BOLD);
    
    /* hardware font engine */
#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration() && 
        !((char_height > GDI_MAX_TILT_TABLE_SIZE) && (font_attr & FONTATTRIB_ITALIC)))
    {
        gdi_2d_set_font_attr(
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),      /* is_tilt */
            FALSE,
            TRUE,   /* is_border */
            FALSE,  /* don't enable bg_color, */
            text_color,
            border_color);
        /* W06.04 Temp Solution for Italic Font */
        if (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
        {
            gdi_2d_set_tilt_table(gdi_tilt_table, char_height);
        }
        gdi_2d_draw_font(x, y, font_data, 0, char_width, char_height);
        return GDI_SUCCEED;
    }
#elif defined(GDI_USING_2D_ENGINE_V3)

    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (gdi_act_layer_info->source_key_enable)
    {
        U32 a, r, g, b;
        U32 ra, rr, rg, rb;
        gdi_act_color_to_rgb(&ra, &rr, &rg, &rb, gdi_act_layer_info->source_key);
        gdi_act_color_to_rgb(&a, &r, &g, &b, text_color);
        if ((r == rr) &&
            (g == rg) &&
            (b == rb))
        {
            text_color = text_color ^ 1;
        }

        gdi_act_color_to_rgb(&a, &r, &g, &b, border_color);
        if ((r == rr) &&
            (g == rg) &&
            (b == rb))
        {
            border_color = border_color ^ 1;
        }
    }
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    if (gdi_font_use_2d_acceleration() &&
        (!INT_QueryIsCachedRAM((kal_uint32)font_data, font_data_size)) &&
        (gdi_act_layer->width <= 2047) && (gdi_act_layer->height <= 2047))
    {
        /* Display AA font, if G2D fail, we need return fail to let
         * font engine to try draw again
         */
        if (font_attr & FE_FONT_ATTR_ANTIALIAS)
        {
        #if defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(GDI_AA_FONT_SUPPORT)
            gdi_get_alpha_blending_source_layer(&src_layer_handle);
            gdi_layer_get_active(&act_layer_handle);
            if (src_layer_handle == act_layer_handle)
            {
                src_layer_handle = NULL;
            }
            ret = gdi_2d_draw_AA_font(
                      MMI_TRUE,
                      text_color,
                      border_color,
                      src_layer_handle,
                      font_data, 
                      font_data_size,
                      0, 
                      x, 
                      y, 
                      char_width, 
                      char_height);
            if (ret == GDI_SUCCEED)
            {
                return ret;
            }
        #endif            
        }
        else if(!((char_height > GDI_MAX_TILT_TABLE_SIZE) && (font_attr & FONTATTRIB_ITALIC)))
        {
            ret = gdi_2d_draw_font_v3(
                      MMI_TRUE,   /* Bordered font */
                      text_color,
                      border_color,
                      (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) ? MMI_TRUE : MMI_FALSE,
                      (const S32 *) gdi_tilt_table, 
                      char_height,
                      font_data, 
                      font_data_size,
                      0, 
                      x, 
                      y, 
                      char_width, 
                      char_height);
            if (ret == GDI_SUCCEED)
            {
                return ret;
            }
        }
    }
#endif

#ifdef __MMI_VECTOR_FONT_SUPPORT__
//    if (font_attr & FE_FONT_ATTR_ANTIALIAS)
    {
        if (!is_gray_bitmap)
        {
            gdi_draw_font_by_abm(x - 1,y - 1,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x - 1,y + 1,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x + 1,y - 1,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x + 1,y + 1,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x + 0,y - 1,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x + 0,y + 1,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x - 1,y + 0,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x + 1,y + 0,border_color,font_data,char_width,char_height);
            gdi_draw_font_by_abm(x,y,text_color,font_data,char_width,char_height);
        }
        else
        {
            U16 *temp;
            gdi_font_prepare_4bits_font_palette(
                AA_font_4bits_border_color_header,
                sizeof(AA_font_4bits_border_color_header),
                border_color);
            temp = (U16*)(&AA_font_4bits_border_color_header);
            temp[0] = char_width;
            temp[1] = char_height;
            
            gdi_image_abm_draw_vector_font(x - 1,y - 1, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x - 1,y + 1, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x + 1,y - 1, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x + 1,y + 1, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x + 0,y - 1, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x + 0,y + 1, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x - 1,y + 0, (U8*)AA_font_4bits_border_color_header, font_data);
            gdi_image_abm_draw_vector_font(x + 1,y + 0, (U8*)AA_font_4bits_border_color_header, font_data);

            gdi_font_prepare_4bits_font_palette(
                AA_font_4bits_text_color_header,
                sizeof(AA_font_4bits_text_color_header),
                text_color);
            temp = (U16*)(&AA_font_4bits_text_color_header);
            temp[0] = char_width;
            temp[1] = char_height;
            gdi_image_abm_draw_vector_font(x,y, (U8*)AA_font_4bits_text_color_header, font_data);

        } 
        return GDI_SUCCEED;
    }
#endif

    /* Optimized software version for bordered font drawing */
    if (((font_attr == 0) || (font_attr & FONTATTRIB_NORMAL)) && (gdi_act_layer->bits_per_pixel >= 16)
	&&  ( text_clip_x1 <=x && x + char_width <=text_clip_x2 
		&&text_clip_y1 <=y && y + char_height<=text_clip_y2))
    {
        gdi_font_show_border_of_char(x, y, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x, y, text_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
    }
    else /* Original version (slower) */
    {
        gdi_show_char(x - 1, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x - 1, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x + 1, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x + 1, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x + 0, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x + 0, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x - 1, y + 0, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
        gdi_show_char(x + 1, y + 0, border_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);

        gdi_show_char(x, y, text_color, font_data, font_data_size, char_width, char_height, font_attr, MMI_FALSE);
    }
    ret = GDI_SUCCEED;
    return ret; //fix warning
}


/*****************************************************************************
 * FUNCTION
 *  gdi_font_begin
 * DESCRIPTION
 *  Invoke this function before gdi_show_char() and gdi_show_char_bordered
 * PARAMETERS
 *  fg_color        [IN]        Font color
 *  font_attr       [IN]        Font attributes
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_font_begin(S32 x, S32 y, gdi_color fg_color, U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;

#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer((gdi_handle) gdi_act_layer);
        gdi_2d_set_font_attr(
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),  /* is_tilt */
            FALSE,  // TODO: is_bold always be FALSE, it should make some change to pixcomfontengine.c, and turn on this HW feature
            FALSE,  /* is_border */
            FALSE,  /* don't enable bg_color, */
            fg_color,
            0);
    }
#elif defined(GDI_USING_2D_ENGINE_V3)
    (void) fg_color;
    (void) font_attr;
#endif

    put_pixel = gd_put_pixel[gdi_act_layer->cf];

    text_clip_x1 = GDI_LAYER.clipx1;
    text_clip_y1 = GDI_LAYER.clipy1;
    text_clip_x2 = GDI_LAYER.clipx2;
    text_clip_y2 = GDI_LAYER.clipy2;

}


/*****************************************************************************
 * FUNCTION
 *  gdi_font_end
 * DESCRIPTION
 *  Invoke this function after gdi_show_char() and gdi_show_char_bordered
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_font_end(void)
{
#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_end();
    }
#endif /* defined(GDI_USING_2D_ENGINE_V2) */

    GDI_UNLOCK;
}

#ifdef __MMI_VECTOR_FONT_SUPPORT__

// TODO: add support 24bits?

void gdi_font_prepare_4bits_font_palette(void *header, int header_size, gdi_color color)
{
    U16 *abm = (U16 *)header;
    U8  *alpha_ptr;
    U32 a, r, g, b;
    U32 alpha;
    S32 i;

    GDI_DEBUG_ASSERT(header_size >= ((6 + 16) * 2 + 16));
    
    gdi_act_color_to_rgb(&a, &r, &g, &b, color);
    r >>= 3;
    g >>= 2;
    b >>= 3;
    
    abm[2] = 1;     /* normal color numbers, transparent color */
    abm[3] = 15;    /* alpha color numbers */ 
    abm[4] = 0;
    abm[5] = 0;

    /* start from color index 1 (0 is reserved for transparent color */
    alpha_ptr = (U8 *)&abm[6 + 15];
    for (i = 1; i < 16; i++)
    {
        alpha = DIV_255(DIV_15(255 * i) * a);
        abm[6 + i - 1] = 
            DIV_255(r * alpha) << 11 |
            DIV_255(g * alpha) << 5 |
            DIV_255(b * alpha);
        alpha_ptr[i - 1] = 255 - alpha;
    }
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */


