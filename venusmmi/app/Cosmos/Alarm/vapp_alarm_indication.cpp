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
 *  vapp_alarm_indication.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Fancy alarm ap.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
	#include "GlobalResDef.h"
	#include "mdi_audio.h"
	#include "wgui.h"
	#include "Mmi_frm_input_gprot.h"

	#include "AlarmSrvGprot.h"
	#include "BootupSrvGprot.h"
	#include "GpioSrvGprot.h"
	#include "ReminderSrvGprot.h"
	 #include "UcmSrvGprot.h"
}

#include "mmi_rp_vapp_alarm_def.h"
#include "mmi_rp_vapp_alarm_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif

#include "vfx_primitive_frame.h"
#include "vfx_renderer.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vfx_timer.h"

#include "vdat_systime.h"

#include "vcp_button.h"
#include "vcp_form.h" // include for vapp_screen_lock_gprot.h
#include "vcp_status_icon_bar.h"

#include "vcui_tone_selector_gprot.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_platform_context.h"

#include "vapp_alarm.h"
#include "vapp_alarm_indication.h"
#include "vapp_alarm_clock.h"
#include "Resource_audio.h"

#ifdef MOTION_SENSOR_SUPPORT
  #include "ReminderSrvGprot.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_ALARM_POP_STOP    'STOP'
#define VAPP_ALARM_POP_SNOOZE  'SNOO'

#define VAPP_ALARM_TIME_DELAY 60000
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmIndApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAlarmIndApp", VappAlarmIndApp, VfxApp);

void VappAlarmIndApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

	VappAlarmParam *param = (VappAlarmParam *)args;

	VFX_ASSERT(param != NULL && argSize == sizeof(VappAlarmParam));

#ifdef MOTION_SENSOR_SUPPORT
	if(srv_reminder_get_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER))
	{
		m_handle = srv_sensor_start_listen(
						SRV_SENSOR_MOTION_TURNOVER, 
						NULL, 
						VappAlarmIndApp::motionTurnoverCallback, 
						param);
	}
#endif

	VfxAppScr *scr = NULL;
	#ifndef __LOW_COST_SUPPORT_COMMON__
	if (vapp_screen_lock_is_exist())
	{
		VFX_OBJ_CREATE_EX(scr, 
						VappAlarmCardScr, 
						this, 
						(param->expiry_index));
	}
	else
	#endif /* XXX */
	{
		VFX_OBJ_CREATE_EX(scr, 
					VappAlarmIndicationScr, 
					this, 
					(param->pwr_off, param->expiry_index));
	}

	if (scr != NULL)
	{
		scr->show();
	}
}
#ifdef MOTION_SENSOR_SUPPORT
void VappAlarmIndApp::onDeinit()
{
	 VfxApp::onDeinit();

	if(srv_reminder_get_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER))
	{
		srv_sensor_stop_listen(m_handle);
		m_handle = -1;
    }
   
}

void VappAlarmIndApp::motionTurnoverCallback(srv_sensor_type_enum sensor_type,void *sensor_data,void *user_data)
{
   if(sensor_type==SRV_SENSOR_MOTION_TURNOVER)
   	{
		srv_sensor_motion_turnover_struct *motion_turnover = (srv_sensor_motion_turnover_struct *)sensor_data;        
		if (SRV_SENSOR_MOTION_TURNOVER_DOWN == motion_turnover->direction)
		{
       srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
			
			VappAlarmParam *param=(VappAlarmParam *)sensor_data;

	   srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(param->expiry_index);
	
	    if (node != NULL && node->vibrate)
	    {
		srv_vibrator_post_req(VIB_PATTERN_1, PLAY_STOP);
	    }
   	}
}
}
#endif /* MOTION_SENSOR_SUPPORT */

MMI_BOOL VappAlarmIndApp::onNmgrNotify(mmi_scenario_id scen_id, void *arg)
{
	VFX_ASSERT(scen_id == MMI_SCENARIO_ID_REMINDER_ALARM);
	VFX_ASSERT(arg != NULL);
	
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_NMGR);
	
    VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
	
	VfxAppLauncher::launchWithCtx(
		VAPP_ALARM_IND,
		VFX_OBJ_CLASS_INFO(VappAlarmIndApp),
		GRP_ID_ROOT,
		cntx,
		arg,
		sizeof(VappAlarmParam));

	OslMfree(arg);
	
	return MMI_TRUE;
}

