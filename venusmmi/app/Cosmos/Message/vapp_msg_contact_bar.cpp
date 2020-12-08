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
 *  vapp_msg_contact_bar.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "vapp_msg_contact_bar.h"
#include "FileMgrSrvGprot.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "mmi_rp_srv_phb_def.h"
#include "../xml/vfx_xml_loader.h"
#include "vcui_phb_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_vapp_contact_def.h"
#include "CustVenusThemeRes.h"
#include "FileMgrSrvGProt.h"

#ifdef __cplusplus
extern "C"
#endif
{
	#include "UMSrvGprot.h"
	#include "PhbSrvGprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define PORTTRAIT_BG_FRAME_NAME		VFX_WSTR("portraitBgFrm")
#define PORTTRAIT_FRAME_NAME		VFX_WSTR("portraitFrm")
#define PORTTRAIT_FG_FRAME_NAME		VFX_WSTR("portraitFgFrm")
#define STATUS_FRAME_NAME			VFX_WSTR("statusFrm")
#define RIGHT_FRAME_1_NAME			VFX_WSTR("rightFrm1")
#define RIGHT_FRAME_2_NAME			VFX_WSTR("rightFrm2")
#define SINGLE_ADDR_FRAME_NAME		VFX_WSTR("singleAddrFrm")
#define GROUP_ADDR_FRAME_NAME		VFX_WSTR("groupAddrFrm")


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMsgContactBar", VappMsgContactBar, VfxControl);

VappMsgContactBar::VappMsgContactBar() :
	m_isLayoutCreated(VFX_FALSE),
	m_isGroup(VFX_FALSE),
	m_isOriGroup(VFX_FALSE),
	m_isLiteMode(VFX_FALSE),
	m_isHitPortrait(VFX_FALSE),
	m_isHitAddr(VFX_FALSE),
	m_isSaveEnabled(VFX_FALSE),
	m_isHitAddrEnabled(VFX_FALSE),
	m_isDataReady(VFX_FALSE),
	m_mode(VAPP_MSG_BAR_MODE_DEFAULT)	
{
}
void VappMsgContactBar::setLiteMode(VfxBool mode)
{
    m_isLiteMode = mode;
}

void VappMsgContactBar::setContact(VfxWString &contact, VappMsgContactEnum type)
{
	VfxImageSrc statusIcon;

	m_contact.m_address = contact;
	m_contact.m_type = type;
	m_contact.m_statusIcon = statusIcon;

	m_isGroup = VFX_FALSE;
  m_isDataReady = VFX_TRUE;
	checkUpdate();
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappMsgContactBar::setContact(VappMsgContactProvider* provider)
{
	m_provider = provider;

	if (provider)
	{
        //provider->m_signalUpdate.connect(this, &VappMsgContactBar::onProviderUpdate);

		if (provider->getCount(0) > 1)
		{
			m_isGroup = VFX_TRUE;
		}
		else
		{
			m_isGroup = VFX_FALSE;

			VfxU32 groupCount = provider->getGroupCount();

			//if other groups have member, we will use group style
			for (VfxU32 i = 1; i < groupCount; i++)
			{
				if (provider->getCount(i) > 0)
				{
					m_isGroup = VFX_TRUE;
					break;
				}
			}

			if (!m_isGroup)
			{
				provider->getContact(m_contact);
			}
		}
	}
	else
	{
		m_isGroup = VFX_FALSE;
	}
	m_isDataReady = VFX_TRUE;
	checkUpdate();
}

void VappMsgContactBar::setStatusIcon(const VfxImageSrc& image)
{
	m_contact.m_statusIcon = image;

	checkUpdate();
}

void VappMsgContactBar::setRightIcon(const VfxImageSrc& image)
{
	m_rightIcon1 = image;
	checkUpdate();
}

void VappMsgContactBar::setRightIcon(const VfxImageSrc& image1, const VfxImageSrc& image2)
{
	m_rightIcon1 = image1;
	m_rightIcon2 = image2;
	checkUpdate();
}

void VappMsgContactBar::setMode(VappMsgContactBarModeEnum mode)
{
    m_mode = mode;

    checkUpdate();
}


S32 VappMsgContactBar::getShadowHeight(void)
{
	S32 shadowHeight = mmi_res_get_theme_integer(VAPP_MSG_CONTACTBAR_SHADOW_HEIGHT);
	return shadowHeight;
}

void VappMsgContactBar::onInit(void)
{
	VfxControl::onInit();

    mmi_frm_cb_reg_event(EVT_ID_PHB_ADD_CONTACT, &VappMsgContactBar::onPhbContactChanged, this);
    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, &VappMsgContactBar::onPhbContactChanged, this);
	mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappMsgContactBar::onPhbContactChanged, this);

	VfxXmlLoader *loader;

	VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
	loader->loadXml(VAPP_SMS_LAYOUT_MSG_CONTACT_BAR);

	setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_CONTACT_BAR_BG));

	m_portraitBgFrame = VFX_XML_FIND_OBJ(loader, PORTTRAIT_BG_FRAME_NAME, VfxFrame);
	m_portraitFrame = VFX_XML_FIND_OBJ(loader, PORTTRAIT_FRAME_NAME, VfxFrame);
	m_portraitFgFrame = VFX_XML_FIND_OBJ(loader, PORTTRAIT_FG_FRAME_NAME, VfxFrame);
	m_statusFrame = VFX_XML_FIND_OBJ(loader, STATUS_FRAME_NAME, VfxFrame);

	m_rightFrame1 = VFX_XML_FIND_OBJ(loader, RIGHT_FRAME_1_NAME, VfxImageFrame);
	m_rightFrame1->setAlignParent(VFX_FRAME_ALIGNER_SIDE_TOP, VFX_FRAME_ALIGNER_MODE_MID);
	m_rightFrame1->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_MID);
	m_rightFrame1->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);

	m_rightFrame2 = VFX_XML_FIND_OBJ(loader, RIGHT_FRAME_2_NAME, VfxImageFrame);

    VfxTextFrame *addrFrame;

	addrFrame = VFX_XML_FIND_OBJ(loader, SINGLE_ADDR_FRAME_NAME, VfxTextFrame);
    m_singlePos = addrFrame->getPos();

	addrFrame = VFX_XML_FIND_OBJ(loader, GROUP_ADDR_FRAME_NAME, VfxTextFrame);
    m_groupPos = addrFrame->getPos();

	VFX_OBJ_CLOSE(loader);

	VfxFontDesc addrfont(VFX_FONT_DESC_VF_SIZE(ADDR_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_9);

	VFX_OBJ_CREATE(m_addrFrame, VfxTextFrame, this);
	m_addrFrame->setFont(addrfont);
	m_addrFrame->setAnchor(0, 0.5);

    m_signalBoundsChanged.connect(this, &VappMsgContactBar::onBoundChanged);
}

