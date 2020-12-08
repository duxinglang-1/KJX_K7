/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_screen_lock_key_main.cpp
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_launcher_key_clock.h"
#include "vapp_screen_lock_key_unlock.h"
#include "vapp_screen_lock_key_unlockitem.h"
#include "vapp_screen_lock_key_arrow.h"
#include "vapp_screen_lock_key_main.h"
#include "vapp_screen_lock_key_factory.h"
#include "vapp_screen_lock_key_unlock_centry.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#if defined(__MMI_NCENTER_SUPPORT__)
#include "vapp_screen_lock_key_notification.h"
#include "vapp_ncenter_gprot.h"
#endif

/* wallpaper */
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_wallpaper_kit.h"

#include "vfx_sys_mem_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "wgui.h"
#include "GlobalResDef.h"
#include "gpiosrvgprot.h"
#include "PhoneSetupGprots.h"	//wallpaper
#include "ScrlockerScreenLockKey.h"

#ifdef __cplusplus
}
#endif

static VappScreenLockKeyMain *g_vapp_screen_lock_key = NULL;

/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * VappScreenLockKeyMain
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockKeyMain", VappScreenLockKeyMain, VfxAppCatScr);

/*----------------------------------------------------------------*/
/* initialize				                              		  */
/*----------------------------------------------------------------*/

void VappScreenLockKeyMain::onInit()
{
	VfxAppCatScr::onInit();

	setSize(LCD_WIDTH, LCD_HEIGHT);

	createWallpaper();
	createClock();
	createStatusIconBar();		
	createUnlock();
#if defined(__MMI_NCENTER_SUPPORT__)
	createNotification();
#endif
	connectSignals();
	registerCBEvent();
	setBacklight();

	VFX_OBJ_CREATE(m_timelineSlide, VfxPointTimeline, this);
	m_timelineSlide->m_signalStopped.connect(this, &VappScreenLockKeyMain::onSlideOver);

	enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_IDLE);
	
	VappScreenLockKeyStateEnum state = (VappScreenLockKeyStateEnum)vapp_screen_lock_key_get_stored_state();

	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_INIT_STATE, state));

	switch (state)
	{	
		case VAPP_SCREEN_LOCK_KEY_STATE_NORMAL:
			switchBacklight(VFX_TRUE);
			enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_NORMAL);
			break;

		case VAPP_SCREEN_LOCK_KEY_STATE_OPERATION:
			switchBacklight(VFX_TRUE);
			enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
			break;

		default:
			switchBacklight(VFX_FALSE);	
			break;
	}
		
}

void VappScreenLockKeyMain::onDeinit()
{	
	VAPP_LOCK_UNLOCK_ANIMATION();

	deregisterCBEvent();
	resetBacklight();
	destroyWallpaper();	
	storeScreenLockState();
	
	VfxAppCatScr::onDeinit();
}

void VappScreenLockKeyMain::storeScreenLockState()
{
	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_DEINIT_STATE, m_state));

	switch (m_state)
	{
		case VAPP_SCREEN_LOCK_KEY_STATE_NORMAL:
		case VAPP_SCREEN_LOCK_KEY_STATE_BACK_TO_NORMAL:
			vapp_screen_lock_key_store_state((VfxU32)VAPP_SCREEN_LOCK_KEY_STATE_NORMAL);
			break;

		case VAPP_SCREEN_LOCK_KEY_STATE_OPERATION:
		case VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_MOVE:
		case VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_SELECT:
    	case VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_UNSELECT:
    	case VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_RESTORE:
			vapp_screen_lock_key_store_state((VfxU32)VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
			break;

		case VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP:
			vapp_screen_lock_key_store_state((VfxU32)m_prevState);
			break;
			
		default:
			vapp_screen_lock_key_store_state(VAPP_SCREEN_LOCK_KEY_STATE_IDLE);
			break;
	}
}

void VappScreenLockKeyMain::closeScreenLock()
{
	mmi_scr_locker_close();
}

VfxBool VappScreenLockKeyMain::isBacklightOn()
{
	return srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD);
}

void VappScreenLockKeyMain::setBacklight()
{
	srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP, VAPP_SCREEN_LOCK_KEY_WATCHDOG_DURATION, 0);
}

void VappScreenLockKeyMain::resetBacklight()
{
	srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
	if (vapp_screen_lock_key_check_emcall())
	{
		srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
	}
}

