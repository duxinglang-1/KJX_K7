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
 *  vapp_shell_settings.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  General settings' implement file
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_SETTINGS__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
	#include "MMI_include.h"

	#include "GpioSrvGprot.h"
	#include "SettingGprots.h"
	#include "DataAccountGprot.h"

	#include "MainMenuDef.h"
	#include "SettingResDef.h"
	#include "WPSSProtos.h"
#ifdef __MMI_BT_SUPPORT__ 
	#include "ConnectivityResDef.h"
	#include "Btcmsrvgprot.h"
	#include "BtcmCuiGprot.h"
	#include "BtmmiScr.h"
	#include "BTMMIScrGprots.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
	#include "DataAccountResDef.h"
	#include "DtcntSrvGprot.h"
	#include "DtcntSrvIprot.h"
#endif
	#include "PhoneSetupGprots.h"

	#include "CommonScreens.h"

	#include "PhnsetGpio.h"
	#include "Gpiosrvprot.h"
        #include "mmi_rp_app_gpio_def.h"
	#include "ModeSwitchSrvGprot.h"
	#include "ModeSwitchAppGprot.h"
	#include "ModeSwitchAppProt.h"
	#include "mmi_rp_app_mode_switch_def.h"
	#include "mmi_rp_app_bluetooth_def.h"
	#include "mmi_rp_app_mainmenu_def.h"
	#include "ProfilesSrvGprot.h"
	#include "ProfilesSrv.h"
	#include "ProfilesAppGprot.h"
	#include "ScrLockerGprot.h"

	#include "NetSetAppGprot.h"
	#include "FlightModeGprot.h"
	#include "IdleAppProt.h"
#include "TetheringSrvGprot.h"
    #include "mmi_rp_app_dataaccount_def.h"
}

#include "trc\vadp_app_trc.h"
#include "vapp_shell_settings.h"
#include "mmi_rp_app_shellapp_base_def.h"

#ifdef __MMI_AUTO_KEYPAD_LOCK__
#include "mmi_rp_app_scr_locker_def.h"
#endif

    #include "MMIDataType.h"
    #include "kal_non_specific_general_types.h"
    #include "vfx_cpp_base.h"
    #include "vfx_input_event.h"
    #include "vfx_datatype.h"
    #include "vfx_control.h"
    #include "vfx_primitive_frame.h"
    #include "vfx_sys_memory.h"
    #include "vfx_object.h"
    #include "mmi_rp_app_venus_shell_settings_def.h"
    #include "vfx_basic_type.h"
    #include "vfx_signal.h"
    #include "vfx_text_frame.h"
    #include "vrt_datatype.h"
    #include "vcp_switch.h"
    #include "vfx_string.h"
    #include "vcp_list_menu.h"
    #include "vfx_frame.h"
    #include "vapp_shell_page_order.h"
    #include "vapp_shell_panel_cfg.h"
    #include "kal_release.h"
    #include "vcp_command_title.h"
    #include "vcp_state_image.h"
    #include "vcp_inline_menu.h"
    #include "GlobalResDef.h"
    #include "mmi_rp_app_dataaccount_def.h"
    #include "kal_trace.h"
    #include "vfx_system.h"
    #include "mmi_rp_srv_flight_mode_def.h"
    #include "mmi_rp_srv_wallpaper_def.h"
    #include "vfx_image_src.h"
    #include "CustDataRes.h"
    #include "vapp_shell_panel.h"
    #include "vrt_system.h"
    #include "NetSetSrvGprot.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "custom_mmi_default_value.h"
    #include "vcp_popup.h"
    #include "gpiosrvgprot.h"
    #include "vfx_animation.h"
    #include "vfx_transform.h"
    
/***************************************************************************** 
 * Definition
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if(!(p)){return;}
#define RETURN_VAL_IF_FAIL(p, ret) if(!(p)){ return (ret);}

// inline definition
#define INLINE_ENUM(_enumName) VappShellSettingContentProvider::##_enumName
#define SETTING_FIELD(_fieldName) VappShellSettingContentProvider::##_fieldName

#define DECLEAR_INLINE_TABLE(size)	\
		static const VcpInlineCellLookup s_cellTable[size]
		
#define BEGIN_INLINE_TABLE(_className) \
		const _className::InlineCell _className::s_cellTable[] = \
		{

#define END_INLINE_TABLE(_className) };

#define INLINE_ITEM(item, cell, type) {INLINE_ENUM(item), cell, type},

typedef void (*FuncPtrBool)(MMI_BOOL);

#if (MMI_MAX_SIM_NUM >= 2)
#define STR_ID_MODE_SWITCH_SETTING STR_GLOBAL_0
#endif

/***************************************************************************** 
 * class VappShellBrightnessSelPopup
 *****************************************************************************/
VfxBool VappShellWaitingPopup::onKeyInput(VfxKeyEvent & event)
{
	return VFX_TRUE;
}

/***************************************************************************** 
 * class VappShellBrightnessSelPopup
 *****************************************************************************/
VappShellBrightnessSelPopup::VappShellBrightnessSelPopup() :
	m_level(0)
{

}

