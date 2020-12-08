/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *  vapp_screen_lock_steam.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the steam screen lock class
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
#include "vfx_uc_include.h"
#include "vapp_screen_lock_native_factory.h"
#include "vapp_screen_lock_steam.h"

#include "vapp_screen_lock_main.h"
//#include "vapp_steam_screen_lock_screen.h"
#include "vapp_screen_lock_steam_frame.h"
#include "vapp_screen_lock_steam_time.h"
#include "vapp_screen_lock_steam_owner_draw.h"
#include "vapp_screen_lock_steam_icon_call.h"
#include "vapp_screen_lock_steam_icon_unlock.h"
#include "vapp_screen_lock_steam_icon_msg.h"
#include "vapp_screen_lock_steam_time.h"
#include "vapp_screen_lock_steam_unlock_item_kit.h"

#include "vapp_wallpaper_kit.h"
#include "vapp_widget_music_player.h"
#include "vapp_ncenter_gprot.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_steam_def.h"
#include "vapp_screen_lock_gprot.h"
#include "vfx_adp_device.h"

// for wallpaper setting api
#include "vapp_wallpaper_setting_method_gprot.h"

// 3D header
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_polygon_mode.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_stencil.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_render_buffer.h"
#include "vfx_render_target.h"
#include "vfx_texture.h"
#include "vfx_asset_loader.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "PhoneSetupGprots.h"
#include "GpioSrvGProt.h"
#include "ShutdownSrvGprot.h"
#include "GlobalResDef.h"
#include "AppMgrSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "gpiosrvgprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_trc.h"

// for fm radio panel
#include "vapp_widget_fm_radio.h"

// memory context for screen lock
#include "vapp_platform_context.h"

#include "mmi_rp_srv_status_icons_def.h"

// To be removed
#include "ScrLockerGprot.h"
#include "ScrSaverGprot.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Function
 *****************************************************************************/


/***************************************************************************** 
 * Screen Lock Steam Class
 *****************************************************************************/

VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(
    VappScreenLockSteam,
    VAPP_SCREEN_LOCK_TYPE_STEAM,
    VappScreenLockSteamPublisher);

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockSteam, VappScreenLock);


VappScreenLockSteam::VappScreenLockSteam():
    m_isAllowFlowWaterDrop(VFX_FALSE),
    m_numFlowWaterDrop(0),
    m_freeFallTime(0),
    m_freeFallDurTime(0),
    m_freeFallHeight(0),
    m_wallpaper(NULL),
    m_widowEdge(NULL),
    m_edgetEffectFrame(NULL),
    m_lockFrame(NULL),
    m_timeArea(NULL),
    m_tlSlideDummyPosY(NULL),
    m_lockState(STATE_NORMAL)
{
    m_numIcons = 3;
    m_ffectFrame[0] = NULL;
    m_ffectFrame[1] = NULL;
    m_ffectFrame[2] = NULL;

    m_icon[0] = NULL;
    m_icon[1] = NULL;
    m_icon[2] = NULL;
}


VappScreenLockId VappScreenLockSteam::getId() const
{
    return VappScreenLockId(VAPP_SCREEN_LOCK_SRC_NATIVE, 
                            VAPP_SCREEN_LOCK_TYPE_STEAM);
}


VfxS32 VappScreenLockSteam::getName(
    VfxWChar *string,
    VfxS32 size) const
{
    VFX_ASSERT(string && size > 0);
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_SCREEN_LOCK_STEAM_SETTING_NAME);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);
    return vfx_sys_wcslen(string);

}


VfxFrame *VappScreenLockSteam::createIcon(
    VfxObject *parentObj)
{
   
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_SCREEN_LOCK_STEAM_SETTING_ICON);

    return icon;

}


VfxS32 VappScreenLockSteam::getScreenshotNum() const
{
    return 1;
}


VfxFrame **VappScreenLockSteam::createScreenshot(VfxObject *parentObj) const
{
    VfxFrame **screenshot;

    VFX_ALLOC_MEM(screenshot, getScreenshotNum(), parentObj);
    
    VFX_OBJ_CREATE(screenshot[0], VfxImageFrame, parentObj);
    ((VfxImageFrame*)(screenshot[0]))->setResId(IMG_ID_VAPP_SCREEN_LOCK_STEAM_SETTING_SNAPSHOT);
    return screenshot;
}


