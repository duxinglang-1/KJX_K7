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
 *  vapp_screen_lock_key_unlock_calllog.cpp
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
#include "vapp_screen_lock_key_unlock_calllog.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "CallLogGprot.h"
#include "CallLogSrvGprot.h"
#include "DialerGprot.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * VappScreenLockKeyUnlockCallLog
 *****************************************************************************/

VAPP_SCREEN_LOCK_KEY_UNLOCK_IMPLEMENT_CLASS(VappScreenLockKeyUnlockCallLog, VappScreenLockKeyUnlockItem);

void VappScreenLockKeyUnlockCallLog::onInit()
{
	VappScreenLockKeyUnlockItem::onInit();

	m_selectResId = IMG_ID_VAPP_SCRLOCK_GLASS_LEFT_SELECT;
	m_bgResId = IMG_ID_VAPP_SCRLOCK_UNLOCK_BG_CALL;
	
	m_bg->setResId(m_bgResId);
	m_card->setResId(IMG_ID_VAPP_SCRLOCK_UNLOCK_CALL);	

	VFX_OBJ_CREATE(m_notify, VfxTextFrame, this);
	//m_notify->setAutoAnimate(VFX_TRUE);
	m_notify->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_KEY_NOTIFY_FONT_SIZE)));
	m_notify->setColor(VAPP_SCREEN_LOCK_KEY_FONT_COLOR);
	getMissedCLogNum();
	setMissedCLogNum();
	
	setAnchor(0.0, 1.0);
	setPos(0, LCD_HEIGHT - 1);
	setSize(m_bg->getSize());

	initComponents();

	m_signalBgSlideIn.connect(this, &VappScreenLockKeyUnlockCallLog::showNotify);
	
	mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG,  	 &VappScreenLockKeyUnlockCallLog::callLogEventHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG,    &VappScreenLockKeyUnlockCallLog::callLogEventHdlr, this);
}

void VappScreenLockKeyUnlockCallLog::onDeinit()
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG,    &VappScreenLockKeyUnlockCallLog::callLogEventHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG,    &VappScreenLockKeyUnlockCallLog::callLogEventHdlr, this);

	VappScreenLockKeyUnlockItem::onDeinit();
}

void VappScreenLockKeyUnlockCallLog::initComponents()
{	
	m_bg->setPos(-getSize().width/2, getSize().height*1.5);
	m_bg->setHidden(VFX_TRUE);
	
	m_card->setPos(-m_card->getSize().width/2, getSize().height + m_card->getSize().height/2);
	m_card->setHidden(VFX_TRUE);
	
	m_notify->setPos(
		VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_X - getPos().x, 
		VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_Y - (getPos().y - getSize().height));
	m_notify->setHidden(VFX_TRUE);

	setBgNormalPos(m_bg->getPos());
	setCardNormalPos(m_card->getPos());

	setBgOperationPos(VfxPoint(getSize().width/2, getSize().height/2));
	setCardOperationPos(VfxPoint(
		VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_X - getPos().x + m_card->getSize().width/2, 
		VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_Y - (getPos().y - getSize().height) + m_card->getSize().height/2));

}

void VappScreenLockKeyUnlockCallLog::onUnlock()
{
	if (m_missedCLogNum == 0)
	{	
		/* dial pad */
		mmi_dialer_launch();
	}
	else
	{	/* missed call */
		mmi_clog_mclt_launch();
	}

	mmi_scr_locker_close();
}

void VappScreenLockKeyUnlockCallLog::getMissedCLogNum()
{
	m_missedCLogNum = srv_clog_get_unread_missed_call_num();

	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_MISSED_CALL, m_missedCLogNum));
}

void VappScreenLockKeyUnlockCallLog::setMissedCLogNum()
{
	//m_missedCLogNum = 23;
		
	if(m_missedCLogNum)
	{
		VfxWString MissNum;
		if(m_missedCLogNum <= 999)
		{
			MissNum.format("%d", m_missedCLogNum);
		}
		else
		{
			MissNum.format("...");
		}

		m_notify->setString(MissNum);
	}
	else
	{
		m_notify->setString(VFX_WSTR("0"));
	}
}

void VappScreenLockKeyUnlockCallLog::updateMissedCLogNum()
{
	getMissedCLogNum();
	setMissedCLogNum();
	showNotify();
}

mmi_ret VappScreenLockKeyUnlockCallLog::callLogEventHdlr(mmi_event_struct * event)
{
	switch (event->evt_id)
    {
        case EVT_ID_SRV_CLOG_ADD_LOG:
        	{
	            srv_clog_evt_add_log_struct *add_evt = (srv_clog_evt_add_log_struct*) event;
	            if (add_evt->new_idf.cate == SRV_CLOG_CATE_CALL && add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED)
	            {
	                VappScreenLockKeyUnlockCallLog* card = (VappScreenLockKeyUnlockCallLog *)event->user_data;
	                card->updateMissedCLogNum();
	            }
        	}
            break;

        case EVT_ID_SRV_CLOG_DEL_LOG:
	        {
	            srv_clog_evt_del_log_struct *del_evt = (srv_clog_evt_del_log_struct*) event;
	            if (del_evt->idf.cate == SRV_CLOG_CATE_CALL && del_evt->idf.log_type == SRV_CLOG_CLT_MISSED)
	            {
	                VappScreenLockKeyUnlockCallLog* card = (VappScreenLockKeyUnlockCallLog *)event->user_data;
	                card->updateMissedCLogNum();
	            }
			}
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

void VappScreenLockKeyUnlockCallLog::showNotify()
{
	if (m_missedCLogNum != 0)
	{
		VappScreenLockKeyUnlockItem::showNotify();
	}
}


#endif

