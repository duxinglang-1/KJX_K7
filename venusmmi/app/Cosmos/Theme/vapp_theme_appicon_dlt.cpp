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
 *  vapp_theme_appicon_dlt.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Downloadable theme support
 *	dlt theme from phone and card are merge sorted togther, 
 *	the actived theme file will be listed at first postion
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "CustVenusThemeRes.h"

#include "nvram_common_defs.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_vapp_theme_def.h"
#include "mmi_rp_vapp_theme_appicon_def.h"

extern "C"
{
#include "FileMgrSrvGprot.h"
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}

#include "vfx_archive.h"
#include "vapp_launcher_setting_provider.h"
#include "vapp_wallpaper_setting_method_gprot.h"

#include "vapp_theme_appicon.h"
#include "vapp_theme_appicon_dlt.h"


/***************************************************************************** 
 * Global function
 *****************************************************************************/


/***************************************************************************** 
 * VappThemeDltAppIconCntx
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappThemeDltAppIconCntx);
VfxU8 VappThemeDltAppIconCntx::s_cntxBuffer[2048];
VfxWChar VappThemeDltAppIconCntx::s_buff[NVRAM_EF_DLT_THEME_SIZE];
VappThemeDltAppIconCntx::VappThemeDltAppIconCntx() :
	VappThemeDltCntx(),
	m_hdlr(INVALID_THEME_HANDLE),
	m_selfMem(NULL)
{

}

void VappThemeDltAppIconCntx::onInit()
{
	VappThemeDltCntx::onInit();

	VFX_OBJ_CREATE(m_selfMem,  VfxContext, VFX_SYS_GLOBAL_CONTEXT);
	m_selfMem->assignPool(VappThemeDltAppIconCntx::s_cntxBuffer, 2048);
}


VfxWChar *VappThemeDltAppIconCntx::getCachePath(void)
{
	return (VfxWChar *)L"Z:\\@Settings\\IconCache.med"; 
}


VfxWChar *VappThemeDltAppIconCntx::getCacheBackupPath(void)
{
	return (VfxWChar *)L"Z:\\@Settings\\IconCacheB.med";
}


VfxS16 VappThemeDltAppIconCntx::active(const VfxWChar *path)
{
	deactive();
	
	mmi_res_theme_ret_enum ret;

	ret = mmi_res_set_dlt_priority_theme(
			path,
			MMI_RES_THEME_PRIORITY_MEDIUM,
			(mmi_res_theme_handle *)&m_hdlr);
	
	return ret;
}


VfxS16 VappThemeDltAppIconCntx::active(VfxU32 index)
{
	deactive();

	//
	// Don't need to active default appicon, return success directly
	//
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


VfxS16 VappThemeDltAppIconCntx::deactive(void)
{
	if (m_hdlr != INVALID_THEME_HANDLE)
	{
		mmi_res_close_priority_theme((mmi_res_theme_handle)m_hdlr);

		m_hdlr = INVALID_THEME_HANDLE;
	}

	return 0;
}


VfxU32 VappThemeDltAppIconCntx::getActiveIndex(void)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("adx", SA_start);
#endif

	VfxU8 index = 0;
	
	VappLauncherSettingProvider *provider;

	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	VfxArchive *ar = provider->createArchiveReader(
									VappLauncherSettingProvider::SETTING_ID_APP_ICON,
									this);

	VfxBool isReset;
	if (ar != NULL)
	{
		index = ar->readU8();
		isReset = VFX_FALSE;
	}
	else
	{
		isReset = VFX_TRUE;
	}
	
	printMemState();
	
	VFX_OBJ_CLOSE(ar);

	if (isReset)
	{
		index = restoreAppicon();
	}
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("adx", SA_stop);
#endif

	return index;
}


VfxBool VappThemeDltAppIconCntx::setActiveIndex(VfxU32 index)
{
	setIsDltActive(VFX_FALSE, index);

	return VFX_TRUE;
}


void VappThemeDltAppIconCntx::setIsDltActive(VfxBool isDlt, VfxU32 index)
{
	VappLauncherSettingProvider *provider;
	
	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
	
	VfxArchive *ar = provider->createArchiveWriter(
									VappLauncherSettingProvider::SETTING_ID_APP_ICON,
									this);
	VFX_ASSERT(ar != NULL);
	
	VfxU8 value = isDlt ? DLT_THEME_TAG : index;
	ar->writeU8(value);
	
	printMemState();
	VFX_OBJ_CLOSE(ar);
}


void VappThemeDltAppIconCntx::getActivePath(VfxWChar *path, VfxS32 size)
{
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("apt", SA_start);
#endif

	if (VappThemeDltAppIconCntx::s_buff[0] == 0 && VappThemeDltAppIconCntx::s_buff[1] == 0)
	{
		VappLauncherSettingProvider *provider;

		provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

		VfxArchive *ar = provider->createArchiveReader(
										VappLauncherSettingProvider::SETTING_ID_APP_ICON,
										this);
		if (ar != NULL)
		{
			// Only skip the first char. then can get right path
			ar->readU8();
			
			VfxWString pathStr;
			ar->readWString(pathStr);
			
			VFX_ASSERT(pathStr.getLength() < size);
		
			vfx_sys_wcscpy(path, pathStr.getBuf());
			vfx_sys_wcscpy(VappThemeDltAppIconCntx::s_buff, pathStr.getBuf());
		}
		else
		{
			path[0] = path[1] = 0;
		}

		printMemState();
		VFX_OBJ_CLOSE(ar);
	}
	else
	{
		vfx_sys_wcscpy(path, VappThemeDltAppIconCntx::s_buff);
	}
	
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("apt", SA_stop);
#endif
}


void VappThemeDltAppIconCntx::setActivePath(const VfxWChar *path, VfxS32 size)
{
	MMI_TRACE(TRACE_GROUP_3, VAPP_THEME_APPICON_SET_ACTIVE_PATH);
	
	VappLauncherSettingProvider *provider;

	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	VfxArchive *ar = provider->createArchiveWriter(
									VappLauncherSettingProvider::SETTING_ID_APP_ICON,
									this);
	VFX_ASSERT(ar != NULL);

	ar->writeU8(DLT_THEME_TAG);
	ar->writeWString(VFX_WSTR_MEM(path));

	printMemState();
	VFX_OBJ_CLOSE(ar);

	vfx_sys_wcscpy(VappThemeDltAppIconCntx::s_buff, path);
}


void VappThemeDltAppIconCntx::onLauncherChange(void)
{
	if (!checkActive())
	{
		//deactive();
		// Restore to default appicon
		//setIsDltActive(VFX_FALSE, 0);
		VappThemeDltAppIconCntx::s_buff[0] = VappThemeDltAppIconCntx::s_buff[1] = 0;
	}
}


VfxBool VappThemeDltAppIconCntx::checkActive(void)
{
	VappLauncherSettingProvider *provider;

	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	VfxArchive *ar = provider->createArchiveReader(
									VappLauncherSettingProvider::SETTING_ID_APP_ICON,
									this);

	MMI_TRACE(TRACE_GROUP_3, VAPP_THEME_APPICON_CHECK_ACTIVE, ar);
	
    VfxBool ret = VFX_FALSE;

	printMemState();
	
	if (ar != NULL)
	{
	    VfxWString strPath;
		VfxU8 index = ar->readU8();
		if (index == DLT_THEME_TAG)
		{
			ar->readWString(strPath);
		}

        VFX_OBJ_CLOSE(ar);

		MMI_TRACE(TRACE_GROUP_3, VAPP_THEME_APPICON_CHECK_ACTIVE_DETAIL, index, strPath.getLength());		

        if (strPath.getLength() != 0)
		{
			vfx_sys_wcscpy(VappThemeDltAppIconCntx::s_buff, strPath.getBuf());
			ret = VappThemeDltData::activeDltTheme(this, strPath.getBuf());
		}
		else
		{
			ret = (active(index) >= 0) ? VFX_TRUE : VFX_FALSE;
			VappThemeDltAppIconCntx::s_buff[0] = VappThemeDltAppIconCntx::s_buff[1] = 0;
		}
	}

	if (!ret)
	{
		active(restoreAppicon());
        VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
	    wallpaperInterface->restoreWallpaperEx(VAPP_WALLPAPER_HOME_SCREEN, (ar == NULL ? VFX_FALSE : VFX_TRUE));
	}

    // applyThemeWallpaper();

	return ret;
}


VfxU32 VappThemeDltAppIconCntx::restoreAppicon(void)
{
	VappLauncherSettingProvider *provider;

	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	VfxU32 index = 0;
	
	VappLauncherId launcherId = provider->getDefaultLauncher();

	if (launcherId.getSource() == VAPP_LAUNCHER_SRC_NATIVE)
	{
		index = vapp_theme_appicon_for_curr_launcher(launcherId.getIntType());
	}
	
	setIsDltActive(VFX_FALSE, index);

	return index;
}

void VappThemeDltAppIconCntx::printMemState(void)
{
#ifndef __MTK_TARGET__
	vfx_sys_mem_pool_status_struct output;
	m_selfMem->statistics(output);

	kal_printf("VappThemeDltAppIconCntx:total_size = %d, used = %d, max_used_size=%d\n",
				output.total_size,
				output.used_size,
				output.max_used_size);
#endif /* __MTK_TARGET__ */
}

