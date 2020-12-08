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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_gallery_player.cpp
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

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_FTO_GALLERY__

#include "mmi_rp_vapp_gallery_def.h"
#include "vapp_gallery_player.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_video_player_cp.h"
#include "vapp_gallery_util.h"
#include "vapp_vol_dialog_gprot.h"
#include "vcui_videoclipper_gprot.h"
#include "vfx_datatype.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_slider_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

extern "C"
{
#include "FileMgrSrvGprot.h"

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#include "RightsMgrGprot.h"
#endif
#include "UcmSrvGprot.h"
#include "vapp_ncenter_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"

#include "MMI_media_app_trc.h"
#include "cbm_api.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/
enum VappGalleryFloatSettingPnaelLayout
{
#if defined(__MMI_MAINLCD_480X800__)
    TAB_W       = 104,
    TAB_H       = 77,
    SEPARATOR_W = 2,
    SEPARATOR_H = 77,
    BTN_W = 50,
    BTN_H = 50,

#elif defined(__MMI_MAINLCD_320X480__)
    TAB_W       = 73,
    TAB_H       = 53,
    SEPARATOR_W = 2,
    SEPARATOR_H = 53,
    BTN_W = 45,
    BTN_H = 45,

#elif defined(__MMI_MAINLCD_240X320__)
    TAB_W       = 55,
    TAB_H       = 48,
    SEPARATOR_W = 2,
    SEPARATOR_H = 48,
    BTN_W = 40,
    BTN_H = 40,

#elif defined(__MMI_MAINLCD_240X400__)
    TAB_W       = 55,
    TAB_H       = 48,
    SEPARATOR_W = 2,
    SEPARATOR_H = 48,
    BTN_W = 40,
    BTN_H = 40,

#else
    TAB_W       = 104,
    TAB_H       = 77,
    SEPARATOR_W = 2,
    SEPARATOR_H = 50,
    BTN_W = 50,
    BTN_H = 50,

#endif
};

enum VappGalleryVideoPlayerLayout
{
#if defined(__MMI_MAINLCD_480X800__)
    TITLE_PANEL_X = 400,
    TITLE_PANEL_W = 636,
    TITLE_PANEL_FONT_SIZE = 24,
    SETTING_BTN_X = 732,
    SETTING_BTN_W = 40,
    SETTING_BTN_H = 40,
    SETTING_X = 787,    // right-top of setting panel
    SETTING_Y = 97,
    VCR_PANEL_X = 10,
    VCR_PANEL_Y = 376,
    VCR_PANEL_W = 779,
    VCR_PANEL_H = 104,
    VCR_SEEKBAR_X = 132,
    VCR_SEEKBAR_Y = 404,
    VCR_SEEKBAR_W = 635,
    VCR_POSITION_TEXT_X = 115,
    VCR_POSITION_TEXT_Y = 439,
    VCR_DURATION_TEXT_X = 722,
    VCR_DURATION_TEXT_Y = 439,

#elif defined(__MMI_MAINLCD_320X480__)
    TITLE_PANEL_X = 240,
    TITLE_PANEL_W = 382,
    TITLE_PANEL_FONT_SIZE = 15,
    SETTING_BTN_X = 441,
    SETTING_BTN_W = 25,
    SETTING_BTN_H = 25,
    SETTING_X = 478,
    SETTING_Y = 61,
    VCR_PANEL_X = 4,
    VCR_PANEL_Y = 247,
    VCR_PANEL_W = 473,
    VCR_PANEL_H = 76,
    VCR_SEEKBAR_X = 84,
    VCR_SEEKBAR_Y = 274,
    VCR_SEEKBAR_W = 376,
    VCR_POSITION_TEXT_X = 76,
    VCR_POSITION_TEXT_Y = 296,
    VCR_DURATION_TEXT_X = 470,
    VCR_DURATION_TEXT_Y = 296,

#elif defined(__MMI_MAINLCD_240X320__)
    TITLE_PANEL_X = 160,
    TITLE_PANEL_W = 252,
    TITLE_PANEL_FONT_SIZE = 13,
    SETTING_BTN_X = 294,
    SETTING_BTN_W = 18,
    SETTING_BTN_H = 19,
    SETTING_X = 292,
    SETTING_Y = 51,
    VCR_PANEL_X = 1,
    VCR_PANEL_Y = 183,
    VCR_PANEL_W = 317,
    VCR_PANEL_H = 58,
    VCR_SEEKBAR_X = 67,
    VCR_SEEKBAR_Y = 206,
    VCR_SEEKBAR_W = 101,
    VCR_POSITION_TEXT_X = 57,
    VCR_POSITION_TEXT_Y = 223,
    VCR_DURATION_TEXT_X = 283,
    VCR_DURATION_TEXT_Y = 223,

#elif defined(__MMI_MAINLCD_240X400__)
    TITLE_PANEL_X = 200,
    TITLE_PANEL_W = 332,
    TITLE_PANEL_FONT_SIZE = 13,
    SETTING_BTN_X = 374,
    SETTING_BTN_W = 18,
    SETTING_BTN_H = 19,
    SETTING_X = 372,
    SETTING_Y = 51,
    VCR_PANEL_X = 1,
    VCR_PANEL_Y = 183,
    VCR_PANEL_W = 397,
    VCR_PANEL_H = 58,
    VCR_SEEKBAR_X = 67,
    VCR_SEEKBAR_Y = 206,
    VCR_SEEKBAR_W = 235,
    VCR_POSITION_TEXT_X = 57,
    VCR_POSITION_TEXT_Y = 223,
    VCR_DURATION_TEXT_X = 283,
    VCR_DURATION_TEXT_Y = 223,

#else
    TITLE_PANEL_X = 400,
    TITLE_PANEL_W = 316,
    TITLE_PANEL_FONT_SIZE = 24,
    SETTING_BTN_X = 732,
    SETTING_BTN_W = 40,
    SETTING_BTN_H = 40,
    SETTING_X = 787,
    SETTING_Y = 97,
    VCR_PANEL_X = 10,
    VCR_PANEL_Y = 376,
    VCR_PANEL_W = 779,
    VCR_PANEL_H = 104,
    VCR_SEEKBAR_X = 132,
    VCR_SEEKBAR_Y = 404,
    VCR_SEEKBAR_W = 635,
    VCR_POSITION_TEXT_X = 115,
    VCR_POSITION_TEXT_Y = 439,
    VCR_DURATION_TEXT_X = 722,
    VCR_DURATION_TEXT_Y = 439,

#endif
};

/*****************************************************************************
 * Function
 *****************************************************************************/
static const VfxWChar* findURLNameSection(const VfxWChar* url)
{
    if(NULL == url)
    {
        return NULL;
    }

    VfxS32 url_len = mmi_wcslen(url);
    const VfxWChar *title_ptr = url + (url_len - 1);
    if (url_len > 1 && *title_ptr != L'/')
    {
        while (*title_ptr != L'/' && url_len > 0)
        {
            --title_ptr;
            --url_len;
        }
        ++title_ptr;
    }
    else
    {
        title_ptr = url;
    }
    return title_ptr;
}

static mmi_ret _onPlayerPageVolumeChange(mmi_event_struct *param)
{
    if(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE != param->evt_id ||
       sizeof(vapp_vol_dialog_evt_struct) != param->size)
    {
        return MMI_RET_OK;
    }

    vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*)param;
    if(VAPP_VOL_DIALOG_IS_MEDIA == volEvent->type)
    {
        return !MMI_RET_OK;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
VappGalleryPlayerPage* VappGalleryPlayerPage::g_inst = NULL;

// #define VIDEO_SCROLLABLE_TEST

#ifdef VIDEO_SCROLLABLE_TEST
extern "C"
{
VfxS32 g_test_scrollable_video_frame = 0;

void flipScrollableVideoTest()
{
    if(g_test_scrollable_video_frame)
        g_test_scrollable_video_frame = 0;
    else
        g_test_scrollable_video_frame = 1;
}
}
#endif // VIDEO_SCROLLABLE_TEST

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryPlayerPage", VappGalleryPlayerPage, VappGalleryPage);
VFX_IMPLEMENT_CLASS("VappGalleryScreenModeHelper", VappGalleryScreenModeHelper, VfxObject);

/*****************************************************************************
 * VappGalleryVideoPlayerSlider Implementation
 *****************************************************************************/
#define VCP_SLIDER_TRACK_MARGIN 3

VappGalleryVideoPlayerSliderBarView::VappGalleryVideoPlayerSliderBarView():
    m_downloadProgress(0)
    ,m_downloadProgressImg(IMG_ID_VAPP_GALLERY_VID_PGDL_PROGRESS_TRACK)
{
}

void VappGalleryVideoPlayerSliderBarView::setDownloadProgress(VfxS32 progress)
{
    m_downloadProgress = vfxMax(0, progress);
    invalidate();
}

static VfxS32 calculateImgPos(VfxS32 value, VfxS32 sliderWidth)
{
    VfxFloat ratio = ((VfxFloat)value) / ((VfxFloat)(sliderWidth));
    VfxS32 div = value - (VfxS32)(((VfxFloat)(VCP_SLIDER_TRACK_MARGIN<<1))*ratio);
    if(div < 3)
    {
         if(div > 0)
         {
              div = 3;
         }
    }
    return div;
}

void VappGalleryVideoPlayerSliderBarView::onDraw(VfxDrawContext &dc)
{
    const VfxS32 w = getSize().width;
    const VfxS32 h =  getSize().height;
    if(w < h || m_trackImgType == VCP_SLIDER_SINGLE_TRACK_IMG)
    {
        // draw downloaded parts, only support Horz
        // and separated style
        VcpSliderBarView::onDraw(dc);
        return;
    }

    const VfxSize slider_size = getParentFrame()->getSize();
    const VfxSize imgSize = m_downloadProgressImg.getSize();
    if(w > h) // Horizontal layout
    {
        VfxS32 l = calculateImgPos(m_divider, slider_size.width);
        VfxS32 r = calculateImgPos(m_downloadProgress, slider_size.width);
        if(r > l)
        {
            dc.drawResizedImage(VfxRect(0, 0, r, h), m_downloadProgressImg);
        }
    }

    // draw basic slider
    VcpSliderBarView::onDraw(dc);
}

void VappGalleryVideoPlayerSlider::onInit()
{
    VcpSlider::onInit();
    m_enableAvailableRegion = VFX_FALSE;
    m_availableRegion = 0.0f;
    setLayout(VCP_SLIDER_LAYOUT_HORZ);
    VcpSliderBarView *track = NULL;
    VFX_OBJ_CREATE(track, VappGalleryVideoPlayerSliderBarView, this);
    setTrack(track);
    track->sendToBack();
}

void VappGalleryVideoPlayerSlider::setCurrentValue(VfxFloat value)
{
    if(m_enableAvailableRegion)
    {
        value = vfxMin(value, m_availableRegion);
    }
    VcpSlider::setCurrentValue(value);
}

void VappGalleryVideoPlayerSlider::setIsDisabled(VfxBool isDisabled)
{
    VcpSlider::setIsDisabled(isDisabled);
    if(m_thumb)
    {
        m_thumb->setIsDisabled(isDisabled);
    }
    return;
}

void VappGalleryVideoPlayerSlider::setThumbHidden(VfxBool isHidden)
{
    if(m_thumb)
    {
        m_thumb->setHidden(isHidden);
    }
    return;
}

void VappGalleryVideoPlayerSlider::enableAvailableRegion(VfxBool enable)
{
    m_enableAvailableRegion = enable;
}

void VappGalleryVideoPlayerSlider::setAvailableRegion(VfxFloat value)
{
    if(!m_enableAvailableRegion)
    {
        return;
    }
    const VfxFloat maxValue = getMaxValue();
    const VfxFloat minValue = getMinValue();
    value = vfxMax(minValue, vfxMin(value, maxValue));
    m_availableRegion = value;

    const VfxFloat ratio = ((value - minValue)/(maxValue - minValue));
    const VfxS32 length = getSize().width;
    VfxS32 pos = (VfxS32)(length * ratio);
    ((VappGalleryVideoPlayerSliderBarView*)m_track)->setDownloadProgress(pos);
}

/*****************************************************************************
 * Class VappGalleryPlayerPage
 *****************************************************************************/
const VappVideoMsec VappGalleryPlayerPage::MSEC_PER_HOUR = 1000 * 60 * 60;

VappGalleryPlayerPage::VappGalleryPlayerPage():
    m_userProc(NULL),
    m_userData(NULL),
    m_titleBar(NULL),
    m_titlePanel(NULL),
    m_player(NULL),
    m_gestureTranslator(NULL),
    m_positionUpdateTimer(NULL),
    m_pdlUpdateTimer(NULL),
    m_VCRPanel(NULL),
    m_buttonPanel(NULL),
    m_seekPanel(NULL),
    m_settingPanel(NULL),
    m_settingBtn(NULL),
    m_seekBar(NULL),
    m_positionText(NULL),
    m_durationText(NULL),
    m_writeVideoInfoToDB(VFX_FALSE),
    m_writeLastPlayInfo(VFX_FALSE),
    m_videoDB(NULL),
    m_PlaybackFinishedTimer(NULL),
    m_keypadLongPressTimer(NULL),
    m_seekOffset(0),
    m_playPauseHelper(NULL),
    m_screenModeHelper(NULL),
    m_isRTSPLink(VFX_FALSE),
    m_autoStartPlay(VFX_FALSE),
    m_shouldPlayAfterSeek(VFX_FALSE),    
    m_isBesSurroundTurnedOn(VFX_FALSE),
    m_shouldSeekToBeginWhileExit(VFX_FALSE),
    m_disablePositionUpdateWhenExit(VFX_FALSE),
    m_disableKeyEventHandle(VFX_FALSE),
    m_isOnBeginSeekVideo(VFX_FALSE),
    m_prepareToPlay(VFX_FALSE),
    m_startingPos(0),  
    m_clipperCuiId(GRP_ID_INVALID),
    m_cuiCloseFunc(NULL),
    m_navigationUp(VFX_KEY_CODE_ARROW_RIGHT),
    m_navigationDown(VFX_KEY_CODE_ARROW_LEFT),
    m_pageRotation(VFX_SCR_ROTATE_TYPE_270),
    m_shouldPlayAfterNCenterExited(VFX_FALSE),
    m_isBarHiddenBeforePreviewPenDown(VFX_FALSE),
    m_selectPopup(NULL)
{
    m_currentFile.setEmpty();
}

void VappGalleryPlayerPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_INIT);
    VappGalleryPage::onInit();

    m_writeVideoInfoToDB = VFX_FALSE;
    m_writeLastPlayInfo = VFX_FALSE;
    m_videoDB = NULL;

    // create background
    setBgColor(VFX_COLOR_BLACK);
    /* remove : MAUI_02877098
    VfxFrame *bgFrame = NULL;
    VFX_OBJ_CREATE(bgFrame, VfxFrame, this);
    bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_VID_BG));
    bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bgFrame->setPos(0, 0);
    bgFrame->setSize(getSize());
    bgFrame->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    */

    // setup phone diration
    updatePageRotationByPreviousScreen();

    // create gesture translator
    VFX_OBJ_CREATE(m_gestureTranslator, VappGalleryGestureTranslator, this);
    m_gestureTranslator->m_signalGestureRecognized.connect(this, &VappGalleryPlayerPage::onGesture);

    // create video player control
    createPlayerControl();

    // create Title bar (above video player)
    createTopBar();

    // create user controls (play/pause/seek)
    // and connect events to handlers
    createVCRControl();

    // playing position update logic
    const VfxMsec POSITION_UPDATE_INTERVAL = 200;
    VFX_OBJ_CREATE(m_positionUpdateTimer, VfxTimer, this);
    m_positionUpdateTimer->setDuration(POSITION_UPDATE_INTERVAL);
    m_positionUpdateTimer->setStartDelay(0);
    m_positionUpdateTimer->m_signalTick.connect(this, &VappGalleryPlayerPage::onUpdatePosition);

    // hold bearer for wifi connection
    cbm_hold_bearer(VappGalleryApp::getCBMAppId());
}

