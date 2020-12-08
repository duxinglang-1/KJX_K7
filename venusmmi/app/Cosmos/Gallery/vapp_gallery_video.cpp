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
 *  vapp_gallery_video.cpp
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

#include "mmi_rp_vapp_gallery_def.h"
#include "vapp_gallery_video.h"
#include "vcp_include.h"
#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_gallery_data.h"
#include "vapp_gallery_player.h"
#include "vapp_gallery_util.h"
#include "vapp_gallery_setting.h"
#include "vfx_adp_device.h"
extern "C"
{
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
}

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_GALLERY_PROP_ID_VIDEO_PAGE_MAIN_TOOLBAR    0x0370

// Since the thumbnails are cached item, their size are decided by
// the Cache item.
#define VTHUMB_WIDTH (VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W)
#define VTHUMB_HEIGHT (VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H)
#define VTHUMB_BK_COLOR (231)

enum VappGalleryVideoListLayout
{
#if defined(__MMI_MAINLCD_320X480__)
    TITLE_LINE_TOP = 5,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 30,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    LAST_PLAY_ICON_TOP = 29,
    LAST_PLAY_ICON_LEFT = 23,
    BOOKMARK_TEXT_LEFT = 88,
    TIME_TEXT_W = 62,
    TIME_TEXT_h = 20,

#elif defined(__MMI_MAINLCD_480X800__)
    TITLE_LINE_TOP = 12,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 57,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    LAST_PLAY_ICON_TOP = 52,
    LAST_PLAY_ICON_LEFT = 31,
    BOOKMARK_TEXT_LEFT = 121,
    TIME_TEXT_W = 84,
    TIME_TEXT_h = 30,

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    TITLE_LINE_TOP = 5,
    TITLE_LINE_RIGHT = 24,
    DESC_LINE_TOP = 32,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    LAST_PLAY_ICON_TOP = 5,
    LAST_PLAY_ICON_LEFT = 24,
    BOOKMARK_TEXT_LEFT = 54,
    TIME_TEXT_W = 47,
    TIME_TEXT_h = 20,

#else
    // prevent build error
    TITLE_LINE_TOP = 5,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 30,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    LAST_PLAY_ICON_TOP = 26,
    LAST_PLAY_ICON_LEFT = 23,
    BOOKMARK_TEXT_LEFT = 65,
    TIME_TEXT_W = 45,
    TIME_TEXT_h = 20,

#endif
};

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryVideoPage", VappGalleryVideoPage, VappGalleryPage);

VappGalleryVideoPage::VappGalleryVideoPage():
    m_mediaList(NULL)
    ,m_videoMenu(NULL)
    ,m_videoDB(NULL)
    ,m_isScrolling(VFX_FALSE)
    ,m_isMultiSelecting(VFX_FALSE)
    ,m_isExit(VFX_FALSE)
    ,m_multiFileOp(NULL)
    ,m_thumbRefreshTimer(NULL)
{
    m_selectedSet.clearAll();
}

void VappGalleryVideoPage::onInit()
{
    VappGalleryPage::onInit(); // call base class

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    kal_mem_set(&m_viewState, 0, sizeof(m_viewState));

    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_VIDEO));
    setTopBar(bar);

    startRefreshTimer(VFX_TRUE, __LINE__);
}

void VappGalleryVideoPage::onDeinit()
{
    if(m_multiFileOp)
    {
        VFX_OBJ_CLOSE(m_multiFileOp);
        m_multiFileOp = NULL;

    }

    VappGalleryPage::onDeinit();
}

void VappGalleryVideoPage::setupVideoMenu()
{
    if(NULL == m_videoMenu)
    {
        VFX_OBJ_CREATE(m_videoMenu, VcpGroupListMenu, this);
        // use default VcpListMenu item height
        m_videoMenu->setSize(getSize());
        m_videoMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT);
        m_videoMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
        m_videoMenu->m_signalItemTapped.connect(this, &VappGalleryVideoPage::onItemTapped);
        m_videoMenu->m_signalItemLongTapped.connect(this, &VappGalleryVideoPage::onItemLongTapped);
        m_videoMenu->m_signalItemSelectionStateChanged.connect(this, &VappGalleryVideoPage::onItemSelectionChange);
        m_videoMenu->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);
        m_videoMenu->setContentProvider(this);
        m_videoMenu->m_signalViewScrollStart.connect(this, &VappGalleryVideoPage::handleViewScrollStart);
        m_videoMenu->m_signalViewScrollEnd.connect(this, &VappGalleryVideoPage::handleViewScrollEnd);
    }

    m_videoMenu->setMenuMode(
                    isMultiSelecting() ? VCP_LIST_MENU_MODE_MULTI_SELECTION : VCP_LIST_MENU_MODE_NORMAL,
                    VFX_FALSE);
}

void VappGalleryVideoPage::getButtonNameImageById(VfxId id, VfxWString &name, MMI_IMG_ID &imgId)
{
    switch(id)
    {
    case 'SHAR':
        name = VFX_WSTR_RES(VCP_STR_TOOL_BAR_SHARE);
        imgId = IMG_ID_VAPP_GALLERY_SHARE_BY_BT;
        break;
    }
    return VappGalleryPage::getButtonNameImageById(id, name, imgId);
}

void VappGalleryVideoPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_ENTER);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    m_isExit = VFX_FALSE;
    m_isScrolling = VFX_FALSE;

    startRefreshTimer(VFX_TRUE, __LINE__);

    // show waiting icon until list is ready
    showPageWaitIcon(VFX_TRUE);

    // if media list is still alive,
    // it means only foreground mem is released.
    if(m_mediaList)
    {
        onMediaListReady(PREPARE_OK);
    }
}

void VappGalleryVideoPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_ENTERED);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    setupMediaList();
    checkUpdate();
}

void VappGalleryVideoPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_EXIT);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    onPageInactiveImpl();

    // close single file operation UI immediately, since it is a top-level popup,
    // so we should close it before transition animation
    VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    const VfxBool releaseForegroundOnly = isActive() && (NULL == pickerCUI);
    if(m_singleFilePopup.isValid() && !releaseForegroundOnly)
    {
        VFX_OBJ_CLOSE(m_singleFilePopup);
    }

    m_isExit = VFX_TRUE;
    m_isScrolling = VFX_FALSE;
    return;
}

void VappGalleryVideoPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_EXITED2);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    onPageInactived2Impl();

    // for picker CUIs, since they store FMgr list in FG memory,
    // we must release entire media list when exit() this page.
    VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    const VfxBool releaseForegroundOnly = isActive() && (NULL == pickerCUI);
    if(!releaseForegroundOnly)
    {
        if(m_singleFilePopup.isValid())
            VFX_OBJ_CLOSE(m_singleFilePopup);
        VFX_OBJ_CLOSE(m_multiFileOp);
    }
}

void VappGalleryVideoPage::onPageInactiveImpl()
{
    startRefreshTimer(VFX_FALSE, __LINE__);

    if(m_mediaList)
    {
        m_mediaList->enableBackgroundDecode(VFX_FALSE);
    }
}

void VappGalleryVideoPage::onPageInactived2Impl()
{
    startRefreshTimer(VFX_FALSE, __LINE__);

    if(m_videoMenu)
    {
        m_videoMenu->getViewState(&m_viewState);
    }

    if(m_videoMenu)
    {
        m_videoMenu->m_signalViewScrollStart.disconnect(this, &VappGalleryVideoPage::handleViewScrollStart);
        m_videoMenu->m_signalViewScrollEnd.disconnect(this, &VappGalleryVideoPage::handleViewScrollEnd);
    }

    // for picker CUIs, since they store FMgr list in FG memory,
    // we must release entire media list when exit() this page.
    VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);

    // release foreground caches,
    VFX_OBJ_CLOSE(m_videoMenu);
    releaseMediaListForeground();

    VFX_OBJ_CLOSE(m_videoDB);
}

void VappGalleryVideoPage::onUpdate()
{
    VappGalleryPage::onUpdate();
    if(m_videoMenu)
    {
        m_videoMenu->updateAllItems();
    }
}

void VappGalleryVideoPage::onBack()
{
    if(isMultiSelecting())
    {
        // cancel, simply leave multi-select state.
        createToolbar();
        endMultiSelect();
        return;
    }

    VappGalleryPage::onBack();
}

void VappGalleryVideoPage::onThumbRefresh(VfxTimer *source)
{
    VFX_UNUSED(source);

    if(!m_videoMenu || !m_mediaList || !m_mediaList->isPrepared())
    {
        return;
    }

    // when doing file operation, do not access file again
    if(m_multiFileOp)
    {
        return;
    }

    const VcpMenuRegion visibleRange = m_videoMenu->getRealContentRegion();
    if(visibleRange.isEmpty())
    {
        return;
    }

    VcpMenuRegionIter iter(m_videoMenu, visibleRange);
    while(!iter.isEnd())
    {
        const VcpMenuPos p = iter.next();
        VcpListMenuCell *pCell = m_videoMenu->getCell(p);
        if(pCell)
        {
            // get custom content frame from Cell
            VappGalleryVideoMenuItemFrame *pItemFrame = static_cast<VappGalleryVideoMenuItemFrame*>(pCell->m_clientFrame);
            if(pItemFrame)
            {
                if(!pItemFrame->isContentReady())
                {
                    m_videoMenu->updateItem(p);
                    return;
                }
            }
        }
    }
    startRefreshTimer(VFX_FALSE, __LINE__);
    return;
}

void VappGalleryVideoPage::handleViewScrollStart(VcpBaseListMenu *menu)
{
    GALLERY_MEASURE_TIME_START("GsS");

    m_isScrolling = VFX_TRUE;
    if(m_mediaList)
    {
        m_mediaList->enableBackgroundDecode(VFX_FALSE);
    }
    startRefreshTimer(VFX_FALSE, __LINE__);
}

void VappGalleryVideoPage::handleViewScrollEnd(VcpBaseListMenu *menu)
{
    m_isScrolling = VFX_FALSE;
    startRefreshTimer(VFX_TRUE, __LINE__);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_VIEW_SCROLL_END_M_THUMB_REFRESH_TIMER_START);
    GALLERY_MEASURE_TIME_STOP("GsS");
}

