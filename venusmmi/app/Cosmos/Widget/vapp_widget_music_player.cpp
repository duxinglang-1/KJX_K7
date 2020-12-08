/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_music_player.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the cosmos music player widget.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_music_player.h"
#include "mmi_rp_vapp_widget_music_player_def.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "../cosmos/musicplayer/Vapp_music_player_util.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_media_app_trc.h" /* Trace header */
#include "AppMgrSrvGprot.h" /* To launch music player */
#include "UCMSrvGProt.h"
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Music Player Widget Meta Frame Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetMusicPlayerMetaFrame", VappWidgetMusicPlayerMetaFrame, VfxControl);

VappWidgetMusicPlayerMetaFrame::VappWidgetMusicPlayerMetaFrame() :
m_mode(MODE_WIDGET),
m_width(0),
m_height(0),
m_is_closing(VFX_FALSE),
m_is_opening(VFX_FALSE)
{
}

VappWidgetMusicPlayerMetaFrame::VappWidgetMusicPlayerMetaFrame(VfxU8 mode, VfxS32 width, VfxS32 height) :
m_mode(mode),
m_width(width),
m_height(height),
m_is_closing(VFX_FALSE),
m_is_opening(VFX_FALSE)
{
}

VappWidgetMusicPlayerMetaFrame::~VappWidgetMusicPlayerMetaFrame()
{
}

void VappWidgetMusicPlayerMetaFrame::onInit()
{
    VfxControl::onInit();

    VfxXmlLoader *loader_common; // Same potition in widget and lock screen

    VFX_OBJ_CREATE(loader_common, VfxXmlLoader, this);
    loader_common->loadXml(VAPP_WIDGET_MUSIC_PLAYER_LAYOUT_CONTENT);

#ifdef __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
    /* Create cover image border */
    m_cover_border = VFX_OBJ_DYNAMIC_CAST(loader_common->findObj(VFX_WSTR("cover_border")), VfxImageFrame);

    /* Create default cover image */
    m_cover = VFX_OBJ_DYNAMIC_CAST(loader_common->findObj(VFX_WSTR("cover_default")), VfxFrame);
#endif /* __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__ */

    /* Create title text */
    m_title_text = VFX_OBJ_DYNAMIC_CAST(loader_common->findObj(VFX_WSTR("text_title")), VfxTextFrame);
    m_title_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(WIDGET_MP_TITLE_FONT_SIZE)));
    m_title_text->setAutoResized(VFX_FALSE);
    m_title_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_title_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    /* Caculate size of title text */
    VfxSize tempTitleSize = m_title_text->getSize();
    VfxPoint tempTitlePos = m_title_text->getPos();
    m_title_text->setSize(m_width - tempTitlePos.x - 6, tempTitleSize.height);

    /* Create album text */
    m_album_text = VFX_OBJ_DYNAMIC_CAST(loader_common->findObj(VFX_WSTR("text_album")), VfxTextFrame);
    m_album_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(WIDGET_MP_SUB_TITLE_FONT_SIZE)));
    m_album_text->setAutoResized(VFX_FALSE);
    m_album_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_album_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    /* Create artist text */
    m_artist_text = VFX_OBJ_DYNAMIC_CAST(loader_common->findObj(VFX_WSTR("text_artist")), VfxTextFrame);
    m_artist_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(WIDGET_MP_SUB_TITLE_FONT_SIZE)));
    m_artist_text->setAutoResized(VFX_FALSE);
    m_artist_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_artist_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    /* Create duration text */
    m_duration_text = VFX_OBJ_DYNAMIC_CAST(loader_common->findObj(VFX_WSTR("text_duration")), VfxTextFrame);
    m_duration_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(WIDGET_MP_SUB_TITLE_FONT_SIZE)));
    m_duration_text->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    VfxPoint tempDurPos = m_duration_text->getPos();
    m_duration_text->setPos(m_width-tempDurPos.x, tempDurPos.y);

    /* Show control text */
    VFX_OBJ_CREATE(m_tap_text, VfxTextFrame, this);

#ifdef __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
    VfxS32 tempImageWidth = m_cover_border->getSize().width;
#else
    VfxS32 tempImageWidth = 10;
#endif

    m_tap_text->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_TAP_TO_ADD_SONG));
    m_tap_text->setAnchor(0.5f, 0.5f);
    m_tap_text->setPos(tempImageWidth + (m_width - tempImageWidth)/2, m_height/2);
    m_tap_text->setSize(m_width - tempTitlePos.x - 6, m_height);
    m_tap_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(WIDGET_MP_TITLE_FONT_SIZE)));
    m_tap_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_tap_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_tap_text->setHidden(VFX_TRUE);

    VFX_OBJ_CLOSE(loader_common);

}

VfxBool VappWidgetMusicPlayerMetaFrame::onPenInput(VfxPenEvent &event)
{
    if(MODE_LOCK == m_mode || m_is_closing || m_is_opening)
    {
        return VFX_FALSE;
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        {
            // Use local variable to keep callback address since this meta frame will be close after launch app.
            VfxCallback0 callback = m_launch_callback;

            mmi_app_launch_param_struct launchParam;
            launchParam.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
            VfxBool isNotLaunchFromMainMenu = VFX_TRUE;
            launchParam.param = (void*)(&isNotLaunchFromMainMenu);
            srv_appmgr_launch_ex("native.mtk.musicplayer", &launchParam, sizeof(mmi_app_launch_param_struct));

            // Change to callback, due to launch app will cause widget being serialized and close this meta frame.
            //m_event_launch.emit();
            callback.invoke();
        }
        break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            break;

        default:
            break;
    }

    return VFX_TRUE;
}

