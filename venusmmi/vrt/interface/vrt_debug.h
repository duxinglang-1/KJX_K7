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
 *  vrt_include.h
 *
 * Project:
 * --------
 *  Venus VRT Debug
 *
 * Description:
 * ------------
 *  Venus VRT Debug header file
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
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_DEBUG_H__
#define __VRT_DEBUG_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

/* Performance hints */
#define VRT_DBG_PERFORMANCE_HINT_NONE           0
#define VRT_DBG_PERFORMANCE_HINT_FRAME_TIME     (1 << 0)
#define VRT_DBG_PERFORMANCE_HINT_IMAGE_TIME     (1 << 1)
#define VRT_DBG_PERFORMANCE_HINT_CACHE_SIZE     (1 << 2)
#define VRT_DBG_PERFORMANCE_HINT_ALL \
    (VRT_DBG_PERFORMANCE_HINT_CACHE_SIZE | \
    VRT_DBG_PERFORMANCE_HINT_IMAGE_TIME | \
    VRT_DBG_PERFORMANCE_HINT_FRAME_TIME)
#define VRT_DBG_PERFORMANCE_HINT_COLOR_MODE     (1 << 3)
#define VRT_DBG_PERFORMANCE_HINT_PROFILE        (1 << 4)


/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef enum
{
    VRT_DBG_HANDLE_TYPE_UNKNOWN = 0,
    VRT_DBG_HANDLE_TYPE_FRAME,
    VRT_DBG_HANDLE_TYPE_TIMELINE,
    VRT_DBG_HANDLE_TYPE_END_OF_ENUM
} vrt_dbg_handle_type_enum;

typedef enum
{
    VRT_DBG_PARAMETER_CACHE_ALLOC_NULL_ASSERT,
    VRT_DBG_PARAMETER_END_OF_ENUM
} vrt_dbg_parameter_enum;

typedef vrt_u32 vrt_dbg_performance_hint_type;

/* canvas debug statistics */
typedef struct
{
    vrt_u32 cur_frame_cnt;
    vrt_u32 max_frame_cnt;
    vrt_u32 cur_timeline_cnt;
    vrt_u32 max_timeline_cnt;

    vrt_u32 cur_draw_cmd_cnt;
    vrt_u32 max_draw_cmd_cnt;
    vrt_u32 cur_draw_cmd_data_buf_size;
    vrt_u32 max_draw_cmd_data_buf_size;

    vrt_u32 cur_vrt_ext_free_size;

    /* cache statistics */
    vrt_u32 asm_pool_size;
    vrt_u32 cur_asm_cache_alloc_size;
    vrt_u32 max_asm_cache_alloc_size;

    vrt_u32 vrt_default_pool_size;
    vrt_u32 cur_med_cache_alloc_size;
    vrt_u32 max_med_cache_alloc_size;

    vrt_u32 app_pool_size;
    vrt_u32 cur_app_cache_alloc_size;
    vrt_u32 max_app_cache_alloc_size;

    /* auto cache statistics */
    vrt_u32 cur_cache_alloc_size;
    vrt_u32 cur_cache_suggest_size;
    vrt_u32 max_cache_suggest_size;
    vrt_u32 cache_max_alloc_size;

    /* temp buffer statistics */
    vrt_u32 tmp_pool_size;
    vrt_u32 cur_tmp_buffer_alloc_size;
    vrt_u32 max_tmp_buffer_alloc_size;

    /* temp buffer + cache */
    vrt_u32 max_total_suggest_size;

    /* time info */
    vrt_u32 animation_time;
    vrt_u32 dirty_scan_time;
    vrt_u32 auto_cache_time;
    vrt_u32 display_time;
    vrt_u32 output_time;
    vrt_u32 draw_frame_time;

    vrt_u32 text_time;   
    vrt_u32 world_time;
    vrt_u32 filter_time;
    vrt_u32 owner_draw_time;
    vrt_u32 clear_color_time;
    vrt_u32 transform_time;
    vrt_u32 overlay_time;
    vrt_u32 hw_lt_time;
    vrt_u32 hw_lt_clean_time;
    vrt_u32 hw_lt_clear_time;
    vrt_u32 hw_ovl_time;
    vrt_u32 hw_ovl_clean_time;
    vrt_u32 hw_blt_time;

    vrt_u32 transform_size;
    vrt_u32 overlay_size;
    vrt_u32 ft_overlay16to16_size;
    vrt_u32 hw_overlay32to32_size;
    vrt_u32 hw_overlay32to16_size;
    vrt_u32 hw_overlay16to32_size;
    vrt_u32 hw_overlay16to16_size;
    vrt_u32 sw_overlay32to32_size;
    vrt_u32 sw_overlay32to16_size;
    vrt_u32 sw_overlay16to32_size;
    vrt_u32 sw_overlay16to16_size;

    vrt_u32 ft_overlay16to16_time;
    vrt_u32 hw_overlay32to32_time;
    vrt_u32 hw_overlay32to16_time;
    vrt_u32 hw_overlay16to32_time;
    vrt_u32 hw_overlay16to16_time;
    vrt_u32 sw_overlay32to32_time;
    vrt_u32 sw_overlay32to16_time;
    vrt_u32 sw_overlay16to32_time;
    vrt_u32 sw_overlay16to16_time;

    vrt_float avg_fps;
    vrt_float last_fps;

    vrt_u32 cur_cache_c_alloc_count;
    vrt_u32 max_cache_c_alloc_count;    
    vrt_u32 cur_cache_c_alloc_size;    
    vrt_u32 max_cache_c_alloc_size;
    vrt_u32 cur_cache_nc_alloc_count;
    vrt_u32 max_cache_nc_alloc_count;
    vrt_u32 cur_cache_nc_alloc_size;
    vrt_u32 max_cache_nc_alloc_size;    
} vrt_canvas_dbg_statistics_struct;


