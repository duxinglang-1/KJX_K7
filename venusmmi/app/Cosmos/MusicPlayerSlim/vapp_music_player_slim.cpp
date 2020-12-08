
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vfx_config.h"

#include "vapp_music_player_slim.h"
#include "GlobalResDef.h"
#include "NotificationGProt.h"
#include "mmi_rp_vapp_music_player_slim_def.h"
#include "mmi_rp_app_cosmos_global_def.h" // For cosmos theme color
#include "vapp_screen_lock_gprot.h"
#include "vfx_adp_device.h"
#include "vapp_music_player_slim_util.h"
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include "Gdi_include.h"
#include "aud_defs.h"
#include "med_main.h"
#include "vapp_ncenter_gprot.h"
#include "AppMgrSrvGProt.h"
#include "ShutdownSrvGprot.h"
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#ifdef __cplusplus
}
#endif

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(__MTK_TARGET__) && defined(__MAUI_SOFTWARE_LA__)
#ifdef __cplusplus
extern "C"
{
#endif
#include "SST_sla.h"
#ifdef __cplusplus
}
#endif
#define SWLA_BEGIN(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define SWLA_END(_symbol_) SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define SWLA_BEGIN(_symbol_)
#define SWLA_END(_symbol_)
#endif

/***************************************************************************** 
 * App Launcher
 *****************************************************************************/

// Lauching function

extern "C" mmi_id vapp_music_player_slim_launch_app(void *param)
{
#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return GRP_ID_INVALID;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    VfxApp *app = VfxAppLauncher::findApp(VAPP_MUSIC_PLAYER_SLIM, VFX_OBJ_CLASS_INFO(VappMusicPlayerAppSlim), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if(app)
    {
        VFX_ASSERT(0);
    }
    else
    {
        VfxAppLauncherParam p(VAPP_MUSIC_PLAYER_SLIM, VFX_OBJ_CLASS_INFO(VappMusicPlayerAppSlim), GRP_ID_ROOT);
        p.setArgument(param, sizeof(VfxBool*));
        return VfxAppLauncher::launchEx(p); 
    }
    return GRP_ID_INVALID;
}

// From main menu
extern "C" MMI_ID vapp_music_player_slim_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = 0;

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_music_player_slim_launch_app(param);
    }
    return app_id;
}

