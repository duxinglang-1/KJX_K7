/*****************************************************************************
* Copyright Statement:
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
 *  vapp_screen_lock_key_unlockitem.cpp
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
#include "vapp_screen_lock_key_unlockitem.h"

/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * VappScreenLockKeyUnlockItem
 *****************************************************************************/

const VfxS32 VappScreenLockKeyUnlockItem::s_breathMap[] = {0, 1, 2, 3, 2, 1};

VFX_IMPLEMENT_CLASS("VappScreenLockKeyUnlockCard", VappScreenLockKeyUnlockItem, IVappScreenLockKeyUnlock);

void VappScreenLockKeyUnlockItem::onInit()
{
	VfxControl::onInit();

	m_breathStep = 0;

	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	m_bg->setAnchor(0.5, 0.5);
	
	VFX_OBJ_CREATE(m_card, VfxImageFrame, this);
	m_card->setAnchor(0.5, 0.5);
	
	//VFX_OBJ_CREATE(m_timerBreath, VfxTimer, this);

	VFX_OBJ_CREATE(m_timelineBgOp, VfxFloatTimeline, this);
	VFX_OBJ_CREATE(m_timelineCardOp, VfxFloatTimeline, this);
	VFX_OBJ_CREATE(m_timelineNotifyOp, VfxFloatTimeline, this);
	VFX_OBJ_CREATE(m_timelineBgPos, VfxPointTimeline, this);
	VFX_OBJ_CREATE(m_timelineCardPos, VfxPointTimeline, this);
	VFX_OBJ_CREATE(m_timelineBreath, VfxFloatTimeline, this);

	m_timelineBgPos->m_signalStopped.connect(this, &VappScreenLockKeyUnlockItem::onSlideIn);
	m_timelineCardPos->m_signalStopped.connect(this, &VappScreenLockKeyUnlockItem::onSlideIn);
	m_timelineBreath->m_signalStopped.connect(this, &VappScreenLockKeyUnlockItem::onBreathStop);
}

void VappScreenLockKeyUnlockItem::onDeinit()
{
	stopTimeline(NULL, VFX_FALSE);
	VfxControl::onDeinit();
}

void VappScreenLockKeyUnlockItem::initComponents()
{

}

void VappScreenLockKeyUnlockItem::setDirection(VappScreenLockKeyDirectionEnum direction)
{
	m_direction = direction;
}

void VappScreenLockKeyUnlockItem::enterIdleState()
{
	//m_timerBreath->stop();
	stopTimeline(NULL, VFX_FALSE);
	m_bg->setResId(m_bgResId);
	initComponents();
}

void VappScreenLockKeyUnlockItem::onEnterOperationState()
{	
	m_timelineBgPos->m_signalStopped.connect(this, &VappScreenLockKeyUnlockItem::onBgSlideIn);
	unlockSlideIn();
}

void VappScreenLockKeyUnlockItem::onEnterBackToNormalState()
{
	unlockSlideOut();
}

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

void VappScreenLockKeyUnlockItem::enterBackToNormalState()
{
	/* notify */
	if (m_notify)
	{
		opacityAnimationHdlr(
			m_timelineNotifyOp,
			m_notify,
			1.0,
			0.0,
			VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION,
			0);
	}
}

void VappScreenLockKeyUnlockItem::enterUnlockSelectState(VappScreenLockKeyDirectionEnum direction)
{
	if (m_direction == direction)
	{
		m_bg->setResId(m_selectResId);
	}
}

void VappScreenLockKeyUnlockItem::enterUnlockUnselectState(VappScreenLockKeyDirectionEnum direction)
{
	if (m_direction == direction)
	{
		m_bg->setResId(m_bgResId);
	}
}
        
#else	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

void VappScreenLockKeyUnlockItem::enterCentryTapState()
{
	onBreath();
}

void VappScreenLockKeyUnlockItem::enterCentryTapFromNormalState()
{
	m_timelineBgPos->m_signalStopped.connect(this, &VappScreenLockKeyUnlockItem::onBgEnteredCentryTap);
	unlockSlideIn();
}

void VappScreenLockKeyUnlockItem::enterUnlockTapState(VappScreenLockKeyDirectionEnum direction)
{
	if (m_direction == direction)
	{
		m_timerBreath->stop();
		m_bg->setResId(m_breathBaseResId + VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BREATH_STEP/2);
	}
}

void VappScreenLockKeyUnlockItem::enterUnlockRestoreState(VappScreenLockKeyDirectionEnum direction)
{
	if (m_direction == direction)
	{
		onBreath();
	}
}

void VappScreenLockKeyUnlockItem::onBgEnteredCentryTap(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	if (isComplete)
	{
		timeline->stop();
		timeline->m_signalStopped.disconnect(this, &VappScreenLockKeyUnlockItem::onBgEnteredCentryTap);
		m_bg->setPos(getBgOperationPos());
		onBreath();
		m_signalEnteredCentryTap.emit();
	}
}

#endif	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

void VappScreenLockKeyUnlockItem::enterUnlockState(VappScreenLockKeyDirectionEnum direction)
{
	if (m_direction == direction)
	{
		onUnlock();
	}
}

void VappScreenLockKeyUnlockItem::onUnlock()
{

}

void VappScreenLockKeyUnlockItem::unlockSlideIn()
{
	/* bg pos */
	m_bg->setHidden(VFX_FALSE);
	posAnimationHdlr(
		m_timelineBgPos, 
		m_bg, 
		getBgNormalPos(), 
		getBgOperationPos(), 
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION,
		0);

	opacityAnimationHdlr(
		m_timelineBgOp,
		m_bg,
		0.0,
		1.0,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION,
		0);
		
	/* card pos */
	m_card->setHidden(VFX_FALSE);
	posAnimationHdlr(
		m_timelineCardPos, 
		m_card, 
		getCardNormalPos(), 
		getCardOperationPos(), 
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION - VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION);

	opacityAnimationHdlr(
		m_timelineCardOp,
		m_card,
		0.0,
		1.0,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION - VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION);

}

