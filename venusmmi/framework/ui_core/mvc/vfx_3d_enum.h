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
 *  vfx_3d_enum.h
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
#ifndef __VFX_3D_ENUM_H__
#define __VFX_3D_ENUM_H__

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_3d_enum.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Default scope of normal pass in render mode
#define VFX_RENDER_SCOPE_DEFAULT            VRT_RENDER_SCOPE_DEFAULT

// Begin of user scopes in render mode
#define VFX_RENDER_SCOPE_USER_BEGIN         VRT_RENDER_SCOPE_USER_BEGIN

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* The culling modes */
typedef enum
{
    VFX_CULLING_NONE    = VRT_CULLING_NONE,
    VFX_CULLING_FRONT   = VRT_CULLING_FRONT,
    VFX_CULLING_BACK    = VRT_CULLING_BACK,
    VFX_CULLING_END_OF_ENUM
} VfxCullingMode;

/* The winding modes */
typedef enum
{
    VFX_WINDING_CCW     = VRT_WINDING_CCW,
    VFX_WINDING_CW      = VRT_WINDING_CW,
    VFX_WINDING_END_OF_ENUM
} VfxWindingMode;

/* The blend equations */
typedef enum
{
    VFX_BLEND_EQUATION_ADD                  = VRT_BLEND_EQUATION_ADD,
    VFX_BLEND_EQUATION_SUBTRACT             = VRT_BLEND_EQUATION_SUBTRACT,
    VFX_BLEND_EQUATION_REVERSE_SUBTRACT     = VRT_BLEND_EQUATION_REVERSE_SUBTRACT,
    VFX_BLEND_EQUATION_END_OF_ENUM
} VfxBlendEquation;

/* The blend factors */
typedef enum
{
    VFX_BLEND_FACTOR_ZERO                       = VRT_BLEND_FACTOR_ZERO,
    VFX_BLEND_FACTOR_ONE                        = VRT_BLEND_FACTOR_ONE,
    VFX_BLEND_FACTOR_SRC_COLOR                  = VRT_BLEND_FACTOR_SRC_COLOR,
    VFX_BLEND_FACTOR_ONE_MINUS_SRC_COLOR        = VRT_BLEND_FACTOR_ONE_MINUS_SRC_COLOR,
    VFX_BLEND_FACTOR_DST_COLOR                  = VRT_BLEND_FACTOR_DST_COLOR,
    VFX_BLEND_FACTOR_ONE_MINUS_DST_COLOR        = VRT_BLEND_FACTOR_ONE_MINUS_DST_COLOR,
    VFX_BLEND_FACTOR_SRC_ALPHA                  = VRT_BLEND_FACTOR_SRC_ALPHA,
    VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA        = VRT_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
    VFX_BLEND_FACTOR_DST_ALPHA                  = VRT_BLEND_FACTOR_DST_ALPHA,
    VFX_BLEND_FACTOR_ONE_MINUS_DST_ALPHA        = VRT_BLEND_FACTOR_ONE_MINUS_DST_ALPHA,
    VFX_BLEND_FACTOR_CONSTANT_COLOR             = VRT_BLEND_FACTOR_CONSTANT_COLOR,
    VFX_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR   = VRT_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR,
    VFX_BLEND_FACTOR_CONSTANT_ALPHA             = VRT_BLEND_FACTOR_CONSTANT_ALPHA,
    VFX_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA   = VRT_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA,
    VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE         = VRT_BLEND_FACTOR_SRC_ALPHA_SATURATE,
    VFX_BLEND_FACTOR_END_OF_ENUM
} VfxBlendFactor;

