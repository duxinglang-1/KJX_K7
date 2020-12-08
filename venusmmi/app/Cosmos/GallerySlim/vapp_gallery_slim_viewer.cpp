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
 *  vapp_gallery_viewer.cpp
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

extern "C"
{
#include "gdi_include.h"
#include "gdi_linear_transform.h"
#include "gdi_layer.h"
#include "cache_sw.h"
#include "iul_spatial_dithering.h"
#include "custom_scatstruct.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"

#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#include "RightsMgrGProt.h"
#include "Drm_errcode.h"
#endif
#include "mmi_rp_vapp_gallery_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_slider_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
}
#include "vapp_gallery_slim_viewer.h"
#include "vapp_gallery_slim_shooting.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_list_menu.h"
#include "vcp_text_view.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

#include "vcui_gallery_gprot.h"
#include "vapp_gallery_slim.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_util.h"
#include "vapp_gallery_slim_setting.h"
#include "vapp_gallery_slim_index.h"
#include "vfx_owner_draw.h"

#include "vapp_wallpaper.h"
#include "cp\vapp_video_player_cp.h"

#include "FileMgrServiceResDef.h"
#include "kal_trace.h"

#ifdef __MMI_COSMOS_PHOTOEDITOR__
#define __GALLERY_PHOTO_EDIT__
#else
#undef __GALLERY_PHOTO_EDIT__
#endif

#ifdef __GALLERY_PHOTO_EDIT__
#include "vapp_imgedt_gprot.h"
#endif

extern "C"
{
#include "MMI_media_app_trc.h"
}

/*****************************************************************************
 * Typedef
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
enum VappGalleryViewerPageLayout
{
    EDIT_BTN_LEFT = 0,
    EDIT_BTN_TOP = 0,
    INFO_BTN_LEFT = 0,
    INFO_BTN_TOP = 0
};
#elif defined(__MMI_MAINLCD_480X800__)
enum VappGalleryViewerPageLayout
{
    EDIT_BTN_LEFT = 0,
    EDIT_BTN_TOP = 0,
    INFO_BTN_LEFT = 0,
    INFO_BTN_TOP = 0
};
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
enum VappGalleryViewerPageLayout
{
    EDIT_BTN_LEFT = 8,
    EDIT_BTN_TOP = 50,
    INFO_BTN_LEFT = 205,
    INFO_BTN_TOP = 50
};
#else
enum VappGalleryViewerPageLayout
{
    EDIT_BTN_LEFT = 8,
    EDIT_BTN_TOP = 53,
    INFO_BTN_LEFT = 205,
    INFO_BTN_TOP = 53
};

#endif

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryViewerPage", VappGalleryViewerPage, VappGalleryPage);
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
VFX_IMPLEMENT_CLASS("VappGalleryMediaInfoCell", VappGalleryMediaInfoCell, VcpFormItemBase);
#endif
/*****************************************************************************
 * VappGalleryViewerPage Implementation
 *****************************************************************************/
VappGalleryViewerPage::VappGalleryViewerPage():
    m_viewer(NULL),
    m_scrBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN)),
    m_titleBar(NULL),
    m_editBtn(NULL),
    m_infoBtn(NULL),
    m_fileOp(NULL),
    m_pageOrientation(VFX_SCR_ROTATE_TYPE_NORMAL),
    m_editorCuiId(NULL),
    m_isMultiTouchMode(VFX_FALSE),
    m_multiTouchZoomGesture(VFX_FALSE)
{
}

VappGalleryViewerPage::VappGalleryViewerPage(const VfxBool confirmScenario):
    m_viewer(NULL),
    m_scrBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN)),
    m_titleBar(NULL),
    m_editBtn(NULL),
    m_infoBtn(NULL),
    m_fileOp(NULL),
    m_pageOrientation(VFX_SCR_ROTATE_TYPE_NORMAL),
    m_editorCuiId(NULL),
    m_isMultiTouchMode(VFX_FALSE),
    m_multiTouchZoomGesture(VFX_FALSE)
{
    m_initState.m_confirmScenario = confirmScenario;
}

void VappGalleryViewerPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_INIT);
    VappGalleryPage::onInit();

    // create UI style
    setPageStyle();
    createTitleBar();

    // create image viewer cp
    VappImageViewerComponentOption option;
    initImageViewerCPOption(option);
    createImageViewerCP(option);
    layoutImageViewerCP();

    // may be overridden
    createToolbar();
}

void VappGalleryViewerPage::setPageStyle()
{
    // Image Viewer is a black-style UI
    // set page style (translucent)
    setTranslucent(VFX_TRUE);
    setBarAutoHide(VFX_TRUE);
    setBgColor(VFX_COLOR_BLACK);
}

void VappGalleryViewerPage::createTitleBar()
{
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_NULL);
    setTopBar(m_titleBar);
}

void VappGalleryViewerPage::initImageViewerCPOption(VappImageViewerComponentOption &option)
{
    option.supportMultiTouch = VFX_TRUE;
    option.supportZoom = VFX_TRUE;
    option.isSyncContentProvider = VFX_TRUE;
}

void VappGalleryViewerPage::createImageViewerCP(VappImageViewerComponentOption &option)
{
    VFX_OBJ_CLOSE(m_viewer);
    VFX_OBJ_CREATE_EX(m_viewer, VappImageViewerComponent, this, (option));
    m_viewer->setSize(getSize());
    m_viewer->setPos(0, 0);
    m_viewer->setFocused(VFX_TRUE);

    // register signal
    m_viewer->getGestureEvent()->connect(this, &VappGalleryViewerPage::onViewerGesture);
    m_viewer->getMediaPlayCommandEvent()->connect(this, &VappGalleryViewerPage::onPlayMedia);
    m_viewer->getStartDisplayMediaEvent()->connect(this, &VappGalleryViewerPage::onStartDisplayMedia);
    m_viewer->getCurrentPanelChangedEvent()->connect(this, &VappGalleryViewerPage::onCurrentPanelChanged);

//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
    m_viewer->getZoomSliderEvent()->connect(this, &VappGalleryViewerPage::onViewerSliderDragging);
#endif

    m_viewer->getViewSliderEvent()->connect(this, &VappGalleryViewerPage::onViewerSliderDragging);
}

void VappGalleryViewerPage::layoutImageViewerCP()
{
    m_viewer->setSize(getSize());
    m_viewer->setPos(0, 0);
    m_viewer->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);
}

VfxBool VappGalleryViewerPage::allowHideAllBars()
{
    return VFX_TRUE;
}

void VappGalleryViewerPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_DEINIT);

    VFX_OBJ_CLOSE(m_viewer);
    VFX_OBJ_CLOSE(m_fileOp);

#ifdef __GALLERY_PHOTO_EDIT__
    if(m_editorCuiId)
    {
        // unregister caller proc
        mmi_frm_group_set_caller_proc(m_editorCuiId, NULL, NULL);
        m_editorCuiId = NULL;
    }
#endif

    VappGalleryPage::onDeinit();
}
// TODO: check the event sequence of back event, current page onDeinit and exist
void VappGalleryViewerPage::onBack()
{
    if(m_viewer && m_viewer->handleBack())
    {
        // not to process back key event
        return;
    }
    return VappGalleryPage::onBack();
}

