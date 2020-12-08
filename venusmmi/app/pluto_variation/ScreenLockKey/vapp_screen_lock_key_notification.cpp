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
 *  vapp_screen_lock_key_notification.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) && defined(__MMI_NCENTER_SUPPORT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_screen_lock_key_unlock.h"
#include "vapp_screen_lock_key_notification.h"
#include "vapp_screen_lock_key_main.h"

#include "mmi_rp_app_venus_screen_lock_key_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "ScrlockerScreenLockKey.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappScreenLockKeyNotification
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockKeyNotification", VappScreenLockKeyNotification, IVappScreenLockKeyUnlock);

void VappScreenLockKeyNotification::onInit()
{
	VfxControl::onInit();

	//setHidden(VFX_TRUE);
	setSize(NOTI_WIDTH, NOTI_LIST_UP_GAP*2);
	setOpacity(0.0);
	setAutoAnimate(VFX_TRUE);

	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	VFX_OBJ_CREATE(m_timer, VfxTimer, this);

	VFX_OBJ_CREATE(m_notiList, VappScreenLockKeyNotificationList, this);
	m_notiList->setPos(NOTI_ICON_LEFT_GAP>>1, NOTI_LIST_UP_GAP);
	m_notiList->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE);

	if (!vapp_screen_lock_key_is_first_enter())
	{
		VfxS32 count = m_notiList->getCellCount();
		if (count)
		{		
			VfxS32 max_h = NOTI_HEIGHT*((count > MAX_CELL_NUM) ? MAX_CELL_NUM : count) + NOTI_LIST_UP_GAP*2;			
		
			VfxS32 img_w, img_h;		
			gdi_image_get_dimension_id(IMG_ID_VAPP_SCRLOCK_PN_BG, &img_w, &img_h);
			
			if (max_h < img_h)
			{
				max_h = img_h;
			}

			setSize(NOTI_WIDTH, max_h);
			
			m_bg->setResId(IMG_ID_VAPP_SCRLOCK_PN_BG);
			m_bg->setSize(getSize());
			m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
			m_bg->sendToBack();

			if (((VappScreenLockKeyMain*)getParent())->getState() == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL)
			{
				//setHidden(VFX_FALSE);
				setOpacity(1.0);
			}
		}
	}

	m_nCenter = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
	m_nCenter->m_signalNStatus.connect(this ,&VappScreenLockKeyNotification::onNotify);

}

void VappScreenLockKeyNotification::onDeinit()
{
	VfxControl::onDeinit();
}

/*****************************************************************************
 * NCenter
 *****************************************************************************/

void VappScreenLockKeyNotification::onNotify(VsrvNotification * notify,VsrvNStatusType status)
{
	VappScreenLockKeyNotificationList::ActionEnum ret = m_notiList->onNotify(notify, status);

	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_PN_NOTIFY, ret));
	
	if (ret != VappScreenLockKeyNotificationList::UNSUPPORT)
	{
		turnOnBacklight();
		
		VfxS32 vh = 0;

		if (ret == VappScreenLockKeyNotificationList::ADD && m_notiList->getCellCount() <= MAX_CELL_NUM)
		{
			vh = NOTI_HEIGHT;
		}
		else if (ret == VappScreenLockKeyNotificationList::CLOSE && m_notiList->getCellCount() < MAX_CELL_NUM)
		{
			vh = -NOTI_HEIGHT;
		}

		VfxS32 cur_h = getSize().height + vh;

		if (cur_h == NOTI_LIST_UP_GAP*2)
		{	//no notification
			setSize(NOTI_WIDTH, cur_h);
			//setHidden(VFX_TRUE);
			setOpacity(0.0);
			return;
		}

		VfxS32 img_w, img_h;		
		gdi_image_get_dimension_id(IMG_ID_VAPP_SCRLOCK_PN_BG, &img_w, &img_h);
		
		if (cur_h < img_h)
		{
			cur_h = img_h;
		}

		VfxS32 max_h = NOTI_HEIGHT*MAX_CELL_NUM + NOTI_LIST_UP_GAP*2;
		setSize(NOTI_WIDTH, (cur_h < max_h) ? cur_h : max_h);
		
		m_bg->setResId(IMG_ID_VAPP_SCRLOCK_PN_BG);
		m_bg->setSize(getSize());
		m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
		m_bg->sendToBack();

		if (((VappScreenLockKeyMain*)getParent())->getState() == VAPP_SCREEN_LOCK_KEY_STATE_NORMAL)
		{
			//setHidden(VFX_FALSE);
			setOpacity(1.0);
		}
	}
	
}

void VappScreenLockKeyNotification::onCheckLayout()
{

}

/*****************************************************************************
 * state machine
 *****************************************************************************/

void VappScreenLockKeyNotification::enterIdleState()
{
	//setHidden(VFX_TRUE);
	setOpacity(0.0);
}

void VappScreenLockKeyNotification::enterNormalState()
{
	//setHidden(VFX_FALSE);
	setOpacity(1.0);
}

void VappScreenLockKeyNotification::enterCentryTapState()
{
	//setHidden(VFX_TRUE);
	setOpacity(0.0);
}

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
void VappScreenLockKeyNotification::enterBackToNormalState()
{
	m_timer->m_signalTick.connect(this, &VappScreenLockKeyNotification::onBackToNormal);
	m_timer->setStartDelay(
		  VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_DURATION
		+ VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION
		+ VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_RESIZE_DURATION);
    m_timer->start();
}
#endif

void VappScreenLockKeyNotification::onBackToNormal(VfxTimer * timer)
{
	timer->stop();
	setOpacity(1.0);
}

void VappScreenLockKeyNotification::turnOnBacklight()
{
	((VappScreenLockKeyMain*)getParent())->switchBacklight(VFX_TRUE);
}


#endif

