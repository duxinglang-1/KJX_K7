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
 *  vapp_sms_viewer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h" 
#include "vapp_sms_operator.h"
#include "vapp_msg_use_detail.h"
#include "vapp_uc_gprot.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "GlobalResDef.h"
#include "vcui_dialer_gprot.h"
#include "vapp_sim_setting_gprot.h"
#include "vapp_sms_util.h"

#ifdef __MMI_SMS_COMPOSER__
    #include "vcui_sms_composer_gprot.h"
#endif


#ifdef __cplusplus
extern "C"
#endif
{
	#include "SmsSrvGprot.h"
	#include "UcSrvGprot.h"
	#include "PhbSrvGprot.h"
    #include "UCMGProt.h"
	#include "SimCtrlSrvGProt.h"
#ifdef __MMI_USB_SUPPORT__
	#include "USBSrvGprot.h"
#endif /* __MMI_USB_SUPPORT__ */
	#include "ModeSwitchSrvGprot.h"
}


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
//VFX_IMPLEMENT_CLASS("VappSmsOperator", VappSmsOperator, VfxObject);

VappSmsOperator::VappSmsOperator() :
	m_smsProvider(NULL),
	m_parentPage(NULL),
	m_currOp(VAPP_SMS_OP_NONE),
	m_currCmdId(0xff),
	m_smsHandle(SRV_SMS_INVALID_HANDLE),
	m_indicatorPopup(NULL),
	m_isLiteMode(VFX_FALSE)
{
}

void VappSmsOperator::setParentPage(VfxPage* parentPage)
{
	m_parentPage = parentPage;
}

void VappSmsOperator::setProvider(VappSmsProvider* provider)
{
	m_smsProvider = provider;
}

void VappSmsOperator::setLiteMode(VfxBool mode)
{
    m_isLiteMode = mode;
}


void VappSmsOperator::Reply(void)
{
	entryUcEditor(VAPP_SMS_OP_REPLY);
}

void VappSmsOperator::forward(void)
{
    entryUcEditor(VAPP_SMS_OP_FORWARD);
}

void VappSmsOperator::edit(void)
{
	entryUcEditor(VAPP_SMS_OP_EDIT);
}

void VappSmsOperator::resend(void)
{
	if (m_smsProvider == NULL)
	{
		return;
	}

    srv_sms_sim_enum smsSimId = m_smsProvider->getSimID();
    mmi_sim_enum simId = SRV_SMS_SMS_SIM_TO_MMI(smsSimId);

    if (!showInfoBalloonIfNeed(simId))
    {
    	m_currOp = VAPP_SMS_OP_RESEND;

        srv_sms_set_unsent_msg_status_ext(
        	(U16)m_smsProvider->getMsgID(),
        	SRV_SMS_SEND_WAITING,
        	NULL,
            NULL);
    }
    
}

