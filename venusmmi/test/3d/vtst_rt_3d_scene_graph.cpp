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
 *  vtst_rt_3d_scene_graph.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d scene graph
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
#include "vfx_skinned_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_texture.h"
#include "vfx_render_buffer.h"
#include "vfx_asset_loader.h"

#include "vcp_button.h"
#include "vcp_slider.h"
#include "gles2\gl2.h"
#include "FileMgrSrvGprot.h"
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
#include "cp\vapp_video_player_cp.h"
#include "mmi_rp_vapp_setting_def.h"
#endif

class VtstRtSceneGraph : public VtstRtScr
{
// Variable
public:

    VfxWorld *m_world;
    VfxCamera *m_camera;
    VfxLight *m_light;
    VfxGroup *m_group;
    VfxSphereMesh *m_mesh1;
    VfxSphereMesh *m_mesh2;
    VfxSphereMesh *m_mesh3;
    VfxSphereMesh *m_mesh4;

    /* UI button */
    VcpButton *m_btnAddCamera;
    VcpButton *m_btnRemoveCamera;

    VcpButton *m_btnAddLight;
    VcpButton *m_btnRemoveLight;

    VcpButton *m_btnAddGroup;
    VcpButton *m_btnRemoveGroup;

    VcpButton *m_btnAddMesh1;
    VcpButton *m_btnRemoveMesh1;
    VcpButton *m_btnAddMesh2;
    VcpButton *m_btnRemoveMesh2;
    VcpButton *m_btnAddMesh3;
    VcpButton *m_btnRemoveMesh3;
    VcpButton *m_btnAddMesh4;
    VcpButton *m_btnRemoveMesh4;

    // Constructor / Destructor
public:
    VtstRtSceneGraph()
    : m_world(NULL)
    , m_camera(NULL)
    , m_light(NULL)
    , m_mesh1(NULL)
    , m_mesh2(NULL)
    , m_group(NULL)
    , m_mesh3(NULL)
    , m_mesh4(NULL)
    , m_btnAddCamera(NULL)
    , m_btnRemoveCamera(NULL)
    , m_btnAddLight(NULL)
    , m_btnRemoveLight(NULL)
    , m_btnAddGroup(NULL)
    , m_btnRemoveGroup(NULL)
    , m_btnAddMesh1(NULL)
    , m_btnRemoveMesh1(NULL)
    , m_btnAddMesh2(NULL)
    , m_btnRemoveMesh2(NULL)
    , m_btnAddMesh3(NULL)
    , m_btnRemoveMesh3(NULL)
    , m_btnAddMesh4(NULL)
    , m_btnRemoveMesh4(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxS32 w = getSize().width / 4;
        VfxS32 h = getSize().height / 17;
        VfxS32 l = 0;
        VfxS32 t = h * 1;

        VFX_OBJ_CREATE(m_world, VfxWorld, this);
        setWorld(m_world);

        VFX_OBJ_CREATE(m_btnAddCamera, VcpButton, this);
        m_btnAddCamera->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddCamera->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddCamera->setText(VFX_WSTR("+ Camera"));
        m_btnAddCamera->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddCamera);

        VFX_OBJ_CREATE(m_btnRemoveCamera, VcpButton, this);
        m_btnRemoveCamera->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveCamera->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveCamera->setText(VFX_WSTR("- Camera"));
        m_btnRemoveCamera->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveCamera);

        VFX_OBJ_CREATE(m_btnAddLight, VcpButton, this);
        m_btnAddLight->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddLight->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddLight->setText(VFX_WSTR("+ Light"));
        m_btnAddLight->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddLight);

        VFX_OBJ_CREATE(m_btnRemoveLight, VcpButton, this);
        m_btnRemoveLight->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveLight->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveLight->setText(VFX_WSTR("- Light"));
        m_btnRemoveLight->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveLight);

        VFX_OBJ_CREATE(m_btnAddGroup, VcpButton, this);
        m_btnAddGroup->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddGroup->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddGroup->setText(VFX_WSTR("+ Group"));
        m_btnAddGroup->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddGroup);

        VFX_OBJ_CREATE(m_btnRemoveGroup, VcpButton, this);
        m_btnRemoveGroup->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveGroup->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveGroup->setText(VFX_WSTR("- Group"));
        m_btnRemoveGroup->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveGroup);

        VFX_OBJ_CREATE(m_btnAddMesh1, VcpButton, this);
        m_btnAddMesh1->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh1->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh1->setText(VFX_WSTR("+ Mesh1"));
        m_btnAddMesh1->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddMesh1);

        VFX_OBJ_CREATE(m_btnRemoveMesh1, VcpButton, this);
        m_btnRemoveMesh1->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh1->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh1->setText(VFX_WSTR("- Mesh1"));
        m_btnRemoveMesh1->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveMesh1);

        VFX_OBJ_CREATE(m_btnAddMesh2, VcpButton, this);
        m_btnAddMesh2->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh2->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh2->setText(VFX_WSTR("+ Mesh2"));
        m_btnAddMesh2->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddMesh2);

        VFX_OBJ_CREATE(m_btnRemoveMesh2, VcpButton, this);
        m_btnRemoveMesh2->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh2->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh2->setText(VFX_WSTR("- Mesh2"));
        m_btnRemoveMesh2->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveMesh2);

        VFX_OBJ_CREATE(m_btnAddMesh3, VcpButton, this);
        m_btnAddMesh3->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh3->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh3->setText(VFX_WSTR("+ Mesh3"));
        m_btnAddMesh3->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddMesh3);

        VFX_OBJ_CREATE(m_btnRemoveMesh3, VcpButton, this);
        m_btnRemoveMesh3->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh3->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh3->setText(VFX_WSTR("- Mesh3"));
        m_btnRemoveMesh3->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveMesh3);

        VFX_OBJ_CREATE(m_btnAddMesh4, VcpButton, this);
        m_btnAddMesh4->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh4->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh4->setText(VFX_WSTR("+ Mesh4"));
        m_btnAddMesh4->m_signalClicked.connect(this, &VtstRtSceneGraph::onAddMesh4);

        VFX_OBJ_CREATE(m_btnRemoveMesh4, VcpButton, this);
        m_btnRemoveMesh4->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh4->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh4->setText(VFX_WSTR("- Mesh4"));
        m_btnRemoveMesh4->m_signalClicked.connect(this, &VtstRtSceneGraph::onRemoveMesh4);

        setTitle(VFX_WSTR("3D Scene Graph test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Scene Graph OK?"));
        return -1;
    }

    void onAddCamera(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_camera == NULL)
        {
            VFX_OBJ_CREATE(m_camera, VfxCamera, m_world);
            m_world->setActiveCamera(m_camera);
            m_camera->setPerspective(
                VRT_PI_2,
                (vrt_float)getSize().width / (vrt_float)getSize().height,
                1.0f, 1000.0f);
            m_camera->setLookAt(VrtVector3f(0, 2, 5), VrtVector3f(0, 2, 0), VrtVector3f(0, 1, 0));
        }
    }

    void onRemoveCamera(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_camera)
        {
            VFX_OBJ_CLOSE(m_camera);
        }
    }

    void onAddLight(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_light == NULL)
        {
            VFX_OBJ_CREATE(m_light, VfxLight, m_world);
        }
    }

    void onRemoveLight(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_light)
        {
            VFX_OBJ_CLOSE(m_light);
        }
    }

    void onAddGroup(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group == NULL)
        {
            VFX_OBJ_CREATE(m_group, VfxGroup, m_world);
            m_group->setTranslation(0, 4, 0);
        }
    }

    void onRemoveGroup(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group)
        {
            VFX_OBJ_CLOSE(m_group);
            m_mesh3 = NULL;
            m_mesh4 = NULL;
        }
    }

    void onAddMesh1(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh1 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh1, VfxSphereMesh, m_world);
            m_mesh1->setTranslation(2, 0, 0);
        }
    }

    void onRemoveMesh1(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh1)
        {
            VFX_OBJ_CLOSE(m_mesh1);
        }
    }

    void onAddMesh2(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh2 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh2, VfxSphereMesh, m_world);
            m_mesh2->setTranslation(-2, 0, 0);
        }
    }

    void onRemoveMesh2(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh2)
        {
            VFX_OBJ_CLOSE(m_mesh2);
        }
    }

    void onAddMesh3(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group && m_mesh3 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh3, VfxSphereMesh, m_group);
            m_mesh3->setTranslation(2, 0, 0);
        }
    }

    void onRemoveMesh3(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh3)
        {
            VFX_OBJ_CLOSE(m_mesh3);
        }
    }

    void onAddMesh4(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group && m_mesh4 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh4, VfxSphereMesh, m_group);
            m_mesh4->setTranslation(-2, 0, 0);
        }
    }

    void onRemoveMesh4(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh4)
        {
            VFX_OBJ_CLOSE(m_mesh4);
        }
    }

};