void VappGalleryVideoPage::setupMediaList()
{
    if(NULL == m_videoDB)
    {
        VFX_OBJ_CREATE(m_videoDB, VappGalleryDB, this);
    }

    if(NULL == m_mediaList)
    {
        // concrete-type dependent
        VappGalleryMediaListVideoInfo *pMediaList = NULL;
        VFX_OBJ_CREATE(pMediaList, VappGalleryMediaListVideoInfo, this);
        // set DB into MediaList
        pMediaList->configVideoDB(m_videoDB);

        // tell data list which storage to scan.
        VappGalleryStorageSetting setting;
        const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
        pMediaList->configFolderPaths(defaultDrv);

        // config extra filter if any
        VcuiGalleryVideoPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPicker);
        if(cui)
        {
            pMediaList->configFileTypeFilter(cui->getTypeFilter());
        }

        // assign to member variable
        m_mediaList = pMediaList;
        m_mediaList->getListEvent()->connect(this, &VappGalleryVideoPage::onMediaListReady);
        m_mediaList->getDecodeEvent()->connect(this, &VappGalleryVideoPage::onDecodeResult);
        m_mediaList->getListReloadStartEvent()->connect(this, &VappGalleryVideoPage::onReloadListStart);
        m_mediaList->getListReloadFinishedEvent()->connect(this, &VappGalleryVideoPage::onReloadListFinished);

        // start async preparation
        m_mediaList->prepareList();
    }
    else
    {
        // set DB into MediaList
        m_mediaList->configVideoDB(m_videoDB);

        // see if we should refresh the list,
        VfxBool shouldRefresh = VFX_FALSE;
        do
        {
            if(!m_mediaList->canRefreshList())
            {
                break;
            }

            // if deleting or sharing file,
            // don't refresh
            if(m_multiFileOp)
            {
                break;
            }

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
            m_mediaList->refreshList();
            m_mediaList->obtainForegroundMemory();
            endMultiSelect();
        }
        else
        {
            // directly restore thumbs
            m_mediaList->obtainForegroundMemory();
        }

        checkUpdate();
    }
}

void VappGalleryVideoPage::closeMediaList()
{
    VFX_OBJ_CLOSE(m_mediaList);
}

void VappGalleryVideoPage::releaseMediaListForeground()
{
    if(m_mediaList)
    {
        m_mediaList->releaseForegroundMemory();
    }
}

void VappGalleryVideoPage::onMediaListReady(VappGalleryPrepareResult prepareResult)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_MEDIA_LIST_READY);
    VfxBool noContent = VFX_TRUE;
    for(VfxS32 i = 0; i < m_mediaList->getGroupCount(); ++i)
    {
        if(0 != m_mediaList->getMediaCountInGroup(i))
        {
            noContent = VFX_FALSE;
            break;
        }
    }

    if(noContent)
    {
        setPageMessage(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_PUT_VID_HINT));
        showPageMessage(VFX_TRUE);
        if(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
        }
        // reset multi-select
        endMultiSelect();
    }
    else
    {
        showPageMessage(VFX_FALSE);
        // create video list after list ready
        setupVideoMenu();
        checkUpdate();

        // show the toolbar
        // create main bottom tool bar
        if(!isSelectOnlyMode())
        {
            if(isMultiSelecting())
            {
                // if we're already in multi-selectio mode,
                // no need to update toolbar.
            }
            else
            {
                createToolbar();
            }
        }
        else
        {
            // select only mode,
            // single ==> no tool bar
            // multi ==> Select All/OK/Cancel
            VcuiGalleryVideoPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPicker);
            if(cui && cui->isMultiSelectMode())
            {
                createCuiToolbar();
            }
        }
    }

    if(m_videoMenu)
    {
        m_videoMenu->m_signalViewScrollStart.connect(this, &VappGalleryVideoPage::handleViewScrollStart);
        m_videoMenu->m_signalViewScrollEnd.connect(this, &VappGalleryVideoPage::handleViewScrollEnd);
        m_videoMenu->setViewState(&m_viewState);
    }
    showPageWaitIcon(VFX_FALSE);
}

void VappGalleryVideoPage::onDecodeResult(VcpMenuPos index, VappGalleryDecodeResult result)
{
    VcpListMenuCell *pCell = m_videoMenu->getCell(index);
    if(NULL == pCell)
    {
        // if cell not exist, unlock the cache
        VfxImageBuffer buf;
        buf.ptr = NULL;
        buf.pitchBytes = 0;
        buf.width = 0;
        buf.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
        m_mediaList->unlockThumb(index, buf);

        return;
    }

    VappGalleryVideoMenuItemFrame *pItemFrame = static_cast<VappGalleryVideoMenuItemFrame*>(pCell->m_clientFrame);
    switch(result)
    {
    case OK:
    case FORMAT_UNSUPPORTED:
    case DRM_LOCKED:
        // already decoded, directly update
        m_videoMenu->updateItem(index);
        // trigger prefresh timer only if menu is not scrollong now
        if(!m_isScrolling)
        {
            startRefreshTimer(VFX_TRUE, __LINE__);
        }
        if(pItemFrame)
        {
            pItemFrame->setQueryFinished(VFX_TRUE);
        }
        break;
    default:
        // decoding, waiting for decodeCallBack
        m_thumbRefreshTimer->stop();
        break;
    }
}

void VappGalleryVideoPage::onReloadListStart(VcpMenuPos mediaPos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_RELOAD_LIST, mediaPos.group, mediaPos.pos, 1);
    startRefreshTimer(VFX_FALSE, __LINE__);
    showPageWaitIcon(VFX_TRUE);
}

void VappGalleryVideoPage::onReloadListFinished(VcpMenuPos mediaPos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_RELOAD_LIST, mediaPos.group, mediaPos.pos, 2);
    startRefreshTimer(VFX_TRUE, __LINE__);
    showPageWaitIcon(VFX_FALSE);
}

