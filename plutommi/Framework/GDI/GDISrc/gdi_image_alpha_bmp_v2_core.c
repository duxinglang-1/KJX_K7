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

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gdi_image_alpha_bmp_v2_internal.h"
#include "gdi_util.h"
#include "gdi_internal.h"

#ifdef GDI_IMAGE_AB2_HAS_GDI

#include "kal_public_api.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gdi_primitive.h"

#endif /* GDI_IMAGE_AB2_HAS_GDI */


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* read / write data */
#define GET_DATA_16(ptr)                (*((U16*)(ptr)))
#define GET_DATA_24(ptr)                ((((U8 *)(ptr))[0]) + (((U8 *)(ptr))[1] << 8) + (((U8*)(ptr))[2] << 16))
#define GET_DATA_32(ptr)                (*((U32 *)(ptr)))

#define PUT_DATA_16(ptr, p)             (*((U16*)(ptr)) = p)
#define PUT_DATA_24(ptr, p)     \
    do                          \
    {                           \
        U8 *ptr8 = (U8*)(ptr);  \
        ptr8[0] = p;            \
        ptr8[1] = p >> 8;       \
        ptr8[2] = p >> 16;      \
    } while (0)
#define PUT_DATA_32(ptr, p)             (*((U32*)(ptr)) = p)


/* ARGB8888 */
#define R_OF_RGB888(c)                  (((c) <<  8) >> 24)
#define G_OF_RGB888(c)                  (((c) << 16) >> 24)
#define B_OF_RGB888(c)                  (((c) << 24) >> 24)
#define A_OF_ARGB8888(c)                ((c) >> 24)

/* ARGB8565 */
#define R_OF_RGB565(c)                  (((c) << 16) >> 27)
#define G_OF_RGB565(c)                  (((c) << 21) >> 26)
#define B_OF_RGB565(c)                  (((c) << 27) >> 27)
#define A_OF_ARGB8565(c)                (((c) <<  8) >> 24)

/* target dependent */
#if 0 /* to phase out*/
#if MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 24
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 32
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


