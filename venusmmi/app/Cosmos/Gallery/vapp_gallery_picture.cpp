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
 *  vapp_gallery_picture.cpp
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

#ifdef __MMI_FTO_GALLERY__
#include "vapp_media_list.h"
#include "mmi_rp_vapp_gallery_def.h"
#include "vapp_gallery_picture.h"
#include "vapp_gallery_index.h"
#include "vapp_gallery_shooting.h"
#include "vapp_gallery_setting.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_fmgr_table.h"
extern "C"
{
#include "MMI_media_app_trc.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/

// define here since RVCT does not work with const integral values this large.
const VfxS32 VappGalleryFolderCollageButton::MAX_DISPLAY_IMAGE_COUNT = 99999;

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

class MyPictureLayout
{
public:
#if defined(__MMI_MAINLCD_320X480__)
    static const VfxS32 ALL_PIC_BTN_H = 92;
    static const VfxS32 ALL_PIC_LABEL_L = 158;
    static const VfxS32 ALL_PIC_LABEL_T = 16;
    static const VfxS32 ALL_PIC_DESC_T = 51;
    static const VfxS32 ALL_PIC_LABEL_FONT_SIZE = 24;
    static const VfxS32 ALL_PIC_LABEL_FONT_BRIGHTNESS = 21;
    static const VfxS32 ALL_PIC_DESC_FONT_SIZE = 18;
    static const VfxS32 ALL_PIC_DESC_FONT_BRIGHTNESS = 80;
    static const VfxS32 ALL_PIC_COLLAGE_W = 155;
    static const VfxS32 ALL_PIC_COLLAGE_H = 85;
    static const VfxS32 ALL_PIC_COLLAGE_CX = 80;
    static const VfxS32 ALL_PIC_COLLAGE_CY = 45;
    static const VfxS32 FOLDER_VIEW_SHADOW = 48;

#elif defined(__MMI_MAINLCD_480X800__)
    static const VfxS32 ALL_PIC_BTN_H = 135;
    static const VfxS32 ALL_PIC_LABEL_L = 240;
    static const VfxS32 ALL_PIC_LABEL_T = 23;
    static const VfxS32 ALL_PIC_DESC_T = 75;
    static const VfxS32 ALL_PIC_LABEL_FONT_SIZE = 35;
    static const VfxS32 ALL_PIC_LABEL_FONT_BRIGHTNESS = 21;
    static const VfxS32 ALL_PIC_DESC_FONT_SIZE = 26;
    static const VfxS32 ALL_PIC_DESC_FONT_BRIGHTNESS = 80;
    static const VfxS32 ALL_PIC_COLLAGE_W = 210;
    static const VfxS32 ALL_PIC_COLLAGE_H = 124;
    static const VfxS32 ALL_PIC_COLLAGE_CX = 121;
    static const VfxS32 ALL_PIC_COLLAGE_CY = 70;
    static const VfxS32 FOLDER_VIEW_SHADOW = 86;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    static const VfxS32 ALL_PIC_BTN_H = 68;
    static const VfxS32 ALL_PIC_LABEL_L = 120;
    static const VfxS32 ALL_PIC_LABEL_T = 19;
    static const VfxS32 ALL_PIC_DESC_T = 40;
    static const VfxS32 ALL_PIC_LABEL_FONT_SIZE = 18;
    static const VfxS32 ALL_PIC_LABEL_FONT_BRIGHTNESS = 21;
    static const VfxS32 ALL_PIC_DESC_FONT_SIZE = 13;
    static const VfxS32 ALL_PIC_DESC_FONT_BRIGHTNESS = 80;
    static const VfxS32 ALL_PIC_COLLAGE_W = 105;
    static const VfxS32 ALL_PIC_COLLAGE_H = 65;
    static const VfxS32 ALL_PIC_COLLAGE_CX = 60;
    static const VfxS32 ALL_PIC_COLLAGE_CY = 36;
    static const VfxS32 FOLDER_VIEW_SHADOW = 45;

#else
    static const VfxS32 ALL_PIC_BTN_H = 92;
    static const VfxS32 ALL_PIC_LABEL_L = 175;
    static const VfxS32 ALL_PIC_LABEL_T = 16;
    static const VfxS32 ALL_PIC_DESC_T = 51;
    static const VfxS32 ALL_PIC_LABEL_FONT_SIZE = 24;
    static const VfxS32 ALL_PIC_LABEL_FONT_BRIGHTNESS = 21;
    static const VfxS32 ALL_PIC_DESC_FONT_SIZE = 18;
    static const VfxS32 ALL_PIC_DESC_FONT_BRIGHTNESS = 80;
    static const VfxS32 ALL_PIC_COLLAGE_W = 155;
    static const VfxS32 ALL_PIC_COLLAGE_H = 85;
    static const VfxS32 ALL_PIC_COLLAGE_CX = 73;
    static const VfxS32 ALL_PIC_COLLAGE_CY = 45;
    static const VfxS32 FOLDER_VIEW_SHADOW = 48;

#endif
};

const VfxFloat VappGalleryImageCollage::PRESS_DOWN_SCALE = 0.96f;

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryPicturePage", VappGalleryPicturePage, VappGalleryPage);

VappGalleryPicturePage::VappGalleryPicturePage():
	m_imageFileList(NULL),
    m_folderList(NULL),
    m_receivedImageFileList(NULL),
    m_folderViewPanel(NULL),
    m_folderView(NULL),
    m_imageFolderBtn(NULL),
    m_folderThumbDecoder(NULL),
    m_thumbnailData(NULL),
    m_decoderOutput(NULL),
    m_decoderWorkingBuf(NULL)
{
}

void VappGalleryPicturePage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_ON_INIT);
    VappGalleryPage::onInit(); // call base class

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    kal_mem_set(&m_viewState, 0, sizeof(m_viewState));

    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_PICTURE));
    setTopBar(bar);


    showPageWaitIcon(VFX_TRUE);
    m_pDB = NULL;
}

