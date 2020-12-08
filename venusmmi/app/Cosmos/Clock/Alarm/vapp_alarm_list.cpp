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
 *  vapp_alarm_list.cpp
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

//#include "mmi_rp_vapp_alarm_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_alarm_def.h"
#include "mmi_rp_vapp_clock_def.h"

#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif

#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "data\vdat_systime.h"

#include "vcp_navi_title_bar.h"
#include "vcp_confirm_popup.h"
#include "vcp_tool_bar.h"

#include "vapp_alarm.h"
#include "vapp_alarm_list.h"
#include "vapp_alarm_list_menu.h"
#include "vapp_alarm_edit.h"
#include "vapp_alarm_clock.h"
#include "vapp_alarm_setting.h"

#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }


/*#define ID_TOOLBAR_BTN1		'BTN1'
#define ID_TOOLBAR_BTN2		'BTN2'
#define ID_TOOLBAR_BTN3		'BTN3'
#define ID_TOOLBAR_BTN4		'BTN4'
#define ID_TOOLBAR_BTN5		'BTN5'
#define ID_TOOLBAR_BTN6		'BTN6'*/




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
 * Class VappAlarmRecentFrame
 *****************************************************************************/
#ifndef __MMI_ALARM_SLIM__

VappAlarmRecentFrame::VappAlarmRecentFrame() :
	m_time(NULL),
	m_txtLabel(NULL),
	m_clock(NULL),
	m_almIdx(0xFF)
{
}
VappAlarmRecentFrame::VappAlarmRecentFrame(const VfxU16& index) :
	m_time(NULL),
	m_txtLabel(NULL),
	m_clock(NULL),
	m_almIdx(index)
{
}

void VappAlarmRecentFrame::onInit()
{
    VfxFrame::onInit();

	VfxImageFrame *bgImage;
	VFX_OBJ_CREATE(bgImage, VfxImageFrame, this);
	bgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	bgImage->setResId(IMG_ID_VAPP_ALARM_BG);
	bgImage->setBounds(0, 0, getParentFrame()->getSize().width, HEIGHT);
	setIsCached(VFX_TRUE);
	setSize(bgImage->getSize());

	VFX_OBJ_CREATE(m_txtLabel, VfxTextFrame, this);

	update();
}

void VappAlarmRecentFrame::update(void)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_UPDATE_RECENT, m_almIdx);
	
	VfxFontDesc font;
	srv_alm_node_type *node = srv_alm_read(m_almIdx);
	
	if (node != NULL)
	{
		VfxU16 height = getSize().height - (LABEL_FONT_SIZE + TIME_FONT_SIZE + TXT_MARGIN);
		height = height >> 1;
		font.size = VFX_FONT_DESC_VF_SIZE(LABEL_FONT_SIZE);
		m_txtLabel->setFont(font);
		m_txtLabel->setAnchor(0.0F, 0.0F);
		m_txtLabel->setPos(LABEL_POS_X, height);
		m_txtLabel->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_txtLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		
		VfxWString strLabel = VFX_WSTR_RES(STR_ID_VAPP_ALARM_NEXT_ALARM);
		
		if (vfx_sys_wcslen((const VfxWChar*)node->label) != 0)
		{
			strLabel += VFX_WSTR_MEM((const VfxWChar*)node->label);
		}
		
		m_txtLabel->setString(strLabel);
		m_txtLabel->setColor(VFX_COLOR_RES(VAPP_ALARM_SUB_COLOR));
		
		
		if (m_time == NULL)
		{
			VFX_OBJ_CREATE_EX(m_time, VappAlarmTimeFrame, this, (node->Hour, node->Min, TIME_FONT_SIZE, AMPM_FONT_SIZE));
			m_time->setPos(TIME_POS_X, 
						   LABEL_POS_Y + m_txtLabel->getBounds().getHeight() + TXT_MARGIN);
		}
		else
		{
			m_time->setTime(node->Hour, node->Min);
		}
		
		VfxSize size = m_txtLabel->getSize();
		m_txtLabel->setSize(m_time->getSize().width, size.height);

		if (m_clock == NULL)
		{
			VFX_OBJ_CREATE_EX(m_clock, VappAlarmClock, this, (node->Hour, node->Min));
			m_clock->setAnchor(1.0F, 0.5F);
			m_clock->setPos(getSize().width - CLOCK_RIGHT_MARGIN, ((getSize().height-4) >> 1));	
		}
		else
		{
			m_clock->setClockTime(node->Hour, node->Min);
		}
	}
	else
	{
		VFX_OBJ_CLOSE(m_time);
		VFX_OBJ_CLOSE(m_clock);
	
		font.size = VFX_FONT_DESC_VF_SIZE(NON_ALM_FONT_SIZE);
		m_txtLabel->setFont(font);
		m_txtLabel->setAnchor(0.5F, 0.5F);		
		m_txtLabel->setPos((getParentFrame()->getSize().width >> 1), (HEIGHT >> 1));
		m_txtLabel->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
		m_txtLabel->setString(STR_ID_VAPP_ALARM_NO_ALARM_SET);
		m_txtLabel->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
		m_txtLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	}	
}

