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
 *  vfx_sys_mem_config.c
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Engine Memory Relative Configure
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_sys_mem_config.h"
// For vfx_sys_mem_pool_allocator_create()
#include "vfx_sys_memory.h"
// For memory size configure values
#include "vfx_sys_config.h"

#include "vrt_datatype.h"
#include "vrt_math.h"
#include "vrt_base_allocator.h"
#include "vrt_system.h"
#include "vrt_canvas.h"
#include "vfx_datatype.h"
#include "vfx_adp_device.h"

#include "MMI_features.h"

#include "app_mem.h"

/* For MED memory */
#include "med_global.h"     
#include "med_smalloc.h"

/* For SSE */
#include "gui_effect_oem.h" 

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "gdi_include.h"
#include "mmi_frm_mem_gprot.h"


#include "ui_buffer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#if defined(__COSMOS_MMI__)
/*
 * In Cosmos projects, most APP is Venus APP. 
 *  Share VRT context with a global memory can reduce 
 *  the memory of concurrent APP.
 */
#define VFX_SYS_USE_GLOBAL_VRT_CONTEXT
#endif

#if defined(__VENUS_3D_UI_ENGINE__) && defined(__COSMOS_MMI__)
#define VFX_SYS_USE_SSE_AS_CACHE
#endif


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
extern void gui_screen_switch_effect_get_frame_buffer_info(U32 frame_buf_index, PU8 *buf_p, S32 *buf_size);
extern S32 gui_screen_switch_effect_get_frame_buffer_count(void);
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

#ifdef __MMI_REDUCED_UI_BUFFER__
extern void vcpSseUseSingleBufferModeInVRT(vrt_bool state);
extern vrt_bool vcpSseIsVRTinSingleBufferMode(void);
#endif /* __MMI_REDUCED_UI_BUFFER__ */

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

/* 
 * Venus System Global Memory 
 */
static VFX_ALIGN(4) VfxU8 g_vfx_sys_mem_global_mem_buf[VFX_SYS_MEM_GLOBAL_POOL_SIZE];
static vrt_allocator_handle g_vfx_sys_mem_global_allocator = NULL;

/* 
 * VRT Context Heap Memory
 */
#if defined(VFX_SYS_USE_GLOBAL_VRT_CONTEXT)
static VfxU32 g_vfx_sys_vrt_context_heap[VFX_SYS_VRT_CONTEXT_HEAP_SIZE / sizeof(VfxU32)];
#endif

static vrt_allocator_handle g_vfx_sys_vrt_context_heap_allocator = NULL;

/* 
 * VRT Cache Memory 
 */
static gdi_handle g_vfx_sys_vrt_gdi_internal_layer = GDI_NULL_HANDLE;
static vrt_u32 g_vfx_sys_vrt_cache_config_size = VFX_SYS_MEM_VRT_CACHE_MAX_SIZE;
static VfxFlag g_vfx_sys_mem_config_flags = 0;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*
 * Note:
 *  These function is only for MAUI to configure VRT memory usage.
 */
/*****************************************************************************
 * FUNCTION
 *  vfx_set_cache_config_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cache_size       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_set_cache_config_size(vrt_u32 cache_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vfx_sys_vrt_cache_config_size = cache_size;

    if (g_vfx_sys_vrt_cache_config_size > VFX_SYS_MEM_VRT_CACHE_MAX_SIZE)
    {
        g_vfx_sys_vrt_cache_config_size = VFX_SYS_MEM_VRT_CACHE_MAX_SIZE;
    }    

    // update cache info
    vfx_sys_get_vrt_mem_provider();
}


/*****************************************************************************
 * FUNCTION
 *  vfx_get_cache_config_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static vrt_u32 vfx_get_cache_config_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vfx_sys_vrt_cache_config_size;
}



/*****************************************************************************
 * FUNCTION
 *  vfx_sys_render_memory_init
 * DESCRIPTION
 *  Init memory for the VRT render.
 * PARAMETERS
 *  mem_config_p                [IN]    memory config structure pointer
 *  max_memory_config_num       [IN]    number of memory config structure available
 *  memory_config_num           [OUT]   number of memory config structure assigned
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_render_memory_init(
    vrt_sys_render_memory_config_struct *mem_config_p,
    vrt_u32 max_memory_config_num,
    vrt_u32 *memory_config_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && !defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) && !defined(VFX_SYS_USE_SSE_AS_CACHE)
    vrt_s32 sse_frame_buffer_count = 0;
    vrt_s32 i = 0;
    VfxU8 *buf_p = NULL;
    VfxS32 buf_size = 0;
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
    gdi_handle layer;
    vrt_u32 mem_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mem_count = 0;

    /* update global memory config */
    vfx_sys_get_vrt_mem_provider();

    /* set ui buffer mode to VENUS */
    if (!VFX_FLAG_HAS(g_vfx_sys_mem_config_flags, VFX_SYS_MEM_CONFIG_FLAG_FORBID_GDI_LAYER))
    {
        ui_buffer_set_mode(UI_BUFFER_MODE_VENUS);
    }

    /* 
     * attach GDI internal layer buffer 
     */
    gdi_layer_get_base_handle(&layer);
 
    /* attach another frame buffer from the GDI layer pool */
    // TODO: Remove !VRT_RENDER_DCACHED_LAYER if gdi internal layer pool is d-cached switchable for NFB porjects
