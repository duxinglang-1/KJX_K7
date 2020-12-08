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
 *  vapp_gallery_player.h
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

#ifndef __VAPP_GALLERY_PLAYER_H__
#define __VAPP_GALLERY_PLAYER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_gallery_slim.h"
#include "vapp_video_player_cp.h"
#include "vapp_gallery_slim_viewer.h"
#include "vapp_ncenter.h"

extern "C"
{
#include "AvrcpSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_GALLERY_PLAYBACK_FINISHED_TIMER_DURATION 50

enum VappGalleryEffectOptCtLayout
{
#if defined(__MMI_MAINLCD_480X800__)
    // align btn with anchor (0.5, 0.5)
    EO_BTN_W = 50, 
    EO_BTN_H = 50,  
    EO_BTN_X = 57, 
    // height of status bar is 38
    EO_BTN_Y_1 = 90 + 38,
    EO_BTN_Y_2 = 170 + 38,
    EO_BTN_Y_3 = 250 + 38,    
#elif defined(__MMI_MAINLCD_320X480__)
    EO_BTN_W = 45, 
    EO_BTN_H = 45,  
    EO_BTN_X = 40, 
    EO_BTN_Y_1 = 60 + 24,
    EO_BTN_Y_2 = 120 + 24,
    EO_BTN_Y_3 = 180 + 24,    
#elif defined(__MMI_MAINLCD_240X320__)
    EO_BTN_W = 40, 
    EO_BTN_H = 40,  
    EO_BTN_X = 31, 
    EO_BTN_Y_1 = 45 + 24,
    EO_BTN_Y_2 = 88 + 24, 
    EO_BTN_Y_3 = 131 + 24,       
#elif defined(__MMI_MAINLCD_240X400__)
    EO_BTN_W = 40, 
    EO_BTN_H = 40,  
    EO_BTN_X = 31, 
    EO_BTN_Y_1 = 45 + 24,
    EO_BTN_Y_2 = 88 + 24,    
    EO_BTN_Y_3 = 131 + 24,       
#else
    EO_BTN_W = 40, 
    EO_BTN_H = 40,  
    EO_BTN_X = 31, 
    EO_BTN_Y_1 = 45 + 24,
    EO_BTN_Y_2 = 88 + 24,    
    EO_BTN_Y_3 = 131 + 24,       
#endif
};

enum VappGalleryScreenModeHelperID
{
    BEGIN_OF_SCREEN_MODE_HELPER_ID = 0,
    NORMAL, 
    RESIZED,    
    CLIPPED, 
    END_OF_SCREEN_MODE_HELPER_ID
};

enum VappGallerV3DHelperType
{
    V3D_HELPER_TYPE_3D_ANAGLYPH, 
    V3D_HELPER_TYPE_SIDE_BY_SIDE, 
    V3D_HELPER_TYPE_END_OF_ENUM
};

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappGalleryVideoPlayerSlider;
class VappGalleryPlayPauseHelper;
class VappGalleryScreenModeHelper;
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
class VappGalleryFloatSettingPnael;
#endif
/***************************************************************************** 
 * Class 
 *****************************************************************************/
enum VappGalleryPlayerVideoFinishState
{
    VGFS_FINISHED,
    VGFS_UNFINISHED,
};

// Display extra "download progress" for PGDL videos
class VappGalleryVideoPlayerSliderBarView : public VcpSliderBarView
{
public:
    VappGalleryVideoPlayerSliderBarView();
    virtual void onDraw(VfxDrawContext &dc);
#ifdef __MMI_REDUCED_UI_BUFFER__
	virtual void baseOnDraw(VfxDrawContext &dc);
#endif
    void setDownloadProgress(VfxS32 progress);
protected:

    VfxS32 m_downloadProgress;
    VfxImageSrc m_downloadProgressImg;
};

class VappGalleryVideoPlayerSlider : public VcpSlider
{
public:
    virtual void onInit();
    virtual void setCurrentValue(VfxFloat value);
#ifdef __MMI_REDUCED_UI_BUFFER__
    virtual VfxFloat PositionToValue(VfxS32 position);
    virtual VfxS32 ValueToPosition(VfxFloat value);
#endif
    virtual void setIsDisabled(VfxBool isDisable);
    void setThumbHidden(VfxBool isHidden);
    void enableAvailableRegion(VfxBool enable);
    void setAvailableRegion(VfxFloat value);

private:
    VfxBool m_enableAvailableRegion;
    VfxFloat m_availableRegion;
};

class VappGalleryPlayerPage : public VappGalleryPage
{
    VFX_DECLARE_CLASS(VappGalleryPlayerPage);

    const static VappVideoMsec MSEC_PER_HOUR;
// Override
public:
    VappGalleryPlayerPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onUpdate();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event); 
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onBarAutoHide();
    virtual void setCustomTitle(const VfxWString &title);
    virtual mmi_ret onProc(mmi_event_struct *evt);

    virtual VfxBool getPageCurrentStorage(U8 &drvLetter);

protected:   
    typedef void (*PFN_CUI_CLOSE)(mmi_id); 

public:
    const static int KEYPAD_LONG_PRESS_TIMER_DURATION = 200;

// Method:
public:
    
    // set a single file for playback.
    void setLocalFile(
            const VfxWChar *filepath,     // [IN] path to the file
            U64 startingMsec = 0,         // [IN] optional starting postiion
            VfxBool isPDL = VFX_FALSE     // [IN] VFX_TRUE if the file is progressive downloaded
            );

    void setRTSPLink(
            const VfxWChar *url);     // [IN] URL of the RTSP link

    void hideAllBars(VfxBool hide);
    
    VfxBool isPlayerCui();

    // config page rotation form external
    // note this function should be called before entry player page
    void configPageRotation(const VfxScrRotateTypeEnum screenRotation);

    void configUserProcAndData(PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC userProc, void* userData);

private:
    PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC m_userProc; 
    void* m_userData; 

    #ifdef __MMI_REDUCED_UI_BUFFER__
    VfxImageFrame *m_titleBar;
    #else
    VcpTitleBar *m_titleBar;
    #endif
    VfxTextFrame *m_titlePanel; 
    VappVideoPlayerComponent *m_player;
    VappGalleryGestureTranslator *m_gestureTranslator;
    VfxTimer *m_positionUpdateTimer;
    VfxTimer *m_pdlUpdateTimer; // timer that updates progressive downloaded file

    VfxFrame *m_VCRPanel;
    VfxFrame *m_buttonPanel;
    VfxFrame *m_seekPanel;
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    VappGalleryFloatSettingPnael *m_settingPanel;
    #endif
    VcpImageButton *m_settingBtn;

    VappGalleryVideoPlayerSlider *m_seekBar;
    VfxTextFrame *m_positionText;
    VfxTextFrame *m_durationText;
    VfxTimer *m_PlaybackFinishedTimer;
    VfxTimer *m_keypadLongPressTimer;
    VfxS32 m_seekOffset;

    VappGalleryPlayPauseHelper *m_playPauseHelper; 
    VappGalleryScreenModeHelper *m_screenModeHelper;

    VfxBool m_isRTSPLink;                 // VFX_TRUE if m_currentFile is an RTSP link
    VfxBool m_isPDL;                      // VFX_TRUE if m_currentFile is progressive downloaded
    VfxBool m_autoStartPlay;              // VFX_TRUE if we should play after video opened
    VfxBool m_shouldPlayAfterSeek;        // VFX_TRUE if we should play after seek finished
    VfxBool m_isBesSurroundTurnedOn;      // VFX_TRUE if BesSurround effect is turned on
    VfxBool m_shouldSeekToBeginWhileExit; // VFX_TRUE if should set seekbar to begin force while exit
    VfxBool m_disablePositionUpdateWhenExit; // VFX_TRUE if disable upate postion
    VfxBool m_disableKeyEventHandle;      // VFX_TRUE if disable key event handle
    VfxBool m_isOnBeginSeekVideo; 
    VfxBool m_prepareToPlay;
    VappVideoMsec m_startingPos;
    VfxWString m_currentFile;   // current file being played

    mmi_id m_clipperCuiId;
    PFN_CUI_CLOSE m_cuiCloseFunc;         // cui close function for running CUI id

    VfxKeyCodeEnum m_navigationUp;
    VfxKeyCodeEnum m_navigationDown;
    VfxScrRotateTypeEnum m_pageRotation;

    // NCenter event flag
    VfxBool m_shouldPlayAfterNCenterExited;

    VfxBool m_isBarHiddenBeforePreviewPenDown;

    VcpSelectPopup *m_selectPopup;

private:
    // post last play time to user app
    void postToUser(const VfxWString &filePath, U64 lastPlayTime);

    // create control and layout
    void createVCRControl();

    // create video player control
    void createPlayerControl();
#ifdef __MMI_REDUCED_UI_BUFFER__
	// coordinate transform function
	VfxPoint coordTransform(VfxS32 x, VfxS32 y, VfxScrRotateTypeEnum targetAngle = VFX_SCR_ROTATE_TYPE_0);
#endif	
    // create titlebar
    void createTopBar();
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    // create setting panel
    void createSettingPanel();
    void onSettingBtnTapped();
    #endif
    // set time text style
    void setTimeTextFormat(VfxTextFrame *timeText);

    // update page rotation info 
    void updatePageRotationByPreviousScreen();

    // create timer to handle lone press scenario for keypad support
    void createKeypadLongPressTimer();

    // handle long press event in keypad
    void onKeypadLongPressTimeout(VfxTimer *timer);

    // open file after setLocalFile() or setRTSPLink(). 
    void openVideo();

    // update slider progress
    void onUpdatePosition(VfxTimer *timer);

    // update PDL progress
    void onUpdatePDLRegion(VfxTimer *timer);

    // update time text (position and duration)
    void setTimeText(VfxTextFrame *text, VappVideoMsec time, VfxBool forceHourDigit = VFX_FALSE);

    void onGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture);

    // handles video seeking UI events
    void onBeginSeekVideo(VcpSlider *slider, VfxFloat value);
    void onSeekVideo(VcpSlider *slider, VfxFloat value);
    void onEndSeekVideo(VcpSlider *slider, VfxFloat value);

    // handles player state change events
    void onPlayerStateChanged(VappVideoPlayerComponent *player, VappVideoPlayerState oldState, VappVideoPlayerState newState);

    void updateControlStateByPlayerState(VappVideoPlayerState state);

    // handles player open video result
    void onVideoOpened(VappVideoPlayerComponent *player, MDI_RESULT openResult);

    // disable effect option control
    void disableEffectOptControl(const VfxBool disableAcess);

    VfxBool isSubtitleSupport() const;

    void checkDRMRequest();
    static void onDRMRequestUserChoice(MMI_BOOL result);

    // handles player playback finish event
    void onPlaybackFinished(VappVideoPlayerComponent *player, MDI_RESULT finishResult);

    // handles player seek finish event
    void onSeekFinished(VappVideoPlayerComponent *player, MDI_RESULT seekResult);

    // handles timer out event for playback finished timer
    void onPlaybackFinishedTimeout(VfxTimer *source);

    // handles command button (play/pause/share/delete) events
    void onButtonTapped(VfxObject *button, VfxId id);
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    void onSettingCommand(VfxObject *button, VfxId id);
#endif
    void onPopupCommand(VfxBasePopup *popup, VfxBasePopupStateEnum state);

