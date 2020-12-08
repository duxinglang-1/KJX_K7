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
 *  vapp_mmsCreationModeSetting .cpp
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
#include "vapp_mms_set_cm.h"


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
*Class VappMMSSetCreationPage
****************************************************************************/
/*
* This class implement creation mode option Free, Warning, Restricted
*/
#ifdef __MMI_MMS_SETTING_COMPOSE_CREATION__

VFX_IMPLEMENT_CLASS("VappMMSSetCreationPage", VappMMSSetCreationPage, VfxPage);

void VappMMSSetCreationPage::onInit()
{
    VfxPage::onInit(); // call base class

       	
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_CREATION_MODE);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
	m_menu->m_signalItemTapped.connect(this, &VappMMSSetCreationPage::onTapItem);
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

void VappMMSSetCreationPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetCreationPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetCreationPage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetCreationPage::getCount() const
{
	return VAPP_LIST_COMPOSE_CREATION_MAX;
}

void VappMMSSetCreationPage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_composeSet = srv_mms_get_nvram_compose_settings();

	switch(m_composeSet->creation_mode)
	{
	case E_CREAT_MODE_RESTRICTED:
		m_selectedIndex = VAPP_LIST_COMPOSE_CREATION_RESTRICTED;
		break;
	case E_CREAT_MODE_WARNING:
		m_selectedIndex = VAPP_LIST_COMPOSE_CREATION_WARNING;
		break;
	case E_CREAT_MODE_FREE:
		m_selectedIndex = VAPP_LIST_COMPOSE_CREATION_FREE;
		break;
	}	
}

VcpListMenuItemStateEnum VappMMSSetCreationPage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetCreationPage::getItemText(
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
		case VAPP_LIST_COMPOSE_CREATION_FREE:
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_FREE);
			break;
		case VAPP_LIST_COMPOSE_CREATION_WARNING:
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_WARNING);
			break;
		case VAPP_LIST_COMPOSE_CREATION_RESTRICTED:
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_RESTRICTED);
			break;
		default:
			text = VFX_WSTR("wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
void VappMMSSetCreationPage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetCreationPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
	case VAPP_LIST_COMPOSE_CREATION_FREE:
		m_selectedIndex = E_CREAT_MODE_FREE;
		break;
	case VAPP_LIST_COMPOSE_CREATION_WARNING:
		m_selectedIndex = E_CREAT_MODE_WARNING;
		break;
	case VAPP_LIST_COMPOSE_CREATION_RESTRICTED:
		m_selectedIndex = E_CREAT_MODE_RESTRICTED;
		break;
	default:
		break;
	}

	m_composeSet->creation_mode = m_selectedIndex;

	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_COMPOSE_SETTING,VAPP_LIST_COMPOSE_CREATION_SETTING));

	getMainScr()->popPage();
}

void VappMMSSetCreationPage::onSelectionChanged
(
    VcpListMenu *menu, // Sender
	VfxU32 index,        // List item index
	VcpListMenuItemStateEnum state        // The new state
)
{
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
#endif
}


#endif

/*****************************************************************************
*Class VappMMSSetPicResizePage
****************************************************************************/
/*
* This class implement picture resize option
*/
#ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__

VFX_IMPLEMENT_CLASS("VappMMSSetPicResizePage", VappMMSSetPicResizePage, VfxPage);

void VappMMSSetPicResizePage::onInit()
{
    VfxPage::onInit(); // call base class
	
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_PICTURE_RESIZE);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetPicResizePage::onTapItem);
    m_menu->m_signalItemSelectionStateChanged.connect(this, &VappMMSSetPicResizePage::onSelectionChanged);
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


void VappMMSSetPicResizePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetPicResizePage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetPicResizePage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetPicResizePage::getCount() const
{
	return VAPP_LIST_COMPOSE_PICTURE_RESIZE_MAX;
}

void VappMMSSetPicResizePage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_composeSet = srv_mms_get_nvram_compose_settings();


	switch(m_composeSet->layout)
	{

		case E_PICTURE_RESIZE_10KB:
			m_selectedIndex = VAPP_LIST_COMPOSE_PICTURE_RESIZE_10KB;
			break;									
		case E_PICTURE_RESIZE_50KB:
			m_selectedIndex = VAPP_LIST_COMPOSE_PICTURE_RESIZE_50KB;
			break;	
		case E_PICTURE_RESIZE_100KB:
			m_selectedIndex = VAPP_LIST_COMPOSE_PICTURE_RESIZE_100KB;
			break;
		case E_PICTURE_RESIZE_OFF:
			m_selectedIndex = VAPP_LIST_COMPOSE_PICTURE_RESIZE_OFF;
			break;
		default:
			break;
	}

}

VcpListMenuItemStateEnum VappMMSSetPicResizePage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetPicResizePage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
   VfxWString temp;
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		
		switch(index)
		{			
			case VAPP_LIST_COMPOSE_PICTURE_RESIZE_10KB:
				temp = VFX_WSTR("10 ");
				//temp += VFX_WSTR_RES(STR_ID_VAPP_MMS_KB);
				temp += VFX_WSTR("KB");
				text = temp;
				break;									
			case VAPP_LIST_COMPOSE_PICTURE_RESIZE_50KB:
				temp = VFX_WSTR("50 ");
				temp += VFX_WSTR("KB");
				text = temp;
				break;	
			case VAPP_LIST_COMPOSE_PICTURE_RESIZE_100KB:
				temp = VFX_WSTR("100 ");
				temp += VFX_WSTR("KB");
				text = temp;
				break;	
			case VAPP_LIST_COMPOSE_PICTURE_RESIZE_OFF:
				text = VFX_WSTR_RES(STR_GLOBAL_OFF);
				break;
			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
void VappMMSSetPicResizePage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetPicResizePage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
		case VAPP_LIST_COMPOSE_PICTURE_RESIZE_10KB:
			m_composeSet->layout = E_PICTURE_RESIZE_10KB;
			break;									
		case VAPP_LIST_COMPOSE_PICTURE_RESIZE_50KB:
			m_composeSet->layout = E_PICTURE_RESIZE_50KB;
			break;	
		case VAPP_LIST_COMPOSE_PICTURE_RESIZE_100KB:
			m_composeSet->layout = E_PICTURE_RESIZE_100KB;
			break;	
		case VAPP_LIST_COMPOSE_PICTURE_RESIZE_OFF:
			m_composeSet->layout = E_PICTURE_RESIZE_OFF;
			break;
		default:
			break;
	}

	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_COMPOSE_SETTING,VAPP_LIST_COMPOSE_PICTURE_RESIZING_SETTING));

	getMainScr()->popPage();
}

void VappMMSSetPicResizePage::onSelectionChanged
(
    VcpListMenu *menu, // Sender
	VfxU32 index,        // List item index
	VcpListMenuItemStateEnum state        // The new state
)
{

}
#endif
#endif /* __MMI_MMS_2__ */
