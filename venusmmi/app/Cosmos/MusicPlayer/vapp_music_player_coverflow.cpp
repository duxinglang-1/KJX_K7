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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#if defined(__COSMOS_MUSICPLY__) && defined(__COSMOS_MUSICPLY_COVER_FLOW__) && !defined(__COSMOS_3D_V10__)

#include "vapp_music_player.h"
#include "vapp_music_player_coverflow.h"
#include "vapp_music_player_ctrlPLSV.h"
#include "vapp_music_player_ctrlmediacache.h"
#include "vapp_music_player_util.h"
#include "vapp_music_player_include.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_app_cosmos_global_def.h" // For cosmos theme color
#include "mmi_rp_srv_venus_component_title_bar_def.h"

#define VAPP_MUSICPLY_UPDATE_DURATION_TIME 250

/***************************************************************************** 
 * VappMusicPlayerCoverFlowPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerCoverFlowPage", VappMusicPlayerCoverFlowPage, VappMusicPlayerPlayerBase);

void VappMusicPlayerCoverFlowPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_INIT);

    VappMusicPlayerPlayerBase::onInit();
}

void VappMusicPlayerCoverFlowPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_DEINIT);

    closeMetaParser();

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->clearCoverFlowPtr(this);
    }

    VappMusicPlayerPlayerBase::onDeinit();
}

void VappMusicPlayerCoverFlowPage::onEnter(VfxBool isBackward)
{
    VappMusicPlayerPlayerBase::onEnter(isBackward);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_ENTER, isBackward);

    if (m_panelAlbumDetail)
    {
        initMetaParser();
        m_panelAlbumDetail->setAlbumCover();
    }

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->updateWaitIconPos(VFX_FALSE, VFX_FALSE);

        // Set screen background color to black to avoid showing background color when page transition
        app->getRootScreen()->setBgColor(VFX_COLOR_BLACK);

        app->resetKeyInput();
    }
}

void VappMusicPlayerCoverFlowPage::onEntered()
{
    VappMusicPlayerPlayerBase::onEntered();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_ENTERED);

    if (!m_onEnteredTimer)
    {
        VFX_OBJ_CREATE(m_onEnteredTimer, VfxTimer, this);
        m_onEnteredTimer->setDuration(10);
        m_onEnteredTimer->m_signalTick.connect(this, &VappMusicPlayerCoverFlowPage::onEnteredPostProc);
    }
    m_onEnteredTimer->start();
}

void VappMusicPlayerCoverFlowPage::onEnteredPostProc(VfxTimer *t)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_ENTERED_POST_PROC);

    m_provider->setMediaCache();

    m_provider->lockFirstVisibleCell();

    VFX_OBJ_CLOSE(m_onEnteredTimer);
    m_onEnteredTimer = NULL;
}

void VappMusicPlayerCoverFlowPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_EXIT, isBackward);

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->resetKeyInput();
    }

    m_provider->pauseMediaCache();

    VappMusicPlayerPlayerBase::onExit(isBackward);
}

void VappMusicPlayerCoverFlowPage::onExited()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_EXITED);

    // Set screen background color back to theme color
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->getRootScreen()->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    }

    VappMusicPlayerPlayerBase::onExited();
}

void VappMusicPlayerCoverFlowPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_ON_EXITED2);

    hideAllCellImages();

    VappMusicPlayerPlayerBase::onExited2();
}

void VappMusicPlayerCoverFlowPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if(param.rotateTo == VFX_SCR_ROTATE_TYPE_90 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270)
    {
        m_pageOrientation = param.rotateTo;
    }
    else
    {
        param.rotateTo = m_pageOrientation;
    }
}

VfxBool VappMusicPlayerCoverFlowPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        // not allow exit cover flow by back key
        VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
        if (app)
        {
            if (!isDetailPanelAlive())
            {
                app->onScreenRotate(VFX_SCR_ROTATE_TYPE_NORMAL);
            }

            return VFX_TRUE;
        }
    }

    return VappMusicPlayerPlayerBase::onKeyInput(event);
}

void VappMusicPlayerCoverFlowPage::initUI()
{
    VappMusicPlayerPlayerBase::initUI();

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        m_provider = app->getProvider();

        VFX_OBJ_CREATE(m_listMenuProvider, VappMusicPlayerListMenuProvider, this);
        m_listMenuProvider->setDataProvider(m_provider);
        m_listMenuProvider->setViewType(VIEW_TYPE_COVER_FLOW);
        
        m_ctrlMediaCache = m_provider->getCtrlMediaCache();
    }
    
    VfxFrame *bgFrame;
    VFX_OBJ_CREATE(bgFrame, VfxFrame, this);
    bgFrame->setIsOpaque(VFX_TRUE);
    bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_GRID_BG));
    bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    // Cover flow menu
    VFX_OBJ_CREATE(m_menu, VappMusicPlayerCoverFlowMenu, this);
    m_menu->enableHorizontalScrollIndicator(VFX_FALSE);

    VappMusicPlayerCoverFlowMenuLayout *layout = VFX_OBJ_DYNAMIC_CAST(m_menu->getLayout(), VappMusicPlayerCoverFlowMenuLayout);
    m_menu->scrollContent(VfxPoint(layout->getStartEndSpace(), 0));
    m_menu->m_signalScrollStopped.connect(this, &VappMusicPlayerCoverFlowPage::onMenuScrollStopped);
    
    // Buttom panel
    VfxFrame *panelPlayback;
    VFX_OBJ_CREATE(panelPlayback, VfxFrame, this);
    panelPlayback->setAnchor(0.0f, 1.0f);
    panelPlayback->setIsOpaque(VFX_TRUE);
    panelPlayback->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_PLAYBACK));
    panelPlayback->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    // Album cover
    VFX_OBJ_CREATE(m_albumCoverFrame, VfxFrame, panelPlayback);
    m_albumCoverFrame->setIsOpaque(VFX_TRUE);
    m_albumCoverFrame->setBgColor(VRT_COLOR_BLACK);
    m_albumCoverFrame->setBorderColor(VRT_COLOR_BLACK);
    m_albumCoverFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // Artist name
    VFX_OBJ_CREATE(m_textArtist, VfxTextFrame, panelPlayback);
    m_textArtist->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_textArtist->setAutoResized(VFX_FALSE);
    m_textArtist->setAutoFontSize(VFX_FALSE);
    m_textArtist->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textArtist->setString(VFX_WSTR(""));
    m_textArtist->setColor(VRT_COLOR_GREY);
    m_textArtist->setIsUnhittable(VFX_TRUE);
    
    // Song title
    VFX_OBJ_CREATE(m_textTitle, VfxTextFrame, panelPlayback);
    m_textTitle->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_textTitle->setAutoResized(VFX_FALSE);
    m_textTitle->setAutoFontSize(VFX_FALSE);
    m_textTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTitle->setString(VFX_WSTR(""));
    m_textTitle->setColor(VRT_COLOR_WHITE);
    m_textTitle->setIsUnhittable(VFX_TRUE);
    
    // Seekbar panel
    VfxFrame *panelSeekbar;
    VFX_OBJ_CREATE(panelSeekbar, VfxFrame, this);
    panelSeekbar->setAnchor(0.0f, 1.0f);
    panelSeekbar->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_PANEL_SLIDER));
    panelSeekbar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    VFX_OBJ_CREATE(m_slider, VcpSlider, panelSeekbar);
    m_slider->setAnchor(0.5f, 0.5f);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setMaxValue(100);
    m_slider->setCurrentValue(0);
    m_slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
    m_slider->setIsUnhittable(VFX_TRUE);////// should remove later
    m_slider->setIsDisabled(VFX_TRUE);
    m_slider->m_signalThumbPressed.connect(this, &VappMusicPlayerCoverFlowPage::onSliderPressed);
    m_slider->m_signalThumbReleased.connect(this, &VappMusicPlayerCoverFlowPage::onSliderReleased);
    m_slider->m_signalThumbDrag.connect(this, &VappMusicPlayerCoverFlowPage::onSliderValueChange);

    VFX_OBJ_CREATE(m_textCurrTime, VfxTextFrame, panelSeekbar);
    m_textCurrTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textCurrTime->setAutoResized(VFX_FALSE);
    m_textCurrTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textCurrTime->setColor(VRT_COLOR_WHITE);
    
    VFX_OBJ_CREATE(m_textTotalTime, VfxTextFrame, panelSeekbar);
    m_textTotalTime->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textTotalTime->setAutoResized(VFX_FALSE);
    m_textTotalTime->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTotalTime->setColor(VRT_COLOR_WHITE);
        
    // Timer for updating UI
    VFX_OBJ_CREATE(m_timerSlider, VfxTimer, this);
    m_timerSlider->setDuration(VAPP_MUSICPLY_UPDATE_DURATION_TIME);
    m_timerSlider->m_signalTick.connect(this, &VappMusicPlayerCoverFlowPage::onTimerCallBack);

#if defined(__MMI_MAINLCD_240X320__)
    setSize(320, 240 - MMI_STATUS_BAR_HEIGHT);
    
    bgFrame->setPos(0, 0);
    bgFrame->setSize(getSize());
    
    m_menu->setPos(0, 9);
    m_menu->setSize(getSize());
    
    panelPlayback->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_btnPrev, VcpButton, panelPlayback);
    VFX_OBJ_CREATE(m_btnPlayPause, VcpButton, panelPlayback);
    VFX_OBJ_CREATE(m_btnNext, VcpButton, panelPlayback);
    panelSeekbar->setHidden(VFX_TRUE);

#elif defined(__MMI_MAINLCD_240X400__)
    setSize(400, 240 - MMI_STATUS_BAR_HEIGHT);
    
    bgFrame->setPos(0, 0);
    bgFrame->setSize(getSize());
    
    m_menu->setPos(0, 9);
    m_menu->setSize(getSize());
    
    panelPlayback->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_btnPrev, VcpButton, panelPlayback);
    VFX_OBJ_CREATE(m_btnPlayPause, VcpButton, panelPlayback);
    VFX_OBJ_CREATE(m_btnNext, VcpButton, panelPlayback);
    panelSeekbar->setHidden(VFX_TRUE);

#elif defined(__MMI_MAINLCD_320X480__)
    setSize(480, 320 - MMI_STATUS_BAR_HEIGHT);
    
    bgFrame->setPos(0, 0);
    bgFrame->setSize(480, 300);
    
    m_menu->setPos(0, 7);
    m_menu->setSize(480, 184);
    
    panelPlayback->setSize(480, 73);
    panelPlayback->setPos(0, 320 - MMI_STATUS_BAR_HEIGHT);
    
    m_albumCoverFrame->setPos(4, 5);
    m_albumCoverFrame->setSize(55, 55);
    m_albumCoverFrame->setBorderWidth(1);
        
    m_textArtist->setPos(68, 13);
    m_textArtist->setSize(217, 22);
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14)));
    
    m_textTitle->setPos(68, 31);
    m_textTitle->setSize(217, 27);
    m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(20)));

    // Playback buttons
    m_btnPrev = createButtonEx(panelPlayback, 
                             VfxRect(293, 9, 47, 47), 
                             FUNC_ID_BTN_PREV, 
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_D, 0),
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, 0));
    m_btnPrev->setIsDisabled(VFX_TRUE);
    
    m_btnPlayPause = createButtonEx(panelPlayback, 
                             VfxRect(353, 5, 53, 54), 
                             FUNC_ID_BTN_PLAY_PAUSE, 
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D, 0),
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG1_N, IMG_ID_VAPP_MUSICPLY_BTN_BG1_P, IMG_ID_VAPP_MUSICPLY_BTN_BG1_N, 0));
    m_btnPlayPause->setIsDisabled(VFX_TRUE);
    
    m_btnNext = createButtonEx(panelPlayback, 
                             VfxRect(421, 9, 47, 47), 
                             FUNC_ID_BTN_NEXT, 
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D, 0),
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, 0));
    m_btnNext->setIsDisabled(VFX_TRUE);     
    
    panelSeekbar->setSize(480, 35);
    panelSeekbar->setPos(0, panelPlayback->getRect().getMinY()+1);
    
    m_slider->setPos(240,35/2);
    m_slider->setLength(410);
    
    m_textCurrTime->setPos(0, 10);
    m_textCurrTime->setSize(40, 12);
    m_textCurrTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textCurrTime->getSize().height)));
    
    m_textTotalTime->setPos(480-40, 10);
    m_textTotalTime->setSize(40, 12);
    m_textTotalTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textTotalTime->getSize().height)));
            
#else //(__MMI_MAINLCD_480X800__)
    setSize(800, 480 - MMI_STATUS_BAR_HEIGHT);
    
    bgFrame->setPos(0, 0);
    bgFrame->setSize(800, 350);
    
    m_menu->setPos(0, 5);
    m_menu->setSize(800, 280);
    
    panelPlayback->setSize(800, 98);
    panelPlayback->setPos(0, 480 - MMI_STATUS_BAR_HEIGHT);
    
    m_albumCoverFrame->setPos(6, 8);
    m_albumCoverFrame->setSize(83, 83);
    m_albumCoverFrame->setBorderWidth(2);
        
    m_textArtist->setPos(104, 20);
    m_textArtist->setSize(398, 23);
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(22)));
    
    m_textTitle->setPos(104, 48);
    m_textTitle->setSize(398, 34);
    m_textTitle->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(30)));

    // Playback buttons
    m_btnPrev = createButtonEx(panelPlayback, 
                             VfxRect(521, 16, 68, 69), 
                             FUNC_ID_BTN_PREV, 
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_N, IMG_ID_VAPP_MUSICPLY_BTN_PREV_D, 0),
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, 0));
    m_btnPrev->setIsDisabled(VFX_TRUE);
    
    m_btnPlayPause = createButtonEx(panelPlayback, 
                             VfxRect(610, 11, 79, 79), 
                             FUNC_ID_BTN_PLAY_PAUSE, 
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N, IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D, 0),
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG1_N, IMG_ID_VAPP_MUSICPLY_BTN_BG1_P, IMG_ID_VAPP_MUSICPLY_BTN_BG1_N, 0));
    m_btnPlayPause->setIsDisabled(VFX_TRUE);
    
    m_btnNext = createButtonEx(panelPlayback, 
                             VfxRect(711, 16, 68, 69), 
                             FUNC_ID_BTN_NEXT, 
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N, IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D, 0),
                             VcpStateImage(IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, IMG_ID_VAPP_MUSICPLY_BTN_BG2_P, IMG_ID_VAPP_MUSICPLY_BTN_BG2_N, 0));
    m_btnNext->setIsDisabled(VFX_TRUE);
    
    panelSeekbar->setSize(800, 60);
    panelSeekbar->setPos(0, panelPlayback->getRect().getMinY()+1);
    
    m_slider->setPos(400, 30);
    m_slider->setLength(654);
    
    m_textCurrTime->setPos(0, 23);
    m_textCurrTime->setSize(72, 18);
    m_textCurrTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textCurrTime->getSize().height)));
    
    m_textTotalTime->setPos(800-72, 23);
    m_textTotalTime->setSize(72, 18);
    m_textTotalTime->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(m_textTotalTime->getSize().height)));
    
#endif

    m_btnPrev->setFuzzy(VFX_FALSE);
    m_btnPlayPause->setFuzzy(VFX_FALSE);
    m_btnNext->setFuzzy(VFX_FALSE);

    // Timer for updating UI
    VFX_OBJ_CREATE(m_timerSlider, VfxTimer, this);
    m_timerSlider->setDuration(VAPP_MUSICPLY_UPDATE_DURATION_TIME);
    m_timerSlider->m_signalTick.connect(this, &VappMusicPlayerCoverFlowPage::onTimerCallBack);
    
    ///// auto scroll to active album
    /*
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(100);
    timer->m_signalTick.connect(this, &VappMusicPlayerCoverFlowPage::makeFocusCellVisible);
    timer->start();
    */
}

