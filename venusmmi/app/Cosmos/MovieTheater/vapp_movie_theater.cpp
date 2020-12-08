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
 *  vapp_movie_theater.cpp
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
#include "vtst_rt_main.h"
#include "Vfx_config.h"

#ifdef __MMI_COSMOS_MOVIE_THEATER__

#include "vcp_include.h"
#include "vapp_movie_theater_gprot.h"
#include "vapp_movie_theater.h"
#include "vapp_movie_theater_index.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_fmgr_table.h"

extern "C"
{
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_movie_theater_def.h"
#include "AppMgrSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "UcmSrvGprot.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "vapp_usb_gprot.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif
#include "MMI_media_app_trc.h"
}


/*****************************************************************************
 * Macro
 *****************************************************************************/
#ifdef __MMI_USB_SUPPORT__
#define CHECK_MASS_STORAGE_AND_RETURN_NULL() if(srv_usb_is_in_mass_storage_mode())\
                                             {\
                                                vapp_usb_unavailable_popup(SRV_USB_ERROR_UNAVAILABLE);\
                                                return NULL;\
                                             }
#else
#define CHECK_MASS_STORAGE_AND_RETURN_NULL()
#endif // __MMI_USB_SUPPORT__

/*****************************************************************************
 * APP Global variable
 *****************************************************************************/
srv_mot_ret_enum VappMovieTheaterPage::m_plUpdateRet = SRV_MOT_S_OK;

/*****************************************************************************
 * APP Exported Function
 *****************************************************************************/
extern "C"
{

// Initialization during boot-up, be careful!
mmi_ret vapp_movie_theater_init(mmi_event_struct *event)
{
    return MMI_RET_OK;
}

// Launches Movie Theater application
MMI_ID vapp_movie_theater_launch(void* param, U32 param_size)
{
	//DCM
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
	DCM_Load(DYNAMIC_CODE_COMPRESS_MOT, 0, 0);
#endif

    CHECK_MASS_STORAGE_AND_RETURN_NULL();

    return VfxAppLauncher::launch(VAPP_MOVIE_THEATER,
                                  VFX_OBJ_CLASS_INFO(VappMovieTheater),
                                  GRP_ID_ROOT);
}

mmi_ret vapp_movie_theater_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

} // extern "C"


/*
//DCM
*/

#pragma arm section code = "DYNAMIC_CODE_MOT_ROCODE", rodata = "DYNAMIC_CODE_MOT_RODATA"


/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMovieTheater", VappMovieTheater, VfxApp);
//VFX_IMPLEMENT_CLASS("VappMovieTheaterScreen", VappMovieTheaterScreen, VfxMainScr);
//VFX_IMPLEMENT_CLASS("VappMovieTheaterPage", VappMovieTheaterPage, VfxPage);

/*****************************************************************************
 * Common framework event handling between App and CUI
 *****************************************************************************/
template<typename T> void registerCommonFrameWorkEvent(T *pThis, VfxBool isRegister)
{
    typedef mmi_ret (*PFNFrameworkRegFunc)(U16 evt_id, mmi_proc_func call_back, void *user_data);
    PFNFrameworkRegFunc action = isRegister ? &mmi_frm_cb_reg_event : &mmi_frm_cb_dereg_event;
    action(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &T::onDevicePlugIn, pThis);
    action(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &T::onDevicePlugOut, pThis);
#ifdef __MMI_USB_SUPPORT__
    action(EVT_ID_USB_ENTER_MS_MODE, &T::onUSBEnterMS, pThis);
#endif

    // to route call change even to screen and page
    pThis->registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, isRegister);
}

/*****************************************************************************
 * Class Implementation : VappMovieTheater
 *****************************************************************************/
void VappMovieTheater::onInit()
{
    VfxApp::onInit();

    registerCommonFrameWorkEvent(this, VFX_TRUE);
    m_provider = NULL;
}

void VappMovieTheater::onDeinit()
{
    registerCommonFrameWorkEvent(this, VFX_FALSE);
    VFX_OBJ_CLOSE(m_provider);

    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_FALSE);

    VfxApp::onDeinit();

//DCM
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MOT);
#endif
}

void VappMovieTheater::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_TRUE);

    VappMovieTheaterScreen *scr = NULL;
    VFX_OBJ_CREATE(scr, VappMovieTheaterScreen, this);

    VFX_OBJ_CREATE(m_provider, VappMovieTheaterContentProvider, this);
    scr->setProvider(m_provider);

    if(NULL == args)
    {
        // display main screen
        scr->show();
    }
    else
    {
        scr->show();
    }
}

mmi_ret VappMovieTheater::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MOVIE_THEATER_ON_PROC, evt->evt_id);

    switch(evt->evt_id)
    {
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
            return onProcPreLockRouting();
        }

        default:
            break;
    }

    return VfxApp::onProc(evt);
}


mmi_ret VappMovieTheater::onUSBEnterMS(mmi_event_struct *param)
{
    // exit MovieTheater application when enter Mass storage mode
    VfxApp *pThis = (VfxApp*)param->user_data;
    pThis->exit();
    return MMI_RET_OK;
}

