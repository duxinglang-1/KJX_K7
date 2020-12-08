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
 *  vapp_sync_remote_accnt_edit.cpp
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
#include "GlobalResDef.h"
#include "global_def.h"
#include "common_nvram_editor_data_item.h"
#include "SyncSrvGprot.h"

extern "C"
{
#include "NwUsabSrvGprot.h"
#include "SimCtrlSrvGprot.h"
}

#include "vcp_confirm_popup.h"
#include "vcp_form.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vcui_dtcnt_select_gprot.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_edit_txtitem.h"
#include "vapp_sync_accnt_edit_select_database.h"

#include "vapp_sync_remote_accnt_edit.h"
#include "vapp_sync_remote_accnt_edit_database.h"
#include "vapp_sync_remote_accnt_edit_name.h"
#include "vapp_sync_remote_accnt_edit_regular.h"
#include "vapp_sync_remote_accnt_edit_server.h"

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
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntEditPage", VappSyncRemoteAccntEditPage, VfxPage);
VappSyncRemoteAccntEditPage::VappSyncRemoteAccntEditPage(const VfxU8 &accntIndex) 
	: m_form(NULL),
  	  m_accntIndex(accntIndex),
  	  m_cuiId(0)
{
}

void VappSyncRemoteAccntEditPage::onInit(void)
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

	toolBar->m_signalButtonTap.connect(this, &VappSyncRemoteAccntEditPage::onToolbarClick);
	setBottomBar(toolBar);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	VcpFormItemLauncherCell *launchName;
	VFX_OBJ_CREATE(launchName, VcpFormItemLauncherCell, m_form);
	launchName->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchName->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_NAME));
	launchName->m_signalTap.connect(this, &VappSyncRemoteAccntEditPage::onFormCellClick);
	m_form->addItem(launchName, ID_FORM_CELL_EDIT_LAUNCH_ACCNT_NAME);

	VcpFormItemLauncherCell *launchServer;
	VFX_OBJ_CREATE(launchServer, VcpFormItemLauncherCell, m_form);
	launchServer->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchServer->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_SERVER_CONN));
	launchServer->m_signalTap.connect(this, &VappSyncRemoteAccntEditPage::onFormCellClick);
	m_form->addItem(launchServer, ID_FORM_CELL_EDIT_LAUNCH_SERVER_ADDR);

	VcpFormItemLauncherCell *launchDatabaseSel;
	VFX_OBJ_CREATE(launchDatabaseSel, VcpFormItemLauncherCell, m_form);
	launchDatabaseSel->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchDatabaseSel->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_APP_TO_SYNC));
	launchDatabaseSel->m_signalTap.connect(this, &VappSyncRemoteAccntEditPage::onFormCellClick);
	m_form->addItem(launchDatabaseSel, ID_FORM_CELL_EDIT_LAUNCH_DATABASE_SELECT);

	VcpFormItemLauncherCell *launchDatabaseAddr;
	VFX_OBJ_CREATE(launchDatabaseAddr, VcpFormItemLauncherCell, m_form);
	launchDatabaseAddr->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchDatabaseAddr->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_DB_ADDR));
	launchDatabaseAddr->m_signalTap.connect(this, &VappSyncRemoteAccntEditPage::onFormCellClick);
	m_form->addItem(launchDatabaseAddr, ID_FORM_CELL_EDIT_LAUNCH_DATABASE_ADDR);

	VcpFormItemLauncherCell *launchDataAccnt;
	VFX_OBJ_CREATE(launchDataAccnt, VcpFormItemLauncherCell, m_form);
	launchDataAccnt->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchDataAccnt->setMainText(VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING));
	launchDataAccnt->m_signalTap.connect(this, &VappSyncRemoteAccntEditPage::onFormCellClick);
	m_form->addItem(launchDataAccnt, ID_FORM_CELL_EDIT_LAUNCH_DATA_ACCNT);

	VcpFormItemLauncherCell *launchRegular;
	VFX_OBJ_CREATE(launchRegular, VcpFormItemLauncherCell, m_form);
	launchRegular->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchRegular->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_SYNC));
	launchRegular->m_signalTap.connect(this, &VappSyncRemoteAccntEditPage::onFormCellClick);
	m_form->addItem(launchRegular, ID_FORM_CELL_EDIT_LAUNCH_REGULAR_SYNC);

	mmi_frm_cb_reg_event(EVT_ID_SRV_SYNC_ACCNT_OP, VappSyncRemoteAccntEditPage::onEvt, this);
}