VtstTestResultEnum vtst_rt_3d_scene_graph(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSceneGraph);
    return VTST_TR_OK;
}



class VtstRtTransformable : public VtstRtScr
{
// Variable
public:

    VfxBoxMesh *m_mesh;

    // Constructor / Destructor
public:
    VtstRtTransformable()
    : m_mesh(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VFX_OBJ_CREATE(m_mesh, VfxBoxMesh, world);

        VfxS32 texWidth = 100;
        VfxTextFrame *text;
        VcpSlider *slider;

        VfxS32 t = getSize().height/16;
        VfxS32 b = getSize().height;

        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Scale"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(2.0);
        slider->setMinValue(0.5);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtTransformable::onScaleChange);

        t += getSize().height/16;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, getSize().height*2/16);
        text->setString(VFX_WSTR("Rotate"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, getSize().height*2/16);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtTransformable::onRotationChange);

        t += getSize().height/16;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Translate"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(2);
        slider->setMinValue(-2);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtTransformable::onTranslationChange);

        setTitle(VFX_WSTR("Tranformable test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Transformable OK?"));
        return -1;
    }

    void onScaleChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setScale(newval);
    }

    void onRotationChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setRotationX(newval);
    }

    void onTranslationChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setTranslation(newval, 0, 0);
    }
};

VtstTestResultEnum vtst_rt_3d_transformable(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTransformable);
    return VTST_TR_OK;
}




class VtstRtNode : public VtstRtScr
{
// Variable
public:

    VfxBoxMesh *m_mesh;

    // Constructor / Destructor
public:
    VtstRtNode()
    : m_mesh(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VFX_OBJ_CREATE(m_mesh, VfxBoxMesh, world);

        VfxS32 l = 0;
        VfxS32 h = getSize().height / 16;
        VfxS32 t = 0;
        VfxS32 texWidth = 100;

        t += h;
        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, this);
        button->setPos(l, t);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("setVisible"));
        button->m_signalClicked.connect(this, &VtstRtNode::onChangeVisible);

        t += h;
        VfxTextFrame *text;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Opacity"));
        VcpSlider *slider;
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(1);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtNode::onOpacityChange);


        setTitle(VFX_WSTR("Node test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Node OK?"));
        return -1;
    }

    void onChangeVisible(VfxObject* sender, VfxId id)
    {
        m_mesh->setVisible(!m_mesh->isVisible());
    }

    void onOpacityChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setOpacity(newval);
    }
};

VtstTestResultEnum vtst_rt_3d_node(VfxU32 param)
{
    VTST_START_SCRN(VtstRtNode);
    return VTST_TR_OK;
}



class VtstRtGroup : public VtstRtScr
{
// Variable
public:
    VfxGroup *m_group[3];
    VfxBoxMesh *m_mesh[3];

    // Constructor / Destructor
public:
    VtstRtGroup()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 8), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));


        VfxObject *parent = world;
        VfxS32 i;
        VfxMatrix4f pivot;
        pivot.translate(0.5f, 0, 0);
        for (i = 0; i < 3; ++i)
        {
            VFX_OBJ_CREATE(m_group[i], VfxGroup, parent);
            parent = m_group[i];
            if (i != 0)
            {
                m_group[i]->setTranslation(2, 0, 0);
            }

            VFX_OBJ_CREATE(m_mesh[i], VfxBoxMesh, parent);
            m_mesh[i]->setScale(2.0f, 0.25f, 0.25f);
            m_mesh[i]->setPivot(pivot);
        }

        VfxS32 l = 0;
        VfxS32 h = getSize().height / 16;
        VfxS32 t = 0;
        VfxS32 texWidth = 50;

        t += h;
        VfxTextFrame *text;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Group1"));
        VcpSlider *slider;
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtGroup::onRotationChange1);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Group2"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtGroup::onRotationChange2);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Group3"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtGroup::onRotationChange3);
        setTitle(VFX_WSTR("Group test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Hierarchy Transform OK?"));
        return -1;
    }

    void onRotationChange1(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_group[0]->setRotationZ(newval);
    }

    void onRotationChange2(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_group[1]->setRotationZ(newval);
    }

    void onRotationChange3(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_group[2]->setRotationZ(newval);
    }

};

VtstTestResultEnum vtst_rt_3d_group(VfxU32 param)
{
    VTST_START_SCRN(VtstRtGroup);
    return VTST_TR_OK;
}





class VtstRtCamera : public VtstRtScr
{
// Variable
public:
    VfxCamera *m_camera;
    // Constructor / Destructor
public:
    VtstRtCamera()
    : m_camera(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VFX_OBJ_CREATE(m_camera, VfxCamera, world);
        world->setActiveCamera(m_camera);
        m_camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        m_camera->setLookAt(VrtVector3f(0, 0, 8), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(2, 0 ,0);
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(-2, 0 ,0);
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(0, 0 ,2);
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(0, 0 ,-2);

        VfxS32 l = 0;
        VfxS32 h = getSize().height / 16;
        VfxS32 t = 0;
        VfxS32 texWidth = 50;

        VfxTextFrame *text;
        VcpSlider *slider;

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("TX"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(5);
        slider->setMinValue(-5);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtCamera::onTranslationXChange);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("TY"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(5);
        slider->setMinValue(-5);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtCamera::onTranslationYChange);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("TZ"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(10);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtCamera::onTranslationZChange);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("RY"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI);
        slider->setMinValue(-VFX_PI);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &VtstRtCamera::onRotationYChange);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Camera Control OK?"));
        return -1;
    }

