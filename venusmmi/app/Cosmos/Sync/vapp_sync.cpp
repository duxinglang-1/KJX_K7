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
 *  vapp_sync.cpp
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

extern "C"
{
#include "ModeSwitchSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "SimCtrlSrvGprot.h"
}

#include "mmi2syncml_struct.h"
#include "mmi_rp_vapp_sync_def.h"

#include "vfx_app_launcher.h"

#include "vapp_sync_gprot.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_list.h"
#include "vapp_sync_log.h"
#include "vapp_sync_now.h"

#include "vapp_sync_remote_accnt_add.h"
#include "vapp_sync_remote_accnt_edit.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
mmi_id vcui_sync_remote_evt_hdlr(mmi_event_struct *evt);

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" mmi_id vapp_sync_launch(void* param, U32 param_size)
{
	mmi_id launch_id;
	
    launch_id = VfxAppLauncher::launch( 
        		VAPP_SYNC,
        		VFX_OBJ_CLASS_INFO(VappSyncApp),
        		GRP_ID_ROOT,
        		NULL,
        		0);

	return launch_id;
}


VfxS8 vapp_sync_is_synchronizing(void)
{
	if (srv_sync_is_synchronizing())
	{
		return 1;
	}

	return 0;
}

VfxS8 vapp_sync_is_contact_synchronizing(VfxS8 popup)
{
	VfxS8 ret = 0;
	
	if (srv_sync_is_db_synchronizing(SYNCML_DB_PHONEBOOK))
	{
		if (popup == 1)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_SYNC_CODE_FORBIDDEN));
		}
		// display popup
		ret = 1;
	}

	return ret;
}

VfxS8 vapp_sync_is_cal_synchronizing(VfxS8 popup)
{
	VfxS8 ret = 0;
	
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	if (srv_sync_is_db_synchronizing(SYNCML_DB_CALENDAR))
	{
		if (popup == 1)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_SYNC_CODE_FORBIDDEN));
		}

		ret = 1;
	}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

	return ret;

}
VfxS8 vapp_sync_is_task_synchronizing(VfxS8 popup)
{
	VfxS8 ret = 0;
	
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	if (srv_sync_is_db_synchronizing(SYNCML_DB_TASK))
	{
		if (popup == 1)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_SYNC_CODE_FORBIDDEN));
		}

		ret = 1;
	}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

	return ret;

}

VfxS8 vapp_sync_is_note_synchronizing(VfxS8 popup)
{
	VfxS8 ret = 0;
	
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	if (srv_sync_is_db_synchronizing(SYNCML_DB_NOTE))
	{
		if (popup == 1)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_SYNC_CODE_FORBIDDEN));
		}

		ret = 1;
	}
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

	return ret;

}

extern "C"
mmi_id vapp_sync_remote_evt_handlr(mmi_event_struct *evt)
{

#ifdef	__MMI_SYNCML_CCA_SUPPORT__
	vcui_sync_remote_evt_hdlr(evt);
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

	return MMI_RET_OK;
}

