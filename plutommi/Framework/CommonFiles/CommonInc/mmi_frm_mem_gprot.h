/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  mmi_frm_mem_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI UI related functions for App-based, Screen-based ASM and Resource Memroy Manager
 *
 *  (Other API are declared in app_mem.h)
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_FRM_MEM_GPROT_H
#define MMI_FRM_MEM_GPROT_H

#ifdef __cplusplus
extern "C"
{
#endif



#include "app_mem.h"
#include "mmidatatype.h"
#include "MMI_features.h"
#include "kal_public_api.h"
#include "mmi_res_range_def.h"
#include "app_mem.h"
#include "kal_general_types.h"
/* DOM-NOT_FOR_SDK-BEGIN */
typedef void*   (*MemAlloc) (U32);
typedef void    (*MemFree) (void *);
typedef void*   (*mmi_malloc_func_ptr) (U32 size, void *arg);
typedef void    (*mmi_mfree_func_ptr) (void *ptr, void *arg);

#undef FILE_PATH_VALUE
#ifdef __32_32_SEG__
#define FILE_PATH_VALUE   NULL
#else
#define FILE_PATH_VALUE   __FILE__
#endif

#if !defined(__32_32_SEG__)
#define __MMI_FRM_ASM_OOM_SCREEN__
#endif

#ifndef OSL_MEMORY_INT_H
#define OSL_MEMORY_INT_H
/* DOM-NOT_FOR_SDK-END */

/*----------------------------------------------------------------*
  General Memory
 *----------------------------------------------------------------*/
/***************************************************************************** 
 * Define
 *****************************************************************************/


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  MMI_FRM_ADM_ALLOC_FRAMEBUFFER
 * DESCRIPTION
 *  This function is to allocate non-cacheable memory, it also can switch cacheable memory
 *  to noncacheable. Should pay attention to the memory size, this size may be required to 32 bytes align.
 * PARAMETERS
 *  adm_id   : [IN]   KAL ADM id.
 *  size     : [IN]   Memory size need to allocate. 
 * RETURNS
 *  Address of allocated memory with noncacheable setting.
 * EXAMPLE
 * <code>
 * KAL_ADM_ID adm_id;
 * void *buff_ptr;
 * adm_id = kal_adm_create(buffer_pool,sizeof(buffer_pool), chunk, MMI_FALSE);
 * buff_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(adm_id, size);
 * ..................
 * kal_adm_free(adm_id, buff_ptr);
 * </code>
 *****************************************************************************/
#define MMI_FRM_ADM_ALLOC_FRAMEBUFFER(adm_id, size)   kal_adm_alloc_nc_align(adm_id, size, __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__)
#define MMI_FRM_ADM_ALLOC_FRAMEBUFFER_DBG(adm_id, size, f, l) kal_adm_alloc_nc_align_dbg(adm_id, size, __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__, f, l)
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mmi_malloc
 * DESCRIPTION
 *  This function is to allocate memory from control buffer. Applications should
 *  use this carefully. If the size is larger than 512B, we suggest application
 *  not use control buffer.
 * PARAMETERS
 *  size     : [IN]   Memory size need to allocate from control buffer. 
 * RETURNS
 *  Address of allocated memory.
 * EXAMPLE
 * <code>
 * U32 buffer_size;
 * void *ptr = mmi_malloc(buffer_size);
 * </code>
 *****************************************************************************/
#define mmi_malloc(size)    get_ctrl_buffer(size)

/*****************************************************************************
 * FUNCTION
 *  mmi_mfree
 * DESCRIPTION
 *  This function is to release memory from control buffer.
 * PARAMETERS
 *  buff     : [IN]   The memory pointer that need to be free. 
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_mfree(ptr)      free_ctrl_buffer(ptr)

/* DOM-NOT_FOR_SDK-BEGIN */
#define OslMalloc(size)     mmi_malloc(size)
#define OslMfree(ptr)       mmi_mfree(ptr)

#endif /* OSL_MEMORY_INT_H */

#ifndef _APP_MEM_MGR_GPROT_INT_H_
#define _APP_MEM_MGR_GPROT_INT_H_
/* DOM-NOT_FOR_SDK-END */

/*----------------------------------------------------------------*
  App-based ASM
 *----------------------------------------------------------------*/
/***************************************************************************** 
 * ASM manager description:
 * To make asm manager mechanism easy to use and maitain, we decide not to
 * support reentry function of asm screens. There are some mechanism to prevent reentry
 * case and make asm manager simple:
 *
 * 1. Press END key will delete asm screens and won't invoke success callback;
 * 2. Callback of incoming call (mmi_frm_appmem_ucm_cb_hdlr) will also delete asm 
 *    screens to prevent reentry and won't invoke success callback;
 * 3. Provide cancel callback to notify application when asm manager is terminated
 *    without invoking success callback and launching new application;
 * 
 * Please refer the test cases mmi_frm_appmem_ut_end_key_behavior_progress_scrn, mmi_frm_appmem_ut_end_key_behavior_startnew_scrn
 * mmi_frm_appmem_ut_ucm_behavior_progress_scrn, mmi_frm_appmem_ut_ucm_behavior_startnew_scrn for
 * the detail work flow of previous description.
 *
 ****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/* Max number of applications shown in the "Stop Application" screen */
#define MMI_FRM_APPMEM_MAX_APP_PROMPTED     (10)
#define MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET  (4)

#define MMI_FRM_APP_MEM_PRIORITY_DEFAULT		(128)

#define APPMEM_STR_NON_DEFINED     STR_GLOBAL_END
/* DOM-NOT_FOR_SDK-END */

/* prepare flag */
typedef enum {
    /* if memory is not enough, prompt Out-of-Memory screen */
    MMI_FRM_ASM_F_NONE          = 0,
    /* prepare memory without Out-of-Memory prompt screen */
    MMI_FRM_ASM_F_FORCE_PREPARE = 0x00000001,
} mmi_frm_asm_prepare_flag_type;


/* The return value of event "EVT_ID_ASM_FORCE_FREE", the event should be processed in 
   root screen group applications */
typedef enum {
    /* Notify framework the memory is freed */
    MMI_FRM_ASM_FREED = MMI_RET_OK,
    /* Notify framework the memory is waiting to free */
    MMI_FRM_ASM_WAITING_TO_FREE,
    /* Notify framework the memory can not be freed */
    MMI_FRM_ASM_FREE_FAIL,
    /* enum end */
    MMI_FRM_ASM_END
} mmi_frm_asm_result_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
/* backward compatible only, please use mmi_frm_asm_result_enum instead */
typedef enum {
    MMI_MEM_FREED           = MMI_FRM_ASM_FREED,
    MMI_MEM_WAITING_TO_FREE = MMI_FRM_ASM_WAITING_TO_FREE,
    MMI_MEM_FREE_FAIL       = MMI_FRM_ASM_FREE_FAIL,
} mmi_frm_appmem_result_enum;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/* This enum is for app-based ASM cancel callback event type */
typedef enum
{
    /* cancel callback event type start */
    MMI_FRM_ASM_CANCEL_BACK_FROM_PROMPT_SCRN,
    /* cancel callback by UCM Call */
    MMI_FRM_ASM_CANCEL_BY_UCM_CALL,
    /* cancel callback by user press end key */
    MMI_FRM_ASM_CANCEL_BY_END_KEY,
    /* cancel callback by interrupt, some interrupt will goback to idle,such as usb plug in, sim card plug in */
    MMI_FRM_ASM_CANCEL_DEL_BY_INTERRUPT,
    /* cancel callback by mmi_frm_asm_cancel() */
    MMI_FRM_ASM_CANCEL_BY_DEMAND,
    /* cancel callback by prepare re-entry */
    MMI_FRM_ASM_CANCEL_BY_REENTRY,
    /* cancel callback event total num */

    MMI_FRM_ASM_CANCEL_BY_PRIORITY,
    
    MMI_FRM_APPMEM_CANCEL_TYPE_TOTAL
} mmi_frm_asm_cancel_reason_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
/* backward compatible only, please use mmi_frm_asm_cancel_reason_enum instead */
typedef enum {
    MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN = MMI_FRM_ASM_CANCEL_BACK_FROM_PROMPT_SCRN,
    MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL           = MMI_FRM_ASM_CANCEL_BY_UCM_CALL,
    MMI_FRM_APPMEM_CANCEL_BY_END_KEY            = MMI_FRM_ASM_CANCEL_BY_END_KEY,
    MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT      = MMI_FRM_ASM_CANCEL_DEL_BY_INTERRUPT,
    MMI_FRM_APPMEM_CANCEL_BY_DEMAND             = MMI_FRM_ASM_CANCEL_BY_DEMAND,
    MMI_FRM_APPMEM_CANCEL_BY_REENTRY            = MMI_FRM_ASM_CANCEL_BY_REENTRY,
    MMI_FRM_APPMEM_CANCEL_BY_PRIORITY           = MMI_FRM_ASM_CANCEL_BY_PRIORITY
} mmi_frm_appmem_event_type_enum;
/* DOM-NOT_FOR_SDK-END */


/* This struct is for app-based ASM cancel callback event */
typedef struct
{
    /* cancel callback event type */
    mmi_frm_appmem_event_type_enum evt_type;
    /* the app id that ask for release memory */
    mmi_id app_id;
} mmi_frm_appmem_evt_struct;


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * CALLBACK
 *  translate key handler
 * DESCRIPTION
 * This is cancel callback function type, when prompt release screen is canceled
 ******************************************************************************/
typedef void (*mmi_frm_appmem_cb)(mmi_frm_appmem_evt_struct*);

/* This is success callback function type, when app can get enough memory */
typedef void (*mmi_frm_appmem_success_cb)(mmi_id app_id, U32 required_size);
/* DOM-NOT_FOR_SDK-END */

/******************************************************
  The cancel callback event send to app proc. Because DOM cannot
  identify Macros in the struct, please see the whole members as follow:
  
  typedef struct {
      //event header
      MMI_EVT_PARAM_HEADER
      //app id which need to be sent 
      mmi_id app_id;
      //cancel event type 
      union {
              mmi_frm_appmem_event_type_enum cancel_reason;
            } arg;
   } mmi_frm_appmem_asm_evt_struct;
 ******************************************************/
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* event header */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    /* app id which need to be sent */
    mmi_id app_id;
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* cancel event type */
    union {
    mmi_frm_appmem_event_type_enum cancel_reason;
    } arg;
    /* DOM-NOT_FOR_SDK-END */
} mmi_frm_appmem_asm_evt_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
#define MMI_EVT_PARAM_HEADER_ASM    \
    MMI_EVT_PARAM_HEADER            \
    mmi_id app_id;