void VappGalleryPicturePage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_ON_DEINIT);
    VFX_OBJ_CLOSE(m_folderView);
    VFX_OBJ_CLOSE(m_folderViewPanel);
    VFX_OBJ_CLOSE(m_imageFolderBtn);
    VFX_OBJ_CLOSE(m_imageFileList);
    VFX_OBJ_CLOSE(m_folderList);
    VFX_OBJ_CLOSE(m_receivedImageFileList);
    VFX_OBJ_CLOSE(m_folderThumbDecoder);
    VFX_OBJ_CLOSE(m_decoderOutput);
    destroyDB();
    VappGalleryPage::onDeinit();
}

void VappGalleryPicturePage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_ON_EXIT);
    // shutdown all background tasks
    if(m_folderView)
    {
        m_folderView->stopUpdate();
        m_folderView->getViewState(&m_viewState);
    }

    VappGalleryPage::onExit(isBackward);
}

void VappGalleryPicturePage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_ON_EXITED);
    // close all components
    VFX_OBJ_CLOSE(m_folderView);
    VFX_OBJ_CLOSE(m_folderViewPanel);
    VFX_OBJ_CLOSE(m_imageFolderBtn);
    VFX_OBJ_CLOSE(m_imageFileList);
    VFX_OBJ_CLOSE(m_folderList);
    VFX_OBJ_CLOSE(m_receivedImageFileList);
    VFX_OBJ_CLOSE(m_folderThumbDecoder);
    VFX_OBJ_CLOSE(m_decoderOutput);
    destroyDB();
    VappGalleryPage::onExited2();

    // release thumbnail cache memory for "Images" button,
    if(m_thumbnailData)
    {
        applib_asm_free_r(getApp()->getGroupId(), m_thumbnailData);
        m_thumbnailData = NULL;
    }
}

void VappGalleryPicturePage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_ON_ENTERED);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    // allocate memory for cache, this is for "Images" button,
    // not for folder view.
    m_thumbnailData = (VappGalleryFolderInfoCacheItem*)applib_asm_alloc_nc_r(getApp()->getGroupId(), sizeof(VappGalleryFolderInfoCacheItem));
    VFX_OBJ_CREATE(m_decoderOutput, VappGalleryMyPictureFolderThumbnailOutput, this);

    // create DB
    setupDB();

    checkUpdate();
    startRefreshUI();
}

void VappGalleryPicturePage::onUpdate()
{
    VappGalleryPage::onUpdate();
}

void VappGalleryPicturePage::startRefreshUI()
{
    // first we start enumerating "Images" button
    if(NULL == m_imageFileList)
    {
        VFX_OBJ_CREATE(m_imageFileList, VappGalleryFmgrImageList, this);
        m_signalImageFileListReady.connect(this, &VappGalleryPicturePage::onImageFileListReady);
        VfxWString rootFolder;
        getRootFolder(rootFolder);
        m_imageFileList->configFolder(rootFolder, &m_signalImageFileListReady);

        // CUI may set custom filter
        VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
        if(cui)
        {
            m_imageFileList->configFileTypeLimit(cui->getTypeFilter());
        }
    }

    m_imageFileList->prepare();

    // after image file list ready, it will trigger subsequent actions.
    // see onImageFileListReady()
}

void VappGalleryPicturePage::createImagesButton()
{
    if(m_imageFolderBtn)
        return;

    // create all pictures button
    VFX_OBJ_CREATE(m_imageFolderBtn, VappGalleryFolderCollageButton, this);
    m_imageFolderBtn->setPos(0, 0);
    m_imageFolderBtn->setSize(getSize().width, MyPictureLayout::ALL_PIC_BTN_H);
    m_imageFolderBtn->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_NONE);
    m_imageFolderBtn->m_signalClicked.connect(this, &VappGalleryPicturePage::onImageFolderBtnClicked);
}

