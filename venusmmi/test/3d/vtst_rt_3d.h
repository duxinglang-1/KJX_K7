/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  vtst_rt_3d.h
 *
 * Project:
 * --------
 *  Venus Regression Test
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VTST_RT_3D_H__
#define __VTST_RT_3D_H__
#ifdef __VENUS_3D_UI_ENGINE__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Autotest Item Predeclaration
 * Please add your test item here
 *****************************************************************************/

// Interaction Items > 3D
VtstTestResultEnum vtst_rt_3d_background(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_pick(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_text_mesh(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_animation(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_auto_animate(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_timeline_chain(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_timeline_chain_current_to(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_timeline_chain_current_by(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_timeline_restart(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_timeline_stop(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_timer_trigger_timeline(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_scene_graph(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_transformable(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_node(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_group(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_world(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_camera(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_mesh(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_viewport(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_frame_texture(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_texture_transform(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_projective_texture(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_environment_map(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_procedural_mesh(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_dispose_object(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_close_object(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_skinned_mesh(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_auto_depth_buffer(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_frame_buffer(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_sw_owner_draw(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_owner_draw(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_owner_draw_init_deinit(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_material_system(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_multi_pass(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_stencil_buffer(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_render_target(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_post_processing(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_group_material(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_frame_material(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_builtin_uniforms(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_color_frame_material(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_mesh_loader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_material_loader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_scene_loader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_animation_loader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_color_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_phong_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_lightmap_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_amboccmap_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_specularmap_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_bumpmap_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_fresnel_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_glass_shader(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_arcball(VfxU32 param);
VtstTestResultEnum vtst_rt_3d_disable_color_key(VfxU32 param);


/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/

VTST_BEGIN_DEF_MENU(L"3D Basic", v3d_basic)
    VTST_DEF_ITEM_TEST(L"3D Background", vtst_rt_3d_background, 0)
    VTST_DEF_ITEM_TEST(L"3D Pick", vtst_rt_3d_pick, 0)
    VTST_DEF_ITEM_TEST(L"3D Text", vtst_rt_3d_text_mesh, 0)
VTST_END_DEF_MENU(v3d_basic);

VTST_BEGIN_DEF_MENU(L"Animation System", v3d_animation_system)
    VTST_DEF_ITEM_TEST(L"Animation",                    vtst_rt_3d_animation, 0)
    VTST_DEF_ITEM_TEST(L"Auto-Animation",               vtst_rt_3d_auto_animate, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Chain",               vtst_rt_3d_timeline_chain, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Chain Current-To",    vtst_rt_3d_timeline_chain_current_to, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Chain Current-By",    vtst_rt_3d_timeline_chain_current_by, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Restart",             vtst_rt_3d_timeline_restart, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Time Stop",           vtst_rt_3d_timeline_stop, 0)
    VTST_DEF_ITEM_TEST(L"Timer Trigger 3D Timeline",    vtst_rt_3d_timer_trigger_timeline, 0)
VTST_END_DEF_MENU(v3d_animation_system)

VTST_BEGIN_DEF_MENU(L"Scene Graph", v3d_scene_graph)
    VTST_DEF_ITEM_TEST(L"Scene Graph Construct",    vtst_rt_3d_scene_graph, 0)
    VTST_DEF_ITEM_TEST(L"Transformable",            vtst_rt_3d_transformable, 0)
    VTST_DEF_ITEM_TEST(L"Node",                     vtst_rt_3d_node, 0)
    VTST_DEF_ITEM_TEST(L"Group",                    vtst_rt_3d_group, 0)
    VTST_DEF_ITEM_TEST(L"World",                    vtst_rt_3d_world, 0)
    VTST_DEF_ITEM_TEST(L"Camera",                   vtst_rt_3d_camera, 0)
    VTST_DEF_ITEM_TEST(L"Mesh",                     vtst_rt_3d_mesh, 0)
    VTST_DEF_ITEM_TEST(L"3D in 2D Frame",           vtst_rt_3d_viewport, 0)
    VTST_DEF_ITEM_TEST(L"2D in 3D World",           vtst_rt_3d_frame_texture, 0)
    VTST_DEF_ITEM_TEST(L"Texture Transform",        vtst_rt_3d_texture_transform, 0)
    VTST_DEF_ITEM_TEST(L"Projective Texture",       vtst_rt_3d_projective_texture, 0)
    VTST_DEF_ITEM_TEST(L"Environment Map",          vtst_rt_3d_environment_map, 0)
    VTST_DEF_ITEM_TEST(L"Procedural Mesh",          vtst_rt_3d_procedural_mesh, 0)
    VTST_DEF_ITEM_TEST(L"Dispose Object",           vtst_rt_3d_dispose_object, 0)
    VTST_DEF_ITEM_TEST(L"Close Object",             vtst_rt_3d_close_object, 0)
    VTST_DEF_ITEM_TEST(L"Skinned Mesh",             vtst_rt_3d_skinned_mesh, 0)
    VTST_DEF_ITEM_TEST(L"Auto Depth Buffer",        vtst_rt_3d_auto_depth_buffer, 0)
    VTST_DEF_ITEM_TEST(L"Frame Buffer Object",      vtst_rt_3d_frame_buffer, 0)
    VTST_DEF_ITEM_TEST(L"Disable Color Key",        vtst_rt_3d_disable_color_key, 0)    
VTST_END_DEF_MENU(v3d_scene_graph)

VTST_BEGIN_DEF_MENU(L"Material System", v3d_material_system)
    VTST_DEF_ITEM_TEST(L"Render State",             vtst_rt_3d_material_system, 0)
    VTST_DEF_ITEM_TEST(L"Multi Pass Rendering",     vtst_rt_3d_multi_pass, 0)
    VTST_DEF_ITEM_TEST(L"Stencil Buffer",           vtst_rt_3d_stencil_buffer, 0)
    VTST_DEF_ITEM_TEST(L"Render Target",            vtst_rt_3d_render_target, 0)
    VTST_DEF_ITEM_TEST(L"Post Processing",          vtst_rt_3d_post_processing, 0)
    VTST_DEF_ITEM_TEST(L"Group Material",           vtst_rt_3d_group_material, 0)
    VTST_DEF_ITEM_TEST(L"Frame Material",           vtst_rt_3d_frame_material, 0)
    VTST_DEF_ITEM_TEST(L"Builtin Uniforms",         vtst_rt_3d_builtin_uniforms, 0)
    VTST_DEF_ITEM_TEST(L"Color Frame Material",     vtst_rt_3d_color_frame_material, 0)    
VTST_END_DEF_MENU(v3d_material_system)

// 3D Shader Library
VTST_BEGIN_DEF_MENU(L"Shader Library", v3d_slib)
    VTST_DEF_ITEM_TEST(L"Color Texture",            vtst_rt_3d_color_shader, 0)
    VTST_DEF_ITEM_TEST(L"Phong Texture",            vtst_rt_3d_phong_shader, 0)
    VTST_DEF_ITEM_TEST(L"Light Map",                vtst_rt_3d_lightmap_shader, 0)
    VTST_DEF_ITEM_TEST(L"Amb. Occ. Map",            vtst_rt_3d_amboccmap_shader, 0)
    //VTST_DEF_ITEM_TEST(L"Specular Map",             vtst_rt_3d_specularmap_shader, 0)
    VTST_DEF_ITEM_TEST(L"Bump Map",                 vtst_rt_3d_bumpmap_shader, 0)
    VTST_DEF_ITEM_TEST(L"Reflection / Refraction",  vtst_rt_3d_fresnel_shader, 0)
    VTST_DEF_ITEM_TEST(L"Window Glass",             vtst_rt_3d_glass_shader, 0)
VTST_END_DEF_MENU(v3d_slib)

// 3D Asset Loader
VTST_BEGIN_DEF_MENU(L"Asset Loader", v3d_asset)
    VTST_DEF_ITEM_TEST(L"Mesh Loader",          vtst_rt_3d_mesh_loader, 0)
    VTST_DEF_ITEM_TEST(L"Material Loader",      vtst_rt_3d_material_loader, 0)
    VTST_DEF_ITEM_TEST(L"Scene Graph Loader",   vtst_rt_3d_scene_loader, 0)
    VTST_DEF_ITEM_TEST(L"Animation Loader",     vtst_rt_3d_animation_loader, 0)
    VTST_DEF_ITEM_MENU(L"Shader Library",       v3d_slib)
VTST_END_DEF_MENU(v3d_asset)

// 3D Owner Draw
VTST_BEGIN_DEF_MENU(L"Owner Draw", v3d_owner_draw)
    VTST_DEF_ITEM_TEST(L"SW Owner Draw",        vtst_rt_3d_sw_owner_draw, 0)
    VTST_DEF_ITEM_TEST(L"GLES Owner Draw",      vtst_rt_3d_owner_draw, 0)
    VTST_DEF_ITEM_TEST(L"Init / Deinit",        vtst_rt_3d_owner_draw_init_deinit, 0)
VTST_END_DEF_MENU(v3d_owner_draw)

// Interaction Test > 3D
VTST_BEGIN_DEF_MENU(L"3D", venus_3d)
    VTST_DEF_ITEM_MENU(L"3D Basic", v3d_basic)
    VTST_DEF_ITEM_MENU(L"Animation System", v3d_animation_system)
    VTST_DEF_ITEM_MENU(L"Scene Graph",      v3d_scene_graph)
    VTST_DEF_ITEM_MENU(L"Material System",  v3d_material_system)
    VTST_DEF_ITEM_MENU(L"Asset Loader",     v3d_asset)
    VTST_DEF_ITEM_MENU(L"Owner Draw",       v3d_owner_draw)
    VTST_DEF_ITEM_TEST(L"Arc Ball",         vtst_rt_3d_arcball, 0)
VTST_END_DEF_MENU(venus_3d)

#endif /* __VENUS_3D_UI_ENGINE__ */
#endif /* __VTST_RT_3D_H__ */

