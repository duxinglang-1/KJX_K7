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
 *  vtst_rt_3d_material_loader.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for material loading
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
#include "FileMgrSrvGprot.h"

class VtstRtMaterialLoader : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtMaterialLoader()
    : m_frame(NULL)
    , m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Material loading test"));
    }

    virtual int start()
    {
        return 9;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VfxWChar fn[256];
        if (m_frame)
        {
            VFX_OBJ_CLOSE(m_frame);
        }
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
                confirm(VFX_WSTR("Load Shader Program OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(3, 2, 5),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 1, 0));
                m_world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxSphereMesh, m_world);
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_base.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("Load Frame Material OK?"));

                VfxS32 w = main_screen_size.width / 3;
                VfxS32 h = main_screen_size.height / 3;

                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(m_frame, VfxFrame, this);
                m_frame->setPos(VfxPoint(w, h));
                m_frame->setSize(VfxSize(w, h));
                m_frame->setBgColor(VFX_COLOR_OLIVE);
                VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
                kal_wsprintf(fn, "%c:\\test\\vtst_frame.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                m_frame->setMaterial(material);

                break;
            }
        case 2:
            {
                confirm(VFX_WSTR("Load Multi-Pass OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(3, 2, 5),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 1, 0));
                m_world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxSphereMesh, m_world);
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_twopass.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 3:
            {
                confirm(VFX_WSTR("Load Shared Shader OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(3, 2, 5),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 1, 0));
                m_world->setActiveCamera(camera);

                VfxSphereMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxSphereMesh, m_world);
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_share.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 4:
            {
                confirm(VFX_WSTR("Load Variables OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(-60, -60, 60),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_basic_phong.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 5:
            {
                confirm(VFX_WSTR("Load Render States OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(-60, -60, 60),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));                
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_states.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 6:
            {
                confirm(VFX_WSTR("Load Texture Sampler OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(-60, -60, 60),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_color.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 7:
            {
                confirm(VFX_WSTR("Load Cube Texture OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(-60, -60, 60),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_frensel.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        case 8:
            {
                confirm(VFX_WSTR("Load Render Target OK?"));
                break;
            }
        }
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_material_loader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMaterialLoader);
    return VTST_TR_FAIL;
}


#endif // __AFX_RT_TEST__