VfxBool VappMusicPlayerCoverFlowPage::onPenInput(VfxPenEvent &event)
{
    return VFX_FALSE;
}

void VappMusicPlayerCoverFlowPage::setAlbumCover(VfxImageBuffer &imgBuf)
{
#ifdef __LOW_COST_SUPPORT_COMMON__
    for (VfxU32 counter = 0; counter < 100 && m_albumCoverFrame->getChildCount() > 0; ++counter)
    {
        // close icon of default album cover
        VfxFrame *f = m_albumCoverFrame->getLastChildFrame();
        if (f)
        {
            VFX_OBJ_CLOSE(f);
        }
    }
#endif

    // set the album cover on playback panel
    if (imgBuf.ptr)
    {
        VfxImageSrc imgSrc;
        imgSrc.setImageBuffer(imgBuf);
        m_albumCoverFrame->setImgContent(imgSrc);
    }
    else
    {
#ifdef __LOW_COST_SUPPORT_COMMON__
        setDefaultCover(m_albumCoverFrame, VFX_FALSE, m_albumCoverFrame->getSize().width, m_albumCoverFrame->getSize().height, VFX_TRUE);
#else
        m_albumCoverFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_NO_TEXT));
#endif
    }

    m_albumCoverFrame->invalidate();
}

