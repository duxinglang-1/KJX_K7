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
 *  vapp_music_player_ctrlmediacache.cpp
 *
 * Project:
 * --------
 *  Media cache control
 *
 * Description:
 * ------------
 *  Media cache control implementation
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vapp_music_player_ctrlmediacache.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_ctrlplsv.h"
#include "vapp_music_player_util.h"
#include "drm_errcode.h"

extern "C"
{
#include "PlstSrvGprot.h"
#include "gdi_include.h"

/* extern from  media cache service */
void srv_mediacache_register_engine(srv_mediacache_eng_callbacks_struct *engine_p);
void srv_mediacache_decode_nb_decode_callback(S32 result, srv_mediacache_err_group_enum group, void *user_data);
}


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

VappMusicPlayerCtrlMediaCahce* VappMusicPlayerCtrlMediaCahce::g_this = NULL;

/***************************************************************************** 
 * VappMusicPlayerCtrlMediaCahce implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMusicPlayerCtrlMediaCahce", VappMusicPlayerCtrlMediaCahce, VfxObject);

void VappMusicPlayerCtrlMediaCahce::onInit()
{
    VfxObject::onInit();

    VappMusicPlayerContentProvider *provider = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerContentProvider);
    provider->m_signalPLSVCallback.connect(this, &VappMusicPlayerCtrlMediaCahce::onPLSVCallback);

    m_bufferImage = NULL;

    g_this = this;
}

void VappMusicPlayerCtrlMediaCahce::onDeinit()
{
    g_this = NULL;

    closeMediaCache();

    VfxObject::onDeinit();
}

void VappMusicPlayerCtrlMediaCahce::initMediaCache(VfxU32 itemCount, VfxU32 width, VfxU32 height, VfxU32 goToIndex)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_INIT, itemCount);

    closeMediaCache();

    m_count = itemCount;

    if (itemCount == 0)
    {
        return;
    }

    // set the size to resize
    m_imageSize = VfxSize(width, height);

    // initialize MediaCache 
    const U32 thumbCacheCount = (VfxU32)VAPP_MUSICPLY_MEDIACACHE_CACHE_COUNT;
    const U32 bytePerLevel2Thumb = width * height * (GDI_MAINLCD_BIT_PER_PIXEL >> 3);    
    const U32 mediaCacheWorkingSize = SRV_MEDIACACHE_RUN_BUF_SIZE(thumbCacheCount);
    
    const U32 cacheSize = thumbCacheCount * bytePerLevel2Thumb;

    const U32 totalHeapSize = mediaCacheWorkingSize + cacheSize;

    // allocate a big heap for MediaCache, SQLite and Thumbnail Level2 cache
    VfxApp *pApp = findRootApp(this);
    m_pMediaCacheHeap = applib_asm_alloc_nc_r(pApp->getGroupId(), totalHeapSize);
    
    if (m_pMediaCacheHeap == NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_INIT_FAIL);
        m_count = 0;
        return;
    }

    U8* pMCWorking = (U8*)m_pMediaCacheHeap;
    U8* pCache = pMCWorking + mediaCacheWorkingSize;
    m_pCachePtr = pCache;
    m_hMediaCache = srv_mediacache_create((void*)pMCWorking, mediaCacheWorkingSize);

    if (m_hMediaCache == NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_INIT_FAIL);
        m_count = 0;
        applib_asm_free_r(pApp->getGroupId(), m_pMediaCacheHeap);
        m_pMediaCacheHeap = NULL;
        return;
    }

    // use level2 cache
    srv_mediacache_config_level2_size(m_hMediaCache, width, height);
    VfxS32 ret = srv_mediacache_add_cache(
                    m_hMediaCache, 
                    SRV_MEDIACACHE_CACHE_TYPE_L2, 
                    pCache, 
                    cacheSize);

    if (ret != SRV_MEDIACACHE_OK)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_INIT_FAIL);
        closeMediaCache();
        return;
    }

    srv_mediacache_config_work_mode_to_prefetch_func(
        m_hMediaCache,
        itemCount,
        &VappMusicPlayerCtrlMediaCahce::getDataCallback);

    // set callback structure
    srv_mediacache_eng_callbacks_struct callback_struct;

    callback_struct.decode_cell = (srv_mediacache_nb_decode)(&VappMusicPlayerCtrlMediaCahce::decodeCell);
    callback_struct.cancel_decode_cell = (srv_mediacache_nb_decode_cancel)(&VappMusicPlayerCtrlMediaCahce::decodeCellCancel);
    callback_struct.search_cell = NULL;
    callback_struct.cancel_search_cell = NULL;
    callback_struct.user_data = reinterpret_cast<U32*>(this);
    srv_mediacache_register_engine(&callback_struct);

    srv_mediacache_config_schedule_policy(m_hMediaCache, SRV_MEDIACACHE_CACHE_METHOD_M1);

    srv_mediacache_start(m_hMediaCache, 0);

    //start from highlight index
    /////srv_mediacache_goto_index(m_hMediaCache, goToIndex);

    // allocate buffer for JPG draw data
    m_bufferImage = (U8*)applib_asm_alloc_nc_r(
                        pApp->getGroupId(), 
                        SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2
                        );
    VFX_ASSERT(m_bufferImage);

    m_isBusy = VFX_FALSE;

    // initialize media cache tasks array
    if (m_mcTasks)
    {
        VFX_FREE_MEM(m_mcTasks);
        m_mcTasks = NULL;
    }
    VFX_ALLOC_MEM(m_mcTasks, sizeof(MediaCacheTask) * itemCount, this);

    // initialize task state
    for (VfxU32 i = 0; i < itemCount; i++)
    {
        m_mcTasks[i].m_state = MediaCacheTask::NONE_PROC;
        m_mcTasks[i].m_imageBuffer.ptr = NULL;
        m_mcTasks[i].m_imageBuffer.width = 0;
        m_mcTasks[i].m_imageBuffer.height = 0;
        m_mcTasks[i].isLocked = VFX_FALSE;
    }

    m_state = RUN;

}

void VappMusicPlayerCtrlMediaCahce::startMediaCache(VfxTimer *timer)
{
    // only called by initMediaCache
    srv_mediacache_start(m_hMediaCache, 0);
}

void VappMusicPlayerCtrlMediaCahce::pauseMediaCache()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_PAUSE, m_state);

    if (m_hMediaCache && m_state == RUN)
    {
        srv_mediacache_pause_decode(m_hMediaCache);
        
        m_state = PAUSE;

        m_isBusy = VFX_FALSE;
    }
}

void VappMusicPlayerCtrlMediaCahce::resumeMediaCache()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_RESUME, m_state);

    if (m_hMediaCache && m_state == PAUSE)
    {
        srv_mediacache_resume_decode(m_hMediaCache);
        m_state = RUN;
    }
}

void VappMusicPlayerCtrlMediaCahce::closeMediaCache()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_MED_CACHE_CLOSE);

    VappMusicPlayerApp *pApp = VFX_OBJ_DYNAMIC_CAST(findRootApp(this), VappMusicPlayerApp);

    if (pApp && pApp->getProvider())
    {
	    pApp->getProvider()->getAlbumCoverAsyncCancel();
    }

    if(m_hMediaCache)
    {
        stopGDI();

        // unlock all cells
        VfxU32 index = 0;
        if (m_mediaCacheContext)
        {
            srv_mediacache_cell_struct *cell = (srv_mediacache_cell_struct*)m_mediaCacheContext->cache_block_start;
            if (cell)
            {
                while ((U8*)cell <= (U8*)m_mediaCacheContext->cache_block_end - sizeof(srv_mediacache_cell_struct))
                {
                    if (cell->buffer)
                    {
                        freeImageBuffer(cell->buffer, index);
                    }
                    cell++;
                    index++;
                };
            }
        }

        srv_mediacache_stop(m_hMediaCache);
        srv_mediacache_remove_cache(m_hMediaCache, m_pCachePtr);
        m_pCachePtr = NULL;
        srv_mediacache_destroy(m_hMediaCache);
        m_hMediaCache = 0;

        VFX_ASSERT(m_pMediaCacheHeap);
        applib_asm_free_r(pApp->getGroupId(), m_pMediaCacheHeap);
        m_pMediaCacheHeap = NULL;
    }

    if (m_bufferImage)
    {
        applib_asm_free_r(pApp->getGroupId(), m_bufferImage);
        m_bufferImage = NULL;
    }

    if (m_mcTasks)
    {
        VFX_FREE_MEM(m_mcTasks);
        m_mcTasks = NULL;
    }

    m_mediaCacheContext = NULL;
    m_decodingCell = NULL;

    m_count = 0;

    m_state = IDLE;

}

MCStateEnum VappMusicPlayerCtrlMediaCahce::getState()
{
    return m_state;
}

void VappMusicPlayerCtrlMediaCahce::setTask(const VfxU32 index, MediaCacheTask &task)
{
    if (index < m_count)
    {
        m_mcTasks[index].m_state = task.m_state;
        m_mcTasks[index].m_imageBuffer = task.m_imageBuffer;
        m_mcTasks[index].isLocked = task.isLocked;
    }
}

MediaCacheTask VappMusicPlayerCtrlMediaCahce::getTask(const VfxU32 index)
{
    if (index < m_count)
    {
        return m_mcTasks[index];
    }
    
    MediaCacheTask dump;
    dump.m_state = MediaCacheTask::DUMP;

    return dump;
}

VfxBool VappMusicPlayerCtrlMediaCahce::findNextNoneProcTask(const VfxU32 start, const VfxU32 end, VfxU32 &index)
{
    for (VfxU32 i = start; i <= end; i++)
    {
        MediaCacheTask task = getTask(i);
        if (task.m_state == MediaCacheTask::NONE_PROC || task.m_state == MediaCacheTask::PROCESSING)
        {
            index = i;
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

void VappMusicPlayerCtrlMediaCahce::resetTask()
{

    for (VfxU32 idx = 0; idx < m_count; idx++)
    {
        m_mcTasks[idx].m_state = MediaCacheTask::NONE_PROC;
        freeImageBuffer(m_mcTasks[idx].m_imageBuffer.ptr, idx);
    }
}

S32 VappMusicPlayerCtrlMediaCahce::getDataCallback(S32 index, WCHAR *buffer, U32 length, void *user_data)
{
    return MMI_TRUE;
}

MMI_BOOL VappMusicPlayerCtrlMediaCahce::decodeCell(
            U32 *handle,
            srv_mediacache_cell_struct *cell_p,
            srv_mediacache_nb_decode_callback done_callback,
            void *user_data)
{
    if (cell_p == NULL)
    {
        return MMI_FALSE;
    }

    VappMusicPlayerCtrlMediaCahce *pThis = g_this;
    if (!pThis)
    {
        return MMI_FALSE;
    }

    // If the decoding cell is not in current screen, return FALSE and decode later
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(findRootApp(pThis), VappMusicPlayerApp);
    if(!app->getProvider()->checkMediaCacheDecodeCellRange(cell_p->file_index))
    {
        pThis->m_isBusy = MMI_FALSE;
        app->getProvider()->getNextItemImage();
        return MMI_FALSE;
    }

    pThis->stopGDI();

    pThis->m_mediaCacheContext = reinterpret_cast<srv_mediacache_cntx_struct*>(user_data);
    pThis->m_decodingCell = cell_p;

    pThis->m_plsvImageStruct.index = cell_p->file_index;
    pThis->m_plsvImageStruct.buff_size = SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2;
    pThis->m_plsvImageStruct.string_ptr = (U32)pThis->m_bufferImage;

    VappMusicPlayerContentProvider *provider = VFX_OBJ_DYNAMIC_CAST(pThis->getParent(), VappMusicPlayerContentProvider);
    VfxS32 ret = provider->getAlbumCoverAsync(&pThis->m_plsvImageStruct);
    if (ret < 0)
    {
        cell_p->err_code = ret;
        cell_p->err_group = SRV_MEDIACACHE_ERR_GROUP_FS;
        cell_p = NULL;
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

MMI_BOOL VappMusicPlayerCtrlMediaCahce::decodeCellCancel(U32 handle)/////, void* user_data)
{
    VappMusicPlayerCtrlMediaCahce *pThis = g_this;
    if (!pThis)
    {
        return MMI_FALSE;
    }

    // stop GDI
    pThis->stopGDI();

    // stop PLSV async get image
    VappMusicPlayerContentProvider *provider = VFX_OBJ_DYNAMIC_CAST(pThis->getParent(), VappMusicPlayerContentProvider);
    provider->getAlbumCoverAsyncCancel();

    // disable busy state
    pThis->m_isBusy = VFX_FALSE;

    // Will use when close media cache
    //pThis->m_mediaCacheContext = NULL;
    pThis->m_decodingCell = NULL;

    return MMI_TRUE;
}

VfxBool VappMusicPlayerCtrlMediaCahce::decodeImage(
            S32 ret,
            U8 *imgBuffer,
            S32 imgWidth,
            S32 imgHeight,
            S32 bufferSize)
{
    if (!g_this
     || !m_mediaCacheContext
     || !m_decodingCell
     || getState() == IDLE)
    {
        m_isBusy = VFX_FALSE;
        return VFX_FALSE;
    }

    if (ret != 0)
    {
        m_decodingCell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        m_decodingCell->err_code = ret;
        m_decodingCell->err_group = SRV_MEDIACACHE_ERR_GROUP_FS;
        m_decodingCell = NULL;

        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            m_mediaCacheContext);

        VfxImageBuffer imgBuf;
        imgBuf.ptr = NULL;
        imgBuf.width = 0;
        imgBuf.height = 0;
        imgBuf.pitchBytes = 0;

        MediaCacheTask task;
        task.m_state = MediaCacheTask::NO_THUMB;
        task.m_imageBuffer = imgBuf;
        setTask(m_plsvImageStruct.index, task);

        return VFX_FALSE;
    }

    else if (imgWidth <= 0 || imgHeight <= 0 
     || imgWidth > SRV_MEDIACACHE_DECODE_MAX_W_H || imgHeight > SRV_MEDIACACHE_DECODE_MAX_W_H)
    {
        // fail
        m_decodingCell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        m_decodingCell->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        m_decodingCell->err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        m_decodingCell = NULL;
     
        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            m_mediaCacheContext);

        return VFX_FALSE;
    }

    m_decodingCell->image_type = GDI_IMAGE_TYPE_JPG_FILE;
    // NOTE: this function will adjust cell size!
    // and it have rounding issues.
    srv_mediacache_cache_fill_cell_by_img(imgWidth, imgHeight, m_decodingCell);
    if (m_decodingCell->image_width <= 0 || m_decodingCell->image_height <= 0)
    {
        // fail
        m_decodingCell->state = SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR;
        m_decodingCell->err_code = SRV_MEDIACACHE_ERR_NOT_SUPPORT;
        m_decodingCell->err_group = SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE;
        m_decodingCell = NULL;

        srv_mediacache_decode_nb_decode_callback(
            (S32) SRV_MEDIACACHE_ERR_NOT_SUPPORT,
            SRV_MEDIACACHE_ERR_GROUP_GDI,
            m_mediaCacheContext);

        return VFX_FALSE;
    }
    else
    {
        ASSERT(m_decodingCell->image_width > 0);
        ASSERT(m_decodingCell->image_height > 0);

        // decode JPG to buffer
        const VfxU32 bufferLength = srv_mediacache_cache_get_img_size_by_type(m_decodingCell->type);
        
        // HACK: we follow srv_mediacache_engine_gdi_nb_decode implementation,
        // override image width and height by L2 size.
        m_decodingCell->image_width = m_imageSize.width;
        m_decodingCell->image_height = m_imageSize.height;
        VFX_ASSERT(bufferLength >= (m_decodingCell->image_width * m_decodingCell->image_height * 2));

        const VfxS32 w = m_decodingCell->image_width;
        const VfxS32 h = m_decodingCell->image_height;
        const VfxS32 layerW = w;
        const VfxS32 layerH = h;
        
        gdi_layer_create_using_outside_memory(
            0,
            0,
            layerW,
            layerH,
            &m_gdiLayer,
            m_decodingCell->buffer,
            bufferLength);

        gdi_layer_push_and_set_active(m_gdiLayer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
        m_hGdiDecode = gdi_imgdec_nb_draw_resized_mem(
            m_gdiLayer,
            0, 0, 
            w, h, 
            GDI_IMAGE_TYPE_JPG,
            bufferSize,
            imgBuffer,
            &VappMusicPlayerCtrlMediaCahce::gdiDecodeDoneCallback
            );
        gdi_layer_pop_and_restore_active();

        return VFX_TRUE;
    }

    return VFX_FALSE;
}

void VappMusicPlayerCtrlMediaCahce::setDecodeCallback(VappMusicPlayerCtrlMediaCacheDecodeCallback callback, void *user_data)
{
    m_decodeCallback = callback;
    m_userData = user_data;
}

VfxU32 VappMusicPlayerCtrlMediaCahce::getCount()
{
    return m_count;
}

DecodeResult VappMusicPlayerCtrlMediaCahce::getImageBuffer(
                VfxU32 index,
                VfxImageBuffer& buffer,
                VfxBool forceGet)
{
    if (m_hMediaCache == NULL)
    {
        //VFX_DEV_ASSERT(m_hMediaCache != NULL);
        m_isBusy = VFX_FALSE;
        return MC_NOT_READY;
    }

    // if task is ready, return OK with decoded image buffer
    MediaCacheTask mcTask = getTask(index);
    if (mcTask.m_state == MediaCacheTask::HAS_THUMB && mcTask.isLocked)
    {
        buffer = mcTask.m_imageBuffer;
        return MC_OK;
    }
    else if (mcTask.m_state == MediaCacheTask::NO_THUMB)
    {
        return EMPTY;
    }

    if (m_isBusy)
    {
        if (forceGet)
        {
            // forceGet = TRUE indicates that this query is the image cell of current view, should be decoded with high priority
            m_isBusy = VFX_FALSE;
        }
        else
        {
            return BUSY;
        }
    }

    // if not ready, lock buffer and try to decode
    srv_mediacache_lock_img_buffer_addr_struct lockedImage;
    lockedImage.user_data = this;
    lockedImage.callback = (srv_mediacache_data_cb)(&VappMusicPlayerCtrlMediaCahce::onMediaCacheDecodeResult);
    lockedImage.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE;

    VfxS32 error_code = srv_mediacache_lock_img_buffer_addr(m_hMediaCache, index, &lockedImage);

    switch(error_code)
    {
        case SRV_MEDIACACHE_OK:
            {
                const int BPP = 2;

                buffer.ptr = reinterpret_cast<VfxU8*>(lockedImage.buffer);
                buffer.colorFormat = VRT_COLOR_TYPE_RGB565;
                buffer.pitchBytes = m_imageSize.width * BPP;
                buffer.width = m_imageSize.width;
                buffer.height = m_imageSize.height;

                VfxImageBuffer taskImgBuffer;
                taskImgBuffer.ptr = reinterpret_cast<VfxU8*>(lockedImage.buffer);
                taskImgBuffer.colorFormat = VRT_COLOR_TYPE_RGB565;
                taskImgBuffer.pitchBytes = m_imageSize.width * BPP;
                taskImgBuffer.width = m_imageSize.width;
                taskImgBuffer.height = m_imageSize.height;

                MediaCacheTask task;
                task.m_state = MediaCacheTask::HAS_THUMB;
                task.m_imageBuffer = taskImgBuffer;
                task.isLocked = VFX_TRUE;
                setTask(index, task);

                m_isBusy = VFX_FALSE;
                return MC_OK;
            }
        case SRV_MEDIACACHE_ERR_NOT_READY:
        case SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE:
        case SRV_MEDIACACHE_ERR_DECODING:
        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
            {
                MediaCacheTask task;
                task.m_state = MediaCacheTask::PROCESSING;
                setTask(index, task);

                m_isBusy = VFX_TRUE;
            }
            return DECODING;

#ifdef __DRM_SUPPORT__
        case DRM_RESULT_NO_PERMISSION:
            {
                MediaCacheTask task;
                task.m_state = MediaCacheTask::DRM_THUMB;
                setTask(index, task);

                m_isBusy = VFX_FALSE;
            }
            return DRM_LOCKED;
#endif

        default:
            {

                MediaCacheTask task;
                task.m_state = MediaCacheTask::NO_THUMB;
                setTask(index, task);

                m_isBusy = VFX_FALSE;
            }
            return FORMAT_UNSUPPORTED;
    }

    MediaCacheTask task;
    task.m_state = MediaCacheTask::NO_THUMB;
    setTask(index, task);

    m_isBusy = VFX_FALSE;
    return UNEXPECTED;
}

VfxBool VappMusicPlayerCtrlMediaCahce::freeImageBuffer(void* buffer, const VfxU32 index)
{
    if (m_hMediaCache)
    {
        S32 errorCode = srv_mediacache_unlock_img_buffer(m_hMediaCache, buffer);

        // reset the unfinished task
        MediaCacheTask task = getTask(index);
        task.m_state = MediaCacheTask::NONE_PROC;
        task.m_imageBuffer.ptr = NULL;
        task.isLocked = VFX_FALSE;
        setTask(index, task);

        if (errorCode == SRV_MEDIACACHE_OK)
        {
            return VFX_TRUE;
        }
    }
    
    return VFX_FALSE;
}

void VappMusicPlayerCtrlMediaCahce::onPLSVCallback(srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2)
{
    if (cb_event == SRV_PLST_CB_EVT_GET_IMAGE)
    {
        if (!g_this
         || !m_mediaCacheContext
         || !m_decodingCell
         || getState() == IDLE)
        {
            m_isBusy = VFX_FALSE;
            return;
        }

        VfxS32 imageW = 0;
        VfxS32 imageH = 0;
        VfxS32 bufferSize = 0;
        U8 *ptr = NULL;

        if (ca_para_2 != m_plsvImageStruct.index
         || ca_para_2 != m_decodingCell->file_index)
        {
            // Index unsync, try to get album cover again
            VappMusicPlayerContentProvider *provider = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerContentProvider);
            VfxS32 ret = provider->getAlbumCoverAsync(&m_plsvImageStruct);
            return;
        }

        if (SRV_PLST_OK == result)
        {
            if (m_plsvImageStruct.buff_size > 0)
            {
                // successfully get JPG data from DB
                VfxS32 ret = gdi_image_get_dimension_mem(
                                GDI_IMAGE_TYPE_JPG,
                                m_bufferImage,
                                m_plsvImageStruct.buff_size,
                                &imageW,
                                &imageH);
                
                bufferSize = m_plsvImageStruct.buff_size;
                ptr = m_bufferImage;
                
                if (!decodeImage(ret, ptr, imageW, imageH, bufferSize))
                {
                    // disable busy state if decode fail
                    m_isBusy = VFX_FALSE;
                }
                return;
            }
            else    // buff_size == 0 means no album cover
            {
                // cell processed fail
                m_isBusy = VFX_FALSE;
            }
        }

        decodeImage(-1, ptr, imageW, imageH, bufferSize);

        // disable busy state if decode fail
        m_isBusy = VFX_FALSE;
    }
}

void VappMusicPlayerCtrlMediaCahce::onMediaCacheDecodeResult(S32 errGroup, S32 errCode, void *userData)
{
    DecodeResult retErrorCode = UNEXPECTED;
    VappMusicPlayerCtrlMediaCahce *pThis = reinterpret_cast<VappMusicPlayerCtrlMediaCahce*>(userData);
    
    if (errCode == SRV_MEDIACACHE_OK)
    {
        retErrorCode = MC_OK;
    }
    else if (errCode == SRV_MEDIACACHE_ERR_NOT_READY || 
             errCode == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE)
    {
        retErrorCode = UNEXPECTED;
    }
    else if (errCode == SRV_MEDIACACHE_ERR_DECODING)
    {
        retErrorCode = DECODING;
    }
    else
    {
        retErrorCode = FORMAT_UNSUPPORTED;
    }

    pThis->m_isBusy = retErrorCode == DECODING;
    
    if (retErrorCode == MC_OK && pThis->m_decodingCell)
    {
        srv_mediacache_lock_img_buffer_addr_struct lockedImage;
        lockedImage.user_data = NULL;
        lockedImage.callback = NULL;
        lockedImage.source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;

        const VfxU32 index = pThis->m_plsvImageStruct.index;
        MediaCacheTask task = pThis->getTask(index);
        if (task.m_state == MediaCacheTask::PROCESSING)
        {
            VfxS32 error_code = srv_mediacache_lock_img_buffer_addr(pThis->m_hMediaCache, pThis->m_decodingCell->file_index, &lockedImage);
            if (error_code == SRV_MEDIACACHE_OK)
            {
                task.m_state = MediaCacheTask::HAS_THUMB;
                task.isLocked = VFX_TRUE;
                pThis->setTask(index, task);
            }
        }
    }
    else if (retErrorCode == UNEXPECTED || retErrorCode == FORMAT_UNSUPPORTED)
    {
        // cell processed fail
        const VfxU32 index = pThis->m_plsvImageStruct.index;

        VfxImageBuffer imgBuf;
        imgBuf.ptr = NULL;
        imgBuf.width = 0;
        imgBuf.height = 0;
        imgBuf.pitchBytes = 0;
        
        MediaCacheTask task;
        task.m_state = MediaCacheTask::NO_THUMB;
        task.m_imageBuffer = imgBuf;
        pThis->setTask(index, task);

        pThis->m_decodeCallback(index, retErrorCode, imgBuf, pThis->m_userData);
    }

    // media cache decode cell schedule complete
    // waiting for GDI decoding JPG
    
}

void VappMusicPlayerCtrlMediaCahce::gdiDecodeDoneCallback(GDI_RESULT result, gdi_handle handle)
{
    VappMusicPlayerCtrlMediaCahce *pThis = g_this;
    if (!g_this
     || !pThis->m_mediaCacheContext
     || !pThis->m_decodingCell
     || pThis->getState() == IDLE)
    {

        pThis->m_isBusy = VFX_FALSE;
        pThis->stopGDI();
        return;
    }

    if(handle != pThis->m_hGdiDecode)
    {
        pThis->m_isBusy = VFX_FALSE;
        return;
    }

    if (pThis->m_decodingCell)
    {
        pThis->m_decodingCell->image_width = pThis->m_imageSize.width;
        pThis->m_decodingCell->image_height = pThis->m_imageSize.height;
    }

    if (pThis->m_mediaCacheContext && pThis->m_mediaCacheContext->decoding_p)
    {
        pThis->m_mediaCacheContext->decoding_p->image_width = pThis->m_imageSize.width;
        pThis->m_mediaCacheContext->decoding_p->image_height = pThis->m_imageSize.height;
    }

    srv_mediacache_decode_nb_decode_callback((S32)result, SRV_MEDIACACHE_ERR_GROUP_GDI, pThis->m_mediaCacheContext);

    VfxImageBuffer imgBuf;
    imgBuf.ptr = pThis->m_decodingCell->buffer;
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    imgBuf.pitchBytes = pThis->m_imageSize.width * 2;
    imgBuf.width = pThis->m_imageSize.width;
    imgBuf.height = pThis->m_imageSize.height;

    // disable busy state after GDI decoding
    pThis->m_isBusy = VFX_FALSE;

    const VfxU32 index = pThis->m_decodingCell->file_index;
    MediaCacheTask task = pThis->getTask(index);

    if (result == GDI_SUCCEED)
    {
        // success
        task.m_imageBuffer = imgBuf;
        pThis->setTask(index, task);

        pThis->m_decodeCallback(index, GDI_OK, imgBuf, pThis->m_userData);
    }
    else
    {
        // fail
        task.m_state = MediaCacheTask::NO_THUMB;
        pThis->setTask(index, task);

        pThis->m_decodeCallback(index, UNEXPECTED, imgBuf, pThis->m_userData);
    }

    pThis->stopGDI();

}

void VappMusicPlayerCtrlMediaCahce::stopGDI()
{

    if (m_hGdiDecode != 0)
    {
        gdi_imgdec_nb_stop(m_hGdiDecode);
        m_hGdiDecode = 0;
    }

    if (m_gdiLayer != 0)
    {
        gdi_layer_free(m_gdiLayer);
        m_gdiLayer = 0;
    }
}

#endif //__COSMOS_MUSICPLY__
