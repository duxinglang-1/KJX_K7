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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#include "GlobalResDef.h"

#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_string.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vapp_sync_accnt_edit_select_database.h"

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
 * Class VappSyncAccntSelectDatabasePage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSyncAccntSelectDatabasePage", VappSyncAccntSelectDatabasePage, VfxPage);
void VappSyncAccntSelectDatabasePage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_APP_TO_SYNC));
	setTopBar(titleBar);

	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_SELDB_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	toolBar->m_signalButtonTap.connect(this, &VappSyncAccntSelectDatabasePage::onToolbarClick);
	setBottomBar(toolBar);

	VcpListMenu *lstMenu;
	VFX_OBJ_CREATE(lstMenu, VcpListMenu,this);
	lstMenu->setContentProvider(this);
	lstMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	lstMenu->setContentProvider(this);
	lstMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_FALSE);
	lstMenu->m_signalItemSelectionStateChanged.connect(this, &VappSyncAccntSelectDatabasePage::onListItemSelect);
	lstMenu->setSize(getSize());

	for (VfxU8 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (VAPP_SYNC_GET_DB_MASK(i) & m_databaseMask)
		{
			m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_SELECTED;
		}
		else
		{
			m_stateLst[i] = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
		}
	}
}


VfxBool VappSyncAccntSelectDatabasePage::getItemText(
											VfxU32 index,
											VcpListMenuFieldEnum fieldType,
											VfxWString &text,
											VcpListMenuTextColorEnum &color
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

VcpListMenuItemStateEnum VappSyncAccntSelectDatabasePage::getItemState(VfxU32 index) const
{	
	return m_stateLst[index];
}

void VappSyncAccntSelectDatabasePage::onSave(void)
{
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
	
	m_signalSelectDone.postEmit(this, m_databaseMask);
}

void VappSyncAccntSelectDatabasePage::onCancel(void)
{
	getMainScr()->popPage();
}

void VappSyncAccntSelectDatabasePage::onListItemSelect(VcpListMenu *obj, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	m_stateLst[index] = newState;
}

void VappSyncAccntSelectDatabasePage::onToolbarClick(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case ID_TOOLBAR_SYNC_ACCNT_SELDB_SAVE:
			onSave();
			break;
			
		case ID_TOOLBAR_SYNC_ACCNT_CANCEL:
			onCancel();
			break;
			
		default:
			break;
	}
}

