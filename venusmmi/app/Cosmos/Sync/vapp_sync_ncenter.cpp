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
*  vapp_sync_ncenter.cpp
*
* Project:
* --------
*  Venus
*
* Description:
* ------------
*  Fancy alarm ap.
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "GlobalResDef.h"
#include "common_nvram_editor_data_item.h"

extern "C"
{
#include "SyncSrvGprot.h"
#include "BtcmSrvGprot.h"
#include "gui_typedef.h"
#include "Wgui_categories_util.h"
#include "app_datetime.h"
}


#include "mmi_rp_srv_status_icons_def.h"
#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "vfx_app.h"
#include "vfx_app_launcher.h"
#include "vcp_global_popup.h"

#include "vapp_sync_gprot.h"
#include "vapp_sync.h"
#include "vapp_sync_ncenter.h"
/*********************************/


//#include "vapp_platform_context.h"

/****************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
VfxU16 VappSyncNCenterMngr::m_regular = 0;
VfxU16 VappSyncNCenterMngr::m_sync[NOTIFY_TYPE_TOTAL] = {SRV_SYNC_TOTAL, SRV_SYNC_TOTAL, SRV_SYNC_TOTAL};
VfxS32 VappSyncNCenterMngr::m_popHdl = GRP_ID_INVALID;  
VfxU8  VappSyncNCenterMngr::m_accntIdx[NOTIFY_TYPE_TOTAL] = {0xFF, 0xFF, 0xFF};
VfxBool VappSyncNCenterMngr::m_noti_exist[NOTIFY_TYPE_TOTAL] = {VFX_FALSE, VFX_FALSE, VFX_FALSE};
VfxU32 VappSyncNCenterMngr::m_timeStamp[NOTIFY_TYPE_TOTAL] = {0, 0, 0};

extern "C"

mmi_ret vapp_sync_on_notification(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	VFX_ASSERT(evt != NULL);
	switch (evt->evt_id)
	{
	case EVT_ID_SRV_SYNC_FINISH:
		VappSyncNCenterMngr::onSyncFinish(evt); // for ongoing and unfinished cell
		break;

	case EVT_ID_SRV_SYNC_ACCNT_OP:
		VappSyncNCenterMngr::onAccntOp(evt);// regular and unfinished cell
		break;
	case EVT_ID_SRV_SYNC_ASK_SYNC:
		VappSyncNCenterMngr::onSyncAsk(evt); // for regular cell
		break;
	default:
		break;
	}	

	return MMI_RET_OK;
}


mmi_ret VappSyncNCenterMngr::onAccntOp(mmi_event_struct *evt) // regular and unfinished cell
{
	srv_sync_accnt_op_evt_struct *opEvt = (srv_sync_accnt_op_evt_struct *)evt;
	if (opEvt->operation == SRV_SYNC_ACCNT_OP_DEL || opEvt->clear)
	{
		wgui_status_icon_bar_hide_icon(STATUS_ICON_SYNCML_ERROR);
	}

	VsrvNCenter *nmInst = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
	
	VsrvNotification *noti = nmInst->queryNotification(VAPP_SYNC, ID_NOTI_UNFINISHED);
	if (noti != NULL)
	{
		updateUnfinishSyncNoti(noti, evt);
	}

	noti = nmInst->queryNotification(VAPP_SYNC, ID_NOTI_REGULAR);
	if (noti != NULL)
	{
		updateRegularSyncNoti(noti, evt);
	}
	
	return MMI_RET_OK;
}


void VappSyncNCenterMngr::updateUnfinishSyncNoti(VsrvNotification *noti, mmi_event_struct *evt)
{
	srv_sync_accnt_op_evt_struct *opEvt = (srv_sync_accnt_op_evt_struct *)evt;

	if (opEvt->index == m_accntIdx[NOTIFY_TYPE_UNFINISHED] &&
		opEvt->sync == m_sync[NOTIFY_TYPE_UNFINISHED])
	{
		if (opEvt->operation == SRV_SYNC_ACCNT_OP_DEL || opEvt->clear)
		{
			VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_SYNC, ID_NOTI_UNFINISHED);
			reset(NOTIFY_TYPE_UNFINISHED);
		}
		else
		{
			VfxWString subStr;
			void *accnt = srv_sync_read_accnt((srv_sync_enum)m_sync[NOTIFY_TYPE_UNFINISHED], m_accntIdx[NOTIFY_TYPE_UNFINISHED]);
			getAccntName(subStr, accnt, (srv_sync_enum)m_sync[NOTIFY_TYPE_UNFINISHED]);
			
			VsrvNotificationEvent *eventNoti = (VsrvNotificationEvent *)noti;
			eventNoti->setSubText(subStr);
			eventNoti->notify();
		}

	}

}


void VappSyncNCenterMngr::updateRegularSyncNoti(VsrvNotification *noti, mmi_event_struct *evt)
{
	srv_sync_accnt_op_evt_struct *opEvt = (srv_sync_accnt_op_evt_struct *)evt;

	if (opEvt->index == m_accntIdx[NOTIFY_TYPE_REGULAR] && opEvt->sync == SRV_SYNC_REMOTE)
	{
		if(opEvt->operation == SRV_SYNC_ACCNT_OP_DEL || 
			opEvt->operation == SRV_SYNC_ACCNT_OP_MODIFY)
		{
			nvram_ef_syncml_account_struct *accnt;

			VFX_SYS_ALLOC_MEM(accnt, sizeof(nvram_ef_syncml_account_struct));

			MMI_BOOL ret = srv_sync_read_accnt_buffer(accnt, 
				sizeof(nvram_ef_syncml_account_struct), 
				SRV_SYNC_REMOTE, 
				m_accntIdx[NOTIFY_TYPE_REGULAR]);

			if (ret && accnt->regular_sync != m_regular)
			{	
				VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_SYNC, ID_NOTI_REGULAR);

				reset(NOTIFY_TYPE_REGULAR); 		
				srv_sync_check_regular_sync();
			}
			else
			{
				VfxWString subStr;
				void *accnt = srv_sync_read_accnt(SRV_SYNC_REMOTE, m_accntIdx[NOTIFY_TYPE_REGULAR]);
				nvram_ef_syncml_account_struct *rmtAccnt = (nvram_ef_syncml_account_struct *)accnt;
				subStr = VFX_WSTR_MEM((const VfxWChar *)rmtAccnt->account_name);

				VsrvNotificationEvent *eventNoti = (VsrvNotificationEvent *)noti;
				eventNoti->setSubText(subStr);								
				eventNoti->notify();		
			}
			
			VFX_SYS_FREE_MEM(accnt);
		}
	}
}


mmi_ret VappSyncNCenterMngr::onSyncFinish(mmi_event_struct *evt) // for ongoing and unfinished cell
{

	srv_sync_finish_evt_struct *finishEvt = (srv_sync_finish_evt_struct *)evt;

	VfxApp *app = VfxAppLauncher::findApp(
		VAPP_SYNC,
		VFX_OBJ_CLASS_INFO(VappSyncApp), 
		VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

	if (app == NULL)
	{
		VfxResId resId = VAPP_SYNC_GEN_PS_ERROR_STR(finishEvt->result);

		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(resId));

	}

	if (finishEvt->result != SRV_SYNC_OK)
	{
		//
		// Skip invalid sync, which maybe from error sync flow.
		//
		if (finishEvt->sync > SRV_SYNC_PHONE)
		{
			return MMI_RET_ERR;
		}
		
		m_timeStamp[NOTIFY_TYPE_UNFINISHED] = srv_sync_get_current_time();			
		m_sync[NOTIFY_TYPE_UNFINISHED] = (VfxU16)finishEvt->sync;
		m_accntIdx[NOTIFY_TYPE_UNFINISHED] = finishEvt->accnt_index;

		VfxWString subStr;
		void *accnt = srv_sync_read_accnt((srv_sync_enum)m_sync[NOTIFY_TYPE_UNFINISHED], m_accntIdx[NOTIFY_TYPE_UNFINISHED]);

		getAccntName(subStr, accnt, (srv_sync_enum)m_sync[NOTIFY_TYPE_UNFINISHED]);

		VsrvNCenter *nmInst = VFX_OBJ_GET_INSTANCE(VsrvNCenter);		
		VsrvNotification *noti = nmInst->queryNotification(VAPP_SYNC, ID_NOTI_UNFINISHED);
		VsrvNotificationEvent *eventNoti;
		if (noti == NULL)
		{
			m_noti_exist[NOTIFY_TYPE_UNFINISHED] = VFX_TRUE; 	
			VsrvNGroupSingleTitle *group;
			VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_SYNC));
			group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC));
			
			VSRV_NOTIFICATION_CREATE_EX(eventNoti, VsrvNotificationEvent,((VsrvNGroup*) group, ID_NOTI_UNFINISHED));
			eventNoti->setIntentCallback((VsrvNitentFuncptr)unfinishIntentCallback, NULL, 0);

			eventNoti->setMainText( VFX_WSTR_RES(STR_ID_VAPP_SYNC_UNFINISH));
			eventNoti->setIcon(VfxImageSrc(IMG_ID_VAPP_STATUS_SYNC_ERROR));
		}
		else
		{
			eventNoti = (VsrvNotificationEvent *)noti;	
		}
		
		eventNoti->setSubText(subStr);
		
		applib_time_struct outTime;
		applib_dt_utc_sec_2_mytime(m_timeStamp[NOTIFY_TYPE_UNFINISHED], &outTime, KAL_FALSE);
		VfxDateTime dateTime;
		dateTime.setDateTime(&outTime);
		eventNoti->setTimeStamp(dateTime);

		eventNoti->notify();

		wgui_status_icon_bar_show_icon(STATUS_ICON_SYNCML_ERROR);
	}
	else 
	{
		if (m_sync[NOTIFY_TYPE_UNFINISHED] == finishEvt->sync && 
			m_accntIdx[NOTIFY_TYPE_UNFINISHED] == finishEvt->accnt_index)
		{
			if (m_noti_exist[NOTIFY_TYPE_UNFINISHED])
			{
				m_noti_exist[NOTIFY_TYPE_UNFINISHED]= VFX_FALSE;
				VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_SYNC, ID_NOTI_UNFINISHED);
			}
			
			reset(NOTIFY_TYPE_UNFINISHED);
			wgui_status_icon_bar_hide_icon(STATUS_ICON_SYNCML_ERROR);
		}
	}

	return MMI_RET_OK;

}

mmi_ret VappSyncNCenterMngr::onSyncAsk(mmi_event_struct *evt) // for regular cell
{
	srv_sync_ask_sync_evt_struct *askEvt = (srv_sync_ask_sync_evt_struct *)evt;

	if (askEvt->sync != SRV_SYNC_REMOTE ||
		askEvt->regular == SRV_SYNC_REGULAR_NEVER ||
		m_accntIdx[NOTIFY_TYPE_REGULAR] != 0xFF)
	{
		return MMI_RET_OK;
	}

	m_timeStamp[NOTIFY_TYPE_REGULAR] = askEvt->notify_timestamp;
	m_regular = askEvt->regular;
	m_accntIdx[NOTIFY_TYPE_REGULAR] = askEvt->accnt_index;	
	VfxWString subStr;	
	nvram_ef_syncml_account_struct *accnt;
	VFX_SYS_ALLOC_MEM(accnt,sizeof(nvram_ef_syncml_account_struct));
	MMI_BOOL ret = srv_sync_read_accnt_buffer(accnt, 
		sizeof(nvram_ef_syncml_account_struct), 
		SRV_SYNC_REMOTE, 
		m_accntIdx[NOTIFY_TYPE_REGULAR]);
	if (ret)
	{
		subStr = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name); 
	}

	VFX_SYS_FREE_MEM(accnt);

	VsrvNGroupSingleTitle *group = NULL;
	VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_SYNC));
	group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC)); 

	VsrvNotificationEvent *noti = NULL;
	VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent,((VsrvNGroup*) group, ID_NOTI_REGULAR));
	noti->setIntentCallback((VsrvNitentFuncptr)askSyncIntentCallback, NULL, 0);

	noti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_SYNC));
	noti->setIcon(VfxImageSrc(IMG_ID_VAPP_SYNC_NMGR_REGULAR));  
	noti->setSubText(subStr);
	applib_time_struct outTime;
	applib_dt_utc_sec_2_mytime(m_timeStamp[NOTIFY_TYPE_REGULAR], &outTime, KAL_FALSE);

	VfxDateTime dateTime;
	dateTime.setDateTime(&outTime);
	noti->setTimeStamp(dateTime);
	noti->notify();

	m_noti_exist[NOTIFY_TYPE_REGULAR] = VFX_TRUE;	
	return MMI_RET_OK;
}

void VappSyncNCenterMngr::closeCurrApp(void)
{
	VfxApp *app = VfxAppLauncher::findApp(VAPP_SYNC, VFX_OBJ_CLASS_INFO(VappSyncApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
	if (app != NULL)
	{
		VfxAppLauncher::terminate(app->getGroupId());
	}	
}


void VappSyncNCenterMngr::onConfirmCallback(VfxId id, void *userData)
{
	//VappSyncNCenterRegularCell *nCell = (VappSyncNCenterRegularCell *)userData;

	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		VfxApp *app = VfxAppLauncher::findApp(VAPP_SYNC, VFX_OBJ_CLASS_INFO(VappSyncApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
		if (app != NULL)
		{
			VfxAppLauncher::terminate(app->getGroupId());
		}

		startSync();
	}

	// ask for next regular sync.
	nextSync();
}



/***************************************************************************** 
* Function
*****************************************************************************/
void VappSyncNCenterMngr::unfinishIntentCallback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{ 
	if (!m_noti_exist[NOTIFY_TYPE_UNFINISHED])
	{
		return;
	}
	
	if (VSRV_NINTENT_TYPE_CLEAR == intent.type || VSRV_NINTENT_TYPE_CLOSE == intent.type)
	{
		reset(NOTIFY_TYPE_UNFINISHED);
		wgui_status_icon_bar_hide_icon(STATUS_ICON_SYNCML_ERROR);
		return;
	}
	
	if (srv_sync_is_synchronizing())
	{

		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_SYNC_PLEASE_WAIT));

		return;
	}

	VfxS16 errCode;
	VfxU8 currTab = (m_sync[NOTIFY_TYPE_UNFINISHED] == SRV_SYNC_REMOTE) ? 0 : 1;
	
	WriteValue(NVRAM_EF_VAPP_SYNC_LAST_TAB, &currTab, DS_BYTE, &errCode);	
		
	closeCurrApp();
	vapp_sync_launch(NULL, 0);	
	reset(NOTIFY_TYPE_UNFINISHED);	
	vsrv_ncenter_close_notification(nhandle);

	wgui_status_icon_bar_hide_icon(STATUS_ICON_SYNCML_ERROR);
}


