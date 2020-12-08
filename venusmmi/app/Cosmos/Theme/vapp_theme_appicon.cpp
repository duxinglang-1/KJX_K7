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
 *  vapp_theme.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Theme AP
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#ifdef __MMI_THEMES_APPLICATION__
#include "MMIDataType.h"
#include "CustVenusThemeRes.h"
#include "CustVenusAppIconCfg.h"
#include "GlobalResDef.h"
#include "FileMgrSrvGprot.h"
#include "vapp_home_gprot.h"
extern "C"
{
#include "mmi_msg_struct.h"
#include "mmi_frm_scenario_gprot.h"
}

#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vapp_theme_def.h"
#include "mmi_rp_vapp_theme_appicon_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_main_scr.h"
#include "vfx_app_launcher.h"

#include "vcp_navi_title_bar.h"

#include "vapp_launcher_setting_provider.h"
#include "vapp_wallpaper_setting_method_gprot.h"

#include "vapp_home_gprot.h"
#include "vapp_theme_dlt.h"
#include "vapp_theme_appicon.h"

#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
#include "vapp_theme_appicon_dlt.h"
#endif


#include "vapp_launcher_setting_provider.h"
#include "vapp_wallpaper_setting_method_gprot.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_THEME_APPICON_SYS_TOTAL (VAPP_THEME_SYSTEM_APPICON_CNT + __MMI_COSMOS_APP_ICON_COUNT__)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" 
mmi_id vapp_theme_appicon_init(mmi_event_struct *evt)
{
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	VappThemeAppIconDltData::initAppIcon();

#else
	VappThemeAppIconCntx *appIconCntx = VFX_OBJ_GET_INSTANCE(VappThemeAppIconCntx);

	VappLauncherSettingProvider *provider;
	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	provider->m_signalDefaultLauncherChanged.connect(appIconCntx, &VappThemeAppIconCntx::onLauncherChange);

	appIconCntx->checkActive();
#endif

	return MMI_RET_OK;
}

VfxS32 vapp_theme_appicon_for_curr_launcher(VfxS32 launcherIntType)
{
	VfxS32 index = 0;
	

	switch(launcherIntType)
	{
#if defined(__MMI_VUI_LAUNCHER_COSMOS__)
		case VAPP_LAUNCHER_TYPE_COSMOS:
			index = 0;
			break;
#endif //__MMI_VUI_LAUNCHER_COSMOS__

#if defined(__MMI_VUI_LAUNCHER_MM__)
		case VAPP_LAUNCHER_TYPE_MM: // Fruite
	#ifdef __MMI_COSMOS_APP_ICON_MM__
			index = VAPP_THEME_SYSTEM_APPICON_CNT + __MMI_COSMOS_APP_ICON_MM__;
	#else
			index = 0;
	#endif
			break;
#endif //__MMI_VUI_LAUNCHER_MM__

#if defined(__MMI_VUI_LAUNCHER_ROBOT__)
		case VAPP_LAUNCHER_TYPE_ROBOT:
	#ifdef __MMI_COSMOS_APP_ICON_ROBOT__
			index = (VAPP_THEME_SYSTEM_APPICON_CNT + __MMI_COSMOS_APP_ICON_ROBOT__);
	#else
			index = 0;
	#endif
			break;
#endif //__MMI_VUI_LAUNCHER_ROBOT__

		default:
			index = 0;
			break;
	};

	return index;
}

