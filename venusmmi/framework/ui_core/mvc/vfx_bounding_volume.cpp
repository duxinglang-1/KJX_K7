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
 *  vfx_bounding_volume.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Bounding Volume Type
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_bounding_volume.h"


/***************************************************************************** 
 * Class VfxBoundingVolume
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VfxBoundingVolume::VfxBoundingVolume() :
    m_testFlags(VFX_BOUNDING_VOLUME_TEST_FLAGS_NONE),
    m_center(0.0f),
    m_radius2(0.0f),
    m_box(0.0f)
{
}


VfxBoundingVolume::VfxBoundingVolume(VfxVector3f center, VfxFloat radius2, VfxVector3f box) :
    m_testFlags(VFX_BOUNDING_VOLUME_TEST_FLAGS_ALL),
    m_center(center),
    m_radius2(radius2),
    m_box(box)
{
}


VfxBoundingVolume::VfxBoundingVolume(VfxVector3f center, VfxVector3f box) :
    m_testFlags(VFX_BOUNDING_VOLUME_TEST_FLAGS_BOX),
    m_center(center),
    m_radius2(0.0f),
    m_box(box)
{
}


VfxBoundingVolume::VfxBoundingVolume(VfxVector3f center, VfxFloat radius2) :
    m_testFlags(VFX_BOUNDING_VOLUME_TEST_FLAGS_SPHERE),
    m_center(center),
    m_radius2(radius2),
    m_box(0.0f)
{
}


VfxBoundingVolume::VfxBoundingVolume(const VfxBoundingVolume &other) :
    m_testFlags(other.m_testFlags),
    m_center(other.m_center),
    m_radius2(other.m_radius2),
    m_box(other.m_box)
{
}


VfxBool VfxBoundingVolume::intersectWithDirRay(const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    if (VFX_FLAG_HAS_ALL(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_ALL))
    {
        return intersectWithDirRayInt(rayOrigin, rayDirection);
    }
    
    if (VFX_FLAG_HAS(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_SPHERE))
    {
        return intersetSphereWithDirRayInt(rayOrigin, rayDirection);
    }
    
    if (VFX_FLAG_HAS(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_BOX))
    {
        return intersetBoxWithDirRayInt(rayOrigin, rayDirection);
    }

    return VFX_FALSE;
}


VfxBool VfxBoundingVolume::intersetSphereWithDirRay(
    const VfxVector3f &rayOrigin, 
    const VfxVector3f &rayDirection) const
{
    if (!VFX_FLAG_HAS(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_SPHERE))
    {
        return VFX_FALSE;
    }

    return intersetSphereWithDirRayInt(rayOrigin, rayDirection);
}


VfxBool VfxBoundingVolume::intersetBoxWithDirRay(
    const VfxVector3f &rayOrigin, 
    const VfxVector3f &rayDirection) const
{
    if (!VFX_FLAG_HAS(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_BOX))
    {
        return VFX_FALSE;
    }

    return intersetBoxWithDirRayInt(rayOrigin, rayDirection);
}


VfxBool VfxBoundingVolume::intersectWithDirRayInt(const VfxVector3f &rayOrigin, const VfxVector3f &rayDirection) const
{
    VFX_DEV_ASSERT(VFX_FLAG_HAS_ALL(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_ALL));
    
    VfxVector3f centerOrigin = rayOrigin - m_center;
    if (interBox(centerOrigin) && interSphere(centerOrigin))
    {
        // The rayOrigin is in this volume
        return VFX_TRUE;
    }
    
    VfxFloat rayDirectionLength = length(rayDirection);
    if (rayDirectionLength == 0.0f)
    {
        // This is a zero length direction
        return VFX_FALSE;
    }
    
    VfxVector3f rayDirectionNormalize(rayDirection / rayDirectionLength);
    VfxFloat distance = dot(centerOrigin, rayDirectionNormalize);
    if (distance > 0)
    {
        // The rayDirection is not pointer to this volume
        return VFX_FALSE;
    }
    
    VfxVector3f verticalPoint = centerOrigin - rayDirectionNormalize * distance;
    if (!interSphere(verticalPoint))
    {
        // The vertical distance between ray and center is not in the volume
        return VFX_FALSE;
    }

    if (!intersetBoxWithNormalizedDirRay(centerOrigin, rayDirectionNormalize))
    {
        // The direction ray does not intersect with this
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VfxBoundingVolume::intersetSphereWithDirRayInt(
    const VfxVector3f &rayOrigin, 
    const VfxVector3f &rayDirection) const
{
    VFX_DEV_ASSERT(VFX_FLAG_HAS(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_SPHERE));
    
    VfxVector3f centerOrigin = rayOrigin - m_center;
    if (interSphere(centerOrigin))
    {
        return VFX_TRUE;
    }
    
    VfxFloat rayDirectionLength = length(rayDirection);
    if (rayDirectionLength == 0.0f)
    {
        return VFX_FALSE;
    }
    
    VfxVector3f rayDirectionNormalize(rayDirection / rayDirectionLength);
    VfxFloat distance = dot(centerOrigin, rayDirectionNormalize);
    if (distance > 0)
    {
        return VFX_FALSE;
    }
    
    VfxVector3f verticalPoint = centerOrigin - rayDirectionNormalize * distance;
    if (!interSphere(verticalPoint))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VfxBoundingVolume::intersetBoxWithDirRayInt(
    const VfxVector3f &rayOrigin, 
    const VfxVector3f &rayDirection) const
{
    VFX_DEV_ASSERT(VFX_FLAG_HAS(m_testFlags, VFX_BOUNDING_VOLUME_TEST_FLAGS_BOX));
    
    VfxVector3f centerOrigin = rayOrigin - m_center;
    if (interBox(centerOrigin))
    {
        return VFX_TRUE;
    }
    
    VfxFloat rayDirectionLength = length(rayDirection);
    if (rayDirectionLength == 0.0f)
    {
        return VFX_FALSE;
    }
    
    VfxVector3f rayDirectionNormalize(rayDirection / rayDirectionLength);
    VfxFloat distance = dot(centerOrigin, rayDirectionNormalize);
    if (distance > 0)
    {
        return VFX_FALSE;
    }

    if (!intersetBoxWithNormalizedDirRay(centerOrigin, rayDirectionNormalize))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VfxBoundingVolume::interSphere(const VfxVector3f &centerPoint) const
{
    if (length2(centerPoint) <= m_radius2)
    {
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}

    
VfxBool VfxBoundingVolume::interBox(const VfxVector3f &centerPoint) const
{
    if (fabs(centerPoint.x) <= m_box.x &&
        fabs(centerPoint.y) <= m_box.y &&
        fabs(centerPoint.z) <= m_box.z)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VfxBoundingVolume::intersetBoxWithNormalizedDirRay(
    const VfxVector3f &centerOrigin,
    const VfxVector3f &rayDirectionNormalize) const
{
    if (rayDirectionNormalize.z != 0.0f)
    {
        VfxVector2f box(
            m_box.x + m_box.z * fabs(rayDirectionNormalize.x / rayDirectionNormalize.z),
            m_box.y + m_box.z * fabs(rayDirectionNormalize.y / rayDirectionNormalize.z));

        VfxVector2f point(
            fabs(centerOrigin.x - centerOrigin.z * rayDirectionNormalize.x / rayDirectionNormalize.z),
            fabs(centerOrigin.y - centerOrigin.z * rayDirectionNormalize.y / rayDirectionNormalize.z));

        if (point.x > box.x || point.y > box.y)
        {
            return VFX_FALSE;
        }
    }

    if (rayDirectionNormalize.y != 0.0f)
    {
        VfxVector2f box(
            m_box.z + m_box.y * fabs(rayDirectionNormalize.z / rayDirectionNormalize.y),
            m_box.x + m_box.y * fabs(rayDirectionNormalize.x / rayDirectionNormalize.y));

        VfxVector2f point(
            fabs(centerOrigin.z - centerOrigin.y * rayDirectionNormalize.z / rayDirectionNormalize.y),
            fabs(centerOrigin.x - centerOrigin.y * rayDirectionNormalize.x / rayDirectionNormalize.y));

        if (point.x > box.x || point.y > box.y)
        {
            return VFX_FALSE;
        }
    }

    if (rayDirectionNormalize.x != 0.0f)
    {
        VfxVector2f box(
            m_box.y + m_box.x * fabs(rayDirectionNormalize.y / rayDirectionNormalize.x),
            m_box.z + m_box.x * fabs(rayDirectionNormalize.z / rayDirectionNormalize.x));

        VfxVector2f point(
            fabs(centerOrigin.y - centerOrigin.x * rayDirectionNormalize.y / rayDirectionNormalize.x),
            fabs(centerOrigin.z - centerOrigin.x * rayDirectionNormalize.z / rayDirectionNormalize.x));

        if (point.x > box.x || point.y > box.y)
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}

#pragma arm section code, rodata