mmi_ret VappAlarmIndApp::onReminderEvt(mmi_event_struct *evt)
{
	if(srv_ucm_is_incoming_call() ||srv_ucm_is_outgoing_call())
			{
			srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM,TONE_WARNING2,
		SRV_PROF_RING_TYPE_ONCE, NULL);
			
			}

	srv_reminder_evt_struct *rmd_evt = (srv_reminder_evt_struct *)evt;

	if (rmd_evt->reminder_type != SRV_REMINDER_TYPE_ALM &&
		rmd_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}

	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_REMINDER, rmd_evt->evt_id, rmd_evt->reminder_type, rmd_evt->notify);
	
	switch(rmd_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
			srv_alm_init(NULL);
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
		{
			srv_alm_node_type *expiryNode = srv_alm_read(rmd_evt->usr_data);

			if (expiryNode->Hour == 0xFF)
			{
				srv_reminder_notify_finish(MMI_FALSE);
				
				break; 
			}
			
			VappAlarmParam *param = (VappAlarmParam *)OslMalloc(sizeof(VappAlarmParam));
			//VFX_SYS_ALLOC_MEM(param, sizeof(VappAlarmParam));
			
			param->launch_id = VappAlarmApp::ID_LAUNCH_ALARM_IND;
			param->pwr_off = (rmd_evt->pwr_off == 1) ? VFX_TRUE : VFX_FALSE;
			param->expiry_index = rmd_evt->usr_data;

			mmi_frm_nmgr_notify_by_app(
				MMI_SCENARIO_ID_REMINDER_ALARM, 
				MMI_EVENT_REMINDER_ALARM,
				VappAlarmIndApp::onNmgrNotify,
				param); 		
			break;
		}
		
		case SRV_REMINDER_NOTIFY_REINIT:
		{
			srv_alm_reset_reminder();
			break;
		}
			
		/*case SRV_REMINDER_NOTIFY_DEINIT:
		{
			
			break;
		}*/
			
		default:
			break;
	}
	
	return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VappAlarmIndicationPopup
 *****************************************************************************/
VappAlarmIndicationPopup::VappAlarmIndicationPopup(const VfxU8 &index) : 
	m_clock(NULL),
	m_label(NULL),
	m_btnStop(NULL),
	m_btnSnooze(NULL),
	m_index(index),
	m_isUsrAction(VFX_FALSE),
	m_isTonePlaying(VFX_FALSE)
{
}

void VappAlarmIndicationPopup::onInit(void)
{
	VfxBasePopup::onInit();
	
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_INIT, m_index);

	VfxFrame *bgImage;
    VFX_OBJ_CREATE(bgImage, VfxFrame, this);
    bgImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    bgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bgImage->setIsCached(VFX_TRUE);
	bgImage->setSize(VfxSize(WIDTH, HEIGHT));
	setSize(bgImage->getSize());
	
	srv_alm_node_type *node = srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);

	VfxFontDesc font;
	VappAlarmTimeFrame *time;

	VfxDateTime currtime;
	currtime.setCurrentTime();
	
	VFX_OBJ_CREATE_EX(time, 
					  VappAlarmTimeFrame, 
					  this, 
					  (currtime.getHour(), currtime.getMinute(), TIME_FONT_SIZE));
	
	VfxTextFrame *label = NULL;
	if (vfx_sys_wcslen((const VfxWChar*)node->label) != 0)
	{
		VFX_OBJ_CREATE(label, VfxTextFrame, this);
		label->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
		font.size = VFX_FONT_DESC_VF_SIZE(LABEL_FONT_SIZE);
                label->setFont(font);
		label->setString(VFX_WSTR_MEM((const VfxWChar*)node->label));

	}
	
	VFX_OBJ_CREATE_EX(m_clock, VappAlarmClock, this, (currtime.getHour(), currtime.getMinute()));
	m_clock->setPos(CLOCK_LEFT_MARTIN, CLOCK_TOP_MARTIN);
	
	m_snooze = VappAlarmApp::getSnoozeVal();
	
	VfxS8 snoozeIndex = ALARM_GET_SNOOZE_IDX(m_snooze);
	

	VFX_OBJ_CREATE(m_btnStop, VcpButton, this);
	m_btnStop->setAnchor(1.0F, 1.0F);
	m_btnStop->setPos(getSize().width - BTN_LEFT_MARGIN, getSize().height - BTN_BOTTOM_MARGIN);
	m_btnStop->setText(VFX_WSTR_RES(STR_ID_VAPP_ALARM_DISMISS));
	
	m_btnStop->setId(VAPP_ALARM_POP_STOP);
	m_btnStop->m_signalClicked.connect(this, &VappAlarmIndicationPopup::onBtnClick);
		
	if (node->Snooze <= VappAlarmApp::MAX_SNOOZE_TIME)
	{
	VFX_OBJ_CREATE(m_btnSnooze, VcpButton, this);
	m_btnSnooze->setText(VFX_WSTR_RES(ALARM_GET_SNOOZE_FOR_RES(snoozeIndex)));
	m_btnSnooze->setId(VAPP_ALARM_POP_SNOOZE);
	m_btnSnooze->m_signalClicked.connect(this, &VappAlarmIndicationPopup::onBtnClick);

		m_btnSnooze->setAnchor(0.0F, 1.0F);
		m_btnSnooze->setPos(BTN_LEFT_MARGIN, getSize().height - BTN_BOTTOM_MARGIN);

		m_btnStop->setSize(getSize().width - m_btnSnooze->getSize().width - (3 * BTN_LEFT_MARGIN), 
					   m_btnStop->getSize().height);
	}
	else
	{
		m_btnStop->setAnchor(0.0F, 1.0F);
		m_btnStop->setPos(BTN_LEFT_MARGIN, getSize().height - BTN_BOTTOM_MARGIN);
		m_btnStop->setSize(getSize().width - (BTN_LEFT_MARGIN << 1), m_btnStop->getSize().height);		
	}

	// reset time position
	VfxU16 timeHeight = getSize().height - 
						(TIME_FONT_SIZE + LABEL_FONT_SIZE + LABEL_INT) -
						m_btnStop->getSize().height - 
						BTN_BOTTOM_MARGIN;
	
	timeHeight = (timeHeight >> 1);
	time->setPos((m_clock->getPos().x + m_clock->getSize().width + (TIME_RIGHT_MARTIN >> 1)), timeHeight);
	
	if (label != NULL)
	{
		VfxS32 x = time->getPos().x;
		VfxS32 y = time->getPos().y + time->getSize().height + LABEL_INT;
		
		label->setPos(x, y);
		label->setSize(getSize().width - x - (TIME_RIGHT_MARTIN >> 1), LABEL_FONT_SIZE);
	    label->setMaxLines(1);
        label->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		//label->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	}
	
	regEvtHdlr();
	mmi_frm_start_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);	

	VfxTimer *timer;
	VFX_OBJ_CREATE(timer, VfxTimer, this);
	timer->setStartDelay(VAPP_ALARM_TIME_DELAY);
	timer->m_signalTick.connect(this, &VappAlarmIndicationPopup::onTimerCallback);
	timer->start();

}

