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
 *  vadp_cube_imgview.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cube Image View Adaptation Layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP_IMGVIEW__

#include "ui_core\base\vfx_datatype.h"
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "ImageViewerGprot.h"

#include "MediaCacheSrvGprot.h"
#include "cubeApp\vapp_cube_imgview_config.h"
#include "vadp_cube_imgview.h"
#include "med_api.h"
#include "USBDeviceGprot.h"
#include "MobileTVPlayerGprot.h"
#include "drm_def.h"
#include "AMGprot.h"

vadp_cube_imgview_cntx_struct g_vadp_cube_imgview;

static S32 vadp_cube_imgview_file_sort_callback(fmgr_filelist_handle fl_hdl, S32 result, S32 progress, S32 total);
void vadp_cube_imgview_init_view_buffer(void);
void vadp_cube_imgview_deinit_view_buffer(void);

void vadp_cube_imgview_malloc_cache_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_cube_imgview.cache_total_memory_size = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_MALLOC_CACHE_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);
    
    g_vadp_cube_imgview.cache_run_buffer_size = SRV_MEDIACACHE_RUN_BUF_SIZE(MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_CACHE_COUNT);
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_vadp_cube_imgview.cache_run_buffer),
        g_vadp_cube_imgview.cache_run_buffer_size);
    g_vadp_cube_imgview.cache_total_memory_size += g_vadp_cube_imgview.cache_run_buffer_size;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_MALLOC_CACHE_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);

    g_vadp_cube_imgview.cache_db_buffer_size = SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_vadp_cube_imgview.cache_db_buffer),
        g_vadp_cube_imgview.cache_run_buffer_size);
    g_vadp_cube_imgview.cache_db_buffer_size += g_vadp_cube_imgview.cache_db_buffer_size;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_MALLOC_CACHE_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);

    g_vadp_cube_imgview.cache_navigation_buffer_size = MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_CACHE_MEM_ONE_ALL;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_vadp_cube_imgview.cache_navigation_buffer),
        g_vadp_cube_imgview.cache_navigation_buffer_size);
    g_vadp_cube_imgview.cache_total_memory_size += g_vadp_cube_imgview.cache_navigation_buffer_size;    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_MALLOC_CACHE_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);

    g_vadp_cube_imgview.cache_view_buffer_size = MMI_VAPP_CUBE_IMGVIEW_VIEW_CACHE_MEM_ALL;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_vadp_cube_imgview.cache_view_buffer),
        g_vadp_cube_imgview.cache_view_buffer_size);
    g_vadp_cube_imgview.cache_total_memory_size += g_vadp_cube_imgview.cache_view_buffer_size;    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_MALLOC_CACHE_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);

    vadp_cube_imgview_init_view_buffer();
}

void vadp_cube_imgview_free_cache_buffer(void)
{
    if (g_vadp_cube_imgview.cache_run_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_vadp_cube_imgview.cache_run_buffer));
        g_vadp_cube_imgview.cache_run_buffer = NULL;
    }
    
    if (g_vadp_cube_imgview.cache_db_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_vadp_cube_imgview.cache_db_buffer));
        g_vadp_cube_imgview.cache_db_buffer = NULL;
    }
    
    if (g_vadp_cube_imgview.cache_navigation_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_vadp_cube_imgview.cache_navigation_buffer));
        g_vadp_cube_imgview.cache_navigation_buffer = NULL;
    }

    if (g_vadp_cube_imgview.cache_view_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_vadp_cube_imgview.cache_view_buffer));
        g_vadp_cube_imgview.cache_view_buffer = NULL;
    }

    vadp_cube_imgview_deinit_view_buffer();
}

void vadp_cube_imgview_set_l2_image_info(S32 width, S32 height)
{
    g_vadp_cube_imgview.navigation_image_width = width;
    g_vadp_cube_imgview.navigation_image_height = height;
}

