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
 *  vapp_movie_theater_index.cpp
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

#ifdef __MMI_COSMOS_MOVIE_THEATER__
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_movie_theater_def.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "vapp_movie_theater.h"
#include "vapp_movie_theater_index.h"
#include "vapp_movie_theater_category.h"
#include "vapp_screen_lock_gprot.h"
#include "vcp_include.h"
#include "vcp_tab_title_bar.h"
#include "../xml/vfx_xml_loader.h"
extern "C"
{
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "MotSrvGprot.h"
#include "gpiosrvgprot.h"
}

/*
//DCM
*/

#pragma arm section code = "DYNAMIC_CODE_MOT_ROCODE", rodata = "DYNAMIC_CODE_MOT_RODATA"


/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_MOVIE_THEATER_REFRESH_MIN_TIME   (1500)

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMovieTheaterIndexPage", VappMovieTheaterIndexPage, VappMovieTheaterPage);

VappMovieTheaterIndexPage::VappMovieTheaterIndexPage():
    m_indexMenu(NULL),
    m_1stEntry(VFX_TRUE),
    m_delayEnteredTimer(NULL),
    m_delayRefreshedTimer(NULL)
{
    m_indexNumber = NULL;
    m_toolBar = NULL;
    m_refreshStart = 0;
    m_isDBReady = VFX_FALSE;
    m_popupWaiting = NULL;
}

void VappMovieTheaterIndexPage::onInit()
{
    VappMovieTheaterPage::onInit();

    // set bg color to avoid abnormal bg color caused by page transition from page with different bg color
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    kal_mem_set(&m_viewState, 0, sizeof(m_viewState));

    // do not create tabBar if no phone drive, default is memory card
    #if defined(__MMI_COSMOS_MOT_NO_USER_DRIVE__)
        /*** low cost support feature set ***/
        // note: multimedia app dose not support phone drive in SLIM project
        VcpTitleBar *titleBar = NULL;
        VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
        titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_AP_NAME));
        setTopBar(titleBar);

        VappMovieTheaterStorageSetting storageSetting;
        storageSetting.setDefaultStorage(SRV_FMGR_DRV_CARD_TYPE);
    #else
        const U8 drv = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE);
        if (srv_fmgr_drv_is_accessible(drv))
        {
			// title bar (a tab title bar that allows storage selection)
			VcpTabTitleBar *tabBar = NULL;
            VFX_OBJ_CREATE(tabBar, VcpTabTitleBar, this);
            tabBar->m_signalTabSwitched.connect(this, &VappMovieTheaterIndexPage::onSelectStorage);
            setTopBar(tabBar);
            createStorageSelectionTab(VFX_TRUE);
        }
        else
        {
            VcpTitleBar *titleBar = NULL;
            VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
            titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_AP_NAME));
            setTopBar(titleBar);

            VappMovieTheaterStorageSetting storageSetting;
            storageSetting.setDefaultStorage(SRV_FMGR_DRV_CARD_TYPE);
        }
    #endif

    m_signalUpdated.connect(this, &VappMovieTheaterIndexPage::handleWaitingEnd);
}

void VappMovieTheaterIndexPage::onDeinit()
{
    VappMovieTheaterPage::onDeinit();
}

void VappMovieTheaterIndexPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_EXIT);
    VappMovieTheaterPage::onExit(isBackward);

    if(m_delayEnteredTimer)
    {
        m_delayEnteredTimer->m_signalTick.disconnect(this, &VappMovieTheaterIndexPage::onDelayEntered);
        m_delayEnteredTimer->stop();
        VFX_OBJ_CLOSE(m_delayEnteredTimer);
        m_delayEnteredTimer = NULL;
    }

    if(m_delayRefreshedTimer)
    {
        m_delayRefreshedTimer->m_signalTick.disconnect(this, &VappMovieTheaterIndexPage::onRefreshed);
        m_delayRefreshedTimer->stop();
        VFX_OBJ_CLOSE(m_delayRefreshedTimer);
        m_delayRefreshedTimer = NULL;
    }

    m_provider->stopUpdating();
    popupWaitingClose();

    // register device plug-in to refresh toolbar
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappMovieTheaterIndexPage::onDevicePlugInOut, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMovieTheaterIndexPage::onDevicePlugInOut, this);
}

