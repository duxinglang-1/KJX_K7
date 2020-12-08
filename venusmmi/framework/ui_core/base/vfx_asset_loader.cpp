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
 *  vfx_asset_loader.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *
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
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_asset_loader.h"
#include "vfx_stream.h"
#include "vfx_asset_src.h"

// For vfx_sys_mem_get_global_allocator()
#include "vfx_sys_mem_config.h"

#include "vfx_bounding_volume.h"
#include "vfx_mesh.h"
#include "vfx_skinned_mesh.h"
#include "vfx_material.h"
#include "vfx_polygon_mode.h"
#include "vfx_blender.h"
#include "vfx_stencil.h"
#include "vfx_compositing_mode.h"
#include "vfx_shader.h"
#include "vfx_texture.h"
#include "vfx_shader_uniforms.h"
#include "vfx_render_buffer.h"
#include "vfx_render_target.h"
#include "vfx_pass.h"
#include "vfx_node.h"
#include "vfx_group.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_animation.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "fs_gprot.h"
#include "FileMgrSrvGProt.h"
#ifdef __cplusplus
} /* extern "C"*/
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define V3DA_FAIL_HANDLE(__cond__, __fallback__)    \
    do {                                            \
        if (!(__cond__)) {                          \
            VFX_LOG(                                \
                VFX_ERROR,                          \
                VFX_ASSETLOADER_DATA_ASSERT_ERROR,  \
                __LINE__, #__cond__);               \
            VFX_DEV_ASSERT(VFX_FALSE);              \
            __fallback__;                           \
        }                                           \
    } while (0)

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


/***************************************************************************** 
 * Class VfxAssetLoader
 *****************************************************************************/

VfxBool VfxAssetLoader::loadMesh(VfxMesh *mesh, const VfxResId resId)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMH", SA_start);
#endif
    VfxAssetIndexType index = loadMeshImp(mesh, resId);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMH", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadMesh(VfxMesh *mesh, const VfxWString &filename)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMH", SA_start);
#endif
    VfxAssetIndexType index = loadMeshImp(mesh, filename);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMH", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadSkinnedMesh(VfxSkinnedMesh *mesh, const VfxResId resid)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSM", SA_start);
#endif
    VfxAssetIndexType index = loadMeshImp((VfxMesh *)mesh, resid);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSM", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadSkinnedMesh(VfxSkinnedMesh *mesh, const VfxWString &filename)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSM", SA_start);
#endif
    VfxAssetIndexType index = loadMeshImp((VfxMesh *)mesh, filename);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSM", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadMaterial(VfxMaterial *mtl, const VfxResId resId)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMT", SA_start);
#endif
    VfxAssetIndexType index = loadMaterialImp(mtl, resId);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMT", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadMaterial(VfxMaterial *mtl, const VfxWString &filename)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMT", SA_start);
#endif
    VfxAssetIndexType index = loadMaterialImp(mtl, filename);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMT", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadScene(
    VfxGroup *root, const VfxResId resId, VfxBool createTargetLookup, VfxBool createBindingLookup)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_start);
#endif
    VfxAssetIndexType index = loadSceneBeginImp(root, resId, createTargetLookup, createBindingLookup);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_stop);
#endif
    loadSceneEndImp();
    return index != 0;
}


VfxBool VfxAssetLoader::loadScene(
    VfxGroup *root, const VfxWString &filename, VfxBool createTargetLookup, VfxBool createBindingLookup)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_start);
#endif
    VfxAssetIndexType index = loadSceneBeginImp(root, filename, createTargetLookup, createBindingLookup);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_stop);
#endif
    loadSceneEndImp();
    return index != 0;
}


VfxBool VfxAssetLoader::loadKeyframe(VfxKeyframeTimeline *kft, const VfxResId resId)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LKF", SA_start);
#endif
    VfxAssetIndexType index = loadKeyframeImp(kft, resId);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LKF", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadKeyframe(VfxKeyframeTimeline *kft, const VfxWString &filename)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LKF", SA_start);
#endif
    VfxAssetIndexType index = loadKeyframeImp(kft, filename);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LKF", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadAnimation(VfxAnimation *anim, VfxNode *node, const VfxResId resId)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LAN", SA_start);
#endif
    VfxAssetIndexType index = loadAnimationImp(anim, node, resId);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LAN", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadAnimation(VfxAnimation *anim, VfxNode *node, const VfxWString &filename)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LAN", SA_start);
#endif
    VfxAssetIndexType index = loadAnimationImp(anim, node, filename);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LAN", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadSceneBegin(
    VfxGroup *root, const VfxResId resId, VfxBool createTargetLookup, VfxBool createBindingLookup)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_start);
#endif
    VfxAssetIndexType index = loadSceneBeginImp(root, resId, createTargetLookup, createBindingLookup);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_stop);
#endif
    return index != 0;
}


VfxBool VfxAssetLoader::loadSceneBegin(
    VfxGroup *root, const VfxWString &filename, VfxBool createTargetLookup, VfxBool createBindingLookup)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_start);
#endif
    VfxAssetIndexType index = loadSceneBeginImp(root, filename, createTargetLookup, createBindingLookup);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSB", SA_stop);
#endif
    return index != 0;
}


void VfxAssetLoader::loadSceneEnd()
{
    return loadSceneEndImp();
}


VfxObject3D *VfxAssetLoader::findObjByName(const VfxString &name)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LFO", SA_start);
#endif

    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_FIND_OBJ_BY_NAME);
    VfxObject3D *obj = NULL;
    if (s_curSceneLoader)
    {
        obj = s_curSceneLoader->findObjByNameImp(name);
    }
    else
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_NOT_LOADING_SCENE);
        VFX_DEV_ASSERT(VFX_FALSE);
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LFO", SA_stop);
#endif
    return obj;
}


VfxAssetIndexType VfxAssetLoader::loadMeshImp(VfxMesh *mesh, const VfxResId resId)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_MESH);
    if (mesh == NULL || resId == NULL)
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxU32 size;
    const VfxU8 *start = vfx_sys_res_get_binary(resId, &size);
    if (!start || !size)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_GET_RESOURCE_FAIL, resId);
        return 0;
    }

    VfxMemIstream is;
    is.open(start, start + size);

    VfxAssetLoader loader(is, resId);

    VfxAssetIndexType index = loader.loadFromStream(mesh);
    is.close();

    mesh->setResId(resId);
    return index;
}


VfxAssetIndexType VfxAssetLoader::loadMeshImp(VfxMesh *mesh, const VfxWString &filename)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_MESH);
    if (mesh == NULL || filename.isEmpty())
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxFileIstream is;

    if (!is.open(filename.getBuf()))
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_OPEN_FILE_FAIL);
        return 0;
    }

    VfxAssetLoader loader(is, filename);

    VfxAssetIndexType index = loader.loadFromStream(mesh);
    is.close();

    mesh->setPath(filename);
    return index;
}


VfxAssetIndexType VfxAssetLoader::loadMeshImp(VfxMesh *mesh, const VfxAssetSrc &source)
{
#ifdef __MAUI_SOFTWARE_LA__
    if (VFX_OBJ_DYNAMIC_CAST(mesh, VfxSkinnedMesh))
    {
        SLA_CustomLogging("LSM", SA_start);
    }
    else
    {
        SLA_CustomLogging("LMH", SA_start);
    }
#endif

    VfxAssetIndexType index = 0;
    switch (source.getType())
    {
    case VFX_ASSET_SRC_TYPE_RES_ID:
        index = loadMeshImp(mesh, source.getResId());
        break;
    case VFX_ASSET_SRC_TYPE_PATH:
        index = loadMeshImp(mesh, source.getPath());
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
        VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_MESH);
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        break;
    }

#ifdef __MAUI_SOFTWARE_LA__
    if (VFX_OBJ_DYNAMIC_CAST(mesh, VfxSkinnedMesh))
    {
        SLA_CustomLogging("LSM", SA_stop);
    }
    else
    {
        SLA_CustomLogging("LMH", SA_stop);
    }
#endif
    return index;
}


VfxAssetIndexType VfxAssetLoader::loadMaterialImp(VfxMaterial *mtl, const VfxResId resId)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_MATERIAL);
    if (mtl == NULL || resId == NULL)
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxU32 size;
    const VfxU8 *start = vfx_sys_res_get_binary(resId, &size);
    if (!start || !size)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_GET_RESOURCE_FAIL, resId);
        return 0;
    }

    VfxMemIstream is;
    is.open(start, start + size);

    VfxAssetLoader loader(is, resId);

    VfxAssetIndexType index = loader.loadFromStream(mtl);
    is.close();

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadMaterialImp(VfxMaterial *mtl, const VfxWString &filename)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_MATERIAL);
    if (mtl == NULL || filename.isEmpty())
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxFileIstream is;

    if (!is.open(filename.getBuf()))
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_OPEN_FILE_FAIL);
        return 0;
    }

    VfxAssetLoader loader(is, filename);

    VfxAssetIndexType index = loader.loadFromStream(mtl);
    is.close();

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadMaterialImp(VfxMaterial *mtl, const VfxAssetSrc &source)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMT", SA_start);
#endif

    VfxAssetIndexType index = 0;
    switch (source.getType())
    {
    case VFX_ASSET_SRC_TYPE_RES_ID:
        index = loadMaterialImp(mtl, source.getResId());
        break;
    case VFX_ASSET_SRC_TYPE_PATH:
        index = loadMaterialImp(mtl, source.getPath());
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
        VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_MATERIAL);
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        break;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LMT", SA_stop);
#endif
    return index;
}