/*****************************************************************************
 * Global Function
 *****************************************************************************/

/*
 * Debug functions
 */

extern vrt_u32 vrt_dbg_get_handle_struct_size(vrt_dbg_handle_type_enum handle_type);

extern void vrt_canvas_dbg_get_statistics(vrt_canvas_dbg_statistics_struct *dbg_stats);
extern void vrt_canvas_dbg_enable_dirty_rect(vrt_bool is_enable);
extern void vrt_canvas_dbg_performance_hint(vrt_dbg_performance_hint_type hint);
extern void vrt_dbg_get_statistics(vrt_canvas_dbg_statistics_struct *dbg_stats);
extern void vrt_dbg_enable_dirty_rect(vrt_bool is_enable);

extern void vrt_dbg_set_parameter(vrt_dbg_parameter_enum param, void *value);

#ifndef __MTK_TARGET__


// This is debug API to enable remap memory.
void vrt_debug_enable_remap(
    int enable // Non-zero means enable this function.
);


// This is debug API to remap memory to help to debug memory issue in MoDis.
// RETURNS: The new memory pointer
void* vrt_debug_remap_mem(
    void* ptr,          // The original memory
    unsigned int size   // The request memory size
);


// This is debug API to remap back to original memory to help to debug memory issue in MoDis.
// RETURNS: The original memory pointer
void* vrt_debug_remap_mem_free(
    void* ptr           // The new memory pointer
);

// Detect a point whether accessable or not
// RETURNS: 0 means the memory cannot be access
int vrt_debug_is_mem_valid(
	void *ptr			// [IN] The memory pointer
);

#else

#define vrt_get_ms_time()
#define vrt_debug_enable_remap(v)
#define vrt_debug_remap_mem(ptr, size) ptr
#define vrt_debug_remap_mem_free(ptr) ptr
#define vrt_debug_is_mem_valid(ptr) 1

#endif


#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /* __VRT_INCLUDE_H__ */

