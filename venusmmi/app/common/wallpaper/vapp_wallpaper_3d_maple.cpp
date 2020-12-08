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
 *  vapp_wallpaper_frame_video.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen frame fast video wallpaper class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_3d_maple.h"
//#include "HomeScreen/vadp_v2p_hs.h"
#include "mmi_rp_app_venus_wallpaper_3d_maple_def.h"

/* RHR start */
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_def.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_input_event.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
#include "vadp_asm.h"
/* RHR end */

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif

// for reg gpio event
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"

#include "gdi_primitive.h"

#include "FileMgrSrvGProt.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Home screen UI componet: frame video wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("3D maple Wallpaper", VappWallpaper3DMaple, VappWallpaper);

VappWallpaper3DMaple::VappWallpaper3DMaple()
    #if defined(MOTION_SENSOR_SUPPORT)
    : m_motionSensorHandle(SRV_SENSOR_MOTION_NO_SLOT)
    #endif
{
        m_targetLoc = 0.5f;
}

void VappWallpaper3DMaple::onSerializeView()
{
    onReleaseView();
}

void VappWallpaper3DMaple::onRestoreView()
{
    onCreateView();
}

void VappWallpaper3DMaple::onCreateView()
{
    setPos(0, 0);
    setSize(LCD_WIDTH, LCD_HEIGHT);
    setBgColor(VFX_COLOR_TRANSPARENT);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    VFX_OBJ_CREATE(m_worldFrame, VfxFrame, this);
    m_worldFrame->setPos(0, 0);
    m_worldFrame->setSize(LCD_WIDTH, LCD_HEIGHT);
    m_worldFrame->setHidden(VFX_FALSE);
    m_worldFrame->bringToFront();
    m_worldFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_worldFrame->setHints((VfxFrameHintsEnum)(VFX_FRAME_HINTS_DISABLE_COLOR_KEY));
    m_worldFrame->setCacheMode(VFX_CACHE_MODE_PREVENT_PARENTS);

    // ===========================================================================================
    // the camera in scene
    VFX_OBJ_CREATE(m_world, VfxWorld, m_worldFrame);
    m_world->enableClearDepth(VRT_TRUE, VRT_FALSE);
    m_worldFrame->setWorld(m_world);

    // load the scene
    VfxAssetLoader::loadSceneBegin(m_world, VAPP_WALLPAPER_3D_MAPLE_SCN_CAMERA);
        VfxCamera * m_camera;
        m_camera = VFX_OBJ_DYNAMIC_CAST(VfxAssetLoader::findObjByName(VFX_STR("Camera-M1-node")), VfxCamera);
    VfxAssetLoader::loadSceneEnd();

    // set timeline
    VFX_OBJ_CREATE(m_worldCameraTimeline, VfxFloatTimeline, m_camera);
    m_worldCameraTimeline->setTarget(m_camera);
    m_worldCameraTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_worldCameraTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_worldCameraTimeline->setDuration(100);
    m_worldCameraTimeline->setAutoReversed(VFX_FALSE);
    m_worldCameraTimeline->setIsFromCurrent(VFX_FALSE);
    m_worldCameraTimeline->setRepeatCount(1);
    m_worldCameraTimeline->setFromValue(m_targetLoc);
    m_worldCameraTimeline->setToValue(m_targetLoc);

    // load the animation
    VFX_OBJ_CREATE(m_worldCameraAnim, VfxAnimation, m_world);
    VfxAssetLoader::loadAnimation(m_worldCameraAnim,
                                  m_world,
                                  VAPP_WALLPAPER_3D_MAPLE_SCN_CAMERA_ANIM);

    m_worldCameraAnim->setTimelineTime(m_worldCameraTimeline);
    if(!this->isSuspended())
        m_worldCameraTimeline->start();

    // ===========================================================================================
    // the base scene

    // load the scene
    VfxAssetLoader::loadSceneBegin(m_world, VAPP_WALLPAPER_3D_MAPLE_SCN);
    VfxAssetLoader::loadSceneEnd();

    // set timeline
    VFX_OBJ_CREATE(m_worldTimeline, VfxFloatTimeline, m_world);
    m_worldTimeline->setTarget(m_world);
    m_worldTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_worldTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_worldTimeline->setDuration(5000);
    m_worldTimeline->setAutoReversed(VFX_FALSE);
    m_worldTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_worldTimeline->setFromValue(0.0f);
    m_worldTimeline->setToValue(1.0f);

    // load the animation
    VFX_OBJ_CREATE(m_worldAnim, VfxAnimation, m_world);
    VfxAssetLoader::loadAnimation(m_worldAnim,
                                  m_world,
                                  VAPP_WALLPAPER_3D_MAPLE_SCN_ANIM);

    m_worldAnim->setTimelineTime(m_worldTimeline);
    if(!this->isSuspended())
        m_worldTimeline->start();
    // ===========================================================================================

    // ===========================================================================================
    // the petals scene

    VFX_OBJ_CREATE(m_petals, VfxGroup, m_world);

    // load the scene
    VfxAssetLoader::loadSceneBegin(m_petals, VAPP_WALLPAPER_3D_MAPLE_PETALS_SCN);
    VfxAssetLoader::loadSceneEnd();

    // set timeline
    VFX_OBJ_CREATE(m_petalstimeline, VfxFloatTimeline, m_petals);
    m_petalstimeline->setTarget(m_petals);
    m_petalstimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_petalstimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_petalstimeline->setDuration(8000);
    m_petalstimeline->setAutoReversed(VFX_FALSE);
    m_petalstimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_petalstimeline->setFromValue(0.0f);
    m_petalstimeline->setToValue(1.0f);

    // load the animation
    VFX_OBJ_CREATE(m_petalsAnim, VfxAnimation, m_petals);
    VfxAssetLoader::loadAnimation(m_petalsAnim,
                                  m_petals,
                                  VAPP_WALLPAPER_3D_MAPLE_PETALS_ANIM);

    m_petalsAnim->setTimelineTime(m_petalstimeline);
    if(!this->isSuspended())
        m_petalstimeline->start();

    // ===========================================================================================
    // the butterfly scene
    VFX_OBJ_CREATE(m_butterfly, VfxGroup, m_world);

    // load the scene
    VfxAssetLoader::loadSceneBegin(m_butterfly, VAPP_WALLPAPER_3D_MAPLE_BUTTERFLY_SCN);
    VfxAssetLoader::loadSceneEnd();

    // set timeline
    VFX_OBJ_CREATE(m_butterflytimeline, VfxFloatTimeline, m_butterfly);
    m_butterflytimeline->setTarget(m_butterfly);
    m_butterflytimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_butterflytimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_butterflytimeline->setDuration(6000);
    m_butterflytimeline->setStartDelay(20000);
    m_butterflytimeline->setAutoReversed(VFX_FALSE);
    m_butterflytimeline->setRepeatCount(1);
    m_butterflytimeline->setFromValue(0.0f);
    m_butterflytimeline->setToValue(1.0f);

    // load the animation
    VFX_OBJ_CREATE(m_butterflyAnim, VfxAnimation, m_butterfly);
    VfxAssetLoader::loadAnimation(m_butterflyAnim,
                                  m_butterfly,
                                  VAPP_WALLPAPER_3D_MAPLE_BUTTERFLY_ANIM);

    m_butterflyAnim->setTimelineTime(m_butterflytimeline);
    m_butterflytimeline->m_signalStopped.connect(this, &VappWallpaper3DMaple::onEndOfButterflyTimeline);
    if(!this->isSuspended())
        m_butterflytimeline->start();
    // ===========================================================================================

    // ===========================================================================================
    // the background tree scene
    VFX_OBJ_CREATE(m_tree, VfxGroup, m_world);

    // load the scene
    VfxAssetLoader::loadSceneBegin(m_tree, VAPP_WALLPAPER_3D_MAPLE_BG_TREE_SCN);
    VfxAssetLoader::loadSceneEnd();

    // set timeline
    VFX_OBJ_CREATE(m_treetimeline, VfxFloatTimeline, m_tree);
    m_treetimeline->setTarget(m_tree);
    m_treetimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_treetimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_treetimeline->setDuration(5000);
    m_treetimeline->setAutoReversed(VFX_FALSE);
    m_treetimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_treetimeline->setFromValue(0.0f);
    m_treetimeline->setToValue(1.0f);

    // load the animation
    VFX_OBJ_CREATE(m_treeAnim, VfxAnimation, m_tree);
    VfxAssetLoader::loadAnimation(m_treeAnim,
                                  m_tree,
                                  VAPP_WALLPAPER_3D_MAPLE_BG_TREE_ANIM);

    m_treeAnim->setTimelineTime(m_treetimeline);
    if(!this->isSuspended())
        m_treetimeline->start();
    // ===========================================================================================

    // ===========================================================================================
    // the petals2 scene

    VFX_OBJ_CREATE(m_petals2, VfxGroup, m_world);

    //m_petals2->setTranslation(150, 50, 0);

    // load the scene

    VfxAssetLoader::loadSceneBegin(m_petals2, VAPP_WALLPAPER_3D_MAPLE_PETALS_FALL_SCN);
    VfxAssetLoader::loadSceneEnd();

    // set timeline
    VFX_OBJ_CREATE(m_petals2timeline, VfxFloatTimeline, m_petals2);
    m_petals2timeline->setTarget(m_petals2);
    m_petals2timeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_petals2timeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_petals2timeline->setDuration(8000);
    m_petals2timeline->setAutoReversed(VFX_FALSE);
    m_petals2timeline->setRepeatCount(1);
    m_petals2timeline->setFromValue(0.0f);
    m_petals2timeline->setToValue(1.0f);

    // load the animation
    VFX_OBJ_CREATE(m_petals2Anim, VfxAnimation, m_petals2);
    VfxAssetLoader::loadAnimation(m_petals2Anim,
                                  m_petals2,
                                  VAPP_WALLPAPER_3D_MAPLE_PETALS_FALL_ANIM);

    m_petals2Anim->setTimelineTime(m_petals2timeline);
    // ===========================================================================================

#if defined(MOTION_SENSOR_SUPPORT)
    // ===========================================================================================
    // motion sensor initialization
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    srv_sensor_motion_shake_cfg_struct threshold;
    threshold.sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;
    m_motionSensorHandle = srv_sensor_start_listen(
                            SRV_SENSOR_MOTION_SHAKE,
                            (void*)&threshold,
                            &VappWallpaper3DMaple::onMotionSensorEvent,
                            (void*)this);
#endif
}


