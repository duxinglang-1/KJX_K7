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
 *  vapp_shutdown_app.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Showdown application of Venus MMI
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

extern "C"
{
#include "gpiosrvgprot.h"     /* srv_backlight_turn_on */
#include "ProfilesSrvGprot.h" /* srv_prof_play_tone */
#include "NotificationGprot.h"
}

#ifdef __LOW_COST_SUPPORT_COMMON__
#include "mmi_rp_vapp_bootup_def.h"
#endif

#include "mmi_rp_vapp_shutdown_def.h"
#include "mmi_rp_vapp_setting_def.h"

#include "vapp_platform_context.h"
#include "vapp_wallpaper_setting_method_gprot.h"

#include "vapp_shutdown.h"
#include "vapp_ani_page_gprot.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
} vapp_shutdown_ani_cntx_struct;

static vapp_shutdown_ani_cntx_struct g_vapp_shutdown_ani_cntx;

static mmi_ret vapp_shutdown_on_animation_completed(mmi_event_struct *evt);

/***************************************************************************** 
 * Class VappShutdownApp 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShutdownApp", VappShutdownApp, VfxApp);

VappAniPage *VappShutdownApp::ceateAniPage(void)
{
	VappAniPage *aniPage;
	
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
	VappWallpaperSettingInterface *wallpaper = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);


	VappWpResType res = wallpaper->getWallpaperResType(VAPP_VIDEO_PWR_OFF_SCREEN);
	switch (res)
	{
		case VAPP_WALLPAPER_VIDEO_WALLPAPER:
			if (wallpaper->getVideoResId(VAPP_VIDEO_PWR_OFF_SCREEN) == VDO_ID_SYS_INVALID_VID)
			{
				VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
				aniPage->m_signalSetAniDone.connect(this, &VappShutdownApp::onSetAniComplete);
				aniPage->setAnimation(getDefaultAni());
				playTone(aniPage);
			}
			else
			{
				VFX_OBJ_CREATE_EX(aniPage, VappAniVideoPage, m_mainScr, (isPlayTone()));
				aniPage->m_signalSetAniDone.connect(this, &VappShutdownApp::onSetAniComplete);
				aniPage->setAnimation(wallpaper->getVideoResId(VAPP_VIDEO_PWR_OFF_SCREEN));
			}
			
			break;

		case VAPP_WALLPAPER_USER_FILE:
			if (wallpaper->checkWallpaper(VAPP_VIDEO_PWR_OFF_SCREEN) != VAPP_WALLPAPER_SETTING_NO_ERROR)
			{
				wallpaper->restoreWallpaper(VAPP_VIDEO_PWR_OFF_SCREEN);

				VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
				aniPage->m_signalSetAniDone.connect(this, &VappShutdownApp::onSetAniComplete);
				aniPage->setAnimation(getDefaultAni());
				playTone(aniPage);
			}
			else
			{
				VFX_OBJ_CREATE_EX(aniPage, VappAniVideoPage, m_mainScr, (isPlayTone()));
				aniPage->m_signalSetAniDone.connect(this, &VappShutdownApp::onSetAniComplete);
				aniPage->setAnimation(wallpaper->getWallpaperFile(VAPP_VIDEO_PWR_OFF_SCREEN));
			}

			break;
			
		default:
			VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
			aniPage->m_signalSetAniDone.connect(this, &VappShutdownApp::onSetAniComplete);
			aniPage->setAnimation(getDefaultAni());
			playTone(aniPage);


			break;
	}
	
#else /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */

	VFX_OBJ_CREATE(aniPage, VappAniPage, m_mainScr);
	aniPage->m_signalSetAniDone.connect(this, &VappShutdownApp::onSetAniComplete);
	aniPage->setAnimation(getDefaultAni());

	playTone(aniPage);
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */

    aniPage->setAllowDelete(VFX_FALSE);
	aniPage->m_signalPlayCompleted.connect(this, &VappShutdownApp::onAniPlayCompleted);
	m_mainScr->pushPage(PAGE_ANIMATION, aniPage);

	return aniPage;
}


