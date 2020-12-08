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
 *  vapp_gallery_data.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_GALLERY_SLIM__

#include "vapp_gallery_slim_data.h"
#include "drm_errcode.h"
#include "mdi_video.h"
#include "vapp_fmgr_table.h" // FIXME: should provide global header for commond folders?
#include "vapp_gallery_slim_util.h"
#include "vapp_gallery_slim.h"
extern "C"
{
#include "cache_sw.h"
#include "mmi_rp_file_type_def.h"
#include "kal_trace.h"
#include "app_mem_med.h"
#include "drm_gprot.h"
#include "gdi_include.h"
#include "gdi_primitive.h"
#include "gdi_lcd.h"
#include "gdi_imgdec.h"
#include "gdi_linear_transform.h"
}

extern "C"
{
#include "MMI_media_app_trc.h"
}

/*****************************************************************************
 * Typedef
 *****************************************************************************/

// Heap-allocated object representing a decod request
class DecodeJob : public VfxObject
{
public:
    IVappGalleryMediaList *m_pList;
    VcpMenuPos m_itemIndex;
};


static void _intersectFilter(FMGR_FILTER &dst, const FMGR_FILTER &src)
{
    for(VfxS32 i = 0; i < sizeof(dst.mask) / sizeof(dst.mask[0]); ++i)
    {
        dst.mask[i] &= src.mask[i];
    }
    return;
}

/*****************************************************************************
 * Functions
 *****************************************************************************/
static VfxBool shouldReplaceSrcKey(VfxS32 targetW, VfxS32 targetH)
{
    // for 24-bit on 76/56,
    // don't replace color key when decode large image (more than 2x LCD)
    // it will be replaced in owner draw when resize / transformed
    #if defined(__ARM1176__) && defined(VAPP_GALLERY_IMG_VIEWER_BPP) && (VAPP_GALLERY_IMG_VIEWER_BPP == 3)
    const VfxBool replaceSrcKey = (targetW * targetH) <= (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 2);
    #else
    const VfxBool replaceSrcKey = VFX_TRUE;
    #endif
    return replaceSrcKey;
}

#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
/*****************************************************************************
 * IVappGalleryMediaListAsync
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryMediaListAsync",VappGalleryMediaListAsync,IVappGalleryMediaList);
VappGalleryMediaListAsync::VappGalleryMediaListAsync():
    m_cacheType(CACHE_TYPE_THUMBNAIL),
    m_provider(NULL),
    m_decoder(NULL),
    m_cacheStore(NULL),
    m_decordingImageBuf(NULL),
    m_backgroundMode(VFX_FALSE),
    m_parsing(VFX_FALSE),
    m_filePathQueryJob(NULL) 
{
}

VappGalleryMediaListAsync::VappGalleryMediaListAsync(VappGalleryCacheItemBaseType cacheType):
    m_cacheType(cacheType),
    m_provider(NULL),
    m_decoder(NULL),
    m_cacheStore(NULL),
    m_decordingImageBuf(NULL),
    m_backgroundMode(VFX_FALSE),
    m_parsing(VFX_FALSE),
    m_filePathQueryJob(NULL)
{
}

void VappGalleryMediaListAsync::onInit()
{
    VfxObject::onInit();
    obtainForegroundMemory();
}

void VappGalleryMediaListAsync::onDeinit()
{
    releaseForegroundMemory();
    VfxObject::onDeinit();
}

VfxBool VappGalleryMediaListAsync::isPrepared() const
{
    if(NULL == m_provider)
        return VFX_FALSE;

    return m_provider->isPrepared();
}

void VappGalleryMediaListAsync::prepareList()
{
    if(NULL == m_provider)
        return;

    m_provider->getProviderPreparedEvent()->connect(this, &VappGalleryMediaListAsync::onProviderReady);
    m_provider->prepare();
}

void VappGalleryMediaListAsync::onProviderReady(VfxS32 fileCount)
{
    m_provider->getProviderPreparedEvent()->disconnect(this, &VappGalleryMediaListAsync::onProviderReady);
    m_signalReady.postEmit(PREPARE_OK);
}

VfxBool VappGalleryMediaListAsync::refreshList()
{
    if(NULL == m_provider)
    {
        return VFX_FALSE;
    }

    if(!m_provider->isPrepared())
    {
        return VFX_FALSE;
    }

    // clear and re-set the cache
    closeCacheStore();
    prepareCacheStore();

    // refresh the list.
    // if it succeeds, media cache will be re-prepared
    m_provider->prepare();
    return VFX_TRUE;
}

void VappGalleryMediaListAsync::release()
{
    VappGalleryMediaListAsync* pThis = this;
    VFX_OBJ_CLOSE(pThis);
}

void VappGalleryMediaListAsync::stopDecode()
{
    if(NULL == m_provider){return;}
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_STOP_DECODE, VAPP_GALLERY_INTERNAL_UNUSED_PARAM, VAPP_GALLERY_INTERNAL_UNUSED_PARAM, m_parsingIndex.group, m_parsingIndex.pos);

    // stop file path query logic
    VfxBool res = m_provider->cancelFilePathQuery();
    VFX_OBJ_CLOSE(m_filePathQueryJob);

    // stop decoding
    if(m_decoder || m_parsing)
    {
        VFX_OBJ_CLOSE(m_decoder);
    }

    removeCacheItemImpl(m_parsingIndex);
    m_parsingIndex.invalid();
    m_parsing = VFX_FALSE;
}

void VappGalleryMediaListAsync::stopDecode(VcpMenuPos itemIdx)
{
    if(NULL == m_provider){return;}

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_STOP_DECODE, itemIdx.group, itemIdx.pos, m_parsingIndex.group, m_parsingIndex.pos);
    if(m_filePathQueryJob.isValid() && m_filePathQueryJob.get()->m_itemIndex == itemIdx)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_STOP_DECODE_CANCEL_FILE_PATH_QUERY, itemIdx.group, itemIdx.pos);
        m_provider->cancelFilePathQuery(itemIdx);
        VFX_OBJ_CLOSE(m_filePathQueryJob);
    }

    if(m_cacheStore && m_parsingIndex.isValid() && m_parsingIndex == itemIdx)
    {
        if(m_decoder || m_parsing)
            VFX_OBJ_CLOSE(m_decoder);

        removeCacheItemImpl(m_parsingIndex);
        m_parsingIndex.invalid();
        m_parsing = VFX_FALSE;
    }
}

VfxBool VappGalleryMediaListAsync::releaseForegroundMemory()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_RELEASE_FG_MEMORY);

    // stop decode first
    stopDecode();

    // unlock all cache item
    do
    {
        if(!isPrepared())
        {
            break;
        }

        if(NULL == m_cacheStore)
        {
            break;
        }

        const VfxS32 fileCount = getMediaCountInGroup(0);
        for(VfxS32 i = 0; i < fileCount; i++)
        {
            const VfxId key = convertItemIdFromMenuPos(VcpMenuPos(0, i));
            VappGalleryCacheItemBase* pItem = getItem(key);
            if(pItem)
            {
                if(CACHE_TYPE_L1 == m_cacheType)
                    ((L1Cache*)m_cacheStore)->unlockCache(key);
                else
                    ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
            }
        }
    }while(0);

    m_backgroundMode = VFX_TRUE;
    VFX_OBJ_CLOSE(m_cacheStore);
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListAsync::obtainForegroundMemory()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_OBTAIN_FG_MEMORY);
    m_backgroundMode = VFX_FALSE;
    prepareCacheStore();
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListAsync::enableBackgroundDecode(VfxBool isEnable)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ENABLE_BG_DECODE, isEnable);

    if(!isEnable)
    {
        stopDecode();
    }
    return VFX_TRUE;
}

VfxS32 VappGalleryMediaListAsync::getGroupCount()
{
    // 0 groups before provider is prepared
    if(!isPrepared())
    {
        return 0;
    }

    // VappGalleryMediaListAsync supports 1 group currently
    return 1;
}

VfxS32 VappGalleryMediaListAsync::getMediaCountInGroup(VfxS32 grpIdx)
{
    if(grpIdx < 0 || grpIdx >= MAX_FOLDER_COUNT)
    {
        return 0;
    }

    if(!isPrepared())
    {
        return 0;
    }

    return m_provider->getFileCount(grpIdx);
}

void VappGalleryMediaListAsync::getGroupName(const VfxS32 group, VfxWString &groupName)
{
    groupName = VFX_WSTR_EMPTY;
}

VappGalleryMediaGroupType VappGalleryMediaListAsync::getMediaGroupType(const VcpMenuPos &itemIdx)
{
    return MEDIA_GROUP_IMAGE;
}

VappGalleryDecodeResult VappGalleryMediaListAsync::getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr)
{
    nameStr = VFX_WSTR_EMPTY;
    return UNEXPECTED;
}
// TODO: check cache result
VappGalleryDecodeResult VappGalleryMediaListAsync::getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path)
{
    if(itemIdx.group < 0 || itemIdx.group >= MAX_FOLDER_COUNT)
    {
        return UNEXPECTED;
    }
    if(NULL == m_provider || NULL == m_cacheStore)
    {
        return UNEXPECTED;
    }

    const VappGalleryCacheItemBase* pItem = getItem(itemIdx);
    if(pItem)
    {
        return pItem->m_result;
    }
    return DECODING;
}

VappGalleryDecodeResult VappGalleryMediaListAsync::getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src)
{
    return UNEXPECTED;
}

VappGalleryDecodeResult VappGalleryMediaListAsync::startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer)
{
    return getThumbImageSrcImpl(itemIdx, buffer);
}

VappGalleryDecodeResult VappGalleryMediaListAsync::lockThumb(
                                const VcpMenuPos &itemIdx,
                                VfxImageBuffer& buffer)
{
    return getThumbImageSrcImpl(itemIdx, buffer);
}

VfxBool VappGalleryMediaListAsync::isMediaReady(const VcpMenuPos &itemIdx)
{
    if(NULL == m_cacheStore)
    {
        return VFX_FALSE;
    }

    // check if the item is already in cache list.
    const VfxId key = convertItemIdFromMenuPos(itemIdx);
    if(CACHE_TYPE_L1 == m_cacheType)
        return ((L1Cache*)m_cacheStore)->hasCache(key);
    else
        return ((ThumbnailCache*)m_cacheStore)->hasCache(key);
}

VfxBool VappGalleryMediaListAsync::canCheckDirty()
{
    return (m_provider && m_provider->canCheckDirty());
}

VfxBool VappGalleryMediaListAsync::checkDirty()
{
    if(!isPrepared())
    {
        return VFX_FALSE;
    }

    return m_provider->isDirty();
}

void VappGalleryMediaListAsync::unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer)
{
    if(NULL == m_cacheStore)
    {
        return;
    }
    // stop decoder if the decoding index is itemidx
    if(m_decoder && m_parsing && itemIdx == m_parsingIndex)
    {
        VFX_OBJ_CLOSE(m_decoder);
        m_parsing = VFX_FALSE;
        m_parsingIndex.invalid();
    }

    // this does not "release" the cache, only unlocks it.
    const VfxId key = convertItemIdFromMenuPos(itemIdx);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_UNLOCK, itemIdx.group, itemIdx.pos, key, __LINE__);
    if(CACHE_TYPE_L1 == m_cacheType)
        ((L1Cache*)m_cacheStore)->unlockCache(key);
    else
        ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
}

VappGalleryMediaListAsync::FilePathReadyEvent* VappGalleryMediaListAsync::getFilePathReadyEvent()
{
    return &m_signalFilePathReady;
}

VfxBool VappGalleryMediaListAsync::isValidGetFileResult(const VfxS32 result) const
{
    if(0 <= result)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

void VappGalleryMediaListAsync::onStartDecodeAfterFileReady(VcpMenuPos index, VfxWString &path, VfxS32 queryResult, void* userData)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ON_START_DECODE_AFTER_FILE_READY, index.group, index.pos, queryResult);

    // check if valid file path callback
    DecodeJob *pJob = static_cast<DecodeJob*>(handleToObject(reinterpret_cast<VfxObjHandle>(userData)));
    if(NULL == pJob)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ON_START_DECODE_AFTER_FILE_READY_ERROR_JOB);
        return;
    }

    VappGalleryDecodeResult tempResult = OK;
    do
    {
        // check result of query file path
        // if query file failed, treat as unexpected decorded result
        if(!isValidGetFileResult(queryResult))
        {
            tempResult = UNEXPECTED;
            VFX_OBJ_CLOSE(m_filePathQueryJob);
            break;
        }

        // check if we are docording other thumb now
        if(m_parsing)
        {
            tempResult = DECODING;
            break;
        }
    }while(0);

    if(OK != tempResult)
    {
        m_decordingImageBuf = NULL;
        m_signalDecode.emit(index, tempResult);
        return;
    }
    // TODO: check if m_thumbnailCache is valid
    // TODO: make sure decoderer

    // start decode
    VfxImageBuffer imgBuf;
    const VfxId key = convertItemIdFromMenuPos(index);
    VappGalleryCacheItemBase *pItem = NULL;
    if(CACHE_TYPE_L1 == m_cacheType)
        pItem = ((L1Cache*)m_cacheStore)->lockCache(key);
    else
        pItem = ((ThumbnailCache*)m_cacheStore)->lockCache(key);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_LOCK, index.group, index.pos, key, __LINE__);
    VFX_ASSERT(pItem);
    do
    {
        //pItem->m_result = DECODING;
        if(CACHE_TYPE_L1 == m_cacheType)
        {
            imgBuf.ptr = ((VappGalleryL1CacheItem*)pItem)->getThumbBufferPtr();
            imgBuf.colorFormat = GALLERY_VRT_CF_VIEWER;
            imgBuf.pitchBytes = (LCD_WIDTH) * VAPP_GALLERY_IMG_VIEWER_BPP;
            imgBuf.width = LCD_WIDTH;
            imgBuf.height = LCD_HEIGHT;
        }
        else
        {
            imgBuf.ptr = ((VappGalleryMediaGridCacheItem*)pItem)->getThumbBufferPtr();
            imgBuf.colorFormat = GALLERY_VRT_CF_THUMB;
            imgBuf.pitchBytes = (VappGalleryMediaGridConstant::THUMB_WIDTH) * VAPP_GALLERY_THUMB_BPP;
            imgBuf.width = VappGalleryMediaGridConstant::THUMB_WIDTH;
            imgBuf.height = VappGalleryMediaGridConstant::THUMB_HEIGHT;
        }
    }while(0);

    m_parsing = VFX_TRUE;
    m_parsingIndex = index;
    VFX_OBJ_CREATE(m_decoder, VappGalleryImageThumbnail, this);
    if(CACHE_TYPE_L1 == m_cacheType){m_decoder->configThumbFitMode(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT);}
    m_decoder->getReadySignal()->connect(this, &VappGalleryMediaListAsync::onThumbnailDecodeResult);
    m_decoder->decode(path, imgBuf);
}

void VappGalleryMediaListAsync::onFilePathReady(VcpMenuPos index, VfxWString &path, VfxS32 queryResult, void* userData)
{
    VappGalleryDecodeResult result = UNEXPECTED;
    VfxWString fileName = VFX_WSTR_EMPTY;
    if(isValidGetFileResult(queryResult))
    {
        result = OK;
        fileName = VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr((WCHAR*)path.getBuf()));
    }

    m_signalFilePathReady.emit(index, path, result);
}

void VappGalleryMediaListAsync::onThumbnailDecodeResult(VappGalleryDecoderBase * sender, VappGalleryDecodeResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ON_THUMB_DECODE_RESULT, m_parsingIndex.group, m_parsingIndex.pos, result);

    const VfxId key = convertItemIdFromMenuPos(m_parsingIndex);
    do
    {
        if(NULL == m_cacheStore ||
           NULL == sender ||
           static_cast<VappGalleryDecoderBase*>(m_decoder) != sender)
        {
            result = UNEXPECTED;
            break;
        }

        VappGalleryCacheItemBase *pItem = getItem(key);
        if(pItem)
        {
            // update result
            pItem->m_result = result;
        }
    }while(0);

    // unlock the cache item.
    if(m_cacheStore)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_LOCK, m_parsingIndex.group, m_parsingIndex.pos, key, __LINE__);
        // unlock the cache item.
        // it is locked when triggering decoder
        if(CACHE_TYPE_L1 == m_cacheType)
            ((L1Cache*)m_cacheStore)->unlockCache(key);
        else
            ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
    }
    VcpMenuPos parsedIndex = m_parsingIndex;
    m_parsing = VFX_FALSE;
    m_parsingIndex.invalid();

    VFX_OBJ_CLOSE(m_decoder);
    VFX_OBJ_CLOSE(m_filePathQueryJob);
    m_signalDecode.emit(parsedIndex, result);
    return;
}

void VappGalleryMediaListAsync::prepareCacheStore()
{
    closeCacheStore();
	switch(m_cacheType)
    {
        case CACHE_TYPE_L1:
        {
            L1Cache *pL1Cache = NULL;
            VFX_OBJ_CREATE_EX(pL1Cache, L1Cache, this, VAPP_GALLERY_ASYNC_MEDIALIST_L1_PREVIEW_FG_SIZE);
            m_cacheStore = pL1Cache;
            break;
        }
        case CACHE_TYPE_THUMBNAIL:
        default:
        {
            ThumbnailCache *pThumbCache = NULL;
            VFX_OBJ_CREATE_EX(pThumbCache, ThumbnailCache, this, VAPP_GALLERY_ASYNC_MEDIALIST_THUMB_FG_SIZE);
            m_cacheStore = pThumbCache;
            break;
        }
    }
}

void VappGalleryMediaListAsync::closeCacheStore()
{
    VFX_OBJ_CLOSE(m_cacheStore);
}

VappGalleryCacheItemBase* VappGalleryMediaListAsync::getItem(const VfxId key)
{
    if(CACHE_TYPE_L1 == m_cacheType)
        return ((L1Cache*)m_cacheStore)->getCacheIfPresent(key);
    else
        return ((ThumbnailCache*)m_cacheStore)->getCacheIfPresent(key);
}

void VappGalleryMediaListAsync::removeCacheItemImpl(const VcpMenuPos index)
{
    if(NULL == m_cacheStore || !index.isValid())
    {
        return;
    }
    // unlock and relase cache item
    const VfxId key = convertItemIdFromMenuPos(index);
    VappGalleryCacheItemBase* pItem = getItem(key);

    if(pItem)
    {
        if(CACHE_TYPE_L1 == m_cacheType)
        {
            ((L1Cache*)m_cacheStore)->unlockCache(key);
            ((L1Cache*)m_cacheStore)->releaseCache(key);
        }
        else
        {
            ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
            ((ThumbnailCache*)m_cacheStore)->releaseCache(key);
        }
        pItem = NULL;
    }
}

VappGalleryDecodeResult VappGalleryMediaListAsync::getThumbImageSrcImpl(VcpMenuPos itemIdx, VfxImageBuffer& buffer)
{
    if(NULL == m_cacheStore)
    {
        return DECODING;
    }

    // check if it exist in cache
    const VfxId key = convertItemIdFromMenuPos(itemIdx);
    const VappGalleryCacheItemBase *pItem = getItem(key);
    if(pItem)
    {
        // [MAUI_03142917]
        // the preview UI timer may double call startDecodeThumb() to check if item decode finished and VappGalleryDecodeResult[0] is OK
        // so check if item is decoding now
        if(m_parsing && m_parsingIndex == itemIdx)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_GET_THUMB_IMAGE_SRC_IMPL, itemIdx.group, itemIdx.pos, 1, m_parsingIndex.group, m_parsingIndex.pos, DECODING);
            return DECODING;
        }
        // check result of cache item
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_GET_THUMB_IMAGE_SRC_IMPL, itemIdx.group, itemIdx.pos, 1, m_parsingIndex.group, m_parsingIndex.pos, pItem->m_result);
        if(OK == pItem->m_result)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_LOCK, itemIdx.group, itemIdx.pos, key, __LINE__);
            if(CACHE_TYPE_L1 == m_cacheType)
            {
                ((L1Cache*)m_cacheStore)->lockCache(key);
                ((VappGalleryL1CacheItem*)pItem)->getImageBuffer(buffer);
            }
            else
            {
                ((ThumbnailCache*)m_cacheStore)->lockCache(key);
                ((VappGalleryMediaGridCacheItem*)pItem)->getImageBuffer(buffer);
            }
            return OK;
        }
        else if(DECODING != pItem->m_result)
        {
            return pItem->m_result;
        }
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_GET_THUMB_IMAGE_SRC_IMPL, itemIdx.group, itemIdx.pos, 0, m_parsingIndex.group, m_parsingIndex.pos, DECODING);
    // if decoder is deocding a thumnail for other image
    if(m_parsing)
    {
        return DECODING;
    }

    // finally we trigger decoding
    // note IVappGallerySocialNetworkProvider:: getFile is the non_blocking function
    VFX_OBJ_CLOSE(m_filePathQueryJob);
    DecodeJob *pJob = NULL;
    VFX_OBJ_CREATE(pJob, DecodeJob, this);
    VFX_DEV_ASSERT(NULL != pJob);
    pJob->m_itemIndex = itemIdx;
    pJob->m_pList = this;
    m_filePathQueryJob = pJob;

    m_decordingImageBuf = &buffer;
    m_provider->getFilePath(itemIdx, FileReadyCallback(this, &VappGalleryMediaListAsync::onStartDecodeAfterFileReady), (void*)(pJob->getObjHandle()));
    return DECODING;
}
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */

/*****************************************************************************
 * IVappGalleryMediaListCommon
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryMediaListCommon",VappGalleryMediaListCommon,IVappGalleryMediaList);
VappGalleryMediaListCommon::VappGalleryMediaListCommon():
    m_cacheType(CACHE_TYPE_THUMBNAIL),
    m_decoder(NULL),
    m_fileList(NULL),
    m_decodingJob(NULL),
    m_cacheStore(NULL),
    m_prepared(VFX_FALSE),
    m_backgroundMode(VFX_FALSE),
    m_parsing(VFX_FALSE),
    m_isWallpaper(VFX_FALSE),
    m_groupCount(0),
    m_liveWallpaperGroupId(0),
    m_staticWallpaperGroupId(0),
    m_videoWallpaperGroupId(0)
{
    kal_mem_set(&m_sourceInfo, 0, sizeof(m_sourceInfo));
}

VappGalleryMediaListCommon::VappGalleryMediaListCommon(VappGalleryCacheItemBaseType cacheType):
    m_cacheType(cacheType),
    m_decoder(NULL),
    m_fileList(NULL),
    m_decodingJob(NULL),
    m_cacheStore(NULL),
    m_prepared(VFX_FALSE),
    m_backgroundMode(VFX_FALSE),
    m_parsing(VFX_FALSE),
    m_isWallpaper(VFX_FALSE),
    m_groupCount(0),
    m_liveWallpaperGroupId(0),
    m_staticWallpaperGroupId(0),
    m_videoWallpaperGroupId(0)
{
    kal_mem_set(&m_sourceInfo, 0, sizeof(m_sourceInfo));
}


void VappGalleryMediaListCommon::onInit()
{
    VfxObject::onInit();
    
    // initially, allow all default types
    FMGR_FILTER_INIT(&m_limitFilter);
    FMGR_FILTER_SET_ALL(&m_limitFilter);
    
    m_sortMethod = FS_SORT_NAME;

}

void VappGalleryMediaListCommon::onDeinit()
{
    VfxObject::onDeinit();
}

void VappGalleryMediaListCommon::configFileTypeFilter(const FMGR_FILTER *filter)
{
    if(filter)
    {
        _intersectFilter(m_limitFilter, *filter);
    }
}

void VappGalleryMediaListCommon::configSortMethod(U32 sortMethod)
{
    m_sortMethod = sortMethod;
}

void VappGalleryMediaListCommon::prepareCacheStore()
{
    closeCacheStore();
	MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLMC_PREPARE_CACHE_STORE_START, m_cacheType, m_cacheStore);
    switch(m_cacheType)
    {
        case CACHE_TYPE_L1:
        {
            L1Cache *pL1Cache = NULL;
            VFX_OBJ_CREATE_EX(pL1Cache, L1Cache, this, (VAPP_GALLERY_ASYNC_MEDIALIST_L1_PREVIEW_FG_SIZE));
            m_cacheStore = pL1Cache;
            break;
        }
        case CACHE_TYPE_THUMBNAIL:
        default:
        {
            ThumbnailCache *pThumbCache = NULL;
            VFX_OBJ_CREATE_EX(pThumbCache, ThumbnailCache, this, (VAPP_GALLERY_IMG_PICKER_FG_SIZE));
            m_cacheStore = pThumbCache;
            break;
        }
    }
	MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLMC_PREPARE_CACHE_STORE_FINISHED, m_cacheType, m_cacheStore);
}

void VappGalleryMediaListCommon::closeCacheStore()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLMC_CLOSE_CACHE_STORE, m_cacheType, m_cacheStore);
	if(m_cacheStore)
	{
		//stop decode
		stopDecode();
		if(CACHE_TYPE_L1 == m_cacheType)
	        ((L1Cache*)m_cacheStore)->unlockAll();
	    else
	        ((ThumbnailCache*)m_cacheStore)->unlockAll();
		VFX_OBJ_CLOSE(m_cacheStore);
	}   
}

VappGalleryCacheItemBase* VappGalleryMediaListCommon::getItem(const VfxId key)
{
    if(CACHE_TYPE_L1 == m_cacheType)
        return ((L1Cache*)m_cacheStore)->getCacheIfPresent(key);
    else
        return ((ThumbnailCache*)m_cacheStore)->getCacheIfPresent(key);
}

VfxBool VappGalleryMediaListCommon::isPrepared() const
{
    return m_prepared;
}

void VappGalleryMediaListCommon::prepareList()
{
    VFX_DEV_ASSERT(!m_prepared);

    if (m_isWallpaper == VFX_FALSE)
    {
        m_prepared = VFX_FALSE;

        // create file list, both image and video
        if(NULL == m_fileList)
        {
            VFX_OBJ_CREATE(m_fileList, VappGalleryFmgrImageVideoList, this);
        }

        m_signalFileListReady.connect(this, &VappGalleryMediaListCommon::onFileListReady);
        m_signalFileListReloadStart.connect(this, &VappGalleryMediaListCommon::onFileListReloadStart);
        m_signalFileListReloadFinished.connect(this, &VappGalleryMediaListCommon::onFileListReloadFinished);

        m_fileList->configFolder(m_folderPath, &m_signalFileListReady, &m_signalFileListReloadStart, &m_signalFileListReloadFinished);
        m_fileList->configFileTypeLimit(&m_limitFilter);
        m_fileList->configSortMethod(m_sortMethod);
        if(!m_searchPattern.isEmpty())
        {
            m_fileList->configSearchFileDuringPrepare(m_searchPattern);
        }
        m_fileList->prepare();
    }
    else
    {
        //get foreground memory before send list ready signal
        obtainForegroundMemory();
        m_signalReady.postEmit(PREPARE_OK);
        m_prepared = VFX_TRUE;
    }
}

VfxBool VappGalleryMediaListCommon::refreshList()
{
    if (m_isWallpaper == VFX_FALSE)
    {
        if(NULL == m_fileList)
        {
            return VFX_FALSE;
        }

        if(!m_fileList->isPrepared())
        {
            return VFX_FALSE;
        }

        // refresh the list.
        // if it succeeds, media cache will be re-prepared
        m_prepared = VFX_FALSE;

        closeCacheStore();

		// clear and re-set the cache
        //prepareCacheStore();

        m_fileList->refresh();
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappGalleryMediaListCommon::release()
{
    VappGalleryMediaListCommon* pThis = this;
    releaseForegroundMemory();
    VFX_OBJ_CLOSE(pThis);
}

void VappGalleryMediaListCommon::stopDecode()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_STOP_DECODE, VAPP_GALLERY_INTERNAL_UNUSED_PARAM, VAPP_GALLERY_INTERNAL_UNUSED_PARAM, m_parsingIndex.group, m_parsingIndex.pos);

    // stop decoding
    VFX_OBJ_CLOSE(m_decodingJob);
    if(m_parsing)
    {
        VFX_OBJ_CLOSE(m_decoder);
    }
    removeCacheItemImpl(m_parsingIndex);
    m_parsingIndex.invalid();
    m_parsing = VFX_FALSE;
}

void VappGalleryMediaListCommon::stopDecode(VcpMenuPos itemIdx)
{

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_STOP_DECODE, itemIdx.group, itemIdx.pos, m_parsingIndex.group, m_parsingIndex.pos);
    if(m_decodingJob.isValid() && m_decodingJob.get()->m_itemIndex == itemIdx)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_STOP_DECODE_CANCEL_FILE_PATH_QUERY, itemIdx.group, itemIdx.pos);
        VFX_OBJ_CLOSE(m_decodingJob);
    }

    if(m_cacheStore && m_parsingIndex.isValid() && m_parsingIndex == itemIdx)
    {
        if(m_parsing)
            VFX_OBJ_CLOSE(m_decoder);

        removeCacheItemImpl(m_parsingIndex);
        m_parsingIndex.invalid();
        m_parsing = VFX_FALSE;
    }
}

VfxBool VappGalleryMediaListCommon::releaseForegroundMemory()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_RELEASE_FG_MEMORY);

    // stop decode first
    stopDecode();

    // unlock all cache item
    do
    {
        if(!isPrepared())
        {
            break;
        }

        if(NULL == m_cacheStore)
        {
            break;
        }

        if(CACHE_TYPE_L1 == m_cacheType)
	        ((L1Cache*)m_cacheStore)->unlockAll();
	    else
	        ((ThumbnailCache*)m_cacheStore)->unlockAll();
    }while(0);

    m_backgroundMode = VFX_TRUE;
    VFX_OBJ_CLOSE(m_cacheStore);
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListCommon::obtainForegroundMemory()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_OBTAIN_FG_MEMORY);
    m_backgroundMode = VFX_FALSE;
    prepareCacheStore();
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListCommon::enableBackgroundDecode(VfxBool isEnable)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ENABLE_BG_DECODE, isEnable);

    if(!isEnable)
    {
        stopDecode();
    }
    return VFX_TRUE;
}

VfxS32 VappGalleryMediaListCommon::getGroupCount()
{
    // 0 groups before provider is prepared
    if(!isPrepared())
    {
        return 0;
    }

    if (m_isWallpaper == VFX_TRUE)
    {
        return getWallpaperGroupCount();
    }
    else
    {
        // VappGalleryMediaListCommon supports 1 group currently
        return 1;
    }
}

VfxS32 VappGalleryMediaListCommon::getMediaCountInGroup(VfxS32 grpIdx)
{
    if (m_isWallpaper == VFX_TRUE)
    {
        return getWallpaperMediaCountInGroup(grpIdx);
    }
    else
    {
        if(NULL == m_fileList)
            return 0;
        if(0 != grpIdx)
            return 0;

        return m_fileList->getTotalFileCount();
    }
}

void VappGalleryMediaListCommon::getGroupName(const VfxS32 group, VfxWString &groupName)
{
    if (m_isWallpaper == VFX_TRUE)
    {
        getWallpaperGroupName(group, groupName);
    }
    else
    {
        groupName = VFX_WSTR_EMPTY;
    }
}

VappGalleryMediaGroupType VappGalleryMediaListCommon::getMediaGroupType(const VcpMenuPos &itemIdx)
{
    if (m_isWallpaper == VFX_TRUE)
    {
        return getWallpaperMediaGroupType(itemIdx);
    }
    else
    {
        VfxWString name;
        VappGalleryDecodeResult queryResult = getMediaName(itemIdx, name);
        if(OK != queryResult)
        {
            return DECODING == queryResult ? MEDIA_GROUP_WAIT_DECODING : MEDIA_GROUP_ERROR;
        }

        GALLERY_MEASURE_TIME_START("Gfg");
        filetypes_group_type_enum fsGroup = srv_fmgr_types_find_group_by_filename_str((const WCHAR*)name);
        GALLERY_MEASURE_TIME_STOP("Gfg");
        switch(fsGroup)
        {
        case FMGR_GROUP_IMAGE:
            return MEDIA_GROUP_IMAGE;
        case FMGR_GROUP_VIDEO:
            return MEDIA_GROUP_VIDEO;
        default:
            return MEDIA_GROUP_IMAGE;
        }
    }
}

VappGalleryDecodeResult VappGalleryMediaListCommon::getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr)
{
    if (m_isWallpaper == VFX_TRUE)
    {
        return getWallpaperMediaName(itemIdx, nameStr);
    }
    else
    {
        if(NULL == m_fileList)
        {
            nameStr.setEmpty();
            return DECODING;
        }
        return m_fileList->getFileName(itemIdx, nameStr);
    }
}

// TODO: check cache result
VappGalleryDecodeResult VappGalleryMediaListCommon::getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path)
{
    if (m_isWallpaper == VFX_TRUE)
    {
        return getWallpaperMediaPath(itemIdx, path);
    }
    else
    {
        if(NULL == m_fileList)
        {
            path.setEmpty();
            return DECODING;
        }
        return m_fileList->getPathName(itemIdx, path);
    }

}

VappGalleryDecodeResult VappGalleryMediaListCommon::getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src)
{
    if (m_isWallpaper == VFX_TRUE)
    {
        return getWallpaperMediaSource(itemIdx, src);
    }
    else
    {
        VFX_ASSERT(m_fileList);
        VfxWString path;
        VappGalleryDecodeResult res = m_fileList->getPathName(itemIdx, path);
        if(OK != res)
        {
            path.setEmpty();
            src.setPath(path);
            return res;
        }
        else
        {
            src.setPath(path);
            return OK;
        }
    }
}

VappGalleryDecodeResult VappGalleryMediaListCommon::startDecodeThumbLiveWallpaper(VcpMenuPos itemIdx, VfxImageBuffer& buffer)
{
     // no cache, lock and decode (wallpaper decode is blocking)
    const VfxId itemId = convertItemIdFromMenuPos(itemIdx);
    const VappGalleryCacheItemBase *pItem = getItem(itemId);
    if (pItem == NULL)
        pItem = ((ThumbnailCache*)m_cacheStore)->lockCache(itemId);
    
    ((VappGalleryMediaGridCacheItem*)pItem)->getImageBuffer(buffer);

    VappWallpaperThumbStruct thumb;
    thumb.height = buffer.height;
    thumb.width = buffer.width;
    thumb.buf_ptr = buffer.ptr;
    thumb.cf = buffer.colorFormat;
    thumb.bpp = getBytePerPixel(buffer.colorFormat);
    // TODO: currently we get thumbnails for live wallpaper only
    MMI_BOOL decodeResult = m_sourceInfo.decode_wallpaper_thumb(itemIdx.pos, &thumb, m_sourceInfo.user_data);
    ((VappGalleryMediaGridCacheItem*)pItem)->m_result = (MMI_TRUE == decodeResult) ? OK : FORMAT_UNSUPPORTED;
    if(OK != ((VappGalleryMediaGridCacheItem*)pItem)->m_result)
    {
        // unlock the cache. Note we still remember the
        ((ThumbnailCache*)m_cacheStore)->unlockCache(itemId);
    }
    return ((VappGalleryMediaGridCacheItem*)pItem)->m_result;
}

VappGalleryDecodeResult VappGalleryMediaListCommon::startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer)
{
    if(NULL == m_cacheStore)
    {
        return DECODING;
    }
    VappGalleryDecodeResult lockRes = lockThumb(itemIdx, buffer);

    if(DECODING != lockRes)
    {
        return lockRes;
    }
    else
    {
        if (m_isWallpaper == VFX_TRUE)
        {
            return startDecodeThumbLiveWallpaper(itemIdx, buffer);
        }
        else
        {
        return getThumbImageSrcImpl(itemIdx, buffer);
    }
    }


}

VappGalleryDecodeResult VappGalleryMediaListCommon::lockThumb(const VcpMenuPos &itemIdx, VfxImageBuffer& buffer)
{
    if(NULL == m_cacheStore)
    {
        return DECODING;
    }

    // check if it exist in cache
    const VfxId key = convertItemIdFromMenuPos(itemIdx);
    const VappGalleryCacheItemBase *pItem = getItem(key);
    if(pItem)
    {
        if (m_isWallpaper == VFX_FALSE)
        {
            // [MAUI_03142917]
            // the preview UI timer may double call startDecodeThumb() to check if item decode finished and VappGalleryDecodeResult[0] is OK
            // so check if item is decoding now
            if(m_parsing && m_parsingIndex == itemIdx)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_GET_THUMB_IMAGE_SRC_IMPL, itemIdx.group, itemIdx.pos, 1, m_parsingIndex.group, m_parsingIndex.pos, DECODING);
                return DECODING;
            }
            // check result of cache item
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_GET_THUMB_IMAGE_SRC_IMPL, itemIdx.group, itemIdx.pos, 1, m_parsingIndex.group, m_parsingIndex.pos, pItem->m_result);
        }
        
        if(OK == pItem->m_result)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_LOCK, itemIdx.group, itemIdx.pos, key, __LINE__);
            if(CACHE_TYPE_L1 == m_cacheType)
            {
                ((L1Cache*)m_cacheStore)->lockCache(key);
                ((VappGalleryL1CacheItem*)pItem)->getImageBuffer(buffer);
            }
            else
            {
                ((ThumbnailCache*)m_cacheStore)->lockCache(key);
                ((VappGalleryMediaGridCacheItem*)pItem)->getImageBuffer(buffer);
            }
            return OK;
        }
        else
        {
            return pItem->m_result;
        }
    }
    else
    {
        return DECODING;
    }
}

VappGalleryDecodeResult VappGalleryMediaListCommon::getThumbImageSrcImpl(VcpMenuPos itemIdx, VfxImageBuffer& buffer)
{
    if(NULL == m_cacheStore)
    {
        return DECODING;
    }

    if(m_parsing)
    {
        return DECODING;
    }

    // finally we trigger decoding
    // note IVappGallerySocialNetworkProvider:: getFile is the non_blocking function
    VFX_OBJ_CLOSE(m_decodingJob);
    DecodeJob *pJob = NULL;
    VFX_OBJ_CREATE(pJob, DecodeJob, this);
    VFX_DEV_ASSERT(NULL != pJob);
    pJob->m_itemIndex = itemIdx;
    pJob->m_pList = this;
    m_decodingJob = pJob;

    VfxWString path = VFX_WSTR_EMPTY;
    VappGalleryDecodeResult resPath = getMediaPath(itemIdx, path);
	if(resPath == OK)
    {
    	onStartDecodeAfterFileReady(itemIdx, path, 0, (void*)(pJob->getObjHandle()));
	}
    return DECODING;
}

VfxBool VappGalleryMediaListCommon::isMediaReady(const VcpMenuPos &itemIdx)
{
    if(NULL == m_cacheStore)
    {
        return VFX_FALSE;
    }

    // check if the item is already in cache list.
    const VfxId key = convertItemIdFromMenuPos(itemIdx);
    if(CACHE_TYPE_L1 == m_cacheType)
        return ((L1Cache*)m_cacheStore)->hasCache(key);
    else
        return ((ThumbnailCache*)m_cacheStore)->hasCache(key);
}

VfxBool VappGalleryMediaListCommon::canCheckDirty()
{
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListCommon::checkDirty()
{
    if(!m_prepared)
    {
        return VFX_FALSE;
    }

    if(NULL == m_fileList)
    {
        return VFX_FALSE;
    }

    return m_fileList->isDirty();
}

void VappGalleryMediaListCommon::unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer)
{
    if(NULL == m_cacheStore)
    {
        return;
    }
    // stop decoder if the decoding index is itemidx
    if(m_decoder && m_parsing && itemIdx == m_parsingIndex)
    {
        VFX_OBJ_CLOSE(m_decoder);
        m_parsing = VFX_FALSE;
        m_parsingIndex.invalid();
    }

    // this does not "release" the cache, only unlocks it.
    const VfxId key = convertItemIdFromMenuPos(itemIdx);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_UNLOCK, itemIdx.group, itemIdx.pos, key, __LINE__);
    if(CACHE_TYPE_L1 == m_cacheType)
        ((L1Cache*)m_cacheStore)->unlockCache(key);
    else
        ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
}

void VappGalleryMediaListCommon::onFileListReady(VappGalleryPrepareResult prepareResult)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLMC_ON_FILE_LIST_READY);

    m_prepared = VFX_TRUE;
    //get foreground memory before send list ready signal
    obtainForegroundMemory();
    m_signalReady.postEmit(PREPARE_OK);
}

void VappGalleryMediaListCommon::onFileListReloadStart(VcpMenuPos mediaPos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLMC_ON_FILE_LIST_RELOAD_START, mediaPos.group, mediaPos.pos);
    m_signalReloadStart.postEmit(mediaPos);
}

void VappGalleryMediaListCommon::onFileListReloadFinished(VcpMenuPos mediaPos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLMC_ON_FILE_LIST_RELOAD_FINISH, mediaPos.group, mediaPos.pos);
    m_signalReloadFinished.postEmit(mediaPos);
}

void VappGalleryMediaListCommon::onStartDecodeAfterFileReady(VcpMenuPos mediaPos, VfxWString &path, VfxS32 queryResult, void* userData)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ON_START_DECODE_AFTER_FILE_READY, mediaPos.group, mediaPos.pos, queryResult);

    // check if valid file path callback
    DecodeJob *pJob = static_cast<DecodeJob*>(handleToObject(reinterpret_cast<VfxObjHandle>(userData)));
    if(NULL == pJob)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ON_START_DECODE_AFTER_FILE_READY_ERROR_JOB);
        return;
    }

    if(m_parsing)
    {
        return;
    }

	// TODO: file may be not ready
	VappGalleryMediaGroupType groupType = getMediaGroupType(mediaPos);
	if(MEDIA_GROUP_WAIT_DECODING == groupType)
	{
		return;
	}
	else if(MEDIA_GROUP_ERROR == groupType)
	{
		m_signalDecode.emit(mediaPos, UNEXPECTED);
		return;
	}
	
    // start decode
    VfxImageBuffer imgBuf;
    const VfxId key = convertItemIdFromMenuPos(mediaPos);
    VappGalleryCacheItemBase *pItem = NULL;
    if(CACHE_TYPE_L1 == m_cacheType)
        pItem = ((L1Cache*)m_cacheStore)->lockCache(key);
    else
        pItem = ((ThumbnailCache*)m_cacheStore)->lockCache(key);

	// pItem may be NULL
	if(!pItem)
	{
		return;
	}

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_LOCK, mediaPos.group, mediaPos.pos, key, __LINE__);
    //VFX_ASSERT(pItem);
    const VfxBool isVideo = (MEDIA_GROUP_VIDEO == groupType);
    if(isVideo)
    {
        // note that we want to reduce memory
        // used by underlying MDI service.
        VappGalleryVideoThumbnail *videoDecoder = NULL;
        VFX_OBJ_CREATE(videoDecoder, VappGalleryVideoThumbnail, this);
        videoDecoder->configLiteMemory(VFX_TRUE);
        m_decoder = videoDecoder;
    }
    else
    {
        VappGalleryImageThumbnail *ImageDecoder = NULL;
        VFX_OBJ_CREATE(ImageDecoder, VappGalleryImageThumbnail, this);
        if(CACHE_TYPE_L1 == m_cacheType)
        {
           //ImageDecoder->configThumbFitMode(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT);
        }
        m_decoder = ImageDecoder;
    }

	m_parsing = VFX_TRUE;
    m_parsingIndex = mediaPos;

    //calc image fit size
    VfxSize originalSize(2, 2);
    VfxSize decodeSize(2, 2);
    U16 gdiFileType = GDI_IMAGE_TYPE_INVALID;
    if(!m_decoder->getDimensionEx(path, originalSize, gdiFileType))
    {
        onThumbnailDecodeResult(m_decoder, FORMAT_UNSUPPORTED);
        return;
    }
    calcDecodeSize(originalSize.width, originalSize.height, &decodeSize.width, &decodeSize.height);

    //assign the decode info
    do
    {
        //pItem->m_result = DECODING;
        if(CACHE_TYPE_L1 == m_cacheType)
        {
            imgBuf.ptr = ((VappGalleryL1CacheItem*)pItem)->getThumbBufferPtr();
            imgBuf.colorFormat = GALLERY_VRT_CF_VIEWER;
            imgBuf.pitchBytes = (decodeSize.width) * VAPP_GALLERY_IMG_VIEWER_BPP;
            imgBuf.width = decodeSize.width;
            imgBuf.height = decodeSize.height;
            ((VappGalleryL1CacheItem*)pItem)->setDecodeSize(decodeSize);
        }
        else
        {
            imgBuf.ptr = ((VappGalleryMediaGridCacheItem*)pItem)->getThumbBufferPtr();
            imgBuf.colorFormat = GALLERY_VRT_CF_THUMB;

            imgBuf.pitchBytes = ((VappGalleryMediaGridConstant::THUMB_WIDTH) / 2 * 2) * VAPP_GALLERY_THUMB_BPP;
            imgBuf.width = VappGalleryMediaGridConstant::THUMB_WIDTH / 2 * 2;
            imgBuf.height = VappGalleryMediaGridConstant::THUMB_HEIGHT / 2 * 2;
        }
    }while(0);

    m_decoder->getReadySignal()->connect(this, &VappGalleryMediaListCommon::onThumbnailDecodeResult);
    m_decoder->decode(path, imgBuf);
}

void VappGalleryMediaListCommon::onThumbnailDecodeResult(VappGalleryDecoderBase * sender, VappGalleryDecodeResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_ON_THUMB_DECODE_RESULT, m_parsingIndex.group, m_parsingIndex.pos, result);

    const VfxId key = convertItemIdFromMenuPos(m_parsingIndex);
    do
    {
        if(NULL == m_cacheStore ||
           NULL == sender ||
           static_cast<VappGalleryDecoderBase*>(m_decoder) != sender)
        {
            result = UNEXPECTED;
            break;
        }

        VappGalleryCacheItemBase *pItem = getItem(key);
        if(pItem)
        {
            // update result
            pItem->m_result = result;
        }
    }while(0);

    // unlock the cache item.
    if(m_cacheStore)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLAS_UNLOCK, m_parsingIndex.group, m_parsingIndex.pos, key, __LINE__);
        // unlock the cache item.
        // it is locked when triggering decoder
        if(CACHE_TYPE_L1 == m_cacheType)
            ((L1Cache*)m_cacheStore)->unlockCache(key);
        else
            ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
    }
    VcpMenuPos parsedIndex = m_parsingIndex;
    m_parsing = VFX_FALSE;
    m_parsingIndex.invalid();

    VFX_OBJ_CLOSE(m_decoder);
    VFX_OBJ_CLOSE(m_decodingJob);
    m_signalDecode.emit(parsedIndex, result);
    return;
}

void VappGalleryMediaListCommon::removeCacheItemImpl(const VcpMenuPos index)
{
    if(NULL == m_cacheStore || !index.isValid())
    {
        return;
    }
    // unlock and relase cache item
    const VfxId key = convertItemIdFromMenuPos(index);
    VappGalleryCacheItemBase* pItem = getItem(key);

    if(pItem)
    {
        if(CACHE_TYPE_L1 == m_cacheType)
        {
            ((L1Cache*)m_cacheStore)->unlockCache(key);
            ((L1Cache*)m_cacheStore)->releaseCache(key);
        }
        else
        {
            ((ThumbnailCache*)m_cacheStore)->unlockCache(key);
            ((ThumbnailCache*)m_cacheStore)->releaseCache(key);
        }
        pItem = NULL;
    }
}

void VappGalleryMediaListCommon::getStartingIndex(VcpMenuPos &pos)
{
    if(m_fileList && m_fileList->getFoundFileIndex(pos))
    {
        return;
    }
    else
    {
        pos.group = 0;
        pos.pos = 0;
    }
}

void VappGalleryMediaListCommon::calcDecodeSize(VfxS32 img_width, VfxS32 img_height, VfxS32 *out_w, VfxS32 *out_h)
{
    if (img_width <= LCD_WIDTH && img_height <= LCD_HEIGHT)
    {
        *out_w = img_width;
        *out_h = img_height;
    }
    else if (img_width*LCD_HEIGHT >= img_height*LCD_WIDTH)
    {
        *out_w = LCD_WIDTH;
        *out_h = LCD_WIDTH * img_height / img_width;
		if ((LCD_WIDTH * img_height % img_width) != 0)
		{
		    *out_h += 1;
		}
    }
    else
    {
        *out_w = LCD_HEIGHT * img_width / img_height;
        *out_h = LCD_HEIGHT;
		if ((LCD_HEIGHT * img_width % img_height) != 0)
		{
		    *out_w += 1;
		}
    }
}

void VappGalleryMediaListCommon::configWallpaperInfo(IWallpaperSourceStruct *info)
{
    m_sourceInfo = *info;
    // make sure callbacks are available
    VFX_DEV_ASSERT(m_sourceInfo.get_thumb_img_id);
    VFX_DEV_ASSERT(m_sourceInfo.get_static_wallpaper_img_id);
    VFX_DEV_ASSERT(m_sourceInfo.get_live_wallpaper);

    getGroupInfoFromWallpaperInfo(
                                m_sourceInfo,
                                m_groupCount,
                                m_liveWallpaperGroupId,
                                m_staticWallpaperGroupId,
                                m_videoWallpaperGroupId);
    m_isWallpaper = VFX_TRUE;
}

void VappGalleryMediaListCommon::getGroupInfoFromWallpaperInfo(
                    const IWallpaperSourceStruct info,  // [IN] the wallpaper info
                    VfxS32 &groupCount,                 // [OUT] final group count
                    VfxS32 &liveWallpaperId,            // [OUT] group id for live wallpaper
                    VfxS32 &staticWallpaperId,           // [OUT] group id for static wallpaper
                    VfxS32 &videoWallpaperId           // [OUT] group id for video wallpaper
                    )
{
    // decide group count and group id
    groupCount = 0;
    liveWallpaperId = -1;
    staticWallpaperId = -1;
    videoWallpaperId = -1;
    if(info.static_wallpaper_count
       && info.live_wallpaper_count)
    {
        groupCount = 2;
        liveWallpaperId = 0;
        staticWallpaperId = 1;
    }
    else if(info.live_wallpaper_count)
    {
        groupCount = 1;
        liveWallpaperId = 0;
    }
    else if(info.static_wallpaper_count)
    {
        groupCount = 1;
        staticWallpaperId = 0;
    }

    if(info.video_wallpaper_count > 0)
    {
        groupCount += 1;
        videoWallpaperId = groupCount - 1;
    }

}

VfxS32 VappGalleryMediaListCommon::getWallpaperGroupCount()
{
    return m_groupCount;
}

VfxS32 VappGalleryMediaListCommon::getWallpaperMediaCountInGroup(VfxS32 group)
{
    if(m_liveWallpaperGroupId== group)
    {
        return m_sourceInfo.live_wallpaper_count;
    }
    else if(m_staticWallpaperGroupId == group)
    {
        return m_sourceInfo.static_wallpaper_count;
    }
    else if(m_videoWallpaperGroupId == group)
    {
        return m_sourceInfo.video_wallpaper_count;
    }
	return 0;
}

void VappGalleryMediaListCommon::getWallpaperGroupName(const VfxS32 group, VfxWString &groupName)
{
    if(m_liveWallpaperGroupId == group)
    {
        groupName.loadFromRes(m_sourceInfo.live_wallpaper_title);
    }
    else if(m_staticWallpaperGroupId == group)
    {
        groupName.loadFromRes(m_sourceInfo.static_wallpaper_title);
    }
    else if(m_videoWallpaperGroupId == group)
    {
        groupName.loadFromRes(m_sourceInfo.video_wallpaper_title);
    }
}

// name is a really common attribute, so give it a special interface here.
VappGalleryDecodeResult VappGalleryMediaListCommon::getWallpaperMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr)
{
    nameStr.setEmpty();
    return OK;
}

VappGalleryMediaGroupType VappGalleryMediaListCommon::getWallpaperMediaGroupType(const VcpMenuPos &itemIdx)
{
    if(m_videoWallpaperGroupId == itemIdx.group)
    {
        return MEDIA_GROUP_VIDEO;
    }
    else
    {
        return MEDIA_GROUP_IMAGE;
    }
}

// override this for File-based wallpaper case
VappGalleryDecodeResult VappGalleryMediaListCommon::getWallpaperMediaPath(const VcpMenuPos &itemIdx, VfxWString &path)
{
    MMI_ID imageID = m_sourceInfo.get_thumb_img_id(
                                  getWallpaperTypeFromGroupId(itemIdx.group),
                                  itemIdx.pos,
                                  m_sourceInfo.user_data);
    // imageID 0 means this is file-based wallpaper
    if(0 == imageID)
    {
        return OK;
    }

    return FORMAT_UNSUPPORTED;
}

// retrieve the original media source.
VappGalleryDecodeResult VappGalleryMediaListCommon::getWallpaperMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src)
{
    MMI_ID imageID = m_sourceInfo.get_thumb_img_id(
                                  getWallpaperTypeFromGroupId(itemIdx.group),
                                  itemIdx.pos,
                                  m_sourceInfo.user_data);

    if(imageID)
    {
        src.setResId(imageID);
        return OK;
    }
    else
    {
        return FORMAT_UNSUPPORTED;
    }

}

VappWpResType VappGalleryMediaListCommon::getWallpaperTypeFromGroupId(VfxS32 group) const
{
    VappWpResType type = VAPP_WALLPAPER_STATIC_WALLPAPER;
    if(m_liveWallpaperGroupId == group)
    {
        type = VAPP_WALLPAPER_LIVE_WALLPAPER;
    }
    else if(m_staticWallpaperGroupId == group)
    {
        type = VAPP_WALLPAPER_STATIC_WALLPAPER;
    }
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    else if(m_videoWallpaperGroupId == group)
    {
        type = VAPP_WALLPAPER_VIDEO_WALLPAPER;
    }
#endif

    return type;
}

/*****************************************************************************
 * Implementation of VappGalleryDecoderBase
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryDecoderBase", VappGalleryDecoderBase, VfxObject);

VappGalleryDecoderBase::VappGalleryThumbDecodeSignal* VappGalleryDecoderBase::getReadySignal()
{
    VFX_ASSERT(0);
    return NULL;
}

gdi_handle VappGalleryDecoderBase::convertImageBufferToLayer(const VfxImageBuffer &imgBuf)
{
    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;

    // Thumbnail must be 16-bit RGB565 or 24-bit RGB888 now
    VFX_ASSERT(imgBuf.colorFormat == VRT_COLOR_TYPE_RGB565 ||
               imgBuf.colorFormat == VRT_COLOR_TYPE_RGB888 ||
               imgBuf.colorFormat == VRT_COLOR_TYPE_UYVY422);
    res = gdi_layer_create_cf_using_outside_memory(convertCF_VRT2GDI(imgBuf.colorFormat),
                                                   0, 0,
                                                   imgBuf.width,
                                                   imgBuf.height,
                                                   &thumbLayer,
                                                   imgBuf.ptr,
                                                   imgBuf.pitchBytes * imgBuf.height);
    VFX_ASSERT(GDI_SUCCEED == res);
    return thumbLayer;
}


VfxBool VappGalleryDecoderBase::verifyImageBuffer(const VfxImageBuffer &imgBuf)
{
    VfxBool ret = VFX_FALSE;
    do
    {
        if(NULL == imgBuf.ptr)
            break;

        if(imgBuf.pitchBytes != imgBuf.width * VAPP_GALLERY_THUMB_BPP)
            break;

        // Thumbnail must be 16-bit RGB565 or 24-bit RGB888 now
        if(VRT_COLOR_TYPE_RGB565 != imgBuf.colorFormat &&
           VRT_COLOR_TYPE_RGB888 != imgBuf.colorFormat &&
           VRT_COLOR_TYPE_UYVY422 != imgBuf.colorFormat )
            break;

        if(imgBuf.width * imgBuf.height <= 0)
            break;

        ret = VFX_TRUE;
    }while(0);

    return ret;
}

/*****************************************************************************
 * Implementation of VappGalleryImageThumbnail
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryImageThumbnail", VappGalleryImageThumbnail, VappGalleryDecoderBase);
VappGalleryImageThumbnail* VappGalleryImageThumbnail::g_decodingInst = NULL;
VappGalleryImageThumbnail* VappGalleryImageThumbnail::g_enhanceDecodingInst = NULL;

VappGalleryImageThumbnail::VappGalleryImageThumbnail():
    m_job(NULL),
    m_layer(NULL),
    m_imgType(GDI_IMAGE_TYPE_INVALID),
    m_thumbFitMode(-1),
    m_isEnhanceDecodeMode(VFX_FALSE)
{
}

VappGalleryImageThumbnail::VappGalleryImageThumbnail(VfxBool isEnhanceDecodeMode):
    m_job(NULL),
    m_layer(NULL),
    m_imgType(GDI_IMAGE_TYPE_INVALID),
    m_thumbFitMode(-1),
    m_isEnhanceDecodeMode(isEnhanceDecodeMode)
{
}

VappGalleryImageThumbnail::VappGalleryThumbDecodeSignal* VappGalleryImageThumbnail::getReadySignal()
{
    return &m_signalResult;
}

void VappGalleryImageThumbnail::onInit()
{
    VappGalleryDecoderBase::onInit();
}

void VappGalleryImageThumbnail::onDeinit()
{
    cancel();
    VappGalleryDecoderBase::onDeinit();
}

void VappGalleryImageThumbnail::configThumbFitMode(gdi_util_mode_enum gdiFitMode)
{
    m_thumbFitMode = gdiFitMode;
}

void VappGalleryImageThumbnail::fitThumbImpl(
                                    const VfxSize originalDim,
                                    const VfxSize  dstSize,
                                    VfxRect &clipWindow,
                                    VfxBool &shouldCleanBlack)
{
    if(-1 == m_thumbFitMode)
    {
        fitInsideImpl(originalDim, dstSize, clipWindow, shouldCleanBlack);
    }
    else
    {
        gdi_util_fit_box(
                        m_thumbFitMode,
                        dstSize.width,
                        dstSize.height,
                        originalDim.width,
                        originalDim.height,
                        &clipWindow.origin.x,
                        &clipWindow.origin.y,
                        &clipWindow.size.width,
                        &clipWindow.size.height
                        );
    }
}

void VappGalleryImageThumbnail::fitInsideImpl(
                                    const VfxSize originalDim,
                                    const VfxSize  dstSize,
                                    VfxRect &clipWindow,
                                    VfxBool &shouldCleanBlack)
{
    const VfxS32 &originalW = originalDim.width;
    const VfxS32 &originalH = originalDim.height;
    VfxS32 offsetX = 0;
    VfxS32 offsetY = 0;
    VfxS32 targetW = 1;
    VfxS32 targetH = 1;
    VfxBool mustClearBlack = VFX_TRUE;

    if(originalW <= dstSize.width ||
       originalH <= dstSize.height)
    {
        mustClearBlack = VFX_TRUE;
        const VfxS32 layer_w = dstSize.width;
        const VfxS32 layer_h = dstSize.height;

        if (originalW > layer_w && originalH > layer_h)
        {
            const VfxS32 v_rate = originalH * 1000 / layer_h;
            const VfxS32 h_rate = originalW * 1000 / layer_w;
            if (v_rate < h_rate)
            {
                targetH = layer_h;
                targetW = layer_h * originalW / originalH;
            }
            else
            {
                targetW = layer_w;
                targetH = layer_w * originalH / originalW;
            }
        }
        else
        {
            targetW = originalW;
            targetH = originalH;
        }
        if (targetW > layer_w)
        {
            offsetX -= (targetW - layer_w)/2;
        }
        else
        {
            offsetX += (layer_w - targetW)/2;
        }
        if (targetH > layer_h)
        {
            offsetY -= (targetH - layer_h)/3;
        }
        else
        {
            offsetY += (layer_h - targetH)/2;
        }
    }
    else
    {
        mustClearBlack = VFX_FALSE;
        // this only works when original > target
        gdi_util_fit_box(
                        GDI_UTIL_MODE_SHORT_SIDE_FIT,
                        dstSize.width,
                        dstSize.height,
                        originalW,
                        originalH,
                        &offsetX,
                        &offsetY,
                        &targetW,
                        &targetH
                        );
    }

    // if this is a portrait image,
    // make the offset 1/2 upper,
    // so we can see the "face" of the subject
    if(offsetY < 0)
    {
        offsetY /= 2;
    }

    // update result
    shouldCleanBlack = mustClearBlack;
    clipWindow = VfxRect(offsetX, offsetY, targetW, targetH);
}

void VappGalleryImageThumbnail::decode(const VfxWString &filename, VfxImageBuffer &thumbBuffer, const VfxRect clipRegion, const VfxSize orignalDimension)
{
    // verify input
    if(!verifyImageBuffer(thumbBuffer))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_IMAGE_THUMBNAIL_DECODE_FAIL_BAD_INPUT);
        m_signalResult.emit(this, UNEXPECTED);
        return;
    }

#ifdef __DRM_SUPPORT__
    // check DRM state
    do
    {
        if(DRM_METHOD_NONE == DRM_get_object_method(NULL, (kal_wchar*)filename.getBuf()))
        {
            break;
        }

        if(!DRM_validate_permission(0, (kal_wchar*)filename.getBuf(), DRM_PERMISSION_DISPLAY))
        {
            m_signalResult.emit(this, DRM_LOCKED);
            return;
        }
    }while(0);
#endif

    // create layer from the cache item (external memory)
    m_layer = convertImageBufferToLayer(thumbBuffer);
    VFX_ASSERT(GDI_NULL_HANDLE != m_layer);

    // only 1 decoding at the same time.
    if(m_isEnhanceDecodeMode)
    {
        VFX_ASSERT(NULL == g_enhanceDecodingInst);
        g_enhanceDecodingInst = this;
    }
    else
    {
        VFX_ASSERT(NULL == g_decodingInst);
        g_decodingInst = this;
    }

    // decide crop region
    VfxSize originalDim= orignalDimension;
    do
    {
        if(1 < orignalDimension.height && 1 < orignalDimension.width)
            break;

        originalDim.width = 1;
        originalDim.height = 1;
    if(!getDimension(filename, originalDim))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_IMAGE_THUMBNAIL_DECODE_FILE_TOO_LARGE, originalDim.width, originalDim.height);
        m_signalResult.emit(this, FORMAT_UNSUPPORTED);
        return;
    }
    }while(0);

    // calculate thumbnail clip window
    VfxRect clipWindow = VfxRect(0, 0, 1, 1);
    VfxBool mustClearBlack = VFX_TRUE;
    if(0 != clipRegion.size.width && 0 != clipRegion.size.height)
    {
        clipWindow = clipRegion;
    }
    else
    {
         fitThumbImpl(originalDim,
                 VfxSize(thumbBuffer.width, thumbBuffer.height),
                 clipWindow,
                 mustClearBlack);
    }

    // adjust clip window origin.
    // YUV format must be 2x in terms of dimension and offset
    if(VRT_COLOR_TYPE_UYVY422 == thumbBuffer.colorFormat)
    {
        clipWindow.origin.x = clipWindow.origin.x / 2 * 2;
        clipWindow.origin.y = clipWindow.origin.y / 2 * 2;
    }

    // init layer
    if(VRT_COLOR_TYPE_UYVY422 != thumbBuffer.colorFormat)
    {
        // avoid color key. note that UYVY422 does not support color key & alpha-blending.
        if(shouldReplaceSrcKey(clipWindow.size.width, clipWindow.size.height))
        {
            gdi_layer_set_source_key_nb_concurrent(m_layer, MMI_TRUE, GDI_COLOR_TRANSPARENT);
        }
        gdi_push_and_set_alpha_blending_source_layer(m_layer);
    }
    
    GALLERY_MEASURE_TIME_START("ALC");

    // GDI_COLOR_BLACK is active layer dependent. We need to follow thumbBuffer's format.
    const gdi_color blackColor = gdi_cf_get_color(convertCF_VRT2GDI(thumbBuffer.colorFormat), 255, 0, 0, 0);

    // if the decoded image fills the output buffer,
    // see if we can skip clear color at all.
    // Clear color can be expensive for large output buffer.
    if(mustClearBlack)
    {
        gdi_layer_clear_nb_concurrent(m_layer, blackColor);
    }
    else
    {
        // still need to clear black for image types with transparency
        // note: 32-bit BMP is not supported
        switch(m_imgType)
        {
        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
            gdi_layer_clear_nb_concurrent(m_layer, blackColor);
            break;
        }
    }
    GALLERY_MEASURE_TIME_STOP("ALC");

    GALLERY_MEASURE_TIME_START("ADF");
    #if defined(VAPP_GALLERY_IMG_VIEWER_BPP) && (VAPP_GALLERY_IMG_VIEWER_BPP == 3)
    const U32 flag = GDI_IMAGE_CODEC_FLAG_DISABLE_DITHER;
    #else
    const U32 flag = 0;
    #endif

    PFN_GDI_IMGDC_CB pCB = (m_isEnhanceDecodeMode) ? (onEnhanceModeDecodeResult) : (onNormalModeDecodeResult);
    // this function does not fail (it asserts directly when there is no job slot)
 
    m_job = gdi_imgdec_nb_draw_resized_file_with_flag(
                    m_layer,
                    clipWindow.origin.x,
                    clipWindow.origin.y,
                    clipWindow.size.width,
                    clipWindow.size.height,
                    (U8*)filename.getBuf(),
                    pCB,
                    flag); 
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_IMAGE_THUMBNAIL_CALLED_GDI_IMGDEC_NB_DRAW_RESIZED_FILE_JOB_D, m_job);

    if(VRT_COLOR_TYPE_UYVY422 != thumbBuffer.colorFormat)
    {
        // note that UYVY422 does not support color key & alpha-blending.
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
}

void VappGalleryImageThumbnail::cancel()
{
    GALLERY_MEASURE_TIME_STOP("ADF");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_IMAGE_THUMBNAIL_STOP_JOB_X, m_job);

    if(m_isEnhanceDecodeMode && NULL == g_enhanceDecodingInst)
        return;
    else if(!m_isEnhanceDecodeMode && NULL == g_decodingInst)
        return;

    // note: a valid m_job could be GDI_NULL_HANDLE!
    GDI_RESULT res = gdi_imgdec_nb_stop(m_job);
    m_job = GDI_NULL_HANDLE;

    if(GDI_NULL_HANDLE != m_layer)
    {
        GDI_RESULT res = gdi_layer_free(m_layer);
        m_layer = GDI_NULL_HANDLE;
    }


    // reset global decoding instance
    if(m_isEnhanceDecodeMode && this == g_enhanceDecodingInst)
        g_enhanceDecodingInst = NULL;
    else if(!m_isEnhanceDecodeMode && this == g_decodingInst)
        g_decodingInst = NULL;

}

VfxBool VappGalleryImageThumbnail::getDimension(const VfxWString &filename, VfxSize &dim)
{
    VfxU16 srcType = GDI_IMAGE_TYPE_INVALID;
    return getDimensionEx(filename, dim, srcType);
}

VfxBool VappGalleryImageThumbnail::getDimensionEx(const VfxWString &filename, VfxSize &dim, VfxU16 &srcType)
{
GALLERY_MEASURE_TIME_START("Ggf");
    srcType = gdi_image_get_type_from_file((CHAR*)filename.getBuf());
GALLERY_MEASURE_TIME_STOP("Ggf");
    m_imgType = srcType;
    if(GDI_IMAGE_TYPE_INVALID == srcType)
    {
        return VFX_FALSE;
    }

GALLERY_MEASURE_TIME_START("Ggd");
    GDI_RESULT result = gdi_imgdec_get_dimension_file(
                                    (CHAR*)filename.getBuf(),
                                    &dim.width,
                                    &dim.height);
GALLERY_MEASURE_TIME_STOP("Ggd");
    // check for image dimension to prevent potiential overflow
    VfxS32 checkWidth = dim.width;
    VfxS32 checkHeight = dim.height;

    // check GIF/PNG limitation (4095 here)
    switch(srcType)
    {
    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
    case GDI_IMAGE_TYPE_GIF:
    case GDI_IMAGE_TYPE_GIF_FILE:
    case GDI_IMAGE_TYPE_PNG:
    case GDI_IMAGE_TYPE_PNG_FILE:
    case GDI_IMAGE_TYPE_PNG_SEQUENCE:
    case GDI_IMAGE_TYPE_BMP:
    case GDI_IMAGE_TYPE_BMP_FILE:
        if(checkWidth > MAX_GIF_PNG_SUPPORT_DIM || checkHeight > MAX_GIF_PNG_SUPPORT_DIM)
        {
            return VFX_FALSE;
        }
        break;
    default:
        break;
    }

    // check overflow
    if(checkWidth <= 0 || checkHeight <= 0 || (checkWidth * checkHeight) <= 0)
    {
        return VFX_FALSE;
    }
    return GDI_SUCCEED == result;
}

void VappGalleryImageThumbnail::onNormalModeDecodeResult(GDI_RESULT result, gdi_handle handle)
{
    if(NULL == g_decodingInst)
    {
        // why do we reach here?
        VFX_ASSERT(0);
        return;
    }

    VappGalleryImageThumbnail *pThis = g_decodingInst;
    g_decodingInst = NULL;
    pThis->handleDecodeResult(result, handle);
}

void VappGalleryImageThumbnail::onEnhanceModeDecodeResult(GDI_RESULT result, gdi_handle handle)
{
    if(NULL == g_enhanceDecodingInst)
    {
        // why do we reach here?
        VFX_ASSERT(0);
        return;
    }

    VappGalleryImageThumbnail *pThis = g_enhanceDecodingInst;
    g_enhanceDecodingInst = NULL;
    pThis->handleDecodeResult(result, handle);
}

void VappGalleryImageThumbnail::handleDecodeResult(GDI_RESULT result, gdi_handle handle)
{
    GALLERY_MEASURE_TIME_STOP("ADF");
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_IMAGE_THUMBNAIL_GDI_DECODE_RESULT_D_FOR_JOB_D, result, handle);
    if(handle != m_job)
    {
        return;
    }
    VFX_ASSERT(GDI_NULL_HANDLE != m_layer);
    // free the layer and job
    GDI_RESULT res = gdi_layer_free(m_layer);
    VFX_ASSERT(GDI_SUCCEED == res);
    m_layer = GDI_NULL_HANDLE;
    m_job = 0;

    if(m_isEnhanceDecodeMode)
        g_enhanceDecodingInst = NULL;
    else
        g_decodingInst = NULL;

    m_signalResult.emit(this, translateGDIResult(result));
    return;
}

VappGalleryDecodeResult VappGalleryImageThumbnail::translateGDIResult(GDI_RESULT result)
{
    switch(result)
    {
    case GDI_SUCCEED:
        return OK;
    default:
        return FORMAT_UNSUPPORTED;
    }
}

/*****************************************************************************
 * Implementation of VappGalleryVideoThumbnail
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryVideoThumbnail", VappGalleryVideoThumbnail, VappGalleryDecoderBase);

VappGalleryVideoThumbnail::VappGalleryVideoThumbnail():
    m_appId(NULL),
    m_decoding(VFX_FALSE),
    m_videoOpened(VFX_FALSE),
    m_videoSeeking(VFX_FALSE),
    m_isLiteMemoryMode(VFX_TRUE),   
    m_decodingLayer(GDI_LAYER_EMPTY_HANDLE)
{
    kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));
}

void VappGalleryVideoThumbnail::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_ON_INIT);
    VappGalleryDecoderBase::onInit();

    // reset all state variables
    clearState();

    m_appId = findRootAppId(this);
}

void VappGalleryVideoThumbnail::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_ON_DEINIT);
    clearState();
    m_appId = NULL;
    VappGalleryDecoderBase::onDeinit();
}

void VappGalleryVideoThumbnail::configLiteMemory(VfxBool isLiteMemory)
{
    m_isLiteMemoryMode = isLiteMemory;
}

VappGalleryVideoThumbnail::VappGalleryThumbDecodeSignal* VappGalleryVideoThumbnail::getReadySignal()
{
    return &m_signalDecode;
}

void VappGalleryVideoThumbnail::clearState()
{
    // there is no explicit cancel in MDI video,
    // so we force close the file.
    // MDI video gurantees no futher callback
    if(m_videoSeeking)
    {
        mdi_video_ply_stop_non_block_seek();
        m_videoSeeking = VFX_FALSE;
    }
    if(m_decodingLayer || m_videoOpened)
    {
        mdi_video_ply_close_file();
        m_videoOpened = VFX_FALSE;
    }

    if(m_decodingLayer)
    {
        gdi_layer_free(m_decodingLayer);
        m_decodingLayer = GDI_LAYER_EMPTY_HANDLE;
    }
    m_decoding = VFX_FALSE;
}

void VappGalleryVideoThumbnail::cancel()
{
    clearState();
}

VfxBool VappGalleryVideoThumbnail::getDimension(const VfxWString &filename, VfxSize &dim)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_GET_DIMENSION);
    // use cached info
    if(m_videoInfo.total_time_duration > 0)
    {
        dim.width = m_videoInfo.width;
        dim.height = m_videoInfo.height;
        return VFX_TRUE;
    }

    if(m_decoding)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_GET_DIMENSION_DURING_DECODING);
        return VFX_FALSE;
    }

    mdi_video_info_struct info;
    kal_mem_set(&info, 0, sizeof(info));
    if(m_isLiteMemoryMode)
    {
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);
    }
    MDI_RESULT result = mdi_video_ply_open_clip_file(
                                m_appId,
                                (const  CHAR*)filename.getBuf(),
                                &info);
    if(MDI_RES_VDOPLY_SUCCEED != result)
    {
        return VFX_FALSE;
    }

    dim.width = info.width;
    dim.height = info.height;
    mdi_video_ply_close_clip_file();
    return VFX_TRUE;
}

VfxBool VappGalleryVideoThumbnail::getDimensionEx(const VfxWString &filename, VfxSize &dim, VfxU16 &srcType)
{
    VFX_UNUSED(srcType);
    return getDimension(filename, dim);
}

U64 VappGalleryVideoThumbnail::getDecodedDuration()
{
    return m_videoInfo.total_time_duration;
}

void VappGalleryVideoThumbnail::decode(const VfxWString &filename, VfxImageBuffer &thumbBuffer, const VfxRect clipRegion, const VfxSize orignalDimension)
{
    VFX_UNUSED(orignalDimension);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_DECODE);
    // This is the beginning of entire decode flow
    // first we async open the file
    // then, async retrieve snapshot
    if(m_decoding)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_DECODE_DURING_DECODING);
        clearState();
        m_signalDecode.postEmit(this, UNEXPECTED);
        return;
    }

    if(!verifyImageBuffer(thumbBuffer))
    {
        // assert on MoDIS for invalid parameter
        VFX_DEV_ASSERT(0);
        clearState();
        m_signalDecode.postEmit(this, UNEXPECTED);
        return;
    }

    VFX_ASSERT(VFX_FALSE == m_decoding);

    m_decoding = VFX_TRUE;
    m_decodingFile = filename;
    kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));

    m_thumbBuffer = thumbBuffer;
    if(m_isLiteMemoryMode)
    {
        mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);
    }
    MDI_RESULT result = mdi_video_ply_open_file(
                                            m_appId,
                                            (const CHAR*)m_decodingFile.getBuf(),
                                            &onVideoOpenResult,
                                            getObjHandle());

    VappGalleryDecodeResult decodeResult = translateMDIResult(result);
    if(OK != decodeResult)
    {
        clearState();
        m_signalDecode.postEmit(this, decodeResult);
        return;
    }
    else
    {
        m_videoOpened = VFX_TRUE;
    }
}

void VappGalleryVideoThumbnail::handleVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_HANDLE_VIDEO_OPEN_RESULT_RET_D, ret);

    if(!m_decoding)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_HANDLE_VIDEO_OPEN_RESULT_BUT_M_DECODING_IS_VFX_FALSE);
        return;
    }

    const VappGalleryDecodeResult openFileResult = translateMDIResult(ret);
    if(OK != openFileResult)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_HANDLE_VIDEO_OPEN_RESULT_ERR_D, openFileResult);
        clearState();
        m_signalDecode.postEmit(this, openFileResult);
        return;
    }

    // fill video info
    if(video_info)
    {
        kal_mem_cpy(&m_videoInfo, video_info, sizeof(mdi_video_info_struct));
    }
    else
    {
        kal_mem_set(&m_videoInfo, 0, sizeof(m_videoInfo));
    }

    // clear thumbnail buffer first, in case decode fails without error code.
    if(m_thumbBuffer.ptr)
    {
        kal_mem_set(m_thumbBuffer.ptr, 0, m_thumbBuffer.height * m_thumbBuffer.pitchBytes);
    }

    // fill video thumbnail in cache item
    VFX_ASSERT(NULL == m_decodingLayer);
    m_decodingLayer = convertImageBufferToLayer(m_thumbBuffer);
    VFX_ASSERT(GDI_LAYER_EMPTY_HANDLE != m_decodingLayer);

    // check MDI get frame capacity
    // if MDI get frame utility dose not support RGB565, translate layer to UYVY422
#if defined(__MTK_TARGET__)
    if(GDI_COLOR_FORMAT_UYVY422 == mdi_video_ply_get_default_frame_color_format())
    {
        checkSnapshotLayerColorFormat(convertCF_VRT2GDI(m_thumbBuffer.colorFormat), GDI_COLOR_FORMAT_UYVY422);
    }
#endif
    // use SNAPSHOT_TIME if video is long enough,
    // use half of video time if video is too short.
    U64 snapShotMsec = 0;
    if(m_isLiteMemoryMode)
    {
        snapShotMsec = 0;
    }
    else
    {
        snapShotMsec = m_videoInfo.total_time_duration >= SNAPSHOT_TIME ? SNAPSHOT_TIME : m_videoInfo.total_time_duration / 2;
    }
    mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE);
    MDI_RESULT getThumbResult = mdi_video_ply_non_block_seek_and_get_frame(
                                                                snapShotMsec,
                                                                m_decodingLayer,
                                                                &onVideoSeekResult,
                                                                getObjHandle());
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_MDI_VIDEO_PLY_NON_BLOCK_SEEK_AND_GET_FRAME, getThumbResult);
    const VappGalleryDecodeResult decodeResult = translateMDIResult(getThumbResult);
    if(OK != decodeResult)
    {
        m_videoSeeking = VFX_FALSE;
        clearState();
        m_signalDecode.postEmit(this, decodeResult);
        return;
    }
    else
    {
        m_videoSeeking = VFX_TRUE;
    }
}

void VappGalleryVideoThumbnail::handleVideoSeekResult(MDI_RESULT ret)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_HANDLE_VIDEO_SEEK_RESULT, ret);
    m_videoSeeking = VFX_FALSE;
    if(!m_decoding)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_HANDLE_VIDEO_SEEK_RESULT_BUT_M_DECODING_IS_VFX_FALSE);
        return;
    }

    VappGalleryDecodeResult decodeResult = translateMDIResult(ret);

#if defined(__MTK_TARGET__)
    // check if decode layer color is same as thumb buffer's to avoid mess frame
    if(GDI_COLOR_FORMAT_UYVY422 == mdi_video_ply_get_default_frame_color_format())
    {
        const gdi_color_format targetCF = convertCF_VRT2GDI(m_thumbBuffer.colorFormat);
        checkSnapshotLayerColorFormat(GDI_COLOR_FORMAT_UYVY422, targetCF);
    }
#endif

    // close MDI and emit result to user
    clearState();
    m_signalDecode.postEmit(this, decodeResult);
    return;
}

void VappGalleryVideoThumbnail::onVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data)
{
    VappGalleryVideoThumbnail *pThis = (VappGalleryVideoThumbnail*)handleToObject((VfxObjHandle)user_data);
    if(NULL == pThis)
    {
        return;
    }
    // call current instance to handle
    pThis->handleVideoOpenResult(ret, video_info);
}

void VappGalleryVideoThumbnail::onVideoSeekResult(MDI_RESULT ret, void *user_data)
{
    VappGalleryVideoThumbnail *pThis = (VappGalleryVideoThumbnail*)handleToObject((VfxObjHandle)user_data);
    if(NULL == pThis)
    {
        return;
    }
    // call current instance to handle
    pThis->handleVideoSeekResult(ret);
}

VappGalleryDecodeResult VappGalleryVideoThumbnail::translateMDIResult(MDI_RESULT ret)
{
    // translate error codes
    switch(ret)
    {
    case MDI_RES_VDOPLY_SUCCEED:
        return OK;
    case MDI_RES_VDOPLY_STREAM_DRM_NEED_RIGHT:
    case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
    case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
        return DRM_LOCKED;
    default:
        return FORMAT_UNSUPPORTED;
    }
}

void VappGalleryVideoThumbnail::checkSnapshotLayerColorFormat(const gdi_color_format sourceCF, const gdi_color_format targetCF)
{
    if(GDI_LAYER_EMPTY_HANDLE == m_decodingLayer)
    {
        return;
    }

    if(targetCF == sourceCF)
    {
        return;
    }

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
    gdi_layer_push_and_set_active(m_decodingLayer);
    do
    {
        // lock mutex
        gdi_lcd_lock_mutex();
        gdi_waiting_blt_finish();
        // convert layer color format
        // note mdi_util_convert_color_format change buffer content of layer, but it dose not change cf of layer handle
        //GDI_RESULT convertRes = gdi_layer_set_color_format(targetCF);
        MMI_BOOL convertRes = mdi_util_convert_color_format(m_decodingLayer, sourceCF, targetCF);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIDEO_THUMBNAIL_CHECK_SNAPSHOT_LAYER_CF, sourceCF, targetCF, convertRes);
        // release LCD mutex
        gdi_lcd_unlock_mutex();
    }while(0);
    gdi_layer_pop_and_restore_active();
}

#ifdef __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__
/*****************************************************************************
 * Implementation of VappGalleryMediaListVideoInfo
 *****************************************************************************/