#if defined(GDI_MAINLCD_MAX_LAYERS) && (GDI_MAINLCD_MAX_LAYERS > 1) && !(defined(__MED_IN_ASM__) && defined(__COSMOS_MMI__))
    if (!g_vfx_sys_vrt_gdi_internal_layer && 
        !VFX_FLAG_HAS(g_vfx_sys_mem_config_flags, VFX_SYS_MEM_CONFIG_FLAG_FORBID_GDI_LAYER))
    {
        if (mem_count < max_memory_config_num)
        {
            VRT_SYS_RENDER_MEMORY_SET_CONFIG(
                mem_config_p, 
                VRT_SYS_RENDER_MEMORY_TYPE_TEMP, 
                (vrt_u8*)ui_buffer_get_start_addr(UI_BUFFER_ID_GDI_SBL), 
                (vrt_u32)ui_buffer_get_block_size(UI_BUFFER_ID_GDI_SBL),
                VRT_SYS_RENDER_MEMORY_FLAG_DYNAMIC_CACHEABLE);

            mem_count++;
            mem_config_p++;                    
        }
    }
#endif /* defined(GDI_MAINLCD_MAX_LAYERS) && (GDI_MAINLCD_MAX_LAYERS > 1) */

    /* 
     * attach SSE buffers, this is very important
     */

