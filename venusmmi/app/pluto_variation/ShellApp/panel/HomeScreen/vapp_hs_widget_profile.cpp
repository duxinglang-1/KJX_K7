/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  vapp_hs_widget_profile.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: Profile
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
//#include "vapp_hs_res.h"
//#include "SettingProfileEnum.h"
extern "C"
{
#include "MMI_features.h"
}

#ifdef __MMI_VUI_HOMESCREEN_PROFILE__
#include "vapp_hs_widget_profile.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vapp_hs_widget_base.h"
#include "vadp_v2p_widget_profile.h"
#include "vfx_timer.h"
#include "vfx_basic_type.h"
extern "C"
{
#include "mmi_rp_app_venus_homescreen_wg_profile_def.h"
}

/*****************************************************************************
 * Class VappHsWidgetProfileButton
 *****************************************************************************/

//Macro to implement class information 
VFX_IMPLEMENT_CLASS(VAPP_HS_PROFILE_BUTTON_CLASS_NAME, VappHsWidgetProfileButton, VfxControl);

VappHsWidgetProfileButton::VappHsWidgetProfileButton() : m_image(NULL)
{   
}


VappHsWidgetProfileButton::~VappHsWidgetProfileButton()
{
}

void VappHsWidgetProfileButton::onInit(void)
{
    VfxControl::onInit();
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
}


void VappHsWidgetProfileButton::onDeinit(void)
{
    //no need to close child object: m_image, 
    //because when an object has been deleted, it also deletes its child objects.
    VfxControl::onDeinit(); 
}

void VappHsWidgetProfileButton::setResId(VfxS32 imageId)
{
	m_image->setResId(imageId);
	setBounds(m_image->getBounds()); 
}

VfxBool VappHsWidgetProfileButton::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_eventPenDown.emit(this, event);
    }
    return VFX_FALSE;
}

/*****************************************************************************
 * Class VappHsWidgetProfile
 *****************************************************************************/
 
void VappHsWidgetProfile::onInit()
{   
    VappHsWidget::onInit();
	for(int i = 0; i < TOTLE_PROFILES; i++)
	{
		m_profiles[i] = NULL;
	}
	m_isViewCreated = VFX_FALSE;
	m_penDownProfile = NULL;

	VFX_OBJ_CREATE(m_timer, VfxTimer, this);
	m_timer->setStartDelay(PROFILE_WIDGET_HIDDEN_TIMER);
    m_timer->setDuration(0);
}

void VappHsWidgetProfile::onDeinit()
{       
	if (m_timer->getIsEnabled())
    {
        m_timer->stop();
    }
	VappHsWidget::onDeinit();
}

VfxBool VappHsWidgetProfile::onPenInput(VfxPenEvent &event)
{
	stopSetHiddenTimer();
	if (event.type == VFX_PEN_EVENT_TYPE_DOWN &&
		m_isDisplayAll == VFX_TRUE &&
		m_penDownProfile != NULL)
	{		
		return VFX_TRUE;
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_MOVE && 
			 m_isDisplayAll == VFX_TRUE &&
			 m_penDownProfile != NULL)
	{
		return VFX_TRUE;
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_MOVE && 
			 m_isDisplayAll == VFX_FALSE &&
			 m_penDownProfile != NULL)
	{
		if (event.pos.x - event.prevPos.x > PROFILE_WIDGET_MOVE_LENGTH ||
			event.pos.x - event.prevPos.x < -PROFILE_WIDGET_MOVE_LENGTH ||
			event.pos.y - event.prevPos.y > PROFILE_WIDGET_MOVE_LENGTH ||
			event.pos.y - event.prevPos.y < -PROFILE_WIDGET_MOVE_LENGTH)
		{
			m_penDownProfile = NULL;
		}
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_UP && m_penDownProfile != NULL)
	{
		profilePenUpHdlr(m_penDownProfile, event);
		m_penDownProfile = NULL;		
	}
	if (event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		startSetHiddenTimer();
	}
    return VappHsWidget::onPenInput(event);
}


VfxU16 VappHsWidgetProfile::getIcon()
{
	return VAPP_HS_IMG_WG_ICON_PROFILE; 
}

VfxU16 VappHsWidgetProfile::getName()
{
    return VAPP_HS_STR_WG_PROFILE; 
}