void VappGalleryViewerPage::createToolbar()
{
    // check full-app case or Image Viewer CUI case
    VcuiGalleryImageViewer *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryImageViewer);

    // in ImageViewer CUI, there is no toolbar.
    if(cui)
    {
        return;
    }
    if(m_initState.m_confirmScenario)
    {
        // Wallpaper preview have only 2 options.
        VcpToolBar *tbar = NULL;
        VFX_OBJ_CREATE(tbar, VcpToolBar, this);
        tbar->addItem('BACK', VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
        tbar->addItem('DELE', VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        tbar->m_signalButtonTap.connect(this, &VappGalleryViewerPage::onToolbarCommand);
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, tbar, VFX_TRUE);
        return;
    }

    VcpToolBar *tbar = NULL;
    VFX_OBJ_CREATE(tbar, VcpToolBar, this);

    VfxBool separateEditInfoButtons = VFX_FALSE;
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    separateEditInfoButtons = VFX_TRUE;
#endif

    VfxBool hasEditButton = VFX_FALSE;
#ifdef __GALLERY_PHOTO_EDIT__
    hasEditButton = VFX_TRUE;
#endif

    VFX_ASSERT(NULL == cui);
    // full-app case
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    tbar->addItem('PLAY', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_PLAY_SLIDESHOW), IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_SLIDESHOW);
#endif
    tbar->addItem('ROTA', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_ROTATE), IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_ROTATE);
    tbar->addItem('DELE', VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

    if(!separateEditInfoButtons && hasEditButton)
    {
        tbar->addItem('EDIT', VFX_WSTR_RES(VCP_STR_TOOL_BAR_EDIT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    }

    tbar->addItem('SETA', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_SET_AS), IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_SET_AS);
    tbar->addItem('SHAR', VFX_WSTR_RES(VCP_STR_TOOL_BAR_SHARE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
    if(!separateEditInfoButtons)
    {
        tbar->addItem('INFO', VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_DETAIL), IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_INFO);
    }
#endif

    if(separateEditInfoButtons)
    {
#ifdef __GALLERY_PHOTO_EDIT__
        // create image button on the page
        // we remember m_editBtn to disable it later
        if(hasEditButton && NULL == m_editBtn)
        {
            VFX_ASSERT(NULL == m_editBtn);
            VFX_OBJ_CREATE(m_editBtn, VcpImageButton, this);
            VcpStateImage editBtnImg(IMG_ID_VAPP_GALLERY_IMG_BTN_EDIT,
                                     IMG_ID_VAPP_GALLERY_IMG_BTN_EDIT,
                                     IMG_ID_VAPP_GALLERY_IMG_BTN_EDIT_DISABLED,
                                     IMG_ID_VAPP_GALLERY_IMG_BTN_EDIT);
            m_editBtn->setImage(editBtnImg);
            m_editBtn->setSize(editBtnImg.getImageNormal().getSize());
            m_editBtn->setEffectSize(VfxSize(56, 56));
            m_editBtn->setIsEffect(VFX_TRUE);
            m_editBtn->setPos(EDIT_BTN_LEFT, EDIT_BTN_TOP);
            m_editBtn->setId('EDIT');
            m_editBtn->setHidden(VFX_TRUE);
            m_editBtn->m_signalClicked.connect(this, &VappGalleryViewerPage::onToolbarCommand);
            m_editBtn->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                      VFX_FRAME_ALIGNER_MODE_SIDE,
                                      VFX_FRAME_ALIGNER_MODE_NONE,
                                      VFX_FRAME_ALIGNER_MODE_NONE);
        }
#endif
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
        if(NULL == m_infoBtn)
        {
            VFX_OBJ_CREATE(m_infoBtn, VcpImageButton, this);
            VcpStateImage infoBtnImg(IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_INFO,
                                     IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_INFO,
                                     IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_INFO,
                                     IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_INFO);
            m_infoBtn->setImage(infoBtnImg);
            m_infoBtn->setSize(infoBtnImg.getImageNormal().getSize());
            m_infoBtn->setEffectSize(VfxSize(56, 56));
            m_infoBtn->setIsEffect(VFX_TRUE);
            m_infoBtn->setPos(INFO_BTN_LEFT, INFO_BTN_TOP);
            m_infoBtn->setId('INFO');
            m_infoBtn->setHidden(VFX_TRUE);
            m_infoBtn->m_signalClicked.connect(this, &VappGalleryViewerPage::onToolbarCommand);
            m_infoBtn->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                      VFX_FRAME_ALIGNER_MODE_SIDE,
                                      VFX_FRAME_ALIGNER_MODE_SIDE,
                                      VFX_FRAME_ALIGNER_MODE_NONE);
        }
#endif
    }
    tbar->m_signalButtonTap.connect(this, &VappGalleryViewerPage::onToolbarCommand);
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, tbar, VFX_TRUE);
    // by default, do not should toolbar until file list is ready
    toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
}

void VappGalleryViewerPage::hideAllBars(VfxBool hide)
{
    if(!allowHideAllBars() && hide)
    {
        return;
    }

    VappGalleryPage::hideAllBars(hide);
    // hide case, onBarAutoHide() would be triggered
    // but in unhide case, we need to reveal zoom slider manually
    if(!hide)
    {
        showFrameImmediately(m_editBtn);
        showFrameImmediately(m_infoBtn);

        if(m_viewer)
        {
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
            showFrameImmediately(m_viewer->getZoomOutLabel());
            showFrameImmediately(m_viewer->getZoomInLabel());
            showFrameImmediately(m_viewer->getZoomSlider());
            showFrameImmediately(m_viewer->getViewSlider());
#endif

            showFrameImmediately(m_viewer->getViewPrevLabel());
            showFrameImmediately(m_viewer->getViewNextLabel());
            showFrameImmediately(m_viewer->getMavIconFrame());
            showFrameImmediately(m_viewer->get3DRedBlueIcon());
        }
    }
}

void VappGalleryViewerPage::onBarAutoHide()
{
    hideFrameAnimated(m_editBtn);
    hideFrameAnimated(m_infoBtn);
    if(m_viewer)
    {
//use compile option to remove zoom in/out code 2012-11-19
#ifdef __VAPP_GALLERY_IMAGE_VIEW_ENABLE_ZOOM__
        hideFrameAnimated(m_viewer->getZoomOutLabel());
        hideFrameAnimated(m_viewer->getZoomInLabel());
        hideFrameAnimated(m_viewer->getZoomSlider());
        hideFrameAnimated(m_viewer->getViewSlider());
#endif
        hideFrameAnimated(m_viewer->getViewPrevLabel());
        hideFrameAnimated(m_viewer->getViewNextLabel());
        hideFrameAnimated(m_viewer->getMavIconFrame());
        hideFrameAnimated(m_viewer->get3DRedBlueIcon());
    }
}

void VappGalleryViewerPage::onEnter(VfxBool isBack)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_ENTER);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        // still draw bar in small screen redraw
        hideAllBars(VFX_FALSE);
        return;
    }

    GALLERY_MEASURE_TIME_START("AVP");
    VappGalleryPage::onEnter(isBack);

    const VfxBool blockRefresh = (NULL != m_fileOp)? VFX_TRUE : VFX_FALSE;
    if(m_viewer)
    {
        // connect provider updated handler
        m_viewer->getProviderUpdatedEvent()->connect(this, &VappGalleryViewerPage::onProviderUpdated);
        m_viewer->handleEnter(blockRefresh, m_initState);
    }

    // according to spec, bars are initially visible
    hideAllBars(VFX_FALSE);
    GALLERY_MEASURE_TIME_STOP("AVP");
}

void VappGalleryViewerPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_ENTERED);
    VappGalleryPage::onEntered();

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    GALLERY_MEASURE_TIME_START("AVE");
    VfxMainScr *pScr = getMainScr();
    if(pScr)
    {
        m_scrBgColor = pScr->getBgColor();
        pScr->setBgColor(VFX_COLOR_BLACK);
    }

	// enable gdi mm color engine
#if defined GDI_COLORENGINE_SUPPORT
	gdi_color_engine_open();
	gdi_color_engine_enable();
#endif

    const VfxBool blockRefresh = (NULL != m_fileOp)? VFX_TRUE : VFX_FALSE;
    if(m_viewer)
    {
        m_viewer->handleEntered(blockRefresh);
    }

    checkUpdate();

    GALLERY_MEASURE_TIME_STOP("AVE");
    // according to spec, bars are initially visible
    hideAllBars(VFX_FALSE);
    return;
}

void VappGalleryViewerPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_EXIT);

    // recover screen bg color
    VfxMainScr *pScr = getMainScr();
    if(pScr)
    {
        pScr->setBgColor(m_scrBgColor);
    }

    onPageInactiveImpl();

    VappGalleryPage::onExit(isBackward);
}

void VappGalleryViewerPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_EXITED2);

    onPageInactived2Impl();

    const VfxBool releaseForegroundOnly = isActive();
	
	// disable gdi mm color engine
#if defined GDI_COLORENGINE_SUPPORT
	gdi_color_engine_disable();
	gdi_color_engine_close();
#endif

    // close UI
    if(!releaseForegroundOnly)
    {
        VFX_OBJ_CLOSE(m_fileOp);
    }

    VappGalleryPage::onExited2();
    return;
}

void VappGalleryViewerPage::onPageInactiveImpl()
{
    if(m_viewer)
        m_viewer->handleExit();
}

void VappGalleryViewerPage::onPageInactived2Impl()
{
    const VfxBool releaseForegroundOnly = isActive();
    if(m_viewer)
    {
        m_viewer->handleExited2(releaseForegroundOnly);
        m_initState = m_viewer->getInitState();
    }
}

