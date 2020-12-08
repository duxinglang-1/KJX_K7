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
 *  vapp_gallery_file_operation.h
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

#ifndef __VAPP_GALLERY_FILE_OPERATION_H__
#define __VAPP_GALLERY_FILE_OPERATION_H__
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_weak_ptr.h"
#include "vapp_media_list.h"
#include "vcp_menu_popup.h"

enum VappGalleryFileOpResult
{
    VGFOR_CANCELLED,    // cancelled before start
    VGFOR_DONE,         // finished without error
    VGFOR_ABORTED,      // aborted after start
    VGFOR_ERROR,        // encounter file errors
};

class VappGallerySingleFileMenuPopup : public VcpMenuPopup
{
public:
    VfxWString m_filePath;
};

class VappGalleryFileUtil
{
public:
    static VfxBool isFileExist(const VfxWChar *filePath);
};


// This file sequence support only forward-iteration.
// There is no index for random acess or reverse iteration.
// This interface is used to provide FileOperationUI a way
// to retrieve files one-by-one.
class IVappGalleryFileOperationSequence
{
public:

    // start must be called first, as a preparation.
    // this should also reset the internal iterator position.
    virtual void start() = 0;

    // returns all file count, including both video and image
    virtual VfxU32 getTotalCount() = 0;

    // imageCount should be filled with image file count
    // videoCount should be filled with video file count.
    virtual VfxBool getCountByType(VfxU32 &imageCount, VfxU32 &videoCount) = 0;

    // check if we reach the end of the sequence
    // RETURNS
    //      VFX_TRUE if there are more files in sequence
    virtual VfxBool hasNextPath() = 0;

    // advance to next file in sequence
    // RETURNS
    //      VFX_FALSE if the sequence has ended. 
    virtual VfxBool getNextPath(VfxWString &filePath) = 0;
};

class VappGalleryFileJobContext
{
public:
    VfxS32  m_jobId;
    VfxBool m_abortJob;
    VfxFloat m_unitPerFile;
public:
    void reset();
    VfxBool isValidJob()const;
    VfxBool isAborting()const;
};

class VappGalleryFileOperationBase : public VfxObject
{
public:
    enum WordingHint
    {
        WORDING_VIDEO,    // shows "Videos" e.g. "Delete Videos"
        WORDING_PICTURE,  // shows "Picture" e.g. "Share pictures"
        WORDING_FILE,
    };
// ctor
public:
    VappGalleryFileOperationBase();

// config methods. call before file operation methods.
public:
    // page to show UI on.
    void configParentPage(VfxPage *page);

public:
    // connect to a handler like
    // void YouClass::onFileOperationDone(VfxObject* sender, VappGalleryFileOpResult result)
    VfxSignal2<VfxObject*, VappGalleryFileOpResult> m_signalOperationDone;

    // notify app release to shrink memory
    VfxSignal0 m_signalReleaseResource;

    VfxS32 getMaxBlueToothShareLimit();
    
protected:
    void showDRMErrorPopup(VfxBool isSingle);
    WordingHint getWordingFromFile(const VfxWString &filePath);

// data member
protected:
    VfxPage *m_parentPage;
};

// This class warps FMgrSrv operation
// and displays proper popup UI components on ParentPage configured
class VappGalleryMultiFileOperationUI : public VappGalleryFileOperationBase
{
// ctor
public:
    VappGalleryMultiFileOperationUI();
    virtual void onDeinit();

// config methods. call before file operation methods.
public:
    // set a file sequence
    void configFileSequence(IVappGalleryFileOperationSequence *sequence);

    // VFX_TRUE if want wording to use "photo" instead of "picture"
    void configPhotoWording(VfxBool usePhoto);

    // config medialist in oder to remove cache data in delete operation 
    void configMediaList(IVappGalleryMediaList *mediaList);
    
// file operation methods
public:
    void showDeleteUI();
    void showShareUI(WordingHint wording = WORDING_FILE);
    
protected:
    mmi_ret onProc(mmi_event_struct *param);
    static mmi_ret fileOperationFinishProc(mmi_event_struct *param);