void VappGalleryPlayerPage::onDeinit()
{
    if(m_player)
    {
        // since we're closing,
        // follow operations should consume DRM
        // this is just for safety since m_player
        // is going to be destroyed anyway
        m_player->enableConsumeDRM(VFX_TRUE);
    }

#ifdef __MMI_VIDEO_CLIPPER__
    // close CUIs
    if((GRP_ID_INVALID != m_clipperCuiId) && m_cuiCloseFunc)
    {
        mmi_frm_group_set_caller_proc(m_clipperCuiId, NULL, NULL);

        // since we're destroying this object,
        // we cannot use this object to post-invoke.
        // use APP instead.
        VfxApp::postInvoke(&delay_close_cui_func,
                           *((void**)((void*)(&m_cuiCloseFunc))),
                           reinterpret_cast<void*>(m_clipperCuiId),
                           NULL);
    }
    m_clipperCuiId = GRP_ID_INVALID;
    m_cuiCloseFunc = NULL;
#endif

    // release bearer for wifi connection
    cbm_release_bearer(VappGalleryApp::getCBMAppId());

    VappGalleryPage::onDeinit();
}

void VappGalleryPlayerPage::createPlayerControl()
{
    if(m_player)
    {
        return;
    }

    VappVideoPlayerPlayOption option;
    option.configAsNormalVideo();
    option.isKeepBacklight = VFX_TRUE;
    option.supportSubtitle = isSubtitleSupport();

#ifdef VIDEO_SCROLLABLE_TEST
    flipScrollableVideoTest();

    if(g_test_scrollable_video_frame)
    {
        VcpScrollable *m_body;
        VFX_OBJ_CREATE(m_body, VcpScrollable, this);

        m_body->setSize(getSize());
        m_body->setPos(0, 0);

        m_body->setContentSize(VfxSize(getSize().width, 4000));
        m_body->setViewRect(VfxRect(0, 0, getSize().width, getSize().height));
        m_body->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);
        m_body->setBgColor(VFX_COLOR_BLACK);
        // create Video Player control
        VFX_OBJ_CREATE_EX(m_player, VappVideoPlayerComponent, m_body, (option));
    }
    else
    {
        // create Video Player control
        VFX_OBJ_CREATE_EX(m_player, VappVideoPlayerComponent, this, (option));
    }
#else  // VIDEO_SCROLLABLE_TEST
    // create Video Player control
    VFX_OBJ_CREATE_EX(m_player, VappVideoPlayerComponent, this, (option));
#endif // VIDEO_SCROLLABLE_TEST

    // we're always full-screen, no scrolling allowed, so disable to speed up.
    m_player->enableScrolling(VFX_FALSE);
    m_player->setSize(getSize());
    m_player->setPos(0, 0);
    m_player->setIsUnhittable(VFX_TRUE);
    m_player->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    m_player->m_signalFileOpened.connect(this, &VappGalleryPlayerPage::onVideoOpened);
    m_player->m_signalPlayerStateChange.connect(this, &VappGalleryPlayerPage::onPlayerStateChanged);
    m_player->m_signalPlaybackFinished.connect(this, &VappGalleryPlayerPage::onPlaybackFinished);
    m_player->m_signalSeekFinished.connect(this,&VappGalleryPlayerPage::onSeekFinished);
}

void VappGalleryPlayerPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_EXIT);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

#ifdef __MMI_AVRCP_SUPPORT__
    // unregister AVRCP
    srv_avrcp_clear_cmd_hdlr(callbackAVRCPCommand);
    g_inst = NULL;
#endif

    // close the playback finished timer
    VFX_OBJ_CLOSE(m_PlaybackFinishedTimer);

    // diable the key event handle
    m_disableKeyEventHandle = VFX_TRUE;

    // stop poistion update timer
    if(m_positionUpdateTimer)
    {
        m_positionUpdateTimer->stop();
    }

    if(m_pdlUpdateTimer)
    {
        m_pdlUpdateTimer->stop();
    }

    // stop keypad long press timer
    if(m_keypadLongPressTimer)
    {
        m_keypadLongPressTimer->stop();
    }
    // check if user do seek behavior
    if(m_isOnBeginSeekVideo)
    {
        onEndSeekVideo(m_seekBar, m_seekBar->getCurrentValue());
    }

    if(m_player)
    {
        // check if playback is unfinished
        VappVideoMsec currentPosition = 0;
        VappVideoMsec totalDuration = 0;

        // pause player first to avoid getting wrong current position
        const VappVideoPlayerState beforeState= m_player->getState();
        m_player->pause();
        switch(beforeState)
        {
        case VGPS_PAUSED:
        case VGPS_PLAYING:
        case VGPS_SEEKING:
            m_player->getCurrentTime(currentPosition);
            m_player->getTotalDuration(totalDuration);
            break;
        default:
            if(m_player->getIsSwitching())
            {
                m_player->getCurrentTime(currentPosition);
                m_player->getTotalDuration(totalDuration);
            }
            else
            {
                currentPosition = m_startingPos;
            }
            break;
        }

        // check the current pos while exit
        // note some files are not seekable in FLV,
        // in this case, the current pos will restore to 0
        // note if before state is VGPS_OPENING or VGPS_CLOSE,
        // it is false returned from isSeekable()
        if((!m_player->isSeekable()) && (VGPS_OPENING != beforeState))
        {
            m_shouldSeekToBeginWhileExit = VFX_TRUE;
        }

        // check if we need to resume playback after interruption
        // note only PLAYING state [MAUI_02456552] and shouldPlayAfterSeek [MAUI_02931850]
        // should force auto start play while enter next time,
        // other case we remain same state
        // to avoid repeate enter and exit behavior (ex: lock, oncall, call terminate, and then unlock)
        // changing m_autoStartPlay to wong value
        if(VGPS_PLAYING == beforeState || m_shouldPlayAfterSeek || m_shouldPlayAfterNCenterExited)
        {
            m_autoStartPlay = VFX_TRUE;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_EXIT_AUTO_START_PLAY_CHECK, beforeState, m_shouldPlayAfterSeek, m_shouldPlayAfterNCenterExited, m_autoStartPlay);
        // reset NCenter flag to prevent auto play wrongly 
        m_shouldPlayAfterNCenterExited = VFX_FALSE;
        m_prepareToPlay = VFX_FALSE;
        // check if not started or reaches end
        if(totalDuration != 0 &&
           currentPosition <= totalDuration)
        {
            if((0 == currentPosition) || (totalDuration == currentPosition))
            {
                updateVideoPlayInfo(VGFS_FINISHED, 0);
                postToUser(m_currentFile, 0);
            }
            else
            {
                updateVideoPlayInfo(VGFS_UNFINISHED, currentPosition);
                postToUser(m_currentFile, currentPosition);
            }
        }
        else
        {
            postToUser(m_currentFile, 0);
        }

        m_startingPos = currentPosition;
    }

    VFX_OBJ_CLOSE(m_videoDB);

    // unregister nCenter event
    registerNotificationCenterEvent(VFX_FALSE);

    // turn off sound effect
    turnOnBesSurround(VFX_FALSE);

    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &_onPlayerPageVolumeChange, this);

    return VappGalleryPage::onExit(isBackward);
}

void VappGalleryPlayerPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_EXITED2);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    if(pMainScr)
    {
        pMainScr->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    }

#if defined(__MMI_CABC__)
    getApp()->resetCABCMode();
#endif

    // closes video player component
    m_player->closeFile();

    // reset update position logic
    m_disablePositionUpdateWhenExit = VFX_FALSE;

    return VappGalleryPage::onExited2();
}

void VappGalleryPlayerPage::onBack()
{
    VappGalleryPage::onBack();
}

void VappGalleryPlayerPage::postToUser(const VfxWString &filePath, U64 lastPlayTime)
{
    if(m_userProc)
    {
        vapp_gallery_last_play_struct last_play_struct;
        vapp_gallery_last_play_struct_init(&last_play_struct);
        last_play_struct.file_path = (WCHAR*)filePath.getBuf();
        last_play_struct.last_play_time = lastPlayTime;

        m_userProc(&last_play_struct, m_userData);
    }
}

void VappGalleryPlayerPage::createVCRControl()
{
    VFX_DEV_ASSERT(NULL == m_VCRPanel);
    VFX_OBJ_CREATE(m_VCRPanel, VfxFrame, this);
    m_VCRPanel->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_VID_BTN_VCR_BG));
    m_VCRPanel->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_VCRPanel->setPos(VCR_PANEL_X, VCR_PANEL_Y);
    m_VCRPanel->setSize(VCR_PANEL_W, VCR_PANEL_H);
    m_VCRPanel->setIsUnhittable(VFX_TRUE); // set panel to unhittable to avoid funzzy boundary of slider reduce fozzy region

    // panel that contains seekbar and duration/position time text
    VFX_DEV_ASSERT(NULL == m_seekPanel);
    VFX_OBJ_CREATE(m_seekPanel, VfxFrame, this);
    VfxXmlLoader::loadBegin(m_seekPanel, VAPP_GALLERY_LAYOUT_VIDEO_PLAYER_SEEK_BAR_PANEL);

    VfxFrame *seekbarFrame = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("seekbarFrame")), VfxFrame);
    seekbarFrame->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_seekBar, VappGalleryVideoPlayerSlider, m_seekPanel);
    m_seekBar->setLength(seekbarFrame->getSize().width);
    m_seekBar->setPos(seekbarFrame->getPos());

    m_positionText = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("positionText")), VfxTextFrame);
    m_durationText = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("durationText")), VfxTextFrame);
    VfxXmlLoader::loadEnd();

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    m_positionText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_durationText->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
#else
    m_positionText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_durationText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
