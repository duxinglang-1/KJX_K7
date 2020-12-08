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
 *  vfx_texture.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_texture.h"
#include "vfx_render_buffer.h"
#include "vfx_object_list.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxTexture
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("Texture", VfxTexture, VfxTransformable);

VfxTexture::VfxTexture(VfxRenderBuffer *renderBuffer) : 
    m_renderBuffer(renderBuffer), 
    m_levelFilter(VFX_FILTER_BASE_LEVEL), 
    m_imageFilter(VFX_FILTER_LINEAR), 
    m_wrapModeS(VFX_TEXTURE_WRAP_CLAMP), 
    m_wrapModeT(VFX_TEXTURE_WRAP_CLAMP)
{
}


void VfxTexture::disposeHandle() const
{
    if (m_handle)
    {
        if (m_renderBuffer.get())
        {
            m_renderBuffer->disposeHandle();
        }

        VfxObject3D::disposeHandle();
    }
}


void VfxTexture::syncData() const
{
    VfxTransformable::syncData();

    VFX_DEV_ASSERT(m_handle != NULL);
    
    VfxRenderBuffer *rb = m_renderBuffer.get();
    if (isPropertyDirty(VFX_TEXTURE_RENDER_BUFFER_DIRTY))
    {
        vrt_texture_set_image(m_handle, rb ? rb->getSyncHandle() : NULL);
    }
    
    if (rb)
    {
        rb->syncData();
    }

    if (isPropertyDirty(VFX_TEXTURE_FILTER_DIRTY))
    {
        vrt_texture_set_filter(
            m_handle,
            (VrtFilterMode)m_levelFilter,
            (VrtFilterMode)m_imageFilter);
    }

    if (isPropertyDirty(VFX_TEXTURE_WINDING_DIRTY))
    {
        vrt_texture_set_wrapping(
            m_handle,
            (VrtWrapMode)m_wrapModeS,
            (VrtWrapMode)m_wrapModeT);
    }

    clearPropertyDirty(VFX_TEXTURE_ALL_DIRTY);
}


VfxRenderBuffer *VfxTexture::getImage() const
{
    return m_renderBuffer.get();
}


void VfxTexture::setFilter(VfxFilterMode levelFilter, VfxFilterMode imageFilter)
{
    VFX_DEV_ASSERT(imageFilter != VFX_FILTER_BASE_LEVEL);
    m_levelFilter = levelFilter;
    m_imageFilter = imageFilter;
    setPropertyDirty(VFX_TEXTURE_FILTER_DIRTY);
}


void VfxTexture::setWrapping(VfxWrapMode wrapS, VfxWrapMode wrapT)
{
    m_wrapModeS = wrapS;
    m_wrapModeT = wrapT;
    setPropertyDirty(VFX_TEXTURE_WINDING_DIRTY);
}


/***************************************************************************** 
 * Class VfxTexture2D
 *****************************************************************************/

VfxTexture2D::VfxTexture2D(VfxImage2D *image) : 
    VfxTexture(image)
{
}


VfxTexture2D::VfxTexture2D(const VfxWString &imagePath)
{
    VfxImage2D *image;
    VFX_OBJ_CREATE_EX(image, VfxImage2D, this, (imagePath));
    m_renderBuffer = image;
}


VfxTexture2D::VfxTexture2D(const VfxResId resId)
{
    VfxImage2D *image;
    VFX_OBJ_CREATE_EX(image, VfxImage2D, this, (resId));
    m_renderBuffer = image;
}


void VfxTexture2D::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);

    m_handle = vrt_create_texture_2d();
    setPropertyDirty(VFX_TEXTURE_RENDER_BUFFER_DIRTY);
}


/***************************************************************************** 
 * Class VfxTextureCube
 *****************************************************************************/

VfxTextureCube::VfxTextureCube(VfxImageCube *cube) : 
    VfxTexture(cube)
{
}


VfxTextureCube::VfxTextureCube(const VfxWString &imagePath)
{
    VfxImageCube *image;
    VFX_OBJ_CREATE_EX(image, VfxImageCube, this, (imagePath));
    m_renderBuffer = image;
}


VfxTextureCube::VfxTextureCube(const VfxResId resId)
{
    VfxImageCube *image;
    VFX_OBJ_CREATE_EX(image, VfxImageCube, this, (resId));
    m_renderBuffer = image;
}


void VfxTextureCube::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);

    m_handle = vrt_create_texture_cube();
    setPropertyDirty(VFX_TEXTURE_RENDER_BUFFER_DIRTY);
}


/***************************************************************************** 
 * Class VfxTextureFrame
 *****************************************************************************/

VfxTextureFrame::VfxTextureFrame(VfxFrame *frame) : 
    VfxTexture(NULL), 
    m_frame(frame)
{
}


void VfxTextureFrame::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);

    m_handle = vrt_create_texture_frame();
    setPropertyDirty(VFX_TEXTURE_FRAME_FRAME_DIRTY);
}


void VfxTextureFrame::syncData() const
{
    VfxTexture::syncData();

    VFX_DEV_ASSERT(m_handle != NULL);

    VfxFrame *frame = m_frame.get();
    if (frame)
    {
        frame->prepareHandle();
    }

    if (isPropertyDirty(VFX_TEXTURE_FRAME_FRAME_DIRTY))
    {
        vrt_texture_frame_set_frame(m_handle, frame ? frame->getHandle() : NULL);
    }

    clearPropertyDirty(VFX_TEXTURE_FRAME_ALL_DIRTY);
}