void VappAlarmRecentFrame::setIndex(const VfxU16& index)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_SET_RECENT, index);

	m_almIdx = index;
	update();
}

VfxU16 VappAlarmRecentFrame::getIndex(void) const
{
	return m_almIdx;
}

#endif 
/***************************************************************************** 
 * Class VappAlarmlistPage
 *****************************************************************************/
mmi_ret VappAlarmlistPage::onEvtHandler(mmi_event_struct *evt)
{
	VappAlarmlistPage *page = (VappAlarmlistPage *)evt->user_data;

	return page->onOpEvt(evt);
}

VappAlarmlistPage::VappAlarmlistPage() :
	                    #ifndef __MMI_ALARM_SLIM__
						m_recentAlm(NULL), 
						#endif
						m_list(NULL), 
						m_toolbar(NULL)						
{
}
void VappAlarmlistPage::onInit(void)
{
    VfxPage::onInit(); 

	// title bar
//	VcpTitleBar *titleBar;
//	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
//	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_ALARM));
//	setTopBar(titleBar);

    //tool bar
    VFX_OBJ_CREATE(m_toolbar,VcpToolBar,this);
	m_toolbar->m_signalButtonTap.connect(this, &VappAlarmlistPage::onToolbarClick);
    setBottomBar(m_toolbar);	
   
	mmi_frm_cb_reg_event(EVT_ID_SRV_ALM_OP, VappAlarmlistPage::onEvtHandler, this);

	VFX_OBJ_CREATE(m_list, VappAlmCustomListMenu, this);
	m_list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

	reset();
}

void VappAlarmlistPage::onDeinit(void)
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_ALM_OP, VappAlarmlistPage::onEvtHandler, this);
	
    VfxPage::onDeinit(); 
}

void VappAlarmlistPage::onBack(void)
{
	if (m_list->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
	{
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_BACK, 0);
		changeMode(VappAlmCustomListMenu::LIST_MODE_LIST);
	}
	else
	{
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_BACK, 2);
		VfxPage::onBack();
	}
}

void VappAlarmlistPage::onEnter(VfxBool isBackward)
{
	vrt_canvas_enable_1st_frame_dithering(VRT_TRUE);
	refresh();	
	#ifndef __MMI_ALARM_SLIM__
	if (m_recentAlm == NULL)
	{
		m_list->setPos(VFX_POINT_ZERO);
		m_list->setSize(getSize());
	}
	else
	{
		m_list->setPos(0, m_recentAlm->getBounds().getMaxY());
	
		VfxS32 height = getSize().height - 	m_recentAlm->getSize().height;
		m_list->setSize(getSize().width, height);
	}
	#else
	
	m_list->setPos(VFX_POINT_ZERO);
	m_list->setSize(getSize());
		
	#endif
}

mmi_ret VappAlarmlistPage::onOpEvt(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SRV_ALM_OP && m_list != NULL)
	{
		srv_alm_op_evt_struct *opEvt = (srv_alm_op_evt_struct *)evt;

		if (opEvt->operation == SRV_ALM_OP_MODIFY)
		{
			m_list->updateOneItem(opEvt->index);
		}
	}
	return MMI_RET_OK;
}