    void onTranslationXChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VfxVector3f trans = m_camera->getTranslation();
        trans.x = newval;
        m_camera->setTranslation(trans);
    }

    void onTranslationYChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VfxVector3f trans = m_camera->getTranslation();
        trans.y = newval;
        m_camera->setTranslation(trans);
    }

    void onTranslationZChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VfxVector3f trans = m_camera->getTranslation();
        trans.z = newval;
        m_camera->setTranslation(trans);
    }

    void onRotationYChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_camera->setRotationY(newval);
    }
};

VtstTestResultEnum vtst_rt_3d_camera(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCamera);
    return VTST_TR_OK;
}



class VtstRtMesh : public VtstRtScr
{
// Variable
public:
    VfxMesh *m_mesh;

// Constructor / Destructor
public:
    VtstRtMesh()
    : m_mesh(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (VfxFloat)getSize().width / (VfxFloat)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(3, 2, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxWChar fn[256];
        VFX_OBJ_CREATE(m_mesh, VfxMesh, world);
        kal_wsprintf(fn, "%c:\\test\\vtst_col_logo.msh", SRV_FMGR_PHONE_DRV);
        VfxAssetLoader::loadMesh(m_mesh, VFX_WSTR_DYNAMIC(fn));
        m_mesh->rotateX(-VRT_PI / 2);

        VfxS32 h = getSize().height / 10;
        VfxS32 w = getSize().width - 2 * h;
        VfxS32 l = h;
        VfxS32 t = 0;

        t += h;
        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, this);
        button->setRect(l, t, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("setSubMeshVisible 0"));
        button->m_signalClicked.connect(this, &VtstRtMesh::onChangeVisible0);

        t += h;
        VFX_OBJ_CREATE(button, VcpButton, this);
        button->setRect(l, t, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("setSubMeshVisible 1"));
        button->m_signalClicked.connect(this, &VtstRtMesh::onChangeVisible1);

        setTitle(VFX_WSTR("Mesh test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Mesh Control OK?"));
        return -1;
    }

    void onChangeVisible0(VfxObject* sender, VfxId id)
    {
        m_mesh->setSubMeshVisible(0, !m_mesh->isSubMeshVisible(0));
    }

    void onChangeVisible1(VfxObject* sender, VfxId id)
    {
        m_mesh->setSubMeshVisible(1, !m_mesh->isSubMeshVisible(1));
    }
};

VtstTestResultEnum vtst_rt_3d_mesh(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMesh);
    return VTST_TR_OK;
}



class VtstRtViewport : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    // Constructor / Destructor
public:
    VtstRtViewport()
    : m_frame(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(100, 100, 100, 100);
        m_frame->sendToBack();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            1,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("3D Viewport OK?"));
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

VtstTestResultEnum vtst_rt_3d_viewport(VfxU32 param)
{
    VTST_START_SCRN(VtstRtViewport);
    return VTST_TR_OK;
}


class VtstRtFrameTexture : public VtstRtScr
{
// Variable
public:

    // Constructor / Destructor
public:
    VtstRtFrameTexture()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxFrame *frame_3d;
        VFX_OBJ_CREATE(frame_3d, VfxFrame, this);
        frame_3d->setSize(getSize());

        // referenced texture frame is created after the 3d frame
        VfxFrame *frame;
        VFX_OBJ_CREATE(m_textureFrame, VfxFrame, this);
        frame = m_textureFrame;

        // texture frame it is
        frame->setSize(100, 250);
        frame->setHints(VFX_FRAME_HINTS_TEXTURE);

        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0, 0, 100, 50);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 1"));

        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0,50, 100, 50);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 2"));

        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0,100, 100, 50);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Stop tl"));
        button->m_signalClicked.connect(this, &VtstRtFrameTexture::onTestTl);

        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0,150, 100, 50);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Test hidden"));
        button->m_signalClicked.connect(this, &VtstRtFrameTexture::onTestHidden);

        VFX_OBJ_CREATE(m_text, VfxTextFrame, frame);
        m_text->setRect(0,200, 100, 50);
        m_text->setString(VFX_WSTR("0"));

        VFX_OBJ_CREATE(m_timer, VfxTimer, button);
        m_time = 0;
        m_timer->setDuration(1000);
        m_timer->m_signalTick.connect(this, &VtstRtFrameTexture::onTimerTick);
        m_timer->start();

        VfxWorld *world;
        VFX_OBJ_CREATE(m_world, VfxWorld, this);
        world = m_world;
        frame_3d->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
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
        VFX_OBJ_CREATE(m_tl, VfxKeyframeTimeline, mesh);
        qtl = m_tl;
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

        // use FPE to watch texture frame dirty to update the 3D frame
        frame_3d->setPropertyEffectCallback(m_textureFrame,
                          fpeCallback,
                          NULL,
                          0,
                          VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

        setTitle(VFX_WSTR("Frame Texture test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Frame Cache OK?"));
        return -1;
    }

private:
    void onTestHidden(VfxObject* sender, VfxId Id)
    {
        if (m_textureFrame->getHints() == VFX_FRAME_HINTS_TEXTURE)
        {
            m_textureFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
        }
        else
        {
            m_textureFrame->setHints(VFX_FRAME_HINTS_TEXTURE);
        }
    }

    void onTestTl(VfxObject* sender, VfxId Id)
    {
        if (m_tl->getIsEnabled())
        {
            m_tl->stop();
        }
        else
        {
            m_tl->start();
        }
    }

    void onTimerTick(VfxTimer *source)
    {
        VfxWString str;
        str.format("%d", m_time);
        m_text->setString(str);
        m_time++;
    }

    static vrt_render_dirty_type_enum fpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                     const vrt_frame_visual_property_struct *watch_frame,
                                                     void *user_data,
                                                     vrt_u32 user_data_size)
    {
        return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
    }

    VfxWorld *m_world;
    VfxFrame *m_textureFrame;
    VfxKeyframeTimeline *m_tl;
    VfxTextFrame *m_text;
    VfxU32 m_time;
    VfxTimer *m_timer;
};

VtstTestResultEnum vtst_rt_3d_frame_texture(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameTexture);
    return VTST_TR_OK;
}



class VtstRtTextureTransform : public VtstRtScr
{
// Variable
public:

    // Constructor / Destructor
public:
    VtstRtTextureTransform()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar vs[256];
        VfxWChar fs[256];
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 70), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);
        kal_wsprintf(vs, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(vs));
        mesh->setRotationX(-VFX_PI / 3);

        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);


        VfxShaderProgram *program;
        kal_wsprintf(vs, "%c:\\test\\texture_animation\\tex_ani.vs", SRV_FMGR_PHONE_DRV);
        kal_wsprintf(fs, "%c:\\test\\texture_animation\\tex_ani.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("tex"), VFX_TYPE_ID_SAMPLER, 1);

        VfxTexture2D *texture;
        kal_wsprintf(vs, "%c:\\test\\fieldstone-texture.jpg", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (VFX_WSTR_DYNAMIC(vs)));
        texture->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
        var->setValue(texture);

        var = uniforms->addUniformVariable(VFX_STR("uTextureMatrix"), VFX_TYPE_ID_MAT4, 1);
        var->bindValue(texture, VFX_BINDING_TRANSFORM);


        VfxVector3fTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxVector3fTimeline, texture);
        tl->setTarget(texture);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        tl->setFromValue(VfxVector3f(0, 0, 0));
        tl->setToValue(VfxVector3f(1, 0, 0));
        tl->setDuration(2000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        setTitle(VFX_WSTR("Texture Transform test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Texture Transform OK?"));
        return -1;
    }

};

