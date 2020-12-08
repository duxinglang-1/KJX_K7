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
 *  vapp_gallery_data.h
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

#ifndef __VAPP_MEDIA_LIST_H__
#define __VAPP_MEDIA_LIST_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"

#ifdef __MMI_GALLERY_SLIM__

#ifdef __cplusplus
extern "C"
{
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "gdi_include.h"
#include "mdi_video.h"
#include "vcui_gallery_gprot.h"  
};
#endif

/***************************************************************************** 
 * Constants
 *****************************************************************************/

// Media Grid thumbnail size effects both MediaCache case and Wallpaper thumb,
// so we define it here. The UI layout should reference these constants.
class VappGalleryMediaGridConstant
{
public:
#if defined(__MMI_MAINLCD_320X480__)
    static const int THUMB_WIDTH = 79;
    static const int THUMB_HEIGHT = 79;
#elif defined(__MMI_MAINLCD_480X800__)
    static const int THUMB_WIDTH = 119;
    static const int THUMB_HEIGHT = 119;
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    static const int THUMB_WIDTH = 60;
    static const int THUMB_HEIGHT = 60;
#else
    // prevent build error
    static const int THUMB_WIDTH = 79;
    static const int THUMB_HEIGHT = 79;
#endif
};

/***************************************************************************** 
 * Forward Declaration 
 *****************************************************************************/
class VappGalleryDecoderBase;
class VappGalleryImageThumbnail;
class VappGalleryVideoInfoCacheItem;
class IVappGalleryMediaInfo;
class DecodeJob;
class IVappGalleryMediaList;
class VappGalleryVideoInfoCacheItem;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
enum VappGalleryMediaGroupType
{
	MEDIA_GROUP_ERROR = -1,
    MEDIA_GROUP_IMAGE,
    MEDIA_GROUP_VIDEO,
    MEDIA_GROUP_WAIT_DECODING
};

enum VappGalleryDecodeResult
{
    OK,
    CANCELLED,          // operation is already cancelled
    DECODING,           // still decoding the file
    FORMAT_UNSUPPORTED, // unsupported file format
    DRM_LOCKED,         // cannot get info due to DRM
    UNEXPECTED,         // invalid input, internal error.
    AUDIO_ONLY,         // some videos have only audio track
    PATH_TOO_DEEP,      // file system error case: path too deep
};

enum VappGalleryPrepareResult
{
    PREPARE_OK,
    PREPARE_ERROR_OUT_OF_MEMORY,      // Prepare failed due to insufficient memory
};