VfxU32 VappMusicPlayerCoverFlowPage::getAlbumCount()
{
    return m_listMenuProvider->getCount();
}

void VappMusicPlayerCoverFlowPage::getAlbumInfo(VfxU32 idx, VfxWString& artist, VfxWString& album)
{
    VcpListMenuTextColorEnum color;
    m_listMenuProvider->getItemText(idx, VCP_LIST_MENU_FIELD_TEXT, album, color);
    m_listMenuProvider->getItemText(idx, VCP_LIST_MENU_FIELD_SUB_TEXT1, artist, color);
}

VfxU32 VappMusicPlayerCoverFlowPage::getAlbumID(VfxU32 idx)
{
    return m_listMenuProvider->getID(idx);
}

void VappMusicPlayerCoverFlowPage::getAlbumImage(VfxU32 idx, VfxImageSrc &imgSrc)
{
    if (!m_listMenuProvider->getItemImage(idx, VCP_LIST_MENU_FIELD_ICON, imgSrc))
    {
        imgSrc.setResId(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER);
    }
}

void VappMusicPlayerCoverFlowPage::makeFocusCellVisible(VfxTimer *timer)
{
    ///// should set to previous screen width then scroll to target posititon

    if (m_ctrlPlayback->getPlayState() == PB_STATE_PLAY
     || m_ctrlPlayback->getPlayState() == PB_STATE_PAUSE)
    {
        VfxU32 index = m_provider->getActiveAlbumIndex();
        m_menu->makeVisible(VcpMenuPos(0, index));

        VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::makeFocusCellVisible] %d: \n", index));
    }
}

void VappMusicPlayerCoverFlowPage::showAlbumDetailPanel(VfxU32 index)
{
    m_focusAlbumIdx = index;
}

void VappMusicPlayerCoverFlowPage::doShowAlbumDetailPanel()
{
    if (m_focusAlbumIdx >= 0 && !isDetailPanelAlive())
    {
        m_provider->pauseMediaCache();

        m_menu->setIsDisabled(VFX_TRUE);
        VFX_OBJ_CREATE_EX(m_panelAlbumDetail, VappMusicPlayerCoverFlowAlbumDetailPanel, this, (m_focusAlbumIdx));
        m_panelAlbumDetail->startShow();
    }
}

void VappMusicPlayerCoverFlowPage::hideAlbumDetailPanel(VfxBool anim)
{
    if (m_panelAlbumDetail)
    {
        if (anim)
        {
            m_panelAlbumDetail->startExit();
        }
        else
        {
            VFX_OBJ_CLOSE(m_panelAlbumDetail);
        }
    }

    m_menu->getLayout()->clearFocusItem();
}

void VappMusicPlayerCoverFlowPage::onAlbumDetailPanelShow()
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->resetPenInput();
    }
}

void VappMusicPlayerCoverFlowPage::onAlbumDetailPanelClosed()
{
    m_panelAlbumDetail = NULL;

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        // trigger setViewType
        app->onKeyBack();

        app->resetPenInput();
    }

    m_provider->setMediaCache();

    m_provider->getNextItemImage();

    m_focusAlbumIdx = -1;
}

VfxBool VappMusicPlayerCoverFlowPage::isDetailPanelAlive()
{
    return m_panelAlbumDetail != NULL;
}

void VappMusicPlayerCoverFlowPage::updateCellImage(VfxU32 index, VfxImageBuffer imgBuf)
{
    m_menu->updateCellImage(index, imgBuf);
}

void VappMusicPlayerCoverFlowPage::updateCellInfo(VfxU32 index)
{
    m_menu->updateCellInfo(index);
}

