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
 *  vfx_sys_memory.c
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#if !defined(__MTK_TARGET__) && defined(WIN32)
#include "windows.h"
#endif

#include "GlobalResDef.h"
#include "vfx_sys_memory.h"
#include "vfx_datatype.h"
// For vfx_sys_mem_zero()
#include "vfx_adp_clib.h"

// For VFX_LOG
#include "trc\vadp_sys_trc.h"
#include "vfx_system.h"
//For VFX_HEAP_PROFILE
#include "mmi_rp_app_data_def.h"
#include "CustDataRes.h"
#include "vrt_datatype.h"
#include "Unicodexdcl.h"
// For vrt_allocator_handle
#include "vrt_base_allocator.h"
// For vrt_debug_remap_mem(), etc.
#include "vrt_debug.h"

// For ADM
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_adm.h"
#include "kal_trace.h"

// For Cachable
#include "cache_sw.h"
#include "custom_scatstruct.h"

// For MMv2
#include "mmi_frm_mem_gprot.h"

#include <string.h>
#include <stdlib.h>


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE_16          16
#define VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE             32
#define VFX_SYS_MEM_POOL_CHUNK_SIZE                 1024
#define VFX_SYS_MEM_POOL_CHUNK_HEADER_FOOTER_SIZE   32
/* The small memory pool threshold, default is 4K */
#define VFX_SYS_MEM_POOL_SMALL_POOL_THRESHOLD       (4 * 1024)

#define VFX_SYS_MEM_POOL_BLOCK_FREE_MAGIC_1 0xabcdef12
#define VFX_SYS_MEM_POOL_BLOCK_FREE_MAGIC_2 0x34567890


/*******************************************************************************
 * External Function prototype
 *******************************************************************************/

extern kal_char* release_branch(void);
extern kal_char* release_verno(void);
extern kal_char* build_date_time(void);


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define ADM_HAS_OLD_ISLOGGING_FLAG(ext_adm_id) (((ADM_CB *)ext_adm_id)->flags & KAL_ADM_OLD_ISLOGGING_FLAG)
#define ADM_HAS_GUARDIAN_FLAG(ext_adm_id) (((ADM_CB *)ext_adm_id)->flags & KAL_ADM_GUARDIAN_FLAG)
#define ADM_HAS_EXTHEADER_FLAG(ext_adm_id) (((ADM_CB *)ext_adm_id)->flags & KAL_ADM_EXTHEADER_FLAG)

#if defined __MMI_USE_MMV2__
    #define HAS_ISSLMM_FLAG(flag)  ((flag)& VFX_SYS_MEM_POOL_CREATE_FLAG_ASM_SLMM )
#else
    #define HAS_ISSLMM_FLAG(flag)  (0)
#endif

#define INVALID_FILE (0xFFFFFFFF)
#define INVALID_LINE (0xFFFFFFFF)


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

typedef struct _vfx_sys_mem_pool_chunk_block_extheader_struct
{    
    VfxU32 filename;  /* point to the caller address in target load/point to the file name string in MODIS load */
    VfxU32 line;
} vfx_sys_mem_pool_chunk_block_extheader_struct;

typedef struct _vfx_sys_mem_pool_chunk_struct
{    
    /* Header */
    VfxU32  alloc_block_cnt;
    VfxU8  *first_free_block;
    struct _vfx_sys_mem_pool_chunk_struct *prev_chunk;
    struct _vfx_sys_mem_pool_chunk_struct *next_chunk;

    /* The buffer to be allocated */
    VfxU8 buffer[
        VFX_SYS_MEM_POOL_CHUNK_SIZE - 
        VFX_SYS_MEM_POOL_CHUNK_HEADER_FOOTER_SIZE];

    /* Footer */
    VfxU32 reserved[4];
} vfx_sys_mem_pool_chunk_struct;


typedef struct _vfx_sys_mem_pool_struct
{
    /* For the thread safe, do not modify flags after memory created */
    MMI_ID  app_id;
    VfxFlag flags;
    void*  mem_id;
    
    VfxU8 *mem_buf;
    VfxU32 mem_buf_size;
    vfx_sys_mutex_struct mem_mutex;
#if defined(__MMI_USE_MMV2__)
    VfxU32 mem_buf_vm_size;  
#endif
    VfxU32 alloc_cnt;
    struct _vfx_sys_mem_pool_struct *next_mem_pool;

    vfx_sys_mem_pool_chunk_struct *first_chunk;
    vfx_sys_mem_pool_chunk_struct *last_chunk;
    vfx_sys_mem_pool_chunk_struct *first_chunk_ext;
    vfx_sys_mem_pool_chunk_struct *last_chunk_ext;

    /* Statistics data */
    VfxU32 max_used_size;
#if defined(__MMI_USE_MMV2__)
    VfxU32 max_used_page_size;  
#endif
    VfxU32 used_size;
    VfxU32 free_in_chunk_size;
    VfxU32 free_in_chunk_size_ext;
} vfx_sys_mem_pool_struct;


typedef void (*vfx_sys_mem_pool_chunk_block_visitor)(
    vfx_sys_mem_pool_struct *mem_pool, 
    vfx_sys_mem_pool_chunk_block_extheader_struct* header, 
    void *user_data);

typedef struct
{
    vfx_sys_mem_pool_struct *mem_pool;
    VfxU32 size;
    const VfxChar *filename;
    VfxU32 line;
} vfx_sys_dbg_mem_pool_logging_dump_struct;

typedef struct _vfx_heap_profiling_overall_struct
{
    MMI_ID app_id;
    VfxU32 peak_size;
#if defined(__MMI_USE_MMV2__)
    VfxU32 peak_page_size;  
#endif
    VfxU32 pool_size;
} vfx_heap_profiling_overall_struct;


#if defined __VFX_HEAP_PROFILE__

typedef struct _vfx_heap_profiling_single_config_struct
{
    MMI_ID profile_app;
    VfxU32 threshold_size;
} vfx_heap_profiling_single_config_struct;


#define VFX_HEAP_ALLOC_MAX  8000


typedef struct _snapshotinfo
{
    VfxU32 file;
    VfxU32 line;
    VfxU32 parent;
    VfxU32 virtual_table;
    VfxU32 size;
    VfxU32 mem_addr;
} snapshotinfo;


#define SNAPSHOT_FLAG_DEFAULT               0 /* file string, ADM pool */
#define SNAPSHOT_FLAG_FILE_RETURN_ADDRESS   (1 << 0)
#define SNAPSHOT_FLAG_POOL_SLMM             (1 << 1)

typedef struct _vfx_heap_profiling_snapshot_struct
{
    MMI_ID profile_app;
    VfxU16 snapshotcount;
    VfxU32 max_size;
    VfxU32 flag;
    VfxU32 trigger_ptr_idx; /*the idx of info[] that ptr that trigger the snapshot*/
#if defined(__MMI_USE_MMV2__)
    VfxU32 max_page_size;
#endif
    snapshotinfo info[VFX_HEAP_ALLOC_MAX];
} vfx_heap_profiling_snapshot_struct;

#endif /* defined __VFX_HEAP_PROFILE__ */


static void vfx_sys_dbg_mem_pool_dump(vfx_sys_mem_pool_struct *mem_pool, const VfxChar* promptStr, VfxS32 leakOnly);


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/*
 * Memory Log
 */
#ifdef VFX_MEM_LOG_ENABLE
static FILE *g_vfx_sys_mem_log_fp = NULL;
#endif /* VFX_MEM_LOG_ENABLE */

/* All system memory pool */
static vfx_sys_mem_pool_struct *g_vfx_sys_mem_pool_list_head = NULL;
static vfx_heap_profiling_overall_struct g_vfx_heap_profiling_overall_arr[MMI_APP_INFO_TOTAL_NUMBER] = {GRP_ID_INVALID};
VfxChar g_vfx_sys_mem_log_info_str[224];

#if defined __VFX_HEAP_PROFILE__
#define PROFILE_DEFAULT_APP                 GRP_ID_INVALID
#define PROFILE_DEFAULT_THRESHOLD_SIZE      0xFFFFFFFF

static vfx_heap_profiling_single_config_struct  g_vfx_heap_profiling_single_config = {PROFILE_DEFAULT_APP,PROFILE_DEFAULT_THRESHOLD_SIZE};
static vfx_heap_profiling_snapshot_struct g_snapshotData;
static vfx_heap_profiling_isObj_cb g_vfx_heap_profiling_isObj_func = NULL;
#endif 


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_init
 * DESCRIPTION
 *  create a memory pool
 * PARAMETERS
 *  mem_pool        [OUT]   the memory pool to be created
 *  mem_buf         [IN]    the memory buffer to be a memory pool
 *  mem_buf_size    [IN]    the memory buffer size
 *  is_logging      [IN]    enable ADM logging 
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_init(
    vfx_sys_mem_pool_struct *mem_pool, 
    VfxU8 *mem_buf, 
    VfxU32 mem_buf_size,
    VfxFlag flags,
    VfxU32 kal_mem_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(mem_pool != NULL);
    VFX_ASSERT(mem_buf != NULL);
    VFX_ASSERT(mem_buf_size > 0);

    memset(mem_pool, 0x00, sizeof(vfx_sys_mem_pool_struct));
    mem_pool->flags = flags;
    vfx_sys_mutex_init(&mem_pool->mem_mutex);
   
    if (HAS_ISSLMM_FLAG(flags))
    {
#if defined(__MMI_USE_MMV2__)
        mem_pool->mem_id = (MMI_FRM_ASM_SLMM_ID)kal_mem_id;
#endif /* defined(__MMI_USE_MMV2__) */
    }
    else
    {
        kal_bool is_logging = 
            VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING) ?
                KAL_TRUE :
                    KAL_FALSE;
        mem_pool->mem_id = kal_adm_create(mem_buf, mem_buf_size, NULL, is_logging);
        VFX_ASSERT(mem_pool->mem_id != NULL);
    }
    mem_pool->mem_buf       = mem_buf;
    mem_pool->mem_buf_size  = mem_buf_size;
    mem_pool->alloc_cnt     = 0;
    mem_pool->next_mem_pool = NULL;
    mem_pool->first_chunk   = NULL;
    mem_pool->last_chunk    = NULL;
    mem_pool->first_chunk_ext   = NULL;
    mem_pool->last_chunk_ext    = NULL;

    if (VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_RESET_STATISTICS))
    {
        mem_pool->max_used_size = 0;
        mem_pool->used_size     = 0;
        mem_pool->free_in_chunk_size = 0;
        mem_pool->free_in_chunk_size_ext = 0;
#if defined(__MMI_USE_MMV2__)
        mem_pool->max_used_page_size = 0;
#endif /* defined(__MMI_USE_MMV2__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_deinit
 * DESCRIPTION
 *  delete a memory pool
 * PARAMETERS
 *  mem_pool        [IN]   the memory pool to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_deinit(vfx_sys_mem_pool_struct *mem_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);
    VFX_DEV_ASSERT(mem_pool->mem_id != NULL);
    /* Not all memory of the memory pool has been freed  */
    VFX_DEV_ASSERT(mem_pool->alloc_cnt == 0);
    VFX_DEV_ASSERT(mem_pool->first_chunk == NULL);
    VFX_DEV_ASSERT(mem_pool->last_chunk == NULL);
    VFX_DEV_ASSERT(mem_pool->first_chunk_ext == NULL);
    VFX_DEV_ASSERT(mem_pool->last_chunk_ext == NULL);

#if !defined(__MMI_USE_MMV2__)
    VFX_DEV_ASSERT(!VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ASM_SLMM));
