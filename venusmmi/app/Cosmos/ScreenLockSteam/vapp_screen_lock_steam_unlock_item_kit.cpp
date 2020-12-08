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
 *  vapp_screen_lock_unlock_item_kit.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the unlock item kit.
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
// for __COSMOS_3D_SCREEN_LOCK__
#include "vapp_screen_lock_steam_unlock_item_kit.h"


/*****************************************************************************
 * Unlock Item Kit Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockSteamUnlockItemKit", VappScreenLockSteamUnlockItemKit, VfxObject);

VappScreenLockSteamUnlockItemKit::VappScreenLockSteamUnlockItemKit() :
    m_factory(NULL)
{
    // Do nothing.
}


void VappScreenLockSteamUnlockItemKit::onInit()
{
    VFX_OBJ_CREATE(m_factory, VappScreenLockSteamUnlockItemFactory, this);
}


void VappScreenLockSteamUnlockItemKit::onDeinit()
{
    if (m_factory)
    {
        VFX_OBJ_CLOSE(m_factory);
    }
}


VappScreenLockUnlockItem *VappScreenLockSteamUnlockItemKit::createUnlockItem(
    const VappScreenLockSteamUnlockItemTypeEnum id,
    VfxObject *parentObj)
{
    VFX_ASSERT(m_factory);

    VappScreenLockUnlockItem *unlockItem = m_factory->createUnlockItem(id, parentObj);

    if (!unlockItem)
    {
        return NULL;
    }

    return unlockItem;
}


VappScreenLockSteamUnlockItemTypeEnum VappScreenLockSteamUnlockItemKit::getUnlockItemId(
    const VappScreenLockSteamUnlockItemPos pos)
{
    return m_factory->getUnlockItemId(pos);
}
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
