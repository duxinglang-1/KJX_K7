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
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_sync_def.h"

#include "SyncSrvGprot.h"
#include "BtcmSrvGprot.h"

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"
#include "vcp_confirm_popup.h"

#include "vapp_sync_accnt_edit_select_database.h"
#include "vapp_sync_accnt_list_menu.h"
#include "vapp_sync_phone_accnt_edit_name.h"
#include "vapp_sync_phone_accnt_edit.h"

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
 * Class VappSyncRemoteAccntEditServerPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncPhoneAccntEditPage", VappSyncPhoneAccntEditPage, VfxPage);
VappSyncPhoneAccntEditPage::VappSyncPhoneAccntEditPage(const VfxS32 &accntIndex) 
	: m_form(NULL),
  	  m_accntIndex(accntIndex)
{
}

void VappSyncPhoneAccntEditPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_INFO));
	setTopBar(titleBar);

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SYNC_EDIT_SYNC, VFX_WSTR_RES(STR_ID_VAPP_SYNC_NOW), IMG_ID_VAPP_SYNC_NOW);
	toolBar->addItem(ID_TOOLBAR_SYNC_EDIT_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	toolBar->addItem(ID_TOOLBAR_SYNC_EDIT_VLOG, VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG), IMG_ID_VAPP_SYNC_VLOG);

	toolBar->m_signalButtonTap.connect(this, &VappSyncPhoneAccntEditPage::onToolbarClick);
	setBottomBar(toolBar);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE);

	VcpFormItemLauncherCell *launchName;
	VFX_OBJ_CREATE(launchName, VcpFormItemLauncherCell, m_form);
	launchName->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchName->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_PHONE_NAME));
	launchName->m_signalTap.connect(this, &VappSyncPhoneAccntEditPage::onFormCellClick);
	m_form->addItem(launchName, ID_FORM_CELL_EDIT_LAUNCH_NAME);


	VcpFormItemLauncherCell *launchDatabaseSel;
	VFX_OBJ_CREATE(launchDatabaseSel, VcpFormItemLauncherCell, m_form);
	launchDatabaseSel->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_APP_TO_SYNC));
	launchDatabaseSel->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchDatabaseSel->m_signalTap.connect(this, &VappSyncPhoneAccntEditPage::onFormCellClick);
	m_form->addItem(launchDatabaseSel, ID_FORM_CELL_EDIT_LAUNCH_SEL_DATABASE);
}

void VappSyncPhoneAccntEditPage::onEnter(VfxBool isBackward)
{
	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];
	ucs2_buff[0] = 0;
	ucs2_buff[1] = 0;
	srv_bt_cm_get_dev_ucs2_name((srv_bt_cm_bt_addr *)&accnt->dev_bt_addr, SRV_BT_CM_BD_UCS2_NAME_LEN, (WCHAR *)ucs2_buff);

	VcpFormItemLauncherCell *launchName;
	launchName = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_NAME);
	launchName->setHintText(VFX_WSTR_MEM(ucs2_buff));

	VcpFormItemLauncherCell *selDB;
	selDB = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_SEL_DATABASE);
	selDB->setHintText(VAPP_SYNC_GEN_DB_STR(accnt->app_to_sync));
	
	VfxPage::onEnter(isBackward);
}

void VappSyncPhoneAccntEditPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case ID_TOOLBAR_SYNC_EDIT_SYNC:
		{
			m_signalAction.postEmit(this, VAPP_SYNC_ACCNT_LIST_ACTION_SYNC, m_accntIndex);
			break;
		}
		
		case ID_TOOLBAR_SYNC_EDIT_DELETE:
		{
	    	VcpConfirmPopup *confirm;
			
			VfxWString strAsk = VFX_WSTR_RES(STR_ID_VAPP_SYNC_DEL_ASK);
			strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_QUOTES_LEFT);
			
			VcpFormItemLauncherCell *nameCell = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_NAME);
			strAsk += nameCell->getHintText();
			
			strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_QUOTES_RIGHT);
			strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_QUESTION);
			
			VFX_OBJ_CREATE(confirm, VcpConfirmPopup, findScreen());
			confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
			confirm->setText(strAsk);
			confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
			confirm->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE), 
									 VFX_WSTR_RES(STR_GLOBAL_CANCEL),
									 VCP_POPUP_BUTTON_TYPE_WARNING,
									 VCP_POPUP_BUTTON_TYPE_CANCEL);
			confirm->m_signalButtonClicked.connect(this, &VappSyncPhoneAccntEditPage::onCmdCallback);
			confirm->setAutoDestory(VFX_TRUE);
			
			confirm->show(VFX_TRUE);
			break;
		}
		
		case ID_TOOLBAR_SYNC_EDIT_VLOG:
		{
			m_signalAction.postEmit(this, VAPP_SYNC_ACCNT_LIST_ACTION_VLOG, m_accntIndex);
			break;
		}
		
		default:
			break;
	}

}

void VappSyncPhoneAccntEditPage::onCmdCallback(VfxObject *obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		m_signalAction.postEmit(this, VAPP_SYNC_ACCNT_LIST_ACTION_DELETE, m_accntIndex);
		getMainScr()->popPage();
	}
}

void VappSyncPhoneAccntEditPage::onFormCellSwitchReq(VcpFormItemSwitchCell *obj, VfxId id, VfxBool newState)
{
	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	accnt->report_status = newState ? 1 : 0;
	
	srv_sync_write_accnt(SRV_SYNC_PHONE, accnt, m_accntIndex);

	obj->setSwitchStatus(newState);
}

void VappSyncPhoneAccntEditPage::onFormCellClick(VcpFormItemCell *obj, VfxId id)
{
	VfxPage *page = NULL;
	
	switch (id)
	{
		case ID_FORM_CELL_EDIT_LAUNCH_NAME:
		{
			VappSyncPhoneAccntEditNamePage *namePage;
			VFX_OBJ_CREATE_EX(namePage, VappSyncPhoneAccntEditNamePage, this, (m_accntIndex));
			namePage->m_signalEditDone.connect(this, &VappSyncPhoneAccntEditPage::onNameEditDone);
			page = namePage;
			break;
		}
		
		case ID_FORM_CELL_EDIT_LAUNCH_SEL_DATABASE:
		{
			nvram_ef_syncml_device_accnt_struct *accnt;
			accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_accntIndex);
			
			VappSyncAccntSelectDatabasePage *selPage;
			VFX_OBJ_CREATE_EX(selPage, VappSyncAccntSelectDatabasePage, this, (accnt->app_to_sync));
			selPage->m_signalSelectDone.connect(this, &VappSyncPhoneAccntEditPage::onSelectDatabaseDone);
			page = selPage;
			break;
		}
		default:
			break;
	}

	if (page != NULL)
	{
		getMainScr()->pushPage(VFX_ID_NULL, page);
	}	
}

void VappSyncPhoneAccntEditPage::onNameEditDone(VfxObject *obj, VfxS32 index)
{
	getMainScr()->popPage();
}

void VappSyncPhoneAccntEditPage::onSelectDatabaseDone(VfxObject *obj, VfxU32 index)
{
	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);
	accnt->app_to_sync = index;

	srv_sync_write_accnt(SRV_SYNC_PHONE, accnt, m_accntIndex);

	getMainScr()->popPage();
}