#endif

    if (HAS_ISSLMM_FLAG(mem_pool->flags))
    {
#if defined(__MMI_USE_MMV2__)
        MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id = (MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id;

        mmi_frm_asm_slmm_free( frm_asm_slmm_id, mem_pool );
        mmi_frm_asm_delete_slmm_pool( frm_asm_slmm_id );
#endif
    }
    else
    {
        kal_adm_delete((KAL_ADM_ID)mem_pool->mem_id);
        mem_pool->mem_id = NULL;
        mem_pool->flags = 0;
        mem_pool->mem_buf = NULL;
        mem_pool->mem_buf_size = 0;
        mem_pool->alloc_cnt = 0;
        mem_pool->next_mem_pool = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_enable_thread_safe
 * DESCRIPTION
 *  Enable flag VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE
 * PARAMETERS
 *  mem_pool        [OUT]   the memory pool to enable thread safe
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_enable_thread_safe(vfx_sys_mem_pool_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = (vfx_sys_mem_pool_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);
    VFX_DEV_ASSERT(!VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE));

    VFX_FLAG_SET(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_take_mutex
 * DESCRIPTION
 *  Take mutex if has flag VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE
 * PARAMETERS
 *  mem_pool        [OUT]   the memory pool to take mutex
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_take_mutex(vfx_sys_mem_pool_struct *mem_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);

    if (VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE))
    {
        vfx_sys_mutex_lock(&mem_pool->mem_mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_give_mutex
 * DESCRIPTION
 *  Give mutex if has flag VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE
 * PARAMETERS
 *  mem_pool        [OUT]   the memory pool to give mutex
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_give_mutex(vfx_sys_mem_pool_struct *mem_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);

    if (VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE))
    {
        vfx_sys_mutex_unlock(&mem_pool->mem_mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_update_status
 * DESCRIPTION
 *  update the status of a memory pool
 * PARAMETERS
 *  mem_pool        [OUT]   the memory pool to be updated
 * RETURNS
 *  1 :             mem_pool->max_used_size is updated 
 *  0 :             mem_pool->max_used_size is not updated
 *****************************************************************************/
static VfxU32 vfx_sys_mem_pool_update_status(vfx_sys_mem_pool_struct *mem_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 free_size;
    VfxU32 used_size;
    VfxU32 has_enlarged = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(mem_pool != NULL);
    
    if (HAS_ISSLMM_FLAG(mem_pool->flags))
    {
#if defined(__MMI_USE_MMV2__)
        VfxU32 used_page_size;
        free_size = mmi_frm_asm_get_slmm_total_left_size((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
        used_page_size = mmi_frm_asm_slmm_get_used_page_size((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
        if (used_page_size > mem_pool->max_used_page_size)
        {
            mem_pool->max_used_page_size = used_page_size;
        }
#endif /* defined(__MMI_USE_MMV2__) */
    }
    else
    {
        free_size = kal_adm_get_total_left_size((KAL_ADM_ID)mem_pool->mem_id);
    }

    used_size = mem_pool->mem_buf_size - free_size - mem_pool->free_in_chunk_size;
    mem_pool->used_size = used_size;
        
    if (used_size > mem_pool->max_used_size)
    {
        mem_pool->max_used_size = used_size;
        has_enlarged = 1;
    }

    return has_enlarged;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_create_chunk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to be add a chunk
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_init_chunk(vfx_sys_mem_pool_chunk_struct *chunk, VfxS32 is_logging, kal_bool flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU8 *p;
    VfxU32 blocksize = flag ? VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE_16 : VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(chunk != NULL);
    
    /* Initialize chunk structure */
    chunk->alloc_block_cnt = 0;
    chunk->prev_chunk = NULL;
    chunk->next_chunk = NULL;

    /* Make the free block list */    
    chunk->first_free_block = p = chunk->buffer + ((is_logging) ? sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct) : 0 );
    while (1)
    {
        VfxU32 block_size = blocksize + ((is_logging) ? sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct) : 0 );
        VfxU8 *next = p + block_size;

        /* init the extheader, it would be used to traverse the used blocks and print log */
        if (is_logging)
        {
            vfx_sys_mem_pool_chunk_block_extheader_struct *header = 
                (vfx_sys_mem_pool_chunk_block_extheader_struct *)(p - sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
            header->filename = 0x00;
            header->line = 0x00;
        }
        
        if ( (next + block_size) > chunk->buffer + sizeof(chunk->buffer))
        {
            (*(VfxU8 **)p) = NULL;
            break;
        }
        else
        {
            (*(VfxU8 **)p) = next;
            p = next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_insert_chunk_to_first
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to be add a chunk
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_insert_chunk_to_first(
    vfx_sys_mem_pool_struct *mem_pool,
    vfx_sys_mem_pool_chunk_struct *chunk,
    kal_bool flag)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);
    VFX_DEV_ASSERT(chunk != NULL);    
    VFX_DEV_ASSERT(chunk->prev_chunk == NULL && chunk->next_chunk == NULL);
    
    if (flag)
    {
    
        /* Let the chunk be the last one if the list is empty */
        if (mem_pool->last_chunk_ext == NULL)
        {
            mem_pool->last_chunk_ext = chunk;
        }
    
        /* Insert into the first chunk */
        chunk->prev_chunk = NULL;
        chunk->next_chunk = mem_pool->first_chunk_ext;    
        
        if (mem_pool->first_chunk_ext != NULL)
        {
            mem_pool->first_chunk_ext->prev_chunk = chunk;
        }    
        mem_pool->first_chunk_ext = chunk;
    }
    else
    {
        /* Let the chunk be the last one if the list is empty */
        if (mem_pool->last_chunk == NULL)
        {
            mem_pool->last_chunk = chunk;
        }
    
        /* Insert into the first chunk */
        chunk->prev_chunk = NULL;
        chunk->next_chunk = mem_pool->first_chunk;    
        
        if (mem_pool->first_chunk != NULL)
        {
            mem_pool->first_chunk->prev_chunk = chunk;
        }    
        mem_pool->first_chunk = chunk;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_insert_chunk_to_last
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to be add a chunk
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_insert_chunk_to_last(
    vfx_sys_mem_pool_struct *mem_pool,
    vfx_sys_mem_pool_chunk_struct *chunk,
    kal_bool flag)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);
    VFX_DEV_ASSERT(chunk != NULL);    
    VFX_DEV_ASSERT(chunk->prev_chunk == NULL && chunk->next_chunk == NULL);
    
    /* Let the chunk be the last one if the list is empty */
    if (flag)
    {
        if (mem_pool->first_chunk_ext == NULL)
        {
            mem_pool->first_chunk_ext = chunk;
        }
        /* Insert into the first chunk */
        chunk->prev_chunk = mem_pool->last_chunk_ext;    
        chunk->next_chunk = NULL;
    
        if (mem_pool->last_chunk_ext != NULL) 
        {
            mem_pool->last_chunk_ext->next_chunk = chunk;
        }    
        mem_pool->last_chunk_ext = chunk;
    }
    else
    {
        if (mem_pool->first_chunk == NULL)
        {
            mem_pool->first_chunk = chunk;
        }
        /* Insert into the first chunk */
        chunk->prev_chunk = mem_pool->last_chunk;    
        chunk->next_chunk = NULL;
    
        if (mem_pool->last_chunk != NULL)
        {
            mem_pool->last_chunk->next_chunk = chunk;
        }    
        mem_pool->last_chunk = chunk;
    }
    
    
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_remove_chunk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to be add a chunk
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_remove_chunk(
    vfx_sys_mem_pool_struct *mem_pool,
    vfx_sys_mem_pool_chunk_struct *chunk,
    kal_bool flag)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);
    VFX_DEV_ASSERT(chunk != NULL);    

    /* Remove the chunk from the list */
    if (chunk->next_chunk != NULL)
    {
        chunk->next_chunk->prev_chunk = chunk->prev_chunk;
    }
    else
    {
        if (flag)
        {
            mem_pool->last_chunk_ext = chunk->prev_chunk;
        }
        else
        {
            mem_pool->last_chunk = chunk->prev_chunk;
        }
    }

    if (chunk->prev_chunk != NULL)
    {
        chunk->prev_chunk->next_chunk = chunk->next_chunk;
    }
    else
    {
        if (flag)
        {
            mem_pool->first_chunk_ext = chunk->next_chunk;
        }
        else
        {
            mem_pool->first_chunk = chunk->next_chunk;
        }
    }

    chunk->prev_chunk = NULL;
    chunk->next_chunk = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_adm_block_print
 * DESCRIPTION
 *  get the adm block extheader info and print
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool vfx_sys_mem_pool_adm_block_print(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data)
{
    ADM_MB_OLDLOGGING_EXTHEADER *logging;
    ADM_CB * const adm_cb = (ADM_CB *)adm_id;
    kal_uint32 size;
    if (!(flags & KAL_ADM_MB_INUSE)) 
    {   /*it's a free block*/
        return KAL_TRUE;
    }

    logging = (ADM_MB_OLDLOGGING_EXTHEADER *)((kal_uint8 *)adm_mb_head + sizeof(ADM_MB_MINI_HEAD) 
                + (ADM_HAS_GUARDIAN_FLAG(adm_cb) ? sizeof(ADM_MB_HEADGUARD) : 0) );

    size = 
        ADM_MB_SIZE(adm_mb_head) - 
        sizeof(ADM_MB_MINI_HEAD) -
        (ADM_HAS_GUARDIAN_FLAG(adm_cb) ? sizeof(ADM_MB_HEADGUARD) + sizeof(ADM_MB_FOOTGUARD) : 0) -
        (ADM_HAS_EXTHEADER_FLAG(adm_cb) ? sizeof(kal_uint32) * adm_cb->extheader_size : 0 ) ;
    
#ifndef __MTK_TARGET__
    sprintf(g_vfx_sys_mem_log_info_str, "[VfxContextLog]File: %s Line: %d Size :%d in ADM block\n", 
                      logging->filename, logging->line, size);
    VFX_TRACE((g_vfx_sys_mem_log_info_str));
#else
    /*In the Target case, we record the caller address in filename field rather than filename string in order to reduce ROM size*/
    sprintf(g_vfx_sys_mem_log_info_str, "[VfxContextLog]Caller Address: 0x%x Line: %d Size :%d in ADM Block - Product: %s Version: %s BuildTime: %s\n", 
                      logging->filename, logging->line, size,
                      release_branch(), release_verno(), build_date_time());
    /*Currently (~2011/06/02), the catcher can only do the  Caller Address -> file/function convertion in system trace*/
    tst_sysfatal_trace((kal_char*)g_vfx_sys_mem_log_info_str);
#endif

    return KAL_TRUE;
}


#if defined(__MMI_USE_MMV2__)
/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_slmm_block_print
 * DESCRIPTION
 *  get the slmm block extheader info and print
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool vfx_sys_mem_pool_slmm_block_print(KAL_SLMM_ID slmm_id, kal_vm_meminfo_t *info, void *v_addr, void *userdata)
{
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id = (MMI_FRM_ASM_SLMM_ID)userdata;
    kal_uint32 log_flag = mmi_frm_asm_get_slmm_log_flag(frm_asm_slmm_id);

    if (info->attr == 0)
    {   /*it's a free block*/
        return KAL_TRUE;
    }

    if (log_flag & APPLIB_MEM_SLMM_LOG_W_RETURN_ADDR)
    {
        sprintf(
            g_vfx_sys_mem_log_info_str, 
            "[VfxContextLog]Caller Address: 0x%x Line: %d Size :%d in SLMM Block - Product: %s Version: %s BuildTime: %s\n", 
            info->filename, 
            info->line, 
            info->size,
            release_branch(), 
            release_verno(), 
            build_date_time());
#ifndef __MTK_TARGET__
        VFX_TRACE((g_vfx_sys_mem_log_info_str));
#else
        tst_sysfatal_trace((kal_char*)g_vfx_sys_mem_log_info_str);
#endif
    }
    else
    {
        if ((kal_uint32)info->filename == INVALID_FILE)
        {
            sprintf(
                g_vfx_sys_mem_log_info_str, 
                "[VfxContextLog]File: %d Line: %d Size :%d in SLMM block\n", 
                (kal_uint32)info->filename, 
                info->line, 
                info->size);
        }
        else
        {
            sprintf(
                g_vfx_sys_mem_log_info_str, 
                "[VfxContextLog]File: %s Line: %d Size :%d in SLMM block\n", 
                info->filename, 
                info->line, 
                info->size);
        }
#ifndef __MTK_TARGET__
        VFX_TRACE((g_vfx_sys_mem_log_info_str));
#else
        tst_sysfatal_trace((kal_char*)g_vfx_sys_mem_log_info_str);
#endif
    }

    return KAL_TRUE;
}
#endif /* defined(__MMI_USE_MMV2__) */


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_chunk_block_print
 * DESCRIPTION
 *  get the mem_pool block (partition) extheader info and print
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void vfx_sys_mem_pool_chunk_block_print(vfx_sys_mem_pool_struct *mem_pool, vfx_sys_mem_pool_chunk_block_extheader_struct* header, void *user_data)
{
    if (header->filename == 0x00 && header->line == 0x00)
    { /*it's a free block*/
        return;
    }

    if (header->filename == INVALID_FILE && header->line == INVALID_LINE)
    { /*it's a invalid log and means some allocation bypass current logging mechanism path*/
        sprintf(
            g_vfx_sys_mem_log_info_str, 
            "[VfxContextLog] Chunk Block Usage - File: invalid Line: invalid Size <= %d Byte\n", 
            VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE);
        VFX_TRACE((g_vfx_sys_mem_log_info_str));
        return;
    }

#ifndef __MTK_TARGET__
    sprintf(
        g_vfx_sys_mem_log_info_str, 
        "[VfxContextLog]File: %s Line: %d Size <= %d Byte in Chunk Block\n", 
        header->filename, 
        header->line, 
        VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE);
    VFX_TRACE((g_vfx_sys_mem_log_info_str));
#else
    /*In the Target case, we record the caller address in filename field rather than filename string in order to reduce ROM size*/
    sprintf(
        g_vfx_sys_mem_log_info_str, 
        "[VfxContextLog]Caller Address: 0x%x Line: %d Size <= %d Byte in Chunk Block - Product: %s Version: %s BuildTime: %s\n", 
        header->filename, 
        header->line, 
        VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE,
        release_branch(), 
        release_verno(), 
        build_date_time());
    /*Currently (~2011/06/02), the catcher can only do the  Caller Address -> file/function convertion in system trace*/
    tst_sysfatal_trace((kal_char*)g_vfx_sys_mem_log_info_str);
#endif
    //VFX_LOG; /*catcher*/
    //VFX_TRACE; /*Modis console*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_chunk_block_traverse
 * DESCRIPTION
 *  tracerse the mem_pool chunk block (partition) to get the block extheader info
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to allocate
 *  callback        [IN]    The callback to handle block extheader info
 *  user_data       [IN]    user data
 * RETURNS
 *  
 *****************************************************************************/
static void vfx_sys_mem_pool_chunk_block_traverse(vfx_sys_mem_pool_struct *mem_pool, vfx_sys_mem_pool_chunk_block_visitor callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_chunk_struct *chunk;
    VfxU32 block_size = VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE + sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct);
    VfxU8 *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING))
    {
        return;
    }

    for (chunk = mem_pool->first_chunk; chunk != NULL; chunk = chunk->next_chunk)
    {
        p = chunk->buffer;
        while (1)
        {
            if ( (p + block_size) > chunk->buffer + sizeof(chunk->buffer))
            {
                break;
            }
            /*here means the block p is inside the chunk*/
            callback (mem_pool,(vfx_sys_mem_pool_chunk_block_extheader_struct*)p,user_data ) ;
            p += block_size ; 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_alloc_block
 * DESCRIPTION
 *  Allocate a memory block from chunk list
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to allocate
 * RETURNS
 *  
 *****************************************************************************/
static VfxU8 *vfx_sys_mem_pool_alloc_block(VfxU32 size, vfx_sys_mem_pool_struct *mem_pool, const VfxChar *filename, VfxU32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_chunk_struct *chunk;
    VfxU8 *ptr = NULL;
    VfxS32 is_logging = VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING);
    kal_bool isSmallChunk = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(mem_pool != NULL);
    VFX_ASSERT( !HAS_ISSLMM_FLAG(mem_pool->flags) );

    /* The first chunk should have a free block */
    if (size > VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE_16)
    {
        chunk = mem_pool->first_chunk;
    }
    else
    {
        chunk = mem_pool->first_chunk_ext;
        isSmallChunk = KAL_TRUE; 
    }    

    if (chunk == NULL || chunk->first_free_block == NULL)
    {
        if (!is_logging)
        {
            /* There is no chunk to create block, so create a new chunk */
            chunk = (vfx_sys_mem_pool_chunk_struct *)kal_adm_alloc(
                (KAL_ADM_ID)mem_pool->mem_id, VFX_SYS_MEM_POOL_CHUNK_SIZE);
        }
        else
        {
            const VfxChar *filename;
            VfxU32 line;
            VFX_MEM_FILL_FILENAME(filename, line);
            /* There is no chunk to create block, so create a new chunk */
            chunk = (vfx_sys_mem_pool_chunk_struct *)kal_adm_alloc_dbg(
                (KAL_ADM_ID)mem_pool->mem_id, 
                VFX_SYS_MEM_POOL_CHUNK_SIZE, 
                (char*)filename, 
                line);
        }

        if (chunk == NULL)
        {
            return NULL;
        }
        if (isSmallChunk)
        {
            mem_pool->free_in_chunk_size_ext += (VFX_SYS_MEM_POOL_CHUNK_SIZE - VFX_SYS_MEM_POOL_CHUNK_HEADER_FOOTER_SIZE);
        }
        else
        {
            mem_pool->free_in_chunk_size += (VFX_SYS_MEM_POOL_CHUNK_SIZE - VFX_SYS_MEM_POOL_CHUNK_HEADER_FOOTER_SIZE);
        }
        vfx_sys_mem_pool_init_chunk(chunk, is_logging, isSmallChunk);
        vfx_sys_mem_pool_insert_chunk_to_first(mem_pool, chunk, isSmallChunk);
    }

    /* Get the first of the free block list in chunk */
    ptr = chunk->first_free_block;
    chunk->alloc_block_cnt++;
    chunk->first_free_block = *(VfxU8 **)ptr;

    /* If the chunk has no free block, move to the tail of list */
    if (chunk->first_free_block == NULL && ((!isSmallChunk && mem_pool->last_chunk != chunk)
                                || (isSmallChunk && mem_pool->last_chunk_ext != chunk)))
    {
        vfx_sys_mem_pool_remove_chunk(mem_pool, chunk, isSmallChunk);
        vfx_sys_mem_pool_insert_chunk_to_last(mem_pool, chunk, isSmallChunk);
    }

    /* Fill the log info to extra header */
    if (is_logging)
    {
        vfx_sys_mem_pool_chunk_block_extheader_struct *header = 
            (vfx_sys_mem_pool_chunk_block_extheader_struct *)(ptr - sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
        header->filename = (VfxU32)filename;
        header->line = line;
        if (isSmallChunk)
        {
            mem_pool->free_in_chunk_size_ext -= (VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE_16 + sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
        }
        else
        {
            mem_pool->free_in_chunk_size -= (VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE + sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
        }
    }
    else
    {
        if (isSmallChunk)
        {
            mem_pool->free_in_chunk_size_ext -= VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE_16;
        }
        else
        {
            mem_pool->free_in_chunk_size -= VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE;
        }
    }

    /* Fill zero to remove previous "free magic number" */
    *((VfxU32 *)ptr + 1) = 0;
    *((VfxU32 *)ptr + 2) = 0;
    
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_free_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_pool        [IN]    the memory pool to be updated
 *  ptr             [IN]    the memory pointer to free
 * RETURNS
 *  
 *****************************************************************************/
static VfxS32 vfx_sys_mem_pool_free_block(vfx_sys_mem_pool_struct *mem_pool, VfxU8 *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_chunk_struct *chunk;
    VfxS32 is_logging = VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING);
    kal_bool isSmallChunk = KAL_FALSE;

    VFX_ASSERT( !HAS_ISSLMM_FLAG(mem_pool->flags) );

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: need to enhance performance
    for (chunk = mem_pool->first_chunk; chunk != NULL; chunk = chunk->next_chunk)
    {
        VfxU8 *chunk_block_start = (VfxU8 *)chunk;
        if (ptr >= chunk_block_start && ptr < chunk_block_start + VFX_SYS_MEM_POOL_CHUNK_SIZE)
        {
            break;
        }
    }
    if (chunk == NULL)
    {
        for (chunk = mem_pool->first_chunk_ext; chunk != NULL; chunk = chunk->next_chunk)
        {
            VfxU8 *chunk_block_start = (VfxU8 *)chunk;
            if (ptr >= chunk_block_start && ptr < chunk_block_start + VFX_SYS_MEM_POOL_CHUNK_SIZE)
            {
                isSmallChunk = KAL_TRUE;
                break;
            }
        }

        if (chunk == NULL)
        {
            /* The pointer is not in any chunk of list */
            return 0;
        }
    }

    /* NOTE: assert here if free a memory block twice */
    VFX_ASSERT(
        *((VfxU32 *)ptr + 1) != VFX_SYS_MEM_POOL_BLOCK_FREE_MAGIC_1 && 
        *((VfxU32 *)ptr + 2) != VFX_SYS_MEM_POOL_BLOCK_FREE_MAGIC_2);

    /* Free the block to the free block list */    
    *(VfxU8 **)ptr = chunk->first_free_block;
    *((VfxU32 *)ptr + 1) = VFX_SYS_MEM_POOL_BLOCK_FREE_MAGIC_1;
    *((VfxU32 *)ptr + 2) = VFX_SYS_MEM_POOL_BLOCK_FREE_MAGIC_2;
    if (is_logging)
    {
        vfx_sys_mem_pool_chunk_block_extheader_struct *header = 
            (vfx_sys_mem_pool_chunk_block_extheader_struct *)(ptr - sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
        header->filename = 0x00;
        header->line = 0x00;
        if (isSmallChunk)
        {
            mem_pool->free_in_chunk_size_ext += (VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE + sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
        }
        else
        {
            mem_pool->free_in_chunk_size += (VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE + sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct));
            
        }
    }
    else
    {
        if (isSmallChunk)
        {
            mem_pool->free_in_chunk_size_ext += VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE;
        }
        else
        {
            mem_pool->free_in_chunk_size += VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE;
        }
    }
    chunk->first_free_block = ptr;
    chunk->alloc_block_cnt--;

    /* If there is no used block, free the chunk */
    if (chunk->alloc_block_cnt == 0)
    {
        vfx_sys_mem_pool_remove_chunk(mem_pool, chunk, isSmallChunk);
        kal_adm_free((KAL_ADM_ID)mem_pool->mem_id, chunk);
        if (isSmallChunk)
        {
           mem_pool->free_in_chunk_size_ext -= (VFX_SYS_MEM_POOL_CHUNK_SIZE - VFX_SYS_MEM_POOL_CHUNK_HEADER_FOOTER_SIZE);
        }
        else
        {   
            mem_pool->free_in_chunk_size -= (VFX_SYS_MEM_POOL_CHUNK_SIZE - VFX_SYS_MEM_POOL_CHUNK_HEADER_FOOTER_SIZE);
        }
    }
    else
    {
        /* or move the chunk to the first. Let the first chuck has free block. */
        if ((!isSmallChunk && mem_pool->first_chunk != chunk) ||
             (isSmallChunk && mem_pool->first_chunk_ext != chunk))
        {
            vfx_sys_mem_pool_remove_chunk(mem_pool, chunk, isSmallChunk);
            vfx_sys_mem_pool_insert_chunk_to_first(mem_pool, chunk, isSmallChunk);
        }
    }
    
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_check_integrity
 * DESCRIPTION
 *  Assert if the pool has memory corruption (typically buffer overflow)
 * PARAMETERS
 *  mem_pool    [IN]    the memory pool to check
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_check_integrity(vfx_sys_mem_pool_struct *mem_pool)
{
#if defined(__MMI_USE_MMV2__)
    if (HAS_ISSLMM_FLAG(mem_pool->flags))
    {
        VFX_ASSERT(mmi_frm_asm_slmm_check_integrity((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id) == NULL);
        return;
    }
#endif

    VFX_ASSERT(kal_adm_check_integrity((KAL_ADM_ID)mem_pool->mem_id) == NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_own
 * DESCRIPTION
 *  Test if the memory pool own the pointer of memory
 * PARAMETERS
 *  mem_pool    [IN]    the memory pool to test
 *  ptr         [IN]    the memory size to be test
 * RETURNS
 *  the allocated memory, return NULL if out of memory
 *****************************************************************************/
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_USE_MMV2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_is_all_free
 * DESCRIPTION
 *  Check if the memory pool is all free
 * PARAMETERS
 *  mem_pool        [OUT]   the memory pool to be created
 * RETURNS
 *  
 *****************************************************************************/
static VfxS32 vfx_sys_mem_pool_is_all_free(vfx_sys_mem_pool_struct *mem_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool != NULL);

    return mem_pool->alloc_cnt == 0;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_dbg_mem_pool_logging_dump
 * DESCRIPTION
 *  dump the mem pool logging info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_dbg_mem_pool_logging_dump(vfx_sys_dbg_mem_pool_logging_dump_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = para->mem_pool;
    VfxU32 size = para->size;
    const VfxChar *filename = para->filename;
    VfxU32 line = para->line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    sprintf(
        g_vfx_sys_mem_log_info_str, 
        "[VfxContextLog][Error] File: %s, Line: %d try to locate %d and over Quota\n", 
        filename, 
        line, 
        size);
    VFX_TRACE((g_vfx_sys_mem_log_info_str));
    sprintf(
        g_vfx_sys_mem_log_info_str, 
        "[VfxContextLog][Error] Its Quota:%d. Used size:%d \n", 
        mem_pool->mem_buf_size, 
        mem_pool->used_size );
    VFX_TRACE((g_vfx_sys_mem_log_info_str));
#else
    /*In the Target case, we record the caller address in filename field rather than filename string in order to reduce ROM size*/
    sprintf(
        g_vfx_sys_mem_log_info_str, 
        "[VfxContextLog][Error] Caller Address: 0x%x Line: %d try to locate %d and over Quota - Product: %s Version: %s BuildTime: %s\n", 
        filename, 
        line, 
        size,
        release_branch(), 
        release_verno(), 
        build_date_time());
    /*Currently (~2011/06/02), the catcher can only do the  Caller Address -> file/function convertion in system trace*/
    tst_sysfatal_trace((kal_char*)g_vfx_sys_mem_log_info_str);
    sprintf(g_vfx_sys_mem_log_info_str, "[VfxContextLog][Error] Its Quota:%d. Used size:%d \n", 
                      mem_pool->mem_buf_size, mem_pool->used_size );
    tst_sysfatal_trace((kal_char*)g_vfx_sys_mem_log_info_str);
#endif

    if (!VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING))
    {
        return ;
    }
    
    if (HAS_ISSLMM_FLAG(mem_pool->flags))
    {
#if defined(__MMI_USE_MMV2__)
        KAL_SLMM_ID kal_vm_id = mmi_frm_asm_get_kal_slmm_id((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
        kal_slmm_traverse(kal_vm_id, 0x00, vfx_sys_mem_pool_slmm_block_print, (void*)mem_pool->mem_id);
#endif /* defined(__MMI_USE_MMV2__) */
    }
    else
    {
        kal_adm_traverse((KAL_ADM_ID)mem_pool->mem_id, KAL_ADM_TRAVERSE_NO_CONCHECK, vfx_sys_mem_pool_adm_block_print, 0);
        vfx_sys_mem_pool_chunk_block_traverse(mem_pool, vfx_sys_mem_pool_chunk_block_print, NULL);
    }
 }


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_check_alloc
 * DESCRIPTION
 *  Check allocation result, ignore if VFX_SYS_MEM_POOL_CREATE_FLAG_DISABLE_ALLOC_CHECK
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_check_alloc(vfx_sys_mem_pool_struct *mem_pool, vfx_sys_mem_alloc_ret_enum alloc_ret, VfxU32 size, const VfxChar *filename, VfxU32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_DISABLE_ALLOC_CHECK))
    {
        return;
    }

    /*
     * Dump log data
     */
    if (alloc_ret != VFX_SYS_MEM_ALLOC_RET_OK && 
        VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING))
    {
        vfx_sys_dbg_mem_pool_logging_dump_struct para;
        para.mem_pool = mem_pool;
        para.size = size;
        para.filename = filename;
        para.line = line;
#if !defined(__MTK_TARGET__) && defined(WIN32)
        vfx_sys_dbg_mem_pool_logging_dump(&para);
#else
        EXT_ASSERT_SPECIFIC(
            0, 
            (vrt_u32)alloc_ret, 
            (vrt_u32)mem_pool, 
            (vrt_u32)size,
            ASSERT_SPECIFIC_CALLBACK, 
            (Assert_Specific_Callback)vfx_sys_dbg_mem_pool_logging_dump, 
            (void*)&para);
#endif
    }

    /* 
     * NOTES:
     *  Please check the value of alloc_ret for error reason.
     */
    VFX_EXT_ASSERT(alloc_ret == VFX_SYS_MEM_ALLOC_RET_OK, (vrt_u32)alloc_ret, (vrt_u32)mem_pool, (vrt_u32)size);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_allocator_release_user_data_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_allocator_release_user_data_callback(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(user_data != NULL);

    vfx_sys_mem_pool_destroy((vfx_sys_mem_pool_handle)user_data);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_allocator_alloc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void *vfx_sys_mem_pool_allocator_alloc_callback(
    vrt_size size, 
    void *user_data, 
    vrt_flag_type flags,
    const vrt_char *file,
    vrt_u32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    vfx_sys_mem_alloc_ret_enum alloc_ret;
    vfx_sys_mem_pool_handle mem_pool_handle = (vfx_sys_mem_pool_handle)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool_handle != NULL);
    
    ptr = vfx_sys_mem_pool_alloc_int(mem_pool_handle, size, flags, &alloc_ret, file, line);
    
    VFX_MEM_LOG(("[VFX] NEW %08X %08X %08X %d <MEM>", mem_pool_handle, 0, ptr, size));

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_allocator_free_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_sys_mem_pool_allocator_free_callback(void *ptr, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_handle mem_pool_handle = (vfx_sys_mem_pool_handle)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_DEV_ASSERT(mem_pool_handle != NULL);
        
    VFX_MEM_LOG(("[VFX] DELETE %08X", ptr));
        
    vfx_sys_mem_pool_free(mem_pool_handle, ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_overall_update
 * DESCRIPTION
 *  update the g_vfx_heap_profiling_overall_arr if necessary
 * PARAMETERS
 *  vfx_sys_mem_pool_struct * mem_pool :  mem_pool
 * RETURNS
 *  void
 *****************************************************************************/
static void vfx_heap_profiling_overall_update(vfx_sys_mem_pool_struct *mem_pool)
{
    MMI_ID app_base_id;
    vrt_u32 i;
    app_base_id = mmi_res_get_app_baseID(mem_pool->app_id);

    for (i = 0; i < sizeof(g_vfx_heap_profiling_overall_arr)/sizeof(g_vfx_heap_profiling_overall_arr[0]); i++)
    {
        if (g_vfx_heap_profiling_overall_arr[i].app_id == app_base_id)
        {
            vfx_sys_mem_pool_take_mutex(mem_pool);
            if (mem_pool->max_used_size > g_vfx_heap_profiling_overall_arr[i].peak_size)
            {
                g_vfx_heap_profiling_overall_arr[i].peak_size = mem_pool->max_used_size;
                g_vfx_heap_profiling_overall_arr[i].pool_size = mem_pool->mem_buf_size;
#if defined(__MMI_USE_MMV2__)
                g_vfx_heap_profiling_overall_arr[i].peak_page_size = mem_pool->max_used_page_size;
#endif
            }
            vfx_sys_mem_pool_give_mutex(mem_pool);
            break;
        }
        else if (g_vfx_heap_profiling_overall_arr[i].app_id == GRP_ID_INVALID)
        {
            vfx_sys_mem_pool_take_mutex(mem_pool);
            g_vfx_heap_profiling_overall_arr[i].app_id = app_base_id;
            g_vfx_heap_profiling_overall_arr[i].peak_size = mem_pool->max_used_size;
            g_vfx_heap_profiling_overall_arr[i].pool_size = mem_pool->mem_buf_size;
#if defined(__MMI_USE_MMV2__)
            g_vfx_heap_profiling_overall_arr[i].peak_page_size = mem_pool->max_used_page_size;
#endif
            vfx_sys_mem_pool_give_mutex(mem_pool);
            break;
        }
    }
}


#if defined(__VFX_HEAP_PROFILE__)
#if defined(__MMI_USE_MMV2__)
/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_slmm_block_snapshot
 * DESCRIPTION
 *  snapshot the memory block that exist in slmm 
 * PARAMETERS
 *  slmm_id:    the kal slmm id
 *  info:       info of the block
 *  v_addr:     virtuall address of the block
 *  userdata:   user data
 * RETURNS
 *  KAL_TRUE
 *  
 *****************************************************************************/
static kal_bool vfx_heap_profiling_slmm_block_snapshot(KAL_SLMM_ID slmm_id, kal_vm_meminfo_t *info, void *v_addr, void *userdata)
{
    void *ptr = userdata;
    if (info->attr == 0)
    {   /*it's a free block*/
        return KAL_TRUE;
    }
 
    if ( g_snapshotData.snapshotcount < sizeof(g_snapshotData.info)/sizeof(g_snapshotData.info[0]))
    {
        VfxU16 i = g_snapshotData.snapshotcount;
        g_snapshotData.info[i].file = (VfxU32)info->filename;
        g_snapshotData.info[i].line = info->line;
        g_snapshotData.info[i].size = info->size;
        g_snapshotData.info[i].mem_addr = (VfxU32)((info->attr & KAL_VM_NONCACHEABLE) ? info->physical : v_addr);
        if (g_snapshotData.info[i].mem_addr == (VfxU32)ptr)
        {
            g_snapshotData.trigger_ptr_idx = i;
        }
        g_snapshotData.info[i].mem_addr += vrt_allocator_get_mem_header_size(); /*header of allocator*/
        /*obj or not?*/
        if ( g_vfx_heap_profiling_isObj_func &&
             g_vfx_heap_profiling_isObj_func( (void*)g_snapshotData.info[i].mem_addr, (void**)&g_snapshotData.info[i].parent) )
        {
            g_snapshotData.info[i].virtual_table = *((VfxU32*)g_snapshotData.info[i].mem_addr);
        }
        else
        {
            g_snapshotData.info[i].virtual_table = NULL;
            g_snapshotData.info[i].parent = NULL;
        }
        g_snapshotData.snapshotcount ++;
    }
    
    return KAL_TRUE;
}
#endif /* defined(__MMI_USE_MMV2__) */

 
/***************************************************************************** 
 * FUNCTION
 *  vfx_heap_profiling_adm_block_snapshot
 * DESCRIPTION
 *  snapshot the memory block that exist in adm 
 * PARAMETERS
 *
 * RETURNS
 *  KAL_TRUE
 *  
 *****************************************************************************/
static kal_bool vfx_heap_profiling_adm_block_snapshot(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *adm_mb_head, void *user_data)
{
    void *ptr = user_data;
    ADM_MB_OLDLOGGING_EXTHEADER *logging;
    ADM_CB * const adm_cb = (ADM_CB *)adm_id;
    kal_uint32 size, overhead;

    if (!(flags & KAL_ADM_MB_INUSE)) 
    {   /*it's a free block*/
        return KAL_TRUE;
    }

    logging = (ADM_MB_OLDLOGGING_EXTHEADER *)((kal_uint8 *)adm_mb_head + sizeof(ADM_MB_MINI_HEAD) 
                + (ADM_HAS_GUARDIAN_FLAG(adm_cb) ? sizeof(ADM_MB_HEADGUARD) : 0) );
    size = ADM_MB_SIZE(adm_mb_head) - sizeof(ADM_MB_MINI_HEAD) 
    - (ADM_HAS_GUARDIAN_FLAG(adm_cb) ? sizeof(ADM_MB_HEADGUARD) + sizeof(ADM_MB_FOOTGUARD) : 0) 
    - (ADM_HAS_EXTHEADER_FLAG(adm_cb) ? sizeof(kal_uint32) * adm_cb->extheader_size : 0 ) ;
	overhead = sizeof(ADM_MB_MINI_HEAD) +(ADM_HAS_GUARDIAN_FLAG(adm_cb) ? sizeof(ADM_MB_HEADGUARD) + sizeof(ADM_MB_FOOTGUARD) : 0) 
    + (ADM_HAS_EXTHEADER_FLAG(adm_cb) ? sizeof(kal_uint32) * adm_cb->extheader_size : 0 );
 
    if ( g_snapshotData.snapshotcount < sizeof(g_snapshotData.info)/sizeof(g_snapshotData.info[0]))
    {
        VfxU16 i = g_snapshotData.snapshotcount;
        kal_uint32 length;
        g_snapshotData.info[i].file = (VfxU32)logging->filename;
        g_snapshotData.info[i].line = logging->line;
        g_snapshotData.info[i].size = (overhead << 24 | size);
        g_snapshotData.info[i].mem_addr = (VfxU32) kal_adm_get_buffer(adm_id, adm_mb_head, &length);
        if (g_snapshotData.info[i].mem_addr == (VfxU32)ptr )
            g_snapshotData.trigger_ptr_idx = i;
        g_snapshotData.info[i].mem_addr += vrt_allocator_get_mem_header_size(); /*header of allocator*/
        /*obj or not?*/
        if ( g_vfx_heap_profiling_isObj_func &&
             g_vfx_heap_profiling_isObj_func( (void*)g_snapshotData.info[i].mem_addr, (void**)&g_snapshotData.info[i].parent) )
        {
            g_snapshotData.info[i].virtual_table = *((VfxU32*)g_snapshotData.info[i].mem_addr);
        }
        else
        {
            g_snapshotData.info[i].virtual_table = NULL;
            g_snapshotData.info[i].parent = NULL;
        }
        g_snapshotData.snapshotcount ++;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_adm_block_snapshot
 * DESCRIPTION
 *  snapshot the memory block that exist in chunk block 
 * PARAMETERS
 *
 * RETURNS
 *  
 *  
 *****************************************************************************/
static void vfx_heap_profiling_chunk_block_snapshot(vfx_sys_mem_pool_struct *mem_pool, vfx_sys_mem_pool_chunk_block_extheader_struct* header, void *user_data)
{
    void *ptr = user_data;
    if (header->filename == 0x00 && header->line == 0x00)
    { /*it's a free block*/
        return;
    }
    if ( g_snapshotData.snapshotcount < sizeof(g_snapshotData.info)/sizeof(g_snapshotData.info[0]))
    {
        VfxU16 i = g_snapshotData.snapshotcount;
        kal_uint32 length, overhead;

		overhead = sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct);
        g_snapshotData.info[i].file = header->filename;
        g_snapshotData.info[i].line = header->line;
        g_snapshotData.info[i].size = (overhead << 24 | VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE);
        g_snapshotData.info[i].mem_addr = (VfxU32) header + sizeof(vfx_sys_mem_pool_chunk_block_extheader_struct);
        if (g_snapshotData.info[i].mem_addr == (VfxU32)ptr )
            g_snapshotData.trigger_ptr_idx = i;
        g_snapshotData.info[i].mem_addr += vrt_allocator_get_mem_header_size(); /*header of allocator*/
        /*obj or not?*/
        if ( g_vfx_heap_profiling_isObj_func &&
             g_vfx_heap_profiling_isObj_func( (void*)g_snapshotData.info[i].mem_addr, (void**)&g_snapshotData.info[i].parent) )
        {
            g_snapshotData.info[i].virtual_table = *((VfxU32*)g_snapshotData.info[i].mem_addr);
        }
        else
        {
            g_snapshotData.info[i].virtual_table = NULL;
            g_snapshotData.info[i].parent = NULL;
        }
        g_snapshotData.snapshotcount ++;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_trigger
 * DESCRIPTION
 *  trigger the profiling to snapshot heap usage
 * PARAMETERS
 *  mem_pool:   memory pool
 *  ptr:        current allocating pointer
 *  flag:       reserve
 * RETURNS
 *  1       profiling method is triggered
 *  0       bypass 
 *****************************************************************************/
static VfxU32 vfx_heap_profiling_trigger(vfx_sys_mem_pool_struct *mem_pool, void* ptr, VfxU32 flag)
{
    if (vfx_heap_profiling_check(mem_pool->app_id, mem_pool->used_size))
    {
        if ( mem_pool->used_size > g_snapshotData.max_size )
        {
            g_snapshotData.profile_app = mmi_res_get_app_baseID(mem_pool->app_id);
            g_snapshotData.max_size = mem_pool->used_size;
            g_snapshotData.snapshotcount = 0;/*reset*/
            #if defined __MMI_USE_MMV2__
            g_snapshotData.max_page_size = 0;/*reset*/
            #endif
            g_snapshotData.flag = SNAPSHOT_FLAG_DEFAULT; /*reset*/
            g_snapshotData.trigger_ptr_idx = VFX_HEAP_ALLOC_MAX; /*reset, invalid*/
            if (HAS_ISSLMM_FLAG(mem_pool->flags))
            {
#if defined(__MMI_USE_MMV2__)
                kal_uint32 log_flag = mmi_frm_asm_get_slmm_log_flag((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
                g_snapshotData.flag |= SNAPSHOT_FLAG_POOL_SLMM;
                g_snapshotData.flag |= (log_flag & APPLIB_MEM_SLMM_LOG_W_RETURN_ADDR) ? SNAPSHOT_FLAG_FILE_RETURN_ADDRESS : 0;
                g_snapshotData.max_page_size = mem_pool->max_used_page_size; /*mmi_frm_asm_slmm_get_used_page_size((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);*/
                kal_slmm_traverse( mmi_frm_asm_get_kal_slmm_id((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id), 0x0, 
                              vfx_heap_profiling_slmm_block_snapshot, ptr);
#endif
            }
            else
            {
#ifdef __MTK_TARGET__
                g_snapshotData.flag |= SNAPSHOT_FLAG_FILE_RETURN_ADDRESS;
#endif
                kal_adm_traverse((KAL_ADM_ID)mem_pool->mem_id, KAL_ADM_TRAVERSE_NO_CONCHECK, 
                                 vfx_heap_profiling_adm_block_snapshot, ptr);
                vfx_sys_mem_pool_chunk_block_traverse(mem_pool, vfx_heap_profiling_chunk_block_snapshot, ptr);
            }
            VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_TRIGGERED/*"[vfx_sys_mem_pool][Profile_detail] app id:%d used size:%d ,snapshoted"*/,
                    g_snapshotData.profile_app, g_snapshotData.max_size );
            if ( g_snapshotData.snapshotcount == sizeof(g_snapshotData.info)/sizeof(g_snapshotData.info[0]))
            {
                VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_OVER_COUNT /*"[vfx_sys_mem_pool][Profile_detail][Warning] app id:%d allocation count is larger than snapshot count, do partial snapshot"*/);
                
            }

            return 1;
        }
    }
    return 0;
}
#endif


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_init
 * DESCRIPTION
 *  Initialize Venus Memory Sub-system on bootup 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __VFX_HEAP_PROFILE__
    vfx_heap_profiling_data_init();
#endif
}


#if defined(__MMI_USE_MMV2__)
/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_create_with_slmm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
vfx_sys_mem_pool_handle vfx_sys_mem_pool_create_with_slmm(mmi_id app_id, U32 mem_size, VfxFlag flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = NULL;
    vfx_sys_mem_pool_struct *i;
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id;
    VfxU8 *mem_buf_head;
    VfxU8 *mem_buf_tail;
    const VfxChar *filename;
    VfxU32 line;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Memory pool can only create on MMI task */
    VFX_ASSERT(vfx_sys_is_mmitask());
    
    frm_asm_slmm_id = mmi_frm_asm_create_slmm_pool(app_id, mem_size, 
#ifndef __MTK_TARGET__ /* on MODIS */
        VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING) ? 1 : 0                                                 
#else
        VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING) ? 1 | APPLIB_MEM_SLMM_LOG_W_RETURN_ADDR : 0 
#endif
    );
    VFX_ASSERT(frm_asm_slmm_id != NULL);

    VFX_MEM_FILL_FILENAME(filename, line);
    mem_pool = (vfx_sys_mem_pool_struct *)mmi_frm_asm_slmm_alloc_sw_r_dbg(frm_asm_slmm_id, sizeof(vfx_sys_mem_pool_struct), (char*)filename, line);
    mem_buf_head = (VfxU8 *)mmi_frm_asm_get_slmm_vm_start(frm_asm_slmm_id);
    mem_buf_tail = (VfxU8 *)mmi_frm_asm_get_slmm_vm_end(frm_asm_slmm_id);

    /* Check if the memory buffer is overlap with exist memory pool */
    for (i = g_vfx_sys_mem_pool_list_head; i != NULL; i = i->next_mem_pool)
    {
        VfxU8 *pool_mem_buf_head = (VfxU8 *)i;
        VfxU8 *pool_mem_buf_tail;

        pool_mem_buf_head = i->mem_buf;
        pool_mem_buf_tail = pool_mem_buf_head + i->mem_buf_vm_size;

        if ((mem_buf_head >= pool_mem_buf_head && mem_buf_head < pool_mem_buf_tail) ||
            (mem_buf_tail > pool_mem_buf_head && mem_buf_tail <= pool_mem_buf_tail))
        {
            /* NOTE: Given memory pool is overlape with other memory pool */
            VFX_ASSERT(0);
        }            
    }

    // Initialize the memory pool
    vfx_sys_mem_pool_init(
        mem_pool,
        mem_buf_head,
        mmi_frm_asm_get_slmm_size(frm_asm_slmm_id),
        flags | VFX_SYS_MEM_POOL_CREATE_FLAG_RESET_STATISTICS | VFX_SYS_MEM_POOL_CREATE_FLAG_ASM_SLMM,
        (VfxU32)frm_asm_slmm_id); 

    // init the app_id
    mem_pool->app_id = app_id;    
    // Fill the slmm vm size
    mem_pool->mem_buf_vm_size = mem_buf_tail - mem_buf_head;
    // Insert into memory pool list
    mem_pool->next_mem_pool = g_vfx_sys_mem_pool_list_head;
    g_vfx_sys_mem_pool_list_head = mem_pool;

    return mem_pool;
}
#endif /* defined(__MMI_USE_MMV2__) */


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_backward_enlarge_slmm_heap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  1 : success
 *  0 : async enlarge 
 *****************************************************************************/
U32 vfx_sys_mem_pool_backward_enlarge_slmm_heap(mmi_id app_id, vrt_allocator_handle handle, U32 mem_size)
{
#if defined(__MMI_USE_MMV2__)
    vfx_sys_mem_pool_struct* mem_pool;
    U32 ret;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_ASSERT(handle != NULL);    
    mem_pool = (vfx_sys_mem_pool_struct*)vrt_allocator_get_info(handle)->user_data;
    if ( !HAS_ISSLMM_FLAG(mem_pool->flags))
    {   /*IT's not a slmm case, ignore the enlarging*/
        return 1;
    }
    ret = mmi_frm_asm_backward_enlarge_slmm_heap( app_id, (MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id, mem_size);
    return ret;
#else /* defined(__MMI_USE_MMV2__) */
    VRT_ASSERT(0);    
    return 0;
#endif /* defined(__MMI_USE_MMV2__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_enlarge_slmm_heap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  1 : success
 *  0 : async enlarge 
 *****************************************************************************/
U32 vfx_sys_mem_pool_enlarge_slmm_heap(
    mmi_id app_id, 
    vrt_allocator_handle handle, 
    U32 mem_size,
    mmi_proc_func func,  
    void *user_data,
    U32 flag
    )
{
#if defined(__MMI_USE_MMV2__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct* mem_pool;
    mmi_frm_asm_change_heap_size_para para;
    U32 ret;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_ASSERT(handle != NULL);    
    mem_pool = (vfx_sys_mem_pool_struct*)vrt_allocator_get_info(handle)->user_data;
    if ( !HAS_ISSLMM_FLAG(mem_pool->flags))
    {   /*IT's not a slmm case, ignore the enlarging*/
        return 1;
    }
    para.app_id = app_id;
    para.heap_size = mem_size;
    para.frm_asm_slmm_id = (MMI_FRM_ASM_SLMM_ID) mem_pool->mem_id;
    para.user_cb = func ;
    para.user_data = user_data;
    para.flag = (flag & VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_NO_OOM) ? 
         FRM_ASM_HEAP_CHANGE_FORCE_PREPARE : FRM_ASM_HEAP_CHANGE_DEFAULT;
    para.flag |= (flag & VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_UNHIDDEN) ? 
        FRM_ASM_HEAP_CHANGE_IN_UNHIDDEN : FRM_ASM_HEAP_CHANGE_DEFAULT;
    para.flag |= (flag & VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_IF_ENOUGH) ? 
        FRM_ASM_HEAP_CHANGE_IF_ENOUGH : FRM_ASM_HEAP_CHANGE_DEFAULT;
    ret = mmi_frm_asm_slmm_change_heap_size(&para);
    return ret;
#else /* defined(__MMI_USE_MMV2__) */
    VRT_ASSERT(0);    
    return 0;
#endif /* defined(__MMI_USE_MMV2__) */
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_shrink_slmm_heap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  1 : success
 *  0 : fail 
 *****************************************************************************/
U32 vfx_sys_mem_pool_shrink_slmm_heap(mmi_id app_id, vrt_allocator_handle handle, U32 mem_size)
{
#if defined(__MMI_USE_MMV2__)
    vfx_sys_mem_pool_struct* mem_pool;
    U32 ret;    
    U32 used_page;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_ASSERT(handle != NULL);    
    mem_pool = (vfx_sys_mem_pool_struct*)vrt_allocator_get_info(handle)->user_data;
    if ( !HAS_ISSLMM_FLAG(mem_pool->flags))
    {   /*It's not a slmm case, ignore the shrink*/
        return 1;
    }
    /*log used state in shrinking*/
    vfx_sys_mem_pool_update_status(mem_pool);
    used_page = mmi_frm_asm_slmm_get_used_page_size((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
    VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_USED_IN_SHRINK /*"[vfx_sys_mem_pool][shrink_slmm_heap] app:%d shrink heap size to %d (used page size:%d, used size: %d)"*/, 
            app_id, mem_size, used_page, mem_pool->used_size);

    ret = mmi_frm_asm_slmm_heap_shrink_size( app_id, (MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id, mem_size);
    return ret;
#else /* defined(__MMI_USE_MMV2__) */
    VRT_ASSERT(0);    
    return 0;
#endif /* defined(__MMI_USE_MMV2__) */
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
vfx_sys_mem_pool_handle vfx_sys_mem_pool_create(
    VfxU8 *mem_buf, 
    VfxU32 mem_buf_size,
    VfxFlag flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = NULL;
    vfx_sys_mem_pool_struct *i;
    VfxU32 struct_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Memory pool can only create on MMI task */
    VFX_ASSERT(vfx_sys_is_mmitask());
    
#if !defined(__MMI_USE_MMV2__)
    VFX_DEV_ASSERT(!VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ASM_SLMM));
#endif
    
    mem_pool = (vfx_sys_mem_pool_struct *)mem_buf;

    /* Caculate the memory pool header struct_size (align to 4) */
    struct_size = (sizeof(vfx_sys_mem_pool_struct) + 3) / 4 * 4;

    /* Check if the memory buffer is overlap with exist memory pool */
    for (i = g_vfx_sys_mem_pool_list_head; i != NULL; i = i->next_mem_pool)
    {
        const VfxU8 *mem_buf_head = mem_buf;
        const VfxU8 *mem_buf_tail = mem_buf + mem_buf_size;

        const VfxU8 *pool_mem_buf_head = (const VfxU8 *)i;
        const VfxU8 *pool_mem_buf_tail = (const VfxU8 *)i + struct_size + i->mem_buf_size;

        if ((mem_buf_head >= pool_mem_buf_head && mem_buf_head < pool_mem_buf_tail) ||
            (mem_buf_tail > pool_mem_buf_head && mem_buf_tail <= pool_mem_buf_tail))
        {
            /* NOTE: Given memory pool is overlape with other memory pool */
            VFX_ASSERT(0);
        }            
    }

    // Initialize the memory pool
    vfx_sys_mem_pool_init(
        mem_pool,
        mem_buf + struct_size,
        mem_buf_size - struct_size,
        flags | VFX_SYS_MEM_POOL_CREATE_FLAG_RESET_STATISTICS,
        0 /*no used, adm id gen inside*/);

    if (mem_buf_size <= VFX_SYS_MEM_POOL_SMALL_POOL_THRESHOLD)
    {
        VFX_FLAG_SET(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_SMALL_POOL);
    }

    // init the app_id
    mem_pool->app_id = GRP_ID_INVALID;
#if defined(__MMI_USE_MMV2__)
    mem_pool->mem_buf_vm_size = 0;
#endif
    // Insert into memory pool list
    mem_pool->next_mem_pool = g_vfx_sys_mem_pool_list_head;
    g_vfx_sys_mem_pool_list_head = mem_pool;

    return mem_pool;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vfx_sys_mem_pool_destroy(vfx_sys_mem_pool_handle handle)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = (vfx_sys_mem_pool_struct *)handle;
    vfx_sys_mem_pool_struct **i;
    VfxS32 is_all_free;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Memory pool can only destroy on MMI task */
    VFX_ASSERT(vfx_sys_is_mmitask());
    
    if (handle == NULL)
    {
        /* Do nothing */
        return;
    }

    if (!VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_DISABLE_LEAK_CHECK))
    {
        /* Check if all memory has been freed */
        is_all_free = vfx_sys_mem_pool_is_all_free(mem_pool);
        if (!is_all_free)
        {
            vfx_sys_mem_pool_update_status(mem_pool);
            if (VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING))
            {
                vfx_sys_dbg_mem_pool_logging_dump_struct para;
                para.mem_pool = mem_pool;
                para.size = 0;
                VFX_MEM_FILL_FILENAME(para.filename, para.line);        
#if !defined(__MTK_TARGET__) && defined(WIN32)
                vfx_sys_dbg_mem_pool_logging_dump(&para);
#else
                EXT_ASSERT_SPECIFIC(
                    0, 
                    (vrt_u32)mem_pool->alloc_cnt, 
                    (vrt_u32)mem_pool, 
                    (vrt_u32)0,
                    ASSERT_SPECIFIC_CALLBACK, 
                    (Assert_Specific_Callback)vfx_sys_dbg_mem_pool_logging_dump, 
                    (void*)&para);
#endif
            }
        }
        if (!is_all_free)
        {
            vfx_sys_dbg_mem_pool_dump(mem_pool, "Memory Leak!", 1);
        }

        VFX_ASSERT(is_all_free);
    }

    /* Assert if the pool has memory corruption */
    vfx_sys_mem_pool_check_integrity(mem_pool);

    // Remove from memory pool list
    for (i = &g_vfx_sys_mem_pool_list_head; *i != NULL; i = &((*i)->next_mem_pool))
    {
        if (*i == mem_pool)
        {
            *i = mem_pool->next_mem_pool;
            break;
        }
    }

    // The memory pool is not in the memory pool list
    VFX_ASSERT(*i != NULL);

    // Record the peak value of heap for profiliing
    if (mem_pool->app_id != GRP_ID_INVALID)
    {
        vfx_heap_profiling_overall_update(mem_pool);
    }
    // Deinitialized the memory pool

    vfx_sys_mem_pool_deinit(mem_pool);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_alloc_int
 * DESCRIPTION
 *  Allocate a memory from the memory pool
 * PARAMETERS
 *  mem_pool    [IN]    the memory pool to allocate
 *  size        [IN]    the memory size to allocate
 *  ret         [OUT]   the result, can be NULL
 *  file        [IN]   the result, can be NULL
 *  line        [IN]   the result, can be NULL
 * RETURNS
 *  The allocated memory, return NULL if out of memory or size is zero
 *****************************************************************************/
void *vfx_sys_mem_pool_alloc_int(vfx_sys_mem_pool_handle handle, VfxU32 size, VfxFlag flags, vfx_sys_mem_alloc_ret_enum *ret, const VfxChar *filename, VfxU32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_alloc_ret_enum alloc_ret = VFX_SYS_MEM_ALLOC_RET_OK;
    vfx_sys_mem_pool_struct *mem_pool = (vfx_sys_mem_pool_struct *)handle;
    void *ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(mem_pool != NULL);
    VFX_ASSERT(mem_pool->mem_id != NULL);

    /* Return NULL if size is zero */
    if (size == 0)
    {
        if (ret != NULL)
        {
            *ret = VFX_SYS_MEM_ALLOC_RET_ZERO_SIZE;
        }
        return NULL;
    }

    /* There is no log data, log a new position here */
    if (filename == NULL || line == 0)
    {
        VFX_MEM_FILL_FILENAME(filename, line);
    }

    vfx_sys_mem_pool_take_mutex(mem_pool);
    
    /* Select an allocation method */
    if (VFX_FLAG_HAS(flags, VFX_SYS_MEM_ALLOC_FLAG_FB))
    {
        /* case: allocate a frame buffer */
        if ( HAS_ISSLMM_FLAG(mem_pool->flags))
        {
#if defined(__MMI_USE_MMV2__)
            ptr = mmi_frm_asm_slmm_alloc_nc_r_dbg((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id, size, (char *)filename, line);
#endif
        }
        else
        {
            ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER_DBG((KAL_ADM_ID)mem_pool->mem_id, size, (char *)filename, line);
        }
    }
    else if (size <= VFX_SYS_MEM_POOL_MIN_BLOCK_SIZE && !VFX_FLAG_HAS(mem_pool->flags, VFX_SYS_MEM_POOL_CREATE_FLAG_SMALL_POOL))
    {
        /* case: allocate a small buffer */
        if (HAS_ISSLMM_FLAG(mem_pool->flags))
        {
#if defined(__MMI_USE_MMV2__)
            ptr = mmi_frm_asm_slmm_alloc_sw_r_dbg((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id, size, (char *)filename, line);
#endif
        }
        else
        {
            ptr = vfx_sys_mem_pool_alloc_block(size, mem_pool, filename, line);

            /* If there is no free block, try use adm allocate directly. */
            if (ptr == NULL)
            {
                ptr = kal_adm_alloc_dbg((KAL_ADM_ID)mem_pool->mem_id, size, (char *)filename, line);
            }
        }
    }
    else
    {
        /* Normal case */
        if ( HAS_ISSLMM_FLAG(mem_pool->flags))
        {
#if defined(__MMI_USE_MMV2__)
            ptr = mmi_frm_asm_slmm_alloc_sw_r_dbg((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id, size, (char *)filename, line);
#endif
        }
        else
        {
            ptr = kal_adm_alloc_dbg((KAL_ADM_ID)mem_pool->mem_id, size, (char *)filename, line);
        }
    }

#if !defined(__MTK_TARGET__)
    /*
     * Note:
     *  Remap memory address for "debug memory" mechanism on MoDIS
     */
    ptr = vrt_debug_remap_mem(ptr, size);
#endif

#if defined(__MMI_USE_MMV2__)
    // TODO: sync the size after enlarge/shrink rather than here
    if (HAS_ISSLMM_FLAG(mem_pool->flags))
    {
        mem_pool->mem_buf_size = mmi_frm_asm_get_slmm_size((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
    }
#endif

    if (ptr != NULL)
    {
        /* Fill magic number */
#if !defined(__MTK_TARGET__)
        memset(ptr, 0xab, size);
#endif

        mem_pool->alloc_cnt++;

        /* Update statistic information */
        if (vfx_sys_mem_pool_update_status(mem_pool))
        {
#if defined(__VFX_HEAP_PROFILE__)
            vfx_heap_profiling_trigger(mem_pool, ptr, 0x00);
#endif
        }
    }
    else
    {
        /* Check the reason */
        if (mem_pool->used_size + size <= mem_pool->mem_buf_size)
        {
            alloc_ret = VFX_SYS_MEM_ALLOC_RET_FRAGMENT;
        }
        else
        {
            alloc_ret = VFX_SYS_MEM_ALLOC_RET_OUT_OF_MEM;
        }
    }

    vfx_sys_mem_pool_give_mutex(mem_pool);

    vfx_sys_mem_pool_check_alloc(mem_pool, alloc_ret, size, filename, line);


    /* Setting result */
    if (ret != NULL)
    {
        *ret = alloc_ret;
    }

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_free
 * DESCRIPTION
 *  free a memory to memory pool
 * PARAMETERS
 *  ptr         [IN]    pointer to the memory to be free
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_pool_free(vfx_sys_mem_pool_handle mem_pool_handle, void *vptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = mem_pool_handle;
    //vfx_sys_mem_pool_struct *i;
#ifdef __MTK_TARGET__
    void* ptr = vptr;
#else
    void* ptr = vrt_debug_remap_mem_free(vptr);
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr == NULL)
    {
        /* Do nothing */
        return;
    }

    /* Because we can only create or release memory pool on MMI task,
        so we just need protect the memory pool data structure */
    vfx_sys_mem_pool_take_mutex(mem_pool);

    /* The pointer must be in one of the all memory pools */
    VFX_ASSERT(mem_pool != NULL);
    /* NOTE: Double free? */
    VFX_ASSERT(mem_pool->alloc_cnt > 0);

    if ( HAS_ISSLMM_FLAG(mem_pool->flags) )
    {
#if defined(__MMI_USE_MMV2__)
        mmi_frm_asm_slmm_free( (MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id, ptr);
        // TODO: sync the size after enlarge/shrink rather than here
        mem_pool->mem_buf_size = mmi_frm_asm_get_slmm_size((MMI_FRM_ASM_SLMM_ID)mem_pool->mem_id);
#endif
    }
    else
    {
        if (!vfx_sys_mem_pool_free_block(mem_pool, ptr))
        {
            kal_adm_free((KAL_ADM_ID)mem_pool->mem_id, ptr);
        }
    }
    mem_pool->alloc_cnt--;

    //vfx_sys_mem_pool_update_status(mem_pool);

    vfx_sys_mem_pool_give_mutex(mem_pool);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_get_status
 * DESCRIPTION
 *  Get status of the given memory pool handle.
 * PARAMETERS
 *  handle      [IN]    The given handle. If the handle is NULL, all value will be zero.
 *  status_buf  [OUT]   The buffer to get. Do nothing if NULL.
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_pool_get_status(vfx_sys_mem_pool_handle handle, vfx_sys_mem_pool_status_struct *status_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_struct *mem_pool = (vfx_sys_mem_pool_struct *)handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status_buf == NULL)
    {
        /* Do nothing */
        return;
    }
    
    vfx_sys_mem_zero(status_buf, sizeof(*status_buf));
    
    if (mem_pool == NULL)
    {
        return;
    }

    vfx_sys_mem_pool_take_mutex(mem_pool);
    vfx_sys_mem_pool_update_status(mem_pool);
    /* Initialize the result */
    status_buf->total_size      = mem_pool->mem_buf_size;
    status_buf->used_size       = mem_pool->used_size;
    status_buf->max_used_size   = mem_pool->max_used_size;

    vfx_sys_mem_pool_give_mutex(mem_pool);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_allocator_create
 * DESCRIPTION
 *  Create a memory pool to be an allocator
 * PARAMETERS
 *  mem_buf         [IN]    memory buffer
 *  mem_buf_size    [IN]    memory buffer size
 *  flags           [IN]    flags to create memory pool
 * RETURNS
 *  new allocator
 *****************************************************************************/
vrt_allocator_handle vfx_sys_mem_pool_allocator_create(
    VfxU8 *mem_buf, 
    VfxU32 mem_buf_size,
    VfxFlag flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_handle mem_pool;
    vrt_allocator_info_struct info;
    vrt_allocator_handle allocator;
    VfxFlag initFlags = flags;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(mem_buf != NULL && mem_buf_size != 0);

    /*
     * NOTE:
     *  Creating an allocater will use memory pool to allocate its data structure.
     *  There is no other one own this memory pool at this time, 
     *  so it doesn't need threading safe when creating an allocater
     */
    if (VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE))
    {
        VFX_FLAG_CLEAR(initFlags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE);
    }
    
    if (HAS_ISSLMM_FLAG(flags))
    {
#if defined(__MMI_USE_MMV2__)
        mem_pool = vfx_sys_mem_pool_create_with_slmm((mmi_id)(0xFFFF & (VfxU32)mem_buf), mem_buf_size, initFlags);
#endif
    }
    else
    {
        mem_pool = vfx_sys_mem_pool_create(mem_buf, mem_buf_size, initFlags);
    }

    VFX_DEV_ASSERT(mem_pool != NULL);

    info.user_data = mem_pool;
    info.release_user_data_callback = vfx_sys_mem_pool_allocator_release_user_data_callback;
    info.alloc_callback = vfx_sys_mem_pool_allocator_alloc_callback;
    info.free_callback = vfx_sys_mem_pool_allocator_free_callback;
    allocator = vrt_allocator_create(NULL, &info);
    VFX_DEV_ASSERT(allocator != NULL);

    if (VFX_FLAG_HAS(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE))
    {
        vfx_sys_mem_pool_enable_thread_safe(mem_pool);
    }

    return allocator;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_allocator_get_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vfx_sys_mem_pool_allocator_get_status(vrt_allocator_handle handle, vfx_sys_mem_pool_status_struct *status_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_pool_handle mem_pool;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status_buf == NULL)
    {
        /* Do nothing */
        return;
    }

    if (handle == NULL)
    {
        vfx_sys_mem_zero(status_buf, sizeof(*status_buf));
        return;
    }
    
    mem_pool = (vfx_sys_mem_pool_handle)vrt_allocator_get_info(handle)->user_data;

    vfx_sys_mem_pool_get_status(mem_pool, status_buf);    
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_remaining_output
 * DESCRIPTION
 *  output the remaining memory block information in profiling heap 
 * PARAMETERS
 *  flags :    reserved
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_dbg_mem_pool_remaining_output(kal_uint32 flags)
{
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_overall_output
 * DESCRIPTION
 *  output the overall profiling result
 * PARAMETERS
 *  flags :    reserved
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_heap_profiling_overall_output(kal_uint32 flags)
{
    vfx_sys_mem_pool_struct *i;
    VfxU32 j;

    /* traverse memory pool to update the record & output some ap's heap info*/
    for (i = g_vfx_sys_mem_pool_list_head; i != NULL; i = i->next_mem_pool)
    {
        if (i->app_id != GRP_ID_INVALID)
        {
            vfx_heap_profiling_overall_update(i);
        }
        else
        {
            /*app_id == GRP_ID_INVALID, heap that does not record in g_vfx_heap_profiling_overall_arr*/
            VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_OVERALL_NO_ID /*"[vfx_sys_mem_pool][Profile_overall] Heap addr:0x%x, peak size:%d, heap size:%d"*/, 
                    i->mem_buf, i->max_used_size, i->mem_buf_size);
        }
    }
    /* traverse g_vfx_heap_profiling_overall_arr and output*/
    for (j = 0; j < sizeof(g_vfx_heap_profiling_overall_arr)/sizeof(g_vfx_heap_profiling_overall_arr[0]); j++)
    {
        if (g_vfx_heap_profiling_overall_arr[j].app_id != GRP_ID_INVALID)
        {
            VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_OVERALL_KNOW_ID /*"[vfx_sys_mem_pool][Profile_overall] Heap of ap:%d, peak size:%d, heap size:%d"*/,
                    g_vfx_heap_profiling_overall_arr[j].app_id, 
                    g_vfx_heap_profiling_overall_arr[j].peak_size,
                    g_vfx_heap_profiling_overall_arr[j].pool_size);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_pool_set_property
 * DESCRIPTION
 *  output the overall profiling result
 * PARAMETERS
 *  handle:    sys mem pool handle
 *  data:      the config data
 *  flags :    the config item
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_pool_set_property(vfx_sys_mem_pool_handle handle, void* data, VfxU32 flag)
{
    vfx_sys_mem_pool_struct *mem_pool = handle;
    if (flag & VFX_SYS_MEM_POOL_SET_APP_ID_PROPERTY_FLAG)
    {
        mem_pool->app_id = (MMI_ID) (0xFFFF & (VfxU32)data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_set_config_disable
 * DESCRIPTION
 *  disable the heap profiling, 
 *  the profiling method only work if __VFX_HEAP_PROFILE__ is defined
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_heap_profiling_set_config_disable(void)
{
#if defined(__VFX_HEAP_PROFILE__)
    g_vfx_heap_profiling_single_config.profile_app = GRP_ID_INVALID;
    g_vfx_heap_profiling_single_config.threshold_size = ~0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_set_config_enable
 * DESCRIPTION
 *  enable the heap profiling and set the config data
 *  the profiling method only work if __VFX_HEAP_PROFILE__ is defined
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_heap_profiling_set_config_enable(U32 appid_32, U32 size_KB)
{
#if defined __VFX_HEAP_PROFILE__
    vfx_sys_mem_pool_struct *i;
    g_vfx_heap_profiling_single_config.profile_app = (MMI_ID) appid_32;
    g_vfx_heap_profiling_single_config.threshold_size = size_KB * 1024;
    vfx_heap_profiling_data_init();
    /* traverse memory pool to update the record & output some ap's heap info*/
    for (i = g_vfx_sys_mem_pool_list_head; i != NULL; i = i->next_mem_pool)
    {
        if (i->app_id == (MMI_ID) appid_32)
        {
            VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_APP_EXIST /*"[vfx_sys_mem_pool][Profile_detail][Warning] app id:%d already exists but enable snapshot must done before app launched"*/,
                    i->app_id);
            break;
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_obj_update
 * DESCRIPTION
 *  find out the object record from snapshot and update 
 * PARAMETERS
 *  allocator:      The allocator
 *  _ptr:           The pointer of object
 *  flag:           reserved
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_heap_profiling_obj_update(vrt_allocator_handle allocator, void* _ptr, VfxU32 flag)
{
#if defined __VFX_HEAP_PROFILE__
    if (g_snapshotData.trigger_ptr_idx < VFX_HEAP_ALLOC_MAX &&
        g_snapshotData.info[g_snapshotData.trigger_ptr_idx].mem_addr == (VfxU32)_ptr)
    {
        vfx_sys_mem_pool_struct* mem_pool;    
        mem_pool = (vfx_sys_mem_pool_struct*) vrt_allocator_get_info(allocator)->user_data;
        if ( mem_pool->used_size == g_snapshotData.max_size 
             /*&& g_snapshotData.profile_app == mmi_res_get_app_baseID(mem_pool->app_id)*//*Mark for speed up*/)
        {
            if (g_vfx_heap_profiling_isObj_func)
            {
                g_vfx_heap_profiling_isObj_func( (void*)g_snapshotData.info[g_snapshotData.trigger_ptr_idx].mem_addr, 
                                                 (void**)&g_snapshotData.info[g_snapshotData.trigger_ptr_idx].parent);
                g_snapshotData.info[g_snapshotData.trigger_ptr_idx].virtual_table = *((VfxU32*)g_snapshotData.info[g_snapshotData.trigger_ptr_idx].mem_addr);
                g_snapshotData.trigger_ptr_idx = VFX_HEAP_ALLOC_MAX; /*reset to invalid*/
            }
        }
    }
#endif
}


MMI_BOOL vfx_heap_profiling_ssc_check(
    WCHAR* str /*user key in data*/,
    CHAR* temp_str /*temp buffer*/, 
    CHAR* pattern_disable, 
    CHAR* pattern_enable, CHAR* pattern_enable_cfg1, CHAR* pattern_enable_cfg2)
{
#if defined __VFX_HEAP_PROFILE__
    mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) pattern_disable);
    if (mmi_ucs2cmp((CHAR*) temp_str, (CHAR*) str) == 0)
    {
        vfx_heap_profiling_set_config_disable();
        VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_DISABLE/*"[vfx_sys_mem_pool][Profile_detail][Disabled]"*/);
            
        return MMI_TRUE;
    }
    if ( mmi_ucs2strlen((const CHAR*)str) == strlen(pattern_enable_cfg2))
    {
        mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) pattern_enable);
        if (mmi_ucs2ncmp
            ((const CHAR*)temp_str, (const CHAR*)str,
             (U32) mmi_ucs2strlen((const CHAR*)temp_str)) == 0)
        {
            U8 temp_str2[20], temp_str3[20];
            U32 appid_32, size_KB;
            memset(temp_str2, 0, sizeof(temp_str2));
            mmi_ucs2ncpy(
                (CHAR*) temp_str2,
                (const CHAR*)&str[strlen(pattern_enable)],
                (U32) (strlen(pattern_enable_cfg1) - strlen(pattern_enable)-1));
            mmi_ucs2_to_asc((CHAR*) temp_str3, (CHAR*) temp_str2);
            appid_32 = atoi((CHAR*) temp_str3);
            memset(temp_str2, 0, sizeof(temp_str2));
            mmi_ucs2ncpy(
                (CHAR*) temp_str2,
                (const CHAR*)&str[strlen(pattern_enable_cfg1)],
                (U32) (strlen(pattern_enable_cfg2) - strlen(pattern_enable_cfg1)-1));
            mmi_ucs2_to_asc((CHAR*) temp_str3, (CHAR*) temp_str2);
            size_KB = atoi((CHAR*) temp_str3);
            vfx_heap_profiling_set_config_enable(appid_32, size_KB);
            VFX_LOG(VFX_INFO, VFX_SYS_MEM_POOL_PROFILE_ENABLE/*"[vfx_sys_mem_pool][Profile_detail][Enable] appid:%d, threshold size:%dKB"*/,
                appid_32, size_KB);
            return MMI_TRUE;
        }
    }
#endif
    return MMI_FALSE;
}


#if defined(__VFX_HEAP_PROFILE__)
/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_check
 * DESCRIPTION
 *  check if the app & size match the basic condiftion of profiling
 * PARAMETERS
 *  app_id:   app id
 *  size:     size of app id
 * RETURNS
 *  1       matched
 *  0       mismatched
 *****************************************************************************/
VfxU32 vfx_heap_profiling_check(MMI_ID app_id,VfxU32 size)
{
    if (size >= g_vfx_heap_profiling_single_config.threshold_size)
    {
        if ( g_vfx_heap_profiling_single_config.profile_app != GRP_ID_INVALID &&
             mmi_res_get_app_baseID(app_id) ==  g_vfx_heap_profiling_single_config.profile_app )
        {
            return 1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_data_init
 * DESCRIPTION
 *  init the global data that used in heap profiling method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_heap_profiling_data_init(void)
{
    g_snapshotData.profile_app = GRP_ID_INVALID;
    g_snapshotData.snapshotcount = 0;
    g_snapshotData.max_size = 0;
    g_snapshotData.flag = SNAPSHOT_FLAG_DEFAULT;
    g_snapshotData.trigger_ptr_idx = VFX_HEAP_ALLOC_MAX;
#if defined __MMI_USE_MMV2__       
    g_snapshotData.max_page_size = 0;
#endif
    memset(g_snapshotData.info, 0x00, sizeof(g_snapshotData.info));
}

/*****************************************************************************
 * FUNCTION
 *  vfx_heap_profiling_set_isObj_callback
 * DESCRIPTION
 *  set the callback that used to check if the memory is allocated as object
 * PARAMETERS
 *  callback:   callback to check if memory content is a Vfx object
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_heap_profiling_set_isObj_callback(vfx_heap_profiling_isObj_cb callback)
{
    if (g_vfx_heap_profiling_isObj_func == NULL)
    {
        g_vfx_heap_profiling_isObj_func = callback;
    }
}
#endif /* defined(__VFX_HEAP_PROFILE__) */


#ifdef VFX_MEM_LOG_ENABLE
/*****************************************************************************
 * FUNCTION
 *  vfx_sys_dbg_mem_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_dbg_mem_log(const VfxChar *fmt, ...)
{
    OSC_Sys_Schedule_Enable(0);
    if (g_vfx_sys_mem_log_fp == NULL)
    {
        g_vfx_sys_mem_log_fp = fopen(VFX_MEM_LOG_FILE_NAME, "w+t");
    }
    
    if (g_vfx_sys_mem_log_fp != NULL)
    {
        va_list args;
        va_start(args, fmt);
        vfprintf(g_vfx_sys_mem_log_fp, fmt, args);
        va_end(args);
        fflush(g_vfx_sys_mem_log_fp);
    }
    OSC_Sys_Schedule_Enable(1);
}
#endif /* VFX_MEM_LOG_ENABLE */


static void vfx_sys_dbg_mem_pool_dump(vfx_sys_mem_pool_struct *mem_pool, const VfxChar* promptStr, VfxS32 leakOnly)
{
#if !defined(__MTK_TARGET__) && defined(WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_TRACE(("[VFX] !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"));
    VFX_TRACE(("[VFX] !!!!!!!!!!!!!!! %s\n", promptStr));
    VFX_TRACE(("[VFX] !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"));
#if !defined(VFX_MEM_LOG_ENABLE)
    VFX_TRACE(("[VFX] Please turn on VFX_MEM_LOG_ENABLE for more detail\n"));
#else /* !defined(VFX_MEM_LOG_ENABLE) */
    {
        char toolBuf[260];
        char cmdBuf[512];
        char srcPath[260];
        VfxS32 i, len;

        if (g_vfx_sys_mem_log_fp == NULL)
        {
            return;
        }
        fclose(g_vfx_sys_mem_log_fp);
        g_vfx_sys_mem_log_fp = NULL;

        GetModuleFileNameA(NULL, srcPath, 260);
        len = strlen(srcPath);
        for (i = 0; i < len; i++)
        {
            srcPath[i] = tolower(srcPath[i]);
        }

        for(i = 0;i < len; i++)
        {
            if(strncmp(srcPath + i, "modis_vc9", 9) == 0)
            {
                break;
            }
        }
        strncpy(toolBuf, srcPath, i);
        strcpy(toolBuf + i, "venusmmi\\framework\\develop\\util\\vloga.pl");

        sprintf(
            cmdBuf, 
            "perl %s -l -h -i %s -f %08X ck", 
            toolBuf, 
            VFX_MEM_LOG_FILE_NAME, 
            (VfxU32)mem_pool);

        system(cmdBuf);
    }
#endif /* !defined(VFX_MEM_LOG_ENABLE) */
#endif /* !defined(__MTK_TARGET__) && defined(WIN32) */
}

