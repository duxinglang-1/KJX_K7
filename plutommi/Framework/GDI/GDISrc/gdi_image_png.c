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
 *  gdi_image_png.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   HW PNG
 *
 *  Author:
 * -------
 *  Viki Hung (MTK01926)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "kal_public_api.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "kal_public_defs.h"
#include "mmi_frm_event_flag_gprot.h"
#include "kal_release.h"
#include "mmi_frm_event_flag_prot.h"
#include "med_smalloc.h"
#include "string.h"

#include "gdi_internal.h"
#include "gd_primitive.h"
#include "gdi_datatype.h"
    
#include "gdi_imgdec_internal.h"
#include "gd_include.h"
#include "gdi_image.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "drm_gprot.h"
#include "gfx_cache_switch_behavior_enum.h"

#if defined(GDI_USING_PNG)

#include "gdd_include.h"
#include "gdi_include.h"
#include "png_decode_enum.h"
#include "png_decode_api.h"
#include "med_utility.h"
#include "fsal.h"

#if defined(GDI_USING_DITHERING)
#include "iul_spatial_dithering.h"
#endif
#endif /* GDI_USING_PNG */

#include "gdi_imgdec_bytestream.h"

#if defined(GDI_USING_PNG)

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define GDI_PNG_CODEC_WAITING_TIME 6000       /* ms */

/* GDI_HW_PNG_MIN_RSB_BUF_SIZE is recommanded to be at least 1KB, and sequential buffer must be 4-byte aligned */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

static PNG_DECODER_HANDLE g_png_decoder_hdl; /* png handler */
static PNG_STATUS_ENUM  g_png_status;

#if ( !defined (__MTK_TARGET__) )
	#define __align(x)
#endif

static __align(4) void *g_png_int_mem;    /* used to alloc internal ram */
static __align(4) void *g_png_ext_mem;    /* used to alloc external ram */
static __align(4) void *g_png_file_buf;   /* use for png to read file */

static U32 g_png_file_buf_size;

static BOOL *g_gdi_imgdec_png_is_aborted;

typedef struct color_struct 
{
   kal_uint8 red;
   kal_uint8 green;
   kal_uint8 blue;
} color_component;

/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_result
 * DESCRIPTION
 *  convert png driver return value into GDI return value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_RESULT gdi_image_png_get_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PNG_STATUS_ENUM cause = g_png_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case PNG_STATUS_OK:
        case PNG_STATUS_DECODE_COMPLETE:
        case PNG_STATUS_ERROR_NULL_OUTPUT_WINDOW: /* window intersection is null */
            return GDI_SUCCEED;
        
        case PNG_STATUS_ERROR_UNSUPPORTED_FILE_DIMENSION : /* source image size is not supported */
            return GDI_IMAGE_ERR_IMAGE_TOO_LARGE;

        case PNG_STATUS_INVALID_SOURCE_FILE: /* source image header is illegal */
            return GDI_IMAGE_ERR_INVALID_IMG_TYPE;

        case PNG_STATUS_UNSUPPORTED_FEATURE: /* setting hw with invalid parameters */
        case PNG_STATUS_INVALID_OPERATION:     /* function is invoked at illegal time */
        case PNG_STATUS_ERROR_DECODE_FAILED:             /* hw decode error */
        case PNG_STATUS_IN_DECODING:            /* hw is decoding */
        case PNG_STATUS_DECODE_TIMEOUT:         /* initialization error */
        case PNG_STATUS_DECODE_INCOMPLETE:      /* a imagewith partial error */
            return GDI_FAILED;

        case GDI_IMAGE_ERR_DECODE_TIME_OUT:
            return GDI_IMAGE_ERR_DECODE_TIME_OUT;
            
        default:
            ASSERT(0);
            return GDI_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwpng_send_ilm_to_gdd
 * DESCRIPTION
 *  send ilm to gdd
 * PARAMETERS
 *  ret     [IN]    return value from png driver
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_hwpng_send_ilm_to_gdd(S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = ret;
    gdd_send_img_codec_ind(&data,sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwpng_timeout_handler
 * DESCRIPTION
 *  timeout handler of gdd
 * PARAMETERS
 *  arg     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_hwpng_timeout_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pngDecReset(g_png_decoder_hdl);
    gdi_image_hwpng_send_ilm_to_gdd((S32)GDI_IMAGE_ERR_DECODE_TIME_OUT);
    GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_PNG_HW_TIMEOUT);//[gdi_image_hwpng_timeout_handler]:Time out
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwpng_callback
 * DESCRIPTION
 *  message handler of png driver
 * PARAMETERS
 *  ret     [IN]    return value from png driver
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_hwpng_callback(PNG_STATUS_ENUM ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_hwpng_send_ilm_to_gdd((S32)ret);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_swpng_progress_callback
 * DESCRIPTION
 *  IMGDEC image progress callback
 * PARAMETERS
 *  void
 * RETURNS
 *  0 if aborted; otherwise, 1.
 *****************************************************************************/
static S32 gdi_imgdec_swpng_progress_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gdi_imgdec_png_is_aborted && *g_gdi_imgdec_png_is_aborted)
    {
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_reset
 * DESCRIPTION
 *  reset png driver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_png_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_png_ext_mem = NULL;
    g_png_int_mem = NULL;
    g_png_file_buf = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_cf_to_hw
 * DESCRIPTION
 *  transform the color format from gdi_color_format to PNG_COLOR_FORMAT_ENUM
 * PARAMETERS
 *  cf      [IN]    the gdi color format to be transform
 *  png_cf  [OUT]   the result png color format 
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_png_cf_to_hw(gdi_color_format cf, PNG_DECODE_COLOR_FORMAT_ENUM *png_cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            *png_cf = PNG_FORMAT_RGB565;
            break;

        case GDI_COLOR_FORMAT_24:
            *png_cf = PNG_FORMAT_RGB888;
            break;

        case GDI_COLOR_FORMAT_32:
            *png_cf = PNG_FORMAT_ARGB8888;
            break;

        case GDI_COLOR_FORMAT_32_PARGB:
            *png_cf = PNG_FORMAT_PARGB8888;
            break;

        case GDI_COLOR_FORMAT_PARGB6666:
            *png_cf = PNG_FORMAT_PARGB6666;
            break;
        default:
            png_cf = NULL;
            return GDI_FAILED;  /* hardware png decoder didn't support this color format */
    }
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwpng_msg_handler
 * DESCRIPTION
 *  msg handler of gdd, handle hwpng msg
 * PARAMETERS
 *  ilm         [IN]        the msg from gdi
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_hwpng_msg_handler(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *interrupt_value;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    interrupt_value = (S32*)&(((gdd_img_codec_event_ind_struct*)ilm->local_para_ptr)->header);
    ASSERT((0 <= *interrupt_value && PNG_STATUS_ENUM_END_CODE >= *interrupt_value) ||
           (GDI_IMAGE_ERR_DECODE_TIME_OUT == *interrupt_value));


    GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_PNG_HW_MSG,//[gdi_image_hwpng_msg_handler]: g_png_status:%d interrupt_value:%d
                    g_png_status, *interrupt_value);
    if (g_gdi_imgdec_png_is_aborted && *g_gdi_imgdec_png_is_aborted)
    {   /* IMGDEC */
        *interrupt_value = PNG_STATUS_ERROR_DECODE_FAILED;
    }
    else if (!gdi_image_progress_callback())
    {   /* GDI NB */
        *interrupt_value = PNG_STATUS_ERROR_DECODE_FAILED;
    }
    
    if (PNG_STATUS_DECODE_INCOMPLETE == *interrupt_value) 
    {
        g_png_status = pngDecDecodeResume(g_png_decoder_hdl);
        if (PNG_STATUS_OK != g_png_status)
        {
            gdi_image_hwpng_send_ilm_to_gdd((S32)g_png_status);
        }
    }
    else 
    {
        /* hw decode fail */
        pngDecReset(g_png_decoder_hdl);
        gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);

        /* finalize */
        g_png_status = pngDecReleaseDecoder(g_png_decoder_hdl);
        g_png_decoder_hdl = NULL;
        GDI_ASSERT(g_png_status != PNG_STATUS_INVALID_OPERATION);

        switch (*interrupt_value)
        {
            case PNG_STATUS_OK:
            case PNG_STATUS_ERROR_UNSUPPORTED_FILE_DIMENSION:    /* source image size is not supported */
            case PNG_STATUS_INVALID_SOURCE_FILE:           /* source image header is illegal */
            case PNG_STATUS_ERROR_INVALID_BUFFER:        /* setting hw with invalid parameters */
            case PNG_STATUS_ERROR_NULL_OUTPUT_WINDOW:            /* window intersection is null */
            case PNG_STATUS_INVALID_OPERATION:     /* function is invoked at illegal time */
            case PNG_STATUS_ERROR_DECODE_FAILED:             /* hw decode error */
            case PNG_STATUS_IN_DECODING:            /* hw is decoding */
            case PNG_STATUS_DECODE_TIMEOUT:         /* initialization error */
                g_png_status = (PNG_STATUS_ENUM)(*interrupt_value);
                break;
                
            case GDI_IMAGE_ERR_DECODE_TIME_OUT:
                g_png_status = PNG_STATUS_DECODE_TIMEOUT;
                break;
                
            default:
                g_png_status = PNG_STATUS_ERROR_DECODE_FAILED;
                ASSERT(0);
                break;            
        }
        GDD_SET_EVENT(GDD_EVENT_WAIT_DECODING);
     }
}

