/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_wallpaper_setting_provider.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the setting of wallpaper.
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

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"

extern "C"
{
#include "MMI_common_app_trc.h"
#include "trc/vadp_app_trc.h"
#include "MMI_trc_Int.h"
#include "Unicodexdcl.h"
#include "PhoneSetupResList.h"  // for resource wallpaper
#include "CustVenusThemeRes.h"  // for checking theme wallpaper
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_USB_SUPPORT__)
#include "Mmi_rp_app_usbsrv_def.h"
#endif /* __MMI_USB_SUPPORT__ */
}
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_setting_provider.h"
#if defined(__COSMOS_MMI_PACKAGE__)
#include "vapp_launcher_setting_provider.h"
#include "vapp_screen_lock_setting_provider.h"
#include "Vapp_setting_wallpaper_type_def_gprot.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#endif
#if defined(__MMI_VUI_WALLPAPER_MRE__)
extern "C"
{
#include "AppMgrSrvGprot.h"
#include "MREAppMgrSrvGprot.h"
}
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/

#if !defined(__MTK_TARGET__)
#undef kal_snprintf
#define kal_snprintf snprintfC99
#endif /* !defined(__MTK_TARGET__) */


#if !defined(__LOW_COST_SUPPORT_COMMON__)
/*****************************************************************************
 * Utility function
 *****************************************************************************/
static VfxBool isFileExist(const VfxWString &fileName)
{
    if (fileName == VFX_WSTR_EMPTY)
    {
        return VFX_FALSE;
    }
    FS_HANDLE fsHandle = FS_Open(fileName.getBuf(), FS_READ_ONLY);
    if(fsHandle < 0)
    {
        return VFX_FALSE;
    }
    FS_Close(fsHandle);
    return VFX_TRUE;
}

static VfxBool deleteFile(const VfxWString &fileName)
{
    VfxS32 attribute = FS_GetAttributes(fileName.getBuf());
    if (attribute & FS_ATTR_READ_ONLY)
    {
        FS_SetAttributes(fileName.getBuf(), (U8) (attribute & ~(FS_ATTR_READ_ONLY)));
    }
    if(FS_Delete((const WCHAR*)fileName.getBuf()) < FS_NO_ERROR)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}
#endif   /*__LOW_COST_SUPPORT_COMMON__*/

/*****************************************************************************
 * Setting Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappWallpaperSettingProvider",
    VappWallpaperSettingProvider,
    VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWallpaperSettingProvider);


VappWallpaperSettingProvider::VappWallpaperSettingProvider():
    m_mscMode(VFX_FALSE)
{
    // Do nothing.
}

void VappWallpaperSettingProvider::onInit()
{
    VfxObject::onInit();

#if defined(__MMI_VUI_WALLPAPER_MRE__)
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappWallpaperSettingProvider::eventProc,
        getObjHandle());
#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */

#if (!defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) && defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappWallpaperSettingProvider::usbMassStorageModeHdlr, this);
mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappWallpaperSettingProvider::usbMassStorageModeHdlr, this);
#endif
}


void VappWallpaperSettingProvider::onDeinit()
{
#if defined(__MMI_VUI_WALLPAPER_MRE__)
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,
        VappWallpaperSettingProvider::eventProc,
        getObjHandle());
#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */

#if (!defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) && defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappWallpaperSettingProvider::usbMassStorageModeHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, VappWallpaperSettingProvider::usbMassStorageModeHdlr, this);
#endif
    VfxObject::onDeinit();
}

