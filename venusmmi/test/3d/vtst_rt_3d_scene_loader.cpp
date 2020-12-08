/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vtst_rt_3d_scene_loader.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for scene graph loading
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
#include "vfx_asset_loader.h"
#include "vfx_world.h"
#include "vfx_mesh.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_animation.h"
#include "FileMgrSrvGprot.h"

class VtstRtSceneLoader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtSceneLoader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Scene loading test"));
    }

    virtual int start()
    {
        return 5;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VfxWChar fn[256];
        if (m_world)
        {
            this->setWorld(NULL);
            VFX_OBJ_CLOSE(m_world);
        }

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 dimension = main_screen_size.width < main_screen_size.height ?
            main_screen_size.width : main_screen_size.height;
        this->setSize(dimension, dimension);

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("Load 3D Scene OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\vtst_teapots.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadScene(m_world, VFX_WSTR_DYNAMIC(fn));

                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("Find Obj by Name OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\vtst_teapots.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadSceneBegin(m_world, VFX_WSTR_DYNAMIC(fn));
                VfxObject3D *obj = VfxAssetLoader::findObjByName(VFX_STR("Cylinder001-node"));
                VfxMesh *cylinder = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);
                obj = VfxAssetLoader::findObjByName(VFX_STR("Spot001-node"));
                VfxLight *spot = VFX_OBJ_DYNAMIC_CAST(obj, VfxLight);
                VfxAssetLoader::loadSceneEnd();

                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *tl;

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, cylinder, (4, VFX_TYPE_ID_QUAT));
                kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
                kfs->setKeyframe(1, 2000,  &VfxQuaternionf(VfxVector3f(0, 0, -0.7071f), 0.7071f));
                kfs->setKeyframe(2, 4000, &VfxQuaternionf(VfxVector3f(0, -0.7071f, 0), 0.7071f));
                kfs->setKeyframe(3, 6000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, cylinder);
                tl->setTarget(cylinder);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(6000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                const VfxVector3f &position = spot->getTranslation();

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, spot, (6, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f(position));
                kfs->setKeyframe(1, 1000, &VfxVector3f(position.x, position.y, position.z + 100));
                kfs->setKeyframe(2, 2000, &VfxVector3f(position.x + 200, position.y, position.z + 100));
                kfs->setKeyframe(3, 3000, &VfxVector3f(position.x + 200, position.y - 100, position.z + 100));
                kfs->setKeyframe(4, 4000, &VfxVector3f(position.x, position.y + 100, position.z + 100));
                kfs->setKeyframe(5, 5000, &VfxVector3f(position));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, spot);
                tl->setTarget(spot);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(5000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                break;
            }
        case 2:
            {
                confirm(VFX_WSTR("Rebind Shader Variable OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\vtst_teapots.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadSceneBegin(m_world, VFX_WSTR_DYNAMIC(fn), VFX_TRUE, VFX_TRUE);
                VfxObject3D *obj = VfxAssetLoader::findObjByName(VFX_STR("Teapot001-node"));
                VFX_OBJ_CLOSE(obj);
                obj = VfxAssetLoader::findObjByName(VFX_STR("Cylinder001-node"));
                VFX_OBJ_CLOSE(obj);
                obj = VfxAssetLoader::findObjByName(VFX_STR("Spot001-node"));
                VfxLight *spot = VFX_OBJ_DYNAMIC_CAST(obj, VfxLight);
                VfxAssetLoader::loadSceneEnd();

                VfxGroup *knot;
                VFX_OBJ_CREATE(knot, VfxGroup, m_world);

                kal_wsprintf(fn, "%c:\\test\\vtst_knot.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadScene(knot, VFX_WSTR_DYNAMIC(fn));
                knot->translate(0, 0, 30);

                VfxKeyframeSequence *kfs;
                VfxKeyframeTimeline *tl;

                const VfxVector3f &position = spot->getTranslation();

                VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, spot, (6, VFX_TYPE_ID_VEC3));
                kfs->setKeyframe(0, 0,    &VfxVector3f(position));
                kfs->setKeyframe(1, 1000, &VfxVector3f(position.x, position.y, position.z + 100));
                kfs->setKeyframe(2, 2000, &VfxVector3f(position.x + 200, position.y, position.z + 100));
                kfs->setKeyframe(3, 3000, &VfxVector3f(position.x + 200, position.y - 100, position.z + 100));
                kfs->setKeyframe(4, 4000, &VfxVector3f(position.x, position.y + 100, position.z + 100));
                kfs->setKeyframe(5, 5000, &VfxVector3f(position));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, spot);
                tl->setTarget(spot);
                tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
                tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
                tl->setKeyframeSequence(kfs);
                tl->setDuration(5000);
                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                break;
            }
        case 3:
            {
                confirm(VFX_WSTR("Share material instance OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\vtst_anim.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadSceneBegin(m_world, VFX_WSTR_DYNAMIC(fn));
                VfxObject3D *obj = VfxAssetLoader::findObjByName(VFX_STR("Teapot002-node"));
                VfxMesh *teapot2 = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);
                VfxAssetLoader::loadSceneEnd();

                VfxMaterial *material = teapot2->getMaterial(0);
                VfxPass *pass = material->getPass(0);
                VfxShaderVariable *shininess = pass->getUniformVariable(VFX_STR("uShininess"));
                shininess->setValue(6.0f);

                break;
            }
        case 4:
            {
                confirm(VFX_WSTR("Load Character OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2, 1.0f, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(15, 30, 5),
                    VrtVector3f(18, 24, 2),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxGroup *sheep;
                VFX_OBJ_CREATE(sheep, VfxGroup, m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\sheep_run\\sheep_run.chr", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadScene(sheep, VFX_WSTR_DYNAMIC(fn));

                break;
            }
        }
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_scene_loader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSceneLoader);
    return VTST_TR_FAIL;
}

#endif // __AFX_RT_TEST__


