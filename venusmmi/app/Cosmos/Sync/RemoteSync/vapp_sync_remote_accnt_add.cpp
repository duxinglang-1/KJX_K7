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
 *  vapp_sync_remote_accnt_add.cpp
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
extern "C"
{
	#include "kal_general_types.h"
	#include "cbm_api.h"
	#include "app_url.h"
}
#include "global_def.h"
#include "GlobalResDef.h"
#include "common_nvram_editor_data_item.h"
#include "SyncSrvGprot.h"
#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_main_scr.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_function_bar.h"

#include "vcui_dtcnt_select_gprot.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_list.h"
#include "vapp_sync_accnt_edit_txtitem.h"

#include "vapp_sync_remote_accnt_list.h"

#include "vapp_sync_remote_accnt_edit.h"
#include "vapp_sync_remote_accnt_add.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define ID_TOOLBAR_SYNC_ACCNT_NEXT		'NEXT'
#define ID_TOOLBAR_SYNC_ACCNT_CANCEL	'CANL'

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncRemoteAccntAddSrvPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntAddSrvPage", 
								VappSyncRemoteAccntAddSrvPage, 
								VappSyncRemoteAccntEditServerPage); 

VappSyncRemoteAccntAddSrvPage::VappSyncRemoteAccntAddSrvPage(const VfxS32 &index) 
	: VappSyncRemoteAccntEditServerPage(index)
{
	
}

void VappSyncRemoteAccntAddSrvPage::onInit(void)
{
	VappSyncRemoteAccntEditServerPage::onInit();

	VcpTitleBar *titleBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTitleBar);
	if (titleBar != NULL)
	{
		VfxWString strStep;
		strStep.loadFromRes(STR_ID_VAPP_SYNC_BASIC_INFO);
		strStep += VFX_WSTR_RES(STR_ID_VAPP_SYNC_STEP_13);
		
		titleBar->setTitle(strStep);
	}

	VcpToolBar *toolBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM), VcpToolBar);
	if (toolBar != NULL)
	{
		toolBar->changeItem(ID_TOOLBAR_SYNC_ACCNT_SERVER_SAVE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_NEXT), IMG_ID_VAPP_SYNC_NEXT);
	}

	VFX_ALLOC_MEM(m_accntData, sizeof(nvram_ef_syncml_account_struct), this);
	memset(m_accntData, 0, sizeof(nvram_ef_syncml_account_struct));

	//nvram_ef_syncml_account_struct *accnt;
	//accnt = (nvram_ef_syncml_account_struct *)m_accntData;
	
	// deactive the previoius active.
	VappSyncTextInputItem *txtAddr = (VappSyncTextInputItem *)m_form->getItem(ID_FORM_CELL_SERVER_ADDR);
	txtAddr->getTextBox()->setAutoActivated(VFX_FALSE);
	
	VappSyncTextInputItem *txtAccntName;
	VFX_OBJ_CREATE(txtAccntName, VappSyncTextInputItem, m_form);
	txtAccntName->setLabelPosition(VCPFORM_TOP_LEFT);
	txtAccntName->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_NAME));
	txtAccntName->m_signalFocusChange.connect(this, &VappSyncRemoteAccntAddSrvPage::onFocusChange);

	VcpTextEditor *txtEditor = txtAccntName->getTextBox();
	txtAccntName->setText(VFX_WSTR_NULL);
	txtEditor->setMaxLength(MAX_SYNCML_PROFILE_NAME - 1);
	txtEditor->setFunctionBar(m_funcBar, VFX_FALSE);
	txtEditor->setAutoActivated(VFX_TRUE);
	
	m_form->insertItem(txtAccntName, ID_FORM_CELL_SERVER_ADDR, ID_FORM_CELL_SERVER_CUSTOM);
	
	m_activeId = ID_FORM_CELL_SERVER_CUSTOM;
	m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_TRUE);
	m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_FALSE);
	m_funcBar->changeItem(ID_FUNCBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FUNC_OK));

	// update the other text
	VappSyncTextInputItem * txtInput = (VappSyncTextInputItem *)m_form->getItem(ID_FORM_CELL_SERVER_ADDR);
	txtInput->setText(VFX_WSTR_NULL);
	txtInput->getTextBox()->setMaxLength(MAX_SYNCML_SERVER_ADDR_LEN - 1);

	VappSyncTextInputItem * txtUsrName = (VappSyncTextInputItem *)m_form->getItem(ID_FORM_CELL_SERVER_USERNAME);
	txtUsrName->setText(VFX_WSTR_NULL);
	txtUsrName->getTextBox()->setMaxLength(MAX_SYNCML_USERNAME - 1);

	VappSyncTextInputItem * txtPassWord = (VappSyncTextInputItem *)m_form->getItem(ID_FORM_CELL_SERVER_PASSWORD);
	txtPassWord->setText(VFX_WSTR_NULL);
	txtPassWord->getTextBox()->setMaxLength(MAX_SYNCML_PASSWORD - 1);
}