#if (!defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) && defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
mmi_ret VappWallpaperSettingProvider::usbMassStorageModeHdlr(mmi_event_struct *evt)
{
    VappWallpaperSettingProvider *userWallpaperSetting = (VappWallpaperSettingProvider*)evt->user_data;
    switch (evt->evt_id)
	{
	case EVT_ID_USB_ENTER_MS_MODE:
		userWallpaperSetting->enterMassStorageMode();
		break;
	case EVT_ID_USB_EXIT_MS_MODE:
		userWallpaperSetting->exitMassStorageMode();
		break;
	default:
		break;
	}
    return MMI_RET_OK;
}
void VappWallpaperSettingProvider::enterMassStorageMode()
{
    VfxBool needUpdateWallpaper = setUsbMassStorageMode(VFX_TRUE);
    if(needUpdateWallpaper)
    {
        notifyWallpaperUpdate(VAPP_WALLPAPER_SRC_LAST_ITEM);
    }
}
void VappWallpaperSettingProvider::exitMassStorageMode()
{
    VfxBool needUpdateWallpaper = setUsbMassStorageMode(VFX_FALSE);
    if(needUpdateWallpaper)
    {  
        notifyWallpaperUpdate(VAPP_WALLPAPER_SRC_LAST_ITEM);       
    }
}
#endif /* __MMI_USB_SUPPORT__  && undefied __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__*/

vrt_allocator_handle VappWallpaperSettingProvider::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}

#if defined(__COSMOS_MMI_PACKAGE__) && defined(MMI_WP_THEME_NUM)
static VfxU32 getThemeWallpaperNum()
{
    const VfxU32 validThemeNum = (mmi_res_is_theme_image(IMG_ID_THEME_WALLPAPER_0)) ? MMI_WP_THEME_NUM : 0;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_SETTING_PROVIDER_GET_THEME_WALLPAPER_NUM_D, validThemeNum);
    return validThemeNum;
}
#endif

void VappWallpaperSettingProvider::getFallbackWallpaperId(VappWallpaperId &id, VfxBool dueToError)
{
    // restore to theme wallpaper as default
#if defined(__COSMOS_MMI_PACKAGE__) && defined(MMI_WP_THEME_NUM)

    // in Cosmos Slim, theme wallpaper may fail to load (even if they exist),
    // so do not restore to theme wallpaper when caused by error.
    VfxBool excludeTheme = VFX_FALSE;
    #if defined(__LOW_COST_SUPPORT_COMMON__)
    excludeTheme = dueToError;
    #endif
    
    id.assignWith(VAPP_WALLPAPER_FACTORY_IMAGE,
                  (getThemeWallpaperNum() && !excludeTheme) ? IMG_ID_WP_THEME_START : IMG_ID_PHNSET_WP_START);
    
#else
    id.assignWith(VAPP_WALLPAPER_FACTORY_IMAGE,
                  IMG_ID_PHNSET_WP_START);
#endif
}

VfxBool VappWallpaperSettingProvider::setUsbMassStorageMode(VfxBool isMSCMode)
{
    VfxBool ret = VFX_FALSE;
    if(isMSCMode != m_mscMode)
    {
        // detect if wallpaper needs to change
        for(VfxU32 i = VAPP_WALLPAPER_SRC_HOMESCREEN; i < VAPP_WALLPAPER_SRC_LAST_ITEM; ++i)
        {
            VappWallpaperId wid = getDefaultWallpaperInternal((VappWallpaperSrcEnum)i, this);
            const VfxBool isFileBased = VappWallpaperKit::isFileBasedWallpaper(wid);
            if(isFileBased)
            {
                ret = VFX_TRUE;
                break;
            }
        }
    }
    m_mscMode = isMSCMode;
    return ret;
}

VappWallpaperId VappWallpaperSettingProvider::getDefaultWallpaperInternal(
    const VappWallpaperSrcEnum src,
    VfxObject *parentObj) const
{
    VfxWString archiveFilename;
    
#ifndef __COSMOS_MMI_PACKAGE__
    getSystemArchiveFilename(src, archiveFilename);
#endif /*pluto*/
    VfxArchive *ar = createArchive(
                        src,
                        archiveFilename,
                        VappArchiveFileSource::SOURCE_MODE_READ,
                        parentObj);

    VappWallpaperId id;
    if (!ar)
    {
        // revert to default setting
        
        // in Cosmos Slim, we should not use Theme wallpaper in lock screen.
        VfxBool preventLoadingTheme = VFX_FALSE;
        #if defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__)
        if(VAPP_WALLPAPER_SRC_LOCK == src)
        {
            preventLoadingTheme = VFX_TRUE;
        }
        #endif
        
        getFallbackWallpaperId(id, preventLoadingTheme);
    }
    else
    {
        id.decodeFromArchive(ar);
        VFX_OBJ_CLOSE(ar);
    }

    return id;
}

