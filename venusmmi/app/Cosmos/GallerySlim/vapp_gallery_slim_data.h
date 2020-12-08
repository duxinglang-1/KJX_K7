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

#ifndef __VAPP_GALLERY_DATA_H__
#define __VAPP_GALLERY_DATA_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_gallery_slim.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_cache.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_gallery_slim_util.h"
#include "cp\vapp_media_list.h"

#ifdef __cplusplus
extern "C"
{
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "gdi_include.h"
#include "gdi_layer.h"
#include "mdi_video.h"
#include "vcui_gallery_gprot.h"    // TODO: test
};
#endif

/*****************************************************************************
 * Forward Declaration
 *****************************************************************************/
class VappGalleryDecoderBase;
class VappGalleryImageThumbnail;
//class VappGalleryVideoInfoCacheItem;
class IVappGalleryMediaInfo;
class DecodeJob;

/*****************************************************************************
 * VappGalleryFmgrList and Derived classes
 *****************************************************************************/
class VappGalleryFmgrList : public VfxObject
{
public:
    enum
    {
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_FOLDER__
        MAX_FOLDER_COUNT = 2
#else
        MAX_FOLDER_COUNT = 1
#endif
    };

    const static VfxS32 MAX_FILE_COUNT = VFX_MAX(FS_SORT_MAX_ENTRY, VAPP_GALLERY_FS_MAX_FILE_COUNT);
    VfxSignal1<VcpMenuPos> m_signalFmgrListLoadStart;
    VfxSignal1<VcpMenuPos> m_signalFmgrListLoadFinished;

// ctor
public:
    VappGalleryFmgrList();

// override VfxObject
public:
    virtual void onInit();
    virtual void onDeinit();

// methods
public:
    // configure storage to scan videos.
    // this must be called before prepare().
    virtual VfxBool config(
        U8 driveLetter,  // [IN] drive to be scanned for file lists
        IVappGalleryMediaList::ListEvent *pReadySignal,  // [IN] signal to be emitted when all lists are ready to use
        IVappGalleryMediaList::ListReloadEvent *pReloadStartSignal = NULL,
        IVappGalleryMediaList::ListReloadEvent *pReloadFinishedSignal = NULL
        );

    // assign a subset of file type to be used.
    // this will be intersected with default filter types.
    virtual VfxBool configFileTypeLimit(const FMGR_FILTER *filter);

    // assign specific sort method. Default is sort by name.
    void configSortMethod(VfxU32 sortMethod);

    // optionally set a file name to be searched during preapre().
    // index of the file can be retrieved via getFoundFileIndex()
    virtual void configSearchFileDuringPrepare(const VfxWString &namePattern);

    // retrieve index of the pattern/filename given in configSearchFileDuringPrepare()
    // found during prepare. This function is only available when list isPrepared().
    // RETURNS VFX_FALSE if the pattern/name is not found
    virtual VfxBool getFoundFileIndex(VcpMenuPos &foundIndex);

    // initialize the list
    void prepare();

    // cancel all async operations
    void stop();

    // re-scan files to populate list.
    void refresh();

    // destroy all lists
    void release();

    VfxBool reload(const VcpMenuPos &index);

    VfxBool isPrepared() const;

    VfxBool isReloading() const;

    VfxBool isDirty();

    // get all file count in all lists
    VfxU32 getTotalFileCount();

    // get file count in a list
    VfxU32 getFileCount(VfxS32 listIndex);

    VappGalleryDecodeResult getFileName(const VcpMenuPos &index, VfxWString &nameStr);
    VappGalleryDecodeResult getPathName(const VcpMenuPos &index, VfxWString &pathStr);

    SRV_FMGR_FILELIST_HANDLE getFileList(const VfxS32 index = 0);

    // information, get file list handle capcacity
    // RETURNS SRV_FMGR_FILELIST_CAP_END if file list dose not exist
    S32 getFileListCapability(const VfxS32 index = 0);

public:
    static VappGalleryDecodeResult convertFMgrError(S32 fmgrResult);

protected:
    VappGalleryDecodeResult getFilePathImpl(const VcpMenuPos &index, VfxWString &pathStr, const VfxBool queryPath);

    // internally calledy by refresh() and prepare()
    // to begin populate file lists
    void refreshAllFileList();

    // start FileMgrSrv to refresh next unrefreshed file list
    // returns VFX_TRUE if next file list starts to refresh.
    // returns VFX_FALSE if there is no next file list.
    VfxBool refreshNextFileList();

    virtual void setFilter(FMGR_FILTER &filter);

    // handles FileMgrSrv finished refreshing file list
    virtual mmi_ret handleFileMgrRefreshResult(srv_fmgr_filelist_refresh_result_event_struct* refreshEvent);

    // handles FileMgrSrv re-load filename result
    virtual mmi_ret handleFileMgrLoadResult(srv_fmgr_filelist_load_result_event_struct* reloadEvent);

    // callback for file manager. dispatches to instance method.
    static mmi_ret onFileMgrEvent(mmi_event_struct *param);

    // dst = dst & src
    void intersectFilter(FMGR_FILTER &dst, const FMGR_FILTER &src);

    void releaseAllFileList();

    VfxBool isUnderPickerCUI();

    void closeLoadingJob(const VfxU32 line);

    void notifyReloadStartEvent(const VcpMenuPos &index, const VfxU32 line);

    void notifyReloadFinishedEvent(const VcpMenuPos &index, const VfxU32 line);

protected:
    // for FileMgrSrv file lists
    VfxBool m_prepared;
    VfxBool m_isReloading;
    VfxU8* m_pFileListHeap;
    VfxS32 m_refreshedListIndex;
    VfxU32 m_sortMethod;
    VcpMenuPos m_searchIndex;       // stores the resource of pattern search during prepare.
    SRV_FMGR_FILELIST_HANDLE m_fileLists[MAX_FOLDER_COUNT];  // handle to FileMgr file list. Used to enumerate files in folder.
    VfxWString m_folderPaths[MAX_FOLDER_COUNT];
    VfxWString m_patternToSearch;   // stores pattern to search for during prepare.
    IVappGalleryMediaList::ListEvent *m_pSignalReady;
    IVappGalleryMediaList::ListReloadEvent *m_pSignalReloadStart;
    IVappGalleryMediaList::ListReloadEvent *m_pSignalReloadFinished;
    FMGR_FILTER m_limitFilter;
    VfxBool m_isFolderExist[MAX_FOLDER_COUNT]; // record if each floder of m_fileLists exist or not
    VfxWeakPtr<DecodeJob> m_loadingJob;
};