void vadp_cube_imgview_init_view_buffer(void)
{
    U8 i;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_INIT_VIEW_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);
    
    for (i = 0; i < VADP_CUBE_IMGVIEW_BUF_COUNT; i++)
    {
        media_get_ext_buffer_framebuffer(
            stack_int_get_active_module_id(),
            &(g_vadp_cube_imgview.view_buffer.buf_ptr[i]),
            MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT * 2);
        g_vadp_cube_imgview.cache_total_memory_size += MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT * 2;
        g_vadp_cube_imgview.view_buffer.is_used[i] = MMI_FALSE;
        g_vadp_cube_imgview.view_buffer.file_index[i] = -1;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_INIT_VIEW_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);
    }
    
    g_vadp_cube_imgview.view_buffer.back_buffer;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_vadp_cube_imgview.view_buffer.back_buffer),
        MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT * 2);
    g_vadp_cube_imgview.cache_total_memory_size += MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT * 2;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_INIT_VIEW_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);

    g_vadp_cube_imgview.view_buffer.curr_index = -1;
}

void  vadp_cube_imgview_deinit_view_buffer(void)
{
    U8 i;
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_INIT_VIEW_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);

    for (i = 0; i < VADP_CUBE_IMGVIEW_BUF_COUNT; i++)
    {
        if (g_vadp_cube_imgview.view_buffer.buf_ptr[i])
        {
            media_free_ext_buffer(
                stack_int_get_active_module_id(),
                &(g_vadp_cube_imgview.view_buffer.buf_ptr[i]));
            g_vadp_cube_imgview.view_buffer.is_used[i] = MMI_FALSE;
            g_vadp_cube_imgview.view_buffer.file_index[i] = -1;
            g_vadp_cube_imgview.cache_total_memory_size -= MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT * 2;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_INIT_VIEW_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);
        }
    }
    
    if (g_vadp_cube_imgview.view_buffer.back_buffer)
    {
        media_free_ext_buffer(
            stack_int_get_active_module_id(),
            &(g_vadp_cube_imgview.view_buffer.back_buffer));
        g_vadp_cube_imgview.cache_total_memory_size -= MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT * 2;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_INIT_VIEW_BUFFER, g_vadp_cube_imgview.cache_total_memory_size);
    }
}


void* vadp_cube_imgview_get_back_buffer(S32 index)
{
    return g_vadp_cube_imgview.view_buffer.back_buffer;
}

void* vadp_cube_imgview_get_avail_buffer(S32 index)
{
    U8 i;

    for (i = 0; i < VADP_CUBE_IMGVIEW_BUF_COUNT; i++)
    {
        if (g_vadp_cube_imgview.view_buffer.is_used[i] == MMI_FALSE)
        {
            g_vadp_cube_imgview.view_buffer.file_index[i] = index;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_AVAIL_BUFFER, i, g_vadp_cube_imgview.view_buffer.buf_ptr[i]);

            return g_vadp_cube_imgview.view_buffer.buf_ptr[i];
        }
    }

    MMI_ASSERT(0);
    return NULL;
}

void vadp_cube_imgview_set_used(S32 file_index, MMI_BOOL is_used)
{
    U8 i;
    
    for (i = 0; i < VADP_CUBE_IMGVIEW_BUF_COUNT; i++)
    {
        if (g_vadp_cube_imgview.view_buffer.file_index[i] == file_index)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_SET_USED, file_index, is_used, i);

            if (is_used)
            {
                g_vadp_cube_imgview.view_buffer.file_index[i] = file_index;
                g_vadp_cube_imgview.view_buffer.is_used[i] = MMI_TRUE;
                return;
            }
            else
            {
                g_vadp_cube_imgview.view_buffer.file_index[i] = -1;
                g_vadp_cube_imgview.view_buffer.is_used[i] = MMI_FALSE;
                return;
            }
        }
    }
}


void vadp_cube_imgview_swap_buffer(S32 index)
{
    void *tmp_buffer;

    U8 i;
    
    for (i = 0; i < VADP_CUBE_IMGVIEW_BUF_COUNT; i++)
    {
        if (g_vadp_cube_imgview.view_buffer.file_index[i] == index)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_SWAP_BUFFER, index, 
                g_vadp_cube_imgview.view_buffer.buf_ptr[i], g_vadp_cube_imgview.view_buffer.back_buffer);
            
            tmp_buffer = g_vadp_cube_imgview.view_buffer.back_buffer;
            g_vadp_cube_imgview.view_buffer.back_buffer = g_vadp_cube_imgview.view_buffer.buf_ptr[i];
            g_vadp_cube_imgview.view_buffer.buf_ptr[i] = tmp_buffer;        
        }
    }
}