VappWallpaperId VappWallpaperSettingProvider::getDefaultWallpaper(
    const VappWallpaperSrcEnum src,
    VfxObject *parentObj) const
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_SETTING_GET_DEFAULT_WALLPAPER);

    VappWallpaperId id = getDefaultWallpaperInternal(src, parentObj);

    #if defined(__MMI_VUI_WALLPAPER_MRE__)
    // Special handling for MRE wallpapers, they may be uninstalled.
    if(VAPP_WALLPAPER_FACTORY_MRE == id.getSource() && VappWallpaperId::TYPE_KIND_STRING == id.getTypeKind())
    {
        // Once installed, treat as resource ready.
        // Do not check for actualy MRE wallpaper validity,
        // because loading error is handled by MRE wallpaper itself.
        if(MMI_FALSE == srv_mre_appmgr_is_app_installed((mmi_app_package_char*)id.getStringType()))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_SETTING_PROVIDER_FALLBACK_WALLPAPER_DUE_TO_MRE_WALLPAPER_UNINSTALLED);
            // use fallback wallpaper if MRE wallpaper is already uninstalled.
            getFallbackWallpaperId(id, VFX_TRUE);
        }
    }
    #endif
    
    // if under USB Mass Storage mode,
    // use fallback wallpaper instead of file-based wallpaper
    if(m_mscMode)
    {
        const VfxBool isFileBased = VappWallpaperKit::isFileBasedWallpaper(id);
        if(isFileBased)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_SETTING_PROVIDER_FALLBACK_WALLPAPER_DUE_TO_MSC_MODE);
            getFallbackWallpaperId(id, VFX_TRUE);
        }
    }
    return id;
}


void VappWallpaperSettingProvider::setDefaultWallpaper(
    const VappWallpaperSrcEnum src,
    const VappWallpaperId &id,
    VfxObject *parentObj) const
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_SETTING_SET_DEFAULT_WALLPAPER_SRC_D, src);

#if !defined(__LOW_COST_SUPPORT_COMMON__)
    // Remove previous wallpaper
    // If the wallpaper is image wallpaper, 
    // since it is a cached image
    do
    {
        VappWallpaperId prevId = getDefaultWallpaper(src, parentObj);

        if(prevId == id)
            break;

        if(VAPP_WALLPAPER_FACTORY_IMAGE != prevId.getSource())
            break;
        
        if(VappWallpaperId::TYPE_KIND_WSTRING != prevId.getTypeKind())
            break;

        const VfxWString prevPath = VFX_WSTR_MEM(prevId.getWStringType());

        // make sure it is a cached files
        VfxChar drv = (VfxChar)prevPath.getBuf()[0];
        if(drv != VAPP_WALLPAPER_ARCHIVE_DRIVE &&
           drv != SRV_FMGR_SYSTEM_DRV)
        {
            break;
        }

        // make sure previous file is a different file
        if(!isFileExist(prevPath))
            break;

        // delete previous cache file
        deleteFile(prevPath);
    
    }while(0);
#endif    
    
    //
    // Save the default screen lock to the system archive.
    //
    VfxWString archiveFilename;

#ifndef __COSMOS_MMI_PACKAGE__   
    getSystemArchiveFilename(src, archiveFilename);
#endif   /*pluto*/

    VfxArchive *ar = createArchive(
                        src,
                        archiveFilename,
                        VappArchiveFileSource::SOURCE_MODE_WRITE,
                        parentObj);

    VFX_ASSERT(ar);

    id.encodeToArchive(ar);

    VFX_OBJ_CLOSE(ar);

    //
    // TODO: Notify that the default screen lock is changed.
    //
}

