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
 *  vrt_asset_file.h
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
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VRT_ASSET_FILE_H__
#define __VRT_ASSET_FILE_H__

#include "vrt_datatype.h"
#include "vrt_3d_enum.h"
#include "vrt_vector.h"

/* VRT 3D Asset File Format
 *   header;
 *   object(s);
 *
 * header
 *   totalsize;
 *
 * object (include externals)
 *   obj_type;
 *   obj_id;
 *   length;
 *   data[length];  // data of object
 *
 */


/* object index type */
typedef vrt_u32         vrt_obj_index_type;

/* object type enum */
typedef enum
{
    VRT_OBJ_TYPE_UNKNOWN = 0,   //HEADER
    VRT_OBJ_TYPE_BONE,          //CONTROLLER
    VRT_OBJ_TYPE_ANIMATION,     //TRACK,
    VRT_OBJ_TYPE_PASS,          //APPEARANCE,
    VRT_OBJ_TYPE_SCENEINFO,     //BACKGROUND,
    VRT_OBJ_TYPE_CAMERA,
    VRT_OBJ_TYPE_RENDERTARGET,  //COMPOSITING,
    VRT_OBJ_TYPE_PROGRAM,       //FOG,
    VRT_OBJ_TYPE_UNIFORMS,      //POLYGON,
    VRT_OBJ_TYPE_GROUP,
    VRT_OBJ_TYPE_MESHNODE,      //IMAGE2D,
    VRT_OBJ_TYPE_INDEXBUFFER,
    VRT_OBJ_TYPE_LIGHT,
    VRT_OBJ_TYPE_MATERIAL,
    VRT_OBJ_TYPE_MESH,
    VRT_OBJ_TYPE_MORPHING,
    VRT_OBJ_TYPE_SKINNED,
    VRT_OBJ_TYPE_TEXTURE,       //TEXTURE2D,
    VRT_OBJ_TYPE_BINDINGS,      //SPRITE,
    VRT_OBJ_TYPE_KEYFRAME,
    VRT_OBJ_TYPE_VERTEXARRAY,
    VRT_OBJ_TYPE_VERTEXBUFFER,
    VRT_OBJ_TYPE_WORLD,
    VRT_OBJ_TYPE_SKINNEDNODE,   //
    VRT_OBJ_TYPE_END_OF_ENUM
} vrt_obj_type_enum;

/* reference type enum */
typedef enum
{
    VRT_REF_TYPE_RES_ID = 0,
    VRT_REF_TYPE_WSTRING,
    VRT_REF_TYPE_CUSTOM_DATA,
    //VRT_REF_TYPE_STRING,
    VRT_REF_TYPE_END_OF_ENUM
} vrt_ref_type_enum;

#define VRT_REF_VALUE_RES_ID_NEED_RELOC 0xFEFE

/* transform flags */
typedef enum
{
    VRT_NODE_PROPERTY_FLAG_TRANSLATION  = 1 << 0,
    VRT_NODE_PROPERTY_FLAG_ROTATION     = 1 << 1,
    VRT_NODE_PROPERTY_FLAG_SCALE        = 1 << 2,
    VRT_NODE_PROPERTY_FLAG_PIVOT        = 1 << 3,
    VRT_NODE_PROPERTY_FLAG_LOOKAT       = 1 << 4,
    //VRT_NODE_PROPERTY_FLAG_ALIGNS       = 1 << 5,
    VRT_NODE_PROPERTY_FLAG_OPACITY      = 1 << 6,
} vrt_node_property_flag;

/* projection type enum */
typedef enum
{
    VRT_CAMERA_PROJECTION_TYPE_PERSPECTIVE = 0,
    VRT_CAMERA_PROJECTION_TYPE_PARALLEL,
    VRT_CAMERA_PROJECTION_TYPE_END_OF_ENUM
} vrt_camera_projection_type_enum;

