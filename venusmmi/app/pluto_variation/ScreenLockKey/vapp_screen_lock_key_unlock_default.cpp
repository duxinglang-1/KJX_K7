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
 *  vapp_screen_lock_key_unlock_default.cpp
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
#include "vapp_screen_lock_key_unlock_default.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

/*****************************************************************************
 * VappScreenLockKeyUnlockDefault
 *****************************************************************************/

VAPP_SCREEN_LOCK_KEY_UNLOCK_IMPLEMENT_CLASS(VappScreenLockKeyUnlockDefault, VappScreenLockKeyUnlockItem);

void VappScreenLockKeyUnlockDefault::onInit()
{
	VappScreenLockKeyUnlockItem::onInit();

	m_selectResId = IMG_ID_VAPP_SCRLOCK_GLASS_UP_SELECT;
	m_bgResId = IMG_ID_VAPP_SCRLOCK_UNLOCK_BG_HOME;
	
	m_bg->setResId(m_bgResId);
	m_card->setResId(IMG_ID_VAPP_SCRLOCK_UNLOCK_HOME);
	m_notify = NULL;

	setAnchor(0.5, 0.5);
	setSize(m_bg->getSize());
	setPos(VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_X + getSize().width/2, VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_Y + getSize().height/2);

	initComponents();
}

void VappScreenLockKeyUnlockDefault::onDeinit()
{
	VappScreenLockKeyUnlockItem::onDeinit();
}

void VappScreenLockKeyUnlockDefault::initComponents()
{
	m_bg->setPos(getSize().width/2, -getSize().height/2);
	m_bg->setHidden(VFX_TRUE);
	
	m_card->setPos(getSize().width/2,  -m_card->getSize().height/2);
	m_card->setHidden(VFX_TRUE);

	setBgNormalPos(m_bg->getPos());
	setCardNormalPos(m_card->getPos());

	setBgOperationPos(VfxPoint(getSize().width/2, getSize().height/2));
	setCardOperationPos(getBgOperationPos());
}

void VappScreenLockKeyUnlockDefault::onUnlock()
{
	mmi_scr_locker_close();
}



#endif

