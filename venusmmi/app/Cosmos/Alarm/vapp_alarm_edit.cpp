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
 *  vapp_alarm_edit.cpp
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
	#include "ReminderSrvGprot.h"
	#include "AlarmSrvGprot.h"
	#include "GlobalResDef.h"
    #include "generalsettingsrvgprot.h"    
}

#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_vapp_alarm_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_date_time.h"
#include "vcp_time_picker.h"
#include "vcp_button.h"
#include "vcp_function_bar.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vcui_tone_selector_gprot.h"

#include "vapp_alarm_edit.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ID_TOOLBAR_SELECT_ALL	'ALL'
#define ID_TOOLBAR_SAVE			'SAVE'
#define ID_TOOLBAR_CANCEL		'CANL'

#define VAPP_ALARM_DEFAULT_TONE SRV_PROF_AUD_TONE1
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
 * Class VappAlarmRepeatPage
 *****************************************************************************/
VappAlarmRepeatPage::VappAlarmRepeatPage() : 
						m_list(NULL), 
						m_days(0), 
						m_bAll(VFX_FALSE)
{
	for (VfxU32 i = 0; i < ALARM_TOTAL_WDAY; i++)
	{
		m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}
VappAlarmRepeatPage::VappAlarmRepeatPage(const VfxU8 &days) 	:
						m_list(NULL), 
						m_days(days), 
						m_bAll(VFX_FALSE)
{
	for (VfxU32 i = 0; i < ALARM_TOTAL_WDAY; i++)
	{
		if (days & (1 << i))
		{
			m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
		}
		else
		{
			m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
		}
	}
}

void VappAlarmRepeatPage::onInit(void)
{
	VfxPage::onInit();

	// title bar
	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ALARM_REPEAT));
	setTopBar(titleBar);

    //tool bar
    VcpToolBar *toolBar; 
    VFX_OBJ_CREATE(toolBar,VcpToolBar,this);
    toolBar->addItem(ID_TOOLBAR_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    toolBar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	toolBar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	toolBar->m_signalButtonTap.connect(this, &VappAlarmRepeatPage::onToolbarClick);
    setBottomBar(toolBar);

	VFX_OBJ_CREATE(m_list,VcpListMenu,this);
	m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_list->setContentProvider(this);
	m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_FALSE);
	m_list->m_signalItemSelectionStateChanged.connect(this, &VappAlarmRepeatPage::onListItemSelect);
	m_list->setSize(getSize());	
	m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	if (m_days == ALARM_REPEAT_EVERYDAY)
	{
		m_bAll = VFX_TRUE;
		toolBar->changeItem(ID_TOOLBAR_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
	}
	else
	{
		m_bAll = VFX_FALSE;
	}
	
}

void VappAlarmRepeatPage::onListItemSelect(VcpListMenu *obj, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	m_stateLst[index] = newState;
	if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
	{
		m_days |= (1 << index);
	}
	else
	{
		m_days &= ~(1 << index);
	}

	VcpToolBar *toolBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM), VcpToolBar);
	VFX_ASSERT(toolBar != NULL);

	if (m_days == ALARM_REPEAT_EVERYDAY)
	{
		m_bAll = VFX_TRUE;
		toolBar->changeItem(ID_TOOLBAR_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
	}
	else
	{
		m_bAll = VFX_FALSE;
		toolBar->changeItem(ID_TOOLBAR_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);	
	}

}

VcpListMenuItemStateEnum VappAlarmRepeatPage::getItemState(VfxU32 index) const
{
	VFX_ASSERT(index < ALARM_TOTAL_WDAY);
	
	return m_stateLst[index];
}


VfxBool VappAlarmRepeatPage::getItemText(
								VfxU32 index,					 // [IN] the index of item
								VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
								VfxWString &text,				 // [OUT] the text resource
								VcpListMenuTextColorEnum &color  // [OUT] the text color
								)
{
	if (fieldType != VCP_LIST_MENU_FIELD_TEXT || index >= ALARM_TOTAL_WDAY)
	{
		return VFX_FALSE;
	}

	text = ALARM_GET_WDAY_STR(index);
	color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

	return VFX_TRUE;
}

void VappAlarmRepeatPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case ID_TOOLBAR_SELECT_ALL:
		{
			VcpListMenuItemStateEnum state = m_bAll ? VCP_LIST_MENU_ITEM_STATE_UNSELECTED : VCP_LIST_MENU_ITEM_STATE_SELECTED;

			for (VfxU32 i = 0; i < ALARM_TOTAL_WDAY; i++)
			{
				m_stateLst[i] = state;
				
				m_list->updateItem(i);
			}
			
			m_bAll = !m_bAll;
			
			VcpToolBar *toolBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM), VcpToolBar);
			VFX_ASSERT(toolBar != NULL);

			if (state == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
			{
                                m_days = 0;
				toolBar->changeItem(ID_TOOLBAR_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
			}
			else
			{
				m_days = ALARM_REPEAT_EVERYDAY;
				toolBar->changeItem(ID_TOOLBAR_SELECT_ALL, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
			}

			break;
		}
			
		case ID_TOOLBAR_SAVE:
		{
			VfxU8 days = 0;
			
			for (VfxU8 i = 0; i < ALARM_TOTAL_WDAY; i++)
			{
				if (m_stateLst[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
				{
					days |= (1 << i);
				}				
			}	
			m_signalSelectDay.postEmit(this, days);
		}
		
		case ID_TOOLBAR_CANCEL:
			getMainScr()->popPage();
			break;
			
		default:
			break;
	}
}


/***************************************************************************** 
 * Class VappAlarmFormItemSwitchCell
 *****************************************************************************/
void VappAlarmFormItemSwitchCell::onCellTap(VfxPenEvent & event)
{
	VcpFormItemSwitchCell::onCellTap(event);
	if(getIsDisabled())
	{
		return;
	}
	if(event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		m_signalTap.postEmit(this, m_id);
	}
}


/***************************************************************************** 
 * Class VappAlarmEditPage
 *****************************************************************************/
VappAlarmEditPage::VappAlarmEditPage() :
	m_funcBar(NULL),
	m_pNode(NULL),
	m_form(NULL), 
	m_index(0xFF), 
	m_repeat(0),
	m_firstEnter(VFX_TRUE)
{
}
VappAlarmEditPage::VappAlarmEditPage(const VfxU8 &index) :
	m_funcBar(NULL),
	m_pNode(NULL),
	m_form(NULL), 
	m_index(index), 
	m_repeat(0),
	m_firstEnter(VFX_TRUE)
{
}
void VappAlarmEditPage::onInit(void)
{
	VfxPage::onInit();

	// title bar
	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ALARM_SET_ALARM));
	setTopBar(titleBar);

	//tool bar

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	toolBar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	toolBar->m_signalButtonTap.connect(this, &VappAlarmEditPage::onToolbarClick);
	setBottomBar(toolBar);

	// form
	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	VcpTimePicker *timePicker;
	VFX_OBJ_CREATE(timePicker, VcpTimePicker, m_form);
	if (srv_setting_get_time_format() == SETTING_TIME_FORMAT_24_HOURS)
	{
		timePicker->setIs24HourView(VFX_TRUE);
	}
	timePicker->setAnchor(0.5F, 0);
	timePicker->setPos(LCD_WIDTH / 2, 0);
	//timePicker->setTime(ttime);
	
	VcpFormItemCustomFrame *customPicker;
	VFX_OBJ_CREATE(customPicker, VcpFormItemCustomFrame, m_form);
	customPicker->attachCustomFrame(timePicker);
	m_form->addItem(customPicker, ID_FORM_CELL_CUSTOM_PICKER);

	//m_repeat = m_pNode->Days;
	
	VcpFormItemLauncherCell *launchRepeat;
	VFX_OBJ_CREATE(launchRepeat, VcpFormItemLauncherCell, m_form);
	launchRepeat->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchRepeat->setMainText(VFX_WSTR_RES(STR_ID_VAPP_ALARM_REPEAT));
	//launchRepeat->setHintText(VappAlarmApp::getRepeatString(m_pNode->Freq, m_pNode->Days));
	launchRepeat->m_signalTap.connect(this, &VappAlarmEditPage::onItemCellLaunch);
	m_form->addItem(launchRepeat, ID_FORM_CELL_LAUNCH_REPEAT);


	VappAlarmFormItemSwitchCell *switchRingTone;
	VFX_OBJ_CREATE(switchRingTone, VappAlarmFormItemSwitchCell, m_form);
	switchRingTone->setMainText(VFX_WSTR_RES(STR_GLOBAL_RINGTONE));
	//switchRingTone->setHintText(getToneString());
	//switchRingTone->setSwitchStatus((m_pNode->ringtone != 0));
	switchRingTone->m_signalSwitchChangeReq.connect(this, &VappAlarmEditPage::onItemSwitchReq);
	switchRingTone->m_signalTap.connect(this, &VappAlarmEditPage::onItemCellLaunch);
	switchRingTone->setIsTappable(VFX_TRUE);
	m_form->addItem(switchRingTone, ID_FORM_CELL_SWITCH_RING);

	VcpFormItemSwitchCell *switchVib;
	VFX_OBJ_CREATE(switchVib, VcpFormItemSwitchCell, m_form);
	switchVib->setMainText(VFX_WSTR_RES(STR_ID_VAPP_ALARM_VIBRATE));
	//switchVib->setSwitchStatus((m_pNode->vibrate != 0));
	switchVib->m_signalSwitchChangeReq.connect(this, &VappAlarmEditPage::onItemSwitchReq);
	m_form->addItem(switchVib, ID_FORM_CELL_SWITCH_VIB);


	//VcpFormItemTextInput *txtLabel;
	VFX_OBJ_CREATE(txtLabel, VcpFormItemTextInput, m_form);
	txtLabel->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_ALARM_LABEL));
	//txtLabel->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
	//txtLabel->getTextBox()->setText(VFX_WSTR_MEM((VfxWChar *)m_pNode->label),
									//(MMI_ALM_MAX_LABEL_LENGTH >> 1) - 1);
	m_form->addItem(txtLabel, ID_FORM_CELL_TXT_LABEL);

	
	//add or edit,set the CP state
	srv_alm_node_type *node = srv_alm_read(m_index);
	VFX_ASSERT(node != NULL);

    VcpTimePickerStruct ttime;

   if(node->Hour != 0xFF) //edit a node
   	{
   	VFX_ALLOC_MEM(m_pNode, sizeof(srv_alm_node_type), this);
	memcpy(m_pNode, node, sizeof(srv_alm_node_type));
	
	m_repeat = m_pNode->Days;
	
	ttime.hour = m_pNode->Hour;
	ttime.minute = m_pNode->Min;
	timePicker->setTime(ttime);
	
	launchRepeat->setHintText(VappAlarmApp::getRepeatString(m_pNode->Freq, m_pNode->Days));

	switchRingTone->setHintText(getToneString());
	switchRingTone->setSwitchStatus((m_pNode->ringtone != 0));

	switchVib->setSwitchStatus((m_pNode->vibrate != 0));
	
	txtLabel->getTextBox()->setText(VFX_WSTR_MEM((VfxWChar *)m_pNode->label),
									(MMI_ALM_MAX_LABEL_LENGTH >> 1) - 1);
   	}
   else   //add a new node
   	{
   	VfxDateTime time;
	time.setCurrentTime();
	
	ttime.hour = (VfxU8)time.getHour();
	ttime.minute = (VfxU8)time.getMinute();
    timePicker->setTime(ttime);
		   
   launchRepeat->setHintText(VFX_WSTR_RES(STR_ID_VAPP_ALARM_REPEAT_ONCE));

	 
	VfxWString strTemp;  
    VfxU16 aud_id = srv_prof_get_audio_id_from_audio_resourece(
							SRV_PROF_AUDIO_RES_TONE, 
							0);
	VfxResId resId = srv_prof_get_string_id_from_srv_audio_id(aud_id);
	strTemp.loadFromRes(resId);
    switchRingTone->setHintText(strTemp);
	switchRingTone->setSwitchStatus(VFX_TRUE);
	
    switchVib->setSwitchStatus(VFX_FALSE);
	   
		   
    txtLabel->getTextBox()->setText(VFX_WSTR(""), (MMI_ALM_MAX_LABEL_LENGTH >> 1) - 1);
   	}

	
}