/* animatable property enum */
typedef enum
{
    /* transformable */
    VRT_ANIMATABLE_PROPERTY_ID_TRANSLATION = 28,    // map to old vrt_object_property_id_enum
    VRT_ANIMATABLE_PROPERTY_ID_ORIENTATION,
    VRT_ANIMATABLE_PROPERTY_ID_SCALE,
    VRT_ANIMATABLE_PROPERTY_ID_PIVOT,
    /* node */
    VRT_ANIMATABLE_PROPERTY_ID_NODE_OPACITY,
    /* light */
    VRT_ANIMATABLE_PROPERTY_ID_LIGHT_COLOR,
    VRT_ANIMATABLE_PROPERTY_ID_LIGHT_INTENSITY,
    /* shader variable */
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_FIRST,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_FLOAT = VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_FIRST,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_VEC2,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_VEC3,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_VEC4,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_QUAT,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT2,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT3,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT4,
    VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_LAST = VRT_ANIMATABLE_PROPERTY_ID_SHADER_VARIABLE_MAT4,

    VRT_ANIMATABLE_PROPERTY_ID_END_OF_ENUM
} vrt_animatable_property_id_enum;

// TODO: change bool fields to flags

/* null-terminated string in file */
typedef struct
{
    vrt_u16 length;     // strlen = length - 1
    //vrt_char *string;
} vrt_file_string;

/* null-terminated wstring in file */
typedef struct
{
    vrt_u16 size;       // wcslen = size / sizeof(vrt_wchar) - 1
    //vrt_wchar *wstring;
} vrt_file_wstring;

/* file custom data type */
typedef struct
{
    vrt_u16 size;
    vrt_u8 *data;
} vrt_file_custom_data;

/* object reference type */
typedef struct
{
    vrt_u8 ref_type;
    union {
        vrt_u16 id;
        vrt_file_wstring wstr;
        vrt_file_custom_data data;
    };
} vrt_obj_ref_type;

/* file header */
typedef struct
{
    vrt_u32                 totalsize;
} vrt_file_header;

/* object header */
typedef struct
{
    vrt_u8                  object_type;
    vrt_obj_index_type      id;
    vrt_u32                 length;
    //void *object_data;
    //void *variable_data;
} vrt_file_object;

#define sizeof_vrt_file_object_hdr (    \
    sizeof(vrt_u8) +                    \
    sizeof(vrt_obj_index_type) +        \
    sizeof(vrt_u32))

/*
 * define types and orders of object fields
 */

/* geometry */
typedef struct
{
    vrt_u16                 num_vertices;
    vrt_u8                  num_components;
    vrt_u8                  type;
    //void *data;
} vrt_obj_vertex_array;

typedef struct
{
    vrt_u8                  primitive_type;
    vrt_u8                  type;
    vrt_u16                 num_indices;
    //void *data;
} vrt_obj_index_buffer;

typedef struct
{
    vrt_u8                  va_count;

    typedef struct
    {
        vrt_file_string         name;
        vrt_obj_index_type      va_id;
        vrt_bool                normalized;
        vrt_bool                scalebiased;
        VrtVector4f             scale;          // if scalebiased
        VrtVector4f             bias;           // if scalebiased
        //VrtVertexArray *va;
    } vrt_fmt_vertex_attrib;

} vrt_obj_vertex_buffer;

typedef struct
{
    vrt_obj_index_type      vb_id;
    vrt_u8                  sm_count;
    //typedef vrt_obj_index_type vrt_fmt_sub_mesh;

    VrtVector3f             volume_center;
    vrt_float               volume_radius2;
    VrtVector3f             volume_box;

    typedef struct
    {
        vrt_u8                  jnt_count;
        //typedef VrtMatrix4f vrt_fmt_inv_bind_mat;
    } vrt_fmt_skinned_mesh;

} vrt_obj_mesh;

/* material */
typedef struct
{
    vrt_u8                  winding;
    vrt_u8                  culling;
} vrt_fmt_polygon_mode;