VtstTestResultEnum vtst_rt_3d_texture_transform(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextureTransform);
    return VTST_TR_OK;
}




class VtstRtProjectiveTexture : public VtstRtScr
{
// Variable
public:

    // Constructor / Destructor
public:
    VtstRtProjectiveTexture()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar fn[256];
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 60), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxLight *light;
        VFX_OBJ_CREATE(light, VfxLight, world);
        light->setTranslation(0, 50, 0);
        light->setRotationX(-VFX_PI / 2);

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);
        kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
        mesh->setRotationX(-VFX_PI / 3);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(vfxSin(2 * VFX_PI / 3), 0, 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(vfxSin(4 * VFX_PI / 3), 0, 0), vfxCos(4 * VFX_PI / 3)));
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


        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        static const vrt_char vShader[] =
        "attribute vec4 v3d_Position;     \n"
        "attribute vec3 v3d_Normal;       \n"
        "varying vec4 vColor;             \n"
        "varying vec4 vTexCoord;          \n"
        "uniform vec4 v3d_PositionScale;  \n"
        "uniform vec4 v3d_PositionBias;   \n"
        "uniform mat4 v3d_MVPMatrix;      \n"
        "uniform mat4 v3d_ModelMatrix;    \n"
        "uniform mat4 v3d_ViewMatrix;     \n"
        "uniform mat3 v3d_NormalMatrix;   \n"
        "uniform mat4 u_LightViewMatrix;  \n"
        "uniform mat4 u_LightProjectMatrix;\n"
        "void main()                      \n"
        "{                                \n"
        "   vec4 pos = v3d_Position * v3d_PositionScale + v3d_PositionBias; \n"
        "   gl_Position = v3d_MVPMatrix * pos; \n"
        "   vTexCoord = u_LightProjectMatrix * v3d_ViewMatrix * v3d_ModelMatrix * pos; \n"
        "   vColor.rgb = vec3(dot(v3d_NormalMatrix * v3d_Normal, vec3(0.0, 0.0, 1.0))); \n"
        "   vColor.a = 1.0;               \n"
        "}                                \n";

        static const vrt_char fShader[] =
        "precision mediump float;           \n"
        "varying vec4 vColor;               \n"
        "varying vec4 vTexCoord;            \n"
        "uniform sampler2D u_ProjTex;       \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = vColor * texture2DProj(u_ProjTex, vTexCoord);  \n"
        "}                                  \n";

        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (vShader, fShader));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("u_LightViewMatrix"), VFX_TYPE_ID_MAT4, 1);
        var->bindValue(light, VFX_BINDING_INVERSE_WORLD_TRANSFORM);

        var = uniforms->addUniformVariable(VFX_STR("u_LightProjectMatrix"), VFX_TYPE_ID_MAT4, 1);
        VfxMatrix4f proj;
        proj.setPerspective(VFX_PI / 4.0f, 1.0f, 1.0f, 1000.0f);
        VfxMatrix4f bias;
        bias.setScale(0.5f);
        bias.translate(0.5f, 0.5f, 0.5f);
        bias *= proj;
        var->setValue(bias);

        var = uniforms->addUniformVariable(VFX_STR("u_ProjTex"), VFX_TYPE_ID_SAMPLER, 1);

        VfxTexture2D *texture;
        kal_wsprintf(fn, "%c:\\test\\test.ktx", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (VFX_WSTR_DYNAMIC(fn)));
        var->setValue(texture);
        setTitle(VFX_WSTR("Projective Texture test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Projective Texture OK?"));
        return -1;
    }

};

VtstTestResultEnum vtst_rt_3d_projective_texture(VfxU32 param)
{
    VTST_START_SCRN(VtstRtProjectiveTexture);
    return VTST_TR_OK;
}



class VtstRtEnvironmentMap : public VtstRtScr
{
// Variable
public:

    // Constructor / Destructor
public:
    VtstRtEnvironmentMap()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar vs[256];
        VfxWChar fs[256];
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, -60, 0), VrtVector3f(0, 0, 0), VrtVector3f(0, 0, 1));
        //camera->setLookAt(VrtVector3f(0, 0, 60), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxLight *light;
        VFX_OBJ_CREATE(light, VfxLight, world);
        light->setTranslation(0, 50, 0);
        light->setRotationX(-VFX_PI / 2);

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);
        kal_wsprintf(vs, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(vs));
        //VfxSphereMesh *mesh;
        //VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (30));
        mesh->setRotationX(-VFX_PI / 3);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(vfxSin(2 * VFX_PI / 3), 0, 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(vfxSin(4 * VFX_PI / 3), 0, 0), vfxCos(4 * VFX_PI / 3)));
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


        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);


        VfxShaderProgram *program;
        kal_wsprintf(vs, "%c:\\test\\reflection\\reflection.vs", SRV_FMGR_PHONE_DRV);
        kal_wsprintf(fs, "%c:\\test\\reflection\\reflection.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass, 
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("u_CubeTex"), VFX_TYPE_ID_SAMPLER, 1);

        VfxTextureCube *texture;
        kal_wsprintf(vs, "%c:\\test\\cube.ktx", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(texture, VfxTextureCube, var, (VFX_WSTR_DYNAMIC(vs)));
        var->setValue(texture);
        setTitle(VFX_WSTR("Environment Map test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Environment Map OK?"));
        return -1;
    }

};

VtstTestResultEnum vtst_rt_3d_environment_map(VfxU32 param)
{
    VTST_START_SCRN(VtstRtEnvironmentMap);
    return VTST_TR_OK;
}



class ParticleSystem : public VfxProceduralMesh
{
    virtual vrt_u32 getVertexArrayCount() const
    {
        return 3;
    }

    virtual vrt_u32 getVertexCount() const
    {
        const vrt_u32 m_vertexCount = 1000;
        return m_vertexCount;
    }

    virtual vrt_u32 getComponentCount(vrt_u32 i) const
    {
        static const vrt_u32 m_componentCount[] = {1, 3, 3};
        return m_componentCount[i];
    }

    virtual vrt_type_id_enum getComponentDataType(vrt_u32 i) const
    {
        static const vrt_type_id_enum m_componentDataType[] =
        {
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT
        };
        return m_componentDataType[i];
    }

    virtual const vrt_char *getAttributeName(vrt_u32 i) const
    {
        const vrt_char *m_attributeName[] =
        {
            "a_lifetime",
            "a_startPosition",
            "a_endPosition"
        };
        return m_attributeName[i];
    }

    virtual vrt_bool isNormalized(vrt_u32 i) const
    {
        return VRT_FALSE;
    }

