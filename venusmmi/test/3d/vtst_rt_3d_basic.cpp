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
 *  vtst_rt_3d_pick.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d basic types
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
#include "vfx_bounding_volume.h"
#include "vfx_texture.h"


/***************************************************************************** 
 * Class VtstRt3DPick
 *****************************************************************************/

class VtstRt3DPick : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxWorld *m_world;
    VfxCamera *m_camera;
    VfxBoxMesh *m_boxMesh1;
    VfxBoxMesh *m_boxMesh2;
    VfxSphereMesh *m_sphereMesh1;
    VfxSphereMesh *m_sphereMesh2;
    VfxSphereMesh *m_sphereMesh3;
    VfxVector3fTimeline *m_clickAnimation;

// Constructor / Destructor
public:
    VtstRt3DPick() : 
        m_frame(NULL), 
        m_world(NULL),
        m_camera(NULL),
        m_boxMesh1(NULL),
        m_boxMesh2(NULL),
        m_sphereMesh1(NULL),
        m_sphereMesh2(NULL),
        m_sphereMesh3(NULL),
        m_clickAnimation(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Basic"));

        setBgColor(VFX_COLOR_BLACK);
    }

    virtual int start()
    {
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        confirm(VFX_WSTR("3D Pick OK?"));

        VfxS32 w = main_screen_size.width;
        VfxS32 h = main_screen_size.height;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(w, h);

        /* Wrold */
        VFX_OBJ_CREATE(m_world, VfxWorld, m_frame);
        m_frame->setWorld(m_world);

        /* Camera */
        VFX_OBJ_CREATE(m_camera, VfxCamera, m_world);
        m_camera->setPerspective(VFX_PI / 2, (VfxFloat)w / h, 20.0f, 2000.0f);
        m_camera->setTranslation(0.0f, 0.0f, 20.0f);
        m_camera->rotateX(VFX_PI / 12.0f);
        m_camera->rotateZ(-VFX_PI / 12.0f);
        m_world->setActiveCamera(m_camera);

        /* Box */
        const VfxVector3f boxSize(30.0f, 40.0f, 50.0f);

        VFX_OBJ_CREATE_EX(m_boxMesh1, VfxBoxMesh, m_world, (boxSize.x, boxSize.y, boxSize.z));
        m_boxMesh1->setTranslation(VfxVector3f(boxSize.x, boxSize.y, -200.0f));
        m_boxMesh1->setRotation(normalize(VfxVector3f(1.0f)), VFX_PI / 2);
        m_boxMesh1->setPickable(VFX_TRUE);

        m_boxMesh1->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                length2(boxSize),
                boxSize * 0.5f));
        
        VFX_OBJ_CREATE_EX(m_boxMesh2, VfxBoxMesh, m_world, (boxSize.x, boxSize.y, boxSize.z));
        m_boxMesh2->setTranslation(VfxVector3f(boxSize.x, -boxSize.y, -200.0f));
        m_boxMesh2->setRotation(normalize(VfxVector3f(1.0f)), VFX_PI / 2);
        m_boxMesh2->setPickable(VFX_TRUE);

        m_boxMesh2->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                boxSize * 0.5f));
        
        /* Sphere */
        const VfxFloat sphereRadius = 15.0f;

        VFX_OBJ_CREATE_EX(m_sphereMesh1, VfxSphereMesh, m_world, (sphereRadius));
        m_sphereMesh1->setTranslation(boxSize.x / 2, boxSize.y / 2, -150.0f);
        m_sphereMesh1->setPickable(VFX_TRUE);

        m_sphereMesh1->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                sphereRadius * sphereRadius,
                VfxVector3f(sphereRadius)));

        VFX_OBJ_CREATE_EX(m_sphereMesh2, VfxSphereMesh, m_world, (sphereRadius));
        m_sphereMesh2->setTranslation(boxSize.x / 2, -boxSize.y / 2, -150.0f);
        m_sphereMesh2->setPickable(VFX_TRUE);

        m_sphereMesh2->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                sphereRadius * sphereRadius));

        VFX_OBJ_CREATE_EX(m_sphereMesh3, VfxSphereMesh, m_world, (sphereRadius * 0.5f));
        m_sphereMesh3->setTranslation(-boxSize.x / 2, 0, -150.0f);

        m_sphereMesh3->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                sphereRadius * sphereRadius));
        
        return -1;
    }


    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        VfxPoint pos = event.getRelPos(m_frame);
        VfxSize size = m_frame->getSize();
        VfxFloat x = (VfxFloat)pos.x;
        VfxFloat y = (VfxFloat)pos.y;
        VfxFloat w = (VfxFloat)size.width;
        VfxFloat h = (VfxFloat)size.height;

        VfxVector3f orig;
        m_camera->getWorldPosition(orig);

        VfxVector3f worldPos = m_camera->unproject(VfxVector3f(
            (VfxFloat)(pos.x * 2) / w - 1.0f,
            -((VfxFloat)(pos.y * 2) / h - 1.0f),
            -1.0f));
        VfxVector3f dir = worldPos - orig;
        
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN ||
            event.type == VFX_PEN_EVENT_TYPE_MOVE)
        {
            VfxNode *pickNode = m_world->pick(orig, dir);
            
            if (pickNode == m_boxMesh1 || pickNode == m_boxMesh2)
            {
                setBgColor(VFX_COLOR_GREEN);
            }
            else if (pickNode == m_sphereMesh1 || pickNode == m_sphereMesh2)
            {
                setBgColor(VFX_COLOR_YELLOW);
            }
            else if (pickNode != NULL)
            {
                setBgColor(VFX_COLOR_RED);
            }
            else
            {
                setBgColor(VFX_COLOR_BLACK);
            }
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_UP ||
            event.type == VFX_PEN_EVENT_TYPE_ABORT)
        {
            setBgColor(VFX_COLOR_BLACK);
        }
        
        return VFX_TRUE;
    }
};