void VappSmsOperator::deleteMsg(void)
{
	m_currOp = VAPP_SMS_OP_DELETE;

	VcpConfirmPopup *confirmPopup;

    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_parentPage);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirmPopup->setText((VfxResId)STR_ID_VAPP_SMS_DEL_MSG_QUERY);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setCustomButton((VfxResId)STR_GLOBAL_DELETE , (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirmPopup->m_signalButtonClicked.connect(this, &VappSmsOperator::onPopupButtonClicked);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->show(VFX_TRUE);
}

void VappSmsOperator::copyFromPhone(void)
{
	m_currOp = VAPP_SMS_OP_COPY_FROM_PHONE;

//#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) || (MMI_MAX_SIM_NUM >= 2))
	VcpCommandPopup *copyToMenu;

	VFX_OBJ_CREATE(copyToMenu, VcpCommandPopup, m_parentPage);

	copyToMenu->m_signalButtonClicked.connect(this, &VappSmsOperator::onPopupButtonClicked);
	copyToMenu->setText((VfxResId)STR_ID_VAPP_SMS_COPY);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	copyToMenu->addItem(CMD_COPY_TO_ARCHIVE, (VfxResId)STR_ID_VAPP_SMS_TO_ARCHIVE);

	srv_sms_status_enum status;

	status = m_smsProvider->getStatus();

	if ((status & SRV_SMS_STATUS_UNSUPPORTED) ||
		(status & SRV_SMS_STATUS_UNSENT) ||
		(status & SRV_SMS_STATUS_DRAFT)
	#ifdef __MMI_USB_SUPPORT__
		|| srv_usb_is_in_mass_storage_mode()
	#endif
	   )
	{
		copyToMenu->disableItem(CMD_COPY_TO_ARCHIVE);
	}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	copyToMenu->addItem(CMD_COPY_TO_TCARD, (VfxResId)STR_ID_VAPP_SMS_TO_TCARD);
	VfxBool isMemoryCardAvailable = srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
	if (!isMemoryCardAvailable)
	{
		copyToMenu->disableItem(CMD_COPY_TO_TCARD);
	}


#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */


#if (MMI_MAX_SIM_NUM >= 2)
	copyToMenu->addItem(CMD_COPY_TO_SIM, STR_ID_VAPP_SMS_TO_SIM);
	if (!srv_sim_ctrl_get_num_of_inserted())
	{
		copyToMenu->disableItem(CMD_COPY_TO_SIM);
	}

#else
	copyToMenu->addItem(CMD_COPY_TO_SIM1, STR_ID_VAPP_SMS_TO_SIM);
	if (!srv_sim_ctrl_is_inserted(MMI_SIM1))
	{
		copyToMenu->disableItem(CMD_COPY_TO_SIM1);
	}
#endif

#if 0
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
	copyToMenu->addItem(CMD_CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
	copyToMenu->setAutoDestory(VFX_TRUE);
	copyToMenu->show(VFX_TRUE);

//#else /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) || (MMI_MAX_SIM_NUM >= 2)) */

	//m_currCmdId = CMD_COPY_TO_SIM1;

	//startOperation();
//#endif /* (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) || (MMI_MAX_SIM_NUM >= 2))) */
}

void VappSmsOperator::copyToPhone(void)
{
	m_currOp = VAPP_SMS_OP_COPY_TO_PHONE;
	m_currCmdId = CMD_COPY_TO_PHONE;

	startOperation();
}

void VappSmsOperator::copyFromArchive(void)
{
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	m_currOp = VAPP_SMS_OP_COPY_FROM_ARCHIVE;
	m_currCmdId = CMD_COPY_FROM_ARCHIVE;

	startOperation();
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
}


#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
void VappSmsOperator::copyFromTcard()
{
	m_currOp = VAPP_SMS_OP_COPY_FROM_TCARD;

	VcpCommandPopup *copyToMenu = NULL;

	VFX_OBJ_CREATE(copyToMenu, VcpCommandPopup, m_parentPage);

	copyToMenu->m_signalButtonClicked.connect(this, &VappSmsOperator::onPopupButtonClicked);
	copyToMenu->setText((VfxResId)STR_ID_VAPP_SMS_COPY);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	copyToMenu->addItem(CMD_COPY_TO_ARCHIVE, (VfxResId)STR_ID_VAPP_SMS_TO_ARCHIVE);

	srv_sms_status_enum status;

	status = m_smsProvider->getStatus();

	if ((status & SRV_SMS_STATUS_UNSUPPORTED) ||
		(status & SRV_SMS_STATUS_UNSENT) ||
		(status & SRV_SMS_STATUS_DRAFT)
	#ifdef __MMI_USB_SUPPORT__
		|| srv_usb_is_in_mass_storage_mode()
	#endif
	   )
	{
		copyToMenu->disableItem(CMD_COPY_TO_ARCHIVE);
	}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

	copyToMenu->addItem(CMD_COPY_TO_PHONE, (VfxResId)STR_ID_VAPP_SMS_TO_PHONE);



#if (MMI_MAX_SIM_NUM >= 2)
	copyToMenu->addItem(CMD_COPY_TO_SIM, STR_ID_VAPP_SMS_TO_SIM);
	if (!srv_sim_ctrl_get_num_of_inserted())
	{
		copyToMenu->disableItem(CMD_COPY_TO_SIM);
	}

#else
	copyToMenu->addItem(CMD_COPY_TO_SIM1, STR_ID_VAPP_SMS_TO_SIM);
	if (!srv_sim_ctrl_is_inserted(MMI_SIM1))
	{
		copyToMenu->disableItem(CMD_COPY_TO_SIM1);
	}
#endif



	copyToMenu->addItem(CMD_CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
	copyToMenu->setAutoDestory(VFX_TRUE);
	copyToMenu->show(VFX_TRUE);


}

void VappSmsOperator::copyToInbox()
{
	srv_sms_storage_enum storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
	if (storage == SRV_SMS_STORAGE_ME)
	{
		m_currOp = VAPP_SMS_OP_COPY_TO_PHONE;
		m_currCmdId = CMD_COPY_TO_PHONE;
		startOperation();
		
	}
	else if (storage == SRV_SMS_STORAGE_TCARD)
	{
		m_currOp = VAPP_SMS_OP_COPY_TO_TCARD;
		m_currCmdId = CMD_COPY_TO_TCARD;
		startOperation();
	}
}

#endif/* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */


#ifdef __MMI_SMS_DETAILS_INFO__	
void VappSmsOperator::useDetail(VappMsgUseDetailProvider* provider)
{
	m_currOp = VAPP_SMS_OP_DELETE;

	VfxMainScr *mainScr;

	mainScr = VfxMainScr::findMainScr(m_parentPage);

	VappMsgUseDetailPage *useDetailPage;

	VFX_OBJ_CREATE(useDetailPage, VappMsgUseDetailPage, mainScr);
	useDetailPage->setProvider(*provider);

    mainScr->pushPage('UseD', useDetailPage);
}
#endif
#ifdef __SRV_SMS_DELIVERY_STATUS__

void VappSmsOperator::viewDeliveryStatus(void)
{
	m_currOp = VAPP_SMS_OP_VIEW_DELIVERY_STATUS;
	VfxWString info;
	VfxWString recipient;
	VfxWChar nameBuff[MMI_PHB_NAME_LENGTH + 1];
	VfxWChar addrBuff[MMI_PHB_NUMBER_LENGTH + 1];
	VfxWString number;
	VfxBool isExisted;
	VfxResId statusResId;
	VfxU16 msgId = m_smsProvider->getMsgID();
	srv_sms_sr_status_enum srStatus;

	srv_sms_get_msg_address(msgId, (S8*)addrBuff);

	isExisted = (srv_phb_get_name_by_number(
							(U16*)addrBuff,
							(U16*)nameBuff,
							MMI_PHB_NAME_LENGTH)? VFX_TRUE: VFX_FALSE);

	info.loadFromRes(STR_ID_VAPP_SMS_REPORTS_RECIPIENT);

	if (isExisted)
	{
		recipient.loadFromMem(nameBuff);
	}
	else
	{
		recipient.loadFromMem(addrBuff);
	}

	info += recipient;
	info += VFX_WSTR("\n");
	info += VFX_WSTR_RES(STR_ID_VAPP_SMS_REPORTS_STATUS);

	srStatus = srv_sms_get_delivery_status(msgId);

	switch (srStatus)
	{
    	case SRV_SMS_SRS_PENDING:
    		statusResId = STR_ID_VAPP_SMS_PENDING;
    		break;

    	case SRV_SMS_SRS_SUCC:
    		statusResId = STR_ID_VAPP_SMS_DELIVERED;
    		break;

    	case SRV_SMS_SRS_FAILED:
    		statusResId = STR_ID_VAPP_SMS_FAILED;
    		break;

		default:
    		statusResId = STR_ID_VAPP_SMS_DELIVERED;
			break;
	}

	info += VFX_WSTR_RES(statusResId);

	VcpConfirmPopup *confirmPopup;

    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_parentPage);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    confirmPopup->setText(info);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->show(VFX_TRUE);
}
#endif
void VappSmsOperator::dialNumber(void)
{
    U16 number[SRV_SMS_MAX_ADDR_LEN + 1];
    srv_sms_get_msg_address((U16)m_smsProvider->getMsgID(), (S8*)number);


	if (number[0] && (applib_is_valid_number_unicode((WCHAR*)number)))
	{
    mmi_id groupId = VfxMainScr::findMainScr(m_parentPage)->getApp()->getGroupId();
		mmi_id cuiId = vcui_dialer_create_ex(groupId, VCUI_DIALER_TYPE_CLASSIC);
    if (cuiId != GRP_ID_INVALID)
    {
        mmi_frm_group_set_caller_proc(cuiId, &VappSmsOperator::onCuiProc, NULL);
        VfxWString dialString;
        dialString.loadFromMem(number); 
        vcui_dialer_set_dial_string(cuiId, dialString);
        vcui_dialer_run(cuiId);
    }
}
}

VfxBool VappSmsOperator::showInfoBalloonIfNeed(void)
{
    VfxResId infoStrId = 0;
    VfxBool result = VFX_TRUE;

	if (!srv_sim_ctrl_is_available(MMI_SIM1) 
    #if (MMI_MAX_SIM_NUM >= 2)
        && !srv_sim_ctrl_is_available(MMI_SIM2)
    #endif
        #if (MMI_MAX_SIM_NUM >= 3)
        && !srv_sim_ctrl_is_available(MMI_SIM3)
    #endif
        #if (MMI_MAX_SIM_NUM >= 4)
        && !srv_sim_ctrl_is_available(MMI_SIM4)
    #endif
       )
    {
        infoStrId = STR_GLOBAL_UNAVAILABLE_SIM;
    }
    else if (!srv_mode_switch_is_network_service_available())
    {
        infoStrId = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;
    }

    if (infoStrId > 0)
    {
		VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);

		balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(infoStrId));
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}

VfxBool VappSmsOperator::showInfoBalloonIfNeed(mmi_sim_enum simId)
{
    VfxResId infoStrId = 0;
    VfxBool result = VFX_TRUE;

	if (!srv_sim_ctrl_is_available(simId))
    {
        infoStrId = STR_GLOBAL_UNAVAILABLE_SIM;
    }
    else if (!srv_mode_switch_is_network_service_available())
    {
        infoStrId = STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE;
    }

    if (infoStrId > 0)
    {
		VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);

		balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(infoStrId));
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}