void VappSyncNCenterMngr::askSyncIntentCallback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
	if (!m_noti_exist[NOTIFY_TYPE_REGULAR])
	{
		return;
	}
	
	if (VSRV_NINTENT_TYPE_CLEAR == intent.type|| VSRV_NINTENT_TYPE_CLOSE == intent.type)
	{
		reset(NOTIFY_TYPE_REGULAR);
		return;
	}
	
	if (srv_sync_is_synchronizing())
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_SYNC_PLEASE_WAIT));

		return;
	}
	nvram_ef_syncml_account_struct *accnt;
	VfxWString accnt_str;
	VFX_SYS_ALLOC_MEM(accnt,sizeof(nvram_ef_syncml_account_struct));
	MMI_BOOL ret = srv_sync_read_accnt_buffer(accnt, 
		sizeof(nvram_ef_syncml_account_struct), 
		SRV_SYNC_REMOTE, 
		m_accntIdx[NOTIFY_TYPE_REGULAR]);

	
	if (ret)
	{
		accnt_str = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name); 
	}

	VFX_FREE_MEM(accnt);	 
	VfxWString strAsk = VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_ASK);
	strAsk += accnt_str;
	strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_ASK_RIGHT);

	m_popHdl = vcp_global_popup_show_confirm_two_button_str(
		GRP_ID_ROOT,
		VCP_POPUP_TYPE_QUESTION,
		strAsk,
		VFX_WSTR_RES(STR_GLOBAL_YES),
		VFX_WSTR_RES(STR_GLOBAL_NO),
		VCP_POPUP_BUTTON_TYPE_NORMAL,
		VCP_POPUP_BUTTON_TYPE_CANCEL,
		&onConfirmCallback,
		NULL);

	m_noti_exist[NOTIFY_TYPE_REGULAR] = VFX_FALSE;
}