VfxBool VappScreenLockSteam::onGetStatusBarTranslucent()
{
    return VFX_TRUE;
}


VfxResId VappScreenLockSteam::onGetStatusBarBg()
{
    return IMG_ID_VAPP_STEAM_SCREEN_LOCK_STATUS_BAR_BG;
}


void VappScreenLockSteam::onCreateView()
{ 

    #if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    m_unlockDistance = getSize().height/2;

    // unlock screen bg
    initWallpaper();

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    VFX_OBJ_CREATE(m_dummyFrame, VfxFrame, this);
    m_dummyFrame->setSize(getSize());

    VFX_OBJ_CREATE(m_lockFrame, VappSteamScreenLockFrame, this);
    m_lockFrame->setSize(getSize());
    m_dummyFrame->addChildFrame(m_lockFrame);

    // Time and Operator area
    VFX_OBJ_CREATE(m_timeArea, VappSteamScreenLockTime, this);
    VfxSize size = VfxSize(getSize().width, VAPP_STEAM_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT);
    m_timeArea->setSize(size);
    m_timeArea->setAnchor(0.5, 1.0);
    m_timeArea->setPos(getSize().width/2, getSize().height/2);
    m_timeArea->setIsUnhittable(VFX_TRUE);
    m_dummyFrame->addChildFrame(m_timeArea);

    // create effect frame
    VFX_OBJ_CREATE(m_ffectFrame[0], VfxImageFrame, this);
    m_ffectFrame[0]->setResId(IMG_ID_VAPP_STEAM_SCREEN_LOCK_HALO);
    m_ffectFrame[0]->setPos(getSize().width/2 - VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP, VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y);
    m_ffectFrame[0]->setAnchor(0.5, 0.5);
    m_ffectFrame[0]->setAutoAnimate(VFX_TRUE);
    m_ffectFrame[0]->setOpacity(0);
    m_dummyFrame->addChildFrame(m_ffectFrame[0]);

    VFX_OBJ_CREATE(m_ffectFrame[1], VfxImageFrame, this);
    m_ffectFrame[1]->setResId(IMG_ID_VAPP_STEAM_SCREEN_LOCK_HALO);
    m_ffectFrame[1]->setPos(getSize().width/2, VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y);
    m_ffectFrame[1]->setAnchor(0.5, 0.5);
    m_ffectFrame[1]->setAutoAnimate(VFX_TRUE);
    m_ffectFrame[1]->setOpacity(0);
    m_dummyFrame->addChildFrame(m_ffectFrame[1]);

    VFX_OBJ_CREATE(m_ffectFrame[2], VfxImageFrame, this);
    m_ffectFrame[2]->setResId(IMG_ID_VAPP_STEAM_SCREEN_LOCK_HALO);
    m_ffectFrame[2]->setPos(getSize().width/2 + VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP, VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y);
    m_ffectFrame[2]->setAnchor(0.5, 0.5);
    m_ffectFrame[2]->setAutoAnimate(VFX_TRUE);
    m_ffectFrame[2]->setOpacity(0);
    m_dummyFrame->addChildFrame(m_ffectFrame[2]);

    //
    // Create unlock item.
    //

    VFX_ASSERT(!m_icon[0]); // to detect memory leak.
    m_icon[0] = createUnlockItem(VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_LEFT, m_lockFrame);
    m_icon[0]->setPos(getSize().width/2 - VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP, VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y);
    m_icon[0]->setAnchor(0.5, 0.5);
    m_icon[0]->m_signalDragStart.connect(this, &VappScreenLockSteam::onIconDragStartHandler); 
    m_icon[0]->m_signalDrag.connect(this, &VappScreenLockSteam::onIconDragHandler); 
    m_icon[0]->m_signalDragEnd.connect(this, &VappScreenLockSteam::onIconDragEndHandler); 
    m_icon[0]->m_signalDragAbort.connect(this, &VappScreenLockSteam::onIconDragAbortHandler); 
    m_icon[0]->setIconId(0);
    m_dummyFrame->addChildFrame(m_icon[0]);

    VFX_ASSERT(!m_icon[1]); // to detect memory leak.
    m_icon[1] = createUnlockItem(VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_MIDDLE, m_lockFrame);
    m_icon[1]->setPos(getSize().width/2, VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y);
    m_icon[1]->setAnchor(0.5, 0.5);
    m_icon[1]->m_signalDragStart.connect(this, &VappScreenLockSteam::onIconDragStartHandler); 
    m_icon[1]->m_signalDrag.connect(this, &VappScreenLockSteam::onIconDragHandler); 
    m_icon[1]->m_signalDragEnd.connect(this, &VappScreenLockSteam::onIconDragEndHandler); 
    m_icon[1]->m_signalDragAbort.connect(this, &VappScreenLockSteam::onIconDragAbortHandler); 
    m_icon[1]->setIconId(1);
    m_dummyFrame->addChildFrame(m_icon[1]);

    VFX_ASSERT(!m_icon[2]); // to detect memory leak.
    m_icon[2] = createUnlockItem(VAPP_SCREEN_LOCK_STEAM_UNLOCK_ITEM_RIGHT, m_lockFrame);
    m_icon[2]->setPos(getSize().width/2 + VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP, VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y);
    m_icon[2]->setAnchor(0.5, 0.5);
    m_icon[2]->m_signalDragStart.connect(this, &VappScreenLockSteam::onIconDragStartHandler); 
    m_icon[2]->m_signalDrag.connect(this, &VappScreenLockSteam::onIconDragHandler); 
    m_icon[2]->m_signalDragEnd.connect(this, &VappScreenLockSteam::onIconDragEndHandler); 
    m_icon[2]->m_signalDragAbort.connect(this, &VappScreenLockSteam::onIconDragAbortHandler); 
    m_icon[2]->setIconId(2);
    m_dummyFrame->addChildFrame(m_icon[2]);

    VFX_OBJ_CREATE(m_tlSlideDummyPosY, VfxS32Timeline, this);
    m_tlSlideDummyPosY->setTarget(m_dummyFrame);
    m_tlSlideDummyPosY->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_tlSlideDummyPosY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_tlSlideDummyPosY->m_signalStopped.connect(this, &VappScreenLockSteam::onSlideDummyStopped);


    VFX_OBJ_CREATE(m_widowEdge, VappSteamScreenLockWindowEdgeFrame, this);
    m_widowEdge->setPos(m_dummyFrame->getPos().x, m_dummyFrame->getPos().y+m_dummyFrame->getSize().height);
    m_widowEdge->setPropertyEffectCallback(
                            m_dummyFrame,
                            edgeFrameEffectCallBack,
                            NULL,
                            0,
                            VRT_FPE_TRIGGER_TYPE_DIRTY);

    FramePropertyEffectData userData2;
    userData2.var = m_unlockDistance;
    m_widowEdge->m_blingEffect->setPropertyEffectCallback(
                            m_dummyFrame,
                            blingEffectFrameEffectCallBack,
                            &userData2,
                            sizeof(userData2),
                            VRT_FPE_TRIGGER_TYPE_DIRTY);

    VFX_OBJ_CREATE(m_edgetEffectFrame, VappSteamScreenLockGlowEffectFrame, this);
    //m_edgetEffectFrame->setResId(IMG_ID_VAPP_STEAM_SCREEN_LOCK_EDGE_HALO);
    m_edgetEffectFrame->setSize(getSize().width, m_edgetEffectFrame->getSize().height);
    m_edgetEffectFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_edgetEffectFrame->setPos(m_widowEdge->getPos().x, m_widowEdge->getPos().y+m_widowEdge->getSize().height);
    FramePropertyEffectData userData;
    userData.var = m_widowEdge->getSize().height;
    m_edgetEffectFrame->setPropertyEffectCallback(
                            m_dummyFrame,
                            edgeHoleFrameEffectCallBack,
                            &userData,
                            sizeof(FramePropertyEffectData),
                            VRT_FPE_TRIGGER_TYPE_DIRTY);
    
    VFX_OBJ_CREATE(m_timerFlowWaterDrop, VfxTimer, this);
    m_timerFlowWaterDrop->setStartDelay(2000);
    m_timerFlowWaterDrop->m_signalTick.connect(this, &VappScreenLockSteam::produceWaterDropTimerCallback);

    #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}


void VappScreenLockSteam::produceWaterDropTimerCallback(VfxTimer *sender)
{
    m_isAllowFlowWaterDrop = VFX_TRUE;
}


vrt_render_dirty_type_enum VappScreenLockSteam::edgeHoleFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    FramePropertyEffectData *userData = (FramePropertyEffectData *)user_data;

    target_frame->pos.x = watch_frame->pos.x;
    target_frame->pos.y = watch_frame->pos.y + watch_frame->bounds.size.height + userData->var;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


vrt_render_dirty_type_enum VappScreenLockSteam::edgeFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    target_frame->pos.x = watch_frame->pos.x;
    target_frame->pos.y = watch_frame->pos.y + watch_frame->bounds.size.height;
 
    MMI_TRACE(TRACE_GROUP_3, 
                TRC_VAPP_STEAM_SCREEN_LOCK_EDGE_FRAME_EFFECT_CALLBACK,
                target_frame->pos.x,
                target_frame->pos.y,
                600);
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


vrt_render_dirty_type_enum VappScreenLockSteam::blingEffectFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    FramePropertyEffectData *userData = (FramePropertyEffectData *)user_data;

    VfxFloat ratio = (-1.0) *(VfxFloat)watch_frame->pos.y/userData->var;
    target_frame->pos.x = LCD_WIDTH * ratio;

    MMI_TRACE(TRACE_GROUP_3, 
                TRC_VAPP_STEAM_SCREEN_LOCK_BLING_EFFECT_FRAME_EFFECT_CALLBACK,
                target_frame->pos.x, 601);

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}



