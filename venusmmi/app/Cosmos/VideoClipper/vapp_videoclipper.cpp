/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_videoclipper.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_VIDEO_CLIPPER__)
#include "vapp_videoclipper.h"
#include "mmi_rp_vapp_videoclipper_def.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_include.h"
#include "MMI_media_app_trc.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "vcp_confirm_popup.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "FileMgrSrvGProt.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mdi_video_clip.h"
#include "mdi_video.h"

#include "GlobalResDef.h"
#include "GpioSrvGprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mdi_audio.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"

#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ENDMARK_REPLAY_TIME     (1000) // ms
#define TIMER_DURATION          (250)  // ms

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VfxU8 VcuiVideoClipperPage::m_state = VcuiVideoClipperPage::STATE_IDLE;

/***************************************************************************** 
 * Function
 *****************************************************************************/

static mmi_ret _onMediaVolumeChange(mmi_event_struct *param)
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


VFX_IMPLEMENT_CLASS("VcuiVideoClipperCui", VcuiVideoClipperCui, VfxCui);

void VcuiVideoClipperCui::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    // create and display main screen
    VcuiVideoClipperScreen *scr;
    VFX_OBJ_CREATE(scr, VcuiVideoClipperScreen, this);
    scr->setParam((vcui_videoclipper_param_struct*)args, getGroupId());
    scr->show();
}


VFX_IMPLEMENT_CLASS("VcuiVideoClipperScreen", VcuiVideoClipperScreen, VfxMainScr);

void VcuiVideoClipperScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VcuiVideoClipperPage *page;
    VFX_OBJ_CREATE(page, VcuiVideoClipperPage, this);
    page->setParam(&m_param, m_id);
    pushPage(0, page);
}


void VcuiVideoClipperScreen::setParam(vcui_videoclipper_param_struct* param, VfxU32 appID)
{
    memcpy(&m_param, param, sizeof(vcui_videoclipper_param_struct));
    m_id = appID;
}


VFX_IMPLEMENT_CLASS("VcuiVideoClipperPage", VcuiVideoClipperPage, VfxPage);


VcuiVideoClipperPage::VcuiVideoClipperPage():
    m_textFrame(NULL),
    m_playControlButton(NULL),
    m_pauseControlButton(NULL),
    m_clipButton(NULL),
    m_tbar(NULL),
    m_sliderBgImage(NULL),
    m_slider(NULL),
    m_video(NULL),
    m_startTime(0),
    m_endTime(0),
    m_playTime(0),
    m_totalTime(0),
    m_isResought(VFX_FALSE),
    m_isWaitPlay(VFX_FALSE),
    m_isDelayPlay(VFX_FALSE),
    m_isWaitClip(VFX_FALSE),
    m_videoStartTimeText(NULL),
    m_videoEndTimeText(NULL),
    m_hintFrame(NULL),
    m_hintText(NULL),
    m_playTimer(NULL),
    m_processingTimer(NULL),
    m_popupMenu(NULL),
    m_rename_popup(NULL),
    m_processingPopup(NULL),
    m_isDeleteSrc(VFX_FALSE),
    m_result(VCUI_VIDEOCLIPPER_EVENT_RESULT_SUCCESS),
    m_hBackgroundPlay(NULL)
{
}


void VcuiVideoClipperPage::onNotificationCenterChanged(VappNCenterEventEnum event)
{
    if (!m_video->isValid())
        return;

    /* Add active app checking for avoiding USB popop causing screen change behind N-Center */
    VcuiVideoClipperCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiVideoClipperCui);
    if (!app->isActive())
        return;

    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
            if (m_state == STATE_PLAY_PLAYING)
            {
                pauseVideo();
                enterState(STATE_PLAY_INT_PLAYING, __LINE__);
            }
            break;
        case VAPP_NCENTER_EVENT_EXITED:
            if (m_state == STATE_PLAY_INT_PLAYING ||
                m_isDelayPlay)
            {
                if (m_state == STATE_PLAY_INT_PLAYING)
                    enterState(STATE_PLAY_READY, __LINE__);
                else if (m_isDelayPlay)
                {
                    m_isDelayPlay = VFX_FALSE;
                    if (m_state == STATE_PLAY_SEEKING)
                        m_isWaitPlay = VFX_TRUE;
                }
                playVideo(m_playTime);
            }              
            break;
        default:
            break;
    }    
}


