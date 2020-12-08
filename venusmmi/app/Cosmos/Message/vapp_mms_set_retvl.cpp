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
 *  vapp_mms_set_retvl.cpp
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
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_setting_prot.h"
#include "vapp_mms_set_retvl.h"


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
*Class VappMMSSetRetvlHomePage
****************************************************************************/
/*
* This class implement home network setting for MMS setting
*/
#ifdef __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__                
VFX_IMPLEMENT_CLASS("VappMMSSetRetvlHomePage", VappMMSSetRetvlHomePage, VfxPage);

void VappMMSSetRetvlHomePage::onInit()
{
    VfxPage::onInit(); // call base class

	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_HOME_NETWORK);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetRetvlHomePage::onTapItem);    
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

void VappMMSSetRetvlHomePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetRetvlHomePage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetRetvlHomePage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetRetvlHomePage::getCount() const
{
	return VAPP_LIST_RETVL_HOME_MAX;
}

void VappMMSSetRetvlHomePage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_retvlSet = srv_mms_get_nvram_retrieval_settings();

    switch (m_retvlSet->home_network)
    {
        case E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE:
            m_selectedIndex = VAPP_LIST_RETVL_HOME_IMMED;
			break;
        case E_HOME_NOETWORK_RETRIEVAL_DEFFERED:
            m_selectedIndex = VAPP_LIST_RETVL_HOME_DEFER;
			break;
		case E_HOME_NOETWORK_RETRIEVAL_RESTRICTED:
            m_selectedIndex = VAPP_LIST_RETVL_HOME_REJECT;
			break;
        default:
            m_selectedIndex = VAPP_LIST_RETVL_HOME_IMMED;
			break;
    }
}

VcpListMenuItemStateEnum VappMMSSetRetvlHomePage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetRetvlHomePage::getItemText(
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
		case VAPP_LIST_RETVL_HOME_IMMED:
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE);
			break;
		case VAPP_LIST_RETVL_HOME_DEFER:
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_DEFFERED);
			break;
		case VAPP_LIST_RETVL_HOME_REJECT:
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_REJECTIVE);
			break;
		default:
			text = VFX_WSTR("wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
void VappMMSSetRetvlHomePage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetRetvlHomePage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
	case VAPP_LIST_RETVL_HOME_IMMED:
		m_retvlSet->home_network = E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE;
		break;
	case VAPP_LIST_RETVL_HOME_DEFER:
		m_retvlSet->home_network = E_HOME_NOETWORK_RETRIEVAL_DEFFERED;
		break;
	case VAPP_LIST_RETVL_HOME_REJECT:
		m_retvlSet->home_network = E_HOME_NOETWORK_RETRIEVAL_RESTRICTED;
		break;
	default:
		break;
	}


	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_RETRIEVAL_SETTING,VAPP_LIST_RETRIEVAL_HOME_NETWORK));

	getMainScr()->popPage();
}

#endif




/*****************************************************************************
*Class VappMMSSetRetvlRoamPage
****************************************************************************/
/*
* This class implement roaming setting
*/
#ifdef __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__                

VFX_IMPLEMENT_CLASS("VappMMSSetRetvlRoamPage", VappMMSSetRetvlRoamPage, VfxPage);

void VappMMSSetRetvlRoamPage::onInit()
{
    VfxPage::onInit(); // call base class

	
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_ROAM_NETWORK);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setContentProvider(this);
	m_menu->setSize(getSize());
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetRetvlRoamPage::onTapItem);
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

void VappMMSSetRetvlRoamPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

void VappMMSSetRetvlRoamPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetRetvlRoamPage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

VfxU32 VappMMSSetRetvlRoamPage::getCount() const
{
	return VAPP_LIST_RETVL_ROAM_MAX;
}

void VappMMSSetRetvlRoamPage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_retvlSet = srv_mms_get_nvram_retrieval_settings();


	switch(m_retvlSet->roaming)
	{
#ifndef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
        case E_ROAMING_RETRIEVAL_AS_HOME:
            m_selectedIndex = VAPP_LIST_RETVL_ROAM_AS_HOME;
			break;
        case E_ROAMING_RETRIEVAL_IMMEDAITE:
            m_selectedIndex = VAPP_LIST_RETVL_ROAM_IMMED;
			break;
        case E_ROAMING_RETRIEVAL_DEFFERED:
            m_selectedIndex = VAPP_LIST_RETVL_ROAM_DEFER;
			break;
        case E_ROAMING_RETRIEVAL_RESTRICTED:
            m_selectedIndex = VAPP_LIST_RETVL_ROAM_REJECT;
			break;
#else
        case 0:
            m_selectedIndex = VAPP_LIST_RETVL_ROAM_NO;
			break;
        case 1:
            m_selectedIndex = VAPP_LIST_RETVL_ROAM_YES;
			break;
#endif
		default:
			break;
	}

}

VcpListMenuItemStateEnum VappMMSSetRetvlRoamPage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetRetvlRoamPage::getItemText(
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
#ifndef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
			case VAPP_LIST_RETVL_ROAM_AS_HOME:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_AS_HOME);
				break;									
			case VAPP_LIST_RETVL_ROAM_IMMED:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE);
				break;	
			case VAPP_LIST_RETVL_ROAM_DEFER:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_DEFFERED);
				break;	
			case VAPP_LIST_RETVL_ROAM_REJECT:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_REJECTIVE);
				break;

#else
            case VAPP_LIST_RETVL_ROAM_NO:
				text = VFX_WSTR_RES(STR_GLOBAL_NO);
				break;									
			case VAPP_LIST_RETVL_ROAM_YES:
				text = VFX_WSTR_RES(STR_GLOBAL_YES);
				break;	
#endif
			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
void VappMMSSetRetvlRoamPage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetRetvlRoamPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
#ifndef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
		case VAPP_LIST_RETVL_ROAM_AS_HOME:
			m_retvlSet->roaming = E_ROAMING_RETRIEVAL_AS_HOME;
			break;									
		case VAPP_LIST_RETVL_ROAM_IMMED:
			m_retvlSet->roaming = E_ROAMING_RETRIEVAL_IMMEDAITE;
			break;	
		case VAPP_LIST_RETVL_ROAM_DEFER:
			m_retvlSet->roaming = E_ROAMING_RETRIEVAL_DEFFERED;
			break;	
		case VAPP_LIST_RETVL_ROAM_REJECT:
			m_retvlSet->roaming = E_ROAMING_RETRIEVAL_RESTRICTED;
			break;
#else
        case VAPP_LIST_RETVL_ROAM_NO:
			m_retvlSet->roaming = 0;
			break;									
		case VAPP_LIST_RETVL_ROAM_YES:
			m_retvlSet->roaming = 1;
			break;	
#endif
		default:
			break;
	}


  

	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_RETRIEVAL_SETTING,VAPP_LIST_RETRIEVAL_ROAMING_NETWORK));

	getMainScr()->popPage();
}
#endif
#endif /* __MMI_MMS_2__  */
