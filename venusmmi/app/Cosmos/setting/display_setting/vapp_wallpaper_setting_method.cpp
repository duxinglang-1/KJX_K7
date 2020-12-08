/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_wallpaper_setting_method.cpp
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
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_wallpaper_setting_method.h"
#include "vcui_gallery_gprot.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_wallpaper_setting_provider.h"
#include "vapp_wallpaper_content_provider.h"
extern "C"
{
    #include "Nvram_common_defs.h"
    #include "PhoneSetupResList.h"
    #include "FileMgrSrvGprot.h"
    #include "mmi_rp_file_type_def.h"
    #include "Drm_gprot.h"
    #ifdef __MMI_USB_SUPPORT__
    #include "Mmi_rp_app_usbsrv_def.h"
    #endif /* __MMI_USB_SUPPORT__ */
    #include "mmi_rp_vapp_setting_def.h"
}


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
VfxS32 support_type[] = 
{
    FMGR_TYPE_BMP,
    FMGR_TYPE_WBMP,
    FMGR_TYPE_WBM,
    FMGR_TYPE_GIF,
#ifdef JPG_DECODE        
    FMGR_TYPE_JPG,
    FMGR_TYPE_JPEG,
#endif         
#if defined(GDI_USING_PNG)
    FMGR_TYPE_PNG,
#endif
#if defined(__DRM_V02__)
    FMGR_TYPE_ODF,
#endif
#if defined(SVG_SUPPORT) && !defined(__MMI_VUI_ENGINE__)
    FMGR_TYPE_SVG,
#endif
#ifdef M3D_MMI_SUPPORT
    FMGR_TYPE_M3D,
#endif 
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    FMGR_TYPE_MAV,
#endif

    //supported videos;
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
#ifdef MP4_DECODE
    FMGR_TYPE_3GP,
    FMGR_TYPE_MP4,
    FMGR_TYPE_MPG,
    FMGR_TYPE_3G2,
#endif /* MP4_DECODE */
#ifdef MJPG_DECODE
    FMGR_TYPE_AVI,
#endif /* MJPG_DECODE */
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */
    /* End of file type */
    FMGR_TYPE_UNKNOWN,
};

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappWallpaperSettingInterface
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWallpaperSettingInterface);

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
const VfxU32 g_memSize = 4 * 1024;
static VfxU32 g_vappWPSettingInterfaceMemPool[g_memSize / sizeof(VfxU32)];
#endif


VappWallpaperSettingInterface::VappWallpaperSettingInterface()
{
}

void VappWallpaperSettingInterface::onInit()
{
    #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool((VfxU8 *)g_vappWPSettingInterfaceMemPool, g_memSize);
    #endif
    VfxObject::onInit();
    
    for (VfxS32 i=0; i<VAPP_WALLPAPER_TYPE_END; ++i)
    {
        m_wallpaperSettingObj[i] = NULL;
    }
    m_UserImageCache = NULL;
    
    createWallpaperObj();    
}

void VappWallpaperSettingInterface::onDeinit()
{
    #ifndef __LOW_COST_SUPPORT_COMMON__
    if(m_UserImageCache)
    {
        VFX_OBJ_CLOSE(m_UserImageCache);
    }
    #endif
    for (VfxS32 i = 0; i < VAPP_WALLPAPER_TYPE_END; ++i)
    {
        VappWpSettingStrategyBase *obj = m_wallpaperSettingObj[i];
        while(obj)
        {
            m_wallpaperSettingObj[i] = obj->m_next;
            VFX_OBJ_CLOSE(obj);
            obj = m_wallpaperSettingObj[i];
        }
    }
    
    #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    vfx_sys_mem_pool_status_struct output;
    m_context->statistics(output);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[VappWallpaperSettingInterface] total[%d], used[%d], max[%d].", output.total_size, output.used_size, output.max_used_size);
    VFX_OBJ_CLOSE(m_context);
    #endif

    VfxObject::onDeinit();
}

