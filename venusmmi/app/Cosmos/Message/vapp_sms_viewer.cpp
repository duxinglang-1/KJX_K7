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
#include "vapp_sms_viewer.h"
#include "vapp_msg_contact_bar.h"
#include "vapp_msg_use_detail.h"
#include "vcp_navi_title_bar.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "vapp_ucm_def.h"
#include "GlobalResDef.h"
#include "vapp_uc_gprot.h"
#include "vapp_sms_util.h"
#ifdef __cplusplus
extern "C"
#endif
{
    #include "SmsSrvGprot.h"
	#include "SimCtrlSrvGProt.h"
    #include "App_datetime.h"
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
//VFX_IMPLEMENT_CLASS("VappSmsViewerPage", VappSmsViewerPage, VfxPage);

VappSmsViewerPage::VappSmsViewerPage() :
	m_smsProvider(NULL),
	m_isLoadDone(VFX_FALSE),
	m_isUpdate(VFX_FALSE),
	m_isLiteMode(VFX_FALSE),
	m_isSupSendKey(VFX_FALSE),
	m_msgStorage(SRV_SMS_STORAGE_UNSPECIFIC),
	m_contactBar(NULL),
	m_contactProvider(NULL),
	m_smsBody(NULL),
	m_toolBar(NULL),
	m_timestampFrame(NULL),
	m_loadingIcon(NULL),
#ifdef __MMI_SMS_PORT_MSG__

	m_vObjectButton(NULL),
#endif
	m_addrOption(NULL)	
{
}

void VappSmsViewerPage::setMsgID(VfxU16 msgID, VfxBool mode)
{
    m_isLiteMode = mode; 
	m_msgID = msgID;
    if (mode)
{
        m_smsOperator->setLiteMode(mode);
    }
	m_smsProvider->setMsgID(msgID);
	m_smsOperator->setProvider(m_smsProvider);
	setContactBar();
	setMsgToolbar();
}
void VappSmsViewerPage::onEntered()
{
    VfxPage::onEntered();
	if (!m_isLoadDone)
	{
	showLoadingIcon();
	m_smsProvider->read(m_msgID, VFX_TRUE); 
	if (m_contactBar)
	{
		m_contactBar->onRotate();
	}
}

}
void VappSmsViewerPage::setSmsProvider(VappSmsProvider& provider)
{
	*m_smsProvider = provider;

	m_smsOperator->setProvider(m_smsProvider);

	setContactBar();
	setMsgToolbar();

	if (provider.isDataValid())
	{
		stopLoadingIcon();
	}
	else
	{
		showLoadingIcon();
		m_smsProvider->update();
	}

	checkUpdateEx();
}

void VappSmsViewerPage::onInit(void)
{
	VfxPage::onInit();
	setBgColor(VFX_COLOR_RES(VAPP_SMS_VIEWER_TEXT_BACKGROUND_COLOR));
	VFX_OBJ_CREATE(m_smsProvider, VappSmsProvider, this);
	m_smsProvider->m_signalReadDone.connect(this, &VappSmsViewerPage::onLoadSmsDone);
	m_smsProvider->m_signalMsgChanged.connect(this, &VappSmsViewerPage::onMsgChanged);
	m_smsProvider->m_signalMsgDeleted.connect(this, &VappSmsViewerPage::onMsgDeleted);
	m_smsProvider->m_signalReadAgain.connect(this, &VappSmsViewerPage::onReadAgain);
	VFX_OBJ_CREATE(m_smsOperator, VappSmsOperator, this);
	m_smsOperator->setParentPage(this);




    VFX_OBJ_CREATE(m_timestampFrame, VfxTextFrame, this);
    m_timestampFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
	m_timestampFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TIMESTAMP_FONT_SIZE)));

	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
}

void VappSmsViewerPage::onDeinit()
{
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__

	if (m_msgStorage == SRV_SMS_STORAGE_TCARD)
	{
    	mmi_frm_cb_dereg_event(
        	EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        	VappSmsViewerPage::onTcardPlugInOutProc,
        	getObjHandle());  
	}
#endif
	VFX_OBJ_CLOSE(m_smsProvider);
	VfxPage::onDeinit();
}

void VappSmsViewerPage:: onUpdate(void)
{
	VfxPage::onUpdate();

	if (m_isUpdate)
	{
		m_isUpdate = VFX_FALSE;
	
		if (m_smsProvider->isDataValid())
		{
			updateBody();
		}
	#ifdef __MMI_SMS_DETAILS_INFO__	
        else
        {
            m_toolBar->setDisableItem(BUTTON_USE_DETAIL, VFX_TRUE);
        }
	#endif
	}
}

void VappSmsViewerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

