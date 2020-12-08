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
 *  vapp_alarm_setting.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Fancy alarm ap.
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
}

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"

#include "vapp_sound_settings_gprot.h"

#include "vapp_alarm.h"
#include "vapp_alarm_setting.h"
//#include "mmi_rp_vapp_alarm_def.h"
#include "mmi_rp_vapp_clock_def.h"


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


/***************************************************************************** 
 * Class VappAlarmSnoozePage
 *****************************************************************************/
void VappAlarmSnoozePage::onInit(void)
{
	VfxPage::onInit();
	// title bar
	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(STR_ID_VAPP_ALARM_SNOOZE);
	setTopBar(titleBar);

	VFX_OBJ_CREATE(m_list,VcpListMenu,this);
	//m_list->setContentProvider(this);
	m_list->setSize(getSize());
	m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_list->setContentProvider(this);
	m_list->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
	m_list->m_signalItemTapped.connect(this, &VappAlarmSnoozePage::onListItemTap);
    m_list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

	VfxS32 height = getSize().height - titleBar->getSize().height;
	m_list->setSize(getSize().width, height);
}

/*void VappAlarmSnoozePage::setValue(const VfxU8 &snooze)
{
	m_snooze = snooze;
}*/

void VappAlarmSnoozePage::onListItemTap(VcpListMenu *obj, VfxU32 index)
{
	m_signalSelected.emit(this, index);

	getMainScr()->popPage();
}

VcpListMenuItemStateEnum VappAlarmSnoozePage::getItemState(VfxU32 index) const
{
	VFX_ASSERT(index < ALARM_TOTAL_SNOOZE);
	
	if (m_snooze != index)
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
}

VfxBool VappAlarmSnoozePage::getItemText(
								VfxU32 index,					 // [IN] the index of item
								VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
								VfxWString &text,				 // [OUT] the text resource
								VcpListMenuTextColorEnum &color  // [OUT] the text color
								)
{
	if (fieldType != VCP_LIST_MENU_FIELD_TEXT || index >= ALARM_TOTAL_SNOOZE)
	{
		return VFX_FALSE;
	}

	text = ALARM_GET_SNOOZE_STR(index);
	color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

	return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappAlarmSettingPage
 *****************************************************************************/
VappAlarmSettingPage::VappAlarmSettingPage() 
	: m_form(NULL), 
	  m_snooze(0), 
	  m_volume(0),
	  m_volWeakPtr(NULL)
{
}
void VappAlarmSettingPage::onInit(void)
{
	VfxPage::onInit();

	m_snooze = VappAlarmApp::getSnoozeVal();

	// title bar
	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(STR_GLOBAL_SETTINGS);
	setTopBar(titleBar);

	// form
	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());	

	VcpFormItemLauncherCell *launchSnooze;
	VFX_OBJ_CREATE(launchSnooze, VcpFormItemLauncherCell, m_form);
	launchSnooze->setMainText(STR_ID_VAPP_ALARM_SNOOZE);

	VfxU8 index = ALARM_GET_SNOOZE_IDX(m_snooze);
	launchSnooze->setHintText(ALARM_GET_SNOOZE_STR(index));
	launchSnooze->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchSnooze->m_signalTap.connect(this, &VappAlarmSettingPage::onItemCellLaunch);
	m_form->addItem(launchSnooze, ID_FORM_CELL_LAUNCH_SNOOZE);

	VcpFormItemLauncherCell *launchVolume;
	VFX_OBJ_CREATE(launchVolume, VcpFormItemLauncherCell, m_form);
	launchVolume->setMainText(STR_GLOBAL_VOLUME);
	launchVolume->m_signalTap.connect(this, &VappAlarmSettingPage::onItemCellLaunch);
	m_form->addItem(launchVolume, ID_FORM_CELL_LAUNCH_VOLUME);
}

void VappAlarmSettingPage::onExit(VfxBool isBackward)
{
	if (m_volWeakPtr.isValid())
	{
		VappSetVolumePopup *volPopup = m_volWeakPtr.get();

		volPopup->stopPreviewTimer();
	}
	
	VfxPage::onExit(isBackward);
}

void VappAlarmSettingPage::onItemCellLaunch(VcpFormItemCell * obj,VfxId id)
{
	switch(id)
	{
		case ID_FORM_CELL_LAUNCH_SNOOZE:
		{
			VappAlarmSnoozePage *snoozePage;
			VFX_OBJ_CREATE_EX(snoozePage, VappAlarmSnoozePage, getMainScr(), ALARM_GET_SNOOZE_IDX(m_snooze));
			snoozePage->m_signalSelected.connect(this, &VappAlarmSettingPage::onSnoozeSelect);
			getMainScr()->pushPage(VFX_ID_NULL, snoozePage);
			break;
		}	
			
		case ID_FORM_CELL_LAUNCH_VOLUME:
		{
			VappSetVolumePopup *volPop;
			VFX_OBJ_CREATE(volPop, VappSetVolumePopup, this);
			volPop->setVolRange(VappSetVolumePopup::VOL_7, VappSetVolumePopup::VOL_1);
			volPop->setInitVol(VappAlarmApp::getVol());
			volPop->setTitle(STR_GLOBAL_VOLUME);
			volPop->m_signalBtnClicked.connect(this, &VappAlarmSettingPage::onVolClick);
			volPop->show(VFX_TRUE);

			m_volWeakPtr = volPop;
			
			break;
		}

		default:
			break;
	}
}

void VappAlarmSettingPage::onVolClick(VfxU8 vol)
{
	VfxS16 errCode;
	
	WriteValue(NVRAM_ALARM_SETTINGS_VOL, &vol, DS_BYTE, &errCode);
}

void VappAlarmSettingPage::onSnoozeSelect(const VfxObject *obj, const VfxU8 &index)
{
	m_snooze = ALARM_GET_SNOOZE_VALUE(index);

	VcpFormItemLauncherCell *cell = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_LAUNCH_SNOOZE);
	cell->setHintText(ALARM_GET_SNOOZE_STR(index));

	VfxS16 errCode;
	WriteValue(NVRAM_ALARM_SETTINGS_SNOOZE, &m_snooze, DS_BYTE, &errCode);
}