/***************************************************************************** 
 * Class VappThemeAppIconDltData
 *****************************************************************************/
void VappThemeAppIconDltData::initAppIcon(void)
{
	MMI_TRACE(TRACE_GROUP_3, VAPP_THEME_APPICON_INIT);

	VappThemeDltAppIconCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);

	VappLauncherSettingProvider *provider;
	provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

	provider->m_signalDefaultLauncherChanged.connect(cntx, &VappThemeDltAppIconCntx::onLauncherChange);


	VfxBool bCheckActive = VFX_TRUE;

	#ifndef __LOW_COST_SUPPORT_COMMON__
	if (cntx->isDltActive())
	{
		if (VappThemeDltData::activeDltCache(cntx, cntx->getCachePath()))
		{
			bCheckActive = VFX_FALSE;
		}
	}
	#endif //__LOW_COST_SUPPORT_COMMON__

	if (bCheckActive)
	{
		cntx->checkActive();
	}

}


VfxBool VappThemeAppIconDltData::getTypeStr(VfxWString &typeName)
{
	VfxResId resId;
	
	if (m_waitingJob != 0)
	{
		resId = STR_ID_VAPP_THEME_APPICON_LOADING;
	}
	else
	{
		if (getCount() != 0)
		{
			resId = STR_ID_VAPP_THEME_APPICON_DLT;
		}
		else
		{
			resId = STR_ID_VAPP_THEME_APPICON_NO;
		}		
	}

	typeName.loadFromRes(resId);
	
	return VFX_TRUE;
}


