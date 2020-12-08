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
 *  gdi_blending.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gdi_include.h"
#include "gdi_primitive.h"
#include "gdi_util.h"
#include "gdi_image.h"


/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_blending_32_to_16
 * DESCRIPTION
 *  alpha blending img_ptr & src_ptr layer, then output to active_ptr.
 * PARAMETERS
 *  img_ptr             [IN]  img layer pointer
 *  img_pitch_bytes     [IN]  img layer width
 *  active_ptr          [IN]  output start pointer
 *  active_pitch_bytes  [IN]  active layer width
 *  src_ptr             [IN]  source layer pointer
 *  src_pitch_bytes     [IN]  source layer width
 *  width               [IN]  output region width
 *  height              [IN]  output region height
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_blending_32_to_16(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (height--)
    {
        U8 *img_line_ptr = img_ptr;
        U8 *src_line_ptr = src_ptr;
        U8 *active_line_ptr = active_ptr;        
        S32 line_width = width;
        
        while (line_width--)
        {
            U32 output_pixel = 0;
            U32 img_pixel, img_a;
            U32 src_pixel, src_pixel_32;
            U32 output_a, output_r, output_g, output_b;
            
            img_pixel = GDI_MEM_GET_32(img_line_ptr);
            img_a = 255 - GDI_A_OF_ARGB8888(img_pixel);

            if (img_a == 0) /* alpha == 255 */
            {
                output_pixel = GDI_RGB565_FROM_ARGB8888(img_pixel);
                GDI_MEM_PUT_16(active_line_ptr, output_pixel);
            }
            else if (img_a == 255) /* alpha == 0 */
            {
                src_pixel = GDI_MEM_GET_16(src_line_ptr);
                GDI_MEM_PUT_16(active_line_ptr, src_pixel);
            }
            else
            {
                output_a = GDI_A_OF_ARGB8888(img_pixel);
                output_r = GDI_R_OF_ARGB8888(img_pixel);
                output_g = GDI_G_OF_ARGB8888(img_pixel);
                output_b = GDI_B_OF_ARGB8888(img_pixel);
                
                src_pixel = GDI_MEM_GET_16(src_line_ptr);
                src_pixel_32 = GDI_ARGB8888_FROM_RGB565(src_pixel);
                output_a += GDI_DIV_255(GDI_A_OF_ARGB8888(src_pixel_32) * img_a);
                output_r += GDI_DIV_255(GDI_R_OF_ARGB8888(src_pixel_32) * img_a);
                output_g += GDI_DIV_255(GDI_G_OF_ARGB8888(src_pixel_32) * img_a);
                output_b += GDI_DIV_255(GDI_B_OF_ARGB8888(src_pixel_32) * img_a);

                if (output_a > 255)
                    output_a = 255;
                if (output_r > 255)
                    output_r = 255;
                if (output_g > 255)
                    output_g = 255;
                if (output_b > 255)
                    output_b = 255;
                output_pixel += output_a << 24;
                output_pixel += output_r << 16;
                output_pixel += output_g << 8;
                output_pixel += output_b;

                output_pixel = GDI_RGB565_FROM_ARGB8888(output_pixel);
                GDI_MEM_PUT_16(active_line_ptr, output_pixel);
            }

            img_line_ptr += sizeof(U32);
            src_line_ptr += sizeof(U16);
            active_line_ptr += sizeof(U16);
        }
        
        img_ptr += img_pitch_bytes;
        src_ptr += src_pitch_bytes;
        active_ptr += active_pitch_bytes;
    }

    return GDI_SUCCEED;
}
    