void VappMusicPlayerCoverFlowPage::hideAllCellImages()
{
    m_menu->hideAllCellImages();
}

void VappMusicPlayerCoverFlowPage::onPlaybackStateChange(PlaybackStateEnum state)
{
    VappMusicPlayerPlayerBase::onPlaybackStateChange(state);
    
    if (m_panelAlbumDetail && state == PB_STATE_PLAY)
    {
        m_panelAlbumDetail->updateListMenu();
    }
}

void VappMusicPlayerCoverFlowPage::setInfoText(VfxWString &title, VfxWString &artist, VfxWString &count)
{
    VappMusicPlayerPlayerBase::setInfoText(title, artist, count);

#if defined(__MMI_MAINLCD_320X480__)
    const VfxU32 h1 = 20;
    const VfxU32 h2 = 31;
#else //(__MMI_MAINLCD_480X800__)
    const VfxU32 h1 = 33;
    const VfxU32 h2 = 48;
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

void VappMusicPlayerCoverFlowPage::updateAlbumPanelItem(VfxS32 index)
{
    m_panelAlbumDetail->updateListMenu(index);
}

void VappMusicPlayerCoverFlowPage::onMenuScrollStopped(VcpScrollable* sender)
{
    vfxPostInvoke0(this, &VappMusicPlayerCoverFlowPage::doShowAlbumDetailPanel);
}


/***************************************************************************** 
 * VappMusicPlayerCoverFlowMenu Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerCoverFlowMenu", VappMusicPlayerCoverFlowMenu, VcpBaseMenu);

void VappMusicPlayerCoverFlowMenu::onInit()
{
    VcpBaseMenu::onInit();

    if (!m_page)
    {
        m_page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    }

    setSlowFactor(1.0, 1.0, 0.75);
}

void VappMusicPlayerCoverFlowMenu::onDeinit()
{
    VcpBaseMenu::onDeinit();
}

VcpBaseMenuLayout* VappMusicPlayerCoverFlowMenu::createLayout()
{
    VappMusicPlayerCoverFlowMenuLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VappMusicPlayerCoverFlowMenuLayout, this, (this));

    if (!m_page)
    {
        m_page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    }
    
    layout->m_itemCount = m_page->getAlbumCount();

    return layout;
}

VfxFrame* VappMusicPlayerCoverFlowMenu::createGroupHeader(VfxS32 group)
{
    return NULL;
}

VfxFrame* VappMusicPlayerCoverFlowMenu::createCell(VfxS32 group, VfxS32 pos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_PAGE_CREATE_CELL, pos);

    VappMusicPlayerCoverFlowMenuCell* item;
    VFX_OBJ_CREATE(item, VappMusicPlayerCoverFlowMenuCell, this);

    if (m_page)
    {
        // check if creating is sequential
        if (m_preCreatedCell != -1)
        {
            if (m_preCreatedCell > pos)
            {
                for (VfxS32 idx = m_preCreatedCell - 1; idx > pos; --idx)
                {
                    m_page->getAlbumID(idx);
                }
            }
            else if (m_preCreatedCell < pos)
            {
                for (VfxU32 idx = m_preCreatedCell + 1; idx < pos; ++idx)
                {
                    m_page->getAlbumID(idx);
                }
            }
        }
        m_preCreatedCell = pos;

        // Query cover image
        VfxImageSrc imgSrc;
        m_page->getAlbumImage(pos, imgSrc);

        MediaCacheTask task = m_page->m_ctrlMediaCache->getTask(pos);

        if (task.m_state == MediaCacheTask::HAS_THUMB)
        {
            if (imgSrc.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
            {
                VfxImageSrc defImgSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER);
                item->setImgContent(defImgSrc);
            }
            else
            {
                item->setImage(imgSrc);
            }

            // because PLSV only allows sequence query info, even album with album cover doesn't need to show album info
            // we still do a ID query here
            m_page->getAlbumID(pos);
        }
        else
        {
            VfxImageSrc defImgSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER);
            item->setImgContent(defImgSrc);

            if (task.m_state == MediaCacheTask::NO_THUMB)
            {
                VfxWString artist, album;
                artist.format("");
                album.format("");
                
                m_page->getAlbumInfo(pos, artist, album);

                item->setTextInfo(artist, album);
            }
            else
            {
                // the same reason as above
                m_page->getAlbumID(pos);
            }
        }
    }

    item->setHighlight(VFX_FALSE, VFX_FALSE);

    return item;
}

void VappMusicPlayerCoverFlowMenu::onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame)
{
    VFX_OBJ_CLOSE(groupFrame);
}

void VappMusicPlayerCoverFlowMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    if (m_page)
    {
        MediaCacheTask task = m_page->m_ctrlMediaCache->getTask(pos);
        m_page->m_ctrlMediaCache->freeImageBuffer(task.m_imageBuffer.ptr, pos);
    }

    VFX_OBJ_CLOSE(cellFrame);
}

void VappMusicPlayerCoverFlowMenu::onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag)
{
}

void VappMusicPlayerCoverFlowMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
    VappMusicPlayerCoverFlowMenuCell* item = (VappMusicPlayerCoverFlowMenuCell*) cell;

    // adjust cell position by reference rect information.
    VfxRect r = rect;
    r.origin.x += 1;
    r.origin.y += 1;
    r.size.width -= 2;
    r.size.height -= 2;

    // do animation or directly show without animation according to flag.
    if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        if (flag & VCP_CELL_FLAG_OPENING)
        {
            item->enter(r, VFX_TRUE);
        }
        else
        {
            item->enter(r, VFX_FALSE);
        }
    }
    else if (flag & VCP_CELL_FLAG_CLOSING)
    {
        item->leave(r);
    }
    else if (flag & VCP_CELL_FLAG_FORCESET)
    {
        item->updatePos(r, VFX_FALSE);
    }
    else
    {
        // There is no special flag, let's update position with aniamtion.
        item->updatePos(r, VFX_TRUE);
    }
}

void VappMusicPlayerCoverFlowMenu::onTouchCell(VcpMenuPos cellPos, CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
    if (touchType == VcpBaseMenu::TouchTap && !m_page->isDetailPanelAlive())
    {
        VappMusicPlayerCoverFlowMenuCell* item = (VappMusicPlayerCoverFlowMenuCell*) cell;
        item->click(cellPos);
        
        getLayout()->setFocusItem(cellPos);

        setCellBorder(VFX_TRUE, cellPos.pos);
    }
}

void VappMusicPlayerCoverFlowMenu::updateCellImage(VfxU32 index, VfxImageBuffer imgBuf)
{
    VcpMenuPos pos(0, index);
    VappMusicPlayerCoverFlowMenuCell* cell = VFX_OBJ_DYNAMIC_CAST(m_cache.getItem(pos), VappMusicPlayerCoverFlowMenuCell);
    if (cell)
    {
        // show album cover image and hide info text
        VfxImageSrc imgSrc(imgBuf);
        cell->setImage(imgSrc);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_COVER_FLOW_MENU_UPDATE_CELL, index);
    }
}

void VappMusicPlayerCoverFlowMenu::updateCellInfo(VfxU32 index)
{
    VcpMenuPos pos(0, index);
    VappMusicPlayerCoverFlowMenuCell* cell = VFX_OBJ_DYNAMIC_CAST(m_cache.getItem(pos), VappMusicPlayerCoverFlowMenuCell);
    if (cell)
    {
        VfxWString artist, album;
        artist.format("");
        album.format("");
        
        if (m_page)
        {
            m_page->getAlbumInfo(index, artist, album);
        }

        cell->setTextInfo(artist, album);
    }
}

void VappMusicPlayerCoverFlowMenu::hideAllCellImages()
{
    const VfxU32 itemNum = getLayout()->getCellCount(0);
    
    for (VfxU32 i = 0; i < itemNum; i++)
    {
        VcpMenuPos pos(0, i);
        VappMusicPlayerCoverFlowMenuCell* cell = VFX_OBJ_DYNAMIC_CAST(m_cache.getItem(pos), VappMusicPlayerCoverFlowMenuCell);
        if (cell)
        {
            cell->hideImage();
        }
    }
}

void VappMusicPlayerCoverFlowMenu::setCellBorder(VfxBool isShow, VfxS32 idx)
{
    if (isShow)
    {
        if (idx != -1)
        {
            VappMusicPlayerCoverFlowMenuCell* cell = VFX_OBJ_DYNAMIC_CAST(
                                                        m_cache.getItem(VcpMenuPos(0, idx)), 
                                                        VappMusicPlayerCoverFlowMenuCell
                                                        );
            if (cell)
            {
                if (m_focusCellIdx != -1)
                {
                    // some cell is still being high lighted
                    VappMusicPlayerCoverFlowMenuCell* hlCell = VFX_OBJ_DYNAMIC_CAST(
                                                                    m_cache.getItem(VcpMenuPos(0, m_focusCellIdx)), 
                                                                    VappMusicPlayerCoverFlowMenuCell
                                                                    );
                    if (hlCell)
                    {
                        hlCell->setHighlight(VFX_FALSE, VFX_TRUE);
                    }
                }

                cell->setHighlight(VFX_TRUE, VFX_TRUE);
                m_focusCellIdx = idx;
            }
        }
    }
    else
    {
        if (m_focusCellIdx != -1)
        {
            VappMusicPlayerCoverFlowMenuCell* cell = VFX_OBJ_DYNAMIC_CAST(
                                                        m_cache.getItem(VcpMenuPos(0, m_focusCellIdx)), 
                                                        VappMusicPlayerCoverFlowMenuCell
                                                        );
            if (cell)
            {
                cell->setHighlight(VFX_FALSE, VFX_TRUE);
            }

            m_focusCellIdx = -1;
        }
    }
}

/***************************************************************************** 
 * VappMusicPlayerCoverFlowMenuLayout Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerCoverFlowMenuLayout", VappMusicPlayerCoverFlowMenuLayout, VcpBaseMenuLayout);

void VappMusicPlayerCoverFlowMenuLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
}

void VappMusicPlayerCoverFlowMenuLayout::onDeinit()
{
    VcpBaseMenuLayout::onDeinit();
}

VcpBaseMenuLayout::ScrollDirEnum VappMusicPlayerCoverFlowMenuLayout::getScrollDir()
{
    return SCROLLDIR_HORZ;
}

VfxS32 VappMusicPlayerCoverFlowMenuLayout::getGroupCount()
{
    return 1;
}

VfxS32 VappMusicPlayerCoverFlowMenuLayout::getCellCount(VfxS32 group)
{
    // we cache the item number while initializing
    return getItemCount();
}

VfxS32 VappMusicPlayerCoverFlowMenuLayout::getContentLength()
{
    VfxS32 colNum = getCellCount(0) / 2 + (getCellCount(0) % 2 ? 1 : 0);
    return colNum * (CellWidth + CellGapX) + getStartEndSpace() * 2;
}

VfxBool VappMusicPlayerCoverFlowMenuLayout::hasGroupHeader(VfxS32 group)
{
    return VFX_FALSE;
}

VcpMenuRegion VappMusicPlayerCoverFlowMenuLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
        getCellByPos(r.origin),
        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
}

VcpMenuPos VappMusicPlayerCoverFlowMenuLayout::getCellByPos(VfxPoint pt)
{
    /*
    Layout of cover flow menu
    ------------------------------
    |       |       |       |
    |   0   |   2   |   4   |   ...
    |       |       |       |
    ------------------------------
    |       |       |       |
    |   1   |   3   |   5   |   ...
    |       |       |       |
    ------------------------------
    */

    VfxS32 x, y;
    VfxS32 cellAndGapWidth = CellWidth + CellGapX;
    VfxS32 cellAndGapHeight = CellHeight + CellGapY;

    x = (pt.x - getStartEndSpace()) / cellAndGapWidth;
    y = pt.y / cellAndGapHeight;

    VcpMenuPos p;
    p.group = 0;
    p.pos = x * 2 + y;

    if (p.pos < 0)
    {
        p.pos = 0;
    }
    else if (p.pos >= getCellCount(p.group))
    {
        p.pos = getCellCount(p.group) - 1;
    }
    return p;
}    

