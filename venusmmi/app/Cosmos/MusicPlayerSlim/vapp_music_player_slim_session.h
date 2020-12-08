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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH´Ë
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
 *  vapp_music_player_slim_session.h
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_SESSION_H__
#define __VAPP_MUSIC_PLAYER_SESSION_H__


/*----------------------------------------------------------------------------------------
 header file
------------------------------------------------------------------------------------------*/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_slim_ctrlplaylist.h"
#include "vapp_music_player_slim_ctrlplayback.h"
#include "vapp_music_player_slim_dataDef.h"

extern "C"
{
#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif
}


#define SESSION_MAX_BITSET_SIZE        (SRV_PLAYLIST_MAX_PLAYLIST_ITEM / 8)
#define SESSION_DELAY_NEXT_TIME        (1500)
#define SESSION_DELAY_PLAY_TIME        (300)
#define SESSION_DELAY_OPEN_TIME        (100)
#define SESSION_ASYNC_TIME             (10)

#define ClrBitSet( index, bitset )     ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet( index, bitset )     ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn( index, bitset )    ((bitset)[(index)>>3] & (1<<((index)&0x07)))

/* session current operation, \
   also can be seen as AP operation, visiable to AP. */
typedef enum
{
    SESSION_ACT_OPEN,    /* opening the library. */
    SESSION_ACT_ADD,     /* adding file. */
    SESSION_ACT_DELETE,  /* deleting file. */
    SESSION_ACT_SEEKING,
    SESSION_ACT_NONE,    /* currently doing nothing, can transfer to any other states. */
    SESSION_ACT_MAX
}SessionActionEnum;

/* internal event, for async mode. */
typedef enum
{
    SESSION_EVT_DESTORY,  /* destory session self. */
    SESSION_EVT_MAX
}SessionEvtEnum;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxBool isOpen;
}VappMusicPlayerOpenCloseEvtStruct;

/*----------------------------------------------------------------------------------------
 para define
------------------------------------------------------------------------------------------*/
class VappMusicPlayerSession : public VfxObject
{
    //VFX_DECLARE_CLASS(VappMusicPlayerSession);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappMusicPlayerSession);

/* variables. */
private:

    VfxContext *m_context;  /* Memory pool for session class. */
    static VappMusicPlayerSession *g_mSessionPtr;  /* this pointer. */
    SessionActionEnum m_currOperation;  /* session current operation, visiable to AP. */

    VappMusicPlayerCtrlPlaybackSlim *m_ctrlPlayback;
    VappMusicPlayerCtrlPlaylist *m_ctrlPlaylist;
    
    VfxU8 m_songValidState[SESSION_MAX_BITSET_SIZE];
    VfxBool m_inBackground;      /* flag app in background run. */
    VfxBool m_inSeriesPlay;      /* flag if current in series play mode. */
    VfxBool m_switchingSong;     /* flag if in swithing song. */
    VfxBool m_btConnecting;      /* flag if in bt connecting. */

    VfxWString m_nextSongPath;   /* the next song's path for delay play. */
    VfxTimer *m_delayPlayTimer;  /* timer for delay start playback. */
    VfxTimer *m_delayNextTimer;  /* timer for delay switch next song. */
    VfxTimer *m_openLibTimer;    /* timer for delay open playllist file. */
 
    VfxSignal2 <SessionEvtEnum, VfxU32> m_signalInternalEvt; /* async Signal self. */

public:
    
    VfxSignal3 <MusicPlayCBEvtEnum, S32, VfxU32> m_signalSessionEvt; /* Signal for session. */


/* Constructor / destructor. */
public:
    VappMusicPlayerSession():
        m_currOperation(SESSION_ACT_MAX),
        m_ctrlPlayback(NULL),
        m_ctrlPlaylist(NULL),
        m_inBackground(VFX_FALSE),
        m_switchingSong(VFX_FALSE),
        m_btConnecting(VFX_FALSE),
        m_delayPlayTimer(NULL),
        m_delayNextTimer(NULL),
        m_openLibTimer(NULL)
    { };

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual vrt_allocator_handle getAllocator();
    virtual void onObjectNotify(VfxId id, void *userData);

private:
    
