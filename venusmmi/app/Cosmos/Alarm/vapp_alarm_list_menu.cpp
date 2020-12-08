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
 *  vapp_alarm_list_menu.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm list page.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

extern "C"
{
	#include "GlobalResDef.h"
	#include "AlarmSrvGprot.h"
	#include "ReminderSrvGprot.h"
}

#include "mmi_rp_vapp_alarm_def.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif

#include "vfx_string.h"
#include "vfx_adp_device.h"

#include "data\vdat_systime.h"

#include "vcp_switch.h"
#include "vcp_confirm_popup.h"

#include "vapp_alarm.h"
#include "vapp_alarm_list_menu.h"
#include "vapp_alarm_clock.h"
#include "vapp_alarm_list.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }

#define VAPP_ALM_LIST_LABEL_COLOR		VfxColor(255, 21, 21, 21)
#define VAPP_ALM_LIST_REPEAT_COLOR  	VfxColor(255, 80, 80, 80)
#define VAPP_ALM_LIST_TIME_COLOR		VfxColor(255, 21, 21, 21)
#define VAPP_ALM_LIST_TIME_AMPM_COLOR	VfxColor(255, 21, 21, 21)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmListItem
 *****************************************************************************/
VappAlarmListItem::VappAlarmListItem() :
	m_txtTime(NULL),
	m_txtRepeat(NULL),
	m_txtLabel(NULL),
	m_switch(NULL),
	m_index(0xFF),
	m_bSwitch(VFX_TRUE)

{
}

VappAlarmListItem::VappAlarmListItem(const VfxU16 &index, const VfxBool &bSwitch) :
	m_txtTime(NULL),
	m_txtRepeat(NULL),
	m_txtLabel(NULL),
	m_switch(NULL),
	m_index(index),
	m_bSwitch(bSwitch)
{
}

/*void VappAlarmListItem::setIndex(const VfxU16& index)
{
	m_index = index;
}*/
	
void VappAlarmListItem::onCreateElements(void)
{
	srv_alm_node_type *node = srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);

	VFX_OBJ_CREATE_EX(m_txtTime, 
					  VappAlarmTimeFrame, 
					  this, 
					  (node->Hour, node->Min, TIME_FONT_SIZE, AMPM_FONT_SIZE));
	
	m_txtTime->setPos(TIME_POS_X, TIME_POS_Y);	
	
	VfxFontDesc font;
	if (node->Freq != SRV_REMINDER_REPEAT_ONCE)
	{
		VFX_OBJ_CREATE(m_txtRepeat, VfxTextFrame, this);
		m_txtRepeat->setAnchor(0.0F, 1.0F);
		m_txtRepeat->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(REPEAT_FONT_SIZE)));
		m_txtRepeat->setString(VappAlarmApp::getRepeatString(node->Freq, node->Days));
	}

	// for test
	if (vfx_sys_wcslen((const VfxWChar*)node->label) != 0)
	{
		VFX_OBJ_CREATE(m_txtLabel, VfxTextFrame, this);
		m_txtLabel->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(LABEL_FONT_SIZE)));
		m_txtLabel->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_txtLabel->setString(VFX_WSTR_MEM((const VfxWChar*)node->label));
		//m_txtLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		//m_txtLabel->setBorder(VFX_COLOR_GREEN);
	}

	if (m_bSwitch)
	{
		VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
		m_switch->setChecked((node->State == 1), VFX_TRUE);
		m_switch->setAnchor(1.0F, 0.5F);
		m_switch->setAutoAnimate(VFX_FALSE);
		//m_switch->m_signalSwitchChanged.connect(this, &VappAlarmListItem::switchCallback);
		m_switch->m_signalToggleAnimationDone.connect(this, &VappAlarmListItem::onAniDone);
	}
}

void VappAlarmListItem::onCloseElements(void)
{
	VFX_OBJ_CLOSE(m_switch);
	VFX_OBJ_CLOSE(m_txtLabel);
	VFX_OBJ_CLOSE(m_txtRepeat);
	VFX_OBJ_CLOSE(m_txtTime);
}

