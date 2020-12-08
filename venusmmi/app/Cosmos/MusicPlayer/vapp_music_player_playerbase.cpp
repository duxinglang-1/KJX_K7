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
 *  vapp_music_player_playerbase.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player player base class
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

#include "vapp_music_player.h"
#include "vapp_music_player_playerbase.h"
#include "vapp_music_player_datatype.h"
#include "vapp_music_player_util.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "mmi_rp_srv_status_icons_def.h"

extern "C"
{
#include "aud_defs.h"
#include "med_main.h"
}

#define VAPP_MUSICPLY_UPDATE_DURATION_TIME 250
#define VAPP_MUSICPLY_MAXIMUN_TIME 999 * 60 * 1000 + 59 * 1000

/***************************************************************************** 
 * VappMusicPlayerPlayerBase Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerPlayerBase", VappMusicPlayerPlayerBase, VfxPage);

void VappMusicPlayerPlayerBase::onInit()
{
    VfxPage::onInit();
    
    m_mplayerSrv = getMusicPlayerSrv();

    initUI();

    // Get NCenter singleton and connect signal
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (NCenter)
    {
        NCenter->m_signalEvent.connect(this, &VappMusicPlayerPlayerBase::onNCenterStatus);
    }
}

void VappMusicPlayerPlayerBase::onDeinit()
{
    closeMetaParser();

    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (NCenter)
    {
        NCenter->m_signalEvent.disconnect(this, &VappMusicPlayerPlayerBase::onNCenterStatus);
    }

    VfxPage::onDeinit();
}

void VappMusicPlayerPlayerBase::onEnter(VfxBool isBackward)
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->updateWaitIconPos();
    }

    // store current status bar background
    m_preStatusBarBgID = getStatusBarBg();

    // set status bar background to black
    setStatusBarBg(WGUI_IMG_STATUS_BAR_SPECIAL_BKG);

    updateTimeInfo();

    // start update slider timer when page entering
    if (m_timerSlider && m_ctrlPlayback && m_ctrlPlayback->getPlayState() == PB_STATE_PLAY)
    {
        m_timerSlider->start();
    }

    if (m_ctrlPlayback && app)
    {
        // initialize UI state
        vfxPostInvoke1(this, &VappMusicPlayerPlayerBase::onPlaybackStateChange, m_ctrlPlayback->getPlayState());
    }
}

void VappMusicPlayerPlayerBase::onExit(VfxBool isBackward)
{
    m_timerPlayPause->stop();

    onKeyAbort();
}

void VappMusicPlayerPlayerBase::onExited()
{
    // stop update slider timer when page can't be seen
    if (m_timerSlider)
    {
        m_timerSlider->stop();
    }
}

void VappMusicPlayerPlayerBase::onNCenterStatus(VappNCenterEventEnum evt)
{
    switch (evt)
    {
        case VAPP_NCENTER_EVENT_ENTERED:
            onKeyAbort();
            break;
            
        default:
            break;
    }
}

void VappMusicPlayerPlayerBase::restoreStatusBarBG()
{
    vfxPostInvoke1(this, &VappMusicPlayerPlayerBase::setStatusBarBg, VfxResId(WGUI_IMG_STATUS_BAR_BKG));
}

void VappMusicPlayerPlayerBase::onBack()
{
    VfxPage::onBack();
}

void VappMusicPlayerPlayerBase::initUI()
{
    // initialize UI here

    if(m_timerPlayPause == NULL)
    {
        VFX_OBJ_CREATE(m_timerPlayPause, VfxTimer, this);
        m_timerPlayPause->setStartDelay(0);
        m_timerPlayPause->m_signalTick.connect(this, &VappMusicPlayerPlayerBase::onEventHandlerTimerCallback);
    }
}

VcpImageButton* VappMusicPlayerPlayerBase::createButton(VfxFrame *parent, VfxRect rect, VfxId id, VcpStateImage stateImg)

{   
    VcpImageButton *btn = NULL;
    VFX_OBJ_CREATE(btn, VcpImageButton, parent);
    btn->setRect(rect);
    btn->setId(id);
    btn->setImage(stateImg);
    btn->m_signalClicked.connect(this, &VappMusicPlayerPlayerBase::eventHandler);

    return btn;
}

VcpButton* VappMusicPlayerPlayerBase::createButtonEx(VfxFrame *parent, VfxRect rect, VfxId id, VcpStateImage fgImg, VcpStateImage bgImg)
{   
    VcpButton *btn = NULL;
    VFX_OBJ_CREATE(btn, VcpButton, parent);
    btn->setRect(rect);
    btn->setId(id);
    btn->setImage(fgImg);
    btn->setBgImageList(bgImg);
    btn->setMargin(0, 0, 0, 0);
    btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    btn->m_signalClicked.connect(this, &VappMusicPlayerPlayerBase::eventHandler);

    return btn;
}

void VappMusicPlayerPlayerBase::setCtrlPlayback(VappMusicPlayerCtrlPlayback *ctrl)
{
    if (ctrl)
    {
        m_ctrlPlayback = ctrl;
        m_ctrlPlayback->m_signalPlaybackStateChange.connect(this, &VappMusicPlayerPlayerBase::onPlaybackStateChange);

        if((m_ctrlPlayback->getPlayState() != PB_STATE_NONE) && (m_ctrlPlayback->getPlayState() != PB_STATE_CLOSE))
        {
            // set flag to block pause if not support pause, no file path needed since the playback is open
            m_isSongPausable = m_ctrlPlayback->isSongPausable(NULL);

            // disable seek bar if not support seek, no file path needed since the playback is open
            m_isSongSeekable = m_ctrlPlayback->isSongSeekable(NULL);
        }
    }
}

VfxBool VappMusicPlayerPlayerBase::onPenInput(VfxPenEvent &event)
{
    return VfxPage::onPenInput(event);
}

VappMusicPlayerGesture VappMusicPlayerPlayerBase::translateGesture(const VfxPenEvent &e)
{
    // we track movement by ourselves,
    // because VfxPenEvent may have exactly the same prevPos,
    // which breaks the swipe detection.
    
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
    }
    else if(VFX_PEN_EVENT_TYPE_UP == e.type)
    {
        const VfxS32 cpWidth = getSize().width;
        const int tappingThreshold = cpWidth / 10;
        const int draggingThreshold = cpWidth / 3;

        VappMusicPlayerGesture gesture = VG_NONE;

        do
        {
            const VfxS32 posX = e.pos.x;
            const VfxS32 downPosX = e.downPos.x;
            VfxS32 displace = vfxAbs(posX - downPosX);

            if(tappingThreshold > displace)
            {
                // only move a little, so this is a TAP.
                gesture = VG_TAP;
                break;
            }
            else
            {
                // if swipe very quickly, treat as a GO NEXT/PREV gesture
                const float swipeSpeed = vfxAbs(posX - downPosX) * 1000.0f /
                                         (e.timeStamp - e.downTimeStamp);
                const float speedThreshold = cpWidth / 10.0f;

                if(swipeSpeed > speedThreshold && displace > draggingThreshold)
                {
                    gesture = posX > downPosX ? VG_GO_PREV : VG_GO_NEXT;
                    break;
                }
            }

            // otherwise it depends on current dragging state.
            gesture = VG_RELEASE;
        }while(false);

        return gesture;
    }
    else if(VFX_PEN_EVENT_TYPE_MOVE == e.type)
    {
    }
    return VG_NONE;
}

void VappMusicPlayerPlayerBase::eventHandler(VfxObject *sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYERBASE_EVENT_HDLR, id);

    m_signalCallback.emit(VappMusicPlayerPlayerPageCallbackEnum(id));

    // Handle after emit signal
    switch(id)
    {
        case FUNC_ID_BTN_SETTING:
            break;

        case FUNC_ID_BTN_ADD_TO_FAVORITE:
            break;

        case FUNC_ID_BTN_REPEAT:
            break;

        case FUNC_ID_BTN_SHUFFLE:
            break;

        case FUNC_ID_BTN_BACK_TO_LIST:
            break;

        case FUNC_ID_BTN_NOW_PLAYING_LIST:
            break;

        case FUNC_ID_BTN_PREV:
            prev();
            break;

        case FUNC_ID_BTN_NEXT:
            next();
            break;

        case FUNC_ID_BTN_PLAY_PAUSE:
            playpause();
            break;

        default:
            break;
    };
}

void VappMusicPlayerPlayerBase::onSliderPressed(VcpSlider *slider, VfxFloat downValue)
{
    char buf[50];
    kal_sprintf(buf,"%f", downValue);
    kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MUSICPLY] VappMusicPlayerPlayerBase::onSliderPressed(), down=[%s]", buf);

    m_sliderDragging = VFX_TRUE;

    m_signalCallback.emit(FUNC_ID_SLIDER_PRESSED);
}

void VappMusicPlayerPlayerBase::onSliderReleased(VcpSlider *slider, VfxFloat upValue)
{
    char buf[50];
    kal_sprintf(buf,"%f", upValue);
    kal_prompt_trace(MOD_MMI_MEDIA_APP, "[MUSICPLY] VappMusicPlayerPlayerBase::onSliderReleased(), up=[%s]", buf);

    m_sliderDragging = VFX_FALSE;

    //MAUI_03210887
    PlaybackStateEnum playState = m_ctrlPlayback->getPlayState();
    if ((PB_STATE_SWITCHING_PLAY == playState)
        || (PB_STATE_SWITCHING_NOT_PLAY == playState))
    {
        m_signalCallback.emit(FUNC_ID_SLIDER_RELEASE);
        return;
    }

    if (m_ctrlPlayback)
    {
        if (m_ctrlPlayback->m_playStateBeforeSeek == PB_STATE_NONE)
        {
            m_ctrlPlayback->m_playStateBeforeSeek = m_ctrlPlayback->getPlayState();
        }
        
        stop();
        
        m_ctrlPlayback->seekStart(upValue);
    }

    m_signalCallback.emit(FUNC_ID_SLIDER_RELEASE);
}

void VappMusicPlayerPlayerBase::onSliderValueChange(VcpSlider *slider, VfxFloat newValue)
{
    setTextCurrTime(VfxU32(newValue));
}

void VappMusicPlayerPlayerBase::onTimerCallBack(VfxTimer *timer)
{
    if (!m_sliderDragging)
    {
        updateCurrTime();
    }
}

void VappMusicPlayerPlayerBase::setConsumeDRM(VfxBool consume)
{
    if(m_ctrlPlayback)
    {
        m_ctrlPlayback->setConsumeDRM(consume);
    }
}

VfxBool VappMusicPlayerPlayerBase::open(const VfxWString &filePath)
{
    const VfxBool ret = m_ctrlPlayback->open(filePath);
    updateTimeInfo();
    return ret;
}

VfxBool VappMusicPlayerPlayerBase::play(const VfxWString &filePath, VfxBool forcePlay, VfxBool updateCurTime)
{
    if (forcePlay)
    {
        if(updateCurTime)
        {
            updateTimeInfo();
        }
        else
        {
            // MAUI_03083407 : update duration for seek case only, to avoid slider shake problem. current time shall update in timer later
            if(!m_sliderDragging)
            {
                updateDuration();
            }
        }
        m_ctrlPlayback->play();
        
        return VFX_TRUE;
    }
    else if (!filePath.isEmpty())
    {
        VfxBool openSuccess = VFX_FALSE;
        if (m_ctrlPlayback)
        {
            if (m_ctrlPlayback->getPlayState() == PB_STATE_OPEN)
            {
                openSuccess = VFX_TRUE;
            }
            else if (open(filePath))
            {
                openSuccess = VFX_TRUE;
            }
        }

        if (openSuccess)
        {
            // set flag to block pause if not support pause
            m_isSongPausable = m_ctrlPlayback->isSongPausable(const_cast<VfxWChar*>(filePath.getBuf()));

            // disable seek bar if not support seek
            m_isSongSeekable = m_ctrlPlayback->isSongSeekable(const_cast<VfxWChar*>(filePath.getBuf()));
            if (m_slider)
            {
                m_slider->setIsUnhittable(!m_isSongSeekable);
            }
            
            if (m_ctrlPlayback->m_playStateBeforeSeek != PB_STATE_NONE)
            {
                if(!m_ctrlPlayback->seek(m_ctrlPlayback->m_seekTime))
                {
                    return VFX_FALSE;
                }
            }
            else
            {
                // seek 0 is a work around for getting correct duration if seek to EOF
                if(!m_ctrlPlayback->seek(0))
                {
                    return VFX_FALSE;
                }
            }
            m_ctrlPlayback->play();         

            updateTimeInfo();
        }
        else
        {
            updateDuration();
            updateCurrTime();
        }

        return openSuccess;
    }
}

void VappMusicPlayerPlayerBase::pause()
{
    if (m_ctrlPlayback)
    {
        m_ctrlPlayback->pause();
    }

    if (m_timerSlider)
    {
        m_timerSlider->stop();
    }
}

void VappMusicPlayerPlayerBase::playpause()
{
    m_timerPlayPause->stop();
    m_timerPlayPause->start();

    // Set button first and do action after timeout
    setPlayPauseBtnImage(VFX_TRUE);
}

void VappMusicPlayerPlayerBase::onEventHandlerTimerCallback(VfxTimer *timer)
{
    doPlaypause();

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->resetPenInput();
    }
}

void VappMusicPlayerPlayerBase::doPlaypause()
{
    if (m_ctrlPlayback)
    {
        PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
        if (!m_isSongPausable && (state == PB_STATE_PLAY || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING))
        {
            showErrorMessage(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_NOT_PAUSABLE), VFX_FALSE);
            stop();

            return;
        }

        if (m_ctrlPlayback->m_playStateBeforeSeek == PB_STATE_PAUSE)
        {
            // do seek while pasued
            play(VFX_WSTR(""), VFX_TRUE);
        }
        else if (m_ctrlPlayback->getPlayState() == PB_STATE_CLOSE)
        {
            // play after file closed
            play(m_ctrlPlayback->getFilePath());
        }
        else
        {
            m_ctrlPlayback->playpause();
        }
    }
}

void VappMusicPlayerPlayerBase::seek(VfxU32 time)
{
    if (m_ctrlPlayback)
    {
        m_ctrlPlayback->seek(time);
    }
}

void VappMusicPlayerPlayerBase::stop()
{
    if (m_ctrlPlayback)
    {
        m_ctrlPlayback->stop();
    }

    if (m_timerSlider)
    {
        m_timerSlider->stop();
    }
}

void VappMusicPlayerPlayerBase::closeFile()
{
    if (m_ctrlPlayback && m_ctrlPlayback->getPlayState() != PB_STATE_CLOSE)
    {
        m_ctrlPlayback->closeFile();
    }
}

void VappMusicPlayerPlayerBase::prev()
{
}

void VappMusicPlayerPlayerBase::next()
{
}

void VappMusicPlayerPlayerBase::initMetaParser()
{
    if (m_metaParser == NULL)
    {
        VFX_OBJ_CREATE(m_metaParser, VappMusicPlayerMetaParser, this);
    }
}

void VappMusicPlayerPlayerBase::closeMetaParser()
{
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

    m_metaParserFilePath.setEmpty();

    m_metaParserImgBuf.ptr = NULL;
}

VfxBool VappMusicPlayerPlayerBase::metaParserParseFile(VfxWString &filePath)
{
    if (m_metaParser)
    {
        return m_metaParser->parseFile(filePath);
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerPlayerBase::getAlbumCoverBySongId(VfxU32 songId, VfxU32 width, VfxU32 height, VfxImageBuffer& imgBuf, VfxBool noBG)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYERBASE_GET_ALBUM_COVER_BY_SONG_ID, songId, width, height, noBG);

    // Get album path from list service
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    VappMusicPlayerContentProvider* provider = app->getProvider();

    VfxWString albumFilePath;
    provider->getAlbumCoverPathBySongID(songId, albumFilePath);

    if (!albumFilePath.isEmpty() && albumFilePath == m_metaParserFilePath)
    {
        imgBuf = m_metaParserImgBuf;
        
        return VFX_TRUE;
    }

    if (!albumFilePath.isEmpty())
    {
        // Check if file exists, if not, use album cache image
        if (m_metaParser
            && m_metaParser->parseFile(albumFilePath)
            && m_metaParser->getCover(width, height, imgBuf, noBG))
        {
            m_metaParserFilePath = albumFilePath;

            m_metaParserImgBuf = imgBuf;
            
            return VFX_TRUE;
        }
        else
        {
            m_metaParserFilePath.setEmpty();

            mmi_id appID = getApp()->getGroupId();
            
            if (m_albumCoverBuffer)
            {
                applib_asm_free_r(appID, m_albumCoverBuffer);
            }

            m_albumCoverBuffer = applib_asm_alloc_nc_r(appID, SRV_PLST_ARTWORK_RESIZED_WIDTH * SRV_PLST_ARTWORK_RESIZED_HEIGHT * 2);
            
            if (m_albumCoverBuffer)
            {
                imgBuf.ptr = (VfxU8*)m_albumCoverBuffer;
                getMusicPlayerSrv()->getAlbumCover(songId, imgBuf);
                if(imgBuf.ptr != NULL)
                {
                    return VFX_TRUE;
                }
            }
        }
    }

    m_metaParserFilePath.setEmpty();

    return VFX_FALSE;
}

srv_plst_media_details_struct* VappMusicPlayerPlayerBase::getAudioInfo()
{
    if (m_metaParser)
    {
        return m_metaParser->getAudioInfo();
    }

    return NULL;
}

void VappMusicPlayerPlayerBase::setInfoText(VfxWString &title, VfxWString &artist, VfxWString &songCount)
{
    if (m_textTitle)
    {
        m_textTitle->setString(title);
    }

    if (m_textArtist)
    {
        m_textArtist->setString(artist);
    }

    setSongCountInfoText(songCount);
}

void VappMusicPlayerPlayerBase::setSongCountInfoText(VfxWString &songCount)
{
    if (m_textIndex)
    {
        m_textIndex->setString(songCount);
    }
}

VfxU32 VappMusicPlayerPlayerBase::getDuration()
{
    if (m_ctrlPlayback)
    {
        return m_ctrlPlayback->getDuration();
    }
    else
    {
        return 0;
    }
}

void VappMusicPlayerPlayerBase::getTimeString(VfxWString &strTime, const VfxU32 duration)
{
    if (m_timeDigitNum == 1)
    {
        strTime.format("%01d:%02d", duration/(60*1000), duration%(60*1000)/1000);

        if (m_textCurrTime && m_textTotalTime)
        {
            m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        }
    }
    else if (m_timeDigitNum == 2)
    {
        strTime.format("%02d:%02d", duration/(60*1000), duration%(60*1000)/1000);

        if (m_textCurrTime && m_textTotalTime)
        {
            m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        }
    }
    else
    {
        strTime.format("%03d:%02d", duration/(60*1000), duration%(60*1000)/1000);

        if (m_textCurrTime && m_textTotalTime)
        {
            m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        }
    }
    
}

void VappMusicPlayerPlayerBase::updateDuration()
{
    updateDurationByValue(getDuration());
}

void VappMusicPlayerPlayerBase::updateDurationByValue(VfxU32 duration)
{
    const VfxU32 maxTime = VfxU32(VAPP_MUSICPLY_MAXIMUN_TIME);
    duration = duration <= maxTime ? duration : maxTime;

    // check the min digit
    if (duration < 10 * 60 * 1000)
    {
        m_timeDigitNum = 1;
    }
    else if (duration < 100 * 60 * 1000)
    {
        m_timeDigitNum = 2;
    }
    else
    {
        m_timeDigitNum = 3;
    }
    
    if (m_textTotalTime)
    {
        VfxWString strTotalTime;
        getTimeString(strTotalTime, duration);
        m_textTotalTime->setString(strTotalTime);
    }

    if (m_slider)
    {
        m_slider->setMaxValue(duration);
    }
}

void VappMusicPlayerPlayerBase::updateCurrTime()
{
    VfxU32 currTime = getCurrTime();
    VfxU32 totalTime = getDuration();
    const VfxU32 maxTime = VfxU32(VAPP_MUSICPLY_MAXIMUN_TIME);
    currTime = currTime <= maxTime ? currTime : maxTime;
    currTime = currTime <= totalTime ? currTime : totalTime;
    setTextCurrTime(currTime);
    if (m_slider)
    {
        m_slider->setCurrentValue(currTime);
    }

    //PlaybackStateEnum playState = m_ctrlPlayback->getPlayState();
    
    // If current time > duration, set duration to current time, only update in play state
    /*if((playState == PB_STATE_PLAY) && (currTime > totalTime))
    {
        updateDurationByValue(currTime);
    }
    else if ((playState == PB_STATE_PAUSE || playState == PB_STATE_STOP) && (currTime > totalTime))
    {
        m_slider->setCurrentValue(totalTime);   
        setTextCurrTime(totalTime);
    }*/
}