void VappGalleryViewerPage::onRotate(const VfxScreenRotateParam &param)
{
    // Rotation of entire page (Landscape mode/Portrait mode)
    // this is NOT image rotate (tap "rotate toolbar)
    VfxPageBar *pbar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    if(pbar)
    {
        VcpToolBar *tbar = VFX_OBJ_DYNAMIC_CAST(pbar, VcpToolBar);
        if(tbar)
        {
            tbar->setLayout(param.rotateTo);
        }
    }

    if(m_viewer)
    {
        m_viewer->handleRotate();
    }
    return VappGalleryPage::onRotate(param);
}

void VappGalleryViewerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    // same orientation case
    if(param.rotateTo == param.rotateFrom)
    {
        m_pageOrientation = param.rotateTo;
        return;
    }

#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    // do not allow orientation change when playing slideshow.
    if(m_viewer && m_viewer->isPlayingSlideshow())
    {
        // disable rotation animation
        param.durTime = 0;

        VfxBool hasLimitation = VFX_FALSE;
        VfxScrRotateTypeEnum slideshowOrientation = VFX_SCR_ROTATE_TYPE_NORMAL;
        if(m_viewer->getSlideshowOrientationLimit(hasLimitation, slideshowOrientation) && hasLimitation)
        {
            // force set to slideshow limited orientation
            param.rotateTo = slideshowOrientation;
        }
        else
        {
            param.rotateTo = param.rotateFrom;
        }
    }
#endif

    // Viewer nor Slideshow does not support 180
    if(param.rotateTo == VFX_SCR_ROTATE_TYPE_180)
    {
        // we keep original orientation
        param.rotateTo = param.rotateFrom;
    }

    // view panel are auto-updated by processing onBoundsChange
    m_pageOrientation = param.rotateTo;
}

void VappGalleryViewerPage::onPlayMedia(VfxWString path)
{
    // launch video player when video thumb is tapped
    VappGalleryPlayerPage *playerPage = NULL;
    VFX_OBJ_CREATE(playerPage, VappGalleryPlayerPage, getMainScr());
    playerPage->setLocalFile(path);

    // config page rotaion
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxScrRotateTypeEnum screenRotation = renderer->getScreenRotateType();
    playerPage->configPageRotation(screenRotation);

    // show player page
    getMainScr()->pushPage(0, playerPage);
}

void VappGalleryViewerPage::onToolbarCommand(VfxObject* sender, VfxId btnId)
{
    if(NULL == m_viewer){return;}

    // keep the bar visible
    hideAllBars(VFX_FALSE);

    switch(btnId)
    {
    // list-based operations
    #ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
    case 'PLAY':
        onPlaySlideshow();
        break;
    #endif
    case 'ROTA':
        rotateImagePreview();
        break;

    // file-based operations
    case 'DELE':
    case 'EDIT':
    case 'SETA':
    case 'SHAR':
    case 'INFO':
        {
            VfxWString path;
            VappGalleryDecodeResult res = m_viewer->getCurrentMediaPath(path);
            if(OK == res)
            {
                handleFileCommand(btnId, path);
            }
            else if(PATH_TOO_DEEP == res)
            {
                VcpConfirmPopup *popup = NULL;
                VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
                popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                popup->setAutoDestory(VFX_TRUE);
                VfxId errStrId = srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR);
                popup->setText(VFX_WSTR_RES(errStrId));
                popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                popup->show(VFX_TRUE);
                return;
            }
            else
            {
                // some other error
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_TOOLBAR_COMMAND_NO_VALID_FILE_PATH);
                return;
            }
        }
        break;
    case 'BACK':
        getMainScr()->popPage();
        break;
    default:
        // unrecognized command, why?
        VFX_DEV_ASSERT(0);
        break;
    }
}

void VappGalleryViewerPage::rotateImagePreview()
{
    if(m_viewer)
        m_viewer->rotateImagePreview();
}

void VappGalleryViewerPage::handleFileCommand(VfxId btnId, const VfxWString &path)
{
    switch(btnId)
    {
    case 'DELE':
        onDeleteFile(path);
        break;
    case 'SHAR':
        onShareFile(path);
        break;
    case 'SETA':
        onSetFileAs(path);
        break;
    case 'EDIT':
        onEditFile(path);
        break;
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
    case 'INFO':
        onViewFileInfo(path);
        break;
#endif
    }
    return;
}

void VappGalleryViewerPage::onViewFileInfo(const VfxWString &path)
{
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
    VappGalleryMediaInfoPage *infoPage = NULL;
    VFX_OBJ_CREATE(infoPage, VappGalleryMediaInfoPage, getMainScr());
    infoPage->setFile(path);
    getMainScr()->pushPage(0, infoPage);
#endif
}

VappGallerySingleFileOperationUI* VappGalleryViewerPage::createFileOperator(const VfxWString &path)
{
    VappGallerySingleFileOperationUI *fileOp = NULL;
    VFX_OBJ_CREATE(fileOp, VappGallerySingleFileOperationUI, this);
    fileOp->configParentPage(this);
    fileOp->configFilePath(path);

    // check we came from My Shooting or My Picture,
    // to decide wording.
    VfxMainScr *scr = getMainScr();
    if(scr)
    {
        VfxPage *p = scr->getPage(scr->getPrevPageId(getId()));
        if(p && PN_MY_SHOOTING == (PageName)p->getId())
        {
            fileOp->configPhotoWording(VFX_TRUE);
        }
        else
        {
            // check file path directly, use photo wording if
            // the path is in shooting folder
            const VfxBool isMyShootingFolder = isFileInMyShootingFolder(path);
            fileOp->configPhotoWording(isMyShootingFolder);
        }
        fileOp->configMediaList(m_viewer->getMediaList());
    }
    return fileOp;
}

VfxBool VappGalleryViewerPage::isFileInMyShootingFolder(const VfxWString &path)
{
    VfxBool isMyShootingFolder = VFX_FALSE;
    do
    {
        if(path.isNull() || path.isEmpty() || path.getLength() < 4)
            break;

        // get the drive letter
        U8 drv = *((U8*)path.getBuf());
        VfxWString folderPath;
        VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(drv, VappGalleryFmgrDefaultFolder::MY_SHOOTING, folderPath);
        const VfxU32 folderPathLen = folderPath.getLength();
        VfxWString chompedPath = path;
        VfxWChar* chompedBuf = chompedPath.lockBuf(folderPathLen + 1);
        if(NULL == chompedBuf)
        {
            break;
        }
        chompedBuf[folderPathLen] = NULL;
        chompedPath.unlockBuf();

        if(0 == mmi_wcsicmp(folderPath.getBuf(), chompedPath.getBuf()))
        {
            isMyShootingFolder = VFX_TRUE;
        }
    }while(0);
    return isMyShootingFolder;
}

void VappGalleryViewerPage::onDeleteFile(const VfxWString &path)
{
    if(m_fileOp || NULL == m_viewer)
    {
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_DELET_FILE);
    m_viewer->suspendDecodeByFileOpInterrupt();

    // actually delete the file
    VFX_ASSERT(NULL == m_fileOp);
    m_fileOp = createFileOperator(path);
    m_fileOp->m_signalOperationDone.connect(this, &VappGalleryViewerPage::onDeleteFileFinished);
    m_fileOp->showDeleteUI();
}

void VappGalleryViewerPage::onDeleteFileFinished(VfxObject *sender, VappGalleryFileOpResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_DELET_FILE_FINISHED, result);

    // destroy the file operation object
    VappGallerySingleFileOperationUI *fileOp = (VappGallerySingleFileOperationUI*)sender;
    VFX_ASSERT(m_fileOp == fileOp);
    VFX_OBJ_CLOSE(m_fileOp);
    m_fileOp = NULL;
    fileOp = NULL;

    // update page UI logic
    if(VGFOR_DONE == result)
    {
        // update the cell count in shooting page
        // [MAUI_03309285] [MT6260 pre-SQC][Cosmos Slim][Gallery] After deleting last image it shows a white square box entered from my picture page
		VappGalleryShootingPage *page = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getPage(PN_MY_SHOOTING), VappGalleryShootingPage);
		if(!page)
		{
			page = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getPage(PN_MY_PICTURE), VappGalleryShootingPage);
		}
		
        if(page)
        {
            page->updateViewCellCount(-1);
        }

        if(m_initState.m_confirmScenario)
        {
            getMainScr()->popPage();
        }
    }
    else
    {
        // cancel/abort/error,
        // check error and show error popup
        if(VGFOR_ERROR == result)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_GALLERY_CANNOT_DELETE).getBuf());
        }
    }

    // viewer logic process
    if(m_viewer)
    {
        m_viewer->resumeDecodeAfterFileOpInterrupt();

        const VfxBool isSuccessful = (VGFOR_DONE == result) ? VFX_TRUE : VFX_FALSE;
        m_viewer->handleFileDeleted(isSuccessful);
    }
}