void VappWallpaperSettingInterface::createWallpaperObj()
{

#ifndef __LOW_COST_SUPPORT_COMMON__
    VFX_OBJ_CREATE(m_UserImageCache, VappWpSettingUserWallpaperSetting, this);//for cache user image
    m_UserImageCache->initSetting();
#endif

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VappWpSettingStrategyBase *obj;
    VappWpSettingWallpaperTypeSetting   *resTypeSetting;
    VappWpSettingVideoWallpaperSetting  *userVideoFileSetting;
    VappWpSettingFileDirectSetting      *userPwrOnOffFileSetting;  

    // Create power on screen setting chain. Typeset->video->fileDirect.
    VFX_OBJ_CREATE(resTypeSetting, VappWpSettingWallpaperTypeSetting, this);
    resTypeSetting->setNvramData(NVRAM_SETTING_PWR_ON_VIDEO_RES_TYPE);
    resTypeSetting->initSetting();
    m_wallpaperSettingObj[VAPP_VIDEO_PWR_ON_SCREEN] = resTypeSetting;
    obj = resTypeSetting;

    VFX_OBJ_CREATE(userVideoFileSetting, VappWpSettingVideoWallpaperSetting, this);
    userVideoFileSetting->setNvramData(NVRAM_SETTING_PWR_ON_VIDEO);
    userVideoFileSetting->initSetting();
    obj->addNext(userVideoFileSetting);
    obj = userVideoFileSetting;

    VFX_OBJ_CREATE(userPwrOnOffFileSetting, VappWpSettingFileDirectSetting, this);
    userPwrOnOffFileSetting->setNvramData(NVRAM_EF_WALLPAPER_FILENAME_LID, 3);
    userPwrOnOffFileSetting->setSettingChain(m_wallpaperSettingObj[VAPP_VIDEO_PWR_ON_SCREEN]);
    userPwrOnOffFileSetting->setSettingType(VAPP_VIDEO_PWR_ON_SCREEN);
    obj->addNext(userPwrOnOffFileSetting);    
    userPwrOnOffFileSetting->initSetting();

    // Create power off screen setting chain.  Typeset->video->fileDirect.
    VFX_OBJ_CREATE(resTypeSetting, VappWpSettingWallpaperTypeSetting, this);
    resTypeSetting->setNvramData(NVRAM_SETTING_PWR_OFF_VIDEO_RES_TYPE);
    resTypeSetting->initSetting();
    m_wallpaperSettingObj[VAPP_VIDEO_PWR_OFF_SCREEN] = resTypeSetting;
    obj = resTypeSetting;

    VFX_OBJ_CREATE(userVideoFileSetting, VappWpSettingVideoWallpaperSetting, this);
    userVideoFileSetting->setNvramData(NVRAM_SETTING_PWR_OFF_VIDEO);
    userVideoFileSetting->initSetting();
    obj->addNext(userVideoFileSetting);
    obj = userVideoFileSetting;

    VFX_OBJ_CREATE(userPwrOnOffFileSetting, VappWpSettingFileDirectSetting, this);
    userPwrOnOffFileSetting->setNvramData(NVRAM_EF_WALLPAPER_FILENAME_LID, 4);
    userPwrOnOffFileSetting->setSettingChain(m_wallpaperSettingObj[VAPP_VIDEO_PWR_OFF_SCREEN]);
    userPwrOnOffFileSetting->setSettingType(VAPP_VIDEO_PWR_OFF_SCREEN);
    obj->addNext(userPwrOnOffFileSetting);    
    userPwrOnOffFileSetting->initSetting();
#endif  /*__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__*/
   
}
    
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
VfxU16 VappWallpaperSettingInterface::getVideoResId(VappWallpaperType type) 
{
    // TODO: The video id is not prepared.
    VfxU16 id = 0;    
    m_wallpaperSettingObj[type]->getWallpaperId(VAPP_WALLPAPER_VIDEO_WALLPAPER, &id);
    return id;
} 
VfxWString VappWallpaperSettingInterface::getWallpaperFile(VappWallpaperType type) 
{
    VfxWString file = VFX_WSTR_EMPTY;
    m_wallpaperSettingObj[type]->getWallpaperFile(VAPP_WALLPAPER_USER_FILE, &file);
    return file;
}

VappWpResType VappWallpaperSettingInterface::getWallpaperResType(VappWallpaperType type) 
{
    VappWpResType resType;
    m_wallpaperSettingObj[type]->getWallpaperResType(&resType);
    return resType;
}

VappWpSetErrorCode VappWallpaperSettingInterface::checkWallpaper(VappWallpaperType type) 
{
    VappWpResType resType;
    m_wallpaperSettingObj[type]->getWallpaperResType(&resType);
    
    VappWpSetErrorCode errorCode = VAPP_WALLPAPER_SETTING_NO_ERROR;
    m_wallpaperSettingObj[type]->checkWallpaper(resType, &errorCode);
    return errorCode;
}

VappWpSetErrorCode VappWallpaperSettingInterface::setWallpaperId(VappWallpaperType type, VappWpResType resType, VfxU16 wallpaperId)
{
    VappWpSetErrorCode errorCode = VAPP_WALLPAPER_SETTING_NO_ERROR;
    m_wallpaperSettingObj[type]->setWallpaperId(resType, wallpaperId, &errorCode);
    if (errorCode == VAPP_WALLPAPER_SETTING_NO_ERROR)
    {

        m_wallpaperSettingObj[type]->setWallpaperResType(resType);
        
    }
    return errorCode;
}