void VappGalleryVideoPage::startRefreshTimer(const VfxBool start, const VfxU32 line)
{
    if(NULL == m_thumbRefreshTimer)
    {
        VFX_OBJ_CREATE(m_thumbRefreshTimer, VfxTimer, this);
        m_thumbRefreshTimer->setStartDelay(50);
        m_thumbRefreshTimer->setDuration(50);
        m_thumbRefreshTimer->m_signalTick.connect(this, &VappGalleryVideoPage::onThumbRefresh);
    }

    if(start)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_M_THUMB_REFRESH_TIMER_START_LINE_D, line);
        m_thumbRefreshTimer->start();
        GALLERY_MEASURE_TIME_START("Grt");
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_M_THUMB_REFRESH_TIMER_STOP_LINE_D, line);
        m_thumbRefreshTimer->stop();
        GALLERY_MEASURE_TIME_STOP("Grt");
    }
}

void VappGalleryVideoPage::onItemLongTapped(VcpGroupListMenu *sender, VcpMenuPos index)
{
    if(isSelectOnlyMode())
    {
        return;
    }

    if(NULL == m_mediaList)
    {
        return;
    }

    if(isMultiSelecting())
    {
        return;
    }

    if(m_mediaList->isReloading())
    {
        return;
    }

    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    // otherwise we show a popup dialog, with filename as its title
    if(m_singleFilePopup.isValid())
    {
        VFX_OBJ_CLOSE(m_singleFilePopup);
    }
    VFX_OBJ_CREATE(m_singleFilePopup, VappGallerySingleFileMenuPopup, getMainScr());
    VfxWString mediaName;
    if(OK == m_mediaList->getMediaName(index, mediaName))
    {
        m_singleFilePopup->setTitle(mediaName);
    }

    m_mediaList->getMediaPath(index, m_singleFilePopup->m_filePath);
    m_singleFilePopup->setAutoDestory(VFX_TRUE);
    m_singleFilePopup->m_signalMenuCallback.connect(this, &VappGalleryVideoPage::onSingleItemMenuCommand);

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

void VappGalleryVideoPage::onItemTapped(VcpGroupListMenu *sender, VcpMenuPos index)
{
    if(m_mediaList->isReloading())
    {
        return;
    }

    if(isSelectOnlyMode())
    {
        // Must be in an Video Picker CUI to work
        VcuiGalleryVideoPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPicker);
        VFX_ASSERT(cui);

        // retrieve selection is always stored in selectedSet
        // so we set it here
        m_selectedSet.clearAll();
        m_selectedSet.set(index);

        vcui_gallery_media_state_enum mediaState = VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
        do
        {
            if(NULL == sender)
                break;

            VcpListMenuCell *pCell = sender->getCell(index);
            if(NULL == pCell)
                break;

            VappGalleryVideoMenuItemFrame *pItemFrame = static_cast<VappGalleryVideoMenuItemFrame*>(pCell->m_clientFrame);
            if(NULL == pItemFrame)
                break;

            mediaState = pItemFrame->getContentDecodeState();
        }while(0);

        cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_OK,
                                     m_mediaList,
                                     &m_selectedSet,
                                     mediaState
                                     );
        return;
    }

    // under multi-select mode, there is no need to handle this event.
    if(isMultiSelecting())
    {
        const VfxBool isAny = isAnySelected();
        disableMultiCommandButton(!isAny);
        const VfxBool isAll = isAllSelected();
        setSelectUnselectButton(!isAll);
        return;
    }

    if(NULL == m_mediaList)
    {
        return;
    }

    VfxWString path;
    m_mediaList->getMediaPath(index, path);

    // jump to video player page.
    // currently video player support only single-file playback.
    // we check the file playback result.
    VappGalleryPlayerPage *playerPage = NULL;
    VFX_OBJ_CREATE(playerPage, VappGalleryPlayerPage, getMainScr());
#ifdef __VAPP_GALLERY_ENABLE_VIDEO_BOOKMARK__
    playerPage->configStoreLastPlay(VFX_TRUE);

    // check if there is a bookmark;
    // start from bookmark to play if there is one.
    U64 bookmark = 0;
    if(OK == m_mediaList->getMediaBookmark(index, bookmark, m_isScrolling) &&
       bookmark != 0)
    {
        playerPage->setLocalFile(path, bookmark);
    }
    else
    {
        playerPage->setLocalFile(path);
    }
#else
    playerPage->setLocalFile(path);
#endif

    // show player page
    getMainScr()->pushPage(0, playerPage);
}

void VappGalleryVideoPage::onItemSelectionChange(VcpGroupListMenu *sender, VcpMenuPos index, VcpListMenuItemStateEnum newState)
{
    // FIXME: handle group in multi-selection logic
    if(VCP_LIST_MENU_ITEM_STATE_SELECTED == newState)
    {
        m_selectedSet.set(index);
    }
    else
    {
        m_selectedSet.clear(index);
    }
}

void VappGalleryVideoPage::createToolbar()
{
 #ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    // check if toolbar already exists
    // if toolbar already exists, we should not re-create one to prevent tool bar flash caused by setbar animation
    do
    {
        VfxPageBar *pagebar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
        if(NULL == pagebar)
        {
            break;
        }
        VcpToolBar *bar = VFX_OBJ_DYNAMIC_CAST(pagebar, VcpToolBar);
        if(bar)
        {
            VfxS32 *b = (VfxS32*)(bar->getAttachProperty(VAPP_GALLERY_PROP_ID_VIDEO_PAGE_MAIN_TOOLBAR, sizeof(VfxS32)));
            if(!(b && *b))
            {
                break;
            }
        }
        return;
    }while(0);

    // tool bar is not exist, create tool bar
    VfxId buttons[3] = {'SHAR', 'DELE', 0};
    VcpToolBar *tbar = createToolbarImpl(buttons, &VappGalleryVideoPage::onToolbarCommand);
    // attach property to inidicate it is main toolbar,  not select toolbar
    const VfxS32 isMainToolbar = 1;
    tbar->setAttachProperty(VAPP_GALLERY_PROP_ID_VIDEO_PAGE_MAIN_TOOLBAR, (void*)&isMainToolbar, sizeof(VfxS32));
#endif
}