void VappHsWidgetProfile::onCreateView()
{
	int i;
	m_isDisplayAll = VFX_FALSE;
	
	VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
	m_imageBg->setResId(VAPP_HS_IMG_WG_PROF_BG);
	m_imageBg->setPos(VfxPoint(PROFILE_BG_OFFSET_X, PROFILE_BG_OFFSET_Y));

	VFX_OBJ_CREATE(m_imageCurrBg, VfxImageFrame, this);
	m_imageCurrBg->setResId(VAPP_HS_IMG_WG_PROF_CURR_BG);
	m_imageCurrBg->setAutoAnimate(VFX_TRUE);

	for(i = 0; i < TOTLE_PROFILES; i++)
	{
		VFX_OBJ_CREATE(m_profiles[i], VappHsWidgetProfileButton, this);
		m_profiles[i]->setAutoAnimate(VFX_TRUE);
	}
	
	VFX_OBJ_CREATE(m_imageActivity, VfxImageFrame, this);
	//m_imageActivity->setAutoAnimate(VFX_TRUE);

	m_isViewCreated = VFX_TRUE;
	m_activatedProfile = vadp_v2p_profile_get_activated_profile();
	m_highlightProfile = m_activatedProfile;

	for(i = 0; i < TOTLE_DISPLAY; i++)
	{
		m_profiles[i]->m_eventPenDown.connect(this, &VappHsWidgetProfile::profilePenDownHdlr);
	}

	updateDisplay();
	
	m_timer->m_signalTick.connect(this, &VappHsWidgetProfile::setHiddenButton);
	startSetHiddenTimer();
}


void VappHsWidgetProfile::onReleaseView()
{
	int i;
	for(i = 0; i < TOTLE_DISPLAY; i++)
	{
		m_profiles[i]->m_eventPenDown.disconnect(this, &VappHsWidgetProfile::profilePenDownHdlr);
	}

	m_timer->m_signalTick.disconnect(this, &VappHsWidgetProfile::setHiddenButton);

	VFX_OBJ_CLOSE(m_imageActivity);
	
	for(i = 0; i < TOTLE_PROFILES; i++)
	{
		VFX_OBJ_CLOSE(m_profiles[i]);
	}
	VFX_OBJ_CLOSE(m_imageBg);
	VFX_OBJ_CLOSE(m_imageCurrBg);
	m_isViewCreated = VFX_FALSE;
}

void VappHsWidgetProfile::startSetHiddenTimer(void)
{
    m_timer->start();
}


void VappHsWidgetProfile::stopSetHiddenTimer(void)
{
	m_timer->stop();
}

void VappHsWidgetProfile::setHiddenButton(VfxTimer *source)
{
    VFX_UNUSED(source); //To avoid unused function parameter warning.
	m_isDisplayAll = VFX_FALSE;
	updateDisplay();
}

