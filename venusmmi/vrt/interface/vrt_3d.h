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
 *  vrt_3d.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VRT_3D_H__
#define __VRT_3D_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
#include "vrt_3d_enum.h"


#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef vrt_object_handle vrt_render_mode_handle;
typedef vrt_object_handle vrt_polygon_mode_handle;
typedef vrt_object_handle vrt_blender_handle;
typedef vrt_object_handle vrt_stencil_handle;
typedef vrt_object_handle vrt_compositing_mode_handle;
typedef vrt_object_handle vrt_render_target_handle;
typedef vrt_object_handle vrt_image_base_handle;
typedef vrt_image_base_handle vrt_image_2d_handle;
typedef vrt_image_base_handle vrt_image_cube_handle;
typedef vrt_image_base_handle vrt_image_text_handle;
typedef vrt_object_handle vrt_depth_buffer_handle;
typedef vrt_object_handle vrt_stencil_buffer_handle;
typedef vrt_object_handle vrt_program_handle;
typedef vrt_animatable_handle vrt_variable_handle;
typedef vrt_object_handle vrt_uniforms_handle;
typedef vrt_object_handle vrt_pass_handle;
typedef vrt_object_handle vrt_material_handle;
typedef vrt_object_handle vrt_material_handle;
typedef vrt_object_handle vrt_vertex_buffer_handle;
typedef vrt_object_handle vrt_index_buffer_handle;

typedef vrt_animatable_handle vrt_transformable_handle;
typedef vrt_transformable_handle vrt_node_handle;
typedef vrt_node_handle vrt_camera_handle;
typedef vrt_node_handle vrt_light_handle;
typedef vrt_node_handle vrt_mesh_handle;
typedef vrt_mesh_handle vrt_skinned_mesh_handle;
typedef vrt_node_handle vrt_group_handle;
typedef vrt_group_handle vrt_bone_handle;
typedef vrt_group_handle vrt_world_handle;

typedef vrt_transformable_handle vrt_texture_handle;
typedef vrt_texture_handle vrt_texture_2d_handle;
typedef vrt_texture_handle vrt_texture_cube_handle;
typedef vrt_texture_handle vrt_texture_frame_handle;


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*
 * object
 */
extern void vrt_object_inc_ref(vrt_object_handle handle);
extern void vrt_object_dec_ref(vrt_object_handle handle);
extern void vrt_object_release(vrt_object_handle handle);
extern void vrt_object_set_sync_object(vrt_object_handle handle, void *sync_object);


/*
 * render mode
 */
extern vrt_render_mode_handle vrt_create_render_mode(void);
extern void vrt_render_mode_set_render_camera(vrt_render_mode_handle mode, vrt_camera_handle camera);
extern void vrt_render_mode_set_scope(vrt_render_mode_handle mode, vrt_u32 scope);


/*
 * polygon mode
 */
extern vrt_polygon_mode_handle vrt_create_polygon_mode(void);
extern void vrt_polygon_mode_set_winding(vrt_polygon_mode_handle mode, VrtWindingMode winding);
extern void vrt_polygon_mode_set_cullng(vrt_polygon_mode_handle mode, VrtCullingMode culling);


/*
 * blender
 */
extern vrt_blender_handle vrt_create_blender(void);
extern void vrt_blender_set_blend_equation(vrt_blender_handle blender, VrtBlendEquation colorEquation, VrtBlendEquation alphaEquation);
extern void vrt_blender_set_blend_function(vrt_blender_handle blender, VrtBlendFactor srcColorFactor, VrtBlendFactor dstColorFactor, VrtBlendFactor srcAlphaFactor, VrtBlendFactor dstAlphaFactor);
extern void vrt_blender_set_blend_color(vrt_blender_handle blender, vrt_color_type color);


/*
 * stencil
 */
extern vrt_stencil_handle vrt_create_stencil(void);
extern void vrt_stencil_set_stencil_function(vrt_stencil_handle stencil, VrtStencilFunc frontFunc, vrt_s32 frontRefValue, vrt_u32 frontFuncMask, VrtStencilFunc backFunc, vrt_s32 backRefValue, vrt_u32 backFuncMask);
extern void vrt_stencil_set_stencil_operation(vrt_stencil_handle stencil, VrtStencilOp frontStencilFailOp, VrtStencilOp frontDepthFailOp, VrtStencilOp frontPassOp, VrtStencilOp backStencilFailOp, VrtStencilOp backDepthFailOp, VrtStencilOp backPassOp);
extern void vrt_stencil_set_stencil_mask(vrt_stencil_handle stencil, vrt_u32 frontWriteMask, vrt_u32 backWriteMask);