    void onPlaylistCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);
    void onPlaybackCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);

    void notifyEvtListener(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);
    void notifyEvtListenerAsync(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);

    void internalEvtHandler(SessionEvtEnum cb_event, VfxU32 cb_para);

    // handle USB mass storage mode
    static mmi_ret onProcUSBMsMode(mmi_event_struct *param);

    // handle onProc event
    static mmi_ret onProcProfIsPlaying(mmi_event_struct *param);
    
    // send EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE event when onDeinit
    void sendOpenCloseEvent(VfxBool isOpen);

    // show playing icon on status bar
    void showStatusBarIcon();

    // hide playing icon on status bar, 
    void hideStatusBarIcon();

    VfxS32 autoNext(VfxS32 &index, VfxBool delayNext, VfxU32 delayTime);

    /* set session operation, forbid other modules to set. */
    void setActionMode(SessionActionEnum action);

    void stopDelayPlay();
    void onDelayPlayTimerTick(VfxTimer *timer);
    void onDelayNextTimerTick(VfxTimer *timer);
    VfxS32 playMusic(const VfxWString &filePath, VfxBool delayStartPlay = VFX_FALSE);
    VfxS32 switchMusic(VfxS32 &index, VfxBool bNext);
    void onOpenLibTimerTick(VfxTimer *timer);
    VfxS32 resumeInterruptPlay(void);
    VfxBool isHasValidSong(void);

#ifdef __MMI_AVRCP_SUPPORT__
    void registerAVRCPcallbak(void);
    void deregisterAVRCPcallback(void);

    // for AVRCP events
    static U8 onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events);
#endif /*__MMI_AVRCP_SUPPORT__*/


/* Functions. */
public:

    // tell session if goto background, and read current play state
    void setBackgroundPlay(VfxBool inBgPlay, PlaybackStateEnum &playState);

    // close music player, stop playback
    void destorySession();

/* play list functions. */
public:

    VfxS32 openLibrary(VfxBool delayOpen = VFX_FALSE);
    
    /* Get current session operation. */
    SessionActionEnum getActionMode();
    PlaybackStateEnum getPlayState();
    PlaybackStateEnum getPlayStateBeforeSeek();

    /* add and delete file. */
    VfxS32 addMusic(VfxWString fileName);
    VfxS32 addMusicFromFolder(VfxWString folderName);
    VfxS32 addMusicCancel(void);
    VfxS32 delMusic(VfxU32 index);    
    VfxS32 delSelectedMusic(void);
    void delCancel(void);
    void delMultiSelectStart(void);
    void delMultiSelectEnd(void);
    void delSelectAll(void);
    void delDeselectAll(void); 
    void delSelectItem(VfxU32 index);
    void delDeselectItem(VfxU32 index);
    VfxBool delIsSelectedItem(VfxU32 index);

    /* for sending playback event & player page set info. */
    VfxS32 getActiveIndex(); 
    void setRepeat(srv_playlist_repeat_enum repeatState);
    void setShuffle(srv_playlist_shuffle_enum shuffleState);
    srv_playlist_repeat_enum getRepeat();
    srv_playlist_shuffle_enum getShuffle();
    VfxS32 getTitle(const VfxU32 index, VfxWString &title);
    VfxBool getPath(const VfxU32 index, VfxWString &path);
    VfxU32 getCount();

/* Playback functions. */
public:
    
    VfxS32 startPlay(VfxU32 index);  /* Start playback. */
    VfxS32 stopPlay();    /* Stop playback. */
    VfxS32 pauseResumePlay();
    VfxS32 switchNext(VfxS32 &index);  /* play next song. */
    VfxS32 switchPrev(VfxS32 &index);  /* play prev song. */
    VfxU32 getDuration();
    VfxU32 getCurrTime();
    VfxBool isSongPausable();
    VfxBool isSongSeekable();
    VfxS32 seekStart(VfxU32 time);
    VfxBool isBackLightOn();
    
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
    VfxU8 getEffectGroup(void);
    VfxU8 getEffectIndex(void);
    void setEffect(VfxU8 group, VfxU8 index);
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

/* Helper functions. */
private:
    VfxBool isMakingCall();
        
};


#endif  // __VAPP_MUSIC_PLAYER_SESSION_H__
#endif  // __MMI_MUSIC_PLAYER_SLIM__