#endif

    m_durationText->setIsUnhittable(VFX_TRUE);
    m_positionText->setIsUnhittable(VFX_TRUE);
    setTimeTextFormat(m_positionText);
    setTimeTextFormat(m_durationText);
    m_durationText->setHidden(VFX_FALSE);
    m_positionText->setHidden(VFX_FALSE);
    setTimeText(m_durationText, 0);
    setTimeText(m_positionText, 0);

    m_seekBar->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_seekBar->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_seekBar->m_signalThumbPressed.connect(this, &VappGalleryPlayerPage::onBeginSeekVideo);
    m_seekBar->m_signalThumbDrag.connect(this, &VappGalleryPlayerPage::onSeekVideo);
    m_seekBar->m_signalThumbReleased.connect(this, &VappGalleryPlayerPage::onEndSeekVideo);

    // panel that contains play/pause and other command buttons
    VFX_DEV_ASSERT(NULL == m_buttonPanel);
    VFX_OBJ_CREATE(m_buttonPanel, VfxFrame, this);
    VfxXmlLoader::loadBegin(m_buttonPanel, VAPP_GALLERY_LAYOUT_VIDEO_PLAYER_BUTTON_PANEL);
    VfxXmlLoader::loadEnd();
    m_buttonPanel->setPos(m_buttonPanel->getPos().x, VCR_PANEL_Y + (VfxS32)((VCR_PANEL_H - m_buttonPanel->getSize().height) * 0.5f));

    VcpButton *playBtn = NULL;
    VcpButton *pauseBtn = NULL;
    VFX_OBJ_CREATE(playBtn, VcpButton, m_buttonPanel);
    playBtn->setSize(m_buttonPanel->getSize());
    playBtn->setBgImageList(VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_BG_N, IMG_ID_VAPP_GALLERY_VID_BTN_BG_P, IMG_ID_VAPP_GALLERY_VID_BTN_BG_D, 0));
    playBtn->setImage(IMG_ID_VAPP_GALLERY_VID_BTN_FG_PLAY);
    playBtn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    playBtn->setMargin(0, 0, 0, 0);    // for central aligned

    VFX_OBJ_CREATE(pauseBtn, VcpButton, m_buttonPanel);
    pauseBtn->setSize(m_buttonPanel->getSize());
    pauseBtn->setBgImageList(VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_BG_N, IMG_ID_VAPP_GALLERY_VID_BTN_BG_P, IMG_ID_VAPP_GALLERY_VID_BTN_BG_D, 0));
    pauseBtn->setImage(IMG_ID_VAPP_GALLERY_VID_BTN_FG_PAUSE);
    pauseBtn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    pauseBtn->setMargin(0, 0, 0, 0);    // for central aligned

    VFX_OBJ_CREATE(m_playPauseHelper, VappGalleryPlayPauseHelper, this);
    m_playPauseHelper->setup(playBtn, pauseBtn);
    m_playPauseHelper->setIsDisabled(VFX_TRUE);
    m_playPauseHelper->getSignalTapped()->connect(this, &VappGalleryPlayerPage::onButtonTapped);
    return;
}

void VappGalleryPlayerPage::setCustomTitle(const VfxWString &title)
{
    if(m_titlePanel)
        m_titlePanel->setString(title);
}

void VappGalleryPlayerPage::createTopBar()
{
    VFX_DEV_ASSERT(NULL == m_titleBar);
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_EMPTY);
    setTopBar(m_titleBar);
    // set page & bar style
    setTranslucent(VFX_TRUE);

    // create title bar panel
    VFX_OBJ_CREATE(m_titlePanel, VfxTextFrame, m_titleBar);
    m_titlePanel->setSize(TITLE_PANEL_W, m_titleBar->getSize().height);
    m_titlePanel->setAnchor(0.5f, 0.5f);
    m_titlePanel->setPos(TITLE_PANEL_X, m_titleBar->getSize().height / 2);
    m_titlePanel->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_titlePanel->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(TITLE_PANEL_FONT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    m_titlePanel->setFont(fontDesc);

    // create setting btn
    VFX_OBJ_CREATE(m_settingBtn, VcpImageButton, m_titleBar);
    m_settingBtn->setImage(VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_SETTING, IMG_ID_VAPP_GALLERY_VID_BTN_SETTING, IMG_ID_VAPP_GALLERY_VID_BTN_SETTING_D, IMG_ID_VAPP_GALLERY_VID_BTN_SETTING));
    m_settingBtn->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_settingBtn->setIsEffect(VFX_TRUE);
    m_settingBtn->setSize(SETTING_BTN_W, SETTING_BTN_H);
    m_settingBtn->setAnchor(0.5f, 0.5f);
    m_settingBtn->setPos(SETTING_BTN_X, (VfxS32)(m_titleBar->getSize().height * 0.5f));
    m_settingBtn->setId('SET');
    m_settingBtn->m_signalClicked.connect(this, &VappGalleryPlayerPage::onButtonTapped);
}

void VappGalleryPlayerPage::createSettingPanel()
{
    if(m_settingPanel || NULL == m_player)
    {
        return;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_CREATE_SETTING_PANEL, m_player->getState());

    VFX_OBJ_CREATE(m_settingPanel, VappGalleryFloatSettingPnael, this);
    // align parent by right-top connor
    m_settingPanel->setAnchor(1.f, 0.f);
    m_settingPanel->setPos(SETTING_X, SETTING_Y);
    m_settingPanel->getSignalTapped()->connect(this, &VappGalleryPlayerPage::onButtonTapped);
    m_settingPanel->setHidden(VFX_TRUE);

    /* config setting buttons */
    // video render mode
    // TODO:  Add general multiple state button create/event handle method
    if(1 < m_player->getSupportedScreenModeCount())
    {
        const VappVideoPlayerScreenMode defaultVSMode = m_player->getDefaultScreenMode();
        createScreenModeControl(defaultVSMode, m_settingPanel);
        if(m_screenModeHelper)
            m_settingPanel->addMultiStateTab(m_screenModeHelper);
    }
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    m_settingPanel->addBinaryTab('BES',
        VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_N,
                      IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_N,
                      IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_D,
                      IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_ON),
                      m_isBesSurroundTurnedOn);
#endif
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    // add 3D anaglyph icon only if project supports 3D anaglyph and there is 3D track
    const VfxBool canSwitch3D = m_player && m_player->canSwitchTo3DAnaglyph(VFX_TRUE);
    if(canSwitch3D)
    {
        const VfxBool is3D = canSwitch3D && m_player && m_player->getIs3DAnaglyphMode();
        m_settingPanel->addBinaryTab('V3D',
            VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_3D_N,
                          IMG_ID_VAPP_GALLERY_VID_BTN_3D_N,
                          IMG_ID_VAPP_GALLERY_VID_BTN_3D_D,
                          IMG_ID_VAPP_GALLERY_VID_BTN_3D_ON),
            is3D);
    }
#endif
#ifdef __MMI_VIDEO_CLIPPER__
    if(!isPlayerCui() && m_player->canClip())
    {
        m_settingPanel->addBinaryTab('EDI',
            VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_EDIT_N,
                          IMG_ID_VAPP_GALLERY_VID_BTN_EDIT_N,
                          IMG_ID_VAPP_GALLERY_VID_BTN_EDIT_D,
                          IMG_ID_VAPP_GALLERY_VID_BTN_EDIT_N));
    }
#endif
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    // add subtitle language icon only if project supports support and there is subtitle track
    if(0 < m_player->getSubtitleTrackCount())
    {
        m_settingPanel->addBinaryTab('LAN',
            VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_SUBTITLE_LANGUAGE_N,
                          IMG_ID_VAPP_GALLERY_VID_BTN_SUBTITLE_LANGUAGE_N,
                          IMG_ID_VAPP_GALLERY_VID_BTN_SUBTITLE_LANGUAGE_D,
                          IMG_ID_VAPP_GALLERY_VID_BTN_SUBTITLE_LANGUAGE_N));
    }
#endif
}

void VappGalleryPlayerPage::onSettingBtnTapped()
{
    if(NULL == m_settingPanel)
    {
        return;
    }

    const VfxBool isHidden = m_settingPanel->getHidden();
    m_settingPanel->setHidden(!isHidden);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_SETTING_BTN_TAPPED, !isHidden);
}

// TODO:  add multi-state btn
void VappGalleryPlayerPage::createScreenModeControl(const VappVideoPlayerScreenMode defaultVSMode, VfxFrame *parentFrame)
{
    if(NULL == parentFrame){return;}
    VcpImageButton *normalBtn = NULL;
    VFX_OBJ_CREATE(normalBtn, VcpImageButton, parentFrame);
    VcpStateImage normalStateIng(IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_NORMAL_N,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_NORMAL_N,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_NORMAL_D,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_NORMAL_N);
    normalBtn->setImage(normalStateIng);
    normalBtn->setSize(EO_BTN_W, EO_BTN_H);
    normalBtn->setAnchor(0.5, 0.5);

    VcpImageButton *clippedBtn = NULL;
    VFX_OBJ_CREATE(clippedBtn, VcpImageButton, parentFrame);
    VcpStateImage clipStateImg(IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_CLIP_N,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_CLIP_N,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_CLIP_D,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_CLIP_N);
    clippedBtn->setImage(clipStateImg);
    clippedBtn->setSize(EO_BTN_W, EO_BTN_H);
    clippedBtn->setAnchor(0.5, 0.5);

    VcpImageButton *resizedBtn = NULL;
    VFX_OBJ_CREATE(resizedBtn, VcpImageButton, parentFrame);
    VcpStateImage resizedStateImg(IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_RESIZE_N,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_RESIZE_N,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_RESIZE_D,
                                IMG_ID_VAPP_GALLERY_VID_BTN_SCREEN_RESIZE_N);
    resizedBtn->setImage(resizedStateImg);
    resizedBtn->setSize(EO_BTN_W, EO_BTN_H);
    resizedBtn->setAnchor(0.5, 0.5);

    // create screen mode helper
    VFX_OBJ_CREATE(m_screenModeHelper, VappGalleryScreenModeHelper, this);
    m_screenModeHelper->setup(normalBtn, clippedBtn, resizedBtn, defaultVSMode);
    m_screenModeHelper->getSignalTapped()->connect(this, &VappGalleryPlayerPage::onButtonTapped);
}

void VappGalleryPlayerPage::setTimeTextFormat(VfxTextFrame *timeText)
{
    timeText->setAutoResized(VFX_FALSE);
    timeText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
    timeText->setFont(VfxFontDesc(
                            VFX_FONT_DESC_VF_SIZE(timeText->getSize().height),
                            VFX_FONT_DESC_ATTR_MONOSPACE));
    timeText->setAutoFontSize(VFX_TRUE);
}

void VappGalleryPlayerPage::updatePageRotationByPreviousScreen()
{
    // query the phone rotation of the previous scrren (which lauches video player)
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxScrRotateTypeEnum screenRotation = renderer->getPreScreenRotateType();
    configPageRotation(screenRotation);
}

void VappGalleryPlayerPage::configPageRotation(const VfxScrRotateTypeEnum screenRotation)
{
    // note video player page always in horizontal screen and
    // keypad will remapping when rotate screen
    switch(screenRotation)
    {
    case VFX_SCR_ROTATE_TYPE_90:
        m_navigationUp = VFX_KEY_CODE_ARROW_LEFT;
        m_navigationDown = VFX_KEY_CODE_ARROW_RIGHT;
        m_pageRotation = VFX_SCR_ROTATE_TYPE_90;
        break;
    default:
        m_navigationUp = VFX_KEY_CODE_ARROW_RIGHT;
        m_navigationDown = VFX_KEY_CODE_ARROW_LEFT;
        m_pageRotation = VFX_SCR_ROTATE_TYPE_270;
        break;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_CONFIG_PAGE_ROTATION, screenRotation, m_pageRotation);
}

void VappGalleryPlayerPage::createKeypadLongPressTimer()
{
    if(NULL == m_keypadLongPressTimer)
    {
        VFX_OBJ_CREATE(m_keypadLongPressTimer, VfxTimer, this);
        m_keypadLongPressTimer->setStartDelay(KEYPAD_LONG_PRESS_TIMER_DURATION);
        m_keypadLongPressTimer->setDuration(KEYPAD_LONG_PRESS_TIMER_DURATION);
        m_keypadLongPressTimer->m_signalTick.connect(this, &VappGalleryPlayerPage::onKeypadLongPressTimeout);
    }
}

void VappGalleryPlayerPage::onKeypadLongPressTimeout(VfxTimer *timer)
{
    VappVideoMsec totalPos = 0;
    m_player->getTotalDuration(totalPos);
    if(0 == totalPos)
    {
        timer->stop();
        return;
    }

    VfxFloat value = calculateSeekValueForKeySuppot(totalPos);
    m_seekBar->setCurrentValue(value);
    onSeekVideo(m_seekBar, m_seekBar->getCurrentValue());
}

void VappGalleryPlayerPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_ENTER);
    VappGalleryPage::onEnter(isBackward);
    // change the parent screen color to black
    VfxMainScr *pScr = getMainScr();
    if(pScr)
    {
        pScr->setBgColor(getBgColor());
    }

    // reset update position logic
    m_disablePositionUpdateWhenExit = VFX_FALSE;
    // reset preview pen down logic
    m_isBarHiddenBeforePreviewPenDown = VFX_FALSE;
}

void VappGalleryPlayerPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_ENTERED);
    VappGalleryPage::onEntered();

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    checkUpdate();
    hideAllBars(VFX_FALSE);

    // reset the key event handle disabled logic
    m_disableKeyEventHandle = VFX_FALSE;

#if defined(__MMI_CABC__)
    getApp()->setCABCMode(MMI_FRM_CABC_MODE_MOVING);
#endif
    //for MAUI_03241542, current screen is N-center,but ap can get onEnterd event
    if (vapp_ncenter_is_entered() == FALSE)
    {
        //acoording to MAUI_03198446 discussion, close background audio(not suspend)
        mdi_audio_terminate_background_play();

#ifdef __MMI_AVRCP_SUPPORT__
    // register AVRCP
    g_inst = this;
    srv_avrcp_set_cmd_hdlr(callbackAVRCPCommand);
#endif

    }
    // register nCenter event
    registerNotificationCenterEvent(VFX_TRUE);

    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &_onPlayerPageVolumeChange, this);

    openVideo();
}

void VappGalleryPlayerPage::configStoreLastPlay(VfxBool writeLastPlayToDB)
{
    // when config write to DB,
    // also allows update last play info
    m_writeVideoInfoToDB = writeLastPlayToDB;
    m_writeLastPlayInfo = writeLastPlayToDB;
}

void VappGalleryPlayerPage::configUserProcAndData(PFN_VAPP_GALLERY_LAST_PLAY_TIME_PROC userProc, void* userData)
{
    m_userProc = userProc;
    m_userData = userData;
}

void VappGalleryPlayerPage::setRTSPLink(const VfxWChar *url)
{
    m_isRTSPLink = VFX_TRUE;
    m_currentFile = VFX_WSTR_MEM(url);
    m_startingPos = 0;
    m_autoStartPlay = VFX_TRUE;

    if(m_player)
    {
        if(VGPS_CLOSED != m_player->getState())
        {
            m_player->stop();
            m_player->closeFile();
        }
        m_player->enableConsumeDRM(VFX_TRUE);   // new file, should consume DRM
    }

    if(m_titleBar)
    {
        VfxWString displayName;

        // check if there's CUI title override
        if(hasCustomTitle())
        {
            getCustomTitle(displayName);
        }
        else
        {
            // otherwise query proper display name from URL
            displayName = VFX_WSTR_MEM(findURLNameSection(url));
        }

       m_titlePanel->setString(displayName);
    }
}

void VappGalleryPlayerPage::setLocalFile(const VfxWChar *filepath, U64 startingMsec, VfxBool isPDL)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_SET_LOCAL_FILE);

    m_isRTSPLink = VFX_FALSE;
    m_isPDL = isPDL;
    m_currentFile = VFX_WSTR_MEM(filepath);
    m_startingPos = startingMsec;
    m_autoStartPlay = VFX_TRUE;

    if(m_player)
    {
        if(VGPS_CLOSED != m_player->getState())
        {
            m_player->stop();
            m_player->closeFile();
        }
        m_player->enableConsumeDRM(VFX_TRUE);   // new file, should consume DRM
    }

    if(m_titleBar)
    {
        VfxWString displayName;

        // check if there's CUI title override
        if(hasCustomTitle())
        {
            getCustomTitle(displayName);
        }
        else
        {
            // otherwise query proper display name from path and set to title bar
            const S32 dispLength = srv_fmgr_fs_path_get_display_name(filepath, NULL, 0);
            if(dispLength > 0)
            {
                const S32 bufSize = (dispLength + 1) * 2;
                displayName.setEmpty();
                VfxWChar *buf = displayName.lockBuf(bufSize);
                const S32 result = srv_fmgr_fs_path_get_display_name(filepath, buf, bufSize);
                displayName.unlockBuf();
                buf = NULL;
            }
        }

        m_titlePanel->setString(displayName);
    }

#ifdef __MMI_VIDEO_PDL__
    if(m_seekBar && m_isPDL)
    {
        // make sure the seek bar is in correct style
        VfxImageSrc img(VCP_IMG_SLIDER_HRZT_H);
        m_seekBar->setImageCompletedPart(img);
        m_seekBar->enableAvailableRegion(VFX_TRUE);
        // start PDL update timer
        const VfxMsec PDL_UPDATE_INTERVAL = 1500;
        if(NULL == m_pdlUpdateTimer)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_PDL_START_PDL_TIMER, 1, 1);
            VFX_OBJ_CREATE(m_pdlUpdateTimer, VfxTimer, this);
            m_pdlUpdateTimer->setDuration(PDL_UPDATE_INTERVAL);
            m_pdlUpdateTimer->setStartDelay(0);
            m_pdlUpdateTimer->m_signalTick.connect(this, &VappGalleryPlayerPage::onUpdatePDLRegion);
        }
    }

    if(!m_isPDL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_PDL_START_PDL_TIMER, 0, 0);
        VFX_OBJ_CLOSE(m_pdlUpdateTimer);
        m_seekBar->enableAvailableRegion(VFX_FALSE);
    }
#endif
}

VfxBool VappGalleryPlayerPage::isPlayerCui()
{
    VcuiGalleryVideoPlayer *cui = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr(getParentFrame())->getApp(), VcuiGalleryVideoPlayer);
    if(cui)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappGalleryPlayerPage::isMakingCall()
{
	return srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0;
}

void VappGalleryPlayerPage::onUpdate()
{
    VappGalleryPage::onUpdate();
}

mmi_ret VappGalleryPlayerPage::onProc(mmi_event_struct *evt)
{
#ifdef __GALLERY_DISABLE_NCENTER_IN_PLAYER__
    if(EVT_ID_VAPP_NCENTER_DRAG == evt->evt_id)
    {
        return MMI_RET_ERR;
    }
#endif

    if(EVT_ID_SRV_UCM_STATUS_CHANGE == evt->evt_id)
    {
        if(isMakingCall())
        {
            // If we want to close/open video when call state change,
            // we may check video open/close state here.
            // note video player CP blocks "play" operation.
        }
    }
    #ifdef __MMI_VIDEO_PDL__

    if(m_player)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][PDL] VappGalleryPlayerPage::onProc DA_EVENT: %d", evt->evt_id);
        switch(evt->evt_id)
        {
        case EVT_ID_VAPP_GALLERY_DA_PAUSE:
            m_player->enableAutoWaitPGDL(VFX_FALSE);
            break;
        case EVT_ID_VAPP_GALLERY_DA_RESUME:
            m_player->enableAutoWaitPGDL(VFX_TRUE);
            break;
        default:
            break;
        }
    }
    #endif

    return VfxPage::onProc(evt);
}

void VappGalleryPlayerPage::onGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture)
{
    if(VG_TAP != gesture)
        return;

    if(!m_isBarHiddenBeforePreviewPenDown)
    {
        hideAllBars(VFX_TRUE);
    }
    else
    {
        // show bars
        hideAllBars(VFX_FALSE);
    }
}

VfxBool VappGalleryPlayerPage::onPreviewPenInput(VfxPenEvent &event)
{
    if(VFX_PEN_EVENT_TYPE_DOWN == event.type)
    {
        m_isBarHiddenBeforePreviewPenDown = getIsBarHidden();
        hideAllBars(VFX_FALSE);
    }
    return VappGalleryPage::onPreviewPenInput(event);
}

VfxBool VappGalleryPlayerPage::onPenInput(VfxPenEvent &event)
{
    m_gestureTranslator->processPenEvent(this, event);
    return VFX_TRUE;
}

VfxBool VappGalleryPlayerPage::onKeyInput(VfxKeyEvent &event)
{
    if(m_disableKeyEventHandle)
    {
        return VappGalleryPage::onKeyInput(event);
    }

    if(VFX_KEY_CODE_ENTER == event.keyCode || VFX_KEY_CODE_CSK == event.keyCode)
    {
        if(m_playPauseHelper->getIsDisabled())
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_KEY_INPUT_ERR, -100);
            return VFX_TRUE;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_KEY_INPUT, event.keyCode, event.type);
        if(VFX_KEY_EVENT_TYPE_DOWN == event.type)
        {
            m_playPauseHelper->setActiveBtnState(VCP_BUTTON_STATE_PRESSED);
        }
        else if(VFX_KEY_EVENT_TYPE_UP == event.type)
        {
            m_playPauseHelper->setActiveBtnState(VCP_BUTTON_STATE_NORMAL);

            // switch player to do play and pause
            VfxId id = 'PAUS';
            if(m_playPauseHelper->isPlayBtnActive())
            {
                id ='PLAY';
            }
            onButtonTapped(NULL, id);
        }
        return VFX_TRUE;
    }
    else if(m_navigationUp == event.keyCode || (m_navigationDown == event.keyCode))
    {
        if(m_player->getIsSwitching())
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_KEY_INPUT_ERR, -200);
            return VFX_TRUE;
        }

        // check if player is seekable
        if(!m_player->isSeekable())
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_KEY_INPUT_ERR, -201);
            return VFX_TRUE;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_KEY_INPUT, event.keyCode, event.type);
        // set seek parameter
        m_seekOffset = 1000;
        if(m_navigationDown == event.keyCode)
        {
            m_seekOffset = -1000;
        }
        switch(event.type)
        {
            case VFX_KEY_EVENT_TYPE_DOWN:
            {
                VappVideoMsec totalPos = 0;
                m_player->getTotalDuration(totalPos);
                if(0 == totalPos){return VFX_TRUE;}

                onBeginSeekVideo(m_seekBar, m_seekBar->getCurrentValue());

                VfxFloat value = calculateSeekValueForKeySuppot(totalPos);
                m_seekBar->setCurrentValue(value);
                onSeekVideo(m_seekBar, m_seekBar->getCurrentValue());
            }

            case VFX_KEY_EVENT_TYPE_LONG_PRESS:
            {
                createKeypadLongPressTimer();
                m_keypadLongPressTimer->start();
                break;
            }
            case VFX_KEY_EVENT_TYPE_UP:
            {
                if(m_keypadLongPressTimer){m_keypadLongPressTimer->stop(); }
                onEndSeekVideo(m_seekBar, m_seekBar->getCurrentValue());
                break;
            }
            default:
                break;
        }

        return VFX_TRUE;
    }


    return VappGalleryPage::onKeyInput(event);
}

void VappGalleryPlayerPage::hideAllBars(VfxBool hide)
{
    VfxPage::hideAllBars(hide);
    if(!hide)
    {
        // show other controls (seekbar, playbtn, ...)
        showFrameImmediately(m_VCRPanel);
        showFrameImmediately(m_buttonPanel);
        showFrameImmediately(m_seekPanel);
        showFrameImmediately(m_settingPanel);
    }
}

void VappGalleryPlayerPage::onBarAutoHide()
{
    VappGalleryPage::onBarAutoHide();
    hideFrameAnimated(m_VCRPanel);
    hideFrameAnimated(m_buttonPanel);
    hideFrameAnimated(m_seekPanel);
    hideFrameAnimated(m_settingPanel);
}

VfxBool VappGalleryPlayerPage::getPageCurrentStorage(U8 &drvLetter)
{
    if(m_isRTSPLink)
    {
        return VFX_FALSE;
    }
    if(m_currentFile.isNull() || m_currentFile.isEmpty())
    {
        return VFX_FALSE;
    }
    drvLetter = *(const U8*)m_currentFile.getBuf();
    return VFX_TRUE;
}

// TODO: block streaming player
void VappGalleryPlayerPage::onEditFile(const VfxWString &path)
{
#if defined(__MMI_VIDEO_CLIPPER__)
    if(NULL == m_player){return;}
    // note video clipper only support for the videos shooted by internal recorder
    const VfxBool clipPreCheck = m_player->canClip();
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery] onEditFile, canClip[%d]", clipPreCheck);
    if( !clipPreCheck)
    {
        return;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_EDIT_FILE);
    do
    {
        VappVideoMsec curPos = 0;
        VappVideoMsec totalTime = 0;
        //MDI_RESULT res;
        //res = m_player->pause();
        //res = m_player->getCurrentTime(curPos);
        //res = m_player->getTotalDuration(totalTime);
        m_player->pause();
        m_player->getCurrentTime(curPos);
        m_player->getTotalDuration(totalTime);

        vcui_videoclipper_param_struct launchParam;
        memset(&launchParam, 0, sizeof(vcui_videoclipper_param_struct));
        // set file path
        mmi_wcscpy((WCHAR*)launchParam.filepath, (WCHAR*)path.getBuf());
        // set video duration
        launchParam.total_time = totalTime;
        // set keyframe time
        VappVideoMsec keyFrameTime = 0;
        MDI_RESULT resGetKeyFrameTime = m_player->getKeyFrameTime(curPos, keyFrameTime);
        launchParam.curr_time = (MDI_RES_VDOPLY_SUCCEED == resGetKeyFrameTime) ? keyFrameTime : 0;

        // register CUI event handler
        m_clipperCuiId = vcui_videoclipper_create(getApp()->getGroupId(), &launchParam);
        if (GRP_ID_INVALID != m_clipperCuiId)
        {
            m_cuiCloseFunc = vcui_videoclipper_close;
            mmi_frm_group_set_caller_proc(m_clipperCuiId, &VappGalleryPlayerPage::onVideoClipperEvent, getObjHandle());
            vcui_videoclipper_run(m_clipperCuiId);
        }

    }while(0);