VappShellBrightnessSelPopup::VappShellBrightnessSelPopup(const VfxU16 &level) : 
	m_level(level - 1)
{
	
}
void VappShellBrightnessSelPopup::onInit(void)
{
	VfxControl::onInit();

	setAnchor(0.5F, 0.5F);

	VfxImageFrame *bgImage;
	VFX_OBJ_CREATE(bgImage, VfxImageFrame, this);
	bgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	bgImage->setResId(VAPP_SHELL_IMG_SETTINGS_BRIGHTNESS_BG);
	bgImage->setBounds(0, 0, WIDTH, HEIGHT);
	setBounds(bgImage->getBounds());
	
	VfxImageFrame *sunImage;
	VFX_OBJ_CREATE(sunImage, VfxImageFrame, this);
	sunImage->setResId(VAPP_SHELL_IMG_SETTINGS_BRIGHTNESS_SUN);	
	sunImage->setPos(SUN_POS_X, SUN_POS_Y);

	VfxS32 xPos, yPos;

	xPos = BAR1_POS_X + BAR_WIDTH / 2;
	yPos = BAR1_POS_Y + BAR1_HEIGHT / 2;
	for (VfxS32 i = 0; i < MAX_LEVELS; i++)
	{
		VFX_OBJ_CREATE(m_levelBar[i], VfxImageFrame, this);
		m_levelBar[i]->setAnchor(0.5F, 0.5F);
		m_levelBar[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
		xPos += (BAR_WIDTH + BAR_INTERVAL) * (i == 0 ? 0 : 1);		
		m_levelBar[i]->setPos(xPos, yPos);
	}

	// the first level bar will always be hilite image
	m_levelBar[0]->setResId(VAPP_SHELL_IMG_SETTINGS_BRIGHTNESS_BAR_HILITE);
	m_levelBar[0]->setBounds(0, 0, BAR_WIDTH, BAR1_HEIGHT);
	// set other bar's image
	updateLevelBar();
	
}

void VappShellBrightnessSelPopup::setCurrentLevel(const VfxU8 &level)
{
	RETURN_IF_FAIL(level > MAX_LEVELS);

	m_level = level - 1;
	updateLevelBar();
}

void VappShellBrightnessSelPopup::updateLevelBar(void)
{
	static const S32 barHeight[MAX_LEVELS] = 
	{
		BAR1_HEIGHT, 
		BAR2_HEIGHT, 
		BAR3_HEIGHT, 
		BAR4_HEIGHT, 
		BAR5_HEIGHT
	};
	
	for (VfxS32 i = 1; i < MAX_LEVELS; i++)
	{
		if (i <= m_level)
		{
			m_levelBar[i]->setResId(VAPP_SHELL_IMG_SETTINGS_BRIGHTNESS_BAR_HILITE);
		}
		else
		{
			m_levelBar[i]->setResId(VAPP_SHELL_IMG_SETTINGS_BRIGHTNESS_BAR_UNHILITE);	
		}
		m_levelBar[i]->setBounds(0, 0, BAR_WIDTH, barHeight[i]);
	}	
}

VfxBool VappShellBrightnessSelPopup::onPenInput(VfxPenEvent &event)
{
	VfxPoint point;

	switch(event.type)
	{
	case VFX_PEN_EVENT_TYPE_DOWN:
		m_bDrag = VFX_TRUE;
		return VFX_TRUE;

	case VFX_PEN_EVENT_TYPE_UP:
		m_bDrag = VFX_FALSE;
	case VFX_PEN_EVENT_TYPE_MOVE:
	{
	    if ((m_bDrag && event.type == VFX_PEN_EVENT_TYPE_MOVE)|| !m_bDrag)
	    {
		for (VfxS32 i = 0; i < MAX_LEVELS; i++)
		{
			point = event.getRelPos(m_levelBar[i]);
			if (m_levelBar[i]->containPoint(point))
			{
				m_level = i;
				updateLevelBar();
				m_signalLevel.emit(i + 1);
				break;
			}
		}
	    }
	}
	break;
		
	default:
		break;
	}
	return VfxControl::onPenInput(event);
}


/***************************************************************************** 
 * class VappShellOrderListItem implementation
 *****************************************************************************/
VappShellOrderListItem::VappShellOrderListItem(
				const VfxBool &switchable, 
				const VfxBool &switchValue) :
	m_image(NULL),
	m_text(NULL),
	m_switch(NULL),
	m_bSwitch(switchable),
	m_bSwitchValue(switchValue),
	m_appId(0)

{
}

void VappShellOrderListItem::onCreateElements(void)
{
	VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
	m_image->setAnchor(0.5F, 0.5F);
	
	VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
	m_text->setColor(VFX_COLOR_BLACK);
	m_text->setBounds(0, 0, TEXT_LENGTH, 65);
	m_text->setAutoResized(VFX_FALSE);
	m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

	if (m_bSwitch)
	{
		VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
		m_switch->setAnchor(0.5F, 0.5F);
		m_switch->setChecked(m_bSwitchValue, VFX_TRUE);
		m_switch->m_signalSwitchChanged.connect(this, &VappShellOrderListItem::switchCallback);
	}	
}


void VappShellOrderListItem::onLayoutElements(void)
{
	VfxS32 xPos = IMG_POS_X + m_image->getBounds().getWidth()/2;

	m_image->setPos(xPos, getBounds().getHeight()/2);	

	xPos = IMG_POS_X + m_image->getBounds().getWidth() + TEXT_INX_X;
	VfxS32 yPos = getBounds().getHeight()/2 - m_text->getMeasureBounds().getHeight()/2;
	m_text->setPos(xPos, yPos);
		
	if (m_switch != NULL)
	{	
		VfxS32 widthSwitch = m_switch->getBounds().getWidth();
		m_switch->setPos(getBounds().getWidth() - widthSwitch / 2 - IMG_POS_X, 
						 getBounds().getHeight() / 2);
	}	
}


void VappShellOrderListItem::onCloseElements(void)
{
	VFX_OBJ_CLOSE(m_switch);
	VFX_OBJ_CLOSE(m_text);
	VFX_OBJ_CLOSE(m_image);
}

void VappShellOrderListItem::setContent(const VfxU16 &appId,											
											  const VfxS32 &resId,
											  const VfxU16 &stringId, 
											  const VfxBool &checked)
{
	m_appId = appId;
	m_image->setResId(resId);

   // After setString(), the bounds of TextFrame will be changed.
	m_text->setString(VFX_WSTR_RES(stringId));

	if (m_switch != NULL &&
		m_switch->getChecked() != checked)
	{
		m_switch->setChecked(checked, VFX_TRUE);
	}
}

void VappShellOrderListItem::setContent(const Content& content)
{
	setContent(content.apId, content.resId, content.string, content.switchable);	
}

void VappShellOrderListItem::switchCallback(VcpSwitch *thiz, VfxBool status)
{
	VFX_UNUSED(thiz);

	m_signalSwitch.emit(m_appId, status);
}

/***************************************************************************** 
 * class VappShellSettingsOrderConfigContentProvider implementation
 *****************************************************************************/
VappShellSettingsOrderConfigContentProvider::VappShellSettingsOrderConfigContentProvider() :
	m_parentList(NULL)
{

}

VcpListMenuCellClientBaseFrame *
	VappShellSettingsOrderConfigContentProvider::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
	VdatShellPageOrder::PageState panelState;
	VdatShellPageOrder *order = VFX_OBJ_GET_INSTANCE(VdatShellPageOrder);	
	order->getState(&panelState, index);
	
	vapp_shell_panel_tbl_struct *item = (vapp_shell_panel_tbl_struct*)getPanelInfo(panelState.value);
	
	VappShellOrderListItem *cellFrame;
	VFX_OBJ_CREATE_EX(cellFrame, 
					  VappShellOrderListItem, 
					  parentFrame, 
					  (item->switchable, panelState.state != 0));
	cellFrame->m_signalSwitch.connect(
					this, 
				    &VappShellSettingsOrderConfigContentProvider::onSwitchCallback);
	
	cellFrame->setContent(item->panel_id, item->img_id, item->str_id, panelState.state != 0);
	
	return cellFrame;
}

void *VappShellSettingsOrderConfigContentProvider::getPanelInfo(const VfxU32 &panelId) const
{
	VFX_ASSERT(panelId < VAPP_SHELL_PANEL_ID_TOTAL);

	for (VfxU8 i = 0; i < VAPP_SHELL_PANEL_ID_TOTAL; i++)
	{
		if (g_vapp_shell_panel_create_tbl[i].panel_id == panelId)
		{
			return (void*)&g_vapp_shell_panel_create_tbl[i];
		}
	}
	
	return NULL;
}

VfxU32 VappShellSettingsOrderConfigContentProvider::getCount(void) const
{ 
	return VAPP_SHELL_PANEL_TOTAL; 
}

VfxBool VappShellSettingsOrderConfigContentProvider::swapItem(VfxU32 index1, VfxU32 index2)
{
	VFX_ASSERT(index1 < VAPP_SHELL_PANEL_TOTAL);
	VFX_ASSERT(index2 < VAPP_SHELL_PANEL_TOTAL);

	VdatShellPageOrder *order = VFX_OBJ_GET_INSTANCE(VdatShellPageOrder);
	order->swapOrder(index1, index2);
	
	return VFX_TRUE;
}

void VappShellSettingsOrderConfigContentProvider::closeItemCustomContentFrame(
			VfxU32 index,  						 // [IN] index of the item
	        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released)
        )
{
	VFX_ASSERT(index < VAPP_SHELL_PANEL_TOTAL);
	VFX_UNUSED(index);

	VFX_OBJ_CLOSE(cell);
}

void VappShellSettingsOrderConfigContentProvider::onSwitchCallback(const VfxU16 &id, const VfxBool &newState)
{
	VFX_ASSERT(id < VAPP_SHELL_PANEL_TOTAL);
	
	// save new order
	VdatShellPageOrder *order = VFX_OBJ_GET_INSTANCE(VdatShellPageOrder);
	order->setPanelState(newState, id);
}


/***************************************************************************** 
 * class VappShellPageOrderConfigScr implementation
 *****************************************************************************/

VappShellPageOrderConfigScr::VappShellPageOrderConfigScr() :
	m_cmdTitle(NULL),
	m_list(NULL)
{
	
}

void VappShellPageOrderConfigScr::onInit(void)
{
	VfxControl::onInit();
	
	VFX_OBJ_CREATE(m_cmdTitle, VcpCommandTitle, this);
    m_cmdTitle->setText(VFX_WSTR_RES(VAPP_SHELL_STR_SETTINGS_TITLE_TEXT));
		
	VcpStateImage imageList;
	imageList.setImage(VAPP_SHELL_IMG_BK_NORMAL,
			   VAPP_SHELL_IMG_BK_PRESS, 
			   VAPP_SHELL_IMG_BK_DISABLE,
			   VAPP_SHELL_IMG_BK_NORMAL);
    m_cmdTitle->setAddOnImageButton(
					1, 
					imageList, 
					1, 
					VcpCommandTitleButtonCB(this, &VappShellPageOrderConfigScr::onCmdButtonUp));

    m_cmdTitle->setAutoAnimate(VFX_TRUE);
	
	VFX_OBJ_CREATE(m_content, VappShellSettingsOrderConfigContentProvider, this);
	VFX_OBJ_CREATE(m_list, VcpListMenu, this);
	m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
	m_list->setContentProvider(m_content);
	m_list->setMenuMode(VCP_LIST_MENU_MODE_REORDER, VFX_FALSE);

	m_signalBoundsChanged.connect(this, &VappShellPageOrderConfigScr::onBoundChange);
}

void VappShellPageOrderConfigScr::onBoundChange(VfxFrame *frame, const VfxRect &old)
{
	VfxRect bounds = getBounds();

    m_cmdTitle->setPos(bounds.origin);
	m_list->setPos(0, m_cmdTitle->getBounds().getHeight() + bounds.origin.y - 2);
	
	
	bounds.size.height -= m_cmdTitle->getBounds().getHeight();
	m_list->setSize(bounds.size.width, bounds.size.height);
}

void VappShellPageOrderConfigScr::onDeinit(void)
{
	VFX_OBJ_CLOSE(m_list);
	VFX_OBJ_CLOSE(m_content);
	VFX_OBJ_CLOSE(m_cmdTitle);
	
	VfxControl::onDeinit();
}

void VappShellPageOrderConfigScr::onCmdButtonUp(VfxObject* obj, VfxId id)
{
	VFX_UNUSED(obj);

	m_signalReqClose.emit();
}


/***************************************************************************** 
 * class VappShellSettingContentProvider implementation
 *****************************************************************************/
BEGIN_INLINE_TABLE(VappShellSettingContentProvider)
#ifdef __MMI_BT_SUPPORT__ 
	INLINE_ITEM(INLINE_BT, 		  NULL, VCP_INL_CELLTYPE_SWITCH)
	INLINE_ITEM(INLINE_BT_SEARCH, NULL, VCP_INL_CELLTYPE_BUTTON)
	INLINE_ITEM(INLINE_GRP_SPLITOR1, NULL, VCP_INL_CELLTYPE_GROUP)
#endif /* __MMI_BT_SUPPORT__  */
#ifdef __MMI_WLAN_FEATURES__
	INLINE_ITEM(INLINE_WIFI, 	    NULL, VCP_INL_CELLTYPE_SWITCH)
	INLINE_ITEM(INLINE_WIFI_SEARCH, NULL, VCP_INL_CELLTYPE_BUTTON)
	INLINE_ITEM(INLINE_GRP_SPLITOR2, NULL, VCP_INL_CELLTYPE_GROUP)
#endif /* __MMI_WLAN_FEATURES__ */
#if 0
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM == 1)
	INLINE_ITEM(INLINE_FLIGHTMODE, 	NULL, VCP_INL_CELLTYPE_SWITCH)
#endif
	INLINE_ITEM(INLINE_PROFILES, 	NULL, VCP_INL_CELLTYPE_RADIOLIST)
#ifdef __MMI_AUTO_KEYPAD_LOCK__
	INLINE_ITEM(INLINE_AUTOLOCK, 	NULL, VCP_INL_CELLTYPE_RADIOLIST)
#endif
	INLINE_ITEM(INLINE_WALLPAPER, 	NULL, VCP_INL_CELLTYPE_BUTTON)
	INLINE_ITEM(INLINE_BRIGHTNESS, 	NULL, VCP_INL_CELLTYPE_BUTTON)
	INLINE_ITEM(INLINE_SHELL_SETTINGS, 	NULL, VCP_INL_CELLTYPE_BUTTON)
END_INLINE_TABLE(VappShellSettingContentProvider)


const VfxResId VappShellSettingContentProvider::s_resAutoLock[] = 
{
	STR_GLOBAL_OFF,
	STR_ID_SLK_15_SEC,
	STR_ID_SLK_30_SEC,
	STR_ID_SLK_1_MIN,
	STR_ID_SLK_5_MIN
};


VappShellSettingContentProvider::VappShellSettingContentProvider(void)
{
	setLookupTable(NULL, INLINE_TOTAL);
}

VappShellSettingContentProvider::~VappShellSettingContentProvider(void)
{
}

void* VappShellSettingContentProvider::makeCustomCellData(const VfxId &id)
{
	VFX_ASSERT(id < INLINE_TOTAL);
	
	switch(id)
	{
#ifdef __MMI_BT_SUPPORT__ 
	case INLINE_BT:
		m_dataSwitch.text = STR_GLOBAL_BLUETOOTH;
		m_dataSwitch.hinttext = 0;
		m_dataSwitch.icon = IMG_GLOBAL_L1;
		if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
		{
			m_dataSwitch.switchState = VFX_TRUE;
		}
		else
		{
			m_dataSwitch.switchState = VFX_FALSE;
		}	
		return (void*)&m_dataSwitch;
		
	case INLINE_BT_SEARCH:
		m_dataButton.text = STR_BT_MYDEVICE;
		m_dataButton.accessory = VCP_INL_ACC_NEXT_STEP_IND;
		m_dataButton.hinttext = 0;
		m_dataButton.icon = IMG_GLOBAL_L1;
		return (void*)&m_dataButton;
#endif /* __MMI_BT_SUPPORT__  */

#ifdef __MMI_WLAN_FEATURES__
	case INLINE_WIFI:
		m_dataSwitch.text = MAIN_MENU_WLAN_TEXT;
		m_dataSwitch.hinttext = 0;
		m_dataSwitch.icon = IMG_GLOBAL_L1;
		if ((srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_ACTIVE) ||
		    (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED))
		{
			m_dataSwitch.switchState = VFX_TRUE;
		}
		else
		{
			m_dataSwitch.switchState = VFX_FALSE;
		}
		return (void*)&m_dataSwitch;
		
	case INLINE_WIFI_SEARCH:
		m_dataButton.text = STR_ID_DTCNT_WLAN_FIND_NETWORK;
		m_dataButton.accessory = VCP_INL_ACC_NEXT_STEP_IND;
		m_dataButton.hinttext = 0;
		m_dataButton.icon = IMG_GLOBAL_L1;
		return (void*)&m_dataButton;
#endif /* __MMI_WLAN_FEATURES__ */

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
#endif

#if (MMI_MAX_SIM_NUM == 1)
	case INLINE_FLIGHTMODE:
		m_dataSwitch.text = STR_MENU_FLIGHT_MODE;
		if (srv_mode_switch_get_current_mode() == SRV_MODE_FLIGHT_MODE)
		{
			m_dataSwitch.switchState = VFX_TRUE;
		}
		else
		{
			m_dataSwitch.switchState = VFX_FALSE;
		}
		return (void*)&m_dataSwitch;
#endif /* __MMI_DUAL_SIM_MASTER__ */

	case INLINE_PROFILES:
	{
		int i;
		m_dataRadioList.text = MAIN_MENU_PROFILES_TEXT;
		m_dataRadioList.icon = IMG_GLOBAL_L1;
		m_dataRadioList.total_options = (VfxS32)m_profilesNum;
		for(i = 0; i< m_profilesNum; i++)
		{
			if(srv_prof_get_activated_profile() == m_enumListProfiles[i])
			{			
				m_dataRadioList.selectedoption = (VfxS32)(i);
				break;
			}
		}
		m_dataRadioList.accessory = VCP_INL_ACC_POPUP_RADIO_LIST;
		m_dataRadioList.optionList = m_strListProfiles;
		
		VFX_LOG(VFX_FUNC, 
				VAPP_SHELL_SETTINGS_RADIO_SELECTED, 
				INLINE_PROFILES, 
				m_dataRadioList.total_options, 
				m_dataRadioList.selectedoption);
		
		return (void*)&m_dataRadioList;
	}
		
#ifdef __MMI_AUTO_KEYPAD_LOCK__
	case INLINE_AUTOLOCK:
	{
		m_dataRadioList.text = STR_ID_SLK_TIME_SETTING;
		m_dataRadioList.icon = IMG_GLOBAL_L1;
		m_dataRadioList.total_options = AUTOLOCK_TOTAL;
		m_dataRadioList.selectedoption = (VfxS32)GetAutoKeypadLockTime();
		m_dataRadioList.accessory = VCP_INL_ACC_POPUP_RADIO_LIST;
		m_dataRadioList.optionList = m_strListAutoLock;
		
		return (void*)&m_dataRadioList;
	}

#endif /* __MMI_AUTO_KEYPAD_LOCK__ */

	case INLINE_WALLPAPER:
		m_dataButton.text = STR_GLOBAL_WALLPAPER;
		m_dataButton.accessory = VCP_INL_ACC_NEXT_STEP_IND;
		m_dataButton.hinttext = 0;
		m_dataButton.icon = IMG_GLOBAL_L1;
		return (void*)&m_dataButton;

	case INLINE_BRIGHTNESS:
		m_dataButton.text = STR_ID_PHNSET_GPIO_BACKLITE_LEVEL;
		m_dataButton.accessory = VCP_INL_ACC_NEXT_STEP_IND;
		m_dataButton.hinttext = 0;
		m_dataButton.icon = IMG_GLOBAL_L1;
		return (void*)&m_dataButton;

	case INLINE_SHELL_SETTINGS:// change order
		m_dataButton.text = VAPP_SHELL_STR_SETTINGS_TITLE_TEXT;
		m_dataButton.accessory = VCP_INL_ACC_NEXT_STEP_IND;
		m_dataButton.hinttext = 0;
		m_dataButton.icon = IMG_GLOBAL_L1;
		return (void*)&m_dataButton;
		
	default:
		break;
	}
		
	return NULL;
}

