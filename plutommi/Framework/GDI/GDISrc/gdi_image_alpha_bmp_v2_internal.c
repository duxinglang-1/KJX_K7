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
 *  gdi_image_alpha_bmp_v2_internal.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Internal functions for alpha bitmap v2
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
Dear Chhavi, can you help verify if it's ok!! Thx
\\Glbfs14\wcp\sw_releases\Valid_Before_20120701\shooting_C55N_FTE_LQVGA\build3

[YiRuei, 5/9]
Dear Shooting,
Confirmed with Glory, the blue border of image is because VRT draw resized ABM/AB2 with source key onto a RGB565 layer. Please help to check the resize result of ABM/AB2. Michael said resizer/linear transform can support RGB565 source key. Thanks.

[Shengxi, 5/9]
Dear Yiruei,
ABM/AB2 image resize should support SRC Key image resize with src key
Thanks!

[Glory, 5/3]
Dear Shengxi,
Please help check this. It should be the FM radio icon drawing problem. Thx a lot.

[Chhavi 05/03]
Dear Glory,
Please find the attached memory dump, Logs and video.
Thanks,,

[Glory, 5/2]
Dear Chhavi,
Please
1. force assert when this happens and attach memory dump
2. attach a new log with
MOD_MMI_FW group 1
MOD_VRT all
3. attach video
Thx a lot.

[Herman 04/30]
Dear Glory,
Please help to check the blue line. Thank you!!


[Load Path]
\\Mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.17\11B\official\CHAMPAGNE55N_V2_DEMO_GPRS(FTE_LQVGA)

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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gdi_image_alpha_bmp_v2_internal.h"

#ifdef GDI_IMAGE_AB2_HAS_GDI

#include "gdi_internal.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include <string.h>
#include "MMIDataType.h"

#include "gdi_datatype.h"
#include "gdi_primitive.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_util.h"
#include "gd_include.h"

#endif /* GDI_IMAGE_AB2_HAS_GDI */

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif



/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ALIGN_TO_2(p)                   ((U8 *)(((U32)(p) + 1) & ~0x1))
#define ALIGN_TO_4(p)                   ((U8 *)(((U32)(p) + 3) & ~0x3))

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

/* RGB888 */
#define R_OF_RGB888(c)              (((c) <<  8) >> 24)
#define G_OF_RGB888(c)              (((c) << 16) >> 24)
#define B_OF_RGB888(c)              (((c) << 24) >> 24)

/* ARGB8565 */
#define R_OF_RGB565(c)                  (((c) << 16) >> 27)
#define G_OF_RGB565(c)                  (((c) << 21) >> 26)
#define B_OF_RGB565(c)                  (((c) << 27) >> 27)
#define A_OF_ARGB8565(c)                (((c) <<  8) >> 24)

    
/* ARGB8888 */
#define A_OF_ARGB8888(c)            ((c) >> 24)
#define R_OF_ARGB8888(c)            R_OF_RGB888(c)
#define G_OF_ARGB8888(c)            G_OF_RGB888(c)
#define B_OF_ARGB8888(c)            B_OF_RGB888(c)

/* RGB16 */
#define RGB565(r, g, b)             (((r) << 11) | ((g) << 5) | (b))
#define RGB3553(r, g, b)            (((r) << 3) | ((b) << 8) | ((g) >> 3) | (((g) & 0x7) << 13))
    
#define ARGB8888_TO_RGB565(c)       RGB565(R_OF_ARGB8888(c) >> 3, G_OF_ARGB8888(c) >> 2, B_OF_ARGB8888(c) >> 3)

#define ARGB8888_TO_RGB888(c)       ((c) & 0xFFFFFF)


/***************************************************************************** 
 * Local Function 
 *****************************************************************************/
#if defined(__FUE__) || defined(__UBL__)

#define GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS 7

static const S16 gdi_alpha_inverse_table[256] = 
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
 *  convert_PARGB8888_to_ARGB8888
 * DESCRIPTION
 *  Converts a memory block (ROI: Region Of Interest) from PARGB8888 to ARGB8888.
 * PARAMETERS
 *  buf_p           [IN]    memory buffer pointer
 *  buf_width       [IN]    memory buffer width
 *  x               [IN]    x offset of ROI
 *  y               [IN]    y offset of ROI
 *  width           [IN]    ROI width
 *  height          [IN]    ROI height
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_util_convert_PARGB8888_to_ARGB8888_buf(U8 *buf_p, S32 buf_width, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *pixel_p; 
    U32 pixel, out_pixel;
    U32 alpha;
    S32 line_pitch;
    S16 inv;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: assert if buf_p is not 4-byte aligned.
    // GDI_ASSERT(!(buf_p & 3) && (width <= buf_width));
    pixel_p = (U32*)buf_p + y * width + x;
    line_pitch = buf_width - width;

    for (y = height - 1; y >= 0; y--)
    {
        for (x = width - 1; x >= 0; x--)
        {
            pixel = *pixel_p;
            alpha = pixel >> 24;
            
            if (alpha)
            {
                inv = gdi_alpha_inverse_table[alpha];

                /* alpha */
                out_pixel = alpha << 24;
                pixel <<= 8;

                // TODO: may need to saturate each channel to 255
                /* red */
                out_pixel |= ((U32)((S16)(pixel >> 24) * inv) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS) << 16;
                pixel <<= 8;    

                /* green */
                out_pixel |= ((U32)((S16)(pixel >> 24) * inv) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS) << 8;
                pixel <<= 8;                

                /* blue */
                out_pixel |= ((U32)((S16)(pixel >> 24) * inv) >> GDI_UTIL_INV_ALPHA_MUL_255_PRECISION_BITS);

                /* output the converted ARGB8888 pixel */
                *pixel_p = out_pixel;
            }

            pixel_p++;
        }

        pixel_p += line_pitch;
    }
}

#endif /* defined(__FUE__) || defined(__UBL__) */


/*****************************************************************************
 * FUNCTION
 *  need_bits
 * DESCRIPTION
 *  return the needed bits to save max number
 * PARAMETERS
 *  max_number      [IN]    the number to caculate
 * RETURNS
 *  Needed bits
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 need_bits(U32 max_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bits = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (max_number != 0)
    {
        max_number >>= 1;
        bits++;
    }
    
    return bits;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rect_intersect 
 * DESCRIPTION
 *  To caculate rectangle intersect to the two ractangle
 * PARAMETERS
 *  ret_rect        [OUT]   result of rectangle
 *  rhs             [IN]    pointer to the first rectangle to caculate
 *  rect            [IN]    pointer to the second rectangle to caculate
 * RETURNS
 *  GDI_FAILED if no intersection area, or it will return GDI_SUCCESSD.
 *****************************************************************************/
MMI_BOOL gdi_image_ab2_rect_intersect(
    gdi_rect_struct *ret, 
    const gdi_rect_struct *lhs,
    const gdi_rect_struct *rhs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(ret != NULL);
    GDI_ASSERT(lhs != NULL);
    GDI_ASSERT(rhs != NULL);
    
    /* check if there is no intersect */
    if ((lhs->x1 > rhs->x2) || 
        (lhs->y1 > rhs->y2) || 
        (lhs->x2 < rhs->x1) || 
        (lhs->y2 < rhs->y1))
    {
        return MMI_FALSE;
    }

    /* calculate the overlapped rect */
    ret->x1 = GDI_IMAGE_AB2_MAX(lhs->x1, rhs->x1);
    ret->y1 = GDI_IMAGE_AB2_MAX(lhs->y1, rhs->y1);
    ret->x2 = GDI_IMAGE_AB2_MIN(lhs->x2, rhs->x2);
    ret->y2 = GDI_IMAGE_AB2_MIN(lhs->y2, rhs->y2);

    return MMI_TRUE;
}


