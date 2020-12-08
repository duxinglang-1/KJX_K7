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
 *  vapp_screen_lock_key_arrow.cpp
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
#include "vapp_screen_lock_key_arrow.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"


/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * VappScreenLockKeyArrow
 *****************************************************************************/

const VfxFloat VappScreenLockKeyArrow::s_opacityTbl[] = {0.6f, 0.7f, 0.8f, 0.9f};

//VAPP_SCREEN_LOCK_KEY_UNLOCK_IMPLEMENT_CLASS(VappScreenLockKeyArrow, IVappScreenLockKeyUnlock);

void VappScreenLockKeyArrow::onInit()
{
	VfxFrame::onInit();

	VFX_OBJ_CREATE(m_arrowInside, VfxImageFrame, this);
	m_arrowInside->setResId(m_imgId);

	VFX_OBJ_CREATE(m_arrowOutside, VfxImageFrame, this);
	m_arrowOutside->setResId(m_imgId);

	VFX_OBJ_CREATE(m_timerBreath, VfxTimer, this);

	VFX_OBJ_CREATE(m_timelineOp, VfxFloatTimeline, this);
	m_timelineOp->m_signalStopped.connect(this, &VappScreenLockKeyArrow::onOpacityChanged);
	
	initLayout();
}

void VappScreenLockKeyArrow::onDeinit()
{
	m_timelineOp->stop();
	m_timerBreath->stop();
	
	VfxControl::onDeinit();
}

void VappScreenLockKeyArrow::initLayout()
{
	switch(m_direction)
	{
		case VAPP_SCREEN_LOCK_KEY_UNLOCK_UP:
			m_arrowOutside->setPos(0, 0);
			m_arrowInside->setPos(0, m_arrowOutside->getBounds().getHeight() + 1);
			setSize(m_arrowOutside->getSize().width, m_arrowOutside->getSize().height * 2 + 1);
			break;

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT:
			m_arrowOutside->setPos(0, 0);
			m_arrowInside->setPos(m_arrowOutside->getBounds().getWidth() + 1, 0);
			setSize(m_arrowOutside->getSize().width * 2 + 1, m_arrowOutside->getSize().height);
			break;

		case VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT:
			m_arrowInside->setPos(0, 0);
			m_arrowOutside->setPos(m_arrowInside->getBounds().getWidth() + 1, 0);
			setSize(m_arrowOutside->getSize().width * 2 + 1, m_arrowOutside->getSize().height);
			break;

		default:
			break;
	}
}

void VappScreenLockKeyArrow::setMyOpacity(VfxFloat op)
{
	setOpacity(op);
	m_arrowInside->setOpacity(op);
	m_arrowOutside->setOpacity(op);
}

void VappScreenLockKeyArrow::show()
{
	setHidden(VFX_FALSE);
	changeOpacity(0.0, 1.0);
}

void VappScreenLockKeyArrow::hide()
{
	changeOpacity(1.0, 0.0);
}

void VappScreenLockKeyArrow::onBreath()
{
	if (!m_timerBreath->getIsEnabled())
	{
		m_breathStep = 0;
		m_timerBreath->m_signalTick.connect(this, &VappScreenLockKeyArrow::onBreathTimerTick);
		m_timerBreath->setDuration(VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_DURATION);	
		m_timerBreath->start();
	}
}

void VappScreenLockKeyArrow::onBreathTimerTick(VfxTimer * timer)
{
	m_arrowOutside->setOpacity(s_opacityTbl[m_breathStep]);
	m_arrowInside->setOpacity(s_opacityTbl[VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_STEP - m_breathStep - 1]);
	m_breathStep++;
	if (m_breathStep == VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_STEP)
	{
		m_breathStep = 0;
	}
}

void VappScreenLockKeyArrow::changeOpacity(VfxFloat fromOpacity, VfxFloat toOpacity)
{
	m_timelineOp->setTarget(this);
	m_timelineOp->setFromValue(fromOpacity);
	m_timelineOp->setToValue(toOpacity);
	m_timelineOp->setDuration(VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_DURATION);
	m_timelineOp->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
	m_timelineOp->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
	m_timelineOp->start();
}

void VappScreenLockKeyArrow::onOpacityChanged(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	if (isComplete)
	{
		timeline->stop();
		if (((VfxFloatTimeline*)timeline)->getToValue() == 1.0)
		{
			//this means enter operation state
			VAPP_LOCK_UNLOCK_ANIMATION();			
			onBreath();
		}
	#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
		else
		{
			setHidden(VFX_TRUE);
			m_signalArrowHidden.emit();
		}
	#endif
	}
}

void VappScreenLockKeyArrow::onEnterOperationState()
{
	show();
}

void VappScreenLockKeyArrow::enterIdleState()
{
	m_timerBreath->stop();
	setHidden(VFX_TRUE);
}

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

void VappScreenLockKeyArrow::enterBackToNormalState()
{
	m_timerBreath->stop();
	hide();
}

void VappScreenLockKeyArrow::enterCentryMoveState(VappScreenLockKeyDirectionEnum direction)
{
	setHidden(direction != m_direction);
	m_timerBreath->stop();
	setMyOpacity(1.0);
}

void VappScreenLockKeyArrow::enterCentryRestoreState(VappScreenLockKeyDirectionEnum direction)
{
	setHidden(VFX_FALSE);
	if (m_direction != direction)
	{
		changeOpacity(0.0, 1.0);
	}
}

void VappScreenLockKeyArrow::onCentryRestored()
{
	onBreath();
}

#else

void VappScreenLockKeyArrow::enterCentryTapState()
{
	m_timerBreath->stop();
	setHidden(VFX_FALSE);
}

#endif



#endif