VappGalleryMediaListVideoInfo::VappGalleryMediaListVideoInfo():
    m_fileList(NULL),
	m_appId(NULL),   
    m_backgroundMode(VFX_FALSE),	
    m_parsing(VFX_FALSE),   
    m_videoDecoder(NULL),
    m_videoInfoCache(NULL),
    m_videoDB(NULL)
{
}

void VappGalleryMediaListVideoInfo::onInit()
{
    VfxObject::onInit();
    m_appId = findRootAppId(this);
    m_videoDecoder = NULL;

    // this allocates in ASM FG
    VFX_OBJ_CREATE(m_videoInfoCache, VideoInfoCache, this);
    // this allocates in Venus heap (ASM BASE)
    VFX_OBJ_CREATE(m_fileList, VappGalleryFmgrList, this);
}

void VappGalleryMediaListVideoInfo::onDeinit()
{
    releaseForegroundMemory();
    VFX_OBJ_CLOSE(m_fileList);
    VfxObject::onDeinit();
}

VfxBool VappGalleryMediaListVideoInfo::configFolderPaths(U8 drv)
{
    if(NULL == m_fileList)
    {

        return VFX_FALSE;
    }

    m_fileList->config(drv, &m_signalReady, &m_signalReloadStart, &m_signalReloadFinished);
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListVideoInfo::configFileTypeFilter(const FMGR_FILTER *filter)
{
    if(NULL == m_fileList)
        return VFX_FALSE;

    m_fileList->configFileTypeLimit(filter);
    return VFX_TRUE;
}

void VappGalleryMediaListVideoInfo::configVideoDB(VappGalleryDB *pDB)
{
    // once set, DB instance cannot be changed.
    VFX_ASSERT(NULL == m_videoDB);
    m_videoDB = pDB;
}

VfxBool VappGalleryMediaListVideoInfo::isPrepared() const
{
    if(NULL == m_fileList)
        return VFX_FALSE;

    return m_fileList->isPrepared();
}

void VappGalleryMediaListVideoInfo::prepareList()
{
    if(NULL == m_fileList)
        return;

    if(m_fileList->isPrepared())
    {
        return;
    }

    m_fileList->prepare();
}

VfxBool VappGalleryMediaListVideoInfo::refreshList()
{
    if(NULL == m_fileList)
    {
        return VFX_FALSE;
    }

    if(!m_fileList->isPrepared())
    {
        return VFX_FALSE;
    }

    // clear and re-set the cache
    VFX_OBJ_CLOSE(m_videoInfoCache);
    VFX_OBJ_CREATE(m_videoInfoCache, VideoInfoCache, this);

    // refresh the list.
    // if it succeeds, media cache will be re-prepared
    m_fileList->refresh();
    return VFX_TRUE;
}

void VappGalleryMediaListVideoInfo::release()
{
    VappGalleryMediaListVideoInfo* pThis = this;
    VFX_OBJ_CLOSE(pThis);
}

VfxBool VappGalleryMediaListVideoInfo::releaseForegroundMemory()
{
    // stop decoding (MDI uses FG memory)
    if(m_videoDecoder || m_parsing)
    {
        VFX_OBJ_CLOSE(m_videoDecoder);
        if(m_videoInfoCache && m_parsingIndex.isValid())
        {
            const VfxId itemId = convertItemIdFromMenuPos(m_parsingIndex);
            const VappGalleryVideoInfoCacheItem *pCacheItem = m_videoInfoCache->getCacheIfPresent(itemId);
            if(pCacheItem)
            {
                m_videoInfoCache->unlockCache(itemId);
                pCacheItem = NULL;
            }
        }
        m_parsingIndex.invalid();
        m_parsing = VFX_FALSE;
    }

    // info cache is FG ASM
    m_backgroundMode = VFX_TRUE;
    VFX_OBJ_CLOSE(m_videoInfoCache);

    // release DB
    m_videoDB = NULL;

    return VFX_TRUE;
}

VfxBool VappGalleryMediaListVideoInfo::obtainForegroundMemory()
{
    m_backgroundMode = VFX_FALSE;
    if(NULL == m_videoInfoCache)
    {
        // this allocates in ASM FG
        VFX_OBJ_CREATE(m_videoInfoCache, VideoInfoCache, this);
    }
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListVideoInfo::enableBackgroundDecode(VfxBool isEnable)
{
    if(!isEnable)
    {
        // stop decoding (MDI uses FG memory)
        VFX_OBJ_CLOSE(m_videoDecoder);
        m_parsingIndex.invalid();
        m_parsing = VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxS32 VappGalleryMediaListVideoInfo::getGroupCount()
{
    // 0 groups before prepared
    if(!isPrepared())
    {
        return 0;
    }

#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_FOLDER__
    // otherwise check if "My Received" has any files.
    // if it is empty, only 1 group (My Video) is returned.
    return getMediaCountInGroup(1) > 0 ? MAX_FOLDER_COUNT : 1;
#else
    // "My Video" group only
    return 1;
#endif
}

VfxS32 VappGalleryMediaListVideoInfo::getMediaCountInGroup(VfxS32 grpIdx)
{
    if(grpIdx < 0 || grpIdx >= MAX_FOLDER_COUNT)
    {
        return 0;
    }

    if(!isPrepared())
    {
        return 0;
    }

    // query count from filelist
    return m_fileList->getFileCount(grpIdx);
}

void VappGalleryMediaListVideoInfo::getGroupName(const VfxS32 group, VfxWString &groupName)
{
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_FOLDER__
    switch(group)
    {
    case 0:
        groupName = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYVIDEO);
        break;
    case 1:
        groupName = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYRECEIVED);
        break;
    default:
        // currently we support only groups.
        groupName = VFX_WSTR_RES(STR_GLOBAL_ERROR);
        break;
    }
#else
    groupName = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYVIDEO);
#endif
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr)
{
    if(itemIdx.group < 0 || itemIdx.group >= MAX_FOLDER_COUNT)
    {
        return UNEXPECTED;
    }

    return m_fileList->getFileName(itemIdx, nameStr);
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path)
{
    if(itemIdx.group < 0 || itemIdx.group >= MAX_FOLDER_COUNT)
    {
        return UNEXPECTED;
    }

    return m_fileList->getPathName(itemIdx, path);
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src)
{
    VfxWString path;
    VappGalleryDecodeResult ret = m_fileList->getPathName(itemIdx, path);
    src.setPath(path);
    return ret;
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::startDecodeThumb(
    VcpMenuPos itemIdx,
    VfxImageBuffer& buffer)
{
    return getThumbImageSrcImpl(itemIdx, buffer, VFX_TRUE);
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::startDecodeThumbEx(
    VcpMenuPos itemIdx,
    VfxImageBuffer& buffer,
    const VfxBool checkMemCacheOnly)
{
    return getThumbImageSrcImpl(itemIdx, buffer, VFX_TRUE, checkMemCacheOnly);
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::lockThumb(
    const VcpMenuPos &itemIdx,
    VfxImageBuffer& buffer,)
{
    return getThumbImageSrcImpl(itemIdx, buffer, VFX_FALSE);
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::getThumbImageSrcImpl(
    const VcpMenuPos &itemIdx,
    VfxImageBuffer& buffer,
    const VfxBool checkDRM,
    const VfxBool checkMemCacheOnly)
{
    if(NULL == m_videoInfoCache)
    {
        return DECODING;
    }

    const VfxId itemCacheId = convertItemIdFromMenuPos(itemIdx);
    const VappGalleryVideoInfoCacheItem *pCacheItem = m_videoInfoCache->getCacheIfPresent(itemCacheId);

    if(pCacheItem)
    {
        if(OK == pCacheItem->m_result)
        {
            m_videoInfoCache->lockCache(itemCacheId);
            pCacheItem->getImageBuffer(buffer);

            if(checkDRM)
            {
                #ifdef __DRM_SUPPORT__
                // check if DRM license expired
                VfxWString path;
                getMediaPath(itemIdx, path);
                MDI_RESULT drmCheckResult = mdi_video_ply_drm_check_permission((const CHAR*)path.getBuf());
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLV_INFO_START_DECODE_CHECK_DRM_PERMISSION, itemIdx.group, itemIdx.pos, drmCheckResult);
                if(MDI_RES_VDOPLY_ERR_DRM_PROHIBITED == drmCheckResult)
                {
                    return DRM_LOCKED;
                }
                #endif
            }
            return OK;
        }
        else if(DECODING != pCacheItem->m_result)
        {
            return pCacheItem->m_result;
        }
    }

    if(checkMemCacheOnly && NULL == pCacheItem)
    {
        return DECODING;
    }

    if(m_parsing)
    {
        return DECODING;
    }

    if(queryMediaInfoFromDB(itemIdx))
    {
        // immediately check resulting cache
        const VappGalleryVideoInfoCacheItem *pQueryCache = m_videoInfoCache->lockCacheIfPresent(itemCacheId);
        VFX_ASSERT(pQueryCache);
        pQueryCache->getImageBuffer(buffer);
        return OK;
    }
    else
    {
        // finally we trigger decoding
        return startDecodeWithMDI(itemIdx);
    }
}

VfxBool VappGalleryMediaListVideoInfo::queryMediaInfoFromDB(const VcpMenuPos &itemIdx)
{
    if(NULL == m_videoDB || NULL == m_videoInfoCache)
    {
        return VFX_FALSE;
    }

    const VfxId key = convertItemIdFromMenuPos(itemIdx);

    // Allocate cache item to store queried results.
    VappGalleryVideoInfoCacheItem *pItem = m_videoInfoCache->lockCache(key);
    VFX_ASSERT(pItem);
    do
    {
        ivd_db_video_result_info result;
        result.result_code = MMI_IVD_OK;
        result.duration_sec = 0;
        result.bookmark_sec = 0;
        result.thumb_buf_ptr = pItem->m_thumbBuffer;
        result.thumb_buf_len = pItem->bufSize;
        result.thumb_width = pItem->VIDEO_THUMB_W;
        result.thumb_height = pItem->VIDEO_THUMB_H;

        // query file name
        VfxWString mediaPath;
        getMediaPath(itemIdx, mediaPath);
        m_videoDB->getItemInfoBlocking((WCHAR*)mediaPath.getBuf(), &result);
        if(result.result_code == MMI_IVD_OK)
        {
            // insert query result into cache item
            // NOTE: thumb buffer should already filled during query
            pItem->m_durationCache = result.duration_sec * 1000;
            pItem->m_bookmarkCache = result.bookmark_sec * 1000;
            pItem->m_result = OK;

            // unlock the item.
            m_videoInfoCache->unlockCache(key);

            return VFX_TRUE;
        }
    }while(0);

    // otherwise we explicitly release the cache item,
    // since the item content is not valid.
    m_videoInfoCache->unlockCache(key);
    m_videoInfoCache->releaseCache(key);

    return VFX_FALSE;
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::getMediaDuration(
    const VcpMenuPos &itemIdx,
    U64 &mediaDuration,
    const VfxBool checkMemCacheOnly)
{
    if(NULL == m_videoInfoCache)
    {
        return DECODING;
    }
    const VfxId itemCacheId = convertItemIdFromMenuPos(itemIdx);
    const VappGalleryVideoInfoCacheItem *pCacheItem = m_videoInfoCache->getCacheIfPresent(itemCacheId);
    if(NULL != pCacheItem)
    {
        if(OK != pCacheItem->m_result)
        {
            return pCacheItem->m_result;
        }
        mediaDuration = pCacheItem->m_durationCache;
        return OK;
    }

    if(checkMemCacheOnly && NULL == pCacheItem)
    {
        return DECODING;
    }

    if(m_parsing)
    {
        return DECODING;
    }

    if(queryMediaInfoFromDB(itemIdx))
    {
        // immediately check resulting cache
        const VappGalleryVideoInfoCacheItem *pQueryCache = m_videoInfoCache->getCacheIfPresent(itemCacheId);
        VFX_ASSERT(pQueryCache);
        mediaDuration = pQueryCache->m_durationCache;
        return OK;
    }
    else
    {
        // finally we trigger decoding
        return startDecodeWithMDI(itemIdx);
    }
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::getMediaBookmark(
    const VcpMenuPos &itemIdx,
    U64 &mediaLastPlay,
    const VfxBool checkMemCacheOnly)
{
    if(NULL == m_videoInfoCache)
    {
        return DECODING;
    }
    const VfxId itemCacheId = convertItemIdFromMenuPos(itemIdx);
    const VappGalleryVideoInfoCacheItem *pCacheItem = m_videoInfoCache->getCacheIfPresent(itemCacheId);
    if(NULL != pCacheItem)
    {
        if(OK != pCacheItem->m_result)
        {
            return pCacheItem->m_result;
        }
        mediaLastPlay = pCacheItem->m_bookmarkCache;
        return OK;
    }

    if(checkMemCacheOnly && NULL == pCacheItem)
    {
        return DECODING;
    }

    if(m_parsing)
    {
        return DECODING;
    }

    if(queryMediaInfoFromDB(itemIdx))
    {
        // immediately check resulting cache
        const VappGalleryVideoInfoCacheItem *pQueryCache  = m_videoInfoCache->getCacheIfPresent(itemCacheId);
        VFX_ASSERT(pQueryCache);
        mediaLastPlay = pQueryCache->m_bookmarkCache;
        return OK;
    }
    else
    {
        // finally we trigger decoding
        return startDecodeWithMDI(itemIdx);
    }
}

VfxBool VappGalleryMediaListVideoInfo::isMediaReady(const VcpMenuPos &itemIdx)
{
    if(NULL == m_videoInfoCache)
    {
        return VFX_FALSE;
    }
    // check if the item is already in cache list.
    const VfxId itemCacheId = convertItemIdFromMenuPos(itemIdx);
    return m_videoInfoCache->hasCache(itemCacheId);
}

VfxBool VappGalleryMediaListVideoInfo::canCheckDirty()
{
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListVideoInfo::checkDirty()
{
    if(!isPrepared())
    {
        return VFX_FALSE;
    }

    return m_fileList->isDirty();
}

VfxBool VappGalleryMediaListVideoInfo::canRemoveDBCacheElement()
{
    return VFX_TRUE;
}

VfxBool VappGalleryMediaListVideoInfo::removeDBCacheElement(VfxWString& filePath)
{
    if(NULL == m_videoDB)
        return VFX_FALSE;
    if(filePath.isNull() || filePath.isEmpty())
        return VFX_FALSE;

    m_videoDB->removeItem((WCHAR*)filePath.getBuf());
    return VFX_TRUE;
}

void VappGalleryMediaListVideoInfo::unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer)
{
    if(NULL == m_videoInfoCache)
    {
        return;
    }
    // stop decoder if the decoding index is itemidx
    if(m_videoDecoder && m_parsing && itemIdx == m_parsingIndex)
    {
        VFX_OBJ_CLOSE(m_videoDecoder);
        m_parsing = VFX_FALSE;
        m_parsingIndex.invalid();
    }
    const VfxId itemCacheId = convertItemIdFromMenuPos(itemIdx);
    m_videoInfoCache->unlockCache(itemCacheId);  // this does not "release" the cache, only unlocks it.
}

VappGalleryDecodeResult VappGalleryMediaListVideoInfo::startDecodeWithMDI(const VcpMenuPos &itemIdx)
{
    if(NULL == m_videoInfoCache || m_backgroundMode)
    {
        return DECODING;
    }
    // check if file path is ready
    VfxWString path;
    VappGalleryDecodeResult pathRes = getMediaPath(itemIdx, path);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLV_START_DECODE_WITH_MDI, itemIdx.group, itemIdx.pos, pathRes);
    #ifdef __VAPP_GALLERY_ENABLE_FS_RELOAD__
    if(DECODING == pathRes)
    {
        return DECODING;
    }
    #endif

    // set up parsing flg create decoder
    VFX_DEV_ASSERT(VFX_FALSE == m_parsing);
    m_parsing = VFX_TRUE;
    m_parsingIndex = itemIdx;

    if(NULL == m_videoDecoder)
    {
        VFX_OBJ_CREATE(m_videoDecoder, VappGalleryVideoThumbnail, this);
        m_videoDecoder->configLiteMemory(VFX_TRUE);
        m_videoDecoder->getReadySignal()->connect(this, &VappGalleryMediaListVideoInfo::onVideoDecodeResult);
    }
    // Allocate cache item and start decode
    VfxId itemId = convertItemIdFromMenuPos(m_parsingIndex);
    VappGalleryVideoInfoCacheItem *pItem = m_videoInfoCache->lockCache(itemId);
    VFX_ASSERT(pItem);
    VfxImageBuffer thumbBuf;
    pItem->getImageBuffer(thumbBuf);
    m_videoDecoder->decode(path, thumbBuf);
    return DECODING;
}

void VappGalleryMediaListVideoInfo::onVideoDecodeResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result)
{
    const VfxId itemId = convertItemIdFromMenuPos(m_parsingIndex);
    do
    {
        if(NULL == m_videoInfoCache ||
           NULL == sender ||
           static_cast<VappGalleryDecoderBase*>(m_videoDecoder) != sender)
        {
            result = UNEXPECTED;
            break;
        }

        VappGalleryVideoInfoCacheItem *pItem  = m_videoInfoCache->getCacheIfPresent(itemId);
        pItem->m_result = result;

        if(OK != result)
        {
            pItem->m_bookmarkCache = 0;
            pItem->m_durationCache = 0;
            break;
        }
        else
        {
            // fill other info in cache item
            pItem->m_bookmarkCache = 0;
            pItem->m_durationCache = m_videoDecoder->getDecodedDuration();
        }

        // write result into DB
        if(m_videoDB)
        {
            // query file name
            VfxWString path;
            getMediaPath(m_parsingIndex, path);

            // insert into DB
            ivd_db_video_result_info input;
            memset(&input, 0, sizeof(input));
            input.result_code = MMI_IVD_OK;
            input.duration_sec = (U32)msecToSec(pItem->m_durationCache);   // potential truncation, but it is rare that video is over 32-bit sec.
            input.bookmark_sec = 0;
            input.thumb_width = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W;
            input.thumb_height = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H;
            input.thumb_buf_ptr = pItem->m_thumbBuffer;
            input.thumb_buf_len = VappGalleryVideoInfoCacheItem::bufSize;
            WCHAR *file_name = (WCHAR*)path.getBuf();
            m_videoDB->setItemInfoBlocking(file_name, &input);
        }
    }while(0);


    if(m_videoInfoCache)
    {
        // unlock the cache item.
        // it is locked when triggering decoder
        m_videoInfoCache->unlockCache(itemId);
    }
    m_parsing = VFX_FALSE;
    m_signalDecode.emit(m_parsingIndex, result);
    VFX_OBJ_CLOSE(m_videoDecoder);
    return;
}
#endif /* __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__ */

/*****************************************************************************
 * Implementation of VappGalleryMediaCacheFileSequence
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
VappGalleryMediaCacheFileSequence::VappGalleryMediaCacheFileSequence():
    m_mediaList(NULL),
    m_bitset(NULL)
{

}

void VappGalleryMediaCacheFileSequence::config(IVappGalleryMediaList *mediaList, const SimpleBitSet *selectionSet)
{
    m_mediaList = mediaList;
    m_bitset = selectionSet;
}

void VappGalleryMediaCacheFileSequence::start()
{
    // start resets the internal index
    m_fileSequenceIndex = VcpMenuPos(0, 0);
    m_fileSequenceCount = 0;
    m_fileSequenceEnded = VFX_FALSE;
    const VfxU32 groupCount = m_mediaList->getGroupCount();
    ASSERT(groupCount <= SimpleBitSet::MAX_GROUP_COUNT);
    for(VfxU32 g = 0; g < groupCount; ++g)
    {
        for(int i = 0; i < m_mediaList->getMediaCountInGroup(g); ++i)
        {
            if(m_bitset->isSet(VcpMenuPos(g, i)))
            {
                ++m_fileSequenceCount;
            }
        }
    }
    return;
}

VfxU32 VappGalleryMediaCacheFileSequence::getTotalCount()
{
    return m_fileSequenceCount;
}

VfxBool VappGalleryMediaCacheFileSequence::getCountByType(VfxU32 &imageCount, VfxU32 &videoCount)
{
    imageCount = 0;
    videoCount = 0;

    const VfxU32 groupCount = m_mediaList->getGroupCount();
    ASSERT(groupCount <= SimpleBitSet::MAX_GROUP_COUNT);
    for(VfxU32 g = 0; g < groupCount; ++g)
    {
        for(int i = 0; i < m_mediaList->getMediaCountInGroup(g); ++i)
        {
            if(m_bitset->isSet(VcpMenuPos(g, i)))
            {
                // TODO: collect file types
                if(MEDIA_GROUP_IMAGE == m_mediaList->getMediaGroupType(VcpMenuPos(g, i)))
                {
                    ++imageCount;
                }
                else
                {
                    ++videoCount;
                }
            }
        }
    }
    return VFX_TRUE;
}

VfxBool VappGalleryMediaCacheFileSequence::hasNextPath()
{
    if(m_fileSequenceEnded)
    {
        return VFX_FALSE;
    }

    // search next path, starting from last found index
    const VfxU32 groupCount = m_mediaList->getGroupCount();
    for(VcpMenuPos p = m_fileSequenceIndex; p.group < groupCount; ++p.group)
    {
        const VfxU32 itemCount = m_mediaList->getMediaCountInGroup(p.group);
        for(; p.pos < itemCount; ++p.pos)
        {
            if(m_bitset->isSet(p))
            {
                return VFX_TRUE;
            }
        }

        // advance to next group,
        // so we reset pos
        p.pos = 0;
    }

    // no next selected path, raise end flag
    m_fileSequenceEnded = VFX_TRUE;
    return VFX_FALSE;
}

VfxBool VappGalleryMediaCacheFileSequence::getNextPath(VfxWString &filePath)
{
    const VfxU32 groupCount = m_mediaList->getGroupCount();
    for(; m_fileSequenceIndex.group < groupCount; ++m_fileSequenceIndex.group)
    {
        const VfxS32 itemCount = m_mediaList->getMediaCountInGroup(m_fileSequenceIndex.group);
        for(; m_fileSequenceIndex.pos < itemCount; ++m_fileSequenceIndex.pos)
        {
            if(m_bitset->isSet(m_fileSequenceIndex))
            {
                m_mediaList->getMediaPath(m_fileSequenceIndex, filePath);
                ++m_fileSequenceIndex.pos;
                if(m_fileSequenceIndex.pos >= itemCount)
                {
                    m_fileSequenceIndex.group += 1;
                    m_fileSequenceIndex.pos = 0;
                }
                return VFX_TRUE;
            }
        }
        // advance to next group,
        // so we reset pos
        m_fileSequenceIndex.pos = 0;
    }
    m_fileSequenceEnded = VFX_TRUE;
    return VFX_FALSE;
}
#endif
/*****************************************************************************
 * Implementation of VappGalleryFmgrDefaultFolder
 *****************************************************************************/
void VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(U8 drv, DEFAULT_FOLDER_TYPE type, VfxWString &path)
{
    VfxWChar* pathBuf = path.lockBuf(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    // start from drive path
    S32 ret = srv_fmgr_drv_get_type(drv);
	if(ret < 0)
    {
        path.setEmpty();
        return;
    }
    const srv_fmgr_drv_type_enum drvType = (srv_fmgr_drv_type_enum)ret;    
    mmi_wcsncpy(pathBuf, srv_fmgr_drv_get_path_by_type(drvType), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    // append proper folder names, with tail slash
    WCHAR *folderName = NULL;
    switch(type)
    {
    case MY_SHOOTING:
        folderName = (WCHAR*)SHOOTING_DOWNLOAD_FOLDER_NAME;
        break;
    case MY_VIDEO:
        folderName = (WCHAR*)VIDEO_DOWNLOAD_FOLDER_NAME;
        break;
    case MY_PICTURE:
        folderName = (WCHAR*)IMAGE_DOWNLOAD_FOLDER_NAME;
        break;
    case MY_RECEIVED:
        folderName = (WCHAR*)RECEIVED_DOWNLOAD_FOLDER_NAME;
        break;
    default:
        folderName = (WCHAR*)VIDEO_DOWNLOAD_FOLDER_NAME;
        break;
    }
    srv_fmgr_path_append_ex(pathBuf, SRV_FMGR_PATH_MAX_FILE_NAME_LEN, folderName, MMI_TRUE);
    path.unlockBuf();
    return;
}

/*****************************************************************************
 * Implementation of VappGalleryFmgrList
 *****************************************************************************/
VappGalleryFmgrList::VappGalleryFmgrList():
    m_prepared(VFX_FALSE)
    ,m_isReloading(VFX_FALSE)
    ,m_pFileListHeap(NULL)
    ,m_refreshedListIndex(-1)
    ,m_sortMethod(FS_SORT_NAME)
    ,m_loadingJob(NULL)
{
    for(int i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        m_fileLists[i] = NULL;
        m_isFolderExist[i] = VFX_FALSE;
    }

    m_searchIndex.invalid();

    FMGR_FILTER_INIT(&m_limitFilter);
    FMGR_FILTER_SET_ALL(&m_limitFilter);
}

void VappGalleryFmgrList::onInit()
{
    VfxObject::onInit();
}

void VappGalleryFmgrList::onDeinit()
{
    releaseAllFileList();
    VfxObject::onDeinit();
}

void VappGalleryFmgrList::releaseAllFileList()
{
    closeLoadingJob(__LINE__);

    for(VfxS32 i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        if(m_fileLists[i])
        {
            srv_fmgr_filelist_abort(m_fileLists[i]);
            srv_fmgr_filelist_destroy(m_fileLists[i]);
            m_fileLists[i] = NULL;
        }
    }
    if(m_pFileListHeap)
    {
        if(isUnderPickerCUI())
        {
            mmi_id appId = findRootAppId(this);
            applib_asm_free_r(appId, m_pFileListHeap);
        }
        else
        {
            VFX_FREE_MEM(m_pFileListHeap);
        }

        m_pFileListHeap = NULL;
    }
}

VfxBool VappGalleryFmgrList::config(
    U8 drv,
    IVappGalleryMediaList::ListEvent *pReadySignal,
    IVappGalleryMediaList::ListReloadEvent *pReloadStartSignal,
    IVappGalleryMediaList::ListReloadEvent *pReloadFinishedSignal)
{
    m_pSignalReady = pReadySignal;
    m_pSignalReloadStart = pReloadStartSignal;
    m_pSignalReloadFinished = pReloadFinishedSignal;

    if(MMI_FALSE == srv_fmgr_drv_is_valid(drv))
    {
        return VFX_FALSE;
    }

    // find proper folder path on the drive
    VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                        drv,
                                        VappGalleryFmgrDefaultFolder::MY_VIDEO,
                                        m_folderPaths[0]);
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_FOLDER__
    VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                        drv,
                                        VappGalleryFmgrDefaultFolder::MY_RECEIVED,
                                        m_folderPaths[1]);
#endif
    return VFX_TRUE;
}

VfxBool VappGalleryFmgrList::configFileTypeLimit(const FMGR_FILTER *filter)
{
    if(NULL == filter)
        return VFX_FALSE;

    m_limitFilter = *filter;

    return VFX_TRUE;
}

void VappGalleryFmgrList::configSortMethod(VfxU32 sortMethod)
{
    m_sortMethod = sortMethod;
}

void VappGalleryFmgrList::configSearchFileDuringPrepare(const VfxWString &namePattern)
{
    m_patternToSearch = namePattern;
}

VfxBool VappGalleryFmgrList::getFoundFileIndex(VcpMenuPos &foundIndex)
{
    if(!m_searchIndex.isValid())
        return VFX_FALSE;

    foundIndex = m_searchIndex;
    return VFX_TRUE;
}

void VappGalleryFmgrList::setFilter(FMGR_FILTER &filter)
{
    // only scan video
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_VIDEO(&filter);
}

void VappGalleryFmgrList::refresh()
{
    // currently, we re-prepare the lists
    // since folders may be created before refresh().
    prepare();
}

void VappGalleryFmgrList::prepare()
{
    VfxS32 listCount = 0;
    for(int i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        if(!m_folderPaths[i].isNull())
        {
            ++listCount;
        }
    }

    // check if there is re-initialization
    if(m_pFileListHeap)
    {
        releaseAllFileList();
    }

    // check memory required by lists
    const VfxU32 singleListMemReq = SRV_FMGR_FOLDER_FILELIST_MEM_SIZE;
    const VfxU32 totalMemReq = vfxMin(listCount, (VfxS32)MAX_FOLDER_COUNT) * singleListMemReq;
    if(totalMemReq)
    {
        VFX_ASSERT(NULL == m_pFileListHeap);

        // for image picker and video picker CUIs
        // allocate in FG memory.
        // Other cases, use Heap memory.
        if(isUnderPickerCUI())
        {
            mmi_id appId = findRootAppId(this);
            m_pFileListHeap = (VfxU8*)applib_asm_alloc_nc_r(appId, totalMemReq);
        }
        else
        {
            VFX_ALLOC_MEM(m_pFileListHeap, totalMemReq, this);
        }
    }
    else
    {
        m_pFileListHeap = NULL;
    }

    FMGR_FILTER filter;

    // allow derived class to define default set
    setFilter(filter);

    // intersect default set with user-specified set
    intersectFilter(filter, m_limitFilter);

    // create all file lists.
    for(int i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        if(m_folderPaths[i].isNull())
        {
            srv_fmgr_empty_filelist_create(&m_fileLists[i]);
        }
        else
        {
            VFX_ASSERT(m_pFileListHeap);
            S32 res = srv_fmgr_folder_filelist_create(
                                        (const WCHAR*)m_folderPaths[i],
                                        &filter,
                                        m_sortMethod,
                                        m_pFileListHeap + singleListMemReq * i,
                                        singleListMemReq,
                                        &m_fileLists[i]);
            // if failed, use dummy file list instead
            if(0 != res)
            {
                srv_fmgr_empty_filelist_create(&m_fileLists[i]);
            }
        }
        VFX_ASSERT(NULL != m_fileLists[i]);
    }

    // scan files to populate list
    refreshAllFileList();
}

VfxBool VappGalleryFmgrList::isPrepared() const
{
    return m_prepared;
}

VfxBool VappGalleryFmgrList::isReloading() const
{
    return m_isReloading;
}

VfxBool VappGalleryFmgrList::isDirty()
{
    for(VfxS32 i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        if(m_fileLists[i])
        {
            // note file survice will return dirty if it does not ensure not dirty
            // [MAUI_02947651] hence we need to consider the scenario that
            // folder dose not exist at the beginning
            if((MMI_TRUE == srv_fmgr_filelist_is_dirty(m_fileLists[i])) &&
               ((0 <= srv_fmgr_fs_path_exist((const WCHAR*)m_folderPaths[i])) || (m_isFolderExist[i])))
            {
                return VFX_TRUE;
            }
        }
    }
    return VFX_FALSE;
}

void VappGalleryFmgrList::intersectFilter(FMGR_FILTER &dst, const FMGR_FILTER &src)
{
    return _intersectFilter(dst, src);
}

void VappGalleryFmgrList::stop()
{
    closeLoadingJob(__LINE__);

    for(int i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        if(NULL != m_fileLists[i])
        {
            srv_fmgr_filelist_abort(m_fileLists[i]);
        }
    }
}

void VappGalleryFmgrList::refreshAllFileList()
{
    // reset loading job
    closeLoadingJob(__LINE__);

    // only 1 list can be refresh at a time.
    // so we must refresh them sequentially.
    m_refreshedListIndex = -1;
    m_prepared = VFX_FALSE;

    if(!refreshNextFileList())
    {
        // fails directly.
        m_prepared = VFX_TRUE;
        // notify client about underlying changes, without initializing MediaCache.
        if(m_pSignalReady)
        {
            m_pSignalReady->postEmit(PREPARE_OK);
        }
    }
}

VfxU32 VappGalleryFmgrList::getFileCount(VfxS32 listIndex)
{
    if(!m_prepared)
        return 0;

    if(listIndex >= MAX_FOLDER_COUNT)
        return 0;

    if(NULL == m_fileLists[listIndex])
        return 0;

    return vfxMin((VfxU32)MAX_FILE_COUNT, (VfxU32)srv_fmgr_filelist_count(m_fileLists[listIndex]));
}

VfxU32 VappGalleryFmgrList::getTotalFileCount()
{
    if(!m_prepared)
    {
        return 0;
    }

    VfxU32 totalCount = 0;
    for(VfxS32 i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        if(NULL == m_fileLists[i])
        {
            continue;
        }
        totalCount += vfxMin((VfxU32)srv_fmgr_filelist_count(m_fileLists[i]),
                             (VfxU32)MAX_FILE_COUNT);
    }
    return totalCount;
}

VappGalleryDecodeResult VappGalleryFmgrList::getFileName(const VcpMenuPos &index, VfxWString &nameStr)
{
    return getFilePathImpl(index, nameStr, VFX_FALSE);
}

VappGalleryDecodeResult VappGalleryFmgrList::getPathName(const VcpMenuPos &index, VfxWString &pathStr)
{
    return getFilePathImpl(index, pathStr, VFX_TRUE);
}

VappGalleryDecodeResult VappGalleryFmgrList::getFilePathImpl(
    const VcpMenuPos &index,
    VfxWString &pathStr,
    const VfxBool queryPath)
{
    if(index.group < 0 || index.group >= MAX_FOLDER_COUNT)
    {
        return UNEXPECTED;
    }
    if(NULL == m_fileLists[index.group])
    {
        return UNEXPECTED;
    }

    // query file path/name
    S32 result = 0;
    if(queryPath)
    {
        // query file path
        const VfxU32 pathLen = SRV_FMGR_PATH_MAX_LEN + 1;
        VfxWChar* strBuf = pathStr.lockBuf(pathLen);
        result = srv_fmgr_filelist_get_filepath(
                            m_fileLists[index.group],
                            index.pos,
                            strBuf,
                            sizeof(VfxWChar) * pathLen);
        pathStr.unlockBuf();
    }
    else
    {
        // query file name
        const VfxU32 nameLen = SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1;
        VfxWChar* strBuf = pathStr.lockBuf(nameLen);
        result = srv_fmgr_filelist_get_filename(
                                    m_fileLists[index.group],
                                    index.pos,
                                    strBuf,
                                    sizeof(VfxWChar) * nameLen);
        pathStr.unlockBuf();
    }

#ifdef __VAPP_GALLERY_ENABLE_FS_RELOAD__
    if((SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY == result) &&
       (SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND   == srv_fmgr_filelist_get_capability(m_fileLists[index.group])))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_GET_FILE_PATH_IMPL, index.group, index.pos);
        reload(index);
    }
#endif
    if(0 != result)
    {
        pathStr.setEmpty();
        return convertFMgrError(result);
    }
    else
    {
        return OK;
    }
}

VfxBool VappGalleryFmgrList::reload(const VcpMenuPos &index)
{
    if(!index.isValid())
    {
        return VFX_FALSE;
    }

    if(m_loadingJob.isValid())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_RELOAD, index.group, index.pos, m_loadingJob.get()->m_itemIndex.group, m_loadingJob.get()->m_itemIndex.pos, VAPP_GALLERY_INTERNAL_UNUSED_PARAM);
        return VFX_FALSE;
    }

    // check file list state
    switch (srv_fmgr_filelist_get_state(m_fileLists[index.group]))
    {
    case SRV_FMGR_FILELIST_STATE_READY:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_RELOAD, index.group, index.pos, -1, -1, 0);
        break;
    case SRV_FMGR_FILELIST_STATE_LOADING:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_RELOAD, index.group, index.pos, -1, -1, -100);
        return VFX_FALSE;
    case SRV_FMGR_FILELIST_STATE_INIT:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_RELOAD, index.group, index.pos, -1, -1, -200);
        return VFX_FALSE;
    case SRV_FMGR_FILELIST_STATE_REFRESHING:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_RELOAD, index.group, index.pos, -1, -1, -300);
        return VFX_FALSE;
    default:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_RELOAD, index.group, index.pos, -1, -1, -400);
        return VFX_FALSE;
    }

    // reset loading job
    closeLoadingJob(__LINE__);
    DecodeJob *pJob = NULL;
    VFX_OBJ_CREATE(pJob, DecodeJob, this);
    pJob->m_itemIndex = index;
    pJob->m_pList     = NULL;
    m_loadingJob      = pJob;

    m_isReloading = VFX_TRUE;

    // only re-load when state is ready
    S32 loadRes = srv_fmgr_filelist_load_file(
                    m_fileLists[index.group],
                    index.pos,
                    onFileMgrEvent,
                    getObjHandle());

    notifyReloadStartEvent(index, __LINE__);
    return VFX_TRUE;
}