/***************************************************************************** 
 * VappMusicPlayerApp Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerAppSlim", VappMusicPlayerAppSlim, VfxApp);

void VappMusicPlayerAppSlim::onRun(void * args, VfxU32 argSize)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_RUN);

    VfxApp::onRun(args, argSize);
    initStage();
}

void VappMusicPlayerAppSlim::onDeinit()
{   
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_DEINIT);

    // need to set backgroundplay
    PlaybackStateEnum playState;
    m_session->setBackgroundPlay(VFX_TRUE, playState);

    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_FALSE);
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_FALSE);

    //for ncenter still leave when close music player cell
    vapp_ncenter_disable_leave();

    VfxApp::onDeinit();
}
mmi_ret VappMusicPlayerAppSlim::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_PROC, evt->evt_id);

    switch(evt->evt_id)
    {
        case EVT_ID_VCUI_FMGR_MEDIA_PICKER_RESULT:
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
            //fmgr cui event and screen lock event notify to allsong page
            notifyTopPage(evt);
            break;
        }
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            onProcUcmStatusChange();
            return MMI_RET_OK;
        }
        default:
            break;
    }
    return VfxApp::onProc(evt);
}
void VappMusicPlayerAppSlim::onProcUcmStatusChange()
{
    VfxBool makingCall = isMakingCall();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_PROC_UCM_STATUS_CHANGE_MAKING_CALL_D, makingCall);

    if(makingCall)
    {
        if (m_nowPlaying)
        {
            m_nowPlaying->setEnablePlaybackUI(VFX_FALSE);
        }
    }
}
void VappMusicPlayerAppSlim::onGroupActive(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_GROUP_ACTIVE);
}

void VappMusicPlayerAppSlim::onGroupInactive(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_GROUP_INACTIVE);

    //close metaparser in inactive state
    if (m_nowPlaying)
    {
        m_nowPlaying->closeMetaParser();
    }
}
void VappMusicPlayerAppSlim::initStage(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_INIT_STAGE);

    m_session = getMusicPlayerSession();
    m_session->m_signalSessionEvt.connect(this, &VappMusicPlayerAppSlim::onSessionCallback);

    VFX_OBJ_CREATE(m_screen, VappMusicPlayerSlimScreen, this);
    m_screen->show();
    m_nowPlaying = m_screen->getNowPlayingPtr();

    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_TRUE);
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_TRUE);
}
void VappMusicPlayerAppSlim::notifyTopPage(mmi_event_struct *evt)
{
    if (m_screen)
    {
        VfxPage *topPage = m_screen->getPage(0);
        if(topPage)
        {
            topPage->processProc(evt);
        }
    }
}
void VappMusicPlayerAppSlim::sendShowHideEvent(VfxBool isShow)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_SEND_SHOW_HIDE_EVENT, isShow);

    // send APP show/hide event
    VappMusicPlayerShowHideEvtStruct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MUSICPLY_SHOW_HIDE);
    evt.isShow = isShow;
        
    MMI_FRM_CB_EMIT_EVENT(&evt);
}
void VappMusicPlayerAppSlim::onSessionCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_APP_ON_SESSION_CALLBACK, cb_event, result, ca_para_2);

     switch (cb_event)
    {       
        case MUSIC_CB_USB_MS_MODE:
        {
            if(m_session)
            {
                m_session->destorySession();
            }
            exit();
            break;
        }
        default:
            break;
    }
}

/***************************************************************************** 
 * VappMusicPlayerScreen Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSlimScreen", VappMusicPlayerSlimScreen, VfxMainScr);

void VappMusicPlayerSlimScreen::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_ON_INIT);

    VfxMainScr::onInit();

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerAppSlim);

    if(!m_app)
    {
        return;
    }
}
void VappMusicPlayerSlimScreen::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_ON_DEINIT);

    VfxMainScr::onDeinit();
}
void VappMusicPlayerSlimScreen::on1stReady()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_ON_1ST_READY);

    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(m_nowPlaying, VappMusicPlayerNowPlayingPage, this);
    pushPage(PAGE_ID_NOW_PLAYING, m_nowPlaying); 
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
}
void VappMusicPlayerSlimScreen::showWaitIcon(VfxBool delayShow)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_SHOW_WAITICON, delayShow);

    if (delayShow)
    {
        return;
    }
    else
    {
            doShowWaitIcon();    
        }
}
void VappMusicPlayerSlimScreen::doShowWaitIcon()
{
    if (!m_waitIcon)
    {
    VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
    m_waitIcon->setAnchor(0.5, 0.5);
    m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
    m_waitIcon->stop();
    m_waitIcon->setAutoAnimate(VFX_FALSE);
    m_waitIcon->setPos(GDI_LCD_WIDTH/2, (GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT)/2);    
    }
    m_waitIcon->bringToFront();
    m_waitIcon->setHidden(VFX_FALSE);
    m_waitIcon->start();
}
void VappMusicPlayerSlimScreen::hideWaitIcon()
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_HIDE_WAITICON);

        if (m_waitIcon)
        {
            if (m_waitIcon->isAnimating())
            {
                m_waitIcon->stop();
                m_waitIcon->setHidden(VFX_TRUE);
                m_waitIcon->sendToBack();
            }
        }
}
VappMusicPlayerAppSlim *VappMusicPlayerSlimScreen::getMusicPlayerSlimApp()
{
    return m_app;
}
void VappMusicPlayerSlimScreen::popupConfirmClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_CONFIRM_CLOSE);

    if (m_popupConfirm)
    {
        m_popupConfirm->exit(VFX_TRUE);
        m_popupConfirm = NULL;
    }
}
void VappMusicPlayerSlimScreen::popupConfirm(
                            VfxWString strHint, 
                            VfxWString strBtn, 
                            VcpPopupTypeEnum popupType, 
                            VcpConfirmPopupButtonSetEnum buttonSet, 
                            VcpPopupButtonTypeEnum buttonType)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_POPUP_CONFIRM);

    VFX_OBJ_CREATE(m_popupConfirm, VcpConfirmPopup, this);
    m_popupConfirm->setInfoType(popupType);
    m_popupConfirm->setText(strHint);
    m_popupConfirm->setButtonSet(buttonSet);
    if (buttonSet == VCP_CONFIRM_BUTTON_SET_USER_DEFINE)
    {
        m_popupConfirm->setCustomButton(strBtn , VFX_WSTR_RES(STR_GLOBAL_CANCEL), buttonType, VCP_POPUP_BUTTON_TYPE_CANCEL);
    }
    m_popupConfirm->show(VFX_TRUE);
    m_popupConfirm->m_signalButtonClicked.connect(this, &VappMusicPlayerSlimScreen::eventHandler);
    m_popupConfirm->setAutoDestory(VFX_TRUE);
}
void VappMusicPlayerSlimScreen::eventHandler(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SCREEN_EVENT_HANDLER, id);

    switch(id)
    {
        // handle playlist open error popup close session and app
        case VCP_CONFIRM_POPUP_BUTTON_OK:
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VappMusicPlayerSession *m_session = getMusicPlayerSession();
            if(m_session)
            {
                m_session->destorySession();
            }
            if(m_app)
            {
                m_app->exit();
            }
            break;
        }
    }
}
VappMusicPlayerNowPlayingPage *VappMusicPlayerSlimScreen::getNowPlayingPtr()
{
    return m_nowPlaying;
}
void VappMusicPlayerSlimScreen::clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying)
{
    if(nowPlaying == m_nowPlaying)
    {
        m_nowPlaying = NULL;
    }
}

#endif /*__MMI_MUSIC_PLAYER_SLIM__*/
