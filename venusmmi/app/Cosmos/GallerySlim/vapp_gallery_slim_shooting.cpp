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
 *  vapp_gallery_shooting.cpp
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

#include "mmi_rp_vapp_gallery_def.h"
#include "vapp_gallery_slim_shooting.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_gallery_slim_viewer.h"
#include "vapp_gallery_slim_player.h"
#include "vapp_gallery_slim_data.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vapp_gallery_slim_util.h"
#include "trc/vadp_app_trc.h"
#include "vapp_gallery_slim_index.h"
#include "vfx_adp_device.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

extern "C"
{
#include "MediaCacheSrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "FileMgrResDef.h"
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
}

// -------------------------------------

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryShootingPage", VappGalleryShootingPage, VappGalleryPage);

VappGalleryShootingPage::VappGalleryShootingPage():
#ifdef __VAPP_GALLERY_ENABLE_CAMERA__
    m_isHideCameraButton(VFX_FALSE)
#else
    m_isHideCameraButton(VFX_TRUE)
#endif
	,m_grid(NULL)
    ,m_mediaList(NULL)
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    ,m_fileOp(NULL)
#endif
    ,m_singleFilePopup(NULL)
    ,m_customFolderFilter(ALLOW_ALL)
    ,m_wallpaperInfo(NULL)
    ,m_sortMethod(FS_SORT_NAME)
    ,m_viewCellCount(0)   
{
    m_customFolderPath.setNull();
}

void VappGalleryShootingPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_INIT);

    VappGalleryPage::onInit(); // call base class

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // reset view state
    kal_mem_set(&m_viewState, 0, sizeof(m_viewState));
    m_viewCellCount = 0;

    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    setTopBar(bar);

    // check for CUI title override
    VfxWString caption;
    if(hasCustomTitle())
    {
        getCustomTitle(caption);
    }
    else
    {
        caption = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_SHOOTING);
    }
    bar->setTitle(caption);

    showPageWaitIcon(VFX_TRUE);

    // Note: grid is created in onEnter().
}

void VappGalleryShootingPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_DEINIT);
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    VFX_OBJ_CLOSE(m_fileOp);
#endif
    VFX_OBJ_CLOSE(m_grid);

    // wallpaper picker case,
    // we destory list until page is destroyed,
    if(NULL != m_wallpaperInfo)
    {
        closeMediaList();
    }
    VappGalleryPage::onDeinit();
}

void VappGalleryShootingPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_EXIT);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    onPageInactiveImpl();

    VappGalleryPage::onExit(isBackward);
}

void VappGalleryShootingPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_EXITED2);
    // in Snapshot mode, we're not in FG, and we don't need
    // to handle changes
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    onPageInactived2Impl();

    VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    const VfxBool releaseForegroundOnly = m_wallpaperInfo || (isActive() && (NULL == pickerCUI));
    if(!releaseForegroundOnly)
    {
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        VFX_OBJ_CLOSE(m_fileOp);
#endif
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
    }

    VappGalleryPage::onExited2();
}

void VappGalleryShootingPage::onPageInactiveImpl()
{
    if(m_grid)
    {
        m_grid->pauseUpdate(VFX_TRUE, __LINE__);
    }

    if(m_mediaList)
    {
        m_mediaList->enableBackgroundDecode(VFX_FALSE);
    }
}

void VappGalleryShootingPage::onPageInactived2Impl()
{
    if(m_grid)
    {
        m_grid->getViewState(&m_viewState);
    }
    if(m_mediaList)
    {
        m_viewCellCount = m_mediaList->getMediaCountInGroup(0);
    }

    // check if we're entering next page
    // or into background.
    // for picker CUIs, since they store FMgr list in FG memory,
    // we must release entire media list when exit() this page.
    VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    const VfxBool releaseForegroundOnly = m_wallpaperInfo || (isActive() && (NULL == pickerCUI));
    if(releaseForegroundOnly)
    {
        // only release thumbnail cache,
        // keep grid CP, toolbar and file list.
        if(m_grid)
        {
            m_grid->releaseAllCachedImage();
        }

        // check if media list is prepared
        // if it is unprepared, close media list after release FG
        const VfxBool isMediaListPrepared = (m_mediaList)? m_mediaList->isPrepared() : VFX_FALSE;

        // since we're going to release the cache buffers,
        // notify VRT to stop
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

        if(m_mediaList)
        {
            m_mediaList->releaseForegroundMemory();
        }
        // close media list if it is not prepared
        if(!isMediaListPrepared)
        {
            closeMediaList();
        }
    }

    // clear file Op and all UI CP
    VFX_OBJ_CLOSE(m_grid);
    // destroy media list
    closeMediaList();
}

void VappGalleryShootingPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_ENTER);
    VappGalleryPage::onEnter(isBackward);
    showPageMessage(VFX_FALSE);

    // for wallpaper, we create medialist immediatly.
    if(m_wallpaperInfo)
    {
        createMediaList();
    }
    createGrid();
}

void VappGalleryShootingPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_ENTERED);
    VappGalleryPage::onEntered();

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    // for wallpaper, we create list in onEnter() already.
    if(NULL == m_wallpaperInfo)
    {
        createMediaList();
    }
    checkUpdate();
}

void VappGalleryShootingPage::onUpdate()
{
    if(m_grid)
    {
        m_grid->checkUpdate();
    }
    VappGalleryPage::onUpdate();
}

void VappGalleryShootingPage::configCustomFolder(const VfxWString &folderPath, CustomFolderFilter filter)
{
    m_customFolderPath = folderPath;
    m_customFolderFilter = filter;
}

void VappGalleryShootingPage::configWallpaperMode(IWallpaperSourceStruct *sourceInfo)
{
    m_wallpaperInfo = sourceInfo;
    return;
}

void VappGalleryShootingPage::configNoCameraButton(VfxBool isHideCameraButton)
{
#ifdef __VAPP_GALLERY_ENABLE_CAMERA__
    m_isHideCameraButton = isHideCameraButton;
#else
    m_isHideCameraButton = VFX_TRUE;
#endif
}

void VappGalleryShootingPage::configSortMethod(const U32 sortMethod)
{
    m_sortMethod = sortMethod;
}

void VappGalleryShootingPage::updateViewCellCount(const VfxS32 offset)
{
    m_viewCellCount = VFX_MAX(m_viewCellCount + offset, 0);
}

void VappGalleryShootingPage::createMediaList()
{
    // backward or not, re-initialize the MediaCache.
    if(NULL == m_mediaList)
    {
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);

        if(NULL == m_wallpaperInfo)
        {
            m_mediaList = createMediaCacheMediaList();
        }
        else
        {
            // use wallpaper data source
            VappGalleryMediaListCommon *pList = NULL;
            VFX_OBJ_CREATE_EX(pList, VappGalleryMediaListCommon, this, (CACHE_TYPE_THUMBNAIL));
            pList->configWallpaperInfo(m_wallpaperInfo);
            m_mediaList = pList;
        }

        // start prepare media list
        m_mediaList->getListEvent()->connect(this, &VappGalleryShootingPage::onMediaListReady);
        m_mediaList->prepareList();
    }
    else
    {
        // see if we should refresh the list,
        // or simply redraw the thumbnails
        VfxBool shouldRefresh = VFX_FALSE;
        do
        {
            if(!m_mediaList->canRefreshList())
            {
                break;
            }

            // if deleting or sharing file,
            // don't refresh
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
            if(m_fileOp)
            {
                break;
            }
#endif
            // no matter whether multi-selection or not,
            // refresh only if file list is dirty
            if(m_mediaList->canCheckDirty() && !m_mediaList->checkDirty())
            {
                break;
            }

            shouldRefresh = VFX_TRUE;
        }while(0);

        if(shouldRefresh)
        {
            // must leave multi-selection before refresh,
            // since the selection info won't be valid after refresh.
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
            if(m_grid && m_grid->isMultiSelecting())
            {
                m_grid->endMultiSelect();
            }
#endif
            setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
            m_mediaList->refreshList();
            m_mediaList->obtainForegroundMemory();
        }
        else
        {
            // directly restore thumbs
            m_mediaList->obtainForegroundMemory();
            onMediaListReady(PREPARE_OK);
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
            if(m_fileOp)
            {
                m_mediaList->enableBackgroundDecode(VFX_FALSE);
            }
#endif
        }
    }
}

void VappGalleryShootingPage::getInputFolder(VfxWString &folderPath)
{

    if(!m_customFolderPath.isNull() && !m_customFolderPath.isEmpty())
    {
        folderPath = m_customFolderPath;
    }
    else
    {
        VappGalleryStorageSetting setting;
        const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
        VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                    defaultDrv,
                                                    VappGalleryFmgrDefaultFolder::MY_SHOOTING,
                                                    folderPath);
    }
    return;
}