#endif
}

mmi_ret VappGalleryPlayerPage::onVideoClipperEvent(mmi_event_struct *evt)
{
    VappGalleryPlayerPage *pThis = (VappGalleryPlayerPage*)handleToObject((VfxObjHandle)(evt->user_data));
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    return pThis->handleVideoClipperEvent(evt);
}

mmi_ret VappGalleryPlayerPage::handleVideoClipperEvent(mmi_event_struct *evt)
{
#if defined(__MMI_VIDEO_CLIPPER__)
    vcui_videoclipper_result_event_struct *clipperEvent = reinterpret_cast<vcui_videoclipper_result_event_struct*>(evt);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_HANDLE_VIDEO_CLIPPER_EVENT, clipperEvent->result);

    if(VCUI_VIDEOCLIPPER_EVENT_RESULT_SUCCESS == clipperEvent->result)
    {
        setTimeText(m_durationText, 0);
        setTimeText(m_positionText, 0);
        m_playPauseHelper->showPlayButton();
        m_seekBar->setCurrentValue(0);
        setLocalFile((const VfxWChar *)(clipperEvent->filepath), 0);

        // because duration of clipped video may less than clipped min clip duration, 
        // destory setting panel and reinit while video reopen
        VFX_OBJ_CLOSE(m_screenModeHelper);
        VFX_OBJ_CLOSE(m_settingPanel);
    }
    vcui_videoclipper_close(m_clipperCuiId);
    m_clipperCuiId = GRP_ID_INVALID;

    m_autoStartPlay = VFX_FALSE;
    m_shouldPlayAfterSeek = VFX_FALSE;
    return MMI_RET_OK;

#else
    return MMI_RET_OK;
#endif
}

void VappGalleryPlayerPage::delay_close_cui_func(void *pfnCloseFunc, void *cuiIdValue, void *dontCare)
{
    PFN_CUI_CLOSE closeFunc = reinterpret_cast<PFN_CUI_CLOSE>(pfnCloseFunc);
    if(closeFunc)
    {
        const U16 cuiId = (U16)(U32)cuiIdValue;
        closeFunc((mmi_id)cuiId);
    }
}

void VappGalleryPlayerPage::openVideo()
{
    if(m_player && VGPS_CLOSED == m_player->getState())
    {
        m_player->openFileEx(
            m_currentFile,
            m_isRTSPLink,
            m_startingPos,
            m_isPDL
            );
    }
}

void VappGalleryPlayerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = m_pageRotation; //VFX_SCR_ROTATE_TYPE_270;
}

void VappGalleryPlayerPage::onButtonTapped(VfxObject *button, VfxId id)
{
    if(isMakingCall())
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
        return;
    }

    switch(id)
    {
    case 'SET':
        onSettingBtnTapped();
        break;
    case 'BES':
    case 'V3D':
    case 'EDI':
    case 'LAN':
        onSettingCommand(button, id);
        break;
    case NORMAL:
    case CLIPPED:
    case RESIZED:
        if(m_screenModeHelper && m_player)
        {
            const VappVideoPlayerState curState = m_player->getState();
            if(VGPS_PLAYING == curState || VGPS_PAUSED == curState)
            {
                const VappVideoPlayerScreenMode nextMode = m_screenModeHelper->convertToVSMode((VappGalleryScreenModeHelperID)id);
                m_screenModeHelper->updateBtnStateByCurrentScreenMode(nextMode);
                m_player->setVideoScreenMode(nextMode);
            }
        }
        break;
    case 'PLAY':
        if(VGPS_CLOSED == m_player->getState())
        {
            m_autoStartPlay = VFX_TRUE;
            openVideo();
        }
        else
        {
            m_player->play();
        }
        break;
    case 'PAUS':
        m_player->pause();
        m_shouldPlayAfterSeek = VFX_FALSE;
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}

void VappGalleryPlayerPage::onSettingCommand(VfxObject *button, VfxId id)
{
    VcpImageButton *pBtn = VFX_OBJ_DYNAMIC_CAST(button, VcpImageButton);
    if(NULL == pBtn || NULL == m_player)
    {
        return;
    }

    VfxBool flag = VFX_FALSE;
    switch(id)
    {
    case 'BES':
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_SETTING_COMMAND, 100);
        flag = !(m_isBesSurroundTurnedOn);
        // because icon has pressed effect, 
        // change btn state image according to icon's hightlight state to prevent flash happened
        if(flag)
        {
            pBtn->setImage(VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_N,
                              IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_ON,
                              IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_D,
                              IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_ON));
        }
        else
        {
            pBtn->setImage(VcpStateImage(IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_N,
                              IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_N,
                              IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_D,
                              IMG_ID_VAPP_GALLERY_VID_BTN_BASE_SURROUND_ON));

        }
        if(turnOnBesSurround(flag))
        {
            m_isBesSurroundTurnedOn = flag;
        }
        pBtn->setIsHighlight(flag);
        break;
    case 'V3D':
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_SETTING_COMMAND, 200);
        flag = !(m_player->getIs3DAnaglyphMode());
        if(m_player->canSwitchTo3DAnaglyph(flag, VFX_TRUE))
        {
            m_positionUpdateTimer->stop();
            m_player->switchTo3DAnaglyph(flag);
            pBtn->setIsHighlight(flag);
        }
        break;
    case 'EDI':
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_SETTING_COMMAND, 300);
        m_player->pause();
        onEditFile(m_currentFile);
        break;
    case 'LAN':
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_SETTING_COMMAND, 400);
        onShowLanguageUI();
        break;
    default:
        break;
    }
}

void VappGalleryPlayerPage::onShowLanguageUI()
{
    const VfxS32 lanCount = m_player->getSubtitleTrackCount();
    const VfxS32 selectedInfoIndex = m_player->getSubtitleIndex();
    if(0 >= lanCount){return;}

    // set popup parameter
    VFX_OBJ_CREATE(m_selectPopup, VcpSelectPopup, this);
    m_selectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_VIDEO_SUBTITLE_SELECTION));
    m_selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
    m_selectPopup->setAutoDestory(VFX_TRUE);
    m_selectPopup->m_signalPopupState.connect(this, &VappGalleryPlayerPage::onPopupCommand);

    // init language items
    //VfxWString lanName = VFX_WSTR_EMPTY;
    for(VfxS32 i = 0; i < lanCount; i++)
    {
        VfxWString lanName;
        const VfxBool res = m_player->getSubtitleLanguageName(i,lanName);
        const VfxS32 id = i;
        const VfxBool isSelected = (selectedInfoIndex == i);
        m_selectPopup->addItem(id,lanName, isSelected);
    }
    m_selectPopup->show(VFX_TRUE);
}

void VappGalleryPlayerPage::onPopupCommand(VfxBasePopup *popup, VfxBasePopupStateEnum state)
{
    if(VFX_BASE_POPUP_AFTER_END_ANIMATION != state){return;}
    if(NULL == m_player){return;}

    VcpSelectPopup *selectedPopup = (VcpSelectPopup*)popup;
    if(NULL == selectedPopup){return;}

    do
    {
        if(!m_player->canToggleSubtitle())
        {
            break;
        }
        const VfxS32 oldIndex =  m_player->getSubtitleIndex();
        const VfxS32 newIndex = (VfxS32)selectedPopup->getFirstSeletedId();
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_LAN_POPUP_COMMAND, oldIndex, newIndex);
        if(oldIndex == newIndex)
        {
            break;
        }
        m_player->switchSubtitle(newIndex);
    }while(0);
}

void VappGalleryPlayerPage::setTimeText(VfxTextFrame *text, VappVideoMsec time, VfxBool forceHourDigit)
{
    VfxWString strTime;
    // Hide HH in HH:MM:SS if less than 1 hour.
    formatTimeText(strTime, time, !forceHourDigit);
    text->setString(strTime);
}

void VappGalleryPlayerPage::onUpdatePosition(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    GALLERY_MEASURE_TIME("OUP");
    if(NULL == m_player || m_disablePositionUpdateWhenExit)
    {
        return;
    }
    VappVideoMsec curPos = 0;
    VappVideoMsec totalPos = 0;
    MDI_RESULT res = m_player->getCurrentTime(curPos);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_UPDATE_POSITION_1, curPos, totalPos, res);

    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        return;
    }

    res = m_player->getTotalDuration(totalPos);
    setTimeText(m_positionText, curPos);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_UPDATE_POSITION_2, curPos, totalPos, res);

    if(totalPos != 0)
    {
        m_seekBar->setCurrentValue((VfxFloat)curPos * 1.0f / totalPos);
    }
}

void VappGalleryPlayerPage::onUpdatePDLRegion(VfxTimer *timer)
{
    if(NULL == m_player || !m_isPDL)
    {
        return;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_PDL_ON_UPDATE_PDL_REGION, 1);
    U64 seekableRegion = 0;
    VappVideoMsec totalPos = 0;
    MDI_RESULT res = m_player->getTotalDuration(totalPos);
    if(totalPos && MDI_RES_VDOPLY_SUCCEED == m_player->getSeekableRegion(seekableRegion))
    {
        if(seekableRegion)
        {
            VfxFloat seekablePos = seekableRegion * 1.0f / totalPos;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_PDL_ON_UPDATE_PDL_REGION_SET_AVAILABLE_REGION, seekablePos * 100);
            m_seekBar->setAvailableRegion(seekablePos);
        }
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_PDL_ON_UPDATE_PDL_REGION, 2);
}

void VappGalleryPlayerPage::onBeginSeekVideo(VcpSlider *slider, VfxFloat value)
{
    m_isOnBeginSeekVideo = VFX_TRUE;
    setBarAutoHide(VFX_FALSE);

    if(m_PlaybackFinishedTimer)
    {
        m_PlaybackFinishedTimer->stop();
    }

    // turn off query update timer to prevent disrupt user input
    m_positionUpdateTimer->stop();
    // pause video playback
    if(VGPS_PLAYING == m_player->getState())
    {
        m_shouldPlayAfterSeek = VFX_TRUE;
        m_player->pause();
    }
}

void VappGalleryPlayerPage::onSeekVideo(VcpSlider *slider, VfxFloat value)
{
    VFX_DEV_ASSERT(NULL != m_player);


    if(m_PlaybackFinishedTimer)
    {
        m_PlaybackFinishedTimer->stop();
    }

    // during seeking, only update time text but no actual seeking.
    VappVideoMsec totalDuration = 0;
    MDI_RESULT res = m_player->getTotalDuration(totalDuration);
    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        return;
    }

    const VappVideoMsec newPos = (VappVideoMsec)(totalDuration * value);
    setTimeText(m_positionText, newPos);
}

void VappGalleryPlayerPage::onEndSeekVideo(VcpSlider *slider, VfxFloat value)
{
    VFX_DEV_ASSERT(NULL != m_player);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_END_SEEK_VIDEO_STATE, m_player->getState());

    // [MAUI_03026955] double check if player is playing to avoid
    // BT open/connect finished and play video  while player is paused but user is do seeking
    if(VGPS_PLAYING == m_player->getState())
    {
        m_shouldPlayAfterSeek = VFX_TRUE;
        m_player->pause();
    }

    // during seeking, only update time text but no actual seeking.
    VappVideoMsec totalDuration = 0;
    MDI_RESULT res = m_player->getTotalDuration(totalDuration);
    if(MDI_RES_VDOPLY_SUCCEED != res)
    {
        return;
    }

    const VfxFloat sliderValue = vfxMin(vfxMax(0.f, value), 1.0f);
    const VappVideoMsec newPos = (VappVideoMsec)(totalDuration * sliderValue);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_END_SEEK_VIDEO, newPos, totalDuration, value);
    setTimeText(m_positionText, newPos);

    // actual "seek" when user release finger
    m_player->seek(newPos);
    m_isOnBeginSeekVideo = VFX_FALSE;

}