class VappGalleryFmgrFolderList : public VappGalleryFmgrList
{
public:
    VappGalleryFmgrFolderList();
    // configure storage to scan folders under My Picture ("Images" folder in disk)
    // also includes the "Received folder" as the 1st folder
    // this must be called before prepare().
    virtual VfxBool config(
        U8 driveLetter,  // [IN] drive to be scanned for file lists
        IVappGalleryMediaList::ListEvent *pReadySignal,  // [IN] signal to be emitted when all lists are ready to use
        IVappGalleryMediaList::ListReloadEvent *pReloadStartSignal = NULL,
        IVappGalleryMediaList::ListReloadEvent *pReloadFinishedSignal = NULL
    );

    // override behavior to add "My Recieved" folder
    VfxU32 getTotalFileCount();

    // override behavior to add "My Recieved" folder
    VfxU32 getFileCount(VfxS32 listIndex);

    // override behavior to add "My Recieved" folder
    VappGalleryDecodeResult getFileName(const VcpMenuPos &index, VfxWString &nameStr);

    // override behavior to add "My Recieved" folder
    VappGalleryDecodeResult getPathName(const VcpMenuPos &index, VfxWString &pathStr);

protected:
    virtual void setFilter(FMGR_FILTER &filter);

    // return index of "My Recieved" folder
    VcpMenuPos getMyRecievedFolderIndex();

    // get index fixed offset for query file info
    VfxS32 getGroupIndexFixedOffset();

protected:
    U8 m_driveLetter;
};

class VappGalleryFmgrImageList : public VappGalleryFmgrList
{
public:
    // scans all image files under an arbitrary folder path
    // this must be called before prepare().
    virtual VfxBool configFolder(
        const VfxWString &folderPath,  // [IN] drive to be scanned for file lists
        IVappGalleryMediaList::ListEvent *pReadySignal,  // [IN] signal to be emitted when all lists are ready to use
        IVappGalleryMediaList::ListReloadEvent *pReloadStartSignal = NULL,
        IVappGalleryMediaList::ListReloadEvent *pReloadFinishedSignal = NULL
    );
protected:
    virtual void setFilter(FMGR_FILTER &filter);
};

class VappGalleryFmgrImageVideoList : public VappGalleryFmgrImageList
{
protected:
    virtual void setFilter(FMGR_FILTER &filter);
};

/*****************************************************************************
 * Social Network support
 *****************************************************************************/
enum VappGalleryCacheItemBaseType
{
    CACHE_TYPE_THUMBNAIL,
    CACHE_TYPE_L1,
};

class VappGalleryCacheItemBase
{
public:
    static const VfxS32 OFFESET_32_ALIGN = 32;
    static const VfxS32 BPP = VAPP_GALLERY_IMG_VIEWER_BPP;
    VappGalleryDecodeResult m_result;
    // padding to 32-byte

    VappGalleryCacheItemBase():
    m_result(DECODING){}
};

class VappGalleryL1CacheItem : public VappGalleryCacheItemBase
{
public:
    static const VfxU32 bufSize = ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * BPP + 31) / 32) * 32;
    static const VfxU32 cacheItemSize = bufSize + OFFESET_32_ALIGN + 32;
	
private:
    U8 m_thumbBuffer[cacheItemSize];
	VfxSize m_decodeSize;

public:
	void setDecodeSize (VfxSize decodeSize)
	{
        m_decodeSize = decodeSize;
	}
	
    GDI_HANDLE getLayer(VfxSize decodeSize) const
    {
        GDI_RESULT res = GDI_FAILED;
        GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
        U8* thumbBufferPtr = getThumbBufferPtr();
        res = gdi_layer_create_cf_using_outside_memory(GALLERY_GDI_CF_VIEWER,
                                                       0, 0,
                                                       m_decodeSize.width,
                                                       m_decodeSize.height,
                                                       &thumbLayer,
                                                       thumbBufferPtr, //(U8*)m_thumbBuffer,
                                                       bufSize);
        VFX_ASSERT(GDI_SUCCEED == res);
        return thumbLayer;
    }

    void getImageBuffer(VfxImageBuffer &thumbBuf) const
    {
        thumbBuf.width = m_decodeSize.width;
        thumbBuf.height = m_decodeSize.height;
        thumbBuf.colorFormat = GALLERY_VRT_CF_VIEWER;
        thumbBuf.pitchBytes = m_decodeSize.width * BPP;
        thumbBuf.ptr = getThumbBufferPtr();//const_cast<VfxU8*>(&m_thumbBuffer[0]);
    }
    U8* getThumbBufferPtr() const
    {
#if (defined(__MTK_TARGET__))
        const VfxU32 line_start_addr = (VfxU32)&m_thumbBuffer[0];
        const VfxU32 line_aligned_start_addr = line_start_addr & ~(CPU_CACHE_LINE_SIZE - 1);
        return (U8*)line_aligned_start_addr;
#else
        const VfxU32 line_start_addr = (VfxU32)&m_thumbBuffer[0];
        return (U8*)line_start_addr;
#endif
    }
};

class VappGalleryMediaGridCacheItem : public VappGalleryCacheItemBase
{
public:

    static const VfxU32 bufSize = ((VappGalleryMediaGridConstant::THUMB_WIDTH * VappGalleryMediaGridConstant::THUMB_HEIGHT * BPP + 31) / 32) * 32 ;
    static const VfxU32 cacheItemSize = bufSize + OFFESET_32_ALIGN + 32;
private:
    U8 m_thumbBuffer[cacheItemSize];

public:
    GDI_HANDLE getLayer() const
    {
        GDI_RESULT res = GDI_FAILED;
        GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
        U8* thumbBufferPtr = getThumbBufferPtr();
        res = gdi_layer_create_cf_using_outside_memory(GALLERY_GDI_CF_THUMB,
                                                       0, 0,
                                                       VappGalleryMediaGridConstant::THUMB_WIDTH,
                                                       VappGalleryMediaGridConstant::THUMB_HEIGHT,
                                                       &thumbLayer,
                                                       thumbBufferPtr, //(U8*)m_thumbBuffer,
                                                       bufSize);
        VFX_ASSERT(GDI_SUCCEED == res);
        return thumbLayer;
    }