/***************************************************************************** 
 * VappThemeAppIconCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeAppIconCell", VappThemeAppIconCell, VcpFormItemLauncherCell);
void VappThemeAppIconCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

	setAccessory(VCPFORM_NEXT_ITEM_ICON);
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_THEME_APPICON));
    m_signalTap.connect(this, &VappThemeAppIconCell::onTap);
}

void VappThemeAppIconCell::onTap(VcpFormItemCell *cell, VfxId id)
{
	VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

	if (mainScr != NULL)
	{
		mmi_id cuiId = VfxAppLauncher::createCui(
							VAPP_THEME_APPICON,
							VFX_OBJ_CLASS_INFO(VcuiThemeAppIcon),
							mainScr->getApp()->getGroupId());

		if (cuiId != GRP_ID_INVALID)
		{
			VfxAppLauncher::runCui(cuiId);
		}
	}
	
	return;
}

mmi_id vapp_theme_appicon_launch(void)
{
	mmi_id id = VfxAppLauncher::launch(
					VAPP_THEME_APPICON,
					VFX_OBJ_CLASS_INFO(VappThemeAppIcon),
					GRP_ID_ROOT);
	return id;
}


#ifndef __MMI_VUI_DOWNLOADABLE_APP_ICON__
/***************************************************************************** 
 * Class VappThemeAppIconCntx Implementation
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappThemeAppIconCntx);
VappThemeAppIconCntx::VappThemeAppIconCntx() :
	VappThemeCntx(),
	m_hdlr(INVALID_THEME_HANDLE)
{

}

VfxS16 VappThemeAppIconCntx::active(VfxU32 index)
{
	deactive();

	if (index < VAPP_THEME_SYSTEM_APPICON_CNT)
	{
		return 0;
	}
	
	mmi_res_theme_ret_enum ret;

	ret = mmi_res_set_priority_theme(
			VAPP_THEME_SYSTEM_APPICON_POS(index),
			MMI_RES_THEME_PRIORITY_MEDIUM,
			(mmi_res_theme_handle *)&m_hdlr);
	
	return ret;
}

VfxS16 VappThemeAppIconCntx::deactive(void)
{
	if (m_hdlr != INVALID_THEME_HANDLE)
	{
		mmi_res_close_priority_theme((mmi_res_theme_handle)m_hdlr);

		m_hdlr = INVALID_THEME_HANDLE;
	}

	return 0;
}

VfxU32 VappThemeAppIconCntx::getActiveIndex(void)
{
	VfxU8 launcherInt[8]; // launcher[launcher] = appicon
	VfxS16 errCode;
	
	ReadValue(NVRAM_THEME_APPICON_ACTIVE_INDEX, launcherInt, DS_DOUBLE, &errCode);

	VappLauncherSettingProvider *provider;
	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	VappLauncherId launcherId = provider->getDefaultLauncher();

	if (launcherId.getSource() == VAPP_LAUNCHER_SRC_NATIVE)
	{
		if (launcherInt[launcherId.getIntType()] > VAPP_THEME_APPICON_SYS_TOTAL)
		{
			return restoreAppicon();
		}
	}
	
	return (VfxU32)launcherInt[launcherId.getIntType()];
}

VfxU32 VappThemeAppIconCntx::restoreAppicon(void)
{
	VappLauncherSettingProvider *provider;

	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	VfxS32 index = 0;
	
	VappLauncherId launcherId = provider->getDefaultLauncher();

	if (launcherId.getSource() == VAPP_LAUNCHER_SRC_NATIVE)
	{
		index = vapp_theme_appicon_for_curr_launcher(launcherId.getIntType());
	}
	
	setActiveIndex(index);

	return index;
}

VfxBool VappThemeAppIconCntx::setActiveIndex(VfxU32 index)
{
	VfxU8 buffer[8]; // launcher[appicon1] = launchr1
	VfxS16 errCode;

	ReadValue(NVRAM_THEME_APPICON_ACTIVE_INDEX, buffer, DS_DOUBLE, &errCode);

	VappLauncherSettingProvider *provider;

	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	
	VappLauncherId launcherId = provider->getDefaultLauncher();

	if (launcherId.getSource() == VAPP_LAUNCHER_SRC_NATIVE)
	{
		buffer[launcherId.getIntType()] = index;
	}
	
	WriteValue(NVRAM_THEME_APPICON_ACTIVE_INDEX, buffer, DS_DOUBLE, &errCode);

	return VFX_TRUE;
}

void VappThemeAppIconCntx::onLauncherChange(void)
{
	checkActive();
}

VfxBool VappThemeAppIconCntx::checkActive(void)
{
	active(getActiveIndex());
	
	return VFX_TRUE;
}

#endif //  __MMI_VUI_DOWNLOADABLE_APP_ICON__

/***************************************************************************** 
 * Class VcuiThemeAppIcon
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiThemeAppIcon", VcuiThemeAppIcon, VappThemeApp);
void VcuiThemeAppIcon::onScr1stReady(VfxMainScrEx *scr)
{
	VappThemeAppIconListPage *page;
	
	VFX_OBJ_CREATE_EX(page, VappThemeAppIconListPage, scr, (m_allocator));
	scr->pushPage('GRID', page);
}


/***************************************************************************** 
 * Class VappThemeAppIcon
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeAppIcon", VappThemeAppIcon, VfxApp);
void VappThemeAppIcon::onRun(void * args,VfxU32 argSize)
{
	VfxMainScrEx *scr;
	VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
	scr->show();
}
	
void VappThemeAppIcon::onScr1stReady(VfxMainScrEx *scr)
{
	VappThemeAppIconListPage *page;
		
	VFX_OBJ_CREATE_EX(page, VappThemeAppIconListPage, scr, (m_allocator));
	scr->pushPage('GRID', page);
}

void VappThemeAppIcon::onInit(void)
{
	VfxApp::onInit();

	VFX_OBJ_CREATE_EX(m_allocator, VappThemeMemAllocator, this, (getGroupId()));
}

void VappThemeAppIcon::onDeinit(void)
{
	m_allocator->freeBuffer();
	
	VfxApp::onDeinit();
}

void VappThemeAppIcon::onGroupTopActive(void)
{
	m_allocator->setGroupId(getGroupId());
	m_allocator->createBuffer();
}

void VappThemeAppIcon::onGroupTopInactive(void)
{
	m_allocator->m_signalBeforeMemFree.emit();	
	m_allocator->freeBuffer();
}


/***************************************************************************** 
 * Class VappThemeAppIconData
 *****************************************************************************/