void VappWidgetMusicPlayerMetaFrame::setCover(const VfxImageSrc &value)
{
#ifdef __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
    m_cover->setImgContent(value);
#endif
}

void VappWidgetMusicPlayerMetaFrame::setTitleSring(const VfxWString &value)
{
    m_title_text->setString(value);
    //m_title_text->setString(VFX_WSTR("Title string test for long string 1234567890"));
}

void VappWidgetMusicPlayerMetaFrame::setAlbumSring(const VfxWString &value)
{
    m_album_text->setString(value);
    //m_album_text->setString(VFX_WSTR("Album string test for long string 1234567890"));
}

void VappWidgetMusicPlayerMetaFrame::setArtistSring(const VfxWString &value)
{
    m_artist_text->setString(value);
    //m_artist_text->setString(VFX_WSTR("Artist string test for long string 1234567890"));
}

void VappWidgetMusicPlayerMetaFrame::setDurationSring(const VfxWString &value)
{
    m_duration_text->setString(value);
}

void VappWidgetMusicPlayerMetaFrame::setTapTextHidden(VfxBool is_hidden)
{
    m_tap_text->setHidden(is_hidden);
}

void VappWidgetMusicPlayerMetaFrame::closeFrame(VfxBool is_next)
{
    VfxS32Timeline *tempTimeline;
    VFX_OBJ_CREATE(tempTimeline, VfxS32Timeline, this);

    tempTimeline->setTarget(this);
    tempTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    tempTimeline->setDurationTime(WIDGET_MP_TIMER_ANIMATION);

    // Not use from current function provide by timeline to avoid quick timeout callback not come problem
    tempTimeline->setIsFromCurrent(VFX_FALSE);
    tempTimeline->setFromValue(getPos().x);

    if(is_next)
    {
        tempTimeline->setToValue(-LCD_WIDTH);
        // Set postion to final position
        setPos(-LCD_WIDTH, getPos().y);
    }
    else
    {
        tempTimeline->setToValue(LCD_WIDTH*2);
        setPos(LCD_WIDTH*2, getPos().y);
    }

    tempTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    tempTimeline->m_signalStopped.connect(this, &VappWidgetMusicPlayerMetaFrame::closeFrameDone);
    tempTimeline->start();
    m_is_closing = VFX_TRUE;
}

void VappWidgetMusicPlayerMetaFrame::closeFrameDone(VfxBaseTimeline *timeline, VfxBool stopped)
{
    VappWidgetMusicPlayerMetaFrame *_this = this;

    m_is_closing = VFX_FALSE;
    VFX_OBJ_CLOSE(_this);
}

void VappWidgetMusicPlayerMetaFrame::openFrame(VfxBool is_next)
{
    VfxS32Timeline *tempTimeline;
    VFX_OBJ_CREATE(tempTimeline, VfxS32Timeline, this);

    tempTimeline->setTarget(this);
    tempTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    tempTimeline->setDurationTime(WIDGET_MP_TIMER_ANIMATION);
    tempTimeline->setIsFromCurrent(VFX_FALSE);
    if(is_next)
    {
        tempTimeline->setFromValue(LCD_WIDTH*2);
    }
    else
    {
        tempTimeline->setFromValue(-LCD_WIDTH);
    }
    tempTimeline->setToValue(0);
    tempTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    tempTimeline->m_signalStopped.connect(this, &VappWidgetMusicPlayerMetaFrame::openFrameDone);
    tempTimeline->start();

    m_is_opening = VFX_TRUE;
}

void VappWidgetMusicPlayerMetaFrame::openFrameDone(VfxBaseTimeline *timeline, VfxBool stopped)
{
    m_is_opening = VFX_FALSE;
    VFX_OBJ_CLOSE(timeline);
}

/*****************************************************************************
 * Music Player Widget Base Panel Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetMusicPlayerBase", VappWidgetMusicPlayerBase, VfxControl);

VappWidgetMusicPlayerBase::~VappWidgetMusicPlayerBase()
{
    /* Disconnect app signal */
    if(m_mplayerSrv != NULL)
    {
        m_mplayerSrv->m_signalOnPrevNext.disconnect(this, &VappWidgetMusicPlayerBase::onPrevNext);
    }

    /* Disconnect playback singal */
    if(m_ctrlPlayback != NULL)
    {
        m_ctrlPlayback->m_signalPlaybackStateChange.disconnect(this, &VappWidgetMusicPlayerBase::onPlaybackStateChange);
        m_ctrlPlayback->m_signalMDICallback.disconnect(this, &VappWidgetMusicPlayerBase::onMDICallback);
    }
}

void VappWidgetMusicPlayerBase::getAppControl(void)
{
    m_mplayerSrv = getMusicPlayerSrv();

    if(m_mplayerSrv)
    {
        m_mplayerSrv->m_signalOnPrevNext.connect(this, &VappWidgetMusicPlayerBase::onPrevNext);

        /* Get playback control and connect state change */
        m_ctrlPlayback = m_mplayerSrv->getCtrlPlayback();
        m_ctrlPlayback->m_signalPlaybackStateChange.connect(this, &VappWidgetMusicPlayerBase::onPlaybackStateChange);
        m_ctrlPlayback->m_signalMDICallback.connect(this, &VappWidgetMusicPlayerBase::onMDICallback);
    }
}