void VcuiVideoClipperPage::onInit()
{
    VfxPage::onInit(); // call base class

    m_setting.total_time = 0;
    m_setting.curr_time = 0;

    VFX_OBJ_CREATE(m_tbar, VcpTitleBar, this);
    m_tbar->setTitle(VFX_WSTR("Video Clipper"));
    setTopBar(m_tbar);

    // create a frame
    VfxFrame *f;
    VFX_OBJ_CREATE(f, VfxFrame, this);
    f->setBgColor(VFX_COLOR_BLACK);
    f->setIsUnhittable(VFX_TRUE);

    // position it according to current size
    VfxSize size = getSize();
    f->setPos(0, 0);
    f->setSize(size);

    // align it!
    f->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VappVideoPlayerPlayOption option;
    option.configAsNormalVideo();
    option.supportFullResolution = VFX_TRUE;
    option.isKeepBacklight = VFX_TRUE;
    
    VFX_OBJ_CREATE_EX(m_video, VappVideoPlayerComponent, this, (option));
    VFX_OBJ_CREATE(m_sliderBgImage, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_slider, VappVideoClipperSlider, this);
    VFX_OBJ_CREATE(m_playControlButton, VcpImageButton, this);
    VFX_OBJ_CREATE(m_pauseControlButton, VcpImageButton, this);
    VFX_OBJ_CREATE(m_clipButton, VcpImageButton, this);
    VFX_OBJ_CREATE(m_videoStartTimeText, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_videoEndTimeText, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_hintFrame, VfxFrame, this);
    VFX_OBJ_CREATE(m_hintText, VfxTextFrame, m_hintFrame);
    VFX_OBJ_CREATE(m_playTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_processingTimer, VfxTimer, this);
    VFX_OBJ_CREATE(m_processingPopup, VcpIndicatorPopup,this);
    
    m_state = STATE_IDLE;
    m_slider->setMinValue(0.0f);
    m_slider->setMaxValue(1.0f);

    VfxImageSrc HintBg(IMG_ID_VAPPP_VDOCLIPPER_HINT_BG);
    
    m_hintFrame->setHidden(VFX_TRUE);
    m_hintFrame->setAnchor(0.5, 0.5);
    m_hintFrame->setBgColor(VRT_COLOR_TRANSPARENT);
    m_hintFrame->setImgContent(HintBg);
    m_hintFrame->setSize(HintBg.getSize().width, HintBg.getSize().height);
    
    m_hintText->setFont(VFX_FONT_DESC_SMALL);
    m_hintText->setAnchor(0.5, 0.5);
    m_hintText->setPos(HintBg.getSize().width / 2, HINT_STR_Y_OFFSET);

    m_playTimer->setStartDelay(TIMER_DURATION);
    m_playTimer->setDuration(TIMER_DURATION);
    m_playTimer->m_signalTick.connect(this, &VcuiVideoClipperPage::onPlayTimerTick);    

    m_processingTimer->setStartDelay(TIMER_DURATION);
    m_processingTimer->setDuration(TIMER_DURATION);
    m_processingTimer->m_signalTick.connect(this, &VcuiVideoClipperPage::onProcessingTimerTick);
    
    VcpStateImage play(IMG_ID_VAPPP_VDOCLIPPER_PLAY_ICON);
    
    m_playControlButton->setImage(play);
    m_playControlButton->setAnchor(0.5, 0.5);
    m_playControlButton->setPos(PLAY_PAUSE_BUTTON_X, PLAY_PAUSE_BUTTON_Y);
    m_playControlButton->setSize(play.getImageNormal().getSize().width, play.getImageNormal().getSize().height);

    VcpStateImage pause(IMG_ID_VAPPP_VDOCLIPPER_PAUSE_ICON);
    
    m_pauseControlButton->setImage(pause);
    m_pauseControlButton->setAnchor(0.5, 0.5);
    m_pauseControlButton->setPos(PLAY_PAUSE_BUTTON_X, PLAY_PAUSE_BUTTON_Y);
    m_pauseControlButton->setSize(pause.getImageNormal().getSize().width, pause.getImageNormal().getSize().height);
    
    VcpStateImage clip(IMG_ID_VAPPP_VDOCLIPPER_TRIM_ICON);
    
    m_clipButton->setImage(clip);
    m_clipButton->setAnchor(0.5, 0.5);
    m_clipButton->setPos(TRIM_BUTTON_X, TRIM_BUTTON_Y);
    m_clipButton->setSize(clip.getImageNormal().getSize().width, clip.getImageNormal().getSize().height);

    m_processingPopup->setAnchor(0.5, 0.5);
    m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_processingPopup->setAutoDestory(VFX_FALSE);
    m_processingPopup->setAutoAnimate(VFX_FALSE);
    m_processingPopup->setProgress(0);
    m_processingPopup->m_signalCanceled.connect(this, &VcuiVideoClipperPage::onProcessingCancel);

    m_videoStartTimeText->setAnchor(0.0, 0.5);
    m_videoEndTimeText->setAnchor(1.0, 0.5);
        
    setTranslucent(VFX_TRUE);

    // make the clip slider hit ratio higher
    m_video->setIsUnhittable(VFX_TRUE); 
    m_sliderBgImage->setIsUnhittable(VFX_TRUE);   
    m_videoStartTimeText->setIsUnhittable(VFX_TRUE);
    m_videoEndTimeText->setIsUnhittable(VFX_TRUE);
    m_hintFrame->setIsUnhittable(VFX_TRUE);

    m_slider->m_signalStartThumbPressed.connect(this, &VcuiVideoClipperPage::startClipMarkPressedHdlr);
    m_slider->m_signalStartThumbReleased.connect(this, &VcuiVideoClipperPage::startClipMarkReleasedHdlr);
    m_slider->m_signalStartThumbDrag.connect(this, &VcuiVideoClipperPage::startClipMarkDragHdlr);
    m_slider->m_signalStartThumbAbort.connect(this, &VcuiVideoClipperPage::startClipMarkAbortHdlr);
    m_slider->m_signalEndThumbPressed.connect(this, &VcuiVideoClipperPage::endClipMarkPressedHdlr);
    m_slider->m_signalEndThumbReleased.connect(this, &VcuiVideoClipperPage::endClipMarkReleasedHdlr);
    m_slider->m_signalEndThumbDrag.connect(this, &VcuiVideoClipperPage::endClipMarkDragHdlr);
    m_slider->m_signalEndThumbAbort.connect(this, &VcuiVideoClipperPage::endClipMarkAbortHdlr);    
    m_slider->m_signalPlayThumbPressed.connect(this, &VcuiVideoClipperPage::playClipMarkPressedHdlr);
    m_slider->m_signalPlayThumbReleased.connect(this, &VcuiVideoClipperPage::playClipMarkReleasedHdlr);
    m_slider->m_signalPlayThumbDrag.connect(this, &VcuiVideoClipperPage::playClipMarkDragHdlr);
    m_slider->m_signalPlayThumbAbort.connect(this, &VcuiVideoClipperPage::playClipMarkAbortHdlr);
    
    VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->m_signalEvent.connect(this, &VcuiVideoClipperPage::onNotificationCenterChanged);    
}


void VcuiVideoClipperPage::onDeinit()
{
    m_state = STATE_IDLE;
        
    VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->m_signalEvent.disconnect(this, &VcuiVideoClipperPage::onNotificationCenterChanged);

    m_slider->m_signalStartThumbPressed.disconnect(this, &VcuiVideoClipperPage::startClipMarkPressedHdlr);
    m_slider->m_signalStartThumbReleased.disconnect(this, &VcuiVideoClipperPage::startClipMarkReleasedHdlr);
    m_slider->m_signalStartThumbDrag.disconnect(this, &VcuiVideoClipperPage::startClipMarkDragHdlr);
    m_slider->m_signalStartThumbAbort.disconnect(this, &VcuiVideoClipperPage::startClipMarkAbortHdlr);    
    m_slider->m_signalEndThumbPressed.disconnect(this, &VcuiVideoClipperPage::endClipMarkPressedHdlr);
    m_slider->m_signalEndThumbReleased.disconnect(this, &VcuiVideoClipperPage::endClipMarkReleasedHdlr);
    m_slider->m_signalEndThumbDrag.disconnect(this, &VcuiVideoClipperPage::endClipMarkDragHdlr);
    m_slider->m_signalEndThumbAbort.disconnect(this, &VcuiVideoClipperPage::endClipMarkAbortHdlr);     
    m_slider->m_signalPlayThumbPressed.disconnect(this, &VcuiVideoClipperPage::playClipMarkPressedHdlr);
    m_slider->m_signalPlayThumbReleased.disconnect(this, &VcuiVideoClipperPage::playClipMarkReleasedHdlr);
    m_slider->m_signalPlayThumbDrag.disconnect(this, &VcuiVideoClipperPage::playClipMarkDragHdlr);
    m_slider->m_signalPlayThumbAbort.disconnect(this, &VcuiVideoClipperPage::playClipMarkAbortHdlr);
    
    VfxPage::onDeinit(); // call base class
}


void VcuiVideoClipperPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_ONENTER, m_state);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    VappNCenter *pNCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    const VfxBool isNCenterEntered = (pNCenter) ? pNCenter->getNCenterEntered() : VFX_FALSE;
    
    if (m_state == STATE_PLAY_INT_PLAYING)
    {
        if (isNCenterEntered)
            m_isDelayPlay = VFX_TRUE;
        else    
            m_isWaitPlay = VFX_TRUE;
    }
    else if (m_state == STATE_CLIP_INT_PREPARING)
    {
        m_isWaitClip = VFX_TRUE;
    }
        
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &_onMediaVolumeChange, this);

    if(NULL == m_hBackgroundPlay)
    {
        m_hBackgroundPlay = mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_ANON_APP);
    }
    
    m_sliderBgImage->setResId(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_BG);
    m_sliderBgImage->setHidden(VFX_TRUE);
    
    VfxWChar* filename_pos;  
    filename_pos = pathGetFilename(m_setting.filepath);      
    m_fileName.loadFromMem(filename_pos);
    m_tbar->setTitle(m_fileName);
    m_slider->setHidden(VFX_TRUE);

    m_srcFilePath.loadFromMem(m_setting.filepath);
    
    m_playControlButton->setHidden(VFX_TRUE);
    m_playControlButton->m_signalClicked.connect(this, &VcuiVideoClipperPage::playControlButtonClickHdlr);

    m_pauseControlButton->setHidden(VFX_TRUE);
    m_pauseControlButton->m_signalClicked.connect(this, &VcuiVideoClipperPage::pauseControlButtonClickHdlr);
    
    m_clipButton->setHidden(VFX_TRUE);
    m_clipButton->m_signalClicked.connect(this, &VcuiVideoClipperPage::clipButtonClickHdlr);

    // Init start & play marker position
    if (!isBackward)
    {
        m_startTime = m_setting.curr_time;
        m_totalTime = m_setting.total_time;
    }
    
    if (m_totalTime < 1000)
    {
        vcui_videoclipper_result_event_struct evt;

        MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_VIDEOCLIPPER_EVENT_RESULT_FAILED, m_appID);
        evt.result = VCUI_VIDEOCLIPPER_EVENT_RESULT_FAILED;
            
        VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
        app->postToCaller((mmi_group_event_struct*)&evt);
        return;
    }
 
    VFX_ASSERT(m_totalTime >= m_startTime);

    if (m_totalTime - m_startTime < 1000)
    {
        m_startTime = 0;
    }
    
    if (!isBackward)
        m_playTime = m_startTime;  

    m_videoStartTimeText->setHidden(VFX_TRUE);
    m_videoStartTimeText->setFont(VFX_FONT_DESC_SMALL);
    
    m_videoEndTimeText->setHidden(VFX_TRUE);
    m_videoEndTimeText->setFont(VFX_FONT_DESC_SMALL);

    // Open the file
    VfxWString filepath;
    MDI_RESULT ret;
    
    filepath.loadFromMem(m_setting.filepath);

    m_video->m_signalFileOpened.connect(this, &VcuiVideoClipperPage::openFileReady);
    m_video->m_signalSeekFinished.connect(this, &VcuiVideoClipperPage::seekFinished);
    m_video->m_signalPlaybackFinished.connect(this, &VcuiVideoClipperPage::playBackFinished);
    ret = m_video->openFileEx(filepath, VFX_FALSE, m_playTime);
    enterState(STATE_PLAY_OPENING, __LINE__);

}


void VcuiVideoClipperPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_ONEXIT, m_state);
    
    if (m_state == STATE_PLAY_OPENING ||
        m_state == STATE_PLAY_PLAYING ||
        m_state == STATE_PLAY_PAUSED ||
        m_state == STATE_PLAY_SEEKING)
    {
        stopVideo();
        
        if (m_state == STATE_PLAY_PLAYING)
            enterState(STATE_PLAY_INT_PLAYING, __LINE__);
    }
    else if (m_state == STATE_CLIP_PREPARING ||
             m_state == STATE_CLIP_CLIPPING)
    {
        clipVideoStop();
        clipVideoClose();

        m_processingPopup->hide(VFX_FALSE);
        enterState(STATE_CLIP_INT_PREPARING, __LINE__);
    }
   
    if(m_hBackgroundPlay)
    {
        mdi_audio_resume_background_play_by_app((MDI_AUD_SUSPEND_BG_APP)m_hBackgroundPlay);
        m_hBackgroundPlay = NULL;
    }
    
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &_onMediaVolumeChange, this);

    VfxPage::onExit(isBackward);
}


void VcuiVideoClipperPage::onExited2()
{
    m_video->closeFile();
    
    if (m_state != STATE_PLAY_INT_PLAYING && 
        m_state != STATE_CLIP_INT_PREPARING)
        enterState(STATE_IDLE, __LINE__);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_STATE, m_state, __LINE__);
    
    VfxPage::onExited2();
}


void VcuiVideoClipperPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if (LCD_HEIGHT > LCD_WIDTH)
        param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
    else
        param.rotateTo = VFX_SCR_ROTATE_TYPE_0;

}


VfxBool VcuiVideoClipperPage::onKeyInput(VfxKeyEvent &event)
{
    if(event.keyCode == VFX_KEY_CODE_ENTER)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_UP)
        {
            if (m_state == STATE_PLAY_PLAYING)
            {
                pauseVideo();
            }
            else if (m_state == STATE_PLAY_READY)
            {
                if (m_playTime == m_endTime || m_isResought)
                {
                    if (m_playTime == m_endTime)
                    {
                        m_playTime = m_startTime;

                        VfxFloat barPos = m_playTime / (VfxFloat)m_totalTime;
                        m_slider->setPlayThumbAutoAnimate(VFX_FALSE);
                        m_slider->setPlayThumbValue(barPos);        
                        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);
                    }
                    
                    playVideo(m_playTime);
                }
                else
                    playVideo();
            }
        }
        return VFX_TRUE;
    }    

    VfxPage::onKeyInput(event);
}