#define VAPP_GALLERY_ASYNC_PROVIDER_SUCCEED 0
#define VAPP_GALLERY_ASYNC_PROVIDER_FILE_PATH_QUERY_FAILED  -1
#define VAPP_GALLERY_ASYNC_PROVIDER_FILE_PATH_QUERY_HAS_CANCELED -2

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class IVappGalleryMediaList : public VfxObject
{
public:
    typedef VfxSignal1<VappGalleryPrepareResult> ListEvent;
    typedef VfxSignal1<VcpMenuPos> ListReloadEvent;
    typedef VfxSignal2<VcpMenuPos, VappGalleryDecodeResult> DecodeEvent;

public:
    // prepare the list object. When it's done, getListEvent() would
    // be signaled.
    virtual void prepareList() = 0;

    virtual VfxBool isPrepared() const { return VFX_FALSE; };

    virtual VfxBool isReloading() const{ return VFX_FALSE; };

    // destroys the list object
    virtual void release() = 0;

    // returns VFX_TRUE if this list supports dynamic refresh of contents
    virtual VfxBool canRefreshList() {return VFX_FALSE; }

    // start refresh (update contents).
    // when refresh is finished, the signal in getListEvent() will be emitted.
    // VFX_FALSE is returned if the list cannot be refreshed
    virtual VfxBool refreshList(){return VFX_FALSE;}

    virtual VfxBool releaseForegroundMemory(){return VFX_FALSE;}
    virtual VfxBool obtainForegroundMemory(){return VFX_FALSE;}

    virtual VfxBool enableBackgroundDecode(VfxBool isEnable){return VFX_FALSE;}

    // get event which is emited while content provider is prepared ready
    virtual ListEvent* getListEvent() = 0;

    // get event which is emited while content provider is reload content ready
    virtual ListReloadEvent* getListReloadStartEvent() = 0;    
    virtual ListReloadEvent* getListReloadFinishedEvent() = 0;

    // get number of groups in the list
    virtual VfxS32 getGroupCount() = 0;

    // number of media in the group
    virtual VfxS32 getMediaCountInGroup(VfxS32 grpIdx) = 0;

    // get UI name of the group
    virtual void getGroupName(const VfxS32 group, VfxWString &groupName) = 0;

    // get media group type (video or image)
    virtual VappGalleryMediaGroupType getMediaGroupType(const VcpMenuPos &itemIdx){return MEDIA_GROUP_IMAGE;};

    // name is a really common attribute, so give it a special interface here.
    virtual VappGalleryDecodeResult getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr) = 0;

    // retrieve the original media file path.
    // UNEXPECTED is returned if the media is not file-based.
    virtual VappGalleryDecodeResult getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path){return UNEXPECTED;};

    // retrieve the original media source.
    virtual VappGalleryDecodeResult getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src) = 0;

    // retrieve parsed MediaInfo result
    virtual VappGalleryDecodeResult getMediaInfo(IVappGalleryMediaInfo **ppInfo){return UNEXPECTED;};

    // The buffer argument will be filled if the item is already decoded.
    virtual VappGalleryDecodeResult startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer) = 0;

    // This event carries itemIdx and corresponding decoding result. if it is OK, then we can use lockThumb
    virtual DecodeEvent* getDecodeEvent() = 0;

    // Try locking a thumbnail image buffer. It may fail.
    virtual VappGalleryDecodeResult lockThumb(const VcpMenuPos &itemIdx, VfxImageBuffer& buffer) = 0;

    // Releasing a locked thumbnail image buffer.
    virtual void unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer) = 0;

    virtual VfxBool isMediaReady(const VcpMenuPos &itemIdx) { return VFX_FALSE; }

    virtual VfxBool canCheckDirty() { return VFX_FALSE; }

    virtual VfxBool checkDirty() { return VFX_FALSE; }

};
#if 1
/***************************************************************************** 
 * IVappGalleryAsyncProvider 
 *****************************************************************************/
typedef VfxCallback4<VcpMenuPos, VfxWString &, VfxS32, void*> FileReadyCallback;

// interface for content provider in social network scenario
class IVappGalleryAsyncProvider
{
public:
    // signal for return total file count of content provider
    // it should be emitted while provider prepare finished
    typedef VfxSignal1<VfxS32> ProviderPreparedEvent;
 
 public:   
    IVappGalleryAsyncProvider():m_prepared(VFX_FALSE){};

public:
    
    // initialize the content provider
    // after provider is prepared, the total file count should be uptated
    virtual void prepare() = 0;
    virtual VfxBool isPrepared() const = 0; 

    // check if content provider is dirty
    // if it's dirty, it should re-prepare 
    virtual VfxBool canCheckDirty() = 0;
    virtual VfxBool isDirty() = 0;
    
    // get total file count (sum of all forlders)
    virtual VfxU32 getTotalFileCount() = 0;

    // get file count in a list
    virtual VfxU32 getFileCount(VfxS32 listIndex) = 0;
    
    // get file path by index
    // note getFilePath() is an async funciton since we need to query from Internet/SN
    // while file is ready, provider should call FileReadyCallback to update file path info according to the index
    virtual void getFilePath(const VcpMenuPos index, FileReadyCallback fileReadyCB, void* userData) = 0;

    virtual VfxBool cancelFilePathQuery() = 0;
    virtual VfxBool cancelFilePathQuery(const VcpMenuPos index) = 0;
    
    // get provider prepared event
    ProviderPreparedEvent* getProviderPreparedEvent(){return &m_signalFileProviderPrepared;};

protected: 
    VfxBool m_prepared;  // VFX_TRUE while provider is initialize ready
    ProviderPreparedEvent m_signalFileProviderPrepared;
};

#endif
/***************************************************************************** 
 * SimpleBitSet 
 *****************************************************************************/
class SimpleBitSet
{
public:
    static const VfxU32 MAX_FIELD_COUNT = FS_SORT_MAX_ENTRY;
    static const VfxU32 MAX_GROUP_COUNT = 2;
    static const VfxU32 TOTAL_BIT_COUNT = MAX_FIELD_COUNT * MAX_GROUP_COUNT;
public:
    void clearAll()
    {
        memset(m_bits, 0, sizeof(VfxBool) * TOTAL_BIT_COUNT);
    }