/*
 * compositing mode
 */
extern vrt_compositing_mode_handle vrt_create_compositing_mode(void);
extern void vrt_compositing_mode_set_blender(vrt_compositing_mode_handle compositing_mode, vrt_blender_handle blender);
extern void vrt_compositing_mode_set_stencil(vrt_compositing_mode_handle compositing_mode, vrt_stencil_handle stencil);
extern void vrt_compositing_mode_set_depth_test_enable(vrt_compositing_mode_handle compositing_mode, vrt_bool enable);
extern void vrt_compositing_mode_set_depth_write_enable(vrt_compositing_mode_handle compositing_mode, vrt_bool enable);
extern void vrt_compositing_mode_set_depth_func(vrt_compositing_mode_handle compositing_mode, VrtDepthFunc func);
extern void vrt_compositing_mode_set_depth_offset(vrt_compositing_mode_handle compositing_mode, vrt_float factor, vrt_float units);
extern void vrt_compositing_mode_set_color_mask(vrt_compositing_mode_handle compositing_mode, vrt_u32 mask);
extern void vrt_compositing_mode_set_dither(vrt_compositing_mode_handle compositing_mode, vrt_bool enable);


/*
 * render target
 */
extern vrt_render_target_handle vrt_create_render_target(void);
extern void vrt_render_target_attach_color_buffer(vrt_render_target_handle render_tartget, vrt_image_2d_handle image);
extern void vrt_render_target_attach_cube_face(vrt_render_target_handle render_tartget, vrt_image_cube_handle image, VrtImageTargetType type);
extern void vrt_render_target_attach_depth_buffer(vrt_render_target_handle render_tartget, vrt_depth_buffer_handle image);
extern void vrt_render_target_attach_stencil_buffer(vrt_render_target_handle render_tartget, vrt_stencil_buffer_handle image);
extern void vrt_render_target_set_clear_color(vrt_render_target_handle render_tartget, vrt_color_type color);
extern void vrt_render_target_enable_clear_color(vrt_render_target_handle render_tartget, vrt_bool enable);


/*
 * image base
 */
extern void vrt_image_base_invalidate(vrt_image_base_handle image, vrt_u32 w, vrt_u32 h, vrt_color_type_enum color_format);
extern void vrt_image_base_invalidate_from_source(vrt_image_base_handle image);


/*
 * image 2d
 */
extern vrt_image_2d_handle vrt_create_image_2d(vrt_u32 w, vrt_u32 h, vrt_color_type_enum color_format);
extern vrt_image_2d_handle vrt_create_image_2d_from_mem_ptr(const vrt_u8 *mem_ptr);
extern vrt_image_2d_handle vrt_create_image_2d_from_path(const vrt_wchar *file_path, vrt_bool is_dynamic);
extern vrt_image_2d_handle vrt_create_image_2d_from_image_buffer(const vrt_image_buffer_struct *image_buffer);


/*
 * image cube
 */
extern vrt_image_cube_handle vrt_create_image_cube(vrt_u32 w, vrt_u32 h, vrt_color_type_enum color_format);
extern vrt_image_cube_handle vrt_create_image_cube_from_mem_ptr(const vrt_u8 *mem_ptr);
extern vrt_image_cube_handle vrt_create_image_cube_from_path(const vrt_wchar *file_path, vrt_bool is_dynamic);


/*
 * image text
 */
extern vrt_image_text_handle vrt_create_image_text(
    vrt_u32 w,
    vrt_u32 h,
    vrt_color_type_enum color_format,
    vrt_image_redraw_funcptr_type redrawCallback,
    void *callbackUserData,
    vrt_size callbackUserDataSize);


/*
 * depth buffer
 */
extern vrt_depth_buffer_handle vrt_create_depth_buffer(vrt_u32 w, vrt_u32 h, vrt_color_type_enum color_format);


/*
 * stencil buffer
 */
extern vrt_stencil_buffer_handle vrt_create_stencil_buffer(vrt_u32 w, vrt_u32 h, vrt_color_type_enum color_format);


/*
 * texture
 */