VappWpSetErrorCode VappWallpaperSettingInterface::setWallpaperFile(VappWallpaperType type, const VfxWString &fileName)
{
    VappWpSetErrorCode errorCode = VAPP_WALLPAPER_SETTING_NO_ERROR;
    m_settingType = type;
    if (type == VAPP_VIDEO_PWR_ON_SCREEN || type == VAPP_VIDEO_PWR_OFF_SCREEN)
    {
        m_wallpaperSettingObj[type]->setWallpaperFile(VAPP_WALLPAPER_USER_FILE, fileName, &errorCode);
        if (errorCode == VAPP_WALLPAPER_SETTING_NO_ERROR)
        {
            m_wallpaperSettingObj[type]->setWallpaperResType(VAPP_WALLPAPER_USER_FILE);     
        }  
    }
    #if !defined(__LOW_COST_SUPPORT_COMMON__)
    else if (type == VAPP_WALLPAPER_HOME_SCREEN || type == VAPP_WALLPAPER_LOCK_SCREEN)
    {
        m_UserImageCache->setWallpaperCacheFile(type, fileName, &errorCode);
    }
    #endif
    return errorCode;
}
#endif  /*__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__*/

#if !defined(__LOW_COST_SUPPORT_COMMON__)
VfxResId VappWallpaperSettingInterface::getErrorString(VappWpSetErrorCode errorCode)
{
    switch (errorCode)
    {
    case VAPP_WALLPAPER_SETTING_NO_ERROR:
        return STR_GLOBAL_DONE;

    case VAPP_WALLPAPER_SETTING_DISK_SIZE_NOT_ENOUGH:
    case VAPP_WALLPAPER_SETTING_FILE_LIMIT_CHECK_FAIL:
        return STR_ID_VAPP_SETTING_WALLPAPER_FILE_TOO_LARGE;

    case VAPP_WALLPAPER_SETTING_COPY_FILE_FAIL:
        return STR_GLOBAL_FAILED_TO_SAVE;

    case VAPP_WALLPAPER_SETTING_DRM_CHECK_FAIL:
        return STR_GLOBAL_DRM_PROHIBITED;

    case VAPP_WALLPAPER_SETTING_FILE_IS_NOT_EXSIT:
        return STR_GLOBAL_FILE_NOT_FOUND;

    case VAPP_WALLPAPER_SETTING_UNSUPPORT_FORMAT:
    default:
	return STR_GLOBAL_UNSUPPORTED_FORMAT;
    }
}

#endif  /*__LOW_COST_SUPPORT_COMMON__*/


void VappWallpaperSettingInterface::restoreWallpaper(VappWallpaperType type)
{
    // Client call restoreWallpaper() is caused by error.
    restoreWallpaperEx(type, VFX_TRUE, VFX_TRUE);
}

void VappWallpaperSettingInterface::restoreWallpaperEx(VappWallpaperType type, VfxBool sendRestoreSignal, VfxBool dueToError)
{
    if(VAPP_VIDEO_PWR_ON_SCREEN == type || VAPP_VIDEO_PWR_OFF_SCREEN == type)
    {

        m_wallpaperSettingObj[type]->restoreWallpaper();
    }
    // restore wallpaper setting factory
    if(VAPP_WALLPAPER_HOME_SCREEN == type || VAPP_WALLPAPER_LOCK_SCREEN == type)
    {
        VappWallpaperSettingProvider *provider = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
        VappWallpaperId wid;
        provider->getFallbackWallpaperId(wid, dueToError);
        provider->setDefaultWallpaper(
                VAPP_WALLPAPER_HOME_SCREEN == type ? VAPP_WALLPAPER_SRC_HOMESCREEN : VAPP_WALLPAPER_SRC_LOCK,
                wid,
                provider);
    }

    if(sendRestoreSignal)
    {
        sendWallpaperUpdateSignal(type);
    }
}

void VappWallpaperSettingInterface::sendWallpaperUpdateSignal(VappWallpaperType type)
{
    m_signalWallpaperIsUpdated.postEmit();	
}

/***************************************************************************** 
 * VappWpSettingWallpaperTypeSetting
 *****************************************************************************/
void VappWpSettingWallpaperTypeSetting::getWallpaperResType(VappWpResType *type) 
{
    // perform operation
    *type = (VappWpResType)m_wallpaperResType;
    
    VappWpSettingStrategyBase::getWallpaperResType(type);
}