void VappGalleryPicturePage::createFolderListView()
{
    if(m_folderView)
        return;

    if(m_folderViewPanel)
        VFX_OBJ_CLOSE(m_folderViewPanel);
    VFX_OBJ_CREATE(m_folderViewPanel, VfxFrame, this);
    m_folderViewPanel->setPos(0, MyPictureLayout::ALL_PIC_BTN_H);
    m_folderViewPanel->setSize(getSize().width, MyPictureLayout::FOLDER_VIEW_SHADOW);
    m_folderViewPanel->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE);
    m_folderViewPanel->setCacheMode(VFX_CACHE_MODE_FORCE);

    // set background
    VfxImageSrc bgImgSrc(IMG_ID_VAPP_GALLERY_PIC_BG_FOLDER_LIST);
    m_folderViewPanel->setImgContent(bgImgSrc);
    m_folderViewPanel->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // create folder list, but don't start list folder yet.
    // we have to wait for m_imageFolderBtn to be ready.
    VFX_OBJ_CREATE(m_folderView, VappGalleryFolderListView, this);
    m_folderView->setFolderList(m_folderList);
    // CUI may set custom filter
    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    if(cui)
    {
        m_folderView->setFileFilter(cui->getTypeFilter());
    }
    m_folderView->setPos(0, MyPictureLayout::ALL_PIC_BTN_H);
    m_folderView->setSize(getSize().width, getSize().height - MyPictureLayout::ALL_PIC_BTN_H);
    m_folderView->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE);
    m_folderView->m_signalTapped.connect(this, &VappGalleryPicturePage::onFolderTapped);

    // speed up image decode
    m_folderView->configDB(m_pDB, m_decoderWorkingBuf);
}

void VappGalleryPicturePage::onFolderTapped(VfxObject *source, VcpMenuPos pos)
{
    VFX_ASSERT(source == m_folderView);
    VfxWString folderPath;
    VfxWString caption;
    if(m_folderView->getItemPath(pos, folderPath))
    {
        m_folderView->getItemCaption(pos, caption);
        gotoFolderThumbnailPage(folderPath, caption);
    }
}

void VappGalleryPicturePage::onImageFolderBtnClicked(VfxObject* btn, VfxId id)
{
    VfxWString folderPath;
    VfxWString caption;
    getRootFolder(folderPath);
    m_imageFolderBtn->getLabelString(caption);
    gotoFolderThumbnailPage(folderPath, caption);
}

void VappGalleryPicturePage::gotoFolderThumbnailPage(const VfxWString &folder, const VfxWString &caption)
{
    VappGalleryShootingPage *thumbnailPage = NULL;
    VFX_OBJ_CREATE(thumbnailPage, VappGalleryShootingPage, getMainScr());

    // configure source folder and page title
    thumbnailPage->configNoCameraButton(VFX_TRUE);
    thumbnailPage->configCustomFolder(folder, VappGalleryShootingPage::ALLOW_IMAGE);
    thumbnailPage->setCustomTitle(caption);


    // TODO: set DB into thumbnail page if we already initialized DB.

    // goto the page
    getMainScr()->pushPage(PN_MY_SHOOTING, thumbnailPage);
    return;
}

void VappGalleryPicturePage::getRootFolder(VfxWString &path, 
                                           const VappGalleryFmgrDefaultFolder::DEFAULT_FOLDER_TYPE type)
{
    VappGalleryStorageSetting setting;
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
    VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                    defaultDrv,
                                                    type,
                                                    path);
}

void VappGalleryPicturePage::onImageFileListReady(VappGalleryPrepareResult prepareResult)
{

    // update image count first, then trigger
    const VfxU32 imageCount = m_imageFileList->getTotalFileCount();

    if(NULL == m_receivedImageFileList)
    {
        VFX_OBJ_CREATE(m_receivedImageFileList, VappGalleryFmgrImageList, this);
        m_signalReceivedImageFileListReady.connect(this, &VappGalleryPicturePage::onReceivedImageFileListReady);
        VfxWString rootFolder;
        getRootFolder(rootFolder, VappGalleryFmgrDefaultFolder::MY_RECEIVED);
        m_receivedImageFileList->configFolder(rootFolder, &m_signalReceivedImageFileListReady);

        // CUI may set custom filter
        VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
        if(cui)
        {
            m_receivedImageFileList->configFileTypeLimit(cui->getTypeFilter());
        }
    }

    m_receivedImageFileList->prepare();
}

void VappGalleryPicturePage::onReceivedImageFileListReady(VappGalleryPrepareResult prepareResult)
{

    // update image count first, then trigger
    const VfxU32 receivedImageCount = m_receivedImageFileList->getTotalFileCount();

    // after scan all image files, start scan all sub-folders
    if(NULL == m_folderList)
    {
        VFX_OBJ_CREATE(m_folderList, VappGalleryFmgrFolderList, this);
        VappGalleryStorageSetting setting;
        const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
        m_folderList->config(defaultDrv, &m_signalFolderListReady);
        m_signalFolderListReady.connect(this, &VappGalleryPicturePage::onFolderListReady);
    }
    m_folderList->prepare();
}

