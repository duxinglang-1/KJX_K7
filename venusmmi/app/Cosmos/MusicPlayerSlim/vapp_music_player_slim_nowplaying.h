
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_NOW_PLAYING_SLIM_H__
#define __VAPP_MUSIC_PLAYER_NOW_PLAYING_SLIM_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "vcp_text_view.h"
#include "FileMgrSrvGProt.h"
#include "vcp_status_icon_bar.h"
#include "vcp_menu_popup.h"
#include "vapp_music_player_slim_datatype.h"
#include "vapp_music_player_slim.h"
#include "vapp_music_player_slim_dataDef.h"
#include "vapp_music_player_slim_meta_parser.h"
#include "vapp_music_player_slim_cui.h"


enum VappMusicPlayerPageModeEnum
{
    PAGE_MODE_NORMAL,
    PAGE_MODE_CUI
};

enum VappMusicPlayerPageSwitchDirEnum
{
    PAGE_SWITCH_DIR_LEFT,
    PAGE_SWITCH_DIR_RIGHT,
    PAGE_SWITCH_DIR_NONE
};

enum VappMusicPlayerPlayerPageCallbackEnum
{
    // UI component callback event

    FUNC_ID_NP_START = 2000,

    // Page entered
    FUNC_ID_PAGE_ENTERED,           // 2001

    // Setting button
    FUNC_ID_BTN_SETTING,            // 2002

    // Repeat button
    FUNC_ID_BTN_REPEAT,             // 2004

    // Shuffle button
    FUNC_ID_BTN_SHUFFLE,            // 2005

    // Back to list view
    FUNC_ID_BTN_BACK_TO_LIST,       // 2006

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
 * Music Player Control componet: Now Playing class
 *****************************************************************************/
class VappMusicPlayerSlimScreen;

class VcuiMusicPlayerScreen;

class VappMusicPlayerNowPlayingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappMusicPlayerNowPlayingPage);

// Variables
private:
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
    VcpImageButton *m_btnPlayPause;

    // Previous button
    VcpImageButton *m_btnPrev;

    // Next button
    VcpImageButton *m_btnNext;  

    // Time of current playback
    VfxTextFrame *m_textCurrTime;

    // Total duration
    VfxTextFrame *m_textTotalTime;

    // Timer to update the seekbar
    VfxTimer *m_timerSlider;
public:
    // Seekbar
    VcpSlider *m_slider;
private:
    // Time display format type is 000:00 or 00:00 or 0:00
    VfxU32 m_timeDigitNum;

    // Check if long press the button
    VfxBool m_isKeyLongPress;

    // Check if long press the button
    VfxBool m_isKeyDown;

    // Normal mode or CUI mode
    VappMusicPlayerPageModeEnum m_pageMode;

    // Playback button panel background image
    VfxFrame *m_panelPlaybackBgImg;

    // Page panel to switch the album cover
    VcpPagePanel *m_pagePanelArtwork;

    // Current page of page panel
    VfxFrame *m_curPage;

    // Album cover frame of current page
    VfxFrame *m_albumCover;
    
    // Shadow of album cover
    VfxFrame *m_shadow;

    // Seting button
    VcpImageButton *m_btnBackToList;

    // Add/remove favorite button
    VcpImageButton *m_btnSetting;

    // Repeat button
    VcpImageButton *m_btnRepeat;

    // Shuffle button
    VcpImageButton *m_btnShuffle;
    
    // Current file path decoded by meta parser
    VfxWString m_metaParserFilePath;
    
    // Current image buffer used by meta parser
    VfxImageBuffer m_metaParserImgBuf;
    
    void *m_albumCoverBuffer;

    VappMusicPlayerSession *m_session;

    VappMusicPlayerSlimScreen *m_screen;
public:
    // Flag to indicate if the seekbar knot is being dragged
    VfxBool m_sliderDragging;
    
    // Meta parser obj
    VappMusicPlayerMetaParser *m_metaParser;
        
    VappMusicPlayerCtrlPlaybackSlim *m_ctrlPlayback;
    
    VcuiMusicPlayerScreen *m_cuiscreen;

    // signal for UI callback
    VfxSignal1 <VfxS32> m_signalCallback;