void VappShellSettingContentProvider::initString()
{
	VfxU8 i, total;

	// Profiles
	total = (VfxS32)srv_prof_get_num_of_profiles();

	m_profilesNum = mmi_prof_get_profiles_enum_list_for_shell((U8 *)m_enumListProfiles, total);
	
	for (i = 0; i < m_profilesNum; i++)
	{
		m_strListProfiles[i].text = VFX_WSTR_MEM(mmi_prof_get_profile_name((mmi_prof_id_enum)(m_enumListProfiles[i])));
		if(i >= 4)
		{
			m_strListProfiles[i].icon = VfxImageSrc(VAPP_SHELL_IMG_PROF_MYSTYLE);
		}
		else
	    {
		    m_strListProfiles[i].icon = VfxImageSrc((VAPP_SHELL_IMG_PROF_GENERAL + i));
	    }
	}

	// Keypad Lock
	for (i = 0; i < AUTOLOCK_TOTAL; i++)
	{
		m_strListAutoLock[i].text = VFX_WSTR_MEM((VfxWChar *)GetString(SETTING_FIELD(s_resAutoLock[i])));
	}

	// Dual Mode
#if 0//def __MMI_DUAL_SIM_MASTER__
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
#endif /* __MMI_DUAL_SIM_MASTER__ */
}

#if 0//def __MMI_DUAL_SIM_MASTER__
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
#endif /* __MMI_DUAL_SIM_MASTER__ */

void VappShellSettingContentProvider::buildMenu()
{
	const InlineCell *cell;
	void *cellDesc;

	VfxS32 pos = 0, group = 0;
	
	for(VfxS32 i = 0; i < m_cellcount ; i++)
	{
		cell = &VappShellSettingContentProvider::s_cellTable[i];

		// next group
		if (cell->type == VCP_INL_CELLTYPE_GROUP)
		{
			pos = 0;
			group ++;
		}
		else
		{
			if (cell->data == NULL)
			{
				cellDesc = makeCustomCellData(cell->id);
			}
			else
			{
				cellDesc = cell->data;
			}
			
			m_parentMenu->createCell(group, pos, cell->id, cell->type);

			if (cell->type == VCP_INL_CELLTYPE_BUTTON)
			{
				m_parentMenu->fillCellData(cell->id, (VcpInlineCellButtonData*)cellDesc);
			}
			else if (cell->type == VCP_INL_CELLTYPE_SWITCH)
			{
				m_parentMenu->fillCellData(cell->id, (VcpInlineCellSwitchData*)cellDesc);
			}
			else if (cell->type == VCP_INL_CELLTYPE_RADIOLIST)
			{
				m_parentMenu->fillCellData(cell->id, (VcpInlineCellRadioListData*)cellDesc);

			}
			
			pos++;
		}
	}
}


/***************************************************************************** 
 * class VappShellSettingsScr
 *****************************************************************************/
VappShellSettingsScr *VappShellSettingsScr::s_currScr = NULL;

VFX_IMPLEMENT_CLASS("VappShellSettingsScr", VappShellSettingsScr, VappShellPanel);
mmi_ret VappShellSettingsScr::evtHandler(mmi_event_struct *evt)
{	
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_EVT_HANDLR, evt->evt_id);

#ifdef __MMI_WLAN_FEATURES__
	VappShellSettingsScr *obj = (VappShellSettingsScr *)evt->user_data;
#endif	
	
	switch (evt->evt_id)
	{
#ifdef __MMI_WLAN_FEATURES__
		case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
		case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
		{			
			if (obj != NULL)
			{
				obj->onSwitchWlanResult(evt);
			}
			break;
		}
#endif /* __MMI_WLAN_FEATURES__ */

		default:
			break;
	}

	
	return MMI_RET_OK;
}

void VappShellSettingsScr::switchCallback(VfxS32 finish)
{
	if (VappShellSettingsScr::s_currScr != NULL)
	{
		VappShellSettingsScr::s_currScr->onSwitchCallback((finish != 0));
	}	
}


mmi_ret VappShellSettingsScr::switchCallback3(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH)
	{
    	if (VappShellSettingsScr::s_currScr != NULL)
    	{
    		VappShellSettingsScr::s_currScr->onSwitchCallback((((srv_mode_switch_rsp_event_struct*)evt)->result != 0));
    	}	
    }
    return MMI_RET_OK;
}
VappShellSettingsScr::VappShellSettingsScr() :
	m_brightScr(NULL),
	m_orderScr(NULL),
	m_content(NULL),
	m_inlineMenu(NULL),
	m_waitingPopupWeakPtr(NULL),
	m_idPending(INLINE_ENUM(INLINE_TOTAL)),
	m_bNewVisual(VFX_FALSE),
	m_ptTimeline(NULL),
	m_transTimeline(NULL),
	m_bClosing(VFX_FALSE),
	m_uActiveScr(SCR_TOTAL),
	m_uSwitchSrc(SWITCH_BY_OTHER),
	m_bg(NULL),
	m_bgShadow(NULL),
	m_topBar(NULL),
	m_titleText(NULL),
	m_bottomBar(NULL)
{
	VappShellSettingsScr::s_currScr = this;
}

void VappShellSettingsScr::onInit()
{
	VappShellPanel::onInit();

	VFX_OBJ_CREATE(m_content, VappShellSettingContentProvider, this);
	regEvtHdlr();

}

void VappShellSettingsScr::regEvtHdlr(void)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_RET_EVT_HANDLR);
	
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, VappShellSettingsScr::evtHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, VappShellSettingsScr::evtHandler, this);
}

void VappShellSettingsScr::unregEvtHdlr(void)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_UNREG_EVT_HANDLR);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, VappShellSettingsScr::evtHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, VappShellSettingsScr::evtHandler, this);
}

