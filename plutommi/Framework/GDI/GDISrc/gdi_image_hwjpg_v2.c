/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_hwjpeg_v2.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image hardware jpeg decoder.
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

#include "gdi_internal.h"
#ifdef GDI_USING_HW_JPEG_V2

#include "med_global.h"
#include "med_utility.h"

#include "gdd_include.h"
#define GDI_HW_JPEG_CODEC_WAITING_TIME 6000       /* ms */

#include "jpeg_enum.h"
#include "jpeg_decode_api.h"      
#include "jpeg_parse_api.h"
#include "gdi_image_jpeg.h"

#include "gd_include.h"

#if defined(GDI_USING_DITHERING)
#include "iul_spatial_dithering.h"
#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
   #include "mmu.h"
   #include "cache_sw.h"
#endif
#endif

#include "kal_release.h"
#include "stack_msgs.h"
#include "fsal.h"
#include "app_ltlcom.h"
#include "med_smalloc.h"

#include "MMIDataType.h"
#include "mmi_frm_event_flag_gprot.h"
#include "mmi_frm_event_flag_prot.h"

#include "gdi_features.h"
#include "gdi_datatype.h"
#include "gdi_image.h"
#include "gdi_imgdec_internal.h"
#include "gdi_primitive.h"
#include "gfx_cache_switch_behavior_enum.h"

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* once you released the handle, the IDP and JPEG HW will be closed and the decoding will be terminated */
static JPEG_DECODER_HANDLE g_hwjpeg_v2_decoder_hdl;

static JPEG_CODEC_STATE_ENUM   g_hwjpeg_v2_state;
static JPEG_CODEC_TYPE_ENUM g_hwjpeg_v2_codec_type;
static S32  g_hwjpeg_v2_decode_result;

static BOOL *g_gdi_imgdec_jpeg_is_aborted;

static kal_int32 gdi_imgdec_jpeg_progress_callback(void);

