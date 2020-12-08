/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_music_player_service.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Music Player ervice header
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_SERVICE_H__
#define __VAPP_MUSIC_PLAYER_SERVICE_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_include.h"
#include "vapp_music_player_ctrlplsv.h"
#include "vapp_music_player_ctrlplayback.h"

extern "C"
{
#include "PlstSrvGprot.h"
#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif
}

enum SrvDBStateEnum
{
    DB_CLOSE,               // 0
    DB_NORMAL,              // 1
    DB_SHRINK,              // 2
    DB_OPENING,             // 3
    DB_NONE                 // 4
};

/***************************************************************************** 
 * Music Player service component: VappMusicPlayerService class
 *****************************************************************************/

class VappMusicPlayerService : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerService);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappMusicPlayerService);

// Public member variables
public:
    // Signal for Open DB callback
    VfxSignal3 <srv_plst_cb_evt_enum, S32, VfxU32> m_signalPLSVCallback;

    // Signal on plsv handle changed
    VfxSignal1 <VfxS32> m_signalPLSVHandleChanged;

    // signal to notify prev / next button is pressed
    VfxSignal1 <VfxBool> m_signalOnPrevNext;

    // signal for MDI callback
    VfxSignal1 <VfxS32> m_signalMDICallback;
    
// Private member variables
private:
    // this pointer
    static VappMusicPlayerService *g_mplayerSrvPtr;

    // Memory pool
    VfxContext *m_context;

    // If service is closing
    VfxBool m_isDying;

// General UI
    VfxTimer *m_statusIconTimer;

    VfxBool m_memoryCardReady;

// PLSV variables
    // If DB is opened
    SrvDBStateEnum m_DBState;

    // PLSV handle
    VfxS32 m_plsvHandle;

    // Memory pool for PLSV
    void *m_memPtr;

    // ADM ID
    KAL_ADM_ID m_admID;
    
    ViewTypeEnum m_activeViewType;

    VfxU32 m_activeCount;

    SongInfoStruct m_activeInfo;

    srv_plst_media_details_struct m_activeDetailInfo;

    VfxS32 m_activePlayListID;
  
    srv_plst_repeat_enum m_repeatState;

    srv_plst_shuffle_enum m_shuffleState;

// Playback variables
    // Playback control
    VappMusicPlayerCtrlPlayback *m_ctrlPlayback;

    VfxTimer *m_delayPlayTimer;

    // this flag indicates that the find next timer is stopped on pen down, and should start it again on pen up
    VfxBool m_isFindNextTimerSuspended;

    VfxBool m_playAfterSwitchSong;

    VfxBool m_isDelayPlay;

    // this bool array is used to store the validation state of each song in active playlist
    // for first round playing, if the song is fail to play, set the state to VFX_FALSE and display error message
    // for second round, skip this song directly and display nothing
    // PS: only display error message in now playing page
    VfxU8 *m_activeListValidState;

    // active list state count
    VfxU32 m_activeListValidStateCount;

    // If the song need to show lyrics
    VfxU8 *m_activeListLyricsState;

    VfxTimer *m_playbackErrTimer;
    
// Constructor / destructor
public:
    VappMusicPlayerService():
      m_context(NULL),
      m_isDying(VFX_FALSE),
      m_statusIconTimer(NULL),
      m_memoryCardReady(VFX_FALSE),
      m_DBState(DB_CLOSE),
      m_plsvHandle(0),
      m_memPtr(NULL),
      m_admID(0),
      m_activeCount(0),
      m_activePlayListID(-1),
      m_ctrlPlayback(NULL),
      m_delayPlayTimer(NULL),
      m_isFindNextTimerSuspended(VFX_FALSE),
      m_playAfterSwitchSong(VFX_TRUE),
      m_isDelayPlay(VFX_FALSE),
      m_activeViewType(VIEW_TYPE_NONE),
      m_activeListValidState(NULL),
      m_activeListLyricsState(NULL),
      m_activeListValidStateCount(0),
      m_repeatState(SRV_PLST_REPEAT_OFF),
      m_shuffleState(SRV_PLST_SHUFFLE_OFF),
      m_playbackErrTimer(NULL)
    {};

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual vrt_allocator_handle getAllocator();
    virtual void onObjectNotify(VfxId id, void *userData);

