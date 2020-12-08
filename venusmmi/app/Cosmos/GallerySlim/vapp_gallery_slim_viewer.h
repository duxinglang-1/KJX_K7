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
 *  vapp_gallery_viewer.h
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

#ifndef __VAPP_GALLERY_VIEWER_H__
#define __VAPP_GALLERY_VIEWER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_gallery_slim.h"
#include "vapp_gallery_slim_data.h"
#include "vcp_page_panel.h"
#include "vapp_gallery_slim_setting.h"
#include "cp\vapp_image_viewer_cp.h"
#include "cp\vapp_media_list.h"

extern "C"
{
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "drm_errcode.h"
}

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
//typedef VfxS32 MediaIndex;
//typedef VfxS32 panelID;
//const static MediaIndex INVALID_MEDIA_INDEX = -1;
//class VappGalleryImageDrawer;
class VappImageViewerComponent;
class VappVideoPlayerComponent;
class VappGalleryGestureTranslator;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappGalleryViewerPage : public VappGalleryPage
{
    VFX_DECLARE_CLASS(VappGalleryViewerPage);

    enum PanelPosition
    {
        CURRENT_PANEL,
        LEFT_PANEL,
        RIGHT_PANEL
    };

    enum ImageVerifySize
    {
        VERIFY_DIM = 10,
    };

// ctor
public:
    VappGalleryViewerPage();
    VappGalleryViewerPage(const VfxBool confirmScenario);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onEnter(VfxBool isBack);
    virtual void onEntered();
    virtual void onExit(VfxBool isBack);
    virtual void onExited2();
    
    virtual void onUpdate();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onRotate(const VfxScreenRotateParam &param);

    virtual VfxBool getPageCurrentStorage(U8 &drvLetter);

    void hideAllBars(VfxBool hide); // note: this is NOT a virtual function in VfxPage!

protected:
    virtual void onPageInactiveImpl();
    virtual void onPageInactived2Impl();

// methods
public:
    // this allows Viewer to display image
    // without scanning entire folder. 
    // mainly used for Single Image Viewer CUI
    void configSingleFile(VfxImageSrc src);
    // scan a folder and set first media index in the folder list to display.
    void configFolderAndIndex(const VfxWString &folder, 
                              VfxU32 mediaIndex, 
                              VfxBool imageOnly = VFX_FALSE,
                              VfxBool videoOnly = VFX_FALSE,
                              VfxS32 sortMethod = FS_SORT_NAME,     // refer to fs_gprot.h
                              VfxBool allowEmpty = VFX_FALSE,
                              const FMGR_FILTER *fileFilter = NULL
                              );
    // scan a folder and set filename to be displayed. 
    void configFolderAndFilename(const VfxWString &folder, 
                                 const VfxWString &focusFileName, 
                                 VfxBool imageOnly = VFX_FALSE,
                                 VfxS32 sortMethod = FS_SORT_NAME,   // refer to fs_gprot.h
                                 const FMGR_FILTER *fileFilter = NULL
                                 );

    // special case that display an empty image
    void configEmpty();
    
    // set if client wants to enter slideshow mode once ready
    void configSlideshowAutoStart(VfxBool autoPlaySlideshow);

// Overridable
protected:
    // allow child to change page style
    virtual void setPageStyle();
    // create title bar
    void createTitleBar();
    // create image viewer cp to display image content
    // note user interaction logic relevant to controls is in ViewerPage 
    // viewer cp is resposible to display image/video sequence 
    virtual void initImageViewerCPOption(VappImageViewerComponentOption &option);
    void createImageViewerCP(VappImageViewerComponentOption &option);
    // allow change position of ViewerCP
    virtual void layoutImageViewerCP();
    // override this to change toolbar & handler
    virtual void createToolbar();
    // decide allow hide bars or not
    virtual VfxBool allowHideAllBars();

// event handler
protected:
    // detect hide of the page bars
    virtual void onBarAutoHide();
    // page UI logic handle for viewerCP gesture 
    void onViewerGesture(VappGalleryGesture gesture, VfxS32 currentPreviewIndex);

    // handle media list count/content update
    void onProviderUpdated(const VfxS32 mediaCount);

    // when "current viewing panel" has changed.
    // note the current panel may be empty.
    void onCurrentPanelChanged(const VfxS32 currentIndex);

    // while viewerCP start to display media content
    void onStartDisplayMedia();

    // handle viewer slider event
    void onViewerSliderDragging(VfxBool isDraging);
    
    // handle toolbar commands
    void onToolbarCommand(VfxObject* sender, VfxId btnId);
    void onPlayMedia(VfxWString path);
    void handleFileCommand(VfxId btnId, const VfxWString &path);
    void onEditFile(const VfxWString &path);
    void onDeleteFile(const VfxWString &path);
    VappGallerySingleFileOperationUI* createFileOperator(const VfxWString &path);
    void onDeleteFileFinished(VfxObject *sender, VappGalleryFileOpResult result);
    void onShareFile(const VfxWString &path);
    void onSetFileAs(const VfxWString &path);
    void onShareAndSetAsFileFinished(VfxObject *sender, VappGalleryFileOpResult result);    // handles both share & set as case
    void onRequireResourceRelease();
    void onViewFileInfo(const VfxWString &path);
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    void onPlaySlideshow();
    void onStopSlideshow();
    void onSlideshowStopped();
#endif

// implementations
protected:
    void showEmptyPage();

    void updateZoomSliderByPanel(VappGalleryViewerPanel *panel);
    VfxBool canZoomPanel(VappGalleryViewerPanel *panel);            // returns VFX_TRUE if the panel content can zoom and ready to zoom.

