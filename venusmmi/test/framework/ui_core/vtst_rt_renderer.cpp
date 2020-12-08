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
 *  vtst_rt_renderer.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VfxRenderer
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "ui_core\mvc\vfx_mmi.h"
#include "vrt_debug.h"

#ifdef __AFX_RT_TEST__

#if defined(__VENUS_3D_UI_ENGINE__)

#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_skinned_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_texture.h"
#include "vfx_render_buffer.h"

#endif /* __VENUS_3D_UI_ENGINE__ */

/***************************************************************************** 
 * VtstRtRenderer Implementation
 *****************************************************************************/

class VtstRtRenderer : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame1;
    VfxFrame *m_frame2;
    
    VfxTimer *m_timer1;
    VfxS32 m_state;

// Constructor / Destructor
public:
    VtstRtRenderer() : 
        m_frame1(NULL),
        m_frame2(NULL),
        m_timer1(NULL),
        m_state(0)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Renderer Test"));
        
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setRect(10, 50, 0, 20);
        m_frame1->setBgColor(VFX_COLOR_YELLOW);

        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setRect(10, 50, 100, 20);
        m_frame2->setBorder(VFX_COLOR_RED, 1);

        VFX_OBJ_CREATE(m_timer1, VfxTimer, this);
        m_timer1->setDuration(100);
        m_timer1->m_signalTick.connect(this, &VtstRtRenderer::onTimerTick);
    }

    void onTimerTick(VfxTimer *source)
    {
        VFX_UNUSED(source);

        m_frame1->setSize(m_state * 50, 20);

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
        
        m_state = (m_state + 1) % 3;
    }

    virtual int start()
    {
        m_timer1->start();
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Animation OK?"));
        return -1;
    }    
};


