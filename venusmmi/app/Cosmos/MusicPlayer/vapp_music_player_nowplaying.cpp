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
 *  vapp_music_player_nowplaying.cpp
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "vapp_music_player_nowplaying.h"
#include "vapp_music_player.h"
#include "vapp_music_player_cui.h"
#include "vapp_music_player_sound_setting.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_util.h"
#include "vcp_scrollable.h"
#include "mmi_rp_vapp_music_player_def.h"

#include "vfx_app.h"

extern "C"
{
#include "aud_defs.h"
#include "med_main.h"
#include "gui.h"
#include "gdi_lcd_config.h"
#include "mmi_frm_input_gprot.h"
}

#define VAPP_MUSICPLY_UPDATE_DURATION_TIME 250
#define VAPP_MUSICPLY_UPDATE_LYRICS_TIME 250
#define VAPP_MUSICPLY_FILE_PATH_LEN (SRV_FMGR_PATH_MAX_LEN+1)

VappMusicPlayerNowPlayingPage *g_thisPtr = NULL;

extern "C" void* VappMusicPlayerLyricsAllocMem(VfxU32 bufferSize, kal_uint32 user_data)
{
    U8* buffer;
    VFX_ALLOC_MEM(buffer, bufferSize, g_thisPtr);
    return  (void*)buffer;
}

extern "C" void VappMusicPlayerLyricsFreeMem(void* buffer, kal_uint32 user_data)
{
    VFX_FREE_MEM(buffer);
}

VfxSize getTextSize(const VfxU32 fontSize, const VfxWChar *str)
{
    VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(fontSize));
    VfxSize textSize = font.measureStr(VFX_WSTR_MEM(str));
    return textSize;
}

