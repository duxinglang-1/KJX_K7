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
 *  vapp_steam_screen_lock_icon_camcoder.cpp
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
#include "vapp_screen_lock_steam_icon_camcoder.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_steam_def.h"

// 3D header
#include "vfx_asset_loader.h"
#include "vfx_material.h"
#include "vfx_world.h"
#include "vfx_mesh.h"
#include "vfx_light.h"
#include "vfx_animation.h"
 
// for sse 
#include "vfx_adp_sse.h"

#if defined(__LOW_COST_SUPPORT_COMMON__)
#include "vapp_camco_express_gprot.h"
#else
#include "vapp_camco_gprot.h"
#endif  


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

VAPP_SCREEN_LOCK_UNLOCK_ITEM_IMPLEMENT_CLASS(VappSteamScreenLockIconCamcoder, VappSteamScreenLockIcon);

VappSteamScreenLockIconCamcoder::VappSteamScreenLockIconCamcoder():
    m_isNeedRepeatRot(VFX_FALSE),
    m_meshIcon(NULL),
    m_oriMaterial(NULL), 
    m_tlRotateIcon(NULL), 
    m_tlRef(NULL)
{  
}


void VappSteamScreenLockIconCamcoder::onInit()
{
    VappSteamScreenLockIcon::onInit();
    
    // create and load scene graph
    VfxWorld *world;
    VFX_OBJ_CREATE(world, VfxWorld, this);
    VfxAssetLoader::loadSceneBegin(world, VAPP_STEAM_SCREEN_LOCK_SCN_CAMCODER_ICON);
    VfxObject3D *obj = VfxAssetLoader::findObjByName(VFX_STR("Icon_Camera-node"));
    m_meshIcon = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);
    m_meshIcon->setScale(0.75, 0.75, 0.75);
 
    VfxAssetLoader::loadSceneEnd(); 
 
    // create and load rotate keyframe timeline
    VFX_OBJ_CREATE(m_tlRotateIcon, VfxKeyframeTimeline, world);
    VfxAssetLoader::loadKeyframe(m_tlRotateIcon, VAPP_STEAM_SCREEN_LOCK_TIMELINE_SPIN);
    m_tlRotateIcon->setTarget(m_meshIcon);

    VFX_OBJ_CREATE(m_tlRef, VfxFloatTimeline, this);
    m_tlRef->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_tlRef->setTarget(this);
    m_tlRef->setDuration(1000);
    m_tlRef->setFromValue(0.0f);
    m_tlRef->setToValue(1.0f);
    m_tlRef->m_signalStopped.connect(this, &VappSteamScreenLockIconCamcoder::onRefTlStoppod);

    m_tlRotateIcon->setTimelineTime(m_tlRef);

    setWorld(world);
 }


void VappSteamScreenLockIconCamcoder::onDeinit()
{ 
    VFX_OBJ_CLOSE(m_oriMaterial); 
    VappSteamScreenLockIcon::onDeinit();
}


void VappSteamScreenLockIconCamcoder::onUnlocked()
{
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_LOCK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER); 
    vapp_camco_launch_app();
 
} 


void VappSteamScreenLockIconCamcoder::onRefTlStoppod(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(m_isNeedRepeatRot)
    {
        m_tlRef->start();
    }
}


void VappSteamScreenLockIconCamcoder::onStartSpinAnimation()
{
    m_meshIcon->setScale(0.9, 0.9, 0.9);
    m_isNeedRepeatRot = VFX_TRUE; 
    
    if(!m_tlRef->getIsEnabled())
    {
        m_tlRef->start();
    }
}


void VappSteamScreenLockIconCamcoder::onStopSpinAnimation()
{
    m_meshIcon->setScale(0.75, 0.75, 0.75);
    m_isNeedRepeatRot = VFX_FALSE;
} 
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
