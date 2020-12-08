/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_vip_contact.cpp
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_VIP_CONTACT__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_vip_contact.h"
#include "mmi_rp_vapp_widget_vip_contact_def.h"
#include "vcp_include.h"
#include "vapp_contact_entry.h"
#include "vcui_phb_gprot.h"
#include "vapp_phb_gprot.h"
#include "PhbSrvGProt.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vcp_menu_popup.h"
#include "vapp_uc_gprot.h"
#include "vcp_photo_border_frame.h"
#include "mmi_rp_srv_phb_def.h"

#include "mmi_rp_app_cosmos_global_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "app_str.h"
#include "Ucmgprot.h"
#include "SimCtrlSrvGProt.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __MMI_EMAIL__
#include "emailappgprot.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VIP contact Widget
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetVipContactPhotoBorder", VappWidgetVipContactPhotoBorder, VcpPhotoBorderFrame);

VappWidgetVipContactPhotoBorder::VappWidgetVipContactPhotoBorder() :
m_show_name_area(VFX_FALSE),
m_width(0),
m_height(0)    
{
}

VappWidgetVipContactPhotoBorder::VappWidgetVipContactPhotoBorder(VfxBool show_name_area, VfxS32 width, VfxS32 height) :
m_show_name_area(show_name_area),
m_width(width),
m_height(height)
{
}

void VappWidgetVipContactPhotoBorder::onInit()
{
    VcpPhotoBorderFrame::onInit();
    
    if (m_show_name_area)
    {
        VFX_OBJ_CREATE(m_name_area, VfxFrame, this);
        m_name_area->setSize(NAME_AREA_WIDTH, NAME_AREA_HEIGHT);
        m_name_area->setAnchor(0.5, 0);
        m_name_area->setPos(m_width/2, (m_height-NAME_AREA_HEIGHT-NAME_AREA_SHIFT));
        m_name_area->setBgColor(VfxColor(255, 68, 64, 64));
        m_name_area->setOpacity(0.8);
        
        /* name */
        VFX_OBJ_CREATE(m_name, VfxTextFrame, m_name_area);            
        m_name->setSize(ITEM_NAME_WIDTH, ITEM_NAME_HEIGHT);
        m_name->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_name->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
        m_name->setAnchor(0.5, 0);
        m_name->setPos(NAME_AREA_WIDTH/2, ITEM_NAME_TALIGN);
        m_name->setAutoResized(VFX_FALSE);
        m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);        
        m_name->setColor(VFX_COLOR_WHITE);

        insertChildFrameAfter(getImageFrame(), m_name_area);
    }

    setMaxSize(VfxSize(m_width, m_height));
    setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
	setImageContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
}

void VappWidgetVipContactPhotoBorder::setName(VfxWString name)
{
    if (m_name != NULL)
    {
        m_name->setString(name);
        m_name->forceUpdate();
    }
}

void VappWidgetVipContactPhotoBorder::disable()
{
	setIsDisabled(VFX_TRUE);
	getImageFrame()->setOpacity(0.6);
	m_name->setOpacity(0.6);
	m_name_area->setOpacity(0.5);
}

void VappWidgetVipContactPhotoBorder::enable()
{
	setIsDisabled(VFX_FALSE);
	getImageFrame()->setOpacity(1);
	m_name->setOpacity(1);
	m_name_area->setOpacity(0.8);
}

VFX_IMPLEMENT_CLASS("VappWidgetVipContactApp", VappWidgetVipContactApp, VfxApp);

void VappWidgetVipContactApp::onRun(void* args, VfxU32 argSize)
{
    vapp_widget_vip_contact_arg *arg;
    arg = (vapp_widget_vip_contact_arg*)args;
    
    m_vipcontact = NULL;
    
    m_vipcontact = arg->vipcontact;
    
    /* Call contacts cui to select contact */
    mmi_id cui_id = GRP_ID_INVALID;
    
    cui_id = vcui_phb_list_create(getGroupId());
    MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_CREATE_CONTACT_CUI, cui_id);
    if (cui_id != GRP_ID_INVALID)
    {
        if (m_vipcontact != NULL)
        {
            m_vipcontact->setContactCuiId(cui_id);
        }
        vcui_phb_list_run(cui_id);
    }
    else
    {
        m_vipcontact->clearAppId();
        this->exit();
    }
}

mmi_ret VappWidgetVipContactApp::onProc(mmi_event_struct * evt)
{
    mmi_ret result = MMI_RET_OK;
    
    if (m_vipcontact != NULL)
    {
        result = m_vipcontact->callProc(evt);
        if (result == MMI_RET_OK)
        {
            m_vipcontact->clearAppId();
            this->exit();
        }
        else if (result == MMI_RET_DONT_CARE)
        {
            result = MMI_RET_OK;
        }
    }
    
    return result;
}

VFX_IMPLEMENT_CLASS("VappWidgetVipContactPopup", VappWidgetVipContactPopup, VfxBasePopup);

VappWidgetVipContactPopup::VappWidgetVipContactPopup() :
m_phb_id(SRV_PHB_INVALID_INDEX),
m_group_id(GRP_ID_INVALID),
m_parent(NULL)
{
}

VappWidgetVipContactPopup::VappWidgetVipContactPopup(mmi_phb_contact_id id, mmi_id group_id, VfxObject *parent) :
m_phb_id(id),
m_group_id(group_id),
m_parent(parent)
{
}

void VappWidgetVipContactPopup::onInit()
{
    VfxBasePopup::onInit();
	VappWidgetVipContact* parent = (VappWidgetVipContact*)m_parent;
	
    if (m_parent != NULL)
    {
        parent->m_opt_menu = NULL;
    }
    
    if (m_phb_id != SRV_PHB_INVALID_INDEX && ContactEntry::isValid(m_phb_id))
    {
        VappContactRes contact_res;
        VappContactName contact_name;
    #ifdef __MMI_PHB_INFO_FIELD__
        VappContactTitle contact_title;
    #endif
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        VappContactCompany contact_company;
    #endif
        ContactEntry entry(m_phb_id);
        
        contact_res = entry.getImage();
        contact_name = entry.getName();
    #ifdef __MMI_PHB_INFO_FIELD__
        contact_title = entry.getTitle();
    #endif
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__    
        contact_company = entry.getCompany();
    #endif
        /* Contact picture */
        VFX_OBJ_CREATE(m_pic, VcpPhotoBorderFrame, this);
        VfxSize size(PIC_WIDTH, PIC_HEIGHT);
        m_pic->setMaxSize(size);
        m_pic->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
		m_pic->setImageContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
		VfxWString path = contact_res.getPath();
		VfxImageSrc imgSrc;
		if (!path.isNull() && !path.isEmpty() && (srv_fmgr_fs_path_exist((const WCHAR*)path.getBuf()) == 0))
        {
            imgSrc = VfxImageSrc(path);
        }
        else
        {
            imgSrc = VfxImageSrc(IMG_PHB_DEFAULT);
        }
        m_pic->setImgContent(imgSrc);
        m_pic->setPos(PIC_LALIGN, PIC_TALIGN);
        m_pic->setIsUnhittable(VFX_TRUE);
        
        VfxS32 x = PIC_LALIGN+PIC_WIDTH+TEXT_LALIGN;
        VfxS32 y = NAME_TALIGN;

        /* Contact name */
        VFX_OBJ_CREATE(m_name, VfxTextFrame, this);
        m_name->setSize(NAME_WIDTH, NAME_HEIGHT);
        m_name->setAutoResized(VFX_FALSE);
        m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_name->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(NAME_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        if (contact_name.getString().isEmpty())
        {
            m_name->setString(VFX_WSTR_RES(STR_GLOBAL_UNNAMED));
        }
        else
        {
            m_name->setString(contact_name.getString());
        }
        m_name->setPos(x, y);
        m_name->setColor(VFX_COLOR_BLACK);
        m_name->forceUpdate();

        /* Contact title */
    #ifdef __MMI_PHB_INFO_FIELD__
        y += (NAME_TITLE_ALIGN+m_name->getSize().height);
        VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
        m_title->setSize(TITLE_WIDTH, TITLE_HEIGHT);
        m_title->setAutoResized(VFX_FALSE);
        m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_title->setString(contact_title.getString());
        m_title->setPos(x, y);
        m_title->setColor(VFX_COLOR_BLACK);
        m_title->forceUpdate();
    #endif
        /* Contact company */
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        y += (TITLE_COMPANY_ALIGN+m_title->getSize().height);
        VFX_OBJ_CREATE(m_company, VfxTextFrame, this);
        m_company->setSize(TITLE_WIDTH, TITLE_HEIGHT);
        m_company->setAutoResized(VFX_FALSE);
        m_company->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_company->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(COMPANY_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_company->setString(contact_company.getString());
        m_company->setPos(x, y);
        m_company->setColor(VFX_COLOR_BLACK);
        m_company->forceUpdate();
    #endif

        /* Button call */
        x = BUTTON_LALIGN;
        y = BUTTON_TALIGN;
        VFX_OBJ_CREATE(m_call, VcpImageButton, this);
        m_call->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);

        VfxResId n = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_N;
		VfxResId p = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_P;
		VfxResId d = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_D;
        mmi_sim_enum sim = MMI_SIM_NONE;
		VfxU32 phone_num_count = entry.getNumberCount();
		/* Show specific SIM icon if and only if:
		   1. Only a phone number 
		   2. Must have prefer SIM 
		   3. Prefer SIM can work */
		if (phone_num_count == 1)
		{
			/* Get prefer SIM of phone number and verif it */
			entry.getNumber();
			VappContactNumber number = entry.getNextNumber();
			VfxU32 SubId = number.getSubId();
			sim = entry.getPreferSim(SubId, VFX_TRUE);
			MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_548b0cdf1d9c479c838947805bb4c473, SubId, 0, sim);
			if (parent != NULL && parent->isSimAvailable(sim))
			{
				/* Assign specific sim icon */
				switch(sim)
		        {
		            case MMI_SIM1:
				#if (MMI_MAX_SIM_NUM == 1)
						n = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_N;
		                p = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_P;
		                d = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM_D;
				#else
		                n = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM1_N;
		                p = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM1_P;
		                d = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM1_D;
				#endif
		                break;
		            case MMI_SIM2:
		                n = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM2_N;
		                p = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM2_P;
		                d = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM2_D;
		                break;
					case MMI_SIM3:
						n = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM3_N;
		                p = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM3_P;
		                d = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM3_D;
						break;
					case MMI_SIM4:
						n = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM4_N;
		                p = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM4_P;
		                d = IMG_ID_VAPP_WIDGET_VIP_CONTACT_CALL_SIM4_D;
						break;
		            default:
		                break;
		        }
			}
			else
			{
				sim = MMI_SIM_NONE;
			}
		}
        
        m_call->setImage(VcpStateImage(n, p, d, n));
        m_call->setPos(x, y);
        m_call->setId(VAPP_WIDGET_VIP_CONTACT_CALL);
        m_call->m_signalClicked.connect(this, &VappWidgetVipContactPopup::onClickLaunch);

		U32 sim_count = srv_sim_ctrl_get_num_of_inserted();
        if (((sim == MMI_SIM1 || sim == MMI_SIM2 || sim == MMI_SIM3 || sim == MMI_SIM4) && !srv_sim_ctrl_is_available(sim)) ||
            phone_num_count == 0 ||
            !parent->isAnySimAvailable())
        {
        	/* Disable call button in these case:
			   1. SIM is unavailable
			   2. No phone number
			   3. No SIM card is available */
            m_call->setIsDisabled(VFX_TRUE);
        }

#ifdef __MMI_MMS_2__        
        /* Button message */
        x += (BUTTON_WIDTH+BUTTON_GAP);
        VFX_OBJ_CREATE(m_message, VcpImageButton, this);
        m_message->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
        m_message->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_N,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_P,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_D,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_MSG_N));
        m_message->setPos(x, y);
        m_message->setId(VAPP_WIDGET_VIP_CONTACT_MSG);
        m_message->m_signalClicked.connect(this, &VappWidgetVipContactPopup::onClickLaunch);        
        if (phone_num_count == 0)
        {
            m_message->setIsDisabled(VFX_TRUE);
        }