VfxBool VappThemeAppIconData::getTypeStr(VfxWString &typeName)
{ 
	typeName.loadFromRes(STR_ID_VAPP_THEME_APPICON_SYS);

	return VFX_TRUE;
}

VfxBool VappThemeAppIconData::isActivated(VfxS32 pos)
{
	VappThemeCntx *cntx;
	
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	cntx = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
#else
	cntx = VFX_OBJ_GET_INSTANCE(VappThemeAppIconCntx);
#endif

	if (cntx->getActiveIndex() == pos)
	{
		return VFX_TRUE;
	}
	
	return VFX_FALSE;
}

VfxImageSrc VappThemeAppIconData::getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size)
{

#if (VAPP_THEME_SYSTEM_APPICON_CNT >= 1)
	if (pos == 0)
	{
		return VfxImageSrc(IMG_ID_VAPP_APPICON_DEFAULT_THUMBNAIL);
	}
	else
#endif
	{
		VfxU8 *img = (VfxU8 *)mmi_res_get_pri_theme_thumbnail(mmi_res_get_app_icon_data(VAPP_THEME_SYSTEM_APPICON_POS(pos)));
		if (img != NULL)
		{
			return VfxImageSrc(img);
		}
		else
		{
			VfxImageSrc(IMG_ID_VAPP_APPICON_DEFAULT_THUMBNAIL);
		}
	}

	return VFX_IMAGE_SRC_NULL;
}

VfxImageSrc VappThemeAppIconData::getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size)
{
#if (VAPP_THEME_SYSTEM_APPICON_CNT >= 1)
	if (pos == 0)
	{
		return VfxImageSrc(IMG_ID_VAPP_APPICON_DEFAULT_PREVIEW);
	}
	else
#endif
	{
		VfxU8 *img = (VfxU8 *)mmi_res_get_pri_theme_preview(mmi_res_get_app_icon_data(VAPP_THEME_SYSTEM_APPICON_POS(pos)));
		if (img != NULL)
		{
			return VfxImageSrc(img);
		}
		else
		{
			VfxImageSrc(IMG_ID_VAPP_APPICON_DEFAULT_PREVIEW);
		}
	}

	return VFX_IMAGE_SRC_NULL;
}