void VappMsgContactBar::onDeinit(void)
{
	m_signalDeinit.emit();
    mmi_frm_cb_dereg_event(EVT_ID_PHB_ADD_CONTACT, &VappMsgContactBar::onPhbContactChanged, this);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_UPD_CONTACT, &VappMsgContactBar::onPhbContactChanged, this);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappMsgContactBar::onPhbContactChanged, this);
	VfxControl::onDeinit();
}

void VappMsgContactBar::onUpdate(void)
{
	VfxControl::onUpdate();
	if (VFX_FALSE == m_isDataReady)
		return;
	if (m_isLayoutCreated && (m_isGroup != m_isOriGroup))
	{
		m_isLayoutCreated = VFX_FALSE;
	}

	m_isOriGroup = m_isGroup;

	if (!m_isLayoutCreated)
	{
		if (m_isGroup)
		{
			createGroupContactLayout();
		}
		else
		{
			createSingleContactLayout();
		}

		m_isLayoutCreated = VFX_TRUE;
	}

    VfxWString addrString;

	if (m_isGroup)
    {
        m_isHitAddrEnabled = VFX_TRUE;

        getGroupContactString(addrString);
    }
    else
	{
        if (m_mode == VAPP_MSG_BAR_MODE_SHOW_LIST_ALWAYS)
        {
            m_isHitAddrEnabled = VFX_TRUE;
        }
        else
        {
            m_isHitAddrEnabled = VFX_FALSE;
        }
    	drawPortrait();

        getSingleContactString(addrString);
    }

    drawRightIcon();
    drawAddressField(addrString);
}