void VappGalleryViewerPage::onShareFile(const VfxWString &path)
{
    if(m_fileOp)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_SHARE_FILE_ALREADY_HAVE_FILE_OP);
        return;
    }


#ifdef __DRM_SUPPORT__
    // Check DRM permission to see if file can be shared
    S32 ret = mmi_rmgr_check_forward((WCHAR*)(const WCHAR*)path);
    if (ret >= 0 && (!(ret & MMI_RMGR_USAGE_SEND)))
    {
        VcpConfirmPopup *popup = NULL;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, getMainScr());
        popup->setInfoType(VCP_POPUP_TYPE_INFO);
        popup->setAutoDestory(VFX_TRUE);
        popup->setText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SHARE_DRM_ERROR_SINGLE));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->show(VFX_TRUE);
        return;
    }
#endif

    m_fileOp = createFileOperator(path);
    m_fileOp->m_signalOperationDone.connect(this, &VappGalleryViewerPage::onShareAndSetAsFileFinished);
    m_fileOp->m_signalReleaseResource.connect(this, &VappGalleryViewerPage::onRequireResourceRelease);
    m_fileOp->showShareUI();
    return;
}

void VappGalleryViewerPage::onSetFileAs(const VfxWString &path)
{
    if(m_fileOp)
    {
        return;
    }
    m_fileOp = createFileOperator(path);
    m_fileOp->m_signalOperationDone.connect(this, &VappGalleryViewerPage::onShareAndSetAsFileFinished);
    m_fileOp->showSetAsUI();
    return;
}

void VappGalleryViewerPage::onShareAndSetAsFileFinished(VfxObject *sender, VappGalleryFileOpResult result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_SHARE_FILE_DONE);
    // we don't care results of these operations,
    // so simply destroy the file operator
    VFX_ASSERT(m_fileOp == sender);
    VFX_OBJ_CLOSE(m_fileOp);
    m_fileOp = NULL;
    sender = NULL;

    if(m_viewer && m_viewer->shouldRefreshProvider())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_SHARE_AND_SET_AS_FINISHED, 1);
        m_initState.m_useIndexInList = VFX_FALSE;
        m_initState.m_displayed = VFX_FALSE;

        m_viewer->setInitState(m_initState);
        m_viewer->refresh();
    }
    return;
}

void VappGalleryViewerPage::onRequireResourceRelease()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_VIEWER_ON_REQUIRE_RES_RELEASE);
    onPageInactiveImpl();
    onPageInactived2Impl();
}

void VappGalleryViewerPage::onEditFile(const VfxWString &path)
{
#ifdef __GALLERY_PHOTO_EDIT__
    vapp_imgedt_scr_rotate_enum cuiRotation = VAPP_IMGEDT_SCR_ROTATE_0;
    switch(m_pageOrientation)
    {
    case VFX_SCR_ROTATE_TYPE_0:
        cuiRotation = VAPP_IMGEDT_SCR_ROTATE_0;
        break;
    case VFX_SCR_ROTATE_TYPE_90:
        cuiRotation = VAPP_IMGEDT_SCR_ROTATE_90;
        break;
    case VFX_SCR_ROTATE_TYPE_180:
        cuiRotation = VAPP_IMGEDT_SCR_ROTATE_0;
        break;
    case VFX_SCR_ROTATE_TYPE_270:
        cuiRotation = VAPP_IMGEDT_SCR_ROTATE_270;
        break;
    }

    vapp_imgedt_launch_struct *launchParam = NULL;
    VFX_ALLOC_MEM(launchParam, sizeof(vapp_imgedt_launch_struct), this);
    do
    {
        launchParam->parent_id = getApp()->getGroupId();
        launchParam->rotate = cuiRotation;
        mmi_wcsncpy(launchParam->filePath, path.getBuf(), path.getLength());
        m_editorCuiId = vapp_imgedt_launch(launchParam,  sizeof(*launchParam));
        if(m_editorCuiId)
        {
            // register caller proc
            mmi_frm_group_set_caller_proc(m_editorCuiId, &onPhotoEditorEvent, getObjHandle());
        }
    }while(0);
    VFX_FREE_MEM(launchParam);
#endif
}

mmi_ret VappGalleryViewerPage::handlePhotoEditorEvent(mmi_event_struct *evt)
{
#ifdef __GALLERY_PHOTO_EDIT__
    if(EVT_ID_IMGEDT_SAVED == evt->evt_id)
    {
        vapp_imgedt_event_struct *imgedtEvent = reinterpret_cast<vapp_imgedt_event_struct*>(evt);
        // Editor saved a new ifle
        // get saved path and set as focus
        const WCHAR *name = srv_fmgr_path_get_filename_ptr(imgedtEvent->filePath);
        m_initState.m_focusFile = VFX_WSTR_MEM(name);
        m_initState.m_refreshed = VFX_FALSE;    // since new file added, we need to refresh the list
        m_initState.m_displayed = VFX_FALSE;
        m_initState.m_focusIndex = 0;
        m_initState.m_useIndexInList = VFX_FALSE;
        m_initState.m_allowEmptyPage = VFX_FALSE;
        return MMI_RET_OK;
    }
    else if(EVT_ID_IMGEDT_BEGIN_SAVE == evt->evt_id)
    {
        m_initState.m_refreshed = VFX_FALSE;    // since file changes, we need to refresh the list
        return MMI_RET_OK;
    }

    return MMI_RET_DONT_CARE;

#else
    return MMI_RET_DONT_CARE;
#endif
}

mmi_ret VappGalleryViewerPage::onPhotoEditorEvent(mmi_event_struct *evt)
{
#ifdef __GALLERY_PHOTO_EDIT__
    VappGalleryViewerPage *pThis = (VappGalleryViewerPage*)handleToObject((VfxObjHandle)evt->user_data);
    if(pThis)
    {
        return pThis->handlePhotoEditorEvent(evt);
    }
    return MMI_RET_DONT_CARE;
#else
    return MMI_RET_DONT_CARE;
#endif
}

void VappGalleryViewerPage::configEmpty()
{
    m_initState.m_allowEmptyPage = VFX_TRUE;
    showEmptyPage();
    return;
}

void VappGalleryViewerPage::showEmptyPage()
{
    // hide all panels
    if(m_viewer)
        m_viewer->hideAllPanel(VFX_TRUE);

    if(m_editBtn)
    {
        m_editBtn->setHidden(VFX_TRUE);
    }
    if(m_infoBtn)
    {
        m_infoBtn->setHidden(VFX_TRUE);
    }

    toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);

    VfxId strId = STR_ID_VAPP_GALLERY_NO_IMG_VID;
    if(m_initState.m_imageOnly)
    {
        const VfxBool isMyShootingFolder = isFileInMyShootingFolder(m_initState.m_folderPath);
        strId = isMyShootingFolder ? STR_ID_VAPP_GALLERY_NO_PHT : STR_ID_VAPP_GALLERY_NO_IMG;
    }
    else if(m_initState.m_videoOnly)
    {
        strId = STR_ID_VAPP_GALLERY_NO_VID;
    }
    setPageMessage(VFX_WSTR_RES(strId));
    showPageMessage(VFX_TRUE, VFX_TRUE);

    // we need to explicitly clear the title bar,
    // since the title bar refresh logic prefer to keep current file name.
    if(m_titleBar)
    {
        m_titleBar->setTitle(VFX_WSTR_NULL);
    }
}

VfxBool VappGalleryViewerPage::getPageCurrentStorage(U8 &drvLetter)
{
    if(m_initState.isSingleFile() )
    {
        if(VFX_IMAGE_SRC_TYPE_PATH != m_initState.m_singleFileSrc.getType())
        {
            return VFX_FALSE;
        }
        const VfxWString &path = m_initState.m_singleFileSrc.getPath();
        if(path.isEmpty() || path.isNull())
        {
            return VFX_FALSE;
        }
        drvLetter = *((const U8*)path.getBuf());
        return VFX_TRUE;
    }

    if(NULL == m_viewer || !m_viewer->hasValidMediaList())
    {
        return VFX_FALSE;
    }

    VfxWString path;
    if(OK != m_viewer->getCurrentMediaPath(path) ||
       path.isEmpty() ||
       path.isNull())
    {
        return VFX_FALSE;
    }
    drvLetter = *((const U8*)path.getBuf());
    return VFX_TRUE;
}

