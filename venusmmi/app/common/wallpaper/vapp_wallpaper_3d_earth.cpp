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
 *  vapp_wallpaper_wave.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wave wallpaper class
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

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__

#include "vapp_wallpaper_3d_earth.h"

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
#include "vapp_hs_cp.h"

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

#include <math.h>

//#include "mmi_rp_app_venus_wallpaper_def.h"
#include "mmi_rp_app_venus_wallpaper_3d_earth_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "gdi_primitive.h"

#ifdef __cplusplus
}
#endif

#define PI 3.1415926535897932384626433832795f


/*****************************************************************************
 * Home screen UI componet: 3D Earth wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("3D Earth Wallpaper", VappWallpaper3DEarth, VappWallpaper);

VappWallpaper3DEarth::VappWallpaper3DEarth():
    m_space(NULL),
    m_moon(NULL)
{
}

void VappWallpaper3DEarth::onCreateView()
{
    VFX_OBJ_CREATE(m_space, VfxImageFrame, this);
    m_space->setResId(IMG_ID_VAPP_WALLPAPER_EARTH_SPACE);
    m_space->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_moon, VfxImageFrame, this);
    m_moon->setResId(IMG_ID_VAPP_WALLPAPER_EARTH_MOON);
    m_moon->setAnchor(0, 0.5);
    m_moon->setPos(VAPP_WALLPAPER_EARTH_MOON_POS_X,VAPP_WALLPAPER_EARTH_MOON_POS_Y);
    m_moon->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_earth, VappEarth, this);
}


void VappWallpaper3DEarth::onReleaseView()
{
}


MMI_IMG_ID VappWallpaper3DEarth::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_EARTH_THUMBNAIL;
}

void VappWallpaper3DEarth::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_3D_EARTH);
}

VfxBool VappWallpaper3DEarth::onAllowSuspendOnSwipe()
{
    return VFX_FALSE;
}


void VappWallpaper3DEarth::onSuspend()
{
    m_earth->suspend();
}

void VappWallpaper3DEarth::onResume()
{
    m_earth->resume();
}

VfxBool VappWallpaper3DEarth::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            return VFX_TRUE;
        }
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            m_earth->stopRot();
            return VFX_TRUE;
        }
        case VFX_PEN_EVENT_TYPE_UP:
        {
            if(m_earth->isStopRot())
            {
                m_earth->startRot();
                return VFX_TRUE;
            }
            
            VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.downTimeStamp);
            VfxS32 xDiff = event.predictPos.x - event.downPos.x;
            VfxS32 offset;

            if (tDiff < SWIPE_CRITERIA && VFX_ABS(xDiff) > SENSITIVITY)
            {
                if (xDiff > 0)
                {
                    m_earth->accerateRot(VappEarth::VAPP_EARTH_CCW_SWIPE);
                }
                else
                {
                    m_earth->accerateRot(VappEarth::VAPP_EARTH_CW_SWIPE);
                }
            }
            return VFX_TRUE;
        }
    }
    return VfxControl::onPenInput(event);

}


void VappWallpaper3DEarth::onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds)
{
    if (getTotalPage() <= 1)
    {
        return;
    }

    VfxS32 x = source->getBounds().origin.x;
    VfxS32 maxBoundsWidth = (totalPage-1)*source->getBounds().getWidth();
    
    // Check x value for fail-safe
    // bounds argument will exceeeds maxBounds
    x = (x < 0) ? (0) : (x);
    x = (x > maxBoundsWidth) ? (maxBoundsWidth) : (x);

    if (m_space && m_moon)
    {
        VfxSize size = m_space->getBounds().size;
        VfxPoint pos = m_space->getPos();

        VfxSize screenSize = getScreenSize();
        VfxS32 a, b, m;

        // Change the wallpaper position:
        //
        //               page width   page width   page width
        //   desktop   |------------|------------|------------|
        //
        //                 wallpaper width
        //   wallpaper |----------------------|
        //
        //                          |<---------- A ---------->|
        //
        //                          |<-- B -->|
        //
        // If the desktop moves X, the wallpaper should move M = X * (B / A).

        a = (totalPage-1)*source->getBounds().getWidth();
        b = size.width - screenSize.width;

        if (a > 0 && b > 0)
        {
            // calculate the bounds of the wallpaper
            m = x * b / a;

            // Check x value for fail-safe
            m = (m < 0) ? (0) : (m);
            m = (m > b) ? (b) : (m);

            // Change wallpaper position
            pos.x = -m;

            VfxS32 maxOffset = (screenSize.width)/4;
            VfxS32 moonPosX = -x * maxOffset / a + maxOffset;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);

            m_space->setPos(pos);
            m_moon->setPos(moonPosX, m_moon->getPos().y);

            VfxAutoAnimate::commit();
        }
    }
}


/***************************************************************************** 
 * VappEarthFrame
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappEarth", VappEarth, VfxFrame);


VappEarth::VappEarth():
    m_flagStopRot(VFX_FALSE),
    m_rotateBySwipe(0),
    m_curRotDir(VAPP_EARTH_CCW_SWIPE)
{
}


void VappEarth::onInit()
{
    VfxFrame::onInit();

    setSize(getParentFrame()->getSize());
    setBgColor(VFX_COLOR_TRANSPARENT);


    VfxMaterial *material;
    VfxPass *pass;
    VfxShaderProgram *program;

    // Material
    VFX_OBJ_CREATE(material, VfxMaterial, this);
    this->setMaterial(material);

    // Pass
    VFX_OBJ_CREATE(pass, VfxPass, material);
    material->setPass(0, pass);

    // Shader Program
#ifndef __MTK_TARGET__
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VAPP_WALLPAPER_EARTH_VERTEX_SHADER, VAPP_WALLPAPER_EARTH_FRAGMENT_SHADER));
    //VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("d:\\test\\globe\\globe.vs"), VFX_WSTR("d:\\test\\globe\\globe.fs")));
#else
    //VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("c:\\globe.vs"), VFX_WSTR("c:\\globe.fs")));
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VAPP_WALLPAPER_EARTH_VERTEX_SHADER, VAPP_WALLPAPER_EARTH_FRAGMENT_SHADER));
#endif
    pass->setShaderProgram(program);
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    VfxShaderVariable *var;

    VfxBool isBGRExt;
#ifndef __MTK_TARGET__
    isBGRExt = VFX_FALSE;
#else
    isBGRExt = VFX_TRUE;
#endif

    var = uniforms->addUniformVariable(VFX_STR("u_isBGRExt"), VFX_TYPE_ID_BOOL, 1);
    var->setValue((VfxBool)isBGRExt);

    VfxMatrix4f proj;
    proj.setPerspective(0.7f, (VfxFloat)this->getSize().width / (VfxFloat)this->getSize().height, 0.1f, 10.0f );
    var = uniforms->addUniformVariable(VFX_STR("u_invProjection"), VFX_TYPE_ID_MAT4, 1);
    var->setValue(inverse(proj));

    var = uniforms->addUniformVariable(VFX_STR("u_skipUpAreaRatio"), VFX_TYPE_ID_FLOAT, 1);
    var->setValue((VfxFloat)VAPP_WALLPAPER_EARTH_PRESION_TABLE_SKIP_UP_AREA_RATIO);

    var = uniforms->addUniformVariable(VFX_STR("u_skipDownAreaRatio"), VFX_TYPE_ID_FLOAT, 1);
    var->setValue((VfxFloat)VAPP_WALLPAPER_EARTH_PRESION_TABLE_SKIP_DOWN_AREA_RATIO);

    // reference timeline for light rotation
    VFX_OBJ_CREATE(m_refTlLightRot, VfxFloatTimeline, this);
    m_refTlLightRot->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTlLightRot->setTarget(this);
    m_refTlLightRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
    m_refTlLightRot->setFromValue(0.0f);
    m_refTlLightRot->setToValue(1.0f);
    m_refTlLightRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_refTlLightRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_refTlLightRot->setIsFromCurrent(VFX_TRUE);

    var = uniforms->addUniformVariable(VFX_STR("u_lightAngle"), VFX_TYPE_ID_FLOAT, 1);
    VfxFloatTimeline *tl;
    VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
    tl->setTarget(var);
    tl->setTimelineTime(m_refTlLightRot, 1.0f, 0.0f,VFX_TIMELINE_TIME_WRAP_TYPE_REPEAT);
    tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    tl->setFromValue(VFX_PI * 2);
    tl->setToValue(0.0f);
    m_refTlLightRot->start();

    // reference timeline for earth rotation
    VFX_OBJ_CREATE(m_refTlEarthRot, VfxFloatTimeline, this);
    m_refTlEarthRot->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTlEarthRot->setTarget(this);
    m_refTlEarthRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
    m_refTlEarthRot->setFromValue(0.0f);
    m_refTlEarthRot->setToValue(VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
    m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_refTlEarthRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_refTlEarthRot->setIsFromCurrent(VFX_TRUE);
    m_refTlEarthRot->m_signalStopped.connect(this, &VappEarth::onRefTlEarthRotStoppod);

    var = uniforms->addUniformVariable(VFX_STR("u_rot"), VFX_TYPE_ID_FLOAT, 1);
    VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
    tl->setTimelineTime(m_refTlEarthRot, 1.0f, 0.0f,VFX_TIMELINE_TIME_WRAP_TYPE_REPEAT);
    tl->setTarget(var);
    tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    tl->setFromValue(0.0f);
    tl->setToValue(1.0f);
    m_refTlEarthRot->start();

    // reference timeline for cloud rotation
    VFX_OBJ_CREATE(m_refTlCloudRot, VfxFloatTimeline, this);
    m_refTlCloudRot->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTlCloudRot->setTarget(this);
    m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
    m_refTlCloudRot->setFromValue(0.0f);
    m_refTlCloudRot->setToValue(VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
    m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_refTlCloudRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_refTlCloudRot->setIsFromCurrent(VFX_TRUE);

    var = uniforms->addUniformVariable(VFX_STR("u_rot_cloud"), VFX_TYPE_ID_FLOAT, 1);
    VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
    tl->setTimelineTime(m_refTlCloudRot, 1.0f, 0.0f,VFX_TIMELINE_TIME_WRAP_TYPE_REPEAT);
    tl->setTarget(var);
    tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    tl->setDurationTime(40000);
    tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    tl->setFromValue(0.0f);
    tl->setToValue(1.0f);
    m_refTlCloudRot->start();

    VfxImage2D *img;
    VfxTexture2D *tex;

    var = uniforms->addUniformVariable(VFX_STR("u_texture"), VFX_TYPE_ID_SAMPLER, 1);
    //VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR("d:\\test\\globe\\day.jpg")));
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (IMG_ID_VAPP_WALLPAPER_EARTH_DAY));
    VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
    tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
    var->setValue(tex);

    var = uniforms->addUniformVariable(VFX_STR("u_cloud"), VFX_TYPE_ID_SAMPLER, 1);
    //VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR("d:\\test\\globe\\cloud.png")));
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (IMG_ID_VAPP_WALLPAPER_EARTH_CLOUD));
    VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
    tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
    var->setValue(tex);

    var = uniforms->addUniformVariable(VFX_STR("u_night"), VFX_TYPE_ID_SAMPLER, 1);
    //VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR("d:\\test\\globe\\night.jpg")));
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (IMG_ID_VAPP_WALLPAPER_EARTH_NIGHT));
    VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
    tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
    var->setValue(tex);

    var = uniforms->addUniformVariable(VFX_STR("u_gloss"), VFX_TYPE_ID_SAMPLER, 1);
    //VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR("d:\\test\\globe\\gloss.jpg")));
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (IMG_ID_VAPP_WALLPAPER_EARTH_GLOSS));
    VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
    tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
    var->setValue(tex);    

    VfxImageBuffer imageBuf;
    imageBuf.ptr = (VfxU8*)GetBinary(VAPP_WALLPAPER_EARTH_DIST);
    imageBuf.pitchBytes = GDI_LCD_WIDTH * 3;
    imageBuf.width = GDI_LCD_WIDTH;
    imageBuf.height = GDI_LCD_HEIGHT - GDI_LCD_HEIGHT * (VAPP_WALLPAPER_EARTH_PRESION_TABLE_SKIP_UP_AREA_RATIO + (1-VAPP_WALLPAPER_EARTH_PRESION_TABLE_SKIP_DOWN_AREA_RATIO)) + 1;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB888;

    var = uniforms->addUniformVariable(VFX_STR("u_dist"), VFX_TYPE_ID_SAMPLER, 1);
    //VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR("c:\\dist.png")));
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VfxImageSrc(imageBuf)));
    VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
    tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
    var->setValue(tex);

    VfxCompositingMode *comp;
    VFX_OBJ_CREATE(comp, VfxCompositingMode, pass);
    comp->setDepthTestEnable(VFX_FALSE);
    comp->setDepthWriteEnable(VFX_FALSE);
    pass->setCompositingMode(comp);

    VfxBlender *blender;
    VFX_OBJ_CREATE(blender, VfxBlender, comp);
    comp->setBlender(blender);
}


void VappEarth::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappEarth::onRefTlEarthRotStoppod(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(isCompleted && m_rotateBySwipe>0)
    {
        VfxFloatTimeline *tl = (VfxFloatTimeline *)timeline; // it is m_refTlEarthRot
        tl->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        tl->setByValue(VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
        tl->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        m_refTlCloudRot->setByValue(VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
        m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_refTlCloudRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_refTlCloudRot->start();

        m_rotateBySwipe = 0;
    }
    else if(isCompleted && m_rotateBySwipe<0)
    {
        VfxFloatTimeline *tl = (VfxFloatTimeline *)timeline; // it is m_refTlEarthRot
        tl->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        tl->setByValue(-VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
        tl->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        m_refTlCloudRot->setByValue(-VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
        m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_refTlCloudRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_refTlCloudRot->start();

        m_rotateBySwipe = 0;
    }
}


VfxBool VappEarth::isStopRot()
{
    return m_flagStopRot;
}


void VappEarth::stopRot()
{
    if(m_rotateBySwipe == 0)
    {
        m_refTlEarthRot->setDuration(m_refTlEarthRot->getDuration()/7.5);
        m_refTlCloudRot->setDuration(m_refTlCloudRot->getDuration()/7.5);
    }
    else
    {
        m_refTlEarthRot->setDuration(m_refTlEarthRot->getDuration()/3);
        m_refTlCloudRot->setDuration(m_refTlCloudRot->getDuration()/3);
    }

    if(m_curRotDir == VAPP_EARTH_CCW_SWIPE)
    {
        m_refTlEarthRot->setByValue(VAPP_WALLPAPER_EARTH_EAR_ROT_RPM * 0.1);
        m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_refTlEarthRot->setRepeatCount(1);
        m_refTlEarthRot->start();

        m_refTlCloudRot->setByValue(VAPP_WALLPAPER_EARTH_CLD_ROT_RPM * 0.1);
        m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_refTlCloudRot->setRepeatCount(1);
        m_refTlCloudRot->start();
    }
    else
    {
        m_refTlEarthRot->setByValue(-VAPP_WALLPAPER_EARTH_EAR_ROT_RPM * 0.1);
        m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_refTlEarthRot->setRepeatCount(1);
        m_refTlEarthRot->start();
        
        m_refTlCloudRot->setByValue(-VAPP_WALLPAPER_EARTH_CLD_ROT_RPM * 0.1);
        m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_refTlCloudRot->setRepeatCount(1);
        m_refTlCloudRot->start();
    }
    
    m_flagStopRot = MMI_TRUE;
    m_rotateBySwipe = 0;
}


void VappEarth::startRot()
{
    m_flagStopRot = MMI_FALSE;
    m_refTlLightRot->start();
    if(m_curRotDir == VAPP_EARTH_CCW_SWIPE)
    {
        m_refTlEarthRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        m_refTlEarthRot->setIsFromCurrent(VFX_TRUE);
        m_refTlEarthRot->setByValue(VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
        m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_refTlEarthRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_refTlEarthRot->start();

        m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        m_refTlCloudRot->setIsFromCurrent(VFX_TRUE);
        m_refTlCloudRot->setByValue(VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
        m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_refTlCloudRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_refTlCloudRot->start();
    }
    else
    {
        m_refTlEarthRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        m_refTlEarthRot->setIsFromCurrent(VFX_TRUE);
        m_refTlEarthRot->setByValue(-VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
        m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_refTlEarthRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_refTlEarthRot->start();

        m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ROT_TIME_PER_CIR);
        m_refTlCloudRot->setIsFromCurrent(VFX_TRUE);
        m_refTlCloudRot->setByValue(-VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
        m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_refTlCloudRot->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_refTlCloudRot->start();
    }
}


void VappEarth::suspend()
{
    m_refTlEarthRot->stop();
    m_refTlCloudRot->stop();
    m_refTlLightRot->stop();
    m_flagStopRot = MMI_TRUE;
    m_rotateBySwipe = 0;
}


void VappEarth::resume()
{
    startRot();
}


void VappEarth::accerateRot(VappEarthSwipeDirEnum swipeDir)
{
    if(swipeDir == VAPP_EARTH_CCW_SWIPE)
    {
        m_rotateBySwipe = VFX_ABS(m_rotateBySwipe);

        if(m_rotateBySwipe == VAPP_WALLPAPER_EARTH_MAX_SWIPE_NUM)
        {
            m_refTlEarthRot->setByValue(VFX_ABS(m_refTlEarthRot->getToValue()));
            m_refTlEarthRot->start();
            m_refTlCloudRot->setByValue(VFX_ABS(m_refTlCloudRot->getToValue()));
            m_refTlCloudRot->start();
        }
        // speed up when swipe again, but it has limit number.
        else if(m_rotateBySwipe < VAPP_WALLPAPER_EARTH_MAX_SWIPE_NUM)
        {
            m_rotateBySwipe++;
            
            m_refTlEarthRot->setIsFromCurrent(VFX_TRUE);
            m_refTlEarthRot->setDuration(VAPP_WALLPAPER_EARTH_ACCERATION_TIME / VFX_ABS(m_rotateBySwipe+1));
            m_refTlEarthRot->setByValue(0.5*VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
            m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            m_refTlEarthRot->setRepeatCount(1);
            m_refTlEarthRot->start();
            
            m_refTlCloudRot->setIsFromCurrent(VFX_TRUE);
            m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ACCERATION_TIME / VFX_ABS(m_rotateBySwipe+1));
            m_refTlCloudRot->setByValue(0.5*VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
            m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            m_refTlCloudRot->setRepeatCount(1);
            m_refTlCloudRot->start();
        }
        else
        {
            m_refTlEarthRot->start();
            m_refTlCloudRot->start();
        }
        m_curRotDir = VAPP_EARTH_CCW_SWIPE;
    }
    else
    {
        m_rotateBySwipe = -VFX_ABS(m_rotateBySwipe);
        
        if(m_rotateBySwipe == -VAPP_WALLPAPER_EARTH_MAX_SWIPE_NUM)
        {
            m_refTlEarthRot->setByValue(-VFX_ABS(m_refTlEarthRot->getToValue()));
            m_refTlEarthRot->start();
            m_refTlCloudRot->setByValue(-VFX_ABS(m_refTlCloudRot->getToValue()));
            m_refTlCloudRot->start();
            
        }
        // speed up when swipe again, but it has limit number.
        else if(m_rotateBySwipe > -VAPP_WALLPAPER_EARTH_MAX_SWIPE_NUM)
        {
            m_rotateBySwipe--;
                    
            m_refTlEarthRot->setIsFromCurrent(VFX_TRUE);
            m_refTlEarthRot->setDuration(VAPP_WALLPAPER_EARTH_ACCERATION_TIME / VFX_ABS(m_rotateBySwipe-1));
            m_refTlEarthRot->setByValue(-0.5*VAPP_WALLPAPER_EARTH_EAR_ROT_RPM);
            m_refTlEarthRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            m_refTlEarthRot->setRepeatCount(1);
            m_refTlEarthRot->start();
            
            m_refTlCloudRot->setIsFromCurrent(VFX_TRUE);
            m_refTlCloudRot->setDuration(VAPP_WALLPAPER_EARTH_ACCERATION_TIME / VFX_ABS(m_rotateBySwipe-1));
            m_refTlCloudRot->setByValue(-0.5*VAPP_WALLPAPER_EARTH_CLD_ROT_RPM);
            m_refTlCloudRot->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
            m_refTlCloudRot->setRepeatCount(1);
            m_refTlCloudRot->start();
        }
        else
        {
            m_refTlEarthRot->start();
            m_refTlCloudRot->start();
        }
        m_curRotDir = VAPP_EARTH_CW_SWIPE;
    }
}
#endif