    void setAll()
    {
        memset(m_bits, 0xFFFFFFFF, sizeof(VfxBool) * TOTAL_BIT_COUNT);
    }

    VfxBool isAllSet(VfxU32 groupId,        // which group to check
                     VfxU32 beginIdx,          // starting index
                     VfxU32 endIdx)            // end of checking index (not included)
    {
        const VfxU32 begin = vfxMax((VfxU32)0, indexFromMenuPos(VcpMenuPos(groupId, beginIdx)));
        const VfxU32 end = vfxMin((VfxU32)TOTAL_BIT_COUNT, indexFromMenuPos(VcpMenuPos(groupId, endIdx)));
        for(VfxU32 i = begin; i < end; ++i)
        {
            if(!m_bits[i])
                return VFX_FALSE;
        }
        return VFX_TRUE;
    }

    VfxBool isAnySet(VfxU32 groupId,        // which group to check
                     VfxU32 beginIdx,          // starting index
                     VfxU32 endIdx)            // end of checking index (not included)
    {
        const VfxU32 begin = vfxMax((VfxU32)0, indexFromMenuPos(VcpMenuPos(groupId, beginIdx)));
        const VfxU32 end = vfxMin((VfxU32)TOTAL_BIT_COUNT, indexFromMenuPos(VcpMenuPos(groupId, endIdx)));
        for(VfxU32 i = begin; i < end; ++i)
        {
            if(m_bits[i])
                return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    /////////////////////////////////
    //  VfxU32 as index
    /////////////////////////////////
    VfxBool isSet(VfxU32 index)const
    {
        // default to group 0
        if(index >= MAX_FIELD_COUNT)
        {
            return VFX_FALSE;
        }
        return m_bits[index];
    }

    void set(VfxU32 index)
    {
        // default to group 0
        if(index >= MAX_FIELD_COUNT)
        {
            return;
        }
        m_bits[index] = VFX_TRUE;
    }

    void clear(VfxU32 index)
    {
        // default to group 0
        if(index >= MAX_FIELD_COUNT)
        {
            return;
        }
        m_bits[index] = VFX_FALSE;
    }

    /////////////////////////////////
    //  VcpMenuPos as index
    /////////////////////////////////
    static inline VfxU32 indexFromMenuPos(const VcpMenuPos &pos)
    {
        const VfxU32 index = vfxMin((VfxU32)(TOTAL_BIT_COUNT - 1),
                                    (VfxU32)(pos.group * MAX_FIELD_COUNT + pos.pos));
        return index;
    }

    VfxBool isSet(const VcpMenuPos &pos)const
    {   
        return m_bits[indexFromMenuPos(pos)];
    }

    void set(const VcpMenuPos &pos)
    {
        m_bits[indexFromMenuPos(pos)] = VFX_TRUE;
    }

    void clear(const VcpMenuPos &pos)
    {
        m_bits[indexFromMenuPos(pos)] = VFX_FALSE;
    }

private:
    VfxBool m_bits[TOTAL_BIT_COUNT];
};

#else

#ifdef __cplusplus
extern "C"
{
#include "MediaCacheSrvGprot.h"
#include "MediaCacheSrv.h"              // we need this internal header to hook engine
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "gdi_include.h"
#include "mdi_video.h"
#include "vcui_gallery_gprot.h"  
};
#endif

/***************************************************************************** 
 * Constants
 *****************************************************************************/

// Media Grid thumbnail size effects both MediaCache case and Wallpaper thumb,
// so we define it here. The UI layout should reference these constants.
class VappGalleryMediaGridConstant
{
public:
#if defined(__MMI_MAINLCD_320X480__)
    static const int THUMB_WIDTH = 79;
    static const int THUMB_HEIGHT = 79;
#elif defined(__MMI_MAINLCD_480X800__)
    static const int THUMB_WIDTH = 119;
    static const int THUMB_HEIGHT = 119;
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    static const int THUMB_WIDTH = 60;
    static const int THUMB_HEIGHT = 60;
#else
    // prevent build error
    static const int THUMB_WIDTH = 79;
    static const int THUMB_HEIGHT = 79;
#endif
};

/***************************************************************************** 
 * Forward Declaration 
 *****************************************************************************/
class VappGalleryDecoderBase;
class VappGalleryImageThumbnail;
class VappGalleryVideoInfoCacheItem;
class IVappGalleryMediaInfo;
class DecodeJob;
class IVappGalleryMediaList;
class VappGalleryVideoInfoCacheItem;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
enum VappGalleryMediaGroupType
{
    MEDIA_GROUP_IMAGE,
    MEDIA_GROUP_VIDEO,    
};

enum VappGalleryDecodeResult
{
    OK,
    CANCELLED,          // operation is already cancelled
    DECODING,           // still decoding the file
    FORMAT_UNSUPPORTED, // unsupported file format
    DRM_LOCKED,         // cannot get info due to DRM
    UNEXPECTED,         // invalid input, internal error.
    AUDIO_ONLY,         // some videos have only audio track
    PATH_TOO_DEEP,      // file system error case: path too deep
};

enum VappGalleryPrepareResult
{
    PREPARE_OK,
    PREPARE_ERROR_OUT_OF_MEMORY,      // Prepare failed due to insufficient memory
};

#define VAPP_GALLERY_ASYNC_PROVIDER_SUCCEED 0
#define VAPP_GALLERY_ASYNC_PROVIDER_FILE_PATH_QUERY_FAILED  -1
#define VAPP_GALLERY_ASYNC_PROVIDER_FILE_PATH_QUERY_HAS_CANCELED -2

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class IVappGalleryMediaList : public VfxObject
{
public:
    typedef VfxSignal1<VappGalleryPrepareResult> ListEvent;
    typedef VfxSignal1<VcpMenuPos> ListReloadEvent;
    typedef VfxSignal2<VcpMenuPos, VappGalleryDecodeResult> DecodeEvent;

public:
    // prepare the list object. When it's done, getListEvent() would
    // be signaled.
    virtual void prepareList() = 0;

    virtual VfxBool isPrepared() const { return VFX_FALSE; };

    virtual VfxBool isReloading() const{ return VFX_FALSE; };

    // destroys the list object
    virtual void release() = 0;

    // returns VFX_TRUE if this list supports dynamic refresh of contents
    virtual VfxBool canRefreshList() {return VFX_FALSE; }

    // start refresh (update contents).
    // when refresh is finished, the signal in getListEvent() will be emitted.
    // VFX_FALSE is returned if the list cannot be refreshed
    virtual VfxBool refreshList(){return VFX_FALSE;}

    virtual VfxBool releaseForegroundMemory(){return VFX_FALSE;}
    virtual VfxBool obtainForegroundMemory(){return VFX_FALSE;}

    virtual VfxBool enableBackgroundDecode(VfxBool isEnable){return VFX_FALSE;}

    // get event which is emited while content provider is prepared ready
    virtual ListEvent* getListEvent() = 0;

    // get event which is emited while content provider is reload content ready
    virtual ListReloadEvent* getListReloadStartEvent() = 0;    
    virtual ListReloadEvent* getListReloadFinishedEvent() = 0;

    // get number of groups in the list
    virtual VfxS32 getGroupCount() = 0;

    // number of media in the group
    virtual VfxS32 getMediaCountInGroup(VfxS32 grpIdx) = 0;

    // get UI name of the group
    virtual void getGroupName(const VfxS32 group, VfxWString &groupName) = 0;

    // get media group type (video or image)
    virtual VappGalleryMediaGroupType getMediaGroupType(const VcpMenuPos &itemIdx){return MEDIA_GROUP_IMAGE;};

    // name is a really common attribute, so give it a special interface here.
    virtual VappGalleryDecodeResult getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr) = 0;

    // retrieve the original media file path.
    // UNEXPECTED is returned if the media is not file-based.
    virtual VappGalleryDecodeResult getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path){return UNEXPECTED;};