#ifndef __COSMOS_MMI_PACKAGE__
VfxS32 VappWallpaperSettingProvider::formatArchiveFilename(
    const VappWallpaperId &id,
    VfxId archiveId,
    kal_char *buf,
    VfxS32 size) const
{
    VfxS32 ret = 0;

    switch (id.getTypeKind())
    {
        case VappWallpaperId::TYPE_KIND_INTEGER:
            ret = 1 + kal_snprintf(
                        buf,
                        size,
                        "%c:\\%s\\%d\\%d\\%08lx.%s",
                        VAPP_WALLPAPER_ARCHIVE_DRIVE,
                        VAPP_WALLPAPER_ARCHIVE_PATH,
                        id.getSource(),
                        id.getIntType(),
                        archiveId,
                        VAPP_WALLPAPER_ARCHIVE_FILE_EXT);
            break;

        case VappWallpaperId::TYPE_KIND_STRING:
            ret = 1 + kal_snprintf(
                        buf,
                        size,
                        "%c:\\%s\\%d\\%s\\%08lx.%s",
                        VAPP_WALLPAPER_ARCHIVE_DRIVE,
                        VAPP_WALLPAPER_ARCHIVE_PATH,
                        id.getSource(),
                        id.getStringType(),
                        archiveId,
                        VAPP_WALLPAPER_ARCHIVE_FILE_EXT);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }

    return ret;
}


void VappWallpaperSettingProvider::getArchiveFilename(
    const VappWallpaperId &id,
    VfxId archiveId,
    VfxWString &archiveFilename) const
{
    //
    // Determine buffer size for the filename, including NULL-terminated char.
    //
    VfxS32 size = formatArchiveFilename(id, archiveId, NULL, 0);

    //
    // Output the filename.
    //
    kal_char *name;

    VFX_SYS_ALLOC_MEM(name, size * sizeof(kal_char));

    formatArchiveFilename(id, archiveId, name, size);

    //
    // Convert the char string to a wide-char string.
    //
    convertAscii2Ucs2(archiveFilename, name);

    VFX_SYS_FREE_MEM(name);
}


VfxS32 VappWallpaperSettingProvider::formatSystemArchiveFilename(
    const VappWallpaperSrcEnum src,
    kal_char *buf,
    VfxS32 size) const
{
    return 1 + kal_snprintf(
                buf,
                size,
                "%c:\\%s\\%s_%s.%s",
                VAPP_WALLPAPER_ARCHIVE_DRIVE,
                VAPP_WALLPAPER_ARCHIVE_PATH,
                VAPP_WALLPAPER_SYS_ARCHIVE_FILE,
                (src == VAPP_WALLPAPER_SRC_HOMESCREEN) ? "hs" : "lock",
                VAPP_WALLPAPER_ARCHIVE_FILE_EXT);
}


void VappWallpaperSettingProvider::getSystemArchiveFilename(
    const VappWallpaperSrcEnum src,
    VfxWString &archiveFilename) const
{
    //
    // Determine buffer size for the filename, including NULL-terminated char.
    //
    const VfxS32 size = formatSystemArchiveFilename(src, NULL, 0);

    //
    // Output the filename.
    //
    kal_char *name;

    VFX_SYS_ALLOC_MEM(name, size * sizeof(kal_char));

    formatSystemArchiveFilename(src, name, size);

    //
    // Convert the char string to a wide-char string.
    //
    convertAscii2Ucs2(archiveFilename, name);

    VFX_SYS_FREE_MEM(name);
}

void VappWallpaperSettingProvider::convertAscii2Ucs2(
    VfxWString &ucs2,
    const VfxChar *ascii) const
{
    VfxU32 size = vfx_sys_strlen(ascii) + 1; // 1 for null-terminated char

    VfxWChar *wideName;

    VFX_SYS_ALLOC_MEM(wideName, size * sizeof(VfxWChar));

    mmi_asc_n_to_wcs((WCHAR *)wideName, (CHAR *)ascii, size - 1);

    ucs2.loadFromMem(wideName);

    VFX_SYS_FREE_MEM(wideName);
}
#endif   /*pluto*/

