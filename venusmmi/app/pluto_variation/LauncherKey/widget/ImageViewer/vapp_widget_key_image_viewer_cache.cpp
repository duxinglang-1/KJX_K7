/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_key_image_viewer_cache.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_key_image_viewer_cache.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "FileMgrSrvGProt.h"

#include "ImageViewerGprot.h"
#include "ImageViewCuiGprot.h"

#include "fs_gprot.h"

#include "med_api.h"

#include "gdi_include.h"
#include "gdi_const.h"

#ifdef __DRM_SUPPORT__
#include "drm_errcode.h"
#endif 

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappWidgetKeyImageViewerCache
 *****************************************************************************/

VfxU8 g_widget_key_image_viewer_filelist_buf[VAPP_WIDGET_KEY_IMAGE_VIEWER_FILELIST_MEM_SIZE];

//VfxS32 VappWidgetKeyImageViewerCache::m_imgIdx = 0;
VfxU16 VappWidgetKeyImageViewerCache::m_storage = 0;
VfxU32 VappWidgetKeyImageViewerCache::m_imgCount = 0;

SRV_FMGR_FILELIST_HANDLE VappWidgetKeyImageViewerCache::m_fileListHandle = NULL;

VFX_IMPLEMENT_CLASS("VappWidgetKeyImageViewerCache", VappWidgetKeyImageViewerCache, VfxObject);

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

VfxU32 VappWidgetKeyImageViewerCache::getImageCount()
{
	return m_imgCount;
}

SRV_FMGR_FILELIST_HANDLE VappWidgetKeyImageViewerCache::getFileList()
{
	return m_fileListHandle;
}

VfxBool VappWidgetKeyImageViewerCache::getFolderPath()
{
	VfxU16 storage = mmi_imgview_get_storage();

	if (m_storage != storage)
	{
		reset();
		m_storage = storage;
	}

	if (FS_NO_ERROR == FS_GetDevStatus(m_storage, FS_MOUNT_STATE_ENUM))
    {
        kal_wsprintf(m_pFolderBuf, "%c:\\%w", m_storage, FMGR_DEFAULT_FOLDER_PHOTOS);

        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool VappWidgetKeyImageViewerCache::startCache(VfxS32 imgIdx)
{
	m_startIdx = imgIdx;
	return createFileList();
}

void VappWidgetKeyImageViewerCache::stopCache(VfxBool isDestroyFileList)
{
	destroyMediaCahce();
	if (isDestroyFileList)
	{
		freeFileList();
	}
}

VfxBool VappWidgetKeyImageViewerCache::createFileList()
{
	S32 ret = 0;

	if (getFolderPath())
	{
		if (!m_fileListHandle)
		{
			FMGR_FILTER filter;
		    FMGR_FILTER_INIT(&filter);
		    FMGR_FILTER_SET_IMAGE(&filter);
		    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_FOLDER);
		    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
		    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
		#ifdef __MMI_IMAGE_VIEWER_EX__
		    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_SVG);
		#endif
		#if defined(__DRM_V02__)
		    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
		#endif

			if (!m_pFileListBuf)
			{			
				//media_get_ext_buffer(stack_get_active_module_id(), &m_pFileListBuf, VAPP_WIDGET_KEY_IMAGE_VIEWER_FILELIST_MEM_SIZE);        

				m_pFileListBuf = g_widget_key_image_viewer_filelist_buf;
				VFX_ASSERT(m_pFileListBuf != NULL);
			}

			ret = srv_fmgr_folder_filelist_create(
					m_pFolderBuf,
					&filter,
					FS_SORT_TIME,
					m_pFileListBuf,
					VAPP_WIDGET_KEY_IMAGE_VIEWER_FILELIST_MEM_SIZE,
					&m_fileListHandle);

			if (ret < FS_NO_ERROR)
				return VFX_FALSE;

		}	
		else if (srv_fmgr_filelist_is_dirty(m_fileListHandle))
		{
			//notify to change image index to 0
			m_signalMsg.emit(FILE_LIST_DIRTY);
		}

		ret = srv_fmgr_filelist_refresh(
				m_fileListHandle,
				NULL,
				m_startIdx,
				0,
				&VappWidgetKeyImageViewerCache::fmgrEventHdlr,
				this);

		if (ret >= FS_NO_ERROR)
			return VFX_TRUE;
	}
	else
	{
		reset();
	}

	return VFX_FALSE;
}

void VappWidgetKeyImageViewerCache::reset()
{
	m_signalMsg.emit(FILE_LIST_RESET);
	freeFileList();
	destroyMediaCahce();
	m_imgCount = 0;
}

void VappWidgetKeyImageViewerCache::freeFileList()
{
	if (m_fileListHandle)
    {
        srv_fmgr_filelist_destroy(m_fileListHandle);
        m_fileListHandle = NULL;

		if (m_pFileListBuf)
		{
			//media_free_ext_buffer(stack_get_active_module_id(), (void**)&m_pFileListBuf);
        	m_pFileListBuf = NULL;
		}
    }
}

