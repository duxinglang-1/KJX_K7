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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_skinned_mesh.cpp
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

#include "vfx_skinned_mesh.h"
#include "vfx_bounding_volume.h"
#include "vrt_3d.h"


#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

/***************************************************************************** 
 * Class VfxBone
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Bone", VfxBone, VfxGroup);

void VfxBone::createHandle() const
{
    m_handle = vrt_create_bone();
}


/***************************************************************************** 
 * Class VfxSkinnedMesh
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("SkinnedMesh", VfxSkinnedMesh, VfxMesh);

VfxSkinnedMesh::VfxSkinnedMesh(VfxU32 subMeshCount)
: VfxMesh(subMeshCount)
{
}

void VfxSkinnedMesh::createHandle() const
{
    switch (m_assetSrc.getType())
    {
    case VFX_ASSET_SRC_TYPE_NULL:
        //m_handle = vrt_create_skinned_mesh();
        break;
    case VFX_ASSET_SRC_TYPE_RES_ID:
        {
            m_handle = vrt_create_skinned_mesh_from_resource(m_assetSrc.getResId());
        }
        break;
    case VFX_ASSET_SRC_TYPE_PATH:
        {
            const VfxWString filePath = m_assetSrc.getPath();
            m_handle = vrt_create_skinned_mesh_from_path(filePath.getBuf(), filePath.isDynamic() ? VRT_TRUE : VRT_FALSE);
        }
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}


void VfxSkinnedMesh::disposeHandle() const
{
    if (m_handle)
    {
        const VfxBone *skeleton = m_skeletonRoot.get();
        if (skeleton)
        {
            skeleton->disposeHandle();
        }

        VfxMesh::disposeHandle();
    }
}

void VfxSkinnedMesh::syncData() const
{
    VfxMesh::syncData();

    VfxBone *bone= m_skeletonRoot.get();
    if (bone && bone->getSyncHandle())
    {
        bone->syncData();
    }
    if (isPropertyDirty(VFX_SKINNED_MESH_SKELETON_DIRTY))
    {
        vrt_skinned_mesh_set_skeleton(m_handle, bone ? bone->getSyncHandle() : NULL);
    }

    clearPropertyDirty(VFX_SKINNED_MESH_ALL_DIRTY);
}


void VfxSkinnedMesh::setSkeleton(VfxBone *skeleton)
{
    m_skeletonRoot = skeleton;
    setPropertyDirty(VFX_SKINNED_MESH_SKELETON_DIRTY);

    if (getSkeletonOffsetTransform() == VfxMatrix4f())
    {
        VfxMatrix4f skeletonTransform;
        skeleton->getTransform(skeletonTransform);
        setSkeletonOffsetTransform(skeletonTransform);
    }
}

VfxBone *VfxSkinnedMesh::getSkeleton() const
{
    return m_skeletonRoot.get();
}

void VfxSkinnedMesh::processPick(VfxNodePickReturn &ret, const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    VfxBone *skeleton = getSkeleton();
    if (skeleton == NULL)
    {
        VfxMesh::processPick(ret, rayOrigin, rayDirection);
        return;
    }
    else if (!VFX_FLAG_HAS_ALL(m_nodeFlags, VFX_NODE_FLAG_VISIBLE | VFX_NODE_FLAG_PICKABLE) ||
        m_boundingVolume == NULL)
    {
        ret.clear();
        return;
    }

    VfxMatrix4f worldTransform;
    getWorldTransform(worldTransform);
    VfxMatrix4f worldTransformInverse;
    worldTransformInverse = inverse(worldTransform);

    VfxVector4f worldRayOrigin = worldTransform * VfxVector4f(rayOrigin, 1.0f);
    VfxVector4f worldRayDirection = worldTransform * VfxVector4f(rayDirection, 0.0f);

    VfxMatrix4f skeletonWorldTransform;
    skeleton->getWorldTransform(skeletonWorldTransform);
    VfxMatrix4f skeletonWorldTransformInverse;
    skeletonWorldTransformInverse = inverse(skeletonWorldTransform);

    VfxVector4f skeletonRayOrigin = getSkeletonOffsetTransformInverse() * (skeletonWorldTransformInverse * worldRayOrigin);
    VfxVector4f skeletonRayDirection = getSkeletonOffsetTransformInverse() * (skeletonWorldTransformInverse * worldRayDirection);

    if (!m_boundingVolume->intersectWithDirRay(skeletonRayOrigin.xyz(), skeletonRayDirection.xyz()))
    {
        ret.clear();
        return;
    }

    ret.m_node = const_cast <VfxSkinnedMesh *> (this);

    VfxVector4f pickPoint = skeletonWorldTransform * getSkeletonOffsetTransform() * VfxVector4f(m_boundingVolume->m_center, 1.0f);
    ret.m_point = (worldTransformInverse * pickPoint).xyz();
}


/***************************************************************************** 
 * Class VfxProceduralSkinnedMesh
 *****************************************************************************/

VfxProceduralSkinnedMesh::VfxProceduralSkinnedMesh()
: VfxSkinnedMesh(1)
{
}

void VfxProceduralSkinnedMesh::createHandle() const
{
    const IVrtProceduralMesh *pm = static_cast<const IVrtProceduralMesh *>(this);
    m_handle = vrt_create_procedural_skinned_mesh(reinterpret_cast<const void *>(pm));
}

#pragma arm section code, rodata