SRV_FMGR_FILELIST_HANDLE VappGalleryFmgrList::getFileList(const VfxS32 index)
{
    if(index < 0 || index >= MAX_FOLDER_COUNT)
    {
        return NULL;
    }
    return m_fileLists[index];
}

S32 VappGalleryFmgrList::getFileListCapability(const VfxS32 index)
{
    SRV_FMGR_FILELIST_HANDLE handle = getFileList(index);
    if(handle)
    {
        S32 capability = srv_fmgr_filelist_get_capability(handle);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_GET_CAPABILITY, index, capability);
        return capability;
    }
    return SRV_FMGR_FILELIST_CAP_END;
}

VfxBool VappGalleryFmgrList::refreshNextFileList()
{
    const VfxS32 nextFileListIndex = m_refreshedListIndex + 1;
    if(nextFileListIndex < 0 || nextFileListIndex >= MAX_FOLDER_COUNT)
    {
        return VFX_FALSE;
    }

    if(NULL == m_fileLists[nextFileListIndex])
    {
        return VFX_FALSE;
    }

    const WCHAR *searchPattern = NULL;
    if(!m_patternToSearch.isNull() &&
       !m_patternToSearch.isEmpty())
    {
        searchPattern = m_patternToSearch.getBuf();
    }

    // check folder exist or not
    if(0 > srv_fmgr_fs_path_exist((const WCHAR*)m_folderPaths[nextFileListIndex]))
    {
        m_isFolderExist[nextFileListIndex] = VFX_FALSE;
    }
    else
    {
        m_isFolderExist[nextFileListIndex] = VFX_TRUE;
    }

    S32 res = srv_fmgr_filelist_refresh(
                            m_fileLists[nextFileListIndex],
                            searchPattern,  // apply search pattern if any
                            0,              // always start from 1st file
                            SRV_FMGR_FILELIST_REFRESH_PROGRESS_OFF,  // no need to receive progress
                            onFileMgrEvent,
                            getObjHandle());
    if(0 != res)
    {
        if(m_fileLists[nextFileListIndex] && MMI_FALSE == srv_fmgr_filelist_is_empty(m_fileLists[nextFileListIndex]))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_MLV_INFO_SRV_FMGR_FILELIST_REFRESH_FAILED, res);
        }
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