void VappScreenLockKeyMain::switchBacklight(VfxBool isOn)
{
	if (isOn)
	{
		srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
		m_isBacklightOn = VFX_TRUE;
	}
	else
	{
		srv_backlight_turn_off_ext();
		m_isBacklightOn = VFX_FALSE;
	}
}

/*----------------------------------------------------------------*/
/* components				                              		  */
/*----------------------------------------------------------------*/

void VappScreenLockKeyMain::createStatusIconBar()
{
	/* status icon bar */
	VFX_OBJ_CREATE(m_iconBar, VcpStatusIconBar, this);
    m_iconBar->enableBackground(VFX_FALSE);
}

void VappScreenLockKeyMain::createClock()
{
	VFX_OBJ_CREATE_EX(m_clock, VappLauncherKeyClock, this, (VfxPoint(0, 0)));
}

#if defined(__MMI_NCENTER_SUPPORT__)
void VappScreenLockKeyMain::createNotification()
{
	VFX_OBJ_CREATE(m_notify, VappScreenLockKeyNotification, this);
	m_notify->setPos((LCD_WIDTH - NOTI_WIDTH)>>1, m_clock->getSize().height);
	m_signalOnEnterState.connect(m_notify, &VappScreenLockKeyNotification::enterState);

	m_iconBar->setIsUnhittable(VFX_TRUE);
}
#endif

void VappScreenLockKeyMain::createUnlock()
{
	VfxPoint pos;

	/*----------------------------------------------------------------*/
	/* create unlock cards                                            */
	/*----------------------------------------------------------------*/
	/* up */
	m_unlockUp = VappScreenLockKeyFactory::getUnlock(VAPP_SCREEN_LOCK_KEY_UNLOCK_DEFAULT, this);
	m_unlockUp->setDirection(VAPP_SCREEN_LOCK_KEY_UNLOCK_UP);
	s_unlockTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_UP] = m_unlockUp;
	/* left */
	m_unlockLeft = VappScreenLockKeyFactory::getUnlock(VAPP_SCREEN_LOCK_KEY_UNLOCK_CALL_LOG, this);
	m_unlockLeft->setDirection(VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT);
	s_unlockTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT] = m_unlockLeft;
	/* right */
	m_unlockRight = VappScreenLockKeyFactory::getUnlock(VAPP_SCREEN_LOCK_KEY_UNLOCK_MESSAGE, this);
	m_unlockRight->setDirection(VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT);
	s_unlockTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT] = m_unlockRight;
	/* centry */
	m_unlockCentry = VappScreenLockKeyFactory::getUnlock(VAPP_SCREEN_LOCK_KEY_UNLOCK_LOCK, this);
	m_unlockCentry->setDirection(VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY);
	s_unlockTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY] = m_unlockCentry;

	/*----------------------------------------------------------------*/
	/* create arrows                                           		  */
	/*----------------------------------------------------------------*/
	/* up */
	VFX_OBJ_CREATE_EX(m_arrowUp, VappScreenLockKeyArrow, this, (VAPP_SCREEN_LOCK_KEY_UNLOCK_UP, IMG_ID_VAPP_SCRLOCK_ARROW_UP));
	m_arrowUp->setPos(VAPP_SCREEN_LOCK_KEY_ARROW_UP1_X, VAPP_SCREEN_LOCK_KEY_ARROW_UP1_Y);
	s_arrowTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_UP] = m_arrowUp;
	/* left */
	VFX_OBJ_CREATE_EX(m_arrowLeft, VappScreenLockKeyArrow, this, (VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT, IMG_ID_VAPP_SCRLOCK_ARROW_LEFT));
	m_arrowLeft->setPos(VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_X, VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_Y);
	s_arrowTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT] = m_arrowLeft;	
	/* right */
	VFX_OBJ_CREATE_EX(m_arrowRight, VappScreenLockKeyArrow, this, (VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT, IMG_ID_VAPP_SCRLOCK_ARROW_RIGHT));
	m_arrowRight->setPos(VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_X, VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_Y);
	s_arrowTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT] = m_arrowRight;

	m_unlockCentry->bringToFront();	
}

