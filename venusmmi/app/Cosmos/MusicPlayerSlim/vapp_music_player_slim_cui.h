

#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_CUI_H__
#define __VAPP_MUSIC_PLAYER_CUI_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_Form.h"
#include "vcp_list_menu.h"
#include "GlobalResDef.h"
#include "vapp_music_player_slim_nowplaying.h"
#if defined(__MMI_NCENTER_SUPPORT__)
#include "vapp_ncenter.h"
#endif

extern "C"
{
#include "AvrcpSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class VcuiSoundRecorder
 *****************************************************************************/
class VcuiMusicPlayerScreen;
class VappMusicPlayerNowPlayingPage;

class VcuiMusicPlayer : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiMusicPlayer);

public:
    VfxBool m_screenClosing;
    mmi_id m_cuiId;
    VcuiMusicPlayerScreen *m_scr;

public:
    VcuiMusicPlayer():
      m_screenClosing(VFX_FALSE),
      m_cuiId(GRP_ID_INVALID),
      m_scr(NULL)
    {};
    
// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual void onGroupActive(void);
    virtual void onGroupInactive(void);
    virtual mmi_ret onProc(mmi_event_struct *evt);

public:
    // Set title and subtitle string, subtitle is on the above
    void setTitle(VfxWString str1, VfxWString str2);
	void notifyCaller();
	VappMusicPlayerNowPlayingPage* getNowPlayingPage();
	void clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying);
#if defined (__MMI_AVRCP_SUPPORT__)
	void registerAVRCPcallbak();
	void deregisterAVRCPcallback();
	static U8 onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events);
#endif
};


/***************************************************************************** 
 * Class VcuiSoundRecorderScreen
 *****************************************************************************/
class VcuiMusicPlayerScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiMusicPlayerScreen);
	
public:
    VfxBool m_screenClosing;
	VfxBool m_isSinglePlayer;
    VfxWString m_filePath;
	
private:
    //VfxBool m_firstEnter;
    VfxWString m_title;
    VfxWString m_subtitle;
	VappMusicPlayerNowPlayingPage *m_nowPlaying;
	VappMusicPlayerCtrlPlaybackSlim *m_ctrlPlayback;
	VcpActivityIndicator *m_waitIcon;
	VfxWeakPtr<VfxTimer> m_waitIconTimer;

public:
    VcuiMusicPlayerScreen():
	  m_screenClosing(VFX_FALSE),
	  m_nowPlaying(NULL),
	  m_ctrlPlayback(NULL),
	  m_waitIcon(NULL)
    {};
	  
	VcuiMusicPlayerScreen(VfxBool isSingle):
    m_screenClosing(VFX_FALSE),
	m_isSinglePlayer(isSingle),
	m_nowPlaying(NULL),
	m_ctrlPlayback(NULL),
	m_waitIcon(NULL)
	{};

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void on1stReady();
    virtual void on2ndReady();    

public:

	void parseFilePath(void *args, VfxU32 argSize);
	VfxWString getFilePath();
    void setFilePath(VfxWString &filePath);
    void setTitle(VfxWString &title, VfxWString &subtitle);
    VfxS32 open(VfxWString &filePath);
    void play();
    void showWaitIcon(VfxBool delayShow = VFX_FALSE);
	void doShowWaitIcon(VfxTimer *timer);
	void hideWaitIcon();
    VappMusicPlayerNowPlayingPage* getNowPlaying();
	void clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying);
	VappMusicPlayerCtrlPlaybackSlim* getCtrlPlayback();
#if defined (__MMI_AVRCP_SUPPORT__)
	void registerAVRCPcallback();
	void deregisterAVRCPcallback();
	U8 onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events);
#endif //__MMI_AVRCP_SUPPORT__
    VfxBool isParentTopActive();
#if defined(__MMI_NCENTER_SUPPORT__)
	// Handle NCenter events
	void onNCenterStatusChanged(VappNCenterEventEnum evt);
#endif
};

#endif /* __VAPP_MUSIC_PLAYER_CUI_H__ */

#endif /*__MMI_MUSIC_PLAYER_SLIM__*/
