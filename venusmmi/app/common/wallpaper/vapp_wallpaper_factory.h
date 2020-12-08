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
 *  vapp_wallpaper_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the base class of the wallpaper factory.
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

#ifndef VAPP_WALLPAPER_FACTORY_H
#define VAPP_WALLPAPER_FACTORY_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_wallpaper_def.h"
#include "vapp_wallpaper_id.h"
#include "vapp_wallpaper.h"


/*****************************************************************************
 * Wallpaper Factory Base Class
 *****************************************************************************/

/*
 * Macro to declare a wallpaper factory.
 */
#define VAPP_WALLPAPER_FACTORY_DECLARE_CLASS(_className)                  \
    VFX_DECLARE_CLASS(_className)

/*
 * Macro to implement a wallpaper factory.
 */
#define VAPP_WALLPAPER_FACTORY_IMPLEMENT_CLASS(_className)                \
    VFX_IMPLEMENT_CLASS(#_className, _className, VappWallpaperFactory);


/*
 * Wallpaper Factory Base Class
 */
class VappWallpaperFactory : public VfxObject
{
    VAPP_WALLPAPER_FACTORY_DECLARE_CLASS(VappWallpaperFactory);

// Constructor / Destructor
public:
    // Default constructor.
    VappWallpaperFactory();

    // Default destructor.
    virtual ~VappWallpaperFactory();

// Overridable
public:
    // This function returns the type of the wallpaper factory.
    // RETURNS: type of the creator.
    virtual VappWallpaperFactorySrcEnum getSource() const = 0;

    // This function gets the total number of the wallpaper associated with this
    // type.
    // RETURNS: total number of the screen locks.
    virtual VfxS32 getTotalNum() = 0;

    // This function gets the id of all the wallpapers associated with this type.
    // RETURNS: successfully retrieves id or not
    virtual VfxBool getId(
        VappWallpaperId &wallpaperId,   // [OUT] Id of the wallpaper
        VfxS32 index                    // [IN]  index from 0 ~ getTotalNum() - 1
    ) = 0;
    
    // This function gets the id of all the wallpapers associated with this type.
    // RETURNS: total number of wallpapers.
    virtual VfxS32 getAllId(
        VappWallpaperId **id,          // [OUT] Id of all the wallpapers
        VfxS32 size                     // [IN]  Size of the 'id' array
    ) = 0;

    // This function creates a wallpapers
    // RETURNS: the created wallpapers
    virtual VappWallpaper *createWallpaper(
        const VappWallpaperId &id,     // [IN] Id of the wallpaper
        VfxObject *parentObj            // [IN] Parent of the wallpapers
    ) = 0;

// Method
public:
    // This function checks if the ID is valid.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isValid(
        const VappWallpaperId &id      // [IN] Launcher ID
    );

    // This function gets the name of wallpaper
    // RETURNS: Length of the wallpaper name
    VfxS32 getName(
        const VappWallpaperId &id,      // [IN]  Screen lock ID
        VfxWChar *string,               // [OUT] String Buffer
        VfxS32 size                     // [IN]  Buffer size in wchar
    );

};

#endif /* VAPP_WALLPAPER_FACTORY_H */