void VappWidgetMusicPlayerBase::onPlayPause(void)
{
    if(m_ctrlPlayback != NULL)
    {
        PlaybackStateEnum state;
        state = m_ctrlPlayback->getPlayState();
    
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_WIDGET_MUSICPLY_INFO_PANEL_BTN_CLICK, state);
    
        if(PB_STATE_PLAY == state ||
           PB_STATE_PAUSE == state ||
           PB_STATE_OPEN == state ||
           PB_STATE_STOP == state ||
           PB_STATE_CLOSE == state ||                   
           PB_STATE_SWITCHING_PLAY == state ||
           PB_STATE_SWITCHING_NOT_PLAY == state ||
           PB_STATE_INTERRUPTED == state ||
           PB_STATE_BT_CONNECTING_WHILE_PLAYING == state)
        {
            /* Stop the song if the song is not pausable */
            if ((state == PB_STATE_PLAY || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING) &&
                !m_ctrlPlayback->isSongPausable(NULL))
            {
                m_ctrlPlayback->stop();
            }
            else if (m_ctrlPlayback->m_playStateBeforeSeek == PB_STATE_PAUSE)
            {
                // do seek while pasued
                if(m_mplayerSrv)
                {
                    m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);
                }
                m_ctrlPlayback->play();
            }
            else
            {
                if(m_mplayerSrv)
                {
                    m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);
                }
                m_ctrlPlayback->playpause();
            }
        }
    }

}

void VappWidgetMusicPlayerBase::onPrev(void)
{
    if(m_mplayerSrv != NULL && isValidState())
    {
        /* Control music player to previous song */
        m_mplayerSrv->onPrev(VFX_TRUE);
    }
}

void VappWidgetMusicPlayerBase::onNext(void)
{
    if(m_mplayerSrv != NULL && isValidState())
    {
        /* Control music player to next song */
        m_mplayerSrv->onNext(NEXT, VFX_TRUE);
    }

}

VfxBool VappWidgetMusicPlayerBase::isValidState(void)
{
    if((m_mplayerSrv == NULL) || (m_mplayerSrv && (m_mplayerSrv->getActiveCount() == 0)))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

/*****************************************************************************
 * Music Player Widget Info Panel Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetMusicPlayerInfoPanel", VappWidgetMusicPlayerInfoPanel, VappWidgetMusicPlayerBase);

VappWidgetMusicPlayerInfoPanel::VappWidgetMusicPlayerInfoPanel() :
m_mode(MODE_WIDGET),
m_is_ctrl_hidden(VFX_FALSE),
m_show_control_text(NULL),
m_tl_panel_open(NULL),
m_tl_panel_close(NULL)
{
}

VappWidgetMusicPlayerInfoPanel::VappWidgetMusicPlayerInfoPanel(VfxU8 mode) :
m_mode(mode),
m_is_ctrl_hidden(VFX_FALSE),
m_show_control_text(NULL),
m_tl_panel_open(NULL),
m_tl_panel_close(NULL)
{
}

VappWidgetMusicPlayerInfoPanel::~VappWidgetMusicPlayerInfoPanel()
{
    /* Deregister app event callback */
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE,(mmi_proc_func)&VappWidgetMusicPlayerInfoPanel::onAppOpenClose, this);
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_MUSICPLY_SHOW_HIDE,(mmi_proc_func)&VappWidgetMusicPlayerInfoPanel::onAppShowHide, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE,(mmi_proc_func)&VappWidgetMusicPlayerInfoPanel::staticEventHandler, this);
}

void VappWidgetMusicPlayerInfoPanel::onInit()
{
    VfxFrame::onInit();

    initUI();

    /* Start a timer update time */
    VFX_OBJ_CREATE(m_timer_curr_time, VfxTimer, this);
    m_timer_curr_time->setStartDelay(0);
    m_timer_curr_time->setDuration(WIDGET_MP_TIMER_UPDATE_DURATION);
    m_timer_curr_time->m_signalTick.connect(this, &VappWidgetMusicPlayerInfoPanel::onCurrTimeTimerExpir);
    m_timer_curr_time->start();

    /* If music player already running, get play and list control */
    getAppControl();

    /* Update content */
    updatePanel();

    /* Register for app open/close event */
    mmi_frm_cb_reg_event(EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE,(mmi_proc_func)&VappWidgetMusicPlayerInfoPanel::onAppOpenClose, this);
    mmi_frm_cb_reg_event(EVT_ID_VAPP_MUSICPLY_SHOW_HIDE,(mmi_proc_func)&VappWidgetMusicPlayerInfoPanel::onAppShowHide, this);

    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE,(mmi_proc_func)&VappWidgetMusicPlayerInfoPanel::staticEventHandler, this);
}

void VappWidgetMusicPlayerInfoPanel::initUI()
{
    /* Create loader */
    VfxXmlLoader *loader;
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);

    /*-------- Load background and screen width, height, lock height layout from resource id -----------*/
    if(MODE_LOCK == m_mode)
    {
        loader->loadXml(VAPP_WIDGET_MUSIC_PLAYER_LAYOUT_LOCK);
    }
    else
    {
        loader->loadXml(VAPP_WIDGET_MUSIC_PLAYER_LAYOUT_WIDGET);
    }
    m_background = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("background")), VfxImageFrame);

    VfxRect bgRect = m_background->getRect();
    m_width = bgRect.getWidth();
    m_height = bgRect.getHeight();

    m_background->setResId(IMG_ID_VAPP_WIDGET_MUSPLY_BACKGROUND);
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setRect(bgRect);

    if((MODE_LOCK == m_mode) && m_is_ctrl_hidden)
    {
        VfxImageFrame *tempLock = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("background_hide_ctrl")), VfxImageFrame);
        VfxRect bglockRect = tempLock->getRect();
        m_height_lock = bglockRect.getHeight();
        VFX_OBJ_CLOSE(tempLock);

        m_background->setSize(m_width, m_height_lock);
    }

    /*------------------------------------- Set object bounds ---------------------------------------------*/
    setBounds(VfxRect(0, 0, m_width, m_height));

    /*-------------------------------------- Set meta frame area ------------------------------------------*/
    VfxControl *tempMetaCtl;
    tempMetaCtl = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("meta_panel")), VfxControl);
    m_height_ctrl = tempMetaCtl->getSize().height;
    VFX_OBJ_CLOSE(tempMetaCtl);

    /* Use a frame to limit the size of meta frame to avoid it exceeds the background 9-slice image */
    VFX_OBJ_CREATE(m_meta_frame_border,VfxFrame,this);
