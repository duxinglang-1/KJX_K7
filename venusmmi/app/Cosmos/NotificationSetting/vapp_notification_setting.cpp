/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   vapp_notification_setting.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   notification setting app
 *
 * Author:
 * -------
 * -------
 *
 *
 *****************************************************************************
 *============================================================================
 *			 HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

//#include "gs_srv_vfx_framework.h" // for GRP_ID_ROOT
#include "MMI_features.h" 
#ifdef __MMI_NSS_SUPPORT__
extern "C"
{
	#include "kal_public_api.h" // for kal_wsprintf
	#include "PnSrvGprot.h"
	#include "NotificationSettingSrvGprot.h"
	#include "AppMgrSrvGprot.h" // for srv_app_info_struct
}
#include "vfx_string.h" // for VFX_WSTR_MEM
#include "vfx_app_launcher.h" // for VfxAppLauncher
#include "vcp_navi_title_bar.h" // for VcpTitleBar
#include "vapp_notification_setting.h"
#include "vcp_confirm_popup.h" // for VcpConfirmPopup

#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA" 

#define VAPP_NOTIFICATION_BG_CELL_ID (5)
void vapp_notification_setting_launch(VfxMainScr* scr)
{
    VfxAppLauncher::launch( 
    VAPP_NOTIFICATION_SETTING, 
    VFX_OBJ_CLASS_INFO(VappNSettingApp),
    GRP_ID_ROOT);
}

/*****************************************************************************
 * Class VappNSettingIconFormCell implementation
 *****************************************************************************/
	VFX_IMPLEMENT_CLASS("VappNSettingIconFormCell", VappNSettingIconFormCell, VcpFormItemLauncherCell);

void VappNSettingIconFormCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
    m_imageFrame->setAnchor(0, 0.5);
    m_imageFrame->setPos(IMG_LEFT_GAPS, getBounds().getHeight() / 2);
    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);


    m_mainText->setRect(VfxRect(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                 m_mainText->getPos().y,
                                 getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ACCESSORY_WIDTH + ACCESSORY_RIGHT_GAPS),
                                 m_mainText->getRect().getHeight()));
}
void VappNSettingIconFormCell::setIconResId(VfxU32 id) 
{
	if (id) 
	{
		m_imageFrame->setResId(id);
		m_imageFrame->setSize(IMG_MAX_WIDTH, IMG_MAX_HEIGHT);
	}
}

void VappNSettingIconFormCell::setIconImage(const mmi_image_src_struct& aImage)
{
	if(MMI_IMAGE_SRC_TYPE_RES_ID == aImage.type)
		m_imageFrame->setResId(aImage.data.res_id);
	else if(MMI_IMAGE_SRC_TYPE_PATH == aImage.type)
	{
		VfxWString path;
		path.loadFromMem(aImage.data.path);
		m_imageFrame->setPath(path);
	}
	else if(MMI_IMAGE_SRC_TYPE_MEM == aImage.type)
	{
		m_imageFrame->loadFromMem(aImage.data.mem);
	}
	else if(MMI_IMAGE_SRC_TYPE_ROM_MEMORY == aImage.type)
	{
		VfxImageSrc imgSrc(aImage.data.image.image_ptr,
								aImage.data.image.image_len,
								VFX_FILE_FORMAT_TYPE_AUTO);
		
		m_imageFrame->setImgContent(imgSrc);
	}
	else
	{
		VFX_OBJ_CLOSE(m_imageFrame);
		return;
	}
	m_imageFrame->setSize(IMG_MAX_WIDTH, IMG_MAX_HEIGHT);
}

void VappNSettingIconFormCell::onUpdate()
{
    VcpFormItemLauncherCell::onUpdate();
    
    if (m_mainText)
    {
        m_mainText->setPos(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, m_mainText->getPos().y);	
	m_mainText->setSize(getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ACCESSORY_WIDTH + ACCESSORY_RIGHT_GAPS), m_mainText->getRect().getHeight());
    }
}


/*****************************************************************************
 * Class VappNSettingApp implementation
 *****************************************************************************/
/*---------------------------------------------------------------------------*
 * Function: onRun()
 * Description: virtual function from VfxApp, Be called when VappNSettingApp is launching. 
 *---------------------------------------------------------------------------*/