void VappScreenLockKeyMain::connectSignals()
{
	VfxS32 i;
	for (i = 0; i <= VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY; i++)
	{
		/*----------------------------------------------------------------*/
		/* unlock card connect signal                              		  */
		/*----------------------------------------------------------------*/

		m_signalOnEnterState.connect(s_unlockTbl[i], &VappScreenLockKeyUnlockItem::enterState);
			
		if (i == VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY)
			break;

		((VappScreenLockKeyUnlockCentry*)m_unlockCentry)->m_signalCentryResized.connect(s_unlockTbl[i], &VappScreenLockKeyUnlockItem::onEnterOperationState);

	#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
		s_arrowTbl[i]->m_signalArrowHidden.connect(s_unlockTbl[i], &VappScreenLockKeyUnlockItem::onEnterBackToNormalState);
	#endif
	
		/*----------------------------------------------------------------*/
		/* arrow connect signal 	                            		  */
		/*----------------------------------------------------------------*/

		((VappScreenLockKeyUnlockCentry*)m_unlockCentry)->m_signalCentryRestored.connect(s_arrowTbl[i], &VappScreenLockKeyArrow::onCentryRestored);

		m_signalOnEnterState.connect(s_arrowTbl[i], &VappScreenLockKeyArrow::enterState);

		s_unlockTbl[i]->m_signalBgSlideIn.connect(s_arrowTbl[i], &VappScreenLockKeyArrow::onEnterOperationState);

	#ifndef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
	 	s_unlockTbl[i]->m_signalEnteredCentryTap.connect(s_arrowTbl[i], &VappScreenLockKeyArrow::onEnterOperationState);
	#endif
	}

}

void VappScreenLockKeyMain::createWallpaper()
{
	m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_LOCK);
	VFX_ASSERT(m_wallpaper);

	m_wallpaper->suspend();

	//For performance, suspend it first
	VFX_OBJ_CREATE(m_timer, VfxTimer, this);
	m_timer->m_signalTick.connect(this, &VappScreenLockKeyMain::onResumeWallpaper);
	m_timer->setStartDelay(600);
    m_timer->start();
}

void VappScreenLockKeyMain::destroyWallpaper()
{
	if(m_wallpaper)
    {
    	m_wallpaper->suspend();
        VFX_OBJ_CLOSE(m_wallpaper);
    }
}

void VappScreenLockKeyMain::onResumeWallpaper(VfxTimer * timer)
{
	timer->stop();
	m_wallpaper->resume();
}

/*----------------------------------------------------------------*/
/* state machine			                              		  */
/*----------------------------------------------------------------*/

VappScreenLockKeyStateEnum VappScreenLockKeyMain::getState()
{
	return m_state;
}

void VappScreenLockKeyMain::enterScreenLockState(VappScreenLockKeyStateEnum state)
{	
	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_ENTER_STATE, m_state, state));

	VAPP_LOCK_CHECK_ANIMATION();

	if (state == VAPP_SCREEN_LOCK_KEY_STATE_OPERATION && state == m_state)
		return;

	switch (state)
	{
		case VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK:
			m_state = state;
			m_timelineSlide->setTarget(m_unlockCentry);
			m_timelineSlide->setFromValue(m_unlockCentry->getPos());
			m_timelineSlide->setToValue(getSlideToPos());
			m_timelineSlide->setDuration(VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_DURATION);
			m_timelineSlide->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
			m_timelineSlide->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
			m_timelineSlide->start();
			break;

		case VAPP_SCREEN_LOCK_KEY_STATE_OPERATION:
		case VAPP_SCREEN_LOCK_KEY_STATE_BACK_TO_NORMAL:
			VAPP_LOCK_LOCK_ANIMATION();
			m_signalOnEnterState.emit(state, m_centryMoveDirection);
			break;

		default:
			m_signalOnEnterState.emit(state, m_centryMoveDirection);
			break;
	}

	m_prevState = m_state;
	m_state = state;
}

void VappScreenLockKeyMain::rollbackScreenLockState(VappScreenLockKeyStateEnum state)
{
	m_state = state;
	m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_TOTAL;
}

void VappScreenLockKeyMain::onSlideOver(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	if (isComplete)
	{
		timeline->stop();
		m_signalOnEnterState.emit(m_state, m_centryMoveDirection);
	}
}

VfxPoint VappScreenLockKeyMain::getSlideToPos()
{
	VfxS32 x = 0, y = 0;
	switch (m_centryMoveDirection)
	{
		case VAPP_SCREEN_LOCK_KEY_UNLOCK_UP:
			return m_unlockUp->getPos();

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT:
			x = m_unlockLeft->getPos().x + m_unlockLeft->getSize().width/2;
			y = m_unlockLeft->getPos().y - m_unlockLeft->getSize().height/2;
			break;

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT:
			x = m_unlockRight->getPos().x - m_unlockLeft->getSize().width/2;
			y = m_unlockRight->getPos().y - m_unlockLeft->getSize().height/2;
			break;
	}

	return VfxPoint(x, y);
}

