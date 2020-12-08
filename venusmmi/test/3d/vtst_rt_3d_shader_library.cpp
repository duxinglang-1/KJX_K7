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
 *  vtst_rt_3d_shader_library.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for shader library
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
#include "FileMgrSrvGprot.h"

class VtstRtColorShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtColorShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Color Texture test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Color Texture OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);                
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_color.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_color_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtColorShader);
    return VTST_TR_FAIL;
}


class VtstRtPhongShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtPhongShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Phong Texture test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Phong Texture OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);                
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_phong.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_phong_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtPhongShader);
    return VTST_TR_FAIL;
}


class VtstRtLightMapShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtLightMapShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Light Map test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Light Map OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_lightmap.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_lightmap_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtLightMapShader);
    return VTST_TR_FAIL;
}


class VtstRtAmbOccMapShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtAmbOccMapShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Amb. Occ. Map test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Amb. Occ. Map OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_amboccmap.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_amboccmap_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtAmbOccMapShader);
    return VTST_TR_FAIL;
}


class VtstRtSpecularMapShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtSpecularMapShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Specular Map test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Specular Map OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_specularmap.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_specularmap_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSpecularMapShader);
    return VTST_TR_FAIL;
}


class VtstRtBumpMapShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtBumpMapShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Bump Map test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Bump Map OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_bumpmap.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_bumpmap_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtBumpMapShader);
    return VTST_TR_FAIL;
}


class VtstRtFresnelShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtFresnelShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Reflect/Refract test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Reflect/Refract OK?"));

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
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_frensel.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);

                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_fresnel_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFresnelShader);
    return VTST_TR_FAIL;
}


class VtstRtGlassShader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtGlassShader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Window Glass test"));
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
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
                confirm(VFX_WSTR("Load Window Glass OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(-75, -60, 100),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxMesh *mesh;
                VfxMaterial *material;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                VfxWChar fn[256];
                kal_wsprintf(fn, "%c:\\test\\vtst_cylinder001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_glass.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(0, material);
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                kal_wsprintf(fn, "%c:\\test\\vtst_frensel.mtl", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMaterial(material, VFX_WSTR_DYNAMIC(fn));
                mesh->setMaterial(1, material);
                break;
            }
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_3d_glass_shader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtGlassShader);
    return VTST_TR_FAIL;
}


#endif // __AFX_RT_TEST__