VfxResId VappShutdownApp::getDefaultAni(void)
{
#ifdef __LOW_COST_SUPPORT_COMMON__
	return IMG_ID_VAPP_BOOTUP_ANIMATION;
#else
	return IMG_ID_VAPP_SHUTDOWN_ANIMATION;
#endif
}


void VappShutdownApp::onSetAniComplete(VappAniPage *obj, VfxS32 result)
{
	if (result == MDI_RES_VDOPLY_SUCCEED)
	{
	    if (!obj->play())
	    {
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
			VappWallpaperSettingInterface *wallpaper = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
			wallpaper->restoreWallpaper(VAPP_VIDEO_PWR_OFF_SCREEN);
#endif
	    }
	}
	else
	{
		m_mainScr->closePage(PAGE_ANIMATION);
		//VFX_OBJ_CLOSE(obj);
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
		VappWallpaperSettingInterface *wallpaper = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
		wallpaper->restoreWallpaper(VAPP_VIDEO_PWR_OFF_SCREEN);
#endif
		// reset action should before createAniPage.
		m_mainScr->pushPage(PAGE_ANIMATION, ceateAniPage());
	}
}


void VappShutdownApp::onInit()
{
    VfxApp::onInit();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VFX_OBJ_CREATE(m_mainScr, VfxMainScr, this);
//    m_mainScr->setAllowDelete(VFX_FALSE);
}

void VappShutdownApp::onRun(void * args,VfxU32 argSize)
{
	playAnimation(vapp_shutdown_on_animation_completed, &g_vapp_shutdown_ani_cntx);
}

VfxAppCloseAnswerEnum VappShutdownApp::onProcessClose(VfxAppCloseOption option)
{
    return VFX_APP_CLOSE_ANSWER_NO;
}

VfxBool VappShutdownApp::isPlayTone(void)
{
#ifndef __MMI_POWER_ON_OFF_MUTE__
	MMI_BOOL value;

	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_OFF_TONE, (void *)&value);
	
	return (value ? VFX_TRUE : VFX_FALSE);
	
#else

	return VFX_FALSE;

#endif /* __MMI_POWER_ON_OFF_MUTE__ */
}


void VappShutdownApp::playTone(VappAniPage *aniPage)
{
	if (isPlayTone())
	{
		aniPage->setTone(SRV_PROF_TONE_POWER_OFF);
	}
}

void VappShutdownApp::playAnimation(mmi_proc_func proc, void *userData)
{
    m_callbackProc = proc;
    m_callbackUserData = userData;

	VappAniPage *aniPage = ceateAniPage();
	showMainScr();
}

void VappShutdownApp::onAniPlayCompleted(VappAniPage *aniPage)
{
    if (m_callbackProc != NULL)
    {
        mmi_proc_func proc = m_callbackProc;
        void *user_data = m_callbackUserData;
        m_callbackProc = NULL;

        ani_completed_evt_struct completed_evt;
        MMI_FRM_INIT_EVENT(&completed_evt, EVT_ID_ANI_COMPLETED);
        MMI_FRM_SEND_EVENT(&completed_evt, proc, user_data);
    }
}

mmi_frm_proc_result_enum vapp_shutdown_play_animation(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    VfxContext *platformCntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
	VfxAppLauncher::launchWithCtx(
        VAPP_SHUTDOWN,
        VFX_OBJ_CLASS_INFO(VappShutdownApp),
        GRP_ID_ROOT,
        platformCntx);

    g_vapp_shutdown_ani_cntx.id_info = id_info;
	
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;   
}


static mmi_ret vapp_shutdown_on_animation_completed(mmi_event_struct *evt)
{
    vapp_shutdown_ani_cntx_struct *cntx =
        static_cast<vapp_shutdown_ani_cntx_struct*>(evt->user_data);

    srv_backlight_turn_off();
	mmi_frm_nmgr_disable_notification();
	
    mmi_frm_proc_notify_completed(cntx->id_info);

    return MMI_RET_OK;
}