/*----------------------------------------------------------------*/
/* key event handling		                              		  */
/*----------------------------------------------------------------*/

void VappScreenLockKeyMain::registerCBEvent()
{
	mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_IN,   &VappScreenLockKeyMain::systemEventHdlr, this);
	mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_OUT,  &VappScreenLockKeyMain::systemEventHdlr, this);
	mmi_frm_cb_reg_event(EVT_ID_PRE_KEY_EVT_ROUTING, &VappScreenLockKeyMain::systemEventHdlr, this);
#ifdef __MMI_NCENTER_SUPPORT__
	mmi_frm_cb_reg_event(EVT_ID_VAPP_NCENTER_DRAG,   &VappScreenLockKeyMain::systemEventHdlr, this);
#endif
}

void VappScreenLockKeyMain::deregisterCBEvent()
{
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_IN,   &VappScreenLockKeyMain::systemEventHdlr, this);
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_OUT,  &VappScreenLockKeyMain::systemEventHdlr, this);
	mmi_frm_cb_dereg_event(EVT_ID_PRE_KEY_EVT_ROUTING, &VappScreenLockKeyMain::systemEventHdlr, this);
#ifdef __MMI_NCENTER_SUPPORT__
	mmi_frm_cb_dereg_event(EVT_ID_VAPP_NCENTER_DRAG,	 &VappScreenLockKeyMain::systemEventHdlr, this);
#endif

}

mmi_ret VappScreenLockKeyMain::systemEventHdlr(mmi_event_struct * event)
{
	VappScreenLockKeyMain* scrlock = (VappScreenLockKeyMain *)event->user_data;
	
    switch (event->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
            scrlock->lcdSleepInHdlr();
            break;

		case EVT_ID_GPIO_LCD_SLEEP_OUT:
			scrlock->lcdSleepOutHdlr();
			break;

		case EVT_ID_PRE_KEY_EVT_ROUTING:
			{
				VfxKeyEvent vEvt;
				mmi_frm_key_evt_struct *pEvt = (mmi_frm_key_evt_struct*)event;
				
				vEvt.keyCode = (VfxKeyCodeEnum)pEvt->key_code;
				vEvt.type = (VfxKeyEventTypeEnum)pEvt->key_type;
					
				return scrlock->onKeyInputDragUnlock(vEvt);
			}
			break;

	#ifdef __MMI_NCENTER_SUPPORT__
		case EVT_ID_VAPP_NCENTER_DRAG:
			return MMI_RET_ERR;
	#endif
	
        default:
            break;
    }
	
    return MMI_RET_OK;
}

void VappScreenLockKeyMain::lcdSleepInHdlr()
{
	if(m_wallpaper)
    {
    	m_wallpaper->suspend();
    }
	enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_IDLE);
	m_isBacklightOn = VFX_FALSE;
}

void VappScreenLockKeyMain::lcdSleepOutHdlr()
{
	if(m_wallpaper)
    {
    	m_wallpaper->resume();
    }
	enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_NORMAL);
	m_isBacklightOn = VFX_TRUE;
}

#if 0
/* under construction !*/
/* under construction !*/
#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
/* under construction !*/
#else	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/
/* under construction !*/
#endif	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

mmi_ret VappScreenLockKeyMain::onKeyInputDragUnlock(VfxKeyEvent & event)
{
	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_KEY_INPUT, event.keyCode, event.type));

	if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		if (!isBacklightOn())
		{		
			switch (event.keyCode)
			{
				case VFX_KEY_CODE_CSK:
					switchBacklight(VFX_TRUE);
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP);					
					break;

				case VFX_KEY_CODE_LSK:
				case VFX_KEY_CODE_RSK:
				case VFX_KEY_CODE_END:
				case VFX_KEY_CODE_POWER:
					switchBacklight(VFX_TRUE);
					break;

				default:
					break;
			}
		}
		else
		{	
			if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_IDLE || m_state == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL)
			{
				switch (event.keyCode)
				{
					case VFX_KEY_CODE_CSK:
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP);
						break;
				#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
					case VFX_KEY_CODE_POWER:
						switchBacklight(VFX_FALSE);
						break;
				#endif
					default:
						break;
				}
			}
			else if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_OPERATION)
			{
				switch (event.keyCode)
				{
					case VFX_KEY_CODE_CSK:
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP);
						break;
						
					case VFX_KEY_CODE_ARROW_UP:
						m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_UP;
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
						break;

					case VFX_KEY_CODE_ARROW_LEFT:
						m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT;
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
						break;

					case VFX_KEY_CODE_ARROW_RIGHT:
						m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT;
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
						break;
				#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
					case VFX_KEY_CODE_POWER:
						switchBacklight(VFX_FALSE);
						break;
				#endif
					default:
						break;
				}
			}
		}
	}
	else if (event.type == VFX_KEY_EVENT_TYPE_UP)
	{
		switch (event.keyCode)
		{
			case VFX_KEY_CODE_CSK:
				if (m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_OPERATION)
				{
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_BACK_TO_NORMAL);
					rollbackScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_NORMAL);
				}
				else if(m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL || m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_IDLE)
				{
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
				}
				break;

			default:
				break;
		}
	}

	if (isBacklightOn())
	{
		/* call srv_backlight_turn_on to restart backlight timer */
		switchBacklight(VFX_TRUE);
	}

	return MMI_RET_OK;
}

#else	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

void VappScreenLockKeyMain::onKeyInputTapUnlock(VfxKeyEvent & event)
{
	if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		if (!isBacklightOn())
		{		
			switch (event.keyCode)
			{
				case VFX_KEY_CODE_CSK:
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
					switchBacklight(VFX_TRUE);
					break;

				case VFX_KEY_CODE_LSK:
				case VFX_KEY_CODE_RSK:
				case VFX_KEY_CODE_END:
				case VFX_KEY_CODE_POWER:
					switchBacklight(VFX_TRUE);
					break;

				default:
					break;
			}
		}
		else
		{
			if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL)
			{
				switch (event.keyCode)
				{
					case VFX_KEY_CODE_CSK:
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
						break;
				#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
					case VFX_KEY_CODE_POWER:
						switchBacklight(VFX_FALSE);
						break;
				#endif
					default:
						break;
				}
			}
			else if (m_state >= VAPP_SCREEN_LOCK_KEY_STATE_OPERATION && m_state <= VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP_FROM_NORMAL)
			{
				switch (event.keyCode)
				{
					case VFX_KEY_CODE_ARROW_UP:
						m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_UP;
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
						break;

					case VFX_KEY_CODE_ARROW_LEFT:
						m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT;
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
						break;

					case VFX_KEY_CODE_ARROW_RIGHT:
						m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT;
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
						break;
				#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
					case VFX_KEY_CODE_POWER:
						switchBacklight(VFX_FALSE);
						break;
				#endif
					default:
						break;
				}
			}
		}
	}
}

#endif	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

/*----------------------------------------------------------------*/
/* pen event handling		                              		  */
/*----------------------------------------------------------------*/

VfxBool VappScreenLockKeyMain::onPenInput(VfxPenEvent & event)
{
#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
	onPenInputDragUnlock(event);
#else
	onPenInputTapUnlock(event);
#endif
		
	return VFX_TRUE;
}

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