mmi_ret VappMovieTheater::onDevicePlugIn(mmi_event_struct *param)
{
    // VappMovieTheater *pThis = reinterpret_cast<VappMovieTheater*>(evt->user_data);
    // VFX_ASSERT(pThis);
    return MMI_RET_OK;
}

mmi_ret VappMovieTheater::onDevicePlugOut(mmi_event_struct *param)
{
    srv_fmgr_notification_dev_plug_event_struct *evt = reinterpret_cast<srv_fmgr_notification_dev_plug_event_struct*>(param);
    VFX_ASSERT(evt->size == sizeof(srv_fmgr_notification_dev_plug_event_struct));

    VappMovieTheater *pThis = reinterpret_cast<VappMovieTheater*>(evt->user_data);
    return pThis->handleDevicePlugOut(evt);
}

mmi_ret VappMovieTheater::onProcPreLockRouting()
{
    VfxPage *p = NULL;
    VappMovieTheaterIndexPage *indexPage = NULL;

    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(getScreen(getBottomScreenId()), VfxMainScr);
    // get page
    p = mainScr->getPage();
    // check if setting related page

    // if we are in index page matching storage, update index
    indexPage = VFX_OBJ_DYNAMIC_CAST(p, VappMovieTheaterIndexPage);
    if(indexPage)
    {
        if (indexPage->m_popupWaiting)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MOVIE_THEATER_ON_PRELOCK_ROUTING);

            return MMI_RET_ERR;
        }
    }

    return MMI_RET_OK;
}

mmi_ret VappMovieTheater::handleDevicePlugOut(srv_fmgr_notification_dev_plug_event_struct* evt)
{
    // check if it is current using?
    const U8 defaultDrv = queryActiveDrive();
    if(!isMatchingStorage(*evt, defaultDrv))
    {
        // ejected storage is non of our concern
        return MMI_RET_OK;
    }

    // If current storage changed,
    // pop to index page if index page is in page history.
    // index page would refresh itself automatically.
    // Otherwise, simply terminate the program
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(getScreen(getBottomScreenId()), VfxMainScr);
    VFX_ASSERT(mainScr);
    VappMovieTheaterIndexPage *indexPage = NULL;
    VfxPage *p = NULL;
    VfxBool directRefresh = VFX_TRUE;

    while(NULL == indexPage && mainScr->getPageCount() > 0)
    {
        // get page
        p = mainScr->getPage();
        // check if setting related page

        // if we are in index page matching storage, update index
        indexPage = VFX_OBJ_DYNAMIC_CAST(p, VappMovieTheaterIndexPage);
        if(indexPage)
        {
            // Note: popPage() does not immediately call VfxPage::onExit() and onDeinit().
            // so we post invoke here.
            vfxPostInvoke1(indexPage, &VappMovieTheaterIndexPage::refreshStorage, directRefresh);
            break;
        }
        // there are other pages on top, do not refresh index page immediately
        directRefresh = VFX_FALSE;
        mainScr->popPage();
    }

    // if the page count reaches 0, this APP will auto-close
    return MMI_RET_OK;
}


U8 VappMovieTheater::queryActiveDrive()
{
    // update current storage setting first
    VappMovieTheaterStorageSetting setting;
    // don't correct invalid storage, since we're handling device removal
    const srv_fmgr_drv_type_enum defaultStorage = setting.getDefaultStorage(VFX_FALSE);
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(defaultStorage);
    return defaultDrv;
}