void VcuiVideoClipperPage::setBounds(const VfxRect &value)
{
    VfxPage::setBounds(value);
    
    if (m_slider && m_setting.total_time)
    {   
        VfxSize size = getSize();
        
        m_sliderBgImage->setPos(SLIDER_BG_X, SLIDER_BG_Y);
        m_sliderBgImage->setSize(size.width - 2*SLIDER_BG_X, SLIDER_BG_HEIGHT);
        m_sliderBgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
        m_slider->setPos(SLIDER_X, SLIDER_Y);
        m_slider->setLength(size.width - 2*SLIDER_X);
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SETBOUNDS, size.width, m_setting.total_time);

        if (m_video)
        {
            m_video->setPos(0, 0);
            m_video->setSize(size.width, size.height);
        }

        if (m_videoStartTimeText)
        {
            VfxPoint startPos;
            
            startPos = convertPointFrom(m_slider->getInitStartThumbPos(), m_slider);
            m_videoStartTimeText->setPos(
                                    SLIDER_X, 
                                    startPos.y + TIME_TEXT_GAP_Y);
        }

        if (m_videoEndTimeText)
        {
            VfxPoint endtPos;

            endtPos = convertPointFrom(m_slider->getInitEndThumbPos(), m_slider);
            
            m_videoEndTimeText->setPos(
                                    SLIDER_X + m_slider->getSize().width, 
                                    endtPos.y + TIME_TEXT_GAP_Y);
        }
    }

}


void VcuiVideoClipperPage::updateUI()
{
    VcuiVideoClipperCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiVideoClipperCui);
}


void VcuiVideoClipperPage::setParam(vcui_videoclipper_param_struct* param, VfxU32 appID)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_PAGESETPARAM);
    memcpy(&m_setting, param, sizeof(vcui_videoclipper_param_struct));
    m_appID = appID;
}


U64 VcuiVideoClipperPage::msecToSec(U64 timeMsec)
{
#define MSEC_PER_SEC (1000)

    const VfxU64 seconds_offset = (500 < (timeMsec % 1000))? 1 : 0;
    const U64 timeSec = timeMsec / MSEC_PER_SEC + seconds_offset;
    return timeSec;
}


VfxWChar* VcuiVideoClipperPage::pathGetFilename(VfxWChar* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxWChar *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path) return NULL;

    for(ptr=path; *ptr; ptr++);

    for(; *ptr!='\\' && ptr!=path; ptr--);

    if(*ptr == '\\')
        ptr++;

    return ptr;
}


void VcuiVideoClipperPage::openFileReady(VappVideoPlayerComponent *player, MDI_RESULT result)
{
    if (m_video->isValid())
    {
        if (result == MDI_RES_VDOPLY_SUCCEED)
        {
            enterState(STATE_PLAY_READY, __LINE__);

            VfxFloat ratio = (VfxFloat)1000/m_setting.total_time;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SLIDERRATIO, (VfxU32)(ratio*100));
            
            if (ratio > 0.15)
            {
                m_slider->setStartThumbFuzzyRatio(0.05);
            }
            else
                m_slider->setStartThumbFuzzyRatio(0);
            
            m_slider->setMinClipBarRatio(ratio);
            
            VfxFloat barLength;
            barLength = m_startTime / (VfxFloat)m_totalTime;
            m_slider->setStartThumbAutoAnimate(VFX_FALSE);
            m_slider->setStartThumbValue(barLength);

            barLength = m_playTime / (VfxFloat)m_totalTime;
            m_slider->setPlayThumbAutoAnimate(VFX_FALSE);
            m_slider->setPlayThumbValue(barLength);
            
            m_slider->setHidden(VFX_FALSE);
            m_sliderBgImage->setHidden(VFX_FALSE);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);
            
            m_playControlButton->setHidden(VFX_FALSE);
            m_clipButton->setHidden(VFX_FALSE);
            VfxWString start, end;

            m_video->getTotalDuration(m_totalTime);
            getTimeText(start, 0, VFX_TRUE);
            getTimeText(end, m_totalTime, VFX_TRUE);

            m_videoStartTimeText->setString(start);
            m_videoEndTimeText->setString(end);

            m_videoStartTimeText->setHidden(VFX_FALSE);
            m_videoEndTimeText->setHidden(VFX_FALSE);

            m_endTime = getVideoTime(m_slider->getEndThumbValue());

            if (m_playTime > 0)
                seekVideo(m_playTime);
            else if (m_isWaitClip)
                clipVideoOpen();
                
        }
        else
        {
            vcui_videoclipper_result_event_struct evt;

            MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_VIDEOCLIPPER_EVENT_RESULT_FAILED, m_appID);
            evt.result = VCUI_VIDEOCLIPPER_EVENT_RESULT_FAILED;
                
            VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
            app->postToCaller((mmi_group_event_struct*)&evt);
        }
    
    }

}


void VcuiVideoClipperPage::seekFinished(VappVideoPlayerComponent *player, MDI_RESULT result)
{
    if (m_video->isValid())
    {
        if (m_state == STATE_PLAY_SEEKING)
            enterState(STATE_PLAY_READY, __LINE__);
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SEEKEND, m_state, __LINE__);

        if (m_isWaitPlay)
        {
            m_isWaitPlay = VFX_FALSE;
            playVideo();
        }
        else if (m_isWaitClip)
            clipVideoOpen();
    }
}


void VcuiVideoClipperPage::playBackFinished(VappVideoPlayerComponent *player, MDI_RESULT result)
{
    m_playTimer->stop();
    m_playTime = m_endTime;
    m_slider->setPlayThumbAutoAnimate(VFX_TRUE);
    m_slider->setPlayThumbValue(m_slider->getEndThumbValue());
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);
    enterState(STATE_PLAY_READY, __LINE__);
    
    drawPlayIcon();
    
}


void VcuiVideoClipperPage::startClipMarkPressedHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_isWaitPlay = VFX_FALSE;
        pauseVideo();
        m_slider->setStartThumbAutoAnimate(VFX_FALSE);

        VappVideoMsec time = getVideoTime(value);
        VfxWString string;
        VfxPoint thumbPos;
        VfxPoint pos;

        getTimeText(string, time, VFX_TRUE);

        thumbPos = m_slider->getStartThumbPos();
        pos = convertPointFrom(thumbPos, m_slider);

        m_hintText->setString(string);
        m_hintFrame->setPos(pos.x, HINT_TEXTFRAME_Y);
        m_hintFrame->setHidden(VFX_FALSE);
    }
}


