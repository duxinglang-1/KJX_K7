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

#include "mmi_rp_vapp_sync_def.h"

extern "C"
{
	#include "mmi2syncml_struct.h"
	#include "BTMMIScrGprots.h"
	#include "BthScoPathSrvGProt.h"
	#include "UCMSrvGprot.h"
	#include "SyncSrvGprot.h"
}

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"

#include "vcui_bt_gprot.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_edit_select_database.h"
#include "vapp_sync_phone_log.h"
#include "vapp_sync_phone_accnt_edit.h"
#include "vapp_sync_phone_accnt_list.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define PHONE_COD_MASK (MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK | MMI_BT_PHONE_MAJOR_DEVICE_MASK | MMI_BT_TELEPHONY_MAJOR_SERVICE_MASK)

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
 * Class VappSyncPhoneAccntListMenu
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncPhoneAccntListMenu", VappSyncPhoneAccntListMenu, VappSyncAccntListMenu);
VfxBool VappSyncPhoneAccntListMenu::getHeaderText(VfxWString &text)
{
	text = VFX_WSTR_RES(STR_ID_VAPP_SYNC_SYNCED_PHONES);
	
	VfxWString statStr;
	statStr.format(" (%d/%d)", m_nAccnt, MAX_SYNCML_DEV_NUM);

	text += statStr;
	
	return VFX_TRUE;
}

VfxBool VappSyncPhoneAccntListMenu::getText(VfxS32 index, VfxWString &text)
{
	VFX_ASSERT(index < MAX_SYNCML_DEV_NUM);
	
	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, (VfxU8)index);

	VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];
	
	ucs2_buff[0] = 0;
	ucs2_buff[1] = 0;
	
	srv_bt_cm_get_dev_ucs2_name((srv_bt_cm_bt_addr *)&accnt->dev_bt_addr, SRV_BT_CM_BD_UCS2_NAME_LEN, (WCHAR *)ucs2_buff);
	
	text = VFX_WSTR_MEM(ucs2_buff);

	return VFX_TRUE;
}

VfxU32 VappSyncPhoneAccntListMenu::getUpdatedCount(void)
{
	nvram_ef_syncml_device_accnt_struct *accnt;
	VfxU32 count = 0;
	
	for (VfxU8 i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, i);
		if (accnt->timestamp != 0)
		{
			m_indexArray[count].index = i;
			m_indexArray[count].timestamp = accnt->timestamp;
			count++;
		}
	}

	return count;
}

VfxBool VappSyncPhoneAccntListMenu::isShowIcon(const VfxS32 &index)
{
	nvram_ef_syncml_view_log_struct *vLog;
	VfxBool bRet = VFX_FALSE;
	VfxS16 errCode;
	
	VFX_ALLOC_MEM(vLog, NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE, this);
	
	ReadRecord(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID, 
			   (index + 1), 
			   vLog, 
			   NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE, 
			   &errCode);
	
	if (vLog->last_sync_time != 0 && ((SYNCML_GET_SYNC_STATUS(vLog->sync_result)) != SRV_SYNC_OK))
	{
		bRet = VFX_TRUE;
	}
	
	VFX_FREE_MEM(vLog);

	VAPP_SYNC_LOG2(MMI_SYNC_SHOW_ICON, index, bRet);
	return bRet;
}


VfxBool VappSyncPhoneAccntListMenu::getMenuEmptyText(
	VfxWString &text,				 // [OUT] the text resource
	VcpListMenuTextColorEnum &color  // [OUT] the text color
	)
{
	text.loadFromRes(STR_ID_VAPP_SYNC_NO_PHONE);
	
	return VFX_TRUE;
}