VfxU32 VappThemeAppIconData::getCount(void) const
{
	// system appIcon + appicon
	return VAPP_THEME_APPICON_SYS_TOTAL;//mmi_res_get_app_icon_count();
}

VfxWString VappThemeAppIconData::getText(VfxS32 pos)
{
	return VFX_WSTR_RES(STR_ID_VAPP_THEME_APPICON1 + pos);
}

void VappThemeAppIconData::genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos)
{
	desc.type = VappThemeData::THEME_TYPE_SYS;
	desc.u.index = pos;
	
	desc.m_changedId = STR_ID_VAPP_THEME_APPICON_CHANGED;
	desc.m_compatibleAskId = STR_ID_VAPP_THEME_APPICON_COMPATIBLE_ASK;
	desc.m_invalidId = STR_ID_VAPP_THEME_APPICON_INVALID;
	desc.m_switchingId = STR_ID_VAPP_THEME_APPICON_SWITCH;
}

VfxClassInfo *VappThemeAppIconData::getCuiClassInfo(void)
{
	return VFX_OBJ_CLASS_INFO(VappThemeAppIconSwitchCui);
}


/***************************************************************************** 
 * Class VappThemeAppIconSwitchCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeAppIconSwitchCui", VappThemeAppIconSwitchCui, VappThemeSwitchCui);
VfxBool VappThemeAppIconSwitchCui::active(void)
{
	VappThemeCntx *cntx;
	
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	cntx = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
#else
	cntx = VFX_OBJ_GET_INSTANCE(VappThemeAppIconCntx);
#endif
	
	if (cntx->active(m_switchDesc.u.index) == 0)
	{
		cntx->setIsDltActive(VFX_FALSE, m_switchDesc.u.index);
	    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
	    wallpaperInterface->restoreWallpaperEx(VAPP_WALLPAPER_HOME_SCREEN, VFX_FALSE);

		return VFX_TRUE;
	}
	
	return VFX_FALSE;
}


/***************************************************************************** 
 * Class VappThemeListPage
 *****************************************************************************/
void VappThemeAppIconListPage::onInitData(void)
{
	VcpTitleBar *titleBar = (VcpTitleBar *)getBar(VFX_PAGE_BAR_LOCATION_TOP);
	if(titleBar != NULL)
	{
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_THEME_APPICON));
	}

	VfxU32 index = 0;

	VappThemeAppIconData *sysData;
	VFX_OBJ_CREATE(sysData, VappThemeAppIconData, this);
	m_themeData[index] = sysData;
	index++;


#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	VappThemeAppIconDltData *dltData;
	VFX_OBJ_CREATE(dltData, VappThemeAppIconDltData, this);
	m_themeData[index] = dltData;
	dltData->m_signalNeedReset.connect(this, &VappThemeAppIconListPage::onNeedReset);
#endif // __MMI_VUI_DOWNLOADABLE_APP_ICON__
}


VfxU32 VappThemeAppIconListPage::getGroupCount() const
{
	VfxU32 count = 1;
	
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	count++;
#endif

	return count;
}


VfxBool VappThemeAppIconListPage::isDltGroup(VfxS32 group) const
{
	if (getGroupCount() > 1)
	{
		return VappThemeListPage::isDltGroup(group);
	}
	else
	{
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
		return VFX_TRUE;
#endif
	}

	return VFX_FALSE;
}

VfxBool VappThemeAppIconListPage::getMenuEmptyText(VfxWString &text)
{
	if (m_isRefreshing)
	{
		text.loadFromRes(STR_ID_VAPP_THEME_APPICON_LOADING);
	}
	else
	{
		text.loadFromRes(STR_ID_VAPP_THEME_APPICON_NO);
	}	
	
	return VFX_TRUE;
}

#endif  /*__MMI_THEMES_APPLICATION__*/
