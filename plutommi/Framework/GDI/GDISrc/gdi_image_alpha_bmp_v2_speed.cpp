/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_alpha_bmp_v2_core.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Core algorithm for alpha bitmap v2
 *  Compiled in ARM mode to enhance performance.
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

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

extern "C"
{
#include "gdi_image_alpha_bmp_v2_internal.h"
#include "gdi_util.h"
#ifdef GDI_IMAGE_AB2_HAS_GDI
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "gdi_primitive.h"
#endif /* GDI_IMAGE_AB2_HAS_GDI */
#include "kal_trace.h"
#include "gdi_internal.h"
}


/***************************************************************************** 
 * Functions 
 *****************************************************************************/

#ifdef __MTK_TARGET__
#pragma Otime
//#pragma arm section code = "INTERNCODE"
#endif

#define GDI_AB2_A_OF_PARGB8565(c)  (((c) << 8) >> 24)


template <U32 rle_normal_color_bytes>
inline U32 gdi_image_ab2_rle_get_normal_color_template(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return 0;
}


template <>
inline U32 gdi_image_ab2_rle_get_normal_color_template<2>(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return GET_TABLE_16(rle_info->normal_color_pal_ptr, color_idx -1);
}


template <>
inline U32 gdi_image_ab2_rle_get_normal_color_template<3>(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return GET_TABLE_24(rle_info->normal_color_pal_ptr, color_idx -1);
}


