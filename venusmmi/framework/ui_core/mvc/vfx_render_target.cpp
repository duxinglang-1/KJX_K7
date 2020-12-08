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
 *  vfx_render_target.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_render_target.h"
#include "vfx_render_buffer.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxRenderTarget
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_CLASS("RenderTarget", VfxRenderTarget, VfxObject3D);

VfxRenderTarget::VfxRenderTarget()
: m_clearColor(VFX_COLOR_NULL)
, m_bEnableClearColor(VFX_FALSE)
{
}

VfxRenderTarget::VfxRenderTarget(VfxImage2D *img)
: m_colorBuffer(img)
, m_clearColor(VFX_COLOR_NULL)
, m_bEnableClearColor(VFX_FALSE)
, m_imageType(VFX_IMAGE_TARGET_2D)
{
    setPropertyDirty(VFX_RENDER_TARGET_COLOR_BUFFER_DIRTY);
}

void VfxRenderTarget::createHandle() const
{
    m_handle = vrt_create_render_target();
}

void VfxRenderTarget::syncData() const
{
    VfxObject3D::syncData();

    VfxRenderBuffer *renderBuffer = m_colorBuffer.get();
    if (isPropertyDirty(VFX_RENDER_TARGET_COLOR_BUFFER_DIRTY))
    {
        if (m_imageType == VFX_IMAGE_TARGET_2D)
        {
            vrt_render_target_attach_color_buffer(m_handle, renderBuffer ? renderBuffer->getSyncHandle() : NULL);
        }
        else
        {
            vrt_render_target_attach_cube_face(m_handle, renderBuffer ? renderBuffer->getSyncHandle() : NULL, (VrtImageTargetType)m_imageType);
        }
    }
    
    if (renderBuffer)
    {
        renderBuffer->syncData();
    }


    VfxDepthBuffer *depth = m_depthBuffer.get();
    if (isPropertyDirty(VFX_RENDER_TARGET_DEPTH_BUFFER_DIRTY))
    {
        vrt_render_target_attach_depth_buffer(m_handle, depth ? depth->getSyncHandle() : NULL);
    }
    
    if (depth)
    {
        depth->syncData();
    }

    VfxStencilBuffer *stencil = m_stencilBuffer.get();
    if (isPropertyDirty(VFX_RENDER_TARGET_STENCIL_BUFFER_DIRTY))
    {
        vrt_render_target_attach_stencil_buffer(m_handle, stencil ? stencil->getSyncHandle() : NULL);
    }
    
    if (stencil)
    {
        stencil->syncData();
    }

    if (isPropertyDirty(VFX_RENDER_TARGET_CLEAR_COLOR_DIRTY))
    {
        vrt_render_target_set_clear_color(m_handle, m_clearColor);
    }

    if (isPropertyDirty(VFX_RENDER_TARGET_CLEAR_COLOR_DIRTY))
    {
        vrt_render_target_enable_clear_color(m_handle, m_bEnableClearColor);
    }

    clearPropertyDirty(VFX_RENDER_TARGET_ALL_DIRTY);
}

void VfxRenderTarget::disposeHandle() const
{
    if (m_handle)
    {
        if (m_colorBuffer.get())
        {
            m_colorBuffer->disposeHandle();
        }

        if (m_depthBuffer.get())
        {
            m_depthBuffer->disposeHandle();
        }

        if (m_stencilBuffer.get())
        {
            m_stencilBuffer->disposeHandle();
        }

        VfxObject3D::disposeHandle();
    }
}



VfxImageBase *VfxRenderTarget::getColorBuffer() const
{
    return m_colorBuffer.get();
}

VfxDepthBuffer *VfxRenderTarget::getDepthBuffer() const
{
    return m_depthBuffer.get();
}

VfxStencilBuffer *VfxRenderTarget::getStencilBuffer() const
{
    return m_stencilBuffer.get();
}

VfxBool VfxRenderTarget::attachColorBuffer(VfxImage2D *img)
{
    m_colorBuffer = img;
    m_imageType = VFX_IMAGE_TARGET_2D;
    setPropertyDirty(VFX_RENDER_TARGET_COLOR_BUFFER_DIRTY);
    return VFX_TRUE;    
}

VfxBool VfxRenderTarget::attachColorBuffer(VfxImageCube *cube, VfxImageTargetType type)
{
    VFX_DEV_ASSERT( type >= VFX_IMAGE_TARGET_CUBE_POSITIVE_X &&
                    type <= VFX_IMAGE_TARGET_CUBE_NEGATIVE_Z);

    m_colorBuffer = cube;
    m_imageType = type;
    setPropertyDirty(VFX_RENDER_TARGET_COLOR_BUFFER_DIRTY);
    return VFX_TRUE;
}

VfxBool VfxRenderTarget::attachDepthBuffer(VfxDepthBuffer *depth)
{
    m_depthBuffer = depth;
    setPropertyDirty(VFX_RENDER_TARGET_DEPTH_BUFFER_DIRTY);
    return VFX_TRUE;
}

VfxBool VfxRenderTarget::attachStencilBuffer(VfxStencilBuffer *stencil)
{
    m_stencilBuffer = stencil;
    setPropertyDirty(VFX_RENDER_TARGET_STENCIL_BUFFER_DIRTY);
    return VFX_TRUE;
}

void VfxRenderTarget::setClearColor(VfxColor color)
{
    m_clearColor = color;
    setPropertyDirty(VFX_RENDER_TARGET_CLEAR_COLOR_DIRTY);
}

void VfxRenderTarget::enableClearColor(VfxBool enable)
{
    m_bEnableClearColor = enable;
    setPropertyDirty(VFX_RENDER_TARGET_ENABLE_CLEAR_DIRTY);
}

#pragma arm section code, rodata
