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
 *  vapp_msg_use_detail.cpp
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
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "vapp_msg_use_detail.h"
#include "vcp_navi_title_bar.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_contact_def.h"
#include "vapp_sms_util.h"
#include "../xml/vfx_xml_loader.h"
#include "GlobalResDef.h"
#include "vapp_uc_gprot.h"
#include "vcui_dialer_gprot.h"
#include "vcui_phb_gprot.h"

#ifdef __MMI_SMS_COMPOSER__
    #include "vcui_sms_composer_gprot.h"
#endif

#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
#include "vcui_bookmark_gprot.h"
#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */
#ifdef __MMI_USB_SUPPORT__
#include "Vapp_usb_gprot.h"
#endif /* __MMI_USB_SUPPORT__ */

#ifdef __cplusplus
extern "C"
#endif
{
	#include "SmsSrvGprot.h"
    #include "UCMGProt.h"
	#include "UcSrvGprot.h"
	#include "EmailAppGProt.h"
	#include "Browser_api.h"
	#include "Conversions.h"
	#include "PhbSrvGprot.h"
	#include "mmi_frm_scenario_gprot.h"
	#include "Custom_phb_config.h"
	#include "Unicodexdcl.h"
	#include "NwUsabSrvGprot.h"
#ifdef __MMI_USB_SUPPORT__
    #include "USBSrvGprot.h" /* srv_usb_is_in_mass_storage_mode */
#endif /* __MMI_USB_SUPPORT__ */
}


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_SMS_DETAILS_INFO__	
#define USE_DETAILS_TITLE_NAME		VFX_WSTR("UseDetails")
#define USE_DETAILS_LIST_NAME		VFX_WSTR("UseDetailsList")

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
VappMsgUseDetailPage::VappMsgUseDetailPage() :
	m_provider(NULL),
	m_listMenu(NULL)
{
}

void VappMsgUseDetailPage::setProvider(VappMsgUseDetailProvider& provider)
{
	if (m_provider != NULL)
	{
		VFX_OBJ_CLOSE(m_provider);
	}

	VFX_OBJ_CREATE_EX(m_provider, VappMsgUseDetailProvider, this, (provider));
	m_listMenu->setContentProvider(m_provider);
}

VfxBool VappMsgUseDetailPage::addAddrItem(VfxWString& text, VappMsgAddrType type)
{
	VappMsgAddrItem addrItem(text, type);

	return addAddrItem(addrItem);
}

VfxBool VappMsgUseDetailPage::addAddrItem(VappMsgAddrItem& addrItem)
{
	if (m_provider == NULL)
	{
		VFX_OBJ_CREATE(m_provider, VappMsgUseDetailProvider, this);
		m_listMenu->setContentProvider(m_provider);
	}

	return m_provider->addAddrItem(addrItem);
}

void VappMsgUseDetailPage::onInit(void)
{
	VfxPage::onInit();

	VfxSize pageSize = getSize();

	VfxXmlLoader *loader;

	VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
	loader->loadXml(VAPP_SMS_LAYOUT_MSG_USE_DETAILS);

    VcpTitleBar *titleBar;

	titleBar = VFX_XML_FIND_OBJ(loader, USE_DETAILS_TITLE_NAME, VcpTitleBar);
    titleBar->setTitle((VfxResId)STR_GLOBAL_DETAILS);
	
	m_listMenu = VFX_XML_FIND_OBJ(loader, USE_DETAILS_LIST_NAME, VcpListMenu);
	m_listMenu->setSize(pageSize);
	m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
	m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
	m_listMenu->m_signalItemTapped.connect(this, &VappMsgUseDetailPage::onItemTapped);
	m_listMenu->m_signalCmdButtonClicked.connect(this, &VappMsgUseDetailPage::onCmdButtonClicked);

	VFX_OBJ_CLOSE(loader);

	VFX_OBJ_CREATE(m_addrOtion, VappMsgAddrOption, this);
	m_addrOtion->setInViewerPage(VFX_FALSE);
}

