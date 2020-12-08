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
 *  vapp_gallery_shooting.h
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

#ifndef __VAPP_GALLERY_SHOOTING_H__
#define __VAPP_GALLERY_SHOOTING_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"
#include "vapp_gallery.h"
#include "vapp_gallery_data.h"
#include "vapp_gallery_file_operation.h"
#include "vcui_gallery_gprot.h"
#include "cp/vapp_media_grid_cp.h"
#include "vfx_weak_ptr.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappMediaGridComponent;
class VappGalleryMediaListMediaCache;
class IVappGalleryMediaList;

class VappGalleryShootingPage : public VappGalleryPage
{
    VFX_DECLARE_CLASS(VappGalleryShootingPage);
    
// Override VfxPage
public:
    VappGalleryShootingPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();
    virtual void onUpdate();
    virtual void onBack();

protected:
    virtual void onPageInactiveImpl();
    virtual void onPageInactived2Impl();

// enum
public:
    enum CustomFolderFilter
    {
        ALLOW_ALL,
        ALLOW_IMAGE,
        ALLOW_VIDEO,
    };

// Method
public:
    // set a specific folder to display image file thumbnails
    // (video files are not displayed)
    void configCustomFolder(const VfxWString &folderPath, CustomFolderFilter filter = ALLOW_ALL);
    
    // setting alternate wallpaper icons to display
    void configWallpaperMode(IWallpaperSourceStruct *sourceInfo);

    // optionally hide camera button in toolbar
    void configNoCameraButton(VfxBool isHideCameraButton);
    
    // config sorting method 
    void configSortMethod(const U32 sortMethod);

    // to update view cell ount 
    void updateViewCellCount(const VfxS32 offset);

protected:

    // initialize media list (backed by FileMgr and MediaCache) and media grid
    void createMediaList();

    // determine which folder to scan
    void getInputFolder(VfxWString &folderPath);

    // create MediaCache-based MediaList.
    VappGalleryMediaListMediaCache *createMediaCacheMediaList();

    // un-initialize media list and media grid
    void closeMediaList();

    // handle media list prepare result
    void onMediaListReady(VappGalleryPrepareResult prepareResult);

    // handle thumbnail tapped on grid
    void onThumbTapped(VcpMenuPos tappedPos, VfxFrame* thumbTapped);

    // handle long pressed event
    void onThumbLongPressed(VcpMenuPos pressedPos);

    // handles toolbar commands (normal state)
    void onToolbarCommand(VfxObject* sender, VfxId id);

    // handles toolbar commands (multi-select state)
    void onToolbarSelectCommand(VfxObject* sender, VfxId id);

    // handles Image Picker CUI command
    void onCuiSelectCommand(VfxObject* sender, VfxId id);

    
    void onShareOperationDone(VfxObject* sender, VappGalleryFileOpResult result);
    void onRequireResourceRelease();
    void onDeleteOperationDone(VfxObject* sender, VappGalleryFileOpResult result);
    // cleanup & refresh state after multi-file operation finished (or cancelled)
    void onFileOperationDone(VfxObject* sender, VappGalleryFileOpResult result, VfxBool refreshList, const VfxBool notifyErrorMessage);

    void onSingleItemMenuCommand(VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item);

    void getButtonNameImageById(VfxId id, VfxWString &name, MMI_IMG_ID &imgId);

    // lazy-create thumbnail grid after media list is ready.
    void createGrid();

    // create ordinary toolbar and set as bottom bar
    void createToolbar(VfxBool cameraOnly = VFX_FALSE);

    // create toolbar for Image Picker CUI (multi-select)
    void createCuiToolbar();

    // create multi-select toolbar and set as bottom bar
    void createSelectToolbar(VfxId mainCommandId);

    // check if 
    VfxBool isSelectOnlyMode() const;

    // check custom filter
    VfxBool isImageOnly();
    
    // launches camera application
    void launchCameraApp();
    // gotoImageViewer, optionally starts slideshow automatically
    void gotoImageViewer(const VcpMenuPos &tappedPos, VfxBool playSlideshow = VFX_FALSE);

    // goto video player page.
    void gotoVideoPlayer(const VcpMenuPos &tappedPos);

// utility functions
public:
    static VfxSize getThumbSize();

private:
    VfxBool m_isHideCameraButton;
    VappMediaGridComponent *m_grid;
    IVappGalleryMediaList *m_mediaList;
    VappGalleryMediaCacheFileSequence m_fileSequence;
    VappGalleryMultiFileOperationUI *m_fileOp;
    VfxWeakPtr<VappGallerySingleFileMenuPopup> m_singleFilePopup;
    
    VfxWString m_customFolderPath;           // allow client to set custom folder path
    CustomFolderFilter m_customFolderFilter; // allow client to set custom file type filter (video only or image only)
    IWallpaperSourceStruct *m_wallpaperInfo; // allow client to set wallpaper source
    VfxU32 m_sortMethod;                     // sort by name in default

    VcpBaseMenuViewState m_viewState; // restore view state after re-enter the page
    VfxS32 m_viewCellCount;    // displays dummy cells for 1st group
};

#endif /* __VAPP_GALLERY_SHOOTING_H__ */