VfxU32 VappMusicPlayerPlayerBase::getCurrTime()
{
    if (m_ctrlPlayback)
    {
        return m_ctrlPlayback->getCurrTime();
    }
    return 0;
}

void VappMusicPlayerPlayerBase::setTextCurrTime(VfxU32 currTime)
{
    if (m_textCurrTime)
    {
        VfxWString strCurrTime;
        getTimeString(strCurrTime, currTime);
        m_textCurrTime->setString(strCurrTime);
    }
}

void VappMusicPlayerPlayerBase::updateTimeInfo()
{
    if(!m_sliderDragging)
    {
        updateDuration();
        updateCurrTime();
    }
}

void VappMusicPlayerPlayerBase::clearTimeInfo()
{
    m_timeDigitNum = 1;

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

void VappMusicPlayerPlayerBase::setEmpty()
{
    VfxWString emptyStr;
    emptyStr.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_NO_SONG_PLAYING);
    VfxWString str2;
    VfxWString str3;

    setInfoText(emptyStr, str2, str3);
    resetSlider();
    clearTimeInfo();
    m_ctrlPlayback->setPlayState(PB_STATE_NONE);
    m_ctrlPlayback->clearFilePath();
}

void VappMusicPlayerPlayerBase::resetSlider()
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

void VappMusicPlayerPlayerBase::maximizeSlider()
{
    if (m_slider)
    {
        VfxFloat value = m_slider->getMaxValue();
        m_slider->setCurrentValue(value);
    }
}

