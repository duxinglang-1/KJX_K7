/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_wallpaper_native_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the native screen lock factory.
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

#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_native_factory.h"
#include "vapp_wallpaper_cfg.h"

#ifdef __MMI_VUI_NATIVE_LIVE_WALLPAPER__

/*****************************************************************************
 * Native Screen Lock Factory
 *****************************************************************************/
VAPP_WALLPAPER_FACTORY_IMPLEMENT_CLASS(VappWallpaperNativeFactory);

VappWallpaperNativeFactory::VappWallpaperNativeFactory()
{
    
}

VappWallpaperFactorySrcEnum VappWallpaperNativeFactory::getSource() const
{
    return VAPP_WALLPAPER_FACTORY_NATIVE;
}

VfxS32 VappWallpaperNativeFactory::getTotalNum()
{
    // exclude wide(static) wallpaper and exclude video wallpaper
    S32 totalCount = VAPP_WALLPAPER_TOTAL - 1;

    // exclude video wallpaper class
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    totalCount -= 1;
#endif
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
    totalCount -= 1;
    totalCount -= 1;
#endif
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    totalCount -= 1;
#endif
#ifdef __MMI_VUI_WALLPAPER_MRE__
    totalCount -= 1;
#endif 
    // exclude frame video class
    return totalCount;
}

VfxS32 VappWallpaperNativeFactory::getLiveWallpaperindex(VfxS32 number) const
{
    // add by 1 because need to skip wide wallpaper  
    number += 1;
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    // add by 1 because need to skip video wallpaper
    number += 1;
#endif
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
    number += 1;
    number += 1;
#endif
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    number += 1;
#endif
#ifdef __MMI_VUI_WALLPAPER_MRE__
    number += 1;
#endif
    return number;
}


VfxBool VappWallpaperNativeFactory::getId(
    VappWallpaperId &wallpaperId,   
    VfxS32 index)
{
    VfxS32 wallpaperEnum = getLiveWallpaperindex(index);
    wallpaperId.assignWith(VAPP_WALLPAPER_FACTORY_NATIVE, wallpaperEnum);
    return VFX_TRUE;
}

VfxS32 VappWallpaperNativeFactory::getAllId(
    VappWallpaperId **id,
    VfxS32 size)
{
    // Make sure the caller's buffer is available and large enough.
    const VfxS32 totalNum = getTotalNum();
    VFX_ASSERT(id && size >= totalNum);

    // Copy ID to the buffer.
    for (VfxS32 i = 0; i < totalNum; ++i)
    {
        VfxS32 wallpaperEnum = getLiveWallpaperindex(i);
        id[i]->assignWith(VAPP_WALLPAPER_FACTORY_NATIVE, wallpaperEnum);
    }

    return totalNum;
}


VappWallpaper *VappWallpaperNativeFactory::createWallpaper(
    const VappWallpaperId &id,
    VfxObject *parentObj)
{
    if (id.getSource() != getSource())
    {
        return NULL;
    }

    const vapp_wallpaper_cfg_struct *tbl = vapp_wallpaper_get_cfg_table();
    const VfxS32 wallpaperEnum = id.getIntType();
    VappWallpaper* wallpaper = NULL;
    
    for (VfxS32 i = 0; i < VAPP_WALLPAPER_TOTAL; i++)
    {
        if (tbl[i].id == wallpaperEnum &&
            tbl[i].create)
        {
            wallpaper = (VappWallpaper *)tbl[i].create(parentObj);
            return wallpaper;
        }
    }

    // invalid wallpaper Enum
    return NULL;
}

#endif /*__MMI_VUI_NATIVE_LIVE_WALLPAPER__*/
