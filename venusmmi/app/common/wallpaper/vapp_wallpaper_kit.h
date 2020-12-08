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
 *  vapp_wallpaper_kit.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the classes for the wallpaper kit.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WALLPAPER_KIT_H__
#define __VAPP_WALLPAPER_KIT_H__

#include "MMI_features.h"

/* RHR start */
#include "vfx_object.h"   
#include "vfx_class_info.h"
#include "vfx_datatype.h"
/* RHR end */

#include "vapp_wallpaper.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_wallpaper_id.h"

class VappWallpaperFactory;
/*****************************************************************************
 * Venus home screen wallpaper kit
 *****************************************************************************/
class VappWallpaperKit : public VfxObject
{
    VFX_DECLARE_CLASS(VappWallpaperKit);

public:
    
    // Create wallpaper according to current system setting
    // @param wallpaperHost [IN] VAPP_WALLPAPER_SRC_HOMESCREEN or VAPP_WALLPAPER_SRC_LOCK
    static VappWallpaper* createWallpaper(VfxObject *parentObj, VappWallpaperSrcEnum src, VfxS32 desktopCount = 1);

    // Create wallpaper object without any subsequent config calls. 
    // User must call createView/suspend/resume/... afterwards
    static VappWallpaper* createWallpaperWithoutSetup(VfxObject *parentObj, VappWallpaperSrcEnum src);

    // Check if a wallpaper requires file system to play.
    // this is used for checking USB Mass storage mode limitation.
    static VfxBool isFileBasedWallpaper(const VappWallpaperId &wallpaperId);
    

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperKit();

// Override
public:
    virtual void onInit();
    virtual void onDeinit();

// Method
public:
    // This function creates a wallpaper from wallpaper enum
    // RETURNS: the created wallpaper.
    VappWallpaper* create(
        VfxS32 id,
        VfxObject *parentObj
    );

    // This function creates a wallpaper from wallpaper Id
    // RETURNS: the created wallpaper.
    VappWallpaper* create(
        const VappWallpaperId &id,
        VfxObject *parentObj
    );

    // get total number of live wallpaper
    S32 getLiveWallpaperTotalNum();

    // get live wallpaper enum id from item index
    VfxBool getLiveWallpaperId(VfxS32 number, VappWallpaperId &wid);

    // get live wallpaper thumbnail
    MMI_IMG_ID getLiveWallpaperThumbnail(const VappWallpaperId &wid);
        
private:
    VfxArray<VappWallpaperFactory*> m_factoryList;
};

#endif /* __VAPP_WALLPAPER_KIT_H__ */