void VappSmsViewerPage::checkUpdateEx(void)
{
	if (!m_isUpdate)
	{
		m_isUpdate = VFX_TRUE;
		checkUpdate();
	}
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__

mmi_ret VappSmsViewerPage::onTcardPlugInOutProc(mmi_event_struct *evt)
{
    VappSmsViewerPage *page = (VappSmsViewerPage *)handleToObject((VfxObjHandle)evt->user_data);

	if (page)
	{
		page->exit();
	}
	return MMI_RET_OK;
}
#endif

void VappSmsViewerPage::setMsgToolbar(void)
{
	m_isUnsentMsg = VFX_FALSE;

	m_toolBar->m_signalButtonTap.connect(this, &VappSmsViewerPage::onButtonClicked);

	srv_sms_status_enum oriMsgStatus;
	srv_sms_status_enum msgStatus;

	oriMsgStatus = m_smsProvider->getStatus();
	msgStatus = (srv_sms_status_enum)(oriMsgStatus & (~SRV_SMS_STATUS_UNSUPPORTED));


	m_msgStorage = m_smsProvider->getStorageType();

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	if (m_msgStorage == SRV_SMS_STORAGE_TCARD)
	{
    	mmi_frm_cb_reg_event(
        	EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        	VappSmsViewerPage::onTcardPlugInOutProc,
        	getObjHandle());  
	}
#endif

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
	if (m_msgStorage == SRV_SMS_STORAGE_SIM)
	{
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		m_toolBar->addItem(BUTTON_COPY_TO_INBOX, (VfxResId)STR_ID_VAPP_MSG_COPY_TO_INBOX, IMG_ID_VAPP_SMS_COPY_TO_PHONE);
	#else
		m_toolBar->addItem(BUTTON_COPY_TO_PHONE, (VfxResId)STR_ID_VAPP_SMS_COPY_TO_PHONE, IMG_ID_VAPP_SMS_COPY_TO_PHONE);
	#endif
		m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	}
	else
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
	{
	#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
		VfxBool isArchiveMsg = VFX_FALSE;

		if (m_smsProvider->getFolderID() == SRV_SMS_FOLDER_ARCHIVE)
		{
			isArchiveMsg = VFX_TRUE;
		}
	#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
		switch (msgStatus)
		{
			case SRV_SMS_STATUS_READ:
			case SRV_SMS_STATUS_UNREAD:
                m_isSupSendKey = VFX_TRUE;
				m_toolBar->addItem(BUTTON_REPLY, (VfxResId)STR_GLOBAL_REPLY, VCP_IMG_TOOL_BAR_COMMON_ITEM_REPLY);
                if (m_isLiteMode == VFX_FALSE)
                {
				m_toolBar->addItem(BUTTON_CALL, (VfxResId)STR_GLOBAL_DIAL, IMG_ID_VAPP_SMS_CALL);
                }
				m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
				m_toolBar->addItem(BUTTON_FORWARD, (VfxResId)STR_GLOBAL_FORWARD, VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD);
                if (m_isLiteMode == VFX_FALSE)
                {
                #ifdef __MMI_SMS_DETAILS_INFO__	
				m_toolBar->addItem(BUTTON_USE_DETAIL, (VfxResId)STR_GLOBAL_DETAILS, IMG_ID_VAPP_SMS_USE_DETAIL);
				#endif
                }

                U16 number[SRV_SMS_MAX_ADDR_LEN + 1];
                srv_sms_get_msg_address((U16)m_smsProvider->getMsgID(), (S8*)number);
                if (number[0] && (applib_is_valid_number_unicode((WCHAR*)number)))
                {
                    m_toolBar->setDisableItem(BUTTON_CALL, VFX_FALSE);
                    m_toolBar->setDisableItem(BUTTON_REPLY, VFX_FALSE);
                }
                else
                {
                    m_toolBar->setDisableItem(BUTTON_CALL, VFX_TRUE);
                    m_toolBar->setDisableItem(BUTTON_REPLY, VFX_TRUE);
                }


			#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
				if (isArchiveMsg)
				{
				    if (m_isLiteMode == VFX_FALSE)
					m_toolBar->addItem(BUTTON_COPY_FROM_ARCHIVE, (VfxResId)STR_ID_VAPP_SMS_COPY_TO_INBOX, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
				}
				else
			#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
				{
				#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
					if (m_msgStorage == SRV_SMS_STORAGE_SIM)
					{
					    if (m_isLiteMode == VFX_FALSE)
						m_toolBar->addItem(BUTTON_COPY_TO_PHONE, (VfxResId)STR_ID_VAPP_SMS_COPY_TO_PHONE, IMG_ID_VAPP_SMS_COPY_TO_PHONE);
					}
					else
				#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
					{
					    if (m_isLiteMode == VFX_FALSE)
				    	{
				#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
					if (m_msgStorage == SRV_SMS_STORAGE_TCARD)
					{
						m_toolBar->addItem(BUTTON_COPY_FROM_TCARD, (VfxResId)STR_ID_VAPP_SMS_COPY, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
					}
					else
						#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
					{
						m_toolBar->addItem(BUTTON_COPY_FROM_PHONE, (VfxResId)STR_ID_VAPP_SMS_COPY, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
					}
				}
					}
				}
				break;

			case SRV_SMS_STATUS_SENT:
				m_toolBar->addItem(BUTTON_FORWARD, (VfxResId)STR_GLOBAL_FORWARD, VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD);
			#ifdef __MMI_SMS_DETAILS_INFO__	
				m_toolBar->addItem(BUTTON_USE_DETAIL, (VfxResId)STR_GLOBAL_DETAILS, IMG_ID_VAPP_SMS_USE_DETAIL);
			#endif
			#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
				if (isArchiveMsg)
				{
					m_toolBar->addItem(BUTTON_COPY_FROM_ARCHIVE, (VfxResId)STR_ID_VAPP_SMS_COPY_TO_SENTBOX, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
					m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
				}
				else
			#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
				{
				#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
					if (m_msgStorage == SRV_SMS_STORAGE_SIM)
					{
						m_toolBar->addItem(BUTTON_COPY_TO_PHONE, (VfxResId)STR_ID_VAPP_SMS_COPY_TO_PHONE, IMG_ID_VAPP_SMS_COPY_TO_PHONE);
						m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
					}
					else
				#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
					{
						m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
					#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
						if (m_msgStorage == SRV_SMS_STORAGE_TCARD)
						{
							m_toolBar->addItem(BUTTON_COPY_FROM_TCARD, (VfxResId)STR_ID_VAPP_SMS_COPY, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
						}
						else
					#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
						{
						m_toolBar->addItem(BUTTON_COPY_FROM_PHONE, (VfxResId)STR_ID_VAPP_SMS_COPY, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
						}
					#ifdef __SRV_SMS_DELIVERY_STATUS__
						m_toolBar->addItem(BUTTON_REPORTS, (VfxResId)STR_ID_VAPP_SMS_REPORTS, IMG_ID_VAPP_SMS_TB_REPORTS);
					#endif
					}
				}
				break;

			case SRV_SMS_STATUS_UNSENT:
			{
				m_toolBar->addItem(BUTTON_RESEND, (VfxResId)STR_GLOBAL_RESEND, IMG_ID_VAPP_SMS_RESEND);
				m_toolBar->addItem(BUTTON_EDIT, (VfxResId)STR_GLOBAL_EDIT, VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
				m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
			#ifdef __MMI_SMS_DETAILS_INFO__	
				m_toolBar->addItem(BUTTON_USE_DETAIL, (VfxResId)STR_GLOBAL_DETAILS, IMG_ID_VAPP_SMS_USE_DETAIL);
			#endif
			#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
				if (isArchiveMsg)
				{
					m_toolBar->setDisableItem(BUTTON_RESEND, VFX_TRUE);
				}
				else
			#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
				{
					m_isUnsentMsg = VFX_TRUE;
				}
				break;
			}

			default:
				m_toolBar->addItem(BUTTON_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
				break;
		}
	}

    srv_sms_sim_enum smsSimId = m_smsProvider->getSimID();
    mmi_sim_enum mmiSimId = SRV_SMS_SMS_SIM_TO_MMI(smsSimId);

    if (!srv_sim_ctrl_is_inserted(mmiSimId))
    {
		m_toolBar->setDisableItem(BUTTON_RESEND, VFX_TRUE);
    }

	if (oriMsgStatus & SRV_SMS_STATUS_UNSUPPORTED)
	{
		m_toolBar->setDisableItem(BUTTON_FORWARD, VFX_TRUE);
		m_toolBar->setDisableItem(BUTTON_EDIT, VFX_TRUE);
	}

	setBottomBar(m_toolBar);
}

void VappSmsViewerPage::setContactBar(void)
{
	
	VFX_OBJ_CREATE(m_contactBar, VappMsgContactBar, this);
    m_contactBar->setSize(getSize().width, m_contactBar->getSize().height);
	m_contactBar->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);
	if (m_isLiteMode)
	{
		m_contactBar->setLiteMode(m_isLiteMode);
	}
	VFX_OBJ_CREATE(m_contactProvider, VappSmsContactProvider, this);
	m_contactProvider->setMsgID(m_msgID);

	m_contactBar->setContact(m_contactProvider);
	

	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(m_smsProvider->getSimID());
	mmi_rp_app_cosmos_global_img_enum sim_img[] = 
		{
			IMG_COSMOS_SIM1,
#if (MMI_MAX_SIM_NUM >= 2)
			IMG_COSMOS_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
			IMG_COSMOS_SIM3,
		#if (MMI_MAX_SIM_NUM >= 4)
			IMG_COSMOS_SIM4
		#endif
#endif
#endif
		};
	m_contactBar->setRightIcon(VfxImageSrc(sim_img[sim_index]));

}

void VappSmsViewerPage::updateBody(void)
{
	VFX_ASSERT(m_smsProvider != NULL);
	VfxDateTime timestamp;
	VfxWChar datatime[DATATIME_BUFF_LEN + 1];
	VfxU32 flags = VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY |
				   VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;

	/* Add timestamp behind the SMS content */
	m_smsProvider->getTimeStatmp(&timestamp);

	datatime[0] = '\n';
	timestamp.getDateTimeString(flags, &datatime[1], DATATIME_BUFF_LEN);

    m_timestampFrame->setString(datatime);

#ifdef __MMI_SMS_PORT_MSG__

	VfxU16 port = m_smsProvider->getDestPort();
	VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);

	if (portReg->findPort(port))
	{
		VfxSize pageSize = getSize();

		if (m_smsBody)
		{
			VFX_OBJ_CLOSE(m_smsBody);
		}

		if (m_vObjectButton == NULL)
		{
			VfxSize barSize = m_contactBar->getSize();
			VfxS32 shadowHeight = m_contactBar->getShadowHeight();
			VfxS32 buttonY;

			buttonY = barSize.height + VOBJECT_MARGIN_TOP - shadowHeight;

			VFX_OBJ_CREATE(m_vObjectButton, VappSmsVObjectButton, this);
			m_vObjectButton->setPos(VOBJECT_MARGIN_LEFT, buttonY);
			m_vObjectButton->setSize(pageSize.width - (VOBJECT_MARGIN_LEFT * 2), VOBJECT_BUTTON_HEIGHT);
			m_vObjectButton->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
			m_vObjectButton->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);

			m_vObjectButton->m_signalClicked.connect(this, &VappSmsViewerPage::onVObjectButtonClicked);
			if (m_isLiteMode)
			{
				m_vObjectButton->setIsDisabled(VFX_TRUE);
			}
			m_timestampFrame->setAnchor(1.0, 0);
			m_timestampFrame->setPos((pageSize.width - TIMESTAMP_MARGIN_RIGHT), (buttonY + VOBJECT_BUTTON_HEIGHT));
			m_timestampFrame->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
			m_timestampFrame->setMargins(0, TIMESTAMP_MARGIN_TOP, 0, TIMESTAMP_MARGIN_TOP);
		}

		VfxImageSrc vObjectImage;
		VfxWString vObjectText;

		portReg->getAppInfo(port, vObjectText, vObjectImage);

		m_vObjectButton->setImage(vObjectImage);
		m_vObjectButton->setText(vObjectText);
	#ifdef __MMI_SMS_DETAILS_INFO__
		m_toolBar->setDisableItem(BUTTON_USE_DETAIL, VFX_TRUE);
	#endif
	}
	else
#endif /* __MMI_SMS_PORT_MSG__ */
	{
	#ifdef __MMI_SMS_PORT_MSG__
		if (m_vObjectButton)
		{
			VFX_OBJ_CLOSE(m_vObjectButton);
		}
	#endif
		if (m_smsBody == NULL)
		{
			VfxSize pageSize = getSize();
			VfxSize barSize = m_contactBar->getSize();
			VfxS32 shadowHeight = m_contactBar->getShadowHeight();

			pageSize.height -= barSize.height;

			VFX_OBJ_CREATE(m_smsBody, VcpTextView, this);
			m_smsBody->setAutoAnimate(VFX_FALSE);
			m_smsBody->setPos(0, barSize.height);
			m_smsBody->setSize(pageSize);
			m_smsBody->setAlignParent(
	                    VFX_FRAME_ALIGNER_MODE_SIDE, 
	                    VFX_FRAME_ALIGNER_MODE_SIDE, 
	                    VFX_FRAME_ALIGNER_MODE_SIDE, 
	                    VFX_FRAME_ALIGNER_MODE_SIDE);
		    m_smsBody->setMargins(TEXT_VIEW_MARGIN_LEFT, (TEXT_VIEW_MARGIN_TOP - shadowHeight), TEXT_VIEW_MARGIN_LEFT, TEXT_VIEW_MARGIN_BUTTOM);
			m_smsBody->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
			
			if (!m_isLiteMode)
			{
		    	m_smsBody->setKeyword(VCP_TEXT_KEYWORD_PHONENUMBER |
									#ifdef __MMI_EMAIL__
									  VCP_TEXT_KEYWORD_EMAIL |
			    					#endif
		    					  	  VCP_TEXT_KEYWORD_URL | 
		    					  	  VCP_TEXT_KEYWORD_USSD);
			m_smsBody->m_signalKeywordClick.connect(this, &VappSmsViewerPage::onKeywordClicked);
			}

			m_timestampFrame->setMargins(0, TIMESTAMP_MARGIN_TOP, 0, TIMESTAMP_MARGIN_TOP);
		}

		VfxWChar *content = m_smsProvider->getContent();
		VfxU32 contentLen = vfx_sys_wcslen(content);

	    VcpRichTextCustomFrame customFrame;
	    customFrame.setFrame(m_timestampFrame);
	    customFrame.setRange(contentLen, contentLen);
	    customFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);

		/* Set SMS content */
		m_smsBody->setText(content);
        m_smsBody->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(VAPP_SMS_TEXT_COLOR));
	    m_smsBody->setTextFormat(&customFrame);
	#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
		VcpIconTable *iconTable = VappUcEmoticon::getEmotionTablePointer();
		VfxU32 tableSize = VappUcEmoticon::getEmotionTableSize();

		m_smsBody->setIconMode(VFX_TRUE, iconTable, (VfxU8)tableSize);
	#endif
		/* Need forceUpdate to get the use detail information from the text keyword format,
		 * for checking whether it is contained use details information */
		m_smsBody->forceUpdate();
	#ifdef __MMI_SMS_DETAILS_INFO__
		m_toolBar->setDisableItem(BUTTON_USE_DETAIL, isDisalbeUseDetail());
	#endif
	}
}

void VappSmsViewerPage::onKeywordClicked(
		VcpTextKeyWordEnum keyworkType,
		VfxWChar* text,
		VfxS32 textLen)
{
    if(m_isLiteMode)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    	balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_SMS_VOICEMAIL_NOT_AVAILABLE));
        return;
    }
	m_smsBody->setHighlight(0, 0);

	VfxWString address;
	VfxWChar *addrText;
	VappMsgAddrType addrType;

	VFX_ALLOC_MEM(addrText, (textLen + 1) * 2, this);
	memcpy(addrText, text, textLen * 2);
	addrText[textLen] = '\0';
	address.loadFromMem(addrText);
	VFX_FREE_MEM(addrText);

	switch (keyworkType)
	{
		case VCP_TEXT_KEYWORD_PHONENUMBER:
			addrType = VAPP_MSG_ADDR_TYPE_PHONENUMBER;
			break;

		case VCP_TEXT_KEYWORD_EMAIL:
			addrType = VAPP_MSG_ADDR_TYPE_EMAIL;
			break;

		case VCP_TEXT_KEYWORD_URL:
			addrType = VAPP_MSG_ADDR_TYPE_URL;
			break;

		case VCP_TEXT_KEYWORD_USSD:
			addrType = VAPP_MSG_ADDR_TYPE_USSD;
			break;

		default:
			addrType = VAPP_MSG_ADDR_TYPE_NONE;
			break;
	}

	if (m_addrOption == NULL)
	{
		VFX_OBJ_CREATE(m_addrOption, VappMsgAddrOption, this);
	}

	m_addrOption->setAddrItem(address, addrType);
	m_addrOption->show(this);
}

void VappSmsViewerPage::onLoadSmsDone(VfxBool result)
{
	m_isLoadDone = VFX_TRUE;
	    stopLoadingIcon();
	checkUpdateEx();
}

void VappSmsViewerPage::onMsgChanged(void)
{
	m_isLoadDone = VFX_TRUE;

	stopLoadingIcon();
	if (m_isUnsentMsg)
	{
		srv_sms_send_status_enum sendStatus;

		sendStatus = m_smsProvider->getSendStatus();

		if (sendStatus != SRV_SMS_SEND_FAIL)
		{
			exit();
		}
	}
	else
	{
        checkUpdateEx();
    }
}

void VappSmsViewerPage::onMsgDeleted(void)
{
	exit();
}
void VappSmsViewerPage::onReadAgain(void)
{
	showLoadingIcon();
	m_smsProvider->read(m_msgID, VFX_TRUE); 
}

void VappSmsViewerPage::onRotate(const VfxScreenRotateParam &param)
{
	if (m_contactBar)
	m_contactBar->onRotate();
}

void VappSmsViewerPage::onButtonClicked(VfxObject * sender, VfxId bottom_id)
{
	if (m_isLoadDone)
	{
		switch (bottom_id)
		{
			case BUTTON_REPLY:
				m_smsOperator->Reply();
				break;

			case BUTTON_CALL:
			{
				m_smsOperator->dialNumber();
				break;
			}

			case BUTTON_RESEND:
				m_smsOperator->resend();
				break;

			case BUTTON_FORWARD:
				m_smsOperator->forward();
				break;

			case BUTTON_EDIT:
				m_smsOperator->edit();
				break;

			case BUTTON_DELETE:
				m_smsOperator->deleteMsg();
				break;
		#ifdef __MMI_SMS_DETAILS_INFO__	
			case BUTTON_USE_DETAIL:
			{
				VappMsgUseDetailProvider *provider;

				VFX_OBJ_CREATE(provider, VappMsgUseDetailProvider, this);

			#if (MMI_MAX_SIM_NUM >= 2)
				srv_sms_sim_enum smsSimId = m_smsProvider->getSimID();
				mmi_sim_enum simId = SRV_SMS_SMS_SIM_TO_MMI(smsSimId);

				provider->setSimId(simId);
			#endif

				addAddrItemToUseDetail(provider);

				m_smsOperator->useDetail(provider);

				VFX_OBJ_CLOSE(provider);
				break;
			}
		#endif
		#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			case BUTTON_COPY_FROM_TCARD:
				m_smsOperator->copyFromTcard();
				break;
			case BUTTON_COPY_TO_INBOX:
				m_smsOperator->copyToInbox();
				break;
		#endif
			case BUTTON_COPY_FROM_PHONE:
				m_smsOperator->copyFromPhone();
				break;

			case BUTTON_COPY_TO_PHONE:
				m_smsOperator->copyToPhone();
				break;
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
			case BUTTON_COPY_FROM_ARCHIVE:
				m_smsOperator->copyFromArchive();
				break;
		#endif
		#ifdef __SRV_SMS_DELIVERY_STATUS__
			case BUTTON_REPORTS:
				m_smsOperator->viewDeliveryStatus();
				break;
		#endif
			default:
				VFX_ASSERT(0);
				break;
		}
	}
}
#ifdef __MMI_SMS_PORT_MSG__

void VappSmsViewerPage::onVObjectButtonClicked(void)
{
	VfxU16 port = m_smsProvider->getDestPort();
	VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);
	VfxWChar *data = m_smsProvider->getContent();
	if (data == NULL)
	{
		return;
	}
	VfxU32 dataSize = m_smsProvider->getContentSize();
	portReg->dispatch(port, (VfxChar*)data, dataSize);
}
#endif
VfxBool VappSmsViewerPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_SEND && event.type == VFX_KEY_EVENT_TYPE_DOWN 
		&& m_isSupSendKey && m_isLiteMode == VFX_FALSE)
    {
        m_smsOperator->dialNumber();
    }

    return VfxPage::onKeyInput(event);
}
#ifdef __MMI_SMS_DETAILS_INFO__	