VfxRect VappMusicPlayerCoverFlowMenuLayout::queryCellRect(VcpMenuPos pos)
{
    return VfxRect(
        pos.pos / 2 * (CellWidth + CellGapX) + getStartEndSpace(),
        pos.pos % 2 ? CellHeight + CellGapY : 0,
        CellWidth,
        CellHeight
        );
}

void VappMusicPlayerCoverFlowMenuLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[0] = 0;
    margin[1] = 0;
    margin[2] = 0;
    margin[3] = 0;
}

void VappMusicPlayerCoverFlowMenuLayout::setItemCount(VfxS32 cnt)
{
    VFX_DEV_ASSERT(cnt >= 0);

    VcpMenuPos p = getFocusItem();
    m_itemCount = (VfxU32)cnt;

    if (cnt == 0)
    {
        clearFocusItem();
    }
    else if (p.isValid() && p.pos >= cnt)
    {
        setFocusItem(VcpMenuPos(0, cnt - 1));
    }

    update();
}

VfxU32 VappMusicPlayerCoverFlowMenuLayout::getItemCount()
{
    return m_itemCount;
}

VfxS32 VappMusicPlayerCoverFlowMenuLayout::getStartEndSpace()
{
    VfxS32 colNum = getCellCount(0) / 2 + (getCellCount(0) % 2 ? 1 : 0);
    
    if (colNum * (CellWidth + CellGapX) < GDI_LCD_WIDTH)
    {
        return 0;
    }
    else
    {
        return (VfxS32)StartEndSpace;
    }
}


