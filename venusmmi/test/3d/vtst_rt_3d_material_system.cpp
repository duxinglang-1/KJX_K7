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
 *  vtst_rt_3d_material_system.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d material system
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
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_render_mode.h"
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

#include "vcp_button.h"
#include "vcp_slider.h"
#include "vcp_switch.h"
#include "FileMgrSrvGprot.h"



class VtstRtRenderState : public VtstRtScr
{
// Variable
public:
    VfxBoxMesh *m_mesh;
    VfxPass *m_pass;

    VfxPolygonMode *m_pm;
    VfxWindingMode m_winding;
    VfxCullingMode m_culling;

    VfxCompositingMode *m_cm;
    VfxDepthFunc m_depthFunc;
    VfxU32 m_colorMask;

    VfxBlendEquation m_colorEquation;
    VfxBlendEquation m_alphaEquation;
    VfxBlendFactor m_srcColorFactor;
    VfxBlendFactor m_dstColorFactor;
    VfxBlendFactor m_srcAlphaFactor;
    VfxBlendFactor m_dstAlphaFactor;
    
    VfxBlender *m_blender;
    VfxStencil *m_stencil;

    VcpButton *m_btnWinding;
    VcpButton *m_btnCulling;
    
    VcpSwitch *m_btnDepthTest;
    VcpSwitch *m_btnDepthWrite;
    VcpButton *m_btnDepthFunc;
    VcpButton *m_btnColorMask;
    //VcpSwitch *m_btnStencil;
    VcpSwitch *m_btnBlender;

    VcpButton *m_btnColorEq;
    VcpButton *m_btnAlphaEq;
    VcpButton *m_btnSrcColorFactor;
    VcpButton *m_btnDstColorFactor;
    VcpButton *m_btnSrcAlphaFactor;
    VcpButton *m_btnDstAlphaFactor;

    // Constructor / Destructor
public:
    VtstRtRenderState()
    : m_mesh(NULL)
    , m_pass(NULL)
    , m_pm(NULL)
    , m_winding(VFX_WINDING_CCW)
    , m_culling(VFX_CULLING_BACK)
    , m_cm(NULL)
    , m_depthFunc(VFX_DEPTH_FUNC_LESS)
    , m_colorMask(NULL)
    , m_colorEquation(VFX_BLEND_EQUATION_ADD)
    , m_alphaEquation(VFX_BLEND_EQUATION_ADD)
    , m_srcColorFactor(VFX_BLEND_FACTOR_SRC_ALPHA)
    , m_dstColorFactor(VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
    , m_srcAlphaFactor(VFX_BLEND_FACTOR_ONE)
    , m_dstAlphaFactor(VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
    , m_blender(NULL)
    , m_stencil(NULL)
    , m_btnWinding(NULL)
    , m_btnCulling(NULL)
    , m_btnDepthTest(NULL)
    , m_btnDepthWrite(NULL)
    , m_btnDepthFunc(NULL)
    , m_btnColorMask(NULL)
    //, m_btnStencil(NULL)
    , m_btnBlender(NULL)
    , m_btnColorEq(NULL)
    , m_btnAlphaEq(NULL)
    , m_btnSrcColorFactor(NULL)
    , m_btnDstColorFactor(NULL)
    , m_btnSrcAlphaFactor(NULL)
    , m_btnDstAlphaFactor(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setBgColor(VFX_COLOR_BLACK);

        // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        // mesh
        VFX_OBJ_CREATE_EX(m_mesh, VfxBoxMesh, world, (2.0f));
        m_mesh->setTranslation(0.5f, 0, 0);

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(-0.5f, 0, 0);

        // material
        VfxMaterial *material;
        VFX_OBJ_CREATE(material, VfxMaterial, m_mesh);
        m_mesh->setMaterial(0, material);

        // pass
        VFX_OBJ_CREATE(m_pass, VfxPass, material);
        material->setPass(0, m_pass);

        VfxS32 w = getSize().width / 4;
        VfxS32 h = getSize().height / 17;
        VfxS32 l = 0;
        VfxS32 t = h * 1;
        VfxS32 indent = 20;

        // UI control
        VcpSwitch *sw;
        VfxTextFrame *text;
        VcpSlider *slider;

        // Polygon Mode
        t+=h;
        VFX_OBJ_CREATE(sw, VcpSwitch, this);
        sw->setPos(l, t);
        sw->m_signalSwitchChanged.connect(this, &VtstRtRenderState::onSwitchPolygonMode);
        sw->setChecked(VFX_FALSE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l + sw->getSize().width, t);
        text->setString(VFX_WSTR("PM"));

        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(getSize().width / 2, t);
        slider->setLength(getSize().width/2);
        slider->setMaxValue(VFX_PI);
        slider->setMinValue(-VFX_PI);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtRenderState::onRotationYChange);

        t+=h;
        VFX_OBJ_CREATE(m_btnWinding, VcpButton, this);
        m_btnWinding->setIsDisabled(VFX_TRUE);
        m_btnWinding->setRect(l+indent, t, 100, 30);
        m_btnWinding->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnWinding->setText(VFX_WSTR("CCW"));
        m_btnWinding->m_signalClicked.connect(this, &VtstRtRenderState::onWindingChanged);

        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(getSize().width / 2, t);
        slider->setLength(getSize().width/2);
        slider->setMaxValue(1);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtRenderState::onOpacityChange);

        t+=h;
        VFX_OBJ_CREATE(m_btnCulling, VcpButton, this);
        m_btnCulling->setIsDisabled(VFX_TRUE);
        m_btnCulling->setRect(l+indent, t, 100, 30);
        m_btnCulling->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnCulling->setText(VFX_WSTR("BACK"));
        m_btnCulling->m_signalClicked.connect(this, &VtstRtRenderState::onCullingChanged);

        // Compositing Mode
        t+=h;
        VFX_OBJ_CREATE(sw, VcpSwitch, this);
        sw->setPos(l, t);
        sw->m_signalSwitchChanged.connect(this, &VtstRtRenderState::onSwitchCompositingMode);
        sw->setChecked(VFX_FALSE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l + sw->getSize().width, t);
        text->setString(VFX_WSTR("CM"));

        // Depth Test
        t+=h;
        VFX_OBJ_CREATE(m_btnDepthTest, VcpSwitch, this);
        m_btnDepthTest->setIsDisabled(VFX_TRUE);
        m_btnDepthTest->setPos(l+indent, t);
        m_btnDepthTest->m_signalSwitchChanged.connect(this, &VtstRtRenderState::onSwitchDepthTest);
        m_btnDepthTest->setChecked(VFX_TRUE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l+indent + m_btnDepthTest->getSize().width, t);
        text->setString(VFX_WSTR("DT"));

        // Depth Write
        t+=h;
        VFX_OBJ_CREATE(m_btnDepthWrite, VcpSwitch, this);
        m_btnDepthWrite->setIsDisabled(VFX_TRUE);
        m_btnDepthWrite->setPos(l+indent, t);
        m_btnDepthWrite->m_signalSwitchChanged.connect(this, &VtstRtRenderState::onSwitchDepthWrite);
        m_btnDepthWrite->setChecked(VFX_TRUE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l+indent + m_btnDepthWrite->getSize().width, t);
        text->setString(VFX_WSTR("DW"));

        // Depth Func
        t+=h;
        VFX_OBJ_CREATE(m_btnDepthFunc, VcpButton, this);
        m_btnDepthFunc->setIsDisabled(VFX_TRUE);
        m_btnDepthFunc->setRect(l+indent, t, 100, 30);
        m_btnDepthFunc->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnDepthFunc->setText(VFX_WSTR("LESS"));
        m_btnDepthFunc->m_signalClicked.connect(this, &VtstRtRenderState::onDepthFuncChanged);

        // Color Mask
        t+=h;
        VFX_OBJ_CREATE(m_btnColorMask, VcpButton, this);
        m_btnColorMask->setIsDisabled(VFX_TRUE);
        m_btnColorMask->setRect(l+indent, t, 100, 30);
        m_btnColorMask->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnColorMask->setText(VFX_WSTR("RGBA"));
        m_btnColorMask->m_signalClicked.connect(this, &VtstRtRenderState::onColorMaskChanged);

        // Blender Mode
        t+=h;
        VFX_OBJ_CREATE(m_btnBlender, VcpSwitch, this);
        m_btnBlender->setIsDisabled(VFX_TRUE);
        m_btnBlender->setPos(l+indent, t);
        m_btnBlender->m_signalSwitchChanged.connect(this, &VtstRtRenderState::onSwitchBlender);
        m_btnBlender->setChecked(VFX_FALSE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l+indent + m_btnBlender->getSize().width, t);
        text->setString(VFX_WSTR("AB"));

        t+=h;
        VFX_OBJ_CREATE(m_btnColorEq, VcpButton, this);
        m_btnColorEq->setIsDisabled(VFX_TRUE);
        m_btnColorEq->setRect(l+indent, t, 100, 30);
        m_btnColorEq->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnColorEq->setText(VFX_WSTR("ADD"));
        m_btnColorEq->m_signalClicked.connect(this, &VtstRtRenderState::onBlendEquationChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnAlphaEq, VcpButton, this);
        m_btnAlphaEq->setIsDisabled(VFX_TRUE);
        m_btnAlphaEq->setRect(l+indent, t, 100, 30);
        m_btnAlphaEq->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAlphaEq->setText(VFX_WSTR("ADD"));
        m_btnAlphaEq->m_signalClicked.connect(this, &VtstRtRenderState::onBlendEquationChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnSrcColorFactor, VcpButton, this);
        m_btnSrcColorFactor->setIsDisabled(VFX_TRUE);
        m_btnSrcColorFactor->setRect(l+indent, t, 100, 30);
        m_btnSrcColorFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnSrcColorFactor->setText(VFX_WSTR("As"));
        m_btnSrcColorFactor->m_signalClicked.connect(this, &VtstRtRenderState::onBlendFuncChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnDstColorFactor, VcpButton, this);
        m_btnDstColorFactor->setIsDisabled(VFX_TRUE);
        m_btnDstColorFactor->setRect(l+indent, t, 100, 30);
        m_btnDstColorFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnDstColorFactor->setText(VFX_WSTR("1 - As"));
        m_btnDstColorFactor->m_signalClicked.connect(this, &VtstRtRenderState::onBlendFuncChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnSrcAlphaFactor, VcpButton, this);
        m_btnSrcAlphaFactor->setIsDisabled(VFX_TRUE);
        m_btnSrcAlphaFactor->setRect(l+indent, t, 100, 30);
        m_btnSrcAlphaFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnSrcAlphaFactor->setText(VFX_WSTR("1"));
        m_btnSrcAlphaFactor->m_signalClicked.connect(this, &VtstRtRenderState::onBlendFuncChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnDstAlphaFactor, VcpButton, this);
        m_btnDstAlphaFactor->setIsDisabled(VFX_TRUE);
        m_btnDstAlphaFactor->setRect(l+indent, t, 100, 30);
        m_btnDstAlphaFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnDstAlphaFactor->setText(VFX_WSTR("1 - As"));
        m_btnDstAlphaFactor->m_signalClicked.connect(this, &VtstRtRenderState::onBlendFuncChanged);
        setTitle(VFX_WSTR("Render State test"));
    }

