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
 *  vtst_rt_3d_animation_loader.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for timeline and animation loading
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
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "FileMgrSrvGprot.h"


class VtstRtAnimationLoader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtAnimationLoader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Animation loading test"));
    }

    virtual int start()
    {
        return 6;
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

        switch (idx)
        {
        case 0:
            {
                confirm(VFX_WSTR("Load Timeline OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(200, 0, -50),
                    VrtVector3f(0, 0, -50),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxBoxMesh *box;
                VfxSphereMesh *sphere;
                VfxKeyframeTimeline *tl;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, m_world, (30));

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, box);

                kal_wsprintf(fn, "%c:\\test\\vtst_anim_Omni001-node-translation.tl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadKeyframe(tl, VFX_WSTR_DYNAMIC(fn));
                tl->setTarget(box);

                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, m_world, (30));
                box->translate(0, 0, -50);

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, box);
                kal_wsprintf(fn, "%c:\\test\\vtst_anim_Teapot000-node-rz.tl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadKeyframe(tl, VFX_WSTR_DYNAMIC(fn));
                tl->setTarget(box);

                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                VFX_OBJ_CREATE_EX(sphere, VfxSphereMesh, m_world, (60));
                sphere->translate(0, 0, -150);

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, sphere);
                kal_wsprintf(fn, "%c:\\test\\vtst_anim_Teapot002-node-scale.tl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadKeyframe(tl, VFX_WSTR_DYNAMIC(fn));
                tl->setTarget(sphere);

                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("Load Shader Uniform Timeline OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(0, 0, 6),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 1, 0));
                m_world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxMaterial *mtl;
                VfxPass *pass;
                VfxShaderUniforms *uniforms;
                VfxShaderVariable *var;
                VfxKeyframeTimeline *tl;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxSphereMesh, m_world);
                mesh->translate(0, 2, 0);

                VFX_OBJ_CREATE(mtl, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_basic_phong.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(mtl, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, mtl);
                pass = mtl->getPass(0);

                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, mtl);
                pass->addShaderUniforms(uniforms);
                var = uniforms->addUniformVariable(VFX_STR("uAmbient"), VFX_TYPE_ID_FLOAT, 1);

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, uniforms);
                kal_wsprintf(fn, "%c:\\test\\vtst_anim_uAmbient.tl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadKeyframe(tl, VFX_WSTR_DYNAMIC(fn));
                tl->setTarget(var);

                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                VFX_OBJ_CREATE(mesh, VfxSphereMesh, m_world);
                mesh->translate(0, -2, 0);

                VFX_OBJ_CREATE(mtl, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_basic_phong.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(mtl, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, mtl);
                pass = mtl->getPass(0);

                VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, mtl);
                pass->addShaderUniforms(uniforms);
                var = uniforms->addUniformVariable(VFX_STR("uDiffuse"), VFX_TYPE_ID_VEC4, 1);

                VFX_OBJ_CREATE(tl, VfxKeyframeTimeline, uniforms);
                kal_wsprintf(fn, "%c:\\test\\vtst_anim_uDiffuse.tl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadKeyframe(tl, VFX_WSTR_DYNAMIC(fn));
                tl->setTarget(var);

                tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                tl->start();

                break;
            }
        case 2:
            {
                VfxS32 dimension = main_screen_size.width < main_screen_size.height ?
                    main_screen_size.width : main_screen_size.height;
                this->setSize(dimension, dimension);

                confirm(VFX_WSTR("Load Hierarchical Animation OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                VfxAnimation *anim;
                VFX_OBJ_CREATE(anim, VfxAnimation, m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\vtst_anim.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadScene(m_world, VFX_WSTR_DYNAMIC(fn));
                kal_wsprintf(fn, "%c:\\test\\vtst_anim.ani", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadAnimation(anim, m_world, VFX_WSTR_DYNAMIC(fn));
                anim->start();

                break;
            }
        case 3:
            {
                VfxS32 dimension = main_screen_size.width < main_screen_size.height ?
                    main_screen_size.width : main_screen_size.height;
                this->setSize(dimension, dimension);

                confirm(VFX_WSTR("Load Animation on Modified Scene OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                // TODO: From Resource

                /* File */
                kal_wsprintf(fn, "%c:\\test\\vtst_anim.scn", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadSceneBegin(m_world, VFX_WSTR_DYNAMIC(fn));
                VfxObject3D *obj = VfxAssetLoader::findObjByName(VFX_STR("Teapot002-node"));
                VfxMesh *teapot2 = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);
                obj = VfxAssetLoader::findObjByName(VFX_STR("Teapot003-node"));
                VfxMesh *teapot3 = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);
                VfxAssetLoader::loadSceneEnd();

                // modify scene graph and lookup table (on loadScene root)

                // 1. remove node
                VFX_OBJ_CLOSE(teapot2);

                // 2. remove lookup entry
                m_world->setTargetLookup(VFX_STR("Teapot000-node"), NULL);

                // 3. replace node
                VfxGroup *parent = teapot3->getParentNode();
                VFX_OBJ_CLOSE(teapot3);
                VfxBoxMesh *box;
                VFX_OBJ_CREATE_EX(box, VfxBoxMesh, parent, (15));
                m_world->setTargetLookup(VFX_STR("Teapot003-node"), box);

                VfxAnimation *anim;
                VFX_OBJ_CREATE(anim, VfxAnimation, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_anim.ani", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadAnimation(anim, m_world, VFX_WSTR_DYNAMIC(fn));
                anim->start();

                break;
            }
        case 4:
            {
                confirm(VFX_WSTR("Load Skeleton Animation OK?"));

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
                VfxAnimation *anim;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(sheep, VfxGroup, m_world);
                kal_wsprintf(fn, "%c:\\test\\sheep_run\\sheep_run.chr", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadScene(sheep, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(anim, VfxAnimation, sheep);
                kal_wsprintf(fn, "%c:\\test\\sheep_run\\sheep_run.ani", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadAnimation(anim, sheep, VFX_WSTR_DYNAMIC(fn));
                anim->start();

                break;
            }
        case 5:
            {
                confirm(VFX_WSTR("Load Morphing Animation OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                // TODO: From Resource

                /* File */

                break;
            }
        }
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_animation_loader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAnimationLoader);
    return VTST_TR_FAIL;
}

#endif // __AFX_RT_TEST__