    void getImageBuffer(VfxImageBuffer &thumbBuf) const
    {
        thumbBuf.width = VappGalleryMediaGridConstant::THUMB_WIDTH / 2 * 2;
        thumbBuf.height = VappGalleryMediaGridConstant::THUMB_HEIGHT;
        thumbBuf.colorFormat = GALLERY_VRT_CF_THUMB;
        thumbBuf.pitchBytes = (VappGalleryMediaGridConstant::THUMB_WIDTH / 2 * 2) * BPP;
        thumbBuf.ptr = getThumbBufferPtr(); //const_cast<VfxU8*>(&m_thumbBuffer[0]);
    }
    U8* getThumbBufferPtr() const
    {
#if (defined(__MTK_TARGET__))
        const VfxU32 line_start_addr = (VfxU32)&m_thumbBuffer[0];
        const VfxU32 line_aligned_start_addr = line_start_addr & ~(CPU_CACHE_LINE_SIZE - 1);
        return (U8*)line_aligned_start_addr;
#else
        const VfxU32 line_start_addr = (VfxU32)&m_thumbBuffer[0];
        return (U8*)line_start_addr;
#endif
    }
};

#ifdef __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__
class VappGalleryMediaListAsync : public IVappGalleryMediaList
{
    VFX_DECLARE_CLASS(VappGalleryMediaListAsync);
public:
    static const VfxS32 MAX_FOLDER_COUNT = 1;

public:
    typedef VappGalleryCache<VappGalleryL1CacheItem> L1Cache;
    typedef VappGalleryCache<VappGalleryMediaGridCacheItem> ThumbnailCache;
    typedef VfxSignal3<VcpMenuPos, VfxWString&, VappGalleryDecodeResult> FilePathReadyEvent;

public:
    VappGalleryMediaListAsync();
    VappGalleryMediaListAsync(VappGalleryCacheItemBaseType type);

    void stopDecode();
    void stopDecode(VcpMenuPos itemIdx);
    VcpMenuPos getParsingIndex(){return m_parsingIndex; }

public:
    virtual void onInit();
    virtual void onDeinit();

// Implementation for IVappGalleryMediaList
public:
    // prepare the list object. When it's done, getListEvent() would be signaled.
    virtual void prepareList();
    virtual VfxBool isPrepared() const;
    void configProvider(IVappGalleryAsyncProvider *provider) { m_provider = provider;};

    // destroys the list
    virtual void release();

    // returns VFX_TRUE if this list supports dynamic refresh of contents
    virtual VfxBool canRefreshList(){return VFX_TRUE;}

    // start refresh (update contents).
    // when refresh is finished, the signal in getListEvent() will be emitted.
    // VFX_FALSE is returned if the list cannot be refreshed
    virtual VfxBool refreshList();

    // obtainForegroundMemory() should be called while entry the page
    // releaseForegroundMemory() shoule be called while exist the page
    virtual VfxBool releaseForegroundMemory();
    virtual VfxBool obtainForegroundMemory();

    // list ready signal
    virtual ListEvent* getListEvent(){return &m_signalReady;}

    // list reload signal -- note it is not support in aysnc media list now
    virtual ListReloadEvent* getListReloadStartEvent(){return &m_signalReloadFinished;}
    virtual ListReloadEvent* getListReloadFinishedEvent(){return &m_signalReloadFinished;}

    // get number of groups in the list
    virtual VfxS32 getGroupCount();

    // number of media in the group
    virtual VfxS32 getMediaCountInGroup(VfxS32 grpIdx);

    // get UI name of the group
    virtual void getGroupName(const VfxS32 group, VfxWString &groupName);

    // always images
    virtual VappGalleryMediaGroupType getMediaGroupType(const VcpMenuPos &itemIdx);

    // name is a really common attribute, so give it a special interface here.
    virtual VappGalleryDecodeResult getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr);

    // retrieve the original media file path.
    // UNEXPECTED is returned if the media is not file-based.
    virtual VappGalleryDecodeResult getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path);

    // retrieve the original media source.
    virtual VappGalleryDecodeResult getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src);

    // thumbnail decoding finished
    // This event carries itemIdx and corresponding decoding result. if it is OK, then we can use lockThumb
    virtual DecodeEvent* getDecodeEvent(){return &m_signalDecode;}

    virtual VfxBool enableBackgroundDecode(VfxBool isEnable);

    virtual VappGalleryDecodeResult startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer);

    // Try locking a thumbnail image buffer. It may fail.
    virtual VappGalleryDecodeResult lockThumb(const VcpMenuPos &itemIdx, VfxImageBuffer& buffer);
    virtual void unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer);
    virtual VfxBool isMediaReady(const VcpMenuPos &itemIdx);

    virtual VfxBool canCheckDirty();
    virtual VfxBool checkDirty();

    FilePathReadyEvent* getFilePathReadyEvent();

protected:
    VfxBool isValidGetFileResult(const VfxS32 result) const;
    void onProviderReady(VfxS32 fileCount);
    void onStartDecodeAfterFileReady(VcpMenuPos index, VfxWString &path, VfxS32 queryResult, void* userData);
    void onFilePathReady(VcpMenuPos index, VfxWString &path, VfxS32 queryResult, void* userData);

    // if DB entry not found or invalid, start decode with MDI.
    // MDI itself does not providing a job queue.
    //virtual VappGalleryDecodeResult startDecodeWithMDI(const VcpMenuPos &itemIdx);

    // handles video decode result
    void onThumbnailDecodeResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);

// Implementation
private:
    void prepareCacheStore();
    void closeCacheStore();
    VappGalleryCacheItemBase* getItem(const VfxId key);
    VappGalleryDecodeResult getThumbImageSrcImpl(VcpMenuPos itemIdx, VfxImageBuffer& buffer);
    void removeCacheItemImpl(const VcpMenuPos index);

private:
    VappGalleryCacheItemBaseType m_cacheType;
    IVappGalleryAsyncProvider *m_provider;  // content provider
    VappGalleryImageThumbnail *m_decoder;           // decoder
    VfxObject *m_cacheStore;
    ListEvent m_signalReady;   // signal which is resposibel to notify content provider is parepared
    ListReloadEvent m_signalReloadStart;
    ListReloadEvent m_signalReloadFinished;

    VfxImageBuffer *m_decordingImageBuf;

    // for MDI parsing, cache & storage
    VfxBool m_backgroundMode;       // do not allocate FG memory when in background
    VfxBool m_parsing;              // is underlying MDI calls runnning
    VcpMenuPos m_parsingIndex;      // index of files sent to MDI
    DecodeEvent m_signalDecode;

    FilePathReadyEvent m_signalFilePathReady;
    VfxWeakPtr<DecodeJob> m_filePathQueryJob;    // keep tracking to make sure we only have 1 decoding job
};
#endif /* __VAPP_GALLERY_ENABLE_ASYNC_MEDIA_LSIT__ */

/*****************************************************************************
 * VappGalleryMediaListCommon
 *****************************************************************************/