static gdi_mutex_struct g_hwjpeg_v2_mutex;
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_get_result
 * DESCRIPTION
 *  convert hwjpeg driver return value into GDI return value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_RESULT gdi_image_hwjpeg_v2_get_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cause = g_hwjpeg_v2_decode_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If it abort the SW JPEG, the state will be idle */
    if ((JPEG_CODEC_TYPE_SW == g_hwjpeg_v2_codec_type) &&
        (cause == JPEG_STATUS_OK) &&
        ((g_hwjpeg_v2_state == JPEG_CODEC_STATE_IDLE) ||
         (g_hwjpeg_v2_state == JPEG_CODEC_STATE_ERROR)))
    {
        cause = JPEG_STATUS_DEC_ERROR_PARSE_INCOMPLETE;
    }

    switch (cause)
    {
        case JPEG_STATUS_OK:
            return GDI_SUCCEED;

        case JPEG_STATUS_DEC_ERROR_SOURCE_DIMENSION_ERROR:
        case JPEG_STATUS_DEC_ERROR_DESTINATION_DIMENSION_ERROR:
            return GDI_IMAGE_ERR_IMAGE_TOO_LARGE;

        case JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT:  /* maybe progressive jpeg if using sw jpeg */
             return GDI_IMAGE_ERR_UNSUPPORTED_FORMAT;
            
        case JPEG_STATUS_CODEC_UNAVAILABLE:
        case JPEG_STATUS_IDP_ERROR:
        case JPEG_STATUS_INVALID_PARAMETER:
        case JPEG_STATUS_INVALID_OPERATION:
        case JPEG_STATUS_INVALID_HANDLE:
        case JPEG_STATUS_IO_ERROR:
        case JPEG_STATUS_DEC_ERROR_PARSE_INCOMPLETE:
        case JPEG_STATUS_DEC_ERROR_INVALID_FILE:
        case JPEG_STATUS_DEC_ERROR_INVALID_BUFFER:
        case JPEG_STATUS_DEC_ERROR_READ_ERROR:
        case JPEG_STATUS_DEC_ERROR_INVALID_WIDTH:
        case JPEG_STATUS_DEC_ERROR_INVALID_HEIGHT:
        case JPEG_STATUS_DEC_ERROR_IDP_UNAVAILABLE:
        case JPEG_STATUS_DEC_ERROR_GENERAL_ERROR:
        case JPEG_STATUS_DEC_ERROR_INSUFFICIENT_MEMORY:
        case JPEG_STATUS_DEC_ERROR_CORRUPT_FILE:
            return GDI_FAILED;

        case GDI_IMAGE_ERR_DECODE_TIME_OUT:
            return GDI_IMAGE_ERR_DECODE_TIME_OUT;

        default:
            return GDI_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_send_ilm_to_gdd
 * DESCRIPTION
 *  send ilm to gdd
 * PARAMETERS
 *  ret     [IN]    return value from jpeg driver
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_hwjpeg_v2_send_ilm_to_gdd(S32 jpeg_codec_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = jpeg_codec_state;
    gdd_send_img_codec_ind(&data,sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_timeout_handler
 * DESCRIPTION
 *  timeout handler of gdd
 * PARAMETERS
 *  arg     [IN]    arg from gdd, not used
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_hwjpeg_v2_timeout_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
    {
        GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_JPG_TIMEOUT,//[gdi_image_hwjpeg_v2_timeout_handler]: decoder:%d
            g_hwjpeg_v2_codec_type);
        gdi_image_hwjpeg_v2_send_ilm_to_gdd((S32)GDI_IMAGE_ERR_DECODE_TIME_OUT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_callback
 * DESCRIPTION
 *  message handler of png driver
 * PARAMETERS
 *  ret     [IN]    return value from jpeg driver
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 gdi_image_hwjpeg_v2_callback(JPEG_CODEC_STATE_ENUM state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_JPG_CALLBACK,//[gdi_image_hwjpeg_v2_callback]: decoder:%d state:%d
        g_hwjpeg_v2_codec_type, state);
    if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
    {
        gdi_image_hwjpeg_v2_send_ilm_to_gdd((S32)state);
    }
    else
    {
        g_hwjpeg_v2_state = state;
        jpegDecReset(g_hwjpeg_v2_decoder_hdl);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_cf_to_hw
 * DESCRIPTION
 *  transform the color format from gdi_color_format to JPEG_RGB_FORMAT_ENUM
 * PARAMETERS
 *  cf      [IN]    the gdi color format to be transform
 *  jpeg_cf  [OUT]   the result jpeg color format 
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_hwjpeg_v2_cf_to_hw(gdi_color_format cf, JPEG_RGB_FORMAT_ENUM *jpeg_cf)
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
            *jpeg_cf = JPEG_RGB_FORMAT_RGB565;
            break;
        
        case GDI_COLOR_FORMAT_24:
            *jpeg_cf = JPEG_RGB_FORMAT_RGB888;
            break;
        
        case GDI_COLOR_FORMAT_32:
            *jpeg_cf = JPEG_RGB_FORMAT_ARGB8888;
            break;

        case GDI_COLOR_FORMAT_32_PARGB:
            *jpeg_cf = JPEG_RGB_FORMAT_ARGB8888;
            break;
        
        case GDI_COLOR_FORMAT_PARGB6666:
            *jpeg_cf = JPEG_RGB_FORMAT_ARGB6666;
            break;
/* this is wrong way */
        case GDI_COLOR_FORMAT_UYVY422:
            *jpeg_cf = JPEG_YUV_FORMAT_PACKED_UYVY422;
            break;
            

        default:
            *jpeg_cf = JPEG_RGB_FORMAT_UNSUPPORTED;
            return GDI_FAILED;  /* hardware png decoder didn't support this color format */
    }
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_msg_handler
 * DESCRIPTION
 *  msg handler of gdd, handle hwpng msg
 * PARAMETERS
 *  ilm         [IN]        the msg from gdi
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_hwjpeg_v2_msg_handler(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    S32 *interrupt_value = (S32*)&
                           (((gdd_img_codec_event_ind_struct*)ilm->local_para_ptr)->header);
    
    ASSERT(((0 <= *interrupt_value) && (JPEG_CODEC_STATE_EOF >= *interrupt_value)) ||
           (GDI_IMAGE_ERR_DECODE_TIME_OUT == *interrupt_value));

    GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_JPG_HW_MSG,//[gdi_image_hwjpeg_v2_msg_handler]: interrupt_value:%d
        *interrupt_value);
    if (g_gdi_imgdec_jpeg_is_aborted && !gdi_imgdec_jpeg_progress_callback())
    {   /* IMGDEC abort error */
        *interrupt_value = JPEG_CODEC_STATE_ERROR;
    }
    else if (!gdi_image_progress_callback())
    {
        if (gdi_image_is_timeout())
        {
            *interrupt_value = GDI_IMAGE_ERR_DECODE_TIME_OUT;
        }
        else
        {
            *interrupt_value = JPEG_CODEC_STATE_ERROR;
        }
    }
    
    if (JPEG_CODEC_STATE_PAUSED == *interrupt_value) 
    {  
        g_hwjpeg_v2_state = JPEG_CODEC_STATE_BUSY;
        g_hwjpeg_v2_decode_result = jpegDecResume(g_hwjpeg_v2_decoder_hdl);
        if (JPEG_STATUS_OK != g_hwjpeg_v2_decode_result)
        {
            gdi_image_hwjpeg_v2_send_ilm_to_gdd((S32)g_hwjpeg_v2_state);
        }
    }
    else if (JPEG_CODEC_STATE_BUSY == *interrupt_value)
    {
        /* still decoding, nothing to do... */
        return ;
    }
    else 
    {
        /* hw decode fail */
        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
        gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
        jpegDecReset(g_hwjpeg_v2_decoder_hdl);

        switch (*interrupt_value)
        {   
            case JPEG_CODEC_STATE_COMPLETE:             /* the module is stopped after the completion of task */
                g_hwjpeg_v2_decode_result = JPEG_STATUS_OK;
                break;
            
            case JPEG_CODEC_STATE_FREE:                 /* the module is free to use */
            case JPEG_CODEC_STATE_IDLE:                 /* the module is acquired by some body */
            case JPEG_CODEC_STATE_EOF:
            case JPEG_CODEC_STATE_ERROR:                /* the module is stopped due to error */
                g_hwjpeg_v2_decode_result = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
                break;
            
            case GDI_IMAGE_ERR_DECODE_TIME_OUT:
                g_hwjpeg_v2_decode_result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                break;
            
            default:
                ASSERT(0);
                break;
        }
        GDD_SET_EVENT(GDD_EVENT_WAIT_DECODING);
     }
}


static kal_int32 gdi_image_hwjpeg_v2_finalize(
                    kal_int32 error_code, 
                    void **extMem,
                    void **intMem,
                    MMI_BOOL *intmem_from_ext,
                    void **readBuffer,
                    void **fsalCacheAddr,
                    STFSAL *jpeg_src_file_handle)
{
    /* finalize */
    jpegDecReleaseDecoder(g_hwjpeg_v2_decoder_hdl);

    if (error_code == GDI_SUCCEED)
    {
        error_code = gdi_image_hwjpeg_v2_get_result();
    }
    if (*intMem)
    {
        if (*intmem_from_ext)
        {
            gdi_free_ext_mem(intMem);
        }
        else
        {
            med_free_int_mem(intMem);
        }
    }
    if (*extMem)
    {
        gdi_free_ext_mem(extMem);
    }
    if (*readBuffer)
    {
        gdi_free_ext_mem(readBuffer);
    }
    if (*fsalCacheAddr)
    {
        gdi_free_ext_mem(fsalCacheAddr);
    }
    FSAL_Close(jpeg_src_file_handle);

    *intmem_from_ext = MMI_FALSE;
    
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_jpeg_progress_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 gdi_imgdec_jpeg_progress_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gdi_imgdec_jpeg_is_aborted && *g_gdi_imgdec_jpeg_is_aborted)
    {
        return 0;
    }

    if ((JPEG_CODEC_TYPE_SW == g_hwjpeg_v2_codec_type) &&
        (KAL_TRUE == g_imgdec_timer_timeout_flag))
    {
        return 0;
    }
    return 1;
}

//warning
#if defined(__JPEG_SENSOR_SUPPORT__) || defined(__POSTPROC_SUPPORT__)
extern JPEG_STATUS_ENUM jpegDecSetRotation(JPEG_DECODER_HANDLE handle,JPEG_DECODE_ROTATE_ANGLE_ENUM angle);
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_draw_internal
 * DESCRIPTION
 *  draw jpeg (hw decoder v2)
 * PARAMETERS
 *  ox                  [IN]    the left-up position of the image to be drawn
 *  oy                  [IN]    the left-up position of the image to be drawn
 *  resized_width       [IN]    the width of image to be drawn
 *  resized_height      [IN]    the height of image to be drawn
 *  src                 [IN]    image file name or memory pointer of image data
 *  size                [IN]    the size of src, if src is file name, size=0
 *  is_file             [IN]    src is file name or memory pointer
 *  is_resized          [IN]    the image will be resized or not
 *  decoded_image_width [OUT]   output the final decode image width
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_image_hwjpeg_v2_draw_internal(
                            gdi_handle output_layer_handle,
                            S32 x,
                            S32 y,
                            S32 resized_width,
                            S32 resized_height,
                            U8 *src,
                            U32 size,
                            BOOL is_file,
                            BOOL is_resized,
                            S32 *decoded_image_width,
                            BOOL source_key_enable,
                            gdi_color source_key_value,
                            BOOL *is_aborted,
                            U32 flag,
                            S32 aspect_flag,
                            BOOL need_rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STFSAL jpeg_src;
    void *extMem = NULL;
    void *intMem = NULL;
    void *readBuffer = NULL;
    void *fsalCacheAddr = NULL;
    kal_int32   ret_value = GDI_SUCCEED;
    MMI_BOOL intmem_from_ext = MMI_FALSE;
    kal_bool force_to_use_swjpeg = KAL_FALSE;
    gdi_layer_struct *out_layer;   
    S32 ox = x, oy = y;
    S32 o_resized_width = resized_width, o_resized_height = resized_height;

    #if defined(GDI_USING_DITHERING)
    kal_bool enable_dithering = KAL_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *  NOTICE!!!
     *  DO NOT use GDI LOCK within this function since this function is
     *  shared between IMGDEC and GDI.
     */
    // NO GDI LOCK FOR THIS FUNCTION

    if (is_resized && ((resized_width == 0) || (resized_height == 0)))
    {
        return GDI_SUCCEED;
    }

    GDI_TRACE(GDI_TRC_DECODE, GDI_JPG_ENTER,//[gdi_image_hwjpeg_v2_draw_internal]: Enter - out_layer:%x x:%d y:%d w:%d h:%d src:%x is_file:%d
        output_layer_handle, x, y, resized_width, resized_height, src, is_file);
    GDI_JPEG_LOCK_MUTEX;

    out_layer = (gdi_layer_struct*)output_layer_handle;
    g_gdi_imgdec_jpeg_is_aborted = is_aborted;

    #if defined(GDI_USING_DITHERING)
    if (is_file &&
        (out_layer->cf == GDI_COLOR_FORMAT_24) &&
        !(flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DITHER))
    {
        enable_dithering = KAL_TRUE;
    }
    #endif

    while (1)
    {
        /* get decoder */
        // gdi_image_jpeg_get_force_use_swjpeg(&force_to_use_swjpeg);
        force_to_use_swjpeg = (flag & GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE) ? KAL_TRUE : KAL_FALSE;
        
        /* Just a temp resolution to switch HW JPEG to SW JPEG */
        if (KAL_FALSE == force_to_use_swjpeg)
        {
            force_to_use_swjpeg = (flag & GDI_IMAGE_CODEC_FLAG_FORCE_DITHER) ? KAL_TRUE : KAL_FALSE;
        }

        if (force_to_use_swjpeg == KAL_FALSE)
        {
            /* get HW decoder */
            g_hwjpeg_v2_decode_result = jpegDecGetDecoder(JPEG_CODEC_TYPE_HW, &g_hwjpeg_v2_decoder_hdl);

            g_hwjpeg_v2_codec_type = JPEG_CODEC_TYPE_HW;
        }
        
        if ((force_to_use_swjpeg == KAL_TRUE) || (JPEG_STATUS_CODEC_UNAVAILABLE == g_hwjpeg_v2_decode_result))
        {
            /* If get hw failed, or force to use sw, get sw decoder here. */
            g_hwjpeg_v2_decode_result = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &g_hwjpeg_v2_decoder_hdl);
            if (JPEG_STATUS_CODEC_UNAVAILABLE == g_hwjpeg_v2_decode_result)
            {
               ASSERT(0);
            }

            g_hwjpeg_v2_codec_type = JPEG_CODEC_TYPE_SW;

            #if defined(GDI_USING_DITHERING)
            enable_dithering = KAL_FALSE;   /* only hw jpeg need to use dithering */
            #endif
            /* The check abort function will be called before the decoding of every MCU row.
             * This feature takes effect only for SW JPEG decoder. 
             */
            // TODO: IMGDEC must replace this callback to prevent being terminated by GDI NONBLOCKING.
            if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
            {
                /* IMGDEC callback */
                g_hwjpeg_v2_decode_result = jpegDecSetCheckAbortFunction(g_hwjpeg_v2_decoder_hdl, gdi_imgdec_jpeg_progress_callback);
            }
            else
            {
                g_hwjpeg_v2_decode_result = jpegDecSetCheckAbortFunction(g_hwjpeg_v2_decoder_hdl, gdi_image_progress_callback);
            }                
        }

        /* We add GDI_IMGDEC_HW_LOCK to pretect HW JPEG from decoding together with HW GIF */
        if (g_hwjpeg_v2_codec_type == JPEG_CODEC_TYPE_HW)
        {
            GDI_IMGDEC_HW_LOCK();
        }

        if (flag & GDI_IMAGE_CODEC_FLAG_DISABLE_CACHE_SWITCH)
        {
            jpegDecSetDstBufferSwitchBehavior(g_hwjpeg_v2_decoder_hdl, GFX_CACHE_SWITCH_BEHAVIOR_NOT_SWITCH);
        }            
        
        g_hwjpeg_v2_decode_result = jpegDecSetCallbackFunction(g_hwjpeg_v2_decoder_hdl, gdi_image_hwjpeg_v2_callback);

        /* Set source image */
        {
            kal_uint32 readBufferSizeBest = 0, readBufferSizeMinimum = 0;
            kal_uint32 fsalCacheSizeBest = 0, fsalCacheSizeMinimum = 0;

            jpegDecQueryFileBuffer(
                g_hwjpeg_v2_decoder_hdl, 
                &readBufferSizeBest, 
                &readBufferSizeMinimum,
                &fsalCacheSizeBest, 
                &fsalCacheSizeMinimum);
            
            if (flag & GDI_IMAGE_CODEC_FLAG_USE_LESS_BUF)
            {
                readBufferSizeBest = readBufferSizeMinimum;
            }
            
            /* allocate file buffer */
            /* with larger file buffer allocated, the overhead of pause-resume will be decreased. */
            while (1)
            {
                if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
                {
                    readBuffer = (void *)gdi_alloc_ext_mem(readBufferSizeBest);
                }
                else
                {
                    readBuffer = (void *)gdi_alloc_ext_mem_cacheable(readBufferSizeBest);
                }
                
                if ((readBuffer != NULL) || (readBufferSizeBest == readBufferSizeMinimum))
                {
                    break;
                }                
                readBufferSizeBest /= 2;
                if (readBufferSizeBest < readBufferSizeMinimum)
                {
                    readBufferSizeBest = readBufferSizeMinimum;
                }
            }
            if (NULL == readBuffer && 0 != readBufferSizeBest)
            {
                ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                break;
            }
            
            /* allocate fsal cache */
            /* this buffer is not necessary, but with it the performance of FSAL will be greatly increased */
            while(1)
            {
                if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
                {
                   fsalCacheAddr = (void *)gdi_alloc_ext_mem(fsalCacheSizeBest);
                }
                else
                {
                   fsalCacheAddr = (void *)gdi_alloc_ext_mem_cacheable(fsalCacheSizeBest);
                }
                
                if((fsalCacheAddr != NULL) || (fsalCacheSizeBest == fsalCacheSizeMinimum))
                {
                    break;
                }                
                fsalCacheSizeBest /= 2;
                if (fsalCacheSizeBest < fsalCacheSizeMinimum)
                {
                    fsalCacheSizeBest = fsalCacheSizeMinimum;
                }
            }
            if (!fsalCacheAddr)
            {
                fsalCacheSizeBest = 0;
            }

            /* open file */
            if (is_file) 
            { 
                ret_value = FSAL_Open(&jpeg_src, src, FSAL_READ_SHARED);
            } 
            else
            {
                FSAL_Direct_SetRamFileSize(&jpeg_src, size);         
                ret_value = FSAL_Open(&jpeg_src, (void *)src, FSAL_ROMFILE);
            }

            /* Set source file */
            if (FSAL_OK != ret_value) 
            {
                ret_value = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
                break;
            }
            else
            {
                g_hwjpeg_v2_decode_result = jpegDecSetSourceFile(
                                                g_hwjpeg_v2_decoder_hdl,
                                                &jpeg_src,
                                                readBuffer,
                                                readBufferSizeBest,
                                                fsalCacheAddr,
                                                fsalCacheSizeBest);
            }
            
            if (JPEG_STATUS_OK != g_hwjpeg_v2_decode_result)
            {
                if ((JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type) &&
                    (g_hwjpeg_v2_decode_result == JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT))
                {
                    jpegDecReset(g_hwjpeg_v2_decoder_hdl);
                    gdi_image_hwjpeg_v2_finalize(   /* close hw jpeg */
                        ret_value,
                        &extMem,
                        &intMem,
                        &intmem_from_ext,
                        &readBuffer,
                        &fsalCacheAddr,
                        &jpeg_src);

                    GDI_IMGDEC_HW_UNLOCK();

                    flag |= GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE; /* force to use sw jpeg */
                    ret_value = GDI_SUCCEED;
                    continue;
                }
                else
                {
                    ret_value = GDI_SUCCEED;
                    break;
                }
            }
        }
        
        /* Set Working Buffer */
        {
            kal_uint32 intMemorySizeBest, intMemorySizeMinumum;
            kal_uint32 extMemorySizeBest, extMemorySizeMinimum;

            jpegDecQueryWorkingMemory(
                g_hwjpeg_v2_decoder_hdl, 
                &intMemorySizeBest, 
                &intMemorySizeMinumum,
                &extMemorySizeBest,
                &extMemorySizeMinimum);

            if (flag & GDI_IMAGE_CODEC_FLAG_USE_LESS_BUF)
            {
                extMemorySizeBest = extMemorySizeMinimum;
            }

            while(1)
            {
                intMem = (void *)med_alloc_int_mem(intMemorySizeBest);
                
                if ((intMem != NULL) || (intMemorySizeBest == intMemorySizeMinumum))
                {
                    break;
                }                
                intMemorySizeBest /= 2;
                if (intMemorySizeBest < intMemorySizeMinumum)
                {
                    intMemorySizeBest = intMemorySizeMinumum;
                }
            }
            if (NULL == intMem && 0 != intMemorySizeBest)
            {
                /* if internal mem is not enough, alloc from ext mem. */
                intMem = (void *)gdi_alloc_ext_mem(intMemorySizeMinumum);
                if (!intMem)
                {
                   ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                   break;
                }
                intmem_from_ext = MMI_TRUE;
            }

            while (1)
            {
                if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
                {
                    extMem = (void *)gdi_alloc_ext_mem(extMemorySizeBest);
                }
                else
                {
                    extMem = (void *)gdi_alloc_ext_mem_cacheable(extMemorySizeBest);
                }
                
                if ((extMem != NULL) || (extMemorySizeBest == extMemorySizeMinimum))
                {
                    break;
                }                
                extMemorySizeBest /= 2;
                if (extMemorySizeBest < extMemorySizeMinimum)
                {
                    extMemorySizeBest = extMemorySizeMinimum;
                }
            }
            if (NULL == extMem && 0 != extMemorySizeBest)
            {
                ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                break;
            }

            g_hwjpeg_v2_decode_result = jpegDecSetWorkingMemory(g_hwjpeg_v2_decoder_hdl, intMem, intMemorySizeBest, extMem, extMemorySizeBest);
            if (JPEG_STATUS_OK != g_hwjpeg_v2_decode_result)
            {
                ret_value = GDI_SUCCEED;
                break;
            }
        }
        
        /* Set Canvas Window */ 
        {
            JPEG_RGB_FORMAT_ENUM    canvas_color_format;   

            ret_value = gdi_image_hwjpeg_v2_cf_to_hw(out_layer->vcf, &canvas_color_format);
            if (GDI_SUCCEED != ret_value)
            {
                ret_value = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                break;
            }
            
            if(out_layer->vcf != GDI_COLOR_FORMAT_UYVY422)
            {
                g_hwjpeg_v2_decode_result = jpegDecSetRGBCanvas(
                                    g_hwjpeg_v2_decoder_hdl, 
                                    out_layer->buf_ptr, 
                                    out_layer->width, 
                                    out_layer->height,
                                    canvas_color_format);
            }
            else
            {
	            g_hwjpeg_v2_decode_result = jpegDecSetYUVCanvas(
	                                    g_hwjpeg_v2_decoder_hdl,
	                                    out_layer->buf_ptr, 
	                                    0,
	                                    0,
	                                    out_layer->width, 
	                                    out_layer->height,
	                                    canvas_color_format);
            }
            if (JPEG_STATUS_OK != g_hwjpeg_v2_decode_result)
            {
                ret_value = GDI_FAILED;
                break;
            }
        }
        /* Set Output Window */
        {
            kal_uint16 src_w, src_h;
            if (!need_rotate)
            {
                jpegDecSetRotation(g_hwjpeg_v2_decoder_hdl, JPEG_DECODE_NO_FLIP_ROTATE_CW_0);
            }
            jpegDecGetImageDimension(g_hwjpeg_v2_decoder_hdl, &src_w, &src_h);      
            if (flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
            {
                gdi_util_adjust_aspect(
                    aspect_flag,
                    x,
                    y,
                    resized_width,
                    resized_height,
                    src_w,
                    src_h,
                    &ox,
                    &oy,
                    &o_resized_width,
                    &o_resized_height);
            }
            if (!is_resized)
            {
                o_resized_width = src_w;
                o_resized_height = src_h;
            }
        }

        /* return the final decode width */
        if (decoded_image_width)
        {
            *decoded_image_width = o_resized_width;
        }
        
        g_hwjpeg_v2_decode_result = jpegDecSetOutputWindow(g_hwjpeg_v2_decoder_hdl, ox, oy, o_resized_width, o_resized_height);
        g_hwjpeg_v2_decode_result = jpegDecSetClipWindow(
                                    g_hwjpeg_v2_decoder_hdl, 
                                    out_layer->clipx1, 
                                    out_layer->clipy1, 
                                    out_layer->clipx2 - out_layer->clipx1 + 1, 
                                    out_layer->clipy2 - out_layer->clipy1 + 1);  

        /* Check abort before decode start */
        if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
        {
            if ((g_gdi_imgdec_jpeg_is_aborted && *g_gdi_imgdec_jpeg_is_aborted))
            {
                ret_value = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                break;
            }
        }
        else
        {
            if (!gdi_image_progress_callback())
            {
                ret_value = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                break;
            }
        }

        /* gdd */
        if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
        {
            gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, gdi_image_hwjpeg_v2_msg_handler);
            /* start gdd */
            gdd_start_timer(
                GDD_TIMER_IMAGE_CODEC_TIMEOUT,
                GDI_HW_JPEG_CODEC_WAITING_TIME,
                gdi_image_hwjpeg_v2_timeout_handler,
                0);
        }
        
        /* start decode */
        g_hwjpeg_v2_state = JPEG_CODEC_STATE_BUSY;
        g_hwjpeg_v2_decode_result = jpegDecStart(g_hwjpeg_v2_decoder_hdl);
        GDI_TRACE(GDI_TRC_DECODE, GDI_JPG_START,//[gdi_image_hwjpeg_v2_draw_internal]: Start - decoder:%d status:%d
            g_hwjpeg_v2_codec_type, g_hwjpeg_v2_decode_result);

        if ((JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type) &&
            (JPEG_STATUS_OK == g_hwjpeg_v2_decode_result))
        {
            /* Check abort after decode start */
            if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
            {
                if ((KAL_TRUE == g_imgdec_timer_timeout_flag) ||
                    (g_gdi_imgdec_jpeg_is_aborted && *g_gdi_imgdec_jpeg_is_aborted))
                {
                    g_hwjpeg_v2_decode_result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                }
            }
            else
            {
                if (!gdi_image_progress_callback())
                {
                    g_hwjpeg_v2_decode_result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                }
            }
        }

        /* gdd */
        if (JPEG_STATUS_OK != g_hwjpeg_v2_decode_result)
        {
            /* hw decode fail */
            if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
            {
                gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
                gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
            }
            jpegDecReset(g_hwjpeg_v2_decoder_hdl);

            /* hw jpeg decoder limitation */
            /* use sw jpeg decoder to try again */
            if ((JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type) &&
                ((g_hwjpeg_v2_decode_result == JPEG_STATUS_DEC_ERROR_SOURCE_DIMENSION_ERROR) ||
                 (g_hwjpeg_v2_decode_result == JPEG_STATUS_DEC_ERROR_DESTINATION_DIMENSION_ERROR) ||
                 (g_hwjpeg_v2_decode_result == JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT)))
            {
                gdi_image_hwjpeg_v2_finalize(   /* close hw jpeg */
                    ret_value,
                    &extMem,
                    &intMem,
                    &intmem_from_ext,
                    &readBuffer,
                    &fsalCacheAddr,
                    &jpeg_src);

                GDI_IMGDEC_HW_UNLOCK();

                flag |= GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE; /* force to use sw jpeg */
                ret_value = GDI_SUCCEED;
                continue;
            }
            else
            {
                break;
            }
        }

        if (JPEG_CODEC_TYPE_HW == g_hwjpeg_v2_codec_type)
        {
		GDD_WAIT_EVENT(GDD_EVENT_WAIT_DECODING);    /* wait gdd finish drawing and set the event */
        }

        if (gdi_image_hwjpeg_v2_get_result() != GDI_SUCCEED)
        {
            break;
        }

        /* dithering */
        #if defined(GDI_USING_DITHERING)
        if (enable_dithering)
        {
            gdi_rect_struct dest_rect;
            U8 *dithering_ptr;

            // Change frame buffer from non-cacheable to cacheable
        #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
            if((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(out_layer->buf_ptr))) && 
               (IS_CACHE_LINE_SIZE_ALIGNED(out_layer->layer_size)) &&
    	       (is_predef_dyna_c_region((kal_uint32)out_layer->buf_ptr, out_layer->layer_size))) 
            {	
                if(KAL_TRUE == INT_QueryIsNonCachedRAM((kal_uint32)out_layer->buf_ptr, out_layer->layer_size))
                {
                    dynamic_switch_cacheable_region((void*)&(out_layer->buf_ptr), out_layer->layer_size, PAGE_CACHEABLE);
                }
            }
        #endif
            
            dithering_ptr = out_layer->buf_ptr;            
            /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
            dest_rect.x1 = ox;
            dest_rect.y1 = oy;
            dest_rect.x2 = ox + o_resized_width- 1;
            dest_rect.y2 = oy + o_resized_height - 1;
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

                dithering_ptr += ((dest_rect.y1 * out_layer->width) + dest_rect.x1) * (out_layer->bits_per_pixel >> 3);
                
                iul_sd_bgr888_2bits_dithering_ip(
                    (unsigned char*)dithering_ptr, 
                    dest_rect.x2 - dest_rect.x1 + 1, 
                    dest_rect.y2 - dest_rect.y1 + 1, 
                    out_layer->width);
            } while(0);

            // Change frame buffer from cacheable to non-cacheable
        #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
            if((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(out_layer->buf_ptr))) && 
               (IS_CACHE_LINE_SIZE_ALIGNED(out_layer->layer_size)) &&
    	       (is_predef_dyna_c_region((kal_uint32)out_layer->buf_ptr, out_layer->layer_size))) 
            {	
                if(KAL_TRUE == INT_QueryIsCachedRAM((kal_uint32)out_layer->buf_ptr, out_layer->layer_size))
                {
                    dynamic_switch_cacheable_region((void*)&(out_layer->buf_ptr), out_layer->layer_size, PAGE_NO_CACHE);
                }
            }
        #endif
        }
        #endif

        /* replace source key */
        if (source_key_enable)
        {
            S32 i = 0, temp_with;
            gdi_rect_struct dest_rect;
            kal_bool need_replace = KAL_TRUE;
            U8* start_buf;
            
            /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
            dest_rect.x1 = ox;
            dest_rect.y1 = oy;
            dest_rect.x2 = ox + o_resized_width- 1;
            dest_rect.y2 = oy + o_resized_height - 1;

            GDI_CLIP_TWO_RECT(
                dest_rect.x1, 
                dest_rect.y1, 
                dest_rect.x2, 
                dest_rect.y2,
                    out_layer->clipx1,
                    out_layer->clipy1,
                    out_layer->clipx2,
                    out_layer->clipy2,
                need_replace = KAL_FALSE);
            if (KAL_TRUE == need_replace)
            {
                temp_with = dest_rect.x2 - dest_rect.x1 + 1;
                start_buf = out_layer->buf_ptr + (((dest_rect.y1 * out_layer->width + dest_rect.x1) * out_layer->bits_per_pixel) >> 3);
                for (i = dest_rect.y1; i <= dest_rect.y2; i++)
                {
                    if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
                    {
                        if ((KAL_TRUE == g_imgdec_timer_timeout_flag) ||
                            (g_gdi_imgdec_jpeg_is_aborted && *g_gdi_imgdec_jpeg_is_aborted))
                        {
                            ret_value = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                            break;
                        }
                    }
                    else
                    {
                        if (!gdi_image_progress_callback())
                        {
                            ret_value = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                            break;
                        }
                    }
                    gd_replace_src_key[out_layer->cf](
                        start_buf,
                        temp_with,
                        0,
                        0,
                        0,
                        0,
                        temp_with - 1,
                        0,
                    source_key_value,
                        temp_with,
                        1);
                    start_buf += (out_layer->width * out_layer->bits_per_pixel) >> 3;
                }
            }
        }
        break;
    }

    /* finalize */
    ret_value = gdi_image_hwjpeg_v2_finalize(
                    ret_value,
                    &extMem,
                    &intMem,
                    &intmem_from_ext,
                    &readBuffer,
                    &fsalCacheAddr,
                    &jpeg_src);

    if (g_hwjpeg_v2_codec_type == JPEG_CODEC_TYPE_HW)
    {
        GDI_IMGDEC_HW_UNLOCK();
    }

    if (ret_value != GDI_SUCCEED)
    {
        GDI_TRACE(GDI_TRC_CODEC_I, GDI_JPG_DECODE_FAIL,//[gdi_image_jpg_fail]: jpg_state:%d decode_result:%d decode_type:%d is_file:%d x:%d y:%d w:%d h:%d
                      g_hwjpeg_v2_state, ret_value, g_hwjpeg_v2_codec_type, is_file, ox, oy, o_resized_width, o_resized_height);
    }
    GDI_JPEG_UNLOCK_MUTEX;
    GDI_TRACE(GDI_TRC_DECODE, GDI_JPG_LEAVE,//[gdi_image_hwjpeg_v2_draw_internal]: Leave - ret:%d
        ret_value);

    return ret_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwjpeg_v2_init
 * DESCRIPTION
 *  Initialize the JPEG decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_jpeg_v2_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_init(&g_hwjpeg_v2_mutex);
}