VfxSize VappGalleryShootingPage::getThumbSize()
{
    // video thumbnail must be even number.
    // note that this may cause VfxFrame to resize the thumbnail again.
    const VfxS32 thumbWidth = VappMediaGridComponentLayout::CELL_WIDTH / 2 * 2;
    const VfxS32 thumbHeight = VappMediaGridComponentLayout::CELL_HEIGHT / 2 * 2;
    VFX_DEV_ASSERT(thumbWidth >= 2);
    VFX_DEV_ASSERT(thumbHeight >= 2);
    return VfxSize(thumbWidth, thumbHeight);
}

VappGalleryMediaListCommon* VappGalleryShootingPage::createMediaCacheMediaList()
{
    // use file manager data source
    VappGalleryMediaListCommon *pList;
    VFX_OBJ_CREATE_EX(pList, VappGalleryMediaListCommon, this, (CACHE_TYPE_THUMBNAIL));

    // check if client set custom file type filter
    VcuiGalleryPickerBase *cuiPicker = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    VappGalleryApp *appGallery  = VFX_OBJ_DYNAMIC_CAST(getApp(), VappGalleryApp);

    VfxWString inputFolder;
    getInputFolder(inputFolder);

    // image folder is assign by client.
    pList->configPath(inputFolder);

    switch(m_customFolderFilter)
    {
    case ALLOW_IMAGE:
    case ALLOW_VIDEO:
        {
            // image folder scans only image, no video
            FMGR_FILTER filter;
            FMGR_FILTER_INIT(&filter);
            if(ALLOW_IMAGE == m_customFolderFilter)
            {
                FMGR_FILTER_SET_IMAGE(&filter);
            }
            else if(ALLOW_VIDEO == m_customFolderFilter)
            {
                FMGR_FILTER_SET_VIDEO(&filter);
            }
            pList->configFileTypeFilter(&filter);
        }
    case ALLOW_ALL:
    default:
        break;
    }

    // intersect with custom-supplied filter
    if(cuiPicker)
    {
        pList->configFileTypeFilter(cuiPicker->getTypeFilter());
    }

    // set sorting method
    pList->configSortMethod(m_sortMethod);

    return pList;
}

void VappGalleryShootingPage::closeMediaList()
{
    if(m_mediaList)
    {
        m_mediaList->release();
        m_mediaList = NULL;
    }
}

void VappGalleryShootingPage::onMediaListReady(VappGalleryPrepareResult prepareResult)
{
    VfxBool noContent = VFX_TRUE;
    for(VfxS32 g = 0; g < m_mediaList->getGroupCount(); ++g)
    {
        if(m_mediaList->getMediaCountInGroup(0) > 0)
        {
            noContent = VFX_FALSE;
            break;
        }
    }

    if(noContent)
    {
        VfxId strId = STR_ID_VAPP_GALLERY_NO_IMG_VID;
        switch(m_customFolderFilter)
        {
        case ALLOW_ALL:
            strId = STR_ID_VAPP_GALLERY_NO_IMG_VID;
            break;
        case ALLOW_IMAGE:
            strId = (PN_MY_SHOOTING == (PageName)getId()) ? STR_ID_VAPP_GALLERY_NO_PHT : STR_ID_VAPP_GALLERY_NO_IMG;
            break;
        case ALLOW_VIDEO:
            strId = STR_ID_VAPP_GALLERY_NO_VID;
            break;
        }
        setPageMessage(VFX_WSTR_RES(strId));
        showPageMessage(VFX_TRUE);
        // re-create a camera only toolbar
        createToolbar(VFX_TRUE);
        m_grid->setDummyCellCount(0);
    }
    else
    {
        showPageMessage(VFX_FALSE);
        // at this point, the media grid may be
        // already created (because we may re-enter from background)
        // set medialist here
        if(m_grid && NULL == m_wallpaperInfo)
        {
            m_grid->setMediaList(m_mediaList);
            m_grid->update();
        }

        // create toolbar if necessary.
        if(NULL == getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
            if(NULL == cui)
            {
                // create full toolbar
                createToolbar(VFX_FALSE);
            }
            else
            {
                createCuiToolbar();
            }
        }
    }
    showPageWaitIcon(VFX_FALSE);
    m_grid->m_signalThumbTapped.connect(this, &VappGalleryShootingPage::onThumbTapped);
    // not support long press in wallpaper scenario
    if(NULL == m_wallpaperInfo)
    {
        m_grid->m_signalThumbLongPressed.connect(this, &VappGalleryShootingPage::onThumbLongPressed);
    }
}