mmi_ret VappWidgetKeyImageViewerCache::fmgrEventHdlr(mmi_event_struct * evt)
{
	VappWidgetKeyImageViewerCache *cacher = (VappWidgetKeyImageViewerCache*)evt->user_data;
	
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
            cacher->fileListRefreshHdlr(evt);
            break;
        
        default:
            break;
    }

    return MMI_RET_OK;
}

void VappWidgetKeyImageViewerCache::fileListRefreshHdlr(mmi_event_struct * evt)
{
	srv_fmgr_filelist_refresh_result_event_struct *refresh_evt = (srv_fmgr_filelist_refresh_result_event_struct*)evt;
	
    m_fileListHandle = refresh_evt->handle;

	VfxU32 count = srv_fmgr_filelist_count(m_fileListHandle);

	if (m_imgCount != count)
	{
		//if add, delete images, notify to change image index to 0
		m_signalMsg.emit(FILE_LIST_DIRTY);
		m_imgCount = count;
	}

	if (m_imgCount == 0)
	{
		m_signalMsg.emit(FILE_LIST_EMPTY);
	}
	else
	{
		createMediaCache();
	}	
}

void VappWidgetKeyImageViewerCache::createMediaCache()
{
	if (m_mediaCacheHandle)
		return;

	if (m_imgCount > VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_MAX)
    {
        m_isOverSortLimit = VFX_TRUE;
    }
    else
    {
        m_isOverSortLimit = VFX_FALSE;
    }
	
    /* allocate memory */
    if (!m_pMediaCacheBuf)
    {
        media_get_ext_buffer(stack_get_active_module_id(), &m_pMediaCacheBuf, VAPP_WIDGET_KEY_IMAGE_VIEWER_MED_MEM_SIZE);        
        VFX_ASSERT(m_pMediaCacheBuf != NULL);
    }        

	void *mediacache_run_buf_p = m_pMediaCacheBuf;
    void *sqlite_buf_p = (void*)((kal_uint32)mediacache_run_buf_p + VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_RUN_BUFFER_SIZE);
        
	m_mediaCacheHandle = srv_mediacache_create(mediacache_run_buf_p, VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_RUN_BUFFER_SIZE);

	VFX_ASSERT(m_mediaCacheHandle != NULL);

	srv_mediacache_ex_define_db_io_buffer_length(VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_SIZE);

#if defined(__MMI_IMAGE_VIEWER_EX_DB__) && defined(__SQLITE3_SUPPORT__)
    srv_mediacache_config_db(
        m_mediaCacheHandle, 
        sqlite_buf_p, 
        VAPP_WIDGET_KEY_IMAGE_VIEWER_SQLITE_BUFFER_SIZE,
        (WCHAR *)m_pFolderBuf,
        (WCHAR *)L"WidgetKeyImageViewer.db"); 
#endif

    srv_mediacache_config_level2_size(m_mediaCacheHandle, CELL_WIDTH, CELL_HEIGHT);

	srv_mediacache_config_work_mode_to_filelist(m_mediaCacheHandle, m_fileListHandle);            
            
    srv_mediacache_add_cache(
        m_mediaCacheHandle, 
        SRV_MEDIACACHE_CACHE_TYPE_L2, 
        (void*)((kal_uint32)sqlite_buf_p + VAPP_WIDGET_KEY_IMAGE_VIEWER_SQLITE_BUFFER_SIZE), 
        VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_BUFFER_SIZE);
            
	srv_mediacache_register_engine_clip_function(imageClipHdlr, this);
            
	srv_mediacache_start(m_mediaCacheHandle, m_startIdx);

    if (m_isOverSortLimit)
    {
        srv_mediacache_pause_decode(m_mediaCacheHandle);
    }

	m_signalMsg.emit(MEDIA_CACHE_START);
}

void VappWidgetKeyImageViewerCache::destroyMediaCahce()
{
	if (m_mediaCacheHandle)
    {
        void *cache_buffer_p = (void*)((kal_uint32)m_pMediaCacheBuf
					                + VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_RUN_BUFFER_SIZE
					                + VAPP_WIDGET_KEY_IMAGE_VIEWER_SQLITE_BUFFER_SIZE);
        srv_mediacache_stop(m_mediaCacheHandle);
        srv_mediacache_remove_cache(m_mediaCacheHandle, cache_buffer_p);
        srv_mediacache_destroy(m_mediaCacheHandle);
        m_mediaCacheHandle = NULL;
    }

    if (m_pMediaCacheBuf)
    {
        media_free_ext_buffer(stack_get_active_module_id(), (void**)&m_pMediaCacheBuf);
        m_pMediaCacheBuf = NULL;
    }
}