mmi_ret VappGalleryFmgrList::handleFileMgrRefreshResult(srv_fmgr_filelist_refresh_result_event_struct* refreshEvent)
{
    // mark current file list as finished
    m_refreshedListIndex += 1;

    // store found index, if found.
    if(refreshEvent->search_index >= 0)
    {
        m_searchIndex.group = m_refreshedListIndex;
        m_searchIndex.pos = refreshEvent->search_index;
    }
    else
    {
        m_searchIndex.invalid();
    }

    if(!refreshNextFileList())
    {
        m_prepared = VFX_TRUE;
        // notify client about underlying changes, without initializing MediaCache.
        if(m_pSignalReady)
        {
            m_pSignalReady->postEmit(PREPARE_OK);
        }
    }
    return MMI_RET_OK;
}

mmi_ret VappGalleryFmgrList::handleFileMgrLoadResult(srv_fmgr_filelist_load_result_event_struct* reloadEvent)
{
    if(!m_loadingJob.isValid())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_HANDLE_FILE_MGR_LOAD_RESULT, VAPP_GALLERY_INTERNAL_UNUSED_PARAM, VAPP_GALLERY_INTERNAL_UNUSED_PARAM, -1);
        return MMI_RET_OK;
    }

    m_isReloading = VFX_FALSE;
    VcpMenuPos mediaPos = m_loadingJob.get()->m_itemIndex;
    notifyReloadFinishedEvent(mediaPos, __LINE__);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_HANDLE_FILE_MGR_LOAD_RESULT, mediaPos.group, mediaPos.pos, 0);

    closeLoadingJob(__LINE__);
    return MMI_RET_OK;
}

