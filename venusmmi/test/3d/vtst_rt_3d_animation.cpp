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
 *  vtst_rt_3d_animation.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d animation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"


/***************************************************************************** 
 * Class VtstRt3DAnimation
 *****************************************************************************/

class VtstRt3DAnimation : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;


// Constructor / Destructor
public:
    VtstRt3DAnimation()
    : m_frame(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Animation test"));
    }

    virtual int start()
    {        
        return 8;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_OBJ_CLOSE(m_frame);

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("2D Keyframe OK?"));

                VfxS32 w = (main_screen_size.width) / 6;
                VfxS32 h = main_screen_size.height / 5;
    
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                VfxFrame *frame;
                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *kf_tl;

                /* Step */
                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, frame, (5, VFX_TYPE_ID_POINT));
                kfs->setKeyframe(0, 0,    &VfxPoint(w * 1, h * 1));
                kfs->setKeyframe(1, 500,  &VfxPoint(w * 2, h * 1 - 50));
                kfs->setKeyframe(2, 1000, &VfxPoint(w * 3, h * 1));
                kfs->setKeyframe(3, 1500, &VfxPoint(w * 4, h * 1 - 50));
                kfs->setKeyframe(4, 2000, &VfxPoint(w * 5, h * 1));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, frame);
                kf_tl->setTarget(frame);
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_STEP);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                /* Linear */
                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, frame, (5, VFX_TYPE_ID_POINT));
                kfs->setKeyframe(0, 0,    &VfxPoint(w * 1, h * 2));
                kfs->setKeyframe(1, 500,  &VfxPoint(w * 2, h * 2 - 50));
                kfs->setKeyframe(2, 1000, &VfxPoint(w * 3, h * 2));
                kfs->setKeyframe(3, 1500, &VfxPoint(w * 4, h * 2 - 50));
                kfs->setKeyframe(4, 2000, &VfxPoint(w * 5, h * 2));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, frame);
                kf_tl->setTarget(frame);
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                /* Spline */
                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, frame, (5, VFX_TYPE_ID_POINT));
                kfs->setKeyframe(0, 0,    &VfxPoint(w * 1, h * 3));
                kfs->setKeyframe(1, 500,  &VfxPoint(w * 2, h * 3 - 50));
                kfs->setKeyframe(2, 1000, &VfxPoint(w * 3, h * 3));
                kfs->setKeyframe(3, 1500, &VfxPoint(w * 4, h * 3 - 50));
                kfs->setKeyframe(4, 2000, &VfxPoint(w * 5, h * 3));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, frame);
                kf_tl->setTarget(frame);
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();
                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("3D Keyframe OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setScreen(
                    0,
                    0,
                    (VfxFloat)main_screen_size.width,
                    (VfxFloat)main_screen_size.height,
                    (VfxFloat)-main_screen_size.height,
                    (VfxFloat)main_screen_size.height);
                world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxBoxMesh *box;
                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *kf_tl;

                /* Step */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 1 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 1, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 1 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_STEP);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));


                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                /* Spline */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));


                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                /* Slerp */
                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
                box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
                kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
                kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
                kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, box);
                kf_tl->setTarget(box);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                /* Squad */
                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
                box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 5, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
                kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
                kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
                kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, box);
                kf_tl->setTarget(box);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SQUAD);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();
                break;
            }
        case 2:
            {
                confirm(VFX_WSTR("3D From/To Timline OK?"));

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
                world->setActiveCamera(camera);

                /* Mesh */
                VfxSphereMesh *mesh;
                VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);

                /* Timeline */
                VfxFloatTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxFloatTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_NODE_PROPERTY_ID_OPACITY);
                tl->setFromValue(0.0f);
                tl->setToValue(1.0f);
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                break;
            }
        case 3:
            {
                confirm(VFX_WSTR("Color Keyframe OK?"));

                VfxS32 w = main_screen_size.width / 2;
                VfxS32 h = main_screen_size.height / 2;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(w, h);
                m_frame->setPos(w/2, h/2);

                /* Color keyframe timeline */
                VfxKeyframeSequence *kfs;
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, m_frame, (4, VFX_TYPE_ID_COLOR));
                kfs->setKeyframe(0, 0,    &VfxColor(VFX_COLOR_WHITE));
                kfs->setKeyframe(1, 667,  &VfxColor(VFX_COLOR_YELLOW));
                kfs->setKeyframe(2, 1333, &VfxColor(VFX_COLOR_GREEN));
                kfs->setKeyframe(3, 2000, &VfxColor(VFX_COLOR_WHITE));

                VfxKeyframeTimeline *kf_tl;
                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, m_frame);
                kf_tl->setTarget(m_frame);
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->start();

                break;
            }
        case 4:
            {
                confirm(VFX_WSTR("Virtual Animatable Property OK?"));

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
                world->setActiveCamera(camera);

                VfxGroup *group;
                VfxBoxMesh *mesh;
                VfxVector3fTimeline *tl;
                VfxQuaternionfTimeline *qtl;
                /* Group 1 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(-2, 0, 0);
                VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
                VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                tl->setFromValue(VfxVector3f(0, 0, 0));
                tl->setToValue(VfxVector3f(0, 2, 0));
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                /* Group 2 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(2, 0, 0);
                VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
                VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_SCALE);
                tl->setFromValue(VfxVector3f(0.5f));
                tl->setToValue(VfxVector3f(2.0f));
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                /* Group 3 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(0, 0, -2);
                VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
                VFX_OBJ_CREATE(qtl, VfxQuaternionfTimeline, mesh);
                qtl->setTarget(mesh);
                qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                qtl->setFromValue(VfxQuaternionf(1,0,0,0));
                qtl->setToValue(VfxQuaternionf(0,1,0,0));
                qtl->setDuration(2000);
                qtl->setAutoReversed(VFX_TRUE);
                qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                qtl->start();

                /* Group 4 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(0, 0, 2);
                VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
                VFX_OBJ_CREATE(qtl, VfxQuaternionfTimeline, mesh);
                qtl->setTarget(mesh);
                qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                qtl->setFromValue(VfxQuaternionf(1,0,0,0));
                qtl->setToValue(VfxQuaternionf(0,1,0,0));
                qtl->setDuration(2000);
                qtl->setAutoReversed(VFX_TRUE);
                qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                qtl->start();
                VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_SCALE);
                tl->setFromValue(VfxVector3f(0.5f));
                tl->setToValue(VfxVector3f(2.0f));
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();
                VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                tl->setFromValue(VfxVector3f(0, 0, 0));
                tl->setToValue(VfxVector3f(0, 2, 0));
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();
                break;
            }
        case 5:
            {
                confirm(VFX_WSTR("Shader Uniform Timeline OK?"));

                VfxS32 w = main_screen_size.width / 2;
                VfxS32 h = main_screen_size.height / 2;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(w, h);
                m_frame->setPos(w/2, h/2);

                VfxMaterial *material;
                VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
                m_frame->setMaterial(material);

                VfxPass *pass;
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                static const vrt_char fShader[] =
                "precision mediump float;           \n"
                "varying vec4 vColor;               \n"
                "varying vec2 vTexCoord;            \n"
                "uniform vec4 uColor0;              \n"
                "uniform vec4 uColor1;              \n"
                "void main()                        \n"
                "{                                  \n"
                "   gl_FragColor = mix(uColor0, uColor1, vTexCoord.x);  \n"
                "}                          \n";
                VfxShaderProgram *program;
                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, fShader));
                pass->setShaderProgram(program);

                VfxShaderUniforms *uniforms;
                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
                pass->addShaderUniforms(uniforms);

                VfxShaderVariable *var;
                VfxVector4fTimeline *tl;                

                var = uniforms->addUniformVariable(VFX_STR("uColor0"), VFX_TYPE_ID_VEC4, 1);
                VFX_OBJ_CREATE(tl, VfxVector4fTimeline, var);
                tl->setTarget(var);
                tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4);
                tl->setFromValue(VfxVector4f(1.0f, 0.0f, 0.0f, 1.0f));
                tl->setToValue(VfxVector4f(0.0f, 1.0f, 0.0f, 1.0f));
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                var = uniforms->addUniformVariable(VFX_STR("uColor1"), VFX_TYPE_ID_VEC4, 1);
                VFX_OBJ_CREATE(tl, VfxVector4fTimeline, var);
                tl->setTarget(var);
                tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4);
                tl->setFromValue(VfxVector4f(1.0f, 1.0f, 0.0f, 1.0f));
                tl->setToValue(VfxVector4f(0.0f, 0.0f, 1.0f, 1.0f));
                tl->setDuration(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                break;
            }
        case 6:
            {
                confirm(VFX_WSTR("Start Delay OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setScreen(
                    0,
                    0,
                    (VfxFloat)main_screen_size.width,
                    (VfxFloat)main_screen_size.height,
                    (VfxFloat)-main_screen_size.height,
                    (VfxFloat)main_screen_size.height);
                world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *kf_tl;


                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setStartDelay(500);
                kf_tl->setDuration(2000);
                kf_tl->start();

                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setStartDelay(1000);
                kf_tl->setDuration(2000);
                kf_tl->start();


                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 4 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 4 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 4, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setStartDelay(1500);
                kf_tl->setDuration(2000);
                kf_tl->start();

                break;
            }
        case 7:
            {
                confirm(VFX_WSTR("KeyFrame Speed Control OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setScreen(
                    0,
                    0,
                    (VfxFloat)main_screen_size.width,
                    (VfxFloat)main_screen_size.height,
                    (VfxFloat)-main_screen_size.height,
                    (VfxFloat)main_screen_size.height);
                world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *kf_tl;


                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->start();

                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(4000);
                kf_tl->start();


                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 4 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 4 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 4, 0));

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(8000);
                kf_tl->start();

                break;
            }
        }

        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_animation(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DAnimation);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRt3DAutoAnimate
 *****************************************************************************/

class VtstRt3DAutoAnimate : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxBoxMesh *m_mesh;

// Constructor / Destructor
public:
    VtstRt3DAutoAnimate() : m_frame(NULL), m_mesh(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Auto Animation test"));
    }

    virtual int start()
    {        
        return 4;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("No animation OK?"));
                VfxMsec du = 4000;
                
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
                world->setActiveCamera(camera);

                VfxGroup *group;
                VfxBoxMesh *mesh;

                /* Group 1 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(-2, 0, 0);
                VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
                mesh->setAutoAnimate(VFX_TRUE);

                // auto animation
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(du);
                
                // auto animation
                mesh->setTranslation(VfxVector3f(0, 2, 0));

                VfxAutoAnimate::commit();

                break;
            }
        case 1:
            {
                VFX_OBJ_CLOSE(m_frame);

                confirm(VFX_WSTR("Initial time animation OK?"));
                VfxMsec du = 4000;
                
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
                world->setActiveCamera(camera);

                VfxGroup *group;
                VfxBoxMesh *mesh;

                /* Group 1 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(-2, 0, 0);
                VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
                mesh->setAutoAnimate(VFX_TRUE);

                // auto animation
                VfxAutoAnimate::initAnimateBegin();
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDuration(du);
                
                // auto animation
                mesh->setTranslation(VfxVector3f(0, 2, 0));

                VfxAutoAnimate::commit();
                VfxAutoAnimate::initAnimateEnd();

                break;
            }
        case 2:
            {
                VFX_OBJ_CLOSE(m_frame);

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
                world->setActiveCamera(camera);

                VfxGroup *group;

                /* Group 1 */
                VFX_OBJ_CREATE(group, VfxGroup, world);
                group->setTranslation(-2, 0, 0);
                VFX_OBJ_CREATE(m_mesh, VfxBoxMesh, group);
                m_mesh->setAutoAnimate(VFX_TRUE);

                return 0;
            }
        case 3:
            {
                confirm(VFX_WSTR("Normal animation OK?"));
                
                // auto animation
                m_mesh->setTranslation(VfxVector3f(0, 2, 0));

                break;
            }
        }
        
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_auto_animate(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DAutoAnimate);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRtTimelineChain
 *****************************************************************************/