void VcuiVideoClipperPage::startClipMarkReleasedHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {        
        m_startTime = getVideoTime(value);
    #ifdef __MTK_TARGET__ 
        mdi_video_ply_get_key_frame_time(m_startTime, MDI_VIDEO_SEARCH_DIR_BACKWARD, &m_startTime);
    #else
        if (m_startTime > 1500)
            m_startTime -= 1500;
        else
            m_startTime = 0;
    #endif

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_STARTMAKER_RELEASE, m_startTime);
        
        m_playTime = m_startTime;
        seekVideo(m_startTime);

        VfxFloat barLength;
        barLength = m_startTime / (VfxFloat)m_totalTime;
        m_slider->setStartThumbAutoAnimate(VFX_TRUE);
        m_slider->setStartThumbValue(barLength);        
        
        m_slider->setPlayThumbAutoAnimate(VFX_FALSE);
        m_slider->setPlayThumbValue(barLength);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);

        m_hintFrame->setHidden(VFX_TRUE);
    }
}


void VcuiVideoClipperPage::startClipMarkDragHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        VappVideoMsec time = getVideoTime(value);
        VfxWString string;
        VfxPoint thumbPos;
        VfxPoint pos;

        getTimeText(string, time, VFX_TRUE);

        thumbPos = m_slider->getStartThumbPos();
        pos = convertPointFrom(thumbPos, m_slider);

        m_hintText->setString(string);
        m_hintFrame->setPos(pos.x, HINT_TEXTFRAME_Y);
        m_hintFrame->setHidden(VFX_FALSE);
    }
}


void VcuiVideoClipperPage::startClipMarkAbortHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_hintFrame->setHidden(VFX_TRUE);
    }
}


void VcuiVideoClipperPage::endClipMarkPressedHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_isWaitPlay = VFX_FALSE;
        pauseVideo();

        VappVideoMsec time = getVideoTime(value);
        VfxWString string;
        VfxPoint thumbPos;
        VfxPoint pos;

        getTimeText(string, time, VFX_TRUE);

        thumbPos = m_slider->getEndThumbPos();
        pos = convertPointFrom(thumbPos, m_slider);

        m_hintText->setString(string);
        m_hintFrame->setPos(pos.x, HINT_TEXTFRAME_Y);
        m_hintFrame->setHidden(VFX_FALSE);
    }    
}


void VcuiVideoClipperPage::endClipMarkReleasedHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_endTime = getVideoTime(value);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
        seekVideo(m_endTime);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_ENDMAKER_RELEASE, m_endTime);
        if (m_playTime > m_endTime)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SET_PLAYTIME_OVER_ENDTIME, m_playTime, m_endTime);
            m_playTime = m_endTime;

            VfxFloat barLength;
            barLength = m_playTime / (VfxFloat)m_totalTime;
            m_slider->setPlayThumbAutoAnimate(VFX_FALSE);
            m_slider->setPlayThumbValue(barLength);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);

        }
    #endif
#endif
        m_hintFrame->setHidden(VFX_TRUE);
    }

    // TODO: display the video from the previous 1 s than end mark position
}


void VcuiVideoClipperPage::endClipMarkDragHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        VappVideoMsec time = getVideoTime(value);
        VfxWString string;
        VfxPoint thumbPos;
        VfxPoint pos;

        getTimeText(string, time, VFX_TRUE);

        thumbPos = m_slider->getEndThumbPos();
        pos = convertPointFrom(thumbPos, m_slider);

        m_hintText->setString(string);
        m_hintFrame->setPos(pos.x, HINT_TEXTFRAME_Y);
        m_hintFrame->setHidden(VFX_FALSE);
    }
}


void VcuiVideoClipperPage::endClipMarkAbortHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_hintFrame->setHidden(VFX_TRUE);
    }
}


void VcuiVideoClipperPage::playClipMarkPressedHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        if (m_state == STATE_PLAY_PLAYING)
        {
            pauseVideo();
            m_isWaitPlay = VFX_TRUE; // When released, need to resume playing.
        }
        VappVideoMsec time = getVideoTime(value);
        VfxWString string;
        VfxPoint thumbPos;
        VfxPoint pos;

        getTimeText(string, time, VFX_TRUE);

        thumbPos = m_slider->getPlayThumbPos();
        pos = convertPointFrom(thumbPos, m_slider);

        m_hintText->setString(string);
        m_hintFrame->setPos(pos.x, HINT_TEXTFRAME_Y);
        m_hintFrame->setHidden(VFX_FALSE);
    }    
}


void VcuiVideoClipperPage::playClipMarkReleasedHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_hintFrame->setHidden(VFX_TRUE);
        m_playTime = getVideoTime(value);
        seekVideo(m_playTime);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_PLAYMAKER_RELEASE, m_playTime);
    }
}


void VcuiVideoClipperPage::playClipMarkDragHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        VappVideoMsec time = getVideoTime(value);
        VfxWString string;
        VfxPoint thumbPos;
        VfxPoint pos;

        getTimeText(string, time, VFX_TRUE);

        thumbPos = m_slider->getPlayThumbPos();
        pos = convertPointFrom(thumbPos, m_slider);

        m_hintText->setString(string);
        m_hintFrame->setPos(pos.x, HINT_TEXTFRAME_Y);
        m_hintFrame->setHidden(VFX_FALSE);
    }
}


void VcuiVideoClipperPage::playClipMarkAbortHdlr(VappVideoClipperSlider *slider, VfxFloat value)
{
    if (slider->isValid())
    {
        m_hintFrame->setHidden(VFX_TRUE);
    }
}


void VcuiVideoClipperPage:: clipPrepareCB(MDI_RESULT result, void* userData)
{
    VcuiVideoClipperPage* this_ptr = (VcuiVideoClipperPage*) userData;

    if (this_ptr->isValid())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CLIP_PREPARECB, m_state, result);
        if (result == MDI_RES_VDOCLIP_SUCCEED)
        {
            this_ptr->clipVideoStart();
        }
        else
        {
            this_ptr->clipVideoClose();
            this_ptr->clipCbEventHdlr(result);
        }
    }
}


void VcuiVideoClipperPage:: clipResultCB(MDI_RESULT result, void* userData)
{
    VcuiVideoClipperPage* this_ptr = (VcuiVideoClipperPage*) userData;
    
    if (this_ptr->isValid())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CLIP_RESULTCB, m_state, result);
        
        this_ptr->clipVideoClose();
        this_ptr->clipCbEventHdlr(result);
    }    
}


void VcuiVideoClipperPage::clipCbEventHdlr(MDI_RESULT result)
{
    m_video->closeFile();
    enterState(STATE_IDLE, __LINE__);
    
    if (result == MDI_RES_VDOCLIP_SUCCEED)
    {
        m_result = VCUI_VIDEOCLIPPER_EVENT_RESULT_SUCCESS;
        m_processingPopup->setProgress(1.0);

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
        renderer->blockAfterNextCommit(1, VfxCallback0(this, &VcuiVideoClipperPage::onProgressBarFinish));

        if (m_isDeleteSrc)
        {
            FS_Delete((WCHAR*)m_srcFilePath.getBuf());
            FS_Rename(m_dstFilePath.getBuf(), m_srcFilePath.getBuf());
            m_dstFilePath = m_srcFilePath;
        }
    }
    else
    {
        VfxU16 stringID;
        mmi_event_notify_enum popup_type;

        stringID = mdi_video_clip_get_error_info(result, &popup_type);
        displayErrorPopup(stringID);
        
    }

}


