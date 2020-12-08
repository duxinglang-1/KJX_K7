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
 *  vapp_music_player_nowplaying.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player now playing page
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

#ifndef __VAPP_MUSIC_PLAYER_NOW_PLAYING_H__
#define __VAPP_MUSIC_PLAYER_NOW_PLAYING_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "vcp_text_view.h"
#include "vapp_music_player_playerbase.h"
#include "vapp_music_player_ctrlplayback.h"
#include "FileMgrSrvGProt.h"

extern "C"
{
#include "lyrics_parser.h"
}

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

/***************************************************************************** 
 * Music Player Control componet: Now Playing class
 *****************************************************************************/

class VappMusicPlayerLyricsPanel;

class VappMusicPlayerNowPlayingPage : public VappMusicPlayerPlayerBase
{
    VFX_DECLARE_CLASS(VappMusicPlayerNowPlayingPage);

    friend class VappMusicPlayerLyricsPanel;

// Variables
private:
    // Normal mode or CUI mode
    VappMusicPlayerPageModeEnum m_pageMode;

    // Playback button panel background image
    VfxFrame *m_panelPlaybackBgImg;

    // Seekbar panel background image
    VfxFrame *m_panelSeekbarBgImg;

    // Page panel to switch the album cover
    VcpPagePanel *m_pagePanelArtwork;

    // Current page of page panel
    VfxFrame *m_curPage;

    // Album cover frame of current page
    VfxFrame *m_albumCover;

    // Shadow of album cover
    VfxFrame *m_shadow;

    // Seting button
    VcpImageButton *m_btnSetting;

    // Add/remove favorite button
    VcpImageButton *m_btnFavorite;

    // Repeat button
    VcpImageButton *m_btnRepeat;

    // Shuffle button
    VcpImageButton *m_btnShuffle;

    // Timer to update lyrics
    VfxTimer *m_timerLyrics;

    // Flag to indicate if lyrics panel is on
    VfxBool m_isLyricsOn;

    // Lyrics panel
    VappMusicPlayerLyricsPanel *m_panelLyrics;

    // Current page orientation
    VfxScrRotateTypeEnum m_pageOrientation;

    // Flag to indicate page is leaving or being coverred
    VfxBool m_isBackwardExit;

    // This Flag is raised between onExit and onExited
    VfxBool m_isExiting;

public:
    VfxBool m_isLaunchToNowPlaying;

// Constructor / Destructor
public:
    VappMusicPlayerNowPlayingPage():
        m_pageMode(PAGE_MODE_NORMAL),
        m_panelPlaybackBgImg(NULL),
        m_panelSeekbarBgImg(NULL),
        m_pagePanelArtwork(NULL),
        m_curPage(NULL),
        m_albumCover(NULL),
        m_shadow(NULL),
        m_btnSetting(NULL),
        m_btnFavorite(NULL),
        m_btnRepeat(NULL),
        m_btnShuffle(NULL),
        m_timerLyrics(NULL),
        m_isLyricsOn(VFX_TRUE),
        m_panelLyrics(NULL),
        m_isLaunchToNowPlaying(VFX_FALSE),
        m_pageOrientation(VFX_SCR_ROTATE_TYPE_0),
        m_isBackwardExit(VFX_FALSE),
        m_isExiting(VFX_FALSE)
    {};
    
    VappMusicPlayerNowPlayingPage(VappMusicPlayerPageModeEnum pageMode):
        m_pageMode(pageMode),
        m_panelPlaybackBgImg(NULL),
        m_panelSeekbarBgImg(NULL),
        m_pagePanelArtwork(NULL),
        m_curPage(NULL),
        m_albumCover(NULL),
        m_shadow(NULL),
        m_btnSetting(NULL),
        m_btnFavorite(NULL),
        m_btnRepeat(NULL),
        m_btnShuffle(NULL),
        m_timerLyrics(NULL),
        m_isLyricsOn(VFX_TRUE),
        m_panelLyrics(NULL),
        m_isLaunchToNowPlaying(VFX_FALSE),
        m_pageOrientation(VFX_SCR_ROTATE_TYPE_0),
        m_isBackwardExit(VFX_FALSE)
    {};
      
// Public methods
public:
    void setRepeat(VfxU32 repeatState);
    void setShuffle(VfxU32 shuffleState);
    void setFavoriteBtn(VfxBool isAdd);
    void initLyricsPanel(const VfxWChar *filePath);
    //void setAlbumCover(VfxImageBuffer &imgBuf, VappMusicPlayerPageSwitchDirEnum dir);
    void setAlbumCover(VfxU32 songId, VfxWString &filePath, VappMusicPlayerPageSwitchDirEnum dir);
    void updateLyrics(void);
    void clearLyrics();

// Override methods
protected:
    void onInit();
    void onDeinit();
    void onEnter(VfxBool isBackward);
    void onEntered();
    void onExit(VfxBool isBackward);
    void onExited();
    void onExited2();
    void onBack();
    void initUI();
    VfxBool onPenInput(VfxPenEvent &event);
    void onRotate(const VfxScreenRotateParam &param);   
    void onQueryRotateEx(VfxScreenRotateParam &param);
    
public:
    void onSliderReleased(VcpSlider *slider, VfxFloat upValue);
    VfxBool play(const VfxWString &filePath, VfxBool forcePlay = VFX_FALSE, VfxBool updateCurTime = VFX_TRUE);

