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
 *  vapp_music_player_slim_ctrlplaylist.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include header file
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_CTRL_PLAYBACK_H__
#define __VAPP_MUSIC_PLAYER_CTRL_PLAYBACK_H__

#include "vfx_mc_include.h"
#include "vapp_music_player_slim_dataDef.h"

extern "C"
{
#include "mdi_audio.h"
#include "BtAudioSrvGprot.h"

#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif
}

/* max playback object supported: app & CUI. */
#define MAX_PLAYBACK_OBJECT         (3)

/* play state or operation */
typedef enum
{
    PB_STATE_PLAY,      /* playing. */
    PB_STATE_PAUSE,     /* play pause */
    PB_STATE_STOP,      /* play stopped. */
    PB_STATE_SEEKING,   /* seeking. */
    PB_STATE_NONE,      /* init state. */
} PlaybackStateEnum;

#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
typedef enum
{
    SOUND_EFFECTS_NONE,
#ifdef __MMI_AUDIO_EQUALIZER__
    SOUND_EFFECTS_EQ,
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    SOUND_EFFECTS_SURROUND,
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    SOUND_EFFECTS_REVERB,
#endif
    SOUND_EFFECTS_TOTAL
}SoundEffectEnum;
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

/* keep the interrupted play info. */
typedef struct
{
    VfxBool isInterrupted;      /* interrupted flag. */
    VfxWString interruptFile;   /* playing file when interrupt. */
    VfxU32 interruptedDuration; /* current playing time when interrupt. */
    VfxU32 totalDuration;       /* total time. */
    PlaybackStateEnum state;    /* play back state when interrupt. */
} InterruptInfoStruct;

/* keep current playing file info. */
typedef struct
{
    VfxWString m_currFilePath;  /* file path of current song. */
    VfxBool m_isSongPausable;   /* flag to indicate if song is pausable. */
    VfxBool m_isSongSeekable;   /* flag to indicate if song is seekable. */
    VfxU32 m_duration;          /* duration of current song. */
    VfxU16 m_sampleRate;        /* Keep sample rate for A2DP use. */
    VfxU8 m_stereo;             /* Keep stereo type for A2DP use. */
} FileInfoStruct;

/* keep the playing info before seek. */
typedef struct
{
    VfxBool isNeedSeek;         /* if need to start seek before play. */
    VfxWString seekFile;        /* playing file when interrupt. */
    VfxU32 seekTime;            /* seeking to time. */
    PlaybackStateEnum state;    /* play back state before seek. */
} SeekInfoStruct;

/*----------------------------------------------------------------------------------------
 para define
------------------------------------------------------------------------------------------*/
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
class VappMusicPlayerSoundEffectAdapt;
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

class VappMusicPlayerCtrlPlaybackSlim : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerCtrlPlaybackSlim);

/* variables. */
private:

    mdi_handle m_mdiHandle;                   /* MDI handle created when open, set NULL when close . */
    VfxU32 m_btaudHandle;                     /* BTAud service handle. */

#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
    VappMusicPlayerSoundEffectAdapt *m_soundEffectAdpt;
#endif

    PlaybackStateEnum m_playbackState;
    FileInfoStruct m_currFileInfo;            /* current playing music info. */
    InterruptInfoStruct m_interruptInfo;      /* interrupted play info. */
    SeekInfoStruct m_seekingInfo;             /* play back info befor seeking. */

    U8 *m_cacheTable;                         /* memory block for MDI seeking. */
    VfxWString m_cacheFilePath;               /* file path of current cache. */     

    VfxBool m_consumeDRM;                     /* flag if need to consume DRM for DRM file. */
    VfxBool m_isRegInterrupt;                 /* flag if interrupt call bcak has been registered. */
    VfxBool m_isA2DPOpen;                     /* flag if A2DP opened. */
    VfxBool m_inBackground;                   /* flag if current in background. */

    static VfxU32 m_objReg[MAX_PLAYBACK_OBJECT];  /* playback object reg. */

public:

    VfxSignal3 <MusicPlayCBEvtEnum, S32, VfxU32> m_signalCtrlPlayback; /* Signal for ctrl-playback callback. */

/* constractor & destructor. */
public:

    VappMusicPlayerCtrlPlaybackSlim():
        m_mdiHandle(0),
        m_btaudHandle(0),
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
        m_soundEffectAdpt(NULL),
#endif
        m_playbackState(PB_STATE_NONE),
        m_cacheTable(NULL),
        m_consumeDRM(VFX_TRUE),
        m_isRegInterrupt(VFX_FALSE),
        m_isA2DPOpen(VFX_FALSE),
        m_inBackground(VFX_FALSE)
    { };