void vadp_cube_imgview_create_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_cube_imgview_malloc_cache_buffer();
    
    g_vadp_cube_imgview.cache_state = VADP_CUBE_IMGVIEW_CACHE_STATE_PAUSE;

    g_vadp_cube_imgview.cache_handle = srv_mediacache_create(g_vadp_cube_imgview.cache_run_buffer, g_vadp_cube_imgview.cache_run_buffer_size);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_CREATE_CACHE_HANDLE, g_vadp_cube_imgview.cache_handle);
        
    srv_mediacache_config_work_mode_to_filelist(g_vadp_cube_imgview.cache_handle, g_vadp_cube_imgview.fl);
    /*
    srv_mediacache_config_database(
        g_vadp_cube_imgview.cache_handle,
        g_vadp_cube_imgview.cache_db_buffer,
        g_vadp_cube_imgview.cache_run_buffer_size,
        NULL);
    */
    srv_mediacache_config_level2_size(g_vadp_cube_imgview.cache_handle, g_vadp_cube_imgview.navigation_image_width, g_vadp_cube_imgview.navigation_image_height);
    srv_mediacache_disable_level2_clip_head(g_vadp_cube_imgview.cache_handle);

    srv_mediacache_add_cache(
        g_vadp_cube_imgview.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L2,
        g_vadp_cube_imgview.cache_navigation_buffer,
        g_vadp_cube_imgview.cache_navigation_buffer_size);
    
#if 1
    srv_mediacache_add_cache(
        g_vadp_cube_imgview.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L1,
        g_vadp_cube_imgview.cache_view_buffer,
        g_vadp_cube_imgview.cache_view_buffer_size);
#endif

    srv_mediacache_start(g_vadp_cube_imgview.cache_handle, 0);
    g_vadp_cube_imgview.cache_state = VADP_CUBE_IMGVIEW_CACHE_STATE_RUNNING;
}

void vadp_cube_imgview_pause_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_PAUSE_CACHE, g_vadp_cube_imgview.cache_handle);
    
    if (g_vadp_cube_imgview.cache_handle)
    {
        srv_mediacache_pause_decode(g_vadp_cube_imgview.cache_handle);
        g_vadp_cube_imgview.cache_state = VADP_CUBE_IMGVIEW_CACHE_STATE_PAUSE;
    }
}

void vadp_cube_imgview_resume_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_RESUME_CACHE, g_vadp_cube_imgview.cache_handle);
    
    if (g_vadp_cube_imgview.cache_handle)
    {
        srv_mediacache_resume_decode(g_vadp_cube_imgview.cache_handle);
        g_vadp_cube_imgview.cache_state = VADP_CUBE_IMGVIEW_CACHE_STATE_RUNNING;
    }
}

void vadp_cube_imgview_close_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_CLOSE_CACHE, g_vadp_cube_imgview.cache_handle);

    if (g_vadp_cube_imgview.cache_handle)
    {
        srv_mediacache_stop(g_vadp_cube_imgview.cache_handle);

        if (g_vadp_cube_imgview.cache_navigation_buffer)
        {
            srv_mediacache_remove_cache(
                g_vadp_cube_imgview.cache_handle,
                g_vadp_cube_imgview.cache_navigation_buffer);
        }
        srv_mediacache_destroy(g_vadp_cube_imgview.cache_handle);
        g_vadp_cube_imgview.cache_handle = 0;
        g_vadp_cube_imgview.cache_state = VADP_CUBE_IMGVIEW_CACHE_STATE_CLOSED;
    }
    
    vadp_cube_imgview_free_cache_buffer();
}

