
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#include "vapp_music_player_slim_nowplaying.h"
#include "vapp_music_player_slim_datatype.h"
#include "vapp_music_player_slim_util.h"
#include "vcp_scrollable.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "vapp_music_player_slim_sound_setting.h"

extern "C"
{
#include "aud_defs.h"
#include "med_main.h"
#include "gui.h"
#include "gdi_lcd_config.h"
#include "gpiosrvgprot.h"
#include "mmi_frm_input_gprot.h"
}

#define VAPP_MUSICPLY_UPDATE_DURATION_TIME 250
#define VAPP_MUSICPLY_MAXIMUN_TIME 999 * 60 * 1000 + 59 * 1000

/***************************************************************************** 
 * VappMusicPlayerNowPlayingPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerNowPlayingPage", VappMusicPlayerNowPlayingPage, VfxPage);

void VappMusicPlayerNowPlayingPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_INIT, m_pageMode);
    VfxPage::onInit();
    initUI();

    //cui mode not use session
    if(m_pageMode == PAGE_MODE_NORMAL)
    {
        m_screen = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerSlimScreen);
        
        //open library
        m_session = getMusicPlayerSession();
        m_session->m_signalSessionEvt.connect(this, &VappMusicPlayerNowPlayingPage::onPlaybackCallback);
    }
    else
    {
        //cui mode screen handler
        m_cuiscreen = VFX_OBJ_DYNAMIC_CAST(getParent(), VcuiMusicPlayerScreen);
    }
}

void VappMusicPlayerNowPlayingPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_DEINIT, m_pageMode);

    closeMetaParser();

    if(m_pageMode == PAGE_MODE_NORMAL)
    {
        m_session->m_signalSessionEvt.disconnect(this, &VappMusicPlayerNowPlayingPage::onPlaybackCallback);
        m_screen->clearNowPlayingPtr(this);
    }
    else
    {
        //clear cui nowplaying page ptr
        VcuiMusicPlayer *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiMusicPlayer);
        if (cui)
        {
            cui->clearNowPlayingPtr(this);
        }
        else if(m_cuiscreen)
        {
            m_cuiscreen->clearNowPlayingPtr(this);
        }
    }
    VfxPage::onDeinit();
}

void VappMusicPlayerNowPlayingPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_ENTER, isBackward, m_pageMode);

    //need to init metaParser early for cui mode
    initMetaParser();
    PlaybackStateEnum playState;

    if(m_pageMode == PAGE_MODE_NORMAL)
    {
        PlaybackStateEnum stateBeforeSeek;
#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
        if(!checkMemoryCardReady())
        {
            onMemoryCardChange();
            return;
        }
#endif
        //update UI info
        updateSongInfo();
        updateTimeInfo();
        setRepeatUI(m_session->getRepeat());
        setShuffleUI(m_session->getShuffle());

        // need to set backgroundplay
        m_session->setBackgroundPlay(VFX_FALSE, playState);
        stateBeforeSeek = m_session->getPlayStateBeforeSeek();

        if(playState == PB_STATE_SEEKING || playState == PB_STATE_PLAY)
        {
            if(stateBeforeSeek == PB_STATE_PLAY || playState == PB_STATE_PLAY)
            {
                setPlayPauseBtnImage(VFX_FALSE);           
            }
            if(playState == PB_STATE_SEEKING)
            { 
                if(!isBackward)
                {
                    m_screen->showWaitIcon();                
                }
                setEnablePlaybackUI(VFX_FALSE);
            }
            else
            {
                setEnablePlaybackUI(VFX_TRUE);
            }
        }
    }
    else
    {
        playState = m_ctrlPlayback->getPlaybackState();

        //get file name from path and set 
        VfxWString title;
        VfxWString subtitle = VFX_WSTR("");
        VfxWString filePath = m_cuiscreen->getFilePath();
        const WCHAR * folder_name = getFilenamebyPath(filePath.getBuf());
        title.loadFromMem(folder_name);
        m_cuiscreen->setTitle(title, subtitle);
        updateTimeInfo();
        if(playState == PB_STATE_SEEKING)
        {
            setPlayPauseBtnImage(VFX_FALSE);
            setEnablePlaybackUI(VFX_FALSE);
        }
        else if(playState == PB_STATE_STOP)
        {
            setPlayPauseBtnImage(VFX_TRUE);
        }
    }
    if(isMakingCall())
    {
        setPlayPauseBtnImage(VFX_TRUE);  
        setEnablePlaybackUI(VFX_FALSE);
        return;
    }
    //set playpause btn by play state
    if(playState == PB_STATE_PLAY)
    {
        if(m_timerSlider)
        {
            m_timerSlider->start();
        }
    }
    VfxPage::onEnter(isBackward);
}

void VappMusicPlayerNowPlayingPage::onExited()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_EXITED);

    if (m_timerSlider)
    {
        m_timerSlider->stop();
    }
} 

void VappMusicPlayerNowPlayingPage::onBack()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_BACK, m_pageMode);

    if(m_pageMode == PAGE_MODE_CUI && m_cuiscreen->m_isSinglePlayer == VFX_FALSE)
    {
        VcuiMusicPlayer *app = (VcuiMusicPlayer*) this->getMainScr()->getParent();
        app->notifyCaller();
        return;
    }
    else
    {
        VfxPage::onBack();
    }
}

void VappMusicPlayerNowPlayingPage::initUI()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_INITUI);

    VfxU32 width = getWidth();
    VfxU32 height = getHeight() - MMI_STATUS_BAR_HEIGHT;
    VfxSize pageSize(width, height);
    setSize(pageSize);
    setIsOpaque(VFX_TRUE);
    setBgColor( VRT_COLOR_MAKE(255, 30, 30, 30));
    
    // Album cover page panel
    VFX_OBJ_CREATE(m_pagePanelArtwork, VcpPagePanel, this);
    m_pagePanelArtwork->setPos(0, 0);
    m_pagePanelArtwork->setSize(pageSize);
    
    // Title panel
    VFX_OBJ_CREATE(m_panelTitle, VfxFrame, this);
    m_panelTitle->setPos(0, 0);
    m_panelTitle->setSize(width, TITLE_H);
    m_panelTitle->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_TOP));
    m_panelTitle->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    // Artist name
    VFX_OBJ_CREATE(m_textArtist, VfxTextFrame, m_panelTitle);
    m_textArtist->setAnchor(0.5f, 0.0f);
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE_ARTIST)));
    m_textArtist->setSize(130, 17); 
    m_textArtist->setPos(width/2, ARTIST_H - MMI_STATUS_BAR_HEIGHT);
    m_textArtist->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textArtist->setAutoResized(VFX_FALSE);
    m_textArtist->setAutoFontSize(VFX_FALSE);
    m_textArtist->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textArtist->setString(VFX_WSTR(""));
    m_textArtist->setColor(VRT_COLOR_GREY);
    m_textArtist->setIsUnhittable(VFX_TRUE);

    // Song title
    VFX_OBJ_CREATE(m_textTitle, VfxTextFrame, m_panelTitle);
    m_textTitle->setAnchor(0.5f, 0.0f);
    m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE_SONG)));
    m_textTitle->setSize(130, 20); 
    m_textTitle->setPos(width/2, 13);
    m_textTitle->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textTitle->setAutoResized(VFX_FALSE);
    m_textTitle->setAutoFontSize(VFX_FALSE);
    m_textTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTitle->setString(VFX_WSTR(""));
    m_textTitle->setColor(VRT_COLOR_WHITE);
    m_textTitle->setIsUnhittable(VFX_TRUE);

    // BackToAllsong
    m_btnBackToList = createButton(m_panelTitle,
                                FUNC_ID_BTN_BACK_TO_LIST, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BACK_TO_LIST, IMG_ID_VAPP_MUSICPLY_BTN_BACK_TO_LIST, 0, 0));
    m_btnBackToList->setPos(TITLE_BTN_X, TITLE_BTN_Y - MMI_STATUS_BAR_HEIGHT);
    m_btnBackToList->setSize(19, 17);

#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
    // SoundEffect
    m_btnSetting= createButton(m_panelTitle, 
                                FUNC_ID_BTN_SETTING, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_EFFECT, IMG_ID_VAPP_MUSICPLY_BTN_EFFECT, 0, 0));
    m_btnSetting->setAnchor(1.0f, 0.0f);
    m_btnSetting->setPos(width - TITLE_BTN_X, TITLE_BTN_Y - MMI_STATUS_BAR_HEIGHT);
    m_btnSetting->setSize(23, 21);
    if(m_pageMode == PAGE_MODE_CUI)
    {
        m_btnSetting->setHidden(VFX_TRUE);
    }
#endif

    // Repeat / shuffle
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnRepeat = createButton(this, 
                                FUNC_ID_BTN_REPEAT, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE, IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE, 0, 0));
        m_btnRepeat->setPos(REPEAT_BTN_X, REPEAT_BTN_Y - MMI_STATUS_BAR_HEIGHT);
        m_btnRepeat->setSize(24, 21);

        m_btnShuffle = createButton(this,
                                FUNC_ID_BTN_SHUFFLE, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, 0, 0));
        m_btnShuffle->setAnchor(1.0f, 0.0f);
        m_btnShuffle->setPos(width - REPEAT_BTN_X, REPEAT_BTN_Y - MMI_STATUS_BAR_HEIGHT);
        m_btnShuffle->setSize(24, 21);
    }
    
    // song index
    VFX_OBJ_CREATE(m_textIndex, VfxTextFrame, this);
    m_textIndex->setAnchor(0.5f, 0.5f);
    m_textIndex->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SIZE_ARTIST)));
    m_textIndex->setSize(100, 24); 
    m_textIndex->setPos(width/2, INDEX_H);
    m_textIndex->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textIndex->setAutoResized(VFX_TRUE);
    m_textIndex->setAutoFontSize(VFX_FALSE);
    m_textIndex->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textIndex->setString(VFX_WSTR(""));
    m_textIndex->setColor(VRT_COLOR_WHITE);
    m_textIndex->setIsUnhittable(VFX_TRUE);

    // Playback Panel
    VFX_OBJ_CREATE(m_panelPlayback, VfxFrame, this);
    m_panelPlayback->setPos(0, height - PLAYBACK_Y);
    m_panelPlayback->setSize(width, PLAYBACK_Y);

    VFX_OBJ_CREATE(m_panelPlaybackBgImg, VfxFrame, m_panelPlayback);
    m_panelPlaybackBgImg->setIsOpaque(VFX_TRUE);
    m_panelPlaybackBgImg->setSize(m_panelPlayback->getSize());
    m_panelPlaybackBgImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_SLIDER));
    m_panelPlaybackBgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_panelPlaybackBgImg->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
                            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    //prev
    m_btnPrev = createButton(
                     m_panelPlayback, 
                     FUNC_ID_BTN_PREV, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_P, IMG_ID_VAPP_MUSICPLY_BTN_PREV_D, 0));
    m_btnPrev->setAnchor(0.0f, 1.0f);
    m_btnPrev->setPos(PREV_BTN_X, PLAYBACK_Y - PREV_BTN_Y);
    m_btnPrev->setSize(18, 20);

    //playpause
    m_btnPlayPause = createButton(
                     m_panelPlayback, 
                     FUNC_ID_BTN_PLAY_PAUSE, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_P, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D, 0));
    m_btnPlayPause->setAnchor(0.0f, 1.0f);
    m_btnPlayPause->setPos(PREV_BTN_X + PLAY_BTN_X + 18, PLAYBACK_Y - PLAY_BTN_Y);
    m_btnPlayPause->setSize(21, 30);

    //next
    m_btnNext = createButton(
                     m_panelPlayback, 
                     FUNC_ID_BTN_NEXT, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_P, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D, 0));
    m_btnNext->setAnchor(1.0f, 1.0f);
    m_btnNext->setPos(width - PREV_BTN_X, PLAYBACK_Y - PREV_BTN_Y);
    m_btnNext->setSize(18, 20);

    // Seek related
    VFX_OBJ_CREATE(m_textCurrTime, VfxTextFrame, m_panelPlayback);
    m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textCurrTime->setAutoResized(VFX_FALSE);
    m_textCurrTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textCurrTime->setColor(VRT_COLOR_WHITE);
    m_textCurrTime->setIsUnhittable(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_textTotalTime, VfxTextFrame, m_panelPlayback);
    m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textTotalTime->setAutoResized(VFX_FALSE);
    m_textTotalTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTotalTime->setColor(VRT_COLOR_WHITE);
    m_textTotalTime->setIsUnhittable(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_slider, VcpSlider, m_panelPlayback);
    m_slider->setAnchor(0.5f, 0.5f);
    m_slider->setMaxValue(100);
    m_slider->setCurrentValue(0);
    m_slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_slider->setCacheMode(VFX_CACHE_MODE_FORCE);
    m_slider->m_signalThumbPressed.connect(this, &VappMusicPlayerNowPlayingPage::onSliderPressed);
    m_slider->m_signalThumbReleased.connect(this, &VappMusicPlayerNowPlayingPage::onSliderReleased);
    m_slider->m_signalThumbDrag.connect(this, &VappMusicPlayerNowPlayingPage::onSliderValueChange);
    m_slider->setPos(width / 2, SLIDER_Y);
    m_slider->setLength(width - 80);
    
    //set seek pos
    m_textCurrTime->setPos(2, SLIDER_Y - 5);
    m_textCurrTime->setSize(40, 12);
    m_textCurrTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textCurrTime->getSize().height)-2));
    m_textTotalTime->setPos(width - 42, SLIDER_Y - 5);
    m_textTotalTime->setSize(40, 12);
    m_textTotalTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textTotalTime->getSize().height)-2));

    //create slider timer
    VFX_OBJ_CREATE(m_timerSlider, VfxTimer, this);
    m_timerSlider->setDuration(VAPP_MUSICPLY_UPDATE_DURATION_TIME);
    m_timerSlider->m_signalTick.connect(this, &VappMusicPlayerNowPlayingPage::onTimerCallBack);

    //cui mode need to update layout
    if(m_pageMode == PAGE_MODE_CUI)
    {
        m_btnBackToList->setHidden(VFX_TRUE);
        m_textIndex->setHidden(VFX_TRUE);  
        m_btnPrev->setHidden(VFX_TRUE);
        m_btnNext->setHidden(VFX_TRUE);

        //playback
        //m_panelPlaybackBgImg->setHidden(VFX_TRUE);

        //playpause btn
        m_btnPlayPause->setPos(CUI_PLAY_BTN_X, PLAYBACK_Y - CUI_PLAY_BTN_Y);

        //time pos
        m_textCurrTime->setAnchor(0.0f, 1.0f);
        m_textTotalTime->setAnchor(0.0f, 1.0f);
        m_textCurrTime->setPos(CUI_SLIDER_X, PLAYBACK_Y - CUI_TIME_Y);
        m_textTotalTime->setPos(width - 42, PLAYBACK_Y - CUI_TIME_Y);

        //slider pos
        m_slider->setAnchor(0.0f, 1.0f);
        m_slider->setPos(CUI_SLIDER_X, PLAYBACK_Y - CUI_SLIDER_Y);
        m_slider->setLength(width - 70);

    }
}
 
VfxS32 VappMusicPlayerNowPlayingPage::play(VfxU32 index)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_PLAY, index);

    return m_session->startPlay(index);
    
}

VfxS32 VappMusicPlayerNowPlayingPage::playpause()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_PLAYPAUSE, m_pageMode);
    
    //normal mode use session and cui mode use ctrl playback
    if(m_pageMode == PAGE_MODE_CUI)
    {
    //cui mode need to handle error situation
        VfxS32 ret = MUSIC_RET_OK;
        PlaybackStateEnum   playbackState = m_ctrlPlayback->getPlaybackState();
        if (PB_STATE_PLAY == playbackState)
        {
            ret = m_ctrlPlayback->pause();
        }
        else if (PB_STATE_PAUSE == playbackState)
        {
            ret = m_ctrlPlayback->resume();
        }
        else
        {
            m_cuiscreen->play();
        }
        return ret;
    }
    else
    {
        return m_session->pauseResumePlay();
    }
}

void VappMusicPlayerNowPlayingPage::seek(VfxU32 time)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SEEK, time);
    //normal mode use session and cui mode use ctrl playback
    if(m_pageMode == PAGE_MODE_CUI)
    {
        m_ctrlPlayback->seekStart(time);
    }
    else
    {
        m_session->seekStart(time);
    }
}

VfxS32 VappMusicPlayerNowPlayingPage::prev()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_PREV);

    VfxS32 index;
    VfxS32 ret = m_session->switchPrev(index);

    m_screen->getMusicPlayerSlimApp()->sendShowHideEvent(VFX_TRUE);
    
    return ret;
}

VfxS32 VappMusicPlayerNowPlayingPage::next()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_NEXT);

    VfxS32 index;
    VfxS32 ret = m_session->switchNext(index);

    m_screen->getMusicPlayerSlimApp()->sendShowHideEvent(VFX_TRUE);
    
    return ret; 
}

void VappMusicPlayerNowPlayingPage::setRepeat()
{
    srv_playlist_repeat_enum repeatState = m_session->getRepeat();
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_REPEAT, repeatState);
        
    if(repeatState < SRV_PLAYLIST_REPEAT_MAX)
    {
        repeatState = (srv_playlist_repeat_enum)(repeatState + 1) ;
    }
    
    if(repeatState ==  SRV_PLAYLIST_REPEAT_MAX)
    {
        repeatState = SRV_PLAYLIST_REPEAT_OFF;
    }
    setRepeatUI(repeatState);
    m_session->setRepeat(repeatState);
}
void VappMusicPlayerNowPlayingPage::setRepeatUI(srv_playlist_repeat_enum repeatState)
{
    switch (repeatState)
    {
        case 0:
            m_btnRepeat->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE, IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE, 0, 0));
            break;  
        case 1: 
            m_btnRepeat->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_SINGLE, IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_SINGLE, 0, 0));
            break;  
        case 2: 
            m_btnRepeat->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_ALL, IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_ALL, 0, 0));
            break;   
            
        default:
            break;
    };
}
void VappMusicPlayerNowPlayingPage::setShuffleUI(srv_playlist_shuffle_enum shuffleState)
{
    switch (shuffleState)
    {
        case 0:
            m_btnShuffle->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, 0, 0));
            break;  
        case 1: 
            m_btnShuffle->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_ON, IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_ON, 0, 0));
            break; 
            
        default:
            break;
    };
}
void VappMusicPlayerNowPlayingPage::setShuffle()
{
    srv_playlist_shuffle_enum shuffleState = m_session->getShuffle();
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_SHUFFLE, shuffleState);
    
    if(shuffleState < SRV_PLAYLIST_SHUFFLE_MAX)
    {
        shuffleState = (srv_playlist_shuffle_enum)(shuffleState + 1) ;
    }
    
    if(shuffleState ==  SRV_PLAYLIST_SHUFFLE_MAX)
    {
        shuffleState = SRV_PLAYLIST_SHUFFLE_OFF;
    }
    setShuffleUI(shuffleState);

    m_session->setShuffle(shuffleState);
}

void VappMusicPlayerNowPlayingPage::setAlbumCover(VfxWString &filePath, VappMusicPlayerPageSwitchDirEnum dir)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_ALBUM_COVER, &filePath);

    VfxFrame *newPage;
    VFX_OBJ_CREATE(newPage, VfxFrame, m_pagePanelArtwork);
    newPage->setIsOpaque(VFX_FALSE);
    newPage->setAnchor(0.5f, 0.5f);
    newPage->setSize(m_pagePanelArtwork->getSize());
    newPage->setPos(m_pagePanelArtwork->getSize().width / 2, m_pagePanelArtwork->getSize().height / 2);

    VfxImageBuffer imgBuf;
    imgBuf.ptr = NULL;
    imgBuf.width = 0;
    imgBuf.height = 0;

    // decide the size of album cover
    VfxU32 coverWidth = 0;
    VfxU32 coverHeight = 0;
    coverWidth = VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH;
    coverHeight = VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT;

   // check and parse the album cover
    VfxBool useDefault = VFX_FALSE;

    if (filePath.isNull() || filePath.isEmpty())
    {
        useDefault = VFX_TRUE;
    }
    else 
    {
        if (m_metaParser&& m_metaParser->parseFile(filePath)
         && m_metaParser->getCover(coverWidth, coverHeight, imgBuf))
        {
            useDefault = VFX_FALSE;
        }
        else
        {
            useDefault = VFX_TRUE;
        }
    }

    if(useDefault)
    {
        newPage->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER));
        newPage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        // Set cover position, no width height need here
        setAlbumCoverPos(newPage, PAGE_MODE_NORMAL, VFX_TRUE, 0, 0);
        m_albumCover = newPage;
    }
    else
    {
        // normal mode using parsed album cover
        VfxImageSrc imgSrc;
        imgSrc.setImageBuffer(imgBuf);
        newPage->setBorder(VRT_COLOR_BLACK, 1);
        newPage->setImgContent(imgSrc);
        newPage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
        newPage->setIsOpaque(VFX_TRUE);
        newPage->setAnchor(0.5f, 0.0f);
        newPage->setCacheMode(VFX_CACHE_MODE_FREEZE);
        
        // Set cover position
        setAlbumCoverPos(newPage, PAGE_MODE_NORMAL, VFX_FALSE, newPage->getSize().width, newPage->getSize().height);
        newPage->setSize(imgBuf.width, imgBuf.height);
    }
    
    switch (dir)
    {
        case PAGE_SWITCH_DIR_LEFT:
            m_pagePanelArtwork->switchTo(newPage, VCP_PAGE_EFFECT_PUSH, 300, VCP_PAGE_DIRECTION_FROM_LEFT, VFX_TRUE);
            break;

        case PAGE_SWITCH_DIR_RIGHT:
            m_pagePanelArtwork->switchTo(newPage, VCP_PAGE_EFFECT_PUSH, 300, VCP_PAGE_DIRECTION_FROM_RIGHT, VFX_TRUE);
            break;

        case PAGE_SWITCH_DIR_NONE:
            m_pagePanelArtwork->switchTo(newPage, VCP_PAGE_EFFECT_NONE, 0, VCP_PAGE_DIRECTION_FROM_NONE, VFX_TRUE);
            break;
    }
}
void VappMusicPlayerNowPlayingPage::setAlbumCoverPos(VfxFrame *image, VappMusicPlayerPageModeEnum page_mode, VfxBool useDefault, VfxS32 width, VfxS32 height)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_ALBUM_COVER_POS, page_mode, useDefault, width, height);

    // normal mode using default disk image
    if (useDefault)
    {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        image->setAnchor(1.0f, 1.0f);
        image->setPos(getWidth()- COVER_X , getHeight()- MMI_STATUS_BAR_HEIGHT - PLAYBACK_Y - COVER_Y);
        image->setSize(75, 81);
    #elif defined(__MMI_MAINLCD_320X480__)
        image->setAnchor(1.0f, 1.0f);
        image->setPos(getWidth()- COVER_X , getHeight()- MMI_STATUS_BAR_HEIGHT - PLAYBACK_Y - COVER_Y);
        image->setSize(136, 147);
    #else //(__MMI_MAINLCD_480X800__) 
    #endif
    }
    else
    {
        image->setAnchor(0.5f, 0.5f);
        image->setPos(width/2, VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT/2 + TITLE_H);
    }
}

void VappMusicPlayerNowPlayingPage::updateDuration()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_UPDATE_DURATION);

    VfxU32 duration;
    VfxWString strTotalTime;
    const VfxU32 maxTime = VfxU32(VAPP_MUSICPLY_MAXIMUN_TIME);

    //get duration 
    if(m_pageMode == PAGE_MODE_NORMAL)
    {
        duration = m_session->getDuration();
    }
    else
    {
        duration = m_ctrlPlayback->getDuration(m_cuiscreen->m_filePath);
    }
    
    duration = duration <= maxTime ? duration : maxTime;
    
    if (m_textTotalTime)
    {
        getTimeString(strTotalTime, duration);
        m_textTotalTime->setString(strTotalTime);
    }

    if (m_slider)
    {
        m_slider->setMaxValue(duration);
    }
}

void VappMusicPlayerNowPlayingPage::updateCurrTime()
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_UPDATE_CURRTIME);

    VfxU32 currTime, totalTime;

    if(m_pageMode == PAGE_MODE_NORMAL)
    {
        //normal mode get time from session
        currTime = m_session->getCurrTime();
        totalTime = m_session->getDuration();
    }
    else
    {
        //cui mode get time from ctrlplayback
        currTime = m_ctrlPlayback->getCurrTime();
        totalTime = m_ctrlPlayback->getDuration(m_cuiscreen->m_filePath);
    }

    const VfxU32 maxTime = VfxU32(VAPP_MUSICPLY_MAXIMUN_TIME);
    currTime = currTime <= maxTime ? currTime : maxTime;
    currTime = currTime <= totalTime ? currTime : totalTime;
    
    setTextCurrTime(currTime);
    
    if (m_slider)
    {
        m_slider->setCurrentValue(currTime);
    }
}

void VappMusicPlayerNowPlayingPage::updateTimeInfo()
{
    if(!m_sliderDragging)
    {
        updateDuration();
        updateCurrTime();
    }
}

void VappMusicPlayerNowPlayingPage::updateSongInfo()
{
    VfxWString title, artist, songPath;
    artist_info_struct *info = NULL;

    VfxS32 index = m_session->getActiveIndex();
    m_session->getPath(index,songPath);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_UPDATE_SONG_INFO, index);  

    setAlbumCover(songPath, PAGE_SWITCH_DIR_NONE);

    if(index < 0 )
    {
        setEmpty();
        setEnablePlaybackUI(VFX_FALSE);
    }
    else
    {    
        if (songPath.isNull() || songPath.isEmpty())
        {
            //do nothing
        }
        else
        {
            if (m_metaParser&& m_metaParser->parseFile(songPath))
            {
                info = getAudioInfo();
            }
            
            if (info && vfx_sys_wcslen(info->artist))
            {
                artist.loadFromMem(info->artist);
            }
        }
        m_session->getTitle(index, title);
        setInfoText(title, index, artist);
        checkSliderSeekable(PAGE_MODE_NORMAL);
        setEnablePlaybackUI(VFX_TRUE);
    }
}
void VappMusicPlayerNowPlayingPage::onSliderReleased(VcpSlider *slider, VfxFloat upValue)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_SLIDER_RELEASED); 

    m_sliderDragging = VFX_FALSE;
    seek(upValue);
}
void VappMusicPlayerNowPlayingPage::onSliderPressed(VcpSlider *slider, VfxFloat upValue)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_SLIDER_PRESSED); 

    m_sliderDragging = VFX_TRUE;
}
void VappMusicPlayerNowPlayingPage::onSliderValueChange(VcpSlider *slider, VfxFloat newValue)
{
    setTextCurrTime(VfxU32(newValue));
}

void VappMusicPlayerNowPlayingPage::onTimerCallBack(VfxTimer *timer)
{
    if (!m_sliderDragging)
    {
        updateCurrTime();
    }

}

void VappMusicPlayerNowPlayingPage::setPlayPauseBtnImage(VfxBool isPlayImage)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_PLAYPAUSE_BTN_IMAGE, isPlayImage); 

    if (m_btnPlayPause)
    {
        if (isPlayImage)
        {
            m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_P, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D, 0));
        }
        else
        {
            m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_N, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_P, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_D, 0));
        }
    }
}

void VappMusicPlayerNowPlayingPage::setEmpty()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_EMPTY); 

    VfxWString emptyStr, artist;
    emptyStr.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_NO_SONG_PLAYING);
    setInfoText(emptyStr, -1, artist);
    resetSlider();
    clearTimeInfo();
}

void VappMusicPlayerNowPlayingPage::setTextCurrTime(VfxU32 currTime)
{
    if (m_textCurrTime)
    {
        VfxWString strCurrTime;
        getTimeString(strCurrTime, currTime);
        m_textCurrTime->setString(strCurrTime);
    }
}

void VappMusicPlayerNowPlayingPage::setEnablePlaybackUI(VfxBool isEnable)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_SET_ENABLE_PLAYBACK_UI, isEnable);

    if (m_slider)
    {
        m_slider->setIsDisabled(!isEnable);
    }
    if (m_btnPrev)
    {
        m_btnPrev->setIsDisabled(!isEnable);
    }
    if (m_btnNext)
    {
        m_btnNext->setIsDisabled(!isEnable);
    }
    if (m_btnPlayPause)
    {
        m_btnPlayPause->setIsDisabled(!isEnable);
    }
    if (m_btnRepeat)
    {
        m_btnRepeat->setIsUnhittable(!isEnable);
    }
    if (m_btnShuffle)
    {
        m_btnShuffle->setIsUnhittable(!isEnable);
    }
}

void VappMusicPlayerNowPlayingPage::setInfoText(VfxWString &title, VfxS32 index, VfxWString &artist)
{
    VfxWString count;

    if(title.isEmpty())
    {
        title.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG);
    }

#if defined(__MMI_MAINLCD_240X320__)
        const VfxU32 h1 = 11;
        const VfxU32 h2 = 18;
#elif defined(__MMI_MAINLCD_240X400__)
        const VfxU32 h1 = 11;
        const VfxU32 h2 = 18;
#elif defined(__MMI_MAINLCD_320X480__)
        const VfxU32 h1 = 13;
        const VfxU32 h2 = 23;
#else //(__MMI_MAINLCD_480X800__) 
#endif
    
    if(index >= 0 )
    {
        count.format("%d / %d", index + 1, m_session->getCount());
        if (m_textIndex)
        {
            m_textIndex->setString(count);
        }
        if(artist.isEmpty())
        {
            artist.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST);
        }
    }
    if (artist.isEmpty())
    {
        m_textTitle->setPos(m_textTitle->getPos().x, h1);
    }
    else
    {
        m_textTitle->setPos(m_textTitle->getPos().x, h2);
    }
    
    if (m_textArtist)
    {
        m_textArtist->setString(artist);
    }

    if (m_textIndex)
    {
        m_textIndex->setString(count);
    }

    if (m_textTitle)
    {
        m_textTitle->setString(title);
    }

}

void VappMusicPlayerNowPlayingPage::setCtrlPlayback(VappMusicPlayerCtrlPlaybackSlim *ctrl)
{
    if (ctrl)
    {
        m_ctrlPlayback = ctrl;
        m_ctrlPlayback->m_signalCtrlPlayback.connect(this, &VappMusicPlayerNowPlayingPage::onPlaybackCallback);
    }
}

void VappMusicPlayerNowPlayingPage::resetSlider()
{
    if (m_slider)
    {
        m_slider->setCurrentValue(0);
    }

    if (m_textCurrTime)
    {
        setTextCurrTime(0);
    }
}

void VappMusicPlayerNowPlayingPage::maximizeSlider()
{
    if (m_slider)
    {
        VfxFloat value = m_slider->getMaxValue();
        m_slider->setCurrentValue(value);
    }
}

void VappMusicPlayerNowPlayingPage::clearTimeInfo()
{
    if (m_textCurrTime)
    {
        VfxWString strCurrTime;
        getTimeString(strCurrTime, 0);
        m_textCurrTime->setString(strCurrTime);
    }

    if (m_textTotalTime)
    {
        VfxWString strTotalTime;
        getTimeString(strTotalTime, 0);
        m_textTotalTime->setString(strTotalTime);
    }
}

void VappMusicPlayerNowPlayingPage::onPlayerPageHandler(VfxObject *sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_PLAYERPAGE_HANDLER, id);

    switch(VappMusicPlayerPlayerPageCallbackEnum(id))
    {
        case FUNC_ID_BTN_REPEAT:
        {
            setRepeat();
            break;
        }
        case FUNC_ID_BTN_SHUFFLE:
        {
            setShuffle();
            break;
        }
        case FUNC_ID_BTN_BACK_TO_LIST:
        {
            VappMusicPlayerAllSongsPage *allsong = NULL;
            VFX_OBJ_CREATE(allsong, VappMusicPlayerAllSongsPage, getMainScr());
            getMainScr()->pushPage(PAGE_ID_ALL_SONGS, allsong);
            
            break;
        }
#ifdef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
        case FUNC_ID_BTN_SETTING:
        {
            VappMusicPlayerSettingRadioPage *soundSetting = NULL;
            VFX_OBJ_CREATE(soundSetting, VappMusicPlayerSettingRadioPage, getMainScr());
            getMainScr()->pushPage(PAGE_ID_SETTING_SOUND_EFFECT, soundSetting);
            break;
        }
#endif
        case FUNC_ID_BTN_PREV:
        {
            prev();
            break;
        }
        case FUNC_ID_BTN_NEXT:
        {
            next();
            break;
        }
        case FUNC_ID_BTN_PLAY_PAUSE:
        {
            playpause();
            break;
        }
        case FUNC_ID_SLIDER_PRESSED:
            break;
        case FUNC_ID_SLIDER_RELEASE:
            break; 
        default:
            break;
    };

}

void VappMusicPlayerNowPlayingPage::onPlaybackCallback(MusicPlayCBEvtEnum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_ON_PLAYBACK_CALLBACK, cb_event, result, ca_para_2);

    switch (cb_event)
    {
        case MUSIC_CB_OPEN:
        {
            if (MUSIC_RET_ASYNC == result)
            {
                m_screen->showWaitIcon();
            }
            else if (MUSIC_RET_OK == result)
            {
                m_screen->hideWaitIcon();
            }
            else if(MUSIC_RET_MEMORY_FULL == result)
            {
                //show memory full popup
                m_screen->popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_MEMORY_FULL),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );    
            }
            else if(MUSIC_RET_MSDC_NOTEXIST == result)
            {  
            }
            else
            {
                //show open fail popup
                m_screen->popupConfirm(
                    VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_OPEN_LIST),
                    VFX_WSTR_RES(STR_GLOBAL_OK),
                    VCP_POPUP_TYPE_FAILURE,
                    VCP_CONFIRM_BUTTON_SET_OK,
                    VCP_POPUP_BUTTON_TYPE_WARNING
                    );            
            }
            break;
        }
        case MUSIC_CB_FILE_END:
        {      
            if(m_pageMode == PAGE_MODE_CUI)
            {
                m_textCurrTime->setString(m_textTotalTime->getString());
                maximizeSlider();
                VfxTimer *timer;
                VFX_OBJ_CREATE(timer, VfxTimer, this);
                timer->setStartDelay(100);
                timer->m_signalTick.connect(this, &VappMusicPlayerNowPlayingPage::postProcFileEnd);
                timer->start();
            }
            else
            {
                // Update CurrTime text and slider status when file plays end;
                m_textCurrTime->setString(m_textTotalTime->getString());
                maximizeSlider();
            }
            break;
        }
        case MUSIC_CB_STOP:
        {
            if(m_timerSlider)
            {
                m_timerSlider->stop();
            }
#if defined (__MMI_AVRCP_SUPPORT__)
            if(m_pageMode == PAGE_MODE_CUI)
            {
                if(!m_cuiscreen->isParentTopActive())
                {
                m_cuiscreen->deregisterAVRCPcallback();
            }
            }
#endif
            break;
        }
        case MUSIC_CB_TERMINATE:
        {
            resetSlider();
            setPlayPauseBtnImage(VFX_TRUE);
            break;
        }
        case MUSIC_CB_PLAY:
        {  
            //notify ncenter to show when play
            if(m_pageMode == PAGE_MODE_NORMAL)
            {
                m_screen->getMusicPlayerSlimApp()->sendShowHideEvent(VFX_TRUE);
            }
            if(MUSIC_RET_OK ==  result)
            {
                if(m_timerSlider)
                {
                    m_timerSlider->start();
                }
                setPlayPauseBtnImage(VFX_FALSE);
                updateTimeInfo();
            }
            else
            {
                VfxWString info;
                info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_PLAY);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)info.getBuf());
                //disable slider
                if (m_slider)
                {
                    m_slider->setIsDisabled(VFX_TRUE);
                }
                setPlayPauseBtnImage(VFX_TRUE);
            }
            break;
        }

        case MUSIC_CB_BT_CONNECT:
        {
            if(m_pageMode == PAGE_MODE_NORMAL)
            {
                if(MUSIC_SUB_BT_CONNECT_START == result)
                {
                    m_screen->showWaitIcon();

					// Set play button unhittable to avoid pressing more than once.
					m_btnPlayPause->setIsUnhittable(VFX_TRUE);
                    m_btnPrev->setIsUnhittable(VFX_TRUE);
                    m_btnNext->setIsUnhittable(VFX_TRUE);
                    m_slider->setIsUnhittable(VFX_TRUE);
                }
                else if(MUSIC_SUB_BT_CONNECT_DONE == result)
                {
                    m_screen->hideWaitIcon();

					// Resume play button hittable.
					m_btnPlayPause->setIsUnhittable(VFX_FALSE);
                    m_btnPrev->setIsUnhittable(VFX_FALSE);
                    m_btnNext->setIsUnhittable(VFX_FALSE);
                    m_slider->setIsUnhittable(VFX_FALSE);
                }
            }
            else
            {
                if(MUSIC_SUB_BT_CONNECT_START == result)
                {
                    m_cuiscreen->showWaitIcon();

					// Set play button unhittable to avoid pressing more than once.
					m_btnPlayPause->setIsUnhittable(VFX_TRUE);
                    m_slider->setIsUnhittable(VFX_TRUE);
                }
                else if(MUSIC_SUB_BT_CONNECT_DONE == result)
                {
                    m_cuiscreen->hideWaitIcon();

					// Resume play button hittable.
					m_btnPlayPause->setIsUnhittable(VFX_FALSE);
                    m_slider->setIsUnhittable(VFX_FALSE);
                }
            }
            break;
        }
        case MUSIC_CB_PAUSE:
        {
            //handle song that can not pause
            if(result == VFX_FALSE)
            {
                VfxWString info = VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_NOT_PAUSABLE);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                                     MMI_EVENT_INFO_BALLOON, 
                                     MMI_NMGR_BALLOON_TYPE_FAILURE, 
                                     (WCHAR*)info.getBuf());
                if(m_pageMode == PAGE_MODE_NORMAL)
                {
                    m_session->stopPlay();
                }
                else
                {
                    m_ctrlPlayback->stop();
                }
                resetSlider();
                setPlayPauseBtnImage(VFX_TRUE);
            }
            else
            {
                setPlayPauseBtnImage(VFX_TRUE);
            }
            if(m_timerSlider)
            {
                m_timerSlider->stop();
            }
            break;
        }
        case MUSIC_CB_RESUME:
        {
            setPlayPauseBtnImage(VFX_FALSE);
            updateTimeInfo();
            if(m_timerSlider)
            {
                m_timerSlider->start();
            }
            break;
        }
        case MUSIC_CB_DUR_UPDATED:
        {
            updateDuration();
            break;
        }
        case MUSIC_CB_SEEKING:
        {
            if(m_pageMode == PAGE_MODE_CUI)
            {
                if(MUSIC_SUB_SEEKING_START == result)
                {
                    m_cuiscreen->showWaitIcon();
                    setEnablePlaybackUI(VFX_FALSE);
                }
                else if(MUSIC_SUB_SEEKING_DONE == result)
                {
                    m_cuiscreen->hideWaitIcon();
                    setEnablePlaybackUI(VFX_TRUE);
                }
            }
            else
            {
                if(MUSIC_SUB_SEEKING_START == result)
                {
                    m_screen->showWaitIcon();
                    if (m_slider)
                    {
                        m_slider->setIsDisabled(VFX_TRUE);
                    }
                    if (m_btnPrev)
                    {
                        m_btnPrev->setIsDisabled(VFX_TRUE);
                    }
                    if (m_btnNext)
                    {
                        m_btnNext->setIsDisabled(VFX_TRUE);
                    }
                    if (m_btnPlayPause)
                    {
                        m_btnPlayPause->setIsDisabled(VFX_TRUE);
                    }

                }
                else if(MUSIC_SUB_SEEKING_DONE == result)
                {
                    m_screen->hideWaitIcon();
                    if (m_slider)
                    {
                        m_slider->setIsDisabled(VFX_FALSE);
                    }
                    if (m_btnPrev)
                    {
                        m_btnPrev->setIsDisabled(VFX_FALSE);
                    }
                    if (m_btnNext)
                    {
                        m_btnNext->setIsDisabled(VFX_FALSE);
                    }
                    if (m_btnPlayPause)
                    {
                        m_btnPlayPause->setIsDisabled(VFX_FALSE);
                    }
                }
            }
            break;
        }
        case MUSIC_CB_SONG_SWITCHED:
        {
            updateSongInfo();
            updateTimeInfo();
            resetSlider();
            break;
        }
        case MUSIC_CB_INTERRUPT:
        {
            setPlayPauseBtnImage(VFX_TRUE);
            break;
        }
        
        case MUSIC_CB_LIST_END:
        {
            setPlayPauseBtnImage(VFX_TRUE);
            break;
        }
        case MUSIC_CB_MSDC_PLUG_OUT:
        {
            onMemoryCardChange();
            break;
        }
        default:
            break;
    }

}

VcpImageButton* VappMusicPlayerNowPlayingPage::createButton(VfxFrame *parent, VfxId id, VcpStateImage stateImg)

{   
    VcpImageButton *btn = NULL;
    VFX_OBJ_CREATE(btn, VcpImageButton, parent);
    btn->setId(id);
    btn->setImage(stateImg);
    btn->m_signalClicked.connect(this, &VappMusicPlayerNowPlayingPage::onPlayerPageHandler);

    return btn;
}

VfxU32 VappMusicPlayerNowPlayingPage::getWidth()
{
    return GDI_LCD_WIDTH;
}

VfxU32 VappMusicPlayerNowPlayingPage::getHeight()
{
    return GDI_LCD_HEIGHT;
}

void VappMusicPlayerNowPlayingPage::getTimeString(VfxWString &strTime, const VfxU32 duration)
{

    strTime.format("%02d:%02d", duration/(60*1000), duration%(60*1000)/1000);

    if (m_textCurrTime && m_textTotalTime)
    {
        m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }
}

artist_info_struct* VappMusicPlayerNowPlayingPage::getAudioInfo()
{    
    if (m_metaParser)
    {
        return m_metaParser->getAudioInfo();
    }

    return NULL;
}

void VappMusicPlayerNowPlayingPage::initMetaParser()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_INIT_METAPARSER);

    if (m_metaParser == NULL)
    {
        VFX_OBJ_CREATE(m_metaParser, VappMusicPlayerMetaParser, this);
    }
}

void VappMusicPlayerNowPlayingPage::closeMetaParser()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOWPLAYING_CLOSE_METAPARSER);

    if (m_metaParser)
    {
        VFX_OBJ_CLOSE(m_metaParser);
        m_metaParser = NULL;
    }

    if (m_albumCoverBuffer)
    {
        mmi_id appID = getApp()->getGroupId();
        applib_asm_free_r(appID, m_albumCoverBuffer);
        m_albumCoverBuffer = NULL;
    }

    m_metaParserImgBuf.ptr = NULL;
}

void VappMusicPlayerNowPlayingPage::postProcFileEnd(VfxTimer *timer)
{
    VFX_OBJ_CLOSE(timer);
    resetSlider();
    setPlayPauseBtnImage(VFX_TRUE);
}
void VappMusicPlayerNowPlayingPage::onMemoryCardChange()
{
    setEmpty();
    VfxWString empty;
    setAlbumCover(empty.setEmpty(), PAGE_SWITCH_DIR_NONE);
    setPlayPauseBtnImage(VFX_TRUE);
    setEnablePlaybackUI(VFX_FALSE);
}
void VappMusicPlayerNowPlayingPage::checkSliderSeekable(VappMusicPlayerPageModeEnum pageMode)
{
    VfxBool isSeekable;

    if(pageMode == PAGE_MODE_CUI)
    {
        isSeekable = m_ctrlPlayback->isSongSeekable();
    }
    else
    {
        isSeekable = m_session->isSongSeekable();
    }
    if(m_slider)
    {
        if(!isSeekable)
        {
            m_slider->setIsUnhittable(VFX_TRUE);
        }
        else
        {
            m_slider->setIsUnhittable(VFX_FALSE);
        }
    }
}

#endif //__MMI_MUSIC_PLAYER_SLIM__