void VappMsgContactBar::onBoundChanged(VfxFrame* frame, const VfxRect& rect)
{
	portraitPenUpEffect();
    checkUpdate();
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappMsgContactBar::createSingleContactLayout(void)
{
	m_portraitBgFrame->setHidden(VFX_FALSE);
	m_portraitBgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_CONTACT_PORTRAIT_BG));

	m_portraitFrame->setHidden(VFX_FALSE);

	m_portraitFgFrame->setHidden(VFX_FALSE);
	m_portraitFgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_CONTACT_PORTRAIT_FG));

	m_addrFrame->setPos(m_singlePos);
}

void VappMsgContactBar::createGroupContactLayout(void)
{
	m_portraitBgFrame->setHidden(VFX_TRUE);
	m_portraitFrame->setHidden(VFX_TRUE);
	m_portraitFgFrame->setHidden(VFX_TRUE);
	m_statusFrame->setHidden(VFX_TRUE);

	m_addrFrame->setPos(m_groupPos);
}

void VappMsgContactBar::drawPortrait(void)
{
	VfxImageSrc image;

	VappMsgContactProvider::getContactImage(image, m_contact.m_address, m_contact.m_type);

  VfxImageSrc imageReset;
  m_portraitFrame->setImgContent(imageReset);
  
	m_portraitFrame->setImgContent(image);

	if (m_contact.m_statusIcon.isNull())
	{
		m_statusFrame->setHidden(VFX_TRUE);
	}
	else
	{
		m_statusFrame->setHidden(VFX_FALSE);
		m_statusFrame->setImgContent(m_contact.m_statusIcon);
	}
}

void VappMsgContactBar::drawRightIcon(void)
{
	if (m_rightIcon1.isNull())
	{
		m_rightFrame1->setHidden(VFX_TRUE);
	}
	else
	{
		m_rightFrame1->setHidden(VFX_FALSE);
		m_rightFrame1->setImgContent(m_rightIcon1);
	}

	if (m_rightIcon2.isNull())
	{
		m_rightFrame2->setHidden(VFX_TRUE);
	}
	else
	{
		VfxS32 rightX = m_rightFrame1->getPos().x - m_rightFrame1->getSize().width - ICON_ICON_OFFSET;
		VfxS32 rightY = m_rightFrame2->getPos().y;

		m_rightFrame2->setPos(rightX, rightY);
		m_rightFrame2->setHidden(VFX_FALSE);
		m_rightFrame2->setImgContent(m_rightIcon2);
	}
}

void VappMsgContactBar::drawAddressField(VfxWString& addrStr)
{
    VfxSize newSize = m_addrFrame->getSize();
	VfxS32 rightX = getContactFieldRightX();
    VfxS32 maxWidth;

	maxWidth = rightX - m_addrFrame->getPos().x;
    newSize.width = maxWidth;

    m_addrFrame->checkUpdate();
    m_addrFrame->setSize(newSize);
    m_addrFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
	m_addrFrame->setString(addrStr);
    m_addrFrame->forceUpdate();

    newSize = m_addrFrame->getSize();

    if (newSize.width > maxWidth)
    {
        newSize.width = maxWidth;

        m_addrFrame->setSize(newSize);
	    m_addrFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }
}