/* Override methods. */
protected:
    virtual void onInit();
    virtual void onDeinit();

/* Implementation. */
private:
    void saveObject();
    void freeObject();

    void setPlaybackState(PlaybackStateEnum state);

    void registerInterruptCallback(void);
    void deregisterInterruptCallback(void);
    void registerBckgrounCallback(void);
    void deregisterBckgrounCallback();
   
    void setCache(const VfxWString filePath);  /* initialize cache table. */
    void freeCache();  /* free cache table. */

    /* handle volume change event. */
    static mmi_ret onProcCheckVolType(mmi_event_struct *param);

    /* handle MDI callback. */
    static void onMDICallback(kal_int32 handle, kal_int32 result, void* user_data);

    /* handle seek callback. */
    static void onSeekCallback(kal_uint8 reason, void* user_data);

    /* handle MDI background interrupt callback. */
    static void onMDIInterruptCallback(mdi_result result, void *user_data);
    
    /* handle MDI background resuem callback */
    static VfxBool onMDIBackgroundCallback(mdi_result result, void *user_data);

    void doPlay();
    void doResume();
    void getAudioInfo(const VfxWString &filePath);
    void cleanCurrFileInfo();
    void cleanInterruptInfo();
    void cleanSeekInfo();
    void updateAudDuration(VfxBool isPrecise);

    VfxBool isMakingCall();
    void turnOnSoundEffect(VfxBool turnOn);

#if defined (__MMI_A2DP_SUPPORT__)
    void openA2DP();  /* open a2dp. */
    void closeA2DP();
    static void onA2DPOpenCallback(VfxS32 result);  /* handle BT callback. */
    void openBTAud();
    void closeBTAud();
    static S32 onBTAudEventCallback(BtAudEvent event, U32 arg, void *user_data);  /* BTAud event handler. */
#endif  //(__MMI_A2DP_SUPPORT__)

/* Public methods. */
public:

    void setBackgroundPlay(VfxBool gotoBg);
    PlaybackStateEnum getPlaybackState();      /* get playback state. */
    PlaybackStateEnum getPBStateBeforeSeek();  /* get play back state before seeking. */
    VfxBool getInterruptState();               /* check if current play be interrupted. */
    void notifyEvtListener(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);

    // playback APIs
    VfxS32 open(const VfxWString &filePath);  /* open input music file. */
    VfxS32 play();                            /* playing current opened music. */
    VfxS32 pause();                           /* pause current playing music. */
    VfxS32 resume();                          /* resume current paused music. */
    void stop();                              /* stop current music. */
    void close();                             /* close current music file. */
    VfxS32 setStartTime(VfxU32 time);         /* set input time as play start time. */
    VfxS32 seekStart(VfxU32 time);            /* async seek. */
    void seekStop(VfxBool pauseSeek = VFX_FALSE);  /* stop current seeking operation. */
    
    VfxS32 resumeInterrupt(const VfxWString &filePath); /* resume play when interrupt. */

    VfxBool isSongPausable();                 /* check if current song pausable. */
    VfxBool isSongSeekable();                 /* check if current song seekable. */

    // get estmate duration
    VfxU32 getDuration(const VfxWString filePath);
    VfxU32 getDurationByPath(const VfxWString filePath);

    // get current play time
    VfxU32 getCurrTime();
    void songSwitched(const VfxWString filePath);
    void interruptEvtHandler(MusicPlayCBEvtEnum evt, VfxS32 para);

    // get MDI error message
    VfxResId getMDIErrorMessage(mdi_result result);
    
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
    void enableSoundEffect(VfxBool enableSoundEffect);
    VfxU8 getEffectGroup(void);
    VfxU8 getEffectIndex(void);
    void setEffect(VfxU8 group, VfxU8 index);
#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
};


/***************************************************************************** 
 * Music Player Control componet: VappMusicPlayerSoundEffectAdapt class
 *****************************************************************************/
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
class VappMusicPlayerSoundEffectAdapt : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerSoundEffectAdapt);

private:
    VfxU8 m_effectType;
    VfxU8 m_effectIndex;
    VfxBool m_isEffectOn;

public:
    VappMusicPlayerSoundEffectAdapt();
    virtual ~VappMusicPlayerSoundEffectAdapt();

    void saveEffect(void);
    void turnOnEffect(void);
    void turnOffEffect(void);

    VfxU8 getEffectGroup(void);
    VfxU8 getEffectIndex(void);
    void setEffect(VfxU8 group, VfxU8 index);
};

#endif  //__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__

#endif  // __VAPP_MUSIC_PLAYER_CTRL_PLAYBACK_H__
#endif  // __MMI_MUSIC_PLAYER_SLIM__