void VappSmsOperator::dialNumberInt(mmi_sim_enum simId)
{
	VfxWChar number[SRV_SMS_MAX_ADDR_LEN + 1];

	srv_sms_get_msg_address((U16)m_smsProvider->getMsgID(), (S8*)number);

    mmi_ucm_make_call_para_struct param;

    mmi_ucm_init_call_para(&param);

	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(simId);
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(sim_id);
    srv_ucm_call_type_enum call_type[] = 
	{
    		SRV_UCM_VOICE_CALL_TYPE,
			SRV_UCM_VOICE_CALL_TYPE_SIM2,
			SRV_UCM_VOICE_CALL_TYPE_SIM3,
			SRV_UCM_VOICE_CALL_TYPE_SIM4
    	};
	param.dial_type = call_type[sim_index];
    param.ucs2_num_uri = (U16*)number;
    mmi_ucm_call_launch(0, &param);
}

void VappSmsOperator::onPopupButtonClicked(VfxObject* obj, VfxId id)
{
	m_currCmdId = id;

	switch (m_currOp)
	{
		case VAPP_SMS_OP_DELETE:
			if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
			{
				m_currCmdId = CMD_DELETE;
			}
			break;

        case VAPP_SMS_OP_DIAL_NUMBER:
            if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
            {
                m_currCmdId = CMD_DIAL_NUMBER;
            }
            break;

		default:
			break;
	}

	if (id < CMD_DELETE)
	{
		mmi_sim_enum mmi_sim[] = 
			{
				MMI_SIM1,
			#if (MMI_MAX_SIM_NUM >= 2)
				MMI_SIM2,
			#if (MMI_MAX_SIM_NUM >= 3)
				MMI_SIM3,
			#if (MMI_MAX_SIM_NUM >= 4)
				MMI_SIM4
			#endif
			#endif
			#endif
			};
        if (!srv_sim_ctrl_is_available(mmi_sim[id]))
        {
    		VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    		balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_SMS_UNAVAILABLE_SIM));
            return;
        }
	
	}
	
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

        if (m_currCmdId == CMD_DIAL_NUMBER)
        {
			dialNumberInt(m_dialSimId);
        }
	else if (m_currCmdId == CMD_COPY_TO_SIM)
	{
		copyToSim();
	}
        else
        {
            if (!showBalloonIfCmdInvalid())
            {
			    startOperation();
            }
        }
    }