/***************************************************************************** 
 * Class VappSyncPhoneAccntListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncPhoneAccntListPage", VappSyncPhoneAccntListPage, VfxPage);
VappSyncPhoneAccntListPage::VappSyncPhoneAccntListPage(const VfxBool &bTitle) :
	m_list(NULL),
	m_hasTitle(bTitle),
	m_activeIndex(0)
{
}
void VappSyncPhoneAccntListPage::onInit(void)
{
	VfxPage::onInit();

	if (m_hasTitle)
	{
		VcpTitleBar *titleBar;
		VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_SYNCED_PHONES));
		setTopBar(titleBar);
	}
	
	VFX_OBJ_CREATE(m_list, VappSyncPhoneAccntListMenu, this);
	m_list->setSize(getSize());
			m_list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
	
	m_list->m_signalTap.connect(this, &VappSyncPhoneAccntListPage::onTapCallback);
	m_list->m_signalAction.connect(this, &VappSyncPhoneAccntListPage::onActionCallback);

	//tool bar
	VcpToolBar *toolBar; 
	VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolBar->addItem('INIT', VFX_WSTR_RES(STR_ID_VAPP_SYNC_INIT_PHONE_SYNC), IMG_ID_VAPP_SYNC_INIT_PHONE);
	toolBar->m_signalButtonTap.connect(this, &VappSyncPhoneAccntListPage::onToolbarClick);
	setBottomBar(toolBar);
	
}

void VappSyncPhoneAccntListPage::onEnter(VfxBool isBackward)
{	
	m_list->updateAllItems();

	VfxPage::onEnter(isBackward);
}

VfxU32 VappSyncPhoneAccntListPage::getTotalCount(void)
{
	nvram_ef_syncml_device_accnt_struct *accnt;
	VfxU32 count = 0;
	
	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, i);
		if (accnt->timestamp != 0)
		{
			count++;
		}
	}
	
	return count;
}

void VappSyncPhoneAccntListPage::onTapCallback(VfxObject *obj, VfxS32 index)
{
	VappSyncPhoneAccntEditPage *page;

	VFX_OBJ_CREATE_EX(page, VappSyncPhoneAccntEditPage, this, (index));
	page->m_signalAction.connect(this, &VappSyncPhoneAccntListPage::onActionCallback);
	
	getMainScr()->pushPage(VFX_ID_NULL, page);
}

void VappSyncPhoneAccntListPage::onActionCallback(VfxObject *obj, VfxId action, VfxS32 index)
{
	switch(action)
	{
		case VAPP_SYNC_ACCNT_LIST_ACTION_SYNC:
		{
			#if defined(__MMI_BT_AUDIO_SUPPORT__)
			if (srv_btsco_is_sco_open() && 
				srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
			{
				mmi_frm_nmgr_balloon(
					MMI_SCENARIO_ID_GENERAL,
					MMI_EVENT_INFO_BALLOON,
					MMI_NMGR_BALLOON_TYPE_INFO,
					(WCHAR *)GetString(STR_GLOBAL_NOT_AVAILABLE));

				return;
			}
			#endif /* __MMI_BT_AUDIO_SUPPORT__ */
			
			#ifdef __MMI_BT_AUTHORIZE__
			nvram_ef_syncml_device_accnt_struct *accnt;
			accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, index);
			
			srv_bt_cm_authorize_type auth = srv_bt_cm_get_authorize((const srv_bt_cm_bt_addr *)&accnt->dev_bt_addr);
			if (auth == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
			{
				mmi_frm_nmgr_balloon(
					MMI_SCENARIO_ID_GENERAL,
					MMI_EVENT_INFO_BALLOON,
					MMI_NMGR_BALLOON_TYPE_INFO,
					(WCHAR *)GetString(STR_GLOBAL_NOT_AVAILABLE));

				return;
			}
			#endif /* __MMI_BT_AUTHORIZE__ */

			m_activeIndex = index;
			if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
			{
				startSync(index);
			}
			else
			{
				cui_bt_power_on_struct param;
				param.confirm_type = CUI_BT_POWER_ON_WITH_ALL_CONFIRM;
				
				mmi_id grpId = vcui_bt_power_on_create(getMainScr()->getGroupId(), &param);
				if (grpId != GRP_ID_INVALID)
				{
					vfxSetCuiCallerScr(grpId, getMainScr());
					vcui_bt_power_on_run(grpId);
				}
				else
				{
					mmi_frm_nmgr_balloon(
						MMI_SCENARIO_ID_GENERAL,
						MMI_EVENT_INFO_BALLOON,
						MMI_NMGR_BALLOON_TYPE_INFO,
						(WCHAR *)GetString(STR_GLOBAL_NOT_AVAILABLE));
				}
			}
			break;
		}
		
		case VAPP_SYNC_ACCNT_LIST_ACTION_DELETE:
		{
			nvram_ef_syncml_device_accnt_struct *accnt;
			accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, index);
			accnt->timestamp = 0;
			srv_sync_write_accnt(SRV_SYNC_PHONE, accnt, index);

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