void VappGalleryPlayerPage::onVideoOpened(VappVideoPlayerComponent *player, MDI_RESULT openResult)
{
    VFX_DEV_ASSERT(player == m_player);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_VIDEO_OPENED, m_player->getState(), openResult);

    hideAllBars(VFX_FALSE);
    if(MDI_RES_VDOPLY_SUCCEED != openResult &&
       MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW != openResult &&
       MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH != openResult)
    {
        // don't auto hide UI when file failed to open.
        setBarAutoHide(VFX_FALSE);

        // reset UI if open failed,
        if(MDI_RES_VDOPLY_SUCCEED != openResult)
        {
            // reset UI if open failed,
            setTimeText(m_durationText, 0);
            setTimeText(m_positionText, 0);
            m_playPauseHelper->showPlayButton();
            m_seekBar->setCurrentValue(0);
        }

        // For 11A.W1112, we don't request DRM
        /*
        if(MDI_RES_VDOPLY_ERR_DRM_PROHIBITED == openResult)
        {
            checkDRMRequest();
        }
        */
        return;
    }

    if (openResult == MDI_RES_VDOPLY_SUCCEED)
    {
        // start polling the timing data
        VappVideoMsec duration = 0;
        MDI_RESULT res = player->getTotalDuration(duration);
        if(duration)
        {
            setTimeText(m_durationText, duration);
            m_durationText->setHidden(VFX_FALSE);
        }
        else
        {
            setTimeText(m_durationText, 0);
            m_durationText->setHidden(VFX_TRUE);
        }

        //
        // Since we already give hint during opening video,
        // no need to seek again
        // player->seek(m_startingPos);

        // update UI pos,
        // note m_startingPos may result in different currentPosition
        VappVideoMsec pos = 0;
        player->getCurrentTime(pos);
        setTimeText(m_positionText, 0);

        // turn on/off surround effect
        turnOnBesSurround(m_isBesSurroundTurnedOn);
    }

    // create setting panel
    createSettingPanel();
    updateControlStateByPlayerState(m_player->getState());

    onUpdatePosition(NULL);

    VappNCenter *pNCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    const VfxBool isNCenterEntered = (pNCenter) ? pNCenter->getNCenterEntered() : VFX_FALSE;
    if((m_autoStartPlay || player->getNeedResumePlayAfterSwitch3DAnaglyph()) && !isNCenterEntered)
    {
        // clear auto start play flag
        m_prepareToPlay = VFX_TRUE;
        m_autoStartPlay = VFX_FALSE;
        player->setNeedResumePlayAfterSwitch3DAnaglyph(VFX_FALSE);
        player->play();
        //register again when Ncenter exit
    #ifdef __MMI_AVRCP_SUPPORT__
        g_inst = this;
        srv_avrcp_set_cmd_hdlr(callbackAVRCPCommand);
    #endif
    }
    else
    {
        m_prepareToPlay = VFX_FALSE;
    } 
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_VIDEO_OPENED_AUTO_PLAY, isNCenterEntered, m_autoStartPlay, m_shouldPlayAfterSeek);
}

void VappGalleryPlayerPage::disableEffectOptControl(const VfxBool disableAcess)
{
    if(m_screenModeHelper)
    {
        m_screenModeHelper->setIsDisabled(disableAcess);
    }
    if(m_settingPanel)
    {
        m_settingPanel->setIsDisabled(disableAcess);
    }
}

VfxBool VappGalleryPlayerPage::isSubtitleSupport() const
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    // check full-app case or player CUI case
    // support subtitle only if project supports subtitle and full Gallery/Video Player case
    VcuiGalleryVideoPlayer *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPlayer);
    if(NULL == cui)
    {
        return VFX_TRUE;
    }
#endif
    return VFX_FALSE;
}

VfxBool VappGalleryPlayerPage::isBesSurroundSupported()
{
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_IS_BES_SURROUND_SUPPORTED, 1);
    return VFX_TRUE;
#else
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_IS_BES_SURROUND_SUPPORTED, 0);
    return VFX_FALSE;
#endif
}

VfxBool VappGalleryPlayerPage::turnOnBesSurround(VfxBool isTurnOn)
{
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    mdi_result res = MDI_AUDIO_SUCCESS;
    if(isTurnOn)
    {
        res = mdi_audio_surround_turn_on(0);
    }
    else
    {
        res = mdi_audio_surround_turn_off();
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_TURN_ON_BES_SURROUND, isTurnOn, res);
    return VFX_TRUE;
#else
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_IS_BES_SURROUND_SUPPORTED, 0);
    return VFX_FALSE;
#endif
}

void VappGalleryPlayerPage::checkDRMRequest()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_CHECK_DRMREQUEST);
#ifdef __DRM_SUPPORT__
    mmi_rmgr_status_enum rmgr_ret = (mmi_rmgr_status_enum)mmi_rmgr_check_rights_by_path(
                                                (U16*)m_currentFile.getBuf(),
                                                DRM_PERMISSION_PLAY,
                                                IMG_ID_VAPP_GALLERY_APP_ICON,
                                                onDRMRequestUserChoice);

    if (rmgr_ret == MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_CALLING_MMI_RMGR_REQUEST_RIGHTS_CONFIRM);
        mmi_rmgr_request_rights_confirm();
        return;
    }
    else if (rmgr_ret == MMI_RMGR_STATUS_NO_PERMISSION)
    {
        // still no permission, stay where we are
        return;
    }
    else
    {
        VFX_ASSERT(0);
        return;
    }
#else /* __DRM_SUPPORT__ */
    return;
#endif /* __DRM_SUPPORT__ */
}

void VappGalleryPlayerPage::onDRMRequestUserChoice(MMI_BOOL result)
{
#ifdef __DRM_SUPPORT__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_DRMREQUEST_USER_CHOICE_D, result);
    if(MMI_FALSE == result)
    {
        // User does not want to request DRM rights.
        // So we do nothing
    }
    else
    {
        // User want to request DRM rights.
        // right manager would take care of it.
    }

#else /* __DRM_SUPPORT__ */
    return;
#endif /* __DRM_SUPPORT__ */
}

void VappGalleryPlayerPage::onPlaybackFinished(VappVideoPlayerComponent *player, MDI_RESULT finishResult)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_PLAYBACK_FINISHED);
    if(m_settingPanel)
    {
        m_settingPanel->setHidden(VFX_TRUE);
    }

    // if underflow happen, the seekbar sould not go to end
    VappVideoMsec duration = 0;
    MDI_RESULT res = m_player->getTotalDuration(duration);
    if( MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW != finishResult &&
        MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH != finishResult &&
        duration)
    {
        // set seekbar value to 100 percent
        m_seekBar->setCurrentValue(1);
    }

    if(MDI_RES_VDOPLY_SUCCEED == finishResult && player)
    {
        // video reachs end, should consume DRM
        // for following operations. (e.g. play again)
        player->enableConsumeDRM(VFX_TRUE);
    }

    updateVideoPlayInfo(VGFS_FINISHED, 0);

    if(m_PlaybackFinishedTimer == NULL)
    {
        VFX_OBJ_CREATE(m_PlaybackFinishedTimer, VfxTimer, this);
        m_PlaybackFinishedTimer->setStartDelay(VAPP_GALLERY_PLAYBACK_FINISHED_TIMER_DURATION);
        m_PlaybackFinishedTimer->setDuration(VAPP_GALLERY_PLAYBACK_FINISHED_TIMER_DURATION);
        m_PlaybackFinishedTimer->m_signalTick.connect(this, &VappGalleryPlayerPage::onPlaybackFinishedTimeout);
	    m_PlaybackFinishedTimer->stop();
    }
    m_PlaybackFinishedTimer->start();

}
void VappGalleryPlayerPage::onPlaybackFinishedTimeout(VfxTimer *source)
{
    source->stop();

    hideAllBars(VFX_FALSE);
    onUpdatePosition(NULL);

}
void VappGalleryPlayerPage::onSeekFinished(VappVideoPlayerComponent *player, MDI_RESULT seekResult)
{
    if(m_isOnBeginSeekVideo)
    {
        return;
    }

    VappNCenter *pNCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    const VfxBool isNCenterEntered = (pNCenter) ? pNCenter->getNCenterEntered() : VFX_FALSE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_SEEK_FINISHED, isNCenterEntered, m_shouldPlayAfterSeek);
    if(isNCenterEntered)
    {
        m_shouldPlayAfterSeek = VFX_FALSE;
        m_player->pause();
        return;
    }

    if((MDI_RES_VDOPLY_SUCCEED == seekResult || MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED == seekResult)
        && player)
    {
        if(m_shouldPlayAfterSeek)
        {
            player->play();
            m_shouldPlayAfterSeek = VFX_FALSE;
            //register again when Ncenter exit
        #ifdef __MMI_AVRCP_SUPPORT__
            g_inst = this;
            srv_avrcp_set_cmd_hdlr(callbackAVRCPCommand);
        #endif
        }
    }
    else
    {
        // should not reach here
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}

void VappGalleryPlayerPage::updateControlStateByPlayerState(VappVideoPlayerState state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_UPDATE_CONTROL_STATE_BY_PLAYER_STATE, m_player->getState());

    switch(state)
    {
    case VGPS_OPENING:
    case VGPS_CLOSED:
        setBarAutoHide(VFX_FALSE);
        m_positionUpdateTimer->stop();
        if(m_pdlUpdateTimer)
        {
            m_pdlUpdateTimer->stop();
        }
        m_playPauseHelper->setIsDisabled(VFX_TRUE);
        m_seekBar->setIsDisabled(VFX_TRUE);
        m_playPauseHelper->showPlayButton();
        disableEffectOptControl(VFX_TRUE);
        m_settingBtn->setIsDisabled(VFX_TRUE);
        if(m_settingPanel){m_settingPanel->setHidden(VFX_TRUE);}
        break;
    case VGPS_PAUSED:
        setBarAutoHide(VFX_FALSE);
        hideAllBars(VFX_FALSE);
        m_playPauseHelper->setIsDisabled(VFX_FALSE);
        if(m_player)
        {
            m_seekBar->setIsDisabled(!m_player->isSeekable());
            m_seekBar->setThumbHidden(!m_player->isSeekable());
        }
        m_playPauseHelper->showPlayButton();
        m_positionUpdateTimer->stop();
        if(m_pdlUpdateTimer)
        {
            m_pdlUpdateTimer->start();
        }
        onUpdatePosition(NULL);
        disableEffectOptControl(VFX_FALSE);
        m_settingBtn->setIsDisabled(VFX_FALSE);
        break;
    case VGPS_PLAYING:
        {
            m_prepareToPlay = VFX_FALSE;
            // temp solution for streaming update correct total_duration after playback()
            VappVideoMsec duration = 0;
            MDI_RESULT res = m_player->getTotalDuration(duration);
            if(duration)
            {
                setTimeText(m_durationText, duration);
                m_durationText->setHidden(VFX_FALSE);
            }
            else
            {
                setTimeText(m_durationText, 0);
                m_durationText->setHidden(VFX_TRUE);
            }

            setBarAutoHide(VFX_TRUE);
            m_positionUpdateTimer->start();
            if(m_pdlUpdateTimer)
            {
                m_pdlUpdateTimer->start();
            }
            m_playPauseHelper->showPauseButton();
            m_playPauseHelper->setIsDisabled(VFX_FALSE);
            if(m_player)
            {
                m_seekBar->setIsDisabled(!m_player->isSeekable());
                m_seekBar->setThumbHidden(!m_player->isSeekable());
            }
            onUpdatePosition(NULL);
            disableEffectOptControl(VFX_FALSE);
            m_settingBtn->setIsDisabled(VFX_FALSE);
            break;
        }
    case VGPS_SEEKING:
        m_positionUpdateTimer->stop();
        if(m_pdlUpdateTimer)
        {
            m_pdlUpdateTimer->start();
        }
        m_playPauseHelper->setIsDisabled(VFX_TRUE);
        onUpdatePosition(NULL);
        disableEffectOptControl(VFX_TRUE);
        m_settingBtn->setIsDisabled(VFX_FALSE);
        break;
    }
}

void VappGalleryPlayerPage::onPlayerStateChanged(
                                        VappVideoPlayerComponent *player,
                                        VappVideoPlayerState oldState,
                                        VappVideoPlayerState newState)
{
    VFX_DEV_ASSERT(m_playPauseHelper);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_PLAYER_STATE_CHANGED, oldState, newState);
    // decide UI control state
    updateControlStateByPlayerState(newState);

    // after first play, we should disable consumption of DRM
    if(newState == VGPS_PLAYING)
    {
        player->enableConsumeDRM(VFX_FALSE);
    }

    // check backlight state
    switch(newState)
    {
    case VGPS_CLOSED:
    case VGPS_PAUSED:
        if(m_shouldSeekToBeginWhileExit)
        {
            m_seekBar->setCurrentValue(0);
            m_shouldSeekToBeginWhileExit = VFX_FALSE;
        }
        break;

    }
}

#ifdef __MMI_AVRCP_SUPPORT__
U8 VappGalleryPlayerPage::callbackAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events)
{
    // TODO: service would provide user data.
    VappGalleryPlayerPage *pThis = VappGalleryPlayerPage::g_inst;
    VFX_ASSERT(pThis);
    return pThis->onAVRCPCommand(command_type, key_events);
}
#endif
#ifdef __MMI_AVRCP_SUPPORT__
U8 VappGalleryPlayerPage::onAVRCPCommand(U8 command_type, srv_avrcp_key_events key_events)
{
    if(NULL == m_player || isMakingCall())
    {
        return SRV_AVRCP_CR_REJECT;
    }

    // we only handle "down" events, don't handle
    // long-press, repeat, and up.
    if(SRV_AVRCP_KEY_DOWN != key_events)
    {
        return SRV_AVRCP_CR_NOT_IMPLEMENT;
    }

    switch(command_type)
    {
    case SRV_AVRCP_POP_PLAY:
    case SRV_AVRCP_POP_PAUSE:
        // for BT AVRCP, we always treat play/pause as "toggle",
        // this is the behavior of Pluto MMI media player.
        if(VGPS_PLAYING == m_player->getState())
        {
            m_player->pause();
            return SRV_AVRCP_CR_ACCEPT;
        }
        else if(VGPS_PAUSED == m_player->getState())
        {
            m_player->play();
            return SRV_AVRCP_CR_ACCEPT;
        }
        return SRV_AVRCP_CR_NOT_IMPLEMENT;
    case SRV_AVRCP_POP_STOP:
        m_player->stop();
        return SRV_AVRCP_CR_ACCEPT;
    default:
        return SRV_AVRCP_CR_NOT_IMPLEMENT;
    }
}
#endif // __MMI_AVRCP_SUPPORT__