void VappSyncRemoteAccntEditPage::onDeinit(void)
{
	if (m_cuiId != GRP_ID_INVALID)
	{
		vcui_dtcnt_select_close(m_cuiId);
		m_cuiId = GRP_ID_INVALID;
	}
	
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SYNC_ACCNT_OP, VappSyncRemoteAccntEditPage::onEvt, this);

	VfxPage::onDeinit();
}

mmi_ret VappSyncRemoteAccntEditPage::onEvt(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SRV_SYNC_ACCNT_OP)
	{
		VappSyncRemoteAccntEditPage *page = (VappSyncRemoteAccntEditPage *)evt->user_data;
		
		return page->onSrvEvt(evt);
	}
	
	return MMI_RET_OK;
}

mmi_ret VappSyncRemoteAccntEditPage::onSrvEvt(mmi_event_struct *evt)
{
	srv_sync_accnt_op_evt_struct *opEvt = (srv_sync_accnt_op_evt_struct *)evt;

	if (m_cuiId != GRP_ID_INVALID &&
		opEvt->operation == SRV_SYNC_ACCNT_OP_MODIFY &&
		opEvt->sync == SRV_SYNC_REMOTE &&
		opEvt->index == m_accntIndex)
	{
		nvram_ef_syncml_account_struct *accnt;

		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
		VFX_ASSERT(accnt != NULL);
		
		for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
		{
			vcui_dtcnt_select_set_account_id(m_cuiId, (cui_dtcnt_sim_enum)i, accnt->net_id[i]);
		}
	}
	
	return MMI_RET_OK;
}

void VappSyncRemoteAccntEditPage::onEnter(VfxBool isBackward)
{
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	VcpFormItemLauncherCell *launchName;
	launchName = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_ACCNT_NAME);
	VfxWString strName = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);
	launchName->setHintText(strName);	

	VcpFormItemLauncherCell *launchServer;
	launchServer = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_SERVER_ADDR);
	VfxWString strServer;
	strServer.format("%s", accnt->server_address);
	launchServer->setHintText(strServer);

	VcpFormItemLauncherCell *launchDatabaseSel;
	launchDatabaseSel =  (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_DATABASE_SELECT);
	launchDatabaseSel->setHintText(VAPP_SYNC_GEN_DB_STR(accnt->app_to_sync));

	VcpFormItemLauncherCell *launchDatabaseAddr;
	launchDatabaseAddr =  (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_DATABASE_ADDR);
	launchDatabaseAddr->setHintText(genDatabaseAddrString());

	VcpFormItemLauncherCell *launchRegular;
	launchRegular = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_REGULAR_SYNC);
	launchRegular->setHintText(VAPP_SYNC_GET_REGULAR_STR(accnt->regular_sync));
	
	checkItemState();

	VfxPage::onEnter(isBackward);
}


void VappSyncRemoteAccntEditPage::checkItemState(void)
{
	VcpFormItemBase *dtcntItem = m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_DATA_ACCNT);
	if (dtcntItem != NULL)
	{	
		nvram_ef_syncml_account_struct *accnt;
		
		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
		VFX_ASSERT(accnt != NULL);

		if (!srv_sim_ctrl_any_sim_is_available())
		{
			dtcntItem->setIsDisabled(VFX_TRUE);
		}
		else
		{
			dtcntItem->setIsDisabled(VFX_FALSE);
		}
	}
}

void VappSyncRemoteAccntEditPage::onToolbarClick(VfxObject* obj, VfxId id)
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
			
			VcpFormItemLauncherCell *nameCell = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_CELL_EDIT_LAUNCH_ACCNT_NAME);
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
			confirm->m_signalButtonClicked.connect(this, &VappSyncRemoteAccntEditPage::onCmdCallback);
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

void VappSyncRemoteAccntEditPage::onCmdCallback(VfxObject *obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		m_signalAction.postEmit(this, VAPP_SYNC_ACCNT_LIST_ACTION_DELETE, m_accntIndex);
		getMainScr()->popPage();
	}
}

void VappSyncRemoteAccntEditPage::onFormCellSwitchReq(VcpFormItemSwitchCell *obj, VfxId id, VfxBool newState)
{
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	if (id == ID_FORM_CELL_EDIT_SWITCH_WIFI_ONLY)
	{
	accnt->wifi_only = newState ? 1 : 0;
	}
	else if (id == ID_FORM_CELL_EDIT_SWITCH_REPORT)
	{
		accnt->sync_report_status = newState ? 1 : 0;
	}
	
	srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, m_accntIndex);

	obj->setSwitchStatus(newState);
	
	checkItemState();
}