/***************************************************************************** 
 * VappMusicPlayerCoverFlowMenuCell Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerCoverFlowMenuCell", VappMusicPlayerCoverFlowMenuCell, VfxControl);

void VappMusicPlayerCoverFlowMenuCell::onInit()
{
    VfxControl::onInit();

    setBgColor(VRT_COLOR_GREY);
    setAnchor(VfxFPoint(0.5, 0.5));
    setBorderColor(VRT_COLOR_MAKE(255, 157, 212, 130));
    setBorderWidth(0);
    setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setIsOpaque(VFX_TRUE);
    
    m_highlight = VFX_FALSE;

    // artist name
    VFX_OBJ_CREATE(m_textArtist, VfxTextFrame, this);
    m_textArtist->setAnchor(0.5, 0.0);
    m_textArtist->setPos(VAPP_MUSICPLY_CF_CELL_WIDTH / 2, TextArtistPosY);
    m_textArtist->setSize(VAPP_MUSICPLY_CF_CELL_WIDTH - TextArtistMarginX * 2, ArtistFontSize);
    m_textArtist->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(ArtistFontSize)));
    m_textArtist->setColor(VRT_COLOR_MAKE(255, 147, 147, 147));
    m_textArtist->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textArtist->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    // sont title
    VFX_OBJ_CREATE(m_textAlbum, VfxTextFrame, this);
    m_textAlbum->setAnchor(0.5, 0.0);
    m_textAlbum->setPos(VAPP_MUSICPLY_CF_CELL_WIDTH / 2, TextAlbumPosY);
    m_textAlbum->setSize(m_textArtist->getSize());
    m_textAlbum->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(AlbumFontSize)));
    m_textAlbum->setColor(VRT_COLOR_MAKE(255, 188, 188, 188));
    m_textAlbum->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textAlbum->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

}

void VappMusicPlayerCoverFlowMenuCell::onDeinit()
{
    VfxControl::onDeinit();
}

void VappMusicPlayerCoverFlowMenuCell::setHighlight(VfxBool isHighLight, VfxBool isAnim)
{
    m_highlight = isHighLight;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    
    if (m_highlight)
    {
        setBorderWidth(HighLightBorderSize);
    }
    else
    {
        setBorderWidth(0);
    } 
    
    VfxAutoAnimate::commit();
}

void VappMusicPlayerCoverFlowMenuCell::enter(const VfxRect& r, VfxBool animation)
{
    updatePos(r, VFX_FALSE);
    setOpacity(1.0f);
}

void VappMusicPlayerCoverFlowMenuCell::leave(const VfxRect& r)
{
}

void VappMusicPlayerCoverFlowMenuCell::updatePos(const VfxRect& r, VfxBool isAnim)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);

    setPos(VfxPoint(r.getMidX(), r.getMidY()));
    setBounds(VfxRect(VfxPoint(0, 0), r.size));

    VfxAutoAnimate::commit();
}

void VappMusicPlayerCoverFlowMenuCell::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);
    //m_textFrame->setBounds(VfxRect(0, 0, value.size.width, value.size.height));
}
void VappMusicPlayerCoverFlowMenuCell::setTextInfo(const VfxWString& textArtist, const VfxWString& textAlbum)
{
    m_textArtist->setString(textArtist);
    m_textAlbum->setString(textAlbum);
    
    m_textArtist->setHidden(VFX_FALSE);
    m_textAlbum->setHidden(VFX_FALSE);
}
void VappMusicPlayerCoverFlowMenuCell::click(VcpMenuPos index)
{
    // Find parent page and show song list
    VfxObject *p = findObject(this, VFX_OBJ_CLASS_INFO(VfxPage));

    if (p != NULL)
    {
        VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(p, VappMusicPlayerCoverFlowPage);
        page->showAlbumDetailPanel(index.pos);
    }
}

void VappMusicPlayerCoverFlowMenuCell::setImage(VfxImageSrc imgSrc)
{   
    setImgContent(imgSrc);
    
    VfxBool setTextHidden =  imgSrc.getType() != VFX_IMAGE_SRC_TYPE_RES_ID;
    m_textArtist->setHidden(setTextHidden);
    m_textAlbum->setHidden(setTextHidden);
}

void VappMusicPlayerCoverFlowMenuCell::hideImage()
{
    setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER));

    m_textArtist->setHidden(VFX_TRUE);
    m_textAlbum->setHidden(VFX_TRUE);
}

/***************************************************************************** 
 * VappMusicPlayerCoverFlowAlbumDetailPanel Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerCoverFlowAlbumDetailPanel", VappMusicPlayerCoverFlowAlbumDetailPanel, VfxControl);

void VappMusicPlayerCoverFlowAlbumDetailPanel::onInit()
{
    VfxControl::onInit();

    setOpacity(0.0f);
    setPos(0, 0);
    setSize(contentAreaWidth, contentAreaHeight);
    setAutoAnimate(VFX_TRUE);

    // Set focus to receive key event
    setFocused(VFX_TRUE);

    // Get parent object and provider
    VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    VFX_ASSERT(page);
    
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(page->getApp(), VappMusicPlayerApp);
    VFX_ASSERT(app);
    
    m_provider = app->getProvider();
    VFX_ASSERT(m_provider);

    VFX_OBJ_CREATE(m_listMenuProvider, VappMusicPlayerListMenuProvider, this);
    m_listMenuProvider->setDataProvider(m_provider);  // Set global data provider to this content provider
    m_listMenuProvider->setViewType(VIEW_TYPE_COVER_FLOW_SONG);

    // Shadow frame
    VFX_OBJ_CREATE(m_shadowFrame, VfxFrame, this);
    m_shadowFrame->setAnchor(0.5f, 0.5f);
    m_shadowFrame->setSize(borderFrameWidth + shadowSize*2, borderFrameHeight + shadowSize*2);
    m_shadowFrame->setPos(contentAreaWidth / 2 , contentAreaHeight / 2);
    m_shadowFrame->setOpacity(0.0f);
    m_shadowFrame->setAutoAnimate(VFX_TRUE);

    // Drop shadow
    VfxRect r(shadowSize, shadowSize, borderFrameWidth, borderFrameHeight);
    dropShadow(m_shadowFrame, r, VFX_TRUE);

    // Border frame
    VFX_OBJ_CREATE(m_borderFrame, VfxFrame, this);
    m_borderFrame->setAnchor(0.5f, 0.5f);
    m_borderFrame->setSize(borderFrameWidth, borderFrameHeight);
    m_borderFrame->setPos(contentAreaWidth / 2 , contentAreaHeight / 2);
    m_borderFrame->setBorder(VRT_COLOR_MAKE(255, 128, 128, 128), 0);

    // Frame to contain title bar and list menu
    VFX_OBJ_CREATE(m_listFrame, VfxFrame, m_borderFrame);
    m_listFrame->setAnchor(1.0f, 0.0f);
    m_listFrame->setSize(titleBarWidth, albumCoverHeight);
    m_listFrame->setPos(borderSize + albumCoverWidth, borderSize);
    m_listFrame->setOpacity(0.0f);
    m_listFrame->setAutoAnimate(VFX_TRUE);
    
    // Create list menu title
    VfxFrame *titleBG;
    VFX_OBJ_CREATE(titleBG, VfxFrame, m_listFrame);
    titleBG->setImgContent(VfxImageSrc(VCP_IMG_TITLEBAR_BACKGROUND_NORMAL));
    titleBG->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    titleBG->setPos(0, 0);
    titleBG->setSize(titleBarWidth, titleBarHeight);

    // Create album name text
    VfxWString titleTextString;
    m_provider->getTitle(m_albumIndex, titleTextString);

    // Set view to cover flow song and get list content
    app->setViewType(VIEW_TYPE_COVER_FLOW_SONG, CHANGE_VIEW_MODE_ENTER, m_albumIndex);

    VfxU32 num = m_provider->getCount();

    VfxTextFrame *titleText;
    VFX_OBJ_CREATE(titleText, VfxTextFrame, titleBG);
    titleText->setString(titleTextString);
    titleText->setAnchor(0.0f, 0.5f);
    titleText->setSize(titleBarTextWidth, titleBarTextHeight);
    titleText->setPos(titleBarMarginX, titleBarHeight / 2 + 5);
    titleText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    titleText->setVerticalToCenter(VFX_TRUE);
    VfxFontDesc font1(VFX_FONT_DESC_VF_SIZE(titleBarFontSize1), VFX_FE1_9);
    titleText->setFont(font1);
    titleText->setAutoResized(VFX_FALSE);
    titleText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    titleText->setColor(VFX_COLOR_WHITE);

    // Create album number text
    VfxWString str;
    str.format(" %d ", num);
    str += num > 1 ? VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS) : VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG);

    VfxTextFrame *numText;
    VFX_OBJ_CREATE(numText, VfxTextFrame, titleBG);
    numText->setString(str);
    numText->setAnchor(1.0f, 0.5f);
    numText->setPos(titleBarWidth, titleBarHeight / 2 + titleBarNumTextShiftY);
    numText->setSize(titleBarNumTextWidth, titleBarNumTextHeight);
    numText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    numText->setVerticalToCenter(VFX_TRUE);
    VfxFontDesc font2(VFX_FONT_DESC_VF_SIZE(titleBarFontSize2), VFX_FE1_9);
    numText->setFont(font2);
    numText->setAutoResized(VFX_FALSE);
    numText->setAutoFontSize((num >= 10) ? VFX_TRUE : VFX_FALSE);
    numText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    numText->setColor(VFX_COLOR_WHITE);

    // Create list menu
    VFX_OBJ_CREATE(m_listMenu, VappMusicPlayerListMenu, m_listFrame);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT_EX);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_listMenu->m_signalItemTapped.connect(this, &VappMusicPlayerCoverFlowAlbumDetailPanel::onListItemTapped);
    m_listMenu->setContentProvider(m_listMenuProvider);
    m_listMenu->setPos(0, titleBarHeight);
    m_listMenu->setSize(titleBarWidth, albumCoverHeight - titleBarHeight);
    m_listMenu->setItemHeight(listMenuItemHeight);
    m_listMenu->setIsOpaque(VFX_FALSE);
    m_listMenu->setSlowFactor(1.0, 1.0, 0.6);
	m_listMenu->setShadowIsDisabled(VFX_TRUE);
    m_listMenu->setItemSeparatorHidden(VFX_TRUE);

    m_provider->setListMenu(m_listMenu);
    m_listMenuProvider->setListMenu(m_listMenu);

    // List menu theme color
    VcpListMenuThemeStruct themeData = m_listMenu->getThemeData();
    themeData.normalTextColor = VRT_COLOR_MAKE(255, 255, 255, 255);
    themeData.lowlightTextColor = VRT_COLOR_MAKE(255, 150, 150, 150);
    themeData.highlightTextColor = VRT_COLOR_MAKE(255, 141, 200, 56);
    themeData.bgColor = VRT_COLOR_MAKE(170, 0, 0, 0);
    m_listMenu->setThemeData(themeData);

    // Create album cover
    VFX_OBJ_CREATE(m_albumImage, VfxFrame, m_borderFrame);
    m_albumImage->setPos(borderSize, borderSize);
    m_albumImage->setSize(albumCoverWidth, albumCoverHeight);
    m_albumImage->setBgColor(VRT_COLOR_MAKE(255, 10, 10, 10));
    m_albumImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_albumImage->setBorder(VRT_COLOR_BLACK, borderSize);
    m_albumImage->setCacheMode(VFX_CACHE_MODE_FREEZE);

    setAlbumCover();    

    // Transparent background
    VfxFrame *darkLayerTop = NULL;
    VFX_OBJ_CREATE(darkLayerTop, VfxFrame, this);
    darkLayerTop->setBgColor(VRT_COLOR_MAKE(128, 0, 0, 0));
    darkLayerTop->setPos(0, 0);
    darkLayerTop->setSize(contentAreaWidth, m_borderFrame->getRect().getMinY());

    VfxFrame *darkLayerBottom = NULL;
    VFX_OBJ_CREATE(darkLayerBottom, VfxFrame, this);
    darkLayerBottom->setBgColor(VRT_COLOR_MAKE(128, 0, 0, 0));
    darkLayerBottom->setPos(0, m_borderFrame->getRect().getMaxY() + 1);
    darkLayerBottom->setSize(contentAreaWidth, contentAreaHeight - m_borderFrame->getRect().getMaxY() + 1);

    VfxFrame *darkLayerLeft = NULL;
    VFX_OBJ_CREATE(darkLayerLeft, VfxFrame, this);
    darkLayerLeft->setBgColor(VRT_COLOR_MAKE(128, 0, 0, 0));
    darkLayerLeft->setPos(0, m_borderFrame->getRect().getMinY());
    darkLayerLeft->setSize(m_borderFrame->getRect().getMinX(), borderFrameHeight);

    VfxFrame *darkLayerRight = NULL;
    VFX_OBJ_CREATE(darkLayerRight, VfxFrame, this);
    darkLayerRight->setBgColor(VRT_COLOR_MAKE(128, 0, 0, 0));
    darkLayerRight->setPos(m_borderFrame->getRect().getMinX() + borderSize + albumCoverWidth, m_borderFrame->getRect().getMinY());
    darkLayerRight->setSize(contentAreaWidth - darkLayerRight->getPos().x, borderFrameHeight);

    m_borderFrame->bringToFront();

    // Timer for animation
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &VappMusicPlayerCoverFlowAlbumDetailPanel::onTimerTick);
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::onDeinit()
{
    m_timer->stop();

    VappMusicPlayerCoverFlowPage *coverFlow = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    if (coverFlow)
    {
        coverFlow->m_menu->setCellBorder(VFX_FALSE);
        coverFlow->m_menu->setIsDisabled(VFX_FALSE);
    }

    VfxControl::onDeinit();
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::setAlbumCover()
{
    //VfxWString filePath;
    //m_provider->getFilePath(0, filePath);
    
    VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    page->initMetaParser();
    
    VfxImageBuffer imgBuf;
    imgBuf.ptr = NULL;
    imgBuf.width = 0;
    imgBuf.height = 0;

    VcpMenuRegion region = m_listMenu->getRealContentRegion();
    VfxU32 index = region.begin.isValid() ? region.begin.pos : 0;

    VfxU32 ID = m_provider->getID(index);

    VfxBool useDefault = VFX_TRUE;
    if((ID > 0) && page->getAlbumCoverBySongId(ID, albumCoverWidth, albumCoverWidth,imgBuf))
    {
        useDefault = VFX_FALSE;
    }

#ifdef __LOW_COST_SUPPORT_COMMON__
    for (VfxU32 counter = 0; counter < 100 && m_albumImage->getChildCount() > 0; ++counter)
    {
        // close icon of default album cover
        VfxFrame *f = m_albumImage->getLastChildFrame();
        if (f)
        {
            VFX_OBJ_CLOSE(f);
        }
    }
#endif

    if (useDefault)
    {
#ifdef __LOW_COST_SUPPORT_COMMON__
        setDefaultCover(m_albumImage, VFX_FALSE, m_albumImage->getSize().width, m_albumImage->getSize().height, VFX_TRUE);
#else
        m_albumImage->setImgContent(VfxImageSrc(IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_NO_TEXT));
#endif
    }
    else
    {
        VfxImageSrc imgSrc;
        imgSrc.setImageBuffer(imgBuf);
        
        m_albumImage->setImgContent(imgSrc);
    }
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::onTimerTick(VfxTimer *timer)
{
    switch (m_animState)
    {
        case SHOW_STEP_1:
            showListFrame();
            break;

        case SHOW_STEP_2:
            // Show border
            m_borderFrame->setBorderWidth(borderSize);
            showShadow();
            m_animState = IDLE;
            break;

        case HIDE_STEP_1:
            hidePanel();
            break;

        case HIDE_STEP_2:
            _doClose();
            break;
    }
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::_doClose()
{
    VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    if (page)
    {
        page->onAlbumDetailPanelClosed();
    }

    VappMusicPlayerCoverFlowAlbumDetailPanel *pThis = this;
    VFX_OBJ_CLOSE(pThis);
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::startShow()
{
    showPanel();
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::startExit(VfxBool isAnim)
{
    setIsDisabled(VFX_TRUE);

    if (isAnim)
    {
        m_borderFrame->setBorderWidth(0);
        hideShadow();
        hideListFrame();
    }
    else
    {
        _doClose();
    }
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::showPanel()
{
    VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::showPanel]\n"));
    
    setAutoAnimate(VFX_TRUE);

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setOpacity(0.0f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::initAnimateBegin();
    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(ANIM_DURATION_SHOW);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE);
        setOpacity(1.0f);
    }
	VfxAutoAnimate::commit();
    VfxAutoAnimate::initAnimateEnd();    

    m_animState = SHOW_STEP_1;
    m_timer->setDuration(ANIM_DURATION_SHOW);
    m_timer->start();
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::hidePanel()
{
    VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::hidePanel]\n"));

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setOpacity(1.0f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(ANIM_DURATION_HIDE);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE);
        setOpacity(0.0f);
    }
    VfxAutoAnimate::commit();

    m_animState = HIDE_STEP_2;
    m_timer->setDuration(ANIM_DURATION_HIDE);
    m_timer->start();
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::showListFrame()
{
    VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::showListFrame]\n"));

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_listFrame->setOpacity(0.0f);
        m_listFrame->setPos(borderSize + albumCoverWidth, borderSize);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDuration(ANIM_DURATION_SHOW);
        VfxAutoAnimate::setDisable(VFX_FALSE);
        m_listFrame->setOpacity(1.0f);
        m_listFrame->setPos(borderFrameWidth - borderSize, borderSize);
    }
    VfxAutoAnimate::commit();

    m_animState = SHOW_STEP_2;
    m_timer->setDuration(ANIM_DURATION_SHOW);
    m_timer->start();
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::hideListFrame()
{
    VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::hideListFrame]\n"));

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_listFrame->setOpacity(1.0f);
        m_listFrame->setPos(borderFrameWidth - borderSize, borderSize);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(ANIM_DURATION_HIDE);
        m_listFrame->setOpacity(0.0f);
        m_listFrame->setPos(borderSize + albumCoverWidth, borderSize);
    }
    VfxAutoAnimate::commit();

    m_animState = HIDE_STEP_1;
    m_timer->setStartDelay(ANIM_DURATION_HIDE);
    m_timer->start();
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::showShadow()
{
    VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::showShadow]\n"));

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_shadowFrame->setOpacity(0.0f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(ANIM_DURATION_SHOW_FAST);
        m_shadowFrame->setOpacity(1.0f);
    }
    VfxAutoAnimate::commit();

    VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    if (page)
    {
        page->onAlbumDetailPanelShow();
    }
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::hideShadow()
{
    VFX_TRACE(("\n[VappMusicPlayerCoverFlowPage::hideShadow]\n"));

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_shadowFrame->setOpacity(1.0f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(ANIM_DURATION_HIDE_FAST);
        m_shadowFrame->setOpacity(0.0f);
    }
    VfxAutoAnimate::commit();
}

VfxBool VappMusicPlayerCoverFlowAlbumDetailPanel::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
                {
                    VappMusicPlayerCoverFlowPage *parent = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
                    if (parent)
                    {
                        parent->hideAlbumDetailPanel();
                    }
                }
                return VFX_TRUE;

            default:
                break;
        }
    }
    
    return VfxControl::onKeyInput(event);
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::onListItemTapped(VcpListMenu *menu, VfxU32 index)
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(findRootApp(this), VappMusicPlayerApp);

    if (app->blockActionInCall())
    {
        return;
    }

    app->onListMenuItemTapped(NULL, index);

    m_listMenu->updateItem(index);

    // set the flag to go to now playing on exit cover flow
    VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    if (page)
    {
        page->m_hasStartPlayback = VFX_TRUE;
    }
}

void VappMusicPlayerCoverFlowAlbumDetailPanel::updateListMenu(VfxS32 index)
{
    if (index == -1)
    {
        m_listMenu->updateAllItems();
    }
    else
    {
        m_listMenu->updateItem(index);
    }
}

VfxBool VappMusicPlayerCoverFlowAlbumDetailPanel::onPenInput(VfxPenEvent &event)
{
    VappMusicPlayerCoverFlowPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerCoverFlowPage);
    VFX_DEV_ASSERT(page != NULL);

    if(VFX_PEN_EVENT_TYPE_DOWN == event.type)
    {
        return VFX_TRUE;
    }

    switch(page->translateGesture(event))
    {
        case VG_TAP:
        {
            page->hideAlbumDetailPanel();
        }
        return VFX_TRUE;
    
        default:
            break;
    }

    return VfxControl::onPenInput(event);
}

#endif //__COSMOS_MUSICPLY__ && __COSMOS_MUSICPLY_COVER_FLOW__ && !__COSMOS_3D_V10__