void VcuiVideoClipperPage::playVideo(VappVideoMsec time)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_PLAY_VIDEO_WITH_TIME, m_state);
    
    if (m_state == STATE_PLAY_READY && m_video->isValid())
    {
        m_video->seek(time);
        m_isWaitPlay = VFX_TRUE;
        m_isResought = VFX_FALSE;
        drawPauseIcon();
    }    
}


void VcuiVideoClipperPage::playVideo()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_PLAY_VIDEO, m_state);
    
    if (m_state == STATE_PLAY_READY && m_video->isValid())
    {        
        m_isResought = VFX_FALSE;
        MDI_RESULT ret = m_video->play();
        if (ret == MDI_RES_VDOPLY_SUCCEED)
        {
            m_playTimer->start();
            enterState(STATE_PLAY_PLAYING, __LINE__);
            drawPauseIcon();
        }
        else
        {
            drawPlayIcon();
        }
    }    
}


void VcuiVideoClipperPage::pauseVideo()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_PAUSE_VIDEO, m_state);
    
    if ((m_state == STATE_PLAY_PLAYING || 
         m_state == STATE_PLAY_SEEKING)&& 
        m_video->isValid())
    {
        m_video->pause();
        enterState(STATE_PLAY_READY, __LINE__);
        
        m_playTimer->stop();
    }

    if ((m_state == STATE_PLAY_READY ||
         m_state == STATE_PLAY_SEEKING) && 
        m_video->isValid())
    {
        drawPlayIcon();
    }
}


void VcuiVideoClipperPage::seekVideo(VappVideoMsec time)
{
    if (!m_video->isValid())
        return;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SEEK_VIDEO, m_state);

    if (m_state == STATE_PLAY_READY ||
        m_state == STATE_PLAY_PAUSED ||
        m_state == STATE_PLAY_SEEKING )
    {
        #ifdef __MTK_TARGET__    
        if (m_video->isSeekable())
        #endif    
        {
            m_isResought = VFX_TRUE;
            m_video->seek(time);
            enterState(STATE_PLAY_SEEKING, __LINE__);
        }
    }
}

void VcuiVideoClipperPage::stopVideo()
{
    if (!m_video->isValid())
        return;
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_STOP_VIDEO, m_state);
    
    m_video->stop();
    m_playTimer->stop();

    drawPlayIcon();

}

void VcuiVideoClipperPage::clipVideoOpen()
{
    MDI_RESULT ret;
    mdi_video_clip_prepare_struct setting;

    m_processingPopup->setPos(getBounds().getMidX(), getBounds().getMidY());
    m_processingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVING));
    m_processingPopup->setProgress(0);
    m_processingPopup->show(VFX_FALSE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CLIP_OPEN, m_state);
//    m_video->closeFile();

    #ifdef __MTK_TARGET__    
    ret = mdi_video_clip_open(m_appID);

    if (ret == MDI_RES_VDOCLIP_SUCCEED)
    {
        setting.src_filepath = (WCHAR*)m_srcFilePath.getBuf();
        setting.dst_filepath = (WCHAR*)m_dstFilePath.getBuf();
        setting.start_time = (VfxU32)m_startTime;
        setting.end_time = (VfxU32)m_endTime;
            
        ret = mdi_video_clip_prepare(&setting, clipPrepareCB, (void*)this);
        if (ret == MDI_RES_VDOCLIP_SUCCEED)
        {
            m_processingTimer->start();
            enterState(STATE_CLIP_PREPARING, __LINE__);
        }
    }

    if (ret != MDI_RES_VDOCLIP_SUCCEED)
    {
        VfxU16 stringID;
        mmi_event_notify_enum popup_type;

        stringID = mdi_video_clip_get_error_info(ret, &popup_type);
        displayErrorPopup(stringID);
        
    }
    
    #else
    m_processingTimer->start();
    m_state = STATE_CLIP_CLIPPING;    
    #endif
}


void VcuiVideoClipperPage::clipVideoStart()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CLIP_START, m_state);
    mdi_video_clip_start(clipResultCB, (void*)this);
    enterState(STATE_CLIP_CLIPPING, __LINE__);
}


void VcuiVideoClipperPage::clipVideoStop()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CLIP_STOP, m_state);
    mdi_video_clip_stop();
    enterState(STATE_PLAY_READY, __LINE__);
}


void VcuiVideoClipperPage::clipVideoClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CLIP_CLOSE, m_state);
    mdi_video_clip_close();
}


VappVideoMsec VcuiVideoClipperPage::getVideoTime(VfxFloat normalizedValue)
{
    VappVideoMsec time;
    time = normalizedValue * m_totalTime;

    return time;
}
    

void VcuiVideoClipperPage::getFilePathAndRelatedInfo(VfxWString& inputFilePath, VfxWString& outFileFolder, VfxWString& outFileName, VfxWString& outExtName)
{
    const WCHAR *filename_ptr = srv_fmgr_path_get_filename_const_ptr(inputFilePath.getBuf());
    const WCHAR *ext_ptr = srv_fmgr_path_get_extension_const_ptr(inputFilePath.getBuf());

    outExtName.loadFromMem(ext_ptr);
    
    VfxWChar *temp_buf;
    
    VFX_ALLOC_MEM(temp_buf, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1)*sizeof(VfxWChar), this);
    kal_wstrncpy(temp_buf, filename_ptr, (ext_ptr-filename_ptr)-1);  
    outFileName.loadFromMem(temp_buf);
    VFX_FREE_MEM(temp_buf);

    VFX_ALLOC_MEM(temp_buf, (SRV_FMGR_PATH_MAX_LEN+1)*sizeof(VfxWChar), this);
    kal_wstrncpy(temp_buf, m_setting.filepath, filename_ptr - inputFilePath.getBuf()); 
    outFileFolder.loadFromMem(temp_buf);
    VFX_FREE_MEM(temp_buf);
}