class VtstRtTimelineChain : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    VtstRtTimelineChain() : 
        m_frame(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Timeline Chain test"));
    }

    virtual int start()
    {
        return 6;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_OBJ_CLOSE(m_frame);

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("Timeline Chain OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VfxFloatTimeline *t;
                VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
                t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                t->setTarget(m_frame);
                t->setDuration(1000);
                t->setFromValue(0.0f);
                t->setToValue(1.0f);
                t->setAutoReversed(VFX_TRUE);
                t->setRepeatCount(3);

                /* Start reference timeline */
                t->start();

                /* create animation */
                VfxAnimation *animation;
                VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setScreen(
                    0,
                    0,
                    (VfxFloat)main_screen_size.width,
                    (VfxFloat)main_screen_size.height,
                    (VfxFloat)-main_screen_size.height,
                    (VfxFloat)main_screen_size.height);
                world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxBoxMesh *box;
                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *kf_tl;

                /* Step */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 1 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 1, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 1 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));
                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_STEP);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);

                /* Linear */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));
                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);

                /* Spline */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));
                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);

                /* Slerp */
                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
                box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
                kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
                kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
                kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
                kf_tl->setTarget(box);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);

                /* Squad */
                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
                box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 5, 0));
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
                kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
                kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
                kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
                kf_tl->setTarget(box);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SQUAD);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);

                VfxU32 userData = 0x12345678;
                kf_tl->setCustomTimingFunc(testTimingFuncCallback, &userData, sizeof(userData));

                /* use control timeline */
                animation->setTimelineTime(t);

                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("Animation Set OK?"));

                VfxS32 w = (main_screen_size.width) / 6;
                VfxS32 h = main_screen_size.height / 5;
    
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VfxFloatTimeline *t;
                VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
                t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                t->setTarget(m_frame);
                t->setDuration(1000);
                t->setFromValue(1.0f);
                t->setToValue(3.0f);
                t->setAutoReversed(VFX_TRUE);
                t->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

                /* create animation */
                VfxAnimation *animation;
                VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

                VfxFrame *frame;
                VfxPointTimeline *kf_tl;

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 1, h * 1));
                kf_tl->setToValue(VfxPoint(w * 5, h * 1));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setDuration(2000);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 1, h * 2));
                kf_tl->setToValue(VfxPoint(w * 3, h * 2));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setStartTime(0);
                kf_tl->setDuration(1000);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 3, h * 3));
                kf_tl->setToValue(VfxPoint(w * 5, h * 3));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setStartTime(1000);
                kf_tl->setDuration(1000);

                animation->setTimelineTime(t, 0.5f, -0.5f);

                /* Start reference timeline */
                t->start();
                break;
            }
        case 2:
            {
                confirm(VFX_WSTR("Custom Interpolation + KeyFrame OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* Wrold */
                VfxWorld *world;
                VFX_OBJ_CREATE(world, VfxWorld, m_frame);
                m_frame->setWorld(world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, world);
                camera->setScreen(
                    0,
                    0,
                    (VfxFloat)main_screen_size.width,
                    (VfxFloat)main_screen_size.height,
                    (VfxFloat)-main_screen_size.height,
                    (VfxFloat)main_screen_size.height);
                world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *kf_tl;

                /* Step */
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
                kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 1 - 50, 0));
                kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 1, 0));
                kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 1 - 50, 0));
                kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));

                VfxU32 userData = 0x12345678;

                VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
                kf_tl->setTarget(mesh);
                kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
                kf_tl->setKeyframeSequence(kfs);
                kf_tl->setDuration(2000);
                kf_tl->setAutoReversed(VFX_TRUE);
                kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                kf_tl->setCustomInterpolateFunc(testInterpolateFuncCallback, &userData, sizeof(userData));
                kf_tl->start();

                break;
            }
        case 3:
            {
                confirm(VFX_WSTR("Pulse timeline time OK?"));

                VfxS32 w = (main_screen_size.width) / 6;
                VfxS32 h = main_screen_size.height / 5;
    
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VfxFloatTimeline *t;
                VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
                t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                t->setTarget(m_frame);
                t->setDuration(1000);
                t->setFromValue(2.0f);
                t->setToValue(2.0f);
                t->setAutoReversed(VFX_TRUE);
                t->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

                /* create animation */
                VfxAnimation *animation;
                VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

                VfxFrame *frame;
                VfxPointTimeline *kf_tl;

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 1, h * 1));
                kf_tl->setToValue(VfxPoint(w * 5, h * 1));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setDuration(2000);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 1, h * 2));
                kf_tl->setToValue(VfxPoint(w * 3, h * 2));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setStartTime(0);
                kf_tl->setDuration(1000);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 3, h * 3));
                kf_tl->setToValue(VfxPoint(w * 5, h * 3));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setStartTime(1000);
                kf_tl->setDuration(1000);

                animation->setTimelineTime(t);

                /* Start reference timeline */
                t->start();
                break;
            }
        case 4:
            {
                confirm(VFX_WSTR("Wrap Type OK?"));

                VfxS32 w = (main_screen_size.width) / 7;
                VfxS32 h = main_screen_size.height / 5;
    
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VfxFloatTimeline *t;
                VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
                t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                t->setTarget(m_frame);
                t->setDuration(2000);
                t->setFromValue(-2.0f);
                t->setToValue(3.0f);
                t->setAutoReversed(VFX_TRUE);
                t->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

                /* create animation */
                VfxAnimation *animation;
                VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

                VfxFrame *frame;
                VfxPointTimeline *kf_tl;

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 3, h * 1));
                kf_tl->setToValue(VfxPoint(w * 4, h * 1));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setDuration(2000);
                kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 3, h * 2));
                kf_tl->setToValue(VfxPoint(w * 4, h * 2));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setDuration(1000);
                kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_NONE);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 3, h * 3));
                kf_tl->setToValue(VfxPoint(w * 4, h * 3));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setDuration(1000);
                kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_REPEAT);

                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
                kf_tl->setTarget(frame);
                kf_tl->setFromValue(VfxPoint(w * 3, h * 4));
                kf_tl->setToValue(VfxPoint(w * 4, h * 4));
                kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                kf_tl->setDuration(1000);
                kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_MIRROR);

                /* Start reference timeline */
                t->start();
                break;
            }
        case 5:
            {
                confirm(VFX_WSTR("Multi-level timeline chain OK?"));

                VfxS32 w = (main_screen_size.width) / 7;
                VfxS32 h = main_screen_size.height / 5;
    
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VfxFloatTimeline *mainTl;
                VFX_OBJ_CREATE(mainTl, VfxFloatTimeline, m_frame);
                mainTl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                mainTl->setTarget(m_frame);
                mainTl->setDuration(2000);
                mainTl->setFromValue(0.0f);
                mainTl->setToValue(1.0f);
                mainTl->setAutoReversed(VFX_TRUE);
                mainTl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

                /* create animation */
                VfxFloatTimeline *tl1;
                VFX_OBJ_CREATE(tl1, VfxFloatTimeline, m_frame);
                tl1->setTarget(m_frame);
                tl1->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                tl1->setFromValue(0.0f);
                tl1->setToValue(1.0f);
                tl1->setTimelineTime(mainTl, 2.0f, -1.0f, VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP);

                VfxFloatTimeline *tl2;
                VFX_OBJ_CREATE(tl2, VfxFloatTimeline, m_frame);
                tl2->setTarget(m_frame);
                tl2->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                tl2->setFromValue(0.0f);
                tl2->setToValue(1.0f);
                tl2->setTimelineTime(mainTl, 2.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP);

                VfxFrame *frame1a;
                VFX_OBJ_CREATE(frame1a, VfxFrame, m_frame);
                frame1a->setSize(VfxSize(10, 10));
                frame1a->setBgColor(VFX_COLOR_WHITE);

                VfxPointTimeline *tl1a;
                VFX_OBJ_CREATE(tl1a, VfxPointTimeline, m_frame);
                tl1a->setTarget(frame1a);
                tl1a->setFromValue(VfxPoint(w * 1, h * 1));
                tl1a->setToValue(VfxPoint(w * 6, h * 1));
                tl1a->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                tl1a->setTimelineTime(tl1);

                VfxFrame *frame1b;
                VFX_OBJ_CREATE(frame1b, VfxFrame, m_frame);
                frame1b->setSize(VfxSize(10, 10));
                frame1b->setBgColor(VFX_COLOR_WHITE);
                
                VfxPointTimeline *tl1b;
                VFX_OBJ_CREATE(tl1b, VfxPointTimeline, m_frame);
                tl1b->setTarget(frame1b);
                tl1b->setFromValue(VfxPoint(w * 1, h * 2));
                tl1b->setToValue(VfxPoint(w * 6, h * 2));
                tl1b->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                tl1b->setTimelineTime(tl2);

                /* Start reference timeline */
                mainTl->start();
                break;
            }
        }
        return -1;
    }

    static VfxTimelineInterpolationRetEnum testInterpolateFuncCallback(
        void *output, 
        const void *fromValue, 
        const void *toValue, 
        VfxTypeIdEnum typeId, 
        VfxFloat t,  
        void *data, 
        VfxU32 dataSize)
    {
        VFX_DEV_ASSERT(data != NULL && dataSize == sizeof(VfxU32));
        VFX_DEV_ASSERT(*(VfxU32 *)data == 0x12345678);
        
        return VFX_TIMELINE_INTERPOLATION_RET_DONE;
    }

    static VfxFloat testTimingFuncCallback(
        VfxFloat t,
        void *data,
        VfxU32 dataSize)
    {
        VFX_DEV_ASSERT(data != NULL && dataSize == sizeof(VfxU32));
        VFX_DEV_ASSERT(*(VfxU32 *)data == 0x12345678);
        return t;
    }
};