void VappSmsViewerPage::addAddrItemToUseDetail(VappMsgUseDetailProvider* provider)
{
	VcpRichTextFormat *textFormat = m_smsBody->getFormatObject();

	for (; textFormat; textFormat = textFormat->getNext())
	{
		if (textFormat->m_type == VCP_RICH_TEXT_TYPE_TEXT)
		{
			VcpRichText *richtext= (VcpRichText*)textFormat;
			VappMsgAddrType addrType;
		
			switch (richtext->m_mode)
			{
				case VCP_TEXT_KEYWORD_PHONENUMBER:
					addrType = VAPP_MSG_ADDR_TYPE_PHONENUMBER;
					break;

				case VCP_TEXT_KEYWORD_EMAIL:
					addrType = VAPP_MSG_ADDR_TYPE_EMAIL;
					break;

				case VCP_TEXT_KEYWORD_URL:
					addrType = VAPP_MSG_ADDR_TYPE_URL;
					break;

				case VCP_TEXT_KEYWORD_USSD:
					addrType = VAPP_MSG_ADDR_TYPE_USSD;
					break;

				default:
					addrType = VAPP_MSG_ADDR_TYPE_NONE;
					break;
			}

			if (addrType != VAPP_MSG_ADDR_TYPE_NONE)
			{
				VfxWChar *addrText;
				VfxWString address;
				VfxWChar *content = m_smsBody->getText();
				VfxU32 start = textFormat->m_range.getStart();
				VfxU32 textLen = textFormat->m_range.getEnd()- start;

				VFX_ALLOC_MEM(addrText, (textLen + 1) * 2, this);
				memcpy(addrText, &content[start], textLen * 2);
				addrText[textLen] = '\0';
				address.loadFromMem(addrText);

				provider->addAddrItem(address, addrType);

				VFX_FREE_MEM(addrText);
			}
		}
	}
}
#endif
VfxBool VappSmsViewerPage::isDisalbeUseDetail(void)
{
	VfxBool result = VFX_TRUE;
	VcpRichTextFormat *textFormat = m_smsBody->getFormatObject();

	for (; textFormat; textFormat = textFormat->getNext())
	{
		if (textFormat->m_type == VCP_RICH_TEXT_TYPE_TEXT)
		{
			VcpRichText *richtext= (VcpRichText*)textFormat;

			if (richtext->m_mode != VCP_TEXT_KEYWORD_NONE)
			{
				result = VFX_FALSE;
				break;
			}
		}
	}

    return result;
}

