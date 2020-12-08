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
 *  vapp_screen_lock_key_notification_cell.cpp
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
#include "vapp_screen_lock_key_notification_cell.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#include "vfx_container.h"
#include "vsrv_ndeclaration.h"
#include "vsrv_notification.h"

/*****************************************************************************
 * VappScreenLockKeyNotificationCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockKeyNotificationCell", VappScreenLockKeyNotificationCell, VcpVarHeightMenuCell);

void VappScreenLockKeyNotificationCell::onInit()
{
	VcpVarHeightMenuCell::onInit();

	setBounds(0, 0, NOTI_LIST_WIDTH, NOTI_HEIGHT);

	VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
	VFX_OBJ_CREATE(m_mainText, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_subText, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_timeText, VfxTextFrame, this);
}

void VappScreenLockKeyNotificationCell::onDeinit()
{
	VcpVarHeightMenuCell::onDeinit();
}

void VappScreenLockKeyNotificationCell::layout(VfxS32 topMargin)
{
	m_icon->setPos(NOTI_ICON_LEFT_GAP>>1, (getSize().height - m_icon->getSize().height)>>1);		

	m_mainText->setPos(m_icon->getPos().x + m_icon->getSize().width + NOTI_ICON_RIGHT_GAP, NOTI_TEXT_UP_GAP);
	m_mainText->setSize(NOTI_LIST_WIDTH - m_mainText->getPos().x, NOTI_MAIN_FONT_SIZE);	
	m_mainText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(NOTI_MAIN_FONT_SIZE)));
	m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

	m_subText->setSize(NOTI_SUB_WIDTH, NOTI_SUB_FONT_SIZE);
	m_subText->setPos(m_mainText->getPos().x, m_mainText->getPos().y + NOTI_MAIN_FONT_SIZE + NOTI_TEXT_MID_GAP);
	m_subText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(NOTI_SUB_FONT_SIZE)));
	m_subText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	
	m_timeText->setSize(NOTI_TIME_WIDTH, NOTI_SUB_FONT_SIZE);
	m_timeText->setPos(m_subText->getPos().x + m_subText->getSize().width + NOTI_TIME_LEFT_GAP, m_subText->getPos().y);
	m_timeText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(NOTI_SUB_FONT_SIZE)));
	m_timeText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

	if (!isTop())
	{
		createSeperator();
	}
}

void VappScreenLockKeyNotificationCell::onUpdate()
{
	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_PN_UPDATE));

	VcpVarHeightMenuCell::onUpdate();

	if (isTop())
	{
		destroySeperator();
	}
	else
	{
		createSeperator();
	}

	VsrvNotificationEvent *ne = (VsrvNotificationEvent*)m_noti;
	//if (!ne->getIcon().isNull())
	//{
	//	setIcon(ne->getIcon());
	//}
	setMainText(ne->getMainText());
	setSubText(ne->getSubText());
	setTimeStamp(ne->getTimeStamp());
	setTimeText();
}

VfxBool VappScreenLockKeyNotificationCell::checkNotifications()
{
	VfxBool ret = VFX_FALSE;

	onUpdate();	

	return ret;	
}

void VappScreenLockKeyNotificationCell::addNotification(VsrvNotification *noti)
{	
	VsrvNotificationEvent *ne = (VsrvNotificationEvent*)noti;
	setMainText(ne->getMainText());
	setSubText(ne->getSubText());
	setTimeStamp(ne->getTimeStamp());
}

void VappScreenLockKeyNotificationCell::setNGroup(VsrvNGroup* group)
{
    ASSERT(group);
    m_nGroup = group;
}

VsrvNGroup* VappScreenLockKeyNotificationCell::getNGroup()
{
    return m_nGroup;
}

void VappScreenLockKeyNotificationCell::setNotify(VsrvNotification * notify)
{
	m_noti = notify;
}

VsrvNotification* VappScreenLockKeyNotificationCell::getNotify()
{
	return m_noti;
}

void VappScreenLockKeyNotificationCell::setCellStruct(VappScreenLockKeyNotificationContex * cStruct)
{
	m_cellStruct = cStruct;
}

VappScreenLockKeyNotificationContex* VappScreenLockKeyNotificationCell::getCellStruct()
{
	return m_cellStruct;
}

void VappScreenLockKeyNotificationCell::setIcon(const VfxImageSrc &imgScr)
{
	if (m_icon && !imgScr.isNull())
	{
		m_icon->setImgContent(imgScr);
		//m_icon->setSize(24, 24);
		//m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	}
}

void VappScreenLockKeyNotificationCell::setMainText(const VfxWString &text)
{
	if (m_mainText)
	{
		m_mainText->setString(text);
	}
}

VfxWString VappScreenLockKeyNotificationCell::getMainText() const
{
	if (m_mainText)
	{
		return m_mainText->getString();
	}
	else
	{
		return VFX_WSTR_NULL;
	}
}

void VappScreenLockKeyNotificationCell::setSubText(const VfxWString &text)
{
	if (m_subText)
	{
		m_subText->setString(text);
	}
}

VfxWString VappScreenLockKeyNotificationCell::getSubText() const
{
	if (m_subText)
	{
		return m_subText->getString();
	}
	else
	{
		return VFX_WSTR_NULL;
	}
}

void VappScreenLockKeyNotificationCell::setTimeText()
{
	VfxDateTime currTime;
    currTime.setCurrentTime();
	
    if (m_lastTime.getYear() == currTime.getYear()&&
        m_lastTime.getMonth() == currTime.getMonth() &&
        m_lastTime.getDay() == currTime.getDay())
    {
        setTimeText(m_lastTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE)); 
    }
    else
    {
        setTimeText(m_lastTime.getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));                                        
    }
}

void VappScreenLockKeyNotificationCell::setTimeText(const VfxWString &text)
{
	if (m_timeText)
	{
		m_timeText->setString(text);
	}
}

VfxWString VappScreenLockKeyNotificationCell::getTimeText() const
{
	if (m_timeText)
	{
		return m_timeText->getString();
	}
	else
	{
		return VFX_WSTR_NULL;
	}
}  

void VappScreenLockKeyNotificationCell::setTimeStamp(VfxDateTime timeStamp)
{
	m_lastTime = timeStamp;
}

VfxDateTime VappScreenLockKeyNotificationCell::getTimeStamp() const
{
	return m_lastTime;
}

void VappScreenLockKeyNotificationCell::setCreateTime(VfxDateTime time)
{
	m_createTime = time;
}

void VappScreenLockKeyNotificationCell::createSeperator()
{
	if (!m_seperator)
	{
		VFX_OBJ_CREATE(m_seperator, VfxFrame, this);
		m_seperator->setSize(getSize().width - NOTI_ICON_LEFT_GAP, 1);
		m_seperator->setPos(NOTI_ICON_LEFT_GAP>>1, 0);
		m_seperator->setBgColor(VFX_COLOR_GREY);
	}
}

void VappScreenLockKeyNotificationCell::destroySeperator()
{
	if (m_seperator)
	{
		VFX_OBJ_CLOSE(m_seperator);
	}
}

#endif

