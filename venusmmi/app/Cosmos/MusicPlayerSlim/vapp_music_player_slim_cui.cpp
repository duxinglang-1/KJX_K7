

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#include "vapp_music_player_slim_cui.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_vol_dialog_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_vapp_music_player_slim_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_music_player_slim_util.h"
#include "mmi_rp_srv_prof_def.h"
#include "vapp_music_player_slim_ctrlplayback.h"
#include "vapp_music_player_slim_nowplaying.h"
#include "vapp_music_player_slim_singleplayer.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "..\interface\cui\vcui_music_player_gprot.h"
#include "UcmSrvGProt.h"
#include "AppMgrSrvGprot.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static void* g_cui_this_ptr = NULL;

/***************************************************************************** 
 * Function
 *****************************************************************************/

// CUI functions

mmi_id vcui_music_player_create(mmi_id parent_id, const VfxWChar* file_path)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_MUSIC_PLAYER,                     /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiMusicPlayer),  /* Cui class */
        parent_id,                            /* parent group id */
        const_cast<VfxWChar*>(file_path), (vfx_sys_wcslen(file_path)+1) * sizeof(VfxWChar));        /* parameters, if any */

    VcuiMusicPlayer *cui = (VcuiMusicPlayer *)VfxApp::getObject(cui_id);
    cui->m_cuiId = cui_id;
    g_cui_this_ptr = cui;
    return cui_id;
}

void vcui_music_player_set_title(mmi_id cui_id, const VfxWChar* title)
{
   /* VcuiMusicPlayer *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiMusicPlayer);
    VfxWString str;
    str.loadFromMem(title);
    cui->setTitle(str, VFX_WSTR(""));*/
}

void vcui_music_player_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void vcui_music_player_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


/***************************************************************************** 
 * Implement VcuiMusicPlayer class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiMusicPlayer", VcuiMusicPlayer, VfxCui);

void VcuiMusicPlayer::onRun(void * args, VfxU32 argSize)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_AP_ON_RUN);
    
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE_EX(m_scr, VcuiMusicPlayerScreen, this, (VFX_FALSE));
    m_scr->parseFilePath(args, argSize);

    // register proc event
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_TRUE);
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_PROF_IS_PLAYING, VFX_TRUE);
    
    // show CUI screen
    m_scr->show();

}

void VcuiMusicPlayer::notifyCaller()
{
    mmi_group_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_MUSIC_PLAYER_CLOSE, m_cuiId);
    postToCaller((mmi_group_event_struct*)&evt);
}

void VcuiMusicPlayer::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_AP_ON_DEINIT);

    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_FALSE);
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_FALSE);
#if defined (__MMI_AVRCP_SUPPORT__)
    deregisterAVRCPcallback();
#endif
    VfxCui::onDeinit();
}

VappMusicPlayerNowPlayingPage* VcuiMusicPlayer::getNowPlayingPage()
{
    if (!m_screenClosing && m_scr)
    {
        return m_scr->getNowPlaying();
    }
    return NULL;
}
void VcuiMusicPlayer::clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying)
{
    if (!m_screenClosing && m_scr)
    {
        m_scr->clearNowPlayingPtr(nowPlaying);
    }
}
void VcuiMusicPlayer::onGroupActive(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_AP_ON_GROUP_ACTIVE);
}
void VcuiMusicPlayer::onGroupInactive(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_AP_ON_GROUP_INACTIVE);
    
    if (getNowPlayingPage())
    {
        getNowPlayingPage()->closeMetaParser();
    }
}
mmi_ret VcuiMusicPlayer::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_AP_ON_PROC, evt->evt_id);
    
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            mmi_group_event_struct evt;
            MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_MUSIC_PLAYER_CLOSE, m_cuiId);
            postToCaller((mmi_group_event_struct*)&evt);
            break;
        }
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            VappMusicPlayerNowPlayingPage *nowPlayingPage = getNowPlayingPage();
            if(nowPlayingPage == NULL)
            {
                break;
            }

            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
            {
                /* Disable all UI in call */
                nowPlayingPage->setEnablePlaybackUI(VFX_FALSE);
            }
            else
            {
                /* Enable UI end call */
                nowPlayingPage->setEnablePlaybackUI(VFX_TRUE);
            }
            break;
        }
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:      
        {
            vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*) evt;

            if (volEvent->type == VAPP_VOL_DIALOG_IS_MEDIA)
            {
                const VfxBool isTopActive = isGroupTopActive();
                if (isTopActive)
                {
                    return !MMI_RET_OK;
                }
                else
                {
                    return MMI_RET_OK;
                }
            }
            break;
        }
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
           const vapp_screen_lock_pre_lock_evt_struct *lockEvt = reinterpret_cast<vapp_screen_lock_pre_lock_evt_struct*>(evt);
           VappMusicPlayerCtrlPlaybackSlim *ctrlPlayback = NULL;
           if(m_scr)
           {
               ctrlPlayback = m_scr->getCtrlPlayback();       
           }
           else
           {
                  return MMI_RET_OK;
           }
              const PlaybackStateEnum state = ctrlPlayback->getPlaybackState();
           if (lockEvt->mode == VAPP_SCREEN_LOCK_MODE_BY_POWER_KEY)
           {
               if (state == PB_STATE_PLAY)
               {
                   if(ctrlPlayback->isSongPausable())
                   {
                       ctrlPlayback->pause();
                   }
                   else
                   {
                       ctrlPlayback->stop();
                   }
               }
               if(state == PB_STATE_SEEKING)
               {
                   ctrlPlayback->seekStop(VFX_TRUE);
               }
               return MMI_RET_OK;
           }
           else if (lockEvt->mode == VAPP_SCREEN_LOCK_MODE_BY_AUTO_LOCK)
           {
               if (state == PB_STATE_PLAY)
               {
                   return MMI_RET_ERR;
               }
               return MMI_RET_OK;
           }
           break;
        }
        default:
            break;
        }

    return VfxCui::onProc(evt);
}