void VappSyncRemoteAccntEditPage::onFormCellClick(VcpFormItemCell *obj, VfxId id)
{
	VfxPage *page = NULL;
	VfxId pageId = VFX_ID_NULL;
	
	switch (id)
	{
		case ID_FORM_CELL_EDIT_LAUNCH_ACCNT_NAME:
		{
			VappSyncRemoteAccntEditNamePage *namePage;
			VFX_OBJ_CREATE_EX(namePage, VappSyncRemoteAccntEditNamePage, getMainScr(), (m_accntIndex));
			namePage->m_signalEditDone.connect(this, &VappSyncRemoteAccntEditPage::onNameEditDone);
			page = namePage;
			pageId = ID_FORM_CELL_EDIT_LAUNCH_ACCNT_NAME;
			break;
		}
		
		case ID_FORM_CELL_EDIT_LAUNCH_SERVER_ADDR:
		{
			VappSyncRemoteAccntEditServerPage *srvPage;
			VFX_OBJ_CREATE_EX(srvPage, VappSyncRemoteAccntEditServerPage, getMainScr(), (m_accntIndex));
			srvPage->m_signalEditDone.connect(this, &VappSyncRemoteAccntEditPage::onServerEditDone);
			page = srvPage;
			pageId = ID_FORM_CELL_EDIT_LAUNCH_SERVER_ADDR;
			break;
		}	
			
		case ID_FORM_CELL_EDIT_LAUNCH_DATABASE_SELECT:
		{
			nvram_ef_syncml_account_struct *accnt;
			accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
			
			VappSyncAccntSelectDatabasePage *selPage;
			VFX_OBJ_CREATE_EX(selPage, VappSyncAccntSelectDatabasePage, getMainScr(), (accnt->app_to_sync));
			selPage->m_signalSelectDone.connect(this, &VappSyncRemoteAccntEditPage::onSelectDatabaseDone);
			page = selPage;
			pageId = ID_FORM_CELL_EDIT_LAUNCH_DATABASE_SELECT;
			break;
		}
		
		case ID_FORM_CELL_EDIT_LAUNCH_DATABASE_ADDR:
		{
			nvram_ef_syncml_account_struct *accnt;
			accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);

			VappSyncRemoteAccntEditDBPage *dbPage;
			VFX_OBJ_CREATE_EX(dbPage, VappSyncRemoteAccntEditDBPage, getMainScr(), (m_accntIndex, accnt->app_to_sync));
			dbPage->m_signalEditDone.connect(this, &VappSyncRemoteAccntEditPage::ontDatabaseEditDone);
			page = dbPage;
			pageId = ID_FORM_CELL_EDIT_LAUNCH_DATABASE_ADDR;
			break;
		}
		
		case ID_FORM_CELL_EDIT_LAUNCH_DATA_ACCNT:
		{
			nvram_ef_syncml_account_struct *accnt;
			accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
			VFX_ASSERT(accnt != NULL);
			
			m_cuiId = vcui_dtcnt_select_create(getMainScr()->getGroupId());
			vfxSetCuiCallerScr(m_cuiId, getMainScr());

			cui_dtcnt_select_run_struct dtcnt_param;

            dtcnt_param.bearers = DATA_ACCOUNT_BEARER_GPRS;
            dtcnt_param.app_id = srv_sync_remote_app_id();
            dtcnt_param.icon_id = IMG_ID_VAPP_SYNC;
            dtcnt_param.str_id = STR_ID_VAPP_SYNC;
            dtcnt_param.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
            dtcnt_param.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
            dtcnt_param.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
			memcpy(dtcnt_param.sim_account_id, accnt->net_id, (sizeof(U32) * MAX_SIM_NUM));

			vcui_dtcnt_select_set_param(m_cuiId, &dtcnt_param);
			vcui_dtcnt_select_run(m_cuiId);
			
			break;
		}
		
		case ID_FORM_CELL_EDIT_LAUNCH_REGULAR_SYNC:
		{
			nvram_ef_syncml_account_struct *accnt;
			accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
			VFX_ASSERT(accnt != NULL);
			
			VappSyncRemoteAccntEditRegularPage *regularPage;
			VFX_OBJ_CREATE_EX(regularPage, VappSyncRemoteAccntEditRegularPage, getMainScr(), (accnt->regular_sync, m_accntIndex));
			regularPage->m_signalSelected.connect(this, &VappSyncRemoteAccntEditPage::onRegularSelectDone);
			page = regularPage;
			pageId = ID_FORM_CELL_EDIT_LAUNCH_REGULAR_SYNC;

			break;
		}
		default:
			break;
	}

	if (page != NULL)
	{
		getMainScr()->pushPage(pageId, page);
	}	
}


