
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "vapp_music_player_slim.h"
#include "vapp_music_player_slim_singleplayer.h"
#include "vcui_music_player_gprot.h"
#include "mmi_rp_vapp_music_slim_single_player_def.h"
#include "GlobalResDef.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif

#include "FileMgrType.h"
#include "FileMgrResDef.h"
#include "UcmSrvGProt.h"
#include "AppMgrSrvGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static void* g_app_this_ptr = NULL;
/***************************************************************************** 
 * App Launcher
 *****************************************************************************/

// Launching function
extern "C" mmi_id vapp_music_player_singleplayer_launch(const WCHAR* filePath, const WCHAR* title)
{
    VappMusicPlayerSinglePlayerArgStruct *arg = NULL;

    VFX_SYS_ALLOC_MEM(arg, sizeof(VappMusicPlayerSinglePlayerArgStruct));
    VFX_ASSERT(arg);

    mmi_wcsncpy(arg->filePath, filePath, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_wcsncpy(arg->title, srv_fmgr_path_get_filename_const_ptr(filePath), SRV_FMGR_PATH_BUFFER_SIZE);

    mmi_id app_id = VfxAppLauncher::launch( 
                    VAPP_MUSIC_SLIM_SINGLE_PLAYER,
                    VFX_OBJ_CLASS_INFO(VappMusicPlayerSinglePlayerApp),
                    GRP_ID_ROOT,
                    (void*)(arg),
                    sizeof(VappMusicPlayerSinglePlayerArgStruct));
    VFX_SYS_FREE_MEM(arg);

    return app_id;
}

// For file manager file open
extern "C" void vapp_music_player_audio_option_open_handler(mmi_menu_id item_id, const WCHAR* filePath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    VfxApp *app = VfxAppLauncher::findApp(
                        VAPP_MUSIC_SLIM_SINGLE_PLAYER, 
                        VFX_OBJ_CLASS_INFO(VappMusicPlayerSinglePlayerApp), 
                        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG
                        );
    if(app)
    {
        // close other instance of single player to make sure there's only one single player exists at a time
        app->exit();
    }
    // allocate continuous option struct
    VappMusicPlayerSinglePlayerArgStruct *arg = NULL;
    VFX_SYS_ALLOC_MEM(arg, sizeof(VappMusicPlayerSinglePlayerArgStruct));
    VFX_ASSERT(arg);

    mmi_wcsncpy(arg->filePath, filePath, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_wcsncpy(arg->title, srv_fmgr_path_get_filename_const_ptr(filePath), SRV_FMGR_PATH_BUFFER_SIZE);

    VfxAppLauncher::launch(
                    VAPP_MUSIC_SLIM_SINGLE_PLAYER,
                    VFX_OBJ_CLASS_INFO(VappMusicPlayerSinglePlayerApp),
                    GRP_ID_ROOT,
                    (void*)(arg),
                    sizeof(VappMusicPlayerSinglePlayerArgStruct));
    VFX_SYS_FREE_MEM(arg);
}

/***************************************************************************** 
 * VappMusicPlayerSinglePlayerApp Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSinglePlayerApp", VappMusicPlayerSinglePlayerApp, VfxApp);

void VappMusicPlayerSinglePlayerApp::onInit()
{
    VfxApp::onInit();

    /*Register event handler when APP running */
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
#endif
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_TRUE);
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_PROF_IS_PLAYING, VFX_TRUE);
}
void VappMusicPlayerSinglePlayerApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    
    //set this ptr when app run
    g_app_this_ptr = this;
    
    VFX_OBJ_CREATE_EX(m_scr, VcuiMusicPlayerScreen, this, (VFX_TRUE));
    m_scr->parseFilePath(args, argSize);
    m_scr->show();    
}

void VappMusicPlayerSinglePlayerApp::onDeinit()
{
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
#endif
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_FALSE);
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_PROF_IS_PLAYING, VFX_FALSE);
#if defined (__MMI_AVRCP_SUPPORT__)
    deregisterAVRCPcallback();
#endif
    VfxApp::onDeinit();
}

void VappMusicPlayerSinglePlayerApp::onGroupActive(void)
{

}
void VappMusicPlayerSinglePlayerApp::onGroupInactive(void)
{
    if(getNowPlayingPage() != NULL)
    {
        getNowPlayingPage()->closeMetaParser();
    }
}
mmi_ret VappMusicPlayerSinglePlayerApp::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SINGLEPLAYER_AP_ON_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            exit();
            return MMI_RET_OK; 
        }
    #endif
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
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            exit();
            return MMI_RET_OK;
        }
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            VappMusicPlayerNowPlayingPage* nowPlayingPage = getNowPlayingPage();
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
            default:
            break;
    }
    return VfxApp::onProc(evt);
}

VappMusicPlayerNowPlayingPage* VappMusicPlayerSinglePlayerApp::getNowPlayingPage()
{
    VappMusicPlayerNowPlayingPage* nowPlayingPage = NULL;
    if((m_scr != NULL) && !m_scr->m_screenClosing)
    {
        nowPlayingPage = m_scr->getNowPlaying();
    }
    
    return nowPlayingPage;
}
#if defined (__MMI_AVRCP_SUPPORT__)
void VappMusicPlayerSinglePlayerApp::registerAVRCPcallback()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SINGLEPLAYER_AP_REGISTER_AVRCP);
    srv_avrcp_set_cmd_hdlr(onAVRCPCmdCallback);
}
void VappMusicPlayerSinglePlayerApp::deregisterAVRCPcallback()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SINGLEPLAYER_AP_DEREGISTER_AVRCP);
    srv_avrcp_clear_cmd_hdlr(onAVRCPCmdCallback);
}
U8 VappMusicPlayerSinglePlayerApp::onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SINGLEPLAYER_AP_ON_AVRCP_CALLBACK);
    VappMusicPlayerSinglePlayerApp *app = reinterpret_cast<VappMusicPlayerSinglePlayerApp*>(g_app_this_ptr);
    VFX_ASSERT(app);
    // Only act AVRCP command for active screen
    if (!app->isGroupActive())
    {
        return SRV_AVRCP_CR_ACCEPT;
    } 
    VappMusicPlayerNowPlayingPage* nowPlaying = app->getNowPlayingPage();
    VFX_ASSERT(nowPlaying);
    return app->m_scr->onAVRCPCmdCallback(command_type, key_events);
}
#endif //__MMI_AVRCP_SUPPORT__
#endif //__MMI_MUSIC_PLAYER_SLIM__