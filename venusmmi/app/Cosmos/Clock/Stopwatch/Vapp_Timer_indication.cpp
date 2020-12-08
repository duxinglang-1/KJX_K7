
/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "Vapp_Timer_indication.h"
#include "Vapp_Timer_page.h"
#include "mmi_rp_vapp_clock_def.h"
#include "vfx_app_launcher.h"
extern "C"
{
	#include "GpioSrvGprot.h"
	#include "mmi_cb_mgr_gprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_TIMER_AUTO_STOP_RING 60000
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern VappTimerstruct g_timer_cntx;
/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" MMI_ID vapp_timer_indication_launch(void* param, U32 param_size)
{
	return VfxAppLauncher::launch(
		VAPP_TIMER_IND,
		VFX_OBJ_CLASS_INFO(VappTimerIndApp),
		GRP_ID_ROOT,
		param,
		param_size);
}

void vapp_timer_stop_ring(void);
void vapp_timer_auto_terminate(void);

/***************************************************************************** 
 * Class VappTimerIndApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappTimerIndApp", VappTimerIndApp, VfxApp);

void VappTimerIndApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

	VfxAppScr *scr = NULL;
	
	VFX_OBJ_CREATE(scr, VappTimerIndicationScr, this);

	if (scr != NULL)
	{
		scr->show();
	}
}

void VappTimerIndApp::onGroupInactive()
{
	VfxApp::onGroupActive();
	vapp_timer_stop_ring();
}

/***************************************************************************** 
 * Class VappTimerIndicationScr
 *****************************************************************************/

VappTimerIndicationScr::VappTimerIndicationScr()
{
	setIsSmallScreen();
}

void VappTimerIndicationScr::onInit(void)
{
	VfxAppScr::onInit();

	setBgColor(VFX_COLOR_TRANSPARENT);

	VFX_OBJ_CREATE(m_popup, VappTimerIndicationPopup, this);
	m_popup->setText(STR_ID_VAPP_TIMER_IND_TIME_OUT);
	m_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
	m_popup->setInfoType(VCP_POPUP_TYPE_INFO);
	m_popup->m_signalButtonClicked.connect(this, &VappTimerIndicationScr::onBtnClick);
}

void VappTimerIndicationScr::onEnter(VfxBool isBackward)
{
	VfxAppScr::onEnter(isBackward);
	if (m_popup != NULL)
	{
		m_popup->show(VFX_TRUE);
	}
    else
    {
      exit();
    }
}

void VappTimerIndicationScr::onBtnClick(VfxObject* obj, VfxId id)
{
	// press "ok" and stop ring and so on
    mmi_event_struct evt;
	g_timer_cntx.time_run_flag = VFX_FALSE;
	g_timer_cntx.time_out_flag = VFX_FALSE;
	
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_TIMER_IND_RESET);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_END);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
	
	exit();
}

/***************************************************************************** 
 * Class VappTimerIndicationPopup
 *****************************************************************************/
void VappTimerIndicationPopup::onInit(void)
{
	VcpConfirmPopup::onInit();
		
	mmi_frm_cb_reg_event(EVT_ID_NMGR_PLAY_TONE, VappTimerIndicationPopup::onEvtHdlr, this);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappTimerIndicationPopup::onEvtHdlr, this);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappTimerIndicationPopup::onEvtHdlr, this);
	
	mmi_frm_start_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);

	StartTimer(MMI_TIMER_AUTO_STOP_RING, VAPP_TIMER_AUTO_STOP_RING, vapp_timer_auto_terminate);
}

void VappTimerIndicationPopup::onDeinit(void)
{
	vapp_timer_stop_ring();
	mmi_frm_cb_dereg_event(EVT_ID_NMGR_PLAY_TONE, VappTimerIndicationPopup::onEvtHdlr, this);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappTimerIndicationPopup::onEvtHdlr, this);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappTimerIndicationPopup::onEvtHdlr, this);
	
	mmi_frm_end_scenario(MMI_SCENARIO_ID_REMINDER_ALARM);
	VcpConfirmPopup::onDeinit();
}
	
VfxBool VappTimerIndicationPopup::onKeyInput(VfxKeyEvent & event)
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
			
		    return VcpConfirmPopup::onKeyInput(event);
	    }
    }	
	return VFX_TRUE;
}

mmi_ret VappTimerIndicationPopup::onEvtHdlr(mmi_event_struct *evt)
{
	VappTimerIndicationPopup *popup = (VappTimerIndicationPopup *)evt->user_data;
	switch (evt->evt_id)
	{
        case EVT_ID_GPIO_BACKLIGHT_DIMMING:
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
			if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
			{
				break;
			}
			else
			{
    			return MMI_RET_ERR;
			}
		case EVT_ID_NMGR_PLAY_TONE:
			{
				popup->playTone();
				break;
			}
		default:
			break;
	}
	
	return MMI_RET_OK;
}

void VappTimerIndicationPopup::playTone(void)
{
	mdi_audio_suspend_background_play();
	if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
	{
		srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, SRV_PROF_TONE_SMS_INCALL, SRV_PROF_RING_TYPE_ONCE, NULL);
		return;
	}
	
    srv_prof_play_req_struct play_req;    
    srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_ALARM);
    
    play_req.volume = 4;
    play_req.aud_path = MDI_DEVICE_SPEAKER_BOTH;
    play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;        
    play_req.audio_id = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING, 0);
    play_req.callback = NULL;
    play_req.audio_type = SRV_PROF_AUDIO_STRING;
    
    srv_prof_play_tone_with_full_struct(&play_req);
}

void vapp_timer_stop_ring(void)
{
	srv_prof_stop_tone(SRV_PROF_TONE_ALARM); 
	g_timer_cntx.time_out_flag = VFX_FALSE;
	mdi_audio_resume_background_play();
}
void vapp_timer_auto_terminate(void)
{
	if (VfxAppLauncher::findApp(VAPP_TIMER_IND, 
								VFX_OBJ_CLASS_INFO(VappTimerIndApp),
								VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG))
	{
		VfxAppLauncher::terminate(VAPP_TIMER_IND);
	}
	if (IsMyTimerExist(MMI_TIMER_AUTO_STOP_RING))
	{
		StopTimer(MMI_TIMER_AUTO_STOP_RING);
	}
	vapp_timer_stop_ring();
}