/*****************************************************************************
* FUNCTION
*  gdi_jpeg_lock_mutex
* DESCRIPTION
*  Lock GDI jpeg mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_jpeg_lock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&g_hwjpeg_v2_mutex);
}


/*****************************************************************************
* FUNCTION
*  gdi_jpeg_unlock_mutex
* DESCRIPTION
*  Unlock GDI jpeg mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_jpeg_unlock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_unlock(&g_hwjpeg_v2_mutex);
}


/*****************************************************************************
* FUNCTION
*  gdi_jpeg_get_dimension_internal
* DESCRIPTION
*  Get the dimension from jpeg decoder
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
GDI_RESULT gdi_jpeg_get_dimension_internal(U8 *src, U32 size, S32 *width, S32 *height, BOOL need_rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STFSAL fsal;
    JPEG_STATUS_ENUM status;
    JPEG_FILE_INFO *file_info;
    GDI_RESULT ret = GDI_FAILED;
    void *file_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        if(FSAL_Open(&fsal, (kal_int8*)src, FSAL_READ_SHARED) != FSAL_OK)
        {
            return GDI_FAILED;
        }
    }
    else
    {
        FSAL_Direct_SetRamFileSize(&fsal, size);
        if(FSAL_Open(&fsal, src, FSAL_ROMFILE) != FSAL_OK)
        {
            return GDI_FAILED;
        }
    }

    file_buffer = gdi_alloc_ext_mem_cacheable(2 * 1024);
    if (file_buffer != NULL)
    {
        FSAL_SetBuffer(&fsal, 2 * 1024, file_buffer);
    }

    status = jpegParserGetImageInfo(&fsal, (JPEG_FILE_INFO **)&file_info);
    if (status != JPEG_STATUS_OK)
    {
        FSAL_Close(&fsal);
        if (file_buffer != NULL)
        {
            gdi_free_ext_mem(&file_buffer);
        }
        return GDI_FAILED;
    }

    if (need_rotate)
    {
        status = jpegParserGetImageDimension(file_info, width, height);
    }
    else
    {
        status = jpegParserGetSourceDimension(file_info, width, height);
    }
    if (status == JPEG_STATUS_OK)
    {
        ret = GDI_SUCCEED;
    }
    status = jpegParserReleaseImageInfo(file_info);
    FSAL_Close(&fsal);
    if (file_buffer != NULL)
    {
        gdi_free_ext_mem(&file_buffer);
    }
    GDI_ASSERT(status == JPEG_STATUS_OK);
    return ret;
}

#endif /* GDI_USING_HW_JPEG_V2 */