S32 vadp_cube_imgview_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, S32 width, S32 height, void** buffer)
{
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret = SRV_MEDIACACHE_OK;
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock_img.callback = NULL;
    lock_img.user_data = NULL;
    lock_img.source = source;
    
    if (g_vadp_cube_imgview.cache_handle == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_LOCK_IMAGE_BUFFER, g_vadp_cube_imgview.cache_handle,
            g_vadp_cube_imgview.cache_state, VADP_CUBE_IMGVIEW_ERROR_NO_SERVICE);
        return VADP_CUBE_IMGVIEW_ERROR_NO_SERVICE;
    }
    
    if (g_vadp_cube_imgview.cache_state == VADP_CUBE_IMGVIEW_CACHE_STATE_PAUSE)
    {
        srv_mediacache_resume_decode(g_vadp_cube_imgview.cache_handle);
    }
    
    error_code = srv_mediacache_lock_img_buffer_addr(g_vadp_cube_imgview.cache_handle, index, &lock_img);
    
    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer = lock_img.buffer;
        ret = SRV_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_NOT_READY || 
        error_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
        error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        ret = error_code;
    }
#ifdef __DRM_SUPPORT__
    else if (error_code == DRM_RESULT_NO_PERMISSION)
    {
        ret = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
#endif
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    
    if (g_vadp_cube_imgview.cache_state == VADP_CUBE_IMGVIEW_CACHE_STATE_PAUSE)
    {
        vadp_cube_imgview_pause_cache();
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_LOCK_IMAGE_BUFFER, g_vadp_cube_imgview.cache_handle,
        g_vadp_cube_imgview.cache_state, ret);
	return ret;
}

void vadp_cube_imgview_free_image_buffer(S32 index, void* buffer)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_LOCK_IMAGE_BUFFER, g_vadp_cube_imgview.cache_handle,
        index, buffer);

    if (g_vadp_cube_imgview.cache_handle == NULL)
    {
        return;
    }
    
	srv_mediacache_unlock_img_buffer(g_vadp_cube_imgview.cache_handle, buffer);
}

void vadp_cube_imgview_decode_callback(S32 err_group,S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_DECODE_CALLBACK,
        err_code, user_data, g_vadp_cube_imgview.decode_cb);
    
    if (err_code == SRV_MEDIACACHE_OK)
    {
        error_code = SRV_MEDIACACHE_OK;
    }
    else if (err_code == SRV_MEDIACACHE_ERR_NOT_READY || 
        err_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
        err_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        error_code = err_code;
    }
#ifdef __DRM_SUPPORT__
    else if (err_code == DRM_RESULT_NO_PERMISSION)
    {
        err_code = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
#endif
    else
    {
        error_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    
    if (g_vadp_cube_imgview.decode_cb)
    {
        g_vadp_cube_imgview.decode_cb(g_vadp_cube_imgview.menu_ptr, (S32)user_data, error_code);
    }
}

S32 vadp_cube_imgview_get_lock_image_buffer_nonblocking(
                                                         void *user_data, 
                                                         S32 index,
                                                         void(*callback)(void*, S32, S32), void** buffer_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
    S32 ret;
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lock_img.callback = vadp_cube_imgview_decode_callback;
    lock_img.user_data = (void*)index;
    lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;
    
    g_vadp_cube_imgview.menu_ptr = user_data;
    g_vadp_cube_imgview.decode_cb = callback;
    
    if (g_vadp_cube_imgview.cache_handle == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_LOCK_IMAGE_BUFFER_NB, user_data, index, callback, VADP_CUBE_IMGVIEW_ERROR_NO_SERVICE);
        return VADP_CUBE_IMGVIEW_ERROR_NO_SERVICE;
    }
    
    if (g_vadp_cube_imgview.cache_state == VADP_CUBE_IMGVIEW_CACHE_STATE_PAUSE)
    {
        srv_mediacache_resume_decode(g_vadp_cube_imgview.cache_handle);
    }
    
    error_code = srv_mediacache_lock_img_buffer_addr(
        g_vadp_cube_imgview.cache_handle, 
        index, 
        &lock_img);
    
    if (error_code == SRV_MEDIACACHE_OK)
    {
        *buffer_pp = lock_img.buffer;
        ret = SRV_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        ret = SRV_MEDIACACHE_ERR_DECODING;
    }
#ifdef __DRM_SUPPORT__
    else if (error_code == DRM_RESULT_NO_PERMISSION)
    {
        ret = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
#endif
    else
    {
        ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_LOCK_IMAGE_BUFFER_NB, user_data, index, callback, ret);

    return ret;
}



/****************************************************************************************************
* 
* file list
* 
****************************************************************************************************/
S32 vadp_cube_imgview_get_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_pathname[SRV_FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_get_storage_file_path((PS8) buf_pathname);
    
    if (g_vadp_cube_imgview.fl)
    {
        if (buf_pathname[0] != g_vadp_cube_imgview.curr_drv)
        {
            vadp_cube_imgview_free_file_list();
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FILE_LIST, g_vadp_cube_imgview.fl);
    return g_vadp_cube_imgview.fl;
}


static mmi_ret mmi_cube_imgview_filelist_refresh_proc(mmi_event_struct *param)
{
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*) param;
    
    switch(param->evt_id) 
    {
    case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {       
            S32 file_count;

            file_count = srv_fmgr_filelist_count(evt->handle);
            
            if (evt->result >= 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_SORT_CALLBACK, file_count, evt->result);
                
                g_vadp_cube_imgview.sort_state = VADP_CUBE_IMGVIEW_SORT_STATE_OVER;
                if (g_vadp_cube_imgview.sort_callback != NULL)
                {
                    /* vadp_cube_imgview_create_cache(); */
                    g_vadp_cube_imgview.sort_callback(
                        g_vadp_cube_imgview.user_data,
                        file_count,
                        VADP_CUBE_IMGVIEW_SORT_STATE_OVER);
                    if (evt->result < 0)
                    {
                        vadp_cube_imgview_free_file_list();
                    }
                }
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_SORT_CALLBACK, file_count, evt->result);
            }
        }
        break;
    }
    
}