void VappScreenLockSteam::onReleaseView()
{
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    deinitWallpaper();
    VFX_OBJ_CLOSE(m_dummyFrame);
    VFX_OBJ_CLOSE(m_lockFrame);
    VFX_OBJ_CLOSE(m_timeArea);
    //VFX_OBJ_CLOSE(m_icon[0]);
    //VFX_OBJ_CLOSE(m_icon[1]);
    //VFX_OBJ_CLOSE(m_icon[2]);
    VFX_OBJ_CLOSE(m_ffectFrame[0]);
    VFX_OBJ_CLOSE(m_ffectFrame[1]);
    VFX_OBJ_CLOSE(m_ffectFrame[2]);
    VFX_OBJ_CLOSE(m_tlSlideDummyPosY);
    VFX_OBJ_CLOSE(m_widowEdge);
    VFX_OBJ_CLOSE(m_edgetEffectFrame);
    VFX_OBJ_CLOSE(m_timerFlowWaterDrop);
}


void VappScreenLockSteam::onPageEnter()
{
    // use gpio service app timer, set 8s to dimming
    srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP, VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME*0.7,VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME);

    if(!m_wallpaper)
    {
        createWallpaper();
    }
    else
    {
        m_wallpaper->resume();
    }
}


void VappScreenLockSteam::onPageExit()
{
    // restore app timer and call turn_off when lock is not active
    // in order to restore backlight from SRV_BACKLIGHT_PERMANENT
    srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
    srv_backlight_turn_off();
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    m_wallpaper->suspend();
}