/***************************************************************************** 
 * VappSyncApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncApp", VappSyncApp, VfxApp);

VfxBool VappSyncApp::s_isConnection = VFX_FALSE;

const VfxU16 VappSyncApp::s_dbIdCode[VAPP_SYNC_TOTAL_DATABASE] = 
{
	SYNCML_DB_ID_CON,
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	SYNCML_DB_ID_CAL,
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	SYNCML_DB_ID_TASK,
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	SYNCML_DB_ID_NOTE,
#endif
};

const VfxResId VappSyncApp::s_strDatabaseName[SYNCML_DB_ID_TOTAL] = 
{
    STR_ID_VAPP_SYNC_CON,
    STR_ID_VAPP_SYNC_CAL,
    STR_ID_VAPP_SYNC_TASK,
    STR_ID_VAPP_SYNC_NOTE	
};

const VfxResId VappSyncApp::s_strDatabaseChkInvalid[SYNCML_DB_ID_TOTAL] =
{
	STR_ID_VAPP_SYNC_DB_INVALID_ADDR_CON,
	STR_ID_VAPP_SYNC_DB_INVALID_ADDR_CAL,
	STR_ID_VAPP_SYNC_DB_INVALID_ADDR_TASK,
	STR_ID_VAPP_SYNC_DB_INVALID_ADDR_NOTE,
};

const VfxId VappSyncApp::s_strDatabaseMask[SYNCML_DB_ID_TOTAL] = 
{
    SYNCML_DB_PHONEBOOK,
    SYNCML_DB_CALENDAR,
    SYNCML_DB_TASK,
    SYNCML_DB_NOTE	
};

const VfxChar *VappSyncApp::s_strDatabasePkgName[SYNCML_DB_ID_TOTAL] = 
{
	"native.mtk.contact",
	"native.mtk.calendar",
	"native.mtk.task",
	"native.mtk.note_dummy"
};

const VfxResId VappSyncApp::s_strErrorCode[SRV_SYNC_RET_TOAL] = 
{
	STR_ID_VAPP_SYNC_FINISHED,
	STR_ID_VAPP_SYNC_UNFINISH,	//SRV_SYNC_RET_FAIL
	STR_ID_VAPP_SYNC_UNFINISH,	//SRV_SYNC_RET_ERROR_INVALID_SYNC
	STR_ID_VAPP_SYNC_UNFINISH,	//SRV_SYNC_RET_ERROR_INVALID_ACCNT
	STR_ID_VAPP_SYNC_UNFINISH,	//SRV_SYNC_RET_ERROR_INVALID_DATABASE
	STR_ID_VAPP_SYNC_CODE_FORBIDDEN,	//SRV_SYNC_RET_ERROR_BUSY
	STR_ID_VAPP_SYNC_UNFINISH,	//SRV_SYNC_RET_ERROR_NO_SELECTED_DB
	STR_ID_VAPP_SYNC_PHB_BUSY,	//SRV_SYNC_RET_ERROR_DB_NOT_READY
	STR_GLOBAL_NOT_AVAILABLE,	//SRV_SYNC_RET_ERROR_WAP_NOT_READY
	STR_ID_VAPP_SYNC_UNFINISH,	//SRV_SYNC_RET_ERROR_INVALID_DATA_ACCOUNT
};


const VappSyncPsErrorCode VappSyncApp::s_psErrorCode[VAPP_SYNC_MAX_PS_ERROR] = 
{
	{SRV_SYNC_OK, 				  STR_ID_VAPP_SYNC_FINISHED},
	{SRV_SYNC_NOT_FOUND, 		  STR_ID_VAPP_SYNC_UNFINISH},
	{SRV_SYNC_FAIL, 			  STR_ID_VAPP_SYNC_UNFINISH},
	{SRV_SYNC_INVALID_CREDENTIAL, STR_ID_VAPP_SYNC_INVALID_CREDENTIAL},
	{SRV_SYNC_MISSING_CREDENTIAL, STR_ID_VAPP_SYNC_MISSING_CREDENTIAL},
	{SYNCML_LOCAL_DB_FULL, 		  STR_ID_VAPP_SYNC_LOCALDB_FULL},
	{SYNCML_ABORT_SYNC, 		  STR_ID_VAPP_SYNC_CANCELLED},
	{SRV_SYNC_PAYMENT_REQUIRED,   STR_ID_VAPP_SYNC_PAYMENT_REQUIRED},
	{SRV_SYNC_CODE_FORBIDDEN,	  STR_ID_VAPP_SYNC_CODE_FORBIDDEN},
	{SRV_SYNC_INCOMPLETE_CMD, 	  STR_ID_VAPP_SYNC_INCOMPLETE_CMD},
	{SRV_SYNC_DEVICE_FULL, 		  STR_ID_VAPP_SYNC_SVR_DEVICE_FULL},
	{SRV_SYNC_SERVICE_UNAVAILABLE,STR_ID_VAPP_SYNC_SERVICE_UNAVAILABLE},
	{SRV_SYNC_DATASTORE_FAIL, 	  STR_ID_VAPP_SYNC_DATASTORE_FAIL},
	{SRV_SYNC_SVR_FAIL, 		  STR_ID_VAPP_SYNC_SVR_FAIL},
	{SRV_SYNC_ERR_OCCUR, 		  STR_ID_VAPP_SYNC_ERR_OCCUR},
	{SRV_SYNC_PROTOCOL_UNSUPPORT, STR_ID_VAPP_SYNC_PROTOCOL_UNSUPPORT},
};


VfxResId VappSyncApp::getPsErrorStr(const VfxU32 &errCode)
{
	VfxResId resId = STR_ID_VAPP_SYNC_UNFINISH;// default error
	
	const VappSyncPsErrorCode *errPair;
	
	for (VfxU32 i = 0; i < VAPP_SYNC_MAX_PS_ERROR; i++)
	{
		 errPair = &(VappSyncApp::s_psErrorCode[i]);
		 if (errPair->errCode == errCode)
		 {
		 	resId = errPair->resId;
			break;
		 }
	}

	return resId;
}

VfxWString VappSyncApp::genDatabaseString(const VfxU32 &app)
{
	VfxWString strDB;
	VfxBool bFirst = VFX_TRUE;
	VfxU8 i = 0;
	
	do 
	{
		if (app & VAPP_SYNC_GET_DB_MASK(i))
		{
			if (!bFirst)
			{
				strDB += VFX_WSTR_RES(STR_ID_VAPP_SYNC_COMMA);
				strDB += VFX_WSTR_RES(STR_ID_VAPP_SYNC_SPACE);
			}
			
			strDB += VAPP_SYNC_GET_DB_NAME(i);

			bFirst = VFX_FALSE;
		}
		i++;
	} while (i < VAPP_SYNC_TOTAL_DATABASE);

	return strDB;
}

VfxBool VappSyncApp::isSyncAvailable(VfxBool isShowPopup)
{
	VfxResId resId = 0;

	// flight mode

	if (!srv_mode_switch_is_network_service_available())
	{
		#ifndef __OP01__
		resId = STR_GLOBAL_NOT_AVAILABLE;
		if (srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_INACTIVE)
		{
			resId = 0;
		}
		#else
		resId = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;
		#endif /* __OP01__ */
	}

	if (isShowPopup && (resId != 0))
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(resId));
	}
	
	return (resId == 0);
}