void VappAlarmEditPage::onEntered(void)
	
{
	if(m_firstEnter)
  	{
	srv_alm_node_type *node = srv_alm_read(m_index);
	if (node->Hour == 0xFF)//add a new node
	{	
	   
	   VFX_ALLOC_MEM(m_pNode, sizeof(srv_alm_node_type), this);
		initNode(m_pNode);
		m_repeat = m_pNode->Days;
	}

	   VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
		m_funcBar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
		m_funcBar->setItemSpecial(ID_TOOLBAR_SAVE);
		m_funcBar->m_signalButtonTap.connect(this, &VappAlarmEditPage::onFuncBarClick);
		
		txtLabel->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
	}
	  m_firstEnter=VFX_FALSE;


}

void VappAlarmEditPage::onDeinit(void)
{
	VFX_OBJ_CLOSE(txtLabel);
	VFX_OBJ_CLOSE(m_funcBar);
	VFX_FREE_MEM(m_pNode);

	VfxPage::onDeinit();
}

void VappAlarmEditPage::initNode(srv_alm_node_type *node)
{
	memset(node, 0, sizeof(srv_alm_node_type));
		
	VfxDateTime time;
	time.setCurrentTime();
	node->State = 1;
	node->Hour = (VfxU8)time.getHour();
	node->Min = (VfxU8)time.getMinute();
	//node->Freq = 0;
	node->ringtone = 1;
	node->vibrate = 0;	/* default vibration state is OFF*/
	node->AudioOption = SRV_PROF_AUDIO_RES_TONE;
	node->AudioOptionValue = 0;
	node->Freq = SRV_REMINDER_REPEAT_ONCE;
	node->label[0] = 0;
	node->label[1] = 0;
}