typedef struct {
    MMI_EVT_PARAM_HEADER_ASM
} mmi_frm_asm_evt_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER_ASM
    U32 required_size;
} mmi_frm_asm_free_evt_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER_ASM
    U32 required_size;
} mmi_frm_asm_prepare_evt_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER_ASM
    mmi_frm_asm_cancel_reason_enum cancel_reason;
} mmi_frm_asm_cancel_evt_struct;
/* DOM-NOT_FOR_SDK-END */

/* This enum is for event type of screen group proc. */
typedef enum {
    /* Event ID start */
    EVT_ID_ASM_BASE = FRAMEWORK_ASM,
    /* Event ID to force free ASM */
    EVT_ID_ASM_FORCE_FREE,  /* mmi_frm_asm_free_evt_struct */
    /* Event ID to free ASM voluntarily */
    EVT_ID_ASM_FREE_REQ,    /* mmi_frm_asm_free_evt_struct */
    /* Event ID that memory is ok to use (prepare ready) */
    EVT_ID_ASM_PREPARED,    /* mmi_frm_asm_prepare_evt_struct */
    /* Event ID that OOM is canceled */
    EVT_ID_ASM_CANCELED,    /* mmi_frm_asm_cancel_evt_struct */

    EVT_ID_ASM_POST_PREPARED,
    /* Event ID that request to enlarge heap in backward active scenario */
    EVT_ID_ASM_BACKWARD_ENLARGE_HEAP,    /* mmi_event_struct */
    /* Event ID that request to shrink heap in inactive scenario */
    EVT_ID_ASM_INACTIVE_SHRINK_HEAP,    /* mmi_event_struct */
    
    EVT_ID_ASM_OOM_BACK_TO_IDLE,
    /* Event ID to free ASM voluntarily, ap do NOT trigger async free(MMI_FRM_ASM_WAITING_TO_FREE).
    just return MMI_FRM_ASM_FREE_FAIL */
    EVT_ID_ASM_FREE_REQ_NO_WAIT,    /* mmi_frm_asm_free_evt_struct */
    
    /* Event ID end */
    EVT_ID_ASM_END
} mmi_frm_asm_evt_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
/* backward compatible only, please use mmi_frm_asm_evt_enum instead */
typedef enum {
    EVT_ID_MEM_FREE_ASM     = EVT_ID_ASM_FORCE_FREE,
    EVT_ID_MEM_IS_ENOUGH    = EVT_ID_ASM_PREPARED,
    EVT_ID_MEM_CANCELED     = EVT_ID_ASM_CANCELED,        
} mmi_frm_appmem_evt_enum;
/* DOM-NOT_FOR_SDK-END */


/* asm property */
typedef struct {
    U32 f_prepare_w_reserve;      /* required mem. will be reserved for AP after prepare */
    U32 f_hide_in_oom;            /* hide AP display in OOM dialog */
    U32 f_skip_size_checking;     /* skip size checking during prepare, so can prepare more than configured */
    /* DOM-NOT_FOR_SDK-BEGIN */
    U32 f_skip_reserve_checking;  /* skip reserve checking (only for framework internal now) */
    U32 f_pluto_launcher;
    /* DOM-NOT_FOR_SDK-END */
} mmi_frm_asm_property_struct;

#if defined __MMI_USE_MMV2__
typedef applib_mem_slmm_id MMI_FRM_ASM_SLMM_ID; 