void VappSyncRemoteAccntAddSrvPage::onDeinit(void)
{
	VFX_FREE_MEM(m_accntData);
	
	VappSyncRemoteAccntEditServerPage::onDeinit();
}

void VappSyncRemoteAccntAddSrvPage::onNext(void)
{
	VfxBool isValidName;

	nvram_ef_syncml_account_struct *accnt  = (nvram_ef_syncml_account_struct *)m_accntData;
	
	VcpFormItemTextInput *txtInput;

	txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_FORM_CELL_SERVER_CUSTOM);

	if (txtInput->getText().isEmpty())
	{
		isValidName = VFX_FALSE;
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_DB_INVALID_ACCNT_NAME));
		m_form->scrollItemToView(ID_FORM_CELL_SERVER_CUSTOM, VCPFORM_SCROLL_BOTTOM);
	}
	else
	{
		isValidName = VFX_TRUE;
		txtInput->setWarningText(VFX_WSTR_NULL);

		// check validation
		VfxPage *page = getMainScr()->getPage(VAPP_SYNC_PAGE_ID(LIST));
		
		VappSyncAccntListPage *listPage;
		listPage = VFX_OBJ_DYNAMIC_CAST(page, VappSyncAccntListPage);
		
		if (listPage != NULL)
		{
			VfxPage *tabPage = listPage->getTabPage(listPage->getCurrTab());
			VappSyncRemoteAccntListPage *rmtListPage;
			rmtListPage = VFX_OBJ_DYNAMIC_CAST(tabPage, VappSyncRemoteAccntListPage);
			if (rmtListPage != NULL &&
				rmtListPage->checkExistAccntName(0xFF, txtInput->getText().getBuf()))
			{
				txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_NAME_EXIST));
				isValidName = VFX_FALSE;
			}
		}

		if (isValidName)
		{
			mmi_ucs2ncpy((CHAR *)accnt->account_name, 
						 (const CHAR *)txtInput->getText().getBuf(),
						 txtInput->getText().getLength());

			accnt->account_name[txtInput->getText().getLength() * 2] = 0;
			accnt->account_name[txtInput->getText().getLength() * 2 + 1] = 0;
		}
	}

	VfxBool isValidAddr;
	txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_FORM_CELL_SERVER_ADDR);
	if (txtInput->getText().isEmpty())
	{
		isValidAddr = VFX_FALSE;
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_DB_INVALID_SRV_ADDR));

		// Only accnt name is valid
		if (isValidName)
		{
			m_form->scrollItemToView(ID_FORM_CELL_SERVER_ADDR, VCPFORM_SCROLL_BOTTOM);
		}
	}
	else
	{
		isValidAddr = VFX_TRUE;
		txtInput->setWarningText(VFX_WSTR_NULL);
		mmi_ucs2_n_to_asc((CHAR *)accnt->server_address, 
						  (CHAR *)txtInput->getText().getBuf(), 
						  (txtInput->getText().getLength() * 2));

		accnt->server_address[txtInput->getText().getLength()] = 0;

		if ((applib_url_is_valid((const char *)accnt->server_address) != 0))
		{
			isValidAddr = VFX_FALSE;
			txtInput->setWarningText(VFX_WSTR_RES(STR_GLOBAL_INVALID_URL));
			m_form->scrollItemToView(ID_FORM_CELL_SERVER_ADDR, VCPFORM_SCROLL_BOTTOM);
		}
	}
	
	// next page
	if (isValidName && isValidAddr)
	{
		txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_FORM_CELL_SERVER_USERNAME);
		mmi_ucs2_n_to_asc((CHAR *)accnt->server_username, 
						  (CHAR *)txtInput->getText().getBuf(), 
						  (txtInput->getText().getLength() * 2));
		accnt->server_username[txtInput->getText().getLength()] = 0;
		
		txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_FORM_CELL_SERVER_PASSWORD);
		mmi_ucs2_n_to_asc((CHAR *)accnt->server_password, 
						  (CHAR *)txtInput->getText().getBuf(), 
						  (txtInput->getText().getLength() * 2));
		accnt->server_password[txtInput->getText().getLength()] = 0;

		// set default status
		accnt->sync_report_status = 1;
		accnt->wifi_only = 0;

		for (VfxU32 i = 0; i < MAX_SIM_NUM; i++)
		{
			accnt->net_id[i] = cbm_encode_data_account_id(
												VAPP_DTCNT_AUTOMATIC_ID,
												(cbm_sim_id_enum)(CBM_SIM_ID_SIM1 + i),
												srv_sync_remote_app_id(),
												KAL_FALSE);
		}

		// next page
		VappSyncRemoteAccntAddSelDBPage *selPage;
		VFX_OBJ_CREATE_EX(selPage, VappSyncRemoteAccntAddSelDBPage, getMainScr(), (m_accntData));
		
		getMainScr()->pushPage(VAPP_SYNC_PAGE_ID(ADD_SELDB), selPage);
	}
}