void VappShellSettingsScr::onInitView(void)
{
	VappShellPanel::onInitView();
	
	// set Backgournd
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    setSize(main_screen_size.width, main_screen_size.height);

    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	m_bg->setPos(VFX_POINT_ZERO);
    m_bg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    m_bg->setBgColor(VFX_COLOR_BLACK);
    m_bg->setIsOpaque(VFX_TRUE);

	VfxRect appBound = getAppBounds();
	
	if (m_uActiveScr == SCR_ORDER)
	{
		appBound.size.height -= getShortcutSize().height;
	}
	
	// Background Shadow
	VFX_OBJ_CREATE(m_bgShadow, VfxImageFrame, this);
	m_bgShadow->setResId(VAPP_SHELL_IMG_SETTINGS_BG_SHADOW);
	m_bgShadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_bgShadow->setPos(appBound.getMinX() + SHADOW_MARGIN, appBound.getMinY() + SHADOW_MARGIN);
	m_bgShadow->setSize(appBound.getWidth() - 2 * SHADOW_MARGIN, appBound.getHeight() - 2 * SHADOW_MARGIN);

	m_content->initString();

	VfxRect rect = VFX_RECT_ZERO;
	rect.size.height = appBound.getHeight() - (TOP_MARGIN + BOTTOM_MARGIN);
	rect.size.width = appBound.getWidth() - (LEFT_MARGIN + RIGHT_MARGIN);

	VfxPoint startPt = appBound.origin;

	// Top bar
	VFX_OBJ_CREATE(m_topBar, VfxImageFrame, this);
	m_topBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_topBar->setResId(VAPP_SHELL_IMG_SETTINGS_TOP_BAR);
	m_topBar->setPos(startPt.x + LEFT_MARGIN, startPt.y + TOP_MARGIN);
	m_topBar->setSize(rect.size.width, m_topBar->getBounds().getHeight());

	// Text
	VFX_OBJ_CREATE(m_titleText, VfxTextFrame, this);
	m_titleText->setAnchor(0.5F, 0.5F);
	m_titleText->setPos(m_topBar->getPos().x + m_topBar->getBounds().getMidX(),
					    m_topBar->getPos().y + m_topBar->getBounds().getMidY());
	m_titleText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_titleText->setString(VFX_WSTR_RES(MAIN_MENU_SETTINGS_TEXT));
	
	// Bottom bar
	VFX_OBJ_CREATE(m_bottomBar, VfxImageFrame, this);
	m_bottomBar->setResId(VAPP_SHELL_IMG_SETTINGS_BOTTOM_BAR);
	m_bottomBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_bottomBar->setPos(startPt.x + LEFT_MARGIN, 
					  1 + appBound.getMaxY() - BOTTOM_MARGIN - m_bottomBar->getBounds().getHeight());
	m_bottomBar->setSize(rect.size.width, m_bottomBar->getBounds().getHeight());

	// Inline menu
	VFX_OBJ_CREATE(m_inlineMenu, VcpInlineMenu, this);
	m_content->setClientMenu(m_inlineMenu);
	m_inlineMenu->setPos(LEFT_MARGIN, 
						 startPt.y + TOP_MARGIN + m_topBar->getSize().height - 2);

	rect.size.height = appBound.getHeight() + 2
					   - (TOP_MARGIN + BOTTOM_MARGIN) 
					   - (m_topBar->getSize().height + m_bottomBar->getSize().height);

	m_inlineMenu->setBounds(rect);
        m_inlineMenu->setViewRect(rect);
        m_inlineMenu->enableVerticalScrollIndicator(VFX_TRUE);

	m_inlineMenu->SwitchChangedTo.connect(this, &VappShellSettingsScr::cellSwitchButtonCallback);	
	m_inlineMenu->Cell_Tapped.connect(this, &VappShellSettingsScr::cellButtonCallback);
	m_inlineMenu->NewOptionSelected.connect(this, &VappShellSettingsScr::cellOptionListCallback);

	m_content->buildMenu();

	initMenu();
}

void VappShellSettingsScr::initMenu(void)
{
		// Update menu status
#ifdef __MMI_BT_SUPPORT__ 
	initBTMenu();
#endif

#ifdef __MMI_WLAN_FEATURES__
	initWlanMenu();	
#endif /* __MMI_WLAN_FEATURES__ */

	VfxU8 prefer_mode = mmi_netset_get_active_preferred_mode();
	
	if (prefer_mode == P_WLAN_ONLY)
	{
#if 0//def __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM == 1)
	    m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_FLIGHTMODE), VFX_FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */	

	}

	if (m_uActiveScr == SCR_ORDER)
	{
		showSetOrderScr(VFX_FALSE);
	}
	else if (m_uActiveScr == SCR_WAITING)
	{
		showWaitingIcon();
	}
#if 0//(MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
#endif
}


void VappShellSettingsScr::onEnterView(void)
{
	VappShellPanel::onEnterView();

	//regEvtHdlr();
}

void VappShellSettingsScr::onExitView(ShellExitCauseEnum cause)
{
	if (cause == APP_SHELL_SCREEN_EXIT && m_orderScr != NULL)
	{
		m_uActiveScr = SCR_ORDER;
	}
	else if (m_uActiveScr == SCR_WAITING)
	{
		// keep the current screen
	}
	else
	{
		m_uActiveScr = SCR_TOTAL;
	}

	VFX_OBJ_CLOSE(m_brightScr);
	VFX_OBJ_CLOSE(m_orderScr);

	//unregEvtHdlr();
	
	// Do nothing
	VappShellPanel::onExitView(cause);
}

void VappShellSettingsScr::onDeinitView(void)
{
    VFX_OBJ_CLOSE(m_inlineMenu);
	VFX_OBJ_CLOSE(m_bottomBar);
	VFX_OBJ_CLOSE(m_titleText);
	VFX_OBJ_CLOSE(m_topBar);
	VFX_OBJ_CLOSE(m_bgShadow);
	VFX_OBJ_CLOSE(m_bg);
	// Do nothing
	VappShellPanel::onDeinitView();
}

void VappShellSettingsScr::onDeinit(void)
{
	VFX_OBJ_CLOSE(m_content);
	unregEvtHdlr();
	VappShellPanel::onDeinit();
}

VfxBool VappShellSettingsScr::onPenInput(VfxPenEvent & event)
{

	if (event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		if (m_brightScr != NULL &&
			!m_brightScr->containPoint(event.getRelPos(m_brightScr)))
		{
			closeBrightnessScr();
		}
		
	}
		
	return VappShellPanel::onPenInput(event);
}

void VappShellSettingsScr::cellSwitchButtonCallback(VfxId id, VfxBool status)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_BTN_SWITCH_CALLBACK, id, status);
	
	RETURN_IF_FAIL(m_inlineMenu != NULL);
	
	VFX_ASSERT(id < INLINE_ENUM(INLINE_TOTAL));
	
#if (MMI_MAX_SIM_NUM == 1)
#if !defined(__MTK_TARGET__)
		if (id == INLINE_ENUM(INLINE_FLIGHTMODE))
		{
			PopupNoSupport();
			return;
		}
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif
	
	switch(id)
	{
#ifdef __MMI_BT_SUPPORT__ 
	case INLINE_ENUM(INLINE_BT):		
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_BTN_SWITCH_BT);

		if (status && !srv_mode_switch_is_network_service_available())
		{
			showActiveBTConfirm();
		}
		else
		{
			switchBT(status);
		}
		
		break;
#endif /* __MMI_BT_SUPPORT__  */

#ifdef __MMI_WLAN_FEATURES__
	case INLINE_ENUM(INLINE_WIFI):
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_BTN_SWITCH_WIFI);
		if (status && !srv_mode_switch_is_network_service_available())
		{
#ifndef __OP01__	
			showActiveWlanConfirm();
#endif /* __OP01__ */
		}
		else
		{
		m_bNewVisual = status;
		preSwitchWlan(status);
		}
		m_idPending = id;
		break;
#endif /* __MMI_WLAN_FEATURES__ */

#if (MMI_MAX_SIM_NUM == 1)
	case INLINE_ENUM(INLINE_FLIGHTMODE):			
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_BTN_SWITCH_WIFI);
		showWaitingIcon();
		m_idPending = id;
		m_bNewVisual = status;
		switchFlightmode(status);
		break;
#endif /* __FLIGHT_MODE_SUPPORT__ */

	default:
		break;
	}
}

void VappShellSettingsScr::updateMenuStatus(void)
{
	#ifdef __MMI_BT_SUPPORT__ 
	if (srv_bt_cm_get_power_status() != SRV_BT_CM_POWER_ON)
	{
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_UPDATEMENU_STAGE, 1);
		m_inlineMenu->updateCellSwitchStatus(INLINE_ENUM(INLINE_BT), VFX_FALSE);
		m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_BT_SEARCH), VFX_FALSE);
	}
	else
	{
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_UPDATEMENU_STAGE, 2);
		m_inlineMenu->updateCellSwitchStatus(INLINE_ENUM(INLINE_BT), VFX_TRUE);
		m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_BT_SEARCH), VFX_TRUE);		
	}
	#endif /* __MMI_BT_SUPPORT__  */

    #ifdef __MMI_WLAN_FEATURES__
    initWlanMenu();
    #endif /* __MMI_WLAN_FEATURES__ */

#if (MMI_MAX_SIM_NUM == 1)
    m_inlineMenu->updateCellSwitchStatus(INLINE_ENUM(INLINE_FLIGHTMODE), (srv_mode_switch_is_network_service_available() == MMI_FALSE ? VFX_TRUE : VFX_FALSE));
#endif

}