#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && !defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) && !defined(VFX_SYS_USE_SSE_AS_CACHE) && !defined(__MMI_REDUCED_UI_BUFFER__)
    sse_frame_buffer_count = (vrt_s32)gui_screen_switch_effect_get_frame_buffer_count();
    for (i = 0; i < sse_frame_buffer_count; i++)
    {
        gui_screen_switch_effect_get_frame_buffer_info((U32)i, &buf_p, &buf_size); 

        /* attach buf b only */
        if ((mem_count < max_memory_config_num) && (i == 1))
        {
            VRT_SYS_RENDER_MEMORY_SET_CONFIG(
                mem_config_p, 
                VRT_SYS_RENDER_MEMORY_TYPE_TEMP, 
                buf_p,
                (vrt_u32)buf_size, 
                VRT_SYS_RENDER_MEMORY_FLAG_DYNAMIC_CACHEABLE);

            mem_count++;
            mem_config_p++;                    
        }
    }
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

    /* assign vrt cache size */
    if (mem_count < max_memory_config_num)
    {
        U8 *mem_p = NULL;
        vrt_sys_render_memory_type_enum cache_mem_type;

        /* low end projects use MED temp */
        cache_mem_type = VRT_SYS_RENDER_MEMORY_TYPE_CACHE;

        VRT_SYS_RENDER_MEMORY_SET_CONFIG(
            mem_config_p,
            cache_mem_type,
            mem_p,
            vfx_get_cache_config_size(),
            VRT_SYS_RENDER_MEMORY_FLAG_DEFAULT);

        mem_count++;
        mem_config_p++;
    }

    *memory_config_num = mem_count;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_render_memory_deinit
 * DESCRIPTION
 *  Deinit memory for the VRT render.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_render_memory_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_sys_vrt_gdi_internal_layer)
    {
        gdi_layer_free(g_vfx_sys_vrt_gdi_internal_layer);
        g_vfx_sys_vrt_gdi_internal_layer = GDI_NULL_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_config_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_config_entry(const vfx_sys_mem_config_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(VFX_SYS_USE_GLOBAL_VRT_CONTEXT)
    VfxFlag allocator_flags = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(param != NULL);
    VFX_DEV_ASSERT(param->app_allocator != NULL);
    
    /*
     * save canvas flags
     */
    g_vfx_sys_mem_config_flags = param->flags;

    /*
     * Prepare VRT context heap allocator
     */
#if defined(VFX_SYS_USE_GLOBAL_VRT_CONTEXT)

    allocator_flags = VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE;
    if (VFX_FLAG_HAS(param->flags, VFX_SYS_MEM_CONFIG_FLAG_SHARE_APP_CONTEXT_FOR_VRT))
    {
        VFX_FLAG_SET(allocator_flags, VFX_SYS_MEM_POOL_CREATE_FLAG_DISABLE_ALLOC_CHECK);
    }
    
    g_vfx_sys_vrt_context_heap_allocator = vfx_sys_mem_pool_allocator_create(
        (VfxU8 *)g_vfx_sys_vrt_context_heap,
        sizeof(g_vfx_sys_vrt_context_heap),
        allocator_flags);
    if (VFX_FLAG_HAS(param->flags, VFX_SYS_MEM_CONFIG_FLAG_SHARE_APP_CONTEXT_FOR_VRT))
    {
        vrt_allocator_set_chain_allocator(
            g_vfx_sys_vrt_context_heap_allocator, 
            param->app_allocator);
    }
    
#else

    g_vfx_sys_vrt_context_heap_allocator = param->app_allocator;

#endif
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_config_leave
 * DESCRIPTION
 * 
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_config_leave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(VFX_SYS_USE_GLOBAL_VRT_CONTEXT)
    vrt_allocator_release(g_vfx_sys_vrt_context_heap_allocator);
#endif
    g_vfx_sys_vrt_context_heap_allocator = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_config_screen_entered
 * DESCRIPTION
 * 
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_config_screen_entered(void)
{
#ifndef __MMI_REDUCED_UI_BUFFER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    PU8 buf_p;
    S32 buf_size;
    extern void vrt_mem_attach(void *mem_p, vrt_u32 size, vrt_u32 flag);
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)

#if 1
    {
        PU8 sse_buf_p = NULL;
        S32 sse_buf_size = 0;

        /* merge SSE buffers into a big pool */
        gui_screen_switch_effect_get_frame_buffer_info(1, &buf_p, &buf_size);
        sse_buf_p = buf_p;
        sse_buf_size = ui_buffer_get_block_size_by_addr(buf_p);

        gui_screen_switch_effect_get_frame_buffer_info(0, &buf_p, &buf_size);
        if (sse_buf_p + sse_buf_size == buf_p)
        {
            sse_buf_size += ui_buffer_get_block_size_by_addr(buf_p);
        }
        gui_screen_switch_effect_get_frame_buffer_info(2, &buf_p, &buf_size);
        if (sse_buf_p + sse_buf_size == buf_p)
        {
            sse_buf_size += ui_buffer_get_block_size_by_addr(buf_p);
        }

        /* attach for 3D gl memory */
        if (sse_buf_p && sse_buf_size)
        {
            vrt_cache_mem_attach_ext(sse_buf_p, (vrt_u32)sse_buf_size, VRT_CACHE_USER_POOL_FLAG_DEFAULT);
        }
    }

#else /* defined(VFX_SYS_USE_SSE_AS_CACHE) */
/* under construction !*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(VFX_SYS_USE_SSE_AS_CACHE) */

#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
#else
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    /* attach SBL to cache pool */
    void *buf_p = ui_buffer_get_start_addr(UI_BUFFER_ID_GDI_SBL);
    vrt_u32 buf_size = ui_buffer_get_block_size(UI_BUFFER_ID_GDI_SBL);
    if (buf_p && buf_size)
    {
        vrt_cache_mem_attach_ext(buf_p, buf_size, VRT_CACHE_USER_POOL_FLAG_DEFAULT);
    }
#endif
    if (vcpSseIsVRTinSingleBufferMode())
    {
        vcpSseUseSingleBufferModeInVRT(VRT_FALSE);
        // switch to double buffer mode
        vrt_canvas_switch_render_buffer_mode();
    }
#endif /* __MMI_REDUCED_UI_BUFFER__ */
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_get_global_allocator
 * DESCRIPTION
 *  Return the allocator of Venus system global memory
 * PARAMETERS
 *  void
 * RETURNS
 *  The allocator
 *****************************************************************************/
vrt_allocator_handle vfx_sys_mem_get_global_allocator(void)
{
    if (g_vfx_sys_mem_global_allocator == NULL)
    {
        g_vfx_sys_mem_global_allocator = vfx_sys_mem_pool_allocator_create(
            g_vfx_sys_mem_global_mem_buf, 
            VFX_SYS_MEM_GLOBAL_POOL_SIZE,
            VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE);
    }
    return g_vfx_sys_mem_global_allocator;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_get_vrt_context_allocator
 * DESCRIPTION
 *  Internal used for debugging. Get the VRT memory allocator
 * PARAMETERS
 *  void
 * RETURNS
 *  The VRT memory allocator
 *****************************************************************************/
vrt_allocator_handle vfx_sys_get_vrt_context_allocator(void)
{
    return g_vfx_sys_vrt_context_heap_allocator;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_get_vrt_mem_provider
 * DESCRIPTION
 * 
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
vrt_mem_provider_handle vfx_sys_get_vrt_mem_provider(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static vrt_mem_provider_struct provider;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    provider.memory_init = vfx_sys_render_memory_init;
    provider.memory_deinit = vfx_sys_render_memory_deinit;
#ifndef __MMI_REDUCED_UI_BUFFER__
#if defined(__MED_IN_ASM__) && defined(__COSMOS_MMI__)
    /* GDI SBL + VRT cache can be merged together for VRT global pool for the first frame */
	if (!VFX_FLAG_HAS(g_vfx_sys_mem_config_flags, VFX_SYS_MEM_CONFIG_FLAG_FORBID_GDI_LAYER))
	{
        provider.global_cache_buf = (U8*)ui_buffer_get_start_addr(UI_BUFFER_ID_GDI_SBL);
        provider.global_cache_size = ui_buffer_get_block_size(UI_BUFFER_ID_GDI_SBL) + ui_buffer_get_block_size(UI_BUFFER_ID_VRT_CACHE);
    }
	else
    {
        provider.global_cache_buf = (U8*)ui_buffer_get_start_addr(UI_BUFFER_ID_VRT_CACHE);
        provider.global_cache_size = ui_buffer_get_block_size(UI_BUFFER_ID_VRT_CACHE);
    }
#else
    provider.global_cache_buf = NULL;
    provider.global_cache_size = vfx_get_cache_config_size();
#endif
    
#else  /* !defined(__MMI_REDUCED_UI_BUFFER__) */
    provider.global_cache_buf = NULL;
    provider.global_cache_size = 0;//vfx_get_cache_config_size();
    //provider.global_cache_buf = (U8*)ui_buffer_get_start_addr(UI_BUFFER_ID_VRT_CACHE);
    //provider.global_cache_size = ui_buffer_get_block_size(UI_BUFFER_ID_VRT_CACHE);
#endif /* __MMI_REDUCED_UI_BUFFER__ */

    return &provider;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_config_is_vrt_able_to_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_size       [IN]
 * RETURNS
 *  
 *****************************************************************************/
VfxU32 vfx_sys_mem_config_is_vrt_able_to_run(VfxU32 app_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI__)
    return 1;
#else /* defined(__COSMOS_MMI__) */

    #if defined(__MED_IN_ASM__)
    {
        void *mem_try_p;
        mem_try_p = mmi_frm_asm_alloc_anonymous_nc((U32)app_size + (U32)g_vfx_sys_vrt_cache_config_size);
        if (mem_try_p)
        {
            mmi_frm_asm_free_anonymous(mem_try_p);
            return 1;
        }
    }        
    #endif

    return 0;    
#endif /* defined(__COSMOS_MMI__) */
}


