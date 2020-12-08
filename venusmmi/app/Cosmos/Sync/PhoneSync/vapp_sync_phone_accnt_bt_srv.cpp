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
#include "mmi2syncml_struct.h"
#include "mmi_rp_srv_sync_def.h"
#include "mmi_rp_vapp_sync_def.h"

extern "C"
{
	#include "AppMgrSrvGprot.h"
	#include "ReminderSrvGprot.h"
}

#include "SyncSrvGprot.h"

#include "vapp_platform_context.h" // for VappPlatformContext


#include "vcp_global_popup.h"
#include "vapp_sync_gprot.h"

#include "vapp_sync.h"
#include "vapp_sync_phone_accnt_list.h"
#include "vapp_sync_phone_accnt_bt_srv.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global function
 *****************************************************************************/
extern "C" U32 srv_sync_get_total_database_type(void);

extern "C" mmi_ret vapp_sync_phone_evt_handlr(mmi_event_struct *evt)
{
	
	MMI_TRACE(TRACE_GROUP_2, MMI_SYNC_PHONE_EVT_HDLR);
	
	switch (evt->evt_id)
	{
		case EVT_ID_SRV_SYNC_ASK_CONN:
			VappSyncPhoneBtServer::onConnAsk(evt);
			break;
			
		case EVT_ID_SRV_SYNC_ASK_SYNC:
			VappSyncPhoneAsk::onSyncAsk(evt);
			
			break;

		case EVT_ID_SRV_SYNC_CM:
			VappSyncPhoneBtServer::onCmEvt(evt);
			VappSyncPhoneAsk::onCmEvt(evt);
			break;
	}

	return MMI_RET_OK;
}

static VfxBool vapp_sync_phone_check_ready(void)
{
	MMI_ID inst;
	VfxU32 i;

	// check database
	for (i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		inst = srv_appmgr_query_instance_single_id(VAPP_SYNC_GET_DB_PKG_NAME(i));
		if (inst != GRP_ID_INVALID)
		{
			VAPP_SYNC_LOG1(MMI_SYNC_APP_LIVE, i);
			
			return VFX_FALSE;
		}
	}

	// check other app
	for (i = 0; i < 2; i++)
	{
		inst = srv_appmgr_query_instance_single_id(VappSyncPhoneBtServer::s_strOtherPkgName[i]);
		if (inst != GRP_ID_INVALID)
		{
			VAPP_SYNC_LOG1(MMI_SYNC_OTHER_APP_LIVE, i);
			return VFX_FALSE;
		}
	}
	

	// 1. every database must be ready.
	// 2. calendar & task reminder can't be active.
	if (!srv_sync_is_database_ready() ||
		(srv_reminder_get_expiry_type() == SRV_REMINDER_TYPE_CAL) ||
		(srv_reminder_get_expiry_type() == SRV_REMINDER_TYPE_TASK))
	{	
		return VFX_FALSE;
	}

	return VFX_TRUE;
}

/***************************************************************************** 
 * Class VappSyncPhoneBtServer
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncPhoneBtServer", VappSyncPhoneBtServer, VbtServer);
VappSyncPhoneBtServer * VappSyncPhoneBtServer::m_sInst = NULL;
const VfxChar *VappSyncPhoneBtServer::s_strOtherPkgName[2] = 
{
	"native.mtk.dialer",
	"native.mtk.calllog"
};

VappSyncPhoneBtServer::VappSyncPhoneBtServer() 
	: m_isStopping(VFX_FALSE)
{
	VappSyncPhoneBtServer::m_sInst = this;
}
VappSyncPhoneBtServer::~VappSyncPhoneBtServer()
{
	VappSyncPhoneBtServer::m_sInst = NULL; 
}

void VappSyncPhoneBtServer::onConnAsk(void *evt)
{
	if (vapp_sync_phone_check_ready())
	{
		srv_sync_ask_conn_evt_struct *conn_evt = (srv_sync_ask_conn_evt_struct *)evt;
		srv_bt_cm_bt_addr bt_addr;

		bt_addr.lap = conn_evt->lap;
		bt_addr.nap = conn_evt->nap;
		bt_addr.uap = conn_evt->uap;

		VFX_OBJ_CREATE(m_sInst, VappSyncPhoneBtServer, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
		VbtServerAgent::launchServer(m_sInst, &bt_addr);	 
	}
	else
	{
		srv_sync_answer(SRV_SYNC_ANSWER_REJECT);
	}
}

void VappSyncPhoneBtServer::onCmEvt(void *evt)
{
	srv_sync_cm_evt_struct *cmEvt = (srv_sync_cm_evt_struct*)evt;

	if (cmEvt->notify == SRV_SYNC_CM_NOTIFY_DISCONN)
	{
		VappSyncApp::setConnecting(VFX_FALSE);

		if (VappSyncPhoneBtServer::m_sInst != NULL)
		{
			VappSyncPhoneBtServer::m_sInst->closeAll();
		}
	}
}

void VappSyncPhoneBtServer::closeAll(void)
{
	m_isStopping = VFX_TRUE;
	srv_sync_answer(SRV_SYNC_ANSWER_REJECT);
	stop();
}

void VappSyncPhoneBtServer::onAuthorizeDone(VfxBool result)
{
	if (result)
	{
		srv_sync_answer(SRV_SYNC_ANSWER_ACCEPT);

		VappSyncApp::setConnecting(VFX_TRUE);

		stop();
	}
	else
	{
		if (!m_isStopping)
		{
			srv_sync_answer(SRV_SYNC_ANSWER_REJECT);
			m_isStopping = VFX_TRUE;

			stop();
		}
	}

	
}

void VappSyncPhoneBtServer::getDisplayText(VfxWString &text, srv_bt_cm_bt_addr *addr)
{
	text = VFX_WSTR_RES(STR_ID_VAPP_SYNC_CONN_ASK);
	
	VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];
	srv_bt_cm_get_dev_ucs2_name(addr, SRV_BT_CM_BD_UCS2_NAME_LEN, (WCHAR *)ucs2_buff);
	
	text += VFX_WSTR_MEM((const VfxWChar *)ucs2_buff);

	text += VFX_WSTR_RES(STR_ID_VAPP_SYNC_CONN_ASK_RIGHT);
}

/***************************************************************************** 
 * Class VappSyncPhoneAsk
 *****************************************************************************/