VtstTestResultEnum vtst_rt_3d_pick(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DPick);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRt3DText
 *****************************************************************************/

class VtstRt3DText : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    VtstRt3DText()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Text Test"));
    }

    virtual int start()
    {        
        return 1;
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
                camera->setPerspective(
                    VRT_PI_2, 
                    (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 
                    20.0f, 
                    2000.0f);
                camera->setLookAt(
                    VrtVector3f(0.0f, 0.0f, 20.0f), 
                    VrtVector3f(0, 0, 0), 
                    VrtVector3f(0, 1, 0));
                world->setActiveCamera(camera);

                VfxGroup *group;
                VFX_OBJ_CREATE(group, VfxGroup, world);
                
                VfxTextMesh *centerMesh = NULL;
                VfxTextMesh *mesh;
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("L"), 0, VFX_TEXT_MESH_ALIGN_MODE_LEFT));
                mesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
                mesh->setTextColor(VFX_COLOR_GREEN);
                mesh->setTextBorderColor(VFX_COLOR_WHITE);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(-10, 10, -10);
                mesh->setRotationY(VFX_PI / 4);

                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("C"), 0, VFX_TEXT_MESH_ALIGN_MODE_CENTER));
                mesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
                mesh->setTextColor(VFX_COLOR_YELLOW);
                mesh->setTextBorderColor(VFX_COLOR_WHITE);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(0, 10, -10);
                mesh->setRotationY(0);
                centerMesh = mesh;
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("R"), 0, VFX_TEXT_MESH_ALIGN_MODE_RIGHT));
                mesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
                mesh->setTextColor(VFX_COLOR_RED);
                mesh->setTextBorderColor(VFX_COLOR_WHITE);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(10, 10, -10);
                mesh->setRotationY(-VFX_PI / 4);
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_LEFT, VFX_TEXT_MESH_VALIGN_MODE_TOP));
                mesh->setTextColor(VFX_COLOR_GREEN);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(-10, 5, -10);
                mesh->setRotationY(VFX_PI / 4);

                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_CENTER, VFX_TEXT_MESH_VALIGN_MODE_TOP));
                mesh->setTextColor(VFX_COLOR_YELLOW);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(0, 5, -10);
                mesh->setRotationY(0);
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_RIGHT, VFX_TEXT_MESH_VALIGN_MODE_TOP));
                mesh->setTextColor(VFX_COLOR_RED);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(10, 5, -10);
                mesh->setRotationY(-VFX_PI / 4);
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_LEFT, VFX_TEXT_MESH_VALIGN_MODE_CENTER));
                mesh->setTextColor(VFX_COLOR_GREEN);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(-10, 0, -10);
                mesh->setRotationY(VFX_PI / 4);

                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_CENTER, VFX_TEXT_MESH_VALIGN_MODE_CENTER));
                mesh->setTextColor(VFX_COLOR_YELLOW);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(0, 0, -10);
                mesh->setRotationY(0);
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_RIGHT, VFX_TEXT_MESH_VALIGN_MODE_CENTER));
                mesh->setTextColor(VFX_COLOR_RED);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(10, 0, -10);
                mesh->setRotationY(-VFX_PI / 4);
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_LEFT, VFX_TEXT_MESH_VALIGN_MODE_BOTTOM));
                mesh->setTextColor(VFX_COLOR_GREEN);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(-10, -5, -10);
                mesh->setRotationY(VFX_PI / 4);

                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_CENTER, VFX_TEXT_MESH_VALIGN_MODE_BOTTOM));
                mesh->setTextColor(VFX_COLOR_YELLOW);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(0, -5, -10);
                mesh->setRotationY(0);
                
                VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_RIGHT, VFX_TEXT_MESH_VALIGN_MODE_BOTTOM));
                mesh->setTextColor(VFX_COLOR_RED);
                mesh->setBackgroundColor(VFX_COLOR_BLACK);
                mesh->setTranslation(10, -5, -10);
                mesh->setRotationY(-VFX_PI / 4);
                
