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
	#include "app_url.h"
}
#include "GlobalResDef.h"
#include "common_nvram_editor_data_item.h"
#include "ImeGprotEnums.h"

#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_sync_def.h"

#include "SyncSrvGprot.h"

#include "vfx_string.h"

#include "vcp_button.h"	// include for vcp_function_bar.h
#include "vcp_function_bar.h"
#include "vcp_form.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vapp_sync_accnt_edit_txtitem.h"
#include "vapp_sync_accnt_list.h"

#include "vapp_sync_remote_accnt_edit.h"
#include "vapp_sync_remote_accnt_edit_server.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }

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
 * Class VappSyncRemoteAccntEditServerPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntEditServerPage", 
								VappSyncRemoteAccntEditServerPage, 
								VfxPage);
VappSyncRemoteAccntEditServerPage::VappSyncRemoteAccntEditServerPage(const VfxS32 &accntIndex )
		: m_funcBar(NULL),
		  m_form(NULL),
		  m_accntIndex(accntIndex)
{
}

void VappSyncRemoteAccntEditServerPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_SERVER_CONN));
	setTopBar(titleBar);

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_SERVER_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	toolBar->m_signalButtonTap.connect(this, &VappSyncRemoteAccntEditServerPage::onToolbarClick);
	setBottomBar(toolBar);

	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	VFX_ASSERT(accnt != NULL);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FUNC_PREV));
    m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FUNC_NEXT));
    m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_funcBar->setItemSpecial(ID_FUNCBAR_SYNC_ACCNT_SAVE);
    m_funcBar->m_signalButtonTap.connect(this, &VappSyncRemoteAccntEditServerPage::onFuncBarClick);
	
	VfxWString strTemp;
	// server address.
	VappSyncTextInputItem *txtAddr;
	VFX_OBJ_CREATE(txtAddr, VappSyncTextInputItem, m_form);
	txtAddr->setLabelPosition(VCPFORM_TOP_LEFT);
	strTemp.format("%s", accnt->server_address);
	txtAddr->setText(strTemp);
	txtAddr->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
	txtAddr->getTextBox()->setMaxLength(MAX_SYNCML_SERVER_ADDR_LEN - 1);
	txtAddr->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_SERVER_ADDR));
	txtAddr->getTextBox()->setIME(IMM_INPUT_TYPE_URL);
	txtAddr->getTextBox()->setAutoActivated(VFX_TRUE);
	txtAddr->m_signalFocusChange.connect(this, &VappSyncRemoteAccntEditServerPage::onFocusChange);
	m_form->addItem(txtAddr, ID_FORM_CELL_SERVER_ADDR);

	// user name
	VappSyncTextInputItem *txtUsrName;
	VFX_OBJ_CREATE(txtUsrName, VappSyncTextInputItem, m_form);
	txtUsrName->setLabelPosition(VCPFORM_TOP_LEFT);
	strTemp.format("%s", accnt->server_username);
	txtUsrName->setText(strTemp);
	txtUsrName->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
	txtUsrName->getTextBox()->setMaxLength(MAX_SYNCML_USERNAME - 1);
	txtUsrName->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_CHAR);
	txtUsrName->setLabelText(VFX_WSTR_RES(STR_GLOBAL_USERNAME)); 
	txtUsrName->m_signalFocusChange.connect(this, &VappSyncRemoteAccntEditServerPage::onFocusChange);
	m_form->addItem(txtUsrName, ID_FORM_CELL_SERVER_USERNAME);
	
	// password
	VappSyncTextInputItem *txtPassWord;
	VFX_OBJ_CREATE(txtPassWord, VappSyncTextInputItem, m_form);
	txtPassWord->setLabelPosition(VCPFORM_TOP_LEFT);
	strTemp.format("%s", accnt->server_password);
	txtPassWord->setText(strTemp);
	txtPassWord->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
	txtPassWord->getTextBox()->setMaxLength(MAX_SYNCML_PASSWORD - 1);
	txtPassWord->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_PASSWORD);
	txtPassWord->setLabelText(VFX_WSTR_RES(STR_GLOBAL_PASSWORD));
	txtPassWord->m_signalFocusChange.connect(this, &VappSyncRemoteAccntEditServerPage::onFocusChange);
	m_form->addItem(txtPassWord, ID_FORM_CELL_SERVER_PASSWORD);
	
	m_activeId = ID_FORM_CELL_SERVER_ADDR;
	m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_TRUE);
	m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_FALSE);
}

void VappSyncRemoteAccntEditServerPage::onDeinit(void)
{
	VFX_OBJ_CLOSE(m_funcBar);

	VfxPage::onDeinit();
}

void VappSyncRemoteAccntEditServerPage::onSave(void)
{
	VfxBool isValid = VFX_TRUE;
	
	
	VcpFormItemTextInput *txtInput;
	
	txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_FORM_CELL_SERVER_ADDR);

	VfxS8* addrBuffer;
	VFX_ALLOC_MEM(addrBuffer, MAX_SYNCML_SERVER_ADDR_LEN, this);
	
	if (txtInput->getText().getLength() == 0)
	{
		isValid = VFX_FALSE;
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_PLS_SERVER_ADDR));
		m_form->scrollItemToView(ID_FORM_CELL_SERVER_ADDR, VCPFORM_SCROLL_BOTTOM);
	}
	else
	{
			
		mmi_ucs2_n_to_asc((CHAR *)addrBuffer, 
					  (CHAR *)txtInput->getText().getBuf(), 
					  (txtInput->getText().getLength() * 2));

		addrBuffer[txtInput->getText().getLength()] = 0;

		if ((applib_url_is_valid((const char *)addrBuffer) != 0))
		{
			isValid = VFX_FALSE;
			txtInput->setWarningText(VFX_WSTR_RES(STR_GLOBAL_INVALID_URL));
			m_form->scrollItemToView(ID_FORM_CELL_SERVER_ADDR, VCPFORM_SCROLL_BOTTOM);
		}
	}
	
	if (isValid)
	{
		nvram_ef_syncml_account_struct *accnt;
		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIndex);
	
		vfx_sys_strcpy((VfxChar *)accnt->server_address, (const VfxChar *)addrBuffer);
		
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
	
	srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, m_accntIndex);
	
	m_signalEditDone.postEmit(this, m_accntIndex);
}
	
	VFX_FREE_MEM(addrBuffer);
	
}

void VappSyncRemoteAccntEditServerPage::onCancel(void)
{
	getMainScr()->popPage();
}

void VappSyncRemoteAccntEditServerPage::onFocusChange(VfxObject *obj, VfxId id, VfxBool isActive)
{
	//VcpFormItemTextInput *txtInput;
	
	m_form->getItem(id);

	if (isActive)
	{
		m_activeId = id;
		
		if (id == ID_FORM_CELL_SERVER_ADDR)
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

void VappSyncRemoteAccntEditServerPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case ID_TOOLBAR_SYNC_ACCNT_SERVER_SAVE:
			onSave();
			break;
			
		case ID_TOOLBAR_SYNC_ACCNT_CANCEL:
			onCancel();
			break;
			
		default:
			break;
	}
}

void VappSyncRemoteAccntEditServerPage::onFuncBarClick(	VfxObject *sender, VfxId id)
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
		nextId >= ID_FORM_CELL_SERVER_ADDR)
	{
		VcpFormItemTextInput *textInput;
		textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
		textInput->getTextBox()->activate();
	}
}