void VappAlarmIndicationPopup::onTimerCallback(VfxTimer *obj)
{
	srv_alm_node_type *node = srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);
	
	if (node->Snooze <= VappAlarmApp::MAX_SNOOZE_TIME)
	{
		onBtnClick(m_btnSnooze, VAPP_ALARM_POP_SNOOZE);
}
	else
	{
		onBtnClick(m_btnSnooze, VAPP_ALARM_POP_STOP);
	}
}


void VappAlarmIndicationPopup::onDeinit(void)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_DEINIT);

	if (m_isTonePlaying)
	{
		mdi_audio_resume_background_play();
		m_isTonePlaying = VFX_FALSE;
	}

	if (!m_isUsrAction)
	{
		VfxId id;
		
		if (m_btnSnooze != NULL)
		{
			id = VAPP_ALARM_POP_SNOOZE;
		}
		else
		{
			id = VAPP_ALARM_POP_STOP;
		}
		
		onBtnClick(m_btnSnooze, id);
	}
	
	mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);
	deregEvtHdlr();
	
	srv_reminder_notify_finish(MMI_FALSE);

	VfxBasePopup::onDeinit();
}

void VappAlarmIndicationPopup::onExit(void)
{
	stopTone();
	stopVib();
	
	VfxBasePopup::onExit();
}

VfxBool VappAlarmIndicationPopup::onKeyInput(VfxKeyEvent & event)
{
	if (event.keyCode == VFX_KEY_CODE_BACK)
	{
		if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
		{
		    leave(VFX_TRUE);
		}
	}

	// below code is from is_mmi_power_off_key_evt()	
    if (event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
    {
    	VfxBool pwrOff = VFX_FALSE;
		
        if (event.keyCode == VFX_KEY_CODE_END)
	{
            if(!mmi_frm_kbd_is_key_supported(VFX_KEY_CODE_POWER))  
		{
                pwrOff = MMI_TRUE;
            }
        }
        else if (event.keyCode  == VFX_KEY_CODE_POWER)
        {
            pwrOff = MMI_TRUE;
		}
		
		if (pwrOff)
		{
			leave(VFX_TRUE);
			
		return VfxBasePopup::onKeyInput(event);
	}
    }
	
	
	return VFX_TRUE;
}

void VappAlarmIndicationPopup::stopTone(void)
{
		srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
}

void VappAlarmIndicationPopup::stopVib(void)
{
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
	
	if (node != NULL && node->vibrate)
	{
		srv_vibrator_post_req(VIB_PATTERN_1, PLAY_STOP);
	}
}

srv_prof_ret VappAlarmIndicationPopup::onPlayToneCallback(srv_prof_ret result)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE_CB, result);
	
	if (result == SRV_PROF_RET_FAIL)
	{
		srv_prof_play_req_struct play_req;
		
  		srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_ALARM);
		
		play_req.volume = MDI_AUD_VOL_MUTE(VappAlarmApp::getVol());
		play_req.aud_path = MDI_DEVICE_SPEAKER_BOTH;
		play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;		
		play_req.audio_id = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE, 0);
        play_req.callback = NULL;
		play_req.audio_type = SRV_PROF_AUDIO_STRING;

		srv_prof_play_tone_with_full_struct(&play_req);
	}
	 
	return SRV_PROF_RET_YES;
}