/*****************************************************************************
 * FUNCTION
 *  gdi_image_blending_32_to_24
 * DESCRIPTION
 *  alpha blending img_ptr & src_ptr layer, then output to active_ptr.
 * PARAMETERS
 *  img_ptr             [IN]  img layer pointer
 *  img_pitch_bytes     [IN]  img layer width
 *  active_ptr          [IN]  output start pointer
 *  active_pitch_bytes  [IN]  active layer width
 *  src_ptr             [IN]  source layer pointer
 *  src_pitch_bytes     [IN]  source layer width
 *  width               [IN]  output region width
 *  height              [IN]  output region height
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_blending_32_to_24(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (height--)
    {
        U8 *img_line_ptr = img_ptr;
        U8 *src_line_ptr = src_ptr;
        U8 *active_line_ptr = active_ptr;        
        S32 line_width = width;
        
        while (line_width--)
        {
            U32 output_pixel = 0;
            U32 img_pixel, img_a;
            U32 src_pixel;
            
            img_pixel = GDI_MEM_GET_32(img_line_ptr);
            img_a = 255 - GDI_A_OF_ARGB8888(img_pixel);
            output_pixel += GDI_R_OF_ARGB8888(img_pixel) << 16;
            output_pixel += GDI_G_OF_ARGB8888(img_pixel) << 8;
            output_pixel += GDI_B_OF_ARGB8888(img_pixel);
            
            src_pixel = GDI_MEM_GET_24(src_line_ptr);
            output_pixel += GDI_DIV_255(GDI_R_OF_RGB888(src_pixel) * img_a) << 16;
            output_pixel += GDI_DIV_255(GDI_G_OF_RGB888(src_pixel) * img_a) << 8;
            output_pixel += GDI_DIV_255(GDI_B_OF_RGB888(src_pixel) * img_a);

            GDI_MEM_PUT_24(active_line_ptr, output_pixel);

            img_line_ptr += sizeof(U32);
            src_line_ptr += 3;
            active_line_ptr += 3;
        }
        
        img_ptr += img_pitch_bytes;
        src_ptr += src_pitch_bytes;
        active_ptr += active_pitch_bytes;
    }

    return GDI_SUCCEED;
}
    

/*****************************************************************************
 * FUNCTION
 *  gdi_image_blending_32_to_32
 * DESCRIPTION
 *  alpha blending img_ptr & src_ptr layer, then output to active_ptr.
 * PARAMETERS
 *  img_ptr             [IN]  img layer pointer
 *  img_pitch_bytes     [IN]  img layer width
 *  active_ptr          [IN]  output start pointer
 *  active_pitch_bytes  [IN]  active layer width
 *  src_ptr             [IN]  source layer pointer
 *  src_pitch_bytes     [IN]  source layer width
 *  width               [IN]  output region width
 *  height              [IN]  output region height
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_blending_32_to_32(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (height--)
    {
        U8 *img_line_ptr = img_ptr;
        U8 *src_line_ptr = src_ptr;
        U8 *active_line_ptr = active_ptr;        
        S32 line_width = width;
        
        while (line_width--)
        {
            U32 output_pixel = 0;
            U32 img_pixel, img_a;
            U32 src_pixel;
            
            img_pixel = GDI_MEM_GET_32(img_line_ptr);
            img_a = 255 - GDI_A_OF_ARGB8888(img_pixel);

            if (img_a == 0) /* alpha == 255 */
            {
                GDI_MEM_PUT_32(active_line_ptr, img_pixel);
            }
            else if (img_a == 255) /* alpha == 0 */
            {
                src_pixel = GDI_MEM_GET_32(src_line_ptr);
                GDI_MEM_PUT_32(active_line_ptr, src_pixel);
            }
            else
            {
                output_pixel = img_pixel;
                
                src_pixel = GDI_MEM_GET_32(src_line_ptr);
                output_pixel += GDI_DIV_255(GDI_A_OF_ARGB8888(src_pixel) * img_a) << 24;
                output_pixel += GDI_DIV_255(GDI_R_OF_ARGB8888(src_pixel) * img_a) << 16;
                output_pixel += GDI_DIV_255(GDI_G_OF_ARGB8888(src_pixel) * img_a) << 8;
                output_pixel += GDI_DIV_255(GDI_B_OF_ARGB8888(src_pixel) * img_a);

                GDI_MEM_PUT_32(active_line_ptr, output_pixel);
            }

            img_line_ptr += sizeof(U32);
            src_line_ptr += sizeof(U32);
            active_line_ptr += sizeof(U32);
        }
        
        img_ptr += img_pitch_bytes;
        src_ptr += src_pitch_bytes;
        active_ptr += active_pitch_bytes;
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_blending_32_to_PARGB6666
 * DESCRIPTION
 *  alpha blending img_ptr & src_ptr layer, then output to active_ptr.
 * PARAMETERS
 *  img_ptr             [IN]  img layer pointer
 *  img_pitch_bytes     [IN]  img layer width
 *  active_ptr          [IN]  output start pointer
 *  active_pitch_bytes  [IN]  active layer width
 *  src_ptr             [IN]  source layer pointer
 *  src_pitch_bytes     [IN]  source layer width
 *  width               [IN]  output region width
 *  height              [IN]  output region height
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_blending_PARGB8888_to_PARGB6666(
    U8 *img_ptr,
    U32 img_pitch_bytes,
    U8 *active_ptr,
    U32 active_pitch_bytes,
    U8 *src_ptr,
    U32 src_pitch_bytes,
    S32 width,
    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (height--)
    {
        U8 *img_line_ptr = img_ptr;
        U8 *src_line_ptr = src_ptr;
        U8 *active_line_ptr = active_ptr;        
        S32 line_width = width;
        
        while (line_width--)
        {
            U32 output_pixel = 0;
            U32 img_pixel, img_inv_a;
            U32 src_pixel;
            
            img_pixel = GDI_MEM_GET_32(img_line_ptr);
            img_pixel = GDI_PARGB6666_FROM_PARGB8888(img_pixel);
            img_inv_a = 0x3f - GDI_A_OF_PARGB6666(img_pixel);

            if (img_inv_a == 0) /* alpha == 0x3f */
            {
                GDI_MEM_PUT_24(active_line_ptr, img_pixel);
            }
            else if (img_inv_a == 0x3f) /* alpha == 0 */
            {
                src_pixel = GDI_MEM_GET_24(src_line_ptr);
                GDI_MEM_PUT_24(active_line_ptr, src_pixel);
            }
            else
            {
                src_pixel = GDI_MEM_GET_24(src_line_ptr);
                output_pixel = img_pixel;
                output_pixel += GDI_PARGB6666(
                    GDI_DIV_63(GDI_A_OF_PARGB6666(src_pixel) * img_inv_a),
                    GDI_DIV_63(GDI_PR_OF_PARGB6666(src_pixel) * img_inv_a),
                    GDI_DIV_63(GDI_PG_OF_PARGB6666(src_pixel) * img_inv_a),
                    GDI_DIV_63(GDI_PB_OF_PARGB6666(src_pixel) * img_inv_a));

                GDI_MEM_PUT_24(active_line_ptr, output_pixel);
            }

            img_line_ptr += sizeof(U32);
            src_line_ptr += 3;
            active_line_ptr += 3;
        }
        
        img_ptr += img_pitch_bytes;
        src_ptr += src_pitch_bytes;
        active_ptr += active_pitch_bytes;
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bitlit_PARGB8888
 * DESCRIPTION
 *  alpha blending img_layer & srouce layer, then output to active layer.
 *  The color format of img_layer should be PARGB8888.
 *  The source layer should not be NULL, and its color format should equal to active layer.
 * PARAMETERS
 *  img_layer  [IN]  the img_layer
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bitlit_PARGB8888(gdi_handle img_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    S32 img_offset_x, img_offset_y;
    S32 img_width;
    S32 img_clip_x1, img_clip_y1, img_clip_x2, img_clip_y2;
    U8 *img_ptr;
    U32 img_pixel_bytes;
    U32 img_pitch_bytes;
    gdi_color_format img_cf;
    
    gdi_handle active_layer_handle = GDI_NULL_HANDLE;
    S32 active_offset_x, active_offset_y;
    S32 active_width;
    S32 active_clip_x1, active_clip_y1, active_clip_x2, active_clip_y2;
    U8 *active_ptr;
    U32 active_pixel_bytes;
    U32 active_pitch_bytes;
    gdi_color_format active_cf;
    
    gdi_handle src_layer_handle = GDI_NULL_HANDLE;
    S32 src_offset_x, src_offset_y;
    S32 src_width;
    S32 src_clip_x1, src_clip_y1, src_clip_x2, src_clip_y2;
    U8 *src_ptr;
    U32 src_pixel_bytes;
    U32 src_pitch_bytes;
    gdi_color_format src_cf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&active_layer_handle);
    gdi_get_alpha_blending_source_layer(&src_layer_handle);
    if (src_layer_handle == GDI_NULL_HANDLE)
    {
        return GDI_FAILED;
    }

    /*
     * Prepare all data
     */
    img_offset_x        = ((gdi_layer_struct*)img_layer)->offset_x;
    img_offset_y        = ((gdi_layer_struct*)img_layer)->offset_y;
    img_width           = ((gdi_layer_struct*)img_layer)->width;
    img_clip_x1         = ((gdi_layer_struct*)img_layer)->clipx1;
    img_clip_y1         = ((gdi_layer_struct*)img_layer)->clipy1;
    img_clip_x2         = ((gdi_layer_struct*)img_layer)->clipx2;
    img_clip_y2         = ((gdi_layer_struct*)img_layer)->clipy2;
    img_ptr             = ((gdi_layer_struct*)img_layer)->buf_ptr;
    img_pixel_bytes     = ((gdi_layer_struct*)img_layer)->bits_per_pixel / 8;
    img_cf              = ((gdi_layer_struct*)img_layer)->cf;
    img_pitch_bytes     = img_width * img_pixel_bytes;
    
    active_offset_x     = ((gdi_layer_struct*)active_layer_handle)->offset_x;
    active_offset_y     = ((gdi_layer_struct*)active_layer_handle)->offset_y;
    active_width        = ((gdi_layer_struct*)active_layer_handle)->width;
    active_clip_x1      = ((gdi_layer_struct*)active_layer_handle)->clipx1;
    active_clip_y1      = ((gdi_layer_struct*)active_layer_handle)->clipy1;
    active_clip_x2      = ((gdi_layer_struct*)active_layer_handle)->clipx2;
    active_clip_y2      = ((gdi_layer_struct*)active_layer_handle)->clipy2;
    active_ptr          = ((gdi_layer_struct*)active_layer_handle)->buf_ptr;
    active_pixel_bytes  = ((gdi_layer_struct*)active_layer_handle)->bits_per_pixel / 8;
    active_cf           = ((gdi_layer_struct*)active_layer_handle)->cf;
    active_pitch_bytes  = active_width * active_pixel_bytes;
    
    src_offset_x        = ((gdi_layer_struct*)src_layer_handle)->offset_x;
    src_offset_y        = ((gdi_layer_struct*)src_layer_handle)->offset_y;
    src_width           = ((gdi_layer_struct*)src_layer_handle)->width;
    src_clip_x1         = ((gdi_layer_struct*)src_layer_handle)->clipx1;
    src_clip_y1         = ((gdi_layer_struct*)src_layer_handle)->clipy1;
    src_clip_x2         = ((gdi_layer_struct*)src_layer_handle)->clipx2;
    src_clip_y2         = ((gdi_layer_struct*)src_layer_handle)->clipy2;
    src_ptr             = ((gdi_layer_struct*)src_layer_handle)->buf_ptr;
    src_pixel_bytes     = ((gdi_layer_struct*)src_layer_handle)->bits_per_pixel / 8;
    src_cf              = ((gdi_layer_struct*)src_layer_handle)->cf;
    src_pitch_bytes     = src_width * src_pixel_bytes;

    /*
     * Check all data
     */
    /* Must be PARGB8888 (32 bits = 4 bytes) */
    GDI_ASSERT(img_pixel_bytes == 4);

    /*
     * Caculate clip
     */
    /* Tansform image layer clip to active layer and intersect */
    img_clip_x1         += (img_offset_x - active_offset_x);
    img_clip_y1         += (img_offset_y - active_offset_y);
    img_clip_x2         += (img_offset_x - active_offset_x);
    img_clip_y2         += (img_offset_y - active_offset_y);
    active_clip_x1      = GDI_MAX(active_clip_x1, img_clip_x1);
    active_clip_y1      = GDI_MAX(active_clip_y1, img_clip_y1);
    active_clip_x2      = GDI_MIN(active_clip_x2, img_clip_x2);
    active_clip_y2      = GDI_MIN(active_clip_y2, img_clip_y2);

    /* Tansform image layer clip to active layer and intersect */
    src_clip_x1         += (src_offset_x - active_offset_x);
    src_clip_y1         += (src_offset_y - active_offset_y);
    src_clip_x2         += (src_offset_x - active_offset_x);
    src_clip_y2         += (src_offset_y - active_offset_y);
    active_clip_x1      = GDI_MAX(active_clip_x1, src_clip_x1);
    active_clip_y1      = GDI_MAX(active_clip_y1, src_clip_y1);
    active_clip_x2      = GDI_MIN(active_clip_x2, src_clip_x2);
    active_clip_y2      = GDI_MIN(active_clip_y2, src_clip_y2);

    /* Actual size to blit */
    width = active_clip_x2 - active_clip_x1 + 1;
    height = active_clip_y2 - active_clip_y1 + 1; 

    /* Zero size, do nothing */
    if (width <= 0 || height <= 0)
    {
        return GDI_SUCCEED;
    }

    active_ptr          += (active_clip_y1 * active_pitch_bytes) + active_clip_x1 * active_pixel_bytes;

    /* Actual image clip to blit */
    img_clip_x1         = active_clip_x1 + (active_offset_x - img_offset_x);
    img_clip_y1         = active_clip_y1 + (active_offset_y - img_offset_y);
    img_clip_x2         = active_clip_x2 + (active_offset_x - img_offset_x);
    img_clip_y2         = active_clip_y2 + (active_offset_y - img_offset_y);
    img_ptr             += (img_clip_y1 * img_pitch_bytes) + img_clip_x1 * img_pixel_bytes;
    
    /* Actual source clip to blit */
    src_clip_x1         = active_clip_x1 + (active_offset_x - src_offset_x);
    src_clip_y1         = active_clip_y1 + (active_offset_y - src_offset_y);
    src_clip_x2         = active_clip_x2 + (active_offset_x - src_offset_x);
    src_clip_y2         = active_clip_y2 + (active_offset_y - src_offset_y);
    src_ptr             += (src_clip_y1 * src_pitch_bytes) + src_clip_x1 * src_pixel_bytes;

    if (active_cf == GDI_COLOR_FORMAT_16 && src_cf == GDI_COLOR_FORMAT_16)
    {
        gdi_image_blending_32_to_16(
            img_ptr,
            img_pitch_bytes,
            active_ptr,
            active_pitch_bytes,
            src_ptr,
            src_pitch_bytes,
            width,
            height);
    }
    #if !defined(GDI_SLIM_COLOR_FORMAT)
    else if (active_cf == GDI_COLOR_FORMAT_24 && src_cf == GDI_COLOR_FORMAT_24)
    {
        gdi_image_blending_32_to_24(
            img_ptr,
            img_pitch_bytes,
            active_ptr,
            active_pitch_bytes,
            src_ptr,
            src_pitch_bytes,
            width,
            height);
    }
    #endif
    
    else if ((active_cf == GDI_COLOR_FORMAT_32 || active_cf == GDI_COLOR_FORMAT_32_PARGB) &&
             (src_cf == GDI_COLOR_FORMAT_32 || src_cf == GDI_COLOR_FORMAT_32_PARGB))
    {
        gdi_image_blending_32_to_32(
            img_ptr,
            img_pitch_bytes,
            active_ptr,
            active_pitch_bytes,
            src_ptr,
            src_pitch_bytes,
            width,
            height);
    }
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    else if (active_cf == GDI_COLOR_FORMAT_PARGB6666 && src_cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        gdi_image_blending_PARGB8888_to_PARGB6666(
            img_ptr,
            img_pitch_bytes,
            active_ptr,
            active_pitch_bytes,
            src_ptr,
            src_pitch_bytes,
            width,
            height);
    }
#endif
    else
    {
        /* General case */
        gdi_img_buf_struct img_buf, dst_buf, src_buf;
        
        img_buf.ptr = img_ptr;
        img_buf.color_format = gdi_img_buf_trans_color_format(img_cf);
        img_buf.pitch_bytes = img_pitch_bytes;
        
        dst_buf.ptr = active_ptr;
        dst_buf.color_format = gdi_img_buf_trans_color_format(active_cf);
        dst_buf.pitch_bytes = active_pitch_bytes;
        
        src_buf.ptr = src_ptr;
        src_buf.color_format = gdi_img_buf_trans_color_format(src_cf);
        src_buf.pitch_bytes = src_pitch_bytes;
        
        gdi_img_buf_copy(&dst_buf, &src_buf, width, height);
        gdi_img_buf_blending(&dst_buf, &img_buf, width, height);            
    }

    return GDI_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  gdi_image_resize_and_blending_int
 * DESCRIPTION
 *  resize layer_handle to resized_width & resized_height, and then blend to active layer.
 *  color format of layer_handle only support GDI_COLOR_FORMAT_32_PARGB.
 *  the output region is (dst_x, dst_y) to (dst_x+resized_width-1, dst_y+resized_height-1)
 * PARAMETERS
 *  layer_handle    [IN]  resize layer_handle and blend to active layer
 *  dst_x           [IN]  output x on active layer
 *  dst_y           [IN]  output y on active layer
 *  resized_width   [IN]  output width on active layer
 *  resized_height  [IN]  output height on active layer
 *  always_blending [IN]  direct output on 32bits layer if always_blending is false
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_resize_and_blending_ex_PARGB8888(
    gdi_handle layer_handle,
    S32 dst_x,
    S32 dst_y,
    S32 resized_width,
    S32 resized_height,
    MMI_BOOL always_blending)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle dst_layer_handle, resized_layer_handle;
    gdi_handle blend_src_layer_handle, act_layer;
    gdi_color_format dst_layer_cf;
    S32 origin_width, origin_height;
    gdi_layer_struct *layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer = (gdi_layer_struct*)layer_handle;

    gdi_layer_get_active(&dst_layer_handle);
    dst_layer_cf = ((gdi_layer_struct *)dst_layer_handle)->cf;
    
    origin_width = ((gdi_layer_struct *)layer_handle)->width;
    origin_height = ((gdi_layer_struct *)layer_handle)->height;
            
    if (!always_blending && 
        (dst_layer_cf == GDI_COLOR_FORMAT_32 || dst_layer_cf == GDI_COLOR_FORMAT_32_PARGB))
    {
        /* Change to PARGB temporary */
        //((gdi_layer_struct *)dst_layer_handle)->vcf = GDI_COLOR_FORMAT_32_PARGB;
        if (dst_layer_cf == GDI_COLOR_FORMAT_32)
        {
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_32_PARGB);
        }
        
        /* Directly resize */
        gdi_bitblt_resized_with_resizer(
            layer_handle, 
            0,
            0,
            origin_width - 1,
            origin_height - 1,
            dst_x,
            dst_y,
            dst_x + resized_width - 1,
            dst_y + resized_height - 1,
            GDI_RESIZER_SW_QUALITY_MEDIUM);
        
        /* Restore color format */
        //((gdi_layer_struct *)dst_layer_handle)->vcf = dst_layer_vcf;
        gdi_layer_set_color_format(dst_layer_cf);

        /* De-PARGB if the output to ARGB layer */
        if (dst_layer_cf == GDI_COLOR_FORMAT_32)
        {
            do
            {
                gdi_rect_struct dest_clip;
                dest_clip.x1 = dst_x;
                dest_clip.y1 = dst_y;
                dest_clip.x2 = dst_x + resized_width - 1;
                dest_clip.y2 = dst_y + resized_height - 1;
                GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);
                
                gdi_util_convert_PARGB8888_to_ARGB8888_buf(
                    ((gdi_layer_struct *)dst_layer_handle)->buf_ptr,
                    ((gdi_layer_struct *)dst_layer_handle)->width,
                    dest_clip.x1,
                    dest_clip.y1,
                    dest_clip.x2 - dest_clip.x1 + 1,
                    dest_clip.y2 - dest_clip.y1 + 1);
            }while(0);
        }
    }
    else
    {
        /* Create resized temp layer */
        gdi_image_create_temp_layer(
            &resized_layer_handle,
            GDI_COLOR_FORMAT_32_PARGB,
            gdi_act_layer->offset_x + dst_x,
            gdi_act_layer->offset_y + dst_y,
            resized_width,
            resized_height);
        if (resized_layer_handle == GDI_NULL_HANDLE)
        {
            return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
        }

        /* Step 1: Resize */
        gdi_layer_push_and_set_active(resized_layer_handle);
        gdi_bitblt_resized_with_resizer(
            layer_handle, 
            0,
            0,
            origin_width - 1,
            origin_height - 1,
            0,
            0,
            resized_width - 1,
            resized_height - 1,
            GDI_RESIZER_SW_QUALITY_MEDIUM);
        gdi_layer_pop_and_restore_active();

        /* Step 2: Blending */
        gdi_layer_push_clip();

        do
        {
            gdi_rect_struct dest_clip;
            dest_clip.x1 = dst_x;
            dest_clip.y1 = dst_y;
            dest_clip.x2 = dst_x + resized_width - 1;
            dest_clip.y2 = dst_y + resized_height - 1;
            GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);

            gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);
            
            gdi_get_alpha_blending_source_layer(&blend_src_layer_handle);
            if (blend_src_layer_handle == GDI_NULL_HANDLE)
            {
              gdi_layer_get_active(&act_layer);
              gdi_push_and_set_alpha_blending_source_layer(act_layer);
              gdi_image_bitlit_PARGB8888(resized_layer_handle);
              gdi_pop_and_restore_alpha_blending_source_layer();
            }
            else
            {
              gdi_image_bitlit_PARGB8888(resized_layer_handle);  
            }
            
        }while(0);
        
        gdi_layer_pop_clip();

        /* Free resized temp layer */
        gdi_image_free_temp_layer(resized_layer_handle);
    }

    return GDI_SUCCEED;
}