void VappGalleryPlayerPage::registerNotificationCenterEvent(const VfxBool doRegister)
{
    VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if(doRegister)
    {
        nCenter->m_signalEvent.connect(this, &VappGalleryPlayerPage::onNotificationCenterChanged);
    }
    else
    {
        nCenter->m_signalEvent.disconnect(this, &VappGalleryPlayerPage::onNotificationCenterChanged);
    }
}

void VappGalleryPlayerPage::onNotificationCenterChanged(VappNCenterEventEnum event)
{
    if(NULL == m_player){return;}

    VappVideoPlayerState curState = m_player->getState();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_NCENTER_CHANGED, event, curState);

    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
            GALLERY_MEASURE_TIME_START("ONC");
        #ifdef __MMI_AVRCP_SUPPORT__
            // unregister AVRCP
            srv_avrcp_clear_cmd_hdlr(callbackAVRCPCommand);
            g_inst = NULL;
        #endif
            // check if player is switching 2D/3D or subtitle
            // if yes, update start pos
            if(m_player->getIsSwitching())
            {
                VappVideoMsec currentPosition = 0;
                m_player->getCurrentTime(currentPosition);
                m_startingPos = currentPosition;
                m_shouldPlayAfterNCenterExited = m_player->getNeedResumePlayAfterSwitch3DAnaglyph();
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_NCENTER_ENTER, 1, m_shouldPlayAfterNCenterExited, currentPosition);
                break;
            }
            // otherwise, update start pos according to player state
            if(VGPS_PLAYING == curState || VGPS_SEEKING == curState || VGPS_PAUSED == curState)
            {
                m_shouldPlayAfterNCenterExited = (VGPS_PLAYING == curState) ? VFX_TRUE : (m_shouldPlayAfterSeek || m_prepareToPlay);
                // suspend video playback
                m_player->pause();
                VappVideoMsec currentPosition = 0;
                m_player->getCurrentTime(currentPosition);
                m_startingPos = currentPosition;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_NCENTER_ENTER, 0, m_shouldPlayAfterNCenterExited, currentPosition);
            }
            else
            {
                m_shouldPlayAfterNCenterExited = (m_autoStartPlay || m_player->getNeedResumePlayAfterSwitch3DAnaglyph()) ? VFX_TRUE : VFX_FALSE;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_NCENTER_ENTER, 0, m_shouldPlayAfterNCenterExited, VAPP_GALLERY_INTERNAL_UNUSED_PARAM);
            }
            break;
        case VAPP_NCENTER_EVENT_EXITED:
            GALLERY_MEASURE_TIME_STOP("ONC");
            //acoording to MAUI_03198446 discussion, close background audio(not suspend)
            mdi_audio_terminate_background_play();
            if(m_player->getIsSwitching())
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_NCENTER_EXITED, 1, m_shouldPlayAfterSeek, m_shouldPlayAfterNCenterExited);
                break;
            }

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_ON_NCENTER_EXITED, 0, m_shouldPlayAfterSeek, m_shouldPlayAfterNCenterExited);            
            if(m_shouldPlayAfterNCenterExited)
                m_shouldPlayAfterSeek = VFX_TRUE;

            m_shouldPlayAfterNCenterExited = VFX_FALSE;
            if(VGPS_PAUSED == m_player->getState())
            {
                m_player->seek(m_startingPos);
            }
            break;
        default:
            break;
    }
}

void VappGalleryPlayerPage::updateVideoPlayInfo(VappGalleryPlayerVideoFinishState finishState, VappVideoMsec lastPlayPos)
{
#ifdef __VAPP_GALLERY_ENABLE_VIDEO_BOOKMARK__
    if(!m_writeVideoInfoToDB)
    {
        return;
    }

    if(NULL == m_videoDB)
    {
        // make sure DB is created on Video's storage, not the storage in NVRAM
        // because the storage in NVRAM may be changed by CUI or another Gallery instance.
        U8 currentStorage = 0;
        if(getPageCurrentStorage(currentStorage))
        {
            VFX_OBJ_CREATE_EX(m_videoDB, VappGalleryDB, this, (currentStorage));
        }
        else
        {
            VFX_OBJ_CREATE(m_videoDB, VappGalleryDB, this);
        }
    }

    if(NULL == m_player ||
       VGPS_PAUSED != m_player->getState())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_CANNOT_UPDATE_VIDEO_PLAY_INFO_SINCE_NO_PLAYER_OR_STATE_ERROR, m_player->getState());
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_UPDATE_VIDEO_PLAY_INFO, m_player->getState());
    // get video duration
    VappVideoMsec totalDuration = 0;
    m_player->getTotalDuration(totalDuration);

    // if there is no video info in DB yet, create one.
    if(!m_videoDB->hasItemInfoBlocking((WCHAR*)m_currentFile.getBuf()))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_NO_VIDEO_INFO_IN_DB_GET_THUMB_FIRST);
        // get video thumbnail and total duration
        VappGalleryCachedImage *thumbImg = NULL;
        VFX_OBJ_CREATE(thumbImg, VappGalleryCachedImage, this);
        thumbImg->lockBuffer(getApp()->getGroupId(),
                             VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W,
                             VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H);

        MDI_RESULT thumbRes = MDI_RES_VDOPLY_SUCCEED;
        GDI_HANDLE thumbLayer = thumbImg->getLayer();
        if(GDI_LAYER_EMPTY_HANDLE != thumbLayer)
        {
            if(m_player->isVideoTrackSupported())
            {
                thumbRes = mdi_video_ply_seek_and_get_frame(0, thumbLayer);
                gdi_layer_free(thumbLayer);
                thumbLayer = GDI_LAYER_EMPTY_HANDLE;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_NO_VIDEO_INFO_IN_DB_GET_THUMB_RET_D, thumbRes);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_NO_VIDEO_INFO_NO_V_TRACK);
            }
        }

        if((MDI_RES_VDOPLY_SUCCEED == thumbRes || MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED == thumbRes)&&
           0 != totalDuration)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_WRITE_VIDEO_INFO_TO_DB_BLOCKING);
            // insert video info into DB
            ivd_db_video_result_info input;
            memset(&input, 0, sizeof(input));
            input.result_code = MMI_IVD_OK;
            input.duration_sec = (U32)msecToSec(totalDuration);
            input.bookmark_sec = 0;
            input.thumb_width = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W;
            input.thumb_height = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H;
            input.thumb_buf_ptr = thumbImg->m_bufPtr;
            input.thumb_buf_len = VappGalleryVideoInfoCacheItem::bufSize;
            m_videoDB->setItemInfoBlocking((WCHAR*)m_currentFile.getBuf(), &input);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_WRITE_VIDEO_INFO_TO_DB_BLOCKING_RET_D, input.result_code);

            // [MAUI_02964311] the test data is failed to preview but play sucessfully.
            // In other word, player will try to get the thumbnail to write to DB while exist.
            // However, mdi_video_ply_seek_and_get_frame(0) will change player current time and
            // our platform does not support multiple players yet.
            // It will caused UI get worng cuurent time to update seekbar position while
            // player page does updateControlStateByPlayerState(PAUSED) during onExit.
            // Turn on the flag "m_disablePositionUpdateWhenExit" to avoid update postion wrongly
            if(0 != lastPlayPos)
            {
                m_disablePositionUpdateWhenExit = VFX_TRUE;
            }
        }

        thumbImg->unlockBuffer();
        VFX_OBJ_CLOSE(thumbImg);
    }
    else
    {
        // note total duartion should be the max value of duration time in preview senario and plaback senario
        // get video info record
        ivd_db_video_result_info record;
        record.thumb_buf_ptr = NULL;
        record.thumb_buf_len = 0;

        m_videoDB->getItemInfoBlocking((WCHAR*)m_currentFile.getBuf(), &record);
        if(totalDuration != record.duration_sec)
        {
            const U64 t = vfxMax(msecToSec(totalDuration), (U64)(record.duration_sec));
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_NO_VIDEO_INFO_FXI_TOTAL_DURATION, t, totalDuration);
            m_videoDB->updateItemTotalDurationBlocking((WCHAR*)m_currentFile.getBuf(), (U32)t);
        }
    }

    // update last play position of given video
    if(finishState == VGFS_FINISHED || !m_writeLastPlayInfo)
    {
        m_videoDB->updateItemBookmarkBlocking((WCHAR*)m_currentFile.getBuf(), 0);
    }
    else if(finishState == VGFS_UNFINISHED && lastPlayPos != 0)
    {
        const U32 bookmark_sec = (U32)msecToSec(lastPlayPos);
        m_videoDB->updateItemBookmarkBlocking((WCHAR*)m_currentFile.getBuf(), bookmark_sec);
    }
#endif
}

VfxFloat VappGalleryPlayerPage::calculateSeekValueForKeySuppot(const VappVideoMsec totalPos)
{
    VappVideoMsec currentValue = (VappVideoMsec)(m_seekBar->getCurrentValue()* totalPos);
    VfxFloat value = (VfxFloat)(currentValue + m_seekOffset)* 1.0f / totalPos;
    if(VFX_ABS(m_seekOffset) >= currentValue && 0 > m_seekOffset)
    {
        value = 0.f;
    }
    value = vfxMin(vfxMax(0.f, value), 1.0f);

    return value;
}

/*****************************************************************************
 * Class VappGalleryPlayPauseHelper
 *****************************************************************************/
VappGalleryPlayPauseHelper::VappGalleryPlayPauseHelper():
    m_playBtn(NULL),
    m_pauseBtn(NULL),
    m_isDisabled(VFX_TRUE)
{
}

void VappGalleryPlayPauseHelper::setup(VcpButton *playBtn, VcpButton *pauseBtn)
{
    VFX_DEV_ASSERT(playBtn);
    VFX_DEV_ASSERT(pauseBtn);

    m_playBtn = playBtn;
    m_pauseBtn = pauseBtn;

    m_playBtn->setId('PLAY');
    m_pauseBtn->setId('PAUS');

    m_playBtn->m_signalClicked.connect(this, &VappGalleryPlayPauseHelper::onButtonTapped);
    m_pauseBtn->m_signalClicked.connect(this, &VappGalleryPlayPauseHelper::onButtonTapped);

    // default shows playbutton
    m_playBtn->setHidden(VFX_FALSE);
    m_pauseBtn->setHidden(VFX_TRUE);
    m_isPlayBtnActive = VFX_TRUE;
}

void VappGalleryPlayPauseHelper::setIsDisabled(VfxBool isDisabled)
{
    m_playBtn->setIsDisabled(isDisabled);
    m_pauseBtn->setIsDisabled(isDisabled);

    m_isDisabled = isDisabled;
}

void VappGalleryPlayPauseHelper::onButtonTapped(VfxObject *button, VfxId id)
{
    return m_signalClicked.emit(button, id);
}

VfxSignal2<VfxObject*, VfxId>* VappGalleryPlayPauseHelper::getSignalTapped()
{
    return &m_signalClicked;
}

void VappGalleryPlayPauseHelper::showPlayButton()
{
    m_playBtn->setHidden(VFX_FALSE);
    m_pauseBtn->setHidden(VFX_TRUE);

    m_isPlayBtnActive = VFX_TRUE;
}

void VappGalleryPlayPauseHelper::showPauseButton()
{
    m_pauseBtn->setHidden(VFX_FALSE);
    m_playBtn->setHidden(VFX_TRUE);

    m_isPlayBtnActive = VFX_FALSE;
}

void VappGalleryPlayPauseHelper::setActiveBtnState(VcpButtonStateEnum state)
{
    if(m_isPlayBtnActive)
    {
        m_playBtn->setState(state);
    }
    else
    {
        m_pauseBtn->setState(state);
    }
}

/*****************************************************************************
 * Class VappGalleryScreenModeHelper
 *****************************************************************************/

VappGalleryScreenModeHelper::VappGalleryScreenModeHelper():
    m_normalBtn(NULL),
    m_clippedBtn(NULL),
    m_resizedBtn(NULL),
    m_isAllBtnHidden(VFX_FALSE)
{
    m_btnIndices[0] = NORMAL;
    m_btnIndices[1] = RESIZED;
    m_btnIndices[2] = CLIPPED;
}