class VappGalleryMediaListCommon : public IVappGalleryMediaList
{
    VFX_DECLARE_CLASS(VappGalleryMediaListCommon);
public:
    static const VfxS32 MAX_FOLDER_COUNT = 1;

public:
    typedef VappGalleryCache<VappGalleryL1CacheItem> L1Cache;
    typedef VappGalleryCache<VappGalleryMediaGridCacheItem> ThumbnailCache;

public:
    VappGalleryMediaListCommon();
    VappGalleryMediaListCommon(VappGalleryCacheItemBaseType type);

    void stopDecode();
    void stopDecode(VcpMenuPos itemIdx);
    VcpMenuPos getParsingIndex(){return m_parsingIndex; }

public:
    virtual void onInit();
    virtual void onDeinit();

// Implementation for IVappGalleryMediaList
public:
    // prepare the list object. When it's done, getListEvent() would be signaled.
    virtual void prepareList();
    virtual VfxBool isPrepared() const;

    // destroys the list
    virtual void release();

    // returns VFX_TRUE if this list supports dynamic refresh of contents
    virtual VfxBool canRefreshList(){return VFX_TRUE;}

    // start refresh (update contents).
    // when refresh is finished, the signal in getListEvent() will be emitted.
    // VFX_FALSE is returned if the list cannot be refreshed
    virtual VfxBool refreshList();

    // obtainForegroundMemory() should be called while entry the page
    // releaseForegroundMemory() shoule be called while exist the page
    virtual VfxBool releaseForegroundMemory();
    virtual VfxBool obtainForegroundMemory();

    // list ready signal
    virtual ListEvent* getListEvent(){return &m_signalReady;}

    // list reload signal -- note it is not support in aysnc media list now
    virtual ListReloadEvent* getListReloadStartEvent(){return &m_signalReloadStart;}
    virtual ListReloadEvent* getListReloadFinishedEvent(){return &m_signalReloadFinished;}

    // get number of groups in the list
    virtual VfxS32 getGroupCount();

    // number of media in the group
    virtual VfxS32 getMediaCountInGroup(VfxS32 grpIdx);

    // get UI name of the group
    virtual void getGroupName(const VfxS32 group, VfxWString &groupName);

    // always images
    virtual VappGalleryMediaGroupType getMediaGroupType(const VcpMenuPos &itemIdx);

    // name is a really common attribute, so give it a special interface here.
    virtual VappGalleryDecodeResult getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr);

    // retrieve the original media file path.
    // UNEXPECTED is returned if the media is not file-based.
    virtual VappGalleryDecodeResult getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path);

    // retrieve the original media source.
    virtual VappGalleryDecodeResult getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src);

    // thumbnail decoding finished
    // This event carries itemIdx and corresponding decoding result. if it is OK, then we can use lockThumb
    virtual DecodeEvent* getDecodeEvent(){return &m_signalDecode;}

    virtual VfxBool enableBackgroundDecode(VfxBool isEnable);

    virtual VappGalleryDecodeResult startDecodeThumbLiveWallpaper(VcpMenuPos itemIdx, VfxImageBuffer& buffer);
		
    virtual VappGalleryDecodeResult startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer);

    // Try locking a thumbnail image buffer. It may fail.
    virtual VappGalleryDecodeResult lockThumb(const VcpMenuPos &itemIdx, VfxImageBuffer& buffer);
    virtual void unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer);
    virtual VfxBool isMediaReady(const VcpMenuPos &itemIdx);

    virtual VfxBool canCheckDirty();
    virtual VfxBool checkDirty();

	// set the target folder. default is D:\Photos.
    // this must be called before prepareList().
    void configPath(
            const VfxWString &folderPath,
            const VfxWString *searchPattern = NULL)
    {
        m_folderPath = folderPath;
        if(searchPattern)
        {
            m_searchPattern = *searchPattern;
        }
    }

    // config serch pattern, it will effect ater refresh list next time
    void configSearchPattern(const VfxWString *searchPattern)
    {
        if(searchPattern)
        {
            m_searchPattern = *searchPattern;
            if(!m_searchPattern.isEmpty() && m_fileList)
            {
                m_fileList->configSearchFileDuringPrepare(m_searchPattern);
            }
        }
    }

    // configure custom FMGR_FILTER for finer-grain filter
    void configFileTypeFilter(const FMGR_FILTER *filter);

    // configure specific FMgr sort order
    void configSortMethod(VfxU32 sortMethod);
	// by default, start from 0.
    // but if searchPattern is assigned in configPath(),
    // configured.
    // call this after isPrepared()
    void getStartingIndex(VcpMenuPos &pos);
// wallpaper public interface
public:
	void configWallpaperInfo(IWallpaperSourceStruct *info);
		static void getGroupInfoFromWallpaperInfo(
							const IWallpaperSourceStruct info,	// [IN] the wallpaper info
							VfxS32 &groupCount, 				// [OUT] final group count
							VfxS32 &liveWallpaperId,			// [OUT] group id for live wallpaper
							VfxS32 &staticWallpaperId,			// [OUT] group id for static wallpaper
							VfxS32 &videoWallpaperId			// [OUT] group id for video wallpaper
							);
protected:
    void onStartDecodeAfterFileReady(VcpMenuPos mediaPos, VfxWString &path, VfxS32 queryResult, void* userData);

    // handles video decode result
    void onThumbnailDecodeResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);
	void onFileListReady(VappGalleryPrepareResult prepareResult);

    void onFileListReloadStart(VcpMenuPos mediaPos);
    void onFileListReloadFinished(VcpMenuPos mediaPos);

// Implementation
private:
    void prepareCacheStore();
    void closeCacheStore();
    VappGalleryCacheItemBase* getItem(const VfxId key);
    VappGalleryDecodeResult getThumbImageSrcImpl(VcpMenuPos itemIdx, VfxImageBuffer& buffer);
    void removeCacheItemImpl(const VcpMenuPos index);
	void calcDecodeSize(VfxS32 img_width, VfxS32 img_height, VfxS32 *out_w, VfxS32 *out_h);
// Implementation for Wallpaper
private:
    VfxS32 getWallpaperGroupCount();
    VfxS32 getWallpaperMediaCountInGroup(VfxS32 group);
    void getWallpaperGroupName(const VfxS32 group, VfxWString &groupName);
    VappGalleryDecodeResult getWallpaperMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr);
    VappGalleryMediaGroupType getWallpaperMediaGroupType(const VcpMenuPos &itemIdx);
    // retrieve the original media source.
    VappGalleryDecodeResult getWallpaperMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src);
    // override this for File-based wallpaper case
    VappGalleryDecodeResult getWallpaperMediaPath(const VcpMenuPos &itemIdx, VfxWString &path);
    VappWpResType getWallpaperTypeFromGroupId(VfxS32 group) const;
	
