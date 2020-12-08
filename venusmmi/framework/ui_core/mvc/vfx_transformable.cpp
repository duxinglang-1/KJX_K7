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
 *  vfx_transformable.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vfx_transformable.h"
#include "vrt_3d.h"
#include "vfx_cpp_base.h"
#include "vfx_auto_animate.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

extern "C"
{
vrt_timeline_handle vrt_animatable_search_property_timeline(vrt_object_handle object_handle, vrt_object_property_id_enum property_id);
}


/***************************************************************************** 
 * Class VfxTransformable
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_VIRTUAL_CLASS("Transformable", VfxTransformable, VfxObject3D);

VfxVector3f VfxTransformable::s_defTranslation;
VfxQuaternionf VfxTransformable::s_defOrientation;
VfxVector3f VfxTransformable::s_defScale(1);
VfxMatrix4f VfxTransformable::s_defPivot;

VfxTransformable::VfxTransformable()
: m_orientation(NULL)
, m_scale(NULL)
, m_pivot(NULL)
{
}

VfxTransformable::~VfxTransformable()
{
    VFX_FREE_MEM(m_orientation);
    VFX_FREE_MEM(m_scale);
    VFX_FREE_MEM(m_pivot);
}

void VfxTransformable::resetProperty(vrt_object_property_id_enum propertyId)
{
    switch (propertyId)
    {
    case VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION:
        setPropertyDirty(VFX_TRANSFORMABLE_TRANSLATION_DIRTY);
        break;
    case VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION:
        setPropertyDirty(VFX_TRANSFORMABLE_ORIENTATION_DIRTY);
        break;
    case VRT_TRANSFORMABLE_PROPERTY_ID_SCALE:
        setPropertyDirty(VFX_TRANSFORMABLE_SCALE_DIRTY);
        break;
    case VRT_TRANSFORMABLE_PROPERTY_ID_PIVOT:
        setPropertyDirty(VFX_TRANSFORMABLE_PIVOT_DIRTY);
        break;
    default:
        // No animatable property in VfxObject3D
        //VfxObject3D::resetProperty(propertyId);
        break;
    }
}

void VfxTransformable::syncData() const
{
    VfxObject3D::syncData();

    if (isPropertyDirty(VFX_TRANSFORMABLE_ALL_DIRTY))
    {
        const VfxVector3f *t = &m_translation;
        const VfxQuaternionf *r = m_orientation;
        const VfxVector3f *s = m_scale;
        const VfxMatrix4f *m = m_pivot;
        vrt_timeline_handle timeline;
        vrt_object_handle object_handle = getSyncHandle();

        // t * r * s * p
        VfxMatrix4f transform;
        VfxBool bSetTransform = VFX_FALSE;

        /* pivot */
        if (m)
        {
            transform = *m;
            bSetTransform = VFX_TRUE;
        }

        /* Find if there is a property timeline exist */
        timeline = vrt_animatable_search_property_timeline(object_handle, VRT_TRANSFORMABLE_PROPERTY_ID_PIVOT);
        if (isPropertyDirty(VFX_TRANSFORMABLE_PIVOT_DIRTY) && (timeline == NULL))
        {
            vrt_transformable_set_pivot(m_handle, (vrt_float *)(m ? m : &s_defPivot));
        }

        /* scale */
        if (s)
        {
            if (bSetTransform)
            {
                transform.scale(*s);
            }
            else
            {
                transform.setScale(*s);
                bSetTransform = VFX_TRUE;
            }
        }

        /* Find if there is a property timeline exist */
        timeline = vrt_animatable_search_property_timeline(object_handle, VRT_TRANSFORMABLE_PROPERTY_ID_SCALE);
        if (isPropertyDirty(VFX_TRANSFORMABLE_SCALE_DIRTY) && (timeline == NULL))
        {
            vrt_transformable_set_scale(m_handle, (vrt_float *)(s ? s : &s_defScale));
        }

        /* orientation */
        if (r)
        {
            if (bSetTransform)
            {
                transform.rotate(*r);
            }
            else
            {
                transform.setRotation(*r);
                bSetTransform = VFX_TRUE;
            }
        }

        /* Find if there is a property timeline exist */
        timeline = vrt_animatable_search_property_timeline(object_handle, VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        if (isPropertyDirty(VFX_TRANSFORMABLE_ORIENTATION_DIRTY) && (timeline == NULL))
        {
            vrt_transformable_set_orientation(m_handle, (vrt_float *)(r ? r : &s_defOrientation));
        }

        /* translation */
        if (t)
        {
            if (bSetTransform)
            {
                transform.translate(*t);
            }
            else
            {
                transform.setTranslation(*t);
            }
        }

        /* Find if there is a property timeline exist */
        timeline = vrt_animatable_search_property_timeline(object_handle, VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        if (isPropertyDirty(VFX_TRANSFORMABLE_TRANSLATION_DIRTY) && (timeline == NULL))
        {
            vrt_transformable_set_translation(m_handle, (vrt_float *)(t ? t : &s_defTranslation));
        }

        /* composite transform */
        vrt_transformable_set_transform(m_handle, (VfxFloat *)&transform);

        clearPropertyDirty(VFX_TRANSFORMABLE_ALL_DIRTY);
    }
}