extern void vrt_texture_set_image(vrt_texture_handle texture, vrt_image_base_handle image);
extern void vrt_texture_set_filter(vrt_texture_handle texture, VrtFilterMode levelFilter, VrtFilterMode imageFilter);
extern void vrt_texture_set_wrapping(vrt_texture_handle texture, VrtWrapMode wrapS, VrtWrapMode wrapT);


/*
 * texture 2d
 */
extern vrt_texture_2d_handle vrt_create_texture_2d(void);


/*
 * texture cube
 */
extern vrt_texture_cube_handle vrt_create_texture_cube(void);


/*
 * texture frame
 */
extern vrt_texture_frame_handle vrt_create_texture_frame(void);
extern void vrt_texture_frame_set_frame(vrt_texture_frame_handle texture, vrt_frame_handle image);


/*
 * program
 */
extern vrt_program_handle vrt_create_program_from_code_code(const vrt_char *vs, const vrt_char *fs);
extern vrt_program_handle vrt_create_program_from_code_path(const vrt_char *vs, const vrt_wchar *fs, vrt_bool is_dynamic);
extern vrt_program_handle vrt_create_program_from_code_resource(const vrt_char *vs, const vrt_res_id fs);
extern vrt_program_handle vrt_create_program_from_path_code(const vrt_wchar *vs, vrt_bool is_dynamic, const vrt_char *fs);
extern vrt_program_handle vrt_create_program_from_path_path(const vrt_wchar *vs, vrt_bool vs_is_dynamic, const vrt_wchar *fs, vrt_bool fs_is_dynamic);
extern vrt_program_handle vrt_create_program_from_path_resource(const vrt_wchar *vs, vrt_bool is_dynamic, const vrt_res_id fs);
extern vrt_program_handle vrt_create_program_from_resource_code(const vrt_res_id vs, const vrt_char *fs);
extern vrt_program_handle vrt_create_program_from_resource_path(const vrt_res_id vs, const vrt_wchar *fs, vrt_bool is_dynamic);
extern vrt_program_handle vrt_create_program_from_resource_resource(const vrt_res_id vs, const vrt_res_id fs);


/*
 * variable
 */
// TODO: support static name string
extern vrt_variable_handle vrt_create_shader_variable(const vrt_char *name, vrt_bool name_is_dynamic, vrt_type_id_enum type, vrt_size count, void *data);
extern void vrt_shader_variable_set_value(vrt_variable_handle variable, void *data);
extern void vrt_shader_variable_bind_uniform(vrt_variable_handle variable, vrt_object_handle object, VrtBindingProperty property_id);


/*
 * uniforms
 */
extern vrt_uniforms_handle vrt_create_uniforms(void);
extern void vrt_uniforms_add_variable(vrt_uniforms_handle uniforms, vrt_variable_handle variable);
extern void vrt_uniforms_remove_all(vrt_uniforms_handle uniforms);


/*
 * pass
 */
extern vrt_pass_handle vrt_create_pass(VrtPassGeometryType type);
extern void vrt_pass_set_program(vrt_pass_handle pass, vrt_program_handle program);
extern void vrt_pass_add_uniforms(vrt_pass_handle pass, vrt_uniforms_handle uniforms);
extern void vrt_pass_remove_all_uniforms(vrt_pass_handle pass);
extern void vrt_pass_set_render_mode(vrt_pass_handle pass, vrt_render_mode_handle render_mode);
extern void vrt_pass_set_polygon_mode(vrt_pass_handle pass, vrt_polygon_mode_handle polygon_mode);
extern void vrt_pass_set_compositing_mode(vrt_pass_handle pass, vrt_compositing_mode_handle compositing_mode);
extern void vrt_pass_set_render_target(vrt_pass_handle pass, vrt_render_target_handle render_target);
extern void vrt_pass_set_render_type(vrt_pass_handle pass);
extern void vrt_pass_set_tessellation_level(vrt_pass_handle pass, vrt_u32 u_level, vrt_u32 v_level);


/*
 * material
 */
extern vrt_material_handle vrt_create_material(vrt_u32 pass_count);
extern void vrt_material_set_pass(vrt_material_handle material, vrt_u32 idx, vrt_pass_handle pass);


/*
 * transformable
 */
extern void vrt_transformable_set_translation(vrt_transformable_handle transformable, const vrt_float *translation);
extern void vrt_transformable_set_orientation(vrt_transformable_handle transformable, const vrt_float *orientation);
extern void vrt_transformable_set_scale(vrt_transformable_handle transformable, const vrt_float *scale);
extern void vrt_transformable_set_pivot(vrt_transformable_handle transformable, const vrt_float *pivot);
extern void vrt_transformable_set_transform(vrt_transformable_handle transformable, const vrt_float *transform);

