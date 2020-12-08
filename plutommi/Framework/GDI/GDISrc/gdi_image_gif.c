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
 *  gdi_image_gif.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Gif related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"
#include "drm_gprot.h"
#include "kal_trace.h"
#include "mmi_frm_event_flag_prot.h"
#include "MMI_fw_trc.h"
#include "gdi_trc.h"
#include "gdi_internal.h"
#include "gd_primitive.h"
#include "gdd_include.h"
#include "gui.h"        /* for timer */
#include "mmi_frm_gprot.h"

#include "med_global.h"
#include "med_utility.h"
#include "med_api.h"

#include "gif_decode_api.h"

#include "kal_general_types.h"
#include "lcd_if.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "drm_gprot.h"
#include "Unicodexdcl.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"

#include "gdi_features.h"
#include "gdi_datatype.h"
#include "gdi_image_gif.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_mutex.h"
#include "gdi_bytestream.h"
#include "gdi_primitive.h"
#include "gdi_animate.h"
#include "kal_release.h"
#include "gdi_layer.h"
#include "gdi_util.h"
#include "gdi_imgdec_internal.h"
#include "gdi_image.h"
#include "gdi_lfs.h"

#include "drv_sw_features_display.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"

#include "gfx_cache_switch_behavior_enum.h"

/****************************************************************************
* Define
*****************************************************************************/
#if !defined(__MTK_TARGET__)
#define __align(x)
#endif 

#if defined GDI_SUPPORT_PALETTES
extern gdi_color gdi_layer_palette[GDI_SUPPORT_PALETTES][256];
#endif 

/*
 * NOTICE: to make a region ARM9 D-cacheable, it must comply with some rules.
 * If we make other variables D-cacheable without checking these rules, 
 * it may have potential issues.
 * 
 * The current implementation also uses gdi_gif_local_palette[], gdi_gif_stack[] and GDI_TREE_BUFFER[] as HW GIF buffer.
 * However, since MT623X does not have HW GIF decoder, the check is redundant.
 */
#if defined(__MTK_TARGET__) && defined(GDI_USING_GIF)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW" 
#endif

gdi_color gdi_gif_local_palette[256];

#if defined(__MTK_TARGET__) && defined(GDI_USING_GIF)
#pragma arm section zidata, rwdata
#endif


#ifdef GDI_USING_GIF

#define GDI_HW_GIF_CODEC_WAITING_TIME 6000

typedef struct
{
    S32 gif_state;
    U32 frame_number;
} gdi_image_hwgif_state_struct;

/****************************************************************************
* Local Variable
*****************************************************************************/
static U16 gdi_image_gif_transparent_index;
static U16 gdi_image_gif_palette_size;
static GIF_DISPOSAL_METHOD_ENUM gdi_image_gif_next_frame_disposal;

static GIF_DECODER_HANDLE g_image_gif_decoder_hdl; /* gif handler */
static GIF_STATUS_ENUM g_image_gif_status;
static GIF_DEC_STATE_ENUM g_image_gif_state;

static kal_bool g_image_gif_file_opened;

static __align(4) void *g_image_gif_int_mem;    /* used to alloc internal ram */
static __align(4) void *g_image_gif_ext_mem;    /* used to alloc external ram */

static BOOL *g_gdi_imgdec_gif_is_aborted;
static U16 g_gdi_image_gif_frame_number;
static GDI_RESULT gdi_image_gif_decode_result;
#endif /* GDI_USING_GIF */

static U32 gdi_image_gif_codec_flag = 0;

#if defined GDI_LCD_PALETTE_SUPPORT_RGB_888
static gdi_color_format gdi_image_gif_palette_color_format = GDI_COLOR_FORMAT_24;
#else
static gdi_color_format gdi_image_gif_palette_color_format = GDI_COLOR_FORMAT_16;
#endif


/****************************************************************************
* Local Function
*****************************************************************************/
#ifdef GDI_USING_GIF

static GDI_RESULT gdi_image_gif_get_color_format(gdi_color_format cf, GIF_COLOR_FORMAT_ENUM *gif);
static S32 gdi_imgdec_gif_progress_callback(void);
static void gdi_image_swgif_callback(kal_uint32 state, kal_uint32 frame_number);
static void gdi_image_hwgif_timeout_handler(void *arg);
static void gdi_image_hwgif_callback(kal_uint32 state, kal_uint32 frame_number);
static void gdi_image_hwgif_msg_handler(ilm_struct *ilm);

#endif /* GDI_USING_GIF */

static GDI_RESULT gdi_image_gif_get_dimension_internal(U8 *GIF_src, S32 *width, S32 *height);
static GDI_RESULT gdi_image_gif_get_dimension_file_internal(const S8 *filename, S32 *width, S32 *height);