void VappWpSettingWallpaperTypeSetting::setWallpaperResType(VappWpResType type, const VfxWString& filename) 
{
    // perform operation
    m_wallpaperResType = type;

    VfxS16 nvramError;
    WriteValue(m_nvramCacheId, &m_wallpaperResType, DS_BYTE, &nvramError);

    //VappWpSettingStrategyBase::setWallpaperResType(type, filename);
}

void VappWpSettingWallpaperTypeSetting::initSetting()
{
    VfxS16 nvramError;
    ReadValue(m_nvramCacheId, &m_wallpaperResType, DS_BYTE, &nvramError);
}

void VappWpSettingWallpaperTypeSetting::restoreWallpaper()
{
    VfxS16 error;
    mmi_frm_get_default_cache_value(DS_BYTE, m_nvramCacheId, &m_wallpaperResType);
    
    WriteValue(m_nvramCacheId, &m_wallpaperResType, DS_BYTE, &error);   
    
    VappWpSettingStrategyBase::restoreWallpaper();
}


/***************************************************************************** 
 * VappWpSettingVideoWallpaperSetting
 *****************************************************************************/
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
void VappWpSettingVideoWallpaperSetting::getWallpaperId(VappWpResType type, VfxU16 *id)  
{
    #if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
    if (type == VAPP_WALLPAPER_VIDEO_WALLPAPER)
    {
        #if defined(__LOW_COST_SUPPORT_COMMON__)
        // Cosmos Slim does not have built-in resource video
        // so we return VDO_ID_SYS_INVALID_VID directly.
        // we cannot return 0 since Boot video would compare the resource ID directly (MAUI_03227086)
        *id = VDO_ID_SYS_INVALID_VID;
        #else
        // TODO: Waiting the UE's preparing;
        *id = m_videoWallpaperId + VDO_ID_SYS_MP4_01;
        #endif
    }
    #endif

	VappWpSettingStrategyBase::getWallpaperId(type, id);
}

void VappWpSettingVideoWallpaperSetting::setWallpaperId(VappWpResType type, VfxU16 wallpaperId, VappWpSetErrorCode *error) 
{
    if (type == VAPP_WALLPAPER_VIDEO_WALLPAPER)
    {
        #if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && !defined(__LOW_COST_SUPPORT_COMMON__)
        // TODO: Waiting the UE's preparing;
        m_videoWallpaperId = wallpaperId - VDO_ID_SYS_MP4_01;
        VfxS16 nvramError;
        WriteValue(m_nvramCacheId, &m_videoWallpaperId, DS_BYTE, &nvramError);
        *error = VAPP_WALLPAPER_SETTING_NO_ERROR;
        #endif
    }

    VappWpSettingStrategyBase::setWallpaperId(type, wallpaperId, error);
}

void VappWpSettingVideoWallpaperSetting::initSetting()
{
    VfxS16 nvramError;
    ReadValue(m_nvramCacheId, &m_videoWallpaperId, DS_BYTE, &nvramError);
}

void VappWpSettingVideoWallpaperSetting::restoreWallpaper()
{
    mmi_frm_get_default_cache_value(DS_BYTE, m_nvramCacheId, &m_videoWallpaperId);
    VfxS16 error;
    WriteValue(m_nvramCacheId, &m_videoWallpaperId, DS_BYTE, &error);

    VappWpSettingStrategyBase::restoreWallpaper();
}
#endif

/***************************************************************************** 
 * VappWpSettingUserWallpaperSetting
 *****************************************************************************/
void VappWpSettingFileDirectSetting::setWallpaperId(VappWpResType type, VfxU16 wallpaperId, VappWpSetErrorCode *error) 
{
    m_resetByUsb = VFX_FALSE; // Cancel mass storage handling
}

void VappWpSettingFileDirectSetting::getWallpaperFile(VappWpResType type, VfxWString *file)
{
    if (type == VAPP_WALLPAPER_USER_FILE)
	{
	#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
        {   
    		VfxU16 res_type = srv_fmgr_types_find_group_by_filename_str(m_userFileName.getBuf());
            if (res_type != FMGR_GROUP_UNKNOWN && res_type == FMGR_GROUP_VIDEO)
            {
            	*file  = m_userFileName;
            }
        }
    #endif

    #if defined(__LOW_COST_SUPPORT_COMMON__)
        {
            VfxU16 res_type = srv_fmgr_types_find_group_by_filename_str(m_userFileName.getBuf());
            if (res_type != FMGR_GROUP_UNKNOWN && res_type == FMGR_GROUP_IMAGE)
            {
            	*file  = m_userFileName;
            }
        }
    #endif // defined(__LOW_COST_SUPPORT_COMMON__)
	}
    VappWpSettingStrategyBase::getWallpaperFile(type, file);
}