typedef struct
{
    vrt_color_type          color;
    vrt_u8                  color_eq;
    vrt_u8                  alpha_eq;
    vrt_u8                  src_color;
    vrt_u8                  dst_color;
    vrt_u8                  src_alpha;
    vrt_u8                  dst_alpha;
} vrt_fmt_blender;

typedef struct
{
    typedef struct
    {
        vrt_u8                  op_sfail;
        vrt_u8                  op_dfail;
        vrt_u8                  op_pass;
        vrt_u8                  func;
        vrt_s32                 ref;
        vrt_u32                 mask;
        vrt_u32                 write_mask;
    } vrt_fmt_face;

    vrt_fmt_face            front;
    vrt_fmt_face            back;
} vrt_fmt_stencil;

typedef struct
{
    vrt_bool                has_blender;
    vrt_bool                has_stencil;
    vrt_u32                 color_mask;
    vrt_float               depth_offset_factor;
    vrt_float               depth_offset_units;
    vrt_bool                depth_test;
    vrt_bool                depth_write_enable;
    vrt_u8                  depth_func;
    //vrt_fmt_blender blender;
    //vrt_fmt_stencil stencil;
} vrt_fmt_compositing_mode;

typedef struct
{
    vrt_obj_ref_type        vs_ref;
    vrt_obj_ref_type        fs_ref;
} vrt_obj_shader_program;

typedef struct
{
    vrt_u8                  texture_type;
    vrt_u8                  level_filter;
    vrt_u8                  image_filter;
    vrt_u8                  wrap_s;
    vrt_u8                  wrap_t;
    vrt_obj_ref_type        image_ref;
} vrt_obj_texture;

typedef struct
{
    vrt_u8                  uv_count;

    typedef struct
    {
        vrt_file_string         name;
        vrt_u8                  type;
        vrt_u8                  count;
        //void *data;
    } vrt_fmt_uniform_variable;

} vrt_obj_uniforms;

typedef struct
{
    // TODO: buffers
    vrt_color_type          clear_color;
    vrt_bool                enable_clear;
} vrt_obj_render_target;

typedef struct
{
    vrt_bool                has_polygon;
    vrt_bool                has_compositing;
    vrt_u8                  un_count;
    vrt_u8                  pass_type;
    vrt_obj_index_type      prog_id;
    vrt_obj_index_type      rt_id;
    VrtVector2us            tessellation_level;
    //vrt_fmt_polygon_mode polygon;
    //vrt_fmt_compositing_mode compositing;
    //typedef vrt_obj_index_type vrt_fmt_shader_uniforms
} vrt_obj_pass;

typedef struct
{
    vrt_u8                  pass_count;
    //typedef vrt_obj_index_type vrt_fmt_material_pass
} vrt_obj_material;

/* scene graph */
typedef struct
{
    vrt_obj_index_type      parent_id;
    vrt_u8                  trsp_flags;
    //VrtMatrix3f             lookat;         // if VRT_NODE_PROPERTY_FLAG_LOOKAT
    //VrtVector3f             translation;    // if VRT_NODE_PROPERTY_FLAG_TRANSLATION
    //VrtQuaternionf          rotation;       // if VRT_NODE_PROPERTY_FLAG_ROTATION
    //VrtVector3f             scale;          // if VRT_NODE_PROPERTY_FLAG_SCALE
    //VrtMatrix4f             pivot;          // if VRT_NODE_PROPERTY_FLAG_PIVOT
    //vrt_float               opacity;        // if VRT_NODE_PROPERTY_FLAG_OPACITY

    typedef struct
    {
        vrt_u8                  child_count;
    } vrt_fmt_group;

    typedef struct
    {
        vrt_u8                  proj_type;
        vrt_float               fovy;
        vrt_float               aspect_ratio;
        vrt_float               znear;
        vrt_float               zfar;
    } vrt_fmt_camera;

    typedef struct
    {
        vrt_color_type          color;
        vrt_float               intensity;
    } vrt_fmt_light;

    typedef struct
    {
        vrt_u8                  bm_count;
        vrt_obj_ref_type        mesh_ref;
        //typedef vrt_obj_ref_type vrt_fmt_bind_mtl;
    } vrt_fmt_mesh;

} vrt_obj_node;