void VappAlarmEditPage::onItemSwitchReq(VcpFormItemSwitchCell *obj, VfxId id, VfxBool newState)
{
	obj->setSwitchStatus(newState);
}

void VappAlarmEditPage::onRepeatSelection(VfxObject *obj, VfxU8 days)
{
	m_repeat = days;

	VcpFormItemLauncherCell *launchRepeat = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_LAUNCH_REPEAT);
	VfxU16 repeat = days == 0 ? SRV_REMINDER_REPEAT_ONCE : SRV_REMINDER_REPEAT_DAYS;
	
	launchRepeat->setHintText(VappAlarmApp::getRepeatString(repeat, days));
}

void VappAlarmEditPage::onItemCellLaunch(VcpFormItemCell *obj, VfxId id)
{
	switch (id)
	{
		case ID_FORM_CELL_LAUNCH_REPEAT:
		{
			VappAlarmRepeatPage *page;
			VFX_OBJ_CREATE_EX(page, VappAlarmRepeatPage, this, (m_repeat));
			page->m_signalSelectDay.connect(this, &VappAlarmEditPage::onRepeatSelection);
			getMainScr()->pushPage(VFX_ID_NULL, page);
			break;
		}	
			
		case ID_FORM_CELL_SWITCH_RING:
		{
			m_cuiGrpId = vcui_tone_selector_create(getMainScr()->getGroupId());
			vfxSetCuiCallerScr(m_cuiGrpId, getMainScr());
			
			if (m_cuiGrpId != GRP_ID_INVALID)
			{			
				vcui_tone_selector_set_filter(m_cuiGrpId, 
					VCUI_TONE_SELECTOR_FILTER_TONE | VCUI_TONE_SELECTOR_FILTER_RING | VCUI_TONE_SELECTOR_FILTER_FILE);

				vcui_tone_selector_set_title_id(m_cuiGrpId, STR_GLOBAL_RINGTONE, IMG_GLOBAL_L1); 

				VfxU16 value;
				if (m_pNode->AudioOption == SRV_PROF_AUDIO_RES_TONE || 
					m_pNode->AudioOption == SRV_PROF_AUDIO_RES_RING)
				{					
					value = srv_prof_get_audio_id_from_audio_resourece(
									(srv_prof_audio_resource_type_enum)m_pNode->AudioOption,
									m_pNode->AudioOptionValue);
				}
				else
				{
					if (srv_fmgr_fs_path_exist((const WCHAR *)m_pNode->tone_path) < 0)
					{					
						m_pNode->AudioOption = SRV_PROF_AUDIO_RES_TONE;
						m_pNode->AudioOptionValue = 0;
						value = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE, 0);
					}
					else
					{
						value = 0;
					}
				}

				vcui_tone_selector_set_hightlight_tone(m_cuiGrpId, value);
				vcui_tone_selector_run(m_cuiGrpId);
			}
			
			break;
		}
		
		default:
			break;
	}
}


VfxWString VappAlarmEditPage::getToneString(void) const
{
	if (m_pNode == NULL)
	{
		return VFX_WSTR_NULL;
	}
	
	VfxWString strTemp;
	
	if (m_pNode->AudioOption == SRV_PROF_AUDIO_RES_TONE ||
		m_pNode->AudioOption == SRV_PROF_AUDIO_RES_RING)
	{
		VfxU16 aud_id = srv_prof_get_audio_id_from_audio_resourece(
							(srv_prof_audio_resource_type_enum)m_pNode->AudioOption, 
							m_pNode->AudioOptionValue);
		VfxResId resId = srv_prof_get_string_id_from_srv_audio_id(aud_id);
		
		strTemp.loadFromRes(resId);
	}
	else if (m_pNode->AudioOption == SRV_PROF_AUDIO_RES_FILE)
	{
		strTemp = VappAlarmApp::checkPathExt((VfxWChar *)m_pNode->tone_path, (const VfxWChar*)L"mp3");
	}
	
	return strTemp;
}

