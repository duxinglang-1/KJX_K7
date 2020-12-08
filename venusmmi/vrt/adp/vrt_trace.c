/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vrt_trace.c
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  VRT Debugging Trace Utilities
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
#include "vrt_platform.h"
#include "vrt_datatype.h"
#include "vrt_draw_cmd.h"
#include "vrt_system.h"
#include "vrt_trace.h"

#include "gdi_image.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
extern vrt_bool vrt_render_is_need_temp_buffer(const vrt_frame_property_struct *fp);
extern vrt_u32 vrt_dbg_get_frame_cache_size(void *cache);
extern void vrt_render_trace_world(const vrt_object_handle world, vrt_s32 level);

#if defined(__MTK_TARGET__)
vrt_bool g_vrt_enable_swla_log = VRT_FALSE;
#endif

vrt_bool g_vrt_trace_is_per_frame_enabled = VRT_FALSE;
vrt_s32 g_vrt_trace_cmd = 0;
vrt_s32 g_vrt_trace_cache = 0;
vrt_frame_property_struct *g_vrt_trace_monitor_frame = NULL;

#if defined(__MTK_TARGET__)
    #define VRT_MUST_TRACE2(x)
#else
    #define VRT_MUST_TRACE2(x)  if (g_vrt_trace_cmd > 1) kal_printf x
#endif

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void vrt_trace_frame(vrt_frame_property_struct *fp)
{
#if !defined(__MTK_TARGET__)
    vrt_srect_struct rect = fp->dirty_info.last_region;
#endif

    vrt_bool is_need_buffer = vrt_render_is_need_temp_buffer(fp);

    VRT_MUST_TRACE((
        "FRAME(%x %x) c(%.8x %1.2f %c) o(%c %c %c %c) b(%d %d (%d %d %d %d) (%d %d %d %d)) t(%c) d(%c %c %c %c) r(%c %d %c) c(%c %c %c %d) h(%c %c) f(%c %c %c) e(%c %c)\n",
        // FRAME
        fp, 
        fp->parent,

        // c
        fp->background_color,
        fp->opacity,
        is_need_buffer ? 'T' : 'F',

        // o
        fp->settings.opaque_mode == VRT_FRAME_OPAQUE_MODE_AUTO ? 'A' :
        fp->settings.opaque_mode == VRT_FRAME_OPAQUE_MODE_TRANSLUCENT ? 'T' :
        fp->settings.opaque_mode == VRT_FRAME_OPAQUE_MODE_COLOR_KEY? 'C' : 'O',
        
        fp->auto_opaque == VRT_FRAME_OPAQUE_MODE_AUTO ? 'A' :
        fp->auto_opaque == VRT_FRAME_OPAQUE_MODE_TRANSLUCENT ? 'T' :
        fp->auto_opaque == VRT_FRAME_OPAQUE_MODE_COLOR_KEY? 'C' : 'O',

        fp->is_covered_by_content ? 'T' : 'F',
        fp->is_covered_by_child ? 'T' : 'F',

        // b
        fp->pos.x,
        fp->pos.y,
        fp->bounds.origin.x,
        fp->bounds.origin.y,
        fp->bounds.size.width,
        fp->bounds.size.height,
        rect.origin.x,
        rect.origin.y,
        rect.size.width,
        rect.size.height,

        // t
        fp->transform.type == VRT_TRANSFORM_TYPE_IDENTITY ? 'I' :
        vrt_transform_is_identity(&fp->transform) == VRT_TRUE ? 'F' :
        fp->transform.type == VRT_TRANSFORM_TYPE_AFFINE ? 'A' : 'P',

        // d
        fp->is_dirty ? 'T' : 'F',
        fp->is_content_dirty ? 'T' : 'F',
        fp->is_tl_dirty ? 'T' : 'F',
        fp->is_content_tl_dirty ? 'T' : 'F',

        // r
        fp->is_region_dirty ? 'T' : 'F',
        fp->dirty_info.timestamp,
        fp->is_region_valid ? 'T' : 'F',

        // c
        VRT_CACHE_IS_SUGGESTED(fp) ? 'T' : 'F',
        fp->cache_info.cache ? 'T' : 'F',
        fp->is_cache_valid ? 'T' : 'F',
        fp->cache_info.cache ? vrt_dbg_get_frame_cache_size(fp->cache_info.cache) : 0,

        // h
        fp->settings.cache_mode == VRT_CACHE_MODE_AUTO ? 'A' :
        fp->settings.cache_mode == VRT_CACHE_MODE_PREVENT_PARENTS ? 'S' :
        fp->settings.cache_mode == VRT_CACHE_MODE_PREVENT ? 'P' :
        fp->settings.cache_mode == VRT_CACHE_MODE_FORCE ? 'F' :
        fp->settings.cache_mode == VRT_CACHE_MODE_RESOURCE ? 'R' :
        fp->settings.cache_mode == VRT_CACHE_MODE_FREEZE ? 'Z' : 'T',

        fp->cache_hints == VRT_CACHE_HINTS_RESOURCE ? 'R' :
        fp->cache_hints == VRT_CACHE_HINTS_FREEZE ? 'Z' :
        fp->cache_hints == VRT_CACHE_HINTS_SUGGESTED ? 'S' :
        fp->cache_hints == VRT_CACHE_HINTS_PRECACHE ? 'C' :
        fp->cache_hints == VRT_CACHE_HINTS_RESERVE ? 'V' :
        fp->cache_hints == VRT_CACHE_HINTS_OPTIONAL ? 'O' :
        fp->cache_hints == VRT_CACHE_HINTS_USELESS ? 'U' :
        fp->cache_hints == VRT_CACHE_HINTS_HIDDEN ? 'H' : 'P',

        // f
        fp->is_full_frame ? 'T' : 'F',
        fp->is_pure_color ? 'T' : 'F',
        fp->is_pure_img_buf ? 'T' : 'F',

        // e
        fp->settings.property_effect ? 'T' : 'F',
        VRT_FRAME_HAS_CUSTOM_RENDER(fp->settings) ? 'T' : 'F'
    ));
}