template <>
inline U32 gdi_image_ab2_rle_get_normal_color_template<4>(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return GET_TABLE_32(rle_info->normal_color_pal_ptr, color_idx -1);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_get_normal_color
 * DESCRIPTION
 *  Get the color value in normal color table.
 *  color_idx MUST in the normal color table.
 * PARAMETERS
 *  rle_info        [IN]    RLE header data
 *  color_idx       [IN]    color index to query
 * RETURNS
 *  Color value of the color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_normal_color_general(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rle_info->normal_color_bytes)
    {
        case 2:
            return gdi_image_ab2_rle_get_normal_color_template<2>(rle_info, color_idx);

        case 3:
            return gdi_image_ab2_rle_get_normal_color_template<3>(rle_info, color_idx);

        case 4:
            return gdi_image_ab2_rle_get_normal_color_template<4>(rle_info, color_idx);

        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_alpha_blending_general
 * DESCRIPTION
 *  Caculate alpha blending color.
 *  src_color must be pre-multiplied alpha format
 * PARAMETERS
 *  dst_color       [IN] desination color
 *  src_color       [IN] source color
 *  dst_layer_cf           [IN] color format of destination layer
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
template <gdi_color_format dst_layer_cf>
inline U32 gdi_image_ab2_alpha_blending_template(
    U32 dst_color, U32 img_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 a, inv_a;
    U32 result;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_layer_cf)
    {
        case GDI_COLOR_FORMAT_24:
            #define GDI_AB2_PRGB888_OF_PARGB8888(_c) (((_c) << 24) >> 24)
        
            inv_a = GDI_A_OF_ARGB8888(img_color);
            result = GDI_RGB888(
                        GDI_DIV_255(GDI_R_OF_RGB888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_G_OF_RGB888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_B_OF_RGB888(dst_color) * inv_a));
            result += GDI_AB2_PRGB888_OF_PARGB8888(img_color);
            return result;

        case GDI_COLOR_FORMAT_32_PARGB:
            a = GDI_A_OF_PARGB8888(img_color);
            inv_a = 0xff - a;

            result = GDI_PARGB8888(
                        GDI_DIV_255(GDI_A_OF_PARGB8888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_PR_OF_PARGB8888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_PG_OF_PARGB8888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_PB_OF_PARGB8888(dst_color) * inv_a));
            result += img_color;
            return result;

        case GDI_COLOR_FORMAT_32:
            a = GDI_A_OF_ARGB8888(img_color);
            inv_a = 0xff - a;
            
            result = GDI_ARGB8888(
                        GDI_DIV_255(GDI_A_OF_ARGB8888(img_color) * a + GDI_A_OF_ARGB8888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_R_OF_ARGB8888(img_color) * a + GDI_R_OF_ARGB8888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_G_OF_ARGB8888(img_color) * a + GDI_G_OF_ARGB8888(dst_color) * inv_a),
                        GDI_DIV_255(GDI_B_OF_ARGB8888(img_color) * a + GDI_B_OF_ARGB8888(dst_color) * inv_a));
            return result;

        default:
            break;
    }

    return 0;
}


template <>
inline U32 gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_16>(
    U32 dst_color, U32 img_color)
{
    #define GDI_AB2_PRGB565_OF_PARGB8565(_c) (((_c) << 16) >> 16)
    
    U32 inv_a = GDI_AB2_A_OF_PARGB8565(img_color);
    U32 result = GDI_RGB565(
                GDI_DIV_255(GDI_R_OF_RGB565(dst_color) * inv_a),
                GDI_DIV_255(GDI_G_OF_RGB565(dst_color) * inv_a),
                GDI_DIV_255(GDI_B_OF_RGB565(dst_color) * inv_a));
    result += GDI_AB2_PRGB565_OF_PARGB8565(img_color);
    return result;
}


template <>
inline U32 gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_PARGB6666>(
    U32 dst_color, U32 img_color)
{
    U32 a = GDI_A_OF_PARGB6666(img_color);
    U32 inv_a = 0x3f - a;

    U32 result = GDI_PARGB6666(
                GDI_DIV_63(GDI_A_OF_PARGB6666(dst_color) * inv_a),
                GDI_DIV_63(GDI_PR_OF_PARGB6666(dst_color) * inv_a),
                GDI_DIV_63(GDI_PG_OF_PARGB6666(dst_color) * inv_a),
                GDI_DIV_63(GDI_PB_OF_PARGB6666(dst_color) * inv_a));
    result += img_color;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_alpha_blending_general
 * DESCRIPTION
 *  Caculate alpha blending color.
 *  src_color must be pre-multiplied alpha format
 * PARAMETERS
 *  dst_color       [IN] desination color
 *  src_color       [IN] source color
 *  dst_layer_cf           [IN] color format of destination layer
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_alpha_blending_general(
    U32 dst_color, U32 img_color, gdi_color_format dst_layer_cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_layer_cf)
    {
        case GDI_COLOR_FORMAT_16:
            return gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_16>(dst_color, img_color);

        case GDI_COLOR_FORMAT_24:
            return gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_24>(dst_color, img_color);

        case GDI_COLOR_FORMAT_PARGB6666:
            return gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_PARGB6666>(dst_color, img_color);

        case GDI_COLOR_FORMAT_32_PARGB:
            return gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_32_PARGB>(dst_color, img_color);

        case GDI_COLOR_FORMAT_32:
            return gdi_image_ab2_alpha_blending_template<GDI_COLOR_FORMAT_32>(dst_color, img_color);

        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_get_alpha_color
 * DESCRIPTION
 *  Get the color value in alpha color table.
 *  color_idx MUST in the alpha color table.
 * PARAMETERS
 *  rle_info        [IN]    RLE header data
 *  color_idx       [IN]    color index to query
 * RETURNS
 *  Color value of the color index
 *****************************************************************************/
template <U32 rle_alpha_color_bytes>
inline U32 gdi_image_ab2_rle_get_alpha_color_template(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return 0;
}


template <>
inline U32 gdi_image_ab2_rle_get_alpha_color_template<3>(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return GET_TABLE_24(rle_info->alpha_color_pal_ptr,
                    color_idx - rle_info->normal_color_cnt - 1);
}


template <>
inline U32 gdi_image_ab2_rle_get_alpha_color_template<4>(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    return GET_TABLE_32(rle_info->alpha_color_pal_ptr,
                            color_idx - rle_info->normal_color_cnt - 1);
}



/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_get_alpha_color
 * DESCRIPTION
 *  Get the color value in alpha color table.
 *  color_idx MUST in the alpha color table.
 * PARAMETERS
 *  rle_info        [IN]    RLE header data
 *  color_idx       [IN]    color index to query
 * RETURNS
 *  Color value of the color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_alpha_color_general(
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 color_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rle_info->alpha_color_bytes)
    {
        case 3:
            return gdi_image_ab2_rle_get_alpha_color_template<3>(rle_info, color_idx);
            
        case 4:
            return gdi_image_ab2_rle_get_alpha_color_template<4>(rle_info, color_idx);

        default:
            break;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_read
 * DESCRIPTION
 *  Read given bits data from bit-stream. The data must less or equal 16 bits.
 * PARAMETERS
 *  bs              [IN]    bit-stream
 *  bits            [IN]    number of bits to read
 * RETURNS
 *  Read data
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_bs_read_cpp(gdi_image_ab2_bs_struct *bs, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(bs != NULL);
    //GDI_ASSERT(bits <= 16);

    if (bs->buf_bits < bits)
    {
        /* read 16 bits data from memory and fill to buffer */
        bs->buf |= ((*(U16 *)bs->mem_ptr) << bs->buf_bits);
        bs->buf_bits += 16;
        bs->mem_ptr  += sizeof(U16);
    }
    
    data = bs->buf & ~(~0 << bits);
    bs->buf >>= bits;
    bs->buf_bits -= bits;

    return data;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_fetch_color_index
 * DESCRIPTION
 *  Parse and return a RLE color index from current position. 
 *  According the ABMv2 RLE file format.
 *  *** Helper function for internal use.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 * RETURNS
 *  the fected color index
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_ps_fetch_color_index(gdi_image_ab2_rle_ps_struct *ps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_ab2_bs_read_cpp(&ps->bs, ps->color_idx_bits);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_alpha
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, with alpha blending.
 *  color formats of source and destination should be the same.
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  src_ptr         [IN]    the alpha blending source image buffer
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  src_pixel_bytes [IN]    bytes per pixels of src_ptr
 *  n               [IN]    number of pixels to output
 *  dst_layer_cf    [IN]    color format of src layer
 *  
 * RETURNS
 *  void
 *****************************************************************************/
template <U32 pixel_bytes,
          gdi_color_format dst_layer_cf,
          U32 rle_normal_color_bytes,
          U32 rle_alpha_color_bytes>
inline void gdi_image_ab2_rle_ps_draw_alpha_template(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color, src_color, img_color;
    U32 ps_count;
    U32 ps_is_discount;
    U32 rle_normal_color_cnt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ps_count = ps->count;
    ps_is_discount = ps->is_discount;
    rle_normal_color_cnt = rle_info->normal_color_cnt;
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps_count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
            ps_count = ps->count;
            ps_is_discount = ps->is_discount;
        }

        draw_count = GDI_IMAGE_AB2_MIN(ps_count, n);
        ps_count    -= draw_count;
        n           -= draw_count;

        if (ps_is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx > rle_normal_color_cnt)
                {
                    /* alpha color, do alpha blending */
                    /* By profiling, this case is more frequent than others */
                    img_color = gdi_image_ab2_rle_get_alpha_color_template<rle_alpha_color_bytes>(rle_info, color_idx);
                    GET_IMAGE_PIXEL_EX(src_color, dst_ptr, pixel_bytes);
                    out_color = gdi_image_ab2_alpha_blending_template<dst_layer_cf>(src_color, img_color);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, pixel_bytes);
                }
                else if (color_idx == 0)
                {
                    /* transparent color, do nothing */
                }
                else /* color_idx <= rle_normal_color_cnt */
                {
                    /* normal color, just put to destination */
                    out_color = gdi_image_ab2_rle_get_normal_color_template<rle_normal_color_bytes>(rle_info, color_idx);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, pixel_bytes);
                }
                dst_ptr += pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx > rle_normal_color_cnt)
            {
                /* alpha color, do alpha blending */
                img_color = gdi_image_ab2_rle_get_alpha_color_template<rle_alpha_color_bytes>(rle_info, color_idx);
                do
                {
                    GET_IMAGE_PIXEL_EX(src_color, dst_ptr, pixel_bytes);
                    out_color = gdi_image_ab2_alpha_blending_template<dst_layer_cf>(src_color, img_color);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, pixel_bytes);
                    dst_ptr += pixel_bytes;
                } while(--draw_count);
            }
            else if (color_idx == 0)
            {
                dst_ptr += (pixel_bytes * draw_count);
            }
            else /* color_idx <= rle_normal_color_cnt */
            {
                /* normal color, just put to destination */
                out_color = gdi_image_ab2_rle_get_normal_color_template<rle_normal_color_bytes>(rle_info, color_idx);
                do
                {
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, pixel_bytes);
                    dst_ptr += pixel_bytes;
                } while(--draw_count);
            }
        } /* if (ps->is_discount) */
    } /* while (n != 0) */

    ps->count = ps_count;
}