    void onTimerCallBack(VfxTimer *timer);
    void eventHandler(VfxObject *sender, VfxId id); 
    void onPlaybackStateChange(PlaybackStateEnum state);
    void setPlayPauseBtnImage(VfxBool showReversePlay = VFX_FALSE);
    void setInfoText(VfxWString &title, VfxWString &artist, VfxWString &count);
    VfxBool isOnTop();
    void onAlbumCoverSwitched(VfxFrame *f, VfxBool isComplete);
    void setEmpty();

// Implementation
private:
    void setThisPtr();
    void updateLayout();
    VfxBool isPortrait();
    VfxU32 getWidth();
    VfxU32 getHeight();
    void setAlbumCoverPos(VfxFrame *image, VappMusicPlayerPageModeEnum page_mode, VfxBool useDefault, VfxS32 width, VfxS32 height);
};


/***************************************************************************** 
 * Music Player Control componet: Lyrics panel class
 *****************************************************************************/

class VappMusicPlayerLyricsPanel : public VfxFrame
{
    VFX_DECLARE_CLASS(VappMusicPlayerLyricsPanel);

    enum
    {
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
        PanelHeight = 107,
        MarginLR = 12,
        MarginTB = 5,
        FontSize = 18,
        LineHeight = 25,
        LineGap = 2,
#else //(__MMI_MAINLCD_480X800__)
        PanelHeight = 160,
        MarginLR = 18,
        MarginTB = 10,
        FontSize = 26,
        LineHeight = 35,
        LineGap = 3,
#endif
    };

// Variables
private:
    VfxFrame *m_bgFrame;
    VcpTextView *m_textView;
    VfxWString m_lyricsFilePath;
    lyrics_meta_struct *m_lyricsData;
    VfxU32 *m_lyricsLineNum;
    VfxU32 *m_lyricsCharIdx;
    VfxU32 m_firstLineIdx;
    VfxU32 *m_lyricsIdxTable;
    VfxBool m_hasLyrics;
    VfxU32 m_duration;
    VfxU32 m_currTime;
    VfxS32 m_currLineID;
    VfxS32 m_currYPos;
    
// Constructor / Destructor
public:
        VappMusicPlayerLyricsPanel():
          m_textView(NULL),
          m_hasLyrics(VFX_FALSE),
          m_lyricsData(NULL),
          m_lyricsLineNum(NULL),
          m_lyricsCharIdx(NULL),
          m_firstLineIdx(0),
          m_lyricsIdxTable(NULL),
          m_duration(0),
          m_currTime(0),
          m_currLineID(-1),
          m_currYPos(0)
          {};


// Public methods
public:

    void initPanel();
    VfxBool initLyrics(VfxWChar *filePath);
    void clearLyrics();
    void updateLyrics(VfxU32 currTime, VfxBool isAnim = VFX_TRUE, VfxBool forceUpdate = VFX_FALSE);
    VfxBool hasLyrics();
    VfxWString getLyricsFilePath();
    VfxBool isShow();
    void showHidePanel(VfxBool show, VfxBool isAnimate = VFX_FALSE);

// Override methods
protected:
    virtual void onInit();
    virtual void onDeinit();
    
// Implementation
private:
    VfxBool parseLyrics(VfxWChar *filePath);
    void deinitLyrics();
};


#endif /*   __VAPP_MUSIC_PLAYER_NOW_PLAYING_H__ */

#endif //__COSMOS_MUSICPLY__