#if defined(GDI_USING_DITHERING)
static GDI_RESULT gdi_imgdec_hwpng_create_dithering_layer(
                    gdi_layer_struct *dither_layer,
                    S32 x,
                    S32 y,
                    S32 width,
                    S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bytes_per_pixel;
    U32 buf_size;
    U8 *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dither_layer != NULL);
    GDI_ASSERT(width > 0 && height > 0);

    bytes_per_pixel = gdi_bits_per_pixel(GDI_COLOR_FORMAT_24) >> 3;
    buf_size = width * height * bytes_per_pixel;
    
    buf = (U8 *)gdi_alloc_ext_mem_framebuffer(buf_size);
    if (buf == NULL)
    {
        /* not enough memory */
        return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
    }

    memset(dither_layer, 0, sizeof(gdi_layer_struct));

    dither_layer->width = width;
    dither_layer->height = height;
    dither_layer->cf = GDI_COLOR_FORMAT_24;
    dither_layer->vcf = GDI_COLOR_FORMAT_24;
    dither_layer->buf_ptr = buf;
    dither_layer->layer_size = buf_size;
    dither_layer->clipx1 = 0;
    dither_layer->clipy1 = 0;
    dither_layer->clipx2 = width - 1;
    dither_layer->clipy2 = height - 1;
    dither_layer->offset_x = x;
    dither_layer->offset_y = y;
    dither_layer->bits_per_pixel = (U8)gdi_bits_per_pixel(GDI_COLOR_FORMAT_24);
    
    return GDI_SUCCEED;
}
#endif


static void gdi_imgdec_png_copy_source_layer(gdi_layer_struct *dst_layer, gdi_layer_struct *src_layer, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_x1, layer_y1, layer_x2, layer_y2;
    S32 src_pitch, dst_pitch;
    S32 src_bpp, dst_bpp; /* byte per pixel */
    PU8 src_ptr, dst_ptr;

    gdi_img_buf_struct dst_buf, src_buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clip by dst layer */
    layer_x1 = dst_layer->offset_x;
    layer_y1 = dst_layer->offset_y;
    layer_x2 = layer_x1 + dst_layer->width - 1;
    layer_y2 = layer_y1 + dst_layer->height - 1;        
    GDI_CLIP_TWO_RECT(clip_x1, clip_y1, clip_x2, clip_y2, layer_x1, layer_y1, layer_x2, layer_y2, return);

    /* clip by src layer */
    layer_x1 = src_layer->offset_x;
    layer_y1 = src_layer->offset_y;
    layer_x2 = layer_x1 + src_layer->width - 1;
    layer_y2 = layer_y1 + src_layer->height - 1;    
    GDI_CLIP_TWO_RECT(clip_x1, clip_y1, clip_x2, clip_y2, layer_x1, layer_y1, layer_x2, layer_y2, return);

    src_bpp = src_layer->bits_per_pixel / 8;
    src_pitch = src_layer->width * src_bpp;
    src_ptr = src_layer->buf_ptr + (clip_y1 - src_layer->offset_y) * src_pitch + (clip_x1 - src_layer->offset_x) * src_bpp;
    
    dst_bpp = dst_layer->bits_per_pixel / 8;
    dst_pitch = dst_layer->width * dst_bpp;
    dst_ptr = dst_layer->buf_ptr + (clip_y1 - dst_layer->offset_y) * src_pitch + (clip_x1 - dst_layer->offset_x) * dst_bpp;

    dst_buf.pitch_bytes = dst_pitch;
    dst_buf.color_format = gdi_img_buf_trans_color_format(dst_layer->cf);
    dst_buf.ptr = dst_ptr;

    src_buf.pitch_bytes = src_pitch;
    src_buf.color_format = gdi_img_buf_trans_color_format(src_layer->cf);;
    src_buf.ptr = src_ptr;

    gdi_img_buf_copy(
        &dst_buf, 
        &src_buf,
        clip_x2 - clip_x1 + 1,
        clip_y2 - clip_y1 + 1);
}