void VappGalleryPicturePage::onFolderListReady(VappGalleryPrepareResult prepareResult)
{
    showPageWaitIcon(VFX_FALSE);

    VFX_ASSERT(m_imageFileList && m_imageFileList->isPrepared());
    VFX_ASSERT(m_folderList && m_folderList->isPrepared());
    VFX_ASSERT(m_receivedImageFileList && m_receivedImageFileList->isPrepared());
    const VfxS32 imageCount = m_imageFileList->getTotalFileCount();
    const VfxS32 folderCount = m_folderList->getTotalFileCount();
    const VfxU32 receivedImageCount = m_receivedImageFileList->getTotalFileCount();
    if(imageCount <= 0 && folderCount <= 1 && receivedImageCount == 0)
    {
        // got nothing to display, show text message
        setPageMessage(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_PUT_IMG_HINT));
        showPageMessage(VFX_TRUE);
        return;
    }

    // otherwise we start decoding thumbnails
    // and show image buton first.
    createImagesButton();

    // success or not, we start update folder list view
    if(m_folderList->getTotalFileCount() > 0)
    {
        createFolderListView();
        // but, we must make sure folder list does not start scan folders
        // until we finished update image button
        if(m_folderView)
        {
            m_folderView->setForceNoUpdate(VFX_TRUE);
            m_folderView->setViewState(&m_viewState);
        }
    }

    m_imageFolderBtn->setImageCount(imageCount);
    if(NULL == m_folderThumbDecoder)
    {
        VFX_OBJ_CREATE(m_folderThumbDecoder, VappGalleryFolderThumbnailDecoder, this);
        VFX_OBJ_CREATE(m_decoderOutput, VappGalleryMyPictureFolderThumbnailOutput, this);
        m_folderThumbDecoder->getDecodeSignal()->connect(this, &VappGalleryPicturePage::onMyPicturesThumbDecoded);
    }
    m_decoderOutput->config(m_thumbnailData);
    m_folderThumbDecoder->config(m_decoderOutput, m_imageFileList, m_pDB, m_decoderWorkingBuf);
    m_folderThumbDecoder->start();

}

void VappGalleryPicturePage::onMyPicturesThumbDecoded(VappGalleryFolderThumbnailDecoder *source, VappGalleryDecodeResult result)
{
    VFX_UNUSED(source);

    if(OK == result)
    {
        // check the cache does indeed exist,
        // then set the image buffer to the collage thumbnails.
        m_imageFolderBtn->setThumbnailCount(m_thumbnailData->m_thumbCount);
        for(U32 i = 0 ; i < m_thumbnailData->m_thumbCount; ++i)
        {
            VfxImageSrc src;
            src.setImageBuffer(m_thumbnailData->getImageBuffer(i));
            m_imageFolderBtn->setThumbnail(i, src);
        }

        #if !defined(__VAPP_GALLERY_ENABLE_PICTURE_PAGE_ALWAYS_SHOW_IMAGE_BUTTON__)
        // hide folder button
        const VfxBool hidden = (0 == m_thumbnailData->m_fileCount) ? VFX_TRUE : VFX_FALSE; 
        m_imageFolderBtn->setHidden(hidden);

        const VfxS32 x = 0; 
        const VfxS32 y = (hidden) ? 0 : (MyPictureLayout::ALL_PIC_BTN_H);        
        const VfxS32 H = getSize().height - y;
        m_folderViewPanel->setPos(x, y);
        m_folderView->setSize(m_folderView->getSize().width, H);
        m_folderView->setPos(x, y);
        #endif 
    }

    VFX_OBJ_CLOSE(m_folderThumbDecoder);
    VFX_OBJ_CLOSE(m_decoderOutput);
    VFX_OBJ_CLOSE(m_imageFileList);

    if(m_folderView)
    {
        m_folderView->setForceNoUpdate(VFX_FALSE);
        m_folderView->checkUpdate();
    }
}

void VappGalleryPicturePage::setupDB()
{
    // if we want to speed up picture page performance, we can config DB and query DB thumb if thumb exist
    // however it will increase picture page memory usage, i.e file lists + DB + folder cache
    // picker cui will increase its memory if we config DB 
    // app case dose not increate app FG size because it bounds on image viewer or video player FG
    // so we config DB only in app scenario
    const mmi_id appId = findRootAppId(this);
    const VfxBool isGalleryAPP = (appId >= VAPP_GALLERY &&
                                  appId < mmi_res_get_app_max(VAPP_GALLERY));
    const VfxBool isGalleryImageViewerAPP = (appId >= VAPP_GALLERY_IMAGE_VIEWER &&
                                             appId < mmi_res_get_app_max(VAPP_GALLERY_IMAGE_VIEWER));
    if(!isGalleryAPP && !isGalleryImageViewerAPP)
    {
        return;
    }
    
    // setup DB only in app case
    if(NULL == m_pDB)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_SETUP_DB);
        VFX_OBJ_CREATE(m_pDB, VappGalleryDB, this);
    }

    if(NULL == m_decoderWorkingBuf)
    {
        const VfxU32 length = (VappGalleryMediaGridConstant::THUMB_WIDTH / 2 * 2) * 
                              (VappGalleryMediaGridConstant::THUMB_HEIGHT / 2 * 2) *
                              VAPP_GALLERY_THUMB_BPP;
        m_decoderWorkingBuf = (U8*)applib_asm_alloc_nc_r(appId, length);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_SETUP_DB_WORKING_MEM, m_decoderWorkingBuf, appId);
    }
}