#ifdef GDI_IMAGE_AB2_HAS_GDI
/*****************************************************************************
 * FUNCTION
 *  gdi_image_dst_to_layer_offset
 * DESCRIPTION
 *  To caculate the give layer position relative with another layer
 * PARAMETERS
 *  to_layer_pos    [OUT]   result position
 *  to_layer        [IN]    layer to caculate to
 *  from_layer      [IN]    layer to caculate from
 *  from_layer_x    [IN]    x value to be caculated from 
 *  from_layer_y    [IN]    y value to be caculated from 
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_dst_to_layer_offset(
    gdi_point2D_struct *to_layer_pos,
    gdi_handle to_layer,
    gdi_handle from_layer,
    S32 from_layer_x,
    S32 from_layer_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_point2D_struct from_layer_offset;
    gdi_point2D_struct to_layer_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(to_layer_pos != NULL);
    GDI_ASSERT(to_layer != GDI_NULL_HANDLE);
    GDI_ASSERT(from_layer != GDI_NULL_HANDLE);
    
    from_layer_offset.x = (S16)((gdi_layer_struct *)from_layer)->offset_x;
    from_layer_offset.y = (S16)((gdi_layer_struct *)from_layer)->offset_y;
    to_layer_offset.x = (S16)((gdi_layer_struct *)to_layer)->offset_x;
    to_layer_offset.y = (S16)((gdi_layer_struct *)to_layer)->offset_y;
    
    /* Result */
    to_layer_pos->x = from_layer_x + from_layer_offset.x - to_layer_offset.x;
    to_layer_pos->y = from_layer_y + from_layer_offset.y - to_layer_offset.y;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_layer_copy
 * DESCRIPTION
 *  Copy a rect between the source and destination layer. 
 *  If the src_layer is GDI_NULL_HANDLE, it will clear the given area.
 * PARAMETERS
 *  dst_rect        [IN]    destination area to update from source layer
 *  src_layer       [IN]    source layer handle
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_layer_copy(
    gdi_handle dst_layer,
    const gdi_rect_struct *dst_rect,
    gdi_handle src_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct dst_layer_clip;
    gdi_rect_struct real_dst_rect;
    gdi_image_ab2_img_buf_struct dst_buf;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_layer != GDI_NULL_HANDLE);
    GDI_ASSERT(dst_rect != NULL);

    if (dst_layer == src_layer)
    {
        /* Do nothing */
        return;
    }

    /* clip area by layer clip, and initialize destination buffer pointer */
    dst_layer_clip.x1   = ((gdi_layer_struct*)dst_layer)->clipx1;
    dst_layer_clip.y1   = ((gdi_layer_struct*)dst_layer)->clipy1;
    dst_layer_clip.x2   = ((gdi_layer_struct*)dst_layer)->clipx2;
    dst_layer_clip.y2   = ((gdi_layer_struct*)dst_layer)->clipy2;
    if (!gdi_image_ab2_rect_intersect(&real_dst_rect, &dst_layer_clip, dst_rect))
    {
        return; /* out of range, do nothing */
    }
    gdi_image_ab2_img_buf_init(&dst_buf, dst_layer, real_dst_rect.x1, real_dst_rect.y1);

    if (src_layer != GDI_NULL_HANDLE)
    {
        gdi_point2D_struct src_offset;
        gdi_image_ab2_img_buf_struct src_buf;
        
        /* find the source position, and initialize source buffer pointer */
        gdi_image_dst_to_layer_offset(
            &src_offset, 
            src_layer, 
            dst_layer,
            real_dst_rect.x1, 
            real_dst_rect.y1);
        gdi_image_ab2_img_buf_init(&src_buf, src_layer, src_offset.x, src_offset.y);

        /* do copy */
        gdi_image_ab2_img_buf_copy(
            &dst_buf, 
            &src_buf,
            (U32)(real_dst_rect.x2 - real_dst_rect.x1 + 1),
            (U32)(real_dst_rect.y2 - real_dst_rect.y1 + 1));
    }
    else /* for direct output decode mode */
    {
        /* do clear */
        gdi_image_ab2_img_buf_clear(
            &dst_buf,
            (U32)(real_dst_rect.x2 - real_dst_rect.x1 + 1),
            (U32)(real_dst_rect.y2 - real_dst_rect.y1 + 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_prepare_boundary
 * DESCRIPTION
 *  Copy the outside area of boundary from the source layer.
 * PARAMETERS
 *  dst_rect        [IN]    desination area needed to copy
 *  boundary_left   [IN]    left size of boundary
 *  boundary_top    [IN]    top size of boundary
 *  boundary_right  [IN]    right size of boundary
 *  boundary_bottom [IN]    bottom size of boundary 
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_ab2_draw_prepare_boundary(
    gdi_handle dst_layer,
    const gdi_rect_struct *dst_rect,
    U32 boundary_left,
    U32 boundary_top,
    U32 boundary_right,
    U32 boundary_bottom,
    gdi_handle src_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct tmp_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_layer != GDI_NULL_HANDLE);
    GDI_ASSERT(dst_rect != NULL);
    
    if (boundary_top > 0)
    {
        tmp_rect.x1 = dst_rect->x1;
        tmp_rect.y1 = dst_rect->y1;
        tmp_rect.x2 = dst_rect->x2;
        tmp_rect.y2 = dst_rect->y1 + boundary_top - 1;
        gdi_image_ab2_layer_copy(dst_layer, &tmp_rect, src_layer);
    }

    if (boundary_bottom > 0)
    {
        tmp_rect.x1 = dst_rect->x1;
        tmp_rect.y1 = dst_rect->y2 - boundary_bottom + 1;
        tmp_rect.x2 = dst_rect->x2;
        tmp_rect.y2 = dst_rect->y2;
        gdi_image_ab2_layer_copy(dst_layer, &tmp_rect, src_layer);
    }
    
    if (boundary_left > 0)
    {
        tmp_rect.x1 = dst_rect->x1;
        tmp_rect.y1 = dst_rect->y1 + boundary_top;
        tmp_rect.x2 = dst_rect->x1 + boundary_left - 1;
        tmp_rect.y2 = dst_rect->y2 - boundary_bottom;
        gdi_image_ab2_layer_copy(dst_layer, &tmp_rect, src_layer);
    }

    if (boundary_right > 0)
    {
        tmp_rect.x1 = dst_rect->x2 - boundary_right + 1;
        tmp_rect.y1 = dst_rect->y1 + boundary_top;
        tmp_rect.x2 = dst_rect->x2;
        tmp_rect.y2 = dst_rect->y2 - boundary_bottom;
        gdi_image_ab2_layer_copy(dst_layer, &tmp_rect, src_layer);
    }
}
#endif /* GDI_IMAGE_AB2_HAS_GDI */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_prepare_to_buf
 * DESCRIPTION
 *  Caculate needed data to draw a ABMv2 image.
 *  It caculate the memory positions of buffers, and the actual image region.
 *  If there is no source layer, the source buffer will pointer to NULL.
 *  The actual image region is accorded by current active layer clipping 
 *  and image boundary.
 *  It will also draw the boundary area if the image not in source color key mode.
 * PARAMETERS
 *  dst_buf         [OUT]   result of the destination buffer
 *  src_buf         [OUT]   result of the (alpha blending) source buffer
 *  img_region      [OUT]   result of the actual image region to draw
 *  offset_x        [IN]    the x offset of the image to draw to active layer
 *  offset_y        [IN]    the y offset of the image to draw to active layer
 *  info            [IN]    ABMv2 header data
 * RETURNS
 *  MMI_FALSE if the image no need to draw, or it will return MMI_TRUE;
 *****************************************************************************/
static MMI_BOOL gdi_image_ab2_draw_prepare_to_buf(
    gdi_image_ab2_img_buf_struct *draw_dst_buf, 
    gdi_image_ab2_img_buf_struct *draw_src_buf, 
    gdi_rect_struct *img_region,
    gdi_image_ab2_img_buf_struct *dst_buf,
    S32 offset_x,
    S32 offset_y, 
    const gdi_image_ab2_info_struct *info,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct dst_rect;
    gdi_point2D_struct dst_pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_UNUSED(decode_mode);
    
    GDI_ASSERT(draw_dst_buf != NULL);
    GDI_ASSERT(img_region != NULL);
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(info != NULL);
    
    /* initialize the destination region */
    dst_rect.x1 = offset_x;
    dst_rect.y1 = offset_y;
    dst_rect.x2 = offset_x + info->width - 1;
    dst_rect.y2 = offset_y + info->height - 1;

    /* caculate the real destination region */
    dst_rect.x1 += info->boundary_left;
    dst_rect.y1 += info->boundary_top;
    dst_rect.x2 -= info->boundary_right;
    dst_rect.y2 -= info->boundary_bottom;

    /* prepare needed information to draw */
    dst_pos.x = dst_rect.x1;
    dst_pos.y = dst_rect.y1;
    draw_dst_buf->ptr = 
        dst_buf->ptr + 
        dst_buf->pitch_bytes * dst_pos.y +
        dst_buf->pixel_bytes * dst_pos.x;
    draw_dst_buf->pixel_bytes = dst_buf->pixel_bytes;
    draw_dst_buf->pitch_bytes = dst_buf->pitch_bytes;

    draw_src_buf->ptr = draw_dst_buf->ptr;
    draw_src_buf->pixel_bytes = draw_dst_buf->pixel_bytes;
    draw_src_buf->pitch_bytes = draw_dst_buf->pitch_bytes;

    img_region->x1 = dst_rect.x1 - dst_rect.x1;
    img_region->y1 = dst_rect.y1 - dst_rect.y1;
    img_region->x2 = dst_rect.x2 - dst_rect.x1;
    img_region->y2 = dst_rect.y2 - dst_rect.y1;

    /*assign the color format of dst buffer*/
    draw_dst_buf->cf = dst_buf->cf;

    return MMI_TRUE;
}


#ifdef GDI_IMAGE_AB2_HAS_GDI
/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_prepare
 * DESCRIPTION
 *  Caculate needed data to draw a ABMv2 image.
 *  It caculate the memory positions of buffers, and the actual image region.
 *  If there is no source layer, the source buffer will pointer to NULL.
 *  The actual image region is accorded by current active layer clipping 
 *  and image boundary.
 *  It will also draw the boundary area if the image not in source color key mode.
 * PARAMETERS
 *  dst_buf         [OUT]   result of the destination buffer
 *  src_buf         [OUT]   result of the (alpha blending) source buffer
 *  img_region      [OUT]   result of the actual image region to draw
 *  offset_x        [IN]    the x offset of the image to draw to active layer
 *  offset_y        [IN]    the y offset of the image to draw to active layer
 *  info            [IN]    ABMv2 header data
 * RETURNS
 *  MMI_FALSE if the image no need to draw, or it will return MMI_TRUE;
 *****************************************************************************/
static MMI_BOOL gdi_image_ab2_draw_prepare(
    gdi_image_ab2_img_buf_struct *dst_buf, 
    gdi_image_ab2_img_buf_struct *src_buf,
    gdi_rect_struct *img_region,
    gdi_handle dst_layer,
    gdi_handle src_layer,
    S32 offset_x, 
    S32 offset_y, 
    const gdi_image_ab2_info_struct *info,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct dst_layer_clip;
    gdi_rect_struct dst_rect;
    gdi_rect_struct clip_dst_rect;
    gdi_point2D_struct dst_pos, src_pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(info != NULL);
    
    /* get layer inforamtions */
    dst_layer_clip.x1   = ((gdi_layer_struct*)dst_layer)->clipx1;
    dst_layer_clip.y1   = ((gdi_layer_struct*)dst_layer)->clipy1;
    dst_layer_clip.x2   = ((gdi_layer_struct*)dst_layer)->clipx2;
    dst_layer_clip.y2   = ((gdi_layer_struct*)dst_layer)->clipy2;
    
    /* initialize the destination region */
    dst_rect.x1 = offset_x;
    dst_rect.y1 = offset_y;
    dst_rect.x2 = offset_x + info->width - 1;
    dst_rect.y2 = offset_y + info->height - 1;

    /* Prepare the boundary area */
    switch (decode_mode)
    {
        case GDI_IMAGE_AB2_DECODE_MODE_OUTPUT:
            /* Clear the boundary */
            gdi_image_ab2_draw_prepare_boundary(
                dst_layer,
                &dst_rect,
                info->boundary_left,
                info->boundary_top,
                info->boundary_right,
                info->boundary_bottom,
                GDI_NULL_HANDLE); /* Null source to clear buffer */
            break;
            
        case GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY:
            /* Do nothing */
            break;
            
        case GDI_IMAGE_AB2_DECODE_MODE_ALPHA:
            /* If it is an alpha blending mode image */
            if (src_layer != GDI_NULL_HANDLE)
            {
                gdi_image_ab2_draw_prepare_boundary(
                    dst_layer,
                    &dst_rect,
                    info->boundary_left,
                    info->boundary_top,
                    info->boundary_right,
                    info->boundary_bottom,
                    src_layer);
            }
            break;

        default:
            GDI_ASSERT(0);
    }

    /* caculate the real destination region */
    dst_rect.x1 += info->boundary_left;
    dst_rect.y1 += info->boundary_top;
    dst_rect.x2 -= info->boundary_right;
    dst_rect.y2 -= info->boundary_bottom;
    if (!gdi_image_ab2_rect_intersect(&clip_dst_rect, &dst_layer_clip, &dst_rect))
    {
        return MMI_FALSE; /* out of range, do nothing */
    }

    /* prepare needed information to draw */
    dst_pos.x = clip_dst_rect.x1;
    dst_pos.y = clip_dst_rect.y1;
    gdi_image_ab2_img_buf_init(dst_buf, dst_layer, dst_pos.x, dst_pos.y);

    if (src_layer != GDI_NULL_HANDLE)
    {
        gdi_image_dst_to_layer_offset(
            &src_pos, 
            src_layer, 
            dst_layer, 
            dst_pos.x, 
            dst_pos.y);
        gdi_image_ab2_img_buf_init(src_buf, src_layer, src_pos.x, src_pos.y);
    }
    else
    {
        /* if there is no alpha blending source layer,
           set the source layer point to NULL */
        gdi_image_ab2_img_buf_null(src_buf);
    }
    
    img_region->x1 = clip_dst_rect.x1 - dst_rect.x1;
    img_region->y1 = clip_dst_rect.y1 - dst_rect.y1;
    img_region->x2 = clip_dst_rect.x2 - dst_rect.x1;
    img_region->y2 = clip_dst_rect.y2 - dst_rect.y1;

    return MMI_TRUE;
}
#endif /* GDI_IMAGE_AB2_HAS_GDI */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_prepare_palette_from_PARGB8565_with_color
 * DESCRIPTION
 *  Converted ab2 palette with color replacement, prepare ab2 palette from 
 *  16bits resgen and convert all color in palette to the same color format 
 *  as destination layer. All color's RGB will be replaced to specified color
 *  in rle_info_ptr.
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
static MMI_BOOL gdi_image_ab2_prepare_palette_from_PARGB8565_with_color(
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
    U32 *u32_to_ptr;
    U32 src_color;
    U32 out_color;
    U32 color_idx;
    U32 ext_buff_size;
    U32 r, g, b, a, inv_a;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (rle_info_ptr == NULL || rle_info_ptr->to_replace_color != 1)
    {
        return MMI_FALSE;
    }

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
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                16, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf);            
            return MMI_FALSE;
        }

        out_color = 0x0000ffff & ((U32)rle_info_ptr->replace_color);
        gd_color_to_rgb_16(&inv_a, &r, &g, &b, out_color); /* inv_a is dummy */
        
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_2(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u16_to_ptr = (U16*)ext_normal_color_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            PUT_DATA_16(u16_to_ptr,out_color);
            u16_to_ptr +=1;
        }

        /*alpha color : reverse alpha value in palette*/
        ext_alpha_color_ptr = ALIGN_TO_2(u16_to_ptr);
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u8_to_ptr = (U8*)ext_alpha_color_ptr;
        u8_from_ptr = (U8*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            inv_a = A_OF_ARGB8565(src_color);
            a = 255 - inv_a;
            out_color = (inv_a << 16) | GDI_RGB565((GDI_IMAGE_AB2_DIV_255(r*a) >> 3),
                                                   (GDI_IMAGE_AB2_DIV_255(g*a) >> 2),
                                                   (GDI_IMAGE_AB2_DIV_255(b*a) >> 3));
            PUT_DATA_24(u8_to_ptr,out_color);
            u8_from_ptr +=3;
            u8_to_ptr +=3;
        }           

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
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                16, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf); 

            return MMI_FALSE;
        }

        out_color = 0x00ffffff & ((U32)rle_info_ptr->replace_color);
        gd_color_to_rgb_24(&inv_a, &r, &g, &b, out_color); /* inv_a is dummy */
    
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_2(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u8_to_ptr = (U8*)ext_normal_color_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            PUT_DATA_24(u8_to_ptr,out_color);
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
            inv_a = A_OF_ARGB8565(src_color);
            a = 255 - inv_a;
            out_color = GDI_ARGB8888(inv_a, 
                                     GDI_IMAGE_AB2_DIV_255(r*a),
                                     GDI_IMAGE_AB2_DIV_255(g*a),
                                     GDI_IMAGE_AB2_DIV_255(b*a));
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
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                16, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf); 

            return MMI_FALSE;
        }

        out_color = (U32)rle_info_ptr->replace_color;
        if (dst_layer_cf == GDI_COLOR_FORMAT_32)
        {    
            gd_color_to_rgb_32(&inv_a, &r, &g, &b, out_color);
            
        }
        else
        {
            gd_color_to_rgb_32PARGB(&inv_a, &r, &g, &b, out_color);
        }
        
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        out_color = (0xFF000000 | out_color);
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            /* normal color has its correct(not reverse) alpha value in palette*/
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_to_ptr +=1;
        }
    
        /*alpha color: correct (not reverse) alpha value in palette*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u8_from_ptr = (U8*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            inv_a = A_OF_ARGB8565(src_color);
            a = 255 - inv_a;
            if (dst_layer_cf == GDI_COLOR_FORMAT_32)
            {
                out_color = GDI_ARGB8888(a, r, g, b);
            }
            else
            { 
                out_color = GDI_ARGB8888(a,
                                         GDI_IMAGE_AB2_DIV_255(r*a),
                                         GDI_IMAGE_AB2_DIV_255(g*a),
                                         GDI_IMAGE_AB2_DIV_255(b*a));
            }
            
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }              
    }
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
#ifdef GDI_LAYER_PARGB6666_SUPPORT    
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
            GDI_TRACE(TRACE_GROUP_1,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                16, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf);
            
            return MMI_FALSE;
        }

        out_color = 0x00ffffff & ((U32)rle_info_ptr->replace_color);
        gd_color_to_rgb_PARGB6666(&inv_a, &r, &g, &b, out_color); /* inv_a is dummy */
        
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        out_color = ((0xfc0000 | out_color) & 0xffffff);
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_to_ptr +=1;
        }
    
        /*alpha color: correct (not reverse) alpha value in palette*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u8_from_ptr = (U8*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_24(u8_from_ptr);
            inv_a = A_OF_ARGB8565(src_color);
            a = 255 - inv_a;
            out_color = GDI_PARGB6666_FROM_ARGB8888_EXT(a, r, g, b);
            PUT_DATA_32(u32_to_ptr,out_color);
            u8_from_ptr +=3;
            u32_to_ptr +=1;
        }


    }
#endif 
#endif    
    else  /* not support dst color format*/
    {
            return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_prepare_palette_from_PARGB8888_with_color
 * DESCRIPTION
 *  Converted ab2 palette with color replacement, prepare ab2 palette from 
 *  16bits resgen and convert all color in palette to the same color format 
 *  as destination layer. All color's RGB will be replaced to specified color
 *  in rle_info_ptr.
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
static MMI_BOOL gdi_image_ab2_prepare_palette_from_PARGB8888_with_color(
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
    U8 *u8_to_ptr;
    U16 *u16_to_ptr;
    U32 *u32_to_ptr, *u32_from_ptr;
    U32 src_color;
    U32 out_color;
    U32 color_idx;
    U32 ext_buff_size;
    U32 inv_a, a, r, g, b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT((((U32)ori_alpha_color_pal_ptr) & 0x3) == 0);

    if (rle_info_ptr == NULL || rle_info_ptr->to_replace_color != 1)
    {
        return MMI_FALSE;
    }
    
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
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                24, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf); 

            return MMI_FALSE;
        }

        out_color = 0x0000ffff & ((U32)rle_info_ptr->replace_color);
        gd_color_to_rgb_16(&inv_a, &r, &g, &b, out_color); /* inv_a is dummy */

        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_2(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u16_to_ptr = (U16*)ext_normal_color_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            PUT_DATA_16(u16_to_ptr,out_color);
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
            inv_a = A_OF_ARGB8888(src_color);
            a = 255 - inv_a;
            out_color = (inv_a << 16) | GDI_RGB565((GDI_IMAGE_AB2_DIV_255(r*a) >> 3),
                                                   (GDI_IMAGE_AB2_DIV_255(g*a) >> 2),
                                                   (GDI_IMAGE_AB2_DIV_255(b*a) >> 3));

            PUT_DATA_24(u8_to_ptr,out_color);
            u32_from_ptr +=1;
            u8_to_ptr +=3;
        }           
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
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                24, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf); 

            return MMI_FALSE;
        }

        out_color = 0x00ffffff & ((U32)rle_info_ptr->replace_color);
        gd_color_to_rgb_24(&inv_a, &r, &g, &b, out_color); /* inv_a is dummy */
    
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_2(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u8_to_ptr = (U8*)ext_normal_color_ptr;
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            PUT_DATA_24(u8_to_ptr,out_color);
            u8_to_ptr +=3;
        }
    
        /*alpha color*/
        /*alpha color will have its reverse alpha value in palette*/
        ext_alpha_color_ptr = ALIGN_TO_4(u8_to_ptr);
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u32_to_ptr = (U32*)ext_alpha_color_ptr;
        u32_from_ptr = (U32*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_32(u32_from_ptr);
            inv_a = A_OF_ARGB8888(src_color);
            a = 255 - inv_a;
            out_color = GDI_ARGB8888(inv_a, 
                                     GDI_IMAGE_AB2_DIV_255(r*a),
                                     GDI_IMAGE_AB2_DIV_255(g*a),
                                     GDI_IMAGE_AB2_DIV_255(b*a));
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_from_ptr +=1;
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
            GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                24, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf); 

            return MMI_FALSE;
        }

        out_color = (U32)rle_info_ptr->replace_color;
        if (dst_layer_cf == GDI_COLOR_FORMAT_32)
        {    
            gd_color_to_rgb_32(&inv_a, &r, &g, &b, out_color);
            
        }
        else
        {
            gd_color_to_rgb_32PARGB(&inv_a, &r, &g, &b, out_color);
        }
        
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        out_color = (0xFF000000 | out_color);
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            /* normal color has its correct(not reverse) alpha value in palette*/        
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_to_ptr +=1;
        }

        /*alpha color*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u32_from_ptr = (U32*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_32(u32_from_ptr);
            inv_a = A_OF_ARGB8888(src_color);
            a = 255 - inv_a;

            if (dst_layer_cf == GDI_COLOR_FORMAT_32)
            {
                out_color = GDI_ARGB8888(a, r, g, b);
            }
            else
            { 
                out_color = GDI_ARGB8888(a,
                                         GDI_IMAGE_AB2_DIV_255(r*a),
                                         GDI_IMAGE_AB2_DIV_255(g*a),
                                         GDI_IMAGE_AB2_DIV_255(b*a));
            }
            
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_from_ptr +=1;
            u32_to_ptr +=1;
        }
    }
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
#ifdef GDI_LAYER_PARGB6666_SUPPORT    
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
            GDI_TRACE(TRACE_GROUP_1,GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,
                24, ((U32)rle_info_ptr->replace_color), ext_buff_size, dst_layer_cf);

            return MMI_FALSE;
        }

        out_color = 0x00ffffff & ((U32)rle_info_ptr->replace_color);
        gd_color_to_rgb_PARGB6666(&inv_a, &r, &g, &b, out_color); /* inv_a is dummy */

        
        /* normal color*/
        ext_normal_color_ptr = ALIGN_TO_4(rle_info_ptr->ext_buffer_ptr);
        rle_info_ptr->normal_color_pal_ptr = ext_normal_color_ptr;
        u32_to_ptr = (U32*)ext_normal_color_ptr;
        out_color = ((0xfc0000 | out_color) & 0xffffff);
        for (color_idx = 0; color_idx < normal_color_cnt; color_idx ++)
        {
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_to_ptr +=1;
        }

        /*alpha color*/
        ext_alpha_color_ptr = (U8*)u32_to_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ext_alpha_color_ptr;
        u32_from_ptr = (U32*)ori_alpha_color_pal_ptr;
        for(color_idx = 0; color_idx < alpha_color_cnt; color_idx ++)
        {
            src_color = GET_DATA_32(u32_from_ptr);
            inv_a = A_OF_ARGB8888(src_color);
            a = 255 - inv_a;
            out_color = GDI_PARGB6666_FROM_ARGB8888_EXT(a, r, g, b);
            PUT_DATA_32(u32_to_ptr,out_color);
            u32_from_ptr +=1;
            u32_to_ptr +=1;
        }

    }