void VappThemeAppIconDltData::genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos)
{
	VappThemeDltData::genSwitchDesc(desc, pos);

	desc.m_changedId = STR_ID_VAPP_THEME_APPICON_CHANGED;
	desc.m_compatibleAskId = STR_ID_VAPP_THEME_APPICON_COMPATIBLE_ASK;
	desc.m_invalidId = STR_ID_VAPP_THEME_APPICON_INVALID;
	desc.m_switchingId = STR_ID_VAPP_THEME_APPICON_SWITCH;
}


VfxU16 VappThemeAppIconDltData::getFiletype(void)
{
	return (VfxU16)FMGR_TYPE_APPICON; 
}


/***************************************************************************** 
 * Class VappThemeAppIconDltSwitchCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeAppIconDltSwitchCui", VappThemeAppIconDltSwitchCui, VappThemeDltSwitchCui);
VappThemeDltCntx *VappThemeAppIconDltSwitchCui::getCntx(void)
{
	return VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx); 
}

VfxBool VappThemeAppIconDltSwitchCui::active(void)
{
    if (VappThemeDltSwitchCui::active())
	{
	    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
	    wallpaperInterface->restoreWallpaperEx(VAPP_WALLPAPER_HOME_SCREEN, VFX_FALSE);

		return VFX_TRUE;
	}

	// retore to default
	VappThemeDltAppIconCntx *cntx = (VappThemeDltAppIconCntx *)getCntx();
	cntx->active(cntx->restoreAppicon());

    return VFX_FALSE;
}

/***************************************************************************** 
 * Helper Function
 *****************************************************************************/
extern "C" 
void vapp_theme_appicon_fmgr_use_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
}


extern "C" 
void vapp_theme_appicon_fmgr_use_handler(
			mmi_menu_id item_id,
			const WCHAR* filepath,
			const srv_fmgr_fileinfo_struct* fileinfo)
{
	VappThemeSwitchDesc desc;
	
	desc.m_changedId = STR_ID_VAPP_THEME_APPICON_CHANGED;
	desc.m_compatibleAskId = STR_ID_VAPP_THEME_APPICON_COMPATIBLE_ASK;
	desc.m_invalidId = STR_ID_VAPP_THEME_APPICON_INVALID;
	desc.m_switchingId = STR_ID_VAPP_THEME_APPICON_SWITCH;
	desc.type = VappThemeData::THEME_TYPE_DLT;

	vapp_theme_fmgr_check_hdlr(
		filepath, 
		VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx),
		VFX_OBJ_CLASS_INFO(VappThemeAppIconDltSwitchCui),
		desc);
}


extern "C"
mmi_ret vapp_theme_appicon_evt_handlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
		case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
			return vapp_theme_fmgr_evt_hdlr(evt, VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx));
			
		default:
			break;
    }
	
    return MMI_RET_OK;
}