private:
	VfxWString m_folderPath;                // path to folder to scan
    VfxWString m_searchPattern;             // optional search pattern during preparation
    VappGalleryCacheItemBaseType m_cacheType;
    VappGalleryDecoderBase *m_decoder;           // decoder
    VappGalleryFmgrImageList *m_fileList;
    ListEvent m_signalFileListReady;
    ListReloadEvent m_signalFileListReloadStart;
    ListReloadEvent m_signalFileListReloadFinished;
    FMGR_FILTER m_limitFilter;
    VfxU32 m_sortMethod;
    VfxWeakPtr<DecodeJob> m_decodingJob;    // keep tracking to make sure we only have 1 decoding job

    VfxObject *m_cacheStore;
    
    ListEvent m_signalReady;
    ListReloadEvent m_signalReloadStart;
    ListReloadEvent m_signalReloadFinished;
    // for MDI parsing, cache & storage
    VfxBool m_prepared;
    VfxBool m_backgroundMode;       // do not allocate FG memory when in background
    VfxBool m_parsing;              // is underlying MDI calls runnning
    VcpMenuPos m_parsingIndex;      // index of files sent to MDI
    DecodeEvent m_signalDecode;
	/*wallpaper variable*/
	VfxBool m_isWallpaper;
	VfxS32 m_groupCount;
    VfxS32 m_liveWallpaperGroupId;
    VfxS32 m_staticWallpaperGroupId;
    VfxS32 m_videoWallpaperGroupId;
    IWallpaperSourceStruct m_sourceInfo;
};

class VappGalleryFmgrDefaultFolder
{
public:
    enum DEFAULT_FOLDER_TYPE
    {
        MY_SHOOTING,
        MY_VIDEO,
        MY_PICTURE,
        MY_RECEIVED,
    };
    static void getFolderPathFromDrv(
                    U8 drv,                     // [IN] root drive
                    DEFAULT_FOLDER_TYPE type,   // [IN] type of default folder to retrieve
                    VfxWString &path            // [OUT] actual folder path
                    );
};


#if __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__
//////////////////////////////////////////////////////
//  Video Cache Info
//////////////////////////////////////////////////////

/*****************************************************************************
 * Implementation of VappGalleryVideoInfoCacheItem
 *****************************************************************************/
class VappGalleryVideoInfoCacheItem
{
public:
    enum VappGalleryVideoThumbLayout
    {
    #if defined(__MMI_MAINLCD_320X480__)
        VIDEO_THUMB_W = 64,
        VIDEO_THUMB_H = 50,

    #elif defined(__MMI_MAINLCD_480X800__)
        VIDEO_THUMB_W = 110,
        VIDEO_THUMB_H = 85,

    #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        VIDEO_THUMB_W = 60,
        VIDEO_THUMB_H = 46,

    #else
        VIDEO_THUMB_W = 64,
        VIDEO_THUMB_H = 50,
    #endif
    };

    static const VfxS32 NAME_CACHE_LEN = 20;
    static const VfxU32 bufSize = VIDEO_THUMB_W * VIDEO_THUMB_H * VAPP_GALLERY_THUMB_BPP;
    VappGalleryDecodeResult m_result;
    U64 m_durationCache;
    U64 m_bookmarkCache;
    VfxWChar m_nameCache[NAME_CACHE_LEN];
    VfxU8 m_thumbBuffer[bufSize];

public:
    VappGalleryVideoInfoCacheItem():
        m_result(DECODING),
        m_durationCache(0),
        m_bookmarkCache(0)
    {
        m_nameCache[0] = NULL;
    }
    GDI_HANDLE getLayer() const
    {
        GDI_RESULT res = GDI_FAILED;
        GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
        res = gdi_layer_create_cf_using_outside_memory(GALLERY_GDI_CF_THUMB,
                                                       0, 0,
                                                       VIDEO_THUMB_W,
                                                       VIDEO_THUMB_H,
                                                       &thumbLayer,
                                                       (U8*)m_thumbBuffer,
                                                       bufSize);
        VFX_ASSERT(GDI_SUCCEED == res);
        return thumbLayer;
    }

    void getImageBuffer(VfxImageBuffer &thumbBuf) const
    {
        thumbBuf.width = VIDEO_THUMB_W;
        thumbBuf.height = VIDEO_THUMB_H;
        thumbBuf.colorFormat = GALLERY_VRT_CF_THUMB;
        thumbBuf.pitchBytes = VIDEO_THUMB_W * VAPP_GALLERY_THUMB_BPP;
        thumbBuf.ptr = const_cast<VfxU8*>(&m_thumbBuffer[0]);
    }
};
#endif /* __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__ */

//////////////////////////////////////////////////////
//  Decoding thumbnails for image and video
//////////////////////////////////////////////////////
class VappGalleryDecoderBase : public VfxObject
{
    VFX_DECLARE_CLASS(VappGalleryDecoderBase);
public:
    // blocking query of media size
    virtual VfxBool getDimension(const VfxWString &filename, VfxSize &dim){
        return VFX_FALSE;
    }
    virtual VfxBool getDimensionEx(const VfxWString &filename, VfxSize &dim, VfxU16 &srcType){
        return VFX_FALSE;
    }

    // async decode
    virtual void decode(const VfxWString &filename, VfxImageBuffer &thumbBuffer, const VfxRect clipRegion = VfxRect(0,0,0,0), const VfxSize orignalDimension = VfxSize (-1, -1)){};
    virtual void cancel(){};

    typedef VfxSignal2<VappGalleryDecoderBase*, VappGalleryDecodeResult> VappGalleryThumbDecodeSignal;
    virtual VappGalleryThumbDecodeSignal* getReadySignal();

protected:
    static gdi_handle convertImageBufferToLayer(const VfxImageBuffer &imgBuf);
    static VfxBool verifyImageBuffer(const VfxImageBuffer &imgBuf);
};

typedef void (*PFN_GDI_IMGDC_CB)(GDI_RESULT result, gdi_handle handle);
class VappGalleryImageThumbnail : public VappGalleryDecoderBase
{
    VFX_DECLARE_CLASS(VappGalleryImageThumbnail);
public:
    enum
    {
        MAX_GIF_PNG_SUPPORT_DIM = VFX_FRAME_MAX_WIDTH * 2,
    };
public:
    VappGalleryImageThumbnail();
    VappGalleryImageThumbnail(VfxBool isEnhanceDecodeMode);

    virtual void onInit();
    virtual void onDeinit();

    virtual VfxBool getDimension(const VfxWString &filename, VfxSize &dim);
    virtual VfxBool getDimensionEx(const VfxWString &filename, VfxSize &dim, VfxU16 &srcType);

