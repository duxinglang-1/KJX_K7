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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_ani_page.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Animation page
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "GlobalResDef.h"

extern "C"
{
#include "Gpiosrvgprot.h" /* EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN */
#include "gui.h"
}
#include "FileMgrSrvGprot.h"
#include "mmi_rp_vapp_bootup_def.h"

#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_page_transition.h"

#include "vapp_video_player_cp.h"
#include "vapp_ani_page_gprot.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef  void (*GuiTimerCallback0FuncType)(void);

/***************************************************************************** 
 * Class VappAniPage
 *****************************************************************************/
VappAniPage *VappAniPage::s_activeAni = NULL;

void VappAniPage::onInit()
{
    VfxPage::onInit();

    setStatusBar(VFX_FALSE);

    VfxSize pageSize = getSize();

    VFX_OBJ_CREATE(m_aniFrame, VfxAnimImageFrame, this);
    

    setBgColor(VFX_COLOR_BLACK);

	// [MAUI_02452183]
	// If backlight off, the animation will be suspended so that the playing time
	// out of the expectation. We don't allow backlight off when animation is
	// playing.
	mmi_frm_cb_reg_event(
		EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN,
		&VappAniPage::onBacklightGoingToBeOff,
		getObjHandle());

}


void VappAniPage::onDeinit()
{

    mmi_frm_cb_dereg_event(
    	EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN,
        &VappAniPage::onBacklightGoingToBeOff,
        getObjHandle());

    VfxPage::onDeinit();
}


void VappAniPage::setAnimation(const VfxResId &aniResId)
{
    VfxSize pageSize = getSize();

    m_aniFrame->setImgContent(VfxImageSrc(aniResId));
    m_aniFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_aniFrame->setAnchor(0.5, 0.5);
    m_aniFrame->setSize(pageSize);
    m_aniFrame->setPos(pageSize.width / 2, pageSize.height / 2);

	m_signalSetAniDone.postEmit(this, 0);
}


VfxBool VappAniPage::play()
{
    if (m_waitingJobs != 0)
    {
        // Already playing
        return VFX_FALSE;
    }

    if (m_toneType != SRV_PROF_TONE_NONE)
    {
        if (s_activeAni != NULL &&
            s_activeAni->m_toneType != SRV_PROF_TONE_NONE)
        {
            if ((s_activeAni->m_waitingJobs & JOB_AUDIO) != 0) // playing tone
            {
                srv_prof_stop_tone(s_activeAni->m_toneType);
                s_activeAni->notifyCompletion(JOB_AUDIO);
            }
        }
    
        if (srv_prof_play_tone(
                m_toneType,
                &VappAniPage::onAudioPlayCompleted) == SRV_PROF_RET_SUCCESS)
        {
            m_waitingJobs |= JOB_AUDIO;
        }
    }

    s_activeAni = this;

    // If in background, we don't play animation.
    // Even we call the playImgContent(), the Venus framework will still not play
	if (isActive())
    {
    	m_waitingJobs |= JOB_ANIMATION;
	    //m_aniFrame->playImgContent(1, VfxCallback0(this, &VappAniPage::onAniCompleted));
	    m_aniFrame->m_signalEnd.connect(this, &VappAniPage::onAniCompleted);
        m_aniFrame->setRepeatCount(1);
        m_aniFrame->play();
	}

	if (m_waitingJobs == 0)
	{
	    // Nothing to be waited for
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, 0);
	    MMI_FRM_POST_EVENT(&evt, &VappAniPage::invokeSignalPlayCompleted, this);
	}

	return VFX_TRUE;
}


// [MAUI_02947404]
// m_signalPlayCompleted will trigger bootup procedure to launch idle
// but framework does not support screen insertion well on screen exit,
// so that the idle screen may be inserted onto the shutdown animation.
// So we post the completed event here.
// In addition, we should not invoke m_signalPlayCompleted.postEmit()
// because postEmit() only posts in Venus internal, will not be out of
// pluto screen handling.
mmi_ret VappAniPage::invokeSignalPlayCompleted(mmi_event_struct *evt)
{
    VappAniPage *aniPage = (VappAniPage *)handleToObject((VfxObjHandle)evt->user_data);

	if (aniPage != NULL)
	{
    	aniPage->m_signalPlayCompleted.emit(aniPage);
	}
	
    return MMI_RET_OK;
}


void VappAniPage::onAniCompleted(VfxObject *anim)
{
    notifyCompletion(JOB_ANIMATION);
}


void VappAniPage::onExit(VfxBool isBackward)
{
	// [Framework limitation]
	// If page exits(e.g. interrupted by call), the animation component will no
	// longer callback. So we set the state to be "already completed".
	notifyCompletion(JOB_ANIMATION);
}


srv_prof_ret VappAniPage::onAudioPlayCompleted(srv_prof_ret result)
{
    if (s_activeAni != NULL)
    {
        s_activeAni->notifyCompletion(JOB_AUDIO);
    }

    return SRV_PROF_RET_SUCCESS;
}


void VappAniPage::notifyCompletion(JobEnum newlyCompletedJob)
{
    if ((m_waitingJobs & newlyCompletedJob) != 0)
    {
        m_waitingJobs &= ~newlyCompletedJob;

        if (newlyCompletedJob == JOB_ANIMATION)
        {
            mmi_frm_cb_dereg_event(
            	EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN,
	            &VappAniPage::onBacklightGoingToBeOff,
	            getObjHandle());
        }
        
        if (m_waitingJobs == 0)
        {
            if (s_activeAni == this)
            {
                s_activeAni = NULL;
            }
            
    	    mmi_event_struct evt;
    	    MMI_FRM_INIT_EVENT(&evt, 0);
    	    MMI_FRM_POST_EVENT(&evt, &VappAniPage::invokeSignalPlayCompleted, getObjHandle());
        }
    }
}