/* translation */
void VfxTransformable::setTranslation(const VfxVector3f &trans)
{
    if (getTranslation() != trans)
    {
        const VrtVector3f &fromValue = getTranslation();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION,
            &fromValue,
            &trans,
            sizeof(trans));

        m_translation = trans;
        setPropertyDirty(VFX_TRANSFORMABLE_TRANSLATION_DIRTY);
    }
}


void VfxTransformable::forceGetTranslation(VfxVector3f &translation) const
{
    if (m_handle == NULL)
    {
        translation = getTranslation();
        return;
    }

    vrt_transformable_get_translation(m_handle, (vrt_float *)&translation);
}


void VfxTransformable::forceSetTranslation(const VfxVector3f &trans)
{
    if (m_handle == NULL)
    {
        setTranslation(trans);
        return;
    }
    
    if (getTranslation() != trans)
    {
        m_translation = trans;
        vrt_object_force_set_property_value(
            m_handle, 
            VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION,
            &trans, 
            sizeof(trans));
    }
}


void VfxTransformable::translate(const VfxVector3f &trans)
{
    if (trans != s_defTranslation)
    {
        const VfxVector3f *t = &m_translation;
        VfxVector3f newtrans = trans;
        if(t)
        {
            newtrans = (*t)+trans;
        }

        VrtVector3f fromValue = getTranslation();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION,
            &fromValue,
            &newtrans,
            sizeof(newtrans));

        m_translation = newtrans;
        setPropertyDirty(VFX_TRANSFORMABLE_TRANSLATION_DIRTY);
    }
}

/* orientation */
void VfxTransformable::setRotationX(VfxFloat angle)
{
    angle /= 2;
    setRotation(VfxQuaternionf(VfxVector3f(vfxSin(angle), 0, 0), vfxCos(angle)));
}

void VfxTransformable::setRotationY(VfxFloat angle)
{
    angle /= 2;
    setRotation(VfxQuaternionf(VfxVector3f(0, vfxSin(angle), 0), vfxCos(angle)));
}

void VfxTransformable::setRotationZ(VfxFloat angle)
{
    angle /= 2;
    setRotation(VfxQuaternionf(VfxVector3f(0, 0, vfxSin(angle)), vfxCos(angle)));
}

void VfxTransformable::setRotation(const VfxVector3f &axis, VfxFloat angle)
{
    angle /= 2;
    setRotation(VfxQuaternionf(axis * vfxSin(angle), vfxCos(angle)));
}


void VfxTransformable::setRotation(const VfxQuaternionf &quat)
{
    if (getRotation() != quat)
    {
        const VrtQuaternionf &fromValue = getRotation();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION,
            &fromValue,
            &quat,
            sizeof(quat));

        setRotationInternal(quat);
        setPropertyDirty(VFX_TRANSFORMABLE_ORIENTATION_DIRTY);
    }
}

const VfxQuaternionf &VfxTransformable::getRotation() const
{
    if(m_orientation)
        return *m_orientation;
    else
        return s_defOrientation;
}

void VfxTransformable::setRotationInternal(const VfxQuaternionf &quat)
{
    if(quat == s_defOrientation)
    {
        VFX_FREE_MEM(m_orientation);
    }
    else
    {
        if (m_orientation == NULL)
        {
            VFX_ALLOC_MEM(m_orientation, sizeof(VfxQuaternionf), this);
        }
        *m_orientation = quat;
    }
}