static void gdi_image_ab2_rle_ps_draw_alpha_general(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    const U8 *src_ptr,
    U32 dst_pixel_bytes, 
    U32 src_pixel_bytes, 
    U32 n,
    gdi_color_format dst_layer_cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color, src_color, img_color;
    U32 ps_count;
    U32 ps_is_discount;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ps_count = ps->count;
    ps_is_discount = ps->is_discount;
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps_count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
            ps_count = ps->count;
            ps_is_discount = ps->is_discount;
        }

        draw_count = GDI_IMAGE_AB2_MIN(ps_count, n);
        ps_count    -= draw_count;
        n           -= draw_count;

        if (ps_is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx > rle_info->normal_color_cnt)
                {
                    /* alpha color, do alpha blending */
                    /* By profiling, this case is more frequent than others */
                    img_color = gdi_image_ab2_rle_get_alpha_color_general(rle_info, color_idx);
                    GET_IMAGE_PIXEL_EX(src_color, src_ptr, src_pixel_bytes);
                    out_color = gdi_image_ab2_alpha_blending_general(src_color, img_color, dst_layer_cf);
                }
                else if (color_idx == 0)
                {
                    /* transparent color, copy from source  */
                    GET_IMAGE_PIXEL_EX(out_color, src_ptr, src_pixel_bytes);
                }
                else /* color_idx <= rle_info->normal_color_cnt */
                {
                    /* normal color, just put to destination */
                    out_color = gdi_image_ab2_rle_get_normal_color_general(rle_info, color_idx);
                }
                PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, dst_pixel_bytes);
                dst_ptr += dst_pixel_bytes;
                src_ptr += src_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx > rle_info->normal_color_cnt)
            {
                /* alpha color, do alpha blending */
                img_color = gdi_image_ab2_rle_get_alpha_color_general(rle_info, color_idx);
                do
                {
                    GET_IMAGE_PIXEL_EX(src_color, src_ptr, src_pixel_bytes);
                    out_color = gdi_image_ab2_alpha_blending_general(src_color, img_color, dst_layer_cf);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color,dst_pixel_bytes);
                    dst_ptr += dst_pixel_bytes;
                    src_ptr += src_pixel_bytes;
                } while(--draw_count);
            }
            else if (color_idx == 0)
            {
                /* transparent color, copy from source  */
                do
                {
                    GET_IMAGE_PIXEL_EX(out_color, src_ptr, src_pixel_bytes);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, dst_pixel_bytes);
                    dst_ptr += dst_pixel_bytes;
                    src_ptr += src_pixel_bytes;
                } while(--draw_count);
            }
            else /* color_idx <= rle_info->normal_color_cnt */
            {
                /* normal color, just put to destination */
                out_color = gdi_image_ab2_rle_get_normal_color_general(rle_info, color_idx);
                do
                {
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, dst_pixel_bytes);
                    dst_ptr += dst_pixel_bytes;
                    src_ptr += src_pixel_bytes;
                } while(--draw_count);
            }
        } /* if (ps->is_discount) */
    } /* while (n != 0) */

    ps->count = ps_count;
}



