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
 *  vapp_sync_now.cpp
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

#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "BtcmSrvGprot.h"
#include "SyncSrvGprot.h"

#include "vcp_status_icon_bar.h"

#include "vapp_dtcnt_gprot.h"
#include "vapp_sync.h"
#include "vapp_sync_now.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"

mmi_ret vapp_sync_on_sync_ask(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	return MMI_RET_OK;
}

/***************************************************************************** 
 * VappSyncNowProgPopup
 *****************************************************************************/
VfxBool VappSyncNowProgPopup::onKeyInput(VfxKeyEvent &event)
{
	if (m_bDisable)
	{
		return VFX_TRUE;
	}

	return VcpIndicatorPopup::onKeyInput(event);
}

void VappSyncNowProgPopup::disableButton(void)
{
	m_bDisable = VFX_TRUE;
	m_button->setIsDisabled(VFX_TRUE);
}

void VappSyncNowProgPopup::setProcessText(const VfxWString &accntName, const VfxWString &text)
{
	if (!m_bDisable)
	{
		VfxWString popStr = accntName;

		VfxSize size = m_textFrame->getFont().measureStr(accntName);
		// width of every char.
		VfxU32 charWidth;
		if (accntName.getLength() != 0)
		{
			charWidth = size.width / accntName.getLength();
		}
		else
		{
			charWidth = 1;
		}
		
		VfxU32 txtLen = VCP_INDICATOR_POPUP_CONTENT_WIDTH - (3 * charWidth);
		
		if (size.width > txtLen)
		{
			popStr.lockBuf(txtLen/charWidth);
			popStr.unlockBuf();

			popStr += VFX_WSTR("...");
		}

		popStr += VFX_WSTR("\n");
		popStr += text;
		
		setText(popStr);
	}
}


/***************************************************************************** 
 * VappSyncNowScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncNowScr", VappSyncNowScr, VfxAppScr);

/***************************************************************************** 
 * static function
 *****************************************************************************/
mmi_ret VappSyncNowScr::onSyncEvt(mmi_event_struct *evt)
{
	VFX_ASSERT(evt != NULL);
	
	VappSyncNowScr *thiz = (VappSyncNowScr *)handleToObject((VfxObjHandle)evt->user_data);
	
	if (thiz != NULL)
	{
		return thiz->onSrvEvt(evt);
	}
	
	return MMI_RET_OK;
}


/***************************************************************************** 
 * Local function
 *****************************************************************************/
VappSyncNowScr::VappSyncNowScr()
	: m_syncPopupWeakPtr(NULL),
	  m_sync(SRV_SYNC_TOTAL),
	  m_index(-1),
	  m_data(NULL)
{
	setIsSmallScreen();
}

VappSyncNowScr::VappSyncNowScr(const VfxU16 &sync, const VfxS32 &index, const void* usr_data)
	: m_sync(sync),
	  m_index(index),
	  m_data(usr_data)
{
	setIsSmallScreen();
}

// simulator evet from service
void VappSyncNowScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
	VfxRenderer* renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	param.rotateTo = renderer->getPreScreenRotateType();
}

void VappSyncNowScr::onRotate(const VfxScreenRotateParam & param)
{
    VfxAppScr::onRotate(param);
	if(m_statusBar)
	{
	    m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
	}
}
void VappSyncNowScr::onInit(void)
{
	VfxAppScr::onInit();

	// status bar need to be updated during alarm
	VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
	m_statusBar->setAutoAnimate(VFX_TRUE);
	m_statusBar->setPos(0, 0);
	VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	m_direction = renderer->getPreScreenRotateType();

	createIndPopup();	
	regEvtHdlr();
}
void VappSyncNowScr::onDeinit(void)
{
	deregEvtHdlr();
	
	if (srv_sync_is_synchronizing())
	{
		mmi_event_struct evt;

		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SYNC_BG_START);

		MMI_FRM_CB_EMIT_POST_EVENT(&evt);
	}
	
	VfxAppScr::onDeinit();
}

void VappSyncNowScr::createIndPopup(void)
{
	VappSyncNowProgPopup *indPopup;
	
	VFX_OBJ_CREATE(indPopup, VappSyncNowProgPopup, this);
	indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
	indPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_SYNCHRONIZING));
	indPopup->m_signalCanceled.connect(this, &VappSyncNowScr::onCancel);
	indPopup->setAutoDestory(VFX_FALSE);

	m_syncPopupWeakPtr = indPopup;
}

void VappSyncNowScr::onEnter(VfxBool isBackward)
{
	VfxAppScr::onEnter(isBackward);

    if (m_statusBar != NULL)
	{
		m_statusBar->setSize(getSize().width, MMI_STATUS_BAR_HEIGHT);
    }

	if (m_syncPopupWeakPtr.isValid())
	{
		VappSyncNowProgPopup *indPop = m_syncPopupWeakPtr.get();
		indPop->show(VFX_TRUE);
	}

	// background sync.
	if (srv_sync_is_synchronizing())
	{
		return;
	}
	
	srv_sync_ret_enum ret;
	
	ret = srv_sync_start((srv_sync_enum)m_sync, 
						 (VfxU8)m_index, 
						 0,
						 (void*)m_data);
	
	if (ret != SRV_SYNC_RET_OK)
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(VAPP_SYNC_GEN_ERROR_STR(ret)));
		
		exit();
	}
}