    virtual int start()
    {        
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Render State OK?"));
        return -1;
    }

    void onSwitchPolygonMode(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_pm)
        {
            VFX_OBJ_CLOSE(m_pm);
            m_pass->setPolygonMode(NULL);
            m_btnWinding->setIsDisabled(VFX_TRUE);
            m_btnCulling->setIsDisabled(VFX_TRUE);
        }
        else
        {
            VFX_OBJ_CREATE(m_pm, VfxPolygonMode, m_pass);
            m_pass->setPolygonMode(m_pm);
            m_winding = VFX_WINDING_CCW;
            m_btnWinding->setIsDisabled(VFX_FALSE);
            m_btnWinding->setText(VFX_WSTR("CCW"));
            m_culling = VFX_CULLING_BACK;
            m_btnCulling->setIsDisabled(VFX_FALSE);
            m_btnCulling->setText(VFX_WSTR("BACK"));
        }
    }

    void onWindingChanged(VfxObject* sender, VfxId id)
    {
        if (m_pm)
        {
            m_winding = (VfxWindingMode)((m_winding + 1) % VFX_WINDING_END_OF_ENUM);
            m_pm->setWinding(m_winding);
            switch(m_winding)
            {
            case VFX_WINDING_CCW:
                m_btnWinding->setText(VFX_WSTR("CCW"));
                break;
            case VFX_WINDING_CW:
                m_btnWinding->setText(VFX_WSTR("CW"));
                break;
            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onCullingChanged(VfxObject* sender, VfxId id)
    {
        if (m_pm)
        {
            m_culling = (VfxCullingMode)((m_culling + 1) % VFX_CULLING_END_OF_ENUM);
            m_pm->setCulling(m_culling);
            switch(m_culling)
            {
            case VFX_CULLING_NONE:
                m_btnCulling->setText(VFX_WSTR("NONE"));
                break;
            case VFX_CULLING_FRONT:
                m_btnCulling->setText(VFX_WSTR("FRONT"));
                break;
            case VFX_CULLING_BACK:
                m_btnCulling->setText(VFX_WSTR("BACK"));
                break;

            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onSwitchCompositingMode(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            m_btnDepthTest->setIsDisabled(VFX_TRUE);
            m_btnDepthWrite->setIsDisabled(VFX_TRUE);
            m_btnDepthFunc->setIsDisabled(VFX_TRUE);
            m_btnColorMask->setIsDisabled(VFX_TRUE);
            //m_btnStencil->setIsDisabled(VFX_TRUE);
            m_btnBlender->setIsDisabled(VFX_TRUE);

            m_btnColorEq->setIsDisabled(VFX_TRUE);
            m_btnAlphaEq->setIsDisabled(VFX_TRUE);
            m_btnSrcColorFactor->setIsDisabled(VFX_TRUE);
            m_btnDstColorFactor->setIsDisabled(VFX_TRUE);
            m_btnSrcAlphaFactor->setIsDisabled(VFX_TRUE);
            m_btnDstAlphaFactor->setIsDisabled(VFX_TRUE);

            VFX_OBJ_CLOSE(m_blender);
            VFX_OBJ_CLOSE(m_stencil);
            VFX_OBJ_CLOSE(m_cm);
            m_pass->setCompositingMode(NULL);
        }
        else
        {
            VFX_OBJ_CREATE(m_cm, VfxCompositingMode, m_pass);
            m_pass->setCompositingMode(m_cm);
            m_btnDepthTest->setIsDisabled(VFX_FALSE);
            m_btnDepthWrite->setIsDisabled(VFX_FALSE);
            m_btnDepthFunc->setIsDisabled(VFX_FALSE);
            m_btnColorMask->setIsDisabled(VFX_FALSE);
            //m_btnStencil->setIsDisabled(VFX_FALSE);
            m_btnBlender->setIsDisabled(VFX_FALSE);

            m_depthFunc = VFX_DEPTH_FUNC_LESS;
            m_btnDepthTest->setChecked(VFX_TRUE);
            m_btnDepthWrite->setChecked(VFX_TRUE);
            m_colorMask = 0;
            m_btnBlender->setChecked(VFX_FALSE);
        }
    }

    void onSwitchDepthTest(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            m_cm->setDepthTestEnable(!m_cm->isDepthTestEnabled());
        }
    }

    void onSwitchDepthWrite(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            m_cm->setDepthWriteEnable(!m_cm->isDepthWriteEnabled());
        }
    }

    void onDepthFuncChanged(VfxObject* sender, VfxId id)
    {
        if (m_cm)
        {
            m_depthFunc = (VfxDepthFunc)((m_depthFunc + 1) % VFX_DEPTH_FUNC_END_OF_ENUM);
            m_cm->setDepthFunc(m_depthFunc);
            switch(m_depthFunc)
            {
            case VFX_DEPTH_FUNC_NEVER:
                m_btnDepthFunc->setText(VFX_WSTR("NONE"));
                break;
            case VFX_DEPTH_FUNC_ALWAYS:
                m_btnDepthFunc->setText(VFX_WSTR("ALWAYS"));
                break;
            case VFX_DEPTH_FUNC_EQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("EQUAL"));
                break;
            case VFX_DEPTH_FUNC_LESS:
                m_btnDepthFunc->setText(VFX_WSTR("LESS"));
                break;
            case VFX_DEPTH_FUNC_GREATER:
                m_btnDepthFunc->setText(VFX_WSTR("GREATER"));
                break;
            case VFX_DEPTH_FUNC_GEQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("GEQUAL"));
                break;
            case VFX_DEPTH_FUNC_LEQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("LEQUAL"));
                break;
            case VFX_DEPTH_FUNC_NOTEQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("NOTEQUAL"));
                break;
            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onColorMaskChanged(VfxObject* sender, VfxId id)
    {
        if (m_cm)
        {
            m_colorMask = (m_colorMask + 1) % 4;
            switch(m_colorMask)
            {
            case 0:
                m_cm->setColorWriteMask(0xFFFFFFFF);
                m_btnColorMask->setText(VFX_WSTR("ARGB"));
                break;
            case 1:
                m_cm->setColorWriteMask(0x00FF0000);
                m_btnColorMask->setText(VFX_WSTR("R"));
                break;
            case 2:
                m_cm->setColorWriteMask(0x0000FF00);
                m_btnColorMask->setText(VFX_WSTR("G"));
                break;
            case 3:
                m_cm->setColorWriteMask(0x000000FF);
                m_btnColorMask->setText(VFX_WSTR("B"));
                break;            
            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onSwitchBlender(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            if (m_blender)
            {
                VFX_OBJ_CLOSE(m_blender);
                m_cm->setBlender(NULL);

                m_btnColorEq->setIsDisabled(VFX_TRUE);
                m_btnAlphaEq->setIsDisabled(VFX_TRUE);
                m_btnSrcColorFactor->setIsDisabled(VFX_TRUE);
                m_btnDstColorFactor->setIsDisabled(VFX_TRUE);
                m_btnSrcAlphaFactor->setIsDisabled(VFX_TRUE);
                m_btnDstAlphaFactor->setIsDisabled(VFX_TRUE);
            }
            else
            {
                VFX_OBJ_CREATE(m_blender, VfxBlender, m_cm);
                m_cm->setBlender(m_blender);

                m_btnColorEq->setIsDisabled(VFX_FALSE);
                m_btnAlphaEq->setIsDisabled(VFX_FALSE);
                m_btnSrcColorFactor->setIsDisabled(VFX_FALSE);
                m_btnDstColorFactor->setIsDisabled(VFX_FALSE);
                m_btnSrcAlphaFactor->setIsDisabled(VFX_FALSE);
                m_btnDstAlphaFactor->setIsDisabled(VFX_FALSE);

                m_colorEquation = VFX_BLEND_EQUATION_ADD;
                m_alphaEquation = VFX_BLEND_EQUATION_ADD;
                m_srcColorFactor = VFX_BLEND_FACTOR_SRC_ALPHA;
                m_dstColorFactor = VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
                m_srcAlphaFactor = VFX_BLEND_FACTOR_ONE;
                m_dstAlphaFactor = VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
            }
        }
    }

    void onBlendEquationChanged(VfxObject* sender, VfxId id)
    {
        if (m_blender)
        {
            VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);
            VfxBlendEquation *eq = NULL;
            if (sender == m_btnColorEq)
            {
                m_colorEquation = (VfxBlendEquation)((m_colorEquation + 1) % VFX_BLEND_EQUATION_END_OF_ENUM);
                eq = &m_colorEquation;
            }
            else
            {
                m_alphaEquation = (VfxBlendEquation)((m_alphaEquation + 1) % VFX_BLEND_EQUATION_END_OF_ENUM);
                eq = &m_alphaEquation;
            }

            switch (*eq)
            {
            case VFX_BLEND_EQUATION_ADD:
                button->setText(VFX_WSTR("ADD"));
                break;
            case VFX_BLEND_EQUATION_SUBTRACT:
                button->setText(VFX_WSTR("SUB"));
                break;
            case VFX_BLEND_EQUATION_REVERSE_SUBTRACT:
                button->setText(VFX_WSTR("REV_SUB"));
                break;
            default:
                VFX_DEV_ASSERT(0);
            }
            
            m_blender->setBlendEquation(m_colorEquation, m_alphaEquation);
        }
    }

    void onBlendFuncChanged(VfxObject* sender, VfxId id)
    {
        if (m_blender)
        {
            VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);
            VfxBlendFactor *factor = NULL;
            if (sender == m_btnSrcColorFactor)
            {
                m_srcColorFactor = (VfxBlendFactor)((m_srcColorFactor + 1) % VFX_BLEND_FACTOR_END_OF_ENUM);                
                factor = &m_srcColorFactor;
            }
            else if (sender == m_btnDstColorFactor)
            {
                m_dstColorFactor = (VfxBlendFactor)((m_dstColorFactor + 1) % VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);                
                factor = &m_dstColorFactor;
            }
            else if (sender == m_btnSrcAlphaFactor)
            {
                m_srcAlphaFactor = (VfxBlendFactor)((m_srcAlphaFactor + 1) % VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);                
                factor = &m_srcAlphaFactor;
            }
            else
            {
                m_dstAlphaFactor = (VfxBlendFactor)((m_dstAlphaFactor + 1) % VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);                
                factor = &m_dstAlphaFactor;
            }

            switch (*factor)
            {
            case VFX_BLEND_FACTOR_ZERO:
                button->setText(VFX_WSTR("0"));
                break;
            case VFX_BLEND_FACTOR_ONE:
                button->setText(VFX_WSTR("1"));
                break;
            case VFX_BLEND_FACTOR_SRC_COLOR:
                button->setText(VFX_WSTR("Cs"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_SRC_COLOR:
                button->setText(VFX_WSTR("1 - Cs"));
                break;
            case VFX_BLEND_FACTOR_DST_COLOR:
                button->setText(VFX_WSTR("Ds"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_DST_COLOR:
                button->setText(VFX_WSTR("1 - Ds"));
                break;
            case VFX_BLEND_FACTOR_SRC_ALPHA:
                button->setText(VFX_WSTR("As"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA:
                button->setText(VFX_WSTR("1 - As"));
                break;
            case VFX_BLEND_FACTOR_DST_ALPHA:
                button->setText(VFX_WSTR("Ad"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_DST_ALPHA:
                button->setText(VFX_WSTR("1 - Ad"));
                break;
            case VFX_BLEND_FACTOR_CONSTANT_COLOR:
                button->setText(VFX_WSTR("C"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR:
                button->setText(VFX_WSTR("1 - C"));
                break;
            case VFX_BLEND_FACTOR_CONSTANT_ALPHA:
                button->setText(VFX_WSTR("A"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA:
                button->setText(VFX_WSTR("1 - A"));
                break;
            case VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE:
                button->setText(VFX_WSTR("As_sat"));
                break; 
            default:
                VFX_DEV_ASSERT(0);
            }
            
            m_blender->setBlendFunc(m_srcColorFactor, m_dstColorFactor, m_srcAlphaFactor, m_dstAlphaFactor);
        }
    }

    void onRotationYChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setRotationY(newval);
    }

    void onOpacityChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setOpacity(newval);
    }
};


VtstTestResultEnum vtst_rt_3d_material_system(VfxU32 param)
{
    VTST_START_SCRN(VtstRtRenderState);
    return VTST_TR_OK;
}



class VtstRtMultiPass : public VtstRtScr
{
// Variable
public:
    VfxLight *m_light;
    // Constructor / Destructor
public:
    VtstRtMultiPass()
    : m_light(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 6), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;
        VfxShaderVariable *var;
        VfxCompositingMode *cm;
        VfxBlender *blender;

        VfxGroup *group;
        VFX_OBJ_CREATE(group, VfxGroup, world);
        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, group, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f(-2, -2, 3));
        kfs->setKeyframe(1, 500,  &VfxVector3f(-2, 2, 3));
        kfs->setKeyframe(2, 1000, &VfxVector3f(2, 2, 3));
        kfs->setKeyframe(3, 1500, &VfxVector3f(2, -2, 3));
        kfs->setKeyframe(4, 2000, &VfxVector3f(-2, -2, 3));
        VfxKeyframeTimeline *kf_tl;
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, group);
        kf_tl->setTarget(group);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        // light
        VFX_OBJ_CREATE(m_light, VfxLight, group);
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, group, (0.1f));
        

        // multi-pass (2 pass)
        VFX_OBJ_CREATE_EX(material, VfxMaterial, world, (2));

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VfxWChar vs[256];
        VfxWChar fs[256];
        kal_wsprintf(vs, "%c:\\test\\light\\phong.vs", SRV_FMGR_PHONE_DRV);        
        kal_wsprintf(fs, "%c:\\test\\light\\phong.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
        pass->addShaderUniforms(uniforms);
        uniforms->addUniformVariable(VFX_STR("u_LightPos"), VFX_TYPE_ID_VEC3, 1)->bindValue(m_light, VFX_BINDING_CAMERA_SPACE_POSITION);
        uniforms->addUniformVariable(VFX_STR("u_LightColor"), VFX_TYPE_ID_VEC4, 1)->bindValue(m_light, VFX_BINDING_LIGHT_COLOR);
        uniforms->addUniformVariable(VFX_STR("u_LightIntensity"), VFX_TYPE_ID_FLOAT, 1)->bindValue(m_light, VFX_BINDING_LIGHT_INTENSITY);


        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);

        kal_wsprintf(vs, "%c:\\test\\shadow\\planar_shadow.vs", SRV_FMGR_PHONE_DRV);
        kal_wsprintf(fs, "%c:\\test\\shadow\\planar_shadow.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
        pass->addShaderUniforms(uniforms);
        var = uniforms->addUniformVariable(VFX_STR("u_LightPos"), VFX_TYPE_ID_VEC3, 1);
        var->bindValue(m_light, VFX_BINDING_WORLD_SPACE_POSITION);

        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);

        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        cm->setBlender(blender);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(-1, 1, 0.5f);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(1, 1, 0.5f);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(-1, -1, 0.5f);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(1, -1, 0.5f);
        mesh->setMaterial(0, material);

        setTitle(VFX_WSTR("Multi Pass test"));
    }

    virtual int start()
    {        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Multi Pass OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_multi_pass(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMultiPass);
    return VTST_TR_OK;
}



class VtstRtStencilBuffer : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtStencilBuffer()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VfxVector3f(75, 0, 40), VfxVector3f(0, 0, 0), VfxVector3f(-8, 0, 15));

        VfxMesh *mesh;
        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;
        VfxPolygonMode *pm;
        VfxCompositingMode *cm;
        VfxStencil *stencil;

        // mirror surface
        VFX_OBJ_CREATE_EX(mesh, VfxPlaneMesh, world, (100.0f));

        VFX_OBJ_CREATE(material, VfxMaterial, world);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VfxWChar vs[256];
        VfxWChar fs[256];
        kal_wsprintf(vs, "%c:\\test\\base.vs", SRV_FMGR_PHONE_DRV);
        kal_wsprintf(fs, "%c:\\test\\base.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        cm->setColorWriteMask(0x00000000);
        cm->setDepthWriteEnable(VFX_FALSE);

        VFX_OBJ_CREATE(stencil, VfxStencil, cm);
        cm->setStencil(stencil);
        stencil->setStencilFunc(
            VFX_STENCIL_FUNC_ALWAYS, 1, 0xFFFFFFFF,
            VFX_STENCIL_FUNC_ALWAYS, 1, 0xFFFFFFFF);
        stencil->setStencilOperation(
            VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_REPLACE,
            VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_REPLACE);

        // reflection
        VFX_OBJ_CREATE(mesh, VfxMesh, world);

        VfxWChar fn[256];
        kal_wsprintf(fn, "%c:\\test\\vtst_teapot000.msh", SRV_FMGR_PHONE_DRV);
        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));

        mesh->setRotation(VfxVector3f(0.0f, 0.0f, 1.0f), VRT_PI_2);
        mesh->setScale(1.2f);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (2, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,     &VfxVector3f(-10, 0, 5));
        kfs->setKeyframe(1, 5000,  &VfxVector3f(-60, 0, 5));

        VfxKeyframeTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, mesh);
        tl->setTarget(mesh);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        tl->setKeyframeSequence(kfs);
        tl->setDuration(5000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setAutoReversed(VFX_TRUE);
        tl->start();

        VFX_OBJ_CREATE_EX(material, VfxMaterial, world, (3));
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);

        kal_wsprintf(vs, "%c:\\test\\stencil\\mirror.vs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_NULL));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
        pass->addShaderUniforms(uniforms);
        uniforms->addUniformVariable(VFX_STR("u_ReflNormal"), VFX_TYPE_ID_VEC3, 1)->setValue(0.0f, 0.0f, 1.0f);

        VFX_OBJ_CREATE(pm, VfxPolygonMode, pass);
        pass->setPolygonMode(pm);
        pm->setWinding(VFX_WINDING_CW);

        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        cm->setColorWriteMask(0x00000000);

        VFX_OBJ_CREATE(stencil, VfxStencil, cm);
        cm->setStencil(stencil);
        stencil->setStencilFunc(
            VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF,
            VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(2, pass);

        kal_wsprintf(vs, "%c:\\test\\stencil\\mirror.vs", SRV_FMGR_PHONE_DRV);
        kal_wsprintf(fs, "%c:\\test\\stencil\\mirror.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
        pass->addShaderUniforms(uniforms);
        uniforms->addUniformVariable(VFX_STR("u_ReflNormal"), VFX_TYPE_ID_VEC3, 1)->setValue(0.0f, 0.0f, 1.0f);
        uniforms->addUniformVariable(VFX_STR("u_FadeDir"), VFX_TYPE_ID_VEC3, 1)->setValue(0.0f, 0.0f, -1.0f);
        uniforms->addUniformVariable(VFX_STR("u_FadeCoef"), VFX_TYPE_ID_VEC3, 1)->setValue(1.0f, 0.01f, 3.0f);

        VFX_OBJ_CREATE(pm, VfxPolygonMode, pass);
        pass->setPolygonMode(pm);
        pm->setWinding(VFX_WINDING_CW);

        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        cm->setDepthFunc(VFX_DEPTH_FUNC_LEQUAL);

        VFX_OBJ_CREATE(stencil, VfxStencil, cm);
        cm->setStencil(stencil);
        stencil->setStencilFunc(
            VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF,
            VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF);

        setTitle(VFX_WSTR("Stencil Buffer Test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Stencil Buffer OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_stencil_buffer(VfxU32 param)
{
    VTST_START_SCRN(VtstRtStencilBuffer);
    return VTST_TR_OK;
}



class VtstRtRenderTarget : public VtstRtScr
{
// Variable
public:
    // Constructor / Destructor
public:
    VtstRtRenderTarget()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxBoxMesh *mesh;
        VfxMaterial *material;
        VfxPass *pass;
        VfxRenderTarget *rt;
        VfxImage2D *rb;
        VfxTexture *tex;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;

        // draw in render target
        VFX_OBJ_CREATE_EX(mesh, VfxBoxMesh, world, (2.0f));

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setKeyframeSequence(kfs);
        qtl->setDuration(20000);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        VFX_OBJ_CREATE_EX(material, VfxMaterial, mesh, (2));
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VFX_OBJ_CREATE(rt, VfxRenderTarget, pass);
        pass->setRenderTarget(rt);

        VFX_OBJ_CREATE_EX(rb, VfxImage2D, rt, (getSize().width / 4, getSize().height / 4, VRT_COLOR_TYPE_RGB565));
        rt->attachColorBuffer(rb);
        rt->enableClearColor(VFX_TRUE);
        rt->setClearColor(VFX_COLOR_GREY);

        // use render target as texture
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, pass, (rb));

        static const vrt_char fs[] =
        "precision mediump float;           \n"
        "varying vec2 vTexCoord;            \n"
        "uniform sampler2D u_RenderTexture; \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = texture2D(u_RenderTexture, vTexCoord); \n"
        "}                                  \n";
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, fs));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);
        VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("u_RenderTexture"), VFX_TYPE_ID_SAMPLER, 1);
        var->setValue(tex);

        setTitle(VFX_WSTR("Render Target test"));
    }

    virtual int start()
    {        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Render Target OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_render_target(VfxU32 param)
{
    VTST_START_SCRN(VtstRtRenderTarget);
    return VTST_TR_OK;
}



class VtstRtPostProcessing : public VtstRtScr
{
// Variable
public:
    // Constructor / Destructor
public:
    VtstRtPostProcessing()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 90), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);

        VfxWChar fn[256];
        kal_wsprintf(fn, "%c:\\test\\vtst_teapot000.msh", SRV_FMGR_PHONE_DRV);
        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setKeyframeSequence(kfs);
        qtl->setDuration(20000);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        VfxMaterial *material;
        VFX_OBJ_CREATE_EX(material, VfxMaterial, mesh, (5));
        mesh->setMaterial(0, material);

        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;
        VfxImage2D *image;
        VFX_OBJ_CREATE_EX(image, VfxImage2D, material, (getSize().width / 2, getSize().height / 2, VRT_COLOR_TYPE_RGB565));

        VfxImage2D *image2;
        VFX_OBJ_CREATE_EX(image2, VfxImage2D, material, (getSize().width / 2, getSize().height / 2, VRT_COLOR_TYPE_RGB565));


        VfxTexture2D *tex;
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, material, (image));

        // Pass 1: Model Pass
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        // Pass 2: Create Glow Map
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);

        VfxRenderTarget *rt1;
        VFX_OBJ_CREATE_EX(rt1, VfxRenderTarget, pass, (image));
        rt1->setClearColor(0xFF000000);
        rt1->enableClearColor(VFX_TRUE);
        pass->setRenderTarget(rt1);
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
#endif
        // Pass 3: Horizontal Blur
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(2, pass);

        VfxRenderTarget *rt2;
        VFX_OBJ_CREATE_EX(rt2, VfxRenderTarget, pass, (image2));
        pass->setRenderTarget(rt2);

        static const vrt_char h_gaussian_blur[] =  
        "precision mediump float;                     \n"
        "varying vec2 vTexCoord;                      \n"
        "uniform sampler2D glow_map;                  \n"
        "uniform ivec2 v3d_BaseTexSize;               \n"
        "void main()                                  \n"
        "{                                            \n"
        "   float blurSize = 1.0 / 100.0;   \n"
        "   gl_FragColor = texture2D(glow_map, vec2(vTexCoord.x - 4.0*blurSize, vTexCoord.y)) * 0.05;  \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x - 3.0*blurSize, vTexCoord.y)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x - 2.0*blurSize, vTexCoord.y)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x - blurSize, vTexCoord.y)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;                \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + blurSize, vTexCoord.y)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + 2.0*blurSize, vTexCoord.y)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + 3.0*blurSize, vTexCoord.y)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + 4.0*blurSize, vTexCoord.y)) * 0.05; \n"
        "}                                            \n";

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, h_gaussian_blur));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
        uniforms->addUniformVariable(VFX_STR("glow_map"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

        // Pass 4: Vertical Blur
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(3, pass);
        pass->setRenderTarget(rt1);

        static const vrt_char v_gaussian_blur[] =  
        "precision mediump float;                     \n"
        "varying vec2 vTexCoord;                      \n"
        "uniform sampler2D glow_map;                  \n"
        "uniform ivec2 v3d_BaseTexSize;               \n"
        "void main()                                  \n"
        "{                                            \n"
        "   float blurSize = 1.0 / 100.0;   \n"
        "   gl_FragColor = texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - 4.0*blurSize)) * 0.05;  \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - 3.0*blurSize)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - 2.0*blurSize)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - blurSize)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;                \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + blurSize)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + 2.0*blurSize)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + 3.0*blurSize)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + 4.0*blurSize)) * 0.05; \n"
        "}     \n";

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, v_gaussian_blur));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image2));
        uniforms->addUniformVariable(VFX_STR("glow_map"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);


        // Pass 5: Add glow
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(4, pass);

        static const vrt_char glow_shader[] =  
        "precision mediump float;                     \n"
        "varying vec2 vTexCoord;                      \n"
        "uniform sampler2D glow_map;                  \n"
        "void main()                                  \n"
        "{                                            \n"
        "   gl_FragColor = texture2D(glow_map, vTexCoord);  \n"
        "}     \n";

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, glow_shader));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
        uniforms->addUniformVariable(VFX_STR("glow_map"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

        VfxCompositingMode *cm;
        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        cm->setDepthTestEnable(VFX_FALSE);
        cm->setDepthWriteEnable(VFX_FALSE);

        VfxBlender *blender;
        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        cm->setBlender(blender);
        blender->setBlendFunc(VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ZERO, VFX_BLEND_FACTOR_ONE);


        setTitle(VFX_WSTR("Post Processing test"));
    }

    virtual int start()
    {        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Post Processing OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_post_processing(VfxU32 param)
{
    VTST_START_SCRN(VtstRtPostProcessing);
    return VTST_TR_OK;
}



class VtstRtGroupMaterial : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtGroupMaterial()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Group Material test"));
    }

    virtual int start()
    {
        return 4;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VfxWChar vs[256];
        VfxWChar fs[256];
        VFX_OBJ_CLOSE(m_world);
        VfxFloat w = getSize().width;
        VfxFloat h = getSize().height;
        switch (idx)
        {
        case 0:
            {
                // world
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                setWorld(m_world);

                // camera
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                m_world->setActiveCamera(camera);
                camera->setPerspective(VRT_PI_2, w / h, 1.0f, 1000.0f);
                camera->setLookAt(VfxVector3f(75, 0, 40), VfxVector3f(0, 0, 0), VfxVector3f(-8, 0, 15));

                #define RENDER_PLANE_STENCIL  (VFX_RENDER_SCOPE_USER_BEGIN << 0)
                #define RENDER_PLANE_COLOR    (VFX_RENDER_SCOPE_USER_BEGIN << 1)

                VfxMaterial *material;
                VfxPass *pass;
                VfxRenderMode *rm;
                VfxPolygonMode *pm;
                VfxCompositingMode *cm;
                VfxBlender *blender;
                VfxStencil *stencil;
                VfxShaderProgram *program;
                VfxShaderUniforms *uniforms;
                VfxMesh *mesh;

                VFX_OBJ_CREATE_EX(material, VfxMaterial, m_world, (2));
                m_world->setMaterial(material);

                // stencil pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                pass->setRenderMode(rm);
                rm->setScope(RENDER_PLANE_STENCIL | VFX_RENDER_SCOPE_DEFAULT);

                kal_wsprintf(vs, "%c:\\test\\stencil\\mirror.vs", SRV_FMGR_PHONE_DRV);
                kal_wsprintf(fs, "%c:\\test\\stencil\\mirror.fs", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);

                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
                pass->addShaderUniforms(uniforms);
                uniforms->addUniformVariable(VFX_STR("u_ReflNormal"), VFX_TYPE_ID_VEC3, 1)->setValue(0.0f, 0.0f, 1.0f);
                uniforms->addUniformVariable(VFX_STR("u_FadeDir"), VFX_TYPE_ID_VEC3, 1)->setValue(0.0f, 0.0f, -1.0f);
                uniforms->addUniformVariable(VFX_STR("u_FadeCoef"), VFX_TYPE_ID_VEC3, 1)->setValue(1.0f, 0.0f, 0.0f);

                VFX_OBJ_CREATE(pm, VfxPolygonMode, pass);
                pass->setPolygonMode(pm);
                pm->setWinding(VFX_WINDING_CW);

                VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
                pass->setCompositingMode(cm);

                VFX_OBJ_CREATE(stencil, VfxStencil, cm);
                cm->setStencil(stencil);
                stencil->setStencilFunc(
                    VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF,
                    VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF);

                // color pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(1, pass);

                VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                pass->setRenderMode(rm);
                rm->setScope(RENDER_PLANE_COLOR | VFX_RENDER_SCOPE_DEFAULT);

                // mirror surface
                VFX_OBJ_CREATE_EX(mesh, VfxPlaneMesh, m_world, (100.0f));

                VFX_OBJ_CREATE_EX(material, VfxMaterial, m_world, (2));
                mesh->setMaterial(0, material);

                // stencil pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                pass->setRenderMode(rm);
                rm->setScope(RENDER_PLANE_STENCIL);

                kal_wsprintf(vs, "%c:\\test\\base.vs", SRV_FMGR_PHONE_DRV);
                kal_wsprintf(fs, "%c:\\test\\base.fs", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);

                VFX_OBJ_CREATE(pm, VfxPolygonMode, pass);
                pass->setPolygonMode(pm);

                VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
                pass->setCompositingMode(cm);
                cm->setColorWriteMask(0x00000000);
                cm->setDepthWriteEnable(VFX_FALSE);

                VFX_OBJ_CREATE(stencil, VfxStencil, cm);
                cm->setStencil(stencil);
                stencil->setStencilFunc(
                    VFX_STENCIL_FUNC_ALWAYS, 1, 0xFFFFFFFF,
                    VFX_STENCIL_FUNC_ALWAYS, 1, 0xFFFFFFFF);
                stencil->setStencilOperation(
                    VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_REPLACE,
                    VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_REPLACE);

                // color pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(1, pass);

                VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                pass->setRenderMode(rm);
                rm->setScope(RENDER_PLANE_COLOR);

                pass->setShaderProgram(program);

                VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
                pass->setCompositingMode(cm);

                VFX_OBJ_CREATE(blender, VfxBlender, cm);
                cm->setBlender(blender);
                blender->setBlendFunc(
                    VFX_BLEND_FACTOR_CONSTANT_COLOR, VFX_BLEND_FACTOR_CONSTANT_ALPHA,
                    VFX_BLEND_FACTOR_CONSTANT_ALPHA, VFX_BLEND_FACTOR_ZERO);
                blender->setBlendColor(VfxColor(192, 0, 192, 0));

                // top objects
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);

                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot000.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));

                mesh->setRotation(VfxVector3f(0.0f, 0.0f, 1.0f), VRT_PI_2);
                mesh->setScale(0.6f);

                VfxKeyframeSequence *kfs;
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (2, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,     &VfxVector3f(0, -20, 5));
                kfs->setKeyframe(1, 5000,  &VfxVector3f(-50, -20, 5));

                VfxKeyframeTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(5000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->setAutoReversed(VFX_TRUE);
                tl->start();

                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, m_world, (10.0));

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (2, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,     &VfxVector3f(0, 20, 20));
                kfs->setKeyframe(1, 5000,  &VfxVector3f(0, -20, 20));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(5000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->setAutoReversed(VFX_TRUE);
                tl->start();

                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, m_world, (10.0));
                mesh->setTranslation(-20, 20, 20);
            }
            confirm(VFX_WSTR("Stencil Reflection OK?"));
            break;
        case 1:
            {
                // world
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                setWorld(m_world);

                // camera
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                m_world->setActiveCamera(camera);
                camera->setPerspective(VRT_PI_2, w / h, 1.0f, 1000.0f);
                camera->setLookAt(VfxVector3f(75, 0, 40), VfxVector3f(0, 0, 0), VfxVector3f(-8, 0, 15));

                // light
                VfxLight *light;
                VFX_OBJ_CREATE(light, VfxLight, m_world);
                light->setTranslation(30, 0, 50);

                // sphere group
                VfxGroup *group;
                VFX_OBJ_CREATE(group, VfxGroup, m_world);

                // cube map
                VfxImageCube *rb;
                VfxDepthBuffer *db;
                VfxTextureCube *tex;
                VFX_OBJ_CREATE_EX(rb, VfxImageCube, m_world, (h / 4, h / 4, VRT_COLOR_TYPE_RGB565));
                VFX_OBJ_CREATE_EX(db, VfxDepthBuffer, m_world, (h / 4, h / 4));
                VFX_OBJ_CREATE_EX(tex, VfxTextureCube, m_world, (rb));

                #define RENDER_SPHERE_REFLECTION    (VFX_RENDER_SCOPE_USER_BEGIN << 0)

                VfxMaterial *material;
                VfxPass *pass;
                VfxRenderMode *rm;
                VfxRenderTarget *rt;
                VfxShaderProgram *program;
                VfxShaderUniforms *uniforms;
                VfxMesh *mesh;

                VFX_OBJ_CREATE_EX(material, VfxMaterial, m_world, (7));
                m_world->setMaterial(material);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
                // PVRTexTool orientation
                VfxVector3f target[6] = {
                    VfxVector3f(0, 1, 0), VfxVector3f(0, -1, 0),
                    VfxVector3f(0, 0, 1), VfxVector3f(0, 0, -1),
                    VfxVector3f(1, 0, 0), VfxVector3f(-1, 0, 0)
                };
                VfxVector3f up[6] = {
                    VfxVector3f(0, 0, -1), VfxVector3f(0, 0, -1),
                    VfxVector3f(1, 0, 0), VfxVector3f(-1, 0, 0),
                    VfxVector3f(0, 0, -1), VfxVector3f(0, 0, -1)
                };
#endif
                VfxColor clear[6] =
                {
                    VFX_COLOR_RED, VFX_COLOR_AQUA,
                    VFX_COLOR_GREEN, VFX_COLOR_FUCHSIA,
                    VFX_COLOR_BLUE, VFX_COLOR_YELLOW
                };

                // cube map passes
                VfxU32 i;
                for (i = 0; i < 6; ++i)
                {
                    VFX_OBJ_CREATE(pass, VfxPass, material);
                    material->setPass(i, pass);

                    VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                    pass->setRenderMode(rm);

                    VFX_OBJ_CREATE(camera, VfxCamera, group);
                    rm->setRenderCamera(camera);
                    camera->setPerspective(VRT_PI_2, 1.0f, 1.0f, 1000.0f);
                    camera->setLookAt(VfxVector3f(0, 0, 0), target[i], up[i]);

                    VFX_OBJ_CREATE(rt, VfxRenderTarget, pass);
                    pass->setRenderTarget(rt);

                    rt->attachColorBuffer(rb, (VfxImageTargetType)(VFX_IMAGE_TARGET_CUBE_POSITIVE_X + i));
                    rt->attachDepthBuffer(db);
                    rt->enableClearColor(VFX_TRUE);
                    rt->setClearColor(clear[i]);
                }

                // normal pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(6, pass);

                VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                pass->setRenderMode(rm);
                rm->setScope(RENDER_SPHERE_REFLECTION | VFX_RENDER_SCOPE_DEFAULT);

                // sphere
                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, group, (20.0f));

                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                mesh->setMaterial(0, material);

                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                VFX_OBJ_CREATE(rm, VfxRenderMode, pass);
                pass->setRenderMode(rm);
                rm->setScope(RENDER_SPHERE_REFLECTION);

                kal_wsprintf(vs, "%c:\\test\\reflection\\reflection.vs", SRV_FMGR_PHONE_DRV);
                kal_wsprintf(fs, "%c:\\test\\reflection\\reflection.fs", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);

                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
                pass->addShaderUniforms(uniforms);
                uniforms->addUniformVariable(VFX_STR("u_CubeTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

                // objects
                VFX_OBJ_CREATE(group, VfxGroup, m_world);

                VfxKeyframeSequence *kfs;
                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, group, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,     &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
                kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(0, 0, vfxSin(2 * VFX_PI / 3)), vfxCos(2 * VFX_PI / 3)));
                kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(0, 0, vfxSin(4 * VFX_PI / 3)), vfxCos(4 * VFX_PI / 3)));
                kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

                VfxKeyframeTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, group);
                tl->setTarget(group);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(20000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                // material for uniform lighting
                VFX_OBJ_CREATE(material, VfxMaterial, group);
                group->setMaterial(material);

                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                static const VfxChar diffuse_vs[] =
                "uniform vec3 uLightPos;                        \n"
                "uniform vec4 v3d_PositionScale;                \n"
                "uniform vec4 v3d_PositionBias;                 \n"
                "uniform mat4 v3d_MVPMatrix;                    \n"
                "uniform mat4 v3d_ModelMatrix;                  \n"
                "uniform mat4 v3d_ModelMatrixInverseTranspose;  \n"
                "attribute vec4 v3d_Position;                   \n"
                "attribute vec3 v3d_Normal;                     \n"
                "attribute vec4 v3d_Color;                      \n"
                "varying vec4 vColor;                           \n"
                "void main()                                    \n"
                "{                                              \n"
                "   vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;                        \n"
                "   gl_Position = v3d_MVPMatrix * position;                                                     \n"
                "   vec4 vPos = v3d_ModelMatrix * position;                                                     \n"
                "   vec3 vLight = normalize(uLightPos - vPos.xyz);                                              \n"
                "   vec3 vNormal = normalize((v3d_ModelMatrixInverseTranspose * vec4(v3d_Normal, 0.0)).xyz);    \n"
                "   vColor = v3d_Color * min(1.0, 0.1 + max(0.0, dot(vNormal, vLight)));                        \n"
                "}                                              \n";

                static const VfxChar diffuse_fs[] =
                "precision mediump float;                       \n"
                "uniform float v3d_Opacity;                     \n"
                "varying vec4 vColor;                           \n"
                "void main()                                    \n"
                "{                                              \n"
                "   gl_FragColor.rgb = vColor.rgb;              \n"
                "   gl_FragColor.a = v3d_Opacity;               \n"
                "}                                              \n";

                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (diffuse_vs, diffuse_fs));
                pass->setShaderProgram(program);

                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
                pass->addShaderUniforms(uniforms);
                uniforms->addUniformVariable(VFX_STR("uLightPos"), VFX_TYPE_ID_VEC3, 1)->bindValue(light, VFX_BINDING_WORLD_SPACE_POSITION);

                VFX_OBJ_CREATE(mesh, VfxMesh, group);

                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot000.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));

                mesh->setTranslation(0, 40, -20);
                mesh->setScale(0.5f);

                VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, group, (5.0));
                mesh->setTranslation(0, 25, 25);

                VfxGroup *group2;
                VFX_OBJ_CREATE(group2, VfxGroup, group);

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, group2, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,     &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
                kfs->setKeyframe(1, 5333,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
                kfs->setKeyframe(2, 10667, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
                kfs->setKeyframe(3, 16000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, group2);
                tl->setTarget(group2);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(16000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                VFX_OBJ_CREATE_EX(mesh, VfxBoxMesh, group2, (10.0));
                mesh->setTranslation(30, 0, 0);

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
                kfs->setKeyframe(1, 3000, &VfxQuaternionf(VfxVector3f(0, 0, vfxSin(2 * VFX_PI / 3)), vfxCos(2 * VFX_PI / 3)));
                kfs->setKeyframe(2, 6000, &VfxQuaternionf(VfxVector3f(0, 0, vfxSin(4 * VFX_PI / 3)), vfxCos(4 * VFX_PI / 3)));
                kfs->setKeyframe(3, 9000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, mesh);
                tl->setTarget(mesh);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(9000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();
            }
            confirm(VFX_WSTR("Dynamic Environment OK?"));
            break;
        case 2:
            {
            }
            confirm(VFX_WSTR("Shadow Map OK?"));
            break;
        case 3:
            {
            }
            confirm(VFX_WSTR("Group Post Processing OK?"));
            break;
        };

        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_group_material(VfxU32 param)
{
    VTST_START_SCRN(VtstRtGroupMaterial);
    return VTST_TR_OK;
}



class VtstRtFrameMaterial : public VtstRtScr
{
// Variable
public:
    // Constructor / Destructor
    VfxFrame *m_frame;
public:
    VtstRtFrameMaterial()
    : m_frame(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Frame Material test"));
    }

    virtual int start()
    {
        return 3;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VfxWChar vs[256];
        VfxWChar fs[256];
        VFX_OBJ_CLOSE(m_frame);
        VfxS32 w = getSize().width;
        VfxS32 h = getSize().height;
        switch (idx)
        {
        case 0:
            {
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setRect(0, 0, w, h);
                m_frame->sendToBack();

                VfxFloatTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxFloatTimeline, m_frame);
                tl->setTarget(m_frame);
                tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
                tl->setDurationTime(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->setFromValue(0.0f);
                tl->setToValue(1.0f);
                tl->start();
                VFX_OBJ_CREATE(tl, VfxFloatTimeline, m_frame);
                tl->setTarget(m_frame);
                tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
                tl->setDurationTime(2000);
                tl->setAutoReversed(VFX_TRUE);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->setFromValue(0.0f);
                tl->setToValue(1.0f);
                tl->start();

                w /= 2;
                h /= 2;
                VfxFrame *frame;
                VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
                frame->setRect(w/2, h/2, w, h);

                h /= 4;
                VcpButton *button;
                VFX_OBJ_CREATE(button, VcpButton, frame);
                button->setRect(0, 0, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 1"));

                VFX_OBJ_CREATE(button, VcpButton, frame);
                button->setRect(0, h, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 2"));

                VFX_OBJ_CREATE(button, VcpButton, frame);
                button->setRect(0, h*2, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 3"));

                VFX_OBJ_CREATE(button, VcpButton, frame);
                button->setRect(0, h*3, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 4"));

                VfxMaterial *material;
                VfxPass *pass;
                VfxShaderProgram *program;
                VfxShaderUniforms *uniforms;
                VfxImage2D *image;
                VfxRenderTarget *rt;
                VfxTexture2D *tex;

                // Material (2 pass rendering)
                VFX_OBJ_CREATE_EX(material, VfxMaterial, m_frame, (2));
                m_frame->setMaterial(material);

                // Pass
                VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
                material->setPass(0, pass);

                // Shader Program                
                kal_wsprintf(fs, "%c:\\test\\blur\\gaussian_blur_h.fs", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);

                // Render Buffer
                VFX_OBJ_CREATE_EX(image, VfxImage2D, pass, (getSize().width/2, getSize().height/2, VRT_COLOR_TYPE_RGB565));

                // Render Target
                VFX_OBJ_CREATE_EX(rt, VfxRenderTarget, pass, (image));
                rt->enableClearColor(VFX_TRUE);
                pass->setRenderTarget(rt);                

                // Pass2
                VFX_OBJ_CREATE(pass, VfxPass, material);

                // Shader Program
                kal_wsprintf(fs, "%c:\\test\\blur\\gaussian_blur_v.fs", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);
                
                // Shader Uniforms
                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
                pass->addShaderUniforms(uniforms);

                // Texture    
                VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
                uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

                material->setPass(1, pass);
            }
            confirm(VFX_WSTR("Viewport Rendering OK?"));
            break;
         case 1:
            {
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setRect(0, 0, w, h);
                m_frame->setBgColor(VFX_COLOR_WHITE);
                m_frame->sendToBack();

                VfxMaterial *material;
                VfxPass *pass;
                VfxShaderProgram *program;

                // Material
                VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
                m_frame->setMaterial(material);

                // Pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                // Shader Program
                kal_wsprintf(vs, "%c:\\test\\globe\\globe.vert", SRV_FMGR_PHONE_DRV);
                kal_wsprintf(fs, "%c:\\test\\globe\\globe.frag", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(
                    program, VfxShaderProgram, pass,
                    (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);


                VfxShaderUniforms *uniforms;
                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
                pass->addShaderUniforms(uniforms);

                VfxShaderVariable *var;

                VfxMatrix4f proj;
                proj.setPerspective(0.6f, (VfxFloat)w / (VfxFloat)h, 0.1f, 10.0f );
                var = uniforms->addUniformVariable(VFX_STR("u_invProjection"), VFX_TYPE_ID_MAT4, 1);
                var->setValue(inverse(proj));

                VfxVector3f earthCentre( 0, -0.25f, -5 );
                var = uniforms->addUniformVariable(VFX_STR("u_centre"), VFX_TYPE_ID_VEC3, 1);
                var->setValue((void *)&earthCentre);

                var = uniforms->addUniformVariable(VFX_STR("u_centre_sqr"), VFX_TYPE_ID_FLOAT, 1);
                var->setValue(dot(earthCentre, earthCentre));

                var = uniforms->addUniformVariable(VFX_STR("u_lightAngle"), VFX_TYPE_ID_FLOAT, 1);
                VfxFloatTimeline *tl;
                VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
                tl->setTarget(var);
                tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
                tl->setDurationTime(10000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->setFromValue(0.0f);
                tl->setToValue(VFX_PI * 2);
                tl->start();

                var = uniforms->addUniformVariable(VFX_STR("u_rot"), VFX_TYPE_ID_FLOAT, 1);
                VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
                tl->setTarget(var);
                tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
                tl->setDurationTime(10000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->setFromValue(0.0f);
                tl->setToValue(1.0f);
                tl->start();

                VfxImage2D *img;
                VfxTexture2D *tex;

                var = uniforms->addUniformVariable(VFX_STR("u_texture"), VFX_TYPE_ID_SAMPLER, 1);
                kal_wsprintf(vs, "%c:\\test\\globe\\day.jpg", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR_DYNAMIC(vs)));
                VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
                tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
                var->setValue(tex);

                var = uniforms->addUniformVariable(VFX_STR("u_night"), VFX_TYPE_ID_SAMPLER, 1);
                kal_wsprintf(vs, "%c:\\test\\globe\\night.jpg", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR_DYNAMIC(vs)));
                VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
                tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
                var->setValue(tex);

                var = uniforms->addUniformVariable(VFX_STR("u_gloss"), VFX_TYPE_ID_SAMPLER, 1);
                kal_wsprintf(vs, "%c:\\test\\globe\\night.jpg", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR_DYNAMIC(vs)));
                VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
                tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
                var->setValue(tex);
            }
            confirm(VFX_WSTR("Globe Effect OK?"));
            break;
        case 2:
            {
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setRect(0, 0, w, h);
                m_frame->setBgColor(VFX_COLOR_WHITE);
                m_frame->sendToBack();

                h /= 4;
                VcpButton *button;
                VFX_OBJ_CREATE(button, VcpButton, m_frame);
                button->setRect(0, 0, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 1"));

                VFX_OBJ_CREATE(button, VcpButton, m_frame);
                button->setRect(0, h, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 2"));

                VFX_OBJ_CREATE(button, VcpButton, m_frame);
                button->setRect(0, h*2, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 3"));

                VFX_OBJ_CREATE(button, VcpButton, m_frame);
                button->setRect(0, h*3, w, h);
                button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                button->setText(VFX_WSTR("Button 4"));

                VfxMaterial *material;
                VfxPass *pass;
                VfxShaderProgram *program;

                // Material
                VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
                m_frame->setMaterial(material);
                m_frame->setHints(VFX_FRAME_HINTS_DEPTH_TEST);

                // Pass
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);
                pass->setTessellationLevel(20, 20);

                // Shader Program
                kal_wsprintf(vs, "%c:\\test\\pagecurl\\pagecurl.vs", SRV_FMGR_PHONE_DRV);
                kal_wsprintf(fs, "%c:\\test\\pagecurl\\pagecurl.fs", SRV_FMGR_PHONE_DRV);
                VFX_OBJ_CREATE_EX(
                    program, VfxShaderProgram, pass,
                    (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
                pass->setShaderProgram(program);

                VfxCompositingMode *cm;
                VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
                pass->setCompositingMode(cm);
                cm->setDepthTestEnable(VFX_TRUE);
                cm->setDepthWriteEnable(VFX_TRUE);

                VfxShaderUniforms *uniforms;
                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
                pass->addShaderUniforms(uniforms);

                VfxShaderVariable *var;
                VcpSlider *slider;
                h = getSize().height / 15;
                VfxS32 t = h;

                var = uniforms->addUniformVariable(VFX_STR("A"), VFX_TYPE_ID_FLOAT, 1);
                var->setValue(-m_frame->getSize().height / 4.0f);
                VFX_OBJ_CREATE(slider, VcpSlider, this);
                slider->setAttachProperty(0x10000001, &var, sizeof(VfxShaderVariable *));
                slider->setPos(0, t);
                slider->setLength(getSize().width);
                slider->setMaxValue(m_frame->getSize().height * 4.0f);
                slider->setMinValue(-m_frame->getSize().height * 4.0f);
                slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
                slider->m_signalUserChangedValue.connect(this, &VtstRtFrameMaterial::onAChanged);

                t += h;
                var = uniforms->addUniformVariable(VFX_STR("theta"), VFX_TYPE_ID_FLOAT, 1);
                var->setValue(VFX_PI / 6.0f);
                VFX_OBJ_CREATE(slider, VcpSlider, this);                
                slider->setAttachProperty(0x10000002, &var, sizeof(VfxShaderVariable *));
                slider->setPos(0, t);
                slider->setLength(getSize().width);
                slider->setMaxValue(VFX_PI / 2.0f);
                slider->setMinValue(0.0f);
                slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
                slider->m_signalUserChangedValue.connect(this, &VtstRtFrameMaterial::onThetaChanged);

                t += h;
                var = uniforms->addUniformVariable(VFX_STR("rho"), VFX_TYPE_ID_FLOAT, 1);
                var->setValue(0.0f);
                VFX_OBJ_CREATE(slider, VcpSlider, this);
                slider->setAttachProperty(0x10000003, &var, sizeof(VfxShaderVariable *));
                slider->setPos(0, t);
                slider->setLength(getSize().width);
                slider->setMaxValue(VFX_PI / 2.0f);
                slider->setMinValue(0.0f);
                slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
                slider->m_signalUserChangedValue.connect(this, &VtstRtFrameMaterial::onRhoChanged);
            }
            confirm(VFX_WSTR("Tessellation OK?"));
            break;
        };
        
        return -1;
    }

    void onAChanged(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VcpSlider *slider = VFX_OBJ_DYNAMIC_CAST(sender->getParent(), VcpSlider);
        VfxShaderVariable *var = *(VfxShaderVariable **)slider->getAttachProperty(0x10000001, sizeof(VfxShaderVariable *));
        var->setValue(newval);
    }

    void onThetaChanged(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VcpSlider *slider = VFX_OBJ_DYNAMIC_CAST(sender->getParent(), VcpSlider);
        VfxShaderVariable *var = *(VfxShaderVariable **)slider->getAttachProperty(0x10000002, sizeof(VfxShaderVariable *));
        var->setValue(newval);
    }

    void onRhoChanged(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VcpSlider *slider = VFX_OBJ_DYNAMIC_CAST(sender->getParent(), VcpSlider);
        VfxShaderVariable *var = *(VfxShaderVariable **)slider->getAttachProperty(0x10000003, sizeof(VfxShaderVariable *));
        var->setValue(newval);
    }
};


VtstTestResultEnum vtst_rt_3d_frame_material(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameMaterial);
    return VTST_TR_OK;
}



class VtstRtBuiltinUniforms : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    
    // Constructor / Destructor
public:
    VtstRtBuiltinUniforms()
    : m_frame(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar vs[256];
        VfxWChar fs[256];

        VtstRtScr::onInit();
        {            
            // test draw in screen space
            VfxFrame *frame;
            VFX_OBJ_CREATE(frame, VfxFrame, this);
            m_frame = frame;
            frame->setAnchor(0.5f, 0.5f);
            frame->setPos(100, 100);
            frame->setSize(140, 140);
            frame->setBgColor(VFX_COLOR_YELLOW);            

            VfxFloatTimeline *tl;
            VFX_OBJ_CREATE(tl, VfxFloatTimeline, frame);
            tl->setTarget(frame);
            tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
            tl->setDurationTime(2000);
            tl->setAutoReversed(VFX_TRUE);
            tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            tl->setFromValue(0.0f);
            tl->setToValue(1.0f);
            tl->start();

            VfxMaterial *mtl;
            VFX_OBJ_CREATE(mtl, VfxMaterial, frame);
            frame->setMaterial(mtl);

            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, mtl);
            mtl->setPass(0, pass);

            kal_wsprintf(vs, "%c:\\test\\builtin_uniform\\frame.vs", SRV_FMGR_PHONE_DRV);
            kal_wsprintf(fs, "%c:\\test\\builtin_uniform\\frame.fs", SRV_FMGR_PHONE_DRV);
            VfxShaderProgram *program;
            VFX_OBJ_CREATE_EX(
                program,
                VfxShaderProgram,
                pass,
                (VFX_WSTR_DYNAMIC(vs),
                 VFX_WSTR_DYNAMIC(fs)));

            pass->setShaderProgram(program);
        }


        {
            // test draw in temp buffer space
            VfxFrame *parent;
            VFX_OBJ_CREATE(parent, VfxFrame, this);
            parent->setBgColor(VFX_COLOR_RED);
            parent->setOpacity(0.5f);
            parent->setRect(0, 200, 200, 200);

            VfxFrame *frame;
            VFX_OBJ_CREATE(frame, VfxFrame, parent);
            frame->setAnchor(0.5f, 0.5f);
            frame->setPos(100, 100);
            frame->setSize(140, 140);
            frame->setBgColor(VFX_COLOR_YELLOW);

            VfxFloatTimeline *tl;
            VFX_OBJ_CREATE(tl, VfxFloatTimeline, frame);
            tl->setTarget(frame);
            tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
            tl->setDurationTime(2000);
            tl->setAutoReversed(VFX_TRUE);
            tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            tl->setFromValue(0.0f);
            tl->setToValue(1.0f);
            tl->start();

            VfxMaterial *mtl;
            VFX_OBJ_CREATE(mtl, VfxMaterial, frame);
            frame->setMaterial(mtl);

            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, mtl);
            mtl->setPass(0, pass);

            VfxShaderProgram *program;
            kal_wsprintf(vs, "%c:\\test\\builtin_uniform\\frame.vs", SRV_FMGR_PHONE_DRV);
            kal_wsprintf(fs, "%c:\\test\\builtin_uniform\\frame.fs", SRV_FMGR_PHONE_DRV);
            VFX_OBJ_CREATE_EX(
                program,
                VfxShaderProgram,
                pass,
                (VFX_WSTR_DYNAMIC(vs),
                 VFX_WSTR_DYNAMIC(fs)));
            
            pass->setShaderProgram(program);

        }

        setTitle(VFX_WSTR("Builtin Uniforms test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Builtin Uniforms OK?"));
        return -1;
    }


    VfxBool onPenInput(VfxPenEvent &event)
    {
        switch (event.type)
        {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_frame->setPos(event.downPos);
            break;
        }
        
        // do nothing
        return VtstRtScr::onPenInput(event);
    }
};


VtstTestResultEnum vtst_rt_3d_builtin_uniforms(VfxU32 param)
{
    VTST_START_SCRN(VtstRtBuiltinUniforms);
    return VTST_TR_OK;
}




class VtstRtColorFrameMaterial : public VtstRtScr
{
// Variable
public:
    
    // Constructor / Destructor
public:
    VtstRtColorFrameMaterial()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar fs[256];

        VtstRtScr::onInit();
        {
            VfxMaterial *mtl;
            VFX_OBJ_CREATE(mtl, VfxMaterial, this);

            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, mtl);
            mtl->setPass(0, pass);

            kal_wsprintf(fs, "%c:\\test\\color_frame_material\\color_frame.fs", SRV_FMGR_PHONE_DRV);
            VfxShaderProgram *program;
            VFX_OBJ_CREATE_EX(
                program,
                VfxShaderProgram,
                pass,
                (VFX_WSTR_NULL,
                 VFX_WSTR_DYNAMIC(fs)));
            pass->setShaderProgram(program);
            
            // create pure color frame (no texture content and children)
            VfxFrame *frame;
            VFX_OBJ_CREATE(frame, VfxFrame, this);
            frame->setPos(getSize().width / 8 , getSize().height / 8);
            frame->setSize(getSize().width / 4 , getSize().height / 4);
            frame->setBgColor(VRT_COLOR_YELLOW);
            frame->setMaterial(mtl);

            VFX_OBJ_CREATE(frame, VfxFrame, this);
            frame->setPos(getSize().width * 5 / 8 , getSize().height / 8);
            frame->setSize(getSize().width / 4 , getSize().height / 4);
            frame->setMaterial(mtl);

            VfxTransform transform;
            transform.type = VRT_TRANSFORM_TYPE_AFFINE;
            transform.data.affine.rz = VFX_PI / 4;            
            VFX_OBJ_CREATE(frame, VfxFrame, this);
            frame->setPos(getSize().width / 8 , getSize().height * 5 / 8);
            frame->setSize(getSize().width / 4 , getSize().height / 4);
            frame->setBgColor(VRT_COLOR_RED);
            frame->setTransform(transform);
            frame->setMaterial(mtl);

            transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            transform.data.matrix3x3.m[0] = 1.2f;
            transform.data.matrix3x3.m[1] = 0.0f;
            transform.data.matrix3x3.m[2] = 0.0f;
            transform.data.matrix3x3.m[3] = 0.0f;
            transform.data.matrix3x3.m[4] = 0.8f;
            transform.data.matrix3x3.m[5] = 0.0f;
            transform.data.matrix3x3.m[6] = 0.0f;
            transform.data.matrix3x3.m[7] = 0.0f;
            transform.data.matrix3x3.m[8] = 1.0f;
            VFX_OBJ_CREATE(frame, VfxFrame, this);
            frame->setPos(getSize().width * 5 / 8 , getSize().height * 5 / 8);
            frame->setSize(getSize().width / 4 , getSize().height / 4);
            frame->setBgColor(VRT_COLOR_GREEN);
            frame->setTransform(transform);
            frame->setMaterial(mtl);
        }

        setTitle(VFX_WSTR("Color frame material test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Color frame material OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_color_frame_material(VfxU32 param)
{
    VTST_START_SCRN(VtstRtColorFrameMaterial);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