#endif
#ifdef __MMI_EMAIL__
        /* Button email */
        x += (BUTTON_WIDTH+BUTTON_GAP);
        VFX_OBJ_CREATE(m_email, VcpImageButton, this);
        m_email->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
        m_email->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_N,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_P,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_D,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_SEND_EMAIL_N));
        m_email->setPos(x, y);
        m_email->setId(VAPP_WIDGET_VIP_CONTACT_EMAIL);
        m_email->m_signalClicked.connect(this, &VappWidgetVipContactPopup::onClickLaunch);
        VfxU32 email_count = entry.getEmailCount();
        if (email_count == 0)
        {
            m_email->setIsDisabled(VFX_TRUE);
        }
#endif

        /* Button cancel */
        x = ITEM_WIDTH - BUTTON_LALIGN;
        VFX_OBJ_CREATE(m_cancel, VcpImageButton, this);
        m_cancel->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
        m_cancel->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_N,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_P,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_D,
                                          IMG_ID_VAPP_WIDGET_VIP_CONTACT_CANCEL_N));
        m_cancel->setAnchor(1, 0);
        m_cancel->setPos(x, y);
        m_cancel->setId(VAPP_WIDGET_VIP_CONTACT_CANCEL);
        m_cancel->m_signalClicked.connect(this, &VappWidgetVipContactPopup::onClickLaunch);        
        
        /* Set background */
        setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_VIP_CONTACT_POPUP_BG));
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        setSize(ITEM_WIDTH, ITEM_HEIGHT);
    }
}

void VappWidgetVipContactPopup::onDeinit()
{
    VfxBasePopup::onDeinit();
}

VfxBool VappWidgetVipContactPopup::onKeyInput(VfxKeyEvent &event)
{
    if ((event.keyCode == VFX_KEY_CODE_BACK || event.keyCode == VFX_KEY_CODE_HOME) && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        leave(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}

void VappWidgetVipContactPopup::disableCallButton(VfxBool disable)
{
    m_call->setIsDisabled(disable);
}

void VappWidgetVipContactPopup::showSimList()
{
	VappWidgetVipContact* parent = (VappWidgetVipContact*)m_parent;
	
	U32 sim_count = srv_sim_ctrl_get_num_of_inserted();
	if (sim_count == 1 && !parent->isAnySimAvailable())
	{
		/* The only one SIM card is unavailable. */
		return;
	}
	
	VFX_OBJ_CREATE(parent->m_sim_menu, VcpMenuPopup, m_parent);

	parent->m_sim_menu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_VIP_CONTACT_SELECT_SIM));

    VfxU32 i = 0;
	VfxWString text;
	VcpMenuPopupItem *item = NULL;
	VfxImageSrc call_icon;
	U16 sim_mask = 0x0000;
	
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
    	item = NULL;
		call_icon.setNull();
		
		mmi_sim_enum sim = MMI_SIM_NONE;
		switch (i)
		{
            case 0:
				sim = MMI_SIM1;
				if (!srv_sim_ctrl_is_inserted(sim))
				{
					continue;
				}
				call_icon = VfxImageSrc(IMG_COSMOS_GEMINI_SIM1_CALL);
				text = VFX_WSTR_RES(STR_GLOBAL_SIM_1);
				break;
            case 1:
				sim = MMI_SIM2;
				if (!srv_sim_ctrl_is_inserted(sim))
				{
					continue;
				}
				call_icon = VfxImageSrc(IMG_COSMOS_GEMINI_SIM2_CALL);
				text = VFX_WSTR_RES(STR_GLOBAL_SIM_2);
				break;
            case 2:
				sim = MMI_SIM3;
				if (!srv_sim_ctrl_is_inserted(sim))
				{
					continue;
				}
				call_icon = VfxImageSrc(IMG_COSMOS_GEMINI_SIM3_CALL);
				text = VFX_WSTR_RES(STR_GLOBAL_SIM_3);
				break;
            case 3:
				sim = MMI_SIM4;
				if (!srv_sim_ctrl_is_inserted(sim))
				{
					continue;
				}
				call_icon = VfxImageSrc(IMG_COSMOS_GEMINI_SIM4_CALL);
				text = VFX_WSTR_RES(STR_GLOBAL_SIM_4);
				break;
			default:
				call_icon = VfxImageSrc(IMG_COSMOS_GEMINI_SIM_CALL);
				text = VFX_WSTR_RES(STR_GLOBAL_SIM);
				break;
		}
		item = parent->m_sim_menu->addItem(sim, text, call_icon, VCP_MENU_POPUP_ITEM_TYPE_2);
		
		if (!parent->isSimAvailable(sim) && item != NULL)
		{
			/* Disable menu item */
			item->setIsDisabled(VFX_TRUE);
		}
		else
		{
			sim_mask |= (U16)(1 << (i+MMI_MAX_SIM_NUM));
		}

		sim_mask |= (U16)(1 << i);
    }                       	
	MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_86621ebe18904071bc13a2d67c980196, sim_count, sim_mask);
	
	parent->m_sim_menu->m_signalMenuCallback.connect(parent, &VappWidgetVipContact::onSelectSimPopup);
	parent->m_sim_menu->m_signalPopupState.connect(parent, &VappWidgetVipContact::onSelectSimPopupStateChange);
	
	parent->m_sim_menu->showMenu();
}