VtstTestResultEnum vtst_rt_renderer(VfxU32 param)
{
    VTST_START_SCRN(VtstRtRenderer);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VtstRtScrRotate Implementation
 *****************************************************************************/

class VtstRtScrRotate : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame1;
    VfxFrame *m_frame2;
    VfxFrame *m_frame3;

    VfxScrRotateTypeEnum m_degree;

// Constructor / Destructor
public:
    VtstRtScrRotate() : 
        m_frame1(NULL),
        m_frame2(NULL),
        m_frame3(NULL),
        m_degree(VFX_SCR_ROTATE_TYPE_0)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Press arrow keys or pen down"));

        setBorder(VFX_COLOR_YELLOW, 3);

        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setBgColor(VFX_COLOR_BLACK);
        m_frame1->setBorder(VFX_COLOR_WHITE, 1);
        m_frame1->setAutoAnimate(VFX_TRUE);

        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setBgColor(VFX_COLOR_BLACK);
        m_frame2->setBorder(VFX_COLOR_WHITE, 1);
        m_frame2->setAutoAnimate(VFX_TRUE);
        
        VFX_OBJ_CREATE(m_frame3, VfxFrame, this);
        m_frame3->setBgColor(VFX_COLOR_BLACK);
        m_frame3->setBorder(VFX_COLOR_WHITE, 1);
        m_frame3->setAutoAnimate(VFX_TRUE);

    #if defined(__VENUS_3D_UI_ENGINE__)

        VfxFrame *frame_3d;
        VFX_OBJ_CREATE(frame_3d, VfxFrame, m_frame3);
        frame_3d->setSize(200, 200);

        // referenced texture frame is created after the 3d frame
        VfxTextFrame *frame;
        VFX_OBJ_CREATE(frame, VfxTextFrame, this); 

        frame->setBgColor(VfxColor(255, 10, 186, 181));
        frame->setRect(0, 0, 100, 100);
        frame->setColor(VFX_COLOR_BLACK);
        frame->setAutoResized(VFX_TRUE);
        frame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        frame->setString(VFX_WSTR("VENUS 3D"));
        frame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);     

        VfxWorld *world;        
        VFX_OBJ_CREATE(world, VfxWorld, frame_3d);
        frame_3d->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)frame_3d->getSize().width / (vrt_float)frame_3d->getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 1, 2), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxBoxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, world);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0 * 10,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 667 * 10,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 1333 * 10, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 2000 * 10, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setKeyframeSequence(kfs);
        qtl->setDuration(2000 * 10);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        static const vrt_char fShader[] =
        "precision mediump float;           \n"
        "varying vec4 vColor;               \n"
        "varying vec2 vTexCoord;            \n"
        "uniform sampler2D frameTex;        \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = /* vColor * */ texture2D(frameTex, vTexCoord);  \n"
        "}                          \n";

        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, fShader));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("frameTex"), VFX_TYPE_ID_SAMPLER, 1);
        pass->addShaderUniforms(uniforms);

        VfxTextureFrame *texture;
        VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frame));
        var->setValue(texture);

        // perspective camera vs. frustum camera
        VFX_OBJ_CREATE(frame_3d, VfxFrame, m_frame3);
        frame_3d->setRect(200, 0, 200, 200);

        VFX_OBJ_CREATE(world, VfxWorld, frame_3d);
        frame_3d->setWorld(world);

        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)frame_3d->getSize().width / (vrt_float)frame_3d->getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(1, 1, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VFX_OBJ_CREATE(mesh, VfxBoxMesh, world);
        mesh->setTranslation(1, -1, 0);

        VFX_OBJ_CREATE(mesh, VfxBoxMesh, world);
        mesh->setTranslation(-1, 1, 0);

        VFX_OBJ_CREATE(frame_3d, VfxFrame, m_frame3);
        frame_3d->setRect(200, 80, 120, 120);

        VFX_OBJ_CREATE(world, VfxWorld, frame_3d);
        frame_3d->setWorld(world);

        VfxMatrix4f frustum;
        float l = -1.0f, r = 0.2f, t = -0.2f, b = 1.0f, n = 1.0f, f = 1000.0f;
        float tx =  (r + l) / (r - l);
        float ty = -(b + t) / (b - t);
        float d = f - n;
        frustum.col[0] = VfxVector4f(2*n/(r-l), 0, 0, 0);
        frustum.col[1] = VfxVector4f(0, 2*n/(b-t), 0, 0);
        frustum.col[2] = VfxVector4f(tx, ty, -(n+f)/d, -1);
        frustum.col[3] = VfxVector4f(0, 0, -2*n*f/d, 0);

        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setGeneric(frustum);
        camera->setLookAt(VrtVector3f(1, 1, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VFX_OBJ_CREATE(mesh, VfxBoxMesh, world);
        mesh->setTranslation(-1, -1, 0);

        VFX_OBJ_CREATE(mesh, VfxBoxMesh, world);
        //mesh->setTranslation(1, 1, 0);

    #endif /* __VENUS_3D_UI_ENGINE__ */

        layout();   
    }

    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }

    virtual void onRotate(const VfxScreenRotateParam &param)
    {              
        VtstRtScr::onRotate(param);

        layout();   
    }

    void layout()
    {
        VfxSize scrSize = getSize();
        
        m_frame1->setRect(10, 50, scrSize.width - 20, 40);
        m_frame2->setRect(10, 100, 40, scrSize.height - 170);
        m_frame3->setRect(60, 100, scrSize.width - 70, scrSize.height - 170);
    }
    
    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Rotiation OK?"));
        return -1;
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (event.keyCode)
            {
                case VFX_KEY_CODE_ARROW_UP:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);
                    return VFX_TRUE;
                case VFX_KEY_CODE_ARROW_LEFT:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90);
                    return VFX_TRUE;
                case VFX_KEY_CODE_ARROW_DOWN:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180);
                    return VFX_TRUE;
                case VFX_KEY_CODE_ARROW_RIGHT:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);
                    return VFX_TRUE;
            }            
        }
        
        return VtstRtScr::onKeyInput(event);
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_UP)
        {
            VfxS32 degree;

            degree = (VfxS32)m_degree;
            degree++;

            m_degree = (VfxScrRotateTypeEnum)degree;

            if (m_degree > VFX_SCR_ROTATE_TYPE_270)
            {
                m_degree = VFX_SCR_ROTATE_TYPE_0;
            }

            VFX_OBJ_GET_INSTANCE(VfxTopLevel)->setScreenRotateType(m_degree);

            return VFX_TRUE;
        }
        
        return VtstRtScr::onPenInput(event);
    }
};


VtstTestResultEnum vtst_rt_scr_rotate(VfxU32 param)
{
    VTST_START_SCRN(VtstRtScrRotate);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * VtstRtLandscape Implementation
 *****************************************************************************/

class VtstRtLandscape : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtLandscape()
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Landscape test <--"));
    }

    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
        param.rotateTo = VFX_SCR_ROTATE_TYPE_LANDSCAPE;
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Landscape?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_landscape(VfxU32 param)
{
    VTST_START_SCRN(VtstRtLandscape);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

