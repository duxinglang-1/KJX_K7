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
 *  vapp_mms_slide_edi.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
extern "C" {
#include "Mmi_frm_gprot.h"
#include "FrameworkGprot.h"
#include "App_str.h"
#include "mmi_inet_app_trc.h"
#include "vapp_mms_appcore.h"
}
#include "vapp_mms_setting_prot.h"
#include "vapp_mms_slide_edi.h"
#include "../xml/vfx_xml_loader.h"

#include "vcp_status_icon_bar.h"
#include "vcp_include.h"
#include "vcp_navi_title_bar.h"
#include "vapp_mms_viewer.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
//void vapp_mms_creation_mode_setting_launch(VappMMSSettingScreen *parent);
/***************************************************************************** 
 * Function
 *****************************************************************************/
 
//VappMMSSettingScreen *scr;
#ifdef __MMI_MMS_SETTING_COMPOSE_SLIDE__

VFX_IMPLEMENT_CLASS("VappMMSSetSlideEdiPage", VappMMSSetSlideEdiPage, VfxPage);

void VappMMSSetSlideEdiPage::onInit()
{
    VfxPage::onInit(); // call base class
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
	m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MMS_USER_DEFINED));
	//titleBar->setSubtitle(VFX_WSTR("Test Subtitle\!"));
	this->setTopBar(m_titleBar); 
	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0,0);
	m_form->setSize(320, 480);
    m_form->setSize(getSize());
	VcpTextEditor *m_textInput;
	VFX_OBJ_CREATE(m_slideTime, VcpFormItemTextInput, m_form);
	//m_slideTime->setText((VfxWChar *)m_slideBuff);
	m_textInput = m_slideTime->getTextBox();
	VfxS32 num = atoi((const char *)m_slideBuff);
    if( 0 == num)
    {
        m_textInput->setText(
                                VFX_WSTR_EMPTY,
                                2,
                                VCP_TEXT_ENCODING_UCS2);
    }
    else
    {
        m_textInput->setText(
                            (VfxWChar *)m_slideBuff,
                            2,
                            VCP_TEXT_ENCODING_UCS2);
    }
	m_textInput->setIME(IMM_INPUT_TYPE_NUMERIC,IME_SETTING_FLAG_NONE);
    m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
	VfxWString temp;
	temp = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DEFAULT_SLIDE_TIMING);
	temp += VFX_WSTR(" (");
	temp += VFX_WSTR_RES(STR_ID_VAPP_MMS_SECONDS);
	temp += VFX_WSTR(")");
	m_slideTime->setLabelText(temp);
	m_form->addItem(m_slideTime, 0);
	m_form->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	VFX_OBJ_CREATE(m_bar, VcpToolBar, this);
	m_bar->addItem(VAPP_MMS_EDI_EDITOR_SEG_BUTTON_SAVE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	m_bar->addItem(VAPP_MMS_EDI_EDITOR_SEG_BUTTON_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	m_bar->m_signalButtonTap.connect(this, &VappMMSSetSlideEdiPage::onMMSEditSegClick);
	m_bar->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	setBottomBar(m_bar);
}

void VappMMSSetSlideEdiPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return VFX_SCR_ROTATE_TYPE_90;
	//return param.rotateTo;
}

void VappMMSSetSlideEdiPage::onRotate(const VfxScreenRotateParam &param)
{
    switch(param.rotateTo)
    {  
        case VFX_SCR_ROTATE_TYPE_NORMAL:                
        case VFX_SCR_ROTATE_TYPE_90:                
        case VFX_SCR_ROTATE_TYPE_180:                
        case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
            m_bar->setLayout(param.rotateTo);
        break;
        default:
        break;
    }
    // VtstToolBarAppBasePage::onRotate(param);
}

VappMMSSetSlideEdiPage::VappMMSSetSlideEdiPage()
{
	VfxChar tempBuff[10];
	VfxU8 userDefinedTime = srv_mms_compose_setting_user_defined_slide_time();
	srv_mms_get_nvram_compose_settings();
	memset(m_slideBuff,0,2);
	sprintf(tempBuff,"%d",userDefinedTime);
	mmi_asc_to_ucs2((char*)m_slideBuff,(char*)tempBuff);
}