typedef struct
{
    vrt_obj_index_type      node_id;
    vrt_u8                  mtl_idx;
    vrt_u8                  pass_idx;
    vrt_u8                  ub_count;

    typedef struct
    {
        vrt_file_string         name;
        vrt_u8                  type;
        vrt_obj_index_type      object_id;
        vrt_u8                  bindprop_id;
    } vrt_fmt_uniform_binding;

} vrt_obj_bindings;

typedef struct
{
    vrt_obj_index_type      ac_id;
    vrt_u16                 name_count;
    vrt_obj_ref_type        bg_ref;

    typedef struct
    {
        vrt_file_string         object_name;
        vrt_obj_index_type      object_id;
    } vrt_fmt_object_table;

    typedef struct
    {
        vrt_u16                 ske_count;

        typedef struct
        {
            vrt_obj_index_type      skin_id;
            vrt_obj_index_type      skeleton_id;
        } vrt_fmt_skin_skeleton;

    } vrt_fmt_extra;

} vrt_obj_scene_info;

/* animation */
typedef struct
{
    vrt_msec_type           start;
    vrt_msec_type           duration;
    vrt_u8                  animprop_id;
    vrt_u8                  interpolation;
    vrt_obj_ref_type        kfs_ref;
} vrt_obj_keyframe_timeline;

typedef struct
{
    vrt_msec_type           start;
    vrt_msec_type           duration;
    vrt_u16                 tl_count;

    typedef struct
    {
        vrt_file_string         target_name;
        vrt_obj_index_type      tl_id;
        vrt_file_string         var_name;       // if animprop_id == VRT_SHADER_VARIABLE_PROPERTY_ID_xxx
        vrt_u8                  mtl_idx;        // if animprop_id == VRT_SHADER_VARIABLE_PROPERTY_ID_xxx
        vrt_u8                  pass_idx;       // if animprop_id == VRT_SHADER_VARIABLE_PROPERTY_ID_xxx
    } vrt_fmt_timeline_target;

} vrt_obj_animation;

/* VRT Keyframe Sequence File Format
 *   header;
 *   data;
 *
 * header
 *   key_count;
 *   type;
 *   interpolation;
 *
 * data {
 *   key_time;
 *   key_value[size_of_type];
 * } [key_count];
 *
 */

typedef vrt_keyframe_sequence_struct vrt_keyframe_file_header;
//vrt_u32 key_count;
//vrt_type_id_enum type_id;

typedef struct
{
    vrt_msec_type           time;
    //void *data;
} vrt_keyframe_file_data;

/* VRT Shader Binary File Header (4-byte aligned)
 *   identifier = {'V', 'S'};
 *   builtin_var_flags[];
 *   padding[0-3];
 */