/* The stencil functions */
typedef enum
{
    VFX_STENCIL_FUNC_NEVER      = VRT_STENCIL_FUNC_NEVER,
    VFX_STENCIL_FUNC_ALWAYS     = VRT_STENCIL_FUNC_ALWAYS,
    VFX_STENCIL_FUNC_EQUAL      = VRT_STENCIL_FUNC_EQUAL,
    VFX_STENCIL_FUNC_LESS       = VRT_STENCIL_FUNC_LESS,
    VFX_STENCIL_FUNC_GREATER    = VRT_STENCIL_FUNC_GREATER,
    VFX_STENCIL_FUNC_GEQUAL     = VRT_STENCIL_FUNC_GEQUAL,
    VFX_STENCIL_FUNC_LEQUAL     = VRT_STENCIL_FUNC_LEQUAL,
    VFX_STENCIL_FUNC_NOTEQUAL   = VRT_STENCIL_FUNC_NOTEQUAL,
    VFX_STENCIL_FUNC_END_OF_ENUM
} VfxStencilFunc;

/* The stencil operations */
typedef enum
{
    VFX_STENCIL_OP_ZERO         = VRT_STENCIL_OP_ZERO,
    VFX_STENCIL_OP_KEEP         = VRT_STENCIL_OP_KEEP,
    VFX_STENCIL_OP_REPLACE      = VRT_STENCIL_OP_REPLACE,
    VFX_STENCIL_OP_INCR         = VRT_STENCIL_OP_INCR,
    VFX_STENCIL_OP_DECR         = VRT_STENCIL_OP_DECR,
    VFX_STENCIL_OP_INVERT       = VRT_STENCIL_OP_INVERT,
    VFX_STENCIL_OP_INCR_WRAP    = VRT_STENCIL_OP_INCR_WRAP,
    VFX_STENCIL_OP_DECR_WRAP    = VRT_STENCIL_OP_DECR_WRAP,
    VFX_STENCIL_OP_END_OF_ENUM
} VfxStencilOp;

/* The depth functions */
typedef enum
{
    VFX_DEPTH_FUNC_NEVER        = VRT_DEPTH_FUNC_NEVER,
    VFX_DEPTH_FUNC_ALWAYS       = VRT_DEPTH_FUNC_ALWAYS,
    VFX_DEPTH_FUNC_EQUAL        = VRT_DEPTH_FUNC_EQUAL,
    VFX_DEPTH_FUNC_LESS         = VRT_DEPTH_FUNC_LESS,
    VFX_DEPTH_FUNC_GREATER      = VRT_DEPTH_FUNC_GREATER,
    VFX_DEPTH_FUNC_GEQUAL       = VRT_DEPTH_FUNC_GEQUAL,
    VFX_DEPTH_FUNC_LEQUAL       = VRT_DEPTH_FUNC_LEQUAL,
    VFX_DEPTH_FUNC_NOTEQUAL     = VRT_DEPTH_FUNC_NOTEQUAL,
    VFX_DEPTH_FUNC_END_OF_ENUM
} VfxDepthFunc;


/* The pass types */
typedef enum
{
    // Default drawing pass
    VFX_PASS_GEOMETRY_DEFAULT   = VRT_PASS_GEOMETRY_DEFAULT ,

    // Pass that draws a viewport
    VFX_PASS_GEOMETRY_VIEWPORT  = VRT_PASS_GEOMETRY_VIEWPORT,

    VFX_PASS_GEOMETRY_END_OF_ENUM
} VfxPassGeometryType;


/* The image target types */
typedef enum
{
    VFX_IMAGE_TARGET_2D                 = VRT_IMAGE_TARGET_2D,
    VFX_IMAGE_TARGET_CUBE_POSITIVE_X    = VRT_IMAGE_TARGET_CUBE_POSITIVE_X,
    VFX_IMAGE_TARGET_CUBE_NEGATIVE_X    = VRT_IMAGE_TARGET_CUBE_NEGATIVE_X,
    VFX_IMAGE_TARGET_CUBE_POSITIVE_Y    = VRT_IMAGE_TARGET_CUBE_POSITIVE_Y,
    VFX_IMAGE_TARGET_CUBE_NEGATIVE_Y    = VRT_IMAGE_TARGET_CUBE_NEGATIVE_Y,
    VFX_IMAGE_TARGET_CUBE_POSITIVE_Z    = VRT_IMAGE_TARGET_CUBE_POSITIVE_Z,
    VFX_IMAGE_TARGET_CUBE_NEGATIVE_Z    = VRT_IMAGE_TARGET_CUBE_NEGATIVE_Z
} VfxImageTargetType;