void VappScreenLockSteam::onSerializeView()
{
    if(m_wallpaper)
{
        m_wallpaper->serializeView();
    }
}


void VappScreenLockSteam::onRestoreView()
{
    if(m_wallpaper)
{
        m_wallpaper->restoreView();
    }
}


mmi_ret VappScreenLockSteam::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappScreenLockSteam* page = (VappScreenLockSteam *)event->user_data;
    
    switch (event->evt_id)
    {
        default:
            break;
    }
    return MMI_RET_OK;
}

        
VfxBool VappScreenLockSteam::isUnlocking()
{
    return (m_lockState == STATE_UNLOCKING) ? VFX_TRUE : VFX_FALSE;
}
 

VfxBool VappScreenLockSteam::onPreviewPenInput(VfxPenEvent &event)
{

    //Ignore pen input if the lock animation is running.
    //Scenario: Cannot rubbing the fog if the animation is running.
    if(m_lockState != STATE_NORMAL)
    {
        return VFX_TRUE;
    }

    if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_lockFrame->stopFogUp();

        //MAUI_03075805: suspend video live wallpaper for performance consideration
        if(m_wallpaper)
        {
            m_wallpaper->suspend();
        }
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_lockFrame->startFogUpTimer();

        //MAUI_03075805: resume wallpaper
        //MAUI_03091643: remove the resume wallpaper timer.
        //scenario: pen_down->drag to edge(pen_abort)        
        if(m_wallpaper && !isUnlocking())
        {
            m_wallpaper->resume();
        }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        //MAUI_03075805: resume wallpaper
        //MAUI_03091643: remove the resume wallpaper timer.
        //scenario: pen_down->drag to edge(pen_abort)
        if(m_wallpaper && !isUnlocking())
        {
            m_wallpaper->resume();
        }
    }

    return MMI_RET_OK;
}