VfxWString VcuiVideoClipperPage::getDstFilePath(VfxWString& srcFolderPath,  VfxWString& srcFileName, VfxWString& extName)
{
#define MAX_CHECK_DURATION (1000)

    VfxWString dstFilePath;
    VfxWString newAppendix(VFX_WSTR("_new"));

    FS_HANDLE file_handle;

    dstFilePath = srcFolderPath;
    dstFilePath += srcFileName;
    dstFilePath += newAppendix;
    dstFilePath += VFX_WSTR(".");
    dstFilePath += extName;
    dstFilePath += VFX_WSTR("\0");

    file_handle = FS_GetAttributes((WCHAR*)dstFilePath.getBuf());
    if (file_handle < 0)
    {
        return dstFilePath;
    }
    else
    {
        VfxU32 i = 2;
        VfxWString num;
        VfxBool isFind = VFX_FALSE;
        kal_uint32 start_time = 0;
        kal_uint32 current_time = 0;
        kal_uint32 elapse_time = 0;

        kal_get_time(&start_time);
        do{
            num.format("%02d", i);

            dstFilePath = srcFolderPath;
            dstFilePath += srcFileName;
            dstFilePath += newAppendix;
            dstFilePath += num;
            dstFilePath += VFX_WSTR(".");
            dstFilePath += extName;

            file_handle = FS_GetAttributes((WCHAR*)dstFilePath.getBuf());
            if (file_handle < 0)
            {
                isFind = VFX_TRUE;
                break;
            }

            kal_get_time(&current_time);
            if (current_time >= start_time)
            {
                elapse_time = current_time - start_time;
            }
            else
            {
                /* wrap around case */
                elapse_time = current_time - (0xFFFFFFFF - 1 - start_time);
            }
    
            i++;
          }while(elapse_time < MAX_CHECK_DURATION);

        if (isFind)
            return dstFilePath;
        else
            return VFX_WSTR_NULL;
    }
    
}


void VcuiVideoClipperPage::playControlButtonClickHdlr(VfxObject* sender, VfxId id)
{
    if (m_state == STATE_PLAY_READY)
    {
        if (m_playTime == m_endTime || m_isResought)
        {
            if (m_playTime == m_endTime)
            {
                m_playTime = m_startTime;

                VfxFloat barPos = m_playTime / (VfxFloat)m_totalTime;
                m_slider->setPlayThumbAutoAnimate(VFX_FALSE);
                m_slider->setPlayThumbValue(barPos);        
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);
            }
            playVideo(m_playTime);
        }
        else
            playVideo();
    }
}


void VcuiVideoClipperPage::pauseControlButtonClickHdlr(VfxObject* sender, VfxId id)
{
    if (m_state == STATE_PLAY_PLAYING)
    {
        pauseVideo();
    }
}


void VcuiVideoClipperPage::clipButtonClickHdlr(VfxObject* sender, VfxId id)
{
    pauseVideo();
    m_isWaitClip = VFX_FALSE;

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VFX_OBJ_CREATE(m_popupMenu, VcpMenuPopup, this);

    m_popupMenu->setTitle(m_fileName);
    m_popupMenu->addItem(OPTION_SAVE_ORIGINAL, VFX_WSTR_RES(STR_ID_VAPP_VDOCLIPPER_SAVE_ORIGINAL));
    m_popupMenu->addItem(OPTION_SAVE_NEW, VFX_WSTR_RES(STR_ID_VAPP_VDOCLIPPER_SAVE_NEW));
    m_popupMenu->addItem(OPTION_CLOSE, VFX_WSTR_RES(STR_GLOBAL_CLOSE));
    m_popupMenu->setAutoDestory(VFX_TRUE);
    m_popupMenu->show(VFX_TRUE);

    m_popupMenu->m_signalMenuCallback.connect(this, &VcuiVideoClipperPage::onSaveMenuButtonClicked);
}


void VcuiVideoClipperPage::getTimeText(VfxWString &timeText, U64 timeMsec, VfxBool hideHourIfZero)
{
    const VfxU32 seconds = (VfxU32)msecToSec(timeMsec);
    const VfxU32 minutes = seconds / 60;
    const VfxU32 hours = minutes / 60;
    const VfxU32 sec_part = seconds % 60;
    const VfxU32 min_part = minutes % 60;
    const VfxU32 hour_part = vfxMin((VfxU32)99, hours); // clamp at 99 hours
    if(hideHourIfZero && 0 == hours)
    {
        timeText.format("%02d:%02d", min_part, sec_part);
    }
    else
    {
        timeText.format("%d:%02d:%02d", hour_part, min_part, sec_part);
    }
}


void VcuiVideoClipperPage::setTimeText(VfxTextFrame *text, VappVideoMsec time, VfxBool forceHourDigit)
{
    VfxWString strTime;
    // Hide HH in HH:MM:SS if less than 1 hour.
    getTimeText(strTime, time, !forceHourDigit);
    text->setString(strTime);
}


void VcuiVideoClipperPage::drawPlayIcon()
{
    m_playControlButton->setHidden(VFX_FALSE);
    m_pauseControlButton->setHidden(VFX_TRUE);
}


void VcuiVideoClipperPage::drawPauseIcon()
{
    m_playControlButton->setHidden(VFX_TRUE);
    m_pauseControlButton->setHidden(VFX_FALSE);
}


void VcuiVideoClipperPage::onPlayTimerTick(VfxTimer *source)
{
    if (source->isValid())
    {   
        m_video->getCurrentTime(m_playTime);
        
        VfxFloat barPos = m_playTime / (VfxFloat)m_totalTime;
        m_slider->setPlayThumbAutoAnimate(VFX_TRUE);
        m_slider->setPlayThumbValue(barPos);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);

        
        if (m_playTime >= m_endTime)
        {
            pauseVideo();
            m_playTime = m_endTime;
            m_slider->setPlayThumbAutoAnimate(VFX_TRUE);
            m_slider->setPlayThumbValue(m_slider->getEndThumbValue());
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_CHANGE_PLAYTIME, m_playTime, __LINE__);
            m_playTimer->stop();
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_UPDATE_PLAYTIME, m_playTime);
    }
}


void VcuiVideoClipperPage::onProcessingTimerTick(VfxTimer *source)
{
    VfxU32 ratio;
    VfxFloat progress;

    if (m_state != STATE_CLIP_CLIPPING)
        return;
    
#ifdef __MTK_TARGET__
    ratio = mdi_video_clip_get_processing_ratio();
    progress = (VfxFloat)ratio/(VfxFloat)100;
    m_processingPopup->setIsAnimate(VFX_FALSE);
    m_processingPopup->pauseProgress();
    m_processingPopup->setProgress(progress);
#else
    progress = m_processingPopup->getProgress();
    progress += 0.1;
    if (progress >= 1)
    {
        m_processingPopup->setProgress(1.0);
        m_processingTimer->stop();
    }
    else
        m_processingPopup->setProgress(progress);
#endif
}