S32 vadp_cube_imgview_create_file_list(
                                      void *user_data,
                                      PU16 path,
                                      vadp_cube_imgview_filter_type_enum filter_type,
                                      vadp_cube_imgview_sort_type_enum sort_type,
                                      vadp_cube_imgview_sort_callback sort_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    S32 file_count = 0;
    FMGR_FILTER filter;
    U16 sort_type_internal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if already created, will not create again */
    if (g_vadp_cube_imgview.fl)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FILE_LIST, g_vadp_cube_imgview.fl, FS_NO_ERROR, 0);
        return FS_NO_ERROR;
    }

    g_vadp_cube_imgview.user_data = user_data;
    g_vadp_cube_imgview.sort_callback = sort_callback;
    
    if (filter_type == VADP_CUBE_IMGVIEW_FILTER_TPYE_IMAGE)
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
        
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
    }
    
    switch (sort_type)
    {
    case VADP_CUBE_IMGVIEW_SORT_TYPE_BY_NAME:
        sort_type_internal = FS_SORT_NAME;
        break;
        
    case VADP_CUBE_IMGVIEW_SORT_TYPE_BY_TIME:
        sort_type_internal = FS_SORT_TIME;
        break;
        
    case VADP_CUBE_IMGVIEW_SORT_TYPE_BY_TYPE:
        sort_type_internal = FS_SORT_TYPE;
        break;
        
    case VADP_CUBE_IMGVIEW_SORT_TYPE_BY_SIZE:
        sort_type_internal = FS_SORT_TYPE;
        break;
        
    default:
        sort_type_internal = FS_NO_SORT;
        break;
    }
    
    if (path == NULL)
    {
        mmi_imgview_get_storage_file_path((PS8) g_vadp_cube_imgview.file_path);
    }

    result = srv_fmgr_folder_filelist_create((WCHAR*)g_vadp_cube_imgview.file_path, &filter, sort_type_internal, 
        NULL, 0, &g_vadp_cube_imgview.fl);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FILE_LIST, g_vadp_cube_imgview.fl, FS_NO_ERROR, result);

    result = srv_fmgr_filelist_refresh(g_vadp_cube_imgview.fl, NULL, 0, 0, mmi_cube_imgview_filelist_refresh_proc, NULL);

    g_vadp_cube_imgview.curr_drv = (S8) g_vadp_cube_imgview.file_path[0];
    
    if (result >= FS_NO_ERROR)
    {
        g_vadp_cube_imgview.sort_state = VADP_CUBE_IMGVIEW_SORT_STATE_DOING;
        file_count = srv_fmgr_filelist_count(g_vadp_cube_imgview.fl);
    }
    else
    {
        g_vadp_cube_imgview.fl = 0;
        g_vadp_cube_imgview.sort_state = VADP_CUBE_IMGVIEW_SORT_STATE_IDLE;
        /* here means occurs error */ ;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FILE_LIST, g_vadp_cube_imgview.fl, FS_NO_ERROR, result);
    return result;
}