mmi_ret VappAlarmEditPage::onProc(mmi_event_struct *evt)
{
	VFX_ASSERT(evt != NULL);
	
	switch(evt->evt_id)
	{
		case EVT_ID_VCUI_TONE_SELECTOR_RESULT:
		{
			vcui_tone_selector_evt_struct *tone_evt = (vcui_tone_selector_evt_struct *)evt;

			if (tone_evt->is_default_sound)
			{
				VfxU16 index;
				m_pNode->AudioOption = srv_prof_get_audio_info_from_audio_resourece(tone_evt->selected_tone, &index);
				m_pNode->AudioOptionValue = index;
			}
			else
			{
				srv_fmgr_fileinfo_struct fmgr_info;
				vcui_tone_selector_get_selected_filepath(
					m_cuiGrpId,
					&fmgr_info,
					(VfxWChar *)m_pNode->tone_path,
					SRV_FMGR_PATH_BUFFER_SIZE);

				m_pNode->AudioOption = SRV_PROF_AUDIO_RES_FILE;
			}
			
			break;
		}

		case EVT_ID_VCUI_TONE_SELECTOR_CLOSE_REQUEST:
		{
			vcui_tone_selector_close(m_cuiGrpId);
			m_cuiGrpId = GRP_ID_INVALID;
			
			VcpFormItemLauncherCell *launchRingTone;
			launchRingTone = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_SWITCH_RING);
			launchRingTone->setHintText(getToneString());
			break;
		}
		
		default:
			break;
	};

	return VfxPage::onProc(evt);
}


void VappAlarmEditPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	/*switch(id)
	{
		case ID_TOOLBAR_SAVE:
			save();
			// go thur to next case
		case ID_TOOLBAR_CANCEL:
			break;
		
		default:
			break;
	}*/
	if(id==ID_TOOLBAR_SAVE)
   {
	  save();
	}
	
	getMainScr()->popPage();				
}

void VappAlarmEditPage::onFuncBarClick(VfxObject *sender, VfxId id)
{
	if (id == ID_TOOLBAR_SAVE)
	{
		onToolbarClick(NULL, id);
	}
}

void VappAlarmEditPage::save(void)
{
	VcpFormItemCustomFrame *customCell  = (VcpFormItemCustomFrame *)m_form->getItem(ID_FORM_CELL_CUSTOM_PICKER);
	VcpTimePicker *timePicker = (VcpTimePicker *)customCell->getFrame();
	VcpTimePickerStruct time = timePicker->getTime();
	
	m_pNode->Hour = time.hour;
	m_pNode->Min  = time.minute;
	
	VcpFormItemSwitchCell *switchRingTone  = (VcpFormItemSwitchCell *)m_form->getItem(ID_FORM_CELL_SWITCH_RING);
	m_pNode->ringtone = switchRingTone->getSwitchStatus() ? 1 : 0;

	VcpFormItemSwitchCell *switchVib  = (VcpFormItemSwitchCell *)m_form->getItem(ID_FORM_CELL_SWITCH_VIB);
	m_pNode->vibrate = switchVib->getSwitchStatus() ? 1 : 0;

	m_pNode->Snooze = 0;
	
	m_pNode->Days = m_repeat;

	if (m_repeat == 0)
	{
		m_pNode->Freq = SRV_REMINDER_REPEAT_ONCE;
	}
	else if (m_repeat == ALARM_REPEAT_EVERYDAY)
	{
		m_pNode->Freq = SRV_REMINDER_REPEAT_EVERYDAY;
	}
	else
	{
		m_pNode->Freq = SRV_REMINDER_REPEAT_DAYS;
	}

	VcpFormItemTextInput *inputLabel = (VcpFormItemTextInput *)m_form->getItem(ID_FORM_CELL_TXT_LABEL);
	vfx_sys_wcscpy((VfxWChar *)m_pNode->label, inputLabel->getText().getBuf());
	m_pNode->timestamp = ALARM_GET_TIMESTAMP;
	
	VfxU8 snoozeVal;
	VfxS16 errCode;
	ReadValue(NVRAM_ALARM_SETTINGS_SNOOZE, &snoozeVal, DS_BYTE, &errCode);
	
	m_pNode->SnoozeInterval = snoozeVal;
	
	srv_alm_write(m_index, m_pNode);
	
	m_signalChanged.postEmit(this, m_index);

}