VfxBool VappMovieTheater::isMatchingStorage(const srv_fmgr_notification_dev_plug_event_struct &evt, U8 drv)
{
    for(VfxS32 i = 0; i < evt.count; ++i)
    {
        if (evt.drv_letters[i] == drv)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

/*****************************************************************************
 * Class Implementation : VappMovieTheaterScreen
 *****************************************************************************/
VappMovieTheaterScreen::VappMovieTheaterScreen() :
    //m_isSSEDisabled(VFX_FALSE),
	m_firstPage(NULL)
{
}

void VappMovieTheaterScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VfxPage *page = NULL;
    if(NULL == m_firstPage)
    {
        VFX_OBJ_CREATE(page, VappMovieTheaterIndexPage, this);

        VappMovieTheaterIndexPage* indexPage = VFX_OBJ_DYNAMIC_CAST(page, VappMovieTheaterIndexPage);
        indexPage->setProvider(m_provider);

        page = indexPage;
    }
    else
    {
        page = m_firstPage;
    }

    pushPage(0, page);
}
/*
void VappMovieTheaterScreen::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);
    if(m_isSSEDisabled)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
    }
}

void VappMovieTheaterScreen::onExit(VfxBool isBackward)
{
    if(m_isSSEDisabled)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);
    }
    VfxMainScr::onExit(isBackward);
}

void VappMovieTheaterScreen::setIsSSEDisabled(const VfxBool disabled)
{
    m_isSSEDisabled = disabled;
}
*/
void VappMovieTheaterScreen::setProvider(VappMovieTheaterContentProvider *provider)
{
    m_provider = provider;
}

VfxBool VappMovieTheaterScreen::onPageBack(VfxPage* page)
{
    VfxBool ret = VfxMainScr::onPageBack(page);
    if(page == m_firstPage)
    {
        m_signalLastPagePopped.emit();
        // if screen is not auto-close,
        // don't allow closing last page
        if(!getAutoClose())
        {
            return VFX_FALSE;
        }
    }
    return ret;
}

/*****************************************************************************
 * Class Implementation : VappMovieTheaterPage
 *****************************************************************************/

VappMovieTheaterPage::VappMovieTheaterPage():
    m_messageFrame(NULL),
    m_waitIcon(NULL)
{
    m_pageMessage.setNull();
}

void VappMovieTheaterPage::onInit()
{
    VfxPage::onInit();

    m_appId = getApp()->getGroupId();
}

void VappMovieTheaterPage::setPageMessage(const VfxWString &message)
{
    m_pageMessage = message;
}

void VappMovieTheaterPage::showPageMessage(VfxBool isShow, VfxBool whiteText)
{
    if(!isShow && m_messageFrame)
    {
        m_messageFrame->setHidden(VFX_TRUE);
        return;
    }

    if(NULL == m_messageFrame)
    {
        VFX_OBJ_CREATE(m_messageFrame, VfxTextFrame, this);
        if(whiteText)
        {
            m_messageFrame->setColor(VFX_COLOR_WHITE);
        }
        else
        {
            //m_messageFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
            m_messageFrame->setColor(VfxColor(255, 140, 140, 140));
        }

        m_messageFrame->setIsUnhittable(VFX_TRUE);
        m_messageFrame->setAnchor(0.5f, 0.5f);
        m_messageFrame->setAutoResized(VFX_TRUE);
        m_messageFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(PAGE_MESSAGE_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_messageFrame->setSize((VfxS32)(getSize().width * VCP_LIST_MENU_EMPTY_TEXT_WITH_RATIO), getSize().height / 3);
        m_messageFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_messageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_messageFrame->setPos(getSize().width / 2, getSize().height / 2);
        m_messageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID,
                                       VFX_FRAME_ALIGNER_MODE_MID);
    }
    m_messageFrame->setHidden(VFX_FALSE);
    m_messageFrame->setString(m_pageMessage);
    m_messageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_messageFrame->bringToFront();
}

void VappMovieTheaterPage::showPageWaitIcon(VfxBool isShow)
{
    if(!isShow && m_waitIcon)
    {
        m_waitIcon->stop();
        m_waitIcon->sendToBack();
        return;
    }

    if(NULL == m_waitIcon)
    {
        VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
        m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
        m_waitIcon->setAnchor(0.5f, 0.5f);
        m_waitIcon->setPos(getSize().width / 2, getSize().height / 2);
        m_waitIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID);

    }
    m_waitIcon->start();
    m_waitIcon->bringToFront();
}

void VappMovieTheaterPage::setProvider(VappMovieTheaterContentProvider *provider)
{
    m_provider = provider;
}

VfxBool VappMovieTheaterPage::getPageCurrentStorage(U8 &drvLetter)
{
    return VFX_FALSE;
}

void VappMovieTheaterPage::onVideoPlayerExitProc(vapp_gallery_last_play_struct* param, void* userData)
{
    // check if object is valid
    VappMovieTheaterPage* pThis = (VappMovieTheaterPage*)handleToObject((VfxObjHandle)userData);
    if (NULL == pThis)
    {
        return;
    }

    VfxWString path;
    pThis->m_provider->getMediaPath(pThis->m_currMediaId, path);

    if (kal_wstrcmp(path.getBuf(), param->file_path))
    {
        // not the file we just played.
        return;
    }

	pThis->m_plUpdateRet = pThis->m_provider->addLastPlayMedia(pThis->m_currMediaId, param->last_play_time);

}

void VappMovieTheaterPage::launchVideoPlayer(VfxWString &path, VfxU64 time)
{
    // launch Gallery Player here
    // set launch option
    vapp_gallery_video_player_launch_option_struct option;

    vapp_gallery_video_player_launch_option_init(&option);
    option.start_time_hint = time;
    option.user_proc = &VappMovieTheaterPage::onVideoPlayerExitProc;
    option.user_data = getObjHandle();

    vapp_gallery_video_player_launch(path.getBuf(), &option);
}

VappMovieTheaterStorageSetting::VappMovieTheaterStorageSetting()
{
    readFromNVRAM();
    m_dirty = VFX_FALSE;
}

VappMovieTheaterStorageSetting::~VappMovieTheaterStorageSetting()
{
    if(m_dirty)
    {
        flushToNVRAM();
    }
}

// get default storage
srv_fmgr_drv_type_enum VappMovieTheaterStorageSetting::getDefaultStorage(VfxBool correntInvalidStorage)
{
    if(correntInvalidStorage)
    {
        // check if default storage is in accessible list
        SRV_FMGR_DRVLIST_HANDLE hDrvList = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
        if(-1 == srv_fmgr_drivelist_get_index_by_drv_type(hDrvList, m_defaultDriveType))
        {
            // fallback to phone storage if default drive is not accessible.
            m_dirty = VFX_TRUE;
            m_defaultDriveType = SRV_FMGR_DRV_PHONE_TYPE;
        }
        srv_fmgr_drivelist_destroy(hDrvList);
    }
    return m_defaultDriveType;
}