void VappMMSSetSlideEdiPage::onMMSEditSegClick(VfxObject *sender, VfxId id)
{
	srv_mms_nvram_compose_settings_struct* composeSet = srv_mms_get_nvram_compose_settings();
	if(id == VAPP_MMS_EDI_EDITOR_SEG_BUTTON_SAVE)
	{
		VfxS32 slideTime; 
		VfxS32 len=10;
		const VfxWChar *inputText = m_slideTime->getText();	
		//slideTime = app_ucs2_atoi((VfxS8*)(m_textInput->getText()));
		if(mmi_ucs2strlen((const char*)inputText))
		{
			
			//mmi_ucs2toi((const char*)((m_slideTime->getTextBox())->getText()), &slideTime, &len);
			mmi_ucs2toi((const char*)(inputText), &slideTime, &len);
		}
		else
		{
			slideTime = 0;
		}
			
        if(slideTime == 0)
        {
            VappMmsPopup popup(STR_ID_VAPP_MMS_SLIDE_TIME_ZERO_ERROR, VCP_POPUP_TYPE_FAILURE, findScreen(), NULL);           
		    popup.displayPopup();
            return;
        }
		composeSet->default_slide_time = slideTime;
		composeSet->max_no_pages = slideTime;
        composeSet->add_drm = VAPP_LIST_SLIDE_TIME_USER;
		srv_mms_write_nvram_compose_settings();
		m_onSetSlideTimeRefresh.emit(VAPP_LIST_SLIDE_TIME_USER);
		getMainScr()->popPage();
		getMainScr()->popPage();
	}
	else if (id == VAPP_MMS_EDI_EDITOR_SEG_BUTTON_CANCEL)
	{
		m_onSetSlideTimeRefresh.emit(VAPP_LIST_SLIDE_TIME_USER);
		getMainScr()->popPage();
	}
}


/*****************************************************************************
*Class VappMMSSetSlideTimePage
****************************************************************************/
/*
* This class implement creation mode option Free, Warning, Restricted
*/

VFX_IMPLEMENT_CLASS("VappMMSSetSlideTimePage", VappMMSSetSlideTimePage, VfxPage);

void VappMMSSetSlideTimePage::onInit()
{
    VfxPage::onInit(); // call base class

	
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_SLIDE_TIME);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);
	m_menu->setSize(getSize());
	m_menu->setContentProvider(this);
    m_menu->m_signalItemTapped.connect(this, &VappMMSSetSlideTimePage::onTapItem);
    m_menu->m_signalItemSelectionStateChanged.connect(this, &VappMMSSetSlideTimePage::onSelectionChanged);
	m_menu->setCellStyle(/*VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT_EX*/VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	m_menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE,VFX_TRUE);
	m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
	m_menu->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	m_menu->updateItem(0);
	VfxXmlLoader::loadEnd();

}

void VappMMSSetSlideTimePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
	
}

VfxU32 VappMMSSetSlideTimePage::getCount() const 
{
	return VAPP_LIST_SLIDE_TIME_MAX;
}

void VappMMSSetSlideTimePage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

    if(isBackward)
    {
        m_menu->updateItem(VAPP_LIST_SLIDE_TIME_USER);
        m_menu->updateItem(m_selectedIndex);
	    m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_COMPOSE_SETTING,VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING));
    }

	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetSlideTimePage::onRotate(
    const VfxScreenRotateParam &param 
)
{
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}


void VappMMSSetSlideTimePage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_composeSet = srv_mms_get_nvram_compose_settings();
	m_selectedIndex = m_composeSet->add_drm;
	m_menu->setVisibleMenuRegion(-1, m_selectedIndex, VFX_FALSE);
}

void VappMMSSetSlideTimePage::onSetSlideTimeRefresh(VfxU32 index)
{
	//COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_SETTING_REFRESH, index);
	m_menu->updateItem(index);
    m_menu->updateItem(m_selectedIndex);
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_COMPOSE_SETTING,VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING));
}