void VappShellSettingsScr::cellOptionListCallback(VfxId id, VfxS32 index)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_OPTION_LIST_CALLBACK, id, index);

	RETURN_IF_FAIL(m_inlineMenu != NULL);
	VFX_ASSERT(id < INLINE_ENUM(INLINE_TOTAL));
	
#if 0//(defined(__MMI_DUAL_SIM_MASTER__) && !defined(__MTK_TARGET__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
	
	switch(id)
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

	case INLINE_ENUM(INLINE_PROFILES):
		onProfileSelection((VfxU8)index);
		break;
		
#ifdef __MMI_AUTO_KEYPAD_LOCK__
	case INLINE_ENUM(INLINE_AUTOLOCK):
		VFX_ASSERT(index >= INLINE_ENUM(AUTOLOCK_OFF));
		VFX_ASSERT(index < INLINE_ENUM(AUTOLOCK_TOTAL));
		onAutoLockSelection((VfxU8)index);
		break;
#endif /* __MMI_AUTO_KEYPAD_LOCK__ */

		break;		
		
	default:
		break;
	}

}

void VappShellSettingsScr::cellButtonCallback(VfxId id)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_BTN_CALLBACK, id);
	
	RETURN_IF_FAIL(getPanelState() == APP_SHELL_ENTER_VIEW);
	VFX_ASSERT(id < INLINE_ENUM(INLINE_TOTAL));
	
	switch(id)
	{
#ifdef __MMI_BT_SUPPORT__ 
	case INLINE_ENUM(INLINE_BT_SEARCH):
		vfxPostInvoke0(this, &VappShellSettingsScr::launchBTSearch);
		break;
#endif
#ifdef __MMI_WLAN_FEATURES__
	case INLINE_ENUM(INLINE_WIFI_SEARCH):
		vfxPostInvoke0(this, &VappShellSettingsScr::launchWlanApp);
		break;
#endif
	case INLINE_ENUM(INLINE_WALLPAPER):
		showWallpaperConfirm();
		break;
		
	case INLINE_ENUM(INLINE_BRIGHTNESS):
		showBrightnessScr();
		break;
		
	case INLINE_ENUM(INLINE_SHELL_SETTINGS):
		showSetOrderScr(VFX_TRUE);
		break;
		
	default:
		break;
	}
}


void VappShellSettingsScr::onAutoLockSelection(const VfxU8 &selIndex)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_AUTOLOCK_SEL, selIndex);

	VfxS16 sError;
	
	WriteValue(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, (void*)&selIndex, DS_BYTE, &sError);

	mmi_scr_locker_stop_timer();
	mmi_scr_locker_start_timer();
}

void VappShellSettingsScr::onProfileSelection(const VfxU8 &selIndex)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_PROFILE_SEL, selIndex);
	srv_prof_activate_profile((srv_prof_internal_profile_enum)(m_content->m_enumListProfiles[selIndex]));
}

void VappShellSettingsScr::onSwitchCallback(VfxBool finish)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_SWITCHCALLBACK, m_idPending, finish, m_bNewVisual);
	closeWaitingIcon();
	
	if (m_inlineMenu == NULL)
	{
		m_idPending = INLINE_ENUM(INLINE_TOTAL);
		return;
	}
	
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_SWITCHCALLBACK, m_idPending, finish, m_bNewVisual);
	
	if (finish)
	{
	switch(m_idPending)
	{

#if 0//def __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM == 1)
		case INLINE_ENUM(INLINE_FLIGHTMODE):
				m_inlineMenu->onPendingActivityCompletion(m_idPending, finish);
#endif
			mmi_flight_mode_update_status_icon();
			updateMenuStatus();
			break;

	default:
		break;
	}
	}
	else
	{
		switch(m_idPending)
		{
			
	#if 0//def __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	#if (MMI_MAX_SIM_NUM == 1)
			case INLINE_ENUM(INLINE_FLIGHTMODE):
	#endif
			showErrorPopup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
				break;

		default:
			break;
		}
	}
	
#ifdef __MMI_BT_SUPPORT__ 
	if (m_idPending == INLINE_ENUM(INLINE_BT))
	{
		onSwitchBTResult(finish);
	}
#endif
	// set at invalid
	m_idPending = INLINE_ENUM(INLINE_TOTAL);
}

void VappShellSettingsScr::onCommandPopCallback(VfxObject *obj, VfxId id)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_CMD_POPUP_CALLBACK, id);
	
	if (id == WALLPAPER_GALLERY || id == WALLPAPER_FMGR || id == WALLPAPER_LIVE)
	{
		vfxPostInvoke1(this, &VappShellSettingsScr::launchWallpaperApp, id);
	}
#ifdef __MMI_BT_SUPPORT__ 
	else if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
	{
		switchBT(VFX_TRUE);
	}
#endif /* __MMI_BT_SUPPORT__  */

}

void VappShellSettingsScr::showBrightnessScr(void)
{
	VfxU8 currentLevel;
	VfxU8 level_1;
	VfxU8 level_2;
	VfxU8 level_3;
	VfxU8 level_4;
	VfxU8 level_5;

	VfxU8 level;

	currentLevel = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_GET_BL, currentLevel);

    level_5 = SRV_GPIO_BACKLIGHT_MAX_LEVEL;
    level_3 = (SRV_GPIO_BACKLIGHT_MIN_LEVEL+SRV_GPIO_BACKLIGHT_MAX_LEVEL)/2;
    level_1 = SRV_GPIO_BACKLIGHT_MIN_LEVEL;
    level_2 = (level_1+level_3)/2;
	level_4 = (level_3+level_5)/2;

	if (currentLevel < level_2)
	{
		level = 1;
	}
	else if (currentLevel < level_3)		
	{
		level = 2;
	}
	else if (currentLevel < level_4)
	{
		level = 3;
	}
	else if (currentLevel < level_5)
	{
		level = 4;
	}
	else if (currentLevel == level_5)
	{
		level = 5;
	}
	else
	{
		level = 1;
	}
	
	if (m_brightScr == NULL)
	{
		m_inlineMenu->setIsUnhittable(VFX_TRUE);
		VFX_OBJ_CREATE_EX(m_brightScr, VappShellBrightnessSelPopup, this, (level));
		m_brightScr->setPos(getAppBounds().getWidth() / 2, 
							getAppBounds().origin.y + getAppBounds().getHeight() / 2);
		m_brightScr->m_signalLevel.connect(this, &VappShellSettingsScr::onLevelClick);
		deregDefaultPageAct(m_brightScr);
	}
	else
	{
		m_brightScr->setCurrentLevel(level);
	}
}


void VappShellSettingsScr::closeBrightnessScr(void)
{
	m_inlineMenu->setIsUnhittable(VFX_FALSE);
	VFX_OBJ_CLOSE(m_brightScr);
}


void VappShellSettingsScr::onLevelClick(const VfxU16 &level)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_SET_LEVEL, level);
	
	VfxU8 ref_level[5];
	VfxU8 set_level;
	static VfxU8 old_level;
	if(level > 5 || level < 1)
	{
		return;
	}
	if (old_level == level)
	{
		return;
	}
	old_level = level;
    ref_level[4] = SRV_GPIO_BACKLIGHT_MAX_LEVEL;
    ref_level[2] = (SRV_GPIO_BACKLIGHT_MIN_LEVEL+SRV_GPIO_BACKLIGHT_MAX_LEVEL)/2;
    ref_level[0] = SRV_GPIO_BACKLIGHT_MIN_LEVEL;
	ref_level[1] = (ref_level[0]+ref_level[2])/2;
	ref_level[3] = (ref_level[2]+ref_level[4])/2;
	set_level = ref_level[level-1];
	mmi_phnset_gpio_set_bl_level(set_level);
}


void VappShellSettingsScr::showWallpaperConfirm(void)
{
    // Popup's parent must be VfxScreen
    VcpCommandPopup *cmdPopup;
    VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, findScreen());

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__
	cmdPopup->setText(VFX_WSTR_RES(STR_GLOBAL_WALLPAPER));
	cmdPopup->addItem(WALLPAPER_LIVE, VFX_WSTR_RES(STR_ID_WALLPAPER_LIVE_WALLPAPER));
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__ */	
    cmdPopup->addItem(WALLPAPER_GALLERY, VFX_WSTR_RES(STR_ID_WALLPAPER_GALLERY));
    cmdPopup->addItem(WALLPAPER_FMGR,   VFX_WSTR_RES(STR_WALLPAPER_DOWNLOAD));
    cmdPopup->addItem(WALLPAPER_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmdPopup->m_signalButtonClicked.connect(this, &VappShellSettingsScr::onCommandPopCallback);
    cmdPopup->setAutoDestory(VFX_TRUE);
    cmdPopup->show(VFX_TRUE);
}