mmi_ret VappAlarmIndicationPopup::onPlayTone(mmi_event_struct *evt)
{
	mmi_nmgr_custom_evt_struct *nmgr_evt = (mmi_nmgr_custom_evt_struct*)evt;
	
	if (nmgr_evt->scenario_id != MMI_SCENARIO_ID_REMINDER_ALARM)
	{
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 0);
		return MMI_RET_OK;
	}

	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);
		
	if (node->ringtone != 0)
	{
	if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
	{
		srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, SRV_PROF_TONE_SMS_INCALL, SRV_PROF_RING_TYPE_ONCE, NULL);

			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 1);
			
		return MMI_RET_OK;
	}

		m_isTonePlaying = VFX_TRUE;
		mdi_audio_suspend_background_play();

		srv_prof_play_req_struct play_req;
		
		srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_ALARM);
		
		play_req.volume = MDI_AUD_VOL_MUTE(VappAlarmApp::getVol());
		play_req.aud_path = MDI_DEVICE_SPEAKER_BOTH;
		play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
		
		switch(node->AudioOption)
		{
			case SRV_PROF_AUDIO_RES_TONE:
			case SRV_PROF_AUDIO_RES_RING:
			{
				VfxU16 aud_id = srv_prof_get_audio_id_from_audio_resourece(
									(srv_prof_audio_resource_type_enum)node->AudioOption, 
									node->AudioOptionValue);
				
				play_req.audio_id = aud_id;
                play_req.callback = NULL;
				play_req.audio_type = SRV_PROF_AUDIO_STRING;
				
				MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 2);
				break;
			}
			
			case SRV_PROF_AUDIO_RES_FILE:
			{
				play_req.audio_type = SRV_PROF_AUDIO_FILE;
				play_req.filepath = (WCHAR *)node->tone_path;
				play_req.callback = VappAlarmIndicationPopup::onPlayToneCallback;
				
				MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 3);
				
				break;
			}
			default:
				break;
		}

		if (srv_prof_play_tone_with_full_struct(&play_req) != SRV_PROF_RET_SUCCESS)
		{
			VappAlarmIndicationPopup::onPlayToneCallback(SRV_PROF_RET_FAIL);
		}
	}
	
	
	return MMI_RET_OK;
}

mmi_ret VappAlarmIndicationPopup::onPlayVib(mmi_event_struct *evt)
{
    mmi_nmgr_custom_evt_struct *nmgr_evt = (mmi_nmgr_custom_evt_struct*)evt;
	
	if (nmgr_evt->scenario_id != MMI_SCENARIO_ID_REMINDER_ALARM)
	{
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_VIB, 0);

		return MMI_RET_OK;
	}
	
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);
		
	if (node->vibrate)
	{
		if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
		{
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_VIB, 1);
			srv_vibrator_post_req(VIB_PATTERN_1, PLAY_ONCE);
		}
		else
		{
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_VIB, 2);
		srv_vibrator_post_req(VIB_PATTERN_1, PLAY_REPEAT);
	}
	}

	return MMI_RET_OK;
}

void VappAlarmIndicationPopup::onBtnClick(VfxObject* obj, VfxId id)
{
	m_isUsrAction = VFX_TRUE;
	
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_BTN_CLICK, id);
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
    VFX_ASSERT(node != NULL);

	switch(id)
	{
		case VAPP_ALARM_POP_STOP:
		{
			if (node->Freq == SRV_REMINDER_REPEAT_ONCE)
			{
				node->State = 0;
			}
			node->Snooze = 0;
			node->timestamp = ALARM_GET_TIMESTAMP;
			
			srv_alm_write(m_index, node);
			break;
		}
		
		case VAPP_ALARM_POP_SNOOZE:
		{
			node->Snooze++;
			node->SnoozeInterval = m_snooze;
			node->timestamp = ALARM_GET_TIMESTAMP;
			srv_alm_write(m_index, node);

			VfxS8 snoozeIndex = ALARM_GET_SNOOZE_IDX(m_snooze);

			if (!VappAlarmApp::needPwrOff())
			{
	            mmi_frm_nmgr_balloon(
	                    MMI_SCENARIO_ID_GENERAL,
	                    MMI_EVENT_INFO_BALLOON,
	                    MMI_NMGR_BALLOON_TYPE_INFO,
	                    (WCHAR*)GetString(ALARM_GET_SNOOZING_FOR_RES(snoozeIndex)));
			}
			
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_BTN_CLICK_SNOOZE, node->Snooze);
			break;
		}
	}
	
	VappAlarmApp::refreshStatusIcon();
	
	m_signalBtnClick.postEmit(this, id);
	leave(VFX_TRUE);
}

