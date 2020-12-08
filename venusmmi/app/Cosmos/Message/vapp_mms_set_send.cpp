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
 *  vapp_mms_set_send.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "MMI_include.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_setting_prot.h"
#include "vapp_mms_set_send.h"


#include "vcp_status_icon_bar.h"
#include "vcp_include.h"
#include "vcp_navi_title_bar.h"
#include "../xml/vfx_xml_loader.h"
 extern "C" {
   #include "MmsSrvGprot.h"
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

/*****************************************************************************
*Class VappMMSSetSendPrioPage
****************************************************************************/
/*
* This class implement priority setting for sending setting
*/
#ifdef __MMI_MMS_SETTING_SENDING_PRIORITY__

VFX_IMPLEMENT_CLASS("VappMMSSetSendPrioPage", VappMMSSetSendPrioPage, VfxPage);

void VappMMSSetSendPrioPage::onInit()
{
    VfxPage::onInit(); // call base class

	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_PRIORITY);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetSendPrioPage::onTapItem);   
	m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
	m_menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE,VFX_TRUE);
	m_menu->updateItem(0);
	m_menu->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	VfxXmlLoader::loadEnd();

}

void VappMMSSetSendPrioPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetSendPrioPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetSendPrioPage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetSendPrioPage::getCount() const
{
	return VAPP_LIST_SENDING_PRIO_MAX;
}

void VappMMSSetSendPrioPage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_sendSet = srv_mms_get_nvram_sending_settings();

    switch (m_sendSet->priority)
    {
        case E_PRIORITY_LOW:
            m_selectedIndex = VAPP_LIST_SENDING_PRIO_LOW;
			break;
        case E_PRIORITY_NORMAL:
            m_selectedIndex = VAPP_LIST_SENDING_PRIO_NORMAL;
			break;
		case E_PRIORITY_HIGH:
            m_selectedIndex = VAPP_LIST_SENDING_PRIO_HIGH;
			break;
        default:
            m_selectedIndex = VAPP_LIST_SENDING_PRIO_NORMAL;
			break;
    }
}

VcpListMenuItemStateEnum VappMMSSetSendPrioPage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetSendPrioPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
   
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		
		switch(index)
		{			
		case VAPP_LIST_SENDING_PRIO_LOW:
			text = VFX_WSTR_RES(STR_GLOBAL_LOW);
			break;
		case VAPP_LIST_SENDING_PRIO_NORMAL:
			text = VFX_WSTR_RES(STR_GLOBAL_NORMAL);
			break;
		case VAPP_LIST_SENDING_PRIO_HIGH:
			text = VFX_WSTR_RES(STR_GLOBAL_HIGH);
			break;
		default:
			text = VFX_WSTR("wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}

VfxBool VappMMSSetSendPrioPage::getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{
	if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
		if(index == VAPP_LIST_SENDING_PRIO_LOW)
		{
			image.setResId(IMG_ID_VENUS_MMS_LOW_PRIORITY);
			return VFX_TRUE;
		}else if(index == VAPP_LIST_SENDING_PRIO_NORMAL)
		{
			image.setResId(IMG_ID_VENUS_MMS_NORMAL_PRIORITY);
			return VFX_TRUE;
		}else if(index == VAPP_LIST_SENDING_PRIO_HIGH)
		{
			image.setResId(IMG_ID_VENUS_MMS_HIGH_PRIORITY);
			return VFX_TRUE;
		}

		else
		{
			return VFX_FALSE;
		}
    }
	return VFX_FALSE;
}	




void VappMMSSetSendPrioPage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetSendPrioPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
	case VAPP_LIST_SENDING_PRIO_LOW:
		m_sendSet->priority = E_PRIORITY_LOW;
		break;
	case VAPP_LIST_SENDING_PRIO_NORMAL:
		m_sendSet->priority = E_PRIORITY_NORMAL;
		break;
	case VAPP_LIST_SENDING_PRIO_HIGH:
		m_sendSet->priority = E_PRIORITY_HIGH;
		break;
	default:
		break;
	}

	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_SENDNG_SETTING,VAPP_LIST_SENDING_PRIORITY));

	getMainScr()->popPage();
}

#endif




/*****************************************************************************
*Class VappMMSSetSendValidPage
****************************************************************************/
/*
* This class implement sending setting-validity period
*/
#ifdef __MMI_MMS_SETTING_SENDING_VALIDITY__                

VFX_IMPLEMENT_CLASS("VappMMSSetSendValidPage", VappMMSSetSendValidPage, VfxPage);

void VappMMSSetSendValidPage::onInit()
{
    VfxPage::onInit(); // call base class
	
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_VALIDITY_PERIOD);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetSendValidPage::onTapItem);    
	m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
	m_menu->updateItem(0);
	m_menu->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	VfxXmlLoader::loadEnd();

}

void VappMMSSetSendValidPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetSendValidPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetSendValidPage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetSendValidPage::getCount() const
{
	return VAPP_LIST_SENDING_VALID_MAX;
}

void VappMMSSetSendValidPage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_sendSet = srv_mms_get_nvram_sending_settings();


	switch(m_sendSet->validity_period)
	{
        case E_VALIDITY_PERIOD_1HR:
            m_selectedIndex = VAPP_LIST_SENDING_VALID_1HR;
			break;
        case E_VALIDITY_PERIOD_6HRS:
            m_selectedIndex = VAPP_LIST_SENDING_VALID_6HR;
			break;
        case E_VALIDITY_PERIOD_12HRS:
            m_selectedIndex = VAPP_LIST_SENDING_VALID_12HR;
			break;
        case E_VALIDITY_PERIOD_1DAY:
            m_selectedIndex = VAPP_LIST_SENDING_VALID_1DAY;
			break;
		case E_VALIDITY_PERIOD_1WEEK:
			m_selectedIndex = VAPP_LIST_SENDING_VALID_1WEEK;
			break;
		case E_VALIDITY_PERIOD_MAX:
			m_selectedIndex = VAPP_LIST_SENDING_VALID_MAXIMUM;
			break;
		default:
			break;
	}

}