void VcuiMusicPlayer::setTitle(VfxWString str1, VfxWString str2)
{
    if (!m_screenClosing && m_scr)
    {
        m_scr->setTitle(str1, str2);
    }
}
#if defined (__MMI_AVRCP_SUPPORT__)
void VcuiMusicPlayer::registerAVRCPcallbak()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_REGISTER_AVRCP);

    srv_avrcp_set_cmd_hdlr(onAVRCPCmdCallback);
}
void VcuiMusicPlayer::deregisterAVRCPcallback()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_DEREGISTER_AVRCP);

    srv_avrcp_clear_cmd_hdlr(onAVRCPCmdCallback);
}
U8 VcuiMusicPlayer::onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_ON_AVRCP_CALLBACK);

    VcuiMusicPlayer *cui = reinterpret_cast<VcuiMusicPlayer*>(g_cui_this_ptr);
    VFX_ASSERT(cui);

    // Only act AVRCP command for active screen
    if (!cui->isGroupActive())
    {
        return SRV_AVRCP_CR_ACCEPT;
    }
    VappMusicPlayerNowPlayingPage* nowPlaying = cui->getNowPlayingPage();
    VFX_ASSERT(nowPlaying);
    return cui->m_scr->onAVRCPCmdCallback(command_type, key_events);
}
#endif //__MMI_AVRCP_SUPPORT__
/***************************************************************************** 
 * Implement VcuiMusicPlayerScreen class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiMusicPlayerScreen", VcuiMusicPlayerScreen, VfxMainScr);

void VcuiMusicPlayerScreen::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_ON_INIT);

    VfxMainScr::onInit();
    
    //create nowplaying page
    VFX_OBJ_CREATE_EX(m_nowPlaying, VappMusicPlayerNowPlayingPage, this, (PAGE_MODE_CUI));

    // create wait icon
    VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
    m_waitIcon->setAnchor(0.5, 0.5);
    m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
    m_waitIcon->setPos(GDI_LCD_WIDTH/2, (GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT)/2);
    m_waitIcon->stop();

    
    //create playback ctrl
    VFX_OBJ_CREATE(m_ctrlPlayback, VappMusicPlayerCtrlPlaybackSlim, this);
    m_nowPlaying->setCtrlPlayback(m_ctrlPlayback);
    setBgColor(VRT_COLOR_BLACK);

#if defined(__MMI_NCENTER_SUPPORT__)
    VappNCenter *ncenter =  VFX_OBJ_GET_INSTANCE(VappNCenter);
    if(ncenter != NULL)
    {
        ncenter->m_signalEvent.connect(this, &VcuiMusicPlayerScreen::onNCenterStatusChanged);
    }
#endif
}

void VcuiMusicPlayerScreen::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_ON_DEINIT);

    VcuiMusicPlayer *parent = VFX_OBJ_DYNAMIC_CAST(getParent(), VcuiMusicPlayer);
    
    if (parent)
    {
        parent->m_screenClosing = VFX_TRUE;
    }

    m_screenClosing = VFX_TRUE;
    //need to close file path
    m_ctrlPlayback->close();
    m_ctrlPlayback->m_signalCtrlPlayback.disconnect(this, &VappMusicPlayerNowPlayingPage::onPlaybackCallback);
#if defined(__MMI_NCENTER_SUPPORT__)
    VappNCenter *ncenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if(ncenter != NULL)
    {
        ncenter->m_signalEvent.disconnect(this, &VcuiMusicPlayerScreen::onNCenterStatusChanged);
    }
#endif
    VfxMainScr::onDeinit();
}

void VcuiMusicPlayerScreen::on1stReady()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_ON_1ST_READY);
    
    VfxMainScr::on1stReady();

    pushPage(0, m_nowPlaying);
}
void VcuiMusicPlayerScreen::showWaitIcon(VfxBool delayShow)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_SHOW_WAITICON);

    if (delayShow)
    {
        if (m_waitIconTimer.get() == NULL)
        {
            VFX_OBJ_CREATE(m_waitIconTimer, VfxTimer, this);
            m_waitIconTimer->setStartDelay(300);
            m_waitIconTimer->m_signalTick.connect(this, &VcuiMusicPlayerScreen::doShowWaitIcon);
        }
        m_waitIconTimer->start();
    }
    else
    {
        doShowWaitIcon(NULL);
    }
}

void VcuiMusicPlayerScreen::doShowWaitIcon(VfxTimer *timer)
{
    if (m_waitIcon)
    {
        m_waitIcon->bringToFront();
        m_waitIcon->setHidden(VFX_FALSE);
        m_waitIcon->start();
    }
}

void VcuiMusicPlayerScreen::hideWaitIcon()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_HIDE_WAITICON);

    if (m_waitIconTimer.get())
    {
        m_waitIconTimer->stop();
    }

    if (m_waitIcon)
    {
        if (m_waitIcon->isAnimating())
        {
            m_waitIcon->stop();
        }

        m_waitIcon->setHidden(VFX_TRUE);
        m_waitIcon->sendToBack();
    }
}

void VcuiMusicPlayerScreen::on2ndReady()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_ON_2ND_READY);

    VfxMainScr::on2ndReady();    

    //open file and handle error situation in play()
    play();    
}
void VcuiMusicPlayerScreen::parseFilePath(void *args, VfxU32 argSize)
{
    //set file path
    VfxWChar *filePath;
    VfxWString title, str;
    VFX_ALLOC_MEM(filePath, argSize, getApp());
    memcpy(filePath, args, argSize);
    str.loadFromMem(filePath);
    setFilePath(str);
    VFX_FREE_MEM(filePath);
}
VfxWString VcuiMusicPlayerScreen::getFilePath()
{
    return m_filePath;
}
void VcuiMusicPlayerScreen::setFilePath(VfxWString &filePath)
{
    m_filePath = filePath;
}

void VcuiMusicPlayerScreen::setTitle(VfxWString &title, VfxWString &subtitle)
{
    m_title = title;
    m_subtitle = subtitle;
    artist_info_struct *info = NULL;
    
    m_nowPlaying->setAlbumCover(m_filePath, PAGE_SWITCH_DIR_NONE);
    
    if (m_filePath.isNull() || m_filePath.isEmpty())
    {
        m_nowPlaying->setEmpty();
        m_nowPlaying->setEnablePlaybackUI(VFX_FALSE);
    }
    else
    {
        if (m_nowPlaying->m_metaParser&& m_nowPlaying->m_metaParser->parseFile(m_filePath))
        {
            info = m_nowPlaying->getAudioInfo();
        }
        if (info && vfx_sys_wcslen(info->artist))
        {
            m_subtitle.loadFromMem(info->artist);
        }
    }
    m_nowPlaying->setInfoText(m_title, -1, m_subtitle);
}

VfxS32 VcuiMusicPlayerScreen::open(VfxWString &filePath)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_OPEN, &filePath);

    if (!m_filePath.isEmpty())
    {
        return m_ctrlPlayback->open(filePath);
    }
    else
    {
        return -1;
    }
} 
void VcuiMusicPlayerScreen::play()
{
    VfxBool isInterrupted = VFX_FALSE;
    VfxS32 ret = MUSIC_RET_OK;

    if (m_filePath.isEmpty())
    {
        return;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {        
        // Disable UI 
        m_nowPlaying->setEnablePlaybackUI(VFX_FALSE);

        // Inform user 
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());

        return;
     }

    isInterrupted = m_ctrlPlayback->getInterruptState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VCUI_SCREEN_PLAY, isInterrupted);
    
    if (isInterrupted)
    {
        /* play terminated by interrupt, user resume play. */
        ret = m_ctrlPlayback->resumeInterrupt(m_filePath);
    }
    else
    {
        ret = open(m_filePath);
        if (MUSIC_RET_OK == ret)
        {
            ret = m_ctrlPlayback->play();
        }
    }
    m_nowPlaying->checkSliderSeekable(PAGE_MODE_CUI);
    //play failed
    if ((MUSIC_RET_OK != ret)
        && (MUSIC_RET_ASYNC != ret))
    {
        //show error message
        VfxWString info;
        info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_PLAY);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)info.getBuf());
        return;
    }  