void VappSyncRemoteAccntAddSrvPage::onCancel(void)
{
	getMainScr()->popPage();
}

void VappSyncRemoteAccntAddSrvPage::onFocusChange(VfxObject *obj, VfxId id, VfxBool isActive)
{
	//VcpFormItemTextInput *txtInput;
	
	m_form->getItem(id);

	if (isActive)
	{
		m_activeId = id;
		
		if (id == ID_FORM_CELL_SERVER_CUSTOM)
		{
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_TRUE);
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_FALSE);
		}
		else if (id == ID_FORM_CELL_SERVER_PASSWORD)
		{
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_FALSE);
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_TRUE);
		}
		else
		{
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_FALSE);
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_FALSE);
		}
	}
}

void VappSyncRemoteAccntAddSrvPage::onFuncBarClick(	VfxObject *sender, VfxId id)
{
	VfxId nextId = ID_FORM_CELL_SERVER_TOTAL;
	
	switch(id)
	{
		case ID_FUNCBAR_SYNC_ACCNT_SAVE:
			onSave();
			break;
			
		case ID_FUNCBAR_SYNC_ACCNT_PREV:
			nextId = m_activeId - 1;
			break;
			
		case ID_FUNCBAR_SYNC_ACCNT_NEXT:
			nextId = m_activeId + 1;
			break;
			
		default:
			break;
	}

	if (nextId < ID_FORM_CELL_SERVER_TOTAL &&
		nextId >= ID_FORM_CELL_SERVER_CUSTOM)
	{
		VcpFormItemTextInput *textInput;
		textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
		textInput->getTextBox()->activate();
	}
}