void VappSyncApp::showSyncNow(const VfxU16 &sync, const VfxS32 &index, const void *data)
{
	if (VappSyncApp::isConnection())
	{
		MMI_TRACE(TRACE_GROUP_2, MMI_SYNC_NOW_IS_CONNECTED);
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_SYNC_CODE_FORBIDDEN));
		
		return;
	}
	
	VappSyncNowScr *scr;
	VFX_OBJ_CREATE_EX(scr, VappSyncNowScr, this, (sync, index, data));
	if (scr != NULL)
	{
		m_syncScr = scr;
		m_activeScrId = scr->show();
	}
}

void VappSyncApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
	
	// for background sync
	if (srv_sync_is_synchronizing())
	{
		srv_sync_enum sync;
		VfxU8 index;

		MMI_ASSERT(srv_sync_active_sync_info(&sync, &index));		
		showSyncNow(sync, index, NULL);
	}
	else
	{
	VappSyncMainScr *scr;
	VFX_OBJ_CREATE(scr, VappSyncMainScr, this);
	if (scr != NULL)
	{
			m_activeScrId = scr->show();
	}
	
}
}

VfxAppCloseAnswerEnum VappSyncApp::onProcessClose(VfxAppCloseOption options)
{
	VfxAppCloseAnswerEnum ans = VFX_APP_CLOSE_ANSWER_YES;

	if (srv_sync_is_synchronizing())
	{
		if (!(options & VFX_APP_CLOSE_OPTION_BG_FLAG))
		{
			if (m_syncScr.isValid())
			{
				VappSyncNowScr *scr = m_syncScr.get();
				scr->abortSync();

				if (options & VFX_APP_CLOSE_OPTION_LATER_FLAG)
				{
				    m_isNeedClose = VFX_TRUE;
				    ans = VFX_APP_CLOSE_ANSWER_LATER;
				}
			}
		}
		//VFX_APP_CLOSE_OPTION_BG_FLAG means HomeKey		
		else
		{
			ans  = VFX_APP_CLOSE_ANSWER_NO;//VFX_APP_CLOSE_ANSWER_YES;
		}
	}
	
	return ans;
}

/***************************************************************************** 
 * VappSyncMainScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncMainScr", VappSyncMainScr, VfxMainScr);
void VappSyncMainScr::on1stReady(void)
{
	VfxMainScr::on1stReady();

	showPage(VAPP_SYNC_PAGE_ID_LIST, 0);
}

void VappSyncMainScr::showPage(VfxId pageId, VfxS32 data)
{
	VfxPage *page = NULL;
	
	switch (pageId)
	{
		case VAPP_SYNC_PAGE_ID_LIST:
		{
			VappSyncAccntListPage *listPage;
			VFX_OBJ_CREATE(listPage, VappSyncAccntListPage, this);
			page = listPage;
			break;
		}	
		case VAPP_SYNC_PAGE_ID_ADD_SERVER:
		{
			VappSyncRemoteAccntAddSrvPage *srvpage;
			VFX_OBJ_CREATE_EX(srvpage, VappSyncRemoteAccntAddSrvPage, this, (data));
			page = srvpage;
			break;
		}
		
		case VAPP_SYNC_PAGE_ID_ACCNT_EDIT:
		{
			VappSyncRemoteAccntEditPage *rmtEditPage;
			VFX_OBJ_CREATE_EX(rmtEditPage, VappSyncRemoteAccntEditPage, this, (data));
			page = rmtEditPage;
			break;
		}
		case VAPP_SYNC_PAGE_ID_LOG:
		{
			VappSyncLogPage *logPage;
			VFX_OBJ_CREATE_EX(logPage, VappSyncLogPage, this, (data));
			page = logPage;
			break;
		}
		
		default:
			break;
	}

	if (page != NULL)
	{
		pushPage(pageId, page);
	}
	
}


extern "C" 
{
	
#ifdef __MMI_SYNCML_CCA_SUPPORT__
	void mmi_syncml_proc_cca_doc(void *param)
	{
		srv_sync_ota_proc_cca_doc(param);
	}
	void mmi_syncml_construct_cca_document_for_dm(void* param)
	{
		srv_sync_ota_construct_cca_doc_for_dm(param);
	}
	void mmi_syncml_install_cca_document_from_dm(void *param)
	{
		srv_sync_ota_install_cca_doc_from_dm(param);
	}
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

}
