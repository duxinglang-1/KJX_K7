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
 *  vapp_bootup_ani.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Bootup animation of Venus MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "gpiosrvgprot.h"     /* srv_backlight_turn_on */
#include "ProfilesSrvGprot.h" /* srv_prof_play_tone */
}

#include "mmi_rp_vapp_bootup_def.h"
#include "mmi_rp_vapp_setting_def.h"

#include "vfx_weak_ptr.h"
#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#include "vapp_ani_page_gprot.h"

#include "vapp_wallpaper_setting_method_gprot.h"
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
    VfxBool ani_completed;
	VappAniPage *aniPage;
} vapp_bootup_ani_cntx_struct;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static vapp_bootup_ani_cntx_struct g_vapp_bootup_ani_cntx;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static mmi_ret vapp_bootup_on_ani_completed(mmi_event_struct *evt);


/***************************************************************************** 
 * VappAniPage
 *****************************************************************************/
void VappBootupApp::onScr1stReady(VfxMainScrEx *scr)
{
	//
	// We can't create ani page before the first main screen is created, if the ani page has used video frame,
	// so it need to be showed after main screen is created.
	if (scr->getPageCount() == 0 && !srv_bootup_is_exception_mode())
	{
		createAniPage();
	}
}

VappAniPage *VappBootupApp::createAniPage(void)
{
	VappAniPage *aniPage;

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
	
	VappWallpaperSettingInterface *wallpaper = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);

	VappWpResType res = wallpaper->getWallpaperResType(VAPP_VIDEO_PWR_ON_SCREEN);
	switch (res)
	{
		case VAPP_WALLPAPER_VIDEO_WALLPAPER:
			if (wallpaper->getVideoResId(VAPP_VIDEO_PWR_ON_SCREEN) == VDO_ID_SYS_INVALID_VID)
			{
				VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
				aniPage->m_signalSetAniDone.connect(this, &VappBootupApp::onSetAniComplete);
				aniPage->setAnimation(IMG_ID_VAPP_BOOTUP_ANIMATION);
				playAniTone();
			}
			else
			{
				VFX_OBJ_CREATE_EX(aniPage, VappAniVideoPage, m_mainScr, (isPlayTone()));
				aniPage->m_signalSetAniDone.connect(this, &VappBootupApp::onSetAniComplete);
				aniPage->setAnimation(wallpaper->getVideoResId(VAPP_VIDEO_PWR_ON_SCREEN));
			}
			
			break;

		case VAPP_WALLPAPER_USER_FILE:
			if (wallpaper->checkWallpaper(VAPP_VIDEO_PWR_ON_SCREEN) != VAPP_WALLPAPER_SETTING_NO_ERROR)
			{
				wallpaper->restoreWallpaper(VAPP_VIDEO_PWR_ON_SCREEN);

				VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
				aniPage->m_signalSetAniDone.connect(this, &VappBootupApp::onSetAniComplete);
				aniPage->setAnimation(IMG_ID_VAPP_BOOTUP_ANIMATION);
				playAniTone();
			}
			else
			{
				VFX_OBJ_CREATE_EX(aniPage, VappAniVideoPage, m_mainScr, (isPlayTone()));
				aniPage->m_signalSetAniDone.connect(this, &VappBootupApp::onSetAniComplete);
				aniPage->setAnimation(wallpaper->getWallpaperFile(VAPP_VIDEO_PWR_ON_SCREEN));
			}

			break;
			
		default:
		{
			VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
			aniPage->m_signalSetAniDone.connect(this, &VappBootupApp::onSetAniComplete);
			aniPage->setAnimation(IMG_ID_VAPP_BOOTUP_ANIMATION);
			playAniTone();
		}
			break;
			
	}
	
#else /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */

	VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
	aniPage->m_signalSetAniDone.connect(this, &VappBootupApp::onSetAniComplete);
	aniPage->setAnimation(IMG_ID_VAPP_BOOTUP_ANIMATION);
	playAniTone();
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */

	g_vapp_bootup_ani_cntx.aniPage = aniPage;
	
    aniPage->setAllowDelete(VFX_FALSE);
	aniPage->m_signalPlayCompleted.connect(this, &VappBootupApp::onAniPlayCompleted);

	m_mainScr->pushPage(PAGE_ANIMATION, aniPage);
	
	return aniPage;
}

