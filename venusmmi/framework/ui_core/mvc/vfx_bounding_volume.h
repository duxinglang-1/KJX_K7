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
 *  vfx_bounding_volume.h
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
#ifndef __VFX_BOUNDING_VOLUME_H__
#define __VFX_BOUNDING_VOLUME_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
// For VfxVector3f
#include "vfx_vector.h"


/***************************************************************************** 
 * Class VfxBoundingVolume
 *****************************************************************************/

#define VFX_BOUNDING_VOLUME_TEST_FLAGS_NONE     (0)
#define VFX_BOUNDING_VOLUME_TEST_FLAGS_SPHERE   (1 << 0)
#define VFX_BOUNDING_VOLUME_TEST_FLAGS_BOX      (1 << 1)
#define VFX_BOUNDING_VOLUME_TEST_FLAGS_ALL      (VFX_BOUNDING_VOLUME_TEST_FLAGS_SPHERE | VFX_BOUNDING_VOLUME_TEST_FLAGS_BOX)



/***************************************************************************** 
 * Class VfxBoundingVolume
 *****************************************************************************/

class VfxBoundingVolume : public VfxBase
{
// Variable
public:
    VfxFlag     m_testFlags;    // Testing flags
    VfxVector3f m_center;       // vector to the center of bounding sphere and box
    VfxFloat    m_radius2;      // radius square of bounding sphere 
    VfxVector3f m_box;          // vector to the positive conrer of bounding box

// Constructor / Destructor
public:
    // Default constructor
    VfxBoundingVolume();
    
    VfxBoundingVolume(VfxVector3f center, VfxFloat radius2, VfxVector3f box);

    VfxBoundingVolume(VfxVector3f center, VfxVector3f box);
    
    VfxBoundingVolume(VfxVector3f center, VfxFloat radius2);
    
    // Copy constructor
    VfxBoundingVolume(const VfxBoundingVolume &other);

// Method        
public:
    // Intersect the ray direction with bounding box and sphere
    VfxBool intersectWithDirRay(
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;

    // Intersect the ray direction with bounding sphere
    VfxBool intersetSphereWithDirRay(
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;

    // Intersect the ray direction with bounding box    
    VfxBool intersetBoxWithDirRay(
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;

// Implementation
private:
    VfxBool intersectWithDirRayInt(
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;

    VfxBool intersetSphereWithDirRayInt(
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;
    
    VfxBool intersetBoxWithDirRayInt(
        const VfxVector3f &rayOrigin, 
        const VfxVector3f &rayDirection
    ) const;
    
    VfxBool interSphere(
        const VfxVector3f &centerPoint  // [IN] the point relative m_center
    ) const;
    
    VfxBool interBox(
        const VfxVector3f &centerPoint  // [IN] the point relative m_center
    ) const;    

    VfxBool intersetBoxWithNormalizedDirRay(
        const VfxVector3f &centerOrigin,
        const VfxVector3f &rayDirectionNormalize
    ) const;
};

#endif /* __VFX_BOUNDING_VOLUME_H__ */