#if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__)
    m_meta_frame_border->setRect(3, 0, m_width-5, m_height_ctrl);
#else
    m_meta_frame_border->setRect(0, 0, m_width, m_height_ctrl);
#endif

    if(MODE_LOCK == m_mode)
    {
        VFX_OBJ_CREATE_EX(m_meta_frame, VappWidgetMusicPlayerMetaFrame, m_meta_frame_border, (VappWidgetMusicPlayerMetaFrame::MODE_LOCK, m_width, m_height_ctrl));
    }
    else
    {
        VFX_OBJ_CREATE_EX(m_meta_frame, VappWidgetMusicPlayerMetaFrame, m_meta_frame_border, (VappWidgetMusicPlayerMetaFrame::MODE_WIDGET,m_width, m_height_ctrl));
    }

    m_meta_frame->setRect(0,0, m_width, m_height_ctrl);
    //m_meta_frame->m_event_launch.connect(this, &VappWidgetMusicPlayerInfoPanel::onAppLaunched);
    m_meta_frame->m_launch_callback = VfxCallback0(this, &VappWidgetMusicPlayerInfoPanel::onAppLaunched);

    /*-------------------------------------- Load other component layout from resource id -----------------*/

    /* Create slider background */
    m_slider_bg = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("slider_bg")), VfxImageFrame);
    VfxSize bgSilderSize = m_slider_bg->getSize();
    m_slider_bg->setResId(IMG_ID_VAPP_WIDGET_MUSPLY_SLIDER_BG);
    m_slider_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_slider_bg->setSize(bgSilderSize);

    /* Create slider bar */
    m_slider_bar = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("slider_bar")), VfxImageFrame);
    m_slider_bar_size = m_slider_bar->getSize();
    m_slider_bar->setResId(IMG_ID_VAPP_WIDGET_MUSPLY_SLIDER_BAR);
    m_slider_bar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    /* Show control text */
    if(MODE_LOCK == m_mode)
    {
        m_show_control_text = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("text_show_control")), VfxTextFrame);
        m_show_control_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(WIDGET_MP_SUB_TITLE_FONT_SIZE)));
        m_show_control_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

        if(!m_is_ctrl_hidden)
        {
            m_show_control_text->setHidden(VFX_TRUE);
        }
    }

    /* Create button */
    m_play_btn = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_play")), VcpButton);
    m_play_btn->setId(BTN_PLAY);
    m_play_btn->setMargin(0, 0, 0, 0);
    m_play_btn->m_signalClicked.connect(this, &VappWidgetMusicPlayerInfoPanel::onButtonClicked);
    m_play_btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_play_btn->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_LARGE_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_LARGE_PRESS, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_LARGE_NORMAL, 0));

    m_prev_btn = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_prev")), VcpButton);
    m_prev_btn->setId(BTN_PREV);
    m_prev_btn->setMargin(0, 0, 0, 0);
    m_prev_btn->m_signalClicked.connect(this, &VappWidgetMusicPlayerInfoPanel::onButtonClicked);    
    m_prev_btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_prev_btn->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_PRESS, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_NORMAL, 0));

    m_next_btn = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_next")), VcpButton);
    m_next_btn->setId(BTN_NEXT);
    m_next_btn->setMargin(0, 0, 0, 0);
    m_next_btn->m_signalClicked.connect(this, &VappWidgetMusicPlayerInfoPanel::onButtonClicked);    
    m_next_btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_next_btn->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_PRESS, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_NORMAL, 0));

    /* Init lock screen in hidden mode */
    if((MODE_LOCK == m_mode) && m_is_ctrl_hidden)
    {
        m_play_btn->setHidden(VFX_TRUE);
        m_prev_btn->setHidden(VFX_TRUE);
        m_next_btn->setHidden(VFX_TRUE); 
    }
    
    /* Close XML Loader */
    VFX_OBJ_CLOSE(loader);

}

void VappWidgetMusicPlayerInfoPanel::destroyUI()
{
    /* Close Slider */
    VFX_OBJ_CLOSE(m_slider_bg);
    VFX_OBJ_CLOSE(m_slider_bar);

    /* Close control text */
    VFX_OBJ_CLOSE(m_show_control_text);

    /* Close button */
    VFX_OBJ_CLOSE(m_play_btn);
    VFX_OBJ_CLOSE(m_prev_btn);
    VFX_OBJ_CLOSE(m_next_btn);

    /* Close meta info frame*/
    VFX_OBJ_CLOSE(m_meta_frame);
    VFX_OBJ_CLOSE(m_meta_frame_border);

    /* Close background */
    VFX_OBJ_CLOSE(m_background);
}

void VappWidgetMusicPlayerInfoPanel::onCurrTimeTimerExpir(VfxTimer *timer)
{
    /* If not in play state, do not update contect */
    if((m_ctrlPlayback != NULL) && (PB_STATE_PLAY != m_ctrlPlayback->getPlayState()))
    {
        m_timer_curr_time->stop();
        return;
    }
    
    updateCurrentTime();
}

void VappWidgetMusicPlayerInfoPanel::onButtonClicked(VfxObject* obj, VfxId id)
{
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return;
    }

    switch(id)
    {
        case BTN_PLAY:
            onPlayPause();
            break;
        case BTN_PREV:
            onPrev();
            break;
        case BTN_NEXT:
            onNext();
            break;
        default:
            break;
    }
}    

