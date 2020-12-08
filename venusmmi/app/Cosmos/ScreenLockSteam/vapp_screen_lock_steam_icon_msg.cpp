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
 *  vapp_steam_screen_lock_icon_msg.cpp
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
#include "vapp_screen_lock_steam_icon_msg.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_steam_def.h"

// 3D header
#include "vfx_asset_loader.h"
#include "vfx_world.h"
#include "vfx_material.h"
#include "vfx_mesh.h"
#include "vfx_light.h"
#include "vfx_animation.h"

#include "vapp_msg_gprot.h"
// for sse 
#include "vfx_adp_sse.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "SmsSrvGprot.h"
#include "MmsSrvGprot.h"
#include "WAPPushSrvGprots.h"
#include "ProvBoxSrvGProt.h" /* mmi_provboxui_get_total_unread_msg_num */

#ifdef __cplusplus
}
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
VAPP_SCREEN_LOCK_UNLOCK_ITEM_IMPLEMENT_CLASS(VappSteamScreenLockIconMsg, VappSteamScreenLockIcon);


VappSteamScreenLockIconMsg::VappSteamScreenLockIconMsg():
    m_isNeedRepeatRot(VFX_FALSE),
    m_meshIcon(NULL),
    m_oriMaterial(NULL),
    m_colMaterial(NULL),
    m_tlRotateIcon(NULL),
    m_tlShakeIcon(NULL),
    m_tlRef(NULL)
{  
}


void VappSteamScreenLockIconMsg::onInit()
{
    VappSteamScreenLockIcon::onInit();
    
    // create and load scene graph
    VfxWorld *world;
    VFX_OBJ_CREATE(world, VfxWorld, this);
    //VfxAssetLoader::loadSceneBegin(world, VFX_WSTR("d:\\test\\unlockIcon\\mail\\Icon_Lock.scn"));
    VfxAssetLoader::loadSceneBegin(world, VAPP_STEAM_SCREEN_LOCK_SCN_MAIL_ICON);
    VfxObject3D *obj = VfxAssetLoader::findObjByName(VFX_STR("Icon_Mail-node"));
    m_meshIcon = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);
    m_meshIcon->setScale(0.75, 0.75, 0.75);

    m_oriMaterial = m_meshIcon->getMaterial(0);
    VFX_OBJ_CREATE(m_colMaterial, VfxMaterial, this);
    VfxAssetLoader::loadMaterial(m_colMaterial, V3D_GEN_ID__DEFAULT_3D_SCRLOCK_ICON_MAIL_C_TEX_3DICON_MTL);

    // after loadSceneEnd, findObjByName will not work
    VfxAssetLoader::loadSceneEnd();

    // create and load shake keyframe timeline
    VFX_OBJ_CREATE(m_tlShakeIcon, VfxKeyframeTimeline, world);
    VfxAssetLoader::loadKeyframe(m_tlShakeIcon, VAPP_STEAM_SCREEN_LOCK_TIMELINE_SHAKE);
    m_tlShakeIcon->setTarget(m_meshIcon);
    m_tlShakeIcon->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

    // create and load keyframe timeline
    VFX_OBJ_CREATE(m_tlRotateIcon, VfxKeyframeTimeline, world);
    //VfxAssetLoader::loadKeyframe(m_tlRotateIcon, VFX_WSTR("d:\\test\\unlockIcon\\mail\\Icon_Mail_Icon_Mail-node-rz.tl"));
    VfxAssetLoader::loadKeyframe(m_tlRotateIcon, VAPP_STEAM_SCREEN_LOCK_TIMELINE_SPIN);
    

    m_tlRotateIcon->setTarget(m_meshIcon);

    VFX_OBJ_CREATE(m_tlRef, VfxFloatTimeline, this);
    m_tlRef->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_tlRef->setTarget(this);
    m_tlRef->setDuration(1000);
    m_tlRef->setFromValue(0.0f);
    m_tlRef->setToValue(1.0f);
    m_tlRef->m_signalStopped.connect(this, &VappSteamScreenLockIconMsg::onRefTlStoppod);

    m_tlRotateIcon->setTimelineTime(m_tlRef);

    reloadMaterial();
    setWorld(world);

    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH,  &VappSteamScreenLockIconMsg::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappSteamScreenLockIconMsg::eventHandler, this);
}