/***************************************************************************** 
 * VappMusicPlayerNowPlayingPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerNowPlayingPage", VappMusicPlayerNowPlayingPage, VappMusicPlayerPlayerBase);

void VappMusicPlayerNowPlayingPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_INIT);

    VappMusicPlayerPlayerBase::onInit();

    // this is a work around to avoid g_thisPtr is set to this then set to NULL in the case goToRoot() then goToNowPlaying()
    vfxPostInvoke0(this, &VappMusicPlayerNowPlayingPage::setThisPtr);

    if (m_pageMode == PAGE_MODE_CUI)
    {
        initMetaParser();
    }
}

void VappMusicPlayerNowPlayingPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_DEINIT);

    g_thisPtr = NULL;

    m_curPage = NULL;
    m_albumCover = NULL;

    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        clearLyrics();
    
        VfxS16 sError;
        VfxS32 ret = WriteValue(NVRAM_VAPP_MUSICPLY_LYRICS_STATE, (void*)&m_isLyricsOn, DS_BYTE, &sError);

        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
        if (app)
        {
            app->clearNowPlayingPtr(this);
        }
    }
    else
    {
        VcuiMusicPlayer *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiMusicPlayer);
        if (cui)
        {
            cui->clearNowPlayingPtr(this);
        }
    }

    closeMetaParser();

    VappMusicPlayerPlayerBase::onDeinit();
}

void VappMusicPlayerNowPlayingPage::setThisPtr()
{
    g_thisPtr = this;
}

void VappMusicPlayerNowPlayingPage::onEnter(VfxBool isBackward)
{
    VappMusicPlayerPlayerBase::onEnter(isBackward);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_ON_ENTER, isBackward);

    initMetaParser();

    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
        
        app->sendShowHideEvent(VFX_TRUE);
		
        if (m_panelLyrics)
        {            
            app->updateWaitIconPos(VFX_FALSE, VFX_TRUE);

            VfxU32 activeIdx = m_mplayerSrv->getActiveIndex();

            if (m_mplayerSrv->getSongValid(activeIdx) && m_mplayerSrv->getSongLyricsState(activeIdx))
            {
                PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
                if (state != PB_STATE_SWITCHING_PLAY && state != PB_STATE_SWITCHING_NOT_PLAY)
                {
                    initLyricsPanel(m_mplayerSrv->getActiveFilePath());
                }
            
                if (m_panelLyrics->hasLyrics())
                {
                    // only update lyrics under some specific playback states
                    InterruptStruct intrInfo = m_ctrlPlayback->getInterruptedInfo();

                    if (state == PB_STATE_PLAY 
                     || state == PB_STATE_STOP
                     || state == PB_STATE_PAUSE
                     || state == PB_STATE_SEEKING
                     || (intrInfo.isInterrupted && intrInfo.state != PB_STATE_CLOSE 
                                                && intrInfo.state != PB_STATE_STOP 
                                                && intrInfo.state != PB_STATE_SWITCHING_PLAY 
                                                && intrInfo.state != PB_STATE_SWITCHING_NOT_PLAY 
                                                && intrInfo.state != PB_STATE_PLAYBACK_FAIL)
                     || (PB_STATE_BT_CONNECTING <= state && state <= PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED))
                    {
                        // update lyrics position without animation
                        vfxPostInvoke3(m_panelLyrics, &VappMusicPlayerLyricsPanel::updateLyrics, getCurrTime(), VFX_FALSE, VFX_TRUE);
                    }
                }
            }
        }

        VfxWString filePath = m_mplayerSrv->getActiveFilePath();
        setAlbumCover(m_mplayerSrv->getActiveID(), filePath, PAGE_SWITCH_DIR_NONE);
    }
    else
    {
    	//MAUI_03230739 CUI groupActive set AppMode to cui
    	m_ctrlPlayback->setIsAppMode(VFX_FALSE);
        VfxWString filePath = m_ctrlPlayback->getFilePath();
        if (!filePath.isEmpty())
        {
            // First launch of CUI, file path is empty here
            setAlbumCover(0, filePath, PAGE_SWITCH_DIR_NONE);
        }
    }
}

void VappMusicPlayerNowPlayingPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_ON_ENTERED);

    if (m_ctrlPlayback->getPlayState() == PB_STATE_PLAYBACK_FAIL)
    {
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
        if (app)
        {
            app->m_doPlayOnEntered = VFX_FALSE;
        }

        return;
    }

    m_signalCallback.emit(FUNC_ID_PAGE_ENTERED);
}

void VappMusicPlayerNowPlayingPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_ON_EXIT, isBackward);

    m_isBackwardExit = isBackward;
    m_isExiting = VFX_TRUE;
    VappMusicPlayerPlayerBase::onExit(isBackward);

    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        VfxS16 sError = 0;
        VfxS32 ret = WriteValue(NVRAM_VAPP_MUSICPLY_LYRICS_STATE, (void*)&m_isLyricsOn, DS_BYTE, &sError);
    }
}

void VappMusicPlayerNowPlayingPage::onExited()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_ON_EXITED);

    m_isExiting = VFX_FALSE;

    if (m_pageMode == PAGE_MODE_CUI && !m_isBackwardExit)
    {
        // CUI page is covered by other page, pause the playback
        const PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
        if (state == PB_STATE_PLAY)
        {
            if(m_isSongSeekable)
            {
                m_ctrlPlayback->pause();
            }
            else
            {
                m_ctrlPlayback->stop();
            }
        }
        else if (state == PB_STATE_SEEKING)
        {
            m_ctrlPlayback->m_playStateBeforeSeek = PB_STATE_PAUSE;
        }
        else if (PB_STATE_BT_CONNECTING <= state && state <= PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED)
        {
            m_ctrlPlayback->pause();
        }
    }
}

void VappMusicPlayerNowPlayingPage::onExited2()
{
    VappMusicPlayerPlayerBase::onExited2();
}

void VappMusicPlayerNowPlayingPage::onRotate(const VfxScreenRotateParam &param)
{
    updateLayout();
}

void VappMusicPlayerNowPlayingPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
    }
    else
    {
        // CUI should support page rotation

        if(param.rotateTo == VFX_SCR_ROTATE_TYPE_180)
        {
            // does not support 180
            param.rotateTo = VFX_SCR_ROTATE_TYPE_0;
        }
        else
        {
            m_pageOrientation = param.rotateTo;
        }
    }
}

void VappMusicPlayerNowPlayingPage::onBack()
{
    // if is launched by widget or NCenter, go back to widget or NCenter on pressing Back key
    // now playing should not close itself, then APP will be hidden

    if (!m_isLaunchToNowPlaying)
    {
        VcuiMusicPlayer*   app = (VcuiMusicPlayer*) this->getMainScr()->getParent();

        if(app->isKindOf(VFX_OBJ_CLASS_INFO(VcuiMusicPlayer)))
        {
            app->notifyCaller();
        }
        else
        {
        VappMusicPlayerPlayerBase::onBack();
    }
}

}

void VappMusicPlayerNowPlayingPage::initUI()
{
    VappMusicPlayerPlayerBase::initUI();

    VfxU32 width = getWidth();
    VfxU32 height = getHeight() - MMI_STATUS_BAR_HEIGHT;
    VfxSize pageSize(width, height);
    setSize(pageSize);
    setIsOpaque(VFX_TRUE);
    setBgColor(VRT_COLOR_BLACK);
    
    // Album cover page panel
    VFX_OBJ_CREATE(m_pagePanelArtwork, VcpPagePanel, this);
    m_pagePanelArtwork->setPos(0, 0);
    m_pagePanelArtwork->m_signalFinished.connect(this, &VappMusicPlayerNowPlayingPage::onAlbumCoverSwitched);
    
    // Title panel
    VFX_OBJ_CREATE(m_panelTitle, VfxFrame, this);
    m_panelTitle->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_TOP));
    m_panelTitle->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    // Artist name
    VFX_OBJ_CREATE(m_textArtist, VfxTextFrame, m_panelTitle);
    m_textArtist->setAnchor(0.5f, 0.0f);
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
    m_textTitle->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textTitle->setAutoResized(VFX_FALSE);
    m_textTitle->setAutoFontSize(VFX_FALSE);
    m_textTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTitle->setString(VFX_WSTR(""));
    m_textTitle->setColor(VRT_COLOR_WHITE);
    m_textTitle->setIsUnhittable(VFX_TRUE);

    // Setting
    m_btnSetting = createButton(m_panelTitle, 
                                VfxRect(9, 8, 34, 34), 
                                FUNC_ID_BTN_SETTING, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SETTING_N, IMG_ID_VAPP_MUSICPLY_BTN_SETTING_N, 0, 0));
    m_btnSetting->setIsEffect(VFX_TRUE);
    
    // Add to favorite
    m_btnFavorite = createButton(m_panelTitle, 
                                VfxRect(277, 8, 34, 34), 
                                FUNC_ID_BTN_ADD_TO_FAVORITE, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_RMV_FAV_N, IMG_ID_VAPP_MUSICPLY_BTN_RMV_FAV_N, 0, 0));
    m_btnFavorite->setIsDisabled(VFX_TRUE);
    m_btnFavorite->setIsEffect(VFX_TRUE);
    
    // Repeat / shuffle
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnRepeat = createButton(this, 
                                VfxRect(78, 60, 28, 28), 
                                FUNC_ID_BTN_REPEAT, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE, IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE, 0, 0));
        m_btnRepeat->setIsEffect(VFX_TRUE);
        
        m_btnShuffle = createButton(this, 
                                VfxRect(217, 60, 28, 28), 
                                FUNC_ID_BTN_SHUFFLE, 
                                VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, 0, 0));
        m_btnShuffle->setIsEffect(VFX_TRUE);
    }
    
    // song serial
    VFX_OBJ_CREATE(m_textIndex, VfxTextFrame, this);
    m_textIndex->setAnchor(0.5f, 0.5f);
    m_textIndex->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textIndex->setAutoResized(VFX_TRUE);
    m_textIndex->setAutoFontSize(VFX_FALSE);
    m_textIndex->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textIndex->setString(VFX_WSTR(""));
    m_textIndex->setColor(VRT_COLOR_WHITE);
    m_textIndex->setIsUnhittable(VFX_TRUE);

    // Playback Panel
    VFX_OBJ_CREATE(m_panelPlayback, VfxFrame, this);
    m_panelPlayback->setAnchor(0.0f, 1.0f);
    m_panelPlayback->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
                            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_panelPlaybackBgImg, VfxFrame, m_panelPlayback);
    m_panelPlaybackBgImg->setIsOpaque(VFX_TRUE);
    m_panelPlaybackBgImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_PLAYBACK));
    m_panelPlaybackBgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_panelPlaybackBgImg->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
                            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_btnTabPage = createButtonEx(
                     m_panelPlayback, 
                     VfxRect(15, 16, 47, 47), 
                     FUNC_ID_BTN_BACK_TO_LIST, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BACK_TO_LIST_N, IMG_ID_VAPP_MUSICPLY_BTN_BACK_TO_LIST_N, 0, 0),
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, 0, 0));

    m_btnPrev = createButtonEx(
                     m_panelPlayback, 
                     VfxRect(73, 16, 47, 47), 
                     FUNC_ID_BTN_PREV, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_D, 0),
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, 0));
    m_btnPrev->setIsDisabled(VFX_TRUE);

    m_btnPlayPause = createButtonEx(
                     m_panelPlayback, 
                     VfxRect(133, 12, 53, 54), 
                     FUNC_ID_BTN_PLAY_PAUSE, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D, 0),
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG1_N, IMG_ID_VAPP_MUSICPLY_BTN_BG1_P, IMG_ID_VAPP_MUSICPLY_BTN_BG1_N, 0));
    m_btnPlayPause->setIsDisabled(VFX_TRUE);
    
    m_btnNext = createButtonEx(
                     m_panelPlayback, 
                     VfxRect(201, 16, 47, 47), 
                     FUNC_ID_BTN_NEXT, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D, 0),
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, 0));
    m_btnNext->setIsDisabled(VFX_TRUE);

    m_btnActivePlaylist = createButtonEx(
                     m_panelPlayback, 
                     VfxRect(260, 16, 47, 47), 
                     FUNC_ID_BTN_NOW_PLAYING_LIST, 
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_NOW_PLAYING_LIST_N, IMG_ID_VAPP_MUSICPLY_BTN_NOW_PLAYING_LIST_N, 0, 0),
                     VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, 0, 0));

    if (m_pageMode == PAGE_MODE_CUI)
    {
        m_btnSetting->setHidden(VFX_TRUE);
        m_btnFavorite->setHidden(VFX_TRUE);
        m_textIndex->setHidden(VFX_TRUE);
        m_btnTabPage->setHidden(VFX_TRUE);
        m_btnActivePlaylist->setHidden(VFX_TRUE);
        m_btnPrev->setHidden(VFX_TRUE);
        m_btnNext->setHidden(VFX_TRUE);
    }
    
    // Seekbar Panel
    VFX_OBJ_CREATE(m_panelSeekbar, VfxFrame, this);
    m_panelSeekbar->setAnchor(0.0f, 1.0f);
    
    VFX_OBJ_CREATE(m_panelSeekbarBgImg, VfxFrame, m_panelSeekbar);
    m_panelSeekbarBgImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_SLIDER));
    m_panelSeekbarBgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    VFX_OBJ_CREATE(m_textCurrTime, VfxTextFrame, m_panelSeekbar);
    m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textCurrTime->setAutoResized(VFX_FALSE);
    m_textCurrTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textCurrTime->setColor(VRT_COLOR_WHITE);
    m_textCurrTime->setIsUnhittable(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_textTotalTime, VfxTextFrame, m_panelSeekbar);
    m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textTotalTime->setAutoResized(VFX_FALSE);
    m_textTotalTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTotalTime->setColor(VRT_COLOR_WHITE);
    m_textTotalTime->setIsUnhittable(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_slider, VcpSlider, m_panelSeekbar);
    m_slider->setAnchor(0.5f, 0.5f);
    m_slider->setMaxValue(100);
    m_slider->setCurrentValue(0);
    m_slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_slider->setIsUnhittable(VFX_TRUE);////// should remove later
    m_slider->setIsDisabled(VFX_TRUE);
    m_slider->setCacheMode(VFX_CACHE_MODE_FORCE);
   
    m_slider->m_signalThumbPressed.connect(this, &VappMusicPlayerNowPlayingPage::onSliderPressed);
    m_slider->m_signalThumbReleased.connect(this, &VappMusicPlayerNowPlayingPage::onSliderReleased);
    m_slider->m_signalThumbDrag.connect(this, &VappMusicPlayerNowPlayingPage::onSliderValueChange);
    
    // Lyrics Panel
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        VFX_OBJ_CREATE(m_panelLyrics, VappMusicPlayerLyricsPanel, this);
        
        VfxU32 isShow = 0;
        VfxS16 sError = 0;
        VfxS32 ret = ReadValue(NVRAM_VAPP_MUSICPLY_LYRICS_STATE, &isShow, DS_BYTE, &sError);
        m_isLyricsOn = isShow != 0;
    }
    
    VFX_OBJ_CREATE(m_timerSlider, VfxTimer, this);
    m_timerSlider->setDuration(VAPP_MUSICPLY_UPDATE_DURATION_TIME);
    m_timerSlider->m_signalTick.connect(this, &VappMusicPlayerNowPlayingPage::onTimerCallBack);

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(12)));
    m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(16)));
    
    m_btnSetting->setRect(VfxRect(8, 5, 30, 30));
    m_btnSetting->setEffectSize(VfxSize(52, 52));
    
    m_btnFavorite->setRect(VfxRect(204, 5, 30, 30));
    m_btnFavorite->setEffectSize(VfxSize(52, 52));
    
    VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(12), VFX_FONT_DESC_EFFECT_BORDER);
    m_textIndex->setFont(font);
    m_textIndex->setSize(100, 24);    
    
    m_btnTabPage->setRect(VfxRect(12, 10, 35, 35));
    m_btnPrev->setRect(VfxRect(56, 10, 35, 35));
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnPlayPause->setRect(VfxRect(100, 7, 41, 41));
    }
    else
    {
        m_btnPlayPause->setRect(VfxRect(100, 7, 47, 47));
        m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, 0));
        m_btnPlayPause->setBgImageList(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG_2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG_2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG_2_D, 0));
    }
    m_btnNext->setRect(VfxRect(151, 10, 35, 35));
    m_btnActivePlaylist->setRect(VfxRect(196, 10, 35, 35));
    
    m_textCurrTime->setSize(40, 12);
    m_textCurrTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textCurrTime->getSize().height)-2));
    m_textTotalTime->setSize(40, 12);
    m_textTotalTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textTotalTime->getSize().height)-2));
    
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnRepeat->setRect(VfxRect(51, 44, 25, 24));
        m_btnRepeat->setEffectSize(VfxSize(35, 35));
        m_btnShuffle->setRect(VfxRect(164, 44, 25, 24));
        m_btnShuffle->setEffectSize(VfxSize(35, 35));
    }

#elif defined(__MMI_MAINLCD_320X480__)
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14)));
    m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(20)));
    
    m_btnSetting->setRect(VfxRect(9, 8, 34, 34));
    m_btnSetting->setEffectSize(VfxSize(56, 56));
    
    m_btnFavorite->setRect(VfxRect(277, 8, 34, 34));
    m_btnFavorite->setEffectSize(VfxSize(56, 56));
    
    VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(14), VFX_FONT_DESC_EFFECT_BORDER);
    m_textIndex->setFont(font);
    m_textIndex->setSize(100, 24);
    
    m_btnTabPage->setRect(VfxRect(15, 16, 47, 47));
    m_btnPrev->setRect(VfxRect(73, 16, 47, 47));
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnPlayPause->setRect(VfxRect(133, 12, 53, 54));
    }
    else
    {
        m_btnPlayPause->setRect(VfxRect(100, 7, 60, 60));
        m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, 0));
        m_btnPlayPause->setBgImageList(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG_2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG_2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG_2_D, 0));
    }
    m_btnNext->setRect(VfxRect(201, 16, 47, 47));
    m_btnActivePlaylist->setRect(VfxRect(260, 16, 47, 47));
    
    m_textCurrTime->setSize(40, 12);
    m_textCurrTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textCurrTime->getSize().height)));
    m_textTotalTime->setSize(40, 12);
    m_textTotalTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textTotalTime->getSize().height)));
    
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnRepeat->setRect(VfxRect(78, 60, 28, 28));
        m_btnRepeat->setEffectSize(VfxSize(39, 39));
        m_btnShuffle->setRect(VfxRect(217, 60, 28, 28));
        m_btnShuffle->setEffectSize(VfxSize(39, 39));
    }

#else //(__MMI_MAINLCD_480X800__)
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(26)));
    m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(35)));
    
    m_btnSetting->setRect(VfxRect(16, 12, 56, 56));
    m_btnSetting->setEffectSize(VfxSize(78, 78));
    
    m_btnFavorite->setRect(VfxRect(422, 12, 56, 56));
    m_btnFavorite->setEffectSize(VfxSize(78, 78));
    
    VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(23), VFX_FONT_DESC_EFFECT_BORDER);
    m_textIndex->setFont(font);
    m_textIndex->setSize(180, 24);
    
    m_btnTabPage->setRect(VfxRect(23, 23, 68, 69));
    m_btnPrev->setRect(VfxRect(113, 23, 68, 69));
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnPlayPause->setRect(VfxRect(202, 18, 79, 79));
    }
    else
    {
        m_btnPlayPause->setRect(VfxRect(202, 18, 93, 93));
        m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, 0));
        m_btnPlayPause->setBgImageList(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG_2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG_2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG_2_D, 0));
    }
    m_btnNext->setRect(VfxRect(304, 23, 69, 69));
    m_btnActivePlaylist->setRect(VfxRect(392, 23, 68, 69));
    
    m_textCurrTime->setSize(64, 18);
    m_textCurrTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textCurrTime->getSize().height)));
    m_textTotalTime->setSize(64, 18);
    m_textTotalTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textTotalTime->getSize().height)));
    
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        m_btnRepeat->setRect(VfxRect(105, 93, 40, 38));
        m_btnRepeat->setEffectSize(VfxSize(60, 60));
        m_btnShuffle->setRect(VfxRect(330, 93, 40, 38));
        m_btnShuffle->setEffectSize(VfxSize(60, 60));
    }
    
#endif
    
    updateLayout();
}

void VappMusicPlayerNowPlayingPage::updateLayout()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_UPDATE_LAYOUT);

    VfxU32 width = getWidth();
    VfxU32 height = getHeight() - MMI_STATUS_BAR_HEIGHT;
    VfxSize pageSize(width, height);
    setSize(pageSize);

    m_pagePanelArtwork->setSize(pageSize);

    // Set album cover position
    if (m_curPage && m_albumCover)
    {
        m_curPage->setSize(pageSize);
        m_curPage->setPos(width / 2, height / 2);


        if (m_pageMode == PAGE_MODE_NORMAL)
        {
            // normal mode using default disk image
            if (m_albumCover->getImgContent().getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
            {
                // Set cover position, no width height need here
                setAlbumCoverPos(m_albumCover, PAGE_MODE_NORMAL, VFX_TRUE, width, height);
            }
            else
            {
                // Set cover position
                setAlbumCoverPos(m_albumCover, PAGE_MODE_NORMAL, VFX_FALSE, width, height);
            }
        }
        else
        {
            // Set cover position, same position in default image and album cover
            setAlbumCoverPos(m_albumCover, PAGE_MODE_CUI, VFX_TRUE, width, height);

            if (m_shadow)
            {
                m_shadow->setPos(m_albumCover->getRect().getMinX(), m_albumCover->getRect().getMinY());
            }
        }
    }
    
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    m_panelTitle->setSize(width, 48);
    m_panelTitle->setPos(0, 0); 

    m_textArtist->setSize(158, 16);
    m_textArtist->setPos(width / 2, 5); 

    if (m_pageMode == PAGE_MODE_CUI)
    {
        m_textTitle->setSize(width - 16, 18);
        
        VfxWString str(m_textArtist->getString());
        if (str.isEmpty())
        {
            m_textTitle->setPos(width / 2, 13);
        }
        else
        {
            m_textTitle->setPos(width / 2, 20);
        }
    }
    else
    {
        m_textTitle->setSize(width - 90, 18);
        
        VfxWString str(m_textArtist->getString());
        if (str.isEmpty())
        {
            m_textTitle->setPos(width / 2, 13);
        }
        else
        {
            m_textTitle->setPos(width / 2, 20);
        }
    }

    m_btnSetting->setPos(8, 5);

    m_btnFavorite->setPos(width - m_btnFavorite->getSize().width - 8, 5);

    m_textIndex->setPos(width / 2, 55);

    m_panelPlayback->setSize(width, 54);
    m_panelPlaybackBgImg->setSize(m_panelPlayback->getSize());

    if (isPortrait() && m_pageMode == PAGE_MODE_NORMAL)
    {
        m_panelPlayback->setPos(0, pageSize.height);
        m_panelPlaybackBgImg->setHidden(VFX_FALSE);
        m_btnPlayPause->setPos(width / 2 - m_btnPlayPause->getSize().width / 2, 7);
        
        m_panelSeekbar->setPos(0, m_panelPlayback->getRect().getMinY()+1);
        m_panelSeekbar->setSize(width, 30);
        m_panelSeekbarBgImg->setHidden(VFX_FALSE);
        m_panelSeekbarBgImg->setSize(m_panelSeekbar->getSize());
        m_textCurrTime->setPos(2, 10);
        m_textTotalTime->setPos(width - 42, 10);
        m_slider->setPos(width / 2, 30 / 2);
        m_slider->setLength(width - 80);
    }
    else
    {
        m_panelPlaybackBgImg->setHidden(VFX_TRUE);
        m_panelSeekbar->setSize(width - 54 - 4, 52);
        m_panelSeekbarBgImg->setHidden(VFX_TRUE);
        
        if (isPortrait())
        {
            m_panelPlayback->setPos(0, pageSize.height - 5);
            m_btnPlayPause->setPos(6, 4);
            m_textCurrTime->setPos(0, 41);
            m_textTotalTime->setPos(m_panelSeekbar->getSize().width - m_textTotalTime->getSize().width, 41);
            m_panelSeekbar->setPos(54, height - 15);
            m_slider->setPos(m_panelSeekbar->getSize().width / 2, 30);
            m_slider->setLength(m_panelSeekbar->getSize().width - 6);
        }
        else
        {
            m_panelPlayback->setPos(0, pageSize.height);
            m_btnPlayPause->setPos(10, 4);
            m_textCurrTime->setPos(0, 30);
            m_textTotalTime->setPos(m_panelSeekbar->getSize().width - 40, 30);
            m_panelSeekbar->setPos(54, height - 10);
            m_slider->setPos(m_panelSeekbar->getSize().width / 2, 35);
            m_slider->setLength(m_panelSeekbar->getSize().width - 80);
        }
    }

#elif defined(__MMI_MAINLCD_320X480__)
    m_panelTitle->setSize(width, 61);
    m_panelTitle->setPos(0, 0); 

    m_textArtist->setSize(width - 100, 22);
    m_textArtist->setPos(width / 2, 5); 

    if (m_pageMode == PAGE_MODE_CUI)
    {
        m_textTitle->setSize(width - 30, 27);
        
        VfxWString str(m_textArtist->getString());
        if (str.isEmpty())
        {
            m_textTitle->setPos(width / 2, 15);
        }
        else
        {
            m_textTitle->setPos(width / 2, 25);
        }
    }
    else
    {
        m_textTitle->setSize(width - 100, 27);
        
        VfxWString str(m_textArtist->getString());
        if (str.isEmpty())
        {
            m_textTitle->setPos(width / 2, 15);
        }
        else
        {
            m_textTitle->setPos(width / 2, 25);
        }
    }

    m_btnSetting->setPos(9, 8);

    m_btnFavorite->setPos(width - m_btnFavorite->getSize().width - 9, 8);

    m_textIndex->setPos(width / 2, 74);

    m_panelPlayback->setSize(width, 73);
    m_panelPlaybackBgImg->setSize(m_panelPlayback->getSize());

    if (isPortrait() && m_pageMode == PAGE_MODE_NORMAL)
    {
        m_panelPlayback->setPos(0, pageSize.height);
        m_panelPlaybackBgImg->setHidden(VFX_FALSE);
        m_btnPlayPause->setPos(width / 2 - m_btnPlayPause->getSize().width / 2, 12);

        m_panelSeekbar->setSize(width, 35);
        m_panelSeekbar->setPos(0, m_panelPlayback->getRect().getMinY()+1);
        m_panelSeekbarBgImg->setHidden(VFX_FALSE);
        m_panelSeekbarBgImg->setSize(m_panelSeekbar->getSize());
        m_textCurrTime->setPos(2, 10);
        m_textTotalTime->setPos(width - 42, 10);
        m_slider->setPos(width / 2, 35 / 2);
        m_slider->setLength(width - 80);
    }
    else
    {
        m_panelPlaybackBgImg->setHidden(VFX_TRUE);
        m_panelSeekbar->setSize(width - 77 - 10, 60);
        m_panelSeekbarBgImg->setHidden(VFX_TRUE);
        
        if (isPortrait())
        {
            m_panelPlayback->setPos(0, pageSize.height - 10);
            m_btnPlayPause->setPos(9, 9);
            m_panelSeekbar->setPos(77, height - 25);
            m_textCurrTime->setPos(0, 47);
            m_textTotalTime->setPos(m_panelSeekbar->getSize().width - m_textTotalTime->getSize().width, 47);
            m_slider->setPos(m_panelSeekbar->getSize().width / 2, 35 / 2 + 17);
            m_slider->setLength(m_panelSeekbar->getSize().width - 2);
        }
        else
        {
            m_btnPlayPause->setPos(9, 9);
            m_panelPlayback->setPos(0, pageSize.height - 5);
            m_panelSeekbar->setPos(77, height - 22);
            m_textCurrTime->setPos(0, 32);
            m_textTotalTime->setPos(m_panelSeekbar->getSize().width - 40, 32);
            m_slider->setPos(m_panelSeekbar->getSize().width / 2, 35 / 2 + 20);
            m_slider->setLength(m_panelSeekbar->getSize().width - 70);
        }
    }
    
#else //(__MMI_MAINLCD_480X800__)
    m_panelTitle->setSize(width, 96);
    m_panelTitle->setPos(0, 0); 

    m_textArtist->setSize(width - 160, 28);
    m_textArtist->setPos(width / 2, 7); 

    if (m_pageMode == PAGE_MODE_CUI)
    {
        m_textTitle->setSize(width - 30, 40);

        VfxWString str(m_textArtist->getString());
        if (str.isEmpty())
        {
            m_textTitle->setPos(width / 2, 25);
        }
        else
        {
            m_textTitle->setPos(width / 2, 40);
        }
    }
    else
    {
        m_textTitle->setSize(width - 160, 40);

        VfxWString str(m_textArtist->getString());
        if (str.isEmpty())
        {
            m_textTitle->setPos(width / 2, 25);
        }
        else
        {
            m_textTitle->setPos(width / 2, 40);
        }
    }

    m_btnSetting->setPos(16, 12);

    m_btnFavorite->setPos(width - m_btnFavorite->getSize().width - 16, 12);

    m_textIndex->setPos(width / 2, 112);

    m_panelPlayback->setSize(width, 115);
    m_panelPlaybackBgImg->setSize(m_panelPlayback->getSize());

    if (isPortrait() && m_pageMode == PAGE_MODE_NORMAL)
    {
        m_panelPlayback->setPos(0, pageSize.height);
        m_panelPlaybackBgImg->setHidden(VFX_FALSE);
        m_btnPlayPause->setPos(width / 2 - m_btnPlayPause->getSize().width / 2, 18);
        
        m_panelSeekbar->setPos(0, m_panelPlayback->getRect().getMinY()+1);
        m_panelSeekbar->setSize(width, 60);
        m_panelSeekbarBgImg->setHidden(VFX_FALSE);
        m_panelSeekbarBgImg->setSize(m_panelSeekbar->getSize());
        m_textCurrTime->setPos(3, 21);
        m_textTotalTime->setPos(width - 67, 21);
        m_slider->setPos(width / 2, 60 / 2);
        m_slider->setLength(width - 128);
    }
    else
    {
        m_panelPlaybackBgImg->setHidden(VFX_TRUE);
        m_panelSeekbar->setSize(width - 115 - 10, 80);
        m_panelSeekbarBgImg->setHidden(VFX_TRUE);
        
        if (isPortrait())
        {
            m_panelPlayback->setPos(0, pageSize.height - 10);
            m_btnPlayPause->setPos(14, 7);
            m_panelSeekbar->setPos(115, height - 27);
            m_textCurrTime->setPos(0, 60);
            m_textTotalTime->setPos(m_panelSeekbar->getSize().width - m_textTotalTime->getSize().width, 60);
            m_slider->setPos(m_panelSeekbar->getSize().width / 2, 36);
            m_slider->setLength(m_panelSeekbar->getSize().width - 7);
        }
        else
        {
            m_panelPlayback->setPos(0, pageSize.height);
            m_btnPlayPause->setPos(20, 11);
            m_panelSeekbar->setPos(115, height - 24);
            m_textCurrTime->setPos(0, 41);
            m_textTotalTime->setPos(m_panelSeekbar->getSize().width - 64, 41);
            m_slider->setPos(m_panelSeekbar->getSize().width / 2, 50);
            m_slider->setLength(m_panelSeekbar->getSize().width - 128);
        }
    }

#endif

    if (m_panelLyrics)
    {
        m_panelLyrics->setPos(0, m_panelSeekbar->getRect().getMinY());
    }
}

VfxBool VappMusicPlayerNowPlayingPage::isPortrait()
{
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        return VFX_TRUE;
    }
    else
    {
        return m_pageOrientation == VFX_SCR_ROTATE_TYPE_NORMAL 
            || m_pageOrientation == VFX_SCR_ROTATE_TYPE_0
            || m_pageOrientation == VFX_SCR_ROTATE_TYPE_180;
    }
}

VfxU32 VappMusicPlayerNowPlayingPage::getWidth()
{
    if (isPortrait())
    {
        return GDI_LCD_WIDTH;
    }
    else
    {
        return GDI_LCD_HEIGHT;
    }
}

VfxU32 VappMusicPlayerNowPlayingPage::getHeight()
{
    if (isPortrait())
    {
        return GDI_LCD_HEIGHT;
    }
    else
    {
        return GDI_LCD_WIDTH;
    }
}

void VappMusicPlayerNowPlayingPage::setRepeat(VfxU32 repeatState)
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
    };
}

void VappMusicPlayerNowPlayingPage::setShuffle(VfxU32 shuffleState)
{
    switch (shuffleState)
    {
        case 0:
            m_btnShuffle->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF, 0, 0));
            break;  
        case 1: 
            m_btnShuffle->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_ON, IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_ON, 0, 0));
            break;  
    };
}

void VappMusicPlayerNowPlayingPage::setFavoriteBtn(VfxBool isAdd)
{
    if (isAdd)
    {
        m_btnFavorite->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_RMV_FAV_N, IMG_ID_VAPP_MUSICPLY_BTN_RMV_FAV_N, 0, 0));
    }
    else
    {
        m_btnFavorite->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_ADD_FAV_N, IMG_ID_VAPP_MUSICPLY_BTN_ADD_FAV_N, 0, 0));
    }
}

void VappMusicPlayerNowPlayingPage::initLyricsPanel(const VfxWChar *filePath)
{
    VfxU32 activeIdx = m_mplayerSrv->getActiveIndex();
    if (!m_mplayerSrv->getSongValid(activeIdx) || !m_mplayerSrv->getSongLyricsState(activeIdx))
    {
        return;
    }
        
    if (!m_panelLyrics || filePath == NULL)
    {
        return;
    }
    
    setThisPtr();

    U16 lyricFilePath[VAPP_MUSICPLY_FILE_PATH_LEN];

    U8 ret = lyrics_convert_file_name(
            (U16*)filePath, 
            (U16*)srv_fmgr_path_get_filename_const_ptr(filePath), 
            lyricFilePath);

    if (VFX_WSTR_MEM(lyricFilePath) == m_panelLyrics->getLyricsFilePath())
    {
        return;
    }
    
    if (ret != LYRICS_ERR_NONE || !isFileExist((VfxWChar*)lyricFilePath))
    {
        if (m_isLyricsOn)
        {
            m_panelLyrics->showHidePanel(VFX_FALSE);
        }
        m_panelLyrics->clearLyrics();

        m_signalCallback.emit(PARSE_LYRICS_FAIL);

        return;
    }

    if (m_panelLyrics->initLyrics(lyricFilePath))
    {
        if (m_isLyricsOn)
        {
            m_panelLyrics->showHidePanel(VFX_TRUE);
        }

        m_signalCallback.emit(PARSE_LYRICS_OK);
    }
    else
    {
        if (m_isLyricsOn)
        {
            m_panelLyrics->showHidePanel(VFX_FALSE);
        }

        m_signalCallback.emit(PARSE_LYRICS_FAIL);
    }
}

void VappMusicPlayerNowPlayingPage::eventHandler(VfxObject *sender, VfxId id)
{
    if (id == FUNC_ID_BTN_SETTING)
    {
        VappMusicPlayerSettingPage *page = NULL;
        VFX_OBJ_CREATE_EX(page, 
            VappMusicPlayerSettingPage, 
            getMainScr(), 
            ((VfxS32)m_pageMode,  m_ctrlPlayback->getCtrlSoundEffect()));

        getMainScr()->pushPage(0, page);
    }
    
    VappMusicPlayerPlayerBase::eventHandler(sender, id);
}

VfxBool VappMusicPlayerNowPlayingPage::onPenInput(VfxPenEvent &event)
{
    if (!m_ctrlPlayback || m_ctrlPlayback->getPlayState() == PB_STATE_NONE)
    {
        return VfxPage::onPenInput(event);
    }

    // CUI page doesn't handle prev/next guesture and tap
    if (m_pageMode == PAGE_MODE_CUI)
    {
        return VfxPage::onPenInput(event);
    }

    // Ignore event if is dragging slider
    if (m_sliderDragging)
    {
        return VfxPage::onPenInput(event);
    }

    // not handle pen event outside the album cover area
    VfxPoint pos(event.pos.x, event.pos.y - MMI_STATUS_BAR_HEIGHT);
    if (pos.y < m_panelTitle->getRect().getMaxY() || pos.y > m_panelSeekbar->getRect().getMinY())
    {
        return VfxPage::onPenInput(event);
    }

    // Ignore event if prev and next button are disabled
    if (m_btnNext && (m_btnNext->getIsDisabled() || m_btnNext->getIsUnhittable()))
    {
        return VfxPage::onPenInput(event);
    }

    switch(translateGesture(event))
    {
    case VG_GO_NEXT:
        m_signalCallback.emit(FUNC_ID_BTN_NEXT);
        return VFX_TRUE;

    case VG_GO_PREV:
        m_signalCallback.emit(FUNC_ID_BTN_PREV);
        return VFX_TRUE;

    case VG_TAP:
        if (m_panelLyrics && m_panelLyrics->hasLyrics())
        {
            m_panelLyrics->showHidePanel(!m_panelLyrics->isShow(), VFX_TRUE);
            m_isLyricsOn = m_panelLyrics->isShow();
        }
        return VFX_TRUE;
    
    case VG_RELEASE:
        break;

    default:
        break;
    }

    return VFX_TRUE;
}

void VappMusicPlayerNowPlayingPage::onSliderReleased(VcpSlider *slider, VfxFloat upValue)
{
    // Update lyrics, do not update if this onSliderReleased is triggered by page exiting (Lyrics updating would fail)
    if (m_panelLyrics && !m_isExiting)
    {
        m_panelLyrics->updateLyrics(upValue, VFX_TRUE, VFX_TRUE);
    }    

    VappMusicPlayerPlayerBase::onSliderReleased(slider, upValue);
}

void VappMusicPlayerNowPlayingPage::onPlaybackStateChange(PlaybackStateEnum state)
{
    VappMusicPlayerPlayerBase::onPlaybackStateChange(state);
    
    VfxBool isDisable = m_ctrlPlayback == NULL || (state == PB_STATE_NONE && m_ctrlPlayback->getFilePath().isEmpty());
    m_btnFavorite->setIsDisabled(isDisable);

    if (!isDisable)
    {
        // block hitting Favorite button on switching
        VfxBool isUnhittable = state == PB_STATE_SWITCHING_PLAY || state == PB_STATE_SWITCHING_NOT_PLAY;
        m_btnFavorite->setIsUnhittable(isUnhittable);
    }

    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        // Handle Lyrics

        if (state == PB_STATE_NONE)
        {
            if (m_isLyricsOn)
            {
                m_panelLyrics->showHidePanel(VFX_FALSE);
            }
        }
        else if (state == PB_STATE_OPEN)
        {
            VfxU32 activeIdx = m_mplayerSrv->getActiveIndex();
            if (m_mplayerSrv->getSongValid(activeIdx) && m_mplayerSrv->getSongLyricsState(activeIdx))
            {
                initLyricsPanel(m_ctrlPlayback->getFilePath());

                if (m_panelLyrics->hasLyrics())
                {
                   // update lyrics position without animation                
                    m_panelLyrics->updateLyrics(getCurrTime(), VFX_FALSE, VFX_TRUE);
                }
            }
        }
        else if ((state == PB_STATE_CLOSE && !m_ctrlPlayback->getInterruptedInfo().isInterrupted)
         || state == PB_STATE_SWITCHING_PLAY
         || state == PB_STATE_SWITCHING_NOT_PLAY)
        {
            clearLyrics();
        }
    }
}

void VappMusicPlayerNowPlayingPage::setPlayPauseBtnImage(VfxBool showReversePlay)
{
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        VappMusicPlayerPlayerBase::setPlayPauseBtnImage(showReversePlay);
    }
    else
    {
        VfxBool isPlayImage = m_ctrlPlayback->getPlayPauseState();

        // Show reverse icon before play/pause request
        if(showReversePlay)
        {
            isPlayImage = !isPlayImage;
        }

        if (isPlayImage)
        {
            m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N, 0));
        }
        else
        {
            m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_2_N, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_2_N, 0));
        }
    }
}

void VappMusicPlayerNowPlayingPage::setInfoText(VfxWString &title, VfxWString &artist, VfxWString &count)
{
    VappMusicPlayerPlayerBase::setInfoText(title, artist, count);

#if defined(__MMI_MAINLCD_240X320__)
    const VfxU32 h1 = 13;
    const VfxU32 h2 = 20;
#elif defined(__MMI_MAINLCD_240X400__)
    const VfxU32 h1 = 13;
    const VfxU32 h2 = 20;
#elif defined(__MMI_MAINLCD_320X480__)
    const VfxU32 h1 = 15;
    const VfxU32 h2 = 25;
#else //(__MMI_MAINLCD_480X800__)
    const VfxU32 h1 = 25;
    const VfxU32 h2 = 40;
#endif

    if (artist.isEmpty())
    {
        m_textTitle->setPos(m_textTitle->getPos().x, h1);
    }
    else
    {
        m_textTitle->setPos(m_textTitle->getPos().x, h2);
    }
}

void VappMusicPlayerNowPlayingPage::onTimerCallBack(VfxTimer *timer)
{
    VappMusicPlayerPlayerBase::onTimerCallBack(timer);

    if (m_isLyricsOn && m_panelLyrics)
    {
        m_panelLyrics->updateLyrics(getCurrTime());
    }
}

VfxBool VappMusicPlayerNowPlayingPage::isOnTop()
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    return app->isGroupTopActive() && app->getViewType() == VIEW_TYPE_NOW_PLAYING;
}

VfxBool VappMusicPlayerNowPlayingPage::play(const VfxWString &filePath, VfxBool forcePlay, VfxBool updateCurTime)
{
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        if (m_panelLyrics && m_panelLyrics->hasLyrics() && (forcePlay || !filePath.isEmpty()))
        {
            // Force to update highlight before play
            if (m_isLyricsOn && m_panelLyrics->hasLyrics() && updateCurTime)
            {
                m_panelLyrics->updateLyrics(getCurrTime(), VFX_FALSE, VFX_TRUE);
            }
        }
    }

    return VappMusicPlayerPlayerBase::play(filePath, forcePlay, updateCurTime);
}

void VappMusicPlayerNowPlayingPage::setAlbumCover(VfxU32 songId, VfxWString &filePath, VappMusicPlayerPageSwitchDirEnum dir)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_NOW_PLAY_SET_ALBUM_COVER);

    VfxFrame *newPage;
    VFX_OBJ_CREATE(newPage, VfxFrame, m_pagePanelArtwork);
    newPage->setIsOpaque(VFX_TRUE);
    newPage->setAnchor(0.5f, 0.5f);
    newPage->setSize(m_pagePanelArtwork->getSize());
    newPage->setPos(m_pagePanelArtwork->getSize().width / 2, m_pagePanelArtwork->getSize().height / 2);
    newPage->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_GRID_BG));
    newPage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VfxImageBuffer imgBuf;
    imgBuf.ptr = NULL;
    imgBuf.width = 0;
    imgBuf.height = 0;

    // decide the size of album cover
    VfxU32 coverWidth = 0;
    VfxU32 coverHeight = 0;
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        coverWidth = VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH;
        coverHeight = VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT;
    }
    else
    {
#if defined(__MMI_MAINLCD_240X320__)
    VfxSize coverSize(123, 123);
#elif defined(__MMI_MAINLCD_240X400__)
    VfxSize coverSize(123, 123);
#elif defined(__MMI_MAINLCD_320X480__)
    VfxSize coverSize(197, 197);
#else //(__MMI_MAINLCD_480X800__)
    VfxSize coverSize(234, 234);
#endif

        coverWidth = coverSize.height;
        coverHeight = coverSize.height;
    }

    // check and parse the album cover
    VfxBool useDefault = VFX_FALSE;
    if ((songId > 0) && getAlbumCoverBySongId(songId, coverWidth, coverHeight, imgBuf))
    {
        useDefault = VFX_FALSE;
    }
    else if (filePath.isNull() || filePath.isEmpty())
    {
        useDefault = VFX_TRUE;
    }
    else if (m_pageMode == PAGE_MODE_CUI
     && m_metaParser
     && m_metaParser->parseFile(filePath)
     && m_metaParser->getCover(coverWidth, coverHeight, imgBuf))
    {
        useDefault = VFX_FALSE;
    }
    else
    {
        useDefault = VFX_TRUE;
    }


    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        if (useDefault)
        {
            // normal mode using default disk image

            VfxFrame *image;
            VFX_OBJ_CREATE(image, VfxFrame, newPage);
            
            image->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_DISK));
            image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

            // Set cover position, no width height need here
            setAlbumCoverPos(image, PAGE_MODE_NORMAL, VFX_TRUE, 0, 0);

            m_shadow = NULL;
            m_albumCover = image;
        }
        else
        {
            // normal mode using parsed album cover
            VfxImageSrc imgSrc;
            imgSrc.setImageBuffer(imgBuf);

            VfxImageFrame *image;
            VFX_OBJ_CREATE(image, VfxImageFrame, newPage);
            image->setBorder(VRT_COLOR_BLACK, 1);
            image->setImgContent(imgSrc);
            image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
            image->setIsOpaque(VFX_TRUE);
            image->setAnchor(0.5f, 0.5f);
            image->setCacheMode(VFX_CACHE_MODE_FREEZE);

            // Set cover position
            setAlbumCoverPos(image, PAGE_MODE_NORMAL, VFX_FALSE, newPage->getSize().width, newPage->getSize().height);

            // If image smaller than this size, let frame resize it
            VfxSize imageSize(imgSrc.getSize());
            VfxS32 shadow_w = imageSize.width;
            VfxS32 shadow_h = imageSize.height;
            if(!useDefault && imageSize.width < SRV_PLST_ARTWORK_RESIZED_WIDTH && imageSize.height< SRV_PLST_ARTWORK_RESIZED_HEIGHT)
            {
                VfxS32 w, h;
                if (imageSize.width > imageSize.height)
                {
                    w = SRV_PLST_ARTWORK_RESIZED_WIDTH;
                    h = SRV_PLST_ARTWORK_RESIZED_HEIGHT * (VfxFloat(imageSize.height) / imageSize.width);
                }
                else if (imageSize.width < imageSize.height)
                {
                    h = SRV_PLST_ARTWORK_RESIZED_HEIGHT;
                    w = SRV_PLST_ARTWORK_RESIZED_WIDTH * (VfxFloat(imageSize.width) / imageSize.height);
                }
                else
                {
                    w = SRV_PLST_ARTWORK_RESIZED_WIDTH;
                    h = SRV_PLST_ARTWORK_RESIZED_HEIGHT;
                }

                image->setSize(w, h);
                shadow_w = w;
                shadow_h = h;
            }

            // drop shadow
            VfxRect r(image->getPos().x - shadow_w / 2,
                      image->getPos().y - shadow_h / 2,
                      shadow_w,
                      shadow_h);
            m_shadow = dropShadow(newPage, r, VFX_FALSE);

            m_albumCover = image;
        }
    }
    else
    {
        // CUI mode using the same layout
        VfxImageSrc imgSrc;
        
        if (useDefault)
        {   
            VfxFrame *image;
            VFX_OBJ_CREATE(image, VfxFrame, newPage);
            setDefaultCover(image, VFX_TRUE, 0, 0, VFX_TRUE);
            m_albumCover = image;
        }
        else
        {
            VfxImageFrame *image;
            VFX_OBJ_CREATE(image, VfxImageFrame, newPage);
            image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
            
            imgSrc.setImageBuffer(imgBuf);
            image->setImgContent(imgSrc);

            m_albumCover = image;
        }

        VfxFrame *image = m_albumCover;

        image->setBorder(VRT_COLOR_BLACK, 1);
        image->setAnchor(0.5f, 0.5f);
        image->setIsOpaque(VFX_TRUE);
        
        // Set cover position, same position in default image and album cover
        setAlbumCoverPos(image, PAGE_MODE_CUI, VFX_TRUE, newPage->getSize().width, newPage->getSize().height);

        // If image smaller than this size, let frame resize it
        VfxSize imageSize(imgSrc.getSize());
    
        VfxU32 shadow_w = 0;
        VfxU32 shadow_h = 0;
        if (useDefault)
        {
            shadow_w = image->getSize().width;
            shadow_h = image->getSize().height;
        }
        else
        {
            shadow_w = imageSize.width;
            shadow_h = imageSize.height;
        }

        if(!useDefault && imageSize.width < SRV_PLST_ARTWORK_RESIZED_WIDTH && imageSize.height< SRV_PLST_ARTWORK_RESIZED_HEIGHT)
        {
            VfxS32 w, h;
            if (imageSize.width > imageSize.height)
            {
                w = SRV_PLST_ARTWORK_RESIZED_WIDTH;
                h = SRV_PLST_ARTWORK_RESIZED_HEIGHT * (VfxFloat(imageSize.height) / imageSize.width);
            }
            else if (imageSize.width < imageSize.height)
            {
                h = SRV_PLST_ARTWORK_RESIZED_HEIGHT;
                w = SRV_PLST_ARTWORK_RESIZED_WIDTH * (VfxFloat(imageSize.width) / imageSize.height);
            }
            else
            {
                w = SRV_PLST_ARTWORK_RESIZED_WIDTH;
                h = SRV_PLST_ARTWORK_RESIZED_HEIGHT;
            }

            image->setSize(w, h);
            shadow_w = w;
            shadow_h = h;
        }

        // drop shadow
        VfxRect r(image->getPos().x - shadow_w / 2,
                  image->getPos().y - shadow_h / 2,
                  shadow_w,
                  shadow_h);
        m_shadow = dropShadow(newPage, r, VFX_FALSE);
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

    m_curPage = newPage;
}

void VappMusicPlayerNowPlayingPage::setAlbumCoverPos(VfxFrame *image, VappMusicPlayerPageModeEnum page_mode, VfxBool useDefault, VfxS32 width, VfxS32 height)
{
    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        // normal mode using default disk image
        if (useDefault)
        {
        #if defined(__MMI_MAINLCD_240X320__)
            image->setSize(230, 262);
            image->setPos(4, 55 - MMI_STATUS_BAR_HEIGHT);
        #elif defined(__MMI_MAINLCD_240X400__)
            image->setSize(230, 262);
            image->setPos(4, 61 - MMI_STATUS_BAR_HEIGHT);
        #elif defined(__MMI_MAINLCD_320X480__)
            image->setSize(310, 339);
            image->setPos(11, 40 - MMI_STATUS_BAR_HEIGHT);
        #else //(__MMI_MAINLCD_480X800__)
            image->setSize(460, 503);
            image->setPos(11, 132 - MMI_STATUS_BAR_HEIGHT);
        #endif
        }
        else
        {
        #if defined(__MMI_MAINLCD_240X320__)
            image->setPos(width / 2, (height - 36) / 2);
        #elif defined(__MMI_MAINLCD_240X400__)
            image->setPos(width / 2, (height - 36) / 2);
        #elif defined(__MMI_MAINLCD_320X480__)
            image->setPos(width / 2, (height - 47) / 2);
        #else //(__MMI_MAINLCD_480X800__)
            image->setPos(width / 2, (height - 90) / 2);
        #endif  
        }
    }
    else
    {
        // CUI mode using the same layout in default image and album cover
    #if defined(__MMI_MAINLCD_240X320__)
        if (isPortrait())
        {
            image->setPos(width / 2, height / 2 - 22);
        }
        else
        {
            image->setPos(width / 2, height / 2);
        }
    #elif defined(__MMI_MAINLCD_240X400__)
        image->setPos(width / 2, height / 2);         
    #elif defined(__MMI_MAINLCD_320X480__)
        image->setPos(width / 2, height / 2 - 22);
    #else //(__MMI_MAINLCD_480X800__)
        image->setPos(width / 2, height / 2);
    #endif
    }
}


void VappMusicPlayerNowPlayingPage::onAlbumCoverSwitched(VfxFrame *f, VfxBool isComplete)
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->resetPenInput();
    }

    if (m_pageMode == PAGE_MODE_NORMAL)
    {
        // handle lyrics for the interrupted case

        VfxU32 activeIdx = m_mplayerSrv->getActiveIndex();
        if (m_mplayerSrv->getSongValid(activeIdx) && m_mplayerSrv->getSongLyricsState(activeIdx))
        {
            initLyricsPanel(m_mplayerSrv->getActiveFilePath());

            if (m_panelLyrics->hasLyrics())
            {
                // update lyrics position without animation                
                m_panelLyrics->updateLyrics(getCurrTime(), VFX_FALSE, VFX_TRUE);
            }
        }
    }
}

void VappMusicPlayerNowPlayingPage::updateLyrics(void)
{
    // Update even panel off, it may seek in cover flow mode
    if (m_panelLyrics)
    {
        m_panelLyrics->updateLyrics(getCurrTime(), VFX_FALSE, VFX_TRUE);
    }
}

void VappMusicPlayerNowPlayingPage::clearLyrics()
{
    if (m_panelLyrics)
    {
        m_panelLyrics->clearLyrics();

        m_panelLyrics->showHidePanel(VFX_FALSE, isOnTop());
    }
}

void VappMusicPlayerNowPlayingPage::setEmpty()
{
    VappMusicPlayerPlayerBase::setEmpty();
    
    setFavoriteBtn(VFX_TRUE);
    m_btnFavorite->setIsDisabled(VFX_TRUE);
}

/***************************************************************************** 
 * VappMusicPlayerLyricsPanel implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerLyricsPanel", VappMusicPlayerLyricsPanel, VfxFrame);

void VappMusicPlayerLyricsPanel::onInit()
{
    VfxFrame::onInit();

    initPanel();
    showHidePanel(VFX_FALSE);
}

void VappMusicPlayerLyricsPanel::onDeinit()
{
    deinitLyrics();

    VfxFrame::onDeinit();
}

void VappMusicPlayerLyricsPanel::initPanel()
{
    setAnchor(0.0f, 1.0f);        
    setSize(GDI_LCD_WIDTH, PanelHeight);

    VFX_OBJ_CREATE(m_bgFrame, VfxFrame, this);
    m_bgFrame->setPos(0, 0);
    m_bgFrame->setSize(getSize());
    m_bgFrame->setAutoAnimate(VFX_TRUE);
    m_bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_LYRICS));
    m_bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_textView, VcpTextView, m_bgFrame);
    m_textView->setPos(0, 0);
    m_textView->setSize(m_bgFrame->getSize());
    m_textView->setContentSize(VfxSize(GDI_LCD_WIDTH, 4000));
    m_textView->setMargins(MarginLR, MarginTB, MarginLR, MarginTB);
    m_textView->setHint(VFX_WSTR(""));
    m_textView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_textView->setAutoAnimate(VFX_TRUE);
    m_textView->setLineGap(LineGap);
    m_textView->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FontSize)));
    m_textView->setMinLineHeight(LineHeight - LineGap);
    m_textView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VRT_COLOR_SILVER);
    m_textView->setVerticalAlignMode(VCP_TEXT_VERT_ALIGN_MODE_TOP);
    m_textView->setScrollIndicatorStyle(VcpScrollable::VC_SCROLLABLE_SCROLL_INDICATOR_STYLE_NONE);
    m_textView->enableVerticalScrollIndicator(VFX_FALSE);
    m_textView->setIsDisabled(VFX_TRUE);

    // No need to show shadow to avoid color banding problem
    //VfxFrame *shadow = NULL;
    //VFX_OBJ_CREATE(shadow, VfxFrame, m_bgFrame);
    //shadow->setSize(m_bgFrame->getSize());
    //shadow->setPos(0, 0);
    //shadow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_LYRICS_SHADOW));
    //shadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}

VfxBool VappMusicPlayerLyricsPanel::initLyrics(VfxWChar *lyricFilePath)
{
    if (VFX_WSTR_MEM(lyricFilePath) == m_lyricsFilePath)
    {
        return VFX_TRUE;
    }

    deinitLyrics();

    m_lyricsFilePath.loadFromMem(lyricFilePath);

    m_lyricsData = lyrics_parse_create(
                        VAPP_MUSICPLY_UPDATE_LYRICS_TIME,
                        VappMusicPlayerLyricsAllocMem, 
                        VappMusicPlayerLyricsFreeMem,
                        NULL); 
    
    VfxBool ret = VFX_FALSE;

    if (m_lyricsData)
    {
        ret = parseLyrics(lyricFilePath);   
    }

    if (!ret)
    {
        deinitLyrics();
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LYRIC_PANEL_INIT_FAIL);
        return VFX_FALSE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LYRIC_PANEL_INIT);

    // Load the string into component
    VfxU32 lineCount = m_lyricsData->line_count;

    VfxU32 allocSize = sizeof(VfxU32)*lineCount;

    // m_lyricsLineNum keeps the line index of each line in text view
    VFX_ALLOC_MEM(m_lyricsLineNum, allocSize, this);
    memset(m_lyricsLineNum, 0, allocSize);
    
    // m_lyricsCharIdx keeps the character index of each line in text view
    VFX_ALLOC_MEM(m_lyricsCharIdx, allocSize, this);
    memset(m_lyricsCharIdx, 0, allocSize);
    
    // m_lyricsIdxTable keeps the converted line index in m_lyricsData to index in text view
    VFX_ALLOC_MEM(m_lyricsIdxTable, allocSize, this);
    memset(m_lyricsIdxTable, 0, allocSize);

    VfxU32 *lyricsLineCount, *lyricsCharCount;

    // lyricsLineCount keeps the line count of each line in text view
    VFX_ALLOC_MEM(lyricsLineCount, allocSize, this);
    memset(lyricsLineCount, 0, allocSize);
    
    // lyricsCharCount keeps the character count of each line
    VFX_ALLOC_MEM(lyricsCharCount, allocSize, this);
    memset(lyricsCharCount, 0, allocSize);
    
    VfxWString strLyrics;
    VfxWString str;

    VfxU32 m_firstLineIdx = lyrics_get_line(m_lyricsData, 0);

    for (VfxU32 idx = m_firstLineIdx, idx2 = 0; idx < LYRICS_MAX_LINES; idx = m_lyricsData->lines_p[idx].id_next, ++idx2)
    {
        str.setEmpty();
        str.loadFromMem(m_lyricsData->lines_p[idx].st_text);

        if (str.isEmpty())
        {
            str.format("\n");
        }
        else
        {
            str += VFX_WSTR("\n");
        }
        strLyrics += str;

        // calculate the line number of current string
        m_textView->setText(m_lyricsData->lines_p[idx].st_text);
        m_textView->forceUpdate();
        lyricsLineCount[idx] = m_textView->getLineCount();

        // add 1 because of the "\n"
        lyricsCharCount[idx] = m_lyricsData->lines_p[idx].ln_text + 1;

        m_lyricsIdxTable[idx] = idx2;
    }

    // fill the m_lyricsLineNum and m_lyricsCharIdx
    for (VfxU32 idx = m_firstLineIdx, count = 0; count < lineCount; idx = m_lyricsData->lines_p[idx].id_next, ++count)
    {
        if (idx >= LYRICS_MAX_LINES)
        {
            break;
        }
        
        if (count == 0)
        {
            m_lyricsLineNum[count] = 0;
            m_lyricsCharIdx[count] = 0;
        }
        else
        {
            VfxU32 prevIdx = m_lyricsData->lines_p[idx].id_prev;
            m_lyricsLineNum[count] = m_lyricsLineNum[count - 1] + lyricsLineCount[prevIdx];
            m_lyricsCharIdx[count] = m_lyricsCharIdx[count - 1] + lyricsCharCount[prevIdx];
        }
    }

    // add 4 empty lines to add more space so that last lyrics line can scroll out the top of text view
    strLyrics += VFX_WSTR("\n\n\n\n");

    //m_textView->scroll(0, -m_currYPos);
    m_textView->setText(strLyrics);
    m_textView->forceUpdate();
    m_textView->scrollToStart();

    m_currYPos = 0;

    VFX_FREE_MEM(lyricsLineCount);
    VFX_FREE_MEM(lyricsCharCount);

    return VFX_TRUE;
}

void VappMusicPlayerLyricsPanel::deinitLyrics()
{
    if (m_lyricsData)
    {
        lyrics_parse_release();
        m_lyricsData = NULL;
        m_textView->setText(VFX_WSTR(""));
        m_currLineID = -1;
    }

    if (m_lyricsLineNum)
    {
        VFX_FREE_MEM(m_lyricsLineNum);
        m_lyricsLineNum = NULL;
    }

    if (m_lyricsCharIdx)
    {
        VFX_FREE_MEM(m_lyricsCharIdx);
        m_lyricsCharIdx = NULL;
    }

    if (m_lyricsIdxTable)
    {
        VFX_FREE_MEM(m_lyricsIdxTable);
        m_lyricsIdxTable = NULL;
    }

    m_lyricsFilePath.setEmpty();
}

S32 getFontSize(UI_string_type text, S32 n)
{
    return 18;
}

VfxBool VappMusicPlayerLyricsPanel::parseLyrics(VfxWChar *lyricFilePath)
{
    if (lyricFilePath)
    {
        U8 ret = lyrics_parse_file(lyricFilePath);

        if (ret == LYRICS_ERR_NONE)
        {
            m_hasLyrics = VFX_TRUE;

            lyrics_format_line(
                m_lyricsData, 
                0xFFFF,         // assume the screen width is very long so that one single line won't be seperated
                m_duration, 
                &getFontSize);
        }
        else
        {
            // parse file error
            m_hasLyrics = VFX_FALSE;
            return VFX_FALSE;
        }
    }
    else
    {
        m_hasLyrics = VFX_FALSE;
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

void VappMusicPlayerLyricsPanel::updateLyrics(VfxU32 currTime, VfxBool isAnim, VfxBool forceUpdate)
{
    m_currTime = currTime;

    if (m_lyricsData)
    {
        VfxU32 lineID = lyrics_get_line(m_lyricsData, currTime / VAPP_MUSICPLY_UPDATE_DURATION_TIME);

        if (lineID != m_currLineID || forceUpdate)
        {
            VfxU32 newLineID = m_lyricsIdxTable[lineID];

            VfxU32 charIdxStart = m_lyricsCharIdx[newLineID];
            VfxU32 charIdxEnd = charIdxStart + m_lyricsData->lines_p[lineID].ln_text;

            VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(FontSize), VFX_FE1_9);
            VcpRichText format;
            format.setFont(font);
            format.setRange(charIdxStart, charIdxEnd);

            format.setTextColor(VRT_COLOR_MAKE(255, 245, 183, 37));
            m_textView->setTextFormat(&format);

            if (newLineID == 0)
            {
                m_textView->scroll(0, -m_currYPos);

                m_currYPos = 0;
            }
            else
            {
                VfxU32 prevID = m_lyricsIdxTable[m_lyricsData->lines_p[lineID].id_prev];
                VfxU32 line = prevID >= LYRICS_MAX_LINES ? 0 : m_lyricsLineNum[prevID]; // prevID >= LYRICS_MAX_LINES is the first line case
                if (prevID > 1)
                {
                    // adjust current line to be placed at the 2nd line
                    line += m_lyricsLineNum[newLineID] - m_lyricsLineNum[prevID] - 1;
                }

                if (m_currYPos != LineHeight * line)
                {
                    m_currYPos = LineHeight * line + 1;

                    VfxRect viewBounds = m_textView->getViewBounds();

                    VfxS32 offset = m_currYPos - viewBounds.origin.y;

                    VappMusicPlayerNowPlayingPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerNowPlayingPage);

                    m_textView->scroll(0, offset, isAnim && page->isOnTop());
                }
            }
            m_currLineID = lineID;
        }
    }
}

void VappMusicPlayerLyricsPanel::clearLyrics()
{
    m_hasLyrics = VFX_FALSE;    
    deinitLyrics();
}

VfxBool VappMusicPlayerLyricsPanel::hasLyrics()
{
    return m_hasLyrics;
}

VfxWString VappMusicPlayerLyricsPanel::getLyricsFilePath()
{
    return m_lyricsFilePath;
}

VfxBool VappMusicPlayerLyricsPanel::isShow()
{
    return m_bgFrame->getPos().y == 0;
}

void VappMusicPlayerLyricsPanel::showHidePanel(VfxBool show, VfxBool isAnimate)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LYRIC_PANEL_SHOW_HIDE, show);

    if ((show && isShow()) || (!show && !isShow()))
    {
        return;
    }

    // Disable the animation
    if(!isAnimate)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
    }

    if (show)
    {
        m_bgFrame->setPos(0, 0);
    }
    else
    {
        m_bgFrame->setPos(0, getParentFrame()->getSize().height);
    }

    if(!isAnimate)
    {
        VfxAutoAnimate::commit();
    }
}

#endif //__COSMOS_MUSICPLY__