VFX_IMPLEMENT_CLASS("VappNSettingApp", VappNSettingApp, VfxApp);
void VappNSettingApp::onRun(void* args, VfxU32 argSize)
{
//local var:
	
//func implementation:
	VfxApp::onRun(args, argSize);

	VFX_OBJ_CREATE_EX(m_screen,VfxMainScrEx,this,(this));
	m_screen->setTransitType(VFX_SCR_TRANSIT_TYPE_CUI);
	m_screen->show();
}

/*---------------------------------------------------------------------------*
 * Function: onProc()
 * Description: App call back function.
 *    @return:
 *---------------------------------------------------------------------------*/
mmi_ret VappNSettingApp::onProc(mmi_event_struct *param)
{
//local var:
	
//func implementation:
	return VfxApp::onProc(param);
}

/*---------------------------------------------------------------------------*
 * Function: onScr1stReady()
 * Description: virtual function from IVfxMainScrHandler, Be called when screen is prepare to show.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::onScr1stReady(VfxMainScrEx* scr)
{
//local var:
	
//func implementation:
	VfxPage* page;
	VFX_OBJ_CREATE(page,VfxPage,scr);
	initAppsListPage(page);
	scr->pushPage(0,page);
}

/*---------------------------------------------------------------------------*
 * Function: onScr2ndReady()
 * Description: virtual function from IVfxMainScrHandler, Be called after 1st fram is drawed.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::onScr2ndReady(VfxMainScrEx* scr)
{
//local var:
	
//func implementation:
	
}

/*---------------------------------------------------------------------------*
 * Function: initAppsListPage()
 * Description: initialize the Apps List Page
 *---------------------------------------------------------------------------*/