VfxAssetIndexType VfxAssetLoader::loadKeyframeImp(VfxKeyframeTimeline *kft, const VfxResId resId)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_KEYFRAME);
    if (kft == NULL || resId == NULL)
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxU32 size;
    const VfxU8 *start = vfx_sys_res_get_binary(resId, &size);
    if (!start || !size)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_GET_RESOURCE_FAIL, resId);
        return 0;
    }

    VfxMemIstream is;
    is.open(start, start + size);

    VfxAssetLoader loader(is, resId);

    VfxAssetIndexType index = loader.loadFromStream(kft);
    is.close();

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadKeyframeImp(VfxKeyframeTimeline *kft, const VfxWString &filename)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_KEYFRAME);
    if (kft == NULL || filename.isEmpty())
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxFileIstream is;

    if (!is.open(filename.getBuf()))
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_OPEN_FILE_FAIL);
        return 0;
    }

    VfxAssetLoader loader(is, filename);

    VfxAssetIndexType index = loader.loadFromStream(kft);
    is.close();

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadAnimationImp(VfxAnimation *anim, VfxNode *node, const VfxResId resId)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_ANIMATION);
    if (anim == NULL || resId == NULL)
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxU32 size;
    const VfxU8 *start = vfx_sys_res_get_binary(resId, &size);
    if (!start || !size)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_GET_RESOURCE_FAIL, resId);
        return 0;
    }

    VfxMemIstream is;
    is.open(start, start + size);

    VfxAssetLoader loader(is, resId);

    VfxAssetIndexType index = loader.loadFromStream(anim, node);
    is.close();

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadAnimationImp(VfxAnimation *anim, VfxNode *node, const VfxWString &filename)
{
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_ANIMATION);
    if (anim == NULL || filename.isEmpty())
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxFileIstream is;

    if (!is.open(filename.getBuf()))
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_OPEN_FILE_FAIL);
        return 0;
    }

    VfxAssetLoader loader(is, filename);

    VfxAssetIndexType index = loader.loadFromStream(anim, node);
    is.close();

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadSceneBeginImp(
    VfxGroup *root, const VfxResId resId, VfxBool createTargetLookup, VfxBool createBindingLookup)
{
    if (s_curSceneLoader)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_LOAD_SCENE_REENTRY);
        return 0;
    }

    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_SCENE_BEGIN);
    if (root == NULL || resId == NULL)
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxU32 size;
    const VfxU8 *start = vfx_sys_res_get_binary(resId, &size);
    if (!start || !size)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_GET_RESOURCE_FAIL, resId);
        return 0;
    }

    VfxMemIstream is;
    is.open(start, start + size);

    VFX_SYS_NEW_EX(s_curSceneLoader, VfxAssetLoader, (is, resId));

    createBindingLookup = (createBindingLookup && VFX_OBJ_DYNAMIC_CAST(root, VfxWorld) != NULL);
    VfxAssetIndexType index = s_curSceneLoader->loadSceneFromStream(root, createBindingLookup);
    is.close();

    if (index == 0)
    {
        loadSceneEndImp();
    }
    else if (createTargetLookup)
    {
        s_curSceneLoader->createAnimTargetMap(root);
    }

    return index;
}


VfxAssetIndexType VfxAssetLoader::loadSceneBeginImp(
    VfxGroup *root, const VfxWString &filename, VfxBool createTargetLookup, VfxBool createBindingLookup)
{
    if (s_curSceneLoader)
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_LOAD_SCENE_REENTRY);
        return 0;
    }

    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_SCENE_BEGIN);
    if (root == NULL || filename.isEmpty())
    {
        // Do nothing
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_INVALID_PARAMETER);
        return 0;
    }

    VfxFileIstream is;

    if (!is.open(filename.getBuf()))
    {
        VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_OPEN_FILE_FAIL);
        return 0;
    }

    VFX_SYS_NEW_EX(s_curSceneLoader, VfxAssetLoader, (is, filename));

    createBindingLookup = (createBindingLookup && VFX_OBJ_DYNAMIC_CAST(root, VfxWorld) != NULL);
    VfxAssetIndexType index = s_curSceneLoader->loadSceneFromStream(root, createBindingLookup);
    is.close();

    if (index == 0)
    {
        loadSceneEndImp();
    }
    else if (createTargetLookup)
    {
        s_curSceneLoader->createAnimTargetMap(root);
    }

    return index;
}


void VfxAssetLoader::loadSceneEndImp()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSE", SA_start);
#endif
    VFX_SYS_DELETE(s_curSceneLoader);
    VFX_LOG(VFX_INFO, VFX_ASSETLOADER_LOAD_SCENE_END);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("LSE", SA_stop);
#endif
}


VfxAssetLoader *VfxAssetLoader::s_curSceneLoader = NULL;

VfxAssetLoader::VfxAssetLoader(VfxFileIstream &is, const VfxWString &filename) :
    m_is(is),
    m_nameTableHead(NULL),
    m_type(VFX_ASSET_LOADER_SRC_TYPE_PATH),
    m_mem(NULL)
{
    const WCHAR *filepath = NULL;
    VfxS32 namepos = -1;
    if (!filename.isNull())
    {
        filepath = srv_fmgr_path_skip_leading_space_const((const WCHAR *)filename.getBuf());
        namepos = srv_fmgr_path_get_filename_pos(filepath);
    }
    if (namepos > 0)
    {
        VfxWChar *folderBuf = m_folder.lockBuf(namepos + 1);
        memcpy(folderBuf, filepath, sizeof(VfxWChar) * namepos);
        folderBuf[namepos] = 0;
        m_folder.unlockBuf();
    }
    else
    {
        VfxWChar *folderBuf = m_folder.lockBuf(FS_MAX_PATH / sizeof(VfxWChar));
        int ret = FS_GetCurrentDir((WCHAR *)folderBuf, FS_MAX_PATH / sizeof(VfxWChar) - 1);
        VFX_DEV_ASSERT(ret == FS_NO_ERROR);
        m_folder.unlockBuf();
    }

    m_objMap.init(vfx_sys_mem_get_global_allocator());
}


VfxAssetLoader::VfxAssetLoader(VfxMemIstream &is, const VfxResId &resId) :
    m_is(is),
    m_nameTableHead(NULL),
    m_type(VFX_ASSET_LOADER_SRC_TYPE_RES_ID),
    m_folder(VFX_WSTR_NULL)
{
    VfxU32 size;
    m_mem = vfx_sys_res_get_binary(resId, &size);

    m_objMap.init(vfx_sys_mem_get_global_allocator());
}

VfxAssetLoader::~VfxAssetLoader()
{
    clearNameTable();
    clearAssetMap();
}


void VfxAssetLoader::readString(VfxString &str)
{
    vrt_file_string fs = {0};
    m_is.readValue(fs.length);

    if (m_type == VFX_ASSET_LOADER_SRC_TYPE_PATH)
    {
        VfxChar *buf = str.lockBuf(fs.length);
        m_is.read((VfxU8 *)buf, fs.length);
        str.unlockBuf();
    }
    else if (m_type == VFX_ASSET_LOADER_SRC_TYPE_RES_ID)
    {
        VfxU32 pos = m_is.tell();
        str = VFX_STR_CONST((const VfxChar *)(m_mem + pos));
        m_is.ignore(fs.length);
    }    
}

void VfxAssetLoader::readWString(VfxWString &wstr)
{
    vrt_file_wstring fws = {0};
    m_is.readValue(fws.size);

    if (m_type == VFX_ASSET_LOADER_SRC_TYPE_PATH)
    {
        VfxWChar *wbuf = wstr.lockBuf(fws.size / sizeof(VfxWChar));
        m_is.read((VfxU8 *)wbuf, fws.size);
        wstr.unlockBuf();
    }
    else if (m_type == VFX_ASSET_LOADER_SRC_TYPE_RES_ID)
    {
        VfxU32 pos = m_is.tell();
        wstr = VFX_WSTR_CONST((const VfxWChar *)(m_mem + pos));
        m_is.ignore(fws.size);
    }
}