VfxBool VappWidgetMusicPlayerInfoPanel::onKeyInput(VfxKeyEvent & event)
{
    // Only handle key event in lock screen
    if(m_mode == MODE_WIDGET || m_is_ctrl_hidden)
    {
        return VFX_FALSE;
    }

    switch (event.keyCode)
    {
        case VFX_KEY_CODE_ENTER:
        {
            if(m_play_btn->getIsDisabled())
            {
                break;
            }

            // Do not act while change song or seeking
            if(m_play_btn->getIsUnhittable())
            {
                break;
            }
            
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_isKeyDown = VFX_TRUE;
                m_play_btn->setState(VCP_BUTTON_STATE_PRESSED);
            }
            else if (event.type == VFX_KEY_EVENT_TYPE_UP && m_isKeyDown)
            {
                m_isKeyDown = VFX_FALSE;
                m_play_btn->setState(VCP_BUTTON_STATE_NORMAL);
                onPlayPause();
            }

            return VFX_TRUE;
        }

        case VFX_KEY_CODE_ARROW_RIGHT:
        {
            if(m_next_btn->getIsDisabled())
            {
                break;
            }

            // Do not act while change song or seeking
            if(m_next_btn->getIsUnhittable())
            {
                break;
            }

            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_next_btn->setState(VCP_BUTTON_STATE_PRESSED);
            }
            else if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                m_isKeyDown = VFX_FALSE;
                m_next_btn->setState(VCP_BUTTON_STATE_NORMAL);
                onNext();
            }

            return VFX_TRUE;
        }

        case VFX_KEY_CODE_ARROW_LEFT:
        {
            if(m_prev_btn->getIsDisabled())
            {
                break;
            }

            // Do not act while change song or seeking
            if(m_prev_btn->getIsUnhittable())
            {
                break;
            }

            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_prev_btn->setState(VCP_BUTTON_STATE_PRESSED);
            }
            else if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                m_isKeyDown = VFX_FALSE;
                m_prev_btn->setState(VCP_BUTTON_STATE_NORMAL);
                onPrev();
            }

            return VFX_TRUE;
        }        

    }

    if(event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        m_isKeyDown = VFX_FALSE;
    }

    return VFX_FALSE;
}


void VappWidgetMusicPlayerInfoPanel::onPlaybackStateChange(PlaybackStateEnum state)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_WIDGET_MUSICPLY_INFO_PANEL_STATE_CHANGE, state);

    switch(state)
    {
        case PB_STATE_NONE:
            /* Check if app clear its active list */
            if(!isValidState())
            {
                updatePanel();
                m_signalPanelClose.emit(this);
                return;
            }

            break;
        case PB_STATE_OPEN:
            updatePanel();
            break;
        case PB_STATE_PLAY:
            m_timer_curr_time->start();
            updateButton();
            break;
        case PB_STATE_PAUSE:
            updateCurrentTime();
            updateButton();
            break;
        case PB_STATE_STOP:
            updateDuration();
            updateButton();
            break;
        case PB_STATE_CLOSE:
            updatePanel();
            break;
        case PB_STATE_PLAYBACK_FAIL:
            updateButton();
            break;
        default:
            updateButton();
            break;
    }
}

void VappWidgetMusicPlayerInfoPanel::onPrevNext(VfxBool is_next)
{
    /* UI is serialized */
    if(m_background == NULL)
    {
        return;
    }

    changeMetaFrame(is_next);
}

void VappWidgetMusicPlayerInfoPanel::onMDICallback(VfxS32 result)
{
    switch (result)
    {
        case VAPP_MUSICPLY_PRE_END_OF_FILE:
            if(m_slider_bar)
            {
                m_slider_bar->setSize(m_slider_bar_size.width, m_slider_bar_size.height);
            }
            break;

        case MDI_AUDIO_END_OF_FILE:
            /* Not handle this case, it will be check in the state change signal*/
            break;

        case MDI_AUDIO_DUR_UPDATED:
        case VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT:
            updateDuration();
            break;

        default:
            break;
    }
}

void VappWidgetMusicPlayerInfoPanel::onHiddenDone(VfxBaseTimeline *timeline, VfxBool is_complete)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_WIDGET_MUSICPLY_INFO_PANEL_ON_HIDDEN_DOWN, is_complete);

    if(is_complete)
    {
        if(m_show_control_text != NULL)
        {
            m_show_control_text->setHidden(VFX_FALSE);
        }
    }
    m_background->setSize(m_width, m_height_lock);

    VFX_OBJ_CLOSE(m_tl_panel_close);

    // Set unfocus to receive key event
    if(MODE_LOCK == m_mode)
    {
        setFocused(VFX_FALSE);
    }
}

void VappWidgetMusicPlayerInfoPanel::onUnHiddenDone(VfxBaseTimeline *timeline, VfxBool is_complete)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_WIDGET_MUSICPLY_INFO_PANEL_ON_UNHIDDEN_DOWN, is_complete);

    if(is_complete)
    {
        m_play_btn->setHidden(VFX_FALSE);
        m_prev_btn->setHidden(VFX_FALSE);
        m_next_btn->setHidden(VFX_FALSE);    
    }

    /* Set actual size */
    m_background->setSize(m_width, m_height);

    VFX_OBJ_CLOSE(m_tl_panel_open);

    // Set focus to receive key event
    if(MODE_LOCK == m_mode)
    {
        setFocused(VFX_TRUE);
    }
}

void VappWidgetMusicPlayerInfoPanel::onAppLaunched(void)
{
    getAppControl();
}

