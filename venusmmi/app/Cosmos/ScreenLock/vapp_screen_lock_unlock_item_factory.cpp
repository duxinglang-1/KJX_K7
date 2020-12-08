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
 *  vapp_screen_lock_unlock_item_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the unlock item factory.
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

// for __COSMOS_3D_SCREEN_LOCK__
#include "vapp_screen_lock_def.h"

#include "vapp_screen_lock_unlock_item_factory.h"

#ifdef __COSMOS_3D_SCREEN_LOCK__
#include "vapp_steam_screen_lock_icon_call.h"
#include "vapp_steam_screen_lock_icon_msg.h"
#include "vapp_steam_screen_lock_icon_unlock.h"
#include "vapp_steam_screen_lock_icon_camcoder.h"
#else
#include "vapp_screen_lock_call_card.h"
#include "vapp_screen_lock_msg_card.h"
#include "vapp_screen_lock_unlock_card.h"
#include "vapp_screen_lock_camcoder_card.h"
#endif


/*****************************************************************************
 * Define
 *****************************************************************************/

/*
 * Macro to add a unlock item .
 */
#define VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(_id, _class)   \
    VappScreenLockUnlockItemFactory::createTableEntry(      \
        _id,                                                \
        _class::createUnlockItem)

#define VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_END()              \
    VappScreenLockUnlockItemFactory::createTableEntry(      \
        VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_INVALID,          \
        NULL)


/*****************************************************************************
 * Configuration
 *****************************************************************************/

const VappScreenLockUnlockItemFactory::configTableEntry
VappScreenLockUnlockItemFactory::s_configTbl[] =
{
#ifdef __COSMOS_3D_SCREEN_LOCK__

    VAPP_SCREEN_LOCK_TYPE_3D_CALL_ICON,

    VAPP_SCREEN_LOCK_TYPE_3D_UNLOCK_ICON,

    VAPP_SCREEN_LOCK_TYPE_3D_MSG_ICON,

    // Enable camcorder card might cause OOM problem with other app, since it used most of ASM pool size.
    //VAPP_SCREEN_LOCK_TYPE_3D_CAMCODER_ICON,

#else

    VAPP_SCREEN_LOCK_TYPE_CALL_CARD,

    VAPP_SCREEN_LOCK_TYPE_UNLOCK_CARD,

    VAPP_SCREEN_LOCK_TYPE_MSG_CARD,

    // Enable camcorder card might cause OOM problem with other app, since it used most of ASM pool size.
    //VAPP_SCREEN_LOCK_TYPE_CAMCODER_CARD,
    

#endif

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_INVALID
};


const VappScreenLockUnlockItemFactory::createTableEntry
VappScreenLockUnlockItemFactory::s_createTbl[] =
{
#ifdef __COSMOS_3D_SCREEN_LOCK__
    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_3D_CAMCODER_ICON,
        VappSteamScreenLockIconCamcoder),

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_3D_CALL_ICON,
        VappSteamScreenLockIconCall),

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_3D_UNLOCK_ICON,
        VappSteamScreenLockIconUnlock),

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_3D_MSG_ICON,
        VappSteamScreenLockIconMsg),
#else
    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_CAMCODER_CARD,
        VappScreenLockCamcoderCard),

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_CALL_CARD,
        VappScreenLockCallCard),

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_UNLOCK_CARD,
        VappScreenLockUnlockCard),

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_TYPE_MSG_CARD,
        VappScreenLockMsgCard),
#endif

    VAPP_SCREEN_LOCK_UNLOCK_ITEM_CFG_END()
};


const VfxS32 VappScreenLockUnlockItemFactory::s_sizeOfTbl =
    sizeof(VappScreenLockUnlockItemFactory::s_createTbl) /
    sizeof(VappScreenLockUnlockItemFactory::createTableEntry) - 1;


/*****************************************************************************
 * Unlock Item Factory
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockUnlockItemFactory", VappScreenLockUnlockItemFactory, VfxObject);

VappScreenLockUnlockItemFactory::VappScreenLockUnlockItemFactory()
{
    // Assert if the configuration of the widgets is not correct.
    VFX_ASSERT(s_sizeOfTbl == VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_TOTAL);
}


VappScreenLockUnlockItem *VappScreenLockUnlockItemFactory::createUnlockItem(
    const VappScreenLockUnlockItemTypeEnum id,
    VfxObject *parentObj)
{
    VfxS32 i;

    // Find the entry corresponding to this unlock item.
    for (i = 0; i < s_sizeOfTbl; i++)
    {
        if (s_createTbl[i].m_type == id)
        {
            break;
        }
    }

    if (i == s_sizeOfTbl)
    {
        return NULL;    // Not found.
    }

    // Make sure the create function is present.
    VFX_ASSERT(s_createTbl[i].m_create);

    return (VappScreenLockUnlockItem *)s_createTbl[i].m_create(parentObj);
}


VappScreenLockUnlockItemTypeEnum VappScreenLockUnlockItemFactory::getUnlockItemId(
    const VappScreenLockUnlockItemPos pos)
{
    VFX_ASSERT(s_configTbl[pos].m_type != VAPP_SCREEN_LOCK_UNLOCK_ITEM_TYPE_INVALID);
    return s_configTbl[pos].m_type;
}
