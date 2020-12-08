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
 *  vapp_ani_page_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Animation page interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_ANI_PAGE_H__
#define __VAPP_ANI_PAGE_H__

#include "MMIDataType.h"
#include "mdi_datatype.h"

extern "C"
{
#include "ProfilesSrvGprot.h"
}

#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"

/***************************************************************************** 
 * Class VappAniPage
 *****************************************************************************/
class VfxKeyEvent;
class VappAniPage : public VfxPage
{
protected:
    static VappAniPage *s_activeAni;

    srv_prof_tone_enum m_toneType;
    VfxAnimImageFrame *m_aniFrame;
    VfxBool m_canComplete;
	
    enum JobEnum
    {
        JOB_NONE      = 0x0,
        JOB_ANIMATION = 0x1,
        JOB_AUDIO     = 0x2,

        END_OF_JOB_ENUM
    };
    VfxU32 m_waitingJobs;
    
    static srv_prof_ret onAudioPlayCompleted(srv_prof_ret result);
    void notifyCompletion(JobEnum newlyCompletedJob);
    void onAniCompleted(VfxObject *anim);
    static mmi_ret onBacklightGoingToBeOff(mmi_event_struct *evt);
    static mmi_ret invokeSignalPlayCompleted(mmi_event_struct *evt);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onExit(VfxBool isBackward);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

public:
    VfxSignal1<VappAniPage*> m_signalPlayCompleted;
    VfxSignal3<VappAniPage*, const VfxKeyEvent&, VfxBool&> m_signalKeyInput;
	VfxSignal2<VappAniPage *, VfxS32> m_signalSetAniDone;

    VappAniPage() :
        m_toneType(SRV_PROF_TONE_NONE),        
        m_canComplete(VFX_FALSE),
        m_waitingJobs(0)
    {
    }

    // Set the tone to be played with the animation
    // If tone is set, the completed signal will be emitted when both
    // the animation and given tone is completed.
    void setTone(const srv_prof_tone_enum &toneType)
    {
        m_toneType = toneType;
    }
	
	void setCanComplete(const VfxBool &canComplete)
	{
		m_canComplete = canComplete;
	}
	
    virtual void setAnimation(const VfxResId &aniResId);
    virtual void setAnimation(const VfxWString &path){};
    virtual VfxBool play();
};


#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
/***************************************************************************** 
 * Class VappAniVideoPage
 *****************************************************************************/
class VappVideoPlayerComponent;
class VfxTimer;
class VappAniVideoPage : public VappAniPage
{
// Constructor
public:

    VappAniVideoPage(VfxBool isAllowTone = VFX_TRUE) : VappAniPage(), m_vFrame(NULL), m_isAllowTone(isAllowTone), m_isChecked(VFX_FALSE){}
	
// Interface
public:
    void setAnimation(const VfxResId &aniResId); 
	void setAnimation(const VfxWString &path);
	void setCanComplete(const VfxBool &canComplete);
    VfxBool play();
	static void onGuiTimer(void *arg);
	void checkStage(void);
	
// Override
protected:
	void onInit();
	void onExited2();
	void onExit(VfxBool isBackward);

// Implementation
private:
	void onVideoOpened(VappVideoPlayerComponent* obj, MDI_RESULT result);
	void onVideoFinished(VappVideoPlayerComponent* obj, MDI_RESULT result);

private:
	enum
	{
		MAX_VIDEO_DURATION_AFTER_COMPLETE = 7000, // After bootup complete, video will play 7s at most
		MAX_VIDEO_DURATION = 20000 // If bootup can't complete as normal, video will play 20s at most
	};
	
	VappVideoPlayerComponent *m_vFrame;
	VfxBool m_isAllowTone;
	VfxBool m_isChecked;
};

#endif /*  __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */

#endif /* __VAPP_ANI_PAGE_H__ */