void VappScreenLockKeyMain::onPenInputDragUnlock(VfxPenEvent & event)
{
	switch (event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:
			if (isTapUnlockCard(event.pos, m_unlockCentry))
			{
				m_isCentryTapped = VFX_TRUE;
				enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP);
			}
			break;

		case VFX_PEN_EVENT_TYPE_MOVE:
			m_isPenMoved = VFX_TRUE;

			if (!m_isCentryTapped)
				return;

			if (m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_OPERATION || m_state == VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_MOVE || m_state == VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_SELECT)
			{
				if (m_wallpaper && !m_wallpaper->isSuspended())
				{
					m_wallpaper->suspend();
				}
			
				m_unlockCentry->setPos(
					m_unlockCentry->getPos().x + event.pos.x - event.prevPos.x, 
					m_unlockCentry->getPos().y + event.pos.y - event.prevPos.y);
				
				updateCentryMoveDirection(event);
				enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_MOVE);
				
				if (isCatchUnlockCard())
				{
					m_isUnlockSelected = VFX_TRUE;
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_SELECT);
				}
				else if (m_isUnlockSelected)
				{
					m_isUnlockSelected = VFX_FALSE;
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_UNSELECT);
					rollbackScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_MOVE);
				}
			}
			else if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP)
			{
				if (!isTapUnlockCard(event.pos, m_unlockCentry))
				{
					m_isCentryTapped = VFX_FALSE;
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
				}
			}
			break;
	
		case VFX_PEN_EVENT_TYPE_UP:
			//m_isPenMoved = VFX_FALSE;
						
			if (!m_isCentryTapped)
				return;
			
			if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP)
			{
				if (!m_isPenMoved)
				{
					if (m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_OPERATION)
					{
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_BACK_TO_NORMAL);
						rollbackScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_NORMAL);
					}
					else if (m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_IDLE || m_prevState == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL)
					{
						enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
					}
				}
				else if (isTapUnlockCard(event.pos, m_unlockCentry))
				{
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);
				}				
			}
			else if (m_isUnlockSelected)
			{
				enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
			}
			else if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_MOVE)
			{
				m_unlockCentry->setPos(
					m_unlockCentry->getPos().x + event.pos.x - event.prevPos.x, 
					m_unlockCentry->getPos().y + event.pos.y - event.prevPos.y);
				
				enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_RESTORE);
				rollbackScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_OPERATION);

				if (m_wallpaper)
				{
					m_wallpaper->resume();
				}
			}

			m_isCentryTapped = VFX_FALSE;
			m_isPenMoved = VFX_FALSE;
			break;
		
		case VFX_PEN_EVENT_TYPE_ABORT:
			break;

		default:
			break;
	}
}

#else	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

void VappScreenLockKeyMain::onPenInputTapUnlock(VfxPenEvent & event)
{
	switch (event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:
			{			
				VappScreenLockKeyUnlockItem *card = getTappedCard(event.downPos);

				if (card == NULL)
					return;
				
				switch(card->m_direction)
				{
					case VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY:
						m_isTapCentryCard = VFX_TRUE;
						if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL)
						{
							enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP_FROM_NORMAL);
						}
						else if (m_state == VAPP_SCREEN_LOCK_KEY_STATE_OPERATION)
						{
							enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP);
						}
						
						break;

					case VAPP_SCREEN_LOCK_KEY_UNLOCK_UP:
					case VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT:
					case VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT:
						if (m_isTapCentryCard == VFX_TRUE)
						{
							//m_isTapCentryCard = VFX_FALSE;
							m_isTapUnlockCard = VFX_TRUE;
							m_centryMoveDirection = card->m_direction;
							enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_TAP);
						}
						break;

					default:
						break;
				}
			}
			break;

		case VFX_PEN_EVENT_TYPE_MOVE:
			if (m_isTapUnlockCard == VFX_TRUE)
			{
				if (!isTapUnlockCard(event.pos, s_unlockTbl[m_centryMoveDirection]))
				{
					m_isTapUnlockCard = VFX_FALSE;
					enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_RESTORE);
					rollbackScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_TAP);
					m_isTapCentryCard = VFX_TRUE;
				}
			}
			break;
	
		case VFX_PEN_EVENT_TYPE_UP:
			if (m_isTapUnlockCard == VFX_TRUE)
			{
				m_isTapUnlockCard = VFX_FALSE;
				enterScreenLockState(VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK);
			}
			break;
		
		case VFX_PEN_EVENT_TYPE_ABORT:
			break;

		default:
			break;
	}
}

#endif	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

VfxBool VappScreenLockKeyMain::isTapUnlockCard(VfxPoint pos, VappScreenLockKeyUnlockItem * card)
{
	switch (card->m_direction)
	{
		case VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY:
			return ((pos.x - card->getPos().x) * (pos.x - card->getPos().x) 
				  + (pos.y - card->getPos().y) * (pos.y - card->getPos().y)
				  <  card->getRadius() * card->getRadius());
			
		case VAPP_SCREEN_LOCK_KEY_UNLOCK_UP:
			return (pos.x > card->getPos().x - card->getSize().width/2)
				&& (pos.x < card->getPos().x + card->getSize().width/2)
				&& (pos.y > card->getPos().y - card->getSize().height/2)
				&& (pos.y < card->getPos().y + card->getSize().height/2);

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT:
			return (pos.x > card->getPos().x)
				&& (pos.x < card->getPos().x + card->getSize().width)
				&& (pos.y > card->getPos().y - card->getSize().height)
				&& (pos.y < card->getPos().y);

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT:
			return (pos.x > card->getPos().x - card->getSize().width)
				&& (pos.x < card->getPos().x)
				&& (pos.y > card->getPos().y - card->getSize().height)
				&& (pos.y < card->getPos().y);

		default:
			return VFX_FALSE;
	}
}

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