mmi_ret VappWidgetMusicPlayerInfoPanel::onAppOpenClose(mmi_event_struct *evt)
{
    VappMusicPlayerOpenCloseEvtStruct *openCloseEvt = (VappMusicPlayerOpenCloseEvtStruct*) evt;
    VappWidgetMusicPlayerInfoPanel* widget = (VappWidgetMusicPlayerInfoPanel*) evt->user_data;

    /* App close, */
    if(openCloseEvt->isOpen)
    {
        widget->getAppControl();
        widget->updatePanel();
    }
    else
    {
        widget->m_mplayerSrv = NULL;
        widget->updatePanel();

        // Ask lock screen to close panel
        widget->m_signalPanelClose.emit(widget);
    }

    //widget->m_signalAppOpenClose.emit(widget, openCloseEvt->isOpen);
    
    return MMI_RET_OK;
}

mmi_ret VappWidgetMusicPlayerInfoPanel::onAppShowHide(mmi_event_struct *evt)
{
    VappMusicPlayerShowHideEvtStruct *showHideEvt = (VappMusicPlayerShowHideEvtStruct*) evt;
    VappWidgetMusicPlayerInfoPanel* widget = (VappWidgetMusicPlayerInfoPanel*) evt->user_data;

    /* Exit App */
    if(!showHideEvt->isShow)
    {
        widget->updatePanel();
    }

    return MMI_RET_OK;
}

mmi_ret VappWidgetMusicPlayerInfoPanel::staticEventHandler(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            VappWidgetMusicPlayerInfoPanel* widget = (VappWidgetMusicPlayerInfoPanel*) evt->user_data;

            if(widget->m_play_btn)
            {
                VcpStateImage imgListPlayBtn;
                imgListPlayBtn.setImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_PRESS, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_DISABLE, 0);
                widget->m_play_btn->setImage(imgListPlayBtn);

                if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
                {
                    widget->m_play_btn->setIsDisabled(VFX_TRUE);
                    widget->m_prev_btn->setIsDisabled(VFX_TRUE);
                    widget->m_next_btn->setIsDisabled(VFX_TRUE);
                }
                else
                {
                    if(widget->isValidState())
                    {
                        widget->m_play_btn->setIsDisabled(VFX_FALSE);
                        widget->m_prev_btn->setIsDisabled(VFX_FALSE);
                        widget->m_next_btn->setIsDisabled(VFX_FALSE);
                    }
                }
            }
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
}

void VappWidgetMusicPlayerInfoPanel::changeMetaFrame(VfxBool is_next)
{
    /* If previous meta frame not close, force to close it */
    if(m_prev_meta_frame.get() != NULL)
    {
        VFX_OBJ_CLOSE(m_prev_meta_frame);
    }

    /* bind to a weak pointer for later check */
    m_prev_meta_frame = m_meta_frame;

    /* Move out the frame */
    m_meta_frame->closeFrame(is_next);

    /* Create new frame and bind to member variable */
    if(MODE_LOCK == m_mode)
    {
        VFX_OBJ_CREATE_EX(m_meta_frame, VappWidgetMusicPlayerMetaFrame, m_meta_frame_border, (VappWidgetMusicPlayerMetaFrame::MODE_LOCK, m_width, m_height_ctrl));
    }
    else
    {
        VFX_OBJ_CREATE_EX(m_meta_frame, VappWidgetMusicPlayerMetaFrame, m_meta_frame_border, (VappWidgetMusicPlayerMetaFrame::MODE_WIDGET,m_width, m_height_ctrl));
    }

    m_meta_frame->setRect(0, 0, m_width, m_height_ctrl);
    //m_meta_frame->m_event_launch.connect(this, &VappWidgetMusicPlayerInfoPanel::onAppLaunched);
    m_meta_frame->m_launch_callback = VfxCallback0(this, &VappWidgetMusicPlayerInfoPanel::onAppLaunched);

    /* Update frame content */
    updatePanel();

    /* Move in the frame */
    m_meta_frame->openFrame(is_next);
}

void VappWidgetMusicPlayerInfoPanel::updateButton(void)
{
    /* UI is serialized */
    if(m_background == NULL)
    {
        return;
    }

    VcpStateImage imgListPlayBtn;
    VfxBool in_call = VFX_FALSE;

    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        in_call = VFX_TRUE;
    }

    if(in_call || (m_ctrlPlayback == NULL) || !isValidState())
    {
        imgListPlayBtn.setImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_PRESS, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_DISABLE, 0);

        m_play_btn->setIsDisabled(VFX_TRUE);
        m_prev_btn->setIsDisabled(VFX_TRUE);
        m_next_btn->setIsDisabled(VFX_TRUE);
    }
    else
    {
        VfxBool isPlayImage = VFX_TRUE;
        
        if (m_ctrlPlayback)
        {
            isPlayImage = m_ctrlPlayback->getPlayPauseState();
        }

        if(isPlayImage)
        {
            imgListPlayBtn.setImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_PRESS, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_DISABLE, 0);
        }
        else
        {
            imgListPlayBtn.setImage(IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PAUSE_NORMAL, IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PAUSE_PRESS, 0, 0);
        }

        // Check if need to disable play icon
        // Playback fail or interrupted in playback fail state, do not enable UI
        InterruptStruct interrupt = m_ctrlPlayback->getInterruptedInfo();
        PlaybackStateEnum state = m_ctrlPlayback->getPlayState();

        if (( state == PB_STATE_PLAYBACK_FAIL) || (interrupt.isInterrupted && (interrupt.state == PB_STATE_PLAYBACK_FAIL)))
        {
            m_play_btn->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_play_btn->setIsDisabled(VFX_FALSE);
        }

        // Set button unhittable when switching play
        if (state == PB_STATE_SWITCHING_PLAY || state == PB_STATE_SWITCHING_NOT_PLAY || state == PB_STATE_SEEKING)
        {
            // Make button up when change song
            m_play_btn->setState(VCP_BUTTON_STATE_NORMAL);
            m_play_btn->setIsUnhittable(VFX_TRUE);
            m_prev_btn->setState(VCP_BUTTON_STATE_NORMAL);
            m_prev_btn->setIsUnhittable(VFX_TRUE);
            m_next_btn->setState(VCP_BUTTON_STATE_NORMAL);
            m_next_btn->setIsUnhittable(VFX_TRUE);

        }
        else
        {
            m_play_btn->setIsUnhittable(VFX_FALSE);
            m_prev_btn->setIsUnhittable(VFX_FALSE);
            m_next_btn->setIsUnhittable(VFX_FALSE);
        }
        
        m_prev_btn->setIsDisabled(VFX_FALSE);
        m_next_btn->setIsDisabled(VFX_FALSE);
    }

    m_play_btn->setImage(imgListPlayBtn);
}