VtstTestResultEnum vtst_rt_3d_timeline_chain(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineChain);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRtTimelineChainCurrentTo
 *****************************************************************************/

class VtstRtTimelineChainCurrentTo : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxFloatTimeline *m_mainTl;
    VfxU32 m_step;

// Constructor / Destructor
public:
    VtstRtTimelineChainCurrentTo() : 
        m_frame(NULL),
        m_mainTl(NULL),
        m_step(0)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Timeline Chain current-to"));
    }

    virtual int start()
    {
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_OBJ_CLOSE(m_frame);

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("Press key and current-to OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VFX_OBJ_CREATE(m_mainTl, VfxFloatTimeline, m_frame);
                m_mainTl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                m_mainTl->setTarget(m_frame);
                m_mainTl->setDuration(500);
                m_mainTl->setIsFromCurrent(VFX_TRUE);
                m_mainTl->setToValue(0.0f);

                VfxFrame *frame;
                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                
                VfxPointTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxPointTimeline, m_frame);
                tl->setTarget(frame);
                tl->setFromValue(VfxPoint(w * 1, h * 1));
                tl->setToValue(VfxPoint(w * 5, h * 1));
                tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                tl->setTimelineTime(m_mainTl);

                break;
            }
        }

        return -1;
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            m_mainTl->setToValue(m_step % 2 == 0 ? 1.0f : 0.0f);
            m_mainTl->start();

            m_step++;
        }

        return VtstRtScr::onPenInput(event);
    };
};


VtstTestResultEnum vtst_rt_3d_timeline_chain_current_to(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineChainCurrentTo);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRtTimelineChainToStep
 *****************************************************************************/

class VtstRtTimelineChainCurrentBy : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxFloatTimeline *m_mainTl;
    VfxU32 m_step;

// Constructor / Destructor
public:
    VtstRtTimelineChainCurrentBy() : 
        m_frame(NULL),
        m_mainTl(NULL),
        m_step(0)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Timeline Chain current-by"));
    }

    virtual int start()
    {
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_OBJ_CLOSE(m_frame);

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("Press key and current-by OK?"));

                VfxS32 w = main_screen_size.width / 6;
                VfxS32 h = main_screen_size.height / 6;

                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

                /* create reference time */
                VFX_OBJ_CREATE(m_mainTl, VfxFloatTimeline, m_frame);
                m_mainTl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
                m_mainTl->setTarget(m_frame);
                m_mainTl->setDuration(500);
                m_mainTl->setIsFromCurrent(VFX_TRUE);
                m_mainTl->setByValue(1.0f);

                VfxFrame *frame;
                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setSize(VfxSize(10, 10));
                frame->setBgColor(VFX_COLOR_WHITE);
                
                VfxPointTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxPointTimeline, m_frame);
                tl->setTarget(frame);
                tl->setFromValue(VfxPoint(w * 1, h * 1));
                tl->setToValue(VfxPoint(w * 5, h * 1));
                tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                tl->setTimelineTime(m_mainTl);

                break;
            }
        }

        return -1;
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            m_mainTl->setByValue(m_step % 2 == 0 ? 1.0f : -1.0f);
            m_mainTl->start();

            m_step++;            
        }

        return VtstRtScr::onPenInput(event);
    };
};


VtstTestResultEnum vtst_rt_3d_timeline_chain_current_by(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineChainCurrentBy);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRtTimelineRestart
 *****************************************************************************/

class VtstRtTimelineRestart : public VtstRtScr
{
// Variable
public:
    VfxVector3fTimeline *m_tl;


// Constructor / Destructor
public:
    VtstRtTimelineRestart()
    : m_tl(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Timeline Restart test"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = (main_screen_size.width) / 6;
        VfxS32 h = main_screen_size.height / 5;


        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

        VFX_OBJ_CREATE(m_tl, VfxVector3fTimeline, mesh);
        m_tl->setTarget(mesh);
        m_tl->setFromValue(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
        m_tl->setToValue(VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));
        m_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        m_tl->setDuration(2000);
        m_tl->setAutoReversed(VFX_TRUE);
        m_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    }

    virtual int start()
    {
        return 3;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("Start Infinite timeline OK?"));
                m_tl->start();
                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("Restart Infinite timeline OK?"));
                m_tl->setRepeatCount(3);
                m_tl->start();
                break;
            }
        case 2:
            {
                confirm(VFX_WSTR("Restart finite timeline OK?"));
                m_tl->start();
                break;
            }
        }
        return -1;
    }

};


VtstTestResultEnum vtst_rt_3d_timeline_restart(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineRestart);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRtTimelineStop
 *****************************************************************************/

class VtstRtTimelineStop : public VtstRtScr
{
// Variable
public:
    VfxFloatTimeline *m_tl;


// Constructor / Destructor
public:
    VtstRtTimelineStop()
    : m_tl(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Timeline Time Life cycle test"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = (main_screen_size.width) / 6;
        VfxS32 h = main_screen_size.height / 5;


        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));


        /* create reference time */

        VFX_OBJ_CREATE(m_tl, VfxFloatTimeline, this);
        m_tl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        m_tl->setTarget(this);
        m_tl->setDuration(1000);
        m_tl->setFromValue(0.0f);
        m_tl->setToValue(1.0f);
        m_tl->setAutoReversed(VFX_TRUE);
        m_tl->setRepeatCount(3);

        VfxVector3fTimeline *t;
        VFX_OBJ_CREATE(t, VfxVector3fTimeline, mesh);
        t->setTarget(mesh);        
        t->setFromValue(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
        t->setToValue(VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));
        t->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        t->setDuration(2000);
        t->setTimelineTime(m_tl);
    }

    virtual int start()
    {
        return 4;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
        case 0:
            {
                m_tl->start();
                return 4000;
            }
        case 1:
            {
                invalidate();
                return 0;
            }
        case 2:
            {
                confirm(VFX_WSTR("Restart another timeline OK?"));

                VfxFloatTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxFloatTimeline, this);
                tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
                tl->setTarget(this);
                tl->setDuration(1000);
                tl->setFromValue(0.0f);
                tl->setToValue(1.0f);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(3);
                tl->start();
                break;
            }
        case 3:
            {
                confirm(VFX_WSTR("Start 3 sec timeline OK?"));
                
                m_tl->start();
                break;
            }
        }
        return -1;
    }

};


VtstTestResultEnum vtst_rt_3d_timeline_stop(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineStop);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRtTimerTrigger3DTimeline
 *****************************************************************************/

class VtstRtTimerTrigger3DTimeline : public VtstRtScr
{
// Variable
public:
    VfxSphereMesh *mesh;

// Constructor / Destructor
public:
    VtstRtTimerTrigger3DTimeline()
    : mesh(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Timer Trigger 3D Timeline test"));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)getSize().width,
            (VfxFloat)getSize().height,
            (VfxFloat)-getSize().height,
            (VfxFloat)getSize().height);
        world->setActiveCamera(camera);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

    }

    virtual int start()
    {
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
        case 0:
            {
                VfxTimer* pTimer;
                VFX_OBJ_CREATE(pTimer, VfxTimer, this);
                pTimer->setStartDelay(1000);
                pTimer->m_signalTick.connect(this, &VtstRtTimerTrigger3DTimeline::onTime);
                pTimer->start();

                return 3000;
            }
        }
        return -1;
    }


    void onTime(VfxTimer *pTimer)
    {

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = (main_screen_size.width) / 6;
        VfxS32 h = main_screen_size.height / 5;
        
        VfxVector3fTimeline *t;
        VFX_OBJ_CREATE(t, VfxVector3fTimeline, mesh);
        t->setTarget(mesh);        
        t->setFromValue(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
        t->setToValue(VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));
        t->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        t->setDuration(2000);
        t->start();
    }
};


VtstTestResultEnum vtst_rt_3d_timer_trigger_timeline(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimerTrigger3DTimeline);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

