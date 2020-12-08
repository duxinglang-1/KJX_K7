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
 *  vapp_sync_accnt_list_menu.cpp
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
#include "common_nvram_editor_data_item.h" 
#include "GlobalResDef.h"
#include "mmi2syncml_struct.h"

#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_sync_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "SyncSrvGprot.h"
extern "C"
{
#include "ModeSwitchSrvGprot.h"
}

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vapp_sync.h"
#include "vapp_sync_now.h"
#include "vapp_sync_remote_log.h"

#include "vapp_sync_remote_accnt_add.h"
#include "vapp_sync_remote_accnt_edit.h"
#include "vapp_sync_remote_accnt_list.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define VAPP_SYNC_ACCNT_REMOTE	'REMT'	/* Remote sync */
#define VAPP_SYNC_ACCNT_PHONE	'PHON'	/* Phone sync */

#define ID_TOOLBAR_SYNC_NEWSYNC		'SYNC'
#define ID_TOOLBAR_SYNC_ACCNT_ADD	'ADD'

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncRemoteAccntListMenu
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntListMenu", VappSyncRemoteAccntListMenu, VappSyncAccntListMenu);
VfxBool VappSyncRemoteAccntListMenu::getHeaderText(VfxWString &text)
{
	text = VFX_WSTR_RES(STR_ID_VAPP_SYNC_REMOTE_ACCNTS);
	
	VfxWString statStr;	
	statStr.format(" (%d/%d)", m_nAccnt, MAX_SYNCML_SV_PROFILES);

	text += statStr;
	
	return VFX_TRUE;
}

VfxBool VappSyncRemoteAccntListMenu::getText(VfxS32 index, VfxWString &text)
{
	VFX_ASSERT(index < MAX_SYNCML_SV_PROFILES);
	
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, (VfxU8)index);

	text = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);
	
	return VFX_TRUE;
}

VfxU32 VappSyncRemoteAccntListMenu::getUpdatedCount(void)
{	
	nvram_ef_syncml_account_struct *accnt;
	VfxU32 count = 0;
	
	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, i);
		if (accnt->timestamp != 0)
		{
			m_indexArray[count].index = i;
			m_indexArray[count].timestamp = accnt->timestamp;
			
			count++;
		}
	}

	return count;
}

VfxBool VappSyncRemoteAccntListMenu::isShowIcon(const VfxS32 &index)
{
	nvram_ef_syncml_view_log_struct *vLog;
	VfxBool bRet = VFX_FALSE;
	VfxS16 errCode;
		
	VFX_ALLOC_MEM(vLog, NVRAM_EF_SYNCML_VIEW_LOG_SIZE, this);
	
	ReadRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, 
			   (index + 1), 
			   vLog, 
			   NVRAM_EF_SYNCML_VIEW_LOG_SIZE, 
			   &errCode);
	
	if (vLog->last_sync_time != 0 && ((SYNCML_GET_SYNC_STATUS(vLog->sync_result)) != SRV_SYNC_OK))
	{
		bRet = VFX_TRUE;
	}
	
	VFX_FREE_MEM(vLog);
	
	return bRet;
}

VfxBool VappSyncRemoteAccntListMenu::getMenuEmptyText(
	VfxWString &text,				 // [OUT] the text resource
	VcpListMenuTextColorEnum &color  // [OUT] the text color
	)
{
	text.loadFromRes(STR_ID_VAPP_SYNC_NO_ACCNT);
	return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappSyncRemoteAccntListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntListPage", VappSyncRemoteAccntListPage, VfxPage);
VappSyncRemoteAccntListPage::VappSyncRemoteAccntListPage(const VfxBool &bTitle)
	: m_list(NULL), 
	  m_hasTitle(bTitle), 
	  m_activeIndex(0)
{
}

VfxU32 VappSyncRemoteAccntListPage::getTotalCount(void)
{
	nvram_ef_syncml_account_struct *accnt;
	VfxU32 count = 0;
	
	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		memset(m_nameBuffer[i], 0, MAX_SYNCML_PROFILE_NAME * sizeof(VfxWChar));
		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, i);
		if (accnt->timestamp != 0)
		{
			vfx_sys_wcsncpy(m_nameBuffer[i], (const VfxWChar *)accnt->account_name, MAX_SYNCML_PROFILE_NAME);
			count++;
		}
	}
	
	return count;
}