void VappGalleryShootingPage::getButtonNameImageById(VfxId id, VfxWString &name, MMI_IMG_ID &imgId)
{
    switch(id)
    {
#ifdef __VAPP_GALLERY_ENABLE_CAMERA__
    case 'CAMR':
        name = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_CAMERA);
        imgId = IMG_ID_VAPP_GALLERY_IMG_BAR_ICON_CAMERA;
        break;
#endif
    case 'MOVE':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_MOVE);
        imgId = VCP_IMG_TOOL_BAR_COMMON_ITEM_MOVE;
        break;
    case 'SHAR':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_SHARE);
        imgId = IMG_ID_VAPP_GALLERY_SHARE_BY_BT;
        break;
    }

    return VappGalleryPage::getButtonNameImageById(id, name, imgId);
}


void VappGalleryShootingPage::createGrid()
{
    if(NULL == m_grid)
    {
        // setup thumbnail grid
        VFX_OBJ_CREATE(m_grid, VappMediaGridComponent, this);
        // note: grid always stick to the top.
        // GRID_MARGIN_Y is counted inside the grid.
        m_grid->setPos(VappMediaGridComponentLayout::GRID_MARGIN,
                       0);
        m_grid->setSize(getSize().width - 2 * VappMediaGridComponentLayout::GRID_MARGIN,
                        getSize().height);
        m_grid->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_grid->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    }

    if(m_grid)
    {
        // m_mediaList may be NULL,
        // grid would clear itself.
        m_grid->setMediaList(m_mediaList);
        m_grid->setViewState(&m_viewState);
        if(NULL == m_wallpaperInfo)
        {
            m_grid->setDummyCellCount(m_viewCellCount);
        }
        else
        {
            // in wallpaper case, the medialist is always prepared.
            // so don't insert dummy cell here.
            m_grid->setDummyCellCount(0);
        }
        m_grid->update();
    }
}

void VappGalleryShootingPage::createCuiToolbar()
{
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    if(NULL == cui)
        return;

    // image picker single-select does not have toolbar
    if(!cui->isMultiSelectMode())
    {
        return;
    }
    else
    {
        // multi-select mode have only OK/Cancel
        VcpToolBar *selectBar = NULL;
        VFX_OBJ_CREATE(selectBar, VcpToolBar, this);

        // center button changes according to previous command
        VfxId buttons[] = {'SALL', 'OKAY', 'CNCL'};
        VfxWString btnName;
        MMI_IMG_ID imgId;
        for(int i = 0 ; i < 3; ++i)
        {
            getButtonNameImageById(buttons[i], btnName, imgId);
            selectBar->addItem(buttons[i], btnName, imgId);
        }
        selectBar->m_signalButtonTap.connect(this, &VappGalleryShootingPage::onCuiSelectCommand);
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, selectBar, VFX_TRUE);
    }
#endif
}

void VappGalleryShootingPage::createToolbar(VfxBool cameraOnly)
{
    // special case for wallpaper picker,
    // There is no toolbar in wallpaper mode
    if(m_wallpaperInfo)
    {
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
        return;
    }

    if(cameraOnly && m_isHideCameraButton)
    {
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
        return;
    }

#if !defined(__VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__)
    if(m_isHideCameraButton)
        return;
#endif

    VcpToolBar *toolbar = NULL;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);

    VfxWString btnName;
    MMI_IMG_ID imgId = 0;
    if(cameraOnly)
    {
        // single camera button case
        getButtonNameImageById('CAMR', btnName, imgId);
        toolbar->addItem('CAMR', btnName, imgId);
    }
    else
    {
#if defined(__VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__)
        // default set of buttons
        VfxId buttons[] = {// 'SLDS',  // TODO: there is no 'SLDS' in W11.12MP, because
                                       // 1. there may be pure videos 2. there is no focus highlight to determine start index
                           'CAMR',
                           'SHAR',
                           // 'MOVE',  // TODO: there is no 'MOVE' in W11.12MP
                           'DELE'
                           };
#else
        VfxId buttons[] = {'CAMR'};
#endif
        for(int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); ++i)
        {
            // skip camera button if configured.
            if(m_isHideCameraButton && buttons[i] == 'CAMR')
            {
                continue;
            }
            getButtonNameImageById(buttons[i], btnName, imgId);
            toolbar->addItem(buttons[i], btnName, imgId);
        }
    }
    toolbar->m_signalButtonTap.connect(this, &VappGalleryShootingPage::onToolbarCommand);
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, toolbar, VFX_TRUE);
}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
void VappGalleryShootingPage::createSelectToolbar(VfxId mainCommandId)
{
    VcpToolBar *selectBar = NULL;
    VFX_OBJ_CREATE(selectBar, VcpToolBar, this);

    // center button changes according to previous command
    VfxId buttons[] = {'SALL', mainCommandId, 'CNCL'};
    VfxWString btnName;
    MMI_IMG_ID imgId;
    for(int i = 0 ; i < 3; ++i)
    {
        getButtonNameImageById(buttons[i], btnName, imgId);
        selectBar->addItem(buttons[i], btnName, imgId);
    }
    selectBar->m_signalButtonTap.connect(this, &VappGalleryShootingPage::onToolbarSelectCommand);
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, selectBar, VFX_TRUE);
}
#endif