void VappWidgetMusicPlayerInfoPanel::updateDuration(void)
{
    if(m_ctrlPlayback != NULL)
    {
        /* Update duration Text */
        m_duration = m_ctrlPlayback->getDuration();

        if(m_meta_frame)
        {
            VfxWString strDuration;
            strDuration.format("%02d:%02d", m_duration/(60*1000), m_duration%(60*1000)/1000);
            m_meta_frame->setDurationSring(strDuration);
        }

        /* Update slider length */
        if(m_slider_bar)
        {
            VfxU32 curr_time;
            curr_time = m_ctrlPlayback->getCurrTime();

            VfxFloat bar_percent = 0;
            if(m_duration > 0)
            {
                if(curr_time >= m_duration)
                {
                    bar_percent = 1;
                }
                else
                {
                    bar_percent = (VfxFloat)curr_time / (VfxFloat)m_duration;
                }
            }
            m_slider_bar->setSize(m_slider_bar_size.width*bar_percent, m_slider_bar_size.height);
        }
    }
    else
    {
        /* Update duration Text */
        if(m_meta_frame)
        {
            m_meta_frame->setDurationSring(VFX_WSTR(""));
        }

        /* Update slider length */
        if(m_slider_bar)
        {
            m_slider_bar->setSize(0, m_slider_bar_size.height);    
        }
    }
}

void VappWidgetMusicPlayerInfoPanel::updateCurrentTime(void)
{
    if((m_ctrlPlayback != NULL) && m_slider_bar)
    {
        VfxU32 curr_time;
        VfxFloat bar_percent = 0;

        curr_time = m_ctrlPlayback->getCurrTime();

        if(m_duration > 0)
        {
            if(curr_time >= m_duration)
            {
                bar_percent = 1;
            }
            else
            {
                bar_percent = (VfxFloat)curr_time / (VfxFloat)m_duration;
            }
        }
        m_slider_bar->setSize(m_slider_bar_size.width*bar_percent, m_slider_bar_size.height);
    }
}

void VappWidgetMusicPlayerInfoPanel::updatePanel(void)
{
    /* UI is serialized */
    if(m_background == NULL)
    {
        return;
    }

    if(!isValidState())
    {
        resetPanel();

        /* Show tap to add songs string*/
        if(MODE_WIDGET == m_mode)
        {
            m_meta_frame->setTapTextHidden(VFX_FALSE);
        }
        return;
    }

    /* Hide tap to add songs string*/
    m_meta_frame->setTapTextHidden(VFX_TRUE);


    /* If not in play state, do not update contect */
    if(m_ctrlPlayback != NULL)
    {
        if(PB_STATE_NONE == m_ctrlPlayback->getPlayState())
        {
            resetPanel();
            return;
        }
    }

#ifdef __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
    /* Update image */
    if (m_mplayerSrv != NULL)
    {
        VfxImageBuffer imgBuf;
        SongInfoStruct song_info;
        m_mplayerSrv->getCurrInfo(song_info);
        m_mplayerSrv->getAlbumCoverByDefaultBuffer(song_info.id, imgBuf);
        
        if(imgBuf.ptr != NULL)
        {
            VfxImageSrc imgSrc;
            imgSrc.setImageBuffer(imgBuf);
            m_meta_frame->setCover(imgSrc);
        }
        else
        {
            m_meta_frame->setCover(VfxImageSrc(IMG_ID_VAPP_WIDGET_MUSPLY_COVER_DEFAULT));
        }
    }
    else
    {
        m_meta_frame->setCover(VfxImageSrc(IMG_ID_VAPP_WIDGET_MUSPLY_COVER_DEFAULT));
    }
    /* Do not update frame when change prev next*/
    //m_meta_frame->setCacheMode(VFX_CACHE_MODE_FREEZE);

#endif /* __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__ */

    /* Get detail info and update title, album and artist  */
    if(isValidState())
    {
        srv_plst_media_details_struct *detail_info = NULL;
        VFX_ALLOC_MEM(detail_info, sizeof(srv_plst_media_details_struct), this);

        if(m_mplayerSrv->getCurrDetailInfo(detail_info))
        {
            m_meta_frame->setTitleSring(VFX_WSTR_MEM(detail_info->title));
            m_meta_frame->setAlbumSring(VFX_WSTR_MEM(detail_info->album));
            m_meta_frame->setArtistSring(VFX_WSTR_MEM(detail_info->artist));
        }
        else
        {
            resetPanelString();
        }

        VFX_FREE_MEM(detail_info);
    }
    else
    {
        resetPanelString();
    }

    /* Update duration and progress bar */
    updateDuration();
    
    /* Update button */
    updateButton();
}