void VappAlarmIndicationPopup::regEvtHdlr(void)
{
    //mmi_frm_cb_reg_event(EVT_ID_GPIO_CLAM_CLOSE, VappAlarmIndicationPopup::onEvtHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_NMGR_PLAY_TONE, VappAlarmIndicationPopup::onEvtHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_NMGR_PLAY_VIB, VappAlarmIndicationPopup::onEvtHdlr, this);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappAlarmIndicationPopup::onEvtHdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappAlarmIndicationPopup::onEvtHdlr, NULL);

}
void VappAlarmIndicationPopup::deregEvtHdlr(void)
{
    //mmi_frm_cb_dereg_event(EVT_ID_GPIO_CLAM_CLOSE, VappAlarmIndicationPopup::onEvtHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_NMGR_PLAY_TONE, VappAlarmIndicationPopup::onEvtHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_NMGR_PLAY_VIB, VappAlarmIndicationPopup::onEvtHdlr, this);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappAlarmIndicationPopup::onEvtHdlr, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappAlarmIndicationPopup::onEvtHdlr, NULL);
}

mmi_ret VappAlarmIndicationPopup::onEvtHdlr(mmi_event_struct *evt)
{
	//kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[Alarm]VappAlarmIndicationPopup::onEvtHdlr(%d)", evt->evt_id);
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_POP_ON_EVT, evt->evt_id);
	VappAlarmIndicationPopup *popup = (VappAlarmIndicationPopup *)evt->user_data;
	switch (evt->evt_id)
	{
		case EVT_ID_NMGR_PLAY_TONE:
			popup->onPlayTone(evt);
			break;
			
		case EVT_ID_NMGR_PLAY_VIB:
			popup->onPlayVib(evt);
			break;

        case EVT_ID_GPIO_BACKLIGHT_DIMMING:
			if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
			{
				break;
			}
			else
			{
				return MMI_RET_ERR;
			}    		

        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
			if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
			{
				break;
			}
			else
			{
    			return MMI_RET_ERR;
			}
		default:
			break;
	}
	
	return MMI_RET_OK;
}


/***************************************************************************** 
 * Class VappAlarmIndicationScr
 *****************************************************************************/
 VFX_IMPLEMENT_CLASS("VappAlarmIndicationScr", VappAlarmIndicationScr, VfxAppScr);

VappAlarmIndicationScr::VappAlarmIndicationScr(const VfxBool &pwrOff, const VfxU8 &index) : 
	m_statusBar(NULL),
	m_popup(NULL),
	m_bPwrOff(pwrOff),
	m_index(index)
{
	setIsSmallScreen();
}

void VappAlarmIndicationScr::onInit(void)
{
	VfxAppScr::onInit();

	setBgColor(VFX_COLOR_TRANSPARENT);
	
	if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
	{
	// status bar need to be updated during alarm
	VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
	m_statusBar->setAutoAnimate(VFX_TRUE);
	m_statusBar->setPos(0, 0);
	}

	// display first page
	VappAlarmIndicationPopup *pop;
	VFX_OBJ_CREATE_EX(pop, VappAlarmIndicationPopup, this, (m_index));
	pop->setAutoDestory(VFX_TRUE);
	pop->m_signalBtnClick.connect(this, &VappAlarmIndicationScr::onPopupClick);

	m_popup = pop;
}

void VappAlarmIndicationScr::onEnter(VfxBool isBackward)
{
	VfxAppScr::onEnter(isBackward);
    if (m_statusBar != NULL)
	{
		m_statusBar->setSize(getSize().width, MMI_STATUS_BAR_HEIGHT);
    }

	VappAlarmIndicationPopup *pop = m_popup.get();
	if (pop != NULL)
	{
		pop->show(VFX_TRUE);
	}
    else
    {
      exit();
    }
}