void VappSteamScreenLockIconMsg::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappSteamScreenLockIconMsg::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappSteamScreenLockIconMsg::eventHandler, this);

    VFX_OBJ_CLOSE(m_oriMaterial);
    VFX_OBJ_CLOSE(m_colMaterial);
    VappSteamScreenLockIcon::onDeinit();
}


VfxU32 VappSteamScreenLockIconMsg::getUnreadMsgNum()
{
    VfxU32 count = 0;

    /* Get SMS unread count */
    count += srv_sms_get_unread_sms_num();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, count, 200);

#ifdef __MMI_MMS_2__
    /* Get MMS unread count */
    VfxS32 result;
    srv_mms_get_msg_count_struct msg_count_req;

    vfx_sys_mem_zero(&msg_count_req, sizeof(srv_mms_get_msg_count_struct));

    msg_count_req.count = 1;
    msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;

    result = srv_mms_get_msg_count(&msg_count_req);

    if (SRV_MMS_RESULT_OK == result)
    {
        count += msg_count_req.rsp_tb[0];
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, msg_count_req.rsp_tb[0], 201);
    }
#endif

#ifdef WAP_SUPPORT
    /* Get Push unread count */
    count += srv_get_push_unread_count();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, srv_get_push_unread_count(), 202);
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    /* Get Prov unread count */
    count += srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_GET_UNREAD_MSG_NUM, srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL), 203);
#endif

    return count;
}


void VappSteamScreenLockIconMsg::onUnlocked()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_ON_UNLOCKED, 200);
    VappMsgLaunchStruct para;
    
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_LOCK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER); 
    if(getUnreadMsgNum())
    {
        para.mode = VAPP_MSG_LAUNCH_INBOX;
        vapp_msg_launch(&para, sizeof(para));
    }
    else
    {
        para.mode = VAPP_MSG_LAUNCH_NORMAL;
        vapp_msg_launch(&para, sizeof(para));
    }
}


void VappSteamScreenLockIconMsg::onRefTlStoppod(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(m_isNeedRepeatRot)
    {
        m_tlRef->start();
    }
    else
    {
        const VfxQuaternionf rot = m_meshIcon->getRotation();
        m_meshIcon->setRotation(VfxQuaternionf(1, 1, 1, 1));
        m_meshIcon->setRotation(rot);
        if(getUnreadMsgNum())
        {
            m_tlShakeIcon->start();
        }
    }
}


void VappSteamScreenLockIconMsg::onStartSpinAnimation()
{
    m_meshIcon->setScale(0.9, 0.9, 0.9);
    
    m_isNeedRepeatRot = VFX_TRUE;
    m_tlShakeIcon->stop();

    if(!m_tlRef->getIsEnabled())
    {
        m_tlRef->start();
    }
}


void VappSteamScreenLockIconMsg::onStopSpinAnimation()
{
    m_meshIcon->setScale(0.75, 0.75, 0.75);
    m_isNeedRepeatRot = VFX_FALSE;
}


void VappSteamScreenLockIconMsg::reloadMaterial()
{
    VfxU32 miss = getUnreadMsgNum();

    if(miss)
    {
        m_meshIcon->setMaterial(0, m_colMaterial);
        m_tlShakeIcon->start();
    }
    else
    {
        m_meshIcon->setMaterial(0, m_oriMaterial);
        m_tlShakeIcon->stop();
    }
}


mmi_ret VappSteamScreenLockIconMsg::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_MSG_CARD_EVENT_HANDLER, event->evt_id, 200);
    VappSteamScreenLockIconMsg* icon = (VappSteamScreenLockIconMsg *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_UM_NOTIFY_READY:
            icon->reloadMaterial();
            break;
            
        case EVT_ID_SRV_UM_NOTIFY_REFRESH: 
            icon->reloadMaterial();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