void VappWidgetVipContactPopup::showNumberList(ContactEntry &entry, VfxId id, VfxU32 count)
{
    VappWidgetVipContact* parent = (VappWidgetVipContact*)m_parent;
	VFX_OBJ_CREATE(parent->m_opt_menu, VcpMenuPopup, m_parent);

	parent->m_opt_menu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_VIP_CONTACT_SELECT_A_NUMBER));

    VfxU32 i = 0, range = 0;
    VfxWString text;

    if (id == VAPP_WIDGET_VIP_CONTACT_MSG)
    {
        range = MSG_START;
    }
 
	VfxImageSrc sim_icon;
	entry.getNumber();
	VfxU32 SubId;
	mmi_sim_enum sim = MMI_SIM_NONE;
    for (i = 0; i < count; i++)
    {
        VappContactNumber number = entry.getNextNumber();
        text = number.getLabel();
        text += VFX_WSTR(": ");
        text += number.getString();
		SubId = number.getSubId();
		sim = entry.getPreferSim(SubId, VFX_TRUE);
		MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_4ca08058918a431780562303017db040, SubId, i, sim);
		switch(sim)
		{
			case MMI_SIM1:
				sim_icon = VfxImageSrc(IMG_COSMOS_SIM1);
				break;
			case MMI_SIM2:
				sim_icon = VfxImageSrc(IMG_COSMOS_SIM2);
				break;
			case MMI_SIM3:
				sim_icon = VfxImageSrc(IMG_COSMOS_SIM3);
				break;
			case MMI_SIM4:
				sim_icon = VfxImageSrc(IMG_COSMOS_SIM4);
				break;
		}

		if (id == VAPP_WIDGET_VIP_CONTACT_MSG)
		{
			parent->m_opt_menu->addItem((i+1+range), text);
		}
		else
		{
			if (parent->isSimAvailable(sim))
			{
    			parent->m_opt_menu->addItem((i+1+range), text, sim_icon);
			}
			else
			{
				parent->m_opt_menu->addItem((i+1+range), text);
			}
		}
		sim_icon.setNull();
    }                       	
	
	parent->m_opt_menu->m_signalMenuCallback.connect(parent, &VappWidgetVipContact::onClickMenuPopup);
	parent->m_opt_menu->m_signalPopupState.connect(parent, &VappWidgetVipContact::onMenuPopupStateChange);
	
	parent->m_opt_menu->showMenu();
}

void VappWidgetVipContactPopup::showEmailList(ContactEntry &entry, VfxU32 count)
{
    VappWidgetVipContact* parent = (VappWidgetVipContact*)m_parent;
	VFX_OBJ_CREATE(parent->m_opt_menu, VcpMenuPopup, m_parent);

	parent->m_opt_menu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_VIP_CONTACT_SELECT_A_EMAIL));

	VcpMenuPopupItem *item;
    VfxU32 i = 0;
    VfxWString text;    

	entry.getEmail();
    for (i = 0; i < count; i++)
    {
        VappContactEmail email = entry.getNextEmail();
        text = email.getLabel();
        text += VFX_WSTR(": ");
        text += email.getString();
    	item = parent->m_opt_menu->createMenuItem((i+1+EMAIL_START), text);
    	parent->m_opt_menu->insertItem(NULL, NULL, item);
    }                       	
	
	parent->m_opt_menu->m_signalMenuCallback.connect(parent, &VappWidgetVipContact::onClickMenuPopup);
	parent->m_opt_menu->m_signalPopupState.connect(parent, &VappWidgetVipContact::onMenuPopupStateChange);
	
	parent->m_opt_menu->showMenu();
}

void VappWidgetVipContactPopup::onClickLaunch(VfxObject* obj, VfxId id)
{
    /* Initialize selected index */
	VappWidgetVipContact* parent = (VappWidgetVipContact*)m_parent;
	parent->setSelectedInfo();
	
    switch (id)
    {        
        case VAPP_WIDGET_VIP_CONTACT_CALL:
#ifdef __MMI_MMS_2__
        case VAPP_WIDGET_VIP_CONTACT_MSG:
#endif
            {
                /* Show phone number list or launch app immediately */
                if (ContactEntry::isValid(m_phb_id))
                {
                    ContactEntry entry(m_phb_id);
                    VfxU32 count = entry.getNumberCount();
                    if (count == 1)
                    {
                    	/* Call the API before to call getNextNumber */
                    	entry.getNumber();
					#ifdef __MMI_MMS_2__
                        if (id == VAPP_WIDGET_VIP_CONTACT_MSG)
                        {
                            VappUcEntryStruct uc_entry;
                            memset(&uc_entry, 0, sizeof(VappUcEntryStruct));

                            uc_entry.type = SRV_UC_STATE_WRITE_NEW_MSG;
                            uc_entry.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
                            uc_entry.addr_num = 1;

                            srv_uc_addr_struct uc_addr;
                            memset(&uc_addr, 0, sizeof(srv_uc_addr_struct));
                            uc_addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
                            uc_addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;

                            VappContactNumber number = entry.getNextNumber();
                            uc_addr.addr = (kal_uint8 *)number.getBuf();

                            uc_entry.addr = &uc_addr;
                            vappUcAppLauncher(&uc_entry);
                        }
                        else
					#endif
                        {
                            VappContactNumber number = entry.getNextNumber();
							VfxU32 SubId = number.getSubId();
                            mmi_sim_enum sim = entry.getPreferSim(SubId, VFX_TRUE);
							if (srv_sim_ctrl_get_num_of_inserted() == 1)
							{
								/* If there is only one SIM card inserted, use it!! */
								sim = parent->getOnlyOneAvailableSim();
							}
							
                            if (!parent->isSimAvailable(sim))
                            {
                            	parent->setSelectedInfo(1);
								showSimList();
                            }
                            else
                            {
                                mmi_ucm_make_call_para_struct make_call_para;
                                mmi_ucm_init_call_para(&make_call_para);
                                    
                                parent->getDialType(&make_call_para.dial_type, sim);
    							
                                make_call_para.ucs2_num_uri = (U16*)number.getBuf();

							    void *cm_user_data = NULL;

						        cm_user_data = srv_phb_create_cm_user_data_by_sub_id(NULL, number.getSubId(), m_phb_id);
							    make_call_para.adv_para.after_callback_user_data = cm_user_data;
				    		    make_call_para.adv_para.phb_data = cm_user_data;
							    make_call_para.adv_para.after_make_call_callback = VappWidgetVipContact::makeCallCb;

                                mmi_ucm_call_launch(m_group_id, &make_call_para);
                            }
                        }
                    }
                    else if (count > 1)
                    {
                        showNumberList(entry, id, count);
                    }
                }
            }
            break;
#ifdef __MMI_EMAIL__            
        case VAPP_WIDGET_VIP_CONTACT_EMAIL:
            {
                /* Show phone number list or launch app immediately */
                if (ContactEntry::isValid(m_phb_id))
                {
                    ContactEntry entry(m_phb_id);
                    VfxU32 count = entry.getEmailCount();
                    if (count == 1)
                    {
                    	entry.getEmail();
                        VappContactEmail email = entry.getNextEmail();
                        mmi_email_app_send_to_ext((const S8*)email.getBuf(), (const S8*)entry.getName().getString().getBuf());
                    }
                    else if (count > 1)
                    {
                        showEmailList(entry, count);
                    }
                }
            }
            break;
#endif            
        case VAPP_WIDGET_VIP_CONTACT_CANCEL:
        default:
            {
                /* Close myselft */
                exit(VFX_TRUE);
            }
            break;
    }
}

void VappWidgetVipContactPopup::refreshContactPic(void)
{
    if (m_pic != NULL && ContactEntry::isValid(m_phb_id))
    {
        ContactEntry entry(m_phb_id);
    
        VappContactRes contact_res = entry.getImage();

        /* Contact picture */
        VfxWString path = contact_res.getPath();
        VfxImageSrc imgSrc;
        if (!path.isNull() && !path.isEmpty() && (srv_fmgr_fs_path_exist((const WCHAR*)path.getBuf()) == 0))
        {
            imgSrc = VfxImageSrc(path);
        }
        else
        {
            imgSrc = VfxImageSrc(IMG_PHB_DEFAULT);
        }
        m_pic->setImgContent(imgSrc);
		m_pic->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
    }
}

VFX_IMPLEMENT_CLASS("VappWidgetVipContactItem", VappWidgetVipContactItem, VfxFrame);

VappWidgetVipContactItem::VappWidgetVipContactItem() :
m_phb_id(SRV_PHB_INVALID_INDEX),
m_my_id(VFX_ID_NULL),
m_parent(NULL),
m_is_ready(VFX_FALSE)
{
}

VappWidgetVipContactItem::VappWidgetVipContactItem(mmi_phb_contact_id id, VfxId my_id, VfxObject* parent, VfxBool isReady) :
m_phb_id(id),
m_my_id(my_id),
m_parent(parent),
m_is_ready(isReady)
{
}
    