VappSteamScreenLockIcon *VappScreenLockSteam::createUnlockItem(
            VappScreenLockSteamUnlockItemPos pos, VfxObject *parentObj)
{
    //
    // Create unlock item.
    //
    VappScreenLockSteamUnlockItemKit *kit;

    VFX_OBJ_CREATE(kit, VappScreenLockSteamUnlockItemKit, parentObj);

    return (VappSteamScreenLockIcon *)kit->createUnlockItem(
                                                kit->getUnlockItemId(pos), 
                                                parentObj);
}


void VappScreenLockSteam::initWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.connect(this, &VappScreenLockSteam::wallpaperUpdatedHdlr);

    createWallpaper();
}


void VappScreenLockSteam::createWallpaper()
{
    m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_LOCK);
}


void VappScreenLockSteam::releaseWallpaper()
{
    if(m_wallpaper)
    {
        VFX_OBJ_CLOSE(m_wallpaper);
    }
}


void VappScreenLockSteam::wallpaperUpdatedHdlr()
{
    releaseWallpaper();

    //
    // Because video wallpaper cannot be created in the background, we can only
    // re-create the wallpaper when this page is active.
    //
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if(isEntered() && !mainScr->getIsSnapshotDrawing() )
    {
        createWallpaper();
    }
}


void VappScreenLockSteam::deinitWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.disconnect(this, &VappScreenLockSteam::wallpaperUpdatedHdlr);

    releaseWallpaper();
}


void VappScreenLockSteam::onSlideDummyStopped(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    if(!isCompleted)
    {
        return;
    }

    VfxFrame *frame = (VfxFrame *)timeline->getTarget();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_SLIDE_DUMMY_STOPPED, m_lockState, 200);
    if(m_lockState == STATE_UNLOCKING)
    {
        m_lockState = STATE_NORMAL;
        m_targetIcon->setUnlocked();
        vapp_screen_lock_close();
    }
    else
    {
        m_freeFallTime++;
        
        if(m_freeFallTime == 5)
        {
            frame->setPos(frame->getPos().x, 0);
            m_lockState = STATE_NORMAL;
            return;
        }

        if(m_freeFallTime%2 == 0)
        {
            m_tlSlideDummyPosY->setFromValue(m_freeFallHeight);
            m_tlSlideDummyPosY->setToValue(0);
            m_tlSlideDummyPosY->setDurationTime(m_freeFallDurTime);
            m_tlSlideDummyPosY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
            m_tlSlideDummyPosY->start();

        }
        else
        {
            m_freeFallHeight = 0.25 * m_freeFallHeight;
            m_freeFallDurTime = 0.7 * m_freeFallDurTime;
            m_tlSlideDummyPosY->setFromValue(0);
            m_tlSlideDummyPosY->setToValue(m_freeFallHeight);
            m_tlSlideDummyPosY->setDurationTime(m_freeFallDurTime);
            m_tlSlideDummyPosY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            m_tlSlideDummyPosY->start();
        }
    }
}


void VappScreenLockSteam::onIconDragStartHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_START_HANDLER, m_lockState, penEvent.pos.y, 200);
    if(m_lockState != STATE_NORMAL)
    {
        return;
    }
    m_oridownPosY = penEvent.pos.y;
    m_targetIcon = icon;
    m_targetIcon->startSpinAnimation();

    // UE design, only stop lock icon shake
    m_icon[1]->stopShakeAnimation();
    m_ffectFrame[m_targetIcon->getIconId()]->setOpacity(1);
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
    m_numFlowWaterDrop = 0;

    m_isAllowFlowWaterDrop = VFX_TRUE;
}


