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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vrt_3d_enum.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
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
#ifndef __VRT_3D_ENUM__
#define __VRT_3D_ENUM__

#ifdef __cplusplus
extern "C"
{
#endif


typedef enum
{
    VRT_RENDER_DEVICE_TYPE_GDI,
    VRT_RENDER_DEVICE_TYPE_GLES
} VrtRenderDeviceType;


typedef enum
{
    VRT_CULLING_NONE = 0,
    VRT_CULLING_FRONT,
    VRT_CULLING_BACK,
    VRT_CULLING_END_OF_ENUM
} VrtCullingMode;

typedef enum
{
    VRT_WINDING_CCW = 0,
    VRT_WINDING_CW,
    VRT_WINDING_END_OF_ENUM
} VrtWindingMode;

typedef enum
{
    VRT_BLEND_EQUATION_ADD = 0,
    VRT_BLEND_EQUATION_SUBTRACT,
    VRT_BLEND_EQUATION_REVERSE_SUBTRACT,
    VRT_BLEND_EQUATION_END_OF_ENUM
} VrtBlendEquation;

typedef enum
{
    VRT_BLEND_FACTOR_ZERO = 0,
    VRT_BLEND_FACTOR_ONE,
    VRT_BLEND_FACTOR_SRC_COLOR,
    VRT_BLEND_FACTOR_ONE_MINUS_SRC_COLOR,
    VRT_BLEND_FACTOR_DST_COLOR,
    VRT_BLEND_FACTOR_ONE_MINUS_DST_COLOR,
    VRT_BLEND_FACTOR_SRC_ALPHA,
    VRT_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
    VRT_BLEND_FACTOR_DST_ALPHA,
    VRT_BLEND_FACTOR_ONE_MINUS_DST_ALPHA,
    VRT_BLEND_FACTOR_CONSTANT_COLOR,
    VRT_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR,
    VRT_BLEND_FACTOR_CONSTANT_ALPHA,
    VRT_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA,
    VRT_BLEND_FACTOR_SRC_ALPHA_SATURATE,
    VRT_BLEND_FACTOR_END_OF_ENUM
} VrtBlendFactor;

typedef enum
{
    VRT_STENCIL_FUNC_NEVER = 0,
    VRT_STENCIL_FUNC_ALWAYS,
    VRT_STENCIL_FUNC_EQUAL,
    VRT_STENCIL_FUNC_LESS,
    VRT_STENCIL_FUNC_GREATER,
    VRT_STENCIL_FUNC_GEQUAL,
    VRT_STENCIL_FUNC_LEQUAL,
    VRT_STENCIL_FUNC_NOTEQUAL,
    VRT_STENCIL_FUNC_END_OF_ENUM
} VrtStencilFunc;

typedef enum
{
    VRT_STENCIL_OP_ZERO = 0,
    VRT_STENCIL_OP_KEEP,
    VRT_STENCIL_OP_REPLACE,
    VRT_STENCIL_OP_INCR,
    VRT_STENCIL_OP_DECR,
    VRT_STENCIL_OP_INVERT,
    VRT_STENCIL_OP_INCR_WRAP,
    VRT_STENCIL_OP_DECR_WRAP,
    VRT_STENCIL_OP_END_OF_ENUM
} VrtStencilOp;

typedef enum
{
    VRT_DEPTH_FUNC_NEVER = 0,
    VRT_DEPTH_FUNC_ALWAYS,
    VRT_DEPTH_FUNC_EQUAL,
    VRT_DEPTH_FUNC_LESS,
    VRT_DEPTH_FUNC_GREATER,
    VRT_DEPTH_FUNC_GEQUAL,
    VRT_DEPTH_FUNC_LEQUAL,
    VRT_DEPTH_FUNC_NOTEQUAL,
    VRT_DEPTH_FUNC_END_OF_ENUM
} VrtDepthFunc;


#define VRT_RENDER_SCOPE_DEFAULT            (1 << 0)    /* default scope of normal pass */
#define VRT_RENDER_SCOPE_USER_BEGIN         (1 << 4)    /* begin of user scopes */
#define VRT_RENDER_SCOPE_ENGINE_MASK        (VRT_RENDER_SCOPE_USER_BEGIN - 1)
#define VRT_RENDER_SCOPE_ALL_MASK           (0xFFFFFFFF)


typedef enum
{
    VRT_PASS_GEOMETRY_DEFAULT = 0,
    VRT_PASS_GEOMETRY_VIEWPORT,
    VRT_PASS_GEOMETRY_END_OF_ENUM
} VrtPassGeometryType;


typedef enum
{
    VRT_PRIMITIVE_POINTS = 0,
    VRT_PRIMITIVE_LINES,
    VRT_PRIMITIVE_LINE_LOOP,
    VRT_PRIMITIVE_LINE_STRIP,
    VRT_PRIMITIVE_TRIANGLES,
    VRT_PRIMITIVE_TRIANGLE_STRIP,
    VRT_PRIMITIVE_TRIANGLE_FAN,
    VRT_PRIMITIVE_END_OF_ENUM
} VrtPrimitiveType;


typedef enum
{
    VRT_IMAGE_TARGET_2D = 0,
    VRT_IMAGE_TARGET_CUBE_POSITIVE_X,
    VRT_IMAGE_TARGET_CUBE_NEGATIVE_X,
    VRT_IMAGE_TARGET_CUBE_POSITIVE_Y,
    VRT_IMAGE_TARGET_CUBE_NEGATIVE_Y,
    VRT_IMAGE_TARGET_CUBE_POSITIVE_Z,
    VRT_IMAGE_TARGET_CUBE_NEGATIVE_Z,
    VRT_IMAGE_TARGET_END_OF_ENUM
} VrtImageTargetType;

typedef enum
{
    VRT_TEXTURE_2D = 0,
    VRT_TEXTURE_CUBE,
    VRT_TEXTURE_DEPTH,
    VRT_TEXTURE_END_OF_ENUM
} VrtTextureType;

typedef enum
{
    VRT_FILTER_BASE_LEVEL = 0,
    VRT_FILTER_NEAREST,
    VRT_FILTER_LINEAR,
    VRT_FILTER_END_OF_ENUM
} VrtFilterMode;

typedef enum
{
    VRT_TEXTURE_WRAP_CLAMP = 0,
    VRT_TEXTURE_WRAP_REPEAT,
    VRT_TEXTURE_WRAP_MIRROR,
    VRT_TEXTURE_WRAP_END_OF_ENUM
} VrtWrapMode;

typedef enum
{
    VRT_BINDING_UNKNOWN = 0,

    // Light property
    VRT_BINDING_LIGHT_COLOR,
    VRT_BINDING_LIGHT_INTENSITY,

    // Camera property
    VRT_BINDING_CAMERA_PROJECTION,

    // Transformable property
    VRT_BINDING_TRANSFORM,
    VRT_BINDING_INVERSE_TRANSFORM,

    // Node property
    VRT_BINDING_ALPHA_FACTOR,

    VRT_BINDING_CAMERA_SPACE_DIRECTION,
    VRT_BINDING_CAMERA_SPACE_POSITION,
    VRT_BINDING_MODEL_SPACE_DIRECTION,
    VRT_BINDING_MODEL_SPACE_POSITION,
    VRT_BINDING_WORLD_SPACE_DIRECTION,
    VRT_BINDING_WORLD_SPACE_POSITION,

    VRT_BINDING_WORLD_TRANSFORM,
    VRT_BINDING_INVERSE_WORLD_TRANSFORM,

    // Bone property
    VRT_BINDING_BONE_MATRICES,

    VRT_BINDING_END_OF_ENUM
} VrtBindingProperty;


#ifdef __cplusplus
}
#endif

#endif


