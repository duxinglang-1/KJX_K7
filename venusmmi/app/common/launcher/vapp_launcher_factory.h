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
 *  vapp_launcher_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the base class of the launcher factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_FACTORY_H
#define VAPP_LAUNCHER_FACTORY_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher.h"
#include "vapp_launcher_def.h"
#include "vapp_launcher_primitive.h"


/*****************************************************************************
 * Launcher Factory Base Class
 *****************************************************************************/

/*
 * Macro to declare a launcher factory.
 */
#define VAPP_LAUNCHER_FACTORY_DECLARE_CLASS(_className)                     \
    VFX_DECLARE_CLASS(_className);                                          \
    VFX_OBJ_DECLARE_SINGLETON_CLASS(_className)

/*
 * Macro to implement a launcher factory.
 */
#define VAPP_LAUNCHER_FACTORY_IMPLEMENT_CLASS(_className)                   \
    VFX_IMPLEMENT_CLASS(#_className, _className, VappLauncherFactory);      \
    VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(_className)

/*
 * Launcher Factory Base Class
 */
class VappLauncherFactory : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherFactory);

// Constructor / Destructor
public:
    // Default constructor.
    VappLauncherFactory();

    // Default destructor.
    virtual ~VappLauncherFactory();

// Method
public:
    // This function checks if the ID is valid.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isValid(
        const VappLauncherId &id        // [IN] Launcher ID
    );

    // This function gets the name of the launcher.
    // RETURNS: Length of the launcher name
    VfxS32 getName(
        const VappLauncherId &id,       // [IN]  Launcher ID
        VfxWChar *string,               // [OUT] String Buffer
        VfxS32 size                     // [IN]  Buffer size in wchar
    );

    // This function creates the launcher icon.
    // RETURNS: Launcher icon.
    VfxFrame *createIcon(
        const VappLauncherId &id,       // [IN] Launcher ID
        VfxObject *parentObj            // [IN] Parent of the launcher icon
    );

    // This function gets the number of the screenshots for this launcher.
    // RETURNS: Number of screenshots.
    VfxS32 getScreenshotNum(
        const VappLauncherId &id        // [IN] Launcher ID
    );

    // This function creates the screenshots for this launcher.
    // RETURNS: Array of the screenshots.
    VfxFrame **createScreenshot(
        const VappLauncherId &id,       // [IN] Launcher ID
        VfxObject *parentObj            // [IN] Parent of the screenshots
    );

// Override
public:
    // This function returns the type of the launcher factory.
    // RETURNS: type of the creator.
    virtual VappLauncherSrcEnum getSource() const = 0;

    // This function gets the total number of the launcher associated with this
    // type.
    // RETURNS: total number of the launchers.
    virtual VfxS32 getTotalNum() const = 0;

    // This function gets the id of all the launchers associated with this type.
    // RETURNS: total number of launchers.
    virtual VfxS32 getAllId(
        VappLauncherId **id,            // [OUT] Id of all the launchers
        VfxS32 size                     // [IN]  Size of the 'id' array
    ) const = 0;

    // This function creates a launcher.
    // RETURNS: the created launcher.
    virtual VappLauncher *createLauncher(
        const VappLauncherId &id,       // [IN] Id of the launcher
        VfxObject *parentObj            // [IN] Parent of the launcher
    ) = 0;
};

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
#endif /* VAPP_LAUNCHER_FACTORY_H */

