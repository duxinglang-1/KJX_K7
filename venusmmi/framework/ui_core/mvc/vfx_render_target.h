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
 *  vfx_render_target.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_RENDER_TARGET_H__
#define __VFX_RENDER_TARGET_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_basic_type.h"
#include "vfx_3d_enum.h"
#include "vfx_weak_ptr.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxImageBase;
class VfxImage2D;
class VfxImageCube;
class VfxDepthBuffer;
class VfxStencilBuffer;


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_RENDER_TARGET_BEGIN_FLAG            (VFX_OBJECT3D_END_FLAG)
#define VFX_RENDER_TARGET_COLOR_BUFFER_DIRTY    (VFX_RENDER_TARGET_BEGIN_FLAG << 1)
#define VFX_RENDER_TARGET_DEPTH_BUFFER_DIRTY    (VFX_RENDER_TARGET_BEGIN_FLAG << 2)
#define VFX_RENDER_TARGET_STENCIL_BUFFER_DIRTY  (VFX_RENDER_TARGET_BEGIN_FLAG << 3)
#define VFX_RENDER_TARGET_CLEAR_COLOR_DIRTY     (VFX_RENDER_TARGET_BEGIN_FLAG << 4)
#define VFX_RENDER_TARGET_ENABLE_CLEAR_DIRTY    (VFX_RENDER_TARGET_BEGIN_FLAG << 5)
#define VFX_RENDER_TARGET_END_FLAG              (VFX_RENDER_TARGET_CLEAR_COLOR_DIRTY)
#define VFX_RENDER_TARGET_ALL_DIRTY             (VFX_RENDER_TARGET_COLOR_BUFFER_DIRTY | VFX_RENDER_TARGET_DEPTH_BUFFER_DIRTY | VFX_RENDER_TARGET_STENCIL_BUFFER_DIRTY | VFX_RENDER_TARGET_CLEAR_COLOR_DIRTY | VFX_RENDER_TARGET_ENABLE_CLEAR_DIRTY)


/***************************************************************************** 
 * Class VfxRenderTarget
 *****************************************************************************/

/*
 * VfxRenderTarget is the render target in 3D material pass.
 */
class VfxRenderTarget : public VfxObject3D
{
    VFX_DECLARE_CLASS(VfxRenderTarget);

// Constructor / Destructor
public:
    // Default constructor
    VfxRenderTarget();

    // Constructor with image2D color buffer
    VfxRenderTarget(VfxImage2D *img);

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Get the image target type.
    VfxImageTargetType getImageType() const;

    // Get the color buffer of the render target.
    VfxImageBase *getColorBuffer() const;

    // Get the depth buffer of the render target.
    VfxDepthBuffer *getDepthBuffer() const;

    // Get the stencil buffer of the render target.
    VfxStencilBuffer *getStencilBuffer() const;

    // Attach a image2D color buffer to the render target.
    VfxBool attachColorBuffer(VfxImage2D *img);

    // Attach a imageCube color buffer to the render target.
    VfxBool attachColorBuffer(VfxImageCube *cube, VfxImageTargetType type);

    // Attach a depth buffer to the render target.
    VfxBool attachDepthBuffer(VfxDepthBuffer *depth);

    // Attach a stencil buffer to the render target.
    VfxBool attachStencilBuffer(VfxStencilBuffer *stencil);

    // Set clear color of the color buffer.
    //
    // NOTE: Default value is VFX_COLOR_NULL.
    void setClearColor(VfxColor color);

    // Get clear color of the color buffer.
    //
    // NOTE: Default value is VFX_COLOR_NULL.
    VfxColor getClearColor() const;

    // Set clear color enable.
    //
    // NOTE: Default value is VFX_FALSE.
    void enableClearColor(VfxBool enable);

    // Whether clear color is enabled.
    //
    // NOTE: Default value is VFX_FALSE.
    VfxBool isEnableClearColor() const;

// Implementation
protected:

    VfxWeakPtr< VfxImageBase > m_colorBuffer;
    VfxWeakPtr< VfxDepthBuffer > m_depthBuffer;
    VfxWeakPtr< VfxStencilBuffer > m_stencilBuffer;
    VfxColor m_clearColor;
    VfxBool m_bEnableClearColor;
    VfxImageTargetType m_imageType;

};



/***************************************************************************** 
 * Implementation
 *****************************************************************************/
inline VfxImageTargetType VfxRenderTarget::getImageType() const
{
    return m_imageType;
}

inline VfxColor VfxRenderTarget::getClearColor() const
{
    return m_clearColor;
}

inline VfxBool VfxRenderTarget::isEnableClearColor() const
{
    return m_bEnableClearColor;
}


#endif /* __VFX_RENDER_TARGET_H__ */