void VappAlarmIndicationScr::onRotate(const VfxScreenRotateParam & param)
{
	VfxAppScr::onRotate(param);
	
    if (m_statusBar != NULL)
	{
	    m_statusBar->setSize(getSize().width, MMI_STATUS_BAR_HEIGHT);
    }
}

void VappAlarmIndicationScr::onPopupClick(VfxObject *obj, VfxId id)
{
	exit();
}

void VappAlarmIndicationScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
	VfxRenderer *render = VFX_OBJ_GET_INSTANCE(VfxRenderer);

	param.rotateTo = render->getPreScreenRotateType();
}

/***************************************************************************** 
 * Class VappAlarmIndicationPopup
 *****************************************************************************/
 #ifndef __LOW_COST_SUPPORT_COMMON__
   VFX_IMPLEMENT_CLASS("VappAlarmCardScr", VappAlarmCardScr, VfxMainScr);

void VappAlarmCardScr::on1stReady()
{
    VfxMainScr::on1stReady();

	// on lock screen
	VappCalReminderCardPage *cardPage;
	VFX_OBJ_CREATE(cardPage, VappCalReminderCardPage, this);
	
	cardPage->m_signalDrag.connect(this, &VappAlarmCardScr::ReminderCardPageLeave);

	VFX_OBJ_CREATE_EX(m_card, VappAlarmCard, cardPage, (m_idx));
	cardPage->addCard(m_card);
	
	pushPage(0, cardPage);

	// set a timer about 30s

	VfxTimer *timer;
	VFX_OBJ_CREATE(timer, VfxTimer, this);
	timer->setStartDelay(VAPP_ALARM_TIME_DELAY);
	timer->m_signalTick.connect(this, &VappAlarmCardScr::onTimeOut);
	timer->start();
		
	m_bAction = VFX_FALSE;
}

void VappAlarmCardScr::onDeinit()
{
	if (!m_bAction)
	{
		m_card->snooze();
	}

    VfxMainScr::onDeinit();
}

void VappAlarmCardScr::processExit(VfxBool isBackward)
{
	m_card->stopTone();
	m_card->stopVib();

	VfxMainScr::processExit(isBackward);
}

void VappAlarmCardScr::ReminderCardPageLeave(VfxObject* sender, VfxId id)
{
	m_bAction = VFX_TRUE;
	
	if (id == VAPP_CAL_REMINDER_SNOOZE)
	{
		m_card->snooze();
	}
	else
	{
		m_card->stop();
	}

	exit();
}

void VappAlarmCardScr::onTimeOut(VfxTimer *obj)
{
	if (!m_bAction)
	{
		VfxId idLeave;
		
		if (m_card->isMovable(VAPP_CAL_REMINDER_CARD_MOVE_DOWN))
		{
			idLeave = VAPP_CAL_REMINDER_SNOOZE;
}
		else
		{
			idLeave = VAPP_CAL_REMINDER_DISMISS;
		}

		ReminderCardPageLeave(obj, idLeave);
	}
}

/***************************************************************************** 
 * Class VappAlarmCard
 *****************************************************************************/

VappAlarmCard::VappAlarmCard(const VfxU8 &index) 
	: m_time(NULL),
	  m_clock(NULL),
	  m_label(NULL),
	  m_index(index),
	  m_bUsrAction(VFX_FALSE),
	  m_bIsTonePlaying(VFX_FALSE)
{
}

void VappAlarmCard::onInit()
{
	VappReminderCard::onInit();

	srv_alm_node_type *node = srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);


	VFX_OBJ_CREATE(m_clock, VfxImageFrame, this);
	m_clock->setResId(IMG_ID_VAPP_ALARM_IND_ON_SCRLK_BG);
	m_clock->setIsUnhittable(VFX_TRUE);
	
	VfxDateTime currtime;
	currtime.setCurrentTime();
	
	VFX_OBJ_CREATE_EX(m_time, 
					  VappAlarmTimeFrame, 
					  this, 
					  (currtime.getHour(), currtime.getMinute(), TIME_FONT_SIZE, AMPM_FONT_SIZE));

	m_time->setTimeColor(VFX_COLOR_BLACK, VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
	
	m_time->setIsUnhittable(VFX_TRUE);
	
	VfxFontDesc font;
	if (vfx_sys_wcslen((const VfxWChar*)node->label) != 0)
	{
		VFX_OBJ_CREATE(m_label, VfxTextFrame, this);
		m_label->setColor(VFX_COLOR_TEAL);
		font.size = VFX_FONT_DESC_VF_SIZE(LABEL_FONT_SIZE);
        m_label->setFont(font);
		m_label->setString(VFX_WSTR_MEM((const VfxWChar*)node->label));
		m_label->setIsUnhittable(VFX_TRUE);
		m_label->setMaxLines(1);
        m_label->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_label->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
	}
	
	layout();

	regEvtHdlr();
	mmi_frm_start_scenario(MMI_SCENARIO_ID_REMINDER_ALARM); 
}