void VappMusicPlayerPlayerBase::setEnablePlaybackUI(VfxBool isEnable, VfxBool playPauseOnly)
{
    if (!playPauseOnly)
    {
        if (m_slider)
        {
            if(m_isSongSeekable)
            {
                m_slider->setIsUnhittable(!isEnable);
            }
            else
            {
                m_slider->setIsUnhittable(VFX_TRUE);
            }
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
    }

    if (m_btnPlayPause)
    {
        m_btnPlayPause->setIsDisabled(!isEnable);
    }
}

void VappMusicPlayerPlayerBase::setHittablePlaybackUI(VfxBool isHittable)
{
    if (m_slider)
    {
        if(m_isSongSeekable)
        {
            m_slider->setIsUnhittable(!isHittable);
        }
        else
        {
            m_slider->setIsUnhittable(VFX_TRUE);
        }
    }

    if (m_btnPrev)
    {
        m_btnPrev->setIsUnhittable(!isHittable);
    }

    if (m_btnPlayPause)
    {
        m_btnPlayPause->setIsUnhittable(!isHittable);
    }

    if (m_btnNext)
    {
        m_btnNext->setIsUnhittable(!isHittable);
    }
}

void VappMusicPlayerPlayerBase::setPlayPauseBtnImage(VfxBool showReversePlay)
{
    if (m_btnPlayPause)
    {
        VfxBool isPlayImage = m_ctrlPlayback->getPlayPauseState();

        // Show reverse icon before play/pause request
        if(showReversePlay)
        {
            isPlayImage = !isPlayImage;
        }

        if (isPlayImage)
        {
            m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D, 0));
        }
        else
        {
            m_btnPlayPause->setImage(VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_N, IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_N, 0, 0));
        }
    }
}