void VfxAssetLoader::readReference(VfxAssetSrc &ref, VfxAssetFileDataStruct *data)
{
    vrt_obj_ref_type fr = {0};
    m_is.readValue(fr.ref_type);

    switch (fr.ref_type)
    {
    case VRT_REF_TYPE_RES_ID:
        {
            m_is.readValue(fr.id);
            V3DA_FAIL_HANDLE(fr.id != VRT_REF_VALUE_RES_ID_NEED_RELOC, return);
            ref.setResId(fr.id);
        }
        break;
    case VRT_REF_TYPE_WSTRING:
        {
            VFX_DEV_ASSERT(m_type == VFX_ASSET_LOADER_SRC_TYPE_PATH);
            VfxWString wstr;
            readWString(wstr);
            normalizePath(wstr);
            ref.setPath(wstr);
        }
        break;
    case VRT_REF_TYPE_CUSTOM_DATA:
        {
            m_is.readValue(fr.data.size);

            if (data != NULL)
            {
                if (m_type == VFX_ASSET_LOADER_SRC_TYPE_PATH)
                {
                    VFX_SYS_ALLOC_MEM(fr.data.data, fr.data.size);
                    m_is.read(fr.data.data, fr.data.size);
                }
                else if (m_type == VFX_ASSET_LOADER_SRC_TYPE_RES_ID)
                {
                    VfxU32 pos = m_is.tell();
                    fr.data.data = (VfxU8 *)(m_mem + pos);
                    m_is.ignore(fr.data.size);
                }
                *data = fr.data;
            }
            else
            {
                m_is.ignore(fr.data.size);
            }
        }
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}

void VfxAssetLoader::normalizePath(VfxWString &path)
{
    VfxWString normpath;
    VfxU32 len = path.getLength();
    if (len >= 3 && path[1] == ':' && (path[2] == '\\' || path[2] == '/'))
    {
        // is absolute
        normpath = path;
    }
    else
    {
        // should be relative
        normpath = m_folder;
        normpath += path;
    }

    len = normpath.getLength();
    VfxWChar *pbuf = normpath.lockBuf(len + 1);

    VFX_DEV_ASSERT(len >= 3 && pbuf[1] == ':' && (pbuf[2] == '\\' || pbuf[2] == '/'));

    VfxArray< VfxU32 > tokens;
    tokens.init(vfx_sys_mem_get_global_allocator());

    pbuf[2] = '\\';
    tokens.pushBack(3);
    for (VfxU32 i = 3; i < len; ++i)
    {
        if (pbuf[i] == '\\' || pbuf[i] == '/')
        {
            pbuf[i] = 0;
            tokens.pushBack(i + 1);
        }
    }

    VfxU32 i = 0;
    while (i < tokens.size())
    {
        if (vfx_sys_wcscmp(&pbuf[tokens[i]], (const VfxWChar *)L".") == 0 || vfx_sys_wcscmp(&pbuf[tokens[i]], (const VfxWChar *)L"") == 0)
        {
            tokens.erase(i);
        }
        else if (vfx_sys_wcscmp(&pbuf[tokens[i]], (const VfxWChar *)L"..") == 0)
        {
            if (i > 0 && vfx_sys_wcscmp(&pbuf[tokens[i - 1]], (const VfxWChar *)L"..") != 0)
            {
                tokens.erase(i);
                tokens.erase(i - 1);
                --i;
            }
            else if (i == 0)
            {
                tokens.erase(i);
            }
            else
            {
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }

    VfxU32 pend = 3;
    if (tokens.size() > 0)
    {
        VfxU32 tlen = vfx_sys_wcslen(&pbuf[tokens[0]]);
        memmove(&pbuf[pend], &pbuf[tokens[0]], sizeof(VfxWChar) * tlen);
        pend += tlen;
        for (VfxU32 i = 1; i < tokens.size(); ++i)
        {
            pbuf[pend] = '\\';
            pend += 1;
            tlen = vfx_sys_wcslen(&pbuf[tokens[i]]);
            memmove(&pbuf[pend], &pbuf[tokens[i]], sizeof(VfxWChar) * tlen);
            pend += tlen;
        }
    }
    pbuf[pend] = 0;

    normpath.unlockBuf();
    if (path != normpath)
    {
        path = normpath;
    }
}


void VfxAssetLoader::addNameTableEntry(const VfxString &name, VfxObject3D *objPtr)
{
    V3DA_FAIL_HANDLE(!name.isNull(), return);
    V3DA_FAIL_HANDLE(objPtr != NULL, return);

    NameTableEntry *entry;
    VFX_SYS_NEW(entry, NameTableEntry);
    entry->name     = name;
    entry->objPtr   = objPtr;

    // add to table
    entry->next     = m_nameTableHead;
    m_nameTableHead = entry;
}

void VfxAssetLoader::clearNameTable()
{
    NameTableEntry *entry = m_nameTableHead;
    while (entry != NULL)
    {
        NameTableEntry *next = entry->next;

        VFX_SYS_DELETE(entry);

        entry = next;
    }

    m_nameTableHead = NULL;
}

void VfxAssetLoader::createAnimTargetMap(VfxNode *node)
{
    node->clearAnimTargetMap();

    NameTableEntry *entry;
    for (entry = m_nameTableHead; entry != NULL; entry = entry->next)
    {
        node->setTargetLookup(entry->name, entry->objPtr.get());
    }
}

VfxObject3D *VfxAssetLoader::findObjByNameImp(const VfxString &name) const
{
    NameTableEntry *entry;
    for (entry = m_nameTableHead; entry != NULL; entry = entry->next)
    {
        if (entry->name == name)
        {
            return entry->objPtr.get();
        }
    }

    VFX_LOG(VFX_WARNING, VFX_ASSETLOADER_OBJECT_NOT_FOUND, name.getBuf());
    return NULL;
}


void VfxAssetLoader::addAssetMapEntry(const VfxAssetIndexType &index, VfxObject *objPtr)
{
    V3DA_FAIL_HANDLE(index != 0, return);
    V3DA_FAIL_HANDLE(objPtr != NULL, return);
    V3DA_FAIL_HANDLE(index > m_objMap.size(), return);

    AssetMapEntry init;
    init.objPtr = NULL;
    init.refCnt = 0;
    m_objMap.resize(index, init);

    // Add to map
    AssetMapEntry &entry = m_objMap[index - 1];
    entry.objPtr = objPtr;
}

void VfxAssetLoader::clearAssetMap()
{
    VfxU32 i;
    for (i = 0; i < m_objMap.size(); ++i)
    {
        AssetMapEntry &entry = m_objMap[i];
        // Never been used
        if (entry.refCnt == 0)
        {
            VFX_OBJ_CLOSE(entry.objPtr);
        }
    }

    m_objMap.clear();
}

VfxObject *VfxAssetLoader::getAssetMapObject(const VfxAssetIndexType &index, const VfxClassInfo *type, VfxS32 &shared)
{
    if (index == 0 || index > m_objMap.size())
    {
        return NULL;
    }

    AssetMapEntry &entry = m_objMap[index - 1];
    VfxObject *objPtr = entry.objPtr->isKindOf(type)? entry.objPtr.get() : NULL;
    if (objPtr == NULL)
    {
        return NULL;
    }

    shared = entry.refCnt ++;
    return objPtr;
}

#define VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(_funcName, _className)                      \
inline _className *VfxAssetLoader::_funcName(const VfxAssetIndexType &index)                \
{                                                                                           \
    VfxS32 shared = 0;                                                                      \
    _className *obj = VFX_STATIC_CAST(                                                      \
        getAssetMapObject(index, VFX_OBJ_CLASS_INFO(_className), shared), _className *);    \
    V3DA_FAIL_HANDLE(obj, return NULL);                                                     \
    return obj;                                                                             \
}

#define VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP(_funcName, _className)                    \
inline _className *VfxAssetLoader::_funcName(const VfxAssetIndexType &index)                \
{                                                                                           \
    VfxS32 shared = 0;                                                                      \
    _className *obj = VFX_STATIC_CAST(                                                      \
        getAssetMapObject(index, VFX_OBJ_CLASS_INFO(_className), shared), _className *);    \
    V3DA_FAIL_HANDLE(obj && !shared, return NULL);                                          \
    return obj;                                                                             \
}

VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getObject3DFromMap, VfxObject3D);
VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getProgramFromMap, VfxShaderProgram);
VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP(getTextureFromMap, VfxTexture);
VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP(getUniformsFromMap, VfxShaderUniforms);
VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP(getRenderTargetFromMap, VfxRenderTarget);
VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP(getPassFromMap, VfxPass);
VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getCameraFromMap, VfxCamera);
VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getNodeFromMap, VfxNode);
VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getGroupFromMap, VfxGroup);
VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getBoneFromMap, VfxBone);
VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP(getSkinnedMeshFromMap, VfxSkinnedMesh);
VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP(getTimelineFromMap, VfxBaseTimeline);

