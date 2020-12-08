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
 *  vfx_transformable.h
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
#ifndef __VFX_TRANSFORMABLE_H__
#define __VFX_TRANSFORMABLE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_vector.h"
#include "vfx_matrix.h"
#include "vfx_quaternion.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_TRANSFORMABLE_BEGIN_FLAG            (VFX_OBJECT3D_END_FLAG)
#define VFX_TRANSFORMABLE_TRANSLATION_DIRTY     (VFX_TRANSFORMABLE_BEGIN_FLAG << 1)
#define VFX_TRANSFORMABLE_ORIENTATION_DIRTY     (VFX_TRANSFORMABLE_BEGIN_FLAG << 2)
#define VFX_TRANSFORMABLE_SCALE_DIRTY           (VFX_TRANSFORMABLE_BEGIN_FLAG << 3)
#define VFX_TRANSFORMABLE_PIVOT_DIRTY           (VFX_TRANSFORMABLE_BEGIN_FLAG << 4)
#define VFX_TRANSFORMABLE_END_FLAG              (VFX_TRANSFORMABLE_PIVOT_DIRTY)
#define VFX_TRANSFORMABLE_ALL_DIRTY             (VFX_TRANSFORMABLE_TRANSLATION_DIRTY | VFX_TRANSFORMABLE_ORIENTATION_DIRTY | VFX_TRANSFORMABLE_SCALE_DIRTY | VFX_TRANSFORMABLE_PIVOT_DIRTY)


/***************************************************************************** 
 * Class VfxTransformable
 *****************************************************************************/

/*
 * VfxTransformable is the base class of 3D transformable object.
 */
class VfxTransformable : public VfxObject3D
{
    VFX_DECLARE_CLASS(VfxTransformable);

public:
    friend class VfxAutoAnimate;

// Constructor / Destructor
public:
    // Default constructor
    VfxTransformable();
    // Destructor
    virtual ~VfxTransformable();

// Override
public:
    virtual void resetProperty(vrt_object_property_id_enum propertyId);

    virtual void syncData() const;

// Property
public:
    /* translation */

    // Set translation of the object.
    void setTranslation(VfxFloat x, VfxFloat y, VfxFloat z);

    // Set translation of the object.
    void setTranslation(const VfxVector3f &translation);

    // Get translation of the object.
    const VfxVector3f &getTranslation() const;

    // Forcely get current translation, even in animation.
    void forceGetTranslation(VfxVector3f &translation) const;

    // Forcely set current translation, even in animation.
    void forceSetTranslation(const VfxVector3f &trans);

    // Translate the object from the last translation.
    void translate(VfxFloat x, VfxFloat y, VfxFloat z);

    // Translate the object from the last translation.
    void translate(const VfxVector3f &translation);

    /* orientation */

    // Set rotation of the object.
    void setRotationX(VfxFloat angle);

    // Set rotation of the object.
    void setRotationY(VfxFloat angle);

    // Set rotation of the object.
    void setRotationZ(VfxFloat angle);

    // Set rotation of the object.
    void setRotation(const VfxVector3f &axis, VfxFloat angle);

    // Set rotation of the object.
    void setRotation(const VfxQuaternionf &quaternion);

    // Get rotation of the object.
    const VfxQuaternionf &getRotation() const;

    // Forcely get current rotation, even in animation.
    void forceGetRotation(VfxQuaternionf &quaternion) const;

    // Forcely set current rotation, even in animation.
    void forceSetRotation(const VfxQuaternionf &quat);

    // Rotate the object from the last rotation.
    void rotateX(VfxFloat angle);

    // Rotate the object from the last rotation.
    void rotateY(VfxFloat angle);

    // Rotate the object from the last rotation.
    void rotateZ(VfxFloat angle);

    // Rotate the object from the last rotation.
    void rotate(const VfxVector3f &axis, VfxFloat angle);

    // Rotate the object from the last rotation.
    void rotate(const VfxQuaternionf &quaternion);

    // Local-rotate the object from the last rotation.
    void localRotateX(VfxFloat angle);

    // Local-rotate the object from the last rotation.
    void localRotateY(VfxFloat angle);

    // Local-rotate the object from the last rotation.
    void localRotateZ(VfxFloat angle);

    // Local-rotate the object from the last rotation.
    void localRotate(const VfxVector3f &axis, VfxFloat angle);

    // Local-rotate the object from the last rotation.
    void localRotate(const VfxQuaternionf &quaternion);

    /* scale */

    // Set scale of the object.
    void setScale(VfxFloat scale);

    // Set scale of the object.
    void setScale(VfxFloat x, VfxFloat y, VfxFloat z);

    // Set scale of the object.
    void setScale(const VfxVector3f &scale);

    // Get scale of the object.
    const VfxVector3f &getScale() const;

    // Forcely get current scale, even in animation.
    void forceGetScale(VfxVector3f &scale) const;

    // Forcely set current scale, even in animation.
    void forceSetScale(const VfxVector3f &scale);

    // Scale the object from the last scale.
    void scale(VfxFloat scale);

    // Scale the object from the last scale.
    void scale(VfxFloat x, VfxFloat y, VfxFloat z);

    // Scale the object from the last scale.
    void scale(const VfxVector3f &scale);

    /* pivot */

    // Set pivot of the object.
    void setPivot(const VfxMatrix4f &pivot);

    // Get pivot of the object.
    const VfxMatrix4f &getPivot() const;

    // Forcely get current pivot, even in animation.
    void forceGetPivot(VfxMatrix4f &pivot) const;

    // Forcely set current pivot, even in animation.
    void forceSetPivot(const VfxMatrix4f &pivot);

    /* transform */

    // Get transform of the object.
    void getTransform(VfxMatrix4f &transform) const;

    // Forcely get current transform, even in animation.
    void forceGetTransform(VfxMatrix4f &transform) const;

// Implementation
protected:

    void setRotationInternal(const VfxQuaternionf &quat);
    void setScaleInternal(const VfxVector3f &scale);
    void setPivotInternal(const VfxMatrix4f &pivot);

    VfxVector3f m_translation;
    VfxQuaternionf *m_orientation;
    VfxVector3f *m_scale;
    VfxMatrix4f *m_pivot;

    static VfxVector3f s_defTranslation;
    static VfxQuaternionf s_defOrientation;
    static VfxVector3f s_defScale;
    static VfxMatrix4f s_defPivot;
};


inline const VfxVector3f &VfxTransformable::getTranslation() const
{
    return m_translation;
}

inline void VfxTransformable::setTranslation(VfxFloat x, VfxFloat y, VfxFloat z)
{
    setTranslation(VfxVector3f(x, y, z));
}

inline void VfxTransformable::translate(VfxFloat x, VfxFloat y, VfxFloat z)
{
    translate(VfxVector3f(x, y, z));
}

inline void VfxTransformable::setScale(VfxFloat scale)
{
    setScale(VfxVector3f(scale));
}

inline void VfxTransformable::setScale(VfxFloat x, VfxFloat y, VfxFloat z)
{
    setScale(VfxVector3f(x, y, z));
}

inline void VfxTransformable::scale(VfxFloat s)
{
    scale(VfxVector3f(s));
}

inline void VfxTransformable::scale(VfxFloat x, VfxFloat y, VfxFloat z)
{
    scale(VfxVector3f(x, y, z));
}

#endif /* __VFX_TRANSFORMABLE_H__ */