// Constructor / Destructor
public:
    VappMusicPlayerNowPlayingPage():
        m_pageMode(PAGE_MODE_NORMAL),
        m_panelPlaybackBgImg(NULL),
        m_pagePanelArtwork(NULL),
        m_curPage(NULL),
        m_albumCover(NULL),
        m_shadow(NULL),
        m_btnBackToList(NULL),
        m_btnSetting(NULL),
        m_btnRepeat(NULL),
        m_btnShuffle(NULL),
        m_albumCoverBuffer(NULL),
        m_session(NULL),
        m_sliderDragging(VFX_FALSE),
        m_metaParser(NULL),
        m_ctrlPlayback(NULL)
    {};
    
    VappMusicPlayerNowPlayingPage(VappMusicPlayerPageModeEnum pageMode):
        m_pageMode(pageMode),
        m_panelPlaybackBgImg(NULL),
        m_pagePanelArtwork(NULL),
        m_curPage(NULL),
        m_albumCover(NULL),
        m_shadow(NULL),
        m_btnBackToList(NULL),
        m_btnSetting(NULL),
        m_btnRepeat(NULL),
        m_btnShuffle(NULL),
        m_albumCoverBuffer(NULL),
        m_session(NULL),
        m_sliderDragging(VFX_FALSE),
        m_metaParser(NULL),
        m_ctrlPlayback(NULL)
    {};

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward); 
    virtual void onExited(); 
    virtual void onBack();

public:
    void initUI();
    VfxS32 play(VfxU32 index);
    VfxS32 playpause();
    void seek(VfxU32 time);
    VfxS32 prev();
    VfxS32 next();
    void setRepeat();
    void setShuffle();
    void setRepeatUI(srv_playlist_repeat_enum repeatState);
    void setShuffleUI(srv_playlist_shuffle_enum shuffleState);
    void setAlbumCover(VfxWString &filePath, VappMusicPlayerPageSwitchDirEnum dir);
    void setAlbumCoverPos(VfxFrame *image, VappMusicPlayerPageModeEnum page_mode, VfxBool useDefault, VfxS32 width, VfxS32 height);
    void updateDuration();
    void updateCurrTime();
    void updateTimeInfo();
    void updateSongInfo();
    void onSliderReleased(VcpSlider *slider, VfxFloat upValue);
    void onSliderPressed(VcpSlider *slider, VfxFloat upValue);
    void onSliderValueChange(VcpSlider *slider, VfxFloat newValue);
    void onTimerCallBack(VfxTimer *timer);
    void onPlaybackStateChange(PlaybackStateEnum state);
    void setPlayPauseBtnImage(VfxBool showReversePlay = VFX_FALSE);
    void setEnablePlaybackUI(VfxBool isEnable);
    void setInfoText(VfxWString &title, VfxS32 index, VfxWString &artist);
    void setCtrlPlayback(VappMusicPlayerCtrlPlaybackSlim *ctrl);
    void resetSlider();
    void maximizeSlider();
    void clearTimeInfo();
    void setEmpty();
    void setTextCurrTime(VfxU32 currTime);
    void onPlayerPageHandler(VfxObject *sender, VfxId id);
    void onPlaybackCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2);
    VcpImageButton* createButton(VfxFrame *parent, VfxId id, VcpStateImage stateImg);
    void closeMetaParser();
    artist_info_struct* getAudioInfo();
    void initMetaParser();
    void postProcFileEnd(VfxTimer *timer);
	void checkSliderSeekable(VappMusicPlayerPageModeEnum pageMode);

private:
    VfxU32 getWidth();
    VfxU32 getHeight();
    void getTimeString(VfxWString &strTime, const VfxU32 duration);
	void onMemoryCardChange();
};
#endif //  __VAPP_MUSIC_PLAYER_NOW_PLAYING_SLIM_H__
#endif //   __MMI_MUSIC_PLAYER_SLIM__ 