VfxS32 VappMsgContactBar::getContactFieldRightX(void)
{
	VfxS32 addrRightX;

	if (m_rightIcon1.isNull())
	{
		addrRightX = m_rightFrame1->getPos().x;
	}
	else
	{
		addrRightX = m_rightFrame1->getPos().x - m_rightFrame1->getSize().width - TEXT_ICON_OFFSET;

		if (!m_rightIcon2.isNull())
		{
			addrRightX -= (m_rightFrame2->getSize().width + ICON_ICON_OFFSET);
		}
	}

	return addrRightX;
}

void VappMsgContactBar::getSingleContactString(VfxWString& singleStr)
{
	if (m_contact.m_address.isEmpty())
	{
		m_isSaveEnabled = VFX_FALSE;

		VappMsgContactProvider::getEmptyContactName(singleStr, m_contact.m_type);
	}
	else
	{
		m_isSaveEnabled = VappMsgContactProvider::getContactName(
							singleStr, m_contact.m_address, m_contact.m_type);
	}

	if (singleStr.isEmpty())
	{
		singleStr = m_contact.m_address;
	}
}

void VappMsgContactBar::getGroupContactString(VfxWString& groupStr)
{
	VfxU32 grpCount = m_provider->getGroupCount();
	VfxBool isFristGroup = VFX_TRUE;

	VFX_ASSERT(grpCount > 0);

	for (VfxU32 i = 0; i < grpCount; i++)
	{
		VfxU32 memberCount = m_provider->getCount(i);

		if (memberCount > 0)
		{
			/* Add a separator between groups */
			if (isFristGroup)
			{
				isFristGroup = VFX_FALSE;
			}
			else
			{
				groupStr += VFX_WSTR(", ");
			}

			VfxWString groupPrefix;

			m_provider->getGroupPrefix(i, groupPrefix);

			groupStr += groupPrefix;

			if (m_provider->isShowMemberInBar(i))
			{
				for (VfxU32 j = 0; j < memberCount; j++)
				{
					VappMsgContact contact;
					VfxWString name;

					if (j > 0)
					{
						groupStr += VFX_WSTR(", ");
					}

					m_provider->getContact(contact, VcpMenuPos(i, j));

					VappMsgContactProvider::getContactPhbName(name, contact.m_address, contact.m_type);

					if (name.isEmpty())
					{
						groupStr += contact.m_address;
					}
					else
					{
						groupStr += name;
					}
				}
			}
		}
	}
}

VfxBool VappMsgContactBar::onPenInput(VfxPenEvent& event)
{
	if (m_isLiteMode)
		return VFX_TRUE;
	switch (event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:
		{
			VfxPoint relPoint = event.getRelPos(this);

			m_isHitAddr = VFX_FALSE;
			m_isHitPortrait = VFX_FALSE;

	        if (m_isHitAddrEnabled)
	        {
				m_isHitAddr = isHitFrame(m_addrFrame, event);
	        }

	        if (m_isSaveEnabled)
	        {
				m_isHitPortrait = isHitFrame(m_portraitFrame, event);

				if (m_isHitPortrait)
				{
					portraitPenDownEffect();
				}
			}
			break;
		}

		case VFX_PEN_EVENT_TYPE_UP:
		{
			if (m_isHitAddr)
			{
				m_isHitAddr = VFX_FALSE;

				onClickAddressField();
			}

			if (m_isHitPortrait)
			{
				m_isHitPortrait = VFX_FALSE;

				portraitPenUpEffect();

				onClickPortrait();
			}
			break;
		}

		case VFX_PEN_EVENT_TYPE_MOVE:
		{
			if (m_isHitAddr)
			{
				m_isHitAddr = isHitFrame(m_addrFrame, event);
			}

			if (m_isHitPortrait)
	        {
				m_isHitPortrait = isHitFrame(m_portraitFrame, event);

	        	if (!m_isHitPortrait)
	        	{
					portraitPenUpEffect();
			    }
 	        }
			break;
		}

		case VFX_PEN_EVENT_TYPE_ABORT:
		{
			m_isHitAddr = VFX_FALSE;
			m_isHitPortrait = VFX_FALSE;
			break;
		}

		default:
		{
			break;
		}
	}

    return VFX_TRUE;
}