// set default storage
void VappMovieTheaterStorageSetting::setDefaultStorage(srv_fmgr_drv_type_enum drvType)
{
    if(m_defaultDriveType != drvType)
    {
        m_dirty = VFX_TRUE;
        m_defaultDriveType = drvType;
    }
}

void VappMovieTheaterStorageSetting::readFromNVRAM()
{
    // read MMI_CACHE
    VfxS16 sError = 0;
    VfxU8 defaultStorage = 0;
    ReadValue(NVRAM_VAPP_MOVIE_THEATER_OPT_DEFAULT_DRV_TYPE, (void*)&defaultStorage, DS_BYTE, &sError);
    m_defaultDriveType = static_cast<srv_fmgr_drv_type_enum>(defaultStorage);
}

void VappMovieTheaterStorageSetting::flushToNVRAM()
{
    // write MMI_CACHE
    VfxS16 sError = 0;
    VfxU8 defaultStorage = static_cast<VfxU8>(m_defaultDriveType);
    WriteValue(NVRAM_VAPP_MOVIE_THEATER_OPT_DEFAULT_DRV_TYPE, (void*)&defaultStorage, DS_BYTE, &sError);
}

/*****************************************************************************
 * VappMovieTheaterContentProvider Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMovieTheaterContentProvider", VappMovieTheaterContentProvider, VfxObject);

VappMovieTheaterContentProvider::VappMovieTheaterContentProvider():
    m_srvMot(0),
    m_mediaId(NULL)
{
    m_mediaInfo = NULL;
    m_currMediaId = (VfxU32)-1;

    for (VfxS32 i=0; i<VAPP_MOVIE_THEATER_CACHE_SIZE; i++)
    {
        m_tCache[i].isUsed = VFX_FALSE;
        m_tCache[i].mediaId = (VfxU32)-1;
        m_tCache[i].thumbnail_size = 0;
        m_tCache[i].thumbnail_buf = NULL;
    }
}

void VappMovieTheaterContentProvider::onInit()
{
    VfxObject::onInit();

    srv_mot_create_struct create_param;
    VappMovieTheater *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMovieTheater);

    m_appId = app->getGroupId();
    create_param.callback = &VappMovieTheaterContentProvider::MOTCallback;
    create_param.user_data = (void*)this;
    create_param.app_id = m_appId;
    m_srvMot = srv_mot_create(&create_param);

    VFX_ASSERT(m_srvMot);

    m_lastCacheIdx = (VfxU32)-1;

    m_state = PROVIDER_STATE_INITED;
}

void VappMovieTheaterContentProvider::onDeinit()
{
    close();
    srv_mot_destroy(m_srvMot);
    m_srvMot = 0;

    if (m_mediaId)
    {
        VFX_FREE_MEM(m_mediaId);
    }

    if (m_mediaInfo)
    {
        VFX_FREE_MEM(m_mediaInfo);
    }

    VfxObject::onDeinit();
}

srv_mot_ret_enum VappMovieTheaterContentProvider::open(srv_fmgr_drv_type_enum type)
{
    srv_mot_open_struct open_param;
    srv_mot_ret_enum ret;

    // initialization
    if (m_mediaInfo == NULL)
    {
        VFX_ALLOC_MEM(m_mediaInfo, sizeof(srv_mot_content_info_struct), this);
    }
    m_currMediaId = (VfxU32)-1;
    clearCache();

    open_param.drive_letter = srv_fmgr_drv_get_letter_by_type(type);
    ret = srv_mot_open(m_srvMot, &open_param);

    if (ret >= 0)
    {
        m_state = PROVIDER_STATE_OPENED;
    }

    return ret;
}

void VappMovieTheaterContentProvider::close()
{
    stopUpdating();
    if (m_state == PROVIDER_STATE_OPENED)
    {
        srv_mot_close(m_srvMot);

        m_currMediaId = (VfxU32)-1;
        m_state = PROVIDER_STATE_INITED;
    }
}

srv_mot_ret_enum VappMovieTheaterContentProvider::update()
{
    srv_mot_ret_enum ret = SRV_MOT_S_OK;

    if (m_state == PROVIDER_STATE_OPENED)
    {
        ret = srv_mot_update(m_srvMot);
        if (ret >= 0)
        {
            m_state = PROVIDER_STATE_UPDATING;
        }
        return ret;
    }

    // impossible!! state must be checked before calling update.
    VFX_ASSERT(0);

    return ret;
}

void VappMovieTheaterContentProvider::stopUpdating()
{
    if (m_state == PROVIDER_STATE_UPDATING)
    {
        srv_mot_stop_updating(m_srvMot);
        m_state = PROVIDER_STATE_OPENED;
    }
}

void VappMovieTheaterContentProvider::refreshCategoryList(srv_mot_cat_enum category)
{
    if (m_state != PROVIDER_STATE_OPENED)
    {
        return;
    }

    VfxU32 number;

    if (m_mediaId)
    {
        VFX_FREE_MEM(m_mediaId);
    }

    getCategoryCount(category, &number);
    VFX_ALLOC_MEM(m_mediaId, number * sizeof(VfxU32), this);

    srv_mot_ret_enum ret;
    srv_mot_list_info_struct* list_info;
    VfxU32 i = 0;

    VFX_ALLOC_MEM(list_info, sizeof(srv_mot_list_info_struct), this);

    ret = srv_mot_get_list_info_start(m_srvMot, category, i, SRV_MOT_SORT_DIR_ASC, list_info);

    while (ret == SRV_MOT_S_OK && i < number)
    {
        m_mediaId[i] = list_info->content_id;
        ret = srv_mot_get_list_info_next(m_srvMot, list_info);
        i++;
    };

    VFX_FREE_MEM(list_info);
}


void VappMovieTheaterContentProvider::getCategoryString(srv_mot_cat_enum category, VfxWString &text)
{
    MMI_ID_TYPE cat_str;

    srv_mot_get_category_string_id(category, &cat_str);

    text = VFX_WSTR_RES(cat_str);
}

void VappMovieTheaterContentProvider::getCategoryString(VfxU32 mediaId, VfxWString &text)
{
    MMI_ID_TYPE cat_str;

    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    srv_mot_get_category_string_id(m_mediaInfo->category, &cat_str);

    text = VFX_WSTR_RES(cat_str);
}

void VappMovieTheaterContentProvider::getCategoryCount(srv_mot_cat_enum category, VfxU32 *number)
{
    if (m_state == PROVIDER_STATE_OPENED)
    {
        srv_mot_get_content_number(m_srvMot, category, number);
    }
    else
    {
        *number = 0;
    }
}

void VappMovieTheaterContentProvider::getMediaName(VfxU32 mediaId, VfxWString &str)
{
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    WCHAR* pBuf = str.lockBuf(SRV_MOT_FILE_NAME_LEN + 1);

    kal_mem_cpy(pBuf, m_mediaInfo->filename, (SRV_MOT_FILE_NAME_LEN + 1)*sizeof(WCHAR));

    str.unlockBuf();
}

void VappMovieTheaterContentProvider::getMediaPath(VfxU32 mediaId, VfxWString &str)
{
    srv_mot_file_path_struct path;

    srv_mot_get_content_path(m_srvMot, mediaId, &path);

    WCHAR* pBuf = str.lockBuf(SRV_MOT_FILE_PATH_LEN + 1);

    kal_mem_cpy(pBuf, path.filepath, (SRV_MOT_FILE_PATH_LEN + 1)*sizeof(WCHAR));

    str.unlockBuf();
}

void VappMovieTheaterContentProvider::getMediaDuration(VfxU32 mediaId, U64 &duration)
{
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    duration = m_mediaInfo->duration;
}

void VappMovieTheaterContentProvider::getMediaDuration(VfxU32 mediaId, VfxWString &str)
{
    U64 duration;

    getMediaDuration(mediaId, duration);
    formatTimeText(str, duration);
}

void VappMovieTheaterContentProvider::getMediaDurationStr(VfxU32 mediaId, VfxWString &str)
{
    U64 duration;
    VfxWString tempText;

    getMediaDuration(mediaId, duration);
    str = VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_DURATION);
    tempText.format(": ");
    str += tempText;
    formatTimeText(tempText, duration);
    str += tempText;
}

void VappMovieTheaterContentProvider::getMediaLastPlayTime(VfxU32 mediaId, U64 &time)
{
    srv_mot_get_recent_playtime(m_srvMot, mediaId, &time);
}

void VappMovieTheaterContentProvider::getMediaLastPlayTimeStr(VfxU32 mediaId, VfxWString &str)
{

    U64 time;
    VfxWString tempText;

    getMediaLastPlayTime(mediaId, time);

    str = VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_LAST_PLAY_TIME);
    tempText.format(": ");
    str += tempText;
    formatTimeText(tempText, time);
    str += tempText;
}


//#define JPG_TESTING

#ifdef JPG_TESTING
static kal_uint8 jpg_pool[4*1024];
#define fn   L"e:\\60x60.jpg"
#endif

void VappMovieTheaterContentProvider::getMediaThumb(VfxU32 mediaId, U8 *buf, U32 &bufSize)
{
    /* check just readed buffer */
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    bufSize = 0;