VfxBool VappScreenLockKeyMain::updateCentryMoveDirection(VfxPenEvent & event)
{
	VappScreenLockKeyDirectionEnum direction = m_centryMoveDirection;

	VfxS32 x1 = m_unlockCentry->getPos().x;
	VfxS32 y1 = m_unlockCentry->getPos().y;
	VfxS32 x2 = ((VappScreenLockKeyUnlockCentry*)m_unlockCentry)->getCardOperationPos().x;
	VfxS32 y2 = ((VappScreenLockKeyUnlockCentry*)m_unlockCentry)->getCardOperationPos().y;

	if (y1 >= y2)
	{
		if (x1 > x2)
		{
			m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT;
		}
		else if (x1 < x2)
		{
			m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT;
		}
	}
	else
	{
		VfxFloat slope = (VfxFloat)(-(y1 - y2)) / (VfxFloat)(x1 - x2);
		
		if (slope > 1.0f || slope < -1.0f)
		{
			m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_UP;
		}
		else if (-1.0f <= slope && slope < 0.0f)
		{
			m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT;
		}
		else if (0.0f <= slope && slope < 1.0f)
		{
			m_centryMoveDirection = VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT;
		}
	}	
	return (direction != m_centryMoveDirection);
}

VfxBool VappScreenLockKeyMain::isCatchUnlockCard()
{
	if (m_centryMoveDirection == VAPP_SCREEN_LOCK_KEY_UNLOCK_TOTAL)
		return VFX_FALSE;

	//VfxS32 r1 = m_unlockCentry->getSize().width/2;
	VfxS32 r1 = m_unlockCentry->getRadius();
	VfxS32 x1 = m_unlockCentry->getPos().x;
	VfxS32 y1 = m_unlockCentry->getPos().y;

	VappScreenLockKeyUnlockItem *card = s_unlockTbl[m_centryMoveDirection];
	VfxS32 r2 = card->getRadius() * 1.3;
	VfxS32 x2 = 0, y2 = 0;

	switch (card->m_direction)
	{
		case VAPP_SCREEN_LOCK_KEY_UNLOCK_UP:
			x2 = card->getPos().x;
			y2 = card->getPos().y + 20;
			break;

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT:
			x2 = card->getPos().x + card->getSize().width/2;
			y2 = card->getPos().y - card->getSize().height/2;
			break;

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT:
			x2 = card->getPos().x - card->getSize().width/2;
			y2 = card->getPos().y - card->getSize().height/2;
			break;

		default:
			VFX_ASSERT(0);
	}

	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 + r2) * (r1 + r2));
}

#else	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

VappScreenLockKeyUnlockItem* VappScreenLockKeyMain::getTappedCard(VfxPoint pos)
{
	VfxS32 i;
	for (i = 0; i < VAPP_SCREEN_LOCK_KEY_UNLOCK_TOTAL; i++)
	{
		if (isTapUnlockCard(pos, s_unlockTbl[i]))
		{
			return s_unlockTbl[i];
		}
	}

	return NULL;
}

#endif	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/


/*****************************************************************************
 * entry function for pluto
 *****************************************************************************/

extern "C" VfxS32 vapp_screen_lock_key_init(void)
{
	if (vfx_sys_mem_config_is_vrt_able_to_run(VAPP_SCREEN_LOCK_KEY_RUN_MEM_SIZE))
        {
	    VfxAppCatScr::initalizeWithScrAsmSize(VAPP_SCREEN_LOCK_KEY_RUN_MEM_SIZE);
	    VFX_OBJ_CREATE(g_vapp_screen_lock_key, VappScreenLockKeyMain, VcpAppScr::getContext());
	    return 0;
	}
	else
	{
		return -1;
	}
}

extern "C" void vapp_screen_lock_key_get_img_size(VfxS32 *dest_w, VfxS32 *dest_h)
{
	*dest_w = VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_WIDTH;
	*dest_h = VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_HEIGHT;
}

extern "C" void vapp_screen_lock_key_deinit(void)
{
	VFX_OBJ_CLOSE(g_vapp_screen_lock_key);
	VfxAppCatScr::deinitalize();
}


#endif