void VappGalleryViewerPage::configSingleFile(VfxImageSrc src)
{
    m_initState.m_focusFile.setNull();
    m_initState.m_focusIndex = 0;
    m_initState.m_folderPath.setNull();
    m_initState.m_useIndexInList = VFX_FALSE;
    m_initState.m_displayed = VFX_FALSE;
    m_initState.m_refreshed = VFX_FALSE;
    m_initState.m_allowEmptyPage = VFX_TRUE;
    m_initState.m_singleFileSrc = src;
    m_initState.m_sortMethod = FS_SORT_NAME;
    m_initState.m_singleFileCheckResult = DECODING;
    // block buffer source here,
    // since it will be confused with image buffers from MediaCache.
    ASSERT(VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER != src.getType());

/*
    // for file sources, we need to consume the rights
    if(m_drmConsumer && VFX_IMAGE_SRC_TYPE_PATH == src.getType())
    {
        m_drmConsumer->setFileAndUserData(src.getPath(), NULL);
        m_drmConsumer->startConsume();
    }
*/
    // for file sources, we need to consume the rights
    if(m_viewer && VFX_IMAGE_SRC_TYPE_PATH == src.getType())
    {
        m_viewer->consumeDRM(src);
    }
}

void VappGalleryViewerPage::configFolderAndIndex(
                                const VfxWString &folder,
                                VfxU32 mediaIndex,
                                VfxBool imageOnly,
                                VfxBool videoOnly,
                                VfxS32 sortMethod,
                                VfxBool allowEmpty,
                                const FMGR_FILTER *fileFilter
                                )
{
    m_initState.m_focusFile.setNull();
    m_initState.m_focusIndex = mediaIndex;
    m_initState.m_folderPath = folder;
    m_initState.m_useIndexInList = VFX_TRUE;
    m_initState.m_displayed = VFX_FALSE;
    m_initState.m_refreshed = VFX_FALSE;
    m_initState.m_allowEmptyPage = allowEmpty;
    m_initState.m_singleFileCheckResult = DECODING;
    m_initState.m_imageOnly = imageOnly;
    m_initState.m_videoOnly = videoOnly;
    m_initState.m_sortMethod = sortMethod;
    m_initState.m_singleFileSrc.setNull();
    if(fileFilter)
    {
        m_initState.m_hasCustomFilter = VFX_TRUE;
        copyFmgrFilter(&m_initState.m_fileFilter, *fileFilter);
    }
}

void VappGalleryViewerPage::configFolderAndFilename(
                                const VfxWString &folder,
                                const VfxWString &focusFileName,
                                VfxBool imageOnly,
                                VfxS32 sortMethod,
                                const FMGR_FILTER *fileFilter)
{
    m_initState.m_focusFile = focusFileName;
    m_initState.m_focusIndex = 0;
    m_initState.m_folderPath = folder;
    m_initState.m_useIndexInList = VFX_FALSE;
    m_initState.m_displayed = VFX_FALSE;
    m_initState.m_refreshed = VFX_FALSE;
    m_initState.m_allowEmptyPage = VFX_TRUE;    // allow display "no video/image". Mainly for Camera->Gallery case.
    m_initState.m_singleFileCheckResult = DECODING;
    m_initState.m_imageOnly = imageOnly;
    m_initState.m_sortMethod = sortMethod;
    m_initState.m_singleFileSrc.setNull();
    if(fileFilter)
    {
        m_initState.m_hasCustomFilter = VFX_TRUE;
        copyFmgrFilter(&m_initState.m_fileFilter, *fileFilter);
    }
}

void VappGalleryViewerPage::configSlideshowAutoStart(VfxBool autoPlaySlideshow)
{
    m_initState.m_autoPlaySlideshow = autoPlaySlideshow;
}

void VappGalleryViewerPage::onProviderUpdated(const VfxS32 mediaCount)
{
    checkUpdate();
    if(mediaCount == 0)
    {
        // if explicitly allow empty page,
        // or we're the last page in Gallery app,
        // display error message instead of going back to previous page.
        if(m_initState.m_allowEmptyPage || getMainScr()->getPageCount() <= 1)
        {
            showEmptyPage();
            return;
        }
        else
        {
            // if the list is empty, return to previous page
            exit();
        }
    }
    else
    {
        GALLERY_MEASURE_TIME_START("VTB");
        toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
        GALLERY_MEASURE_TIME_STOP("VTB");
        if(m_editBtn)
        {
            m_editBtn->setHidden(VFX_FALSE);
        }
        if(m_infoBtn)
        {
            m_infoBtn->setHidden(VFX_FALSE);
        }
        showPageMessage(VFX_FALSE, VFX_TRUE);
    }
}

void VappGalleryViewerPage::onCurrentPanelChanged(const VfxS32 currentIndex)
{
    // when switch new media, hide the OSD,
    // since their state may change,
    // this is to reduce visual impact.
    hideAllBars(VFX_TRUE);
    checkUpdate();
}

void VappGalleryViewerPage::onStartDisplayMedia()
{
    updateToolbar();
}

void VappGalleryViewerPage::onViewerSliderDragging(VfxBool isDraging)
{
    if(isDraging)
        hideAllBars(VFX_FALSE);
}

void VappGalleryViewerPage::onUpdate()
{
    VappGalleryPage::onUpdate();
    VFX_DEV_ASSERT(m_titleBar);

    // update title
    VfxWString titleText;
    if(hasCustomTitle())
    {
        getCustomTitle(titleText);
    }
    else if(m_viewer)
    {
        m_viewer->getCurrentMediaName(titleText);
    }

    if(!titleText.isEmpty())
    {
        m_titleBar->setTitle(titleText);
    }

    updateToolbar();
}

void VappGalleryViewerPage::onViewerGesture(VappGalleryGesture gesture, VfxS32 currentPreviewIndex)
{
    VFX_UNUSED(currentPreviewIndex);
    switch(gesture)
    {
    case VG_TAP:
        {
            // toggle bar hiding state
            const VfxBool isBarHidden = getIsBarHidden();
            const VfxU64 animDuration = (isBarHidden)? 0 : 250;
            hideAllBars(!isBarHidden);
            if(m_viewer)
            {
                m_viewer->handlePageUiAnim(VFX_FALSE, animDuration);
            }
        }
        break;
    case VG_DOUBLE_TAP:
    case VG_GO_NEXT:
    case VG_GO_PREV:
    case VG_DRAG:
    case VG_DRAG_END:
        // do not process
        break;
    default:
        break;
    }
}

void VappGalleryViewerPage::updateToolbar()
{
    VfxPageBar *pbar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    VcpToolBar *tbar = VFX_OBJ_DYNAMIC_CAST(pbar, VcpToolBar);
    if(tbar)
    {
        // TODO: merge this with canZoom()
        const VfxBool isImageVisible = (m_viewer && m_viewer->isCurrentPreviewImageVisible());
        const VfxBool isVideo = (m_viewer && m_viewer->isCurrentPreviewVideo());
        const VfxBool isMAVImg = (m_viewer && m_viewer->isCurrentPreviewMAV());
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
        const VfxBool disableSetAsWallpaper = (!isImageVisible || isVideo);
#else
        const VfxBool disableSetAsWallpaper = (!isImageVisible || isVideo || isMAVImg);
#endif
        // note: we always allow "delete" and "share" even if the image cannot be displayed.
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
        tbar->setDisableItem('PLAY', !isImageVisible || isVideo || isMAVImg);
#endif
        tbar->setDisableItem('ROTA', !isImageVisible || isVideo || isMAVImg);
        tbar->setDisableItem('SETA', disableSetAsWallpaper);
        tbar->setDisableItem('INFO', !isImageVisible || isVideo || isMAVImg);
        if(m_infoBtn)
        {
            m_infoBtn->setHidden(!isImageVisible || isVideo || isMAVImg);
        }

#ifdef __GALLERY_PHOTO_EDIT__
        // update toolbar availability
        VfxBool canEdit = VFX_FALSE;
        do
        {
            if(NULL == m_viewer)
            {
                break;
            }

            if(!m_viewer->isProviderPrepared())
            {
                break;
            }

            if(isVideo || isMAVImg)
            {
                break;
            }

            VfxWString path;
            if(OK != m_viewer->getCurrentMediaPath(path))
            {
                break;
            }

            if(MMI_FALSE == vapp_imgedt_is_file_support(path.getBuf()))
            {
                break;
            }

            canEdit = VFX_TRUE;
        }while(0);

        const VfxBool disableEdit = !(isImageVisible && canEdit);
        tbar->setDisableItem('EDIT', disableEdit);
        if(m_editBtn)
        {
            m_editBtn->setHidden(disableEdit);
        }
#endif
    }
}