// Set wallpaper file according to type, it will cache the file to system drive
void VappWpSettingFileDirectSetting::setWallpaperFile(VappWpResType type, const VfxWString &fileName, VappWpSetErrorCode *error) 
{
    if (type == VAPP_WALLPAPER_USER_FILE)
	{
	    m_userFileName = fileName;
        
        vfx_sys_wcscpy((VfxWChar *)m_fileData.userFile, fileName.getBuf());
        
        VfxS16 errCode;
        WriteRecord(m_nvramRecordId, m_nvramFileId, &m_fileData, sizeof(VappWpSettingUserFileStruct), &errCode); 
    }
    // perform operation
    VappWpSettingStrategyBase::setWallpaperFile(type, fileName, error);
}

// Check wallpaper availability, if it is not available to use, restore the wallpaper
void VappWpSettingFileDirectSetting::checkWallpaper(VappWpResType type, VappWpSetErrorCode *error) 
{
    if (type == VAPP_WALLPAPER_USER_FILE)
    {
	    VappWpSetErrorCode errorCode = checkWallpaperInt();
        if (errorCode != VAPP_WALLPAPER_SETTING_NO_ERROR)
    	{
    	    *error = errorCode;
    	}
    }
    VappWpSettingStrategyBase::checkWallpaper(type, error);
}

void VappWpSettingFileDirectSetting::initSetting()
{
    VfxS16 nvramError;

    memset(&m_fileData, 0, sizeof(VappWpSettingUserFileStruct));

    ReadRecord(m_nvramRecordId, m_nvramFileId, &m_fileData, sizeof(VappWpSettingUserFileStruct), &nvramError); 

    m_userFileName = VFX_WSTR_MEM(m_fileData.userFile);

    // If the file is valid, set resource type to user file wallpaper
}

void VappWpSettingFileDirectSetting::setNvramData(VfxU16 recordId, VfxU16 fileId) 
{
    m_nvramRecordId = recordId; 
    m_nvramFileId = fileId;
}


VappWpSetErrorCode VappWpSettingFileDirectSetting::checkWallpaperInt()
{
    VfxWString usingFileName(getFileName());
        
    if (usingFileName.isNull() || usingFileName.isEmpty())
    {
        usingFileName = m_userFileName;
    }

    if (usingFileName.isNull() || usingFileName.isEmpty())
    {
	return VAPP_WALLPAPER_SETTING_FILE_IS_NOT_EXSIT;
    }
    
    if (!isFileExist(usingFileName))
    {
	return VAPP_WALLPAPER_SETTING_FILE_IS_NOT_EXSIT;
    }

    if(!checkFileFormat(usingFileName, support_type))
    {
	    return VAPP_WALLPAPER_SETTING_UNSUPPORT_FORMAT;
    }

#ifdef __DRM_SUPPORT__    
    if (!isDRMVaild(usingFileName.getBuf()))
	{
	    return VAPP_WALLPAPER_SETTING_DRM_CHECK_FAIL;
	}
#endif  	
    return VAPP_WALLPAPER_SETTING_NO_ERROR;
}



#ifdef __MMI_USB_SUPPORT__
mmi_ret VappWpSettingFileDirectSetting::usbMassStorageModeHdlr(mmi_event_struct *evt)
{
    VappWpSettingFileDirectSetting *userWallpaperSetting = (VappWpSettingFileDirectSetting*)evt->user_data;
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

void VappWpSettingFileDirectSetting::enterMassStorageMode()
{
    VappWallpaperSettingProvider *provider = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VfxBool needUpdateWallpaper = provider->setUsbMassStorageMode(VFX_TRUE);
    if(needUpdateWallpaper)
    {
        VappWallpaperSettingInterface *settingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
        settingInterface->sendWallpaperUpdateSignal(m_wpType);
        m_resetByUsb = VFX_TRUE;
    }
}

void VappWpSettingFileDirectSetting::exitMassStorageMode()
{
    VappWallpaperSettingProvider *provider = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VfxBool needUpdateWallpaper = provider->setUsbMassStorageMode(VFX_FALSE);
    if(needUpdateWallpaper)
    {
        VappWallpaperSettingInterface *settingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
        settingInterface->sendWallpaperUpdateSignal(m_wpType);
    }
    m_resetByUsb = VFX_FALSE;
}
#endif /* __MMI_USB_SUPPORT__ */

VappWpSettingFileDirectSetting::VappWpSettingFileDirectSetting() : m_resetByUsb(VFX_FALSE), m_wpType(VAPP_WALLPAPER_TYPE_END)
{
    #ifdef __MMI_USB_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappWpSettingFileDirectSetting::usbMassStorageModeHdlr, this);
        mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappWpSettingFileDirectSetting::usbMassStorageModeHdlr, this);
    #endif /* __MMI_USB_SUPPORT__ */
}