void VappSmsViewerPage::showLoadingIcon(void)
{
	if (m_loadingIcon == NULL)
	{
		VfxSize pagesize = getSize();

		VFX_OBJ_CREATE(m_loadingIcon, VcpActivityIndicator, this);
		m_loadingIcon->setAnchor(0.5,  0.5);
		m_loadingIcon->setPos(pagesize.width / 2, pagesize.height / 2);
        m_loadingIcon->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID);
		m_loadingIcon->start();
	}
}

void VappSmsViewerPage::stopLoadingIcon(void)
{
	VFX_OBJ_CLOSE(m_loadingIcon);
}


//////////////////////////////////////////////////////////////////////
//						VappSmsLiteViewer							//
//////////////////////////////////////////////////////////////////////
//VFX_IMPLEMENT_CLASS("VappSmsLiteViewer", VappSmsLiteViewer, VappMsgViewerCp);

VappSmsLiteViewer::VappSmsLiteViewer() :
	m_smsProvider(NULL),
	m_vObjectIcon(NULL),
	m_statusIcon(NULL),
	m_outerSize(0, 0),			
	m_preOuterSize(0, 0),
	m_viewerSize(0, 0),
	m_isOuterSize(VFX_TRUE),	
	m_isNeedUpdate(VFX_FALSE),
	m_resendButton(NULL),
	m_sendingIcon(NULL)
{
}