    virtual void decode(const VfxWString &filename,
                        VfxImageBuffer &thumbBuffer,
                        const VfxRect clipRegion = VfxRect(0,0,0,0),
                        const VfxSize orignalDimension = VfxSize (-1, -1));
    virtual void cancel();

    virtual VappGalleryThumbDecodeSignal* getReadySignal();

    // config thumbnail fit mode
    // if APP not specify it, use fit form inside defaultly
    void configThumbFitMode(gdi_util_mode_enum gdiFitMode);  //[IN] gdi_util_mode_enum gdiFitMode

protected:
    void fitThumbImpl(
                const VfxSize originalDim,
                const VfxSize  dstSize,
                VfxRect &clipWindow,
                VfxBool &shouldCleanBlack);
    void fitInsideImpl(
        const VfxSize originalDim,
        const VfxSize  dstSize,
        VfxRect &clipWindow,
        VfxBool &shouldCleanBlack);
    void handleDecodeResult(GDI_RESULT result, gdi_handle handle);

protected:
    static VappGalleryImageThumbnail* g_decodingInst;   // because GDI callback does not carry user data
    static VappGalleryImageThumbnail* g_enhanceDecodingInst;   // because GDI callback does not carry user data
    GDI_HANDLE m_job;          // decoding job
    GDI_HANDLE m_layer;        // decoding layer
    VfxU16 m_imgType;    // GDI image type
    VappGalleryThumbDecodeSignal m_signalResult;    // decode result
    VfxS32 m_thumbFitMode;
    VfxBool m_isEnhanceDecodeMode;

private:
    static void onNormalModeDecodeResult(GDI_RESULT result, gdi_handle handle);
    static void onEnhanceModeDecodeResult(GDI_RESULT result, gdi_handle handle);
    static VappGalleryDecodeResult translateGDIResult(GDI_RESULT result);

};

class VappGalleryVideoThumbnail : public VappGalleryDecoderBase
{
    VFX_DECLARE_CLASS(VappGalleryVideoThumbnail);

public:
    const static VfxMsec SNAPSHOT_TIME = 4000;

    VappGalleryVideoThumbnail();
    virtual void onInit();
    virtual void onDeinit();

    // VappGalleryVideoThumbnail-specific.
    // Default is VFX_TRUE (only get 1st frame of the video)
    void configLiteMemory(VfxBool isLiteMemory);

    // only call this after ready signal is emitted.
    U64 getDecodedDuration();

    virtual VfxBool getDimension(const VfxWString &filename, VfxSize &dim);
    virtual VfxBool getDimensionEx(const VfxWString &filename, VfxSize &dim, VfxU16 &srcType);

    virtual void decode(const VfxWString &filename,
                        VfxImageBuffer &thumbBuffer,
                        const VfxRect clipRegion = VfxRect(0,0,0,0),
                        const VfxSize orignalDimension = VfxSize (-1, -1));
    virtual void cancel();

    virtual VappGalleryThumbDecodeSignal* getReadySignal();

protected:
    // handles MDI video open result
    virtual void handleVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info);

    // handles MDI seek and get frame result
    virtual void handleVideoSeekResult(MDI_RESULT ret);

    // this resets all state variables unconditionally
    void clearState();

    // for decoding video thumbnail with MDI
    mmi_id m_appId;                     // app group id for MDI to allocate memory
    VfxBool m_decoding;                 // is underlying MDI calls runnning
    VfxBool m_videoOpened;              // VFX_TRUE if the video is successfully opened in MDI
    VfxBool m_videoSeeking;             // VFX_TRUE if nonblock_seek is processing
    VfxBool m_isLiteMemoryMode;         // VFX_TRUE makes this decode decode 1st frame only, use less FG memory
    GDI_HANDLE m_decodingLayer;          // gdi handle for video snapshot
    VfxWString m_decodingFile;          // index of files sent to MDI
    VfxImageBuffer m_thumbBuffer;       // output thumbnail buffer
    VappGalleryThumbDecodeSignal m_signalDecode;
    mdi_video_info_struct m_videoInfo;  // The opened(for decoding) video info.

private:
    // MDI callback function
    static void onVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data);
    static void onVideoSeekResult(MDI_RESULT ret, void *user_data);
    static VappGalleryDecodeResult translateMDIResult(MDI_RESULT ret);

    // note MDI get frame utility not supports RGB565 for all chips
    // check and fix color format to avoid mess frame
    void checkSnapshotLayerColorFormat(const gdi_color_format sourceCF, const gdi_color_format targetCF);
};

#ifdef __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__
// support multiple (currently 2) folders to scan videos.
// use MDI and a custom cache manager instead of MediaCache.
class VappGalleryMediaListVideoInfo : public IVappGalleryMediaList
{
public:
    #ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_FOLDER__
    static const VfxS32 MAX_FOLDER_COUNT = 2;
    #else
    static const VfxS32 MAX_FOLDER_COUNT = 1;
    #endif
public:
    typedef VappGalleryCache<VappGalleryVideoInfoCacheItem> VideoInfoCache;
// ctor
public:
    VappGalleryMediaListVideoInfo();

// override VfxObject
public:
    virtual void onInit();
    virtual void onDeinit();

// method
public:
    // configure storage to scan videos.
    // this must be called before prepareList().
    virtual VfxBool configFolderPaths(U8 driveLetter);

    // restrict file type with a FMGR_FILTER.
    // note the result is the intersection of default set and the filter given.
    virtual VfxBool configFileTypeFilter(const FMGR_FILTER *filter);

    // configure an external VappGalleryDB that is used
    // to store video info and thumbnail.
    // this must be called before prepareList().
    virtual void configVideoDB(VappGalleryDB *pDB);

// Implements IVappGalleryMediaList
public:
    virtual void prepareList();
    virtual void release();

    virtual VfxBool isPrepared() const;

    virtual VfxBool isReloading() const
    {
        if(m_fileList)
            return m_fileList->isReloading();
        return VFX_FALSE;
    };

    virtual VfxBool canRefreshList(){
        return VFX_TRUE;
    }

    virtual VfxBool refreshList();

    virtual ListEvent* getListEvent(){
        return &m_signalReady;
    }

    virtual ListReloadEvent* getListReloadStartEvent(){
        return &m_signalReloadStart;
    }

    virtual ListReloadEvent* getListReloadFinishedEvent(){
        return &m_signalReloadFinished;
    }

    virtual DecodeEvent* getDecodeEvent(){
        return &m_signalDecode;
    }

    virtual VfxBool releaseForegroundMemory();
    virtual VfxBool obtainForegroundMemory();

    virtual VfxBool enableBackgroundDecode(VfxBool isEnable);

    virtual VfxS32 getGroupCount();