void VappMusicPlayerPlayerBase::showErrorMessage(VfxWString str, VfxBool startTimer)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYERBASE_SHOW_ERROR, startTimer);

    m_mplayerSrv->stopPlaybackErrTimer();

    if (startTimer)
    {
        m_mplayerSrv->startPlaybackErrTimer();    
        
        m_ctrlPlayback->registerInterruptCallback(VFX_TRUE);

        m_strErrorMsg = str;
    }

    // use balloon to show error message now
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        const_cast<WCHAR*>(str.getBuf()));
}

VfxBool VappMusicPlayerPlayerBase::onPlaybackErrTimerTimeout()
{
    VfxBool ret = VFX_FALSE;

    if (m_strErrorMsg != VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_ERROR_NOT_PAUSABLE))
    {
        ret = VFX_TRUE;
    }

    clearErrorMessage();

    return ret;
}

void VappMusicPlayerPlayerBase::clearErrorMessage()
{
    m_strErrorMsg.setEmpty();

    m_mplayerSrv->stopPlaybackErrTimer();
}

void VappMusicPlayerPlayerBase::MDICallbackHandler(kal_int32 cb)
{
    switch (cb)
    {
        case MDI_AUDIO_DUR_UPDATED:
            updateDuration();
            break;

        case AUD_SEEK_REASON_DONE:
            break;

        case AUD_SEEK_REASON_TERMINATED:
            break;

        case AUD_SEEK_REASON_FAIL:
            break;

        case VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT:
            // stop the UI update timer
            stop();
            
            m_mplayerSrv->stopPlaybackErrTimer();

            break;

    };
}

