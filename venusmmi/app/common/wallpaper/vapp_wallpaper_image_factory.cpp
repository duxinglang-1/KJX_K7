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
 *  vapp_wallpaper_user_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE factory of the screen lock.
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
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_image_factory.h"
#include "vapp_wallpaper_wide.h"

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VAPP_WALLPAPER_FACTORY_IMPLEMENT_CLASS(VappWallpaperImageFactory);

VappWallpaperImageFactory::VappWallpaperImageFactory()
{
    // Do nothing.
}

VappWallpaperFactorySrcEnum VappWallpaperImageFactory::getSource() const
{
    return VAPP_WALLPAPER_FACTORY_IMAGE;
}

VfxS32 VappWallpaperImageFactory::getTotalNum()
{
    return 0;
}

VfxBool VappWallpaperImageFactory::getId(
    VappWallpaperId &wallpaperId,   
    VfxS32 index)
{
    return VFX_FALSE;
}

VfxS32 VappWallpaperImageFactory::getAllId(
    VappWallpaperId **idArray,
    VfxS32 size)
{
    return 0;
}

VappWallpaper *VappWallpaperImageFactory::createWallpaper(
    const VappWallpaperId &id,
    VfxObject *parentObj)
{
    // Create VappWallpaperWide
    VappWallpaperWide *wp = NULL;
    VFX_OBJ_CREATE(wp, VappWallpaperWide, parentObj);
    if(VappWallpaperId::TYPE_KIND_INTEGER == id.getTypeKind())
    {
        VfxU32 resId = 0;
        resId = (VfxU32)id.getIntType();
        // assign resource id
        wp->setResId(resId);
    }
    else if(VappWallpaperId::TYPE_KIND_WSTRING == id.getTypeKind())
    {
        const VfxWChar* path = id.getWStringType();
        wp->setPath(VFX_WSTR_MEM(path));
    }

    return wp;
}