void VappShellSettingsScr::launchWallpaperApp(VfxId id)
{
	if (id == WALLPAPER_GALLERY)
	{
		mmi_phnset_wallpaper_entry_system(GRP_ID_INVALID);
	}
	else if (id == WALLPAPER_FMGR)
	{
		mmi_phnset_wallpaper_entry_fmgr(GRP_ID_INVALID);
	}
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__
	else if (id == WALLPAPER_LIVE)
	{
		mmi_phnset_wallpaper_entry_vui_live_wallpaper(GRP_ID_INVALID);
	}
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__ */	
}


void VappShellSettingsScr::showSetOrderScr(VfxBool anim)
{
	hideShortcutBar(VFX_TRUE);
	
	if (m_orderScr == NULL)
	{
		VFX_OBJ_CREATE(m_orderScr, VappShellPageOrderConfigScr, findScreen());
		m_orderScr->m_signalReqClose.connect(this, &VappShellSettingsScr::onReqClose);
		deregDefaultPageAct(m_orderScr);
		
		VfxRect bounds = getAppBounds();
	    vrt_size_struct main_screen_size;
	    vrt_color_type_enum main_screen_color_format;  
	    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

		bounds.size.height = main_screen_size.height - bounds.origin.y + 2;
		
		m_orderScr->setAnchor(0.5F, 0.5F);
		m_orderScr->setPos(bounds.getMidPoint());
		m_orderScr->setBounds(bounds);

		if (anim)
		{
		pushFrame(m_orderScr, EFFECT_FADE_IN);
	}
		
	}
}

void VappShellSettingsScr::onPushFinish(VfxBaseTimeline *thiz, VfxBool finish)
{
	if (m_bClosing)
	{
		VFX_OBJ_CLOSE(m_orderScr);
		m_bClosing = VFX_FALSE;
		m_uActiveScr = SCR_TOTAL;
	}

}

void VappShellSettingsScr::pushFrame(VfxFrame *frame, VfxU16 effect)
{
	if (m_transTimeline == NULL)
	{
		VFX_OBJ_CREATE(m_transTimeline, VfxTransformTimeline, this);
		m_transTimeline->m_signalStopped.connect(this, &VappShellSettingsScr::onPushFinish);
	}
	VfxTransform trans = frame->getTransform();
	VfxTransform newTrans = trans;

	newTrans.type = VRT_TRANSFORM_TYPE_AFFINE;

	newTrans.data.affine.sx = 0.5;
	newTrans.data.affine.sy = 0.5;

	m_transTimeline->setTarget(frame);
	if (effect == EFFECT_FADE_IN)
	{
		m_transTimeline->setFromValue(newTrans);
		m_transTimeline->setToValue(trans);
		frame->setTransform(trans);
	}
	else
	{
		m_transTimeline->setFromValue(trans);
		m_transTimeline->setToValue(newTrans);
	}
	
	m_transTimeline->setDurationTime(250);
	m_transTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

	
	
	m_transTimeline->start();

}

void VappShellSettingsScr::onReqClose(void)
{
	hideShortcutBar(VFX_FALSE);
	m_bClosing = VFX_TRUE;
	pushFrame(m_orderScr, EFFECT_FADE_OUT);
}


void VappShellSettingsScr::showWaitingIcon(void)
{
	VappShellWaitingPopup *waiting;
	VFX_OBJ_CREATE(waiting, VappShellWaitingPopup, findScreen());
	waiting->setAutoDestory(VFX_TRUE);
	waiting->show(VFX_TRUE);

	m_waitingPopupWeakPtr = waiting;

	m_uActiveScr = SCR_WAITING;
}

void VappShellSettingsScr::closeWaitingIcon(void)
{
	if (m_waitingPopupWeakPtr.isValid())
	{
		VappShellWaitingPopup *waiting = m_waitingPopupWeakPtr.get();
		waiting->exit(VFX_TRUE);
	}

	m_uActiveScr = SCR_TOTAL;
}

#if (MMI_MAX_SIM_NUM == 1)
void VappShellSettingsScr::switchFlightmode(const VfxBool &state)
{
	VfxU8 ret;
	
	if (state)
	{
		ret = srv_mode_switch_switch_network_mode(SRV_MODE_FLIGHT_MODE, 
					   VappShellSettingsScr::switchCallback3,
					   NULL);
	}
	else
	{
		ret = srv_mode_switch_switch_network_mode(SRV_MODE_NORMAL_MODE, 
					   VappShellSettingsScr::switchCallback3,
					   NULL);
	}	

	// if ret==0, mode swtich can't use.
	if (ret == 0)
	{
		onSwitchCallback(VFX_FALSE);
	}
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_BT_SUPPORT__ 
void VappShellSettingsScr::showActiveBTConfirm(void)
{
	// Popup's parent must be VfxScreen
	VcpConfirmPopup *cnfPopup;
	VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, findScreen());
	cnfPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
	cnfPopup->setText(VFX_WSTR_RES(STR_BT_POWER_ON_IN_FLIGHT_MODE_CNF));
	cnfPopup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_ACTIVATE),
							  VFX_WSTR_RES(STR_GLOBAL_CANCEL),
							  VCP_POPUP_BUTTON_TYPE_RECOMMEND,
							  VCP_POPUP_BUTTON_TYPE_CANCEL);
	cnfPopup->m_signalButtonClicked.connect(this, &VappShellSettingsScr::onCommandPopCallback);
	cnfPopup->setAutoDestory(VFX_TRUE);
	cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
	cnfPopup->show(VFX_TRUE);
}

void VappShellSettingsScr::switchBT(const VfxBool &state)
{
	if (!mmi_bt_is_permission(MMI_TRUE))
	{
		return;
	}
	showWaitingIcon();
	m_idPending = INLINE_ENUM(INLINE_BT);
	m_bNewVisual = state;
	m_uSwitchSrc = SWITCH_BY_SHELL;
	
	if (state)
	{
		mmi_bt_power_on_bt((FuncPtrBool)VappShellSettingsScr::switchCallback);
	}
	else
	{
		mmi_bt_power_off_bt((FuncPtrBool)VappShellSettingsScr::switchCallback);
	}
}

void VappShellSettingsScr::launchBTSearch(void)
{
  	mmi_bt_entry_mydev_menu_by_shell();
}

void VappShellSettingsScr::initBTMenu(void)
{
	srv_bt_cm_power_status_enum bt_status = srv_bt_cm_get_power_status();

	if (bt_status != SRV_BT_CM_POWER_ON)
	{
		m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_BT_SEARCH), VFX_FALSE);
		
		if (bt_status == SRV_BT_CM_POWER_SWITCHING_ON &&
			m_uActiveScr != SCR_WAITING)
		{
			mmi_bt_register_power_on_callback_with_result((FuncPtrBool)VappShellSettingsScr::switchCallback);
			showWaitingIcon();
			m_idPending = INLINE_ENUM(INLINE_BT);
			m_bNewVisual = VFX_TRUE;;
			m_uSwitchSrc = SWITCH_BY_BT;
		}
	}

}

void VappShellSettingsScr::onSwitchBTResult(const VfxBool &state)
{
	if (m_uSwitchSrc == SWITCH_BY_SHELL)
	{
		m_inlineMenu->onPendingActivityCompletion(m_idPending, state);
	}
	else if (m_uSwitchSrc == SWITCH_BY_BT)
	{
		m_inlineMenu->updateCellSwitchStatus(m_idPending, 
											 srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON);
	}
	m_uSwitchSrc = SWITCH_BY_OTHER;


	m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_BT_SEARCH), (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON));

	if (!state)
	{
		VfxU16 string_id = mmi_bt_get_popup_string();
		if (string_id == STR_BT_POWER)
		{
			string_id = STR_GLOBAL_ERROR;
		}
	
		showErrorPopup(string_id);
	}
}
#endif /* __MMI_BT_SUPPORT__  */