    // retrieve the original media source.
    virtual VappGalleryDecodeResult getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src) = 0;

    // retrieve parsed MediaInfo result
    virtual VappGalleryDecodeResult getMediaInfo(IVappGalleryMediaInfo **ppInfo){return UNEXPECTED;};

    // retrieve parsed MediaDuration
    virtual VappGalleryDecodeResult getMediaDuration(const VcpMenuPos &itemIdx, U64 &mediaDuration, const VfxBool checkMemCacheOnly = VFX_FALSE){return UNEXPECTED;};

    // retrieve parsed Media last play position
    virtual VappGalleryDecodeResult getMediaBookmark(const VcpMenuPos &itemIdx, U64 &mediaBookmark, const VfxBool checkMemCacheOnly = VFX_FALSE){return UNEXPECTED;};

    // The buffer argument will be filled if the item is already decoded.
    virtual VappGalleryDecodeResult startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer) = 0;

    // This event carries itemIdx and corresponding decoding result. if it is OK, then we can use lockThumb
    virtual DecodeEvent* getDecodeEvent() = 0;

    // Try locking a thumbnail image buffer. It may fail.
    virtual VappGalleryDecodeResult lockThumb(const VcpMenuPos &itemIdx, VfxImageBuffer& buffer, srv_mediacache_image_source_enum decodeMethod) = 0;

    // Releasing a locked thumbnail image buffer.
    virtual void unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer) = 0;

    virtual VfxBool isMediaReady(const VcpMenuPos &itemIdx) { return VFX_FALSE; }

    virtual VfxBool canCheckDirty() { return VFX_FALSE; }

    virtual VfxBool checkDirty() { return VFX_FALSE; }

    // Reomve cache element in DB
    virtual VfxBool canRemoveDBCacheElement(){ return VFX_FALSE; }
    virtual VfxBool removeDBCacheElement(VfxWString& filePath){ return VFX_FALSE; }
};
#if 1
/***************************************************************************** 
 * IVappGalleryAsyncProvider 
 *****************************************************************************/