void VappMsgContactBar::portraitPenDownEffect(void)
{
	m_portraitBgFrame->setOpacity(0.5f);
    m_portraitFrame->setOpacity(0.5f);
    m_portraitFgFrame->setOpacity(0.5f);

	if (m_statusFrame)
	{
    	m_statusFrame->setOpacity(0.5f);
	}
}

void VappMsgContactBar::portraitPenUpEffect(void)
{
    m_portraitBgFrame->setOpacity(1.0f);
    m_portraitFrame->setOpacity(1.0f);
   	m_portraitFgFrame->setOpacity(1.0f);

    if (m_statusFrame)
    {
    	m_statusFrame->setOpacity(1.0f);
	}
}

VfxBool VappMsgContactBar::isHitFrame(VfxFrame* frame, VfxPenEvent& event)
{
	VfxBool result;
	VfxPoint relPoint = event.getRelPos(this);

	relPoint = frame->convertPointFrom(relPoint, this);
	result = frame->containPoint(relPoint);

	return result;
}

void VappMsgContactBar::onClickPortrait(void)
{
	VcpCommandPopup *contactMenu;

	VFX_OBJ_CREATE(contactMenu, VcpCommandPopup, this);

	contactMenu->m_signalButtonClicked.connect(this, &VappMsgContactBar::onPopupButtonClicked);
	contactMenu->m_signalPopupState.connect(this, &VappMsgContactBar::onPopupStateChanged);
	contactMenu->setText(m_contact.m_address);
	contactMenu->addItem(BUTTON_ADD_NEW, (VfxResId)VAPP_PHB_STR_CREATE_NEW_CONTACT);
	contactMenu->addItem(BUTTON_ADD_EXIST, (VfxResId)VAPP_PHB_STR_ADD_TO_EXISTING_CONTACT);
	contactMenu->addItem(BUTTON_CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
	contactMenu->setAutoDestory(VFX_TRUE);
	contactMenu->show(VFX_TRUE);
}

void VappMsgContactBar::onPopupButtonClicked(VfxObject* obj, VfxId id)
{
	m_buttonId = id;
}

void VappMsgContactBar::onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
		switch (m_buttonId)
		{
			case BUTTON_ADD_NEW:
			{
				saveContact(VAPP_PHB_SAVE_CONTACT_NEW);
				break;
			}

			case BUTTON_ADD_EXIST:
				saveContact(VAPP_PHB_SAVE_CONTACT_REPLACE);
				break;

			case BUTTON_CANCEL:
			default:
				break;
		}
    }
}

void VappMsgContactBar::saveContact(vcui_phb_save_contact_type_enum tpye)
{
    mmi_id groupId = VfxMainScr::findMainScr(this)->getApp()->getGroupId();
	mmi_id cuiId = vcui_phb_contact_saver_create(groupId);

	if (cuiId != GRP_ID_INVALID)
	{
		VfxWChar *addrBuff = (VfxWChar*)m_contact.m_address.getBuf();
		VfxU32 addrLen = m_contact.m_address.getLength(); 

		mmi_frm_group_set_caller_proc(cuiId, &VappMsgContactBar::onCuiProc, NULL);

		vcui_phb_contact_saver_set_type(cuiId, tpye);

		switch (m_contact.m_type)
		{
			case VAPP_MSG_CONTACT_TYPE_PHONENUMBER:
				vcui_phb_contact_saver_set_number(cuiId, addrBuff, addrLen);
				break;

			case VAPP_MSG_CONTACT_TYPE_EMAIL:
				vcui_phb_contact_saver_set_email(cuiId, addrBuff, addrLen);
				break;

			case VAPP_MSG_CONTACT_TYPE_SNS_NICKNAME:
				break;

			default:
				break;
		}

		vcui_phb_contact_saver_run(cuiId);
	}
}