/*definition for mmi_frm_asm_change_heap_size_para's flag*/
#define FRM_ASM_HEAP_CHANGE_DEFAULT       (0)
#define FRM_ASM_HEAP_CHANGE_IN_BACKWARD   (1<<0)
#define FRM_ASM_HEAP_CHANGE_FORCE_PREPARE (1<<1)
#define FRM_ASM_HEAP_CHANGE_IF_ENOUGH     (1<<2)
#define FRM_ASM_HEAP_CHANGE_IN_UNHIDDEN   (1<<3)
#define FRM_ASM_HEAP_CHANGE_ONLY_FREE_VOLUNTEERS (1<<4)

typedef struct {
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id; 
    mmi_id app_id;
    kal_uint32 heap_size;
    mmi_proc_func user_cb; 
    void* user_data; 
    kal_uint32 flag;
}mmi_frm_asm_change_heap_size_para;
#else
/*for Gabget Lib dummy link, remove if MMv2 support pluto project*/
typedef void* MMI_FRM_ASM_SLMM_ID; 
#endif
/*****************************************************************************
 * Adapter 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_total_left_size_r
 * DESCRIPTION
 *  Get available size of app-based ASM for given id.
 *
 *  Remark: this function is only suggested for *debug* purpose because
 *  1. The memory pool may be fragmented (total left free space is meaningless 
 *     if the pool has serious memory fragmentation)
 *  2. Even if the free space is contiguous, sometimes we still cannot allocate 10 * 10KB blocks 
 *     with 100KB free space because of the overheads of memory management bookkeeping
 *
 *  Please use mmi_frm_asm_get_max_alloc_size_r() instead to get actually allocatable size.
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  id :        [IN]    app id
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
extern U32 mmi_frm_asm_get_total_left_size_r(mmi_id id);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_max_alloc_size_r
 * DESCRIPTION
 *  Get the max possible size of single allocation from app-based ASM for given id. 
 *  Return value of it is typically less than mmi_frm_asm_get_total_left_size_r()
 *  if the pool is fragmented.
 *
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of the overheads of memory management bookkeeping. 
 *
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the free space
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  id :        [IN]    app id
 * RETURNS
 *  Maximum available allocation size in byte
 *****************************************************************************/
extern U32 mmi_frm_asm_get_max_alloc_size_r(mmi_id id);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_check_enough
 * DESCRIPTION
 *  do actual allocation to check if given memory size is allocatable for given id.
 * PARAMETERS
 *  id :        [IN]    app id
 *  size :      [IN]    size to check
 * RETURNS
 *  MMI_BOOL. If enough return MMI_TRUE, else return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_check_enough(mmi_id id, U32 size);

/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_check_enough_with_subsize
 * DESCRIPTION
 *  check if the ID 's ASM remaining size is enough for the request
 * PARAMETERS
 *  mmi_id:             [IN]    app id
 *  total_size:         [IN]    the total request size (non-continuous + continuous)
 *  continuous_subsize: [IN]    only useful in MMv2 case, the continuous memory size part of request
 * RETURNS
 *  1 : success ; 0 : fail
  *****************************************************************************/
U32 mmi_frm_asm_check_enough_with_subsize(mmi_id id, U32 total_size, U32 continuous_subsize);

#ifdef  __MMI_ASM_OOM_AUTO_KILL__
/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_set_app_priority
 * DESCRIPTION
 *  set app alloc memory priority
 * PARAMETERS
 *  app_id:    [IN]    ID of the application to be set
 *	priority:  [IN]    memory priority (range:0-255, 0:max priority, 255:min priority)
 * RETURNS
 *  void
 **************************************************************************/
extern void mmi_frm_asm_set_app_priority(mmi_id app_id, U32 priority);

/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_get_app_priority
 * DESCRIPTION
 *  get app alloc memory priority
 * PARAMETERS
 *  app_id:    [IN]    ID of the application to be set
 * RETURNS
 * memory priority (range:0-255, 0:max priority, 255:min priority)
 **************************************************************************/
extern U32 mmi_frm_asm_get_app_priority(mmi_id app_id);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_notify_stop_finished
 * DESCRIPTION
 *  This function is invoked by an application to notify MMI framework when 
 *  it was requested to be stopped and it finished the async stop operation.
 *  (Memory used by it are all released)
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  id:         [IN]    ID of the application requested to stop
 *  result:     [IN]    Whether the stop operation succeeded or not
 * RETURNS
 *  void
 *****************************************************************************/