/*****************************************************************************
 * Class Implementation of VappGalleryViewerPage (Slideshow section)
 *****************************************************************************/
#ifdef __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
void VappGalleryViewerPage::onPlaySlideshow()
{
    if(m_viewer->isPlayingSlideshow())
    {
        return;
    }

    m_viewer->getSlideshowStoppedEvent()->connect(this, &VappGalleryViewerPage::onSlideshowStopped);
    const VfxBool res = m_viewer->playSlideshow();
    // start to play slideshow sucessfully, update page UI
    if(res)
    {
        hideAllBars(VFX_TRUE);
        setBarAutoHide(VFX_FALSE);
    }
}


void VappGalleryViewerPage::onStopSlideshow()
{
    if(m_viewer)
        m_viewer->stopSlideshow();
}

void VappGalleryViewerPage::onSlideshowStopped()
{
    checkUpdate();
    hideAllBars(VFX_FALSE);
    setBarAutoHide(allowHideAllBars());
    //hideAllBars(VFX_TRUE);
}
#endif

/*****************************************************************************
 * Class Implementation of VappGalleryShuffleIndex
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation of VappGalleryViewerPanel
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation of VappGalleryMediaInfoPage
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_IMAGE_INFO_PAGE__
VappGalleryMediaInfoPage::VappGalleryMediaInfoPage()
{
}

void VappGalleryMediaInfoPage::onInit()
{
    VfxPage::onInit();

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // title bar
    VcpTitleBar *titleBar = NULL;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    setTopBar(titleBar);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMAGE_DETAIL));

    // info text
    VFX_OBJ_CREATE(m_infoView, VcpForm, this);
    //m_infoView->setBgColor(VFX_COLOR_WHITE);
    m_infoView->setSize(getSize());
    m_infoView->setPos(0, 0);
    m_infoView->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappGalleryMediaInfoPage::setFile(const VfxWString &filename)
{
    VfxWString strInfo;
    VappGalleryMediaInfoParser parser;
    parser.parseFile(filename);
    parser.insertInfoItems(m_infoView);
}

/*****************************************************************************
 * Class Implementation of VappGalleryMediaInfoCell
 *****************************************************************************/
VappGalleryMediaInfoCell::VappGalleryMediaInfoCell():
    m_title(NULL),
    m_desc(NULL)
{
}

void VappGalleryMediaInfoCell::onInit()
{
    VcpFormItemBase::onInit();

    // create main text
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setColor(VFX_COLOR_RES(COR_ID_VAPP_GALLERY_PIC_ALL_PIC_LABEL_FONT_BRIGHTNESS));
    m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE)));
    m_title->setPos(MARGIN_X, 0);
    m_title->setSize(ITEM_WIDTH, 5);
    m_title->forceUpdate();

    VFX_OBJ_CREATE(m_desc, VfxTextFrame, this);
    m_desc->setColor(VFX_COLOR_RES(COR_ID_VAPP_GALLERY_PIC_ALL_PIC_DESC_FONT_BRIGHTNESS));
    m_desc->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(DESC_FONT_SIZE)));
    const VfxS32 x = MARGIN_X;
    const VfxS32 y = m_title->getSize().height;
    m_desc->setPos(x, y);
    m_desc->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_desc->setSize(ITEM_WIDTH, 5);

    const VfxS32 totalHeight = (m_title->getSize().height + m_desc->getSize().height + TAIL_GAP);

    setSize(ITEM_WIDTH, totalHeight);
    setHeight(totalHeight);
}

void VappGalleryMediaInfoCell::setTitleText(const VfxWString &text)
{
    VFX_ASSERT(m_title);
    m_title->setString(text);
    m_title->forceUpdate();
}

void VappGalleryMediaInfoCell::setDescText(const VfxWString &text)
{
    VFX_ASSERT(m_desc);

    m_desc->setString(text);
    m_desc->forceUpdate();
    VfxS32 height = (m_title->getSize().height + m_desc->getSize().height + TAIL_GAP);
    setSize(ITEM_WIDTH, height);
    setHeight(height);
}

/*****************************************************************************
 * Class Implementation of VappGalleryMediaInfoParser
 *****************************************************************************/
VappGalleryMediaInfoParser::VappGalleryMediaInfoParser():
    m_fileInfoReady(VFX_FALSE),
    m_jpegInfoReady(VFX_FALSE),
    m_imageWidth(0),
    m_imageHeight(0)
{
    memset(&m_jpegInfo, 0, sizeof(m_jpegInfo));
    memset(&m_fileInfo, 0, sizeof(m_fileInfo));
}

void VappGalleryMediaInfoParser::parseFile(const VfxWString &filename)
{
    m_fileInfoReady = VFX_FALSE;
    m_jpegInfoReady = VFX_FALSE;

    // retrieve basic file info
    S32 fmgrResult = srv_fmgr_fs_path_get_fileinfo((const WCHAR*)filename, &m_fileInfo);
    if(0 > fmgrResult)
    {
        m_fileInfoReady = VFX_FALSE;
        // failed
        return;
    }
    else
    {
        m_fileInfoReady = VFX_TRUE;
    }

    // get basic image size
    const GDI_RESULT sizeResult = gdi_image_get_dimension_file((CHAR*)(const WCHAR*)filename, &m_imageWidth, &m_imageHeight);
    if (sizeResult < 0)
    {
        m_imageWidth = m_imageHeight = 0;
    }

    // retrieve jpeg info
    const GDI_RESULT result = gdi_image_jpeg_get_exif_info((CHAR*)(const WCHAR*)filename, &m_jpegInfo);
    if(0 == result)
    {
        m_jpegInfoReady = VFX_TRUE;
    }
}

void VappGalleryMediaInfoParser::addResultItem(VcpForm *form, VfxId &itemId, const VfxWString &title, const VfxWString &desc)
{
    VappGalleryMediaInfoCell *cell = NULL;
    VFX_OBJ_CREATE(cell, VappGalleryMediaInfoCell, form);
    cell->setTitleText(title);
    cell->setDescText(desc);
    form->addItem(cell, itemId++);
}

void VappGalleryMediaInfoParser::insertInfoItems(VcpForm *form)
{
    VfxWString label;
    VfxWString content;
    VfxId itemId = 0;

    form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_PHOTO_BASIC_INFO));

    // append basic file info
    if(m_fileInfoReady)
    {
        label = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_EXIF_IMAGE_WIDTH);
        content.format("%d", m_imageWidth);
        addResultItem(form, itemId, label, content);

        label = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_EXIF_IMAGE_HEIGHT);
        content.format("%d", m_imageHeight);
        addResultItem(form, itemId, label, content);

        label = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_EXIF_FILE_SIZE);
        formatSizeText(content, m_fileInfo.size);
        addResultItem(form, itemId, label, content);
    }

    if(!m_jpegInfoReady)
    {
        form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_EXIF_NO_INFORMATION));
        return;
    }

    // insert JPEG title
    form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_PHOTO_INFO));

    // append JPEG info