void VappMusicPlayerPlayerBase::onPlaybackStateChange(PlaybackStateEnum state)
{
    /* Update seekable and pausable state for player base after open */
    if(PB_STATE_OPEN == state)
    {
        m_isSongSeekable = m_ctrlPlayback->isSongSeekable(NULL);
        m_isSongPausable = m_ctrlPlayback->isSongPausable(NULL);
    }

    VfxBool isEnable = (m_ctrlPlayback != NULL)
                    && (getMusicPlayerSrv()->isMakingCall() == VFX_FALSE)
                    && (state != PB_STATE_NONE);

    setEnablePlaybackUI(isEnable);

    if (isEnable)
    {
        VfxBool isHittable = state != PB_STATE_SEEKING
                          && state != PB_STATE_BT_CONNECTING
                          && state != PB_STATE_BT_CONNECTING_WHILE_PLAYING
                          && state != PB_STATE_BT_CONNECTING_WHILE_RESUME
                          && state != PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED;
        
        setHittablePlaybackUI(isHittable);
    }

    // Playback fail or interrupted in playback fail state, do not enable UI
    InterruptStruct interrupt = m_ctrlPlayback->getInterruptedInfo();
    if ((state == PB_STATE_PLAYBACK_FAIL) || (interrupt.isInterrupted && (interrupt.state == PB_STATE_PLAYBACK_FAIL)))
    {
        // block slider and pause button on playback fail
        if (m_slider)
        {
            m_slider->setIsUnhittable(VFX_TRUE);
        }

        if (m_btnPlayPause)
        {
            m_btnPlayPause->setIsUnhittable(VFX_TRUE);
            // Gray the play button on playback fail
            m_btnPlayPause->setIsDisabled(VFX_TRUE);        
        }
    }
    else if (state == PB_STATE_SWITCHING_PLAY || state == PB_STATE_SWITCHING_NOT_PLAY)
    {
        // block slider when switching song
        if (m_slider)
        {
            m_slider->setIsUnhittable(VFX_TRUE);
        }

        // Do not act for play button when switching songs
        if (m_btnPlayPause)
        {
            m_btnPlayPause->setIsUnhittable(VFX_TRUE);
        }
    }
    //else if (interrupt.isInterrupted && interrupt.state == PB_STATE_PLAY)
    //{
     //   setHittablePlaybackUI(VFX_FALSE);
    //}
    
    if (state == PB_STATE_STOP 
     || state == PB_STATE_PAUSE
     || state == PB_STATE_CLOSE
     || state == PB_STATE_SWITCHING_PLAY
     || state == PB_STATE_SWITCHING_NOT_PLAY
     || state == PB_STATE_PLAYBACK_FAIL)
    {
        // should abort any pressing key
        onKeyAbort();
    }

    setPlayPauseBtnImage();

    /* If song is not pausable, it will stop when user press pause. Update current time here */
    if (state == PB_STATE_STOP && !m_isSongPausable)
    {
        updateCurrTime();
        resetSlider();
    }

    // Update current time for pause state to show precise pause time
    if (state == PB_STATE_PAUSE
     || state == PB_STATE_SEEKING)
    {
        updateCurrTime();
    }

    if (m_timerSlider)
    {
        if (state == PB_STATE_PLAY)
        {
            m_timerSlider->start();
        }
        else
        {
            m_timerSlider->stop();
        }
    }
}