/*****************************************************************************
 * FUNCTION
 *  vrt_trace_draw_cmd_queue
 * DESCRIPTION
 *  Trace VRT draw command queue
 * PARAMETERS
 *  cmd_queue       [IN]    draw command queue
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_trace_draw_cmd_queue(vrt_canvas_draw_cmd_queue_struct *cmd_queue)
{
    vrt_s32 cmd_index, j, level = 0, draw_cmd_num;
    vrt_draw_cmd_struct *cmd;

    draw_cmd_num = vrt_draw_cmd_queue_get_tail_index(cmd_queue);

    for (cmd_index = 0; cmd_index < draw_cmd_num; cmd_index += cmd->draw_cmd_size)
    {
        cmd = vrt_draw_cmd_queue_get_args(cmd_queue, cmd_index);

        switch(cmd->draw_cmd_type)
        {
        case VRT_DRAW_CMD_PUSH_AND_SET_ACTIVE_FRAME:
            break;

        case VRT_DRAW_CMD_POP_AND_RESTORE_FRAME:
            level--;
            //break;

        default:
            if (g_vrt_trace_cmd > 1)
            {
                j = level;
                while (j--)
                    VRT_MUST_TRACE2(("-"));
            }
            break;
        }

        switch(cmd->draw_cmd_type)
        {
        case VRT_DRAW_CMD_NOP:
        case VRT_DRAW_CMD_END:
		case VRT_DRAW_CMD_DRAW_NON:
            break;

        case VRT_DRAW_CMD_COMMENT:
            {
                vrt_draw_cmd_comment_struct *cmd_args = (vrt_draw_cmd_comment_struct *)cmd;
                
                if (cmd_args->string_offset & 0x1)
                {
                    VRT_MUST_TRACE(("[%s]\n", (vrt_u8*)((vrt_u8*)cmd_args + (cmd_args->string_offset>>1))));
                }
                else
                {
                    VRT_MUST_TRACE(("[%s]\n", (vrt_u8*)(cmd_args->string_offset)));
                }
            }
            break;

        /* Frame commands */
        case VRT_DRAW_CMD_PUSH_AND_SET_ACTIVE_FRAME:
            {
                vrt_draw_cmd_push_and_set_active_frame_struct *cmd_args = (vrt_draw_cmd_push_and_set_active_frame_struct *)cmd;

                vrt_frame_property_struct* fp = cmd_args->active_properties;
                j = level;
                while (j--)
                    VRT_MUST_TRACE(("-"));

                level++;
                vrt_trace_frame(fp);
#ifdef VRT_3D
                if (fp->settings.world)
                {
                    vrt_render_trace_world(fp->settings.world, level);
                }
#endif /* VRT_3D */
            }
            break;

        case VRT_DRAW_CMD_POP_AND_RESTORE_FRAME:
            VRT_MUST_TRACE2(("POP_FRAME\n"));
            break;

        case VRT_DRAW_CMD_SET_CLIP:
            VRT_MUST_TRACE2(("SET_CLIP\n"));
            break;

        case VRT_DRAW_CMD_SET_FILL_COLOR:
            VRT_MUST_TRACE2(("SET_FILL_COLOR\n"));
            break;

        case VRT_DRAW_CMD_SET_STROKE_COLOR:
            VRT_MUST_TRACE2(("SET_STROKE_COLOR\n"));
            break;

        case VRT_DRAW_CMD_SET_FALLBACK_IMAGE:
            VRT_MUST_TRACE2(("SET_FALLBACK_IMAGE\n"));
            break;

        case VRT_DRAW_CMD_FILL_RECT:
            VRT_MUST_TRACE2(("SET_STROKE_COLOR\n"));
            break;

        case VRT_DRAW_CMD_DRAW_PIXEL:
            VRT_MUST_TRACE2(("SET_STROKE_COLOR\n"));
            break;

        case VRT_DRAW_CMD_DRAW_LINE:
            VRT_MUST_TRACE2(("DRAW_LINE\n"));
            break;

        case VRT_DRAW_CMD_DRAW_RECT:
            VRT_MUST_TRACE2(("DRAW_RECT\n"));
            break;

        case VRT_DRAW_CMD_DRAW_AA_LINE:
            VRT_MUST_TRACE2(("DRAW_AA_LINE\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_FROM_MEM:
            VRT_MUST_TRACE2(("DRAW_IMG_FROM_MEM\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_FROM_RES_ID:
            VRT_MUST_TRACE2(("DRAW_IMG_FROM_RES_ID\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_FROM_FILE:
            VRT_MUST_TRACE2(("DRAW_IMG_FROM_FILE\n"));
            break;

        case VRT_DRAW_CMD_DRAW_RESIZED_IMG_FROM_MEM:
            VRT_MUST_TRACE2(("DRAW_RESIZED_IMG_FROM_MEM\n"));
            break;

        case VRT_DRAW_CMD_DRAW_RESIZED_IMG_FROM_RES_ID:
            VRT_MUST_TRACE2(("DRAW_RESIZED_IMG_FROM_RES_ID\n"));
            break;

        case VRT_DRAW_CMD_DRAW_RESIZED_IMG_FROM_FILE:
            VRT_MUST_TRACE2(("DRAW_RESIZED_IMG_FROM_FILE\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_RES_ID:
        case VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_MEM:
            {
                void *cmd_args;
                vrt_u8 *img_p;
                vrt_s32 w, h;
            #if !defined(__MTK_TARGET__)
                vrt_frame_content_placement_type_enum placement;
            #endif

                cmd_args = (void*)cmd;
                
                if (VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_RES_ID == cmd->draw_cmd_type)
                {
                    img_p = vrt_sys_res_image_lock(((vrt_draw_cmd_draw_img_content_from_res_id_struct *)cmd_args)->res_id);
                #if !defined(__MTK_TARGET__)
                    placement = ((vrt_draw_cmd_draw_img_content_from_res_id_struct *)cmd_args)->place_type;
                #endif
                }
                else 
                {
                    img_p = ((vrt_draw_cmd_draw_img_content_from_mem_struct *)cmd_args)->image_ptr;
                #if !defined(__MTK_TARGET__)
                    placement = ((vrt_draw_cmd_draw_img_content_from_mem_struct *)cmd_args)->place_type;
                #endif
                }

                if (img_p)
                {
                    gdi_image_get_dimension((vrt_u8*)img_p, &w, &h);
                }
                else
                {
                    w = 0;
                    h = 0;
                }

                VRT_MUST_TRACE2((
                    "DRAW_IMG_CONTENT_FROM_MEM size(%d %d) placement(%s)\n",
                    w, h,
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT ? "TOP_LEFT" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP ? "TOP" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP_RIGHT ? "TOP_RIGHT" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_LEFT ? "LEFT" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_CENTER ? "CENTER" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT ? "RIGHT" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_LEFT ? "BOTTOM_LEFT" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM ? "BOTTOM" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_RIGHT ? "BOTTOM_RIGHT" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE ? "RESIZE" :
                    placement == VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT ? "RESIZE_ASPECT" : "RESIZE_ASPECT_FILL"
                ));
            }
            break;

        case VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_FILE:
            VRT_MUST_TRACE2(("DRAW_IMG_CONTENT_FROM_FILE\n"));
            break;

        case VRT_DRAW_CMD_DRAW_LAYER:
            VRT_MUST_TRACE2(("DRAW_LAYER\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_LAYER:
            VRT_MUST_TRACE2(("DRAW_IMG_CONTENT_FROM_LAYER\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_BUF:
            VRT_MUST_TRACE2(("DRAW_IMG_BUF\n"));
            break;

        case VRT_DRAW_CMD_DRAW_RESIZED_IMG_BUF:
            VRT_MUST_TRACE2(("DRAW_RESIZED_IMG_BUF\n"));
            break;

        case VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_IMG_BUF:
            VRT_MUST_TRACE2(("DRAW_IMG_CONTENT_FROM_IMG_BUF\n"));
            break;

        case VRT_DRAW_CMD_SET_FONT:
            VRT_MUST_TRACE2(("SET_FONT\n"));
            break;

        case VRT_DRAW_CMD_SET_ELLIPSIS:
            VRT_MUST_TRACE2(("SET_ELLIPSIS\n"));
            break;

        case VRT_DRAW_CMD_DRAW_TEXT:
            {
                vrt_draw_cmd_draw_text_struct *cmd_args = (vrt_draw_cmd_draw_text_struct *)cmd;
                
                if (cmd_args->string & 0x1)
                {
                    VRT_MUST_TRACE2(("DRAW_TEXT %S\n", (vrt_u8*)((vrt_u8*)cmd_args + (cmd_args->string>>1))));
                }
                else
                {
                    VRT_MUST_TRACE2(("DRAW_TEXT %S\n", (vrt_u8*)(cmd_args->string)));
                }
            }
            break;

        case VRT_DRAW_CMD_DRAW_TEXT_N:
            {
                vrt_draw_cmd_draw_text_n_struct *cmd_args = (vrt_draw_cmd_draw_text_n_struct *)cmd;
                
                if (cmd_args->string & 0x1)
                {
                    VRT_MUST_TRACE2(("DRAW_TEXT_N %S\n", (vrt_u8*)((vrt_char*)cmd_args + (cmd_args->string>>1))));
                }
                else
                {
                    VRT_MUST_TRACE2(("DRAW_TEXT_N %S\n", (vrt_u8*)((vrt_u32*)cmd_args->string)));
                }
            }
            break;

        case VRT_DRAW_CMD_DRAW_TEXT_N_BASELINE:
            {
                vrt_draw_cmd_draw_text_n_baseline_struct *cmd_args = (vrt_draw_cmd_draw_text_n_baseline_struct *)cmd;
                
                if (cmd_args->string & 0x1)
                {
                    VRT_MUST_TRACE2(("DRAW_TEXT_N_BASELINE %S\n", (vrt_u8*)((vrt_u8*)cmd_args + (cmd_args->string>>1))));
                }
                else
                {
                    VRT_MUST_TRACE2(("DRAW_TEXT_N_BASELINE %S\n", (vrt_u8*)((vrt_u32*)cmd_args->string)));
                }
            }
            break;
#ifdef VRT_3D
        case VRT_DRAW_CMD_DRAW_WORLD:
            VRT_MUST_TRACE2(("VRT_DRAW_CMD_DRAW_WORLD\n"));
            break;
#endif /* VRT_3D */
        default:
            VRT_ASSERT(0);

        }

        if (cmd->do_pop == VRT_TRUE)
        {
            level--;
            if (g_vrt_trace_cmd > 1)
            {
                j = level;
                while (j--)
                    VRT_MUST_TRACE2(("-"));
            }
            VRT_MUST_TRACE2(("POP_FRAME\n"));
        }
    }
}

void vrt_trace_set_monitor_frame(vrt_frame_property_struct *fp)
{
    g_vrt_trace_monitor_frame = fp;
}