void VappWidgetVipContactItem::onInit()
{
    VfxFrame::onInit();

    m_del_button = NULL;
    m_fp_frame = NULL;   

    /* Get contact entry */
    VfxBool isEntryValid = (m_phb_id != SRV_PHB_INVALID_INDEX)? VFX_TRUE : VFX_FALSE;

    if (!m_is_ready)
    {
        isEntryValid = VFX_FALSE;
    }
    
    VappContactRes contact_res;
    VappContactName contact_name;
    if (isEntryValid)
    {
        ContactEntry entry(m_phb_id);
        contact_res = entry.getImage();
        contact_name = entry.getName();
    }
    
    /* contact pic */
    VfxImageSrc imgSrc;
    if (m_phb_id == SRV_PHB_INVALID_INDEX)
    {
        imgSrc = VfxImageSrc(IMG_ID_VAPP_WIDGET_VIP_ADD);
    }
    else
    {
        if (isEntryValid)
        {
            VfxWString path = contact_res.getPath();
            if (path.isNull() || path.isEmpty())
            {
                imgSrc = VfxImageSrc(IMG_PHB_DEFAULT);
            }
            else
            {
                /* Use pbm */
                VfxU8 *buffer = NULL;
                VFX_ALLOC_MEM(buffer, SRV_FMGR_PATH_BUFFER_SIZE, this);
                memset(buffer, 0, SRV_FMGR_PATH_BUFFER_SIZE);
                app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
                VfxChar* ext_ptr = (VfxChar*)srv_fmgr_path_get_extension_ptr((WCHAR*)buffer);
                memset(ext_ptr, 0, app_ucs2_strlen((const kal_int8*)ext_ptr)*sizeof(VfxWChar));
                app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)L"pbm");
            	if (srv_fmgr_fs_path_exist((const WCHAR*)buffer) == 0)
                {
                    imgSrc = VfxImageSrc(VFX_WSTR_MEM((VfxWChar*)buffer));
                }
                else
                {
                    imgSrc = VfxImageSrc(IMG_PHB_DEFAULT);
                }
                VFX_FREE_MEM(buffer);
            }
        }
        else
        {
            imgSrc = VfxImageSrc(IMG_ID_VAPP_WIDGET_VIP_ADD);
        }
    }

    /* full panel */
    VFX_OBJ_CREATE_EX(m_fp_frame, VappWidgetVipContactPhotoBorder, this, (VFX_TRUE, ITEM_WIDTH, ITEM_HEIGHT));
    if (!imgSrc.isNull() && !imgSrc.isEmpty())
    {
        m_fp_frame->setImgContent(imgSrc);
    }

    /* Set Name */
    if (m_phb_id == SRV_PHB_INVALID_INDEX)
    {
        m_fp_frame->setName(VFX_WSTR_RES(STR_GLOBAL_ADD));
    }
    else
    {
        if (isEntryValid)
        {
            if (contact_name.getString().isEmpty())
            {
                m_fp_frame->setName(VFX_WSTR_RES(STR_GLOBAL_UNNAMED));
            }
            else
            {
                m_fp_frame->setName(contact_name.getString());
            }
        }
        else
        {
            m_fp_frame->setName(VFX_WSTR_RES(STR_GLOBAL_LOADING));
        }
    }
	/* Workaround because there is no variable id in photoborder structure */
	switch (m_my_id)
	{
		case 1:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard1);
			break;
		case 2:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard2);
			break;
		case 3:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard3);
			break;
		case 4:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard4);
			break;
		case 5:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard5);
			break;
		case 6:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard6);
			break;
		case 7:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard7);
			break;
		case 8:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard8);
			break;
		case 9:
			m_fp_frame->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickCard9);
			break;
		default:
			/* Currently, we only have at most 9 items */
			VFX_DEV_ASSERT(0);
			break;
	}
	
	if (!m_is_ready)
    {
        disableFpButton();
    }
    
    /* for delete */
    VFX_OBJ_CREATE(m_del_button, VcpImageButton, this);
    m_del_button->setSize(40, 40);
    m_del_button->setAnchor(0.5, 0.5);
    m_del_button->setPos(ITEM_WIDTH/2, ITEM_HEIGHT/2);
    m_del_button->setHidden(VFX_FALSE);
    m_del_button->m_signalClicked.connect((VappWidgetVipContact*)m_parent, &VappWidgetVipContact::onClickDelete);
    m_del_button->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_DEL_CONTACT));
    m_del_button->setId((m_my_id+MY_DEL_ID_BASE));
    m_del_button->setHidden(VFX_TRUE);

    setSize(ITEM_WIDTH, ITEM_HEIGHT);
}

void VappWidgetVipContactItem::onDeinit()
{
    VfxFrame::onDeinit();
}

void VappWidgetVipContactItem::disableFpButton()
{
	if (m_fp_frame != NULL)
	{
		m_fp_frame->disable();
	}
}

void VappWidgetVipContactItem::enableFpButton()
{
	if (m_fp_frame != NULL)
	{
		m_fp_frame->enable();
	}
}

void VappWidgetVipContactItem::hideDelButton(VfxBool hide)
{
    m_del_button->setHidden(hide);
}

void VappWidgetVipContactItem::setName(VfxWString &text)
{
    if (text.isEmpty())
    {
        m_fp_frame->setName(VFX_WSTR_RES(STR_GLOBAL_UNNAMED));
    }
    else
    {
        m_fp_frame->setName(text);
    }
    
}

void VappWidgetVipContactItem::setPic(VfxImageSrc &img)
{
    m_fp_frame->setImgContent(img);
    m_fp_frame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
}

void VappWidgetVipContactItem::setPhbId(mmi_phb_contact_id id)
{
    m_phb_id = id;
}

void VappWidgetVipContactItem::setPic(mmi_phb_contact_id id)
{    
    if (ContactEntry::isValid(id))
    {
        VappContactRes contact_res;
        ContactEntry entry(id);
        contact_res = entry.getImage();

        VfxWString path = contact_res.getPath();
        if (path.isNull() || path.isEmpty())
        {
            m_fp_frame->setImgContent(VfxImageSrc(IMG_PHB_DEFAULT));
        }
        else
        {
            VfxU8 *buffer = NULL;
            VFX_ALLOC_MEM(buffer, SRV_FMGR_PATH_BUFFER_SIZE, this);
            memset(buffer, 0, SRV_FMGR_PATH_BUFFER_SIZE);
            app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
            VfxChar* ext_ptr = (VfxChar*)srv_fmgr_path_get_extension_ptr((WCHAR*)buffer);
            memset(ext_ptr, 0, app_ucs2_strlen((const kal_int8*)ext_ptr)*sizeof(VfxWChar));
            app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)L"pbm");
            m_fp_frame->setImgContent(VfxImageSrc(VFX_WSTR_MEM((VfxWChar*)buffer)));
            VFX_FREE_MEM(buffer);
        }
        m_fp_frame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
    }    
}

void VappWidgetVipContactItem::setName(mmi_phb_contact_id id)
{
    if (ContactEntry::isValid(id))
    {
        VappContactName contact_name;
        ContactEntry entry(id);
        contact_name = entry.getName();

        VfxWString name;
        if (contact_name.getString().isEmpty())
        {
            name = VFX_WSTR_RES(STR_GLOBAL_UNNAMED);
        }
        else
        {
            name = contact_name.getString();
        }
        m_fp_frame->setName(name);
    }
}

VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetVipContact, VAPP_WIDGET_TYPE_VIP_CONTACT, VappWidgetVipContactPublisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetVipContact, VappWidget);

VappWidgetVipContact* VappWidgetVipContact::m_context = NULL;

mmi_ret VappWidgetVipContact::static_callerProc(mmi_event_struct *evt)
{
    VappWidgetVipContact* obj = (VappWidgetVipContact*)evt->user_data;
    return obj->onProc(evt);
}

void VappWidgetVipContact::setContactCuiId(mmi_id cui_id)
{
    m_phb_list_cui = cui_id;
}

void VappWidgetVipContact::clearAppId(void)
{
    m_id = GRP_ID_INVALID;
}

void VappWidgetVipContact::getDialType(srv_ucm_call_type_enum *dial_type, mmi_sim_enum preferSIM)
{
    if (dial_type == NULL)
    {
        return;
    }
    
    // select sim to make call
    if (preferSIM == MMI_SIM1)
    {
        (*dial_type) = SRV_UCM_VOICE_CALL_TYPE;
    }
    else if (preferSIM == MMI_SIM2)
    {
        (*dial_type) = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    }
	else if (preferSIM == MMI_SIM3)
	{
		(*dial_type) = SRV_UCM_VOICE_CALL_TYPE_SIM3;
	}
	else if (preferSIM == MMI_SIM4)
	{
		(*dial_type) = SRV_UCM_VOICE_CALL_TYPE_SIM4;
	}
    else
    {
        (*dial_type) = (srv_ucm_call_type_enum)((*dial_type) & (~SRV_UCM_VOIP_CALL_TYPE));
    }
}