VfxBool VappMusicPlayerPlayerBase::onKeyInput(VfxKeyEvent &event)
{
    VfxBool bHandled = VFX_FALSE;

    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        back();

        // Return False here, 'cause we want the key event pass to screen level to process view control
        return VFX_FALSE;
    }

    // Handle for CSK, Arrow key
    switch(event.keyCode)
    {
        case VFX_KEY_CODE_ENTER:
            if(m_btnPlayPause && (m_btnPlayPause->getIsDisabled() || m_btnPlayPause->getIsUnhittable()))
            {
                break;
            }

            // Do not act while change song
            if(m_ctrlPlayback->getPlayState() == PB_STATE_SWITCHING_PLAY || m_ctrlPlayback->getPlayState() == PB_STATE_SWITCHING_NOT_PLAY)
            {
                // restore button image
                if (m_isKeyDown && event.type == VFX_KEY_EVENT_TYPE_UP && m_btnPlayPause)
                {
                    m_btnPlayPause->setState(VCP_BUTTON_STATE_NORMAL);
                    bHandled = VFX_TRUE;
                }

                break;
            }
            
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                if (m_btnPlayPause)
                {
                    m_isKeyDown = VFX_TRUE;
                    m_btnPlayPause->setState(VCP_BUTTON_STATE_PRESSED);
                    bHandled = VFX_TRUE;
                }
            }
            else if (event.type == VFX_KEY_EVENT_TYPE_UP && m_isKeyDown)
            {
                if (m_btnPlayPause)
                {
                    m_btnPlayPause->setState(VCP_BUTTON_STATE_NORMAL);
                }
                m_signalCallback.emit(FUNC_ID_BTN_PLAY_PAUSE);
                playpause();
                bHandled = VFX_TRUE;
            }
            break;

        case VFX_KEY_CODE_ARROW_RIGHT:
            if(m_btnNext && !m_btnNext->getIsDisabled() && !m_btnNext->getIsUnhittable())
            {
                onKeyPrevNext(event.type, m_btnNext, VFX_TRUE);
                bHandled = VFX_TRUE;
            }
            break;

        case VFX_KEY_CODE_ARROW_LEFT:
            if(m_btnPrev && !m_btnPrev->getIsDisabled() && !m_btnPrev->getIsUnhittable())
            {
                onKeyPrevNext(event.type, m_btnPrev, VFX_FALSE);
                bHandled = VFX_TRUE;
            }
            break;

        default:
            break;
    }

    // Clear key down when key up
    if(event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        m_isKeyDown = VFX_FALSE;
    }

    if (bHandled)
    {
        return VFX_TRUE;
    }

    return VfxPage::onKeyInput(event);
}