#ifdef GDI_LAYER_PARGB6666_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  gdi_image_bitlit_PARGB8888
 * DESCRIPTION
 *  alpha blending img_layer & srouce layer, then output to active layer.
 *  The color format of img_layer should be PARGB6666.
 *  The source layer should not be NULL, and its color format should equal to active layer.
 * PARAMETERS
 *  img_layer  [IN]  the img_layer
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_bitlit_PARGB6666(gdi_handle img_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    S32 img_offset_x, img_offset_y;
    S32 img_width;
    S32 img_clip_x1, img_clip_y1, img_clip_x2, img_clip_y2;
    U8 *img_ptr;
    U32 img_pixel_bytes;
    U32 img_pitch_bytes;
    gdi_color_format img_cf;
    
    gdi_handle active_layer_handle = GDI_NULL_HANDLE;
    S32 active_offset_x, active_offset_y;
    S32 active_width;
    S32 active_clip_x1, active_clip_y1, active_clip_x2, active_clip_y2;
    U8 *active_ptr;
    U32 active_pixel_bytes;
    U32 active_pitch_bytes;
    gdi_color_format active_cf;
    
    gdi_handle src_layer_handle = GDI_NULL_HANDLE;
    S32 src_offset_x, src_offset_y;
    S32 src_width;
    S32 src_clip_x1, src_clip_y1, src_clip_x2, src_clip_y2;
    U8 *src_ptr;
    U32 src_pixel_bytes;
    U32 src_pitch_bytes;
    gdi_color_format src_cf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&active_layer_handle);
    gdi_get_alpha_blending_source_layer(&src_layer_handle);
    if (src_layer_handle == GDI_NULL_HANDLE)
    {
        return GDI_FAILED;
    }

    /*
     * Prepare all data
     */
    img_offset_x        = ((gdi_layer_struct*)img_layer)->offset_x;
    img_offset_y        = ((gdi_layer_struct*)img_layer)->offset_y;
    img_width           = ((gdi_layer_struct*)img_layer)->width;
    img_clip_x1         = ((gdi_layer_struct*)img_layer)->clipx1;
    img_clip_y1         = ((gdi_layer_struct*)img_layer)->clipy1;
    img_clip_x2         = ((gdi_layer_struct*)img_layer)->clipx2;
    img_clip_y2         = ((gdi_layer_struct*)img_layer)->clipy2;
    img_ptr             = ((gdi_layer_struct*)img_layer)->buf_ptr;
    img_pixel_bytes     = ((gdi_layer_struct*)img_layer)->bits_per_pixel / 8;
    img_cf              = ((gdi_layer_struct*)img_layer)->cf;
    img_pitch_bytes     = img_width * img_pixel_bytes;
    
    active_offset_x     = ((gdi_layer_struct*)active_layer_handle)->offset_x;
    active_offset_y     = ((gdi_layer_struct*)active_layer_handle)->offset_y;
    active_width        = ((gdi_layer_struct*)active_layer_handle)->width;
    active_clip_x1      = ((gdi_layer_struct*)active_layer_handle)->clipx1;
    active_clip_y1      = ((gdi_layer_struct*)active_layer_handle)->clipy1;
    active_clip_x2      = ((gdi_layer_struct*)active_layer_handle)->clipx2;
    active_clip_y2      = ((gdi_layer_struct*)active_layer_handle)->clipy2;
    active_ptr          = ((gdi_layer_struct*)active_layer_handle)->buf_ptr;
    active_pixel_bytes  = ((gdi_layer_struct*)active_layer_handle)->bits_per_pixel / 8;
    active_cf           = ((gdi_layer_struct*)active_layer_handle)->cf;
    active_pitch_bytes  = active_width * active_pixel_bytes;
    
    src_offset_x        = ((gdi_layer_struct*)src_layer_handle)->offset_x;
    src_offset_y        = ((gdi_layer_struct*)src_layer_handle)->offset_y;
    src_width           = ((gdi_layer_struct*)src_layer_handle)->width;
    src_clip_x1         = ((gdi_layer_struct*)src_layer_handle)->clipx1;
    src_clip_y1         = ((gdi_layer_struct*)src_layer_handle)->clipy1;
    src_clip_x2         = ((gdi_layer_struct*)src_layer_handle)->clipx2;
    src_clip_y2         = ((gdi_layer_struct*)src_layer_handle)->clipy2;
    src_ptr             = ((gdi_layer_struct*)src_layer_handle)->buf_ptr;
    src_pixel_bytes     = ((gdi_layer_struct*)src_layer_handle)->bits_per_pixel / 8;
    src_cf              = ((gdi_layer_struct*)src_layer_handle)->cf;
    src_pitch_bytes     = src_width * src_pixel_bytes;

    GDI_ASSERT(img_cf == GDI_COLOR_FORMAT_PARGB6666);
    
    /*
     * Caculate clip
     */
    /* Tansform image layer clip to active layer and intersect */
    img_clip_x1         += (img_offset_x - active_offset_x);
    img_clip_y1         += (img_offset_y - active_offset_y);
    img_clip_x2         += (img_offset_x - active_offset_x);
    img_clip_y2         += (img_offset_y - active_offset_y);
    active_clip_x1      = GDI_MAX(active_clip_x1, img_clip_x1);
    active_clip_y1      = GDI_MAX(active_clip_y1, img_clip_y1);
    active_clip_x2      = GDI_MIN(active_clip_x2, img_clip_x2);
    active_clip_y2      = GDI_MIN(active_clip_y2, img_clip_y2);

    /* Tansform image layer clip to active layer and intersect */
    src_clip_x1         += (src_offset_x - active_offset_x);
    src_clip_y1         += (src_offset_y - active_offset_y);
    src_clip_x2         += (src_offset_x - active_offset_x);
    src_clip_y2         += (src_offset_y - active_offset_y);
    active_clip_x1      = GDI_MAX(active_clip_x1, src_clip_x1);
    active_clip_y1      = GDI_MAX(active_clip_y1, src_clip_y1);
    active_clip_x2      = GDI_MIN(active_clip_x2, src_clip_x2);
    active_clip_y2      = GDI_MIN(active_clip_y2, src_clip_y2);

    /* Actual size to blit */
    width = active_clip_x2 - active_clip_x1 + 1;
    height = active_clip_y2 - active_clip_y1 + 1; 

    /* Zero size, do nothing */
    if (width <= 0 || height <= 0)
    {
        return GDI_SUCCEED;
    }

    active_ptr          += (active_clip_y1 * active_pitch_bytes) + active_clip_x1 * active_pixel_bytes;

    /* Actual image clip to blit */
    img_clip_x1         = active_clip_x1 + (active_offset_x - img_offset_x);
    img_clip_y1         = active_clip_y1 + (active_offset_y - img_offset_y);
    img_clip_x2         = active_clip_x2 + (active_offset_x - img_offset_x);
    img_clip_y2         = active_clip_y2 + (active_offset_y - img_offset_y);
    img_ptr             += (img_clip_y1 * img_pitch_bytes) + img_clip_x1 * img_pixel_bytes;
    
    /* Actual source clip to blit */
    src_clip_x1         = active_clip_x1 + (active_offset_x - src_offset_x);
    src_clip_y1         = active_clip_y1 + (active_offset_y - src_offset_y);
    src_clip_x2         = active_clip_x2 + (active_offset_x - src_offset_x);
    src_clip_y2         = active_clip_y2 + (active_offset_y - src_offset_y);
    src_ptr             += (src_clip_y1 * src_pitch_bytes) + src_clip_x1 * src_pixel_bytes;

    {
        /* General case */
        gdi_img_buf_struct img_buf, dst_buf, src_buf;
        
        img_buf.ptr = img_ptr;
        img_buf.color_format = gdi_img_buf_trans_color_format(img_cf);
        img_buf.pitch_bytes = img_pitch_bytes;
        
        dst_buf.ptr = active_ptr;
        dst_buf.color_format = gdi_img_buf_trans_color_format(active_cf);
        dst_buf.pitch_bytes = active_pitch_bytes;
        
        src_buf.ptr = src_ptr;
        src_buf.color_format = gdi_img_buf_trans_color_format(src_cf);
        src_buf.pitch_bytes = src_pitch_bytes;
        
        gdi_img_buf_copy(&dst_buf, &src_buf, width, height);
        gdi_img_buf_blending(&dst_buf, &img_buf, width, height);
    }

    return GDI_SUCCEED;
}