#define PRINT_EXIF_INFO(__a__,__A__)\
    do{\
        if((m_jpegInfo.##__a__##) && strlen((const char*)m_jpegInfo.##__a__##))\
        {\
            content.format("%s", (char*)m_jpegInfo.##__a__##);\
            label.loadFromRes(##__A__##);\
            addResultItem(form, itemId, label, content);\
        }\
   }while(0);


    PRINT_EXIF_INFO(make, STR_ID_VAPP_GALLERY_EXIF_MAKE);
    PRINT_EXIF_INFO(model, STR_ID_VAPP_GALLERY_EXIF_MODEL);
    PRINT_EXIF_INFO(orientation, STR_ID_VAPP_GALLERY_EXIF_ORIENTATION);
    PRINT_EXIF_INFO(x_resolution, STR_ID_VAPP_GALLERY_EXIF_X_RESOLUTION);
    PRINT_EXIF_INFO(y_resolution, STR_ID_VAPP_GALLERY_EXIF_Y_RESOLUTION);
    PRINT_EXIF_INFO(resolution_unit, STR_ID_VAPP_GALLERY_EXIF_RESOLUTION_UNIT);
    PRINT_EXIF_INFO(software, STR_ID_VAPP_GALLERY_EXIF_SOFTWARE);
    PRINT_EXIF_INFO(date_time, STR_ID_VAPP_GALLERY_EXIF_DATE_TIME);
    PRINT_EXIF_INFO(ycbcr_positioning, STR_ID_VAPP_GALLERY_EXIF_YCBCR_POSITIONING);
    PRINT_EXIF_INFO(exif_ifd, STR_ID_VAPP_GALLERY_EXIF_EXIF_IFD);
    PRINT_EXIF_INFO(exposure_time, STR_ID_VAPP_GALLERY_EXIF_EXPOSURE_TIME);
    PRINT_EXIF_INFO(fnumber, STR_ID_VAPP_GALLERY_EXIF_FNUMBER);
    PRINT_EXIF_INFO(exposure_program, STR_ID_VAPP_GALLERY_EXIF_EXPOSURE_PROGRAM);
    PRINT_EXIF_INFO(iso_speed_ratings, STR_ID_VAPP_GALLERY_EXIF_ISO_SPEED_RATINGS);
    PRINT_EXIF_INFO(exif_version, STR_ID_VAPP_GALLERY_EXIF_EXIF_VERSION);
    PRINT_EXIF_INFO(date_time_original, STR_ID_VAPP_GALLERY_EXIF_DATE_TIME_ORIGINAL);
    PRINT_EXIF_INFO(date_time_digitized, STR_ID_VAPP_GALLERY_EXIF_DATE_TIME_DIGITIZED);
    PRINT_EXIF_INFO(components_config, STR_ID_VAPP_GALLERY_EXIF_COMPONENTS_CONFIG);
    PRINT_EXIF_INFO(exposure_bias_value, STR_ID_VAPP_GALLERY_EXIF_EXPOSURE_BIAS_VALUE);
    PRINT_EXIF_INFO(metering_mode, STR_ID_VAPP_GALLERY_EXIF_METERING_MODE);
    PRINT_EXIF_INFO(light_source, STR_ID_VAPP_GALLERY_EXIF_LIGHT_SOURCE);
    PRINT_EXIF_INFO(flash, STR_ID_VAPP_GALLERY_EXIF_FLASH);
    // PRINT_EXIF_INFO(maker_note, STR_ID_VAPP_GALLERY_EXIF_MAKER_NOTE);    // don't display maker note since they don't mean much to user
    PRINT_EXIF_INFO(flashpix_version, STR_ID_VAPP_GALLERY_EXIF_FLASHPIX_VERSION);
    PRINT_EXIF_INFO(color_space, STR_ID_VAPP_GALLERY_EXIF_COLOR_SPACE);
    PRINT_EXIF_INFO(pixel_x_dimension, STR_ID_VAPP_GALLERY_EXIF_PIXEL_X_DIMENSION);
    PRINT_EXIF_INFO(pixel_y_dimension, STR_ID_VAPP_GALLERY_EXIF_PIXEL_Y_DIMENSION);
    PRINT_EXIF_INFO(exposure_mode, STR_ID_VAPP_GALLERY_EXIF_EXPOSURE_MODE);
    PRINT_EXIF_INFO(digital_zoom_ratio, STR_ID_VAPP_GALLERY_EXIF_DIGITAL_ZOOM_RATIO);
    PRINT_EXIF_INFO(scene_capture_type, STR_ID_VAPP_GALLERY_EXIF_SCENE_CAPTURE_TYPE);

#undef PRINT_EXIF_INFO
}
#endif

/*****************************************************************************
 * Class Implementation of VappGalleryWallpaperPreviewPage
 *****************************************************************************/
VappGalleryWallpaperPreviewPage::VappGalleryWallpaperPreviewPage():
    m_wallpaperInfo(NULL),
    m_wallpaperType(VAPP_WALLPAPER_STATIC_WALLPAPER),
    m_indexSelected(-1),
    m_isEntered(VFX_FALSE), 
    m_activeLiveWallpaper(NULL)
{

}

void VappGalleryWallpaperPreviewPage::onEnter(VfxBool isBack)
{
    VappGalleryViewerPage::onEnter(isBack);

    // register UCM event
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_INDICATION, &VappGalleryWallpaperPreviewPage::onEvent, getObjHandle());

    if(m_wallpaperInfo &&
       (VAPP_WALLPAPER_LIVE_WALLPAPER == m_wallpaperType || VAPP_WALLPAPER_VIDEO_WALLPAPER == m_wallpaperType)
       && NULL == m_activeLiveWallpaper)
    {
        // video wallpaper & live wallpaper requires re-creation
        createWallpaperFrameFromInfo();
    }
}

void VappGalleryWallpaperPreviewPage::onEntered()
{
    VappGalleryViewerPage::onEntered();
    m_isEntered = VFX_TRUE;

    if(m_wallpaperInfo &&
       NULL != m_activeLiveWallpaper)
    {
        if(VAPP_WALLPAPER_LIVE_WALLPAPER == m_wallpaperType)
        {
            VappWallpaper *wp = (VappWallpaper*)m_activeLiveWallpaper;
            if(wp->checkResource())
            {
                wp->resume();
                setOKButtonEnabled(VFX_TRUE);
            }
            else
            {
                setOKButtonEnabled(VFX_FALSE);
            }
        }
        #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
        if(VAPP_WALLPAPER_VIDEO_WALLPAPER == m_wallpaperType)
        {
            VappVideoPlayerComponent* cp = VFX_OBJ_DYNAMIC_CAST(m_activeLiveWallpaper, VappVideoPlayerComponent);
            if(NULL == cp)
            {
                setOKButtonEnabled(VFX_FALSE);
                return;
            }

            // delay 1 frame before playing
            VfxTimer *timer = NULL;
            VFX_OBJ_CREATE(timer, VfxTimer, this);
            timer->m_signalTick.connect(this, &VappGalleryWallpaperPreviewPage::onDelayPlay);
            timer->setStartDelay(1);
            timer->start();

        }
        #endif
    }
}

void VappGalleryWallpaperPreviewPage::onDelayPlay(VfxTimer *sender)
{
    VFX_OBJ_CLOSE(sender);
    if(m_isEntered && VAPP_WALLPAPER_VIDEO_WALLPAPER == m_wallpaperType)
    {
        VappVideoPlayerComponent* cp = VFX_OBJ_DYNAMIC_CAST(m_activeLiveWallpaper, VappVideoPlayerComponent);
        if(NULL == cp)
        {
            setOKButtonEnabled(VFX_FALSE);
            return;
        }
        MDI_RESULT playResult = cp->play();
        if(MDI_RES_VDOPLY_SUCCEED != playResult &&
           MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != playResult)
        {
            setOKButtonEnabled(VFX_FALSE);
        }
    }
}

void VappGalleryWallpaperPreviewPage::onExit(VfxBool isBack)
{
    m_isEntered = VFX_FALSE;
    if(m_wallpaperInfo &&
       NULL != m_activeLiveWallpaper)
    {
        if(VAPP_WALLPAPER_LIVE_WALLPAPER == m_wallpaperType)
        {
            VappWallpaper *wp = (VappWallpaper*)m_activeLiveWallpaper;
            wp->suspend();
        }
        #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
        if(VAPP_WALLPAPER_VIDEO_WALLPAPER == m_wallpaperType)
        {
            VappVideoPlayerComponent* cp = VFX_OBJ_DYNAMIC_CAST(m_activeLiveWallpaper, VappVideoPlayerComponent);
            if(cp)
            {
                MDI_RESULT pauseResult = cp->pause();
                cp->swithVideoLayerToSW(VFX_TRUE);
            }
        }
        #endif
    }

    VappGalleryViewerPage::onExit(isBack);
}

void VappGalleryWallpaperPreviewPage::onExited2()
{
    // unregister UCM event
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_INDICATION, &VappGalleryWallpaperPreviewPage::onEvent, getObjHandle());

    VFX_OBJ_CLOSE(m_activeLiveWallpaper);
    VappGalleryViewerPage::onExited2();
}

void VappGalleryWallpaperPreviewPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_0;
}