void VappMusicPlayerPlayerBase::onKeyPrevNext(VfxKeyEventTypeEnum key_type, VcpButton *btn, VfxBool is_next)
{
    if(key_type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_isKeyDown = VFX_TRUE;
        m_isKeyLongPress = VFX_FALSE;
        btn->setState(VCP_BUTTON_STATE_PRESSED);
    }
    else if (key_type == VFX_KEY_EVENT_TYPE_UP && m_isKeyDown)
    {
        if(m_isKeyLongPress)
        {
            // must set m_isKeyLongPress to FALSE before onSliderReleased, so that onPlaybackStateChange will not trigger onKeyAbort()
            m_isKeyLongPress = VFX_FALSE;

            if(m_isSongSeekable)
            {
                VFX_OBJ_CLOSE(m_timerKeyLongPress);

                m_sliderDragging = VFX_FALSE;
                
                VfxFloat currTime = m_slider->getCurrentValue();
                onSliderReleased(NULL, currTime);
            }            
        }
        else
        {
            if(is_next)
            {
                m_signalCallback.emit(FUNC_ID_BTN_NEXT);
            }
            else
            {
                m_signalCallback.emit(FUNC_ID_BTN_PREV);
            }
        }
        btn->setState(VCP_BUTTON_STATE_NORMAL);
    }
    else if(key_type == VFX_KEY_EVENT_TYPE_LONG_PRESS && m_isKeyDown)
    {
        if (!m_mplayerSrv->getSongValid(m_mplayerSrv->getActiveIndex()))
        {
            return;
        }
    
        m_isKeyLongPress = VFX_TRUE;
    
        if(m_isSongSeekable)
        {
            m_isKeySeekForward = is_next;
            m_sliderDragging = VFX_TRUE;

            VFX_OBJ_CREATE(m_timerKeyLongPress, VfxTimer, this);
            m_timerKeyLongPress->setStartDelay(0);
            m_timerKeyLongPress->setDuration(100);
            m_timerKeyLongPress->m_signalTick.connect(this, &VappMusicPlayerPlayerBase::onKeyLongPressTimerTimeout);
            m_timerKeyLongPress->start();
        }
    }
}

