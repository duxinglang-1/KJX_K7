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
 *  vapp_video_player_cp.h
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
 ****************************************************************************/
#ifndef __VAPP_VIDEO_PLAYER_CP_H__
#define __VAPP_VIDEO_PLAYER_CP_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "MMI_features.h"

extern "C"
{
#include "mdi_datatype.h"
#include "mdi_video.h"
#include "BtAudioSrvGprot.h"
#include "A2DPSrvGProt.h"

}

/*
sample usage:
	VappVideoPlayerComponent *m_player;
	VFX_OBJ_CREATE(m_player, VappVideoPlayerComponent, this);
	m_player->setPos(...);
	m_player->setSize(...);
	
	m_player->m_signalFileOpened.connect(this, &VappMyApplication::onFileReady);
	m_player->openFile(VFX_WSTR("D:\\videos\\test.mpg"));

then, in onFileReady(VappVideoPlayerComponent *player, MDI_RESULT result)
    if(MDI_RES_VDOPLY_SUCCEED == result)
	{
        m_player->show();
	    m_player->play();   // play from start after open()
    }
    else
    {
        // handle various errors
        // Note: The player UI will change to error icon by itself.
    }

on exit page, or enter background mode:
	m_player->pause();
	m_player->suspend(pArchive); 

up to this point, most resources are released. 
User can open another video now. 
and if we want to resume same file when onEnter():
    m_player->resume(pArchive); // have to wait for m_signalFileOpened
    m_player->play();   // play from previous pause() time.


Current limitation:
   * You cannot apply any transformation except translation on VappVideoPlayerComponent.
   * When size or bounds change, the video will be paused.
   * When changing the position, the video will not be playing.
   * Currently (before W10.50), the component will overlapp all other frames. 
*/

typedef U64 VappVideoMsec;  // Unit is in milli-second. Based on MDI, different from VfxMsec.

enum VappVideoPlayerSeekHint
{
    VGSH_SEEK_BEGIN,
    VGSH_SEEKING,
    VGSH_SEEK_END,
};

enum VappVideoPlayerSpeed
{
    VGPS_SPEED_1X,
    VGPS_SPEED_HALF_X,
    VGPS_SPEED_1_HALF_X,
    VGPS_SPEED_2X,
};

enum VappVideoPlayerState
{
    VGPS_CLOSED,
    VGPS_OPENING,
    VGPS_PAUSED,
    VGPS_PLAYING,
    VGPS_SEEKING,
};

enum VappVideoPlayerScreenMode
{
    VS_STRETCH = 0,
    VS_INSIDE,
    VS_OUTSIDE,
    VS_END_OF_MODE
};

class VappVideoPlayerPlayOption : public VfxBase
{
public:
    VfxBool delayStartWaitingIcon;  // VFX_TRUE to delay start wiating icon until openfile
    VfxBool disableAudio;           // VFX_TRUE to disable audio
    VfxBool loopForever;            // VFX_TRUE to loop the video infinitely
    VfxBool useRingVol;             // VFX_TRUE to use ring volume instead of media volumes
    VfxBool isWallpaperScenario;    // VFX_TRUE indicates wallpaper scenario and affects overall behavior
    VfxBool isKeepBacklight;        // VFX_TRUE to automatically keep backlight on
    VfxBool useAnonymousASM;        // VFX_TRUE means anonymous ASM is used instead of root APP ASM (COSMOS)
    VfxBool supportFullResolution;   // VFX_TRUE to set MDI scenario with player scenario, otherwise set CIF scenario
    VfxBool supportSubtitle;        // VFX_TRUE if we support subtitle. 
    VfxBool isPreview;              // VFX_TRUE if we're "previewing" wallpaper or Boot video.
    VfxBool enablePlayDuringCall;   // VFX_TRUE if we allow play video when making call
    MMI_ID  asmGroupId;             // Allow client to override group id for ASM memory allocation
    VfxImageSrc defaultBackground;   // if not null image, this is used as background image when opening or error occurs
    
public:
    VappVideoPlayerPlayOption();

// configuration shortcut
public:
    void configAsWallpaperVideo();
    void configAsBootVideo();
    void configAsNormalVideo();
    void configAsMmsVideo();
    void configAsWallpaperVideoPreview();   // same as configAsWallpaperVideo, except APP ASM is used
    void configAsBootVideoPreview();        // same as configAsBootVideo, except APP ASM is used
};

class VfxVideoFrame;
class VappMDIAdaptor;
class VappVideoPlayerInputSource;
class VappVideoPlayerSwitchMemento;
class VcpActivityIndicator;
class VappVideoPlayerComponentDisplay;