void VappScreenLockSteam::onIconDragHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_HANDLER, m_lockState, penEvent.pos.y, 200);

    // m_target may be NULL when procedure is
    // onIconDragStartHandler -> onSlideDummyStopped -> onIconDragHandler/onIconDragEndHandler
    // so needs to return when target is NULL
    if(m_lockState != STATE_NORMAL || m_targetIcon == NULL)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_HANDLER, m_lockState, penEvent.pos.y, 500);
        return;
    }

    if(penEvent.pos.y >= m_oridownPosY)
    {
        m_dummyFrame->setPos(m_dummyFrame->getPos().x, 0);
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_HANDLER, m_lockState, penEvent.pos.y, 600);
    }
    else
    {
        VfxS32 offsetY = m_oridownPosY - penEvent.pos.y;
        m_dummyFrame->setPos(m_dummyFrame->getPos().x, -offsetY);
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_HANDLER, m_lockState, penEvent.pos.y, 700);
        MMI_TRACE(TRACE_GROUP_3, 
                    TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_HANDLER, 
                    m_dummyFrame->getPos().x, -offsetY, 701);
    }

    if(m_isAllowFlowWaterDrop)
    {
        VfxS32 randomX = rand() % (getSize().width);
        VfxS32 tmp = rand()%10000;

        if(tmp > 6000)
        {
            m_lockFrame->addWaterDrop(VfxPoint(randomX,0));
            m_numFlowWaterDrop++;
        }

        // restart allow flow water drop timer
        if(!m_timerFlowWaterDrop->getIsEnabled())
        {
            m_timerFlowWaterDrop->start();
        }
        m_isAllowFlowWaterDrop = VFX_FALSE;
    }
}


void VappScreenLockSteam::onIconDragEndHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_END_HANDLER, m_lockState, penEvent.pos.y, 200);
    if(m_lockState != STATE_NORMAL || m_targetIcon == NULL)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_END_HANDLER, m_lockState, penEvent.pos.y, 500);
        return;
    }

    m_ffectFrame[m_targetIcon->getIconId()]->setOpacity(0);
    m_targetIcon->stopSpinAnimation();
    m_icon[1]->startShakeAnimation();

    // There has two condition to unlock
    // 1. slide card up over m_unlockDistance
    // 2. swipe card up quickly, we use predictPos to decide it
    if( (m_oridownPosY - penEvent.pos.y) >= m_unlockDistance ||
        (m_oridownPosY - penEvent.predictPos.y) >= m_unlockDistance)
    {
        m_lockState = STATE_UNLOCKING;
        m_tlSlideDummyPosY->setFromValue(m_dummyFrame->getPos().y);
        m_tlSlideDummyPosY->setToValue(-getSize().height - m_widowEdge->getSize().height - m_edgetEffectFrame->getSize().height);
        m_tlSlideDummyPosY->setDurationTime(VAPP_SCREEN_LOCK_UNLOCK_SLIDE_ANI_DURATION);
        m_tlSlideDummyPosY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_tlSlideDummyPosY->start();
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_END_HANDLER, m_lockState, penEvent.pos.y, 201);

        // Suspend wallpaper for the performance consideration,MAUI_03144615.
        if(m_wallpaper)
        {
            m_wallpaper->suspend();
        }
    }
    else
    {
        m_lockState = STATE_SLIDING;
        m_freeFallHeight = m_dummyFrame->getPos().y;
        m_freeFallTime = 0;
        m_freeFallDurTime = VAPP_SCREEN_LOCK_RESTORE_LOCK_SLIDE_ANI_DURATION;
        m_tlSlideDummyPosY->setFromValue(m_dummyFrame->getPos().y);
        m_tlSlideDummyPosY->setToValue(0);
        m_tlSlideDummyPosY->setDurationTime(VAPP_SCREEN_LOCK_RESTORE_LOCK_SLIDE_ANI_DURATION);
        m_tlSlideDummyPosY->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
        m_tlSlideDummyPosY->start();
        m_targetIcon = NULL;
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_DRAG_END_HANDLER, m_lockState, penEvent.pos.y, 202);
    }

    m_timerFlowWaterDrop->stop();
    m_isAllowFlowWaterDrop = VFX_FALSE;
}