void VfxTransformable::forceGetRotation(VfxQuaternionf &rotation) const
{
    if (m_handle == NULL)
    {
        rotation = getRotation();
        return;
    }

    vrt_transformable_get_orientation(m_handle, (vrt_float *)&rotation);
}

void VfxTransformable::forceSetRotation(const VfxQuaternionf &quat)
{
    if (m_handle == NULL)
    {
        setRotation(quat);
        return;
    }
    
    if (getRotation() != quat)
    {
        setRotationInternal(quat);
        vrt_object_force_set_property_value(
            m_handle, 
            VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION,
            &quat, 
            sizeof(quat));
    }
}

void VfxTransformable::rotateX(VfxFloat angle)
{
    angle /= 2;
    rotate(VfxQuaternionf(VfxVector3f(vfxSin(angle), 0, 0), vfxCos(angle)));
}

void VfxTransformable::rotateY(VfxFloat angle)
{
    angle /= 2;
    rotate(VfxQuaternionf(VfxVector3f(0, vfxSin(angle), 0), vfxCos(angle)));
}

void VfxTransformable::rotateZ(VfxFloat angle)
{
    angle /= 2;
    rotate(VfxQuaternionf(VfxVector3f(0, 0, vfxSin(angle)), vfxCos(angle)));
}

void VfxTransformable::rotate(const VfxVector3f &axis, VfxFloat angle)
{
    angle /= 2;
    rotate(VfxQuaternionf(axis * vfxSin(angle), vfxCos(angle)));
}

void VfxTransformable::rotate(const VfxQuaternionf &quat)
{
    if (quat != s_defOrientation)
    {
        const VfxQuaternionf *q = m_orientation;
        VfxQuaternionf newquat = quat;            
        if(q)
        {
            newquat = (quat*(*q));
        }

        VrtQuaternionf fromValue = getRotation();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION,
            &fromValue,
            &newquat,
            sizeof(newquat));

        setRotationInternal(newquat);
        setPropertyDirty(VFX_TRANSFORMABLE_ORIENTATION_DIRTY);
    }
}


void VfxTransformable::localRotateX(VfxFloat angle)
{
    angle /= 2;
    localRotate(VfxQuaternionf(VfxVector3f(vfxSin(angle), 0, 0), vfxCos(angle)));
}

void VfxTransformable::localRotateY(VfxFloat angle)
{
    angle /= 2;
    localRotate(VfxQuaternionf(VfxVector3f(0, vfxSin(angle), 0), vfxCos(angle)));
}

void VfxTransformable::localRotateZ(VfxFloat angle)
{
    angle /= 2;
    localRotate(VfxQuaternionf(VfxVector3f(0, 0, vfxSin(angle)), vfxCos(angle)));
}

void VfxTransformable::localRotate(const VfxVector3f &axis, VfxFloat angle)
{
    angle /= 2;
    localRotate(VfxQuaternionf(axis * vfxSin(angle), vfxCos(angle)));
}

void VfxTransformable::localRotate(const VfxQuaternionf &quat)
{
    if (quat != s_defOrientation)
    {
        const VfxQuaternionf *q = m_orientation;
        VfxQuaternionf newquat = quat;
        if(q)
        {
            newquat = ((*q)*quat);
        }

        VrtQuaternionf fromValue = getRotation();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION,
            &fromValue,
            &newquat,
            sizeof(newquat));

        setRotationInternal(newquat);
        setPropertyDirty(VFX_TRANSFORMABLE_ORIENTATION_DIRTY);
    }
}



/* scale */
void VfxTransformable::setScale(const VfxVector3f &scale)
{
    if (getScale() != scale)
    {
        const VrtVector3f &fromValue = getScale();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_SCALE,
            &fromValue,
            &scale,
            sizeof(scale));

        setScaleInternal(scale);
        setPropertyDirty(VFX_TRANSFORMABLE_SCALE_DIRTY);
    }
}

const VfxVector3f &VfxTransformable::getScale() const
{
    if(m_scale)
        return *m_scale;
    else
        return s_defScale;
}

void VfxTransformable::setScaleInternal(const VfxVector3f &scale)
{
    if(scale == s_defScale)
    {
        VFX_FREE_MEM(m_scale);
    }
    else
    {
        if (m_scale == NULL)
        {
            VFX_ALLOC_MEM(m_scale, sizeof(VfxVector3f), this);
        }
        *m_scale = scale;
    }
}