__inline void mmi_frm_asm_notify_stop_finished(mmi_id id, MMI_BOOL result)
{
    applib_mem_ap_notify_stop_finished((kal_uint32)id, (kal_bool)result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_pool_size_r
 * DESCRIPTION
 *  Return the fixed size of app-based ASM pool
 *
 *  Remark: we can use this function to decide the maximum possible memory 
 *  we can allocate (the whole pool size).
 * 
 *  However, sometimes we cannot allocate 10 * 10KB blocks in an 100KB memory pool
 *  because of the overheads of memory management bookkeeping. 
 *  
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the pool size:
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
__inline U32 mmi_frm_asm_get_pool_size_r(void)
{
    return applib_mem_ap_get_pool_size();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_is_valid_block_r
 * DESCRIPTION
 *  Check if a app-based ASM memory block is valid by inspecting its guard patterns.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr:     [IN]        Memory block to check
 * RETURNS
 *  Return true if 'mem_ptr' is a valid block
 *****************************************************************************/
__inline MMI_BOOL mmi_frm_asm_is_valid_block_r(void *mem_ptr)
{
    return applib_mem_ap_is_valid_block(mem_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_check_integrity_r
 * DESCRIPTION
 *  Check if the internal state of app-based ASM is correct. 
 *  If not, then ASSERT!
 *
 *  Remark: This function takes a lot of computation time, and it should not be
 *  used in normal case. 
 *  The function call can be inserted in application code when we need to locate 
 *  hard-to-find memory corruption issue.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline void mmi_frm_asm_check_integrity_r(void)
{
    applib_mem_ap_check_integrity();
}


/*****************************************************************************
 * Extern Global Variable 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Function 
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
extern void *mmi_frm_asm_alloc_int(mmi_id id, U32 size, asm_alloc_flag alloc_flag, CHAR* file, U32 line);
extern void mmi_frm_asm_free_int(mmi_id id, void *ptr, CHAR* file, U32 line);
/* DOM-NOT_FOR_SDK-END */

/* all allocate would be 32 bytes alignment and default to cacheable (kal_adm_alloc_align) */
/* both alloc and free are thread-safe w/ postfix '_r', means re-entrant, to identify this */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is cacheable version for normal usage.
 *
 *  Remark: 1. This function can be used in non-MMI task (postfix '_r', means re-entrant for thread-safe).
 *          2. allocated memory is cacheable. for non-cacheable, please use mmi_frm_asm_alloc_nc_r instead.
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define mmi_frm_asm_alloc_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_DEFAULT_FLAG, FILE_PATH_VALUE, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_sw_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is cacheable version for SW usage, DO-NOT use the allocated memory for HW access.
 *  It identifies the allocated memory is for software usage and can be remap to non-continuous physical memory
    to reduce the memory fragmentation. User should be remember the allocated memory CANNOT be converted to non-cacheable memory for HW usage 
 *  for HW usage. 
 *
 *  Remark: 1. This function can be used in non-MMI task (postfix '_r', means re-entrant for thread-safe).
 *          2. allocated memory is cacheable. for non-cacheable, please use mmi_frm_asm_alloc_nc_r instead.
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define mmi_frm_asm_alloc_sw_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_SW_FLAG, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_sw_r_dbg
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  It identifies the allocated memory is for software usage and can be remap to non-continuous physical memory
    to reduce the memory fragmentation. User should be remember the allocated memory CANNOT be converted to non-cacheable memory for HW usage 
 *  for HW usage. 
 *
 * PARAMETERS
 *  _id :        [IN] app id
 *  _size :      [IN] size to allocate
 *  _f :         [IN] filename (CHAR *)
 *  _l :         [IN] line nmber (U32)
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define mmi_frm_asm_alloc_sw_r_dbg(_id, _size,  _f, _l)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_SW_FLAG, _f, _l)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_nc_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is non-cacheable version of mmi_frm_asm_alloc_r.
 *
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define mmi_frm_asm_alloc_nc_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_FB_FLAG, FILE_PATH_VALUE, __LINE__)

#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_alloc_nc_top_r
 * DESCRIPTION
 *  allocate memory from app-based ASM with given size for given id.
 *  This is non-cacheable version of mmi_frm_asm_alloc_r, it's api for MMv2 feature only
 *  (It provides a flexibility to fine-tune fragment that caused by continuous buffer)
 *
 * PARAMETERS
 *  _id :        [IN]    app id
 *  _size :      [IN]    size to allocate
 * RETURNS
 *  pointer to allocated memory. NULL if memory is not available.
 *****************************************************************************/
#define mmi_frm_asm_alloc_nc_top_r(_id, _size)   mmi_frm_asm_alloc_int(_id, _size, ASM_ALLOC_IS_FB_FLAG|ASM_ALLOC_IS_TOP_FLAG, FILE_PATH_VALUE, __LINE__)
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_free_r
 * DESCRIPTION
 *  free memory allocated by mmi_frm_asm_alloc_r or mmi_frm_asm_alloc_nc_r.
 *
 * PARAMETERS
 *  _id :           [IN]    app id
 *  _mem_ptr :      [IN]    memory to free
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_frm_asm_free_r(_id, _mem_ptr)  mmi_frm_asm_free_int(_id, _mem_ptr, FILE_PATH_VALUE, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_prepare
 * DESCRIPTION
 *  ask to prepare given size of memory for given id.
 *  here prepare means to make sure actual allocation is available.
 *  after prepare success, prepare callback will be invoked and allocation of given size is guaranteed within a function call.
 *  if memory is not available to prepare, Out-of-Memory screen prompted and ask user to free memory of running application(s).
 *
 *  Remark: this function only can be used in MMI task.
 * PARAMETERS
 *  app_id :        [IN]    app id
 *  size :          [IN]    size to prepare
 *  prepare_cb :    [IN]    callback proc. for prepare result. see mmi_frm_asm_evt_enum for relative events.
 *  user_data :     [IN]    user data of callback proc.
 *  flag :          [IN]    prepare flag
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_prepare(
                    mmi_id app_id, 
                    U32 size, 
                    mmi_proc_func prepare_cb, 
                    void *user_data, 
                    mmi_frm_asm_prepare_flag_type flag);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_prepare_w_subsize
 * DESCRIPTION
 *  ask to prepare given size of memory for given id.
 *  here prepare means to make sure actual allocation is available.
 *  after prepare success, prepare callback will be invoked and allocation of given size is guaranteed within a function call.
 *  if memory is not available to prepare, Out-of-Memory screen prompted and ask user to free memory of running application(s).
 *
 *  Remark: this function only can be used in MMI task.
 * PARAMETERS
 *  app_id :        [IN]    app id
 *  total_size:         [IN]    the total request size (non-continuous + continuous)
 *  continuous_subsize: [IN]    only useful in MMv2 case, the continuous memory size part of request
 *  prepare_cb :    [IN]    callback proc. for prepare result. see mmi_frm_asm_evt_enum for relative events.
 *  user_data :     [IN]    user data of callback proc.
 *  flag :          [IN]    prepare flag
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_prepare_w_subsize(
                    mmi_id app_id, 
                    U32 total_size, 
                    U32 continuous_subsize, 
                    mmi_proc_func prepare_cb, 
                    void *user_data, 
                    mmi_frm_asm_prepare_flag_type flag);
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_property_init
 * DESCRIPTION
 *  initialize asm property structure.
 *
 * PARAMETERS
 *  p :           [IN]    pointer to asm property structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_asm_property_init(mmi_frm_asm_property_struct *p);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_base_shrink_size
 * DESCRIPTION
 *  shrink the app's base size
 *
 * PARAMETERS
 *  app_id :           [IN]    app group id
 *  new_base_size :    [IN]    the base size after shrink
 * RETURNS
 *  MMI_TRUE           success
 *  MMI_FALSE          screen gourp of app doesn't exist
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_base_shrink_size(mmi_id app_id, U32 new_base_size);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_clean_base_shrink
 * DESCRIPTION
 *  clean the shrinking of app's base size
 *
 * PARAMETERS
 *  app_id :           [IN]    app group id
 * RETURNS
 *  MMI_TRUE           success
 *  MMI_FALSE          screen gourp of app doesn't exist
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_clean_base_shrink(mmi_id app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_property
 * DESCRIPTION
 *  get asm property for given id.
 *
 * PARAMETERS
 *  app_id :        [IN]    app id
 *  p :             [IN]    pointer to asm property structure
 * RETURNS
 *  success or not
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_get_property(mmi_id app_id, mmi_frm_asm_property_struct *p);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_set_property
 * DESCRIPTION
 *  set asm property for given id.
 *
 * PARAMETERS
 *  app_id :        [IN]    app id
 *  p :             [IN]    pointer to asm property structure
 * RETURNS
 *  success or not
 *****************************************************************************/
extern MMI_BOOL mmi_frm_asm_set_property(mmi_id app_id, mmi_frm_asm_property_struct *p);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_cancel_prepare
 * DESCRIPTION
 *  cancel submitted prepare request.
 *
 * PARAMETERS
 *  app_id :        [IN]    app id
 *  prepare_cb :    [IN]    callback proc. used in previous prepare request.
 *  user_data :     [IN]    user data of callback proc.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_asm_cancel_prepare(mmi_id app_id, mmi_proc_func prepare_cb, void *user_data);

#ifdef __MED_IN_ASM__
/* DOM-NOT_FOR_SDK-BEGIN */
extern void *mmi_frm_cache_alloc_int(U32 size, asm_alloc_flag alloc_type, PsFuncPtr free_cb, U32 flag, CHAR *file, U32 line);
extern void mmi_frm_cache_free_int(void *mem_ptr, CHAR *file, U32 line);
/* DOM-NOT_FOR_SDK-END */
#endif

#ifdef __MED_IN_ASM__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cache_alloc
 * DESCRIPTION
 *  allocate cache with given size. allocated memory is cacheable.
 *  
 * PARAMETERS
 *  _size :         [IN]    cache size to allocate
 *  _free_cb :      [IN]    callback function called when need to free allocated cache.
 *                          just stop cache usage and framework will help to free the cache pointer.
 *  _flag :         [IN]    reserved flag.
 * RETURNS
 *  memory pointer allocated
 *****************************************************************************/
#define mmi_frm_cache_alloc(_size, _free_cb, _flag)   mmi_frm_cache_alloc_int(_size, ASM_ALLOC_DEFAULT_FLAG, _free_cb, _flag, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cache_alloc_sw
 * DESCRIPTION
 *  allocate cache with given size. 
 *  This is cacheable version for SW usage, DO-NOT use the allocated memory for HW access.
 *  
 * PARAMETERS
 *  _size :         [IN]    cache size to allocate
 *  _free_cb :      [IN]    callback function called when need to free allocated cache.
 *                          just stop cache usage and framework will help to free the cache pointer.
 *  _flag :         [IN]    reserved flag.
 * RETURNS
 *  memory pointer allocated
 *****************************************************************************/
#define mmi_frm_cache_alloc_sw(_size, _free_cb, _flag)   mmi_frm_cache_alloc_int(_size, ASM_ALLOC_IS_SW_FLAG, _free_cb, _flag, FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cache_alloc_nc
 * DESCRIPTION
 *  allocate cache with given size. non-cacheable version of mmi_frm_cache_alloc.
 *  
 * PARAMETERS
 *  _size :         [IN]    cache size to allocate
 *  _free_cb :      [IN]    callback function called when need to free allocated cache.
 *                          just stop cache usage and framework will help to free the cache pointer.
 *  _flag :         [IN]    reserved flag.
 * RETURNS
 *  memory pointer allocated
 *****************************************************************************/
#define mmi_frm_cache_alloc_nc(_size, _free_cb, _flag)   mmi_frm_cache_alloc_int(_size, ASM_ALLOC_IS_FB_FLAG, _free_cb, _flag, FILE_PATH_VALUE, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cache_free
 * DESCRIPTION
 *  free cache allocated by mmi_frm_cache_alloc or mmi_frm_cache_alloc_nc.
 *  
 * PARAMETERS
 *  _mem_ptr :      [IN]    cache memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_frm_cache_free(_mem_ptr)    mmi_frm_cache_free_int(_mem_ptr, FILE_PATH_VALUE, __LINE__)
#endif

#if defined __MMI_USE_MMV2__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_create_slmm_pool
 * DESCRIPTION
 *  Create the slmm pool in ASM
 *  
 * PARAMETERS
 *  app_id :      [IN]    app id
 *  mem_size :    [IN]    slmm pool size
 *  is_log :      [IN]    1 : Enable the logging; 0 : disable the logging
 * RETURNS
 *  return : frm_asm_slmm_id for following asm slmm pool access (allocate/free)
 *           NULL means size check fail
 *****************************************************************************/
MMI_FRM_ASM_SLMM_ID mmi_frm_asm_create_slmm_pool(mmi_id app_id, U32 mem_size, U32 is_log);


/* DOM-NOT_FOR_SDK-BEGIN */
extern void *_mmi_frm_asm_slmm_alloc(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, U32 mem_size, MMI_BOOL is_cacheable, MMI_BOOL is_continuous, CHAR* file, U32 line);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_alloc_sw_r
 * DESCRIPTION
 *  allocate slmm memory block in asm. 
 *  This is cacheable version for normal SW usage
 *  
 * PARAMETERS
 *  _slmm_id :   [IN] slmm pool id (MMI_FRM_ASM_SLMM_ID) 
 *  _size :      [IN] size (U32)
 * RETURNS
 *  memory pointer allocated 
 *****************************************************************************/
#define mmi_frm_asm_slmm_alloc_sw_r(_slmm_id, _size)  _mmi_frm_asm_slmm_alloc(_slmm_id, _size, MMI_TRUE, MMI_FALSE,  FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_alloc_sw_r_dbg
 * DESCRIPTION
 *  allocate slmm memory block in asm with caller information for debug. 
 *  This is cacheable version for normal SW usage, DO-NOT use the allocated memory for HW access
 *  
 * PARAMETERS
 *  _slmm_id :   [IN] slmm pool id (MMI_FRM_ASM_SLMM_ID) 
 *  _size :      [IN] size (U32)
 *  _f :         [IN] filename (CHAR *)
 *  _l :         [IN] line nmber (U32)
 * RETURNS
 *  memory pointer allocated 
 *****************************************************************************/
#define mmi_frm_asm_slmm_alloc_sw_r_dbg(_slmm_id, _size, _f, _l)  _mmi_frm_asm_slmm_alloc(_slmm_id, _size, MMI_TRUE, MMI_FALSE,  _f, _l)
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_alloc_nc_r
 * DESCRIPTION
 *  allocate slmm memory block in asm. 
 *  This is non-cacheable version can be used for SW(worse performance) & HW access
 *  
 * PARAMETERS
 *  _slmm_id :   [IN] slmm pool id (MMI_FRM_ASM_SLMM_ID) 
 *  _size :      [IN] size (U32)
 * RETURNS
 *  memory pointer allocated 
 *****************************************************************************/
#define mmi_frm_asm_slmm_alloc_nc_r(_slmm_id, _size) _mmi_frm_asm_slmm_alloc(_slmm_id, _size, MMI_FALSE, MMI_TRUE,  FILE_PATH_VALUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_alloc_nc_r_dbg
 * DESCRIPTION
 *  allocate slmm memory block in asm with caller information for debug. 
 *  This is non-cacheable version can be used for SW(worse performance) & HW access
 *  
 * PARAMETERS
 *  _slmm_id :   [IN] slmm pool id (MMI_FRM_ASM_SLMM_ID) 
 *  _size :      [IN] size (U32)
 *  _f :         [IN] filename (CHAR *)
 *  _l :         [IN] line nmber (U32)
 * RETURNS
 *  memory pointer allocated 
 *****************************************************************************/
#define mmi_frm_asm_slmm_alloc_nc_r_dbg(_slmm_id, _size, _f, _l) _mmi_frm_asm_slmm_alloc(_slmm_id, _size, MMI_FALSE, MMI_TRUE, _f, _l)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_free
 * DESCRIPTION
 *  free allocated slmm block by mmi_frm_asm_slmm_alloc or mmi_frm_cache_alloc_xx.
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :   [IN] frm_asm_slmm_id
 *  ptr             :   [IN] allocated pointer
 * RETURNS
 *  0
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_free(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, void *ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_delete_slmm_pool
 * DESCRIPTION
 *  delete slmm pool in asm
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  0
 *****************************************************************************/
kal_uint32 mmi_frm_asm_delete_slmm_pool (MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_size
 * DESCRIPTION
 *  get slmm pool size
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *   slmm size
 *****************************************************************************/
kal_uint32 mmi_frm_asm_get_slmm_size(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_shrunk_heap_size
 * DESCRIPTION
 *  get slmm pool shrunk size
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *   slmm shrunk size
 *****************************************************************************/
kal_uint32 mmi_frm_asm_get_slmm_shrunk_heap_size(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_total_left_size
 * DESCRIPTION
 *  get slmm pool total left size
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  total left size
 *****************************************************************************/
kal_uint32 mmi_frm_asm_get_slmm_total_left_size(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_check_integrity
 * DESCRIPTION
 *  check slmm pool integrity
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  NULL
 *****************************************************************************/
void* mmi_frm_asm_slmm_check_integrity(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_vm_start
 * DESCRIPTION
 *  get slmm pool virtual memory start address
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  start address
 *****************************************************************************/
kal_uint32 mmi_frm_asm_get_slmm_vm_start(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_vm_end
 * DESCRIPTION
 *  get slmm pool virtual memory end address
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  end address
 *****************************************************************************/
kal_uint32 mmi_frm_asm_get_slmm_vm_end(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_owner_id
 * DESCRIPTION
 *  get slmm pool owner id
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  mmi id
 *****************************************************************************/
mmi_id mmi_frm_asm_get_slmm_owner_id(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_kal_slmm_id
 * DESCRIPTION
 *  get slmm pool's kal slmm id
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  KAL_SLMM_ID
 *****************************************************************************/
KAL_SLMM_ID mmi_frm_asm_get_kal_slmm_id(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_get_slmm_log_flag
 * DESCRIPTION
 *  get slmm pool's log flag
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 * RETURNS
 *  log flag
 *****************************************************************************/
kal_uint32 mmi_frm_asm_get_slmm_log_flag(applib_mem_slmm_id asm_slmm_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_limit_size
 * DESCRIPTION
 *  call applib_mem_ap_slmm_limit_size and update mem usage size 
 *  
 * PARAMETERS
 :  app_id          :      [IN] app id
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 *  old_size        :      [IN] The size before change
 *  new_size        :      [IN] The size after change
 * RETURNS
 *  1
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_limit_size(mmi_id app_id, MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, U32 old_size, U32 new_size);
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_change_heap_size
 * DESCRIPTION
 *  change the slmm heap size
 *  
 * PARAMETERS
 *  frm_asm_slmm_id :      [IN] frm_asm_slmm_id
 *  heap_app_id :          [IN] frm_asm_slmm_id
 * RETURNS
 *  1 : success
 *  0 : async enlarge 
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_change_heap_size (mmi_frm_asm_change_heap_size_para*  para_p);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_backward_enlarge_slmm_heap
 * DESCRIPTION
 *  shrink the slmm context heap size in backward scenario
 *  
 * PARAMETERS
 *  app_id :           [IN] app id
 *  frm_asm_slmm_id :  [IN] frm_asm_slmm_id
 *  size :             [IN] the final heap size 
 * RETURNS
 *  1 : success
 *  0 : async enlarge 
 *****************************************************************************/
kal_uint32 mmi_frm_asm_backward_enlarge_slmm_heap (
    mmi_id heap_app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size);
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_heap_shrink_size
 * DESCRIPTION
 *  shrink the slmm heap size
 *  
 * PARAMETERS
 *  app_id :           [IN] app id
 *  frm_asm_slmm_id :  [IN] frm_asm_slmm_id
 *  size :             [IN] the final heap size 
 * RETURNS
 *  1 : success
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_heap_shrink_size  ( 
    mmi_id app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_heap_enlarge_size_if_enough
 * DESCRIPTION
 *  enlarge the slmm heap size, return MMI_FALSE if ASM is insufficient. 
 *  No OOM would be trigger
 *
 * PARAMETERS
 *  app_id :           [IN] app id
 *  frm_asm_slmm_id :  [IN] frm_asm_slmm_id
 *  size :             [IN] the final heap size 
 * RETURNS
 *  MMI_TRUE : success
 *  MMI_FALSE : fail
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_heap_enlarge_size_if_enough ( 
    mmi_id heap_app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size );

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_heap_enlarge_size_only_free_volunteers
 * DESCRIPTION
 *  enlarge the slmm heap size, if ASM is insufficient it will free the volunteers.
 *  No OOM would be trigger, no async process would be trigger
 *
 * PARAMETERS
 *  app_id :           [IN] app id
 *  frm_asm_slmm_id :  [IN] frm_asm_slmm_id
 *  size :             [IN] the final heap size 
 * RETURNS
 *  MMI_TRUE : success
 *  MMI_FALSE : fail 
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_heap_enlarge_size_only_free_volunteers ( 
    mmi_id app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_slmm_get_used_page_size
 * DESCRIPTION
 *  get slmm used page size
 *
 * PARAMETERS
 *  frm_asm_slmm_id :  [IN] frm_asm_slmm_id
 * RETURNS
 * used page size
 *****************************************************************************/
kal_uint32 mmi_frm_asm_slmm_get_used_page_size ( MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id );
#else
/*for Gabget Lib dummy link, remove if MMv2 support pluto project*/
extern void *_mmi_frm_asm_slmm_alloc(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, U32 mem_size, MMI_BOOL is_cacheable, MMI_BOOL is_continuous, CHAR* file, U32 line);
kal_uint32 mmi_frm_asm_slmm_free(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, void *ptr);
#endif
/* DOM-NOT_FOR_SDK-BEGIN */
extern void *mmi_frm_asm_alloc_anonymous_int(U32 size,  asm_alloc_flag alloc_flag, CHAR* file, U32 line);
extern void mmi_frm_asm_free_anonymous_int(void *ptr, CHAR* file, U32 line);
extern U32 mmi_frm_asm_get_max_alloc_anonymous(void);

/* anonymous access */
#define ASM_ANONYMOUS_ID                        (FRAMEWORK_ASM)
#define mmi_frm_asm_alloc_anonymous(_size)      mmi_frm_asm_alloc_anonymous_int(_size, ASM_ALLOC_DEFAULT_FLAG, FILE_PATH_VALUE, __LINE__)
#define mmi_frm_asm_alloc_anonymous_sw(_size)      mmi_frm_asm_alloc_anonymous_int(_size, ASM_ALLOC_IS_SW_FLAG, FILE_PATH_VALUE, __LINE__)
#define mmi_frm_asm_alloc_anonymous_nc(_size)   mmi_frm_asm_alloc_anonymous_int(_size, ASM_ALLOC_IS_FB_FLAG, FILE_PATH_VALUE, __LINE__)
#define mmi_frm_asm_free_anonymous(_mem_ptr)    mmi_frm_asm_free_anonymous_int(_mem_ptr, FILE_PATH_VALUE, __LINE__)
void mmi_frm_asm_app_hide(MMI_ID app_id);
void mmi_frm_asm_app_unhide(MMI_ID app_id);
extern U32 mmi_frm_asm_get_asm_usage(MMI_ID requester_id, applib_mem_ap_usage_struct *applist, MMI_BOOL inc_hide, MMI_BOOL skip_v10);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_init
 * DESCRIPTION
 *  Initialize app-based ASM. This is called at boot up and create ADM pool.
 *  Applications should not call this.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_init(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_mem
 * DESCRIPTION
 *  Show "insufficient memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *  Remark: 
 *  1. This function is not suggested to be used in "interrupt screens" 
 *     (e.g. MT call or USB plug-in indication)
 *     Otherwise, it might re-enter the prompt screen and confuse user.
 *  2. 'success_callback' needs to enter a new MMI screen!
 *  3. There is a "cancel callback" registered by mmi_frm_appmem_set_cancel_callback.
 *  4. If the application is original screen based, when allocate fail, it should call
 *     this function to show "insufficient meomory" screen. The success callback must 
 *     be registered, to make framework know what to do next when the memory is enough.
 *  5. When screen group allocate ASM and don't register stop callback, 
 *     it is no need to call this function when allocate memory fail. But in group proc, 
 *     it should handle EVT_ID_MEM_IS_ENOUGH. The group that doesn't use ASM is no need to handle this.
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name          : [IN]    Application ID
 *  app_icon          : [IN]    Image ID of the application 
 *  required_size     : [IN]    Minimum required memory for the application
 *  success_callback  : [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * 1. The application is screen based.
 *    applib_mem_ap_register(
 *         APPLIB_MEM_AP_ID_TEST1, 
 *         STR_GLOBAL_1, 
 *         IMG_GLOBAL_L1, 
 *         mmi_frm_appmem_unit_test_stop_1);
 *    .............
 *    mem_ptr = applib_mem_ap_alloc(...);
 *    if (mem_ptr == NULL)
 *    {
 *        mmi_frm_appmem_prompt_to_release_mem(app_name, app_icon, size, entryfunction);
 *        mmi_frm_appmem_set_cancel_callback(..);
 *    }
 * 2. If screen group allcoate App-based ASM(such as CUI).
 *    mmi_frm_group_create(parent_sg, cui_sg_id, cui_asm_test_proc, NULL);
 *    mem_ptr = applib_mem_ap_alloc(cui_sg_id, size);
 *    if (!mem_ptr)
 *        return;
 *    else
 *        cui_asm_test_run();
 *    ..........
 *    mmi_ret cui_asm_test_proc(mmi_event_struct *evt)
 *    {
 *        switch(evt->evt_id)
 *        {
 *          case EVT_ID_GROUP_DEINIT:
 *               applib_mem_ap_free(cntx_ptr->mem_ptr);
 *               break;
 *          case EVT_ID_MEM_IS_ENOUGH:
 *               mem_ptr = applib_mem_ap_alloc(cntx_ptr->asm_id, cntx_ptr->asm_size);
 *               cui_asm_test_run();
 *               break;
 *          case EVT_ID_MEM_CANCELED:
 *               cui_asm_test_close();
 *               break;
 *         }
 *       return MMI_RET_OK;
 *    }
 * </code>
 *****************************************************************************/
extern void mmi_frm_appmem_prompt_to_release_mem(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                U32 required_size,
                void (*success_callback)(void));


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_full_pool
 * DESCRIPTION
 *  Show "insufficient memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *  This function is similar to mmi_frm_appmem_prompt_to_release_mem
 *  but it requires the whole pool.
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name           : [IN]    Application ID 
 *  app_icon           : [IN]    Image ID of the application 
 *  success_callback   : [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_prompt_to_release_full_pool(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                void (*success_callback)(void));


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_check_prompt_screen
 * DESCRIPTION
 *  if ordinary screen based app invoke asm manager just return app id, else if the app is
 *  screen group return root app id.
 * PARAMETERS
 *  void 
 * RETURNS
 *  Root app id which invoke asm manager.
 *****************************************************************************/
extern applib_mem_ap_id_enum mmi_frm_appmem_check_prompt_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_set_cancel_callback
 * DESCRIPTION
 *  Cancel callback will be invoked to notify application when asm manager is cancel.
 *  E.g. user press back (RSK) in prompt screen, press END key in progressing screen or 
 *  start new application screen, interrupt goback to idle, and UCM call at any screen,
 *  which means asm manager can't launch new application due to some reasons. All cancel
 *  callback types are defined in mmi_frm_appmem_event_type_enum.
 *  1. If the application is original screen based allocate ASM fail, This api should be called after 
 *  mmi_frm_appmem_prompt_to_release_mem.
 *  2. If screen group allocate fail, just handle EVT_ID_MEM_CANCELED in group proc. It's no need to
 *  call this function.
 *  Example code please see mmi_frm_appmem_prompt_to_release_mem.
 * PARAMETERS
 *  app_id            : [IN]    application id
 *  cancel_callback   : [IN]    Function pointer of cancel callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_set_cancel_callback(applib_mem_ap_id_enum app_id, mmi_frm_appmem_cb cancel_callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_disable_auto_prompt_screen
 * DESCRIPTION
 *  disable auto-prompt when app-ASM allocation failed. Application needs to call
 *  mmi_frm_appmem_prompt_to_release_mem directly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_disable_auto_prompt_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_enable_auto_prompt_screen
 * DESCRIPTION
 *  re-enable auto-prompt when app-ASM allocation failed. Application is no need
 *  to call mmi_frm_appmem_prompt_to_release_mem, just handle events in proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_enable_auto_prompt_screen(void);

/* DOM-NOT_FOR_SDK-END */

#ifdef __COSMOS_MMI_PACKAGE__
/************************************************************************
                           Temp memory API
************************************************************************/
extern void* mmi_frm_temp_alloc_int(U32 size, U32 line);
extern void mmi_frm_temp_free_int(void* ptr, U32 line);
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_alloc
 * DESCRIPTION
 *  Temp memory allocate function. Temp memory life cyle is in a primitive. And the
 *  size is 20K. You must free the memory when the primitive is end. When allocate fail,
 *  it will be assert just like control buffer. Temp memory can only be used in MMI Task.
 * PARAMETERS
 *  size   : [IN] allocate size.
 * RETURNS
 *  The address of the allocated memory.
 *****************************************************************************/
#define mmi_frm_temp_alloc(size)   mmi_frm_temp_alloc_int(size, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_free
 * DESCRIPTION
 *  Temp memory free function. 
 * PARAMETERS
 *  ptr    : [IN] The free memory pointer.
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_frm_temp_free(ptr)   mmi_frm_temp_free_int(ptr, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_get_max_left_size
 * DESCRIPTION
 *  The max allocated size of temp memory. You can use this function to query, if
 *  you could use temp memory
 * PARAMETERS
 *  void
 * RETURNS
 *  The max allocate size.
 *****************************************************************************/
extern U32 mmi_frm_temp_get_max_left_size(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_mem_init
 * DESCRIPTION
 *  init temp memory during boot up process, this is used by framework only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_temp_mem_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_check_all_free
 * DESCRIPTION
 *  check if all temp memory is free after a primitive. The temp memory life cycle is 
 *  during a primitive. If it's not free all , it will be assert. This function is used
 *  by framework only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_temp_check_all_free(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_get_allocate_num
 * DESCRIPTION
 *  Get the allocate number of temp memory. This function is used by framework.
 * PARAMETERS
 *  void
 * RETURNS
 *  The allocate number.
 *****************************************************************************/
extern U32 mmi_frm_temp_get_allocate_num(void);
extern U32 mmi_frm_temp_get_max_left_size(void);
#endif

/* DOM-NOT_FOR_SDK-BEGIN */
#endif /* _APP_MEM_MGR_GPROT_INT_H_ */

#ifndef _SCR_MEM_MGR_GPROT_INT_H_
#define _SCR_MEM_MGR_GPROT_INT_H_
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_alloc
 * DESCRIPTION
 *  Allocate screen-based ASM for the general buffer
 *  Remark:
 *  1. It might return NULL if the allocate failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using mmi_frm_scrmem_alloc() 100 times.
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *  We suggest application allocate a total size once, and use ADM to manage the return
 *  memory pool, other than allocate many times.
 *  This function can be only used in MMI task. 
 * PARAMETERS
 *  mem_size       : [IN]        Memory size
 * RETURNS
 *  Allocated memory address
 * EXAMPLE
 * <code>
 * U32 total_size;
 * void *ptr = mmi_frm_scrmem_alloc(total_size);
 * KAL_ADM_ID adm_id = kal_adm_create(ptr, sizeof(ptr), chunk, MMI_FALSE);
 * g_buff = kal_adm_alloc(adm_id);
 * </code>
 *****************************************************************************/
#define mmi_frm_scrmem_alloc(mem_size)              applib_mem_screen_alloc_int((kal_uint32)mem_size, KAL_FALSE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_alloc_framebuffer
 * DESCRIPTION
 *  Allocate screen-based ASM for the frame buffer(noncacheable)
 *  Remark:
 *  1. It might return NULL if the allocate failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using mmi_frm_scrmem_alloc_framebuffer() 100 times
 * PARAMETERS
 *  mem_size       : [IN]        Memory size
 * RETURNS
 *  Allocated memory address.
 *****************************************************************************/
#define mmi_frm_scrmem_alloc_framebuffer(mem_size)  applib_mem_screen_alloc_int((kal_uint32)mem_size, KAL_TRUE, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_free
 * DESCRIPTION
 *  Free screen-based shared memory
 * PARAMETERS
 *  mem_ptr   : [IN]      The memory block need to be free.
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_frm_scrmem_free(mem_ptr)                applib_mem_screen_free_int(mem_ptr, __LINE__)
    
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_enable_debug_leak_check
 * DESCRIPTION
 *  Enable the screen memory leakage check
 * PARAMETERS
 *  void
 * RETURNS
 *  None
 *****************************************************************************/
extern void mmi_frm_scrmem_enable_debug_leak_check(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_disable_debug_leak_check
 * DESCRIPTION
 *  Disable the screen memory leakage check
 * PARAMETERS
 *  void
 * RETURNS
 *  None
 *****************************************************************************/
extern void mmi_frm_scrmem_disable_debug_leak_check(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_debug_check_leak
 * DESCRIPTION
 *  Screen memory leak check
 * PARAMETERS
 *  void
 * RETURNS
 *  None
 *****************************************************************************/
extern void mmi_frm_scrmem_debug_check_leak(void);

#endif /* _SCR_MEM_MGR_GPROT_INT_H_ */
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */


#ifndef MMI_MEM_MONITOR_H
#define MMI_MEM_MONITOR_H
/*----------------------------------------------------------------*
  Memory Monitor
 *----------------------------------------------------------------*/
#ifdef __MMI_MEMORY_MONITOR__
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_MEM_MON_PROFILING_PERIOD    (200)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef struct
{
    U32 maximal_alloc_size;
    U32 current_alloc_size;
    U32 total_alloc_count;
    U32 total_alloc_size;
} partition_mem_alloc_struct;

typedef struct
{
    U32 register_scr_mem_size;
    U32 current_scr_alloc_size;
    U32 maximal_scr_alloc_size;
    U32 scr_alloc_count;
    U32 register_app_mem_size;
    U32 current_app_alloc_size;
    U32 maximal_app_alloc_size;
    U32 app_alloc_count;
} asm_mem_alloc_info_struct;

typedef enum
{
    MEM_MON_DYNAMIC_DATA,
    MEM_MON_STATIC_DATA,
    MEM_MON_DATA_TYPE_TOTAL
} mmi_mem_monitor_data_type;

typedef enum
{
    MMI_EM_MEMORY_MONITOR_OFF = 0,
    MMI_EM_MEMORY_MONITOR_OSL,
    MMI_EM_MEMORY_MONITOR_ASM,
    #ifdef __MMI_VUI_ENGINE__
    MMI_EM_MEMORY_MONITOR_VUI,
    #endif /* __MMI_VUI_ENGINE__ */
    MMI_EM_MEMORY_MONITOR_AFM,
    MMI_EM_MEMORY_MONITOR_TOTAL
} mmi_mem_monitor_type_enum;

/* which area is mem. monitor displaying on */
typedef struct {
    S32 x1;
    S32 y1;
    S32 x_offset;
    S32 y_offset;
} mmi_mem_mon_canvas_type;

typedef void (*mmi_mem_mon_info_str_cb_type)(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p);


/* type of string drawing function */
typedef void (*mmi_mem_mon_string_drawing_func_type)(PU16 unicode_str, S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * Extern Global Variable 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Function 
 *****************************************************************************/
extern void mmi_mem_mon_print_info(void);
extern void mmi_mem_mon_profiling_memory_monitor(mmi_mem_monitor_type_enum mem_type, mmi_mem_mon_canvas_type *canvas_p);
extern mmi_mem_monitor_type_enum mmi_mem_mon_profiling_get_enable(void);
extern void mmi_mem_mon_profiling_set_enable(mmi_mem_monitor_type_enum enable);
extern void mmi_mem_mon_construct_static_statistic(U16 *unicode_buff, U32 buff_size);

extern void mmi_mem_mon_start_periodic_profiling(U32 interval_in_ms);

extern void mmi_mem_mon_update_detail_info(mmi_frm_mem_type monitor_type);

extern void mmi_mem_mon_print_string(mmi_mem_mon_canvas_type *canvas_p, PU16 unicode_str);

/*
extern PU8 mmi_mem_mon_get_list_str(mmi_mem_monitor_type_enum idx);
*/
extern void mmi_mem_mon_set_string_drawing_function(mmi_mem_mon_string_drawing_func_type func_ptr);

#endif /* #ifdef __MMI_MEMORY_MONITOR__ */

#endif /* MMI_MEM_MONITOR_H */

/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* MMI_FRM_MEM_GPROT_H */ 


