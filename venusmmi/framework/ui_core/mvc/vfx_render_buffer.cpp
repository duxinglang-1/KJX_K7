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
 *  vfx_render_buffer.cpp
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

#include "vfx_render_buffer.h"
#include "vrt_3d.h"

extern "C"
{
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "gdi_include.h"
// for mmi_fe_color and mmi_fe_xxx()
#include "PixcomFontEngine.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

// TODO: only vector font needs PARGB8888
#define VFX_IMAGE_TEXT_COLOR_FORMAT     VRT_COLOR_TYPE_PARGB8888


#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

/***************************************************************************** 
 * Static function
 *****************************************************************************/

static gdi_color_format vrt_cf_to_gdi_cf(vrt_color_type_enum cf)
{
    switch (cf)
    {
    case VRT_COLOR_TYPE_RGB565:
        return GDI_COLOR_FORMAT_16;
    case VRT_COLOR_TYPE_ARGB8888:
        return GDI_COLOR_FORMAT_32;
    case VRT_COLOR_TYPE_PARGB8888:
        return GDI_COLOR_FORMAT_32_PARGB;
    case VRT_COLOR_TYPE_RGB888:
        return GDI_COLOR_FORMAT_24;    
    case VRT_COLOR_TYPE_A8:
        return GDI_COLOR_FORMAT_A8;
    case VRT_COLOR_TYPE_UYVY422:
        return GDI_COLOR_FORMAT_UYVY422;
    case VRT_COLOR_TYPE_PARGB6666:
        return GDI_COLOR_FORMAT_PARGB6666;
    default:
        VRT_DEV_ASSERT(0);
    }
    return 0;
}


/***************************************************************************** 
 * Class VfxRenderBuffer
 *****************************************************************************/

VfxRenderBuffer::VfxRenderBuffer(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat) : 
    m_width(w), 
    m_height(h), 
    m_colorFormat(colorFormat)
{
}


void VfxRenderBuffer::setSize(VfxU32 w, VfxU32 h)
{
    m_width = w;
    m_height = h;
}


/***************************************************************************** 
 * Class VfxImageBase
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VfxImageBase", VfxImageBase, VfxRenderBuffer);

VfxImageBase::VfxImageBase(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat)
: VfxRenderBuffer(w, h, colorFormat)
{
}


VfxImageBase::VfxImageBase(const VfxImageSrc &imageSrc)
: VfxRenderBuffer(0, 0, VRT_COLOR_TYPE_UNKNOWN)
, m_imageSrc(imageSrc)
{
}


VfxImageBase::VfxImageBase(const VfxWString &imagePath)
: VfxRenderBuffer(0, 0, VRT_COLOR_TYPE_UNKNOWN)
, m_imageSrc(imagePath)
{
}


VfxImageBase::VfxImageBase(const VfxResId resId)
: VfxRenderBuffer(0, 0, VRT_COLOR_TYPE_UNKNOWN)
, m_imageSrc(resId)
{
}


void VfxImageBase::invalidate()
{
    setPropertyDirty(VFX_IMAGEBASE_CONTENT_DIRTY);
}


void VfxImageBase::syncData() const
{
    VfxRenderBuffer::syncData();

    if (isPropertyDirty(VFX_IMAGEBASE_CONTENT_DIRTY))
    {
        switch (m_imageSrc.getType())
        {
        case VFX_IMAGE_SRC_TYPE_NULL:
            vrt_image_base_invalidate(m_handle, m_width, m_height, m_colorFormat);
            break;
        default:
            vrt_image_base_invalidate_from_source(m_handle);
        }
    }

    clearPropertyDirty(VFX_IMAGEBASE_ALL_DIRTY);
}


void VfxImageBase::destroy() const
{
    // do not invalidate an image unless it is explicitly set
    VfxBool is_valid = !isPropertyDirty(VFX_IMAGEBASE_CONTENT_DIRTY);

    VfxRenderBuffer::destroy();

    if (is_valid)
    {
        clearPropertyDirty(VFX_IMAGEBASE_CONTENT_DIRTY);
    }
}


void VfxImageBase::disposeHandle() const
{
    // do not invalidate an image unless it is explicitly set
    VfxBool is_valid = !isPropertyDirty(VFX_IMAGEBASE_CONTENT_DIRTY);

    VfxRenderBuffer::disposeHandle();

    if (is_valid)
    {
        clearPropertyDirty(VFX_IMAGEBASE_CONTENT_DIRTY);
    }
}


/***************************************************************************** 
 * Class VfxImage2D
 *****************************************************************************/

VfxImage2D::VfxImage2D(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat)
: VfxImageBase(w, h, colorFormat)
{
}


VfxImage2D::VfxImage2D(const VfxImageSrc &imageSrc)
: VfxImageBase(imageSrc)
{
}

VfxImage2D::VfxImage2D(const VfxWString &imagePath)
: VfxImageBase(imagePath)
{
}

VfxImage2D::VfxImage2D(const VfxResId resId)
: VfxImageBase(resId)
{
}

void VfxImage2D::createHandle() const
{

    switch (m_imageSrc.getType())
    {
    case VFX_IMAGE_SRC_TYPE_NULL:
        m_handle = vrt_create_image_2d(m_width, m_height, m_colorFormat);
        break;
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        m_handle = vrt_create_image_2d_from_mem_ptr(vrt_sys_res_image_lock(m_imageSrc.getResId()));
        break;
    case VFX_IMAGE_SRC_TYPE_MEM:
        m_handle = vrt_create_image_2d_from_mem_ptr(m_imageSrc.getMem());
        break;
    case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        {
            const VfxImageBuffer &imageBuffer = m_imageSrc.getImageBuffer();
            vrt_image_buffer_struct image_buffer;
            imageBuffer.initVrtImageBuffer(image_buffer);
            m_handle = vrt_create_image_2d_from_image_buffer(&image_buffer);
        }
        break;
    case VFX_IMAGE_SRC_TYPE_PATH:
        {
            const VfxWString filePath = m_imageSrc.getPath();
            m_handle = vrt_create_image_2d_from_path(filePath.getBuf(), filePath.isDynamic() ? VRT_TRUE : VRT_FALSE);
        }
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }

}


/***************************************************************************** 
 * Class VfxImageCube
 *****************************************************************************/

VfxImageCube::VfxImageCube(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat)
: VfxImageBase(w, h, colorFormat)
{
}

VfxImageCube::VfxImageCube(const VfxImageSrc &imageSrc)
: VfxImageBase(imageSrc)
{
}

VfxImageCube::VfxImageCube(const VfxWString &imagePath)
: VfxImageBase(imagePath)
{
}

VfxImageCube::VfxImageCube(const VfxResId resId)
: VfxImageBase(resId)
{
}

void VfxImageCube::createHandle() const
{
    switch (m_imageSrc.getType())
    {
    case VFX_IMAGE_SRC_TYPE_NULL:
        m_handle = vrt_create_image_cube(m_width, m_height, m_colorFormat);
        break;
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        m_handle = vrt_create_image_cube_from_mem_ptr(vrt_sys_res_image_lock(m_imageSrc.getResId()));
        break;
    case VFX_IMAGE_SRC_TYPE_MEM:
        m_handle = vrt_create_image_cube_from_mem_ptr(m_imageSrc.getMem());
        break;
    case VFX_IMAGE_SRC_TYPE_PATH:
        {
            const VfxWString filePath = m_imageSrc.getPath();
            m_handle = vrt_create_image_cube_from_path(filePath.getBuf(), filePath.isDynamic() ? VRT_TRUE : VRT_FALSE);
        }
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}


/***************************************************************************** 
 * Class VrtImageText
 *****************************************************************************/

VfxImageText::VfxImageText(VfxU32 w, VfxU32 h) :
    VfxImage2D(w, h, VFX_IMAGE_TEXT_COLOR_FORMAT),
    m_autosize(VFX_FALSE)
{
}


VfxImageText::VfxImageText(const VfxWString &string, const VfxFontDesc &font) :
    VfxImage2D(0, 0, VFX_IMAGE_TEXT_COLOR_FORMAT),
    m_autosize(VFX_TRUE),
    m_string(string),
    m_font(font)
{
    layout();
}


VfxImageText::VfxImageText(VfxU32 w, VfxU32 h, const VfxWString &string, const VfxFontDesc &font) :
    VfxImage2D(w, h, VFX_IMAGE_TEXT_COLOR_FORMAT),
    m_autosize(VFX_FALSE),
    m_string(string),
    m_font(font)
{
}


void VfxImageText::setString(const VfxWString &value)
{
    m_string = value;
    layout();
    invalidate();
}


void VfxImageText::setFont(const VfxFontDesc &value)
{
    m_font = value;
    layout();
    invalidate();
}


void VfxImageText::setTextColor(const VfxColor &value)
{
    m_textColor = value;
    invalidate();
}


void VfxImageText::setTextBorderColor(const VfxColor &value)
{
    m_textBorderColor = value;
    invalidate();
}


void VfxImageText::setBackgroundColor(const VfxColor &value)
{
    m_backroundColor = value;
    invalidate();
}


void VfxImageText::createHandle() const
{
    VFX_DEV_ASSERT(m_handle == NULL);

    m_handle = vrt_create_image_text(
        m_width, 
        m_height, 
        m_colorFormat,
        redraw,
        getObjHandle(),
        sizeof(VfxObjHandle));
}


void VfxImageText::layout()
{
    if (m_autosize)
    {
        VfxSize size = m_font.measureStr(m_string);

        // fully height
        static const VfxWChar s_str[] = {0x0041, 0x0067, 0x0068, 0x5BB6, 0}; /* 'Agh' */
        static VfxS32 max_height = 0;
        static VfxFontDesc s_font;
        if (s_font != m_font || max_height == 0)
        {
            VfxSize max_size = m_font.measureStr(s_str);
            s_font = m_font;
            max_height = max_size.height;
        }

        size.height = VFX_MAX(size.height, max_height);

        setSize(size.width + 4, size.height + 4);
    }
}


vrt_bool VfxImageText::redraw(
    vrt_image_buffer_struct *image_buffer,
    const vrt_point_struct *top_left,
    void *user_data,
    vrt_size user_data_size)
{
    VfxImageText *text = (VfxImageText *)VfxObject::handleToObject(user_data);
    if (text == NULL)
    {
        VFX_TRACE(("VfxImageText has been deleted.\n"));
        return VRT_FALSE;
    }

    if (text->m_string.isEmpty())
    {
        return VRT_TRUE;
    }
    
    vrt_font_struct vrtFont;
    text->m_font.initVrtFont(vrtFont);

    mmi_fe_color feColor;
    feColor.a = text->m_textColor.getA();
    feColor.r = text->m_textColor.getR();
    feColor.g = text->m_textColor.getG();
    feColor.b = text->m_textColor.getB();
    mmi_fe_set_text_color(feColor);

    VfxPoint pos(-top_left->x + 2, -top_left->y + 2);

    if (text->m_font.effect == VFX_FONT_DESC_EFFECT_BORDER)
    {
        feColor.a = text->m_textBorderColor.getA();
        feColor.r = text->m_textBorderColor.getR();
        feColor.g = text->m_textBorderColor.getG();
        feColor.b = text->m_textBorderColor.getB();
        mmi_fe_set_text_border_color(feColor);

        pos.x -= 1;
        pos.y -= 1;
    }

    gdi_handle layer;
    gdi_layer_create_cf_using_outside_memory(
        vrt_cf_to_gdi_cf(image_buffer->color_format),
        0,
        0,
        image_buffer->width,
        image_buffer->height,
        &layer,
        image_buffer->buf_p,
        image_buffer->pitch_bytes * image_buffer->height);

    gdi_layer_push_and_set_active(layer);    
    gdi_layer_clear(text->m_backroundColor.value);

    if (text->m_font.effect == VFX_FONT_DESC_EFFECT_BORDER)
    {
        ShowStringBordered(
            pos.x, 
            pos.y, 
            *(stFontAttribute *)&vrtFont, 
            0, 
            (U8 *)text->m_string.getBuf(), 
            0);
    }
    else
    {
        ShowString(
            pos.x, 
            pos.y, 
            *(stFontAttribute *)&vrtFont, 
            0, 
            (U8 *)text->m_string.getBuf(), 
            0);
    }
    
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(layer);

    return VRT_TRUE;
}


/***************************************************************************** 
 * Class VfxDepthBuffer
 *****************************************************************************/

VfxDepthBuffer::VfxDepthBuffer(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat)
: VfxRenderBuffer(w, h, colorFormat)
{
}


void VfxDepthBuffer::createHandle() const
{
    m_handle = vrt_create_depth_buffer(m_width, m_height, m_colorFormat);    
}


/***************************************************************************** 
 * Class VfxStencilBuffer
 *****************************************************************************/

VfxStencilBuffer::VfxStencilBuffer(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat)
: VfxRenderBuffer(w, h, colorFormat)
{
}


void VfxStencilBuffer::createHandle() const
{
    m_handle = vrt_create_stencil_buffer(m_width, m_height, m_colorFormat);    
}

#pragma arm section code, rodata