void VappSyncRemoteAccntEditPage::closeRelativePage(void)
{
	for (VfxU32 i = ID_FORM_CELL_EDIT_LAUNCH_ACCNT_NAME; i < ID_FORM_CELL_EDIT_TOTAL; i++)
	{
		getMainScr()->closePage(i);
	}

	if (m_cuiId != GRP_ID_INVALID)
	{
		vcui_dtcnt_select_close(m_cuiId);
		m_cuiId = GRP_ID_INVALID;
	}
}

void VappSyncRemoteAccntEditPage::onNameEditDone(VfxObject *obj, VfxS32 index)
{
	getMainScr()->popPage();
}


void VappSyncRemoteAccntEditPage::onServerEditDone(VfxObject *obj, VfxS32 index)
{
	getMainScr()->popPage();
}

void VappSyncRemoteAccntEditPage::onSelectDatabaseDone(VfxObject *obj, VfxU32 mask)
{
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);
	
	if (accnt->app_to_sync != (VfxU8)mask)
	{
	VappSyncRemoteAccntEditDBPage *dbPage;
	VFX_OBJ_CREATE_EX(dbPage, VappSyncRemoteAccntEditDBPage, this, (m_accntIndex, mask));
	dbPage->m_signalEditDone.connect(this, &VappSyncRemoteAccntEditPage::ontDatabaseEditDone);
		
		getMainScr()->pushPage(ID_FORM_CELL_EDIT_LAUNCH_DATABASE_ADDR, dbPage);
}
	else
	{	
		getMainScr()->popPage();
	}

}

void VappSyncRemoteAccntEditPage::ontDatabaseEditDone(VfxObject *obj, VfxS32 index, VfxU32 dbMask)
{
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);
	accnt->app_to_sync = (VfxU8)dbMask;
	
	srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, m_accntIndex);

	getMainScr()->closePage(ID_FORM_CELL_EDIT_LAUNCH_DATABASE_SELECT);
	getMainScr()->popPage();
}

void VappSyncRemoteAccntEditPage::onRegularSelectDone(VfxObject *obj, VfxU8 regular)
{
	nvram_ef_syncml_account_struct *accnt;

	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	accnt->regular_sync = regular;
	srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, m_accntIndex);

	getMainScr()->popPage();
}

mmi_ret VappSyncRemoteAccntEditPage::onProc(mmi_event_struct *evt)
{
	VFX_ASSERT(evt != NULL);
	
	switch(evt->evt_id)
	{
		case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
		{
			nvram_ef_syncml_account_struct *accnt;
			accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
			VFX_ASSERT(accnt != NULL);
			
			cui_dtcnt_select_event_any_sim_selected_struct *dtcnt_evt;
			dtcnt_evt = (cui_dtcnt_select_event_any_sim_selected_struct *)evt;

			VFX_ASSERT(dtcnt_evt->selectSim < MAX_SIM_NUM);
			accnt->net_id[dtcnt_evt->selectSim] = dtcnt_evt->accountId;

			srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, m_accntIndex);
		
			break;
		}
		case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
		case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
		case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
		case CUI_DTCNT_SELECT_EVENT_CLOSE:
		{
			vcui_dtcnt_select_close(m_cuiId);
			m_cuiId = GRP_ID_INVALID;
			break;
		}
		
		default:
			break;
	};

	return VfxPage::onProc(evt);
}


VfxWString VappSyncRemoteAccntEditPage::genDatabaseAddrString(void)
{
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);

	VfxWString outStr, databaseStr;
	VfxBool bFirst = VFX_TRUE;
	VfxU8 i = 0;
	
	do 
	{
		if (vfx_sys_strlen((const VfxChar *)accnt->database_address[VAPP_SYNC_GET_ID(i)]) > 0)
		{
			if (!bFirst)
			{
				outStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_COMMA);
				outStr += VFX_WSTR_RES(STR_ID_VAPP_SYNC_SPACE);
			}
			
			outStr += VAPP_SYNC_GET_DB_NAME(i);

			bFirst = VFX_FALSE;
		}
		i++;
	} while (i < VAPP_SYNC_TOTAL_DATABASE);

	return outStr;
}