void VappScreenLockSteam::onIconDragAbortHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent)
{;
    if(m_targetIcon == NULL)
    {
        return;
    }

    m_ffectFrame[m_targetIcon->getIconId()]->setOpacity(0);
    m_targetIcon->stopSpinAnimation();
    m_icon[1]->startShakeAnimation();
    m_dummyFrame->setPos(m_dummyFrame->getPos().x, 0);
    m_targetIcon = NULL;
    m_lockState = STATE_NORMAL;
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_ON_ICON_ABORT_HANDLER, m_lockState, penEvent.pos.y, 800);    
}


VfxSize VappScreenLockSteam::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}

/***************************************************************************** 
 * VappSteamScreenLockWindowEdgeFrame
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSteamScreenLockWindowEdgeFrame", VappSteamScreenLockWindowEdgeFrame, VfxFrame);


VappSteamScreenLockWindowEdgeFrame::VappSteamScreenLockWindowEdgeFrame()
{
}


void VappSteamScreenLockWindowEdgeFrame::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_edgetFrame, VfxImageFrame, this);
    m_edgetFrame->setResId(IMG_ID_VAPP_STEAM_SCREEN_LOCK_WINDOW_EDGE);
    m_edgetFrame->setSize(getParentFrame()->getSize().width, m_edgetFrame->getSize().height);
    setSize(m_edgetFrame->getSize());

    VFX_OBJ_CREATE(m_blingEffect, VappSteamScreenLockGlowEffectFrame, this);
    m_blingEffect->setResId(IMG_ID_VAPP_STEAM_SCREEN_LOCK_BLING);
    m_blingEffect->setSize(200, m_blingEffect->getSize().height);
    m_blingEffect->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_blingEffect->setAnchor(0.5, 0.5);
    m_blingEffect->setPos(m_edgetFrame->getPos().x+m_edgetFrame->getSize().width/2, m_edgetFrame->getSize().height/2);

    VfxTransform t = getTransform();
    VFX_ASSERT(t.type == VRT_TRANSFORM_TYPE_AFFINE);
    t.data.affine.rz = VFX_DEG_TO_RAD(25);
    m_blingEffect->setTransform(t);

}


void VappSteamScreenLockWindowEdgeFrame::updateBlingEffectPos(VfxS32 dummyFrameOffsetY, VfxS32 unlockDistance)
{
    VfxFloat ratio = 1.0 - (VfxFloat)dummyFrameOffsetY / unlockDistance;
    m_blingEffect->setPos(LCD_WIDTH*ratio, m_blingEffect->getPos().y);
}


/***************************************************************************** 
 * VappSteamScreenLockGlowEffectFrame
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSteamScreenLockGlowEffectFrame", VappSteamScreenLockGlowEffectFrame, VfxImageFrame);


VappSteamScreenLockGlowEffectFrame::VappSteamScreenLockGlowEffectFrame()
{
}


void VappSteamScreenLockGlowEffectFrame::onInit()
{
    VfxImageFrame::onInit();

    // Material
    VfxMaterial *material;
    VFX_OBJ_CREATE(material, VfxMaterial, this);
    this->setMaterial(material);

    // Pass
    VfxPass *pass;    
    VFX_OBJ_CREATE(pass, VfxPass, material);
    material->setPass(0, pass);

    // set blending mode
     VfxCompositingMode *cm;
     VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
     pass->setCompositingMode(cm);
     cm->setDepthTestEnable(VFX_FALSE);

     VfxBlender *blender;
     VFX_OBJ_CREATE(blender, VfxBlender, cm);
     cm->setBlender(blender);

     blender->setBlendEquation(VFX_BLEND_EQUATION_ADD, VFX_BLEND_EQUATION_ADD);
     blender->setBlendFunc(VFX_BLEND_FACTOR_DST_COLOR, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA);
}


void VappSteamScreenLockGlowEffectFrame::onDeinit()
{
    VfxImageFrame::onDeinit();
}
#endif
