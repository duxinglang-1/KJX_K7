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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vrt_frame_gprot.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  Exported interface of frame properties
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

#ifndef __VRT_FRAME_GPROT_H__
#define __VRT_FRAME_GPROT_H__


#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_platform.h"
#include "vrt_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VRT_FRAME_HAS_CUSTOM_RENDER(st)     (st.custom_render)

#define VRT_CACHE_IS_SUGGESTED(fp) (fp->cache_hints < VRT_CACHE_HINTS_NOT_SUGGESTED)
#define VRT_CACHE_IS_NOT_SUGGESTED(fp) (fp->cache_hints >= VRT_CACHE_HINTS_NOT_SUGGESTED)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* Pre-defined _vrt_frame_property_struct */
struct _vrt_frame_property_struct;

typedef struct _vrt_frame_dirty_info_struct
{
    vrt_u32                 timestamp;          // timestamp for last time region update.
    vrt_srect_struct        last_region;
    struct _vrt_frame_dirty_info_struct *region_parent;
} vrt_frame_dirty_info_struct;

/* frame cache hint */
typedef enum
{
    VRT_CACHE_HINTS_RESOURCE,           // force to cache even it is hidden
    VRT_CACHE_HINTS_FREEZE,             // freeze frame cache has higher priority
    VRT_CACHE_HINTS_SUGGESTED,          // suggested by VRT in this frame
    VRT_CACHE_HINTS_PRECACHE,           // suggested by VRT in next frame

    VRT_CACHE_HINTS_NOT_SUGGESTED,
    VRT_CACHE_HINTS_RESERVE = VRT_CACHE_HINTS_NOT_SUGGESTED, // Reserve cache if it is existing
    VRT_CACHE_HINTS_OPTIONAL,           // optional in this frame
    VRT_CACHE_HINTS_USELESS,            // useless in this frame
    VRT_CACHE_HINTS_HIDDEN,             // no visible in this frame
    VRT_CACHE_HINTS_PREVENT,            // prevent to cache
    VRT_CACHE_HINTS_END_OF_ENUM
} vrt_cache_hints_enum;

/* frame cache information */
typedef struct
{
    void *cache;
} vrt_frame_cache_info_struct;

/* programmable frame property effect */
typedef struct
{
    struct _vrt_frame_property_struct *prev;
    struct _vrt_frame_property_struct *next;

    const struct _vrt_frame_property_struct *watch_frame;
    vrt_frame_property_effect_funcptr_type callback;
    vrt_u32 user_data_size;
    vrt_frame_property_effect_trigger_type_enum trigger_type;
    vrt_bool is_first_time;
} vrt_frame_property_effect_struct;

/* programmable frame property effect */
typedef struct
{
    struct _vrt_frame_property_struct *prev;
    struct _vrt_frame_property_struct *next;

    vrt_frame_property_monitor_funcptr_type callback;
    vrt_u32 user_data_size;
} vrt_frame_property_monitor_struct;

/* frame properties which are VRT read-only */
typedef struct
{
    vrt_frame_property_effect_struct *property_effect; /* programmable frame property effect */
    vrt_frame_property_monitor_struct *property_monitor; /* programmable frame property monitor */
    void *custom_render;                        /* custom render (owner draw or filter) */
    vrt_u32 layer_handle;                       /* layer frame handle */
    void *anim_image;                             /* animation image */
#ifdef VRT_3D
    vrt_object_handle material;                 /* material (for 3D) */
    vrt_object_handle world;                    /* world (for 3D) */
#endif
    vrt_frame_hints_enum frame_hints            : VRT_BIT_COUNT(VRT_FRAME_HINTS_END_OF_ENUM);          /* frame hints */
    vrt_cache_mode_enum cache_mode              : VRT_BIT_COUNT(VRT_CACHE_MODE_END_OF_ENUM);           /* cache mode */
    vrt_frame_opaque_mode_enum opaque_mode      : VRT_BIT_COUNT(VRT_FRAME_OPAQUE_MODE_END_OF_ENUM);    /* frame content opaque mode */
    vrt_frame_culling_type_enum culling_type    : VRT_BIT_COUNT(VRT_FRAME_CULLING_TYPE_END_OF_ENUM);   /* culling type */
    vrt_render_quality_enum quality             : VRT_BIT_COUNT(VRT_RENDER_QUALITY_END_OF_ENUM);       /* render quality */
    vrt_bit is_z_sort_child                     : 1;    /* z sort child frames */
    vrt_bit animate_image_update                : 1;    /* animation image need update */
} vrt_frame_setting_struct;