#ifdef JPG_TESTING
    FS_HANDLE fh;
    VfxU32 filesize, realsize;
    fh = FS_Open((const WCHAR*)fn, FS_READ_ONLY);

    FS_GetFileSize(fh, &filesize);
    FS_Read(fh, jpg_pool, filesize, &realsize);

    S32 width, height;
    // add image header here!

    buf[0] = (U8)gdi_image_get_type_from_mem((PS8)jpg_pool);
    if (GDI_IMAGE_TYPE_INVALID == buf[0])
    {
        // invalid image buffer
        FS_Close(fh);
        return;
    }
    gdi_image_get_dimension_mem(buf[0], jpg_pool, filesize, &width, &height);
    buf[1] = 1;
    buf[2] = filesize & 0xff;
    buf[3] = (filesize >> 8) & 0xff;
    buf[4] = (filesize >> 16) & 0xff;
    buf[5] = height & 0xff;
    buf[6] = ((height & 0xf00) >> 8) + ((width & 0xf) << 4);
    buf[7] = (width >> 4) & 0xff;

    kal_mem_cpy(buf + 8, jpg_pool, filesize);
    bufSize = filesize + 8;

    FS_Close(fh);
#else
    if (m_mediaInfo->thumbnail_size)
    {
        // fill to cache
        S32 width, height;

        // add res image header
        buf[0] = (U8)gdi_image_get_type_from_mem((PS8)m_mediaInfo->thumbnail_buf);

        if (GDI_IMAGE_TYPE_INVALID == buf[0])
        {
            // invalid image buffer
            return;
        }

        gdi_image_get_dimension_mem(buf[0], m_mediaInfo->thumbnail_buf, m_mediaInfo->thumbnail_size, &width, &height);
        buf[1] = 1;
        buf[2] = m_mediaInfo->thumbnail_size & 0xff;
        buf[3] = (m_mediaInfo->thumbnail_size >> 8) & 0xff;
        buf[4] = (m_mediaInfo->thumbnail_size >> 16) & 0xff;
        buf[5] = height & 0xff;
        buf[6] = ((height & 0xf00) >> 8) + ((width & 0xf) << 4);
        buf[7] = (width >> 4) & 0xff;

        kal_mem_cpy(buf + 8, m_mediaInfo->thumbnail_buf, m_mediaInfo->thumbnail_size);
        bufSize = m_mediaInfo->thumbnail_size + 8;
    }