void VappAlarmlistPage::reset(void)
{
	VfxU8 list[NUM_OF_ALM];
	VfxU8 count;
	
	VappAlarmApp::getAlmList(list, count);
	
	
	m_toolbar->removeItem(ID_TOOLBAR_BTN4);
	m_toolbar->removeItem(ID_TOOLBAR_BTN5);
	m_toolbar->removeItem(ID_TOOLBAR_BTN6);
		
	m_toolbar->addItem(ID_TOOLBAR_BTN1, STR_GLOBAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
	m_toolbar->addItem(ID_TOOLBAR_BTN2, STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	#ifndef __MMI_ALARM_SLIM__
	m_toolbar->addItem(ID_TOOLBAR_BTN3, STR_GLOBAL_SETTINGS, VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
	#endif

	
	m_list->setEditMode(VappAlmCustomListMenu::LIST_MODE_LIST);

	if (count != 0)
	{	
		m_toolbar->setDisableItem(ID_TOOLBAR_BTN2, VFX_FALSE);
		#ifndef __MMI_ALARM_SLIM__

		if (m_recentAlm == NULL)
		{
			VFX_OBJ_CREATE_EX(m_recentAlm, VappAlarmRecentFrame, this, (VappAlarmApp::getRecentAlm()));		
		}
        #endif
		m_list->m_signalDeleteDone.connect(this, &VappAlarmlistPage::onDeleteDone);
		m_list->m_signalTap.connect(this, &VappAlarmlistPage::onListItemTap);
		m_list->m_signalSwitch.connect(this, &VappAlarmlistPage::onListItemSwitch);
		
		// Refresh timer
    	VdatTimeNotification *sysTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    	sysTimeSrv->m_signalTimeChanged.connect(this, &VappAlarmlistPage::onTimeChanged);		
	}
	else
	{
        #ifndef __MMI_ALARM_SLIM__
		VFX_OBJ_CLOSE(m_recentAlm);
        #endif
     	m_toolbar->setDisableItem(ID_TOOLBAR_BTN2, VFX_TRUE);
	}
}

void VappAlarmlistPage::onListItemTap(VfxObject * obj, VfxU32 index)
{
	VFX_ASSERT(obj == m_list);

	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_TAP, index);
	
	VappAlarmEditPage *page;
	VFX_OBJ_CREATE_EX(page, VappAlarmEditPage, this, (index));
	page->m_signalChanged.connect(this, &VappAlarmlistPage::onEditDone);
	getMainScr()->pushPage(VFX_ID_NULL, page);	
}

void VappAlarmlistPage::onListItemSwitch(VfxU16 index, VfxBool newState)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_SWITCH, index, newState);
	// update recent alarm
	#ifndef __MMI_ALARM_SLIM__
	m_recentAlm->setIndex(VappAlarmApp::getRecentAlm());
    #endif
	VappAlarmApp::refreshStatusIcon();
}

void VappAlarmlistPage::onToolbarClick(VfxObject* obj, VfxId id)
{

	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_TOOLBAR, id);
    switch(id)
    {
        case ID_TOOLBAR_BTN1: /* Add */
		{
			VfxU8 newIndex = srv_alm_get_index();

			if (newIndex != 0xFF)
			{
				VappAlarmEditPage *page;
				VFX_OBJ_CREATE_EX(page, VappAlarmEditPage, this, (newIndex));
				page->m_signalChanged.connect(this, &VappAlarmlistPage::onEditDone);
				getMainScr()->pushPage(VFX_ID_NULL, page);
			}
			else
			{
				mmi_frm_nmgr_balloon(
					MMI_SCENARIO_ID_GENERAL,
					MMI_EVENT_INFO_BALLOON,
					MMI_NMGR_BALLOON_TYPE_INFO,
					(WCHAR *)GetString(STR_ID_VAPP_ALARM_MAX_NUMBER));

			}
			break;
        }
			
        case ID_TOOLBAR_BTN2: /* Delete */
        {
			changeMode(VappAlmCustomListMenu::LIST_MODE_DELETE);
            break;
        }
        #ifndef __MMI_ALARM_SLIM__

		case ID_TOOLBAR_BTN3: /* Settings */
		{
			VappAlarmSettingPage *page;
			VFX_OBJ_CREATE(page, VappAlarmSettingPage, this);
			getMainScr()->pushPage(VFX_ID_NULL, page);
			
			break;
		}
        #endif
		case ID_TOOLBAR_BTN4: /* Select All */
		{
		    VcpListMenuItemStateEnum state;
			
			state = m_bAll ? VCP_LIST_MENU_ITEM_STATE_UNSELECTED : VCP_LIST_MENU_ITEM_STATE_SELECTED;
						
			for (VfxU32 i = 0; i < m_list->getCount(); i++)
			{
				m_list->setListState(i, state);
				
			}
						 
			m_bAll = !m_bAll;
			break;
		}
		case ID_TOOLBAR_BTN5: /* Delete */
		{
			VcpConfirmPopup *confirm;
			VFX_OBJ_CREATE(confirm, VcpConfirmPopup, getMainScr());
			confirm->setInfoType(VCP_POPUP_TYPE_WARNING);

            VfxWString delTotal;
            delTotal.format("%d", m_list->getSelectedCount());
			VfxResId delResId = m_list->getSelectedCount() > 1 ? STR_ID_VAPP_ALARM_DELETE_SELECTED : STR_ID_VAPP_ALARM_DELETE_ONE_SELECTED;
            VfxWString text = VFX_WSTR_RES(delResId);
            text += VFX_WSTR_RES(STR_ID_VAPP_ALARM_L_BRACKET);
            text += delTotal;
            text += VFX_WSTR_RES(STR_ID_VAPP_ALARM_R_BRACKET);
            text += VFX_WSTR_RES(STR_ID_VAPP_ALARM_QUESTION_MARK);
            
            confirm->setText(text);
			confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
			confirm->setCustomButton(STR_GLOBAL_DELETE, 
									 STR_GLOBAL_CANCEL,
									 VCP_POPUP_BUTTON_TYPE_WARNING,
									 VCP_POPUP_BUTTON_TYPE_CANCEL);
			confirm->m_signalButtonClicked.connect(this, &VappAlarmlistPage::onDelCmdCallback);
			confirm->setAutoDestory(VFX_TRUE);

			confirm->show(VFX_TRUE);
			
            break;
        }
		
		case ID_TOOLBAR_BTN6: /* Cancel */
			changeMode(VappAlmCustomListMenu::LIST_MODE_LIST);
			break;
			
        default:
            break;
    }
}