void VappSmsOperator::copyToSim()
{
	
	VcpCommandPopup *copyToSimMenu = NULL;
	
	VFX_OBJ_CREATE(copyToSimMenu, VcpCommandPopup, m_parentPage);

	copyToSimMenu->m_signalButtonClicked.connect(this, &VappSmsOperator::onPopupButtonClicked);
	copyToSimMenu->setText((VfxResId)STR_ID_VAPP_SMS_COPY_TO_SIM);

	ASSERT(MMI_MAX_SIM_NUM >= 2);
	
	VfxWString text;
	VfxWString name;
	mmi_rp_app_vapp_sms_str_enum str[] = 
		{
			STR_ID_VAPP_SMS_TO_SIM1,
		#if (MMI_MAX_SIM_NUM >= 2)
			STR_ID_VAPP_SMS_TO_SIM2,
		#if (MMI_MAX_SIM_NUM >= 3)
			STR_ID_VAPP_SMS_TO_SIM3,
		#if (MMI_MAX_SIM_NUM >= 4)
			STR_ID_VAPP_SMS_TO_SIM4
		#endif
		#endif
		#endif
		};
	for (VfxU8 index = 0; index < MMI_MAX_SIM_NUM; index++)
	{
		text.loadFromRes(str[index]);
		name = vapp_sim_settings_get_sim_name(vapp_sms_sim_index_to_mmi_sim(index));
		if(!name.isEmpty())
		{
			text += VFX_WSTR("(");
			text += name;
			text += VFX_WSTR(")");
		}
		copyToSimMenu->addItem(index, text);
		if (!srv_sim_ctrl_is_inserted(vapp_sms_sim_index_to_mmi_sim(index)))
		{
			copyToSimMenu->disableItem(index);
		}
	}
#if 0
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
	copyToSimMenu->addItem(CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
	copyToSimMenu->setAutoDestory(VFX_TRUE);
	copyToSimMenu->show(VFX_TRUE);
}

VfxBool VappSmsOperator::showBalloonIfCmdInvalid(void)
{
    VfxBool result = VFX_TRUE;
    mmi_sim_enum simId = MMI_SIM1;


	if (m_currCmdId < CMD_DELETE)
	{
		simId = vapp_sms_sim_index_to_mmi_sim(m_currCmdId);	
	}
	else
	{
		result = VFX_FALSE;
	}
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	if (result)
    {
    	if (srv_sim_ctrl_is_available(simId))
        {
            result = VFX_FALSE;
        }
        else
        {
    		VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);

    		balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_GLOBAL_UNAVAILABLE_SIM));
        }
    }
    return result;
}