    virtual const vrt_float *getScaleVector(vrt_u32 i) const
    {
        static const vrt_float m_scale[] = {1.0f, 1.0f, 1.0f, 1.0f};
        return m_scale;
    }

    virtual const vrt_float *getBiasVector(vrt_u32 i) const
    {
        static const vrt_float m_bias[] = {0.0f, 0.0f, 0.0f, 0.0f};
        return m_bias;
    }

    /* index buffer */
    virtual vrt_u32 getIndexBufferCount() const
    {
        return 1;
    }

    virtual VrtPrimitiveType getPrimitiveType(vrt_u32 i) const
    {
        return VRT_PRIMITIVE_POINTS;
    }

    virtual vrt_u32 getIndexCount(vrt_u32 i) const
    {
        return getVertexCount();
    }

    virtual vrt_type_id_enum getIndexDataType(vrt_u32 i) const
    {
        return VRT_TYPE_ID_UNKNOWN;
    }

    virtual void initVertexArrays(void **va_buffers) const
    {
        float *lifeTime = (float *)va_buffers[0];
        float *startPos = (float *)va_buffers[1];
        float *endPos = (float *)va_buffers[2];

        vrt_u32 i;
        for ( i = 0; i < getVertexCount(); i++ )
        {
            // Lifetime of particle
            lifeTime[i] = ( (float)(rand() % 10000) / 10000.0f );

            // End position of particle
            endPos[i * 3 + 0] = ( (float)(rand() % 10000) / 5000.0f ) - 1.0f;
            endPos[i * 3 + 1] = ( (float)(rand() % 10000) / 5000.0f ) - 1.0f;
            endPos[i * 3 + 2] = ( (float)(rand() % 10000) / 5000.0f ) - 1.0f;

            // Start position of particle
            startPos[i * 3 + 0] = ( (float)(rand() % 10000) / 40000.0f ) - 0.125f;
            startPos[i * 3 + 1] = ( (float)(rand() % 10000) / 40000.0f ) - 0.125f;
            startPos[i * 3 + 2] = ( (float)(rand() % 10000) / 40000.0f ) - 0.125f;

        }
    }

    virtual void initIndexBuffers(void **data) const
    {
    }

};

class VtstRtProceduralMesh : public VtstRtScr
{
// Variable
public:

    // Constructor / Destructor
public:
    VtstRtProceduralMesh()
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar vs[256];
        VfxWChar fs[256];
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 1), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        ParticleSystem *ps;
        VFX_OBJ_CREATE(ps, ParticleSystem, world);

        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, ps);
        ps->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        VfxShaderProgram *program;
        kal_wsprintf(vs, "%c:\\test\\ParticleSystem\\particle.vs", SRV_FMGR_PHONE_DRV);
        kal_wsprintf(fs, "%c:\\test\\ParticleSystem\\particle.fs", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(
            program,
            VfxShaderProgram,
            pass,
            (VFX_WSTR_DYNAMIC(vs),
             VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        /* u_time */
        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("u_time"), VFX_TYPE_ID_FLOAT, 1);
        VfxFloatTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
        tl->setTarget(var);
        tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->setDuration(1000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        /* u_color */
        var = uniforms->addUniformVariable(VFX_STR("u_color"), VFX_TYPE_ID_VEC4, 1);
        var->setValue(0.75f, 0.75f, 0.5f, 0.5f);

        /* s_texture */
        var = uniforms->addUniformVariable(VFX_STR("s_texture"), VFX_TYPE_ID_SAMPLER, 1);
        VfxTexture2D *texture;
        kal_wsprintf(vs, "%c:\\test\\ParticleSystem\\smoke.png", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (VFX_WSTR_DYNAMIC(vs)));
        var->setValue(texture);

        VfxCompositingMode *cm;
        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        cm->setDepthTestEnable(VFX_FALSE);

        pass->setCompositingMode(cm);

        VfxBlender *blender;
        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        blender->setBlendFunc(VFX_BLEND_FACTOR_SRC_ALPHA, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA);
        cm->setBlender(blender);

        setTitle(VFX_WSTR("Procedural Mesh test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Procedural Mesh OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_procedural_mesh(VfxU32 param)
{
    VTST_START_SCRN(VtstRtProceduralMesh);
    return VTST_TR_OK;
}



class VtstRtDisposeObject : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;
    VfxMesh *m_mesh;
    
// Constructor / Destructor
public:
    VtstRtDisposeObject() : 
        m_world(NULL)
        m_mesh(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_world, VfxWorld, this);
        setWorld(m_world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, m_world);
        m_world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 70), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VFX_OBJ_CREATE_EX(m_mesh, VfxBoxMesh, m_world, (10));

        setTitle(VFX_WSTR("Test dispose object"));
    }

    virtual int start()
    {
        return 3;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
        case 0:
            confirm(VFX_WSTR("Object Display OK?"));
            break;
        case 1:
            m_world->removeChildNode(m_mesh);
            confirm(VFX_WSTR("Remove From Scene OK?"));
            break;
        case 2:
            VFX_OBJ_CLOSE(m_mesh);
            confirm(VFX_WSTR("Object Close OK?"));
            break;
        }

        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_dispose_object(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDisposeObject);
    return VTST_TR_OK;
}


class VtstRtCloseObject : public VtstRtScr
{
// Variable
public:
    VfxMaterial *m_material;

// Constructor / Destructor
public:
    VtstRtCloseObject() : 
        m_material(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Test close material"));
    }

    virtual int start()
    {
        return 2;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
        case 0:
            VFX_OBJ_CREATE(m_material, VfxMaterial, this);

            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, m_material);
            m_material->setPass(0, pass);

            setMaterial(m_material);
            confirm(VFX_WSTR("Set Material OK?"));
            break;
        case 1:
            VFX_OBJ_CLOSE(m_material);
            confirm(VFX_WSTR("Close Material OK?"));
            break;
        }

        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_close_object(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCloseObject);
    return VTST_TR_OK;
}


class SkinnedMesh : public VfxProceduralSkinnedMesh
{
    static const VfxS32 u_count = 10;
    static const VfxS32 v_count = 20;

    virtual vrt_u32 getVertexArrayCount() const
    {
        return 4;
    }

    virtual vrt_u32 getVertexCount() const
    {
        const vrt_s32 numSlices = v_count;
        const vrt_s32 numParallels = u_count;
        const vrt_s32 numVertices = ( numParallels + 1 ) * ( numSlices + 1 );
        return numVertices;
    }

    virtual vrt_u32 getComponentCount(vrt_u32 i) const
    {
        static const vrt_u32 m_componentCount[] = {3, 3, 4, 4};
        return m_componentCount[i];
    }

    virtual vrt_type_id_enum getComponentDataType(vrt_u32 i) const
    {
        static const vrt_type_id_enum m_componentDataType[] =
        {
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_U16
        };
        return m_componentDataType[i];
    }

    virtual const vrt_char *getAttributeName(vrt_u32 i) const
    {
        const vrt_char *m_attributeName[] =
        {
            "v3d_Position",
            "v3d_Normal",
            "v3d_BoneWeights",
            "v3d_BoneIndices"
        };
        return m_attributeName[i];
    }

    virtual vrt_bool isNormalized(vrt_u32 i) const
    {
        return VRT_FALSE;
    }

    virtual const vrt_float *getScaleVector(vrt_u32 i) const
    {
        static const vrt_float m_scale[] = {1.0f, 1.0f, 1.0f, 1.0f};
        return m_scale;
    }

    virtual const vrt_float *getBiasVector(vrt_u32 i) const
    {
        static const vrt_float m_bias[] = {0.0f, 0.0f, 0.0f, 0.0f};
        return m_bias;
    }

    /* index buffer */
    virtual vrt_u32 getIndexBufferCount() const
    {
        return 1;
    }

    virtual VrtPrimitiveType getPrimitiveType(vrt_u32 i) const
    {
        return VRT_PRIMITIVE_TRIANGLES;
    }

    virtual vrt_u32 getIndexCount(vrt_u32 i) const
    {
        const vrt_s32 numSlices = v_count;
        const vrt_s32 numParallels = u_count;
        const vrt_s32 numIndices = numParallels * numSlices * 6;
        return numIndices;
    }

    virtual vrt_type_id_enum getIndexDataType(vrt_u32 i) const
    {
        return VRT_TYPE_ID_U16;
    }

    virtual void initVertexArrays(void **va_buffers) const
    {
        VfxVector3f *pos = (VfxVector3f *)va_buffers[0];
        VfxVector3f *normal = (VfxVector3f *)va_buffers[1];
        VfxVector4f *weights = (VfxVector4f *)va_buffers[2];
        VfxVector4us *indices = (VfxVector4us *)va_buffers[3];

        const VfxS32 numSlices = v_count;
        const VfxS32 numParallels = u_count;
        const VfxFloat angleStep = -(2.0f * VFX_PI) / ((VfxFloat) numSlices);

        const VfxFloat radius = 0.5f;
        const VfxFloat hight = 4.0f;

        VfxS32 i, j;
        for ( i = 0; i < numParallels + 1; i++ )
        {
            for ( j = 0; j < numSlices + 1; j++ )
            {
                int vertex = ( i * (numSlices + 1) + j );

                normal[vertex].x = vfxSin ( angleStep * (VfxFloat)j );
                normal[vertex].z = vfxCos ( angleStep * (VfxFloat)j );
                normal[vertex].y = 0;

                pos[vertex].x = radius * normal[vertex].x;
                pos[vertex].z = radius * normal[vertex].z;
                pos[vertex].y = hight / numParallels * i;

                indices[vertex].x = 0;
                indices[vertex].y = 1;
                indices[vertex].z = 2;
                indices[vertex].w = 0;

                weights[vertex].x = 1.0f - float(i) / numParallels;
                weights[vertex].y = float(i) / numParallels;
                weights[vertex].z = 0;
                weights[vertex].w = 0;
            }
        }
    }

    virtual void initIndexBuffers(void **data) const
    {
        VfxU16 *indexBuf = (VfxU16 *)data[0];

        const VfxS32 numSlices = v_count;
        const VfxS32 numParallels = u_count;
        VfxS32 i, j;
        for ( i = 0; i < numParallels ; i++ )
        {
            for ( j = 0; j < numSlices; j++ )
            {
                *indexBuf++  = i * ( numSlices + 1 ) + j;
                *indexBuf++ = ( i + 1 ) * ( numSlices + 1 ) + j;
                *indexBuf++ = ( i + 1 ) * ( numSlices + 1 ) + ( j + 1 );

                *indexBuf++ = i * ( numSlices + 1 ) + j;
                *indexBuf++ = ( i + 1 ) * ( numSlices + 1 ) + ( j + 1 );
                *indexBuf++ = i * ( numSlices + 1 ) + ( j + 1 );
            }
        }
    }

};

class VtstRtSkinnedMesh : public VtstRtScr
{
// Variable
public:

    // Constructor / Destructor
public:

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxGroup *character;
        VFX_OBJ_CREATE(character, VfxGroup, world);
        character->setTranslation(0, -2, 0);

        /* create skeleton */
        VfxGroup *root;
        VFX_OBJ_CREATE(root, VfxGroup, character);
        VfxBone *bone_0;
        VFX_OBJ_CREATE(bone_0, VfxBone, root);
        bone_0->setTranslation(0, 0, 0);
        VfxBone *bone_1;
        VFX_OBJ_CREATE(bone_1, VfxBone, bone_0);
        bone_1->setTranslation(0, 2, 0);
        VfxBone *bone_2;
        VFX_OBJ_CREATE(bone_2, VfxBone, bone_1);
        bone_2->setTranslation(0, 2, 0);
        VfxSphereMesh *widget;
        VFX_OBJ_CREATE_EX(widget, VfxSphereMesh, bone_2, (0.5f));

        /* create skinned mesh */
        SkinnedMesh *mesh;
        VFX_OBJ_CREATE(mesh, SkinnedMesh, character);
        mesh->setSkeleton(bone_0);
        mesh->setTranslation(2, 0, 0);

        /* setup skeleton animation */
        VfxQuaternionfTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxQuaternionfTimeline, bone_1);
        qtl->setTarget(bone_1);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setFromValue(VfxQuaternionf(0,0,0,1));
        qtl->setToValue(VfxQuaternionf(0,0,vfxSin(VFX_PI / 4),vfxCos(VFX_PI / 4)));
        qtl->setDuration(2000);
        qtl->setAutoReversed(VFX_TRUE);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();
        setTitle(VFX_WSTR("Test Skinned Mesh"));

    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Skinned Mesh OK?"));
        return -1;
    }

};

VtstTestResultEnum vtst_rt_3d_skinned_mesh(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSkinnedMesh);
    return VTST_TR_OK;
}




class VtstRtAutoDepthBuffer: public VtstRtScr
{
// Variable
public:
    // Constructor / Destructor
    VfxFrame *m_frame;
public:
    VtstRtAutoDepthBuffer()
    : m_frame(NULL)
    {
    }

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(100, 100, 200, 200);
        m_frame->sendToBack();
        m_frame->setOpacity(0.5f);

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setRect(0, 0, 100, 100);

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, frame);
        frame->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            1,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Auto Depth Buffer OK?"));
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

VtstTestResultEnum vtst_rt_3d_auto_depth_buffer(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAutoDepthBuffer);
    return VTST_TR_OK;
}


class VtstRtWrold : public VtstRtScr
{
// Variable
public:

    // Override
protected:
    virtual void onInit()
    {
        VfxWChar fn[256];
        VtstRtScr::onInit();

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setRect(getSize().width/4, getSize().height/4, getSize().width/2, getSize().height/2);

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, frame);
        frame->setWorld(world);

        VfxImage2D *bg;
        kal_wsprintf(fn, "%c:\\test\\test.ktx", SRV_FMGR_PHONE_DRV);
        VFX_OBJ_CREATE_EX(bg, VfxImage2D, world, (VFX_WSTR_DYNAMIC(fn)));
        world->setBackground(bg);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            1,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("3D World OK?"));
        return -1;
    }

};

VtstTestResultEnum vtst_rt_3d_world(VfxU32 param)
{
    VTST_START_SCRN(VtstRtWrold);
    return VTST_TR_OK;
}