    void startDeleteOperation(const VfxWString &filePath);
    void finishDeleteOperation(VappGalleryFileOpResult res);

    void startBlueToothShareOperation(VfxBool showLimitCheck);

    void onDeleteConfirm(VfxObject* sender, VfxId id);
    void onOverLimitShareConfirm(VfxObject* sender, VfxId id);
    void onCancelFileOperation(VfxObject* sender, VfxFloat curr_progress);

    void removeCacheElementFromDBImpl(VfxWString &path);
protected:
    VfxBool m_usePhotoWording;
    IVappGalleryFileOperationSequence *m_fileSequence;
    VfxWeakPtr<IVappGalleryMediaList> m_mediaList;
    VfxWeakPtr<VcpIndicatorPopup> m_progress;
    VfxWeakPtr<VcpConfirmPopup> m_confirmDelete;
    VfxWeakPtr<VcpConfirmPopup> m_confirmShareOverLimit;
    VappGalleryFileJobContext m_jobContext;  
    VfxWString m_deletingPath;
};


// This class warps FMgrSrv operation for a singal file
// and displays proper popup UI components on ParentPage configured
class VappGallerySingleFileOperationUI : public VappGalleryFileOperationBase
{
// ctor
public:
    VappGallerySingleFileOperationUI();

// override
protected:
    virtual void onInit();
    virtual void onDeinit();

// config methods. call before file operation methods.
public:
    void configFilePath(const VfxWString &filePath);

    // VFX_TRUE if want wording to use "photo" instead of "picture"
    void configPhotoWording(VfxBool usePhoto);
    
    // config medialist in oder to remove cache data in delete operation 
    void configMediaList(IVappGalleryMediaList *mediaList);

// file operation methods
public:
    void showDeleteUI();
    void showShareUI();
    void showSetAsUI();
    
protected:
    mmi_ret onFileOperationFinished(mmi_event_struct *param);
    static mmi_ret fileOperationFinishProc(mmi_event_struct *param);

    void startDeleteOperation(const VfxWString &filePath);
    //void finishDeleteOperation(VappGalleryFileOpResult res);

    void onDeleteConfirm(VfxObject* sender, VfxId id);
    void onShareConfirm(VfxObject* sender, VfxId id);
    void onSetAsConfirm(VfxObject* sender, VfxId id);

    void removeCacheElementFromDBImpl(VfxWString &path);

    // invoke contact set CUI
    void setAsContactImage(const VfxWString &filePath);

    // invoke wallpaper setting CUI
    void setAsWallpaper(VfxId wallpaperType, const VfxWString &filePath);

    // this is a UI flow, and it is in background,
    // so there is no "finish"
    void doBackgroundBlueToothShare(const VfxWString &filePath);

    void launchSNSUploader(const VfxWString &filePath);

    // launch ap, so there is no "finish"
    void launchUnifiedComposer(const VfxWString &filePath);

    // launch ap, so there is no "finish"
    void launchEmail(const VfxWString &filePath);

    // handles underlying CUI events
    // funcptr to generic CUI close function
    typedef void (*PFN_CUI_CLOSE)(mmi_id);
    mmi_ret onCuiEvent(mmi_event_struct *evt);
    static mmi_ret callerProc(mmi_event_struct *evt);
    static void delay_close_cui_func(void *closeFunc, void *cuiId, void *dontCare);
protected:
    VfxBool m_usePhotoWording;
    VfxWString m_filePath;
    VfxWeakPtr<IVappGalleryMediaList> m_mediaList;
    VfxWeakPtr<VcpIndicatorPopup> m_waitPopup;
    VfxWeakPtr<VcpConfirmPopup> m_confirmDelete;
    VfxWeakPtr<VcpCommandPopup> m_shareOptions;
    VfxWeakPtr<VcpCommandPopup> m_setAsOptions;
    VfxS32  m_jobId;
    mmi_id m_appId;     // app group id
    mmi_id m_cuiId;     // current running CUI id
    PFN_CUI_CLOSE m_cuiCloseFunc;  // cui close function for running CUI id
};

#endif // __VAPP_GALLERY_FILE_OPERATION_H__