typedef VfxCallback4<VcpMenuPos, VfxWString &, VfxS32, void*> FileReadyCallback;

// interface for content provider in social network scenario
class IVappGalleryAsyncProvider
{
public:
    // signal for return total file count of content provider
    // it should be emitted while provider prepare finished
    typedef VfxSignal1<VfxS32> ProviderPreparedEvent;
 
 public:   
    IVappGalleryAsyncProvider():m_prepared(VFX_FALSE){};

public:
    
    // initialize the content provider
    // after provider is prepared, the total file count should be uptated
    virtual void prepare() = 0;
    virtual VfxBool isPrepared() const = 0; 

    // check if content provider is dirty
    // if it's dirty, it should re-prepare 
    virtual VfxBool canCheckDirty() = 0;
    virtual VfxBool isDirty() = 0;
    
    // get total file count (sum of all forlders)
    virtual VfxU32 getTotalFileCount() = 0;

    // get file count in a list
    virtual VfxU32 getFileCount(VfxS32 listIndex) = 0;
    
    // get file path by index
    // note getFilePath() is an async funciton since we need to query from Internet/SN
    // while file is ready, provider should call FileReadyCallback to update file path info according to the index
    virtual void getFilePath(const VcpMenuPos index, FileReadyCallback fileReadyCB, void* userData) = 0;

    virtual VfxBool cancelFilePathQuery() = 0;
    virtual VfxBool cancelFilePathQuery(const VcpMenuPos index) = 0;
    
    // get provider prepared event
    ProviderPreparedEvent* getProviderPreparedEvent(){return &m_signalFileProviderPrepared;};

protected: 
    VfxBool m_prepared;  // VFX_TRUE while provider is initialize ready
    ProviderPreparedEvent m_signalFileProviderPrepared;
};

#endif
/***************************************************************************** 
 * SimpleBitSet 
 *****************************************************************************/
class SimpleBitSet
{
public:
    static const VfxU32 MAX_FIELD_COUNT = FS_SORT_MAX_ENTRY;
    static const VfxU32 MAX_GROUP_COUNT = 2;
    static const VfxU32 TOTAL_BIT_COUNT = MAX_FIELD_COUNT * MAX_GROUP_COUNT;
public:
    void clearAll()
    {
        memset(m_bits, 0, sizeof(VfxBool) * TOTAL_BIT_COUNT);
    }

    void setAll()
    {
        memset(m_bits, 0xFFFFFFFF, sizeof(VfxBool) * TOTAL_BIT_COUNT);
    }

    VfxBool isAllSet(VfxU32 groupId,        // which group to check
                     VfxU32 beginIdx,          // starting index
                     VfxU32 endIdx)            // end of checking index (not included)
    {
        const VfxU32 begin = vfxMax((VfxU32)0, indexFromMenuPos(VcpMenuPos(groupId, beginIdx)));
        const VfxU32 end = vfxMin((VfxU32)TOTAL_BIT_COUNT, indexFromMenuPos(VcpMenuPos(groupId, endIdx)));
        for(VfxU32 i = begin; i < end; ++i)
        {
            if(!m_bits[i])
                return VFX_FALSE;
        }
        return VFX_TRUE;
    }