VappWpSettingFileDirectSetting::~VappWpSettingFileDirectSetting()
{
    #ifdef __MMI_USB_SUPPORT__
        mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappWpSettingFileDirectSetting::usbMassStorageModeHdlr, this);
        mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, VappWpSettingFileDirectSetting::usbMassStorageModeHdlr, this);
    #endif /* __MMI_USB_SUPPORT__ */
}

#ifdef __DRM_SUPPORT__
VfxBool VappWpSettingFileDirectSetting::isDRMVaild(const VfxWChar *fileName)
{
    VfxU16 res_type = srv_fmgr_types_find_group_by_filename_str(fileName);
    VfxU8 permission;    
    
    if (res_type == FMGR_GROUP_IMAGE)
    {
        permission = DRM_PERMISSION_DISPLAY;
    }
    else if (res_type == FMGR_GROUP_VIDEO)
    {
        permission = DRM_PERMISSION_PLAY;
    }
    else 
    {
        permission = DRM_PERMISSION_NONE;
    }
    
    if (permission != DRM_PERMISSION_NONE)
    {
        FS_HANDLE handle = DRM_open_file((kal_wchar*)fileName, FS_READ_ONLY, permission);
        
        if (handle >= FS_NO_ERROR)
        {
            VfxBool isValid = DRM_validate_forward_rule(handle, permission);
            DRM_close_file(handle);
            return isValid;
        }
        else
        {
            return VFX_FALSE; // Cannot open the file
        }
    }
    return VFX_TRUE;
}
#endif /* __DRM_SUPPORT__ */

VfxBool VappWpSettingFileDirectSetting::checkFileFormat(VfxWString fileName, VfxS32 *formatArray)
{
    VfxU8 i;
    VfxS32 format = srv_fmgr_types_find_type_by_filepath(fileName.getBuf());
    if (!format)
	{
	    return MMI_FALSE;
	}
    for (i = 0; formatArray[i] != FMGR_TYPE_UNKNOWN; i++)
	{
        if (format == formatArray[i])		
    	{
    	    return MMI_TRUE;
    	}
	}
    return MMI_FALSE;
}

VfxBool VappWpSettingFileDirectSetting::isFileExist(const VfxWString &fileName)
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

/***************************************************************************** 
 * VappWpSettingUserWallpaperSetting
 *****************************************************************************/
#if !defined(__LOW_COST_SUPPORT_COMMON__)
 void VappWpSettingUserWallpaperSetting::setWallpaperCacheFile(VappWallpaperType type, const VfxWString &fileName, VappWpSetErrorCode *error)
{
    if(type == VAPP_WALLPAPER_HOME_SCREEN)
    {
       setDefaultFilename(WALLPAPER_CACHE_DEFAULT_HOME_FILENAME);
    }
    else if(type == VAPP_WALLPAPER_LOCK_SCREEN)
    {

        setDefaultFilename(WALLPAPER_CACHE_DEFAULT_LOCK_FILENAME);
    }
    m_cacheType = type;

    *error = cacheFile(fileName);

}
void VappWpSettingUserWallpaperSetting::getWallpaperFile(VappWpResType type, VfxWString *file)
{
    if (type == VAPP_WALLPAPER_USER_FILE)
	{
    #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
		VfxU16 res_type = srv_fmgr_types_find_group_by_filename_str(m_cacheFileName.getBuf());
        if (res_type != FMGR_GROUP_UNKNOWN && res_type != FMGR_GROUP_VIDEO )
    #endif
        *file  = m_cacheFileName;	
	}
    VappWpSettingFileDirectSetting::getWallpaperFile(type, file);
}


void VappWpSettingUserWallpaperSetting::restoreWallpaper() 
{
    if (!m_resetByUsb)
    {
	// Do not delete the file if it is caused by mass storage mode
        deleteOldFile();  
    }
    
    VappWpSettingStrategyBase::restoreWallpaper();
}