void VappNSettingApp::initAppsListPage(VfxPage* aAppListPage)
{
//local var:
	VcpTitleBar *bar;
	VcpForm *form;
	VappNSettingIconFormCell* app;
//func implementation:
    VFX_OBJ_CREATE(bar, VcpTitleBar, aAppListPage);
    bar->setTitle(STR_VAPP_NOTIFICATION_SETTING);
    aAppListPage->setTopBar(bar);

	VFX_OBJ_CREATE(form, VcpForm, aAppListPage);
	form->setBounds(VfxRect(VfxPoint(0, 0), aAppListPage->getSize()));
	form->setAlignParent(
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE);
#ifdef __MMI_PNS__	
    VFX_OBJ_CREATE(m_backgroundSetting, VcpFormItemSwitchCell, form);
    m_backgroundSetting->setIsTappable(VFX_FALSE);
    m_backgroundSetting->setMainText(STR_ID_VAPP_NOTIFICATION_BACKGROUND_DATA);
    m_backgroundSetting->setSwitchStatus(SRV_PNS_SETTING_ON == srv_pns_get_global_setting());
    form->addItem(m_backgroundSetting, VAPP_NOTIFICATION_BG_CELL_ID);
	m_backgroundSetting->m_signalSwitchChangeReq.connect(this, &VappNSettingApp::onBackgroundSwitch);
#endif //__MMI_PNS__
	form->addCaption(STR_ID_VAPP_NOTIFICATION_BACKGROUND_APPS,0);
	VfxWString mainText;
	VfxU32 num = mmi_srv_nss_get_node_num();
	mmi_srv_nss_node node_info;

	for(VfxU32 i = 0; i < num; i++)
	{
		mmi_srv_nss_get_node_by_index (i , &node_info); 
	    VFX_OBJ_CREATE(app, VappNSettingIconFormCell, form);
		if(NATIVE_APP_TYPE == node_info.app_type)
		{
			mainText.loadFromRes(node_info.app_info.native_res.app_str_id);
			app->setIconResId(node_info.app_info.native_res.app_image_id);
			app->setMainText(mainText);
		}
		else // MRE_APP_TYPE
		{
			mmi_app_package_name_struct appPackageName;
			srv_app_info_struct mre_info;
			//app id -> package name
			srv_appmgr_get_app_package_name_by_id(node_info.app_id, appPackageName);
			srv_appmgr_get_app_package_info(
				appPackageName,
				&mre_info
				);
			mainText.loadFromMem((VfxWChar*)mre_info.string);
			app->setMainText(mainText);
			app->setIconImage(mre_info.image);
		}
		if(mainText.isEmpty())
			VFX_OBJ_CLOSE(app);
		else
		{
			app->setAccessory(VCPFORM_NEXT_ITEM_ICON);
			app->m_signalTap.connect(this, &VappNSettingApp::goToDetailSetting);
		    form->addItem(app, VAPP_NOTIFICATION_BG_CELL_ID + 1 +i);
		}
	}
}
/*---------------------------------------------------------------------------*
 * Function: onPopupButtonClicked()
 * Description: background data confirm popup call back function.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::onPopupButtonClicked(VfxObject* sender, VfxId id)
{
//local var:

//func implementation:
#ifdef __MMI_PNS__
	if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		srv_pns_switch_global_setting(SRV_PNS_SETTING_OFF);
		m_backgroundSetting->setSwitchStatus(VFX_FALSE);
	}	
#endif //__MMI_PNS__
}

/*---------------------------------------------------------------------------*
 * Function: onBackgroundSwitch()
 * Description: user clicked the background switch cell.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::onBackgroundSwitch(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal)
{
#ifdef __MMI_PNS__
//local var:

//func implementation:
	if(!newVal)
	{
	VcpConfirmPopup *popup = NULL;
	VFX_OBJ_CREATE (popup, VcpConfirmPopup, m_screen);
	popup->setInfoType(VCP_POPUP_TYPE_WARNING);
	popup->setText(STR_ID_VAPP_NOTIFICATION_BACKGROUND_DATA_CONFIRM);
	popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	popup->setCustomButton(
					  STR_GLOBAL_OK, 
					  STR_GLOBAL_CANCEL, 
					  VCP_POPUP_BUTTON_TYPE_NORMAL,
					  VCP_POPUP_BUTTON_TYPE_CANCEL
					  );
	popup->m_signalButtonClicked.connect(this, &VappNSettingApp::onPopupButtonClicked);
	popup->setAutoDestory(VFX_TRUE);
	popup->show(VFX_TRUE);

		return;
	}
	srv_pns_switch_global_setting(SRV_PNS_SETTING_ON);
	cell->setSwitchStatus(newVal);
#endif //__MMI_PNS__
}


/*---------------------------------------------------------------------------*
 * Function: onAppDetailSettingSwitch()
 * Description: user clicked the Form cells on detail page.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::onAppDetailSettingSwitch(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal)
{
//local var:
	VfxU32 value;
//func implementation:
	if(newVal)
	{
		value = SETTING_ON;
	}
	else
	{
		value = SETTING_OFF;
	}
	mmi_srv_nss_set_setting(m_appId, (nss_setting_key_enum)id, value);
	cell->setSwitchStatus(newVal);	
}


/*---------------------------------------------------------------------------*
 * Function: goToDetailSetting()
 * Description: go to detail setting page.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::goToDetailSetting(VcpFormItemCell* cell, VfxId Id)
{
//local var:
	 
//func implementation:
	m_appIndex = (VfxU32)(Id - VAPP_NOTIFICATION_BG_CELL_ID - 1);
	VFX_OBJ_CREATE(m_detailPage, VfxPage, m_screen);
	initAppsSettingPage();
	m_screen->pushPage(0,m_detailPage);
}



/*---------------------------------------------------------------------------*
 * Function: onStyleCellClicked()
 * Description: user clicked style cell.
 *---------------------------------------------------------------------------*/
void VappNSettingApp::onStyleCellClicked(VcpFormItemCell* cell, VfxId Id)
{
//local var:
	VfxPage* page;
//func implementation:
	VFX_OBJ_CREATE(page, VfxPage, m_screen);
	initStylePage(page);
	m_screen->pushPage(0,page);
}

/*---------------------------------------------------------------------------*
 * Function: initAppsSettingPage()
 * Description: initialize the Apps detail setting Page
 *---------------------------------------------------------------------------*/