void VappScreenLockKeyUnlockItem::unlockSlideOut()
{
	/* card pos */
	posAnimationHdlr(
		m_timelineCardPos, 
		m_card, 
		getCardOperationPos(), 
		getCardNormalPos(), 
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION);

	opacityAnimationHdlr(
		m_timelineCardOp,
		m_card,
		1.0,
		0.0,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION);
	
	/* bg pos */
	posAnimationHdlr(
		m_timelineBgPos, 
		m_bg, 
		getBgOperationPos(),
		getBgNormalPos(),	 
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION);

	opacityAnimationHdlr(
		m_timelineBgOp,
		m_bg,
		1.0,
		0.0,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION,
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION);
}

void VappScreenLockKeyUnlockItem::onBgSlideIn(VfxBaseTimeline *timeline, VfxBool isComplete)
{
	if (isComplete)
	{
		timeline->stop();
		timeline->m_signalStopped.disconnect(this, &VappScreenLockKeyUnlockItem::onBgSlideIn);
		m_signalBgSlideIn.emit();
	}
}

void VappScreenLockKeyUnlockItem::onBreath()
{
	m_bg->setHidden(VFX_FALSE);
	m_card->setHidden(VFX_FALSE);
	
	m_bg->setResId(m_selectResId);
	opacityAnimationHdlr(m_timelineBreath, this, 1.0, 0.5, 777, 0);	
	
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

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
#endif

void VappScreenLockKeyUnlockItem::onBreathStop(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	if (isComplete)
	{
		VfxFloatTimeline *tl = (VfxFloatTimeline*)timeline;
		tl->stop();
		opacityAnimationHdlr(
			tl,
			this,
			tl->getToValue(),
			tl->getFromValue(),
			tl->getDuration(),
			tl->getStartTime());
	}
}


void VappScreenLockKeyUnlockItem::onSlideIn(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	if (isComplete)
	{
		timeline->stop();
		VfxFrame* frame = (VfxFrame*)timeline->getTarget();
		VfxPoint pos = ((VfxPointTimeline*)timeline)->getToValue();
		frame->setPos(pos);
	}
}

void VappScreenLockKeyUnlockItem::showNotify()
{
	if (m_notify && m_bg->getPos() != getBgNormalPos())
	{
		m_notify->setHidden(VFX_FALSE);
		opacityAnimationHdlr(
			m_timelineNotifyOp,
			m_notify,
			0.0,
			1.0,
			VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION,
			0);
	}	
}

void VappScreenLockKeyUnlockItem::stopTimeline(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	m_timelineBgOp->stop();
	m_timelineCardOp->stop();
	m_timelineNotifyOp->stop();
	m_timelineBgPos->stop();
	m_timelineCardPos->stop();
	m_timelineBreath->stop();
}

void VappScreenLockKeyUnlockItem::posAnimationHdlr(
	VfxPointTimeline * timeline,
	VfxAnimatable * target,
	VfxPoint fromValue,
	VfxPoint toValue,
	VfxMsec duration,
	VfxMsec startTime)
{
	timeline->setTarget(target);
	timeline->setFromValue(fromValue);
	timeline->setToValue(toValue);
	timeline->setDuration(duration);
	timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
	timeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
	timeline->setStartTime(startTime);
	timeline->start();
}

void VappScreenLockKeyUnlockItem::opacityAnimationHdlr(
	VfxFloatTimeline * timeline,
	VfxAnimatable * target,
	VfxFloat fromValue,
	VfxFloat toValue,
	VfxMsec duration,
	VfxMsec startTime)
{
	timeline->setTarget(target);
	timeline->setFromValue(fromValue);
	timeline->setToValue(toValue);
	timeline->setDuration(duration);
	timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
	timeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
	timeline->setStartTime(startTime);
	timeline->start();
}

void VappScreenLockKeyUnlockItem::setBgNormalPos(VfxPoint pos)
{
	m_bgNormalPos = pos;
}

VfxPoint VappScreenLockKeyUnlockItem::getBgNormalPos()
{
	return m_bgNormalPos;
}

void VappScreenLockKeyUnlockItem::setBgOperationPos(VfxPoint pos)
{
	m_bgOperationPos = pos;
}

VfxPoint VappScreenLockKeyUnlockItem::getBgOperationPos()
{
	return m_bgOperationPos;
}

void VappScreenLockKeyUnlockItem::setCardNormalPos(VfxPoint pos)
{
	m_cardNormalPos = pos;
}

VfxPoint VappScreenLockKeyUnlockItem::getCardNormalPos()
{
	return m_cardNormalPos;
}

void VappScreenLockKeyUnlockItem::setCardOperationPos(VfxPoint pos)
{
	m_cardOperationPos = pos;
}

VfxPoint VappScreenLockKeyUnlockItem::getCardOperationPos()
{
	return m_cardOperationPos;
}

VfxPoint VappScreenLockKeyUnlockItem::getExternalCenter()
{
	return VfxPoint(getPos().x + m_bg->getSize().width/2, getPos().y + m_bg->getSize().height/2);
}

VfxPoint VappScreenLockKeyUnlockItem::getInternalCenter()
{
	return VfxPoint(m_bg->getSize().width/2, m_bg->getSize().height/2);
}

VfxS32 VappScreenLockKeyUnlockItem::getRadius()
{
	return m_card->getSize().width/2;
}


#endif

