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
 *  vapp_screen_lock_kit.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the screen lock kit.
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

#ifndef VAPP_SCREEN_LOCK_KIT_H
#define VAPP_SCREEN_LOCK_KIT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_primitive.h"
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_factory.h"


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Macro to populate a screen lock factory.
 */
#define VAPP_SCREEN_LOCK_SYS_PUBLISH_FACTORY(_className, _publisher)        \
                                                                            \
    extern "C" mmi_ret _publisher(mmi_event_struct *event)                  \
    {                                                                       \
        _className *factory = VFX_OBJ_GET_INSTANCE(_className);             \
        VappScreenLockKit *kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);   \
        kit->add(factory);                                                  \
        return MMI_RET_OK;                                                  \
    }


/*****************************************************************************
 * Screen Lock Kit Filter Class
 *****************************************************************************/

class VappScreenLockKitFilter : public VfxBase
{
public:
    VappScreenLockKitFilter();

    VappScreenLockKitFilter(
        VfxBool initial
    );

    ~VappScreenLockKitFilter();

public:
    void permit(
        VappScreenLockSrcEnum source
    );

    void forbit(
        VappScreenLockSrcEnum source
    );

    VfxBool isPermitted(
        VappScreenLockSrcEnum source
    ) const;

private:
    enum
    {
        TOTAL_SOURCE_NUM = VAPP_SCREEN_LOCK_SRC_TOTAL
    };

private:
    VfxBool m_permitted[TOTAL_SOURCE_NUM];
};


/*****************************************************************************
 * Screen Lock Kit Class
 *****************************************************************************/

class VappScreenLockKit : public VfxObject
{
    VFX_DECLARE_CLASS(VappScreenLockKit);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappScreenLockKit);

// Constructor / Destructor
public:
    // Default Constructor
    VappScreenLockKit();

public:
    // This function gets the total number of supported screen locks.
    // RETURNS: total number of screen locks.
    VfxS32 getTotalNum(
        const VappScreenLockKitFilter *filter = NULL// [IN] Filter
    );

    // This function gets the ID of all the supported screen locks.
    // RETURNS: total number of screen locks.
    VfxS32 getAllId(
        VappScreenLockId **id,                      // [OUT] Screen Lock ID array
        VfxS32 size,                                // [IN]  Size of the array
        const VappScreenLockKitFilter *filter = NULL// [IN]  Filter
    );

    // This fucntion checks if the screen lock ID is valid.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isIdValid(
        const VappScreenLockId &id,                     // [IN] Screen lock ID
        const VappScreenLockKitFilter *filter = NULL    // [IN] Filter
    );

    // This function creates the screen locks.
    // RETURNS: the created screen lock.
    VappScreenLock *createScreenLock(
        const VappScreenLockId &id,     // [IN] ScreenLock ID
        VfxObject *parentObj            // [IN] Parent object of the screen_lock
    );

    // This function gets the name of the screen lock.
    // RETURNS: Length of the screen lock name
    VfxS32 getName(
        const VappScreenLockId &id,     // [IN]  Screen lock ID
        VfxWChar *string,               // [OUT] String Buffer
        VfxS32 size                     // [IN]  Buffer size in wchar
    );

    // This function creates the screen lock icon.
    // RETURNS: screen lock icon.
    VfxFrame *createIcon(
        const VappScreenLockId &id,     // [IN] Screen lock ID
        VfxObject *parentObj            // [IN] Parent of the screen lock icon
    );

    // This function gets the number of the screenshots for this launcher.
    // RETURNS: Number of screenshots.
    VfxS32 getScreenshotNum(
        const VappScreenLockId &id      // [IN] Screen lock ID
    );

    // This function creates the screenshots for this launcher.
    // RETURNS: Array of the screenshots.
    VfxFrame **createScreenshot(
        const VappScreenLockId &id,     // [IN] Screen lock ID
        VfxObject *parentObj            // [IN] Parent of the snapshot
    );

    // This function releases the screenshot array.
    void releaseScreenshot(
        VfxFrame **screenshot,          // [IN] Screenshot array
        VfxS32 size                     // [IN] Size of the array
    ) const;

// Method
public:
    // This function adds a launcher factory to the kit.
    void add(
        VappScreenLockFactory *factory      // [IN] Screen lock factory
    );

    // This function removes a launcher factory from the kit.
    void remove(
        VappScreenLockFactory *factory      // [IN] Screen lock factory
    );

// Variable
private:
    // Factory list.
    VfxObjList m_factoryList;
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* VAPP_SCREEN_LOCK_KIT_H */