VcpListMenuItemStateEnum VappMMSSetSendValidPage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetSendValidPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
   
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		
		switch(index)
		{			
			case VAPP_LIST_SENDING_VALID_1HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_1_HR);
				break;									
			case VAPP_LIST_SENDING_VALID_6HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_6_HRS);
				break;	
			case VAPP_LIST_SENDING_VALID_12HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_12_HRS);
				break;	
			case VAPP_LIST_SENDING_VALID_1DAY:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_1_DAY);
				break;
			case VAPP_LIST_SENDING_VALID_1WEEK:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_1_WEEK);
				break;
			case VAPP_LIST_SENDING_VALID_MAXIMUM:
				text = VFX_WSTR_RES(STR_GLOBAL_MAXIMUM);
				break;
			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
void VappMMSSetSendValidPage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetSendValidPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
			case VAPP_LIST_SENDING_VALID_1HR:
				m_sendSet->validity_period = E_VALIDITY_PERIOD_1HR;
				break;									
			case VAPP_LIST_SENDING_VALID_6HR:
				m_sendSet->validity_period = E_VALIDITY_PERIOD_6HRS;
				break;	
			case VAPP_LIST_SENDING_VALID_12HR:
				m_sendSet->validity_period = E_VALIDITY_PERIOD_12HRS;
				break;	
			case VAPP_LIST_SENDING_VALID_1DAY:
				m_sendSet->validity_period = E_VALIDITY_PERIOD_1DAY;
				break;
			case VAPP_LIST_SENDING_VALID_1WEEK:
				m_sendSet->validity_period = E_VALIDITY_PERIOD_1WEEK;
				break;
			case VAPP_LIST_SENDING_VALID_MAXIMUM:
				m_sendSet->validity_period = E_VALIDITY_PERIOD_MAX;
				break;
		default:
			break;
	}



	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_SENDNG_SETTING,VAPP_LIST_SENDING_VALIDITY_PERIOD));

	getMainScr()->popPage();
}
#endif

/*****************************************************************************
*Class VappMMSSetSendDeliveryPage
****************************************************************************/
/*
* This class implement sending setting-validity period
*/
#ifdef __MMI_MMS_SETTING_DELIVERY_TIME__                

VFX_IMPLEMENT_CLASS("VappMMSSetSendDeliveryPage", VappMMSSetSendDeliveryPage, VfxPage);

void VappMMSSetSendDeliveryPage::onInit()
{
    VfxPage::onInit(); // call base class

	
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_DELIVERY_TIME);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetSendDeliveryPage::onTapItem);
	m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
	m_menu->updateItem(0);
	m_menu->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	VfxXmlLoader::loadEnd();

}


void VappMMSSetSendDeliveryPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetSendDeliveryPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetSendDeliveryPage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetSendDeliveryPage::getCount() const
{
	return VAPP_LIST_SENDING_DELIVERY_MAX;
}

void VappMMSSetSendDeliveryPage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_sendSet = srv_mms_get_nvram_sending_settings();


	switch(m_sendSet->delivery_time)
	{
        case E_IMMEDIATE:
            m_selectedIndex = VAPP_LIST_SENDING_DELIVERY_IMMED;
			break;
        case E_1_HR:
            m_selectedIndex = VAPP_LIST_SENDING_DELIVERY_1HR;
			break;
        case E_2_HR:
            m_selectedIndex = VAPP_LIST_SENDING_DELIVERY_2HR;
			break;
        case E_12_HRS:
            m_selectedIndex = VAPP_LIST_SENDING_DELIVERY_12HR;
			break;
        case E_24_HRS:
            m_selectedIndex = VAPP_LIST_SENDING_DELIVERY_24HR;
			break;
		default:
			break;
	}

}

VcpListMenuItemStateEnum VappMMSSetSendDeliveryPage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetSendDeliveryPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
   
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		
		switch(index)
		{			
			case VAPP_LIST_SENDING_DELIVERY_IMMED:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE);
				break;									
			case VAPP_LIST_SENDING_DELIVERY_1HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_1_HR);
				break;	
			case VAPP_LIST_SENDING_DELIVERY_2HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_2_HR);
				break;
			case VAPP_LIST_SENDING_DELIVERY_12HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_12_HRS);
				break;	
			case VAPP_LIST_SENDING_DELIVERY_24HR:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_24_HRS);
				break;

			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
void VappMMSSetSendDeliveryPage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetSendDeliveryPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
			case VAPP_LIST_SENDING_DELIVERY_IMMED:
				m_sendSet->delivery_time = E_IMMEDIATE;
				break;									
			case VAPP_LIST_SENDING_DELIVERY_1HR:
				m_sendSet->delivery_time = E_1_HR;
				break;	
			case VAPP_LIST_SENDING_DELIVERY_2HR:
				m_sendSet->delivery_time = E_2_HR;
				break;	
			case VAPP_LIST_SENDING_DELIVERY_12HR:
				m_sendSet->delivery_time = E_12_HRS;
				break;	
			case VAPP_LIST_SENDING_DELIVERY_24HR:
				m_sendSet->delivery_time = E_24_HRS;
				break;
		default:
			break;
	}

	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_SENDNG_SETTING,VAPP_LIST_SENDING_DELIVERY_TIME));

	getMainScr()->popPage();
}
#endif
#endif /* __MMI_MMS_2__  */