typedef enum
{
    /* unknown and attributes */
    VRT_BSV_UNKNOWN = 0,
    VRT_BSA_POSITION,               // "v3d_Position"   ("v3d_PositionScale",  "v3d_PositionBias")
    VRT_BSA_COLOR,                  // "v3d_Color"
    VRT_BSA_TEXCOORD,               // "v3d_TexCoord"   ("v3d_TexCoordScale",  "v3d_TexCoordBias")
    VRT_BSA_TEXCOORD1,              // "v3d_TexCoord1"  ("v3d_TexCoord1Scale", "v3d_TexCoord1Bias")
    VRT_BSA_TEXCOORD2,              // "v3d_TexCoord2"  ("v3d_TexCoord2Scale", "v3d_TexCoord2Bias")
    VRT_BSA_TEXCOORD3,              // "v3d_TexCoord3"  ("v3d_TexCoord3Scale", "v3d_TexCoord3Bias")
    VRT_BSA_TEXCOORD4,              // "v3d_TexCoord4"  ("v3d_TexCoord4Scale", "v3d_TexCoord4Bias")
    VRT_BSA_TEXCOORD5,              // "v3d_TexCoord5"  ("v3d_TexCoord5Scale", "v3d_TexCoord5Bias")
    VRT_BSA_TEXCOORD6,              // "v3d_TexCoord6"  ("v3d_TexCoord6Scale", "v3d_TexCoord6Bias")
    VRT_BSA_TEXCOORD7,              // "v3d_TexCoord7"  ("v3d_TexCoord7Scale", "v3d_TexCoord7Bias")
    VRT_BSA_NORMAL,                 // "v3d_Normal"
    VRT_BSA_TANGENT,                // "v3d_Tangent"
    VRT_BSA_BINORMAL,               // "v3d_Binormal"
    VRT_BSA_POINT_SIZE,             // "v3d_PointSize"
    VRT_BSA_BONE_WEIGHTS,           // "v3d_BoneWeights"
    VRT_BSA_BONE_INDICES,           // "v3d_BoneIndices"
    VRT_BSA_CUSTOM,

    /* uniforms */
    VRT_BSU_TIME,                           // "v3d_Time"
    VRT_BSU_FILTER_TIMING,                  // "v3d_FilterTiming"
    VRT_BSU_FPE_USER0,                      // "v3d_FpeUser0"
    VRT_BSU_POS_Z,                          // "v3d_PosZ"
    VRT_BSU_SCREEN_ROTATE_MATRIX,           // "v3d_ScreenRotateMatrix"
    VRT_BSU_SCREEN_DIRECTION,               // "v3d_ScreenDirection"
    VRT_BSU_VIEWPORT_SIZE,                  // "v3d_ViewportSize"
    VRT_BSU_SCALE,                          // "v3d_Scale"
    VRT_BSU_BIAS,                           // "v3d_Bias"
    VRT_BSU_TESSELLATION_LEVEL,             // "v3d_TessellationLevel"
    VRT_BSU_OPACITY,                        // "v3d_Opacity"
    VRT_BSU_FRAME_ORIGIN,                   // "v3d_FrameOrigin"
    VRT_BSU_ANCHOR,                         // "v3d_Anchor"
    VRT_BSU_AFFINE_SCALE,                   // "v3d_AffineScale"
    VRT_BSU_AFFINE_ROTATE,                  // "v3d_AffineRotate"
    VRT_BSU_AFFINE_TRANSLATE,               // "v3d_AffineTranslate"
    VRT_BSU_PROJECTIVE_TRANSFORM,           // "v3d_ProjectiveTransform"
    VRT_BSU_BASE_TEX_SIZE,                  // "v3d_BaseTexSize"
    VRT_BSU_BASE_TEX,                       // "v3d_BaseTex"
    VRT_BSU_ALPHA_TEX,                      // "v3d_AlphaTex"
    VRT_BSU_COLOR_KEY,                      // "v3d_ColorKey"
    VRT_BSU_REPEAT_ORIGIN,                  // "v3d_RepeatOrigin"
    VRT_BSU_REPEAT_SIZE,                    // "v3d_RepeatSize"
    VRT_BSU_OUT_RECT_SIZE,                  // "v3d_OutRectSize"

    VRT_BSU_NORMAL_MATRIX,                          // "v3d_NormalMatrix"
    VRT_BSU_MODEL_VIEW_PROJECTION_SCREEN_MATRIX,    // "v3d_MVPSMatrix"
    VRT_BSU_MODEL_VIEW_PROJECTION_MATRIX,           // "v3d_MVPMatrix"
    VRT_BSU_MODEL_VIEW_MATRIX,                      // "v3d_MVMatrix"
    VRT_BSU_VIEW_PROJECTION_MATRIX,                 // "v3d_VPMatrix"
    VRT_BSU_PROJECT_MATRIX,                         // "v3d_ProjectMatrix"
    VRT_BSU_MODEL_MATRIX,                           // "v3d_ModelMatrix"
    VRT_BSU_VIEW_MATRIX,                            // "v3d_ViewMatrix"
    VRT_BSU_MODEL_VIEW_PROJECTION_MATRIX_INVERSE,   // "v3d_MVPMatrixInverse"
    VRT_BSU_MODEL_VIEW_MATRIX_INVERSE,              // "v3d_MVMatrixInverse"
    VRT_BSU_VIEW_PROJECTION_MATRIX_INVERSE,         // "v3d_VPMatrixInverse"
    VRT_BSU_PROJECT_MATRIX_INVERSE,                 // "v3d_ProjectMatrixInverse"
    VRT_BSU_MODEL_MATRIX_INVERSE,                   // "v3d_ModelMatrixInverse"
    VRT_BSU_VIEW_MATRIX_INVERSE,                    // "v3d_ViewMatrixInverse"
    VRT_BSU_MODEL_VIEW_PROJECTION_MATRIX_TRANSPOSE, // "v3d_MVPMatrixTranspose"
    VRT_BSU_MODEL_VIEW_MATRIX_TRANSPOSE,            // "v3d_MVMatrixTranspose"
    VRT_BSU_VIEW_PROJECTION_MATRIX_TRANSPOSE,       // "v3d_VPMatrixTranspose"
    VRT_BSU_PROJECT_MATRIX_TRANSPOSE,               // "v3d_ProjectMatrixTranspose"
    VRT_BSU_MODEL_MATRIX_TRANSPOSE,                 // "v3d_ModelMatrixTranspose"
    VRT_BSU_VIEW_MATRIX_TRANSPOSE,                  // "v3d_ViewMatrixTranspose"
    VRT_BSU_MODEL_VIEW_PROJECTION_MATRIX_INVERSE_TRANSPOSE, // "v3d_MVPMatrixInverseTranspose"
    VRT_BSU_MODEL_VIEW_MATRIX_INVERSE_TRANSPOSE,            // "v3d_MVMatrixInverseTranspose"
    VRT_BSU_VIEW_PROJECTION_MATRIX_INVERSE_TRANSPOSE,       // "v3d_VPMatrixInverseTranspose"
    VRT_BSU_PROJECT_MATRIX_INVERSE_TRANSPOSE,               // "v3d_ProjectMatrixInverseTranspose"
    VRT_BSU_MODEL_MATRIX_INVERSE_TRANSPOSE,                 // "v3d_ModelMatrixInverseTranspose"
    VRT_BSU_VIEW_MATRIX_INVERSE_TRANSPOSE,                  // "v3d_ViewMatrixInverseTranspose"
    VRT_BSU_BONE_TRANSFORMS,                                // "v3d_BoneTransforms"

    VRT_BSV_END_OF_ENUM
} VrtBuiltInShaderVariableID;

#define VRT_BUILTIN_SHADER_VARIABLE_FLAGS_SIZE  ((VRT_BSV_END_OF_ENUM + 7) / 8)

#define VRT_SHADER_BINARY_IDENTIFIER_REF        { 0X56, 0X53 }      // 'V', 'S'
#define VRT_SHADER_BINARY_HEADER_SIZE           (((2 + VRT_BUILTIN_SHADER_VARIABLE_FLAGS_SIZE + 3) / 4) * 4)
#define VRT_SHADER_BINARY_HEADER_PADDING        (VRT_SHADER_BINARY_HEADER_SIZE - 2 - VRT_BUILTIN_SHADER_VARIABLE_FLAGS_SIZE)

typedef struct
{
    vrt_u8 identifier[2];
    vrt_u8 builtin_var_flags[VRT_BUILTIN_SHADER_VARIABLE_FLAGS_SIZE];
    vrt_u8 padding[VRT_SHADER_BINARY_HEADER_PADDING];
} vrt_shader_file_header;

#endif /* __VRT_ASSET_FILE_H__ */

