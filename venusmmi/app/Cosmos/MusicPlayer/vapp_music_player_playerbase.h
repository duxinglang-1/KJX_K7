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
 *  vapp_music_player_playerbase.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player base class of player page
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_PLAYERBASE_H__
#define __VAPP_MUSIC_PLAYER_PLAYERBASE_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_ctrlplayback.h"
#include "vapp_music_player_meta_parser.h"
#include "vapp_ncenter.h"

enum VappMusicPlayerPlayerPageCallbackEnum
{
    // UI component callback event

    FUNC_ID_NP_START = 2000,

    // Page entered
    FUNC_ID_PAGE_ENTERED,           // 2001

    // Setting button
    FUNC_ID_BTN_SETTING,            // 2002

    // Add to favorite button
    FUNC_ID_BTN_ADD_TO_FAVORITE,    // 2003

    // Repeat button
    FUNC_ID_BTN_REPEAT,             // 2004

    // Shuffle button
    FUNC_ID_BTN_SHUFFLE,            // 2005

    // Back to list view
    FUNC_ID_BTN_BACK_TO_LIST,       // 2006

    // Go to now playing playlist
    FUNC_ID_BTN_NOW_PLAYING_LIST,   // 2007

    // Previous
    FUNC_ID_BTN_PREV,               // 2008

    // Next
    FUNC_ID_BTN_NEXT,               // 2009

    // Play / pause
    FUNC_ID_BTN_PLAY_PAUSE,         // 2010

    // Slider pressed
    FUNC_ID_SLIDER_PRESSED,         // 2011

    // Slider release
    FUNC_ID_SLIDER_RELEASE,         // 2012

    // Parse lyrics success
    PARSE_LYRICS_OK,                // 2013

    // No lyrics or lyrics error
    PARSE_LYRICS_FAIL,              // 2014

    FUNC_ID_BTN_END
};


enum VappMusicPlayerGesture
{
    VG_NONE,        // no gesture or not recognized
    VG_TAP,         // user taps
    VG_DOUBLE_TAP,  // user double taps
    VG_GO_PREV,     // user fast swipe to go previous
    VG_GO_NEXT,     // user fast swipe to go next
    VG_RELEASE,     // after dragging, user releases
};

/***************************************************************************** 
 * Music Player Control componet: Player base class
 *****************************************************************************/

class VappMusicPlayerService;

class VappMusicPlayerPlayerBase : public VfxPage
{
    VFX_DECLARE_CLASS(VappMusicPlayerPlayerBase);

// Variables
protected:
    // Music player service
    VappMusicPlayerService *m_mplayerSrv;

    // Previous background image of status bar, use this to restore to previous look
    VfxResId m_preStatusBarBgID;

    // Title text panel
    VfxFrame *m_panelTitle;

    // Show artist name
    VfxTextFrame *m_textArtist;

    // Show song title
    VfxTextFrame *m_textTitle;

    // Show current song index / total song number
    VfxTextFrame *m_textIndex;

    // Playback button panel
    VfxFrame *m_panelPlayback;  

    // Play / pause button, change image while play state changed
    VcpButton *m_btnPlayPause;

    // Previous button
    VcpButton *m_btnPrev;

    // Next button
    VcpButton *m_btnNext;

    // Back to tab page
    VcpButton *m_btnTabPage;

    // Go to active playlist page
    VcpButton *m_btnActivePlaylist;

    // Time of current playback
    VfxTextFrame *m_textCurrTime;

    // Total duration
    VfxTextFrame *m_textTotalTime;

    // Timer to update the seekbar
    VfxTimer *m_timerSlider;

    // Seekbar panel
    VfxFrame *m_panelSeekbar;

    // Seekbar
    VcpSlider *m_slider;

    // Playback control, passed from APP
    VappMusicPlayerCtrlPlayback *m_ctrlPlayback;

    // Current error message
    VfxWString m_strErrorMsg;

    // Flag to indicate if current playing song is pausable
    VfxBool m_isSongPausable;

    // Flag to indicate if current playing song is seekable
    VfxBool m_isSongSeekable;

    // Time display format type is 000:00 or 00:00 or 0:00
    VfxU32 m_timeDigitNum;

    // Check if long press the button
    VfxBool m_isKeyLongPress;

    // Check if long press the button
    VfxBool m_isKeyDown;

    // Key long press to seek forward or backward
    VfxBool m_isKeySeekForward;

    // Key long press timer
    VfxTimer *m_timerKeyLongPress;

    void *m_albumCoverBuffer;

    // Timer to update play pause button when receive pen up
    VfxTimer *m_timerPlayPause;

    // Meta parser obj
    VappMusicPlayerMetaParser *m_metaParser;

    // Current file path decoded by meta parser
    VfxWString m_metaParserFilePath;

    // Current image buffer used by meta parser
    VfxImageBuffer m_metaParserImgBuf;

public:
    // Flag to indicate if the seekbar knot is being dragged
    VfxBool m_sliderDragging;