VfxS32 VappSyncPhoneAsk::s_hSync   = -1;
srv_bt_cm_bt_addr VappSyncPhoneAsk::s_devAddr = {0};

void VappSyncPhoneAsk::onSyncAsk(void *event)
{
	srv_sync_ask_sync_evt_struct *syncEvt = (srv_sync_ask_sync_evt_struct*)event;

	if (syncEvt->sync != SRV_SYNC_PHONE)
	{
		return;
	}
	
	if (vapp_sync_phone_check_ready())
	{
		VfxWString strAsk = VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCEPT_ASK);
		
		VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];

		s_devAddr.lap = syncEvt->lap;
		s_devAddr.nap = syncEvt->nap;
		s_devAddr.uap = syncEvt->uap;
		
		srv_bt_cm_get_dev_ucs2_name(&s_devAddr, SRV_BT_CM_BD_UCS2_NAME_LEN, (WCHAR *)ucs2_buff);
		
		strAsk += VFX_WSTR_MEM((const VfxWChar *)ucs2_buff);
		
		strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCEPT_ASK_RIGHT);
		
	    s_hSync = vcp_global_popup_show_confirm_two_button_str(
					GRP_ID_ROOT,
			        VCP_POPUP_TYPE_QUESTION,
			        strAsk,
			        VFX_WSTR_RES(STR_GLOBAL_YES),
			        VFX_WSTR_RES(STR_GLOBAL_NO),
			        VCP_POPUP_BUTTON_TYPE_NORMAL,
			        VCP_POPUP_BUTTON_TYPE_CANCEL,
			        VappSyncPhoneAsk::onConfirmCallback,
			        syncEvt->user_data);
	}
	else
	{
		srv_sync_answer(SRV_SYNC_ANSWER_REJECT);
	}
	
	VappSyncApp::setConnecting(VFX_FALSE);
}

void VappSyncPhoneAsk::onCmEvt(void *evt)
{
	srv_sync_cm_evt_struct *cmEvt = (srv_sync_cm_evt_struct*)evt;

	if (cmEvt->notify == SRV_SYNC_CM_NOTIFY_DISCONN)
	{
		if (s_hSync != -1)
		{
			vcp_global_popup_cancel(s_hSync);
		}
	}
}

void VappSyncPhoneAsk::onConfirmCallback(VfxId id, void *userData)
{
    switch (id)
    {
	    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
		{
			MMI_ID syncInst = srv_appmgr_query_instance_single_id("native.mtk.sync");
			
			if (syncInst != GRP_ID_INVALID)
			{
				srv_appmgr_close_app(syncInst);
			}

			srv_sync_answer(SRV_SYNC_ANSWER_ACCEPT);
			
			VappSyncPhoneAsk::startSync(userData);
			
	        break;
	    }
	    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
	    case VCP_POPUP_BUTTON_NO_PRESSED:
	        srv_sync_answer(SRV_SYNC_ANSWER_REJECT);
			
	        break;

	    default:
	        break;
    }

	s_hSync = -1;
}

void VappSyncPhoneAsk::startSync(void *usrData)
{
	VfxBool isNew = VFX_FALSE;
	
	S32 index = VappSyncPhoneAccntListPage::locateAccntIndex(isNew, &s_devAddr);

	if (isNew)
	{
		nvram_ef_syncml_device_accnt_struct *accnt;
		
		accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, index);
		memset(accnt, 0, sizeof(nvram_ef_syncml_device_accnt_struct));
		
		accnt->app_to_sync = srv_sync_get_total_database_type();
		memcpy(&accnt->dev_bt_addr, &s_devAddr, sizeof(srv_bt_cm_bt_addr));
		
		accnt->dev_bt_cod = srv_bt_cm_get_dev_cod(&s_devAddr);
		accnt->timestamp = srv_sync_get_current_time();
		accnt->report_status = 0;
		accnt->role = SYNCML_DS_CLIENT;

		srv_sync_write_accnt(SRV_SYNC_PHONE, accnt, index);
	}

	// for device B, also start sync at MMI.
	// 			   the database is determined by device A.
	srv_sync_ret_enum ret = srv_sync_start(SRV_SYNC_PHONE, index, 0, usrData);
	
	if (ret == SRV_SYNC_RET_OK)
	{
	    vapp_sync_launch(NULL, 0);
    }

}

