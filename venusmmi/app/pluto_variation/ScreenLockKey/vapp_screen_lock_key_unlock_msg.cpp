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
 *  vapp_screen_lock_key_unlock_msg.cpp
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
#include "vapp_screen_lock_key_unlock_msg.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "UMGProt.h"
#include "SmsSrvGprot.h"
#include "MmsSrvGprot.h"
#include "WAPPushSrvGprots.h"
#include "ProvBoxSrvGProt.h" /* mmi_provboxui_get_total_unread_msg_num */
#include "UmSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappScreenLockKeyUnlockMsg
 *****************************************************************************/

VAPP_SCREEN_LOCK_KEY_UNLOCK_IMPLEMENT_CLASS(VappScreenLockKeyUnlockMsg, VappScreenLockKeyUnlockItem);

void VappScreenLockKeyUnlockMsg::onInit()
{
	VappScreenLockKeyUnlockItem::onInit();

	m_selectResId = IMG_ID_VAPP_SCRLOCK_GLASS_RIGHT_SELECT;
	m_bgResId = IMG_ID_VAPP_SCRLOCK_UNLOCK_BG_MSG;
	
	m_bg->setResId(m_bgResId);
	m_card->setResId(IMG_ID_VAPP_SCRLOCK_UNLOCK_MSG);

	VFX_OBJ_CREATE(m_notify, VfxTextFrame, this);
	m_notify->setAutoAnimate(VFX_TRUE);
	m_notify->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_KEY_NOTIFY_FONT_SIZE)));
	m_notify->setColor(VAPP_SCREEN_LOCK_KEY_FONT_COLOR);
	if(srv_um_check_ready())
	{
		getMissedMsgNum();
		setMissedMsgNum();
	}	

	setAnchor(1.0, 1.0);
	setPos(LCD_WIDTH - 1, LCD_HEIGHT - 1);
	setSize(m_bg->getSize());

	initComponents();

	m_signalBgSlideIn.connect(this, &VappScreenLockKeyUnlockMsg::showNotify);

	mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappScreenLockKeyUnlockMsg::msgEventHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY,   &VappScreenLockKeyUnlockMsg::msgEventHdlr, this);
}

void VappScreenLockKeyUnlockMsg::onDeinit()
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappScreenLockKeyUnlockMsg::msgEventHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY,   &VappScreenLockKeyUnlockMsg::msgEventHdlr, this);

	VappScreenLockKeyUnlockItem::onDeinit();
}

void VappScreenLockKeyUnlockMsg::initComponents()
{
	m_bg->setPos(getSize().width*1.5, getSize().height*1.5);
	m_bg->setHidden(VFX_TRUE);
	
	m_card->setPos(getSize().width + m_card->getSize().width/2, getSize().height + m_card->getSize().height/2);
	m_card->setHidden(VFX_TRUE);
	
	m_notify->setPos(
		VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_X - (getPos().x - getSize().width), 
		VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_Y - (getPos().y - getSize().height));
	m_notify->setHidden(VFX_TRUE);

	setBgNormalPos(m_bg->getPos());
	setCardNormalPos(m_card->getPos());

	setBgOperationPos(VfxPoint(getSize().width/2, getSize().height/2));
	setCardOperationPos(VfxPoint(
		VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_X - (getPos().x - getSize().width) + m_card->getSize().width/2, 
		VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_Y - (getPos().y - getSize().height) + m_card->getSize().height/2));

}

void VappScreenLockKeyUnlockMsg::onUnlock()
{
	if (m_missedMsgNum == 0)
	{
		mmi_um_entry_main_message_menu_with_check();
	}
	else if (m_missedMsgNum == 1)
	{
		mmi_um_nmgr_lsk_handler(NULL);
	}
	else
	{
		mmi_um_nmgr_lsk_handler(NULL);
	}
	
	mmi_scr_locker_close();
}

void VappScreenLockKeyUnlockMsg::getMissedMsgNum()
{
	/* Get SMS unread count */
	m_missedMsgNum = srv_sms_get_unread_sms_num();

#ifdef __MMI_MMS_2__
	/* Get MMS unread count */
    VfxS32 result;
    srv_mms_get_msg_count_struct msg_count_req;
    vfx_sys_mem_zero(&msg_count_req, sizeof(srv_mms_get_msg_count_struct));

    msg_count_req.count = 1;
    msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;

    result = srv_mms_get_msg_count(&msg_count_req);
    if (SRV_MMS_RESULT_OK == result)
    {
        m_missedMsgNum += msg_count_req.rsp_tb[0];
    }
#endif

#ifdef WAP_SUPPORT
    /* Get Push unread count */
    m_missedMsgNum += srv_get_push_unread_count();
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    /* Get Prov unread count */
    m_missedMsgNum += srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
#endif

	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_MISSED_MSG, m_missedMsgNum));
}

void VappScreenLockKeyUnlockMsg::setMissedMsgNum()
{
	//m_missedMsgNum = 7;

    if(m_missedMsgNum)
    {        
        VfxWString missNum;
        if(m_missedMsgNum <= 999)
        {
            missNum.format("%d", m_missedMsgNum);
        }
        else
        {
            missNum.format("...");
        }
        
        m_notify->setString(missNum);
    }
    else
    {
        m_notify->setString(VFX_WSTR("0"));
    }
}

void VappScreenLockKeyUnlockMsg::updateMissedMsgNum()
{
	if(!srv_um_check_ready())
        return;

	getMissedMsgNum();
	setMissedMsgNum();
	showNotify();
}

mmi_ret VappScreenLockKeyUnlockMsg::msgEventHdlr(mmi_event_struct * event)
{
    VappScreenLockKeyUnlockMsg* card = (VappScreenLockKeyUnlockMsg *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_UM_NOTIFY_READY:
        case EVT_ID_SRV_UM_NOTIFY_REFRESH: 
            card->updateMissedMsgNum();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

void VappScreenLockKeyUnlockMsg::showNotify()
{
	if (m_missedMsgNum != 0)
	{
		VappScreenLockKeyUnlockItem::showNotify();
	}
}

#endif