void VappWallpaper3DMaple::onReleaseView()
{
    VFX_OBJ_CLOSE(m_world);

    m_worldFrame = NULL;
    m_world = NULL;
    m_tree = NULL;
    m_petals = NULL;
    m_petals2 = NULL;
    m_butterfly = NULL;

    m_worldCameraTimeline = NULL;
    m_worldTimeline = NULL;
    m_worldAnim = NULL;
    m_worldCameraAnim = NULL;
    m_treetimeline = NULL;
    m_treeAnim = NULL;
    m_butterflytimeline = NULL;
    m_butterflyAnim = NULL;
    m_petalstimeline = NULL;
    m_petals2timeline = NULL;
    m_petalsAnim = NULL;

#if defined(MOTION_SENSOR_SUPPORT)
    if(m_motionSensorHandle != SRV_SENSOR_MOTION_NO_SLOT)
    {
        srv_sensor_stop_listen(m_motionSensorHandle);
        m_motionSensorHandle = SRV_SENSOR_MOTION_NO_SLOT;
    }
#endif
}


MMI_IMG_ID VappWallpaper3DMaple::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_3D_MAPLE_THUMBNAIL;
}

void VappWallpaper3DMaple::onSuspend()
{
    m_worldTimeline->stop();
    m_worldCameraTimeline->stop();
    m_treetimeline->stop();
    m_butterflytimeline->stop();
    m_butterflytimeline->setDuration(1);
    m_butterflytimeline->setStartDelay(0);
    m_butterflytimeline->setToValue(0.0f);
    m_butterflytimeline->start();
    m_petalstimeline->stop();
    m_petals2timeline->stop();
}

