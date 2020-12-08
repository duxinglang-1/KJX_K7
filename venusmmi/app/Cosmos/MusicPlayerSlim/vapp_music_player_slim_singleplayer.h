
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_SLIM_SINGLEPLAYER_H__
#define __VAPP_MUSIC_PLAYER_SLIM_SINGLEPLAYER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_ctrlplayback.h"
#include "vapp_music_player_slim_datatype.h"


/***************************************************************************** 
 * Enumeration
 *****************************************************************************/

typedef struct
{
    VfxWChar filePath[SRV_FMGR_PATH_MAX_LEN + 1];
    VfxWChar title[SRV_FMGR_PATH_MAX_LEN + 1];
}VappMusicPlayerSinglePlayerArgStruct;


/***************************************************************************** 
 * Music Player UI componet: Music player single player class
 *****************************************************************************/

class VappMusicPlayerSinglePlayerApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappMusicPlayerSinglePlayerApp);

public:
    VcuiMusicPlayerScreen *m_scr;

private:
    mmi_id m_cuiID;

public:
    VappMusicPlayerSinglePlayerApp()
    {};

// Override
public:
    virtual void onInit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual void onGroupActive(void);
    virtual void onGroupInactive(void);

// Public methods
public:
    mmi_id getCuiID()
    {
        return m_cuiID;
    };

    // Return the pointer of VappMusicPlayerNowPlayingPage
    VappMusicPlayerNowPlayingPage* getNowPlayingPage();
#if defined (__MMI_AVRCP_SUPPORT__)
	void registerAVRCPcallback();
	void deregisterAVRCPcallback();
	static U8 onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events);
#endif

// Protected methods
protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);
};


/***************************************************************************** 
 * Music Player UI componet: Music player single player screen
 *****************************************************************************/

class VappMusicPlayerSinglePlayerScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMusicPlayerSinglePlayerScreen);

public:
    VappMusicPlayerSinglePlayerScreen()
    {};

// Override
public:
    virtual mmi_ret onProc(mmi_event_struct *evt );

};


#endif /* __MMI_MUSIC_PLAYER_SLIM__ */

#endif //__COSMOS_MUSICPLY__