void VcuiVideoClipperPage::onSaveMenuButtonClicked(VcpMenuPopup* pMenu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    if (!pMenu->isValid())
        return;

    if (event != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
        return;

    VfxWString folderPath;
    VfxWString fileName;
    VfxWString extName;
        
    if (item->getId() == OPTION_SAVE_ORIGINAL)
    {
//        m_dstFilePath = m_srcFilePath;
        m_isDeleteSrc = VFX_TRUE;

        getFilePathAndRelatedInfo(m_srcFilePath,folderPath, fileName, extName);

        VfxWString temp(VFX_WSTR("(Temp)"));
        
        fileName += temp;

        m_dstFilePath = folderPath;
        m_dstFilePath += fileName;
        m_dstFilePath += VFX_WSTR(".");
        m_dstFilePath += extName;
        m_dstFilePath += VFX_WSTR("\0");
        
        clipVideoOpen();
    }
    else if (item->getId() == OPTION_SAVE_NEW)
    {        
        /* get dst file path and file name */
        getFilePathAndRelatedInfo(m_srcFilePath,folderPath, fileName, extName);
        m_dstFilePath = getDstFilePath(folderPath, fileName, extName);

        VfxU32 length = m_dstFilePath.getLength();
        
        if (length < SRV_FMGR_PATH_MAX_LEN)
        {
            getFilePathAndRelatedInfo(m_dstFilePath,folderPath, fileName, extName);
        }
        else
        {
            getFilePathAndRelatedInfo(m_srcFilePath,folderPath, fileName, extName);
        }
        
        VFX_OBJ_CREATE(m_rename_popup, VappFileNameEditorPopup, this);
        m_rename_popup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_VDOCLIPPER_SAVE_NEW_TITLE));

        /* Get filename without extension */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
        m_rename_popup->setText(fileName, (SRV_FMGR_PATH_MAX_LEN - folderPath.getLength()- extName.getLength() - 1), VFX_FALSE);
    #endif


        /* Set file extension */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
        m_rename_popup->setExt((VfxS8*)extName.getBuf()); 
    #endif

        /* Set highlight for whole text */
        m_rename_popup->getInputbox()->setHighlight(0, m_rename_popup->getText().getLength());

        m_rename_popup->setIME(IMM_INPUT_TYPE_SENTENCE);
        m_rename_popup->m_signalButtonClicked.connect(this, &VcuiVideoClipperPage::onRenameFileClicked);
    
        m_rename_popup->show(VFX_TRUE);
    }
        
}


void VcuiVideoClipperPage::onRenameFileClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_CANCEL:
            VFX_OBJ_CLOSE(m_rename_popup);
            break;
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxWString folderPath;
            VfxWString fileName;
            VfxWString extName;
            VfxWString newFileName;
            FS_HANDLE file_handle;
            
            getFilePathAndRelatedInfo(m_srcFilePath,folderPath, fileName, extName);

            newFileName = m_rename_popup->getText();
            
            m_dstFilePath = folderPath;
            m_dstFilePath += newFileName;
            m_dstFilePath += VFX_WSTR(".");
            m_dstFilePath += extName;

            VfxS32 fs_ret = m_rename_popup->isValidFilePath();
            
            if (fs_ret >= FS_NO_ERROR)
            {
                file_handle = FS_GetAttributes((WCHAR*)m_dstFilePath.getBuf());
                if (file_handle < 0)
                {
                    VFX_OBJ_CLOSE(m_rename_popup);
                    clipVideoOpen();
                }
                else
                {
                    m_rename_popup->setErrorText(VFX_WSTR_RES(STR_GLOBAL_FILENAME_ALREADY_EXISTS));
                }    
            }
            else
            {
                m_rename_popup->setErrorText(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(fs_ret)));
            }
            break;
        }
            
        default:
            break;
    }
}

void VcuiVideoClipperPage::onProcessingCancel(VfxObject* obj, VfxFloat processing)
{
    clipVideoStop();
    clipVideoClose();
        
    m_processingPopup->hide(VFX_FALSE);
}


mmi_ret VcuiVideoClipperPage::cbEventHandler(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
            if (m_state == STATE_IDLE ||
                m_state == STATE_PLAY_READY)
            {
                return MMI_RET_OK;
            }
            else
                return !MMI_RET_OK;
            break;
        default:
            break;
    }    
    
    return MMI_RET_OK;
}


void VcuiVideoClipperPage::onProgressBarFinish()
{
    vcui_videoclipper_result_event_struct evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, m_result, m_appID);
    evt.result = m_result;
    kal_wstrncpy(evt.filepath, m_dstFilePath.getBuf(), SRV_FMGR_PATH_MAX_LEN); 
        
    VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    app->postToCaller((mmi_group_event_struct*)&evt);
}


void VcuiVideoClipperPage::enterState(VfxU8 state, VfxU32 line)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_ENTERSTATE, m_state, state, line);
    m_state = (VfxU8)state;
}


void VcuiVideoClipperPage::displayErrorPopup(VfxU16 stringID)
{
    m_processingPopup->hide(VFX_FALSE);

    m_result = VCUI_VIDEOCLIPPER_EVENT_RESULT_FAILED;
    m_processingPopup->hide(VFX_FALSE);

    VcpConfirmPopup* popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->m_signalButtonClicked.connect(this, &VcuiVideoClipperPage::onPopupButtonClicked);
    popup->setAutoDestory(VFX_TRUE);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    popup->setText(VFX_WSTR_RES(stringID));
//        popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    popup->show(VFX_TRUE);
}


void VcuiVideoClipperPage::onPopupButtonClicked(VfxObject* obj, VfxId id)
{
    onProgressBarFinish();
}

extern "C" MMI_BOOL vcui_videoclipper_is_available(const mdi_video_info_struct* video_info_p)
{
    if (video_info_p->is_proprietary == MMI_TRUE && video_info_p->total_time_duration > 1000)
    {
        return MMI_TRUE;
    }
    else
        return MMI_FALSE;
}

extern "C" mmi_id vcui_videoclipper_create(mmi_id parent_id, vcui_videoclipper_param_struct *param)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_VIDEOCLIPPER,
                                        VFX_OBJ_CLASS_INFO(VcuiVideoClipperCui),
                                        parent_id,
                                        param,
                                        sizeof(vcui_videoclipper_param_struct));
    return cui_id;
}

extern "C" void vcui_videoclipper_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

extern "C" void vcui_videoclipper_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

#endif /* __MMI_VIDEO_CLIPPER__ */