#ifdef __MMI_AVRCP_SUPPORT__
    // handle AVRCP commands (blue tooth remote)
    U8 onAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events);
#endif // __MMI_AVRCP_SUPPORT__

    // register/ unregister to notification Center  
    void registerNotificationCenterEvent(const VfxBool doRegister);

    // notification Center event handle
    void onNotificationCenterChanged(VappNCenterEventEnum event);

    VfxBool isMakingCall();
    
    VfxFloat calculateSeekValueForKeySuppot(const VappVideoMsec totalPos);

private:
#ifdef __MMI_AVRCP_SUPPORT__
    // for AVRCP events
    static U8 callbackAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events);
#endif // __MMI_AVRCP_SUPPORT__
    static VappGalleryPlayerPage* g_inst;
    
};

class VappGalleryPlayPauseHelper : public VfxObject
{
public:
    VappGalleryPlayPauseHelper();

// method
public:
    void setup(VcpButton *playBtn, VcpButton *pauseBtn);

    // the returned signal is emitted when play or pause
    // button are clicked.
    // defaut id in getSignalClicked() is 'PLAY' and 'PAUS'
    VfxSignal2<VfxObject*, VfxId>* getSignalTapped();

    // support setting disable state to
    // underlying play and pause buttons
    void setIsDisabled(VfxBool isDisabled);