VcpToolBar* VappGalleryVideoPage::createToolbarImpl(const VfxId buttons[3], ToolbarHandler handlerMethod)
{
    VcpToolBar *selectBar = NULL;
    VFX_OBJ_CREATE(selectBar, VcpToolBar, this);

    // center button changes according to previous command
    VfxWString btnName;
    MMI_IMG_ID imgId;
    for(int i = 0 ; i < 3; ++i)
    {
        if(0 != buttons[i])
        {
            getButtonNameImageById(buttons[i], btnName, imgId);
            selectBar->addItem(buttons[i], btnName, imgId);
        }
    }
    selectBar->m_signalButtonTap.connect(this, handlerMethod);
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, selectBar, VFX_TRUE);
    return selectBar;
}

void VappGalleryVideoPage::createSelectToolbar(VfxId mainCommandId)
{
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    VfxId buttons[3] = {'SALL', 0, 'CNCL'};
    buttons[1] = mainCommandId;
    createToolbarImpl(buttons, &VappGalleryVideoPage::onToolbarSelectCommand);
#endif
}

void VappGalleryVideoPage::createCuiToolbar()
{
    VfxId buttons[3] = {'SALL', 'OKAY', 'CNCL'};
    createToolbarImpl(buttons, &VappGalleryVideoPage::onCuiSelectCommand);
}

void VappGalleryVideoPage::onToolbarCommand(VfxObject* sender, VfxId id)
{
#ifdef __VAPP_GALLERY_ENABLE_MULTIPLE_SELECT__
    VcpToolBar *toolbar = VFX_OBJ_DYNAMIC_CAST(sender, VcpToolBar);

    // these commands require multi-selection,
    // enter multi-selection mode and change toobar.
    beginMultiSelect();
    createSelectToolbar(id);
    disableMultiCommandButton(VFX_TRUE);
#endif
}

void VappGalleryVideoPage::onSingleItemMenuCommand(VcpMenuPopup* sender, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item)
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
    fileOp->configMediaList(m_mediaList);
    switch (btnId)
    {
    case 'SHAR':
        fileOp->m_signalOperationDone.connect(this, &VappGalleryVideoPage::onShareOperationDone);
        fileOp->m_signalReleaseResource.connect(this, &VappGalleryVideoPage::onRequireResourceRelease);
        fileOp->showShareUI();
        break;
    case 'DELE':
        fileOp->m_signalOperationDone.connect(this, &VappGalleryVideoPage::onDeleteOperationDone);
        fileOp->showDeleteUI();
        break;
    default:
        VFX_OBJ_CLOSE(fileOp);
        break;
    }
    return;
}

void VappGalleryVideoPage::onCuiSelectCommand(VfxObject* sender, VfxId id)
{
    // Must be in an Video Picker CUI to work
    VcuiGalleryVideoPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPicker);
    VFX_ASSERT(cui);

    switch(id)
    {
    case 'SALL':
        {
            const VfxBool isAllSet = isAllSelected();
            setAllMarkState(!isAllSet);
            setSelectUnselectButton(isAllSet);
            disableMultiCommandButton(isAllSet);
        }
        break;
    case 'CNCL':
        cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_CANCEL, m_mediaList, &m_selectedSet);
        break;
    case 'OKAY':
        cui->notifyPickOperationDone(VCUI_GALLERY_RESULT_OK, m_mediaList, &m_selectedSet);
        break;
    }
    return;
}

void VappGalleryVideoPage::onToolbarSelectCommand(VfxObject* sender, VfxId id)
{
    if('SALL' == id)
    {
        const VfxBool isAllSet = isAllSelected();
        setAllMarkState(!isAllSet);
        setSelectUnselectButton(isAllSet);
        disableMultiCommandButton(isAllSet);
        return;
    }
    else if('CNCL' == id)
    {
        // cancel, simply leave multi-select state.
        createToolbar();
        endMultiSelect();
    }
    else
    {
        // process command. no need to leave multi-select yet.
        // We leave multi-select after confirmation & possible progress indicator.
        startRefreshTimer(VFX_FALSE, __LINE__);
        // pause decode to prevent file being locked
        if(m_mediaList)
        {
            m_mediaList->enableBackgroundDecode(VFX_FALSE);

        }

        if(m_multiFileOp)
        {
            VFX_OBJ_CLOSE(m_multiFileOp);
            m_multiFileOp = NULL;
        }
        VFX_OBJ_CREATE(m_multiFileOp, VappGalleryMultiFileOperationUI, this);
        m_multiFileOp->configParentPage(this);
        m_fileSequence.config(m_mediaList, &m_selectedSet);
        m_multiFileOp->configFileSequence(&m_fileSequence);
        m_multiFileOp->configMediaList(m_mediaList);

        switch(id)
        {
        case 'SHAR':
            m_multiFileOp->m_signalOperationDone.connect(this, &VappGalleryVideoPage::onShareOperationDone);
            m_multiFileOp->showShareUI();
            break;
        case 'DELE':
            m_multiFileOp->m_signalOperationDone.connect(this, &VappGalleryVideoPage::onDeleteOperationDone);
            m_multiFileOp->showDeleteUI();
            break;
        default:
            VFX_OBJ_CLOSE(m_multiFileOp);
        }
    }
}