// Functions
public:
    // close music player app, stop playback
    void closeMusicPlayer();

    VfxBool getIsDying();

// Event handling
public:
    // send EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE event
    void sendOpenCloseEvent(VfxBool isOpen);

    // send EVT_ID_VAPP_MUSICPLY_PLAY_START event and song info
    void sendPlayStartEvent(void);

    // send EVT_ID_VAPP_MUSICPLY_PLAY_START event when playback stop
    void sendPlayStopEvent(void);

    // handle onProc event
    static mmi_ret onProcCheckVolType(mmi_event_struct *param);

    // handle onProc event
    static mmi_ret onProcProfIsPlaying(mmi_event_struct *param);

#ifdef __MMI_USB_SUPPORT__
    // handle USB mass storage mode
    static mmi_ret onProcEnterUsbMsMode(mmi_event_struct *param);
#endif

// General UI
public:
    // show playing icon on status bar
    void showStatusBarIcon();

    // hide playing icon on status bar, 
    void hideStatusBarIcon(VfxBool delay = VFX_FALSE);

    // the button timer tick, hide the status bar play icon
    void onStatusIconTimerTick(VfxTimer *timer);

    // check if memory card is plugged in
    void checkMemoryCardReady();

    // return m_memoryCardReady
    VfxBool getMemoryCardReady();

// PLSV functions
public:
    // PLSV initialization
    void initPLSV();

    // return PLSV handle
    VfxS32 getPLSVHandle();

    // config default playlist
    void configDefaultPlaylist();

    // Cacnel open/reopen DB
    void openDBCancel();

    // Close DB
    void closeDB();

    // Reopen DB
    VfxS32 reopenDB(VfxBool isPlugIn);
    
    // Reallocate PLSV memory
    VfxBool reallocMemory(VfxBool shrink);

    // Get m_DBState
    SrvDBStateEnum getDBState();

    // Get if DB is ready
    VfxBool getDBIsReady();

    // Set m_DBState
    void setDBState(SrvDBStateEnum state);

    // send open DB ok and SrvHandle changed signals
    void signalOpenDBOK();

    // Get ID, srv only cares about active list
    VfxU32 getActiveListID(VfxU32 index);

    // Set active song, and keep active info
    VfxBool setActive(VfxU32 index, VfxBool updateDB = VFX_TRUE);
    
    // for Widget, del event from FMGR
    void getCurrInfo(SongInfoStruct &info, VfxBool query = VFX_FALSE);

    // for sending playback event & player page set info
    VfxBool getCurrDetailInfo(srv_plst_media_details_struct *infoStruct);

    // for widget
    void getAlbumCoverByDefaultBuffer(VfxU32 ID, VfxImageBuffer &imgBuf);

    void getAlbumCover(VfxU32 ID, VfxImageBuffer &imgBuf);

    VfxWString getActiveFilePath();

    void clearActiveFilePath();

    ViewTypeEnum getActiveViewType();

    VfxU32 getActiveCount();

    void updateActiveCount();

    VfxU32 getActiveIndex();
    
    void updateActiveIndex();

    VfxU32 getActiveID();

    void updateActiveID();

    VfxU32 getActivePlayListID();
    
    void setActivePlayListID(VfxS32 listID);

    void clearActivePlaylist();

    void setDuration(VfxU32 ID, VfxU32 duration);

    void setRepeat(srv_plst_repeat_enum repeatState);

    void setShuffle(srv_plst_shuffle_enum shuffleState);

    srv_plst_repeat_enum getRepeat();

    srv_plst_shuffle_enum getShuffle();

private:
    // DB initialization
    void initDB();

    static VfxS32 SrvPLSVCallback(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2);

    VfxS32 doSrvPLSVCallback(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2);

    VfxBool getAlbumCoverByID(VfxU32 ID, void *buffer, VfxU32 &bufferSize);

    VfxS32 prev(SongInfoStruct &info);

    VfxS32 next(SongInfoStruct &info, VfxBool delayUpdateIndex = VFX_FALSE);

    VfxS32 autoNext(SongInfoStruct &info);


