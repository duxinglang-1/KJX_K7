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
 *  vtst_rt_3d_mesh_loader.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d mesh loading
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
#include "vfx_skinned_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_compositing_mode.h"
#include "FileMgrSrvGprot.h"

class VtstRtMeshLoader : public VtstRtScr
{
// Variable
public:
    VfxWorld *m_world;

// Constructor / Destructor
public:
    VtstRtMeshLoader()
    : m_world(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("3D Mesh loading test"));
    }

    virtual int start()
    {
        return 4;
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
                confirm(VFX_WSTR("Load 3D Mesh OK?"));

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

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_teapot001.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));

                break;
            }
        case 1:
            {
                confirm(VFX_WSTR("Load Sub-mesh OK?"));

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

                VfxMesh *mesh;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\vtst_col_logo.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                mesh->rotateX(-VRT_PI / 2);

                VfxMaterial *material;
                VFX_OBJ_CREATE(material, VfxMaterial, mesh);
                mesh->setMaterial(1, material);

                VfxPass *pass;
                VFX_OBJ_CREATE(pass, VfxPass, material);
                material->setPass(0, pass);

                VfxCompositingMode *mode;
                VFX_OBJ_CREATE(mode, VfxCompositingMode, pass);
                pass->setCompositingMode(mode);

                mode->setColorWriteMask(0xFFFF00FF);

                break;
            }
        case 2:
            {
                confirm(VFX_WSTR("Load Skinned-mesh OK?"));

                /* World */
                VFX_OBJ_CREATE(m_world, VfxWorld, this);
                this->setWorld(m_world);

                /* Camera */
                VfxCamera *camera;
                VFX_OBJ_CREATE(camera, VfxCamera, m_world);
                camera->setPerspective(VRT_PI_2,
                    (VfxFloat)main_screen_size.width / (VfxFloat)main_screen_size.height, 1.0f, 1000.0f);
                camera->setLookAt(
                    VrtVector3f(120, 60, 40),
                    VrtVector3f(0, 0, 0),
                    VrtVector3f(0, 0, 1));
                m_world->setActiveCamera(camera);

                VfxSkinnedMesh *mesh;

                // TODO: From Resource

                /* File */
                VFX_OBJ_CREATE(mesh, VfxSkinnedMesh, m_world);
                kal_wsprintf(fn, "%c:\\test\\sheep_run\\sheep_body-mesh-skin.msh", SRV_FMGR_PHONE_DRV);
                VfxAssetLoader::loadSkinnedMesh(mesh, VFX_WSTR_DYNAMIC(fn));
                break;
            }
        case 3:
            {
                confirm(VFX_WSTR("Load Morphing-mesh OK?"));
                break;
            }
        }
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_mesh_loader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMeshLoader);
    return VTST_TR_FAIL;
}


#endif // __AFX_RT_TEST__