mmi_ret VappAniPage::onBacklightGoingToBeOff(mmi_event_struct *evt)
{
    VappAniPage *aniPage;

    aniPage = static_cast<VappAniPage*>(VfxObject::handleToObject(
        reinterpret_cast<VfxObjHandle>(evt->user_data)));

    if (aniPage == NULL)
    {
        return MMI_RET_OK;
    }

    if ((aniPage->m_waitingJobs & JOB_ANIMATION) != 0)
    {
        return -1; // Not allow backlight off
    }

    return MMI_RET_OK;
}


VfxBool VappAniPage::onKeyInput(VfxKeyEvent &event)
{
    VfxBool processed;

    processed = VFX_FALSE;
    m_signalKeyInput.emit(this, event, processed);

    if (!processed)
    {
        processed = VfxPage::onKeyInput(event);
    }

    return processed;
}

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
/***************************************************************************** 
 * Class VappAniVideoPage
 *****************************************************************************/
void VappAniVideoPage::onInit()
{
	VappAniPage::onInit();

	VappVideoPlayerPlayOption option;
	
	option.configAsBootVideo();
	option.disableAudio = !m_isAllowTone;
	option.enablePlayDuringCall = VFX_TRUE;

	VFX_OBJ_CREATE_EX(m_vFrame, VappVideoPlayerComponent, this, (option));
	m_vFrame->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
	m_vFrame->m_signalFileOpened.connect(this, &VappAniVideoPage::onVideoOpened);
	m_vFrame->m_signalPlaybackFinished.connect(this, &VappAniVideoPage::onVideoFinished);
}


void VappAniVideoPage::onGuiTimer(void *arg)
{
	VappAniVideoPage *thiz = (VappAniVideoPage *)handleToObject(arg);

	if (thiz != NULL)
	{
		thiz->checkStage();
	}
}

void VappAniVideoPage::checkStage(void)
{
	if (m_vFrame != NULL)
	{
		VfxBool canStop = VFX_FALSE;

		// After MAX_VIDEO_DURATION, video should be closed
		if (m_isChecked)
		{
			canStop = VFX_TRUE;		
		}
		else
		{
			if (m_canComplete)
			{
				canStop = VFX_TRUE;
			}
			else
			{
				gui_start_timer_ex((MAX_VIDEO_DURATION - MAX_VIDEO_DURATION_AFTER_COMPLETE), VappAniVideoPage::onGuiTimer, getObjHandle());
				m_isChecked = VFX_TRUE;
			}
		}
		
		if (canStop)
		{
			// after stop, there won't be any finish signal.
			m_vFrame->stop();

			notifyCompletion(JOB_ANIMATION);
		}
	}
}

void VappAniVideoPage::onExited2()
{
	VFX_OBJ_CLOSE(m_vFrame);
	
	VappAniPage::onExited();
}


void VappAniVideoPage::onExit(VfxBool isBackward)
{
	if (m_vFrame != NULL)
	{
		m_vFrame->pause();
	}
	
	VappAniPage::onExit(isBackward);
}

void VappAniVideoPage::setAnimation(const VfxResId &aniResId)
{
	m_waitingJobs |= JOB_ANIMATION;
	MDI_RESULT result = m_vFrame->openResId(aniResId);
	if (result != MDI_RES_VDOPLY_SUCCEED)
	{
		m_signalSetAniDone.emit(this, (VfxS32)result);
	}
}

void VappAniVideoPage::setAnimation(const VfxWString &path)
{
	m_waitingJobs |= JOB_ANIMATION;
	MDI_RESULT result = m_vFrame->openFile(path);
	if (result != MDI_RES_VDOPLY_SUCCEED)
	{
		m_signalSetAniDone.emit(this, (VfxS32)result);
	}
}

void VappAniVideoPage::setCanComplete(const VfxBool &canComplete)
{
	VappAniPage::setCanComplete(canComplete);
}

VfxBool VappAniVideoPage::play()
{
	s_activeAni = this;
	
	// if play failed, just finish video playing phase
	if (m_vFrame->play() != MDI_RES_VDOPLY_SUCCEED)
	{
		notifyCompletion(JOB_ANIMATION);

		return VFX_FALSE;
	}
	else
	{
		VappVideoMsec videoMsec;

		// If the video duration is more than 7s
		if ((m_vFrame->getTotalDuration(videoMsec) == MDI_RES_VDOPLY_SUCCEED) && (videoMsec > MAX_VIDEO_DURATION_AFTER_COMPLETE))
		{
			gui_start_timer_ex(MAX_VIDEO_DURATION_AFTER_COMPLETE, VappAniVideoPage::onGuiTimer, getObjHandle());
		}		
	}

	return VFX_TRUE;
}


void VappAniVideoPage::onVideoOpened(VappVideoPlayerComponent* obj, MDI_RESULT result)
{
	m_signalSetAniDone.emit(this, (VfxS32)result);
}

void VappAniVideoPage::onVideoFinished(VappVideoPlayerComponent* obj, MDI_RESULT result)
{
	gui_cancel_timer((GuiTimerCallback0FuncType)VappAniVideoPage::onGuiTimer);
	
	notifyCompletion(JOB_ANIMATION);
}

#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */

