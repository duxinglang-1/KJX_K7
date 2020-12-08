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
 *  vfx_skinned_mesh.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_SKINNED_MESH_H__
#define __VFX_SKINNED_MESH_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mesh.h"
#include "vfx_group.h"


/***************************************************************************** 
 * Class VfxBone
 *****************************************************************************/

/*
 * VfxBone is the bone object of skeleton of skinned mesh.
 */
class VfxBone : public VfxGroup
{
    VFX_DECLARE_CLASS(VfxBone);

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_SKINNED_MESH_BEGIN_FLAG             (VFX_MESH_END_FLAG)
#define VFX_SKINNED_MESH_SKELETON_DIRTY         (VFX_SKINNED_MESH_BEGIN_FLAG << 1)
#define VFX_SKINNED_MESH_END_FLAG               VFX_SKINNED_MESH_SKELETON_DIRTY
#define VFX_SKINNED_MESH_ALL_DIRTY              (VFX_SKINNED_MESH_SKELETON_DIRTY)


/***************************************************************************** 
 * Class VfxSkinnedMesh
 *****************************************************************************/

/*
 * VfxSkinnedMesh is the skinned mesh object in 3D scene.
 */
class VfxSkinnedMesh : public VfxMesh
{
    VFX_DECLARE_CLASS(VfxSkinnedMesh);

// Constructor / Destructor
public:
    // Default constructor
    VfxSkinnedMesh(VfxU32 subMeshCount = 1);

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set skeleton root.
    void setSkeleton(VfxBone *skeleton);

    // Get skeleton root.
    VfxBone *getSkeleton() const;

    // Internal used. Set skeleton offset transform from stream for picking.
    void setSkeletonOffsetTransform(const VfxMatrix4f &skeletonOff);

    // Get skeleton offset transform.
    const VfxMatrix4f &getSkeletonOffsetTransform() const;

    // Get skeleton offset transform inverse.
    const VfxMatrix4f &getSkeletonOffsetTransformInverse() const;

// Override
protected:
    virtual void processPick(
        VfxNodePickReturn &ret,
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;

// Implementation
protected:
    VfxWeakPtr< VfxBone > m_skeletonRoot;
    VfxMatrix4f m_skeletonOffset;
    VfxMatrix4f m_skeletonOffsetInverse;
};


inline void VfxSkinnedMesh::setSkeletonOffsetTransform(const VfxMatrix4f &skeletonOff)
{
    m_skeletonOffset = skeletonOff;
    m_skeletonOffsetInverse = inverse(skeletonOff);
}


inline const VfxMatrix4f &VfxSkinnedMesh::getSkeletonOffsetTransform() const
{
    return m_skeletonOffset;
}


inline const VfxMatrix4f &VfxSkinnedMesh::getSkeletonOffsetTransformInverse() const
{
    return m_skeletonOffsetInverse;
}


/***************************************************************************** 
 * Class VfxProceduralSkinnedMesh
 *****************************************************************************/

/*
 * VfxProceduralSkinnedMesh is a custom skinned mesh object in 3D scene.
 */
class VfxProceduralSkinnedMesh : public VfxSkinnedMesh, public IVrtProceduralMesh
{
// Constructor / Destructor
public:
    // Default constructor
    VfxProceduralSkinnedMesh();

// Override
public:
    virtual void createHandle() const;
};


#endif /* __VFX_SKINNED_MESH_H__ */