void VappAlarmCard::layout(void)
{
	VfxS32 xShift = m_cardFrame->getPos().x - (m_cardFrame->getSize().width >> 1);
	
	m_clock->setAnchor(0.0F, 0.5F);
	m_clock->setPos(xShift + CLOCK_LEFT_MARGIN, (getSize().height >> 1));

	VfxS32 x, y;
	x = xShift + CLOCK_LEFT_MARGIN + m_clock->getBounds().getWidth() + TIME_LEFT_MARGIN;
	y = (getSize().height - (TIME_FONT_SIZE + LABEL_TOP_MARGIN + LABEL_FONT_SIZE)) >> 1;
	m_time->setAnchor(0.0F, 0.0F);
	m_time->setPos(x, y);

	if (m_label != NULL)
	{
		m_label->setSize(m_cardFrame->getBounds().getMaxX() - x - 10, LABEL_FONT_SIZE);

		m_label->setPos(x, (y + TIME_FONT_SIZE + LABEL_TOP_MARGIN));
	}
}

VfxBool VappAlarmCard::isMovable(const VfxS32 &operation)
{
	if (operation == VAPP_CAL_REMINDER_CARD_MOVE_DOWN)
	{
		srv_alm_node_type *node = srv_alm_read(m_index);
		VFX_ASSERT(node != NULL);
		if (node->Snooze >= VappAlarmApp::MAX_SNOOZE_TIME)
		{
			return VFX_FALSE;
		}
	}

	return VFX_TRUE;
}

void VappAlarmCard::stop(void)
{
	m_bUsrAction = VFX_TRUE;
	onBtnClick(NULL, VAPP_ALARM_POP_STOP);
}

void VappAlarmCard::snooze(void)
{
	m_bUsrAction = VFX_TRUE;
	onBtnClick(NULL, VAPP_ALARM_POP_SNOOZE);
}

void VappAlarmCard::onDeinit(void)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_DEINIT);

	if (m_bIsTonePlaying)
	{
		mdi_audio_resume_background_play();
	}
	
	stopTone();
	stopVib();
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
	
	mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);
	
	deregEvtHdlr();
	
	srv_reminder_notify_finish(MMI_FALSE);

	VappReminderCard::onDeinit();
}

void VappAlarmCard::stopTone(void)
{
		srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
}

void VappAlarmCard::stopVib(void)
{
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
	
	if (node != NULL && node->vibrate)
	{
		srv_vibrator_post_req(VIB_PATTERN_1, PLAY_STOP);
	}
}


mmi_ret VappAlarmCard::onPlayTone(mmi_event_struct *evt)
{
	mmi_nmgr_custom_evt_struct *nmgr_evt = (mmi_nmgr_custom_evt_struct*)evt;
	
	if (nmgr_evt->scenario_id != MMI_SCENARIO_ID_REMINDER_ALARM)
	{
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 0);
		return MMI_RET_OK;
	}

	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);
		
	if (node->ringtone != 0)
	{
	if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
	{
		srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, SRV_PROF_TONE_SMS_INCALL, SRV_PROF_RING_TYPE_ONCE, NULL);

			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 1);
			
		return MMI_RET_OK;
	}

		m_bIsTonePlaying = VFX_TRUE;
		mdi_audio_suspend_background_play();

		srv_prof_play_req_struct play_req;
		
		srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_ALARM);
		
		play_req.volume = MDI_AUD_VOL_MUTE(VappAlarmApp::getVol());
		play_req.aud_path = MDI_DEVICE_SPEAKER_BOTH;
		play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
		
		switch(node->AudioOption)
		{
			case SRV_PROF_AUDIO_RES_TONE:
			case SRV_PROF_AUDIO_RES_RING:
			{
				VfxU16 aud_id = srv_prof_get_audio_id_from_audio_resourece(
									(srv_prof_audio_resource_type_enum)node->AudioOption, 
									node->AudioOptionValue);
				
				play_req.audio_id = aud_id;
                play_req.callback = NULL;
				play_req.audio_type = SRV_PROF_AUDIO_STRING;
				
				MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 2);
				break;
			}
			
			case SRV_PROF_AUDIO_RES_FILE:
			{
				play_req.audio_type = SRV_PROF_AUDIO_FILE;
				play_req.filepath = (WCHAR *)node->tone_path;
				play_req.callback = VappAlarmIndicationPopup::onPlayToneCallback;
				
				MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_TONE, 3);
				
				break;
			}
			default:
				break;
		}

		if (srv_prof_play_tone_with_full_struct(&play_req) != SRV_PROF_RET_SUCCESS)
		{
			VappAlarmIndicationPopup::onPlayToneCallback(SRV_PROF_RET_FAIL);
		}
	}
	
	
	return MMI_RET_OK;
}

