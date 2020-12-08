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
 *  vapp_wallpaper_file_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE screen lock factory.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WALLPAPER_FILE_FACTORY_H
#define VAPP_WALLPAPER_FILE_FACTORY_H

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_wallpaper_factory.h"

/*****************************************************************************
 * Class that represents a wallpaper file
 *****************************************************************************/
class WallpaperFile
{
public:
    VfxU32 hintCluster;
    VfxU32 hintIndex;
    #ifndef __MTK_TARGET__
    VfxWChar filePath[FS_MAX_PATH];
    #endif
    
public:
    FS_HANDLE openFileHandle() const;
    VfxWString getFilePath() const;

    static VfxWString getRootFolder();
    static void fromWallpaperId(const VappWallpaperId &id, WallpaperFile &f);
};

/*****************************************************************************
 * File-based (mwp, lwp) wallpaper factory
 *****************************************************************************/
class VappWallpaperFileFactory : public VappWallpaperFactory
{
    VAPP_WALLPAPER_FACTORY_DECLARE_CLASS(VappWallpaperFileFactory);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperFileFactory();

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    
    // Please refer to VappWallpaperFactory.
    virtual VappWallpaperFactorySrcEnum getSource() const;

    // Please refer to VappWallpaperFactory.
    virtual VfxS32 getTotalNum();

   // Please refer to VappWallpaperFactory.
    virtual VfxBool getId(
        VappWallpaperId &wallpaperId,   
        VfxS32 index                    
    );
   
    // Please refer to VappWallpaperFactory.
    virtual VfxS32 getAllId(
        VappWallpaperId **id,
        VfxS32 size
    );

    // Please refer to VappWallpaperFactory.
    virtual VappWallpaper *createWallpaper(
        const VappWallpaperId &id,
        VfxObject *parentObj
    );
    
private:
    static const VfxS32 MAX_FILE_WALLPAPER_COUNT = 200;     // maximum on-disk live wallpaper count
    VfxBool isSupportLWP() const;
    void initWallpaperArrayIfNeeded();                              // lazy-evaluate the array
    void validateAndRemoveWallpaper();                      // force update the array

private:
    VfxBool m_wallpaperArrayChecked;             // for lazy-evaluation of wallpaper array
    VfxArray<VappWallpaperId> m_wallpaperArray;  // searched file wallpapers
};

#endif // __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
#endif /* VAPP_WALLPAPER_FILE_FACTORY_H */