/* frame properties */
typedef struct _vrt_frame_property_struct
{
    /* 
     * animatable properties 
     */
    vrt_point_struct        pos;                /* anchor point to parent's origin */
    vrt_float               pos_z;              /* z position */
    vrt_rect_struct         bounds;             /* bounds rect */
    vrt_fpoint_struct       anchor_point;       /* anchor point */
    vrt_float               opacity;            /* frame opacity */
    vrt_transform_struct    transform;          /* frame transform */
    vrt_color_type          background_color;   /* frame background color */

    vrt_color_type          border_color;       /* border color */
    vrt_s32                 border_width;       /* border width */

    vrt_float               filter_timing;      /* timing value for filters */
    vrt_float               fpe_user_0;         /* FPE user property 0 */

    /*
     * internal 
     */

    vrt_frame_dirty_info_struct dirty_info;     /* dirty rectangle information */
    vrt_frame_cache_info_struct cache_info;     /* frame cache information */

    struct _vrt_frame_property_struct *parent;  /* frame parent */

    vrt_frame_setting_struct settings;          /* Settings */

    /* User data */
    void *user_data;

	/* cache info */
    vrt_cache_hints_enum cache_hints            : VRT_BIT_COUNT(VRT_CACHE_HINTS_END_OF_ENUM);
    vrt_frame_opaque_mode_enum auto_opaque      : VRT_BIT_COUNT(VRT_FRAME_OPAQUE_MODE_END_OF_ENUM);     /* automatically detected opaque mode */
#ifdef VRT_3D
    vrt_cache_lock_mode_enum cache_lock_mode    : VRT_BIT_COUNT(VRT_CACHE_LOCK_MODE_END_OF_ENUM);
#endif
    vrt_transform_type_enum transform_type      : VRT_BIT_COUNT(VRT_TRANSFORM_TYPE_END_OF_ENUM + 1);    /* equivalent (identity?) transform type */
    vrt_bit is_cache_disable        : 1;    /* for prevent parent cache */
    vrt_bit is_cache_valid          : 1;

    vrt_bit is_covered_by_content   : 1;    // TODO: change to is_covered (by content, child, or sibling) ?
    vrt_bit is_covered_by_child     : 1;
    //vrt_bit is_covered_by_sibling   : 1;

    /* dirty info */
    vrt_bit is_dirty                : 1;
    vrt_bit is_content_dirty        : 1;
    vrt_bit is_tl_dirty             : 1;
    vrt_bit is_content_tl_dirty     : 1;

    /* region info */
    vrt_bit is_region_dirty         : 1;
    vrt_bit is_region_valid         : 1;

    /* timeline info */
    vrt_bit is_tl_opacity           : 1;    /* opacity has timeline */
    vrt_bit is_tl_bgcolor           : 1;    /* background has timeline */
    vrt_bit is_tl_bounds            : 1;    /* bounds has timeline */
	vrt_bit is_tl_pos               : 1;    /* position has timeline */
	vrt_bit is_tl_transform         : 1;    /* transform has timeline */

    /* frame info */
    vrt_bit is_full_frame           : 1;    /* this frame is covered by children */
    vrt_bit is_pure_color           : 1;    /* pure color frame */
    vrt_bit is_pure_img_buf         : 1;    /* pure image buffer frame */

    /* runtime info */
    vrt_bit is_dirty_scaned         : 1;
    vrt_bit is_bypass_overlay       : 1;

    vrt_bit is_need_owner_draw_init : 1;    /* owner draw init */
    vrt_bit is_in_render            : 1;    /* TODO: remove it, it's duplicated to frame state */
    vrt_bit is_partial_dirty        : 1;
    vrt_bit is_precache_children    : 1;    /* only for precache timeline (one time flag) */
    vrt_bit is_precache             : 1;    /* only for precache timeline (one time flag) */
} vrt_frame_property_struct;


/* frame property array */
typedef struct _vrt_frame_property_array_item_struct
{
    vrt_frame_property_struct *properties;
    vrt_s32 cache_hash;
} vrt_frame_property_array_item_struct;

typedef struct _vrt_frame_property_array_struct
{
    vrt_frame_property_array_item_struct *array;
    vrt_u32 size;
    vrt_u32 free_size;
    vrt_u32 total_size;
} vrt_frame_property_array_struct;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VRT_FRAME_GPROT_H__ */