void VappGalleryPicturePage::destroyDB()
{
    VFX_OBJ_CLOSE(m_pDB);
    if(m_decoderWorkingBuf)
    {
        const mmi_id appId = findRootAppId(this);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_PICTURE_DESTORY_DB_WORKING_MEM, m_decoderWorkingBuf, appId);

        applib_asm_free_r(appId, m_decoderWorkingBuf);
        m_decoderWorkingBuf = NULL;
    }
}

/*****************************************************************************
 * VappGalleryImageCollage Implementation
 *****************************************************************************/
VappGalleryImageCollage::VappGalleryImageCollage():
    m_activeImageCount(0),
    m_waitIcon(NULL)
{
    for(int i = 0; i < MAX_IMAGE_COUNT; ++i)
    {
        m_images[i] = NULL;
    }
}

void VappGalleryImageCollage::onInit()
{
    VfxFrame::onInit();

    m_activeImageCount = 0;
    setIsCached(VFX_TRUE);
    setAnchor(0.5f, 0.5f);
    setSize(MyPictureLayout::ALL_PIC_COLLAGE_W,
            MyPictureLayout::ALL_PIC_COLLAGE_H);
    // create all cells,
    // note that we reverse creation,
    // since first cell (index 0) is on topmost layer.
    const VfxPoint center(MyPictureLayout::ALL_PIC_COLLAGE_W / 2,
                          MyPictureLayout::ALL_PIC_COLLAGE_H / 2);
    for(int i = 0; i < MAX_IMAGE_COUNT; ++i)
    {
        VappGalleryImageCell *img = NULL;
        VFX_OBJ_CREATE(img, VappGalleryImageCell, this);
        img->setHidden(VFX_FALSE);   // FIXME: change to default hidden
        img->setPos(center);
        m_images[MAX_IMAGE_COUNT - 1 - i] = img;
    }

    showWaitIcon(VFX_TRUE);
}

VfxS32 VappGalleryImageCollage::getActiveImageCount()
{
    return m_activeImageCount;
}

VfxBool VappGalleryImageCollage::setActiveImageCount(VfxS32 activeCount)
{
    // release previous active image count resources
    const VfxImageSrc nullSrc;
    for(int i = activeCount - 1; i < m_activeImageCount && i >= 0; ++i)
    {
        m_images[i]->setThumb(nullSrc);
    }

    m_activeImageCount = activeCount;

    // re-layout immediately
    layoutCollage();
    return VFX_TRUE;
}

void VappGalleryImageCollage::setPressed(VfxBool pressed)
{
    for(int i = 0; i < m_activeImageCount; ++i)
    {
        // set pressed for visible images
        m_images[i]->setPressed(pressed);
    }

    // in pressed state, entire collage is shifted a bit down and smaller
    VfxTransform t = getTransform();
    const VfxFloat scale = pressed ? PRESS_DOWN_SCALE : 1.0f;
    t.data.affine.sx = scale;
    t.data.affine.sy = scale;
    t.data.affine.ty = (VfxFloat)(pressed ? PRESS_DOWN_OFFSET : 0);
    setTransform(t);
}

void VappGalleryImageCollage::showEmptyThumbnail()
{
    VfxImageSrc emptyIcon;
    emptyIcon.setResId(IMG_ID_VAPP_GALLERY_IDX_PICTURE_ICON);
    setThumbnail(0, emptyIcon);
    setActiveImageCount(1);
    m_images[0]->setDefaultIcon();
    showWaitIcon(VFX_FALSE);
}

VfxBool VappGalleryImageCollage::setThumbnail(VfxS32 index, const VfxImageSrc &imgSrc)
{
    if(index < 0 || index >= MAX_IMAGE_COUNT)
    {
        return VFX_FALSE;
    }
    m_images[index]->setThumb(imgSrc);
    return VFX_TRUE;
}