void VappSmsLiteViewer::setMsgId(VfxU32 msgId)
{
	VappMsgViewerCp::setMsgId(msgId);
	m_msgID = msgId;
	showLoading();
	m_smsProvider->read(msgId, VFX_TRUE);
}

VfxU32 VappSmsLiteViewer::getTimestamp(void)
{
    VfxU32 timestamp = srv_sms_get_msg_timestamp_utc_sec((U16)m_msgId);

	return timestamp;
}

void VappSmsLiteViewer::forceUpdate(void)
{
	onUpdate();
}

void VappSmsLiteViewer::setBounds(const VfxRect &value)
{
	if (m_isOuterSize)
	{
		m_outerSize = value.size;
	}
	else
	{
		m_isOuterSize = VFX_TRUE;
	}

	VappMsgViewerCp::setBounds(value);
}

void VappSmsLiteViewer::onInit(void)
{
	VappMsgViewerCp::onInit();

	VFX_OBJ_CREATE(m_smsProvider, VappSmsProvider, this);
	m_smsProvider->m_signalReadDone.connect(this, &VappSmsLiteViewer::onLoadSmsDone);
	m_smsProvider->m_signalMsgChanged.connect(this, &VappSmsLiteViewer::onMsgChanged);
	m_smsProvider->m_signalMsgDeleted.connect(this, &VappSmsLiteViewer::onMsgDeleted);
	m_smsProvider->m_signalReadAgain.connect(this, &VappSmsLiteViewer::onReadAgain);

	VFX_OBJ_CREATE(m_smsContent, VcpTextView, this);
	m_smsContent->setAnchor(0, 0.5);
	m_smsContent->setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, VFX_FRAME_ALIGNER_MODE_SIDE);
	m_smsContent->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
	m_smsContent->setIsUnhittable(VFX_TRUE);
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__

	VcpIconTable *iconTable = VappUcEmoticon::getEmotionTablePointer();
	VfxU32 tableSize = VappUcEmoticon::getEmotionTableSize();

	m_smsContent->setIconMode(VFX_TRUE, iconTable, (VfxU8)tableSize);