void VappHsWidgetProfile::updateDisplay()
{
	if (!m_isViewCreated)
	{
		return;
	}
	if (m_isDisplayAll && m_activatedProfile < TOTLE_DISPLAY)
	{
		VfxU8 i;
		VfxPoint pos = VfxPoint(0, 0);
		for (i = 0; i < TOTLE_DISPLAY; i++)
		{
			m_profiles[i]->setHidden(VFX_FALSE);
		}
		i = GENERAL_PROFILE;
		if (m_highlightProfile == GENERAL_PROFILE)
		{
			pos.x = PROFILE_LEFT_OFFSET_L_X;
			pos.y = PROFILE_LEFT_OFFSET_L_Y;
			m_imageCurrBg->setPos(pos);
			m_profiles[GENERAL_PROFILE]->setPos(VfxPoint(pos.x + PROFILE_LARGE_OFFSET_X, pos.y + PROFILE_LARGE_OFFSET_Y));
			i++;
		}
		else
		{
			pos.x = PROFILE_LEFT_OFFSET_S_X;
			pos.y = PROFILE_LEFT_OFFSET_S_Y;
			for ( i = GENERAL_PROFILE; i < m_highlightProfile; i++)
			{				
				m_profiles[i]->setPos(pos);
				pos.x = pos.x + PROFILE_SMALL_SIZE_X + PROFILE_GAP;
			}
			pos.y = 0;
			m_imageCurrBg->setPos(pos);
			m_profiles[i]->setPos(VfxPoint(pos.x + PROFILE_LARGE_OFFSET_X, pos.y + PROFILE_LARGE_OFFSET_Y));
			i++;

		}
		pos.x = pos.x + PROFILE_CURRBG_SIZE_X + PROFILE_GAP;
		pos.y = PROFILE_LEFT_OFFSET_S_Y;
		for (; i < TOTLE_DISPLAY; i++)
		{
			m_profiles[i]->setPos(pos);
			pos.x = pos.x + PROFILE_SMALL_SIZE_X + PROFILE_GAP;
		}
		for(i = 0; i < TOTLE_DISPLAY; i++)
		{
			m_profiles[i]->setResId(i * 2 + VAPP_HS_IMG_WG_PROF_GENERAL_S);
		}
		m_imageBg->setHidden(VFX_FALSE);
		m_profiles[m_highlightProfile]->setResId(m_highlightProfile * 2 + VAPP_HS_IMG_WG_PROF_GENERAL_L);	
		
		m_imageActivity->setHidden(VFX_FALSE);
		
		if (m_highlightProfile == m_activatedProfile)
		{
		    m_imageCurrBg->addChildFrame(m_imageActivity);
			//m_imageCurrBg->addChild(m_imageActivity);
			m_imageActivity->setResId(VAPP_HS_IMG_WG_PROF_ACTIVITY_L);
		}
		else
		{
		    m_profiles[m_activatedProfile]->addChildFrame(m_imageActivity);
			//m_profiles[m_activatedProfile]->addChild(m_imageActivity);
			m_imageActivity->setResId(VAPP_HS_IMG_WG_PROF_ACTIVITY_S);
		}
		setBounds(VfxRect(0,
						  0, 
						  m_imageBg->getBounds().getWidth(), 
						  m_imageCurrBg->getBounds().getHeight()));
	}
	else
	{
		for(int i = 0; i < TOTLE_DISPLAY; i++)
		{
			m_profiles[i]->setHidden(VFX_TRUE);
		}
		m_imageActivity->setHidden(VFX_TRUE);
		if (m_activatedProfile < TOTLE_DISPLAY)
		{
			m_profiles[m_activatedProfile]->setResId(m_activatedProfile * 2 + VAPP_HS_IMG_WG_PROF_GENERAL_L);
		}
		else
		{
//			m_profiles[m_activatedProfile]->setResId(m_activatedProfile - HEADSET_PROFILE + VAPP_HS_IMG_WG_PROF_HEADSET_L);
		}
		m_imageBg->setHidden(VFX_TRUE);
		m_profiles[m_activatedProfile]->setHidden(VFX_FALSE);
		m_imageCurrBg->setPos(VfxPoint(0, 0));
		m_profiles[m_activatedProfile]->setPos(VfxPoint(PROFILE_LARGE_OFFSET_X, PROFILE_LARGE_OFFSET_Y));
		setBounds(m_imageCurrBg->getBounds()); 
	}
}

VfxU8 VappHsWidgetProfile::getProfileId(const VappHsWidgetProfileButton * profile_p) const
{
	for(int i = 0; i < TOTLE_DISPLAY; i++)
	{
		if (m_profiles[i] == profile_p)
			return i;
	}
	return TOTLE_DISPLAY;
}

void VappHsWidgetProfile::profilePenDownHdlr(VappHsWidgetProfileButton * profile_p, VfxPenEvent &event)
{
    VFX_UNUSED(event);//To avoid unused function parameter warning.
	if (m_isDisplayAll == VFX_TRUE)
	{
		profile_p->setOpacity(0.5f);
	}
	m_penDownProfile = profile_p;
}

void VappHsWidgetProfile::profilePenUpHdlr(VappHsWidgetProfileButton * profile_p, VfxPenEvent &event)
{
	profile_p->setOpacity(1.0f);
	VfxU8 profileId = getProfileId(profile_p);
	if (m_profiles[profileId]->containPoint(event.getRelPos(m_profiles[profileId])))
	{
		if (m_isDisplayAll == VFX_TRUE && m_highlightProfile == profileId)
		{
			vadp_v2p_profile_set_activated_profile(m_highlightProfile);
			m_activatedProfile = m_highlightProfile;
			m_isDisplayAll = VFX_FALSE;			
		}
		else
		{
			m_highlightProfile = profileId;
			m_isDisplayAll = VFX_TRUE;
		}
		updateDisplay();
	}
}
#endif