void VappWidgetVipContact::setSelectedInfo(VfxS32 selected_index, mmi_sim_enum selected_sim)
{
	m_selected_menu_popup_id = selected_index;
	m_selected_sim = selected_sim;
}

mmi_ret VappWidgetVipContact::PhbListen(mmi_event_struct* evt)
{
    if (evt->evt_id == EVT_ID_PHB_READY)
    {
        MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_GOT_PHB_EVENT);
        srv_phb_startup_evt_struct *phbEvt = (srv_phb_startup_evt_struct*)evt;
        if (phbEvt->phb_ready && m_context != NULL)
        {
            MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_REFRESH_WIDGET);
            m_context->refreshContactItems();
            if (m_context->m_edit != NULL) m_context->m_edit->setIsDisabled(VFX_FALSE);

            mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappWidgetVipContact::PhbListen, m_context);
        }
    }

    return MMI_RET_OK;
}

mmi_ret VappWidgetVipContact::DriveListen(mmi_event_struct* evt)
{
	switch (evt->evt_id)
	{
	    case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            if (m_context != NULL && m_context->m_card != NULL)
			{
			    srv_mode_switch_notify_struct *flightMode = (srv_mode_switch_notify_struct*)evt;
                if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_ON &&
                     flightMode->select_flight_mode == SRV_MODE_SWITCH_OFF))
                {
                    m_context->m_card->disableCallButton(VFX_FALSE);
                }
                else if ((flightMode->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                          flightMode->select_flight_mode == SRV_MODE_SWITCH_ON))
                {
                    m_context->m_card->disableCallButton(VFX_TRUE);
                }
            }
            break;
        }
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
			{
				if (m_context != NULL)
				{
                    m_context->refreshContactItems();
                    if (m_context->m_card != NULL && ContactEntry::isValid(m_context->m_contacts_id[m_context->m_curr_id]))
                    {
                        srv_fmgr_notification_dev_plug_event_struct *drv_evt = (srv_fmgr_notification_dev_plug_event_struct*)evt;
					    VfxU8 i = 0;
    					
					    ContactEntry entry(m_context->m_contacts_id[m_context->m_curr_id]);
        
        			    VappContactRes contact_res = entry.getImage();
						if (!contact_res.getPath().isNull() && !contact_res.getPath().isEmpty())
						{
						    for (i = 0; i < drv_evt->count; i++)
		                    {
		                	    if (drv_evt->drv_letters[i] == (VfxU8)contact_res.getPath().getBuf()[0])
	                		    {
	                			    m_context->m_card->m_pic->setImgContent(VfxImageSrc(IMG_PHB_DEFAULT));
								    break;
	                		    }
						    }
						}
                    }
				}
			}
			break;
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
	#ifdef __MMI_USB_SUPPORT__
	    case EVT_ID_USB_EXIT_MS_MODE:
	#endif
		    {
		        if (m_context != NULL)
		        {
		            m_context->refreshContactItems();
					if (m_context->m_card != NULL)
					{
						m_context->m_card->refreshContactPic();
					}
		        }
		    }
			break;
	}
    return MMI_RET_OK;
}

#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
mmi_ret VappWidgetVipContact::SimEventListen(mmi_event_struct* evt)
{
    if (evt->evt_id == EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED)
    {
        srv_sim_ctrl_event_detected_evt_struct *simEvt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

        switch (simEvt->type)
        {
            case SRV_SIM_CTRL_EVENT_DET_REMOVED:
            case SRV_SIM_CTRL_EVENT_DET_INSERTED:
            case SRV_SIM_CTRL_EVENT_DET_RECOVERY_START:
            case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
                MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_0d6f2b73ba97494080b1f393d33b414f, evt->evt_id, simEvt->type);
                if (m_context != NULL)
                {
                    /* Close all popup */
                    if (m_context->m_card != NULL)
                    {
                        VFX_OBJ_CLOSE(m_context->m_card);
                    }

                    if (m_context->m_opt_menu != NULL)
                    {
                        VFX_OBJ_CLOSE(m_context->m_opt_menu);
                    }

                	if (m_context->m_sim_menu != NULL)
                	{
                		VFX_OBJ_CLOSE(m_context->m_sim_menu);
                	}
                }
                break;
            default:
                break;
        };
    }

    return MMI_RET_OK;
}
#endif

mmi_ret VappWidgetVipContact::callProc(mmi_event_struct *evt)
{
    return onProc(evt);
}

mmi_ret VappWidgetVipContact::onProc(mmi_event_struct *evt)
{
    mmi_ret result = MMI_RET_DONT_CARE;
    
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PHB_LIST_RESULT:
            {
        		if (m_phb_list_cui != GRP_ID_INVALID)
        		{
        			vcui_phb_list_result_event_struct *phBookEvt = (vcui_phb_list_result_event_struct*)evt;

        			if (phBookEvt->result > 0)
        			{
        			    m_contacts_id[m_curr_id] = vcui_phb_list_get_contact_id(m_phb_list_cui);

                        MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_ADD_ITEM, m_curr_id, m_contacts_id[m_curr_id]);
                        if (ContactEntry::isValid( m_contacts_id[m_curr_id]))
                        {
                        #ifndef __MMI_SLIM_WIDGET_VIP_CONTACTS__
                            m_item_array[m_curr_id]->setPhbId(m_contacts_id[m_curr_id]);
                            m_item_array[m_curr_id]->setPic(m_contacts_id[m_curr_id]);
                            m_item_array[m_curr_id]->setName(m_contacts_id[m_curr_id]);
                        #endif
                            save(m_curr_id);
                        }
                    }

                    vcui_phb_list_close(m_phb_list_cui);
                    m_phb_list_cui = GRP_ID_INVALID;
                    result = MMI_RET_OK;
                }
            }
            break;
    }

    return result;
}

void VappWidgetVipContact::resetContactItem(VfxS8 index)
{
    if (index < 0 || index >= ITEM_NUM)
    {
        return;
    }

    /* Reset id */
    m_contacts_id[index] = SRV_PHB_INVALID_INDEX;
    m_item_array[index]->m_phb_id = SRV_PHB_INVALID_INDEX;
    /* Reset pic */
    m_item_array[index]->m_fp_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_VIP_ADD));
    m_item_array[index]->m_fp_frame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
    /* Reset name */
    m_item_array[index]->m_fp_frame->setName(VFX_WSTR_RES(STR_GLOBAL_ADD));
    /* Hide delete icon */
    m_item_array[index]->hideDelButton(VFX_TRUE);
}

void VappWidgetVipContact::showEditMode(void)
{
	VfxU8 i = 0;
    for (i = 0; i < ITEM_NUM; i++)
    {
        /* Disable full panel button */
        m_item_array[i]->disableFpButton();
        /* Hide delete button */
        if (m_contacts_id[i] != SRV_PHB_INVALID_INDEX)
        {
            m_item_array[i]->hideDelButton(VFX_FALSE);
        }
    }
    m_edit_mode = VFX_TRUE;
    m_edit->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_DELETE_DONE));
}

void VappWidgetVipContact::leaveEditMode(void)
{
	VfxU8 i = 0;
    for (i = 0; i < ITEM_NUM; i++)
    {
        /* Enable full panel button */
        m_item_array[i]->enableFpButton();
        /* Hide delete button */
        m_item_array[i]->hideDelButton(VFX_TRUE);
    }
    m_edit_mode = VFX_FALSE;
    m_edit->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_DELETE_MODE));
}

void VappWidgetVipContact::makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
	srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
}

mmi_sim_enum VappWidgetVipContact::getOnlyOneAvailableSim(void)
{
    VfxU8 i = 0;
	mmi_sim_enum sim = MMI_SIM_NONE;

	do {
		if (srv_sim_ctrl_get_num_of_inserted() == 1)
		{
		    for (i = 0; i < MMI_SIM_TOTAL; i++)
            {
                switch (i)
                {
                    case 0:
                        sim = MMI_SIM1;
                        break;
                    case 1:
                        sim = MMI_SIM2;
                        break;
                    case 2:
                        sim = MMI_SIM3;
                        break;
                    case 3:
                        sim = MMI_SIM4;
                        break;
                }

                if (isSimAvailable(sim))
    			{
    				break;
    			}
            }
		}
	} while (0);

	MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_88713982faba4457ba6275f462bd8850, sim);
	return sim;
}