void VappWidgetMusicPlayerInfoPanel::resetPanel(void)
{
#ifdef __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
    m_meta_frame->setCover(VfxImageSrc(IMG_ID_VAPP_WIDGET_MUSPLY_COVER_DEFAULT));
#endif
    m_meta_frame->setDurationSring(VFX_WSTR(""));
    resetPanelString();
    m_slider_bar->setSize(0, m_slider_bar_size.height);

    updateButton();
}

void VappWidgetMusicPlayerInfoPanel::resetPanelString(void)
{
    m_meta_frame->setTitleSring(VFX_WSTR(""));
    m_meta_frame->setAlbumSring(VFX_WSTR(""));
    m_meta_frame->setArtistSring(VFX_WSTR(""));
}

void VappWidgetMusicPlayerInfoPanel::setControlHidden(VfxBool is_hidden)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_WIDGET_MUSICPLY_INFO_PANEL_SET_CTRL_HIDDEN, m_is_ctrl_hidden, is_hidden);

    if(m_is_ctrl_hidden == is_hidden)
    {
        return;
    }

    if(is_hidden)
    {
        /* Stop open animation */
        VFX_OBJ_CLOSE(m_tl_panel_open);

        /* Create tineline */
        VFX_OBJ_CREATE(m_tl_panel_close, VfxSizeTimeline, this);
        m_tl_panel_close->setTarget(m_background);
        m_tl_panel_close->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE);
        m_tl_panel_close->setDurationTime(WIDGET_MP_TIMER_ANIMATION);
        m_tl_panel_close->m_signalStopped.connect(this, &VappWidgetMusicPlayerInfoPanel::onHiddenDone);
        m_tl_panel_close->setToValue(VfxSize(m_width, m_height_lock));

        /* Hide button */
        m_play_btn->setHidden(VFX_TRUE);
        m_prev_btn->setHidden(VFX_TRUE);
        m_next_btn->setHidden(VFX_TRUE);    

        /* Start timeline */
        m_tl_panel_close->start();
    }
    else
    {
        /* Stop open animation */
        VFX_OBJ_CLOSE(m_tl_panel_close);

        /* Create tineline */
        VFX_OBJ_CREATE(m_tl_panel_open, VfxSizeTimeline, this);
        m_tl_panel_open->setTarget(m_background);
        m_tl_panel_open->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE);
        m_tl_panel_open->setDurationTime(WIDGET_MP_TIMER_ANIMATION);
        m_tl_panel_open->m_signalStopped.connect(this, &VappWidgetMusicPlayerInfoPanel::onUnHiddenDone);
        m_tl_panel_open->setToValue(VfxSize(m_width, m_height));

        /* Hide text */
        if(m_show_control_text != NULL)
        {
            m_show_control_text->setHidden(VFX_TRUE);
        }

        /* Start timeline */
        m_tl_panel_open->start();
    }

    m_is_ctrl_hidden = is_hidden;
}

VfxBool VappWidgetMusicPlayerInfoPanel::isControlHidden(void)
{
    return m_is_ctrl_hidden;
}

void VappWidgetMusicPlayerInfoPanel::setPanelActive(VfxBool isActive)
{
    // When screen use this panel inacive, call this function to reset button status
    if(!isActive)
    {
        m_play_btn->setState(VCP_BUTTON_STATE_NORMAL);
        m_next_btn->setState(VCP_BUTTON_STATE_NORMAL);
        m_prev_btn->setState(VCP_BUTTON_STATE_NORMAL);
    }
}

/*****************************************************************************
 * Music Player Widget Class
 *****************************************************************************/
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetMusicPlayer, VAPP_WIDGET_TYPE_MUSIC_PLAYER, VappWidgetMusicPlayerPublisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetMusicPlayer, VappWidget);
VappWidgetMusicPlayer::VappWidgetMusicPlayer()
{
}


VappWidgetId VappWidgetMusicPlayer::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_MUSIC_PLAYER);
}


VfxSize VappWidgetMusicPlayer::getMaxSize() const
{
    return VfxSize(WIDGET_MP_WIDTH, WIDGET_MP_HEIGHT);
}


VfxS32 VappWidgetMusicPlayer::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_MUSPLY);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetMusicPlayer::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_MUSPLY_ICON);

    return icon;
}


void VappWidgetMusicPlayer::onCreateView()
{
    VappWidget::onCreateView();

    /* Create info panel for image, title, duration, ... */
    VFX_OBJ_CREATE_EX(m_info_panel, VappWidgetMusicPlayerInfoPanel, this, (VappWidgetMusicPlayerInfoPanel::MODE_WIDGET));
}


void VappWidgetMusicPlayer::onReleaseView()
{
    VFX_OBJ_CLOSE(m_info_panel);
    
    VappWidget::onReleaseView();
}

void VappWidgetMusicPlayer::onSerializeView(VfxArchive *ar)
{
    m_info_panel->destroyUI();
    VappWidget::onSerializeView(ar);    
}

void VappWidgetMusicPlayer::onRestoreView(VfxArchive *ar)
{
    /* Create info panel for image, title, duration, ... */
    m_info_panel->initUI();
    m_info_panel->updatePanel();

    VappWidget::onRestoreView(ar);
}

VfxPoint VappWidgetMusicPlayer::onGetEditButtonOffset()
{
    return VfxPoint(WIDGET_MP_WIDTH - WIDGET_MP_GET_BUFFER_OFFSET_X, WIDGET_MP_GET_BUFFER_OFFSET_Y);
}

#endif /* defined(__COSMOS_MUSICPLY__) */