void VappSyncPhoneAccntListPage::onToolbarClick(VfxObject* obj, VfxId id)
{
	switch(id)
	{
		case 'INIT':
		{
			cui_bt_select_device_struct bt_attr;
			bt_attr.cod_mask = (MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK | 
							    MMI_BT_PHONE_MAJOR_DEVICE_MASK |
      						    MMI_BT_TELEPHONY_MAJOR_SERVICE_MASK);
			bt_attr.service_id = 0;

			mmi_id grpId = vcui_bt_select_device_create(getMainScr()->getGroupId(), &bt_attr);
			if (grpId != GRP_ID_INVALID)
			{
				vfxSetCuiCallerScr(grpId, getMainScr());
				vcui_bt_select_device_run(grpId);
			}
			else
			{
				mmi_frm_nmgr_balloon(
					MMI_SCENARIO_ID_GENERAL,
					MMI_EVENT_INFO_BALLOON,
					MMI_NMGR_BALLOON_TYPE_INFO,
					(WCHAR *)GetString(STR_GLOBAL_NOT_AVAILABLE));
			}

			break;
		}
		
		default:
			break;
	}
}


mmi_ret VappSyncPhoneAccntListPage::onProc(mmi_event_struct *evt)
{
	VFX_ASSERT(evt != NULL);
	
	VAPP_SYNC_LOG0(MMI_SYNC_PHONE_LIST_PROC);

	switch(evt->evt_id)
	{
		case EVT_ID_GROUP_CUI_BT_SELECT_DEVICE:
		{
			cui_bt_select_device_result *bt_select = (cui_bt_select_device_result *)evt;

			VAPP_SYNC_LOG1(MMI_SYNC_PHONE_LIST_PROC_BT, bt_select->result);
			
			if (bt_select->result)
			{
				if (!isCodMatch(bt_select->dev_info.cod, PHONE_COD_MASK))
				{
					mmi_frm_nmgr_balloon(
						MMI_SCENARIO_ID_GENERAL,
						MMI_EVENT_INFO_BALLOON,
						MMI_NMGR_BALLOON_TYPE_INFO,
						(WCHAR *)GetString(STR_GLOBAL_NOT_SUPPORTED));
					
					break;
				}
				
				memcpy(&m_selBtAddr, &bt_select->dev_info.bd_addr, sizeof(srv_bt_cm_bt_addr));
				
				VfxBool isNew = VFX_FALSE;
				VfxS32 accntIdx = VappSyncPhoneAccntListPage::locateAccntIndex(
										isNew, 
										&m_selBtAddr);

				if (isNew)
				{
					startNewSync();
				}
				else
				{
					startSync(accntIdx);
				}
				
				m_activeIndex = accntIdx;
			}
			
			vcui_bt_select_device_close(bt_select->cui_id);
		}
		break;
		
		case EVT_ID_GROUP_CUI_BT_POWER_ON:
		{
			cui_bt_power_on_result *pwr_on = (cui_bt_power_on_result *)evt;
            
			MMI_TRACE(TRACE_GROUP_2, MMI_SYNC_PHONE_ON_BTON, pwr_on->result, m_activeIndex);
			
			if (pwr_on->result)
			{
			startSync(m_activeIndex);
			}

			vcui_bt_power_on_close(pwr_on->cui_id);
			
			break;
		}
		
		default:
			break;
	}

	return MMI_RET_OK;
}

void VappSyncPhoneAccntListPage::onSelectDone(VfxObject *obj, VfxU32 dbMask)
{
	getMainScr()->popPage();
	
	// save the selected device
	nvram_ef_syncml_device_accnt_struct *accnt;

	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_activeIndex);

	memset(accnt, 0, sizeof(nvram_ef_syncml_device_accnt_struct));
	// default value is 0
	memcpy(&accnt->dev_bt_addr, &m_selBtAddr, sizeof(srv_bt_cm_bt_addr));
	accnt->dev_bt_cod = srv_bt_cm_get_dev_cod(&m_selBtAddr);
	accnt->role = SYNCML_DS_SERVER;
	accnt->report_status = 0;
	accnt->app_to_sync = dbMask;
	
	// default value.
	accnt->timestamp = srv_sync_get_current_time();
	srv_sync_write_accnt(SRV_SYNC_PHONE, accnt, m_activeIndex);
	
	m_list->updateAllItems();
	
	startSync(m_activeIndex);
}