void VfxTransformable::forceGetScale(VfxVector3f &scale) const
{
    if (m_handle == NULL)
    {
        scale = getScale();
        return;
    }

    vrt_transformable_get_scale(m_handle, (vrt_float *)&scale);
}

void VfxTransformable::forceSetScale(const VfxVector3f &scale)
{
    if (m_handle == NULL)
    {
        setScale(scale);
        return;
    }
    
    if (getScale() != scale)
    {
        setScaleInternal(scale);
        vrt_object_force_set_property_value(
            m_handle, 
            VRT_TRANSFORMABLE_PROPERTY_ID_SCALE,
            &scale, 
            sizeof(scale));
    }
}

void VfxTransformable::scale(const VfxVector3f &scale)
{
    if (scale != s_defScale)
    {
        const VfxVector3f *s = m_scale;
        VfxVector3f newscale = scale;
        if(s)
        {
            newscale = ((*s)*scale);
        }

        const VrtVector3f &fromValue = getScale();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_SCALE,
            &fromValue,
            &newscale,
            sizeof(newscale));

        setScaleInternal(newscale);
        setPropertyDirty(VFX_TRANSFORMABLE_SCALE_DIRTY);
    }
}

/* pivot */
void VfxTransformable::setPivot(const VfxMatrix4f &pivot)
{
    if (getPivot() != pivot)
    {
        const VrtMatrix4f &fromValue = getPivot();
        VfxAutoAnimate::setAnimatableProperty(
            this,
            VRT_TRANSFORMABLE_PROPERTY_ID_PIVOT,
            &fromValue,
            &pivot,
            sizeof(pivot));

        setPivotInternal(pivot);
        setPropertyDirty(VFX_TRANSFORMABLE_PIVOT_DIRTY);
    }
}

const VfxMatrix4f &VfxTransformable::getPivot() const
{
    if(m_pivot)
        return *m_pivot;
    else
        return s_defPivot;
}

void VfxTransformable::setPivotInternal(const VfxMatrix4f &pivot)
{
    if(pivot == s_defPivot)
    {
        VFX_FREE_MEM(m_pivot);
    }
    else
    {
        if (m_pivot == NULL)
        {
            VFX_ALLOC_MEM(m_pivot, sizeof(VfxMatrix4f), this);
        }
        *m_pivot = pivot;
    }
}

void VfxTransformable::forceGetPivot(VfxMatrix4f &pivot) const
{
    if (m_handle == NULL)
    {
        pivot = getPivot();
        return;
    }

    vrt_transformable_get_pivot(m_handle, (vrt_float *)&pivot);
}


void VfxTransformable::forceSetPivot(const VfxMatrix4f &pivot)
{
    if (m_handle == NULL)
    {
        setPivot(pivot);
        return;
    }

    if (getPivot() != pivot)
    {
        setPivotInternal(pivot);
        vrt_object_force_set_property_value(
            m_handle, 
            VRT_TRANSFORMABLE_PROPERTY_ID_PIVOT,
            &pivot, 
            sizeof(pivot));
    }
}


/* transform */
void VfxTransformable::getTransform(VfxMatrix4f &transform) const
{
    VfxBool isSetTransform = VFX_FALSE;
    VfxMatrix4f *p = m_pivot;
    if (p)
    {
        transform = *p;
        isSetTransform = VFX_TRUE;
    }

    VfxVector3f *s = m_scale;
    if (s)
    {
        if (isSetTransform)
        {
            transform.scale(*s);
        }
        else
        {
            transform.setScale(*s);
            isSetTransform = VFX_TRUE;
        }
    }

    VfxQuaternionf *r = m_orientation;
    if (r)
    {
        if (isSetTransform)
        {
            transform.rotate(*r);
        }
        else
        {
            transform.setRotation(*r);
            isSetTransform = VFX_TRUE;
        }
    }

    const VfxVector3f *t = &m_translation;
    if (t)
    {
        if (isSetTransform)
        {
            transform.translate(*t);
        }
        else
        {
            transform.setTranslation(*t);
        }
    }
}

void VfxTransformable::forceGetTransform(VfxMatrix4f &transform) const
{
    if (m_handle == NULL)
    {
        getTransform(transform);
        return;
    }

    vrt_transformable_get_transform(m_handle, (vrt_float *)&transform);
}

#pragma arm section code, rodata