void vadp_cube_imgview_free_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FILE_LIST, g_vadp_cube_imgview.fl);
    
    if (g_vadp_cube_imgview.fl)
    {
        /* vadp_cube_imgview_close_cache(); */
        
        g_vadp_cube_imgview.sort_callback = NULL;
        g_vadp_cube_imgview.user_data = NULL;
        srv_fmgr_filelist_destroy(g_vadp_cube_imgview.fl);
        g_vadp_cube_imgview.fl = 0;
    }
}

S32 vadp_cube_imgview_get_file_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_cube_imgview.fl != 0)
    {
        file_count = srv_fmgr_filelist_count(g_vadp_cube_imgview.fl);
        if (file_count >= FS_NO_ERROR)
        {
            ;
        }
        else
        {
            file_count = 0;
        }
    }
    else
    {
        file_count = 0;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FILE_COUNT, g_vadp_cube_imgview.fl, file_count);

    return file_count;
}

void vadp_cube_imgview_change_to_view_mode(S32 index)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_CHANGE_TO_VIEW_MODE, g_vadp_cube_imgview.cache_handle, index);
        
    srv_mediacache_stop(g_vadp_cube_imgview.cache_handle); 
    
    srv_mediacache_add_cache(
        g_vadp_cube_imgview.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L1,
        g_vadp_cube_imgview.cache_view_buffer,
        g_vadp_cube_imgview.cache_view_buffer_size);

    srv_mediacache_start(g_vadp_cube_imgview.cache_handle, index);  /* g_mmi_cube_imgview_cntx.cache_focus_index); */
}

void vadp_cube_imgview_change_to_navigation_mode(S32 index)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_CHANGE_TO_VIEW_MODE, g_vadp_cube_imgview.cache_handle, index);
        
    srv_mediacache_stop(g_vadp_cube_imgview.cache_handle); 
    
    srv_mediacache_remove_cache(
        g_vadp_cube_imgview.cache_handle,
        g_vadp_cube_imgview.cache_view_buffer);
    srv_mediacache_start(g_vadp_cube_imgview.cache_handle, index);  /* g_mmi_cube_imgview_cntx.cache_focus_index); */
}

U16 vadp_cube_imgview_get_forbid_item_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID string_id = 0;
    mmi_event_notify_enum event_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MRE_AM__
    if (mmi_am_is_using_media_memory())
    {
        S32 type;
        
        string_id = mmi_am_get_error_info(MMI_MRE_ERR_IS_UNAVAILABLE, &type);
        
        return string_id;
    }
#endif

#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        string_id = mmi_usb_get_error_info(MMI_USB_ERR_IS_UNAVAILABLE, &event_type);
        
        return string_id;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_FORBID_ITEM_INFO, string_id, event_type);
    
    return string_id;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void vadp_cube_imgview_register_clip_callback(srv_mediacache_engine_clip cb, void *user_data)
{
    srv_mediacache_register_engine_clip_function(cb, user_data);
}

void vadp_cube_imgview_fit_view_cell(S32 dest_w, S32 dest_h, S32 source_w, S32 source_h, PS32 x, PS32 y, PS32 w, PS32 h)
{
    gdi_util_fit_box(
        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
        dest_w,
        dest_h,
        source_w,
        source_h,
        x,
        y,
        w,
        h);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_FIT_VIEW_CELL, dest_w, dest_h, source_w, source_h, x, y, w, h);
}