void VappMovieTheaterIndexPage::onExited2()
{
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

    m_indexMenu->getViewState(&m_viewState);

    VFX_OBJ_CLOSE(m_indexMenu);
    VFX_FREE_MEM(m_indexNumber);
    m_indexNumber = NULL;

    return VappMovieTheaterPage::onExited2();
}

void VappMovieTheaterIndexPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_ENTER);
    VappMovieTheaterPage::onEnter(isBackward);

    // Index of pages, which is a list menu.
    VFX_OBJ_CREATE(m_indexMenu, VcpListMenu, this);
    m_indexMenu->setSize(getSize().width, getSize().height);
    //m_indexMenu->setItemHeight(IndexPageLayout::MENU_H);
    m_indexMenu->setContentProvider(this);
    m_indexMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    //m_indexMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    //m_indexMenu->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_FALSE);
    m_indexMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
    m_indexMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_indexMenu->m_signalItemTapped.connect(this, &VappMovieTheaterIndexPage::onIndexItemTapped);
    m_indexMenu->setViewState(&m_viewState);

    VFX_ALLOC_MEM(m_indexNumber, sizeof(VfxS32)*INDEX_MENU_ITEM_COUNT, this);
    kal_mem_set(m_indexNumber, 0xFF, sizeof(VfxS32)*INDEX_MENU_ITEM_COUNT);

    if (m_toolBar == NULL)
    {

        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);

        m_toolBar->addItem('RFSH', VFX_WSTR_RES(STR_GLOBAL_REFRESH), VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH);
        m_toolBar->setDisableItem('RFSH', VFX_FALSE);
        m_toolBar->m_signalButtonTap.connect(this, &VappMovieTheaterIndexPage::onClickToolBarButton);
        m_toolBar->setHidden(VFX_FALSE);
        setBottomBar(m_toolBar);
    }

    VappMovieTheaterStorageSetting storageSetting;
    handleWaitingBegin(storageSetting.getDefaultStorage(VFX_FALSE));
    handleStorageChangeLite(storageSetting);

    // set receiver for callback.
    m_provider->setCBReceiver(this);

    // will do this in change storage
    /*
    if (m_1stEntry)
    {
        srv_mot_ret_enum ret;
        ret = m_provider->open(storageSetting.getDefaultStorage(VFX_FALSE));
        if (ret < 0)
        {
            VfxWString text;

            m_provider->getErrorString(ret, text);
            mmi_frm_nmgr_balloon(
    		      MMI_SCENARIO_ID_DEFAULT,
    		      MMI_EVENT_INFO_BALLOON,
    		      MMI_NMGR_BALLOON_TYPE_FAILURE,
    		      text.getBuf());
        }
    }
    */
	if(isBackward)
	{
		m_1stEntry = VFX_FALSE;
	}
}

void VappMovieTheaterIndexPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_ENTERED);
    VappMovieTheaterPage::onEntered();
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MOT][Index] 5000!!");

    if(NULL == m_delayEnteredTimer)
    {
        VFX_OBJ_CREATE(m_delayEnteredTimer, VfxTimer, this);
        m_delayEnteredTimer->setStartDelay(10);
        m_delayEnteredTimer->setDuration(0);
    }
    if(NULL == m_delayRefreshedTimer)
    {
        VFX_OBJ_CREATE(m_delayRefreshedTimer, VfxTimer, this);
    }

    m_delayEnteredTimer->m_signalTick.connect(this, &VappMovieTheaterIndexPage::onDelayEntered);
    m_delayEnteredTimer->start();
}

void VappMovieTheaterIndexPage::onDelayEntered(VfxTimer *timer)
{
    timer->stop();
    timer->m_signalTick.disconnect(this, &VappMovieTheaterIndexPage::onDelayEntered);

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[MOT][Index] onDelayEntered");

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    // start to use.
    handleWaitingEnd();

    // make sure tab bar UI is up-to-date
    createStorageSelectionTab(VFX_FALSE);

    // then update storage-related UI elements
    {
        VappMovieTheaterStorageSetting storageSetting;
        handleStorageChange(storageSetting);
    }

    // register device plug-in to refresh tab bar
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappMovieTheaterIndexPage::onDevicePlugInOut, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMovieTheaterIndexPage::onDevicePlugInOut, this);
}