void VappAlarmListItem::onLayoutElements(void)
{
	if (m_txtRepeat != NULL)
	{
		m_txtTime->setAnchor(0.0F, 0.0F);
		m_txtTime->setPos(TIME_POS_X, TIME_POS_Y);
		m_txtRepeat->setPos(REPEAT_POX_X, getRect().getHeight() - TIME_POS_Y);
	}
	else
	{
		m_txtTime->setAnchor(0.0F, 0.5F);
		m_txtTime->setPos(TIME_POS_X, (getRect().getHeight() >> 1));		
	}

	if (m_txtLabel != NULL)
	{
		VfxS32 yPos;
		VfxS32 yShift = m_txtTime->getAmpmHeight();
		
		if (yShift == 0)
		{
			m_txtLabel->setAnchor(0.0F, 1.0F);
		}
		else
		{
			m_txtLabel->setAnchor(0.0F, 0.0F);
			yShift += 2;

		}
		
		yPos = (m_txtTime->getPos().y +
				m_txtTime->getSize().height * (1 - m_txtTime->getAnchor().y)) - yShift;
		
		m_txtLabel->setPos(TIME_POS_X + m_txtTime->getSize().width + LABEL_POS_SHIFT,
						   yPos);	
	}

	if (m_switch != NULL)
	{
		m_switch->setHidden(getMenu()->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION);
		if (!m_switch->getHidden())
		{
			srv_alm_node_type *node = srv_alm_read(m_index);
			m_switch->setChecked((node->State == 1), VFX_TRUE);
		m_switch->setPos(getRect().getWidth() - SWITCH_RIFHT_MARGIN, (getRect().getHeight()) / 2);
	}	
}

	// set text boundary
	if (m_txtLabel != NULL)
	{
		VfxU16 width;
		
		if (m_bSwitch != NULL && !m_switch->getHidden())
		{
			width = m_switch->getPos().x - m_txtLabel->getPos().x - 3 - m_switch->getSize().width;
		}
		else
		{
			width = (getSize().width - m_txtLabel->getPos().x - SWITCH_RIFHT_MARGIN);
		}

		m_txtLabel->setSize(width, m_txtLabel->getSize().height);
	}

	if (getCell()->m_isHighlight)
	{
		m_txtTime->setTimeColor(VFX_COLOR_WHITE, VFX_COLOR_WHITE);
		
		if (m_txtRepeat != NULL)
		{
			m_txtRepeat->setColor(VFX_COLOR_WHITE);
		}
		
		if (m_txtLabel != NULL)
		{
			m_txtLabel->setColor(VFX_COLOR_WHITE);
		}
	}
	else
	{
		m_txtTime->setTimeColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN), VFX_COLOR_RES(VAPP_ALARM_SUB_COLOR));
		
		if (m_txtRepeat != NULL)
		{
			m_txtRepeat->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
		}
		
		if (m_txtLabel != NULL)
		{
			m_txtLabel->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
		}
	}
}


void VappAlarmListItem::onAniDone(VcpSwitch *obj, VfxBool newState)
{
	VFX_ASSERT(obj == m_switch);

#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("ass", SA_start);
#endif

	srv_alm_node_type *node = srv_alm_read(m_index);

	node->State = newState ? 1 : 0;
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("as0", SA_start);
#endif
	srv_alm_write(m_index, node);

#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("as0", SA_stop);
#endif

	m_signalSwitch.postEmit(m_index, newState);

#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("ass", SA_stop);
#endif

}

/***************************************************************************** 
 * Class VappAlmCustomListMenu
 *****************************************************************************/
VappAlmCustomListMenu::VappAlmCustomListMenu(const VfxBool &bSwitch) :
	m_bSwitch(bSwitch),
	m_totalAlm(0),
	m_mode(LIST_MODE_LIST)
{
	m_indexLst[0] = 0xFF;
	/*for (VfxU32 i = 0; i < NUM_OF_ALM; i++)
	{
		m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}*/
	resetState();
}

void VappAlmCustomListMenu::onInit(void)
{
	VcpListMenu::onInit();

	VappAlarmApp::getAlmList(m_indexLst, m_totalAlm);
	
	setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
	setContentProvider(this);

	m_signalItemTapped.connect(this, &VappAlmCustomListMenu::onItemTap);
	m_signalItemSelectionStateChanged.connect(this, &VappAlmCustomListMenu::onListItemSelect);
	m_signalItemLongTapped.connect(this, &VappAlmCustomListMenu::onLongTap);
}

void VappAlmCustomListMenu::setListState(const VfxU32 &index,const VcpListMenuItemStateEnum &newState)
{
	RETURN_IF_FAIL(index < getCount());
	
	m_stateLst[index] = newState;
	setItemState(index, newState);

	checkHasSelect();
}

const VfxU8 *VappAlmCustomListMenu::getIndexList(void) const
{
	return m_indexLst;
}

VcpListMenuCellClientBaseFrame* 
	VappAlmCustomListMenu::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
	VFX_ASSERT(index < getCount());
	
	VappAlarmListItem *obj;	

	VFX_OBJ_CREATE_EX(obj, VappAlarmListItem, parentFrame, (m_indexLst[index], m_bSwitch));

	if (m_bSwitch)
	{
		obj->m_signalSwitch.connect(this, &VappAlmCustomListMenu::onSwitch);
	}
	
	return obj;
}

void VappAlmCustomListMenu::onListItemSelect(VcpListMenu *obj, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	VFX_ASSERT(index < getCount());
	
	m_stateLst[index] = newState;

	checkHasSelect();
}

void VappAlmCustomListMenu::onItemTap(VcpListMenu *obj, VfxU32 index)
{
	VFX_ASSERT(index < getCount());

	m_signalTap.postEmit(obj, m_indexLst[index]);
}

void VappAlmCustomListMenu::onSwitch(VfxU16 index, VfxBool newState)
{
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("as1", SA_start);
#endif
	m_signalSwitch.postEmit(index, newState);
	
#ifdef __MAUI_SOFTWARE_LA__
			SLA_CustomLogging("as1", SA_start);
#endif

}