S32 vadp_cube_imgview_get_image_info(S32 index, PS32 org_width, PS32 ori_height, PS32 resize_width, PS32 resize_height)
{
    S32 ret = -1;
    srv_mediacache_get_img_info_struct image_info;

    ret = srv_mediacache_get_image_info(g_vadp_cube_imgview.cache_handle, index, &image_info);
    *resize_width = image_info.resized_width;
    *resize_height = image_info.resized_height;
    *org_width = image_info.org_width;
    *ori_height = image_info.org_height;

    if ((image_info.resized_width == -1) ||
        (image_info.resized_height == -1) ||
        (image_info.org_width == -1) ||
        (image_info.org_height == -1))
    {
    #ifdef __DRM_SUPPORT__
        if (ret == DRM_RESULT_NO_PERMISSION)
        {
            return ret;
        }
    #endif

        if (image_info.is_cached)
        {
            ret = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        }
        else
        {
            ret = SRV_MEDIACACHE_ERR_DECODING;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_IMAGE_INFO, ret, *org_width, *ori_height, *resize_width, *resize_height);
    
    return ret;
}

S32 vadp_cube_imgview_get_image_buffer(S32 index, S32 dest_width, S32 dest_height, PS32 dest_resize_w, PS32 dest_resized_h, void **buffer, PS32 source)
{
    S32 result;
    srv_mediacache_img_to_buffer_struct buf;
    S32 image_width, image_height, org_width, org_height;
    S32 resize_x, resize_y, resize_w, resize_h;
    S32 real_source;

    result = vadp_cube_imgview_get_image_info(index, &org_width, &org_height, &image_width, &image_height);
    if (result != SRV_MEDIACACHE_OK)
    {
    #ifdef __DRM_SUPPORT__
        if (result == DRM_RESULT_NO_PERMISSION)
        {
            result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
        }
    #endif

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_IMAGE_BUFFER, index, result);
        return result;
    }

    vadp_cube_imgview_fit_view_cell(dest_width, dest_height, org_width, org_height, &resize_x, &resize_y, &resize_w, &resize_h);

    real_source = srv_mediacache_cell_can_draw_by_index(g_vadp_cube_imgview.cache_handle, index);

#if 1
    if (*source == SRV_MEDIACACHE_OK_L1)
    {
        if (real_source == SRV_MEDIACACHE_OK_L2)
        {
            *dest_resize_w = resize_w;
            *dest_resized_h = resize_h;

            *source = SRV_MEDIACACHE_OK_L2;
            return SRV_MEDIACACHE_OK;
        }
    }
#endif

    if (*source == SRV_MEDIACACHE_OK_L1)
    {
        buf.buffer = vadp_cube_imgview_get_back_buffer(index);
    }
    else
    {
        buf.buffer = vadp_cube_imgview_get_avail_buffer(index);
    }
    
    buf.length = resize_w * resize_h * 2;
    buf.width = resize_w;
    buf.height = resize_h;
    buf.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;
    buf.callback = NULL;
    buf.user_data = NULL;

    result = srv_mediacache_get_img_to_buffer(g_vadp_cube_imgview.cache_handle, index, &buf);
    if (result == SRV_MEDIACACHE_OK)
    {
        *dest_resize_w = resize_w;
        *dest_resized_h = resize_h;
        *buffer = buf.buffer;
        
        if ((*source == SRV_MEDIACACHE_OK_L1) && (real_source == SRV_MEDIACACHE_OK_L1))
        {
            vadp_cube_imgview_swap_buffer(index);
        }
        else
        {
            vadp_cube_imgview_set_used(index, MMI_TRUE);
        }
        *source = real_source;
    }
#ifdef __DRM_SUPPORT__
    else if (result == DRM_RESULT_NO_PERMISSION)
    {
        result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
#endif
    else
    {
        vadp_cube_imgview_set_used(index, MMI_FALSE);
        *source = SRV_MEDIACACHE_CACHE_TYPE_UNUSED;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_IMAGE_BUFFER, index, result);
    return result;
}

void vadp_cube_imgview_decode_callback2(S32 err_group,S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = SRV_MEDIACACHE_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_IMAGE_BUFFER, user_data, err_code);

    if (err_code == SRV_MEDIACACHE_OK)
    {
        error_code = SRV_MEDIACACHE_OK;
    }
    else if (err_code == SRV_MEDIACACHE_ERR_NOT_READY || 
        err_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
        err_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        error_code = err_code;
    }
    else
    {
        error_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
    }
    
    if (g_vadp_cube_imgview.decode_cb2)
    {
        g_vadp_cube_imgview.decode_cb2(g_vadp_cube_imgview.menu_ptr2, (S32)user_data, error_code);
    }
}