void VappMsgContactBar::onClickAddressField(void)
{
    if (m_provider == NULL)
    {
        return;
    }

    VfxWString causeStr;

    if (m_provider->isShowRecipientList(causeStr))
    {
    	VfxMainScr *mainScr;

    	mainScr = VfxMainScr::findMainScr(this);

    	VappMsgContactListPage *page;

    	VFX_OBJ_CREATE_EX(page, VappMsgContactListPage, mainScr, (this));
    	page->setProvider(m_provider);
        mainScr->pushPage('Cont', page);
    }
    else
    {
        if (!causeStr.isEmpty())
        {
    		VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);

    		balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, causeStr);
        }
    }
}

mmi_ret VappMsgContactBar::onPhbContactChanged(mmi_event_struct *param)
{
    VappMsgContactBar *currBar = (VappMsgContactBar*)param->user_data;

	currBar->checkUpdate();

    return MMI_RET_OK;
}

mmi_ret VappMsgContactBar::onCuiProc(mmi_event_struct *evt)
{
	mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;

	switch(evt->evt_id)
    {
		case EVT_ID_CUI_PHB_SAVE_RESULT:
			vcui_phb_contact_saver_close(senderId);
			break;

		default:
			break;
	}

    return MMI_RET_OK;
}
void VappMsgContactBar::onRotate()
{
	portraitPenUpEffect();
}


//---------------------VappMsgContactProvider-------------------//
//VFX_IMPLEMENT_CLASS("VappMsgContactProvider", VappMsgContactProvider, VfxObject);

VfxBool VappMsgContactProvider::getContactName(
			VfxWString& name,
			VfxWString& address,
			VappMsgContactEnum type)
{
	VfxBool isNeedSaved = VFX_FALSE;

	if (address.isEmpty())
	{
		name.setEmpty();
	}
	else
	{
		if (type == VAPP_MSG_CONTACT_TYPE_ALPHANUMBIC)
		{
			name.setEmpty();
		}
		else
		{
			VfxBool isExisted;

			isExisted = getContactPhbName(name, address, type);

			if (!isExisted)
			{
				isNeedSaved = VFX_TRUE;
			}
			else
			{
                if (name.isEmpty())
                    name.loadFromRes(STR_GLOBAL_UNNAMED);
			}
		}
	}

	return isNeedSaved;
}

VfxBool VappMsgContactProvider::getContactPhbName(
			VfxWString& name,
			VfxWString& address,
			VappMsgContactEnum type)
{
	VfxBool isExisted = VFX_FALSE;
	VfxWChar nameBuff[MMI_PHB_NAME_LENGTH + 1];
	VfxWChar *addrBuff = (VfxWChar*)address.getBuf();

	switch (type)
	{
		case VAPP_MSG_CONTACT_TYPE_PHONENUMBER:
		{		
			isExisted = (srv_phb_get_name_by_number(
									(U16*)addrBuff,
									(U16*)nameBuff,
									MMI_PHB_NAME_LENGTH)? VFX_TRUE: VFX_FALSE);
			break;
		}


		default:
	    	break;
	}

	if (isExisted)
	{
		name.loadFromMem(nameBuff);
	}
	else
	{
		name.setEmpty();
	}

	return isExisted;
}