template<class Provider> VfxArchive* createWallpaperSettingArchive(VappArchiveFileSource::SourceModeEnum mode, Provider *p, VfxObject *parentObj)
{
    VfxArchive *ar = NULL;
    if(VappArchiveFileSource::SOURCE_MODE_WRITE == mode)
    {
        ar = p->createArchiveWriter(
                        Provider::SETTING_ID_WALLPAPER,
                        parentObj);
    }
    else if(VappArchiveFileSource::SOURCE_MODE_READ == mode)
    {
        ar = p->createArchiveReader(
                        Provider::SETTING_ID_WALLPAPER,
                        parentObj);
    }
    return ar;
}

VfxArchive *VappWallpaperSettingProvider::createArchive(
    const VappWallpaperSrcEnum src,
    const VfxWString &archiveFilename,
    VappArchiveFileSource::SourceModeEnum mode,
    VfxObject *parentObj) const
{
#ifdef __COSMOS_MMI_PACKAGE__
    // COSMOS 2.0, use different setting for differnt launcher and lock screen.
    VfxArchive *ar = NULL;
    switch(src)
    {
        case VAPP_WALLPAPER_SRC_LOCK:
        {
            VappScreenLockSettingProvider *provider;
            provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);
            ar = createWallpaperSettingArchive(mode, provider, parentObj);
            break;
        }
        case VAPP_WALLPAPER_SRC_HOMESCREEN:
        {
            VappLauncherSettingProvider *provider;
            provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);
            ar = createWallpaperSettingArchive(mode, provider, parentObj);
            break;
        }        
    }
    return ar;

#else
    // Pluto, use single setting
    VfxArchive *ar;
    VappArchiveFileSource *arSource;

    VFX_OBJ_CREATE(ar, VfxArchive, parentObj);
    VFX_OBJ_CREATE(arSource, VappArchiveFileSource, ar);

    VfxBool ret = arSource->open(archiveFilename.getBuf(), mode);
    if (!ret)
    {
        VFX_OBJ_CLOSE(ar);
        return NULL;
    }

    ar->setSource(arSource);

    return ar;
#endif
}





mmi_ret VappWallpaperSettingProvider::eventProc(mmi_event_struct *evt)
{
#if defined(__MMI_VUI_WALLPAPER_MRE__)
    VappWallpaperSettingProvider *provider;
    provider = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    if(provider && evt)
    {
        switch (evt->evt_id)
        {
            case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
            {
                srv_appmgr_update_event_struct *p = (srv_appmgr_update_event_struct *)evt;
                provider->handleUninstall(p->app_name);
                break;
            }
            default:
            {
                break;
            }
        }
    }
#endif
    return MMI_RET_OK;
}


void VappWallpaperSettingProvider::handleUninstall(const VfxChar *appName)
{
#if defined(__MMI_VUI_WALLPAPER_MRE__)
    const VappWallpaperId uninstallWid(VAPP_WALLPAPER_FACTORY_MRE, appName);
    for(VfxU32 i = VAPP_WALLPAPER_SRC_HOMESCREEN; i < VAPP_WALLPAPER_SRC_LAST_ITEM; ++i)
    {
        VappWallpaperSrcEnum src = (VappWallpaperSrcEnum)i;
        VappWallpaperId defaultWid = getDefaultWallpaperInternal(src, this);
        if(defaultWid == uninstallWid)
        {
            getFallbackWallpaperId(defaultWid, VFX_TRUE);
            setDefaultWallpaper(src, defaultWid, this);
            notifyWallpaperUpdate(src);
        }
    }
#endif
}

void VappWallpaperSettingProvider::notifyWallpaperUpdate(VappWallpaperSrcEnum src)
{
#ifdef __COSMOS_MMI_PACKAGE__
    // only Cosmos has notify mechanism.
    // Pluto uses screen enter/exit instead.
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->sendWallpaperUpdateSignal((VappWallpaperType)src);
#endif
}