#endif
    //m_smsContent->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
}

void VappSmsLiteViewer::onDeinit()
{
	VFX_OBJ_CLOSE(m_smsProvider);
	VappMsgViewerCp::onDeinit();
}

void VappSmsLiteViewer:: onUpdate(void)
{
	VappMsgViewerCp::onUpdate();

	if (m_smsProvider->isDataValid())
	{
		//if (m_isNeedUpdateView)
		{
		updateView();
			m_isNeedUpdate = VFX_FALSE;
		}
	}
	else
	{
		setIntSize(VfxSize(0, 0));
	}

}

void VappSmsLiteViewer::updateView(void)
{

	if ((m_isNeedUpdate == VFX_FALSE) && (m_preOuterSize == m_outerSize))
	{
		setIntSize(m_viewerSize);
		return;
	}
	m_preOuterSize = m_outerSize;
	VfxSize contentSize = m_outerSize;
	VfxSize viewerSize(0, 0);
	VfxS32 contentX = 0;
	VfxS32 rightOffset = 0;
	VfxSize statusIconSize(0, 0);
	VfxSize vObjectIconSize(0, 0);
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	VfxS32 vObjectIconX = 0;
	VfxSize rightIconSize(0, 0);
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/

	VfxU32 status = m_smsProvider->getStatus();

    status &= (~SRV_SMS_STATUS_UNSUPPORTED);

	switch (status)
	{
	#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
		case SRV_SMS_STATUS_UNSENT:
		{
			srv_sms_send_status_enum send_status;

			send_status = m_smsProvider->getSendStatus();

			switch (send_status)
			{
				case SRV_SMS_SEND_FAIL:
				{
					VFX_OBJ_CLOSE(m_sendingIcon);

					if (m_resendButton == NULL)
					{
						VFX_OBJ_CREATE(m_resendButton, VcpImageButton, this);
						m_resendButton->m_signalClicked.connect(this, &VappSmsLiteViewer::onButtonClicked);
						m_resendButton->setAnchor(1.0, 0.5);
		                m_resendButton->setSize(RIGHT_ICON_SIZE, RIGHT_ICON_SIZE);
		                m_resendButton->setImage(VcpStateImage(
											IMG_ID_VAPP_SMS_RESEND_BUTTON,
											IMG_ID_VAPP_SMS_RESEND_BUTTON,
											IMG_ID_VAPP_SMS_RESEND_BUTTON,
											0));

                        srv_sms_sim_enum smsSim = m_smsProvider->getSimID();
                        mmi_sim_enum mmiSim = SRV_SMS_SMS_SIM_TO_MMI(smsSim);

                        if (!srv_sim_ctrl_is_inserted(mmiSim))
                        {
                            m_resendButton->setOpacity(0.3f);
                        }
					}

					rightIconSize = m_resendButton->getSize();
					rightOffset = rightIconSize.width + TEXT_RIGTH_ICON_OFFSET;

					if (m_statusIcon == NULL)
					{
						VFX_OBJ_CREATE(m_statusIcon, VfxImageFrame, this);
						m_statusIcon->setAnchor(0, 0.5);
					}

					m_statusIcon->setResId(IMG_ID_VAPP_SMS_SEND_FAIL);

					statusIconSize = m_statusIcon->getSize();
					contentX = statusIconSize.width + LEFT_ICON_TEXT_OFFSET;
					break;
				}

				case SRV_SMS_SEND_WAITING:
				{
					VFX_OBJ_CLOSE(m_sendingIcon);
					VFX_OBJ_CLOSE(m_resendButton);

					if (m_statusIcon == NULL)
					{
						VFX_OBJ_CREATE(m_statusIcon, VfxImageFrame, this);
						m_statusIcon->setAnchor(0, 0.5);
					}

					m_statusIcon->setResId(IMG_ID_VAPP_SMS_SEND_WAITING);

					statusIconSize = m_statusIcon->getSize();
					contentX = statusIconSize.width + LEFT_ICON_TEXT_OFFSET;
                    break;
				}

				case SRV_SMS_SEND_SENDING:
				{
					VFX_OBJ_CLOSE(m_statusIcon);
					VFX_OBJ_CLOSE(m_resendButton);

					if (m_sendingIcon == NULL)
					{
						VFX_OBJ_CREATE(m_sendingIcon, VcpActivityIndicator, this);
						m_sendingIcon->setAnchor(1.0, 0.5);
						m_sendingIcon->setSize(RIGHT_ICON_SIZE, RIGHT_ICON_SIZE);
						m_sendingIcon->start();
					}			

					rightIconSize = m_sendingIcon->getSize();
					rightOffset = rightIconSize.width + TEXT_RIGTH_ICON_OFFSET;
					break;
				}

				default:
					VFX_OBJ_CLOSE(m_sendingIcon);
					VFX_OBJ_CLOSE(m_statusIcon);
					VFX_OBJ_CLOSE(m_resendButton);
					break;
			}
			break;
		}
	#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/

		case SRV_SMS_STATUS_DRAFT:
		{
		#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
			VFX_OBJ_CLOSE(m_sendingIcon);
			VFX_OBJ_CLOSE(m_resendButton);
		#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/

			if (m_statusIcon == NULL)
			{
				VFX_OBJ_CREATE(m_statusIcon, VfxImageFrame, this);
				m_statusIcon->setAnchor(0, 0.5);
			}
			m_statusIcon->setResId(IMG_ID_VAPP_SMS_DRAFT);

			statusIconSize = m_statusIcon->getSize();
			contentX = statusIconSize.width + LEFT_ICON_TEXT_OFFSET;
			break;
		}

		default:
		{
			VFX_OBJ_CLOSE(m_statusIcon);
		#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
			VFX_OBJ_CLOSE(m_sendingIcon);
			VFX_OBJ_CLOSE(m_resendButton);
		#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
			break;
		}
	}

	VfxWString vObjectText;
	VfxWChar *contentBuff;
#ifdef __MMI_SMS_PORT_MSG__

	VfxU16 port = m_smsProvider->getDestPort();
	VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);

	if (portReg->findPort(port))
	{
		VfxImageSrc vObjectImage;

		portReg->getAppInfo(port, vObjectText, vObjectImage);

		contentBuff = (VfxWChar*)vObjectText.getBuf();

		if (m_vObjectIcon == NULL)
		{
			VFX_OBJ_CREATE(m_vObjectIcon, VfxImageFrame, this);
			m_vObjectIcon->setAnchor(0, 0.5);
		}
		m_vObjectIcon->setImgContent(vObjectImage);

		vObjectIconSize = m_vObjectIcon->getSize();
		contentX += vObjectIconSize.width;

		if (m_statusIcon)
		{
			vObjectIconX = statusIconSize.width + LEFT_ICON_ICON_OFFSET;
			contentX += LEFT_ICON_ICON_OFFSET;
		}
		else
		{
			contentX += LEFT_ICON_TEXT_OFFSET;
		}
	}
	else