void VappMovieTheaterIndexPage::onSelectStorage(VfxObject *sender, VfxId btnId)
{
    VFX_UNUSED(sender);

    // btnId are srv_fmgr_drv_type_enum
    const srv_fmgr_drv_type_enum drvType = (srv_fmgr_drv_type_enum)btnId;

    VappMovieTheaterStorageSetting storageSetting;
    if(drvType != storageSetting.getDefaultStorage(VFX_FALSE))
    {
        storageSetting.setDefaultStorage(drvType);
        handleStorageChange(storageSetting);
    }
}

void VappMovieTheaterIndexPage::refreshStorage(VfxBool directRefresh)
{
    if(!directRefresh)
    {
        // simply set dirty flag, to refresh the entry in onEnter
    }
    else
    {
        // refresh UI
        createStorageSelectionTab(VFX_FALSE);
        VappMovieTheaterStorageSetting setting;
        handleStorageChange(setting);
    }
}

VfxBool VappMovieTheaterIndexPage::handleStorageChangeLite(VappMovieTheaterStorageSetting &storageSetting)
{
    // check non-exist drives
    const srv_fmgr_drv_type_enum defaultStorage = storageSetting.getDefaultStorage(VFX_FALSE);
    const U8 drv = srv_fmgr_drv_get_letter_by_type(defaultStorage);
    if(MMI_FALSE == srv_fmgr_drv_is_accessible(drv))
    {
        // update page message
        setPageMessage(VFX_WSTR_RES(STR_GLOBAL_NO_MEMORY_CARD));
        showPageMessage(VFX_TRUE);

        // make sure waiting animation stopped.
        handleWaitingEnd();
        popupWaitingClose();

        // stop delay refresh timer.
        if (m_delayRefreshedTimer)
        {
            m_delayRefreshedTimer->m_signalTick.disconnect(this, &VappMovieTheaterIndexPage::onRefreshed);
            m_delayRefreshedTimer->stop();
        }

        // set other menu item disabled
        if (m_indexMenu)
        {
            m_indexMenu->setHidden(VFX_TRUE);
        }

        if (m_toolBar)
        {
            m_toolBar->setDisableItem('RFSH', VFX_TRUE);
        }

        // update toolbar
        VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
        if(tabBar)
        {
            tabBar->setHighlightedTab(defaultStorage);
        }

        // make sure the last panel is updated
        return VFX_FALSE;
    }
    else
    {
        showPageMessage(VFX_FALSE);

        if (m_indexMenu)
        {
            m_indexMenu->setHidden(VFX_FALSE);
            m_indexMenu->updateAllItems();
        }

        if (m_toolBar)
        {
            m_toolBar->setDisableItem('RFSH', VFX_FALSE);
        }

        return VFX_TRUE;
    }
}

void VappMovieTheaterIndexPage::handleStorageChange(VappMovieTheaterStorageSetting &storageSetting)
{
    // handles any device change.
    // note: if a memory card is removed, we still keep the "default storage".
    // only update UI to display "No memory card".

    if (m_indexNumber)
    {
        kal_mem_set(m_indexNumber, 0xFF, sizeof(VfxS32)*INDEX_MENU_ITEM_COUNT);
    }

    if(!handleStorageChangeLite(storageSetting))
    {
        // drive not valid, close current provider.
        m_provider->close();

        return;
    }

    // update UI, update tab and notify collection to re-query
    VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
    if(tabBar)
    {
        tabBar->setHighlightedTab(storageSetting.getDefaultStorage(VFX_TRUE));
    }

    if (m_toolBar)
    {
        m_toolBar->setDisableItem('RFSH', VFX_FALSE);
    }
    m_provider->close();
    srv_mot_ret_enum ret = m_provider->open(storageSetting.getDefaultStorage(VFX_FALSE));
    if (ret < 0)
    {
        VfxWString text;

        m_provider->getErrorString(ret, text);
        mmi_frm_nmgr_balloon(
		      MMI_SCENARIO_ID_DEFAULT,
		      MMI_EVENT_INFO_BALLOON,
		      MMI_NMGR_BALLOON_TYPE_FAILURE,
		      text.getBuf());

        if (m_toolBar)
        {
            m_toolBar->setDisableItem('RFSH', VFX_TRUE);
        }

        return;
    }

    // refresh menu items
    showPageMessage(VFX_FALSE);

    if (m_indexMenu)
    {
        m_indexMenu->setHidden(VFX_FALSE);
        m_indexMenu->updateAllItems();
    }

    if (m_toolBar)
    {
        m_toolBar->setDisableItem('RFSH', VFX_FALSE);
    }

    // force update entire page
    checkUpdate();
}