#if 1
                VfxQuaternionfTimeline *rtl;
                VFX_OBJ_CREATE(rtl, VfxQuaternionfTimeline, centerMesh);
                rtl->setTarget(centerMesh);
                rtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                rtl->setFromValue(normalize(VfxQuaternionf(0,0,1,-0.5)));
                rtl->setToValue(normalize(VfxQuaternionf(0,0,1,0.5)));
                rtl->setDuration(2000);
                rtl->setAutoReversed(VFX_TRUE);
                rtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                rtl->start();
#endif

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
#endif

                confirm(VFX_WSTR("Text mesh OK?"));
            }
        }

        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_text_mesh(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DText);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Class VtstRt3DBackground
 *****************************************************************************/

class VtstRt3DBackground : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRt3DBackground()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Background"));
    }

    virtual int start()
    {        
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        confirm(VFX_WSTR("3D Pick OK?"));

        VfxS32 w = main_screen_size.width;
        VfxS32 h = main_screen_size.height;

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setSize(w, h);

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, frame);
        frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(VFX_PI / 2, (VfxFloat)w / h, 20.0f, 2000.0f);
        camera->setTranslation(0.0f, 0.0f, 20.0f);
        world->setActiveCamera(camera);

        /* Box */
        VfxMesh *mesh;
        VFX_OBJ_CREATE_EX(mesh, VfxBoxMesh, world, (50.0f));
        mesh->setTranslation(VfxVector3f(0.0f, 0.0f, -200.0f));

        frame->removeFromParentFrame();


        VfxAutoAnimate::initAnimateBegin();
        mesh->setTranslation(VfxVector3f(0.0f, 0.0f, -150.0f));        
        VfxAutoAnimate::initAnimateEnd();

        return 0;
    }
};


VtstTestResultEnum vtst_rt_3d_background(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DBackground);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

