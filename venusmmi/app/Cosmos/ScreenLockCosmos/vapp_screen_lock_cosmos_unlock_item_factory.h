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
 *  vapp_screen_lock_unlock_item_factory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the unlock item factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_COSMOS_UNLOCK_ITEM_FACTORY_H
#define VAPP_SCREEN_LOCK_COSMOS_UNLOCK_ITEM_FACTORY_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_object.h"   
#include "vfx_class_info.h"
#include "vfx_datatype.h"


/*****************************************************************************
 * Define
 *****************************************************************************/
 
class VappScreenLockUnlockItem;


/*****************************************************************************
 * Enum
 *****************************************************************************/

/*
 * Unlock Item Type:
 */
typedef enum
{
	VAPP_SCREEN_LOCK_TYPE_CAMCODER_CARD,

	VAPP_SCREEN_LOCK_TYPE_CALL_CARD,
	
	VAPP_SCREEN_LOCK_TYPE_UNLOCK_CARD,
	
	VAPP_SCREEN_LOCK_TYPE_MSG_CARD,

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_TOTAL,

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_INVALID
    
} VappScreenLockUnlockItemTypeEnum;


/*
 * Unlock Item Pos:
 */
typedef enum
{
    VAPP_SCREEN_LOCK_UNLOCK_ITEM_LEFT = 0,
        
    VAPP_SCREEN_LOCK_UNLOCK_ITEM_MIDDLE,
    
    VAPP_SCREEN_LOCK_UNLOCK_ITEM_RIGHT
} VappScreenLockUnlockItemPos;

/*****************************************************************************
 * Unlock Item Factory
 *****************************************************************************/

class VappScreenLockUnlockItemFactory : public VfxObject
{
    VFX_DECLARE_CLASS(VappScreenLockUnlockItemFactory);

public:
    // This block defines the class used to register the unlock item.

    class createTableEntry : public VfxBase
    {
    public:
        typedef VappScreenLockUnlockItem *(*createFunc)(VfxObject *parentObj);

    // Constructor / Destructor
    public:
        // Default constructor
        createTableEntry() :
            m_type(VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_INVALID),
            m_create(NULL)
        {
            // Do nothing.
        }

        // Construct a entry with the type and create function.
        createTableEntry(VappScreenLockUnlockItemTypeEnum type, createFunc create) :
            m_type(type),
            m_create(create)
        {
            // Do nothing.
        }

    // Variable
    public:
        // Type of the unlock item
        VappScreenLockUnlockItemTypeEnum m_type;

        // Create function for such unlock item
        createFunc m_create;
    };

    class configTableEntry : public VfxBase
    {
    // Constructor / Destructor
    public:
        // Default constructor
        configTableEntry() :
            m_type(VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_INVALID)
        {
            // Do nothing.
        }

        // Construct a entry with the type and create function.
        configTableEntry(VappScreenLockUnlockItemTypeEnum type) :
            m_type(type)
        {
            // Do nothing.
        }

    // Variable
    public:
        // Type of the unlock item
        VappScreenLockUnlockItemTypeEnum m_type;
    };


// Constructor / Destructor
public:
    VappScreenLockUnlockItemFactory();

// Override
public:
    virtual VappScreenLockUnlockItem *createUnlockItem(
        const VappScreenLockUnlockItemTypeEnum id,
        VfxObject *parentObj
    );

    VappScreenLockUnlockItemTypeEnum getUnlockItemId(
        const VappScreenLockUnlockItemPos pos);

// Variable
private:
    // Table for the unlock item registration.
    static const createTableEntry s_createTbl[];

    // Size of the table.
    static const VfxS32 s_sizeOfTbl;

    // Table for unlock item order customization
    static const configTableEntry s_configTbl[];

};
#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__*/
#endif /* VAPP_SCREEN_LOCK_COSMOS_UNLOCK_ITEM_FACTORY_H */