void VappSyncRemoteAccntListPage::onInit(void)
{
	VfxPage::onInit();

	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		VFX_ALLOC_MEM(m_nameBuffer[i], (MAX_SYNCML_PROFILE_NAME * sizeof(VfxWChar)), this);
	}
	
	if (m_hasTitle)
	{
		VcpTitleBar *titleBar;
		VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_REMOTE));
		setTopBar(titleBar);
	}
	
	VFX_OBJ_CREATE(m_list, VappSyncRemoteAccntListMenu, this);
	m_list->setSize(getSize()); 
	m_list->setAlignParent(
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE);
	m_list->m_signalTap.connect(this, &VappSyncRemoteAccntListPage::onTapCallback);
	m_list->m_signalAction.connect(this, &VappSyncRemoteAccntListPage::onActionCallback);

	//tool bar
	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem(ID_TOOLBAR_SYNC_ACCNT_ADD, VFX_WSTR_RES(STR_ID_VAPP_SYNC_ADD_RMT_ACCNT), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
	toolBar->m_signalButtonTap.connect(this, &VappSyncRemoteAccntListPage::onToolbarClick);
	setBottomBar(toolBar);

	mmi_frm_cb_reg_event(EVT_ID_SRV_SYNC_ACCNT_OP, VappSyncRemoteAccntListPage::onAccntChange, getObjHandle());

}

void VappSyncRemoteAccntListPage::onDeinit(void)
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SYNC_ACCNT_OP, VappSyncRemoteAccntListPage::onAccntChange, getObjHandle());

	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		VFX_FREE_MEM(m_nameBuffer[i]);
	}

	VfxPage::onDeinit();
}

void VappSyncRemoteAccntListPage::onEnter(VfxBool isBackward)
{
	getTotalCount();
	
	m_list->updateAllItems();

	VfxPage::onEnter(isBackward);
}

void VappSyncRemoteAccntListPage::onTapCallback(VfxObject *obj, VfxS32 index)
{
	VappSyncRemoteAccntEditPage *rmtEditPage;
	
	VFX_OBJ_CREATE_EX(rmtEditPage, VappSyncRemoteAccntEditPage, this, (index));
	rmtEditPage->m_signalAction.connect(this, &VappSyncRemoteAccntListPage::onActionCallback);
	getMainScr()->pushPage(VAPP_SYNC_PAGE_ID(ACCNT_EDIT), rmtEditPage);
}

void VappSyncRemoteAccntListPage::onActionCallback(VfxObject *obj, VfxId action, VfxS32 index)
{
	switch(action)
	{
		case VAPP_SYNC_ACCNT_LIST_ACTION_SYNC:
		{
			if (!VappSyncApp::isSyncAvailable(VFX_TRUE))
			{
				return;
			}
			else
			{
			startSync(index);
			}
			break;
		}
		
		case VAPP_SYNC_ACCNT_LIST_ACTION_DELETE:
		{
			nvram_ef_syncml_account_struct *accnt;
			accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, index);
			memset(accnt, 0, sizeof(nvram_ef_syncml_account_struct));
			srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, index);
			
			m_list->updateAllItems();

			break;
		}	

		case VAPP_SYNC_ACCNT_LIST_ACTION_VLOG:
		{
			viewLog(index);
			break;
		}
		
		default:
			break;
	}
}

void VappSyncRemoteAccntListPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	if (id == ID_TOOLBAR_SYNC_ACCNT_ADD)
	{
		if (srv_sync_accnt_new_index(SRV_SYNC_REMOTE) >= 0)
		{
			VappSyncMainScr *scr = (VappSyncMainScr *)getMainScr();
			scr->showPage(VAPP_SYNC_PAGE_ID(ADD_SERVER), 0);
		}
		else
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_SYNC_REACH_MAXIMUM));
		}
	}		
}

void VappSyncRemoteAccntListPage::startSync(const VfxS32 &index)
{
	VappSyncApp *app = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getApp(), VappSyncApp);

	if (app != NULL)
	{
		app->showSyncNow(SRV_SYNC_REMOTE, index, NULL);
	}
}

void VappSyncRemoteAccntListPage::viewLog(const VfxS32 &index)
{
	VappSyncRemoteLogPage *logPage;
	
	VFX_OBJ_CREATE_EX(logPage, VappSyncRemoteLogPage, this, (index));
	getMainScr()->pushPage(VFX_ID_NULL, logPage);
}

VfxBool VappSyncRemoteAccntListPage::checkExistAccntName(const VfxU8 &activeIdx, const VfxWChar *newName) const
{
	VfxBool ret = VFX_FALSE;

	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{		
		if (i != activeIdx && 
			vfx_sys_wcslen(m_nameBuffer[i]) != 0 &&
			vfx_sys_wcscmp(m_nameBuffer[i], newName) == 0)
		{
			ret = VFX_TRUE;
			break;
		}
	}

	return ret;
}

mmi_ret VappSyncRemoteAccntListPage::processAccntChange(mmi_event_struct *evt)
{
	getTotalCount();
	
	return MMI_RET_OK;
}

mmi_ret VappSyncRemoteAccntListPage::onAccntChange(mmi_event_struct *evt)
{
	VappSyncRemoteAccntListPage *thiz = (VappSyncRemoteAccntListPage *)handleToObject((VfxObjHandle)evt->user_data);
	if (thiz != NULL)
	{
		return thiz->processAccntChange(evt);
	}
	
	return MMI_RET_OK;
}