#endif
}

void VappMovieTheaterContentProvider::getMediaThumb(VfxU32 mediaId, U8 **buf, U32 &bufSize)
{
    VfxU32 cacheIdx;

    VFX_ASSERT(m_tCache[0].thumbnail_buf);

    /* check cache */
    if (isInCache(mediaId, cacheIdx))
    {
        getFromCache(cacheIdx, buf, bufSize);

        return;
    }

    /* check just readed buffer */
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    // get empty slot and fill it.
    VappMovieTheaterThumbCacheStruct* tpCache = getEmptyCache();

    bufSize = 0;
#ifdef JPG_TESTING
    FS_HANDLE fh;
    VfxU32 filesize, realsize;
    fh = FS_Open((const WCHAR*)fn, FS_READ_ONLY);

    FS_GetFileSize(fh, &filesize);
    FS_Read(fh, jpg_pool, filesize, &realsize);

    S32 width, height;
    // add image header here!

    tpCache->thumbnail_buf[0] = (U8)gdi_image_get_type_from_mem((PS8)jpg_pool);
    if (GDI_IMAGE_TYPE_INVALID == tpCache->thumbnail_buf[0])
    {
        // invalid image buffer
        FS_Close(fh);
        return;
    }
    gdi_image_get_dimension_mem(tpCache->thumbnail_buf[0], jpg_pool, filesize, &width, &height);
    tpCache->thumbnail_buf[1] = 1;
    tpCache->thumbnail_buf[2] = filesize & 0xff;
    tpCache->thumbnail_buf[3] = (filesize >> 8) & 0xff;
    tpCache->thumbnail_buf[4] = (filesize >> 16) & 0xff;
    tpCache->thumbnail_buf[5] = height & 0xff;
    tpCache->thumbnail_buf[6] = ((height & 0xf00) >> 8) + ((width & 0xf) << 4);
    tpCache->thumbnail_buf[7] = (width >> 4) & 0xff;

    kal_mem_cpy(tpCache->thumbnail_buf + 8, jpg_pool, filesize);
    tpCache->thumbnail_size = filesize + 8;
    tpCache->isUsed = VFX_TRUE;
    tpCache->mediaId = mediaId;

    // output
    *buf = tpCache->thumbnail_buf;
    bufSize = tpCache->thumbnail_size;

    FS_Close(fh);
#else
    if (m_mediaInfo->thumbnail_size)
    {
        // fill to cache
        S32 width, height;

        // add res image header
        tpCache->thumbnail_buf[0] = (U8)gdi_image_get_type_from_mem((PS8)m_mediaInfo->thumbnail_buf);

        if (GDI_IMAGE_TYPE_INVALID == tpCache->thumbnail_buf[0])
        {
            // invalid image buffer
            return;
        }

        gdi_image_get_dimension_mem(tpCache->thumbnail_buf[0], m_mediaInfo->thumbnail_buf, m_mediaInfo->thumbnail_size, &width, &height);
        tpCache->thumbnail_buf[1] = 1;
        tpCache->thumbnail_buf[2] = m_mediaInfo->thumbnail_size & 0xff;
        tpCache->thumbnail_buf[3] = (m_mediaInfo->thumbnail_size >> 8) & 0xff;
        tpCache->thumbnail_buf[4] = (m_mediaInfo->thumbnail_size >> 16) & 0xff;
        tpCache->thumbnail_buf[5] = height & 0xff;
        tpCache->thumbnail_buf[6] = ((height & 0xf00) >> 8) + ((width & 0xf) << 4);
        tpCache->thumbnail_buf[7] = (width >> 4) & 0xff;

        kal_mem_cpy(tpCache->thumbnail_buf + 8, m_mediaInfo->thumbnail_buf, m_mediaInfo->thumbnail_size);
        tpCache->thumbnail_size = m_mediaInfo->thumbnail_size + 8;
        tpCache->isUsed = VFX_TRUE;
        tpCache->mediaId = mediaId;

        // output
        *buf = tpCache->thumbnail_buf;
        bufSize = tpCache->thumbnail_size;
    }
#endif
}