VcpListMenuItemStateEnum VappMMSSetSlideTimePage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetSlideTimePage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
   	const char* slideTimeMenu[8] ={"3 ","5 ", "8 ", "15 ", "20 ", "30 ", "60 ", "User defined"};
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {										
		VfxChar tempBuff[30];

		if(index == VAPP_LIST_SLIDE_TIME_USER)
		{
			/* user****** defined */
			text = VFX_WSTR_RES(STR_ID_VAPP_MMS_USER_DEFINED);
		}
		else
		{
		mmi_asc_to_ucs2((char*)tempBuff, (char*)slideTimeMenu[index]);
			text = VFX_WSTR_MEM((VfxWChar *)tempBuff);
			text += VFX_WSTR_RES(STR_ID_VAPP_MMS_SECONDS);
		}


		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

		return VFX_TRUE;
	}
	else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
	{
		if(index == VAPP_LIST_SLIDE_TIME_USER)
		{
			VfxChar tempBuff[30];
			VfxChar tempUCS2Buff[30];			
			VfxU8 userDefinedTime = srv_mms_compose_setting_user_defined_slide_time();
			if(userDefinedTime)
			{
				sprintf(tempBuff,"%d ",userDefinedTime);
			mmi_asc_to_ucs2((char*)tempUCS2Buff,(char*)tempBuff);
			//text = VFX_WSTR_RES(STR_ID_UMMS_SETTINGS_DEFAULT_SLIDE_TIMING);
			text = VFX_WSTR_MEM((VfxWChar *)tempUCS2Buff);
			if(userDefinedTime == 1)
			{
				text += VFX_WSTR_RES(STR_ID_VAPP_MMS_SECOND);
			}
			else
			{
				text += VFX_WSTR_RES(STR_ID_VAPP_MMS_SECONDS);
			}
			}
			else
			{
				text = VFX_WSTR_RES(STR_GLOBAL_NONE);				
			}
			return VFX_TRUE;
		}
		else
		{
			text = VFX_WSTR_NULL;
		}
		
	}
	else
	{
		text = VFX_WSTR_NULL;
	}
	return VFX_FALSE;
	
}
void VappMMSSetSlideTimePage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetSlideTimePage::onTapItem(VcpListMenu *menu,VfxU32 index)
{

    switch(index)
    {			
        case VAPP_LIST_SLIDE_TIME_USER:
            VappMMSSetSlideEdiPage  *mmsSlideEdiPage;
            VFX_OBJ_CREATE(mmsSlideEdiPage, VappMMSSetSlideEdiPage, getMainScr());
            mmsSlideEdiPage->m_onSetSlideTimeRefresh.connect(this, &VappMMSSetSlideTimePage::onSetSlideTimeRefresh);
            getMainScr()->pushPage(0, mmsSlideEdiPage);
            break;
            case VAPP_LIST_SLIDE_TIME_3:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 3;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        case VAPP_LIST_SLIDE_TIME_5:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 5;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        case VAPP_LIST_SLIDE_TIME_8:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 8;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        case VAPP_LIST_SLIDE_TIME_15:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 15;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        case VAPP_LIST_SLIDE_TIME_20:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 20;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        case VAPP_LIST_SLIDE_TIME_30:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 30;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        case VAPP_LIST_SLIDE_TIME_60:
            m_selectedIndex = index;
            m_composeSet->add_drm = m_selectedIndex;
            m_composeSet->default_slide_time = 60;
            srv_mms_write_nvram_compose_settings();
            getMainScr()->popPage();
        break;
        default:
        break;
    }
    m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_COMPOSE_SETTING,VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING));
}

void VappMMSSetSlideTimePage::onSelectionChanged
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


VfxBool VappMMSSetSlideTimePage::getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{
	if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
		if(index == VAPP_LIST_SLIDE_TIME_USER)
		{
			image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
			return VFX_TRUE;
		}
		else
		{
			return VFX_FALSE;
		}
    }
	return VFX_FALSE;
}	
#endif
#endif /* __MMI_MMS_2__  */