void VappMsgContactProvider::getContactImage(
		VfxImageSrc& image,
		VfxWString& address,
		VappMsgContactEnum type)
{
	VfxWChar imgPath[SRV_FMGR_PATH_MAX_LEN + 1];
	VfxU16 storeIndex;
	VfxU16 imageID;
	VfxU16 resType = 0;
	VfxWString name;
	VfxBool isStored = VFX_FALSE;

	getContactPhbName(name, address, type);

	if (type == VAPP_MSG_CONTACT_TYPE_PHONENUMBER)
	{
		isStored = (srv_phb_get_store_index_by_number((U16*)address.getBuf(), &storeIndex)? VFX_TRUE: VFX_FALSE);
		if (isStored)
		{
			srv_phb_get_image(storeIndex, (U16*)&imageID, (U16*)imgPath, (U16*)&resType);
		}
	}

#ifdef __MMI_FILE_MANAGER__
	if ((resType & SRV_PHB_RES_TYPE_IMAGE_FILE) && (srv_fmgr_fs_path_exist(imgPath) == 0))
	{
        image.setPath(VFX_WSTR_MEM(imgPath));
	}
	else
#endif /* __MMI_FILE_MANAGER__ */
	if ((resType & SRV_PHB_RES_TYPE_IMAGE_ID) && (imageID != IMG_PHB_DEFAULT))
	{
		image.setResId(imageID);
	}
	else if ((!address.isEmpty()) && (type != VAPP_MSG_CONTACT_TYPE_ALPHANUMBIC) && (!isStored))
	{
		image.setResId(IMG_COSMOS_HEAD_PORTRAIT);
	}
	else
	{
		image.setResId(IMG_COSMOS_HEAD_PORTRAIT_2);
	}
}

void VappMsgContactProvider::getEmptyContactName(VfxWString& name, VappMsgContactEnum type)
{
	switch (type)
	{
	    case VAPP_MSG_CONTACT_TYPE_EMAIL:
			name.loadFromRes(STR_ID_VAPP_SMS_NO_EMAIL);
	    	break;

    	case VAPP_MSG_CONTACT_TYPE_SNS_NICKNAME:
        {
			name.loadFromRes(STR_ID_VAPP_SMS_NO_NICKNAME);
    		break;
		}

		default:
			name.loadFromRes(STR_GLOBAL_NO_NUMBER);
	    	break;
	}
}

//---------------------VappMsgContactListPage-------------------//
VappMsgContactListPage::VappMsgContactListPage() :
	m_listProvider(NULL),
	m_contactProvider(NULL),	
	m_listMenu(NULL),
	m_toolBar(NULL),
	m_isProviderUpdate(VFX_FALSE)
{
}
VappMsgContactListPage::VappMsgContactListPage(VappMsgContactBar *contactbar) :
	m_listProvider(NULL),
	m_contactProvider(NULL),	
	m_listMenu(NULL),
	m_toolBar(NULL),
	m_contactBar(contactbar),
	m_isProviderUpdate(VFX_FALSE)	
{
}

void VappMsgContactListPage::setProvider(VappMsgContactProvider* provider)
{
	if (provider)
	{
		//if (m_contactProvider)
		//{
			//m_contactProvider->m_signalUpdate.disconnect(this, &VappMsgContactListPage::onProviderUpdate);
		//}

		m_contactProvider = provider;
		//m_contactProvider->m_signalUpdate.connect(this, &VappMsgContactListPage::onProviderUpdate);

		if (m_listProvider == NULL)
		{
			VFX_OBJ_CREATE(m_listProvider, VappMsgContactListProvider, this);
		}

		m_listProvider->setProvider(provider);

		m_listMenu->setContentProvider(m_listProvider);

		checkUpdate();
	}
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappMsgContactListPage::onButtonClicked(VfxObject * sender, VfxId bottomId)
{
	m_contactProvider->resendFailed();
	exit();
}

void VappMsgContactListPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle((VfxResId)STR_ID_VAPP_SMS_RECIPIENTS);

	setTopBar(titleBar);


	VFX_OBJ_CREATE(m_listMenu, VcpGroupListMenu, this);
	m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
	                VFX_FRAME_ALIGNER_MODE_SIDE, 
	                VFX_FRAME_ALIGNER_MODE_SIDE, 
	                VFX_FRAME_ALIGNER_MODE_SIDE, 
	                VFX_FRAME_ALIGNER_MODE_SIDE);
	
	if (m_contactBar.isValid())
	{
		VappMsgContactBar *contactbar = (VappMsgContactBar *)m_contactBar.get();
		contactbar->m_signalDeinit.connect(this, &VappMsgContactListPage::onMemoryOut);
}
}



void VappMsgContactListPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
}

void VappMsgContactListPage::onMemoryOut(void)
{
	exit();
}

void VappMsgContactListPage::onUpdate(void)
{
    VfxPage::onUpdate();

    if (m_contactProvider)
    {
    	if (m_contactProvider->isResendFailed())
    	{
    		if (m_toolBar == NULL)
    		{
    			VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);

    			m_toolBar->m_signalButtonTap.connect(this, &VappMsgContactListPage::onButtonClicked);
    			m_toolBar->addItem(BUTTON_RESEND_FAILED, (VfxResId)STR_ID_VAPP_SMS_RESEND_FAILED_MSG, IMG_ID_VAPP_SMS_RESEND);

    			setBottomBar(m_toolBar);
    		}

            VfxBool isDisable = m_contactProvider->isDisableResendButton();

            m_toolBar->setDisableItem(BUTTON_RESEND_FAILED, isDisable);
    	}
    	else
    	{
    		if (m_toolBar)
    		{
    			VFX_OBJ_CLOSE(m_toolBar);
    			setBottomBar(NULL);
    		}
    	}
    }

    if (m_isProviderUpdate && m_listMenu)
    {
        m_isProviderUpdate = VFX_FALSE;
    
	    m_listMenu->updateAllItems();
	}
}

//---------------------VappMsgContactListProvider-------------------//
VappMsgContactListProvider::VappMsgContactListProvider()
{
}

void VappMsgContactListProvider::setProvider(VappMsgContactProvider* provider)
{
	m_provider = provider;
}

VfxBool VappMsgContactListProvider::getItemText(
	        VcpMenuPos index,
	        VcpListMenuFieldEnum fieldType,
	        VfxWString &text,
	        VcpListMenuTextColorEnum &color)
{
	VfxBool result = VFX_FALSE;

	if (m_provider)
	{
		if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
		{
			result = m_provider->getHeaderText(index.group, text);
		}
		else if (index.pos < m_provider->getCount(index.group))
		{
			VappMsgContact contact;
			VfxWString name;
			m_provider->getContact(contact, index);
			m_provider->getContactPhbName(name, contact.m_address, contact.m_type);

			if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
			{
				result = VFX_TRUE;

				if (name.isEmpty())
				{
					text = contact.m_address;
				}
				else
				{
					text = name;
				}

		        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
			}
			else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
			{
				if (!name.isEmpty())
				{
					result = VFX_TRUE;
					text = contact.m_address;
				}

		        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
			}
		}
	}

	return result;
}

VfxBool VappMsgContactListProvider::getItemImage(
	        VcpMenuPos index,                    
	        VcpListMenuFieldEnum fieldType,  
	        VfxImageSrc& image) 
{
	VfxBool result = VFX_TRUE;

	if (m_provider && (index.pos < m_provider->getCount(index.group)) &&
		(fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG))
	{
		VappMsgContact contact;

		m_provider->getContact(contact, index);

		image = contact.m_statusIcon;
	}
	else
	{
		result = VFX_FALSE;
	}

	return result;
}

VfxU32 VappMsgContactListProvider::getCount(VfxU32 group) const
{
	return m_provider ? m_provider->getCount(group) : 0;
}

VfxBool VappMsgContactListProvider::hasGroupHeader(VfxS32 group) const
{
	return m_provider ? m_provider->hasGroupHeader(group) : VFX_FALSE;
}

VfxU32 VappMsgContactListProvider::getGroupCount(void) const
{
	return m_provider ? m_provider->getGroupCount() : 0;
}

VfxBool VappMsgContactListProvider::getItemIsHighlightable(VcpMenuPos pos) const
{
    return VFX_FALSE;
}