#endif
	{
		contentBuff = m_smsProvider->getContent();
		VFX_OBJ_CLOSE(m_vObjectIcon);
	}
////////////////////////////////
	viewerSize.width = contentX + rightOffset;
	contentSize.width -= viewerSize.width;

	m_smsContent->setAutoResized(VFX_TRUE);
	m_smsContent->setAutoAnimate(VFX_FALSE);
	m_smsContent->setTruncateMode(VCP_TEXT_TRUNCATE_WITH_AUTO_RESIZE);
	m_smsContent->setSize(contentSize);
	m_smsContent->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
	m_smsContent->setText(contentBuff);
    m_smsContent->forceUpdate();
    if (m_smsContent->getLineCount() < 2)
    {
        m_smsContent->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
	    m_smsContent->forceUpdate();

    }

	contentSize = m_smsContent->getSize();

	if (contentSize.height > VAPP_MSG_VIEWER_LITE_MAX_HEIGHT)
	{
		contentSize.height = VAPP_MSG_VIEWER_LITE_MAX_HEIGHT;
		m_smsContent->setAutoResized(VFX_FALSE);
		m_smsContent->setTruncateMode(VCP_TEXT_TRUNCATE_MODE_END);
		m_smsContent->setSize(contentSize);
	    m_smsContent->forceUpdate();
	}

///////////////////////////////
    viewerSize.width += contentSize.width;
	viewerSize.height = contentSize.height;

	if (viewerSize.height < statusIconSize.height)
	{
		viewerSize.height = statusIconSize.height;
	}

	if (viewerSize.height < vObjectIconSize.height)
	{
		viewerSize.height = vObjectIconSize.height;
	}

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	if (viewerSize.height < rightIconSize.height)
	{
		viewerSize.height = rightIconSize.height;
	}
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
	VfxColor color = VFX_COLOR_RES(VAPP_SMS_VIEWER_TEXT_COLOR);
	m_smsContent->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, color);
	m_smsContent->setPos(contentX, (viewerSize.height / 2));

	if (m_statusIcon)
	{
		m_statusIcon->setPos(0, (viewerSize.height / 2));
	}

	if (m_vObjectIcon)
	{
		m_vObjectIcon->setPos(vObjectIconX, (viewerSize.height / 2));
	}

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	if (m_sendingIcon)
	{
		m_sendingIcon->setPos(viewerSize.width, (viewerSize.height / 2));
	}

	if (m_resendButton)
	{
		m_resendButton->setPos(viewerSize.width, (viewerSize.height / 2));
	}
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
	setIntSize(viewerSize);
	m_viewerSize = viewerSize;

	
}

void VappSmsLiteViewer::onLoadSmsDone(VfxBool result)
{
	stopLoading();
	m_isNeedUpdate = VFX_TRUE;
	onUpdate();
	setContentReady(VFX_TRUE);
}

void VappSmsLiteViewer::onMsgChanged(void)
{
	m_isNeedUpdate = VFX_TRUE;
	checkUpdate();
}

void VappSmsLiteViewer::onMsgDeleted(void)
{
	//Send Siginal to Parent
}

void VappSmsLiteViewer::onReadAgain(void)
{

	showLoading();

	m_smsProvider->read(m_msgID, VFX_FALSE);
}

void VappSmsLiteViewer::setIntSize(const VfxSize &value)
{
	m_isOuterSize = VFX_FALSE;
	setSize(value);
}

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
void VappSmsLiteViewer::onButtonClicked(VfxObject * sender, VfxId bottom_id)
{

    {
        srv_sms_sim_enum smsSim = m_smsProvider->getSimID();
        mmi_sim_enum mmiSim = SRV_SMS_SMS_SIM_TO_MMI(smsSim);

        if (!VappSmsOperator::showInfoBalloonIfNeed(mmiSim))
        {
            srv_sms_set_unsent_msg_status_ext(
            	(U16)m_msgId,
            	SRV_SMS_SEND_WAITING,
            	&VappSmsLiteViewer::onResendDone,
            	getObjHandle());
        }
    }
}

void VappSmsLiteViewer::onResendDone(srv_sms_callback_struct* callback_data)
{
	VfxObjHandle objHandle = (VfxObjHandle)callback_data->user_data;
	VappSmsLiteViewer *currViewer = (VappSmsLiteViewer*)VfxObject::handleToObject(objHandle);

	if (currViewer)
	{
		if (callback_data->result)
		{
			currViewer->checkUpdate();
		}
	}
}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */


//VFX_IMPLEMENT_CLASS("VappSmsContactProvider", VappSmsContactProvider, VappMsgContactProvider);

VappSmsContactProvider::VappSmsContactProvider() :
	m_msgID(SRV_SMS_INVALID_MSG_ID)
{

}

