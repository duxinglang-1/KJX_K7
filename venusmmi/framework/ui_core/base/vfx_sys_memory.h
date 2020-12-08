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
 *  vfx_sys_memory.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Provide system memory management for porting.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_SYS_MEMORY_H__
#define __VFX_SYS_MEMORY_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_datatype.h"
// For vrt_allocator_handle
#include "vrt_base_allocator.h"

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef VFX_MEM_LOG_ENABLE
    /* Debug utility. Log the information of memory usage into file */
    #define VFX_MEM_LOG(_args)                                                  \
    do                                                                          \
    {                                                                           \
        vfx_sys_dbg_mem_log _args;                                              \
        vfx_sys_dbg_mem_log(" #%s:%d\n", __FILE__, __LINE__);                   \
    } while(0)
#else
    #define VFX_MEM_LOG(_args)        
#endif

#ifndef __MTK_TARGET__ /* on MODIS */
    #define VFX_MEM_FILL_FILENAME(filename, line)                                     \
    do                                                                          \
    {                                                                           \
        filename = __FILE__ ;                                                   \
        line = __LINE__;                                                        \
    } while(0)
#elif defined (__RVCT__)
    #define VFX_MEM_FILL_FILENAME(filename, line)                               \
    do                                                                          \
    {   /*link address rather than filename string*/                                    \
        filename =  (const VfxChar *)__current_pc();                            \
        line = __LINE__;                                                        \
    } while(0)
#else /*ADS*/
    #define VFX_MEM_FILL_FILENAME(filename, line)                               \
    do                                                                          \
    {   /*link address rather than filename string*/                                    \
        __asm {mov filename, pc;}                                               \
        line = __LINE__;                                                        \
    } while(0)
#endif    
/*
 * Memory Pool Create Flags
 */

#define VFX_SYS_MEM_POOL_CREATE_FLAG_NONE                   (0)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE            (1 << 0)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING         (1 << 1)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_RESET_STATISTICS       (1 << 2)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_ASM_SLMM               (1 << 3)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_DISABLE_LEAK_CHECK     (1 << 4)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_DISABLE_ALLOC_CHECK    (1 << 5)
#define VFX_SYS_MEM_POOL_CREATE_FLAG_SMALL_POOL             (1 << 6)


/*
 * Change SLMM Pool Size Flags
 */

#define VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_DEFAULT      (0)      /*default OOM*/
#define VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_NO_OOM       (1 << 0) /*No OOM, force prepare*/
#define VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_UNHIDDEN     (1 << 1) /*OOM, unhidden enlarge in background*/
#define VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_IF_ENOUGH    (1 << 2) /*enlarge heap if check enough*/

/*
 * vfx_sys_mem_pool_set_property Flags
 */
#define VFX_SYS_MEM_POOL_SET_APP_ID_PROPERTY_FLAG    (1)

/*
 * Allocate Memory Flags
 */

/* The allocated memory is used for frame buffer */
#define VFX_SYS_MEM_ALLOC_FLAG_FB       VRT_ALLOCATOR_ALLOC_FLAG_FB


#define vfx_sys_mem_pool_alloc(_handle, _size, _flags, _ret) \
    vfx_sys_mem_pool_alloc_int(_handle, _size, _flags, _ret, 0, 0)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
typedef enum
{
    VFX_SYS_MEM_ALLOC_RET_OK = 0,
    VFX_SYS_MEM_ALLOC_RET_ZERO_SIZE,
    VFX_SYS_MEM_ALLOC_RET_OUT_OF_MEM,
    VFX_SYS_MEM_ALLOC_RET_FRAGMENT,
    VFX_SYS_MEM_ALLOC_RET_END_OF_ENUM
} vfx_sys_mem_alloc_ret_enum;

/* Memory pool status */
typedef struct
{
    /* Total size of the memory pool, 
        equal to the given size on vfx_sys_mem_pool_create() */
    VfxU32 total_size;
    /* Current used size of the memory pool */
    VfxU32 used_size;
    /* The largest used size of the memory pool, 
        update the value on each vfx_sys_mem_pool_get_status() */
    VfxU32 max_used_size;
} vfx_sys_mem_pool_status_struct;

#if defined(__VFX_HEAP_PROFILE__)
typedef VfxU32 (*vfx_heap_profiling_isObj_cb) (void* ptr, void** parent_p);
#endif /* defined(__VFX_HEAP_PROFILE__) */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern void vfx_sys_mem_init(void);

/* 
 * Memory pool
 */

extern vfx_sys_mem_pool_handle vfx_sys_mem_pool_create(VfxU8 *mem_buf, VfxU32 mem_buf_size, VfxFlag flags);
extern void vfx_sys_mem_pool_destroy(vfx_sys_mem_pool_handle handle);
extern void *vfx_sys_mem_pool_alloc_int(vfx_sys_mem_pool_handle handle, VfxU32 size, VfxFlag flags, vfx_sys_mem_alloc_ret_enum *ret, const VfxChar *filename, VfxU32 line);
extern void vfx_sys_mem_pool_free(vfx_sys_mem_pool_handle mem_pool_handle, void *vptr);
extern void vfx_sys_mem_pool_get_status(vfx_sys_mem_pool_handle handle, vfx_sys_mem_pool_status_struct *status_buf);


/* 
 * Allocator support
 */

extern vrt_allocator_handle vfx_sys_mem_pool_allocator_create(VfxU8 *mem_buf, VfxU32 mem_buf_size, VfxFlag flags);
extern void vfx_sys_mem_pool_allocator_get_status(vrt_allocator_handle handle, vfx_sys_mem_pool_status_struct *status_buf);

extern U32 vfx_sys_mem_pool_backward_enlarge_slmm_heap(
    mmi_id app_id, 
    vrt_allocator_handle handle, 
    U32 mem_size);

extern U32 vfx_sys_mem_pool_enlarge_slmm_heap(
    mmi_id app_id, 
    vrt_allocator_handle handle, 
    U32 mem_size,
    mmi_proc_func func,  
    void *user_data,
    U32 flag);

extern U32 vfx_sys_mem_pool_shrink_slmm_heap(
    mmi_id app_id, 
    vrt_allocator_handle handle, 
    U32 mem_size);


/*
 * Memory debug log
 */
extern void vfx_sys_dbg_mem_pool_remaining_output(kal_uint32 flags);
extern void vfx_heap_profiling_overall_output(kal_uint32 flags);
extern void vfx_sys_mem_pool_set_property(vfx_sys_mem_pool_handle handle, void* data, VfxU32 flag);
extern void vfx_heap_profiling_obj_update(vrt_allocator_handle allocator, void* _ptr, VfxU32 flag);
extern MMI_BOOL vfx_heap_profiling_ssc_check(
            WCHAR* str /*user key in data*/,
            CHAR* temp_str /*temp buffer*/, 
            CHAR* pattern_disable, 
            CHAR* pattern_enable, CHAR* pattern_enable_cfg1, CHAR* pattern_enable_cfg2);

#if defined(__VFX_HEAP_PROFILE__)
extern VfxU32 vfx_heap_profiling_check(MMI_ID app_id,VfxU32 size);
extern void vfx_heap_profiling_data_init(void);
extern void vfx_heap_profiling_set_isObj_callback(vfx_heap_profiling_isObj_cb callback);
#endif /* defined(__VFX_HEAP_PROFILE__) */

#ifdef VFX_MEM_LOG_ENABLE
extern void vfx_sys_dbg_mem_log(const VfxChar *fmt, ...);
#endif /* VFX_MEM_LOG_ENABLE */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __VFX_SYS_MEMORY_H__ */