#endif    
#endif    
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

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_prepare_palette_from_ARGB8565
 * DESCRIPTION
 *  Read the ABMv2 RLE header.
 * PARAMETERS
 *  rle_info_ptr    [OUT]   result of header
 *  info_ptr        [IN]    buffer to read
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_prepare_palette_from_ARGB8888
 * DESCRIPTION
 *  Read the ABMv2 RLE header.
 * PARAMETERS
 *  rle_info_ptr    [OUT]   result of header
 *  info_ptr        [IN]    buffer to read
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_read_rle_header
 * DESCRIPTION
 *  Read the ABMv2 RLE header.
 * PARAMETERS
 *  rle_info_ptr    [OUT]   result of header
 *  info_ptr        [IN]    buffer to read
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/
static MMI_BOOL gdi_image_ab2_read_rle_header(
    gdi_image_ab2_rle_info_struct *rle_info_ptr,
    const gdi_image_ab2_info_struct *info_ptr,
    U8 dst_layer_cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL ret = MMI_FALSE;
    const U8 *header_ptr;
    U32 ori_normal_color_bytes;
    U32 ori_alpha_color_bytes;
    U32 normal_color_cnt, alpha_color_cnt;
    U32 color_idx_cnt;
    const U8  *ori_normal_color_pal_ptr;
    const U8  *ori_alpha_color_pal_ptr;
    const U8  *ori_bs_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(rle_info_ptr != NULL);
    GDI_ASSERT(info_ptr != NULL);
    GDI_ASSERT(info_ptr->algorithm_header_ptr != NULL);

    /* check if 2-bytes alignment */
    if (((U32)info_ptr->algorithm_header_ptr & 0x1) != 0)
    {
        ret = MMI_FALSE;
        return ret;
    }

    rle_info_ptr->to_replace_color = info_ptr->to_replace_color;

    if (rle_info_ptr->to_replace_color == 1)
    {
        rle_info_ptr->replace_color = info_ptr->replace_color;
    }
    
    /* prepare data needed */
    header_ptr          = info_ptr->algorithm_header_ptr;

    normal_color_cnt    = *(U16 *)header_ptr;
    alpha_color_cnt     = *(U16 *)(header_ptr + 2);
    /* index 0 is reserved for transparent color, so +1 */
    color_idx_cnt       = 1 + normal_color_cnt + alpha_color_cnt;

    rle_info_ptr->normal_color_cnt  = normal_color_cnt;
    rle_info_ptr->alpha_color_cnt   = alpha_color_cnt;
    rle_info_ptr->color_idx_bits    = need_bits(color_idx_cnt - 1);
    
    ori_normal_color_bytes  = gdi_image_ab2_normal_color_bytes(info_ptr->pixel_format);
    ori_alpha_color_bytes   = gdi_image_ab2_alpha_color_bytes(info_ptr->pixel_format);

    ori_normal_color_pal_ptr = header_ptr + (sizeof(U16) * 2);
    ori_alpha_color_pal_ptr = ALIGN_TO_2( ori_normal_color_pal_ptr +
                                          ori_normal_color_bytes * normal_color_cnt);
    
    if (info_ptr->pixel_format == GDI_IMAGE_AB2_FORMAT_PARGB8888            ||
        info_ptr->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE  ||
        info_ptr->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY)
    {
        ori_alpha_color_pal_ptr = ALIGN_TO_4(ori_alpha_color_pal_ptr);
    }
    
    ori_bs_ptr = ALIGN_TO_2(  ori_alpha_color_pal_ptr +
                              ori_alpha_color_bytes * alpha_color_cnt);    
    
    /**************************************************************/
    /* Prepare converted palette if necessary                     */
    /**************************************************************/    

    /*************** resouce palette: PARGB8565 ***************************/
    if (info_ptr->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY      ||
        info_ptr->pixel_format == GDI_IMAGE_AB2_FORMAT_PARGB8565            ||
        info_ptr->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE)
    {
        if (rle_info_ptr->to_replace_color == 0)
        {
            ret = gdi_image_ab2_prepare_palette_from_PARGB8565(
                rle_info_ptr,
                ori_normal_color_pal_ptr,
                ori_alpha_color_pal_ptr,
                dst_layer_cf,
                normal_color_cnt,
                alpha_color_cnt);        
        }
        else
        {
            ret = gdi_image_ab2_prepare_palette_from_PARGB8565_with_color(
                rle_info_ptr,
                ori_normal_color_pal_ptr,
                ori_alpha_color_pal_ptr,
                dst_layer_cf,
                normal_color_cnt,
                alpha_color_cnt);
        }
    }
    /*************** resouce palette: PARGB8888 ***************************/
    else if (info_ptr->pixel_format ==  GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY     ||
             info_ptr->pixel_format ==  GDI_IMAGE_AB2_FORMAT_PARGB8888           ||
             info_ptr->pixel_format ==  GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE)
    {
        if (rle_info_ptr->to_replace_color == 0)
        {
            ret = gdi_image_ab2_prepare_palette_from_PARGB8888(
                rle_info_ptr,
                ori_normal_color_pal_ptr,
                ori_alpha_color_pal_ptr,
                dst_layer_cf,
                normal_color_cnt,
                alpha_color_cnt);    
        }
        else
        {
            ret = gdi_image_ab2_prepare_palette_from_PARGB8888_with_color(
                rle_info_ptr,
                ori_normal_color_pal_ptr,
                ori_alpha_color_pal_ptr,
                dst_layer_cf,
                normal_color_cnt,
                alpha_color_cnt);    
        }
    }
    else if(0) //TODO: future plan: ARGB8565, ARGB8888
    {
    }
    else /* not support palette color format*/
    {
        return MMI_FALSE;
    }

    /**************************************************************/    


    if (rle_info_ptr->use_ext_palette)
    {
        rle_info_ptr->bs_ptr = ori_bs_ptr;
    }
    else
    {
        rle_info_ptr->ext_buffer_ptr = NULL;    
        rle_info_ptr->normal_color_bytes = ori_normal_color_bytes;
        rle_info_ptr->alpha_color_bytes = ori_alpha_color_bytes;
    
        rle_info_ptr->normal_color_pal_ptr = ori_normal_color_pal_ptr;
        rle_info_ptr->alpha_color_pal_ptr = ori_alpha_color_pal_ptr;
        rle_info_ptr->bs_ptr = ori_bs_ptr;

    }

   return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode
 * DESCRIPTION
 *  Decode ABMv2 RLE format. It will decode the RLE header, and draw the 
 *  image to the destination image buffer.
 *  The des_buf and src_buf must pre-processed with cliiping, and point to the 
 *  start position to draw after clipping. The img_region must be pre-processed 
 *  with cliiping too.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  src_buf         [IN]    alpha blending source image buffer
 *  img_region      [IN]    region of the image actual to draw
 *  info            [IN]    ABMv2 header data
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/
static MMI_BOOL gdi_image_ab2_rle_decode(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    const gdi_rect_struct *img_region,
    const gdi_image_ab2_info_struct *info,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_rle_info_struct rle_info;
    U32 img_width;
    U32 draw_width, draw_height;
    U32 begin_ignore, line_ignore;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(dst_buf->ptr != NULL);
    GDI_ASSERT(src_buf != NULL);
    GDI_ASSERT(img_region != NULL);
    GDI_ASSERT(info != NULL);
    GDI_ASSERT(info->algorithm_header_ptr != NULL);

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("ABP", SA_start);
#endif
    /* Read RLE header */
    if (!gdi_image_ab2_read_rle_header(&rle_info, info, dst_buf->cf))
    {
        return MMI_FALSE;
    }
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("ABP", SA_stop);
#endif

    /* Prepare needed data */
    img_width    = info->width - info->boundary_left - info->boundary_right;
    draw_width   = (U32)(img_region->x2 - img_region->x1 + 1);
    draw_height  = (U32)(img_region->y2 - img_region->y1 + 1);
    begin_ignore = img_width * img_region->y1 + img_region->x1;
    line_ignore  = img_width - draw_width;

    
    /* This is a fully transparent image */
    if (rle_info.alpha_color_cnt == 0 && rle_info.normal_color_cnt == 0)
    {
        if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_OUTPUT)
        {
            gdi_image_ab2_img_buf_clear(dst_buf, draw_width, draw_height);
        }
        else if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_ALPHA)
        {
            /* Copy source buffer directy */
            gdi_image_ab2_img_buf_copy(dst_buf, src_buf, draw_width, draw_height);
        }

        if (rle_info.use_ext_palette && (U8*)rle_info.ext_buffer_ptr != NULL)
        {
           gdi_free_ext_mem((void**)&(rle_info.ext_buffer_ptr));
        }
        
        return MMI_TRUE;
    }

    /* Decode */
    switch (decode_mode)
    {
        case GDI_IMAGE_AB2_DECODE_MODE_OUTPUT:
            gdi_image_ab2_rle_decode_direct_output(
                dst_buf, 
                &rle_info, 
                draw_width, 
                draw_height, 
                begin_ignore, 
                line_ignore);
            break;
            
        case GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY:
            gdi_image_ab2_rle_decode_na(
                dst_buf, 
                &rle_info,
                draw_width,
                draw_height,
                begin_ignore,
                line_ignore);
            break;
            
        case GDI_IMAGE_AB2_DECODE_MODE_ALPHA:
            gdi_image_ab2_rle_decode_alpha(
                dst_buf, 
                src_buf,
                &rle_info,
                draw_width,
                draw_height,
                begin_ignore,
                line_ignore);
            break;

        default:
            GDI_ASSERT(0);
    }


    if (rle_info.use_ext_palette && (U8*)rle_info.ext_buffer_ptr != NULL)
    {
       gdi_free_ext_mem((void**)&(rle_info.ext_buffer_ptr));
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_rle_decode_fully_opaque
 * DESCRIPTION
 *  Decode ABMv2 RLE format. It will decode the RLE header, and draw the 
 *  image to the destination image buffer.
 *  The des_buf and src_buf must pre-processed with cliiping, and point to the 
 *  start position to draw after clipping. The img_region must be pre-processed 
 *  with cliiping too.
 * PARAMETERS
 *  dst_buf         [IN]    destination image buffer (the target to draw)
 *  src_buf         [IN]    alpha blending source image buffer
 *  img_region      [IN]    region of the image actual to draw
 *  info            [IN]    ABMv2 header data
 * RETURNS
 *  MMI_TRUE if decode succeed.
 *****************************************************************************/
static MMI_BOOL gdi_image_ab2_rle_decode_fully_opaque(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    const gdi_rect_struct *img_region,
    const gdi_image_ab2_info_struct *info,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_rle_info_struct rle_info;
    U32 img_width;
    U32 draw_width, draw_height;
    U32 begin_ignore, line_ignore;
    U32 palette_normal_color_bytes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(dst_buf->ptr != NULL);
    GDI_ASSERT(src_buf != NULL);
    GDI_ASSERT(img_region != NULL);
    GDI_ASSERT(info != NULL);
    GDI_ASSERT(info->algorithm_header_ptr != NULL);


    /* Read RLE header */
    if (!gdi_image_ab2_read_rle_header(&rle_info, info, dst_buf->cf))
    {
        return MMI_FALSE;
    }
    /* Prepare needed data */
    img_width    = info->width - info->boundary_left - info->boundary_right;
    draw_width   = (U32)(img_region->x2 - img_region->x1 + 1);
    draw_height  = (U32)(img_region->y2 - img_region->y1 + 1);
    begin_ignore = img_width * img_region->y1 + img_region->x1;
    line_ignore  = img_width - draw_width;

    palette_normal_color_bytes = rle_info.normal_color_bytes;
    
    /* Decode */
    switch (decode_mode)
    {
        case GDI_IMAGE_AB2_DECODE_MODE_OUTPUT:
            if (dst_buf->pixel_bytes == palette_normal_color_bytes &&
                (info->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE ||
                info->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE  ||
                info->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY  ||
                info->pixel_format == GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY ))
            {
                gdi_image_ab2_rle_decode_full_opaque(
                    dst_buf, 
                    &rle_info,
                    draw_width,
                    draw_height,
                    begin_ignore,
                    line_ignore);
            }
            else /* dst color format: GDI_COLOR_FORMAT_32, GDI_COLOR_FORMAT_32_PARGB */
            {
                GDI_ASSERT(0);
            }
            break;
            
        case GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY:
        case GDI_IMAGE_AB2_DECODE_MODE_ALPHA:
            GDI_ASSERT(0);
            break;
        default:
            GDI_ASSERT(0);
    }


    if (rle_info.use_ext_palette && (U8*)rle_info.ext_buffer_ptr != NULL)
    {
       gdi_free_ext_mem((void**)&(rle_info.ext_buffer_ptr));
    }

    return MMI_TRUE;
}


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_img_buf_null
 * DESCRIPTION
 *  Initialize the image buffer data structure to point to null
 * PARAMETERS
 *  img_buf         [OUT]   image buffer to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_img_buf_null(gdi_image_ab2_img_buf_struct *img_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(img_buf != NULL);
    
    img_buf->ptr = NULL;
    img_buf->pixel_bytes = 0;
    img_buf->pitch_bytes = 0;
}  


#ifdef GDI_IMAGE_AB2_HAS_GDI
/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_img_buf_init
 * DESCRIPTION
 *  Initialize the image buffer data structure
 * PARAMETERS
 *  img_buf         [OUT]   image buffer to be initialized
 *  layer_handle    [IN]    the layer to create image buffer
 *  x               [IN]    x offset of the layer
 *  y               [IN]    y offset of the layer
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_img_buf_init(
    gdi_image_ab2_img_buf_struct *img_buf,
    gdi_handle layer_handle,
    S32 x,
    S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(img_buf != NULL);
    GDI_ASSERT(layer_handle != GDI_NULL_HANDLE);
    //GDI_ASSERT(x >= 0);
    //GDI_ASSERT(y >= 0);
    
    layer = (gdi_layer_struct*)layer_handle;
    img_buf->pixel_bytes = layer->bits_per_pixel / 8;
    img_buf->pitch_bytes = layer->width * img_buf->pixel_bytes;
    img_buf->ptr = 
        layer->buf_ptr + 
        img_buf->pitch_bytes * y +
        img_buf->pixel_bytes * x;
    img_buf->cf = layer->cf;
}  
#endif /* GDI_IMAGE_AB2_HAS_GDI */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_img_buf_clear
 * DESCRIPTION
 *  Clear image data to zero with given size
 * PARAMETERS
 *  dst_buf         [OUT]   destination buffer
 *  w               [IN]    width to be copied
 *  h               [IN]    height to be copied
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_img_buf_clear(
    gdi_image_ab2_img_buf_struct *dst_buf,
    U32 w,
    U32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 *dst_ptr;
    U32 dst_pitch;
    S32 line_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);

    dst_ptr     = dst_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;

    line_size = dst_buf->pixel_bytes * w;

    for (i = h; i != 0; i--)
    {
        memset(dst_ptr, 0, line_size);

        dst_ptr += dst_pitch;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_img_buf_copy
 * DESCRIPTION
 *  Copy the image data with given size
 * PARAMETERS
 *  dst_buf         [OUT]   destination buffer
 *  src_buf         [IN]    source buffer
 *  w               [IN]    width to be copied
 *  h               [IN]    height to be copied
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_img_buf_copy(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    U32 w,
    U32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    U8 *dst_ptr, *src_ptr;
    U32 dst_pitch, src_pitch;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(src_buf != NULL);

    dst_ptr     = dst_buf->ptr;
    src_ptr     = src_buf->ptr;
    dst_pitch   = dst_buf->pitch_bytes;
    src_pitch   = src_buf->pitch_bytes;

    if (dst_buf->cf == src_buf->cf)
    {
        S32 line_size = src_buf->pixel_bytes * w;

        for (i = h; i != 0; i--)
        {
            memcpy(dst_ptr, src_ptr, line_size);

            src_ptr += src_pitch;
            dst_ptr += dst_pitch;            
        }
    }
    else if (dst_buf->cf == GDI_COLOR_FORMAT_16 && src_buf->cf == GDI_COLOR_FORMAT_24)
    {
        for (j = h; j != 0; j--)
        {
            U8 *src_pixel_ptr = src_ptr;
            U8 *dst_pixel_ptr = dst_ptr;
            for (i = w; i != 0; i--)
            {   
                U32 p = GET_DATA_24(src_pixel_ptr);
                PUT_DATA_16(dst_pixel_ptr, ARGB8888_TO_RGB565(p));
                dst_pixel_ptr += 2;
                src_pixel_ptr += 3;
            }
            src_ptr += src_pitch;
            dst_ptr += dst_pitch;            
        }
    }
    else if (dst_buf->cf == GDI_COLOR_FORMAT_24 && src_buf->cf == GDI_COLOR_FORMAT_16)
    {
        for (j = h; j != 0; j--)
        {
            U8 *src_pixel_ptr = src_ptr;
            U8 *dst_pixel_ptr = dst_ptr;
            for (i = w; i != 0; i--)
            {   
                U32 p = GET_DATA_16(src_pixel_ptr);
                PUT_DATA_24(dst_pixel_ptr, GDI_RGB888_FROM_RGB565(p));
                dst_pixel_ptr += 3;
                src_pixel_ptr += 2;
            }
            src_ptr += src_pitch;
            dst_ptr += dst_pitch;            
        }
    }
    // TODO: to phase out
    else if (dst_buf->cf == GDI_COLOR_FORMAT_24 && src_buf->pixel_bytes == 4)
    {
        for (j = h; j != 0; j--)
        {
            U8 *src_pixel_ptr = src_ptr;
            U8 *dst_pixel_ptr = dst_ptr;
            for (i = w; i != 0; i--)
            {   
                U32 p = GET_DATA_32(src_pixel_ptr); /* 4 bytes alignment!? */
                if (A_OF_ARGB8888(p))
                {
                    PUT_DATA_24(dst_pixel_ptr, ARGB8888_TO_RGB888(p));
                }                    
                dst_pixel_ptr += 3;
                src_pixel_ptr += 4;
            }
            src_ptr += src_pitch;
            dst_ptr += dst_pitch;            
        }
    }
    else
    {            
        /* Currently we only support same color format */
        /* Do nothing */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_is_src_color_key_mode
 * DESCRIPTION
 *  Querry if the pixel format is a source key mode format.
 * PARAMETERS
 *  pixel_format    [IN]    pixel format to query
 * RETURNS
 *  MMI_TURE if it is a source key mode formay, otherwise MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gdi_image_ab2_is_src_color_key_mode(const gdi_image_ab2_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(info != NULL);

    switch (info->pixel_format)
    {
        case GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY:
        case GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY:
        case GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE:
        case GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE:        
            return MMI_TRUE;
            
        case GDI_IMAGE_AB2_FORMAT_PARGB8888:
        case GDI_IMAGE_AB2_FORMAT_PARGB8565:
            return MMI_FALSE;
            
        default:
            GDI_ASSERT(MMI_FALSE);
            break;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_normal_color_bytes
 * DESCRIPTION
 *  Query the pixel size WITHOUT alpha channel in bytes.
 * PARAMETERS
 *  pixel_format    [IN]    pixel format to query
 * RETURNS
 *  Pixel size in bytes.
 *****************************************************************************/
U32 gdi_image_ab2_normal_color_bytes(U32 pixel_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pixel_format)
    {
        case GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY:
        case GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE:
            return GDI_IMAGE_AB2_RGB888_SRC_KEY_NORMAL_BYTES;
            
        case GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY:
        case GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE:        
            return GDI_IMAGE_AB2_RGB565_SRC_KEY_NORMAL_BYTES;

        case GDI_IMAGE_AB2_FORMAT_PARGB8888:
            return GDI_IMAGE_AB2_PARGB8888_NORMAL_BYTES;
            
        case GDI_IMAGE_AB2_FORMAT_PARGB8565:
            return GDI_IMAGE_AB2_PARGB8565_NORMAL_BYTES;

        default:
            GDI_ASSERT(MMI_FALSE);
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_alpha_color_bytes
 * DESCRIPTION
 *  Query the pixel size with alpha channel in bytes.
 * PARAMETERS
 *  pixel_format    [IN]    pixel format to query
 * RETURNS
 *  Pixel size in bytes.
 *****************************************************************************/
U32 gdi_image_ab2_alpha_color_bytes(U32 pixel_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pixel_format)
    {
        case GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY:
        case GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE:
            return GDI_IMAGE_AB2_RGB888_SRC_KEY_ALPHA_BYTES;
            
        case GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY:
        case GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE:        
            return GDI_IMAGE_AB2_RGB565_SRC_KEY_ALPHA_BYTES;

        case GDI_IMAGE_AB2_FORMAT_PARGB8888:
            return GDI_IMAGE_AB2_PARGB8888_ALPHA_BYTES;
            
        case GDI_IMAGE_AB2_FORMAT_PARGB8565:
            return GDI_IMAGE_AB2_PARGB8565_ALPHA_BYTES;

        default:
            GDI_ASSERT(MMI_FALSE);
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_read_header
 * DESCRIPTION
 *  Read the ABMv2 image header from given buffer
 * PARAMETERS
 *  info_ptr        [OUT]   pointer to the result of header information
 *  header_ptr      [IN]    pointer to the header buffer
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_read_header(
    gdi_image_ab2_info_struct *info_ptr, 
    const U8 *header_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gdi_image_ab2_header_format_struct *header;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(info_ptr != NULL);
    GDI_ASSERT(header_ptr != NULL);

    /* cast the memory pointer */
    header = (const gdi_image_ab2_header_format_struct *)header_ptr;
    info_ptr->width             = header->width;
    info_ptr->height            = header->height;
    info_ptr->boundary_left     = header->boundary_left;
    info_ptr->boundary_top      = header->boundary_top;
    info_ptr->boundary_right    = header->boundary_right;
    info_ptr->boundary_bottom   = header->boundary_bottom;
    info_ptr->pixel_format      = header->format;
    info_ptr->algorithm         = header->algorithm;
    info_ptr->algorithm_header_ptr = header_ptr + GDI_IMAGE_AB2_HEADER_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_abm_v2_draw
 * DESCRIPTION
 *  Draw ABMv2 image on the current active layer
 * PARAMETERS
 *  offset_x        [IN]    x offset to draw
 *  offset_y        [IN]    y offset to draw
 *  data_ptr        [IN]    pointer to ABM data
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *****************************************************************************/
MMI_BOOL gdi_image_ab2_draw_to_buf(
    gdi_image_ab2_img_buf_struct *dst_buf,
    S32 offset_x, 
    S32 offset_y, 
    const U8 *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    gdi_image_ab2_info_struct info;
    gdi_image_ab2_img_buf_struct draw_dst_buf, draw_src_buf;
    gdi_rect_struct img_region;
    
    gdi_image_ab2_decode_mode_enum decode_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_buf != NULL);
    GDI_ASSERT(data_ptr != NULL);
    GDI_ASSERT(dst_buf->cf > GDI_COLOR_FORMAT_8 && dst_buf->cf < GDI_COLOR_FORMAT_STANDARD_END);
    
    if (((U32)data_ptr & 0x1) != 0)
    {
        return MMI_FALSE;
    }

    /* with no color replacement*/
    info.to_replace_color = 0;

    /*
     * Prepare data
     */
    /* Read file header */
    gdi_image_ab2_read_header(&info, data_ptr);

    /* Decide the decode mode */
    if (dst_buf->cf == GDI_COLOR_FORMAT_32 || dst_buf->cf == GDI_COLOR_FORMAT_32_PARGB ||
        dst_buf->cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        decode_mode = GDI_IMAGE_AB2_DECODE_MODE_OUTPUT;
    }
    else if (gdi_image_ab2_is_src_color_key_mode(&info))
    {
        decode_mode = GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY;
    }
    else
    {
        decode_mode = GDI_IMAGE_AB2_DECODE_MODE_ALPHA;
    }
    
    /* Prepare the decoder needed information */    
    if (!gdi_image_ab2_draw_prepare_to_buf(
        &draw_dst_buf, 
        &draw_src_buf, 
        &img_region, 
        dst_buf,
        offset_x, 
        offset_y, 
        &info,
        decode_mode))
    {
        /* out of range, no need to draw */
        return MMI_TRUE; 
    }

    /* Decode */
    switch (info.algorithm)
    {
        case GDI_IMAGE_AB2_ALGORITHM_RLE:
        {
            /* Always de-multiplied */
            ret = gdi_image_ab2_rle_decode(
                &draw_dst_buf, 
                &draw_src_buf, 
                &img_region, 
                &info, 
                decode_mode);
            break;
        }
        
        default:
            GDI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_to_buf_internal
 * DESCRIPTION
 *  Draw ABMv2 image on the current active layer with specified decode mode
 * PARAMETERS
 *  offset_x        [IN]    x offset to draw
 *  offset_y        [IN]    y offset to draw
 *  data_ptr        [IN]    pointer to ABM data
 *  decode_mode     [IN]    decode mode to process
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *****************************************************************************/
S32 gdi_image_ab2_draw_to_buf_internal(
    gdi_image_ab2_img_buf_struct *dst_buf,
    S32 offset_x, 
    S32 offset_y, 
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    MMI_BOOL ret_bool = MMI_TRUE;
    gdi_image_ab2_info_struct info;
    gdi_image_ab2_img_buf_struct draw_dst_buf, draw_src_buf;
    gdi_rect_struct img_region;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GDI_ASSERT(dst_buf != NULL);
    //GDI_ASSERT(data_ptr != NULL);

    if (dst_buf == NULL || data_ptr == NULL)
    {
        return GDI_FAILED;
    }
    
    if (((U32)data_ptr & 0x1) != 0)
    {
        return GDI_FAILED;
    }

    /* with no color replacement*/
    info.to_replace_color = 0;

    /*
     * Prepare data
     */
    /* Read file header */
    gdi_image_ab2_read_header(&info, data_ptr);

    /* Prepare the decoder needed information */    
    if (!gdi_image_ab2_draw_prepare_to_buf(
        &draw_dst_buf, 
        &draw_src_buf, 
        &img_region, 
        dst_buf,
        offset_x, 
        offset_y, 
        &info,
        decode_mode))
    {
        /* out of range, no need to draw */
        return GDI_SUCCEED; 
    }

    /* Decode */
    switch (info.algorithm)
    {
        case GDI_IMAGE_AB2_ALGORITHM_RLE:
        {
            /* Always de-multiplied */
            ret_bool = gdi_image_ab2_rle_decode_fully_opaque(
                &draw_dst_buf, 
                &draw_src_buf, 
                &img_region, 
                &info, 
                decode_mode);

            if (ret_bool == MMI_TRUE) ret = GDI_SUCCEED;
            else ret = GDI_FAILED;
            
            break;
        }
        
        default:
            return GDI_IMAGE_ERR_NO_DECODER_SUPPORT;//GDI_ASSERT(0);
    }


    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_get_final_decode_mode
 * DESCRIPTION
 *  Decide final decode mode of ab2 image
 * PARAMETERS
 *  dst_layer          [IN]    destination layer handle
 *  ab2_img_info       [IN]    ab2 header information
 *  decode_mode        [IN]    decode mode
 * RETURNS
 *  final_decode_mode    
 *****************************************************************************/
gdi_image_ab2_decode_mode_enum gdi_image_ab2_get_final_decode_mode(
    gdi_handle dst_layer,
    gdi_image_ab2_info_struct* ab2_img_info,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    gdi_color_format dst_layer_cf;

    /* Get destination layer color format */
    dst_layer_cf = ((gdi_layer_struct*)dst_layer)->cf;

    /*
     * Decide final decode mode
     */
    if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_AUTO ||
        decode_mode == GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA)
    {
        if ((dst_layer_cf == GDI_COLOR_FORMAT_32 || 
             dst_layer_cf == GDI_COLOR_FORMAT_32_PARGB ||
             dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666) &&
            decode_mode != GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA)
        {
            decode_mode = GDI_IMAGE_AB2_DECODE_MODE_OUTPUT;
        }
        else if (gdi_image_ab2_is_src_color_key_mode(ab2_img_info))
        {
            decode_mode = GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY;
        }
        else
        {
            decode_mode = GDI_IMAGE_AB2_DECODE_MODE_ALPHA;
        }
    }
    return decode_mode;
}


#ifdef GDI_IMAGE_AB2_HAS_GDI

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_internal
 * DESCRIPTION
 *  Draw ABMv2 image on the current active layer
 * PARAMETERS
 *  dst_layer       [IN]    destination layer handle
 *  offset_x        [IN]    x offset to draw
 *  offset_y        [IN]    y offset to draw
 *  src_layer       [IN]    source layer handle
 *  data_ptr        [IN]    pointer to ABMv2 header
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_internal(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_image_ab2_info_struct info;
    gdi_image_ab2_img_buf_struct dst_buf, src_buf;
    gdi_rect_struct img_region;
    
    gdi_color_format dst_layer_cf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_layer != GDI_NULL_HANDLE);
    GDI_ASSERT(data_ptr != NULL);
    
    if (((U32)data_ptr & 0x1) != 0)
    {
        return GDI_FAILED;
    }

    /* Read file header */
    gdi_image_ab2_read_header(&info, data_ptr);

    /* with no color replacement*/
    info.to_replace_color = 0;

    /* Get destination layer color format */
    dst_layer_cf = ((gdi_layer_struct*)dst_layer)->cf;

    decode_mode = gdi_image_ab2_get_final_decode_mode(dst_layer,&info,decode_mode);

    /* Must has blending source layer in alpha mode */
    /* Make sure blending source layer and dest layer has the same color format*/
    if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_ALPHA)
    {
        gdi_color_format src_layer_cf;
        
        if (src_layer == GDI_NULL_HANDLE)
        {
            return GDI_FAILED;
        }

        src_layer_cf = ((gdi_layer_struct*)src_layer)->cf;
        
        /* If source layer and destination layer has different color format */
        if (dst_layer_cf != src_layer_cf)
        {
            gdi_rect_struct dst_rect;
            
            /* Only support 24bits, 16bits source color */
            if (src_layer_cf != GDI_COLOR_FORMAT_16 && src_layer_cf != GDI_COLOR_FORMAT_24)
            {
                return GDI_FAILED;
            }

            /* Copy the layer and let source and destlayer */
            dst_rect.x1 = dst_layer_x;
            dst_rect.y1 = dst_layer_y;
            dst_rect.x2 = dst_layer_x + info.width - 1;
            dst_rect.y2 = dst_layer_y + info.height - 1;
            gdi_image_ab2_layer_copy(dst_layer, &dst_rect, src_layer);

            src_layer = dst_layer;
        }
    }
    
    /* Prepare the decoder needed information */
    if (!gdi_image_ab2_draw_prepare(
        &dst_buf, 
        &src_buf, 
        &img_region, 
        dst_layer,
        src_layer,
        dst_layer_x, 
        dst_layer_y, 
        &info,
        decode_mode))
    {
        /* out of range, no need to draw */
        return GDI_SUCCEED; 
    }

    /*
     * Do decoding
     */
    switch (info.algorithm)
    {
        case GDI_IMAGE_AB2_ALGORITHM_RLE:
        {
            ret = gdi_image_ab2_rle_decode(
                &dst_buf, 
                &src_buf, 
                &img_region, 
                &info,
                decode_mode) ? GDI_SUCCEED : GDI_FAILED;
            break;
        }
        
        default:
            GDI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_internal_with_color
 * DESCRIPTION
 *  Draw ABMv2 image on the current active layer
 * PARAMETERS
 *  dst_layer       [IN]    destination layer handle
 *  offset_x        [IN]    x offset to draw
 *  offset_y        [IN]    y offset to draw
 *  src_layer       [IN]    source layer handle
 *  data_ptr        [IN]    pointer to ABMv2 header
 *  color           [IN]    color to replace as
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_internal_with_color(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode,
    U32 color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_image_ab2_info_struct info;
    gdi_image_ab2_img_buf_struct dst_buf, src_buf;
    gdi_rect_struct img_region;
    
    gdi_color_format dst_layer_cf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_layer != GDI_NULL_HANDLE);
    GDI_ASSERT(data_ptr != NULL);
    
    if (((U32)data_ptr & 0x1) != 0)
    {
        return GDI_FAILED;
    }

    /* Read file header */
    gdi_image_ab2_read_header(&info, data_ptr);

    /* with color replacement*/
    info.to_replace_color = 1;
    info.replace_color = color;
    
    /* Get destination layer color format */
    dst_layer_cf = ((gdi_layer_struct*)dst_layer)->cf;

    /*
     * Decide a decode mode
     */
    if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_AUTO ||
        decode_mode == GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA)
    {
        if ((dst_layer_cf == GDI_COLOR_FORMAT_32 || 
             dst_layer_cf == GDI_COLOR_FORMAT_32_PARGB ||
             dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666) 
            && decode_mode != GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA)
        {
            decode_mode = GDI_IMAGE_AB2_DECODE_MODE_OUTPUT;
        }
        else if (gdi_image_ab2_is_src_color_key_mode(&info))
        {
            decode_mode = GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY;
        }
        else
        {
            decode_mode = GDI_IMAGE_AB2_DECODE_MODE_ALPHA;
        }
    }

    /* Must has blending source layer in alpha mode */
    /* Make sure blending source layer and dest layer has the same color format*/
    if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_ALPHA)
    {
        gdi_color_format src_layer_cf;
        
        if (src_layer == GDI_NULL_HANDLE)
        {
            return GDI_FAILED;
        }

        src_layer_cf = ((gdi_layer_struct*)src_layer)->cf;
        
        /* If source layer and destination layer has different color format */
        if (dst_layer_cf != src_layer_cf)
        {
            gdi_rect_struct dst_rect;
            
            /* Only support 24bits, 16bits source color */
            if (src_layer_cf != GDI_COLOR_FORMAT_16 && src_layer_cf != GDI_COLOR_FORMAT_24)
            {
                return GDI_FAILED;
            }

            /* Copy the layer and let source and destlayer */
            dst_rect.x1 = dst_layer_x;
            dst_rect.y1 = dst_layer_y;
            dst_rect.x2 = dst_layer_x + info.width - 1;
            dst_rect.y2 = dst_layer_y + info.height - 1;
            gdi_image_ab2_layer_copy(dst_layer, &dst_rect, src_layer);

            src_layer = dst_layer;
        }
    }
    
    /* Prepare the decoder needed information */
    if (!gdi_image_ab2_draw_prepare(
        &dst_buf, 
        &src_buf, 
        &img_region, 
        dst_layer,
        src_layer,
        dst_layer_x, 
        dst_layer_y, 
        &info,
        decode_mode))
    {
        /* out of range, no need to draw */
        return GDI_SUCCEED; 
    }

    /*
     * Do decoding
     */
    switch (info.algorithm)
    {
        case GDI_IMAGE_AB2_ALGORITHM_RLE:
        {
            ret = gdi_image_ab2_rle_decode(
                &dst_buf, 
                &src_buf, 
                &img_region, 
                &info,
                decode_mode) ? GDI_SUCCEED : GDI_FAILED;
            break;
        }
        
        default:
            GDI_ASSERT(0);
    }

    return ret;
}


#endif /* GDI_IMAGE_AB2_HAS_GDI */


