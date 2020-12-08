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
 *  gdi_ipp.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "gdi_internal.h"
#include "ipp_interface.h"
#include "gdi_ipp.h"
#include "gdc_include.h"

#include "med_utility.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "ipp_enum.h"
#include "string.h"
#include "med_smalloc.h"
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_primitive.h"
#include "gdi_mutex.h"

#define GDI_IPP_PROGRESS_PERCENTAGE_INTERVAL 10 /* ipp call back every 10 percent */

static GDI_IPP_CALLBACK_FUNC gdi_ipp_app_done_callback;
static U32 gdi_ipp_flag = 0;

void gdi_ipp_set_flag(U32 flag)
{
    gdi_ipp_flag |= flag;
}

U32 gdi_ipp_get_flag(U32 flag)
{
    return (gdi_ipp_flag & flag);
}

void gdi_ipp_clear_flag(U32 flag)
{
    gdi_ipp_flag &= (~flag);
}

void gdi_ipp_reset_flag(void)
{
    gdi_ipp_flag = 0;
}


static void gdi_ipp_get_done_callback(GDI_IPP_CALLBACK_FUNC *done_callback)
{
    *done_callback = gdi_ipp_app_done_callback;
}


static GDI_RESULT gdi_ipp_cf_to_hw(gdi_color_format cf, IPP_COLOR_FORMAT_ENUM *png_cf)
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
            *png_cf = IPP_COLOR_FORMAT_RGB565;
            break;

        case GDI_COLOR_FORMAT_24:
            *png_cf = IPP_COLOR_FORMAT_RGB888;
            break;

        default:
            png_cf = NULL;
            return GDI_FAILED;  /* not support this color format */
    }
    return GDI_SUCCEED;
}


static IPP_EFFECT_ENUM gdi_ipp_get_effect_id(gdi_ipp_effect_enum gdi_effect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IPP_EFFECT_ENUM effect = IPP_PIXEL_EFFECT_GRAYSCALE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define POST_PIXEL_EFFECT_MAPPING_SWITCH(__effect__)      \
          case GDI_IPP_EFFECT_##__effect__##:       \
             effect = IPP_PIXEL_EFFECT_##__effect__##;\
             break;
    #define POST_BLOCK_EFFECT_MAPPING_SWITCH(__effect__)      \
          case GDI_IPP_EFFECT_##__effect__##:       \
             effect = IPP_BLOCK_EFFECT_##__effect__##;\
             break;

    switch (gdi_effect_id)
    {
        POST_PIXEL_EFFECT_MAPPING_SWITCH(GRAYSCALE);
        POST_PIXEL_EFFECT_MAPPING_SWITCH(SEPIA);
        POST_PIXEL_EFFECT_MAPPING_SWITCH(SEPIAGREEN);
        POST_PIXEL_EFFECT_MAPPING_SWITCH(SEPIABLUE);
        POST_PIXEL_EFFECT_MAPPING_SWITCH(COLORINV);
        POST_PIXEL_EFFECT_MAPPING_SWITCH(GRAYINV);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(WATERCOLOR);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(LIGHTBLUR);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(BLUR);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(STRONGBLUR);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(UNSHARP);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(SHARPEN);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(MORESHARPEN);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(MEDIAN);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(DILATION);
        POST_BLOCK_EFFECT_MAPPING_SWITCH(EROSION);
        
    default:
        // shall not enter here 
        GDI_ASSERT(0);
        break;
        
    }
    return effect;
}

kal_uint32 gdi_ipp_callback(kal_int32 percentage)
{
    if (percentage >= 100)
    {
        gdi_ipp_set_flag(GDI_IPP_FLAG_PROCESS_DONE);
    }
    return GDI_SUCCEED;
}