void VappMusicPlayerPlayerBase::onKeyLongPressTimerTimeout(VfxTimer *timer)
{
    VfxFloat currTime = m_slider->getCurrentValue();
    VfxFloat newTime;

    if(m_isKeySeekForward)
    {
        VfxFloat totalTime = m_slider->getMaxValue();

        newTime = currTime + 1000.0;

        if(newTime > totalTime)
        {
            newTime = totalTime;
        }
    }
    else
    {
        if(currTime < 1)
        {
            newTime = 0;
        }
        else
        {
            newTime = currTime - 1000.0;
        }
    }

    m_slider->setCurrentValue(newTime);
    setTextCurrTime(VfxU32(newTime));
}

void VappMusicPlayerPlayerBase::onKeyAbort(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYERBASE_ON_KEY_ABORT, m_isKeyLongPress);

    if (!m_isKeyDown)
    {
        return;
    }

    m_isKeyDown = VFX_FALSE;

    // Stop key long press timer and clear key flags
    if(m_isKeyLongPress)
    {
        m_isKeyLongPress = VFX_FALSE;

        if (m_isSongSeekable)
        {
            if (m_timerKeyLongPress)
            {
                VFX_OBJ_CLOSE(m_timerKeyLongPress);
                m_timerKeyLongPress = NULL;
            }
            m_sliderDragging = VFX_FALSE;
            m_isKeyLongPress = VFX_FALSE;

            VfxFloat currTime = m_slider->getCurrentValue();
            onSliderReleased(NULL, currTime);
        }
    }

    // Reset all button state to normal state when exit screen
    if(m_btnPlayPause && !m_btnPlayPause->getIsDisabled())
    {
        m_btnPlayPause->setState(VCP_BUTTON_STATE_NORMAL);
    }
    if(m_btnPrev && !m_btnPrev->getIsDisabled())
    {
        m_btnPrev->setState(VCP_BUTTON_STATE_NORMAL);
    }
    if(m_btnNext && !m_btnNext->getIsDisabled())
    {
        m_btnNext->setState(VCP_BUTTON_STATE_NORMAL);
    }

}

#endif //__COSMOS_MUSICPLY__