void VappAlarmlistPage::onTimeChanged(VfxU32 flag)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_TIME);

    if (flag & VDAT_SYSTIME_CHANGED_MIN)
    {
    	refresh();
	}
}

void VappAlarmlistPage::refresh(void)
{
    #ifndef __MMI_ALARM_SLIM__

	if (m_recentAlm != NULL)
	{
		m_recentAlm->setIndex(VappAlarmApp::getRecentAlm());
	}
	#endif

	VfxU8 list[NUM_OF_ALM];
	VfxU8 total;
		
	VappAlarmApp::getAlmList(list, total);
		
	if ((total != m_list->getCount()) ||
			(memcmp(m_list->getIndexList(), list, total) != 0))
	{
		m_list->updateAllItems(VFX_TRUE);
	}
}


void VappAlarmlistPage::onEditDone(VfxObject *obj, VfxU8 index)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_EDIT_DONE);
	
	m_list->updateAllItems(VFX_TRUE);
	reset();
	refresh();
}

void VappAlarmlistPage::onDeleteDone(void)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_DEL_DONE);	
	onEditDone(NULL,NULL);
	onEnter(VFX_FALSE);
}

/***************************************************************************** 
 * Class VappAlarmlistPage Delete action
 *****************************************************************************/
void VappAlarmlistPage::changeMode(const VfxU16 &newMode)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_CHANGEMODE, newMode);
	
	switch (newMode)
	{
		case VappAlmCustomListMenu::LIST_MODE_DELETE:
		{
			m_list->m_signalTap.disconnect(this, &VappAlarmlistPage::onListItemTap);
			m_list->m_signalSwitch.disconnect(this, &VappAlarmlistPage::onListItemSwitch);

			createDelToolbar();
			m_list->setEditMode(newMode);
			
			break;
		}
		case VappAlmCustomListMenu::LIST_MODE_LIST:
		{
			reset();
			break;
		}
		default:
			break;
	}
}

void VappAlarmlistPage::createDelToolbar(void)
{
	m_toolbar->removeItem(ID_TOOLBAR_BTN1);
	m_toolbar->removeItem(ID_TOOLBAR_BTN2);
	#ifndef __MMI_ALARM_SLIM__
	m_toolbar->removeItem(ID_TOOLBAR_BTN3);
    #endif
	m_toolbar->addItem(ID_TOOLBAR_BTN4, STR_ID_VAPP_ALARM_MARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_toolbar->addItem(ID_TOOLBAR_BTN5, STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	m_toolbar->addItem(ID_TOOLBAR_BTN6, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

	m_toolbar->setDisableItem(ID_TOOLBAR_BTN5, VFX_TRUE);
	

	m_bAll = VFX_FALSE;
	m_list->m_signalHasSelect.connect(this, &VappAlarmlistPage::onSelChange);
}
void VappAlarmlistPage::onSelChange(VfxObject *obj, VfxU32 count)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_SEL_CHANGE, count);
	
	if (m_list->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
	{
		m_toolbar->setDisableItem(ID_TOOLBAR_BTN5, (count == 0));

		if (count == m_list->getCount())
		{
			m_bAll = VFX_TRUE;
			m_toolbar->changeItem(ID_TOOLBAR_BTN4, STR_ID_VAPP_ALARM_UNMARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
		}
		else
	    {
			m_bAll = VFX_FALSE;			
			m_toolbar->changeItem(ID_TOOLBAR_BTN4, STR_ID_VAPP_ALARM_MARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
		}
	}
}

void VappAlarmlistPage::onDelCmdCallback(VfxObject *obj, VfxId id)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_LIST_ON_DEL_CMD, id);
	
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		m_list->deleteSelectedItems();
		onDeleteDone();
	    changeMode(VappAlmCustomListMenu::LIST_MODE_LIST);
     }
}

#pragma arm section code, rodata
