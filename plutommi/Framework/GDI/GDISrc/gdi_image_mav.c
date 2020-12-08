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
 *  gdi_image_mav.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MAV image type 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gdi_internal.h"
#include "gdi_image.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_mutex.h"
#include "gd_include.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "MMIDataType.h"

#include "med_utility.h"
#include "med_smalloc.h"

#include "drm_gprot.h"

#include "mav_decoder.h"
#include "gdi_imgdec_internal.h"
#include "gdi_image_mav.h"
#include "gdd_include.h"

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#define GDI_HW_MAV_CODEC_WAITING_TIME 6000       /* ms */

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static gdi_mutex_struct g_image_mav_mutex;
static gdi_image_mav_decoder_struct g_image_mav_decoder;


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_send_ilm_to_gdd
 * DESCRIPTION
 *  send ilm to gdd
 * PARAMETERS
 *  ret     [IN]    return value from jpeg driver
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_mav_send_ilm_to_gdd(S32 mav_codec_state)
{

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = mav_codec_state;
    gdd_send_img_codec_ind(&data,sizeof(data));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_timeout_handler
 * DESCRIPTION
 *  timeout handler of gdd
 * PARAMETERS
 *  arg     [IN]    arg from gdd, not used
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_mav_timeout_handler(void *arg)
{
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
    {
        gdi_image_mav_send_ilm_to_gdd((S32)GDI_IMAGE_ERR_DECODE_TIME_OUT);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_callback
 * DESCRIPTION
 *  message handler of mav driver
 * PARAMETERS
 *  ret     [IN]    return value from jpeg driver
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 gdi_image_mav_callback(JPEG_CODEC_STATE_ENUM state)
{
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
    {
        gdi_image_mav_send_ilm_to_gdd((S32)state);
    }
    else
    {
        g_image_mav_decoder.decode_state = state;
        mavDecReset(g_image_mav_decoder.handle);
    }
#endif
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_get_result
 * DESCRIPTION
 *  convert hwjpeg driver return value into GDI return value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_RESULT gdi_image_mav_get_result(void)
{
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If it abort the SW JPEG, the state will be idle */
    if ((JPEG_CODEC_TYPE_SW == g_image_mav_decoder.type) &&
        ((g_image_mav_decoder.decode_state == JPEG_CODEC_STATE_IDLE) ||
         (g_image_mav_decoder.decode_state == JPEG_CODEC_STATE_ERROR)))
    {
        g_image_mav_decoder.status = MAV_DEC_STATUS_JPEG_FAIL;
    }

    switch (g_image_mav_decoder.status)
    {
        case MAV_DEC_STATUS_OK:
            return GDI_SUCCEED;

        case MAV_DEC_STATUS_FS_FAIL:
        case MAV_DEC_STATUS_FS_ASYNC_NOT_SUPPORT:
        case MAV_DEC_STATUS_INVALID_FILE:
             return GDI_IMAGE_ERR_INVALID_FILE;
            
        default:
            return GDI_FAILED;
    }
#else
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_mav_progress_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 gdi_imgdec_mav_progress_callback(void)
{
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_image_mav_decoder.is_aborted && *(g_image_mav_decoder.is_aborted))
    {
        return 0;
    }

    if ((JPEG_CODEC_TYPE_SW == g_image_mav_decoder.type) &&
        (KAL_TRUE == g_imgdec_timer_timeout_flag))
    {
        return 0;
    }
    return 1;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_msg_handler
 * DESCRIPTION
 *  msg handler of gdd, handle hwjpg msg
 * PARAMETERS
 *  ilm         [IN]        the msg from gdi
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_mav_msg_handler(ilm_struct *ilm)
{
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

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

    if (g_image_mav_decoder.is_aborted && !gdi_imgdec_mav_progress_callback())
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
    
    if (JPEG_CODEC_STATE_BUSY == *interrupt_value)
    {
        /* still decoding, nothing to do... */
        return ;
    }
    else 
    {
        /* hw decode fail */
        gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
        gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
        mavDecReset(g_image_mav_decoder.handle);
        g_image_mav_decoder.decode_state = *interrupt_value;

        switch (*interrupt_value)
        {
            case JPEG_CODEC_STATE_COMPLETE: /* the module is stopped after the completion of task */
                g_image_mav_decoder.status = MAV_DEC_STATUS_OK;
                break;

            case JPEG_CODEC_STATE_FREE:                 /* the module is free to use */
            case JPEG_CODEC_STATE_IDLE:                 /* the module is acquired by some body */
            case JPEG_CODEC_STATE_EOF:
            case JPEG_CODEC_STATE_ERROR:                /* the module is stopped due to error */
                g_image_mav_decoder.status = MAV_DEC_STATUS_JPEG_FAIL;
                break;

            case GDI_IMAGE_ERR_DECODE_TIME_OUT:
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                break;

            default:
                ASSERT(0);
                break;
        }
        GDD_SET_EVENT(GDD_EVENT_WAIT_DECODING);
     }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_mav_draw_internal
 * DESCRIPTION
 *  draw mav image
 * PARAMETERS
 *  flag            [IN]        flag
 *  ox              [IN]        draw position x
 *  y               [IN]        draw position y
 *  resized_width   [IN]        draw width
 *  resized_height  [IN]        draw height
 *  frame_pos       [IN]        frame position
 *  src             [IN]        image pointer
 *  size            [IN]        image fize
 *  is_aborted      [IN]        image is aborted
 *  flag            [IN]        image flag
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_imgdec_mav_draw_internal(
            gdi_handle output_layer_handle,
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U32 frame_pos,
            U8 *src,
            U32 size,
            BOOL *is_aborted,
            U32 flag,
            S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *out_layer;
    GDI_RESULT result = GDI_FAILED;
    STFSAL fsal;
    kal_bool force_to_use_swjpeg = KAL_FALSE;
    void *readBuffer = NULL;
    void *fsalCacheAddr = NULL;
    void *extMem = NULL;
    void *intMem = NULL;
    MMI_BOOL intmem_from_ext = MMI_FALSE;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create file handle */
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        if(FSAL_Open(&fsal, (kal_int8*)src, FSAL_READ) != FSAL_OK)
        {
            return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
        }
    }
    else
    {
        FSAL_Direct_SetRamFileSize(&fsal, size);
        if(FSAL_Open(&fsal, src, FSAL_ROMFILE) != FSAL_OK)
        {
            return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
        }
    }

    GDI_MAV_LOCK_MUTEX;
    g_image_mav_decoder.result = GDI_SUCCEED;
    g_image_mav_decoder.handle = NULL;
    g_image_mav_decoder.is_aborted = is_aborted;
    do
    {
        /* Get Mav decoder handle */
        force_to_use_swjpeg = (flag & GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE) ? KAL_TRUE : KAL_FALSE;
        if (force_to_use_swjpeg == KAL_FALSE)
        {
            g_image_mav_decoder.type = JPEG_CODEC_TYPE_HW;
            g_image_mav_decoder.status = mavDecGetHandle(
                                             &(g_image_mav_decoder.handle),
                                             g_image_mav_decoder.type);
        }
        if ((force_to_use_swjpeg == KAL_TRUE) ||
            (MAV_DEC_STATUS_JPEG_HANDLE_UNAVAILABLE == g_image_mav_decoder.status))
        {
            g_image_mav_decoder.type = JPEG_CODEC_TYPE_SW;
            g_image_mav_decoder.status = mavDecGetHandle(
                                             &(g_image_mav_decoder.handle),
                                             g_image_mav_decoder.type);
            if (MAV_DEC_STATUS_JPEG_HANDLE_UNAVAILABLE == g_image_mav_decoder.status)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
                break;
            }
        }

        if (g_image_mav_decoder.type == JPEG_CODEC_TYPE_HW)
        {
            GDI_IMGDEC_HW_LOCK();
        }

        /* Set File Handle and File buffer */
        {
            kal_uint32 readBufferSizeBest = 0, readBufferSizeMinimum = 0;
            kal_uint32 fsalCacheSizeBest = 0, fsalCacheSizeMinimum = 0;
            g_image_mav_decoder.status = mavDecQuerySrcFileBuf(
                                             g_image_mav_decoder.handle,
                                             &readBufferSizeBest,
                                             &readBufferSizeMinimum,
                                             &fsalCacheSizeBest,
                                             &fsalCacheSizeMinimum);
            if (g_image_mav_decoder.status != MAV_DEC_STATUS_OK)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_FAILED;
                break;
            }

            /* Malloc read buffer */
            while (1)
            {
                if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
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
                g_image_mav_decoder.result = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                break;
            }

            /* allocate fsal cache, but with it the performance of FSAL will be greatly increased */
            while(1)
            {
                if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
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

            g_image_mav_decoder.status = mavDecSetSrcFile(
                                             g_image_mav_decoder.handle,
                                             &fsal,
                                             fsalCacheAddr,
                                             fsalCacheSizeBest,
                                             readBuffer,
                                             readBufferSizeBest);
            if (g_image_mav_decoder.status != MAV_DEC_STATUS_OK)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_FAILED;
                break;
            }
        }


        out_layer = (gdi_layer_struct*)output_layer_handle;
        /* Set Canvas Window */ 
        {
            JPEG_RGB_FORMAT_ENUM canvas_color_format;
            g_image_mav_decoder.result = gdi_image_hwjpeg_v2_cf_to_hw(out_layer->vcf, &canvas_color_format);
            if (GDI_SUCCEED != g_image_mav_decoder.result)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
                break;
            }
            g_image_mav_decoder.status = mavDecSetRGBCanvas(
                                             g_image_mav_decoder.handle,
                                             out_layer->buf_ptr, 
                                             out_layer->width, 
                                             out_layer->height,
                                             canvas_color_format);
            if (g_image_mav_decoder.status != MAV_DEC_STATUS_OK)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_FAILED;
                break;
            }
        }

        /* Set Output Window */
        {
            kal_uint32 src_w, src_h;
            mavDecQuerySrcImageResolution(g_image_mav_decoder.handle, &src_w, &src_h);
            if (resized_width == 0 && resized_height == 0)
            {
                resized_width = src_w;
                resized_height = src_h;
            }
            else if (flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
            {
                /* MAV can not enlarge */
                gdi_util_adjust_aspect(
                    aspect_flag,
                    ox,
                    ox,
                    resized_width,
                    resized_height,
                    src_w,
                    src_h,
                    &ox,
                    &oy,
                    &resized_width,
                    &resized_height);
            }
            g_image_mav_decoder.status = mavDecSetOutputWindow(g_image_mav_decoder.handle, ox, oy, resized_width, resized_height);
            g_image_mav_decoder.status = mavDecSetClipWindow(
                                             g_image_mav_decoder.handle, 
                                             out_layer->clipx1, 
                                             out_layer->clipy1, 
                                             out_layer->clipx2 - out_layer->clipx1 + 1, 
                                             out_layer->clipy2 - out_layer->clipy1 + 1);  
            if (g_image_mav_decoder.status != MAV_DEC_STATUS_OK)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_FAILED;
                break;
            }
        }

        /* Set abort function and callback */
        {
            g_image_mav_decoder.status = mavDecSetCallbackFunction(
                                             g_image_mav_decoder.handle,
                                             gdi_image_mav_callback);                                             
            if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
            {
                /* IMGDEC callback */
                g_image_mav_decoder.status = mavDecSetCheckAbortFunction(
                                                 g_image_mav_decoder.handle,
                                                 gdi_imgdec_mav_progress_callback);
            }
            else
            {
                g_image_mav_decoder.status = mavDecSetCheckAbortFunction(
                                                 g_image_mav_decoder.handle,
                                                 gdi_image_progress_callback);
            }
        }


        /* Set working buffer */
        {
            kal_uint32 intMemorySizeBest, intMemorySizeMinumum;
            kal_uint32 extMemorySizeBest, extMemorySizeMinimum;

            g_image_mav_decoder.status = mavDecQueryWorkingMemory(
                                             g_image_mav_decoder.handle,
                                             &intMemorySizeBest,
                                             &intMemorySizeMinumum,
                                             &extMemorySizeBest,
                                             &extMemorySizeMinimum);
            if (g_image_mav_decoder.status != MAV_DEC_STATUS_OK)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_FAILED;
                break;
            }

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
                   g_image_mav_decoder.result = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                   break;
                }
                intmem_from_ext = MMI_TRUE;
            }

            while (1)
            {
                if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
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
                g_image_mav_decoder.result = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                break;
            }

            g_image_mav_decoder.status = mavDecSetWorkingMemory(
                                             g_image_mav_decoder.handle,
                                             intMem,
                                             intMemorySizeBest,
                                             extMem,
                                             extMemorySizeBest);
            if (g_image_mav_decoder.status != MAV_DEC_STATUS_OK)
            {
                g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_FAILED;
                break;
            }
        }


        /* start decode */
        g_image_mav_decoder.status = mavDecSetDecodeMode(
                                         g_image_mav_decoder.handle,
                                         JPEG_DECODE_MODE_MAIN_IMAGE);
        /* gdd */
        if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
        {
            gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, gdi_image_mav_msg_handler);
            /* start gdd */
            gdd_start_timer(
                GDD_TIMER_IMAGE_CODEC_TIMEOUT,
                GDI_HW_MAV_CODEC_WAITING_TIME,
                gdi_image_mav_timeout_handler,
                0);
        }
        g_image_mav_decoder.decode_state = JPEG_CODEC_STATE_BUSY;        
        g_image_mav_decoder.status = mavDecStart(g_image_mav_decoder.handle, frame_pos);
        if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
        {
            if (MAV_DEC_STATUS_OK == g_image_mav_decoder.status)
            {
                /* Check abort after decode start */
                if (flag & GDI_IMAGE_CODEC_FLAG_IS_IMGDEC)
                {
                    if ((KAL_TRUE == g_imgdec_timer_timeout_flag) ||
                        (g_image_mav_decoder.is_aborted && *g_image_mav_decoder.is_aborted))
                    {
                        g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                    }
                }
                else
                {
                    if (!gdi_image_progress_callback())
                    {
                        g_image_mav_decoder.result = GDI_IMAGE_ERR_DECODE_TIME_OUT;
                    }
                }
            }
            else
            {
                gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
                gdd_stop_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT);
                mavDecReset(g_image_mav_decoder.handle);
                break;
            }
        }

        if (JPEG_CODEC_TYPE_HW == g_image_mav_decoder.type)
        {
		    GDD_WAIT_EVENT(GDD_EVENT_WAIT_DECODING);    /* wait gdd finish drawing and set the event */
        }
    } while(0);

    if (g_image_mav_decoder.result != GDI_IMAGE_ERR_DECODE_TIME_OUT)
    {
        g_image_mav_decoder.result = gdi_image_mav_get_result();
    }

    /* Free all memory */
    {
        if (intMem)
        {
            if (intmem_from_ext)
            {
                gdi_free_ext_mem(&intMem);
            }
            else
            {
                med_free_int_mem(&intMem);
            }
        }
        if (extMem)
        {
            gdi_free_ext_mem(&extMem);
        }
        if (readBuffer)
        {
            gdi_free_ext_mem(&readBuffer);
        }
        if (fsalCacheAddr)
        {
            gdi_free_ext_mem(&fsalCacheAddr);
        }
        intmem_from_ext = MMI_FALSE;
    }

    if (g_image_mav_decoder.handle != NULL)
    {
        g_image_mav_decoder.status = mavDecReleaseHandle(&(g_image_mav_decoder.handle));
        GDI_ASSERT(MAV_DEC_STATUS_OK == g_image_mav_decoder.status);
    }

    if (g_image_mav_decoder.type == JPEG_CODEC_TYPE_HW)
    {
        GDI_IMGDEC_HW_UNLOCK();
    }
    result = g_image_mav_decoder.result;
    GDI_MAV_UNLOCK_MUTEX;

    /* Close file */
    FSAL_Close(&fsal);