void VappGalleryShootingPage::launchCameraApp()
{
    srv_appmgr_launch("native.mtk.camcorder");
}

void VappGalleryShootingPage::onToolbarCommand(VfxObject* sender, VfxId id)
{
    VcpToolBar *toolbar = VFX_OBJ_DYNAMIC_CAST(sender, VcpToolBar);
    switch(id)
    {
    case 'CAMR':
        launchCameraApp();
        break;

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    case 'SHAR':
    case 'MOVE':
    case 'DELE':
        {
            if(NULL == m_grid)
            {
                break;
            }
            // these commands require multi-selection,
            // enter multi-selection mode and change toobar.
            m_grid->beginMultiSelect();
            createSelectToolbar(id);
            disableMultiCommandButton(VFX_TRUE);
        }
        break;
#endif

    default:
        // unrecognized command
        VFX_DEV_ASSERT(FALSE);
        return;
    }
}

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
void VappGalleryShootingPage::onToolbarSelectCommand(VfxObject* sender, VfxId id)
{
    if(NULL == m_grid)
        return;

    if('SALL' == id)
    {
        // simply select all
        const VfxBool alreadySelectAll = m_grid->isAllSelected();
        m_grid->setAllSelected(!alreadySelectAll);
        setSelectUnselectButton(alreadySelectAll);
        disableMultiCommandButton(alreadySelectAll);
        return;
    }

    if('CNCL' == id)
    {
        // cancel, simply leave multi-select state.
        m_grid->endMultiSelect();
        createToolbar();
        return;
    }

    // process command. no need to leave multi-select yet.
    // We leave multi-select after confirmation & possible progress indicator.
    if(m_fileOp)
    {
        VFX_OBJ_CLOSE(m_fileOp);
        m_fileOp = NULL;
    }
    VFX_OBJ_CREATE(m_fileOp, VappGalleryMultiFileOperationUI, this);
    m_fileOp->configParentPage(this);
    m_fileSequence.config(m_mediaList, m_grid->getSelectionBitSet());
    m_fileOp->configFileSequence(&m_fileSequence);
    m_fileOp->configMediaList(m_mediaList);

    if(PN_MY_SHOOTING == (PageName)getId())
    {
        m_fileOp->configPhotoWording(VFX_TRUE);
    }

    switch(id)
    {
    case 'SHAR':
        m_fileOp->m_signalOperationDone.connect(this, &VappGalleryShootingPage::onShareOperationDone);
        m_fileOp->showShareUI();
        break;
    case 'DELE':
        if(m_mediaList && m_mediaList->isPrepared())
        {
            m_mediaList->enableBackgroundDecode(VFX_FALSE);
        }
        m_fileOp->m_signalOperationDone.connect(this, &VappGalleryShootingPage::onDeleteOperationDone);
        m_fileOp->showDeleteUI();
        break;
    case 'MOVE':
        // move is not supported
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);  // unrecognized command
    }
}
#endif

void VappGalleryShootingPage::onCuiSelectCommand(VfxObject* sender, VfxId id)
{
    switch(id)
    {
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    case 'SALL':
        {
            const VfxBool alreadySelectAll = m_grid->isAllSelected();
            m_grid->setAllSelected(!alreadySelectAll);
            setSelectUnselectButton(alreadySelectAll);
            disableMultiCommandButton(alreadySelectAll);
        }
        return;
#endif
    case 'OKAY':
        {

            VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
            if(m_grid)
            {
 #ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
                cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_OK, m_mediaList, m_grid->getSelectionBitSet());
 #else
 				cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_OK, m_mediaList, 0, 0);
 #endif
            }
        }
        return;
    case 'CNCL':
        exit();
        return;
    }
}

void VappGalleryShootingPage::onShareOperationDone(VfxObject* sender, VappGalleryFileOpResult result)
{
    onFileOperationDone(sender, result, VFX_FALSE, VFX_FALSE);
}

void VappGalleryShootingPage::onRequireResourceRelease()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_SHOOTING_ON_REQUIRE_RES_RELEASE);
    onPageInactiveImpl();
    onPageInactived2Impl();
}