GDI_RESULT gdi_ipp_get_capability(
            gdi_ipp_effect_enum effect_id, 
            MMI_BOOL *ipp_support, 
            MMI_BOOL *ipp_allow_pause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint32 *effect_list = NULL;
    kal_uint32 effect_list_size;
    kal_uint32 effect_supported_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_ipp_get_capability)

    *ipp_support = MMI_FALSE;
    *ipp_allow_pause = MMI_FALSE;
            
    ippQuerySupportedEffects(NULL, &effect_list_size);  /* get size of effect list */
    
    effect_list = (kal_uint32*) gdi_alloc_ext_mem(effect_list_size);
    if(!effect_list)
    {
        GDI_RETURN(GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE);
    }
    effect_supported_count = ippQuerySupportedEffects((IPP_ENUM_EFFECT_SUPPORTER*)effect_list, &effect_list_size);   /* get effect list */

    if (effect_supported_count == 0)
    {
        *ipp_support = MMI_FALSE;
        *ipp_allow_pause = MMI_FALSE;
    }
    else
    {
        switch (effect_list[effect_id])
        {
            case IPP_EFFECT_NOT_SUPPORTED:
                *ipp_support = MMI_FALSE;
                *ipp_allow_pause = MMI_FALSE;
                break;
            
            case IPP_EFFECT_SW_SUPPORTED:
                *ipp_support = MMI_TRUE;
                *ipp_allow_pause = MMI_TRUE;
                break;
            
            case IPP_EFFECT_HW_SUPPORTED:
                *ipp_support = MMI_TRUE;
                *ipp_allow_pause = MMI_FALSE;
                break;
            
             default:
                GDI_ASSERT(0);
                break;
        }
    }
    
    gdi_free_ext_mem((void **)&effect_list);

    GDI_EXIT_CRITICAL_SECTION(gdi_ipp_get_capability)
    return GDI_SUCCEED;
}




GDI_RESULT gdi_ipp_process(
            gdi_handle layer_handle,
            gdi_ipp_effect_enum effect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_layer_struct *src_layer = (gdi_layer_struct*)layer_handle;
    kal_uint32 ippHandle = 0;
    IPP_COLOR_FORMAT_ENUM ipp_color_format;
    kal_uint8 *dst_buf = NULL, *working_mem = NULL;
    kal_uint32 dst_buf_size = 0, working_mem_size = 0;
    IPP_EFFECT_ENUM ipp_effect_id;
    MMI_BOOL support_by_sw, ipp_support;
    IPP_STATUS_ENUM ipp_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    GDI_ENTER_CRITICAL_SECTION(gdi_ipp_process)
    ret = gdi_ipp_get_capability(
                effect_id, 
                &ipp_support, 
                &support_by_sw);
    if (ret < 0)
    {
        GDI_RETURN(ret);
    }
    else if (ipp_support == MMI_FALSE)
    {
        GDI_RETURN(GDI_FAILED);
    }
    
    do
    {
        /* Get Handle */
        ippHandle = ippGetHandle();
        if (ippHandle == 0)
        {
            ret = GDI_FAILED;
            break;
        }
        
        ipp_effect_id = gdi_ipp_get_effect_id(effect_id);
        ipp_status = ippSetEffect(ippHandle, ipp_effect_id);
        if (ipp_status != IPP_STATUS_OK)
        {
            ret = GDI_FAILED;
            break;
        }
        /* alloc dst buffer */
        dst_buf_size = (src_layer->width * src_layer->height * src_layer->bits_per_pixel) >> 3;
        dst_buf = (kal_uint8 *)gdi_alloc_ext_mem(dst_buf_size);
        if (!dst_buf)
        {
            ret = GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
            break;
        }

        /* Set Source and Destination information */
        gdi_ipp_cf_to_hw(src_layer->vcf, &ipp_color_format);
        ipp_status = ippSetSrcInfo(
                        ippHandle, 
                        src_layer->buf_ptr, 
                        src_layer->width,
                        src_layer->height, 
                        ipp_color_format);

        ipp_status = ippSetDstInfo(
                        ippHandle, 
                        dst_buf, 
                        dst_buf_size, 
                        ipp_color_format);

        /* alloc and set working memory */
        working_mem_size = ippQueryWorkingMemory(
                                ipp_effect_id, 
                                src_layer->width, 
                                src_layer->height,
                                (src_layer->bits_per_pixel)>>3);
        if (working_mem_size)
        {
            working_mem = (kal_uint8 *)gdi_alloc_ext_mem(working_mem_size);
            if (!working_mem)
            {
                ret = GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
                break;
            }
        }
        
        ipp_status = ippSetWorkingMemory(ippHandle, working_mem, working_mem_size);
        ipp_status = ippSetProgressCallbckFunc(
                        ippHandle, 
                        gdi_ipp_callback, 
                        GDI_IPP_PROGRESS_PERCENTAGE_INTERVAL); /* call back every 10 percent */
        gdi_ipp_clear_flag(GDI_IPP_FLAG_PROCESS_DONE);
        ippStartProcess(ippHandle);

        if (support_by_sw == MMI_TRUE)  /* support pause/resume */
        {
            while(1)
            {
                /* done */
                if (gdi_ipp_get_flag(GDI_IPP_FLAG_PROCESS_DONE))
                {
                    break;
                }
                /* change state */
                if (gdi_ipp_get_flag(GDI_IPP_FLAG_NONBLOCK))
                {
                    IPP_STATE_ENUM ipp_state;

                    if (!gdi_image_progress_callback())  /* non blocking force abort */
                    {
                        ippAbortProcess(ippHandle);
                        ret = GDI_ERR_NB_ABORT;
                        break;
                    }
                    if (gdi_ipp_get_flag(GDI_IPP_FLAG_ABORTING))
                    {
                        ippAbortProcess(ippHandle);
                        gdi_ipp_clear_flag(GDI_IPP_FLAG_ABORTING);
                        break;
                    }

                    ipp_state = ippQueryState(ippHandle);
                    
                    if (gdi_ipp_get_flag(GDI_IPP_FLAG_PAUSING))
                    {
                        if (ipp_state == IPP_STATE_PROCESS)
                        {
                            ipp_status = ippPauseProcess(ippHandle);
                        }
                    }
                    else
                    {
                        if (ipp_state == IPP_STATE_PAUSED)
                        {
                            ipp_status = ippResumeProcess(ippHandle);
                        }
                    }
                }
                kal_sleep_task(1);  /* waiting */
            }
        }
        if (ret >= 0)   /* copy buffer if no error */
        {
            memcpy(src_layer->buf_ptr, dst_buf, dst_buf_size);
        }
    } while(0);

    /* free buffer */
    if (dst_buf)
    {
        gdi_free_ext_mem((void**)&dst_buf);
    }
    if (working_mem)
    {
        gdi_free_ext_mem((void**)&working_mem);
    }

    /* clear all flag */
    gdi_ipp_reset_flag();
    
    /* release handle */
    if (ippHandle > 0)
    {
        ipp_status = ippReleaseHandle(ippHandle);
        if (ipp_status != IPP_STATUS_OK)
        {
            ret = GDI_FAILED;
        }
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_post_effect)
    return ret;
}


