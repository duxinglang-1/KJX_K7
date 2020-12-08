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
 *  vapp_wallpaper_setting_method_gprot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_WALLPAPER_SETTING_METHOD_GPROT_H__
#define __VAPP_WALLPAPER_SETTING_METHOD_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_wallpaper_type_def_gprot.h"
extern "C"
{
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_vapp_setting_def.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define WALLPAPER_CACHE_DEFAULT_DRIVE         (SRV_FMGR_SYSTEM_DRV)
#define WALLPAPER_CACHE_DEFAULT_FOLDER        ("@Settings")
#define WALLPAPER_CACHE_DEFAULT_LOCK_FILENAME (VFX_WSTR("LockWP"))
#define WALLPAPER_CACHE_DEFAULT_HOME_FILENAME (VFX_WSTR("HomeWP"))
#define WALLPAPER_CACHE_DEFAULT_MENU_FILENAME (VFX_WSTR("MenuWP"))
#define WALLPAPER_CACHE_FILENAME_MAX_LENGTH   (64) // C:\@Settings\HomeWp0x.jpg
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    IMG_ID_WP_THEME_START 		= IMG_ID_THEME_WALLPAPER_0,
    IMG_ID_WP_THEME_THUMB_START = IMG_ID_THEME_WALLPAPER_THUMB_0,
    
    IMG_ID_WP_THEME_MAX 		= IMG_ID_WP_THEME_START + MMI_WP_THEME_NUM - 1,
    IMG_ID_WP_THEME_THUMB_MAX 	= IMG_ID_WP_THEME_THUMB_START + MMI_WP_THEME_NUM - 1

}vapp_theme_type_enum;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappWpSettingStrategyBase;
class VappWpSettingUserWallpaperSetting;
class VappWallpaperSettingInterface : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWallpaperSettingInterface);
    
protected:
	virtual void onInit();
	virtual void onDeinit();

public:
	    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator()
    {
        return m_context->getAllocator();
    }

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    virtual VfxU16 getVideoResId(VappWallpaperType type); 
    
    // Get wallpaper file path and file name
    // Return NULL if this type wallpaper is using resource from system provided
    // It will restore the wallpaper if the setting is invalid
    virtual VfxWString getWallpaperFile(VappWallpaperType type);

    // Get resource type of input type wallpaper setting
    virtual VappWpResType getWallpaperResType(VappWallpaperType type);
        

    // Check wallpaper availability, if it is not available to use, restore the wallpaper
    virtual VappWpSetErrorCode checkWallpaper(VappWallpaperType type);
     // Set wallpaper ID according to type and resource type
    // Assert if the resource type is VAPP_WALLPAPER_USER_FILE
    virtual VappWpSetErrorCode setWallpaperId(VappWallpaperType type, VappWpResType resType, VfxU16 wallpaperId);
     
    // Set wallpaper file according to type, m_signalSettingFinished will be emit when setting is finished
    virtual VappWpSetErrorCode setWallpaperFile(VappWallpaperType type, const VfxWString &fileName);
#endif /*__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__*/

#if !defined(__LOW_COST_SUPPORT_COMMON__)
    VfxResId getErrorString(VappWpSetErrorCode errorCode);
#endif

    // Restore wallpaper to the default one
    virtual void restoreWallpaper(VappWallpaperType type);
    virtual void restoreWallpaperEx(VappWallpaperType type, VfxBool sendRestoreSignal = VFX_TRUE, VfxBool dueToError = VFX_FALSE);
    
    void sendWallpaperUpdateSignal(VappWallpaperType type);

    // Internal sue
private:
    VappWallpaperSettingInterface();


private:
    void createWallpaperObj();
          
    // Variable
public:
    VfxSignal1 <VfxU8> m_signalSettingFinished; // will emit VappWpSetErrorCode
    VfxSignal0 m_signalWallpaperIsUpdated;
    
private:
    VappWpSettingStrategyBase *m_wallpaperSettingObj[VAPP_WALLPAPER_TYPE_END];
    VappWpSettingUserWallpaperSetting *m_UserImageCache;
    VappWallpaperType m_settingType; // used for user file setting
    VfxContext *m_context;

    friend class VappWpSettingFileDirectSetting;
    friend class VappWallpaperSettingProvider;
};
#endif /* __VAPP_WALLPAPER_SETTING_METHOD_GPROT_H__ */
 