/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_alpha
 * DESCRIPTION
 *  Decode the RLE data stream with alpha.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  src_buf         [IN]    alpha blending source image buffer
 *  rle_info        [IN]    RLE header data
 *  draw_width      [IN]    pixels to draw a line
 *  draw_height     [IN]    lines to draw
 *  begin_ignore    [IN]    pixels to ignore before drawing
 *  line_ignore     [IN]    pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
extern "C"
void gdi_image_ab2_rle_decode_alpha(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_rle_ps_struct ps;
    U8 *dst_ptr, *src_ptr;
    U32 dst_pitch, src_pitch;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(src_buf != NULL);
    GDI_ASSERT(rle_info != NULL);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
    src_ptr = src_buf->ptr;

    dst_pitch = dst_buf->pitch_bytes;
    src_pitch = src_buf->pitch_bytes;
#if defined(GDI_LAYER_PARGB6666_SUPPORT)
    if (src_ptr == dst_ptr &&
        src_buf->pixel_bytes == 3 &&
        dst_buf->cf == GDI_COLOR_FORMAT_PARGB6666 &&
        rle_info->normal_color_bytes == 4 &&
        rle_info->alpha_color_bytes == 4)
    {
        for (i = draw_height; i != 0; i--)
        {
            gdi_image_ab2_rle_ps_draw_alpha_template<3, GDI_COLOR_FORMAT_PARGB6666, 4, 4>(
                &ps,
                rle_info,
                dst_ptr,
                draw_width);
            
            /* Seek to the begin of next line */
            gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
            dst_ptr += dst_pitch;
            src_ptr += src_pitch;
        }
    }
    else
#endif /* GDI_LAYER_PARGB6666_SUPPORT */
#if defined(__COSMOS__MMI_PACKAGE__)
    if (src_ptr == dst_ptr &&
         src_buf->pixel_bytes == 2 &&
         dst_buf->cf == GDI_COLOR_FORMAT_16 &&
         rle_info->normal_color_bytes == 2 &&
         rle_info->alpha_color_bytes == 3)
    {
        for (i = draw_height; i != 0; i--)
        {
            gdi_image_ab2_rle_ps_draw_alpha_template<2, GDI_COLOR_FORMAT_16, 2, 3>(
                &ps,
                rle_info,
                dst_ptr,
                draw_width);
            
            /* Seek to the begin of next line */
            gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
            dst_ptr += dst_pitch;
            src_ptr += src_pitch;
        }
    }
    else
#endif		
    {
        for (i = draw_height; i != 0; i--)
        {
            gdi_image_ab2_rle_ps_draw_alpha_general(
                &ps,
                rle_info,
                dst_ptr,
                src_ptr,
                dst_buf->pixel_bytes,
                src_buf->pixel_bytes,
                draw_width,
                dst_buf->cf);
            
            /* Seek to the begin of next line */
            gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
            dst_ptr += dst_pitch;
            src_ptr += src_pitch;
        }
    }
}

#ifdef __MTK_TARGET__
#pragma Ospace
//#pragma arm section code
#endif


