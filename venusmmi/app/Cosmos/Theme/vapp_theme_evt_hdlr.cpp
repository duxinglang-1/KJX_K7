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
 *  vapp_theme_evt_hdlr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Theme reactive for slim project
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#include "MMIDataType.h"
#include "CustVenusThemeRes.h"
#include "GlobalResDef.h"

extern "C"
{
#include "FileMgrSrvGProt.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_scenario_gprot.h"
#include "nvram_common_defs.h"
#include "UsbSrvGprot.h"
}

#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vapp_theme_def.h"

#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_wallpaper_setting_provider.h"
#include "vapp_theme_dlt.h"
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
#include "vapp_theme_appicon_dlt.h"
#endif
#include "vapp_theme_evt_hdlr.h"

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
static mmi_ret vapp_theme_post_launch(mmi_event_struct *evt)
{
	VFX_ASSERT(evt->user_data != NULL);
	
	mmi_id cui_id = VfxAppLauncher::launch(
										VCUI_THEME_SWITCH,
										VFX_OBJ_CLASS_INFO(VappThemeAndAppIconSwitchCui),
										GRP_ID_ROOT,
										evt->user_data,
										sizeof(VappThemeSwitchDesc));
	
	//VappThemeSwitchDesc *desc = (VappThemeSwitchDesc *)evt->user_data;
	//VFX_SYS_DELETE(desc);
	
	return MMI_RET_OK;

}

mmi_ret VappThemeDevEvtHandler(mmi_event_struct *evt)
{
	VfxBool isRestore = VFX_FALSE;
	// Reset to default theme & AppIcon
	switch(evt->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
		case EVT_ID_USB_ENTER_MS_MODE:
			if (!VappThemeAndAppIconSwitchCui::isNeedReset())
			{
				return MMI_RET_OK;
			}
			break;

		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
		case EVT_ID_USB_EXIT_MS_MODE:
			if (!VappThemeAndAppIconSwitchCui::isNeedRestore())
			{
				return MMI_RET_OK;
			}
			isRestore = VFX_TRUE;
			break;

		default:
			return MMI_RET_OK;
	}


	static VappThemeSwitchDesc s_desc;

	s_desc.initRes();
	s_desc.isNeedConfirm = VFX_FALSE;
	s_desc.isRestore = isRestore;

	mmi_event_struct launchEvt;
	
	MMI_FRM_INIT_EVENT(&launchEvt, 0);

	MMI_FRM_POST_EVENT(&launchEvt, vapp_theme_post_launch, &s_desc);

	return MMI_RET_OK;
}


mmi_id vapp_theme_evt_init(mmi_event_struct *evt)
{
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappThemeDevEvtHandler, NULL);
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappThemeDevEvtHandler, NULL);
	
	mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappThemeDevEvtHandler, NULL);
	mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappThemeDevEvtHandler, NULL);
	
	return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VappThemeAndAppIconSwitchCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeAndAppIconSwitchCui", VappThemeAndAppIconSwitchCui, VappThemeDltSwitchCui);
VfxBool VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_TOTAL] = {VFX_FALSE, VFX_FALSE};
VfxBool VappThemeAndAppIconSwitchCui::isNeedReset(void)
{
	VappThemeDltCntx *obj;
	VfxWChar *buffer;
	VfxChar drvLetter[2];
	VfxBool bRet = VFX_FALSE;
	obj = VFX_OBJ_GET_INSTANCE(VappThemeDltCntx);
	
	if (obj != NULL && obj->isDltActive())
	{
		VFX_SYS_ALLOC_MEM(buffer, NVRAM_EF_DLT_THEME_SIZE);
		buffer[0] = buffer[1] = 0;

		obj->getActivePath(buffer, NVRAM_EF_DLT_THEME_SIZE);
		if (vfx_sys_wcslen(buffer) != 0)
		{
			mmi_wcs_n_to_asc(drvLetter, buffer, 2);
			bRet = (SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drvLetter[0])) ? VFX_TRUE : VFX_FALSE;
		}
		VFX_SYS_FREE_MEM(buffer);
		return bRet;
	}
	
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	obj = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
	if (obj != NULL && obj->isDltActive())
	{
		VFX_SYS_ALLOC_MEM(buffer, NVRAM_EF_DLT_THEME_SIZE);
		buffer[0] = buffer[1] = 0;
		
		obj->getActivePath(buffer, NVRAM_EF_DLT_THEME_SIZE);
		if (vfx_sys_wcslen(buffer) != 0)
		{
			mmi_wcs_n_to_asc(drvLetter, buffer, 2);
		#ifdef __MMI_USB_SUPPORT__
			if (srv_usb_is_in_mass_storage_mode())
			{
				bRet = VFX_TRUE;
			}
			else
		#endif //__MMI_USB_SUPPORT__
			{
				bRet = (SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drvLetter[0])) ? VFX_TRUE : VFX_FALSE;
			}
		}
		VFX_SYS_FREE_MEM(buffer);

		return bRet;
	}