GDI_RESULT gdi_image_resize_and_blending_ex_PARGB6666(
    gdi_handle layer_handle,
    S32 dst_x,
    S32 dst_y,
    S32 resized_width,
    S32 resized_height,
    MMI_BOOL always_blending)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle dst_layer_handle, resized_layer_handle;
    gdi_handle blend_src_layer_handle, act_layer;
    gdi_color_format dst_layer_cf;
    S32 origin_width, origin_height;
    gdi_layer_struct *layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer = (gdi_layer_struct*)layer_handle;

    gdi_layer_get_active(&dst_layer_handle);
    dst_layer_cf = ((gdi_layer_struct *)dst_layer_handle)->cf;
    
    origin_width = ((gdi_layer_struct *)layer_handle)->width;
    origin_height = ((gdi_layer_struct *)layer_handle)->height;
            
    if (!always_blending && (dst_layer_cf == GDI_COLOR_FORMAT_PARGB6666))
    {
        /* Directly resize */
        gdi_bitblt_resized_with_resizer(
            layer_handle, 
            0,
            0,
            origin_width - 1,
            origin_height - 1,
            dst_x,
            dst_y,
            dst_x + resized_width - 1,
            dst_y + resized_height - 1,
            GDI_RESIZER_SW_QUALITY_MEDIUM);
    }
    else
    {
        /* Create resized temp layer */
        gdi_image_create_temp_layer(
            &resized_layer_handle,
            GDI_COLOR_FORMAT_PARGB6666,
            gdi_act_layer->offset_x + dst_x,
            gdi_act_layer->offset_y + dst_y,
            resized_width,
            resized_height);
        if (resized_layer_handle == GDI_NULL_HANDLE)
        {
            return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
        }

        /* Step 1: Resize */
        gdi_layer_push_and_set_active(resized_layer_handle);
        gdi_bitblt_resized_with_resizer(
            layer_handle, 
            0,
            0,
            origin_width - 1,
            origin_height - 1,
            0,
            0,
            resized_width - 1,
            resized_height - 1,
            GDI_RESIZER_SW_QUALITY_MEDIUM);
        gdi_layer_pop_and_restore_active();

        /* Step 2: Blending */
        gdi_layer_push_clip();

        do
        {
            gdi_rect_struct dest_clip;
            dest_clip.x1 = dst_x;
            dest_clip.y1 = dst_y;
            dest_clip.x2 = dst_x + resized_width - 1;
            dest_clip.y2 = dst_y + resized_height - 1;
            GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);

            gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);
            
            gdi_get_alpha_blending_source_layer(&blend_src_layer_handle);
            if (blend_src_layer_handle == GDI_NULL_HANDLE)
            {
                gdi_layer_get_active(&act_layer);
                gdi_push_and_set_alpha_blending_source_layer(act_layer);
                gdi_image_bitlit_PARGB6666(resized_layer_handle);
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
            else
            {
                gdi_image_bitlit_PARGB6666(resized_layer_handle);  
            }
        }while(0);
        
        gdi_layer_pop_clip();

        /* Free resized temp layer */
        gdi_image_free_temp_layer(resized_layer_handle);
    }

    return GDI_SUCCEED;
}
#endif /* GDI_LAYER_PARGB6666_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_resize_and_blending_ex
 * DESCRIPTION
 *  resize layer_handle to resized_width & resized_height, and then blend to active layer.
 *  color format of layer_handle only support PARGB6666 and PARGB8888.
 *  the output region is (dst_x, dst_y) to (dst_x+resized_width-1, dst_y+resized_height-1)
 * PARAMETERS
 *  layer_handle    [IN]  resize layer_handle and blend to active layer
 *  dst_x           [IN]  output x on active layer
 *  dst_y           [IN]  output y on active layer
 *  resized_width   [IN]  output width on active layer
 *  resized_height  [IN]  output height on active layer
 *  always_blending [IN]  direct output on 32bits layer if always_blending is false
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_resize_and_blending_ex(
    gdi_handle layer_handle,
    S32 dst_x,
    S32 dst_y,
    S32 resized_width,
    S32 resized_height,
    MMI_BOOL always_blending)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(layer_handle != GDI_NULL_HANDLE);
    GDI_ASSERT(resized_width > 0 && resized_height > 0);
    
    layer = (gdi_layer_struct*)layer_handle;

    ret = GDI_FAILED;
    if (layer->cf == GDI_COLOR_FORMAT_32_PARGB)
    {
        ret = gdi_image_resize_and_blending_ex_PARGB8888(
                layer_handle,
                dst_x, 
                dst_y,
                resized_width,
                resized_height,
                always_blending);
    }
#ifdef GDI_LAYER_PARGB6666_SUPPORT
    else if (layer->cf == GDI_COLOR_FORMAT_PARGB6666)
    {
        ret = gdi_image_resize_and_blending_ex_PARGB6666(
                layer_handle,
                dst_x, 
                dst_y,
                resized_width,
                resized_height,
                always_blending);
    }
#endif

    return ret;
}