void VappGalleryImageCollage::showWaitIcon(VfxBool bShow)
{
    // change image visibility
    // note we always show the main image (index 0)
    for(int i = 1; i < MAX_IMAGE_COUNT; ++i)
    {
        // do not show image when show wait icon
        // or when the image is not in active images.
        m_images[i]->setHidden(bShow || i >= m_activeImageCount);
    }

    if(!bShow)
    {
        #ifdef __VAPP_GALLERY_ENABLE_IMAGE_COLLECTION_WAITING_ICON__
        if(m_waitIcon)
        {
            m_waitIcon->stop();
            VFX_OBJ_CLOSE(m_waitIcon);
        }
        return;
        #endif
    }
    else
    {
        const VfxS32 width = getSize().width;
        const VfxS32 vertCenter = getSize().height / 2;
        const VfxS32 horzCenter = getSize().width / 2;

        #ifdef __VAPP_GALLERY_ENABLE_IMAGE_COLLECTION_WAITING_ICON__
        if(NULL == m_waitIcon)
        {
            VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
        }
        m_waitIcon->setAnchor(0.5f, 0.5f);
        m_waitIcon->setPos(horzCenter, vertCenter);
        m_waitIcon->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_MID);
        m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
        m_waitIcon->start();
        #endif

        // show main image
        m_images[0]->setPos(horzCenter, vertCenter);
        m_images[0]->setEmptyContent();

    }
}

void VappGalleryImageCollage::layoutCollage()
{
    const VfxS32 imgCount = getActiveImageCount();
    if(imgCount <= 0)
    {
        showWaitIcon(VFX_TRUE);
        return;
    }
    else
    {
        showWaitIcon(VFX_FALSE);
    }

    // otherwise layout the images
    const VfxS32 width = getSize().width;
    const VfxS32 vertCenter = getSize().height / 2;
    const VfxS32 horzCenter = getSize().width / 2;

    // only 1 image case, directly put to center
    // also, all put to center when shrinked
    if(1 == imgCount)
    {
        m_images[0]->setPos(horzCenter, vertCenter);
        return;
    }

    // images should spread around center index.
    // and we want images to distribute evenly in horizontal direction.

    // max spread
    const VfxFloat rotateRatio = 1.2f;  // if a sqare of dimension W, it may occupy W * sqrt(2) after rotation.
    const VfxS32 maxOffset = (VfxS32)((width / 2) - rotateRatio * (VappGalleryImageCell::DEFAULT_DIM_W / 2));
    const VfxFloat offsetBase = (VappGalleryImageCollage::MAX_IMAGE_COUNT - 1) / 2.0f;
    const VfxFloat offsetRatio = static_cast<VfxFloat>(maxOffset) * 1.0f / offsetBase;
    // index distance to center
    const VfxFloat centerIdx = (imgCount - 1.0f) / 2;
    for(VfxS32 i = 0; i < imgCount; ++i)
    {
        const VfxFloat indexDist = i - centerIdx;
        const VfxS32 horzOffset = (VfxS32)(indexDist * offsetRatio);

        // random rotation except first (topmost) image
        if(0 == i)
        {
            m_images[i]->setPos(horzCenter + horzOffset, vertCenter);
        }
        else
        {
            const VfxS32 MAX_DEG = 20;
            const VfxS32 MAX_VERT_OFFSET = 10;
            m_images[i]->setRotation((VfxFloat)(rand() % MAX_DEG));
            m_images[i]->setPos(horzCenter + horzOffset, vertCenter + (rand() % MAX_VERT_OFFSET) - (MAX_VERT_OFFSET / 2));
        }
    }

}

/*****************************************************************************
 * VappGalleryFolderCollage Implementation
 *****************************************************************************/
void VappGalleryFolderCollage::layoutCollage()
{
    const VfxS32 imgCount = getActiveImageCount();
    if(imgCount <= 0)
    {
        showWaitIcon(VFX_TRUE);
        return;
    }
    else
    {
        showWaitIcon(VFX_FALSE);
    }

    const VfxSize selfSize = getSize();
    const VfxS32 vertCenter = selfSize.height / 2;
    const VfxS32 horzCenter = selfSize.width / 2;

    // only 1 image case, directly put to center
    // also, all put to center when shrinked
    if(1 == imgCount)
    {
        for(int i = 0; i < imgCount; ++i)
        {
            m_images[i]->setPos(horzCenter, vertCenter);
        }
        return;
    }

    // images should spread around center index.
    // and we want images to distribute evenly in horizontal direction.
    // Layout in this order: (0 is top most)
    //   3       4      ----> level 2, offset = 2a + rand(b)
    //     1   2        ----> level 1, offset = 1a + rand(b)
    //       0          ----> level 0, offset = 0a + rand(b)
    //                        a is fixed "offset per level"
    //                        b is a small random placement
    const VfxS32 OFFSET_PER_LEVEL = (COLLAGE_W - VappGalleryImageCell::DEFAULT_DIM_W) / MAX_IMAGE_COUNT;
    const VfxS32 MAX_RAND_OFFSET_DIST = COLLAGE_W / MAX_IMAGE_COUNT;
    const VfxS32 MAX_DEG = 20;
    for(int i = 0; i < imgCount; ++i)
    {
        const VfxS32 level = (i + 1) / 2;
        const VfxS32 randHorzOffset = (rand() % MAX_RAND_OFFSET_DIST) - (MAX_RAND_OFFSET_DIST / 2);
        const VfxS32 direction = (i % 2) ? -1 : 1;
        const VfxS32 horzOffset = level * OFFSET_PER_LEVEL * direction + randHorzOffset;
        const VfxS32 vertOffset = (rand() % MAX_RAND_OFFSET_DIST) - (MAX_RAND_OFFSET_DIST / 2);

        m_images[i]->setPos(horzCenter + horzOffset, vertCenter + vertOffset);
        // random rotation except first (topmost) image
        if(0 != i)
        {
            m_images[i]->setRotation((VfxFloat)(rand() % MAX_DEG * direction));
        }
    }
}