GDI_RESULT gdi_ipp_nb_set_done_callback(GDI_IPP_CALLBACK_FUNC done_callback)
{
    gdi_ipp_app_done_callback = done_callback;
    return GDI_SUCCEED;
}

GDI_RESULT gdi_ipp_nb_start_process(
            gdi_handle layer_handle,
            gdi_ipp_effect_enum effect_id,
            gdi_handle *ipp_handle)
{
    gdi_result ret;
    GDI_IPP_CALLBACK_FUNC done_callback;

    gdi_ipp_get_done_callback(&done_callback);  
    if (done_callback == NULL)
    {
        return GDI_FAILED;  // TODO: is this check needed?
    }
    ret = gdc_job_add_ipp(
            layer_handle,
            effect_id,
            done_callback,
            ipp_handle);
    
    gdi_ipp_nb_set_done_callback(NULL); 

    return ret;
}

/*GDI_RESULT gdi_ipp_nb_pause_process(gdi_handle ipp_handle)
{
    // can't use gdi mutex in this API, or the nb ipp will be abort
    // check handle is ipp
    if (gdc_job_is_ipp(ipp_handle))
    {
        gdi_ipp_set_flag(GDI_IPP_FLAG_PAUSING);
        return GDI_SUCCEED;
    }
    else
    {
        return GDI_FAILED;
    }
}
GDI_RESULT gdi_ipp_nb_resume_process(gdi_handle ipp_handle)
{
    if (gdc_job_is_ipp(ipp_handle))
    {
        gdi_ipp_clear_flag(GDI_IPP_FLAG_PAUSING);
        return GDI_SUCCEED;
    }
    else
    {
        return GDI_FAILED;
    }
}
*/
GDI_RESULT gdi_ipp_nb_stop_process(gdi_handle ipp_handle)
{
    if (gdc_job_is_ipp(ipp_handle))
    {
        //abort
        gdi_ipp_set_flag(GDI_IPP_FLAG_ABORTING);
        //delete job
        //gdc_job_del_one(ipp_handle);
        return GDI_SUCCEED;
    }
    else
    {
        return GDI_FAILED;
    }
}