mmi_ret VappGalleryFmgrList::onFileMgrEvent(mmi_event_struct *param)
{
    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    VappGalleryFmgrList *pThis = (VappGalleryFmgrList*)handleToObject((VfxObjHandle)param->user_data);
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
            if(param->size != sizeof(srv_fmgr_filelist_refresh_result_event_struct))
            {
                return MMI_RET_OK;
            }
            srv_fmgr_filelist_refresh_result_event_struct *refreshEvent = (srv_fmgr_filelist_refresh_result_event_struct*)param;
            return pThis->handleFileMgrRefreshResult(refreshEvent);
        }

        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
        {
            if(param->size != sizeof(srv_fmgr_filelist_load_result_event_struct))
            {
                return MMI_RET_OK;
            }
            srv_fmgr_filelist_load_result_event_struct *reload_evt = (srv_fmgr_filelist_load_result_event_struct*)param;
            return pThis->handleFileMgrLoadResult(reload_evt);
        }
    }
    return MMI_RET_OK;
}

VappGalleryDecodeResult VappGalleryFmgrList::convertFMgrError(S32 fmgrResult)
{
    switch(fmgrResult)
    {
    case FS_PATH_OVER_LEN_ERROR:
        return PATH_TOO_DEEP;
    case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
    case SRV_FMGR_FILELIST_ERROR_BUSY:
        return DECODING;
    default:
        return FORMAT_UNSUPPORTED;
    }
}

