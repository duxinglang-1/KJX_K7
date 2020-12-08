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
 *  vfx_texture.h
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
#ifndef __VFX_TEXTURE_H__
#define __VFX_TEXTURE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_transformable.h"
#include "vfx_image_src.h"
#include "vfx_weak_ptr.h"
#include "vfx_3d_enum.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxRenderBuffer;
class VfxImage2D;
class VfxImageCube;
class VfxImageText;
class VfxFrame;

class VfxWString;
class VfxFontDesc;


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_TEXTURE_BEGIN_FLAG              (VFX_TRANSFORMABLE_END_FLAG)
#define VFX_TEXTURE_RENDER_BUFFER_DIRTY     (VFX_TEXTURE_BEGIN_FLAG << 1)
#define VFX_TEXTURE_FILTER_DIRTY            (VFX_TEXTURE_BEGIN_FLAG << 2)
#define VFX_TEXTURE_WINDING_DIRTY           (VFX_TEXTURE_BEGIN_FLAG << 3)
#define VFX_TEXTURE_END_FLAG                (VFX_TEXTURE_WINDING_DIRTY)
#define VFX_TEXTURE_ALL_DIRTY               (VFX_TEXTURE_RENDER_BUFFER_DIRTY | VFX_TEXTURE_FILTER_DIRTY | VFX_TEXTURE_WINDING_DIRTY)

#define VFX_TEXTURE_FRAME_BEGIN_FLAG        (VFX_TEXTURE_END_FLAG)
#define VFX_TEXTURE_FRAME_FRAME_DIRTY       (VFX_TEXTURE_FRAME_BEGIN_FLAG << 1)
#define VFX_TEXTURE_FRAME_END_FLAG          (VFX_TEXTURE_FRAME_FRAME_DIRTY)
#define VFX_TEXTURE_FRAME_ALL_DIRTY         (VFX_TEXTURE_FRAME_FRAME_DIRTY)


/***************************************************************************** 
 * Class VfxTexture
 *****************************************************************************/

/*
 * VfxTexture is the base class of 3D texture.
 */
class VfxTexture : public VfxTransformable
{
    VFX_DECLARE_CLASS(VfxTexture);

// Constructor / Destructor
public:
    // Default constructor
    VfxTexture(VfxRenderBuffer *renderBuffer = NULL);

// Override
public:
    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Get image object.
    VfxRenderBuffer *getImage() const;

    // Set texture filter modes.
    //
    // NOTE: Default values are VFX_FILTER_BASE_LEVEL and VFX_FILTER_LINEAR.
    void setFilter(VfxFilterMode levelFilter, VfxFilterMode imageFilter);

    // Set texture wrap modes.
    //
    // NOTE: Default values are VFX_TEXTURE_WRAP_CLAMP and VFX_TEXTURE_WRAP_CLAMP.
    void setWrapping(VfxWrapMode wrapS, VfxWrapMode wrapT);

    // Get texture level filter mode.
    //
    // NOTE: Default value is VFX_FILTER_BASE_LEVEL.
    VfxFilterMode getLevelFilter() const;

    // Get texture image filter mode.
    //
    // NOTE: Default value is VFX_FILTER_LINEAR.
    VfxFilterMode getImageFilter() const;

    // Get texture wrapS mode.
    //
    // NOTE: Default value is VFX_TEXTURE_WRAP_CLAMP.
    VfxWrapMode getWrapS() const;

    // Get texture wrapT mode.
    //
    // NOTE: Default value is VFX_TEXTURE_WRAP_CLAMP.
    VfxWrapMode getWrapT() const;

// Implementation
protected:

    VfxWeakPtr< VfxRenderBuffer > m_renderBuffer;

    VfxFilterMode m_levelFilter;
    VfxFilterMode m_imageFilter;
    VfxWrapMode m_wrapModeS;
    VfxWrapMode m_wrapModeT;
};


/***************************************************************************** 
 * Class VfxTexture2D
 *****************************************************************************/

/*
 * VfxTexture2D is the texture2D for 3D material shader.
 */
class VfxTexture2D : public VfxTexture
{
// Constructor / Destructor
public:
    // Constructor with image2D object
    VfxTexture2D(VfxImage2D *image);

    // Constructor with image path
    VfxTexture2D(const VfxWString &imagePath);

    // Constructor with image resource ID
    VfxTexture2D(const VfxResId resId);

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Class VfxTextureCube
 *****************************************************************************/

/*
 * VfxTextureCube is the textureCube for 3D material shader.
 */
class VfxTextureCube : public VfxTexture
{
// Constructor / Destructor
public:
    // Constructor with imageCube object
    VfxTextureCube(VfxImageCube *cube);

    // Constructor with image path
    VfxTextureCube(const VfxWString &imagePath);

    // Constructor with image resource ID
    VfxTextureCube(const VfxResId resId);

// Override
public:
    virtual void createHandle() const;
};


/***************************************************************************** 
 * Class VfxTextureFrame
 *****************************************************************************/

/*
 * VfxTextureFrame is the texture of frame for 3D material shader.
 */
class VfxTextureFrame : public VfxTexture
{
// Constructor / Destructor
public:
    // Constructor with frame
    VfxTextureFrame(VfxFrame *frame);

// Override
public:
    virtual void createHandle() const;

    virtual void syncData() const;

// Implementation
protected:

    VfxWeakPtr <VfxFrame> m_frame;
};


/***************************************************************************** 
 * Class VfxTexture Implementation
 *****************************************************************************/

inline VfxFilterMode VfxTexture::getLevelFilter() const
{
    return m_levelFilter;
}

inline VfxFilterMode VfxTexture::getImageFilter() const
{
    return m_imageFilter;
}

inline VfxWrapMode VfxTexture::getWrapS() const
{
    return m_wrapModeS;
}

inline VfxWrapMode VfxTexture::getWrapT() const
{
    return m_wrapModeT;
}

#endif /* __VFX_TEXTURE_H__ */

