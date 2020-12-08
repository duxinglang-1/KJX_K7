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
 *  vapp_music_player_ctrlplayback.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player playback control
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
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_CTRL_PLAYBACK_H__
#define __VAPP_MUSIC_PLAYER_CTRL_PLAYBACK_H__

#include "vfx_mc_include.h"
#include "vapp_music_player_sound_setting.h"

extern "C"
{
#include "mdi_audio.h"
#include "BtAudioSrvGprot.h"
}

enum PlaybackStateEnum
{
    PB_STATE_NONE,                              // 0
    PB_STATE_CLOSE,                             // 1
    PB_STATE_OPEN,                              // 2
    PB_STATE_PLAYBACK_FAIL,                     // 3
    PB_STATE_PLAY,                              // 4
    PB_STATE_PAUSE,                             // 5
    PB_STATE_STOP,                              // 6
    PB_STATE_SWITCHING_PLAY,                    // 7
    PB_STATE_SWITCHING_NOT_PLAY,                // 8
    PB_STATE_SEEKING,                           // 9
    PB_STATE_INTERRUPTED,                       // 10

    PB_STATE_BT_CONNECTING,                     // 11
    PB_STATE_BT_CONNECTING_WHILE_PLAYING,       // 12
    PB_STATE_BT_CONNECTING_WHILE_RESUME,        // 13
    PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED    // 14
};

enum RepeatState
{
    REPEAT_NONE,
    REPEAT_SINGLE,
    REPEAT_ALL
};

typedef struct
{
    VfxBool isInterrupted;
    VfxU32 interruptedDuration;
    VfxU32 totalDuration;
    PlaybackStateEnum state;
} InterruptStruct;

#define VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT    3501
#define VAPP_MUSICPLY_INTERRUPT_CB_RESUME       3502

#define VAPP_MUSICPLY_PRE_END_OF_FILE       3506 /* Send result before end of file */
#define VAPP_MUSICPLY_EOF_ON_PLAY_REQ       3507 /* Return EOF on play request instead of callback */


/***************************************************************************** 
 * Music Player Playback Ctrl
 *****************************************************************************/

class VappMusicPlayerCtrlPlayback : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerCtrlPlayback);

// Variables
private:
    // MDI handle
    mdi_handle m_mdiHandle;

    // flag to indicate that the control is used by App or CUI
    VfxBool m_isAppMode;

    // current playback state
    PlaybackStateEnum m_playState;

    // memory block for MDI seeking
    U8 *m_cacheTable;

    // file path of current song
    VfxWString m_filePath;

    // file path of current cache
    VfxWString m_cacheFilePath;

    // duration of current song
    VfxU32 m_duration;

    // flag to indicate that the duration is updated to correct one
    VfxBool m_isPreciseDuration;

    // sound effect object
    VappMusicPlayerSoundEffect *m_ctrlSoundEffect;

    // BTAud service handle
    VfxU32 m_btaudHandle;

    // Flag to indicate if current playing song is pausable
    VfxBool m_isSongPausable;

    // Flag to indicate if current playing song is seekable
    VfxBool m_isSongSeekable;

    // flag to indicate if already registered interrupt callback
    VfxBool m_isRegsterIntrCallback;

    // flag to check if need to comsume DRM in this session
    VfxBool m_consumeDRM;

    // Keep sample rate for A2DP use
    VfxU16 m_sampleRate;

    // Keep stereo type for A2DP use
    VfxU8 m_stereo;

    // Flag to indicate if A2DP is opend by music player AP
    VfxBool m_isA2DPOpen;

public:
    // signal for playback state changed
    VfxSignal1 <PlaybackStateEnum> m_signalPlaybackStateChange;

    // signal for MDI callback
    VfxSignal1 <VfxS32> m_signalMDICallback;

    // info structure that contains interrupted flag and interrupted time
    InterruptStruct m_interruptInfo;

    // previous playback state before seek
    PlaybackStateEnum m_playStateBeforeSeek;
    
    // Time to seek (ms)
    VfxU32 m_seekTime;
    
    // flag to indicate the incoming interrupt callback is caused by Music Player
    VfxBool m_doTerminateBgPlay;

    // this pointer for APP
    static VappMusicPlayerCtrlPlayback *g_thisPtrForApp;

    // this pointer for CUI
    static VappMusicPlayerCtrlPlayback *g_thisPtrForCui;

    VfxSignal2 <VfxBool, VfxBool> m_signalShowHideWaitIcon;