VfxBool VappGalleryFmgrList::isUnderPickerCUI()
{
    VfxBool isUnderPickerCUI = VFX_FALSE;
    for(VfxObject *pObj = this; pObj != NULL; pObj = pObj->getParent())
    {
        VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(pObj, VcuiGalleryPickerBase);
        if(pickerCUI != NULL)
        {
            isUnderPickerCUI = VFX_TRUE;
            break;
        }
    }
    return isUnderPickerCUI;
}

void VappGalleryFmgrList::closeLoadingJob(const VfxU32 line)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_CLOSE_LODAING_JOB, line);
    VFX_OBJ_CLOSE(m_loadingJob);
    m_loadingJob = NULL;
}

void VappGalleryFmgrList::notifyReloadStartEvent(const VcpMenuPos &index, const VfxU32 line)
{
    if(m_pSignalReloadStart)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_NOTIFY_RELOAD_START_EVT, line);
        m_pSignalReloadStart->postEmit(index);
    }
}

void VappGalleryFmgrList::notifyReloadFinishedEvent(const VcpMenuPos &index, const VfxU32 line)
{
    if(m_pSignalReloadFinished)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FMGR_LIST_NOTIFY_RELOAD_FINISHED_EVT, line);
        m_pSignalReloadFinished->postEmit(index);
    }
}

/*****************************************************************************
 * Implementation of VappGalleryFmgrFolderList
 *****************************************************************************/
VappGalleryFmgrFolderList::VappGalleryFmgrFolderList():
    m_driveLetter(0)
{
}

void VappGalleryFmgrFolderList::setFilter(FMGR_FILTER &filter)
{
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
}

VfxBool VappGalleryFmgrFolderList::config(
    U8 driveLetter,  // [IN] drive to be scanned for file lists
    IVappGalleryMediaList::ListEvent *pReadySignal,  // [IN] signal to be emitted when all lists are ready to use
    IVappGalleryMediaList::ListReloadEvent *pReloadStartSignal,
    IVappGalleryMediaList::ListReloadEvent *pReloadFinishedSignal)
{
    m_driveLetter= driveLetter;
    m_pSignalReady = pReadySignal;
    m_pSignalReloadStart = pReloadStartSignal;
    m_pSignalReloadFinished = pReloadFinishedSignal;

    if(MMI_FALSE == srv_fmgr_drv_is_valid(driveLetter))
    {
        return VFX_FALSE;
    }

    // find proper folder path on the drive
    for(int i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        m_folderPaths[i].setNull();
    }

    // only setup 1st folder
    VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                        driveLetter,
                                        VappGalleryFmgrDefaultFolder::MY_PICTURE,
                                        m_folderPaths[0]);
    return VFX_TRUE;
}


VfxU32 VappGalleryFmgrFolderList::getTotalFileCount()
{
    // append "Received" folder
    return VappGalleryFmgrList::getTotalFileCount() + 1;
}

VfxU32 VappGalleryFmgrFolderList::getFileCount(VfxS32 listIndex)
{
    if(0 == listIndex)
    {
        // append "Received" folder
        return VappGalleryFmgrList::getFileCount(listIndex) + 1;
    }
    else
    {
        return VappGalleryFmgrList::getFileCount(listIndex);
    }
}

VappGalleryDecodeResult VappGalleryFmgrFolderList::getFileName(const VcpMenuPos &index, VfxWString &nameStr)
{
    const VcpMenuPos posReceived = getMyRecievedFolderIndex();
    const VfxS32     fixedOffset = getGroupIndexFixedOffset();

    // check if it queries MY Received folder
    if(posReceived == index)
    {
        nameStr = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYRECEIVED);
        return OK;
    }

    // if not, fix query index and start query
    VcpMenuPos fixedIndex;
    fixedIndex.group = index.group;
    fixedIndex.pos = index.pos;
    if(0 == fixedIndex.group)
    {
        fixedIndex.pos -= fixedOffset;
    }

    return VappGalleryFmgrList::getFileName(fixedIndex, nameStr);
}