    // signal for UI callback
    VfxSignal1 <VfxS32> m_signalCallback;
    
// Constructor / Destructor
public:
    VappMusicPlayerPlayerBase():
        m_mplayerSrv(NULL),
        m_preStatusBarBgID(0),
        m_textArtist(NULL),
        m_textTitle(NULL),
        m_textIndex(NULL),
        m_slider(NULL),
        m_sliderDragging(VFX_FALSE),
        m_btnPlayPause(NULL),
        m_btnPrev(NULL),
        m_btnNext(NULL),
        m_textCurrTime(NULL),
        m_textTotalTime(NULL),
        m_ctrlPlayback(NULL),
        m_timerSlider(NULL),
        m_isSongPausable(VFX_TRUE),
        m_isSongSeekable(VFX_TRUE),
        m_metaParser(NULL),
        m_timeDigitNum(1),
        m_timerKeyLongPress(NULL),
        m_isKeyLongPress(VFX_FALSE),
        m_isKeyDown(VFX_FALSE),
        m_albumCoverBuffer(NULL),
        m_timerPlayPause(NULL)
    {};
      
// Public methods
public:
    void restoreStatusBarBG();
    
// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onExited();
    virtual void onBack();
    virtual void initUI();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

public:
    void setConsumeDRM(VfxBool consume);
    virtual VfxBool open(const VfxWString &filePath);
    virtual VfxBool play(const VfxWString &filePath, VfxBool forcePlay = VFX_FALSE, VfxBool updateCurTime = VFX_TRUE);
    virtual void pause();
    virtual void playpause();
    virtual void seek(VfxU32 time);
    virtual void stop();
    virtual void closeFile();
    virtual void prev();
    virtual void next();

    // Initialize meta parser
    void initMetaParser();

    // Close meta parser
    void closeMetaParser();

    // Parse file
    VfxBool metaParserParseFile(VfxWString &filePath);

    // Get album cover by song ID (from file or play list album cache)
    VfxBool getAlbumCoverBySongId(VfxU32 songId, VfxU32 width, VfxU32 height, VfxImageBuffer& imgBuf, VfxBool noBG = VFX_TRUE);

    // Get audioInfo
    srv_plst_media_details_struct* getAudioInfo();

    // Set song title, artist name, song index
    virtual void setInfoText(VfxWString &title, VfxWString &artist, VfxWString &songCount);

    virtual void setSongCountInfoText(VfxWString &songCount);

    // Get total duration of current song
    virtual VfxU32 getDuration();

    void getTimeString(VfxWString &strTime, const VfxU32 time);

    // Update the total duration
    virtual void updateDuration();

    // Update current playing time
    virtual void updateCurrTime();

    // Get current playing time
    virtual VfxU32 getCurrTime();

    // Set the text of current time
    virtual void setTextCurrTime(VfxU32 currTime);

    // Update duration, current time, and seekbar
    virtual void updateTimeInfo();

    // Clear duraiton, current time to empty string
    virtual void clearTimeInfo();

    // Reset to empty state
    virtual void setEmpty();

    // Reset slider
    virtual void resetSlider();

    // Maximize current value of slider
    virtual void maximizeSlider();

    // Enable/disable playback UI (seekbar, prev, play/pause, next)
    virtual void setEnablePlaybackUI(VfxBool isEnable, VfxBool playPauseOnly = VFX_FALSE);

    // Set hittable state of playback UI (seekbar, prev, play/pause, next)
    virtual void setHittablePlaybackUI(VfxBool isHittable);

    // Update play / pause button image
    virtual void setPlayPauseBtnImage(VfxBool showReversePlay = VFX_FALSE);

    // Set playback control
    virtual void setCtrlPlayback(VappMusicPlayerCtrlPlayback *ctrl);

    // Handle MDI seek callback
    virtual void MDICallbackHandler(kal_int32 cb);

    // Update UI on playback state changed
    virtual void onPlaybackStateChange(PlaybackStateEnum state);

    // UI event handler
    virtual void eventHandler(VfxObject *sender, VfxId id); 

    void onEventHandlerTimerCallback(VfxTimer *timer);

    // Seekbar knot pressed
    virtual void onSliderPressed(VcpSlider *slider, VfxFloat downValue);

    // Seekbar knot released
    virtual void onSliderReleased(VcpSlider *slider, VfxFloat upValue);

    // Seekbar knot dragged and moved
    virtual void onSliderValueChange(VcpSlider *slider, VfxFloat newValue);

    // Timer tick
    virtual void onTimerCallBack(VfxTimer *timer);

    // Show error message
    void showErrorMessage(VfxWString str, VfxBool startTimer = VFX_TRUE);

    // Error timer tick
    virtual VfxBool onPlaybackErrTimerTimeout();

    // Clean error message and stop error timer
    void clearErrorMessage();

    // Handle key press for prev, next, seek
    void onKeyPrevNext(VfxKeyEventTypeEnum key_type, VcpButton *btn, VfxBool is_next);

    // Long press timer
    void onKeyLongPressTimerTimeout(VfxTimer *timer);

    // Abort key down handling
    void onKeyAbort(void);

    // Translate pen event to gesture
    VappMusicPlayerGesture translateGesture(const VfxPenEvent &e);

    // playPause will switch button image then call doPlayPause
    void doPlaypause();

// Implementation
protected:
    // Create image button
    VcpImageButton* createButton(VfxFrame *parent, VfxRect rect, VfxId id, VcpStateImage stateImg);

    // Create VcpButton
    VcpButton* createButtonEx(VfxFrame *parent, VfxRect rect, VfxId id, VcpStateImage fgImg, VcpStateImage bgImg);

    // Update duration bt input parameter
    void updateDurationByValue(VfxU32 duration);

    // Handle NCenter events
    void onNCenterStatus(VappNCenterEventEnum evt);
};

#endif /*   __VAPP_MUSIC_PLAYER_PLAYERBASE_H__  */

#endif //__COSMOS_MUSICPLY__