/* The texture types */
typedef enum
{
    VFX_TEXTURE_2D          = VRT_TEXTURE_2D,
    VFX_TEXTURE_CUBE        = VRT_TEXTURE_CUBE,
    VFX_TEXTURE_DEPTH       = VRT_TEXTURE_DEPTH,
    VFX_TEXTURE_END_OF_ENUM
} VfxTextureType;

/* The texture filter modes */
typedef enum
{
    VFX_FILTER_BASE_LEVEL   = VRT_FILTER_BASE_LEVEL,
    VFX_FILTER_NEAREST      = VRT_FILTER_NEAREST,
    VFX_FILTER_LINEAR       = VRT_FILTER_LINEAR,
    VFX_FILTER_END_OF_ENUM
} VfxFilterMode;

/* The texture wrap modes */
typedef enum
{
    VFX_TEXTURE_WRAP_CLAMP  = VRT_TEXTURE_WRAP_CLAMP,
    VFX_TEXTURE_WRAP_REPEAT = VRT_TEXTURE_WRAP_REPEAT,
    VFX_TEXTURE_WRAP_MIRROR = VRT_TEXTURE_WRAP_MIRROR,
    VFX_TEXTURE_WRAP_END_OF_ENUM
} VfxWrapMode;

/* The variable binding properties */
typedef enum
{
    // Light property
    VFX_BINDING_LIGHT_COLOR             = VRT_BINDING_LIGHT_COLOR,
    VFX_BINDING_LIGHT_INTENSITY         = VRT_BINDING_LIGHT_INTENSITY,

    // Camera property
    VFX_BINDING_CAMERA_PROJECTION       = VRT_BINDING_CAMERA_PROJECTION,

    // Transformable property
    VFX_BINDING_TRANSFORM               = VRT_BINDING_TRANSFORM,
    VFX_BINDING_INVERSE_TRANSFORM       = VRT_BINDING_INVERSE_TRANSFORM,

    // Node property
    VFX_BINDING_ALPHA_FACTOR            = VRT_BINDING_ALPHA_FACTOR,

    VFX_BINDING_CAMERA_SPACE_DIRECTION  = VRT_BINDING_CAMERA_SPACE_DIRECTION,
    VFX_BINDING_CAMERA_SPACE_POSITION   = VRT_BINDING_CAMERA_SPACE_POSITION,
    VFX_BINDING_MODEL_SPACE_DIRECTION   = VRT_BINDING_MODEL_SPACE_DIRECTION,
    VFX_BINDING_MODEL_SPACE_POSITION    = VRT_BINDING_MODEL_SPACE_POSITION,
    VFX_BINDING_WORLD_SPACE_DIRECTION   = VRT_BINDING_WORLD_SPACE_DIRECTION,
    VFX_BINDING_WORLD_SPACE_POSITION    = VRT_BINDING_WORLD_SPACE_POSITION,

    VFX_BINDING_WORLD_TRANSFORM         = VRT_BINDING_WORLD_TRANSFORM,
    VFX_BINDING_INVERSE_WORLD_TRANSFORM = VRT_BINDING_INVERSE_WORLD_TRANSFORM,

    // Bone property
    VFX_BINDING_BONE_MATRICES           = VRT_BINDING_BONE_MATRICES,

    VFX_BINDING_END_OF_ENUM
} VfxVariableBindingProperty;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __VFX_3D_ENUM_H__ */