mmi_ret VappMovieTheaterIndexPage::onDevicePlugInOut(mmi_event_struct *param)
{
    if(NULL == param)
    {
        return MMI_RET_OK;
    }
    VappMovieTheaterIndexPage* pThis = (VappMovieTheaterIndexPage*)param->user_data;
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    return pThis->handleDevicePlugInOut(param);
}

mmi_ret VappMovieTheaterIndexPage::handleDevicePlugInOut(mmi_event_struct *param)
{
    // update storage selection tab
    // note that we don't update storage,
    // it is handled by VappGalleryApp or VcuiGalleryBase
    //createStorageSelectionTab(VFX_FALSE);

    // then, we check if the arrival drive is exactly
    // what user choosed. if so, we need to refresh the current storage.
    do
    {
        // detect right memcard name by re-creating storage tab.
        createStorageSelectionTab(VFX_FALSE);

        if(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN != param->evt_id)
        {
            break;
        }

        if(sizeof(srv_fmgr_notification_dev_plug_event_struct) != param->size)
        {
            break;
        }

        const srv_fmgr_notification_dev_plug_event_struct* plugEvent = (srv_fmgr_notification_dev_plug_event_struct*)param;
        VappMovieTheaterStorageSetting setting;
        const VfxId currentStorageType = setting.getDefaultStorage(VFX_FALSE);
        for(U8 i = 0; i < plugEvent->count; ++i)
        {
            if(currentStorageType == srv_fmgr_drv_get_type(plugEvent->drv_letters[i]))
            {
                handleStorageChange(setting);
                break;
            }
        }
    }while(0);

    return MMI_RET_OK;
}

void VappMovieTheaterIndexPage::createStorageSelectionTab(VfxBool updateStorage)
{
    VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
    if(NULL == tabBar)
    {
        return;
    }

    // try to remember highlighted item
    const VfxId previousHighlight = tabBar->getHighlightedTab();

    if(tabBar->getTabCount())
    {
        tabBar->removeAllTabs();
    }

    // insert accessible drive names
    VfxWString driveName;
    SRV_FMGR_DRVLIST_HANDLE hDrvList = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    for(VfxS32 i = 0; i < srv_fmgr_drivelist_count(hDrvList); ++i)
    {
        const U8 drv = srv_fmgr_drivelist_get_drv_letter(hDrvList, i);

        const srv_fmgr_drv_type_enum drvType = (srv_fmgr_drv_type_enum)srv_fmgr_drv_get_type(drv);
        // assign icon
        const VfxId iconId = drvType < SRV_FMGR_DRV_CARD_TYPE ? IMG_ID_VAPP_FMGR_TAB_PHONE_ICN : IMG_ID_VAPP_FMGR_TAB_CARD_ICN;

        // assign name
        VfxWChar *nameBuf = driveName.lockBuf(SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        srv_fmgr_drv_get_name(drv, nameBuf, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        driveName.unlockBuf();

        tabBar->addTab(drvType, VcpStateImage(iconId), driveName);
    }
    srv_fmgr_drivelist_destroy(hDrvList);
    hDrvList = NULL;

    if(updateStorage)
    {
        // set default focus tab
        // retrieve default setting
        VappMovieTheaterStorageSetting setting;
        tabBar->setHighlightedTab(setting.getDefaultStorage(VFX_TRUE));
    }
    else
    {
        tabBar->setHighlightedTab(previousHighlight);
    }
}

void VappMovieTheaterIndexPage::handleWaitingBegin(srv_fmgr_drv_type_enum defaultStorage)
{
    showPageWaitIcon(VFX_TRUE);

    VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
    if(tabBar)
    {
        if (defaultStorage == SRV_FMGR_DRV_PHONE_TYPE)
        {
            tabBar->setTabEnabled(SRV_FMGR_DRV_CARD_TYPE, VFX_FALSE);
        }
        else
        {
            tabBar->setTabEnabled(SRV_FMGR_DRV_PHONE_TYPE, VFX_FALSE);
        }
    }

    if (m_indexMenu)
    {
        m_indexMenu->setIsUnhittable(VFX_TRUE);
    }

    if (m_toolBar)
    {
        m_toolBar->setDisableItem('RFSH', VFX_TRUE);
    }
}

void VappMovieTheaterIndexPage::handleWaitingEnd()
{
    showPageWaitIcon(VFX_FALSE);

    VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
    if(tabBar)
    {
        tabBar->setTabEnabled(SRV_FMGR_DRV_PHONE_TYPE, VFX_TRUE);
        tabBar->setTabEnabled(SRV_FMGR_DRV_CARD_TYPE, VFX_TRUE);
    }

    if (m_indexMenu)
    {
        m_indexMenu->setIsUnhittable(VFX_FALSE);
    }

    if (m_toolBar)
    {
        m_toolBar->setDisableItem('RFSH', VFX_FALSE);
    }
}

void VappMovieTheaterIndexPage::popupWaiting(VfxWString str, VfxBool withCancelBtn)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MOVIE_THEATER_POPUP_WAITING);

    if (m_popupWaiting)
    {
        return;
    }

    VFX_OBJ_CREATE(m_popupWaiting, VcpIndicatorPopup, this);
    if (withCancelBtn)
    {
        m_popupWaiting->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_popupWaiting->m_signalCanceled.connect(this, &VappMovieTheaterIndexPage::onWaitingCanceled);
    }
    else
    {
        m_popupWaiting->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    }
    m_popupWaiting->setAutoDestory(VFX_TRUE);
    m_popupWaiting->setText(str);

    m_popupWaiting->show(VFX_TRUE);
}

