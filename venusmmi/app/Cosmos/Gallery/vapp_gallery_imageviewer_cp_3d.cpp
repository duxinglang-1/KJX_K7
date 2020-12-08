/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_gallery_viewer_3d.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_FTO_GALLERY__) && defined(__VENUS_3D_UI_ENGINE__)
#include "vcui_gallery_gprot.h"
#include "vapp_image_viewer_cp.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_shader.h"
#include "vfx_texture.h"
#include "vfx_render_buffer.h"
#include "vfx_compositing_mode.h"
#include "vfx_polygon_mode.h"

extern "C"
{
#include "MMI_media_app_trc.h"
}

struct VappGalleryViewerSwitchData
{
    VfxSize m_previewImgBufSize;
    VfxSize m_enhancedImgBufSize;
    VfxBool shouldUseEnhance(const VfxSize &previewImgSize) const;
};

VfxBool VappGalleryViewerSwitchData::shouldUseEnhance(const VfxSize &previewImgSize) const
{
    const VfxBool largerThanPreview = previewImgSize.width * previewImgSize.height > GDI_LCD_WIDTH * GDI_LCD_HEIGHT;
    const VfxBool hasEnhance = ((m_enhancedImgBufSize.width > m_previewImgBufSize.width) &&
                               (m_enhancedImgBufSize.height > m_previewImgBufSize.height));
    return largerThanPreview && hasEnhance;
} 