void VappSmsOperator::startOperation(void)
{
	VfxU16 msgId = m_smsProvider->getMsgID();
	VfxObjHandle objHandle = getObjHandle();

	showIndicatorPopup();

	switch (m_currCmdId)
	{
		case CMD_DELETE:
			m_smsHandle = srv_sms_delete_msg(
							msgId,
							&VappSmsOperator::onOperateDone,
							objHandle);
			break;

	#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
		case CMD_COPY_TO_ARCHIVE:
			srv_sms_copy_msg_to_archive(
				msgId,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;

		case CMD_COPY_FROM_ARCHIVE:
			srv_sms_copy_msg_from_archive(
				msgId,
				SRV_SMS_STORAGE_ME,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;
	#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		case CMD_COPY_TO_TCARD:
			srv_sms_copy_msg(
				msgId,
				SRV_SMS_STORAGE_TCARD,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;
		
	#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

		case CMD_COPY_TO_SIM1:
			srv_sms_copy_msg_ext(
				msgId,
				SRV_SMS_STORAGE_SIM,
				SRV_SMS_SIM_1,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;

	#if (MMI_MAX_SIM_NUM >= 2)
		case CMD_COPY_TO_SIM2:
			srv_sms_copy_msg_ext(
				msgId,
				SRV_SMS_STORAGE_SIM,
				SRV_SMS_SIM_2,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;
	#endif /* (MMI_MAX_SIM_NUM >= 2) */

	#if (MMI_MAX_SIM_NUM >= 3)
		case CMD_COPY_TO_SIM3:
			srv_sms_copy_msg_ext(
				msgId,
				SRV_SMS_STORAGE_SIM,
				SRV_SMS_SIM_3,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;
	#endif /* (MMI_MAX_SIM_NUM >= 3) */
    
	#if (MMI_MAX_SIM_NUM >= 4)
		case CMD_COPY_TO_SIM4:
			srv_sms_copy_msg_ext(
				msgId,
				SRV_SMS_STORAGE_SIM,
				SRV_SMS_SIM_4,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;
	#endif /* (MMI_MAX_SIM_NUM >= 4) */

		case CMD_COPY_TO_PHONE:
			srv_sms_copy_msg(
				msgId,
				SRV_SMS_STORAGE_ME,
				&VappSmsOperator::onOperateDone,
				objHandle);
			break;

		default:
			break;
	}
}

void VappSmsOperator::onOperateDone(srv_sms_callback_struct* callbackData)
{
	VfxObjHandle objHandle = (VfxObjHandle)callbackData->user_data;
	VappSmsOperator *currOperator = (VappSmsOperator*)VfxObject::handleToObject(objHandle);

	if (currOperator)
	{
        currOperator->m_smsHandle = SRV_SMS_INVALID_HANDLE;
		currOperator->stopIndicatorPopup();
		currOperator->popupOperateResult(callbackData->result? VFX_TRUE: VFX_FALSE, callbackData->cause);
	}
}

void VappSmsOperator::popupOperateResult(VfxBool result, srv_sms_cause_enum errorCause)
{
	VfxResId resId;

	resId = getResultStringRes(result, errorCause);

	if (resId)
	{
		if (result)
		{
			VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);

			balloon->addItem(VCP_INFO_BALLOON_TYPE_SUCCESS, VFX_WSTR_RES(resId));
		}
		else
		{
		    VcpConfirmPopup *failPopup;	    

	        VFX_OBJ_CREATE(failPopup, VcpConfirmPopup, m_parentPage);
	        failPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
	        failPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
	        failPopup->setText(resId);
	        failPopup->show(VFX_TRUE);
		}
	}
}

VfxResId VappSmsOperator::getResultStringRes(VfxBool result, srv_sms_cause_enum errorCause)
{
	VfxResId resId = 0;

	if (result)
	{
		switch(m_currCmdId)
		{
			case CMD_DELETE:
				break;

		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			case CMD_COPY_TO_ARCHIVE:
				resId = STR_ID_VAPP_SMS_COPIED_TO_ARCHIVE;
				break;

			case CMD_COPY_FROM_ARCHIVE:
			{
				srv_sms_status_enum msgStatus;

				msgStatus = m_smsProvider->getStatus();
				msgStatus = (srv_sms_status_enum)(msgStatus & (~SRV_SMS_STATUS_UNSUPPORTED));

				switch (msgStatus)
				{
					case SRV_SMS_STATUS_READ:
					case SRV_SMS_STATUS_UNREAD:
						resId = STR_ID_VAPP_SMS_COPIED_TO_INBOX;
						break;

					case SRV_SMS_STATUS_SENT:
						resId = STR_ID_VAPP_SMS_COPIED_TO_SENTBOX;
						break;

					case SRV_SMS_STATUS_UNSENT:
						resId = STR_ID_VAPP_SMS_COPIED_TO_OUTBOX;
						break;

					default:
						break;
				}
				break;
			}
		#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #if (MMI_MAX_SIM_NUM >= 4)
            case CMD_COPY_TO_SIM4:
                resId = STR_ID_VAPP_SMS_COPIED_TO_SIM4;
                break;
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
			case CMD_COPY_TO_SIM3:
				resId = STR_ID_VAPP_SMS_COPIED_TO_SIM3;
				break;
        #endif
		#if (MMI_MAX_SIM_NUM >= 2)
			case CMD_COPY_TO_SIM2:
				resId = STR_ID_VAPP_SMS_COPIED_TO_SIM2;
				break;
            case CMD_COPY_TO_SIM1:
				resId = STR_ID_VAPP_SMS_COPIED_TO_SIM1;
				break;
		#else
            case CMD_COPY_TO_SIM1:
               	resId = STR_ID_VAPP_SMS_COPIED_TO_SIM;
				break; 
        #endif
			case CMD_COPY_TO_PHONE:
				resId = STR_ID_VAPP_SMS_COPIED_TO_PHONE;
				break;
		#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			case CMD_COPY_TO_TCARD:
				resId = STR_ID_VAPP_SMS_COPIED_TO_TCARD;
				break;
		#endif

			default:
				break;
		}
	}
	else
	{
		switch(m_currCmdId)
		{
			case CMD_DELETE:
				resId = STR_ID_VAPP_SMS_FAIL_TO_DELETE;
				break;

		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			case CMD_COPY_TO_ARCHIVE:
			case CMD_COPY_FROM_ARCHIVE:
		#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
			case CMD_COPY_TO_SIM1:
	    #if (MMI_MAX_SIM_NUM >= 2)
			case CMD_COPY_TO_SIM2:
		#endif /* (MMI_MAX_SIM_NUM >= 2) */
        #if (MMI_MAX_SIM_NUM >= 3)
			case CMD_COPY_TO_SIM3:
		#endif /* (MMI_MAX_SIM_NUM >= 2) */
        #if (MMI_MAX_SIM_NUM >= 4)
			case CMD_COPY_TO_SIM4:
		#endif /* (MMI_MAX_SIM_NUM >= 2) */
		#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			case CMD_COPY_TO_TCARD:
		#endif
			case CMD_COPY_TO_PHONE:
			{
				if (errorCause == SRV_SMS_CAUSE_MEM_FULL)
				{
					resId = STR_GLOBAL_MEMORY_FULL;
				}
				else
				{
					resId = STR_ID_VAPP_SMS_FAIL_TO_COPY;
				}
				break;
			}

			default:
				break;
		}
	}

	return resId;
}

void VappSmsOperator::onCancelClicked(VfxObject* obj, VfxFloat progress)
{
	stopIndicatorPopup();
	srv_sms_abort(m_smsHandle, NULL, NULL);
}

void VappSmsOperator::showIndicatorPopup(void)
{
	if (m_indicatorPopup == NULL)
	{
		VfxWString text;

		switch (m_currCmdId)
		{
			case CMD_DELETE:
				text.loadFromRes(STR_GLOBAL_DELETING);
				break;
		#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			case CMD_COPY_TO_TCARD:
		#endif
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			case CMD_COPY_TO_ARCHIVE:
		#endif
			case CMD_COPY_TO_SIM1:
        #if (MMI_MAX_SIM_NUM >= 2)
			case CMD_COPY_TO_SIM2:
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
			case CMD_COPY_TO_SIM3:
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
			case CMD_COPY_TO_SIM4:
        #endif
			case CMD_COPY_TO_PHONE:
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			case CMD_COPY_FROM_ARCHIVE:
		#endif
				text.loadFromRes(STR_GLOBAL_COPYING);
				break;

			default:
				break;
		}

		if (!text.isEmpty())
	    {
	    	VFX_OBJ_CREATE(m_indicatorPopup, VcpIndicatorPopup, m_parentPage);

		    m_indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
		    m_indicatorPopup->setAutoDestory(VFX_FALSE);
		    m_indicatorPopup->m_signalCanceled.connect(this, &VappSmsOperator::onCancelClicked);
    		m_indicatorPopup->setText(text);

	    	m_indicatorPopup->show(VFX_TRUE);
		}
	}
}

void VappSmsOperator::stopIndicatorPopup(void)
{
	VFX_OBJ_CLOSE(m_indicatorPopup);
}


void VappSmsOperator::entryUcEditor(VappSmsOpType opType)
{
	if (m_smsProvider == NULL)
	{
		return;
	}

	m_currOp = opType;

    
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
	VappUcEntryStruct ucData;
	VfxWChar *content = m_smsProvider->getContent();

	memset(&ucData, 0, sizeof(VappUcEntryStruct));

	ucData.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
	ucData.info_type = SRV_UC_INFO_TYPE_SMS;
	ucData.sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
	ucData.msg_id = m_smsProvider->getMsgID();

	switch (opType)
	{
		case VAPP_SMS_OP_FORWARD:
			ucData.type = SRV_UC_STATE_FORWARD;
			ucData.operation = UC_OPERATION_FORWARD;
            if (m_isLiteMode)
            {
                ucData.msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
            }
			break;
		case VAPP_SMS_OP_REPLY:
			ucData.type = SRV_UC_STATE_REPLY;
			ucData.operation = UC_OPERATION_REPLY;
            if (m_isLiteMode)
            {
                ucData.msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
            }
			break;

		case VAPP_SMS_OP_EDIT:
			ucData.type = SRV_UC_STATE_EDIT_EXISTED_MSG;
			ucData.operation = UC_OPERATION_EDIT_EXISTED_MSG;
			break;

		default:
			break;
	}

    mmi_id groupId = VfxMainScr::findMainScr(m_parentPage)->getApp()->getGroupId();
	mmi_id cuiId = vcui_unifiedcomposer_create(groupId, &ucData);

    if (cuiId != GRP_ID_INVALID)
	{
		mmi_frm_group_set_caller_proc(cuiId, &VappSmsOperator::onCuiProc, NULL);
		vcui_unifiedcomposer_run(cuiId);
	}
#endif  /*defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)*/

#ifdef __MMI_SMS_COMPOSER__   
    mmi_id smsComposerCui = 0;
    VcuiSmsComposerEntryStruct *entryData;
    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );
    
	// set operation method to a existed msg, only for message app internal use
	entryData->msg_id = m_smsProvider->getMsgID();
	switch (opType)
	{
		case VAPP_SMS_OP_FORWARD:
			entryData->operation = VCUI_SMS_COMPOSER_OPERATION_FORWARD;
			break;
		case VAPP_SMS_OP_REPLY:
			entryData->operation = VCUI_SMS_COMPOSER_OPERATION_REPLY;
			break;
		case VAPP_SMS_OP_EDIT:
			entryData->operation = VCUI_SMS_COMPOSER_OPERATION_EDIT;
			break;
		default:
			break;
	}
	
    mmi_id groupId = VfxMainScr::findMainScr(m_parentPage)->getApp()->getGroupId();
    smsComposerCui = vcui_sms_composer_create(groupId);
    if(smsComposerCui !=  GRP_ID_INVALID)
    {
        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
        vfxSetCuiCallerScr(smsComposerCui, VfxMainScr::findMainScr(m_parentPage));
        vcui_sms_composer_run(smsComposerCui);
    }
    VFX_FREE_MEM(entryData);
   
#endif /* __MMI_SMS_COMPOSER__ */

    
}

mmi_ret VappSmsOperator::onCuiProc(mmi_event_struct *evt)
{
	mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;

	switch(evt->evt_id)
    {
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
		case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
			vcui_unifiedcomposer_close(senderId);
			break;
#endif /* (__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/
#ifdef __MMI_SMS_COMPOSER__		
        case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
        {
            /* just close it */
            VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
            vcui_sms_composer_close(ucEvt->sender_id);        
            break;
        }
#endif /* __MMI_SMS_COMPOSER__ */
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            vcui_dialer_close(senderId);
            break;

		default:
			break;
	}

    return MMI_RET_OK;
}


