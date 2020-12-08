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
 *  vapp_screen_lock_native_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the native screen lock factory.
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

#ifndef VAPP_SCREEN_LOCK_NATIVE_FACTORY_H
#define VAPP_SCREEN_LOCK_NATIVE_FACTORY_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_factory.h"


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Macro to populate a native screen lock.
 */
#define VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(_className, _type, _publisher)  \
                                                                            \
    extern "C" mmi_ret _publisher(mmi_event_struct *event)                  \
    {                                                                       \
        VappScreenLockNativeFactory *factory;                               \
        factory = VFX_OBJ_GET_INSTANCE(VappScreenLockNativeFactory);        \
        factory->add(_type, _className::createScreenLock);                  \
        return MMI_RET_OK;                                                  \
    }


/*****************************************************************************
 * Native Widget Factory
 *****************************************************************************/

class VappScreenLockNativeFactory : public VappScreenLockFactory
{
    VAPP_SCREEN_LOCK_FACTORY_DECLARE_CLASS(VappScreenLockNativeFactory);

//
// This block defines the class used to register the native screen lock.
//
private:
    typedef VappScreenLock *(*CreateFunc)(VfxObject *parentObj);

    struct ConfigEntry
    {
        // Type of the screen lock.
        VappScreenLockTypeEnum m_type;

        // Create function for this screen lock.
        CreateFunc m_create;
    };

    enum
    {
        // Max number of entries in the table.
        MAX_CONFIG_SIZE = 8
    };

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockNativeFactory();

// Method
public:
    // This function adds the specified screen lock to the native factory.
    void add(
        VappScreenLockTypeEnum type,    // [IN] Type
        CreateFunc createFunc           // [IN] Create function
    );

// Override
public:
    // Please refer to VappScreenLockFactory.
    virtual VappScreenLockSrcEnum getSource() const
    {
        return VAPP_SCREEN_LOCK_SRC_NATIVE;
    }

    // Please refer to VappScreenLockFactory.
    virtual VfxS32 getTotalNum() const
    {
        return s_count;
    }

    // Please refer to VappScreenLockFactory.
    virtual VfxS32 getAllId(
        VappScreenLockId **id,
        VfxS32 size
    ) const;

    // Please refer to VappScreenLockFactory.
    virtual VappScreenLock *createScreenLock(
        const VappScreenLockId &id,
        VfxObject *parentObj
    );

// Variable
private:
    // Configuration table
    static ConfigEntry s_table[];

    // Number of entries in the table.
    static VfxS32 s_count;
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* VAPP_SCREEN_LOCK_NATIVE_FACTORY_H */