/***************************************************************************** 
 * Local Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_init
 * DESCRIPTION
 *  Initialize the given bit-stream data structure.
 *  The first data will start at given memory pointer.
 * PARAMETERS
 *  bs              [OUT]   bit-stream structure to be initialized
 *  mem_ptr         [IN]    start memory to be a bit-stream
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_bs_init(
    gdi_image_ab2_bs_struct *bs,
    const U8 *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(bs != NULL);

    if ((U32)mem_ptr & 0x1 != 0)
    {
        /* if mem_ptr is not 2-bytes alignment, read one byte into buffer */
        bs->mem_ptr     = mem_ptr + 1;
        bs->buf         = *(U8 *) mem_ptr;
        bs->buf_bits    = 8;
    }
    else
    {
        bs->mem_ptr     = mem_ptr;
        bs->buf         = 0;
        bs->buf_bits    = 0;
    }
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
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_bs_read(gdi_image_ab2_bs_struct *bs, U32 bits)
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
 *  gdi_image_ab2_bs_ignore
 * DESCRIPTION
 *  Ignore given bits data from bit-stream. The bits must less or equal 16.
 * PARAMETERS
 *  bs              [IN]    bit-stream
 *  bits            [IN]    number of bits to ignore
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_bs_ignore(gdi_image_ab2_bs_struct *bs, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
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
    
    bs->buf >>= bits;
    bs->buf_bits -= bits;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_bs_ignore_large
 * DESCRIPTION
 *  Ignore given bits data from bit-stream, can handle larger than 16 bits.
 * PARAMETERS
 *  bs              [IN]    bit-stream
 *  bits            [IN]    number of bits to ignore
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void gdi_image_ab2_bs_ignore_large(gdi_image_ab2_bs_struct *bs, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(bs != NULL);

    if (bits >= 16)
    {
        bits -= bs->buf_bits;
        bs->buf         = 0;
        bs->buf_bits    = 0;

        bs->mem_ptr += (bits / 16) * sizeof(U16);
        bits %= 16;
    }
    
    gdi_image_ab2_bs_ignore(bs, bits);
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
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_normal_color(
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
            return GET_TABLE_16(rle_info->normal_color_pal_ptr, color_idx -1);

        case 3: 
            return GET_TABLE_24(rle_info->normal_color_pal_ptr, color_idx -1);

        case 4:
            return GET_TABLE_32(rle_info->normal_color_pal_ptr, color_idx -1);

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
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_rle_get_alpha_color(
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
            return GET_TABLE_24(rle_info->alpha_color_pal_ptr,
                            color_idx - rle_info->normal_color_cnt - 1);

        case 4:
            return GET_TABLE_32(rle_info->alpha_color_pal_ptr,
                            color_idx - rle_info->normal_color_cnt - 1);

        //break; //warning
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_init
 * DESCRIPTION
 *  Initialize RLE pixel stream data structure.
 * PARAMETERS
 *  ps              [OUT]   the RLE pixel stream to be initialized
 *  mem_ptr         [IN]    the start memory to be a RLE pixel stream
 *  color_idx_bits  [IN]    the bits per color index
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_ps_init(
    gdi_image_ab2_rle_ps_struct *ps,
    const U8 *mem_ptr,
    U32 color_idx_bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    GDI_ASSERT(ps != NULL);
    GDI_ASSERT(mem_ptr != NULL);

    gdi_image_ab2_bs_init(&ps->bs, mem_ptr);
    
    ps->color_idx_bits      = color_idx_bits;
    
    ps->count               = 0;
    ps->is_discount         = 0;
    ps->repeat_color_idx    = 0;
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
    //GDI_ASSERT(ps != NULL);

    return gdi_image_ab2_bs_read(&ps->bs, ps->color_idx_bits);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_fetch_color_index
 * DESCRIPTION
 *  Parse a new RLE pack encoding.
 *  According the ABMv2 RLE file format.
 *  *** Helper function for internal use.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_ps_fetch_pack(gdi_image_ab2_rle_ps_struct *ps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 pack_head;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(ps != NULL);
    //GDI_ASSERT(ps->count == 0);
    
    pack_head       = gdi_image_ab2_bs_read(&ps->bs, 8);

    ps->count       = (pack_head & 0x7f) + 1;
    ps->is_discount = pack_head & 0x80;
    
    if (!ps->is_discount)
    {
        ps->repeat_color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
    }
}


/*
 * optimization for time
 */
#ifdef __MTK_TARGET__
#pragma Otime
#pragma arm section code = "INTERNCODE"
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_ignore
 * DESCRIPTION
 *  Ignore pixels by given number
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  n               [IN]    number of pixels to be ignored
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_ps_ignore(gdi_image_ab2_rle_ps_struct *ps, U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ps_count;
    U32 ps_is_discount;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ps_count = ps->count;
    ps_is_discount = ps->is_discount;
            
    while (n != 0)
    {
        U32 ignore_count;
        
        if (ps_count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
            ps_count = ps->count;
            ps_is_discount = ps->is_discount;
        }

        ignore_count = GDI_IMAGE_AB2_MIN(ps_count, n);
        ps_count    -= ignore_count;
        n           -= ignore_count;

        if (ps_is_discount)
        {
            gdi_image_ab2_bs_ignore_large(&ps->bs, ps->color_idx_bits * ignore_count);
        }
    } /* while (n > 0) */

    ps->count = ps_count;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_full_opaque
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, WITOUT alpha blending (get normal color only).
 *  Source can not have transparent color index
 *  Normal color bytes of palette and dst must be the same.
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_full_opaque(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 dst_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count  = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                /* normal color, put to destination */
                /* color index will not be 0 */
                    out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, dst_pixel_bytes);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            /* normal color, put to destination */

            /* this is faster only if the color continuous rate is high */
            //draw_count *= dst_pixel_bytes;
            //    PUT_IMG_PIXEL_HS(   dst_ptr, 
            //                        GET_NORMAL_TABLE_COLOR( rle_info->normal_color_pal_ptr, color_idx - 1), 
            //                        draw_count);
            //dst_ptr += draw_count;

            /* original */
            out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
            do 
            {
                PUT_IMAGE_PIXEL_EX(dst_ptr, out_color,dst_pixel_bytes);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);            
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_to_8888
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, direct output to PARGB8888 or ARGB8888.
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_to_8888(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 dst_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count  = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx == 0)
                {
                    out_color = 0;
                }
                else if (color_idx <= rle_info->normal_color_cnt) /*normal color*/
                {
                    out_color = GET_TABLE_32(rle_info->normal_color_pal_ptr, color_idx -1);
                }
                else /*alpha color*/
                {
                    out_color = GET_TABLE_32(rle_info->alpha_color_pal_ptr,
                                             color_idx - rle_info->normal_color_cnt - 1);
                }                
                PUT_DATA_32(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx == 0)
            {
                out_color = 0;
            }
            else if (color_idx <= rle_info->normal_color_cnt) /*normal color*/
            {
                out_color = GET_TABLE_32(rle_info->normal_color_pal_ptr, color_idx -1);
            }
            else /*alpha color*/
            {
                out_color = GET_TABLE_32(rle_info->alpha_color_pal_ptr,
                                         color_idx - rle_info->normal_color_cnt - 1);
            }   

            do 
            {
                PUT_DATA_32(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}



/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_to_6666
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, direct output to PARGB6666.
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_to_6666(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 dst_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count  = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx == 0)
                {
                    out_color = 0;
                }
                else if (color_idx <= rle_info->normal_color_cnt) /*normal color*/
                {
                    out_color = GET_TABLE_32(rle_info->normal_color_pal_ptr, color_idx -1);
                }
                else /*alpha color*/
                {
                    out_color = GET_TABLE_32(rle_info->alpha_color_pal_ptr,
                                             color_idx - rle_info->normal_color_cnt - 1);
                }                
                PUT_DATA_24(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx == 0)
            {
                out_color = 0;
            }
            else if (color_idx <= rle_info->normal_color_cnt) /*normal color*/
            {
                out_color = GET_TABLE_32(rle_info->normal_color_pal_ptr, color_idx -1);
            }
            else /*alpha color*/
            {
                out_color = GET_TABLE_32(rle_info->alpha_color_pal_ptr,
                                         color_idx - rle_info->normal_color_cnt - 1);
            }   

            do 
            {
                PUT_DATA_24(dst_ptr, out_color);
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_ps_draw_na
 * DESCRIPTION
 *  Decode n pixels to dst_ptr, WITOUT alpha blending (source color key mode).
 *  ***This function is the core to be optimized for performance.
 *  Please modify it carefully.
 * PARAMETERS
 *  ps              [IN]    the RLE pixel stream
 *  rle_info        [IN]    the RLE header data
 *  dst_ptr         [OUT]   the target image buffer to output
 *  dst_pixel_bytes [IN]    bytes per pixels of dst_ptr
 *  n               [IN]    number of pixels to output
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_rle_ps_draw_na(
    gdi_image_ab2_rle_ps_struct *ps, 
    const gdi_image_ab2_rle_info_struct *rle_info,
    U8 *dst_ptr,
    U32 dst_pixel_bytes, 
    U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 color_idx;
    U32 out_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n != 0)
    {
        U32 draw_count;
        
        if (ps->count == 0)
        {
            gdi_image_ab2_rle_ps_fetch_pack(ps);
        }

        draw_count  = GDI_IMAGE_AB2_MIN(ps->count, n);
        ps->count   -= draw_count;
        n           -= draw_count;

        if (ps->is_discount)
        {
            /* discontinue pack */
            do
            {
                color_idx = gdi_image_ab2_rle_ps_fetch_color_index(ps);
                if (color_idx == 0)
                {
                    /* transparent color, do nothing */
                }
                else
                {
                    /* normal color, put to destination */
                    out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, dst_pixel_bytes);
                }
                dst_ptr += dst_pixel_bytes;
            } while(--draw_count);
        }
        else
        {
            /* repeat pack */
            color_idx = ps->repeat_color_idx;
            if (color_idx == 0)
            {
                /* transparent color, seek destination pointer to next position to draw */
                dst_ptr += dst_pixel_bytes * draw_count;
            }
            else
            {
                /* normal color, put to destination */
                out_color = gdi_image_ab2_rle_get_normal_color(rle_info, color_idx);
                do 
                {
                    PUT_IMAGE_PIXEL_EX(dst_ptr, out_color, dst_pixel_bytes);
                    dst_ptr += dst_pixel_bytes;
                } while(--draw_count);
            }
        } /* if (ps->is_discount) */
    } /* while (n != 0) */
}


/*
 * optimization for space
 */
#ifdef __MTK_TARGET__
#pragma Ospace
#pragma arm section code
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_full_opaque
 * DESCRIPTION
 *  Decode the RLE data stream to RGB565 or RGB888 WITHOUT alpha.
 *  Source can not have transparent color index.
 *  The normal color bytes of palette and dst need to be the same.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  rle_info        [IN]    the RLE header data
 *  draw_width      [IN]    the pixels to draw a line
 *  draw_height     [IN]    the lines to draw
 *  begin_ignore    [IN]    the pixels to ignore before drawing
 *  line_ignore     [IN]    the pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_decode_full_opaque(
    gdi_image_ab2_img_buf_struct *dst_buf,
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
    U8 *dst_ptr;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(rle_info != NULL);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
        for (i = draw_height; i != 0; i--)
        {
            gdi_image_ab2_rle_ps_draw_full_opaque(
                &ps,
                rle_info,
                dst_ptr,
                dst_buf->pixel_bytes,
                draw_width);

            /* Seek to the begin of next line */
            gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
            dst_ptr += dst_buf->pitch_bytes;
        }        
        
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_direct_output
 * DESCRIPTION
 *  Decode the RLE data stream to a PARGB8888 or ARGB8888 or PARGB6666 buffer
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  rle_info        [IN]    the RLE header data
 *  draw_width      [IN]    the pixels to draw a line
 *  draw_height     [IN]    the lines to draw
 *  begin_ignore    [IN]    the pixels to ignore before drawing
 *  line_ignore     [IN]    the pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_decode_direct_output(
    gdi_image_ab2_img_buf_struct *dst_buf,
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
    U8 *dst_ptr;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(rle_info != NULL);
    GDI_ASSERT(rle_info->normal_color_bytes == 4 && rle_info->alpha_color_bytes == 4);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
    
    if (dst_buf->cf == GDI_COLOR_FORMAT_32 || dst_buf->cf == GDI_COLOR_FORMAT_32_PARGB)
    {
    
    for (i = draw_height; i != 0; i--)
    {
        gdi_image_ab2_rle_ps_draw_to_8888(
            &ps,
            rle_info,
            dst_ptr,
            dst_buf->pixel_bytes,
            draw_width);

        /* Seek to the begin of next line */
        gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
        dst_ptr += dst_buf->pitch_bytes;
    }
}
    else /* dst_buf is GDI_COLOR_FORMAT_PARGB6666 */
    {
        for (i = draw_height; i != 0; i--)
        {
            gdi_image_ab2_rle_ps_draw_to_6666(
                &ps,
                rle_info,
                dst_ptr,
                dst_buf->pixel_bytes,
                draw_width);

            /* Seek to the begin of next line */
            gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
            dst_ptr += dst_buf->pitch_bytes;
        }    
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_na
 * DESCRIPTION
 *  Decode the RLE data stream WITHOUT alpha.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  rle_info        [IN]    the RLE header data
 *  draw_width      [IN]    the pixels to draw a line
 *  draw_height     [IN]    the lines to draw
 *  begin_ignore    [IN]    the pixels to ignore before drawing
 *  line_ignore     [IN]    the pixels to ignore after drawing each line
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_rle_decode_na(
    gdi_image_ab2_img_buf_struct *dst_buf,
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
    U8 *dst_ptr;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(rle_info != NULL);

    /* create a RLE pixel stream */
    gdi_image_ab2_rle_ps_init(&ps, rle_info->bs_ptr, rle_info->color_idx_bits);

    /* Seek to the start position (ignore top clipping) */
    gdi_image_ab2_rle_ps_ignore(&ps, begin_ignore);
    dst_ptr = dst_buf->ptr;
    
    for (i = draw_height; i != 0; i--)
    {
        gdi_image_ab2_rle_ps_draw_na(
            &ps,
            rle_info,
            dst_ptr,
            dst_buf->pixel_bytes,
            draw_width);

        /* Seek to the begin of next line */
        gdi_image_ab2_rle_ps_ignore(&ps, line_ignore);
        dst_ptr += dst_buf->pitch_bytes;
    }
}



/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_PARGB8565_to_PARGB8888
 * DESCRIPTION
 *  Restoure color to PARGB8888 color format
 *  the alpha value will keep in correct value (not reverse)
 * PARAMETERS
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_PARGB8565_to_PARGB8888(U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 a, r, g, b;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: may be optimized
    a = 255 - A_OF_ARGB8565(src_color);

    r = GDI_IMAGE_AB2_BITS_5_to_8(R_OF_RGB565(src_color));
    if (r > a)
    {
        r = a;
    }

    g = GDI_IMAGE_AB2_BITS_6_to_8(G_OF_RGB565(src_color));
    if (g > a)
    {
        g = a;
    }

    b = GDI_IMAGE_AB2_BITS_5_to_8(B_OF_RGB565(src_color));
    if (b > a)
    {
        b = a;
    }

    return (a << 24) | (r << 16) | (g << 8) | b;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_PARGB8565_to_PARGB6666
 * DESCRIPTION
 *  Restoure color to PARGB6666 color format
 *  the alpha value will keep in correct value (not reverse)
 * PARAMETERS
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_PARGB8565_to_PARGB6666(U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 a, r, g, b;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: may be optimized
    a = ((255 - A_OF_ARGB8565(src_color)) >> 2);

    r = GDI_IMAGE_AB2_BITS_5_to_6(R_OF_RGB565(src_color));
    if (r > a)
    {
        r = a;
    }

    g = G_OF_RGB565(src_color);
    if (g > a)
    {
        g = a;
    }

    b = GDI_IMAGE_AB2_BITS_5_to_6(B_OF_RGB565(src_color));
    if (b > a)
    {
        b = a;
    }

    return (a << 18) | (r << 12) | (g << 6) | b;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_PARGB8888_to_PARGB6666
 * DESCRIPTION
 *  Restoure color to PARGB6666 color format
 *  the alpha value will keep in correct value (not reverse)
 * PARAMETERS
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_PARGB8888_to_PARGB6666(U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 a, r, g, b;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: may be optimized
    a = GDI_BITS_8_to_6(255 - A_OF_ARGB8888(src_color));

    r = GDI_BITS_8_to_6(R_OF_RGB888(src_color));
    if (r > a)
    {
        r = a;
    }

    g = GDI_BITS_8_to_6(G_OF_RGB565(src_color));
    if (g > a)
    {
        g = a;
    }

    b = GDI_BITS_8_to_6(B_OF_RGB888(src_color));
    if (b > a)
    {
        b = a;
    }

    return (a << 18) | (r << 12) | (g << 6) | b;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_PARGB8565_to_PARGB8888_inv_alpha
 * DESCRIPTION
 *  Restoure color to PARGB8888 color format
 *  the alpha value will keep in reverse value
 * PARAMETERS
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_PARGB8565_to_PARGB8888_inv_alpha(U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 a, inv_a, r, g, b;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: may be optimized
    inv_a = A_OF_ARGB8565(src_color);
    a = 255 - inv_a;

    r = GDI_IMAGE_AB2_BITS_5_to_8(R_OF_RGB565(src_color));
    if (r > a)
    {
        r = a;
    }

    g = GDI_IMAGE_AB2_BITS_6_to_8(G_OF_RGB565(src_color));
    if (g > a)
    {
        g = a;
    }

    b = GDI_IMAGE_AB2_BITS_5_to_8(B_OF_RGB565(src_color));
    if (b > a)
    {
        b = a;
    }

    return (inv_a << 24) | (r << 16) | (g << 8) | b;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_PARGB8888_to_ARGB8888
 * DESCRIPTION
 *  Restoure color to PARGB8888 color format
 * PARAMETERS
 *  src_color       [IN] source color
 * RETURNS
 *  the result of alpha blending
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 gdi_image_ab2_PARGB8888_to_ARGB8888(U32 src_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 alpha;
    U32 inv;
    U32 out_pixel;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    alpha = src_color >> 24;
    
    if (alpha)
    {
        inv = gdi_alpha_inverse_table[alpha];
    
        /* alpha */
        out_pixel = alpha << 24;
        src_color <<= 8;
    
        // TODO: may need to saturate each channel to 255
        /* red */
        out_pixel |= ((U32)((S16)(src_color >> 24) * inv) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS) << 16;
        src_color <<= 8;    
    
        /* green */
        out_pixel |= ((U32)((S16)(src_color >> 24) * inv) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS) << 8;
        src_color <<= 8;                
    
        /* blue */
        out_pixel |= ((U32)((S16)(src_color >> 24) * inv) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS);
    
    }
    else
    {
        out_pixel = src_color;
    }

    return out_pixel;

}


#define ALIGN_TO_2(p)                   ((U8 *)(((U32)(p) + 1) & ~0x1))
#define ALIGN_TO_4(p)                   ((U8 *)(((U32)(p) + 3) & ~0x3))


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_prepare_palette_from_PARGB8565
 * DESCRIPTION
 *  Converted ab2 palette, prepare ab2 palette from 16bits resgen and convert 
 *  all color in palette to the same color format as destination layer.
 * PARAMETERS
 *  rle_info_ptr                [OUT]   result of header
 *  ori_normal_color_pal_ptr    [IN]    normal color palette ptr from resgen
 *  ori_alpha_color_pal_ptr     [IN]    alpha color palette ptr from resgen
 *  dst_layer_cf                [IN]    destination layer color format
 *  normal_color_cnt            [IN]    normal color count from resgen
 *  alpha_color_cnt             [IN]    alpha color count from resgen
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/
MMI_BOOL gdi_image_ab2_prepare_palette_from_PARGB8565(
    gdi_image_ab2_rle_info_struct *rle_info_ptr,
    const U8  *ori_normal_color_pal_ptr,
    const U8  *ori_alpha_color_pal_ptr,
    U8 dst_layer_cf,
    U32 normal_color_cnt,
    U32 alpha_color_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ext_normal_color_ptr = NULL;
    U8 *ext_alpha_color_ptr = NULL;
    U8 *u8_to_ptr, *u8_from_ptr;
    U16 *u16_from_ptr;
    U32 *u32_to_ptr;
    U32 src_color;
    U32 out_color;
    U32 color_idx;
    U32 ext_buff_size = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dst_layer_cf == GDI_COLOR_FORMAT_16)
    {
        /* no need to convert palette */
        rle_info_ptr->use_ext_palette = 0;
        rle_info_ptr->ext_buffer_ptr = NULL;
        
    }
    else if (dst_layer_cf == GDI_COLOR_FORMAT_24)
    {
        rle_info_ptr->use_ext_palette = 1;
        rle_info_ptr->normal_color_bytes = 3;
        rle_info_ptr->alpha_color_bytes = 4;
        ext_buff_size = normal_color_cnt*rle_info_ptr->normal_color_bytes + alpha_color_cnt*rle_info_ptr->alpha_color_bytes + 4; //+4 for possible align
        rle_info_ptr->ext_buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(ext_buff_size);
        if (rle_info_ptr->ext_buffer_ptr == NULL)
        {
            rle_info_ptr->use_ext_palette = 0;
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_PALETTE_ALLOC_ERR,16,ext_buff_size,dst_layer_cf);
            return MMI_FALSE;
        }
    
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_2(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u8_to_ptr = (U8*)ext_normal_color_ptr;
        u16_from_ptr = (U16*)ori_normal_color_pal_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_16(u16_from_ptr);
            out_color = GDI_RGB888_FROM_RGB565(src_color);
            PUT_DATA_24(u8_to_ptr,out_color);
            u16_from_ptr +=1;
            u8_to_ptr +=3;
        }
    
        /*alpha color*/
        /*alpha color will have its reverse alpha value in palette*/
        ext_alpha_color_ptr = ALIGN_TO_4(u8_to_ptr);
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u32_to_ptr = (U32*)ext_alpha_color_ptr;
        u8_from_ptr = (U8*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            out_color = gdi_image_ab2_PARGB8565_to_PARGB8888_inv_alpha(src_color);
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }            
    }
    else if (dst_layer_cf == GDI_COLOR_FORMAT_32 || dst_layer_cf == GDI_COLOR_FORMAT_32_PARGB)
    {
        rle_info_ptr->use_ext_palette = 1;
        rle_info_ptr->normal_color_bytes = 4;
        rle_info_ptr->alpha_color_bytes = 4;            
        ext_buff_size = normal_color_cnt*rle_info_ptr->normal_color_bytes + alpha_color_cnt*rle_info_ptr->alpha_color_bytes + 4; //+4 for possible align
    
        rle_info_ptr->ext_buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(ext_buff_size);
        if (rle_info_ptr->ext_buffer_ptr == NULL)
        {
            rle_info_ptr->use_ext_palette = 0;
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_PALETTE_ALLOC_ERR,16,ext_buff_size,dst_layer_cf);                
            return MMI_FALSE;
        }
    
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        u16_from_ptr = (U16*)ori_normal_color_pal_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_16(u16_from_ptr);
            /* normal color has its correct(not reverse) alpha value in palette*/
            out_color = (0xff000000 | GDI_RGB888_FROM_RGB565(src_color));
            PUT_DATA_32(u32_to_ptr,out_color);
            u16_from_ptr +=1;
            u32_to_ptr +=1;
        }
    
        /*alpha color: correct (not reverse) alpha value in palette*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u8_from_ptr = (U8*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            out_color = gdi_image_ab2_PARGB8565_to_PARGB8888(src_color);
            if (dst_layer_cf == GDI_COLOR_FORMAT_32)
            {
               out_color = gdi_image_ab2_PARGB8888_to_ARGB8888(out_color);
            }
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }              
    }
    else if (dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        rle_info_ptr->use_ext_palette = 1;
        rle_info_ptr->normal_color_bytes = 4;
        rle_info_ptr->alpha_color_bytes = 4;            
        ext_buff_size = normal_color_cnt*rle_info_ptr->normal_color_bytes + alpha_color_cnt*rle_info_ptr->alpha_color_bytes + 4; //+4 for possible align
    
        rle_info_ptr->ext_buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(ext_buff_size);
        if (rle_info_ptr->ext_buffer_ptr == NULL)
        {
                rle_info_ptr->use_ext_palette = 0;
                GDI_TRACE(TRACE_GROUP_1,GDI_TRC_AB2_PALETTE_ALLOC_ERR,16,ext_buff_size,dst_layer_cf);                
                return MMI_FALSE;
        }
    
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        u16_from_ptr = (U16*)ori_normal_color_pal_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_16(u16_from_ptr);
            /* normal color has its correct(not reverse) alpha value in palette*/
            out_color = GDI_PARGB6666_FROM_RGB565(src_color);
            PUT_DATA_32(u32_to_ptr,out_color);
            u16_from_ptr +=1;
            u32_to_ptr +=1;
        }
    
        /*alpha color: correct (not reverse) alpha value in palette*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u8_from_ptr = (U8*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            out_color = gdi_image_ab2_PARGB8565_to_PARGB6666(src_color);
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }
    }
    else  /* not support dst color format*/
    {
            return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_prepare_palette_from_PARGB8888
 * DESCRIPTION
 *  Converted ab2 palette, prepare ab2 palette from 24bits resgen and convert 
 *  all color in palette to the same color format as destination layer.
 * PARAMETERS
 *  rle_info_ptr                [OUT]   result of header
 *  ori_normal_color_pal_ptr    [IN]    normal color palette ptr from resgen
 *  ori_alpha_color_pal_ptr     [IN]    alpha color palette ptr from resgen
 *  dst_layer_cf                [IN]    destination layer color format
 *  normal_color_cnt            [IN]    normal color count from resgen
 *  alpha_color_cnt             [IN]    alpha color count from resgen
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/
MMI_BOOL gdi_image_ab2_prepare_palette_from_PARGB8888(
    gdi_image_ab2_rle_info_struct *rle_info_ptr,
    const U8  *ori_normal_color_pal_ptr,
    const U8  *ori_alpha_color_pal_ptr,
    U8 dst_layer_cf,
    U32 normal_color_cnt,
    U32 alpha_color_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ext_normal_color_ptr = NULL;
    U8 *ext_alpha_color_ptr = NULL;
    U8 *u8_to_ptr, *u8_from_ptr;
    U16 *u16_to_ptr;
    U32 *u32_to_ptr, *u32_from_ptr;
    U32 src_color;
    U32 out_color;
    U32 color_idx;
    U32 ext_buff_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT((((U32)ori_alpha_color_pal_ptr) & 0x3) == 0);
    
    if (dst_layer_cf == GDI_COLOR_FORMAT_16)
    {
        rle_info_ptr->use_ext_palette = 1;
        rle_info_ptr->normal_color_bytes = 2;
        rle_info_ptr->alpha_color_bytes = 3;
        ext_buff_size = normal_color_cnt*rle_info_ptr->normal_color_bytes + alpha_color_cnt*rle_info_ptr->alpha_color_bytes + 4; //+4 for possible align
        rle_info_ptr->ext_buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(ext_buff_size);
        if (rle_info_ptr->ext_buffer_ptr == NULL)
        {
            rle_info_ptr->use_ext_palette = 0;
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_PALETTE_ALLOC_ERR,24,ext_buff_size,dst_layer_cf);            
            return MMI_FALSE;
        }
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_2(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u16_to_ptr = (U16*)ext_normal_color_ptr;
        u8_from_ptr = (U8*)ori_normal_color_pal_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            out_color = GDI_RGB565_FROM_ARGB8888(src_color);
            PUT_DATA_16(u16_to_ptr,out_color);
            u8_from_ptr +=3;
            u16_to_ptr +=1;
        }

        /*alpha color : reverse alpha value in palette*/
        ext_alpha_color_ptr = ALIGN_TO_2(u16_to_ptr);
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u8_to_ptr = (U8*)ext_alpha_color_ptr;
        u32_from_ptr = (U32*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_32(u32_from_ptr);
            out_color = GDI_RGB565_FROM_ARGB8888(src_color);
            out_color |= ((src_color >> 24) << 16);
            PUT_DATA_24(u8_to_ptr,out_color);
            u32_from_ptr +=1;
            u8_to_ptr +=3;
        }           
    }
    else if (dst_layer_cf == GDI_COLOR_FORMAT_24)
    {
        /* Currently if resouce palette is no necessary to convert color format, use resource palette while decoding */
        rle_info_ptr->use_ext_palette = 0;
        rle_info_ptr->ext_buffer_ptr = NULL;        
    }
    else if (dst_layer_cf == GDI_COLOR_FORMAT_32 || dst_layer_cf == GDI_COLOR_FORMAT_32_PARGB)
    {
        rle_info_ptr->use_ext_palette = 1;
        rle_info_ptr->normal_color_bytes = 4;
        rle_info_ptr->alpha_color_bytes = 4;            
        ext_buff_size = normal_color_cnt*rle_info_ptr->normal_color_bytes + alpha_color_cnt*rle_info_ptr->alpha_color_bytes + 4; //+4 for possible align
    
        rle_info_ptr->ext_buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(ext_buff_size);
        if (rle_info_ptr->ext_buffer_ptr == NULL)
        {
            rle_info_ptr->use_ext_palette = 0;
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_PALETTE_ALLOC_ERR,24,ext_buff_size,dst_layer_cf);            
            return MMI_FALSE;
        }
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        u8_from_ptr = (U8*)ori_normal_color_pal_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            out_color = (0xff000000 | src_color);
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }

        /*alpha color*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u32_from_ptr = (U32*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_32(u32_from_ptr);
            src_color = (255 - A_OF_ARGB8888(src_color)) << 24 | (src_color & 0xffffff);
            if (dst_layer_cf == GDI_COLOR_FORMAT_32)
            {
                out_color = gdi_image_ab2_PARGB8888_to_ARGB8888(src_color); //possible to optimize
                PUT_DATA_32(u32_to_ptr,out_color);
            }
            else /*GDI_COLOR_FORMAT_32_PARGB*/
            {
                PUT_DATA_32(u32_to_ptr,src_color);
            }
            u32_from_ptr +=1;
            u32_to_ptr +=1;
        }
    }
    else if (dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        rle_info_ptr->use_ext_palette = 1;
        rle_info_ptr->normal_color_bytes = 4;
        rle_info_ptr->alpha_color_bytes = 4;            
        ext_buff_size = normal_color_cnt*rle_info_ptr->normal_color_bytes + alpha_color_cnt*rle_info_ptr->alpha_color_bytes + 4; //+4 for possible align
    
        rle_info_ptr->ext_buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(ext_buff_size);
        if (rle_info_ptr->ext_buffer_ptr == NULL)
        {
            rle_info_ptr->use_ext_palette = 0;
            GDI_TRACE(TRACE_GROUP_1,GDI_TRC_AB2_PALETTE_ALLOC_ERR,24,ext_buff_size,dst_layer_cf);                        
            return MMI_FALSE;
        }
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        u8_from_ptr = (U8*)ori_normal_color_pal_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            out_color = GDI_PARGB6666_FROM_RGB888(src_color);
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }

        /*alpha color*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u32_from_ptr = (U32*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_32(u32_from_ptr);
            out_color = gdi_image_ab2_PARGB8888_to_PARGB6666(src_color);
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_from_ptr +=1;
            u32_to_ptr +=1;
        }
    }
    else  /* not support dst color format*/
    {
        return MMI_FALSE;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_TRUE;

}