    // check if btns of PlayPauseHelper is disabled or not
    VfxBool getIsDisabled(){return m_isDisabled;}

    // show play button. pause button is hide
    void showPlayButton();

    // show pause button and hide play button
    void showPauseButton();

    // check if play btn is cuurrent active btn
    VfxBool isPlayBtnActive(){ return m_isPlayBtnActive; }

    // set current active btn state
    void setActiveBtnState(VcpButtonStateEnum state);

private:
    VcpButton *m_playBtn;
    VcpButton *m_pauseBtn;
    VfxSignal2 <VfxObject*, VfxId>  m_signalClicked;
    VfxBool m_isPlayBtnActive;
    VfxBool m_isDisabled;

    // implementation
private:
    void onButtonTapped(VfxObject *button, VfxId id);
};


/***************************************************************************** 
 * VappGallerySettingFloatPnael 
 *****************************************************************************/

#ifdef __MMI_VIDEO_3D_ANAGLYPH__
class VappGalleryFloatSettingPnael : public VfxFrame
{   
public: 
    VappGalleryFloatSettingPnael();
    virtual void onInit();
public:     
    // add binary state(on/off) tab
    // note we use highlight state of VcpImageBytton to indicated ON state
    void addBinaryTab(const VfxId id, const VcpStateImage &stateImage, const VfxBool highlight = VFX_FALSE);
    // add multiple state tab
    // TODO: add general multi-state config
    void addMultiStateTab(VappGalleryScreenModeHelper *helper);
    // update panel layout according to tab count
    void updateLayout();
    // highlight specific tab
    void highlightTab(const VfxId id, const VfxBool highlight);   
    // disable all controls of setting panel
    void setIsDisabled(const VfxBool isDisabled);
    // disable specific tab
    void disableTab(const VfxId id, const VfxBool isDisabled);  
    // get disabled state of the specific tab
    VfxBool getIsTabDisabled(const VfxId id);
    // get tap event signal
    VfxSignal2<VfxObject*, VfxId>* getSignalTapped();
    
private:
    void _addTab(VfxObject *pObj);
    // check and calculate the position of next separator and Tap
    // return VFX_TRUE if we should add a separator before next tap
    VfxS32 _getTabCount() const;
    VcpImageButton* _getBinaryBtn(VfxId id);
    void onButtonTapped(VfxObject *button, VfxId id);

private:    
    VfxS32 m_tabCount;
    VfxSignal2 <VfxObject*, VfxId>  m_signalTapped;    
    VfxList<VcpImageButton *> m_binaryBtnList;

};
#endif /*__MMI_VIDEO_3D_ANAGLYPH__*/
#endif /* __VAPP_GALLERY_PLAYER_H__ */

