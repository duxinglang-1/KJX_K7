/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_steam_screen_lock_frame.cpp
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
#include "vapp_screen_lock_steam_frame.h"
#include "vapp_screen_lock_Steam_owner_draw.h"
#include "vapp_screen_lock_steam_icon.h"
#include "vcp_bubble_effect.h"
#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_trc.h"
#include "vfx_adp_device.h"

/* for 3d header*/
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

// for test
#include "Vcp_button.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "GpioSrvGProt.h"
#include "gdi_primitive.h"

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
VFX_IMPLEMENT_CLASS("VappSteamScreenLockFrame", VappSteamScreenLockFrame, VfxControl);

VappSteamScreenLockFrame::VappSteamScreenLockFrame():
    m_ownerDraw(NULL)
{
}

void VappSteamScreenLockFrame::onInit()
{
    VfxControl::onInit();

    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
    //setCacheMode(VFX_CACHE_MODE_RESOURCE);
    
    //VFX_OBJ_CREATE(m_ownerDraw, VappSteamScreenLockOwenerDraw, this);
    setSize(getParentFrame()->getSize());
    VFX_OBJ_CREATE_EX(m_ownerDraw, VappSteamScreenLockOwenerDraw, this, (getSize()));       
    setOwnerDraw(m_ownerDraw);
    setPosZ(0);
    setPropertyEffectCallback(
        this,
        frameEffectCallBack,
        m_ownerDraw,
        sizeof(VappSteamScreenLockOwenerDraw),
        VRT_FPE_TRIGGER_TYPE_EVERYTIME);

    VFX_OBJ_CREATE(m_timerStartFog, VfxTimer, this);
    m_timerStartFog->setStartDelay(VAPP_STEAM_SCREEN_LOCK_FRAME_FOG_UP_TIMER_TIME);
    m_timerStartFog->m_signalTick.connect(this, &VappSteamScreenLockFrame::onStartFogTimerCallback);

#ifdef MOTION_SENSOR_SUPPORT
    srv_sensor_motion_shake_cfg_struct shake_sensitive;
    // modify for sensor split
    shake_sensitive.sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;

    m_motionSensorPara.m_motion_shake_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_SHAKE , &shake_sensitive, onMotionShakeCallback, m_ownerDraw);
    m_motionSensorPara.m_motion_tilt_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_TILT , NULL, onMotionTiltDetailCallback, m_ownerDraw);
#endif
    mmi_frm_cb_reg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappSteamScreenLockFrame::eventHandler, this);
}


void VappSteamScreenLockFrame::onDeinit()
{
#ifdef MOTION_SENSOR_SUPPORT
    /* disable motion sensor */
    if (m_motionSensorPara.m_motion_shake_handle >= 0)
    {
        srv_sensor_stop_listen(m_motionSensorPara.m_motion_shake_handle);
        m_motionSensorPara.m_motion_shake_handle = -1;
    }
    if (m_motionSensorPara.m_motion_tilt_handle >= 0)
    {
        srv_sensor_stop_listen(m_motionSensorPara.m_motion_tilt_handle);
        m_motionSensorPara.m_motion_tilt_handle = -1;
    }
#endif

    mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_IN, &VappSteamScreenLockFrame::eventHandler, this);
    m_timerStartFog->m_signalTick.disconnect(this, &VappSteamScreenLockFrame::onStartFogTimerCallback);
    VfxControl::onDeinit();
    
    //release g_mem_buffer
    m_ownerDraw->releaseResource();
}


#ifdef MOTION_SENSOR_SUPPORT
void VappSteamScreenLockFrame::onMotionShakeCallback(srv_sensor_type_enum sensor_type, 
            void *sensor_data, void *user_data)
{
    srv_sensor_motion_shake_struct * p_shake;
    p_shake = (srv_sensor_motion_shake_struct *)sensor_data;

    //FramePropertyEffectData *userData = (FramePropertyEffectData *)user_data;
    //VappSteamScreenLockOwenerDraw *ownerDraw = (VappSteamScreenLockOwenerDraw *)userData->ownerDrawPtr;
    VappSteamScreenLockOwenerDraw *ownerDraw = (VappSteamScreenLockOwenerDraw *)user_data;
    if(p_shake->action == SRV_SENSOR_MOTION_SHAKING)
    {
        ownerDraw->reset();
    }
}