void VappSyncNCenterMngr::startSync(void)
{	
	srv_sync_ret_enum ret = srv_sync_start(SRV_SYNC_REMOTE, m_accntIdx[NOTIFY_TYPE_REGULAR], 0, NULL);

	// Only remote sync has regular sync
	if (ret != SRV_SYNC_RET_OK)
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(VAPP_SYNC_GEN_ERROR_STR(ret)));

		return;
	}

	vapp_sync_launch(NULL, 0);
}

void VappSyncNCenterMngr::nextSync(void)
{
	U8 idx = m_accntIdx[NOTIFY_TYPE_REGULAR];
	srv_sync_finish_regular_sync(idx);

	reset(NOTIFY_TYPE_REGULAR);
}

void VappSyncNCenterMngr::reset(VfxU8 noti_type)
{
	m_noti_exist[noti_type] = VFX_FALSE;
	m_sync[noti_type] = SRV_SYNC_TOTAL;
	m_accntIdx[noti_type] = 0xFF;

	if ((noti_type == NOTIFY_TYPE_ONGOING) && (m_popHdl != GRP_ID_INVALID))
	{
		vcp_global_popup_cancel(m_popHdl);
		m_popHdl = GRP_ID_INVALID;
	}
}

void VappSyncNCenterMngr::getAccntName(VfxWString &str, void *accnt, srv_sync_enum sync)
{
	VFX_ASSERT(accnt != NULL);
	
	if (SRV_SYNC_REMOTE == sync)
	{
		nvram_ef_syncml_account_struct *rmtAccnt = (nvram_ef_syncml_account_struct *)accnt;

		str.loadFromMem((const VfxWChar *)rmtAccnt->account_name);
	}
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	else
	{
		nvram_ef_syncml_device_accnt_struct *phnAccnt = (nvram_ef_syncml_device_accnt_struct *)accnt;
		VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];

		srv_bt_cm_get_dev_ucs2_name((srv_bt_cm_bt_addr *)&phnAccnt->dev_bt_addr, 
			SRV_BT_CM_BD_UCS2_NAME_LEN,
			(WCHAR *)ucs2_buff);
		
		str.loadFromMem((const VfxWChar *)ucs2_buff);
	}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */	

}