void VappWidgetKeyImageViewerCache::imageClipHdlr(U32 * handle,S32 * layer_w,S32 * layer_h,srv_mediacache_rect_struct * img_org,srv_mediacache_rect_struct * img_resized,void * user_data)
{
	if (img_org->width <= CELL_WIDTH && img_org->height <= CELL_HEIGHT)
	{
		img_resized->width = img_org->width;
        img_resized->height = img_org->height;
        *layer_w = img_org->width;
        *layer_h = img_org->height;
	}
	else if (img_org->width <= CELL_WIDTH && img_org->height > CELL_HEIGHT)
	{
		img_resized->x = 0;
		img_resized->y = (CELL_HEIGHT - img_org->height)/2;
		img_resized->width = img_org->width;
        img_resized->height = img_org->height;
        *layer_w = img_org->width;
        *layer_h = CELL_HEIGHT;
	}
	else if (img_org->width > CELL_WIDTH && img_org->height <= CELL_HEIGHT)
	{
		img_resized->x = (CELL_WIDTH - img_org->width)/2;
		img_resized->y = 0;
		img_resized->width = img_org->width;
        img_resized->height = img_org->height;
        *layer_w = CELL_WIDTH;
        *layer_h = img_org->height;
	}
	else
	{
		VfxS32 resized_offset_x, resized_offset_y, resized_width, resized_height;
        VfxFloat img_scale = (FLOAT)img_org->width / (FLOAT)img_org->height;
        VfxFloat cell_scale = (FLOAT)CELL_WIDTH / (FLOAT)CELL_HEIGHT;

        if (img_scale <= cell_scale)
        {
        	resized_width = CELL_WIDTH;
			resized_height = (VfxS32)(resized_width / img_scale);
            resized_offset_x = 0;
			resized_offset_y = (CELL_HEIGHT - resized_height)/2;
        }
        else
        {
			resized_height = CELL_HEIGHT;
			resized_width = (VfxS32)(resized_height * img_scale);
            resized_offset_x = (CELL_WIDTH - resized_width)/2;
			resized_offset_y = 0;
        }
	
		img_resized->x = resized_offset_x;
		img_resized->y = resized_offset_y;
		img_resized->width = resized_width;
        img_resized->height = resized_height;
        *layer_w = CELL_WIDTH;
        *layer_h = CELL_HEIGHT;
	}	
}

VfxS32 VappWidgetKeyImageViewerCache::getErrorCode(VfxS32 ret)
{
	return 0;
}

VfxS32 VappWidgetKeyImageViewerCache::lockImageBufferBlock(
	srv_mediacache_image_source_enum source,
	VfxS32 imgIdx,
	void * * buffer)
{
	VfxS32 ret = 0;
    srv_mediacache_lock_img_buffer_addr_struct lock_img;
	lock_img.callback = NULL;
    lock_img.user_data = NULL;
    lock_img.source = source;

    if (m_mediaCacheHandle == NULL)
        return -0x00222222;
    
    if (m_isOverSortLimit)
    {
        srv_mediacache_resume_decode(m_mediaCacheHandle);
    }
            
    ret = srv_mediacache_lock_img_buffer_addr(m_mediaCacheHandle, imgIdx, &lock_img);

    if (m_isOverSortLimit)
    {
        srv_mediacache_pause_decode(m_mediaCacheHandle);
    }

	if (ret == SRV_MEDIACACHE_OK)
	{
		*buffer = lock_img.buffer;
	}
            
    return ret;
}

VfxS32 VappWidgetKeyImageViewerCache::lockImageBufferNonBlock(
		srv_mediacache_image_source_enum source,
		srv_mediacache_data_cb cb,
		void *user_data,
		VfxS32 imgIdx,
		void * * buffer)
{
	VfxS32 ret = 0;
	srv_mediacache_lock_img_buffer_addr_struct lock_img;
    lock_img.callback = cb;
    lock_img.user_data = user_data;
    lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;
	//lock_img.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE;
	
    if (m_mediaCacheHandle == NULL)
        return -0x00222222;
    
    if (m_isOverSortLimit)
    {
        srv_mediacache_resume_decode(m_mediaCacheHandle);
    }
            
    ret = srv_mediacache_lock_img_buffer_addr(m_mediaCacheHandle, imgIdx, &lock_img); 

	if (ret == SRV_MEDIACACHE_OK)
	{
		*buffer = lock_img.buffer;
	}
            
    return ret;
}

VfxS32 VappWidgetKeyImageViewerCache::unlockImageBuffer(void * buffer)
{
	VfxS32 ret = 0;
	if (m_mediaCacheHandle)
	{
		ret = srv_mediacache_unlock_img_buffer(m_mediaCacheHandle, buffer);
	}

	return ret;
}

VfxS32 VappWidgetKeyImageViewerCache::getImageInfo(VfxS32 imgIdx, VfxS32 * resized_width,VfxS32 * resized_height)
{
	VfxS32 ret = 0;
	srv_mediacache_get_img_info_struct img_info;
	
	if (!m_mediaCacheHandle)
        return -0x00222222;
    
    ret = srv_mediacache_get_image_info(m_mediaCacheHandle, imgIdx, &img_info);

    if (ret >= SRV_MEDIACACHE_OK)
    {
        *resized_width = img_info.resized_width;
        *resized_height = img_info.resized_height;        
    }
    else
    {
        *resized_width = 0;
        *resized_height = 0;

        VFX_ASSERT(0);
    }
    return ret;
}

void VappWidgetKeyImageViewerCache::goToIndex(VfxS32 idx)
{
	srv_mediacache_goto_index(m_mediaCacheHandle, idx);
}

#endif