    void updateToolbar();

    // rotate the current image clock-wise 90 degree
    void rotateImagePreview();

    // check if a given path is in My Shooting folder
    VfxBool isFileInMyShootingFolder(const VfxWString &path);
    
protected:
    mmi_ret handlePhotoEditorEvent(mmi_event_struct *evt);
    static mmi_ret onPhotoEditorEvent(mmi_event_struct *evt);

// data member
protected:
    VappImageViewerComponent *m_viewer;

    // background cololr of screen
    VfxColor m_scrBgColor;
    // page title bar
    VcpTitleBar *m_titleBar;
    // (only for QVGA/WQVGA because landscape toolbar is full)
    VcpImageButton *m_editBtn;
    // (only for QVGA/WQVGA because landscape toolbar is full)
    VcpImageButton *m_infoBtn;
    VappGalleryViewerMediaState m_initState;
    // Running file operation
    VappGallerySingleFileOperationUI *m_fileOp;
    // currently focused (active) Panels
    panelID m_currentPanel;
    // user-overridden title bar text
    VfxWString m_customTitle;
    // records current page orientation (NOT image rotation)
    VfxScrRotateTypeEnum m_pageOrientation;
    // for launching ImageEditor CUI
    mmi_id m_editorCuiId;
    // for multitouch gesture support
    VfxBool m_isMultiTouchMode;
    VfxBool m_multiTouchZoomGesture;
};

class VappGalleryWallpaperPreviewPage : public VappGalleryViewerPage
{
public:
    VappGalleryWallpaperPreviewPage();

public:
    virtual void setBounds(const VfxRect &value);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onEnter(VfxBool isBack);
    virtual void onEntered();
    virtual void onExit(VfxBool isBack);
    virtual void onExited2();

public:
    void setWallpaperSource(IWallpaperSourceStruct *sourceInfo);
    void setSelectedWallpaper(VappWpResType wallpaperType, VfxS32 indexSelected);

protected:
    // override toolbar options & handlers
    virtual void createToolbar();
    // override to force title bar caption
    // VFX_TRUE means there is a custom title,
    // VFX_FALSE means using default title behavior
    virtual VfxBool getCustomTitle(VfxWString &title){return VFX_FALSE;};

    virtual void setPageStyle();

    virtual VfxBool allowHideAllBars();

    virtual void initImageViewerCPOption(VappImageViewerComponentOption &option);
    virtual void layoutImageViewerCP();

    // override, since WallpaperPreivew shold not allow rotation.
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    void createWallpaperFrameFromInfo();
    void setOKButtonEnabled(VfxBool enabled);
    void onDelayPlay(VfxTimer *sender);
    void onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result);
    void onVideoFinished(VappVideoPlayerComponent *sender, MDI_RESULT result);

    static mmi_ret onEvent(mmi_event_struct *param);

private:
    void onToolbarCommand(VfxObject* sender, VfxId btnId);
    IWallpaperSourceStruct *m_wallpaperInfo;
    VappWpResType m_wallpaperType;
    VfxS32 m_indexSelected;
    VfxBool m_isEntered;                    // is page in Entered state (FG available)
    VfxFrame *m_activeLiveWallpaper;        // may be live wallpaper or video frame
};

/***************************************************************************** 
 * Image Info
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
class VappGalleryMediaInfoParser
{
public:
    VappGalleryMediaInfoParser();
    void parseFile(const VfxWString &filename);
    void insertInfoItems(VcpForm *form);
private:
    void addResultItem(VcpForm *form, VfxId &itemId, const VfxWString &title, const VfxWString &desc);
private:
    VfxBool m_fileInfoReady;
    VfxBool m_jpegInfoReady;
    VfxS32 m_imageWidth;
    VfxS32 m_imageHeight;
    srv_fmgr_fileinfo_struct m_fileInfo;
    gdi_image_jpeg_exif_info_struct m_jpegInfo;
    
};

class VappGalleryMediaInfoCell : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappGalleryMediaInfoCell);
public:
    VappGalleryMediaInfoCell();
public:
    void setTitleText(const VfxWString &text);
    void setDescText(const VfxWString &text);

protected:
    virtual void onInit();

// Implementation
private:
    enum
    {
#if defined(__MMI_MAINLCD_480X800__)
        TITLE_FONT_SIZE = 30,
        DESC_FONT_SIZE = 26,
        MARGIN_X    = 14,
        TAIL_GAP   = 18,

#elif defined(__MMI_MAINLCD_320X480__)
        TITLE_FONT_SIZE = 20,
        DESC_FONT_SIZE = 16,
        MARGIN_X    = 8,
        TAIL_GAP   = 10,

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        TITLE_FONT_SIZE = 16,
        DESC_FONT_SIZE = 14,
        MARGIN_X    = 5,
        TAIL_GAP   = 6,

#else
        TITLE_FONT_SIZE = 16,
        DESC_FONT_SIZE = 14,
        MARGIN_X    = 5,
        TAIL_GAP   = 6,

#endif
        // these are resolution-independent
        TITLE_FONT_WHITENESS = 21,
        DESC_FONT_WHITENESS = 80,
        ITEM_WIDTH  = GDI_LCD_WIDTH - MARGIN_X * 2,
    };

    VfxTextFrame *m_title;
    VfxTextFrame *m_desc;
};

class VappGalleryMediaInfoPage : public VfxPage
{
// Override
public:
    VappGalleryMediaInfoPage();
    virtual void onInit();

// method
public:
    void setFile(const VfxWString &filename);
private:
    VcpForm *m_infoView;
};

#endif // __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__

#endif /* __VAPP_GALLERY_VIEWER_H__ */