void VappGalleryShootingPage::onDeleteOperationDone(VfxObject* sender, VappGalleryFileOpResult result)
{
    onFileOperationDone(sender, result, VFX_TRUE, VFX_TRUE);
    // [MAUI_03207774] HACK: 
    // base menu dose not expect base menu's conent count varies dynamically
    // in base menu side, if content changed, app should reset, reset layet etc

    // if we do not reset, base menu gets un-sync length while gallery content procider is dirty
    // in this case, base menu freezes while VRT draw content until lendth queried from APP is sync with base menu's cache
    // solution to prevent endless freeze worongly:
    // 1. scroll to top
    // 2. update layout 
    if(m_grid)
    {
        //m_grid->makeVisible(VfxRect(0, 0, m_grid->getSize().width, m_grid->getSize().height), VFX_TRUE);
        m_grid->updateLayout();
    }
}

void VappGalleryShootingPage::onFileOperationDone(VfxObject* sender, VappGalleryFileOpResult result, VfxBool refreshList, const VfxBool notifyErrorMessage)
{
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    if(m_fileOp == sender)
    {
        VFX_OBJ_CLOSE(m_fileOp);
        m_fileOp = NULL;
    }
#endif

    if(result == VGFOR_CANCELLED)
    {
        // resume the decode process, which is paused while user clicked the delete btn
        if(m_grid && m_mediaList && m_mediaList->canRefreshList())
        {
            m_mediaList->enableBackgroundDecode(VFX_TRUE);
        }
        // keep in multi-selection state
        if(m_mediaList &&
           m_mediaList->canRefreshList() &&
           m_mediaList->canCheckDirty() &&
           m_mediaList->checkDirty())
        {
            // must leave multi-selection before refresh,
            // since the selection info won't be valid after refresh.
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
            if(m_grid && m_grid->isMultiSelecting())
            {
                m_grid->endMultiSelect();
                createToolbar();
            }
#endif
            m_grid->releaseAllCachedImage();
            m_mediaList->refreshList();
            m_mediaList->enableBackgroundDecode(VFX_TRUE);
        }
        return;
    }
    else
    {
        if(m_grid)
        {
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
			// leave multi-selection mode
            m_grid->endMultiSelect();
#endif
            m_grid->getViewState(&m_viewState);
        }

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        // re-init toolbar
        createToolbar();
#endif

        if(refreshList)
        {
            // force update the list.
            // we close then open, so there is no animation.
            if(m_grid && m_mediaList && m_mediaList->canRefreshList())
            {
                m_grid->releaseAllCachedImage();
                m_mediaList->refreshList();
                m_mediaList->enableBackgroundDecode(VFX_TRUE);
            }
            else
            {
                closeMediaList();
                createMediaList();
            }
        }

        // check error and notify user.
        if(notifyErrorMessage && result == VGFOR_ERROR)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_GALLERY_CANNOT_DELETE).getBuf());
        }
        return;
    }
}


void VappGalleryShootingPage::onSingleItemMenuCommand(VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item)
{
    if(VCP_MENU_POPUP_EVENT_ITEM_SELECTED != evt)
        return;

    VFX_ASSERT(item);
    VfxId btnId = item->getId();

    VappGallerySingleFileMenuPopup *menuPopup = static_cast<VappGallerySingleFileMenuPopup*>(sender);

    VappGallerySingleFileOperationUI *fileOp = NULL;
    VFX_OBJ_CREATE(fileOp, VappGallerySingleFileOperationUI, this);
    fileOp->configParentPage(this);
    fileOp->configFilePath(menuPopup->m_filePath);

    switch (btnId)
    {
    case 'SHAR':
        fileOp->m_signalOperationDone.connect(this, &VappGalleryShootingPage::onShareOperationDone);
        fileOp->m_signalReleaseResource.connect(this, &VappGalleryShootingPage::onRequireResourceRelease);
        fileOp->showShareUI();
        break;
    case 'DELE':
        fileOp->m_signalOperationDone.connect(this, &VappGalleryShootingPage::onDeleteOperationDone);
        fileOp->showDeleteUI();
        break;
    default:
        VFX_OBJ_CLOSE(fileOp);
        break;
    }
    return;
}

void VappGalleryShootingPage::onBack()
{
    // special case for wallpaper picker
    if(NULL != m_wallpaperInfo)
    {
        // ignore group tapp event
        VcuiGalleryWallpaperPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryWallpaperPicker);
        if(cui)
        {
            cui->finishPickOperation(VcuiGalleryWallpaperPicker::WALLPAPER_PICK_Cancel, VcpMenuPos(0, -1));
        }
        return;
    }
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    if(m_grid && m_grid->isMultiSelecting())
    {
        // cancel, simply leave multi-select state.
        m_grid->endMultiSelect();
        createToolbar();
        return;
    }