void VappBootupApp::onSetAniComplete(VappAniPage *obj, VfxS32 result)
{
	if (result == MDI_RES_VDOPLY_SUCCEED)
	{
	    if (!obj->play())
	    {
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
			VappWallpaperSettingInterface *wallpaper = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
			wallpaper->restoreWallpaper(VAPP_VIDEO_PWR_ON_SCREEN);
#endif
	    }
	}
	else
	{
		m_mainScr->closePage(PAGE_ANIMATION);
		//VFX_OBJ_CLOSE(obj);
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
		VappWallpaperSettingInterface *wallpaper = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
		wallpaper->restoreWallpaper(VAPP_VIDEO_PWR_ON_SCREEN);
#endif
		// reset action should before createAniPage.
		m_mainScr->pushPage(PAGE_ANIMATION, createAniPage());
	}
}

VfxBool VappBootupApp::isPlayTone(void)
{
	// if (mute) { don't allow vVframe to play tone}, volume
	// bootup can entry idle althoudh the tone hasn't been finished.
#ifndef __MMI_POWER_ON_OFF_MUTE__
	MMI_BOOL value;

	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_OFF_TONE, (void *)&value);
	MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_PLAY_TONE, value);
	
	return value ? VFX_TRUE : VFX_FALSE;
#else

	return VFX_FALSE;

#endif /* __MMI_POWER_ON_OFF_MUTE__ */
}

void VappBootupApp::playAniTone(void)
{	// if (mute) { don't allow vVframe to play tone}, volume
	// bootup can entry idle althoudh the tone hasn't been finished.

	if (isPlayTone())
	{
		srv_prof_play_tone(SRV_PROF_TONE_POWER_ON, NULL);
	}
}

void VappBootupApp::playAnimation(mmi_proc_func proc, void *userData)
{
    m_callbackProc = proc;
    m_callbackUserData = userData;

	if (m_mainScr->isShown())
	{
		createAniPage();
	}
	else
	{
		showMainScr();
	}	

	closeWaiting();
}

void VappBootupApp::onAniPlayCompleted(VappAniPage *aniPage)
{
    if (m_callbackProc != NULL)
    {
        mmi_proc_func proc = m_callbackProc;
        void *user_data = m_callbackUserData;
        m_callbackProc = NULL;

        animation_completed_evt_struct completed_evt;
        MMI_FRM_INIT_EVENT(&completed_evt, EVT_ID_ANIMATION_COMPLETED);
        MMI_FRM_SEND_EVENT(&completed_evt, proc, user_data);
    }
}


mmi_frm_proc_result_enum vapp_bootup_play_animation(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    vapp_bootup_ani_cntx_struct *cntx = &g_vapp_bootup_ani_cntx;
    VappBootupApp *app = VappBootupApp::getApp();

    if (srv_bootup_is_exception_mode())
    {
        cntx->ani_completed = VFX_TRUE;
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_PLAY_ANIMATION);

    cntx->id_info = id_info;
    cntx->ani_completed = VFX_FALSE;
    app->playAnimation(vapp_bootup_on_ani_completed, cntx);

    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


static mmi_ret vapp_bootup_on_ani_completed(mmi_event_struct *evt)
{
    vapp_bootup_ani_cntx_struct *cntx;

    srv_backlight_turn_off();

    cntx = reinterpret_cast<vapp_bootup_ani_cntx_struct*>(evt->user_data);
    cntx->ani_completed = VFX_TRUE;
    mmi_frm_proc_notify_completed(cntx->id_info);

    return MMI_RET_OK;
}


mmi_frm_proc_ctrl_enum vapp_bootup_ani_on_proc_status_changed(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status)
{
    vapp_bootup_ani_cntx_struct *cntx = &g_vapp_bootup_ani_cntx;

	// Only animation isn't finished
	if (!cntx->ani_completed &&
		((set_status->n_completed + 1) == set_status->n_total_procs))
	{
		if (VappBootupApp::getApp() != NULL)
		{
			VappAniPage *aniPage = cntx->aniPage;
			if (aniPage != NULL)
			{
				aniPage->setCanComplete(VFX_TRUE);
			}
		}
	}
	
    if (cntx->ani_completed &&
        set_status->n_completed < set_status->n_total_procs)
    {
    	// Waiting for protocol(SIM) ready, show a waiting indicator first
    	//Wen, replay the animation may be not good behavior
        VappBootupApp::getApp()->showWaiting(STR_ID_VAPP_BOOTUP_WAIT_FOR_SIM);
    }

    return MMI_FRM_PROC_CTRL_CONTINUE;
}
#pragma arm section code, rodata
