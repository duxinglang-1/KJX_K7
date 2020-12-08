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
 *  vapp_sync_accnt_edit_name.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "common_nvram_editor_data_item.h"
#include "GlobalResDef.h"

#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_sync_def.h"

#include "SyncSrvGprot.h"

#include "vcp_form.h"
#include "vcp_function_bar.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vapp_sync_accnt_edit_txtitem.h"
#include "vapp_sync_accnt_edit_name.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define ID_TOOLBAR_SYNC_ACCNT_SAVE		'SAVE'
#define ID_TOOLBAR_SYNC_ACCNT_CANCEL	'CANL'


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncAccntEditDatabasePage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSyncAccntEditNamePage", VappSyncAccntEditNamePage, VfxPage);
VappSyncAccntEditNamePage::VappSyncAccntEditNamePage(const VfxS32 &accntIndex)
	: m_form(NULL),
	  m_accntIndex(accntIndex)
{
}
void VappSyncAccntEditNamePage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_NAME));
	setTopBar(titleBar);

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	toolBar->m_signalButtonTap.connect(this, &VappSyncAccntEditNamePage::onToolbarClick);
	setBottomBar(toolBar);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
					VFX_FRAME_ALIGNER_MODE_SIDE, 
					VFX_FRAME_ALIGNER_MODE_SIDE, 
					VFX_FRAME_ALIGNER_MODE_SIDE);
	
	VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_funcBar->setItemSpecial(ID_FUNCBAR_SYNC_ACCNT_SAVE);
    m_funcBar->m_signalButtonTap.connect(this, &VappSyncAccntEditNamePage::onFuncBarClick);

	VcpFormItemTextInput *txtInput;
	VFX_OBJ_CREATE(txtInput, VcpFormItemTextInput, m_form);
	txtInput->setLabelPosition(VCPFORM_TOP_LEFT);
	txtInput->setText(getName(m_accntIndex));
	txtInput->setLabelText(getLabel(m_accntIndex));
	txtInput->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
	txtInput->getTextBox()->setMaxLength(getMaxLen(m_accntIndex));
	txtInput->getTextBox()->setAutoActivated(VFX_TRUE);
	
	m_form->addItem(txtInput, ID_VAPP_SYNC_EDIT_NAME);
	
}

void VappSyncAccntEditNamePage::onDeinit(void)
{
	VFX_OBJ_CLOSE(m_funcBar);
	
	VfxPage::onDeinit();
}

void VappSyncAccntEditNamePage::onSave(void)
{
	VcpFormItemTextInput *txtInput;
	txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_VAPP_SYNC_EDIT_NAME);

	if (txtInput->getText().getLength() == 0)
	{
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_DB_INVALID_ACCNT_NAME));
		return;
	}
	
	if (!onSaveName(m_accntIndex, txtInput->getText()))
	{
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_NAME_EXIST));
		return;
	}
	
	m_signalEditDone.postEmit(this, m_accntIndex);
}

void VappSyncAccntEditNamePage::onCancel(void)
{
	getMainScr()->popPage();
}

void VappSyncAccntEditNamePage::onToolbarClick(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case ID_TOOLBAR_SYNC_ACCNT_SAVE:
			onSave();
			break;
			
		case ID_TOOLBAR_SYNC_ACCNT_CANCEL:
			onCancel();
			break;
			
		default:
			break;
	}
}

void VappSyncAccntEditNamePage::onFuncBarClick(	VfxObject *sender, VfxId id)
{
	if (id == ID_FUNCBAR_SYNC_ACCNT_SAVE)
	{
		onSave();
	}
}