void VappMovieTheaterContentProvider::freeMediaThumb(VfxU32 mediaId)
{
    setCacheUnused(mediaId);
}

void VappMovieTheaterContentProvider::getMediaTitle(VfxU32 mediaId, VfxWString &str)
{
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    U32 strLen = kal_wstrlen(m_mediaInfo->title);
    if (strLen)
    {
        WCHAR* pBuf = str.lockBuf(strLen + 1);

        kal_mem_cpy(pBuf, m_mediaInfo->title, (strLen + 1)*sizeof(WCHAR));

        str.unlockBuf();
    }
    else
    {
        MMI_ID_TYPE str_id;
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_MOVIE_NAME, &str_id);
        str = VFX_WSTR_RES(str_id);
    }
}

void VappMovieTheaterContentProvider::getMediaYear(VfxU32 mediaId, VfxWString &str)
{
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    U32 strLen = kal_wstrlen(m_mediaInfo->datetime);
    if (strLen)
    {
        WCHAR* pBuf = str.lockBuf(strLen + 1);

        kal_mem_cpy(pBuf, m_mediaInfo->datetime, (strLen + 1)*sizeof(WCHAR));

        str.unlockBuf();
    }
    else
    {
        MMI_ID_TYPE str_id;
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_YEAR, &str_id);
        str = VFX_WSTR_RES(str_id);
    }
}

void VappMovieTheaterContentProvider::getMediaStarring(VfxU32 mediaId, VfxWString &str)
{
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    U32 strLen = kal_wstrlen(m_mediaInfo->artist);
    if (strLen)
    {
        WCHAR* pBuf = str.lockBuf(strLen + 1);

        kal_mem_cpy(pBuf, m_mediaInfo->artist, (strLen + 1)*sizeof(WCHAR));

        str.unlockBuf();
    }
    else
    {
        MMI_ID_TYPE str_id;
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_STARRING, &str_id);
        str = VFX_WSTR_RES(str_id);
    }
}

void VappMovieTheaterContentProvider::getMediaPlot(VfxU32 mediaId, VfxWString &str)
{
    if (mediaId != m_currMediaId)
    {
        srv_mot_get_content_info(m_srvMot, mediaId, m_mediaInfo);
        m_currMediaId = mediaId;
    }

    U32 strLen = kal_wstrlen(m_mediaInfo->descript);
    if (strLen)
    {
        WCHAR* pBuf = str.lockBuf(strLen + 1);

        kal_mem_cpy(pBuf, m_mediaInfo->descript, (strLen + 1)*sizeof(WCHAR));

        str.unlockBuf();
    }
    else
    {
        MMI_ID_TYPE str_id;
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_PLOT, &str_id);
        str = VFX_WSTR_RES(str_id);
    }
}

void VappMovieTheaterContentProvider::getMediaId(const VfxU32 index, U32 &mediaId)
{
    mediaId = m_mediaId[index];
}

srv_mot_ret_enum VappMovieTheaterContentProvider::addLastPlayMedia(VfxU32 mediaId, U64 playTime)
{
	srv_mot_ret_enum ret;

    ret = srv_mot_add_recent_playlist(m_srvMot, mediaId, playTime);

	return ret;
}

void VappMovieTheaterContentProvider::getErrorString(srv_mot_ret_enum error, VfxWString &text)
{
    MMI_ID_TYPE cat_str;

    srv_mot_get_error_string_id(m_srvMot, error, &cat_str);

    text = VFX_WSTR_RES(cat_str);
}