void VappSteamScreenLockFrame::onMotionTiltDetailCallback(
        srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{

    srv_sensor_motion_tilt_struct *p_tilt;
    p_tilt = ( srv_sensor_motion_tilt_struct *)sensor_data;

    //FramePropertyEffectData *userData = (FramePropertyEffectData *)user_data;
    //VappSteamScreenLockOwenerDraw *ownerDraw = (VappSteamScreenLockOwenerDraw *)userData->ownerDrawPtr;
    VappSteamScreenLockOwenerDraw *ownerDraw = (VappSteamScreenLockOwenerDraw *)user_data;

    //VfxFloat cos_theta = cos(p_tilt->angle.gx * PI / 180);
    //VfxFloat sin_theta = sin(p_tilt->angle.gy * PI / 180);
    //ownerDraw->setGravity(cos_theta, sin_theta, 0);

    VfxFloat x_gravity = (VfxFloat)p_tilt->acc.x / 980.0;
    VfxFloat y_gravity = (VfxFloat)p_tilt->acc.y / 980.0;
    VfxFloat z_gravity = (VfxFloat)p_tilt->acc.z / 980.0;

    //ownerDraw->setGravity(x_gravity, y_gravity, 0);
    
    // for the case of lying position, see MAUI_03161112
    ownerDraw->setGravity(x_gravity, y_gravity, z_gravity);
}
#endif

void VappSteamScreenLockFrame::startFogUpTimer()
{
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    m_timerStartFog->start();
}


void VappSteamScreenLockFrame::stopFogUp()
{
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    m_timerStartFog->stop();
    m_ownerDraw->m_fogUpTimes  = 0;
}

//MAUI_03028170:after rub fog and press power key immediately
//need to stop the fog timer to prevent the backlight turn on again
void VappSteamScreenLockFrame::stopFogUpNoBacklight()
{
    m_timerStartFog->stop();
    m_ownerDraw->m_fogUpTimes  = 0;
}

void VappSteamScreenLockFrame::onStartFogTimerCallback(VfxTimer *obj)
{
    m_ownerDraw->m_fogUpTimes = 250;
    srv_backlight_turn_off();
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}


void VappSteamScreenLockFrame::addWaterDrop(VfxPoint pos)
{
    VfxPoint tmpPos = convertPointTo(pos, this);
    tmpPos.y = getSize().height - tmpPos.y;

    VfxS32 dropWeight = rand()%400 + 50;

    m_ownerDraw->addWaterDrop(tmpPos, dropWeight);
}


VfxBool VappSteamScreenLockFrame::onPenInput(VfxPenEvent &event)
{
    // transform to opengl coordinate
    VfxS32 posX = event.getRelPos(this).x;
    VfxS32 posY = getSize().height - event.getRelPos(this).y;
    VfxS32 prevX = event.getRelPrevPos(this).x;
    VfxS32 prevY = getSize().height - event.getRelPrevPos(this).y;
    VfxS32 timeStamp = event.timeStamp;
    VfxS32 prevtimeStamp = event.prevTimeStamp;
    VfxS32 downtimeStamp = event.downTimeStamp;

    VfxS32 dropTrigerArea;
    VfxS32 dropTrigerTime;
    VfxS32 dropWeight;

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_STEAM_SCREEN_LOCK_FRAME_ON_PEN_INPUT, 
                event.type, 
                event.getRelPrevPos(this).x, event.getRelPrevPos(this).y,
                event.getRelPos(this).x, event.getRelPos(this).y, 
                200);
    
    // dispatch event directly
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            {
                m_ownerDraw->addStrokeLine(posX, posY, (posX+0.1), (posY+0.1));                          
     
                m_lastDropletTimestamp = timeStamp;
                m_movingArea = 0;
                return VFX_TRUE;
            }
            break;
        
        case VFX_PEN_EVENT_TYPE_MOVE:
            {            
                m_ownerDraw->addStrokeLine(prevX,prevY, posX, posY);                          
                m_movingArea = m_movingArea + (posX - prevX)*(posX - prevX) + 
                                (posY - prevY)*(posY - prevY);
                dropTrigerArea = rand()%3000 + 1000;
                dropTrigerTime = rand()%2000 + 500;
                if(m_movingArea >= dropTrigerArea && 
                    (timeStamp - m_lastDropletTimestamp) >= dropTrigerTime)
                {
                    m_movingArea = 0;
                    m_lastDropletTimestamp = timeStamp;
                    if(timeStamp - m_lastDropletTimestamp > 1500)
                    {
                        dropWeight = rand()%100 + 50;
                    }
                    else if(timeStamp - m_lastDropletTimestamp > 3000)
                    {
                        dropWeight = rand()%300 + 50;
                    }
                    else
                    {
                        dropWeight = rand()%500 + 50;
                    }
                    m_ownerDraw->addWaterDrop(VfxPoint(posX, posY), dropWeight);
                }
                invalidate();
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            {
                VRT_MUST_TRACE(("\n"));
                dropTrigerArea = rand()%3000 + 1000;
                dropTrigerTime = rand()%2000 + 1000;
                if(m_movingArea >= dropTrigerArea && 
                    (timeStamp - m_lastDropletTimestamp) >= dropTrigerTime)
                {
                    m_movingArea = 0;
                    m_lastDropletTimestamp = timeStamp;
                    if(timeStamp - m_lastDropletTimestamp > 1000)
                    {
                        dropWeight = rand()%100 + 50;
                    }
                    else if(timeStamp - m_lastDropletTimestamp > 2000)
                    {
                        dropWeight = rand()%300 + 50;
                    }
                    else
                    {
                        dropWeight = rand()%500 + 50;
                    }
                    m_ownerDraw->addWaterDrop(VfxPoint(posX, posY), dropWeight);
                }

            }
            break;
        default:
            break;
    }
    return VfxControl::onPenInput(event);
}


VfxSize VappSteamScreenLockFrame::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}


vrt_render_dirty_type_enum VappSteamScreenLockFrame::frameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    VappSteamScreenLockOwenerDraw *ownerDraw = (VappSteamScreenLockOwenerDraw*)user_data;

    if (ownerDraw->m_redrawWaterDrop || ownerDraw->m_fogUpTimes) 
    {
        target_frame->fpe_user_0 = 0;
        return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
    }
    else
    {
          return VRT_RENDER_DIRTY_TYPE_NONE;
    }
}


void VappSteamScreenLockFrame::resetOwnerDraw()
{
    m_ownerDraw->reset();
}

mmi_ret VappSteamScreenLockFrame::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappSteamScreenLockFrame *frame = (VappSteamScreenLockFrame *)event->user_data;
    

    switch (event->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
        {
            frame->resetOwnerDraw();

            //MAUI_03028170:after rub fog and press power key immediately
            //need to stop the fog timer to prevent the backlight turn on again
            frame->stopFogUpNoBacklight();
        }
        break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
