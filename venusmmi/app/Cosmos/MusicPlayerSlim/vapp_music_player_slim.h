
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__


#ifndef __VAPP_MUSIC_PLAYER_SLIM_H__
#define __VAPP_MUSIC_PLAYER_SLIM_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vapp_music_player_slim_session.h"
#include "vapp_music_player_slim_datatype.h"
#include "vapp_music_player_slim_allsong.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_music_player_slim_nowplaying.h"


/***************************************************************************** 
 * Enumeration
 *****************************************************************************/
enum
{
    FUNC_ID_START = 1000,

    // Command toolbar
    FUNC_ID_TB_BTN_ADD_SONGS,           // 1002
    FUNC_ID_TB_BTN_REMOVE,               // 1003

    // Confirm toolbar
    FUNC_ID_TB_BTN_OK,                  // 1004
    FUNC_ID_TB_BTN_CANCEL,              // 10
    FUNC_ID_TB_BTN_SELECT_ALL,          // 10

    // Context menu item
    FUNC_ID_CM_REMOVE,                  // 10
    FUNC_ID_CM_CANCEL,                  // 10

    // Setting
    FUNC_ID_GO_TO_SOUND_EFFECT,         // 10
    FUNC_ID_SOUND_LYRICS_CLOSE,         // 10

    FUNC_ID_END
};
typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxBool isShow;
}VappMusicPlayerShowHideEvtStruct;


#ifdef __COSMOS_MUSICPLY_SOUND_SETTING__

#endif
#define MUSICPLY_PLST_NAME_MAX_LENGTH 40

/***************************************************************************** 
 * Music Player UI componet: Music player app class
 *****************************************************************************/

    class VappMusicPlayerSlimScreen ;
    class VappMusicPlayerAllSongsPage;
    class VappMusicPlayerNowPlayingPage;
    
    class VappMusicPlayerAppSlim : public VfxApp
    {
        VFX_DECLARE_CLASS(VappMusicPlayerAppSlim);
        
    friend class VappMusicPlayerAllSongsPage;
            
private:
    VappMusicPlayerSession *m_session;
    VappMusicPlayerSlimScreen *m_screen;
    VappMusicPlayerNowPlayingPage *m_nowPlaying;
public:
    VappMusicPlayerAppSlim() :
        m_session(NULL),
        m_screen(NULL),
        m_nowPlaying(NULL)
    {};

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onGroupActive(void);
    virtual void onGroupInactive(void);
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    void notifyTopPage(mmi_event_struct *evt);

public:
    void onProcUcmStatusChange();
    void sendShowHideEvent(VfxBool isShow);
    void onSessionCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);
    void initStage();
    };


/***************************************************************************** 
 * Music Player UI componet: Music player screen class
 *****************************************************************************/

class VappMusicPlayerSlimScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMusicPlayerSlimScreen);
    
public:
    VappMusicPlayerAllSongsPage *m_allsong;
    VappMusicPlayerAppSlim* m_app;
    VcpActivityIndicator *m_waitIcon;  
    VappMusicPlayerNowPlayingPage *m_nowPlaying;
    VcpConfirmPopup *m_popupConfirm;

public:
        VappMusicPlayerSlimScreen():
            m_allsong(NULL),
            m_app(NULL),
            m_waitIcon(NULL),
            m_nowPlaying(NULL),
            m_popupConfirm(NULL)
        {
#ifdef LOW_COST_SUPPORT
            setAppContextShareForVrt(VFX_TRUE);
#endif
        };

private:
    virtual void onInit();
    virtual void onDeinit();
    virtual void on1stReady();
    
public:
    void showWaitIcon(VfxBool delayShow = VFX_FALSE);
    void doShowWaitIcon();
    void hideWaitIcon();
    VappMusicPlayerAppSlim *getMusicPlayerSlimApp();
    void popupConfirmClose();
    void popupConfirm(
                                VfxWString strHint, 
                                VfxWString strBtn, 
                                VcpPopupTypeEnum popupType, 
                                VcpConfirmPopupButtonSetEnum buttonSet, 
                                VcpPopupButtonTypeEnum buttonType);
    void eventHandler(VfxObject* sender, VfxId id);
	VappMusicPlayerNowPlayingPage *getNowPlayingPtr();
	void clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying);

};

#endif  //__VAPP_MUSIC_PLAYER_SLIM_H__
#endif /*__MMI_MUSIC_PLAYER_SLIM__*/