class VappVideoPlayerSwitchMemento
{
public:
    VappVideoPlayerSwitchMemento();
    void reset();
    void configMemento(
                    const VfxBool isSwitchingMode,
                    const VfxBool isSeekable,
                    const VfxBool needResumeAfterSwitch,
                    const U64 totalDuration, 
                    const U64 currentTime,
                    const VappVideoMsec seekableRegion);
    VfxBool isSwitching() const;
    VfxBool isSeekable() const;
    VfxBool isNeedResumeAfterSwitch() const; 
    MDI_RESULT getSeekableRegion(
                VappVideoMsec &seekableRegion   // [OUT] 0 ~ seekableRegion is the region that can be seeked to.
                );
    MDI_RESULT getTotalTime(U64 &time);
    MDI_RESULT getCurrentTime(U64 &time);
private:
    VfxBool m_isSwitchingMode;
    VfxBool m_isSeekable;
    VfxBool m_needResumeAfterSwitch;    
    U64 m_totalDuration;
    U64 m_currentTime;
    VappVideoMsec m_seekableRegion;
};

class VappVideoPlayerComponent : public VfxFrame
{
    VFX_DECLARE_CLASS(VappVideoPlayerComponent);

public:
    VappVideoPlayerComponent();
    VappVideoPlayerComponent(const VappVideoPlayerPlayOption &option);

public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void setHidden(VfxBool isHidden);
    
// methods
public:
    // Asynchronous file open. 
    // m_signalFileOpened will be emitted when the file has opened.
    MDI_RESULT openFile(
                    const VfxWString &filePath        // local file path
                    );

    // Asynchronous file/URL open. 
    // m_signalFileOpened will be emitted when the file has opened.
    MDI_RESULT openFileEx(
                    const VfxWString &filePath,       // [IN] local file path or RTSP link
                    VfxBool isRTSPLink = VFX_FALSE,   // [IN] VFX_TRUE if the filePath is a RTSP link e.g. rtsp://streaming.server.com/SWdecode/x264.mp4
                    U64 startTimeHint = 0,            // [IN] Hint for initial start playtime. This helps stream media to have a correct start buffering time.
                                                      //      Note: user should call "getCurrentTime()" again after receiving m_signalFileOpened,
                                                      //      since this is only a hint.
                    VfxBool isPDL = VFX_FALSE         // [IN] VFX_TRUE if the file needs to adopt Progressive Download. 
                    );

    MDI_RESULT openResId(
                    VfxResId resId                    // [IN] resource id of a video 
                    );

    // close the file. This is blocking call.
    MDI_RESULT closeFile();

    // get current player state
    VappVideoPlayerState getState() const;

    /*
    For resource suspend/resume (Not supported yet)
    on exit page, or enter background mode:
	    m_player->pause();
	    m_player->suspend(pArchive); 

    up to this point, most resources are released. 
    User can open another video now. 
    and if we want to resume same file when onEnter():

        m_player->resume(pArchive); // have to wait for m_signalFileOpened
        m_player->play();   // play from previous pause() time.
    */
    MDI_RESULT suspend(void *archive = NULL);
    MDI_RESULT resume(void *archive = NULL);

    // VCR controls, start playing
    MDI_RESULT play();
    // VCR controls, pause playing
    MDI_RESULT pause();
    // VCR controls, pause playing and seek to beginning
    MDI_RESULT stop();

    // VCR controls, query if current media supports random seek.
    VfxBool isSeekable();

    // Retrieves seekable region of current video
    MDI_RESULT getSeekableRegion(
                VappVideoMsec &seekableRegion   // [OUT] 0 ~ seekableRegion is the region that can be seeked to.
                );
    
    // VCR control, query if content support audio track only
    VfxBool isVideoTrackSupported();

    // VCR controls, notify start rotate.
    void startRotate();

    // VCR controls, notify stop rotate.
    void endRotate();
    
    // VCR controls, seek to specific time.
    // hint is currently unused.
    MDI_RESULT seek(VappVideoMsec time, VappVideoPlayerSeekHint hint = VGSH_SEEKING);
    // VCR controls, Play with certain speed
    MDI_RESULT playWithSpeed(VappVideoPlayerSpeed speed);

    // Information, get total duration. 
    MDI_RESULT getTotalDuration(VappVideoMsec &totalDuration);
    MDI_RESULT getCurrentTime(VappVideoMsec &currentTime);
    MDI_RESULT getKeyFrameTime(const VappVideoMsec referenceTime, VappVideoMsec &keyFrameTime);
    MDI_RESULT getVideoAspectRatio(VfxS32 &width, VfxS32 &height);

    // Information, check if file can be clipped
    // only support the videos which are shooted by internal recorder currently
    VfxBool canClip() const;

    VfxBool canChangePlayPausedState() const;