VfxBool VappMovieTheaterContentProvider::isDBReady()
{
    if (PROVIDER_STATE_OPENED == m_state)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

srv_mot_ret_enum VappMovieTheaterContentProvider::memorySpaceCheck()
{
	srv_mot_ret_enum ret = SRV_MOT_S_OK;
	ret = srv_mot_update_memory_check(m_srvMot);
	return ret;
}

void VappMovieTheaterContentProvider::createMediaCache()
{
    VFX_ASSERT(m_tCache[0].thumbnail_buf == NULL);

    for (VfxS32 i = 0; i < VAPP_MOVIE_THEATER_CACHE_SIZE; i++)
    {
        m_tCache[i].thumbnail_buf = (VfxU8*)applib_asm_alloc_nc_r(m_appId, SRV_MOT_THUMBNAIL_SIZE);
        //VFX_ALLOC_MEM(m_tCache[i].thumbnail_buf, SRV_MOT_THUMBNAIL_SIZE, this);
    }
}

void VappMovieTheaterContentProvider::destroyMediaCache()
{
    VFX_ASSERT(m_tCache[0].thumbnail_buf);

    for (VfxS32 i = 0; i < VAPP_MOVIE_THEATER_CACHE_SIZE; i++)
    {
        applib_asm_free_r(m_appId, m_tCache[i].thumbnail_buf);
        m_tCache[i].isUsed = VFX_FALSE;
        m_tCache[i].mediaId = (VfxU32)-1;
        m_tCache[i].thumbnail_size = 0;
        m_tCache[i].thumbnail_buf = NULL;
    }
}

VfxBool VappMovieTheaterContentProvider::isInCache(VfxU32 mediaId, VfxU32 &cacheIdx)
{
    for (VfxS32 i = 0; i < VAPP_MOVIE_THEATER_CACHE_SIZE; i++)
    {
        if (m_tCache[i].mediaId == mediaId)
        {
            cacheIdx = i;
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

void VappMovieTheaterContentProvider::getFromCache(VfxU32 cacheIdx, U8 **buf, U32 &bufSize)
{
    *buf = m_tCache[cacheIdx].thumbnail_buf;
    bufSize = m_tCache[cacheIdx].thumbnail_size;

    m_tCache[cacheIdx].isUsed = VFX_TRUE;
}

void VappMovieTheaterContentProvider::setCacheUnused(VfxU32 mediaId)
{
    VfxU32 cacheIdx;

    if (isInCache(mediaId, cacheIdx))
    {
        m_tCache[cacheIdx].isUsed = VFX_FALSE;
    }
    else
    {
        // impossible! must in cache!
        VFX_ASSERT(0);
    }
}

VappMovieTheaterThumbCacheStruct* VappMovieTheaterContentProvider::getEmptyCache()
{
    VfxU32 i;
    VfxU32 nextIdx = ((m_lastCacheIdx + 1) % VAPP_MOVIE_THEATER_CACHE_SIZE);
    VfxU32 currIdx;

    for (i = nextIdx; i < (nextIdx + VAPP_MOVIE_THEATER_CACHE_SIZE); i++)
    {
        currIdx = i % VAPP_MOVIE_THEATER_CACHE_SIZE;
        if (m_tCache[currIdx].isUsed == VFX_FALSE)
        {
            m_lastCacheIdx = currIdx;
            return &m_tCache[currIdx];
        }
    }

    // cache not enough! please enlarge it!
    VFX_ASSERT(0);

    return NULL;
}

void VappMovieTheaterContentProvider::clearCache()
{
    for (VfxS32 i = 0; i < VAPP_MOVIE_THEATER_CACHE_SIZE; i++)
    {
        m_tCache[i].isUsed = VFX_FALSE;
        m_tCache[i].mediaId = (VfxU32)-1;
        m_tCache[i].thumbnail_size = 0;
    }
}

void VappMovieTheaterContentProvider::setCBReceiver(VfxObject* receiver)
{
    m_cbReceiver = receiver;
}


static U64 msecToSec(U64 timeMsec)
{
    const VfxU64 seconds_offset = (500 < (timeMsec % 1000))? 1 : 0;
    const U64 timeSec = timeMsec / 1000 + seconds_offset;
    return timeSec;
}

// format miliseconds into "HH:MM:SS" format.
// if hideHourIfZero is VFX_TRUE, then "MM:SS" is used when the time is less than 1 hour.
void VappMovieTheaterContentProvider::formatTimeText(VfxWString &timeText, U64 timeMsec, VfxBool hideHourIfZero)
{
    const VfxU32 seconds = (VfxU32)msecToSec(timeMsec);
    const VfxU32 minutes = seconds / 60;
    const VfxU32 hours = minutes / 60;
    const VfxU32 sec_part = seconds % 60;
    const VfxU32 min_part = minutes % 60;
    const VfxU32 hour_part = vfxMin((VfxU32)99, hours); // clamp at 99 hours
    if(hideHourIfZero && 0 == hours)
    {
        timeText.format("%02d:%02d", min_part, sec_part);
    }
    else
    {
        timeText.format("%d:%02d:%02d", hour_part, min_part, sec_part);
    }
}


VfxS32 VappMovieTheaterContentProvider::MOTCallback(void* user_data, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param)
{
    VappMovieTheaterContentProvider *pThis = reinterpret_cast<VappMovieTheaterContentProvider*>(user_data);

    if (cb_event == SRV_MOT_CB_EVT_UPDATED)
    {
        pThis->m_state = PROVIDER_STATE_OPENED;

        //m_signalMOTCallback.emit(cb_event, result, param);
        VappMovieTheaterIndexPage* index_page = VFX_OBJ_DYNAMIC_CAST(pThis->m_cbReceiver, VappMovieTheaterIndexPage);
        index_page->updateListItems(result);
    }

    return 0;
}

//DCM
#pragma arm section code, rodata


#endif // __MMI_COSMOS_MOVIE_THEATER__
