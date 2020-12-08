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
 *  vapp_wallpaper_kit.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements the wallpaper kit.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_setting_provider.h"
#include "trc/vadp_app_trc.h"

/* RHR start */
#include "vfx_cpp_base.h"  
#include "vfx_object.h"    
#include "vfx_sys_memory.h" 
#include "vfx_class_info.h" 
#include "vfx_datatype.h"  
#include "vapp_wallpaper.h"    
#include "vapp_wallpaper_cfg.h"   
#include "kal_public_api.h"
#include "vrt_datatype.h"   
#include "kal_general_types.h"
/* RHR end */

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_wallpaper_setting_method_gprot.h"
#else
#include "WPSSProtos.h"
#include "SettingGprots.h"
extern S8 *idle_screen_wallpaper_name;
extern S8 *idle_screen_wallpaper_name_original;
extern MMI_ID_TYPE idle_screen_wallpaper_ID;
extern MMI_theme *current_MMI_theme;
#endif
#ifdef __MMI_VUI_NATIVE_LIVE_WALLPAPER__
#include "vapp_wallpaper_native_factory.h"
#endif
#include "vapp_wallpaper_image_factory.h"
#include "vapp_wallpaper_file_factory.h"
#if defined(__MMI_VUI_WALLPAPER_MRE__)
#include "vapp_wallpaper_mre_factory.h"
#endif
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
#include "vapp_wallpaper_video_factory.h"
#endif
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
#include "vapp_wallpaper_user_factory.h"
#endif
#include "CustVenusThemeRes.h"

#ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
#include "vapp_theme.h"
#include "mmi_rp_vapp_theme_def.h"
#endif

/*****************************************************************************
 * Venus home wallpaper kit
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWallpaper Kit", VappWallpaperKit, VfxObject);

VappWallpaperKit::VappWallpaperKit()
{
}

void VappWallpaperKit::onInit()
{
    VfxObject::onInit();
    m_factoryList.init(this);

    // setup factories 
    // currently we don't use register-during-bootup mechanism.
    VappWallpaperFactory *f = NULL;
    #ifdef __MMI_VUI_NATIVE_LIVE_WALLPAPER__
    VFX_OBJ_CREATE(f, VappWallpaperNativeFactory, this);
    m_factoryList.pushBack(f);
    #endif
    VFX_OBJ_CREATE(f, VappWallpaperImageFactory, this);
    m_factoryList.pushBack(f);
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)
    VFX_OBJ_CREATE(f, VappWallpaperFileFactory, this);
    m_factoryList.pushBack(f);
    #endif
    #ifdef __MMI_VUI_WALLPAPER_MRE__
    VFX_OBJ_CREATE(f, VappWallpaperMreFactory, this);
    m_factoryList.pushBack(f); 
    #endif
    #ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    VFX_OBJ_CREATE(f, VappWallpaperUserFileFactory, this);
    m_factoryList.pushBack(f);
    #endif
    #ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VFX_OBJ_CREATE(f, VappWallpaperVideoFactory, this);
    m_factoryList.pushBack(f);
    #endif
}

void VappWallpaperKit::onDeinit()
{
    // release all factories
    for(VfxS32 i = 0; i < m_factoryList.size(); ++i)
    {
        VappWallpaperFactory *f = m_factoryList[i];
        VFX_OBJ_CLOSE(f);
    }
    m_factoryList.deinit();
    VfxObject::onDeinit();
}

VappWallpaper* VappWallpaperKit::create(
        VfxS32 id,
        VfxObject *parentObj)
{
    // this function exists only for backward compatability.
    // it now creates only static wallpaper.
    VappWallpaperId wid;
    wid.assignWith(VAPP_WALLPAPER_FACTORY_NATIVE, id);
    return this->create(wid, parentObj);
}

VappWallpaper* VappWallpaperKit::create(
    const VappWallpaperId &id,
    VfxObject *parentObj)
{
    const VappWallpaperFactorySrcEnum factoryType = id.getSource();

    for(VfxS32 i = 0; i < m_factoryList.size(); ++i)
    {
        VappWallpaperFactory *f = m_factoryList[i];
        if(f->getSource() == factoryType)
        {
            return f->createWallpaper(id, parentObj);
        }
    }

    VFX_ASSERT(0);  // unrecognized factory type
    return NULL;
}

S32 VappWallpaperKit::getLiveWallpaperTotalNum()
{
    VfxS32 totalCount = 0;
    for(VfxS32 i = 0; i < m_factoryList.size(); ++i)
    {
        VappWallpaperFactory *factory = m_factoryList[i];
        totalCount += factory->getTotalNum();
    }
    return totalCount;
}

VfxBool VappWallpaperKit::getLiveWallpaperId(VfxS32 number, VappWallpaperId &wid)
{
    const VfxS32 totalCount = getLiveWallpaperTotalNum();
    if(number < 0 || number >= totalCount)
    {
        // wallpaper index overflow
        VFX_ASSERT(0);
    }

    for(VfxS32 factoryIdx = 0; factoryIdx < m_factoryList.size(); ++factoryIdx)
    {
        const VfxS32 wallpaperInFactory = m_factoryList[factoryIdx]->getTotalNum();
        if(number >= wallpaperInFactory)
        {
            number -= wallpaperInFactory;
        }
        else
        {
            // found, get the id
            m_factoryList[factoryIdx]->getId(wid, number);
            break;
        }
    }
    return VFX_TRUE;
}


MMI_IMG_ID VappWallpaperKit::getLiveWallpaperThumbnail(const VappWallpaperId &wid)
{
    VappWallpaper *wallpaper = create(wid, this);
    VfxResId resId = wallpaper->getThumbnail();
    VFX_OBJ_CLOSE(wallpaper);
    return resId;
}

VfxBool VappWallpaperKit::isFileBasedWallpaper(const VappWallpaperId &wid)
{
    switch(wid.getSource())
    {
    case VAPP_WALLPAPER_FACTORY_NATIVE:
        return VFX_FALSE;
    case VAPP_WALLPAPER_FACTORY_FILE:
    case VAPP_WALLPAPER_FACTORY_MRE:
    case VAPP_WALLPAPER_FACTORY_USERFILE:
        return VFX_TRUE;
    case VAPP_WALLPAPER_FACTORY_IMAGE:
    case VAPP_WALLPAPER_FACTORY_VIDEO:
        if(VappWallpaperId::TYPE_KIND_WSTRING == wid.getTypeKind())
        {
            // a path, so this is file-based
            return VFX_TRUE;
        }
        else if(VappWallpaperId::TYPE_KIND_INTEGER == wid.getTypeKind())
        {
            // resource id, not file-based
            // but if it is theme wallpaper, it may be a 
            // downloadable app icon's wallpaper
#ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
            VfxU8 activeIndex;
            VfxS16 errCode;
            ReadValue(NVRAM_THEME_ACTIVE_INDEX, &activeIndex, DS_BYTE, &errCode);
            
            if(MMI_TRUE == mmi_res_is_theme_image(wid.getIntType()) && (DLT_THEME_TAG == activeIndex))
            {
                return VFX_TRUE;
            }
#endif /*__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__*/    
                return VFX_FALSE;
           
        }
        else
        {
            return VFX_FALSE;
        }
    }
    return VFX_FALSE;
}

