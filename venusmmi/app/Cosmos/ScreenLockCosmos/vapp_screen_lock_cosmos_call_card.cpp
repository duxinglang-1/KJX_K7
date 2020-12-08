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
 *  vapp_screen_lock_call_card.cpp
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

#include "vapp_screen_lock_cosmos_call_card.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_cosmos_def.h"

#include "vapp_dialer_gprot.h"

// for sse 
#include "vfx_adp_sse.h"

#include "mmi_rp_srv_venus_component_button_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "CallLogSrvGprot.h"

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
VAPP_SCREEN_LOCK_UNLOCK_ITEM_IMPLEMENT_CLASS(VappScreenLockCallCard, VappScreenLockCard);

VappScreenLockCallCard::VappScreenLockCallCard()
{
}

void VappScreenLockCallCard::onClicked()
{
}

void VappScreenLockCallCard::onReleased()
{
}

void VappScreenLockCallCard::onUnlocked()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_CALL_CARD_ON_UNLOCKED, 200);
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_LOCK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER); 
    vapp_dialer_launch_from_lock_screen(NULL, 0);
}


void VappScreenLockCallCard::onInit()
{
    VappScreenLockCard::onInit();

    m_imgUnpress->setResId(IMG_ID_VAPP_SCREEN_LOCK_UNCLICKED_CARD1);
    m_imgUnpress->setOpacity(1);
    
    VFX_OBJ_CREATE(m_imgIcon, VfxImageFrame, this);
    m_imgIcon->setResId(IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_PHONE);

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

    VfxU32 miss = srv_clog_get_unread_missed_call_num();
    setMissNum(miss);

    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG,  &VappScreenLockCallCard::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG,  &VappScreenLockCallCard::eventHandler, this);
}

void VappScreenLockCallCard::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG, &VappScreenLockCallCard::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG, &VappScreenLockCallCard::eventHandler, this);
    VappScreenLockCard::onDeinit();
}


void VappScreenLockCallCard::setMissNum(VfxU32 num)
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
        VfxWString MissNum;
        if(num <= 999)
        {
            MissNum.format("%d", num);
        }
        else
        {
            MissNum.format("999");
        }

        m_textMissNum->setString(MissNum);
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


mmi_ret VappScreenLockCallCard::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_CLOG_ADD_LOG:
        {
            srv_clog_evt_add_log_struct *add_evt = (srv_clog_evt_add_log_struct*) event;
            if (add_evt->new_idf.cate == SRV_CLOG_CATE_CALL && add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED)
            {
                VappScreenLockCallCard* card = (VappScreenLockCallCard *)event->user_data;
                VfxU32 miss = srv_clog_get_unread_missed_call_num();
                card->setMissNum(miss);
            }
        }
            break;

        case EVT_ID_SRV_CLOG_DEL_LOG:
        {
            srv_clog_evt_del_log_struct *del_evt = (srv_clog_evt_del_log_struct*) event;
            if (del_evt->idf.cate == SRV_CLOG_CATE_CALL && del_evt->idf.log_type == SRV_CLOG_CLT_MISSED)
            {
                VappScreenLockCallCard* card = (VappScreenLockCallCard *)event->user_data;
                VfxU32 miss = srv_clog_get_unread_missed_call_num();
                card->setMissNum(miss);
            }
}
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