/***************************************************************************** 
 * Class VappSyncRemoteAccntAddSelDatabasePage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntAddSelDBPage", 
								VappSyncRemoteAccntAddSelDBPage, 
								VappSyncAccntSelectDatabasePage);

VappSyncRemoteAccntAddSelDBPage::VappSyncRemoteAccntAddSelDBPage(void *accntData)
	: VappSyncAccntSelectDatabasePage(0), m_accntData(accntData)
	  
{

}

void VappSyncRemoteAccntAddSelDBPage::onInit(void)
{
	VappSyncAccntSelectDatabasePage::onInit();
	
	VcpTitleBar *titleBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTitleBar);
	if (titleBar != NULL)
	{
		VfxWString strStep;
		strStep.loadFromRes(STR_ID_VAPP_SYNC_APP_TO_SYNC);
		strStep += VFX_WSTR_RES(STR_ID_VAPP_SYNC_STEP_23);
		
		titleBar->setTitle(strStep);
	}
	
	VcpToolBar *toolBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM), VcpToolBar);
	if (toolBar != NULL)
	{
		toolBar->changeItem(ID_TOOLBAR_SYNC_ACCNT_SELDB_SAVE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_NEXT), IMG_ID_VAPP_SYNC_NEXT);
	}

	m_signalSelectDone.connect(this, &VappSyncRemoteAccntAddSelDBPage::onSelectDone);
}

void VappSyncRemoteAccntAddSelDBPage::onSelectDone(VfxObject *obj, VfxU32 mask)
{
	nvram_ef_syncml_account_struct *accnt = (nvram_ef_syncml_account_struct *)m_accntData;
	accnt->app_to_sync = mask;

	// next page
	VappSyncRemoteAccntAddDBPage *addrPage;
	VFX_OBJ_CREATE_EX(addrPage, VappSyncRemoteAccntAddDBPage, getMainScr(), (mask, m_accntData));
	getMainScr()->pushPage(VAPP_SYNC_PAGE_ID(ADD_DBADDR), addrPage);
}


void VappSyncRemoteAccntAddSelDBPage::onCancel(void)
{
	getMainScr()->closePage(VAPP_SYNC_PAGE_ID(ADD_SERVER));
	getMainScr()->popPage();
}


/***************************************************************************** 
 * Class VappSyncRemoteAccntAddDBPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntAddDBPage", 
								VappSyncRemoteAccntAddDBPage, 
								VappSyncRemoteAccntEditDBPage);
VappSyncRemoteAccntAddDBPage::VappSyncRemoteAccntAddDBPage(const VfxU32 &dbMask, void *accntData)
	: VappSyncRemoteAccntEditDBPage(0, dbMask), m_accntData(accntData)  
{
	
}
void VappSyncRemoteAccntAddDBPage::onInit(void)
{
	VappSyncRemoteAccntEditDBPage::onInit();
	
	VcpTitleBar *titleBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTitleBar);
	if (titleBar != NULL)
	{
		VfxWString strStep;
		strStep.loadFromRes(STR_ID_VAPP_SYNC_DB_ADDR);
		strStep += VFX_WSTR_RES(STR_ID_VAPP_SYNC_STEP_33);
		
		titleBar->setTitle(strStep);
	}
	
	m_funcBar->changeItem(ID_FUNCBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FINISH));

	VcpToolBar *toolBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM), VcpToolBar);
	if (toolBar != NULL)
	{
		toolBar->changeItem(ID_TOOLBAR_SYNC_ACCNT_DB_SAVE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FINISH), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
	}
}


VfxBool VappSyncRemoteAccntAddDBPage::onSave(void)
{
	m_accntIndex = srv_sync_accnt_new_index(SRV_SYNC_REMOTE);
	
	if (m_accntIndex < 0)
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_SYNC_REACH_MAXIMUM));

		return VFX_FALSE;
	}
	
	if (VappSyncRemoteAccntEditDBPage::onSave())
    {
		srv_sync_write_accnt(SRV_SYNC_REMOTE, m_accntData, m_accntIndex);
		
		onFinish();
    }

	return VFX_TRUE;
}

VfxWString VappSyncRemoteAccntAddDBPage::getAddress(const VfxS32 accntIndex, const VfxU32 &dbID)
{
	return VFX_WSTR_NULL;
}

void VappSyncRemoteAccntAddDBPage::saveAddr(const VfxS32 accntIndex,
						 						const VfxU32 &dbID, 
						 						const VfxWChar *buffer, 
						 						const VfxU32 &length)
{
	nvram_ef_syncml_account_struct *accnt =  (nvram_ef_syncml_account_struct *)m_accntData;

	mmi_wcs_n_to_asc((CHAR *)accnt->database_address[dbID], (WCHAR *)buffer, (length << 1));
	
	accnt->timestamp = srv_sync_get_current_time();
}


void VappSyncRemoteAccntAddDBPage::onFinish(void)
{
	onCancel();
}


void VappSyncRemoteAccntAddDBPage::onCancel(void)
{
	getMainScr()->closePage(VAPP_SYNC_PAGE_ID(ADD_SELDB));
	getMainScr()->closePage(VAPP_SYNC_PAGE_ID(ADD_SERVER));
	getMainScr()->popPage();
}