VfxBool VappWidgetVipContact::isSimAvailable(mmi_sim_enum sim)
{
	VfxBool available = VFX_FALSE;

	do {
		if (sim != MMI_SIM_NONE)
		{
			if (!srv_sim_ctrl_is_available(sim))
			{
				break;
			}

			if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_OFF)
			{
				break;
			}

			available = VFX_TRUE;
		}
	} while(0);

	MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_172d3bd91dda41b0a004fb3de8ff07df, sim, available);
	return available;
}

VfxBool VappWidgetVipContact::isAnySimAvailable(void)
{
	VfxBool result = VFX_FALSE;
	VfxU8 i = 0;
	
	do {
		if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
		{
			break;
		}

		for (i = 0; i < MMI_MAX_SIM_NUM; i++)
		{
			switch (i)
			{
				case 0:
					result = isSimAvailable(MMI_SIM1);
					break;
				case 1:
					result = isSimAvailable(MMI_SIM2);
					break;
				case 2:
					result = isSimAvailable(MMI_SIM3);
					break;
				case 3:
					result = isSimAvailable(MMI_SIM4);
					break;
			}
			
			if (result)
			{
				break;
			}
		}
	} while(0);

	MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_f560e10acf48478bac8bc52b5a347556, i, result);
	return result;
}

void VappWidgetVipContact::launchApp(mmi_sim_enum sim)
{
	mmi_phb_contact_id phb_id = m_contacts_id[m_curr_id];
		
	VfxS32 id = m_selected_menu_popup_id, i = 0;

#ifdef __MMI_EMAIL__            
    if (id > VappWidgetVipContactPopup::EMAIL_START)
    {
        id -= (VappWidgetVipContactPopup::EMAIL_START+1);
        
        ContactEntry entry(phb_id);
		VappContactEmail email;
		entry.getEmail();
		do {
			email = entry.getNextEmail();
			i++;
		} while (i <= id);
        mmi_email_app_send_to_ext((const S8*)email.getBuf(), (const S8*)entry.getName().getString().getBuf());
    }
    else 
#endif
#ifdef __MMI_MMS_2__
    if (id > VappWidgetVipContactPopup::MSG_START)
    {
        id -= (VappWidgetVipContactPopup::MSG_START+1);

        VappUcEntryStruct entry;
        memset(&entry, 0, sizeof(VappUcEntryStruct));

        entry.type = SRV_UC_STATE_WRITE_NEW_MSG;
        entry.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
        entry.addr_num = 1;

        srv_uc_addr_struct uc_addr;
        memset(&uc_addr, 0, sizeof(srv_uc_addr_struct));
        uc_addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
        uc_addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;

        ContactEntry contact(phb_id);
		VappContactNumber number;
		contact.getNumber();
		do {
			number = contact.getNextNumber();
			i++;
		} while (i <= id);
        uc_addr.addr = (kal_uint8 *)number.getBuf();

        entry.addr = &uc_addr;
        vappUcAppLauncher(&entry);
    }
    else
#endif
    {
        ContactEntry entry(phb_id);
		mmi_ucm_make_call_para_struct make_call_para;
        mmi_ucm_init_call_para(&make_call_para);

        if (id > 0)
        {
            id--;
        }

		VappContactNumber number;
		entry.getNumber();
		do {
			number = entry.getNextNumber();
			i++;
		} while (i <= id);

		VfxU32 SubId = number.getSubId();
		mmi_sim_enum number_sim = entry.getPreferSim(SubId, VFX_TRUE);
		
		if (sim == MMI_SIM_NONE)
		{
			/* Modified prefer SIM according to SPEC */
			if (number_sim == MMI_SIM_NONE && srv_sim_ctrl_get_num_of_inserted() == 1)
			{
				/* No prefer SIM and there is only on SIM card available. Use it! */
				number_sim = getOnlyOneAvailableSim();
			}
			else if (number_sim != MMI_SIM_NONE && !isSimAvailable(number_sim))
			{
				/* Prefer SIM is unavailable. To show SIM selector. */
				number_sim = MMI_SIM_NONE;
			}
		}

		MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_6c4cd5e81a89433b9fbdae378d678d15, SubId, id, number_sim, sim);
		if (number_sim != MMI_SIM_NONE || sim != MMI_SIM_NONE)
		{
            m_selected_menu_popup_id = -1;

			if (sim != MMI_SIM_NONE)
			{
				getDialType(&make_call_para.dial_type, sim);
			}
			else
			{
				getDialType(&make_call_para.dial_type, number_sim);
			}
	        make_call_para.ucs2_num_uri = (U16*)number.getBuf();

	        /* Get parent group id */
	        VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)this);
	        mmi_id group_id = scr->getGroupId();

			void *cm_user_data = NULL;

		    cm_user_data = srv_phb_create_cm_user_data_by_sub_id(NULL, number.getSubId(), phb_id);
			make_call_para.adv_para.after_callback_user_data = cm_user_data;
    		make_call_para.adv_para.phb_data = cm_user_data;
			make_call_para.adv_para.after_make_call_callback = VappWidgetVipContact::makeCallCb;
			
	        mmi_ucm_call_launch(group_id, &make_call_para);
		}
		else
		{
			if (m_card != NULL)
			{
				m_card->showSimList();
			}
		}
    }
}

void VappWidgetVipContact::onMenuPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
	if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION && m_selected_menu_popup_id >= 0 && m_sim_menu == NULL)
	{
		/* User has selected item */
		launchApp();
	}
    else if (state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        m_selected_menu_popup_id = -1;
    }
}

void VappWidgetVipContact::onSelectSimPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
	if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION && m_selected_menu_popup_id >= 0 && m_selected_sim > MMI_SIM_NONE)
	{
		/* User has selected item */
		launchApp(m_selected_sim);
	}
    else if (state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        m_selected_sim = MMI_SIM_NONE;
    }
}


void VappWidgetVipContact::onClickMenuPopup(VcpMenuPopup* opt_menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
	if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
	    mmi_phb_contact_id phb_id = m_contacts_id[m_curr_id];
	    if (ContactEntry::isValid(phb_id))
        {
            m_selected_menu_popup_id = item->getId();
            m_opt_menu->exit(VFX_TRUE);
        }
	}
}

void VappWidgetVipContact::onSelectSimPopup(VcpMenuPopup* opt_menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
	if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
	    m_selected_sim = (mmi_sim_enum)item->getId();
		m_sim_menu->exit(VFX_TRUE);
	}
}
void VappWidgetVipContact::onClickCard1()
{
	onClickCardPanel(NULL, 1);
}

void VappWidgetVipContact::onClickCard2()
{
	onClickCardPanel(NULL, 2);
}

void VappWidgetVipContact::onClickCard3()
{
	onClickCardPanel(NULL, 3);
}

void VappWidgetVipContact::onClickCard4()
{
	onClickCardPanel(NULL, 4);
}

void VappWidgetVipContact::onClickCard5()
{
	onClickCardPanel(NULL, 5);
}

void VappWidgetVipContact::onClickCard6()
{
	onClickCardPanel(NULL, 6);
}

void VappWidgetVipContact::onClickCard7()
{
	onClickCardPanel(NULL, 7);
}

void VappWidgetVipContact::onClickCard8()
{
	onClickCardPanel(NULL, 8);
}

void VappWidgetVipContact::onClickCard9()
{
	onClickCardPanel(NULL, 9);
}


void VappWidgetVipContact::onClickCardPanel(VfxObject* obj, VfxId id)
{
    VFX_DEV_ASSERT(id != VFX_ID_NULL);
    if (id > MY_DEL_ID_BASE)
    {
        m_curr_id = (id - MY_DEL_ID_BASE - 1);
    }
    else
    {
        m_curr_id = id - 1;
    }
    VFX_DEV_ASSERT(m_curr_id >= 0);

    if (m_contacts_id[m_curr_id] == SRV_PHB_INVALID_INDEX)
    {
        /* Add contact case */
        vapp_widget_vip_contact_arg arg;
        arg.vipcontact = this;

        m_id = VfxAppLauncher::launch(VAPP_WIDGET_VIP_CONTACT, 
                               VFX_OBJ_CLASS_INFO(VappWidgetVipContactApp),
                               GRP_ID_ROOT,
                               (void*)&arg,
                               sizeof(vapp_widget_vip_contact_arg));
    }
    else
    {
        /* Show cantact card case */
        if (ContactEntry::isValid(m_contacts_id[m_curr_id]))
        {
            /* Show contact card */
            /* Get parent group id */
            VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)this);
            mmi_id group_id = scr->getGroupId();
            
            VFX_OBJ_CREATE_EX(m_card, VappWidgetVipContactPopup, this, (m_contacts_id[m_curr_id], group_id, (VfxObject*)this));
            m_card->show(VFX_TRUE);
        }
        else
        {
            /* Show error message */            
            VFX_OBJ_CREATE(m_pop, VcpConfirmPopup, this);

            m_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_pop->setText(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_VIP_CONTACT_ERR_CONTACT_NOT_FOUND));
            m_pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    		m_pop->show(VFX_TRUE);

            resetContactItem(m_curr_id);

            save(m_curr_id);
        }
    }
}