static vrt_render_dirty_type_enum enhancedImgFPECallback(
                        vrt_frame_visual_property_struct *target_frame,
                        const vrt_frame_visual_property_struct *watch_frame,
                        void *user_data,
                        vrt_u32 user_data_size)
{
    VFX_ASSERT(user_data && user_data_size == sizeof(VappGalleryViewerSwitchData));
    const VappGalleryViewerSwitchData &switchData = *(VappGalleryViewerSwitchData*)user_data;
    if(switchData.shouldUseEnhance(watch_frame->bounds.size))
    {
        // keep frame size (to prevent re-generate image cache)
        // and use transform to resize
        const vrt_size_struct frameSize = target_frame->bounds.size;

        // replace other attributes
        *target_frame = *watch_frame;

        // but make sure enhanced version are visible if 
        // we have enlarged the image
        target_frame->opacity = 1.0f;


        return VRT_RENDER_DIRTY_TYPE_DIRTY;

        // calculate transform
        const VfxFloat ratioX = target_frame->bounds.size.width * 1.0f / frameSize.width;
        const VfxFloat ratioY = target_frame->bounds.size.height * 1.0f / frameSize.height;

        // restore frame size
        target_frame->bounds.size = frameSize;

        if(VRT_TRANSFORM_TYPE_IDENTITY == target_frame->transform.type)
        {
            target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
            target_frame->transform.data.affine.sx = ratioX;
            target_frame->transform.data.affine.sy = ratioY;
        }
        else if(VRT_TRANSFORM_TYPE_AFFINE == target_frame->transform.type)
        {
            target_frame->transform.data.affine.sx *= ratioX;
            target_frame->transform.data.affine.sy *= ratioY;
        }
        else
        {
            // don't know how to deal with 3D
            VFX_ASSERT(0);
        }
    }
    else
    {
        // no need to display enhanced image.
        target_frame->opacity = 0.0f;
    }
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

static vrt_render_dirty_type_enum previewImgFPECallback(
                        vrt_frame_visual_property_struct *target_frame,
                        const vrt_frame_visual_property_struct *watch_frame,
                        void *user_data,
                        vrt_u32 user_data_size)
{
    VFX_ASSERT(user_data && user_data_size == sizeof(VappGalleryViewerSwitchData));
    const VappGalleryViewerSwitchData &switchData = *(VappGalleryViewerSwitchData*)user_data;
    // make sure preview version are opacity 0 (not visible)
    // if we have enlarged the image
    if(switchData.shouldUseEnhance(watch_frame->bounds.size))
    {
        target_frame->opacity = 0.0f;
    }
    else
    {
        target_frame->opacity = 1.0f;
    }
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void setupZoomImageFrame(VfxFrame *f, VfxImageBuffer &buf)
{
    // to prevent VRT create a large cache,
    // we set the enhance frame to pure color (no image content)
    // and setup a material with enhance buffer as texture instead.
    // it's important to set content to NULL to supress cache
    f->setImgContent(VFX_IMAGE_SRC_NULL);
    // no cache since we're using material
    f->setCacheMode(VFX_CACHE_MODE_PREVENT);
    f->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    // no background clear color
    f->setBgColor(VFX_COLOR_TRANSPARENT);
    f->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    f->setOpacity(1.0f);
    f->setHidden(VFX_FALSE);

    // 1-pass material that draws enhanced image
    VfxMaterial *mat = NULL;
    VFX_OBJ_CREATE(mat, VfxMaterial, f);
    VfxPass *pass = NULL;
    VFX_OBJ_CREATE(pass, VfxPass, mat);
    mat->setPass(0, pass);

    // turn off z-test and back face culling
    VfxCompositingMode *modeConfig;
    VFX_OBJ_CREATE(modeConfig, VfxCompositingMode, pass);
    modeConfig->setDepthTestEnable(VFX_FALSE);
    modeConfig->setDepthWriteEnable(VFX_FALSE);
    pass->setCompositingMode(modeConfig);
    VfxPolygonMode *polygonMode;
    VFX_OBJ_CREATE(polygonMode, VfxPolygonMode, pass);
    polygonMode->setCulling(VFX_CULLING_NONE);
    pass->setPolygonMode(polygonMode);
    
    // use the enhance buffer as texture
    static const VfxChar vShaderStr[] = \
    "precision mediump float;\n\n"
    "uniform sampler2D uDiffuseSampler;\n"
    "varying vec2 vTexCoord;\n\n"
    "void main()\n"
    "{\n"
    "    vec4 color = texture2D(uDiffuseSampler, vec2(vTexCoord.x, 1.0 - vTexCoord.y));\n"
    "    gl_FragColor = vec4(color.rgb, 1.0);\n"
    "} \n";

    VfxShaderProgram *prog;
    VFX_OBJ_CREATE_EX(prog, VfxShaderProgram, pass, ((VfxChar*)NULL, vShaderStr));
    pass->setShaderProgram(prog);
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxImage2D *img = NULL;
    VfxTexture2D *tex2D = NULL;
    VfxImageSrc enhancedImgSrc(buf);
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (enhancedImgSrc));
    VFX_OBJ_CREATE_EX(tex2D, VfxTexture2D, var, (img));
    var->setValue(tex2D);

    f->setMaterial(mat);
    // notify GL to create a new texture and drop old one
    img->invalidate();
}

void VappGalleryViewerPanel::setupZoomFrames()
{
    // 2D owner draw + SW LT is too slow in Venus3D case.
    // We want to use OpenGL HW to display the image
    // without caching the output.
    // So, we create another frame (m_enhancedImg)
    // that displays the zoom-ed content.
    // We then use FPE callbacks to decide which frame to display.
    VappGalleryViewerSwitchData switchData;
    switchData.m_previewImgBufSize = m_cachedBuffer.getSize();
    switchData.m_enhancedImgBufSize = m_enhancedBuffer.getSize();

    // clear previous material/frame
    VFX_OBJ_CLOSE(m_enhancedImg);

    // clear previous material
    VfxMaterial *oldMaterial = m_previewImg->getMaterial();
    m_previewImg->setMaterial(NULL);
    VFX_OBJ_CLOSE(oldMaterial);
    
    if(m_enhancedBuffer.ptr)
    {
        VFX_OBJ_CREATE(m_enhancedImg, VfxFrame, this);
        m_enhancedImg->setSize(m_enhancedBuffer.getSize());
        setupZoomImageFrame(m_enhancedImg, m_enhancedBuffer);
        // swtich between LCD(previewImg) and enlarged image(enhancedImg)
        m_enhancedImg->setPropertyEffectCallback(
                                        m_previewImg,
                                        &enhancedImgFPECallback,
                                        &switchData,
                                        sizeof(switchData),
                                        VRT_FPE_TRIGGER_TYPE_DIRTY);
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setupZoomImageFrame(m_previewImg, m_cachedBuffer);
    VfxAutoAnimate::commit();
    m_previewImg->setPropertyEffectCallback(
                                        m_previewImg,
                                        &previewImgFPECallback,
                                        &switchData,
                                        sizeof(switchData),
                                        VRT_FPE_TRIGGER_TYPE_DIRTY);
    
    // ViewerPanel need not cache.
    setCacheMode(VFX_CACHE_MODE_PREVENT);
}

void VappGalleryViewerPanel::teardownZoomFrames()
{
    VFX_OBJ_CLOSE(m_enhancedImg);
    VfxMaterial *oldMaterial = m_previewImg->getMaterial();
    m_previewImg->setMaterial(NULL);
    VFX_OBJ_CLOSE(oldMaterial);
    m_previewImg->setPropertyEffectCallback(
                                        NULL,
                                        NULL,
                                        NULL,
                                        0);
    m_previewImg->setCacheMode(VFX_CACHE_MODE_AUTO);
    m_previewImg->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_AUTO);
}

#endif