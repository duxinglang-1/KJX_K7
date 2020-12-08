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
 *  vfx_render_buffer.h
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
#ifndef __VFX_RENDER_BUFFER_H__
#define __VFX_RENDER_BUFFER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_3d_enum.h"

#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vfx_image_src.h"
#include "vfx_weak_ptr.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_RENDERBUFFER_BEGIN_FLAG     (VFX_OBJECT3D_END_FLAG)
#define VFX_RENDERBUFFER_END_FLAG       (VFX_RENDERBUFFER_BEGIN_FLAG)
#define VFX_RENDERBUFFER_ALL_DIRTY      (0)


/***************************************************************************** 
 * Class VfxRenderBuffer
 *****************************************************************************/

/*
 * VfxRenderBuffer is the base class of Venus 3D render buffer.
 */
class VfxRenderBuffer : public VfxObject3D
{
// Constructor / Destructor
public:
    // Constructor with width, height, and color format
    VfxRenderBuffer(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat);

// Property
public:
    // Get buffer width.
    VfxU32 getWidth() const;

    // Get buffer height.
    VfxU32 getHeight() const;

    // Get buffer color format.
    VfxColorTypeEnum getColorFormat() const;

// Implementation
protected:
    // Set buffer size.
    void setSize(VfxU32 w, VfxU32 h);

    VfxU32 m_width;
    VfxU32 m_height;
    VfxColorTypeEnum m_colorFormat;
};


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_IMAGEBASE_BEGIN_FLAG        (VFX_RENDERBUFFER_END_FLAG)
#define VFX_IMAGEBASE_CONTENT_DIRTY     (VFX_IMAGEBASE_BEGIN_FLAG << 1)
#define VFX_IMAGEBASE_END_FLAG          (VFX_IMAGEBASE_CONTENT_DIRTY)
#define VFX_IMAGEBASE_ALL_DIRTY         (VFX_IMAGEBASE_CONTENT_DIRTY)


/***************************************************************************** 
 * Class VfxImageBase
 *****************************************************************************/

/*
 * VfxImageBase is the base class of Venus 3D image.
 */
class VfxImageBase : public VfxRenderBuffer
{
    VFX_DECLARE_CLASS(VfxImageBase);

// Constructor / Destructor
public:
    // Constructor with width, height, and color format
    VfxImageBase(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat);

    // Constructor with image source
    VfxImageBase(const VfxImageSrc &imageSrc);

    // Constructor with image path
    VfxImageBase(const VfxWString &imagePath);

    // Constructor with image resource ID
    VfxImageBase(const VfxResId resId);

// Property
public:
    // Get image source.
    const VfxImageSrc &getImageSrc() const;

    // Invalidate image content.
    void invalidate();

// Override
public:
    virtual void syncData() const;

    virtual void destroy() const;

    virtual void disposeHandle() const;

// Implementation
protected:
    VfxImageSrc m_imageSrc;
};


/***************************************************************************** 
 * Class VfxImage2D
 *****************************************************************************/

/*
 * VfxImage2D is the Venus 3D image2D.
 */
class VfxImage2D : public VfxImageBase
{
// Constructor / Destructor
public:
    // Constructor with width, height, and color format
    VfxImage2D(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat);

    // Constructor with image source
    VfxImage2D(const VfxImageSrc &imageSrc);

    // Constructor with image path
    VfxImage2D(const VfxWString &imagePath);

    // Constructor with image resource ID
    VfxImage2D(const VfxResId resId);

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Class VfxImageCube
 *****************************************************************************/

/*
 * VfxImageCube is the Venus 3D imageCube.
 */
class VfxImageCube : public VfxImageBase
{
// Constructor / Destructor
public:
    // Constructor with width, height, and color format
    VfxImageCube(VfxU32 w, VfxU32 h, VfxColorTypeEnum colorFormat);

    // Constructor with image source
    VfxImageCube(const VfxImageSrc &imageSrc);

    // Constructor with image path
    VfxImageCube(const VfxWString &imagePath);

    // Constructor with image resource ID
    VfxImageCube(const VfxResId resId);

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Class VrtImageText
 *****************************************************************************/

/*
 * VfxImageText is the Venus 3D image2D for text.
 */
class VfxImageText : public VfxImage2D
{
// Constructor / Destructor
public:
    // Constructor with width and height
    VfxImageText(
        VfxU32 w, 
        VfxU32 h
    );

    // Constructor with text string and font
    VfxImageText(
        const VfxWString &string, 
        const VfxFontDesc &font
    );

    // Constructor with width, height, text string, and font
    VfxImageText(
        VfxU32 w, 
        VfxU32 h,
        const VfxWString &string, 
        const VfxFontDesc &font
    );

// Property
public:
    // Set string.
    void setString(const VfxWString &value);
    // Set font.
    void setFont(const VfxFontDesc &value);
    // Set text color.
    void setTextColor(const VfxColor &value);
    // Set text border color.
    void setTextBorderColor(const VfxColor &value);
    // Set background color.
    void setBackgroundColor(const VfxColor &value);

    // Get string.
    const VfxWString &getString() const;
    // Get font.
    const VfxFontDesc &getFont() const;

// Override
public:
    virtual void createHandle() const;    

// Implementation
private:
    static vrt_bool redraw(
        vrt_image_buffer_struct *image_buffer,
        const vrt_point_struct *top_left,
        void *user_data,
        vrt_size user_data_size);

    void layout();

    const VfxBool m_autosize;

    VfxWString m_string;
    VfxFontDesc m_font;

    VfxColor m_textColor;
    VfxColor m_textBorderColor;
    VfxColor m_backroundColor;
};


/***************************************************************************** 
 * Class VfxDepthBuffer
 *****************************************************************************/

/*
 * VfxDepthBuffer is the Venus 3D depth buffer.
 */
class VfxDepthBuffer : public VfxRenderBuffer
{
// Constructor / Destructor
public:
    // Constructor with width, height, and color format
    VfxDepthBuffer(VfxU32 w, VfxU32 h, VfxColorTypeEnum color_format = VRT_COLOR_TYPE_D16);

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Class VfxStencilBuffer
 *****************************************************************************/

/*
 * VfxStencilBuffer is the Venus 3D stencil buffer.
 */
class VfxStencilBuffer : public VfxRenderBuffer
{
// Constructor / Destructor
public:
    // Constructor with width, height, and color format
    VfxStencilBuffer(VfxU32 w, VfxU32 h, VfxColorTypeEnum color_format = VRT_COLOR_TYPE_S8);

// Override
public:
    virtual void createHandle() const;
};



/***************************************************************************** 
 * Implementation
 *****************************************************************************/

inline VfxU32 VfxRenderBuffer::getWidth() const
{
    return m_width;
}


inline VfxU32 VfxRenderBuffer::getHeight() const
{
    return m_height;
}


inline VfxColorTypeEnum VfxRenderBuffer::getColorFormat() const
{
    return m_colorFormat;
}


inline const VfxImageSrc &VfxImageBase::getImageSrc() const
{
    return m_imageSrc;
}


inline const VfxWString &VfxImageText::getString() const
{
    return m_string;
}


inline const VfxFontDesc &VfxImageText::getFont() const
{
    return m_font;
}


#endif /* __VFX_RENDER_BUFFER_H__ */