#ifdef __MMI_WLAN_FEATURES__
void VappShellSettingsScr::preSwitchWlan(const VfxBool &state)
{
	if (state)
	{
		if(srv_tethering_is_switching(SRV_TETHERING_TYPE_WIFI_HS) == MMI_TRUE)
		{
			showErrorPopup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
			return;
		}
        if(MMI_FALSE == srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS))
        {
            // If the tethering is on, ask user to turn off the hotspot 
        	VcpConfirmPopup *cnfPopup;
        	VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, findScreen());
        	cnfPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        	cnfPopup->setText(VFX_WSTR_RES(STR_ID_DTCNT_WLAN_TURN_OFF_HOTSPOT_CFM));
            /*
        	cnfPopup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_ACTIVATE),
        							  VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        							  VCP_POPUP_BUTTON_TYPE_RECOMMEND,
        							  VCP_POPUP_BUTTON_TYPE_CANCEL);
        							  */
        	cnfPopup->m_signalButtonClicked.connect(this, &VappShellSettingsScr::onTurnOffHotspotPopCallback);
        	cnfPopup->setAutoDestory(VFX_TRUE);
        	cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
        	cnfPopup->show(VFX_TRUE);
            return;
        }
	}
    switchWlan(state);
}

void VappShellSettingsScr::switchWlan(const VfxBool &state)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_SWITCH_WIFI, state);
	
	srv_dtcnt_result_enum ret;
    
    showWaitingIcon();
    
	if (state)
	{
		ret = srv_dtcnt_wlan_init(NULL, NULL);
	}
	else
	{
		ret = srv_dtcnt_wlan_deinit(NULL, NULL);
	}

	if (ret == SRV_DTCNT_RESULT_FAILED)
	{
		if (state)
		{
			srv_dtcnt_wlan_init_res_ind_evt_struct evt;
			evt.res = SRV_DTCNT_WLAN_REQ_RES_FAILED;
			evt.evt_id = EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND;
			
			onSwitchWlanResult((mmi_event_struct *)&evt);
		}
		else
		{
			srv_dtcnt_wlan_deinit_res_ind_evt_struct evt;
			evt.res = SRV_DTCNT_WLAN_REQ_RES_FAILED;
			evt.evt_id = EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND;

			onSwitchWlanResult((mmi_event_struct *)&evt);

		}
	}
}

void VappShellSettingsScr::onTurnOffHotspotPopCallback(VfxObject *obj, VfxId id)
{
    switch (id)
	{
	case VCP_CONFIRM_POPUP_BUTTON_YES:
        // Show a waiting popup
		srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, (srv_tethering_cb_func_ptr)&VappShellSettingsScr::switchHotspotCallback, this);
		break;

	default:
		break;
	}
}
void VappShellSettingsScr::launchWlanApp(void)
{
	mmi_wlan_entry_wlan_wizard_new();
}

void VappShellSettingsScr::onSwitchWlanResult(mmi_event_struct *evt)
{
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_WIFI_RESULT, 0, 0);	

	if (m_idPending == INLINE_ENUM(INLINE_WIFI))
	{
		closeWaitingIcon();
	}	
	
	if (m_inlineMenu == NULL)
	{
		m_idPending = INLINE_ENUM(INLINE_TOTAL);
		return;
	}
	

	VfxBool result;
	
	if (evt->evt_id == EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND)
	{
		srv_dtcnt_wlan_init_res_ind_evt_struct *wlan_evt;
		wlan_evt = (srv_dtcnt_wlan_init_res_ind_evt_struct *)evt;
		result = (wlan_evt->res == SRV_DTCNT_WLAN_REQ_RES_DONE) ? VFX_TRUE : VFX_FALSE;
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_WIFI_ON, result);
	}
	else
	{
		srv_dtcnt_wlan_deinit_res_ind_evt_struct *wlan_evt;
		wlan_evt = (srv_dtcnt_wlan_deinit_res_ind_evt_struct *)evt;
		result = (wlan_evt->res == SRV_DTCNT_WLAN_REQ_RES_DONE) ? VFX_TRUE : VFX_FALSE;
		VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_WIFI_OFF, result);
	}
	
	m_inlineMenu->onPendingActivityCompletion(INLINE_ENUM(INLINE_WIFI), result);

	if (result)
	{
		if (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INACTIVE ||
			srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INVALID_MAC)
		{
			m_inlineMenu->updateCellSwitchStatus(INLINE_ENUM(INLINE_WIFI), VFX_FALSE);
			m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_WIFI_SEARCH), VFX_FALSE);
			VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_WIFI_MENU, 0);
		}
		else
		{
			m_inlineMenu->updateCellSwitchStatus(INLINE_ENUM(INLINE_WIFI), VFX_TRUE);
			m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_WIFI_SEARCH), VFX_TRUE);
			VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_WIFI_MENU, 1);
		}

		//initWlanMenu();
	}
	else
	{
		showErrorPopup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
	}
}

void VappShellSettingsScr::onSwitchHotspotCallback(VfxBool result)
{
    if (result)    
	{
        // Turn on WLAN
	    switchWlan(VFX_TRUE);
	}
    else
    {
        showErrorPopup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
    }
}

void VappShellSettingsScr::switchHotspotCallback(VfxU16 tethering_type, MMI_BOOL result, void *user_data)
{
	if (tethering_type == SRV_TETHERING_TYPE_WIFI_HS && VappShellSettingsScr::s_currScr != NULL)
	{
		VappShellSettingsScr::s_currScr->onSwitchHotspotCallback((result == MMI_TRUE ? VFX_TRUE : VFX_FALSE));
	}	
}

void VappShellSettingsScr::initWlanMenu(void)
{
	
		if (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INACTIVE)
		{
			m_inlineMenu->updateCellVisibility(INLINE_ENUM(INLINE_WIFI_SEARCH), VFX_FALSE);
		}
		
		if (!srv_mode_switch_is_network_service_available())
		{
#ifndef __OP01__
			m_inlineMenu->updateCellActiveState(INLINE_ENUM(INLINE_WIFI), VFX_TRUE);
#else /*__OP01__  */
			m_inlineMenu->updateCellActiveState(INLINE_ENUM(INLINE_WIFI), VFX_FALSE);
#endif /*__OP01__  */
		}
		else
		{
			m_inlineMenu->updateCellActiveState(INLINE_ENUM(INLINE_WIFI), VFX_TRUE);
		}

	}
#ifndef __OP01__
void VappShellSettingsScr::showActiveWlanConfirm(void)
	{
	VcpConfirmPopup *cnfPopup;
	VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, findScreen());
	cnfPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
	cnfPopup->setText(VFX_WSTR_RES(STR_ID_DTCNT_WLAN_OPEN_WLAN_UNDER_FLIGHT));
	cnfPopup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_ACTIVATE),
							  VFX_WSTR_RES(STR_GLOBAL_CANCEL),
							  VCP_POPUP_BUTTON_TYPE_RECOMMEND,
							  VCP_POPUP_BUTTON_TYPE_CANCEL);
	cnfPopup->m_signalButtonClicked.connect(this, &VappShellSettingsScr::onCommandPopCallbackForWlan);
	cnfPopup->setAutoDestory(VFX_TRUE);
	cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
	cnfPopup->show(VFX_TRUE);
	}

void VappShellSettingsScr::onCommandPopCallbackForWlan(VfxObject *obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
	{
		m_bNewVisual = VFX_TRUE;
		// Waiting icon will be shown in the switchWlan()
		preSwitchWlan(VFX_TRUE);
	}
}
#endif /* __OP01__ */

#endif /* __MMI_WLAN_FEATURES__ */

void VappShellSettingsScr::showErrorPopup(const VfxResId &resId)
{	
	VFX_LOG(VFX_FUNC, VAPP_SHELL_SETTINGS_ERROR);	

	VcpAlertPopup *failPopup;
	VFX_OBJ_CREATE(failPopup, VcpAlertPopup, findScreen());
	failPopup->setDuration(2000);
    failPopup->setText(VFX_WSTR_RES(resId));
	failPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
	failPopup->setAutoDestory(VFX_TRUE);
	failPopup->show(VFX_TRUE);
}

#endif /* __MMI_VUI_SHELL_SETTINGS__ */

