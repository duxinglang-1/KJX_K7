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
 *  vapp_sync_accnt_edit_database.cpp
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
#include "ImeGprotEnums.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_sync_def.h"

#include "SyncSrvGprot.h"

#include "vfx_object.h"
#include "vfx_string.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_function_bar.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_edit_txtitem.h"
#include "vapp_sync_accnt_edit_database.h"

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

VFX_IMPLEMENT_CLASS("VappSyncAccntEditDatabasePage", VappSyncAccntEditDatabasePage, VfxPage);
VappSyncAccntEditDatabasePage::VappSyncAccntEditDatabasePage(const VfxS32 &accntIndex, const VfxU32 &dbMask)
	: m_funcBar(NULL),
	  m_form(NULL),
	  m_accntIndex(accntIndex),
	  m_dbCheckMask(dbMask),
	  m_activeItem(0xFF)
{
}
void VappSyncAccntEditDatabasePage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_DB_ADDR));
	setTopBar(titleBar);

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	toolBar->m_signalButtonTap.connect(this, &VappSyncAccntEditDatabasePage::onToolbarClick);
	setBottomBar(toolBar);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setSize(getSize());
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE);

	VfxU8 i = 0, total = 0;
	for (i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (VAPP_SYNC_GET_DB_MASK(i) & m_dbCheckMask)
		{
			total++;
		}
	}

	VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);

	if (total > 1)
	{
    	m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FUNC_PREV));
   	 	m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_WSTR_RES(STR_ID_VAPP_SYNC_FUNC_NEXT));
	}
    m_funcBar->addItem(ID_FUNCBAR_SYNC_ACCNT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_funcBar->setItemSpecial(ID_FUNCBAR_SYNC_ACCNT_SAVE);
    m_funcBar->m_signalButtonTap.connect(this, &VappSyncAccntEditDatabasePage::onFuncBarClick);
	
	m_totalDb = 0;
	for (i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (VAPP_SYNC_GET_DB_MASK(i) & m_dbCheckMask)
		{
			VappSyncTextInputItem *txtInput;
			
			VFX_OBJ_CREATE(txtInput, VappSyncTextInputItem, m_form);
			txtInput->setLabelPosition(VCPFORM_TOP_LEFT);
			txtInput->setText(getAddress(m_accntIndex, i));
			txtInput->setLabelText(VAPP_SYNC_GET_DB_NAME(i));
			txtInput->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
			txtInput->getTextBox()->setMaxLength(getMaxAddrLen(m_accntIndex, i));
			txtInput->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_CHAR);
			txtInput->m_signalFocusChange.connect(this, &VappSyncAccntEditDatabasePage::onFocusChange);
			m_form->addItem(txtInput, i);

			m_idBuff[m_totalDb++] = i;
		}
		}

	VappSyncTextInputItem *activeInput;
	activeInput = (VappSyncTextInputItem *)m_form->getItem(m_idBuff[0]);
	activeInput->getTextBox()->setAutoActivated(VFX_TRUE);
	}

void VappSyncAccntEditDatabasePage::onDeinit(void)
{
	VFX_OBJ_CLOSE(m_funcBar);

	VfxPage::onDeinit();
}

VfxWString VappSyncAccntEditDatabasePage::getAddress(const VfxS32 accntIndex, const VfxU32 &dbID)
{
	return VFX_WSTR_NULL;
}

VfxU32 VappSyncAccntEditDatabasePage::getMaxAddrLen(const VfxS32 accntIndex, const VfxU32 &dbID) const
{
	return MAX_SYNCML_DATABASE_ADDR_LEN; 
}

VfxBool VappSyncAccntEditDatabasePage::onSave(void)
{
	if (!checkAddress())
	{
		return VFX_FALSE;
	}
	
	VcpFormItemTextInput *txtInput;
	
	for (VfxU8 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (VAPP_SYNC_GET_DB_MASK(i) & m_dbCheckMask)
		{
			txtInput = (VcpFormItemTextInput *)m_form->getItem(i);
			saveAddr(m_accntIndex, i, txtInput->getText().getBuf(), txtInput->getText().getLength());
		}
	}

	m_signalEditDone.postEmit(this, m_accntIndex, m_dbCheckMask);

	return VFX_TRUE;
}

VfxU8 VappSyncAccntEditDatabasePage::findIndex(const VfxId &id) const
{
	VfxU8 i;
	
	for (i = 0; i < m_totalDb; i++)
	{
		if (m_idBuff[i] == id)
		{
			break;
		}
	}
	
	return i;
}

void VappSyncAccntEditDatabasePage::onCancel(void)
{
	getMainScr()->popPage();
}

void VappSyncAccntEditDatabasePage::onToolbarClick(VfxObject* obj, VfxId id)
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

VfxBool VappSyncAccntEditDatabasePage::checkAddress(void)
{
	VfxBool isValid = VFX_TRUE;
	VcpFormItemTextInput *txtInput;
	
	for (VfxU8 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if ((VAPP_SYNC_GET_DB_MASK(i) & m_dbCheckMask))
		{
			txtInput = (VcpFormItemTextInput *)m_form->getItem(i);
			if (txtInput != NULL && txtInput->getText().isEmpty())
			{
				txtInput->setWarningText(VFX_WSTR_RES(VAPP_SYNC_GET_DB_CHK_INVALID_RESID(i)));			

				// only scroll to the first item.
				if (isValid)
				{
					m_form->scrollItemToView(i, VCPFORM_SCROLL_BOTTOM);
				}
				isValid = VFX_FALSE;
			}
			else
			{
				txtInput->setWarningText(VFX_WSTR_NULL);			
			}
		}
	}

	return isValid;
}

void VappSyncAccntEditDatabasePage::onFuncBarClick(	VfxObject *sender, VfxId id)
{
	VfxId nextId = 0xFF;
	
	switch(id)
	{			
		case ID_FUNCBAR_SYNC_ACCNT_PREV:
			nextId = m_idBuff[m_activeItem - 1];
			break;
			
		case ID_FUNCBAR_SYNC_ACCNT_NEXT:
			nextId = m_idBuff[m_activeItem + 1];
			break;
			
		case ID_FUNCBAR_SYNC_ACCNT_SAVE:
			onSave();
			break;
			
		default:
			break;
		}

	if (nextId != 0xFF)
	{
		VcpFormItemTextInput *textInput;
		textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
		textInput->getTextBox()->activate();
	}
}

void VappSyncAccntEditDatabasePage::onFocusChange(VfxObject *item, VfxId id, VfxBool isActive)
{
	//VcpFormItemTextInput *txtInput;
		
	m_form->getItem(id);

	if (isActive)
	{
		m_activeItem = findIndex(id);
			
		if (m_totalDb < 2) 
		{
			return;
		}

		if (m_activeItem == 0)
		{
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_PREV, VFX_TRUE);
			m_funcBar->setDisableItem(ID_FUNCBAR_SYNC_ACCNT_NEXT, VFX_FALSE);
		}
		else if (m_activeItem == (m_totalDb - 1))
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