// Playback functions
public:
    // Get ctrlPlayback
    VappMusicPlayerCtrlPlayback* getCtrlPlayback();

    // for playback
    
    // handle preivous event from player page
    void onPrev(VfxBool delayPlay = VFX_FALSE);
    
    // handle next event from player page
    void onNext(GetNextModeEnum nextMode = AUTO_NEXT, VfxBool delayPlay = VFX_FALSE);

    // Start playback
    void onPlay(VfxBool delayPlay);

    // Stop playback
    void onStop(VfxBool sendStopEvent = VFX_TRUE);

    VfxBool getIsDelayPlay();

    void startDelayPlayTimer();

    void stopDelayPlayTimer();

    VfxBool getIsDelayPlayTimerEnable();

    void setIsDelayPlay(VfxBool isDelayPlay);

    VfxBool getPlayAfterSwitchSong();

    void setPlayAfterSwitchSong(VfxBool isPlay);

    // initialize the bool array to store the validation state of each song of current playing playlist
    void initActiveListValidState();

    // free the validation state array
    void deinitActiveListValidState();

    // set the validation state of assigned song
    void setSongValid(const VfxU32 index, const VfxBool isValid);

    // get the validation state of assigned song
    VfxBool getSongValid(const VfxU32 index);

    // set the lyrics state of assigned song
    void setSongLyricsState(const VfxU32 index, const VfxBool isValid);

    // get the lyrics state of assigned song
    VfxBool getSongLyricsState(const VfxU32 index);

    // start find next timer
    void startFindNextTimer(void);

    // stop find next timer
    void stopFindNextTimer(void);

    // check if find next timer enabled
    VfxBool isFindNextTimerEnabled(void);

    VfxBool getIsFindNextTimerSuspended();

    void setIsFindNextTimerSuspended(VfxBool suspend);

    // handle some post process of onInvalidFile() by using plutommi timer
    static void findNextTimerTimeout(void);

    // playback error message timer
    void startPlaybackErrTimer();

    void stopPlaybackErrTimer();

    VfxBool getIsPlaybackErrTimerEnabled();


private:
    // Switch to prev/next song
    void onPrevNext(VfxBool isNext, GetNextModeEnum nextMode, VfxBool delayPlay);

    // Handle delay play
    void onDelayPlayTimerTick(VfxTimer *t);

    // playback state changed
    void onPlaybackStateChange(PlaybackStateEnum state);

    // handle MDI callback playback fail event
    void onPlaybackFail(VfxS32 result);

    // check if all songs in active are invalid. if so, stop the playback
    void onInvalidFile(VfxBool delayExecute = VFX_FALSE);

    // handle some post process of onInvalidFile()
    void handlePostOnInvalidFile(VfxTimer *timer);

    // MDI callback function
    void onMDICallback(VfxS32 result);

    // handle playback error timer timeout
    void onPlaybackErrTimerTick(VfxTimer *t);


// Helper functions
public:
    // check if is making call
    VfxBool isMakingCall();
    
    // check if in calling and popup warning balloon
    VfxBool blockActionInCall(VfxBool showMessage = VFX_TRUE);

    // check if current state is undeletable
    VfxBool isUndeletableState();

    // turn on back light
    void turnOnBackLight();

    // check if back light is on
    VfxBool isBackLightOn();

private:
    

// AVRCP fucntions
public:

private:
#ifdef __MMI_AVRCP_SUPPORT__
    // handle AVRCP commands (blue tooth remote)
    U8 onAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events);

    // for AVRCP events
    static U8 onAVRCPCmdCallback(U8 command_type, srv_avrcp_key_events key_events);
#endif /*__MMI_AVRCP_SUPPORT__*/


};

#endif /*   __VAPP_MUSIC_PLAYER_SERVICE_H__ */

#endif //__COSMOS_MUSICPLY__