VappGalleryDecodeResult VappGalleryFmgrFolderList::getPathName(const VcpMenuPos &index, VfxWString &pathStr)
{
    const VcpMenuPos posReceived = getMyRecievedFolderIndex();
    const VfxS32     fixedOffset = getGroupIndexFixedOffset();

    // check if it queries MY Received folder
    if(posReceived == index)
    {
        VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                        m_driveLetter,
                                        VappGalleryFmgrDefaultFolder::MY_RECEIVED,
                                        pathStr);
        return OK;
    }

    // if not, fix query index and start query
    VcpMenuPos fixedIndex;
    fixedIndex.group = index.group;
    fixedIndex.pos = index.pos;
    if(0 == fixedIndex.group)
    {
        fixedIndex.pos -= fixedOffset;
    }
    return VappGalleryFmgrList::getPathName(fixedIndex, pathStr);
}

// return index of "My Recieved" folder
VcpMenuPos VappGalleryFmgrFolderList::getMyRecievedFolderIndex()
{
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_AS_THE_FIRST_FOLDER__
    // first entry is always "Received" folder
    return VcpMenuPos(0, 0);
#else
    // last entry is always "Received" folder
    // group index is 0
    // pos is (total_folder_count - 1, 0) because index starts from 0
    const VfxS32 folderCount = getTotalFileCount();
    return VcpMenuPos(0, folderCount - 1);
#endif
}

// get fixed index offset
VfxS32 VappGalleryFmgrFolderList::getGroupIndexFixedOffset()
{
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_AS_THE_FIRST_FOLDER__
    return 1;
#else
    // last entry is always "Received" folder
    return 0;
#endif
}

/*****************************************************************************
 * Implementation of VappGalleryFmgrImageList
 *****************************************************************************/
void VappGalleryFmgrImageList::setFilter(FMGR_FILTER &filter)
{
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);

    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_FOLDER);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif
}

VfxBool VappGalleryFmgrImageList::configFolder(
    const VfxWString &folderPath,
    IVappGalleryMediaList::ListEvent *pReadySignal,
    IVappGalleryMediaList::ListReloadEvent *pReloadStartSignal,
    IVappGalleryMediaList::ListReloadEvent *pReloadFinishedSignal)
{
    m_pSignalReady = pReadySignal;
    m_pSignalReloadStart = pReloadStartSignal;
    m_pSignalReloadFinished = pReloadFinishedSignal;

    // find proper folder path on the drive
    for(int i = 0; i < MAX_FOLDER_COUNT; ++i)
    {
        m_folderPaths[i].setNull();
    }

    m_folderPaths[0] = folderPath;
    return VFX_TRUE;
}

/*****************************************************************************
 * Implementation of VappGalleryFmgrImageVideoList
 *****************************************************************************/
void VappGalleryFmgrImageVideoList::setFilter(FMGR_FILTER &filter)
{
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_SET_VIDEO(&filter);

    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_FOLDER);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif
}

/*****************************************************************************
 * Implementation of VappGalleryFolderInfoCacheItem
 *****************************************************************************/

void VappGalleryFolderInfoCacheItem::clear()
{
    m_fileCount = 0;
    m_thumbCount = 0;
}

// total file count in the folder
void VappGalleryFolderInfoCacheItem::setFileCount(VfxS32 fileCount)
{
    m_fileCount = fileCount;
}

// thumbnail buffer count that can be filled by decoder
VfxS32 VappGalleryFolderInfoCacheItem::getMaxThumbCount()
{
    return MAX_THUMB_COUNT;
}

// successfully decoded thumbnail count
void VappGalleryFolderInfoCacheItem::setDecodedThumbCount(VfxS32 thumbCount)
{
    m_thumbCount = thumbCount;
}

GDI_HANDLE VappGalleryFolderInfoCacheItem::getLayer(VfxS32 thumbIndex) const
{
    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
    res = gdi_layer_create_cf_using_outside_memory(GALLERY_GDI_CF_THUMB,
                                                   0, 0,
                                                   thumb_w,
                                                   thumb_h,
                                                   &thumbLayer,
                                                   getThumbBufferPtr(thumbIndex),
                                                   BUF_SIZE_PER_THUMB);
    VFX_ASSERT(GDI_SUCCEED == res);
    return thumbLayer;
}

VfxImageBuffer VappGalleryFolderInfoCacheItem::getImageBuffer(VfxS32 thumbIndex) const
{
    VfxImageBuffer thumbBuf;
    if(thumbIndex < 0 || thumbIndex >= MAX_THUMB_COUNT)
    {
        // input parameter out-of-bound
        VFX_ASSERT(0);
        thumbBuf.width = 0;
        thumbBuf.height = 0;
        thumbBuf.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
        thumbBuf.pitchBytes = 0;
        thumbBuf.ptr = NULL;
        return thumbBuf;
    }

    thumbBuf.width = thumb_w;
    thumbBuf.height = thumb_h;
    thumbBuf.colorFormat = GALLERY_VRT_CF_THUMB;
    thumbBuf.pitchBytes = thumb_w * VAPP_GALLERY_THUMB_BPP;
    thumbBuf.ptr = const_cast<VfxU8*>(getThumbBufferPtr(thumbIndex));
    return thumbBuf;
}

U8* VappGalleryFolderInfoCacheItem::getThumbBufferPtr(VfxS32 thumbIndex) const
{
    if(thumbIndex < 0 || thumbIndex >= MAX_THUMB_COUNT)
    {
        VFX_ASSERT(0);
        return NULL;
    }
    return ((VfxU8*)m_thumbBuffer) + BUF_SIZE_PER_THUMB * thumbIndex;
}

/*****************************************************************************
 * Implementation of VappGalleryMyPictureFolderThumbnailOutput
 *****************************************************************************/
VappGalleryMyPictureFolderThumbnailOutput::VappGalleryMyPictureFolderThumbnailOutput():
    m_pCacheItem(NULL)
{
}

void VappGalleryMyPictureFolderThumbnailOutput::config(VappGalleryFolderInfoCacheItem *pCacheItem)
{
    m_pCacheItem = pCacheItem;
}

void VappGalleryMyPictureFolderThumbnailOutput::setFileCount(VfxS32 fileCount)
{
    VFX_ASSERT(m_pCacheItem);
    return m_pCacheItem->setFileCount(fileCount);
}

VfxS32 VappGalleryMyPictureFolderThumbnailOutput::getMaxThumbCount()
{
    VFX_ASSERT(m_pCacheItem);

    return m_pCacheItem->getMaxThumbCount();
}

void VappGalleryMyPictureFolderThumbnailOutput::setDecodedThumbCount(VfxS32 thumbCount)
{
    VFX_ASSERT(m_pCacheItem);
    return m_pCacheItem->setDecodedThumbCount(thumbCount);
}

VfxImageBuffer VappGalleryMyPictureFolderThumbnailOutput::getImageBuffer(VfxS32 thumbIndex) const
{
    VFX_ASSERT(m_pCacheItem);
    return m_pCacheItem->getImageBuffer(thumbIndex);

}

#ifdef __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__
/*****************************************************************************
 * Implementation of VappGalleryFolderThumbnailDecoder
 *****************************************************************************/
VappGalleryFolderThumbnailDecoder::VappGalleryFolderThumbnailDecoder():
    m_decodeResizeWokingBuf(NULL), 
    m_pDB(NULL),
    m_fileList(NULL),
    m_outputItem(NULL),
    m_thumbDecoder(NULL),
    m_totalFileInFolder(0),
    m_decodedFileCount(0),
    m_nextFileIndex(0)
{
}

void VappGalleryFolderThumbnailDecoder::onInit()
{
    VfxObject::onInit();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_ON_INIT);
    m_thumbDecoder = NULL;
}

void VappGalleryFolderThumbnailDecoder::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_ON_DEINIT);
    // make sure we cancelled all decoding
    cancel();
    VfxObject::onDeinit();
}

VappGalleryFolderThumbnailDecoder::DecodeSignal* VappGalleryFolderThumbnailDecoder::getDecodeSignal()
{
    return &m_decodeSignal;
}

void VappGalleryFolderThumbnailDecoder::config(
            VappGalleryFolderThumbnailDecoderOutputBase *outputItem,
            VappGalleryFmgrList *fileList,
            VappGalleryDB *pDB,
            U8* resizeWorkingBuf)
{
    VFX_ASSERT(outputItem);
    VFX_ASSERT(fileList);

    m_outputItem = outputItem;
    m_fileList = fileList;
    m_pDB = pDB; 
    m_decodeResizeWokingBuf = resizeWorkingBuf;

    m_nextFileIndex = 0;
    return;
}

VfxBool VappGalleryFolderThumbnailDecoder::start()
{
    if(!startDecodeNextFile())
    {
        // no file to decode
        if(m_outputItem)
        {
            m_outputItem->setFileCount(m_fileList ? m_fileList->getTotalFileCount() : 0);
            m_outputItem->setDecodedThumbCount(0);
        }

        m_decodeSignal.postEmit(this, OK);
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VappGalleryFolderThumbnailDecoder::needDecodeMoreFile()
{
    if(NULL == m_outputItem || NULL == m_fileList)
        return VFX_FALSE;

    if(m_decodedFileCount >= m_outputItem->getMaxThumbCount())
        return VFX_FALSE;

    if(m_nextFileIndex >= m_fileList->getTotalFileCount())
        return VFX_FALSE;

    if(m_nextFileIndex >= MAX_TRY_DECODE_FILE_COUNT)
        return VFX_FALSE;

    return VFX_TRUE;
}

VfxBool VappGalleryFolderThumbnailDecoder::startDecodeNextFile()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_START_DECODE_NEXT_FILE);
    VFX_ASSERT(m_outputItem);
    VFX_ASSERT(m_fileList);

    if(!needDecodeMoreFile())
        return VFX_FALSE;

    // retrieve next valid file path, or return when reach end of list
    VfxWString path;
    while(OK != m_fileList->getPathName(VcpMenuPos(0, m_nextFileIndex), path))
    {
        if(needDecodeMoreFile())
        {
            ++m_nextFileIndex;
        }
        else
        {
            return VFX_FALSE;
        }
    }

    VFX_ASSERT(NULL == m_thumbDecoder);

    // create decoder from path, check it is video or photo
    VfxBool isVideo = VFX_FALSE;
    do
    {
        S32 fileType = srv_fmgr_types_find_type_by_filepath((WCHAR*)path.getBuf());
        isVideo = (FMGR_GROUP_VIDEO == srv_fmgr_types_find_group_by_type((filetypes_file_type_enum)fileType));
    }while(0);

    if(isVideo)
    {
        // note that we want to reduce memory
        // used by underlying MDI service.
        VappGalleryVideoThumbnail *videoDecoder = NULL;
        VFX_OBJ_CREATE(videoDecoder, VappGalleryVideoThumbnail, this);
        videoDecoder->configLiteMemory(VFX_TRUE);
        m_thumbDecoder = videoDecoder;
    }
    else
    {
        VFX_OBJ_CREATE(m_thumbDecoder, VappGalleryImageThumbnail, this);
    }
    VfxImageBuffer buf = m_outputItem->getImageBuffer(m_decodedFileCount);

    // query DB to check if cahce exist
    if(m_pDB && m_decodeResizeWokingBuf)
    {
        VfxSize orginalDim (1, 1);
        m_thumbDecoder->getDimension(path, orginalDim);    
        if(getThumbIfCachePresent(path, buf, isVideo, orginalDim))
        {
            handleDecodeResult(m_thumbDecoder, OK);
            return VFX_TRUE;
        }
    }

    m_thumbDecoder->getReadySignal()->connect(this, &VappGalleryFolderThumbnailDecoder::handleDecodeResult);
    m_thumbDecoder->decode(path, buf);
    return VFX_TRUE;
}

VfxBool VappGalleryFolderThumbnailDecoder::getThumbIfCachePresent(
    const VfxWString &path, 
    VfxImageBuffer &thumbBuffer,
    const VfxBool isVideo, 
    VfxSize originalDim)
{
    if(NULL == m_pDB || NULL == m_decodeResizeWokingBuf)
        return VFX_FALSE;
    
    VFX_ASSERT(thumbBuffer.ptr);    

    const VfxS32 str_length = path.getLength();    
    // TODO: check string lengh?
    if(isVideo)
    {  
        ivd_db_video_result_info result;
        result.result_code = MMI_IVD_OK;
        result.duration_sec = 0;
        result.bookmark_sec = 0;
        result.thumb_buf_ptr = reinterpret_cast<VfxU8*>(thumbBuffer.ptr); //thumbBuffer.ptr;
        result.thumb_buf_len = thumbBuffer.width * VAPP_GALLERY_THUMB_BPP;
        result.thumb_width  = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W;
        result.thumb_height = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H;
        m_pDB->getItemInfoBlocking((WCHAR*)path.getBuf(), &result);
        if(result.result_code == MMI_IVD_OK)
        {
            // result is OK
            // NOTE: thumb buffer should already filled during query
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }
    else
    {    
        // ivd_ivsrv_db_get_img_blocking dose not support resize
        // so we use a temp buffer, m_decodeResizeWokingBuf, whose size is same as cached image size in DB, to DB query
        // and then resize temp buf content to thumbBuffer

        // file size is the size of original file
        // DB query check it to verify if the same file
        U32 file_size = 0;
        FS_HANDLE fs_hdle = FS_Open((WCHAR*)path.getBuf(), FS_READ_ONLY);
        FS_GetFileSize(fs_hdle, &file_size);
        FS_Close(fs_hdle);

        U32 buf_len = thumbBuffer.width * thumbBuffer.height * VAPP_GALLERY_THUMB_BPP;
        
        ivd_db_img_info_struct result;
        result.db_handle = m_pDB->getDBHnadle();
        result.path = (CHAR*)path.getBuf();     // not image path is case sensitive in IVD, but video deose not
        result.image_width  = VappGalleryMediaGridConstant::THUMB_WIDTH / 2 * 2; 
        result.image_height = VappGalleryMediaGridConstant::THUMB_HEIGHT / 2 * 2; 
        result.color_format = GALLERY_GDI_CF_THUMB;
        result.org_image_width  = originalDim.width;  // width of original image 
        result.org_image_height = originalDim.height; // height of original image 
        result.file_date = 0;
        result.file_time = 0;
        result.file_size = file_size;
        result.file_CRC = 0;
        result.with_meta = MMI_TRUE;

        S32 error_code = ivd_ivsrv_db_get_img_blocking(&result, m_decodeResizeWokingBuf, buf_len);
        
        if (0 == error_code && result.err_code == 0)
        {
            // DB query result is OK
            // resize temp buf to thumbnail size
            VfxImageBuffer srcBuf;
            srcBuf.width = (VappGalleryMediaGridConstant::THUMB_WIDTH / 2 * 2);
            srcBuf.height = (VappGalleryMediaGridConstant::THUMB_HEIGHT / 2 * 2);
            srcBuf.colorFormat = convertCF_GDI2VRT(GALLERY_GDI_CF_THUMB);
            srcBuf.pitchBytes = srcBuf.width * VAPP_GALLERY_THUMB_BPP; 
            srcBuf.ptr = m_decodeResizeWokingBuf;
            VfxRect dstRect(0, 0, thumbBuffer.width, thumbBuffer.height);
            VfxRect srcRect(0, 0, srcBuf.width, srcBuf.height);

            resizeImageBuf(
                thumbBuffer, 
                srcBuf, 
                dstRect, 
                srcRect, 
                VAPP_GALLERY_THUMB_BPP);
            return VFX_TRUE;
        }         
        return VFX_FALSE;
    }
}


static VfxBool g_resize_debug = VFX_FALSE; 
void VappGalleryFolderThumbnailDecoder::resizeImageBuf(
    VfxImageBuffer &dstBuffer,     
    VfxImageBuffer &srcBuffer,
    VfxRect &dstRect, 
    VfxRect &srcRect, 
    const VfxS32 bpp)
{ 
    gdi_lt_matrix_struct gdi_matrix;
    gdi_handle dstLayer = convertImageBufferToLayer(dstBuffer, VFX_FALSE);
    gdi_handle srcLayer = convertImageBufferToLayer(srcBuffer, VFX_FALSE);

    VfxMatrix3x3Ex m;
    VfxMatrix3x3Ex s;
    s.setScale(dstBuffer.width * 1.0f / srcBuffer.width, 
               dstBuffer.height * 1.0f / srcBuffer.height);
    m = s * m;
    m.transpose();
    kal_mem_cpy(&gdi_matrix.m[0], &m.m[0], sizeof(gdi_matrix.m));

    gdi_layer_push_and_set_active(dstLayer);
    gdi_lt_projective_transform_ext(
                    &gdi_matrix,
                    srcLayer,
                    0,
                    0,
                    srcBuffer.width,
                    srcBuffer.height,
                    0,
                    0,
                    dstBuffer.width,
                    dstBuffer.height,
                    GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
                    GDI_COLOR_TRANSPARENT,
                    GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
                    0);
    gdi_layer_pop_and_restore_active();

    if(g_resize_debug)
    {
        gdi_layer_save_bmp_file(srcLayer, (CHAR*)L"E:\\cache_src.bmp");
        gdi_layer_save_bmp_file(dstLayer, (CHAR*)L"E:\\cache_dst.bmp");
    }
    
    gdi_layer_free(srcLayer);     
    gdi_layer_free(dstLayer);
}

VfxBool VappGalleryFolderThumbnailDecoder::cancel()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_CANCEL);
    if(m_thumbDecoder)
    {
        VFX_OBJ_CLOSE(m_thumbDecoder);
        m_thumbDecoder = NULL;
    }
    return VFX_TRUE;
}

void VappGalleryFolderThumbnailDecoder::handleDecodeResult(VappGalleryDecoderBase* sender, VappGalleryDecodeResult result)
{
    if(OK == result)
    {
        ++m_decodedFileCount;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_THUMBNAIL_DECODE_FAILED);
    }

    // destroy decoder
    if(m_thumbDecoder)
    {
        VFX_ASSERT(m_thumbDecoder == sender);
        VFX_OBJ_CLOSE(m_thumbDecoder);
        m_thumbDecoder = NULL;
    }

    // decode next file no matter success or fail
    ++m_nextFileIndex;

    if(startDecodeNextFile())
    {
        // successfully start decoding next file
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_START_DECODE_FILE);
        return;
    }
    else
    {
        // finished, notify client that we're done.
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_FOLDER_THUMBNAIL_DECODER_ALL_THUMB_DECODE_FINISH);
        m_outputItem->setFileCount(m_fileList->getTotalFileCount());
        m_outputItem->setDecodedThumbCount(m_decodedFileCount);
        m_decodeSignal.postEmit(this, OK);
    }
    return;
}
#endif /* __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__ */

#endif