/*****************************************************************************
 * VappGalleryImageCell Implementation
 *****************************************************************************/
VappGalleryImageCell::VappGalleryImageCell():
    m_showDefaultIcon(VFX_FALSE),
	m_isPressed(VFX_FALSE)
{

}

void VappGalleryImageCell::onInit()
{
    VfxFrame::onInit();
    setSize(DEFAULT_DIM_W, DEFAULT_DIM_H);  // default to a square image cell
    setAutoAnimate(VFX_TRUE);
    setAnchor(0.5f, 0.5f);  // position & rotation are around center

    VfxTransform t = getTransform();
    t.type = VRT_TRANSFORM_TYPE_AFFINE;
    t.setIdentity();
    setTransform(t);
}

void VappGalleryImageCell::onDraw(VfxDrawContext &dc)
{
    VfxSize s = getSize();
    if(0 == s.width || 0 == s.height)
    {
        return;
    }

    VfxBool drawBorder = VFX_TRUE;

    // draw thubnail
#if defined(__MMI_MAINLCD_480X800__) 
    const VfxS32 shadowEffect = 3;
#else
    const VfxS32 shadowEffect = 1;
#endif
    const VfxS32 x = (s.width  - DEFAILT_THUMB_SIZE) / 2 ;
    const VfxS32 y = (s.height - DEFAILT_THUMB_SIZE - shadowEffect) / 2 ;
    switch (m_thumbImgSrc.getType())
    {
    case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        dc.drawResizedImage(VfxRect(x, y, DEFAILT_THUMB_SIZE, DEFAILT_THUMB_SIZE), m_thumbImgSrc);
        break;
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        drawBorder = VFX_FALSE;
        dc.drawImage(0, 0, m_thumbImgSrc);
        break;
    case VFX_IMAGE_SRC_TYPE_NULL:
    default:
        dc.setFillColor(VfxColor(255, DEFAILT_THUMB_WHITENESS, DEFAILT_THUMB_WHITENESS, DEFAILT_THUMB_WHITENESS));
        dc.fillRect(VfxRect(x, y, DEFAILT_THUMB_SIZE, DEFAILT_THUMB_SIZE));
        break;
    }

    // draw border
    if(drawBorder)
    {
        VfxImageSrc borderImg = (m_isPressed)?
                                VfxImageSrc(IMG_ID_VAPP_GALLERY_PIC_FRAME_DOWN):
                                VfxImageSrc(IMG_ID_VAPP_GALLERY_PIC_FRAME);
        const VfxS32 borderX  = (s.width  - borderImg.getSize().width ) / 2 ;
        const VfxS32 borderY  = (s.height - borderImg.getSize().height) / 2 ;
        dc.drawImage(borderX, borderY, borderImg);
    }
}

void VappGalleryImageCell::setSizeAndThumbSize(
                                    const VfxSize &cellSize,
                                    const VfxSize &thumbSize)
{
    setSize(cellSize);
    invalidate();
}

void VappGalleryImageCell::setBorderIcon()
{
}

void VappGalleryImageCell::setDefaultIcon()
{
    m_thumbImgSrc = VfxImageSrc(IMG_ID_VAPP_GALLERY_IDX_PICTURE_ICON);
    invalidate();
}

void VappGalleryImageCell::setEmptyContent()
{
    m_thumbImgSrc = VfxImageSrc();
}

void VappGalleryImageCell::setPressed(VfxBool pressed)
{
    if(m_showDefaultIcon)
    {
        return;
    }

    m_isPressed = pressed;
    invalidate();
}

void VappGalleryImageCell::setThumb(const VfxImageSrc &src)
{
    m_thumbImgSrc = src;
    invalidate();
}

void VappGalleryImageCell::flashIn()
{
    return;
}

void VappGalleryImageCell::setRotation(const VfxFloat degree)
{
    VfxTransform t = getTransform();
    VFX_ASSERT(t.type == VRT_TRANSFORM_TYPE_AFFINE);
    t.data.affine.rz = VFX_DEG_TO_RAD(degree);
    setTransform(t);
}

/*****************************************************************************
 * VappGalleryFolderCollageButton Implementation
 *****************************************************************************/
VappGalleryFolderCollageButton::VappGalleryFolderCollageButton() :
    m_collage(NULL),
    m_txtDesc(NULL),
    m_imageCount(NULL)
{
}