#undef VFX_IMPLEMENT_GET_SHARED_ASSET_FROM_MAP
#undef VFX_IMPLEMENT_GET_UNSHARED_ASSET_FROM_MAP


VfxAssetIndexType VfxAssetLoader::loadFromStream(VfxObject *obj, VfxNode *ref)
{
    V3DA_FAIL_HANDLE(obj != NULL, return 0);

    // file header
    vrt_file_header header = {0};
    m_is.readValue(header.totalsize);

    // file objects
    VfxAssetIndexType target_id = 0;
    VfxU32 cur_pos = m_is.tell();
    while (cur_pos < header.totalsize)
    {
        vrt_file_object object = {0};
        m_is.readValue(object.object_type);
        m_is.readValue(object.id);
        m_is.readValue(object.length);
        V3DA_FAIL_HANDLE(object.object_type < VRT_OBJ_TYPE_END_OF_ENUM, return 0);
        V3DA_FAIL_HANDLE(object.id != 0, return 0);

        VfxU32 end_pos = cur_pos + object.length;

        switch (object.object_type)
        {
        case VRT_OBJ_TYPE_VERTEXARRAY:
        case VRT_OBJ_TYPE_INDEXBUFFER:
        case VRT_OBJ_TYPE_VERTEXBUFFER:
            // Ignore mesh data
            //m_is.ignore(object.length - sizeof_vrt_file_object_hdr);
            break;

        case VRT_OBJ_TYPE_MESH:
            //VFX_DEV_ASSERT(VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh));
            if (parseMesh(VFX_STATIC_CAST(obj, VfxMesh *)))
            {
                VFX_DEV_ASSERT(target_id == 0);
                target_id = object.id;
            }
            return target_id;
            //break;

        case VRT_OBJ_TYPE_SKINNED:
            //VFX_DEV_ASSERT(VFX_OBJ_DYNAMIC_CAST(obj, VfxSkinnedMesh));
            if (parseSkinnedMesh(VFX_STATIC_CAST(obj, VfxSkinnedMesh *)))
            {
                VFX_DEV_ASSERT(target_id == 0);
                target_id = object.id;
            }
            return target_id;
            //break;

        case VRT_OBJ_TYPE_RENDERTARGET:
            addAssetMapEntry(object.id, createRenderTarget(obj));
            break;
        case VRT_OBJ_TYPE_PROGRAM:
            addAssetMapEntry(object.id, createShaderProgram(obj));
            break;
        case VRT_OBJ_TYPE_TEXTURE:
            addAssetMapEntry(object.id, createTexture(obj));
            break;
        case VRT_OBJ_TYPE_UNIFORMS:
            addAssetMapEntry(object.id, createShaderUniforms(obj));
            break;
        case VRT_OBJ_TYPE_PASS:
            addAssetMapEntry(object.id, createPass(obj));
            break;
        case VRT_OBJ_TYPE_MATERIAL:
            //VFX_DEV_ASSERT(VFX_OBJ_DYNAMIC_CAST(obj, VfxMaterial));
            if (parseMaterial(VFX_STATIC_CAST(obj, VfxMaterial *)))
            {
                VFX_DEV_ASSERT(target_id == 0);
                target_id = object.id;
            }
            return target_id;
            //break;

        case VRT_OBJ_TYPE_KEYFRAME:
            {
                VfxKeyframeTimeline *timeline = VFX_OBJ_DYNAMIC_CAST(obj, VfxKeyframeTimeline);
                if (timeline)
                {
                    if (parseTimeline(VFX_STATIC_CAST(obj, VfxKeyframeTimeline *)))
                    {
                        VFX_DEV_ASSERT(target_id == 0);
                        target_id = object.id;
                    }
                    return target_id;
                }
                else
                {
                    VFX_OBJ_CREATE(timeline, VfxKeyframeTimeline, obj);
                    if (parseTimeline(timeline))
                    {
                        addAssetMapEntry(object.id, timeline);
                    }
                    else
                    {
                        VFX_OBJ_CLOSE(timeline);
                    }
                }
            }
            break;
        case VRT_OBJ_TYPE_ANIMATION:
            //VFX_DEV_ASSERT(VFX_OBJ_DYNAMIC_CAST(obj, VfxAnimation));
            if (parseAnimation(VFX_STATIC_CAST(obj, VfxAnimation *), ref))
            {
                VFX_DEV_ASSERT(target_id == 0);
                target_id = object.id;
            }
            return target_id;
            //break;

        default:
            //VFX_DEV_ASSERT(VFX_FALSE);
            break;
        }

        cur_pos = m_is.tell();
        V3DA_FAIL_HANDLE(end_pos >= cur_pos, return 0);
        if (end_pos > cur_pos)
        {
            m_is.ignore(end_pos - cur_pos);
            cur_pos = m_is.tell();
            V3DA_FAIL_HANDLE(end_pos == cur_pos, return 0);
        }
    }

    // Should not reach here
    VFX_DEV_ASSERT(VFX_FALSE);
    return target_id;
}

VfxAssetIndexType VfxAssetLoader::loadSceneFromStream(VfxGroup *root, VfxBool createBindingLookup)
{
    V3DA_FAIL_HANDLE(root != NULL, return 0);

    // file header
    vrt_file_header header = {0};
    m_is.readValue(header.totalsize);

    // root object
    vrt_file_object rootobj = {0};
    m_is.readValue(rootobj.object_type);
    m_is.readValue(rootobj.id);
    m_is.readValue(rootobj.length);
    V3DA_FAIL_HANDLE(rootobj.object_type == VRT_OBJ_TYPE_GROUP || rootobj.object_type == VRT_OBJ_TYPE_WORLD, return 0);
    V3DA_FAIL_HANDLE(rootobj.id != 0, return 0);

    // root node
    if (!parseAndCreateNode((VfxNode **)&root, NULL))
    {
        return 0;
    }
    vrt_obj_node::vrt_fmt_group fg = {0};
    m_is.readValue(fg.child_count);

    addAssetMapEntry(rootobj.id, root);

    // file objects
    VfxU32 cur_pos = m_is.tell();
    while (cur_pos < header.totalsize)
    {
        vrt_file_object object = {0};
        m_is.readValue(object.object_type);
        m_is.readValue(object.id);
        m_is.readValue(object.length);
        V3DA_FAIL_HANDLE(object.object_type < VRT_OBJ_TYPE_END_OF_ENUM, return 0);
        V3DA_FAIL_HANDLE(object.id != 0, return 0);

        VfxU32 end_pos = cur_pos + object.length;

        switch (object.object_type)
        {
        case VRT_OBJ_TYPE_WORLD:
            // World in world
            V3DA_FAIL_HANDLE(VFX_FALSE, return 0);
            break;

        case VRT_OBJ_TYPE_GROUP:
            addAssetMapEntry(object.id, createGroupNode(VFX_OBJ_CLASS_INFO(VfxGroup)));
            break;
        case VRT_OBJ_TYPE_BONE:
            addAssetMapEntry(object.id, createGroupNode(VFX_OBJ_CLASS_INFO(VfxBone)));
            break;
        case VRT_OBJ_TYPE_CAMERA:
            addAssetMapEntry(object.id, createCameraNode());
            break;
        case VRT_OBJ_TYPE_LIGHT:
            addAssetMapEntry(object.id, createLightNode());
            break;
        case VRT_OBJ_TYPE_MESHNODE:
            addAssetMapEntry(object.id, createMeshNode(root, VFX_OBJ_CLASS_INFO(VfxMesh)));
            break;
        case VRT_OBJ_TYPE_SKINNEDNODE:
            addAssetMapEntry(object.id, createMeshNode(root, VFX_OBJ_CLASS_INFO(VfxSkinnedMesh)));
            break;
        case VRT_OBJ_TYPE_BINDINGS:
            createShaderBindings(root, createBindingLookup);    // unlikely be referenced
            break;
        case VRT_OBJ_TYPE_SCENEINFO:
            if (!parseSceneInfo(root))
            {
                return 0;
            }
            //VFX_DEV_ASSERT(m_is.tell() == header.totalsize);
            //VFX_DEV_ASSERT(root->getNodeCount() == fg.child_count);
            return rootobj.id;
            //break;

        default:
            //VFX_DEV_ASSERT(VFX_FALSE);
            break;
        }

        cur_pos = m_is.tell();
        V3DA_FAIL_HANDLE(end_pos >= cur_pos, return 0);
        if (end_pos > cur_pos)
        {
            m_is.ignore(end_pos - cur_pos);
            cur_pos = m_is.tell();
            V3DA_FAIL_HANDLE(end_pos == cur_pos, return 0);
        }
    }

    // Should not reach here
    VFX_DEV_ASSERT(VFX_FALSE);
    return 0;
}


