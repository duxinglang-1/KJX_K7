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
 *  vfx_camera.h
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_CAMERA_H__
#define __VFX_CAMERA_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_node.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_CAMERA_BEGIN_FLAG               VFX_NODE_END_FLAG
#define VFX_CAMERA_PROJECTION_DIRTY         (VFX_CAMERA_BEGIN_FLAG << 1)
#define VFX_CAMERA_END_FLAG                 VFX_CAMERA_PROJECTION_DIRTY
#define VFX_CAMERA_ALL_DIRTY                (VFX_CAMERA_PROJECTION_DIRTY)


/***************************************************************************** 
 * Class VfxCamera
 *****************************************************************************/

/*
 * VfxCamera is the camera object in 3D scene.
 */
class VfxCamera : public VfxNode
{
    VFX_DECLARE_CLASS(VfxCamera);

// Override
public:
    virtual void createHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set perspective projection.
    void setPerspective(VfxFloat fovy, VfxFloat aspectRatio, VfxFloat n, VfxFloat f);

    // Set parallel projection.
    void setParallel(VfxFloat fovy, VfxFloat aspectRatio, VfxFloat n, VfxFloat f);

    // Set projection from a generic transform.
    void setGeneric(const VfxMatrix4f& projectionTransform);

    // Set projection from a generic transform and its inverse transform.
    void setGeneric(const VfxMatrix4f& projectionTransform, const VfxMatrix4f& inverseProjectionTransform);

    // Set screen projection.
    void setScreen(VfxFloat x, VfxFloat y, VfxFloat w, VfxFloat h);

    // Set screen projection with znear/zfar.
    void setScreen(VfxFloat x, VfxFloat y, VfxFloat w, VfxFloat h, VfxFloat n, VfxFloat f);

    // Get projection transform matrix.
    const VfxMatrix4f &getProjectionMatrix() const;

    // Get projection inverse transform matrix.
    const VfxMatrix4f &getInverseProjectionMatrix() const;

    // Set camera view transform.
    void setLookAt(const VfxVector3f& pos, const VfxVector3f& target, const VfxVector3f& up);

    //void getViewMatrix(VfxMatrix4f &viewMatrix) const;

    // Un-project vector from view/projection of this camera.
    VfxVector3f unproject(const VfxVector3f &src) const;

// Implementation
protected:
    VfxMatrix4f m_projection;
    VfxMatrix4f m_inverseProjection;
};

#endif /* __VFX_CAMERA_H__ */