#ifdef GDI_USING_GIF
extern KAL_ADM_ID gdi_layer_buffer_pool_id;
#endif /* GDI_USING_GIF */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_dimension_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  GIF_src     [?]     
 *  width       [?]     
 *  height      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdi_image_gif_get_dimension_internal(U8 *GIF_src, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    GIF_STATUS_ENUM gif_status;
    STFSAL fsal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FSAL_Direct_SetRamFileSize(&fsal, 14);
    if (FSAL_Open(&fsal, GIF_src, FSAL_ROMFILE) != FSAL_OK)
    {
        return GDI_FAILED;
    }
    
    gif_status = gifGetImageDimension(&fsal, (kal_uint32*)width, (kal_uint32*)height);
    if (gif_status == GIF_STATUS_OK)
    {
        ret = GDI_SUCCEED;
    }
    
    FSAL_Close(&fsal);
#endif /* GDI_USING_GIF */

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_dimension_file_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdi_image_gif_get_dimension_file_internal(const S8 *filename, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    GIF_STATUS_ENUM gif_status;
    STFSAL fsal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(FSAL_Open(&fsal, (kal_int8*)filename, FSAL_READ) != FSAL_OK)
    {
        return GDI_FAILED;
    }
    
    gif_status = gifGetImageDimension(&fsal, (kal_uint32*)width, (kal_uint32*)height);
    if (gif_status == GIF_STATUS_OK)
    {
        ret = GDI_SUCCEED;
    }
    
    FSAL_Close(&fsal);
#endif /* GDI_USING_GIF */

    return ret;
}


#ifdef GDI_USING_GIF
/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_set_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static void gdi_image_gif_set_palette(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
    {        
        for (i = 0; i < gdi_image_gif_palette_size; i++)
        {
            gdi_layer_set_palette(i, gdi_gif_local_palette[i]);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_color_format
 * DESCRIPTION
 *  transform gdi color format to gif color format
 * PARAMETERS
 *  void       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_gif_get_color_format(gdi_color_format cf, GIF_COLOR_FORMAT_ENUM *gif)
{
    switch(cf)
    {
        case GDI_COLOR_FORMAT_8:
            *gif = GIF_COLOR_FORMAT_8;
            break;
        case GDI_COLOR_FORMAT_16:
            *gif = GIF_COLOR_FORMAT_16;
            break;
        case GDI_COLOR_FORMAT_24:
            *gif = GIF_COLOR_FORMAT_24;
            break;
        case GDI_COLOR_FORMAT_32:
            *gif = GIF_COLOR_FORMAT_ARGB8888;
            break;
        case GDI_COLOR_FORMAT_32_PARGB:
            *gif = GIF_COLOR_FORMAT_ARGB8888;
            break;
        case GDI_COLOR_FORMAT_PARGB6666:
            *gif = GIF_COLOR_FORMAT_ARGB6666;
            break;
        case GDI_COLOR_FORMAT_MAINLCD:
            *gif = GIF_COLOR_FORMAT_CUSTOM_1;
            break;
        case GDI_COLOR_FORMAT_SUBLCD:
            *gif = GIF_COLOR_FORMAT_CUSTOM_2;
            break;
        default:
            return GDI_FAILED;
    }
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_gif_progress_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static S32 gdi_imgdec_gif_progress_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gdi_imgdec_gif_is_aborted && *g_gdi_imgdec_gif_is_aborted)
    {
        return 0;
    }

    if (KAL_TRUE == g_imgdec_timer_timeout_flag)
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_swgif_callback
 * DESCRIPTION
 *  message handler of gif driver
 * PARAMETERS
 *  ret     [IN]    return value from gif driver
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_swgif_callback(kal_uint32 state, kal_uint32 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_timeout_handler
 * DESCRIPTION
 *  timeout handler of gdd
 * PARAMETERS
 *  arg     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_hwgif_timeout_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_hwgif_state_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_image_gif_state = GIF_DEC_STATE_STOP;
    data.gif_state = GDI_IMAGE_ERR_DECODE_TIME_OUT;
    data.frame_number = 0;
    gdd_send_img_codec_ind(&data,sizeof(data));
    GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_GIF_HW_TIMEOUT);//[gdi_image_hwgif_timeout_handler]:Time out
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_callback
 * DESCRIPTION
 *  message handler of gif driver
 * PARAMETERS
 *  ret     [IN]    return value from gif driver
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_hwgif_callback(kal_uint32 state, kal_uint32 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_hwgif_state_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_image_gif_state = (GIF_DEC_STATE_ENUM)state;
    data.gif_state = state;
    data.frame_number = frame_number;
    gdd_send_img_codec_ind(&data,sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_msg_handler
 * DESCRIPTION
 *  msg handler of gdd, handle hwgif msg
 * PARAMETERS
 *  ilm         [IN]        the msg from gdi
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_hwgif_msg_handler(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_hwgif_state_struct *p;
    GIF_STATUS_ENUM status = GIF_STATUS_OK; 
    kal_uint32 gif_stop_handling_flag = 0;
    kal_bool gif_decoder_half_complete = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gifDecGetState(g_image_gif_decoder_hdl, &g_image_gif_state);

    p = (gdi_image_hwgif_state_struct*)(&(((gdd_img_codec_event_ind_struct*)ilm->local_para_ptr)->header));

    if (p->gif_state == GIF_DEC_STATE_STOP)
    {
        gif_decoder_half_complete = KAL_TRUE;
    }

    if (p->gif_state == GDI_IMAGE_ERR_DECODE_TIME_OUT)
    {
        gdi_image_gif_decode_result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
        g_image_gif_state = GIF_DEC_STATE_STOP;
    }

    if (g_gdi_imgdec_gif_is_aborted && *g_gdi_imgdec_gif_is_aborted)
    {   /* IMGDEC */
        gdi_image_gif_decode_result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
        g_image_gif_state = GIF_DEC_STATE_STOP;
    }

    if(!gdi_image_progress_callback())
    {
        gdi_image_gif_decode_result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
        g_image_gif_state = GIF_DEC_STATE_STOP;
    }

    GDI_BRIEF_TRACE(GDI_TRC_DECODE, GDI_GIF_HW_MSG,//[gdi_image_hwgif_msg_handler]: gif_state:%d decode_result:%d g_gif_state:%d
        p->gif_state, gdi_image_gif_decode_result, g_image_gif_state);
    switch (g_image_gif_state)
    {
    case GIF_DEC_STATE_DECODING: // do nothing, just wait HW GIF...
        break;
 
    case GIF_DEC_STATE_PAUSE:
        status = gifDecResume(g_image_gif_decoder_hdl);
        if (GIF_STATUS_OK == status)
        {
            gifDecGetState(g_image_gif_decoder_hdl, &g_image_gif_state);
        }
        else
        {
            gif_stop_handling_flag = 1;
            g_image_gif_state = GIF_DEC_STATE_STOP;
            g_image_gif_status = status;
        }
        break;
 
    case GIF_DEC_STATE_COMPLETE:
        if (p->frame_number < g_gdi_image_gif_frame_number)
        {
            status = gifDecResume(g_image_gif_decoder_hdl);
            if (GIF_STATUS_OK == status)
            {
                gifDecGetState(g_image_gif_decoder_hdl, &g_image_gif_state);
            }
            else
            {
                gif_stop_handling_flag = 1;
                g_image_gif_state = GIF_DEC_STATE_STOP;
                g_image_gif_status = status;
            }
        }
        else /* reach target frame */
        {
            /* finish */
            gif_stop_handling_flag = 1;
        }
        break;
 
    case GIF_DEC_STATE_STOP:
        if (KAL_TRUE == gif_decoder_half_complete)
        {
            if (p->frame_number < g_gdi_image_gif_frame_number)
            {
                status = gifDecResume(g_image_gif_decoder_hdl);
                if (GIF_STATUS_OK == status)
                {
                    gifDecGetState(g_image_gif_decoder_hdl, &g_image_gif_state);
                }
                else
                {
                    gif_stop_handling_flag = 1;
                    g_image_gif_state = GIF_DEC_STATE_STOP;
                    g_image_gif_status = status;
                }
            }
            else /* reach target frame */
            {
                /* finish */
                g_image_gif_state = GIF_DEC_STATE_COMPLETE;
                gif_stop_handling_flag = 1;
            }
        }
        else
        {
            gif_stop_handling_flag = 1;   
        }
        break;
    default:
        gif_stop_handling_flag = 1;
        break;
    }
 
    if (gif_stop_handling_flag)
    {
        gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
        gifDecStop(g_image_gif_decoder_hdl);
        GDD_SET_EVENT(GDD_EVENT_WAIT_DECODING);
    }
}

#endif /* GDI_USING_GIF */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_delay
 * DESCRIPTION
 *  get frame delay of each frame of an gif
 * PARAMETERS
 *  flag                [IN]    represent the data_ptr is file name or not image data
 *  data_ptr            [IN]    file name or image data
 *  img_size            [IN]    0 or size of data_ptr 
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   delay time of each frame
 *  max_frame_count     [IN]    the size of frame_delay_array
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_frame_delay(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            S32 *frame_count,
            U32 *frame_delay_array,
            U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_gif_get_frame_delay_from_file((S8*)data_ptr, (S32*)frame_count, frame_delay_array, max_frame_count);
    }
    else
    {
        return gdi_image_gif_get_frame_delay_from_mem(data_ptr, img_size, (S32*) frame_count, frame_delay_array, max_frame_count);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_delay_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename            [IN]    image file name
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   delay time of each frame
 *  max_frame_count     [IN]    the size of frame_delay_array
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_frame_delay_from_file(
                const S8 *filename, 
                S32 *frame_count, 
                U32 *frame_delay_array, 
                U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    GIF_STATUS_ENUM status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_file)

    *frame_count = 0;

    GDI_IMGDEC_HW_LOCK();
    if(FSAL_Open(&fsal, (kal_int8*)filename, FSAL_READ) != FSAL_OK)
    {
        GDI_IMGDEC_HW_UNLOCK();
        GDI_RETURN(GDI_FAILED);
    }
	status = gifGetFrameDelay(
	          &fsal,
	          frame_count,
	          frame_delay_array,
	          max_frame_count);
	FSAL_Close(&fsal);
	if (GIF_STATUS_OK == status)
	{
	    ret = GDI_SUCCEED;
	}

    GDI_IMGDEC_HW_UNLOCK();
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_file)
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_delay_from_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_ptr            [IN]    file name or image data
 *  size                [IN]    0 or size of data_ptr 
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   delay time of each frame
 *  max_frame_count     [IN]    the size of frame_delay_array        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_frame_delay_from_mem(
                U8 *data_ptr, 
                U32 size, 
                S32 *frame_count, 
                U32 *frame_delay_array, 
                U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    GIF_STATUS_ENUM status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_mem)

    *frame_count = 0;

    GDI_IMGDEC_HW_LOCK();
    FSAL_Direct_SetRamFileSize(&fsal, size);
    if(FSAL_Open(&fsal, data_ptr, FSAL_ROMFILE) != FSAL_OK)
    {
        GDI_IMGDEC_HW_UNLOCK();
        GDI_RETURN(GDI_FAILED);
    }

    status = gifGetFrameDelay(
	          &fsal,
	          frame_count,
	          frame_delay_array,
	          max_frame_count);
	FSAL_Close(&fsal);
    if (GIF_STATUS_OK == status)
    {
        ret = GDI_SUCCEED;
    }

    GDI_IMGDEC_HW_UNLOCK();
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_mem)
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_disposal
 * DESCRIPTION
 *  get frame disposal of each frame of an gif
 * PARAMETERS
 *  flag                [IN]    represent the data_ptr is file name or not image data
 *  data_ptr            [IN]    file name or image data
 *  img_size            [IN]    0 or size of data_ptr 
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   disposal of each frame
 *  max_frame_count     [IN]    the size of frame_disposal_array
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_disposal(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            S32 *frame_count,
            GDI_GIF_DISPOSAL_ENUM *frame_disposal_array,
            U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_gif_get_disposal_from_file((S8*)data_ptr, (S32*)frame_count, frame_disposal_array, max_frame_count);
    }
    else
    {
        return gdi_image_gif_get_disposal_from_mem(data_ptr, img_size, (S32*) frame_count, frame_disposal_array, max_frame_count);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_disposal_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename            [IN]    image file name
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   dispoal of each frame
 *  max_frame_count     [IN]    the size of frame_disposal_array
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_disposal_from_file(
                const S8 *filename, 
                S32 *frame_count, 
                GDI_GIF_DISPOSAL_ENUM *frame_disposal_array, 
                U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    GIF_STATUS_ENUM gif_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_disposal_from_file)

    GDI_IMGDEC_HW_LOCK();
    if(FSAL_Open(&fsal, (kal_int8*)filename, FSAL_READ) != FSAL_OK)
    {
        GDI_IMGDEC_HW_UNLOCK();
        GDI_RETURN(GDI_FAILED);
    }
	gif_status = gifGetAllFrameDisposalMethod(
	                 &fsal,
	                 frame_count,
	                 (GIF_DISPOSAL_METHOD_ENUM*)frame_disposal_array,
	                 max_frame_count);
	FSAL_Close(&fsal);
    GDI_IMGDEC_HW_UNLOCK();
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_disposal_from_file)

    if (GIF_STATUS_OK == gif_status)
    {
        ret = GDI_SUCCEED;
    }
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_disposal_from_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_ptr            [IN]    file name or image data
 *  size                [IN]    0 or size of data_ptr 
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   disposal_ of each frame
 *  max_frame_count     [IN]    the size of frame_disposal_array        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_disposal_from_mem(
                U8 *data_ptr, 
                U32 size, 
                S32 *frame_count, 
                GDI_GIF_DISPOSAL_ENUM *frame_disposal_array,
                U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    GIF_STATUS_ENUM gif_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_disposal_from_mem)
    GDI_IMGDEC_HW_LOCK();
    FSAL_Direct_SetRamFileSize(&fsal, size);
    if(FSAL_Open(&fsal, data_ptr, FSAL_ROMFILE) != FSAL_OK)
    {
        GDI_IMGDEC_HW_UNLOCK();
        GDI_RETURN(GDI_FAILED);
    }
    gif_status = gifGetAllFrameDisposalMethod(
	                 &fsal,
	                 frame_count,
	                 (GIF_DISPOSAL_METHOD_ENUM*)frame_disposal_array,
	                 max_frame_count);
	FSAL_Close(&fsal);
    GDI_IMGDEC_HW_UNLOCK();
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_disposal_from_mem)

    if (GIF_STATUS_OK == gif_status)
    {
        ret = GDI_SUCCEED;
    }
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  GIF_src             [?]         
 *  size                [IN]        
 *  frame_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_draw(S32 ox, S32 oy, U8 *GIF_src, U32 size, U16 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    gdi_handle act_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_draw)

    gdi_layer_get_active(&act_layer);
    gdi_image_gif_codec_flag = gdi_image_codec_get_flag();
    ret = gdi_imgdec_gif_draw_internal(
              act_layer,
              ox,
              oy,
              0,
              0,
              GIF_src,
              size,
              frame_number,
              (BOOL)0, // is_file
              gdi_act_layer_info->source_key_enable, // src_key_enable
              gdi_act_layer_info->source_key, // src_key_value
              NULL,
              gdi_image_gif_codec_flag,
              0);
    GDI_TRACE(GDI_TRC, GDI_TRC_6,//"gdi_image_gif_draw src=%x,size=%d,x=%d,y=%d,frame_number=%d ret=%d",
              GIF_src,size,ox,oy,frame_number,ret);

#ifdef GDI_USING_GIF
    if (ret == GDI_SUCCEED)
    {
        gdi_image_gif_set_palette();
    }
#endif /* GDI_USING_GIF */
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_draw)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_draw_resized
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  GIF_src             [?]         
 *  size                [IN]        
 *  frame_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_draw_resized(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *GIF_src,
            U32 size,
            U16 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    gdi_handle act_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_draw_resized)

    gdi_layer_get_active(&act_layer);
    gdi_image_gif_codec_flag = gdi_image_codec_get_flag();
    ret = gdi_imgdec_gif_draw_internal(
              act_layer,
              ox,
              oy,
              resized_width,
              resized_height,
              GIF_src,
              size,
              frame_number,
              (BOOL)0, // is_file
              gdi_act_layer_info->source_key_enable, // src_key_enable
              gdi_act_layer_info->source_key, // src_key_value
              NULL,
              gdi_image_gif_codec_flag,
              0);

    GDI_TRACE(GDI_TRC, GDI_TRC_8,//"gdi_image_gif_draw_resized src=%x,size=%d,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d",
              GIF_src,size,ox,oy,resized_width,resized_height,frame_number,ret);

#ifdef GDI_USING_GIF
    if (ret == GDI_SUCCEED)
    {
        gdi_image_gif_set_palette();
    }
#endif /* GDI_USING_GIF */

    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_draw_resized)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_draw_with_background_color
 * DESCRIPTION
 *  Displays a given frame of the GIF file, and full layer will be filled with background color
 * PARAMETERS
 *  GIF_src                 [?]         
 *  size                    [IN]        
 *  frame_number            [IN]        Frame number to load for animated GIF.
 *  background_color        [IN]        
 *  is_transparent          [?]         
 *  file(?)                 [IN]        The GIF file in bytestream format
 *  oy(?)                   [IN]        Position at which the GIF image is to be displayed
 *  ox(?)                   [IN]        Position at which the GIF image is to be displayed
 *  color_depth(?)          [IN]        Output color depth.
 * RETURNS
 *  0  if GIF_load failed (invalid GIF image)
 *  1  if GIF_load is successful
 *****************************************************************************/
GDI_RESULT gdi_image_gif_draw_with_background_color(
            U8 *GIF_src,
            U32 size,
            U16 frame_number,
            gdi_color background_color,
            BOOL *is_transparent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    gdi_handle act_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_draw_with_background_color)

    gdi_image_gif_codec_flag = gdi_image_codec_get_flag();
    gdi_layer_get_active(&act_layer);

    gdi_image_gif_reset();  

    /* fill the frame buffer with background color */
    GDI_ASSERT(gdi_act_layer->bits_per_pixel == 16);
    gdi_memset16((U8*) gdi_act_layer->buf_ptr, (U16) background_color, gdi_act_layer->layer_size);     /* FIXME */

    ret = gdi_imgdec_gif_draw_internal(
              act_layer,
              0,
              0,
              0,
              0,
              GIF_src,
              size,
              frame_number,
              (BOOL)0, // is_file
              KAL_TRUE, // src_key_enable
              background_color, // src_key_value
              NULL,
              gdi_image_gif_codec_flag,
              0);

    GDI_TRACE(GDI_TRC, GDI_TRC_10,//"gdi_image_gif_draw_with_background_color(sw) src=%x,size=%d,frame_number=%d ret=%d",
              GIF_src,size,frame_number,ret);
    
#ifdef GDI_USING_GIF
    if (ret == GDI_SUCCEED)
    {
        gdi_image_gif_set_palette();
    }
#endif /* GDI_USING_GIF */

    gdi_image_gif_codec_flag = 0;

    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_draw_with_background_color)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_draw_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  filename            [IN]        
 *  frame_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_draw_file(S32 ox, S32 oy, const S8 *filename, U16 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle act_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_draw_file)
    
    gdi_image_gif_codec_flag = gdi_image_codec_get_flag();
    gdi_layer_get_active(&act_layer);
    
    ret = gdi_imgdec_gif_draw_internal(
              act_layer,
              ox,
              oy,
              0,
              0,
              (U8 *)filename,
              0,
              frame_number,
              (BOOL)1, // is_file
              gdi_act_layer_info->source_key_enable, // src_key_enable
              gdi_act_layer_info->source_key, // src_key_value
              NULL,
              gdi_image_gif_codec_flag,
              0);

//    GDI_TRACE(GDI_TRC, GDI_TRC_12,//"gdi_image_gif_draw_file(sw) id=%x,x=%d,y=%d,frame_number=%d ret=%d",
//              cache_id,ox,oy,frame_number,ret_sw);

#ifdef GDI_USING_GIF
    if (ret == GDI_SUCCEED)
    {
        gdi_image_gif_set_palette();
    }
#endif /* GDI_USING_GIF */

    if (ret == GDI_FAILED)
    {
        gdi_image_gif_reset_entry_file(filename);
        break;
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_draw_file)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_draw_resized_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  filename            [IN]        
 *  frame_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_draw_resized_file(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            const S8 *filename,
            U16 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle act_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_draw_file)
    
    gdi_image_gif_codec_flag = gdi_image_codec_get_flag();
    gdi_layer_get_active(&act_layer);
    
    ret = gdi_imgdec_gif_draw_internal(
              act_layer,
              ox,
              oy,
              resized_width,
              resized_height,              
              (U8 *)filename,
              0,
              frame_number,
              (BOOL)1, // is_file
              gdi_act_layer_info->source_key_enable, // src_key_enable
              gdi_act_layer_info->source_key, // src_key_value
              NULL,
              gdi_image_gif_codec_flag,
              0);

//    GDI_TRACE(GDI_TRC, GDI_TRC_12,//"gdi_image_gif_draw_file(sw) id=%x,x=%d,y=%d,frame_number=%d ret=%d",
//              cache_id,ox,oy,frame_number,ret_sw);

#ifdef GDI_USING_GIF
    if (ret == GDI_SUCCEED)
    {
        gdi_image_gif_set_palette();
    }
#endif /* GDI_USING_GIF */

    if (ret == GDI_FAILED)
    {
        gdi_image_gif_reset_entry_file(filename);
        break;
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_draw_file)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  GIF_src     [?]     
 *  width       [?]     
 *  height      [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_dimension(U8 *GIF_src, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = gdi_image_gif_get_dimension_internal(GIF_src, width, height);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_dimension_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_dimension_file(const S8 *filename, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = gdi_image_gif_get_dimension_file_internal(filename, width, height);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_check_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  frame_count     [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_check_animation(U8 *data_ptr, U32 size, MMI_BOOL *is_anim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    U32 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *is_anim = MMI_FALSE;

    FSAL_Direct_SetRamFileSize(&fsal, size);
    if(FSAL_Open(&fsal, data_ptr, FSAL_ROMFILE) != FSAL_OK)
    {
        return GDI_FAILED;
    }

	if (GIF_STATUS_OK == gifCheckAnimation(&fsal, &temp))
	{
	    ret = GDI_SUCCEED;
	    if (temp > 0)
	    {
	        *is_anim = MMI_TRUE;
	    }
	}
	FSAL_Close(&fsal);

#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_check_animation_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  is_anim     [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_check_animation_file(const S8 *filename, MMI_BOOL *is_anim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    U32 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *is_anim = MMI_FALSE;
    if(FSAL_Open(&fsal, (kal_int8*)filename, FSAL_READ) != FSAL_OK)
    {
        return GDI_FAILED;
    }

	if (GIF_STATUS_OK == gifCheckAnimation(&fsal, &temp))
	{
	    ret = GDI_SUCCEED;
	    if (temp > 0)
	    {
	        *is_anim = MMI_TRUE;
	    }
	}
	FSAL_Close(&fsal);

#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  GIF_src         [?]         
 *  size            [IN]        
 *  frame_count     [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_frame_count(U8 *GIF_src, U32 size, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    U32 frame_delay_array[2];
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_gif_get_frame_delay_from_mem(
              GIF_src, 
              size, 
              frame_count, 
              frame_delay_array, 
              2);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_count_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  frame_count     [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_frame_count_file(const S8 *filename, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    U32 frame_delay_array[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_gif_get_frame_delay_from_file(
              filename, 
              frame_count, 
              frame_delay_array, 
              2);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_gif_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // TODO: IMGDEC LOCK?
#ifdef GDI_USING_GIF
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_reset)
    
    gifDecResetCache(GIF_DEC_TYPE_SW);
    gifDecResetCache(GIF_DEC_TYPE_HW);
    
#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
    gdi_image_single_bank_cache_reset();
#endif
	
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_reset)
#endif /* GDI_USING_GIF */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_reset_entry_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_gif_reset_entry_file(const S8* filename)
{
#ifdef GDI_USING_GIF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STFSAL fsal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_reset_entry_file)

    if(FSAL_Open(&fsal, (kal_int8*)filename, FSAL_READ) != FSAL_OK)
    {
        GDI_RETURN_VOID;
    }

    gifDecResetCacheEntry(&fsal, GIF_DEC_TYPE_SW);
	FSAL_Close(&fsal);

//#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
//    gdi_image_single_bank_cache_reset_entry(src, size);
//#endif	
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_reset_entry_file)
#endif /* GDI_USING_GIF */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_reset_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_gif_reset_entry(U8* src, U32 size)
{
#ifdef GDI_USING_GIF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STFSAL fsal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_reset_entry)

    FSAL_Direct_SetRamFileSize(&fsal, size);
    if(FSAL_Open(&fsal, src, FSAL_ROMFILE) != FSAL_OK)
    {
        GDI_RETURN_VOID;
    }

    gifDecResetCacheEntry(&fsal, GIF_DEC_TYPE_SW);
	FSAL_Close(&fsal);

#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
    gdi_image_single_bank_cache_reset_entry(src, size);
#endif	
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_reset_entry)
#endif /* GDI_USING_GIF */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_transparent_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 gdi_image_gif_get_transparent_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_GIF
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_transparent_index)
    ret = gdi_image_gif_transparent_index;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_transparent_index)
#else
    GDI_ASSERT(0);
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_palette_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gdi_image_gif_get_palette_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_GIF
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_palette_size)
    ret = gdi_image_gif_palette_size;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_palette_size)
#else
    GDI_ASSERT(0);
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_convert_disposal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static GDI_GIF_DISPOSAL_ENUM gdi_image_gif_convert_disposal(
                              GIF_DISPOSAL_METHOD_ENUM gif_disposal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_GIF_DISPOSAL_ENUM disposal = GDI_GIF_DISPOSAL_RSVD; //warning fix

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(gif_disposal)
    {
        case GIF_DISPOSAL_NO_ACTION:
              disposal = GDI_GIF_DISPOSAL_NO_ACTION;
              break;
        case GIF_DISPOSAL_NOT_DISPOSAL:
              disposal = GDI_GIF_DISPOSAL_NOT_DISPOSAL;
              break;
        case GIF_DISPOSAL_RESTORE_BG:
              disposal = GDI_GIF_DISPOSAL_RESTORE_BG;
              break;
        case GIF_DISPOSAL_RESTORE_PRE:
              disposal = GDI_GIF_DISPOSAL_RESTORE_PRE;
              break;
        case GIF_DISPOSAL_RSVD:
              disposal = GDI_GIF_DISPOSAL_RSVD;
              break;
        default:
              GDI_ASSERT(0);
    }
    return disposal;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_disposal_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdi_image_gif_get_frame_disposal_from_file(
                              const S8 *filename,
                              S32 frame_index,
                              GDI_GIF_DISPOSAL_ENUM *disposal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    GIF_DISPOSAL_METHOD_ENUM temp_disposal;
    GIF_STATUS_ENUM gif_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_file)

    GDI_IMGDEC_HW_LOCK();
    if(FSAL_Open(&fsal, (kal_int8*)filename, FSAL_READ) != FSAL_OK)
    {
        GDI_IMGDEC_HW_UNLOCK();
        GDI_RETURN(GDI_FAILED);
    }
    gif_status = gifGetFrameNDisposalMethod(
                     NULL,
	                 &fsal,
	                 frame_index,
	                 &temp_disposal);
    
	FSAL_Close(&fsal);

	if (GIF_STATUS_OK == gif_status)
    {
        ret = GDI_SUCCEED;
        *disposal = gdi_image_gif_convert_disposal(temp_disposal);
    }
    GDI_IMGDEC_HW_UNLOCK();
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_file)
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_frame_disposal_from_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static GDI_RESULT gdi_image_gif_get_frame_disposal_from_mem(
                   U8 *data_ptr,
                   U32 size,
                   S32 frame_index,
                   GDI_GIF_DISPOSAL_ENUM *disposal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
#ifdef GDI_USING_GIF
    STFSAL fsal;
    GIF_DISPOSAL_METHOD_ENUM temp_disposal;
    GIF_STATUS_ENUM gif_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_file)

    GDI_IMGDEC_HW_LOCK();
    FSAL_Direct_SetRamFileSize(&fsal, size);
    if(FSAL_Open(&fsal, data_ptr, FSAL_ROMFILE) != FSAL_OK)
    {
        GDI_IMGDEC_HW_UNLOCK();
        GDI_RETURN(GDI_FAILED);
    }
    gif_status = gifGetFrameNDisposalMethod(
                     NULL,
	                 &fsal,
	                 frame_index,
	                 &temp_disposal);
    
	FSAL_Close(&fsal);

	if (GIF_STATUS_OK == gif_status)
    {
        ret = GDI_SUCCEED;
        *disposal = gdi_image_gif_convert_disposal(temp_disposal);
    }
    GDI_IMGDEC_HW_UNLOCK();
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_frame_delay_from_file)
#endif /* GDI_USING_GIF */
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_next_frame_disposal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_frame_disposal(
                       U32 flag,
                       U8 *data_ptr,
                       U32 img_size,
                       S32 frame_index,
                       GDI_GIF_DISPOSAL_ENUM *disposal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_gif_get_frame_disposal_from_file((S8*)data_ptr, frame_index, disposal);
    }
    else
    {
        return gdi_image_gif_get_frame_disposal_from_mem(data_ptr, img_size, frame_index, disposal);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_next_frame_disposal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
GDI_GIF_DISPOSAL_ENUM gdi_image_gif_get_next_frame_disposal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_GIF_DISPOSAL_ENUM disposal;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_GIF
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_get_next_frame_disposal)
    disposal = gdi_image_gif_convert_disposal(gdi_image_gif_next_frame_disposal);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_get_next_frame_disposal)
#else
    GDI_ASSERT(0);
#endif /* GDI_USING_GIF */
    return disposal;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_draw_handler
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
GDI_RESULT gdi_image_gif_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 frame_number = (U16) frame_pos;
    GDI_RESULT result = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_draw_handler)
    
    gdi_image_gif_codec_flag = flag;
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        if (w && h)
        {
            result = gdi_image_gif_draw_resized_file(x, y, w, h, (S8*) data_ptr, frame_number);
        }
        else
        {
            result = gdi_image_gif_draw_file(x, y, (S8*) data_ptr, frame_number);
        }
    }
    else
    {
        if (w && h)
        {
            result = gdi_image_gif_draw_resized(x, y, w, h, data_ptr, img_size, frame_number);
        }
        else
        {
            result = gdi_image_gif_draw(x, y, data_ptr, img_size, frame_number);
        }
    }
    gdi_image_gif_codec_flag = 0;

    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_draw_handler)
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_dimension_handler
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
GDI_RESULT gdi_image_gif_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_gif_get_dimension_file((S8*) data_ptr, width, height);
    }
    else
    {
        return gdi_image_gif_get_dimension(data_ptr, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_get_pos_info_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  quick_mode      [IN]        
 *  total_pos       [?]         
 *  pos_type        [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_get_pos_info_handler(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            BOOL quick_mode,
            S32 *total_pos,
            gdi_anim_pos_type_enum *pos_type)
{
    *pos_type = GDI_ANIM_POS_TYPE_INDEX;
        
    if (!quick_mode)
    {
        if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        {
            return gdi_image_gif_get_frame_count_file((S8*) data_ptr, (S32*) total_pos);
        }
        else
        {
            return gdi_image_gif_get_frame_count(data_ptr, img_size, (S32*) total_pos);
        }
    }
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_gif_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_is_gif_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 f;
    U8 buf[3];
    kal_uint32 len;
    kal_int32 result;

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
    
    result = DRM_read_file(f, buf, 3, &len);

    DRM_close_file(f);

    if (result == FS_NO_ERROR)
        if (len == 3)
            if (buf[0] == 'G' && buf[1] == 'I' && buf[2] == 'F')
            {
                return GDI_SUCCEED;
            }
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_gif_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  output_layer_handle       [IN]
 *  ox                        [IN]
 *  oy                        [IN]
 *  resized_width             [IN]
 *  resized_height            [IN]
 *  src                       [IN]
 *  size                      [IN]
 *  is_file                   [IN]
 *  is_aborted                [IN]
 *  flag                      [IN]
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_imgdec_gif_draw_internal(
            gdi_handle output_layer_handle,
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            U16 frame_number,
            BOOL is_file,
            kal_bool src_key_enable,
            kal_uint32 src_key_value,
            BOOL *is_aborted,
            U32 flag,
            S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret_value = GDI_FAILED;

#ifdef GDI_USING_GIF
    GIF_DEC_TYPE_ENUM decode_type = GIF_DEC_TYPE_HW;
    S32 width, height, display_width, display_height;
    MMI_BOOL is_resize = MMI_FALSE;

	STFSAL gif_src;
    gdi_layer_struct *out_layer;
    kal_bool force_to_use_swgif = KAL_FALSE;
    void *fsalCacheAddr = NULL, *readBuffer = NULL;
    kal_bool is_system_init = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_TRACE(GDI_TRC_DECODE, GDI_GIF_ENTER,//[gdi_imgdec_gif_draw_internal]: Enter - out_layer:%d x:%d y:%d w:%d h:%d src:%d is_file:%d
        output_layer_handle, ox, oy, resized_width, resized_height, src, is_file);
    GDI_IMGDEC_HW_LOCK();
    /* It use sw gif to decode the dimension. If can not use sw decode,
     * it can return directly.
     */
    if (is_file)
    {
        ret_value = gdi_image_gif_get_dimension_file_internal((S8 *)src, &width, &height);
    }
    else
    {
        ret_value = gdi_image_gif_get_dimension_internal(src, &width, &height);
    }
    if (ret_value != GDI_SUCCEED)
    {
        GDI_IMGDEC_HW_UNLOCK();
        return ret_value;
    }

    gdi_image_gif_decode_result = GDI_SUCCEED;
    g_gdi_imgdec_gif_is_aborted = is_aborted;
    g_gdi_image_gif_frame_number = frame_number;
    out_layer = (gdi_layer_struct*)output_layer_handle;
    is_system_init = kal_query_systemInit();

    /* decide whether we need to resize gif */
    if ((resized_width == 0) && (resized_height == 0))
    {
        resized_width = width;
        resized_height = height;
    }
    
    do
    {
        is_resize = MMI_FALSE;
        force_to_use_swgif = (flag & GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE) ? KAL_TRUE : KAL_FALSE;
        /* Get the gif decoder. If HW decode not exist, we will try to use SW. */
        if (force_to_use_swgif == KAL_FALSE)
        {
            decode_type = GIF_DEC_TYPE_HW;
            g_image_gif_status = gifDecGetHandle(decode_type, &g_image_gif_decoder_hdl);
            if (GIF_STATUS_OK != g_image_gif_status)
            {
                force_to_use_swgif = KAL_TRUE;
            }
        }
        if (force_to_use_swgif == KAL_TRUE)
        {
            decode_type = GIF_DEC_TYPE_SW;
            g_image_gif_status = gifDecGetHandle(decode_type, &g_image_gif_decoder_hdl);
        }
        if (GIF_STATUS_OK != g_image_gif_status)
        {
            ret_value = GDI_IMAGE_ERR_NO_DECODER;
            break;
        }

        if (flag & GDI_IMAGE_CODEC_FLAG_DISABLE_CACHE_SWITCH)
        {
            gifDecSetDstBufferSwitchBehavior(g_image_gif_decoder_hdl, GFX_CACHE_SWITCH_BEHAVIOR_NOT_SWITCH);
        }       

        do /* Use this do loop to decode for HW/SW gif */
        {
            /* Check whether we should resize the image */
            if ((resized_width != width) || (resized_height != height))
            {
                is_resize = MMI_TRUE;
            }
            g_image_gif_status = gifDecIsResizeSupport(decode_type);
            if (GIF_STATUS_OK != g_image_gif_status)
            {
                /* If HW GIF not support resize, we will use SW */
                if ((decode_type == GIF_DEC_TYPE_HW) && (MMI_TRUE == is_resize))
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
                is_resize = MMI_FALSE;
                display_width = width;
                display_height = height;
            }
            else if ((MMI_TRUE == is_resize) &&
                     !(flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT))
            {
                display_width = resized_width;
                display_height = resized_height;
            }
            else
            {
                display_width = width;
                display_height = height;
            }

            if (flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
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
                    ox,
                    ox,
                    resized_width,
                    resized_height,
                    width,
                    height,
                    &ox,
                    &oy,
                    &display_width,
                    &display_height);
            }

            /* Prepare fsal handle */
            {
                FSAL_Status file_status;
                memset(&gif_src, 0 , sizeof(STFSAL));
                /* Use this assert to check whether we have gif file not closed */
                GDI_ASSERT(KAL_FALSE == g_image_gif_file_opened);
                if (is_file)
                {
                    /* Use this assert to check whether we have gif file not closed */
                    file_status = FSAL_Open(&gif_src, src, FSAL_READ);            
                }
                else
                {
                    FSAL_Direct_SetRamFileSize(&gif_src, size);         
                    file_status = FSAL_Open(&gif_src, (void *)src, FSAL_ROMFILE);
                }
                /* Set source file */
                if (FSAL_OK != file_status) 
                {
                    ret_value = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
                    break;
                }
                else
                {
                    g_image_gif_file_opened = KAL_TRUE;
                    g_image_gif_status = gifDecSetSourceFile(g_image_gif_decoder_hdl, &gif_src);
                }
                
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set fsal cache read buffer */
            {
                kal_uint32 fsalCacheSizeBest = 0, fsalCacheSizeMinimum = 0, fsalCacheSize = 0;
                kal_uint32 readbufferSizeBest = 0, readbufferSizeMinimum = 0, readbufferSize = 0;
    
                g_image_gif_status = gifDecQueryFileBuffer(
                                         g_image_gif_decoder_hdl,
                                         &readbufferSizeBest,
                                         &readbufferSizeMinimum,
                                         &fsalCacheSizeBest,
                                         &fsalCacheSizeMinimum);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
    
                /* Malloc read buffer */
                readbufferSize = readbufferSizeBest;
                {
                    while (1)
                    {
                            if (decode_type == GIF_DEC_TYPE_HW)
                            {
                                readBuffer = (void *)gdi_alloc_ext_mem(readbufferSize);
                            }
                            else
                            {
                                readBuffer = (void *)gdi_alloc_ext_mem_cacheable(readbufferSize);
                            }
                        if ((readBuffer != NULL) || (readbufferSize == readbufferSizeMinimum))
                        {
                            break;
                        }                
                        readbufferSize /= 2;
                        if (readbufferSize < readbufferSizeMinimum)
                        {
                            readbufferSize = readbufferSizeMinimum;
                        }
                    }
    
                    if ((NULL == readBuffer) && (0 != readbufferSize))
                    {
                        ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                        g_image_gif_status = GIF_STATUS_DEC_NO_READ_BUFFER;
                        break;
                    }
                }
    
                /* fsalCacheSize can be 0, it will not effect the GIF decode, but
                 * it will effect the GIF file access speed if that file is in disc.
                 */
                fsalCacheSize = fsalCacheSizeBest;
                while (1)
                {
                        if (decode_type == GIF_DEC_TYPE_HW)
                        {
                             fsalCacheAddr = (void *)gdi_alloc_ext_mem(fsalCacheSize);
                        }
                        else
                        {
                             fsalCacheAddr = (void *)gdi_alloc_ext_mem_cacheable(fsalCacheSize);
                        }
                    if ((fsalCacheAddr != NULL) || (fsalCacheSize == fsalCacheSizeMinimum))
                    {
                        break;
                    }                
                    fsalCacheSize /= 2;
                    if (fsalCacheSize < fsalCacheSizeMinimum)
                    {
                        fsalCacheSize = fsalCacheSizeMinimum;
                    }
                }
                /* Cache buffer will only affect the read file speed of GIF, but it 
                 * will not affect the decode of GIF.
                 */
                if (NULL == fsalCacheAddr)
                {
                    fsalCacheSize = 0;
                    fsalCacheAddr = NULL;
                }
    
                g_image_gif_status = gifDecSetFileBuffer(
                                         g_image_gif_decoder_hdl,
                                         readBuffer,
                                         readbufferSize, 
                                         fsalCacheAddr,
                                         fsalCacheSize);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }


            /* Set the dest RGB buffer info */
            {
                GIF_COLOR_FORMAT_ENUM dest_color_format;
    
                /* Set the Dst RGB buffer info */
                ret_value = gdi_image_gif_get_color_format(out_layer->vcf, &dest_color_format);
                if (GDI_SUCCEED != ret_value)
                {
                    ret_value = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                    g_image_gif_status = GIF_STATUS_OK;
                    break;
                }
                g_image_gif_status = gifDecSetDstRGBBufferInfo(
                                         g_image_gif_decoder_hdl,
                                         out_layer->buf_ptr,
                                         out_layer->layer_size,
                                         out_layer->width,
                                         out_layer->height,
                                         dest_color_format);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set working buffer */
            {
                kal_uint32 internal_mem_size = 0;
                kal_uint32 external_mem_size = 0;
                g_image_gif_status = gifDecQueryWorkingMemory(
                                         g_image_gif_decoder_hdl,
                                         &internal_mem_size,
                                         &external_mem_size);
                if (internal_mem_size != 0)
                {
                    if(is_system_init == KAL_TRUE)
                    {
                        g_image_gif_int_mem = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(gdi_layer_buffer_pool_id, internal_mem_size);
                    }
                    else
                    {
                        g_image_gif_int_mem = (void *)med_alloc_int_mem(internal_mem_size);
        	    }
                    if (!g_image_gif_int_mem)
                    {
                        ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                        g_image_gif_status = GIF_STATUS_OK;
                        break;
                    }
                }
    
                    if (GIF_DEC_TYPE_HW == decode_type)
                    {
                        g_image_gif_ext_mem = (void *)gdi_alloc_ext_mem(external_mem_size);
                    }
                    else
                    {
                        g_image_gif_ext_mem = (void *)gdi_alloc_ext_mem_cacheable(external_mem_size);
                    }
                if (!g_image_gif_ext_mem)
                {
                    ret_value = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                    g_image_gif_status = GIF_STATUS_OK;
                    break;
                }
    
                memset(g_image_gif_ext_mem, 0, external_mem_size);
                memset(g_image_gif_int_mem, 0, internal_mem_size);           
                       
                g_image_gif_status = gifDecSetWorkingMemory(
                                         g_image_gif_decoder_hdl,
                                         g_image_gif_int_mem,
                                         internal_mem_size,
                                         g_image_gif_ext_mem,
                                         external_mem_size);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set the transparent color */
            {
                kal_bool transparent_enable = KAL_TRUE;
                if (flag & GDI_IMAGE_CODEC_FLAG_DISABLE_SRC_KEY)
                {
                    transparent_enable = KAL_FALSE;
                }
                g_image_gif_status = gifDecSetTransparentEnable(
                                         g_image_gif_decoder_hdl,
                                         transparent_enable);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set source color */
            {
                g_image_gif_status = gifDecSetSrcKey(
                                         g_image_gif_decoder_hdl,
                                         src_key_enable,
                                         src_key_value);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set the dest window and dest clip window */
            {
                g_image_gif_status = gifDecSetDstClipWindow(
                                         g_image_gif_decoder_hdl,
                                         out_layer->clipx1,
                                         out_layer->clipy1,
                                         out_layer->clipx2 - out_layer->clipx1 + 1,
                                         out_layer->clipy2 - out_layer->clipy1 + 1);
                g_image_gif_status = gifDecSetDstWindow(
                                         g_image_gif_decoder_hdl,
                                         ox,
                                         oy,
                                         display_width,
                                         display_height); 
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set Hook interrupt call back function */
            {
                if (GIF_DEC_TYPE_HW == decode_type)
                { 
                    gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, gdi_image_hwgif_msg_handler);
                    g_image_gif_status = gifDecSetCallbackFunction(
                                             g_image_gif_decoder_hdl,
                                             &gdi_image_hwgif_callback);
                }
                else if (GIF_DEC_TYPE_SW == decode_type) 
                {
                    g_image_gif_status = gifDecSetCallbackFunction(
                                             g_image_gif_decoder_hdl,
                                             &gdi_image_swgif_callback);
                    if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
                    {
                        g_image_gif_status = gifDecSetCheckAbortFunction(
                                                 g_image_gif_decoder_hdl,
                                                 gdi_imgdec_gif_progress_callback);
                    }
                    else
                    {
                        g_image_gif_status = gifDecSetCheckAbortFunction(
                                                 g_image_gif_decoder_hdl,
                                                 gdi_image_progress_callback);
                    }
                }
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Set GIF plaette color format */
            if (out_layer->vcf == GDI_COLOR_FORMAT_8)
            {
                GIF_COLOR_FORMAT_ENUM palette_color_format;    
                ret_value = gdi_image_gif_get_color_format(gdi_image_gif_palette_color_format, &palette_color_format);
                if (GDI_SUCCEED != ret_value)
                {
                    ret_value = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                    g_image_gif_status = GIF_STATUS_OK;
                    break;
                }
                g_image_gif_status = gifDecSetColorPaletteFormat(
                                         g_image_gif_decoder_hdl,
                                         palette_color_format);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    ret_value = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                    break;
                }
            }

            /* Start GIF decode */
            {
                if (GIF_DEC_TYPE_HW == decode_type)
                {
                    /* start gdd */
                    gdd_start_timer(
                        GDD_TIMER_IMAGE_CODEC_TIMEOUT,
                        GDI_HW_GIF_CODEC_WAITING_TIME,
                        gdi_image_hwgif_timeout_handler,
                        0);
                }

                g_image_gif_status = gifDecStart(g_image_gif_decoder_hdl, frame_number);
                GDI_TRACE(GDI_TRC_DECODE, GDI_GIF_START,//[gdi_imgdec_gif_draw_internal]: Start - decoder:%d frame:%d status:%d
                    decode_type, frame_number, g_image_gif_status);
                if (GIF_STATUS_OK != g_image_gif_status)
                {
                    if (GIF_DEC_TYPE_HW == decode_type)
                    {
                        gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
                        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
                        gifDecStop(g_image_gif_decoder_hdl);
                    }
                    else
                    {
                        gifDecStop(g_image_gif_decoder_hdl);
                    }

                    if (g_image_gif_status == GIF_STATUS_OUTPUT_WINDOW_NO_INTERSECTION)
                    {
                        ret_value = GDI_SUCCEED;
                    }
                    else
                    {
                        ret_value = GDI_IMAGE_ERR_DECODE_FAILED;
                    }
                    break;
                }
            }

            /* Handle GIF decode */
            {
                if (GIF_DEC_TYPE_HW == decode_type)
                {
                    /* wait gdd finish drawing and set the event */
                    GDD_WAIT_EVENT(GDD_EVENT_WAIT_DECODING);
                    if(GIF_DEC_STATE_COMPLETE  != g_image_gif_state)
                    {
                        ret_value = GDI_IMAGE_ERR_DECODE_FAILED;
                        if (GIF_STATUS_NO_FRAME == g_image_gif_status)
                        {
                            ret_value = GDI_IMAGE_ERR_DECODE_NO_FRAME;
                        }
                        break;
                    }
                }
                else /* sw gif decode */
                {
                    GIF_DEC_STATE_ENUM dec_state;
                    U32 dec_frame = 0;
                    do
    		        {
    		    	    g_image_gif_status = gifDecGetState(g_image_gif_decoder_hdl, &dec_state);
    		    	    if (GIF_STATUS_OK != g_image_gif_status)
    		    	    {
    		    	        ret_value = GDI_IMAGE_ERR_DECODE_FAILED;
    		    	        if (GIF_STATUS_NO_FRAME == g_image_gif_status)
                                {
                                    ret_value = GDI_IMAGE_ERR_DECODE_NO_FRAME;
                                }
    		    	        break;
    		    	    }
    		            switch(dec_state)
    		            {
    		                case GIF_DEC_STATE_DECODING: // do nothing, just wait HW GIF...
    		                    break;
    
    		                case GIF_DEC_STATE_PAUSE:			           
    		                    gifDecResume(g_image_gif_decoder_hdl);
    		                    continue;

    		                case GIF_DEC_STATE_COMPLETE:
    		                    gifDecGetFrameNumberDecoded(g_image_gif_decoder_hdl, &dec_frame);
    		                    if(dec_frame < frame_number)
    		                    {
    		                        gifDecResume(g_image_gif_decoder_hdl);
    		                        continue;
    		                    }
    		                case GIF_DEC_STATE_STOP:
    		                default:
    					        break;
    		            }
    		        } while((GIF_DEC_STATE_COMPLETE != dec_state)&&
    		    			(GIF_DEC_STATE_STOP != dec_state));
    			    g_image_gif_status = gifDecStop(g_image_gif_decoder_hdl);
                }
            }

            //if (GIF_DEC_TYPE_HW == decode_type)
            {
                kal_uint32 delay_time;
                gifDecGetCurFrameDelayTime(g_image_gif_decoder_hdl, &delay_time);
                if (0 == delay_time)
                {
                    delay_time = 100; // default value 100 ms
                }
                
                if (!(flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC))
                {
    	            gdi_anim_set_frame_delay(delay_time);

                    gdi_image_set_update_area(
                        ox,
                        oy,
                        ox + display_width - 1,
                        oy + display_height - 1);
                }

                /* Support Color Index Overlay */
                if (out_layer->vcf == GDI_COLOR_FORMAT_8)
                {
                    int i = 0;
                    U32 *active_palette;
        			// only index color format need to get palette
        			gifDecGetPalette(
        			    g_image_gif_decoder_hdl,
        			    &active_palette,
        			    &gdi_image_gif_palette_size);   

                    for (i = 0; i < gdi_image_gif_palette_size; i++)
                    {
                        gdi_gif_local_palette[i] = active_palette[i];
                    }

        	    // only index color format need to get transparent index
        	    gifDecGetTransparentIndex(g_image_gif_decoder_hdl, (kal_uint8*)&gdi_image_gif_transparent_index);
                }
                gifGetFrameNDisposalMethod(g_image_gif_decoder_hdl, &gif_src, frame_number, &gdi_image_gif_next_frame_disposal);
            }
            ret_value = GDI_SUCCEED;

        } while(0);

        /* Free working buffer */
        {
            if (g_image_gif_int_mem != NULL)
            {
                if(is_system_init == KAL_TRUE)
                {
                    kal_adm_free(gdi_layer_buffer_pool_id, g_image_gif_int_mem);
                }
                else
                {
                    med_free_int_mem(&g_image_gif_int_mem);
                }
            }

            if (g_image_gif_ext_mem != NULL)
            {
                gdi_free_ext_mem(&g_image_gif_ext_mem);
            }
        }

        /* Free fsal cache read buffer */
        {
            if (NULL != readBuffer)
            {
                gdi_free_ext_mem(&readBuffer);
                readBuffer = NULL;
            }

            if (NULL != fsalCacheAddr)
            {
                gdi_free_ext_mem(&fsalCacheAddr);
            }
        }

        /* Close fsal handle */
        {
            FSAL_Close(&gif_src);
	    g_image_gif_file_opened = KAL_FALSE;
        }
        gifDecReleaseHandle(&g_image_gif_decoder_hdl);

        if ((GDI_SUCCEED != ret_value) && (GIF_DEC_TYPE_HW == decode_type))
        {
            if ((g_image_gif_status != GIF_STATUS_NO_FRAME) &&
                (gdi_image_gif_decode_result != GDI_IMAGE_ERR_DECODE_TIME_OUT))
            {
                flag |= GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE;
                ret_value = GDI_SUCCEED;
                continue;
            }
        }
        break;
    } while(1);

    if (ret_value != GDI_SUCCEED)
    {
        GDI_TRACE(GDI_TRC_CODEC_I, GDI_GIF_DECODE_FAIL,//[gdi_image_gif_fail]: gif_state:%d decode_result:%d decode_type:%d is_file:%d x:%d y:%d w:%d h:%d
                      g_image_gif_status, ret_value, decode_type, is_file, ox, oy, resized_width, resized_height);
    }

    GDI_TRACE(GDI_TRC_DECODE, GDI_GIF_LEAVE,//[gdi_imgdec_gif_draw_internal]: Leave - ret:%d
        ret_value);
    GDI_IMGDEC_HW_UNLOCK();
#endif /* GDI_USING_GIF */
    return ret_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_set_palette_color_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_gif_set_palette_color_format(gdi_color_format cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_GIF
    GDI_ENTER_CRITICAL_SECTION(gdi_image_gif_set_palette_color_format)
    gdi_image_gif_palette_color_format = cf;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_gif_set_palette_color_format)
#else
    GDI_ASSERT(0);
#endif /* GDI_USING_GIF */
}