VfxBool VfxAssetLoader::parseMesh(VfxMesh *mesh)
{
    vrt_obj_mesh om = {0};
    m_is.readValue(om.vb_id);
    m_is.readValue(om.sm_count);

    mesh->setSubMeshCount(om.sm_count);

    m_is.ignore(sizeof(vrt_obj_index_type) * om.sm_count);

    // bounding volume
    m_is.readValue(om.volume_center);
    m_is.readValue(om.volume_radius2);
    m_is.readValue(om.volume_box);

    mesh->setBoundingVolume(VfxBoundingVolume(om.volume_center, om.volume_radius2, om.volume_box));

    return VFX_TRUE;
}

VfxBool VfxAssetLoader::parseSkinnedMesh(VfxSkinnedMesh *mesh)
{
    if (!parseMesh(mesh))
        return VFX_FALSE;

    vrt_obj_mesh::vrt_fmt_skinned_mesh fsm = {0};
    m_is.readValue(fsm.jnt_count);

    if (fsm.jnt_count)
    {
        VrtMatrix4f skeletonOff;
        m_is.readValue(skeletonOff);
        mesh->setSkeletonOffsetTransform(skeletonOff);

        //m_is.ignore(sizeof(VrtMatrix4f) * (fsm.jnt_count - 1));
    }
    else
    {
        //m_is.ignore(sizeof(VrtMatrix4f) * fsm.jnt_count);
    }

    return VFX_TRUE;
}

VfxBool VfxAssetLoader::parseMaterial(VfxMaterial *material)
{
    vrt_obj_material om = {0};
    m_is.readValue(om.pass_count);

    material->setPassCount(om.pass_count);

    // passes
    VfxU32 i;
    for (i = 0; i < om.pass_count; ++i)
    {
        vrt_obj_index_type pid = 0;
        m_is.readValue(pid);

        // pass by object index
        VfxPass *pass = getPassFromMap(pid);
        VFX_DEV_ASSERT(pass);

        material->setPass(i, pass);
    }

    return VFX_TRUE;
}

VfxBool VfxAssetLoader::parseSceneInfo(VfxGroup *root)
{
    vrt_obj_scene_info osi = {0};
    m_is.readValue(osi.ac_id);
    m_is.readValue(osi.name_count);
    VfxAssetSrc bg_ref;
    readReference(bg_ref);

    VfxWorld *world = VFX_OBJ_DYNAMIC_CAST(root, VfxWorld);
    if (world)
    {
        // active camera by object index
        if (osi.ac_id)
        {
            VfxCamera *camera = getCameraFromMap(osi.ac_id);
            VFX_DEV_ASSERT(camera);

            world->setActiveCamera(camera);
        }

        // background by reference
        if (!bg_ref.isNull())
        {
            VfxImage2D *bg = NULL;
            switch (bg_ref.getType())
            {
            case VFX_ASSET_SRC_TYPE_RES_ID: VFX_OBJ_CREATE_EX(bg, VfxImage2D, world, (bg_ref.getResId()));  break;
            case VFX_ASSET_SRC_TYPE_PATH:   VFX_OBJ_CREATE_EX(bg, VfxImage2D, world, (bg_ref.getPath()));   break;
            default:                        VFX_DEV_ASSERT(VFX_FALSE);
            }

            world->setBackground(bg);
        }
    }

    // names
    VfxU32 i;
    for (i = 0; i < osi.name_count; ++i)
    {
        vrt_obj_scene_info::vrt_fmt_object_table fot = {0};
        VfxString object_name;
        readString(object_name);
        m_is.readValue(fot.object_id);
        VFX_DEV_ASSERT(fot.object_id != 0);

        // object by object index
        VfxObject3D *object = getObject3DFromMap(fot.object_id);
        VFX_DEV_ASSERT(object);

        addNameTableEntry(object_name, object);
    }

    vrt_obj_scene_info::vrt_fmt_extra fex = {0};
    m_is.readValue(fex.ske_count);

    for (i = 0; i < fex.ske_count; ++i)
    {
        vrt_obj_scene_info::vrt_fmt_extra::vrt_fmt_skin_skeleton fsk = {0};
        m_is.readValue(fsk.skin_id);
        m_is.readValue(fsk.skeleton_id);
        VFX_DEV_ASSERT(fsk.skin_id != 0);
        VFX_DEV_ASSERT(fsk.skeleton_id != 0);

        // skin by object index
        VfxSkinnedMesh *skin = getSkinnedMeshFromMap(fsk.skin_id);
        V3DA_FAIL_HANDLE(skin, return VFX_FALSE);

        // skeleton by object index
        VfxBone *bone = getBoneFromMap(fsk.skeleton_id);
        VFX_DEV_ASSERT(bone);

        skin->setSkeleton(bone);
    }

    return VFX_TRUE;
}

static vrt_object_property_id_enum vrt_anim_prop_to_vrt_obj_prop(vrt_animatable_property_id_enum animprop_id)
{
    switch (animprop_id)
    {
    case VRT_ANIMATABLE_PROPERTY_ID_TRANSLATION:            return VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION;
    case VRT_ANIMATABLE_PROPERTY_ID_ORIENTATION:            return VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION;
    case VRT_ANIMATABLE_PROPERTY_ID_SCALE:                  return VRT_TRANSFORMABLE_PROPERTY_ID_SCALE;
    case VRT_ANIMATABLE_PROPERTY_ID_PIVOT:                  return VRT_TRANSFORMABLE_PROPERTY_ID_PIVOT;

    case VRT_ANIMATABLE_PROPERTY_ID_NODE_OPACITY:           return VRT_NODE_PROPERTY_ID_OPACITY;

    case VRT_ANIMATABLE_PROPERTY_ID_LIGHT_COLOR:            return VRT_LIGHT_PROPERTY_ID_LIGHT_COLOR;
    case VRT_ANIMATABLE_PROPERTY_ID_LIGHT_INTENSITY:        return VRT_LIGHT_PROPERTY_ID_LIGHT_INTENSITY;

    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_FLOAT:  return VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_VEC2:   return VRT_SHADER_VARIABLE_PROPERTY_ID_VEC2;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_VEC3:   return VRT_SHADER_VARIABLE_PROPERTY_ID_VEC3;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_VEC4:   return VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_QUAT:   return VRT_SHADER_VARIABLE_PROPERTY_ID_QUAT;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT2:   return VRT_SHADER_VARIABLE_PROPERTY_ID_MAT2;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT3:   return VRT_SHADER_VARIABLE_PROPERTY_ID_MAT3;
    case VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT4:   return VRT_SHADER_VARIABLE_PROPERTY_ID_MAT4;
    }

    VFX_ASSERT(0);
    return VRT_OBJECT_PROPERTY_ID_UNKNOWN;
}

VfxBool VfxAssetLoader::parseTimeline(VfxKeyframeTimeline *timeline)
{
    vrt_obj_keyframe_timeline okt = {0};
    m_is.readValue(okt.start);
    m_is.readValue(okt.duration);
    m_is.readValue(okt.animprop_id);
    m_is.readValue(okt.interpolation);
    VfxAssetSrc kfs_ref;
    readReference(kfs_ref);
    V3DA_FAIL_HANDLE(okt.animprop_id < VRT_ANIMATABLE_PROPERTY_ID_END_OF_ENUM, return VFX_FALSE);
    V3DA_FAIL_HANDLE(okt.interpolation < VFX_INTERPOLATE_FUNC_ID_END_OF_ENUM, return VFX_FALSE);
    V3DA_FAIL_HANDLE(!kfs_ref.isNull(), return VFX_FALSE);

    timeline->setStartTime(okt.start);
    timeline->setDurationTime(okt.duration);
    timeline->setTargetPropertyId(vrt_anim_prop_to_vrt_obj_prop((vrt_animatable_property_id_enum)okt.animprop_id));
    timeline->setKeyframeInterpolation((VfxInterpolationFuncIdEnum)okt.interpolation);
    timeline->setKeyframeSource(kfs_ref);

    return VFX_TRUE;
}