void VappGalleryScreenModeHelper::setup(VcpImageButton *normalBtn,
                                        VcpImageButton *clippedBtn,
                                        VcpImageButton *resizedBtn,
                                        const VappVideoPlayerScreenMode defaultVS)
{
    VFX_DEV_ASSERT(normalBtn);
    VFX_DEV_ASSERT(clippedBtn);
    VFX_DEV_ASSERT(resizedBtn);

    m_normalBtn = normalBtn;
    m_clippedBtn = clippedBtn;
    m_resizedBtn = resizedBtn;

    m_normalBtn->setId(NORMAL);
    m_clippedBtn->setId(CLIPPED);
    m_resizedBtn->setId(RESIZED);

    m_normalBtn->m_signalClicked.connect(this, &VappGalleryScreenModeHelper::onButtonTapped);
    m_clippedBtn->m_signalClicked.connect(this, &VappGalleryScreenModeHelper::onButtonTapped);
    resizedBtn->m_signalClicked.connect(this, &VappGalleryScreenModeHelper::onButtonTapped);

    // init m_btnIndices according to supported video screen mode
    VfxU8 index = 0;
    for(VfxS8 i = BEGIN_OF_SCREEN_MODE_HELPER_ID + 1;
        i < END_OF_SCREEN_MODE_HELPER_ID;
        i ++)
    {
        VappGalleryScreenModeHelperID id = (VappGalleryScreenModeHelperID)i;
        if(VappVideoPlayerComponent::isScreenModeSupported(convertToVSMode(id)))
        {
            m_btnIndices[index] = id;
            index ++;
        }
    }

    if(1 >= index)
    {
        setAllBtnHidden(VFX_TRUE);
    }

    while(END_OF_SCREEN_MODE_HELPER_ID > index + 1)
    {
        m_btnIndices[index] = END_OF_SCREEN_MODE_HELPER_ID;
        index++;
    }

    VFX_TRACE(("[Gallery][VideoPlayer] videoScreenHelper, m_btnIndices[%d] = %d", 0, m_btnIndices[index]));
    VFX_TRACE(("[Gallery][VideoPlayer] videoScreenHelper, m_btnIndices[%d] = %d", 1, m_btnIndices[index]));
    VFX_TRACE(("[Gallery][VideoPlayer] videoScreenHelper, m_btnIndices[%d] = %d", 2, m_btnIndices[index]));

    // default shows normal btn
    updateBtnStateByCurrentScreenMode(defaultVS);
    //showButtonById(convertID(defaultVS));
}

void VappGalleryScreenModeHelper::setPosition(const VfxS32 x, const VfxS32 y)
{
    if(m_normalBtn){m_normalBtn->setPos(x, y);}
    if(m_clippedBtn){m_clippedBtn->setPos(x, y);}
    if(m_resizedBtn){m_resizedBtn->setPos(x, y);}
}

VappGalleryScreenModeHelperID VappGalleryScreenModeHelper::convertID(VappVideoPlayerScreenMode vs)
{
    switch(vs)
    {
        case VS_INSIDE:
            return NORMAL;
        case VS_OUTSIDE:
            return CLIPPED;
        case VS_STRETCH:
            return RESIZED;
        default:
            return END_OF_SCREEN_MODE_HELPER_ID;
    }
}

VappVideoPlayerScreenMode VappGalleryScreenModeHelper::convertToVSMode(VappGalleryScreenModeHelperID id)
{
    switch(id)
    {
        case NORMAL:
            return VS_INSIDE;
        case CLIPPED:
            return VS_OUTSIDE;
        case RESIZED:
            return VS_STRETCH;
        default:
            return VS_END_OF_MODE;
    }
}

VappVideoPlayerScreenMode VappGalleryScreenModeHelper::getNextScreenMode(VfxId curBtnId)
{
    // search the index of current button in m_btnIndices
    VfxS8 curIndex = END_OF_SCREEN_MODE_HELPER_ID;
    do
    {
        const VfxS8 length = END_OF_SCREEN_MODE_HELPER_ID - BEGIN_OF_SCREEN_MODE_HELPER_ID - 1;
        for(int i = 0; i < length; i++)
        {
            if(curBtnId == m_btnIndices[i])
            {
                curIndex = i;
                break;
            }
        }
        if(END_OF_SCREEN_MODE_HELPER_ID == curIndex){ return VS_END_OF_MODE;}
    }while(0);

    // get next button id
    VfxS8 nextIndex = curIndex + 1;
    if( (END_OF_SCREEN_MODE_HELPER_ID <= nextIndex + 1) ||
        (END_OF_SCREEN_MODE_HELPER_ID == m_btnIndices[nextIndex]))
    {
        nextIndex = 0;
    }
    VappGalleryScreenModeHelperID nextBtnId = m_btnIndices[nextIndex];

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_GET_NEXT_SCREEN_MODE, curBtnId, nextBtnId);
    return convertToVSMode(nextBtnId);
}

void VappGalleryScreenModeHelper::updateBtnStateByCurrentScreenMode(const VappVideoPlayerScreenMode mode)
{
    // show icon of next screen mode to indicate the next screen
    const VappVideoPlayerScreenMode nextMode = getNextScreenMode(convertID(mode));
    const VappGalleryScreenModeHelperID nextBtnId = convertID(nextMode);
    showButtonById(nextBtnId);
}

void VappGalleryScreenModeHelper::showButtonById(VappGalleryScreenModeHelperID id)
{
    VFX_DEV_ASSERT(id != END_OF_SCREEN_MODE_HELPER_ID);

    if(m_isAllBtnHidden)
    {
        return;
    }
    m_normalBtn->setHidden(id == m_normalBtn->getId()? VFX_FALSE : VFX_TRUE);
    m_clippedBtn->setHidden(id == m_clippedBtn->getId()? VFX_FALSE : VFX_TRUE);
    m_resizedBtn->setHidden(id == m_resizedBtn->getId()? VFX_FALSE : VFX_TRUE);
}

void VappGalleryScreenModeHelper::setIsDisabled(const VfxBool b)
{
    m_normalBtn->setIsDisabled(b);
    m_clippedBtn->setIsDisabled(b);
    m_resizedBtn->setIsDisabled(b);
}

VfxSignal2<VfxObject*, VfxId>* VappGalleryScreenModeHelper::getSignalTapped()
{
    return &m_signalClicked;
}

void VappGalleryScreenModeHelper::onButtonTapped(VfxObject *button, VfxId id)
{
    return m_signalClicked.emit(button, id);
}

void VappGalleryScreenModeHelper::setAllBtnHidden(const VfxBool b)
{
    m_isAllBtnHidden = b;
    if(!b)
    {
        m_normalBtn->setHidden(b);
        m_clippedBtn->setHidden(b);
        m_resizedBtn->setHidden(b);
    }
}

/*****************************************************************************
 * VappGallerySettingFloatPnael
 *****************************************************************************/
VappGalleryFloatSettingPnael::VappGalleryFloatSettingPnael()
    : m_tabCount(0)
{
}
void VappGalleryFloatSettingPnael::onInit()
{
    VfxFrame::onInit();

    // note panel size depends on the number of tabs
    // set background
    setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_VID_SETTING_BG));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_binaryBtnList.init(this);
}

void VappGalleryFloatSettingPnael::addBinaryTab(const VfxId id, const VcpStateImage &stateImage, const VfxBool highlight)
{
    VcpImageButton *btn;
    VFX_OBJ_CREATE(btn, VcpImageButton, this);

    btn->setId(id);
    btn->setImage(stateImage);
    btn->setSize(BTN_W, BTN_H);
    btn->setAnchor(0.5, 0.5);
    btn->setIsHighlight(highlight);
    btn->m_signalClicked.connect(this, &VappGalleryFloatSettingPnael::onButtonTapped);
    btn->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    _addTab((VfxObject*)btn);
}

void VappGalleryFloatSettingPnael::addMultiStateTab(VappGalleryScreenModeHelper *helper)
{
    if(NULL == helper){return;}
    // TODO: how to config clicked callcallback
    /*
        * for each "visible" button
        *   - get clicked signal
        */
    _addTab(helper);
}

void VappGalleryFloatSettingPnael::updateLayout()
{
    const VfxS32 numTab = _getTabCount();
    const VfxS32 numSeparator = (0 < numTab) ? (numTab - 1) : (0);

    setSize(numTab * TAB_W + numSeparator * SEPARATOR_W, TAB_H);
}

void VappGalleryFloatSettingPnael::highlightTab(const VfxId id, const VfxBool highlight)
{
    VcpImageButton *pBtn = _getBinaryBtn(id);
    if(pBtn)
    {
        pBtn->setIsHighlight(highlight);
    }
}

void VappGalleryFloatSettingPnael::setIsDisabled(const VfxBool isDisabled)
{
    VfxList<VcpImageButton *>::It i;
    for(i = m_binaryBtnList.begin(); !i.isNull(); ++i)
    {
        VcpImageButton *pBtn = (*i);
        pBtn->setIsDisabled(isDisabled);
    }
}

void VappGalleryFloatSettingPnael::disableTab(const VfxId id, const VfxBool isDisabled)
{
    VcpImageButton *pBtn = _getBinaryBtn(id);
    if(pBtn)
    {
        pBtn->setIsDisabled(isDisabled);
    }
}

VfxBool VappGalleryFloatSettingPnael::getIsTabDisabled(const VfxId id)
{
    VcpImageButton *pBtn = _getBinaryBtn(id);
    if(pBtn)
    {
        return pBtn->getIsDisabled();
    }
    return VFX_FALSE;
}

VfxSignal2<VfxObject*, VfxId>* VappGalleryFloatSettingPnael::getSignalTapped()
{
    return &m_signalTapped;
}

void VappGalleryFloatSettingPnael::_addTab(VfxObject *pObj)
{
    if(NULL == pObj)
    {
        return;
    }

    // check if it is a valid control
    VcpImageButton *pBtn = NULL;
    VappGalleryScreenModeHelper *pHelper = NULL;
    do
    {
        pBtn    = VFX_OBJ_DYNAMIC_CAST(pObj, VcpImageButton);
        pHelper = VFX_OBJ_DYNAMIC_CAST(pObj, VappGalleryScreenModeHelper);
        if(NULL == pBtn && NULL == pHelper)
        {
            return;
        }
    }while(0);

    VfxS32 tapPosX = 0;
    VfxS32 tapPosY = 0;
    VfxS32 separatorPosX = 0;
    VfxS32 separatorPosY = 0;

    // add a separator if there are more than one setting tabs
    if(_calculateNextSeparatorAndTapPos(tapPosX, tapPosY, separatorPosX, separatorPosY))
    {
        _createSeparator(separatorPosX, separatorPosY);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_SETTING_ADD_TAB, m_tabCount, tapPosX, tapPosY, separatorPosX, separatorPosY);
    // assign control position
    if(pBtn)
    {
        pBtn->setPos(tapPosX, tapPosY);
        m_binaryBtnList.pushBack(pBtn);
    }
    else if(pHelper)
    {
        pHelper->setPosition(tapPosX, tapPosY);
    }

    // update tab count
    m_tabCount ++;
    // update setting size
    updateLayout();
}

VfxBool VappGalleryFloatSettingPnael::_calculateNextSeparatorAndTapPos(
                                        VfxS32 &tapPosX,
                                        VfxS32 &tapPosY,
                                        VfxS32 &separatorPosX,
                                        VfxS32 &separatorPosY)
{
    const VfxS32 numTab       = _getTabCount();
    const VfxS32 numSeparator = (0 < numTab) ? (numTab - 1) : (0);
    const VfxS32 offsetX      = TAB_W * numTab + SEPARATOR_W * numSeparator;
    const VfxS32 dx           = (0 < numTab) ? (SEPARATOR_W) : (0);

    tapPosX = (VfxS32)(offsetX + TAB_W * 0.5f + dx);
    tapPosY = (VfxS32)(TAB_H * 0.5f);

    separatorPosX = offsetX;
    separatorPosY = (VfxS32)(TAB_H * 0.5f);

    return (0 < numTab) ? VFX_TRUE : VFX_FALSE;
}

void VappGalleryFloatSettingPnael::_createSeparator(const VfxS32 x, const VfxS32 y)
{
    VfxFrame *separator = NULL;
    VFX_OBJ_CREATE(separator, VfxFrame, this);

    separator->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_VID_SETTING_SEPARATOR));
    separator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    separator->setSize(SEPARATOR_W, SEPARATOR_H);
    separator->setAnchor(0, 0.5);
    separator->setPos(x, y);
}

VfxS32 VappGalleryFloatSettingPnael::_getTabCount() const
{
    return m_tabCount;
}

VcpImageButton* VappGalleryFloatSettingPnael::_getBinaryBtn(VfxId id)
{
    VfxList<VcpImageButton *>::It i;
    for(i = m_binaryBtnList.begin(); !i.isNull(); ++i)
    {
        VcpImageButton *pBtn = (*i);
        if(id == pBtn->getId())
        {
            return pBtn;
        }
    }
    return NULL;
}

void VappGalleryFloatSettingPnael::onButtonTapped(VfxObject *button, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PLAYER_SETTING_ON_BTN_TAPPED);
    return m_signalTapped.emit(button, id);
}
#endif