    /*
     * subtitle support
     */
    VfxBool canToggleSubtitle() const;
    VfxBool toggleSubtitle(const VfxBool on);
    VfxBool switchSubtitle(const VfxS32 infoIndex);
    // set the index of videoInfo.subtitle_info[], 
    // note it is not subtitle track index(videoInfo.subtitle_info[i].track_index)
    void setSubtitleIndex(const VfxS32 infoIndex){m_subtitleInfoIndex = infoIndex;};
    // get subtitle info index, i.e. index of videoInfo.subtitle_info[]
    VfxS32 getSubtitleIndex() const{return m_subtitleInfoIndex;}; 

    // subtitle information, get subtitle language name
    VfxBool getSubtitleLanguageName(const VfxS32 infoIndex, VfxWString &name) const;
    // subtitle information , get total subtitle track count    
    VfxS32 getSubtitleTrackCount() const;

    // video screen mode    
    VappVideoPlayerScreenMode getVideoScreenMode(){return m_screenMode;};
    void setVideoScreenMode(const VappVideoPlayerScreenMode newMode);

    VappVideoPlayerScreenMode getDefaultScreenMode();
    static U8 getMDIDefaultScreenMode();
    static VfxS32 getSupportedScreenModeCount();
    static VfxBool isScreenModeSupported(const VappVideoPlayerScreenMode mode);
    static U8 convertToMDIScreenModeID(const VappVideoPlayerScreenMode mode);
    static VappVideoPlayerScreenMode convertToScreenModeID(const U8 mdiMode);

    // 3D anaglyph support
    VfxBool getIsSwitching();
    void setIs3DAnaglyphMode(const VfxBool b){m_is3DAnaglyphMode = b;};
    VfxBool getIs3DAnaglyphMode(){return m_is3DAnaglyphMode;};
    VfxBool canSwitchTo3DAnaglyph(const VfxBool swtchTo3D, VfxBool shouldPopupErrMsg = VFX_FALSE);
    VfxBool switchTo3DAnaglyph(const VfxBool swtchTo3D);
    VfxBool getNeedResumePlayAfterSwitch3DAnaglyph();
    void setNeedResumePlayAfterSwitch3DAnaglyph(const VfxBool needResumePlay);

    // Controls DRM rights consumption behavior.
    // By default, VideoPlayComponent would always consume
    // the rights in open() and play().
    void enableConsumeDRM(VfxBool shouldConsume);

    // when file size/buffer is insufficient,
    // video CP stops playback and wait for file to enlarge.
    // Call this API to stop and report error.
    void enableAutoWaitPGDL(
            VfxBool enableAutoWait  // [IN] VFX_FALSE to simply stop and report error. Default is VFX_TRUE
            );

    // default is VFX_TRUE, 
    // set to VFX_FALSE allows faster display, but will crash if scrolled.
    void enableScrolling(VfxBool enableScrolling);

    VfxBool getCurrentFrame(VfxImageBuffer &imgBuf);

    // returns underlying video layer.
    // only available when paused in wallpaper scenario.
    // this is because non-wallpaper scenario video layer may be rotated.
    void swithVideoLayerToSW(VfxBool convertToRGB565);
    void swithVideoLayerToHW();
    
    // WLAN prefer support
    static mmi_ret onBearerSwitch(mmi_event_struct *param);
    mmi_ret handleBearerSwitch(mmi_event_struct *param);   

// event signals
public:
    // after openFile() is called, this signal is invoked when the 
    // file is ready to play, or an error has occured.
    // see mdi_datatype.h for possible results like MDI_RES_VDOPLY_SUCCEED or MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE
    VfxSignal2<VappVideoPlayerComponent*, MDI_RESULT> m_signalFileOpened;

    // after video finishes playback, this signal is invoked.
    // The playback may be finished normally (MDI_RES_VDOPLY_SUCCEED) 
    // or finished with error (e.g. MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH)
    VfxSignal2<VappVideoPlayerComponent*, MDI_RESULT> m_signalPlaybackFinished;

    // invoked with <play_instance, old_state, new_state> when player state changes.
    VfxSignal3<VappVideoPlayerComponent*, VappVideoPlayerState, VappVideoPlayerState> m_signalPlayerStateChange;


    // after video finishes seeking, this signal is invoked.
    VfxSignal2<VappVideoPlayerComponent*, MDI_RESULT> m_signalSeekFinished;

protected:
    MDI_RESULT openImpl(const VappVideoPlayerInputSource &source);
        
    // check & set new state, then returns old state
    // while forceToNotifyApp is true, VideoCP alway notify app state changed event even if old state and new state are same
    VappVideoPlayerState setState(VappVideoPlayerState newState, const VfxBool forceToNotifyApp = VFX_FALSE);