// Constructor / Destructor
public:
    VappMusicPlayerCtrlPlayback():
      m_mdiHandle(0),
      m_isAppMode(VFX_TRUE),
      m_playState(PB_STATE_NONE),
      m_cacheTable(NULL),
      m_duration(0),
      m_isPreciseDuration(VFX_FALSE),
      m_ctrlSoundEffect(NULL),
      m_btaudHandle(0),
      m_isSongPausable(VFX_TRUE),
      m_isSongSeekable(VFX_TRUE),
      m_isRegsterIntrCallback(VFX_FALSE),
      m_doTerminateBgPlay(VFX_FALSE),
      m_seekTime(0),
      m_playStateBeforeSeek(PB_STATE_NONE),
      m_isA2DPOpen(VFX_FALSE)
      {};

// Public methods
public:
    // set the flag m_isAppMode
    void setIsAppMode(VfxBool isApp);

    // return MDI handle
    VfxS32 getHandle();

    // set MDI handle
    void setHandle(VfxS32 handle);

    // set playback state
    void setPlayState(PlaybackStateEnum state);

    // get playback state
    PlaybackStateEnum getPlayState();

    // Return TRUE for play button image, FALSE for pause
    VfxBool getPlayPauseState();

    // playback APIs
    void setConsumeDRM(VfxBool consume);
    VfxBool open(const VfxWString &filePath);
    void play();
    void doPlay();
    void resumeInterruptPlay();
    void pause();
    void resume();
    void doResume();
    void playpause();
    VfxBool seek(VfxU32 time);
    void seekStart(VfxU32 time);    //async seek
    void seekStop();
    void stop();
    void closeFile(VfxBool clearFilePath = VFX_TRUE);

    // clear seek time & play state before seek
    void clearSeekInfo();

    // check if current song pausable
    VfxBool isSongPausable(VfxWChar *filePath);

    // check if current song seekable
    VfxBool isSongSeekable(VfxWChar *filePath);

    // get file path of current song
    VfxWString getFilePath();

    // set file path of current song
    void setFilePath(VfxWString filePath);

    // clear file path
    void clearFilePath();

    // update current duration
    void updateDuration(VfxBool force_precise = VFX_FALSE);

    // update current file duration when player is not open
    void updateDurationByPath(const VfxWChar *filePath);

    // set current time to 0
    void resetDuration(void);

    // get duration
    VfxU32 getDuration();

    // get duration by filepath
    VfxU32 getDurationByPath(const VfxWChar *filePath);

    // get current play time
    VfxU32 getCurrTime();

    // set the m_isPreciseDuration flag to TRUE
    void setPreciseDuration();

    // register interrupt callback
    void registerInterruptCallback(VfxBool force_register = VFX_FALSE);

    // deregister interrupt callback
    void deregisterInterruptCallback();

	// register background callback
	void registerBackgroundCallback();
    
    // get sound effect object
    VappMusicPlayerSoundEffect* getCtrlSoundEffect();

    // get MDI error message
    VfxResId getMDIErrorMessage(mdi_result result);

    // terminate all background play
    void terminateBackgroundPlay();

    // check if background play callback registry is alive
    VfxBool isBackgroundPlayValid();

    // check if still has background callback registered
    VfxBool hasBackgroundCallback();

    // get interrupt info structure
    InterruptStruct getInterruptedInfo();

    // clear interrupt info
    void clearInterruptState(VfxBool keepInterrupt = VFX_FALSE, VfxBool keepState = VFX_FALSE);

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();

// Implementation
private:
    // initialize cache table
    void setCache(VfxBool reallocate);

    // free cache table
    void freeCache();

    // handle MDI EOF callback in timer
    void onEOFTimerExpir(VfxTimer *timer);

    // handle MDI callback
    static void onMDICallback(kal_int32 handle, kal_int32 result, void* user_data);

    // handle seek callback
    static void onSeekCallback(kal_uint8 reason, void* data);

    // handle MDI background interrupt callback
    static void onMDIInterruptCallback(mdi_result result, void *user_data);
    void doMDIInterruptCallback(mdi_result result);
    
    // handle MDI background resuem callback
    static VfxBool onMDIBackgroundCallback(mdi_result result, void *user_data);
    void doMDIBackgroundCallback(mdi_result result);

    // handle BT callback
    static void onBTOpenCallback(VfxS32 result);

    // open a2dp
    void openA2DP();
   
    // close A2DP and codec
    void closeA2DP(VfxBool notifyOpener = VFX_FALSE);

    // BTAud event handler
    static S32 BTAudEventHandler(BtAudEvent event, U32 arg, void *user_data);
};


#endif /*   __VAPP_MUSIC_PLAYER_CTRL_PLAYBACK_H__   */

#endif //__COSMOS_MUSICPLY__