void VappWallpaper3DMaple::onResume()
{
    m_worldTimeline->start();
    m_worldCameraTimeline->start();
    m_treetimeline->start();
    m_butterflytimeline->start();
    m_petalstimeline->start();
    m_petals2timeline->start();
}

VfxBool VappWallpaper3DMaple::onAllowSuspendOnSwipe()
{
    return VFX_FALSE;
}

VfxBool VappWallpaper3DMaple::onAllowSuspendOnPenDown()
{
    return VFX_FALSE;
}

VfxBool VappWallpaper3DMaple::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            return VFX_TRUE;
        }
    }
    return VFX_TRUE;

}

void VappWallpaper3DMaple::onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds)
{

    VfxSize screenSize = getScreenSize();
    VfxS32 x = source->getBounds().origin.x;
    VfxS32 pastX = oldBounds.origin.x;

    VfxFloat t = (x *1.0) / (screenSize.width * (totalPage-1));
    m_targetLoc = t;

    if(m_worldCameraTimeline == NULL)
        return;

    //VfxFloat current_value = (*(VfxFloat *)(((vrt_canvas_timeline_struct *)m_worldCameraTimeline->m_timelineHandle)->active_parameters.target));

    if((x % screenSize.width == 0) && (pastX % screenSize.width == 0))
    {
        VfxU32 diff = vfxAbs((x % screenSize.width) - (pastX % screenSize.width));

        if(diff > 1)
            m_worldCameraTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        else
            m_worldCameraTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_worldCameraTimeline->setDuration(800 + (diff - 1) * 50);
    }
    else if((x % screenSize.width == 0) && (pastX % screenSize.width != 0))
    {
        m_worldCameraTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_worldCameraTimeline->setDuration(800);
    }
    else
    {
        m_worldCameraTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_worldCameraTimeline->setDuration(800);
    }
    m_worldCameraTimeline->setIsFromCurrent(VFX_TRUE);
    m_worldCameraTimeline->setToValue(t);
    m_worldCameraTimeline->start();

}


void VappWallpaper3DMaple::onEndOfButterflyTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(isCompleted)
    {
        m_butterflytimeline->setDuration(6000);
        m_butterflytimeline->setStartDelay(20000);
        m_butterflytimeline->setToValue(1.0f);
        m_butterflytimeline->start();
    }
}

void VappWallpaper3DMaple::onMotionSensorEvent(srv_sensor_type_enum type, void *sensor_data, void *user_data)
{
#if defined(MOTION_SENSOR_SUPPORT)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if(type == SRV_SENSOR_MOTION_SHAKE)
    {
        VappWallpaper3DMaple *obj = (VappWallpaper3DMaple*)user_data;
        obj->m_petals2timeline->start();
    }
#endif
}

#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__ */