void VappNSettingApp::initAppsSettingPage()
{
//local var:
	VcpTitleBar *bar;
	VcpForm *form;
	VcpFormItemSwitchCell *settings;
	mmi_srv_nss_node node_info;
    U32 currentValue;
    U32 mask;
	U32 settingValue;
//func implementation:

	mmi_srv_nss_get_node_by_index (m_appIndex, &node_info); 
	currentValue = node_info.notification_setting;
	mask = node_info.notification_mask;
	m_appId = node_info.app_id;
	//show app name
	VFX_OBJ_CREATE(bar, VcpTitleBar, m_detailPage);
	if(NATIVE_APP_TYPE == node_info.app_type)
	{
		bar->setTitle(node_info.app_info.native_res.app_str_id);
	}
	else // MRE_APP_TYPE
	{
		srv_app_info_struct mre_info;
		mmi_app_package_name_struct appPackageName;
		//app id -> package name
		srv_appmgr_get_app_package_name_by_id(m_appId, appPackageName);
		srv_appmgr_get_app_package_info(
			appPackageName,
			&mre_info
			);
		bar->setTitle(mre_info.string);
	}
	m_detailPage->setTopBar(bar);


	VFX_OBJ_CREATE(form, VcpForm, m_detailPage);
	form->setBounds(VfxRect(VfxPoint(0, 0), m_detailPage->getSize()));
	form->setAlignParent(
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE);

	if(NSS_IS_SETTING_CONFIGURABLE(mask, NSS_MASK_NCENTER))
	{
		VFX_OBJ_CREATE(settings, VcpFormItemSwitchCell, form);
		settings->setIsTappable(VFX_FALSE);
		settings->setMainText(STR_ID_VAPP_NOTIFICATION_CENTER);// "Notification center"
		NSS_EXTRACT_SETTING_VALUE(currentValue, NSS_SETTING_NCENTER, settingValue);
		settings->setSwitchStatus(SETTING_ON == settingValue);
		settings->m_signalSwitchChangeReq.connect(this, &VappNSettingApp::onAppDetailSettingSwitch);
		form->addItem(settings, NSS_SETTING_NCENTER);
	}

	
	if(NSS_IS_SETTING_CONFIGURABLE(mask, NSS_MASK_ALERT))
	{
		VfxResId hintTextId;
		VFX_OBJ_CREATE(m_styleCell, VcpFormItemLauncherCell, form);
	    m_styleCell->setMainText(STR_ID_VAPP_NOTIFICATION_STYLE);//"Notification style"
		NSS_EXTRACT_SETTING_VALUE(currentValue, NSS_SETTING_ALERT, settingValue);
		if(ALERT_TYPE_STATUS_BAR == settingValue)
		{
			hintTextId = STR_ID_VAPP_NOTIFICATION_STATUS_BAR;
			m_styleIndex = 1;
		}
		else if(ALERT_TYPE_POPUP == settingValue)
		{
			hintTextId = STR_ID_VAPP_NOTIFICATION_POPUP;
			m_styleIndex = 2;
		}
		else
		{
			hintTextId = STR_ID_VAPP_NOTIFICATION_NONE;
			m_styleIndex = 0;
		}
	    m_styleCell->setHintText(hintTextId);
		m_styleCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	    m_styleCell->m_signalTap.connect(this, &VappNSettingApp::onStyleCellClicked);
	    form->addItem(m_styleCell, NSS_SETTING_ALERT);
	}

	
	if(NSS_IS_SETTING_CONFIGURABLE(mask, NSS_MASK_BADGE_ICON))
	{
		VFX_OBJ_CREATE(settings, VcpFormItemSwitchCell, form);
		settings->setIsTappable(VFX_FALSE);
		settings->setMainText(STR_ID_VAPP_NOTIFICATION_BADGE_ICON);// "Badge app icon"
		NSS_EXTRACT_SETTING_VALUE(currentValue, NSS_SETTING_BADGE_ICON, settingValue);
		settings->setSwitchStatus(SETTING_ON == settingValue);
		settings->m_signalSwitchChangeReq.connect(this, &VappNSettingApp::onAppDetailSettingSwitch);
		form->addItem(settings, NSS_SETTING_BADGE_ICON);
	}
	
	
	if(NSS_IS_SETTING_CONFIGURABLE(mask, NSS_MASK_SOUND))
	{
		VFX_OBJ_CREATE(settings, VcpFormItemSwitchCell, form);
		settings->setIsTappable(VFX_FALSE);
		settings->setMainText(STR_ID_VAPP_NOTIFICATION_SOUND);// "Sound"
		NSS_EXTRACT_SETTING_VALUE(currentValue, NSS_SETTING_SOUND, settingValue);
		settings->setSwitchStatus(SETTING_ON == settingValue);
		settings->m_signalSwitchChangeReq.connect(this, &VappNSettingApp::onAppDetailSettingSwitch);
		form->addItem(settings, NSS_SETTING_SOUND);
	}
	
	
	if(NSS_IS_SETTING_CONFIGURABLE(mask, NSS_MASK_LOCK_SCRN))
	{
		VFX_OBJ_CREATE(settings, VcpFormItemSwitchCell, form);
		settings->setIsTappable(VFX_FALSE);
		settings->setMainText(STR_ID_VAPP_NOTIFICATION_VIEW_IN_LOCK);// "View in lock screen"
		NSS_EXTRACT_SETTING_VALUE(currentValue, NSS_SETTING_LOCK_SCRN, settingValue);
		settings->setSwitchStatus(SETTING_ON == settingValue);
		settings->m_signalSwitchChangeReq.connect(this, &VappNSettingApp::onAppDetailSettingSwitch);
		form->addItem(settings, NSS_SETTING_LOCK_SCRN);
	}
}