VfxBool VappSmsContactProvider::getContact(VappMsgContact& contact, VcpMenuPos index_ex)
{
	VfxU32 count = srv_sms_get_msg_addr_num((U16)m_msgID);
	VfxBool result = VFX_TRUE;
	VfxU32 index = index_ex.pos;

	if (index < count)
	{
		VfxWChar addrBuff[SRV_SMS_MAX_ADDR_LEN + 1];
		srv_sms_status_enum status;
		
#ifdef __SRV_SMS_DELIVERY_STATUS__
		VfxResId imageId = 0;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

		srv_sms_get_msg_multi_addr((WCHAR*)addrBuff, &status, (U16)m_msgID, (U16)index);

		contact.m_address.loadFromMem(addrBuff);

        if (srv_sms_check_ucs2_number((S8*)addrBuff))
        {
    		contact.m_type = VAPP_MSG_CONTACT_TYPE_PHONENUMBER;
        }
        else
        {
    		contact.m_type = VAPP_MSG_CONTACT_TYPE_ALPHANUMBIC;
        }
	#ifdef __SRV_SMS_DELIVERY_STATUS__

        status = (srv_sms_status_enum)(status & (~SRV_SMS_STATUS_UNSUPPORTED));

		if (count > 1)
		{
			switch (status)
			{

				case SRV_SMS_STATUS_UNSENT:
					imageId = IMG_ID_VAPP_SMS_SEND_FAIL;
					break;

				default:
					break;
			}
		}
		else
		{
			switch (status)
			{
				case SRV_SMS_STATUS_READ:
				case SRV_SMS_STATUS_UNREAD:
					imageId = IMG_ID_VAPP_SMS_RECEIVED;
					break;

				case SRV_SMS_STATUS_SENT:
					imageId = IMG_ID_VAPP_SMS_SENT;
					break;

				case SRV_SMS_STATUS_UNSENT:
				{
					srv_sms_send_status_enum sendStatus;

					sendStatus = srv_sms_get_unsent_msg_status(m_msgID);

					if (sendStatus == SRV_SMS_SEND_FAIL)
					{
						imageId = IMG_ID_VAPP_SMS_SEND_FAIL;
					}
					break;
				}

				default:
					break;
			}
		}

		contact.m_statusIcon.setResId(imageId);
	#endif
	}
	else
	{
		result = VFX_FALSE;
	}

	return result;
}

VfxU32 VappSmsContactProvider::getCount(VfxU32 group) const
{
	VfxU32 count;

	if(group > 0)
	{
		count = 0;
	}
	else
	{
		count = srv_sms_get_msg_addr_num(m_msgID);
	}

	return count;
}

VfxBool VappSmsContactProvider::isShowMemberInBar(VfxU32 group) const
{
	if (group == 0)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxBool VappSmsContactProvider::isShowRecipientList(VfxWString& causeStr)
{
	VfxBool result = VFX_TRUE;
	srv_sms_send_status_enum status;

	status = srv_sms_get_unsent_msg_status((U16)m_msgID);

	if ((status == SRV_SMS_SEND_SENDING) ||
	    (status == SRV_SMS_SEND_WAITING))
	{
	    causeStr.loadFromRes(STR_ID_VAPP_SMS_SENDING_CANNOT_OPEN);

		result = VFX_FALSE;
	}

	return result;
}

VfxBool VappSmsContactProvider::isResendFailed(void)
{
	VfxBool result = VFX_FALSE;
	srv_sms_status_enum status;

	status = srv_sms_get_msg_status((U16)m_msgID);

	if (status == SRV_SMS_STATUS_UNSENT)
	{
		result = VFX_TRUE;
	}

	return result;
}

void VappSmsContactProvider::resendFailed(void)
{
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_set_unsent_msg_status_ext(
    	(U16)m_msgID,
    	SRV_SMS_SEND_WAITING,
    	NULL,
    	NULL);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
}


//////////////////////////////////////////////////////////////////////
// 						VappSmsVObjectButton						//
//////////////////////////////////////////////////////////////////////
//VFX_IMPLEMENT_CLASS("VappSmsVObjectButton", VappSmsVObjectButton, VfxControl);
#ifdef __MMI_SMS_PORT_MSG__

VappSmsVObjectButton::VappSmsVObjectButton() :
	m_isClicked(VFX_FALSE)
{

}

void VappSmsVObjectButton::setImage(const VfxImageSrc& image)
{
	m_image->setImgContent(image);

	checkUpdate();
}

void VappSmsVObjectButton::setText(const VfxWString& text)
{
	m_text->setString(text);
	checkUpdate();
}

void VappSmsVObjectButton::onInit(void)
{
	VfxControl::onInit();

	setImgContent(VfxImageSrc(IMG_ID_VAPP_SMS_VOBJECT_BUTTON_N));
	setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

	VFX_OBJ_CREATE(m_image, VfxImageFrame, this);

	VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
	m_text->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	m_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));
}

void VappSmsVObjectButton::onUpdate(void)
{
	VfxControl::onUpdate();

	VfxSize size = getSize();
	VfxSize imageSize = m_image->getSize();
	VfxS32 textPosX = IMAGE_MARGIN + imageSize.width + TEXT_MARGIN;

	m_image->setAnchor(0, 0.5);
	m_image->setPos(IMAGE_MARGIN, size.height / 2);

	m_text->setAnchor(0, 0.5);
	m_text->setPos(textPosX, size.height / 2);
}

VfxBool VappSmsVObjectButton::onPenInput(VfxPenEvent& event)
{
	switch (event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:
		{
			m_isClicked = VFX_TRUE;
			setImgContent(VfxImageSrc(IMG_ID_VAPP_SMS_VOBJECT_BUTTON_P));
			break;
		}

		case VFX_PEN_EVENT_TYPE_UP:
		{
			if (m_isClicked)
			{
				setImgContent(VfxImageSrc(IMG_ID_VAPP_SMS_VOBJECT_BUTTON_N));
				m_signalClicked.emit();
			}
			break;
		}

		case VFX_PEN_EVENT_TYPE_MOVE:
		{
			VfxPoint relPoint = event.getRelPos(this);

			if (!containPoint(relPoint))
			{
				m_isClicked = VFX_FALSE;
				setImgContent(VfxImageSrc(IMG_ID_VAPP_SMS_VOBJECT_BUTTON_N));
			}
			break;
		}

		case VFX_PEN_EVENT_TYPE_ABORT:
		{
			m_isClicked = VFX_FALSE;
			break;
		}

		default:
		{
			break;
		}
	}

    return VFX_TRUE;
}
#endif