void VappGalleryVideoPage::onRequireResourceRelease()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_REQUIRE_RES_RELEASE);
    onPageInactiveImpl();
    onPageInactived2Impl();
}

void VappGalleryVideoPage::onShareOperationDone(VfxObject* sender, VappGalleryFileOpResult result)
{
    if(m_multiFileOp == sender)
    {
        VFX_OBJ_CLOSE(m_multiFileOp);
        sender = NULL;
    }
    else if(sender && sender->isValid())
    {
        // single file case, we don't store file operation in member
        VFX_OBJ_CLOSE(sender);
    }

    if(result != VGFOR_CANCELLED)
    {
        // TODO: this setBottomBar causes ASSERTION in VcpBaseMenu,
        // if we don't destory the menu (m_grid).
        createToolbar();

        // leave multi-selection mode
        endMultiSelect();
    }
    else
    {
        // check if we need refresh list
        if(m_mediaList &&
           m_mediaList->canRefreshList() &&
           m_mediaList->canCheckDirty() &&
           m_mediaList->checkDirty())
        {
            m_videoMenu->m_signalViewScrollStart.disconnect(this, &VappGalleryVideoPage::handleViewScrollStart);
            m_videoMenu->m_signalViewScrollEnd.disconnect(this, &VappGalleryVideoPage::handleViewScrollEnd);
            VFX_OBJ_CLOSE(m_videoMenu);
            m_mediaList->refreshList();
            createToolbar();
            endMultiSelect();
        }
        return;
    }

    startRefreshTimer(VFX_TRUE, __LINE__);
    if(m_mediaList)
    {
        m_mediaList->enableBackgroundDecode(VFX_TRUE);
    }
}

void VappGalleryVideoPage::onDeleteOperationDone(VfxObject* sender, VappGalleryFileOpResult result)
{
    onShareOperationDone(sender, result);

    if(result != VGFOR_CANCELLED)
    {
        // currently we destroy and re-create the list menu
        m_videoMenu->m_signalViewScrollStart.disconnect(this, &VappGalleryVideoPage::handleViewScrollStart);
        m_videoMenu->m_signalViewScrollEnd.disconnect(this, &VappGalleryVideoPage::handleViewScrollEnd);
        VFX_OBJ_CLOSE(m_videoMenu);
        if(m_mediaList && m_mediaList->canRefreshList())
        {
            m_mediaList->refreshList();
        }

        // force update the list instead of destroy it.
        // we need to reset since the list maybe already changed.
        checkUpdate();

        // check error and notify user.
        if(result == VGFOR_ERROR)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_GALLERY_CANNOT_DELETE).getBuf());
        }
        return;
    }
    else
    {
        // check if we need refresh list
        if(m_mediaList &&
           m_mediaList->canRefreshList() &&
           m_mediaList->canCheckDirty() &&
           m_mediaList->checkDirty())
        {
            m_videoMenu->m_signalViewScrollStart.disconnect(this, &VappGalleryVideoPage::handleViewScrollStart);
            m_videoMenu->m_signalViewScrollEnd.disconnect(this, &VappGalleryVideoPage::handleViewScrollEnd);
            VFX_OBJ_CLOSE(m_videoMenu);
            m_mediaList->refreshList();
            endMultiSelect();
        }
        return;
    }
}

VfxBool VappGalleryVideoPage::isMultiSelecting()const
{
    return m_isMultiSelecting;
}

VfxBool VappGalleryVideoPage::isSelectOnlyMode() const
{
    // if we're under video picker CUI,
    // then we only allow selection
    VcuiGalleryVideoPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPicker);
    return NULL != cui;
}

void VappGalleryVideoPage::beginMultiSelect()
{
    if(isMultiSelecting() || NULL == m_videoMenu)
    {
        return;
    }

    m_isMultiSelecting = VFX_TRUE;
    m_selectedSet.clearAll();

    m_videoMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
}

void VappGalleryVideoPage::setAllMarkState(VfxBool markAll)
{
    // update selection state
    if(markAll)
    {
        m_selectedSet.setAll();
    }
    else
    {
        m_selectedSet.clearAll();
    }

    // redraw visible cells.
    m_videoMenu->updateAllItems();
}

void VappGalleryVideoPage::endMultiSelect()
{
    if(!isMultiSelecting())
    {
        return;
    }

    m_isMultiSelecting = VFX_FALSE;
    m_selectedSet.clearAll();

    if(m_videoMenu)
    {
        m_videoMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_videoMenu->updateAllItems();
    }
}