#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
#include "mdi_include.h"
#endif
extern void vrt_set_video_layer_ext(vrt_sys_video_layer_index_enum index, gdi_handle layer, vrt_s32 order, vrt_bool is_video);
#ifdef __cplusplus
}
#endif

class VtstVideoFrame : public VfxFrame
{
// Variable
public:
    VfxU8 *m_buffer;
    VfxSize m_bufferSize;

// Constructor / Destructor
public:
    // Default constructor
    VtstVideoFrame()
    : m_buffer(NULL)
    {
    }

// Override
protected:
    virtual void onDeinit()
    {
        unPrepare();
        VfxFrame::onDeinit();
    }

// Method
public:

    inline void setBufferSize(VfxSize size)
    {
        m_bufferSize = size;
    }

    inline const VfxSize getBufferSize()
    {
        return m_bufferSize;
    }

    inline VfxBool isReady()
    {
        return getLayerHandle() != 0;
    }

    VfxBool prepare()
    {
        gdi_handle frame_layer = getLayerHandle();
        if (!frame_layer)
        {
            VfxU32 bufferSize = m_bufferSize.width * m_bufferSize.height * 2;
            VFX_FREE_MEM(m_buffer);
            VFX_ALLOC_MEM_EX(m_buffer, bufferSize, VFX_SYS_MEM_ALLOC_FLAG_FB, this);

            if (m_buffer == NULL)
            {
                return VFX_FALSE;
            }

            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->mustShowNextFrame();

            gdi_layer_create_cf_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                0,
                0,
                m_bufferSize.width,
                m_bufferSize.height,
                &frame_layer,
                m_buffer,
                bufferSize);

            gdi_layer_set_hw_update_layer(frame_layer, KAL_TRUE);
            vrt_set_video_layer_ext(VRT_SYS_VIDEO_LAYER_INDEX_0, frame_layer, 0, VRT_TRUE);

            gdi_handle layer[4];
            VfxS32 i;
            gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);
            for (i = 0; i < 4; i++)
            {
                if (layer[i] && !(((gdi_layer_struct*)layer[i]) -> flag & 1))
                {
                    layer[i] = GDI_NULL_HANDLE;
                }
            }
            layer[0] = frame_layer;
            gdi_layer_set_blt_layer(layer[0], layer[1], layer[2], layer[3]);

            setLayerHandle(frame_layer);
        }

        return VFX_TRUE;
    }

    void unPrepare()
    {
        gdi_handle frame_layer = getLayerHandle();
        if (frame_layer)
        {
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->mustShowNextFrame();
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();

            setLayerHandle(0);

            gdi_handle layer[4];
            VfxS32 i;
            gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);
            for (i = 0; i < 4; i++)
            {
                if (layer[i] && !(((gdi_layer_struct*)layer[i]) -> flag & 1))
                {
                    layer[i] = GDI_NULL_HANDLE;
                }

                if (layer[i] == frame_layer)
                {
                    layer[i] = GDI_NULL_HANDLE;
                }
            }
            gdi_layer_set_blt_layer(layer[0], layer[1], layer[2], layer[3]);

            vrt_set_video_layer_ext(VRT_SYS_VIDEO_LAYER_INDEX_0, GDI_LAYER_EMPTY_HANDLE, 0, VRT_TRUE);

            gdi_layer_free(frame_layer);
        }

        VFX_FREE_MEM(m_buffer);
    }
};

class VtstRtFrameBuffer : public VtstRtScr
{
// Variable
public:
    VfxS32 m_level;
    VfxBool m_stack;
    VfxFrame *m_video;
    VfxFrame *m_panel;
    VfxTextFrame *m_text;
    VcpButton *m_button;
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    VtstRtFrameBuffer()
    : m_level(0)
    , m_stack(VFX_FALSE)
    , m_video(NULL)
    , m_panel(NULL)
    , m_text(NULL)
    , m_button(NULL)
    , m_frame(NULL)
    {
    }

// Override
protected:

    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Frame Buffer test"));
        setBorder(VFX_COLOR_YELLOW, 3);

        /* control panel */
        VfxS32 l = getSize().width < getSize().height ? getSize().width : getSize().height;
        VfxS32 w = l / 6;
        VfxS32 h = l / 10;

        VFX_OBJ_CREATE(m_panel, VfxFrame, this);
        m_panel->setRect(w, h, w * 4, h * 5);

        VFX_OBJ_CREATE(m_text, VfxTextFrame, m_panel);
        m_text->setRect(0, h * 0, w, h);
        m_text->setAutoFontSize(VFX_TRUE);

