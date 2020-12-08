/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_steam_screen_lock_icon.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_STEAM_ICON_H__
#define __VAPP_SCREEN_LOCK_STEAM_ICON_H__

#ifdef __COSMOS_3D_SCREEN_LOCK__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_screen_lock_unlock_item.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_WIDTH     184
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_HEIGHT    222
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_WIDTH     122
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_HEIGHT    135
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_WIDTH      61
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_HEIGHT     86
#else
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_WIDTH     184
#define VAPP_STEAM_SCREEN_LOCK_ICON_SCENE_HEIGHT    222
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappSteamScreenLockIcon : public VappScreenLockUnlockItem
{
    VFX_DECLARE_CLASS(VappSteamScreenLockIcon);

public:
    VappSteamScreenLockIcon();

// Method
public:
    void setUnlocked();
    void startSpinAnimation();
    void startShakeAnimation();
    void stopSpinAnimation();
    void stopShakeAnimation();
    void setIconId(VfxS32 id);
    VfxS32 getIconId();

// Overridable
protected:
    virtual void    onUnlocked();
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onStartSpinAnimation();
    virtual void onStartShakeAnimation();
    virtual void onStopSpinAnimation();
    virtual void onStopShakeAnimation();

// Signal
public:
    VfxSignal2 <VappSteamScreenLockIcon *, const VfxPenEvent& > m_signalDragStart;
    VfxSignal2 <VappSteamScreenLockIcon *, const VfxPenEvent&  > m_signalDrag;
    VfxSignal2 <VappSteamScreenLockIcon *, const VfxPenEvent&  > m_signalDragEnd;
    VfxSignal2 <VappSteamScreenLockIcon *, const VfxPenEvent&  > m_signalDragAbort;

// Variable
private:
    VfxS32 m_iconId;

};
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
#endif /* __VAPP_SCREEN_LOCK_STEAM_ICON_H__ */

