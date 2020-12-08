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
 *  vapp_screen_lock_msg_card.cpp
 *
 * Project:
 * --------
 *  Venus
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

#include "vapp_screen_lock_cosmos_msg_card.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_cosmos_def.h"
#include "vapp_msg_gprot.h"

// for sse 
#include "vfx_adp_sse.h"

#include "mmi_rp_srv_venus_component_button_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "SmsSrvGprot.h"
#include "MmsSrvGprot.h"
#include "WAPPushSrvGprots.h"
#include "ProvBoxSrvGProt.h" /* mmi_provboxui_get_total_unread_msg_num */

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
VAPP_SCREEN_LOCK_UNLOCK_ITEM_IMPLEMENT_CLASS(VappScreenLockMsgCard, VappScreenLockCard);

VappScreenLockMsgCard::VappScreenLockMsgCard():
    m_missNum(0)
{
}


void VappScreenLockMsgCard::onInit()
{
    VappScreenLockCard::onInit();

    m_imgUnpress->setResId(IMG_ID_VAPP_SCREEN_LOCK_UNCLICKED_CARD3);
    m_imgUnpress->setOpacity(1);

    VFX_OBJ_CREATE(m_imgIcon, VfxImageFrame, this);
    m_imgIcon->setResId(IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_ENVELOP);

    VFX_OBJ_CREATE(m_imgIconDot, VfxImageFrame, this);
    m_imgIconDot->setResId(IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_DOT);
    oriDotSize = m_imgIconDot->getSize();
    m_imgIconDot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imgIconDot->setOpacity(0);
    m_imgIconDot->setAnchor(0.5, 0);
    m_imgIconDot->setPos(getSize().width/2, 
                         m_imgIconArrow->getPos().y+m_imgIconArrow->getSize().height/2+VAPP_SCREEN_LOCK_CARD_ICON_ARROW_Y_OFFSET+m_imgIcon->getSize().height+VAPP_SCREEN_LOCK_CARD_ICON_DOT_Y_OFFSET);
    m_imgIconDot->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_textMissNum, VfxTextFrame, this); 
    m_textMissNum->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_MISS_NUM_STR_SIZE), VFX_FONT_DESC_ATTR_BOLD, VFX_FONT_DESC_EFFECT_NONE));
    m_textMissNum->setOpacity(0);
    m_textMissNum->setAnchor(0.5, 0.5);
    m_textMissNum->setFullLineHeightMode(VFX_FALSE);    
    m_textMissNum->setPos(m_imgIconDot->getPos().x, 
                          m_imgIconDot->getPos().y + m_imgIconDot->getSize().height/2 -
                          VAPP_SCREEN_LOCK_CARD_TEXT_NUM_Y_OFFSET);
    m_textMissNum->setAutoAnimate(VFX_TRUE);
    
    m_imgIcon->setAnchor(0.5, 0.5);
    m_imgIcon->setPos(getSize().width/2, getSize().height/2+VAPP_SCREEN_LOCK_CARD_OFFSET_BTW_IMG_AND_REAL_CARD/2); 

    updateMsgNum();

    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH,  &VappScreenLockMsgCard::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappScreenLockMsgCard::eventHandler, this);
}


void VappScreenLockMsgCard::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappScreenLockMsgCard::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappScreenLockMsgCard::eventHandler, this);

    VappScreenLockCard::onDeinit();
}


mmi_ret VappScreenLockMsgCard::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_EVENT_HANDLER, event->evt_id, 200);
    VappScreenLockMsgCard* card = (VappScreenLockMsgCard *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_UM_NOTIFY_READY:
            card->updateMsgNum();
            break;
            
        case EVT_ID_SRV_UM_NOTIFY_REFRESH: 
            card->updateMsgNum();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


void VappScreenLockMsgCard::setMissNum(VfxU32 num)
{    
    if(num >= 100)  // 3 digits, stretch the icon dot
    {
        m_imgIconDot->setSize(VAPP_SCREEN_LOCK_CARD_ICON_DOT_WIDTH, m_imgIconDot->getSize().height);
    }
    else
    {
        m_imgIconDot->setSize(oriDotSize);
    }

    if(num)
    {
        m_missNum = num;
        
        VfxWString missNumString;
        if(num <= 999)
        {
            missNumString.format("%d", num);
        }
        else
        {
            missNumString.format("999");
        }
        
        m_textMissNum->setString(missNumString);
        m_imgIconDot->setOpacity(1);
        m_textMissNum->setOpacity(1);
        
        m_imgIcon->setAnchor(0.5, 0);
        m_imgIcon->setPos(getSize().width/2, m_imgIconArrow->getPos().y+m_imgIconArrow->getSize().height+VAPP_SCREEN_LOCK_CARD_ICON_ARROW_Y_OFFSET);  
    }
    else
    {
        m_imgIconDot->setOpacity(0);
        m_textMissNum->setOpacity(0);    

        m_imgIcon->setAnchor(0.5, 0.5);
        m_imgIcon->setPos(getSize().width/2, getSize().height/2+VAPP_SCREEN_LOCK_CARD_OFFSET_BTW_IMG_AND_REAL_CARD/2); 
    }
}


VfxBool VappScreenLockMsgCard::updateMsgNum()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_UPDATE_MSG_NUMBER, srv_um_check_ready(), getUnreadMsgNum(), 200);
    if(MMI_FALSE == srv_um_check_ready())
    {
        return MMI_FALSE;
    }

    setMissNum(getUnreadMsgNum());
    return MMI_TRUE;
}


VfxU32 VappScreenLockMsgCard::getUnreadMsgNum()
{
    VfxU32 count = 0;

    /* Get SMS unread count */
    count += srv_sms_get_unread_sms_num();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, count, 200);

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
        count += msg_count_req.rsp_tb[0];
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, msg_count_req.rsp_tb[0], 201);
    }
#endif

#ifdef WAP_SUPPORT
    /* Get Push unread count */
    count += srv_get_push_unread_count();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, srv_get_push_unread_count(), 202);
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    /* Get Prov unread count */
    count += srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL), 203);
#endif

    return count;
}


void VappScreenLockMsgCard::onClicked()
{
}


void VappScreenLockMsgCard::onReleased()
{
}


void VappScreenLockMsgCard::onUnlocked()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_ON_UNLOCKED, 200);
    VappMsgLaunchStruct para;
    
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_LOCK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER); 
    if(m_missNum)
    {
        para.mode = VAPP_MSG_LAUNCH_INBOX;
        vapp_msg_launch(&para, sizeof(para));
    }
    else
    {
        para.mode = VAPP_MSG_LAUNCH_NORMAL;
        vapp_msg_launch(&para, sizeof(para));
    }
}
#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
