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
#include "vapp_screen_lock_app_def.h"

#ifdef __COSMOS_3D_SCREEN_LOCK__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_screen_lock_steam_unlock_item_factory.h"
#include "vapp_screen_lock_steam_icon_call.h"
#include "vapp_screen_lock_steam_icon_msg.h"
#include "vapp_screen_lock_steam_icon_unlock.h"
#include "vapp_screen_lock_steam_icon_camcoder.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

/*
 * Macro to add a unlock item .
 */
#define VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_ADD(_id, _class)   \
    VappScreenLockSteamUnlockItemFactory::createTableEntry(      \
        _id,                                                \
        _class::createUnlockItem)

#define VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_END()              \
    VappScreenLockSteamUnlockItemFactory::createTableEntry(      \
        VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_TYPE_INVALID,          \
        NULL)


/*****************************************************************************
 * Configuration
 *****************************************************************************/

const VappScreenLockSteamUnlockItemFactory::configTableEntry
VappScreenLockSteamUnlockItemFactory::s_configTbl[] =
{
    VAPP_SCREEN_LOCK_STEAM_TYPE_3D_CALL_ICON,

    VAPP_SCREEN_LOCK_STEAM_TYPE_3D_UNLOCK_ICON,

    VAPP_SCREEN_LOCK_STEAM_TYPE_3D_MSG_ICON,

    // Enable camcorder card might cause OOM problem with other app, since it used most of ASM pool size.
    //VAPP_SCREEN_LOCK_STEAM_TYPE_3D_CAMCODER_ICON,

    VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_TYPE_INVALID
};


const VappScreenLockSteamUnlockItemFactory::createTableEntry
VappScreenLockSteamUnlockItemFactory::s_createTbl[] =
{
    VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_STEAM_TYPE_3D_CAMCODER_ICON,
        VappSteamScreenLockIconCamcoder),

    VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_STEAM_TYPE_3D_CALL_ICON,
        VappSteamScreenLockIconCall),

    VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_STEAM_TYPE_3D_UNLOCK_ICON,
        VappSteamScreenLockIconUnlock),

    VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_ADD(
        VAPP_SCREEN_LOCK_STEAM_TYPE_3D_MSG_ICON,
        VappSteamScreenLockIconMsg),

    VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_CFG_END()
};


const VfxS32 VappScreenLockSteamUnlockItemFactory::s_sizeOfTbl =
    sizeof(VappScreenLockSteamUnlockItemFactory::s_createTbl) /
    sizeof(VappScreenLockSteamUnlockItemFactory::createTableEntry) - 1;


/*****************************************************************************
 * Unlock Item Factory
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockSteamUnlockItemFactory", VappScreenLockSteamUnlockItemFactory, VfxObject);

VappScreenLockSteamUnlockItemFactory::VappScreenLockSteamUnlockItemFactory()
{
    // Assert if the configuration of the widgets is not correct.
    VFX_ASSERT(s_sizeOfTbl == VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_TYPE_TOTAL);
}


VappScreenLockUnlockItem *VappScreenLockSteamUnlockItemFactory::createUnlockItem(
    const VappScreenLockSteamUnlockItemTypeEnum id,
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


VappScreenLockSteamUnlockItemTypeEnum VappScreenLockSteamUnlockItemFactory::getUnlockItemId(
    const VappScreenLockSteamUnlockItemPos pos)
{
    VFX_ASSERT(s_configTbl[pos].m_type != VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_TYPE_INVALID);
    return s_configTbl[pos].m_type;
}
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