mmi_ret VappAlarmCard::onPlayVib(mmi_event_struct *evt)
{
	mmi_nmgr_custom_evt_struct *nmgr_evt = (mmi_nmgr_custom_evt_struct*)evt;
	
	if (nmgr_evt->scenario_id != MMI_SCENARIO_ID_REMINDER_ALARM)
	{
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_VIB, 0);

		return MMI_RET_OK;
	}
	
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);
		
	if (node->vibrate)
	{
		if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
		{
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_VIB, 1);
			srv_vibrator_post_req(VIB_PATTERN_1, PLAY_ONCE);
		}
		else
		{
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_PLAY_VIB, 2);
		srv_vibrator_post_req(VIB_PATTERN_1, PLAY_REPEAT);
	}
	}

	return MMI_RET_OK;
}

void VappAlarmCard::onBtnClick(VfxObject* obj, VfxId id)
{

	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_BTN_CLICK, id);

	switch(id)
	{
		case VAPP_ALARM_POP_STOP:
		{
			srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
			VFX_ASSERT(node != NULL);
			if (node->Freq == SRV_REMINDER_REPEAT_ONCE)
			{
				node->State = 0;
			}
			node->Snooze = 0;
			node->timestamp = ALARM_GET_TIMESTAMP;
			
			srv_alm_write(m_index, node);
			break;
		}
		
		case VAPP_ALARM_POP_SNOOZE:
		{
			srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(m_index);
			VFX_ASSERT(node != NULL);
			node->Snooze++;
			node->SnoozeInterval = VappAlarmApp::getSnoozeVal();

			node->timestamp = ALARM_GET_TIMESTAMP;
			srv_alm_write(m_index, node);

			VfxS8 snoozeIndex = ALARM_GET_SNOOZE_IDX(node->SnoozeInterval);
			
            mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_GENERAL,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_INFO,
                    (WCHAR*)GetString(ALARM_GET_SNOOZING_FOR_RES(snoozeIndex)));
			
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_BTN_CLICK_SNOOZE, node->Snooze);
			
			break;
		}
	}

	VappAlarmApp::refreshStatusIcon();
}

void VappAlarmCard::regEvtHdlr(void)
{
    mmi_frm_cb_reg_event(EVT_ID_NMGR_PLAY_TONE, VappAlarmCard::onEvtHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_NMGR_PLAY_VIB, VappAlarmCard::onEvtHdlr, this);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappAlarmCard::onEvtHdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappAlarmCard::onEvtHdlr, NULL);

}
void VappAlarmCard::deregEvtHdlr(void)
{
    mmi_frm_cb_dereg_event(EVT_ID_NMGR_PLAY_TONE, VappAlarmCard::onEvtHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_NMGR_PLAY_VIB, VappAlarmCard::onEvtHdlr, this);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappAlarmCard::onEvtHdlr, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappAlarmCard::onEvtHdlr, NULL);
}

mmi_ret VappAlarmCard::onEvtHdlr(mmi_event_struct *evt)
{
//kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[Alarm]VappAlarmCard::onEvtHdlr(%d)", evt->evt_id);
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_IND_ON_EVT, evt->evt_id);

	VappAlarmCard *card = (VappAlarmCard *)evt->user_data;
	switch (evt->evt_id)
	{
		case EVT_ID_NMGR_PLAY_TONE:
			card->onPlayTone(evt);
			break;
			
		case EVT_ID_NMGR_PLAY_VIB:
			card->onPlayVib(evt);
			break;

        case EVT_ID_GPIO_BACKLIGHT_DIMMING:
			if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
			{
				break;
			}
			else
			{
				return MMI_RET_ERR;
			}   


        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
			if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
			{
				break;
			}
			else
			{
				return MMI_RET_ERR;
			}              

		default:
			break;
	}
	
	return MMI_RET_OK;
}
#endif

#ifndef __LOW_COST_SUPPORT_COMMON__
void mmi_usb_terminate_alarm(void)
{
	VfxApp *app = VfxAppLauncher::findApp(
								VAPP_ALARM_IND,
								VFX_OBJ_CLASS_INFO(VappAlarmIndApp),
								VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
	if(app)
	{
     VappAlarmCardScr *almScreen =VFX_OBJ_DYNAMIC_CAST(app->getScreen(app->getTopScreenId()),VappAlarmCardScr);
	   if(almScreen)
		  {
        almScreen->onTimeOut(NULL);
	  	}
	}
	
}
#endif
