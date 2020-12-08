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
 *  vapp_wallpaper_mre_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE factory of the wallpaper.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WALLPAPER_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

extern "C"
{
#include "MREAppMgrSrvGprot.h"
#include "SafeModeSrvGprot.h"
}

#include "vfx_uc_include.h"
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_mre_factory.h"
#include "vapp_wallpaper_mre.h"
#include "vapp_wallpaper_kit.h"


/*****************************************************************************
 * MRE Wallpaper Factory
 *****************************************************************************/

VAPP_WALLPAPER_FACTORY_IMPLEMENT_CLASS(VappWallpaperMreFactory);


VappWallpaperFactorySrcEnum VappWallpaperMreFactory::getSource() const
{
    return VAPP_WALLPAPER_FACTORY_MRE;
}


VfxS32 VappWallpaperMreFactory::getTotalNum()
{
    if (srv_safe_mode_is_active())
    {
        return 0;
    }

    return srv_mre_appmgr_get_app_num(
            SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE);
}


VfxBool VappWallpaperMreFactory::getId(
        VappWallpaperId &wallpaperId,
        VfxS32 index)
{
    if (srv_safe_mode_is_active())
    {
        return VFX_FALSE;
    }

    const VfxS32 totalNum = getTotalNum();

    if(index < 0 || index >= totalNum)
    {
        return VFX_FALSE;
    }

    mmi_app_package_name_struct *package = NULL;
    VFX_SYS_ALLOC_MEM(package, totalNum * sizeof(mmi_app_package_name_struct));

    mmi_ret ret = srv_mre_appmgr_get_app_list(
                    SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE,
                    package,
                    totalNum);
    VFX_ASSERT(ret == MMI_RET_OK);
    wallpaperId.assignWith(VAPP_WALLPAPER_FACTORY_MRE, package[index]);
    VFX_SYS_FREE_MEM(package);

    return VFX_TRUE;
}


VfxS32 VappWallpaperMreFactory::getAllId(
    VappWallpaperId **id,
    VfxS32 size)
{
    if (srv_safe_mode_is_active())
    {
        return 0;
    }

    VfxS32 totalNum = getTotalNum();

    VFX_ASSERT(id && size >= totalNum);

    mmi_app_package_name_struct *package;

    VFX_SYS_ALLOC_MEM(package, totalNum * sizeof(mmi_app_package_name_struct));

    mmi_ret ret = srv_mre_appmgr_get_app_list(
                    SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE,
                    package,
                    totalNum);

    VFX_ASSERT(ret == MMI_RET_OK);

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        id[i]->assignWith(VAPP_WALLPAPER_FACTORY_MRE, package[i]);
    }

    VFX_SYS_FREE_MEM(package);

    return totalNum;
}


VappWallpaper *VappWallpaperMreFactory::createWallpaper(
    const VappWallpaperId &id,
    VfxObject *parentObj)
{
    if (srv_safe_mode_is_active() ||
        id.getSource() != VAPP_WALLPAPER_FACTORY_MRE||
        id.getTypeKind() != VappWallpaperId::TYPE_KIND_STRING)
    {
        return NULL;
    }

    VappWallpaperMre *wp = NULL;
    VFX_OBJ_CREATE(wp, VappWallpaperMre, parentObj);
    wp->setMreId(VFX_STR_DYNAMIC(id.getStringType()));
    return wp;
}

#endif /* defined(__MMI_VUI_WALLPAPER_MRE__) */