void VappMovieTheaterIndexPage::onWaitingCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MOVIE_THEATER_ON_WAITING_CANCELED);

    m_provider->stopUpdating();

    if (m_indexMenu)
    {
        m_indexMenu->updateAllItems();
    }

    popupWaitingClose();
}

void VappMovieTheaterIndexPage::popupWaitingClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MOVIE_THEATER_POPUP_WAITING_CLOSE);

    if (m_popupWaiting)
    {
        if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_TRUE)
        {
            m_popupWaiting->exit(VFX_TRUE);
        }
        else
        {
            m_popupWaiting->exit(VFX_FALSE);
        }
        m_popupWaiting = NULL;
    }
}

void VappMovieTheaterIndexPage::onIndexItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(sender == m_indexMenu);

	if (m_provider->isDBReady())
	{
	    srv_mot_ret_enum ret = m_provider->memorySpaceCheck();
		if(ret == SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				(WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_MEMORY_FULL).getBuf());
		}
		else
		{
			onGotoPage(index);
		}
	}
}

void VappMovieTheaterIndexPage::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{
    kal_mem_set(m_indexNumber, 0xFF, sizeof(VfxS32)*INDEX_MENU_ITEM_COUNT);
    m_refreshStart = VfxTimer::getCurrentSystemTime();

    if (m_provider->isDBReady())
    {
        srv_mot_ret_enum ret = m_provider->update();
        if (ret >= 0)
        {
            //handleWaitingBegin();
            popupWaiting(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_POPUP_REFRESHING), VFX_TRUE);
        }
        else
        {
            VfxWString text;

            m_provider->getErrorString(ret, text);
            mmi_frm_nmgr_balloon(
    		      MMI_SCENARIO_ID_DEFAULT,
    		      MMI_EVENT_INFO_BALLOON,
    		      MMI_NMGR_BALLOON_TYPE_FAILURE,
    		      text.getBuf());
        }
    }
}

void VappMovieTheaterIndexPage::onGotoPage(VfxU32 index)
{
    VappMovieTheaterCategoryPage *page = NULL;
    srv_mot_cat_enum cat;

    if (index == 0)
    {
        cat = SRV_MOT_CAT_RECENT_PLAY;
    }
    else if (index == 1)
    {
        cat = SRV_MOT_CAT_ALL;
    }
    else
    {
        cat = (srv_mot_cat_enum)(index - 2);
    }

    VFX_OBJ_CREATE_EX(page, VappMovieTheaterCategoryPage, getMainScr(), (cat));
    page->setProvider(m_provider);

    getMainScr()->pushPage(0, page);
}