void VappAlmCustomListMenu::closeItemCustomContentFrame(
								VfxU32 index,
								VcpListMenuCellClientBaseFrame *cell)
{
	//VFX_ASSERT(index < getCount());
	
	VFX_OBJ_CLOSE(cell);
}

VfxBool VappAlmCustomListMenu::getMenuEmptyText(
			VfxWString &text,				 // [OUT] the text resource
			VcpListMenuTextColorEnum &color  // [OUT] the text color
			)
{
	text.loadFromRes(STR_ID_VAPP_ALARM_NO_ALARMS);
	
	return VFX_TRUE;
}

VcpListMenuItemStateEnum VappAlmCustomListMenu::getItemState(VfxU32 index) const
{
	VFX_ASSERT(index < getCount());
	
	return m_stateLst[index];
}

void VappAlmCustomListMenu::updateOneItem(const VfxU32 &index)
{
	for (VfxU32 i = 0; i < m_totalAlm; i++)
	{
		if (m_indexLst[i] == index)
		{
			updateItem(i);
			
			VappAlarmApp::refreshStatusIcon();
			break;
		}
	}
}

void VappAlmCustomListMenu::updateAllItems(VfxBool needReset)
{
	VappAlarmApp::getAlmList(m_indexLst, m_totalAlm);

	resetAllItems(needReset);

	VappAlarmApp::refreshStatusIcon();
}

VfxU32 VappAlmCustomListMenu::getSelectedCount(void)
{
    VfxU32 total = 0;
    
	for (VfxU32 i = 0; i < m_totalAlm; i++)
	{
		if (m_stateLst[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
            total++;
		}
	}

    return total;
}


void VappAlmCustomListMenu::deleteSelectedItems(void)
{
	srv_alm_node_type *node;

	for (VfxU32 i = 0; i < m_totalAlm; i++) 
	{
		if (m_stateLst[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
			node = srv_alm_read(m_indexLst[i]);
			memset(node, 0xFF, sizeof(srv_alm_node_type));
			srv_alm_write(m_indexLst[i], node);
		}
	}
}

void VappAlmCustomListMenu::setEditMode(const VfxU16 &newMode)
{
	if (m_mode != newMode)
	{
		switch (newMode)
		{
			case LIST_MODE_DELETE:
			{
				resetState();
				setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
				break;
			}
			
			case LIST_MODE_LIST:
			{
				setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
				break;
			}
		}
		
		m_mode = newMode;
	}	
}

void VappAlmCustomListMenu::onLongTap(VcpListMenu *obj, U32 index)
{
	if (m_mode != LIST_MODE_LIST)
	{
		return;
	}
	
	vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

		
	VcpMenuPopup *menuPop;

	VFX_OBJ_CREATE(menuPop, VcpMenuPopup, this);
	menuPop->setAutoDestory(VFX_TRUE);
	menuPop->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ALARM_ALARM_OPTIONS));

	menuPop->addItem('DELE', VFX_WSTR_RES(STR_GLOBAL_DELETE));

	menuPop->m_signalMenuCallback.connect(this, &VappAlmCustomListMenu::onMenuCallack);	
	menuPop->showMenu();

	m_indexLongTap = index;
}

void VappAlmCustomListMenu::onMenuCallack(
								VcpMenuPopup* menu,
								VcpMenuPopupEventEnum evt,
								VcpMenuPopupItem *item)
{
    if (evt == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
    	switch (item->getId())
    	{			
			case 'DELE':
			{
    	    	VcpConfirmPopup *confirm;
				VFX_OBJ_CREATE(confirm, VcpConfirmPopup, findScreen());
				confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
				confirm->setText(VFX_WSTR_RES(STR_ID_VAPP_ALARM_DELETE_ASK));
				confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
				confirm->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE), 
										 VFX_WSTR_RES(STR_GLOBAL_CANCEL),
										 VCP_POPUP_BUTTON_TYPE_WARNING,
										 VCP_POPUP_BUTTON_TYPE_CANCEL);
				confirm->m_signalButtonClicked.connect(this, &VappAlmCustomListMenu::onCmdCallback);
				confirm->setAutoDestory(VFX_TRUE);

				confirm->show(VFX_TRUE);
				break;
			}
			default:
				break;
    	}
    } 

}


void VappAlmCustomListMenu::onCmdCallback(VfxObject *obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		srv_alm_node_type *node;
		
		node = srv_alm_read(m_indexLst[m_indexLongTap]);
		memset(node, 0xFF, sizeof(srv_alm_node_type));
		srv_alm_write(m_indexLst[m_indexLongTap], node);

		m_signalDeleteDone.postEmit();
	}
}

void VappAlmCustomListMenu::checkHasSelect(void)
{
	VfxU32 count = 0;
	
	for (VfxU32 i = 0; i < getCount(); i++)
	{
		if (m_stateLst[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
			count++;
		}
	}

	m_signalHasSelect.postEmit(this, count);
}

void VappAlmCustomListMenu::resetState(void)
{
	for (VfxU32 i = 0; i < NUM_OF_ALM; i++)
	{
		m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