void VappWidgetVipContact::onClickDelete(VfxObject* obj, VfxId id)
{
    VFX_DEV_ASSERT(id != VFX_ID_NULL);
    if (id > MY_DEL_ID_BASE)
    {
        m_curr_id = (id - MY_DEL_ID_BASE - 1);
    }
    else
    {
        m_curr_id = id - 1;
    }
    VFX_DEV_ASSERT(m_curr_id >= 0);

    resetContactItem(m_curr_id);

    save(m_curr_id);
}

void VappWidgetVipContact::onClickEdit(VfxObject* obj, VfxId id)
{
    if (m_edit_mode)
    {
        /* Cancel edit mode */
        leaveEditMode();
    }
    else
    {
        /* Enter edit mode */
        showEditMode();
    }
}

VappWidgetId VappWidgetVipContact::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_VIP_CONTACT);
}


VfxSize VappWidgetVipContact::getMaxSize() const
{
    return VfxSize(WIDTH, HEIGHT);
}


VfxS32 VappWidgetVipContact::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_VIP_CONTACT);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetVipContact::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_VIP_CONTACT);

    return icon;
}

#ifdef __MMI_SLIM_WIDGET_VIP_CONTACTS__
void VappWidgetVipContact::createAllCp()
{
    VfxBool isReady = vapp_phb_check_ready();
    
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImg->setResId(IMG_ID_VAPP_WIDGET_VIP_CONTACT_BG);
    m_bgImg->setSize(VfxSize(WIDTH, HEIGHT));
    
    VFX_OBJ_CREATE(m_title_frame, VfxFrame, this);
    m_title_frame->setPos(TITLE_FRAME_LALIGN, TITLE_FRAME_TALIGN);
    m_title_frame->setSize(TITLE_FRAME_WIDTH, TITLE_FRAME_HEIGHT);
    m_title_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_VIP_CONTACT_TITLE_BG));
    m_title_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    VFX_OBJ_CREATE(m_title, VfxTextFrame, m_title_frame);
    m_title->setAnchor(0, 0);
    m_title->setPos(TITLE_LALIGN, TITLE_TALIGN);
    m_title->setSize(5, 5);
    m_title->setColor(VFX_COLOR_WHITE);
    m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_VIP_CONTACT));
    m_title->forceUpdate();

    VFX_OBJ_CREATE(m_edit, VcpImageButton, this);
    m_edit->setAnchor(1.0, 0);
    m_edit->setPos((WIDTH-DEL_MODE_ICON_RALIGN), DEL_MODE_ICON_TALIGN);
    m_edit->setSize(DEL_MODE_ICON_WIDTH, DEL_MODE_ICON_HEIGHT);
    m_edit->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_DELETE_MODE));
    m_edit->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_edit->m_signalClicked.connect(this, &VappWidgetVipContact::onClickEdit);
    if (!isReady)
    {
        m_edit->setIsDisabled(VFX_TRUE);
    }

    VfxU16 itemId, buffer = SRV_PHB_INVALID_INDEX;
    VfxS16 err = 0;
    VfxBool modified = VFX_FALSE;
    VfxU8 i = 0;
    VfxS32 x = ITEM_LALIGN, y = ITEM_TALIGN;
    VfxS32 diff_y = (VappWidgetVipContactItem::ITEM_HEIGHT+ITEM_TBGAP), diff_x = (VappWidgetVipContactItem::ITEM_WIDTH+ITEM_LRGAP);    
    
    for (i = 0; i < ITEM_NUM; i++)
    {
        itemId = getNvramItemId(i);
        ReadValue(itemId, (void*)&buffer, DS_SHORT, &err);
        m_contacts_id[i] = (mmi_phb_contact_id)buffer;
        MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_NOT_INIT, i, m_contacts_id[i]);
        if (m_contacts_id[i] != SRV_PHB_INVALID_INDEX && isReady)
        {
            if (!ContactEntry::isValid(m_contacts_id[i]))
            {
                MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_INVALID);
                m_contacts_id[i] = SRV_PHB_INVALID_INDEX;
                modified = VFX_TRUE;
            }
        }
        VFX_OBJ_CREATE_EX(m_item_array[i], VappWidgetVipContactItem, this, (m_contacts_id[i], (i+1), (VfxObject*)this, isReady));

        m_item_array[i]->setPos(x, y);
        x += diff_x;
        if ((i%3) == 2)
        {
            x = ITEM_LALIGN;            
            y += diff_y;
        }        
    }

    if (modified == VFX_TRUE)
    {
        save();
    }
}
#endif

void VappWidgetVipContact::onCreateView()
{
    VappWidget::onCreateView();

    m_curr_id = -1;
	m_selected_menu_popup_id = -1;
	m_selected_sim = MMI_SIM_NONE;
    m_phb_list_cui = GRP_ID_INVALID;
    m_id = GRP_ID_INVALID;
    m_edit_mode = VFX_FALSE;
    m_card = NULL;
    m_pop = NULL;

    m_context = this;

    setCacheMode(VFX_CACHE_MODE_PREVENT);
    /* Register exit mass storage event handler */
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappWidgetVipContact::DriveListen, m_context);
#endif
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappWidgetVipContact::DriveListen, m_context);
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappWidgetVipContact::DriveListen, m_context);
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, VappWidgetVipContact::SimEventListen, m_context);
#endif
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappWidgetVipContact::DriveListen, m_context);

    VfxBool isReady = vapp_phb_check_ready();
	if (!isReady)
	{
		mmi_frm_cb_reg_event(EVT_ID_PHB_READY, VappWidgetVipContact::PhbListen, this);
	}
    MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_QUERY_PHB_READY, isReady);

#ifndef __MMI_SLIM_WIDGET_VIP_CONTACTS__
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImg->setResId(IMG_ID_VAPP_WIDGET_VIP_CONTACT_BG);
    m_bgImg->setSize(VfxSize(WIDTH, HEIGHT));
    
    VFX_OBJ_CREATE(m_title_frame, VfxFrame, this);
    m_title_frame->setPos(TITLE_FRAME_LALIGN, TITLE_FRAME_TALIGN);
    m_title_frame->setSize(TITLE_FRAME_WIDTH, TITLE_FRAME_HEIGHT);
    m_title_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_VIP_CONTACT_TITLE_BG));
    m_title_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    VFX_OBJ_CREATE(m_title, VfxTextFrame, m_title_frame);
    m_title->setAnchor(0, 0);
    m_title->setPos(TITLE_LALIGN, TITLE_TALIGN);
    m_title->setSize(5, 5);
    m_title->setColor(VFX_COLOR_WHITE);
    m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_VIP_CONTACT));
    m_title->forceUpdate();

    VFX_OBJ_CREATE(m_edit, VcpImageButton, this);
    m_edit->setAnchor(1.0, 0);
    m_edit->setPos((WIDTH-DEL_MODE_ICON_RALIGN), DEL_MODE_ICON_TALIGN);
    m_edit->setSize(DEL_MODE_ICON_WIDTH, DEL_MODE_ICON_HEIGHT);
    m_edit->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_VIP_CONTACT_DELETE_MODE));
    m_edit->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_edit->m_signalClicked.connect(this, &VappWidgetVipContact::onClickEdit);
    if (!isReady)
    {
        m_edit->setIsDisabled(VFX_TRUE);
    }

    VfxU16 itemId, buffer = SRV_PHB_INVALID_INDEX;
    VfxS16 err = 0;
    VfxBool modified = VFX_FALSE;
    VfxU8 i = 0;
    VfxS32 x = ITEM_LALIGN, y = ITEM_TALIGN;
    VfxS32 diff_y = (VappWidgetVipContactItem::ITEM_HEIGHT+ITEM_TBGAP), diff_x = (VappWidgetVipContactItem::ITEM_WIDTH+ITEM_LRGAP);    
    
    for (i = 0; i < ITEM_NUM; i++)
    {
        itemId = getNvramItemId(i);
        ReadValue(itemId, (void*)&buffer, DS_SHORT, &err);
        m_contacts_id[i] = (mmi_phb_contact_id)buffer;
        MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_NOT_INIT, i, m_contacts_id[i]);
        if (m_contacts_id[i] != SRV_PHB_INVALID_INDEX && isReady)
        {
            if (!ContactEntry::isValid(m_contacts_id[i]))
            {
                MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_INVALID);
                m_contacts_id[i] = SRV_PHB_INVALID_INDEX;
                modified = VFX_TRUE;
            }
        }
        VFX_OBJ_CREATE_EX(m_item_array[i], VappWidgetVipContactItem, this, (m_contacts_id[i], (i+1), (VfxObject*)this, isReady));

        m_item_array[i]->setPos(x, y);
        x += diff_x;
        if ((i%3) == 2)
        {
            x = ITEM_LALIGN;            
            y += diff_y;
        }        
    }

    if (modified == VFX_TRUE)
    {
        save();
    }