void VappSyncPhoneAccntListPage::startNewSync(void)
{
	VAPP_SYNC_LOG0(MMI_SYNC_PHONE_START_NEW_SYNC);

	VappSyncAccntSelectDatabasePage *page;

	VFX_OBJ_CREATE(page, VappSyncAccntSelectDatabasePage, getMainScr());
	page->m_signalSelectDone.connect(this, &VappSyncPhoneAccntListPage::onSelectDone);
	
	getMainScr()->pushPage(VFX_ID_NULL, page);
}

void VappSyncPhoneAccntListPage::startSync(const VfxS32 &index)
{
	VappSyncApp *app = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getApp(), VappSyncApp);

	if (app != NULL)
	{
		app->showSyncNow(SRV_SYNC_PHONE, index, NULL);
	}
}

void VappSyncPhoneAccntListPage::viewLog(const VfxS32 &index)
{
	VappSyncPhoneLogPage *logPage;
	
	VFX_OBJ_CREATE_EX(logPage, VappSyncPhoneLogPage, this, (index));
	getMainScr()->pushPage(VFX_ID_NULL, logPage);

}

VfxS32 VappSyncPhoneAccntListPage::locateAccntIndex(VfxBool &isNew, void *btAddr)
{
	VfxS32 accntIdx = -1, oldestIdx = 0, firstSlot = -1;
	VfxU32 oldTimestamp = 0xFFFFFFFF;
	MMI_BOOL ret;

	nvram_ef_syncml_device_accnt_struct *accnt;
	srv_bt_cm_bt_addr *addr = (srv_bt_cm_bt_addr *)btAddr;

	//VFX_SYS_ALLOC_MEM(accnt, sizeof(nvram_ef_syncml_device_accnt_struct));
	accnt = (nvram_ef_syncml_device_accnt_struct *)OslMalloc(sizeof(nvram_ef_syncml_device_accnt_struct));
	// find in the current accnt
	for (VfxU32 i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		ret = srv_sync_read_accnt_buffer(accnt, 
										 sizeof(nvram_ef_syncml_device_accnt_struct),
										 SRV_SYNC_PHONE, 
										 i);
		MMI_ASSERT(ret);
	
		if (accnt->timestamp < oldTimestamp)
		{
			oldestIdx = i;
			oldTimestamp = accnt->timestamp;
		}

		if (accnt->timestamp == 0)
		{
			if (firstSlot < 0)
			{
				firstSlot = i;
			}

			continue;
		}
		
		if (accnt->dev_bt_addr.lap == addr->lap &&
			accnt->dev_bt_addr.uap == addr->uap &&
			accnt->dev_bt_addr.nap == addr->nap)
		{
			accntIdx = i;
			break;
		}
	}

	OslMfree(accnt);
	
	isNew = VFX_FALSE;
	
	if (accntIdx < 0)
	{
		isNew = VFX_TRUE;
		// find the fist empty slot
		if (firstSlot >= 0)
		{
			accntIdx = firstSlot;
		}
		// if no empty slot, then replace the oldest one
		else
		{
			accntIdx = oldestIdx;
		}
	}

	VAPP_SYNC_LOG4(MMI_SYNC_PHONE_FIND_ACCNT, isNew, accntIdx, firstSlot, oldestIdx);
	
	return accntIdx;
}

/*
  *copy from MMI_BOOL mmi_bt_is_dev_cod_match(U32 device_cod, U32 specific_cod) 
  *	in BTMMIScr.c 
  */
VfxBool VappSyncPhoneAccntListPage::isCodMatch(const VfxU32 &device_cod, const VfxU32 &specific_cod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool match = VFX_FALSE;
    VfxU32 major_service = 0, major_device = 0, minor_device = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (specific_cod == 0xFFFFFFFF)
    {
        match = VFX_TRUE;
    }
	//#define MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK                            (0x000000)
    else if (specific_cod == 0x000000)
    {
        match = VFX_TRUE;
    }
    else
    {
        major_service = 0x00FFE000 & specific_cod;
        major_device = 0x00001F00 & specific_cod;
        minor_device = 0x000000FC & specific_cod;
        if ((major_service & device_cod) != 0)
        {
            if ((major_device == 0) && (minor_device == 0))
            {
                match = VFX_TRUE;
            }
            else if (((device_cod & 0x1F00) == major_device) && ((minor_device == 0) || ((device_cod & 0xFF) == minor_device)))
            {
                match = VFX_TRUE;
            }
        }
    }
	
    return match;
}

