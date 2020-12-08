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
 *  vapp_screen_lock_key_unlock_centry.cpp
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
#include "vapp_screen_lock_key_unlock_centry.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "ScreenLockKeyImageSetting.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * VappScreenLockKeyUnlockCentry
 *****************************************************************************/

VAPP_SCREEN_LOCK_KEY_UNLOCK_IMPLEMENT_CLASS(VappScreenLockKeyUnlockCentry, VappScreenLockKeyUnlockItem);    

void VappScreenLockKeyUnlockCentry::onInit()
{
	VappScreenLockKeyUnlockItem::onInit();

	m_isZoomIn = VFX_FALSE;

	m_selectResId = IMG_ID_VAPP_SCRLOCK_GLASS_CENTRY;
	//m_breathBaseResId = IMG_ID_VAPP_SCRLOCK_GLASS_CENTRY_0;
	m_bg->setResId(m_selectResId);

	setAnchor(0.5, 0.5);
	setSize(m_bg->getSize());
	setPos(VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_X + getSize().width/2, VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_Y + getSize().height/2);

	setCardOperationPos(getPos());

	m_bg->setPos(getSize().width/2, getSize().height/2);

	setCardImg();
	m_card->setPos(getSize().width/2, getSize().height/2);

	VFX_OBJ_CREATE(m_timelineZoom, VfxTransformTimeline, this);
	m_timelineZoom->m_signalStopped.connect(this, &VappScreenLockKeyUnlockCentry::onCentryResized);
	
	m_tf1 = getTransform();
	m_tf2.data.affine.sx = 1.1; 
    m_tf2.data.affine.sy = 1.1;

}

void VappScreenLockKeyUnlockCentry::onDeinit()
{
	m_timelineBreath->stop();
	VappScreenLockKeyUnlockItem::onDeinit();
}

void VappScreenLockKeyUnlockCentry::setCardImg()
{
	mmi_screen_lock_key_img_setting_type_enum type = mmi_screen_lock_key_img_setting_get_type();
	switch (type)
	{
		case MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_SYS:
			m_card->setResId(mmi_screen_lock_key_img_setting_get_img_id());
			break;

		case MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_USR:
			m_card->setPath(VFX_WSTR_MEM((const U16*)mmi_screen_lock_key_img_setting_get_img_path()));
			break;

		case MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_NOT_SET:
			m_card->setResId(IMG_ID_VAPP_SCRLOCK_UNLOCK_LOCK);
			break;

		default:
			VFX_ASSERT(0);
			break;
	}	
}


void VappScreenLockKeyUnlockCentry::enterIdleState()
{
	m_timelineBreath->stop();
	m_bg->setResId(m_selectResId);
}

void VappScreenLockKeyUnlockCentry::enterNormalState()
{
	onBreath();
}

void VappScreenLockKeyUnlockCentry::enterOperationState()
{
	onResize(VFX_FALSE, 0);
}

void VappScreenLockKeyUnlockCentry::enterCentryTapState()
{
	m_timelineBreath->stop();
	setOpacity(0.0);
	setOpacity(1.0);
	m_bg->setResId(IMG_ID_VAPP_SCRLOCK_GLASS_CENTRY);
	onResize(VFX_TRUE, 0);
}

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

void VappScreenLockKeyUnlockCentry::enterBackToNormalState()
{
	onResize(VFX_FALSE, VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_DURATION + VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION);
}

void VappScreenLockKeyUnlockCentry::enterCentryRestoreState(VappScreenLockKeyDirectionEnum direction)
{
	posAnimationHdlr(
		m_timelineCardPos,
		this,
		getPos(),
		getCardOperationPos(),
		VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_RESIZE_DURATION,
		0);
	
	onResize(VFX_FALSE, 7);	//!0 will not emit m_signalCentryResized
}
    
#else	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

void VappScreenLockKeyUnlockCentry::enterCentryTapFromNormalState()
{
	enterCentryTapState();
}

#endif	/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/


void VappScreenLockKeyUnlockCentry::onResize(VfxBool isZoomIn, VfxMsec startTime)
{	
	m_isZoomIn = isZoomIn;
	resizeAnimationHdlr(m_timelineZoom, this, VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_RESIZE_DURATION, startTime);
}    

void VappScreenLockKeyUnlockCentry::resizeAnimationHdlr(
	VfxTransformTimeline * timeline,
	VfxAnimatable * target,
	VfxMsec duration,
	VfxMsec startTime)
{	
    timeline->setTarget(target);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

	if (m_isZoomIn)
	{
		timeline->setFromValue(m_tf1);
		timeline->setToValue(m_tf2);
	}
	else
	{
		timeline->setFromValue(m_tf2);
		timeline->setToValue(m_tf1);
	}    
    
    timeline->setDurationTime(duration); 
    timeline->setRepeatCount(1);
	timeline->setAutoReversed(VFX_TRUE);
	timeline->setStartTime(startTime);
    timeline->start();
}

void VappScreenLockKeyUnlockCentry::onCentryResized(VfxBaseTimeline * timeline,VfxBool isCompleted)
{
	if (isCompleted)
	{
		timeline->stop();

		if (m_isZoomIn)
		{
			m_isZoomIn = VFX_FALSE;
			//m_bg->setResId(IMG_ID_VAPP_SCRLOCK_GLASS_CENTRY_BIG);
		}
		else
		{
			if (timeline->getStartTime() == 0)
			{	
				//this means enter operation state, notify other cards to slide in
				m_signalCentryResized.emit();
			}
			else if (timeline->getStartTime() == 7)
			{
				//this means enter centry restore state, notify arrows show
				m_signalCentryRestored.emit();
			}
			else
			{
				//this means go back to normal state
				VAPP_LOCK_UNLOCK_ANIMATION();
			}
			
			onBreath();
		}
	}
}

VfxS32 VappScreenLockKeyUnlockCentry::getRadius()
{
	return m_bg->getSize().width/2;
}

#endif