#if defined (__MMI_AVRCP_SUPPORT__)
    registerAVRCPcallback();
#endif
}

VappMusicPlayerNowPlayingPage* VcuiMusicPlayerScreen::getNowPlaying()
{
    return m_nowPlaying;
}

void VcuiMusicPlayerScreen::clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying)
{
    if (nowPlaying == m_nowPlaying)
    {
        m_nowPlaying = NULL;
    }
}
VappMusicPlayerCtrlPlaybackSlim* VcuiMusicPlayerScreen::getCtrlPlayback()
{
    return m_ctrlPlayback;
}
#if defined (__MMI_AVRCP_SUPPORT__)
U8 VcuiMusicPlayerScreen::onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events)
{
    /* only handle "down" events, don't handle \
       long-press, repeat, and up. */
    if (SRV_AVRCP_KEY_DOWN != key_events)
    {
        return SRV_AVRCP_CR_ACCEPT;
    }

    /* block operation when making call. */
    if (isMakingCall())
    {
        return SRV_AVRCP_CR_REJECT;
    }

    switch(command_type)
    {
        case SRV_AVRCP_POP_PLAY:
        case SRV_AVRCP_POP_PAUSE:
        {
            m_nowPlaying->playpause();
            return SRV_AVRCP_CR_ACCEPT;
        }
        case SRV_AVRCP_POP_STOP:
        {
            m_ctrlPlayback->stop();
            return SRV_AVRCP_CR_ACCEPT;
        }
        default:
            break;
    }

    return SRV_AVRCP_CR_NOT_IMPLEMENT;
}
void VcuiMusicPlayerScreen::registerAVRCPcallback()
{
    if(m_isSinglePlayer)
    {
        VappMusicPlayerSinglePlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerSinglePlayerApp);
        app->registerAVRCPcallback();
    }
    else
    {
        VcuiMusicPlayer *cui = VFX_OBJ_DYNAMIC_CAST(getParent(), VcuiMusicPlayer);
        cui->registerAVRCPcallbak();
    }
}
void VcuiMusicPlayerScreen::deregisterAVRCPcallback()
{
    if(m_isSinglePlayer)
    {
        VappMusicPlayerSinglePlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerSinglePlayerApp);
        app->deregisterAVRCPcallback();
    }
    else
    {
        VcuiMusicPlayer *cui = VFX_OBJ_DYNAMIC_CAST(getParent(), VcuiMusicPlayer);
        cui->deregisterAVRCPcallback();
    }
}
#endif //__MMI_AVRCP_SUPPORT__
VfxBool VcuiMusicPlayerScreen::isParentTopActive()
{
    if(m_isSinglePlayer)
    {
        VappMusicPlayerSinglePlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerSinglePlayerApp);
        return app->isGroupActive();
    }
    else
    {
        VcuiMusicPlayer *cui = VFX_OBJ_DYNAMIC_CAST(getParent(), VcuiMusicPlayer);
        return cui->isGroupActive();    
    }
}
#if defined(__MMI_NCENTER_SUPPORT__)
void VcuiMusicPlayerScreen::onNCenterStatusChanged(VappNCenterEventEnum evt)
{
    switch (evt)
    {
        case VAPP_NCENTER_EVENT_ENTERED:
        {
#ifdef __MMI_AVRCP_SUPPORT__
            deregisterAVRCPcallback();
#endif
            break;
        }  
        case VAPP_NCENTER_EVENT_EXITED:
        {
#ifdef __MMI_AVRCP_SUPPORT__
            registerAVRCPcallback();
#endif
            break;
        }         
        default:
            break;
    }
}
#endif

#endif /*__MMI_MUSIC_PLAYER_SLIM__*/