void VappGalleryWallpaperPreviewPage::createToolbar()
{
    // Wallpaper preview have only 2 options.
    VcpToolBar *tbar = NULL;
    VFX_OBJ_CREATE(tbar, VcpToolBar, this);
    tbar->addItem('OKAY', VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    tbar->addItem('BACK', VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    tbar->m_signalButtonTap.connect(this, &VappGalleryWallpaperPreviewPage::onToolbarCommand);
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, tbar, VFX_TRUE);
}

void VappGalleryWallpaperPreviewPage::initImageViewerCPOption(VappImageViewerComponentOption &option)
{
    option.supportMultiTouch = VFX_FALSE;
    option.supportZoom = VFX_FALSE;
    option.isSyncContentProvider = VFX_TRUE;
}

void VappGalleryWallpaperPreviewPage::layoutImageViewerCP()
{
    if(NULL == m_viewer)
        return;

    VfxPoint origin = getMainScr()->convertPointTo(VfxPoint(0, 0), this);
    m_viewer->setSize(getMainScr()->getSize());
    m_viewer->setPos(origin);
}

void VappGalleryWallpaperPreviewPage::setBounds(const VfxRect &value)
{
    VappGalleryViewerPage::setBounds(value);
    layoutImageViewerCP();
}

void VappGalleryWallpaperPreviewPage::setPageStyle()
{
    // Wallpaper picker preview is a black-style UI
    // but toolbars won't disappear
    setBgColor(VFX_COLOR_BLACK);
    setTranslucent(VFX_TRUE);
    setBarAutoHide(VFX_FALSE);
}

VfxBool VappGalleryWallpaperPreviewPage::allowHideAllBars()
{
    return VFX_FALSE;
}

void VappGalleryWallpaperPreviewPage::setWallpaperSource(IWallpaperSourceStruct *sourceInfo)
{
    m_wallpaperInfo = sourceInfo;
}

void VappGalleryWallpaperPreviewPage::setSelectedWallpaper(VappWpResType wallpaperType, VfxS32 indexSelected)
{
    // check for same setting
    if(m_wallpaperType == wallpaperType &&
       m_indexSelected == indexSelected)
    {
        return;
    }

    m_wallpaperType = wallpaperType;
    m_indexSelected = indexSelected;

    // close previous live wallpaper (if any)
    VFX_OBJ_CLOSE(m_activeLiveWallpaper);

    createWallpaperFrameFromInfo();
}

void VappGalleryWallpaperPreviewPage::createWallpaperFrameFromInfo()
{
    if(NULL == m_wallpaperInfo || NULL == m_viewer)
    {
        return;
    }

    switch(m_wallpaperType)
    {
    case VAPP_WALLPAPER_LIVE_WALLPAPER:
        if(m_wallpaperInfo->get_live_wallpaper)
        {
            VFX_OBJ_CLOSE(m_activeLiveWallpaper);
            VfxFrame *hostFrame = static_cast<VfxFrame*>(m_viewer->getCurrentPanel());
            VappWallpaper *ret = (VappWallpaper*)m_wallpaperInfo->get_live_wallpaper(m_indexSelected, (void*)hostFrame, m_wallpaperInfo->user_data);
            VFX_DEV_ASSERT(ret);
            ret->suspend();
            m_activeLiveWallpaper = reinterpret_cast<VfxFrame*>(ret);
        }
        break;
    case VAPP_WALLPAPER_STATIC_WALLPAPER:
        if(m_wallpaperInfo->get_static_wallpaper_img_id)
        {
            MMI_IMG_ID previewImgId = m_wallpaperInfo->get_static_wallpaper_img_id(m_indexSelected, m_wallpaperInfo->user_data);
            VfxFrame *hostFrame = static_cast<VfxFrame*>(m_viewer->getCurrentPanel());
            VfxFrame *previewFrame = NULL;
            VFX_OBJ_CREATE(previewFrame, VfxFrame, hostFrame);
            previewFrame->setSize(hostFrame->getSize());
            previewFrame->setPos(0, 0);
            previewFrame->setImgContent(VfxImageSrc(previewImgId));
            previewFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
        }
        break;
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    case VAPP_WALLPAPER_VIDEO_WALLPAPER:
        if(m_wallpaperInfo->get_video_wallpaper_vid_id)
        {
            VFX_OBJ_CLOSE(m_activeLiveWallpaper);
            MMI_IMG_ID videoId = m_wallpaperInfo->get_video_wallpaper_vid_id(m_indexSelected, m_wallpaperInfo->user_data);
            VappVideoPlayerPlayOption option;
            option.configAsWallpaperVideoPreview();
            VappVideoPlayerComponent *video;
            VfxFrame *hostFrame = static_cast<VfxFrame*>(m_viewer->getCurrentPanel());
            VFX_OBJ_CREATE_EX(video, VappVideoPlayerComponent, hostFrame, (option));
            video->setPos(0, 0);
            video->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
            video->m_signalFileOpened.connect(this, &VappGalleryWallpaperPreviewPage::onVideoOpened);
            video->m_signalPlaybackFinished.connect(this, &VappGalleryWallpaperPreviewPage::onVideoFinished);
            video->openResId(videoId);
            video->pause();
            video->swithVideoLayerToSW(VFX_TRUE);
            setOKButtonEnabled(VFX_TRUE);
            m_activeLiveWallpaper = video;
        }
        break;
#endif
    default:
        VFX_ASSERT(0);
    }
}

VfxBool VappGalleryWallpaperPreviewPage::onPenInput(VfxPenEvent &event)
{
    // skip logic of PreviewPage, bypass event to children
    return VappGalleryPage::onPenInput(event);
}

void VappGalleryWallpaperPreviewPage::onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result)
{
    if(MDI_RES_VDOPLY_SUCCEED != result &&
       MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != result)
    {
        setOKButtonEnabled(VFX_FALSE);
        return;
    }

    setOKButtonEnabled(VFX_TRUE);
    onDelayPlay(NULL);
    return;
}

void VappGalleryWallpaperPreviewPage::onVideoFinished(VappVideoPlayerComponent *sender, MDI_RESULT result)
{
    if(MDI_RES_VDOPLY_SUCCEED != result &&
       MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT != result)
    {
         setOKButtonEnabled(VFX_FALSE);
         return;
    }

    setOKButtonEnabled(VFX_TRUE);
}

void VappGalleryWallpaperPreviewPage::setOKButtonEnabled(VfxBool enabled)
{
    VfxPageBar *bar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    VcpToolBar *tbar = VFX_OBJ_DYNAMIC_CAST(bar, VcpToolBar);
    if(tbar)
    {
        tbar->setDisableItem('OKAY', !enabled);
    }
}

void VappGalleryWallpaperPreviewPage::onToolbarCommand(VfxObject* sender, VfxId btnId)
{
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    if('OKAY' == btnId)
    {
        // check for broken wallpaper (e.g. file-based live wallpaper)
        VfxBool validWallpaper = VFX_TRUE;
        do
        {
            if(VAPP_WALLPAPER_LIVE_WALLPAPER == m_wallpaperType)
            {
                if(NULL == m_activeLiveWallpaper)
                {
                    validWallpaper = VFX_FALSE;
                    break;
                }

                VappWallpaper *wp = (VappWallpaper*)m_activeLiveWallpaper;
                wp->suspend();
                if(!wp->checkResource())
                {
                    validWallpaper = VFX_FALSE;
                    break;
                }
            }
            validWallpaper = VFX_TRUE;
        }while(0);

        if(!validWallpaper)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
            return;
        }
        VcuiGalleryWallpaperPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryWallpaperPicker);
        if(cui)
        {
            VfxS32 groupId = m_wallpaperType;
            cui->finishPickOperation(VcuiGalleryWallpaperPicker::WALLPAPER_PICK_OK, VcpMenuPos(groupId, m_indexSelected));
        }
        return;
    }
    else if('BACK' == btnId)
    {
        getMainScr()->popPage();
        return;
    }
    VFX_DEV_ASSERT(VFX_FALSE);  // unrecognized command
}

mmi_ret VappGalleryWallpaperPreviewPage::onEvent(mmi_event_struct *param)
{
    VappGalleryWallpaperPreviewPage *pThis = (VappGalleryWallpaperPreviewPage*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    switch(param->evt_id)
    {
    case EVT_ID_SRV_UCM_INDICATION:
        // handle background call finish to resume video
        if(VAPP_WALLPAPER_VIDEO_WALLPAPER == pThis->m_wallpaperType &&
           NULL != pThis->m_activeLiveWallpaper)
        {
            srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)param;
            if (ind->ind_type == SRV_UCM_RELEASE_IND && !srv_ucm_is_any_call())
            {
                MDI_RESULT playResult = MDI_RES_VDOPLY_SUCCEED;
                VappVideoPlayerComponent* player = (VappVideoPlayerComponent*)pThis->m_activeLiveWallpaper;
                playResult = player->play();
                pThis->setOKButtonEnabled(MDI_RES_VDOPLY_SUCCEED == playResult ||
                                          MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT == playResult);
            }
        }
        break;
    }

    return MMI_RET_OK;

}

#endif // #ifdef __MMI_FTO_GALLERY__
