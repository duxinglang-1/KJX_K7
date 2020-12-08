/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWRE")
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_steam_screen_lock_card.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vapp_screen_lock_def.h"

#ifdef __COSMOS_3D_SCREEN_LOCK__
#include "vapp_screen_lock_steam_icon.h"
#include "mmi_rp_vapp_screen_lock_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_VIRTUAL_CLASS("VappSteamScreenLockIcon", VappSteamScreenLockIcon, VappScreenLockUnlockItem);


VappSteamScreenLockIcon::VappSteamScreenLockIcon()
{  
}


void VappSteamScreenLockIcon::onInit()
{
    VfxControl::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);
    setSize(VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_WIDTH,
            VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_HEIGHT);
}


void VappSteamScreenLockIcon::onDeinit()
{
    VfxControl::onDeinit();

}


void VappSteamScreenLockIcon::setUnlocked()
{
    onUnlocked();
}


void VappSteamScreenLockIcon::onUnlocked()
{
}


void VappSteamScreenLockIcon::startSpinAnimation()
{
    onStartSpinAnimation();
}


void VappSteamScreenLockIcon::onStartSpinAnimation()
{
}


void VappSteamScreenLockIcon::stopSpinAnimation()
{
    onStopSpinAnimation();
}


void VappSteamScreenLockIcon::onStopSpinAnimation()
{
}


void VappSteamScreenLockIcon::startShakeAnimation()
{
    onStartShakeAnimation();
}


void VappSteamScreenLockIcon::onStartShakeAnimation()
{
}


void VappSteamScreenLockIcon::stopShakeAnimation()
{
    onStopShakeAnimation();
}


void VappSteamScreenLockIcon::onStopShakeAnimation()
{
}


VfxBool VappSteamScreenLockIcon::onPenInput(VfxPenEvent &event)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ICON_ON_PEN_INPUT, event.type, 200);
    // dispatch event directly
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_signalDragStart.emit(this, event);
            return VFX_TRUE;
        
        case VFX_PEN_EVENT_TYPE_MOVE:
            m_signalDrag.emit(this, event);
            return VFX_TRUE;

        case VFX_PEN_EVENT_TYPE_UP:
            m_signalDragEnd.emit(this, event);
            return VFX_TRUE;

        case VFX_PEN_EVENT_TYPE_ABORT:
            m_signalDragAbort.emit(this, event);
            return VFX_TRUE;
            
        default:
            break;
    }
    return VfxControl::onPenInput(event);
}


void VappSteamScreenLockIcon::setIconId(VfxS32 id)
{
    m_iconId = id;
}


VfxS32 VappSteamScreenLockIcon::getIconId()
{
    return m_iconId;
}
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