#endif
    VappGalleryPage::onBack();
}

void VappGalleryShootingPage::onThumbTapped(VcpMenuPos tappedPos, VfxFrame* thumbTapped)
{
    // special case for wallpaper picker
    if(NULL != m_wallpaperInfo)
    {
        // ignore group tapp event
        if(tappedPos.pos < 0)
        {
            return;
        }
        VappGalleryWallpaperPreviewPage *wallpaperPreview = NULL;
        VFX_OBJ_CREATE(wallpaperPreview, VappGalleryWallpaperPreviewPage, getMainScr());
        wallpaperPreview->setWallpaperSource(m_wallpaperInfo);

        VfxS32 groupCount = 0;
        VfxS32 liveWallpaperGroupId = 0;
        VfxS32 staticWallpaperGroupId = 0;
        VfxS32 videoWallpaperGroupId = 0;
        VappGalleryMediaListCommon::getGroupInfoFromWallpaperInfo(
                                                    *m_wallpaperInfo,
                                                    groupCount,
                                                    liveWallpaperGroupId,
                                                    staticWallpaperGroupId,
                                                    videoWallpaperGroupId
                                                    );
        VappWpResType type = VAPP_WALLPAPER_STATIC_WALLPAPER;
        if(liveWallpaperGroupId == tappedPos.group)
        {
            type = VAPP_WALLPAPER_LIVE_WALLPAPER;
        }
        else if(staticWallpaperGroupId == tappedPos.group)
        {
            type = VAPP_WALLPAPER_STATIC_WALLPAPER;
        }
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
        else if(videoWallpaperGroupId == tappedPos.group)
        {
            type = VAPP_WALLPAPER_VIDEO_WALLPAPER;
        }
#endif
        else
        {
            VFX_ASSERT(0);
        }

        wallpaperPreview->setSelectedWallpaper(type, tappedPos.pos);
        wallpaperPreview->setCustomTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IMG_PREVIEW));

        // go to wallpaper preview page
        getMainScr()->pushPage(0, wallpaperPreview);
    }
    else
    {
        // block file operation if it is reloading now
        if(m_mediaList->isReloading())
            return;

        VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        if(cui && !cui->isMultiSelectMode() && m_grid)
#else
		if(cui && m_grid)
#endif
        {
            // check for path too long case.
            // directly disallows user to choose it.
            if(m_mediaList)
            {
                VfxWString mediaPath;
                const VappGalleryDecodeResult pathRes = m_mediaList->getMediaPath(tappedPos, mediaPath);
                if(OK != pathRes)
                {
                    VfxId errStrId = STR_ID_VAPP_GALLERY_IDX_SCANNING;
                    switch(pathRes)
                    {
                    case DECODING:
                        errStrId = STR_ID_VAPP_GALLERY_IDX_SCANNING;
                        break;
                    case PATH_TOO_DEEP:
                        errStrId = srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR);
                        break;
                    }
                    VfxWString ballonText = VFX_WSTR_RES(errStrId);
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, ballonText);
                }
                else
                {
                    // user choose a valid path, since this is a
                    // single select CUI, notify parent immediately
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
                    SimpleBitSet *bitset = m_grid->getSelectionBitSet();
                    bitset->clearAll();
                    bitset->set(tappedPos);
                    VappMediaGridComponentCell *cell = VFX_OBJ_DYNAMIC_CAST(m_grid->getCellIfPresent(tappedPos.group, tappedPos.pos),
                                                                          VappMediaGridComponentCell);
                    cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_OK,
                                                 m_mediaList,
                                                 bitset,
                                                 cell ? cell->getContentDecodeState() : VCUI_GALLERY_MEDIA_STATE_UNKNOWN
                                                 );
#else
					VappMediaGridComponentCell *cell = VFX_OBJ_DYNAMIC_CAST(m_grid->getCellIfPresent(tappedPos.group, tappedPos.pos),
                                                                          VappMediaGridComponentCell);
                    cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_OK,
                                                 m_mediaList,
                                                 tappedPos.group, 
                                                 tappedPos.pos,
                                                 cell ? cell->getContentDecodeState() : VCUI_GALLERY_MEDIA_STATE_UNKNOWN
                                                 );
#endif
                }
            }
        }
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        else if(m_grid && m_grid->isMultiSelecting())
        {
            // check select/unselect all
            const VfxBool alreadySelectAll = m_grid->isAllSelected();
            setSelectUnselectButton(!alreadySelectAll);
            // enable/disable command button
            disableMultiCommandButton(!m_grid->isAnySelected());
        }