        VcpSlider *slider;
        VFX_OBJ_CREATE(slider, VcpSlider, m_panel);
        slider->setRect(w, h * 0, w * 3, h);
        slider->setMinValue(0);
        slider->setMaxValue(7);
        slider->setTotalDiscreteStepsForPen(7);
        slider->setCurrentValue(VfxFloat(m_level));
        slider->m_signalUserChangedValue.connect(this, &VtstRtFrameBuffer::onLevelChange);

        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, m_panel);
        button->setRect(0, h * 1, w * 4, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Rotate Screen"));
        button->m_signalClicked.connect(this, &VtstRtFrameBuffer::onRotateScreen);

        VFX_OBJ_CREATE(button, VcpButton, m_panel);
        button->setRect(0, h * 2, w * 4, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Buffer Format"));
        button->m_signalClicked.connect(this, &VtstRtFrameBuffer::onBufferFormat);

        VFX_OBJ_CREATE(button, VcpButton, m_panel);
        button->setRect(0, h * 3, w * 4, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->m_signalClicked.connect(this, &VtstRtFrameBuffer::onStackChange);
        m_button = button;

        VFX_OBJ_CREATE(button, VcpButton, m_panel);
        button->setRect(0, h * 4, w * 4, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Hide Panel"));
        button->m_signalClicked.connect(this, &VtstRtFrameBuffer::onHidePanel);

        reinitFrameStack();
        updateText();
        updateButton();
    }

    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }

    virtual void onRotate(const VfxScreenRotateParam &param)
    {
        VtstRtScr::onRotate(param);

#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
        if (VFX_OBJ_DYNAMIC_CAST(m_video, VappVideoPlayerComponent))
        {
            m_video->setSize(getSize());
        }
#endif

        VfxS32 i;
        VfxFrame *frame = m_frame;
        if (m_stack)
        {
            for (i = 0; i < m_level; ++i)
            {
                frame->setSize(getSize());
                frame = frame->getFirstChildFrame();
            }
        }
        else
        {
            for (i = 0; i < m_level; ++i)
            {
                frame->setSize(getSize());
                VfxFrame *child = frame->getFirstChildFrame();
                child->setSize(getSize());
                frame = frame->getNextFrame();
            }
        }
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Frame Buffer OK?"));
        return -1;
    }

    void reinitFrameStack()
    {
        if (m_frame)
        {
            VfxFrame *frame = m_frame;
            do {
                VfxFrame *next = frame->getNextFrame();
                VFX_OBJ_CLOSE(frame);
                frame = next;
            } while (frame != m_panel);

            m_frame = NULL;
        }

        if (m_stack)
        {
            VFX_OBJ_CREATE(m_frame, VfxFrame, this);

            VfxS32 i;
            VfxFrame *frame = m_frame;
            for (i = 0; i < m_level; ++i)
            {
                frame->setSize(getSize());
                frame->setBgColor(VFX_COLOR_BLACK);
                frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
                frame->setOpacity(0.75f);
                frame->setAutoAnimate(VFX_TRUE);

                VfxFrame *parent = frame;
                VFX_OBJ_CREATE(frame, VfxFrame, parent);
            }

            VfxS32 l = getSize().width < getSize().height ? getSize().width : getSize().height;
            VfxS32 w = l / 6;
            VfxS32 h = l / 10;

            frame->setRect(w * 1, h * 7, 10, 10);
            frame->setBgColor(VFX_COLOR_WHITE);
            //frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

            /* timeline */
            VfxS32Timeline *tl;
            VFX_OBJ_CREATE(tl, VfxS32Timeline, frame);
            tl->setTarget(frame);
            tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
            tl->setFromValue(w * 1);
            tl->setToValue(w * 5 - 10);
            tl->setDuration(1000);
            tl->setAutoReversed(VFX_TRUE);
            tl->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
            tl->start();
        }
        else
        {
            VfxS32 i;
            for (i = 0; i < m_level; ++i)
            {
                VfxFrame *frame;
                VFX_OBJ_CREATE(frame, VfxFrame, this);
                frame->setSize(getSize());
                frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
                frame->setAutoAnimate(VFX_TRUE);

                VfxFrame *child;
                VFX_OBJ_CREATE(child, VfxFrame, frame);
                child->setSize(getSize());
                child->setBgColor(VFX_COLOR_BLACK);
                child->setOpacity(0.1f);
                child->setAutoAnimate(VFX_TRUE);

                if (i == 0)
                {
                    m_frame = frame;

                    /* timeline */
                    VfxFloatTimeline *tl;
                    VFX_OBJ_CREATE(tl, VfxFloatTimeline, m_frame);
                    tl->setTarget(m_frame);
                    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
                    tl->setFromValue(0.0f);
                    tl->setToValue(1.0f);
                    tl->setDuration(1000);
                    tl->setAutoReversed(VFX_TRUE);
                    tl->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
                    tl->start();
                }
            }
        }

        m_panel->bringToFront();
    }

    void updateText()
    {
        VfxWString string;
        string.format("%d +%d%s",
            m_level,
            VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_NORMAL ? 0 : 1,
            m_video ? "*" : "");
        m_text->setString(string);
    }

    void updateButton()
    {
        m_button->setText(m_stack ? VFX_WSTR("To Frame Overlays") : VFX_WSTR("To Frame FBOs"));
    }

    void onLevelChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_level = int(newval);

        reinitFrameStack();
        updateText();
    }

    void onRotateScreen(VfxObject *sender, VfxId id)
    {
        VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        toplevel->setScreenRotateType(toplevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_NORMAL ?
            VFX_SCR_ROTATE_TYPE_LANDSCAPE :
            VFX_SCR_ROTATE_TYPE_NORMAL);

        updateText();
    }

    void onBufferFormat(VfxObject *sender, VfxId id)
    {
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
        if (VFX_OBJ_DYNAMIC_CAST(m_video, VappVideoPlayerComponent))
        {
            VFX_OBJ_CLOSE(m_video);
        }
        else if (m_video)
        {
            VFX_OBJ_CLOSE(m_video);
            VappVideoPlayerPlayOption option;
            option.configAsWallpaperVideo();
            VappVideoPlayerComponent *video;
            VFX_OBJ_CREATE_EX(video, VappVideoPlayerComponent, this, (option));
            video->sendToBack();
            video->setSize(getSize());
            video->setBgColor(VFX_COLOR_TRANSPARENT);
            video->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
            video->m_signalFileOpened.connect(this, &VtstRtFrameBuffer::onVideoOpened);
            video->openResId(VDO_ID_SYS_MP4_02);
            m_video = video;
        }
#else
        if (m_video)
        {
            VFX_OBJ_CLOSE(m_video);
        }
#endif
        else
        {
            VFX_DEV_ASSERT(m_video == NULL);
            VtstVideoFrame *video;
            VFX_OBJ_CREATE(video, VtstVideoFrame, this);
            video->sendToBack();
            video->setBufferSize(VfxSize(10, 10));
            video->prepare();
            m_video = video;
        }

        updateText();
    }

#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
    void onVideoOpened(VappVideoPlayerComponent *sender, MDI_RESULT result)
    {
        if (sender && sender == m_video && MDI_RES_VDOPLY_SUCCEED == result)
        {
            sender->setVideoScreenMode(VS_STRETCH);
            sender->play();
        }
    }
#endif

    void onStackChange(VfxObject *sender, VfxId id)
    {
        m_stack = !m_stack;

        reinitFrameStack();
        updateButton();
    }

    void onHidePanel(VfxObject *sender, VfxId id)
    {
        m_panel->setHidden(VFX_TRUE);
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            m_panel->setHidden(VFX_FALSE);
        }

        return VtstRtScr::onPenInput(event);
    }
};


VtstTestResultEnum vtst_rt_3d_frame_buffer(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameBuffer);
    return VTST_TR_OK;
}


class BlueDraw : public VfxOwnerDraw
{
protected:
    virtual vrt_bool isUsingGLAPI() const { return VFX_TRUE; }

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
    {
        // Set the viewport
        glViewport( dstRect.origin.x, dstRect.origin.y, dstRect.size.width, dstRect.size.height );

        // Clear the color buffer
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear ( GL_COLOR_BUFFER_BIT );        
    }
};

class VtstRtDisableColorKey : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;

    // Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setBgColor(VFX_COLOR_WHITE);
        
        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setCacheMode(VFX_CACHE_MODE_FORCE);
        m_frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
        m_frame->setHints(VFX_FRAME_HINTS_DISABLE_COLOR_KEY);
        m_frame->setBgColor(VFX_COLOR_YELLOW);
        m_frame->setRect(
            getSize().width/4,
            getSize().height/4,
            getSize().width/2,
            getSize().height/2);

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        BlueDraw *ownerDraw;
        VFX_OBJ_CREATE(ownerDraw, BlueDraw, this);
        frame->setOwnerDraw(ownerDraw);
        frame->setRect(
            m_frame->getSize().width/4,
            m_frame->getSize().height/4,
            m_frame->getSize().width/2,
            m_frame->getSize().height/2);

        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, this);
        button->setRect(0,0, 200, 50);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Enable/Disable ColorKey"));
        button->m_signalClicked.connect(this, &VtstRtDisableColorKey::onSwitchColorKey);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Disable Color Key OK?"));
        return -1;
    }

    void onSwitchColorKey(VfxObject* sender, VfxId Id)
    {
        VfxFrameHintsEnum hints = m_frame->getHints();
        ((int &)hints) ^= VFX_FRAME_HINTS_DISABLE_COLOR_KEY;
        m_frame->setHints(hints);
    }

};

VtstTestResultEnum vtst_rt_3d_disable_color_key(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDisableColorKey);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