void VappMsgUseDetailPage::onItemTapped(VcpListMenu* listMenu, VfxU32 index)
{        
	VappMsgAddrItem& addrItem = m_provider->getAddrItem(index);

	m_addrOtion->setAddrItem(addrItem);
	m_addrOtion->show(this);
}

void VappMsgUseDetailPage::onCmdButtonClicked(VcpListMenu* listMenu, VfxU32 index)
{
	VappMsgAddrItem& addrItem = m_provider->getAddrItem(index);

	m_addrOtion->setAddrItem(addrItem);

	switch (addrItem.m_type)
    {
        case VAPP_MSG_ADDR_TYPE_PHONENUMBER:
        case VAPP_MSG_ADDR_TYPE_USSD:
        {
            m_addrOtion->editBeforeCall();
            break;
        }

        case VAPP_MSG_ADDR_TYPE_URL:
            m_addrOtion->gotoUrl();
            break;

    #ifdef __MMI_EMAIL__
        case VAPP_MSG_ADDR_TYPE_EMAIL:
            m_addrOtion->sendEmail();
            break;
    #endif /* __MMI_EMAIL__ */

        default:
            break;
    }
}

void VappMsgUseDetailPage::onPopupButtonClicked(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		m_isDialNumber = VFX_TRUE;
	}
}

void VappMsgUseDetailPage::onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if ((state == VFX_BASE_POPUP_AFTER_END_ANIMATION) && m_isDialNumber)
    {
        m_addrOtion->dialNumber(m_dialSimId);
    }
}

void VappMsgUseDetailPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
}

const VfxResId VappMsgUseDetailProvider::m_buttonIcon[VappMsgUseDetailProvider::ICON_TOTAL][VappMsgUseDetailProvider::ICON_STATE_TOTAL] = 
        {
	    #if (MMI_MAX_SIM_NUM >= 2)
            {
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N
            },
            {
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N
            },
        #if (MMI_MAX_SIM_NUM >= 3)
            {
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N
            },
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            {
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N,
                IMG_ID_VAPP_DETAIL_CALL_N
            },
        #endif
        #else
            {
                IMG_COSMOS_GEMINI_LIST_CALL_N,
                IMG_COSMOS_GEMINI_LIST_CALL_P,
                IMG_COSMOS_GEMINI_LIST_CALL_D
            },
        #endif
        #ifdef __MMI_EMAIL__       
          {
                IMG_ID_VAPP_MSG_SEND_EMAIL_N,
                IMG_ID_VAPP_MSG_SEND_EMAIL_P,
                IMG_ID_VAPP_MSG_SEND_EMAIL_D
            },
        #endif
            {
                IMG_ID_VAPP_MSG_GO_TO_URL_N,
                IMG_ID_VAPP_MSG_GO_TO_URL_P,
                IMG_ID_VAPP_MSG_GO_TO_URL_D
            }
        };

VappMsgUseDetailProvider::VappMsgUseDetailProvider() :
	m_count(0),
	m_simId(MMI_SIM1)
{
}

VappMsgUseDetailProvider::VappMsgUseDetailProvider(VappMsgUseDetailProvider& copyProvider)
{
	VfxU32 i;

	m_count = copyProvider.m_count;
	m_simId = copyProvider.m_simId;

	for (i = 0; i < m_count; i++)
	{
		m_addrItem[i] = copyProvider.m_addrItem[i];
	}
}

void VappMsgUseDetailProvider::setSimId(mmi_sim_enum simId)
{
	m_simId = simId;
}

mmi_sim_enum VappMsgUseDetailProvider::getSimId(void)
{
	return m_simId;
}