    virtual VfxS32 getMediaCountInGroup(VfxS32 grpIdx);

    virtual void getGroupName(const VfxS32 group, VfxWString &groupName);

    // always videos
    virtual VappGalleryMediaGroupType getMediaGroupType(const VcpMenuPos &itemIdx){
        return MEDIA_GROUP_VIDEO;
    }

    // name is a really common attribute, so give it a special interface here.
    virtual VappGalleryDecodeResult getMediaName(const VcpMenuPos &itemIdx, VfxWString &nameStr);
    virtual VappGalleryDecodeResult getMediaPath(const VcpMenuPos &itemIdx, VfxWString &path);

    // retrieve the original media source.
    virtual VappGalleryDecodeResult getMediaSource(const VcpMenuPos &itemIdx, VfxImageSrc &src);

    virtual VappGalleryDecodeResult startDecodeThumb(VcpMenuPos itemIdx, VfxImageBuffer& buffer);
    virtual VappGalleryDecodeResult startDecodeThumbEx(VcpMenuPos itemIdx, VfxImageBuffer& buffer, const VfxBool checkMemCacheOnly = VFX_FALSE);
    virtual VappGalleryDecodeResult lockThumb(const VcpMenuPos &itemIdx, VfxImageBuffer& buffer);
    virtual void unlockThumb(const VcpMenuPos &itemIdx, const VfxImageBuffer& buffer);
    virtual VappGalleryDecodeResult getMediaDuration(const VcpMenuPos &itemIdx, U64 &mediaDuration, const VfxBool checkMemCacheOnly = VFX_FALSE);
    virtual VappGalleryDecodeResult getMediaBookmark(const VcpMenuPos &itemIdx, U64 &mediaLastPlay, const VfxBool checkMemCacheOnly = VFX_FALSE);
    virtual VfxBool isMediaReady(const VcpMenuPos &itemIdx);
    virtual VfxBool canCheckDirty();
    virtual VfxBool checkDirty();

    virtual VfxBool canRemoveDBCacheElement();
    virtual VfxBool removeDBCacheElement(VfxWString& filePath);

protected:
    // query Video info from DB
    virtual VfxBool queryMediaInfoFromDB(const VcpMenuPos &itemIdx);

    // if DB entry not found or invalid, start decode with MDI.
    // MDI itself does not providing a job queue.
    virtual VappGalleryDecodeResult startDecodeWithMDI(const VcpMenuPos &itemIdx);

    // handles video decode result
    void onVideoDecodeResult(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result);

private:
    VappGalleryDecodeResult getThumbImageSrcImpl(
        const VcpMenuPos &itemIdx,
        VfxImageBuffer& buffer,
        const VfxBool checkDRM = VFX_FALSE,
        const VfxBool checkMemCacheOnly = VFX_FALSE);

private:
    // for FileMgrSrv file lists
    VappGalleryFmgrList *m_fileList;
    ListEvent m_signalReady;
    ListReloadEvent m_signalReloadStart;
    ListReloadEvent m_signalReloadFinished;

    // for MDI parsing, cache & storage
    mmi_id m_appId;                 // app group id for MDI to allocate memory
    VfxBool m_backgroundMode;       // do not allocate FG memory when in background

    VfxBool m_parsing;              // is underlying MDI calls runnning
    VcpMenuPos m_parsingIndex;      // index of files sent to MDI
    VappGalleryVideoThumbnail *m_videoDecoder;  // used to extract video thumbnail
    VideoInfoCache *m_videoInfoCache;    // resource cache manager
    VappGalleryDB *m_videoDB;                       // video info DB
    DecodeEvent m_signalDecode;

private:
    // for MDI
    static void onVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info, void *user_data);
};
#endif /* __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__ */

class VappGalleryFolderThumbnailDecoderOutputBase : public VfxObject
{
public:
    // total file count in the folder
    virtual void setFileCount(VfxS32 fileCount) = 0;

    // thumbnail buffer count that can be filled by decoder
    virtual VfxS32 getMaxThumbCount() = 0;

    // successfully decoded thumbnail count
    virtual void setDecodedThumbCount(VfxS32 thumbCount) = 0;

    // retrieve a thumbnail buffer for decoder to write
    virtual VfxImageBuffer getImageBuffer(VfxS32 thumbIndex) const = 0;
};

// Cache item in My Picture page,
// this must not be an virtual class since it
// will be placed in continuous cache memory
class VappGalleryFolderInfoCacheItem
{
public:
    static const VfxU32 MAX_THUMB_COUNT = 5;
    static const VfxS32 thumb_w = 50;
    static const VfxS32 thumb_h = 50;
    static const VfxU32 BUF_SIZE_PER_THUMB = thumb_w * thumb_h * VAPP_GALLERY_THUMB_BPP;
    static const VfxU32 BUF_SIZE_TOTAL = BUF_SIZE_PER_THUMB * MAX_THUMB_COUNT;

    U32 m_fileCount;                        // total file count in folder
    U32 m_thumbCount;                       // decoded thumbnail count
    VfxU8 m_thumbBuffer[BUF_SIZE_TOTAL];    // thumbnail buffers

public:
    void clear();

    // total file count in the folder
    void setFileCount(VfxS32 fileCount);

    // thumbnail buffer count that can be filled by decoder
    VfxS32 getMaxThumbCount();

    // successfully decoded thumbnail count
    void setDecodedThumbCount(VfxS32 thumbCount);

    GDI_HANDLE getLayer(VfxS32 thumbIndex) const;

    VfxImageBuffer getImageBuffer(VfxS32 thumbIndex) const;

private:
    U8* getThumbBufferPtr(VfxS32 thumbIndex) const;
};

// this class adapts VappGalleryFolderInfoCacheItem to VappGalleryFolderThumbnailDecoderOutputBase
class VappGalleryMyPictureFolderThumbnailOutput : public VappGalleryFolderThumbnailDecoderOutputBase
{
public:
    VappGalleryMyPictureFolderThumbnailOutput();

    void config(VappGalleryFolderInfoCacheItem *pCacheItem);

    // total file count in the folder
    virtual void setFileCount(VfxS32 fileCount);

    // thumbnail buffer count that can be filled by decoder
    virtual VfxS32 getMaxThumbCount();

    // successfully decoded thumbnail count
    virtual void setDecodedThumbCount(VfxS32 thumbCount);

    // retrieve a thumbnail buffer for decoder to write
    virtual VfxImageBuffer getImageBuffer(VfxS32 thumbIndex) const;

private:
    VappGalleryFolderInfoCacheItem *m_pCacheItem;
};