VfxBool VfxAssetLoader::parseAnimation(VfxAnimation *anim, VfxNode *node)
{
    vrt_obj_animation oa = {0};
    m_is.readValue(oa.start);
    m_is.readValue(oa.duration);
    m_is.readValue(oa.tl_count);

    VfxU32 i;
    for (i = 0; i < oa.tl_count; ++i)
    {
        vrt_obj_animation::vrt_fmt_timeline_target ftt = {0};
        VfxString target_name;
        readString(target_name);
        m_is.readValue(ftt.tl_id);

        // timeline by object index
        VfxBaseTimeline *tl = getTimelineFromMap(ftt.tl_id);
        V3DA_FAIL_HANDLE(tl, return VFX_FALSE);

        // target by name hash
        VfxAnimatable *target = NULL;
        if (node != NULL)
        {
            target = node->getTargetLookup(target_name);
        }

        // real target is a shader variable in target mesh
        vrt_object_property_id_enum prop_id = tl->getTargetPropertyId();
        if (VRT_SHADER_VARIABLE_PROPERTY_ID_FIRST <= prop_id &&
            prop_id <= VRT_SHADER_VARIABLE_PROPERTY_ID_LAST)
        {
            VfxString var_name;
            readString(var_name);
            m_is.readValue(ftt.mtl_idx);
            m_is.readValue(ftt.pass_idx);

            // variable by index and name
            VfxShaderVariable *var = NULL;

            VfxMesh *mesh = VFX_OBJ_DYNAMIC_CAST(target, VfxMesh);
            if (mesh != NULL && mesh->getSubMeshCount() > ftt.mtl_idx)
            {
                VfxMaterial *mtl = mesh->getMaterial(ftt.mtl_idx);
                if (mtl != NULL && mtl->getPassCount() > ftt.pass_idx)
                {
                    VfxPass *pass = mtl->getPass(ftt.pass_idx);
                    if (pass != NULL)
                    {
                        var = pass->getUniformVariable(var_name);
                    }
                }
            }

            target = var;
        }

        if (target == NULL)
        {
            VFX_LOG(VFX_INFO, VFX_ASSETLOADER_TARGET_NOT_FOUND, target_name.getBuf());
            VFX_OBJ_CLOSE(tl);
        }
        else
        {
            tl->setTarget(target);
        }
    }

    //anim->setStartTime(oa.start);
    //anim->setDurationTime(oa.duration);

    return VFX_TRUE;
}


VfxBool VfxAssetLoader::parseAndCreateNode(VfxNode **ppnode, const VfxClassInfo *type)
{
    VFX_DEV_ASSERT(ppnode != NULL);
    VFX_DEV_ASSERT(*ppnode != NULL || type != NULL);

    vrt_obj_node on = {0};
    m_is.readValue(on.parent_id);
    m_is.readValue(on.trsp_flags);
    //m_is.readValue(on.opacity);

    if (*ppnode == NULL)
    {
        VFX_DEV_ASSERT(on.parent_id != 0);

        // parent group by object index
        VfxGroup *parent = getGroupFromMap(on.parent_id);
        V3DA_FAIL_HANDLE(parent, return VFX_FALSE);

        // create node
        VfxObject *object = type->createObject(parent);
        *ppnode = VFX_OBJ_DYNAMIC_CAST(object, VfxNode);
        VFX_DEV_ASSERT(*ppnode);
    }
    else
    {
        // root node
        VFX_DEV_ASSERT(on.parent_id == 0);
    }

    // parse transforms
    VfxNode *node = *ppnode;

    if (on.trsp_flags & VRT_NODE_PROPERTY_FLAG_LOOKAT)
    {
        // special case: lookat
        VFX_DEV_ASSERT(on.trsp_flags == VRT_NODE_PROPERTY_FLAG_LOOKAT);
        VfxCamera *camera = VFX_OBJ_DYNAMIC_CAST(node, VfxCamera);
        VFX_DEV_ASSERT(camera);
        if (camera)
        {
            VfxMatrix3f lookat;
            m_is.readValue(lookat);
            camera->setLookAt(lookat.col[0], lookat.col[1], lookat.col[2]);
        }
    }
    else
    {
        if (on.trsp_flags & VRT_NODE_PROPERTY_FLAG_TRANSLATION)
        {
            VfxVector3f translation;
            m_is.readValue(translation);
            node->setTranslation(translation);
        }
        if (on.trsp_flags & VRT_NODE_PROPERTY_FLAG_ROTATION)
        {
            VfxQuaternionf rotation;
            m_is.readValue(rotation);
            node->setRotation(rotation);
        }
        if (on.trsp_flags & VRT_NODE_PROPERTY_FLAG_SCALE)
        {
            VfxVector3f scale;
            m_is.readValue(scale);
            node->setScale(scale);
        }
        if (on.trsp_flags & VRT_NODE_PROPERTY_FLAG_PIVOT)
        {
            VfxMatrix4f pivot;
            m_is.readValue(pivot);
            node->setPivot(pivot);
        }
    }

    if (on.trsp_flags & VRT_NODE_PROPERTY_FLAG_OPACITY)
    {
        VfxFloat opacity;
        m_is.readValue(opacity);
        node->setOpacity(opacity);
    }

    return VFX_TRUE;
}


VfxPolygonMode *VfxAssetLoader::createPolygonMode(VfxObject *owner)
{
    vrt_fmt_polygon_mode fpm = {0};
    m_is.readValue(fpm.winding);  // VFX_WINDING_CCW
    m_is.readValue(fpm.culling);  // VFX_CULLING_BACK
    V3DA_FAIL_HANDLE(fpm.winding < VFX_WINDING_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fpm.culling < VFX_CULLING_END_OF_ENUM, return NULL);

    VfxPolygonMode *mode = NULL;
    VFX_OBJ_CREATE(mode, VfxPolygonMode, owner);

    mode->setWinding((VfxWindingMode)fpm.winding);
    mode->setCulling((VfxCullingMode)fpm.culling);

    return mode;
}

VfxBlender *VfxAssetLoader::createBlender(VfxObject *owner)
{
    vrt_fmt_blender fb = {0};
    m_is.readValue(fb.color);     // VRT_COLOR_NULL
    m_is.readValue(fb.color_eq);  // VFX_BLEND_EQUATION_ADD
    m_is.readValue(fb.alpha_eq);  // VFX_BLEND_EQUATION_ADD
    m_is.readValue(fb.src_color); // VFX_BLEND_FACTOR_SRC_ALPHA
    m_is.readValue(fb.dst_color); // VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA
    m_is.readValue(fb.src_alpha); // VFX_BLEND_FACTOR_ONE
    m_is.readValue(fb.dst_alpha); // VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA
    V3DA_FAIL_HANDLE(fb.color_eq < VFX_BLEND_EQUATION_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fb.alpha_eq < VFX_BLEND_EQUATION_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fb.src_color < VFX_BLEND_FACTOR_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fb.dst_color < VFX_BLEND_FACTOR_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fb.src_alpha < VFX_BLEND_FACTOR_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fb.dst_alpha < VFX_BLEND_FACTOR_END_OF_ENUM, return NULL);

    VfxBlender *blender = NULL;
    VFX_OBJ_CREATE(blender, VfxBlender, owner);

    blender->setBlendColor(fb.color);
    blender->setBlendEquation((VfxBlendEquation)fb.color_eq, (VfxBlendEquation)fb.alpha_eq);
    blender->setBlendFunc((VfxBlendFactor)fb.src_color, (VfxBlendFactor)fb.dst_color, (VfxBlendFactor)fb.src_alpha, (VfxBlendFactor)fb.dst_alpha);

    return blender;
}