    MDI_RESULT playAfterAudioReady();

    MDI_RESULT playAndChangeState();

    // called from static onVideoOpenResult
    virtual void handleVideoOpenResult(MDI_RESULT ret, mdi_video_info_struct *video_info);

    virtual void handleAsyncSeekResult(MDI_RESULT ret, mdi_video_info_struct *video_info);

    virtual void onSeekDoneAfterOpen(MDI_RESULT ret, mdi_video_info_struct *video_info);
    
    // called from static onPlayFinished
    virtual void handlePlayFinished(MDI_RESULT ret);

    // called from static onBTOpenCallback
    virtual void handleBTOpenCallback(srv_a2dp_callback_event_enum result);

    VfxBool isMakingCall();

private:
// data members
    VappVideoPlayerComponentDisplay *m_display;
    VfxFrame *m_audioOnlyIconFrame;
    VcpActivityIndicator *m_waitIcon;
    VfxBool m_shouldPlayAfterBTConnected;
    VfxBool m_shouldConsumeDRM;     // VFX_TRUE if we need to consume DRM when playing a video
                                    //          this happens when 
                                    //            * Player first open this file
                                    //            * Player finishes playback of this file successfully, then play again
    VfxBool m_shouldWaitPGDLFile;   // VFX_TRUE if PGDL FILE_NOT_ENOUGH error is encountered,
                                    // automatically enter seeking state and wait for the file to grow.
                                    // VFX_FALSE to simply stop. default is VFX_TRUE.
    VappVideoPlayerState m_state;
    VfxWString m_videoFilePath;
    mdi_video_info_struct m_currentVideoInfo;
    mmi_id m_appId;
    MDI_RESULT m_videoOpenResult;
    MDI_RESULT m_videoSeekResult;
    VfxBool m_needResumePlayAfterReady;
    VfxBool m_needResumePlayAfterEndRotate;
    VfxBool m_needResumePlayAfterEndSeek;
    VfxBool m_needBlockingSeekAndGetFrame;
    VfxBool m_needResumePlayAfterSwitch3DAnaglyph;
    VfxBool m_allowScrolling;       // slower, but allows scrolling this component.
    VappVideoPlayerPlayOption m_option; // other playback option
    U8 m_hBackgroundPlay;  // handle to paused background play. used to resume BG play.
    VfxBool m_connectingBT;                    // flag to prevent connect BT during BT connecting.
    U32 m_hBTAudio;                            // handle to BT Audio service
    VappMDIAdaptor *m_mdiPlayer;        // encapsulates MDI video/PDL/stream
    VfxBool m_videoFrameNotReady;
    VfxBool m_isBacklightForced;                // VFX_TRUE if we already force backlight to be on

    VappVideoPlayerScreenMode m_screenMode;

    // subtitle support
    VfxS32 m_subtitleInfoIndex;    // index of videoInfo.subtitle_info[], 
                                   // note it is not subtitle track index(videoInfo.subtitle_info[i].track_index)

    // We need to remember video info without MDI Adaptors
    // for 2D <-> 3D switch and subtitle switch.
    // During switch, we need to close and re-open MDI service,
    // so the MDI adaptors will not have correct infomation.
    // We therefore keep video info in case UI querying
    VappVideoPlayerSwitchMemento m_switchMemento;
    VfxBool m_is3DAnaglyphMode;

// implementation
    void createDisplay(const mmi_id appid);
    void setErrorIcon(VfxId iconImgId);
    void createAudioOnlyIcon();
    void showAudioOnlyIcon(const VfxBool showAudioIcon);
    void onBoundsChange(VfxFrame *frm, const VfxRect &rect);
    void changeRotation();
    MDI_RESULT prepareAndShowVideo(mdi_video_info_struct* videoInfo);
    VfxBool createA2DPConnection(VfxBool playAfterBTReady);
    S16 convertMDIPlaySpeed(VappVideoPlayerSpeed speed);
    void delayEmitFileReady(mdi_result ret);
    void delayEmitSeekDone(mdi_result ret);
    void onVideoFramePreparedAfterOpen();
    void onVideoFramePrepared();
    void onVideoFramePreparedAfterSeek();
	void popupMDIErrorMessage(mdi_result result);
    mmi_ret handleDeviceEvent(mmi_event_struct *param);
    void restoreLayerAndUnprepareVideoFrame();

// static callback handlers
protected:
    static void onPlayFinished(MDI_RESULT ret, void *user_data);
    static void onBTOpenCallback(VfxS32 result);
    static S32 onBTDeviceArrival(BtAudEvent event, U32 arg, void *user_data);
    static mmi_ret onDeviceEvent(mmi_event_struct *param);
};

#endif //__VAPP_VIDEO_PLAYER_CP_H__