GDI_RESULT gdi_image_jpeg_get_desc_from_file(const WCHAR *filepath, kal_char *out_desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#if defined(GDI_USING_HW_JPEG_V2) && defined(GDI_USING_JPEG_EXIF)
    STFSAL fsal;
    void *file_buffer;
    JPEG_FILE_INFO *file_info;
    JPEG_STATUS_ENUM status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(FSAL_Open(&fsal, (void*)filepath, FSAL_READ_SHARED) != FSAL_OK)
    {
        return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }

    file_buffer = NULL;
    do {
        file_buffer = gdi_alloc_ext_mem_cacheable(2 * 1024);
        if (file_buffer == NULL)
        {
            ret = GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
            break;
        }

        FSAL_SetBuffer(&fsal, 2 * 1024, file_buffer);

        status = jpegParserGetImageInfo(&fsal, (JPEG_FILE_INFO**)&file_info);
        if (status != JPEG_STATUS_OK)
        {
            ret = GDI_IMAGE_ERR_INVALID_FILE;
            break;
        }

        status = jpegParserGetImageDescription(file_info, (kal_uint8*)out_desc);
        if (status == JPEG_STATUS_OK)
        {
            ret = GDI_SUCCEED;
        }
        status = jpegParserReleaseImageInfo(file_info);
    } while (0);

    if (file_buffer != NULL)
    {
        gdi_free_ext_mem(&file_buffer);
    }
    
    FSAL_Close(&fsal);

#endif

    return ret;
}