#endif //__MMI_VUI_DOWNLOADABLE_APP_ICON__

	return VFX_FALSE;
}

VfxBool VappThemeAndAppIconSwitchCui::isNeedRestore(void)
{
	VfxBool bRet = VFX_FALSE;
	VappThemeDltCntx *obj;
	VfxWChar *buffer;
	
	if (VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_THEME])
	{
		obj = VFX_OBJ_GET_INSTANCE(VappThemeDltCntx);
		VFX_SYS_ALLOC_MEM(buffer, NVRAM_EF_DLT_THEME_SIZE);
		if (VappThemeDltData::getActiveThemePath(obj, buffer, NVRAM_EF_DLT_THEME_SIZE))
		{			
			bRet = VFX_TRUE;
		}
		VFX_SYS_FREE_MEM(buffer);
		return bRet;
	}

#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	if (VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_APPICON])
	{
		obj = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
		VFX_SYS_ALLOC_MEM(buffer, NVRAM_EF_DLT_THEME_SIZE);
		if (VappThemeDltData::getActiveThemePath(obj, buffer, NVRAM_EF_DLT_THEME_SIZE))
		{			
			bRet = VFX_TRUE;
		}
		VFX_SYS_FREE_MEM(buffer);
		return bRet;
	}

#endif //__MMI_VUI_DOWNLOADABLE_APP_ICON__

	return VFX_FALSE;
}

VfxBool VappThemeAndAppIconSwitchCui::active(void)
{
	if (!m_switchDesc.isRestore)
	{
		return reset();
	}
	
	return restore();
}

VappThemeDltCntx *VappThemeAndAppIconSwitchCui::getCntx()
{
	return m_cntx;
}

VfxBool VappThemeAndAppIconSwitchCui::reset(void)
{
	VappThemeCntx *objTheme = VFX_OBJ_GET_INSTANCE(VappThemeCntx);

	if (objTheme != NULL && objTheme->isDltActive())
	{
		objTheme->setIsDltActive(VFX_FALSE, 1); // slim project hasn't system appicon
		objTheme->active(1);

		VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_THEME] = VFX_TRUE;
	}
	
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	VappThemeDltAppIconCntx *objAppIcon = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);

	if (objAppIcon != NULL && objAppIcon->isDltActive())
	{
		objAppIcon->active(objAppIcon->restoreAppicon());
		
        // MAUI_03218844: [MRE_LWP_001_011]MRE wallpaper do not resume after plug in memory card
        // MRE wallpaper is special case,
        // according to MRE spec, don't restore wallpaper if it is MRE
        VappWallpaperSettingProvider *wp = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
        VappWallpaperId wid = wp->getDefaultWallpaper(VAPP_WALLPAPER_SRC_HOMESCREEN, this);
        if(wid.getSource() != VAPP_WALLPAPER_FACTORY_MRE)
        {
            VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
            // don't call restoreWallpaper() here, since both USB Mass Storage and Card Remove
            // calls this reset() function. If we call restoreWallpaper() then user's setting will be lost.
            // So we simply notify Launcher to update wallpaper,
            // and VappWallpaperSettingProvider should determine if current wallpaper is usable or not.
            wallpaperInterface->sendWallpaperUpdateSignal(VAPP_WALLPAPER_HOME_SCREEN);
        }
        
        
		VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_APPICON] = VFX_TRUE;
	}
#endif // __MMI_VUI_DOWNLOADABLE_APP_ICON__

	return VFX_TRUE;
}


VfxBool VappThemeAndAppIconSwitchCui::restore(void)
{
	VfxBool ret = VFX_FALSE;

	VfxWChar *buffer;

	VFX_ALLOC_MEM(buffer, NVRAM_EF_DLT_THEME_SIZE, this);
	
	if (VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_THEME])
	{
		m_cntx  = VFX_OBJ_GET_INSTANCE(VappThemeDltCntx);

		if (VappThemeDltData::getActiveThemePath(m_cntx, buffer, NVRAM_EF_DLT_THEME_SIZE))
		{
			ret = VappThemeDltData::activeDltTheme(getCntx(), buffer);
		}

		VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_THEME] = VFX_FALSE;
	}

#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	if (VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_APPICON])
	{
		m_cntx  = VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
		
		if (VappThemeDltData::getActiveThemePath(m_cntx, buffer, NVRAM_EF_DLT_THEME_SIZE))
		{
			ret = VappThemeDltData::activeDltTheme(getCntx(), buffer);
            VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    	    wallpaperInterface->restoreWallpaperEx(VAPP_WALLPAPER_HOME_SCREEN, VFX_TRUE);
		}

		VappThemeAndAppIconSwitchCui::s_isNeedRestore[VAPP_THEME_RESTORE_APPICON] = VFX_FALSE;
	}
#endif //__MMI_VUI_DOWNLOADABLE_APP_ICON__

	VFX_FREE_MEM(buffer);

	return ret;
}