#else
    createAllCp();
#endif
}


void VappWidgetVipContact::onReleaseView()
{
    VfxU8 i = 0;

    VFX_OBJ_CLOSE(m_bgImg);

    if (m_card != NULL)
    {
        VFX_OBJ_CLOSE(m_card);
    }

    if (m_pop != NULL)
    {
        VFX_OBJ_CLOSE(m_pop);
    }

    if (m_opt_menu != NULL)
    {
        VFX_OBJ_CLOSE(m_opt_menu);
    }

	if (m_sim_menu != NULL)
	{
		VFX_OBJ_CLOSE(m_sim_menu);
	}
	
    for (i = 0; i < ITEM_NUM; i++)
    {
        VFX_OBJ_CLOSE(m_item_array[i]);
        m_contacts_id[i] = SRV_PHB_INVALID_INDEX;
    }

    if (m_id != GRP_ID_INVALID)
    {
        /* Close app */
		VfxApp *app = VfxApp::getObject(m_id);
		if (app != NULL && app->isValid() && app->isKindOf(VFX_OBJ_CLASS_INFO(VappWidgetVipContactApp)))
		{
        	app->exit();
		}
    }
    
    VFX_OBJ_CLOSE(m_title);
    VFX_OBJ_CLOSE(m_title_frame);
    VFX_OBJ_CLOSE(m_edit);

    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappWidgetVipContact::PhbListen, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, VappWidgetVipContact::DriveListen, m_context);
#endif
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappWidgetVipContact::DriveListen, m_context);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappWidgetVipContact::DriveListen, m_context);
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, VappWidgetVipContact::SimEventListen, m_context);
#endif
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappWidgetVipContact::DriveListen, m_context);
    

    m_context = NULL;
    
    VappWidget::onReleaseView();
}


void VappWidgetVipContact::onSerializeView(VfxArchive *ar)
{
    /* Close contact popup */
    if (m_card != NULL)
    {
        VFX_OBJ_CLOSE(m_card);
    }

    if (m_opt_menu != NULL)
    {
        VFX_OBJ_CLOSE(m_opt_menu);
    }

    if (m_sim_menu != NULL)
    {
        VFX_OBJ_CLOSE(m_sim_menu);
    }
    // Release your resources if the home screen becomes inactive.
#ifdef __MMI_SLIM_WIDGET_VIP_CONTACTS__
    if (m_bgImg) VFX_OBJ_CLOSE(m_bgImg);
    if (m_title) VFX_OBJ_CLOSE(m_title);
    if (m_title_frame) VFX_OBJ_CLOSE(m_title_frame);
    if (m_edit) VFX_OBJ_CLOSE(m_edit);

    VfxS32 i = 0;
    for (i = 0; i < ITEM_NUM; i++)
    {
        VFX_OBJ_CLOSE(m_item_array[i]);
    }
#endif
}

void VappWidgetVipContact::refreshContactItems()
{
    VfxBool modified = VFX_FALSE;
    VfxU8 i = 0;

    MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_REFRESH_ITEMS);
    for (i = 0; i < ITEM_NUM; i++)
    {
        if (m_item_array[i] != NULL)
        {
            if (m_contacts_id[i] != SRV_PHB_INVALID_INDEX)
            {
                if (!ContactEntry::isValid(m_contacts_id[i]))
                {
                    MMI_TRACE(TRACE_GROUP_1, TRC_VAPP_VIP_CONTACT_ITEM_INVALID, m_contacts_id[i]);
                    resetContactItem(i);
                    modified = VFX_TRUE;
                }
                else
                {
                    VappContactRes contact_res;
                    VappContactName contact_name;
                    
                    ContactEntry entry(m_contacts_id[i]);
                    contact_res = entry.getImage();

                    VfxImageSrc imgSrc;
                    VfxWString path = contact_res.getPath();
                    if (path.isNull() || path.isEmpty())
                    {
                        imgSrc = VfxImageSrc(IMG_PHB_DEFAULT);
                    }
                    else
                    {
                        VfxU8 *buffer = NULL;
                        VFX_ALLOC_MEM(buffer, SRV_FMGR_PATH_BUFFER_SIZE, this);
                        memset(buffer, 0, SRV_FMGR_PATH_BUFFER_SIZE);
                        app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
                        VfxChar* ext_ptr = (VfxChar*)srv_fmgr_path_get_extension_ptr((WCHAR*)buffer);
                        memset(ext_ptr, 0, app_ucs2_strlen((const kal_int8*)ext_ptr)*sizeof(VfxWChar));
                        app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)L"pbm");
                        if (srv_fmgr_fs_path_exist((const WCHAR*)path.getBuf()) == 0)
                        {
                            imgSrc = VfxImageSrc(VFX_WSTR_MEM((VfxWChar*)buffer));
                        }
                        else
                        {
                            imgSrc = VfxImageSrc(IMG_PHB_DEFAULT);
                        }
                        VFX_FREE_MEM(buffer);
                    }

                    m_item_array[i]->setPic(imgSrc);
                    m_item_array[i]->setName(m_contacts_id[i]);
                }
            }
            m_item_array[i]->enableFpButton();
        }
    }

	if (m_edit_mode)
	{
		/* Disable empty item and show delete icon on contact item because it is in edit mode */
		showEditMode();
	}
	
    if (modified == VFX_TRUE)
    {
        save();
    }
}

void VappWidgetVipContact::onRestoreView(VfxArchive *ar)
{
#ifdef __MMI_SLIM_WIDGET_VIP_CONTACTS__
    createAllCp();
#endif
    // Restore your resources if the home screen becomes active.
    if (ar != NULL && vapp_phb_check_ready())
    {
        refreshContactItems();
    }
}


void VappWidgetVipContact::onEnterEditMode()
{
    VappWidget::onEnterEditMode();

	if (m_edit_mode)
	{
    	leaveEditMode();
	}

    /* Disable vip contacts edit button */
    m_edit->setIsDisabled(VFX_TRUE);
}


void VappWidgetVipContact::onExitEditMode()
{
    m_edit->setIsDisabled(VFX_FALSE);
    VappWidget::onExitEditMode();
}

VfxU16 VappWidgetVipContact::getNvramItemId(VfxS32 index)
{
    VfxU16 itemId = NVRAM_CONTACT_1;
    switch (index)
    {
        case 0:
            itemId = NVRAM_CONTACT_1;
            break;
        case 1:
            itemId = NVRAM_CONTACT_2;
            break;
        case 2:
            itemId = NVRAM_CONTACT_3;
            break;
        case 3:
            itemId = NVRAM_CONTACT_4;
            break;
        case 4:
            itemId = NVRAM_CONTACT_5;
            break;
        case 5:
            itemId = NVRAM_CONTACT_6;
            break;
        case 6:
            itemId = NVRAM_CONTACT_7;
            break;
        case 7:
            itemId = NVRAM_CONTACT_8;
            break;
        case 8:
            itemId = NVRAM_CONTACT_9;
            break;

    }

    return itemId;
}

void VappWidgetVipContact::save(VfxS32 index)
{
    VfxU16 itemId, buffer;
    VfxS16 err = 0;
    if (index == ITEM_NUM)
    {
        VfxU8 i = 0;
        for (i = 0; i < ITEM_NUM; i++)
        {
            buffer = (VfxU16)m_contacts_id[i];
            itemId = getNvramItemId(i);
            WriteValue(itemId, (void*)&buffer, DS_SHORT, &err);
        }
    }
    else
    {
        buffer = (VfxU16)m_contacts_id[index];
        itemId = getNvramItemId(index);
        WriteValue(itemId, (void*)&buffer, DS_SHORT, &err);
    }
}


VfxPoint VappWidgetVipContact::onGetEditButtonOffset()
{
    VfxPoint point = VappWidget::onGetEditButtonOffset();
    point.x = WIDGET_EDIT_BUTTON_X;
    point.y = WIDGET_EDIT_BUTTON_Y;
    return point;
}


void VappWidgetVipContact::onDrag(VfxPenEvent &event)
{
    VappWidget::onDrag(event);
}


void VappWidgetVipContact::onMove(VfxPenEvent &event)
{
    VappWidget::onMove(event);
}


void VappWidgetVipContact::onDrop(VfxPenEvent &event)
{
    VappWidget::onDrop(event);
}


void VappWidgetVipContact::onAbort(VfxPenEvent &event)
{
    VappWidget::onAbort(event);
}


void VappWidgetVipContact::onFocus()
{
    VappWidget::onFocus();
}


void VappWidgetVipContact::onDefocus()
{
    VappWidget::onDefocus();
}

#endif /* __MMI_VUI_WIDGET_VIP_CONTACT__ */
