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
 *  vapp_launcher_kit.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the kit of the lancher framework.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_KIT_H
#define VAPP_LAUNCHER_KIT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher.h"
#include "vapp_launcher_def.h"
#include "vapp_launcher_primitive.h"
#include "vapp_launcher_factory.h"


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Macro to populate a launcher factory.
 */
#define VAPP_LAUNCHER_SYS_PUBLISH_FACTORY(_className, _publisher)           \
                                                                            \
    extern "C" mmi_ret _publisher(mmi_event_struct *event)                  \
    {                                                                       \
        _className *factory = VFX_OBJ_GET_INSTANCE(_className);             \
        VappLauncherKit *kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);       \
        kit->add(factory);                                                  \
        return MMI_RET_OK;                                                  \
    }


/*****************************************************************************
 * Launcher Kit Filter Class
 *****************************************************************************/

class VappLauncherKitFilter : public VfxBase
{
public:
    VappLauncherKitFilter();

    VappLauncherKitFilter(
        VfxBool initial
    );

    ~VappLauncherKitFilter();

public:
    void permit(
        VappLauncherSrcEnum source
    );

    void forbit(
        VappLauncherSrcEnum source
    );

    VfxBool isPermitted(
        VappLauncherSrcEnum source
    ) const;

private:
    enum
    {
        TOTAL_SOURCE_NUM = VAPP_LAUNCHER_SRC_TOTAL
    };

private:
    VfxBool m_permitted[TOTAL_SOURCE_NUM];
};


/*****************************************************************************
 * Launcher Kit
 *****************************************************************************/

class VappLauncherKit : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherKit);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherKit);

// Constructor / Destructor
public:
    // Default Constructor
    VappLauncherKit();

// Method
public:
    // This function gets the total number of supported launchers.
    // RETURNS: total number of launchers.
    VfxS32 getTotalNum(
        const VappLauncherKitFilter *fitler = NULL  // [IN] Kit filter
    );

    // This function gets the ID of all the supported launchers.
    // RETURNS: total number of launchers.
    VfxS32 getAllId(
        VappLauncherId **id,                        // [OUT] Launcher ID array
        VfxS32 size,                                // [IN]  Size of the array
        const VappLauncherKitFilter *filter = NULL  // [IN]  Kit filter
    );

    // This function checks if the ID is valid to create a launcher.
    // RETURNS: valid or not.
    VfxBool isIdValid(
        const VappLauncherId &id,                   // [IN] Launcher ID
        const VappLauncherKitFilter *filter = NULL  // [IN] Kit filter
    );

    // This function gets the name of the launchers.
    // RETURNS: length of the launcher name
    VfxS32 getName(
        const VappLauncherId &id,   // [IN]  Launcher ID
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN]  Buffer size in wchar
    );

    // This function creates the launchers.
    // RETURNS: the created launcher.
    VappLauncher *createLauncher(
        const VappLauncherId &id,   // [IN] Launcher ID
        VfxObject *parentObj        // [IN] Parent object of the launcher
    );

    // This function creates the launcher icon.
    // RETURNS: the launcher icon.
    VfxFrame *createIcon(
        const VappLauncherId &id,   // [IN] Launcher ID
        VfxObject *parentObj        // [IN] Parent object of the launcher
    );

    // This function gets the number of the screenshots for this launcher.
    // RETURNS: Number of screenshots.
    VfxS32 getScreenshotNum(
        const VappLauncherId &id        // [IN] Launcher ID
    ) const;

    // This function creates the screenshots for this launcher.
    // RETURNS: Array of the screenshots.
    VfxFrame **createScreenshot(
        const VappLauncherId &id,       // [IN] Launcher ID
        VfxObject *parentObj            // [IN] Parent of the screenshots
    ) const;

    // This function releases the screenshot array.
    void releaseScreenshot(
        VfxFrame **screenshot,          // [IN] Screenshot array
        VfxS32 size                     // [IN] Size of the array
    ) const;

// Method
public:
    // This function adds a launcher factory to the kit.
    void add(
        VappLauncherFactory *factory        // [IN] Launcher factory
    );

    // This function removes a launcher factory from the kit.
    void remove(
        VappLauncherFactory *factory        // [IN] Launcher factory
    );

// Variable
private:
    // Factory list.
    VfxObjList m_factoryList;
};

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
#endif /* VAPP_LAUNCHER_KIT_H */