extern void vrt_transformable_get_translation(vrt_transformable_handle transformable, vrt_float *translation);
extern void vrt_transformable_get_orientation(vrt_transformable_handle transformable, vrt_float *orientation);
extern void vrt_transformable_get_scale(vrt_transformable_handle transformable, vrt_float *scale);
extern void vrt_transformable_get_pivot(vrt_transformable_handle transformable, vrt_float *pivot);
extern void vrt_transformable_get_transform(vrt_transformable_handle transformable, vrt_float *transform);

/*
 * node
 */
extern void vrt_node_set_opacity(vrt_node_handle node, vrt_float opacity);
extern void vrt_node_set_visible(vrt_node_handle node, vrt_bool visible);


/*
 * camera
 */
extern vrt_camera_handle vrt_create_camera(void);
extern void vrt_camera_set_projection(vrt_camera_handle camera, const vrt_float *projection_transform);
extern void vrt_camera_set_view(vrt_camera_handle camera, const vrt_float *view_transform);


/*
 * light
 */
extern vrt_light_handle vrt_create_light(void);
extern void vrt_light_set_color(vrt_light_handle light, vrt_color_type color);
extern void vrt_light_set_intensity(vrt_light_handle light, vrt_float intensity);


/*
 * mesh
 */
extern vrt_mesh_handle vrt_create_mesh(void);
extern vrt_mesh_handle vrt_create_mesh_from_mem_ptr(const vrt_u8 *mem_ptr, vrt_size mem_size);
extern vrt_mesh_handle vrt_create_mesh_from_path(const vrt_wchar *file_path, vrt_bool is_dynamic);
extern vrt_mesh_handle vrt_create_mesh_from_resource(const vrt_res_id res_id);
extern vrt_mesh_handle vrt_create_plane_mesh(vrt_float width, vrt_float height);
extern vrt_mesh_handle vrt_create_box_mesh(vrt_float length, vrt_float width, vrt_float height);
extern vrt_mesh_handle vrt_create_sphere_mesh(vrt_float radius);
extern vrt_mesh_handle vrt_create_procedural_mesh(const void *procedural_mesh);
extern void vrt_mesh_set_material(vrt_mesh_handle mesh, vrt_u32 idx, vrt_material_handle material);
extern void vrt_mesh_set_submesh_visible(vrt_mesh_handle mesh, vrt_u32 idx, vrt_bool visible);
//extern void vrt_mesh_set_weight(vrt_mesh_handle mesh, vrt_u32 idx, vrt_float weight);


/*
 * skinned mesh
 */
extern vrt_skinned_mesh_handle vrt_create_skinned_mesh(void);
extern vrt_skinned_mesh_handle vrt_create_skinned_mesh_from_mem_ptr(const vrt_u8 *mem_ptr, vrt_size mem_size);
extern vrt_skinned_mesh_handle vrt_create_skinned_mesh_from_path(const vrt_wchar *file_path, vrt_bool is_dynamic);
extern vrt_skinned_mesh_handle vrt_create_skinned_mesh_from_resource(const vrt_res_id res_id);
extern vrt_skinned_mesh_handle vrt_create_procedural_skinned_mesh(const void *procedural_mesh);
extern void vrt_skinned_mesh_set_skeleton(vrt_skinned_mesh_handle mesh, vrt_bone_handle skeleton);


/*
 * group
 */
extern vrt_group_handle vrt_create_group(void);
extern void vrt_group_add_child(vrt_group_handle group, vrt_node_handle node);
extern void vrt_group_remove_all_children(vrt_group_handle group);
extern void vrt_group_set_material(vrt_group_handle group, vrt_material_handle material);


/*
 * bone
 */
extern vrt_bone_handle vrt_create_bone(void);


/*
 * world
 */
extern vrt_world_handle vrt_create_world(void);
extern void vrt_world_set_active_camera(vrt_world_handle world, vrt_camera_handle camera);
extern void vrt_world_set_background(vrt_world_handle world, vrt_image_2d_handle background);
extern void vrt_world_enable_clear_depth(vrt_world_handle world, vrt_bool enable, vrt_bool clear_before_draw);
extern void vrt_world_enable_clear_stencil(vrt_world_handle world, vrt_bool enable, vrt_bool clear_before_draw);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __VRT_3D_H__ */