#if defined(GDI_USING_DITHERING)
static GDI_RESULT gdi_imgdec_png_free_dithering_layer(gdi_layer_struct *dither_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buf = dither_layer->buf_ptr;
    if (buf != NULL)
    {
        gdi_free_ext_mem((void**)&buf);
    }
    return GDI_SUCCEED;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_hwpng_draw_internal
 * DESCRIPTION
 *  draw png image
 * PARAMETERS
 *  ox                  [IN]    the left-up position of the image to be drawn
 *  oy                  [IN]    the left-up position of the image to be drawn
 *  resized_width       [IN]    the width of image to be drawn
 *  resized_height      [IN]    the height of image to be drawn
 *  src                 [IN]    image file name or memory pointer of image data
 *  size                [IN]    the size of src, if src is file name, size=0
 *  is_file             [IN]    src is file name or memory pointer
 *  is_resized          [IN]    the image will be resized or not
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_imgdec_png_draw_internal(
            gdi_handle output_layer_handle,
            gdi_handle src_layer_handle,
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL *is_aborted,
            U32 flag,
            S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STFSAL png_src;
    kal_int32 ret_value = GDI_SUCCEED;
    PNG_DECODE_COLOR_FORMAT_ENUM canvas_color_format;
    MMI_BOOL intmem_from_ext = MMI_FALSE;
    gdi_layer_struct *out_layer, *src_layer;
    BOOL is_src_key_enable;
    gdi_color src_key_value;

    PNG_DECODER_TYPE_ENUM decoder_type;

#if defined(GDI_USING_DITHERING)
    kal_bool enable_dithering = KAL_FALSE;
    gdi_rect_struct dither_dest_rect = {0, 0, 0, 0};
    gdi_layer_struct dither_layer_struct;
    gdi_handle dither_layer = GDI_NULL_HANDLE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_IMGDEC_HW_LOCK();
    GDI_TRACE(GDI_TRC_DECODE, GDI_PNG_ENTER,//[gdi_imgdec_png_draw_internal]: Enter - out_layer:%x src_layer:%x x:%d y:%d w:%d h:%d src:%x is_file:%d
        output_layer_handle, src_layer_handle, ox, oy, resized_width, resized_height, src, is_file);

    src_layer = (gdi_layer_struct*)src_layer_handle;
    out_layer = (gdi_layer_struct*)output_layer_handle;

    is_src_key_enable = gdi_layer_info[out_layer->id].source_key_enable;
    src_key_value = gdi_layer_info[out_layer->id].source_key;
        
    g_gdi_imgdec_png_is_aborted = is_aborted;

    do
    {
        /* initialization */
        gdi_image_png_reset();

        /* Get PNG decoder */
        decoder_type = PNG_DECODER_TYPE_SW;
        g_png_status = pngDecGetDecoder(decoder_type, &g_png_decoder_hdl);
        if (PNG_STATUS_OK != g_png_status)
        {
            decoder_type = PNG_DECODER_TYPE_HW;
            g_png_status = pngDecGetDecoder(decoder_type, &g_png_decoder_hdl);
        }
        if (PNG_STATUS_OK != g_png_status)
        {
            ret_value = GDI_IMAGE_ERR_NO_DECODER;
            break;
        }

        if (flag & GDI_IMAGE_CODEC_FLAG_DISABLE_CACHE_SWITCH)
        {
            pngDecSetDstBufferSwitchBehavior(g_png_decoder_hdl, GFX_CACHE_SWITCH_BEHAVIOR_NOT_SWITCH);
        }                    

        /* The following code will set buffer and begin decode */
        do
        {
            /* Set file buffer */
            {
                kal_uint32 file_buffer_size_min = 0;
                kal_uint32 file_buffer_size_best = 0;
                g_png_status = pngDecQueryFileBufferSize(g_png_decoder_hdl, &file_buffer_size_best, &file_buffer_size_min);
                if (PNG_STATUS_OK != g_png_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }

                /* If png has to use flatten, png can't use gdi_work_buffer to read source image. 
                   Because flatten also use gdi_work_buffer to solve buffer 4-byte alignment problem on MT6235&MT6238.
                   If they both use gdi_work_buffer, png src image data will be over written, then decoder decode fail. */
                {
                    g_png_file_buf_size = file_buffer_size_best;
                    if (NULL == g_png_file_buf)
                    {
                        while(1)
                        {
                            if (PNG_DECODER_TYPE_HW == decoder_type)
                            {
                                g_png_file_buf = (void *)gdi_alloc_ext_mem(g_png_file_buf_size);
                            }
                            else /* For SW, recommend using external cacheable memory */
                            {
                                g_png_file_buf = (void *)gdi_alloc_ext_mem_cacheable(g_png_file_buf_size);
                            }

                            if ((g_png_file_buf != NULL) || (file_buffer_size_best == file_buffer_size_min))
                            {
                                break;
                            } 
                            if ((g_png_file_buf_size == file_buffer_size_min) && (g_png_file_buf == NULL))
                            {
                                break;
                            }
                            g_png_file_buf_size /= 2;
                            if (g_png_file_buf_size < file_buffer_size_min)
                            {
                                g_png_file_buf_size = file_buffer_size_min;
                            }                                
                        }
                           
                        if ((NULL == g_png_file_buf) && (file_buffer_size_best != 0))
                        {                          
                            ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                            break;
                        }
                    } 

                    if (!g_png_file_buf)
                    {
                        ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                        g_png_status = PNG_STATUS_OK;
                        break;
                    }
                }
            }

            /* Set Working Buffer */
            {
                kal_uint32 internal_mem_size = 0;
                kal_uint32 external_mem_size = 0;

                g_png_status = pngDecQueryWorkingBufferSize(g_png_decoder_hdl, &internal_mem_size, &external_mem_size);

                if (0 != internal_mem_size)
                {    
                    g_png_int_mem = (void *)med_alloc_int_mem(internal_mem_size);
                    if (!g_png_int_mem)
                    {
                        /* if internal mem is not enough, alloc from ext mem. */
                        g_png_int_mem = (void *)gdi_alloc_ext_mem(internal_mem_size);
                        if (!g_png_int_mem)
                        {
                            ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                            g_png_status = PNG_STATUS_OK;
                            break;
                        }
                        intmem_from_ext = MMI_TRUE;
                    }
                }

                if (0 != external_mem_size)
                {    
                    if (PNG_DECODER_TYPE_HW == decoder_type)
                    {                    
                         g_png_ext_mem = (void *)gdi_alloc_ext_mem(external_mem_size);
                    }
                    else
                    {
                         g_png_ext_mem = (void *) gdi_alloc_ext_mem_cacheable(external_mem_size);    
                    }
                    
                    if (!g_png_ext_mem)
                    {
                        ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                        g_png_status = PNG_STATUS_OK;
                        break;
                    }  
                }

                memset(g_png_ext_mem, 0, external_mem_size);
                memset(g_png_int_mem, 0, internal_mem_size);           
                   
                g_png_status = pngDecSetWorkingBuffer(g_png_decoder_hdl, (kal_uint32 *)g_png_int_mem, (kal_uint32 *)g_png_ext_mem);
                if (PNG_STATUS_OK != g_png_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }
        
            /* Open file */
            {
                if (is_file) 
                { 
                    ret_value = FSAL_Open(&png_src, src, FSAL_READ);
                } 
                else
                {
                    FSAL_Direct_SetRamFileSize(&png_src, size);         
                    ret_value = FSAL_Open(&png_src, (void *)src, FSAL_ROMFILE);
                }
                /* Set source file */
                if (FSAL_OK != ret_value) 
                {
                    ret_value = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
                    break;
                }
                else
                {
                    g_png_status = pngDecSetSourceFile(g_png_decoder_hdl, &png_src, g_png_file_buf, g_png_file_buf_size);
                    if (PNG_STATUS_OK != g_png_status)
                    {
                        ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                        break;
                    }
                }
            }

            /* Adjust the output x,y,w,h */
            {
                kal_int32 src_w, src_h;
                pngDecGetImgDimension(g_png_decoder_hdl, &src_w, &src_h);
                if ((resized_width == 0) || (resized_height == 0))
                {
                    resized_width = src_w;
                    resized_height = src_h;
                }
                else if (flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
                {
                    /* PNG can not enlarge */
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
                        ox,
                        oy,
                        resized_width,
                        resized_height,
                        src_w,
                        src_h,
                        &ox,
                        &oy,
                        &resized_width,
                        &resized_height);
                }
            }

            /* Create dithering layer */
            {
            #if defined(GDI_USING_DITHERING)
                g_png_status = pngDecQueryDitheringSupport(g_png_decoder_hdl);
                if (PNG_STATUS_OK == g_png_status)
                {
                    g_png_status = pngDecEnableDithering(g_png_decoder_hdl, KAL_TRUE);
                }
                /* HW decoder can use GDI dithering */
                if ((PNG_STATUS_OK != g_png_status) &&
                    (PNG_DECODER_TYPE_HW == decoder_type))
                {
                    if (is_file &&
                        ((out_layer->cf == GDI_COLOR_FORMAT_16) ||
                        (out_layer->cf == GDI_COLOR_FORMAT_24)))
                    {
                        /* Merge the dithering clip. */
                        dither_dest_rect.x1 = ox;
                        dither_dest_rect.y1 = oy;
                        dither_dest_rect.x2 = ox + resized_width- 1;
                        dither_dest_rect.y2 = oy + resized_height - 1;
                        do
                        {
                            GDI_CLIP_TWO_RECT(
                                dither_dest_rect.x1, 
                                dither_dest_rect.y1, 
                                dither_dest_rect.x2, 
                                dither_dest_rect.y2,
                                out_layer->clipx1,
                                out_layer->clipy1,
                                out_layer->clipx2,
                                out_layer->clipy2,
                                break);
                            enable_dithering = KAL_TRUE;
                        } while(0);
                    }

                    /* create a RGB888 layer for dithering if destination is RGB565 */
                    if (enable_dithering && (out_layer->cf == GDI_COLOR_FORMAT_16))
                    {
                        gdi_result dither_ret = GDI_FAILED;
                        do
                        {
                            dither_ret = gdi_imgdec_hwpng_create_dithering_layer(
                                             &dither_layer_struct,
                                             out_layer->offset_x + dither_dest_rect.x1,
                                             out_layer->offset_y + dither_dest_rect.y1,
                                             dither_dest_rect.x2 - dither_dest_rect.x1 + 1, 
                                             dither_dest_rect.y2 - dither_dest_rect.y1 + 1);

                            /* if create dither_layer fail, do decoding without dithering */
                            if (dither_ret != GDI_SUCCEED)
                            {
                                dither_layer = GDI_NULL_HANDLE;
                                enable_dithering = KAL_FALSE;
                                break;
                            }
                            dither_layer = (gdi_handle)(&dither_layer_struct);

                            /* replace output layer to dither_layer */
                            ox -= dither_dest_rect.x1;
                            oy -= dither_dest_rect.y1;
                            out_layer = (gdi_layer_struct*)dither_layer;
                        } while(0);
                    }
                }
            #endif /* GDI_USING_DITHERING */
            }  

            /* Set Canvas Window */
            {
                ret_value = gdi_image_png_cf_to_hw(out_layer->vcf, &canvas_color_format);
                if (GDI_SUCCEED != ret_value)
                {
                    ret_value = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                    g_png_status = PNG_STATUS_OK;
                    break;
                }
                g_png_status = pngDecSetCanvas(
                                   g_png_decoder_hdl,
                                   out_layer->buf_ptr,
                                   out_layer->width,
                                   out_layer->height,
                                   canvas_color_format);
                if (PNG_STATUS_OK != g_png_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set Output Window */
            {
                g_png_status = pngDecSetOutputWindow(g_png_decoder_hdl, ox, oy, resized_width, resized_height);
            }
        
            /* Set clip Window */
            g_png_status = pngDecSetClipWindow(
                               g_png_decoder_hdl,
                               out_layer->clipx1,
                               out_layer->clipy1,
                               out_layer->clipx2 - out_layer->clipx1 + 1,
                               out_layer->clipy2 - out_layer->clipy1 + 1);

            /* set source layer and blending mode */
            {
                PNG_DECODE_COLOR_FORMAT_ENUM blend_color_format;
                PNG_BLEND_MODE_ENUM blending_mode = PNG_BLEND_NONE;
                gdi_rect_struct dest_rect;
                /* Todo: need ask Robin what is the use of this width and height */
                U8 *src_layer_start_ptr = NULL;
                U32 blend_buffer_width = 0, blend_buffer_height = 0;

                if (PNG_DECODER_TYPE_SW == decoder_type)
                {
                    PNG_DECODE_COLOR_FORMAT_ENUM out_color_format;

                    ret_value = gdi_image_png_cf_to_hw(out_layer->vcf, &out_color_format);
                    if (GDI_SUCCEED != ret_value)
                    {
                        ret_value = GDI_FAILED;
                        g_png_status = PNG_STATUS_OK;
                        break;
                    }

                    if ((GDI_ERROR_HANDLE == src_layer_handle) && 
                        ((out_color_format != PNG_FORMAT_ARGB8888) && 
                         (out_color_format != PNG_FORMAT_PARGB8888) &&
                         (out_color_format != PNG_FORMAT_PARGB6666)))
                    {
                        //ret_value = GDI_LAYER_ERR_NO_VALID_LAYER_HANDLE;
                        //g_png_status = PNG_STATUS_OK;
                        //break;
                        blending_mode = PNG_BLEND_NONE;
                        blend_color_format = out_color_format;
                    }
                    else if ((out_color_format == PNG_FORMAT_ARGB8888) ||
                             (out_color_format == PNG_FORMAT_PARGB8888) ||
                             (out_color_format == PNG_FORMAT_PARGB6666))
                    {
                        blending_mode = PNG_BLEND_NONE;
                        blend_color_format = out_color_format;
                    }
                    else
                    {
                        if ((src_layer->width != out_layer->width) ||  /* decoder limitation */
                             (src_layer->cf != out_layer->cf) ||
                             ((src_layer != out_layer) && (flag & GDI_IMAGE_CODEC_FLAG_BLEND_2_LAYERS)))
                        {
                            /* blend 2 layers */
                            gdi_layer_blend_2_layers(src_layer_handle, ox, oy, ox + resized_width - 1, oy + resized_height - 1);
        
                            src_layer = out_layer;
                            src_layer_start_ptr = src_layer->buf_ptr;
                            blend_buffer_width = src_layer->width;
                            blend_buffer_height = src_layer->height;
                        }
                        else
                        {
                            S32 src_bpp, ofs_x, ofs_y;
                            ofs_x = out_layer->offset_x - src_layer->offset_x;
                            ofs_y = out_layer->offset_y - src_layer->offset_y;
    
                            src_bpp = src_layer->bits_per_pixel /8;
                            src_layer_start_ptr = src_layer->buf_ptr + 
                                                  (src_layer->width * src_bpp * ofs_y) + 
                                                  (ofs_x * src_bpp);
                            blend_buffer_width = src_layer->width;
                            blend_buffer_height = src_layer->height;
                        }

                        ret_value = gdi_image_png_cf_to_hw(src_layer->vcf, &blend_color_format);
                        if (GDI_SUCCEED != ret_value)
                        {
                            ret_value = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                            g_png_status = PNG_STATUS_OK;
                            break;
                        }
                        blending_mode = PNG_BLEND_FILE_ALPHA;
                    }
                }
                else if (PNG_DECODER_TYPE_HW == decoder_type)
                {
                    if ((GDI_NULL_HANDLE == src_layer_handle) || 
                        (pngDecIsFileAlphaExist(g_png_decoder_hdl) != 1))
                    {
                        blending_mode = PNG_BLEND_NONE;
                        blend_color_format = PNG_FORMAT_ARGB8888;
                        if (out_layer->cf == GDI_COLOR_FORMAT_PARGB6666)
                        {
                            blend_color_format = PNG_FORMAT_PARGB6666;
                        }
                    }
                    else
                    {
                        if ((src_layer != out_layer) && 
                            (flag & GDI_IMAGE_CODEC_FLAG_BLEND_2_LAYERS))
                        {
                            /* blend 2 layers */
                            gdi_layer_blend_2_layers(src_layer_handle, ox, oy, ox + resized_width - 1, oy + resized_height - 1);
    
                            src_layer = out_layer;
                            src_layer_start_ptr = src_layer->buf_ptr;
                            blend_buffer_width = src_layer->width;
                            blend_buffer_height = src_layer->height;
                        }
                        else if ((src_layer->width != out_layer->width) ||  /* decoder limitation */
                                ((pngDecIsFileTransparencyExist(g_png_decoder_hdl) == 1) && (src_layer != out_layer)))
                             /* Hw png drop transparent point when file transparency exist, so copy src buffer data to dst data. */
                        {
                            /* copy src layer to act layer */
                            if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
                            {
                                /* IMAGE DITHERING CASE ONLY */
                                gdi_imgdec_png_copy_source_layer(out_layer, src_layer, out_layer->offset_x, out_layer->offset_y, out_layer->offset_x + resized_width - 1,  out_layer->offset_y + resized_height - 1);
                            }
                            else if (gdi_layer_flatten_is_ready() == KAL_TRUE)
                            {
                                dest_rect.x1 = ox;
                                dest_rect.y1 = oy;
                                dest_rect.x2 = ox + resized_width - 1;
                                dest_rect.y2 = oy + resized_height - 1;
                                do
                                {
                                    GDI_CLIP_TWO_RECT(
                                        dest_rect.x1, 
                                        dest_rect.y1, 
                                        dest_rect.x2, 
                                        dest_rect.y2,
                                        out_layer->clipx1,
                                        out_layer->clipy1,
                                        out_layer->clipx2,
                                        out_layer->clipy2,
                                        break);
                                } while(0);
                                GDI_LCD_LOCK_MUTEX;
                                gdi_layer_flatten_ext_internal(
                                    src_layer_handle, 
                                    0, 
                                    0, 
                                    0,
                                    0,
                                    0,
                                    dest_rect.x1,
                                    dest_rect.y1,
                                    dest_rect.x2,
                                    dest_rect.y2,
                                    out_layer->buf_ptr,
                                    out_layer->layer_size,
                                    out_layer->width,
                                    out_layer->height,
                                    out_layer->offset_x,
                                    out_layer->offset_y,
                                    out_layer->bits_per_pixel,
                                    out_layer->vcf,
                                    out_layer->rotate_value,
                                    0,
                                    NULL,
                                    NULL);
                                    GDI_LCD_UNLOCK_MUTEX;
                            }
                            else
                            {
                                S32 ofx = out_layer->offset_x - src_layer->offset_x;
                                S32 ofy = out_layer->offset_y - src_layer->offset_y;
                                
                                gdi_bitblt(
                                    src_layer_handle,
                                    ox + ofx, 
                                    oy + ofy, 
                                    ox + resized_width - 1 + ofx, 
                                    oy + resized_height - 1 + ofy, 
                                    ox, 
                                    oy);
                            }
                            src_layer = out_layer;
                            src_layer_start_ptr = src_layer->buf_ptr;
                            blend_buffer_width = src_layer->width;
                            blend_buffer_height = src_layer->height;
                        }
                        else
                        {   
                            S32 src_bpp, ofs_x, ofs_y;
                            ofs_x = out_layer->offset_x - src_layer->offset_x;
                            ofs_y = out_layer->offset_y - src_layer->offset_y;
        
                            src_bpp = src_layer->bits_per_pixel /8;
                            src_layer_start_ptr = src_layer->buf_ptr + 
                                                  (src_layer->width * src_bpp * ofs_y) + 
                                                  (ofs_x * src_bpp);
                            blend_buffer_width = src_layer->width;
                            blend_buffer_height = src_layer->height;
                        }

                        ret_value = gdi_image_png_cf_to_hw(src_layer->vcf, &blend_color_format);
                        if (GDI_SUCCEED != ret_value)
                        {
                            ret_value = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                            g_png_status = PNG_STATUS_OK;
                            break;
                        }
                        blending_mode = PNG_BLEND_FILE_ALPHA;
                    }
                }

                g_png_status = pngDecSetAlphaBlending(
                                   g_png_decoder_hdl,
                                   src_layer_start_ptr,
                                   blend_buffer_width,
                                   blend_buffer_height,
                                   blend_color_format,
                                   blending_mode);
            }

            /* set replace color to replace the source key of acitve layer to another similar color */
            do
            {
                color_component replaced_color, replace_as_this_color;
                U32 cA, cR, cG, cB;
                
                if ((!is_src_key_enable)
                #if defined(GDI_USING_DITHERING)
                    || (enable_dithering)
                #endif
                )
                {
                    break;
                }
                
                if (canvas_color_format == PNG_FORMAT_RGB565)
                {
                    replaced_color.red = (src_key_value & 0xf800) >> 11;
                    replaced_color.green = (src_key_value & 0x07e0) >> 5;
                    replaced_color.blue = (src_key_value & 0x001f);
                    replace_as_this_color.red = (src_key_value & 0xf800) >> 11;
                    replace_as_this_color.green = (src_key_value & 0x07e0) >> 5;
                    replace_as_this_color.blue = (src_key_value & 0x001f);
                }
                else
                {
                    gd_color_to_rgb[out_layer->cf](&cA, &cR, &cG, &cB, src_key_value);
                    replaced_color.red = cR;
                    replaced_color.green = cG;
                    replaced_color.blue = cB;
                    replace_as_this_color.red = cR;
                    replace_as_this_color.green = cG;
                    replace_as_this_color.blue = cB;
                }
                replace_as_this_color.blue = replace_as_this_color.blue ^ 1;
                g_png_status = pngDecSetColorReplacement(
                                   g_png_decoder_hdl,
                                   KAL_TRUE,
                                   replaced_color.red,
                                   replaced_color.green,
                                   replaced_color.blue,
                                   replace_as_this_color.red,
                                   replace_as_this_color.green,
                                   replace_as_this_color.blue);
            } while (0);

            pngDecSetTimeoutValue(g_png_decoder_hdl, GDI_PNG_CODEC_WAITING_TIME / 10); /* 600 msec */

            /* Set Hook interrupt call back function */
            {
                if (PNG_DECODER_TYPE_HW == decoder_type)
                { 
                    gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, gdi_image_hwpng_msg_handler);
                    g_png_status = pngDecHookCallback(g_png_decoder_hdl, &gdi_image_hwpng_callback);   
                }
                else if (PNG_DECODER_TYPE_SW == decoder_type) 
                {
                    if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
                    {
                        g_png_status = pngDecSetCheckAbortFunction(g_png_decoder_hdl, gdi_imgdec_swpng_progress_callback);
                    }
                    else
                    {
                        g_png_status = pngDecSetCheckAbortFunction(g_png_decoder_hdl, gdi_image_progress_callback);
                    }
                }
                if (PNG_STATUS_OK != g_png_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            if (PNG_DECODER_TYPE_HW == decoder_type)
            {
                /* start gdd */
                gdd_start_timer(
                    GDD_TIMER_IMAGE_CODEC_TIMEOUT,
                    GDI_PNG_CODEC_WAITING_TIME,
                    gdi_image_hwpng_timeout_handler,
                    0);
            }
            /* TRIGGER DECODE */
            g_png_status = pngDecDecodeStart(g_png_decoder_hdl);
            GDI_TRACE(GDI_TRC_DECODE, GDI_PNG_START,//[gdi_imgdec_png_draw_internal]: Start - decoder:%d status:%d
                    decoder_type, g_png_status);
            if (PNG_DECODER_TYPE_HW == decoder_type)
            {
                if (PNG_STATUS_OK == g_png_status)
                {
                    GDD_WAIT_EVENT(GDD_EVENT_WAIT_DECODING); /* wait gdd finish drawing and set the event */
                }
                else
                {
                    PNG_STATUS_ENUM status;
                    pngDecReset(g_png_decoder_hdl);
                    gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
                    gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);     
                    status = pngDecReleaseDecoder(g_png_decoder_hdl);
                    g_png_decoder_hdl = NULL;
                    GDI_ASSERT(status != PNG_STATUS_INVALID_OPERATION);           
                }
            }
            else if (PNG_DECODER_TYPE_SW == decoder_type)
            {
                /* finalize */
                PNG_STATUS_ENUM status;
                status = pngDecReleaseDecoder(g_png_decoder_hdl);
                g_png_decoder_hdl = NULL;
                GDI_ASSERT(status != PNG_STATUS_INVALID_OPERATION);
            }

            /* If layer is PARGB, convert the output region from ARGB to PARGB. */
            if (out_layer->vcf == GDI_COLOR_FORMAT_32_PARGB)
            {
                U32 ox1, oy1, ox2, oy2;
    
                ox1 = ox;
                oy1 = oy;
                ox2 = ox + resized_width - 1;
                oy2 = oy + resized_height - 1;
    
                do
                {
                    GDI_IMGDEC_LAYER_CLIP_RECT_TEST(out_layer, ox1, oy1, ox2, oy2, break);
    
                    gdi_util_convert_ARGB8888_to_PARGB8888_buf(
                        out_layer->buf_ptr,
                        out_layer->width,
                        ox1, 
                        oy1,
                        ox2 - ox1 + 1,
                        oy2 - oy1 + 1);
                } while(0);
            }

        } while(0);

        /* dithering */
    #if defined(GDI_USING_DITHERING)
        if (enable_dithering)
        {
            U8 *dithering_ptr = NULL;

            if (((gdi_layer_struct*)output_layer_handle)->cf == GDI_COLOR_FORMAT_16)
            {
                unsigned short *src_key = (unsigned short*)(&src_key_value);

                out_layer = (gdi_layer_struct*)output_layer_handle; 
                dithering_ptr = out_layer->buf_ptr;
                dithering_ptr += ((dither_dest_rect.y1 * out_layer->width) + dither_dest_rect.x1) * (out_layer->bits_per_pixel >> 3);
                /* dithering from dither_layer to output layer */
                if (!is_src_key_enable)
                {
                    iul_sd_bgr888_to_rgb565(
                        ((gdi_layer_struct*)dither_layer)->buf_ptr,
                        (unsigned short*)dithering_ptr,
                        dither_dest_rect.x2 - dither_dest_rect.x1 + 1, 
                        dither_dest_rect.y2 - dither_dest_rect.y1 + 1, 
                        out_layer->width);
                }
                else
                {
                    iul_sd_bgr888_to_rgb565_srckey(
                        ((gdi_layer_struct*)dither_layer)->buf_ptr,
                        (unsigned short*)dithering_ptr,
                        dither_dest_rect.x2 - dither_dest_rect.x1 + 1, 
                        dither_dest_rect.y2 - dither_dest_rect.y1 + 1, 
                        out_layer->width,
                        src_key);
                }
                gdi_imgdec_png_free_dithering_layer(&dither_layer_struct);
            }
            else if (((gdi_layer_struct*)output_layer_handle)->cf == GDI_COLOR_FORMAT_24)
            {
                unsigned char *src_key = (unsigned char*)(&src_key_value);

                dithering_ptr = out_layer->buf_ptr;
                dithering_ptr += ((dither_dest_rect.y1 * out_layer->width) + dither_dest_rect.x1) * (out_layer->bits_per_pixel >> 3);
                if (!is_src_key_enable)
                {
                    iul_sd_rgb888_2bits_dithering_ip(
                        (unsigned char*)dithering_ptr, 
                        dither_dest_rect.x2 - dither_dest_rect.x1 + 1, 
                        dither_dest_rect.y2 - dither_dest_rect.y1 + 1, 
                        out_layer->width);
                }
                else
                {
                    iul_sd_rgb888_2bits_dithering_ip_srckey(
                        (unsigned char*)dithering_ptr, 
                        dither_dest_rect.x2 - dither_dest_rect.x1 + 1, 
                        dither_dest_rect.y2 - dither_dest_rect.y1 + 1, 
                        out_layer->width,
                        src_key);
                 }
            }
        }
    #endif /* GDI_USING_DITHERING */
        
        /* to prevent race condition: g_hwpng_decode_result from pngFinalize() and from gdi_image_hwpng_msg_handler() */
        if (PNG_STATUS_OK != g_png_status) 
        {
            ret_value = GDI_SUCCEED;
            break;   
        }
    } while(0);

    if (g_png_file_buf)
    {
        gdi_free_ext_mem(&g_png_file_buf);
    }
	
    if (g_png_int_mem)
    {
        if (intmem_from_ext)
        {
            gdi_free_ext_mem(&g_png_int_mem);
        }
        else
        {
            med_free_int_mem(&g_png_int_mem);
        }
    }
    if (g_png_ext_mem)
    {
        gdi_free_ext_mem(&g_png_ext_mem);
    }
    
    g_png_int_mem = NULL;
    g_png_ext_mem = NULL;
    g_png_file_buf = NULL;

    if (is_file)
    {
        FSAL_Close(&png_src);
    }

    if (g_png_decoder_hdl != NULL)
    {
        PNG_STATUS_ENUM status;
        status = pngDecReleaseDecoder(g_png_decoder_hdl);
        g_png_decoder_hdl = NULL;
        GDI_ASSERT(status != PNG_STATUS_INVALID_OPERATION);
    }

    if (ret_value == GDI_SUCCEED)
    {
        ret_value = gdi_image_png_get_result();
    }

    if (ret_value != GDI_SUCCEED)
    {
        GDI_TRACE(GDI_TRC_CODEC_I, GDI_PNG_DECODE_FAIL,//[gdi_image_png_fail]: png_state:%d decode_result:%d decode_type:%d is_file:%d x:%d y:%d w:%d h:%d
                      g_png_status, ret_value, decoder_type, is_file, ox, oy, resized_width, resized_height);
    }
    GDI_TRACE(GDI_TRC_DECODE, GDI_PNG_LEAVE,//[gdi_imgdec_png_draw_internal]: Leave - ret:%d
                    ret_value);
    GDI_IMGDEC_HW_UNLOCK();

    return ret_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_draw_internal
 * DESCRIPTION
 *  draw png image
 * PARAMETERS
 *  ox                  [IN]    the left-up position of the image to be drawn
 *  oy                  [IN]    the left-up position of the image to be drawn
 *  resized_width       [IN]    the width of image to be drawn
 *  resized_height      [IN]    the height of image to be drawn
 *  src                 [IN]    image file name or memory pointer of image data
 *  size                [IN]    the size of src, if src is file name, size=0
 *  is_file             [IN]    src is file name or memory pointer
 *  is_resized          [IN]    the image will be resized or not
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_png_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_blocking,
            void (*callback) (GDI_RESULT result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    gdi_handle act_layer, src_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_png_draw_internal)

    gdi_layer_get_active(&act_layer);
    gdi_get_alpha_blending_source_layer(&src_layer);
    
    ret = gdi_imgdec_png_draw_internal(
            act_layer,
            src_layer,
            ox, 
            oy, 
            resized_width, 
            resized_height, 
            src, 
            size, 
            is_file, 
            NULL,
            gdi_image_codec_get_flag(),
            0);

    GDI_EXIT_CRITICAL_SECTION(gdi_image_png_draw_internal)

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_dimension_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  png_src     [?]         
 *  size        [IN]        
 *  width       [?]         
 *  height      [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_get_dimension_internal(U8 *png_src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 BUFFER[24];
    U8 *buffer;

    while (1)
    {
        if (size == 0)  /* from file */
        {
            FS_HANDLE file_handle;
            file_handle = DRM_open_file(
                              (U16*)png_src,
                               FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED,
                               DRM_PERMISSION_DISPLAY);

            if (file_handle >= 0)
            {
                U32 len;

                buffer = BUFFER;
                DRM_read_file(file_handle, buffer, 24, &len);
                DRM_close_file(file_handle);
                if (len == 24)
                    break;  /* success read data */
            }
        }
        else if (size >= 24)    /* from memory */
        {
            memcpy(BUFFER, png_src, 24);
            buffer = BUFFER;   /* success get data */
            break;
        }
        return GDI_FAILED;
    }
    if (memcmp(buffer, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)  /* PNG signature */
        if (*((U32*) (buffer + 8)) == 13 << 24)             /* must be IHDR, length = 13,but LSB */
            if (memcmp(buffer + 12, "IHDR", 4) == 0)        /* must be 'IHDR' */
            {
                buffer += 16;
                *width = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
                buffer += 4;
                *height = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
                return GDI_SUCCEED;
            }
    return GDI_FAILED;
}



#else /* GDI_USING_PNG */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_dimension_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  png_src     [?]         
 *  size        [IN]        
 *  width       [?]         
 *  height      [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_get_dimension_internal(U8 *png_src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  src                 [?]         
 *  size                [IN]        
 *  is_file             [IN]        
 *  is_blocking         [IN]        
 *  callback            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_blocking,
            void (*callback) (GDI_RESULT result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GDI_FAILED;
}

void gdi_image_png_dummy(void) {}

#endif /* GDI_USING_PNG */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_draw_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  frame_pos       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_codec_set_flag_begin(flag);
    ret = gdi_image_png_draw_internal(
            x,
            y,
            w,
            h,
            data_ptr,
            img_size,
            TOBOOL(flag & GDI_IMAGE_CODEC_FLAG_IS_FILE),
            TRUE,
            NULL);
    gdi_image_codec_set_flag_end();

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_dimension_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_png_get_dimension_file((S8*) data_ptr, width, height);
    }
    else
    {
        return gdi_image_png_get_dimension(data_ptr, img_size, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_png_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_is_png_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    U8 buf[8];
    U32 len;
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = DRM_open_file(
            (U16*) file_name,
            FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED,
            DRM_PERMISSION_DISPLAY);
    if (f < 0) 
    {
        return GDI_IMAGE_ERR_INVALID_FILE;
    }

    result = DRM_read_file(f, buf, 8, &len);

    DRM_close_file(f);

    if (result == FS_NO_ERROR)
        if (len == 8)
            if (memcmp(buf, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)
            {
                return GDI_SUCCEED;
            }
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_png_get_dimension
 * DESCRIPTION
 *  Gets PNG dimension.
 * PARAMETERS
 *  src          [IN]   image source pointer
 *  size         [IN]   image size
 *  width        [OUT]  width
 *  height       [OUT]  height
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_png_get_dimension(U8 *src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_imgdec_bytestream_struct bs;
    
    U8 buf[24];
    U8 *buffer;
    
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_imgdec_bytestream_init(&bs, src, size);

    do
    {
        ret = gdi_imgdec_bytestream_read(&bs, buf, 24);
        if (ret == GDI_FAILED)
        {
            break;
        }
        
        if ((memcmp(buf, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0) &&  /* PNG signature */
            (*((U32*) (buf + 8)) == 13 << 24) &&                 /* must be IHDR, length = 13,but LSB */
            (memcmp(buf + 12, "IHDR", 4) == 0))                 /* must be 'IHDR' */
        {
            buffer = (PU8)buf;
            buffer += 16;
            *width = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
            buffer += 4;
            *height = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);

            ret = GDI_SUCCEED;
        }
    } while(0);

    gdi_imgdec_bytestream_deinit(&bs);

    return ret;
}



