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
 *  vfx_camera.cpp
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

#include "vfx_camera.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxCamera
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Camera", VfxCamera, VfxNode);


void VfxCamera::createHandle() const
{
    m_handle = vrt_create_camera();
}


void VfxCamera::syncData() const
{
    VfxNode::syncData();
    if (isPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY))
    {
        vrt_camera_set_projection(m_handle, (VfxFloat *)&m_projection);
    }

    clearPropertyDirty(VFX_CAMERA_ALL_DIRTY);
}


void VfxCamera::setPerspective(VfxFloat fovy, VfxFloat aspectRatio, VfxFloat n, VfxFloat f)
{
    m_projection.setPerspective(fovy, aspectRatio, n, f);
    m_inverseProjection.setInversePerspective(fovy, aspectRatio, n, f);
    setPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY);
}


void VfxCamera::setParallel(VfxFloat fovy, VfxFloat aspectRatio, VfxFloat n, VfxFloat f)
{
    m_projection.setParallel(fovy, aspectRatio, n, f);
    m_inverseProjection = inverse(m_projection);
    setPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY);
}


void VfxCamera::setGeneric(const VfxMatrix4f& projectionTransform)
{
    m_projection = projectionTransform;
    m_inverseProjection = inverse(projectionTransform);
    setPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY);
}


void VfxCamera::setGeneric(const VfxMatrix4f& projectionTransform, const VfxMatrix4f& inverseProjectionTransform)
{
    m_projection = projectionTransform;
    m_inverseProjection = inverseProjectionTransform;
    setPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY);
}


void VfxCamera::setScreen(VfxFloat x, VfxFloat y, VfxFloat w, VfxFloat h)
{
    m_projection.setScreen(x, y, w, h);
    m_inverseProjection = inverse(m_projection);
    setPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY);
}


void VfxCamera::setScreen(VfxFloat x, VfxFloat y, VfxFloat w, VfxFloat h, VfxFloat n, VfxFloat f)
{
    vrt_float d = f - n;
    m_projection.setScale(2/w, 2/h, 1/d);
    m_inverseProjection = inverse(m_projection);
    setTranslation((x + w / 2), (y + h / 2), n);
    setRotation(VfxQuaternionf(1, 0, 0, 0));
    setPropertyDirty(VFX_CAMERA_PROJECTION_DIRTY);
}


const VfxMatrix4f &VfxCamera::getProjectionMatrix() const
{
    return m_projection;
}


const VfxMatrix4f &VfxCamera::getInverseProjectionMatrix() const
{
    return m_inverseProjection;
}


void VfxCamera::setLookAt(const VfxVector3f& pos, const VfxVector3f& target, const VfxVector3f& up)
{
    VfxMatrix4f m;
    m.setLookAt(pos, target, up);
    setTranslation(m.col[3].xyz());
    m.col[3][0] = 0.0f;
    m.col[3][1] = 0.0f;
    m.col[3][2] = 0.0f;

    setRotation(convert(m));
}


VfxVector3f VfxCamera::unproject(const VfxVector3f &src) const
{
    // inverse view trasform is camera world transform
    VfxMatrix4f inverseView;
    getWorldTransform(inverseView);
    
    VfxVector4f temp = inverseView * (m_inverseProjection * VfxVector4f(src, 1.0f));

    return VfxVector3f(
        temp.x / temp.w,
        temp.y / temp.w,
        temp.z / temp.w);
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