#ifdef __VAPP_GALLERY_ENABLE_VIDEO_MEDIA_LSIT__
class VappGalleryFolderThumbnailDecoder : public VfxObject
{
public:
    static const VfxU32 MAX_TRY_DECODE_FILE_COUNT = 50;
    typedef VfxSignal2<VappGalleryFolderThumbnailDecoder*, VappGalleryDecodeResult> DecodeSignal;

public:
    VappGalleryFolderThumbnailDecoder();
    virtual void onInit();
    virtual void onDeinit();
public:
    DecodeSignal* getDecodeSignal();

    void config(
            VappGalleryFolderThumbnailDecoderOutputBase *outputItem,
            VappGalleryFmgrList *fileList,
            VappGalleryDB *pDB, 
            U8* resizeWorkingBuf);

    // start decoding thumbnail
    VfxBool start();

    VfxBool cancel();

protected:
    // internal implementation to decode next file
    VfxBool startDecodeNextFile();

    VfxBool needDecodeMoreFile();

    void handleDecodeResult(VappGalleryDecoderBase* sender, VappGalleryDecodeResult result);

    VfxBool getThumbIfCachePresent(
        const VfxWString &path, 
        VfxImageBuffer &thumbBuffer, 
        const VfxBool isVideo, 
        VfxSize originalDim);

    void resizeImageBuf(
        VfxImageBuffer &dstBuffer,     
        VfxImageBuffer &srcBuffer,
        VfxRect &dstRect, 
        VfxRect &srcRect, 
        const VfxS32 bpp);

protected:
    U8* m_decodeResizeWokingBuf;                    // the buffer length is equal to "DB image size * BPP"
    VappGalleryDB *m_pDB;                           // DB used to speed up thumb decoding
    VappGalleryFmgrList *m_fileList;               // list of media files in the folder
    VappGalleryFolderThumbnailDecoderOutputBase *m_outputItem;   // results are writing to this output item. clients should define their own output item.
    VappGalleryDecoderBase *m_thumbDecoder;         // used to decode single image or video file
    VfxS32 m_totalFileInFolder;                     // total file count in folder
    VfxS32 m_decodedFileCount;                      // thumbnail written to m_outputItem
    VfxS32 m_nextFileIndex;                         // index of next file to be decoded
    DecodeSignal m_decodeSignal;                    // emitted when finishing decoding folder thumbnails.
};
#endif

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
class VappGalleryMediaCacheFileSequence : public IVappGalleryFileOperationSequence
{
// Implement IVappGalleryFileOperationSequence
public:
    VappGalleryMediaCacheFileSequence();
    void config(IVappGalleryMediaList *mediaList, const SimpleBitSet *selectionSet);

    // start must be called first, as a preparation.
    // this should also reset the internal iterator position.
    virtual void start();

    // returns all file count, including both video and image
    virtual VfxU32 getTotalCount();

    // imageCount should be filled with image file count
    // videoCount should be filled with video file count.
    virtual VfxBool getCountByType(VfxU32 &imageCount, VfxU32 &videoCount);

    // check if we reach the end of the sequence
    // RETURNS
    //      VFX_TRUE if there are more files in sequence
    virtual VfxBool hasNextPath();

    // advance to next file in sequence
    // RETURNS
    //      VFX_FALSE if the sequence has ended.
    virtual VfxBool getNextPath(VfxWString &filePath);

private:
    VcpMenuPos  m_fileSequenceIndex;  // most recently found index in sequence.
    VfxU32  m_fileSequenceCount;      // total number of selected file in sequence
    VfxBool m_fileSequenceEnded;      // search ended, for quick return of hasNextPath();

    IVappGalleryMediaList *m_mediaList;
    const SimpleBitSet *m_bitset;
};
#endif

class VappGalleryCachedImage : public VfxObject
{
public:
    // for caching thumbnail buffer
    VfxBool m_valid;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxU32 m_bufLen;
    VfxU8* m_bufPtr;
    mmi_id m_appId;

public:
    VappGalleryCachedImage():
        m_valid(VFX_FALSE),
        m_width(0),
        m_height(0),
        m_bufLen(0),
        m_bufPtr(NULL),
        m_appId(0)
    {
    }

    virtual void onDeinit()
    {
        // assert if destroyed without unlocking
        VFX_ASSERT(NULL == m_bufPtr);
        VfxObject::onDeinit();
    }

    void setValid(VfxBool valid)
    {
        m_valid = valid;
    }

    VfxBool isValid()
    {
        return m_valid;
    }

    VfxBool fillImageSrc(VfxImageSrc &imgSrc)
    {
        if(NULL == m_bufPtr)
        {
            imgSrc.setNull();
            return VFX_FALSE;
        }
        VfxImageBuffer imgBuf;
        imgBuf.width = m_width;
        imgBuf.height = m_height;
        imgBuf.pitchBytes = m_width * VAPP_GALLERY_THUMB_BPP;
        imgBuf.ptr = m_bufPtr;
        imgBuf.colorFormat = GALLERY_VRT_CF_THUMB;
        imgSrc.setImageBuffer(imgBuf);
        return VFX_TRUE;
    }

    void lockBuffer(mmi_id appId, VfxS32 w, VfxS32 h)
    {
        VFX_ASSERT(NULL == m_bufPtr);
        if(w)
        {
            m_width = w;
        }
        if(h)
        {
            m_height = h;
        }
        VFX_ASSERT(m_width > 0);
        VFX_ASSERT(m_height > 0);

        m_bufLen = m_width * m_height * VAPP_GALLERY_THUMB_BPP;
        m_appId = appId;
        m_bufPtr = (U8*)applib_asm_alloc_nc_r(m_appId, m_bufLen);

        kal_mem_set(m_bufPtr, 0, m_bufLen);
    }

    void unlockBuffer()
    {
        if(NULL == m_bufPtr)
        {
            return;
        }
        VFX_ASSERT(m_appId);
        applib_asm_free_r(m_appId, m_bufPtr);
        m_bufPtr = NULL;
        m_bufLen = NULL;
    }

    GDI_HANDLE getLayer() const
    {
        GDI_RESULT res = GDI_FAILED;
        GDI_HANDLE thumbLayer = GDI_LAYER_EMPTY_HANDLE;
        res = gdi_layer_create_cf_using_outside_memory(GALLERY_GDI_CF_THUMB,
                                                       0, 0,
                                                       m_width,
                                                       m_height,
                                                       &thumbLayer,
                                                       (U8*)m_bufPtr,
                                                       m_bufLen);
        if(GDI_SUCCEED != res)
        {
            return GDI_LAYER_EMPTY_HANDLE;
        }
        else
        {
            return thumbLayer;
        }
    }
};


#endif /* __VAPP_GALLERY_DATA_H__ */