#endif //#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_draw_handler
 * DESCRIPTION
 *  draw ktx image
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_mav_draw_handler(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *data_ptr, 
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
    gdi_handle act_layer;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_mav_draw_handler)
    gdi_layer_get_active(&act_layer);
    flag = gdi_image_codec_get_flag();
    ret = gdi_imgdec_mav_draw_internal(
              act_layer,
              x,
              y,
              w,
              h,
              frame_pos,
              data_ptr,
              img_size,
              NULL,
              flag,
              0);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_mav_draw_handler)
#endif //#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_get_info_internal
 * DESCRIPTION
 *  get information of mav image
 * PARAMETERS
 *  fsal           [IN]     STFSAL handle
 *  total_pos      [OUT]    total frame count
 *  width          [OUT]    width
 *  height         [OUT]    height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_mav_get_info_internal(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            U32 *total_pos,
            U32 *width,
            U32 *height,
            kal_bool *is_mav)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MAV_DECODER_HANDLE *handler = NULL;
    MAV_DEC_STATUS status;
    STFSAL fsal;
    gdi_result ret = GDI_FAILED;
    void *readBuffer = NULL;
    void *fsalCacheAddr = NULL;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        if(FSAL_Open(&fsal, (kal_int8*)data_ptr, FSAL_READ) != FSAL_OK)
        {
            return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
        }
    }
    else
    {
        FSAL_Direct_SetRamFileSize(&fsal, img_size);
        if(FSAL_Open(&fsal, data_ptr, FSAL_ROMFILE) != FSAL_OK)
        {
            return GDI_FAILED;
        }
    }

    status = mavDecGetHandle(&handler, JPEG_CODEC_TYPE_SW);
    if (status != MAV_DEC_STATUS_OK)
    {
        FSAL_Close(&fsal);
        return GDI_FAILED;
    }

    do
    {
        kal_uint32 readBufferSizeBest = 0, readBufferSizeMinimum = 0;
        kal_uint32 fsalCacheSizeBest = 0, fsalCacheSizeMinimum = 0;
        status = mavDecQuerySrcFileBuf(
                     handler,
                     &readBufferSizeBest,
                     &readBufferSizeMinimum,
                     &fsalCacheSizeBest,
                     &fsalCacheSizeMinimum);
        if (status != MAV_DEC_STATUS_OK)
        {
            break;
        }
        /* Malloc read buffer */
        while (1)
        {
            readBuffer = (void *)gdi_alloc_ext_mem(readBufferSizeBest);            
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
            break;
        }
            
        /* allocate fsal cache */
        while(1)
        {
            fsalCacheAddr = (void *)gdi_alloc_ext_mem_cacheable(fsalCacheSizeBest);
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

        status = mavDecSetSrcFile(
                     handler,
                     &fsal,
                     fsalCacheAddr,
                     fsalCacheSizeBest,
                     readBuffer,
                     readBufferSizeBest);
        if (status != MAV_DEC_STATUS_OK)
        {
            break;
        }

        if (total_pos != NULL)
        {
            status = mavDecQueryFrameCount(handler, total_pos);
            if (status == MAV_DEC_STATUS_OK)
            {
                ret = GDI_SUCCEED;
            }            
        }
        if (width != NULL && height != NULL)
        {
            status = mavDecQuerySrcImageResolution(handler, width, height);
            if (status == MAV_DEC_STATUS_OK)
            {
                ret = GDI_SUCCEED;
            }
        }
        if (is_mav != NULL)
        {
            status = mavDecQueryIsMAV(handler, is_mav);
            if (status == MAV_DEC_STATUS_OK)
            {
                ret = GDI_SUCCEED;
            }
        }
    } while(0);

    /* Free all memory */
    {
        if (readBuffer)
        {
            gdi_free_ext_mem(&readBuffer);
        }
        if (fsalCacheAddr)
        {
            gdi_free_ext_mem(&fsalCacheAddr);
        }
    }

    mavDecReleaseHandle(&handler);
    FSAL_Close(&fsal);
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_get_dimension_handler
 * DESCRIPTION
 *  get dimension of the mav image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_mav_get_dimension_handler(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_mav_get_info_internal(
              flag,
              data_ptr,
              img_size,
              NULL,
              width,
              height,
              NULL);
#endif //#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_get_pos_info_handler
 * DESCRIPTION
 *  get frame count of the mav image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  quick_mode     [IN]     unused
 *  total_pos      [OUT]    frame count
 *  pos_type       [IN]     unused
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_mav_get_pos_info_handler(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            BOOL quick_mode,
            S32 *total_pos,
            gdi_anim_pos_type_enum *pos_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_mav_get_info_internal(
              flag,
              data_ptr,
              img_size,
              total_pos,
              NULL,
              NULL,
              NULL);
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_mav_file
 * DESCRIPTION
 *  is mav image file
 * PARAMETERS
 *  file_name           [IN]     file name
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_is_mav_file(U8 *file_name)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
    kal_bool is_mav = KAL_FALSE;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_mav_get_info_internal(
              GDI_IMAGE_CODEC_FLAG_IS_FILE,
              file_name,
              0,
              NULL,
              NULL,
              NULL,
              &is_mav);
    if (is_mav == KAL_TRUE)
    {
        ret = GDI_SUCCEED;
    }
#endif 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_mav_mem
 * DESCRIPTION
 *  is mav image mem
 * PARAMETERS
 *  data_ptr           [IN]    mem data
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_is_mav_mem(U8 *data_ptr, U32 img_size)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
    kal_bool is_mav = KAL_FALSE;
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_mav_get_info_internal(
              0,
              data_ptr,
              img_size,
              NULL,
              NULL,
              NULL,
              &is_mav);
    if (is_mav == KAL_TRUE)
    {
        ret = GDI_SUCCEED;
    }
#endif 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_mav_init
 * DESCRIPTION
 *  Initialize the mav decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_mav_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_init(&g_image_mav_mutex);
}


/*****************************************************************************
* FUNCTION
*  gdi_mav_lock_mutex
* DESCRIPTION
*  Lock GDI mav mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_mav_lock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&g_image_mav_mutex);
}


/*****************************************************************************
* FUNCTION
*  gdi_mav_unlock_mutex
* DESCRIPTION
*  Unlock GDI mav mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_mav_unlock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_unlock(&g_image_mav_mutex);
}

