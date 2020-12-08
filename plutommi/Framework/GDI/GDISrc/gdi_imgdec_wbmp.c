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
 *  gdi_imgdec_wbmp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  IMGDEC WBMP decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "drm_gprot.h"

#include "gd_include.h"
#include "gdi_imgdec_bytestream.h"
#include "gdi_imgdec_resizer.h"

#include "setjmp.h"
#include "string.h"
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_imgdec_internal.h"
#include "gdi_datatype.h"

#include "gdi_imgdec_wbmp.h"

#define GDI_WBMP_MAX_WIDTH  (8192)
#define GDI_WBMP_MAX_HEIGHT (8192)

#define GDI_IMGDEC_WBMP_PUT_PIXEL(x, y) \
do \
{ \
    if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, x, y))   \
    { \
        gdi_color pixel = (d & 0x80) ? white : black; \
        gdi_imgdec_resizer_put(&dec->resizer, pixel, TRUE); \
    } \
} while (0)    

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_wbmp_multi_byte_int
 * DESCRIPTION
 *  Reads a VLQ.
 * PARAMETERS
 *  void
 * RETURNS
 *  VLQ value.
 *****************************************************************************/
S32 gdi_imgdec_wbmp_multi_byte_int(gdi_imgdec_bytestream_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value = 0;
    S32 maxlen = 4;
    U8 byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (maxlen--)
    {
        gdi_imgdec_bytestream_read(bs, &byte, 1);
        
        value <<= 7;
        value |= byte & 0x7f;
        if (!(byte & 0x80))
        {
            maxlen = 0;
        }        
    }
    
    return value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_wbmp_init
 * DESCRIPTION
 *  Initializes IMGDEC WBMP.
 * PARAMETERS
 *  dec               [IN]  decoder handle
 *  out_layer         [IN]  output layer
 *  is_aborted        [IN]  aborted flag
 *  flag              [IN]  flag
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_wbmp_init(gdi_imgdec_wbmp_struct *dec, gdi_handle out_layer, BOOL *is_aborted, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dec, 0, sizeof(gdi_imgdec_wbmp_struct));

    dec->out_layer = out_layer;
    dec->is_aborted = is_aborted;    
    dec->flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_wbmp_deinit
 * DESCRIPTION
 *  Deinit IMGDEC WBMP decoder.
 * PARAMETERS
 *  dec       [IN]  image decoder
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_wbmp_deinit(gdi_imgdec_wbmp_struct *dec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* finish resizer */
    gdi_imgdec_resizer_deinit(&dec->resizer);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_internal
 * DESCRIPTION
 *  WBMP core draw function
 * PARAMETERS
 *  dec                  [IN] decoder handle
 *  sx                   [IN] start x
 *  sy                   [IN] start y
 *  resized_width        [IN] resized width
 *  resized_height       [IN] resized height
 * RETURNS
 *  GDI_SUCCEED if successful; otherwise, GDI_FAILED.
 *****************************************************************************/
GDI_RESULT gdi_image_wbmp_draw_internal(gdi_imgdec_wbmp_struct *dec, S32 sx, S32 sy, S32 resized_width, S32 resized_height, U32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
    S32 x, y;
    gdi_color black, white;

    gd_color_from_rgb_func color_from_rgb;
    gdi_layer_struct *out_layer = (gdi_layer_struct*)dec->out_layer;
    S32 resizer_init_ret = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    color_from_rgb = gd_color_from_rgb[out_layer->vcf];

    /* black */
    black = color_from_rgb(0xFF, 0, 0, 0);
    /* white */
    white = color_from_rgb(0xFF, 0xFF, 0xFF, 0xFF);

    /* only support WBMP Type 0 B/W Uncompressed Bitmap */
    if (gdi_imgdec_bytestream_seek(&dec->bs, 2) != GDI_SUCCEED)
    {
        return GDI_FAILED;
    }
    
    width = gdi_imgdec_wbmp_multi_byte_int(&dec->bs);
    height = gdi_imgdec_wbmp_multi_byte_int(&dec->bs);
    if ((width > GDI_WBMP_MAX_WIDTH) || (height > GDI_WBMP_MAX_HEIGHT))
    {
        /* Otherwise, the next loop takes too much time with corrupted header */
        return GDI_FAILED;
    }

    if (dec->flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
    {
        /* WBMP can not enlarge */
        if (aspect_flag & GDI_UTIL_MODE_SHORT_SIDE_FIT)
        {
            aspect_flag &= ~GDI_UTIL_MODE_SHORT_SIDE_FIT;
            aspect_flag |= GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT;
        }
        if (aspect_flag & GDI_UTIL_MODE_LONG_SIDE_FIT)
        {
            aspect_flag &= ~GDI_UTIL_MODE_LONG_SIDE_FIT;
            aspect_flag |= GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT;
        }
        gdi_util_adjust_aspect(
            aspect_flag,
            sx,
            sy,
            resized_width,
            resized_height,
            width,
            height,
            &sx,
            &sy,
            &resized_width,
            &resized_height);
    }
    else
    {
        if (!(resized_width || resized_height) || (resized_width > width) || (resized_height > height))
        {
            resized_width = width;
            resized_height = height;
        }
    }

    if ((resized_width == 0) || (resized_height == 0))
    {
        return GDI_SUCCEED;
    }

    resizer_init_ret = gdi_imgdec_resizer_init(
            &dec->resizer,
            dec->out_layer,    
            width,
            height,
            0,
            0,
            width - 1,
            height - 1,
            sx,
            sy,
            sx + resized_width - 1,
                           sy + resized_height - 1);
    if (resizer_init_ret == 0)
    {
        /* no pixel to output */
        return GDI_SUCCEED;
    }
    else if (resizer_init_ret < 0)
    {
        /* decode limitation, output width too large */
        return GDI_FAILED;
    }

    for (y = 0; y < height; y++)
    {
        if ((GDI_IMGDEC_IS_ABORTED(dec)) || 
            (KAL_TRUE == g_imgdec_timer_timeout_flag) || 
            !gdi_image_progress_callback())
        {
            return GDI_IMAGE_ERR_DECODE_TIME_OUT;
        }
        
        for (x = 0; x < width;)
        {
            U32 d;
            S32 len;
            U8 byte = 0;

            gdi_imgdec_bytestream_read(&dec->bs, &byte, 1);
            d = (U32)byte;

            len = width - x;
            if (len > 8)
            {
                len = 8;
            }

            switch (len)
            {
                case 8:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 7:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 6:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 5:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 4:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 3:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 2:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
                case 1:
                    GDI_IMGDEC_WBMP_PUT_PIXEL(x, y);
                    d <<= 1;
                    x++;
            }
        }
    }
    
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_wbmp_draw_handler
 * DESCRIPTION
 *  IMGDEC WBMP draw handler
 * PARAMETERS
 *  out_layer       [IN]        output layer
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 *  flag            [IN]        flag 
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_imgdec_wbmp_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag)
{
    #if defined(GDI_USING_WBMP)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_imgdec_wbmp_struct dec;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_imgdec_wbmp_init(&dec, out_layer, is_aborted, flag);
    gdi_imgdec_bytestream_init(&dec.bs, data_ptr, img_size);    
    
    ret = gdi_image_wbmp_draw_internal(&dec, x, y, w, h, aspect_flag);
    
    gdi_imgdec_bytestream_deinit(&dec.bs);    
    gdi_imgdec_wbmp_deinit(&dec);

    return ret;
    #else
    return GDI_FAILED;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_wbmp_get_dimension
 * DESCRIPTION
 *  Gets WBMP dimension.
 * PARAMETERS
 *  src          [IN]   image source pointer
 *  size         [IN]   image size
 *  width        [OUT]  width
 *  height       [OUT]  height
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_wbmp_get_dimension(U8 *src, U32 size, S32 *width, S32 *height)
{
    #if defined(GDI_USING_WBMP)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    gdi_imgdec_bytestream_struct bs;
    GDI_RESULT ret = GDI_FAILED;
    kal_uint8 head_bytes[2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = 0;
    *height = 0;

    gdi_imgdec_bytestream_init(&bs, src, size);
    
    do
    {
        ret = gdi_imgdec_bytestream_read(&bs, head_bytes, sizeof(head_bytes));
        if (ret != GDI_SUCCEED ||
            !(head_bytes[0] == 0 && head_bytes[1] == 0))
        {
            break;
        }

        *width = gdi_imgdec_wbmp_multi_byte_int(&bs);
        *height = gdi_imgdec_wbmp_multi_byte_int(&bs);

        if (*width > GDI_WBMP_MAX_WIDTH || *height > GDI_WBMP_MAX_HEIGHT)
        {
            *width = 0;
            *height = 0;
            ret = GDI_FAILED;
            break;
        }

        ret = GDI_SUCCEED;
    } while (0);
    
    gdi_imgdec_bytestream_deinit(&bs);

    return ret;
    #else
    return GDI_FAILED;
    #endif
}