void VappSyncNowScr::onBack()
{
	onCancel(NULL, 0);
}

void VappSyncNowScr::onCancel(VfxObject* obj, VfxFloat id)
{
	if (m_syncPopupWeakPtr.isValid())
	{
		VappSyncNowProgPopup *indPop = m_syncPopupWeakPtr.get();
		indPop->setText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_CANCELLING));
		indPop->disableButton();
		indPop->show(VFX_FALSE);
	}

	srv_sync_abort((srv_sync_enum)m_sync);
}

mmi_ret VappSyncNowScr::onFinish(mmi_event_struct *evt)
{
	srv_sync_finish_evt_struct *finishEvt = (srv_sync_finish_evt_struct *)evt;

	VfxResId resId = VAPP_SYNC_GEN_PS_ERROR_STR(finishEvt->result);
		
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
		MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
		(WCHAR *)GetString(resId));

	VappSyncApp *selfApp = VFX_OBJ_DYNAMIC_CAST(getApp(), VappSyncApp);

	if (selfApp != NULL && selfApp->needClose())
{
		selfApp->continueSyncClose();
	}
	else
	{
		exit();	
	}

	return MMI_RET_OK;
}


mmi_ret VappSyncNowScr::onProgress(mmi_event_struct *evt)
{
	srv_sync_progress_evt_struct *progEvt = (srv_sync_progress_evt_struct *)evt;

	if (m_syncPopupWeakPtr.isValid())
	{
		VappSyncNowProgPopup *indPop = m_syncPopupWeakPtr.get();

		VfxResId leftResId, rightResId;

		if (progEvt->action == SRV_SYNC_ACTION_SEND)
		{
			leftResId = STR_ID_VAPP_SYNC_SENDING;
			rightResId = STR_ID_VAPP_SYNC_SENDING_RIGHT;
		}
		else
		{
			leftResId = STR_ID_VAPP_SYNC_RECEIVING;
			rightResId = STR_ID_VAPP_SYNC_RECEIVING_RIGHT;
		}

		VfxWString infoStr = VFX_WSTR_RES(leftResId);
		infoStr += VFX_WSTR_RES(VAPP_SYNC_GET_DB_RESID(progEvt->db_id));
		infoStr += VFX_WSTR_RES(rightResId);		
		
		VfxWString progStr;

		if (progEvt->total != 0)
		{
		    progStr.format(" (%d/%d)", progEvt->curr, progEvt->total);
		}
		else
		{
			progStr.format(" (%d)", progEvt->curr);
		}

		infoStr += VFX_WSTR("\n");
		infoStr += progStr;
		
		indPop->setProcessText(getAccntName(), infoStr);
	}
	
	return MMI_RET_OK;
}

VfxWString VappSyncNowScr::getAccntName(void) const
{
	VfxWString strAccnt = VFX_WSTR_NULL;
	
	if (m_sync == SRV_SYNC_REMOTE)
	{
		nvram_ef_syncml_account_struct *accnt;
		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_index);
		strAccnt = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);
	}
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
	else
	{
		nvram_ef_syncml_device_accnt_struct *devAccnt;
		devAccnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, m_index);
		
		VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];
		srv_bt_cm_get_dev_ucs2_name((srv_bt_cm_bt_addr *)&devAccnt->dev_bt_addr, SRV_BT_CM_BD_UCS2_NAME_LEN, (WCHAR *)ucs2_buff);
		
		strAccnt = VFX_WSTR_MEM(ucs2_buff);
	}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

	return strAccnt;
}

void VappSyncNowScr::regEvtHdlr(void)
{
	mmi_frm_cb_reg_event(EVT_ID_SRV_SYNC_PROGRESS, VappSyncNowScr::onSyncEvt, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_SRV_SYNC_FINISH, VappSyncNowScr::onSyncEvt, getObjHandle());
}

void VappSyncNowScr::deregEvtHdlr(void)
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SYNC_PROGRESS, VappSyncNowScr::onSyncEvt, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SYNC_FINISH, VappSyncNowScr::onSyncEvt, getObjHandle());
}

mmi_ret VappSyncNowScr::onSrvEvt(mmi_event_struct *evt)
{
	mmi_ret ret = MMI_RET_OK;
	
	switch (evt->evt_id)
	{
		case EVT_ID_SRV_SYNC_FINISH:
			ret = onFinish(evt);
			break;
			
		case EVT_ID_SRV_SYNC_PROGRESS:
			ret = onProgress(evt);
			break;
			
		default:
			break;
	}
	
	return ret;
}