VfxBool VappGalleryVideoPage::isAllSelected()
{
    for(VfxU32 g = 0; g < getGroupCount(); ++g)
    {
        if(!m_selectedSet.isAllSet(g, 0, getCount(g)))
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}

VfxBool VappGalleryVideoPage::isAnySelected()
{
    for(VfxU32 g = 0; g < getGroupCount(); ++g)
    {
        if(m_selectedSet.isAnySet(g, 0, getCount(g)))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

////////////////////////////////////////////////////////////////////
//  Implementation of IListMenuContentProvider - Custom Layout
////////////////////////////////////////////////////////////////////

VfxU32 VappGalleryVideoPage::getGroupCount() const
{
    if(NULL == m_mediaList)
    {
        return 0;
    }
    return m_mediaList->getGroupCount();
}

VfxBool VappGalleryVideoPage::hasGroupHeader(VfxS32 group) const
{
    return group == 0 ? VFX_FALSE : VFX_TRUE;
}

VfxU32 VappGalleryVideoPage::getCount(VfxU32 group) const
{
    if(NULL == m_mediaList || !m_mediaList->isPrepared())
    {
        return 0;
    }
    return m_mediaList->getMediaCountInGroup(group);
}

VfxBool VappGalleryVideoPage::getItemText(
    VcpMenuPos p,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    GALLERY_MEASURE_TIME("VIT");    // Vide Item Text

    if(NULL == m_mediaList || !m_mediaList->isPrepared())
    {
        return VFX_FALSE;
    }

    // group header
    if(-1 == p.pos)
    {
        // only handle group header text
        if(VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT != fieldType)
        {
            return VFX_FALSE;
        }
        m_mediaList->getGroupName(p.group, text);
        return VFX_TRUE;
    }

    // item texts
    if(VCP_LIST_MENU_FIELD_TEXT == fieldType &&
       OK == m_mediaList->getMediaName(p, text))
    {
        #ifdef __VAPP_GALLERY_INTERNAL_DEBUG__
        VfxWString str = VFX_WSTR_EMPTY;
        str.format("[%d][%d]", p.group, p.pos);
        str += text;
        text = str;
        #endif
        return VFX_TRUE;
    }
    else if(VCP_LIST_MENU_FIELD_SUB_TEXT1 == fieldType &&
            !m_isExit)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_GET_ITEM_TEXT_SUB_TEXT1_M_IS_EXIT_D, m_isExit);
        U64 duration = 0;
        VappGalleryDecodeResult res = m_mediaList->getMediaDuration(p, duration, m_isScrolling);
        if(res == OK)
        {
            formatTimeText(text, duration);
            return VFX_TRUE;
        }
    }
    else if(VCP_LIST_MENU_FIELD_SUB_TEXT2 == fieldType &&
            !m_isExit)
    {
    #ifdef __VAPP_GALLERY_ENABLE_VIDEO_BOOKMARK__
        VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
        if(pickerCUI)
        {
            return VFX_FALSE;
        }

        U64 bookmarkMsec = 0;
        if(m_videoDB &&
           (OK == m_mediaList->getMediaBookmark(p, bookmarkMsec, m_isScrolling)) &&
           bookmarkMsec != 0)
        {
            formatTimeText(text, bookmarkMsec);
            return VFX_TRUE;
        }
    #else
        return VFX_FALSE;
    #endif
    }
    return VFX_FALSE;
}

VfxBool VappGalleryVideoPage::getItemImage(
    VcpMenuPos pos,                 // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    )
{
    GALLERY_MEASURE_TIME("VII");    // Video Item Image
    if(VCP_LIST_MENU_FIELD_ICON == fieldType)
    {
        if(NULL == m_mediaList || m_isExit || !m_mediaList->isPrepared())
        {
            image.setResId(IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON);
        }
        else
        {
            // in function call of mdi_video_ply_open_file, mpl setups source provider to initialize (SWLA tag: SP) in VFIL task
            // if APP dose heavy UI update or play animation while opening a video, it causes that
            // VFIL is interrupted by MMI or VRT and block MMI task waiting funtion return of mdi_video_ply_open_file
            // considering menu scrolling performance,
            // we do not trigger video decoder while video menu is scrolling
            // so we check if cache exist in memory cache only while menu is scrolling
            VfxImageBuffer thumbBuf;
            VappGalleryDecodeResult decodeResult = m_mediaList->startDecodeThumbEx(pos, thumbBuf, m_isScrolling);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_GET_ITEM_IMAGE, pos.group, pos.pos, decodeResult, m_isScrolling);

            switch(decodeResult)
            {
            case OK:
                // already decoded, directly update
                image.setImageBuffer(thumbBuf);
                break;
            case FORMAT_UNSUPPORTED:
                image.setResId(IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON);
                break;
            case DRM_LOCKED:
                image.setResId(IMG_ID_VAPP_GALLERY_SHT_DRM_ICON);
                break;
            default:
                // decoding, waiting for decodeCallBack
               // don't stop thumb refresh timer here because getItemImage() may be called while decoding
                image.setResId(IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON);
                break;
            }
        }

        return VFX_TRUE;
    }
    else if(VCP_LIST_MENU_FIELD_ICON_EXTRA1 == fieldType)
    {
    #ifdef __VAPP_GALLERY_ENABLE_VIDEO_BOOKMARK__
        VcuiGalleryPickerBase *pickerCUI = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);

        if(NULL == m_mediaList || m_isExit || !m_mediaList->isPrepared() || pickerCUI)
        {
            return VFX_FALSE;
        }

        U64 bookmarkMsec = 0;
        m_mediaList->getMediaBookmark(pos, bookmarkMsec, m_isScrolling);
        if(bookmarkMsec != 0)
        {
            image.setResId(IMG_ID_VAPP_GALLERY_MYVID_ICON_LAST_PLAY);
            return VFX_TRUE;
        }
    #else
        return VFX_FALSE;
    #endif
    }
    return VFX_FALSE;
}

void VappGalleryVideoPage::closeItemImage(
    VcpMenuPos pos,                 // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxImageSrc imgSrc              // [IN] the image resource
    )
{
    if(VCP_LIST_MENU_FIELD_ICON == fieldType
       && m_mediaList)
    {
        if(imgSrc.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER)
        {
            m_mediaList->unlockThumb(pos, imgSrc.getImageBuffer());
        }
        else
        {
            // the cell is not decoded yet so there is no buffer.
            // we don't need buffer to unlock in this case.
            VfxImageBuffer buf;
            buf.ptr = NULL;
            buf.pitchBytes = 0;
            buf.width = 0;
            buf.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
            m_mediaList->unlockThumb(pos, buf);
        }
    }
}