void VappMovieTheaterIndexPage::onRefreshed(VfxTimer *timer)
{
    if (timer)
    {
        timer->stop();
        timer->m_signalTick.disconnect(this, &VappMovieTheaterIndexPage::onRefreshed);
    }

    if (m_indexMenu)
    {
        m_indexMenu->updateAllItems();
    }
    //m_signalUpdated.postEmit();
    popupWaitingClose();

    // check if we have to launch screen lock?
    if ((srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE)&&
        vapp_screen_lock_is_allowed_launch())
    {
        vapp_screen_lock_launch();
    }
}

void VappMovieTheaterIndexPage::updateListItems(srv_mot_ret_enum result)
{
    if (result == SRV_MOT_S_FINISH)
    {
        VfxMsec diffTime = VfxTimer::getCurrentSystemTime() - m_refreshStart;

        if (diffTime >= VAPP_MOVIE_THEATER_REFRESH_MIN_TIME)
        {
            onRefreshed(m_delayRefreshedTimer);
        }
        else
        {
            m_delayRefreshedTimer->setStartDelay(VAPP_MOVIE_THEATER_REFRESH_MIN_TIME - diffTime);
            m_delayRefreshedTimer->setDuration(0);
            m_delayRefreshedTimer->m_signalTick.connect(this, &VappMovieTheaterIndexPage::onRefreshed);
            m_delayRefreshedTimer->start();
        }
    }
    else
    {
        //handleWaitingEnd();
        if (result < 0)
        {
            VfxWString text;

            m_provider->getErrorString(result, text);
            mmi_frm_nmgr_balloon(
    		      MMI_SCENARIO_ID_DEFAULT,
    		      MMI_EVENT_INFO_BALLOON,
    		      MMI_NMGR_BALLOON_TYPE_FAILURE,
    		      text.getBuf());
        }
        onRefreshed(m_delayRefreshedTimer);
    }
}


/////////////////////////////////////////////////////////////////
//  Implementation of IVcpListMenuContentProvider
/////////////////////////////////////////////////////////////////
VfxU32 VappMovieTheaterIndexPage::getCount() const
{

    return INDEX_MENU_ITEM_COUNT;
}

VfxBool VappMovieTheaterIndexPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType,
                            VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VfxWString temp_text;

    if (index > INDEX_MENU_ITEM_COUNT)
    {
        return VFX_FALSE;
    }

    if (index == 0)
    {
        m_provider->getCategoryString(SRV_MOT_CAT_RECENT_PLAY, text);
    }
    else if (index == 1)
    {
        m_provider->getCategoryString(SRV_MOT_CAT_ALL, text);
        if (m_indexNumber[index] <= 0)
        {
            m_provider->getCategoryCount(SRV_MOT_CAT_ALL, (VfxU32*)&m_indexNumber[index]);
        }
        temp_text.format(" (%d)", m_indexNumber[index]);
        text += temp_text;
    }
    else
    {
        srv_mot_cat_enum cat = (srv_mot_cat_enum)(index - 2);
        m_provider->getCategoryString(cat, text);
        if (m_indexNumber[index] <= 0)
        {
            m_provider->getCategoryCount(cat, (VfxU32*)&m_indexNumber[index]);
        }
        temp_text.format(" (%d)", m_indexNumber[index]);
        text += temp_text;
    }

    return VFX_TRUE;
}

VcpListMenuItemStateEnum VappMovieTheaterIndexPage::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}

/*
VfxS32 VappMovieTheaterIndexPage::MOTCallback(void* user_data, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param)
{
    VappMovieTheaterIndexPage *pThis = reinterpret_cast<VappMovieTheaterIndexPage*>(user_data);

    if (cb_event == SRV_MOT_CB_EVT_UPDATED)
    {
        pThis->showPageWaitIcon(VFX_FALSE);
        pThis->m_indexMenu->updateAllItems();
    }

    return 0;
}
*/

//DCM
#pragma arm section code, rodata



#endif