void VappGalleryFolderCollageButton::onInit()
{
    VcpImageButton::onInit();

    // setup background color and state images
    setBgColor(VFX_COLOR_BLACK);
    const VcpStateImage bg(IMG_ID_VAPP_GALLERY_PIC_BG_ALL_PIC,
                           IMG_ID_VAPP_GALLERY_PIC_BG_ALL_PIC,
                           IMG_ID_VAPP_GALLERY_PIC_BG_ALL_PIC,
                           IMG_ID_VAPP_GALLERY_PIC_BG_ALL_PIC);
    setImage(bg);
    setIsStretchMode(VFX_TRUE);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // create the "Images" label
    // (actual folder path name in file system)
    // it is vertically centered at first.
    m_txtLabel = NULL;
    VFX_OBJ_CREATE(m_txtLabel, VfxTextFrame, this);
    m_txtLabel->setPos(MyPictureLayout::ALL_PIC_LABEL_L,
                       MyPictureLayout::ALL_PIC_BTN_H / 2);
    m_txtLabel->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MyPictureLayout::ALL_PIC_LABEL_FONT_SIZE)));
    m_txtLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_txtLabel->setColor(VFX_COLOR_RES(COR_ID_VAPP_GALLERY_PIC_ALL_PIC_LABEL_FONT_BRIGHTNESS));
    VfxWString label;
    getLabelString(label);
    m_txtLabel->setString(label);
    m_txtLabel->setAutoAnimate(VFX_TRUE);

    // create description label.
    VFX_OBJ_CREATE(m_txtDesc, VfxTextFrame, this);
    m_txtDesc->setPos(MyPictureLayout::ALL_PIC_LABEL_L,
                      MyPictureLayout::ALL_PIC_DESC_T);
    m_txtDesc->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MyPictureLayout::ALL_PIC_DESC_FONT_SIZE)));
    m_txtDesc->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_txtDesc->setColor(VFX_COLOR_RES(COR_ID_VAPP_GALLERY_PIC_ALL_PIC_DESC_FONT_BRIGHTNESS));
    // create collage item
    VFX_OBJ_CREATE(m_collage, VappGalleryImageCollage, this);
    m_collage->setPos(MyPictureLayout::ALL_PIC_COLLAGE_CX,
                      MyPictureLayout::ALL_PIC_COLLAGE_CY);
}

VfxBool VappGalleryFolderCollageButton::onPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        m_collage->setPressed(VFX_TRUE);
        break;
    case VFX_PEN_EVENT_TYPE_UP:
    case VFX_PEN_EVENT_TYPE_ABORT:
        m_collage->setPressed(VFX_FALSE);
        break;
    }

    return VcpImageButton::onPenInput(event);
}

VfxBool VappGalleryFolderCollageButton::getLabelString(VfxWString &labelStr)
{
    // for MAUI_02653795, use resource string instead.
    labelStr = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_PICTURE);
    /*
    // default folder name is "Images\",
    // so we need to remove the backslash
    labelStr = VFX_WSTR_MEM((VfxWChar*)IMAGE_DOWNLOAD_FOLDER_NAME);
    WCHAR *labelBuf = labelStr.lockBuf(labelStr.getLength() + 1);
    srv_fmgr_path_remove_slash(labelBuf);
    labelStr.unlockBuf();
    */
    return VFX_TRUE;
}

void VappGalleryFolderCollageButton::setThumbnailCount(VfxS32 thumbCount)
{

    if(NULL == m_collage)
        return;

    if(0 == thumbCount)
    {
        m_collage->showEmptyThumbnail();
    }
    else
    {
        m_collage->setActiveImageCount(thumbCount);
    }
}

void VappGalleryFolderCollageButton::setThumbnail(VfxS32 index, VfxImageSrc src)
{
    if(NULL == m_collage)
        return;

    m_collage->setThumbnail(index, src);
}

void VappGalleryFolderCollageButton::setImageCount(VfxS32 imageCount)
{
    m_imageCount = imageCount;
    if(0 == m_imageCount)
    {
        m_txtDesc->setHidden(VFX_TRUE);
        m_txtLabel->setPos(MyPictureLayout::ALL_PIC_LABEL_L,
                           (getSize().height / 2) - (MyPictureLayout::ALL_PIC_LABEL_FONT_SIZE / 2));
        if(m_collage)
        {
            m_collage->showEmptyThumbnail();
        }
    }
    else
    {
        // adjust main label position
        m_txtLabel->setPos(MyPictureLayout::ALL_PIC_LABEL_L,
                           MyPictureLayout::ALL_PIC_LABEL_T);

        VfxWString strDesc;
        // at max show 99999
        const VfxS32 displayCount = vfxMin(MAX_DISPLAY_IMAGE_COUNT, m_imageCount);
        strDesc.format("%d  ", displayCount);
        strDesc += VFX_WSTR_RES(displayCount <= 1 ?
                                STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX_SINGLE :
                                STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX);
        m_txtDesc->setString(strDesc);
        m_txtDesc->setHidden(VFX_FALSE);
    }
}

#endif

