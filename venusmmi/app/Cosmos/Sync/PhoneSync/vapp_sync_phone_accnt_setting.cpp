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
 *  vapp_sync_phone_accnt_edit.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"
#include "GlobalResDef.h"

#include "vapp_sync_phone_accnt_edit.h"
#include "vapp_sync_phone_accnt_edit_name.h"
#include "vapp_sync_accnt_edit_select_database.h"
#include "vapp_sync_phone_accnt_setting.h"
#include "SyncSrvGprot.h"
#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define ID_TOOLBAR_SYNC_EDIT_SYNC	'SYNC'
#define ID_TOOLBAR_SYNC_EDIT_DELETE	'DEL'
#define ID_TOOLBAR_SYNC_EDIT_VLOG	'CANL'

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
 
/***************************************************************************** 
 * Class VappSyncPhoneAccntSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncPhoneAccntSettingPage", VappSyncPhoneAccntSettingPage, VfxPage);
VappSyncPhoneAccntSettingPage::VappSyncPhoneAccntSettingPage(const VfxS32 &accntIndex) 
	: m_form(NULL),
	  m_list(NULL),
  	  m_accntIndex(accntIndex),
  	  m_databaseMask(0)
{
	for (VfxU8 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

void VappSyncPhoneAccntSettingPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_SETTINGS));
	setTopBar(titleBar);

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem('OK', VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);

	toolBar->m_signalButtonTap.connect(this, &VappSyncPhoneAccntSettingPage::onToolbarClick);
	setBottomBar(toolBar);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	VcpFormItemCaption *appCaption;
	VFX_OBJ_CREATE(appCaption, VcpFormItemCaption, m_form);
	appCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_APP_TO_SYNC));
	m_form->addItem(appCaption, ID_FORM_CELL_CAP_APP);
	
	VcpFormItemCustomFrame *custFrame;
	VFX_OBJ_CREATE(custFrame, VcpFormItemCustomFrame, m_form);

	VFX_OBJ_CREATE(m_list, VcpListMenu, this);
	m_list->setContentProvider(this);
	m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_FALSE);
	m_list->m_signalItemSelectionStateChanged.connect(this, &VappSyncPhoneAccntSettingPage::onListItemSelect);
	m_list->setSize(getSize().width, (m_list->getItemHeight(0) * getCount()));
	m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	custFrame->attachCustomFrame(m_list);
	m_form->addItem(custFrame, ID_FORM_CELL_SEL_DATABASE);
}

void VappSyncPhoneAccntSettingPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	VFX_ASSERT(id == 'OK');
	
	m_databaseMask = 0;
	
	for (VfxU8 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (m_stateLst[i] == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
			m_databaseMask |= VAPP_SYNC_GET_DB_MASK(i);
		}
	}

	if (m_databaseMask == 0)
	{
		VfxWString balloonStr;
		balloonStr.loadFromRes(STR_ID_VAPP_SYNC_PLS_SEL_APP);
		
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)balloonStr.getBuf());

		return;
	}

	nvram_ef_syncml_device_accnt_struct *accnt;
	
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_accntIndex);
	accnt->timestamp = srv_sync_get_current_time();
	accnt->app_to_sync = m_databaseMask;
	accnt->report_status = 0;
	
	srv_sync_write_accnt(SRV_SYNC_PHONE, accnt, m_accntIndex);

	m_signalDone.postEmit();
}

VfxBool VappSyncPhoneAccntSettingPage::getItemText(
	VfxU32 index,					 // [IN] the index of item
	VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
	VfxWString &text,				 // [OUT] the text resource
	VcpListMenuTextColorEnum &color  // [OUT] the text color
	)
{
	if (fieldType != VCP_LIST_MENU_FIELD_TEXT)
	{
		return VFX_FALSE;
	}

	text.loadFromRes(VAPP_SYNC_GET_DB_RESID(index));
	color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

	return VFX_TRUE;
}

VcpListMenuItemStateEnum VappSyncPhoneAccntSettingPage::getItemState(VfxU32 index) const
{
	return m_stateLst[index];
}

void VappSyncPhoneAccntSettingPage::onListItemSelect(VcpListMenu *obj, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	m_stateLst[index] = newState;
}