void VappWpSettingUserWallpaperSetting::initSetting()
{

    WCHAR wBuffer[(SRV_FMGR_PATH_MAX_LEN + 1)];
    memset(wBuffer, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
    mmi_asc_to_ucs2((CHAR*)wBuffer, m_fileData.cacheFile);
    m_cacheFileName = VFX_WSTR_MEM(wBuffer);

    // If the file is valid, set resource type to user file wallpaper
    initFolder();
}

VappWpSetErrorCode VappWpSettingUserWallpaperSetting::initFolder()
{
    /* Create cache folder */
    VfxWString path = VFX_WSTR_EMPTY;
    path.format("%c:\\%s", WALLPAPER_CACHE_DEFAULT_DRIVE, WALLPAPER_CACHE_DEFAULT_FOLDER);
      
    FS_HANDLE fsHandle = FS_Open(path.getBuf(), FS_OPEN_DIR | FS_READ_ONLY);
        
    /* Folder Exists */
    if (fsHandle > 0)
    {
        VfxS32 attribute = FS_GetAttributes(path.getBuf());
        if (!(attribute & FS_ATTR_DIR) || !(attribute & FS_ATTR_HIDDEN))
    	{
            FS_SetAttributes(path.getBuf(), FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
        FS_Close(fsHandle);
    }
    /* Folder Does Not Exist */
    else if (FS_CreateDir(path.getBuf()) == FS_NO_ERROR)
    {
        /* Create Success */
        VfxS32 attribute = FS_GetAttributes(path.getBuf());
        if (!(attribute & FS_ATTR_DIR) || !(attribute & FS_ATTR_HIDDEN))
    	{
            FS_SetAttributes(path.getBuf(), FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }    
    else
    {
        return VAPP_WALLPAPER_SETTING_PREPARE_FOLDER_FAIL;
    }
    return VAPP_WALLPAPER_SETTING_NO_ERROR;
}


VappWpSetErrorCode VappWpSettingUserWallpaperSetting::cacheFile(const VfxWString fileName)
{
    // Check file format
    if(!checkFileFormat(fileName, support_type))
    {
        return VAPP_WALLPAPER_SETTING_UNSUPPORT_FORMAT;
    }

#ifdef __DRM_SUPPORT__    
    if (!isDRMVaild(fileName.getBuf()))
	{
	    return VAPP_WALLPAPER_SETTING_DRM_CHECK_FAIL;
	}
#endif  	

    VappWpSetErrorCode ret = checkFolder(fileName);
    if (ret != VAPP_WALLPAPER_SETTING_NO_ERROR)
    {
        return ret;
    }

    VfxWChar *postfix = (VfxWChar*)srv_fmgr_path_get_extension_const_ptr(fileName.getBuf());
    
    // Prepare cache file.
    // We retry new file name if it already exists.
    // Note that old cache file will be removed by VappWallpaperSettingProvider
    VfxS32 retryCount = 0;
    const VfxS32 MAX_RETRY_COUNT = 10000;
    for(VfxS32 retryCount = 0; retryCount < MAX_RETRY_COUNT; ++retryCount)
    {
        m_cacheFileName = getDefaultFile(retryCount, VFX_WSTR_MEM(postfix));
        if(!isFileExist(m_cacheFileName))
        {
            break;
        }
    }
    // too many temp files
    VFX_ASSERT(!isFileExist(m_cacheFileName));

    // Copy file
    VfxS32 jobId = srv_fmgr_async_copy(
        fileName.getBuf(),
        m_cacheFileName.getBuf(),
        SRV_FMGR_ASYNC_FLAG_PRIORITY_FG,
        &VappWpSettingUserWallpaperSetting::cacheFinishedProc,
        this);

    if(jobId < 0)
    {
        return VAPP_WALLPAPER_SETTING_COPY_FILE_FAIL;
    }

    return VAPP_WALLPAPER_SETTING_NO_ERROR;
}

mmi_ret VappWpSettingUserWallpaperSetting::cacheFinishedProc(mmi_event_struct *evt)
{
    VappWpSettingUserWallpaperSetting *settingMethod = (VappWpSettingUserWallpaperSetting*)evt->user_data;
    return settingMethod->onCacheFinish(evt);
}

mmi_ret VappWpSettingUserWallpaperSetting::onCacheFinish(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_FMGR_ASYNC_DONE)
	{
        srv_fmgr_async_done_event_struct *fmgrEvt = (srv_fmgr_async_done_event_struct*)evt;

        if (fmgrEvt->result >= 0)
        {
            VappWallpaperId wid;

            VappLiveWallpaperContentProvider::getUserWallpaperId(wid, m_cacheFileName);
            VappWallpaperSettingProvider *provider = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
            VappWallpaperSrcEnum src;
            src = VAPP_WALLPAPER_HOME_SCREEN == m_cacheType ? VAPP_WALLPAPER_SRC_HOMESCREEN : VAPP_WALLPAPER_SRC_LOCK;
            provider->setDefaultWallpaper(
            src,
            wid,
            this);

            provider->notifyWallpaperUpdate(src);
            //m_signalSettingFinished.emit(VAPP_WALLPAPER_SETTING_NO_ERROR, m_cacheFileName);
            VappWallpaperSettingInterface *settingInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
            settingInterface->m_signalSettingFinished.emit(VAPP_WALLPAPER_SETTING_NO_ERROR);

            return MMI_RET_OK;
            
        }
	}

	deleteFile(m_cacheFileName);
    //m_errorStringId = srv_fmgr_fs_error_get_string(fmgrEvt->result);
    m_signalSettingFinished.emit(VAPP_WALLPAPER_SETTING_COPY_FILE_FAIL, VFX_WSTR_EMPTY);

	return MMI_RET_OK;
}

VappWpSetErrorCode VappWpSettingUserWallpaperSetting::checkFolder(VfxWString fileName)
{
    VappWpSetErrorCode ret = initFolder();
    if (ret != VAPP_WALLPAPER_SETTING_NO_ERROR)
	{
	    return ret;
	}
    
    FS_HANDLE fsHandle = FS_Open(fileName.getBuf(), FS_READ_ONLY);
    VfxU32 fileLength;
    if(fsHandle < 0)
    {
        return VAPP_WALLPAPER_SETTING_OPEN_FILE_FAIL;
    }
    FS_GetFileSize(fsHandle, &fileLength);
    FS_Close(fsHandle);

    if(fileLength == 0)
    {
        return VAPP_WALLPAPER_SETTING_EMPTY_FILE;
    }

    /* check device free space */    
    VfxWString path = VFX_WSTR_EMPTY;
    path.format("%c:\\", WALLPAPER_CACHE_DEFAULT_DRIVE);
    FS_DiskInfo diskInfo;

    if (FS_GetDiskInfo(path.getBuf(), &diskInfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE) >= 0)
    {
        VfxU64 disk_free_space = diskInfo.FreeClusters * diskInfo.SectorsPerCluster * diskInfo.BytesPerSector;

        if (fileLength >= disk_free_space || fileLength > MAX_USER_DEFINED_FILE_SIZE)
        {
            return VAPP_WALLPAPER_SETTING_DISK_SIZE_NOT_ENOUGH;
        }
    }
    else
    {
        return VAPP_WALLPAPER_SETTING_GET_DISK_INFO_FAIL;
    }    

    return VAPP_WALLPAPER_SETTING_NO_ERROR;    
}


VfxBool VappWpSettingUserWallpaperSetting::deleteFile(const VfxWString &fileName)
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

VfxBool VappWpSettingUserWallpaperSetting::deleteOldFile()
{
    VfxWString fileName = VFX_WSTR_EMPTY;
    if (!m_cacheFileName.isEmpty() && !m_cacheFileName.isNull())
	{
        if(isFileExist(m_cacheFileName))
        {
            if(!deleteFile(m_cacheFileName))
            {
                return VFX_FALSE;
            }
        }
	}
    m_cacheFileName = VFX_WSTR_EMPTY;
    m_userFileName = VFX_WSTR_EMPTY;
    
    VappWpSettingUserFileStruct fileData;
    memset(&fileData, 0, sizeof(VappWpSettingUserFileStruct));
    VfxS16 nvramError;
    WriteRecord(m_nvramRecordId, m_nvramFileId, &fileData, NVRAM_EF_WALLPAPER_FILENAME_SIZE, &nvramError); 

    return VFX_TRUE;
}



VfxWString VappWpSettingUserWallpaperSetting::getDefaultFile(VfxU8 index, VfxWString postfix)
{
    VfxWString defaultFileName = VFX_WSTR_EMPTY;    

    defaultFileName.format(
        "%c:\\%s\\",
        WALLPAPER_CACHE_DEFAULT_DRIVE,
        WALLPAPER_CACHE_DEFAULT_FOLDER);

    defaultFileName += m_defaultFileName;

    VfxWString temp = VFX_WSTR_EMPTY;
    
    temp.format(
        "%d.",
        index);
    
    defaultFileName+=temp;
    
    defaultFileName+=postfix;
    
    return defaultFileName;
}

VappWpSettingUserWallpaperSetting::VappWpSettingUserWallpaperSetting() : m_defaultFileName(VFX_WSTR_EMPTY)
{
}

VappWpSettingUserWallpaperSetting::~VappWpSettingUserWallpaperSetting()
{
}
#endif //#if !defined(__LOW_COST_SUPPORT_COMMON__)