    VfxBool isAnySet(VfxU32 groupId,        // which group to check
                     VfxU32 beginIdx,          // starting index
                     VfxU32 endIdx)            // end of checking index (not included)
    {
        const VfxU32 begin = vfxMax((VfxU32)0, indexFromMenuPos(VcpMenuPos(groupId, beginIdx)));
        const VfxU32 end = vfxMin((VfxU32)TOTAL_BIT_COUNT, indexFromMenuPos(VcpMenuPos(groupId, endIdx)));
        for(VfxU32 i = begin; i < end; ++i)
        {
            if(m_bits[i])
                return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    /////////////////////////////////
    //  VfxU32 as index
    /////////////////////////////////
    VfxBool isSet(VfxU32 index)const
    {
        // default to group 0
        if(index >= MAX_FIELD_COUNT)
        {
            return VFX_FALSE;
        }
        return m_bits[index];
    }

    void set(VfxU32 index)
    {
        // default to group 0
        if(index >= MAX_FIELD_COUNT)
        {
            return;
        }
        m_bits[index] = VFX_TRUE;
    }

    void clear(VfxU32 index)
    {
        // default to group 0
        if(index >= MAX_FIELD_COUNT)
        {
            return;
        }
        m_bits[index] = VFX_FALSE;
    }

    /////////////////////////////////
    //  VcpMenuPos as index
    /////////////////////////////////
    static inline VfxU32 indexFromMenuPos(const VcpMenuPos &pos)
    {
        const VfxU32 index = vfxMin((VfxU32)(TOTAL_BIT_COUNT - 1),
                                    (VfxU32)(pos.group * MAX_FIELD_COUNT + pos.pos));
        return index;
    }

    VfxBool isSet(const VcpMenuPos &pos)const
    {   
        return m_bits[indexFromMenuPos(pos)];
    }

    void set(const VcpMenuPos &pos)
    {
        m_bits[indexFromMenuPos(pos)] = VFX_TRUE;
    }

    void clear(const VcpMenuPos &pos)
    {
        m_bits[indexFromMenuPos(pos)] = VFX_FALSE;
    }

private:
    VfxBool m_bits[TOTAL_BIT_COUNT];
};
#endif

#if 1
struct VappGallerySlideshowEffectOption
{
    VcpPageEffectType effectType;
    MMI_STR_ID nameId;
};

class VappGallerySlideShowSetting
{
public:
    const static VfxMsec TRANSITION_TIME_MSEC = 2000;

public:
    VappGallerySlideShowSetting();
    ~VappGallerySlideShowSetting();

    void flushToNVRAM();

    VfxBool getShuffle();
    
    void setShuffle(VfxBool isShuffle);

    VfxBool getRepeat();

    void setRepeat(VfxBool isRepeat);

    VfxMsec getDelayTime();

    VfxS32 getDelayOptionCount() const;

    VfxMsec getDelayTimeByOptionIndex(VfxS32 idx);

    void setSelectedDelayOptionIndex(VfxS32 idx);

    VfxS32 getSelectedDelayOptionIndex() const;
    
    /////////////////////////////////////////////////
    void getEffect(VfxBool &isTransitionEffect, VcpPageEffectType &transitionType);
    
    MMI_STR_ID getEffectName();
    VfxS32 getEffectOptionCount() const;
    VcpPageEffectType getEffectByOptionIndex(VfxS32 idx);
    MMI_STR_ID getEffectNameByOptionIndex(VfxS32 idx);
    void setSelectedEffectOptionIndex(VfxS32 idx);
    VfxS32 getSelectedEffectOptionIndex() const;
    VfxMsec getTransitionDuration() const;

protected:
    void readFromNVRAM();

private:
    const static VfxS32 DELAY_OPTION_COUNT = 6;
    const static VfxMsec g_delayOption[DELAY_OPTION_COUNT];
    const static VappGallerySlideshowEffectOption g_effectOption[];

private:
    // in-memory value
    VfxU16 m_delaySecondOptionIndex;
    VfxU16 m_effectOptionIndex;
    VfxU8 m_isShuffle;
    VfxU8 m_isRepeat;
};
#endif

#endif /* __VAPP_GALLERY_DATA_H__ */