S32 vadp_cube_imgview_get_image_buffer_nonblocking(void *menu_ptr, S32 index, S32 dest_width, S32 dest_height, PS32 dest_resize_w, PS32 dest_resized_h, void **buffer, PS32 source, void(*callback)(void*, S32, S32))
{
    S32 result;
    srv_mediacache_img_to_buffer_struct buf;
    S32 image_width, image_height, org_width, org_height;
    S32 resize_x, resize_y, resize_w, resize_h;
    S32 real_source;

    result = vadp_cube_imgview_get_image_info(index, &org_width, &org_height, &image_width, &image_height);
    if (result != SRV_MEDIACACHE_OK)
    {
    #ifdef __DRM_SUPPORT__
        if (result == DRM_RESULT_NO_PERMISSION)
        {
            result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
            return result;
        }
    #endif

        srv_mediacache_goto_index(g_vadp_cube_imgview.cache_handle, index);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_IMAGE_BUFFER_NB, index, result);
        return result;
    }

    vadp_cube_imgview_fit_view_cell(dest_width, dest_height, org_width, org_height, &resize_x, &resize_y, &resize_w, &resize_h);

	real_source = srv_mediacache_cell_can_draw_by_index(g_vadp_cube_imgview.cache_handle, index);
    
#if 1
    if (*source == SRV_MEDIACACHE_OK_L1)
    {
        if (real_source == SRV_MEDIACACHE_OK_L2)
        {
			*dest_resize_w = resize_w;
            *dest_resized_h = resize_h;
			
            vadp_cube_imgview_focus_change(index);
            *source = SRV_MEDIACACHE_OK_L2;
            return SRV_MEDIACACHE_OK;
        }
    }
#endif

    if (*source == SRV_MEDIACACHE_OK_L1)
    {
        buf.buffer = vadp_cube_imgview_get_back_buffer(index);
    }
    else
    {
        buf.buffer = vadp_cube_imgview_get_avail_buffer(index);
    }

    g_vadp_cube_imgview.decode_cb2 = callback;
    g_vadp_cube_imgview.menu_ptr2 = menu_ptr;

    buf.length = resize_w * resize_h * 2;
    buf.width = resize_w;
    buf.height = resize_h;
    buf.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;
    buf.callback = vadp_cube_imgview_decode_callback2;
    buf.user_data = (void*)index;
    
    result = srv_mediacache_get_img_to_buffer(g_vadp_cube_imgview.cache_handle, index, &buf);
    if (result == SRV_MEDIACACHE_OK)
    {
        *dest_resize_w = resize_w;
        *dest_resized_h = resize_h;
        
        *buffer = buf.buffer;
        //*source = real_source;

        if ((*source == SRV_MEDIACACHE_OK_L1) && (real_source == SRV_MEDIACACHE_OK_L1))
        {
            vadp_cube_imgview_swap_buffer(index);
        }
        else
        {
            vadp_cube_imgview_set_used(index, MMI_TRUE);
        }
        *source = real_source;
    }
#ifdef __DRM_SUPPORT__
    else if (result == DRM_RESULT_NO_PERMISSION)
    {
        result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
#endif
    else
    {
        vadp_cube_imgview_set_used(index, MMI_FALSE);
        *source = SRV_MEDIACACHE_CACHE_TYPE_UNUSED;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_GET_IMAGE_BUFFER_NB, index, result);
    return result;
}


void vadp_cube_imgview_view_mode_free_image_buffer(S32 index, void *buffer)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_VIEW_MODE_FREE_IMAGE_BUFFER, index, buffer);

    vadp_cube_imgview_set_used(index, MMI_FALSE);
}


void vadp_cube_imgview_focus_change(S32 index)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_CUBE_IMGVIEW_FOCUS_CHANGE, g_vadp_cube_imgview.cache_handle, index);
    
    if (g_vadp_cube_imgview.cache_handle)
    {
        srv_mediacache_goto_index(g_vadp_cube_imgview.cache_handle, index);
    }
}

#endif /* __MMI_VUI_3D_CUBE_APP_IMGVIEW__ */ 