#endif
        else
        {
            VFX_ASSERT(m_mediaList);
			VappGalleryMediaGroupType groupType = m_mediaList->getMediaGroupType(tappedPos);
            if(MEDIA_GROUP_VIDEO == groupType)
            {
                // launch video player
                gotoVideoPlayer(tappedPos);
            }
            else if(MEDIA_GROUP_IMAGE == groupType)
            {
                // launch Image Viewer (file-based)
                gotoImageViewer(tappedPos);
            }
			// TODO: define string id
			else if(MEDIA_GROUP_WAIT_DECODING == groupType)
			{
				mmi_frm_nmgr_balloon(
	                MMI_SCENARIO_ID_DEFAULT,
	                MMI_EVENT_INFO_BALLOON,
	                MMI_NMGR_BALLOON_TYPE_FAILURE,
	                (WCHAR *)VFX_WSTR("File is reloading, please wait...").getBuf());
			}
			
        }
    }
}

void VappGalleryShootingPage::onThumbLongPressed(VcpMenuPos pressedPos)
{
    do
    {
        if(NULL == m_mediaList || !m_mediaList->isPrepared())
            return;

#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
        if(m_fileOp)
            return;
#endif

        if(m_singleFilePopup.isValid())
            return;

        // in select only mode, do not allow file operation no matter whether
        // it is multi-selection or single selection
        if(isSelectOnlyMode())
            return;

        // block file operation if it is reloading now
        if(m_mediaList->isReloading())
            return;
    }while(0);

    // play touch feedback
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    VfxWString mediaName;
	VfxWString mediaPath;
    if(OK == m_mediaList->getMediaName(pressedPos, mediaName) && 
		OK == m_mediaList->getMediaPath(pressedPos, mediaPath))
    {	
    	// create menu and set up title
    	VFX_OBJ_CLOSE(m_singleFilePopup);
    	VFX_OBJ_CREATE(m_singleFilePopup, VappGallerySingleFileMenuPopup, getMainScr());

		m_singleFilePopup->m_filePath = mediaPath;
		m_singleFilePopup->setTitle(mediaName);
	    m_singleFilePopup->setAutoDestory(VFX_TRUE);
	    m_singleFilePopup->m_signalMenuCallback.connect(this, &VappGalleryShootingPage::onSingleItemMenuCommand);

	    VfxId buttons[2] = {'SHAR', 'DELE'};
	    VfxWString btnName;
	    MMI_IMG_ID imgId = 0;
	    for(VfxS32 i = 0; i < 2; ++i)
	    {
	        getButtonNameImageById(buttons[i], btnName, imgId);
	        m_singleFilePopup->addItem(buttons[i], btnName);
	    }
	    m_singleFilePopup->show(VFX_TRUE);
    }
}

void VappGalleryShootingPage::gotoVideoPlayer(const VcpMenuPos &tappedPos)
{
    VFX_ASSERT(m_mediaList);
    VfxWString path;
    if(OK == m_mediaList->getMediaPath(tappedPos, path))
    {
        // launch video player when video thumb is tapped
        VappGalleryPlayerPage *playerPage = NULL;
        VFX_OBJ_CREATE(playerPage, VappGalleryPlayerPage, getMainScr());
        playerPage->setLocalFile(path);
        // show player page
        getMainScr()->pushPage(0, playerPage);
    }
}


VfxBool VappGalleryShootingPage::isSelectOnlyMode() const
{
    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    return (cui  ? VFX_TRUE : VFX_FALSE);
}


VfxBool VappGalleryShootingPage::isImageOnly()
{
    return m_customFolderFilter == ALLOW_IMAGE;
}

void VappGalleryShootingPage::gotoImageViewer(const VcpMenuPos &tappedPos, VfxBool playSlideshow)
{
    VappGalleryViewerPage *viewerPage = NULL;
    VFX_OBJ_CREATE(viewerPage, VappGalleryViewerPage, getMainScr());

    // config viewer page index
    VfxWString inputFolder;
    getInputFolder(inputFolder);
    const VfxBool imageOnly = isImageOnly();
    viewerPage->configFolderAndIndex(inputFolder,
                                     tappedPos.pos,
                                     imageOnly,
                                     VFX_FALSE,
                                     m_sortMethod
                                     );
    viewerPage->configSlideshowAutoStart(playSlideshow);

    // go to viewer page
    getMainScr()->pushPage(0, viewerPage);
    return;
}

#endif