VcpListMenuItemStateEnum VappGalleryVideoPage::getItemState(
    VcpMenuPos index) const
{
    if(!isMultiSelecting())
    {
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
    else
    {
        return m_selectedSet.isSet(index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

VcpListMenuCellClientBaseFrame* VappGalleryVideoPage::getItemCustomContentFrame(
                                                        VcpMenuPos index,
                                                        VfxFrame *parentFrame)
{
    VappGalleryVideoMenuItemFrame *pCell = NULL;
    VFX_OBJ_CREATE(pCell, VappGalleryVideoMenuItemFrame, parentFrame);
    return pCell;
}


void VappGalleryVideoPage::closeItemCustomContentFrame(VcpMenuPos index,
                                                       VcpListMenuCellClientBaseFrame *cell)
{
    VFX_OBJ_CLOSE(cell);
    return;
}

////////////////////////////////////////////////////////////////////
//  Implementation of VappGalleryVideoMenuItemFrame
////////////////////////////////////////////////////////////////////

VappGalleryVideoMenuItemFrame::VappGalleryVideoMenuItemFrame():
    m_queryFinished(VFX_FALSE)
{
}

VfxBool VappGalleryVideoMenuItemFrame::getQueryFinished()
{
    return m_queryFinished;
}

void VappGalleryVideoMenuItemFrame::setQueryFinished(VfxBool finished)
{
    m_queryFinished = finished;
}

void VappGalleryVideoMenuItemFrame::onLayoutElements()
{
    GALLERY_MEASURE_TIME("VLE");    // video layout elements
    // workaround NULL pointer issue of VcpListMenu
    if(NULL == m_textFrame3)
    {
        VFX_OBJ_CREATE(m_textFrame3, VfxTextFrame, this);
        m_textFrame3->setAutoAnimate(VFX_TRUE);
    }

    if(NULL == m_textFrame2)
    {
        VFX_OBJ_CREATE(m_textFrame2, VfxTextFrame, this);
        m_textFrame2->setAutoAnimate(VFX_TRUE);
    }

    VcpListMenuCellIconTripleTextFrame::onLayoutElements();

    // adjust video thumbnail icon position.
    if(m_imageFrame)
    {
        m_imageFrame->setSize(VTHUMB_WIDTH, VTHUMB_HEIGHT);
        m_imageFrame->setPos(1, 1);
        m_imageFrame->setBgColor(VfxColor(255, VTHUMB_BK_COLOR, VTHUMB_BK_COLOR, VTHUMB_BK_COLOR));
        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    // file name position
    if(m_textFrame1)
    {
        GALLERY_MEASURE_TIME("VFP");    // Video file name position
        const VfxS32 titleLineWidth = getRect().getWidth() - TEXT_LEFT - TEXT1_RIGHT_GAPS - TITLE_LINE_RIGHT;
        m_textFrame1->setSize(titleLineWidth, m_textFrame1->getSize().height);
        m_textFrame1->setPos(TEXT_LEFT, TITLE_LINE_TOP);
        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    // duration text
    if(m_textFrame2)
    {
        VfxTextFrame *durationTxt = VFX_OBJ_DYNAMIC_CAST(m_textFrame2, VfxTextFrame);
        if(durationTxt)
        {
            durationTxt->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            durationTxt->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
        }

        m_textFrame2->setSize(TIME_TEXT_W, m_textFrame2->getSize().height);
        m_textFrame2->setPos(TEXT_LEFT, DESC_LINE_TOP);
        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    #ifdef __VAPP_GALLERY_ENABLE_VIDEO_BOOKMARK__
    // last played text
    if(m_textFrame3)
    {
        VfxTextFrame *lastPlayTxt = VFX_OBJ_DYNAMIC_CAST(m_textFrame3, VfxTextFrame);
        if(lastPlayTxt)
        {
            lastPlayTxt->setAutoResized(VFX_FALSE);
            lastPlayTxt->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        }
        m_textFrame3->setSize(TIME_TEXT_W, m_textFrame3->getSize().height);
        m_textFrame3->setPos(getSize().width - BOOKMARK_TEXT_LEFT, DESC_LINE_TOP);
        m_textFrame3->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    // last played icon (a pause icon)
    if(m_extraImgFrame1)
    {
        m_extraImgFrame1->setPos(getSize().width - LAST_PLAY_ICON_LEFT, LAST_PLAY_ICON_TOP);
        m_extraImgFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                         VFX_FRAME_ALIGNER_MODE_SIDE,
                                         VFX_FRAME_ALIGNER_MODE_SIDE,
                                         VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    #endif
}

VfxBool VappGalleryVideoMenuItemFrame::isContentReady()
{
    VfxImageSrc src = m_imageFrame->getImgContent();
    if(VFX_IMAGE_SRC_TYPE_RES_ID == src.getType())
    {
        if(IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON == src.getResId())
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}

vcui_gallery_media_state_enum VappGalleryVideoMenuItemFrame::getContentDecodeState() const
{
    VfxImageSrc src = m_imageFrame->getImgContent();
    switch(src.getType())
    {
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        switch(src.getResId())
        {
        case IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON:
            return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
        case IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON:
        case IMG_ID_VAPP_GALLERY_SHT_DRM_ICON:
            return VCUI_GALLERY_MEDIA_STATE_FORMAT_UNSUPPORTED;
        }
        break;
    case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        return VCUI_GALLERY_MEDIA_STATE_OK;
    default:
        return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
    }

    return VCUI_GALLERY_MEDIA_STATE_UNKNOWN;
}

#endif