/*---------------------------------------------------------------------------*
 * Function: initStylePage()
 * Description: initialize the App Style Page
 *---------------------------------------------------------------------------*/
void VappNSettingApp::initStylePage(VfxPage* aStylePage)
{
//local var:
	VcpTitleBar *titleBar;
	mmi_srv_nss_node node_info;
//func implementation:
	mmi_srv_nss_get_node_by_index (m_appIndex, &node_info); 
	m_appId = node_info.app_id;
	//show app name
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, aStylePage);
	if(NATIVE_APP_TYPE == node_info.app_type)
	{
		titleBar->setTitle(node_info.app_info.native_res.app_str_id);
	}
	else // MRE_APP_TYPE
	{
		srv_app_info_struct mre_info;
		mmi_app_package_name_struct appPackageName;
		//app id -> package name
		srv_appmgr_get_app_package_name_by_id(m_appId, appPackageName);
		srv_appmgr_get_app_package_info(
			appPackageName,
			&mre_info
			);
		titleBar->setTitle(mre_info.string);
	}
	aStylePage->setTopBar(titleBar);


    VFX_OBJ_CREATE(m_listMenu,VcpListMenu, aStylePage);
	m_listMenu->setContentProvider(this);
	m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setSize(m_screen->getSize());
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappNSettingApp::onItemSelect);
}


/*---------------------------------------------------------------------------*
  * Function: onItemSelect()
  * Description: callback function, be called when user select a notification style.
  *---------------------------------------------------------------------------*/
void VappNSettingApp::onItemSelect(VcpListMenu *menuList, VfxU32 item_id)
{
	//local var:
	VfxResId strId = 0;
	VfxU16 styleId = 0;
	//func implementation:
	switch(item_id)
	{
		case 0:
		{
			strId = STR_ID_VAPP_NOTIFICATION_NONE;
			styleId = ALERT_TYPE_NONE;
			break;
		}
		case 1:
		{
			strId = STR_ID_VAPP_NOTIFICATION_STATUS_BAR;
			styleId = ALERT_TYPE_STATUS_BAR;
			break;
		}
		case 2:
		{
			strId = STR_ID_VAPP_NOTIFICATION_POPUP;
			styleId = ALERT_TYPE_POPUP;
			break;
		}
		default:
			return;
	}
	m_styleIndex = item_id;
	mmi_srv_nss_set_setting(m_appId, NSS_SETTING_ALERT, styleId);
	m_styleCell->setHintText(strId);
	m_screen->popPage();
}

/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Description: virtual function from IVcpListMenuContentProvider, give image of list items.
 *---------------------------------------------------------------------------*/
VfxBool VappNSettingApp::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
//local var:
	VfxResId hintTextId;
//func implementation:
	if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
		if(0 == index)
		{
			hintTextId = STR_ID_VAPP_NOTIFICATION_NONE;
		}
		else if(1 == index)
		{
			hintTextId = STR_ID_VAPP_NOTIFICATION_STATUS_BAR;
		}
		else
		{
			hintTextId = STR_ID_VAPP_NOTIFICATION_POPUP;
		}
		text.loadFromRes(hintTextId);
		return VFX_TRUE;
    }	
	return VFX_FALSE;
}	

/*---------------------------------------------------------------------------*
 * Function: getItemState()
 * Description: virtual from IVcpListMenuContentProvider, give the item status.
 *---------------------------------------------------------------------------*/
VcpListMenuItemStateEnum VappNSettingApp::getItemState(VfxU32 index) const
{
//local var:
	
//func implementation:
	if(index == m_styleIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}	

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Description: the count of list items .
 *---------------------------------------------------------------------------*/
VfxU32 VappNSettingApp::getCount() const
{
//local var:
	
//func implementation:
	return 3;
}

#pragma arm section code, rodata
/*---------------------------------------------------------------------------*/
#endif // __MMI_NSS_SUPPORT__

//End of File