VfxStencil *VfxAssetLoader::createStencil(VfxObject *owner)
{
    vrt_fmt_stencil fs = {0};
    m_is.readValue(fs.front.op_sfail);
    m_is.readValue(fs.front.op_dfail);
    m_is.readValue(fs.front.op_pass);
    m_is.readValue(fs.front.func);
    m_is.readValue(fs.front.ref);
    m_is.readValue(fs.front.mask);
    m_is.readValue(fs.front.write_mask);
    m_is.readValue(fs.back.op_sfail);
    m_is.readValue(fs.back.op_dfail);
    m_is.readValue(fs.back.op_pass);
    m_is.readValue(fs.back.func);
    m_is.readValue(fs.back.ref);
    m_is.readValue(fs.back.mask);
    m_is.readValue(fs.back.write_mask);
    V3DA_FAIL_HANDLE(fs.front.op_sfail < VFX_STENCIL_OP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.front.op_dfail < VFX_STENCIL_OP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.front.op_pass < VFX_STENCIL_OP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.front.func < VFX_STENCIL_FUNC_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.back.op_sfail < VFX_STENCIL_OP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.back.op_dfail < VFX_STENCIL_OP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.back.op_pass < VFX_STENCIL_OP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(fs.back.func < VFX_STENCIL_FUNC_END_OF_ENUM, return NULL);

    VfxStencil *stencil = NULL;
    VFX_OBJ_CREATE(stencil, VfxStencil, owner);

    stencil->setStencilFunc(
        (VfxStencilFunc)fs.front.func, fs.front.ref, fs.front.mask,
        (VfxStencilFunc)fs.back.func, fs.back.ref, fs.back.mask);
    stencil->setStencilOperation(
        (VfxStencilOp)fs.front.op_sfail, (VfxStencilOp)fs.front.op_dfail, (VfxStencilOp)fs.front.op_pass,
        (VfxStencilOp)fs.back.op_sfail, (VfxStencilOp)fs.back.op_dfail, (VfxStencilOp)fs.back.op_pass);
    stencil->setStencilMask(fs.front.write_mask, fs.back.write_mask);

    return stencil;
}

VfxCompositingMode *VfxAssetLoader::createCompositingMode(VfxObject *owner)
{
    vrt_fmt_compositing_mode fcm = {0};
    m_is.readValue(fcm.has_blender);          // VFX_FALSE
    m_is.readValue(fcm.has_stencil);          // VFX_FALSE
    m_is.readValue(fcm.color_mask);           // 0xFFFFFFFF
    m_is.readValue(fcm.depth_offset_factor);  // 0.0f
    m_is.readValue(fcm.depth_offset_units);   // 0.0f
    m_is.readValue(fcm.depth_test);           // VFX_TRUE
    m_is.readValue(fcm.depth_write_enable);   // VFX_TRUE
    m_is.readValue(fcm.depth_func);           // VFX_DEPTH_FUNC_LESS
    V3DA_FAIL_HANDLE(fcm.depth_func < VFX_DEPTH_FUNC_END_OF_ENUM, return NULL);

    VfxCompositingMode *mode = NULL;
    VFX_OBJ_CREATE(mode, VfxCompositingMode, owner);

    if (fcm.has_blender)
    {
        VfxBlender *blender = createBlender(owner);
        mode->setBlender(blender);
    }
    if (fcm.has_stencil)
    {
        VfxStencil *stencil = createStencil(owner);
        mode->setStencil(stencil);
    }

    mode->setColorWriteMask(fcm.color_mask);
    mode->setDepthOffset(fcm.depth_offset_factor, fcm.depth_offset_units);
    mode->setDepthTestEnable(fcm.depth_test);
    mode->setDepthWriteEnable(fcm.depth_write_enable);
    mode->setDepthFunc((VfxDepthFunc)fcm.depth_func);

    return mode;
}

VfxShaderProgram *VfxAssetLoader::createShaderProgram(VfxObject *owner)
{
    //vrt_obj_shader_program osp = {0};
    VfxAssetSrc vs_ref;
    readReference(vs_ref);
    VfxAssetSrc fs_ref;
    readReference(fs_ref);

    VfxShaderProgram *prog = NULL;
    VFX_OBJ_CREATE_EX(prog, VfxShaderProgram, owner, (vs_ref, fs_ref));

    return prog;
}

VfxTexture *VfxAssetLoader::createTexture(VfxObject *owner)
{
    vrt_obj_texture ot = {0};
    m_is.readValue(ot.texture_type);
    m_is.readValue(ot.level_filter);
    m_is.readValue(ot.image_filter);
    m_is.readValue(ot.wrap_s);
    m_is.readValue(ot.wrap_t);
    VfxAssetSrc image_ref;
    readReference(image_ref);
    V3DA_FAIL_HANDLE(ot.texture_type < VFX_TEXTURE_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(ot.level_filter < VFX_FILTER_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(ot.image_filter < VFX_FILTER_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(ot.wrap_s < VFX_TEXTURE_WRAP_END_OF_ENUM, return NULL);
    V3DA_FAIL_HANDLE(ot.wrap_t < VFX_TEXTURE_WRAP_END_OF_ENUM, return NULL);

    VfxImageBase *image = NULL;
    if (!image_ref.isNull())
    {
        VfxImageSrc image_src;
        switch (image_ref.getType())
        {
        case VFX_ASSET_SRC_TYPE_RES_ID: image_src.setResId(image_ref.getResId());   break;
        case VFX_ASSET_SRC_TYPE_PATH:   image_src.setPath(image_ref.getPath());     break;
        default:                        VFX_DEV_ASSERT(VFX_FALSE);
        }

        switch (ot.texture_type)
        {
        case VFX_TEXTURE_2D:    VFX_OBJ_CREATE_EX(image, VfxImage2D, owner, (image_src));       break;
        case VFX_TEXTURE_CUBE:  VFX_OBJ_CREATE_EX(image, VfxImageCube, owner, (image_src));     break;
        //case VFX_TEXTURE_DEPTH: VFX_OBJ_CREATE_EX(image, VfxImageDepth, owner, (image_src));    break;
        default:                VFX_DEV_ASSERT(VFX_FALSE);
        }
    }

    VfxTexture *texture = NULL;
    switch (ot.texture_type)
    {
    case VFX_TEXTURE_2D:    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, owner, ((VfxImage2D *)image));         break;
    case VFX_TEXTURE_CUBE:  VFX_OBJ_CREATE_EX(texture, VfxTextureCube, owner, ((VfxImageCube *)image));     break;
    //case VFX_TEXTURE_DEPTH: VFX_OBJ_CREATE_EX(texture, VfxTextureDepth, owner, ((VfxImageDepth *)image));   break;
    default:                V3DA_FAIL_HANDLE(VFX_FALSE, return NULL);
    }

    texture->setFilter((VfxFilterMode)ot.level_filter, (VfxFilterMode)ot.image_filter);
    texture->setWrapping((VfxWrapMode)ot.wrap_s, (VfxWrapMode)ot.wrap_t);

    return texture;
}

VfxShaderUniforms *VfxAssetLoader::createShaderUniforms(VfxObject *owner)
{
    vrt_obj_uniforms ou = {0};
    m_is.readValue(ou.uv_count);

    VfxShaderUniforms *uniforms = NULL;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, owner);

    // variables
    VfxU32 i;
    for (i = 0; i < ou.uv_count; ++i)
    {
        vrt_obj_uniforms::vrt_fmt_uniform_variable fuv = {0};
        VfxString name;
        readString(name);
        m_is.readValue(fuv.type);
        m_is.readValue(fuv.count);
        V3DA_FAIL_HANDLE(fuv.type < VFX_TYPE_ID_END_OF_ENUM, VFX_OBJ_CLOSE(uniforms); return NULL);

        VfxShaderVariable *variable = uniforms->addUniformVariable(name, (VfxTypeIdEnum)fuv.type, fuv.count);

        if (fuv.type == VFX_TYPE_ID_SAMPLER)
        {
            V3DA_FAIL_HANDLE(fuv.count == 1, VFX_OBJ_CLOSE(uniforms); return NULL);

            vrt_obj_index_type tex_id = 0;
            m_is.readValue(tex_id);

            VfxTexture *tex = NULL;
            if (tex_id)
            {
                tex = getTextureFromMap(tex_id);
                VFX_DEV_ASSERT(tex);
            }

            variable->setValue(tex);
        }
        else if (m_type == VFX_ASSET_LOADER_SRC_TYPE_PATH)
        {
            variable->readValueStream(m_is);
        }
        else if (m_type == VFX_ASSET_LOADER_SRC_TYPE_RES_ID)
        {
            VfxU32 pos = m_is.tell();
            variable->setValueFromConstBuf((void *)(m_mem + pos));
            m_is.ignore(variable->getDataSize());
        }
    }

    return uniforms;
}

VfxRenderTarget *VfxAssetLoader::createRenderTarget(VfxObject *owner)
{
    vrt_obj_render_target ort = {0};
    // TODO: read buffer refs
    m_is.readValue(ort.clear_color);  // VRT_COLOR_NULL
    m_is.readValue(ort.enable_clear); // VFX_FALSE

    VfxRenderTarget *rt = NULL;
    VFX_OBJ_CREATE(rt, VfxRenderTarget, owner);

    // TODO: attach buffers
    rt->setClearColor(ort.clear_color);
    rt->enableClearColor(ort.enable_clear);

    return rt;
}

VfxPass *VfxAssetLoader::createPass(VfxObject *owner)
{
    vrt_obj_pass op = {0};
    m_is.readValue(op.has_polygon);           // VFX_FALSE
    m_is.readValue(op.has_compositing);       // VFX_FALSE
    m_is.readValue(op.un_count);
    m_is.readValue(op.pass_type);             // VFX_PASS_GEOMETRY_DEFAULT
    m_is.readValue(op.prog_id);
    m_is.readValue(op.rt_id);
    m_is.readValue(op.tessellation_level);    // VrtVector2us(1, 1)
    V3DA_FAIL_HANDLE(op.pass_type < VFX_PASS_GEOMETRY_END_OF_ENUM, return NULL);

    VfxPass *pass = NULL;
    VFX_OBJ_CREATE_EX(pass, VfxPass, owner, ((VfxPassGeometryType)op.pass_type));

    if (op.has_polygon)
    {
        VfxPolygonMode *polygon = createPolygonMode(owner);
        pass->setPolygonMode(polygon);
    }
    if (op.has_compositing)
    {
        VfxCompositingMode *compositing = createCompositingMode(owner);
        pass->setCompositingMode(compositing);
    }

    // uniforms list
    VfxU32 i;
    for (i = 0; i < op.un_count; ++i)
    {
        vrt_obj_index_type su_id = 0;
        m_is.readValue(su_id);

        // uniforms by object index
        VfxShaderUniforms *su = getUniformsFromMap(su_id);
        VFX_DEV_ASSERT(su);
        if (su)
        {
            pass->addShaderUniforms(su);
        }
    }

    // shader program by object index
    if (op.prog_id)
    {
        VfxShaderProgram *prog = getProgramFromMap(op.prog_id);
        VFX_DEV_ASSERT(prog);

        pass->setShaderProgram(prog);
    }

    // render target by object index
    if (op.rt_id)
    {
        VfxRenderTarget *rt = getRenderTargetFromMap(op.rt_id);
        VFX_DEV_ASSERT(rt);

        pass->setRenderTarget(rt);
    }

    pass->setTessellationLevel(op.tessellation_level);

    return pass;
}

VfxGroup *VfxAssetLoader::createGroupNode(const VfxClassInfo *type)
{
    VfxGroup *group = NULL;
    if (!parseAndCreateNode((VfxNode **)&group, type))
        return NULL;

    vrt_obj_node::vrt_fmt_group fg = {0};
    m_is.readValue(fg.child_count);

    return group;
}

VfxCamera *VfxAssetLoader::createCameraNode()
{
    VfxCamera *camera = NULL;
    if (!parseAndCreateNode((VfxNode **)&camera, VFX_OBJ_CLASS_INFO(VfxCamera)))
        return NULL;

    vrt_obj_node::vrt_fmt_camera fc = {0};
    m_is.readValue(fc.proj_type);
    m_is.readValue(fc.fovy);
    m_is.readValue(fc.aspect_ratio);
    m_is.readValue(fc.znear);
    m_is.readValue(fc.zfar);
    V3DA_FAIL_HANDLE(
        (vrt_camera_projection_type_enum)fc.proj_type < VRT_CAMERA_PROJECTION_TYPE_END_OF_ENUM,
        VFX_OBJ_CLOSE(camera); return NULL);

    switch (fc.proj_type)
    {
    case VRT_CAMERA_PROJECTION_TYPE_PERSPECTIVE:
        camera->setPerspective(fc.fovy, fc.aspect_ratio, fc.znear, fc.zfar);
        break;
    case VRT_CAMERA_PROJECTION_TYPE_PARALLEL:
        camera->setParallel(fc.fovy, fc.aspect_ratio, fc.znear, fc.zfar);
        break;
    default: VFX_DEV_ASSERT(VFX_FALSE);
    }

    return camera;
}

VfxLight *VfxAssetLoader::createLightNode()
{
    VfxLight *light = NULL;
    if (!parseAndCreateNode((VfxNode **)&light, VFX_OBJ_CLASS_INFO(VfxLight)))
        return NULL;

    vrt_obj_node::vrt_fmt_light fl = {0};
    m_is.readValue(fl.color);
    m_is.readValue(fl.intensity);

    light->setColor(fl.color);
    light->setIntensity(fl.intensity);

    return light;
}

VfxMesh *VfxAssetLoader::createMeshNode(VfxGroup *mtlowner, const VfxClassInfo *type)
{
    VfxMesh *mesh = NULL;
    if (!parseAndCreateNode((VfxNode **)&mesh, type))
        return NULL;

    vrt_obj_node::vrt_fmt_mesh fm = {0};
    m_is.readValue(fm.bm_count);
    VfxAssetSrc mesh_ref;
    readReference(mesh_ref);

    // mesh data by reference
    if (!mesh_ref.isNull())
    {
        // TODO: shallow-clone mesh if loaded (do not reload)
        VfxAssetIndexType mesh_id = loadMeshImp(mesh, mesh_ref);
        if (mesh_id != 0)
        {
            //addAssetMapEntry(mesh_id, mesh);
        }
    }

    V3DA_FAIL_HANDLE(fm.bm_count == mesh->getSubMeshCount(), VFX_OBJ_CLOSE(mesh); return NULL);

    // bind materials
    VfxU32 i;
    for (i = 0; i < fm.bm_count; ++i)
    {
        VfxAssetSrc mtl_ref;
        VfxAssetFileDataStruct mtl_ins = {0};
        readReference(mtl_ref, &mtl_ins);
        VFX_DEV_ASSERT(mtl_ref.isNull() || mtl_ins.data == NULL);

        // material by reference
        if (!mtl_ref.isNull())
        {
            VfxMaterial *mtl = NULL;
            VFX_OBJ_CREATE(mtl, VfxMaterial, mtlowner);

            // TODO: clone material if loaded (do not reload)
            VfxAssetIndexType mtl_id = loadMaterialImp(mtl, mtl_ref);
            if (mtl_id != 0)
            {
                mesh->setMaterial(i, mtl);
                //addAssetMapEntry(mtl_id, mtl);
            }
            else
            {
                VFX_OBJ_CLOSE(mtl);
            }
        }
        else if (mtl_ins.data != NULL)
        {
            VFX_DEV_ASSERT(mtl_ins.size == sizeof(VfxAssetIndexType) + sizeof(VfxU8));
            VfxAssetIndexType *node_id = (VfxAssetIndexType *)mtl_ins.data;
            VfxU8 *mtl_idx = (VfxU8 *)(node_id + 1);
            VFX_DEV_ASSERT(*node_id != 0);

            // node by object index
            VfxNode *node = getNodeFromMap(*node_id);
            VFX_DEV_ASSERT(node);

            // material by index
            VfxMaterial *mtl = NULL;

            // currently only mesh can set material
            VfxMesh *share = VFX_OBJ_DYNAMIC_CAST(node, VfxMesh);
            if (share != NULL && share->getSubMeshCount() > *mtl_idx)
            {
                mtl = share->getMaterial(*mtl_idx);
                if (mtl != NULL)
                {
                    mesh->setMaterial(i, mtl);
                }
            }

            // free data buffer
            if (m_type == VFX_ASSET_LOADER_SRC_TYPE_PATH)
            {
                VFX_SYS_FREE_MEM(mtl_ins.data);
            }
        }
    }

    return mesh;
}

VfxShaderUniforms *VfxAssetLoader::createShaderBindings(VfxGroup *root, VfxBool createLookup)
{
    vrt_obj_bindings ob = {0};
    m_is.readValue(ob.node_id);
    m_is.readValue(ob.mtl_idx);
    m_is.readValue(ob.pass_idx);
    m_is.readValue(ob.ub_count);
    VFX_DEV_ASSERT(ob.node_id != 0);

    // node by object index
    VfxNode *node = getNodeFromMap(ob.node_id);
    VFX_DEV_ASSERT(node);

    // pass by index
    VfxMaterial *mtl = NULL;
    VfxPass *pass = NULL;

    // currently only mesh can set material
    VfxMesh *mesh = VFX_OBJ_DYNAMIC_CAST(node, VfxMesh);
    if (mesh != NULL && mesh->getSubMeshCount() > ob.mtl_idx)
    {
        mtl = mesh->getMaterial(ob.mtl_idx);
        if (mtl != NULL && mtl->getPassCount() > ob.pass_idx)
        {
            pass = mtl->getPass(ob.pass_idx);
        }
    }

    V3DA_FAIL_HANDLE(pass, return NULL);

    VfxShaderUniforms *uniforms = NULL;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, mtl);

    // bindings
    VfxU32 i;
    for (i = 0; i < ob.ub_count; ++i)
    {
        vrt_obj_bindings::vrt_fmt_uniform_binding fub = {0};
        VfxString name;
        readString(name);
        m_is.readValue(fub.type);
        m_is.readValue(fub.object_id);
        m_is.readValue(fub.bindprop_id);
        V3DA_FAIL_HANDLE(fub.type < VFX_TYPE_ID_END_OF_ENUM, VFX_OBJ_CLOSE(uniforms); return NULL);
        V3DA_FAIL_HANDLE(fub.bindprop_id < VFX_BINDING_END_OF_ENUM, VFX_OBJ_CLOSE(uniforms); return NULL);

        VfxWorld *world = root->getWorld();
        VfxObject3D *object = NULL;
        if (fub.object_id)
        {
            // object by object index
            object = getObject3DFromMap(fub.object_id);
            VFX_DEV_ASSERT(object);

            if (createLookup && object && world)
            {
                world->setBindingLookup(name, object);
            }
        }
        else
        {
            // external object by variable name
            if (world != NULL)
            {
                object = world->getBindingLookup(name);
            }
        }

        if (object == NULL)
        {
            VFX_LOG(VFX_INFO, VFX_ASSETLOADER_BINDING_NOT_FOUND, name.getBuf());
        }
        else
        {
            VfxShaderVariable *binding = uniforms->addUniformVariable(name, (VfxTypeIdEnum)fub.type, 1);
            binding->bindValue(object, (VfxVariableBindingProperty)fub.bindprop_id);
        }
    }

    pass->addShaderUniforms(uniforms);

    return uniforms;
}