VfxBool VappMsgUseDetailProvider::addAddrItem(VfxWString& text, VappMsgAddrType type)
{
	VfxBool result = VFX_TRUE;

	if (m_count < MAX_ADDR_ITEM)
	{
		m_addrItem[m_count].m_text = text;
		m_addrItem[m_count].m_type = type;
		m_count++;
	}
	else
	{
		result = VFX_FALSE;
	}

	return result;
}

VfxBool VappMsgUseDetailProvider::addAddrItem(VappMsgAddrItem& addrItem)
{
	return addAddrItem(addrItem.m_text, addrItem.m_type);
}

VappMsgAddrItem& VappMsgUseDetailProvider::getAddrItem(VfxU32 index)
{
	return m_addrItem[index];
}

VfxBool VappMsgUseDetailProvider::getItemText(
	        VfxU32 index,
	        VcpListMenuFieldEnum fieldType,
	        VfxWString &text,
	        VcpListMenuTextColorEnum &color)
{
	VfxBool result = VFX_TRUE;

	if ((fieldType == VCP_LIST_MENU_FIELD_TEXT) && (index < m_count))
	{
		text = m_addrItem[index].m_text;
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	else
	{
		result = VFX_FALSE;
	}

	return result;
}

VfxBool VappMsgUseDetailProvider::getItemImage(
	        VfxU32 index,                    
	        VcpListMenuFieldEnum fieldType,  
	        VfxImageSrc& image) 
{
	VfxBool result = VFX_TRUE;

	if (index < m_count)
	{
		VfxU32 tpye = m_addrItem[index].m_type;
		VfxU32 iconIndex;

		switch (tpye)
		{
			case VAPP_MSG_ADDR_TYPE_PHONENUMBER:
			case VAPP_MSG_ADDR_TYPE_USSD:
				iconIndex = ICON_DIAL;

		    #if (MMI_MAX_SIM_NUM >= 2)
		        if (m_simId == MMI_SIM2)
		        {
					iconIndex = ICON_DIAL_SIM2;
		        }
			#endif
            #if (MMI_MAX_SIM_NUM >= 3)
		        if (m_simId == MMI_SIM3)
		        {
					iconIndex = ICON_DIAL_SIM3;
		        }
			#endif
            #if (MMI_MAX_SIM_NUM >= 4)
		        if (m_simId == MMI_SIM4)
		        {
					iconIndex = ICON_DIAL_SIM4;
		        }
			#endif 
				break;

        #ifdef __MMI_EMAIL__
			case VAPP_MSG_ADDR_TYPE_EMAIL:
				iconIndex = ICON_SEND_EMAIL;
				break;
        #endif /* __MMI_EMAIL__ */

			case VAPP_MSG_ADDR_TYPE_URL:
				iconIndex = ICON_GO_TO_URL;
				break;

			default:
				iconIndex = ICON_TOTAL;
				break;
        }

		if (iconIndex < ICON_TOTAL)
		{
    		VfxU32 stateIndex;

			switch (fieldType)
			{
				case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
					stateIndex = ICON_STATE_NORNAL;
					break;

				case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
					stateIndex = ICON_STATE_PRESSED;
					break;

				case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
					stateIndex = ICON_STATE_DIALBLED;
					break;

				default:
					stateIndex = ICON_STATE_TOTAL;
					break;
			}

			if (stateIndex < ICON_STATE_TOTAL)
			{
        		VfxResId imageID;

				imageID = m_buttonIcon[iconIndex][stateIndex];

        	    image.setResId(imageID);
			}
		}
        else
        {
    		result = VFX_FALSE;
        }
	}
	else
	{
		result = VFX_FALSE;
	}

	return result;
}

VfxU32 VappMsgUseDetailProvider::getCount(void) const
{
	return m_count;
}

VcpListMenuCmdStateEnum VappMsgUseDetailProvider::getItemCmdState(VfxU32 index) const
{
	return VCP_LIST_MENU_CMD_STATE_DEFAULT;
}
#endif /* __MMI_SMS_DETAILS_INFO__ */
VappMsgAddrOption::VappMsgAddrOption():m_isInViewPage(VFX_TRUE)
{
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
	m_ucAddr.addr = NULL;
#endif /*(__MMI_UNIFIED_COMPOSER__) ||(__MMI_MMS_STANDALONE_COMPOSER__)*/
}

void VappMsgAddrOption::setAddrItem(VfxWString& addr, VappMsgAddrType addrType)
{
	m_addrItem.m_text = addr;
	m_addrItem.m_type = addrType;
	checkUpdate();
}

void VappMsgAddrOption::setAddrItem(VappMsgAddrItem& addrItem)
{
	m_addrItem = addrItem;
	checkUpdate();
}

void VappMsgAddrOption::onDeinit(void)
{
	VfxControl::onDeinit();

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
	VFX_FREE_MEM(m_ucAddr.addr);
#endif /*(__MMI_UNIFIED_COMPOSER__) ||(__MMI_MMS_STANDALONE_COMPOSER__)*/
}

void VappMsgAddrOption::OnButtonClicked(VfxObject* obj, VfxId id)
{
	switch (id)
	{
		case BUTTON_EDIT_BEFORE_CALL:
			editBeforeCall();
			break;

		case BUTTON_SEND_MESSAGE:
			sendMessage();
			break;
		case BUTTON_ADD_AS_NEW_CONTACT:
			saveContact(VAPP_PHB_SAVE_CONTACT_NEW);
			break;

		case BUTTON_ADD_TO_EXISTING_CONTACT:
			saveContact(VAPP_PHB_SAVE_CONTACT_REPLACE);
			break;

		case BUTTON_GOTO_URL:
		{
		#ifdef __MMI_USB_SUPPORT__
    		if (MMI_TRUE == srv_usb_is_in_mass_storage_mode())
    		{
        		vapp_usb_unavailable_popup(0);
    		}
    		else
		#endif /* __MMI_USB_SUPPORT__ */
			{
			gotoUrl();
			}
			break;
		}

#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
		case BUTTON_SAVE_TO_BOOKMARK:
		{
		#ifdef __MMI_USB_SUPPORT__
    		if (MMI_TRUE == srv_usb_is_in_mass_storage_mode())
    		{
        		vapp_usb_unavailable_popup(0);
    		}
    		else
		#endif /* __MMI_USB_SUPPORT__ */
			{
			saveToBookmark();
			}
			break;
		}
#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */

#ifdef __MMI_EMAIL__
		case BUTTON_SEND_EMAIL:
			sendEmail();
			break;
#endif /* __MMI_EMAIL__ */

    	case BUTTON_CANCEL:
		default:
			break;
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
		#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */
/* under construction !*/
        #ifdef __MMI_EMAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_EMAIL__ */
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
mmi_ret VappMsgAddrOption::onCuiProc(mmi_event_struct *evt)
{
	mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;

	switch(evt->evt_id)
    {
		case EVT_ID_CUI_PHB_SAVE_RESULT:
			vcui_phb_contact_saver_close(senderId);
			break;

	#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
		case EVT_ID_VCUI_BKM_ADD_BKM_CLOSE:
			vcui_bkm_add_bkm_close(senderId);
			break;
	#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */

        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            vcui_dialer_close(senderId);
            break;

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
		case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
			vcui_unifiedcomposer_close(senderId);
			break;
#endif /*(__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/
#ifdef __MMI_SMS_COMPOSER__
        case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
        {
            /* just close it */
            VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
            vcui_sms_composer_close(ucEvt->sender_id);        
            break;
        }
#endif /*__MMI_SMS_COMPOSER__*/
		default:
			break;
	}

    return MMI_RET_OK;
}
void VappMsgAddrOption::setInViewerPage(VfxBool isInViewerPage)
{
	m_isInViewPage = isInViewerPage;
}

void VappMsgAddrOption::show(VfxPage *page)
{
	if ((m_addrItem.m_type == VAPP_MSG_ADDR_TYPE_NONE) ||
		(m_addrItem.m_text.isEmpty()))
	{
		return;
	}

	if (m_addrItem.m_type == VAPP_MSG_ADDR_TYPE_USSD)
	{
		editBeforeCall();
	}
	else
	{
		VFX_OBJ_CREATE(m_cmdPopup, VcpCommandPopup, page);
	    m_cmdPopup->m_signalButtonClicked.connect(this, &VappMsgAddrOption::OnButtonClicked);
	    //m_cmdPopup->m_signalPopupState.connect(this, &VappMsgAddrOption::onPopupStateChanged);

		m_cmdPopup->setText(m_addrItem.m_text);

		switch (m_addrItem.m_type)
		{
			case VAPP_MSG_ADDR_TYPE_PHONENUMBER:
				if (m_isInViewPage)
				{
				    m_cmdPopup->addItem(BUTTON_EDIT_BEFORE_CALL, (VfxResId)STR_ID_VAPP_SMS_EDIT_BEFORE_CALL);
				}
				m_cmdPopup->addItem(BUTTON_SEND_MESSAGE, (VfxResId)STR_GLOBAL_SEND_MESSAGE);
				m_cmdPopup->addItem(BUTTON_ADD_AS_NEW_CONTACT, (VfxResId)VAPP_PHB_STR_CREATE_NEW_CONTACT);
				m_cmdPopup->addItem(BUTTON_ADD_TO_EXISTING_CONTACT, (VfxResId)VAPP_PHB_STR_ADD_TO_EXISTING_CONTACT);
				break;

			case VAPP_MSG_ADDR_TYPE_URL:
				m_cmdPopup->addItem(BUTTON_GOTO_URL, (VfxResId)STR_GLOBAL_GO_TO_URL);
			#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
				m_cmdPopup->addItem(BUTTON_SAVE_TO_BOOKMARK, (VfxResId)STR_ID_VAPP_SMS_SAVE_TO_BOOKMARKS);
			#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */
				break;

			case VAPP_MSG_ADDR_TYPE_EMAIL:
            #ifdef __MMI_EMAIL__
				m_cmdPopup->addItem(BUTTON_SEND_EMAIL, (VfxResId)STR_ID_VAPP_SMS_SEND_EMAIL);
            #endif /* __MMI_EMAIL__ */
				m_cmdPopup->addItem(BUTTON_ADD_AS_NEW_CONTACT, (VfxResId)VAPP_PHB_STR_CREATE_NEW_CONTACT);
				m_cmdPopup->addItem(BUTTON_ADD_TO_EXISTING_CONTACT, (VfxResId)VAPP_PHB_STR_ADD_TO_EXISTING_CONTACT);
				break;

			default:
				break;
		}

		m_cmdPopup->addItem(BUTTON_CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);

		m_cmdPopup->setAutoDestory(VFX_TRUE);
		m_cmdPopup->show(VFX_TRUE);
	}
}

void VappMsgAddrOption::dialNumber(mmi_sim_enum simId)
{
	VfxWChar *destNum;
	const VfxWChar *srcNum = m_addrItem.m_text.getBuf();
	VfxU32 buffLen = vfx_sys_wcslen(srcNum);

	VFX_ALLOC_MEM(destNum, (buffLen + 1) * sizeof(VfxWChar), this);
	removePhoneNumberSeparator(destNum, srcNum);

    mmi_ucm_make_call_para_struct param;

    mmi_ucm_init_call_para(&param);

	srv_ucm_call_type_enum call_type[] = 
		{
			SRV_UCM_VOICE_CALL_TYPE,
		#if (MMI_MAX_SIM_NUM >= 2)
			SRV_UCM_VOICE_CALL_TYPE_SIM2,
		#if (MMI_MAX_SIM_NUM >= 3)
			SRV_UCM_VOICE_CALL_TYPE_SIM3,
		#if (MMI_MAX_SIM_NUM >= 4)
			SRV_UCM_VOICE_CALL_TYPE_SIM4
		#endif
		#endif
		#endif
		};
	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(simId);
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(sim_id);
	param.dial_type = call_type[sim_index];

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
	#endif


    param.ucs2_num_uri = (U16*)destNum;
	mmi_ucm_call_launch(0, &param);

	VFX_FREE_MEM(destNum);
}

void VappMsgAddrOption::editBeforeCall(void)
{
    mmi_id groupId = VfxMainScr::findMainScr(this)->getApp()->getGroupId();
	mmi_id cuiId;

    cuiId = vcui_dialer_create_ex(groupId, VCUI_DIALER_TYPE_CLASSIC);

    if (cuiId != GRP_ID_INVALID)
	{
		mmi_frm_group_set_caller_proc(cuiId, &VappMsgAddrOption::onCuiProc, NULL);

		VfxWChar *destNum;
		const VfxWChar *srcNum = m_addrItem.m_text.getBuf();
		VfxU32 buffLen = vfx_sys_wcslen(srcNum);
		VfxWString dialString;

		VFX_ALLOC_MEM(destNum, (buffLen + 1) * sizeof(VfxWChar), this);

		removePhoneNumberSeparator(destNum, srcNum);
		dialString.loadFromMem(destNum);

		VFX_FREE_MEM(destNum);

		vcui_dialer_set_dial_string(cuiId, dialString);
		vcui_dialer_run(cuiId);
	}
}

void VappMsgAddrOption::saveContact(vcui_phb_save_contact_type_enum tpye)
{
    mmi_id groupId = VfxMainScr::findMainScr(this)->getApp()->getGroupId();
	mmi_id cuiId = vcui_phb_contact_saver_create(groupId);

    if (cuiId != GRP_ID_INVALID)
	{
		mmi_frm_group_set_caller_proc(cuiId, &VappMsgAddrOption::onCuiProc, NULL);
		vcui_phb_contact_saver_set_type(cuiId, tpye);

		VfxWChar *addrBuff = (VfxWChar*)m_addrItem.m_text.getBuf();
		VfxU32 addrLen = m_addrItem.m_text.getLength();

		switch (m_addrItem.m_type)
		{
			case VAPP_MSG_ADDR_TYPE_PHONENUMBER:
				vcui_phb_contact_saver_set_number(cuiId, addrBuff, addrLen);
				break;

			case VAPP_MSG_ADDR_TYPE_EMAIL:
				vcui_phb_contact_saver_set_email(cuiId, addrBuff, addrLen);
				break;

			default:
				break;
		}

		vcui_phb_contact_saver_run(cuiId);
	}
}

void VappMsgAddrOption::gotoUrl(void)
{
#ifdef BROWSER_SUPPORT
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)m_addrItem.m_text.getBuf());
#endif /* BROWSER_SUPPORT */
}

#ifdef __MMI_EMAIL__
void VappMsgAddrOption::sendEmail(void)
{
	mmi_email_app_send_to((S8*)m_addrItem.m_text.getBuf());
}
#endif /* __MMI_EMAIL__ */

#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
void VappMsgAddrOption::saveToBookmark(void)
{
	mmi_id groupId = VfxMainScr::findMainScr(this)->getApp()->getGroupId();
    mmi_id cuiId = vcui_bkm_add_bkm_create(groupId);

    if (cuiId != GRP_ID_INVALID)
    {
		mmi_frm_group_set_caller_proc(cuiId, &VappMsgAddrOption::onCuiProc, NULL);

		VfxChar *utf8Buff;
		VfxU32 utf8BuffSize = (m_addrItem.m_text.getLength() * 3) / 2;
	
		VFX_ALLOC_MEM(utf8Buff, utf8BuffSize, this);

		mmi_chset_ucs2_to_utf8_string((U8*)utf8Buff, utf8BuffSize, (U8*)m_addrItem.m_text.getBuf());
		vcui_bkm_add_bkm_run(cuiId, (U8*)utf8Buff);

		VFX_FREE_MEM(utf8Buff);
    }
}
#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */

void VappMsgAddrOption::sendMessage(void)
{
	VfxWChar *destNum;
	const VfxWChar *srcNum = m_addrItem.m_text.getBuf();
	VfxU32 buffLen = vfx_sys_wcslen(srcNum);
	VFX_ALLOC_MEM(destNum, (buffLen + 1) * sizeof(VfxWChar), this);
	removePhoneNumberSeparator(destNum, srcNum);

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
	VappUcEntryStruct ucData;

	memset(&ucData, 0, sizeof(VappUcEntryStruct));

	ucData.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
	ucData.info_type = SRV_UC_INFO_TYPE_SMS;
	ucData.sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;

	VFX_FREE_MEM(m_ucAddr.addr);


	m_ucAddr.next = NULL;
	m_ucAddr.previous = NULL;
	m_ucAddr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
	m_ucAddr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
	m_ucAddr.addr = (kal_uint8*)destNum;

	ucData.addr = &m_ucAddr;
	ucData.addr_num = 1;
	ucData.msg_id = SRV_SMS_INVALID_MSG_ID;

	ucData.type = SRV_UC_STATE_WRITE_NEW_MSG;
	ucData.operation = UC_OPERATION_WRITE_NEW_MSG;

    mmi_id groupId = VfxMainScr::findMainScr(this)->getApp()->getGroupId();
	mmi_id cuiId = vcui_unifiedcomposer_create(groupId, &ucData);

    if (cuiId != GRP_ID_INVALID)
	{
		mmi_frm_group_set_caller_proc(cuiId, &VappMsgAddrOption::onCuiProc, NULL);
		vcui_unifiedcomposer_run(cuiId);
	}
#endif /*(__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/

#ifdef __MMI_SMS_COMPOSER__
    mmi_id smsComposerCui = 0;
    VcuiSmsComposerEntryStruct *entryData;
    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );

    // set address
    VcuiSmsComposerAddrStruct address;
    address.next = NULL;
    address.previous = NULL;
    address.type = VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
    address.addr = destNum;  
    entryData->addr_num = 1;
    entryData->addr = &address;

    // set text
    //entryData->text_buffer = (VfxChar *)m_shareUrl;
    //entryData->text_num = mmi_ucs2strlen((CHAR*)m_shareUrl);
    
	
	// set operation method to a existed msg, only for message app internal use
	//entryData->msg_id = msgId;
	entryData->operation = VCUI_SMS_COMPOSER_OPERATION_NEW;

    mmi_id groupId = VfxMainScr::findMainScr(this)->getApp()->getGroupId();
    smsComposerCui = vcui_sms_composer_create(groupId);
    if(smsComposerCui !=  GRP_ID_INVALID)
    {
        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
        vfxSetCuiCallerScr(smsComposerCui, VfxMainScr::findMainScr(this));
        vcui_sms_composer_run(smsComposerCui);
    }
    VFX_FREE_MEM(entryData);
#endif /* __MMI_SMS_COMPOSER__ */

}

void VappMsgAddrOption::removePhoneNumberSeparator(VfxWChar* dest, const VfxWChar* src)
{
	if (!dest || !src)
	{
		return;
	}

	const VfxWChar *tempSrc = src;
	VfxWChar *tempDest = dest;

	while (*tempSrc != '\0')
	{
		switch (*tempSrc)
		{
			case '-':
			case '(':
			case ')':
			case ' ':
				break;

			default:
				*tempDest = *tempSrc;
				tempDest++;
				break;
	
		}

		tempSrc++;
	}

	*tempDest = '\0';
}