VappWallpaper* VappWallpaperKit::createWallpaperWithoutSetup(VfxObject *parentObj, VappWallpaperSrcEnum src)
{
    VappWallpaper *wallpaper = NULL;
    // Use wallpaper ID to create wallpaper
    VappWallpaperSettingProvider *setting = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingProvider);
    VappWallpaperKit *wallpaperKit = NULL;
    VFX_OBJ_CREATE(wallpaperKit, VappWallpaperKit, parentObj);
    wallpaper = wallpaperKit->create(setting->getDefaultWallpaper(src, parentObj), parentObj);
    if(NULL == wallpaper)
    {
        VappWallpaperId fallbackId;
        setting->getFallbackWallpaperId(fallbackId, VFX_TRUE);
        wallpaper = wallpaperKit->create(fallbackId, parentObj);
    }
    VFX_OBJ_CLOSE(wallpaperKit);
    return wallpaper;
}

VappWallpaper* VappWallpaperKit::createWallpaper(VfxObject *parentObj, VappWallpaperSrcEnum src, VfxS32 desktopCount)
{
    VappWallpaper *wallpaper = createWallpaperWithoutSetup(parentObj, src);
    if(wallpaper)
    {
        wallpaper->setSource(src);
        wallpaper->setTotalPage(desktopCount);
        wallpaper->createView();
        wallpaper->sendToBack();
        wallpaper->setDesktopBoundsChanged(desktopCount, wallpaper, wallpaper->getBounds());
        if(VAPP_WALLPAPER_SRC_LOCK == src)
        {
            wallpaper->setIsDisabled(VFX_TRUE);
        }
        // by default, wallpapers are created in resumed state.
        wallpaper->suspend();
        wallpaper->resume();
    }    
    return wallpaper;
}
